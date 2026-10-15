#include "ff.h"

static void THISCALL fn5d6af0(u8 *self) {
  volatile u8 frame_space[0x20];
  (void)frame_space;
  u8 *frame=(u8 *)__builtin_frame_address(0);
  u8 *active=frame-0x15;
  u32 *value=(u32 *)(frame-0x1c);
  u8 *table=(u8 *)(*(u32 *)(*(u32 *)0x70039c+0x9b));
  void *first=(void *)vcall<u32>(table,0x134);
  *active=0;
  vcall<void>(first,0x90,0x68a9d4u,(u32)active);
  if (*active) return;
  void *sys=(void *)vcall<u32>(table,0x138);
  *value=0;
  vcall<void>(sys,0x88,0x6ac968u,(u32)value);
  u32 h=vcall<u32>(table,0x4c,*(u32 *)(self+0x44));
  u32 code=vcall<u32>(table,0x114,0x6b5a80u,0u,0x6b5b68u,0x2du,h)&0xffff;
  vcall<void>((void *)*(u32 *)(self+0x44),0x12c,*value,code);
}
PCREG(5d6af0,fn5d6af0);
