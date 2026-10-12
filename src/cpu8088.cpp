#include "cpu8088.hpp"
#include <iostream>

CPU8088::CPU8088()
{

}

CPU8088::~CPU8088()
{

}

std::uint8_t CPU8088::decode(std::uint8_t opcode)
{
	return 0x00;
}

void CPU8088::connect_bus(Bus *bus)
{
	this->bus = bus;

	std::cout << "Bus connected @ address " << this->bus << std::endl;
}

std::uint8_t CPU8088::read_byte(std::uint32_t address)
{
	return bus->read_byte(address);
}

void CPU8088::write_byte(std::uint32_t address, std::uint8_t value)
{
	bus->write_byte(address, value);
}

