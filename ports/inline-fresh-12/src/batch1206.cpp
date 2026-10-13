// batch1206.cpp - fresh slice 12, batch 6. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"
typedef long long s64;

extern "C" u32 __attribute__((cdecl)) ext_61c790(u32 a, u32 b, u32 c, u32 d, u32 e, u8 *s);   // ret 0
extern "C" u32 __attribute__((cdecl)) ext_6206e0(u8 *s);                                       // grow buffer, ret 0
extern "C" void THISCALL ext_553d00(u8 *self);                                                 // ret 0
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 i);                                          // ret 4
extern "C" void THISCALL ext_44c2b0(u8 *self);                                                 // ret 0
extern "C" void THISCALL ext_44c370(u8 *self);                                                 // ret 0

// 0x4b0e80: once (byte +0x6c) and only while engine+0x1a9f is set: t = ((clock(+0x40) - start(+0x50)) * 0x6400 >> 10)
// * 1/1024; when t passes +0x5c and leaves the window (+0x58 - +0x54, +0x58], sets byte +0x6c.
static void THISCALL windowCheck(u8 *self) {
  if (self[0x6c]) return;
  u8 *eng = G(u8 *, 0x70039c);
  if (!*(u32 *)(eng + 0x1a9f)) return;
  s32 d = *(s32 *)(eng + 0x40) - *(s32 *)(self + 0x50);
  s32 q = (s32)(((s64)d * 0x6400) >> 10);
  float t = (float)q * G(float, 0x6785e4);
  if (*(float *)(self + 0x5c) >= t) return;
  float hi = *(float *)(self + 0x58);
  float lo = hi - *(float *)(self + 0x54);
  if (t > lo) {
    if (hi >= t) return;
  }
  if (t > hi) self[0x6c] = 1;
}
PCREG(4b0e80, windowCheck);

// 0x6211c0: cdecl wrapper of 0x61c790 (6 args, s = output buffer: cur +0xc, end +8, start +0x10). On success, when c is
// 0 a trailing space is dropped; then a NUL is appended (0x6206e0(s) grows a full buffer; failure returns 1).
static u32 __attribute__((cdecl)) fmtTerm(u32 a, u32 b, u32 c, u32 d, u32 e, u8 *s) {
  u32 r = ext_61c790(a, b, c, d, e, s);
  if (r) return r;
  if (!c) {
    u8 *p = *(u8 **)(s + 0xc);
    if (p != *(u8 **)(s + 0x10) && p[-1] == 0x20) *(u8 **)(s + 0xc) = p - 1;
  }
  if (*(u32 *)(s + 0xc) == *(u32 *)(s + 8)) {
    if (!ext_6206e0(s)) return 1;
  }
  **(u8 **)(s + 0xc) = 0;
  (*(u32 *)(s + 0xc))++;
  return 0;
}
PCREG(6211c0, fmtTerm);

// 0x494b40: when this->+0 differs from engine+0x3c: +4 = 0, engine->slot 0x190() object's slot 0x184 is called
// (cdecl, this on the stack) with (0, 4, arg), and +0 = engine+0x3c. Then +8:+0xc = engine->slot 0x1c8(0x68d798,
// 0x1471) (64-bit result). ret 4.
typedef u32(__attribute__((cdecl)) * cfn4)(u8 *, u32, u32, u32);
static void THISCALL f494b40(u32 *self, u32 arg) {
  u8 *eng = G(u8 *, 0x70039c);
  if (self[0] != *(u32 *)(eng + 0x3c)) {
    self[1] = 0;
    u8 *o = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
    (*(cfn4 *)(*(u8 **)o + 0x184))(o, 0, 4, arg);
    self[0] = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
    eng = G(u8 *, 0x70039c);
  }
  u64 r = vcall<u64>(eng, 0x1c8, 0x68d798, 0x1471);
  self[2] = (u32)r;
  self[3] = (u32)(r >> 32);
}
PCREG(494b40, f494b40);

// 0x5537c0 / 0x555fc0: makes sure +0xc is set (0x553d00(this); if still null, logs message 0x28c / 0x27c through the
// log object 0x700390), then (+0xc)->slot 0x8c / 0x88(*item(0), *item(1)) where item(i) = 0x5003d0(arg->+4, i). ret 4.
typedef void(__attribute__((cdecl)) * printfn)(u8 *, u32);
template <u32 CODE, u32 SLOT>
static void THISCALL pairCall(u8 *self, u8 *arg) {
  if (!*(u32 *)(self + 0xc)) {
    ext_553d00(self);
    if (!*(u32 *)(self + 0xc)) {
      u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6a57fc, CODE);
      (*(printfn *)(*(u8 **)pr + 0x2c))(pr, 0x6a5894);
    }
  }
  u32 *i1 = ext_5003d0(*(u8 **)(arg + 4), 1);
  u32 *i0 = ext_5003d0(*(u8 **)(arg + 4), 0);
  vcall<u32>(*(u8 **)(self + 0xc), SLOT, *i0, *i1);
}
PCREG(5537c0, (pairCall<0x28c, 0x8c>));
PCREG(555fc0, (pairCall<0x27c, 0x88>));

// 0x4bb4c0: handles id (u16) for the controller at +0x44: id == +0x48 -> unless the owner +0x55 is flagged (+0x1dc) or
// controller->+0x18->+4 == 1: 0x44c2b0(controller) and (+0x51)->slot 0x84(); id == +0x4a -> 0x44c370(controller) when
// its byte +0x20 is set, and controller->+0x18->+0x7c = +0x4c. Returns 0. ret 8.
static u32 THISCALL onId(u8 *self, u16 id, u32) {
  u8 *c = *(u8 **)(self + 0x44);
  if (!c) return 0;
  if (id == *(u16 *)(self + 0x48)) {
    u8 *e = *(u8 **)(self + 0x55);
    if ((!e || !e[0x1dc]) && *(u32 *)(*(u8 **)(c + 0x18) + 4) != 1) {
      ext_44c2b0(c);
      u8 *f = *(u8 **)(self + 0x51);
      if (f) vcall<u32>(f, 0x84);
    }
  }
  if (id == *(u16 *)(self + 0x4a)) {
    c = *(u8 **)(self + 0x44);
    if (c[0x20]) ext_44c370(c);
    *(u32 *)(*(u8 **)(*(u8 **)(self + 0x44) + 0x18) + 0x7c) = *(u32 *)(self + 0x4c);
  }
  return 0;
}
PCREG(4bb4c0, onId);
