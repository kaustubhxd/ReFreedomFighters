#include "ff.h"

// 0x4e0e90: thiscall(this, want) ret 4: advances the typed-record cursor [this+8] until a record with tag == want (low byte)
// or the 0xff terminator; eax at the end is stale register content, not a result (spec compares memory only)
u32 THISCALL fn_4e0e90(u8 *self, u32 want) {
  for (;;) {
    u8 *p = *(u8 **)(self + 8);
    u8 b = *p;
    if (b == 0xff) return 0;
    u8 tag = b & 0x3f;
    if (tag == (u8)want) return 0;
    u32 k = (u32)tag - 1;
    u8 *q;
    if (k > 0xb) {
      q = p + 1;
    } else {
      static const u8 map[12] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1, 3};
      switch (map[k]) {
        case 0: q = p + 9; break;
        case 1: q = p + 5; break;
        case 2: {
          u32 n = 0;
          while (p[1 + n] != 0) n++;
          q = p + 2 + n;
          break;
        }
        case 3: {
          u32 len;
          __builtin_memcpy(&len, p + 1, 4);
          q = p + (len + 1);
          break;
        }
        default: q = p + 1; break;
      }
    }
    *(u8 **)(self + 8) = q;
  }
}
PCREG(4e0e90, fn_4e0e90);

// 0x457680: stdcall(code) ret 4: walks a 3x3x3 grid from the centre by 3-bit move codes (up to 10 steps) and returns the visited cell mask
// (0x7fffffff when the mask is empty)
u32 STDCALL fn_457680(u32 code) {
  u32 mask = 0;
  s32 x = 1, y = 1, z = 1;
  u32 cnt = 0;
  for (;;) {
    u32 sel = code & 7;
    code >>= 3;
    switch (sel) {
      case 0: x++; break;
      case 1: x--; break;
      case 2: y++; break;
      case 3: y--; break;
      case 4: z++; break;
      case 5: z--; break;
      default: break;
    }
    if ((u32)x > 2 || (u32)y > 2 || (u32)z > 2) break;
    u32 cell = (u32)(x + 3 * (y + 3 * z));
    cnt++;
    mask |= 1u << (cell & 31);
    if (cnt == 10) break;
  }
  return mask ? mask : 0x7fffffff;
}
PCREG(457680, fn_457680);
