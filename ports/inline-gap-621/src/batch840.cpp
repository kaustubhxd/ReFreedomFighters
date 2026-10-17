// batch840.cpp - gap band functions with hooked callees (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_63f090(u8 *self, u8 *s);   // hooked (GUESS): returns an id in ax, ret 4

typedef u8 *(THISCALL *vg0_t)(u8 *self);
typedef u32 (THISCALL *vg1_t)(u8 *self, u8 *a);
typedef u32 (__attribute__((cdecl)) *qcb_t)(u8 *obj, u32 a, u32 b, u32 tag);

// 0x63f4e0: thiscall(out, ent, unused) ret 0xc - al. If u16 ent[6] (id) is 0: takes a new slot s from this[0x228]->vt[8](), s[8] = ent,
// then this->vt[0x9c](s): on success ent[6] = 0x63f090(s), out[0x10] = s, returns 1; on failure this->vt[0x98](s) and
// this[0x228]->vt[0xc](s) (give it back), returns 0. A slot from this[0x228]->vt[8]() that is null returns 0. With an id, out[0x10] =
// this[0x68][(id & 0xfff)*4] and returns 1.
static u8 THISCALL resolveEntry_63f4e0(u8 *self, u8 *out, u8 *ent, u32 unused) {
  (void)unused;
  u32 id = *(u16 *)(ent + 6);
  if (id) {
    *(u32 *)(out + 0x10) = *(u32 *)(*(u8 **)(self + 0x68) + (id & 0xfff) * 4);
    return 1;
  }
  u8 *pool = *(u8 **)(self + 0x228);
  u8 *s = (*(vg0_t *)(*(u8 **)pool + 8))(pool);
  if (!s) return 0;
  *(u8 **)(s + 8) = ent;
  u8 ok = (u8)(*(vg1_t *)(*(u8 **)self + 0x9c))(self, s);
  if (ok) {
    *(u16 *)(ent + 6) = (u16)ext_63f090(self, s);
    *(u8 **)(out + 0x10) = s;
    return 1;
  }
  (*(vg1_t *)(*(u8 **)self + 0x98))(self, s);
  pool = *(u8 **)(self + 0x228);
  (*(vg1_t *)(*(u8 **)pool + 0xc))(pool, s);
  return 0;
}
PCREG(63f4e0, resolveEntry_63f4e0);

// 0x62ce70: cdecl(out, code, a, b, obj) - code 0xf returns 0; code 0x12 asks obj[0x1c](obj, a, b, 0x6c01bc) and then
// obj[0x1c](obj, a, b, 0x6c01ac): a nonzero answer sets *out to 0x62cf00 / 0x62cf40 and returns 0; otherwise if out[0xc] == 0 and
// code == 0x1c returns 0x34, else sets *out = 0x51f230 and returns -1
static u32 __attribute__((cdecl)) queryHandler_62ce70(u32 *out, u32 code, u32 a, u32 b, u8 *obj) {
  if (code == 0xf) return 0;
  if (code == 0x12) {
    if ((*(qcb_t *)(obj + 0x1c))(obj, a, b, 0x6c01bc)) {
      *out = 0x62cf00;
      return 0;
    }
    if ((*(qcb_t *)(obj + 0x1c))(obj, a, b, 0x6c01ac)) {
      *out = 0x62cf40;
      return 0;
    }
  }
  if (out[3] == 0 && code == 0x1c) return code + 0x18;
  *out = 0x51f230;
  return 0xffffffffu;
}
PCREG(62ce70, queryHandler_62ce70);
