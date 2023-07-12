Warning, the Readme is WIP

2023c

Note: Message Exchange (Part7a.xml, Part7b.xml) files were not updated (unused in MDCM, TODO)!


Attributes
----------

1.
optionally 1st update version in Part6.xsl, e.g. <dicts edition="2023c">

xsltproc Part6.xsl part06.xml > Part6.xml

2.
xsltproc TagKeywords.xsl Part6.xml > mdcmTagKeywords.h

removed/comment tags without name:
typedef mdcm::Attribute<0x0008, 0x0202> ;
typedef mdcm::Attribute<0x0018, 0x0061> ;
typedef mdcm::Attribute<0x0018, 0x9445> ;
typedef mdcm::Attribute<0x0028, 0x0020> ;
typedef mdcm::Attribute<0x0400, 0x0315> ;
typedef mdcm::Attribute<0x300a, 0x0782> ;

3.
xsltproc TagToType.xsl Part6.xml > mdcmTagToType.h

4.
xsltproc TagToVR.xsl Part6.xml > mdcmTagToVR.cxx

5.
xsltproc DefaultDicts.xsl Part6.xml > mdcmDefaultDicts.cxx

removed duplicated entries (0x7fe0,0x0010), (0x7fe0,0x0020), (0x7fe0,0x0030), (0x7fe0, 0x0040)

UIDs
----

xsltproc UIDToTemp.xsl Part6.xml > tmp.cxx

Retired -> Retired0
Retired -> Retired1
12leadECGWaveformStorage -> ECG12leadWaveformStorage

Recommended: diff 'UIDsStrings' and add new UIDs to mdcmUIDs.h/.cxx, it is much easier,
otherwise caution with private entries.
