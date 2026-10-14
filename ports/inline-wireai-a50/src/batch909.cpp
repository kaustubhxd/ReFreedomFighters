// batch909.cpp - residue-9 slice (floor(addr/16) mod 20 == 9, unmentioned in docs, no PCREG before this batch). Four short bodies,
// each read fully.
//  0x5f3290 SaveSerialInfo_t::savestring(...)  [thiscall, one stack arg (a pointer to a dword), ret 4, void]: the object at this+0x15
//           gets slot +0x5c with one argument (the dword at the argument's address). Callee pops (ret 4 in the exe pairing).
//  0x4b1850 ZCutSeqDeleteObj::Command(u16 cmd, void* out) [thiscall, two stack args, ret 8, returns 0]: if cmd == the word at
//           this+0x48, the byte at this+0x4a is written to *out.
//  0x4cb4d0 ZViewNotifyCheckBox::Save(ZSaveGame*) [thiscall, one stack arg, ret 4, returns 1]: clears bit 6 of this+4; calls slot +0x44
//           of the save object (argument) with one argument, this+0x4c (callee pops).
//  0x64a6d0 (cdecl, two pointer args, no pop): returns 1 if the dword at the second pointer is below the dword at the first (unsigned),
//           else -1.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x5f3290 (name map: SaveSerialInfo_t::savestring).
static void THISCALL Save5f3290(u8 *self, u32 *arg) {
  u8 *o = (u8 *)FP(self, 0x15);
  vcall<void>(o, 0x5c, U32(arg, 0));
}
PCREG(5f3290, Save5f3290);

// 0x4b1850 (name map: ZCutSeqDeleteObj::Command(unsigned short, void*)).
static u32 THISCALL Command4b1850(u8 *self, u16 cmd, u8 *out) {
  if (cmd == U16(self, 0x48)) *out = U8(self, 0x4a);
  return 0;
}
PCREG(4b1850, Command4b1850);

// 0x4cb4d0 (name map: ZViewNotifyCheckBox::Save(ZSaveGame*)).
static u8 THISCALL Save4cb4d0(u8 *self, u8 *save) {
  U32(self, 4) &= 0xffffffbfu;
  vcall<void>(save, 0x44, FP(self, 0x4c));
  return 1;
}
PCREG(4cb4d0, Save4cb4d0);

// 0x64a6d0 (cdecl, no name in the map).
static s32 Cmp64a6d0(u32 *a, u32 *b) {
  u32 av = *a;
  return (*b < av) ? 1 : -1;
}
PCREG(64a6d0, Cmp64a6d0);
