// batch1001.cpp - fresh-10 batch 1: small slice-10 wrappers. Names from the GC name map; GUESS where it has none.
#include "ff.h"

// 0x650c20 ZRender::RemoveView(ZViewBase*): forwards to slot 0x30 of the object at this+0xbd.
static u32 THISCALL RemoveView(u8 *self, u32 view) {
  return vcall<u32>(*(void **)(self + 0xbd), 0x30, view);
}
PCREG(650c20, RemoveView);

// 0x601c60 CHostInterface::notifyRecycleProcess(Process_t*): forwards to slot 0xa8 of the object at [0x70039c+8].
static u32 THISCALL notifyRecycleProcess(u8 *, u32 proc) {
  return vcall<u32>(G(void *, 0x7003a4), 0xa8, proc);
}
PCREG(601c60, notifyRecycleProcess);

// 0x655360 GUESS: ShowWindow(hwnd at this+0x133, cmd) through the IAT slot 0x676198.
typedef u32(STDCALL *showwin_t)(u32, u32);
static u32 THISCALL ShowWnd(u8 *self, u32 cmd) {
  return G(showwin_t, 0x676198)(*(u32 *)(self + 0x133), cmd);
}
PCREG(655360, ShowWnd);

// 0x54e160 GUESS destructor body: vtable 0x6a3ea8, free the buffer at this+0x53 (operator delete 0x634273, cdecl).
extern "C" void ext_634273(void *p, u32 n);
static void THISCALL DtorBody(u8 *self) {
  void *p = *(void **)(self + 0x53);
  *(u32 *)self = 0x6a3ea8;
  if (p) ext_634273(p, 1);
}
PCREG(54e160, DtorBody);

// 0x63e660 ZDrawBase::FreeSprites(void*, int): count--, used -= size rounded up to 16, then slot 0x24(p, rounded).
static u32 THISCALL FreeSprites(u8 *self, u32 p, u32 size) {
  u32 r = (size + 0xf) & 0xfffffff0;
  *(u32 *)(self + 8) -= 1;
  *(u32 *)(self + 0xc) -= r;
  return vcall<u32>(self, 0x24, p, r);
}
PCREG(63e660, FreeSprites);

// 0x6564e0 ZPrimControlBase::GetLightDirectionalData(out, in): slot 0x148(out, in), then out+0x18 = in+0x18.
static u32 THISCALL GetLightDirectionalData(u8 *self, u8 *out, u8 *in) {
  vcall<void>(self, 0x148, out, in);
  u32 v = *(u32 *)(in + 0x18);
  *(u32 *)(out + 0x18) = v;
  return v;
}
PCREG(6564e0, GetLightDirectionalData);

// 0x656620 ZPrimControlBase::GetLightSpotSquareData(out, in): slot 0x150(out, in), then out+0x38 = in+0x38.
static u32 THISCALL GetLightSpotSquareData(u8 *self, u8 *out, u8 *in) {
  vcall<void>(self, 0x150, out, in);
  u32 v = *(u32 *)(in + 0x38);
  *(u32 *)(out + 0x38) = v;
  return v;
}
PCREG(656620, GetLightSpotSquareData);

// 0x656b20 GUESS: slot 0x94(slot 0xc(a), b).
static u32 THISCALL Fwd656b20(u8 *self, u32 a, u32 b) {
  u32 x = vcall<u32>(self, 0xc, a);
  return vcall<u32>(self, 0x94, x, b);
}
PCREG(656b20, Fwd656b20);
