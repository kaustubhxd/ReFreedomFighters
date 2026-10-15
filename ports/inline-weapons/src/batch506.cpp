// batch506.cpp - weapons thread, batch 506: the sniper scope commands ZItemWeapon::ScopeReady / ScopeFire.
// Both look up the "ScopeCamera" and send it a registered message ("coolioSTART" / "coolioFIRE") with
// ZGEOM::SendCommand(camera, msg id, &flag) (slot 0x12c). The message id comes from ZEngineDataBase::RegisterZMsg
// (render manager slot 0x114: name, 0, file, line, flag pointer; five pushes at the exe site). MSVC pushes &flag (SendCommand's third argument)
// before evaluating RegisterZMsg, which made an earlier reading of this code look like a register bug; it is not.
// The camera's handler may clear the flag; ScopeReady returns it.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u8(THISCALL *vB0)(void *self);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef void(THISCALL *vFind)(void *self, const char *name, u32 *out);
typedef u32(THISCALL *vRegMsg)(void *self, const char *name, u32 z, const char *file, u32 line, u8 *flag);
typedef void(THISCALL *vSend2)(void *self, u32 a, u32 b);

// Shared part; fire = 0 for ScopeReady (needs a chambered bullet, "coolioSTART", zitem.cpp line 0xcb6),
// 1 for ScopeFire ("coolioFIRE", line 0xc9e). Skipped without sniper mode, without an owner, or for an owner that
// IsDerivedFrom(0x200074) with GetController() == 1. Returns ScopeReady's al.
static u8 scope(u8 *self, int fire) {
  u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
  if (!((vB0)VT(t, 0x32c))(t))   // HasSniperMode
    return 1;
  if (!((vU0)VT(self, 0x2f4))(self))
    return 1;
  u8 *o = (u8 *)((vU0)VT(self, 0x2f4))(self);
  if (((vBU)VT(o, 0x1e0))(o, 0x200074)) {
    o = (u8 *)((vU0)VT(self, 0x2f4))(self);
    if (((vU0)VT(o, 0x420))(o) == 1)
      return 1;
  }
  if (!fire && !((vB0)VT(self, 0x354))(self))   // GetBulletInChamber
    return 0;
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (u8 *)((vU0)VT(rm, 0x138))(rm);
  u32 cam = 0;
  ((vFind)VT(x, 0x88))(x, (const char *)0x688d74, &cam);   // "ScopeCamera"
  u8 flag = 1;
  rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 id = ((vRegMsg)VT(rm, 0x114))(rm, fire ? (const char *)0x688d80 : (const char *)0x688d8c, 0,
                                    (const char *)0x6887c4, fire ? 0xc9e : 0xcb6, &flag) & 0xffff;   // five pushes
  ((vSend2)VT(self, 0x12c))(self, cam, id);   // two pushes at the exe site (cam, id)
  return flag;
}
static u8 THISCALL scopeReady(u8 *self) { return scope(self, 0); }
static void THISCALL scopeFire(u8 *self) { scope(self, 1); }
PCREG(470a00, scopeReady);
PCREG(470920, scopeFire);
