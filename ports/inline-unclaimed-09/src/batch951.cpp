// batch951.cpp - area 56, claim A10: ZFFSearchLightGroup::Alarm(float*, S*) (0x5c61b0). thiscall, two stack arguments, ret 8.
// Calls are unverified (GUESS recording stubs in the spec). The original's push of edi before the list's begin call saves edi.
#include "ff.h"

extern "C" void THISCALL ext_5c78e0(u8 *self, u8 *s);

typedef void(THISCALL *ListBegin)(u8 *self, u32 *flag);           // list vt+0x4c (one argument; edi is saved, not passed)
typedef u32(THISCALL *ListNext)(u8 *self, u32 *flag);             // list vt+0x5c (returns the id)
typedef void(THISCALL *Call12c)(u8 *self, u32 id, u32 w, u8 *l);   // this+0x44 vt+0x12c

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5c61b0, ZFFSearchLightGroup::Alarm (medium name; GUESS on the roles of the arguments; see docs/20-unclaimed-56.md A10).
static void THISCALL searchLightAlarm(u8 *self, float *a, u8 *s) {
  ext_5c78e0(self, s);
  float x = *(float *)(self + 0x6d) * G(float, 0x67862c);
  s32 t = (s32)x;
  u32 gv = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
  u32 v = gv - (u32)t;
  *(float *)(s + 0x28) = (float)(s32)v * G(float, 0x6785e4);
  u32 l[4];
  l[0] = 0x6a549cu;
  l[1] = *(u32 *)(a + 0);
  l[2] = *(u32 *)(a + 1);
  l[3] = *(u32 *)(a + 2);
  u8 *list = *(u8 **)(s + 0xc);
  if (list) {
    u32 flag = 0;
    ((ListBegin)slot(list, 0x4c))(list, &flag);
    u32 id = ((ListNext)slot(list, 0x5c))(list, &flag);
    while (flag != 0) {
      u8 *o = *(u8 **)(self + 0x44);
      ((Call12c)slot(o, 0x12c))(o, id, (u32)*(u16 *)0x71433c, (u8 *)l);
      list = *(u8 **)(s + 0xc);
      id = ((ListNext)slot(list, 0x5c))(list, &flag);
    }
  }
}
PCREG(5c61b0, searchLightAlarm);
