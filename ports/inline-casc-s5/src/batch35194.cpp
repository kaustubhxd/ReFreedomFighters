// batch35194.cpp - cascade s5 batch 35194 (tier H): 0x4af170 (GUESS test that the straight line between two points is clear and that there is ground below the target).
#include "ff.h"

extern "C" u8 *THISCALL ext_4e1b60(u8 *q);                                    // Q init: [+0x34] = 1.0f, [+0x44] = 0, byte [+0x6c] = 1
extern "C" void FASTCALL ext_43e920(float *out, float *a, float *b);          // out = a - b, ret 4
extern "C" void THISCALL ext_440530(u8 *self);                                // log helper
typedef u64(THISCALL *ts_t)(void *, u32, u32);
typedef void(THISCALL *lg_t)(void *, u32, u32, u32);
typedef u8(THISCALL *tr_t)(void *, u8 *, u32, u32, u32, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// Debug log (only when the floats at [engine+0x9c7] and [engine+0x9c3] are both non-zero): ts = engine slot 0x1c8(0x67a7f8, line) (a 64-bit result in EDX:EAX); engine slot `slot`(lo, hi, 0x690d48).
static void dbgLog(u32 line, u32 slot) {
  u8 *eng = G(u8 *, 0x70039c);
  if (bitsf(rd32u(eng + 0x9c7)) != 0.0f && bitsf(rd32u(eng + 0x9c3)) != 0.0f) {
    u64 ts = (*(ts_t **)eng)[0x1c8 / 4](eng, 0x67a7f8, line);
    u8 *e2 = G(u8 *, 0x70039c);
    (*(lg_t **)e2)[slot / 4](e2, (u32)ts, (u32)(ts >> 32), 0x690d48);
  }
}

// 0x4af170, stdcall(unused, p1, p2) ret 0xc, returns al. Debug log 0x259 via slot 0x178; Q (0x70 bytes, 0x4e1b60); A = {p1.x, p1.y + 1.0 (0x678858), p1.z}; P2 = {p2.x, p2.y + 1.0, p2.z}; Q[0..2] = A; Q[3..5] = P2 - A;
// mgr = [[engine+0x9b]+0xadc] slot 0x2e0(Q, 0, 0x20, -1, 1, 0): hit -> debug log 0x260 via slot 0x17c and returns 0. Otherwise Q[0..2] = P2, Q[3..5] = {0, -2.0f, 0}, Q[0x34 / 4] = 1.0f and the same query: 0x440530(0x690d48); returns the second result.
static u8 STDCALL fn4af170(u32 unused, float *p1, float *p2) {
  dbgLog(0x259, 0x178);
  u8 Qb[0x70];
  u32 *Q = (u32 *)Qb;
  float A[3], P2[3];
  ext_4e1b60(Qb);
  float K = G(float, 0x678858);
  A[0] = p1[0];
  A[1] = p1[1] + K;
  A[2] = p1[2];
  P2[0] = p2[0];
  P2[1] = p2[1] + K;
  P2[2] = p2[2];
  Q[0] = fbits(A[0]);
  Q[1] = fbits(A[1]);
  Q[2] = fbits(A[2]);
  ext_43e920((float *)(Qb + 0xc), P2, A);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(*(u8 **)(eng + 0x9b) + 0xadc);
  u8 hit = (*(tr_t **)mgr)[0x2e0 / 4](mgr, Qb, 0, 0x20, 0xffffffffu, 1, 0);
  if (hit) {
    dbgLog(0x260, 0x17c);
    return 0;
  }
  Q[0] = fbits(P2[0]);
  Q[1] = fbits(P2[1]);
  Q[2] = fbits(P2[2]);
  Q[0x34 / 4] = 0x3f800000;
  Q[3] = 0;
  Q[4] = 0xc0000000;
  Q[5] = 0;
  eng = G(u8 *, 0x70039c);
  mgr = *(u8 **)(*(u8 **)(eng + 0x9b) + 0xadc);
  u8 hit2 = (*(tr_t **)mgr)[0x2e0 / 4](mgr, Qb, 0, 0x20, 0xffffffffu, 1, 0);
  ext_440530((u8 *)0x690d48);
  return hit2 ? 1 : 0;
}
PCREG(4af170, fn4af170);
