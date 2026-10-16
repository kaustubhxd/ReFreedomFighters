// batch1626.cpp - CEVENTCONTROLLER::AddActor / RemoveActor (soundtimers thread, 2026-10-11).
//
// Correction to the earlier blocker note: AddActor allocates its node through the event list object itself (list
// object at controller+4, vtable +4), not through ZDllSound's 0x53a9e0. 0x53a9e0 is only AddEvent's allocator.
//
// Controller fields: +4 event list object L (vtable: +0x4c first, +0x64 next element (returns it, 0 at the end),
// +0x44 remove, +4 allocate a node; the node pointer is node+4). Lists are linked through node +0xc (next) and +0x10
// (prev); controller heads: +0xe (first), +0x12 and +0x16 (cursors that RemoveActor moves off a removed node).
// Node: +0 kind (1 when the actor IsKindOf class 0x2007d0, else 2), +4 actor, +8 a word copied from sys+0x40 (GUESS:
// the original copies the value at sys+0x40 into the node; sys+0x40 is also the tick counter read by CanIPlay, an
// unresolved overlap, see docs/20-soundtimers.md).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

void THISCALL CEventController_AddActor(u8 *self, u8 *actor) {
  u8 *L = AT(u8 *, self, 4);
  if (L) {
    u32 tmp = 0;
    vcall<void>(L, 0x4c, &tmp);
    u8 *cur = vcall<u8 *>(L, 0x64, &tmp);
    while (cur) {
      if (AT(u8 *, cur, 4) == actor) return;  // already registered
      cur = vcall<u8 *>(L, 0x64, &tmp);
    }
  }
  u8 *node = vcall<u8 *>(AT(u8 *, self, 4), 0x4, (u32)0) - 4;
  u8 kind = vcall<u8>(actor, 0x1e0, (u32)0x2007d0) ? 1 : 2;
  AT(u32, node, 0) = kind;
  AT(u8 *, node, 4) = actor;
  u32 *word = (u32 *)(node + 8);
  u32 *sysword = (u32 *)(sys() + 0x40);
  if (word != sysword) *word = *sysword;
  AT(u32, node, 0x10) = 0;
  AT(u32, node, 0xc) = 0;
  u8 *head = AT(u8 *, self, 0xe);
  if (!head) {
    AT(u8 *, self, 0xe) = node;
    return;
  }
  u8 *last = head;
  while (AT(u8 *, last, 0xc)) last = AT(u8 *, last, 0xc);
  AT(u8 *, last, 0xc) = node;
  AT(u8 *, node, 0x10) = last;
}
PCREG(53a910, CEventController_AddActor);

void THISCALL CEventController_RemoveActor(u8 *self, u8 *actor) {
  u8 *L = AT(u8 *, self, 4);
  if (!L) return;
  u32 tmp = 0;
  vcall<void>(L, 0x4c, &tmp);
  u8 *cur = vcall<u8 *>(L, 0x64, &tmp);
  while (cur && AT(u8 *, cur, 4) != actor) cur = vcall<u8 *>(L, 0x64, &tmp);
  if (!cur) return;
  u8 *nx = AT(u8 *, cur, 0xc);
  if (cur == AT(u8 *, self, 0xe)) {
    AT(u8 *, self, 0xe) = nx;
    if (nx) AT(u8 *, nx, 0x10) = 0;
  } else {
    u8 *pv = AT(u8 *, cur, 0x10);
    if (!nx) {
      if (pv) AT(u8 *, pv, 0xc) = 0;
    } else {
      AT(u8 *, pv, 0xc) = nx;
      AT(u8 *, nx, 0x10) = pv;
    }
  }
  if (AT(u8 *, self, 0x12) == cur) {
    AT(u8 *, self, 0x12) = nx;
    if (!nx) AT(u8 *, self, 0x12) = AT(u8 *, self, 0xe);
  }
  if (AT(u8 *, self, 0x16) == cur) {
    AT(u8 *, self, 0x16) = nx;
    if (!nx) AT(u8 *, self, 0x16) = AT(u8 *, self, 0xe);
    if (AT(u8 *, self, 0x16) == cur) AT(u8 *, self, 0x16) = 0;
  }
  if (AT(u8 *, self, 0x12) == cur) AT(u8 *, self, 0x12) = 0;
  if (AT(u8 *, self, 0xe) == cur) AT(u8 *, self, 0xe) = 0;
  vcall<void>(AT(u8 *, self, 4), 0x44, &tmp);
}
PCREG(53b1b0, CEventController_RemoveActor);
