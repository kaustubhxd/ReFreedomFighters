#include "ff.h"

typedef u32(*CbFn3)(void *, u32, u32, u32);
typedef u32(THISCALL *V1)(void *, u32);

// 0x62d360: cdecl(a, b, c, d, e): parser step over b-0xf; case 2 calls e->[0x1c](e, c + e->[0x44], d, 0x6c01ec)
extern "C" u32 fn_62d360(u32 *a, int b, u32 c, u32 d, u8 *e) {
  u32 i = (u32)b - 0xf;
  if (i <= 0x1a) {
    static const u8 map[27] = {0, 7, 7, 1, 7, 2, 7, 7, 3, 7, 7, 7, 7, 7, 7, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 1};
    switch (map[i]) {
      case 0: return 0;
      case 1: a[0] = 0x62d690; return 0x2e;
      case 2: {
        CbFn3 f = *(CbFn3 *)(e + 0x1c);
        if (f(e, c + *(u32 *)(e + 0x44), d, 0x6c01ec)) {
          a[0] = 0x62d470;
          return 0x26;
        }
        break;
      }
      case 3: a[1] = 2; a[0] = 0x62d5c0; return 0x27;
      case 4: a[0] = 0x62d690; return 0x30;
      case 5: a[0] = 0x62d690; return 0x2f;
      case 6: a[0] = 0x62d690; return 0x31;
      default: break;
    }
  }
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62d360, fn_62d360);

// 0x4e6330: thiscall(this, visitor) ret 4: walks the typed-record cursor *this past one record; a tag 9 record first hands each non-null
// dword of its body to visitor->[4](value). eax at exit is stale (spec compares memory and calls only).
u32 THISCALL fn_4e6330(u8 **self, u8 *visitor) {
  u8 *p = *self;
  if ((p[0] & 0x3f) == 9) {
    u32 len;
    __builtin_memcpy(&len, p + 1, 4);
    u8 *q = p + 5;
    u32 n = (len >> 2) - 1;
    while (n != 0) {
      u32 v;
      __builtin_memcpy(&v, q, 4);
      if (v) (*(V1 *)(*(u8 **)visitor + 4))(visitor, v);
      q += 4;
      n--;
    }
  }
  p = *self;
  u32 k = (u32)(p[0] & 0x3f) - 1;
  if (k > 0xa) return 0;
  static const u8 map[11] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1};
  switch (map[k]) {
    case 0: *self = p + 9; break;
    case 1: *self = p + 5; break;
    case 2: {
      u32 n = 0;
      while (p[1 + n] != 0) n++;
      *self = p + 2 + n;
      break;
    }
    case 3: {
      u32 len;
      __builtin_memcpy(&len, p + 1, 4);
      *self = p + (len + 1);
      break;
    }
    default: break;
  }
  return 0;
}
PCREG(4e6330, fn_4e6330);
