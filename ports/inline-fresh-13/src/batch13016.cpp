// batch13016.cpp - fresh slice 13, batch 16 (docs/20-fresh-13.md), 2026-10-12.
// 0x658950 GUESS ZRender counter-page mouse select (no name map entry; it calls ZRender::PrintCounters 0x650430 first
// and uses the "MultiSelect" string 0x6c4400): thiscall, one argument (the first line), ret 4, returns a line count.
//  - r = PrintCounters(line); 0 -> return 0.
//  - this->vtbl[+0x118](&mouse) (two floats); the line height and width come from this->vtbl[+0xf8] / [+0xf4] (x87
//    st0 results) divided by the int at +0x88 on the x87 stack (53-bit control word) and stored as floats. row =
//    trunc((mouse.y - (h * 0.0f[0x6785d0] - 0.5f[0x67a6ac])) / h), col = trunc((mouse.x + 0.5f) / w).
//  - Mouse button state bytes sys+0xa10 / sys+0xa60 (>= 0x80 = down): click state 0x81241c goes 0 -> 1 on a press
//    (left as is otherwise; reset to 0 when up); with the second button down sys[+0x190]()->[+0x184](0, 0x32,
//    "MultiSelect") is called (cdecl, 4 words) and multi-select 0x812424 = 1, else 0x812424 = 0 and 0x812420 = 0.
//  - list = (this+0x94)->vtbl[+0x18](); only on a fresh click (state 1) with col < 0x50 and this->vtbl[+0x1a4]():
//    walk the list (iterator slots 0x4c init / 0x64 next) to element number `row` counting from line + 1; its
//    counter (element+8, mask at +0x1d9) toggles: a set mask is cleared (other counters with the same mask are
//    cleared too in single-select; in multi-select they are counted and the mask is kept in this+0x98 when shared);
//    an empty mask takes the multi-select mask 0x812420 or the lowest clear bit of this+0x98 (unless it is 0x3f),
//    is or-ed into this+0x98 and remembered in 0x812420. Then the state becomes 2. Returns line + 1 + steps walked
//    in that case, otherwise r.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_650430[];
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef u32(THISCALL *R0)(void *self);
typedef void(THISCALL *P1)(void *self, void *a);
typedef long double(THISCALL *FR)(void *self);
typedef void (*C4)(void *o, u32 a, u32 b, u32 c);

#define g_click G(u32, 0x81241c)
#define g_mask G(u32, 0x812420)
#define g_multi G(u8, 0x812424)

static float per(u8 *self, u32 slot) {
  long double v = ((FR)VT(self, slot))(self);
  float n = (float)AT(s32, self, 0x88);
  return (float)(v / (long double)n);
}

static u32 THISCALL fn658950(u8 *self, u32 line) {
  u32 r = ((R1)(void *)ext_650430)(self, line);
  if (!r)
    return 0;
  float mouse[2];
  ((P1)VT(self, 0x118))(self, mouse);
  float h = per(self, 0xf8);
  s32 row = _mm_cvttss_si32(_mm_set_ss((mouse[1] - (h * G(float, 0x6785d0) - G(float, 0x67a6ac))) / h));
  float w = per(self, 0xf4);
  s32 col = _mm_cvttss_si32(_mm_set_ss((mouse[0] + G(float, 0x67a6ac)) / w));
  u8 *sys = G(u8 *, 0x70039c);
  if (AT(u8, sys, 0xa10) >= 0x80) {
    if (g_click == 0)
      g_click = 1;
  } else {
    g_click = 0;
  }
  if (AT(u8, sys, 0xa60) >= 0x80) {
    u8 *o = (u8 *)((R0)VT(sys, 0x190))(sys);
    ((C4)VT(o, 0x184))(o, 0, 0x32, 0x6c4400);
    g_multi = 1;
  } else {
    g_multi = 0;
    g_mask = 0;
  }
  u8 *lst = (u8 *)((R0)VT(self + 0x94, 0x18))(self + 0x94);
  if (g_click != 1 || col >= 0x50 || !((R0)VT(self, 0x1a4))(self))
    return r;
  u32 idx = line + 1;
  if (lst) {
    u32 it[3];
    ((P1)VT(lst, 0x4c))(lst, it);
    u8 *e = (u8 *)((R1)VT(lst, 0x64))(lst, (u32)it);
    if (e) {
      while (idx != (u32)row) {
        idx++;
        e = (u8 *)((R1)VT(lst, 0x64))(lst, (u32)it);
        if (!e)
          goto done;
      }
      u8 *c = e + 8;
      if (c) {
        if (AT(u32, c, 0x1d9) != 0) {
          s32 shared = 0;
          u32 it2[3];
          ((P1)VT(lst, 0x4c))(lst, it2);
          u8 *f = (u8 *)((R1)VT(lst, 0x64))(lst, (u32)it2);
          if (f) {
            s32 k = 0;
            do {
              u8 *d = f + 8;
              if (AT(u32, d, 0x1d9) == AT(u32, c, 0x1d9) && c != d) {
                if (!g_multi)
                  AT(u32, d, 0x1d9) = 0;
                else
                  k++;
              }
              f = (u8 *)((R1)VT(lst, 0x64))(lst, (u32)it2);
            } while (f);
            shared = k;
          }
          if (!g_multi || (g_mask = AT(u32, c, 0x1d9), shared == 0))
            AT(u32, self, 0x98) &= ~AT(u32, c, 0x1d9);
          AT(u32, c, 0x1d9) = 0;
        } else {
          s32 m = AT(s32, self, 0x98);
          if (m != 0x3f) {
            u32 bit;
            if (g_multi && g_mask != 0) {
              bit = g_mask;
            } else {
              u32 n = 0;
              while (m & 1) {
                m >>= 1;
                n++;
              }
              bit = 1;
              for (; n; n--)
                bit += bit;
            }
            AT(u32, c, 0x1d9) = bit;
            AT(u32, self, 0x98) |= bit;
            g_mask = bit;
          }
        }
      }
    }
  }
done:
  g_click = 2;
  return idx;
}
PCREG(658950, fn658950);
