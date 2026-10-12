// batch6242 - unclaimed-62 claim 35 (gap band 0x561000-0x581000): two thiscall functions with one stack argument (ret 4).
//   0x56b430  calls 0x57f350 (thiscall, the argument; GUESS stub by address), then r = 0x4e5e60 (thiscall with ecx = the argument, no stack
//             argument, returns eax; GUESS stub by address), then this[0xcee] = r.
//   0x572580  a = the argument; if this[0x44] differs from a: when this[0x44] is non-zero call its vtable slot 0x78 (thiscall, no argument,
//             ecx = this); then this[0x44] = a and this[0x30] = a.
#include "ff.h"

extern "C" void THISCALL ext_57f350(void *self, u32 a);   // exe: thiscall, one stack argument (ret 4)
extern "C" u32 THISCALL ext_4e5e60(void *self);           // exe: thiscall, no stack argument; ecx = the argument (returns eax)

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL fn56b430(u8 *self, u32 a) {
  ext_57f350(self, a);
  u32 r = ext_4e5e60((void *)a);
  wr32u(self + 0xcee, r);
}

static void THISCALL fn572580(u8 *self, u32 a) {
  u32 cur = rd32u(self + 0x44);
  if (a != cur) {
    if (cur != 0) vcall<void>(self, 0x78);
    wr32u(self + 0x44, a);
    wr32u(self + 0x30, a);
  }
}

PCREG(56b430, fn56b430);
PCREG(572580, fn572580);
