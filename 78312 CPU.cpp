#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

const float clockSpeedCPU = 0;

//using string = std::string;


class CPU
{

    public:
//    using Bit = bool;
//    using Byte = unsigned char;
//    using Word = unsigned short;
    class Byte{
    public:

        bool bit0;
        bool bit1;
        bool bit2;
        bool bit3;
        bool bit4;
        bool bit5;
        bool bit6;
        bool bit7;

        //second set of bits
        bool bit8;
        bool bit9;
        bool bit10;
        bool bit11;
        bool bit12;
        bool bit13;
        bool bit14;
        bool bit15;
    };


                        /* CPU control registers*/
    short PC;		//Program Counter 		(16-bit Register)//
    class PSW{
    public:
        //PSW Low Bytes
            class Low{
                public:
                bool CY = 0;		//Carry(PSW.L0)
                bool SUB = 0;	//Subtraction(PSW.L1)   set to 1 if ALU is doing a subtraction operation, else 0
                bool PV = 0;		//Parity/Overflow(PSW.L2)
                bool UF = 0;	//User Flag(PSW.L3)
                bool AC = 0;		//Auxillary Carry(PSW.L4)
                bool RSS = 0;	//Register Set Selection Flag(PSW.L5)
                bool Z = 0;	//Zero Flag(PSW.L6)
                bool S = 0;		//Sign Flag(PSW.L7)
                };
    };
            class High{
                //PSW High Bytes
                public:
                bool IE = 0;    //Interrupt Request Enable Flag (PSW.H1)// EI will set this to 1, DI will set it to 0
                bool RBS0 = 0;
                bool RBS1 = 0;
                bool RBS2 = 0;

                bool H0 = 0;	//0(PSW.H0) Unused
                bool H1 = IE; 		//(PSW.H1)
                bool H2 = 0;		//0(PSW.H2) Unused
                bool H3 = 0;		//0(PSW.H3) Unused
                bool H4 = RBS0;	//Register bank selection flag bit 0(PSW.H4)
                bool H5 = RBS1;	//Register bank selection flag bit 1(PSW.H5)
                bool H6 = RBS2;	//Register bank selection flag bit 2(PSW.H6)
                bool H7 = 0;		//0(PSW.H7) Unused
                };
            };



    short SP;		//Stack Pointer 				(16-bit Register)//
                    //Becomes undef if Reset();

    char CCW;	//CPU Control Word 		(8-bit)//


    char A, X, B, C , D, E, H, L; //General Purpose Registers(8-bit)

    char R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;		//Register Absolute names // if RSS == 1 && (A) then R7
                                                                                                                                                                    // else R0 (logic selection idea)
    short AX, BC, DE, HL;	// Register Pairs (16-Bit)

    class ALU {      //Arithmetic Logic Unit definition - will contain functions for specific operation performed
    public:

        int ALUoperand1;        //The first variable handed to the ALU
        char ALUoperation;     //The operation being performed i.e addition, subtraction
        int ALUoperand2;        //The second variable handed to the ALU
        int ALUresult;          //The result of the ALUs calculation

        ALU(int VAR1, char OPERATION, int VAR2, int RESULT){       //ALU constructor with parameters


            ALUoperand1 = VAR1;
            ALUoperation = OPERATION;
            ALUoperand2 = VAR2;
            ALUresult = RESULT;
            if (ALUoperation == '+'){
                //do addition thingy and store result somewhere
               RESULT, ALUresult = VAR1 + VAR2;
               printf("semi coded addition feature");
            }
            else if (ALUoperation == '-'){
                //do subtraction thingy and store result somewhere
                    RESULT, ALUresult = VAR1 - VAR2;
                    printf("semi coded subtraction feature");

            }
            else{
                //catch unintended states
                printf("HELP");
            }


        }
        };





int main()  //Main loop, not finished yet
{
    char give;
    CPU CPUObject;

        //ALU (ALUoperation,ALUoperator1,ALUoperator2,ALUresult)
    {

    };
    bool running = true;
    while (running)
    {
        while(TRUE)
        {
            char key = getch();
            switch(key)
            {
                default: std::cout << key; break;
                ALU(1, '+', 1, NULL);
            };
        }
        Sleep(10);
    }
    return 0;
}

    // union {
        // struct {A, X} = AX;
    // }

//TODO: Vector addresses

void Reset() {  				//Reset chip function - eventually will behave as the hardware RESET pin
                                //SP = undef
};
//TODO: instruction cycles and literally everything else
 cpuCycle(){
    float Frequency = clockSpeedCPU; //Define it later..

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
