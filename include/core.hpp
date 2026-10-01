#pragma once
#include <array>
#include "cpu8088.hpp"

class Core
{
	private:
		std::array<std::uint8_t, 128 * 1024> memory; // KB
		CPU8088 cpu;


	public:
		Core();
		~Core();

};
