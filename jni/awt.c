#include "awt.h"

// empty initIDs implementations for all classes, we won't need the
// references to JVM items in native code since we won't do anything here
AWT_INITIDS_STUB(AWTEvent)
AWT_INITIDS_STUB(Button)
AWT_INITIDS_STUB(Checkbox)
AWT_INITIDS_STUB(CheckboxMenuItem)
AWT_INITIDS_STUB(Color)
AWT_INITIDS_STUB(Component)
AWT_INITIDS_STUB(Container)
AWT_INITIDS_STUB(Cursor)
AWT_INITIDS_STUB(Dialog)
AWT_INITIDS_STUB(Dimension)
AWT_INITIDS_STUB(Event)
AWT_INITIDS_STUB(FileDialog)
AWT_INITIDS_STUB(Font)
AWT_INITIDS_STUB(FontMetrics)
AWT_INITIDS_STUB(Frame)
AWT_INITIDS_STUB(Insets)
AWT_INITIDS_STUB(KeyboardFocusManager)
AWT_INITIDS_STUB(Label)
AWT_INITIDS_STUB(Menu)
AWT_INITIDS_STUB(MenuBar)
AWT_INITIDS_STUB(MenuComponent)
AWT_INITIDS_STUB(MenuItem)
AWT_INITIDS_STUB(Rectangle)
AWT_INITIDS_STUB(Scrollbar)
AWT_INITIDS_STUB(ScrollPane)
AWT_INITIDS_STUB(ScrollPaneAdjustable)
AWT_INITIDS_STUB(TextArea)
AWT_INITIDS_STUB(TextField)
AWT_INITIDS_STUB(Toolkit)
AWT_INITIDS_STUB(TrayIcon)
AWT_INITIDS_STUB(Window)

AWT_INITIDS_STUB(event_InputEvent)
AWT_INITIDS_STUB(event_KeyEvent)
AWT_INITIDS_STUB(event_MouseEvent)

AWT_INITIDS_STUB(image_BufferedImage)
AWT_INITIDS_STUB(image_ColorModel)
AWT_INITIDS_STUB(image_ComponentSampleModel)
AWT_INITIDS_STUB(image_IndexColorModel)
AWT_INITIDS_STUB(image_Kernel)
AWT_INITIDS_STUB(image_Raster)
AWT_INITIDS_STUB(image_SampleModel)
AWT_INITIDS_STUB(image_SinglePixelPackedSampleModel)

INITIDS_STUB(sun_awt_FontDescriptor)
INITIDS_STUB(sun_awt_image_BufImgSurfaceData)
INITIDS_STUB(sun_awt_image_ByteComponentRaster)
INITIDS_STUB(sun_awt_image_BytePackedRaster)
INITIDS_STUB(sun_awt_image_GifImageDecoder)
INITIDS_STUB(sun_awt_image_ImageRepresentation)
INITIDS_STUB(sun_awt_image_IntegerComponentRaster)
INITIDS_STUB(sun_awt_image_ShortComponentRaster)
INITIDS_STUB(sun_awt_PlatformFont)

INITIDS_STUB(sun_java2d_Disposer)
INITIDS_STUB(sun_java2d_loops_GraphicsPrimitiveMgr)
INITIDS_STUB(sun_java2d_pipe_Region)
INITIDS_STUB(sun_java2d_pipe_ShapeSpanIterator)
INITIDS_STUB(sun_java2d_pipe_SpanClipRenderer)
INITIDS_STUB(sun_java2d_SurfaceData)

// AWT might do some direct SunToolkit calls for closing the splashscreen
JNIEXPORT void JNICALL
Java_sun_awt_SunToolkit_closeSplashScreen(JNIEnv *env, jclass cls) {
}

// AWT has an additional native source, we won't need that either
JNIEXPORT void JNICALL
Java_java_awt_AWTEvent_nativeSetSource(JNIEnv *env, jobject self,
		jobject newSource) {
}

// Cursor has an additional finalizeImpl method,
// we haven't allocated anything so nothing to do here
JNIEXPORT void JNICALL
Java_java_awt_Cursor_finalizeImpl(JNIEnv *env, jobject self, jobject newSource) {
}

