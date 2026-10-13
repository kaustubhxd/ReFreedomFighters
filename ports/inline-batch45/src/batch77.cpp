// batch77.cpp - player mechanics, main thread batch 77 (2026-10-11): small ZFFHERO state queries and the focus
// forwarders to the hero's camera helper (+0x85a). Names from the GC map (high).
#include "ff.h"

// 0x592c20 ZFFHERO::IsRunning() const, thiscall, eax. Running = flag 2 set and flag 0x10000000 clear in +0x417.
static u32 THISCALL heroIsRunning(u8 *self) {
  return (*(u32 *)(self + 0x417) & 0x10000002u) == 2u;
}
PCREG(592c20, heroIsRunning);

// 0x592c40 ZFFHERO::IsSneaking() const, thiscall, al. True when flag 0x400 is set or flag 2 is clear.
static u8 THISCALL heroIsSneaking(u8 *self) {
  u32 f = *(u32 *)(self + 0x417);
  if (f & 0x400u) return 1;
  if (f & 2u) return 0;
  return 1;
}
PCREG(592c40, heroIsSneaking);

// 0x594f70 ZFFHERO::SetMoveSpeeds(const float*), thiscall, ret 4. Copies three speeds to +0x65d, +0x661, +0x665.
static void THISCALL heroSetMoveSpeeds(u8 *self, const u32 *v) {
  *(u32 *)(self + 0x65d) = v[0];
  *(u32 *)(self + 0x661) = v[1];
  *(u32 *)(self + 0x665) = v[2];
}
PCREG(594f70, heroSetMoveSpeeds);

// 0x591d10 ZFFHERO::GetFocusMatPos(mat, pos), 0x591d60 GetGlobalFocalPoint(pos), 0x5922a0 GetRootFocusMatPos(mat, pos):
// tail jumps to the camera helper's (+0x85a) slots 0x8c, 0x88 and 0x90 with the same arguments (thiscall, the callee
// pops). The port calls and returns the helper's eax.
static u32 THISCALL heroGetFocusMatPos(u8 *self, float *m, float *p) {
  return vcall<u32>(*(void **)(self + 0x85a), 0x8c, m, p);
}
PCREG(591d10, heroGetFocusMatPos);
static u32 THISCALL heroGetGlobalFocalPoint(u8 *self, float *p) {
  return vcall<u32>(*(void **)(self + 0x85a), 0x88, p);
}
PCREG(591d60, heroGetGlobalFocalPoint);
static u32 THISCALL heroGetRootFocusMatPos(u8 *self, float *m, float *p) {
  return vcall<u32>(*(void **)(self + 0x85a), 0x90, m, p);
}
PCREG(5922a0, heroGetRootFocusMatPos);
