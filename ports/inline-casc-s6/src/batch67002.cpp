#include "ff.h"

extern "C" void THISCALL ext_547520(u32 flags, void *ctx);

static u8 THISCALL fn644e70(u8 *cfg, void *object) {
  u32 count=*(u32 *)(cfg+0x21);
  vcall<void>(object,0x44,count);
  u32 i=0;
  u8 *entries=(u8 *)*(u32 *)(cfg+0x25);
  for (; i<count; ++i) {
    u8 *entry=entries+i*0x1df;
    u32 handle=vcall<u32>((void *)(*(u32 *)(*(u32 *)0x70039c+0x9b)),0x4c,*(u32 *)(entry+0x36));
    vcall<void>(object,0x3c,handle);
    vcall<void>(object,0x68,(u32)(entry+8));
    entry[0x3e]=*(u32 *)(entry+0x17f)!=0;
    vcall<void>(object,0x60,entry[0x15]);
    vcall<void>(object,0x60,entry[0x3e]);
    if (entry[0x15] && entry[0x3e]) ext_547520(*(u32 *)(entry+0x17f),object);
  }
  u8 *entry=(u8 *)*(u32 *)(cfg+0x29);
  u32 handle=vcall<u32>((void *)(*(u32 *)(*(u32 *)0x70039c+0x9b)),0x4c,*(u32 *)(entry+0x36));
  vcall<void>(object,0x3c,handle);
  vcall<void>(object,0x68,(u32)(entry+8));
  entry[0x3e]=*(u32 *)(entry+0x17f)!=0;
  vcall<void>(object,0x60,entry[0x15]);
  vcall<void>(object,0x60,entry[0x3e]);
  if (entry[0x15] && entry[0x3e]) ext_547520(*(u32 *)(entry+0x17f),object);
  for (u32 j=0;j<count;++j) vcall<void>(object,0x44,*(u32 *)(cfg+0x2d+j*4));
  return 1;
}
PCREG(644e70,fn644e70);
