// batch2449.cpp - decomp area 24, batch 2449 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43f8c0(void *self, const void *src);   // ZGROUP::CopyData(const ZGEOM*), ret 4
extern "C" void THISCALL ext_45d5b0(void *self, const void *src);   // ZGEOM::CopyData(const ZGEOM*), ret 4
extern "C" void THISCALL ext_4e4840(void *self, void *item);        // CQuadtree::Delete(CQuadtreeObj*), ret 4
extern "C" void THISCALL ext_44a1f0(void *self);                    // ZLNKWHANDS::ResetTargets()

// 0x4548b0 ZTemplate::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL templateCopyData(u8 *self, const void *src) {
  ext_43f8c0(self, src);
  vcall<void>((void *)src, 0x1e0, 0x1000e9u);  // the slot is on the source (esi = the argument in the exe)
}
PCREG(4548b0, templateCopyData);

// 0x4559a0 ZParticleController::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL particleControllerCopyData(u8 *self, const void *src) {
  ext_45d5b0(self, src);
  vcall<void>((void *)src, 0x1e0, 0x2000e4u);  // on the source, as in the exe
}
PCREG(4559a0, particleControllerCopyData);

// 0x443c30 ZTreeGroup::RemoveDynamicGeom(ZBaseGeom*), thiscall, ret 4.
static void THISCALL treeGroupRemoveDynamicGeom(u8 *self, u8 *geom) {
  u32 item = *(u32 *)(geom + 0x64);
  if (item) {
    void *q = vcall<void *>(self, 0x314);
    ext_4e4840(q, (void *)item);
  }
}
PCREG(443c30, treeGroupRemoveDynamicGeom);

// 0x454820 ZTemplate::ClassInit2(), thiscall, plain ret: ResetTargets, the global call, then the tail jump to slot 0x28.
static void THISCALL templateClassInit2(u8 *self) {
  ext_44a1f0(self);
  typedef void (*fn0)(void);
  fn0 fn = *(fn0 *)0x7003b0;
  if (!fn)
    __builtin_trap();
  fn();
  vcall<void>(self, 0x28);
}
PCREG(454820, templateClassInit2);
