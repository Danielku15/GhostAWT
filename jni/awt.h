#ifndef AWT_H_
#define AWT_H_

#include "commons.h"

#define AWT_INITIDS_STUB(classname) \
JNIEXPORT void JNICALL \
Java_java_awt_##classname##_initIDs(JNIEnv *env, jclass cls) \
{ \
}

#endif /* AWT_H_ */
