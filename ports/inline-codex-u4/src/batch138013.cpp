#include "ff.h"
extern "C" void THISCALL ext_4db500(void*,float*);
static void THISCALL arrangeReferences(u8* s){
 vcall<void>(s,0x68,0x10u,0u);
 u8* source=*(u8**)(s+0x44);s32 offset=0;
 if(vcall<u8>(source,0x1e0,0x10003bu))offset=_mm_cvttss_si32(_mm_load_ss((float*)(source+0x9f)));
 u32 iter[2];void* refs=s+0x48;vcall<void>(refs,0x4c,iter);
 u32 id=vcall<u32>(refs,0x5c,iter);
 while(iter[0]){
  u8* actor=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,id);
  if(actor){
   u32 axis=s[0xf8]==0;float vec[3];ext_4db500(*(void**)(actor+8),vec);
   vec[axis]=(float)offset;vcall<void>(actor,0x70,vec);
   if(s[0xf9])offset=(s32)((u32)offset+*(u32*)(s+0xf4));
   else{
    u8* shape=*(u8**)(actor+8);float dim=*(float*)(shape+0x40+4*axis);
    float next=(dim+dim)+(float)*(s32*)(s+0xf4);
    next=next+(float)offset;
    offset=_mm_cvttss_si32(_mm_set_ss(next));
   }
  }
  id=vcall<u32>(refs,0x5c,iter);
 }
}
PCREG(4f68b0,arrangeReferences);
