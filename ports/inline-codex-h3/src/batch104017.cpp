#include "ff.h"
extern "C" char ext_634db8[];
static u32 THISCALL append_forty_byte_record(u32* list,u32* source) {
  u32 n=list[0]; u32* dst=list+10*n;
  for(u32 i=0;i<10;i++) dst[i+1]=source[i];
  list[0]=n+1;
  return source[9];
}
PCREG(5de900,append_forty_byte_record);
typedef double(VECTORCALL *ExpFn)(double);
static float record_score(u32 now,u8* r) {
  float dt=(float)(s32)(now-G(u32,r+0xc));
  dt=dt*G(float,0x6785e4);
  dt=dt*G(float,0x6b724c);
  dt=dt/G(float,r+0x14);
  double e=((ExpFn)(void*)ext_634db8)((double)dt);
  return (float)(e*(double)G(float,r+0x18));
}
static u32 THISCALL replace_minimum_age_record(u8* self,u32* source) {
  u32* list=(u32*)(self+0x48);
  if(list[0]<5) return append_forty_byte_record(list,source);
  u32 now=G(u32,(u8*)g_pSysInterface+0x40);
  u8* best=self+0x4c;
  float bestScore=record_score(now,best);
  u32 n=list[0];
  for(u32 i=1;i<n;i++) {
    u8* r=best+i*0x28;
    float score=record_score(now,r);
    if(bestScore>score) { best=r; bestScore=score; }
  }
  for(u32 i=0;i<10;i++) G(u32,best+i*4)=source[i];
  return source[9];
}
PCREG(5de090,replace_minimum_age_record);
