// batch34071.cpp - cascade tier E, batch 34071: 0x55c9b0 (checked forward of a slot id), 0x5764c0 (select a message by a name compare), 0x57dfb0 (lookup result bookkeeping).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *m, u32 i);       // thiscall ret 4
extern "C" void THISCALL ext_575ee0(void *self);          // thiscall, plain ret
extern "C" void THISCALL ext_562b50(void *self, u32 a);   // thiscall ret 4
extern "C" void THISCALL ext_4db500(void *self, u32 *out);   // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);          // /GS check

// 0x55c9b0, thiscall(a) ret 4: s = ext_5003d0([a+4], 0); when byte [s+4] is neither 0 nor 1: p = [0x700390]->slot0x20(0x69c8e0, 0x104); p->slot0x2c(p, 0x69c6b0, 0x69c938) (cdecl, ecx = vtable);
// the assert hook [0x7003b0] is called (int3 when null). Returns [this+0x1c]->slot0x728([s]).
static u32 THISCALL fn55c9b0(u8 *self, u8 *a) {
  u8 *s = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 t = s[4];
  if (t != 0 && t != 1) {
    u8 *p = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x69c8e0u, 0x104u);
    typedef void (*pf)(u8 *, u32, u32);
    (*(pf *)(*(u8 **)p + 0x2c))(p, 0x69c6b0, 0x69c938);
    typedef void (*hf)(void);
    hf h = G(hf, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  return vcall<u32>(*(u8 **)(self + 0x1c), 0x728, *(u32 *)s);
}
PCREG(55c9b0, fn55c9b0);

// 0x5764c0, thiscall, plain ret: nothing when byte [this+0x20b] is 0. e = [this+0x94]; when byte [e+0x103e] is 0: ext_575ee0(this); else when the string at e+0x48 equals the string at 0x6a6e5c and byte [e+0x1040] is 0:
// ext_562b50(this, 0x6a9454), otherwise ext_562b50(this, this+0x206). Then this->slot0xe8() and [this+0xdc] = 3.
static void THISCALL fn5764c0(u8 *self) {
  if (self[0x20b] == 0) return;
  u8 *e = *(u8 **)(self + 0x94);
  if (e[0x103e] == 0) {
    ext_575ee0(self);
  } else {
    const u8 *x = e + 0x48;
    const u8 *y = (const u8 *)0x6a6e5c;
    bool eq = true;
    for (;; x++, y++) {
      if (*x != *y) { eq = false; break; }
      if (*x == 0) break;
    }
    if (eq && e[0x1040] == 0)
      ext_562b50(self, 0x6a9454);
    else
      ext_562b50(self, (u32)(self + 0x206));
  }
  vcall<void>(self, 0xe8);
  *(u32 *)(self + 0xdc) = 3;
}
PCREG(5764c0, fn5764c0);

// 0x57dfb0, thiscall(a, b) ret 8, returns false: r = (this+0x264)->slot0x2c(b). Zero: [this+0x344] = b, byte [this+0x349] = 0. Else byte [this+0x349] = 1, [this+0x340] = b, o = [[0x70039c]+0x9b]->slot0x58(b),
// ext_4db500([o+8], &local); the /GS check.
static bool THISCALL fn57dfb0(u8 *self, u32 a, u32 b) {
  u32 v[4];
  u32 r = vcall<u32>(self + 0x264, 0x2c, b);   // the vtable is read from [this+0x264]
  (void)a;
  if (r == 0) {
    *(u32 *)(self + 0x344) = b;
    self[0x349] = 0;
  } else {
    self[0x349] = 1;
    *(u32 *)(self + 0x340) = b;
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tbl, 0x58, b);
    ext_4db500(*(u8 **)(o + 8), v);
  }
  ext_633654(0);
  return false;
}
PCREG(57dfb0, fn57dfb0);
