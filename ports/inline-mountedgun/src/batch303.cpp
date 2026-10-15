// batch303.cpp - mounted gun tree, batch 303: who controls the nest's gun, the "gun no good" release, FrameUpdate.
// Class id 0x2007f9 (IsA, slot 0x1e0) is the gunner type (inferred: an actor; its +0x91c holds the reference of the
// machine gun it uses, its slot 0x504 returns the held weapon, whose slot 0xbc(bool) is toggled on mount/dismount).
// Gun object (reference +0x70): slot 0x2f4 returns the current user, slot 0x2f0(userRef, 0, 0) sets it, slot 0x2d0(0, 0)
// resets something (inferred: the aim). Gun geom +0x44: slot 0x288(gun, 0, 1) and slot 0x12c(target, msg, 0) send events.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef u8 *(THISCALL *vcallP0)(void *self);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vcallVUUU)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *regMsg)(void *self, const char *name, u32 z, const char *file, u32 line);

extern "C" u8 THISCALL ext_5c82a0(void *self, const float *p);   // AimWeaponAt (batch 302)
extern "C" u8 THISCALL ext_5c8470(void *self, u32 ref);          // AimWeaponRef (batch 302)
extern "C" void THISCALL ext_5c8650(void *self);                 // placeUser (batch 302)
extern "C" void THISCALL ext_5c92a0(void *self);                 // SendMachineGunNoGood (this batch)
extern "C" void THISCALL ext_5c9330(void *self, u8 *user);       // setUser (this batch)

static inline u8 *objMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *byRef(u32 ref) {
  u8 *m = objMgr();
  return ((vcallPU)VT(m, 0x58))(m, ref);
}

// 0x5c9330 (no GC match; inferred setUser / "SetMGOwner"-like), thiscall, ret 4.
// The gun's current user (gun slot 0x2f4), if it is a gunner and not `user`, loses the gun: its +0x91c = 0, its held
// weapon gets slot 0xbc(0), and the lock target (+0x88) is cleared. A gunner `user` gets +0x91c = the gun reference
// and its held weapon slot 0xbc(1); a non-null user with no owner set (+0x80 == 0) makes the gun aim at the base's
// slot-0x84 point from (0, 0, 1000). Finally the gun's user is set to user's reference (slot 0x2f0) and slot 0x2d0(0, 0).
static void THISCALL setUser(u8 *self, u8 *user) {
  u8 *gun = byRef(*(u32 *)(self + 0x70));
  u8 *cur = ((vcallP0)VT(gun, 0x2f4))(gun);
  if (cur && ((vcallBU)VT(cur, 0x1e0))(cur, 0x2007f9) && cur != user) {
    *(u32 *)(cur + 0x91c) = 0;
    if (((vcallP0)VT(cur, 0x504))(cur)) {
      u8 *w = ((vcallP0)VT(cur, 0x504))(cur);
      ((vcallVU)VT(w, 0xbc))(w, 0);
    }
    *(u32 *)(self + 0x88) = 0;
  }
  if (user) {
    if (((vcallBU)VT(user, 0x1e0))(user, 0x2007f9)) {
      *(u32 *)(user + 0x91c) = *(u32 *)(self + 0x70);
      if (((vcallP0)VT(user, 0x504))(user)) {
        u8 *w = ((vcallP0)VT(user, 0x504))(user);
        ((vcallVU)VT(w, 0xbc))(w, 1);
      }
    }
    if (*(u32 *)(self + 0x80) == 0) {
      float pt[3] = {0.0f, 0.0f, 1000.0f};
      u8 *base = byRef(*(u32 *)(self + 0x74));
      ((vcallVP)VT(base, 0x84))(base, pt);
      ext_5c82a0(self, pt);
    }
  }
  void **gvt = *(void ***)gun;
  u8 *m = objMgr();
  u32 uref = ((vcallUU)VT(m, 0x4c))(m, (u32)user);
  ((vcallVUUU)gvt[0x2f0 / 4])(gun, uref, 0, 0);
  ((vcallVUU)VT(gun, 0x2d0))(gun, 0, 0);
}
PCREG(5c9330, setUser);

// 0x5c92a0 CMachinegunControlGroup::SendMachineGunNoGood(), GC map [low]; thiscall, no args.
// Clears the owner (+0x80), takes the gun's user, releases the gun (setUser(0)), sends gun-geom slot 0x288(gun, 0, 1),
// and sends the user the "MachineGunNoGood" message (id from manager slot 0x114, file line 0x1a6) via slot 0x128.
static void THISCALL sendMachineGunNoGood(u8 *self) {
  *(u32 *)(self + 0x80) = 0;
  u8 *gun = byRef(*(u32 *)(self + 0x70));
  u8 *user = ((vcallP0)VT(gun, 0x2f4))(gun);
  ext_5c9330(self, nullptr);
  u8 *g = *(u8 **)(self + 0x44);
  ((vcallVUUU)VT(g, 0x288))(g, (u32)gun, 0, 1);
  void **uvt = *(void ***)user;
  u8 *m = objMgr();
  u16 id = (u16)((regMsg)VT(m, 0x114))(m, (const char *)0x6a4e60, 0, (const char *)0x6b49b8, 0x1a6);
  ((vcallVUUU)uvt[0x128 / 4])(user, id, 0, 0);
}
PCREG(5c92a0, sendMachineGunNoGood);

// 0x5c8d40 CMachinegunControlGroup::FrameUpdate(), GC map [high]; thiscall, no args. Only with a lock target (+0x88):
// once the clock passes the lock expiry (+0x8c seconds), the target is cleared and the gun geom sends it the message
// whose id is in 0x714380 (slot 0x12c(target, id, 0)); if no new target was set by that, the owner is cleared, the
// gun released (setUser(0)) and gun-geom slot 0x288(gun, 0, 1) sent. Otherwise, with an owner (+0x80), the gun is
// placed on its base and aimed at the owner (AimWeaponRef); a clamped aim releases it (SendMachineGunNoGood).
static void THISCALL frameUpdate(u8 *self) {
  u32 tgt = *(u32 *)(self + 0x88);
  if (!tgt)
    return;
  s32 expiry = (s32)(*(float *)(self + 0x8c) * 1024.0f);   // 0x678620
  if (*(s32 *)(G(u8 *, 0x70039c) + 0x40) > expiry) {
    u8 *g = *(u8 **)(self + 0x44);
    *(u32 *)(self + 0x88) = 0;
    ((vcallVUUU)VT(g, 0x12c))(g, tgt, G(u16, 0x714380), 0);
    if (*(u32 *)(self + 0x88) == 0) {
      *(u32 *)(self + 0x80) = 0;
      u8 *gun = byRef(*(u32 *)(self + 0x70));
      ext_5c9330(self, nullptr);
      u8 *g2 = *(u8 **)(self + 0x44);
      ((vcallVUUU)VT(g2, 0x288))(g2, (u32)gun, 0, 1);
      return;
    }
  }
  if (*(u32 *)(self + 0x80) == 0)
    return;
  ext_5c8650(self);
  if (ext_5c8470(self, *(u32 *)(self + 0x80)))
    ext_5c92a0(self);
}
PCREG(5c8d40, frameUpdate);
