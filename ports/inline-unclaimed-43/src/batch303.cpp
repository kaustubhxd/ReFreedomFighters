// batch303.cpp - vector clear-then-append on this+0x6e (begin, +0x72 finish, +0x76 end) (area 43, 2026-10-12).
// 0x5ac960, thiscall (this = ECX), two stack arguments (arg1 pointer-like, arg2 dword), ret 8. No name-map entry.
// Body: arg1 == 0 returns at once. Otherwise finish is moved to begin (the size is cut to a multiple of 16 and removed,
// which is begin when the vector is 16-aligned). The record { 0, arg2 << 16, obj1 = this+0x1a, obj2 = this+0x42 }
// (16 bytes) is built on the frame, then obj1->slot 0x280(arg1, arg2) and, when the byte at this+0x19 is set,
// obj2->slot 0x280(arg1, arg2). Then: if finish == end, _M_insert_aux(this+0x6e, finish, &record) (exe, 0x5acad0).
// Otherwise the record is stored at finish (skipped when finish is 0) and finish += 16.
// The copy loop of the original (from begin to finish) never runs: it compares finish with itself (eax = 0).
// Quirk (not claimed): when the byte at this+0x19 is 0 the original copies the stale frame word [ebp-8] into the record's
// last dword (only the flag-on path writes it). The port writes 0 there; the spec only uses the flag-on path.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_5acad0(u8 *vec, u32 pos, u32 val);   // _M_insert_aux (ecx vec, stack pos, val)

static void THISCALL vecClearAppend(u8 *self, u8 *arg1, u32 arg2) {
  if (arg1 == 0)
    return;
  u32 begin = U32(self, 0x6e);
  // finish -= (finish - begin) rounded down to 16 (exe: sar/neg/shl on the byte size)
  s32 d = (s32)(U32(self, 0x72) - begin);
  d = d >> 4;
  d = -d;
  d = (s32)((u32)d << 4);
  U32(self, 0x72) += (u32)d;

  u32 rec[4];
  rec[0] = 0;
  rec[1] = (arg2 & 0xffff) << 16;
  u32 obj1 = U32(self, 0x1a);
  rec[2] = obj1;
  vcall<void>((void *)obj1, 0x280, arg1, arg2);
  if (*(u8 *)(self + 0x19) != 0) {
    u32 obj2 = U32(self, 0x42);
    rec[3] = obj2;
    vcall<void>((void *)obj2, 0x280, arg1, arg2);
  } else {
    rec[3] = 0;   // quirk: the original copies the stale word at [ebp-8] here
  }
  u32 fin = U32(self, 0x72);
  if (fin != U32(self, 0x76)) {
    if (fin != 0) {
      u32 *dst = (u32 *)fin;
      dst[0] = rec[0];
      dst[1] = rec[1];
      dst[2] = rec[2];
      dst[3] = rec[3];
    }
    U32(self, 0x72) = fin + 0x10;
  } else {
    ext_5acad0(self + 0x6e, fin, (u32)(unsigned long)rec);
  }
}
PCREG(5ac960, vecClearAppend);
