// batch52006.cpp - cascade tier H, batch 52006: 0x46d070 (read/serialize a block of fields through a stream, then rescale four floats).
#include "ff.h"

extern "C" void THISCALL ext_46cee0(void *self, void *s);               // ret 4
extern "C" void THISCALL ext_4e0fd0(void *s, u32 v);                    // ret 4
extern "C" void THISCALL ext_4e11e0(void *s, void *p, u32 n);           // ret 8
extern "C" void THISCALL ext_4e12e0(void *s, void *p, u32 n);           // ret 8 (thunk to 0x4e11e0)
extern "C" void THISCALL ext_4e12f0(void *s, void *p, u32 n);           // ret 8
extern "C" void THISCALL ext_4e14a0(void *s, void *p, u32 n);           // ret 8
extern "C" u8 THISCALL ext_4e1600(void *s);                             // plain, kind in al
extern "C" void THISCALL ext_4e1b30(void *s);                           // plain

// 0x46d070, thiscall(s) ret 4: ext_46cee0(this, s); then through the stream s: 4e11e0 on +0x98 and +0x9c (n = 1), 4e0fd0([+0xa0]), kind = 4e1600(); kind (al) == 3: 4e11e0 on +0xa4;
// 4e12f0 on +0xa8, +0xac, +0xb0, +0xb4, +0xb8, +0xbc, +0xc0; 4e14a0 on +0xc4, +0xc5, +0xc6; 4e0fd0([+0xc7]); 4e12e0 on +0xcb; 4e11e0 on +0xcf, +0xd3; 4e12e0 on +0xd7; 4e1b30().
// Then [+0xc0] = 60.0 (0x67885c) / [+0xc0]; [+0xa8], [+0xb0], [+0xb4] *= 100.0 (0x67cd40).
static void THISCALL fn46d070(u8 *self, u8 *s) {
  ext_46cee0(self, s);
  ext_4e11e0(s, self + 0x98, 1);
  ext_4e11e0(s, self + 0x9c, 1);
  ext_4e0fd0(s, *(u32 *)(self + 0xa0));
  if (ext_4e1600(s) == 3) ext_4e11e0(s, self + 0xa4, 1);
  ext_4e12f0(s, self + 0xa8, 1);
  ext_4e12f0(s, self + 0xac, 1);
  ext_4e12f0(s, self + 0xb0, 1);
  ext_4e12f0(s, self + 0xb4, 1);
  ext_4e12f0(s, self + 0xb8, 1);
  ext_4e12f0(s, self + 0xbc, 1);
  ext_4e12f0(s, self + 0xc0, 1);
  ext_4e14a0(s, self + 0xc4, 1);
  ext_4e14a0(s, self + 0xc5, 1);
  ext_4e14a0(s, self + 0xc6, 1);
  u32 v = self[0xc7] | self[0xc8] << 8 | self[0xc9] << 16 | (u32)self[0xca] << 24;
  ext_4e0fd0(s, v);
  ext_4e12e0(s, self + 0xcb, 1);
  ext_4e11e0(s, self + 0xcf, 1);
  ext_4e11e0(s, self + 0xd3, 1);
  ext_4e12e0(s, self + 0xd7, 1);
  ext_4e1b30(s);
  *(float *)(self + 0xc0) = G(float, 0x67885c) / *(float *)(self + 0xc0);
  float k = G(float, 0x67cd40);
  *(float *)(self + 0xa8) = *(float *)(self + 0xa8) * k;
  *(float *)(self + 0xb0) = *(float *)(self + 0xb0) * k;
  *(float *)(self + 0xb4) = *(float *)(self + 0xb4) * k;
}
PCREG(46d070, fn46d070);
