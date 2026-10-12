#include "bus.hpp"
#include "memory_consts.hpp"

Bus::Bus(
	std::array<std::uint8_t, MemoryConsts::Sizes::PHYSICAL_MEM_SIZE> *physical_mem,
	std::array<std::uint8_t, MemoryConsts::Sizes::VIDEO_MEM_SIZE> *video_mem,
	std::array<std::uint8_t, MemoryConsts::Sizes::EXPANSION_MEM_SIZE> *expansion_mem,
	std::array<std::uint8_t, MemoryConsts::Sizes::BIOS_MEM_SIZE> *bios_mem)
{
	this->physical_mem = physical_mem;
	this->video_mem = video_mem;
	this->expansion_mem = expansion_mem;
	this->bios_mem = bios_mem;
}

Bus::~Bus()
{
}

std::uint8_t Bus::read_byte(std::uint32_t address)
{
	// TODO: verify if need to break down these ranges
	// further. Likely for IVT + BIOS data area.
	if (address >= MemoryConsts::Boundaries::PHYSICAL_MEM_LOWER_BOUNDARY 
		&& address <= MemoryConsts::Boundaries::PHYSICAL_MEM_UPPER_BOUNDARY)
	{
		if (address > MemoryConsts::Sizes::PHYSICAL_MEM_SIZE)
		{
			return 0xFF;
		}

		return (*physical_mem)[address];
	}

	if (address >= MemoryConsts::Boundaries::VIDEO_MEM_LOWER_BOUNDARY 
		&& address <= MemoryConsts::Boundaries::VIDEO_MEM_UPPER_BOUNDARY)
	{
		// TODO: implement EGA vs MDA vs CGA logic mem ranges.
		return (*video_mem)[address - MemoryConsts::Boundaries::VIDEO_MEM_LOWER_BOUNDARY];
	}

	if (address >= MemoryConsts::Boundaries::EXPANSION_MEM_LOWER_BOUNDARY 
		&& address <= MemoryConsts::Boundaries::EXPANSION_MEM_UPPER_BOUNDARY)
	{
		return (*expansion_mem)[address - MemoryConsts::Boundaries::EXPANSION_MEM_LOWER_BOUNDARY];
	}

	if (address >= MemoryConsts::Boundaries::BIOS_MEM_LOWER_BOUNDARY
		&& address <= MemoryConsts::Boundaries::BIOS_MEM_UPPER_BOUNDARY)
	{
		return (*bios_mem)[address - MemoryConsts::Boundaries::BIOS_MEM_LOWER_BOUNDARY];
	}

	return 0x00;
}

void Bus::write_byte(std::uint32_t address, std::uint8_t value)
{
	if (address >= MemoryConsts::Boundaries::PHYSICAL_MEM_LOWER_BOUNDARY 
		&& address <= MemoryConsts::Boundaries::PHYSICAL_MEM_UPPER_BOUNDARY)
	{
		(*physical_mem)[address] = value;
	}

	if (address >= MemoryConsts::Boundaries::VIDEO_MEM_LOWER_BOUNDARY 
		&& address <= MemoryConsts::Boundaries::VIDEO_MEM_UPPER_BOUNDARY)
	{
		// TODO: implement EGA vs MDA vs CGA logic mem ranges.
		(*video_mem)[address - MemoryConsts::Boundaries::VIDEO_MEM_LOWER_BOUNDARY] = value;
	}

	if (address >= MemoryConsts::Boundaries::EXPANSION_MEM_LOWER_BOUNDARY 
		&& address <= MemoryConsts::Boundaries::EXPANSION_MEM_UPPER_BOUNDARY)
	{
		(*expansion_mem)[address - MemoryConsts::Boundaries::EXPANSION_MEM_LOWER_BOUNDARY] = value;
	}

	if (address >= MemoryConsts::Boundaries::BIOS_MEM_LOWER_BOUNDARY
		&& address <= MemoryConsts::Boundaries::BIOS_MEM_UPPER_BOUNDARY)
	{
		(*bios_mem)[address - MemoryConsts::Boundaries::BIOS_MEM_LOWER_BOUNDARY] = value;
	}
}
