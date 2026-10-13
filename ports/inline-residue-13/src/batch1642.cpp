// batch1642.cpp - ZActorIf::SetVisLightMultiplier(OpaqueCallParameters_t&) (0x508410, residue 13, 2026-10-12).
// Reads the first parameter (only to match the original's read), takes an id from the render manager (sys+0x9b, vtable
// +0x4c on the actor's object), registers "Msg_SetVisLightMultiplier" through vtable +0x114 with FIVE pushes at this site
// (the local, 0x12e, the file, 0, the name; the coordinator's six-argument note does not match this call site), then sends
// the low word of the result with the actor's +0x73a field through +0x58, and passes that result to the actor object's
// vtable +0x130. GUESS: the meanings of these calls are not traced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_5003d0[];  // opaque call parameter i (pointer to value; batch 45 / 1603)
typedef u32 *(THISCALL *ParamFn)(void *view, u32 i);

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

void THISCALL ZActorIf_SetVisLightMultiplier(u8 *self, u8 *params) {
  u8 *db = AT(u8 *, sys(), 0x9b);
  u32 local8 = vcall<u32>(db, 0x4c, AT(u32, self, 0x18));
  u32 *pv = ((ParamFn)(void *)ext_5003d0)(AT(void *, params, 4), 0);
  (void)*(float *)pv;
  u32 r = vcall<u32>(db, 0x114, (u32)0x6904b8, (u32)0, (u32)0x69cff0, (u32)0x12e, (u32)&local8);
  u16 w = (u16)r;
  u32 v = vcall<u32>(db, 0x58, AT(u32, AT(u8 *, self, 0x18), 0x73a), (u32)w);
  vcall<void>(AT(u8 *, self, 0x18), 0x130, v);
}
PCREG(508410, ZActorIf_SetVisLightMultiplier);
