// batch6526.cpp - unclaimed-65: batch 26 (docs/20-unclaimed-65.md, claim 20): ZItemWeapon::OwnerDraw (0x46fda0), the whole function
// lifted; branch group 1 (the slot 0x20 result is zero, the tail call 0x46f9d0) is the first one verified (see the doc for the rest).
// The /GS cookie 0x633654 is not reproduced (the spec patches it to a ret).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void THISCALL ext_46f9d0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);  // seven stack args (ret 0x1c)
extern "C" void FASTCALL ext_4dfd10(u8 *out, u8 *in);                 // fastcall, ret 0
extern "C" void FASTCALL ext_4de480(u8 *self, u32 in);                // fastcall, ret 0 (tail jmp to 0x4419f0)
extern "C" void FASTCALL ext_441970(u8 *out, u8 *in, u32 s);          // fastcall, one stack argument (ret 4)
extern "C" void FASTCALL ext_441940(u8 *out, u8 *in);                 // fastcall, ret 0
extern "C" void FASTCALL ext_4de440(u8 *out, u8 *in, u32 s);          // fastcall, one stack argument (ret 4)
extern "C" void FASTCALL ext_43e920(u8 *out, u32 in, u32 s);          // PSVECSubtract, fastcall, one stack argument (ret 4)
extern "C" void THISCALL ext_4daa70(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);  // five stack arguments (ret 0x14)

// 0x46fda0, ZItemWeapon::OwnerDraw(p8, pc, p10, p14, p18, p1c, p20). See docs/20-unclaimed-65.md (claim 20) for the frame map.
static void THISCALL ownerDraw(u8 *self, u32 p8, u32 pc, u32 p10, u32 p14, u32 p18, u32 p1c, u32 p20) {
  u32 L70 = 0;
  u8 L7c[0x10];
  u8 L58[0x24];
  u8 L34[0x24];
  u8 L10[0x10];

  // group 1: the slot 0x20 of p10 returns zero: the tail call 0x46f9d0 with the same seven arguments (46feec)
  if ((vc0((u8 *)p10, 0x20) & 0xff) == 0) {
    ext_46f9d0(self, p8, pc, p10, p14, p18, p1c, p20);
    return;
  }

  // the flags of self+8 (test 0x2c00 on [obj+0x3c]) end the routine
  if (*(const u32 *)(*(u8 **)(self + 8) + 0x3c) & 0x2c00) return;

  u8 *obj = (u8 *)vc0(self, 0x2dc);
  if (obj == nullptr) obj = self;
  ext_4dfd10(L34, *(u8 **)(obj + 8));
  ext_4de480(L34, p18);
  ext_441970(L10, *(u8 **)(obj + 8) + 0x24, (u32)L34);
  ext_43e920(L7c, p1c, (u32)L10);

  // the object at self+0xd9: slots 0x4c and 0x5c (the 0x5c result feeds the render slot 0x58)
  if (*(u8 **)(self + 0xd9) == nullptr) return;
  vc1(*(u8 **)(self + 0xd9), 0x4c, (u32)&L70);
  u32 last = vc1(*(u8 **)(self + 0xd9), 0x5c, (u32)&L70);
  if (L70 == 0) return;
  do {
    u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *res = (u8 *)vc1(render, 0x58, last);
    u8 *o = *(u8 **)(res + 8);
    if (*(const u32 *)(o + 0x6c) != 0 && (*(const u32 *)(o + 0x3c) & 0x2c00) == 0) {
      ext_441970(L10, o + 0x24, (u32)L34);
      ext_441940(L10, L7c);
      ext_4de440(L58, o, (u32)L34);
      ext_4daa70(o, p10, p14, (u32)L58, (u32)L10, 0);
    }
    last = vc1(*(u8 **)(self + 0xd9), 0x5c, (u32)&L70);
  } while (L70 != 0);
}

PCREG(46fda0, ownerDraw);
