#pragma once

enum class RegMapByte {
	AL = 0b000,
	BL = 0b011,
	CL = 0b001,
	DL = 0b010,

	AH = 0b100,
	BH = 0b111,
	CH = 0b101,
	DH = 0b110,
};

enum class RegMapWord {
	AX = 0b000,
	BX = 0b011,
	CX = 0b001,
	DX = 0b010,

	SP = 0b100,
	BP = 0b101,
	SI = 0b110,
	DI = 0b111,
};

enum class RegMapMemory {
	BXSI = 0b000,
	BXDI = 0b001,
	BPSI = 0b010,
	BPDI = 0b011,

	SI = 0b100,
	DI = 0b101,
	BP = 0b110,
	BX = 0b111,
};
