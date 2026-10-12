// batch6244 - unclaimed-62 claim 37 (gap band 0x561000-0x581000): 0x565a40 [thiscall, one stack argument, ret 4].
// 0x564a40 (thiscall, the argument; GUESS stub by address) is called first. Then the object at this+0xc7e gets a tail jump through its vtable's
// slot 0xbc with the same argument; its eax is returned (the exe's jmp leaves the stack for the target).
#include "ff.h"

extern "C" void THISCALL ext_564a40(void *self, u32 a);   // exe: thiscall, one stack argument

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static u32 THISCALL fn565a40(u8 *self, u32 a) {
  ext_564a40(self, a);
  return vcall<u32>(rdp(self + 0xc7e), 0xbc, a);
}

PCREG(565a40, fn565a40);
