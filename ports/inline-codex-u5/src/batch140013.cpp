#include "ff.h"
static float past_time(u32 now,float seconds,u32 factor){
 s32 ticks=_mm_cvttss_si32(_mm_set_ss(seconds*G(float,factor)));
 return (float)(s32)(now-(u32)ticks)*G(float,0x6785e4);
}
extern "C" u32 THISCALL dispatch_timer(u8* me,u32 message,u32 unused){
 u16 tag=(u16)message;
 if(tag==0x401){if(!me[0x48])vcall<void>(me,0x64,0x10u);}
 else if(tag==0x400){if(!me[0x48])vcall<void>(me,0x68,0x10u,0u);}
 else if(tag==*(u16*)(me+0x76)){
  *(u32*)(me+0x96)=0;*(u32*)(me+0x9a)=0;*(u32*)(me+0x9e)=0;
  vcall<void>(*(void**)(me+0x44),0x84,me+0x96);
  *(float*)(me+0x92)=past_time(*(u32*)(G(u8*,0x70039c)+0x40),*(float*)(me+0x7a),0x67862c);
  *(u32*)(me+0x8a)=*(u32*)(G(u8*,0x70039c)+0x40);*(u32*)(me+0x8e)=0;
  vcall<void>(*(void**)(me+0x44),0x2c);
  if(me[0x48])vcall<void>(me,0x64,0x10u);
 }else if(tag==G(u16,0x700348)){
  float f=*(float*)(me+0x4e);
  if(f!=G(float,0x6785d0))*(float*)(me+0x92)=past_time(*(u32*)(G(u8*,0x70039c)+0x40),f,0x678620);
 }
 return 0;
}
PCREG(4c3b40,dispatch_timer);
