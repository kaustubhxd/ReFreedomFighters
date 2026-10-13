// batch4118.cpp - unclaimed-41 batch 18 (slice 13): 0x5ed510 (name not in the map; GUESS).
#include "ff.h"

extern "C" void THISCALL ext_5ec390(u8 *self, u32 A, u32 X, u32 C, u32 B, u32 I);  // batch 16 (original code)
extern "C" void THISCALL ext_5ec120(u8 *self, u32 a1, u32 a2, u32 a3);             // three stack args; checksum stub (GUESS)
extern "C" u32 THISCALL ext_5ed2b0(u8 *self, u32 a1, u32 a2, u32 a3);              // three stack args, returns eax; stub (GUESS)
extern "C" u32 THISCALL ext_5ecd80(u8 *self, u32 a1, u32 a2);                      // two stack args, returns eax; stub (GUESS)

static double signed_plus18(s32 v) {
  return (double)v + (((u32)v >> 31) ? 4294967296.0 : 0.0);
}

// 0x5ed510 (GUESS name): thiscall, two stack arguments (P = [ebp+8], Q = [ebp+0xc]; ret 8). Returns the eax of 0x5ecd80.
static u32 THISCALL fn5ed510(u8 *self, u8 *P, u32 Q) {
  typedef s32(THISCALL * i0_t)(u8 *);
  u32 vt = *(u32 *)P;
  s32 r0 = ((i0_t)(*(u32 *)vt))(P);
  float fa = (float)r0;
  s32 r4 = ((i0_t)(*(u32 *)(vt + 4)))(P);
  float g = (float)r4;

  s32 M = *(s32 *)(self + 0xe7);
  if (M == 1) {
    *(float *)(self + 0xd7) = (float)*(s32 *)(self + 0xef);
  } else if (M == 2) {
    s32 D = *(s32 *)(self + 0xdf);
    float v = fa - (float)signed_plus18(D);
    v = v - (float)*(s32 *)(self + 0xef);
    *(float *)(self + 0xd7) = v;
  } else if (M == 3) {
    s32 D = *(s32 *)(self + 0xdf);
    float v = fa * G(float, 0x67a6ac);
    u32 h = (u32)D >> 1;
    v = v - (float)(double)(s32)h;
    v = v + (float)*(s32 *)(self + 0xef);
    *(float *)(self + 0xd7) = v;
  }

  s32 N = *(s32 *)(self + 0xeb);
  if (N == 1) {
    *(float *)(self + 0xdb) = (float)*(s32 *)(self + 0xf3);
  } else if (N == 2) {
    s32 E = *(s32 *)(self + 0xe3);
    float v = g - (float)signed_plus18(E);
    v = v - (float)*(s32 *)(self + 0xf3);
    *(float *)(self + 0xdb) = v;
  }

  ext_5ec390(self, 0x18, 8, 8, 8, 0);
  ext_5ec390(self, 0x60, 8, 0x10, 8, 1);
  ext_5ec390(self, 0x20, 8, 8, 8, 2);
  ext_5ec390(self, 0x58, 0, 8, 0x10, 3);
  ext_5ec390(self, 0, 0x10, 0x10, 0x10, 4);
  ext_5ec390(self, 0x70, 0, 8, 0x10, 5);
  ext_5ec390(self, 8, 0, 8, 8, 6);
  ext_5ec390(self, 0x40, 0, 0x10, 8, 7);
  ext_5ec390(self, 0x30, 0, 8, 8, 8);

  s32 D = *(s32 *)(self + 0xdf);
  ext_5ec120(self, (u32)(D - 0x10), 8u, 1u);
  ext_5ec120(self, (u32)(D - 0x10), 8u, 7u);
  s32 E = *(s32 *)(self + 0xe3);
  ext_5ec120(self, 8u, (u32)(E - 0x10), 3u);
  ext_5ec120(self, 8u, (u32)(E - 0x10), 5u);
  D = *(s32 *)(self + 0xdf);
  E = *(s32 *)(self + 0xe3);
  ext_5ec120(self, (u32)(D - 0x10), (u32)(E - 0x10), 4u);

  float db = *(float *)(self + 0xdb);
  float d7 = *(float *)(self + 0xd7);
  ext_5ed2b0(self, (u32)(s32)d7, (u32)(s32)db, 0u);                                  // A
  ext_5ed2b0(self, (u32)(s32)(d7 + 8.0f), (u32)(s32)db, 1u);                         // B
  s32 D2 = *(s32 *)(self + 0xdf);
  float dDf = (float)signed_plus18(D2);
  ext_5ed2b0(self, (u32)(s32)((dDf + d7) - 8.0f), (u32)(s32)db, 2u);                 // C
  ext_5ed2b0(self, (u32)(s32)d7, (u32)(s32)(db + 8.0f), 3u);                       // D
  ext_5ed2b0(self, (u32)(s32)(d7 + 8.0f), (u32)(s32)(db + 8.0f), 4u);             // E
  s32 D3 = *(s32 *)(self + 0xdf);
  float dDf3 = (float)signed_plus18(D3);
  ext_5ed2b0(self, (u32)(s32)((dDf3 + d7) - 8.0f), (u32)(s32)(db + 8.0f), 5u);    // F
  s32 E2 = *(s32 *)(self + 0xe3);
  float dEf = (float)signed_plus18(E2);
  ext_5ed2b0(self, (u32)(s32)d7, (u32)(s32)((dEf + db) - 8.0f), 6u);              // G
  ext_5ed2b0(self, (u32)(s32)(d7 + 8.0f), (u32)(s32)((dEf + db) - 8.0f), 7u);     // H
  ext_5ed2b0(self, (u32)(s32)((dDf3 + d7) - 8.0f), (u32)(s32)((dEf + db) - 8.0f), 8u);  // I
  return ext_5ecd80(self, (u32)P, Q);
}
PCREG(5ed510, fn5ed510);
