// batch1031.cpp - ZCamHelper::Load(ZLoadGame*): the helper's saved fields, the mirror of batch1030 (Save).
// The op table is generated from the disassembly of 0x5d0600 (87 ops, in call order). Codes:
//   0 plain read through the load object (slot in the table, destination = field pointer);
//   1 float read to a temporary, clamped (out of +-3.13985 becomes pi), then stored (a54, a58, ae9);
//   2 read dword to a temporary (slot 0x44), low 16 bits kept, stored as dword (ad5, e1c);
//   3 handle read (slot 0x40) to a temporary, then the manager's slot 0x58 resolves it (ae5, e18);
//   4 dword read (slot 0x40) to a temporary, stored raw (b50).
// Camera thread, 2026-10-11.
#include "cam.h"

struct LoadOp {
  u16 off;
  u8 slot;
  u8 code;
};
static const LoadOp kZCamLoad[] = {
    {0xa54, 0x50, 1},
    {0xa58, 0x50, 1},
    {0xa5c, 0x50, 0},
    {0xa60, 0x50, 0},
    {0xa64, 0x50, 0},
    {0xa68, 0x50, 0},
    {0xa6c, 0x50, 0},
    {0xa70, 0x68, 0},
    {0xa71, 0x68, 0},
    {0xa72, 0x6c, 0},
    {0xa7e, 0x6c, 0},
    {0xa8a, 0x6c, 0},
    {0xa96, 0x50, 0},
    {0xa9a, 0x50, 0},
    {0xa9e, 0x50, 0},
    {0xaa2, 0x50, 0},
    {0xaae, 0x50, 0},
    {0xab6, 0x68, 0},
    {0xad5, 0x44, 2},
    {0xad9, 0x50, 0},
    {0xadd, 0x50, 0},
    {0xad4, 0x68, 0},
    {0xae1, 0x40, 0},
    {0xae5, 0x40, 3},
    {0xae9, 0x50, 1},
    {0xaed, 0x50, 0},
    {0xaf1, 0x50, 0},
    {0xaf5, 0x50, 0},
    {0xaf9, 0x50, 0},
    {0xafd, 0x50, 0},
    {0xb01, 0x50, 0},
    {0xb05, 0x50, 0},
    {0xb09, 0x50, 0},
    {0xb0d, 0x50, 0},
    {0xb11, 0x50, 0},
    {0xb15, 0x50, 0},
    {0xb19, 0x68, 0},
    {0xb1a, 0x68, 0},
    {0xb1f, 0x50, 0},
    {0xb23, 0x50, 0},
    {0xb27, 0x50, 0},
    {0xb2b, 0x50, 0},
    {0xb2f, 0x68, 0},
    {0xb30, 0x68, 0},
    {0xb31, 0x68, 0},
    {0xb32, 0x68, 0},
    {0xb33, 0x68, 0},
    {0xb34, 0x68, 0},
    {0xb35, 0x50, 0},
    {0xb39, 0x6c, 0},
    {0xb45, 0x68, 0},
    {0xb47, 0x68, 0},
    {0xb48, 0x68, 0},
    {0xb49, 0x50, 0},
    {0xb4d, 0x68, 0},
    {0xb4f, 0x68, 0},
    {0xb50, 0x40, 4},
    {0xc6d, 0x40, 0},
    {0xc71, 0x6c, 0},
    {0xc7d, 0x6c, 0},
    {0xc89, 0x74, 0},
    {0xcad, 0x6c, 0},
    {0xcb9, 0x74, 0},
    {0xcdd, 0x74, 0},
    {0xd01, 0x6c, 0},
    {0xd0d, 0x40, 0},
    {0xd11, 0x40, 0},
    {0xd15, 0x6c, 0},
    {0xd21, 0x68, 0},
    {0xd22, 0x6c, 0},
    {0xd2e, 0x40, 0},
    {0xd32, 0x68, 0},
    {0xd33, 0x68, 0},
    {0xd34, 0x68, 0},
    {0xd35, 0x68, 0},
    {0xdd8, 0x68, 0},
    {0xdf5, 0x50, 0},
    {0xdf9, 0x50, 0},
    {0xdfd, 0x50, 0},
    {0xe01, 0x50, 0},
    {0xe05, 0x50, 0},
    {0xe09, 0x50, 0},
    {0xe0d, 0x68, 0},
    {0xe0e, 0x68, 0},
    {0xe17, 0x68, 0},
    {0xe18, 0x40, 3},
    {0xe1c, 0x44, 2},
};

static inline float load_clamp_pi(float t) {
  if (t > G(float, 0x6ad1fc)) return G(float, 0x67da18);
  if (G(float, 0x6ad234) > t) return G(float, 0x67da18);
  return t;
}

// 0x5d0600 ZCamHelper::Load(ZLoadGame*): clears flag 0x40 of +4, then reads every field of the table.
static THISCALL u32 ZCamHelper_Load(u8 *self, void *lg) {
  at<u32>(self, 4) &= 0xffffffbf;
  for (const LoadOp &op : kZCamLoad) {
    switch (op.code) {
      case 0: vcall<void>(lg, op.slot, self + op.off); break;
      case 1: {
        float t = 0.0f;
        vcall<void>(lg, op.slot, &t);
        at<float>(self, op.off) = load_clamp_pi(t);
        break;
      }
      case 2: {
        u32 t = 0;
        vcall<void>(lg, op.slot, &t);
        at<u32>(self, op.off) = t & 0xffffu;
        break;
      }
      case 3: {
        u32 t = 0;
        vcall<void>(lg, op.slot, &t);
        at<u32>(self, op.off) = vcall<u32>(SYS9B, 0x58, t);
        break;
      }
      case 4: {
        u32 t = 0;
        vcall<void>(lg, op.slot, &t);
        at<u32>(self, op.off) = t;
        break;
      }
    }
  }
  return 1;
}
PCREG(5d0600, ZCamHelper_Load);
