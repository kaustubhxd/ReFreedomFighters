// batch34042.cpp - cascade tier E, batch 34042: 0x567110 (command gate), 0x56f7c0 (copy a snapshot into the attached object), 0x5708a0 (publish a table value
// under one of two names).
#include "ff.h"

extern "C" u32 THISCALL ext_566f10(void *self);                         // thiscall, plain ret
extern "C" void THISCALL ext_563d40(void *self, u32 a, u32 *p, u32 b);  // thiscall ret 0xc
extern "C" void THISCALL ext_5672c0(void *self, u32 a);                 // thiscall ret 4
extern "C" void THISCALL ext_567510(void *self);                        // thiscall, plain ret
extern "C" bool THISCALL ext_562c20(void *self, u32 k);                 // thiscall ret 4 (verified, batch 34041)
extern "C" void THISCALL ext_5ad790(void *buf);                         // thiscall, plain ret: builds a snapshot
extern "C" void THISCALL ext_56e9d0(void *self, void *buf);             // thiscall ret 4
extern "C" void THISCALL ext_5ad230(void *self, void *p);               // thiscall ret 4
extern "C" void THISCALL ext_5ad2b0(void *self, void *p);               // thiscall ret 4
extern "C" void THISCALL ext_59ca50(void *self, void *p);               // thiscall ret 4
extern "C" void THISCALL ext_5ae710(void *self, u32 a);                 // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                        // /GS check
extern "C" void THISCALL ext_562440(void *self);                        // thiscall, plain ret

// 0x567110, thiscall(a) ret 4, returns bool: false when this->slot0xd8() is true. When a == 1 and slot 0xd8() is (still) false: x = 0x566f10(this); 0x563d40(this, 0, &x, 2);
// 0x5672c0(this, x); 0x567510(this). Finally returns 0x562c20(this, a).
static bool THISCALL fn567110(u8 *self, u32 a) {
  if (vcall<bool>(self, 0xd8)) return false;
  if (a == 1) {
    if (!vcall<bool>(self, 0xd8)) {
      u32 x = ext_566f10(self);
      ext_563d40(self, 0, &x, 2);
      ext_5672c0(self, x);
      ext_567510(self);
    }
  }
  return ext_562c20(self, a);
}
PCREG(567110, fn567110);

// 0x56f7c0, thiscall, no args: ebx = [this+0x94]; builds a snapshot (0x5ad790 on a 4 KB local), 0x56e9d0(ebx+0x57, snapshot), 0x5ad230(ebx+0x3b1, this+0x1c9), 0x5ad2b0(ebx+0x3b1, this+0x1e9),
// [ebx+0x411] = [this+0x4b6], 0x59ca50([this+0x94], this+0x1e9), 0x5ae710(ebx+0x57, 0), then the /GS check.
static void THISCALL fn56f7c0(u8 *self) {
  u8 buf[0xfe8];
  u8 *ebx = *(u8 **)(self + 0x94);
  ext_5ad790(buf);
  ext_56e9d0(ebx + 0x57, buf);
  ext_5ad230(ebx + 0x3b1, self + 0x1c9);
  ext_5ad2b0(ebx + 0x3b1, self + 0x1e9);
  *(u32 *)(ebx + 0x411) = *(u32 *)(self + 0x4b6);
  ext_59ca50(*(u8 **)(self + 0x94), self + 0x1e9);
  ext_5ae710(ebx + 0x57, 0);
  ext_633654(0);
}
PCREG(56f7c0, fn56f7c0);

// 0x5708a0, thiscall, no args: 0x562440(this); s = engine table slot 0x138(); v = engine table slot 0x4c([this+0x44], 0x10); s->slot0x60(name, v) with name 0x6a86e0 when byte
// [this+0x1a3] is set, else 0x6a86ec.
static void THISCALL fn5708a0(u8 *self) {
  ext_562440(self);
  bool flag = self[0x1a3] != 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *s = vcall<u8 *>(tbl, 0x138);
  u32 vt = *(u32 *)s;
  (void)vt;
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x4c, *(u32 *)(self + 0x44), 0x10u);
  vcall<void>(s, 0x60, flag ? 0x6a86e0u : 0x6a86ecu, v);
}
PCREG(5708a0, fn5708a0);
