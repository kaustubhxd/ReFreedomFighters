// batch419.cpp - residue 2 row 0x5571e0 (stdcall, one argument obj, ret 4). p = 0x5003d0(dword [obj+4], 1) (exe; GUESS, hooked);
// q = 0x5003d0(dword [obj+4], 0); flag = (dword [p] != 0); r = 0x589c20 with ECX = dword 0x7003b8 and arguments
// (0, dword [q], flag) (exe; GUESS, hooked); then 0x597fc0 with ECX = r (exe; no arguments; GUESS, hooked).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_5003d0(void *self, u32 arg);
extern "C" u32 THISCALL ext_589c20(void *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_597fc0(void *self);

static void STDCALL pairThenCall(u8 *obj) {
  void *ecx0 = (void *)(unsigned long)U32(obj, 0x4);
  u32 p = ext_5003d0(ecx0, 1u);
  u32 q = ext_5003d0(ecx0, 0u);
  u32 flag = (*(u32 *)(unsigned long)p != 0) ? 1u : 0u;
  u32 value = *(u32 *)(unsigned long)q;
  u32 r = ext_589c20((void *)(unsigned long)G(u32, 0x7003b8), 0u, value, flag);
  ext_597fc0((void *)(unsigned long)r);
}
PCREG(5571e0, pairThenCall);
