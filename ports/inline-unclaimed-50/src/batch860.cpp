// batch860.cpp - area 50 (residue-9 candidate): 0x439fd0 [105 instr, thiscall, one stack arg (a source record), ret 4; no
// name in the map (GUESS "init from a source record, with a debug line")]. Logs a line (logger 0x700390, file 0x67a850,
// line 0xe55, format 0x67ac90), runs two base steps (0x4388a0, 0x438910), allocates 0x1c bytes (0x41e290) and constructs
// the object (0x4ccbe0) when the allocation worked; then copies the source's flags and words into this (+0x15, +0x19, +0x35,
// +0x3e, +0x42, +0x46, +0x32 bit 4), calls 0x4386a0 for the source's values at +0xa7 and +0xab, and calls this's vt +0x08
// for the two slots at +0x80 and +0x90 when they are not -1. The exe's SEH frame (fs:[0]) is not reproduced.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4388a0(void *self);                             // base step (stood in)
extern "C" void THISCALL ext_438910(void *self);                             // base step (stood in)
extern "C" void THISCALL ext_4386a0(void *self, u32 a, u32 b);               // value step (stood in)
extern "C" void *THISCALL ext_4ccbe0(void *self, u32 a, u32 b);              // constructor (stood in)
extern "C" void *ext_41e290(u32 size);                                        // allocator (stood in; cdecl)

// 0x439fd0 (name GUESS).
static void THISCALL Fn439fd0(u8 *self, u8 *src) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x67a850, 0xe55u);
  typedef void (*printf_t)(void *, const char *);
  (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x67ac90);
  ext_4388a0(self);
  ext_438910(self);
  void *p = ext_41e290(0x1c);
  void *obj = 0;
  if (p) obj = ext_4ccbe0(p, 2, 0);
  U32(self, 0x15) = (u32)obj;
  U32(self, 0x19) = 0;
  U32(self, 0x3e) = 0;
  U32(self, 0x42) = 0;
  U32(self, 0x46) = 0;
  if (U8(src, 0xa0) == 0) U32(self, 0x35) = U32(src, 0xa1);
  if (U32(src, 0x80) == 0xffffffffu && U32(src, 0x90) == 0xffffffffu && U32(src, 0xa7) == 0 && U32(src, 0xab) == 0)
    U8(self, 0x32) = U8(self, 0x32) | 4;
  else
    U8(self, 0x32) = U8(self, 0x32) & 0xfb;
  U32(self, 0x3e) = 0;
  u32 w = U32(src, 0xa7);
  if (w != 0) ext_4386a0(self, w, 1);
  w = U32(src, 0xab);
  if (w != 0) ext_4386a0(self, w, 0);
  u8 *q = src + 0x80;
  if (U32(q, 0) != 0xffffffffu) vcall<void>(self, 0x8, (u32)q, 1u);
  q = src + 0x90;
  if (U32(q, 0) != 0xffffffffu) vcall<void>(self, 0x8, (u32)q, 0u);
}
PCREG(439fd0, Fn439fd0);
