#include "ff.h"

// 0x624960: cdecl(arg0, arg1) - boolean test function
// Returns 1 if [arg1]==0xf4 AND ([arg1+1] & 0x30)!=0, else 0
int __cdecl sub_624960(int arg0, unsigned char* arg1) {
    return (arg1[0] == 0xf4 && (arg1[1] & 0x30) != 0) ? 1 : 0;
}
PCREG(624960, sub_624960);
