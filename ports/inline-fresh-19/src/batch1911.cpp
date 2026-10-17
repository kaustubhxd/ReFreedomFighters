// batch1911.cpp - fresh slice 19, batch 1911 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
// SEH frames and stack cookies of the exe are not ported (the state they leave is the same).
#include "ff.h"

extern "C" bool THISCALL ext_45f960(u8 *self, u8 *s);                   // ZGEOM::Save (hooked)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);                              // DBREAD::operator unsigned int() (hooked)
extern "C" float THISCALL ext_4e5e80(u8 *db);                            // DBREAD::operator float() (hooked)
extern "C" u8 *ext_45c4f0(u32 n, u32 pool);                              // pool operator new (cdecl; hooked)
extern "C" u8 *ext_45c4b0(u32 n);                                        // operator new (cdecl; hooked)
extern "C" u8 *THISCALL ext_51f3e0(u8 *o, u32 c, u32 a, u32 b);          // constructor (hooked, ret 0xc)
extern "C" u32 FASTCALL ext_6071c0(u32 n);                               // next table size >= n (exe code)
extern "C" void THISCALL ext_59a9b0(u8 *v, u32 n);                       // vector reserve (hooked)
extern "C" void THISCALL ext_606ee0(u8 *v, u32 at, u32 n, u32 *val);     // vector insert n copies (hooked)
extern "C" void THISCALL ext_57aaf0(u8 *self);                           // ZFFMissingControllerDialog::UpdateMessage (hooked)

// 0x4550f0 ZMaterialDesc::Save(ZSaveGame *s) ret 4: ZGEOM::Save, then words +0x18 +0x1c +0x20 +0x34 +0x28 (slot 0x3c),
// float +0x30 (slot 0x4c), +0x2c (slot 0x44), words +0x24 +0x3c +0x40 +0x44 +0x48 (slot 0x3c); returns 1.
static bool THISCALL save_4550f0(u8 *self, u8 *s) {
  ext_45f960(self, s);
  static const u8 a[5] = {0x18, 0x1c, 0x20, 0x34, 0x28};
  for (u32 i = 0; i < 5; i++) vcall<void>(s, 0x3c, *(u32 *)(self + a[i]));
  vcall<void>(s, 0x4c, *(float *)(self + 0x30));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x2c));
  static const u8 b[5] = {0x24, 0x3c, 0x40, 0x44, 0x48};
  for (u32 i = 0; i < 5; i++) vcall<void>(s, 0x3c, *(u32 *)(self + b[i]));
  return true;
}
PCREG(4550f0, save_4550f0);

// 0x4c1e30 ZMusicSegment::Init(ZGEOM *g, DBREAD &d) ret 8: mode 0/1/2 into +0x48 (other values leave it), words +0x4c
// +0x50 +0x54, bool +0x58; when the next field's type byte ([d] & 0x3f, not 0xff) is 2 (float), three floats +0x59 +0x5d +0x61.
static void THISCALL init_4c1e30(u8 *self, u8 *, u8 *d) {
  u32 m = ext_4e5e60(d);
  if (m == 0) *(u32 *)(self + 0x48) = 0;
  else if (m == 1) *(u32 *)(self + 0x48) = 1;
  else if (m == 2) *(u32 *)(self + 0x48) = 2;
  *(u32 *)(self + 0x4c) = ext_4e5e60(d);
  *(u32 *)(self + 0x50) = ext_4e5e60(d);
  *(u32 *)(self + 0x54) = ext_4e5e60(d);
  self[0x58] = ext_4e5e60(d) != 0;
  u8 t = **(u8 **)d;
  if (t == 0xff || (t & 0x3f) != 2) return;
  *(float *)(self + 0x59) = ext_4e5e80(d);
  *(float *)(self + 0x5d) = ext_4e5e80(d);
  *(float *)(self + 0x61) = ext_4e5e80(d);
}
PCREG(4c1e30, init_4c1e30);

// 0x51f530 (no GC name) fastcall (a, b; c, pool) ret 8: 0x171d bytes from the pool (or plain new without one), constructed
// by 0x51f3e0(c, a, b); returns the object or 0.
static u8 *FASTCALL make_51f530(u32 a, u32 b, u32 c, u32 pool) {
  u8 *o = pool ? ext_45c4f0(0x171d, pool) : ext_45c4b0(0x171d);
  if (!o) return 0;
  return ext_51f3e0(o, c, a, b);
}
PCREG(51f530, make_51f530);

// 0x606a70 (no GC name) constructor: the vector at +3 (+3 begin, +7 end, +0xb cap) and +0xf cleared; reserved for
// n = 0x6071c0(100) (table size) and filled with n zero words (insert at end); +0xf = 0. Returns this.
static u8 *THISCALL ctor_606a70(u8 *self) {
  *(u32 *)(self + 3) = 0;
  *(u32 *)(self + 7) = 0;
  *(u32 *)(self + 0xb) = 0;
  *(u32 *)(self + 0xf) = 0;
  u32 n = ext_6071c0(0x64);
  ext_59a9b0(self + 3, n);
  u32 z = 0;
  ext_606ee0(self + 3, *(u32 *)(self + 7), n, &z);
  *(u32 *)(self + 0xf) = 0;
  return self;
}
PCREG(606a70, ctor_606a70);

// 0x57edf0 (no GC name) (a, i, n) ret 0xc: the two widgets +0xc[i] and +0x1c[i] each get vt[0x284](a) and
// vt[0x26c]((float)n, 0, 0) (n unsigned).
static void THISCALL fn_57edf0(u8 *self, u32 a, u32 i, u32 n) {
  vcall<void>(*(u8 **)(self + 0xc + i * 4), 0x284, a);
  float f = (float)(double)n;
  vcall<void>(*(u8 **)(self + 0xc + i * 4), 0x26c, f, 0u, 0u);
  vcall<void>(*(u8 **)(self + 0x1c + i * 4), 0x284, a);
  vcall<void>(*(u8 **)(self + 0x1c + i * 4), 0x26c, f, 0u, 0u);
}
PCREG(57edf0, fn_57edf0);

// 0x6101b0 (no GC name) (float start, float end, color) ret 0xc: fog globals 0x724960 / 0x724964 / 0x724954 (color with
// alpha 0xff) and device render states (COM slot 0xc8 on +0x1377): 0x22 color, 0x8c 3, 0x23 0, 0x24 start, 0x25 end.
typedef void(STDCALL *rs_t)(u8 *, u32, u32);
static void THISCALL setFog_6101b0(u8 *self, float s, float e, u32 col) {
  G(float, 0x724960) = s;
  col |= 0xff000000u;
  G(u32, 0x724954) = col;
  G(float, 0x724964) = e;
  static const u32 st[3] = {0x22, 0x8c, 0x23};
  u32 v[3] = {col, 3, 0};
  for (u32 k = 0; k < 3; k++) {
    u8 *dev = *(u8 **)(self + 0x1377);
    (*(rs_t *)(*(u8 **)dev + 0xc8))(dev, st[k], v[k]);
  }
  u8 *dev = *(u8 **)(self + 0x1377);
  (*(rs_t *)(*(u8 **)dev + 0xc8))(dev, 0x24, G(u32, 0x724960));
  dev = *(u8 **)(self + 0x1377);
  (*(rs_t *)(*(u8 **)dev + 0xc8))(dev, 0x25, G(u32, 0x724964));
}
PCREG(6101b0, setFog_6101b0);

// 0x57a6b0 ZFFMissingControllerDialog::FrameUpdate(): mask = [0x7003a0]->vt[0x4c](); each of the 4 controller ids at +0x184
// (-1 = none) whose bit is clear marks +0x194[i] (once) and +0x198; with +0x198 set and no link (+0x94) bytes +0x13298 /
// +0x13299 set: UpdateMessage, and unless +0x88, vt[0x84]()->vt[0x2fc](+0x44).
static void THISCALL frameUpdate_57a6b0(u8 *self) {
  u32 m = vcall<u32>(G(u8 *, 0x7003a0), 0x4c);
  for (u32 i = 0; i < 4; i++) {
    s32 c = *(s32 *)(self + 0x184 + 4 * i);
    if (c == -1 || (m & (1u << (c & 31))) || self[0x194 + i]) continue;
    self[0x194 + i] = 1;
    self[0x198] = 1;
  }
  if (!self[0x198]) return;
  u8 *p = *(u8 **)(self + 0x94);
  if (p && (p[0x13298] || p[0x13299])) return;
  ext_57aaf0(self);
  if (self[0x88]) return;
  vcall<void>(vcall<u8 *>(self, 0x84), 0x2fc, *(u32 *)(self + 0x44));
}
PCREG(57a6b0, frameUpdate_57a6b0);
