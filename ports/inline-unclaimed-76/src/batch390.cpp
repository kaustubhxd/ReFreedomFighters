// batch390.cpp - area 76, residue 17 (out/functions.jsonl).
// 0x4f05d0 (thiscall, one stack argument, ret 4; GUESS): calls virtual functions on this and the argument,
// unpacks and stores byte fields.
#include "ff.h"

extern "C" u32 THISCALL ext_45f3c0(u8 *self, u8 *arg);

static u32 THISCALL f4f05d0(u8 *selfp, u8 *argp) {
  u32 self = (u32)selfp;
  u32 arg = (u32)argp;

  // Call this.vtbl[0x244](this)
  typedef void (THISCALL *fn244)(u32);
  fn244 fn = (fn244)(*(u32 *)(*(u32 *)self + 0x244u));
  fn(self);

  // Call ext_45f3c0(this, arg) - external helper
  u32 res = ext_45f3c0(selfp, argp);

  if (!res) return 0;

  // Call arg.vtbl[0x40](arg, this+0x18)
  typedef void (THISCALL *fn40)(u32, u32);
  fn40 fn1 = (fn40)(*(u32 *)(*(u32 *)arg + 0x40u));
  fn1(arg, self + 0x18u);

  // Call arg.vtbl[0x40](arg, this+0x1c)
  fn40 fn2 = (fn40)(*(u32 *)(*(u32 *)arg + 0x40u));
  fn2(arg, self + 0x1cu);

  // Call arg.vtbl[0x18](arg, this+0x20, 1)
  typedef void (THISCALL *fn18)(u32, u32, u32);
  fn18 fn3 = (fn18)(*(u32 *)(*(u32 *)arg + 0x18u));
  fn3(arg, self + 0x20u, 1u);

  // Call arg.vtbl[0x18](arg, this+0x21, 1)
  fn3(arg, self + 0x21u, 1u);

  // Call arg.vtbl[0x18](arg, this+0x22, 8)
  fn3(arg, self + 0x22u, 8u);

  // Call arg.vtbl[0x18](arg, this+0x3e, 8)
  fn3(arg, self + 0x3eu, 8u);

  // Call arg.vtbl[0x18](arg, &local, 1) and extract the byte
  u8 local = 0;
  fn18 fn4 = (fn18)(*(u32 *)(*(u32 *)arg + 0x18u));
  fn4(arg, (u32)&local, 1u);

  u8 low = local & 0xfu;
  u8 high = (local >> 4u) & 1u;

  *(u8 *)(self + 0x8fu) = low;
  *(u8 *)(self + 0x91u) = high;

  u8 byte_at_esi_3 = *(u8 *)(self + 0x18u + 3u);
  *(u8 *)(self + 0x8eu) = byte_at_esi_3;

  // Call this.vtbl[0x238](this, arg)
  typedef void (THISCALL *fn238)(u32, u32);
  fn238 fn5 = (fn238)(*(u32 *)(*(u32 *)self + 0x238u));
  fn5(self, arg);

  *(u8 *)(self + 0x90u) = 1u;

  return 1u;
}
PCREG(4f05d0, f4f05d0);
