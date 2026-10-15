// batch50004.cpp - cascade u3, tier H, batch 50004: 0x640590 (walk the object list at this+0x204 and update each entry's sub-object).
#include "ff.h"

extern "C" void THISCALL ext_4dbb00(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_4dd3d0(u8 *self);

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// debug trace: when the engine object's floats at +0x9c7 and +0x9c3 are both nonzero (unaligned), calls slot 0x1c8(0x67a7f8, line) (64-bit result) and then slot `slot`(lo, hi, 0x6c27e0).
static void dbgtrace(u32 line, u32 slot) {
  u8 *sys = G(u8 *, 0x70039c);
  if (bitsf(rd32(sys + 0x9c7)) != 0.0f && bitsf(rd32(sys + 0x9c3)) != 0.0f) {
    u64 r = vcall<u64>(sys, 0x1c8, 0x67a7f8, line);
    sys = G(u8 *, 0x70039c);
    vcall<void>(sys, slot, (u32)r, (u32)(r >> 32), 0x6c27e0);
  }
}

struct Iter {
  u8 **cur;
  u32 idx;
  u32 *node;
};

// 0x640590, thiscall() void: trace (line 0x259, slot 0x178); ebx = unaligned dword at [[sys+0x9b]+0x5d35]; walks the container at this+0x204 (begin: slot 0xc(&it), step: slot 0x10(&it) or the
// inline block iteration idx++ / node[8] / node+0x10 / cur += 4). Entries whose [e+0x38] sub-object is null or whose byte [e+5] bit 0 is clear are skipped. For the others, t = [sub+0x54]:
// t and [[t+0xc]+0x23] (unaligned) == 0x80000d: t slot 0x220(0) when [t+0x18] & 8; otherwise: [sub+0x3c] & 0x2000000 -> ext_4dbb00(sub, 0), ext_4dd3d0(sub); else when [t+0x18] & 8 and ebx
// is set -> ebx slot 0x14(sub); then t slot 0x220(0). Finally trace (line 0x260, slot 0x17c).
static void THISCALL fn640590(u8 *self) {
  dbgtrace(0x259, 0x178);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(sys + 0x9b);
  u32 ebx = rd32(tab + 0x5d35);
  u8 *cont = self + 0x204;
  Iter it;
  vcall<void>(cont, 0xc, (u32)&it);
  while (it.cur) {
    u8 *el = *it.cur;
    u8 *sub = *(u8 **)(el + 0x38);
    if (!sub || !(el[5] & 1)) {
      vcall<void>(cont, 0x10, (u32)&it);
      continue;
    }
    u32 idx = it.idx + 1;
    it.idx = idx;
    u8 **cur;
    if (idx == it.node[0]) {
      it.node = (u32 *)it.node[2];
      if (it.node) {
        it.idx = 0;
        cur = (u8 **)(it.node + 4);
      } else {
        cur = 0;
      }
    } else {
      cur = it.cur + 1;
    }
    it.cur = cur;
    u8 *t = *(u8 **)(sub + 0x54);
    if (t && rd32(*(u8 **)(t + 0xc) + 0x23) == 0x80000d) {
      if (!(t[0x18] & 8)) continue;
    } else if (*(u32 *)(sub + 0x3c) & 0x2000000) {
      ext_4dbb00(sub, 0);
      ext_4dd3d0(sub);
    } else if ((t[0x18] & 8) && ebx) {
      vcall<void>((void *)ebx, 0x14, (u32)sub);
    }
    vcall<void>(t, 0x220, 0);
  }
  dbgtrace(0x260, 0x17c);
}
PCREG(640590, fn640590);
