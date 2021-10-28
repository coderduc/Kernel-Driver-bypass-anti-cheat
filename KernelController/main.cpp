#include <iostream>
#include "kernel_interface.h"
#include "offsets.h"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\mfk");

	ULONG address = Driver.GetClientAddress();
	ULONG processid = Driver.GetProcessId();

	std::cout << " Client Address " << std::hex << address << std::endl;
	std::cout << " ProcessID " << processid << std::endl;

	while (true)
	{
		uint32_t base = Driver.ReadVirtualMemory<uint32_t>(processid, 0x0014FF78, sizeof(uint32_t));
		std::cout << base << std::endl;
	}
}
