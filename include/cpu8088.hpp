#pragma once
#include <cstdint>

struct CPU8088
{
	/* == General purpose registers == */
	struct {
		std::uint8_t al;
		std::uint8_t ah;
	} ax; // Accumulator

	struct {
		std::uint8_t bl;
		std::uint8_t bh;
	} bx; // Base Register

		struct {
		std::uint8_t cl;
		std::uint8_t ch;
	} cx; // Counter Register

	struct {
		std::uint8_t dl;
		std::uint8_t dh;
	} dx; // Data Register

	/* == Segment Registers == */
	std::uint16_t cs; // Code Segment: points to segment for executable program instructions
	std::uint16_t ds; // Data Segment: points to segment used for program data
	std::uint16_t ss; // Stack Segment: points to segment for system stack (temp storage)
	std::uint16_t es; // Extra Segment: aditional segment register for extra data storage

	/* == Pointers and Index Registers == */
	std::uint16_t sp; // Stack Pointer: points to top of stack within stack segment
	std::uint16_t bp; // Base Pointer: points to data within the stack, often used for passing parameters
	std::uint16_t si; // Source Index: used as source address pointer for string and block data manipulations
	std::uint16_t di; // Destination Index: used as a destination address pointer for string operations

	std::uint16_t ip; // Instruction Pointer: contains the 16-bit offset of the next instructions to be fetched + executed within the code segment

	/* == Flag Register == */
	// | TF | DF | IF | OF | SF | ZF | AF | PF | CF
	// | Trap | Direction | Interrupt | Overflow | Sign | Zero | Aux Carry | Parity | Carry |
	// Bits 7, 6, 5 are control flags, typically controlled by software and control how the processor runs.
	// Bits 4, 3, 2, 1, 0 are status flags, usually set by the previous operation.
	std::uint16_t flags;
};
