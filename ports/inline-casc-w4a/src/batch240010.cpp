// batch240010.cpp - Sonnet-w4a: CRT per-thread lock-token helpers (fs:[0x2c] TLS array).
#include "ff.h"

extern "C" void ext_6345b0();
extern "C" u32 ext_6345fd();
extern "C" u32 ext_6345bc();
extern "C" u32 ext_634609(u32 a);

static inline u8 *w4a_tls_slot() {
  u32 tls;
  asm volatile("movl %%fs:0x2c, %0" : "=r"(tls));
  return *(u8 **)(tls + G(u32, 0x7257d4) * 4);
}

// 0x63452b: cdecl(p): 6345b0(); token = ++[0x6f5660]; *p = token; thread slot[+4] = token; 6345fd(); tail call 6345bc()
static u32 fn_63452b(u32 *p) {
  ext_6345b0();
  u32 t = G(u32, 0x6f5660) + 1;
  G(u32, 0x6f5660) = t;
  *p = t;
  *(u32 *)(w4a_tls_slot() + 4) = G(u32, 0x6f5660);
  ext_6345fd();
  return ext_6345bc();
}
PCREG(63452b, fn_63452b);

// 0x63456a: cdecl(p): 6345b0(); while *p == -1 call 634609(100); then *p == 0: *p = -1, else slot[+4] = token; tail 6345fd()
static u32 fn_63456a(u32 *p) {
  ext_6345b0();
  while (*p != 0) {
    if (*p == 0xffffffffu) {
      ext_634609(0x64);
      continue;
    }
    *(u32 *)(w4a_tls_slot() + 4) = G(u32, 0x6f5660);
    return ext_6345fd();
  }
  *p = 0xffffffffu;
  return ext_6345fd();
}
PCREG(63456a, fn_63456a);
