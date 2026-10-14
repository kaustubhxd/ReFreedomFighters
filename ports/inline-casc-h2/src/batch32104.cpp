// batch32104.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" u32 THISCALL ext_658dc0(u8 *self, u32 a);                  // thiscall ret 4
extern "C" void THISCALL ext_658ff0(u8 *self, float a);               // thiscall ret 4
extern "C" void THISCALL ext_4cbe50(u8 *self, u8 *src);               // thiscall ret 4

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x5d5510, thiscall no args, returns the slot's eax: x = (float)((int)[[0x70039c]+0x6f] / 16 + 1), y = same for [..+0x73] (unaligned ints, division the biased value is shifted right by 4 (arithmetic));
// slot 0x258 of [this+0x44] with (&{x, y}, 0).
static u32 THISCALL fn5d5510(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  float v[2];
  s32 a = (s32)rd32(eng + 0x6f);
  v[0] = (float)(((a + ((a >> 31) & 15)) >> 4) + 1);
  s32 b = (s32)rd32(eng + 0x73);
  v[1] = (float)(((b + ((b >> 31) & 15)) >> 4) + 1);
  return vcall<u32>(*(void **)(self + 0x44), 0x258, (u32)v, 0u);
}
PCREG(5d5510, fn5d5510);

// 0x657c50, stdcall(p, float f) ret 8: [p+0x6c] == 0 or word [p+0x5a] == 0 -> nothing; o = unaligned [[0x70039c]+0x190f]; slot 0x20 of o is called with the word and leaves it on the stack for 0x63eab0 (which pops it) -> q;
// k = unaligned [[[0x70039c]+0x1aa3]+0x20] + [p+0x6c]; z = 0x658dc0(q, k); z != 0 -> 0x658ff0(z, f).
static void STDCALL fn657c50(u8 *p, float f) {
  if (!*(u32 *)(p + 0x6c)) return;
  u32 w = *(u16 *)(p + 0x5a);
  if (!w) return;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = (u8 *)rd32(eng + 0x190f);
  u32 slot = *(u32 *)(*(u8 **)o + 0x20);
  u8 *q;
  __asm__ volatile("push %[w]\n\tmov %[o], %%ecx\n\tcall *%[slot]\n\tmov %%eax, %%ecx\n\tcall ext_63eab0"
                   : "=a"(q)
                   : [w] "r"(w), [o] "r"(o), [slot] "r"(slot)
                   : "ecx", "edx", "memory", "cc");
  u8 *c1 = (u8 *)rd32(eng + 0x1aa3);
  u32 k = rd32(c1 + 0x20) + *(u32 *)(p + 0x6c);
  u8 *z = (u8 *)ext_658dc0(q, k);
  if (z) ext_658ff0(z, f);
}
PCREG(657c50, fn657c50);

// 0x57c870, thiscall(src) ret 4, returns this: 0x4cbe50(this, src); then copies [0x80..0xa0) as two 16-byte blocks, byte 0xa0, dword 0xa1 (unaligned), bytes 0xa5 and 0xa6, unaligned dwords 0xa7, 0xab, 0xaf.
static u8 *THISCALL fn57c870(u8 *self, u8 *src) {
  ext_4cbe50(self, src);
  for (int i = 0; i < 0x20; i++) self[0x80 + i] = src[0x80 + i];
  self[0xa0] = src[0xa0];
  for (int i = 0; i < 4; i++) self[0xa1 + i] = src[0xa1 + i];
  self[0xa5] = src[0xa5];
  self[0xa6] = src[0xa6];
  for (int i = 0; i < 4; i++) self[0xa7 + i] = src[0xa7 + i];
  for (int i = 0; i < 4; i++) self[0xab + i] = src[0xab + i];
  for (int i = 0; i < 4; i++) self[0xaf + i] = src[0xaf + i];
  return self;
}
PCREG(57c870, fn57c870);
