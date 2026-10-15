#include "ff.h"
extern "C" void ext_633654(u32);
static void THISCALL bind_configs(u8* me){
 void* table=*(void**)(G(u8*,0x70039c)+0x9b);
 void* conf=vcall<void*>(table,0x134);
 u8 enabled=0;vcall<void>(conf,0x90,0x68a9d4,&enabled);
 const u32 names[]={0x6ac968,0x6ac8fc,0x6ac920,0x6ac944};
 for(int i=0;i<(enabled?4:1);i++){
  table=*(void**)(G(u8*,0x70039c)+0x9b);
  void* values=vcall<void*>(table,0x138);
  u32 value=0;vcall<void>(values,0x88,names[i],&value);
  table=*(void**)(G(u8*,0x70039c)+0x9b);
  void* child=*(void**)(me+0x44);u8* savedvt=*(u8**)child;
  u32 handle=vcall<u32>(table,0x4c,child);
  u32 id=vcall<u32>(table,0x114,0x6b5a80,0,0x6b5b68,enabled?0x27:0x2d,handle);
  child=*(void**)(me+0x44);
  typedef void(THISCALL *Fn)(void*,u32,u32);
  (*(Fn*)(savedvt+0x12c))(child,value,(u32)(u16)id);
 }
 ext_633654(0);
}
PCREG(5d6af0,bind_configs);
