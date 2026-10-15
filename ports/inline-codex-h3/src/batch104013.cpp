#include "ff.h"
extern "C" u8 THISCALL ext_4640f0(void*,u32);
extern "C" u32 THISCALL ext_467850(void*,u32,u32);
static u8 THISCALL serialize_actor_state(u8* self,u8* stream) {
  u32 object=G(u32,self+0x169);
  if(!ext_4640f0(self,(u32)stream)) return 0;
  vcall<u32>(stream,0x3c,object);
  vcall<u32>(stream,0x60,(u32)G(u8,self+0x158));
  vcall<u32>(stream,0x44,(u32)G(u8,self+0x159));
  vcall<u32>(stream,0x44,G(u32,self+0x136));
  vcall<u32>(stream,0x4c,G(float,self+0x1ca));
  ext_467850(self+0x16d,(u32)stream,(u32)self);
  u32 child=vcall<u32>(stream,0x68,(u32)(self+0x1ba));
  vcall<u32>((void*)child,0x4c,G(float,self+0x1c6));
  u32 node=G(u32,self+0x1ce);
  node=node?G(u32,(u8*)node+4):0;
  if(node) {
    u32 result=vcall<u32>((void*)node,4);
    vcall<u32>(stream,0x3c,result);
    vcall<u32>((void*)node,0x18,(u32)stream);
  } else vcall<u32>(stream,0x3c,0);
  vcall<u32>(stream,0x44,G(u32,self+0x14f));
  return 1;
}
PCREG(467770,serialize_actor_state);
