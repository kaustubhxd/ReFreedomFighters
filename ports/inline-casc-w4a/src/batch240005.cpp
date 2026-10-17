// batch240005.cpp - Sonnet-w4a: CRT helpers (encoded-pointer call, startup lock).
#include "ff.h"

extern "C" u32 THISCALL ext_634aae(u32 self, u32 arg);   // import thunk (ecx = this, 1 stack arg, callee pops)
extern "C" u32 ext_634cb5();

// 0x6345bc: no args: if [0x7257f4] == 0: decode the pointer f = ror([cookie] ^ [0x7257fc], cookie & 31), call thunk
// 634aae with ecx = f and arg 0x7257f0, then return f(); else import1(v) then return import2([0x7257f4]) (v = the same value)
static u32 fn_6345bc() {
  u32 v = G(u32, 0x7257f4);
  if (v == 0) {
    u32 c = G(u32, 0x6f5630);
    u32 x = c ^ G(u32, 0x7257fc);
    u32 n = c & 0x1f;
    u32 f = n ? (x >> n) | (x << (32 - n)) : x;
    ext_634aae(f, 0x7257f0);
    return ((u32(*)())f)();
  }
  (*(u32(__stdcall **)(u32))0x67613c)(v);
  return (*(u32(__stdcall **)(u32))0x676140)(G(u32, 0x7257f4));
}
PCREG(6345bc, fn_6345bc);

// 0x633d00: no args: lock acquire keyed by the thread stack base (fs:[0x18]->+4) in [0x725494]; 0 when the helper
// 634cb5 says no or the lock was free (taken now), 1 in al (upper bytes = owner) when this thread already owns it
static u32 fn_633d00() {
  if (!ext_634cb5()) return 0;
  u32 teb;
  asm volatile("movl %%fs:0x18, %0" : "=r"(teb));
  u32 owner = *(u32 *)(teb + 4);
  for (;;) {
    u32 old = __sync_val_compare_and_swap((u32 *)0x725494, 0u, owner);
    if (old == 0) return 0;
    if (old == owner) return (owner & ~0xffu) | 1;
  }
}
PCREG(633d00, fn_633d00);
