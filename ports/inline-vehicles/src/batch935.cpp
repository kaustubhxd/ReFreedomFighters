// batch935.cpp - vehicles thread, batch 935: ZMoveOnSpline::ClassInit (0x512590), thiscall, no arguments.
// For each child geom (list at +0x50, next at +0x60) the body is taken from the first child whose name matches
// *CollisionBox*, *Coli* or *Body* and whose +0x54 object answers slot 0x1e0(0x200002); Exit_Box_* children go to the
// list at +0x127, Ground_Box_* children to +0x12b (their entry flag cleared). The body gets the render manager's
// slot 0x50 id, then its ZGEOM gets the message forwarding flags. Without a body: the error line is printed and the
// hook at 0x7003b0 runs (int3 in the exe when it is not set).
//
// Stood-in exe callees (spec side): 0x44a1f0, 0x4db860, 0x4cc1d0, 0x4cbec0. Pure helpers that run as exe code:
// 0x4dc110 (child name) and 0x4cc850 (wildcard match).
#include "ff.h"

extern "C" void THISCALL ext_44a1f0(void *self);
extern "C" void THISCALL ext_4db860(void *child, u32 flag);
extern "C" u32 THISCALL ext_4cc1d0(void *tmp);
extern "C" void THISCALL ext_4cbec0(void *tmp);
extern "C" u32 THISCALL ext_4dc110(void *child);
extern "C" u32 FASTCALL ext_4cc850(u32 name, const char *pattern);

#define STR(a) ((const char *)(a))

// 0x512590 ZMoveOnSpline::ClassInit().
static void THISCALL moveClassInit(u8 *self) {
  vcall<void>(self, 0x124, 1u, 0u, 0u, 0u);
  ext_44a1f0(self);
  *(u32 *)(self + 0x123) = 0;
  u8 *child = *(u8 **)(self + 0x50);
  while (child) {
    // Body search, in the exe's order: *CollisionBox* (name, then the 0x1e0 test when the name is absent), *Coli*
    // (the same), *Body* (the test only when the name is absent). The 0x1e0 test is only asked when it can matter.
    bool isBody = false;
    if (*(u32 *)(self + 0x123) == 0) {
      bool n1 = ext_4cc850(ext_4dc110(child), STR(0x69e524)) == 0;
      if (n1 && vcall<u8>(*(void **)(child + 0x54), 0x1e0, 0x200002u))
        isBody = true;
      if (!isBody && *(u32 *)(self + 0x123) == 0) {
        bool n2 = ext_4cc850(ext_4dc110(child), STR(0x69e534)) == 0;
        if (n2 && vcall<u8>(*(void **)(child + 0x54), 0x1e0, 0x200002u))
          isBody = true;
        if (!isBody && *(u32 *)(self + 0x123) == 0) {
          bool n3 = ext_4cc850(ext_4dc110(child), STR(0x69e53c)) == 0;
          if (n3 && vcall<u8>(*(void **)(child + 0x54), 0x1e0, 0x200002u))
            isBody = true;
        }
      }
    }
    if (isBody) {
      void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
      *(u32 *)(self + 0x123) = vcall<u32>(rm, 0x50, (u32)child);
    } else {
      // Exit boxes (+0x127) or ground boxes (+0x12b).
      if (ext_4cc850(ext_4dc110(child), STR(0x69e544)) == 0) {
        ext_4db860(child, 1);
        void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
        u32 x = vcall<u32>(rm, 0x50, (u32)child);
        vcall<void>(*(void **)(self + 0x127), 4, x);
      } else if (ext_4cc850(ext_4dc110(child), STR(0x69e550)) == 0) {
        ext_4db860(child, 1);
        void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
        u32 x = vcall<u32>(rm, 0x50, (u32)child);
        u32 e = vcall<u32>(*(void **)(self + 0x12b), 4, x);
        *(u32 *)e = 0;
      }
    }
    child = *(u8 **)(child + 0x60);
  }
  if (*(u32 *)(self + 0x123)) {
    u8 *g = (u8 *)vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, *(u32 *)(self + 0x123));
    u8 *t = (u8 *)vcall<u32>(g, 0x10c, 0x68f47cu, 0xffffffffu);
    if (!(t[4] & 1)) {
      vcall<void>(t, 8);
      t[4] |= 4;
    }
    if (t[4] & 1) {
      vcall<void>(t, 0x4c);
      vcall<void>(t, 0x54, *(u32 *)(t + 0x30));
      *(u32 *)(t + 4) |= 0x100;
    }
    vcall<void>(g, 0x3c, 1u);
  } else {
    void *dbg = *(void **)0x700390;
    typedef void *(THISCALL * at)(void *, const char *, u32);
    typedef void(CDECL_FN)(void *, const char *, u32);
    void *o = (*(at *)(*(u8 **)dbg + 0x20))(dbg, STR(0x69e4bc), 0x13au);
    u8 buf[0x20];
    u32 r = vcall<u32>(self, 0x1d8, (u32)buf, 1u);
    u32 s = ext_4cc1d0((void *)r);
    ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, STR(0x69e560), s);
    ext_4cbec0(buf);
    void (*hook)(void) = *(void (**)(void))0x7003b0;
    if (!hook)
      __builtin_trap();   // the exe executes int3 here
    hook();
  }
}
PCREG(512590, moveClassInit);
