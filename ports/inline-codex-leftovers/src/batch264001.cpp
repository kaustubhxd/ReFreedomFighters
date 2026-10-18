// Codex: 494950 normal entry and shared continuation 4949d3, from original disassembly.
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe50_copy(u32,u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cc1d0_data(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cbec0_drop(u32) __asm__("ext_4cbec0");
extern "C" void FASTCALL ext_633654(u32);
static u32 rd494(u32 a) {u32 v;__builtin_memcpy(&v,(void*)a,4);return v;}
extern "C" u32 THISCALL hand_494950(u32 self) {
  volatile SehRecord reg;
  reg.next=seh_head(); reg.handler=0x667f7b; reg.state=-1; seh_set_head(&reg);
  u8 local[128] __attribute__((aligned(4)));
  u32 temp=(u32)local;
  reg.state=0; // @state0
  u32 engine=G(u32,0x70039c), manager=rd494(engine+0x1aa3);
  ((u32(THISCALL*)(u32,u32))rd494(rd494(manager)+0x58))(manager,rd494(engine+0x9db)); // @manager
  reg.state=-1; // @state1
  ext_4cbe50_copy(temp,self+0xbcd);
  reg.state=2; // @state2
  u32 data=ext_4cc1d0_data(temp);
  u32 semi=((u32(*)(u32,u32))G(u32,0x676254))(data,0x3b); // @separator
  if(semi) {
    u32 src=semi+1, dst=ext_4cc1d0_data(self+0xbcd);
    u8 b; do {b=*(u8*)src++;*(u8*)dst++=b;} while(b); // @copy
    *(u8*)semi=0; // @truncate
  }
  engine=G(u32,0x70039c); manager=rd494(engine+0x1a9f);
  if(manager) ((u32(THISCALL*)(u32))rd494(rd494(manager)+0x3c))(manager); // @optional
  u32 vt=rd494(self);
  *(u8*)(self+0xbb2)=0; // @clear
  data=ext_4cc1d0_data(temp);
  ((u32(THISCALL*)(u32,u32))rd494(vt+0xa0))(self,data); // @load
  ((u32(THISCALL*)(u32,u32))rd494(rd494(self)+0x18c))(self,1); // @notify
  if(*(u8*)(self+0xbb2)) ((u32(THISCALL*)(u32,u32))rd494(rd494(self)+0x188))(self,0); // @conditional
  ((u32(THISCALL*)(u32))rd494(rd494(self)+0x120))(self); // @finish
  u32 result=ext_4cbec0_drop(temp);
  seh_set_head(reg.next); // @unlink
  ext_633654(G(u32,0x6f5630));
  return result; // @return
}
PCREG(494950,hand_494950);
