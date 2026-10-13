// batch941.cpp - vehicles thread, batch 941: ZHeli::ClassInit2() (0x51be80), thiscall, no arguments.
// Base class init (0x5124c0, stood in). The heli's track object (TrackLinkObjects, slot 0x25c of the render object) gives
// +0x481. For each child geom (list +0x50, next +0x60), by name:
//   *Cannon_PosBox*  (when +0x44d != 0): the cannon weapon is created (slot 0x328) into +0x405; its position is the
//                    child's root point (0x4db670) mapped to the heli (slot 0x8c);
//   *PilotBox*       the pilot box id -> +0x479 (render manager slot 0x50);
//   WingGun_R*       (when +0x44d != 0) slot 0x388 with +0x411, the child id -> +0x40d;
//   WingGun_L*       (when +0x44d != 0) slot 0x388 with +0x425, the child id -> +0x409;
//   WingRocket*      (when +0x451 != 0 and count +0x449 < 4) slot 0x38c -> +0x439[count], count++.
// Then, without a pilot box: "WARNING! %s HAS NO PilotBox." (line 0x171); with one: slot 0xbc(1) on its object.
// Then the heli's emitter (+0x4ad) gets the dust set (0x516b60, stood in), a direction vector (0.4 rad) (0x516fd0,
// stood in), and +0x4e6 = 50, +0x4ea = 20, +0x4ee = 50, +0x50a = 500, +0x50e = 100.
// Stood in: 0x5124c0, 0x4db670 (root point), 0x516b60, 0x516fd0, the heli's slots 0x328/0x388/0x38c/0x8c, the render
// manager's 0x25c object, the child lookups (0x50, 0x58, 0xbc) and the debug object.
#include "ff.h"

extern "C" void THISCALL ext_5124c0(void *self);
extern "C" u32 THISCALL ext_4dc110(void *child);                          // child name (exe, pure)
extern "C" u32 FASTCALL ext_4cc850(u32 name, const char *pattern);        // wildcard match (exe, pure)
extern "C" void THISCALL ext_4db670(void *child, float *out);             // ZBaseGeom::GetRootPoint (stood in)
extern "C" void THISCALL ext_516b60(void *em, u32 zero, const char *name, void *owner);  // emitter init (stood in)
extern "C" void THISCALL ext_516fd0(void *em, float *v);                  // emitter direction (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *rmobj() { return *(void **)(sysp() + 0x9b); }

// 0x51be80 ZHeli::ClassInit2().
static void THISCALL heliClassInit2(u8 *s) {
  ext_5124c0(s);
  *(u32 *)(s + 0x481) = vcall<u32>(*(void **)((u8 *)rmobj() + 0xadc), 0x25c, 0x685f44u, 0u);
  u32 child = *(u32 *)(s + 0x50);
  while (child) {
    u8 *c = (u8 *)child;
    if (ext_4cc850(ext_4dc110(c), (const char *)0x69f938) == 0) {
      if (*(u32 *)(s + 0x44d)) {
        *(u32 *)(s + 0x405) = vcall<u32>(s, 0x328, *(u32 *)(s + 0x44d), (u32)s, 0x484c5745u);
        float *p = (float *)(s + 0x45d);
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        ext_4db670(c, p);
        vcall<void>(s, 0x8c, p);
      }
    } else if (ext_4cc850(ext_4dc110(c), (const char *)0x69f948) == 0) {
      *(u32 *)(s + 0x479) = vcall<u32>(rmobj(), 0x50, child);
    } else if (ext_4cc850(ext_4dc110(c), (const char *)0x69f954) == 0) {
      if (*(u32 *)(s + 0x44d)) {
        vcall<void>(s, 0x388, (u32)(s + 0x411), child);
        *(u32 *)(s + 0x40d) = vcall<u32>(rmobj(), 0x50, child);
      }
    } else if (ext_4cc850(ext_4dc110(c), (const char *)0x69f960) == 0) {
      if (*(u32 *)(s + 0x44d)) {
        vcall<void>(s, 0x388, (u32)(s + 0x425), child);
        *(u32 *)(s + 0x409) = vcall<u32>(rmobj(), 0x50, child);
      }
    } else if (ext_4cc850(ext_4dc110(c), (const char *)0x69f96c) == 0) {
      if (*(u32 *)(s + 0x451) && *(s32 *)(s + 0x449) < 4) {
        u32 v = vcall<u32>(s, 0x38c, child);
        *(u32 *)(s + 0x439 + 4 * *(s32 *)(s + 0x449)) = v;
        ++*(s32 *)(s + 0x449);
      }
    }
    child = *(u32 *)(c + 0x60);
  }
  if (*(u32 *)(s + 0x479) == 0) {
    void *dbg = *(void **)0x700390;
    typedef void *(THISCALL * at)(void *, const char *, u32);
    typedef void(CDECL_FN)(void *, const char *, const char *);
    void *o = (*(at *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x69f8b8, 0x171u);
    u32 nm = *(u32 *)(s + 4);
    ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, (const char *)0x69f978, nm ? (const char *)nm : (const char *)0x67c8e8);
  }
  if (*(u32 *)(s + 0x479))
    vcall<void>(vcall<void *>(rmobj(), 0x58, *(u32 *)(s + 0x479)), 0xbc, 1u);
  ext_516b60(s + 0x4ad, 0u, (const char *)0x69f9b8, s);
  float v[3] = {0.0f, bitsf(0x3eb2b8c2), 0.0f};
  ext_516fd0(s + 0x4ad, v);
  F(s, 0x50a) = bitsf(0x43fa0000);
  F(s, 0x50e) = bitsf(0x42c80000);
  F(s, 0x4e6) = bitsf(0x42480000);
  F(s, 0x4ea) = bitsf(0x41a00000);
  F(s, 0x4ee) = bitsf(0x42480000);
}
PCREG(51be80, heliClassInit2);
