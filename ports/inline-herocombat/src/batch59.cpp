// batch59.cpp - mounted-gun tree, inline session batch 59: ZFFHeroMovementMachinegun::GotControl (0x5e5300) and
// TerminateControl (0x5e7290).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *sendFn)(void *self, u32 name, u32 a, u32 file, u32 line, u32 param, u32 b);
struct Quad { u32 a, b, c, d; };   // passed by value
typedef void(THISCALL *vcallVFQ)(void *self, float f, Quad q);

extern "C" void THISCALL ext_595440(u8 *hero, u32 stash, u32 reason);   // ZFFHERO::StashItem (batch 49)

static u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static u8 *heroOf(u8 *self) { return *(u8 **)(self + 0x36d); }

// The render manager's slot 0x114 builds a message id from a name (with the source file and line), the result is a
// u16; the object's slot 0x128 receives it. "GetItemWeapon" and "GetCenter" pass an out pointer as the parameter.
static void sendTo(u8 *obj, u32 name, u32 line, u32 param) {
  void **ovt = *(void ***)obj;
  u8 *rm = rmgr();
  u16 id = (u16)((sendFn)VT(rm, 0x114))(rm, name, 0, 0x6b7a5cu, line, param, 0);
  ((vcallVU)ovt[0x128 / 4])(obj, id);
}

// 0x5e5300 ZFFHeroMovementMachinegun::GotControl(), thiscall. Marks the gun in use (+0x54c), stamps the hero (+0x36d)
// with the frame time at +0x9e3, sets hero flag 0x2000000 and clears 0x400 in +0x417, gives the hero the gun handle
// (+0x551 to +0x84a) and stashes its item (StashItem(true, 8)). Then it sends the gun (render-manager slot 0x58 of
// +0x551) "GetItemWeapon" (out to +0x555, line 0x813), "GetCenter" (out to +0x559, line 0x818) and "SetOwner" with the
// hero's handle (slot 0x4c, line 0x81c).
static void THISCALL mgGotControl(u8 *self) {
  self[0x54c] = 1;
  *(float *)(heroOf(self) + 0x9e3) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
  *(u32 *)(heroOf(self) + 0x417) |= 0x2000000;
  *(u32 *)(heroOf(self) + 0x417) &= 0xfffffbffu;
  *(u32 *)(heroOf(self) + 0x84a) = *(u32 *)(self + 0x551);
  ext_595440(heroOf(self), 1, 8);
  u8 *rm = rmgr();
  u8 *gun = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x551));
  *(u32 *)(self + 0x555) = 0;
  sendTo(gun, 0x6a584cu, 0x813, (u32)(self + 0x555));   // "GetItemWeapon"
  *(u32 *)(self + 0x559) = 0;
  sendTo(gun, 0x6a585cu, 0x818, (u32)(self + 0x559));   // "GetCenter"
  void **gvt = *(void ***)gun;
  rm = rmgr();
  u32 h = ((vcallUU)VT(rm, 0x4c))(rm, (u32)heroOf(self));
  rm = rmgr();
  u16 id = (u16)((sendFn)VT(rm, 0x114))(rm, 0x6b4a14u, 0, 0x6b7a5cu, 0x81c, h, 0);   // "SetOwner"
  ((vcallVU)gvt[0x128 / 4])(gun, id);
}
PCREG(5e5300, mgGotControl);

// 0x5e7290 ZFFHeroMovementMachinegun::TerminateControl(bool force), thiscall, ret 4, result in al. A forced stop clears
// +0x54c; while it is still set the result is false and nothing happens. Otherwise: the held weapon (+0x555) gets its
// slot 0x2d0(0, 0); the hero's gun handle (+0x84a) and time (+0x9e3) are cleared, its slot 0x4b4(0, (0, 0, 0, -1)) is
// called, flag 0x2000000 is cleared and the item comes back (StashItem(false, 8)); the gun is sent "SetOwner" 0 (line
// 0x82e). Returns true.
static u8 THISCALL mgTerminateControl(u8 *self, u32 force) {
  if ((u8)force)
    self[0x54c] = 0;
  if (self[0x54c] != 0)
    return 0;
  u8 *rm = rmgr();
  u8 *wpn = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x555));
  ((vcallVUU)VT(wpn, 0x2d0))(wpn, 0, 0);
  *(u32 *)(heroOf(self) + 0x84a) = 0;
  *(u32 *)(heroOf(self) + 0x9e3) = 0;
  Quad q = {0, 0, 0, 0xffffffffu};
  u8 *hero = heroOf(self);
  ((vcallVFQ)VT(hero, 0x4b4))(hero, 0.0f, q);
  *(u32 *)(heroOf(self) + 0x417) &= 0xfdffffffu;
  ext_595440(heroOf(self), 0, 8);
  rm = rmgr();
  u8 *gun = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x551));
  sendTo(gun, 0x6b4a14u, 0x82e, 0);   // "SetOwner"
  return self[0x54c] == 0;
}
PCREG(5e7290, mgTerminateControl);

// 0x5950c0 ZFFHERO::SetUseAction(USEACTION a, float prio, const char *name), thiscall, ret 0xc. Keeps the offered use
// action with the smallest value: when prio is below +0x9db, a goes to +0x9d7, prio to +0x9db and name to +0x9df.
static void THISCALL setUseAction(u8 *self, u32 a, float prio, u32 name) {
  if (*(float *)(self + 0x9db) > prio) {
    *(u32 *)(self + 0x9d7) = a;
    *(float *)(self + 0x9db) = prio;
    *(u32 *)(self + 0x9df) = name;
  }
}
PCREG(5950c0, setUseAction);

typedef u32(THISCALL *vcallU0)(void *self);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVUP)(void *self, u32 a, void *b);
typedef u32(THISCALL *vcallUP)(void *self, void *a);
extern "C" void THISCALL ext_5950c0(u8 *hero, u32 a, float prio, u32 name);

// 0x5e8460 ZFFHeroMovementMachinegun::WantControl(const float*, const float *pos, const float*), thiscall, ret 0xc, al.
// On a gun already (hero flag 0x2000000): the in-use byte +0x54c. Otherwise it finds the "MachinegunList" object once
// (render-manager slot 0x138, then its slot 0x88 by name, cached at +0x54d) and walks its list (+0x18; slots 0x4c and
// 0x5c, each handle to +0x551). For each gun, pos goes into the gun's space (slot 0x8c); a gun is in reach when the local
// z is not above 0 and |(x, y, z + 75)| <= 125, and it is taken when asking it "GetOwner" (line 0x7f3) leaves 0. With a
// gun handle at +0x551 the hero is offered use action 4 with value |(x, 0, z + 75)| / 2 (from the last gun looked at),
// and the result is true when the hero's chosen action (+0x9d3) is 4 and the use key (+0x66c) is down.
static u8 THISCALL mgWantControl(u8 *self, const float *, const float *pos, const float *) {
  if (*(u32 *)(heroOf(self) + 0x417) & 0x2000000)
    return self[0x54c];
  if (*(u32 *)(self + 0x54d) == 0) {
    u8 *rm = rmgr();
    u8 *o = (u8 *)((vcallU0)VT(rm, 0x138))(rm);
    u32 tmp = 0;
    ((vcallVUP)VT(o, 0x88))(o, 0x6b4a2cu, &tmp);   // "MachinegunList"
    *(u32 *)(self + 0x54d) = tmp;
  }
  u8 *rm = rmgr();
  u8 *owner = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x54d));
  if (!owner)
    return 0;
  float v[3];
  u32 it;
  u8 *list = *(u8 **)(owner + 0x18);
  if (list) {
    ((vcallVP)VT(list, 0x4c))(list, &it);
    list = *(u8 **)(owner + 0x18);
    *(u32 *)(self + 0x551) = ((vcallUP)VT(list, 0x5c))(list, &it);
    while (it != 0) {
      rm = rmgr();
      u8 *g = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0x551));
      if (g) {
        v[0] = pos[0];
        v[1] = pos[1];
        v[2] = pos[2];
        ((vcallVP)VT(g, 0x8c))(g, v);
        float z = v[2];
        if (!(z > 0.0f)) {
          z += 75.0f;
          v[2] = z;
          float d = (float)crt::sqrt((double)(v[1] * v[1] + v[0] * v[0] + z * z));
          if (!(d > 125.0f)) {
            u32 res = 0;
            void **gvt = *(void ***)g;
            rm = rmgr();
            u16 id = (u16)((sendFn)VT(rm, 0x114))(rm, 0x6a5830u, 0, 0x6b7a5cu, 0x7f3, (u32)&res, 0);   // "GetOwner"
            ((vcallVU)gvt[0x128 / 4])(g, id);
            if (res == 0)
              break;
          }
        }
      }
      list = *(u8 **)(owner + 0x18);
      *(u32 *)(self + 0x551) = ((vcallUP)VT(list, 0x5c))(list, &it);
    }
  }
  if (*(u32 *)(self + 0x551) == 0)
    return 0;
  v[1] = 0.0f;
  float d = (float)crt::sqrt((double)(v[0] * v[0] + 0.0f + v[2] * v[2]));
  ext_5950c0(heroOf(self), 4, d * 0.5f, 0);
  u8 *hero = heroOf(self);
  return *(u32 *)(hero + 0x9d3) == 4 && hero[0x66c] != 0;
}
PCREG(5e8460, mgWantControl);
