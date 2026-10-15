#include "ff.h"
static void THISCALL fn4cbd00(u8* s){
 u8* child=*(u8**)(*(u8**)(s+0x44)+8);
 u8* sys=G(u8*,0x70039c);u8* cb=*(u8**)(*(u8**)(sys+0x1aa3)+0x18);u32 period;
 if(!vcall<u8>(cb,0xdc,*(u32*)(child+0x6c),&period)){vcall<void>(s,0x58);return;}
 sys=G(u8*,0x70039c);
 float x=*(float*)(sys+0x48)**(float*)(s+0x48);x=x+*(float*)(s+0x4c);
 double numerator=(double)x,denominator=(double)period;float result;
 asm volatile("fldl %1; fldl %2; fxch %%st(1); 1: fprem; fnstsw %%ax; test $0x400, %%ax; jnz 1b; fstp %%st(1); fstps %0" : "=m"(result):"m"(numerator),"m"(denominator):"ax","cc","st","st(1)");
 *(float*)(s+0x4c)=result;
 sys=G(u8*,0x70039c);cb=*(u8**)(*(u8**)(sys+0x1aa3)+0x18);
 vcall<void>(cb,0xe0,*(u8**)(*(u8**)(s+0x44)+8),result);
}
PCREG(4cbd00,fn4cbd00);
