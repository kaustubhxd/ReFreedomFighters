#include "ff.h"
static void THISCALL update_gate_and_emit_vector(u8* self,u32* out) {
  u8* sys=(u8*)g_pSysInterface;
  s32 scaled=(s32)(G(float,self+0x14)*G(float,0x678620));
  if ((s32)G(u32,sys+0x40)>scaled) {
    for(u32 j=0;j<3;j++) G(u32,self+0x18+4*j)=G(u32,self+0x24+4*j);
    u8* obj=G(u8*,self+8);
    if(obj) {
      float random=vcall<float>(sys,0x1c0,0x69e4bc,0x556);
      u32 handle=random>=G(float,0x67a6ac) ? vcall<u32>(obj,0x3b8) : vcall<u32>(obj,0x3b4);
      vcall<void>(obj,0x398,handle,(u32)(self+0x24));
    } else {
      for(u32 j=0;j<3;j++) G(u32,self+0x24+4*j)=0;
    }
    vcall<void>(G(u8*,self+4),0x84,(u32)(self+0x24));
    s32 delay=(s32)(G(float,0x6e8e80)*G(float,0x67862c));
    s32 left=(s32)G(u32,sys+0x40)-delay;
    G(float,self+0x14)=(float)left*G(float,0x6785e4);
  }
  for(u32 j=0;j<3;j++) out[j]=G(u32,self+0x18+4*j);
}
PCREG(512ca0,update_gate_and_emit_vector);
