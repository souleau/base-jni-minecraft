#include "minecraft.h"
#include "../jvm.h"
#include "../classes/cls.h"

mc::mc(jobject object_in) : c_jobject(object_in)
{

}

mc mc::getMinecraft()
{
	static jmethodID getMinecraftMethod = jvm::env->GetStaticMethodID(cls::minecraft_cls, "A", "()Lave;");

	return mc(jvm::env->CallStaticObjectMethod(cls::minecraft_cls, getMinecraftMethod));

}