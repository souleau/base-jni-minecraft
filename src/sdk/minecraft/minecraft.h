#pragma once
#include "../jvm.h"


class mc : public c_jobject
{
public:
	mc(jobject object_in);

	static mc getMinecraft();
};