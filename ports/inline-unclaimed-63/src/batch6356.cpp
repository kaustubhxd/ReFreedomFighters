// batch6356.cpp - unclaimed-63 batch 56: 0x5dbc30 (target of the Load thunk 0x5dbc20; no GC name), thiscall, no stack arguments, plain ret.
//   SEH-style cookie check (0x633654 at the end) not reproduced: tagged.
//   A = this[+0x44]; A->vtbl[+0x80](&L4c, &L28) (thiscall, two arguments, ret 8). B = A[+8];
//   0x4daf90(B, &L10) (thiscall, one argument, ret 4); 0x4db7c0(B, &L1c) (thiscall, one argument, ret 4);
//   0x4419f0(&L10, &L4c) and 0x441940(&L10, &L28) (fastcall: ECX, EDX; plain ret; other areas' code, stubbed).
//   this[+0x48..+0x50] = L10[0..2]; 0x4de420(this+0x60, &L4c) (fastcall copy of 0x24 bytes, verified mcpy);
//   this[+0x54..+0x5c] = L1c[0..2]; this[+0x88] = 5.0f; this[+0x84] = 0;
//   C = [[0x7003b8] + 0x2c51]; 0x581960(C, this+0x48) (thiscall, one argument, ret 4; other areas' code, stubbed).
#include "ff.h"

extern "C" void THISCALL ext_4daf90(void *self, u32 a);      // thiscall, one argument, ret 4, stubbed
extern "C" void THISCALL ext_4db7c0(void *self, u32 a);      // thiscall, one argument, ret 4, stubbed
extern "C" void FASTCALL ext_4419f0(u32 a, u32 b);            // fastcall, plain ret, stubbed
extern "C" void FASTCALL ext_441940(u32 a, u32 b);            // fastcall, plain ret, stubbed
extern "C" void FASTCALL ext_4de420(u32 dst, u32 src);        // fastcall, the verified 0x24-byte copy (original code)
extern "C" void THISCALL ext_581960(void *self, u32 a);       // thiscall, one argument, ret 4, stubbed

typedef void(THISCALL * two_fn)(void *, u32, u32);

// 0x5dbc30 (Load body).
static void THISCALL unnamed5dbc30(u8 *self) {
  u32 L4c[9];
  u32 L28[9];
  u32 L10[3];
  u32 L1c[3];
  u8 *A = *(u8 **)(self + 0x44);
  ((two_fn)(*(u32 *)(*(u32 *)A + 0x80)))((void *)A, (u32)L4c, (u32)L28);
  u8 *B = *(u8 **)(A + 8);
  ext_4daf90((void *)B, (u32)L10);
  ext_4db7c0((void *)B, (u32)L1c);
  ext_4419f0((u32)L10, (u32)L4c);
  ext_441940((u32)L10, (u32)L28);
  *(u32 *)(self + 0x48) = L10[0];
  *(u32 *)(self + 0x4c) = L10[1];
  *(u32 *)(self + 0x50) = L10[2];
  ext_4de420((u32)(self + 0x60), (u32)L4c);
  *(u32 *)(self + 0x54) = L1c[0];
  *(u32 *)(self + 0x58) = L1c[1];
  *(u32 *)(self + 0x5c) = L1c[2];
  *(u32 *)(self + 0x88) = 0x40a00000u;
  *(u32 *)(self + 0x84) = 0;
  u8 *gobj = (u8 *)G(u32, 0x7003b8);
  u8 *C = *(u8 **)(gobj + 0x2c51);
  ext_581960((void *)C, (u32)(self + 0x48));
}
PCREG(5dbc30, unnamed5dbc30);
