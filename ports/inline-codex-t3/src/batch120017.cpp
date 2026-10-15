#include "ff.h"
extern "C" void THISCALL ext_4a7fb0(void *,void *);
static void THISCALL initializeMotionFlags(u8 *self,void *unused,void *db) {
 ext_4a7fb0(self,db);
 *(u32 *)(self+0x76)=*(u32 *)(G(u8 *,0x70039c)+0x40);
 *(u32 *)(self+0x72)=*(u32 *)(G(u8 *,0x70039c)+0x40);
 *(u32 *)(self+0x7b)=0;
 if(*(float *)(self+0x5a)!=0.0f || *(float *)(self+0x5e)!=0.0f || *(float *)(self+0x62)!=0.0f) {
  for(u32 i=0;i<3;++i) *(float *)(self+0x5a+4*i)*=G(float,0x67da04);
  self[0x7d]=1;
 }
 if(*(float *)(self+0x66)!=0.0f || *(float *)(self+0x6a)!=0.0f || *(float *)(self+0x6e)!=0.0f) self[0x7e]=1;
 if(!self[0x7a]) self[0x7c]=1;
 vcall<void>(self,0x68,0x10u,0u);
 if(!*(u16 *)(self+0x50)) self[0x7b]=1;
 vcall<void>(*(void **)(self+0x44),0x3c,1u);
}
PCREG(4a7e20,initializeMotionFlags);
