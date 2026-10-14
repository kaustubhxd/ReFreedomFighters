// batch929.cpp - 0x4388a0 ZInputAction::FreeActionDependencies() [thiscall (ECX = this), no args, no pop]. Body read in full (2026-10-12).
// obj = this+0x3e. If obj is null, return. Else obj slot +0x4c(&local); p = obj slot +0x64(&local); while p: v = the dword at p; if v, 0x634273
// (cdecl: v, 1; stood in); p = obj slot +0x64(&local). Then if this+0x3e is set, its slot 0 (scalar deleting destructor) with 1; and this+0x3e = 0.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void ext_634273(void *obj, u32 n);   // stood in (cdecl)

// 0x4388a0 (name in the map: ZInputAction::FreeActionDependencies()).
static void THISCALL Free4388a0(u8 *self) {
  u8 *obj = (u8 *)FP(self, 0x3e);
  if (!obj) return;
  u32 local = 0;
  vcall<void>(obj, 0x4c, (void *)&local);
  u32 p = vcall<u32>(obj, 0x64, (void *)&local);
  while (p != 0) {
    u32 v = *(u32 *)p;
    if (v != 0) ext_634273((void *)v, 1u);
    p = vcall<u32>(obj, 0x64, (void *)&local);
  }
  obj = (u8 *)FP(self, 0x3e);
  if (obj) vcall<void>(obj, 0u, 1u);
  U32(self, 0x3e) = 0;
}
PCREG(4388a0, Free4388a0);
