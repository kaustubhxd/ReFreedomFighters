// batch6222.cpp - unclaimed-62 claim 15 (slice 2): four leaves.
//   0x487650  thiscall, two arguments (ret 8), returns this: this+0x10 = arg2, this+4 = arg1, this+0xc, +0x14, +0x18, +8 = 0, this+0x1c byte = 0,
//             this+0 = vtable 0x68d14c
//   0x59e610  thiscall, one argument (ret 4): count = this+0x7ce; while count != 0 and the signed dword at this+0x7c2 + 16*count is >= arg,
//             count--, store it at this+0x7ce (the exe loads count into eax, so the store happens after each decrement)
//   0x545e20  thiscall, no arguments: base = this+0xf (dword); for i in 0..this+0x28 (signed): copy three dwords from base+0x14+0x34*i - 8, -0x38, -0x34 ...
//             (mirrors the exe's index walk literally)
//   0x4ce5b0  thiscall, one argument (ret 4), returns dword: idx = arg; if idx >= this+0x14 (signed) return 0; c = this+0xc & 0x7fffffff;
//             d = this+4; while idx >= c (signed) { d = d->next (+4); idx -= c }; return d[ idx * this+0x18 * 4 + 0x10 ]
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 *THISCALL fn487650(u8 *self, u32 a1, u32 a2) {
  wr32u(self + 0x10, a2);
  wr32u(self + 4, a1);
  wr32u(self + 0xc, 0);
  wr32u(self + 0x14, 0);
  wr32u(self + 0x18, 0);
  wr32u(self + 8, 0);
  wr32u(self, 0x68d14c);
  self[0x1c] = 0;
  return self;
}

static void THISCALL fn59e610(u8 *self, u32 arg) {
  u32 cnt = rd32u(self + 0x7ce);
  while (cnt != 0) {
    if ((s32)rd32u(self + cnt * 16 + 0x7c2) < (s32)arg) break;
    cnt--;
    wr32u(self + 0x7ce, cnt);
  }
}

static void THISCALL fn545e20(u8 *self) {
  u8 *esi = rdp(self + 0xf);
  u8 *edx = esi + 0x14;
  s32 n = (s32)rd32u(self + 0x28);
  s32 i = 0;
  if (n <= 0) return;
  do {
    u8 *old = esi;
    esi += 0x34;
    wr32u(old, rd32u(edx - 8));
    edx += 0x34;
    wr32u(edx - 0x44, rd32u(edx - 0x38));
    i++;
    wr32u(edx - 0x40, rd32u(edx - 0x34));
  } while (i < n);
}

static u32 THISCALL fn4ce5b0(u8 *self, u32 arg) {
  u32 idx = arg;
  if ((s32)idx >= (s32)rd32u(self + 0x14)) return 0;
  s32 c = (s32)(rd32u(self + 0xc) & 0x7fffffffu);
  u8 *d = rdp(self + 4);
  if ((s32)idx >= c) {
    do {
      d = rdp(d + 4);
      idx -= (u32)c;
    } while ((s32)idx >= c);
  }
  u32 stride = rd32u(self + 0x18);
  return rd32u(d + (idx * stride) * 4 + 0x10);
}

PCREG(487650, fn487650);
PCREG(59e610, fn59e610);
PCREG(545e20, fn545e20);
PCREG(4ce5b0, fn4ce5b0);
