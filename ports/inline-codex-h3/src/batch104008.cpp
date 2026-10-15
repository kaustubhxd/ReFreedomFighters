#include "ff.h"
static void THISCALL update_bounded_area(u8* self,u8 enabled) {
  if(!enabled) {
    u8* old=G(u8*,self+0x54);
    if(old) { vcall<void>(old,0); return; }
  }
  u8* mgr=G(u8*,(u8*)g_pSysInterface+0x1aa3);
  u8* query=G(u8*,mgr+0x18);
  u8 ok=vcall<u8>(query,0x114,G(u32,self+0x6c),(u32)(self+0x30),(u32)(self+0x40));
  G(u32,self+0x3c)|=0x100000;
  if(ok) {
    float x=G(float,self+0x40),y=G(float,self+0x44),z=G(float,self+0x48);
    float sum=x*x+y*y+z*z;
    G(float,self+0x4c)=(float)crt::sqrt((double)sum)+G(float,0x678858);
    return;
  }
  G(float,self+0x4c)=0.0f;
  for(u32 j=0;j<3;j++) G(u32,self+0x30+4*j)=0;
  for(u32 j=0;j<3;j++) G(u32,self+0x40+4*j)=0;
  float floor=G(float,0x679540);
  const u32 small=0x39000000;
  if(floor>G(float,self+0x40)) G(u32,self+0x40)=small;
  if(floor>G(float,self+0x44)) G(u32,self+0x44)=small;
  if(floor>G(float,self+0x48)) G(u32,self+0x48)=small;
}
PCREG(4da1d0,update_bounded_area);
