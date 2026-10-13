#include "ff.h"
// batch2753.cpp - unclaimed-27 batch 53 (residue 6). Virtual call setter, 16 bytes.
// FUN_00465a60: GUESS name. Thiscall, 4 arguments, calls virtual slot +0xc, returns 1.

static u8 THISCALL funcVirtualCallSetOne(u8 *this_obj, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
  // Load member at this+0x1ce
  u8 *member = (u8 *)(unsigned long)*(u32 *)(unsigned long)(this_obj + 0x1ce);

  // Get vtable and call slot +0xc
  u32 *vt = (u32 *)(unsigned long)*(u32 *)member;
  typedef void (*Func)(u8 *);
  ((Func)vt[0xc / 4])(member);

  return 1;
}

PCREG(465a60, funcVirtualCallSetOne);
