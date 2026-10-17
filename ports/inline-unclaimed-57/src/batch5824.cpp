// batch5824.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 124: 0x5c3c60 (COpenWindow::TimeUpdate, GUESS name unnamed5c3c60), thiscall, no args, plain ret.
// X = sub->vt[+0x138](); X->vt[+0x88](0x681320, &v14); S = sub->vt[+0x58](v14); GetCen(S+8 -> v10) (ZBaseGeom::GetCen, verified in batch411, inlined here);
// S->vt[+0x84](&v10); M->vt[+0x8c](&v10); al = M->vt[+0x180](&v10, -10.0f) (the float constant 0xc1200000 pushed in the slot).
// If !al: if this+0x48 != 0: this+0x48 = 0; return. If this+0x48 != 0: return. this+0x48 = 1; S2 = sub->vt[+0x58](this+0x49 dword);
// if S2: T = S2->vt[+0x2c4](); T->vt[+0x2fc](S2). else: O = logger->vt[+0x20](0x6b3eb8, 0x2f); O->vt[+0x2c](O, 0x6b3eec) (cdecl).
// The cookie check (0x633654) is omitted (no effect on a valid cookie).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot1)(u8 *self, u32 a);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *Slot2r)(u8 *self, u32 a, u32 b);
typedef void (*FnC2)(u32 a, u32 b);  // cdecl

// 0x5c3c60, thiscall, no args (GUESS name)
static void THISCALL unnamed5c3c60(u8 *self) {
  u32 v14 = 0;
  u32 v10[3];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *X = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
  v14 = 0;
  ((Slot2)VT(X)[0x88 / 4])(X, 0x681320, (u32)(unsigned long)&v14);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *S = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, v14);
  u8 *g = *(u8 **)(S + 8);  // ZBaseGeom::GetCen(g, &v10): three dwords from g+0x30
  v10[0] = *(u32 *)(g + 0x30);
  v10[1] = *(u32 *)(g + 0x34);
  v10[2] = *(u32 *)(g + 0x38);
  ((SlotA)VT(S)[0x84 / 4])(S, (u32)(unsigned long)v10);
  u8 *M = *(u8 **)(self + 0x44);
  ((SlotA)VT(M)[0x8c / 4])(M, (u32)(unsigned long)v10);
  M = *(u8 **)(self + 0x44);
  u8 al = (u8)((Slot2r)VT(M)[0x180 / 4])(M, (u32)(unsigned long)v10, 0xc1200000u);
  if (!al) {
    if (*(u8 *)(self + 0x48) != 0) *(u8 *)(self + 0x48) = 0;
    return;
  }
  if (*(u8 *)(self + 0x48) != 0) return;
  u32 key = *(u32 *)(self + 0x49);
  *(u8 *)(self + 0x48) = 1;
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *S2 = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, key);
  if (S2 == 0) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *O = (u8 *)(unsigned long)((Slot2r)VT(lg)[0x20 / 4])(lg, 0x6b3eb8, 0x2f);
    ((FnC2)VT(O)[0x2c / 4])((u32)(unsigned long)O, 0x6b3eec);
    return;
  }
  u8 *T = (u8 *)(unsigned long)((SlotN)VT(S2)[0x2c4 / 4])(S2);
  ((SlotA)VT(T)[0x2fc / 4])(T, (u32)(unsigned long)S2);
}
PCREG(5c3c60, unnamed5c3c60);
