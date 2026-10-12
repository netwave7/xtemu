#include "system.hpp"
#include "cpu8088.hpp"
#include "memory_consts.hpp"

System::System()
{
	physical_mem = std::make_unique<std::array<std::uint8_t, MemoryConsts::Sizes::PHYSICAL_MEM_SIZE>>();
	video_mem = std::make_unique<std::array<std::uint8_t, MemoryConsts::Sizes::VIDEO_MEM_SIZE>>();
	expansion_mem = std::make_unique<std::array<std::uint8_t, MemoryConsts::Sizes::EXPANSION_MEM_SIZE>>();
	bios_mem = std::make_unique<std::array<std::uint8_t, MemoryConsts::Sizes::BIOS_MEM_SIZE>>();

	physical_mem->fill(0xF9);
	video_mem->fill(0x24);
	expansion_mem->fill(0xBE);
	bios_mem->fill(0xAD);

	bus = std::make_unique<Bus>(
		physical_mem.get(),
		video_mem.get(),
		expansion_mem.get(),
		bios_mem.get()
	);

	cpu = std::make_unique<CPU8088>();
	cpu->connect_bus(bus.get());
}

System::~System()
{
}
