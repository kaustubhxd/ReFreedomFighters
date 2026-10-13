// batch527.cpp - weapons thread, batch 527: ZLNKWHANDS::CreateLnkAction (0x4733d0) and the ninth ZLnkAction
// constructor 0x485ca0 it uses. Action id (1..15) picks the class; each case allocates the object with the exe's
// __builtin_new (0x41e290, cdecl, size argument) and constructs it with the exe's constructor (ext_ bindings, so
// the constructor code is the original). Hand offsets: right hand +0x34f, left hand +0x2e7. Fields used: +0x1ea..
// +0x222 (action parameters, first group), +0x226..+0x262 (second group, ids 11-13), +0x2b7..+0x2cf (ids 14-15).
// The SEH frame of the exe is not reproduced (it has no effect on the result).
// Argument order per case was read from the pushes in the disassembly (see docs/20-weapons.md, CreateLnkAction).
// GUESS: which field group belongs to which action; the field names are not known.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void *ext_41e290(u32 size);                              // __builtin_new (cdecl)
extern "C" u32 THISCALL ext_485d30(void *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);   // 5 args
extern "C" u32 THISCALL ext_485df0(void *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);   // 5 args
extern "C" u32 THISCALL ext_485d00(void *self, u32 a0, u32 a1, u32 a2, u32 a3);           // 4 args
extern "C" u32 THISCALL ext_485d70(void *self, u32 a0, u32 a1, u32 a2, u32 a3);           // 4 args
extern "C" u32 THISCALL ext_485e90(void *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);   // 5 args
extern "C" u32 THISCALL ext_485db0(void *self, u32 a0, u32 a1, u32 a2, u32 a3);           // 4 args
extern "C" u32 THISCALL ext_485e30(void *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);   // 10 args
extern "C" u32 THISCALL ext_485ca0(void *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8);          // 9 args

// 0x485ca0: nine arguments; +4..+0x14 = a0..a4, +0x18 = a6, +0x1c = a5, +0x20 = a7, +0x24 = a8, +0x28 = 0; vtable 0x68cd8c.
static u32 THISCALL lnkH(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)(self + 0x18) = a6;
  *(u32 *)(self + 0x1c) = a5;
  *(u32 *)(self + 0x20) = a7;
  *(u32 *)(self + 0x24) = a8;
  *(u32 *)self = 0x68cd8c;
  *(u32 *)(self + 0x28) = 0;
  return (u32)self;
}
PCREG(485ca0, lnkH);

// 0x4733d0 CreateLnkAction(id): returns the new action (eax from its constructor) or 0 (id out of 1..15, or no memory).
static u32 THISCALL createLnkAction(u8 *s, u32 id) {
  u32 h = (u32)(s + 0x2e7);   // left hand slot
  u32 r = (u32)(s + 0x34f);   // right hand slot
  void *p;
  switch (id) {
  case 1:  p = ext_41e290(0x18); return p ? ext_485db0(p, 1, (u32)s, h, *(u32 *)(s + 0x21a)) : 0;
  case 2:  p = ext_41e290(0x18); return p ? ext_485db0(p, 2, (u32)s, r, *(u32 *)(s + 0x21e)) : 0;
  case 3:  p = ext_41e290(0x18); return p ? ext_485d70(p, 3, (u32)s, h, *(u32 *)(s + 0x212)) : 0;
  case 4:  p = ext_41e290(0x18); return p ? ext_485d70(p, 4, (u32)s, r, *(u32 *)(s + 0x216)) : 0;
  case 5:  p = ext_41e290(0x18); return p ? ext_485df0(p, 5, (u32)s, h, *(u32 *)(s + 0x1fa), *(u32 *)(s + 0x202)) : 0;
  case 6:  p = ext_41e290(0x18); return p ? ext_485df0(p, 6, (u32)s, r, *(u32 *)(s + 0x1fe), *(u32 *)(s + 0x206)) : 0;
  case 7:  p = ext_41e290(0x1c); return p ? ext_485d30(p, 7, (u32)s, h, *(u32 *)(s + 0x1ea), *(u32 *)(s + 0x1fa)) : 0;
  case 8:  p = ext_41e290(0x1c); return p ? ext_485d30(p, 8, (u32)s, r, *(u32 *)(s + 0x1ee), *(u32 *)(s + 0x1f6)) : 0;
  case 9:  p = ext_41e290(0x14); return p ? ext_485d00(p, 9, (u32)s, h, *(u32 *)(s + 0x20a)) : 0;
  case 10: p = ext_41e290(0x14); return p ? ext_485d00(p, 10, (u32)s, r, *(u32 *)(s + 0x20e)) : 0;
  case 11: p = ext_41e290(0x18); return p ? ext_485e90(p, 11, (u32)s, r, h, *(u32 *)(s + 0x222)) : 0;
  case 12: p = ext_41e290(0x40); return p ? ext_485e30(p, 12, (u32)s, h, *(u32 *)(s + 0x226), *(u32 *)(s + 0x22e), *(u32 *)(s + 0x236), *(u32 *)(s + 0x232), *(u32 *)(s + 0x23a), *(u32 *)(s + 0x25e), *(u32 *)(s + 0x262)) : 0;
  case 13: p = ext_41e290(0x40); return p ? ext_485e30(p, 13, (u32)s, r, *(u32 *)(s + 0x22a), *(u32 *)(s + 0x22e), *(u32 *)(s + 0x236), *(u32 *)(s + 0x232), *(u32 *)(s + 0x23a), *(u32 *)(s + 0x25e), *(u32 *)(s + 0x262)) : 0;
  case 14: p = ext_41e290(0x30); return p ? ext_485ca0(p, 14, (u32)s, r, *(u32 *)(s + 0x2bb), *(u32 *)(s + 0x2bf), *(u32 *)(s + 0x2c3), *(u32 *)(s + 0x2c7), *(u32 *)(s + 0x2cb), *(u32 *)(s + 0x2cf)) : 0;
  case 15: p = ext_41e290(0x30); return p ? ext_485ca0(p, 15, (u32)s, h, *(u32 *)(s + 0x2b7), *(u32 *)(s + 0x2bf), *(u32 *)(s + 0x2c3), *(u32 *)(s + 0x2c7), *(u32 *)(s + 0x2cb), *(u32 *)(s + 0x2cf)) : 0;
  default: return 0;
  }
}
PCREG(4733d0, createLnkAction);
