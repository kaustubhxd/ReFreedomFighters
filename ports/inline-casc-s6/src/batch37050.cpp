// batch37050.cpp - cascade s6 batch 37050.. 0x472280.
#include "ff.h"

extern "C" void THISCALL ext_4dcbb0(u8 *self, u32 f);          // ret 4
extern "C" void THISCALL ext_474eb0(u8 *self, u8 *b, u8 *p);   // ret 8
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define F32(o) (*(u32 *)(self + (o)))

static inline u8 *tabObj() { return *(u8 **)(*(u8 **)0x70039c + 0x9b); }
static inline u8 *look(u32 id) { u8 *t = tabObj(); return (u8 *)(*(v1_t **)t)[0x58 / 4](t, id); }

// 0x472280, thiscall(b, id) ret 8, returns the previous id (+0x51): switches the object bound to the entity b from the current one to the object named id. The same non-zero id
// logs error 0x4d and returns. With an object for id: this+0x55 = 1, its slot 0x2f0 gets b's handle from table slot 0x4c(b, [table+0xadc], 1), b's slot 0x290 is told
// (O+8, kind, ...) (a 3-float record {0, -4.0f, 0} for kind 0x11), 0x4dcbb0(O+8, 1) and b slot 0x128(word +0x66, id, 0). Without one the previous object (+0x51) is unbound instead
// (b slot 0x294, 0x4dcbb0(.., 0), 0x474eb0, this+0x55 = 0, slot 0x128(word, 2, 0)). Finally +0x51 = id (or 0).
static u32 THISCALL fn472280(u8 *self, u8 *b, u32 id) {
  if (id != 0 && id == F32(0x51)) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x68961c, 0x4d);
    (*(cdl_t **)L)[0x2c / 4](L, 0x689684);
    return F32(0x51);
  }
  u8 *o = look(id);
  u32 esi;
  if (o) {
    *(u8 *)(self + 0x55) = 1;
    u8 *t = tabObj();
    u32 h = (*(v3_t **)t)[0x4c / 4](t, (u32)b, *(u32 *)(t + 0xadc), 1);
    (*(v1_t **)o)[0x2f0 / 4](o, h);
    u32 kind = F32(0x56);
    if (kind == 0x11) {
      u32 v[3] = {0, 0xc0800000u, 0};
      (*(v4_t **)b)[0x290 / 4](b, *(u32 *)(o + 8), 0x11, 0, (u32)v);
    } else {
      (*(v4_t **)b)[0x290 / 4](b, *(u32 *)(o + 8), kind, 0, 0);
    }
    ext_4dcbb0(*(u8 **)(o + 8), 1);
    esi = id;
    if (esi == 0) {
      (*(v3_t **)b)[0x128 / 4](b, *(u16 *)(self + 0x66), 2, 0);
    } else {
      (*(v3_t **)b)[0x128 / 4](b, *(u16 *)(self + 0x66), esi, 0);
    }
  } else {
    u8 *p = look(F32(0x51));
    if (!p) return 0;
    (*(v2_t **)b)[0x294 / 4](b, *(u32 *)(p + 8), F32(0x56));
    ext_4dcbb0(*(u8 **)(p + 8), 0);
    ext_474eb0(self, b, p);
    *(u8 *)(self + 0x55) = 0;
    esi = 0;
    (*(v3_t **)b)[0x128 / 4](b, *(u16 *)(self + 0x66), 2, 0);
  }
  u32 old = F32(0x51);
  F32(0x51) = esi;
  return old;
}
PCREG(472280, fn472280);
