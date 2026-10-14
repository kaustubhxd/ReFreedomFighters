// batch35019.cpp - cascade s5 batch 35016: 0x567200 (GUESS base update, then write a formatted label through the object found by name).
#include "ff.h"

extern "C" void THISCALL ext_563110(u8 *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_567510(u8 *self);                 // plain ret
typedef u32(THISCALL *g2_t)(void *, u32, u32);
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v1_t)(void *, void *);

// 0x567200, thiscall(a, b) ret 8, returns AL = 0 (EAX otherwise unspecified). 0x563110(this, a, b), 0x567510(this); h = [this+0x54] slot 0x25c(0x6a674c, 0).
// When h: s = engine(0x70039c) slot 0x190(); t = [[engine+0x9b]+0xae4]; v = t slot 0 called with three stack arguments (this[0x188]+1, 0x6a6fac, 0x6a6fc0) that it does NOT pop;
// then slot 0x198 of s as a stdcall-like call (v, buf, s) that pops 8 bytes, the remaining 0x10 bytes are cleaned by the caller. Finally h slot 0x284(buf). buf is a 0x100-byte local.
static u32 THISCALL fn567200(u8 *self, u32 a, u32 b) {
  u8 buf[0x100];
  ext_563110(self, a, b);
  ext_567510(self);
  u8 *h0 = *(u8 **)(self + 0x54);
  u8 *h = (u8 *)(*(g2_t **)h0)[0x25c / 4](h0, 0x6a674c, 0);
  if (h) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *s = (u8 *)(*(g0_t **)eng)[0x190 / 4](eng);
    u32 val = *(u32 *)(self + 0x188) + 1;
    u8 *tab = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xae4);
    u32 vt = *(u32 *)s;
    u32 f198 = ((u32 *)vt)[0x198 / 4];
    u32 f0 = **(u32 **)tab;
    u32 dummy_a = val, dummy_d = f0;
    asm volatile("push %%eax\n\tpush $0x6a6fac\n\tpush $0x6a6fc0\n\tcall *%%edx\n\tpush %%eax\n\tpush %[buf]\n\tpush %[s]\n\tcall *%[f]\n\tadd $16, %%esp"
                 : "+a"(dummy_a), "+d"(dummy_d), "+c"(tab)
                 : [buf] "r"(buf), [s] "r"(s), [f] "r"(f198)
                 : "memory", "cc");
    (*(v1_t **)h)[0x284 / 4](h, buf);
  }
  return 0;
}
PCREG(567200, fn567200);
