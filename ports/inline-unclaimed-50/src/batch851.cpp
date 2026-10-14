// batch851.cpp - area 50 (residue-9 candidate, largest free row): ZFFHERO::Load(ZLoadGame*) [0x592d50, 427 instr,
// thiscall, callee pops 4, returns bool true]. The base load (0x483f20) runs first. Then the hero's fields come from the
// load object's slots, in the exe's order: 0x68 bytes, 0x48 dwords, 0x40 dwords (some resolved through the global manager's
// slot 0x58 into +0x658, +0x68c, +0x84e, +0xeee, +0xecb), 0x58 pointer dwords, 0x50 floats, 0x6c 12-byte blocks, 0x74 blocks
// (the matrices). A slot returns the object it was called on (the exe chains on that return value at +0x7fb and +0x669).
// 0x4cc1d0 (object at +0x698) and the sub-loads 0x58a8d0, 0x58a9b0 (stream in ECX, pointer in EDX) and 0x59d3a0 (this =
// the object at +0x54) are stood in by the harness. The last part stores this into the global table at 0x7003b8 indexed by
// the dword at +0x684, and points +0x64f at the table record chosen by a 0x48 read (record size 0xf4, base offset 0xd91).
// The exe keeps the table pointer in [0x7003b8]; the port writes the same words.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_483f20(void *self, void *s);        // base class load (stood in by the harness)
extern "C" void *THISCALL ext_4cc1d0(void *self);                // object owned by +0x698 (stood in)
extern "C" void FASTCALL ext_58a8d0(void *s, void *p);            // sub-load: ECX stream, EDX pointer (stood in)
extern "C" void FASTCALL ext_58a9b0(void *s, void *p);            // sub-load: ECX stream, EDX pointer (stood in)
extern "C" void THISCALL ext_59d3a0(void *self, void *s);        // sub-object load (stood in)

// the engine's global manager lookup (vt +0x58 of [[0x70039c]+0x9b])
static u32 MgrLookup(u32 key) {
  return vcall<u32>(FP(G(u8 *, 0x70039c), 0x9b), 0x58, key);
}

// 0x592d50 ZFFHERO::Load(ZLoadGame*).
static bool THISCALL ZFFHERO_Load(u8 *self, void *s) {
  ext_483f20(self, s);
  vcall<void *>(s, 0x68, self + 0x653);
  vcall<void *>(s, 0x48, self + 0x64b);
  u32 t8, t12;
  vcall<void *>(s, 0x40, &t8);
  U32(self, 0x654) = t8;
  vcall<void *>(s, 0x40, &t12);
  U32(self, 0x658) = MgrLookup(t12);
  vcall<void *>(s, 0x68, self + 0x65c);
  vcall<void *>(s, 0x40, &t8);
  U32(self, 0x67b) = t8;
  vcall<void *>(s, 0x48, self + 0x680);
  vcall<void *>(s, 0x40, &t12);
  U32(self, 0x68c) = MgrLookup(t12);
  vcall<void *>(s, 0x58, self + 0x690);
  vcall<void *>(s, 0x58, self + 0x694);
  void *obj = ext_4cc1d0(self + 0x698);
  vcall<void *>(s, 0x64, obj);
  vcall<void *>(s, 0x50, self + 0x7ec);
  vcall<void *>(s, 0x68, self + 0x7f0);
  vcall<void *>(s, 0x68, self + 0x7f1);
  vcall<void *>(s, 0x68, self + 0x7f2);
  vcall<void *>(s, 0x48, self + 0x7f3);
  vcall<void *>(s, 0x48, self + 0x7f7);
  void *x = vcall<void *>(s, 0x50, self + 0x7fb);
  vcall<void *>(x, 0x50, self + 0x7ff);
  vcall<void *>(s, 0x50, self + 0x803);
  vcall<void *>(s, 0x50, self + 0x807);
  vcall<void *>(s, 0x50, self + 0x80b);
  vcall<void *>(s, 0x50, self + 0x80f);
  vcall<void *>(s, 0x50, self + 0x813);
  vcall<void *>(s, 0x50, self + 0x817);
  vcall<void *>(s, 0x50, self + 0x81b);
  vcall<void *>(s, 0x40, self + 0x842);
  vcall<void *>(s, 0x40, self + 0x846);
  vcall<void *>(s, 0x40, &t12);
  U32(self, 0x84e) = MgrLookup(t12);
  vcall<void *>(s, 0x74, self + 0x862);
  vcall<void *>(s, 0x6c, self + 0x886);
  vcall<void *>(s, 0x74, self + 0x892);
  vcall<void *>(s, 0x6c, self + 0x8b6);
  vcall<void *>(s, 0x50, self + 0x9e3);
  vcall<void *>(s, 0x40, self + 0x83e);
  vcall<void *>(s, 0x68, self + 0x66f);
  vcall<void *>(s, 0x40, &t12);
  U32(self, 0xeee) = MgrLookup(t12);
  vcall<void *>(s, 0x6c, self + 0x65d);
  void *x1 = vcall<void *>(s, 0x68, self + 0x669);
  void *x2 = vcall<void *>(x1, 0x68, self + 0x66a);
  // from here the exe's ebx is self + 0x66c (its last use is the store to +0x66c below)
  vcall<void *>(x2, 0x68, self + 0x66c);
  void *w = vcall<void *>(s, 0x68, self + 0x66d);
  vcall<void *>(w, 0x68, self + 0x66e);
  vcall<void *>(s, 0x40, self + 0x676);
  vcall<void *>(s, 0x68, self + 0x67f);
  vcall<void *>(s, 0x48, self + 0x684);
  vcall<void *>(s, 0x6c, self + 0x42d);
  vcall<void *>(s, 0x40, self + 0x83e);
  vcall<void *>(s, 0x6c, self + 0x439);
  vcall<void *>(s, 0x50, self + 0x451);
  vcall<void *>(s, 0x68, self + 0x831);
  vcall<void *>(s, 0x50, self + 0x81f);
  vcall<void *>(s, 0x50, self + 0x823);
  vcall<void *>(s, 0x68, self + 0x9f4);
  vcall<void *>(s, 0x68, self + 0x9f5);
  ext_58a8d0(s, self + 0xa16);
  ext_58a9b0(s, self + 0xd4a);
  vcall<void *>(s, 0x6c, self + 0xeb3);
  vcall<void *>(s, 0x6c, self + 0xebf);
  u32 tmp = 0;
  vcall<void *>(s, 0x40, &tmp);
  U32(self, 0xecb) = MgrLookup(tmp);
  vcall<void *>(s, 0x50, self + 0xed3);
  vcall<void *>(s, 0x50, self + 0xed7);
  vcall<void *>(s, 0x50, self + 0xedb);
  vcall<void *>(s, 0x48, self + 0xedf);
  vcall<void *>(s, 0x68, self + 0xeec);
  vcall<void *>(s, 0x68, self + 0xeed);
  vcall<void *>(s, 0x48, self + 0xf5e);
  ext_59d3a0(FP(self, 0x54), s);
  u32 t16 = 0;
  vcall<void *>(s, 0x48, &t16);
  u8 *table = G(u8 *, 0x7003b8);
  U8(self, 0x66c) = 0;
  U32(self, 0x64f) = (u32)(table + t16 * 0xf4 + 0xd91);
  u32 idx = U32(self, 0x684);
  *(u32 *)(table + 0x2c39 + idx * 4) = (u32)self;
  return true;
}
PCREG(592d50, ZFFHERO_Load);
