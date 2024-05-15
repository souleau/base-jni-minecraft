#include "jvm.h"

void jvm::load()
{
	JNI_GetCreatedJavaVMs(&vm, 1l, nullptr);

	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_2) == JNI_EDETACHED)
	{
		vm->AttachCurrentThreadAsDaemon(reinterpret_cast<void**>(&env), nullptr);
	}
}

c_jobject::c_jobject(jobject object_in)
{
	this->cached_object = object_in;
}

c_jobject::~c_jobject()
{
	if (this->cached_object != nullptr)
	{
		jvm::env->DeleteLocalRef(this->cached_object);
	}
}