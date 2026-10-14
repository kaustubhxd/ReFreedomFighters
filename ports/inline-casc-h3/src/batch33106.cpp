// batch33106.cpp - h3 () batch 33106: tier H float/SSE functions
#include "ff.h"

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x4d1220: thiscall no args, returns the wrapping sum of dword [base + 8*i + 4] for i < [this+8] (0 when the count is 0)
static u32 THISCALL fn4d1220(u8 *self) {
  u32 n = *(u32 *)(self + 8);
  if (n == 0) return 0;
  u8 *base = *(u8 **)self;
  u32 sum = 0;
  for (u32 i = 0; i < n; i++) sum += *(u32 *)(base + 8 * i + 4);
  return sum;
}
PCREG(4d1220, fn4d1220);

// 0x467850: thiscall(o, q) ret 8, returns false: o->slot 0x60(byte [this]); slot 0x70(this+1); slot 0x68(this+0x25); slot 0x4c([+0x31]); slot 0x4c([+0x35]); slot 0x3c([+0x39]); r = [+0x3d] ? q->slot 0x3bc(16 bytes from this+0x3d) : 0; o->slot 0x3c(r)
static u8 THISCALL fn467850(u8 *self, u8 *o, u8 *q) {
  vcall<u32>(o, 0x60, (u32)self[0]);
  vcall<u32>(o, 0x70, (u32)(self + 1));
  vcall<u32>(o, 0x68, (u32)(self + 0x25));
  vcall<u32>(o, 0x4c, R32(self + 0x31));
  vcall<u32>(o, 0x4c, R32(self + 0x35));
  vcall<u32>(o, 0x3c, R32(self + 0x39));
  u32 r = 0;
  if (R32(self + 0x3d) != 0) {
    u32 a0 = R32(self + 0x3d), a1 = R32(self + 0x41), a2 = R32(self + 0x45), a3 = R32(self + 0x49);
    r = vcall<u32>(q, 0x3bc, a0, a1, a2, a3);
  }
  vcall<u32>(o, 0x3c, r);
  return 0;
}
PCREG(467850, fn467850);
