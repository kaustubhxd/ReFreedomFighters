// batch34060.cpp - cascade tier E, batch 34060: 0x518110 (time-gated update or a two-way slot sequence), 0x52b430 (read a counted array from a stream and clear its fields), 0x54eca0 (reset a
// block to defaults and query the COM-style device).
#include "ff.h"

typedef u32(STDCALL *com7_t)(void *dev, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x518110, thiscall, no args: with byte [this+0x133]: t = [engine+0x40]; p = this+0x35c; nothing when [p] >= t (signed) or when p happens to equal the address of a stack local; else [p] = t + 0x400.
// Without it: flag = ([this+0x1650] != 1); this slot 0x80(this+0x6c, this+0x60); this slot 0x36c(flag) (the pushed value is EBX, whose upper bits are what the caller left in it); this slot 0x80 again.
static void THISCALL fn518110(u8 *self) {
  s32 local;
  if (self[0x133] != 0) {
    s32 t = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
    s32 *p = (s32 *)(self + 0x35c);
    if (*p >= t) return;
    if ((u32)p == (u32)&local) return;
    *p = t + 0x400;
    return;
  }
  u32 flag = *(u32 *)(self + 0x1650) != 1;
  vcall<void>(self, 0x80, (u32)(self + 0x6c), (u32)(self + 0x60));
  vcall<void>(self, 0x36c, flag);
  vcall<void>(self, 0x80, (u32)(self + 0x6c), (u32)(self + 0x60));
}
PCREG(518110, fn518110);

// 0x52b430, thiscall(s) ret 4, returns true: s slot 0x48 into this+4, this+8, this+0xc; s slot 0x18([this], [this+4]*0x32); then for each of the [this+4] (signed) 0x32-byte entries at [this] the
// dwords at +0x20, +0x24, +0x28 are cleared.
static bool THISCALL fn52b430(u8 *self, u8 *s) {
  vcall<void>(s, 0x48, (u32)(self + 4));
  vcall<void>(s, 0x48, (u32)(self + 8));
  vcall<void>(s, 0x48, (u32)(self + 0xc));
  s32 n = *(s32 *)(self + 4);
  vcall<void>(s, 0x18, *(u32 *)self, (u32)n * 0x32);
  u8 *p = *(u8 **)self;
  for (s32 i = 0; i < n; i++) {
    wr32u(p + 0x24, 0);
    wr32u(p + 0x28, 0);
    wr32u(p + 0x20, 0);
    p += 0x32;
  }
  return true;
}
PCREG(52b430, fn52b430);

// 0x54eca0, thiscall, no args: nothing when [this+4] is null. Otherwise the block at +8..+0x4c is reset (+8, +0xc, +0x10..+0x20 = 0, +0x24 = 0.25f, +0x28 = 1.5f, +0x2c = 1.0f, +0x30 = 0, +0x34 = 1.0f,
// +0x38..+0x44 = 0, +0x48 = 1.0f, +0x4c = 7) and the COM-style method 0x10 of [this+4] is called with (dev, 0x6bdf70, 0x80000001, 0, 0, this+8, 0x48) (stdcall); a negative result logs through the
// object at 0x700390 (slot 0x20(0x6a4168, 0x168), then its slot 0x2c with (r, 0x6a42c4), caller-popped).
static void THISCALL fn54eca0(u8 *self) {
  u8 *dev = *(u8 **)(self + 4);
  if (!dev) return;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 8) = 0;
  for (u32 off = 0x10; off <= 0x20; off += 4) *(u32 *)(self + off) = 0;
  *(u32 *)(self + 0x24) = 0x3e800000;
  *(u32 *)(self + 0x28) = 0x3fc00000;
  *(u32 *)(self + 0x2c) = 0x3f800000;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0x3f800000;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x40) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x48) = 0x3f800000;
  *(u32 *)(self + 0x4c) = 7;
  u32 vt = *(u32 *)dev;
  com7_t f = (com7_t)((u32 *)vt)[0x10 / 4];
  s32 hr = (s32)f(dev, 0x6bdf70, 0x80000001u, 0, 0, (u32)(self + 8), 0x48);
  if (hr >= 0) return;
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x6a4168u, 0x168u);
  u32 rvt = *(u32 *)r;
  u32 slot = ((u32 *)rvt)[0x2c / 4];
  asm volatile("push $0x6a42c4\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(rvt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(54eca0, fn54eca0);
