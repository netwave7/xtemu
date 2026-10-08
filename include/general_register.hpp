#pragma once
#include <cstdint>

class GeneralRegister {
public:
	std::uint16_t value = 0x0000;

	std::uint8_t &low_byte() {
		return reinterpret_cast<std::uint8_t*>(&value)[0];
	}

	std::uint8_t &high_byte() {
		return reinterpret_cast<std::uint8_t*>(&value)[0];
	}
};
