// Take the first 32 bits
// Shift
// if 32 bits are less than DEVISOR goto 2
// XOR 32 bits by devisor, goto 2

#include<ctypes>
/startheader
#define DEVISOR 0x04C11DB7
//endheader
uint32_t PNG::CRC32(
