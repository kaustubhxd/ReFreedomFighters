#include "ff.h"
extern "C" u8 THISCALL ext_5be810(u8*,u8*);
extern "C" u8* THISCALL ext_5be720(u8*);
extern "C" void THISCALL ext_5bf340(u8*,u8*,s32);
static void THISCALL fn5be5b0(u8* s){
 if(*(u32*)(s+0x91e)){
  u8* p=s+0x4c+58*(*(u32*)(s+0x926));
  if(p[8]<p[7]){
   float f=*(float*)(p+0x35)*G(float,0x678620);
   s32 t=_mm_cvttss_si32(_mm_set_ss(f));
   if(*(s32*)(G(u8*,0x70039c)+0x40)>=t&&ext_5be810(s,p)){
    u8* item=ext_5be720(s);ext_5bf340(s,item,*(s32*)(s+0x926));--*(u32*)(s+0x91e);
   }
  }
  ++*(u32*)(s+0x926);if(*(s32*)(s+0x926)>=*(s32*)(s+0x90c))*(u32*)(s+0x926)=0;
 }
 u8* p=s+0x92e;
 while(p!=s + 0x92e + *(u32*)(s+0x92a)){
  u8* entry=s+0x718+5*(*p);ext_5bf340(s,entry,(s32)*(s8*)(entry+4));++p;
 }
 *(u32*)(s+0x92a)=0;
}
PCREG(5be5b0,fn5be5b0);
