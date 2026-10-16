// batch1003.cpp - fresh-10 batch 3: destructors, save/load helpers, list walkers (slice 10).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)
typedef void *(THISCALL *logpos_t)(void *, u32, u32);
static inline void *LogAt(u32 file, u32 line) {
  void *l = G(void *, 0x700390);
  return (*(logpos_t *)(*(u8 **)l + 0x20))(l, file, line);
}
typedef void (*hook_t)();
static inline void AssertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}

// 0x4d4d60 ZBigFile::~ZBigFile() (scalar deleting): vtable 0x69666c, [+0x11] = 0, delete([+0xd], 1),
// base vtable 0x696634, delete(this, 0x15) when flag & 1.
static u8 *THISCALL BigFileDtor(u8 *self, u32 flags) {
  void *p = *(void **)(self + 0xd);
  *(u32 *)self = 0x69666c;
  *(u32 *)(self + 0x11) = 0;
  ext_634273(p, 1);
  *(u32 *)self = 0x696634;
  if (flags & 1) ext_634273(self, 0x15);
  return self;
}
PCREG(4d4d60, BigFileDtor);

// 0x4f6820 CAutoScroller::FrameUpdate(): starts once (+0x50 = 1 when +0x50 and +0x51 are clear), then
// target.slot374(rm.dt (+0x48) * speed (+0x4c) + target.pos (+0xa3), 1).
typedef void(THISCALL *setf_t)(void *, float, u32);
static void THISCALL AutoScrollerFrameUpdate(u8 *self) {
  if (!self[0x50] && !self[0x51]) self[0x50] = 1;
  u8 *t = *(u8 **)(self + 0x44);
  float v = *(float *)(G(u8 *, 0x70039c) + 0x48) * *(float *)(self + 0x4c);
  v = v + *(float *)(t + 0xa3);
  (*(setf_t *)(*(u8 **)t + 0x374))(t, v, 1);
}
PCREG(4f6820, AutoScrollerFrameUpdate);

// 0x5f3160 SerialInfo_t::savebool(bool) (medium): writes the bool as a dword at the cursor (+8), cursor += 4;
// the assert hook runs first when cursor + 4 passes the end (+0xc).
static void THISCALL SaveBool(u8 *self, u32 b) {
  if (*(u32 *)(self + 8) + 4 > *(u32 *)(self + 0xc)) AssertHook();
  **(u32 **)(self + 8) = (u8)b;
  *(u32 *)(self + 8) += 4;
}
PCREG(5f3160, SaveBool);

// 0x4f42a0 ZWINPIC::SaveGeometry(ZSaveGame*): slot 0x3c for +0x2e and +0x32, slot 0x24 for +0x2a, +0x36, +0x3a.
static void THISCALL WinpicSaveGeometry(u8 *self, void *sv) {
  vcall<void>(sv, 0x3c, *(u32 *)(self + 0x2e));
  vcall<void>(sv, 0x3c, *(u32 *)(self + 0x32));
  vcall<void>(sv, 0x24, *(u32 *)(self + 0x2a));
  vcall<void>(sv, 0x24, *(u32 *)(self + 0x36));
  vcall<void>(sv, 0x24, *(u32 *)(self + 0x3a));
}
PCREG(4f42a0, WinpicSaveGeometry);

// 0x49b2e0 ZLoadGame::Load(unsigned) (the map says two arguments; ret 4 shows one): current (+0xc) = the 16-byte
// entry of the table (+0x10, count +8) whose first dword is id + 1; when none matches, the assert hook.
typedef u32 (*hookr_t)();
static u32 THISCALL LoadGameLoad(u8 *self, u32 id) {
  u32 key = id + 1, n = *(u32 *)(self + 8);
  if (n) {
    u8 *t = *(u8 **)(self + 0x10);
    for (u32 i = 0; i != n; i++)
      if (*(u32 *)(t + 16 * i) == key) {
        u32 e = (u32)(t + 16 * i);
        *(u32 *)(self + 0xc) = e;
        return e;
      }
  }
  hookr_t h = G(hookr_t, 0x7003b0);
  if (!h) asm volatile("int3");
  return h();
}
PCREG(49b2e0, LoadGameLoad);

// 0x4ce960 ALLOCREF::PrintRef(unsigned): log file 0x695b7c line 0x604, format 0x695cf8 (ref, ref & mask (+0x10),
// ref >> shift (+0x14)).
typedef void (*logp4_t)(void *, u32, u32, u32, u32);
static void THISCALL AllocRefPrintRef(u8 *self, u32 ref) {
  void *p = LogAt(0x695b7c, 0x604);
  (*(logp4_t *)(*(u8 **)p + 0x2c))(p, 0x695cf8, ref, ref & *(u32 *)(self + 0x10), ref >> (*(u32 *)(self + 0x14) & 31));
}
PCREG(4ce960, AllocRefPrintRef);

// 0x4cfae0 GUESS: pops every entry of the table at +8 (count +0x1c8) and frees the block before each (CRT free).
typedef void (*free_t)(void *);
static void THISCALL FreeAll4cfae0(u8 *self) {
  while (*(u32 *)(self + 0x1c8)) {
    u32 i = --*(u32 *)(self + 0x1c8);
    G(free_t, 0x6762ec)(*(void **)(*(u8 **)(self + 8 + 4 * i) - 4));
  }
}
PCREG(4cfae0, FreeAll4cfae0);

// 0x4b1c20 ZCutPushSceneOnKeyStart::FrameUpdate(): if keys (rm+0x1907).slot2c(key (+0x4c), 0): scene (rm+0x9b)
// slot a8(), then slot a0(scene id (+0x48)).
static void THISCALL CutPushSceneFrameUpdate(u8 *self) {
  if (vcall<bool>(*(void **)(G(u8 *, 0x70039c) + 0x1907), 0x2c, *(u32 *)(self + 0x4c), 0u)) {
    vcall<void>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0xa8);
    vcall<void>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0xa0, *(u32 *)(self + 0x48));
  }
}
PCREG(4b1c20, CutPushSceneFrameUpdate);

// 0x61cce0 GUESS (cdecl): 0x61ce20(o, [o+0x8c], &a, b, d); if a (as the callee left it): [o+0x110] = 0x61cd30,
// 0x61d090(o, 0, [o+0x8c], a, b, d).
extern "C" void ext_61ce20(u8 *, u32, u32 *, u32, u32);
extern "C" void ext_61d090(u8 *, u32, u32, u32, u32, u32);
static void F61cce0(u8 *o, u32 a, u32 b, u32 d) {
  ext_61ce20(o, *(u32 *)(o + 0x8c), &a, b, d);
  if (a) {
    *(u32 *)(o + 0x110) = 0x61cd30;
    ext_61d090(o, 0, *(u32 *)(o + 0x8c), a, b, d);
  }
}
PCREG(61cce0, F61cce0);

// 0x444260 ZROOM::AttachGeom(ZBaseGeom*, bool, bool): ZGROUP::AttachGeom, then for a geom whose (+0x54)->(+0xc)
// type (+0x23) is 0x200015: this.slot360(scene (rm+0x9b).slot50(geom)).
extern "C" void THISCALL ext_43ef30(void *, void *, u32, u32);
static void THISCALL RoomAttachGeom(u8 *self, u8 *g, u32 a, u32 b) {
  ext_43ef30(self, g, a, b);
  u8 *x = *(u8 **)(g + 0x54);
  if (x && *(u32 *)(*(u8 **)(x + 0xc) + 0x23) == 0x200015) {
    u32 r = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x50, g);
    vcall<void>(self, 0x360, r);
  }
}
PCREG(444260, RoomAttachGeom);

// 0x6482a0 / 0x6483e0 ZDrawArray<...>::Add() (medium): walk the free list from the cursor (+8) for a block whose
// word +2 is not 0xffff (stop at the start or a null link); else grow; count (+0xc)++ and take a slot from the block.
template <u32 GROW, u32 TAKE>
static u32 THISCALL DrawArrayAdd(u8 *self) {
  typedef bool(THISCALL * grow_t)(void *);
  typedef u32(THISCALL * take_t)(void *);
  u8 *start = *(u8 **)(self + 8);
  if (start) {
    u8 *e = start;
    for (;;) {
      if (*(u16 *)(e + 2) != 0xffff) {
        ++*(u32 *)(self + 0xc);
        return ((take_t)TAKE)(e);
      }
      e = *(u8 **)(e + 8);
      *(u8 **)(self + 8) = e;
      if (e == start || !e) break;
    }
  }
  if (!((grow_t)GROW)(self)) return 0;
  ++*(u32 *)(self + 0xc);
  return ((take_t)TAKE)(*(void **)(self + 8));
}
PCREG(6482a0, (DrawArrayAdd<0x648c50, 0x648630>));
PCREG(6483e0, (DrawArrayAdd<0x63b3c0, 0x648690>));

// 0x6361e0 GUESS constructor: vtable 0x6c2114, +4 = 'ABGR' (0x52474241), fields +8..+0x1c and +0x29 cleared, +0x28 = 0.
static u8 *THISCALL Ctor6361e0(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x52474241;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)self = 0x6c2114;
  return self;
}
PCREG(6361e0, Ctor6361e0);

// 0x5ff0a0 GUESS: doubles a u16 array {data, count}: new(count*2 elements * 2 bytes, -1 on overflow), copy the old
// count, free the old block (0x41e2c0), count *= 2.
extern "C" u16 *ext_41e290(u32 n);
extern "C" void ext_41e2c0(void *p);
static void THISCALL GrowU16(u8 *self) {
  u16 *old = *(u16 **)self;
  u32 n2 = *(u32 *)(self + 4) * 2;
  u64 bytes = (u64)n2 * 2;
  u16 *nw = ext_41e290(bytes >> 32 ? 0xffffffff : (u32)bytes);
  *(u16 **)self = nw;
  for (u32 i = 0; i < *(u32 *)(self + 4); i++) (*(u16 **)self)[i] = old[i];
  ext_41e2c0(old);
  *(u32 *)(self + 4) = n2;
}
PCREG(5ff0a0, GrowU16);

// 0x454f20 ZMaterialDescGroup::GetMaterialDescriptor(unsigned) const: iterate the group (+0x5c) with slot 4c (begin)
// and slot 5c (next); returns the first element whose id (+0x34) matches, else 0.
static u8 *THISCALL GetMaterialDescriptor(u8 *self, u32 id) {
  void *g = *(void **)(self + 0x5c);
  if (!g) return 0;
  u32 it[3];
  vcall<void>(g, 0x4c, it);
  u8 *e = vcall<u8 *>(*(void **)(self + 0x5c), 0x5c, it);
  while (it[0]) {
    if (*(u32 *)(e + 0x34) == id) return e;
    e = vcall<u8 *>(*(void **)(self + 0x5c), 0x5c, it);
  }
  return 0;
}
PCREG(454f20, GetMaterialDescriptor);
