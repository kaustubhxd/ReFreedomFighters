#include "ff.h"
extern "C" void THISCALL ext_4e73b0(u8*,u32*,u32*,u32*,float,float);
static u32 THISCALL apply_compact_transform(u8* self,u16 key,u32 mode) {
  if(key!=G(u16,self+0x115)) return 0;
  G(u8,self+0x10e)=0;
  for(u32 j=0;j<6;j++) G(u32,self+0xd2+4*j)=G(u32,self+0x11b+4*j);
  u8* sys=(u8*)g_pSysInterface;
  G(u32,self+0xf6)=G(u32,sys+0x40);
  u32 zero[3]={0,0,0};
  u32 copied[3];
  u8* stream=G(u8*,self+0x44);
  if(mode==0) vcall<void>(stream,0x74,(u32)(self+0x90),(u32)(self+0x84));
  vcall<void>(stream,0x84,(u32)zero);
  for(u32 j=0;j<3;j++) copied[j]=G(u32,self+0xd2+4*j);
  vcall<void>(stream,0x88,(u32)copied);
  u32 gv=G(u32,self+0xf6);
  float global_scale=(float)gv*G(float,0x6785e4);
  ext_4e73b0(G(u8*,self+0x48),zero,copied,(u32*)(self+0xde),G(float,self+0xea),global_scale);
  return 0;
}
PCREG(4a64c0,apply_compact_transform);
