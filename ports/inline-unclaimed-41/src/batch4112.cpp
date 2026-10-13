// batch4112.cpp - unclaimed-41 batch 12 (slice 13): 0x507510 (name not in the map; GUESS).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *table, u32 index);   // array accessor, original code

// 0x507510 (GUESS name): thiscall, one stack argument x (ret 4). With s = [x+4]:
//   v1 = (acc(s,0), acc(s,1), acc(s,2)) values; v2 = (acc(s,3), acc(s,4), acc(s,5)) values; v6 = acc(s,6) value;
//   f = (C1 > v6) ? C1 : ((C2 < v6) ? C2 : v6), with C1 at 0x67a284 and C2 at 0x680a70;
//   o = [this+0x18]: o.vt[+0x624](f); o.vt[+0x630](&v28) (writes v28); o.vt[+0x5e8](&v2); o.vt[+0x5e0](&v28, &v1).
static void THISCALL fn507510(u8 *self, u8 *x) {
  u8 *s = *(u8 **)(x + 4);
  u8 *p2 = ext_5003d0(s, 2);
  u8 *p1 = ext_5003d0(s, 1);
  u8 *p0 = ext_5003d0(s, 0);
  float v1[3] = {*(float *)p0, *(float *)p1, *(float *)p2};
  u8 *p5 = ext_5003d0(s, 5);
  u8 *p4 = ext_5003d0(s, 4);
  u8 *p3 = ext_5003d0(s, 3);
  float v2[3] = {*(float *)p3, *(float *)p4, *(float *)p5};
  u8 *p6 = ext_5003d0(s, 6);
  float v6 = *(float *)p6;
  float c1 = G(float, 0x67a284);
  float c2 = G(float, 0x680a70);
  float f = (c1 > v6) ? c1 : ((c2 < v6) ? c2 : v6);
  u8 *o = *(u8 **)(self + 0x18);
  typedef void(THISCALL * v1_t)(u8 *, u32);
  typedef void(THISCALL * v2_t)(u8 *, u32, u32);
  (*(v1_t *)(*(u32 *)o + 0x624))(o, fbits(f));
  float v28[3] = {0.0f, 0.0f, 0.0f};
  (*(v1_t *)(*(u32 *)o + 0x630))(o, (u32)v28);
  (*(v1_t *)(*(u32 *)o + 0x5e8))(o, (u32)v2);
  (*(v2_t *)(*(u32 *)o + 0x5e0))(o, (u32)v28, (u32)v1);
}
PCREG(507510, fn507510);
