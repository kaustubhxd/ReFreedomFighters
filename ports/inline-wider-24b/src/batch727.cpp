// batch727.cpp - soldier AI, batch 727 (2026-10-12): ZFFActorIf::CheckPosition (0x558810). The point (items 0..2 of the
// in-accessor) goes to the actor's pathfinder (slot 0x5d0 on the actor, slot 0x220 on the pathfinder, which returns a bool).
// Without a pathfinder the native logs "Warning: Missing pathfinder. FFActor.CheckPosition() returned true" (line 0x116) and
// the result is 0 (the message says true, the code stores 0; GUESS: the message is stale). The result goes to output 0 through
// the typed setter 0x5002f0.
#include "ff.h"

struct Item { u32 v; u8 t; u8 pad[3]; };   // accessor item: value at +0, type byte at +4

extern "C" Item *THISCALL ext_5003d0(void *acc, u32 idx);                          // accessor
extern "C" void THISCALL ext_5002f0(Item *it, u32 value);                          // typed setter (value on the stack)

static void printf_0(void *log, const char *fmt) {
  typedef void(__attribute__((cdecl)) * pf_t)(void *, const char *);
  (*(pf_t *)(*(u8 **)log + 0x2c))(log, fmt);
}

// 0x558810 ZFFActorIf::CheckPosition(OpaqueCallParameters_t&) [low].
static void THISCALL actorif_CheckPosition(u8 *self, u8 *pr) {
  void *inAcc = *(void **)(pr + 4);
  Item *i2 = ext_5003d0(inAcc, 2);
  Item *i1 = ext_5003d0(inAcc, 1);
  Item *i0 = ext_5003d0(inAcc, 0);
  float v[3] = {bitsf(i0->v), bitsf(i1->v), bitsf(i2->v)};

  u8 *actor = *(u8 **)(self + 0x1c);
  void *pf = vcall<void *>(actor, 0x5d0);
  u32 r = 0;
  if (pf) {
    r = (u8)vcall<u8>(pf, 0x220, v);
  } else {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6a5eb0, 0x116);
    printf_0(log, (const char *)0x6a5ee8);   // "Warning: Missing pathfinder. FFActor.CheckPosition() returned true"
  }

  Item *o0 = ext_5003d0(*(void **)(pr + 8), 0);
  ext_5002f0(o0, r);
}
PCREG(558810, actorif_CheckPosition);
