// batch34024.cpp - cascade tier E, batch 34024: 0x52cb00 (write a record to a stream when the checker accepts), 0x5590d0 / 0x559140 (send a kind-checked
// entry byte to a sink with a 1 / 0 flag).
#include "ff.h"

extern "C" bool THISCALL ext_45f960(void *self, void *s);       // thiscall ret 4, bool in al
extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);          // thiscall ret 4: entry lookup
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x52cb00, thiscall(s) ret 4: when 0x45f960(this, s): s->slot0x44([this+0x75]); p = [this+0x79] (unaligned pointer); s->slot0x44 of [p+4], [p+8], [p+0xc];
// s->slot0x10([p], [p+4]*0x32); returns true, else false.
static bool THISCALL fn52cb00(u8 *self, u8 *s) {
  if (!ext_45f960(self, s)) return false;
  vcall<void>(s, 0x44, rd32u(self + 0x75));
  u8 *p = (u8 *)rd32u(self + 0x79);
  vcall<void>(s, 0x44, *(u32 *)(p + 4));
  vcall<void>(s, 0x44, *(u32 *)(p + 8));
  vcall<void>(s, 0x44, *(u32 *)(p + 0xc));
  vcall<void>(s, 0x10, *(u32 *)p, *(u32 *)(p + 4) * 0x32);
  return true;
}
PCREG(52cb00, fn52cb00);

// Shared body of 0x5590d0 / 0x559140: e = 0x5003d0([a+4], 0); a kind byte [e+4] other than 0 / 1 logs through the object at 0x700390
// (slot 0x20(0x69c8e0, 0x104), its slot 0x2c with (r, 0x69c6b0, 0x69c938), caller-popped) and calls the assert hook (int3 when null);
// then [this+0x1c]->slot0x6d8(flag, byte [e]).
static inline void send_entry(u8 *self, u8 *a, u32 flag) {
  u8 *e = (u8 *)ext_5003d0(*(u8 **)(a + 4), 0);
  u8 kind = e[4];
  if (kind != 0 && kind != 1) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x104u);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x69c938\n\tpush $0x69c6b0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *o = *(u8 **)(self + 0x1c);
  vcall<void>(o, 0x6d8, flag, (u32)e[0]);
}

// 0x5590d0, thiscall(a) ret 4: flag 1.
static void THISCALL fn5590d0(u8 *self, u8 *a) { send_entry(self, a, 1); }
PCREG(5590d0, fn5590d0);

// 0x559140, thiscall(a) ret 4: flag 0.
static void THISCALL fn559140(u8 *self, u8 *a) { send_entry(self, a, 0); }
PCREG(559140, fn559140);
