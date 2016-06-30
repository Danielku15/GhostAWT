#ifndef COMMONS_H_
#define COMMONS_H_

#include <jni.h>
#include <stdint.h>

#define INITIDS_STUB(classname) \
JNIEXPORT void JNICALL \
Java_##classname##_initIDs(JNIEnv *env, jclass cls) \
{ \
}

#if defined(__LP__) || defined(_LP64) || defined(__x86_64__)
#define jlong_to_ptr(a) ((void*)(a))
#define ptr_to_jlong(a) ((jlong)(a))
#else
#define jlong_to_ptr(a) ((void*)(int)(a))
#define ptr_to_jlong(a) ((jlong)(int)(a))
#endif

#endif /* COMMONS_H_ */
