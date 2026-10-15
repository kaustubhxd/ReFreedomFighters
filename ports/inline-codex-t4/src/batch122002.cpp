#include "ff.h"
extern "C" u8* THISCALL ext_64c7e0(u8*,u32);
extern "C" float FASTCALL ext_4e0830(u8*,u8*);
static float THISCALL fn63eb90(u8* s,u32 id){
 u32 index=id&0xfff;
 u8* entry=(*(u8***)(s+0x68))[index];
 __m128 best=_mm_set_ss(G(float,0x67cd44));
 for(u32 i=0;i<*(u32*)(s+0xec);++i){
  u8* owner=*(u8**)(s+0xf0+4*i);
  if((*(u32**)(owner+0x10071))[index]){
   u8* other=ext_64c7e0(owner,id);
   float dist=ext_4e0830(entry+0x2c,*(u8**)(other+0x20)+0x64);
   best=_mm_min_ss(_mm_set_ss(dist),best);
  }
 }
 double d=(double)_mm_cvtss_f32(best);
 d=(*(crt::libm1*)0x676330)(d);
 return (float)d;
}
PCREG(63eb90,fn63eb90);
