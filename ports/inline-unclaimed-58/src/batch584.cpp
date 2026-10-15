// batch584.cpp - gameplay-CORE functions from decomp-pilot/core-todo/residue-17.txt (area 58, slice floor(addr/16) mod 20 == 17).
#include "ff.h"

typedef u32(THISCALL *VtArgU32)(u8 *, u32);     // one stack word; the callee pops 4
typedef void(THISCALL *VtArgTwo)(u8 *, u32, u32);

// 0x49ef50, CMsgForward::Save(ZSaveGame* save) (GUESS name from the core list): [this+4] &= ~0x40; save->vtable[0x3c](save,
// [this+0x48]); r = save->vtable[0x40](save, zero-extended word [this+0x4c]); return (r & ~0xff) | 1 (the asm sets al = 1).
static u32 THISCALL saveFields_49ef50(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  VtArgU32 f3c = (VtArgU32)(*(u32 *)(*(u32 *)save + 0x3c));
  f3c(save, *(u32 *)(self + 0x48));
  VtArgU32 f40 = (VtArgU32)(*(u32 *)(*(u32 *)save + 0x40));
  u32 r = f40(save, (u32)*(u16 *)(self + 0x4c));
  return (r & ~0xffu) | 1u;
}
PCREG(49ef50, saveFields_49ef50);

// 0x5c3d90, COpenWindow::Load(ZLoadGame* load): [this+4] &= ~0x40; load->vtable[0x68](load, this+0x48); r =
// load->vtable[0x40](load, this+0x49); return (r & ~0xff) | 1. Name GUESS from the core list.
static u32 THISCALL loadFields_5c3d90(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  VtArgU32 f68 = (VtArgU32)(*(u32 *)(*(u32 *)load + 0x68));
  f68(load, (u32)(self + 0x48));
  VtArgU32 f40 = (VtArgU32)(*(u32 *)(*(u32 *)load + 0x40));
  u32 r = f40(load, (u32)(self + 0x49));
  return (r & ~0xffu) | 1u;
}
PCREG(5c3d90, loadFields_5c3d90);

// 0x437ad0, thiscall(arr, arg) ret 8: for i in 0..3: e = arr[i]; if e == -1 stop; this->vtable[4](this, e, arg).
// Name ZInputAction::AddNodes (from the core list).
static void THISCALL addNodes_437ad0(u8 *self, u32 *arr, u32 arg) {
  for (int i = 0; i < 4; ++i) {
    u32 e = arr[i];
    if (e == 0xffffffffu) break;
    VtArgTwo f4 = (VtArgTwo)(*(u32 *)(*(u32 *)self + 4));
    f4(self, e, arg);
  }
}
PCREG(437ad0, addNodes_437ad0);
