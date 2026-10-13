// f16b025.cpp - fresh slice 16, batch 25 (2026-10-12).
// 0x4c6680 CRootGroup scalar deleting dtor: vtable 0x694b1c; [0x70039c] slot 0x1a8(+0x4c); +0x4c -> its slot 0(1) (deleting
//           dtor); then the base part as in 0x4b1000 (+0x44 = +0x30 = 0, vtable 0x686874, db slot 0x34(this); flags & 1:
//           flags & 4 -> 0x4690b0(this, 0x55), else the assert handler). SEH not reproduced.
// 0x63a0c0 (fastcall mode, lo*; hi*, out, idx): widens two 3-component colours: c | c >> 5 (green: >> 6 for mode 0 on lo,
//           always >> 6 on hi) into S (from lo) and T (from hi); 0x6383a0(fastcall mode, table; &S, &T) fills a 4-entry
//           table of 16 bytes; out[i] = table[idx[i]] for 16 entries. Ret 0xc. Cookie not reproduced. (Looks like a DXT
//           colour-block decoder: a GUESS from the shape.)
// 0x443c80 ZTreeGroup::RemoveStaticChildTreeGroup(child): for this and each parent tree group: arr = +0x7b (word count,
//           word capacity, entries): find child (index i, or count), count--; count left -> arr[i] = arr[count]; else
//           capacity 0 -> [0x6ff968] slot 0x20(arr), +0x7b = 0, [0x6ff968] slot 0x14() == 0 -> delete it (slot 0(1)) and
//           clear [0x6ff968]. Stop when slot 0x310() or 0x308() is true or slot 0x20() is null; next = GetTreeGroup([slot
//           0x20() + 8]).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4690b0[], ext_6383a0[], ext_4db7e0[];

typedef void (*Hfn)();

extern "C" void *THISCALL f16_4c6680(u8 *self, u32 flags) {
  u32 sub = AT(u32, self, 0x4c);
  AT(u32, self, 0) = 0x694b1cu;
  vcall<void>(G(void *, 0x70039c), 0x1a8, sub);
  if (AT(void *, self, 0x4c)) vcall<void>(AT(void *, self, 0x4c), 0, 1u);
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0x30) = 0;
  AT(u32, self, 0) = 0x686874u;
  vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x34, (void *)self);
  if (flags & 1) {
    if (flags & 4)
      ((void (*)(void *, u32))(void *)ext_4690b0)(self, 0x55);
    else
      G(Hfn, 0x7003b0)();
  }
  return self;
}

extern "C" void FASTCALL f16_63a0c0(int mode, int *lo, int *hi, u32 *out, u32 *idx) {
  volatile int S[3], T[3];
  volatile u32 table[16];
  S[0] = (lo[0] >> 5) | lo[0];
  T[0] = (hi[0] >> 5) | hi[0];
  S[1] = (mode ? lo[1] >> 5 : lo[1] >> 6) | lo[1];
  T[1] = (hi[1] >> 6) | hi[1];
  S[2] = (lo[2] >> 5) | lo[2];
  T[2] = (hi[2] >> 5) | hi[2];
  ((void(FASTCALL *)(int, volatile u32 *, volatile int *, volatile int *))(void *)ext_6383a0)(mode, table, S, T);
  for (int i = 0; i < 16; i++) {
    out[4 * i + 0] = table[idx[i] * 4 + 0];
    out[4 * i + 1] = table[idx[i] * 4 + 1];
    out[4 * i + 2] = table[idx[i] * 4 + 2];
    out[4 * i + 3] = table[idx[i] * 4 + 3];
  }
}

extern "C" void THISCALL f16_443c80(u8 *self, u32 child) {
  do {
    u8 *arr = AT(u8 *, self, 0x7b);
    u32 n = AT(u16, arr, 0), i = 0;
    if (n)
      while (AT(u32, arr, 4 + 4 * i) != child && ++i != n) {
      }
    u16 left = (u16)(n - 1);
    AT(u16, arr, 0) = left;
    arr = AT(u8 *, self, 0x7b);
    if (left) {
      AT(u32, arr, 4 + 4 * i) = AT(u32, arr, 4 + 4 * AT(u16, arr, 0));
    } else if (AT(u16, arr, 2) == 0) {
      vcall<void>(G(void *, 0x6ff968), 0x20, arr);
      AT(u32, self, 0x7b) = 0;
      if (vcall<u32>(G(void *, 0x6ff968), 0x14) == 0) {
        if (G(void *, 0x6ff968)) vcall<void>(G(void *, 0x6ff968), 0, 1u);
        G(u32, 0x6ff968) = 0;
      }
    }
    if (vcall<bool>(self, 0x310)) return;
    if (vcall<bool>(self, 0x308)) return;
    if (!vcall<void *>(self, 0x20)) return;
    u8 *g = vcall<u8 *>(self, 0x20);
    self = ((u8 * (THISCALL *)(void *))(void *)ext_4db7e0)(AT(void *, g, 8));
  } while (self);
}

PCREG(4c6680, f16_4c6680);
PCREG(63a0c0, f16_63a0c0);
PCREG(443c80, f16_443c80);
