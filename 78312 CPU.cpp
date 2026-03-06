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
	struct PSW	//Program Status Word 	(16-bit Register)//
	{
									Byte CY : 1;		//Carry(PSW.L0)
									Byte SUB : 1; 	//Subtraction(PSW.L1)
									Byte PV : 1;		//Parity/Overflow(PSW.L2)
									Byte UF : 1;		//User Flag(PSW.L3)
									Byte AC : 1;		//Auxillary Carry(PSW.L4)
									Byte RSS : 1;	//Register Set Selection Flag(PSW.L5)
									Byte Z : 1;		//Zero Flag(PSW.L6)
									Byte S : 1;		//Sign Flag(PSW.L7)
		Byte PSWLowByte =	(CY, SUB, PV, UF, AC, RSS, Z, S);		//Program Status Word low order byte
									
															//Byte 0 : 1;	//0(PSW.H0) Unused
									Byte IE : 1; 		//Interrupt Request Enable Flag(PSW.H1)
									//Byte 0 : 1;		//0(PSW.H2) Unused
									//Byte 0 : 1;		//0(PSW.H3) Unused
									Byte RBS0 : 1;	//Register bank selection flag bit 0(PSW.H4)
									Byte RBS1 : 1;	//Register bank selection flag bit 1(PSW.H5)
									Byte RBS2 : 1;	//Register bank selection flag bit 2(PSW.H6)
									//Byte 0 : 1;		//0(PSW.H7) Unused
		Byte PSWHighByte = 	(0, IE, 0, 0, RBS0, RBS1, RBS2, 0);	//Program Status Word high order byte

	};
	struct SP;		//Stack Pointer 				(16-bit Register)//
	
	struct CCW;	//CPU Control Word 		(8-bit)//
	
	
			

	

	
	
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
