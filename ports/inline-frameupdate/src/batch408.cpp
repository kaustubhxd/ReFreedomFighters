// batch408.cpp - the root of the hero's per-frame update: ZFFHERO::ClassFrameUpdate (0x58d000, ZFFHERO vtable slot 88).
// Every callee is either lifted in batches 48-55 / 400-407 or by sibling threads; here they are called by address.
// Slot names: PC ZFFHERO / ZFFActor / ZItem / ZEngineDataBase / ZWINDOWS vtables through the name map
// (see docs/20-frameupdate.md, "Corrections").
#include "ff.h"

typedef u16 (THISCALL *RegisterZMsgFn)(void *db, const char *name, u32 a, const char *file, s32 line);
static inline u8 *db() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }  // ZEngineDataBase
static inline u8 *refToPtr(u32 ref) { return vcall<u8 *>(db(), 0x58, ref); }  // GeomRefToPtr
static inline u32 ptrToRef(u8 *p) { return vcall<u32>(db(), 0x4c, p); }       // the inverse (no name)
static inline u16 registerZMsg(const char *name, s32 line) {  // ZEngineDataBase::RegisterZMsg [high]
  u8 *d = db();
  return vcall<u16>(d, 0x114, name, 0u, (const char *)0x6ac6d0u, line);  // ZFFHero.cpp
}
static inline void stamp(u8 *at) {  // tick assignment with the exe's self-assignment check
  u8 *now = G(u8 *, 0x70039c) + 0x40;
  if (at != now)
    *(u32 *)at = *(u32 *)now;
}
static inline s32 cvtt(float x) { return _mm_cvtt_ss2si(_mm_set_ss(x)); }

extern "C" void THISCALL ext_595800(u8 *self);  // ZFFHERO::UpdateFollowers [high]
extern "C" void THISCALL ext_593cc0(u8 *self);  // ZFFHERO::PerformDie [high]
extern "C" void THISCALL ext_6474d0(u8 *bm, u32 on, u32 index);  // ZBoneModifyBase::SetOverrideLODIndex (batch 48)
extern "C" void THISCALL ext_482370(u8 *self);  // ZPlayer::ClassFrameUpdate (batch 400)
extern "C" s32 FASTCALL ext_4cc850(const char *s, const char *pat);  // striwcmp (batch 54)
extern "C" void THISCALL ext_595440(u8 *self, u32 stash, u32 reason);  // ZFFHERO::StashItem (batch 49)
extern "C" u8 *THISCALL ext_591e50(u8 *self, u32 type);              // ZFFHERO::GetItem (batch 49)
extern "C" u8 THISCALL ext_58ff30(u8 *self);                         // ZFFHERO::ControlSpecialItems (batch 55)
extern "C" u8 THISCALL ext_590240(u8 *self);                         // ZFFHERO::ControlWeapons (batch 53)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);  // vdist (batch 48)
extern "C" void THISCALL ext_5d2e60(u8 *cam);                          // ZCamHelper::UpdateFocusSystem (batch 402)
extern "C" u32 THISCALL ext_597720(u8 *osd, float *dist);             // ZGameOSD::FindNextRecruit (batch 401)
extern "C" s32 THISCALL ext_596cf0(u8 *osd);                          // ZGameOSD::CharismaGetRecruitable (batch 48)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);  // PSVECSubtract
extern "C" u32 THISCALL ext_59ffc0(u8 *actor);                        // get +0x77f (batch 48)
extern "C" void FASTCALL ext_43e960(float *a, const float *b);        // a -= b (x87)
extern "C" u8 *THISCALL ext_591d80(u8 *self);                         // find FirstAid_Large (batch 49)
extern "C" void THISCALL ext_5ab070(u8 *o);                           // count frame (batch 48)
struct PMF16 {
  u32 w[4];
};
extern "C" void THISCALL ext_467410(u8 *t, u8 *obj, float fade, PMF16 cb);  // ZTARGET::Remove (batch 402)
extern "C" void THISCALL ext_592410(u8 *self, u8 *actor);  // ZFFHERO::HealWounded (batch 401)
extern "C" void THISCALL ext_591190(u8 *self);             // ZFFHERO::DisplayUseAction (batch 401)
extern "C" void THISCALL ext_596680(u8 *self);             // recruit timeout (batch 48)
extern "C" void THISCALL ext_595250(u8 *self);             // ZFFHERO::StartRagdoll [low]
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);    // vmmul (batch 48)
extern "C" void FASTCALL ext_441940(float *a, const float *b);    // PSVECAdd
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);  // mmul in place (batch 48)
extern "C" void THISCALL ext_5cdb70(u8 *cam);                     // ZCamHelper::ControlBody (batch 400)
extern "C" void THISCALL ext_59c420(u8 *lc);                      // ZFFLevelController::PushEndScene (batch 48)

// Inline copy of StashItem(false, reason) (batch 49), as the exe has it.
static inline void unstash(u8 *self, u32 reason) {
  *(u32 *)(self + 0x836) &= ~reason;
  if (*(u32 *)(self + 0x836)) {
    if (!*(u32 *)(self + 0x832))
      vcall<u8 *>(self, 0x504);  // GetRHandItem, result unused
  } else if (*(u32 *)(self + 0x832)) {
    vcall<void>(self, 0x3dc);                          // RemoveCurrentLnkAction
    vcall<void>(self, 0x480, *(u32 *)(self + 0x832));  // ControlUseOneAlone
    *(u32 *)(self + 0x832) = 0;
  }
}

static void headAndRoot(u8 *self) {
  s32 bone = vcall<s32>(self, 0x3a8);                                         // NeckBoneIndex
  vcall<void>(self, 0x390, bone, (float *)(self + 0x862), (float *)(self + 0x886));  // GetIKBoneMatPos
  vcall<void>(self, 0x98, (float *)(self + 0x862), (float *)(self + 0x886));         // GetRootMatPos
  vcall<void>(self, 0x80, (float *)(self + 0x892), (float *)(self + 0x8b6));         // GetRootTM
}

// ---------------------------------------------------------------- 0x58d000 ZFFHERO::ClassFrameUpdate() [high]
static void THISCALL heroClassFrameUpdate(u8 *self) {
  *(u32 *)(self + 0x829) = 0x3e4ccccdu;  // 0.2
  ext_595800(self);
  if (self[0x827])
    ext_593cc0(self);
  u32 lod;
  if ((*(u8 **)(self + 0x85a))[0xb45]) {
    *(u32 *)(self + 0x417) |= 0x200000;
    lod = 0xff;
  } else {
    *(u32 *)(self + 0x417) &= ~0x200000u;
    lod = 0;
  }
  ext_6474d0(vcall<u8 *>(self, 0x24c), 1, lod);  // GetBoneModifier
  if (!vcall<u8>(self, 0x438))                   // IsDead
    ext_482370(self);
  else
    vcall<void>(self, 0x5ec);  // UpdatePoolGeoms
  *(u32 *)(self + 0x417) &= ~0x4000000u;
  {
    void **dvt = *(void ***)db();
    u32 ref = vcall<u32>(self, 0x428);  // GetContactGeom
    u8 *contact = ((u8 * (THISCALL *)(u8 *, u32)) dvt[0x58 / 4])(db(), ref);
    if (contact) {
      const char *nm = *(const char **)(contact + 4) ? *(const char **)(contact + 4) : (const char *)0x67c8e8u;
      if (!ext_4cc850(nm, (const char *)0x6acac0u)) {  // "WaterWalk*"
        *(u32 *)(self + 0x417) |= 0x4000000;
      } else {
        nm = *(const char **)(contact + 4) ? *(const char **)(contact + 4) : (const char *)0x67c8e8u;
        if (!ext_4cc850(nm, (const char *)0x6acaccu)) {  // "WaterSwim*"
          *(u32 *)(self + 0x417) |= 0x8000000;
          *(float *)(self + 0x9f6) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;
        }
      }
    }
  }
  if (cvtt((*(float *)(self + 0x9f6) + 0.1f) * 1024.0f) < *(s32 *)(G(u8 *, 0x70039c) + 0x40))
    *(u32 *)(self + 0x417) &= ~0x8000000u;  // swimming ends 0.1 s after the last swim contact
  if (*(u32 *)(self + 0x417) & 0x8000000)
    ext_595440(self, 1, 1);
  else
    unstash(self, 1);
  if (*(u32 *)(self + 0x417) & 0x400000)
    ext_595440(self, 1, 0x80);
  else
    unstash(self, 0x80);

  if (vcall<u8>(self, 0x438))
    goto dead;

  headAndRoot(self);
  if (!vcall<u8 *>(self, 0x504) && !*(u32 *)(self + 0x836) && !*(u32 *)(self + 0x832) && !vcall<u32>(self, 0x3f0)) {
    // nothing in hand and nothing going on: take the item remembered at +0x83a back, or the best item
    u8 *o = refToPtr(*(u32 *)(self + 0x83a));
    u8 *item = (o && vcall<u8 *>(o, 0x2f4) == self) ? o : ext_591e50(self, 1);  // ZItem::GetItemOwner
    void **vt = *(void ***)self;
    u32 ref = ptrToRef(item);
    ((void(THISCALL *)(u8 *, u32))vt[0x480 / 4])(self, ref);  // ControlUseOneAlone
    *(u32 *)(self + 0x83a) = 0;
  }
  if (!(*(u32 *)(self + 0x417) & 0x40000) || self[0x70]) {
    u8 *ao = vcall<u8 *>(self, 0x650);  // GetNearestActionObject
    vcall<void>(self, 0x66c, ao);       // UpdateDefaultAction
    if (ao) {
      void **avt = *(void ***)ao;
      u32 ref = ptrToRef(self);
      ((void(THISCALL *)(u8 *, u32))avt[0x90 / 4])(ao, ref);
    }
  }
  if (!(*(u32 *)(self + 0x417) & 0x10000000)) {
    if (!ext_58ff30(self))
      ext_590240(self);
  }
  vcall<void>(self, 0x410);  // UpdateTargets
  if (*(u32 *)(self + 0x83e)) {
    u8 *o = refToPtr(*(u32 *)(self + 0x83e));
    if (o) {  // forget the remembered item once it is more than 150 away (at the hero's height)
      float mat[9], ip[6] = {0, 0, 0, 0, 0, 0}, hp[3];
      vcall<void>(o, 0x2c4, mat, ip);  // ZItem::GetItemRootTM
      (void)hp;
      vcall<void>(self, 0x84, ip + 3);  // GetRootPoint
      ip[1] = ip[4];
      if (ext_4e0870(ip, ip + 3) > 150.0f)  // [0x68af14]
        *(u32 *)(self + 0x83e) = 0;
    }
  }
  if (*(u8 **)(self + 0x85a))
    ext_5d2e60(*(u8 **)(self + 0x85a));
  vcall<void>(self, 0x4a8);  // UpdateAimTarget
  {
    float hp[3] = {0, 0, 0};
    vcall<void>(self, 0x84, hp);
    float dist;
    u32 r = ext_597720(*(u8 **)(self + 0x852), &dist);
    if (r) {
      if (200.0f > dist) {  // [0x67da2c]
        if (*(float *)(self + 0x9db) > dist) {
          *(float *)(self + 0x9db) = dist;
          *(u32 *)(self + 0x9d7) = 6;  // Recruit
          *(u32 *)(self + 0x9df) = 0;
        }
      } else if (self[0xeed] && 800.0f > dist) {  // [0x6ab7e0]
        u8 *sys = G(u8 *, 0x70039c);
        float tm = vcall<float>(sys, 0x1c0, (const char *)0x6ac6d0u, 0x842u);  // TimeStampCounter
        if (tm > 0.9f) {                                                        // [0x683768]
          u8 *osd = *(u8 **)(self + 0x852);
          s32 n = *(s32 *)(osd + 0x1fae);
          if (n < ext_596cf0(osd)) {  // a recruitable one is nearby: it calls out (sound 0x1f)
            u8 *a = refToPtr(r);
            float ap[3] = {0, 0, 0}, dv[3];
            vcall<void>(a, 0x84, ap);
            ext_43e920(dv, hp, ap);
            if (250.0 > __builtin_fabs((double)dv[1]))  // [0x6ad208]
              vcall<void>(a, 0x6e8, 0x1fu, 1u, self);  // ZFFActor::PlaySound_Enum(unsigned char, bool, ZFFHERO*)
          }
        }
      }
    }
    u8 *list = *(u8 **)(self + 0x9e8);
    if (!list)
      goto tail;
    *(u32 *)(self + 0x9ec) = 0;  // nearest actor to talk to
    *(u32 *)(self + 0x9f0) = 0;  // nearest wounded actor to heal
    u32 mask = 4u | (1u << (*(u32 *)(*(u8 **)(self + 0x54) + 4) & 31));
    s32 iter = -1;
    float bestTalk = 40000.0f, bestHeal = 40000.0f;  // [0x6abbb0]
    u8 *a = vcall<u8 *>(list, 0x84, hp, 200.0f, &iter, mask);
    while (a) {
      if (vcall<u8>(a, 0x1e0, 0x2007f9u) && !vcall<u8>(a, 0x438)) {  // a living ZFFActor
        u32 heal = ext_59ffc0(a) == 5 ? 1u : 0u;
        s32 maxhp = vcall<s32>(a, 0x6a8);  // GetMaxHitpoints
        s32 cur = vcall<s32>(a, 0x674);    // GetHitpoints
        bool take = true;
        if (cur < maxhp && *(u32 *)(*(u8 **)(a + 0x54) + 4) == 2)
          heal = (heal & ~0xffu) | 1;
        else if (!(u8)heal && !a[0x920])
          take = false;
        if (take) {
          float ap[3] = {0, 0, 0};
          vcall<void>(a, 0x84, ap);
          ext_43e960(ap, hp);
          float d2 = ap[1] * ap[1] + ap[0] * ap[0];
          d2 = d2 + ap[2] * ap[2];
          if ((u8)heal) {
            if (bestHeal > d2) {
              *(u8 **)(self + 0x9f0) = a;
              bestHeal = d2;
            }
          } else if (bestTalk > d2) {
            *(u8 **)(self + 0x9ec) = a;
            bestTalk = d2;
          }
        }
      }
      a = vcall<u8 *>(*(u8 **)(self + 0x9e8), 0x84, hp, 200.0f, &iter, mask);
    }
    if (u8 *t = *(u8 **)(self + 0x9ec)) {
      float d = (float)crt::sqrt((double)bestTalk);
      if (*(float *)(self + 0x9db) > d) {
        *(float *)(self + 0x9db) = d;
        *(u32 *)(self + 0x9d7) = 7;  // Talk
        *(u32 *)(self + 0x9df) = 0;
      }
      if (*(u32 *)(self + 0x9d3) == 7 && self[0x66c])
        vcall<void>(self, 0x130, t, (u32) * (u16 *)(self + 0x7dc), 0u);  // SendCommand(ZGEOM*, unsigned short, void*)
    }
    if (*(u32 *)(self + 0x9f0)) {
      u8 *item = vcall<u8 *>(self, 0x504);  // GetRHandItem
      u8 large = 0;
      bool found = false;
      if (item) {
        u8 *tpl = vcall<u8 *>(item, 0x2e8);  // ZItem::GetItemTemplate
        const char *nm = *(const char **)(tpl + 4) ? *(const char **)(tpl + 4) : (const char *)0x67c8e8u;
        const char *want = (const char *)0x6acb04u;  // "FirstAid_Large"
        bool eq = true;
        for (;;) {  // MSVC's inline strcmp, two bytes a step
          if (nm[0] != want[0]) {
            eq = false;
            break;
          }
          if (!nm[0])
            break;
          if (nm[1] != want[1]) {
            eq = false;
            break;
          }
          nm += 2;
          want += 2;
          if (!nm[-1])
            break;
        }
        if (eq) {
          large = 1;
          found = true;
        }
      }
      if (!found) {
        item = ext_591d80(self);
        large = 0;
      }
      if (!item && !large && !self[0x9f4])
        goto tail;
      float d = (float)crt::sqrt((double)bestHeal);
      if (*(float *)(self + 0x9db) > d) {
        *(float *)(self + 0x9db) = d;
        *(u32 *)(self + 0x9d7) = 0xf;  // GiveHealth
        *(u32 *)(self + 0x9df) = 0;
      }
      if (*(u32 *)(self + 0x9d3) == 0xf && self[0x66c]) {
        ext_5ab070(*(u8 **)(*(u8 **)(self + 0x852) + 0x1d0f));
        if (large) {  // the large kit in hand is used up: drop it from the hand
          PMF16 none = {{0, 0, 0, 0xffffffffu}};
          u8 *rh = vcall<u8 *>(self, 0x4f8);  // GetRHand
          ext_467410(rh + 4, self, 0.0f, none);
          rh = vcall<u8 *>(self, 0x4f8);
          vcall<void>(rh, 0x8, self, 0u);
          vcall<void>(item, 0x2d0, 3u, 0u);      // ZItem::SetState(ITEMSTATE, CCom*)
          vcall<void>(item, 0x2f0, 0u, 0u, 1u);  // ZItem::SetItemOwner(unsigned, ZGROUP*, bool)
          vcall<void>(item, 0x210, 1u);
        } else if (item) {
          u32 ref = ptrToRef(item);
          void **vt = *(void ***)self;
          u16 msg = registerZMsg((const char *)0x688968u, 0x8c6);  // "MSG_REMOVEITEMFROMINVENTORY"
          ((void(THISCALL *)(u8 *, u8 *, u32, u32))vt[0x130 / 4])(self, self, msg, ref);  // SendCommand
        }
        ext_592410(self, *(u8 **)(self + 0x9f0));
        self[0x66b] = 0;
      }
    }
  }
tail:
  ext_591190(self);
  ext_596680(self);
  if ((s32)(*(u32 *)(self + 0x93a) + 0x66) < *(s32 *)(G(u8 *, 0x70039c) + 0x40)) {
    // breadcrumb trail: every 0x66 ticks (0.1 s) the root point goes into a ring of 10, and +0x942 is the length
    // of the trail
    stamp(self + 0x93a);
    float p[3] = {0, 0, 0};
    vcall<void>(self, 0x84, p);
    u32 i = *(u32 *)(self + 0x93e);
    *(u32 *)(self + 0x93e) = i + 1;
    float *trail = (float *)(self + 0x8c2);
    trail[3 * i] = p[0];
    trail[3 * i + 1] = p[1];
    trail[3 * i + 2] = p[2];
    if (*(u32 *)(self + 0x93e) == 10)
      *(u32 *)(self + 0x93e) = 0;
    *(u32 *)(self + 0x942) = 0;
    for (int k = 0; k < 9; k++) {
      float d[3];
      ext_43e920(d, trail + 3 * k, trail + 3 * (k + 1));
      float l2 = d[0] * d[0] + d[1] * d[1];
      l2 = l2 + d[2] * d[2];
      *(float *)(self + 0x942) = (float)crt::sqrt((double)l2) + *(float *)(self + 0x942);
    }
  }
  return;

dead:
  ext_595250(self);
  vcall<u8>(self, 0x348);  // UpdateAnimationsAndGroundLink
  {
    float m[9], p[3], v[3];
    vcall<void>(self, 0x384, m, p);  // ZPlayer::GetRootCenter
    v[0] = *(float *)(self + 0x48);
    v[1] = *(float *)(self + 0x4c);
    v[2] = *(float *)(self + 0x50);
    ext_4419f0(v, m);
    ext_441940(p, v);
    ext_4de480(m, (const float *)(self + 0x24));
    vcall<void>(self, 0x5f0, m, p);  // SetGroupPos
  }
  headAndRoot(self);
  if (*(u8 **)(self + 0x85a)) {
    ext_5d2e60(*(u8 **)(self + 0x85a));
    ext_5cdb70(*(u8 **)(self + 0x85a));
  }
  {
    float t = *(float *)(self + 0x817);  // time of death, s
    if (t == 0.0f)
      return;
    if (!(cvtt((*(float *)(self + 0x81b) + t) * 1024.0f) < *(s32 *)(G(u8 *, 0x70039c) + 0x40)))
      return;
  }
  {
    u8 *cfg = vcall<u8 *>(db(), 0x134);
    u8 mp = 0;
    vcall<void>(cfg, 0x90, (const char *)0x68a9d4u, &mp);  // "Multiplayer"
    if (mp) {
      void **vt = *(void ***)self;
      u16 msg = registerZMsg((const char *)0x6acad8u, 0x7cb);  // "MSG_ReSpawn"
      u32 ref = ptrToRef(self);
      ((void(THISCALL *)(u8 *, u32, u32, u32))vt[0x12c / 4])(self, ref, msg, 0);  // SendCommand(unsigned, ushort, void*)
    } else {
      if (*(u8 **)(self + 0x9e8)) {  // tell a follower nearby to play the hero-dead music
        float hp[3] = {0, 0, 0}, ap[3];
        vcall<void>(self, 0x84, hp);
        s32 iter = -1;
        ap[0] = ap[1] = ap[2] = 0;
        u8 *a = vcall<u8 *>(*(u8 **)(self + 0x9e8), 0x84, hp, 1200.0f, &iter, 1u);
        while (a) {
          if (vcall<u8>(a, 0x1e0, 0x2007f9u)) {
            vcall<void>(a, 0x84, ap);
            ext_43e960(ap, hp);
            float d2 = ap[1] * ap[1] + ap[0] * ap[0];
            d2 = d2 + ap[2] * ap[2];
            if (1440000.0f > d2) {  // [0x6ad22c] = 1200^2
              void **avt = *(void ***)a;
              u16 msg = registerZMsg((const char *)0x6acae4u, 0x7e4);  // "Msg_Music_Herodead"
              ((void(THISCALL *)(u8 *, u32, u32, u32))avt[0x128 / 4])(a, msg, 0, 0);  // SendCommand(ushort, void*, ZGEOM*)
              break;
            }
          }
          a = vcall<u8 *>(*(u8 **)(self + 0x9e8), 0x84, hp, 1200.0f, &iter, 1u);
        }
      }
      u8 *menus = vcall<u8 *>(db(), 0x138);
      u32 id = 0;
      vcall<void>(menus, 0x88, (const char *)0x6acaf8u, &id);  // "rDEADMENU"
      u8 *w = refToPtr(id);
      u8 *lc = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c15);
      if (*(u32 *)(lc + 0x1044) == 3)
        ext_59c420(lc);
      if (w) {
        u8 *ws = vcall<u8 *>(w, 0x2c4);  // ZWINGROUP::GetSystem
        vcall<void>(ws, 0x2fc, w);        // ZWINDOWS::PushWindow
      }
    }
    *(u32 *)(self + 0x817) = 0;
  }
}
PCREG(58d000, heroClassFrameUpdate);
