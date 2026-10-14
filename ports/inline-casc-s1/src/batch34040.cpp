// batch34040 - cascade tier E, batch 34040: 0x509ff0 (show every object of a list), 0x54bae0 (tear down five owned members), 0x54dd50 (advance a three-mode
// state machine).
#include "ff.h"

extern "C" void FASTCALL ext_54f2b0(void *ecx, u32 edx);   // fastcall, plain ret
extern "C" void THISCALL ext_54da10(void *self);           // thiscall, plain ret
extern "C" u32 THISCALL ext_54e1e0(void *p);               // thiscall, plain ret: returns the byte at +0x59

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x509ff0, thiscall(unused) ret 4: like 0x509aa0 but slot 0xbc(0): walks the id list object at [[this+0xc]+0x18] (slot 0x4c begin, slot 0x5c next, stack iterator) and
// calls slot 0xbc(0) on every object found through engine table slot 0x58.
static void THISCALL fn509ff0(u8 *self, u32 unused) {
  (void)unused;
  u32 it[3];
  u8 *l = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
  if (!l) return;
  vcall<void>(l, 0x4c, (u32)it);
  u32 id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, id);
    if (o) vcall<void>(o, 0xbc, 0u);
    id = vcall<u32>(*(u8 **)(*(u8 **)(self + 0xc) + 0x18), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(509ff0, fn509ff0);

// 0x54bae0, thiscall, no args: c1 = [this+0x63ec]: c1->slot0x48(c1) and 0x54f2b0(result, 0x6a3b90) when found; c2 = [this+0x63e8]: c2->slot8(c2); c3 = [this+0x63f0] read, [this+0x63e8] = 0,
// c3->slot8(c3); c4 = [this+0x63f4]: c4->slot0(1) and [this+0x63f4] = 0; [this+0x63f0] = 0; c1 (re-read)->slot8(c1) and [this+0x63ec] = 0; then 0x54da10(this).
static void THISCALL fn54bae0(u8 *self) {
  u8 *c1 = *(u8 **)(self + 0x63ec);
  if (c1) {
    u32 r = vcall<u32>(c1, 0x48, (u32)c1);
    if (r) ext_54f2b0((void *)r, 0x6a3b90u);
  }
  u8 *c2 = *(u8 **)(self + 0x63e8);
  if (c2) vcall<void>(c2, 8, (u32)c2);
  u8 *c3 = *(u8 **)(self + 0x63f0);
  *(u32 *)(self + 0x63e8) = 0;
  if (c3) vcall<void>(c3, 8, (u32)c3);
  u8 *c4 = *(u8 **)(self + 0x63f4);
  if (c4) {
    vcall<void>(c4, 0, 1u);
    *(u32 *)(self + 0x63f4) = 0;
  }
  c1 = *(u8 **)(self + 0x63ec);
  *(u32 *)(self + 0x63f0) = 0;
  if (c1) {
    vcall<void>(c1, 8, (u32)c1);
    *(u32 *)(self + 0x63ec) = 0;
  }
  ext_54da10(self);
}
PCREG(54bae0, fn54bae0);

// 0x54dd50, thiscall, no args: v = this->slot0x34(); [this+0x20] = [this+0x1c]; [this+0x1c] = v; mode = [this+0x75] (unaligned). Mode 1: when byte [+0x7e]: this->slot0x30(), [+0x7e] = 0,
// [+0x7c] = 1. Mode 3 with the pointer p at [+0x29]: when [+0x7c] is non-zero: this->slot0x30(); otherwise when 0x54e1e0(p) (the byte at p+0x59): [+0x1c] = [+0x10], [+0x20] = 0 and when
// this->slot0x30() is non-zero [+0x7c] = 1. Other modes: nothing more.
static void THISCALL fn54dd50(u8 *self) {
  u32 v = vcall<u32>(self, 0x34);
  u32 old = *(u32 *)(self + 0x1c);
  *(u32 *)(self + 0x1c) = v;
  u32 mode = rd32u(self + 0x75);
  *(u32 *)(self + 0x20) = old;
  if (mode == 1) {
    if (self[0x7e]) {
      vcall<void>(self, 0x30);
      self[0x7e] = 0;
      self[0x7c] = 1;
    }
    return;
  }
  if (mode != 3) return;
  u8 *p = (u8 *)rd32u(self + 0x29);
  if (!p) return;
  if (self[0x7c] != 0) {
    vcall<void>(self, 0x30);
    return;
  }
  if (!(u8)ext_54e1e0(p)) return;
  *(u32 *)(self + 0x1c) = *(u32 *)(self + 0x10);
  *(u32 *)(self + 0x20) = 0;
  if (vcall<u32>(self, 0x30) == 0) return;
  self[0x7c] = 1;
}
PCREG(54dd50, fn54dd50);
