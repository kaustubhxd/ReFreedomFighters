// batch6540.cpp - unclaimed-65: batch 40 (docs/20-unclaimed-65.md, claim 22): ZWeaponTest::FrameUpdate (0x469220), the whole function
// lifted (thiscall, no arguments). Branch groups are verified one by one (see the doc). No SEH and no cookie in this function.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }

// the slot 0x184 calls of the exe: cdecl-like (the callee takes P as its first stack argument and ignores ecx), so the caller removes
// the arguments. A cdecl function pointer call gives the same stack; ecx is not set (the callee does not read it).
typedef u32(__attribute__((cdecl)) * C4)(u32, u32, u32, u32);
typedef u32(__attribute__((cdecl)) * C5)(u32, u32, u32, u32, u32);

static void callCdecl4(u32 fn, u32 a, u32 b, u32 c, u32 d) { ((C4)fn)(a, b, c, d); }
static void callCdecl5(u32 fn, u32 a, u32 b, u32 c, u32 d, u32 e) { ((C5)fn)(a, b, c, d, e); }

extern "C" void THISCALL ext_46d5f0(u8 *s);   // thiscall, no arguments (another claim; stubbed in the specs)

// 0x469220, ZWeaponTest::FrameUpdate(). See docs/20-unclaimed-65.md (claim 22) for the call conventions.
static void THISCALL frameUpdate(u8 *self) {
  u8 *render = G(u8 *, 0x70039c);
  u8 *o1907 = *(u8 **)(render + 0x1907);

  // the top block: the slot 0x184 call on P (four arguments), then the 0x24 test, then the 0x1907 test, then the index decrement
  u8 *p0 = (u8 *)vc0(render, 0x190);
  callCdecl4(*(const u32 *)(*(const u32 *)p0 + 0x184), (u32)p0, 0, 8, 0x688770);
  const bool b24 = (vc1(render, 0xe8, 0x24) & 0xff) != 0;
  bool dec = b24;
  if (!dec) dec = (vc2(o1907, 0x38, 0x686754, 0) & 0xff) != 0;
  if (dec) {
    u32 idx = *(const u32 *)(self + 0x370);
    if (idx == 0) idx = *(const u32 *)(self + 0x1dc);
    *(u32 *)(self + 0x370) = idx - 1;
  }

  // the 0x23 block: the index increments, or wraps to zero at the end of the count
  bool b23 = (vc1(render, 0xe8, 0x23) & 0xff) != 0;
  if (!b23) b23 = (vc2(o1907, 0x38, 0x686768, 0) & 0xff) != 0;
  if (b23) {
    const u32 last = *(const u32 *)(self + 0x1dc) - 1;
    const u32 cur = *(const u32 *)(self + 0x370);
    *(u32 *)(self + 0x370) = cur >= last ? 0 : cur + 1;
  }

  // the item loop: for each item, P = slot 0x190 and the slot 0x184 call with five arguments (the tag depends on the current index)
  u32 i = 0;
  u32 cursor = (u32)(self + 0x4c);
  while (i < *(const u32 *)(self + 0x1dc)) {
    u8 *p = (u8 *)vc0(render, 0x190);
    const u32 item = *(const u32 *)cursor;
    u32 name = *(const u32 *)(item + 4);
    if (name == 0) name = 0x67c8e8;
    const bool cur = i == *(const u32 *)(self + 0x370);
    // the stack, top first: P, 0, i + 10, the tag, the name (the name is pushed first in the exe, so it is the last argument)
    callCdecl5(*(const u32 *)(*(const u32 *)p + 0x184), (u32)p, 0, i + 0xa, cur ? 0x6887c0 : 0x6887bc, name);
    cursor += 4;
    ++i;
  }

  // the compare of the slot 0x350 result with the current item (46d5f0 when they differ)
  u8 *o1e0 = *(u8 **)(self + 0x1e0);
  const u32 r350 = vc0(o1e0, 0x350);
  if (r350 != *(const u32 *)(self + 0x4c + 4 * *(const u32 *)(self + 0x370))) ext_46d5f0(self);

  // the 0x31 block, with the edge flag at 0x6ff994
  bool r31 = (vc1(render, 0xe4, 0x31) & 0xff) != 0;
  if (!r31) r31 = (vc2(o1907, 0x38, 0x686780, 0) & 0xff) != 0;
  u8 *f994 = (u8 *)0x6ff994;
  if (*f994 == 0) {
    if (r31) {
      u8 *o = *(u8 **)(self + 0x1e0);
      if (o) vc2(o, 0x2d0, 3, 0);
      *f994 = 1;
    }
  } else if (!r31) {
    u8 *o = *(u8 **)(self + 0x1e0);
    if (o) vc2(o, 0x2d0, 0, 0);
    *f994 = 0;
  }

  // the 0x33 block, with the edge flag at 0x6ff995
  bool r33 = (vc1(render, 0xe4, 0x33) & 0xff) != 0;
  if (!r33) r33 = (vc2(o1907, 0x38, 0x686794, 0) & 0xff) != 0;
  u8 *f995 = (u8 *)0x6ff995;
  if (*f995 == 0) {
    if (r33) {
      u8 *o = *(u8 **)(self + 0x1e0);
      if (o) vc2(o, 0x2d0, 5, 0);
      *f995 = 1;
    }
  } else if (!r33) {
    u8 *o = *(u8 **)(self + 0x1e0);
    const u32 v = vc0(o, 0x364);
    if (*(u8 **)(self + 0x1e0)) vc1(*(u8 **)(self + 0x1e0), 0x360, v);
    o = *(u8 **)(self + 0x1e0);
    if (o) vc2(o, 0x2d0, 0, 0);
    *f995 = 0;
  }

  // the 0x34 block, with the edge flag at 0x6ff996
  bool r34 = (vc1(render, 0xe4, 0x34) & 0xff) != 0;
  if (!r34) r34 = (vc2(o1907, 0x38, 0x6867a8, 0) & 0xff) != 0;
  u8 *f996 = (u8 *)0x6ff996;
  if (*f996 == 0) {
    if (r34) {
      u8 *o = *(u8 **)(self + 0x1e0);
      if (o) vc2(o, 0x2d0, 6, 0);
      *f996 = 1;
    }
  } else if (!r34) {
    u8 *o = *(u8 **)(self + 0x1e0);
    if (o) vc2(o, 0x2d0, 0, 0);
    *f996 = 0;
  }
}

PCREG(469220, frameUpdate);
