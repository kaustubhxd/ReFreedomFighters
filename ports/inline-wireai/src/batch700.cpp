// batch700.cpp - soldier AI, batch 700 (2026-10-11): vision-system (CCheckVisible) and cover-reservation leaves.
// Names come from the GameCube ELF via decoders/gc_pc_namemap.tsv (confidence noted per function).
// CCheckVisible layout used here (PC, packed): objects at +0x54 (8 bytes each), seers at +0x694 (0x1b8 bytes each,
// 200 of them; seer +0 = geom ref, seer +0x28 = 200 u16 per-object states, top two bits flags), +0x15e78 a float.
#include "ff.h"

// 0x4aaa30 CCheckVisible::GetObjectData(unsigned int) const [high]: address of object record idx.
static u8 *THISCALL cv_GetObjectData(u8 *self, u32 idx) { return self + idx * 8 + 0x54; }
PCREG(4aaa30, cv_GetObjectData);

// 0x4aab90 CCheckVisible::GetSeerData(unsigned int) const [high]: address of seer record idx.
static u8 *THISCALL cv_GetSeerData(u8 *self, u32 idx) { return self + idx * 0x1b8 + 0x694; }
PCREG(4aab90, cv_GetSeerData);

// 0x4aabb0 CCheckVisible::GetSeerIndex(unsigned int) const [high]: index of the seer whose ref matches, else -1.
static s32 THISCALL cv_GetSeerIndex(u8 *self, u32 ref) {
  u32 *p = (u32 *)(self + 0x694);
  for (u32 i = 0; i < 200; i++, p = (u32 *)((u8 *)p + 0x1b8))
    if (*p == ref)
      return (s32)i;
  return -1;
}
PCREG(4aabb0, cv_GetSeerIndex);

// 0x4ab410 CCheckVisible::OnSetVisDistMultiplier(void*) [high]: event handler, copies the dword the event points at.
static u32 THISCALL cv_OnSetVisDistMultiplier(u8 *self, u32 *ev) {
  *(u32 *)(self + 0x15e78) = *ev;
  return 0;
}
PCREG(4ab410, cv_OnSetVisDistMultiplier);

// 0x4ab180 CCheckVisible::OnResetTimers(void*) [high]: clears the low 14 bits (timer) of every seer/object state,
// keeping the two flag bits.
static u32 THISCALL cv_OnResetTimers(u8 *self, void *) {
  u8 *seer = self + 0x6bc;
  for (int i = 0; i < 200; i++, seer += 0x1b8) {
    u16 *s = (u16 *)seer;
    for (int j = 0; j < 200; j++)
      s[j] &= 0xc000;
  }
  return 0;
}
PCREG(4ab180, cv_OnResetTimers);

// 0x4ab280 CCheckVisible::OnSeerDel(void*) [medium]: frees the seer slot whose ref equals the event argument itself
// (the PC code compares the pointer value, it does not read through it).
static u32 THISCALL cv_OnSeerDel(u8 *self, u32 ref) {
  for (u32 i = 0; i < 200; i++) {
    if (*(u32 *)(self + 0x694 + i * 0x1b8) == ref) {
      *(u32 *)(self + 0x694 + i * 0x1b8) = 0;
      return 0;
    }
  }
  return 0;
}
PCREG(4ab280, cv_OnSeerDel);

// 0x5de9c0 CReservable::Release() [medium]: clears the holder.
static void THISCALL res_Release(u8 *self) { *(u32 *)(self + 4) = 0; }
PCREG(5de9c0, res_Release);

// 0x5de970 named CFFCoverList::SendCoverNoGood(unsigned int) [medium]; the body reads a CReservable-like record
// (+0 expiry in seconds as float, +4 holder): true when held and (int)(expiry * 1024) < engine tick (+0x40).
static bool THISCALL cover_SendCoverNoGood(u8 *self) {
  if (*(u32 *)(self + 4) == 0)
    return false;
  float t = *(float *)self * 1024.0f;   // 0x678620
  s32 ms = _mm_cvttss_si32(_mm_set_ss(t));
  return ms < *(s32 *)(*(u8 **)0x70039c + 0x40);
}
PCREG(5de970, cover_SendCoverNoGood);

// 0x5de9d0 CReservable::Reserve(unsigned int, float) [high]. Holder at +4, expiry (seconds) at +0.
// If already held by someone else, logs "WARNING: Actor %s tried to renew a not-freed reservable held by %s ..."
// through the debug logger (0x700390). Engine (0x70039c): +0x9b geom database (slot 0x58 = ref to geom ptr),
// +0x40 tick in 1/1024 s. The geom's slot 0x20 returns its class info, whose +4 is the name (or "<NONAME>").
static void THISCALL res_Reserve(u8 *self, u32 who, float time) {
  u32 cur = *(u32 *)(self + 4);
  if (cur != 0 && who != cur) {
    u8 *eng = *(u8 **)0x70039c;
    void *db = *(void **)(eng + 0x9b);
    void *gOld = vcall<void *>(db, 0x58, cur);
    eng = *(u8 **)0x70039c;
    db = *(void **)(eng + 0x9b);
    void *gNew = vcall<void *>(db, 0x58, who);
    void *logger = *(void **)0x700390;
    void *log = vcall<void *>(logger, 0x20, (const char *)0x6b7250, 0xc);
    eng = *(u8 **)0x70039c;
    float now = (float)*(s32 *)(eng + 0x40) * 0.0009765625f;   // 0x6785e4
    u8 *ciOld = vcall<u8 *>(gOld, 0x20);
    const char *nOld = (const char *)0x67c8e8;   // "<NONAME>"
    if (*(const char **)(ciOld + 4))
      nOld = *(const char **)(ciOld + 4);
    u8 *ciNew = vcall<u8 *>(gNew, 0x20);
    const char *nNew = (const char *)0x67c8e8;
    if (*(const char **)(ciNew + 4))
      nNew = *(const char **)(ciNew + 4);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *, const char *, double, double);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6b7288, nNew, nOld, (double)*(float *)self, (double)now);
  }
  *(u32 *)(self + 4) = who;
  s32 d = _mm_cvttss_si32(_mm_set_ss(time * -1024.0f));   // 0x67862c
  s32 tick = *(s32 *)(*(u8 **)0x70039c + 0x40);
  *(float *)self = (float)(tick - d) * 0.0009765625f;
}
PCREG(5de9d0, res_Reserve);

// 0x5df400 CCoverSpot::Reserve(unsigned int, float, unsigned int, bool) [high]: CCoverSpot starts with a
// CReservable. Stores the user ref at +8, sets/clears flag 0x20 at +0x34 from the bool, then reserves.
extern "C" void THISCALL ext_5de9d0(void *, u32, float);
static void THISCALL spot_Reserve(u8 *self, u32 who, float time, u32 user, u32 flag) {   // bool: only the low byte counts
  *(u32 *)(self + 8) = user;
  *(u32 *)(self + 0x34) = (*(u32 *)(self + 0x34) & ~0x20u) | ((u8)flag ? 0x20u : 0u);
  ext_5de9d0(self, who, time);
}
PCREG(5df400, spot_Reserve);

// 0x59e050 ZFFActor::CanSee(unsigned int) [medium]: asks the vision system (actor +0x8ee) with the actor's seer
// index (+0x8f2); false when the actor has no seer slot (-1).
extern "C" bool THISCALL ext_4a9cb0(void *, s32, u32);
static bool THISCALL actor_CanSee(u8 *self, u32 ref) {
  s32 seer = *(s32 *)(self + 0x8f2);
  if (seer == -1)
    return false;
  return ext_4a9cb0(*(void **)(self + 0x8ee), seer, ref);
}
PCREG(59e050, actor_CanSee);
