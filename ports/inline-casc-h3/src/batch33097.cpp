// batch33097.cpp - h3 () batch 33097: tier H float/SSE functions
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(u8 *self);                      // float in st0
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                        // eax
extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 which);            // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 v);                // ret 4
extern "C" void THISCALL ext_500360(u8 *self, u32 v);                // ret 4

// 0x5142c0: thiscall no args: byte [0xcd]==0: t=[this+0x5c]->slot 0x18() (float); [0xc8] >= t: [0xcd]=1, this->slot 0x130(u16 [0x205], 0); byte [0xcc]==0: t=slot 0x18(); 1/8192 >= t: [0xcc]=1, slot 0x130(u16 [0x203], 0)
static void THISCALL fn5142c0(u8 *self) {
  if (self[0xcd] == 0) {
    float t = vcall<float>(*(u8 **)(self + 0x5c), 0x18);
    if (*(float *)(self + 0xc8) >= t) {
      u32 w = *(u16 *)(self + 0x205);
      self[0xcd] = 1;
      vcall<u32>(self, 0x130, (u32)self, w, 0u);
    }
  }
  if (self[0xcc] == 0) {
    float t = vcall<float>(*(u8 **)(self + 0x5c), 0x18);
    if (0.0001220703125f >= t) {
      u32 w = *(u16 *)(self + 0x203);
      self[0xcc] = 1;
      vcall<u32>(self, 0x130, (u32)self, w, 0u);
    }
  }
}
PCREG(5142c0, fn5142c0);

// 0x551720: stdcall(obj, a, u32 *p) ret 0xc: b = obj->slot 0x18(a); b: c = b->slot 0x4c(); 0x5002f0(0x5003d0(c, 0), p[0]); 0x500360(0x5003d0(c, 1), p[1]); 0x500360(0x5003d0(c, 2), p[2]); return b
static u8 *STDCALL fn551720(u8 *obj, u32 a, u32 *p) {
  u8 *b = vcall<u8 *>(obj, 0x18, a);
  if (!b) return b;
  u8 *c = vcall<u8 *>(b, 0x4c);
  u32 *q = ext_5003d0(c, 0);
  ext_5002f0((u8 *)q, p[0]);
  q = ext_5003d0(c, 1);
  ext_500360((u8 *)q, p[1]);
  q = ext_5003d0(c, 2);
  ext_500360((u8 *)q, p[2]);
  return b;
}
PCREG(551720, fn551720);

// 0x4bd3f0: thiscall(a, stream) ret 8: [0x4c],[0x50] = e60; [0x64],[0x68],[0x6c],[0x70] = e80; f5 = e80; zero [0x48],[0x54],[0x5c],[0x58]; [0x80]=[0x7c]=f5; [0x60]=(float)(s32)[0x4c]; [0x74]=1; [0x78]=0; [0x84]=-1.0
static void THISCALL fn4bd3f0(u8 *self, u32 a, u8 *s) {
  (void)a;
  u32 d;
  float f;
  d = ext_4e5e60(s); *(u32 *)(self + 0x4c) = d;
  d = ext_4e5e60(s); *(u32 *)(self + 0x50) = d;
  f = ext_4e5e80(s); *(float *)(self + 0x64) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x68) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x6c) = f;
  f = ext_4e5e80(s); *(float *)(self + 0x70) = f;
  float f5 = ext_4e5e80(s);
  float c = (float)*(s32 *)(self + 0x4c);
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x58) = 0;
  *(float *)(self + 0x80) = f5;
  *(float *)(self + 0x60) = c;
  *(float *)(self + 0x7c) = f5;
  *(u32 *)(self + 0x74) = 1;
  *(u32 *)(self + 0x78) = 0;
  *(u32 *)(self + 0x84) = 0xbf800000;
}
PCREG(4bd3f0, fn4bd3f0);
