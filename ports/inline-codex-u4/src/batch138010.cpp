#include "ff.h"
static void THISCALL updateInputTimers(u8* s){
 float dt=*(float*)(G(u8*,0x70039c)+0x34);
 for(u32 i=0;i<262;++i){
  bool active=false;
  if(i<256)active=(G(u8*,0x70039c)[0xa0b+5*i]>>7)!=0;
  else if(s[0x5fd])active=vcall<u8>(*(void**)(G(u8*,0x70039c)+0x1907),0x2c,*(u32*)(s+0x603+8*(i-256)),0u)!=0;
  float* timer=(float*)(s+0x1df+4*i);
  if(active){
   if(*timer==0.f)vcall<void>(s,0x2dc,4u,i,0u,*(u32*)(s+0x64));
   else if(*timer>G(float,0x67c1a4)){
    *timer=*timer-G(float,0x69908c);
    vcall<void>(s,0x2dc,8u,i,0u,*(u32*)(s+0x64));
   }
   *timer=*timer+dt;
  }else if(*timer!=0.f){
   vcall<void>(s,0x2dc,0x10u,i,0u,*(u32*)(s+0x64));
   *(u32*)timer=0;
  }
 }
}
PCREG(4f2300,updateInputTimers);
