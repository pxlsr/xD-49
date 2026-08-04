
//using string = std::string;
char ExternalROM [65536]; // Memory space to emulate System ROM (64kb)

class CPU
{

    public:
//    using Bit = bool;
//    using Byte = unsigned char;
//    using Word = unsigned short;
   

    char A, X, B, C , D, E, H, L; //General Purpose Registers(8-bit)

    char R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;		//Register Absolute names // if RSS == 1 && (A) then R7
                                                                                                                                                                    // else R0 (logic selection idea)
    short AX, BC, DE, HL;	// Register Pairs (16-Bit)

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
 cpuCycle(){
    float Frequency = clockSpeedCPU; //Define it later..

};
