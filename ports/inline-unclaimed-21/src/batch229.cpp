// batch229.cpp - small leaves, slice 0/1. 0x511bc0 (name GUESS): fastcall(this in ecx, arr in edx). cnt = vt[0x48](this);
// for i < cnt (signed): x = vt[0x40](this); r = child->vt[0x58](child, x) where child = [[0x70039c]+0x9b]; arr[n+1] = r with
// n = arr[0]; arr[0] = n + 1. Returns this.
#include "ff.h"

typedef void(THISCALL *SlotOutPtr)(u8 *, u32 *);     // vtable slot writing one dword through an out pointer
typedef u32(THISCALL *SlotArgRet)(u8 *, u32);        // vtable slot, one stack word, eax result

static u32 vslot12(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static u8 *FASTCALL fillFromCalls_511bc0(u8 *self, u32 *arr) {
  s32 cnt = 0;
  ((SlotOutPtr)vslot12(self, 0x48))(self, (u32 *)&cnt);
  for (s32 i = 0; i < cnt; ++i) {
    u32 x = 0;
    ((SlotOutPtr)vslot12(self, 0x40))(self, &x);
    u8 *rm = G(u8 *, 0x70039c);
    u8 *child = *(u8 **)(rm + 0x9b);
    u32 r = ((SlotArgRet)vslot12(child, 0x58))(child, x);
    u32 n = arr[0];
    arr[n + 1] = r;
    arr[0] = n + 1;
  }
  return self;
}
PCREG(511bc0, fillFromCalls_511bc0);
