#include "ff.h"
extern "C" u8 THISCALL ext_4640f0(void*,void*);
extern "C" void THISCALL ext_467850(void*,void*,void*);
static u8 THISCALL write_entity(u8* me,void* stream){
 if(!ext_4640f0(me,stream))return 0;
 vcall<void>(stream,0x3c,*(u32*)(me+0x169));
 vcall<void>(stream,0x60,(u32)me[0x158]);
 vcall<void>(stream,0x44,*(u32*)(me+0x159));
 vcall<void>(stream,0x44,*(u32*)(me+0x136));
 vcall<void>(stream,0x4c,*(float*)(me+0x1ca));
 ext_467850(me+0x16d,stream,me);
 void* nestedStream=vcall<void*>(stream,0x68,me+0x1ba);
 vcall<void>(nestedStream,0x4c,*(float*)(me+0x1c6));
 void* nested=*(void**)(*(u8**)(me+0x1ce)+4);
 if(nested){
  u8* vt=*(u8**)stream;
  u32 id=vcall<u32>(nested,4);
  typedef void(THISCALL *Fn)(void*,u32);(*(Fn*)(vt+0x3c))(stream,id);
  vcall<void>(nested,0x18,stream);
 }else vcall<void>(stream,0x3c,0);
 vcall<void>(stream,0x44,*(u32*)(me+0x14f));
 return 1;
}
PCREG(467770,write_entity);
