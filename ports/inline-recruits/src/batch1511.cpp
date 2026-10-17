// batch1511.cpp - recruits thread, batch 1511: CFormationControl::CheckRegroup and the "formation of a group" lookup.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define SYS G(u8 *, 0x70039c)
typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);
typedef void *(__attribute__((cdecl)) * memsetFn)(void *, s32, u32);
#define CRT_MEMSET (*(memsetFn *)0x676260)

typedef u64(THISCALL *fStamp)(void *, const char *, u32);
typedef void(THISCALL *fMark)(void *, u32, u32, const char *);
static void prof(u32 slot, u32 line, u32 name) {
  if (!(*(float *)(SYS + 0x9c7) != 0.0f && *(float *)(SYS + 0x9c3) != 0.0f))
    return;
  u8 *s = SYS;
  u64 t = ((fStamp)(*(void ***)s)[0x1c8 / 4])(s, (const char *)0x67a7f8, line);
  u8 *s2 = SYS;
  ((fMark)(*(void ***)s2)[slot / 4])(s2, (u32)t, (u32)(t >> 32), (const char *)name);
}

struct RefIter {
  u32 cur, a, b;
};

// "Alive and active" test used for formation members and leaders: the object is an actor (class 0x200074), its
// slot 0x438 (dead) answers no, and its geom's ([o slot 0x20]+8) flag bit 10 at +0x3c is clear.
static inline bool inactive(u8 *o) {
  u8 *g = vcall<u8 *>(o, 0x20);
  return (*(u32 *)(*(u8 **)(g + 8) + 0x3c) >> 10) & 1;
}

// Formation (CFormationControl table entry): +0 leader id, +4 member table (entries {member id, slot index, ...}),
// +8 event queue, +0xc slot-used flags[12].

// 0x5b5d60 CFormationControl::CheckRegroup(unsigned* formation), thiscall, ret 4, AL = formation still valid.
// Dead or inactive members are removed (their slot freed); if any were, the slots are packed again: each member
// keeps its slot when free, a member without one (-1) takes the first free slot, else it gets the last slot handed
// out (the original keeps that index across members, so two members can share one; a "no free slot" error is
// logged only when nothing was handed out yet). The member with the lowest slot (first one on ties) becomes the
// candidate leader. If the leader is an actor that is dead or inactive, the formation is dissolved: every member
// gets event +0x4e with the new leader id (0 when the old leader is of class 0x2003e8) and is removed; returns 0.
// Leaders that are not actors, or alive and active, keep the formation (returns 1). Profiling marker 0x6b2258.
static u8 THISCALL formCheckRegroup(u8 *self, u32 *f) {
  prof(0x178, 0x259, 0x6b2258);
  u8 changed = 0;
  u32 best = 0;
  s32 minSlot = 12;
  if (*(void **)(f + 1)) {
    RefIter it;
    vcall<void>(*(void **)(f + 1), 0x4c, &it);
    for (u32 *m = vcall<u32 *>(*(void **)(f + 1), 0x64, &it); m; m = vcall<u32 *>(*(void **)(f + 1), 0x64, &it)) {
      u8 *o = vcall<u8 *>(objTable(), 0x58, m[0]);
      if (!vcall<u8>(o, 0x1e0, 0x200074u))
        continue;
      if (!vcall<u8>(o, 0x438) && !inactive(o)) {
        s32 sl = (s32)m[1];
        if (sl < minSlot || best == 0) {
          best = m[0];
          minSlot = sl;
        }
        continue;
      }
      f[3 + m[1]] = 0;
      vcall<void>(*(void **)(f + 1), 0x44, &it);
      changed = 1;
    }
    if (changed) {
      s32 slot = -1;
      CRT_MEMSET(f + 3, 0, 0x30);
      if (*(void **)(f + 1)) {
        RefIter it2;
        vcall<void>(*(void **)(f + 1), 0x4c, &it2);
        for (s32 *m = vcall<s32 *>(*(void **)(f + 1), 0x64, &it2); m; m = vcall<s32 *>(*(void **)(f + 1), 0x64, &it2)) {
          s32 cur = m[1];
          if (cur < 0) {
            for (s32 k = 0; k < 12; ++k)
              if (f[3 + k] == 0) {
                slot = k;
                break;
              }
          } else if (f[3 + cur] == 0) {
            slot = cur;
          }
          if (slot != -1) {
            m[1] = slot;
            f[3 + slot] = 1;
          } else {
            void *lo = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6b21ec, 0x308u);
            ((logPrintf)(*(void ***)lo)[0x30 / 4])(lo, (const char *)0x6b2264);
          }
        }
      }
    }
  }
  u8 *ld = vcall<u8 *>(objTable(), 0x58, f[0]);
  if (!vcall<u8>(ld, 0x1e0, 0x200074u) || (!vcall<u8>(ld, 0x438) && !inactive(ld))) {
    prof(0x17c, 0x260, 0x6b2258);
    return 1;
  }
  u32 nl = vcall<u8>(ld, 0x1e0, 0x2003e8u) ? 0 : best;
  if (*(void **)(f + 1)) {
    RefIter it3;
    vcall<void>(*(void **)(f + 1), 0x4c, &it3);
    for (u32 *m = vcall<u32 *>(*(void **)(f + 1), 0x64, &it3); m; m = vcall<u32 *>(*(void **)(f + 1), 0x64, &it3)) {
      void *o = vcall<void *>(objTable(), 0x58, m[0]);
      vcall<void>(o, 0x128, (u32) * (u16 *)(self + 0x4e), &nl, 0u);
      vcall<void>(*(void **)(f + 1), 0x44, &it3);
    }
  }
  prof(0x17c, 0x260, 0x6b2258);
  return 0;
}
PCREG(5b5d60, formCheckRegroup);

extern "C" u8 THISCALL ext_4db9a0(void *geom, u32 cls);   // ZBaseGeom::IsDerivedFrom

// 0x5b6ab0 (unnamed; formation key of a group), thiscall, ret 4. Walks the group's children ([g+8], next by group
// slot 0x50); for each recruitable actor (class 0x2007f9) whose id (table slot 0x50) is a formation key in +0x48,
// returns that id; 0 when none.
static u32 THISCALL formKeyOfGroup(u8 *self, u8 *grp) {
  u32 c = *(u32 *)(grp + 8);
  while (c) {
    if (ext_4db9a0((void *)c, 0x2007f9)) {
      u32 id = vcall<u32>(objTable(), 0x50, c);
      if (vcall<u32>(*(void **)(self + 0x48), 0x2c, id))
        return id;
    }
    vcall<void>(grp, 0x50, &c);
  }
  return 0;
}
PCREG(5b6ab0, formKeyOfGroup);
