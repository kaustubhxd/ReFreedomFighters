// batch210048.cpp - Sonnet-w3a: two more /GS-protected rows (message formatter, consistency check with handler)
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);  // /GS check
extern "C" u32 ext_561c40();
extern "C" u32 THISCALL ext_5636c0(u8 *self, u32 a, void *buf);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
typedef u32 (*HookU)();

static void THISCALL fn57c390(u8 *self) {
  u8 buf[0x104];
  u32 al = ext_561c40() & 0xff;  // @57c390_a
  u8 *eng = G(u8 *, 0x70039c);
  u8 *m = *(u8 **)(ld32(eng + 0x9b) + 0xae4);
  typedef u32 (THISCALL *S2)(u8 *, u32, u32);
  u32 r1 = (*(S2 *)(*(u8 **)m))(m, 0x6a67e8, al ? 0x6aa76c : 0x6aa774);  // @57c390_b
  u8 *o = (u8 *)vcall<u32>(G(u8 *, 0x70039c), 0x190);  // @57c390_c
  u8 *vt = *(u8 **)o;
  m = *(u8 **)(ld32(G(u8 *, 0x70039c) + 0x9b) + 0xae4);
  u32 r2 = (*(S2 *)(*(u8 **)m))(m, 0x6a6a34, 0x6aa64c);  // @57c390_d
  typedef u32 (*F)(u8 *, void *, u32, u32, u32);
  (*(F *)(vt + 0x198))(o, buf, 0x68dcfc, r2, r1);  // @57c390_e
  ext_5636c0(self, *(u32 *)(self + 0x180), buf);  // @57c390_f
  ext_633654(0);
}
PCREG(57c390, fn57c390);

static void THISCALL fn5ff960(u8 *self, u8 *a) {
  u32 buf[4];
  u32 loc;
  vcall<u32, u32 *, u32>(a, 0x70, buf, 0x10);  // @5ff960_a
  bool ok = true;
  for (int i = 0; i < 4; i++)
    if (buf[i] != *(u32 *)(self + 0x18 + 4 * i)) { ok = false; break; }  // @5ff960_b
  if (!ok) {
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  vcall<u32, u32 *>(a, 0x5c, &loc);  // @5ff960_c
  if (loc != *(u32 *)(self + 8)) {  // @5ff960_d
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  vcall<u32, u32 *>(a, 0x5c, &loc);
  if (loc != *(u32 *)(self + 0xc)) {  // @5ff960_e
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  ext_633654(0);
}
PCREG(5ff960, fn5ff960);
