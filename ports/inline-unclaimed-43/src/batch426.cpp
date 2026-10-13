// batch426.cpp - residue 2 row 0x43b9a0 (thiscall, one stack argument msg, ret 4; config reader error report).
// L = dword [0x700390]; p = slot 0x20 of L with (0x67bd78 "..\..\code\engine\system\configreader.cpp", 0x23d) (thiscall,
// two stack arguments); line = 0x61bbd0 with ECX = this (exe, thiscall no arguments; hooked by address in the spec, GUESS: the
// current line number); file = dword [this+0x143] (0x4cc1d0 is a one-instruction getter, inlined); then slot 0x2c of p as a
// cdecl call (p, 0x67c0bc "Error in config file %s, line %d : %s", file, line, msg), cleaned by the caller (add esp, 0x14).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_61bbd0(void *self);                 // exe callee by address (hooked in the spec)

typedef void (*LogFn)(u32 stream, u32 fmt, u32 file, u32 line, u32 msg);

static void THISCALL configError(u8 *self, u32 msg) {
  u8 *logger = (u8 *)(unsigned long)G(u32, 0x700390);
  u32 p = vcall<u32>((void *)logger, 0x20, 0x67bd78u, 0x23du);
  u32 line = ext_61bbd0(self);
  u32 file = U32(self, 0x143);
  LogFn fn = (LogFn)(unsigned long)U32((u8 *)(unsigned long)U32((u8 *)(unsigned long)p, 0), 0x2c);
  fn(p, 0x67c0bcu, file, line, msg);
}
PCREG(43b9a0, configError);
