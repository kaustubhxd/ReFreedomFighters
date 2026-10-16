// batch8827.cpp - wire-hit-parts run 5 (2026-10-16): ZFFActorActionCloseCombat::CallBack 0x5eaf80 as plain C (the strict lift in
// inline-casc-h1 batch31103 is an x86 asm thunk, which wasm cannot build).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

typedef void(THISCALL *vVU)(void *self, u32 a);
typedef u16(THISCALL *vReg)(void *self, const char *name, u32 z, const char *file, u32 line);
typedef void(THISCALL *vCmd)(void *self, u32 msg, u32 data, u32 z);

// 0x5eaf80 ZFFActorActionCloseCombat::CallBack() (GameCube reference), the end-of-clip callback: attacker (+8) slot 0x704(0); the message id of
// "CloseCombatFinished" from the render manager ([0x70039c] + 0x9b) slot 0x114 (RegisterZMsg(name, 0, ZFFActorActions.cpp, 0x82)); the attacker
// gets it through slot 0x128(id, 0, 0) (the slot is read from the vtable the attacker had before the 0x114 call). Returns false.
static u8 THISCALL ccCallBack(u8 *self) {
  void *at = *(void **)(self + 8);
  ((vVU)VT(at, 0x704))(at, 0);
  void **vt = *(void ***)*(void **)(self + 8);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u16 id = ((vReg)VT(rm, 0x114))(rm, (const char *)0x6a4d58, 0, (const char *)0x6b80b4, 0x82);
  ((vCmd)vt[0x128 / 4])(*(void **)(self + 8), id, 0, 0);
  return 0;
}
PCREG(5eaf80, ccCallBack);
