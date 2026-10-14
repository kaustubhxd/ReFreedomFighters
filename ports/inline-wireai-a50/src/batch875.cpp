// batch875.cpp - area 50 (residue-09 candidate): 0x5ffd10 [30 instr, thiscall, one stack arg (a 16-bit key), ret 4, returns an
// int; GUESS "index lookup table with base key and offset"]. idx = (word key - word at this+0) as an unsigned 16-bit value; when
// idx < the count at this+8 the result is table[idx] + this+0x10 (table at this+0xc). Otherwise a line is printed (logger 0x700390,
// file 0x6b9420, line 0x137, format 0x69c6b0 with 0x6b9474) and the assert hook at 0x7003b0 is called when set and its result is the function's result (the exe traps when the hook is null).
#include "ff.h"

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x5ffd10 (name GUESS).
static u32 THISCALL Lookup5ffd10(u8 *self, u32 key) {
  u16 ax = (u16)key - U16(self, 0);
  u32 idx = ax;
  if (idx < U32(self, 8)) {
    u32 *table = (u32 *)FP(self, 0xc);
    return table[idx] + U32(self, 0x10);
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x6b9420, 0x137u);
  typedef void (*printf_t)(void *, const char *, const char *);
  (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x69c6b0, (const char *)0x6b9474);
  typedef u32 (*hook_t)(void);
  hook_t hook = *(hook_t *)0x7003b0;   // the exe calls it when set (a null hook is an int3 trap in the exe)
  if (hook) return hook();
  return 0;
}
PCREG(5ffd10, Lookup5ffd10);
