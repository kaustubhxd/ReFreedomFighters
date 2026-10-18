#include "ff.h"

extern "C" u32 THISCALL ext_52e320(void *s2, void *mv);
extern "C" u32 THISCALL ext_531070(void *s2, void *mv);
extern "C" u32 THISCALL ext_530a40(void *s2);
extern "C" u32 THISCALL ext_532730(void *self, u32 v);
extern "C" float FASTCALL ext_532850(void *a, void *b);
extern "C" void THISCALL ext_52d250(void *self, u32 a, u32 b);
extern "C" void FASTCALL ext_633654(u32 cookie);

#define EBP (fr + 0x98)
#define P(off) (EBP - (off))
static inline u16 R16(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W16(u8 *p, u16 v) { __builtin_memcpy(p, &v, 2); }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

// 0x5320b0: thiscall(cell a, level d, S, pos) ret 0x10 -> ax, /GS. Walks the (up to 255) entries of the lookup record of cell a (cell = this[0x98] + a * 0x15; its
// entry index at +0 selects a 12 byte [0x5a] item on the last level d == this[0x38] - 1 or a 0x16 byte [0x54] node otherwise; its records are 10 bytes at [0x66]). Records
// whose kind byte equals cell[3] move the cell by (scale * record words) into a copy S2 of the query struct S (0x2d bytes at ebp-0x34, probe 0x52e320 for kind 3, else 0x531070);
// a hit asks 0x530a40 for the neighbour cell, optionally compares heights (0x532850 distances when byte [0x6e9000] and pos are set) and rewrites the neighbour cell
// (0x52d250) when its height is higher than ours + margin. Returns 0xffff when the neighbour lookup fails, else 1.
// The frame keeps the original layout (the real helpers 0x530a40 / 0x532850 / probes read the stack structs): ebp = fr + 0x98.
static u32 body_5320b0(u8 *edi, u32 a_arg, u32 d, u8 *S, u8 *pos) {
  u8 fr[0xa0];
  __builtin_memset(fr, 0xcc, sizeof fr);
  W32(P(0x78), (u32)S);
  W32(P(0x4c), (u32)pos);
  u32 ecx_a = (u16)a_arg;
  u8 *esi = edi == 0 ? 0 : (u8 *)(ecx_a * 0x15 + R32(edi + 0x98));
  W32(P(0x7c), (u32)edi);
  W32(P(0x88), ecx_a);
  W32(P(0x3c), (u32)esi);
  u32 idx = R16(esi);
  u32 edx;
  if (d == R32(edi + 0x38) - 1) edx = R16((u8 *)R32(edi + 0x5a) + idx * 12);
  else edx = R16((u8 *)(idx * 0x16 + R32(edi + 0x54)));
  u32 rec8 = R16((u8 *)(R32(edi + 0x78) + edx * 10 + 8));
  u8 al = *(u8 *)(R32(edi + 0x7c) + edx);
  if (al == 0) return 1;
  W32(P(0x68), 0);
  W32(P(0x40), al);
  u32 off = rec8 * 10;
  W32(P(0x6c), off);
  for (;;) {
    u8 *ebx = (u8 *)(R32(edi + 0x66) + R32(P(0x6c)));
    if (ebx[0] == esi[3]) {
      u32 sh = R32(edi + 0x38) - d;
      u32 m1, m3;
      if (sh == 0) {
        m1 = 1;
        m3 = 1;
      } else {
        u32 c = (sh - 1) & 31;
        m1 = 8u << c;
        m3 = 1u << c;
        W32(P(0x44), m1);
      }
      u8 *cell = (u8 *)R32(P(0x3c));
      u16 di = R16(cell + 4);
      W16(P(0x38), di);
      di = R16(cell + 6);
      W16(P(0x36), R16(cell + 8));
      W16(P(0x58), R16(ebx + 2));
      W16(P(0x56), R16(ebx + 4));
      W16(P(0x54), R16(ebx + 6));
      u32 p1 = m1 * R32(P(0x58));
      u32 p2 = m1 * R32(P(0x56));
      u32 p3 = m3 * R32(P(0x54));
      u16 ax = R16(P(0x38));
      ax = (u16)(ax + (u16)p1);
      W16(P(0x38), ax);
      di = (u16)(di + (u16)p2);
      W16(P(0x94), ax);
      u32 aval = R32(P(0x88));
      W32(P(0x64), ebx[1]);
      W16(P(0x36), (u16)(R16(P(0x36)) + (u16)p3));
      __builtin_memcpy(P(0x34), S, 0x10);
      W32(P(0xc), R32(S + 0x28));
      *P(8) = S[0x2c];
      __builtin_memcpy(P(0x24), S + 0x10, 0x10);
      W16(P(0x46), di);
      W16(P(0x92), di);
      __builtin_memcpy(P(0x14), S + 0x20, 8);
      u32 r;
      if (*P(0x14) == 3) r = ext_52e320(P(0x34), P(0x58));
      else r = ext_531070(P(0x34), P(0x58));
      r = (u16)r;
      W32(P(0x44), r);
      if (r != 0) {
        u32 nb = (u16)ext_530a40(P(0x34));
        nb = (u16)(nb + (u16)(R32(P(0x64)) - 1));
        W32(P(0x8c), nb);
        if (nb == 0) return 0xffff;
        float x3 = G(float, 0x678858), x1 = 0.0f, x2 = 0.0f;
        u8 *ncell = (u8 *)(nb * 0x15 + R32(edi + 0x98));
        if (G(u8, 0x6e9000) && R32(P(0x4c)) != 0) {
          u8 *c0 = (u8 *)R32(P(0x3c));
          W16(P(0x60), R16(c0 + 4));
          W16(P(0x5e), R16(c0 + 6));
          W16(P(0x5c), R16(c0 + 8));
          W32(P(0x74), R32(P(0x94)));
          W16(P(0x70), R16(P(0x36)));
          float f84 = ext_532850((void *)R32(P(0x4c)), P(0x74));
          WF(P(0x84), f84);
          float f50 = ext_532850((void *)R32(P(0x4c)), P(0x60));
          WF(P(0x50), f50);
          float f80 = ext_532850(P(0x60), P(0x74));
          WF(P(0x80), f80);
          x1 = RF(P(0x84));
          x2 = RF(P(0x50));
          x3 = RF(P(0x80));
        }
        u8 *c0 = (u8 *)R32(P(0x3c));
        float xm = RF(c0 + 0xa);
        xm = xm + x3;
        xm = xm + x1;
        xm = xm - x2;
        xm = xm + G(float, 0x68c730);
        WF(P(0x50), xm);
        float lim = xm + G(float, 0x67a284);
        float nh = RF(ncell + 0xa);
        if (nh > lim) {
          u32 eax = R16(ebx + 8);
          u32 e2 = 0, cx = eax;
          if ((s16)(u16)eax < 0) {
            cx = (u16)(0 - cx);
            e2 = 1;
          }
          bool go = true;
          if (edi[4]) {
            u32 k = e2 + (u32)(u16)cx * 2;
            u32 v = R16((u8 *)(R32(edi + 0x8c) + k * 2));
            go = (u8)ext_532730(edi, v) != 0;
          }
          if (go) {
            u16 nx = (u16)(R16(P(0x38)) & 0xfff8);
            u32 av = R32(P(0x88));
            ncell[0x14] &= 0xfe;
            u16 ny = (u16)(R16(P(0x46)) & 0xfff8);
            WF(ncell + 0xa, RF(P(0x50)));
            W16(ncell + 0xe, (u16)av);
            W16(ncell + 4, nx);
            W16(ncell + 8, R16(P(0x36)));
            W16(ncell + 6, ny);
            ncell[3] = (u8)R32(P(0x64));
            W16(ncell, (u16)R32(P(0x44)));
            ext_52d250(edi, av, R32(P(0x8c)));
          }
        }
      }
      esi = (u8 *)R32(P(0x3c));
    }
    u32 j = R32(P(0x68)) + 1;
    W32(P(0x68), j);
    W32(P(0x6c), R32(P(0x6c)) + 10);
    if ((s32)j >= (s32)R32(P(0x40))) break;
  }
  return 1;
}
extern "C" u32 THISCALL fn_5320b0(u8 *self, u32 a, u32 d, u8 *S, u8 *pos);
extern "C" u32 THISCALL fn_5320b0(u8 *self, u32 a, u32 d, u8 *S, u8 *pos) {
  u32 r = body_5320b0(self, a, d, S, pos);
  ext_633654(G(u32, 0x6f5630));
  return (u16)r;
}
PCREG(5320b0, fn_5320b0);
