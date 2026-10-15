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

// 0x473b70 ForceLHandItem(item, force): the same for the left hand (type slot 0x514, attach slot 0x524) without the
// "already held" test. Note the exe's type-1 branch works on the RIGHT hand (+0x34f, IK target +0x353), unlike the
// drop branch (left hand +0x2e7, +0x2eb); kept as is.
static void THISCALL forceLHandItem(u8 *self, u8 *item, u8 force) {
  u32 ty = ((vU0)VT(self, 0x514))(self);
  if (!force && ty) {
    if (ty == 1) {
      u8 *hd = self + 0x34f;
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ((vUUU)VT(cur, 0x2d0))(cur, 1, 0);
      ext_467410(self + 0x353, (u32)self, 0.0f, kNone);
      hd = self + 0x34f;
      ((vUUU)VT(hd, 8))(hd, (u32)self, 0);
    } else {
      u8 *hd = self + 0x2e7;
      u8 *cur = (u8 *)((vU0)VT(hd, 0x10))(hd);
      if (!cur)
        return;
      ext_467410(self + 0x2eb, (u32)self, 0.0f, kNone);
      ((vUU)VT(self, 0x46c))(self, (u32)cur);
    }
    return;
  }
  if (!item) {
    ((vUU)VT(self, 0x524))(self, 0);
    return;
  }
  ((vUU)VT(self, 0x524))(self, handleOf((u32)item));
  ((vUUU)VT(item, 0x2d0))(item, 0, 0);
}
PCREG(473b70, forceLHandItem);
