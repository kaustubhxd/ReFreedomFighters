#include "ff.h"
extern "C" void THISCALL ext_524f50(void*);
extern "C" void THISCALL ext_526df0(void*);
extern "C" void THISCALL ext_524b00(void*);
extern "C" void FASTCALL ext_4de040(void*,float*,u32);
extern "C" void FASTCALL ext_4ddcb0(float*,float*,float);
extern "C" void FASTCALL ext_4de480(float*,float*);
static void step(u8* me){
 float z=*(float*)(me+0x38),x=*(float*)(me+0x30);
 *(u32*)(me+0x50)=0;
 ext_4de040(me+0xc,(float*)(me+0x4c),0);
 float a[9],b[9];ext_4ddcb0(a,(float*)(me+0xc),z);ext_4ddcb0(b,(float*)(me+0x24),x);
 ext_4de480((float*)(me+0xc),a);ext_4de480((float*)(me+0xc),b);
}
static void THISCALL dynamics(u8* me){
 s32 now=*(s32*)(G(u8*,0x70039c)+0x40);
 s32 old=_mm_cvtt_ss2si(_mm_set_ss(*(float*)(me+0x48)*1024.0f));
 *(float*)(me+0x9c)=bitsf(0x3ba3d70a);
 float dt=(float)(s32)((u32)now-(u32)old)*G(float,0x6785e4)/G(float,0x69c69c);
 s32 n=_mm_cvtt_ss2si(_mm_set_ss(dt)); if(n>=10)n=10;
 if(n>0){
  for(int i=0;i<n;i++){ext_524f50(me);ext_526df0(me);ext_524b00(me);step(me);}
  if(n>=10)*(float*)(me+0x48)=(float)*(s32*)(G(u8*,0x70039c)+0x40)*G(float,0x6785e4);
  else *(float*)(me+0x48)=(float)n**(float*)(me+0x9c)+*(float*)(me+0x48);
 }
 ext_526df0(me);ext_524b00(me);step(me);
}
PCREG(524ff0,dynamics);
