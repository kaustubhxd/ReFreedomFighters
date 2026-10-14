// batch926.cpp - 0x569590 [thiscall (ECX = this), one stack arg (id: a pointer to a string or a small code), ret 4, returns al].
// Body re-read in full (2026-10-12; the first draft was wrong and is replaced).
//  1. 0x562c20(this, id) (thiscall; stood in). If it is nonzero, return 1.
//  2. If id == 1: mgr = g+0x9b; mgr slot +0xa4 (no args); mgr slot +0xa0 with 0x6a7598 (one arg).
//  3. 0x563500(this) (no args; stood in). 0x561f10(this, 0) (one arg; stood in).
//  4. local = (id == 0x8ae) ? 0x15 : id.
//  5. x = mgr slot +0x134 (no args); x slot +0x68 with (0x6a75b0, 0, 0) (callee pops 12).
//  6. g slot +0x5c with (0x6a7584, &id) (ECX = g; callee pops 8): if it returns nonzero, the value of id (now written through &id) is
//     atoi-ed through the import slot 0x6762d8 (cdecl; stood in); the result is ebx, otherwise ebx = 0.
//  7. t = 10 * ebx. If local < t (unsigned): return 0.
//  8. If id == 0x8ae: x2 = mgr slot +0x134; x2 slot +0x68 with (0x6a757c, 1, 0).
//  9. 0x563500(this); 0x562af0(this, local) (one arg; stood in). Return 0.
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_562c20(void *self, u32 id);
extern "C" void THISCALL ext_563500(void *self);
extern "C" void THISCALL ext_561f10(void *self, u32 v);
extern "C" void THISCALL ext_562af0(void *self, u32 v);

static u8 *mgr569590() { return (u8 *)FP(G(u8 *, 0x70039c), 0x9b); }

// 0x569590 (no name in the map).
static bool THISCALL Run569590(u8 *self, u32 id) {
  if (ext_562c20(self, id)) return true;
  if (id == 1u) {
    vcall<void *>(mgr569590(), 0xa4);
    vcall<void>(mgr569590(), 0xa0, (void *)0x6a7598u);
  }
  ext_563500(self);
  ext_561f10(self, 0u);
  u32 local = (id == 0x8aeu) ? 0x15u : id;   // mov eax,0x15; cmovne eax,esi
  u8 *x = (u8 *)vcall<void *>(mgr569590(), 0x134);
  vcall<void>(x, 0x68, (void *)0x6a75b0u, 0u, 0u);
  u32 slot = id;
  bool hit = vcall<bool>(G(u8 *, 0x70039c), 0x5c, (void *)0x6a7584u, (void *)&slot);
  u32 ebx = 0;
  if (hit) ebx = ((s32(*)(const char *))G(u32, 0x6762d8))((const char *)slot);
  u32 t = ebx * 10u;
  if (local < t) return false;
  if (id == 0x8aeu) {
    u8 *x2 = (u8 *)vcall<void *>(mgr569590(), 0x134);
    vcall<void>(x2, 0x68, (void *)0x6a757cu, 1u, 0u);
  }
  ext_563500(self);
  ext_562af0(self, local);   // ebx was reloaded from the local at 0x56965a
  return false;
}
PCREG(569590, Run569590);
