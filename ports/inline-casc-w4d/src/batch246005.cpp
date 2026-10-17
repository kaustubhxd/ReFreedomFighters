// batch246005.cpp - Sonnet-w4d, tier 6/7 hand ports (run 5).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
typedef u32(THISCALL *W5T1)(u32, u32);
typedef u32(THISCALL *W5T4)(u32, u32, u32, u32, u32);
extern "C" u32 ext_41e290_w5(u32) __asm__("ext_41e290");
extern "C" u32 THISCALL ext_4e6780_w5(u32, u32) __asm__("ext_4e6780");
extern "C" u32 THISCALL ext_48cf50_w5(u32) __asm__("ext_48cf50");
extern "C" u32 THISCALL ext_4cbe80_w5(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cc690_w5(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4cbec0_w5(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_48f880_w5(u32, u32) __asm__("ext_48f880");
extern "C" u32 THISCALL ext_493820_w5(u32, u32, u32, u32) __asm__("ext_493820");
static inline u32 w5ld(u32 a) { u32 v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline void w5st(u32 a, u32 v) { __builtin_memcpy((void *)a, &v, 4); }

// 0x493980: thiscall(name, id, -, -) ret 0x10 -> ax (SEH 0x667ee8, states 0/1/-1/2). Lazily builds the sound/name table object at
// this[0x1c55] (alloc 0x20, ctor 0x4e6780(0x402), vtable 0x68d9bc -> 0x68d9d8, 0x48cf50) and registers three this->vslot 0x114
// callbacks; then lowercases a temp copy of name and looks it up with 0x48f880: hit -> the word at result+4; miss -> id (or a
// new ++this[0x1c59]), a copy of the lowercase name in a buffer from G[0x70039c] vslot 0xf8(len+1) stored at this[0xc4d + id*4],
// registered with 0x493820(table, buf slot, id, 1). Returns the 16-bit id.
extern "C" u32 THISCALL GUESS_493980(u32 self, u32 name, u32 a1, u32 a2, u32 a3) {
  (void)a2; (void)a3;
  SEH_ENTER(0x667ee8);
  u8 Tb[0x84] __attribute__((aligned(4)));
  u32 T = (u32)Tb;
  u32 esi;
  if (w5ld(self + 0x1c55) == 0) {
    esi = ext_41e290_w5(0x20);
    reg.state = 0;
    if (esi) {
      ext_4e6780_w5(esi, 0x402);
      reg.state = 1;
      w5st(esi, 0x68d9bc);
      w5st(esi + 0x1c, 0);
      w5st(esi + 0x18, 0);
      ext_48cf50_w5(esi);
      w5st(esi, 0x68d9d8);
    } else {
      esi = 0;
    }
    reg.state = -1;
    w5st(self + 0x1c55, esi);
    ((W5T4)*(u32 *)(*(u32 *)self + 0x114))(self, 0x68a994, 0x401, 0, 0);
    ((W5T4)*(u32 *)(*(u32 *)self + 0x114))(self, 0x68d9f0, 0x400, 0, 0);
    ((W5T4)*(u32 *)(*(u32 *)self + 0x114))(self, 0x68d9f0, 0x400, 0, 0);
  }
  ext_4cbe80_w5(T, name);
  reg.state = 2;
  ext_4cc690_w5(T);
  u32 pp = *(u32 *)T;
  u32 r = ext_48f880_w5(w5ld(self + 0x1c55), (u32)&pp);
  if (r != 0 && r + 4 != 0) {
    esi = *(const u16 *)(r + 4);
  } else {
    esi = a1;
    if (esi == 0) {
      esi = w5ld(self + 0x1c59) + 1;
      w5st(self + 0x1c59, esi);
    }
    const u8 *s = (const u8 *)*(u32 *)T;
    u32 len = 0;
    while (s[len]) len++;
    u32 g = *(u32 *)0x70039c;
    u32 ebx = self + 0xc4d + esi * 4;
    u32 buf = ((W5T1)*(u32 *)(*(u32 *)g + 0xf8))(g, len + 1);
    w5st(ebx, buf);
    const u8 *s2 = (const u8 *)*(u32 *)T;
    u8 *d = (u8 *)w5ld(ebx);
    u8 cl;
    do { cl = *s2++; *d++ = cl; } while (cl);
    ext_493820_w5(w5ld(self + 0x1c55), ebx, esi, 1);
    esi &= 0xffff;
  }
  ext_4cbec0_w5(T);
  SEH_LEAVE();
  return esi & 0xffff;
}
PCREG(493980, GUESS_493980);
