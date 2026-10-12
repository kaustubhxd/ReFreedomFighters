#include "ff.h"
// batch966.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x4324d0 (thiscall, one stack argument, ret 4) and 0x4253c0 (cdecl, four parameters).
// 0x4324d0: sub = self+0xac; r = sub.vt[0x84](sub, a1). If r != 0: return *(u32*)(*(u32*)(r+4)) (the getter 0x4cc1d0 inlined: mov eax,[ecx]).
// Else: local = out of g.vt[0x5c](a1, &local) with g = [0x70039c] (ecx = g); return local.
// 0x4253c0(obj, p1, p2, p4): return obj.vt[0x4c](p1, p2, &p4) (thiscall, callee-cleaned; eax passes through; the out slot is not read here).

typedef u32(THISCALL *tc1)(u8 *, u32);
typedef u32(THISCALL *tc2)(u8 *, u32, u32);
typedef u32(THISCALL *tc3)(u8 *, u32, u32, u32);

static u32 THISCALL zg4324d0(u8 *self, u32 a1) {
  u8 *sub = self + 0xac;
  u32 r = ((tc1)(*(u32 *)(*(u32 *)sub + 0x84)))(sub, a1);
  if (r != 0) return *(u32 *)(*(u32 *)(r + 4));
  u32 local;
  u8 *g = G(u8 *, 0x70039c);
  ((tc2)(*(u32 *)(*(u32 *)g + 0x5c)))(g, a1, (u32)&local);
  return local;
}
PCREG(4324d0, zg4324d0);

static u32 zg4253c0(u8 *obj, u32 p1, u32 p2, u32 p4) {
  return ((tc3)(*(u32 *)(*(u32 *)obj + 0x4c)))(obj, p1, p2, (u32)&p4);
}
PCREG(4253c0, zg4253c0);
