#pragma once

#include "Fact.h"
#include <windows.h>

class Sanitizer : public Fact {
public:
	bool test();
private:
	void asanTest();
	void poisonMemoryRegion();
};