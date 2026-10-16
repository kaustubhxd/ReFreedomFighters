// batch5786.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 86: 0x5c4f80 (GUESS name unnamed_5c4f80), thiscall, one stack argument obj
// (ret 4), returns al = 1. Order: clear bit 0x40 of this+4; for i < this+0x50 (re-read each step), with entry = this+0x4c base + 0x19*i:
// obj->vt[+0x54](dword entry+0); obj->vt[+0x64](dword entry+4); obj->vt[+0x44](dword entry+8); obj->vt[+0x68](entry+0xc) (a pointer);
// obj->vt[+0x60](byte entry+0x18). The slots run as fake vtable stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotV)(u8 *self, u32 v);

// 0x5c4f80, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5c4f80(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  for (s32 i = 0, off = 0; i < (s32)*(u32 *)(self + 0x50); i++, off += 0x19) {
    u8 *ent = *(u8 **)(self + 0x4c) + off;
    ((SlotV)VT(obj)[0x54 / 4])(obj, *(u32 *)ent);
    ((SlotV)VT(obj)[0x64 / 4])(obj, *(u32 *)(ent + 4));
    ((SlotV)VT(obj)[0x44 / 4])(obj, *(u32 *)(ent + 8));
    ((SlotV)VT(obj)[0x68 / 4])(obj, (u32)(unsigned long)(ent + 0xc));
    ((SlotV)VT(obj)[0x60 / 4])(obj, (u32)*(u8 *)(ent + 0x18));
  }
  return 1;
}
PCREG(5c4f80, unnamed5c4f80);
