// batch34124.cpp - cascade tier E, batch 34124: 0x48b700 (create or look up an object and bind it), 0x4d86c0 (broadcast to a container), 0x4f4c20 (read a mode word).
#include "ff.h"

extern "C" u32 THISCALL ext_4cbe40(void *self);                          // thiscall, plain ret (indirect tail)
extern "C" u32 THISCALL ext_4f9c90(void *self, void *a);                 // thiscall ret 4
extern "C" u32 THISCALL ext_4e11e0(void *self, void *p, u32 n);          // thiscall ret 8
extern "C" u32 THISCALL ext_4e12e0(void *self, void *p, u32 n);          // thiscall ret 8
extern "C" u32 THISCALL ext_4e1b30(void *self);                          // thiscall, plain ret

// 0x48b700, thiscall(a, b, c) ret 0xc, returns the bound object (0 when none): when this->slot0x7c() has a non-zero low byte the log object [0x700390]->slot0x20(0x68d798, 0xe20)->slot0x2c(it, 0x68df0c, a) (cdecl) is called.
// e = c, or this->slot0x154(a, 1) when c is 0 (return 0 when that is 0 too); p = ext_4cbe40(e); p->slot0x70(e, -1); returns p.
static u32 THISCALL fn48b700(u8 *self, u32 a, u32 b, u8 *c) {
  (void)b;
  if ((u8)vcall<u32>(self, 0x7c)) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x68d798u, 0xe20u);
    typedef void (*pf)(u8 *, u32, u32);
    (*(pf *)(*(u8 **)lg + 0x2c))(lg, 0x68df0c, a);
  }
  u8 *e = c;
  if (!e) {
    e = vcall<u8 *>(self, 0x154, a, 1u);
    if (!e) return 0;
  }
  u8 *p = (u8 *)ext_4cbe40(e);
  vcall<void>(p, 0x70, (u32)e, 0xffffffffu);
  return (u32)p;
}
PCREG(48b700, fn48b700);

// 0x4d86c0, thiscall(a, b) ret 8, bool: p = this->slot0xc(a); false when null. m = [p]: when null returns true. Else m->slot0x4c(&it); item = [p]->slot0x5c(&it); while it[0] != 0: item->slot0x10(b); item = [p]->slot0x5c(&it). Returns true.
static bool THISCALL fn4d86c0(u8 *self, u32 a, u32 b) {
  u32 it[3];
  u8 *p = vcall<u8 *>(self, 0xc, a);
  if (!p) return false;
  u8 *m = *(u8 **)p;
  if (!m) return true;
  vcall<void>(m, 0x4c, (u32)it);
  u8 *item = vcall<u8 *>(*(u8 **)p, 0x5c, (u32)it);
  if (it[0] == 0) return true;
  do {
    vcall<void>(item, 0x10, b);
    item = vcall<u8 *>(*(u8 **)p, 0x5c, (u32)it);
  } while (it[0] != 0);
  return true;
}
PCREG(4d86c0, fn4d86c0);

// 0x4f4c20, thiscall(a) ret 4: ext_4f9c90(this, a); reads from the stream a: ext_4e11e0(a, &mode, 1), ext_4e12e0(a, this+0x8f, 1), then two ext_4e12e0 on the (cleared) argument slot, ext_4e1b30(a);
// [this+0x70] = 0x10 when mode == 1, else 1.
static void THISCALL fn4f4c20(u8 *self, u32 a) {
  u8 *obj = (u8 *)a;
  u32 mode;
  ext_4f9c90(self, obj);
  ext_4e11e0(obj, &mode, 1);
  ext_4e12e0(obj, self + 0x8f, 1);
  a = 0;
  ext_4e12e0(obj, &a, 1);
  ext_4e12e0(obj, &a, 1);
  ext_4e1b30(obj);
  *(u32 *)(self + 0x70) = mode == 1 ? 0x10 : 1;
}
PCREG(4f4c20, fn4f4c20);
