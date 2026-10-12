// batch279.cpp - unclaimed area 67, gap band: indexed table lookup with a hook fallback.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f4a80, thiscall, ret 4 (argument w, read as 16 bits for the index; the return is the full argument on the fallback).
static u32 THISCALL indexTable4a80(u8 *selfP, u32 w) {
  u32 self = (u32)(unsigned long)selfP;
  u16 idx = (u16)w;
  if ((u32)idx < rdw(self, 0x104))
    return *(u32 *)(unsigned long)(rdw(self, 0x108) + (u32)idx * 4);
  u32 hook = *(u32 *)0x7003b0;
  if (hook != 0)
    ((void (*)(void))hook)();
  return w;
}
PCREG(5f4a80, indexTable4a80);
