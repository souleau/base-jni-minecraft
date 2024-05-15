#include "cls.h"
#include "../jvm.h"

void cls::load()
{
	minecraft_cls = jvm::env->FindClass("ave");
}