#pragma once
#include <array>
#include "cpu8088.hpp"

class System
{
	public:
		// TOOD: read/write 16-bit words?
		std::uint8_t read_byte(std::uint32_t address);
		void write_byte(std::uint32_t address, std::uint8_t value);

		System();
		~System();

	private:
		// TODO: move address boundaries into constexprs.
		static constexpr int PHYSICAL_MEM_SIZE_K = 128;

		std::array<std::uint8_t, PHYSICAL_MEM_SIZE_K * 1024> physical_mem { 0x00 }; // 0K -> 640K
		std::array<std::uint8_t, 128 * 1024> video_mem { 0x00 }; // 640K -> 768K
		std::array<std::uint8_t, 192 * 1024> expansion_mem { 0x00 }; // 768K -> 960K
		std::array<std::uint8_t, 40 * 1024> bios_mem { 0x00 }; // 960K -> 1MB
		CPU8088 cpu;

	};
