// batch1002.cpp - unclaimed-07 batch 2 (docs/20-unclaimed-07.md): ZActionControlMap::Init, CActionController::End and
// ZInputActions::GetActionMapStatus. Names are from the GC name map (naming only, never committed); bodies from the PC bytes.
#include "ff.h"

// 0x5b3dd0, ZActionControlMap::Init() (high): g_sys (0x70039c) slot +0xbc gives an object; its slot +0xb8 gives the byte
// stored at this+0x55. Then g_sys slot +0xbc again, the object's slot +0xc0 gives the byte stored at this+0x56.
static void THISCALL actionMapInit(u8 *self) {
  void *sys = G(void *, 0x70039c);
  self[0x55] = (u8)vcall<u32>(vcall<void *>(sys, 0xbc), 0xb8);
  self[0x56] = (u8)vcall<u32>(vcall<void *>(sys, 0xbc), 0xc0);
}
PCREG(5b3dd0, actionMapInit);

// 0x4a0780, CActionController::End() (high): does not use this (ECX is overwritten). Reads the object pointer at
// g_sys+0x9b, calls its slot +0x138 for the object esi, then calls esi's slot +0xa0 with (0x68f724, 0) and then with
// (0x68f75c, 0). Plain ret (no arguments).
static void THISCALL actionControllerEnd(u8 *self) {
  (void)self;
  u8 *sys = G(u8 *, 0x70039c);
  void *ctl = *(void **)(sys + 0x9b);
  void *esi = vcall<void *>(ctl, 0x138);
  vcall<void>(esi, 0xa0, 0x68f724u, 0u);
  vcall<void>(esi, 0xa0, 0x68f75cu, 0u);
}
PCREG(4a0780, actionControllerEnd);

// 0x438260, ZInputActions::GetActionMapStatus(const char*) (medium): p = vtable slot +0x58 on the name. When the first
// dword of p is 3, the result is vtable slot +0x30 of the object at p-4 (no arguments). Otherwise, when the first dword
// is 0, the dword at p+0x42 is set to 0. The result is p in the second case.
static u32 THISCALL inputGetActionMapStatus(u8 *self, u32 a1) {
  u32 p = vcall<u32>(self, 0x58, a1);
  u32 first = *(u32 *)p;
  if (first == 3)
    return vcall<u32>((void *)(p - 4), 0x30);
  if (first == 0)
    *(u32 *)(p + 0x42) = first;
  return p;
}
PCREG(438260, inputGetActionMapStatus);
