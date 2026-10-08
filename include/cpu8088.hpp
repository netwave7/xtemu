#pragma once
#include <cstdint>
#include "modrm_byte/reg_map.hpp"
#include "general_register.hpp"
#include <memory>
#include <unordered_map>

class CPU8088
{
	private:
		/* == General purpose registers == */
		GeneralRegister ax; // Accumulator
		GeneralRegister bx; // Base register
		GeneralRegister cx; // Counter register
		GeneralRegister dx; // Data register

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

		// ModR/M byte 
		// =================
		// For example, instruction '00 C0'.
		// 00 is the opcode, and C0 is the R/M byte.
		// C0 in binary = 1100000
		// Bits 7-6 = MOD (mode) === 11
		// --> Tells you how to interpret it
		// Bits 5-3 = REG (register) == 000
		// --> Tells you which reigster to use
		// Bits 2-0 = R/M (register / memory) == 000
		// --> Tells you whether to use register or memory addressing mode.
		//
		//std::unordered_map<RegMapByte, std::uint8_t*> reg_map = {
		//	{ RegMapByte::AL, ax.low_byte() },
		//	{ RegMapByte::BL, bx.low_byte() },
		//	{ RegMapByte::CL, cx.low_byte() },
		//	{ RegMapByte::DL, dx.low_byte() },

		//	{ RegMapByte::AH, ax.high_byte() },
		//	{ RegMapByte::BH, bx.high_byte() },
		//	{ RegMapByte::CH, cx.high_byte()},
		//	{ RegMapByte::DH, dx.high_byte() }
		//};

		std::uint8_t fetched_value;
		std::uint16_t absolute_address;
		std::uint16_t relative_address;

	public:
		CPU8088();
		~CPU8088();
};
