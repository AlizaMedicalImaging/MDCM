/*********************************************************
 *
 * MDCM
 *
 * Modifications github.com/issakomi
 *
 *********************************************************/

/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef MDCMITEM_H
#define MDCMITEM_H

#include "mdcmDataElement.h"
#include "mdcmDataSet.h"
#include "mdcmParseException.h"
#include "mdcmSwapper.h"
#ifdef MDCM_SUPPORT_BROKEN_IMPLEMENTATION
#  include "mdcmByteSwapFilter.h"
#endif

namespace mdcm
{

class DataSet;

class MDCM_EXPORT Item : public DataElement
{
public:
  Item() : DataElement(Tag(0xfffe, 0xe000), 0xffffffff)
  {
  }

  friend std::ostream &
  operator<<(std::ostream &, const Item &);

  void
  Clear()
  {
    this->DataElement::Clear();
    NestedDataSet.Clear();
  }

  template <typename TDE>
  VL
  GetLength() const
  {
    if (ValueLengthField.IsUndefined())
    {
      assert(!NestedDataSet.GetLength<TDE>().IsUndefined());
      // Item Start             4
      // Item Length            4
      // DataSet                ?
      // Item End Delimitation  4
      // Item End Length        4
      assert(NestedDataSet.GetLength<TDE>() % 2 == 0);
      return TagField.GetLength() /* 4 */ + ValueLengthField.GetLength() /* 4 */
             + NestedDataSet.GetLength<TDE>() + 4 + 4;
    }
    else
    {
      // Item Start             4
      // Item Length            4
      // DataSet                ?
      const VL nestedlen = NestedDataSet.GetLength<TDE>();
      // The following line is commented out, since we could be in the case where
      // we are computing the actual length of an implicit dataset, from an
      // initially read explicit dataset in which case the two length cannot
      // related to each other
      // assert( ValueLengthField == nestedlen );
      assert(nestedlen % 2 == 0);
      return TagField.GetLength() /* 4 */ + ValueLengthField.GetLength() /* 4 */ + nestedlen;
    }
  }

  void
  InsertDataElement(const DataElement & de)
  {
    NestedDataSet.Insert(de);
    if (!IsUndefinedLength())
    {
      assert(0 && "InsertDataElement");
    }
  }

  const DataElement &
  GetDataElement(const Tag & t) const
  {
    return NestedDataSet.GetDataElement(t);
  }

  void
  SetNestedDataSet(const DataSet & nested)
  {
    NestedDataSet = nested;
  }

  const DataSet &
  GetNestedDataSet() const
  {
    return NestedDataSet;
  }

  DataSet &
  GetNestedDataSet()
  {
    return NestedDataSet;
  }

  Item(const Item & val)
    : DataElement(val)
  {
    NestedDataSet = val.NestedDataSet;
  }

  template <typename TDE, typename TSwap>
  std::istream &
  Read(std::istream & is)
  {
    {
      DataSet & nested = NestedDataSet;
      nested.Clear();
      assert(nested.IsEmpty());
    }
    if (!TagField.Read<TSwap>(is))
    {
#if 1
      throw std::logic_error("Should not happen (item)");
#else
      return is;
#endif
    }
#ifdef MDCM_SUPPORT_BROKEN_IMPLEMENTATION
    // MR_Philips_Intera_SwitchIndianess_noLgtSQItem_in_trueLgtSeq.dcm
    if (TagField == Tag(0xfeff, 0x00e0) || TagField == Tag(0xfeff, 0xdde0))
    {
      mdcmWarningMacro("ByteSwaping Private SQ: " << TagField);
      // Invert previously read TagField since wrong endianness:
      TagField = Tag(SwapperDoOp::Swap(TagField.GetGroup()), SwapperDoOp::Swap(TagField.GetElement()));
      assert(TagField == Tag(0xfffe, 0xe000) || TagField == Tag(0xfffe, 0xe0dd));
      if (!ValueLengthField.Read<SwapperDoOp>(is))
      {
        assert(0 && "Should not happen");
        return is;
      }
      // Some file written by GDCM 1.0 we writting 0xFFFFFFFF instead of 0x0
      if (TagField == Tag(0xfffe, 0xe0dd))
      {
        if (ValueLengthField)
        {
          mdcmAlwaysWarnMacro("ValueLengthField is not 0 (GDCM 1.0 bug?)");
        }
      }
      else if (ValueLengthField.IsUndefined())
      {
        DataSet & nested = NestedDataSet;
        nested.Clear();
        assert(nested.IsEmpty());
        std::streampos start = is.tellg();
        try
        {
          nested.template ReadNested<TDE, SwapperDoOp>(is);
          ByteSwapFilter bsf(nested);
          bsf.ByteSwap();
        }
        catch (const ParseException &)
        {
          // MM: MR_Philips_Intera_PrivateSequenceExplicitVR_in_SQ_2001_e05f_item_wrong_lgt_use_NOSHADOWSEQ.dcm
          // You have to byteswap the length but not the tag...sigh
          mdcmWarningMacro("Attempt to read nested Item without byte-swapping the Value Length");
          start -= is.tellg();
          assert(start < 0);
          is.seekg(start, std::ios::cur);
          nested.Clear();
          nested.template ReadNested<TDE, SwapperNoOp>(is);
          ByteSwapFilter bsf(nested);
          // MM: Tags are read in big endian, need to byteswap them back
          bsf.SetByteSwapTag(true);
          bsf.ByteSwap();
        }
        catch (...)
        {
          // MR_Philips_Intera_No_PrivateSequenceImplicitVR.dcm
          mdcmWarningMacro("Unhandled exception");
          assert(0);
        }
      }
      else
      {
        DataSet & nested = NestedDataSet;
        nested.Clear();
        assert(nested.IsEmpty());
        nested.template ReadWithLength<TDE, SwapperDoOp>(is, ValueLengthField);
        ByteSwapFilter bsf(nested);
        bsf.ByteSwap();
      }
      return is;
    }
#if 0
    // http://groups.google.com/group/comp.protocols.dicom/msg/c07efcf5e759fc83
    // Bug_Philips_ItemTag_3F3F.dcm
    if (TagField == Tag(0x3f3f, 0x3f00))
    {
      TagField = Tag(0xfffe, 0xe000);
    }
#endif
#endif
    if (TagField != Tag(0xfffe, 0xe000) && TagField != Tag(0xfffe, 0xe0dd))
    {
      mdcmAlwaysWarnMacro("Invalid Item, found tag: " << TagField);
      throw std::logic_error("Not a valid Item");
    }
    assert(TagField == Tag(0xfffe, 0xe000) || TagField == Tag(0xfffe, 0xe0dd));
    if (!ValueLengthField.Read<TSwap>(is))
    {
      assert(0 && "Should not happen");
      return is;
    }
    if (TagField == Tag(0xfffe, 0xe0dd))
    {
      // Some buggy files written by GDCM 1.0 have 0xFFFFFFFF instead of 0x0.
      if (ValueLengthField)
      {
        mdcmDebugMacro("ValueLengthField is not 0 but " << ValueLengthField);
      }
    }
    else if (ValueLengthField.IsUndefined())
    {
      DataSet & nested = NestedDataSet;
      nested.Clear();
      assert(nested.IsEmpty());
      nested.template ReadNested<TDE, TSwap>(is);
    }
    else
    {
      assert(!ValueLengthField.IsUndefined());
      DataSet & nested = NestedDataSet;
      nested.Clear();
      assert(nested.IsEmpty());
      nested.template ReadWithLength<TDE, TSwap>(is, ValueLengthField);
    }
    return is;
  }

  template <typename TDE, typename TSwap>
  const std::ostream &
  Write(std::ostream & os) const
  {
#ifdef MDCM_SUPPORT_BROKEN_IMPLEMENTATION
    if (false && TagField == Tag(0x3f3f, 0x3f00)) // Disabled workaround for Philips bug?
    {
      Tag t(0xfffe, 0xe000);
      t.Write<TSwap>(os);
    }
    else
#endif
    {
      assert(TagField == Tag(0xfffe, 0xe000) || TagField == Tag(0xfffe, 0xe0dd));
      if (TagField == Tag(0xfffe, 0xe0dd))
      {
        mdcmWarningMacro("SeqDelItem found in sequence with defined length");
        assert(ValueLengthField == 0);
        assert(NestedDataSet.Size() == 0);
      }
      if (!TagField.Write<TSwap>(os))
      {
        assert(0 && "Should not happen");
        return os;
      }
    }
    if (ValueLengthField.IsUndefined())
    {
      if (!ValueLengthField.Write<TSwap>(os))
      {
        assert(0 && "Should not happen");
        return os;
      }
    }
    else
    {
      const VL dummy = NestedDataSet.GetLength<TDE>();
      assert(dummy % 2 == 0);
      if (!dummy.Write<TSwap>(os))
      {
        assert(0 && "Should not happen");
        return os;
      }
    }
    NestedDataSet.Write<TDE, TSwap>(os);
    if (ValueLengthField.IsUndefined())
    {
      const Tag itemDelItem(0xfffe, 0xe00d);
      itemDelItem.Write<TSwap>(os);
      VL zero = 0;
      zero.Write<TSwap>(os);
    }
    return os;
  }

  /*
  MM:
  There are three special SQ related Data Elements that are not ruled by the VR encoding rules conveyed
  by the Transfer Syntax. They shall be encoded as Implicit VR. These special Data Elements are Item
  (FFFE,E000), Item Delimitation Item (FFFE,E00D), and Sequence Delimitation Item (FFFE,E0DD).
  However, the Data Set within the Value Field of the Data Element Item (FFFE,E000) shall be encoded
  according to the rules conveyed by the Transfer Syntax.
  */
  bool
  FindDataElement(const Tag & t) const
  {
    return NestedDataSet.FindDataElement(t);
  }

private:
  DataSet NestedDataSet{};
};

inline std::ostream &
operator<<(std::ostream & os, const Item & val)
{
  os << val.TagField;
  os << "\t" << val.ValueLengthField << "\n";
  val.NestedDataSet.Print(os, "\t");
  return os;
}

} // end namespace mdcm

#endif // MDCMITEM_H
