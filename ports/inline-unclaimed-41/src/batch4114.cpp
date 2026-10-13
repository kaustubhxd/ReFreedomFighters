// batch4114.cpp - unclaimed-41 batch 14 (slice 13): 0x4e89d0 (name not in the map; GUESS).
#include "ff.h"

// 0x4e8b70, a pure bit reader (stdcall: arg1 = data, arg2 = index; ret 8). Original code run as is.
extern "C" u32 STDCALL ext_4e8b70(u8 *data, u32 idx);

// 0x4e89d0 (GUESS name): stdcall, six arguments (ret 0x18). Packed table lookup with interpolation:
//   n = (s32)x; if n != 0: w = (s8)data[0]; read w bits at bit (n-1)*w of data -> idx;
//     if idx != 0: w2 = (s8)data2[0]; read w2 bits at bit (idx-1)*w2 of data2 -> val2 (else val2 = 0; idx = 0 when the first read is 0).
//   out = table[3*idx .. 3*idx+2];
//   if n < limit-1: v3 = ext_4e8b70(data2, idx+1); if v3 > n, skip the hook, else call the hook (0x7003b0, no arguments);
//     d = v3 - val2; t = (x - (float)val2) / (float)d; if t != 0.0: out[k] += (table[3*idx+3+k] - out[k]) * t for k = 0..2.
// The reads use the PC's shifts (sar with cl masked to 5 bits; the byte window is 4 bytes at (bit >> 3) + 1 .. +3).
static u32 readBits(u8 *base, s32 bitpos, s32 w) {
  s32 byte = bitpos >> 3;
  s32 off = bitpos & 7;
  u32 v = ((u32)base[byte + 1] << 16) | ((u32)base[byte + 2] << 8) | (u32)base[byte + 3];
  u32 raw = v << 8;
  s32 sh = 32 - off - w;
  s32 val = (s32)raw >> (sh & 31);
  u32 mask = (1u << (w & 31)) - 1u;
  return (u32)val & mask;
}

static void STDCALL fn4e89d0(float *out, float x, s32 limit, u8 *data, u8 *data2, float *table) {
  s32 n = (s32)x;
  u32 idx = 0;
  u32 val2 = 0;
  if (n != 0) {
    s32 w = (s8)data[0];
    idx = readBits(data, (n - 1) * w, w);
    if (idx != 0) {
      s32 w2 = (s8)data2[0];
      val2 = readBits(data2, ((s32)idx - 1) * w2, w2);
    }
  }
  for (u32 k = 0; k < 3; k++)
    out[k] = table[3 * idx + k];
  if (n >= limit - 1)
    return;
  u32 v3 = ext_4e8b70(data2, idx + 1);
  if ((s32)v3 <= n) {
    void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
    hook();
  }
  u32 d = v3 - val2;
  float t = (x - (float)(s32)val2) / (float)(s32)d;
  if (!(t == 0.0f)) {
    for (u32 k = 0; k < 3; k++) {
      float next = table[3 * idx + 3 + k];
      out[k] = (next - out[k]) * t + out[k];
    }
  }
}
PCREG(4e89d0, fn4e89d0);
