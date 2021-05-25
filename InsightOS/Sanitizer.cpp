#include "Sanitizer.h"
#include <iostream>
#include <stdlib.h>

bool Sanitizer::test() {
	// asanTest();

	poisonMemoryRegion();

	return true;
}

void Sanitizer::asanTest() {
	int x[100];
	printf("Hello! \n");
	x[100] = 5;
}

extern "C" void __asan_poison_memory_region(void*, size_t);// mark unaddressable
extern "C" void __asan_unpoison_memory_region(void const volatile* addr, size_t size);// mark addressable

// A developer can manually poison memory to customize debugging
void Sanitizer::poisonMemoryRegion() {
	char* x = new char[16];
	x[10] = 0;
	__asan_poison_memory_region(x, 16);
	//__asan_unpoison_memory_region(x, 16);
	int res = x[10];

	std::cout << "x[10]=" << res << std::endl;

	delete[] x;
}