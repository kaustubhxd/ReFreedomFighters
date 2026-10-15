#include "ff.h"
extern "C" void ext_5d7b10();
static void THISCALL initialize_level(u8* me){
 u8* sys=G(u8*,0x70039c);void* logger=*(void**)(sys+0x1907);
 if(logger){vcall<void>(logger,0xc,0x6ef72c,0x6b5de0,0);sys=G(u8*,0x70039c);}
 vcall<void>(sys,0x1cc,1);ext_5d7b10();
 *(u32*)(me+0x1c8)=*(u32*)(G(u8*,0x70039c)+0x40)+0x800;
 void* actor=*(void**)(G(u8*,0x70039c)+0x190f);u8* savedvt=*(u8**)actor;
 s32 value=vcall<s32>(actor,0xdc);
 s32 next=vcall<s32>(actor,0xd8,(float)value);
 actor=*(void**)(G(u8*,0x70039c)+0x190f);
 typedef void(THISCALL *Fn)(void*,u32,u32,float);
 (*(Fn*)(savedvt+0x134))(actor,0,0,(float)next);
 for(int i=0;i<2;i++){
  actor=*(void**)(G(u8*,0x70039c)+0x190f);vcall<void>(actor,0x138,3,0);
  actor=*(void**)(G(u8*,0x70039c)+0x190f);vcall<void>(actor,0x50);
 }
}
PCREG(5d78e0,initialize_level);
