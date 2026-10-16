#include "ff.h"

typedef u32(*CbFn4)(void *, u32, u32, u32);
typedef u32(THISCALL *LogNew2)(void *, u32, u32);

// 0x62d030: cdecl(a, b, c, d, e): parser step over b-0xf; case 3 tries two e->[0x1c](e, c, d, str) callbacks
extern "C" u32 fn_62d030(u32 *a, int b, u32 c, u32 d, u8 *e) {
  u32 i = (u32)b - 0xf;
  if (i <= 0xa) {
    static const u8 map[11] = {0, 4, 1, 2, 4, 4, 4, 4, 4, 4, 3};
    switch (map[i]) {
      case 0: return 0;
      case 1: a[0] = 0x62e120; return 7;
      case 2: {
        CbFn4 f = *(CbFn4 *)(e + 0x1c);
        if (f(e, c, d, 0x6c0208)) {
          a[0] = 0x62d160;
          return 0;
        }
        f = *(CbFn4 *)(e + 0x1c);
        if (f(e, c, d, 0x6c01f4)) {
          a[0] = 0x62d110;
          return 0;
        }
        break;
      }
      case 3: a[0] = 0x62dc60; return 6;
      default: break;
    }
  }
  if (a[3] == 0 && b == 0x1c) return (u32)b + 0x18;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62d030, fn_62d030);

// 0x4e14a0: thiscall(this, out, n) ret 8: reads n typed records (cursor [this+8]); a tag 3 record gives out[i] = (dword != 0); any other
// record logs through [0x700390] and runs the assert hook [0x7003b0] (int3 when null); the cursor then advances by 9 / 5 / string / blob / 1.
// eax at exit is stale (spec compares memory and calls only).
u32 THISCALL fn_4e14a0(u8 *self, u8 *out, s32 n) {
  for (s32 i = 0; i < n; i++) {
    u8 *p = *(u8 **)(self + 8);
    u8 b = *p;
    if (b != 0xff && (b & 0x3f) == 3) {
      u32 v;
      __builtin_memcpy(&v, p + 1, 4);
      out[i] = v != 0;
    } else {
      void *L = G(void *, 0x700390);
      u8 *M = (u8 *)(*(LogNew2 *)(*(u8 **)L + 0x20))(L, 0x697114, 0x247);
      u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
      asm volatile(
          "pushl $0x6971b8\n\t"
          "pushl %[m]\n\t"
          "call *%%eax\n\t"
          "addl $8, %%esp"
          : "+a"(ra), "+c"(rc)
          : [m] "r"(M)
          : "edx", "memory", "cc");
      typedef u32 (*Hook)();
      Hook h = G(Hook, 0x7003b0);
      if (!h) __builtin_trap();
      h();
    }
    p = *(u8 **)(self + 8);
    b = *p;
    u32 tag = b & 0x3f;   // the original maps 0xff to 0, which lands in the same default case as 0x3f
    u32 k = tag - 1;
    u32 adv;
    if (k > 0xb) {
      adv = 1;
    } else {
      static const u8 map[12] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1, 3};
      switch (map[k]) {
        case 0: adv = 9; break;
        case 1: adv = 5; break;
        case 2: {
          u32 m = 0;
          while (p[1 + m] != 0) m++;
          adv = 2 + m;
          break;
        }
        case 3: {
          u32 len;
          __builtin_memcpy(&len, p + 1, 4);
          adv = len + 1;
          break;
        }
        default: adv = 1; break;
      }
    }
    *(u8 **)(self + 8) = p + adv;
  }
  return 0;
}
PCREG(4e14a0, fn_4e14a0);
