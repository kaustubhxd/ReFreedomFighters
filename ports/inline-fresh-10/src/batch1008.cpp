// batch1008.cpp - fresh-10 batch 8: list cleanup, wildcard compare, sound scene pop, DBREAD copy, min/max (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)

// 0x49a3e0 GUESS: for each element of the list (+8) (slot4c begin, slot64 next): its block (+4) goes back to the
// allocator (+0x10)->(+4) through 0x4ce1c0(block-4, size dword at block-4), or delete(block, 0) when there is none;
// then the list and the object at +4 are deleted through slot 0 (flag 1) and the fields cleared.
extern "C" void THISCALL ext_4ce1c0(void *, void *, u32);
static void THISCALL FreeBlocks49a3e0(u8 *self) {
  void *l = *(void **)(self + 8);
  if (l) {
    u32 it[3];
    vcall<void>(l, 0x4c, it);
    for (u8 *e = vcall<u8 *>(*(void **)(self + 8), 0x64, it); e; e = vcall<u8 *>(*(void **)(self + 8), 0x64, it)) {
      u8 *d = *(u8 **)(e + 4);
      if (!d) continue;
      void *a = *(void **)(*(u8 **)(e + 0x10) + 4);
      if (a) ext_4ce1c0(a, d - 4, F32(d, -4));
      else ext_634273(d, 0);
    }
    l = *(void **)(self + 8);
    if (l) vcall<void>(l, 0, 1u);
  }
  F32(self, 8) = 0;
  F32(self, 0xc) = 0;
  void *o = *(void **)(self + 4);
  if (o) {
    vcall<void>(o, 0, 1u);
    F32(self, 4) = 0;
  }
}
PCREG(49a3e0, FreeBlocks49a3e0);

// 0x602160 CHostInterface::stricmpwild(const char*, const char*) (high): -1 when pattern b is longer than 1000;
// else striwcmp(a, "*" + b + "*") (strncpy into a 1 KB buffer; the exe's range check after it cannot fire).
typedef char *(*strncpy_t)(char *, const char *, u32);
extern "C" u32 FASTCALL ext_4cc850(const char *, const char *);
static u32 THISCALL StricmpWild(u8 *, const char *a, const char *b) {
  s32 n = 0;
  while (b[n]) n++;
  if (n > 1000) return 0xffffffff;
  char buf[0x404];
  G(strncpy_t, 0x67642c)(buf + 1, b, n);
  buf[0] = '*';
  buf[n + 1] = '*';
  buf[n + 2] = 0;
  return ext_4cc850(a, buf);
}
PCREG(602160, StricmpWild);

// 0x538220 ZDllSound::PopScene() (high): delete +0x52fe (slot 0, flag 1) and +0x5302 (delete size 1), the event
// controller +0x52fa (~CEVENTCONTROLLER, delete 0x1a); ZSoundObjectManager::PopScene (+0x8b); slot208(); slot160(0x81);
// while +0x50ba is set, repeat slot19c() until it returns true.
extern "C" void THISCALL ext_53a8f0(void *);
extern "C" void THISCALL ext_534510(void *);
static void THISCALL DllSoundPopScene(u8 *self) {
  void *a = *(void **)(self + 0x52fe);
  if (a) vcall<void>(a, 0, 1u);
  void *b = *(void **)(self + 0x5302);
  F32(self, 0x52fe) = 0;
  if (b) ext_634273(b, 1);
  void *c = *(void **)(self + 0x52fa);
  F32(self, 0x5302) = 0;
  if (c) {
    ext_53a8f0(c);
    ext_634273(c, 0x1a);
  }
  F32(self, 0x52fa) = 0;
  ext_534510(self + 0x8b);
  vcall<void>(self, 0x208);
  vcall<void>(self, 0x160, 0x81u);
  if (self[0x50ba])
    while (!vcall<u8>(self, 0x19c)) {}
}
PCREG(538220, DllSoundPopScene);

// 0x56f220 CNewMenu::CopyEventDataBlock(DBREAD&) (high): ZSoundController::CopyData(db), then 11 dwords read in
// this order: +0x19d, +0x1a1, +0x1a9, +0x199, +0x1a5, +0x1ad, +0x1b1, +0x1b5, +0x1b9, +0x1bd, +0x1c5.
extern "C" void THISCALL ext_610100(void *, void *);
extern "C" u32 THISCALL ext_4e5e60(void *);
static void THISCALL NewMenuCopyEventDataBlock(u8 *self, void *db) {
  static const u16 offs[11] = {0x19d, 0x1a1, 0x1a9, 0x199, 0x1a5, 0x1ad, 0x1b1, 0x1b5, 0x1b9, 0x1bd, 0x1c5};
  ext_610100(self, db);
  for (int i = 0; i < 11; i++) F32(self, offs[i]) = ext_4e5e60(db);
}
PCREG(56f220, NewMenuCopyEventDataBlock);

// 0x63a2e0 GUESS (fastcall n, rows; stack mn, mx): for each of 4 columns, mn = min (from 0xff) and mx = max (from 0)
// of the n rows of 4 ints (signed compares; n <= 0 leaves the start values).
static void FASTCALL ColumnMinMax(s32 n, s32 *rows, s32 *mn, s32 *mx) {
  for (int c = 0; c < 4; c++) { mn[c] = 0xff; mx[c] = 0; }
  for (int c = 0; c < 4; c++)
    for (s32 i = 0; i < n; i++) {
      s32 v = rows[i * 4 + c];
      if (v < mn[c]) mn[c] = v;
      if (v > mx[c]) mx[c] = v;
    }
}
PCREG(63a2e0, ColumnMinMax);

// 0x45ace0 GUESS (fastcall cls, parent; stack name, geom; SEH frame): o = 0x45c4f0(0x24, cls); if o: ZSTDOBJ ctor
// (parent, name, geom), vtable 0x683e50, +0x18..+0x20 = 10.0f, ZBaseGeom::SetPrim(o+8 geom, 0); returns o (0 if none).
extern "C" u8 *ext_45c4f0(u32, u32);
extern "C" void THISCALL ext_43de40(void *, u32, u32, u32);
extern "C" void THISCALL ext_4dcdf0(void *, u32);
static u8 *FASTCALL NewStdObj45ace0(u32 cls, u32 parent, u32 name, u32 geom) {
  u8 *o = ext_45c4f0(0x24, cls);
  if (!o) return 0;
  ext_43de40(o, parent, name, geom);
  F32(o, 0) = 0x683e50;
  F32(o, 0x18) = 0x41200000;
  F32(o, 0x1c) = 0x41200000;
  F32(o, 0x20) = 0x41200000;
  ext_4dcdf0(*(void **)(o + 8), 0);
  return o;
}
PCREG(45ace0, NewStdObj45ace0);
