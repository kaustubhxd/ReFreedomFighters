#include "ff.h"
struct Empty29{u32 a,b,c,d;};
extern "C" void THISCALL ext_467410(void*,u32,u32,Empty29);
static u8 THISCALL exchange_lists(u8* me){
 Empty29 empty{0,0,0,0xffffffff};
 ext_467410(*(u8**)(me+0xc)+4,*(u32*)(me+8),0,empty);
 ext_467410(*(u8**)(me+0x10)+4,*(u32*)(me+8),0,empty);
 u32 left=vcall<u32>(*(void**)(me+0xc),0x10);
 vcall<void>(*(void**)(me+0xc),8,*(u32*)(me+8),0);
 u32 right=vcall<u32>(*(void**)(me+0x10),0x10);
 vcall<void>(*(void**)(me+0x10),8,*(u32*)(me+8),0);
 if(left){
  u8* vt=**(u8***)(me+0x10);
  u32 id=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,left);
  typedef void(THISCALL *Fn)(void*,u32,u32);(*(Fn*)(vt+8))(*(void**)(me+0x10),*(u32*)(me+8),id);
 }
 if(right){
  u8* vt=**(u8***)(me+0xc);
  u32 id=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,right);
  typedef void(THISCALL *Fn)(void*,u32,u32);(*(Fn*)(vt+8))(*(void**)(me+0xc),*(u32*)(me+8),id);
 }
 return 0;
}
PCREG(4862b0,exchange_lists);
