#include "system.hpp"

System::System()
{

}

System::~System()
{

}

std::uint8_t System::read_byte(std::uint32_t address)
{
	// TODO: verify if need to break down these ranges
	// further. Likely for IVT + BIOS data area.
	if (address >= 0x00000 && address <= 0x9FFFFF)
	{
		return physical_mem[address];
	}

	if (address >= 0xA0000 && address <= 0xBFFFF)
	{
		// TODO: implement EGA vs MDA vs CGA logic mem ranges.
		return video_mem[address - 0xBFFFF];
	}

	if (address >= 0xC0000 && address <= 0xEFFFF)
	{
		return expansion_mem[address - 0xEFFFF];
	}

	if (address >= 0xF0000 && address <= 0xFFFFF)
	{
		return bios_mem[address - 0xFFFFF];
	}

	return 0x00;
}

void System::write_byte(std::uint32_t address, std::uint8_t value)
{
	if (address >= 0x00000 && address <= 0x9FFFFF)
	{
		physical_mem[address] = value;
	}

	if (address >= 0xA0000 && address <= 0xBFFFF)
	{
		// TODO: implement EGA vs MDA vs CGA logic mem ranges.
		video_mem[address - 0xBFFFF] = value;
	}

	if (address >= 0xC0000 && address <= 0xEFFFF)
	{
		expansion_mem[address - 0xEFFFF] = value;
	}

	if (address >= 0xF0000 && address <= 0xFFFFF)
	{
		bios_mem[address - 0xFFFFF] = value;
	}
}
