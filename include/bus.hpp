#pragma once
#include <cstdint>
#include <array>
#include "memory_consts.hpp"

class Bus 
{
	private:
		std::array<std::uint8_t, MemoryConsts::Sizes::PHYSICAL_MEM_SIZE> *physical_mem = nullptr;
		std::array<std::uint8_t, MemoryConsts::Sizes::VIDEO_MEM_SIZE> *video_mem = nullptr;
		std::array<std::uint8_t, MemoryConsts::Sizes::EXPANSION_MEM_SIZE> *expansion_mem = nullptr;
		std::array<std::uint8_t, MemoryConsts::Sizes::BIOS_MEM_SIZE> *bios_mem = nullptr;


	public:
		std::uint8_t read_byte(std::uint32_t address);
		void write_byte(std::uint32_t address, std::uint8_t value);

		Bus(
			std::array<std::uint8_t, MemoryConsts::Sizes::PHYSICAL_MEM_SIZE> *physical_mem,
			std::array<std::uint8_t, MemoryConsts::Sizes::VIDEO_MEM_SIZE> *video_mem,
			std::array<std::uint8_t, MemoryConsts::Sizes::EXPANSION_MEM_SIZE> *expansion_mem,
			std::array<std::uint8_t, MemoryConsts::Sizes::BIOS_MEM_SIZE> *bios_mem
		);

		~Bus();
};
