enum ModMap {
	Register = 0b11, // R/M refers to a register
	Memory = 0b00, // R/M refers to memory
	Memory8BitOffset = 0b01, // Memory + 8-bit displacement
	Memory16BitOffset = 0b10 // Memory + 16-bit displacement
};
