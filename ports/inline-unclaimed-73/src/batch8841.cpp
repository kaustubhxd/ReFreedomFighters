// batch8841.cpp - residue 6 batch 88 (GUESS names): FUN_0065f1e0, FUN_005335a0, FUN_00433420, FUN_00448be0, FUN_00427120.
#include "ff.h"

extern "C" u32 THISCALL ext_431410(void *self, u32 a1, u32 a2);
extern "C" u32 THISCALL ext_448a30(void *self, u32 a);
extern "C" u32 THISCALL ext_4e1b30(void *self);
extern "C" void ext_iat_676124(u64 *local);

// 0x65f1e0 (GUESS FUN_0065f1e0): stdcall, two arguments. Sets [p+0x24] |= 1, [p+0x40] = f (float).
static void STDCALL guess65f1e0(void *p, float f) {
  *(u32 *)((u8 *)p + 0x24) |= 1;
  *(float *)((u8 *)p + 0x40) = f;
}
PCREG(65f1e0, guess65f1e0);

// 0x5335a0 (GUESS FUN_005335a0): thiscall, one argument. Calls vcall at vtable[0x244] with (a).
// Returns r ? *(u32*)r : 0.
static u32 THISCALL guess5335a0(void *self, u32 a) {
  u32 **vt = (u32 **)self;
  u32 fn_ptr = vt[0][0x244 / 4];

  // Use inline assembly to preserve ECX across the thiscall
  u32 r;
  asm volatile(
    "push %[arg]\n\t"
    "mov %[self], %%ecx\n\t"
    "call *%[fn]\n\t"
    : "=a" (r)
    : [self] "r" (self), [arg] "r" (a), [fn] "r" (fn_ptr)
    : "ecx"
  );

  return r ? *(u32 *)r : 0;
}
PCREG(5335a0, guess5335a0);

// 0x433420 (GUESS FUN_00433420): thiscall, one argument. Sets [this+0xf8] = a.
// Returns 0x431410(0x67a048, a) (thiscall with ecx=this, ret 8).
static u32 THISCALL guess433420(void *self, u32 a) {
  *(u32 *)((u8 *)self + 0xf8) = a;
  return ext_431410(self, 0x67a048, a);
}
PCREG(433420, guess433420);

// 0x448be0 (GUESS FUN_00448be0): thiscall, one argument. Calls 0x448a30(this, a), then 0x4e1b30(a).
// Returns result of 0x4e1b30 (last call sets eax).
static u32 THISCALL guess448be0(void *self, u32 a) {
  ext_448a30(self, a);
  return ext_4e1b30((void *)a);
}
PCREG(448be0, guess448be0);

// 0x427120 (GUESS FUN_00427120): cdecl, no arguments. Calls [0x676124] with &local (8 bytes).
// Returns 64-bit local in eax:edx.
static u64 guess427120() {
  u64 local = 0;
  typedef void (*IATFn)(u64 *);
  IATFn fn = (IATFn)*(u32 *)0x676124;
  if (fn) fn(&local);
  return local;
}
PCREG(427120, guess427120);
