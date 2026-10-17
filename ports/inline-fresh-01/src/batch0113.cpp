// batch0113.cpp - fresh-01 batch 13 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 arr, u32 i);                 // array element pointer (checked)
extern "C" u32 THISCALL ext_5002f0(u32 *e, u32 v);                   // script value set
extern "C" u32 THISCALL ext_5979c0(u32 obj);                         // counts list entries whose type is 5
extern "C" u8 THISCALL ext_4db9e0(u32 geom);                         // ZBaseGeom::IsMovingObject

typedef void (*handlerFn)();
typedef void (*log3Fn)(void *, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x4bc090, ZSoundRandomVolume::Load(ZLoadGame*): clears bit 0x40 of +4; load slot 0x48 into a local, stored at
// +0x48; slot 0x50 into +0x4c, +0x79, +0x50, +0x54, +0x58, +0x5c, +0x60; slot 0x48 into +0x64, +0x68; slot 0x50
// into +0x6c, +0x70, +0x74; slot 0x68 into +0x78. Returns 1 (al).
static u8 THISCALL soundRandomVolumeLoad(u8 *self, u8 *load) {
  u32 tmp;
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(load, 0x48, &tmp);
  *(u32 *)(self + 0x48) = tmp;
  vcall<void>(load, 0x50, self + 0x4c);
  vcall<void>(load, 0x50, self + 0x79);
  vcall<void>(load, 0x50, self + 0x50);
  vcall<void>(load, 0x50, self + 0x54);
  vcall<void>(load, 0x50, self + 0x58);
  vcall<void>(load, 0x50, self + 0x5c);
  vcall<void>(load, 0x50, self + 0x60);
  vcall<void>(load, 0x48, self + 0x64);
  vcall<void>(load, 0x48, self + 0x68);
  vcall<void>(load, 0x50, self + 0x6c);
  vcall<void>(load, 0x50, self + 0x70);
  vcall<void>(load, 0x50, self + 0x74);
  vcall<void>(load, 0x68, self + 0x78);
  return 1;
}
PCREG(4bc090, soundRandomVolumeLoad);

// 0x555290 (script native, unnamed): element 0 must be type 0 or 1 (else log 0x69c8e0:0x104 and the handler / int3);
// h = element 0 value, f = element 1 value; o = render slot 0x58(h); r = -1, or when o and o+0x852 are set,
// r = [o+0x852]+0x1fae, minus 0x5979c0(o+0x852) when f != 0; result element 0 of +8 set to r.
static void THISCALL native555290(u8 *self, u8 *p) {
  u32 *e0 = ext_5003d0(*(u32 *)(p + 4), 0);
  u8 t = *((u8 *)e0 + 4);
  if (t != 0 && t != 1) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x69c8e0u, 0x104u);
    (*(log3Fn *)(*(u8 **)lg + 0x2c))(lg, 0x69c6b0, 0x69c938);
    handlerFn h = G(handlerFn, 0x7003b0);
    if (!h) __builtin_debugtrap();
    else h();
  }
  u32 h0 = *e0;
  u32 f = *ext_5003d0(*(u32 *)(p + 4), 1);
  u32 r = 0xffffffffu;
  u8 *o = vcall<u8 *>(render(), 0x58, h0);
  if (o) {
    u32 s = *(u32 *)(o + 0x852);
    if (s) {
      r = *(u32 *)(s + 0x1fae);
      if (f) r -= ext_5979c0(s);
    }
  }
  ext_5002f0(ext_5003d0(*(u32 *)(p + 8), 0), r);
}
PCREG(555290, native555290);

// 0x63e850, ZDrawBase::GeomEnter(ZGeomDrawEntry*): clears the entry's slot index (+6, 0xffff = none) and the slot
// table word +0x270+4*i; sets bit 1 of +5; entry word 0 = [[0x70039c]+0x3c]; list +0x1f0 slot 8(&entry); geom
// +0x38 gets flag 0x1000; moving geoms (flags 0x40040000 or IsMovingObject) go to list +0x1b4; entry +0x3c bit 1
// to +0x1dc; entry +0x3f to +0x1c8. The entry pointer is re-read from its stack slot after each list call.
static void THISCALL drawBaseGeomEnter(u8 *self, u8 *entry) {
  u8 *ent = entry;
  u16 i = *(u16 *)(ent + 6);
  if (i != 0xffff) {
    *(u16 *)(ent + 6) = 0xffff;
    *(u32 *)(self + (u32)i * 4 + 0x270) = 0;
  }
  ent[5] |= 1;
  *(u32 *)ent = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  vcall<void>(self + 0x1f0, 8, &ent);
  u8 *g = *(u8 **)(ent + 0x38);
  *(u32 *)(g + 0x3c) |= 0x1000;
  if ((*(u32 *)(g + 0x3c) & 0x40040000) || ext_4db9e0((u32)g)) {
    u8 *tmp = ent;
    vcall<void>(self + 0x1b4, 8, &tmp);
  }
  if (ent[0x3c] & 1) vcall<void>(self + 0x1dc, 8, &ent);
  if (ent[0x3f]) vcall<void>(self + 0x1c8, 8, &ent);
}
PCREG(63e850, drawBaseGeomEnter);

// 0x657490, ZPrimControlGC::GetPrimTextureAnimData(unsigned int, unsigned int*): prim = slot 0xc(id); fails (0) when
// prim+2 is set; else looks up the textures +4 (u16), +0x60, +0x68 in [[0x70039c]+0x1aa3]+0x14 (slot 4(id, 0)) and
// takes word 0 of each one's +0x3c data (0 when missing); *out = unsigned max of the three; returns out != 0.
static u32 texFrames(u32 id) {
  u8 *mgr = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x14);
  u8 *t = vcall<u8 *>(mgr, 4, id, 0u);
  if (t && *(u32 **)(t + 0x3c)) return **(u32 **)(t + 0x3c);
  return 0;
}
static u8 THISCALL primTextureAnimData(u8 *self, u32 id, u32 *out) {
  u8 *prim = vcall<u8 *>(self, 0xc, id);
  if (*(u16 *)(prim + 2)) return 0;
  u32 a = texFrames(*(u16 *)(prim + 4));
  u32 b = texFrames(*(u32 *)(prim + 0x60));
  u32 c = texFrames(*(u32 *)(prim + 0x68));
  u32 m = c;
  if (b > m) m = b;
  if (a > m) m = a;
  *out = m;
  return m != 0;
}
PCREG(657490, primTextureAnimData);
