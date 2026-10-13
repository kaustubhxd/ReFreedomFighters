// batch1001.cpp - area 81 (residue 0), batch 1001: ZPlayer::ClassInit(), 0x4824c0, thiscall, no args, plain ret (cookie check not reproduced).
// vslot 0x41c(0); vslot 0x628(); helper 0x472ff0(this) (GUESS, stood in); [this+0x6c]+4 byte = 1; [this+0x424] = 0; vslot 0x110(0x10, 0x3e8);
// vslot 0x80(&L34, &L10); [this+0x412] = 1; vslot 0x370(&L34, &L10); the call on [this+8] to 0x4690b0 is a bare ret and is left out;
// R = render vslot 0x25c(0x68beb8, 0), or when that is zero R vslot 0x294(0x68beb8, 0x67f610, 0, 1); then the result's vslot 0x218(this).
#include "ff.h"

extern "C" void THISCALL ext_472ff0(void *self);   // GUESS (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4824c0 ZPlayer::ClassInit().
static void THISCALL playerClassInit(u8 *t) {
  vcall<void>(t, 0x41c, 0u);
  vcall<void>(t, 0x628);
  ext_472ff0(t);
  u8 *m = (u8 *)D(t, 0x6c);
  m[4] = 1;
  D(t, 0x424) = 0;
  vcall<void>(t, 0x110, 0x10u, 0x3e8u);
  u32 l10[4];
  u32 l34[9];
  vcall<void>(t, 0x80, (u32)l34, (u32)l10);
  t[0x412] = 1;
  vcall<void>(t, 0x370, (u32)l34, (u32)l10);
  u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u8 *r = (u8 *)D(rm, 0xadc);
  u32 x = vcall<u32>(r, 0x25c, 0x68beb8u, 0u);
  if (!x)
    x = vcall<u32>(r, 0x294, 0x68beb8u, 0x67f610u, 0u, 1u);
  vcall<void>((void *)x, 0x218, (u32)t);
}
PCREG(4824c0, playerClassInit);
