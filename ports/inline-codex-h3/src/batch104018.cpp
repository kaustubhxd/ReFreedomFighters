#include "ff.h"
extern "C" u32 THISCALL ext_487c70(void*,u32,u32,u32,u32);
static u8 THISCALL clear_inactive_motion(u8* self,u32 a,u32 b,u32* out,u32 d) {
  u8* found=(u8*)vcall<u32>((void*)G(u32,self+0xc),0x10);
  if(!found) return 0;
  if(G(u32,self+0x28)==0) return 0;
  ext_487c70(self,a,b,(u32)out,d);
  u8* state=(u8*)G(u32,self+4);
  out[0]=out[1]=out[2]=0;
  u8 flags=G(u8,state+0x417);
  if((flags&0x18)==0) G(u16,self+0x3bb)=0;
  if((flags&3)==0 && G(u8,self+0x3ad)!=0 &&
     G(u8,self+0x3bb)==0 && (flags&8)==0 &&
     G(u8,self+0x3bc)==0 && (flags&0x10)==0 &&
     G(u8,self+0x3be)==0) return 1;
  return 0;
}
PCREG(487e50,clear_inactive_motion);
