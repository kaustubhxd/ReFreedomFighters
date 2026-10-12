// batch6249 - ragdoll side (claim 42): four small CRagdoll2 / ZRagdollContainer functions.
//   0x640fe0  CRagdoll2::Activate [thiscall, no argument]: this+0x14 = 1, this+0x15 = 1, this+0x16 = 1000, this+0x1a = 0x43160000,
//             this+0x1e = 0x44bb8000, this+0x22 = 0.
//   0x641c50  CRagdoll2::EnableTimeOut(bool) [thiscall, ret 4]: old = this+0x14; this+0x14 = arg byte; when old == 0 and the byte is non-zero,
//             this+0x16 = 1000, this+0x1a = 0x43160000, this+0x1e = 0x44bb8000, this+0x22 = 0.
//   0x641b60  ZRagdollContainer::DeactivateRagdoll(CRagdoll2*) [thiscall, ret 4]: if p == this+0x29 then p+0x15 = 0; else idx = (p - this+0x25) / 0x1df
//             (signed, with the exe's magic-number sequence); if idx is negative or >= this+0x21, the debug report (line 0xa2, text 0x6c2864 with idx)
//             and the return; else the flag word at this+0x2d + 4*idx = 0.
//   0x642140  ZRagdollContainer::GetRagdoll(bool) [thiscall, ret 4]: if the byte is zero: the first index i < this+0x21 whose flag word at this+0x2d is
//             zero gets flag 1 and the result is this+0x25 + i*0x1df (else 0). Otherwise: the result is this+0x29 unless its +0x15 byte is set (then 0).
#include "ff.h"

typedef void (*reportArgFn)(void *, const char *, s32);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void defaults(u8 *self) {
  wr32u(self + 0x16, 0x3e8);
  wr32u(self + 0x1a, 0x43160000u);
  wr32u(self + 0x1e, 0x44bb8000u);
  wr32u(self + 0x22, 0);
}

static void THISCALL fn640fe0(u8 *self) {
  self[0x14] = 1;
  self[0x15] = 1;
  defaults(self);
}

static void THISCALL fn641c50(u8 *self, u32 flag) {
  u8 old = self[0x14];
  u8 b = (u8)flag;
  self[0x14] = b;
  if (old == 0 && b != 0) defaults(self);
}

static void THISCALL fn641b60(u8 *self, u8 *p) {
  u8 *single = rdp(self + 0x29);
  if (p == single) {
    single[0x15] = 0;
    return;
  }
  u32 diff = (u32)p - rd32u(self + 0x25);
  long long prod = (long long)(s32)diff * (long long)0x4468c067LL;
  s32 q = (s32)(prod >> 32) >> 7;
  s32 idx = q + (s32)((u32)q >> 31);
  if (idx < 0 || idx >= (s32)rd32u(self + 0x21)) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x6c283c, 0xa2);
    (*(reportArgFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6c2864, idx);
    return;
  }
  wr32u(rdp(self + 0x2d) + idx * 4, 0);
}

static u8 *THISCALL fn642140(u8 *self, u32 flag) {
  if ((u8)flag == 0) {
    s32 count = (s32)rd32u(self + 0x21);
    if (count <= 0) return 0;
    u8 *flags = rdp(self + 0x2d);
    for (s32 i = 0; i < count; i++) {
      if (rd32u(flags + i * 4) == 0) {
        wr32u(flags + i * 4, 1);
        return rdp(self + 0x25) + (u32)i * 0x1df;
      }
    }
    return 0;
  }
  u8 *p = rdp(self + 0x29);
  if (p[0x15] != 0) return 0;
  return p;
}

PCREG(640fe0, fn640fe0);
PCREG(641c50, fn641c50);
PCREG(641b60, fn641b60);
PCREG(642140, fn642140);
