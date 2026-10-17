// batch427.cpp - residue 2 row 0x5f9260 (thiscall, no arguments; stack canary and vtable slot call with assert hook).
// Canary: xor [ebp-4] with [0x6f5630]. Call 0x5fa630 (GUESS, hooked by address, returns a pointer).
// Extract pointer: ecx = dword [eax]. Call slot 0x14 of that pointer as a thiscall with arguments:
// ([this+0xac6], [this+0x82], 0x6b8e80, local buffer at ebp-0x68, the pointer).
// Then check the assert hook at 0x7003b0; if non-null, call it with ECX = this.
// Validate canary, call 0x633654 (exe stack check, hooked by address, GUESS).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *THISCALL ext_5fa630(void *self);          // exe callee by address (hooked in the spec)
extern "C" void ext_633654(void);                          // exe stack check (hooked in the spec)

static void THISCALL stackCheckWithHook(u8 *self) {
  u8 buf[0x68];
  void *ptr = ext_5fa630(self);
  u32 vtable = U32((u8 *)ptr, 0);  // dereference ptr to get vtable
  u32 arg1 = U32(self, 0xac6);
  u32 arg2 = U32(self, 0x82);
  typedef void (*SlotFn)(void);
  SlotFn slot = (SlotFn)(unsigned long)U32((u8 *)(unsigned long)vtable, 0x14);
  asm volatile(
    "push %[a1]\n"
    "push %[a2]\n"
    "push %[a3]\n"
    "push %[a4]\n"
    "push %[a5]\n"
    "call *%[fn]\n"
    : : [a1]"r"(arg1), [a2]"r"(arg2), [a3]"r"(0x6b8e80u),
        [a4]"r"((u32)buf), [a5]"r"((u32)ptr), [fn]"r"(slot), "c"(vtable));
  u32 hook = G(u32, 0x7003b0);
  if (hook) {
    typedef void (*HookFn)(void);
    HookFn hfn = (HookFn)(unsigned long)hook;
    asm("call *%0" : : "r"(hfn), "c"(vtable));
    ext_633654();
  }
}
PCREG(5f9260, stackCheckWithHook);
