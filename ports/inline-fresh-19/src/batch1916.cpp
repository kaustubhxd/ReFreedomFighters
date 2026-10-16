// batch1916.cpp - fresh slice 19, batch 1916 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" u8 *THISCALL ext_469870(u8 *self);                             // base constructor, returns this (hooked)
extern "C" void THISCALL ext_5a5c50(u8 *o);                               // (no GC name) (hooked)
extern "C" void THISCALL ext_5a5c60(u8 *o);                               // (no GC name) (hooked)
extern "C" void THISCALL ext_5a5c80(u8 *o, float a, float b, char *s);    // (no GC name) ret 0xc (hooked)
extern "C" u32 VECTORCALL ext_633910(float x);                            // CRT float -> unsigned helper, runs as exe code

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))
typedef void (*logf_t)(void *, ...);

static inline void assert_hook() {
  void (*hook)() = *(void (**)())0x7003b0u;
  if (hook) hook();
  else __builtin_debugtrap();   // the exe falls into an int3 when no hook is set
}

// 0x48b5b0 ZEngineDataBase::AllocGeomCallEvent(ZGEOM *g) ret 4: logs an error while vt[0x7c]() is true (enginedatabase
// line 0xe0e); 0x40 bytes from the db allocator (+8, vt[0x44]; the assert hook when it fails) built by 0x469870; then
// +0x10 = engine +0x40 (skipped when they are the same word) and +0x1c = db vt[0x4c](g). Returns it. (SEH not ported.)
static u8 *THISCALL allocEvent_48b5b0(u8 *self, u32 g) {
  if ((u8)vcall<u32>(self, 0x7c)) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x68d798u, 0xe0eu);
    (*(logf_t *)(*(u8 **)log + 0x2c))(log, 0x68dec8u);
  }
  u8 *o = vcall<u8 *>(*(u8 **)(DB + 8), 0x44, 0x40u);
  if (!o) assert_hook();
  if (!o) return 0;
  o = ext_469870(o);
  if (!o) return 0;
  u8 *rm = *(u8 **)0x70039cu;
  if (o + 0x10 != rm + 0x40) *(u32 *)(o + 0x10) = *(u32 *)(rm + 0x40);
  *(u32 *)(o + 0x1c) = vcall<u32>(DB, 0x4c, g);
  return o;
}
PCREG(48b5b0, allocEvent_48b5b0);

// 0x4c2ab0 ZMusicControl::SendMusicInfo(unsigned short id) ret 4: clears the three counters at +0x1bb; walks the list at
// +0xfc (vt[0x4c] begin, vt[0x5c] next into a 0xc-byte stack iterator, until its first word is 0); for each geom (db
// vt[0x58]) whose vt[0x104]("MusicSegment") gives a segment: info = segment vt[0x84](), counter [info type 0/1/2] + 1,
// vt[0x94](id, info) (id pushed as the whole incoming dword). Then vt[0x94](word +0x1b1, counters).
static void THISCALL sendMusicInfo_4c2ab0(u8 *self, u32 id) {
  u32 *cnt = (u32 *)(self + 0x1bb);
  cnt[0] = 0;
  cnt[1] = 0;
  cnt[2] = 0;
  u8 *lst = self + 0xfc;
  u32 it[3];
  vcall<void>(lst, 0x4c, it);
  u32 e = vcall<u32>(lst, 0x5c, it);
  while (it[0]) {
    u8 *seg = vcall<u8 *>(vcall<u8 *>(DB, 0x58, e), 0x104, 0x693490u);
    if (seg) {
      u32 *info = vcall<u32 *>(seg, 0x84);
      if (*info == 0) cnt[0]++;
      else if (*info == 1) cnt[1]++;
      else if (*info == 2) cnt[2]++;
      vcall<void>(self, 0x94, id, info);
    }
    e = vcall<u32>(lst, 0x5c, it);
  }
  vcall<void>(self, 0x94, (u32)*(u16 *)(self + 0x1b1), cnt);
}
PCREG(4c2ab0, sendMusicInfo_4c2ab0);

// 0x5ea870 (no GC name; numeric display) (float v) ret 4: below 1/8192 [0x679540] only 0x5a5c50(+0x1d0f) (when set).
// Else 0x5a5c60(+0x1d0f), "%d" of ftou(v) into a stack buffer (engine vt[0x190]()->vt[0x198], cdecl) and, with +0x1d0f,
// 0x5a5c80(+0x1d1b * 0.8 * +0x1d23, +0x1d1f * 0.8 * +0x1d27, buffer). (Cookie not ported.)
typedef void (*spf_t)(u8 *, char *, u32, u32);
static void THISCALL show_5ea870(u8 *self, float v) {
  u8 *t = *(u8 **)(self + 0x1d0f);
  if (0.0001220703125f > v) {   // [0x679540]
    if (t) ext_5a5c50(t);
    return;
  }
  if (t) ext_5a5c60(t);
  u8 *o = vcall<u8 *>(*(u8 **)0x70039cu, 0x190);
  char buf[0x20];
  (*(spf_t *)(*(u8 **)o + 0x198))(o, buf, 0x6784f4u, ext_633910(v));
  t = *(u8 **)(self + 0x1d0f);
  if (!t) return;
  float a = *(float *)(self + 0x1d1b) * 0.8f * *(float *)(self + 0x1d23);   // 0.8 = [0x67c1a8]
  float b = *(float *)(self + 0x1d1f) * 0.8f * *(float *)(self + 0x1d27);
  ext_5a5c80(t, a, b, buf);
}
PCREG(5ea870, show_5ea870);

// 0x42d730 ZSysInterface::Load(ZLoadGame *l) ret 4: l->vt[0xc](2), then one read per field into this (slot, offset):
// 0x5c +0xc, +4, +0x14; 0x58 +0x1c; 0x50 +0x20; 0x58 +0x24; 0x50 +0x2c; 0x58 +0x30; 0x50 +0x34; 0x58 +0x38; 0x40 +0x3c;
// 0x58 +0x40, +0x44; 0x50 +0x48; 0x58 +0x4c; 0x50 +0x58; 0x48 +0x1b49; 0x68 +0x1b59.
static void THISCALL load_42d730(u8 *self, u8 *l) {
  vcall<void>(l, 0xc, 2u);
  static const u16 fs[18][2] = {{0x5c, 0xc},   {0x5c, 4},     {0x5c, 0x14},  {0x58, 0x1c},    {0x50, 0x20},   {0x58, 0x24},
                                {0x50, 0x2c},  {0x58, 0x30},  {0x50, 0x34},  {0x58, 0x38},    {0x40, 0x3c},   {0x58, 0x40},
                                {0x58, 0x44},  {0x50, 0x48},  {0x58, 0x4c},  {0x50, 0x58},    {0x48, 0x1b49}, {0x68, 0x1b59}};
  for (u32 i = 0; i < 18; i++) vcall<void>(l, fs[i][0], self + fs[i][1]);
}
PCREG(42d730, load_42d730);
