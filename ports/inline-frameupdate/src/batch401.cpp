// batch401.cpp - per-frame update chain: ZFFHERO::HealWounded, ZFFHERO::DisplayUseAction, ZGameOSD::FindNextRecruit.
#include "ff.h"

// MYSTR (GC name; layout inferred from another build of the same engine): char *String, then a 124-byte inline buffer.
struct MYSTR {
  char *String;
  char m_Buffer[124];
};
extern "C" const char *THISCALL ext_4cc1d0(MYSTR *s);   // MYSTR c_str (returns String)
extern "C" void THISCALL ext_4cbec0(MYSTR *s);          // MYSTR::~MYSTR [high]
extern "C" void THISCALL ext_466f60(u8 *self, u32 snd);  // ZIKLNKOBJ::PlaySound [high]
extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *pos, u32 a, s32 b);  // ZGameOSD::CharismaAddExperience [high]
extern "C" void THISCALL ext_5a2e20(u8 *actor, u32 a, u32 b, u32 c, float t);     // ZFFActor::SetRecruitMode [high]
typedef void (*cdeclPrintf)(void *self, const char *fmt, const char *arg);

// ---------------------------------------------------------------- 0x592410 ZFFHERO::HealWounded(ZFFActor*) [high]
// thiscall, ret 4. The /GS cookie and the SEH frame (only for the MYSTR destructor) are not ported.
static void THISCALL heroHealWounded(u8 *self, u8 *actor) {
  if (*(u32 *)(*(u8 **)(actor + 0xc) + 0x23) != 0x2007f9u) {  // class id of ZFFActor (inference from the message)
    u8 *log = G(u8 *, 0x700390);
    u8 *out = vcall<u8 *>(log, 0x20, (const char *)0x6ac6d0u, 0x8edu);  // ZFFHero.cpp, line 2285
    MYSTR name;
    MYSTR *n = vcall<MYSTR *>(actor, 0x1d8, &name, 1u);
    const char *s = ext_4cc1d0(n);
    (*(cdeclPrintf *)(*(u8 **)out + 0x2c))(out, (const char *)0x6acb14u, s);  // "WARNING: ZFFHERO::HealWounded %s is not a class ZFFActor"
    ext_4cbec0(&name);
    return;
  }
  void **vt = *(void ***)actor;
  u32 v = ((u32(THISCALL *)(u8 *))vt[0x6a8 / 4])(actor);
  ((void(THISCALL *)(u8 *, u32))vt[0x6a0 / 4])(actor, v);
  ext_466f60(self, *(u32 *)(self + 0xf06));
  ext_466f60(self, *(u32 *)(self + 0xf02));
  if (*(u32 *)(*(u8 **)(actor + 0x54) + 4) == 2) {
    float mat[9], pos[3];
    vt = *(void ***)actor;
    s32 bone = ((s32(THISCALL *)(u8 *))vt[0x3a0 / 4])(actor);  // slot 0x3a0 (no name; a bone index, like 0x3a8 NeckBoneIndex)
    ((void(THISCALL *)(u8 *, s32, float *, float *))vt[0x390 / 4])(actor, bone, mat, pos);  // ZIKLNKOBJ::GetIKBoneMatPos [high]
    u8 *g = vcall<u8 *>(actor, 0x20);
    vcall<void>(g, 0x84, pos);
    pos[1] = pos[1] + 50.0f;  // [0x680a84]
    ext_596940(*(u8 **)(self + 0x852), *(u32 *)(*(u8 **)(actor + 0x54) + 8) == 1 ? 5u : 4u, pos, 1u, -1);
  }
  ext_5a2e20(actor, 0, 1, 0, 5.0f);
}
PCREG(592410, heroHealWounded);

// ---------------------------------------------------------------- 0x591190 ZFFHERO::DisplayUseAction() [high]
// thiscall, plain ret. The action requested this frame is at +0x9d7 (cleared here); +0x9d3 keeps the last one shown.
extern "C" void THISCALL ext_59a860(u8 *osd, const char *msg, u32 isNew);  // ZGameOSD::SetHelpMessage [high]
// Strings: 1 PickUp, 2 RaiseFlag, 3 CancelRaiseFlag, 4 UseMachineGun, 5 LeaveMachineGun, 6 Recruit, 7 Talk, 8 OpenGate,
// 9 CancelOpenGate, 10 OpenSewer, 11 CancelOpenSewer, 12 AccessSewer, 13 PlaceC4, 14 CancelPlaceC4, 15 GiveHealth,
// 16 ClimbLadder; 17 uses the message at +0x9df. (Jump table at 0x591430.)
static const u32 kUseActionStr[17] = {0,        0x6a73b4, 0x6ad018, 0x6ad024, 0x6ad034, 0x6ad044,
                                      0x6ad054, 0x6ad05c, 0x6ad064, 0x6ad070, 0x6ad080, 0x6ad08c,
                                      0x6ad09c, 0x6ad0a8, 0x6ad0b0, 0x6ad0c0, 0x6ad0cc};
static void THISCALL heroDisplayUseAction(u8 *self) {
  u32 a = *(u32 *)(self + 0x9d7);
  u8 isNew = *(u32 *)(self + 0x9d3) != a;
  *(u32 *)(self + 0x9d3) = a;
  *(u32 *)(self + 0x9d7) = 0;
  *(u32 *)(self + 0x9db) = 0x7e967699u;  // 1e38f, a "far away" distance (inference)
  const char *msg;
  if (a > 0x11) {
    msg = (const char *)0x6ad0d8u;  // "Henning Fix This"
  } else if (a == 0) {
    return;
  } else {
    if (a == 0x11) {
      msg = *(const char **)(self + 0x9df);  // a message set directly by the caller
    } else {
      u8 *loc = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xae4);  // text lookup (slot 0)
      msg = vcall<const char *>(loc, 0x0, (const char *)0x6a73bcu, (const char *)kUseActionStr[a]);  // "Menu/UseActions"
    }
    if (!msg)
      return;
  }
  ext_59a860(*(u8 **)(self + 0x852), msg, isNew);
  *(u32 *)(self + 0x9df) = 0;
}
PCREG(591190, heroDisplayUseAction);

// ---------------------------------------------------------------- 0x597720 ZGameOSD::FindNextRecruit(float*) [high]
// thiscall, ret 4, eax = render-manager handle of the nearest recruitable actor (0 when none); *outDist = its distance.
extern "C" u32 THISCALL ext_597a20(u8 *osd, u32 handle);  // (no name) handle already taken?
extern "C" u32 THISCALL ext_597b10(u8 *osd, u32 handle);  // (no name)
extern "C" u32 THISCALL ext_59ffc0(u8 *actor);            // get +0x77f (batch 48)
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);  // vdist2 [medium]
static u32 THISCALL osdFindNextRecruit(u8 *osd, float *outDist) {
  if (!*(u8 **)(osd + 0x4f7))
    return 0;
  float hpos[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(*(u8 **)(osd + 0x1d0b), 0x84, hpos);
  u32 best = 0;
  float bestD = *(float *)0x67cd44;
  s32 iter = -1;
  u32 team = *(u32 *)(*(u8 **)(*(u8 **)(osd + 0x1d0b) + 0x54) + 0x10);
  u8 *a = vcall<u8 *>(*(u8 **)(osd + 0x4f7), 0x84, hpos, 1500.0f, &iter, team);
  while (a) {
    if (*(u8 **)(osd + 0x1d0b) != a && *(u32 *)(*(u8 **)(a + 0x54) + 8) != 4 && !vcall<u8>(a, 0x438)) {
      u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u32 h = vcall<u32>(rm, 0x4c, a);
      s32 n = *(s32 *)(osd + 0x4ef);
      bool taken = false;
      for (s32 i = 0; i < n; i++)
        if (*(u32 *)(osd + 0x2ef + 4 * i) == h) {
          taken = true;
          break;
        }
      if (!taken && !(u8)ext_597a20(osd, h) && !(u8)ext_597b10(osd, h) && ext_59ffc0(a) != 5) {
        float apos[3] = {0.0f, 0.0f, 0.0f};
        vcall<void>(a, 0x84, apos);
        float d = ext_4e0830(apos, hpos);
        if (!(d > *(float *)0x6ad31c) && bestD > d) {  // 2.25e6 = 1500^2
          bestD = d;
          best = h;
        }
      }
    }
    a = vcall<u8 *>(*(u8 **)(osd + 0x4f7), 0x84, hpos, 1500.0f, &iter, team);
  }
  if (outDist)
    *outDist = (float)crt::sqrt((double)bestD);
  return best;
}
PCREG(597720, osdFindNextRecruit);
