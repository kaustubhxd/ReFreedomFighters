#include "ff.h"
extern "C" u32 ext_633910();
static u32 THISCALL update_progress_ratio(u8* self) {
  u8* target=(u8*)G(u32,self+0x6d);
  if(!target) return G(u32,self+0x89);
  u32 n=vcall<u32>(target,0x14);
  G(u32,self+0x91)=n;
  if(!n) {
    G(u32,self+0x8d)=G(u32,self+0x89);
    u32 v=G(u32,self+0x89);
    if(v) G(u32,self+0x69)=v>>3; else G(u32,self+0x69)=0;
    return v;
  }
  u8* sys=(u8*)g_pSysInterface;
  u8* table=(u8*)G(u32,sys+0x9b);
  for(u32 i=0;i<n;i++) {
    u32 zero=0;
    u32 q=vcall<u32>(target,0x30,zero);
    u8* rec=(u8*)vcall<u32>(table,0x58,q);
    if(rec) {
      float x=G(float,rec+0x20)*G(float,0x67da00)/G(float,self+0x79);
      u32 base=G(u32,self+0x89);
      float bf=(float)(s32)base;
      float sum=x+bf;
      u32 cv;
      asm volatile("movss %1, %%xmm0\n\tcall ext_633910" : "=a"(cv) : "m"(sum) : "ecx","edx","memory","xmm0","xmm1","xmm2","xmm3","xmm4","xmm5");
      G(u32,self+0x89)=cv;
    }
  }
  u32 v=G(u32,self+0x89);
  G(u32,self+0x8d)=v;
  if(v) G(u32,self+0x69)=v>>3; else G(u32,self+0x69)=0;
  return v;
}
PCREG(4c1f80,update_progress_ratio);
