#ifndef COMMONS_H_
#define COMMONS_H_

#include <jni.h>

#define INITIDS_STUB(classname) \
JNIEXPORT void JNICALL \
Java_##classname##_initIDs(JNIEnv *env, jclass cls) \
{ \
}

#ifdef _LP64
#define jlong_to_ptr(a) ((void*)(a))
#define ptr_to_jlong(a) ((jlong)(a))
#else
#define jlong_to_ptr(a) ((void*)(int)(a))
#define ptr_to_jlong(a) ((jlong)(int)(a))
#endif

# ifndef _UINTPTR_T_DEFINED
#  define _UINTPTR_T_DEFINED
#  ifdef _LP64
     typedef unsigned __int64 uintptr_t;
#  else
     typedef unsigned int uintptr_t;
#  endif
# endif


#endif /* COMMONS_H_ */
