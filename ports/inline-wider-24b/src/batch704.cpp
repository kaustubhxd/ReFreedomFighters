// batch704.cpp - soldier AI, batch 704 (2026-10-11): CCheckVisible OnCheckVisibleTo, OnForceVisible, OnSeerAdd.
#include "ff.h"

struct MYSTR_buf { u8 b[0x80]; };
extern "C" const char *THISCALL ext_4cc1d0(void *);
extern "C" void THISCALL ext_4cbec0(void *);
typedef void(__attribute__((cdecl)) * printf1_t)(void *, const char *, const char *);
typedef void(__attribute__((cdecl)) * printf2_t)(void *, const char *, const char *, const char *);

static inline void *geom_of(u32 ref) {
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  return vcall<void *>(db, 0x58, ref);
}
static inline void *debug_log(u32 line) {
  return vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x690610, line);
}

// 0x4aad50 CCheckVisible::OnCheckVisibleTo(void*) [high]: event {seer ref, object ref, u8 result}. Unknown seer: logs
// "WARNING: OnCheckVisibleTo(): %s is not a seer", returns 0. Otherwise result = CanSee(seer index, object), returns 1.
extern "C" bool THISCALL ext_4a9cb0(void *, s32, u32);
static u32 THISCALL cv_OnCheckVisibleTo(u8 *self, u32 *ev) {
  s32 k = 0;
  for (; k < 200; k++)
    if (*(u32 *)(self + 0x694 + k * 0x1b8) == ev[0])
      break;
  if (k == 200) {
    void *g = geom_of(ev[0]);
    void *log = debug_log(0x183);
    MYSTR_buf n;
    void *m = vcall<void *>(g, 0x1d8, &n, 1);
    const char *s = ext_4cc1d0(m);
    (*(printf1_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6908c0, s);
    ext_4cbec0(&n);
    return 0;
  }
  *(u8 *)(ev + 2) = ext_4a9cb0(self, k, ev[1]);
  return 1;
}
PCREG(4aad50, cv_OnCheckVisibleTo);

// 0x4aae40 CCheckVisible::OnForceVisible(void*) [high]: event {seer ref, object ref}. Takes the first seer slot with that
// ref that also has the object registered (the object search repeats for every matching seer slot). Then, ignoring the
// pending bit: normally sets the visible bit and sends "seen" (+0x50); under the invisible cheat (0x700324 != 0) clears
// a set visible bit and sends "lost" (+0x52), or does nothing. Returns 1. Not found: logs
// "Warning: OnForceVisible() Seer %s or Object %s not found" and returns 0.
static u32 THISCALL cv_OnForceVisible(u8 *self, u32 *ev) {
  for (s32 k = 0; k < 200; k++) {
    if (*(u32 *)(self + 0x694 + k * 0x1b8) != ev[0])
      continue;
    for (s32 i = 0; i < 200; i++) {
      if (*(u32 *)(self + 0x54 + i * 8) != ev[1])
        continue;
      u8 *seer = self + 0x694 + k * 0x1b8;
      u16 *st = (u16 *)(seer + 0x28) + i;
      u32 id;
      if (G(float, 0x700324) == 0.0f) {
        *st |= 0x4000;
        id = *(u16 *)(self + 0x50);
      } else {
        u16 v = *st;
        if (!(v >> 14 & 1))
          return 1;
        *st = v & 0xbfff;
        id = *(u16 *)(self + 0x52);
      }
      vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)seer, id, *(u32 *)(self + 0x54 + i * 8));
      return 1;
    }
  }
  void *gObj = geom_of(ev[1]);
  void *gSeer = geom_of(ev[0]);
  void *log = debug_log(0x141);
  MYSTR_buf n1, n2;
  void *m1 = vcall<void *>(gObj, 0x1d8, &n1, 1);
  void *m2 = vcall<void *>(gSeer, 0x1d8, &n2, 1);
  const char *s1 = ext_4cc1d0(m1);
  const char *s2 = ext_4cc1d0(m2);
  (*(printf2_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x690858, s2, s1);
  ext_4cbec0(&n2);
  ext_4cbec0(&n1);
  return 0;
}
PCREG(4aae40, cv_OnForceVisible);

// 0x4ab1c0 CCheckVisible::OnSeerAdd(void*) [high]: obsolete message; always logs
// "Error: Msg_SeerAdd - Use Msg_SeerObjectAdd instead - %s" with the sender's name and returns 0.
static u32 THISCALL cv_OnSeerAdd(u8 *self, u32 ref) {
  void *g = geom_of(ref);
  void *log = debug_log(0xa7);
  MYSTR_buf n;
  void *m = vcall<void *>(g, 0x1d8, &n, 1);
  const char *s = ext_4cc1d0(m);
  (*(printf1_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x69073c, s);
  ext_4cbec0(&n);
  return 0;
}
PCREG(4ab1c0, cv_OnSeerAdd);
