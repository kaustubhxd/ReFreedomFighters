// batch1411.cpp - unclaimed-14 batch 11 (slice 13, heavy list): ZRequireMatPosSpeed::Command(unsigned short, void*).
#include "ff.h"

// Helpers (original addresses; the harness replaces each with an accumulating stub, see harness/helper_stubs.py).
extern "C" void THISCALL ext_4db2c0(u8 *self, u32 a1, u32 a2);  // 2 stack args: a1 = buf+0x31, a2 = buf+0x25
extern "C" void THISCALL ext_4e0a10(u8 *self);                  // no stack args
extern "C" void FASTCALL ext_4e0980(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_4de7e0(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_4419f0(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_441940(u8 *ecx, u8 *edx);

// 0x4a60d0, ZRequireMatPosSpeed::Command(unsigned short, void*) (high): thiscall, two stack arguments (ret 8), returns 0.
// Only the command 0x4004 does anything: buf[0] = 1; then the helper calls in the PC order (the register values are
// shown in the comments; note that esi = buf+0x31 after the first helper, and edi = buf+0x25). Afterwards it copies
// fields of this into buf at offsets 1, 5, 9, 0xd .. 0x21 (the PC writes unaligned dwords).
static u32 THISCALL zRequireMatPosSpeedCommand(u8 *self, u32 cmd, u8 *buf) {
  if ((u16)cmd == 0x4004) {
    buf[0] = 1;
    u8 *obj = *(u8 **)(*(u8 **)(self + 0x44) + 8);
    ext_4db2c0(obj, (u32)(buf + 0x31), (u32)(buf + 0x25));   // ecx = obj; pushes buf+0x31 last, so it is arg 1
    u8 loc1c[0x20] = {};
    ext_4e0a10(loc1c);                                       // ecx = &loc1c
    ext_4e0980(loc1c, self + 0x48);                          // ecx = &loc1c, edx = this+0x48
    ext_4de7e0(buf + 0x31, loc1c);                           // ecx = esi (buf+0x31), edx = &loc1c
    u8 loc10[0x20] = {};
    ext_4e0a10(loc10);
    ext_4e0980(loc10, self + 0x54);
    ext_4419f0(loc10, buf + 0x31);                           // ecx = &loc10, edx = esi (buf+0x31)
    ext_441940(buf + 0x25, loc10);                           // ecx = edi (buf+0x25), edx = &loc10
    *(u32 *)(buf + 1) = *(u32 *)(self + 0x78);
    *(u32 *)(buf + 5) = *(u32 *)(self + 0x7c);
    *(u32 *)(buf + 9) = *(u32 *)(self + 0x80);
    *(u32 *)(buf + 0xd) = *(u32 *)(self + 0x60);
    *(u32 *)(buf + 0x11) = *(u32 *)(self + 0x64);
    *(u32 *)(buf + 0x15) = *(u32 *)(self + 0x68);
    *(u32 *)(buf + 0x19) = *(u32 *)(self + 0x6c);
    *(u32 *)(buf + 0x1d) = *(u32 *)(self + 0x70);
    *(u32 *)(buf + 0x21) = *(u32 *)(self + 0x74);
  }
  return 0;
}
PCREG(4a60d0, zRequireMatPosSpeedCommand);
