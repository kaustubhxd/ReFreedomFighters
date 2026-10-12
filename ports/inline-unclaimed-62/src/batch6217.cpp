// batch6217.cpp - unclaimed-62 claim 10 (slice 1): 0x516d10 (no name in the name map) [thiscall, ret 4, returns al = 1]. The archive
// argument (edi) has four vtable slots (0x40, 0x50, 0x68, 0x6c, one pointer each) that take the record's fields (this+4 .. this+0x75) as
// output addresses; the parameter's own address goes to slot 0x40 twice. The message table's slot 0x58 (taking the archive value) fills
// this+0 and this+0x29. The exe reads the parameter slot again for each 0x58 call, so the port takes its address and rereads it.
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 THISCALL fn516d10(u8 *self, u32 arch) {
  u8 *edi = (u8 *)arch;
  vcall<void>(edi, 0x40, (u32)&arch);
  wr32u(self, vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x9b), 0x58, arch));
  vcall<void>(edi, 0x40, (u32)(self + 4));
  vcall<void>(edi, 0x40, (u32)(self + 8));
  vcall<void>(edi, 0x50, (u32)(self + 0xc));
  vcall<void>(edi, 0x50, (u32)(self + 0x10));
  vcall<void>(edi, 0x50, (u32)(self + 0x14));
  vcall<void>(edi, 0x50, (u32)(self + 0x18));
  vcall<void>(edi, 0x68, (u32)(self + 0x1c));
  vcall<void>(edi, 0x6c, (u32)(self + 0x1d));
  vcall<void>(edi, 0x40, (u32)&arch);
  wr32u(self + 0x29, vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x9b), 0x58, arch));
  vcall<void>(edi, 0x6c, (u32)(self + 0x2d));
  vcall<void>(edi, 0x6c, (u32)(self + 0x39));
  vcall<void>(edi, 0x6c, (u32)(self + 0x45));
  vcall<void>(edi, 0x6c, (u32)(self + 0x51));
  vcall<void>(edi, 0x50, (u32)(self + 0x5d));
  vcall<void>(edi, 0x50, (u32)(self + 0x61));
  vcall<void>(edi, 0x6c, (u32)(self + 0x65));
  vcall<void>(edi, 0x50, (u32)(self + 0x71));
  vcall<void>(edi, 0x50, (u32)(self + 0x75));
  return 1;
}
PCREG(516d10, fn516d10);
