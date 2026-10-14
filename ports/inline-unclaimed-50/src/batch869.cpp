// batch869.cpp - area 50 (residue-09 file row): 0x584610 CHitpointControl::Load2() [37 instr, thiscall]. If the byte at this+0x63
// is set, this is appended to the global table at [0x7003b8] (the count at +0xb61, the slots from +0xb65). Then the value of
// this+0x44 through the render manager's vt +0x4c is pushed onto the list at table+0x4a0 (cur at +4, end at +8): stored at cur
// when cur is not null, and cur advances by 4; when cur equals end, the list grows through 0x4301c0 (cdecl; stood in).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *ext_4301c0(void *cur, u32 *value);   // list growth (stood in; cdecl)

// 0x584610 CHitpointControl::Load2 (name from the residue file).
static void THISCALL Load2_584610(u8 *self) {
  if (U8(self, 0x63) != 0) {
    u8 *tbl = G(u8 *, 0x7003b8);
    u32 idx = U32(tbl, 0xb61);
    U32(tbl, 0xb65 + idx * 4) = (u32)self;
    U32(tbl, 0xb61) = idx + 1;
  }
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u32 v = vcall<u32>(mgr, 0x4c, U32(self, 0x44));
  u8 *lst = G(u8 *, 0x7003b8) + 0x4a0;
  u8 *cur = (u8 *)U32(lst, 4);
  if (cur == (u8 *)U32(lst, 8)) {
    ext_4301c0(cur, &v);
    return;
  }
  if (cur != 0) U32(cur, 0) = v;
  U32(lst, 4) = U32(lst, 4) + 4;
}
PCREG(584610, Load2_584610);
