// batch3006.cpp - unclaimed-30: batch 6 (docs/20-unclaimed-30.md, claim 1). CHitpointControl::Load2 [map 0x584610; thiscall, no
// arguments]. With this+0x63 set, this is recorded in the global list (count at g+0xb61, entries from g+0xb65). The message
// table's slot 0x4c gives a value for this+0x44; the value goes to the list cursor (g+0x4a4 is the cursor, g+0x4a8 the end) when the
// cursor is not null, and the cursor advances by 4. At the end the list's own insert (0x4301c0, thiscall with two arguments, exe
// code) takes the cursor and the value's address instead.
#include "ff.h"

// 0x4301c0 (exe code): list insert at the cursor with a grow path; thiscall, two stack arguments (ret 8).
extern "C" void THISCALL ext_4301c0(u8 *list, u32 cursor, u32 *value);

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL hitpointLoad2(u8 *self) {
  if (self[0x63]) {
    u8 *g = G(u8 *, 0x7003b8);
    u32 n = rd32u(g + 0xb61);
    wr32u(g + 0xb65 + 4 * n, (u32)self);
    wr32u(g + 0xb61, n + 1);
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = *(u8 **)(eng + 0x9b);
  u32 x = vcall<u32>(msg, 0x4c, rd32u(self + 0x44));
  u8 *L = G(u8 *, 0x7003b8) + 0x4a0;
  u32 cursor = rd32u(L + 4);
  if (cursor == rd32u(L + 8)) {
    ext_4301c0(L, cursor, &x);
    return;
  }
  if (cursor) wr32u((u8 *)cursor, x);
  wr32u(L + 4, cursor + 4);
}
PCREG(584610, hitpointLoad2);
