#include <iostream>
#include <cstdint>

//Clock speeds
float clockSpeedCPU = 12.000;    //12.000MHz (CPU clock speed)
float clockSpeedDSP = 32.768;    //32.768MHz (Synth core clock speed)
    //float clockSpeedMultiplier = 1.000;   //might come in handy later for clock speed fuckery
//Memories
char DRAM [4096];                //
char SRAM1 [8000];               //HM6264ASP SRAM
char SRAM2 [32000];              //HM62256LP SRAM
char SRAM3 [2048];               //LC3517AS SRAM
char OSROM [65536];              //Memory space to emulate System ROM (64kb)
char PCMROM [262144];             //Memory space to emulate PCM sample ROM (2Mbit)

//Operation code parsing from OS binary
//I will need to update this with an opcode table using hex to map the operations
struct OPCodes
{
    //Mnemonics used for this CPU:      TODO: Table this shit so it can be hex-represented
    //ADD, ADDC, ADDW, ADJ4, AND, AND1,
    //BC, BE, BF, BFSET, BGE, BGT, BH, BL, BLE, BLT, BN, BNC, BNE, BNH,
    //BNL, BNV, BNZ, BP, BPE, BPO, BR, BRK, BRKCS, BT, BTCLR, BV, BZ,
    //CALL, CALLF, CALLT, CLR1, CMP, CMPBKC, CMPBKE, CMPBKNC, CMPBKNE,
    //CMPMC, CMPME, CMPMNC, CMPMNE, CMPW,
    //DBNZ, DEC, DECW, DI, DIVUW, DIVUX, EI,
    //INC, INCW, MOV, MOVBK, MOVM, MOVW, MOV1,
    //MULU, MULUW, NOP, NOT1, OR, OR1, POP,
    //POPU, PUSH, PUSHU, RET, RETI, RETCS, ROL, ROLC,
    //ROL4, ROR, RORC, ROR4, SEL, SET1, SHL, SHLW, SHR, SHRW,
    //SUB, SUBC, SUBW, SWRS, XCH, XCHBK, XCHM, XCHW, XOR, XOR1
        //Operands used for this CPU:
        //
        //
        //
        //
        //

    public: 
    short mnemonic;
    short operand1;
    short operand2;
    short operand3;
    short operand4;
    short operand5;
    short operand6;
};


class CPU
{

    public:
//    using Bit = bool;
//    using Byte = unsigned char;
//    using Word = unsigned short;
   

    char A, X, B, C , D, E, H, L; //General Purpose Registers(8-bit)

    char R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;		//Register Absolute names // if RSS == 1 && (A) then R7
                                                                                                                                                                    // else R0 (logic selection idea)
	// Register Pairs (16-Bit) TODO!!

    class ALU {      //Arithmetic Logic Unit definition - will contain functions for specific operation performed
    public:

            //foobar


        };
    };       






    int main()  //Main loop, not finished yet, I guess I could hash this into a watchdog timer or something wild
{

    
}


//TODO: Vector addresses

void RESET() {  				//Reset chip function - eventually will behave as the hardware RESET pin
                                //SP = undef
                                //
                                //if RESET() {
                                //(CPU.PSW.Low.bits = 0) and (CPU.PSW.High.bits = 0) }

};
//TODO: instruction cycles and literally everything else
 void cpuCycle(){
    float Frequency = clockSpeedCPU; //Define it later..

};
