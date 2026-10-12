// batch313.cpp - ZInputActions::PrintActionDebugInfo(char *name) (core-todo residue-02). 0x439f60, thiscall (this = ECX),
// one stack argument, ret 4. GC 80248b64 (name map, high). Body: a = this slot 0x58(name); if a != 0 and [a] == 0:
// printer = g 0x700390; obj = printer slot 0x20(file "actions.cpp", line 0x6b4); then obj's vtable slot 0x2c (cdecl,
// five arguments: obj, format "Action %s: Hold %s, Tap %s", a+4, tap, hold), with hold = byte[a+0x2e] >= 0x80 ? "true" : "false"
// and tap = byte[a+0x2f] & 0x10 ? "true" : "false".
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL inputActionsPrintDebugInfo(u8 *self, const char *name) {
  u8 *a = vcall<u8 *>((void *)self, 0x58, (void *)name);
  if (a == 0 || U32(a, 0) != 0)
    return;
  u8 *printer = (u8 *)G(u32, 0x700390);
  u8 *obj = vcall<u8 *>((void *)printer, 0x20, (void *)(unsigned long)0x67a850u, 0x6b4u);
  const char *hold = (a[0x2e] >= 0x80) ? (const char *)(unsigned long)0x67a8ccu : (const char *)(unsigned long)0x67a8d4u;
  const char *tap = (a[0x2f] & 0x10) ? (const char *)(unsigned long)0x67a8ccu : (const char *)(unsigned long)0x67a8d4u;
  typedef void (*printfn)(void *, const char *, const char *, const char *, const char *);
  printfn fn = (printfn)(unsigned long)U32((u8 *)(unsigned long)U32(obj, 0), 0x2c);
  fn(obj, (const char *)(unsigned long)0x67a8dcu, (const char *)(unsigned long)U32(a, 4), tap, hold);
}
PCREG(439f60, inputActionsPrintDebugInfo);
