// batch861.cpp - area 50 (residue-9 candidate): 0x513190 [105 instr, thiscall, no args, no name in the map (GUESS "class-level
// init of a vehicle-like object from the render manager's named values")]. The render manager (+0x9b, vt +0x138) gives a name
// id (vt +0x88 with name 0x692dec); with a non-zero id the object (vt +0x58) gives the value stored at +0x1f5 by its vt +0x100.
// Otherwise a debug line is printed (logger 0x700390, file 0x69e4bc, line 0x16d; cdecl printf with the name at +4, or the
// default 0x67c8e8). A second name (0x681320) gives the object at +0x1f9; +0x1f1 is set to 0.5; a line (0x178) is printed when
// +0x12f is zero; +0x1cd and +0x1d5 come from the sound manager (+0x1a9f, vt +0x60) when it exists.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// the engine's render manager (the object at [[0x70039c]+0x9b])
static inline u8 *FP_mgr() { return (u8 *)FP(G(u8 *, 0x70039c), 0x9b); }

// 0x513190 (name GUESS).
static void THISCALL Init513190(u8 *self) {
  const char *dflt = (const char *)0x67c8e8;
  u32 tmp = 0;
  vcall<void>(vcall<u8 *>(FP_mgr(), 0x138), 0x88, (u32)0x692dec, &tmp);
  if (tmp != 0) {
    u8 *o = vcall<u8 *>(FP_mgr(), 0x58, tmp);
    U32(self, 0x1f5) = vcall<u32>(o, 0x100, (u32)0x692dc4);
  } else {
    U32(self, 0x1f5) = 0;
    u8 *sink = vcall<u8 *>(G(u8 *, 0x700390), 0x20, (u32)0x69e4bc, 0x16du);
    const char *name = U32(self, 4) ? (const char *)U32(self, 4) : dflt;
    typedef void (*printf_t)(void *, const char *, const char *);
    (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x69e58c, name);
  }
  tmp = 0;
  vcall<void>(vcall<u8 *>(FP_mgr(), 0x138), 0x88, (u32)0x681320, &tmp);
  U32(self, 0x1f9) = (u32)vcall<u8 *>(FP_mgr(), 0x58, tmp);
  U32(self, 0x1f1) = 0x3f000000u;
  if (U32(self, 0x12f) == 0) {
    u8 *sink = vcall<u8 *>(G(u8 *, 0x700390), 0x20, (u32)0x69e4bc, 0x178u);
    const char *name = U32(self, 4) ? (const char *)U32(self, 4) : dflt;
    typedef void (*printf_t)(void *, const char *, const char *);
    (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x69e5c0, name);
  }
  U32(self, 0x1cd) = 0;
  U32(self, 0x1d5) = 0;
  u8 *snd = (u8 *)FP(G(u8 *, 0x70039c), 0x1a9f);
  if (snd) {
    U32(self, 0x1cd) = vcall<u32>(snd, 0x60, U32(self, 0x12f), (u32)0x69e5ec);
    U32(self, 0x1d5) = vcall<u32>(snd, 0x60, U32(self, 0x12f), (u32)0x69e5f8);
  }
}
PCREG(513190, Init513190);
