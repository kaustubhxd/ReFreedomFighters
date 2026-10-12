// batch606.cpp - unclaimed-06 claim 6 (docs/20-unclaimed-06.md): ZItemTemplateAmmo::Save(ZSaveGame*). Thiscall, one
// argument, ret 4. Names are from the GC name map (naming only). The base save 0x441790 is original code (it calls the
// ZSaveGame stand-in's slots, which the harness stubs with serial_stubs.save_obj).
#include "ff.h"

extern "C" u8 THISCALL ext_441790(u8 *self, void *sg);   // original base-class save, ecx = this, one argument

// 0x4706d0, ZItemTemplateAmmo::Save(ZSaveGame*) (high): base save, then four ZSaveGame calls through its vtable:
// slot 0x6c with this+0x70, slot 0x3c with this+0xa0, slot 0x10 with (this+0x98, this+0x9c << 2). Returns true.
static u8 THISCALL itemTemplateAmmoSave(u8 *self, void *sg) {
  ext_441790(self, sg);
  void **vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x6c)))(sg, *(u32 *)(self + 0x70));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x3c)))(sg, *(u32 *)(self + 0xa0));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32, u32))(*(void **)((u8 *)vt + 0x10)))(sg, *(u32 *)(self + 0x98),
                                                                        *(u32 *)(self + 0x9c) << 2);
  return 1;
}
PCREG(4706d0, itemTemplateAmmoSave);
