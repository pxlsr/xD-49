#include <stdio.h>
#include <stdlib.h>

const int clockSpeed;

struct CPU 
{
	using Byte = unsigned char;
	using Word = unsigned short;
						
						/* CPU control registers*/
	Word PC;		//Program Counter 		(16-bit Register)//
	Word PSW;	//Program Status Word 	(16-bit Register)//
	Word SP;		//Stack Pointer 				(16-bit Register)//
	Byte CCW;	//CPU Control Word 		(8-bit Register)//
	
	
	Byte R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15 //General Purpose Registers(8-bit)
	Word RP0, RP1, RP2,	RP3, RP4, RP5, RP6, RP7											// Register Pairs (Am I the only one who thinks of crabs in regards to register pairs?)
};


//TODO: instruction cycles and literally everything else

void Reset() {  				//Reset chip function
};

void Fetch() {				
};

void Decode() {
};

void Execute() {
};