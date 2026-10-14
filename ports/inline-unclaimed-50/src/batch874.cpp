// batch874.cpp - area 50 (residue-09 candidate): 0x4d2cd0 [35 instr, thiscall, two stack args (ret 8), returns an int in eax;
// GUESS "copy a stored block of an entry the manager finds"]. The object's vt +0xb0 (with the first argument, and 0) gives an
// entry e; with no entry the result is 0. If the entry's flags word (through its +4 pointer, byte +0x10) lacks bit 2, a debug
// line is printed (logger 0x700390, vt +0x24, cdecl, format 0x696394 with the first argument). The block at e + [e] + 0xc with
// length [e+8] is copied (memcpy, import 0x67626c) to the second argument, and the length is returned.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x4d2cd0 (name GUESS).
static u32 THISCALL Copy4d2cd0(u8 *self, u32 a1, u32 a2) {
  u8 *e = (u8 *)vcall<u8 *>(self, 0xb0, a1, 0u);
  if (e == 0) return 0;
  u8 *fl = (u8 *)FP(e, 4);
  if ((U8(fl, 0x10) & 4) == 0) {
    u8 *lg = G(u8 *, 0x700390);
    typedef void (*log_t)(void *, const char *, u32);
    (*(log_t *)(*(u8 **)lg + 0x24))(lg, (const char *)0x696394, a1);
  }
  typedef void *(*memcpy_t)(void *, const void *, u32);
  (*(memcpy_t *)0x67626c)((void *)a2, e + U32(e, 0) + 0xc, U32(e, 8));
  return U32(e, 8);
}
PCREG(4d2cd0, Copy4d2cd0);
