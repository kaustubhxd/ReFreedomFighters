// batch1906.cpp - fresh slice 19, batch 1906 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);                 // sized operator delete (cdecl; hooked)
extern "C" void THISCALL ext_4dd060(u8 *g, float *v);          // (no GC name; hooked)
extern "C" double VECTORCALL ext_634d7c(double x);             // sqrt thunk (jmp [0x676330]), runs as exe code
extern "C" void THISCALL ext_4dce50(u8 *g, float r);           // ZBaseGeom::SetRadius (hooked)
extern "C" void THISCALL ext_45d5b0(u8 *self, u8 *g);          // ZGEOM::CopyData (hooked)
extern "C" void THISCALL ext_49d2c0(u8 *self);                 // (no GC name; hooked)
extern "C" void THISCALL ext_6132a0(u8 *self);                 // ZTextureManagerGC::~ZTextureManagerGC (hooked)
extern "C" void THISCALL ext_4a3b40(u8 *self);                 // constructor (hooked)
extern "C" void THISCALL ext_5b7f00(u8 *self);                 // CCheckInsideBox::CCheckInsideBox (hooked)
extern "C" void THISCALL ext_5b9380(u8 *self);                 // CFriendlyControl::CFriendlyControl (hooked)
extern "C" void THISCALL ext_4face0(u8 *self, u8 *b);          // ZFONT::CopyDataBlock (hooked)
extern "C" void THISCALL ext_4e1b20(u8 *b);                    // DBLK (no GC name; hooked)
extern "C" void THISCALL ext_4e12e0(u8 *b, u32 *out, s32 n);   // DBLK::Get(unsigned *, int) (hooked)
extern "C" void THISCALL ext_4e1b30(u8 *b);                    // DBLK::NextBlock (hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x45aff0 ZBoxPrimitive::CalcCenSize(): geom +8: 0x4dd060(+0x18), then SetRadius(sqrt(x*x + y*y + z*z) + 1.0f
// [0x678858]) from the geom's +0x40/+0x44/+0x48 (as ZCubeGrid::CalcCenSize 0x451b30 without SetCen).
static void THISCALL calcCenSize_45aff0(u8 *self) {
  ext_4dd060(*(u8 **)(self + 8), (float *)(self + 0x18));
  u8 *g = *(u8 **)(self + 8);
  float x = *(float *)(g + 0x40), y = *(float *)(g + 0x44), z = *(float *)(g + 0x48);
  float s = x * x + y * y;
  s = s + z * z;
  float r = (float)ext_634d7c((double)s);
  ext_4dce50(g, r + G(float, 0x678858));
}
PCREG(45aff0, calcCenSize_45aff0);

// 0x454d30 ZMaterialDesc::CopyData(const ZGEOM *g) ret 4: when g's class (+0xc)->+0x23 is 0x2000f0 copies twelve words
// (in the exe's order), then tail-calls ZGEOM::CopyData(g).
static void THISCALL copyData_454d30(u8 *self, u8 *g) {
  if (*(u32 *)(*(u8 **)(g + 0xc) + 0x23) == 0x2000f0) {
    static const u8 offs[12] = {0x18, 0x1c, 0x20, 0x34, 0x28, 0x30, 0x2c, 0x24, 0x3c, 0x40, 0x44, 0x48};
    for (u32 i = 0; i < 12; i++) *(u32 *)(self + offs[i]) = *(u32 *)(g + offs[i]);
  }
  ext_45d5b0(self, g);
}
PCREG(454d30, copyData_454d30);

// 0x4a37f0 ZSoundMove::Init(): +0x48 = +0x44, +0x128 = 0, +0x124 = (+0x78)->vt[0x14](), vt[0x84](+0x4c), vt[0x84](+0x58),
// vt[0x88](), +0x74 = (float)engine->+0x40 * [0x6785e4] (1/1024).
static void THISCALL init_4a37f0(u8 *self) {
  *(u32 *)(self + 0x48) = *(u32 *)(self + 0x44);
  *(u32 *)(self + 0x128) = 0;
  *(u32 *)(self + 0x124) = vcall<u32>(self + 0x78, 0x14);
  vcall<void>(self, 0x84, (u32)(self + 0x4c));
  vcall<void>(self, 0x84, (u32)(self + 0x58));
  vcall<void>(self, 0x88);
  *(float *)(self + 0x74) = (float)*(s32 *)(*(u8 **)0x70039cu + 0x40) * G(float, 0x6785e4);
}
PCREG(4a37f0, init_4a37f0);

// 0x428af0 (no GC name) (obj, dev) ret 8: dev->vt[0x18](dev, 4, &range) COM style with a DIPROPRANGE-shaped stack struct
// {0x18, 0x10, obj->+0x18, 2, -999, 999} (GUESS on the meaning: DirectInput SetProperty(DIPROP_RANGE)); returns hr >= 0.
// The stack cookie check is not ported.
typedef s32(STDCALL *setprop_t)(u8 *, u32, u32 *);
static u32 THISCALL fn_428af0(u8 *, u8 *obj, u8 *dev) {
  u32 s[6] = {0x18, 0x10, *(u32 *)(obj + 0x18), 2, 0xfffffc19u, 0x3e7};
  return (*(setprop_t *)(*(u8 **)dev + 0x18))(dev, 4, s) >= 0;
}
PCREG(428af0, fn_428af0);

// 0x48fa70 (no GC name) (no args): deletes the 32 objects at +0x48 (vt[0](1)) and clears each slot; the object at +0xc8:
// 0x49d2c0, sized delete 0x29, +0xc8 = 0; then +0xad0 = +0xad8 = 0.
static void THISCALL fn_48fa70(u8 *self) {
  u8 **p = (u8 **)(self + 0x48);
  for (u32 i = 0; i < 0x20; i++, p++) {
    if (*p) {
      vcall<void>(*p, 0, 1u);
      *p = 0;
    }
  }
  u8 *q = *(u8 **)(self + 0xc8);
  if (q) {
    ext_49d2c0(q);
    ext_634273(q, 0x29);
    *(u32 *)(self + 0xc8) = 0;
  }
  *(u32 *)(self + 0xad0) = 0;
  *(u32 *)(self + 0xad8) = 0;
}
PCREG(48fa70, fn_48fa70);

// 0x6125f0 (no GC name) scalar deleting destructor (flags) ret 4: vptr 0x6bd5a0, ~ZTextureManagerGC, vptr 0x6bd594, flag 1
// frees 0x2216c bytes; returns this. The exe's SEH frame is not ported.
static u8 *THISCALL sdtor_6125f0(u8 *self, u32 f) {
  *(u32 *)self = 0x6bd5a0;
  ext_6132a0(self);
  *(u32 *)self = 0x6bd594;
  if (f & 1) ext_634273(self, 0x2216c);
  return self;
}
PCREG(6125f0, sdtor_6125f0);

// Factories (no GC names): o = (engine db +8)->vt[0x44](incoming ecx as a stack word: GUESS, as 0x57be70); with o, the
// constructor. The exe's SEH frame and cookie are not ported.
static inline u8 *alloc_db(u8 *self) { return vcall<u8 *>(*(u8 **)(DB + 8), 0x44, (u32)self); }
static u8 *THISCALL make_4a3cf0(u8 *self) {
  u8 *o = alloc_db(self);
  if (o) ext_4a3b40(o);
  return o;
}
PCREG(4a3cf0, make_4a3cf0);
static u8 *THISCALL make_5b7fb0(u8 *self) {
  u8 *o = alloc_db(self);
  if (o) ext_5b7f00(o);
  return o;
}
PCREG(5b7fb0, make_5b7fb0);
static u8 *THISCALL make_5b94f0(u8 *self) {
  u8 *o = alloc_db(self);
  if (o) ext_5b9380(o);
  return o;
}
PCREG(5b94f0, make_5b94f0);

// 0x4ee070 ZWINOBJSPRITEHOLDER::SaveCleanup(bool b) ret 4: s = db vt[0x138](); b: s->vt[0xa0](0x697b08, 0); otherwise
// s->vt[0x60](0x697b08, db vt[0x4c](this, 4)) (s's vtable read before the db call).
static void THISCALL saveCleanup_4ee070(u8 *self, bool b) {
  if (b) {
    u8 *s = vcall<u8 *>(DB, 0x138);
    vcall<void>(s, 0xa0, 0x697b08u, 0u);
    return;
  }
  u8 *s = vcall<u8 *>(DB, 0x138);
  u8 *vt = *(u8 **)s;
  u32 id = vcall<u32>(DB, 0x4c, (u32)self, 4u);
  (*(void(THISCALL **)(u8 *, u32, u32))(vt + 0x60))(s, 0x697b08u, id);
}
PCREG(4ee070, saveCleanup_4ee070);

// 0x638cf0 (no GC name) (dst, x, y, w, h, stride, id) ret 0x1c: info = vt[0x38](id) {+4 pitch in words, +0x10 data};
// copies h rows of w words from data[y * pitch + x] to dst (dst advances by stride bytes, pitch re-read per row).
// Returns info in eax (GUESS that it is used; the exe leaves it there).
static u8 *THISCALL blit_638cf0(u8 *self, u32 *dst, s32 x, s32 y, s32 w, s32 h, s32 stride, u32 id) {
  u8 *info = vcall<u8 *>(self, 0x38, id);
  s32 k = *(s32 *)(info + 4) * y + x;
  u32 *data = *(u32 **)(info + 0x10);
  for (; h > 0; h--) {
    for (s32 i = 0; i < w; i++) dst[i] = data[k + i];
    dst = (u32 *)((u8 *)dst + stride);
    k += *(s32 *)(info + 4);
  }
  return info;
}
PCREG(638cf0, blit_638cf0);

// 0x4f63b0 ZTTFONT::CopyDataBlock(DBLK *b) ret 4: ZFONT::CopyDataBlock, 0x4e1b20, Get(&id, 1) -> +0x93; t = the texture
// table ((engine +0x1aa3)->+0x18)->vt[0xc](id); +0x97 = t + t->+4, +0x9b = that + 0x18, +0x9f = +0x9b + 20 * (that)->+8;
// NextBlock.
static void THISCALL copyDataBlock_4f63b0(u8 *self, u8 *b) {
  ext_4face0(self, b);
  ext_4e1b20(b);
  u32 id;
  ext_4e12e0(b, &id, 1);
  *(u32 *)(self + 0x93) = id;
  u8 *tab = *(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x1aa3) + 0x18);
  u8 *t = vcall<u8 *>(tab, 0xc, id);
  *(u32 *)(self + 0x97) = 0;
  u8 *e = t + *(u32 *)(t + 4);
  *(u8 **)(self + 0x97) = e;
  u8 *d = e + 0x18;
  *(u8 **)(self + 0x9b) = d;
  *(u8 **)(self + 0x9f) = d + *(u32 *)(e + 8) * 20;
  ext_4e1b30(b);
}
PCREG(4f63b0, copyDataBlock_4f63b0);
