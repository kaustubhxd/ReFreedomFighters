// batch913.cpp - residue-9 slice: two bodies read in full.
//  0x62de90 [cdecl: object pointer, code; no pop; returns a dword]: code 0x0f -> 0; code 0x1b -> *obj = 0x62df30, returns 0x12;
//           code 0x1c with obj[3] == 0 -> 0x34; otherwise *obj = 0x51f230 and returns -1.
//  0x610110 [stdcall, one byte arg (a flag; ret 4)]: flag nonzero: if the word at 0x724968 is not 4, set it to 4 and call the
//           object P = [0x724a00] through its vtable slot +0xc8 (ECX = the vtable, args: P, 0x17, 4; callee pops 12).
//           flag zero: the same with 8 in place of 4 (only if the word is not 8).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x62de90 (no name in the map).
s32 Fn62de90(u32 *obj, u32 code) {
  if (code == 0x0fu) return 0;
  if (code == 0x1bu) {
    obj[0] = 0x62df30u;
    return 0x12;
  }
  if (obj[3] == 0 && code == 0x1cu) return 0x34;
  obj[0] = 0x51f230u;
  return -1;
}
PCREG(62de90, Fn62de90);

// call the slot +0xc8 of object P with ECX = its vtable and args (P, 0x17, n); the callee pops its arguments.
static void Call610110(u32 n) {
  u8 *P = (u8 *)G(u32, 0x724a00);
  u8 *vt = *(u8 **)P;
  void *fn = *(void **)(vt + 0xc8);
  typedef void(THISCALL * fn_t)(void *, void *, u32, u32);
  ((fn_t)fn)((void *)vt, (void *)P, 0x17u, n);
}

// 0x610110 (no name in the map).
static void STDCALL Flag610110(u8 flag) {
  if (flag != 0) {
    if (G(u32, 0x724968) != 4) {
      G(u32, 0x724968) = 4;
      Call610110(4u);
    }
  } else {
    if (G(u32, 0x724968) != 8) {
      G(u32, 0x724968) = 8;
      Call610110(8u);
    }
  }
}
PCREG(610110, Flag610110);
