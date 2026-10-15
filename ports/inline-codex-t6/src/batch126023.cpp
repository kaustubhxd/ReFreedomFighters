#include "ff.h"
extern "C" void* THISCALL ext_5a4690(void*,u32);
extern "C" void THISCALL ext_5a45c0(void*,u32);
extern "C" void THISCALL ext_5aaa80(void*,float,float,void*);
static void THISCALL timerText(u8* me){
 if(!G(u8,me+0x60)||!G(u32,me+0x58))return;
 u8* timer=(u8*)ext_5a4690(G(void*,me+0x58),G(u32,me+0x1d0b));ext_5a45c0(G(void*,me+0x58),G(u32,me+0x1d0b));u8* state=G(u8*,me+0x58);
 if(!G(u32,state+0x48)&&!G(u8,state+0x58)&&!G(u8,state+0x59))return;
 float original=G(float,state+0x50),value=original;if(original==G(float,0x6785d0))value=G(float,timer+0xe);
 if(G(u8,state+0x58)&&G(u8,timer)&&original>G(float,timer+0xe))value=G(float,timer+0xe);
 void* formatter=vcall<void*>(G(void*,0x70039c),0x190);s32 seconds=_mm_cvttss_si32(_mm_set_ss(value))%60;s32 minutes=_mm_cvttss_si32(_mm_set_ss(value/G(float,0x67885c)))%60;
 u8 text[32];typedef void(*formatfn)(void*,void*,u32,s32,s32);(*(formatfn*)(*(u8**)formatter+0x198))(formatter,text,0x6b8058,minutes,seconds);
 if(G(u32,me+0x1d0f)){float x=G(float,me+0x1d1b)*G(float,0x67c1a4);x=x*G(float,me+0x1d23);float y=G(float,me+0x1d1f)*G(float,0x680a58);y=y*G(float,me+0x1d27);ext_5aaa80(G(void*,me+0x1d0f),x,y,text);}
}
PCREG(5ea960,timerText);
