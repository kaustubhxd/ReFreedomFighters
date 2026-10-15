#include "ff.h"
static void THISCALL serializeTime(u8* me){
 if(me[0x1e90]){
  u64 counter;typedef int(STDCALL*Counter)(u64*);G(Counter,0x6760e0)(&counter);*(u64*)(me+0x23c6)=counter;
 }else *(u64*)(me+0x23c6)=vcall<u64>(G(void*,0x70039c),0x1c8,0x677fb4u,0x9a9u);
 typedef s32(*Clock)();s32 t=G(Clock,0x676434)();
 float rounded=(float)((double)t*G(double,0x6785e8));*(double*)(me+0xc)=(double)rounded;
 vcall<void>(me,0x1fc,me+0xc,8u,6u,0x677fb4u,0x9b1u);
 vcall<void>(me,0x1fc,me+0x23c6,8u,11u,0x677fb4u,0x9b2u);
}
PCREG(4234f0,serializeTime);
