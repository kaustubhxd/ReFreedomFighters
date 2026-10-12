// batch6206.cpp - unclaimed-62 claim 3 (slice-1 leaves): three small functions. Names unknown (not in the name map).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5330(u8 *obj);   // exe: tail-call target of 0x462bd0 (no arguments)

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x5a8350: the dword at +0x300.
static u32 THISCALL leaf5a8350(const u8 *self) { return rd32u(self + 0x300); }
PCREG(5a8350, leaf5a8350);

// 0x5ab050: if the dword at +0x300 is not 0x10000000, the dword at +0x8b3 is incremented.
static void THISCALL leaf5ab050(u8 *self) {
  if (rd32u(self + 0x300) != 0x10000000u) wr32u(self + 0x8b3, rd32u(self + 0x8b3) + 1);
}
PCREG(5ab050, leaf5ab050);

// 0x462bd0: the object at +0x5c; null gives the constant 0x677b5a (eax); otherwise the exe tail-jumps to 0x4e5330 with that object.
static u32 THISCALL leaf462bd0(u8 *self) {
  u8 *o = (u8 *)rd32u(self + 0x5c);
  if (!o) return 0x677b5au;
  return ext_4e5330(o);
}
PCREG(462bd0, leaf462bd0);
