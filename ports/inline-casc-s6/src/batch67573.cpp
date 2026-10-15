// batch67573.cpp - cascade s6 batch 67573: 0x460cb0.
#include "ff.h"

extern "C" void THISCALL ext_4764b0(u8 *o, u32 a, u32 b, u32 c);   // ctor, ret 0xc
extern "C" void THISCALL ext_476500(u8 *o);                          // plain
extern "C" void THISCALL ext_476f50(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_477480(u8 *o);
extern "C" void THISCALL ext_47f6c0(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_47f6f0(u8 *o);
extern "C" void THISCALL ext_468030(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_468080(u8 *o);
extern "C" void THISCALL ext_4654b0(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_465660(u8 *o);
extern "C" void THISCALL ext_469da0(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_46a5c0(u8 *o);
extern "C" void THISCALL ext_47fce0(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_47fd30(u8 *o);
extern "C" void THISCALL ext_460e40(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_460f90(u8 *o);
extern "C" void THISCALL ext_471b50(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_471f60(u8 *o);
extern "C" void THISCALL ext_43de40(u8 *o, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_43de70(u8 *o);

#define G32(a) (*(volatile u32 *)(a))

// 0x460cb0, cdecl() plain ret: a construct-and-destroy self test. Clears the three globals at 0x6ffa68 / 6c / 70, then builds ten stack objects with a three-zero-argument constructor and runs the matching
// second function on each, in this order: 4764b0 / 476500, 476f50 / 477480, 47f6c0 / 47f6f0, 468030 / 468080, 4654b0 / 465660, 469da0 / 46a5c0, 47fce0 / 47fd30, 460e40 / 460f90, 471b50 / 471f60 and
// 43de40 / 43de70, the last one with its first dword set to 0x6852c0 in between.
static void fn460cb0() {
  u8 a[0x10], b[0x10], c[0x10], d[0x10], e[0x10], f[0x10], g[0x10], h[0x10], i[0x10], j[0x10];
  G32(0x6ffa68) = 0;
  G32(0x6ffa6c) = 0;
  G32(0x6ffa70) = 0;
  ext_4764b0(a, 0, 0, 0);
  ext_476500(a);
  ext_476f50(b, 0, 0, 0);
  ext_477480(b);
  ext_47f6c0(c, 0, 0, 0);
  ext_47f6f0(c);
  ext_468030(d, 0, 0, 0);
  ext_468080(d);
  ext_4654b0(e, 0, 0, 0);
  ext_465660(e);
  ext_469da0(f, 0, 0, 0);
  ext_46a5c0(f);
  ext_47fce0(g, 0, 0, 0);
  ext_47fd30(g);
  ext_460e40(h, 0, 0, 0);
  ext_460f90(h);
  ext_471b50(i, 0, 0, 0);
  ext_471f60(i);
  ext_43de40(j, 0, 0, 0);
  *(u32 *)j = 0x6852c0u;
  ext_43de70(j);
}
PCREG(460cb0, fn460cb0);
