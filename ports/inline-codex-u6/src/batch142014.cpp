#include "ff.h"
extern "C" void FASTCALL ext_4de040(void*,float*,u32);
extern "C" void FASTCALL ext_4ddcb0(float*,float*,float);
extern "C" void FASTCALL ext_4de480(float*,float*);
extern "C" void THISCALL ext_527f80(void*);
extern "C" void THISCALL ext_529760(void*);
extern "C" void THISCALL ext_527710(void*);
extern "C" void THISCALL ext_529660(void*);
extern "C" void THISCALL ext_528090(void*);
static void THISCALL init(u8* me,u32* pos,u32* dir){
 for(int i=0;i<3;i++)((u32*)me)[i]=pos[i];
 for(int i=0;i<3;i++)*(u32*)(me+0x4c+4*i)=dir[i];
 *(u32*)(me+0x50)=0;for(int i=0;i<3;i++)*(u32*)(me+0x58+4*i)=*(u32*)(me+0x4c+4*i);
 ext_4de040(me+0xc,(float*)(me+0x4c),0);
 vcall<void>(*(void**)(me+0x89),0x7c,me+0xc,me);
 ext_527f80(me);ext_529760(me);ext_527710(me);
 float z=*(float*)(me+0x38),x=*(float*)(me+0x30);*(u32*)(me+0x50)=0;
 ext_4de040(me+0xc,(float*)(me+0x4c),0);
 float a[9],b[9];ext_4ddcb0(a,(float*)(me+0xc),z);ext_4ddcb0(b,(float*)(me+0x24),x);
 ext_4de480((float*)(me+0xc),a);ext_4de480((float*)(me+0xc),b);
 vcall<void>(*(void**)(me+0x89),0x7c,me+0xc,me);
 ext_529660(me);ext_528090(me);
 vcall<void>(*(void**)(me+0x89),0x7c,me+0xc,me);
 *(float*)(me+0x48)=(float)*(s32*)(G(u8*,0x70039c)+0x40)*G(float,0x6785e4);
 *(u32*)(me+0x85)=*(u32*)(G(u8*,0x70039c)+0x40)+0x1c00;
}
PCREG(528100,init);
