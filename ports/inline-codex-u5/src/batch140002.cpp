#include "ff.h"
extern "C" void FASTCALL ext_43e960(void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_4419f0(void*,void*);
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" u8 THISCALL vehicle_bounds(u8* me){
 float local[3]={*(float*)(me+0x2b3),*(float*)(me+0x2b7),*(float*)(me+0x2bb)};
 ext_43e960(local,me+0x28f);ext_441a60(local,me+0x26b);
 for(int i=0;i<3;++i)if(__builtin_fabs((double)local[i])>(double)*(float*)(me+0x227+4*i))return 0;
 u32 event[3]={*(u32*)(me+0x2bf),0,vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,me)};
 vcall<void>(me,0x130,*(u32*)(me+0x2af),(u32)*(u16*)(me+0x2d4),event);
 float x=*(float*)(me+0x227);
 struct {float a[3];float b[3];u32 id;} sweep={{x+x,local[1],local[2]},{x*G(float,0x692b60),local[1],local[2]},vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,me)};
 ext_4419f0(sweep.a,me+0x26b);ext_441940(sweep.a,me+0x28f);
 ext_4419f0(sweep.b,me+0x26b);ext_441940(sweep.b,me+0x28f);
 vcall<void>(me,0x130,*(u32*)(me+0x2af),(u32)*(u16*)(me+0x2d2),&sweep);
 return 1;
}
PCREG(514d80,vehicle_bounds);
