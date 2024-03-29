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
#ifndef MDCMDICT_H
#define MDCMDICT_H

#include "mdcmTypes.h"
#include "mdcmTag.h"
#include "mdcmPrivateTag.h"
#include "mdcmDictEntry.h"
#include "mdcmSystem.h"
#include "mdcmMacro.h"
#include <iostream>
#include <iomanip>
#include <map>

namespace mdcm
{
/**
 * Class to represent a map of DictEntry
 */

static const DictEntry tagNotFound("", "", VR::INVALID, VM::VM0, true);

class MDCM_EXPORT Dict
{
public:
  typedef std::map<Tag, DictEntry>     MapDictEntry;
  typedef MapDictEntry::iterator       Iterator;
  typedef MapDictEntry::const_iterator ConstIterator;

  MDCM_DISALLOW_COPY_AND_MOVE(Dict);

  Dict() : DictInternal()
  {
    assert(DictInternal.empty());
  }
  friend std::ostream &
  operator<<(std::ostream &, const Dict &);
  ConstIterator
  Begin() const
  {
    return DictInternal.cbegin();
  }
  ConstIterator
  End() const
  {
    return DictInternal.cend();
  }
  bool
  IsEmpty() const
  {
    return DictInternal.empty();
  }

  void
  AddDictEntry(const Tag & tag, const DictEntry & de)
  {
#ifndef NDEBUG
    MapDictEntry::size_type s = DictInternal.size();
#endif
    DictInternal.insert(MapDictEntry::value_type(tag, de));
#ifndef NDEBUG
    assert(s < DictInternal.size());
#endif
  }

  const DictEntry &
  GetDictEntry(const Tag & tag) const
  {
    MapDictEntry::const_iterator it = DictInternal.find(tag);
    if (it == DictInternal.cend())
    {
      return tagNotFound;
    }
    assert(DictInternal.count(tag) == 1);
    return it->second;
  }

  const char *
  GetKeywordFromTag(const Tag & tag) const
  {
    MapDictEntry::const_iterator it = DictInternal.find(tag);
    if (it == DictInternal.cend())
    {
      return nullptr;
    }
    assert(DictInternal.count(tag) == 1);
    return it->second.GetKeyword();
  }

  // Lookup DictEntry by keyword. Even if DICOM standard defines keyword
  // as being unique. The lookup table is built on Tag. Therefore
  // looking up a DictEntry by Keyword is more inefficient than looking up
  // by Tag.
  const DictEntry &
  GetDictEntryByKeyword(const char * keyword, Tag & tag) const
  {
    MapDictEntry::const_iterator it = DictInternal.cbegin();
    if (keyword)
    {
      for (; it != DictInternal.cend(); ++it)
      {
        if (strcmp(keyword, it->second.GetKeyword()) == 0)
        {
          tag = it->first;
          assert(DictInternal.count(tag) == 1);
          return it->second;
        }
      }
    }
    tag = Tag(0xffff, 0xffff);
    return tagNotFound;
  }

protected:
  friend class Dicts;
  void
  LoadDefault();

private:
  MapDictEntry DictInternal;
};

inline std::ostream &
operator<<(std::ostream & os, const Dict & val)
{
  Dict::MapDictEntry::const_iterator it = val.DictInternal.cbegin();
  for (; it != val.DictInternal.cend(); ++it)
  {
    const Tag &       t = it->first;
    const DictEntry & de = it->second;
    os << t << " " << de << '\n';
  }

  return os;
}

/**
 * Private Dict
 */
class MDCM_EXPORT PrivateDict
{
  typedef std::map<PrivateTag, DictEntry> MapDictEntry;
  friend std::ostream &
  operator<<(std::ostream &, const PrivateDict &);

public:
  PrivateDict() = default;
  ~PrivateDict() = default;
  MDCM_DISALLOW_COPY_AND_MOVE(PrivateDict);

  void
  AddDictEntry(const PrivateTag & tag, const DictEntry & de)
  {
#ifndef NDEBUG
    MapDictEntry::size_type s = DictInternal.size();
#endif
    DictInternal.insert(MapDictEntry::value_type(tag, de));
#ifndef NDEBUG
    assert(s < DictInternal.size());
#endif
  }

  bool
  RemoveDictEntry(const PrivateTag & tag)
  {
    MapDictEntry::size_type s = DictInternal.erase(tag);
    assert(s == 1 || s == 0);
    return s == 1;
  }

  bool
  FindDictEntry(const PrivateTag & tag) const
  {
    MapDictEntry::const_iterator it = DictInternal.find(tag);
    if (it == DictInternal.cend())
    {
      return false;
    }
    return true;
  }

  const DictEntry &
  GetDictEntry(const PrivateTag & tag) const
  {
    MapDictEntry::const_iterator it = DictInternal.find(tag);
    if (it == DictInternal.cend())
    {
      return tagNotFound;
    }
    assert(DictInternal.count(tag) == 1);
    return it->second;
  }

  void
  PrintXML() const
  {
    MapDictEntry::const_iterator it = DictInternal.cbegin();
    std::cout << "<dict edition=\"2008\">\n";
    for (; it != DictInternal.cend(); ++it)
    {
      const PrivateTag & t = it->first;
      const DictEntry &  de = it->second;
      std::cout << "  <entry group=\"" << std::hex << std::setw(4) << std::setfill('0') << t.GetGroup() << "\""
                << " element=\"xx" << std::setw(2) << std::setfill('0') << t.GetElement() << "\""
                << " vr=\"" << de.GetVR() << "\" vm=\"" << de.GetVM() << "\" owner=\"" << t.GetOwner();
      const char * name = de.GetName();
      if (*name == 0)
      {
        std::cout << "\"/>\n";
      }
      else
      {
        std::cout << "\" name=\"" << de.GetName() << "\"/>\n";
      }
    }
    std::cout << "</dict>\n";
  }

  bool
  IsEmpty() const
  {
    return DictInternal.empty();
  }

protected:
  friend class Dicts;
  void
  LoadDefault();

private:
  MapDictEntry DictInternal;
};

inline std::ostream &
operator<<(std::ostream & os, const PrivateDict & val)
{
  PrivateDict::MapDictEntry::const_iterator it = val.DictInternal.cbegin();
  for (; it != val.DictInternal.cend(); ++it)
  {
    const PrivateTag & t = it->first;
    const DictEntry &  de = it->second;
    os << t << " " << de << '\n';
  }
  return os;
}

} // end namespace mdcm

#endif // MDCMDICT_H
