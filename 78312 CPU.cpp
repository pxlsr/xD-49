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

        //
        //first set of bits (high order byte(?) in 16 bit mode)
                        // if mode = PSW then bit configuration is:
        bool bit0;      // =0 = H7
        bool bit1;      // =RBS2 = H6
        bool bit2;      // =RBS1 = H5
        bool bit3;      // =RBS0 = H4
        bool bit4;      // =0 = H3
        bool bit5;      // =0 = H2
        bool bit6;       //=IE = H1
        bool bit7;      // =0 = H0

        //second set of bits (low order byte(?) in 16 bit mode)
                        //if mode = PSW then bit configuration is:
        bool bit8;      //=S = L7
        bool bit9;      //=Z = L6
        bool bit10;     //=RSS = L5
        bool bit11;     //=AC = L4
        bool bit12;     //=UF = L3
        bool bit13;     //=PV = L2
        bool bit14;     //=SUB = L1
        bool bit15;     //=CY = L0
    };


                        /* CPU control registers*/
    short PC;		//Program Counter 		(16-bit Register)//
    class PSW{
    public:
        //PSW Low Byte
            class Low{
                public:
                //Program Status Word - Low Byte (or bits)
                bool CY;		//Carry flag (CY)         set to 1 if a carry/borrow occurs from/into bit 7 or bit 15, else 0;

                bool SUB;	    //Subtraction flag (SUB)   set to 1 if ALU is doing a subtraction operation, else 0

                bool PV;		//Parity/Overflow flag (P/V) - Overflow mode: set to 1 if overflow or underflow occurs as twos complement during arithmetic instruction execution else 0

                                                    // - Parity mode: when number of bits is even, set to 1, if odd, 0; (only works on lower 8 bits)
                bool UF;	    //User Flag

                bool AC;		//Auxillary Carry flag (AC) set to 1 if a carry/borrow occurs from/into bit 3, else 0;

                bool RSS;
                                //Register Set Selection Flag - Specifies the general registers which function as X, A, C, and B.
                                //The correspondence between function registers and absolute registers (R0-R15) or (RP0-RP7) depends on bitstate of RSS (or sometimes not)

                                //if 8-bit mode {R0-R15} else if 16-bit mode {RP0 - RP7}

                                //if RSS=0{ R0, R1, R2, R3 = X, A, B, C}
                                //else if RSS=1 {R4, R5, R6, R7 = X, A, B, C}
                                //regardless of RSS{ R8, R9, R10, R11 = VPlow, VPhigh, UPlow, UPhigh}
                                //regardless of RSS {R12, R13, R14, R15 = E, D, L, H}
                                //if RSS=0{RP0, RP1 = AX, BC}else if RSS=1{RP2, RP3 = AX, BC}
                                //regardless of RSS{RP4, RP5, RP6, RP7 = VP, UP, DE, HL}

                bool Z;	        //Zero Flag - when operation result is 0, set Z flag to 1. Else if not 0, set Z flag to = 0;
                                //              if
                bool S;


                bool L0 = CY;		//Carry(PSW.L0)
                bool L1 = SUB;	//Subtraction(PSW.L1)
                bool L2 = PV;		//Parity/Overflow(PSW.L2)
                bool L3 = UF;	//User Flag(PSW.L3)
                bool L4 = AC;		//Auxillary Carry(PSW.L4)
                bool L5 = RSS;	//Register Set Selection Flag(PSW.L5)
                bool L6 = Z;	//Zero Flag(PSW.L6)
                bool L7 = S;		//Sign Flag(PSW.L7)
                };
    };
            class High{
                //PSW High Byte (or bits)
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

        ALU(int VAR1, char OPERATION, int VAR2){       //ALU constructor with parameters
            if (OPERATION == '+'){
                //do addition thingy and store result somewhere
               int RESULT = VAR1 + VAR2;

               ALUresult = RESULT;
               printf("semi coded addition feature");
            }
            else if (OPERATION == '-'){
                //do subtraction thingy and store result somewhere
                    int RESULT = VAR1 - VAR2;
                    ALUresult = RESULT;
                    printf("semi coded subtraction feature");

            }
            else{
                //catch unintended states
                printf("HELP");
            }


        }
        };



int result=0;
int main()  //Main loop, not finished yet, I guess I could hash this into a watchdog timer or something wild
{

     CPU CPUObject;
     result = ALU(1, '-', 1).ALUresult;
     if (result == 0){
        //somehow set PSW.Z (Zero flag) to 1;
        printf("RESULT IS ZERO");
     }




    bool running = true;
    while (running)
    {
        while(TRUE)
        {
            char key = getch();
            switch(key)
            {


                default: std::cout << result; break;



            };
        }
        Sleep(10);
    }
    return 0;
}


//TODO: Vector addresses

void RESET() {  				//Reset chip function - eventually will behave as the hardware RESET pin
                                //SP = undef
                                //
                                //if RESET() {
                                //(CPU.PSW.Low.bits = 0) and (CPU.PSW.High.bits = 0) }

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
