// batch5748.cpp - unclaimed-57, band batch 48 (name GUESS): 0x5da670, thiscall, two stack args (a1 = object, a2 = pointer to 3 floats p),
// ret 8. tmp[0] = p0 * this+0x7e + this+0x76; t = this+0x82; v1 = p1 * t + this+0x7a; v2 = p3 * t (the fourth float, at +0xc); tmp[1] = (K - v1) - v2 (K = float at
// 0x678858); tmp[2] = p2 * this+0x7e. Then a1->vt[+0x23c](&tmp) (thiscall, one argument; unverified: a fake slot in the spec logs the three
// values, not the stack address). Ends with the stack cookie check 0x633654 (a no-op here: the cookie is unchanged; hooked in the spec).
// SEH/cookie: the cookie write and check are not reproduced; their only effect is the check itself, which passes.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *SlotVec)(u8 *self, float *p);

static void THISCALL unnamed5da670(u8 *self, u32 a1, u32 a2) {
  float *p = (float *)(unsigned long)a2;
  u8 *o = (u8 *)(unsigned long)a1;
  float tmp[3];
  tmp[0] = p[0] * *(float *)(self + 0x7e) + *(float *)(self + 0x76);
  float t = *(float *)(self + 0x82);
  float v1 = p[1] * t + *(float *)(self + 0x7a);
  float v2 = p[3] * t;
  float k = G(float, 0x678858);
  tmp[1] = (k - v1) - v2;
  tmp[2] = p[2] * *(float *)(self + 0x7e);
  ((SlotVec)VT(o)[0x23c / 4])(o, tmp);
}
PCREG(5da670, unnamed5da670);
