// batch1908.cpp - fresh slice 19, batch 1908 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
// SEH frames and stack cookies of the exe are not ported (the state they leave is the same).
#include "ff.h"

extern "C" void THISCALL ext_64cda0(u8 *r, u32 id);               // (no GC name; hooked)
extern "C" void THISCALL ext_4ce180(u8 *self, u32 id);            // ZDrawBase::FreeDrawId(unsigned short) (hooked)
extern "C" double VECTORCALL ext_634db2(double x, double y);      // pow thunk (jmp [0x67634c]), runs as exe code
extern "C" void THISCALL ext_44c230(u8 *s, float d);              // ZSNDOBJ::SetMinDistance (hooked)
extern "C" void *ext_41e290(u32 n);                               // operator new (cdecl; hooked)
extern "C" u8 *THISCALL ext_600d70(u8 *o, u32 name, u32 v);       // export symbol constructor (hooked)
extern "C" void THISCALL ext_5f4630(u8 *arr);                     // pointer array grow (hooked)
extern "C" void THISCALL ext_500900(u8 *self, u8 *a, u32 b);      // base constructor (hooked)
extern "C" void THISCALL ext_505d50(u8 *self);                    // (no GC name; hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x63ee70 (no GC name) (id) ret 4: each of the [+0xec] renderers at +0xf0 whose table (+0x10071)[id & 0xfff] is set gets
// 0x64cda0(id); then (+0x68)[id & 0xfff] = 0 and FreeDrawId(+0xb990, (u16)id - 1) (pushed as a full word).
static void THISCALL freeId_63ee70(u8 *self, u32 id) {
  u32 n = *(u32 *)(self + 0xec);
  if (n) {
    u8 **r = (u8 **)(self + 0xf0);
    u32 i = 0;
    do {
      if (*(u32 *)(*(u8 **)(*r + 0x10071) + (id & 0xfff) * 4)) ext_64cda0(*r, id);
      i++;
      r++;
    } while (i != *(u32 *)(self + 0xec));
  }
  u32 lo = id & 0xffff;
  (*(u32 **)(self + 0x68))[lo & 0xfff] = 0;
  ext_4ce180(self + 0xb990, lo - 1);
}
PCREG(63ee70, freeId_63ee70);

// 0x4c2e70 ZSoundExtend::SetValuesLight(): with a sound (+0x44) that has +0x1c: light flag 8 on its +0x18->+0x40 follows
// +0x64; a level +0x48 <= 0 sets +0x88 = 100 / pow(10, level / -20) (constants 0x693d60, 0x692790, 0x67da30); a min
// distance +0x54 other than 0 goes to SetMinDistance.
static void THISCALL setValuesLight_4c2e70(u8 *self) {
  u8 *s = *(u8 **)(self + 0x44);
  if (!s || !*(u32 *)(s + 0x1c)) return;
  if (*(u32 *)(self + 0x64)) *(u32 *)(*(u8 **)(s + 0x18) + 0x40) |= 8;
  else *(u32 *)(*(u8 **)(s + 0x18) + 0x40) &= ~8u;
  float v = *(float *)(self + 0x48);
  if (!(0.0f < v) && v == v) {
    float q = v / G(float, 0x67da30);
    double p = ext_634db2(G(double, 0x692790), (double)q);
    *(float *)(*(u8 **)(s + 0x18) + 0x88) = (float)(G(double, 0x693d60) / p);
  }
  float d = *(float *)(self + 0x54);
  if (d != G(float, 0x6785d0)) ext_44c230(s, d);
}
PCREG(4c2e70, setValuesLight_4c2e70);

// 0x628f30 (no GC name) cdecl (unused, begin, end, int *out): *out = 0xb; a 6-byte name "x\0m\0l\0" spelled all lower case
// sets *out = 0xc and returns 1; any capital in it returns 0 when the L is reached; anything else returns 1.
static s32 is_xml_628f30(u32, const char *b, const char *e, s32 *out) {
  *out = 0xb;
  if (e - b != 6 || b[1] != 0) return 1;
  s32 up = 0;
  if (b[0] == 'X') up = 1;
  else if (b[0] != 'x') return 1;
  if (b[3] != 0) return 1;
  if (b[2] == 'M') up = 1;
  else if (b[2] != 'm') return 1;
  if (b[5] != 0) return 1;
  if (b[4] == 'L') return 0;
  if (b[4] != 'l') return 1;
  if (up) return 0;
  *out = 0xc;
  return 1;
}
PCREG(628f30, is_xml_628f30);

// 0x601f70 CSdlDataExchange::setExportSymbol(const char *name, int v) ret 8: e = new(4) constructed by 0x600d70(name, v)
// (0 when new fails); appended to the pointer array at +4 (count +0xc, capacity +8; full grows through 0x5f4630).
static void THISCALL setExportSymbol_601f70(u8 *self, u32 name, u32 v) {
  u8 *o = (u8 *)ext_41e290(4);
  u8 *e = o ? ext_600d70(o, name, v) : 0;
  if (*(u32 *)(self + 0xc) >= *(u32 *)(self + 8)) ext_5f4630(self + 4);
  (*(u8 ***)(self + 4))[*(u32 *)(self + 0xc)] = e;
  (*(u32 *)(self + 0xc))++;
}
PCREG(601f70, setExportSymbol_601f70);

// 0x504730 (no GC name) constructor (a, b) ret 8: base 0x500900(a, b), vptr 0x69cc88, 0x505d50 when [0x700f7c] is 0;
// b is replaced through a->+0x15->vt[0x40](&b) and +0x14 = db vt[0x58](b). Returns this.
static u8 *THISCALL ctor_504730(u8 *self, u8 *a, u32 b) {
  ext_500900(self, a, b);
  *(u32 *)self = 0x69cc88;
  if (!G(u32, 0x700f7c)) ext_505d50(self);
  vcall<void>(*(u8 **)(a + 0x15), 0x40, (u32)&b);
  *(u32 *)(self + 0x14) = vcall<u32>(DB, 0x58, b);
  return self;
}
PCREG(504730, ctor_504730);
