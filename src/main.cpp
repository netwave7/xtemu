#include "system.hpp"
#include <iostream>
#include <format>
#include <vector>

int main(int argc, char **argv)
{
	System system;

	std::vector<std::uint32_t> test_addresses = 
	{
		0xFFFFB,
		0xBAC33,
		0x22004,
		0x5698B
	};

	for (const auto &addr : test_addresses)
	{
		std::cout << "MEM READ: " << std::format("0x{:02X}\n", system.cpu->read_byte(addr));
	}

	return 0;
}
