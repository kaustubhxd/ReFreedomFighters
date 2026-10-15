// batch511.cpp - weapons thread, batch 511: putting items into the hands (ZLNKWHANDS ForceR/LHandItem and helpers).
// Hand slot objects: right +0x34f (its IK target ZTARGET at +0x353), left +0x2e7 (IK target +0x2eb).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
struct PMF { u32 fn, adj, vb, vi; };
extern "C" void THISCALL ext_467410(void *target, u32 owner, float time, PMF cb);   // ZTARGET remove with callback
static const PMF kNone = {0, 0, 0, 0xffffffffu};
static inline u32 handleOf(u32 o) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vUU)VT(rm, 0x4c))(rm, o);
}

// 0x473cd0 ForceRHandItem(item, force): nothing when the item is already in the right hand. Unless forced, an
// occupied hand (GetRHandItemType, slot 0x510, non-zero) is only emptied: type 1 puts the item away (state 1, IK
// target released, detached), other types drop it (LetItemFall, slot 0x46c); the new item is not taken this call.
// Forced or empty: attach the new item (AttachRHandItem slot 0x520 with its handle, or 0) and set it to state 0.
static void THISCALL forceRHandItem(u8 *self, u8 *item, u8 force) {
  u32 ty = ((vU0)VT(self, 0x510))(self);
  u8 *hd = self + 0x34f;
  if ((u8 *)((vU0)VT(hd, 0x10))(hd) == item)
    return;
  if (!force && ty) {
    if (ty == 1) {
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ((vUUU)VT(cur, 0x2d0))(cur, 1, 0);
      ext_467410(self + 0x353, (u32)self, 0.0f, kNone);
      ((vUUU)VT(hd, 8))(hd, (u32)self, 0);
    } else {
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ext_467410(self + 0x353, (u32)self, 0.0f, kNone);
      ((vUU)VT(self, 0x46c))(self, (u32)cur);
    }
    return;
  }
  if (!item) {
    ((vUU)VT(self, 0x520))(self, 0);
    return;
  }
  ((vUU)VT(self, 0x520))(self, handleOf((u32)item));
  ((vUUU)VT(item, 0x2d0))(item, 0, 0);
}
PCREG(473cd0, forceRHandItem);

