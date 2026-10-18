#include "ff.h"

extern "C" u32 ext_62dc60(u32 *a, int b);

static inline u32 parse_fail(u32 *a, int b) {
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}

// 0x62ca20: cdecl(a, b): parser state step over b-0xf
extern "C" u32 fn_62ca20(u32 *a, int b) {
  u32 i = (u32)b - 0xf;
  if (i <= 0x1a) {
    static const u8 map[27] = {0, 3, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                               3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
    switch (map[i]) {
      case 0: return 0;
      case 1: a[0] = a[3] != 0 ? 0x62dc60 : 0x62dbb0; return 0;
      case 2: a[0] = 0x62cac0; return 0x13;
      default: break;
    }
  }
  return parse_fail(a, b);
}
PCREG(62ca20, fn_62ca20);

// 0x62d470: cdecl(a, b): parser state step over b-0xf
extern "C" u32 fn_62d470(u32 *a, int b) {
  u32 i = (u32)b - 0xf;
  if (i <= 0x15) {
    static const u8 map[22] = {0, 4, 4, 4, 4, 4, 1, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3};
    switch (map[i]) {
      case 0: return 0;
      case 1: a[0] = 0x62d510; return 0;
      case 2: a[0] = 0x62cf90; return 0x28;
      case 3: a[0] = 0x62cf90; return 0x29;
      default: break;
    }
  }
  return parse_fail(a, b);
}
PCREG(62d470, fn_62d470);

// 0x62dbb0: cdecl(a, b): parser state step over b+4; case 5 tail-jumps to 0x62dc60 with the same arguments
extern "C" u32 fn_62dbb0(u32 *a, int b) {
  u32 i = (u32)b + 4;
  if (i <= 0x26) {
    static const u8 map[39] = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1,
                               5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 5, 5, 5, 5, 5, 5, 3, 4};
    switch (map[i]) {
      case 0:
        if (a[2] == 0) return 0;
        break;
      case 1: return 0;
      case 2: break;
      case 3: a[0] = 0x62ce70; return 0;
      case 4:
        if (a[2] != 0) {
          a[2] = a[2] - 1;
          return 0;
        }
        break;
      default: return ext_62dc60(a, b);
    }
    return parse_fail(a, b);
  }
  return ext_62dc60(a, b);
}
PCREG(62dbb0, fn_62dbb0);
