// batch38011.cpp - cascade s8 batch 38011: 0x5c8a80 (property getter/setter dispatch by id).
#include "ff.h"

extern "C" void THISCALL ext_5c82a0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5c8470(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5c87f0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5c90b0(u8 *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5c9130(u8 *self, u32 a, u32 f);   // ret 8
extern "C" void THISCALL ext_5c9330(u8 *self, u32 a);   // ret 4
extern "C" u32 THISCALL ext_5c94f0(u8 *self);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ID(addr) G(u16, addr)
#define ENG G(u8 *, 0x70039c)

// 0x5c8a80, thiscall(id, arg) ret 8, returns 0: dispatches on the u16 id against eleven id globals (0x714350..0x71437c); most cases read a field of this into *arg or forward
// arg to a helper. Case 0x714360 maps two ids through the table object (engine +0x9b slot 0x58) and calls this[0x44] slot 0x288; case 0x714374 logs when +0x88 is set and
// differs from arg, else calls 0x5c9130(this, arg, 2.0f).
static u32 THISCALL fn5c8a80(u8 *self, u32 idarg, u32 arg) {
  u16 id = (u16)idarg;
  if (id == ID(0x714350)) {
    *(u32 *)arg = *(u32 *)(self + 0x70);
    return 0;
  }
  if (id == ID(0x714368)) {
    *(u32 *)arg = *(u32 *)(self + 0x74);
    return 0;
  }
  if (id == ID(0x714354)) {
    ext_5c82a0(self, arg);
    return 0;
  }
  if (id == ID(0x714358)) {
    ext_5c8470(self, arg);
    return 0;
  }
  if (id == ID(0x71435c)) {
    ext_5c87f0(self, arg);
    return 0;
  }
  if (id == ID(0x714360)) {
    u8 *t = *(u8 **)(ENG + 0x9b);
    u32 s = SLOT(t, 0x58, v1_t)(t, *(u32 *)(self + 0x70));
    t = *(u8 **)(ENG + 0x9b);
    u32 d = SLOT(t, 0x58, v1_t)(t, arg);
    ext_5c9330(self, d);
    u8 *o = *(u8 **)(self + 0x44);
    SLOT(o, 0x288, v3_t)(o, s, 0, 1);
    if (arg == 0) *(u32 *)(self + 0x80) = 0;
    return 0;
  }
  if (id == ID(0x714364)) {
    *(u32 *)arg = ext_5c94f0(self);
    return 0;
  }
  if (id == ID(0x71436c)) {
    ext_5c90b0(self, arg);
    return 0;
  }
  if (id == ID(0x714370)) {
    if (*(u32 *)(self + 0x88) == 0 && ext_5c94f0(self) == 0) {
      *(u32 *)arg = 0;
      return 0;
    }
    *(u32 *)arg = 1;
    return 0;
  }
  if (id == ID(0x71437c)) {
    *(u32 *)arg = *(u32 *)(self + 0x88);
    return 0;
  }
  if (id == ID(0x714374)) {
    u32 v = *(u32 *)(self + 0x88);
    if (v != 0 && v != arg) {
      u8 *lg = G(u8 *, 0x700390);
      void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x6b49b8, 0x11e);
      (*(log2_t **)st)[0x2c / 4](st, 0x6b4a48);
      return 0;
    }
    ext_5c9130(self, arg, 0x40000000);
  }
  return 0;
}
PCREG(5c8a80, fn5c8a80);
