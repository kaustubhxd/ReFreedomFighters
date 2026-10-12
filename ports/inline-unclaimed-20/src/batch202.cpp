// batch202.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Small bodies: a flag
// clear, a linked-list search, a wrapper that calls the original 0x59d450 (not a port), and a vtable tail call.
#include "ff.h"

extern "C" void THISCALL ext_59d450(u8 *self);   // original code, not ported in this claim (the harness binds it to the exe)

// 0x43abb0, stdcall(p): if p, clear the dword at p+0x29, then p[0x2e] &= 0x2f and p[0x2f] &= 1. Name GUESS. The asm
// also skips the dword write when p+0x29 equals a stack slot (&local); a heap or object pointer never does that, so the
// port writes unconditionally.
static void STDCALL clearFlags_43abb0(u8 *p) {
  if (p) {
    *(u32 *)(p + 0x29) = 0;
    p[0x2e] &= 0x2f;
    p[0x2f] &= 1;
  }
}
PCREG(43abb0, clearFlags_43abb0);

// 0x45f370, thiscall(key): walk the list at [this+0xc] (next at +0xc); if the dword at node+0x23 equals key, return
// eax = (node & ~0xff) | 1 (the asm sets al = 1 and leaves the upper bits of the pointer); else return 0. Name GUESS.
static u32 THISCALL findNodeKey_45f370(u8 *self, u32 key) {
  u8 *node = *(u8 **)(self + 0xc);
  while (node) {
    if (*(u32 *)(node + 0x23) == key) return ((u32)node & ~0xffu) | 1u;
    node = *(u8 **)(node + 0xc);
  }
  return 0;
}
PCREG(45f370, findNodeKey_45f370);

// 0x59d430, thiscall(mode): [this+4] = mode, then call the original setModeFlags 0x59d450 on this. Name GUESS.
static void THISCALL setModeAndRun_59d430(u8 *self, u32 mode) {
  *(u32 *)(self + 4) = mode;
  ext_59d450(self);
}
PCREG(59d430, setModeAndRun_59d430);

// 0x5abcb0, thiscall: set [this+0x83] = 1; if [this+0x6a] is non-null, tail-call its vtable slot 2 (+8) with that
// object as this and no arguments. The asm is a jmp; a call followed by ret has the same effect for a 0-argument slot.
// Name GUESS.
typedef void(THISCALL *SlotFn)(u8 *);
static void THISCALL flagAndNotify_5abcb0(u8 *self) {
  self[0x83] = 1;
  u8 *obj = *(u8 **)(self + 0x6a);
  if (obj) {
    SlotFn fn = (SlotFn)(*(u32 *)(*(u32 *)obj + 8));
    fn(obj);
  }
}
PCREG(5abcb0, flagAndNotify_5abcb0);
