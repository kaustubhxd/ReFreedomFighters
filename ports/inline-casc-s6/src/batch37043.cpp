// batch37043.cpp - cascade s6 batch 37043: 0x4b3270.
#include "ff.h"

extern "C" void THISCALL ext_4b3a70(u8 *self);                 // plain ret
extern "C" void THISCALL ext_4b6b90(u8 *self, u32 item);       // ret 4
extern "C" void THISCALL ext_4b6e00(u8 *self, u32 o, u32 f);   // ret 8
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))
#define B8(o) (*(u8 *)(self + (o)))
#define W16(o) (*(u16 *)(self + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x4b3270, thiscall, no args: tears the per-frame state down. Runs 0x4b3a70, hands every item of the list at this+0x10e (slots 0x4c / 0x64) to 0x4b6b90, every object the table
// returns (slot 0x54) for the ids of the list at this+0xf2 (slots 0x4c / 0x5c) to 0x4b6e00(o, 1), clears both lists (slot 0xc), zeroes the byte arrays at this+0x90 / +0x94
// (this+0xee entries), releases the object this+0x88 through the owner at this+0x44 (slot 0x12c), the object named at this+0x74 (slot 0x210, when +0x9a / +0xa0 are set and its
// +0x4c is 0) and finishes with slot 0x130 of the owner.
static void THISCALL fn4b3270(u8 *self) {
  B8(0x4d) = 0;
  ext_4b3a70(self);
  void *l1 = self + 0x10e;
  u32 v;
  (*(v1_t **)l1)[0x4c / 4](l1, (u32)&v);
  u32 item = (*(v1_t **)l1)[0x64 / 4](l1, (u32)&v);
  while (item != 0) {
    ext_4b6b90(self, item);
    item = (*(v1_t **)l1)[0x64 / 4](l1, (u32)&v);
  }
  (*(v0_t **)l1)[0xc / 4](l1);
  void *l2 = self + 0xf2;
  u32 v2;
  (*(v1_t **)l2)[0x4c / 4](l2, (u32)&v2);
  item = (*(v1_t **)l2)[0x5c / 4](l2, (u32)&v2);
  if (v2 != 0) {
    do {
      void *t = tabObj();
      u32 o = (*(v1_t **)t)[0x54 / 4](t, item);
      if (o) ext_4b6e00(self, o, 1);
      item = (*(v1_t **)l2)[0x5c / 4](l2, (u32)&v2);
    } while (v2 != 0);
  }
  (*(v0_t **)l2)[0xc / 4](l2);
  (*(v0_t **)l1)[0xc / 4](l1);
  if ((s32)F32(0xee) > 0) {
    for (s32 i = 0; i < (s32)F32(0xee); i++) {
      ((u8 *)F32(0x90))[i] = 0;
      ((u8 *)F32(0x94))[i] = 0;
    }
  }
  B8(0x9e) = 0;
  if (F32(0x88) != 0) {
    void *p = *(void **)(self + 0x44);
    void *t = tabObj();
    u32 id = (*(v1_t **)t)[0x4c / 4](t, (u32)p);
    (*(v3_t **)p)[0x12c / 4](p, F32(0x88), W16(0x50), id);
    F32(0x88) = 0;
  }
  if (B8(0x9a) != 0 && B8(0xa0) != 0) {
    void *t = tabObj();
    u8 *o = (u8 *)(*(v1_t **)t)[0x58 / 4](t, F32(0x74));
    if (*(u32 *)(o + 0x4c) == 0) {
      (*(v1_t **)o)[0x210 / 4](o, 1);
      F32(0x74) = 0;
      B8(0xa0) = 0;
    }
  }
  void *p = *(void **)(self + 0x44);
  (*(v3_t **)p)[0x130 / 4](p, (u32)p, W16(0x50), 0);
}
PCREG(4b3270, fn4b3270);
