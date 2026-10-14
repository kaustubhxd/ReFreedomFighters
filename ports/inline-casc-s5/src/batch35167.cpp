// batch35167.cpp - cascade s5 batch 35167: 0x496fe0 (GUESS release one block of a pool: free its trailing reference, log and hand it back).
#include "ff.h"

extern "C" void THISCALL ext_4ce1c0(void *self, u32 off, u32 n);   // thiscall, ret 8
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *l3_t)(void *, u32, u32, u32);

// 0x496fe0, thiscall(a) ret 4, no return value. this[0x3c]--; sz = a[0x2c]; r = the dword at a + sz - 4; when non-zero: engine object L = [0x70038c] slot 0xd4(r) and that dword is zeroed. off = a - this[0x30]; n = (sz + 15) & ~15;
// 0x4ce1c0(this[0x2c], off, n); when L is set: L slot 0x30(0x68e524, off, n); then (L re-read, dereferenced even when null) L slot 0x50(a, n, 0x20a0ff); this[0x38] -= sz.
static void THISCALL fn496fe0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x3c) -= 1;
  u32 sz = *(u32 *)(a + 0x2c);
  u32 r = *(u32 *)(a + sz - 4);
  if (r) {
    u8 *lg = G(u8 *, 0x70038c);
    (*(v1_t **)lg)[0xd4 / 4](lg, r);
    *(u32 *)(a + sz - 4) = 0;
  }
  sz = *(u32 *)(a + 0x2c);
  u32 off = (u32)a - *(u32 *)(self + 0x30);
  u32 n = (sz + 0xf) & 0xfffffff0u;
  ext_4ce1c0(*(void **)(self + 0x2c), off, n);
  u8 *lg = G(u8 *, 0x70038c);
  if (lg) (*(l3_t **)lg)[0x30 / 4](lg, 0x68e524, off, n);
  lg = G(u8 *, 0x70038c);
  (*(l3_t **)lg)[0x50 / 4](lg, (u32)a, n, 0x20a0ff);
  *(u32 *)(self + 0x38) -= sz;
}
PCREG(496fe0, fn496fe0);
