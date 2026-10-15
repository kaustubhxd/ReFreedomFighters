// batch32129.cpp - cascade h2 (Sonnet): two tier H functions.
#include "ff.h"

extern "C" void FASTCALL ext_4e0980(void *a, void *b);        // vector helper (ecx, edx), exe code
extern "C" void FASTCALL ext_441940(void *a, void *b);        // vector helper (ecx, edx), exe code

// 0x457760, thiscall(out) ret 4: three calls of engine slot 0x1bc with (0x683734, 0x43a) give integers a, b, c; z = (float)a / K(0x683774) - 1.0, y = (float)b / K - 1.0, x = (float)c / K - 1.0;
// out = {x, y, z}; 0x4e0980(out, this+0x44); 0x441940(out, this+0x50).
static void THISCALL fn457760(u8 *self, float *out) {
  void *eng = G(void *, 0x70039c);
  s32 a = vcall<s32>(eng, 0x1bc, 0x683734u, 0x43au);
  float z = (float)a / G(float, 0x683774);
  z = z - G(float, 0x678858);
  eng = G(void *, 0x70039c);
  s32 b = vcall<s32>(eng, 0x1bc, 0x683734u, 0x43au);
  float y = (float)b / G(float, 0x683774);
  y = y - G(float, 0x678858);
  eng = G(void *, 0x70039c);
  s32 c = vcall<s32>(eng, 0x1bc, 0x683734u, 0x43au);
  float x = (float)c / G(float, 0x683774);
  x = x - G(float, 0x678858);
  out[0] = x;
  out[1] = y;
  out[2] = z;
  ext_4e0980(out, self + 0x44);
  ext_441940(out, self + 0x50);
}
PCREG(457760, fn457760);

// 0x4e3230, register ABI (ecx = base, edx = n) with a stack argument i, ret 4: a min-heap sift-down over 9-byte records whose first dword is a float key: l = 2i+1, m = 2i;
// best = (l <= n and key[i] > key[l]) ? l : i; then (m <= n and key[best] > key[m]) -> best = m; best == i -> done; otherwise the two records are swapped and i = best, repeat.
static void FASTCALL fn4e3230(u8 *base, s32 n, s32 i) {
  while (true) {
    s32 l = i * 2 + 1;
    s32 m = i + i;
    s32 best;
    if (l <= n && *(float *)(base + i * 9) > *(float *)(base + l * 9)) best = l;
    else best = i;
    if (m <= n && *(float *)(base + best * 9) > *(float *)(base + m * 9)) best = m;
    if (best == i) return;
    u8 *pa = base + i * 9;
    u8 *pb = base + best * 9;
    u8 ta[9], tb[9];
    for (int k = 0; k < 9; k++) { ta[k] = pa[k]; tb[k] = pb[k]; }
    for (int k = 0; k < 8; k++) pa[k] = tb[k];
    pa[8] = tb[8];
    for (int k = 0; k < 8; k++) pb[k] = ta[k];
    pb[8] = ta[8];
    i = best;
  }
}
PCREG(4e3230, fn4e3230);
