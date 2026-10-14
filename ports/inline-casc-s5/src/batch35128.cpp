// batch35128.cpp - cascade s5 batch 35128: 0x500760 (GUESS look up an object, create a named child through the owner and store it in the object's tagged slot).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4: slot record {value dword, kind byte at +4}
typedef u32(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *g0_t)(void *);
typedef u8 *(THISCALL *c2_t)(void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);

// 0x500760, stdcall(A, k, name) ret 0xc, returns the object or 0. o = A slot 0x18(k); null gives 0. h = o slot 0x4c(); X = A slot 0(0x67a14c, 0); X slot 0x30(name); t = 0x5003d0(h, 0): kind 4 first calls (value) slot 0x28(), kinds 0 and 4 set
// value = X slot 0x24() and kind = 4, other kinds are left alone; finally X slot 0x28(). Returns o.
static u32 STDCALL fn500760(u8 *A, u32 k, u32 name) {
  u8 *o = (u8 *)(*(g1_t **)A)[0x18 / 4](A, k);
  if (!o) return 0;
  u32 h = (*(g0_t **)o)[0x4c / 4](o);
  u8 *X = (*(c2_t **)A)[0](A, 0x67a14c, 0);
  (*(v1_t **)X)[0x30 / 4](X, name);
  u32 *t = ext_5003d0(h, 0);
  u8 kind = ((u8 *)t)[4];
  if (kind == 0 || kind == 4) {
    if (kind == 4) {
      u8 *ov = (u8 *)t[0];
      (*(v0_t **)ov)[0x28 / 4](ov);
    }
    t[0] = (*(g0_t **)X)[0x24 / 4](X);
    ((u8 *)t)[4] = 4;
  }
  (*(v0_t **)X)[0x28 / 4](X);
  return (u32)o;
}
PCREG(500760, fn500760);
