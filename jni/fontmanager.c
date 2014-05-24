#include <stdlib.h>
#include "fontmanager.h"

// the TrueType font library requires those id's
JNIEXPORT void JNICALL
Java_sun_font_SunFontManager_initIDs(JNIEnv *env, jclass cls) {
	jclass javaClass = (*env)->FindClass(env, "sun/font/TrueTypeFont");
	sunFontIDs.ttReadBlockMID = (*env)->GetMethodID(env, javaClass, "readBlock",
			"(Ljava/nio/ByteBuffer;II)I");
	sunFontIDs.ttReadBytesMID = (*env)->GetMethodID(env, javaClass, "readBytes",
			"(II)[B");

	javaClass = (*env)->FindClass(env, "sun/font/Type1Font");
	sunFontIDs.readFileMID = (*env)->GetMethodID(env, javaClass, "readFile",
			"(Ljava/nio/ByteBuffer;)V");

	javaClass = (*env)->FindClass(env, "java/awt/geom/Point2D$Float");
	sunFontIDs.pt2DFloatClass = (jclass) (*env)->NewGlobalRef(env, javaClass);
	sunFontIDs.pt2DFloatCtr = (*env)->GetMethodID(env,
			sunFontIDs.pt2DFloatClass, "<init>", "(FF)V");

	sunFontIDs.xFID = (*env)->GetFieldID(env, sunFontIDs.pt2DFloatClass, "x",
			"F");
	sunFontIDs.yFID = (*env)->GetFieldID(env, sunFontIDs.pt2DFloatClass, "y",
			"F");

	javaClass = (*env)->FindClass(env, "sun/font/StrikeMetrics");
	sunFontIDs.strikeMetricsClass = (jclass) (*env)->NewGlobalRef(env,
			javaClass);

	sunFontIDs.strikeMetricsCtr = (*env)->GetMethodID(env,
			sunFontIDs.strikeMetricsClass, "<init>", "(FFFFFFFFFF)V");

	javaClass = (*env)->FindClass(env, "java/awt/geom/Rectangle2D$Float");
	sunFontIDs.rect2DFloatClass = (jclass) (*env)->NewGlobalRef(env, javaClass);
	sunFontIDs.rect2DFloatCtr = (*env)->GetMethodID(env,
			sunFontIDs.rect2DFloatClass, "<init>", "()V");
	sunFontIDs.rect2DFloatCtr4 = (*env)->GetMethodID(env,
			sunFontIDs.rect2DFloatClass, "<init>", "(FFFF)V");
	sunFontIDs.rectF2DX = (*env)->GetFieldID(env, sunFontIDs.rect2DFloatClass,
			"x", "F");
	sunFontIDs.rectF2DY = (*env)->GetFieldID(env, sunFontIDs.rect2DFloatClass,
			"y", "F");
	sunFontIDs.rectF2DWidth = (*env)->GetFieldID(env,
			sunFontIDs.rect2DFloatClass, "width", "F");
	sunFontIDs.rectF2DHeight = (*env)->GetFieldID(env,
			sunFontIDs.rect2DFloatClass, "height", "F");

	javaClass = (*env)->FindClass(env, "java/awt/geom/GeneralPath");
	sunFontIDs.gpClass = (jclass) (*env)->NewGlobalRef(env, javaClass);
	sunFontIDs.gpCtr = (*env)->GetMethodID(env, sunFontIDs.gpClass, "<init>",
			"(I[BI[FI)V");
	sunFontIDs.gpCtrEmpty = (*env)->GetMethodID(env, sunFontIDs.gpClass,
			"<init>", "()V");

	javaClass = (*env)->FindClass(env, "sun/font/Font2D");
	sunFontIDs.f2dCharToGlyphMID = (*env)->GetMethodID(env, javaClass,
			"charToGlyph", "(I)I");
	sunFontIDs.getMapperMID = (*env)->GetMethodID(env, javaClass, "getMapper",
			"()Lsun/font/CharToGlyphMapper;");
	sunFontIDs.getTableBytesMID = (*env)->GetMethodID(env, javaClass,
			"getTableBytes", "(I)[B");
	sunFontIDs.canDisplayMID = (*env)->GetMethodID(env, javaClass, "canDisplay",
			"(C)Z");

	javaClass = (*env)->FindClass(env, "sun/font/CharToGlyphMapper");
	sunFontIDs.charToGlyphMID = (*env)->GetMethodID(env, javaClass,
			"charToGlyph", "(I)I");

	javaClass = (*env)->FindClass(env, "sun/font/PhysicalStrike");
	sunFontIDs.getGlyphMetricsMID = (*env)->GetMethodID(env, javaClass,
			"getGlyphMetrics", "(I)Ljava/awt/geom/Point2D$Float;");
	sunFontIDs.getGlyphPointMID = (*env)->GetMethodID(env, javaClass,
			"getGlyphPoint", "(II)Ljava/awt/geom/Point2D$Float;");
	sunFontIDs.adjustPointMID = (*env)->GetMethodID(env, javaClass,
			"adjustPoint", "(Ljava/awt/geom/Point2D$Float;)V");
	sunFontIDs.pScalerContextFID = (*env)->GetFieldID(env, javaClass,
			"pScalerContext", "J");

	javaClass = (*env)->FindClass(env, "sun/font/GlyphList");
	sunFontIDs.glyphListX = (*env)->GetFieldID(env, javaClass, "x", "F");
	sunFontIDs.glyphListY = (*env)->GetFieldID(env, javaClass, "y", "F");
	sunFontIDs.glyphListLen = (*env)->GetFieldID(env, javaClass, "len", "I");
	sunFontIDs.glyphImages = (*env)->GetFieldID(env, javaClass, "images", "[J");
	sunFontIDs.glyphListUsePos = (*env)->GetFieldID(env, javaClass,
			"usePositions", "Z");
	sunFontIDs.glyphListPos = (*env)->GetFieldID(env, javaClass, "positions",
			"[F");
	sunFontIDs.lcdRGBOrder = (*env)->GetFieldID(env, javaClass, "lcdRGBOrder",
			"Z");
	sunFontIDs.lcdSubPixPos = (*env)->GetFieldID(env, javaClass, "lcdSubPixPos",
			"Z");
}

FontManagerNativeIDs sunFontIDs;
JNIEXPORT FontManagerNativeIDs getSunFontIDs() {
	return sunFontIDs;
}

//
// FIleFontStrike
JNIEXPORT jboolean JNICALL Java_sun_font_FileFontStrike_initNative(JNIEnv *env,
		jclass unused) {
	return JNI_FALSE;
}

JNIEXPORT jlong JNICALL
Java_sun_font_FileFontStrike__1getGlyphImageFromWindows(JNIEnv *env,
		jobject unused, jstring fontFamily, jint style, jint size,
		jint glyphCode, jboolean fm) {
	return (jlong) 0;
}

//
// NullFontScaler
static void *theNullScalerContext = NULL;
int isNullScalerContext(void *context) {
	return theNullScalerContext == context;
}

JNIEXPORT jlong JNICALL
Java_sun_font_NullFontScaler_getNullScalerContext(JNIEnv *env, jclass cls) {
	if (theNullScalerContext == NULL) {
		theNullScalerContext = malloc(1);
	}

	return ptr_to_jlong(theNullScalerContext);
}

JNIEXPORT jlong JNICALL Java_sun_font_NullFontScaler_getGlyphImage(JNIEnv *env,
		jobject scaler, jlong pContext, jint glyphCode) {
	void *nullscaler = calloc(sizeof(GlyphInfo), 1);
	return ptr_to_jlong(nullscaler);
}

//
// StrikeCache

JNIEXPORT void JNICALL Java_sun_font_StrikeCache_freeIntMemory(JNIEnv *env,
		jclass cacheClass, jintArray jmemArray, jlong pContext) {

	int len = (*env)->GetArrayLength(env, jmemArray);
	jint* ptrs = (jint*) (*env)->GetPrimitiveArrayCritical(env, jmemArray,
	NULL);
	int i;

	if (ptrs) {
		for (i = 0; i < len; i++) {
			if (ptrs[i] != 0) {
				GlyphInfo *ginfo = (GlyphInfo *) ptrs[i];
				free((void*) ginfo);
			}
		}
		(*env)->ReleasePrimitiveArrayCritical(env, jmemArray, ptrs, JNI_ABORT);
	}
	if (!isNullScalerContext(jlong_to_ptr(pContext))) {
		free(jlong_to_ptr(pContext));
	}
}

JNIEXPORT void JNICALL Java_sun_font_StrikeCache_freeLongMemory(JNIEnv *env,
		jclass cacheClass, jlongArray jmemArray, jlong pContext) {

	int len = (*env)->GetArrayLength(env, jmemArray);
	jlong* ptrs = (jlong*) (*env)->GetPrimitiveArrayCritical(env, jmemArray,
	NULL);
	int i;

	if (ptrs) {
		for (i = 0; i < len; i++) {
			if (ptrs[i] != 0L) {
				GlyphInfo *ginfo = (GlyphInfo *) jlong_to_ptr(ptrs[i]);
				free((void*) ginfo);
			}
		}
		(*env)->ReleasePrimitiveArrayCritical(env, jmemArray, ptrs, JNI_ABORT);
	}
	if (!isNullScalerContext(jlong_to_ptr(pContext))) {
		free(jlong_to_ptr(pContext));
	}
}

JNIEXPORT void JNICALL Java_sun_font_StrikeCache_freeIntPointer(JNIEnv *env,
		jclass cacheClass, jint ptr) {
	if (ptr != 0) {
		free((void*) ptr);
	}
}

JNIEXPORT void JNICALL Java_sun_font_StrikeCache_freeLongPointer(JNIEnv *env,
		jclass cacheClass, jlong ptr) {
	if (ptr != 0L) {
		free(jlong_to_ptr(ptr));
	}
}

JNIEXPORT void JNICALL
Java_sun_font_StrikeCache_getGlyphCacheDescription(JNIEnv *env, jclass cls,
		jlongArray results) {

	jlong* nresults;
	GlyphInfo *info;
	size_t baseAddr;

	if ((*env)->GetArrayLength(env, results) < 13) {
		return;
	}

	nresults = (jlong*) (*env)->GetPrimitiveArrayCritical(env, results, NULL);
	if (nresults == NULL) {
		return;
	}
	info = (GlyphInfo*) calloc(1, sizeof(GlyphInfo));
	if (info == NULL) {
		(*env)->ReleasePrimitiveArrayCritical(env, results, nresults, 0);
		return;
	}
	baseAddr = (size_t) info;
	nresults[0] = sizeof(void*);
	nresults[1] = sizeof(GlyphInfo);
	nresults[2] = 0;
	nresults[3] = (size_t) &(info->advanceY) - baseAddr;
	nresults[4] = (size_t) &(info->width) - baseAddr;
	nresults[5] = (size_t) &(info->height) - baseAddr;
	nresults[6] = (size_t) &(info->rowBytes) - baseAddr;
	nresults[7] = (size_t) &(info->topLeftX) - baseAddr;
	nresults[8] = (size_t) &(info->topLeftY) - baseAddr;
	nresults[9] = (size_t) &(info->image) - baseAddr;
	nresults[10] = (jlong) (uintptr_t) info; /* invisible glyph */
	nresults[11] = (size_t) &(info->cellInfo) - baseAddr;
	nresults[12] = (size_t) &(info->managed) - baseAddr;

	(*env)->ReleasePrimitiveArrayCritical(env, results, nresults, 0);
}

//
// SunLayoutEngine
JNIEXPORT void JNICALL
Java_sun_font_SunLayoutEngine_initGVIDs(JNIEnv *env, jclass cls) {
}

JNIEXPORT void JNICALL Java_sun_font_SunLayoutEngine_nativeLayout(JNIEnv *env,
		jclass cls, jobject font2d, jobject strike, jfloatArray matrix,
		jint gmask, jint baseIndex, jcharArray text, jint start, jint limit,
		jint min, jint max, jint script, jint lang, jint typo_flags, jobject pt,
		jobject gvdata, jlong upem, jlong layoutTables) {
}

//
// DrawGlyphList

JNIEXPORT void JNICALL
Java_sun_java2d_loops_DrawGlyphList_DrawGlyphList(JNIEnv *env, jobject self,
		jobject sg2d, jobject sData, jobject glyphlist) {
}
JNIEXPORT void JNICALL
Java_sun_java2d_loops_DrawGlyphListAA_DrawGlyphListAA(JNIEnv *env, jobject self,
		jobject sg2d, jobject sData, jobject glyphlist) {
}
JNIEXPORT void JNICALL
Java_sun_java2d_loops_DrawGlyphListLCD_DrawGlyphListLCD(JNIEnv *env,
		jobject self, jobject sg2d, jobject sData, jobject glyphlist) {
}

//
// FreetypeFontScale

INITIDS_STUB(sun_font_FreetypeFontScaler)

JNIEXPORT jlong JNICALL
Java_sun_font_FreetypeFontScaler_initNativeScaler(JNIEnv *env, jobject scaler,
		jobject font2D, jint type, jint indexInCollection, jboolean supportsCJK,
		jint filesize) {
	return 0;
}

JNIEXPORT jobject JNICALL
Java_sun_font_FreetypeFontScaler_getFontMetricsNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler) {
	return (*env)->NewObject(env, sunFontIDs.strikeMetricsClass,
			sunFontIDs.strikeMetricsCtr, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

JNIEXPORT jfloat JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphAdvanceNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jint glyphCode) {
	return 0;
}

JNIEXPORT void JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphMetricsNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jint glyphCode, jobject metrics) {
	(*env)->SetFloatField(env, metrics, sunFontIDs.xFID, 0);
	(*env)->SetFloatField(env, metrics, sunFontIDs.yFID, 0);
}

JNIEXPORT jlong JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphImageNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jint glyphCode) {
	GlyphInfo *glyphInfo = (GlyphInfo*) calloc(1, sizeof(GlyphInfo));
	return ptr_to_jlong(glyphInfo);
}

JNIEXPORT jobject JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphOutlineBoundsNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jint glyphCode) {
	return (*env)->NewObject(env, sunFontIDs.rect2DFloatClass,
			sunFontIDs.rect2DFloatCtr);
}

JNIEXPORT jobject JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphOutlineNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jint glyphCode, jfloat xpos, jfloat ypos) {
	return (*env)->NewObject(env, sunFontIDs.gpClass, sunFontIDs.gpCtrEmpty);
}

JNIEXPORT jobject JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphVectorOutlineNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jintArray glyphArray, jint numGlyphs, jfloat xpos, jfloat ypos) {
	return (*env)->NewObject(env, sunFontIDs.gpClass, sunFontIDs.gpCtrEmpty);
}

JNIEXPORT jobject JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphPointNative(JNIEnv *env,
		jobject scaler, jobject font2D, jlong pScalerContext, jlong pScaler,
		jint glyphCode, jint pointNumber) {
	return (*env)->NewObject(env, sunFontIDs.pt2DFloatClass,
			sunFontIDs.pt2DFloatCtr, 0, 0);
}

JNIEXPORT jlong JNICALL
Java_sun_font_FreetypeFontScaler_getLayoutTableCacheNative(JNIEnv *env,
		jobject scaler, jlong pScaler) {
	return 0;
}

JNIEXPORT void JNICALL
Java_sun_font_FreetypeFontScaler_disposeNativeScaler(JNIEnv *env,
		jobject scaler, jlong pScaler) {
}

JNIEXPORT jint JNICALL
Java_sun_font_FreetypeFontScaler_getGlyphCodeNative(JNIEnv *env, jobject scaler,
		jlong pScaler, jchar charCode) {
	return 0;
}

JNIEXPORT jint JNICALL
Java_sun_font_FreetypeFontScaler_getNumGlyphsNative(JNIEnv *env, jobject scaler,
		jlong pScaler) {
	return 1;
}

JNIEXPORT jint JNICALL
Java_sun_font_FreetypeFontScaler_getMissingGlyphCodeNative(JNIEnv *env,
		jobject scaler, jlong pScaler) {
	return 0;
}

JNIEXPORT jlong JNICALL
Java_sun_font_FreetypeFontScaler_getUnitsPerEMNative(JNIEnv *env,
		jobject scaler, jlong pScaler) {
	return 2048;
}

JNIEXPORT jlong JNICALL
Java_sun_font_FreetypeFontScaler_createScalerContextNative(JNIEnv *env,
		jobject scaler, jlong pScaler, jdoubleArray matrix, jint aa, jint fm,
		jfloat boldness, jfloat italic) {
	return 0;
}
