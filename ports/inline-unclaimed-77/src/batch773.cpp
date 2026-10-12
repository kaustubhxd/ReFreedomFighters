// batch773.cpp - unclaimed-77 claim 3 (docs/20-unclaimed-77.md): three pure leaves, thiscall, no callees. Names from the GC
// name map (medium).
#include "ff.h"

// 0x449540, ZLIGHT::LightAttributeChanged() const (medium): eax = dword at this+0x18 shifted right by 3; then `and al, 1`
// replaces only the low byte with (eax & 1). The upper bits of eax are the shifted value's own bits (not the caller's), so
// the port reproduces them exactly.
static u32 THISCALL lightAttributeChanged(u8 *self) {
  u32 t = *(u32 *)(self + 0x18) >> 3;
  return (t & 0xffffff00u) | (t & 1u);
}
PCREG(449540, lightAttributeChanged);

// 0x4cdd40, STATICREFTAB::Count() const (medium): returns the dword at this+0x14.
static u32 THISCALL staticRefTabCount(u8 *self) {
  return *(u32 *)(self + 0x14);
}
PCREG(4cdd40, staticRefTabCount);

// 0x64fc40, ZRenderBaseDll::GetRagdollContainer() (medium): returns the dword at this+0x38.
static u32 THISCALL renderBaseDllGetRagdollContainer(u8 *self) {
  return *(u32 *)(self + 0x38);
}
PCREG(64fc40, renderBaseDllGetRagdollContainer);
