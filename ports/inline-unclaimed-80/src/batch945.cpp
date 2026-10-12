#include "ff.h"
// batch945.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): ZGROUP::AddLine(u32, u32, u32) (0x43eb00, high).
// Thiscall with ecx unused (the object comes from the global at 0x70039c, read again after every virtual call, as the exe does).
// (1) obj = [g+0x9b]; esi = obj vslot +0x58(obj.+0x14). (2) if esi == 0: c = [obj+0xadc]; esi = c vslot +0x294(0x67c7fc,
// 0x67cd24, 1, 1); obj = [g+0x9b]; r = obj vslot +0x4c(esi); [[g+0x9b]+0x14] = r. (3) tail: 0x65f400(ecx = esi, a1, a2, a3), returned.
// All virtual calls are callee-cleaned (the exe pops nothing after them), so each is a plain thiscall of the slot.

extern "C" u32 THISCALL ext_65f400(u8 *self, u32 a1, u32 a2, u32 a3);

typedef u32(THISCALL *tc1)(u8 *, u32);
typedef u32(THISCALL *tc4)(u8 *, u32, u32, u32, u32);

static u32 THISCALL zgroupAddLine(u8 *self, u32 a1, u32 a2, u32 a3) {
  (void)self;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 esi = ((tc1)(*(u32 *)(*(u32 *)obj + 0x58)))(obj, *(u32 *)(obj + 0x14));
  if (esi == 0) {
    u8 *c = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
    esi = ((tc4)(*(u32 *)(*(u32 *)c + 0x294)))(c, 0x67c7fc, 0x67cd24, 1, 1);
    u8 *o2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 r = ((tc1)(*(u32 *)(*(u32 *)o2 + 0x4c)))(o2, esi);
    *(u32 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0x14) = r;
  }
  return ext_65f400((u8 *)esi, a1, a2, a3);
}
PCREG(43eb00, zgroupAddLine);
