// batch1907.cpp - fresh slice 19, batch 1907 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
// SEH frames and stack cookies of the exe are not ported (the state they leave is the same).
#include "ff.h"

extern "C" void THISCALL ext_5f10c0(u8 *dst, u32 x);           // 12-byte element copy constructor (hooked)
extern "C" void THISCALL ext_4302d0(u8 *self, u8 *end, u32 x); // vector grow-and-insert (hooked)
extern "C" void THISCALL ext_4cbe80(u8 *s, u32 txt);           // MYSTR::MYSTR(const char*) (hooked)
extern "C" void THISCALL ext_4cbee0(u8 *s, u8 *o);             // MYSTR::operator= (hooked)
extern "C" void THISCALL ext_4cbec0(u8 *s);                    // MYSTR::~MYSTR (hooked)
extern "C" void THISCALL ext_561020(u8 *self);                 // CBaseWindow::CBaseWindow (hooked)
extern "C" void THISCALL ext_59a9b0(u8 *v, u32 n);             // vector reserve (hooked)
extern "C" void THISCALL ext_4ff9d0(u8 *v);                    // vector destructor (hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x4311f0 (no GC name) vector<12-byte T>::push_back(const T &x) ret 4: room left (+4 != +8): copy-construct at +4 (when
// not null) and advance it by 12; otherwise the grow-and-insert 0x4302d0(end, x).
static void THISCALL pushBack_4311f0(u8 *self, u32 x) {
  u8 *end = *(u8 **)(self + 4);
  if (end == *(u8 **)(self + 8)) {
    ext_4302d0(self, end, x);
    return;
  }
  if (end) ext_5f10c0(end, x);
  *(u32 *)(self + 4) += 0xc;
}
PCREG(4311f0, pushBack_4311f0);

// 0x4febf0 ZSaveGame::ZSaveGame(const ZSaveGame &o) ret 4: vptr 0x68e948, then copies +4 .. +0x13b.
static u8 *THISCALL copyCtor_4febf0(u8 *self, u8 *o) {
  *(u32 *)self = 0x68e948;
  for (u32 k = 4; k < 0x13c; k += 4) *(u32 *)(self + k) = *(u32 *)(o + k);
  return self;
}
PCREG(4febf0, copyCtor_4febf0);

// 0x423ff0 (no GC name) (const char *s) ret 4: the MYSTR at +0x23db = MYSTR(s) (through a stack temporary), byte +0x1b3f = 0.
static void THISCALL setName_423ff0(u8 *self, u32 s) {
  alignas(4) u8 tmp[0x80];
  ext_4cbe80(tmp, s);
  ext_4cbee0(self + 0x23db, tmp);
  ext_4cbec0(tmp);
  self[0x1b3f] = 0;
}
PCREG(423ff0, setName_423ff0);

// 0x56f030 (no GC name) window factory: o = (engine db +8)->vt[0x44](incoming ecx as a stack word: GUESS, as 0x57be70);
// with o: CBaseWindow ctor, vptr 0x6a83e8, byte +0x198 = 1, byte +0x1c9 = 0, +0x4b2 = 0. Returns o.
static u8 *THISCALL make_56f030(u8 *self) {
  u8 *o = vcall<u8 *>(*(u8 **)(DB + 8), 0x44, (u32)self);
  if (o) {
    ext_561020(o);
    *(u32 *)o = 0x6a83e8;
    o[0x198] = 1;
    o[0x1c9] = 0;
    *(u32 *)(o + 0x4b2) = 0;
  }
  return o;
}
PCREG(56f030, make_56f030);

// 0x51f170 (no GC name) (no args): when [0x7018d8] is 0, a stack vector {0, 0, 0, owns = 1} reserved for 50 (0x59a9b0) is
// passed to vt[0x1c] and destroyed (0x4ff9d0).
static void THISCALL fn_51f170(u8 *self) {
  if (G(u32, 0x7018d8)) return;
  alignas(4) u8 v[16];
  *(u32 *)v = 0;
  *(u32 *)(v + 4) = 0;
  *(u32 *)(v + 8) = 0;
  v[0xc] = 1;
  ext_59a9b0(v, 0x32);
  vcall<void>(self, 0x1c, (u32)v);
  ext_4ff9d0(v);
}
PCREG(51f170, fn_51f170);

// 0x54c3f0 (no GC name) (no args): o = vt[0x40](); o->vt[8](&desc, 1) with a 12-word stack descriptor {6, 0, 1, 0x5622,
// 0x10, 0x20, (word 6 not set), 1, 0, 0x10, 2, 1} (looks like a WAVEFORMAT/buffer description: GUESS); on failure
// o->vt[4](1) and 0, else o.
static u8 *THISCALL fn_54c3f0(u8 *self) {
  u32 d[12];
  d[0] = 6;
  d[1] = 0;
  d[2] = 1;
  d[3] = 0x5622;
  d[4] = 0x10;
  d[5] = 0x20;
  d[7] = 1;
  d[8] = 0;
  d[9] = 0x10;
  d[10] = 2;
  d[11] = 1;
  u8 *o = vcall<u8 *>(self, 0x40);
  if (vcall<bool>(o, 8, (u32)d, 1u)) return o;
  vcall<void>(o, 4, 1u);
  return 0;
}
PCREG(54c3f0, fn_54c3f0);
