// batch1104.cpp - unclaimed-11 batch 4 (docs/20-unclaimed-11.md): ZActor::MoveToPosition (0x4796e0, high).
// Thiscall, two stack arguments (ret 8). Three virtual calls on this, in this order: slot 0x630(out) fills a local
// vec3, slot 0x5e8(a2), slot 0x5e0(local, a1). The slots are read from the object's vtable at run time, as the PC does.
#include "ff.h"

typedef void(THISCALL *vfn1)(void *self, void *arg);
typedef void(THISCALL *vfn2)(void *self, void *arg1, void *arg2);

// 0x4796e0, ZActor::MoveToPosition(const float*, const float*) (high).
static void THISCALL actorMoveToPosition(u8 *self, const float *a1, const float *a2) {
  float local[3];
  void **vt = *(void ***)self;
  ((vfn1)vt[0x630 / 4])(self, local);
  ((vfn1)vt[0x5e8 / 4])(self, (void *)a2);
  ((vfn2)vt[0x5e0 / 4])(self, local, (void *)a1);
}
PCREG(4796e0, actorMoveToPosition);
