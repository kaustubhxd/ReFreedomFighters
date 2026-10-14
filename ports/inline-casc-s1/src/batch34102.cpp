// batch34102.cpp - escalation batch 34102: small wrappers 0x4e49d0, 0x5d3480, 0x4681d0, 0x4d3af0, 0x59a7e0, 0x5de230, 0x42ac96.
#include "ff.h"

extern "C" u32 THISCALL ext_4e49f0(void *self, u32 a, void *b);        // thiscall ret 8
extern "C" void THISCALL ext_5d3780(void *self);                       // thiscall, plain ret
extern "C" u32 THISCALL ext_584cc0(void *self, void *a);               // thiscall ret 4
extern "C" u32 THISCALL ext_4d24e0(void *self, u32 a, u32 b, u32 *c, u32 d);   // thiscall ret 0x10
extern "C" u32 THISCALL ext_597c40(void *self);                        // thiscall, plain ret
extern "C" u32 THISCALL ext_597d30(void *self);                        // thiscall, plain ret
extern "C" u32 THISCALL ext_5de090(void *self, u32 a);                 // thiscall ret 4
extern "C" u32 ext_42ac71(u32 a, u32 b, u32 c, u32 *va);               // cdecl

// 0x4e49d0, thiscall(a) ret 4: ext_4e49f0([this], a, this+4); returns its eax.
static u32 THISCALL fn4e49d0(u8 *self, u32 a) {
  return ext_4e49f0(*(u8 **)self, a, self + 4);
}
PCREG(4e49d0, fn4e49d0);

// 0x5d3480, thiscall(a, b) ret 8, returns 0: when the low word of a equals the word [this+0x52], ext_5d3780(this).
static u32 THISCALL fn5d3480(u8 *self, u32 a, u32 b) {
  (void)b;
  if ((u16)a == (u16)(self[0x52] | self[0x53] << 8)) ext_5d3780(self);
  return 0;
}
PCREG(5d3480, fn5d3480);

// 0x4681d0, thiscall plain: p = unaligned [this+0x1de]; when set ext_584cc0(p, this); then the unaligned dword [this+0x1de] = 0.
static void THISCALL fn4681d0(u8 *self) {
  u8 *p = (u8 *)(self[0x1de] | self[0x1df] << 8 | self[0x1e0] << 16 | (u32)self[0x1e1] << 24);
  if (p) ext_584cc0(p, self);
  self[0x1de] = 0; self[0x1df] = 0; self[0x1e0] = 0; self[0x1e1] = 0;
}
PCREG(4681d0, fn4681d0);

// 0x4d3af0, thiscall(a, b) ret 8: ext_4d24e0(this, a, 8, &b, 0) where &b is the parameter slot's address; returns its eax.
static u32 THISCALL fn4d3af0(u8 *self, u32 a, u32 b) {
  u32 bb = b;
  return ext_4d24e0(self, a, 8, &bb, 0);
}
PCREG(4d3af0, fn4d3af0);

// 0x59a7e0, thiscall(a) ret 4: byte a set: ext_597c40(this), else ext_597d30(this); returns its eax.
static u32 THISCALL fn59a7e0(u8 *self, u32 a) {
  if ((u8)a) return ext_597c40(self);
  return ext_597d30(self);
}
PCREG(59a7e0, fn59a7e0);

// 0x5de230, thiscall(a, b) ret 8, returns 0: when the low word of a equals the word at 0x7143a0, ext_5de090(this, b).
static u32 THISCALL fn5de230(u8 *self, u32 a, u32 b) {
  if ((u16)a == G(u16, 0x7143a0)) ext_5de090(self, b);
  return 0;
}
PCREG(5de230, fn5de230);

// 0x42ac96, cdecl(a, b, c, ...): ext_42ac71(a, b, 0, address of the third argument slot) (the callee walks the variable arguments through that pointer); returns its eax.
static u32 fn42ac96(u32 a, u32 b, u32 c) {
  return ext_42ac71(a, b, 0, &c);
}
PCREG(42ac96, fn42ac96);
