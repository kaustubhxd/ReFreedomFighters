// batch67520.cpp - cascade s6 batch 67520: 0x55aec0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" u8 *THISCALL ext_5002f0(u8 *node, u32 v);     // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x55aec0, thiscall(a) ret 4: script op picking a neighbour. The result node a+8 is first set to int 0. With the owner's object list at [this+0x1c]+0x921 (count, then pointers) and
// the first argument a direction flag, every listed object that does not answer slot 0x438 and whose slot-0x20 record has flag bit 10 clear is scored (slot 0x674 when the flag is set,
// else slot 0x6a8); the highest score above both -1 and the owner's own score (0x674 minus 1 / 0x6a8) wins, unless it is the owner itself, and its table handle (slot 0x4c) becomes the result.
static void THISCALL fn55aec0(u8 *self, u8 *a) {
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), 0);
  u32 dir = D32(ext_5003d0(*(u32 *)(a + 4), 0), 0);
  u8 *owner = *(u8 **)(self + 0x1c);
  u8 *list = *(u8 **)(owner + 0x921);
  if (!list) return;
  s32 best = -1;
  u8 *bestSlot = list + (D32(list, 0) + 1) * 4;
  s32 base = dir ? (s32)vcall<u32>(owner, 0x674) - 1 : (s32)vcall<u32>(owner, 0x6a8);
  for (u8 *p = list + 4; p != list + (D32(list, 0) + 1) * 4; p += 4) {
    u8 *obj = *(u8 **)p;
    if ((u8)vcall<u32>(obj, 0x438)) continue;
    u8 *rec = (u8 *)vcall<u32>(obj, 0x20);
    u32 v = D32(*(u8 **)(rec + 8), 0x3c);
    if (((~(v >> 10)) & 1) == 0) continue;
    s32 sc = dir ? (s32)vcall<u32>(obj, 0x674) : (s32)vcall<u32>(obj, 0x6a8);
    if (sc > best && sc > base) {
      best = sc;
      bestSlot = p;
    }
  }
  if (bestSlot == list + (D32(list, 0) + 1) * 4) return;
  u32 cand = D32(bestSlot, 0);
  if (cand == D32(self, 0x1c)) return;
  u32 h = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x4c, cand);
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), h);
}
PCREG(55aec0, fn55aec0);
