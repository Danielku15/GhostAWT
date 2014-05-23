#ifndef FONTMANAGER_H_
#define FONTMANAGER_H_

#include "commons.h"

typedef struct GlyphInfo {
	float advanceX;
	float advanceY;
	unsigned short width;
	unsigned short height;
	unsigned short rowBytes;
	unsigned char managed;
	float topLeftX;
	float topLeftY;
	void *cellInfo;
	unsigned char *image;
} GlyphInfo;


typedef struct FontManagerNativeIDs {

    // sun.font.Font2D
    jmethodID getMapperMID;
    jmethodID getTableBytesMID;
    jmethodID canDisplayMID;
    jmethodID f2dCharToGlyphMID;

    // sun.font.CharToGlyphMapper
    jmethodID charToGlyphMID;

    // sun.font.PhysicalStrike
    jmethodID getGlyphMetricsMID;
    jmethodID getGlyphPointMID;
    jmethodID adjustPointMID;
    jfieldID  pScalerContextFID;

    // java.awt.geom.Rectangle2D.Float
    jclass rect2DFloatClass;
    jmethodID rect2DFloatCtr;
    jmethodID rect2DFloatCtr4;
    jfieldID rectF2DX, rectF2DY, rectF2DWidth, rectF2DHeight;

    // java.awt.geom.Point2D.Float
    jclass pt2DFloatClass;
    jmethodID pt2DFloatCtr;
    jfieldID xFID, yFID;

    // java.awt.geom.GeneralPath
    jclass gpClass;
    jmethodID gpCtr;
    jmethodID gpCtrEmpty;

    // sun.font.StrikeMetrics
    jclass strikeMetricsClass;
    jmethodID strikeMetricsCtr;

    // sun.font.TrueTypeFont
    jmethodID ttReadBlockMID;
    jmethodID ttReadBytesMID;

    // sun.font.Type1Font
    jmethodID readFileMID;

    // sun.font.GlyphList
    jfieldID glyphListX, glyphListY, glyphListLen,
      glyphImages, glyphListUsePos, glyphListPos, lcdRGBOrder, lcdSubPixPos;
} FontManagerNativeIDs;

extern FontManagerNativeIDs sunFontIDs;
JNIEXPORT FontManagerNativeIDs getSunFontIDs();

#endif /* FONTMANAGER_H_ */
