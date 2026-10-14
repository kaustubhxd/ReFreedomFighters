// batch709.cpp - soldier AI, batch 709 (2026-10-11): the goal stack and the target-manager switch.
// Goals are script states: a PState {u32 priority, u32 goal (a PPO state address), u32 data, u32 extra} in a
// PStateQueue (count at actor +0x7ce, up to 16 records at +0x7d2, kept sorted by priority, highest last; GC names
// PState/PStateQueue from ZFFActor::AddGoal 80072b38). The active goal is at +0x8d6, its data at +0x8da.
// GetStateNameFromAddr / GetStateAddrFromName convert between goal ids and the script's state names.
#include "ff.h"

struct PState { u32 prio, goal, data, extra; };

// 0x5a2460: name map says ZFFActor::AddGoal [high] (from the "Goal stack full" string), but the body is the queue
// insert that AddGoal inlines on GC: thiscall on the PStateQueue, one PState* argument. Full queue: logs
// "WARNING: Goal stack full" (statequeue.h line 0x5d), false. A record with the same goal and data already queued: false.
// Otherwise inserted before the first record whose priority is higher (unsigned), and the result says whether the new
// record is now the top.
static bool THISCALL psq_Insert(u32 *q, const PState *g) {
  u32 n = q[0];
  if (n == 16) {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6adef8, 0x5d);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6adf50);
    return false;
  }
  PState *items = (PState *)(q + 1);
  u32 pos = 0;
  for (; pos < n; pos++) {
    PState e = items[pos];
    if (g->goal == e.goal && g->data == e.data)
      return false;
    if (g->prio < items[pos].prio)
      break;
  }
  if (pos < n) {
    for (u32 k = n - 1; k != pos; k--)
      items[k + 1] = items[k];
    items[pos + 1] = items[pos];
  }
  items[pos] = *g;
  q[0]++;
  PState top = items[q[0] - 1];
  return g->goal == top.goal && g->data == top.data;
}
PCREG(5a2460, psq_Insert);

// 0x5a2cb0 ZFFActor::SetGoalData(unsigned int goal, unsigned int data) [medium]: as compiled it only rewrites a data
// field with the value it already has (active goal, or the first queued record with that goal and data) -- no effect.
static void THISCALL ffactor_SetGoalData(u8 *self, u32 goal, u32 data) {
  u32 act = *(u32 *)(self + 0x8d6);
  if (act != 0 && act == goal && *(u32 *)(self + 0x8da) == data) {
    *(u32 *)(self + 0x8da) = data;
    return;
  }
  u32 *q = (u32 *)(self + 0x7ce);
  PState *it = (PState *)(self + 0x7d2);
  PState *end = (PState *)((u8 *)q + q[0] * 16 + 4);
  for (; it != end; it++) {
    if (it->goal == goal && it->data == data) {
      it->data = data;
      return;
    }
  }
}
PCREG(5a2cb0, ffactor_SetGoalData);

struct MYSTR_buf { u8 b[0x80]; };
extern "C" const char *THISCALL ext_4cc1d0(void *);
extern "C" void THISCALL ext_4cbec0(void *);
extern "C" void *__attribute__((cdecl)) ext_41e290(u32);          // operator new
extern "C" void __attribute__((cdecl)) ext_634273(void *, u32);   // sized operator delete

static void ff_assert() {
  void (*h)() = *(void (**)())0x7003b0;
  if (h)
    h();
  else
    __builtin_debugtrap();
}

// 0x5a30e0 ZFFActor::UseTargetManager(bool) [high]: the target manager (+0x92a) is an empty 1-byte object; enabling
// allocates it, disabling frees it; doing either twice logs "Tried to re-enable ot re-disable TargetManager on '%s'".
static void THISCALL ffactor_UseTargetManager(u8 *self, u32 on) {
  if ((u8)on) {
    if (*(void **)(self + 0x92a) == 0) {
      *(void **)(self + 0x92a) = ext_41e290(1);
      return;
    }
  } else {
    void *tm = *(void **)(self + 0x92a);
    if (tm) {
      ext_634273(tm, 1);
      *(void **)(self + 0x92a) = 0;
      return;
    }
  }
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ae6a0, 0xc7e);
  MYSTR_buf n;
  void *m = vcall<void *>(self, 0x1d8, &n, 1);
  const char *s = ext_4cc1d0(m);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aef14, s);
  ext_4cbec0(&n);
}
PCREG(5a30e0, ffactor_UseTargetManager);

// 0x5a20d0 ZFFActor::PopGoal(unsigned int goal, unsigned int) [high] (second argument unused). Warns and asserts when
// another goal is active or the stack is empty (then carries on); pops the top if it is that goal, else removes the
// first record with that goal, else warns "WARNING: %s trying to pop goal (%s) not in stack". Names come from slot
// 0x70c (GetStateNameFromAddr).
static void THISCALL ffactor_PopGoal(u8 *self, u32 goal, u32) {
  typedef void(__attribute__((cdecl)) * printf3_t)(void *, const char *, const char *, const char *);
  typedef void(__attribute__((cdecl)) * printf4_t)(void *, const char *, const char *, const char *, const char *);
  u32 act = *(u32 *)(self + 0x8d6);
  if (act != 0 && act != goal) {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ae6a0, 0xb9b);
    MYSTR_buf n;
    void *m = vcall<void *>(self, 0x1d8, &n, 1);
    const char *sa = vcall<const char *>(self, 0x70c, *(u32 *)(self + 0x8d6));
    const char *sg = vcall<const char *>(self, 0x70c, goal);
    const char *me = ext_4cc1d0(m);
    (*(printf4_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aed80, me, sg, sa);
    ext_4cbec0(&n);
    ff_assert();
  }
  u32 *q = (u32 *)(self + 0x7ce);
  if (q[0] == 0) {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ae6a0, 0xba0);
    MYSTR_buf n;
    void *m = vcall<void *>(self, 0x1d8, &n, 1);
    const char *sg = vcall<const char *>(self, 0x70c, goal);
    const char *me = ext_4cc1d0(m);
    (*(printf3_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aedcc, me, sg);
    ext_4cbec0(&n);
    ff_assert();
  }
  PState *items = (PState *)(q + 1);
  if (goal == *(u32 *)((u8 *)q + q[0] * 16 - 8)) {
    if (q[0] != 0)
      q[0]--;
    return;
  }
  for (PState *it = items; it != (PState *)((u8 *)q + q[0] * 16 + 4); it++) {
    if (it->goal == goal) {
      u32 k = (u32)(it - items);
      for (; k < q[0] - 1; k++)
        items[k] = items[k + 1];
      q[0]--;
      return;
    }
  }
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ae6a0, 0xbb2);
  MYSTR_buf n;
  void *m = vcall<void *>(self, 0x1d8, &n, 1);
  const char *sg = vcall<const char *>(self, 0x70c, goal);
  const char *me = ext_4cc1d0(m);
  (*(printf3_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6aee0c, me, sg);
  ext_4cbec0(&n);
}
PCREG(5a20d0, ffactor_PopGoal);

// 0x59ffd0 ZFFActor::GetStateAddrFromName(const char*) [high]: through +0x10 -> +0x1c -> +4 -> +4 -> +0x96 (the
// script's VM image) to VMImageInfo_t::getStateAddrFromName (0x5ffe80); 0 when any link is null.
extern "C" u32 THISCALL ext_5ffe80(void *, const char *);
static u32 THISCALL ffactor_GetStateAddrFromName(u8 *self, const char *name) {
  u8 *p = *(u8 **)(self + 0x10);
  if (!p || !(p = *(u8 **)(p + 0x1c)) || !(p = *(u8 **)(p + 4)) || !(p = *(u8 **)(p + 4)))
    return 0;
  return ext_5ffe80(*(void **)(p + 0x96), name);
}
PCREG(59ffd0, ffactor_GetStateAddrFromName);

// 0x5a0010 ZFFActor::GetStateNameFromAddr(unsigned int) [high]: same chain, slot 0 of the image; "<N/A>" otherwise.
static const char *THISCALL ffactor_GetStateNameFromAddr(u8 *self, u32 addr) {
  u8 *p = *(u8 **)(self + 0x10);
  if (!p || !(p = *(u8 **)(p + 0x1c)) || !(p = *(u8 **)(p + 4)) || !(p = *(u8 **)(p + 4)))
    return (const char *)0x6aeb20;
  return vcall<const char *>(*(void **)(p + 0x96), 0, addr);
}
PCREG(5a0010, ffactor_GetStateNameFromAddr);
