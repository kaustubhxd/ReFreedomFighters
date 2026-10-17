// batch942.cpp - vehicles thread, batch 942: ZTank::ClassInit() (0x5207e0), thiscall, no arguments.
// Vehicle class init (0x515630, stood in), then the transform (slot 0x80 into +0x6c / +0x60). The child walk takes the
// turret (*Tower* or *Turret*, when its flags have no 0x100000 bit; otherwise the warning "ZTank::ClassInit -> [%s] is
// not a group!" for it) into +0x25d1. The cannon position (child "Cannon_PosBox", slot 0x25c of the tank) goes into
// +0x25e5 and the machine-gun position ("MachineGun_PosBox") into +0x25f1, each mapped through the turret (slot 0x8c);
// without them the warnings (lines 0xdc / 0xe1) print and the positions are zeroed. Finally the render manager's script
// object ("HitmanGround") gives the player id into +0x2707.
// Stood in: 0x515630, 0x4cc1d0, 0x4cbec0, the debug object and the tank/turret/child/render-manager slots.
#include "ff.h"

extern "C" void THISCALL ext_515630(void *self);
extern "C" u32 THISCALL ext_4dc110(void *child);
extern "C" u32 FASTCALL ext_4cc850(u32 name, const char *pattern);
extern "C" u32 THISCALL ext_4cc1d0(void *tmp);
extern "C" void THISCALL ext_4cbec0(void *tmp);

static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *rmobj() { return *(void **)(sysp() + 0x9b); }
static inline const char *nameOf(u8 *s) { return *(u32 *)(s + 4) ? (const char *)*(u32 *)(s + 4) : (const char *)0x67c8e8; }

typedef void *(THISCALL *dbgAt)(void *, const char *, u32);
typedef void(CDECL_FN)(void *, const char *, const char *);
static void *dbgLine(u32 line) {
  void *dbg = *(void **)0x700390;
  return (*(dbgAt *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x6a04a8, line);
}

// 0x5207e0 ZTank::ClassInit().
static void THISCALL tankClassInit(u8 *s) {
  ext_515630(s);
  vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
  u32 child = *(u32 *)(s + 0x50);
  bool cannonSeen = false, mgSeen = false;   // [ebp-0x91] / [ebp-0x92] start at 0
  while (child) {
    u8 *c = (u8 *)child;
    bool tower = ext_4cc850(ext_4dc110(c), "*Tower*") == 0;
    bool turret = tower || ext_4cc850(ext_4dc110(c), "*Turret*") == 0;
    if (turret) {
      u8 *T = *(u8 **)(c + 0x54);
      *(u32 *)(s + 0x25d1) = (u32)T;
      if (!(*(u32 *)(T + 0xc) ? (*(u32 *)(*(u8 **)(T + 0xc) + 0x23) & 0x100000) : 0)) {
        // the flags object does not carry the group bit: "is not a group!" with the child's name
        void *o = dbgLine(0xc2);
        u8 buf[0x20];
        u32 r = vcall<u32>(T, 0x1d8, (u32)buf, 1u);
        u32 st = ext_4cc1d0((void *)r);
        ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, (const char *)0x6a04fc, (const char *)st);
        ext_4cbec0(buf);
      }
    }
    child = *(u32 *)(c + 0x60);
  }
  u32 cannon = vcall<u32>(s, 0x25c, 0x6a0528u, 0u);
  if (cannon) {
    cannonSeen = true;
    vcall<void>((void *)cannon, 0x84, (u32)(s + 0x25e5));
    vcall<void>(*(void **)(s + 0x25d1), 0x8c, (u32)(s + 0x25e5));
  }
  u32 mg = vcall<u32>(s, 0x25c, 0x6a0538u, 0u);
  if (mg) {
    mgSeen = true;
    vcall<void>((void *)mg, 0x84, (u32)(s + 0x25f1));
    vcall<void>(*(void **)(s + 0x25d1), 0x8c, (u32)(s + 0x25f1));
  }
  if (!cannonSeen) {
    void *o = dbgLine(0xdc);
    ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, (const char *)0x6a054c, nameOf(s));
    *(u32 *)(s + 0x25e5) = 0;
    *(u32 *)(s + 0x25e9) = 0;
    *(u32 *)(s + 0x25ed) = 0;
  }
  if (!mgSeen) {
    void *o = dbgLine(0xe1);
    ((CDECL_FN *)(*(u32 **)o)[0x2c / 4])(o, (const char *)0x6a0584, nameOf(s));
    *(u32 *)(s + 0x25f1) = 0;
    *(u32 *)(s + 0x25f5) = 0;
    *(u32 *)(s + 0x25f9) = 0;
  }
  u32 id = 0;
  vcall<void>(vcall<void *>(rmobj(), 0x138), 0x88, 0x681320u, (u32)&id);
  *(u32 *)(s + 0x2707) = vcall<u32>(rmobj(), 0x58, id);
}
PCREG(5207e0, tankClassInit);
