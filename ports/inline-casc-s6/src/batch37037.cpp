// batch37037.cpp - cascade s6 batch 37037: 0x4a88c0.
#include "ff.h"

extern "C" void THISCALL ext_4a93b0(u8 *self);   // plain ret
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define W16(o) (*(u16 *)(self + (o)))
#define F32(o) (*(u32 *)(self + (o)))

// 0x4a88c0, thiscall(id, p) ret 8, always returns 0: message handler keyed by the 16-bit id. this: +0xcf / +0xcd / +0x48 / +0x67 / +0x89 are the ids it reacts to.
// +0xcf: runs 0x4a93b0 (and continues); +0xcd: shows/hides the table object named by +0xc3 (slot 0xbc(p == 0)); +0x48: stores p == 0 at +0x4a and
// drives the object at +0x4e (slot 0xbc(p != 0), slot 0x2c when p == 0 else 0x28); +0x67: state machine on p[0] (2 stores p[1..3] at +0x7d.., 4 / 5 count at +0xd2 and
// toggle the object at +0x4e) always storing p[0] at +0x75; +0x89: copies +0x8b / +0x8f into p[0] / p[1].
static u32 THISCALL fn4a88c0(u8 *self, u32 idw, u32 *p) {
  u16 id = (u16)idw;
  if (id == W16(0xcf)) ext_4a93b0(self);
  if (id == W16(0xcd)) {
    void *t = *(void **)(*(u8 **)0x70039c + 0x9b);
    u8 *o = (u8 *)(*(v1_t **)t)[0x58 / 4](t, F32(0xc3));
    if (!o) return 0;
    (*(v1_t **)o)[0xbc / 4](o, p == 0);
    return 0;
  }
  if (id == W16(0x48)) {
    F32(0x4a) = (p == 0);
    void *q = *(void **)(self + 0x4e);
    if (!q) return 0;
    (*(v1_t **)q)[0xbc / 4](q, p != 0);
    q = *(void **)(self + 0x4e);
    if (p == 0) (*(v0_t **)q)[0x2c / 4](q);
    else (*(v0_t **)q)[0x28 / 4](q);
    return 0;
  }
  if (id == W16(0x67)) {
    void *q;
    switch (p[0]) {
      case 2:
        F32(0x7d) = p[1];
        F32(0x81) = p[2];
        F32(0x85) = p[3];
        break;
      case 4: {
        u32 c = F32(0xd2);
        F32(0xd2) = c + 1;
        if (c == 0) {
          q = *(void **)(self + 0x4e);
          (*(v1_t **)q)[0xbc / 4](q, 1);
          q = *(void **)(self + 0x4e);
          (*(v0_t **)q)[0x28 / 4](q);
          F32(0x79) = F32(0x75);
        }
        break;
      }
      case 5:
        F32(0xd2) = F32(0xd2) - 1;
        if ((s32)F32(0xd2) <= 0) {
          if (F32(0x4a) != 0) {
            q = *(void **)(self + 0x4e);
            (*(v1_t **)q)[0xbc / 4](q, 0);
            q = *(void **)(self + 0x4e);
            (*(v0_t **)q)[0x2c / 4](q);
          }
          F32(0x75) = F32(0x79);
          F32(0xd2) = 0;
          return 0;
        }
        break;
      default:
        break;
    }
    F32(0x75) = p[0];
    return 0;
  }
  if (id == W16(0x89)) {
    p[0] = F32(0x8b);
    p[1] = F32(0x8f);
  }
  return 0;
}
PCREG(4a88c0, fn4a88c0);
