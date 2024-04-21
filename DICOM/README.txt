Warning, the Readme is WIP

Currently DICOM is 2024b

Note: Message Exchange (Part7a.xml, Part7b.xml) files were not updated, the attributes
seem to be valid and they are not really used in MDCM (TODO check how to update).


Attributes
----------

1.
Update DICOM version in Part6.xsl, e.g. <dicts edition="2023c">

xsltproc Part6.xsl part06.xml > Part6.xml

2.
xsltproc TagKeywords.xsl Part6.xml > mdcmTagKeywords.h

remove tags without name:
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

removed retired duplicated entries (0x7fe0,0x0010), (0x7fe0,0x0020), (0x7fe0,0x0030), (0x7fe0,0x0040)
removed { 0x1010,0x0000,VR::US,VM::VM1_n,"Zonal Map","ZonalMap",true }, retired, possible conflict with group length

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
they can be added manualy (there will be ~25000 useless lines):

(0028,04x0) - (0028,04x3) are in the file 0028_04x3_retired.txt.7z
(0028,08x0) - (0028,08x8) are in the file 0028_08x8_retired.txt.7z
(1000,xxx0) - (1000,xxx5) are in the file 1000_xxx5_retired.txt.7z



UIDs
----

xsltproc UIDToTemp.xsl Part6.xml > tmp.cxx

I add new UIDs manually:
diff 'UIDsStrings' array and with last_UIDsStrings.txt and add new UIDs to mdcmUIDs.h/.cxx,
replace last_UIDsStrings.txt for the next time (if lost run above xsltproc with the previous
Part6.xml).

If recreate completely:
don't forget private UIDs (!) and change
Retired -> Retired0
Retired -> Retired1
12leadECGWaveformStorage -> ECG12leadWaveformStorage

more post-processing may be required (replace dots, etc.)!
