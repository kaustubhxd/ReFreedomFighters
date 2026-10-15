// batch 78003: 0x5d28c0
#include "ff.h"

extern "C" void THISCALL ext_5d1ea0(void *);
extern "C" void THISCALL ext_4e0d80(void *, float);
extern "C" void FASTCALL ext_43e8e0(void *, void *, void *);
extern "C" void THISCALL ext_5d2630(void *, u32);
extern "C" void THISCALL ext_5cf300(void *, void *, void *);
extern "C" void THISCALL ext_5a7500(void *, float, float);

static float rf(u8 *p) { return bitsf(*(u32 *)p); }
static void wf(u8 *p, float x) { *(u32 *)p = fbits(x); }
static void THISCALL fn5d28c0(u8 *self) {
  wf(self+0xae9, rf(self+0xa54));
  *(u32 *)(self+0xaed) = *(u32 *)(self+0xa5c);
  ext_5d1ea0(self);
  u32 out[3];
  vcall<void>(self, 0x88, out);

  double a = (double)rf(self+0xa5c);
  double b = (double)rf(self+0xa54);
  double cb = crt::cos(b);
  double cx = crt::cos(a);
  float first = (float)(cb*cx);
  float second = (float)crt::sin(a);
  double sb = crt::sin(b);
  double cx2 = crt::cos(a);
  float third = (float)(sb*cx2);
  u8 *rot = self+0xa72;
  wf(rot, first); wf(rot+4, second); wf(rot+8, third);

  ext_4e0d80(rot, rf(self+0xdfd));
  ext_43e8e0(self+0xd15, (u8 *)out, rot);
  ext_4e0d80(rot, 10000.0f);
  ext_43e8e0(self+0xa7e, (u8 *)out, rot);
  if (*(u8 *)(self+0xd33)) {
    for(int i=0;i<3;i++) *(u32 *)(self + 0xa7e + 4*i)=*(u32 *)(self + 0xd15 + 4*i);
    ext_5d2630(self, *(u32 *)(self+0xd2e));
  }
  float lim = rf((u8 *)0x67da04);
  float tmp[2] = {0,0};
  ext_5cf300(self, tmp, self+0xa7e);
  float x = tmp[0], y = tmp[1];
  if (!(lim >= x)) x = 0;
  if (!(lim >= y)) y = 0;
  u32 ctrl = *(u32 *)(self+0xe18);
  if (ctrl) ext_5a7500((void *)ctrl, x, y);
  for(int i=0;i<3;i++) *(u32 *)(self + 0xd15 + 4*i)=*(u32 *)(self + 0xa7e + 4*i);
}
PCREG(5d28c0, fn5d28c0);
