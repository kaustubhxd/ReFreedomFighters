// batch32141.cpp - cascade h2 (Sonnet): two tier H functions (SSE int-to-float / x87 float accumulate).
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
typedef u32 (*hook_t)();
typedef u32 (*cd3_t)(u32, u32, u32);

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);          // thiscall ret 4
extern "C" u32 THISCALL ext_43eb80(u8 *self, u32 a);          // thiscall ret 4
extern "C" s32 ext_405f20(u8 *a, u32 b);                      // cdecl, returns an index (-1 = none)

// 0x511200, stdcall(arg) ret 4: x = 0x5003d0([arg+4], 0); id = 0x43eb80([[[0x70039c]+0x9b]+0xadc], [x]); s = slot 0x60 of [[0x70039c]+0x9b] with id;
// s != 0: y = 0x5003d0([arg+4], 1); [s+0x40] |= 0x80; [s+8] = 5; [s+0x2c] = 1; float [s+0x88] = (float)(int)[y].
// z = 0x5003d0([arg+8], 0): byte [z+4] <= 1 (unsigned) -> [z] = id; byte [z+4] = 1; return. Otherwise log through [0x700390] (slot 0x20 with (0x69c8e0, 0xc4), then cdecl slot 0x2c with (o, 0x69c6b0, 0x69c938))
// and call the assert hook [0x7003b0] (int3 when null); return.
static void STDCALL fn511200(u8 *arg) {
  u32 *x = (u32 *)ext_5003d0(*(u8 **)(arg + 4), 0);
  u32 first = *x;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *t = *(u8 **)(eng + 0x9b);
  u32 id = ext_43eb80(*(u8 **)(t + 0xadc), first);
  u8 *eng2 = G(u8 *, 0x70039c);
  u8 *s = vcall<u8 *>(*(void **)(eng2 + 0x9b), 0x60, id);
  if (s) {
    u32 *y = (u32 *)ext_5003d0(*(u8 **)(arg + 4), 1);
    float v = (float)(s32)*y;
    *(u32 *)(s + 0x40) |= 0x80;
    *(u32 *)(s + 8) = 5;
    *(u32 *)(s + 0x2c) = 1;
    *(float *)(s + 0x88) = v;
  }
  u8 *z = (u8 *)ext_5003d0(*(u8 **)(arg + 8), 0);
  if (z[4] <= 1) {
    *(u32 *)z = id;
    z[4] = 1;
    return;
  }
  void *g = G(void *, 0x700390);
  u8 *o = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0xc4u);
  (*(cd3_t *)(*(u8 **)o + 0x2c))((u32)o, 0x69c6b0, 0x69c938);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(511200, fn511200);

// 0x406250, cdecl(a0, a1, a2, a3, a4, a5), returns 0 or -1: i = a2 / a3 (signed), lim = (a5 + a2) / a3; i >= lim -> 0. esi = 0 (kept across passes). Pass: r = 0x405f20(a0, a4) (cdecl); r == -1 -> return -1;
// n = [a0]; row = [a0+0xc] + 4*n*r; for k in 0 .. n (while k < [a0], at least one pass when n > 0): esi++; float *q = &a1[esi-1][i]; *q = (float)((double)*q + (double)*row) (x87 53-bit); row++; if esi == a3: esi = 0, i++.
// Repeat passes while i < lim.
static s32 fn406250(u8 *a0, float **a1, s32 a2, s32 a3, u32 a4, s32 a5) {
  s32 i = a2 / a3;
  s32 lim = (a5 + a2) / a3;
  s32 esi = 0;
  if (i >= lim) return 0;
  do {
    s32 r = ext_405f20(a0, a4);
    if (r == -1) return -1;
    s32 n = (s32)rd32(a0);
    float *row = (float *)(*(u8 **)(a0 + 0xc) + 4 * (n * r));
    s32 k = 0;
    if (n > 0) {
      do {
        esi++;
        float *p = a1[esi - 1];
        float *q = p + i;
        *q = (float)((double)*q + (double)*row);
        if (esi == a3) {
          esi = 0;
          i++;
        }
        k++;
        row++;
      } while (k < (s32)rd32(a0));
    }
  } while (i < lim);
  return 0;
}
PCREG(406250, fn406250);
