#pragma once
#include <cstdint>

namespace MemoryConsts
{
	namespace Sizes
	{
		constexpr int PHYSICAL_MEM_SIZE = 128 * 1024; // Max 640K.
		constexpr int VIDEO_MEM_SIZE = 128 * 1024;
		constexpr int EXPANSION_MEM_SIZE = 192 * 1024;
		constexpr int BIOS_MEM_SIZE = 64 * 1024;
	}

	namespace Boundaries
	{
		constexpr std::uint32_t PHYSICAL_MEM_LOWER_BOUNDARY = 0x00000;
		constexpr std::uint32_t PHYSICAL_MEM_UPPER_BOUNDARY = 0x9FFFF;

		constexpr std::uint32_t VIDEO_MEM_LOWER_BOUNDARY = 0xA0000;
		constexpr std::uint32_t VIDEO_MEM_UPPER_BOUNDARY = 0xBFFFF;

		constexpr std::uint32_t EXPANSION_MEM_LOWER_BOUNDARY = 0xC0000;
		constexpr std::uint32_t EXPANSION_MEM_UPPER_BOUNDARY = 0xEFFFF;

		constexpr std::uint32_t BIOS_MEM_LOWER_BOUNDARY = 0xF0000;
		constexpr std::uint32_t BIOS_MEM_UPPER_BOUNDARY = 0xFFFFF;
	}
};
