// batch35002.cpp - cascade s5 batch 35002: 0x555c60 (GUESS resolve an entry and apply its flag 0x1000 to the target).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 a);    // thiscall, ret 4: returns a record pointer
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a);   // thiscall, ret 4
typedef u32 (*hook_t)();

// 0x555c60, stdcall(s) ret 4: rec = 0x5003d0(s[4], 0); when rec[4] is neither 0 nor 1 a log line goes out through the object at 0x700390 (slot 0x20(0x69c8e0, 0x104),
// then slot 0x2c(r, 0x69c6b0, 0x69c938) called with ECX = the vtable and caller-popped) and the assert hook 0x7003b0 is called (int3 when null).
// Then e = engine[+0x9b] slot 0x58(rec[0]); 0x5002f0(0x5003d0(s[8], 0), e ? ((e[8][+0x3c]) & 0x1000) : 0).
static void STDCALL fn555c60(u8 *s) {
  u8 *rec = ext_5003d0(*(u32 *)(s + 4), 0);
  u8 b = rec[4];
  if (b != 0 && b != 1) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x69c938\n\tpush $0x69c6b0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = vcall<u8 *>(tab, 0x58, *(u32 *)rec);
  u32 flags = 0;
  if (e) flags = *(u32 *)(*(u8 **)(e + 8) + 0x3c) & 0x1000;
  u8 *r2 = ext_5003d0(*(u32 *)(s + 8), 0);
  ext_5002f0(r2, flags);
}
PCREG(555c60, fn555c60);
