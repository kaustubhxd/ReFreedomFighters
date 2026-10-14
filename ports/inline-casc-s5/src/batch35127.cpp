// batch35127.cpp - cascade s5 batch 35127: 0x551bd0 (GUESS look up an object by key and store five values into its record slots).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4, returns a slot record
extern "C" void THISCALL ext_5002f0(u32 self, u32 a);  // thiscall, ret 4
typedef u32(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *g0_t)(void *);

// 0x551bd0, stdcall(A, k, arr) ret 0xc, returns the object or 0. o = A slot 0x18(k); null gives 0. e = o slot 0x4c(); for i = 0..4: 0x5002f0(0x5003d0(e, i), arr[i]) (arr[i] is read before the lookup). Returns o.
static u32 STDCALL fn551bd0(u8 *A, u32 k, u32 *arr) {
  u8 *o = (u8 *)(*(g1_t **)A)[0x18 / 4](A, k);
  if (!o) return 0;
  u32 e = (*(g0_t **)o)[0x4c / 4](o);
  for (u32 i = 0; i < 5; i++) {
    u32 v = arr[i];
    u32 r = ext_5003d0(e, i);
    ext_5002f0(r, v);
  }
  return (u32)o;
}
PCREG(551bd0, fn551bd0);
