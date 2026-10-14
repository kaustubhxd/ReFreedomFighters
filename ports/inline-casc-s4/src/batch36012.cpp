// batch36012.cpp - cascade s4 batch 36012: 0x4db860, 0x4f4160, 0x5601c0, 0x56f0c0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_4da770(void *self, u32 a);               // ret 4
extern "C" u8 *THISCALL ext_4daff0(void *self);                       // plain ret
extern "C" void THISCALL ext_4dae60(void *self);                      // plain ret
extern "C" void THISCALL ext_4d9bf0(void *self);                      // plain ret
extern "C" void THISCALL ext_4d9ce0(void *self);                      // plain ret
extern "C" void THISCALL ext_4d9d20(void *self, u32 a);               // ret 4
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);        // ret 8

// 0x4db860, thiscall(flag) ret 4 (this = E). flag: E[0x3c] & 0x800 returns; 0x4da770(E, 0); when E[0x3c] & 0x40000 and E[0x64] and (E[0x3c] & 0xff): q = 0x4daff0(E[0x50] ? E[0x50][0x54][8] : 0),
// q->slot 0x320(E), E[0x64] = 0, then 0x4dae60(E) for the whole 0x40000 case; finally 0x4dc630(E, 0x800, 0). No flag: returns unless E[0x3c] & 0x800; 0x4dc630(E, 0, 0x800);
// returns when E[0x3c] & 0x200c00; with 0x40000: E[0x64] == 0 -> 0x4d9ce0(E); then 0x4d9bf0(E); finally 0x4d9d20(E, 0).
static void THISCALL fn4db860(u8 *E, u32 flag) {
  if ((u8)flag) {
    if (rd(E + 0x3c) & 0x800) return;
    ext_4da770(E, 0);
    u32 f = rd(E + 0x3c);
    if (f & 0x40000) {
      bool done = false;
      if (rd(E + 0x64) != 0 && (u8)f != 0) {
        u8 *p = *(u8 **)(E + 0x50);
        u8 *ctx = p ? *(u8 **)(p + 0x54) : 0;
        u8 *c2 = *(u8 **)(ctx + 8);
        u8 *q = ext_4daff0(c2);
        if (q) {
          (*(v1_t **)q)[0x320 / 4](q, (u32)E);
          wr(E + 0x64, 0);
        }
        done = true;
      }
      (void)done;
      ext_4dae60(E);
    }
    ext_4dc630(E, 0x800, 0);
    return;
  }
  if (!(rd(E + 0x3c) & 0x800)) return;
  ext_4dc630(E, 0, 0x800);
  u32 f = rd(E + 0x3c);
  if (f & 0x200c00) return;
  if (f & 0x40000) {
    if (rd(E + 0x64) == 0) ext_4d9ce0(E);
    ext_4d9bf0(E);
  }
  ext_4d9d20(E, 0);
}
PCREG(4db860, fn4db860);

extern "C" void THISCALL ext_4ef660(void *self, void *s);  // ret 4
extern "C" void THISCALL ext_4e12e0(void *self, u32 *out, u32 n);  // ret 8
extern "C" void THISCALL ext_4e1b30(void *self);

// 0x4f4160, thiscall(s) ret 4 (this = E): 0x4ef660(E, s); local = 0; 0x4e12e0(s, &local, 1); P = ([[0x70039c]+0x1aa3][0x18])->slot 0xc(local);
// E[0x2e] = cnt = P[0]; E[0x2a] = P+4; E[0x91] = 1; Q = P+4+cnt*40; E[0x32] = q = Q[0]; E[0x36] = Q+4; E[0x3a] = Q+4+q*4; each rec[4] (stride 8) = E[0x2a] + rec[4]*40;
// E->slot 0x228(); E->slot 0x244(); E[0x90] = 1; 0x4e1b30(s).
static void THISCALL fn4f4160(u8 *E, u8 *s) {
  typedef void(THISCALL * v0_t)(void *);
  u32 local = 0;
  ext_4ef660(E, s);
  ext_4e12e0(s, &local, 1);
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *h = *(u8 **)(o + 0x18);
  u8 *P = (*(v1o_t **)h)[0xc / 4](h, local);
  u32 cnt = rd(P);
  wr(E + 0x2e, cnt);
  wr(E + 0x2a, (u32)(P + 4));
  E[0x91] = 1;
  u8 *Q = P + 4 + cnt * 40;
  u32 q = rd(Q);
  wr(E + 0x32, q);
  wr(E + 0x36, (u32)(Q + 4));
  wr(E + 0x3a, (u32)(Q + 4 + q * 4));
  if (q != 0) {
    u32 i = 0;
    do {
      u8 *rec = *(u8 **)(E + 0x3a) + 8 * i;
      i++;
      wr(rec + 4, rd(E + 0x2a) + rd(rec + 4) * 40);
    } while (i < rd(E + 0x32));
  }
  (*(v0_t **)E)[0x228 / 4](E);
  (*(v0_t **)E)[0x244 / 4](E);
  E[0x90] = 1;
  ext_4e1b30(s);
}
PCREG(4f4160, fn4f4160);

// 0x5601c0, thiscall(a) ret 4 (this = E): for k in {0x55fd40, 0x55fe40, 0x55ffb0, 0x55ffe0, 0x5600a0, 0x560010, 0x55ff50, 0x55fca0, 0x55fbd0}: a[0xc] byte zero returns; E->slot 0x48(k).
static void THISCALL fn5601c0(u8 *E, u8 *a) {
  static const u32 ks[9] = {0x55fd40, 0x55fe40, 0x55ffb0, 0x55ffe0, 0x5600a0, 0x560010, 0x55ff50, 0x55fca0, 0x55fbd0};
  for (int i = 0; i < 9; i++) {
    if (a[0xc] == 0) return;
    (*(v1_t **)E)[0x48 / 4](E, ks[i]);
  }
}
PCREG(5601c0, fn5601c0);

extern "C" u32 THISCALL ext_561cb0(void *self, u32 code, u32 *p);  // ret 8

// 0x56f0c0, thiscall(code, p) ret 8 (this = E): t = [[0x70039c]+0x9b]; (u16)code == (u16)t->slot 0x114(0x6a8530, 0, 0x6a8508, 0x281): v = *p; v != 6: E[0x1eb] = v + '0', E[0x1ec..0x1ed] = 0x0052; else
// E[0x1e9] = [0x6a7810] (dword), E[0x1ed] = [0x6a7814] (byte); returns 0. Else (u16)code == (u16)t->slot 0x114(0x6a6868, 0, 0x6a8508, 0x292): E[0x4b6] = *p, returns 1. Else 0x561cb0(E, code, p).
static u32 THISCALL fn56f0c0(u8 *E, u32 code, u32 *p) {
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = (*(v4r_t **)t)[0x114 / 4](t, 0x6a8530u, 0, 0x6a8508u, 0x281u);
  if ((u16)code == (u16)r) {
    u32 v = *p;
    if (v != 6) {
      *(u16 *)(E + 0x1ec) = 0x52;
      E[0x1eb] = (u8)(v + 0x30);
      return 0;
    }
    wr(E + 0x1e9, G(u32, 0x6a7810));
    E[0x1ed] = G(u8, 0x6a7814);
    return 0;
  }
  t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  r = (*(v4r_t **)t)[0x114 / 4](t, 0x6a6868u, 0, 0x6a8508u, 0x292u);
  if ((u16)code == (u16)r) {
    wr(E + 0x4b6, *p);
    return 1;
  }
  return ext_561cb0(E, code, p);
}
PCREG(56f0c0, fn56f0c0);
