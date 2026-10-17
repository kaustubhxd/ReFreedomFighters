// batch5821.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 121: 0x5c5910 (CTimerEvent::TimeUpdate()), thiscall, no stack args, plain ret.
// n = this+0x4c; this+0x4c = n + 1; if n <= this+0x50: return. Else: this+0x4c = 0; r = (engine 0x70039c)->vt[+0x1bc](0x6b42a0, 0x20);
// this+0x50 = r % this+0x48 (signed remainder); p = (global 0x700390); o = p->vt[+0x20](0x6b42a0, 0x21); r2 = engine->vt[+0x1bc](0x6b42a0, 0x21);
// o->vt[+0x2c](0x6b42d4, r2) (cdecl, three arguments: o is the first); w = (u16)(sub->vt[+0x114](0x6b4280, 0, 0x6b42a0, 0x23, 0)) with sub = (engine)+0x9b;
// (this+0x44)->vt[+0x130](this+0x44, w) (thiscall; the object is both ECX and the first argument).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA2)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *Slot2v)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *Slot5)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);
typedef void (*Fn3)(u32 a, u32 b, u32 c);  // cdecl (the default on i386)

// 0x5c5910, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5c5910(u8 *self) {
  u32 n = *(u32 *)(self + 0x4c);
  *(u32 *)(self + 0x4c) = n + 1;
  if ((s32)n <= (s32)*(u32 *)(self + 0x50)) return;
  *(u32 *)(self + 0x4c) = 0;
  u8 *eng = G(u8 *, 0x70039c);
  s32 r = (s32)((SlotA2)VT(eng)[0x1bc / 4])(eng, 0x6b42a0, 0x20);
  *(u32 *)(self + 0x50) = (u32)(r % (s32)*(u32 *)(self + 0x48));
  u8 *p = G(u8 *, 0x700390);
  u8 *o = (u8 *)(unsigned long)((SlotA2)VT(p)[0x20 / 4])(p, 0x6b42a0, 0x21);
  eng = G(u8 *, 0x70039c);
  u32 r2 = ((SlotA2)VT(eng)[0x1bc / 4])(eng, 0x6b42a0, 0x21);
  ((Fn3)VT(o)[0x2c / 4])((u32)(unsigned long)o, 0x6b42d4, r2);
  eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *obj = *(u8 **)(self + 0x44);
  u32 w = (u16)((Slot5)VT(sub)[0x114 / 4])(sub, 0x6b4280, 0, 0x6b42a0, 0x23, 0);
  ((Slot2v)VT(obj)[0x130 / 4])(obj, (u32)(unsigned long)obj, w);
}
PCREG(5c5910, unnamed5c5910);
