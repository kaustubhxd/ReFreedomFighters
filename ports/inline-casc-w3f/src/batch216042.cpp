// batch216042.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_505fa0_thiscall2(u32, u32) __asm__("ext_505fa0");
extern "C" u32 ext_506040_cdecl3(...) __asm__("ext_506040");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL ext_506040_thiscall1(u32) __asm__("ext_506040");
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
extern "C" u32 THISCALL lifted_505df0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_505df0
  u8 loc[0x80] __attribute__((aligned(16)));
  u32 edi = ecx_in, ebx = a0, eax;
  u32 p = ext_5003d0_thiscall2(*(u32 *)(ebx + 4), 0);  // @h1_505df0
  u32 t = *(u8 *)(p + 4);
  if (t == 3) eax = *(u32 *)p;  // @h2_505df0
  else if (t == 4) {  // @h3_505df0
    u32 c = *(u32 *)p;
    eax = ((u32(THISCALL *)(u32))VSLOT(c, 0x34))(c);  // @h4_505df0
  } else {
    u32 lg = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x69c8e0, 0x111);  // @h5_505df0
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x69c6b0, 0x69c9b0);  // @h6_505df0
    u32 h = G(u32, 0x7003b0);
    if (h) { ((u32(*)())h)(); eax = 0; } else __builtin_trap();
  }
  u32 esi = ext_505fa0_thiscall2(edi, eax);  // @h7_505df0
  u32 x;
  if (esi) { u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b); x = esi - *(u32 *)(tbl + 0x44); }  // @h8_505df0
  else x = (u32)-1;
  u32 q = ext_5003d0_thiscall2(*(u32 *)(ebx + 8), 0);  // @h9_505df0
  eax = ext_5002f0_thiscall2(q, x);  // @h10_505df0
  if (G(u8, 0x700f78) != 0 && esi == 0) {  // @h11_505df0
    u32 o14 = *(u32 *)(edi + 0x14);
    u32 s1 = ((u32(THISCALL *)(u32))VSLOT(o14, 0x30c))(o14);  // @h12_505df0
    u32 e1 = s1 ? s1 : 0x69cd1c;
    u32 o14b = *(u32 *)(edi + 0x14);
    u32 s2 = ((u32(THISCALL *)(u32))VSLOT(o14b, 0x310))(o14b);  // @h13_505df0
    u32 e2 = s2 ? s2 : 0x69cd1c;
    u32 lg = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x69cd2c, 0xb7);  // @h14_505df0
    u32 o14c = *(u32 *)(edi + 0x14);
    u32 sv = ((u32(THISCALL *)(u32, u32, u32))VSLOT(o14c, 0x1d8))(o14c, (u32)(u8 *)loc, 1);  // @h15_505df0
    reg.state = 0;
    u32 str = ext_4cc1d0_thiscall1(sv);
    u32 p2 = ext_5003d0_thiscall2(*(u32 *)(ebx + 4), 0);  // @h16_505df0
    u32 r40 = ext_506040_thiscall1(p2);  // @h17_505df0
    ((u32(*)(u32, u32, u32, u32, u32, u32))VSLOT(L, 0x30))(L, 0x69cd60, r40, e1, e2, str);  // @h18_505df0
    eax = ext_4cbec0_thiscall1((u32)(u8 *)loc);
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(505df0, lifted_505df0);

