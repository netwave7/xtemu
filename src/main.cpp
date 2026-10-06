#include "system.hpp"

int main(int argc, char **argv)
{
	System system;

	system.opcode_map[0x01]();
	system.opcode_map[0x00]();

	return 0;
}
