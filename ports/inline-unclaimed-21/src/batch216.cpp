// batch216.cpp - unclaimed area 21 (docs/20-unclaimed-21.md). A lookup on the render-manager child (vtable 0x58 with the
// first argument) and, when it returns an object, a call of that object's vtable 0x138 with (b, c, this). Name GUESS.
#include "ff.h"

typedef u32(THISCALL *SlotArgRet)(u8 *, u32);                 // vtable slot, one stack word, eax result
typedef void(THISCALL *SlotThreeVoid)(u8 *, u32, u32, u8 *);  // vtable slot, three stack words, no result used

static u32 vslot4(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x45fb00, thiscall(a, b, c) (ret 0xc): child = [[0x70039c] + 0x9b]; r = child->vt[0x58](child, a); if r:
// r->vt[0x138](r, b, c, this). Name GUESS.
static void THISCALL lookupCall_45fb00(u8 *self, u32 a, u32 b, u32 c) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *child = *(u8 **)(rm + 0x9b);
  u8 *r = (u8 *)(u32)((SlotArgRet)vslot4(child, 0x58))(child, a);
  if (r) ((SlotThreeVoid)vslot4(r, 0x138))(r, b, c, self);
  (void)c;
}
PCREG(45fb00, lookupCall_45fb00);
