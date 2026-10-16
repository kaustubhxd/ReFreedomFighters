#include "ff.h"

// 0x628ee0: cdecl(int c): 1 for c in {9, 10, 13, 32} (jump table via byte map), else 0
extern "C" u32 fn_628ee0(int c) {
  u32 i = (u32)c - 9;
  if (i > 0x17) return 0;
  static const u8 map[24] = {0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
  switch (map[i]) {
    case 0: return 1;
    default: return 0;
  }
}
PCREG(628ee0, fn_628ee0);

// 0x62c640: cdecl(u8 a, u8 b): classify a in 0xd8..0xff
extern "C" u32 fn_62c640(u32 a, u32 b) {
  u32 i = (u32)(u8)a - 0xd8;
  if (i > 0x27) return 0x1d;
  static const u8 map[40] = {0, 0, 0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                             3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
  switch (map[i]) {
    case 0: return 7;
    case 1: return 8;
    case 2:
      if ((u8)b < 0xfe) return 0x1d;
      return 0;
    default: return 0x1d;
  }
}
PCREG(62c640, fn_62c640);

// 0x5af1d0: thiscall(this, int sel) ret 4: field selector
u32 THISCALL fn_5af1d0(u8 *self, int sel) {
  u32 i = (u32)sel - 0xc;
  if (i > 4) return 0;
  switch (i) {
    case 0: return *(u32 *)(self + 0xc);
    case 1: return *(u32 *)(self + 8);
    case 2: return *(u32 *)self;
    case 3: return *(u32 *)(self + 0x10) != 0;
    default: return *(u32 *)(self + 4);
  }
}
PCREG(5af1d0, fn_5af1d0);

// 0x62cb80: cdecl(u32 *a, int b): parser state step
extern "C" u32 fn_62cb80(u32 *a, int b) {
  u32 i = (u32)b - 0xf;
  if (i <= 0x1a) {
    static const u8 map[27] = {0, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1};
    if (map[i] == 0) return 0;
    if (map[i] == 1) {
      a[0] = 0x62cc00;
      return 0x1c;
    }
  }
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62cb80, fn_62cb80);

// 0x62e120: cdecl(u32 *a, int b): parser state step
extern "C" u32 fn_62e120(u32 *a, int b) {
  u32 i = (u32)b - 0xb;
  if (i <= 0x12) {
    static const u8 map[19] = {0, 2, 0, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1};
    if (map[i] == 0) return 0;
    if (map[i] == 1) {
      a[0] = 0x51f230;
      return 2;
    }
  }
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62e120, fn_62e120);
