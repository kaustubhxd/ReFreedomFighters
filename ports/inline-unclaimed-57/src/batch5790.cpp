// batch5790.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 90: 0x5d8340 (GUESS name unnamed_5d8340), thiscall, one stack argument db
// (ret 4), no return value. Order: s = 0x4e5ea0(ECX = db) (reader, hooked: a heap string); len = strlen(s); if len > 0x63: assert hook
// 0x7003b0 (non-null in the spec; the original's int3 branch is not reproduced); strncpy(this+0x4e, s, 0x63) (CRT import at 0x67642c,
// called through the IAT entry as the original does); this+0xb1 = 0; this+0xb2 = (0x4e5e60(db) != 0); if the byte at *(dword db) is
// neither 0xff nor (b & 0x3f) == 0xff: this+0xbc = (engine)+0x9b ->vt[+0x58](0x4e5e60(db)).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void *(*StrncpyFn)(void *dst, const void *src, u32 n);

extern "C" u8 *THISCALL ext_4e5ea0(u8 *db);  // string reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)

// 0x5d8340, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5d8340(u8 *self, u8 *db) {
  u8 *s = ext_4e5ea0(db);
  u32 len = 0;
  while (s[len]) len++;
  if (len > 0x63) {
    u32 hook = G(u32, 0x7003b0);
    if (hook) ((void (*)(void))hook)();
  }
  ((StrncpyFn)(unsigned long)G(u32, 0x67642c))(self + 0x4e, s, 0x63);
  *(u8 *)(self + 0xb1) = 0;
  *(u8 *)(self + 0xb2) = ext_4e5e60(db) != 0;
  u8 b = *(u8 *)(unsigned long)*(u32 *)db;
  if (b != 0xff && (u8)(b & 0x3f) != 0xff) {
    u32 v = ext_4e5e60(db);
    u8 *eng = G(u8 *, 0x70039c);
    u8 *sub = *(u8 **)(eng + 0x9b);
    *(u32 *)(self + 0xbc) = ((SlotA)VT(sub)[0x58 / 4])(sub, v);
  }
}
PCREG(5d8340, unnamed5d8340);
