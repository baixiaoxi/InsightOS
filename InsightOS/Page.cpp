#include "Page.h"
#include <iostream>

bool Page::test() {
	size_t pageSize = 0;// 页大小
	size_t allocGranularity = 0;// 分配粒度
	size_t numAddressBits = 0;// 地址位数
	size_t virtualMemoryLimit = size_t(-1);// 虚拟内存上限
#ifdef X64
	size_t minValidAddress = 0;// 最小地址
	size_t maxValidAddress = 0;// 最大地址
#endif

#ifdef XP_WIN
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	pageSize = sysinfo.dwPageSize;// 页大小
	allocGranularity = sysinfo.dwAllocationGranularity;// 颗粒度
#else
	pageSize = size_t(sysconf(_SC_PAGESIZE));// 页大小
	allocGranularity = pageSize;
#endif

#ifdef X64
#ifdef XP_WIN
	minValidAddress = size_t(sysinfo.lpMinimumApplicationAddress);
	maxValidAddress = size_t(sysinfo.lpMaximumApplicationAddress);
	numAddressBits = 0;//mozilla::FloorLog2(maxValidAddress) + 1;
#else
	numAddressBits = FindAddressLimit();
	minValidAddress = allocGranularity;
	maxValidAddress = (UINT64_C(1) << numAddressBits) - 1 - allocGranularity;
#endif
#else
	numAddressBits = 32;
#endif
	std::cout << "Page####################################################################" << std::endl;
	std::cout << "pageSize:" << pageSize
		<< ", allocGranularity=" << allocGranularity
		<< ", numAddressBits=" << numAddressBits
		<< ", virtualMemoryLimit=" << virtualMemoryLimit
		<< std::endl;

#ifdef X64
	std::cout << "minValidAddress=" << minValidAddress
		<< ", maxValidAddress=" << maxValidAddress
		<< std::endl;
#endif

	return true;
}