// batch950.cpp - 0x562140 (no name in the map), read in full (2026-10-12). STDCALL (two stack args, ret 8, void; ECX is not used): a = first arg
// (the second word pushed last), L = second arg, a list object. If L is null, return. node = [L+8]; if node is null, return. Loop: if 0x4db9a0 (thiscall,
// ECX = node, one arg 0x20002c; returns al; stood in) returns non-zero, call slot +0x250 of [node+0x54] with one arg a (stood in). Then call slot +0x50
// of L with one arg: the address of node (the callee updates node). Continue while node is non-zero.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u8 THISCALL ext_4db9a0(void *self, u32 flag);   // stood in (one arg, returns al)

// 0x562140 (no name in the map).
static void STDCALL Walk562140(u8 *a, u8 *L) {
  if (!L) return;
  u32 node = U32(L, 8);
  if (!node) return;
  do {
    if (ext_4db9a0((void *)node, 0x20002cu)) vcall<void>(FP((void *)node, 0x54), 0x250, a);
    vcall<void>(L, 0x50, &node);
  } while (node != 0);
}
PCREG(562140, Walk562140);
