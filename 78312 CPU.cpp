#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

const float clockSpeedCPU;

struct CPU 
{
	using Bit = bool;
	using Byte = unsigned char;
	using Word = unsigned short;

						
						/* CPU control registers*/
	struct PC;		//Program Counter 		(16-bit Register)//
	struct PSW;	//Program Status Word 	(16-bit Register)//
	struct SP;		//Stack Pointer 				(16-bit Register)//
	struct CCW;	//CPU Control Word 		(8-bit Register)//
	
	Bit S, Z, AC, P/V, SUB, CY;	//Flags for selecting instruction
	
	Byte A, X, B, C , D, E, H, L; //General Purpose Registers(8-bit)
	
	//Byte R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15		//Register Absolute names // if RSS == 1 && (A) then R7
																																								// else R0 (logic selection idea)
	Word AX, BC, DE, HL;	// Register Pairs (16-Bit)
};




//Main loop, not finished yet
int main()
{
	bool running = true;
	while (running)
	{
		while(keyPress())
		{
			char key = getch();
			switch(key)
			{
				default: std::cout << key; break;
			}
		}
		Sleep(10);
	}
	return 0;
}

	// union {
		// struct {A, X} = AX;
	// }

//TODO: Vector addresses

void Reset() {  				//Reset chip function

};







//TODO: instruction cycles and literally everything else
	

cpuCycle(clockSpeedCPU){
	float Frequency = clockSpeedCPU; //Define it later..
	Fetch();
	
	Decode();
	
	Execute();
	
};
//Fetch portion of instructions
void Fetch() {				
};
//Decode portion of instructions
void Decode() {
};
//Execution stage of instructions
void Execute() {
};
