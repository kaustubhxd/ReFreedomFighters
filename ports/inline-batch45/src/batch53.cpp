// batch53.cpp - shoot tree, inline session batch 53: ZFFHERO::ControlWeapons (the shoot root) and
// ZFFHERO::ForwardEventToFollowers.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallU0)(void *self);
typedef u8(THISCALL *vcallB0)(void *self);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallP)(void *self, float *p);
typedef void(THISCALL *vcallEvt)(void *self, u32 evt, void *data, u32 z);

struct Quad { u32 a, b, c, d; };   // passed by value: (0, 0, 0, -1)
typedef void(THISCALL *vcallFireAt)(void *self, float *aim, float spread, Quad q);
typedef void(THISCALL *vcallFireIdle)(void *self, float f, Quad q);

extern "C" void THISCALL ext_5cf690(u8 *cam, float *out);                 // GetFireAimPos (batch 52)
extern "C" void THISCALL ext_591820(u8 *self, u32 evt, void *data);       // ForwardEventToFollowers

// 0x591820 ZFFHERO::ForwardEventToFollowers(unsigned short evt, void *data), thiscall, ret 8. The follower list at
// +0xa16 holds a count, then 0x30-byte records from +0xa1a whose first dword is the follower; each gets its slot
// 0x128 (evt, data, 0). The end is re-read every pass. evt is forwarded as the whole stack dword.
static void THISCALL forwardEventToFollowers(u8 *self, u32 evt, void *data) {
  u8 *base = self + 0xa16;
  for (u8 *e = self + 0xa1a; e != base + 4 + *(s32 *)base * 0x30; e += 0x30) {
    u8 *f = *(u8 **)e;
    ((vcallEvt)VT(f, 0x128))(f, evt, data, 0);
  }
}
PCREG(591820, forwardEventToFollowers);

static inline bool gunReady(u8 *w) {
  if (!((vcallBU)VT(w, 0x1e0))(w, 0x1007d2))
    return false;
  u8 *m = (u8 *)((vcallU0)VT(w, 0x350))(w);
  return ((vcallB0)VT(m, 0x328))(m) != 0;
}

// 0x590240 ZFFHERO::ControlWeapons(), thiscall, result in al: 0 with no held item (slot 0x504), else 1.
static u8 THISCALL controlWeapons(u8 *self) {
  u8 *w = (u8 *)((vcallU0)VT(self, 0x504))(self);
  if (!w)
    return 0;
  u8 armed = 0;
  if (gunReady(w)) {
    if (self[0x669] && ((vcallU0)VT(self, 0x3f0))(self) == 0xd && ((vcallU0)VT(w, 0x35c))(w) != 0)
      ((vcallV0)VT(self, 0x3dc))(self);
    if (((vcallUU)VT(self, 0x560))(self, (u32)w) != 0 && ((vcallU0)VT(w, 0x35c))(w) == 0)
      goto reload;
    if (((vcallU0)VT(w, 0x35c))(w) != 0 && !((vcallB0)VT(w, 0x354))(w)) {
      if (((vcallU0)VT(self, 0x3f0))(self) != 0)
        return 1;
      ((vcallVU)VT(self, 0x4f0))(self, (u32)w);
      return 1;
    }
    armed = 1;
  }
  if (((vcallU0)VT(self, 0x3f0))(self) != 0)
    return 1;
  {
    float aim[3];
    Quad q = {0, 0, 0, 0xffffffffu};
    if ((self[0x669] && self[0x66b]) || self[0x7f0]) {
      ext_5cf690(*(u8 **)(self + 0x85a), aim);
      ((vcallP)VT(self, 0x65c))(self, aim);
      ext_591820(self, *(u16 *)(self + 0x7e0), 0);
      return 1;
    }
    if (*(float *)(self + 0x813) != 0.0f) {
      ((vcallVU)VT(self, 0x518))(self, 0);
      s32 until = (s32)((*(float *)(self + 0x813) + 1.0f) * 1024.0f);
      if (until > *(s32 *)(G(u8 *, 0x70039c) + 0x40)) {
        aim[0] = 0.0f;
        aim[1] = 120.0f;
        aim[2] = 0.0f;
        ext_5cf690(*(u8 **)(self + 0x85a), aim);
        ((vcallP)VT(self, 0x8c))(self, aim);
        ((vcallFireAt)VT(self, 0x4b0))(self, aim, *(float *)(self + 0x829), q);
        return 1;
      }
      ((vcallFireIdle)VT(self, 0x4b4))(self, 1.0f, q);
      *(u32 *)(self + 0x813) = 0;
      return 1;
    }
    u8 *cam = *(u8 **)(self + 0x85a);
    if (cam[0xb45] && armed) {
      ext_5cf690(cam, aim);
      ((vcallP)VT(self, 0x8c))(self, aim);
      ((vcallFireAt)VT(self, 0x4b0))(self, aim, *(float *)(self + 0x829), q);
    } else {
      ((vcallFireIdle)VT(self, 0x4b4))(self, 1.0f, q);
    }
  }
  if (!gunReady(w))
    return 1;
  if (((vcallUU)VT(self, 0x560))(self, (u32)w) == 0)
    return 1;
  {
    u32 clip = ((vcallU0)VT(w, 0x364))(w);
    if (((vcallU0)VT(w, 0x35c))(w) == clip)
      return 1;
  }
reload:
  if (((vcallU0)VT(self, 0x3f0))(self) == 0)
    ((vcallVU)VT(self, 0x4ec))(self, (u32)w);
  return 1;
}
PCREG(590240, controlWeapons);
