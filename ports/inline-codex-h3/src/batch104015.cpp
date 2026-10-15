#include "ff.h"
static u8 THISCALL update_two_related_objects(u8* self,u32 tick) {
  u8* state=(u8*)G(u32,self+0x310);
  float f=(float)(tick*20u)+G(float,state+0xa3);
  vcall<u32>(state,0x374,f,1u);
  u8* sys=(u8*)g_pSysInterface;
  u8* table=(u8*)G(u32,sys+0x9b);
  u8* first=(u8*)vcall<u32>(table,0x58,G(u32,self+0x184));
  if(first && (u8)vcall<u32>(first,0x1e0,0x80100032u)) {
    float a=G(float,state+0xa3),b=G(float,state+0x9f);
    s32 total=(s32)a+(s32)b;
    s32 count=(s32)vcall<u32>(state,0x388);
    if(total<count) vcall<u32>(first,0x2d8);
    else vcall<u32>(first,0x2dc);
  }
  u32 result=0;
  u8* second=(u8*)vcall<u32>(table,0x58,G(u32,self+0x180));
  if(second && (u8)vcall<u32>(second,0x1e0,0x80100032u)) {
    s32 a=(s32)G(float,state+0xa3);
    if(a>0) result=vcall<u32>(second,0x2d8);
    else result=vcall<u32>(second,0x2dc);
  }
  return (u8)result;
}
PCREG(57ece0,update_two_related_objects);
