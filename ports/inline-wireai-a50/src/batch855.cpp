// batch855.cpp - area 50 (residue-9 candidate): 0x5a29d0 [167 instr, thiscall, one stack arg (the stream), ret 4, returns
// true; no name in the map (GUESS "save of the hero's control fields")]. Save order: the base save (0x47ade0, exe, stood in),
// a float (vt +0x4c), dwords (vt +0x3c, +0x44), words (vt +0x48), a byte (vt +0x60), a 12-byte vector (vt +0x68), then a
// counted list of 16-byte blocks (vt +0x10 for each, count at +0x7ce), a 16-byte block (vt +0x10), bytes, a word, two dwords
// with the engine manager's +0x44 subtracted, the sub-object save (0x59d3f0, stood in), a dword, two bytes, and finally a
// dword from the table lookup (0x589f70, stood in) through vt +0x44.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_47ade0(void *self, void *s);         // base save (stood in by the harness)
extern "C" void THISCALL ext_59d3f0(void *self, void *s);         // sub-object save (stood in by the harness)
extern "C" u32 THISCALL ext_589f70(void *table, u32 arg);          // table lookup (stood in by the harness)

// 0x5a29d0 (name GUESS).
static bool THISCALL Save5a29d0(u8 *self, void *s) {
  ext_47ade0(self, s);
  vcall<void>(s, 0x4c, F32(self, 0x94d));
  vcall<void>(s, 0x3c, U32(self, 0x77f));
  vcall<void>(s, 0x60, (u32)U8(self, 0x783));
  vcall<void>(s, 0x3c, U32(self, 0x784));
  vcall<void>(s, 0x3c, U32(self, 0x792));
  vcall<void>(s, 0x3c, U32(self, 0x796));
  vcall<void>(s, 0x3c, U32(self, 0x78a));
  vcall<void>(s, 0x3c, U32(self, 0x78e));
  vcall<void>(s, 0x44, U32(self, 0x79a));
  vcall<void>(s, 0x48, (u32)U16(self, 0x7a0));
  vcall<void>(s, 0x48, (u32)U16(self, 0x7a2));
  vcall<void>(s, 0x48, (u32)U16(self, 0x7a4));
  vcall<void>(s, 0x68, (u32)(self + 0x8fb));
  vcall<void>(s, 0x3c, U32(self, 0x907));
  vcall<void>(s, 0x44, U32(self, 0x90f));
  vcall<void>(s, 0x44, U32(self, 0x7ce));
  u8 *p = self + 0x7d2;
  u8 *end = self + 0x7d2 + (U32(self, 0x7ce) << 4);
  if (p != end) {
    do {
      vcall<void>(s, 0x10, (u32)p, 0x10u);
      p += 0x10;
    } while (p != end);
  }
  vcall<void>(s, 0x10, (u32)(self + 0x8d2), 0x10u);
  vcall<void>(s, 0x60, (u32)U8(self, 0x920));
  vcall<void>(s, 0x60, (u32)U8(self, 0x929));
  vcall<void>(s, 0x48, (u32)U16(self, 0x788));
  vcall<void>(s, 0x3c, U32(self, 0x7b2) - U32(FP(G(u8 *, 0x70039c), 0x9b), 0x44));
  vcall<void>(s, 0x3c, U32(self, 0x7ae) - U32(FP(G(u8 *, 0x70039c), 0x9b), 0x44));
  ext_59d3f0(FP(self, 0x54), s);
  vcall<void>(s, 0x3c, U32(self, 0x8f2));
  vcall<void>(s, 0x60, (u32)U8(self, 0x8fa));
  vcall<void>(s, 0x60, (u32)U8(self, 0x917));
  u32 tv = ext_589f70(G(u8 *, 0x7003b8), U32(self, 0x921));
  vcall<void>(s, 0x44, tv);
  return true;
}
PCREG(5a29d0, Save5a29d0);
