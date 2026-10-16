// batch1804.cpp - fresh-18 batch 4 (slice 18): cleanup, pools, BST insert, loaders, bounds bits.
#include "ff.h"

static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*cdeclLog2)(void *, u32);
typedef void (*cdeclLog3)(void *, u32, u32);
// Engine log: 0x700390 slot 0x20(file, line) gives a logger whose cdecl slot 0x2c takes the text (and args).
static inline void ffLog(u32 file, u32 line, u32 text) {
  void *lg = vcall<void *>(G(void *, 0x700390), 0x20, file, line);
  (*(cdeclLog2 *)(*(u8 **)lg + 0x2c))(lg, text);
}

extern "C" void ext_634273(void *p, u32 size);                    // operator delete(p, size), cdecl
extern "C" void THISCALL ext_5626c0(void *self);                  // CBaseWindow::Load2
extern "C" void THISCALL ext_563510(void *self, u32 pic);         // CBaseWindow::SetBackGroundPicture
extern "C" void THISCALL ext_563610(void *self, u32 a);
extern "C" u32 THISCALL ext_566f10(void *self);                   // CController::GetCS
extern "C" void THISCALL ext_5672c0(void *self, u32 cs);          // CController::SetCS
extern "C" void THISCALL ext_44b610(void *self);
extern "C" void ext_44b740(void *p);                              // ZSoundObject::~ZSoundObject (cdecl here)
extern "C" void *ext_41e290(u32 size);                            // operator new, cdecl
extern "C" void ext_41e2c0(void *p);                              // free, cdecl
extern "C" void *ext_634d22(void *d, const void *s, u32 n);       // memcpy (CRT, cdecl)
extern "C" void THISCALL ext_4301c0(void *vec, u32 *pos, u32 *val);

// 0x64f8a0 ZRenderBaseDll::Cleanup() [high]
static void THISCALL f64f8a0(u8 *self) {
  if (*(void **)(self + 0x20)) ext_634273(*(void **)(self + 0x20), 1);
  void *o = *(void **)(self + 0x18);
  *(u32 *)(self + 0x20) = 0;
  if (o) vcall<void>(o, 0x160, 1);
  void *p = *(void **)(self + 0x2c);
  *(u32 *)(self + 0x18) = 0;
  if (p) ext_634273(p, 1);
  void *q = *(void **)(self + 0x68);
  *(u32 *)(self + 0x2c) = 0;
  if (q) vcall<void>(q, 0xc, 1);
  *(u32 *)(self + 0x68) = 0;
}
PCREG(64f8a0, f64f8a0);

// 0x44d520 ZBoneParticle::RemoveParticles(unsigned int) [medium]: detaches particle i (engine slot 0x58 by id +0x10,
// then that geom's slot 0x294(this+8, +0xc)) and swaps it with the last live entry.
static void THISCALL f44d520(u8 *self, u32 i) {
  u8 *p = (*(u8 ***)(self + 0x20))[i];
  void *g = vcall<void *>(engineObj9b(), 0x58, *(u32 *)(p + 0x10));
  if (g) vcall<void>(g, 0x294, *(u32 *)(self + 8), *(u32 *)(p + 0xc));
  *(u32 *)(p + 0x10) = 0;
  (*(u32 *)(self + 0x1c))--;
  u8 **arr = *(u8 ***)(self + 0x20);
  arr[i] = arr[*(u32 *)(self + 0x1c)];
  (*(u8 ***)(self + 0x20))[*(u32 *)(self + 0x1c)] = p;
}
PCREG(44d520, f44d520);

// 0x615560 GUESS free-list allocator, 48-byte slots (same field reset as 0x6486e0).
static u8 *THISCALL f615560(u8 *pool) {
  u16 h = *(u16 *)(pool + 2);
  if (h == 0xffff) return 0;
  u8 *e = pool + (u32)h * 48;
  *(u16 *)(pool + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x22) = 0xffff;
  *(u32 *)(e + 0x10) = 0;
  *(u32 *)(e + 0x14) = 0xffff1206;
  *(u32 *)(e + 0x18) = 0;
  *(u32 *)(e + 0x1c) = 0;
  *(u32 *)(e + 0x24) = 0;
  *(u32 *)(e + 0x2c) = 0;
  *(u32 *)(e + 0x28) = 0;
  e[0x20] = 0;
  pool[0]++;
  return e + 0x10;
}
PCREG(615560, f615560);

// 0x44ea60 ZBOXGATEGROUP::CalcMaxMinBits(float*) const [high]: outcode of a point against the box min (+0x5c) and
// max (+0x68): bits 1/2 x, 4/8 y, 0x10/0x20 z (NaN compares false, as comiss does).
static u32 THISCALL f44ea60(const u8 *self, const float *v) {
  const float *mn = (const float *)(self + 0x5c), *mx = (const float *)(self + 0x68);
  u32 r = 0;
  if (mn[0] >= v[0]) r = 1;
  else if (v[0] >= mx[0]) r = 2;
  if (mn[1] >= v[1]) r |= 4;
  else if (v[1] >= mx[1]) r |= 8;
  if (mn[2] >= v[2]) r |= 0x10;
  else if (v[2] >= mx[2]) r |= 0x20;
  return r;
}
PCREG(44ea60, f44ea60);

// 0x4cec60 STRREFTAB::PrintStatus() [high]: logs every entry (slot 0x4c starts the 12-byte iterator, slot 0x5c steps).
static void THISCALL f4cec60(void *self) {
  if (!self) return;
  u32 it[3];
  vcall<void>(self, 0x4c, it);
  u32 x = vcall<u32>(self, 0x5c, it);
  while (it[0]) {
    void *lg = vcall<void *>(G(void *, 0x700390), 0x20, 0x695b7c, 0x5c2);
    (*(cdeclLog3 *)(*(u8 **)lg + 0x2c))(lg, 0x695cec, x);
    x = vcall<u32>(self, 0x5c, it);
  }
}
PCREG(4cec60, f4cec60);

// 0x4e8160 GUESS binary tree insert (sentinel at +8, root at +4; node: parent, left, right, key +0xc signed).
static void THISCALL f4e8160(u32 *self, u32 *node) {
  node[1] = self[2];
  node[2] = self[2];
  node[0] = self[2];
  u32 nil = self[2];
  u32 parent = nil;
  u32 cur = self[1];
  if (cur != nil) {
    s32 key = (s32)node[3];
    do {
      parent = cur;
      cur = key < *(s32 *)(cur + 0xc) ? *(u32 *)(cur + 4) : *(u32 *)(cur + 8);
    } while (cur != nil);
  }
  node[0] = parent;
  if (parent == self[2]) {
    self[1] = (u32)node;
    return;
  }
  if ((s32)node[3] < *(s32 *)(parent + 0xc)) *(u32 **)(parent + 4) = node;
  else *(u32 **)(parent + 8) = node;
}
PCREG(4e8160, f4e8160);

// 0x5670a0 CController::Load2() [high]
static void THISCALL f5670a0(u8 *self) {
  ext_5626c0(self);
  ext_563510(self, 0x6a6f98);
  ext_563610(self, 0x6a6fa0);
  *(u32 *)(self + 0x194) = vcall<u32>(engineObj9b(), 0x58, *(u32 *)(self + 0x190));
  ext_5672c0(self, ext_566f10(self));
  u8 *o = *(u8 **)(self + 0x94);
  *(u32 *)(o + 0x132b3) = vcall<u32>(engineObj9b(), 0x4c, *(u32 *)(self + 0x44));
}
PCREG(5670a0, f5670a0);

// 0x4b3460 CCutSequenceCharacterSound::Command(unsigned short, void*) [high]: stop command (+0x72) clears +0x182;
// the end command (+0x70) releases the sound (+0x6c) when +0x184 or +0x182 is set.
static u32 THISCALL f4b3460(u8 *self, u32 cmd, u32) {
  u16 c = (u16)cmd;
  if (c == *(u16 *)(self + 0x72)) self[0x182] = 0;
  if (c != *(u16 *)(self + 0x70)) return 0;
  if (!self[0x184] && !self[0x182]) return 0;
  vcall<void>(self, 0xa0);
  void *s = vcall<void *>(engineObj9b(), 0x60, *(u32 *)(self + 0x6c));
  if (s) {
    ext_44b610(s);
    ext_44b740(s);
  }
  *(u32 *)(self + 0x6c) = 0;
  return 0;
}
PCREG(4b3460, f4b3460);

// 0x4d61e0 GUESS array grow (count +0, data +8): doubles the capacity (size with overflow -> 0xffffffff), copies,
// frees the old block; logs when the allocation fails (file 0x696770 line 0x14f).
static void THISCALL f4d61e0(u32 *self) {
  u32 n = self[0] * 2;
  u64 bytes = (u64)n * 4;
  u32 sz = (bytes >> 32) ? 0xffffffffu : (u32)bytes;
  void *b = ext_41e290(sz);
  if (!b) ffLog(0x696770, 0x14f, 0x696be8);
  ext_634d22(b, (void *)self[2], self[0] << 2);
  self[0] = n;
  ext_41e2c0((void *)self[2]);
  self[2] = (u32)b;
}
PCREG(4d61e0, f4d61e0);

// 0x42d360 ZSysInterface::HandleIfNDef(...) [high]: pushes 1 when slot 0x8c says the name is not defined and the
// current top (last element) is nonzero, else 0, onto the int stack vector at +0x1b61.
static void THISCALL f42d360(u8 *self, u32 name) {
  u8 r = vcall<u8>(self, 0x8c, name);
  u32 *vec = *(u32 **)(self + 0x1b61);
  u32 *end = (u32 *)vec[1];
  u32 v = (!r && end[-1] != 0) ? 1 : 0;
  if (end == (u32 *)vec[2]) {
    ext_4301c0(vec, end, &v);
    return;
  }
  if (end) *end = v;
  vec[1] += 4;
}
PCREG(42d360, f42d360);

// 0x4960e0 ZGeomBuffer::AllocRoomList() [high]: takes the next free 32-byte room list (index table +0x55, base +0x51,
// used count +0x59, max 0x1fe), clears it and reports it to the memory tracker at 0x70038c.
static u8 *THISCALL f4960e0(u8 *self) {
  u32 n = *(u32 *)(self + 0x59);
  if (n >= 0x1fe) {
    ffLog(0x68e36c, 0xc9c, 0x68e7e0);
    return 0;
  }
  u8 *e = *(u8 **)(self + 0x51) + (u32)(*(u16 **)(self + 0x55))[n] * 32;
  *(u32 *)(self + 0x59) = n + 1;
  e[0x1c] = 0;
  *(u32 *)(e + 0x18) = 0;
  void *m = G(void *, 0x70038c);
  if (m) vcall<void>(m, 0x2c, 0x68e7d4, (u32)(e - *(u8 **)(self + 0x51)), 0x20);
  return e;
}
PCREG(4960e0, f4960e0);

// 0x4f7520 ZScrollArea::SetCameraPri(unsigned int) [high]: stores the priority (+0x97); when active (+0xa7) moves the
// camera (+0x93) in the window manager (engine +0x190f): slot 0xb8(cam), slot 0xac(cam, (float)pri unsigned).
static void THISCALL f4f7520(u8 *self, u32 pri) {
  *(u32 *)(self + 0x97) = pri;
  if (!self[0xa7]) return;
  vcall<void>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0xb8, *(u32 *)(self + 0x93));
  void *wm = *(void **)(G(u8 *, 0x70039c) + 0x190f);
  u32 v = *(u32 *)(self + 0x97);
  double d = (double)(s32)v + G(double, 0x680aa0 + 8 * (v >> 31));
  vcall<void>(wm, 0xac, *(u32 *)(self + 0x93), (float)d);
}
PCREG(4f7520, f4f7520);
