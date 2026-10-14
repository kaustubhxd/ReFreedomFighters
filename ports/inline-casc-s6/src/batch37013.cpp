// batch37013.cpp - cascade s6 batch 37013: 0x51d6f0.
#include "ff.h"

extern "C" void THISCALL ext_4db2c0(u8 *self, u32 *a, u32 *b);                                  // ret 8
extern "C" u32 THISCALL ext_43ec00(u8 *self, u32 *a, u32 *b, u32 c, u32 d, u32 e, u32 f);      // ret 0x18
extern "C" void THISCALL ext_46b440(u8 *self, u32 a, u32 b);                                    // ret 8
typedef u32(THISCALL *v1_t)(void *, u32);

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u8 *slot58(u32 id) { void *t = tabObj(); return (u8 *)(*(v1_t **)t)[0x58 / 4](t, id); }
static inline u8 *slot60(u32 id) { void *t = tabObj(); return (u8 *)(*(v1_t **)t)[0x60 / 4](t, id); }
#define F32(o) (*(u32 *)(self + (o)))

// 0x51d6f0, thiscall, no args: when +0x469 is set, creates (once each) two effect handles from the objects named at +0x409 / +0x40d (stored at +0x4a1 / +0x49d via
// 0x4db2c0 + 0x43ec00) and primes the effect record the table returns for the handle (0.1f at +0x78, +0x60/+0x64 set up, +0x84 = this+0x1f1);
// when it is clear, fades both handles out with 0x46b440(0, 0.1f) and clears them.
static void THISCALL fn51d6f0(u8 *self) {
  if (F32(0x469)) {
    u32 id = F32(0x409);
    if (id && !F32(0x4a1)) {
      u8 *o = slot58(id);
      if (o) {
        u32 v34[9], v10[3];
        ext_4db2c0(*(u8 **)(o + 8), v34, v10);
        u32 h = ext_43ec00(o, v34, v10, F32(0x495), 0, 0, 0);
        F32(0x4a1) = h;
        u8 *p = slot60(h);
        if (p) {
          *(u32 *)(p + 0x78) = 0x3dcccccd;
          *(u32 *)(p + 0x60) = 0x19 - *(u32 *)(p + 0x64);
          *(u32 *)(p + 0x64) = 0x19;
          *(u32 *)(p + 0x84) = F32(0x1f1);
        }
      }
    }
    id = F32(0x40d);
    if (id && !F32(0x49d)) {
      u8 *o = slot58(id);
      if (o) {
        u32 v34[9], v10[3];
        ext_4db2c0(*(u8 **)(o + 8), v34, v10);
        u32 h = ext_43ec00(o, v34, v10, F32(0x495), 0, 0, 0);
        F32(0x49d) = h;
        u8 *p = slot60(h);
        if (p) {
          u32 t = -*(u32 *)(p + 0x64);
          *(u32 *)(p + 0x64) = 0;
          *(u32 *)(p + 0x60) = t;
          *(u32 *)(p + 0x84) = F32(0x1f1);
        }
      }
    }
    return;
  }
  u32 h = F32(0x4a1);
  if (h) {
    u8 *p = slot60(h);
    if (p) ext_46b440(p, 0, 0x3dcccccd);
    F32(0x4a1) = 0;
  }
  h = F32(0x49d);
  if (h) {
    u8 *p = slot60(h);
    if (p) ext_46b440(p, 0, 0x3dcccccd);
    F32(0x49d) = 0;
  }
}
PCREG(51d6f0, fn51d6f0);
