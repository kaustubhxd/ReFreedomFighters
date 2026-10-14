// batch33046.cpp - h3 () batch 33046: node recycler, slot scan, six tiny vcall wrappers
#include "ff.h"

extern "C" u32 THISCALL ext_63b240(u8 *self);                         // bool in al
extern "C" u8 *THISCALL ext_589c20(u8 *self, u32 idx);                // ret 4
#define G7003b8 (*(u8 **)0x7003b8)

// 0x648520: thiscall: skip 0xffff nodes (next at +8), refill via 0x63b240, hand out the free record after the node
static u8 *THISCALL fn648520(u8 *self) {
  u8 *head = *(u8 **)(self + 8);
  u8 *edx;
  if (head) {
    for (;;) {
      u8 *n = *(u8 **)(self + 8);
      if (*(u16 *)(n + 2) != 0xffff) {
        (*(u32 *)(self + 0xc))++;
        edx = n;
        goto have;
      }
      u8 *nx = *(u8 **)(n + 8);
      *(u8 **)(self + 8) = nx;
      if (head == nx) break;
      if (!nx) break;
    }
  }
  if (!(u8)ext_63b240(self)) return 0;
  edx = *(u8 **)(self + 8);
  (*(u32 *)(self + 0xc))++;
have:
  u32 ax = *(u16 *)(edx + 2);
  if ((u16)ax == 0xffff) return 0;
  u8 *rec = edx + (ax + 1) * 16;
  *(u16 *)(edx + 2) = *(u16 *)rec;
  *(u32 *)rec = 0;
  *(u32 *)(rec + 4) = 0xffff1207;
  *(u32 *)(rec + 8) = 0;
  *(u32 *)(rec + 0xc) = 0;
  edx[0]++;
  return rec;
}
PCREG(648520, fn648520);

// 0x597a70: thiscall(a) ret 4 bool: scan four slots of global 0x7003b8
static u32 THISCALL fn597a70(u8 *self, u32 a) {
  for (int i = 0; i < 4; i++) {
    u8 *edi = ext_589c20(G7003b8, i);
    if (!edi) continue;
    u8 *edx = *(u8 **)(G7003b8 + i * 4 + 0x2c3d);
    u32 v = *(u32 *)(*(u8 **)(edx + 8) + 0x3c);
    if (!((~(v >> 10)) & 1)) continue;
    u8 *ecx = *(u8 **)(edx + 0x54);
    u32 eax = *(u32 *)(*(u8 **)(*(u8 **)(self + 0x1d0b) + 0x54) + 4);
    if (eax != *(u32 *)(ecx + 4)) continue;
    int n = *(int *)(edi + 0x1fae);
    if (n <= 0) continue;
    u32 *p = (u32 *)(edi + 0x1dae);
    for (int k = 0; k < n; k++, p++)
      if (*p == a) return 1;
  }
  return 0;
}
PCREG(597a70, fn597a70);

// 0x466d70: thiscall: vslot 0x2b4(0x11)
static u32 THISCALL fn466d70(u8 *self) { return vcall<u32>(self, 0x2b4, 0x11u); }
PCREG(466d70, fn466d70);

// 0x466f50: thiscall: vslot 0x2b4(2)
static u32 THISCALL fn466f50(u8 *self) { return vcall<u32>(self, 0x2b4, 2u); }
PCREG(466f50, fn466f50);

// 0x46eab0: thiscall: r = vslot 0x350(); return *(u32*)(r + 0x11b)
static u32 THISCALL fn46eab0(u8 *self) {
  u8 *r = vcall<u8 *>(self, 0x350);
  return *(u32 *)(r + 0x11b);
}
PCREG(46eab0, fn46eab0);

// 0x54df90: thiscall bool: vslot 0x24(); return 1
static u32 THISCALL fn54df90(u8 *self) {
  vcall<u32>(self, 0x24);
  return 1;
}
PCREG(54df90, fn54df90);

// 0x46e580: thiscall: vslot 0x25c(0x68887c, 0)
static u32 THISCALL fn46e580(u8 *self) { return vcall<u32>(self, 0x25c, 0x68887cu, 0u); }
PCREG(46e580, fn46e580);

// 0x46e450: thiscall: o = sysobj+0x9b object; return o->vslot 0x58([this+0xb6])
static u32 THISCALL fn46e450(u8 *self) {
  u8 *o = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  return vcall<u32>(o, 0x58, *(u32 *)(self + 0xb6));
}
PCREG(46e450, fn46e450);
