#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_4e8b70(void *self, void *stream, u32 idx);
extern "C" void FASTCALL ext_4df040(void *a, void *b, float *q, float u);

// Reads the idx-th (1-based) packed value of a bit stream: byte 0 holds the signed bit width w, the values follow MSB first from byte 1.
static inline u32 getbits(const u8 *P, u32 idx) {
  int w = (s8)P[0];
  int bp = (int)(idx - 1) * w;
  int byte = bp >> 3;
  int off = bp & 7;
  u32 v = ((u32)P[byte + 1] << 8) | P[byte + 2];
  v = (v << 8) | P[byte + 3];
  v <<= 8;
  int sh = 32 - off - w;
  int x = (int)v >> (sh & 31);
  return (u32)x & ((1u << (w & 31)) - 1);
}

// 0x4e87b0: thiscall(out, t, n, A, B, table) ret 0x18, /GS protected, returns nothing useful. Samples a packed animation track at time t:
// ti = (int)t. i0 = ti ? A[ti] : 0 (bit stream A, a 0 value gives b0 = 0 too), b0 = B[i0]. out[0..3] = table[i0] (4 int16, 8 bytes per entry) / 32512.0f.
// When ti < n - 1 the next key time r = 0x4e8b70(this, B, i0 + 1) must be > ti (else the assert hook [0x7003b0] runs, int3 if null), the next key table[i0 + 1] is
// converted into q[4], u = (t - b0) / (r - b0) and, unless u == 0.0f, 0x4df040(out, out, q, u) blends the sample.
extern "C" void THISCALL fn_4e87b0(u8 *self, float *out, float t, int n, const u8 *A, const u8 *B, const s16 *T) {
  int ti = (int)t;
  u32 i0, b0;
  if (ti == 0) {
    i0 = 0;
    b0 = 0;
  } else {
    i0 = getbits(A, (u32)ti);
    if (i0 == 0)
      b0 = 0;
    else
      b0 = getbits(B, i0);
  }
  float K = G(float, 0x69764c);
  out[0] = (float)T[i0 * 4 + 0] / K;
  out[1] = (float)T[i0 * 4 + 1] / K;
  out[2] = (float)T[i0 * 4 + 2] / K;
  out[3] = (float)T[i0 * 4 + 3] / K;
  if ((int)t < n - 1) {
    u32 r = ext_4e8b70(self, (void *)B, i0 + 1);
    float q[4];
    float K2 = G(float, 0x69764c);
    q[0] = (float)T[(i0 + 1) * 4 + 0] / K2;
    q[1] = (float)T[(i0 + 1) * 4 + 1] / K2;
    q[2] = (float)T[(i0 + 1) * 4 + 2] / K2;
    q[3] = (float)T[(i0 + 1) * 4 + 3] / K2;
    if (!((int)r > (int)t)) {
      typedef void (*Hook)();
      Hook h = G(Hook, 0x7003b0);
      if (!h) __builtin_trap();
      h();
    }
    float u = (t - (float)(int)b0) / (float)(int)(r - b0);
    if (u != G(float, 0x6785d0)) ext_4df040(out, out, q, u);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(4e87b0, fn_4e87b0);
