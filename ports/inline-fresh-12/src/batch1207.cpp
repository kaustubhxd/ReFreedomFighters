// batch1207.cpp - fresh slice 12, batch 7. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // sized operator delete
extern "C" u32 THISCALL ext_659c00(u8 *self);                           // release handle (batch1201 port; runs here)
extern "C" void THISCALL ext_659bb0(u8 *self);                          // ret 0
extern "C" void FASTCALL ext_43e8e0(void *out, u8 *a, u8 *b);           // fastcall (out, a) + 1 stack word, ret 4
extern "C" void FASTCALL ext_43e920(void *out, u8 *a, u8 *b);           // same shape
extern "C" u8 THISCALL ext_4f0ce0(u8 *self, u8 *s);                     // ret 4, bool in AL
extern "C" u32 THISCALL ext_562c20(u8 *self, u32 v);                    // ret 4
extern "C" void THISCALL ext_57f750(u8 *self);                          // ret 0

// 0x616cc0: scalar deleting destructor: vtable 0x6bdde8, 0x659c00(+0x24), 0x659bb0(+0xc), base vtable 0x6bdc40, sized
// delete 0x30 when bit 0 of flags is set. The SEH frame (fs:[0]) only guards the member calls. ret 4.
static u8 *THISCALL sdd616cc0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6bdde8;
  ext_659c00(self + 0x24);
  ext_659bb0(self + 0xc);
  *(u32 *)self = 0x6bdc40;
  if (flags & 1) ext_634273(self, 0x30);
  return self;
}
PCREG(616cc0, sdd616cc0);

// 0x43fa00: evaluates 0x43e8e0 and 0x43e920 on (+8)->+0x30/+0x40 into scratch locals (results unused), calls slot 0,
// and when (+8)->+0x4c is not 0.0 (unordered counts as not equal) evaluates both again.
static void THISCALL f43fa00(u8 *self) {
  u8 tmp[0x30];
  u8 *t = *(u8 **)(self + 8);
  ext_43e8e0(tmp + 0x24, t + 0x30, t + 0x40);
  t = *(u8 **)(self + 8);
  ext_43e920(tmp + 0x18, t + 0x30, t + 0x40);
  vcall<u32>(self, 0);
  t = *(u8 **)(self + 8);
  if (!(*(float *)(t + 0x4c) == G(float, 0x6785d0))) {
    ext_43e8e0(tmp + 0xc, t + 0x30, t + 0x40);
    t = *(u8 **)(self + 8);
    ext_43e920(tmp, t + 0x30, t + 0x40);
  }
}
PCREG(43fa00, f43fa00);

// 0x4f4680: with +0x97 temporarily set to +0xac: s->slot 0x44(+0xb0), ok = 0x4f0ce0(s); +0x97 restored. On ok:
// s->slot 0x5c(+0xac, or the empty string 0x677b5a) and true. ret 4.
static bool THISCALL f4f4680(u8 *self, u8 *s) {
  u32 saved = *(u32 *)(self + 0x97);
  u32 b0 = *(u32 *)(self + 0xb0);
  *(u32 *)(self + 0x97) = *(u32 *)(self + 0xac);
  vcall<u32>(s, 0x44, b0);
  u8 ok = ext_4f0ce0(self, s);
  *(u32 *)(self + 0x97) = saved;
  if (!ok) return false;
  u32 nm = *(u32 *)(self + 0xac);
  vcall<u32>(s, 0x5c, nm ? nm : 0x677b5a);
  return true;
}
PCREG(4f4680, f4f4680);

// 0x57f500: v != 1 -> 0x562c20(v); v == 1 -> b = engine->slot 0xbc() twice (a, b); b->slot 0xbc(!a->slot 0xb8());
// 0x57f750(this); returns false. ret 4.
static u32 THISCALL f57f500(u8 *self, u32 v) {
  if (v != 1) return ext_562c20(self, v);
  u8 *a = vcall<u8 *>(G(u8 *, 0x70039c), 0xbc);
  u8 *b = vcall<u8 *>(G(u8 *, 0x70039c), 0xbc);
  u8 on = vcall<u8>(a, 0xb8);
  vcall<u32>(b, 0xbc, (u32)(on == 0));
  ext_57f750(self);
  return 0;
}
PCREG(57f500, f57f500);
