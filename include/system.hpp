#pragma once
#include <array>
#include <memory>
#include "cpu8088.hpp"
#include "memory_consts.hpp"

class System
{
	public:
		System();
		~System();

		std::unique_ptr<CPU8088> cpu;

	private:
		std::unique_ptr<std::array<std::uint8_t, MemoryConsts::Sizes::PHYSICAL_MEM_SIZE>> physical_mem; // 0K ->> 640K
		std::unique_ptr<std::array<std::uint8_t, MemoryConsts::Sizes::VIDEO_MEM_SIZE>> video_mem; // 640K ->> 768K
		std::unique_ptr<std::array<std::uint8_t, MemoryConsts::Sizes::EXPANSION_MEM_SIZE>> expansion_mem; // 768K ->> 960K
		std::unique_ptr<std::array<std::uint8_t, MemoryConsts::Sizes::BIOS_MEM_SIZE>> bios_mem; // 960K ->> 1MB

		std::unique_ptr<Bus> bus;
};
