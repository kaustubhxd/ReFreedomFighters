// batch32128.cpp - cascade h2 (): two tier H functions.
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(void *a, void *b);        // distance between two vectors (real exe code, float in st0)
extern "C" void FASTCALL ext_633654(u32 cookie);               // /GS check

static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x52d1c0, stdcall(A, N, ACC, P, Q, ign1, ign2, val) ret 0x20: [N] != 0 -> ACC[0] = (float)(distance(P, Q) + ACC[0]) (x87, 0x4e0870); P[0..2] = Q[0..2]; n = [N];
// [[A+0xc] + n*16] = ACC[0]; [[A+0x10] + n*4] = 0; [[A+0x14] + n*4] = val; [[A+0xc] + n*16 + 4..0xc] = Q[0..2]; [N] = n + 1.
static void STDCALL fn52d1c0(u8 *A, u32 *N, float *ACC, float *P, float *Q, u32, u32, u32 val) {
  if (*N != 0) {
    float d = ext_4e0870(P, Q);
    ACC[0] = (float)((double)d + (double)ACC[0]);
  }
  P[0] = Q[0]; P[1] = Q[1]; P[2] = Q[2];
  u32 n = *N;
  u32 *arr = *(u32 **)(A + 0xc);
  *(float *)((u8 *)arr + n * 16) = ACC[0];
  (*(u32 **)(A + 0x10))[n] = 0;
  (*(u32 **)(A + 0x14))[n] = val;
  u8 *base = *(u8 **)(A + 0xc);
  *(float *)(base + n * 16 + 4) = Q[0];
  *(float *)(base + n * 16 + 8) = Q[1];
  *(float *)(base + n * 16 + 0xc) = Q[2];
  *N = *N + 1;
}
PCREG(52d1c0, fn52d1c0);

// 0x5b9780, thiscall no args (/GS frame): r = slot 0x84 of this with ([[this+0x50]+0x18], [this+0x58]); [this+0x58] = r; r != 0 -> o = engine table slot 0x58 with r; v = {0, 0, 0}; slot 0x84 of o with &v;
// local = {0x6b281c, v[0], v[1], v[2]}; slot 0x128 of [this+0x44] with (word [this+0x60], &local, 0); /GS check.
static void THISCALL fn5b9780(u8 *self) {
  u32 local[4];
  float v[3];
  u32 r = vcall<u32>(self, 0x84, *(u32 *)(*(u8 **)(self + 0x50) + 0x18), *(u32 *)(self + 0x58));
  *(u32 *)(self + 0x58) = r;
  if (r) {
    void *o = vcall<void *>(engTable(), 0x58, r);
    v[0] = 0; v[1] = 0; v[2] = 0;
    vcall<void>(o, 0x84, (u32)v);
    local[0] = 0x6b281c;
    __builtin_memcpy(&local[1], &v[0], 4);
    __builtin_memcpy(&local[2], &v[1], 4);
    __builtin_memcpy(&local[3], &v[2], 4);
    vcall<void>(*(void **)(self + 0x44), 0x128, (u32)*(u16 *)(self + 0x60), (u32)local, 0u);
  }
  ext_633654(0);
}
PCREG(5b9780, fn5b9780);
