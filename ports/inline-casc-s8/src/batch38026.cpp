// batch38026.cpp - cascade s8 batch 38026: 0x4ac120 (register the matching objects of a node chain).
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(u8 *node, u32 flags);   // ret 4
extern "C" void THISCALL ext_4acf30(u8 *self, u32 a);      // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))

static u32 node_flags(u8 *n) {
  u8 *t = *(u8 **)(n + 0x54);
  return t ? *(u32 *)(*(u8 **)(t + 0xc) + 0x23) : 0x200002;
}
// Walks the node list `list` (+0x11a of this, slots 0x4c begin / 0x5c next with a cursor dword) for an object, looked up through the table (slot 0x58), that passes slot 0x1e0(test)
// and whose slot 0x2e8 result equals target; true when one is found.
static bool find_match(u8 *list, u32 test, u32 target) {
  u32 cur[2];
  SLOT(list, 0x4c, v1_t)(list, (u32)cur);
  u32 r = SLOT(list, 0x5c, v1_t)(list, (u32)cur);
  if (cur[0] == 0) return false;
  do {
    u8 *t = TABLE;
    u8 *o = (u8 *)SLOT(t, 0x58, v1_t)(t, r);
    if (o && (u8)SLOT(o, 0x1e0, v1_t)(o, test)) {
      if (SLOT(o, 0x2e8, v0_t)(o) == target) return true;
    }
    r = SLOT(list, 0x5c, v1_t)(list, (u32)cur);
  } while (cur[0] != 0);
  return false;
}

// 0x4ac120, thiscall(owner) ret 4. Walks the chain owner[0x50] -> +0x60 (stops when a node's flag word, [[n+0x54]+0xc]+0x23, lacks bit 0x100000): for nodes passing 0x4db9a0(0x1007d3)
// the target n[0x54] is registered through 0x4acf30 (with the table's slot 0x4c handle) unless the list at +0x11a already holds an object that matches it, and for nodes passing
// 0x1007d4 the same is done with the target from slot 0x340 of n[0x54] (match test 0x1007d8); nodes passing 0x100001 (and not 0x1007d3) go to slot 0x8c.
static void THISCALL fn4ac120(u8 *self, u8 *owner) {
  u8 *n = *(u8 **)(owner + 0x50);
  u8 *list = self + 0x11a;
  while (n) {
    if (!(node_flags(n) & 0x100000)) return;
    if ((u8)ext_4db9a0(n, 0x1007d3)) {
      u8 *target = *(u8 **)(n + 0x54);
      if (!find_match(list, 0x1007d1, (u32)target)) {
        u8 *t = TABLE;
        ext_4acf30(self, SLOT(t, 0x4c, v1_t)(t, (u32)target));
      }
      if ((u8)ext_4db9a0(n, 0x1007d4)) {
        u8 *t0 = *(u8 **)(n + 0x54);
        u32 u = SLOT(t0, 0x340, v1_t)(t0, 0);
        if (!find_match(list, 0x1007d8, u)) {
          u8 *t = TABLE;
          ext_4acf30(self, SLOT(t, 0x4c, v1_t)(t, u));
        }
      }
    } else if ((u8)ext_4db9a0(n, 0x100001)) {
      SLOT(self, 0x8c, v1_t)(self, *(u32 *)(n + 0x54));
    }
    n = *(u8 **)(n + 0x60);
  }
}
PCREG(4ac120, fn4ac120);
