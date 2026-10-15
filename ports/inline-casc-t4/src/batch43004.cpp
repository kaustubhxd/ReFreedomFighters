// batch43004.cpp - t4 (Sonnet) batch 43004: tier H float/SSE functions
#include "ff.h"

extern "C" void ext_443ef0();                                  // regs: ecx = out, edx = base; stack (vec *, float scale), ret 8: out = base + vec * scale
extern "C" void ext_4cc7f0();                                  // regs: ecx = haystack, edx = needle; returns eax (found pointer or 0)
extern "C" void THISCALL ext_494b40(u8 *self, u32 a);          // thiscall ret 4
extern "C" void THISCALL ext_494ac0(u8 *self, u32 a);          // thiscall ret 4
extern "C" void THISCALL ext_43e0f0(u8 *self);                 // thiscall, plain ret

// 0x484ff0, thiscall(a, b) ret 8: out[3] = b + (a+0xc) * -[this+0x451] (0x443ef0, sign flipped with the mask at 0x67af40);
// e = this->slot 0x20(); e->slot 0x7c(a, out) (thiscall, ret 8)
static void THISCALL fn484ff0(u8 *self, u8 *a, u8 *b) {
  float out[4];
  u32 nb = fbits(*(float *)(self + 0x451)) ^ *(u32 *)0x67af40;
  __asm__ volatile("pushl %[k]\n\tpushl %[p]\n\tcall ext_443ef0"
                   : : [k] "r"(nb), [p] "r"(a + 0xc), "c"(out), "d"(b) : "eax", "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
  u8 *e = vcall<u8 *>(self, 0x20);
  vcall<void>(e, 0x7c, (u32)a, (u32)out);
}
PCREG(484ff0, fn484ff0);

// 0x48f7e0, thiscall(a) ret 4: [this+0x10] == float at 0x680a60: 0x494b40(this, 0x68e274); a->slot 0x5c(0x10, 0, 0);
// 0x494ac0(this, a->slot 0x14()); otherwise only a->slot 0x5c(0x10, 0, 0)
static void THISCALL fn48f7e0(u8 *self, u8 *a) {
  if (*(float *)(self + 0x10) == G(float, 0x680a60)) {
    ext_494b40(self, 0x68e274);
    vcall<void>(a, 0x5c, 0x10u, 0u, 0u);
    u32 r = vcall<u32>(a, 0x14);
    ext_494ac0(self, r);
  } else {
    vcall<void>(a, 0x5c, 0x10u, 0u, 0u);
  }
}
PCREG(48f7e0, fn48f7e0);

// 0x4ef130, thiscall no args: r = [[sys+0x190f]]->slot 0x178(); byte [0x700e20] = (0x4cc7f0(r, "string at 0x6983ac") != 0); 0x43e0f0(this);
// buf (9 dwords): 16 bytes from 0x698560, 16 bytes from 0x698570, dword 0; this->slot 0x6c(buf); this->slot 0x244()
static void THISCALL fn4ef130(u8 *self) {
  u8 *o = *(u8 **)(*(u8 **)0x70039c + 0x190f);
  u8 *r = vcall<u8 *>(o, 0x178);
  u32 f;
  __asm__ volatile("call ext_4cc7f0" : "=a"(f) : "c"(r), "d"(0x6983ac) : "memory", "cc");
  G(u8, 0x700e20) = (f != 0);
  ext_43e0f0(self);
  u32 buf[9];
  for (int i = 0; i < 4; i++) buf[i] = ((u32 *)0x698560)[i];
  for (int i = 0; i < 4; i++) buf[4 + i] = ((u32 *)0x698570)[i];
  buf[8] = 0;
  vcall<void>(self, 0x6c, (u32)buf);
  vcall<void>(self, 0x244);
}
PCREG(4ef130, fn4ef130);
