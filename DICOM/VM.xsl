<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="text" indent="yes"/>
<!--
  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.
-->
  <xsl:template name="VMStringToVMType">
    <xsl:param name="vmstring"/>
    <xsl:choose>
      <xsl:when test="string-length($vmstring) = 0">
        <xsl:value-of select="'VM0'"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="concat('VM',translate($vmstring,'-','_'))"/>
      </xsl:otherwise>
    </xsl:choose>
 </xsl:template>
</xsl:stylesheet>
