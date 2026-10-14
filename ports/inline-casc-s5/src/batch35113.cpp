// batch35113.cpp - cascade s5 batch 35113: 0x578c70 (GUESS apply three stored option bytes through helpers, then format and show a label).
#include "ff.h"

extern "C" void THISCALL ext_579bd0(u8 *self, u32 a);   // thiscall, ret 4
extern "C" void THISCALL ext_579b20(u8 *self, u32 a);   // thiscall, ret 4 (batch 35047)
extern "C" void THISCALL ext_579a60(u8 *self, u32 a);   // thiscall, ret 4 (batch 35112)
typedef u8 *(THISCALL *g0p_t)(void *);
typedef void(THISCALL *v3_t)(void *, void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x578c70, thiscall, no arguments. 0x579bd0(this, byte +0x1b4); 0x579b20(this, byte +0x1b5); l = byte +0x1b6 (stored in a dword local whose upper bytes are uninitialised in the exe: only the low byte is defined);
// s = [0x70039c] slot 0x190(); s slot 0x198 called with ECX = its vtable and four caller-popped stack args (s, buf, 0x6a9af0, [this+0x194]); t = [engine+0x9b] slot 0x134(); t slot 0x68(buf, l, 0); 0x579a60(this, byte +0x1b7);
// this slot 0xd0(0).
static void THISCALL fn578c70(u8 *self) {
  u8 buf[0x40];
  ext_579bd0(self, self[0x1b4]);
  ext_579b20(self, self[0x1b5]);
  u32 l = self[0x1b6];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *s = (*(g0p_t **)eng)[0x190 / 4](eng);
  u32 vt = *(u32 *)s;
  u32 f = ((u32 *)vt)[0x198 / 4];
  u32 idx = *(u32 *)(self + 0x194);
  asm volatile("push %[idx]\n\tpush $0x6a9af0\n\tpush %[buf]\n\tpush %[s]\n\tcall *%[f]\n\tadd $16, %%esp" : : "c"(vt), [idx] "r"(idx), [buf] "r"(buf), [s] "r"(s), [f] "r"(f) : "eax", "edx", "memory", "cc");
  eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *t = (*(g0p_t **)tab)[0x134 / 4](tab);
  (*(v3_t **)t)[0x68 / 4](t, buf, l, 0);
  ext_579a60(self, self[0x1b7]);
  (*(v1_t **)self)[0xd0 / 4](self, 0);
}
PCREG(578c70, fn578c70);
