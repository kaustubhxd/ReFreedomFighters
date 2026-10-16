// batch210037.cpp - Sonnet-w3a: small BLOCKED rows (selector with callbacks, forwarder with branches, message router)
#include "ff.h"

extern "C" u32 THISCALL ext_562d90(u8 *self, u32 a);
extern "C" u32 ext_561c40();
extern "C" u32 STDCALL ext_561f50(u32 a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 fn62ce70(u8 *A, u32 sel, u32 p10, u32 p14, u8 *obj) {
  if (sel == 0xf) return 0;  // @62ce70_a
  typedef u32 (*CB)(u8 *, u32, u32, u32);
  if (sel == 0x12) {  // @62ce70_b
    if ((*(CB *)(obj + 0x1c))(obj, p10, p14, 0x6c01bc)) {  // @62ce70_c
      *(u32 *)A = 0x62cf00;  // @62ce70_d
      return 0;
    }
    if ((*(CB *)(obj + 0x1c))(obj, p10, p14, 0x6c01ac)) {  // @62ce70_e
      *(u32 *)A = 0x62cf40;  // @62ce70_f
      return 0;
    }
  }
  if (*(u32 *)(A + 0xc) == 0 && sel == 0x1c) return sel + 0x18;  // @62ce70_g
  *(u32 *)A = 0x51f230;  // @62ce70_h
  return 0xffffffffu;
}
PCREG(62ce70, fn62ce70);

static u32 THISCALL fn45df10(u8 *self, u8 *a, u32 p0c, u32 p10, u32 p14, u32 p18) {
  u32 al = vcall<u32>(mgr(), 0x10) & 0xff;  // @45df10_a
  if (al) return vcall<u32, u8 *, u32, u32, u32, u32>(self, 0x1b8, a, p10, p14, 0, p18);  // @45df10_b
  u32 o = vcall<u32>(self, 0x20);  // @45df10_c
  if (!o) return 0;
  u32 edi = p14;
  if (!edi) edi = *(u32 *)(self + 4);  // @45df10_d
  u8 *m = *(u8 **)(self + 0xc);
  u32 r = vcall<u32, u32, u32, u32, u32, u32>(a, 0x298, edi, p0c, ld32(m + 0x23), 0, 1);  // @45df10_e
  if (r) {
    if (vcall<u32, u32, u32>(self, 0x1b4, r, p10) & 0xff) return 0;  // @45df10_f
  }
  return r;
}
PCREG(45df10, fn45df10);

static u32 THISCALL fn57c2b0(u8 *self, u32 msg) {
  u32 r = vcall<u32>(self, 0xd8);  // @57c2b0_a
  if (r & 0xff) return r & ~0xffu;  // @57c2b0_b
  const u8 *s = (const u8 *)ld32(*(u8 **)(self + 0xf4) + 4);
  if (!s) s = (const u8 *)0x67c8e8;  // @57c2b0_c
  const u8 *t = (const u8 *)0x6aa64c;
  bool eq = true;
  for (u32 i = 0;; i++) {
    if (s[i] != t[i]) { eq = false; break; }  // @57c2b0_d
    if (s[i] == 0) break;
  }
  if (eq && (msg == 0x103 || msg == 0x102)) {  // @57c2b0_e
    u32 x = ext_561c40() & 0xff;  // @57c2b0_f
    ext_561f50(x == 0);  // @57c2b0_g
    r = vcall<u32>(self, 0xf8);  // @57c2b0_h
    return (r & ~0xffu) | 1;
  }
  return ext_562d90(self, msg);  // @57c2b0_i
}
PCREG(57c2b0, fn57c2b0);
