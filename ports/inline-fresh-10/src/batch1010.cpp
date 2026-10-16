// batch1010.cpp - fresh-10 batch 10: frees, autosave, library unload, data-block copy, loads (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SCENE (*(u8 **)(*(u8 **)0x70039c + 0x9b))
extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)
extern "C" void ext_634d52(void *p);          // free (cdecl, jumps through the IAT)
extern "C" void ext_4690b0(void *p, u32 n);   // ZOctreeFuskeBaseKlasse::lort (cdecl; empty in this build)
extern "C" void THISCALL ext_4cbec0(void *);  // MYSTR::~MYSTR
extern "C" void *ext_41e290(u32);             // new (cdecl)
extern "C" void ext_41e2c0(void *);           // GUESS release through ZSysMem [0x70038c] slot10, else free (cdecl)
typedef void (*hook_t)();
static inline void Assert() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}

// 0x403ee0 GUESS (cdecl): free a 13-dword struct: +0x14, +0x18, +0x1c (when set); the 17 x 11 table at +8 (each
// row's 11 entries, the row, then the table; only when +8 is set); +0x10 and +0xc; then zero all 13 dwords.
static void FreeTable403ee0(u32 *p) {
  if (!p) return;
  if (p[5]) ext_634d52((void *)p[5]);
  if (p[6]) ext_634d52((void *)p[6]);
  if (p[7]) ext_634d52((void *)p[7]);
  if (p[2]) {
    for (int r = 0; r < 17; r++) {
      for (int k = 0; k < 11; k++) ext_634d52(((void ***)p[2])[r][k]);
      ext_634d52(((void **)p[2])[r]);
    }
    ext_634d52((void *)p[2]);
  }
  ext_634d52((void *)p[4]);
  ext_634d52((void *)p[3]);
  for (int i = 0; i < 13; i++) ((volatile u32 *)p)[i] = 0;
}
PCREG(403ee0, FreeTable403ee0);

// 0x575ee0 ZSubZoneMap::AutoSave() (high): level controller (+0x94).SetNextScene(+0x206); o = scene.slot60(+0x21d);
// if o: +0xec = 1, +0xed = clock (rm+0x40) * [0x6785e4], +0xf1 = +0x88, +0xf5 = +0x88 / [0x67a284].
// AutoSaveEnabled() ? slotd0(+0x219) : (SaveRaw(controller+0x57, false), LoadLevel()).
extern "C" void THISCALL ext_59cb60(void *, void *);
extern "C" u8 THISCALL ext_561be0(void *);
extern "C" void THISCALL ext_5ae710(void *, u32);
extern "C" void THISCALL ext_562bc0(void *);
static void THISCALL SubZoneAutoSave(u8 *self) {
  ext_59cb60(*(void **)(self + 0x94), self + 0x206);
  u8 *o = vcall<u8 *>(SCENE, 0x60, F32(self, 0x21d));
  if (o) {
    o[0xec] = 1;
    *(float *)(o + 0xed) = (float)*(s32 *)(*(u8 **)0x70039c + 0x40) * G(float, 0x6785e4);
    float f = *(float *)(o + 0x88);
    *(float *)(o + 0xf1) = f;
    *(float *)(o + 0xf5) = f / G(float, 0x67a284);
  }
  if (ext_561be0(self)) {
    vcall<void>(self, 0xd0, F32(self, 0x219));
    return;
  }
  ext_5ae710(*(u8 **)(self + 0x94) + 0x57, 0);
  ext_562bc0(self);
}
PCREG(575ee0, SubZoneAutoSave);

// 0x427020 ZSysFileGC::FreeLib(long) (low): find the library entry with handle +4 == h in the list +0x10c; when its
// count (+8) drops to 0: +0xc and +0x10 get slot14(1), delete(+0, 1), the list removes it (slot44 at the iterator),
// FreeLibrary(h), true. Not found or still referenced: false.
typedef u32(STDCALL *freelib_t)(u32);
static u8 THISCALL FreeLib(u8 *self, u32 h) {
  if (!*(void **)(self + 0x10c)) return 0;
  u32 it[3];
  vcall<void>(*(void **)(self + 0x10c), 0x4c, it);
  for (u32 *e = vcall<u32 *>(*(void **)(self + 0x10c), 0x64, it); e; e = vcall<u32 *>(*(void **)(self + 0x10c), 0x64, it)) {
    if (h != e[1]) continue;
    if (--e[2]) return 0;
    if (e[3]) vcall<void>((void *)e[3], 0x14, 1u);
    if (e[4]) vcall<void>((void *)e[4], 0x14, 1u);
    ext_634273((void *)e[0], 1);
    vcall<void>(*(void **)(self + 0x10c), 0x44, it);
    G(freelib_t, 0x6760b0)(h);
    return 1;
  }
  return 0;
}
PCREG(427020, FreeLib);

// 0x4ff920 GUESS destructor body (SEH frame): the vectors at +0x38, +0x1c and +4 (begin, capacity end at +8) go to
// 0x54f870(begin, bytes) when both are non-zero; +0x2c and +0x10 go to 0x41e2c0 after the first two.
extern "C" void THISCALL ext_54f870(void *, void *, u32);
static inline void FreeVec(u8 *v) {
  u8 *b = *(u8 **)v;
  u32 n = *(u8 **)(v + 8) - b;
  if (b && n) ext_54f870(v, b, n);
}
static void THISCALL Dtor4ff920(u8 *self) {
  FreeVec(self + 0x38);
  ext_41e2c0(*(void **)(self + 0x2c));
  FreeVec(self + 0x1c);
  ext_41e2c0(*(void **)(self + 0x10));
  FreeVec(self + 4);
}
PCREG(4ff920, Dtor4ff920);

// 0x4f4160 ZWINPIC::CopyDataBlock(DBLK*) (high): ZWINOBJ::CopyDataBlock(db); id = db.Get(1 dword); t =
// [[rm+0x1aa3]+0x18].slotc(id): +0x2e = n (t[0]), +0x2a = t+4 (n entries of 40 bytes), +0x91 = 1; q = t+4+n*40:
// +0x32 = m (q[0]), +0x36 = q+4, +0x3a = q+4+m*4 (m pairs of dwords); each pair's second dword becomes an entry
// pointer (+0x2a + idx*40). Then slot228(), slot244(), +0x90 = 1, db.NextBlock().
extern "C" void THISCALL ext_4ef660(void *, void *);
extern "C" void THISCALL ext_4e12e0(void *, u32 *, u32);
extern "C" void THISCALL ext_4e1b30(void *);
static void THISCALL WinPicCopyDataBlock(u8 *self, void *db) {
  ext_4ef660(self, db);
  u32 id = 0;
  ext_4e12e0(db, &id, 1);
  void *tab = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18);
  u32 *t = vcall<u32 *>(tab, 0xc, id);
  u32 n = t[0];
  u8 *base = (u8 *)(t + 1);
  F32(self, 0x2e) = n;
  *(u8 **)(self + 0x2a) = base;
  self[0x91] = 1;
  u32 *q = (u32 *)(base + n * 40);
  u32 m = q[0];
  F32(self, 0x32) = m;
  *(u32 **)(self + 0x36) = q + 1;
  *(u32 **)(self + 0x3a) = q + 1 + m;
  if (m) {
    u32 i = 0;
    do {
      u32 *e = (u32 *)(*(u8 **)(self + 0x3a) + i * 8);
      i++;
      e[1] = (u32)(*(u8 **)(self + 0x2a) + e[1] * 40);
    } while (i < F32(self, 0x32));
  }
  vcall<void>(self, 0x228);
  vcall<void>(self, 0x244);
  self[0x90] = 1;
  ext_4e1b30(db);
}
PCREG(4f4160, WinPicCopyDataBlock);

// 0x5ff960 GUESS check header (thiscall, stream; /GS): stream.slot70(buf, 16); buf must equal +0x18..+0x27, then two
// stream.slot5c dwords must equal +8 and +0xc; each mismatch calls the assert hook (int3 when it is null).
static void THISCALL CheckHeader5ff960(u8 *self, void *s) {
  u32 buf[4];
  vcall<void>(s, 0x70, buf, 0x10u);
  for (int i = 0; i < 4; i++)
    if (buf[i] != F32(self, 0x18 + 4 * i)) {
      Assert();
      break;
    }
  u32 v;
  vcall<void>(s, 0x5c, &v);
  if (v != F32(self, 8)) Assert();
  vcall<void>(s, 0x5c, &v);
  if (v != F32(self, 0xc)) Assert();
}
PCREG(5ff960, CheckHeader5ff960);

// 0x4b23a0 CCutSequenceSoundStartStop::~CCutSequenceSoundStartStop() (medium; scalar deleting, SEH frame): ~MYSTR(+0x95);
// +0x44 = +0x30 = 0; vtable 0x686874; scene.slot34(this); flag 1: flag 4 ? lort(this, 0x224) : assert hook. Returns this.
static u8 *THISCALL SoundStartStopDtor(u8 *self, u32 flags) {
  ext_4cbec0(self + 0x95);
  F32(self, 0x44) = 0;
  F32(self, 0x30) = 0;
  F32(self, 0) = 0x686874;
  vcall<void>(SCENE, 0x34, self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x224);
    else Assert();
  }
  return self;
}
PCREG(4b23a0, SoundStartStopDtor);

// 0x4b5be0 CCutSequenceSoundStartStop::Load(ZLoadGame*) (high): +4 &= ~0x40; assert hook (always); slot98(0); then
// g reads: 48 +0x48, 58 +0x50, 50 +0x58, 50 +0x5c, 48 +0x68, 48 +0x6c, 40 +0x8d, 50 +0x60, 48 +0x64, 48 +0x70,
// 48 +0x74, 40 +0x7c. Returns true (AL only).
static u8 THISCALL SoundStartStopLoad(u8 *self, void *g) {
  F32(self, 4) &= ~0x40u;
  Assert();
  vcall<void>(self, 0x98, 0u);
  static const u8 ops[12][2] = {{0x48, 0x48}, {0x58, 0x50}, {0x50, 0x58}, {0x50, 0x5c}, {0x48, 0x68}, {0x48, 0x6c},
                                {0x40, 0x8d}, {0x50, 0x60}, {0x48, 0x64}, {0x48, 0x70}, {0x48, 0x74}, {0x40, 0x7c}};
  for (int i = 0; i < 12; i++) vcall<void>(g, ops[i][0], self + ops[i][1]);
  return 1;
}
PCREG(4b5be0, SoundStartStopLoad);

// 0x4804e0 ZLightOverlay::InitFeedBackSprite() (low): +0x8c = new(8) = {1, new(0x44)}; the 0x44 block: zeros, 1.0f
// at +0x14/+0x1c/+0x20/+0x28, +0x2c = +0x30 = 2 * this+0x1c, -1 at +0x34..+0x40.
static void THISCALL InitFeedBackSprite(u8 *self) {
  u32 *a = (u32 *)ext_41e290(8);
  *(u32 **)(self + 0x8c) = a;
  a[0] = 1;
  u32 *b = (u32 *)ext_41e290(0x44);
  (*(u32 **)(self + 0x8c))[1] = (u32)b;
  b = (u32 *)(*(u32 **)(self + 0x8c))[1];
  b[0] = 0;
  b[1] = 0;
  b[2] = 0;
  float r = *(float *)(self + 0x1c);
  *(float *)(b + 11) = r + r;
  float r2 = *(float *)(self + 0x1c);
  b[3] = 0;
  b[4] = 0;
  b[5] = 0x3f800000;
  b[6] = 0;
  b[7] = 0x3f800000;
  *(float *)(b + 12) = r2 + r2;
  b[8] = 0x3f800000;
  b[9] = 0;
  b[10] = 0x3f800000;
  b[13] = b[14] = b[15] = b[16] = 0xffffffff;
}
PCREG(4804e0, InitFeedBackSprite);

// 0x447d20 GUESS (fastcall cls, name; stack info, geom; SEH frame): geom ? 0x446f30(geom, info, cls, name) :
// o = 0x45c4b0(0x24); ZGEOM(o, info, cls, name); +0x18 = 0; +0x14 |= 1 when scene byte +0xbad; vtable 0x67e790.
extern "C" u32 FASTCALL ext_446f30(u32, u32, u32, u32);
extern "C" u8 *ext_45c4b0(u32);
extern "C" void THISCALL ext_45c3a0(void *, u32, u32, u32);
static u32 FASTCALL Create447d20(u32 a, u32 b, u32 info, u32 geom) {
  if (geom) return ext_446f30(geom, info, a, b);
  u8 *o = ext_45c4b0(0x24);
  if (!o) return 0;
  ext_45c3a0(o, info, a, b);
  F32(o, 0) = 0x67dc30;
  F32(o, 0x18) = 0;
  if (SCENE[0xbad]) F32(o, 0x14) |= 1;
  F32(o, 0) = 0x67e790;
  return (u32)o;
}
PCREG(447d20, Create447d20);
