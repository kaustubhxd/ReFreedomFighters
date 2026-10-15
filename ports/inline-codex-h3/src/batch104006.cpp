#include "ff.h"
extern "C" void ext_5d7b10();
static void THISCALL refresh_global_timing(u8* self) {
  u8* sys=(u8*)g_pSysInterface;
  u8* log=G(u8*,sys+0x1907);
  if(log) vcall<void>(log,0xc,0x6ef72c,0x6b5de0,0u);
  (void)vcall<u32>(sys,0x1cc,1u);
  ext_5d7b10();
  G(u32,self+0x1c8)=G(u32,sys+0x40)+0x800;
  u8* actor=G(u8*,sys+0x190f);
  u32 tick=vcall<u32>(actor,0xdc);
  vcall<void>(actor,0xd8,(float)tick);
  vcall<void>(self,0x1fc,(u32)(self+0x1e90),1u,10u);
  vcall<void>(actor,0x138,3u,0u);
  vcall<void>(actor,0x50);
  vcall<void>(actor,0x138,3u,0u);
  vcall<void>(actor,0x50);
}
PCREG(5d78e0,refresh_global_timing);
