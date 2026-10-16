// batch1912.cpp - fresh slice 19, batch 1912 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);                            // base constructor (hooked)
extern "C" void ext_4690b0(void *p, u32 n);                               // empty function, here as sized delete (cdecl, hooked)
extern "C" u8 *FASTCALL ext_4f4990(u8 *p, u32 c, u32 a, u32 b);           // (no GC name) ret 8 (hooked)
extern "C" u8 *ext_45c4b0(u32 n);                                         // operator new (cdecl; hooked)
extern "C" void THISCALL ext_4f97f0(u8 *o, u32 c, u32 a, u32 b);          // base constructor ret 0xc (hooked)

extern "C" u32 ext_62c640(u32 hi, u32 lo);                               // UTF-16 byte type of a non-ASCII unit (cdecl, exe code)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

static inline void assert_hook() {
  void (*hook)() = *(void (**)())0x7003b0u;
  if (hook) hook();
  else __builtin_debugtrap();   // the exe falls into an int3 when no hook is set
}

// 0x459ab0 ZParticleBox::DrawBufferViewUpdate(ZDrawBuffer *b, ZCAMERA *cam) ret 8: per-frame view counter +0x1c (reset when
// +0x20 differs from the render manager's frame +0x3c, else incremented); for views 0..3 with geometry +0x40: the view
// block +0xd4 + 0xa0 * view gets cam +0x64 / +0x68 at +8 / +0xc, vt[0x80](m, v) fills a 0x24-byte and a 0xc-byte stack
// object, then b->vt[0x28](+0x40, block, m, v, 0, 0). Returns 0. (Stack cookie not ported.)
typedef void(THISCALL *mv_t)(u8 *, u8 *, u8 *);
typedef void(THISCALL *db28_t)(u8 *, u32, u8 *, u8 *, u8 *, u32, u32);
static bool THISCALL viewUpdate_459ab0(u8 *self, u8 *b, u8 *cam) {
  u8 *rm = *(u8 **)0x70039cu;
  if (*(u32 *)(self + 0x20) != *(u32 *)(rm + 0x3c)) {
    *(u32 *)(self + 0x1c) = 0;
    *(u32 *)(self + 0x20) = *(u32 *)(rm + 0x3c);
  } else {
    (*(u32 *)(self + 0x1c))++;
  }
  u32 i = *(u32 *)(self + 0x1c);
  if (i >= 4) return false;
  u8 *blk = self + 0xd4 + i * 0xa0;
  if (!*(u32 *)(self + 0x40)) return false;
  u8 m[0x24], v[0xc];
  (*(mv_t *)(*(u8 **)self + 0x80))(self, m, v);
  *(u32 *)(blk + 0xc) = *(u32 *)(cam + 0x68);
  *(u32 *)(blk + 8) = *(u32 *)(cam + 0x64);
  (*(db28_t *)(*(u8 **)b + 0x28))(b, *(u32 *)(self + 0x40), blk, m, v, 0, 0);
  return false;
}
PCREG(459ab0, viewUpdate_459ab0);

// 0x4ca8f0 (GC map: ZSpin::CopyEventDataBlock, low confidence; the code is a constructor): base 0x469870, +4 |= 0x20,
// +0x44 = 0, vptr 0x695410, then two RegisterZMsg (db slot 0x114, 4 words) ids into words +0x90 / +0x92. Returns this.
// (SEH frame not ported.)
static u8 *THISCALL ctor_4ca8f0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x695410;
  *(u16 *)(self + 0x90) = (u16)vcall<u32>(DB, 0x114, 0x6954c0u, 0u, 0x695494u, 0x6au);
  *(u16 *)(self + 0x92) = (u16)vcall<u32>(DB, 0x114, 0x6954d4u, 0u, 0x695494u, 0x6bu);
  return self;
}
PCREG(4ca8f0, ctor_4ca8f0);

// 0x5c7af0 ZFFShowMessage scalar deleting destructor (flags) ret 4: +0x44 = +0x30 = 0, vptr 0x686874, db vt[0x34](this);
// flag 1 frees: flag 4 = 0x4690b0(this, 0x52), else the assert hook [0x7003b0] (int3 without one). Returns this.
static u8 *THISCALL sdtor_5c7af0(u8 *self, u32 f) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(DB, 0x34, self);
  if (f & 1) {
    if (f & 4) ext_4690b0(self, 0x52);
    else assert_hook();
  }
  return self;
}
PCREG(5c7af0, sdtor_5c7af0);

// 0x4f4ab0 (no GC name) fastcall (a, b; c, p) ret 8: with p, returns 0x4f4990(p, c, a, b); else new(0x97) built by
// 0x4f97f0(c, a, b), vptr 0x699924, +0x8f = 0, +0x93 = 1; returns it (0 when new fails). (SEH frame not ported.)
static u8 *FASTCALL make_4f4ab0(u32 a, u32 b, u32 c, u8 *p) {
  if (p) return ext_4f4990(p, c, a, b);
  u8 *o = ext_45c4b0(0x97);
  if (!o) return 0;
  ext_4f97f0(o, c, a, b);
  *(u32 *)o = 0x699924;
  *(u32 *)(o + 0x8f) = 0;
  *(u32 *)(o + 0x93) = 1;
  return o;
}
PCREG(4f4ab0, make_4f4ab0);

// 0x622ef0 (no GC name; expat's big2_updatePosition shape) cdecl (enc, p, end, pos): walks 2-byte big-endian units from p
// to end; type = enc +0x4c table for a zero high byte, else 0x62c640(hi, lo); types 6 / 7 step 3 / 4 bytes, LF (10) and CR
// (9, swallowing a following LF) bump the line pos[0] and reset the column, everything else steps 2; column pos[1] + 1
// per step.
static void upd_622ef0(u8 *enc, u8 *p, u8 *end, u32 *pos) {
  if (p == end) return;
  u32 col = pos[1];
  do {
    u32 t = p[0] ? ext_62c640(p[0], p[1]) : enc[0x4c + p[1]];
    switch (t) {
    case 6: p += 3; break;
    case 7: p += 4; break;
    case 9:
      pos[0]++;
      p += 2;
      if (p != end) {
        u32 t2 = p[0] ? ext_62c640(p[0], p[1]) : enc[0x4c + p[1]];
        if (t2 == 10) p += 2;
      }
      col = 0xffffffffu;
      pos[1] = col;
      break;
    case 10:
      col = 0xffffffffu;
      pos[1] = col;
      pos[0]++;
      p += 2;
      break;
    default: p += 2; break;
    }
    pos[1] = ++col;
  } while (p != end);
}
PCREG(622ef0, upd_622ef0);
