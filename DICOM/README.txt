Warning, the Readme is WIP, not complete!!

2021d

Notes:
 * C++ files were post-processed with clang-format 8
 * Message Exchange (Part7a.xml, Part7b.xml) files were not updated (should be no problem at all)


Attributes
----------
1. xsltproc Part6.xsl part06.xml > Part6.xml

2. xsltproc TagKeywords.xsl Part6.xml > mdcmTagKeywords.h

removed tags without name:
typedef mdcm::Attribute<0x0008, 0x0202> ;
typedef mdcm::Attribute<0x0018, 0x0061> ;
typedef mdcm::Attribute<0x0018, 0x9445> ;
typedef mdcm::Attribute<0x0028, 0x0020> ;
typedef mdcm::Attribute<0x0400, 0x0315> ;
typedef mdcm::Attribute<0x300a, 0x0782> ;

3. xsltproc TagToType.xsl Part6.xml > mdcmTagToType.h

4. xsltproc TagToVR.xsl Part6.xml > mdcmTagToVR.cxx

5. xsltproc DefaultDicts.xsl Part6.xml > mdcmDefaultDicts.cxx

UIDs
----

1. xsltproc UIDToTemp.xsl Part6.xml > tmp.cxx

2. Manually copy arrays to gdcmUIDs.h and gdcmUIDs.cxx

Retired -> Retired0
Retired -> Retired1
// 12leadECGWaveformStorage -> ECG12leadWaveformStorage

