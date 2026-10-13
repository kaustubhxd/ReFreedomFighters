// batch702.cpp - soldier AI, batch 702 (2026-10-11): CCheckVisible queries and "ping" events.
// 0x700324 is the static CCheckVisible::m_fInvisible (GC symbol _13CCheckVisible.m_fInvisible): any value other than
// exactly 0.0 (NaN included) makes everyone invisible to every seer.
// Event ids: u16 at +0x50 is sent when a seer sees an object, u16 at +0x52 when it loses sight (dispatcher at +0x44,
// slot 0x12c(seer ref, event id, object ref)).
#include "ff.h"

static inline bool cv_everyone_visible() { return G(float, 0x700324) == 0.0f; }
static inline void cv_send(u8 *self, u32 seer, u32 ev, u32 obj) {
  void *disp = *(void **)(self + 0x44);
  vcall<void>(disp, 0x12c, seer, ev, obj);
}

// 0x4a9cb0 CCheckVisible::CanSee(unsigned int seerIdx, unsigned int objRef) const [high]. False when the invisible
// cheat value is set. Unknown object: logs "WARNING: CanSee(): %s does not look at %s" (object name, seer name) and
// returns false. Otherwise true when the pair's state has both the pending and visible bits.
// (SEH frame and stack cookie for the two MYSTR temporaries are not reproduced.)
struct MYSTR_buf { u8 b[0x80]; };
extern "C" const char *THISCALL ext_4cc1d0(void *);
extern "C" void THISCALL ext_4cbec0(void *);
static bool THISCALL cv_CanSee(u8 *self, u32 seer, u32 ref) {
  if (!cv_everyone_visible())
    return false;
  u8 *s = self + seer * 0x1b8;
  u32 i = 0;
  for (; i < 200; i++)
    if (*(u32 *)(self + 0x54 + i * 8) == ref)
      return (*(u16 *)(s + 0x6bc + i * 2) & 0xc000) == 0xc000;
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  void *gObj = vcall<void *>(db, 0x58, ref);
  db = *(void **)(*(u8 **)0x70039c + 0x9b);
  void *gSeer = vcall<void *>(db, 0x58, *(u32 *)(s + 0x694));
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x690610, 0x170);
  MYSTR_buf n1, n2;
  void *m1 = vcall<void *>(gObj, 0x1d8, &n1, 1);
  void *m2 = vcall<void *>(gSeer, 0x1d8, &n2, 1);
  const char *s1 = ext_4cc1d0(m1);
  const char *s2 = ext_4cc1d0(m2);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x690894, s2, s1);
  ext_4cbec0(&n2);
  ext_4cbec0(&n1);
  return false;
}
PCREG(4a9cb0, cv_CanSee);

// Re-announce one pair: pending+visible pairs are re-sent as "seen" (normal case) or, under the invisible cheat,
// lose the visible bit and are sent as "lost".
static inline void cv_ping(u8 *self, u8 *seer, u16 *st, u32 obj) {
  if ((*st & 0xc000) != 0xc000)
    return;
  u32 ev;
  if (cv_everyone_visible()) {
    *st |= 0x4000;
    ev = *(u16 *)(self + 0x50);
  } else {
    u16 v = *st;
    if (!(v >> 14 & 1))
      return;
    *st = v & 0xbfff;
    ev = *(u16 *)(self + 0x52);
  }
  cv_send(self, *(u32 *)seer, ev, obj);
}

// 0x4ab020 CCheckVisible::OnGetAllVisible(void*) [high]: event argument = seer ref. Re-announces every object that
// seer currently sees. 0 if the seer is not registered, else 1.
static u32 THISCALL cv_OnGetAllVisible(u8 *self, u32 seerRef) {
  u32 k = 0;
  for (; k < 200; k++)
    if (*(u32 *)(self + 0x694 + k * 0x1b8) == seerRef)
      break;
  if (k == 200)
    return 0;
  u8 *seer = self + 0x694 + k * 0x1b8;
  for (u32 j = 0; j < 200; j++)
    cv_ping(self, seer, (u16 *)(seer + 0x28) + j, *(u32 *)(self + 0x54 + j * 8));
  return 1;
}
PCREG(4ab020, cv_OnGetAllVisible);

// 0x4ab320 CCheckVisible::OnSendVisiblePing(void*) [medium]: event argument = object ref. Re-announces that object to
// every seer that sees it. 0 if the object is not registered, else 1.
static u32 THISCALL cv_OnSendVisiblePing(u8 *self, u32 objRef) {
  u32 i = 0;
  for (; i < 200; i++)
    if (*(u32 *)(self + 0x54 + i * 8) == objRef)
      break;
  if (i == 200)
    return 0;
  u8 *seer = self + 0x694;
  for (int k = 0; k < 200; k++, seer += 0x1b8)
    cv_ping(self, seer, (u16 *)(seer + 0x28) + i, *(u32 *)(self + 0x54 + i * 8));
  return 1;
}
PCREG(4ab320, cv_OnSendVisiblePing);
