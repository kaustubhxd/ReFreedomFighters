// batch33079.cpp - h3 (Sonnet) batch 33079: tier H float/SSE functions
#include "ff.h"

extern "C" u32 THISCALL ext_4dcd70(u8 *self, u32 a);               // ret 4

#define SYS (*(u8 **)0x70039c)
#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x5d13f0: thiscall(int a) ret 4: a != 0: byte [this+0xb34]=1; byte [this+0xa71] = (1.2207e-4 >= [this+0xb23]); [this+0xb23] = (float)a / 127.0f
static void THISCALL fn5d13f0(u8 *self, s32 a) {
  if (a == 0) return;
  float old = *(float *)(self + 0xb23);
  self[0xb34] = 1;
  self[0xa71] = 0.0001220703125f >= old;
  *(float *)(self + 0xb23) = (float)a / 127.0f;
}
PCREG(5d13f0, fn5d13f0);

// 0x4f38e0: thiscall(p) ret 4: g=[0x70039c]: [g+0x9e7] = (float)[g+0x6f] / p[0]; [g+0x9eb] = (float)[g+0x73] / p[1]; tail this->slot 0x304(p)
static u32 THISCALL fn4f38e0(u8 *self, float *p) {
  u8 *g = SYS;
  *(float *)(g + 0x9e7) = (float)*(s32 *)(g + 0x6f) / p[0];
  g = SYS;
  *(float *)(g + 0x9eb) = (float)*(s32 *)(g + 0x73) / p[1];
  return vcall<u32>(self, 0x304, (u32)p);
}
PCREG(4f38e0, fn4f38e0);

// 0x5d1300: thiscall(int a) ret 4: a != 0: byte [this+0xb34]=1; byte [this+0xa71] = ([this+0xb23] >= 1.2207e-4); [this+0xb23] = -((float)a / 127.0f)
static void THISCALL fn5d1300(u8 *self, s32 a) {
  if (a == 0) return;
  float old = *(float *)(self + 0xb23);
  self[0xb34] = 1;
  self[0xa71] = old >= 0.0001220703125f;
  *(u32 *)(self + 0xb23) = fbits((float)a / 127.0f) ^ 0x80000000u;
}
PCREG(5d1300, fn5d1300);

// 0x467f20: thiscall: id=[this+0x153]; id && o=table->slot 0x60(id) && 0.1f > [o+0x70] (ordered): [this+0x153]=0
static void THISCALL fn467f20(u8 *self) {
  u32 id = *(u32 *)(self + 0x153);
  if (!id) return;
  u8 *o = vcall<u8 *>(SYS_TABLE, 0x60, id);
  if (!o) return;
  if (0.10000000149011612f > *(float *)(o + 0x70)) *(u32 *)(self + 0x153) = 0;
}
PCREG(467f20, fn467f20);

// 0x52a270: thiscall(float a) ret 4: x=[+0x31]+[+0x14]+a; [this+8] = ([+0x35] > x) ? [+0x35] : minss([+0x39], x); tail 0x4dcd70([[this+0x18]+8], this+4)
static u32 THISCALL fn52a270(u8 *self, float a) {
  float x = *(float *)(self + 0x31);
  x += *(float *)(self + 0x14);
  x += a;
  float hi = *(float *)(self + 0x35);
  float v;
  if (hi > x) {
    v = hi;
  } else {
    float lo = *(float *)(self + 0x39);
    v = lo < x ? lo : x;
  }
  *(float *)(self + 8) = v;
  return ext_4dcd70(*(u8 **)(*(u8 **)(self + 0x18) + 8), (u32)(self + 4));
}
PCREG(52a270, fn52a270);

// 0x441890: thiscall(float a) ret 4: v=[this+0x88]; v == 0 ? ([0x54]=1.0, [0x5c]=2.0) : (a'=a*100; [0x54]=a'; [0x5c]=(v/0.78125)*a')
static void THISCALL fn441890(u8 *self, float a) {
  float v = *(float *)(self + 0x88);
  if (v == 0.0f) {
    *(u32 *)(self + 0x54) = 0x3f800000;
    *(u32 *)(self + 0x5c) = 0x40000000;
    return;
  }
  float w = v / 0.78125f;
  float ap = a * 100.0f;
  float r = w * ap;
  *(float *)(self + 0x54) = ap;
  *(float *)(self + 0x5c) = r;
}
PCREG(441890, fn441890);

// 0x4f6820: thiscall: byte [this+0x50] set when both [0x50],[0x51] are 0; x=[sysobj+0x48]*[this+0x4c]+[o+0xa3]; o->slot 0x374(x, 1)
static u32 THISCALL fn4f6820(u8 *self) {
  if (self[0x50] == 0 && self[0x51] == 0) self[0x50] = 1;
  u8 *g = SYS;
  u8 *o = *(u8 **)(self + 0x44);
  float x = *(float *)(g + 0x48) * *(float *)(self + 0x4c);
  x += *(float *)(o + 0xa3);
  return vcall<u32>(o, 0x374, fbits(x), 1u);
}
PCREG(4f6820, fn4f6820);

// 0x462fd0: thiscall(i) ret 4 float (st0): [this+0x6c]->slot 0x58(this); b=this->slot 0x2cc(); (b[48i+0x14] * b[48i+0x10]) * b[48i+0x18] in x87 double precision
static double THISCALL fn462fd0(u8 *self, s32 i) {
  vcall<u32>(*(u8 **)(self + 0x6c), 0x58, (u32)self);
  u8 *b = vcall<u8 *>(self, 0x2cc);
  u8 *e = b + i * 48;
  double x = (double)*(float *)(e + 0x14);
  x = x * (double)*(float *)(e + 0x10);
  x = x * (double)*(float *)(e + 0x18);
  return x;
}
PCREG(462fd0, fn462fd0);
