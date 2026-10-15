// batch516.cpp - weapons thread, batch 516: ZWeaponRecycleList, the list of dropped weapons that are deleted after a
// lifetime, and ZFFHERO::RemoveFromWeaponRecycleList (picking a dropped weapon up again).
// ZWeaponRecycleList (an event object registered as "rWeaponRecycleList"): +0x48 count, +0x4c entries of 8 bytes
// {ZItem* item, float expiry time (s)}, +0x44c float lifetime (s, read from the level data).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_5e93f0(u8 *list, u32 item, u8 all);   // RemoveWeapon

static const char *const kName = (const char *)0x6acf30;   // "rWeaponRecycleList"
static inline u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x5e9300 AddWeapon(item): append {item, now + lifetime} (no bounds check).
static void THISCALL addWeapon(u8 *self, u32 item) {
  s32 now = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  s32 d = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x44c) * -1024.0f));
  u32 i = *(u32 *)(self + 0x48);
  *(u32 *)(self + 0x4c + i * 8) = item;
  *(float *)(self + 0x50 + i * 8) = (float)(s32)((u32)now - (u32)d) * 0.0009765625f;
  (*(u32 *)(self + 0x48))++;
}
PCREG(5e9300, addWeapon);

static inline void eraseAt(u8 *self, u32 i) {
  u32 *cnt = (u32 *)(self + 0x48);
  u32 *e = (u32 *)(self + 0x4c);
  for (; i < *cnt - 1; i++) {
    e[2 * i] = e[2 * i + 2];
    e[2 * i + 1] = e[2 * i + 3];
  }
  (*cnt)--;
}

// 0x5e93f0 RemoveWeapon(item, all): all = false removes the first entry holding `item`; all = true removes every
// empty (null item) entry. Exe quirk kept: after removing an empty entry the scan skips the entry that moved into
// its place, so two empty entries in a row are not both removed in one call.
static void THISCALL removeWeapon(u8 *self, u32 item, u8 all) {
  u32 *cnt = (u32 *)(self + 0x48);
  u8 *base = self + 0x4c;
  u8 *p = base;
  if (p == base + *cnt * 8)
    return;
  for (;;) {
    if (all) {
      if (*(u32 *)p != 0) {
        p += 8;
      } else {
        u8 *oldEnd = base + *cnt * 8;
        u32 i = (u32)(p - base) >> 3;
        p += 8;
        eraseAt(self, i);
        if (p == oldEnd)
          return;
      }
    } else {
      if (*(u32 *)p == item) {
        eraseAt(self, (u32)(p - base) >> 3);
        return;
      }
      p += 8;
    }
    if (p == base + *cnt * 8)
      return;
  }
}
PCREG(5e93f0, removeWeapon);

// 0x5e9150 FrameUpdate(): every weapon whose expiry has passed is taken out of the game's geom list
// ([0x7003b8]: count +0x8b4, array +0x8b8; swap with the last), deleted (slot 0x210(1)) and its entry emptied; then
// the empty entries are purged. (The item's GetItemTemplate, slot 0x2e8, is called first and its result unused.)
static void THISCALL recycleFrameUpdate(u8 *self) {
  float now = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;
  for (u8 *p = self + 0x4c; p != self + 0x4c + *(u32 *)(self + 0x48) * 8; p += 8) {
    u8 *it = *(u8 **)p;
    if (!it || !(now > *(float *)(p + 4)))
      continue;
    ((vU0)VT(it, 0x2e8))(it);
    u8 *g = G(u8 *, 0x7003b8);
    u32 item = *(u32 *)p;
    u32 *a = (u32 *)(g + 0x8b8);
    for (; a != (u32 *)(g + (*(u32 *)(g + 0x8b4) + 0x22e) * 4); a++) {
      if (*a == item) {
        *a = *(u32 *)(g + *(u32 *)(g + 0x8b4) * 4 + 0x8b4);
        (*(u32 *)(g + 0x8b4))--;
        break;
      }
    }
    it = *(u8 **)p;
    if (it)
      ((vUU)VT(it, 0x210))(it, 1);
    *(u32 *)p = 0;
  }
  ext_5e93f0(self, 0, 1);
}
PCREG(5e9150, recycleFrameUpdate);

// 0x5e90f0 Init(): look the name up in the event table (render manager slot 0x138 object, slot 0x88; result unused)
// and register this object under it (slot 0x5c(name, this, 2)).
static void THISCALL recycleInit(u8 *self) {
  u8 *x = (u8 *)((vU0)VT(rmgr(), 0x138))(rmgr());
  u32 found = 0;
  ((vUUU)VT(x, 0x88))(x, (u32)kName, (u32)&found);
  x = (u8 *)((vU0)VT(rmgr(), 0x138))(rmgr());
  ((vUUUU)VT(x, 0x5c))(x, (u32)kName, (u32)self, 2);
}
PCREG(5e90f0, recycleInit);

// 0x5e9070 CopyData(other): count, entries and lifetime.
static void THISCALL recycleCopyData(u8 *self, u8 *o) {
  *(u32 *)(self + 0x48) = *(u32 *)(o + 0x48);
  u32 *d = (u32 *)(self + 0x4c);
  u32 *s = (u32 *)(o + 0x4c);
  for (s32 n = *(s32 *)(o + 0x48); n > 0; n--) {
    d[0] = s[0];
    d[1] = s[1];
    d += 2;
    s += 2;
  }
  *(u32 *)(self + 0x44c) = *(u32 *)(o + 0x44c);
}
PCREG(5e9070, recycleCopyData);

// 0x594540 ZFFHERO::RemoveFromWeaponRecycleList(item): when the hero uses the list (+0x9e7), find it by name and
// remove the item from it.
static void THISCALL heroRemoveFromRecycle(u8 *self, u32 item) {
  if (!self[0x9e7])
    return;
  u8 *x = (u8 *)((vU0)VT(rmgr(), 0x138))(rmgr());
  u32 list = 0;
  ((vUUU)VT(x, 0x88))(x, (u32)kName, (u32)&list);
  ext_5e93f0((u8 *)list, item, 0);
}
PCREG(594540, heroRemoveFromRecycle);
