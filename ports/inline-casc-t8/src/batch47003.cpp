// batch47003.cpp - cascade t8 batch 47003: 0x5f9130 (tier F row).
#include "ff.h"

typedef void (*hook_t)();

extern "C" void THISCALL ext_5f3c90(void *self, u32 *p);             // ret 4
extern "C" u32 THISCALL ext_5f5620(void *self, u32 v);               // ret 4
extern "C" void THISCALL ext_5f56f0(void *self);                     // plain ret
extern "C" void THISCALL ext_5f55e0(void *self);                     // plain ret
extern "C" void THISCALL ext_6001e0(void *ctx, void *a, u32 b, u32 *c, void *d);   // ret 0x10, this = a[0x96]

static inline u16 rd16(u8 *p) { return (u16)(p[0] | (p[1] << 8)); }
static inline void wr16(u8 *p, u32 v) { p[0] = (u8)v; p[1] = (u8)(v >> 8); }
static inline void wr32(u8 *p, u32 v) { p[0] = (u8)v; p[1] = (u8)(v >> 8); p[2] = (u8)(v >> 16); p[3] = (u8)(v >> 24); }


// 0x5f9130, thiscall(a, flag byte) ret 8. Word this[0xac] has flags: 0x800 set -> assert hook (int3 when none, result ignored); 0x8800 any set -> this[0x12] = a, return.
// Else old = this[0x64], rec = {2, ?, ?, old, a} -> 0x5f3c90(this, rec); this[0x6c] != -1: this[0xa6] (unaligned dword) = 0x5f5620(this, this[0x6c]); with flag: this[0xac] |= 0x800, 0x5f56f0(this), clear 0x800.
// 0x5f55e0(this+0x40), 0x5f55e0(this+0x34), this[0xaa] = 0 (word); a != this[0x64]: 0x6001e0(this[0x96]; this, a, this+0x64, this+0x28).
// this[0x68] != -1: this[0xa6] = 0x5f5620(this, this[0x68]), with flag the same 0x800 / 0x5f56f0 / clear sequence; else this[0xa6] = 0x5f5620(this, a).
static void THISCALL fn5f9130(u8 *self, u32 a, u32 flagarg) {
  u8 flag = (u8)flagarg;
  if (rd16(self + 0xac) & 0x800) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  if (rd16(self + 0xac) & 0x8800) {
    *(u32 *)(self + 0x12) = a;
    return;
  }
  u32 old = *(u32 *)(self + 0x64);
  u32 rec[5];
  rec[0] = 2;
  rec[1] = 0;
  rec[2] = 0;
  rec[3] = old;
  rec[4] = a;
  ext_5f3c90(self, rec);
  u32 v = *(u32 *)(self + 0x6c);
  if (v != 0xffffffff) {
    wr32(self + 0xa6, ext_5f5620(self, v));
    if (flag) {
      wr16(self + 0xac, rd16(self + 0xac) | 0x800);
      ext_5f56f0(self);
      wr16(self + 0xac, rd16(self + 0xac) & 0xf7ff);
    }
  }
  ext_5f55e0(self + 0x40);
  ext_5f55e0(self + 0x34);
  wr16(self + 0xaa, 0);
  if (a != *(u32 *)(self + 0x64)) ext_6001e0(*(void **)(self + 0x96), self, a, (u32 *)(self + 0x64), self + 0x28);
  v = *(u32 *)(self + 0x68);
  if (v != 0xffffffff) {
    wr32(self + 0xa6, ext_5f5620(self, v));
    if (flag) {
      wr16(self + 0xac, rd16(self + 0xac) | 0x800);
      ext_5f56f0(self);
      wr16(self + 0xac, rd16(self + 0xac) & 0xf7ff);
    }
  } else {
    wr32(self + 0xa6, ext_5f5620(self, a));
  }
}
PCREG(5f9130, fn5f9130);
