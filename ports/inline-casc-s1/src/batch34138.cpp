// batch34138.cpp - cascade tier E, batch 34138: 0x555350 (look up and toggle), 0x569f80 (per-frame state step), 0x574bc0 (query engine values and apply).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);      // ret 4
extern "C" u32 THISCALL ext_5002f0(void *self, u32 v);      // ret 4
extern "C" void THISCALL ext_562260(void *self);            // plain ret (tail jump)
extern "C" void THISCALL ext_56ac30(void *self);            // plain ret
extern "C" u32 THISCALL ext_589c20(void *self, u32 i);      // ret 4
extern "C" void THISCALL ext_59a5b0(void *self, u32 a, u32 b, u32 c);   // ret 0xc
typedef void (*hook_t)();

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x555350, stdcall(p) ret 4: e = [ext_5003d0([p+4], 0)] ; s = [[0x70039c]+0x9b]->slot0x58(e). When s is null: the logger [0x700390]->slot0x20(0x6a57fc, 0x39f) q, q->slot0x30(q, 0x6a5b64) (cdecl, ecx = vtable) and v = 0.
// Otherwise v = 0 unless s->slot0x1e0(0x2003e8) is true (low byte), then v = (u8)s->slot0x64c(). Returns ext_5002f0(ext_5003d0([p+8], 0), v).
static u32 STDCALL fn555350(u8 *p) {
  u32 *cell = (u32 *)ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *s = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *cell);
  u32 v;
  if (!s) {
    u8 *q = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6a57fcu, 0x39fu);
    typedef void (*pf)(u8 *, u32);
    (*(pf *)(*(u8 **)q + 0x30))(q, 0x6a5b64);
    v = 0;
  } else if ((u8)vcall<u32>(s, 0x1e0, 0x2003e8u)) {
    v = (u8)vcall<u32>(s, 0x64c);
  } else {
    v = 0;
  }
  u8 *o = (u8 *)ext_5003d0(*(u8 **)(p + 8), 0);
  return ext_5002f0(o, v);
}
PCREG(555350, fn555350);

// 0x569f80, thiscall plain: ext_562260(this); when [this+0x1c5] == 5: this->slot0x84()->slot0x2fc([this+0x44]) and [+0x1c5] = 0. Then unless this->slot0xd0... slot0xd8() is true (low byte): state [+0x1c5]:
// 1 -> p = [+0x1c9]; when p and p->slot0x20(0x6a75f0) low byte: [[0x70039c]+0x1907]->slot0x14(0x6a7820) when set, [+0x1c9] = 0, this->slot0xd0([+0x180]); 6 -> tail call ext_56ac30(this).
static void THISCALL fn569f80(u8 *self) {
  ext_562260(self);
  if (rd32(self + 0x1c5) == 5) {
    u8 *o = vcall<u8 *>(self, 0x84);
    vcall<void>(o, 0x2fc, rd32(self + 0x44));
    wr32(self + 0x1c5, 0);
  }
  if ((u8)vcall<u32>(self, 0xd8)) return;
  u32 st = rd32(self + 0x1c5);
  if (st == 1) {
    u8 *p = (u8 *)rd32(self + 0x1c9);
    if (!p) return;
    if (!(u8)vcall<u32>(p, 0x20, 0x6a75f0u)) return;
    u8 *q = (u8 *)rd32(G(u8 *, 0x70039c) + 0x1907);
    if (q) vcall<void>(q, 0x14, 0x6a7820u);
    wr32(self + 0x1c9, 0);
    vcall<void>(self, 0xd0, rd32(self + 0x180));
  } else if (st == 6) {
    ext_56ac30(self);
  }
}
PCREG(569f80, fn569f80);

// 0x574bc0, thiscall plain: ext_59a5b0(ext_589c20([0x7003b8], 0), 0, 0x679e6c, 0); x = [[0x70039c]+0x9b]->slot0x138(); x->slot0x88(0x68c070, &l) (l = 0 first); w = table->slot0x114(0x6a4ea0, 0, 0x6a9104, 0x22a, 0);
// [this+0x44]->slot0x12c(l, (u16)w) through the vtable read before the call.
static void THISCALL fn574bc0(u8 *self) {
  u32 l = 0;
  u32 e = ext_589c20(G(u8 *, 0x7003b8), 0);
  ext_59a5b0((void *)e, 0, 0x679e6c, 0);
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = vcall<u8 *>(t, 0x138);
  l = 0;
  vcall<void>(x, 0x88, 0x68c070u, (u32)&l);
  u8 *tgt = *(u8 **)(self + 0x44);
  u8 *vt = *(u8 **)tgt;
  u32 v = *(volatile u32 *)&l;
  t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = (u16)vcall<u32>(t, 0x114, 0x6a4ea0u, 0u, 0x6a9104u, 0x22au, 0u);
  typedef void (THISCALL *f2)(void *, u32, u32);
  (*(f2 *)(vt + 0x12c))(tgt, v, w);
}
PCREG(574bc0, fn574bc0);
