Warning, WIP


Attributes
----------


Note: Message Exchange (Part7a.xml, Part7b.xml) files will not be updated,
the attributes seem to be valid and they are not really used in MDCM.


1.
It is recommended to update DICOM version in Part6.xsl before to
have correct version in generated Part6.xml,
(search the line '<dicts edition=', e.g. <dicts edition="2026b">).


xsltproc Part6.xsl part06.xml > Part6.xml


2.
xsltproc TagKeywords.xsl Part6.xml > mdcmTagKeywords.h


Remove invalid retired tags without name (search '> ;'):
typedef mdcm::Attribute<0x0008, 0x0202> ;
typedef mdcm::Attribute<0x0018, 0x0061> ;
typedef mdcm::Attribute<0x0018, 0x9445> ;
typedef mdcm::Attribute<0x0028, 0x0020> ;
typedef mdcm::Attribute<0x0400, 0x0315> ;
typedef mdcm::Attribute<0x300a, 0x0782> ;


3.
xsltproc TagToType.xsl Part6.xml > mdcmTagToType.h


4.
xsltproc TagToVR.xsl Part6.xml > mdcmTagToVR.h


5.
xsltproc DefaultDicts.xsl Part6.xml > mdcmDefaultDicts.cxx

Some attributes will fail:

Problem with element:(0028,04x0)
Problem with element:(0028,04x1)
Problem with element:(0028,04x2)
Problem with element:(0028,04x3)
Problem with element:(0028,08x0)
Problem with element:(0028,08x2)
Problem with element:(0028,08x3)
Problem with element:(0028,08x4)
Problem with element:(0028,08x8)
Problem with element:(1000,xxx0)
Problem with element:(1000,xxx1)
Problem with element:(1000,xxx2)
Problem with element:(1000,xxx3)
Problem with element:(1000,xxx4)
Problem with element:(1000,xxx5)

They are all retired and there will be conficts and they are useless,
they can be added manualy (don't do it, there will be ~25000 useless lines, it
will be most likely never required)

(0028,04x0) - (0028,04x3) are in the file 0028_04x3_retired.txt.7z
(0028,08x0) - (0028,08x8) are in the file 0028_08x8_retired.txt.7z
(1000,xxx0) - (1000,xxx5) are in the file 1000_xxx5_retired.txt.7z

Very important:
to avoid conflicts: remove (comment) retired duplicated entries:
  //{ 0x7fe0,0x0010,VR::OB_OW,VM::VM1,"Variable Pixel Data","VariablePixelData",true },
  //{ 0x7fe0,0x0020,VR::OW,VM::VM1,"Variable Coefficients SDVN","VariableCoefficientsSDVN",true },
  //{ 0x7fe0,0x0030,VR::OW,VM::VM1,"Variable Coefficients SDHN","VariableCoefficientsSDHN",true },
  //{ 0x7fe0,0x0040,VR::OW,VM::VM1,"Variable Coefficients SDDN","VariableCoefficientsSDDN",true },
  //{ 0x1010,0x0000,VR::US,VM::VM1_n,"Zonal Map","ZonalMap",true },





UIDs
----

xsltproc UIDToTemp.xsl Part6.xml > tmp.cxx


I add new UIDs manually sequentially
(there are usually only several new UIDs, if any):
diff 'UIDsStrings' array (e.g. copy from tmp.cxx and paste in an new file) with
the last_UIDsStrings.txt and add manually new UIDs to mdcmUIDs.h/.cxx.

Replace last_UIDsStrings.txt for the next time (if lost -- run the above xsltproc
command with the previous Part6.xml).
Edit mdcmUIDs.h/.cxx. It is tricky, caution with enums, increment.


UID can be recreated completely:
don't forget private UIDs (!) and change
Retired -> Retired0
Retired -> Retired1
12leadECGWaveformStorage -> ECG12leadWaveformStorage
more post-processing may be required (replace dots, etc.)!

