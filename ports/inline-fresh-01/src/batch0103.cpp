// batch0103.cpp - fresh-01 batch 3 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void THISCALL ext_45c3e0(u8 *self);                 // ZGEOM destructor body
extern "C" void ext_45c510(void *p);                           // ZGEOM::operator delete(void*) (cdecl)
extern "C" void ext_4690b0(void *p, u32 size);                 // empty cdecl body (sized delete in this build)
extern "C" u32 THISCALL ext_5f9570(u32 elem);                  // per-element serial size
extern "C" void ext_61dba0(u8 *a0, u32 a1, u32 *out, u32 a2, u32 a3);   // cdecl, writes *out
extern "C" void ext_620bc0(u8 *a0, u32 v, u32 a2, u32 a3);              // cdecl

typedef u32(STDCALL *moveFileFn)(u32, u32);
typedef u32(THISCALL *s20Fn)(void *, u32, u32);
typedef u32 (*logFn)(void *, u32);
typedef void *(*memmoveFn)(void *, const void *, u32);

// 0x427fd0, ZSysFileGC::Rename(char*, char*): MoveFileA(from, to); on failure logs through [0x700390] slot 0x20
// (0x6789ac, 0x183) and that object's cdecl slot 0x2c(obj, 0x678c90). ECX is not used. EAX is MoveFileA's result, or the
// log call's result after a failure.
static u32 THISCALL sysFileRename(u8 *self, u32 from, u32 to) {
  u32 r = (*(moveFileFn *)0x676130)(from, to);
  if (r) return r;
  u8 *mgr = G(u8 *, 0x700390);
  u8 *o = (u8 *)(*(s20Fn *)(*(u8 **)mgr + 0x20))(mgr, 0x6789ac, 0x183);
  return (*(logFn *)(*(u8 **)o + 0x2c))(o, 0x678c90);
}
PCREG(427fd0, sysFileRename);

// 0x648c10, ZViewBase::AddAlwaysDrawMaterials(): sets bit 0 of +0x18282, +0x1827d = -1, +0x18291 = this+0x18259,
// word +0x1828f = word +0x20; then the draw list entry n = [+0x20]: [+0x2c + n*8] = this+0x1827d,
// [+0x28 + n*8] = 0x8068009; [+0x20]++. Stores in this order.
static void THISCALL viewAddAlwaysDrawMaterials(u8 *self) {
  self[0x18282] |= 1;
  u8 *e = self + 0x1827d;
  *(u32 *)e = 0xffffffffu;
  *(u8 **)(self + 0x18291) = self + 0x18259;
  *(u16 *)(self + 0x1828f) = *(u16 *)(self + 0x20);
  s32 n = *(s32 *)(self + 0x20);
  *(u8 **)(self + n * 8 + 0x2c) = e;
  *(u32 *)(self + n * 8 + 0x28) = 0x8068009;
  ++*(u32 *)(self + 0x20);
}
PCREG(648c10, viewAddAlwaysDrawMaterials);

// 0x4527d0, ZDebugGeom scalar deleting destructor: vtable = 0x6815d8, ZGEOM destructor body 0x45c3e0; flags bit 0:
// delete, through 0x4690b0(this, 0x1c) when bit 2 is set (empty in this build), else ZGEOM::operator delete(this).
static u8 *THISCALL debugGeomScalarDelete(u8 *self, u32 flags) {
  *(u32 *)self = 0x6815d8;
  ext_45c3e0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x1c);
    else ext_45c510(self);
  }
  return self;
}
PCREG(4527d0, debugGeomScalarDelete);

// 0x54f110 (unnamed): moves `cur` toward `target` by at most `step` (signed ints): returns target when it is within
// step, else cur +/- step. Differences wrap like the original's 32-bit subtraction. ECX is not used (ret 0xc).
static s32 STDCALL approach54f110(s32 target, s32 cur, s32 step) {
  if (target == cur) return target;
  if (target > cur) {
    if ((s32)((u32)target - (u32)cur) > step) return (s32)((u32)cur + (u32)step);
    return target;
  }
  if ((s32)((u32)cur - (u32)target) > step) return (s32)((u32)cur - (u32)step);
  return target;
}
PCREG(54f110, approach54f110);

// 0x4afed0, CCutSequenceObjects::LoadInit(): s = render([0x70039c]+0x9b) slot 0x138; n = render slot 0x4c(this+0x44);
// s slot 0x4c(0x69206c, n). s's vtable is read before the second render call.
static u32 THISCALL cutSequenceLoadInit(u8 *self) {
  u8 *s = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
  u8 *svt = *(u8 **)s;
  u32 n = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, *(u32 *)(self + 0x44));
  typedef u32(THISCALL * f4c)(void *, u32, u32);
  return (*(f4c *)(svt + 0x4c))(s, 0x69206c, n);
}
PCREG(4afed0, cutSequenceLoadInit);

// 0x500150 (unnamed): 4 + the sum of 0x5f9570(elem) over the pointer vector [begin=this+0, end=this+4]. The count is
// (end-begin)>>2 (arithmetic shift), re-read each iteration; the loop index compares unsigned.
static u32 THISCALL vectorSerialSize(u8 *self) {
  u32 sum = 4;
  u32 i = 0;
  if (((s32)(*(u32 *)(self + 4) - *(u32 *)self) >> 2) == 0) return sum;
  do {
    sum += ext_5f9570((*(u32 **)self)[i]);
    i++;
  } while (i < (u32)((s32)(*(u32 *)(self + 4) - *(u32 *)self) >> 2));
  return sum;
}
PCREG(500150, vectorSerialSize);

// 0x4d29d0, CGlobalCom::Defrag(): walks the blocks of the buffer at this+8 (size this+0xc); each block starts with its
// size (dword) and an in-use byte at +4. In-use blocks are moved down with memmove when they are not in place;
// the used size becomes the new this+0xc.
static void THISCALL globalComDefrag(u8 *self) {
  u32 w = 0, r = 0;
  if (*(u32 *)(self + 0xc) > 0) {
    do {
      u8 *buf = *(u8 **)(self + 8);
      u32 n = *(u32 *)(buf + r);
      u8 *blk = buf + r;
      r += n;
      if (blk[4]) {
        u8 *dst = buf + w;
        w += n;
        if (r != w) (*(memmoveFn *)0x676278)(dst, blk, n);
      }
    } while (r < *(u32 *)(self + 0xc));
  }
  *(u32 *)(self + 0xc) = w;
}
PCREG(4d29d0, globalComDefrag);

// 0x4f3950, ZWINDOWS::SetShowMouse(bool): w = render([0x70039c]+0x9b) slot 0x58(this+0x73); when w is set, this+0x5fa =
// show and tail-calls w slot 0xbc(show == 0). Returns 0 when w is null.
static u32 THISCALL windowsSetShowMouse(u8 *self, u32 show) {
  u8 *w = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *(u32 *)(self + 0x73));
  if (!w) return 0;
  u8 b = (u8)show;
  self[0x5fa] = b;
  return vcall<u32>(w, 0xbc, (u32)(b == 0));
}
PCREG(4f3950, windowsSetShowMouse);

// 0x61fd10 (unnamed, cdecl): v = a1; 0x61dba0(a0, a0+0x8c dword, &v, a2, a3) may change v; when v != 0,
// a0+0x110 = 0x620bc0 (callback) and 0x620bc0(a0, v, a2, a3).
static void call61fd10(u8 *a0, u32 a1, u32 a2, u32 a3) {
  u32 v = a1;
  ext_61dba0(a0, *(u32 *)(a0 + 0x8c), &v, a2, a3);
  if (v) {
    *(u32 *)(a0 + 0x110) = 0x620bc0;
    ext_620bc0(a0, v, a2, a3);
  }
}
PCREG(61fd10, call61fd10);

// 0x4f1290 (unnamed): if the float pair at this+0x22/+0x26 differs from p[0]/p[1] (NaN counts as different), copies p
// into it, sets this+0x90 = 1 and calls own slot 0x228. The second argument is not used (ret 8).
static void THISCALL setPos4f1290(u8 *self, const u32 *p, u32 unused) {
  float x = bitsf(*(u32 *)(self + 0x22)), px = bitsf(p[0]);
  if (x == px) {
    float y = bitsf(*(u32 *)(self + 0x26)), py = bitsf(p[1]);
    if (y == py) return;
  }
  *(u32 *)(self + 0x22) = p[0];
  *(u32 *)(self + 0x26) = p[1];
  self[0x90] = 1;
  vcall<void>(self, 0x228);
}
PCREG(4f1290, setPos4f1290);
