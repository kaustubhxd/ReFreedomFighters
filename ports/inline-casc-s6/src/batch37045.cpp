// batch37045.cpp - cascade s6 batch 37045: 0x4730b0.
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define C0(o, off) ((*(v0_t **)(o))[(off) / 4]((o)))
#define ST() C0(self, 0x3f0)

// 0x4730b0, thiscall(a) ret 4, returns 0, 1 or 2: state transition request. The state of this (slot 0x3f0) 3 or 4 means nothing to do (0). When a answers slot 0x1e0(0x1007da):
// through the object this+slot 0x500 gives (if any) its state object slot 0x2e8's slot 0x308 flag decides between requesting state 9 (flag set) or 5 through slot 0x45c(state, 0)
// (skipped when already in that state) and returns 1. Otherwise, only in state 4, the object of slot 0x504 decides: state-object slot 0x300 == 2 requests 0xa, else slot 0x308 == 0
// requests 6; returns 2.
static u32 THISCALL fn4730b0(void *self, void *a) {
  if (ST() == 4) return 0;
  if (ST() == 3) return 0;
  C0(a, 0x2e8);
  if ((u8)(*(v1_t **)a)[0x1e0 / 4](a, 0x1007da)) {
    if (ST() == 3) return 0;
    void *p = (void *)C0(self, 0x500);
    if (!p) return 1;
    void *x = (void *)C0(p, 0x2e8);
    u32 q = C0(x, 0x308);
    if (q != 0) {
      if (ST() == 9) return 0;
      (*(v2_t **)self)[0x45c / 4](self, 9, 0);
      return 1;
    }
    if (ST() == 5) return 0;
    (*(v2_t **)self)[0x45c / 4](self, 5, 0);
    return 1;
  }
  if (ST() != 4) return 0;
  void *s = (void *)C0(self, 0x504);
  if (!s) return 2;
  void *y = (void *)C0(s, 0x2e8);
  if (C0(y, 0x300) == 2) {
    if (ST() == 0xa) return 0;
    (*(v2_t **)self)[0x45c / 4](self, 0xa, 0);
    return 2;
  }
  void *y2 = (void *)C0(s, 0x2e8);
  if (C0(y2, 0x308) != 0) return 2;
  if (ST() == 6) return 0;
  (*(v2_t **)self)[0x45c / 4](self, 6, 0);
  return 2;
}
PCREG(4730b0, fn4730b0);
