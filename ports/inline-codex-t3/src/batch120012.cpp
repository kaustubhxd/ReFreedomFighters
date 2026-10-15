#include "ff.h"
extern "C" void THISCALL ext_64e150(void *,void *);
static void THISCALL resetRenderEntries(u8 *self) {
 u32 tmp[3];u32 *it=vcall<u32 *>(self+12,12,tmp);
 u8 **p=(u8 **)it[0];u32 index=it[1];u8 *block=(u8 *)it[2];
 while(p) {
  u8 *entry=*p;*(u16 *)(entry+0x1e)=0;*(u32 *)(entry+0x14)=0;*(u32 *)(entry+0x18)=0;
  ++index;
  if(index==*(u32 *)block) {block=*(u8 **)(block+8);if(!block)break;index=0;p=(u8 **)(block+16);}
  else ++p;
 }
 vcall<void>(*(void **)(self+0x10165),0x14);
 *(u8 **)(self+0x181c5)=self+0x101c1;*(u32 *)(self+0x101c1)=0;
 for(u32 i=0;i!=*(u32 *)(self+0x10089);++i) {
  u8 *entry=*(u8 **)(self+0x1008d+4*i);
  void *ctl=*(void **)(*(u8 **)(entry+12)+12);
  if(ctl && vcall<u8>(ctl,0x258)) {vcall<void>(self,0x2c,entry);ext_64e150(self,entry);vcall<void>(self,0x30);}
 }
}
PCREG(64c800,resetRenderEntries);
