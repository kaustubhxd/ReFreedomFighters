// batch1031.cpp - area 81, batch 1031: 0x5022e0, thiscall (this; P as one stack argument), ret 4. Cookie check not reproduced. The helper 0x5003d0 (element
// address: [S] + 8 * (T[+4] + idx), one stack argument, ret 4) is the REAL exe code, called through its address (not stood in). The record kinds are
// read from byte +4 (3: value = dword 0; 4: dword 0 is an object whose slot 0x34 gives the value; other: a debug print and the hook at 0x7003b0). The
// render manager's slot 0x114 gives a word (four arguments), this's slot 0x12c-holder (the object at +0xc) takes three arguments.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef u8 *(__attribute__((thiscall)) * elem_fn)(void *self, u32 idx);
typedef void(__attribute__((cdecl)) * print_fn)(u32, u32, u32);

static u8 *elem(u8 *T, u32 idx) {
  volatile u32 addr = 0x5003d0u;   // read at run time: a literal would make the link look for a symbol
  elem_fn fn = (elem_fn)(u64)addr;
  return fn(T, idx);
}

// 0x5022e0 (thiscall: this; P).
static void THISCALL recordChain(u8 *X, u32 Parg) {
  u8 *P = (u8 *)Parg;
  u8 *Q1 = (u8 *)D(P, 4);
  u8 *R1 = elem(Q1, 1);
  u32 kind = R1[4];
  u32 V1 = 0;
  if (kind == 3) {
    V1 = D(R1, 0);
  } else if (kind == 4) {
    u8 *Z = (u8 *)D(R1, 0);
    V1 = vcall<u32>(Z, 0x34);
  } else {
    u8 *chan = (u8 *)vcall<u32>((void *)*(u32 *)0x700390, 0x20, 0x69c8e0u, 0x111u);
    print_fn fn = (print_fn)D(*(u8 **)chan, 0x2c);
    fn((u32)chan, 0x69c6b0u, 0x69c9b0u);
    void (*hook)() = (void (*)())*(u32 *)0x7003b0;
    if (!hook)
      __builtin_trap();
    hook();
    V1 = 0;
  }
  u8 *rm = (u8 *)D(*(u8 **)0x70039c, 0x9b);
  u32 F = (u16)vcall<u32>(rm, 0x114, V1, 0u, 0x69ca10u, 0x23eu);
  u8 *R2 = elem(Q1, 2);
  u8 *R3 = elem(Q1, 0);
  u32 V2 = D(R2, 0);
  u32 V3 = D(R3, 0);
  vcall<void>((void *)D(X, 0xc), 0x12c, V3, F, V2);
}
PCREG(5022e0, recordChain);
