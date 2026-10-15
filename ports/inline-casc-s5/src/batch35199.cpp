// batch35199.cpp - cascade s5 batch 35199 (tier H): 0x4b7240 (GUESS update a menu/HUD entry: refresh its cached value, then show or hide its linked object).
#include "ff.h"

extern "C" u32 THISCALL ext_467260(u8 *self, u32 a, u32 b, u32 c);                                    // ret 0xc
extern "C" u8 *THISCALL ext_4dc130(u8 *self);                                                         // getter, plain ret
extern "C" u32 THISCALL ext_43ec00(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);               // ret 0x18
extern "C" void THISCALL ext_441890(u8 *self, float f);                                               // ret 4
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *o2_t)(void *, u32, u32);
typedef u8 *(THISCALL *o1_t)(void *, u32);
typedef u8(THISCALL *b1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4b7240, thiscall(a, unused) ret 8, no return value. (1) byte [+0x180]: [+0x64] = dword [engine+0x40]; byte [+0x181]: this slot 0x64(0x10); this slot 0x9c(). (2) Returns when the unaligned dword [engine+0x1a9f] is 0 or tab slot 0x58([+0x50]) is null.
// R = [+0x50] ? this slot 0x94(a, [+0x50]) : 0; X = R[0x54] (R must not be null here); when X exists and X slot 0x1e0(0x200027): mode [+0x54] == 1: X slot 0x3f8([+0x58] != 0) and return; mode 0: v = 0x467260(X, [+0x58], 0xc, 0); [+0x6c] = v; e = tab slot 0x60(v) (null returns);
// O = unaligned [engine+0x1a9f]; O slot 0x70([+0x58]) must be true; e[0x88] = [+0x60]; other modes return. Otherwise (no X or slot false): when [+0x50] and R2 = this slot 0x94(a, [+0x50]) are non-null: v = 0x43ec00(0x4dc130(R2), R2, R2 + 0x24, [+0x58], 0, 0, 0); [+0x6c] = v;
// e = tab slot 0x60(v) (null returns); e[0x40] |= 0x80; e[0x2c] = 2; e[0x88] = [+0x60]. Both successful paths end with 0x441890(e, float [+0x5c]) and e[0x40] = (e[0x40] & ~4) | 0x20.
static void THISCALL fn4b7240(u8 *self, u32 a, u32 unused) {
  if (self[0x180]) {
    *(u32 *)(self + 0x64) = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
    if (self[0x181]) (*(v1_t **)self)[0x64 / 4](self, 0x10);
    (*(v0_t **)self)[0x9c / 4](self);
  }
  u8 *eng = G(u8 *, 0x70039c);
  if (rd32u(eng + 0x1a9f) == 0) return;
  u8 *tab = *(u8 **)(eng + 0x9b);
  if (!(*(o1_t **)tab)[0x58 / 4](tab, *(u32 *)(self + 0x50))) return;
  u32 k = *(u32 *)(self + 0x50);
  u8 *R = 0;
  if (k) R = (*(o2_t **)self)[0x94 / 4](self, a, k);
  u8 *X = *(u8 **)(R + 0x54);
  u8 *e;
  if (X && (*(b1_t **)X)[0x1e0 / 4](X, 0x200027)) {
    u32 mode = *(u32 *)(self + 0x54);
    if (mode == 1) {
      (*(v1_t **)X)[0x3f8 / 4](X, *(u32 *)(self + 0x58) != 0 ? 1 : 0);
      return;
    }
    if (mode != 0) return;
    u32 v = ext_467260(X, *(u32 *)(self + 0x58), 0xc, 0);
    *(u32 *)(self + 0x6c) = v;
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    e = (*(o1_t **)tab)[0x60 / 4](tab, v);
    if (!e) return;
    eng = G(u8 *, 0x70039c);
    u8 *O = (u8 *)rd32u(eng + 0x1a9f);
    if (!(*(b1_t **)O)[0x70 / 4](O, *(u32 *)(self + 0x58))) return;
    *(u32 *)(e + 0x88) = *(u32 *)(self + 0x60);
  } else {
    u32 k2 = *(u32 *)(self + 0x50);
    if (!k2) return;
    u8 *R2 = (*(o2_t **)self)[0x94 / 4](self, a, k2);
    if (!R2) return;
    u8 *o = ext_4dc130(R2);
    u32 v = ext_43ec00(o, (u32)R2, (u32)(R2 + 0x24), *(u32 *)(self + 0x58), 0, 0, 0);
    *(u32 *)(self + 0x6c) = v;
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    e = (*(o1_t **)tab)[0x60 / 4](tab, v);
    if (!e) return;
    *(u32 *)(e + 0x40) |= 0x80;
    *(u32 *)(e + 0x2c) = 2;
    *(u32 *)(e + 0x88) = *(u32 *)(self + 0x60);
  }
  ext_441890(e, bitsf(*(u32 *)(self + 0x5c)));
  *(u32 *)(e + 0x40) = (*(u32 *)(e + 0x40) & 0xfffffffbu) | 0x20;
}
PCREG(4b7240, fn4b7240);
