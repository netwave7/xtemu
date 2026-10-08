#pragma once
#include <string>
#include <functional>
#include <cstdint>

struct Instruction {
	std::uint8_t opcode;
	std::string name;
	std::function<std::uint8_t()> addressing_func;
	std::function<void()> execution_func;
};
