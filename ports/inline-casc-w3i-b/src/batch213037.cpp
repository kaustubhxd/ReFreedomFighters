#include "ff.h"

typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);

static inline u32 *find_rec(u32 key) {
  for (u32 k = 0; k < 18; k++) {
    u32 *e = (u32 *)(0x6e7a38 + k * 0x14);
    if (*e == key) return (u32 *)(0x6e7a30 + k * 0x14);
  }
  return 0;
}

static inline u32 slen1(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n + 1;
}

static inline void log3(u32 fmt, u32 str) {
  u8 *L = G(u8 *, 0x700390);
  u32 ra = *(u32 *)(*(u8 **)L + 0x24), rc = *(u32 *)L;
  asm volatile(
      "pushl %[s]\n\t"
      "pushl %[f]\n\t"
      "pushl %[l]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [s] "r"(str), [f] "r"(fmt), [l] "r"(L)
      : "edx", "memory", "cc");
}

static inline void log2(u32 fmt) {
  u8 *L = G(u8 *, 0x700390);
  u32 ra = *(u32 *)(*(u8 **)L + 0x24), rc = *(u32 *)L;
  asm volatile(
      "pushl %[f]\n\t"
      "pushl %[l]\n\t"
      "call *%%eax\n\t"
      "addl $8, %%esp"
      : "+a"(ra), "+c"(rc)
      : [f] "r"(fmt), [l] "r"(L)
      : "edx", "memory", "cc");
}

// 0x4d2700: thiscall(this, str, mask, key, X, Y) ret 0x14: looks the record for key (field +8 of the 0x14-byte records at 0x6e7a30, 18 of them),
// logs when its flags (+0x10) do not contain mask, derives a length and a value (Y, record field +0xc, or from X by the record type 0xc..0x11), then
// calls this->[0xac](str, strlen+1, record for the type, value, X or &X when the type is 5)
u32 THISCALL fn_4d2700(u8 *self, u32 str, u32 mask, u32 key, u32 X, u32 Y) {
  u32 *rec = find_rec(key);
  if ((rec[4] & mask) == 0) log3(0x6963cc, str);
  u32 type = rec[2];
  u32 ebx = type == 5 ? (u32)&X : X;
  u32 len = slen1((const char *)str);
  u32 val = Y;
  if (val == 0) {
    val = rec[3];
    if (val == 0) {
      u32 d = type - 0xc;
      if (d <= 5) {
        switch (d) {
          case 0:
          case 2: val = slen1((const char *)ebx); break;
          case 3:
          case 5: val = *(u32 *)ebx; break;
          default: log2(0x696404); break;
        }
      } else {
        log2(0x696404);
      }
    }
  }
  u32 *rec2 = find_rec(rec[2]);
  return (*(V5 *)(*(u8 **)self + 0xac))(self, str, len, (u32)rec2, val, ebx);
}
PCREG(4d2700, fn_4d2700);
