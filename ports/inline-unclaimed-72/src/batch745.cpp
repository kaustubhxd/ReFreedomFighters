// batch745.cpp - ZActionPushButton::Execute() (0x486700) [high], area 72 slice 0 (2026-10-12). Logs "CODE NOT TESTED - TALK TO HS"
// (zlnkwhandsactions.cpp line 0x1d8). Then: A = +8 slot 0x80 (out40, out10); B = +0xc slot 0x384 (out64, out1c); PSVECSubtract
// (ecx = out70, edx = out10, stack = out1c); vmtmul (ecx = out70, edx = out64); B slot 0x8c (out10); D = +0x10 slot 0x1c with
// (B, 0, &out10, 0.8f, a 16-byte object {0x465708, 0, 0, 0} passed by value). Then the four-way choice of (x, y) by |z| vs |x|
// and by sign / size (floats 119, 90, 59, 30, 29, 0, 89, 60): B slot 0x228 with (+0x14, 1, x, y, 1.0f). Returns true.
// The SEH-free cookie check is not reproduced. The exe's own PSVECSubtract and vmtmul run as exe code.
#include "ff.h"


// bottom-up helpers (ported and checked in batch758): PSVECSubtract and vmtmul, used here instead of the exe calls.
static void FASTCALL psvec_sub(float *out, const float *a, const float *b) {
  for (int i = 0; i < 3; i++)
    out[i] = (float)((long double)a[i] - (long double)b[i]);
}
static void FASTCALL vmtmul_port(float *out, const float *m) {
  long double c0 = out[0], c1 = out[1], c2 = out[2];
  long double r0 = c0 * m[6];
  r0 += c1 * m[7];
  r0 += c2 * m[8];
  long double r1 = c0 * m[3];
  r1 += c1 * m[4];
  r1 += c2 * m[5];
  long double r2 = c0 * m[0];
  r2 += c1 * m[1];
  r2 += c2 * m[2];
  out[0] = (float)r0;
  out[1] = (float)r1;
  out[2] = (float)r2;
}

static void logLine(u32 line, const char *msg) {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x68cdc4, line);
  typedef void(__attribute__((cdecl)) * pf_t)(void *, const char *);
  (*(pf_t *)(*(u8 **)log + 0x2c))(log, msg);
}

static inline float absf(float v) { return v < 0.0f ? -v : v; }


// 0x486700 ZActionPushButton::Execute() [high].
static bool THISCALL pushButton_Execute(u8 *self) {
  logLine(0x1d8, (const char *)0x68ce30);   // "CODE NOT TESTED - TALK TO HS"

  float out40[8];
  float out10[3];
  float out64[3];
  float out1c[3];
  float out70[3];
  vcall<void>(*(void **)(self + 8), 0x80, out40, out10);
  vcall<void>(*(void **)(self + 0xc), 0x384, out64, out1c);
  psvec_sub(out70, out10, out1c);
  vmtmul_port(out70, out64);
  vcall<void>(*(void **)(self + 0xc), 0x8c, out10);

  u32 obj8[4] = {0x465708u, 0u, 0u, 0u};   // the 16-byte object passed by value
  void *B = *(void **)(self + 0xc);
  vcall<void>(*(void **)(self + 0x10), 0x1c, B, 0u, out10, 0x3f4ccccdu, obj8[0], obj8[1], obj8[2], obj8[3]);

  float x = out70[0];
  float z = out70[2];
  float xv, yv;
  if (!(absf(z) > absf(x))) {                  // branch B: |z| <= |x|
    if (!(0.0f > x)) {
      xv = bitsf(0x42700000u); yv = bitsf(0x42b20000u);   // 60, 89
    } else {
      xv = 0.0f; yv = bitsf(0x41e80000u);                 // 0, 29
    }
  } else {                                     // branch A: |z| > |x|
    if (!(absf(out40[4]) > absf(out40[1]))) {
      xv = bitsf(0x41f00000u); yv = bitsf(0x426c0000u);   // 30, 59
    } else {
      xv = bitsf(0x42b40000u); yv = bitsf(0x42ee0000u);   // 90, 119
    }
  }
  vcall<void>(*(void **)(self + 0xc), 0x228, *(u32 *)(self + 0x14), 1u, fbits(xv), fbits(yv), 0x3f800000u);
  return true;
}
PCREG(486700, pushButton_Execute);
