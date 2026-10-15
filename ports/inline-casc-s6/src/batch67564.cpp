// batch67564.cpp - cascade s6 batch 67564: 0x575bd0.
#include "ff.h"

extern "C" u32 THISCALL ext_5b1000(u8 *e, u8 *name);                           // ret 4, bool in al
extern "C" void THISCALL ext_574af0(u8 *self, u32 z, u32 *r, u32 flag, u32 one, u8 *s);   // ret 0x14

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x575bd0, thiscall() plain ret (eax unused): refreshes five entries of 0x24 bytes at this+0x240 ({+0 flag, +4 source object with slot 0x84 filling a 3-dword record, ...}). For every entry with a flag and
// a source the record is read (slot 0x84), the entry's name (+0 -> +4, default 0x67c8e8) is looked up in this[0x94]+0x50f (0x5b1000) and, while fewer than this[0x1fe] slot objects (array at this+0x190) have
// been used, the next slot object gets the name (via the manager's slot 0 at sys[0x9b][0xae4]) through its slot 0x284, is hidden (0xbc(0)) and set to 0x14 (0x260), and is passed to 0x574af0 with the record
// and the lookup flag; otherwise 0x574af0 gets no slot object.
static void THISCALL fn575bd0(u8 *self) {
  u32 r[3];
  u32 used = 0;
  u8 *slotp = self + 0x190;
  u8 *e = self + 0x240;
  for (int i = 0; i < 5; i++, e += 0x24) {
    if (D32(e, 0) == 0) continue;
    u8 *src = *(u8 **)(e + 4);
    if (!src) continue;
    r[0] = r[1] = r[2] = 0;
    vcall<void>(src, 0x84, (u32)r);
    u8 *nm = *(u8 **)(*(u8 **)e + 4);
    if (!nm) nm = (u8 *)0x67c8e8;
    u8 flag = (u8)ext_5b1000(*(u8 **)(self + 0x94) + 0x50f, nm);
    u8 *s = 0;
    if (used < D32(self, 0x1fe)) {
      u8 *nm2 = *(u8 **)(*(u8 **)e + 4);
      if (!nm2) nm2 = (u8 *)0x67c8e8;
      u8 *mgr = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xae4);
      u32 y = vcall<u32>(mgr, 0, 0x6a930cu, (u32)nm2);
      s = *(u8 **)slotp;
      vcall<void>(s, 0x284, y);
      vcall<void>(s, 0xbc, 0u);
      vcall<void>(s, 0x260, 0x14u);
      used++;
      slotp += 4;
    }
    ext_574af0(self, 0, r, flag, 1, s);
  }
}
PCREG(575bd0, fn575bd0);
