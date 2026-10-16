#include "ff.h"

typedef u32(THISCALL *V1)(void *, void *);
typedef u32(THISCALL *V0)(void *);
extern "C" u32 THISCALL ext_4e1590(void *self);

static inline void call_hook() {
  typedef u32 (*Hook)();
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  h();
}

// 0x486cc0: thiscall(this, a) ret 4: a->[0x50](this+0x2c); a->[0x68](&flag); when flag is set a->[0x40](&kind) and kinds 1..6 copy this+{0x10,
// 0x14, 0x1c, 0x18, 0x20, 0x24} to +0x28; other kinds run the assert hook. Returns the last call's eax.
u32 THISCALL fn_486cc0(u8 *self, u8 *a) {
  (*(V1 *)(*(u8 **)a + 0x50))(a, self + 0x2c);
  volatile u8 flag;
  u32 r = (*(V1 *)(*(u8 **)a + 0x68))(a, (void *)&flag);
  if (flag == 0) return r;
  volatile u32 kind;
  (*(V1 *)(*(u8 **)a + 0x40))(a, (void *)&kind);
  u32 k = kind - 1;
  if (k <= 5) {
    static const u8 off[6] = {0x10, 0x14, 0x1c, 0x18, 0x20, 0x24};
    u32 v = *(u32 *)(self + off[k]);
    *(u32 *)(self + 0x28) = v;
    return v;
  }
  typedef u32 (*Hook)();
  Hook h = G(Hook, 0x7003b0);
  if (!h) __builtin_trap();
  return h();
}
PCREG(486cc0, fn_486cc0);

static inline u32 tagof(u8 *p) {
  u8 b = *p;
  return b == 0xff ? 0 : (b & 0x3f);
}

static inline void log_bad() {
  call_hook();
  u8 *L = G(u8 *, 0x700390);
  u32 ra = *(u32 *)(*(u8 **)L + 0x24), rc = *(u32 *)L;
  asm volatile(
      "pushl $0x6970f8\n\t"
      "pushl %[l]\n\t"
      "call *%%eax\n\t"
      "addl $8, %%esp"
      : "+a"(ra), "+c"(rc)
      : [l] "r"(L)
      : "edx", "memory", "cc");
}

// 0x4e11e0: thiscall(this, out, n) ret 8: reads n int-like typed records (tags 3, 8, 10, 11) into out[]: others run the assert hook and log
// through [0x700390]->[0x24]; the cursor [this+8] advances by 0x4e1590(this)+1; returns the last advance (n >= 1)
u32 THISCALL fn_4e11e0(u8 *self, u32 *out, s32 n) {
  u32 adv;
  for (;;) {
    u8 *p = *(u8 **)(self + 8);
    u32 t = tagof(p);
    if (t != 3 && t != 10 && t != 11 && t != 8) log_bad();
    p = *(u8 **)(self + 8);
    t = tagof(p);
    u32 i = t - 3;
    if (i <= 8 && (i == 0 || i == 5 || i == 7 || i == 8)) {
      u32 v;
      __builtin_memcpy(&v, p + 1, 4);
      *out = v;
    } else {
      log_bad();
    }
    adv = ext_4e1590(self) + 1;
    *(u8 **)(self + 8) += adv;
    if (n == 1) break;
    n--;
    out++;
  }
  return adv;
}
PCREG(4e11e0, fn_4e11e0);
