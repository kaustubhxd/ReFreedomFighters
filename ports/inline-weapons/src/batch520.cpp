// batch520.cpp - weapons thread, batch 520: small ZLNKWHANDS members: hand/list accessors, dialog animations, IK
// targets of the two hands, reset, near items, per-bone damage multipliers.
// Fields: +0x1e6 hit animation name, +0x23e / +0x24e four listen / talk dialog animations, +0x2e3 inventory list,
// +0x2e7 / +0x34f left / right hand slot objects (IK targets at +0x2eb / +0x353), +0x3b7 near-items list,
// +0x3bb dialog flag, +0x3ea.. ten per-bone damage multipliers.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32 (*hookFn)();
struct PMF { u32 fn, adj, vb, vi; };
typedef void(THISCALL *vSetIK)(void *hand, u8 *owner, const float *a, const float *b, float t, PMF cb);
extern "C" void THISCALL ext_467410(void *target, u8 *owner, float time, PMF cb);   // ZTARGET release
extern "C" void THISCALL ext_467710(u8 *self);                                      // ZIKLNKOBJ::Reset
extern "C" void THISCALL ext_466220(u8 *t);                                         // ZTARGET::Clear
extern "C" void THISCALL ext_467f60(u8 *self);                                      // ZIKLNKOBJ::UpdateTargets
extern "C" void THISCALL ext_467cd0(u8 *t, u8 *obj);                                // ZTARGET::Update

static u32 THISCALL getRHand(u8 *s) { return (u32)(s + 0x34f); }
PCREG(4744e0, getRHand);
static u32 THISCALL getLHand(u8 *s) { return (u32)(s + 0x2e7); }
PCREG(474440, getLHand);
static u32 THISCALL getInventoryList(u8 *s) { return *(u32 *)(s + 0x2e3); }
PCREG(4743e0, getInventoryList);
static u32 THISCALL getNearItems(u8 *s) { return *(u32 *)(s + 0x3b7); }
PCREG(4744b0, getNearItems);
static u8 THISCALL getDialog(u8 *s) { return s[0x3bb]; }
PCREG(474310, getDialog);
static void THISCALL setDialog(u8 *s, u8 on) { s[0x3bb] = on != 0; }
PCREG(475910, setDialog);
static void THISCALL setHitAnimation(u8 *s, u32 name) { *(u32 *)(s + 0x1e6) = name; }
PCREG(475930, setHitAnimation);

// 0x475300 Reset(): ZIKLNKOBJ::Reset, clear the aim target and the aim state; aim blend back to 1.
static void THISCALL hReset(u8 *s) {
  ext_467710(s);
  ext_466220(s + 0x26a);
  for (u32 o = 0x3bc; o <= 0x3dc; o += 4)
    *(u32 *)(s + o) = 0;
  s[0x3e9] = 0;
  *(u32 *)(s + 0x1e2) = 0x3f800000;
}
PCREG(475300, hReset);

// 0x475280 RemoveNearItem(h): when the near-items list has it (slot 0x28), remove it (slot 0x3c, tail call).
static void THISCALL removeNearItem(u8 *s, u32 h) {
  u8 *l = *(u8 **)(s + 0x3b7);
  if (!l || !((vUU)VT(l, 0x28))(l, h))
    return;
  l = *(u8 **)(s + 0x3b7);
  ((vUU)VT(l, 0x3c))(l, h);
}
PCREG(475280, removeNearItem);

// Set/Remove L/R HandIKTarget: pass through to the hand slot object (slot 0x1c with the owner) or to the hand's
// ZTARGET release.
static void THISCALL setLHandIKTarget(u8 *s, const float *a, const float *b, float t, PMF cb) {
  u8 *h = s + 0x2e7;
  ((vSetIK)VT(h, 0x1c))(h, s, a, b, t, cb);
}
PCREG(475940, setLHandIKTarget);
static void THISCALL setRHandIKTarget(u8 *s, const float *a, const float *b, float t, PMF cb) {
  u8 *h = s + 0x34f;
  ((vSetIK)VT(h, 0x1c))(h, s, a, b, t, cb);
}
PCREG(4759b0, setRHandIKTarget);
static void THISCALL removeLHandIKTarget(u8 *s, float t, PMF cb) { ext_467410(s + 0x2eb, s, t, cb); }
PCREG(475250, removeLHandIKTarget);
static void THISCALL removeRHandIKTarget(u8 *s, float t, PMF cb) { ext_467410(s + 0x353, s, t, cb); }
PCREG(4752b0, removeRHandIKTarget);

// 0x4760d0 UpdateTargets(): the base class's targets, the aim (own slot 0x4a8 UpdateAimTarget), then both hands.
static void THISCALL updateTargets(u8 *s) {
  ext_467f60(s);
  ((vU0)VT(s, 0x4a8))(s);
  ext_467cd0(s + 0x2eb, s);
  ext_467cd0(s + 0x353, s);
}
PCREG(4760d0, updateTargets);

// 0x4739b0 / 0x4739e0 DialogListen / DialogTalk(n): play animation n (clamped to 0..3) with ActivateAnim (slot
// 0x230), mode 1 for listening and 5 for talking.
static inline s32 clamp3(s32 n) { return n < 0 ? 0 : (n > 3 ? 3 : n); }
static void THISCALL dialogListen(u8 *s, s32 n) {
  ((vUUU)VT(s, 0x230))(s, *(u32 *)(s + 0x23e + 4 * clamp3(n)), 1);
}
PCREG(4739b0, dialogListen);
static void THISCALL dialogTalk(u8 *s, s32 n) {
  ((vUUU)VT(s, 0x230))(s, *(u32 *)(s + 0x24e + 4 * clamp3(n)), 5);
}
PCREG(4739e0, dialogTalk);

// Get/SetDamageMultForBone(bone): ten float multipliers; bone -> offset 0:+0x3ea 1:+0x3fe 2:+0x402 3:+0x406 4:+0x40a
// 5:+0x3ee 6:+0x3f6 7:+0x40e 8:+0x3f2 9:+0x3fa. Get asserts on other bones (and returns 0); Set ignores them.
static const u16 kBoneOff[10] = {0x3ea, 0x3fe, 0x402, 0x406, 0x40a, 0x3ee, 0x3f6, 0x40e, 0x3f2, 0x3fa};
static float THISCALL getDamageMult(u8 *s, u8 bone) {
  if (bone > 9) {
    hookFn h = G(hookFn, 0x7003b0);
    if (!h)
      __builtin_debugtrap();
    h();
    return 0.0f;
  }
  return *(float *)(s + kBoneOff[bone]);
}
PCREG(474250, getDamageMult);
static void THISCALL setDamageMult(u8 *s, u8 bone, u32 v) {
  if (bone > 9)
    return;
  *(u32 *)(s + kBoneOff[bone]) = v;
}
PCREG(475820, setDamageMult);
