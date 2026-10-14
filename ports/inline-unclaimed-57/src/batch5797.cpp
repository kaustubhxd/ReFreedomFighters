// batch5797.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 97: 0x5d7610 (GUESS name unnamed_5d7610), thiscall, one stack argument db (ret 4),
// no return value. Order: this+0x1d6 = 0x4e5e60(db); this+0x1da = 0x4e5e60(db); this+0x15a = 0x4e5e60(db); s = 0x4e5ea0(db); len = strlen(s);
// if len > 0x63: assert hook 0x7003b0 (non-null in the spec); strncpy(this+0x15e, s, 0x63) (CRT import through the IAT at 0x67642c);
// this+0x1c1 = 0; r = 0x4e5e60(db); this+0x1de = 0; this+0x1e2 = 0; this+0x1c2 = (r != 0); if the byte at *(dword db) is neither 0xff nor
// (b & 0x3f) == 0xff: this+0x1de = 0x4e5e60(db); the same test again: if it passes this+0x1e2 = 0x4e5e60(db).
#include "ff.h"

typedef void *(*StrncpyFn)(void *dst, const void *src, u32 n);

extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)
extern "C" u8 *THISCALL ext_4e5ea0(u8 *db);  // string reader, original code (hooked in the spec)

// 0x5d7610, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5d7610(u8 *self, u8 *db) {
  *(u32 *)(self + 0x1d6) = ext_4e5e60(db);
  *(u32 *)(self + 0x1da) = ext_4e5e60(db);
  *(u32 *)(self + 0x15a) = ext_4e5e60(db);
  u8 *s = ext_4e5ea0(db);
  u32 len = 0;
  while (s[len]) len++;
  if (len > 0x63) {
    u32 hook = G(u32, 0x7003b0);
    if (hook) ((void (*)(void))hook)();
  }
  ((StrncpyFn)(unsigned long)G(u32, 0x67642c))(self + 0x15e, s, 0x63);
  *(u8 *)(self + 0x1c1) = 0;
  u32 r = ext_4e5e60(db);
  *(u32 *)(self + 0x1de) = 0;
  *(u32 *)(self + 0x1e2) = 0;
  *(u8 *)(self + 0x1c2) = r != 0;
  u8 b = *(u8 *)(unsigned long)*(u32 *)db;
  if (b != 0xff && (u8)(b & 0x3f) != 0xff) *(u32 *)(self + 0x1de) = ext_4e5e60(db);
  u8 b2 = *(u8 *)(unsigned long)*(u32 *)db;
  if (b2 != 0xff && (u8)(b2 & 0x3f) != 0xff) *(u32 *)(self + 0x1e2) = ext_4e5e60(db);
}
PCREG(5d7610, unnamed5d7610);
