// batch216060.cpp - Sonnet-w3c, hand-written ports (read from the disassembly).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
extern "C" u32 STDCALL ext_610100_s1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_4e1600_t1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e12f0_t3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e11e0_t3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e1b30_t1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4690b0_t1(u32) __asm__("ext_4690b0");
#define ext_4690b0_t0 ext_4690b0_t1
extern "C" u32 THISCALL ext_4cc1d0_t1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cbec0_t1(u32) __asm__("ext_4cbec0");
extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_4d5440_t1(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4cbeb0_t1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbee0_t2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc5f0_t1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cbe50_t2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_t2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cc2c0_t2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_5f2d60_t3(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 THISCALL ext_42b390_t3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 STDCALL ext_6014a0_s1(u32) __asm__("ext_6014a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 THISCALL ext_4cca60_t2(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4db7e0_t1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_6014a0_t2(u32, u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_4cbe80_t1(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cc2c0_t1(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cbec0_t0(u32) __asm__("ext_4cbec0");
extern "C" void ext_634047_v(void) __asm__("ext_634047");
extern "C" u32 THISCALL ext_4cc1d0_t0(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cbe50_t1(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbeb0_t0(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbf30_t1(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_5fb2c0_t1(u32, u32) __asm__("ext_5fb2c0");
extern "C" u32 THISCALL ext_5f10c0_t1(u32, u32) __asm__("ext_5f10c0");
extern "C" void FASTCALL ext_430480_f(u32 node, u32 root1) __asm__("ext_430480");
extern "C" u32 THISCALL ext_603110_t0(u32) __asm__("ext_603110");
extern "C" u32 THISCALL ext_602260_t1(u32, u32) __asm__("ext_602260");
extern "C" u32 THISCALL ext_6031e0_t1(u32, u32) __asm__("ext_6031e0");
extern "C" u32 THISCALL ext_602240_t0(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_604650_t0(u32) __asm__("ext_604650");
extern "C" u32 THISCALL ext_5fa5d0_t0(u32) __asm__("ext_5fa5d0");
extern "C" u32 THISCALL ext_603500_t1(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_4d2280_t0(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d3ab0_t2(u32, u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL ext_4d2330_t0(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4cbee0_t1(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc5f0_t0(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4de7a0_t0(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4cc000_tf(u32, float) __asm__("ext_4cc000");
extern "C" u32 THISCALL ext_43cf00_t1(u32, u32) __asm__("ext_43cf00");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" u32 THISCALL ext_4db2f0_t1(u32, u32) __asm__("ext_4db2f0");
extern "C" u32 THISCALL ext_4d2d30_t2(u32, u32, u32) __asm__("ext_4d2d30");
extern "C" u32 THISCALL ext_43e0f0_t0(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_456ab0_t0(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_4ccbe0_t2(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4cc630_t1(u32, u32) __asm__("ext_4cc630");
extern "C" u32 THISCALL ext_4ccdd0_t3(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4cd9b0_t2(u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 THISCALL ext_4e3e70_t1(u32, u32) __asm__("ext_4e3e70");
extern "C" float THISCALL ext_443080_f(u32, u32) __asm__("ext_443080");
extern "C" u32 THISCALL ext_4e4fc0_t1(u32, u32) __asm__("ext_4e4fc0");
extern "C" u32 THISCALL ext_4e4fe0_tf(u32, float) __asm__("ext_4e4fe0");
extern "C" u32 THISCALL ext_52e0a0_t3(u32, u32, u32, u32) __asm__("ext_52e0a0");
extern "C" u32 THISCALL ext_476dc0_t1(u32, u32) __asm__("ext_476dc0");
extern "C" u32 THISCALL ext_52d1c0_t8(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_52d1c0");
extern "C" u32 THISCALL ext_4da3a0_t0(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4d6520_t3(u32, u32, u32, u32) __asm__("ext_4d6520");
extern "C" u32 THISCALL ext_62f9d0_t4(u32, u32, u32, u32, u32) __asm__("ext_62f9d0");
extern "C" u32 THISCALL ext_5003d0_t1(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_5002f0_t1(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_4e5e60_t0(u32) __asm__("ext_4e5e60");
extern "C" float THISCALL ext_4e5e80_f(u32) __asm__("ext_4e5e80");
extern "C" u32 THISCALL ext_4e5ea0_t0(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6330_t1(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_4e6b30_t0(u32) __asm__("ext_4e6b30");
extern "C" u32 THISCALL ext_4e6c80_t4(u32, u32, u32, u32, u32) __asm__("ext_4e6c80");
extern "C" u32 THISCALL ext_4ccba0_t0(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4cdd40_t0(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4c8fe0_t0(u32) __asm__("ext_4c8fe0");
extern "C" u32 THISCALL ext_4ccf60_t0(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_603090_t0(u32) __asm__("ext_603090");
extern "C" u32 THISCALL ext_5fb660_t0(u32) __asm__("ext_5fb660");
extern "C" u32 THISCALL ext_606b80_t0(u32) __asm__("ext_606b80");
extern "C" u32 THISCALL ext_469870_t0(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4d8330_t3(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4e3d60_t1(u32, u32) __asm__("ext_4e3d60");
extern "C" u32 THISCALL ext_4e3e40_t1(u32, u32) __asm__("ext_4e3e40");
extern "C" u32 THISCALL ext_4e3340_t1(u32, u32) __asm__("ext_4e3340");
extern "C" u32 THISCALL ext_494b40_t1(u32, u32) __asm__("ext_494b40");
extern "C" u32 THISCALL ext_494ac0_t1(u32, u32) __asm__("ext_494ac0");
extern "C" u32 THISCALL ext_41e680_t0(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_4d3ab0_t2b(u32, u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL ext_4ccb40_t2(u32, u32, u32) __asm__("ext_4ccb40");
extern "C" u32 THISCALL ext_4cd6f0_t2(u32, u32, u32) __asm__("ext_4cd6f0");
extern "C" u32 THISCALL ext_4cf690_t0(u32) __asm__("ext_4cf690");
extern "C" u32 THISCALL ext_4ccef0_t0(u32) __asm__("ext_4ccef0");
extern "C" u32 FASTCALL ext_43e920_f(u32 out, u32 b, u32 a) __asm__("ext_43e920");
extern "C" double VECTORCALL ext_634d7c_vc(double) __asm__("ext_634d7c");
extern "C" u32 THISCALL ext_4ccd10_t2(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 STDCALL ext_45e420_s1(u32) __asm__("ext_45e420");
extern "C" u32 THISCALL ext_48db70_t0(u32) __asm__("ext_48db70");
extern "C" u32 THISCALL ext_4cd0e0_t0(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_473370_t1(u32, u32) __asm__("ext_473370");
extern "C" u32 THISCALL ext_4e11d0_t2(u32, u32, u32) __asm__("ext_4e11d0");
extern "C" u32 THISCALL ext_4e11e0_t2(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_t2(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e0fd0_t1(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e1b30_t0(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_448a30_t1(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_4e12f0_t2(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_5c7570_t1(u32, u32) __asm__("ext_5c7570");
extern "C" u32 FASTCALL ext_441970_f(u32 out, u32 src, u32 m) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_441940_f(u32 a, u32 b) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_f(u32 a, u32 b) __asm__("ext_4419f0");
extern "C" float FASTCALL ext_4e0870_f(u32 a, u32 b) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_4d3a00_t3(u32, u32, u32, u32) __asm__("ext_4d3a00");
extern "C" u32 THISCALL ext_4d39a0_t2(u32, u32, u32) __asm__("ext_4d39a0");
extern "C" u32 THISCALL ext_4d3ad0_t3(u32, u32, u32, u32) __asm__("ext_4d3ad0");
extern "C" u32 THISCALL ext_42b390_t2(u32, u32, u32) __asm__("ext_42b390");
extern "C" void ext_41e2c0_c1(u32) __asm__("ext_41e2c0");
extern "C" u32 THISCALL ext_46a4f0_t0(u32) __asm__("ext_46a4f0");
extern "C" u32 THISCALL ext_43eb80_t1(u32, u32) __asm__("ext_43eb80");
extern "C" u32 THISCALL ext_4b5620_t1(u32, u32) __asm__("ext_4b5620");
extern "C" u32 THISCALL ext_4999c0_t1(u32, u32) __asm__("ext_4999c0");
extern "C" u32 THISCALL ext_499970_t0(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_54f870_t2(u32, u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_4d2030_t1(u32, u32) __asm__("ext_4d2030");
extern "C" u32 THISCALL ext_6352f0_t1(u32, u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_4c4740_t3(u32, u32, u32, u32) __asm__("ext_4c4740");
extern "C" u32 THISCALL ext_4cbeb0_t0b(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_44a1f0_t0(u32) __asm__("ext_44a1f0");
extern "C" u32 THISCALL ext_4e3180_t0(u32) __asm__("ext_4e3180");
extern "C" u32 THISCALL ext_4e49d0_t1(u32, u32) __asm__("ext_4e49d0");
extern "C" u32 THISCALL ext_4da720_t1(u32, u32) __asm__("ext_4da720");
extern "C" u32 THISCALL ext_4d9ce0_t0(u32) __asm__("ext_4d9ce0");
extern "C" u32 THISCALL ext_499880_t2(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_49a790_t2(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b340_t2(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_49b2e0_t1(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_492200_t1(u32, u32) __asm__("ext_492200");
extern "C" u32 THISCALL ext_492880_t1(u32, u32) __asm__("ext_492880");
extern "C" u32 THISCALL ext_499970_t0b(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_4cc930_t3(u32, u32, u32) __asm__("ext_4cc930");
extern "C" u32 THISCALL ext_441e40_t2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_5003d0_t2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_5002f0_t2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_506040_t1(u32) __asm__("ext_506040");
extern "C" u32 THISCALL ext_41e680_t1(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_4d2280_t1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d3ad0_t4(u32, u32, u32, u32) __asm__("ext_4d3ad0");
extern "C" u32 THISCALL ext_4d2ed0_t2(u32, u32) __asm__("ext_4d2ed0");
extern "C" u32 THISCALL ext_4d2330_t1(u32) __asm__("ext_4d2330");

extern "C" u32 THISCALL lifted_448a30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66600b);  // @h_448a30
  u8 loc[0x80] __attribute__((aligned(16)));
  volatile u32 w[16];
  for (int i = 0; i < 16; i++) w[i] = 0;
  u32 esi = ecx_in, ebx = a0, eax;
  ext_610100_s1(ebx);  // @h1_448a30
  eax = ext_4e1600_t1(ebx);  // @h2_448a30
  if ((eax & 0xff) == 1) {  // @h3_448a30
    u32 obj = ((u32(THISCALL *)(u32))VSLOT(esi, 0x20))(esi);  // @h4_448a30
    u32 lg = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x67f54c, 0x7f);  // @h5_448a30
    u32 sv = ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1d8))(obj, (u32)(u8 *)loc, 1);  // @h6_448a30
    reg.state = 0;
    u32 str = ext_4cc1d0_t1(sv);
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x30))(L, 0x67f574, str);  // @h7_448a30
    reg.state = -1;
    ext_4cbec0_t1((u32)(u8 *)loc);
    ext_4e12f0_t3(ebx, (u32)(u32 *)&w[1], 1);  // @h8_448a30
    ext_4e12f0_t3(ebx, (u32)(u32 *)&w[2], 1);  // @h9_448a30
    eax = ext_4e1600_t1(ebx);  // @h10_448a30
    if ((eax & 0xff) == 3) {  // @h11_448a30
      ext_4e11e0_t3(ebx, (u32)(u32 *)&w[3], 1);  // @h12_448a30
      ext_4e12f0_t3(ebx, (u32)(u32 *)&w[4], 1);  // @h13_448a30
    } else {
      ext_4e12f0_t3(ebx, (u32)(u32 *)&w[4], 1);  // @h14_448a30
      ext_4e11e0_t3(ebx, (u32)(u32 *)&w[5], 1);  // @h15_448a30
      ext_4e11e0_t3(ebx, (u32)(u32 *)&w[6], 1);  // @h16_448a30
      ext_4e11e0_t3(ebx, (u32)(u32 *)&w[7], 1);  // @h17_448a30
    }
    esi = ecx_in;
  }
  ext_4e11e0_t3(ebx, (u32)(u32 *)&w[8], 1);  // @h18_448a30
  ext_4e11e0_t3(ebx, (u32)(u32 *)&w[9], 1);  // @h19_448a30
  ext_4e11e0_t3(ebx, (u32)(u32 *)&w[0], 1);  // @h20_448a30
  ext_4e1b30_t1(ebx);  // @h21_448a30
  *(u32 *)(esi + 0x18) &= 0xfffffffb;  // @h22_448a30
  if (w[0] != 0) *(u32 *)(esi + 0x18) |= 4;  // @h23_448a30
  eax = ext_4690b0_t1(*(u32 *)(esi + 8));  // @h24_448a30
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(448a30, lifted_448a30);

extern "C" u32 THISCALL lifted_50c900(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669e8b);  // @h_50c900
  u8 sb[0x4000] __attribute__((aligned(16)));
  volatile u32 w = 0;
  u32 ebx = a0, eax;
  ext_5003d0_t2(*(u32 *)(ebx + 8), 0);  // @h1_50c900
  u32 p1 = ext_5003d0_t2(*(u32 *)(ebx + 4), 1);  // @h2_50c900
  u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 x = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, *(u32 *)p1);  // @h3_50c900
  if (x == 0) {  // @h4_50c900
    u32 lg = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x69d420, 0x404);  // @h5_50c900
    eax = ((u32(*)(u32, u32))VSLOT(L, 0x2c))(L, 0x69d900);  // @h6_50c900
  } else {
    tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    u32 R = ((u32(THISCALL *)(u32))VSLOT(tbl, 0x138))(tbl);  // @h7_50c900
    w = 0;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(R, 0x88))(R, 0x690ad0, (u32)(u32 *)&w);  // @h8_50c900
    tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    u32 y = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, w);  // @h9_50c900
    if (y == 0) {  // @h10_50c900
      u32 lg = G(u32, 0x700390);
      u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x69d420, 0x40b);  // @h11_50c900
      eax = ((u32(*)(u32, u32))VSLOT(L, 0x2c))(L, 0x69d94c);  // @h12_50c900
    } else {
      u32 p2 = ext_5003d0_t2(*(u32 *)(ebx + 4), 2);  // @h13_50c900
      u32 s2 = ext_506040_t1(p2);
      u32 z = ((u32(THISCALL *)(u32, u32, u32))VSLOT(y, 0x25c))(y, s2, 0);  // @h14_50c900
      if (z == 0) {  // @h15_50c900
        u32 lg = G(u32, 0x700390);
        u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x69d420, 0x411);  // @h16_50c900
        u32 p3 = ext_5003d0_t2(*(u32 *)(ebx + 4), 2);  // @h17_50c900
        u32 s3 = ext_506040_t1(p3);
        eax = ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x69d974, s3);  // @h18_50c900
      } else {
        ext_4d2280_t1((u32)sb);
        reg.state = 0;
        u32 p4 = ext_5003d0_t2(*(u32 *)(ebx + 4), 0);  // @h19_50c900
        ext_4d3ad0_t4((u32)sb, 0x69d9a4, *(u32 *)p4, 0x10);  // @h20_50c900
        u32 r41 = ext_41e680_t1(z);
        ext_4d3ad0_t4((u32)sb, 0x69d9b4, r41, 0x10);  // @h21_50c900
        tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
        u32 hv = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(tbl, 0x114))(tbl, 0x69d9c8, 0, 0x69d420, 0x418, (u32)sb) & 0xffff;  // @h22_50c900
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(x, 0x130))(x, x, hv);  // @h23_50c900
        u32 e2 = ext_4d2ed0_t2((u32)sb, 0x688a30);  // @h24_50c900
        u32 p5 = ext_5003d0_t2(*(u32 *)(ebx + 8), 0);  // @h25_50c900
        eax = ext_5002f0_t2(p5, e2);  // @h26_50c900
        eax = ext_4d2330_t1((u32)sb);
      }
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(50c900, lifted_50c900);

extern "C" u32 THISCALL lifted_600c70(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d86e);  // @h_600c70
  volatile u32 A0 = a0;
  u32 ebx = ecx_in, edi;
  edi = ext_41e290_cdecl1((u32)0x18);  // @h1_600c70
  reg.state = 0;
  if (edi) {  // @h2_600c70
    u32 s = edi + 0xc;
    *(u32 *)s = 0; *(u32 *)(s + 4) = 0; *(u32 *)(s + 8) = 0;
    u32 p = ext_6014a0_s1(8);  // @h3_600c70
    *(u32 *)s = p;
    *(u32 *)(s + 4) = p;
    *(u32 *)(s + 8) = p + 8;  // @h4_600c70
    if (p) *(u8 *)p = 0;
    *(u8 *)p = 0;
  } else edi = 0;
  u32 esi = a0;
  *(u32 *)ebx = edi;
  reg.state = -1;
  u32 len = 0;
  while (*(u8 *)(esi + len)) len++;  // @h5_600c70
  ext_5f2d60_t3(edi + 0xc, esi, esi + len);  // @h6_600c70
  u32 o = *(u32 *)ebx;
  *(u32 *)o = 2;  // @h7_600c70
  u32 o2 = ext_41e290_cdecl1((u32)0xc);  // @h8_600c70
  reg.state = 1;
  u32 ecx;
  if (o2) ecx = ext_42b390_t3(o2, a1, (u32)((volatile u8 *)&A0 + 3));  // @h9_600c70
  else ecx = 0;
  *(u32 *)(*(u32 *)ebx + 4) = ecx;  // @h10_600c70
  SEH_LEAVE();
  return ebx;
}
PCREG(600c70, lifted_600c70);

extern "C" u32 THISCALL lifted_600e40(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66dc9f);  // @h_600e40
  volatile u32 A0 = a0;
  u32 ebx = ecx_in, edi;
  edi = ext_41e290_cdecl1((u32)0x18);  // @h1_600e40
  reg.state = 0;
  if (edi) {  // @h2_600e40
    u32 s = edi + 0xc;
    *(u32 *)s = 0; *(u32 *)(s + 4) = 0; *(u32 *)(s + 8) = 0;
    u32 p = ext_6014a0_s1(8);  // @h3_600e40
    *(u32 *)s = p;
    *(u32 *)(s + 4) = p;
    *(u32 *)(s + 8) = p + 8;  // @h4_600e40
    if (p) *(u8 *)p = 0;
    *(u8 *)p = 0;
  } else edi = 0;
  u32 esi = a0;
  *(u32 *)ebx = edi;
  reg.state = -1;
  u32 len = 0;
  while (*(u8 *)(esi + len)) len++;  // @h5_600e40
  ext_5f2d60_t3(edi + 0xc, esi, esi + len);  // @h6_600e40
  u32 o = *(u32 *)ebx;
  *(u32 *)o = 1;  // @h7_600e40
  *(u32 *)(*(u32 *)ebx + 4) = a1;  // @h8_600e40
  SEH_LEAVE();
  return ebx;
}
PCREG(600e40, lifted_600e40);

extern "C" u32 THISCALL lifted_600f20(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d86e);  // @h_600f20
  volatile u32 A0 = a0;
  u32 ebx = ecx_in, edi;
  edi = ext_41e290_cdecl1((u32)0x18);  // @h1_600f20
  reg.state = 0;
  if (edi) {  // @h2_600f20
    u32 s = edi + 0xc;
    *(u32 *)s = 0; *(u32 *)(s + 4) = 0; *(u32 *)(s + 8) = 0;
    u32 p = ext_6014a0_s1(8);  // @h3_600f20
    *(u32 *)s = p;
    *(u32 *)(s + 4) = p;
    *(u32 *)(s + 8) = p + 8;  // @h4_600f20
    if (p) *(u8 *)p = 0;
    *(u8 *)p = 0;
  } else edi = 0;
  u32 esi = a0;
  *(u32 *)ebx = edi;
  reg.state = -1;
  u32 len = 0;
  while (*(u8 *)(esi + len)) len++;  // @h5_600f20
  ext_5f2d60_t3(edi + 0xc, esi, esi + len);  // @h6_600f20
  u32 o = *(u32 *)ebx;
  *(u32 *)o = 3;  // @h7_600f20
  u32 o2 = ext_41e290_cdecl1((u32)0xc);  // @h8_600f20
  reg.state = 1;
  u32 ecx;
  if (o2) ecx = ext_42b390_t3(o2, a2, (u32)((volatile u8 *)&A0 + 3));  // @h9_600f20
  else ecx = 0;
  *(u32 *)(*(u32 *)ebx + 8) = ecx;  // @h10_600f20
  *(u32 *)(*(u32 *)ebx + 4) = a1;  // @h11_600f20
  SEH_LEAVE();
  return ebx;
}
PCREG(600f20, lifted_600f20);

extern "C" u32 THISCALL hand_42c380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d7c);  // @h_42c380
  u8 S90[0x80] __attribute__((aligned(16)));
  u8 S110[0x80] __attribute__((aligned(16)));
  u8 S190[0x80] __attribute__((aligned(16)));
  u32 esi = ecx_in, edi = a0, eax;
  ext_4cbeb0_t1((u32)S90);
  reg.state = 0;
  eax = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x11c))(esi, (u32)S190);  // @h1_42c380
  reg.state = 1;
  ext_4cbee0_t2((u32)S90, eax);  // @h2_42c380
  reg.state = 0;
  ext_4cbec0_t1((u32)S190);  // @h3_42c380
  eax = ext_4cc5f0_t1((u32)S90);  // @h4_42c380
  if (eax == 0) {  // @h5_42c380
    ext_4cbe50_t2(edi, (u32)S90);  // @h6_42c380
  } else {
    ext_4cbeb0_t1((u32)S110);
    reg.state = 2;
    ext_4cbe80_t2((u32)S190, 0x679a34);  // @h7_42c380
    reg.state = 3;
    ext_4cbee0_t2((u32)S110, (u32)S190);  // @h8_42c380
    reg.state = 2;
    ext_4cbec0_t1((u32)S190);  // @h9_42c380
    ext_4cc2c0_t2((u32)S110, (u32)S90);  // @h10_42c380
    ext_4cbe50_t2(edi, (u32)S110);  // @h11_42c380
    ext_4cbec0_t1((u32)S110);  // @h12_42c380
  }
  eax = ext_4cbec0_t1((u32)S90);
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return edi;
}
PCREG(42c380, hand_42c380);

extern "C" u32 THISCALL hand_434bf0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6657bf);  // @h_434bf0
  u32 self = ecx_in, ebx;
  u32 obj = ext_41e290_cdecl1((u32)0x6f);  // @h1_434bf0
  reg.state = 0;
  if (obj) ebx = ext_4d5440_t1(obj);  // @h2_434bf0
  else ebx = 0;
  reg.state = -1;
  u32 len = 0;
  while (*(u8 *)(a0 + len)) len++;  // @h3_434bf0
  u32 buf = ext_41e290_cdecl1((u32)(len + 1));  // @h4_434bf0
  u32 i = 0;
  for (;;) { u8 ch = *(u8 *)(a0 + i); *(u8 *)(buf + i) = ch; i++; if (!ch) break; }  // @h5_434bf0
  u32 (*f)(u32, u32) = *(u32 (**)(u32, u32))0x676258;
  u32 p = f(buf, 0x5c);  // @h6_434bf0
  if (p == 0) p = f(buf, 0x2f);  // @h7_434bf0
  if (p != 0) {  // @h8_434bf0
    *(u8 *)p = 0;
    ((u32(THISCALL *)(u32, u32))VSLOT(self, 0x50))(self, buf);  // @h9_434bf0
  }
  ext_634273_cdecl2(buf, 1);  // @h10_434bf0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x34))(ebx, a0, 1);  // @h11_434bf0
  SEH_LEAVE();
  return ebx;
}
PCREG(434bf0, hand_434bf0);

extern "C" u32 THISCALL hand_441e40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665e4f);  // @h_441e40
  u32 esi = ecx_in;
  if (*(u32 *)(esi + 0x7b) == 0) {  // @h1_441e40
    u32 mgr = G(u32, 0x6ff968);
    if (mgr == 0) {  // @h2_441e40
      u32 o = ext_41e290_cdecl1((u32)0x28);  // @h3_441e40
      reg.state = 0;
      if (o) mgr = ext_4cca60_t2(o, 1, 0x120);  // @h4_441e40
      else mgr = 0;
      reg.state = -1;
      G(u32, 0x6ff968) = mgr;
    }
    u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 4))(mgr, 0) - 4;  // @h5_441e40
    *(u32 *)(esi + 0x7b) = r;
    ext_634d10_cdecl3(r, 0, 0x484);  // @h6_441e40
  }
  u32 buf = *(u32 *)(esi + 0x7b);
  *(u32 *)(buf + (u32)*(u16 *)(buf + 2) * 4 + 0x404) = a0;  // @h7_441e40
  (*(u16 *)(*(u32 *)(esi + 0x7b) + 2))++;  // @h8_441e40
  u32 eax = ((u32(THISCALL *)(u32))VSLOT(esi, 0x310))(esi);  // @h9_441e40
  if ((u8)eax == 0) {
    eax = ((u32(THISCALL *)(u32))VSLOT(esi, 0x30c))(esi);  // @h10_441e40
    if ((u8)eax == 0) {
      eax = ((u32(THISCALL *)(u32))VSLOT(esi, 0x20))(esi);  // @h11_441e40
      if (eax != 0) {
        u32 t = ((u32(THISCALL *)(u32))VSLOT(esi, 0x20))(esi);  // @h12_441e40
        eax = ext_4db7e0_t1(*(u32 *)(t + 8));  // @h13_441e40
        if (eax) eax = hand_441e40(eax, a0);  // @h14_441e40
      }
    }
  }
  SEH_LEAVE();
  return eax;
}
PCREG(441e40, hand_441e40);

extern "C" u32 THISCALL hand_41e4b0(u32 ecx_in) {
  SEH_ENTER(0x663faf);  // @h_41e4b0
  u32 esi = ecx_in;
  ((u32(THISCALL *)(u32))VSLOT(esi, 0x44))(esi);  // @h1_41e4b0
  u32 mgr = G(u32, 0x70038c);
  u32 o;
  if (mgr) o = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 8))(mgr, 0x19);  // @h2_41e4b0
  else o = ((u32(*)(u32))G(u32, 0x6762f0))(0x19);  // @h3_41e4b0
  reg.state = 0;
  u32 c = 0;
  if (o) c = ext_4cc930_t3(o, 0x12, 0x40000);  // @h4_41e4b0
  *(u32 *)(esi + 4) = c;
  *(u32 *)(esi + 0x24) = *(u32 *)(c + 4);  // @h5_41e4b0
  u32 n = *(u32 *)(c + 0x10) + 1;
  reg.state = -1;
  u64 prod = (u64)n * 4;  // @h6_41e4b0
  u32 sz = (u32)prod | ((prod >> 32) ? 0xffffffffu : 0u);
  mgr = G(u32, 0x70038c);
  u32 r;
  if (mgr) r = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 8))(mgr, sz);  // @h7_41e4b0
  else r = ((u32(*)(u32))G(u32, 0x6762f0))(sz & 0x1fffffff);  // @h8_41e4b0
  *(u32 *)(esi + 0x28) = r;
  u32 n2 = *(u32 *)(*(u32 *)(esi + 4) + 0x10) + 1;
  u32 ret = ext_634d10_cdecl3(r, 0, n2);  // @h9_41e4b0
  SEH_LEAVE();
  return ret;
}
PCREG(41e4b0, hand_41e4b0);

extern "C" u32 THISCALL hand_42b2e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6649d8);  // @h_42b2e0
  u32 edi = ecx_in;
  *(u32 *)(edi) = 0;
  *(u32 *)(edi + 4) = 0;
  *(u32 *)(edi + 8) = 0;
  u32 ebx = a1 - a0;
  reg.state = 0;
  u32 esi = ebx + 1;
  if (esi <= 0xfffffffeu) {  // @h1_42b2e0
    u32 eax;
    if (esi == 0) eax = 0;  // @h2_42b2e0
    else eax = ext_6014a0_t2(edi, esi);  // @h3_42b2e0
    *(u32 *)(edi) = eax;
    *(u32 *)(edi + 4) = eax;
    *(u32 *)(edi + 8) = eax + esi;  // @h4_42b2e0
  }
  esi = *(u32 *)(edi);
  ((u32(*)(u32, u32, u32))G(u32, 0x676278))(esi, a0, ebx);  // @h5_42b2e0
  esi -= a0;
  u32 eax = a1 + esi;  // @h6_42b2e0
  *(u32 *)(edi + 4) = eax;
  *(u8 *)eax = 0;
  SEH_LEAVE();
  return edi;
}
PCREG(42b2e0, hand_42b2e0);

extern "C" u32 THISCALL hand_42db40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664f46);  // @h_42db40
  u8 b210[0x200] __attribute__((aligned(16)));
  u8 b410[0x200] __attribute__((aligned(16)));
  u8 b610[0x200] __attribute__((aligned(16)));
  u8 o690[0x80] __attribute__((aligned(16)));
  u8 o710[0x80] __attribute__((aligned(16)));
  u32 ebx = ecx_in;
  u8 *esi = (u8 *)a0;
  if (*esi != 0) {  // @h1_42db40
    do {
      while (*esi == 0xd || *esi == 0xa) esi++;  // @h2_42db40
      u32 cnt = 0;
      if (*esi != 0) {
        for (;;) {
          u8 al = *esi;
          if (al == 0xd || al == 0xa) break;  // @h3_42db40
          b210[cnt] = al;
          cnt++;
          esi++;
          if (*esi == 0) break;
        }
        if (cnt >= 0x200) ext_634047_v();  // @h4_42db40
      }
      b210[cnt] = 0;
      u32 len = 0;
      while (b210[len]) len++;
      if ((s32)len > 0) {  // @h5_42db40
        u8 *p = b210 + len - 1;
        if (p != b210) {  // @h6_42db40
          do {
            u8 cl = *p;
            if (cl != 0x20 && cl != 9 && cl != 0xd && cl != 0xa) break;  // @h7_42db40
            *p = 0;
            p--;
          } while (p != b210);
        }
      }
      if (b210[0] != 0x2f && b210[1] != 0x2f) {  // @h8_42db40
        ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ebx, 0x68))(ebx, (u32)b210, (u32)b610, (u32)b410);  // @h9_42db40
        u32 r = ((u32(*)(u32, u32))G(u32, 0x676414))((u32)b610, 0x679e7c);  // @h10_42db40
        if (r == 0) {  // @h11_42db40
          ext_4cbe80_t1((u32)o690, (u32)b410);  // @h12_42db40
          reg.state = 0;
          ext_4cc2c0_t1(ebx + 0x1ab7, (u32)o690);  // @h13_42db40
          reg.state = -1;
          ext_4cbec0_t0((u32)o690);  // @h14_42db40
          ext_4cbe80_t1((u32)o710, 0x676c04);  // @h15_42db40
          reg.state = 1;
          ext_4cc2c0_t1(ebx + 0x1ab7, (u32)o710);  // @h16_42db40
          reg.state = -1;
          ext_4cbec0_t0((u32)o710);  // @h17_42db40
        }
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x60))(ebx, (u32)b610, (u32)b410);  // @h18_42db40
      }
    } while (*esi != 0);
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 1;
}
PCREG(42db40, hand_42db40);

extern "C" u32 THISCALL hand_432270(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6686a6);  // @h_432270
  u8 s110[0x80] __attribute__((aligned(16)));
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 self = ecx_in;
  u32 mgr = G(u32, 0x700390);
  u32 lg = ((u32(THISCALL *)(u32, u32, u32))VSLOT(mgr, 0x20))(mgr, 0x679f78, 0x441);  // @h1_432270
  u32 cs = ext_4cc1d0_t0(a0);  // @h2_432270
  ((u32(*)(u32, u32, u32))VSLOT(lg, 0x2c))(lg, 0x67a1e8, cs);  // @h3_432270
  ext_4cbe50_t1((u32)s110, a0);  // @h4_432270
  reg.state = 0;
  u8 *esi = (u8 *)ext_4cc1d0_t0((u32)s110);  // @h5_432270
  u32 ret = 0;
  if (*esi != 0) {  // @h6_432270
    do {
      u8 *edi = 0;
      u8 *ebx = esi;
      if (*esi != 0x3b) {  // @h7_432270
        for (;;) {
          u8 al = *esi;
          if (al == 0) {  // @h8_432270
            u32 m2 = G(u32, 0x700390);
            u32 l2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m2, 0x20))(m2, 0x679f78, 0x448);  // @h9_432270
            ((u32(*)(u32, u32))VSLOT(l2, 0x2c))(l2, 0x67a210);  // @h10_432270
            break;
          }
          if (al == 0x3d) {  // @h11_432270
            *esi = 0;
            edi = esi + 1;
          }
          esi++;
          if (*esi == 0x3b) break;  // @h12_432270
        }
      }
      *esi = 0;
      esi++;
      if (*(u32 *)ebx == 0x43727473) {  // @h13_432270
        if (ebx[4] == 0x43 && edi != 0) {  // @h14_432270
          u32 v = ((u32(*)(u32))G(u32, 0x6762d8))((u32)edi);  // @h15_432270
          ebx += 5;
          ext_4cbeb0_t0((u32)s90);  // @h16_432270
          reg.state = 1;
          ext_4cbf30_t1((u32)s90, v);  // @h17_432270
          u32 c1 = ext_4cc1d0_t0((u32)s90);  // @h18_432270
          ((u32(THISCALL *)(u32, u32, u32))VSLOT(self, 0x68))(self, (u32)ebx, c1);  // @h19_432270
          u32 g = G(u32, 0x70039c);
          u32 c2 = ext_4cc1d0_t0((u32)s90);  // @h20_432270
          ((u32(THISCALL *)(u32, u32, u32))VSLOT(g, 0x60))(g, (u32)ebx, c2);  // @h21_432270
          reg.state = 0;
          ext_4cbec0_t0((u32)s90);  // @h22_432270
        } else if (ebx[4] == 0x72) {  // @h23_432270
          ((u32(THISCALL *)(u32, u32))VSLOT(self, 0x6c))(self, (u32)(ebx + 5));  // @h24_432270
        }
      }
    } while (*esi != 0);
  }
  ret = ext_4cbec0_t0((u32)s110);  // @h25_432270
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(432270, hand_432270);

extern "C" u32 THISCALL hand_5fb400(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66d471);  // @h_5fb400
  u32 edi = ecx_in;
  u32 ebx = a2;
  u32 esi;
  bool create = true;
  if (ebx != *(u32 *)edi && a1 == 0) {  // @h1_5fb400
    u32 klen = *(u32 *)(a3 + 4) - *(u32 *)a3;  // @h2_5fb400
    s32 nlen = (s32)(*(u32 *)(ebx + 0x11) - *(u32 *)(ebx + 0xd));  // @h3_5fb400
    s32 L = (s32)klen;
    s32 n = (nlen >= L) ? L : nlen;  // @h4_5fb400
    s32 r = (s32)((u32(*)(u32, u32, u32))G(u32, 0x676408))(*(u32 *)a3, *(u32 *)(ebx + 0xd), (u32)n);  // @h5_5fb400
    bool neg;
    if (r == 0) neg = L < nlen;  // @h6_5fb400
    else neg = r < 0;  // @h7_5fb400
    create = neg;
  }
  if (!create) {
    esi = ext_5fb2c0_t1(edi, a3);  // @h8_5fb400
    *(u32 *)(ebx + 9) = esi;
    u32 eax = *(u32 *)edi;
    if (ebx == *(u32 *)(eax + 9)) *(u32 *)(eax + 9) = esi;  // @h9_5fb400
  } else {
    esi = ext_6014a0_t2(edi, 0x1d);  // @h10_5fb400
    u32 np = esi + 0xd;
    reg.state = 0;
    if (np) {  // @h11_5fb400
      ext_5f10c0_t1(np, a3);  // @h12_5fb400
      *(u32 *)(esi + 0x19) = *(u32 *)(a3 + 0xc);  // @h13_5fb400
    }
    *(u32 *)(ebx + 5) = esi;  // @h14_5fb400
    u32 eax = *(u32 *)edi;
    if (ebx == eax) {  // @h15_5fb400
      *(u32 *)(eax + 1) = esi;
      eax = *(u32 *)edi;
      *(u32 *)(eax + 9) = esi;  // @h16_5fb400
    } else if (ebx == *(u32 *)(eax + 5)) {  // @h17_5fb400
      *(u32 *)(eax + 5) = esi;
    }
  }
  *(u32 *)(esi + 1) = ebx;  // @h18_5fb400
  *(u32 *)(esi + 5) = 0;
  *(u32 *)(esi + 9) = 0;
  ext_430480_f(esi, *(u32 *)edi + 1);  // @h19_5fb400
  *(u32 *)(edi + 4) += 1;  // @h20_5fb400
  *(u32 *)a0 = esi;
  SEH_LEAVE();
  return a0;
}
PCREG(5fb400, hand_5fb400);

extern "C" u32 STDCALL hand_4d4a40(u32 a0) {
  SEH_ENTER(0x66adf6);  // @h_4d4a40
  u32 esi = *(u32 *)a0;
  u32 edi = ((u32(*)(u32))G(u32, 0x6763f4))(esi);  // @h1_4d4a40
  reg.state = 0;
  u32 r = ((u32(*)(u32))G(u32, 0x6763d8))(esi);  // @h2_4d4a40
  if (r != 0) {  // @h3_4d4a40
    u32 cb = G(u32, 0x7003b0);
    if (cb) ((u32(*)(void))cb)();  // @h4_4d4a40
    else __builtin_trap();
  }
  SEH_LEAVE();
  return edi;
}
PCREG(4d4a40, hand_4d4a40);

extern "C" u32 STDCALL hand_4d4b20(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66adf6);  // @h_4d4b20
  u32 esi = *(u32 *)a2;
  u32 edi = ((u32(*)(u32, u32, u32, u32))G(u32, 0x6763f8))(a0, 1, a1, esi);  // @h1_4d4b20
  reg.state = 0;
  u32 r = ((u32(*)(u32))G(u32, 0x6763d8))(esi);  // @h2_4d4b20
  if (r != 0) {  // @h3_4d4b20
    u32 cb = G(u32, 0x7003b0);
    if (cb) ((u32(*)(void))cb)();  // @h4_4d4b20
    else __builtin_trap();
  }
  SEH_LEAVE();
  return edi;
}
PCREG(4d4b20, hand_4d4b20);

extern "C" u32 THISCALL hand_602bc0(u32 ecx_in) {
  SEH_ENTER(0x66dbd8);  // @h_602bc0
  volatile u32 L[8] __attribute__((aligned(16)));
  u32 esi = ecx_in;
  u32 r = ext_603110_t0(esi);  // @h1_602bc0
  L[0] = 0x6b8508;  // @h2_602bc0
  L[1] = 0;
  L[2] = 0;
  L[3] = 0;
  *(volatile u8 *)&L[5] = 0;  // @h3_602bc0
  reg.state = 0;
  ext_602260_t1((u32)L, r);  // @h4_602bc0
  ext_6031e0_t1(esi, (u32)L);  // @h5_602bc0
  *(u8 *)esi = 1;  // @h6_602bc0
  u32 ret = ext_602240_t0((u32)L);  // @h7_602bc0
  SEH_LEAVE();
  return ret;
}
PCREG(602bc0, hand_602bc0);

extern "C" u32 THISCALL hand_5f3050(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u32 o = ext_41e290_cdecl1((u32)0x12);  // @h1_5f3050
  reg.state = 0;
  u32 esi;
  if (o) esi = ext_604650_t0(o);  // @h2_5f3050
  else esi = 0;
  reg.state = -1;
  if (esi != 0 && a1 != 0)  // @h3_5f3050
    ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x30))(esi, a1);  // @h4_5f3050
  SEH_LEAVE();
  return esi;
}
PCREG(5f3050, hand_5f3050);

extern "C" u32 FASTCALL hand_42b160(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6649b1);  // @h_42b160
  u32 esi = ecx_in, ebx = edx_in, edi = a0;
  if (esi != ebx) {  // @h1_42b160
    do {
      reg.state = 0;
      if (edi) ext_5f10c0_t1(edi, esi);  // @h2_42b160
      esi += 0xc;  // @h3_42b160
      reg.state = -1;
      edi += 0xc;  // @h4_42b160
    } while (esi != ebx);
  }
  SEH_LEAVE();
  return edi;
}
PCREG(42b160, hand_42b160);

extern "C" u32 THISCALL hand_5a3dc0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5a3dc0
  u32 ebx = ecx_in;
  *(u32 *)ebx = 0x6af018;  // @h1_5a3dc0
  u32 esi = ebx + 0xe9;
  for (int i = 4; i != 0; i--) {  // @h2_5a3dc0
    u32 p = *(u32 *)esi;
    if (p) ((u32(THISCALL *)(u32, u32))VSLOT(p, 0))(p, 1);  // @h3_5a3dc0
    esi += 4;
  }
  *(u32 *)(ebx + 0x44) = 0;  // @h4_5a3dc0
  *(u32 *)(ebx + 0x30) = 0;  // @h5_5a3dc0
  *(u32 *)ebx = 0x686874;  // @h6_5a3dc0
  reg.state = 0;
  u32 g = G(u32, 0x70039c);
  u32 c = *(u32 *)(g + 0x9b);  // @h7_5a3dc0
  u32 ret = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x34))(c, ebx);  // @h8_5a3dc0
  SEH_LEAVE();
  return ret;
}
PCREG(5a3dc0, hand_5a3dc0);

extern "C" u32 THISCALL hand_600be0(u32 ecx_in) {
  SEH_ENTER(0x66d828);  // @h_600be0
  u32 edi = ecx_in;
  ext_5fa5d0_t0(edi);  // @h1_600be0
  *(u32 *)edi = 0x6b96fc;  // @h2_600be0
  reg.state = 0;
  *(u32 *)(edi + 8) = 0xa;  // @h3_600be0
  *(u32 *)(edi + 0xc) = 0;  // @h4_600be0
  *(u32 *)(edi + 4) = ext_41e290_cdecl1((u32)40);  // @h5_600be0
  *(u32 *)(edi + 0x10) = edi + 4;  // @h6_600be0
  *(u32 *)(edi + 0x14) = 0;  // @h7_600be0
  *(u8 *)(edi + 0x18) = 0;  // @h8_600be0
  SEH_LEAVE();
  return edi;
}
PCREG(600be0, hand_600be0);

extern "C" u32 THISCALL hand_601d80(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601d80
  u32 esi = ext_41e290_cdecl1((u32)0x2a);  // @h1_601d80
  reg.state = 0;
  if (esi) {  // @h2_601d80
    ext_603500_t1(esi, a2);  // @h3_601d80
    *(u32 *)esi = 0x6b97b4;  // @h4_601d80
    *(u32 *)(esi + 0x18) = esi + 0xc;  // @h5_601d80
    *(u32 *)(esi + 0x1c) = 0;  // @h6_601d80
    *(u32 *)(esi + 0x20) = 0;  // @h7_601d80
    *(u16 *)(esi + 0x24) = 0;  // @h8_601d80
    *(u32 *)(esi + 0x26) = a0;  // @h9_601d80
  } else {
    esi = 0;
  }
  reg.state = -1;
  ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x58))(esi, a1);  // @h10_601d80
  SEH_LEAVE();
  return esi;
}
PCREG(601d80, hand_601d80);

extern "C" u32 THISCALL hand_474e00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474e00
  u8 buf[0x40c8] __attribute__((aligned(16)));
  u32 edi = ecx_in;
  ext_4d2280_t0((u32)buf);  // @h1_474e00
  reg.state = 0;
  u32 g = G(u32, 0x70039c);
  u32 c = *(u32 *)(g + 0x9b);  // @h2_474e00
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, a0);  // @h3_474e00
  ext_4d3ab0_t2((u32)buf, 0x688a30, r);  // @h4_474e00
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(edi, 0x168))(edi, (u32)G(u16, 0x6ff9ac), (u32)buf);  // @h5_474e00
  u32 ret = ext_4d2330_t0((u32)buf);  // @h6_474e00
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(474e00, hand_474e00);

extern "C" u32 THISCALL hand_4352f0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4352f0
  u8 buf[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 esi = ecx_in;
  for (u32 i = 0; i < 0x80; i++) buf[i] = 0;  // @h1_4352f0
  u32 m = G(u32, 0x7003ac);
  ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(m, 0x6c))(m, (u32)buf, 0x67a5c8, 8);  // @h2_4352f0
  ext_4cbe80_t1((u32)s110, (u32)buf);  // @h3_4352f0
  reg.state = 0;
  ext_4cbee0_t1(esi + 0x8c, (u32)s110);  // @h4_4352f0
  u32 ret = ext_4cbec0_t0((u32)s110);  // @h5_4352f0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4352f0, hand_4352f0);

extern "C" u32 THISCALL hand_435630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435630
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 edi = ecx_in;
  ext_4cbe80_t1((u32)s90, a0);  // @h1_435630
  reg.state = 0;
  edi += 0xc;  // @h2_435630
  ext_4cbee0_t1(edi, (u32)s90);  // @h3_435630
  reg.state = -1;
  ext_4cbec0_t0((u32)s90);  // @h4_435630
  u32 m = G(u32, 0x7003ac);
  u32 esi = *(u32 *)m;
  u32 len = ext_4cc5f0_t0(edi);  // @h5_435630
  u32 cs = ext_4cc1d0_t0(edi);  // @h6_435630
  u32 ret = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 0x14)))(m, 0x67a5bc, 8, cs, len);  // @h7_435630
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(435630, hand_435630);

#define W32(p, off, v) (*(volatile u32 *)((p) + (off)) = (v))
extern "C" u32 THISCALL hand_5ebae0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cad3);  // @h_5ebae0
  u32 esi = ecx_in;
  W32(esi, 0, 0x6b80f4);  // @h1_5ebae0
  reg.state = 0;
  W32(esi, 0x62, 0);  // @h2_5ebae0
  W32(esi, 0x66, 0);
  W32(esi, 0x6a, 0);
  reg.state = 1;
  *(volatile u16 *)(esi + 0x34) = 0x100;  // @h3_5ebae0
  W32(esi, 0x3e, a0);  // @h4_5ebae0
  W32(esi, 0x5a, 0);
  W32(esi, 0x42, a0);  // @h5_5ebae0
  W32(esi, 0x36, 0);
  W32(esi, 0x5e, 0);
  u32 p = ext_41e290_cdecl1((u32)8);  // @h6_5ebae0
  W32(esi, 0x3a, p);  // @h7_5ebae0
  W32(esi, 0x4e, 0);
  W32(esi, 0x4a, 0);
  W32(esi, 0x46, 0);
  *(volatile u32 *)(p) = 0;  // @h8_5ebae0
  *(volatile u32 *)(p + 4) = 0;
  W32(esi, 0x6e, 0);
  W32(esi, 0x72, 0);
  *(volatile u8 *)(esi + 0xa6) = 1;  // @h9_5ebae0
  ext_4de7a0_t0(esi + 0x76);  // @h10_5ebae0
  W32(esi, 0xa2, 0);
  W32(esi, 0x9e, 0);  // @h11_5ebae0
  W32(esi, 0x9a, 0);
  SEH_LEAVE();
  return esi;
}
PCREG(5ebae0, hand_5ebae0);

extern "C" u32 THISCALL hand_4314c0(u32 ecx_in, u32 a0, float a1) {
  SEH_ENTER(0x664d1b);  // @h_4314c0
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 edi = ecx_in;
  ext_4cbeb0_t0((u32)s90);  // @h1_4314c0
  reg.state = 0;
  ext_4cc000_tf((u32)s90, a1);  // @h2_4314c0
  u32 cs = ext_4cc1d0_t0((u32)s90);  // @h3_4314c0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(edi, 0x68))(edi, a0, cs);  // @h4_4314c0
  u32 g = G(u32, 0x70039c);
  u32 cs2 = ext_4cc1d0_t0((u32)s90);  // @h5_4314c0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(g, 0x60))(g, a0, cs2);  // @h6_4314c0
  u32 ret = ext_4cbec0_t0((u32)s90);  // @h7_4314c0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4314c0, hand_4314c0);

extern "C" u32 THISCALL hand_435a10(u32 ecx_in) {
  SEH_ENTER(0x6658ca);  // @h_435a10
  u32 esi = ecx_in;
  W32(esi, 4, 2);  // @h1_435a10
  W32(esi, 8, 0);  // @h2_435a10
  *(volatile u8 *)(esi + 0xc) = 0;  // @h3_435a10
  W32(esi, 0, 0x67a65c);  // @h4_435a10
  W32(esi, 0xd, 0);
  W32(esi, 0x15, 0);
  W32(esi, 0x11, 0);
  W32(esi, 0x19, 0);  // @h5_435a10
  for (u32 off = 0x1d; off <= 0x4d; off += 0x10) {  // @h6_435a10
    W32(esi, off, 0);
    W32(esi, off + 4, 0);
    W32(esi, off + 8, 0);
    W32(esi, off + 12, 0);
  }
  reg.state = 0;
  u32 o = ext_41e290_cdecl1((u32)0x34a);  // @h7_435a10
  reg.state = 1;
  if (o) {  // @h8_435a10
    u32 r = ext_43cf00_t1(o, esi);  // @h9_435a10
    W32(esi, 0x65, r);  // @h10_435a10
  } else {
    W32(esi, 0x65, 0);  // @h11_435a10
  }
  SEH_LEAVE();
  return esi;
}
PCREG(435a10, hand_435a10);

extern "C" u32 THISCALL hand_4d16e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66930f);  // @h_4d16e0
  u32 ebx = ecx_in;
  u32 node = ext_41e290_cdecl1((u32)0x14);  // @h1_4d16e0
  reg.state = 0;
  u32 ret = node;
  if (node) {  // @h2_4d16e0
    u32 len = 0;
    while (*(u8 *)(a0 + len)) len++;
    len += 1;  // @h3_4d16e0
    u32 buf = ext_41e290_cdecl1(len);  // @h4_4d16e0
    *(u32 *)(node + 0xc) = buf;  // @h5_4d16e0
    ext_634d22_cdecl3(buf, a0, len);  // @h6_4d16e0
    *(u32 *)(node + 0x10) = len;  // @h7_4d16e0
    *(u32 *)node = ebx;  // @h8_4d16e0
    *(u32 *)(node + 4) = *(u32 *)(ebx + 0x1c);  // @h9_4d16e0
    *(u32 *)(node + 8) = 0;  // @h10_4d16e0
    u32 t = *(u32 *)(ebx + 0x1c);
    ret = t;
    if (t) *(u32 *)(t + 8) = node;  // @h11_4d16e0
    else *(u32 *)(ebx + 0x18) = node;  // @h12_4d16e0
    *(u32 *)(ebx + 0x1c) = node;  // @h13_4d16e0
  }
  SEH_LEAVE();
  return ret;
}
PCREG(4d16e0, hand_4d16e0);

extern "C" float THISCALL hand_4668d0(u32 ecx_in) {
  SEH_ENTER(0x666eeb);  // @h_4668d0
  u8 s[0x40c8] __attribute__((aligned(16)));
  u32 self = ecx_in;
  ext_4d2280_t0((u32)s);  // @h1_4668d0
  reg.state = 0;
  u32 obj = ext_4db2f0_t1(*(u32 *)(self + 8), 0);  // @h2_4668d0
  u32 g = G(u32, 0x70039c);
  u32 c = *(u32 *)(g + 0x9b);  // @h3_4668d0
  u32 r = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x685f58, 0, 0x685ee0, 0x249, (u32)s, 0);  // @h4_4668d0
  ((u32(THISCALL *)(u32, u32))VSLOT(obj, 0x128))(obj, r & 0xffff);  // @h5_4668d0
  volatile float f = 0;
  ext_4d2d30_t2((u32)s, 0x685f64, (u32)&f);  // @h6_4668d0
  float fv = f;
  ext_4d2330_t0((u32)s);  // @h7_4668d0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return fv;
}
PCREG(4668d0, hand_4668d0);

extern "C" u32 THISCALL hand_4558a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_4558a0
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 ebx = ecx_in;
  u32 eax = ext_43e0f0_t0(ebx);  // @h1_4558a0
  if (*(u32 *)(ebx + 0x49) == 0) {  // @h2_4558a0
    eax = *(u32 *)(ebx + 0x4d);
    if (eax != 0 && *(u8 *)eax != 0) {  // @h3_4558a0
      ext_4cbe80_t1((u32)s90, eax);  // @h4_4558a0
      reg.state = 0;
      u32 r = ext_456ab0_t0((u32)s90);  // @h5_4558a0
      *(u32 *)(ebx + 0x49) = r;
      reg.state = -1;
      eax = ext_4cbec0_t0((u32)s90);  // @h6_4558a0
      if (*(u32 *)(ebx + 0x49) == 0) {  // @h7_4558a0
        u32 m = G(u32, 0x700390);
        u32 edi = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x682d18, 0x142);  // @h8_4558a0
        u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x1d8))(ebx, (u32)s110, 1);  // @h9_4558a0
        u32 esi = *(u32 *)edi;
        reg.state = 1;
        u32 cs = ext_4cc1d0_t0(r1);  // @h10_4558a0
        ((u32(*)(u32, u32, u32, u32))(*(u32 *)(esi + 0x2c)))(edi, 0x682de0, *(u32 *)(ebx + 0x4d), cs);  // @h11_4558a0
        eax = ext_4cbec0_t0((u32)s110);  // @h12_4558a0
      }
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(4558a0, hand_4558a0);

extern "C" u32 THISCALL hand_4720f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_4720f0
  u32 esi = ecx_in;
  if (*(u32 *)(esi + 0x3b7) == 0) {  // @h1_4720f0
    u32 o = ext_41e290_cdecl1((u32)0x1c);  // @h2_4720f0
    reg.state = 0;
    u32 r = 0;
    if (o) r = ext_4ccbe0_t2(o, 4, 0);  // @h3_4720f0
    reg.state = -1;
    *(u32 *)(esi + 0x3b7) = r;  // @h4_4720f0
  }
  u32 g = G(u32, 0x70039c);
  u32 c = *(u32 *)(g + 0x9b);  // @h5_4720f0
  u32 ebx = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x58))(c, a0);  // @h6_4720f0
  u32 fl = *(u32 *)(*(u32 *)(ebx + 8) + 0x3c);  // @h7_4720f0
  u32 ret;
  if ((fl >> 10) & 1) {  // @h8_4720f0
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x68961c, 0x14e);  // @h9_4720f0
    u32 name = *(u32 *)(ebx + 4);  // @h10_4720f0
    if (name == 0) name = 0x67c8e8;  // @h11_4720f0
    ret = ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x68977c, name);  // @h12_4720f0
  } else {
    u32 o2 = *(u32 *)(esi + 0x3b7);
    ret = ((u32(THISCALL *)(u32, u32))VSLOT(o2, 4))(o2, a0);  // @h13_4720f0
  }
  SEH_LEAVE();
  return ret;
}
PCREG(4720f0, hand_4720f0);

extern "C" u32 THISCALL hand_4cc000(u32 ecx_in, float a0) {
  SEH_ENTER(0x66921b);  // @h_4cc000
  u8 b410[0x400] __attribute__((aligned(16)));
  u8 s490[0x88] __attribute__((aligned(16)));
  u32 esi = ecx_in;
  volatile double d = (double)a0;  // @h1_4cc000
  u32 isn = ((u32(*)(double))G(u32, 0x676328))(d);  // @h2_4cc000
  if (isn != 0) {  // @h3_4cc000
    *(volatile u32 *)b410 = 0x4e414e;  // @h4_4cc000
  } else {
    u32 g = G(u32, 0x70039c);
    u32 X = ((u32(THISCALL *)(u32))VSLOT(g, 0x190))(g);  // @h5_4cc000
    double dd = d;
    ((u32(*)(u32, u32, u32, double))VSLOT(X, 0x198))(X, 0x7003d0, 0x6792bc, dd);  // @h6_4cc000
    ((u32(*)(u32, u32, u32))G(u32, 0x67642c))((u32)b410, 0x7003d0, 0x7f);  // @h7_4cc000
  }
  ext_4cc630_t1((u32)s490, (u32)b410);  // @h8_4cc000
  reg.state = 0;
  if (esi != (u32)s490) {  // @h9_4cc000
    u32 e = *(u32 *)esi;
    if (e != esi + 4) ext_634273_cdecl2(e, 1);  // @h10_4cc000
    ext_4cc630_t1(esi, *(u32 *)s490);  // @h11_4cc000
  }
  u32 e2 = *(u32 *)s490;
  if (e2 != (u32)s490 + 4) ext_634273_cdecl2(e2, 1);  // @h12_4cc000
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return esi;
}
PCREG(4cc000, hand_4cc000);

extern "C" u32 THISCALL hand_42bf90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664c7f);  // @h_42bf90
  u32 esi = ecx_in;
  if (*(u32 *)(esi + 0x1b55) == 0) {  // @h1_42bf90
    u32 b = ext_41e290_cdecl1((u32)0xa000);  // @h2_42bf90
    *(u32 *)(esi + 0x1b55) = b;
    ext_634d10_cdecl3(b, 0, 0xa000);  // @h3_42bf90
    u32 o = ext_41e290_cdecl1((u32)0x10);  // @h4_42bf90
    reg.state = 0;
    u32 r = 0;
    if (o) r = ext_4ccdd0_t3(o, 0, 0xa000, 0x800);  // @h5_42bf90
    reg.state = -1;
    *(u32 *)(esi + 0x1b51) = r;  // @h6_42bf90
  }
  u32 edi = (a0 + 4) & 0xfffe;  // @h7_42bf90
  u32 ebx = edi & 0xffff;
  u32 p = *(u32 *)(esi + 0x1b51);
  s32 res = (s32)ext_4cd9b0_t2(p, ebx, 1);  // @h8_42bf90
  if (res < 0) {  // @h9_42bf90
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6799ac, 0x120);  // @h10_42bf90
    ((u32(*)(u32, u32))VSLOT(L, 0x2c))(L, 0x6799d8);  // @h11_42bf90
    u32 cb = G(u32, 0x7003b0);
    if (cb) ((u32(*)(void))cb)();  // @h12_42bf90
    else __builtin_trap();
  }
  u32 eax = *(u32 *)(esi + 0x1b55) + (u32)res;  // @h13_42bf90
  *(u8 *)(ebx + eax - 1) = 0x5a;  // @h14_42bf90
  *(u16 *)eax = (u16)edi;  // @h15_42bf90
  eax += 2;
  SEH_LEAVE();
  return eax;
}
PCREG(42bf90, hand_42bf90);

extern "C" u32 THISCALL hand_442d20(u32 ecx_in) {
  SEH_ENTER(0x665ebf);  // @h_442d20
  u8 v1c[0x20] __attribute__((aligned(16)));
  u32 ebx = ecx_in;
  u32 o = ext_41e290_cdecl1((u32)0x2d);  // @h1_442d20
  reg.state = 0;
  u32 r = 0;
  if (o) r = ext_4e3e70_t1(o, 0x2800);  // @h2_442d20
  *(u32 *)(ebx + 0x71) = r;  // @h3_442d20
  reg.state = -1;
  float fl = ext_443080_f(ebx, (u32)v1c);  // @h4_442d20
  float c1 = G(float, 0x67d164);
  float m = (c1 > fl) ? c1 : fl;  // @h5_442d20
  ext_4e4fc0_t1(*(u32 *)(ebx + 0x71), (u32)v1c);  // @h6_442d20
  float q = G(float, 0x67d168) / m;  // @h7_442d20
  ext_4e4fe0_tf(*(u32 *)(ebx + 0x71), q);  // @h8_442d20
  ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x2f0))(ebx, *(u32 *)(ebx + 8));  // @h9_442d20
  u32 eax = *(u32 *)(ebx + 0x7b);
  if (eax != 0) {  // @h10_442d20
    if (*(u16 *)(eax + 2) != 0) {  // @h11_442d20
      u32 i = 0, off = 0x404;
      do {
        u32 ob = *(u32 *)(*(u32 *)(ebx + 0x7b) + off);  // @h12_442d20
        ((u32(THISCALL *)(u32))VSLOT(ob, 0x324))(ob);  // @h13_442d20
        off += 4;
        i++;
        eax = (u32) * (u16 *)(*(u32 *)(ebx + 0x7b) + 2);  // @h14_442d20
      } while (i != eax);
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(442d20, hand_442d20);

extern "C" u32 THISCALL hand_531a50(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66a71f);  // @h_531a50
  u32 self = ecx_in;
  u32 ebx = a0;
  u32 ok = ext_52e0a0_t3(self, ebx, a1, 1) & 0xff;  // @h1_531a50
  if (ok == 0) {  // @h2_531a50
    SEH_LEAVE();
    return 0;
  }
  volatile u32 v10 = 0;
  volatile u32 l8;
  u32 o = ext_41e290_cdecl1((u32)0x18);  // @h3_531a50
  l8 = o;
  reg.state = 0;
  u32 edi;
  if (o) edi = ext_476dc0_t1(o, 2);  // @h4_531a50
  else edi = 0;
  reg.state = -1;
  l8 = 0;
  ext_52d1c0_t8(self, edi, (u32)&v10, (u32)&l8, ebx, ebx, 2, a2, 0);  // @h5_531a50
  ext_52d1c0_t8(self, edi, (u32)&v10, (u32)&l8, ebx, a1, 2, a2, 0);  // @h6_531a50
  u32 fv = l8;
  *(u32 *)(edi + 4) = fv;  // @h7_531a50
  SEH_LEAVE();
  return edi;
}
PCREG(531a50, hand_531a50);

extern "C" u32 THISCALL hand_434ad0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664256);  // @h_434ad0
  u8 iter[12] __attribute__((aligned(16)));
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 edi = ecx_in;
  u32 ebx = a0;
  u32 it = *(u32 *)(edi + 4);
  u32 ret = 0;
  if (it != 0) {  // @h1_434ad0
    ((u32(THISCALL *)(u32, u32))VSLOT(it, 0x4c))(it, (u32)iter);  // @h2_434ad0
    it = *(u32 *)(edi + 4);
    u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(it, 0x64))(it, (u32)iter);  // @h3_434ad0
    while (esi != 0) {  // @h4_434ad0
      ext_4cbeb0_t0((u32)s90);  // @h5_434ad0
      reg.state = 0;
      ext_4cbe80_t1((u32)s110, *(u32 *)(*(u32 *)esi + 0xd));  // @h6_434ad0
      reg.state = 1;
      ext_4cbee0_t1((u32)s90, (u32)s110);  // @h7_434ad0
      reg.state = 0;
      ext_4cbec0_t0((u32)s110);  // @h8_434ad0
      u32 g = G(u32, 0x700394);
      u32 gv = *(u32 *)g;
      u32 cs = ext_4cc1d0_t0((u32)s90);  // @h9_434ad0
      s32 r = (s32)((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(gv + 0x30)))(g, cs, 0);  // @h10_434ad0
      if (r < 0) r = 0;  // @h11_434ad0
      ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 4))(ebx, (u32)r);  // @h12_434ad0
      reg.state = -1;
      ext_4cbec0_t0((u32)s90);  // @h13_434ad0
      it = *(u32 *)(edi + 4);
      esi = ((u32(THISCALL *)(u32, u32))VSLOT(it, 0x64))(it, (u32)iter);  // @h14_434ad0
    }
    ret = esi;
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(434ad0, hand_434ad0);

extern "C" u32 THISCALL hand_5fa7e0(u32 ecx_in) {
  SEH_ENTER(0x66d2ae);  // @h_5fa7e0
  u32 edi = ecx_in;
  W32(edi, 0, 0);  // @h1_5fa7e0
  W32(edi, 4, 0);
  W32(edi, 8, 0);
  u32 e = ext_6014a0_t2(edi, 8);  // @h2_5fa7e0
  W32(edi, 0, e);
  W32(edi, 4, e);  // @h3_5fa7e0
  W32(edi, 8, e + 8);  // @h4_5fa7e0
  *(volatile u8 *)e = 0;
  reg.state = 0;
  u32 x = edi + 0xc;  // @h5_5fa7e0
  W32(x, 0, 0);
  W32(x, 4, 0);
  W32(x, 8, 0);
  e = ext_6014a0_t2(x, 8);  // @h6_5fa7e0
  W32(x, 0, e);
  W32(x, 4, e);
  W32(x, 8, e + 8);  // @h7_5fa7e0
  *(volatile u8 *)e = 0;
  reg.state = 1;
  x = edi + 0x18;  // @h8_5fa7e0
  W32(x, 0, 0);
  W32(x, 4, 0);
  W32(x, 8, 0);
  e = ext_6014a0_t2(x, 8);  // @h9_5fa7e0
  W32(x, 0, e);
  W32(x, 4, e);
  W32(x, 8, e + 8);  // @h10_5fa7e0
  *(volatile u8 *)e = 0;
  reg.state = 2;
  W32(edi, 0x28, 0xa);  // @h11_5fa7e0
  W32(edi, 0x2c, 0);  // @h12_5fa7e0
  u32 r = ext_41e290_cdecl1((u32)40);  // @h13_5fa7e0
  W32(edi, 0x24, r);  // @h14_5fa7e0
  W32(edi, 0x30, edi + 0x24);  // @h15_5fa7e0
  W32(edi, 0x34, 0);  // @h16_5fa7e0
  W32(edi, 0x38, 0);  // @h17_5fa7e0
  SEH_LEAVE();
  return edi;
}
PCREG(5fa7e0, hand_5fa7e0);

extern "C" u32 THISCALL hand_45fb40(u32 ecx_in, float a0) {
  SEH_ENTER(0x6685bb);  // @h_45fb40
  volatile u32 iter[3];
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 esi = ecx_in;
  u32 eax;
  if ((u8)ext_4da3a0_t0(*(u32 *)(esi + 8)) != 0) {  // @h1_45fb40
    u32 c = *(u32 *)(*(u32 *)(esi + 0x10) + 8);
    if (c != 0) {  // @h2_45fb40
      ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, (u32)iter);  // @h3_45fb40
      c = *(u32 *)(*(u32 *)(esi + 0x10) + 8);
      eax = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x5c))(c, (u32)iter);  // @h4_45fb40
      while (iter[0] != 0) {  // @h5_45fb40
        u32 m = G(u32, 0x70038c);
        eax = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0xcc))(m, eax);  // @h6_45fb40
        if (eax != 0 && *(u32 *)(eax + 0x1c) != 0 && (*(u8 *)(eax + 0x14) & 8) != 0) {  // @h7_45fb40
          *(volatile float *)(eax + 0xc) = a0;  // @h8_45fb40
          SEH_LEAVE();
          ext_633654(G(u32, 0x6f5630));
          return eax;
        }
        c = *(u32 *)(*(u32 *)(esi + 0x10) + 8);
        eax = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x5c))(c, (u32)iter);  // @h9_45fb40
      }
    }
  }
  u32 m2 = G(u32, 0x700390);
  u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m2, 0x20))(m2, 0x685054, 0x5bd);  // @h10_45fb40
  u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x1d8))(esi, (u32)s90, 1);  // @h11_45fb40
  reg.state = 0;
  u32 cs = ext_4cc1d0_t0(r1);  // @h12_45fb40
  ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x685128, cs);  // @h13_45fb40
  eax = ext_4cbec0_t0((u32)s90);  // @h14_45fb40
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(45fb40, hand_45fb40);

extern "C" u32 THISCALL hand_4d7220(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6695d2);  // @h_4d7220
  u32 edi = ecx_in;
  u32 esi = ext_41e290_cdecl1((u32)0x432);  // @h1_4d7220
  reg.state = 0;
  u32 q = ext_41e290_cdecl1((u32)0x38);  // @h2_4d7220
  *(u32 *)(esi + 0x26) = q;  // @h3_4d7220
  reg.state = -1;
  *(u32 *)(esi + 0x1e) = 0;
  *(u32 *)esi = a1;  // @h4_4d7220
  bool fail = true;
  if (a1 == 3) {  // @h5_4d7220
    if ((u8)ext_4d6520_t3(edi, a0, esi + 4, 0) != 0) {  // @h6_4d7220
      u32 u = *(u32 *)(edi + 0x15);
      u32 v = ((u32(THISCALL *)(u32, u32))VSLOT(u, 0xc))(u, *(u32 *)(edi + 0x11));  // @h7_4d7220
      *(u32 *)(esi + 0x1e) = v;
      *(u32 *)(esi + 0x22) = v;  // @h8_4d7220
      *(u32 *)(esi + 0x2a) = *(u32 *)(esi + 0x12);  // @h9_4d7220
      q = *(u32 *)(esi + 0x26);
      *(u32 *)(q + 0x20) = 0;
      *(u32 *)(q + 0x24) = 0;  // @h10_4d7220
      *(u32 *)q = esi + 0x2e;  // @h11_4d7220
      *(u32 *)(q + 4) = 0;
      u32 r = ext_62f9d0_t4(esi + 0x2e, *(u32 *)(esi + 0x26), (u32)-0xf, 0x69688c, 0x38);  // @h12_4d7220
      *(u32 *)(esi + 0x42e) = r;  // @h13_4d7220
      if (r == 0) fail = false;  // @h14_4d7220
    }
  }
  if (fail) {
    ext_634273_cdecl2(*(u32 *)(esi + 0x26), 0x38);  // @h15_4d7220
    ext_634273_cdecl2(esi, 0x432);  // @h16_4d7220
    SEH_LEAVE();
    return 0;
  }
  *(u8 *)(edi + 0x6e) = 0;  // @h17_4d7220
  SEH_LEAVE();
  return esi;
}
PCREG(4d7220, hand_4d7220);

extern "C" u32 STDCALL hand_555570(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_555570
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 edi = a0;
  u32 P = ext_5003d0_t1(*(u32 *)(edi + 4), 0);  // @h1_555570
  u32 e = *(u32 *)P;
  u32 g = *(u32 *)(G(u32, 0x70039c) + 0x9b);  // @h2_555570
  u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x58))(g, e);  // @h3_555570
  u32 Q = ext_5003d0_t1(*(u32 *)(edi + 8), 0);  // @h4_555570
  u32 eax = ext_5002f0_t1(Q, 0);  // @h5_555570
  if (esi == 0) {  // @h6_555570
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6a57fc, 0x2dc);  // @h7_555570
    eax = ((u32(*)(u32, u32))VSLOT(L, 0x2c))(L, 0x6a5948);  // @h8_555570
  } else {
    u8 okb = (u8)((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x1e0))(esi, 0x200074);  // @h9_555570
    if (okb == 0) {  // @h10_555570
      u32 m = G(u32, 0x700390);
      u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6a57fc, 0x2e0);  // @h11_555570
      u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x1d8))(esi, (u32)s90, 1);  // @h12_555570
      reg.state = 0;
      u32 cs = ext_4cc1d0_t0(r1);  // @h13_555570
      ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x6a5978, cs);  // @h14_555570
      eax = ext_4cbec0_t0((u32)s90);  // @h15_555570
    } else {
      u32 b = ((u32(THISCALL *)(u32))VSLOT(esi, 0x438))(esi) & 0xff;  // @h16_555570
      u32 Q2 = ext_5003d0_t1(*(u32 *)(edi + 8), 0);  // @h17_555570
      eax = ext_5002f0_t1(Q2, b);  // @h18_555570
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(555570, hand_555570);

extern "C" u32 THISCALL hand_5b86a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x663fdf);  // @h_5b86a0
  u32 esi = ecx_in, rd = a0;
  *(u32 *)(esi + 0x48) = ext_4e5e60_t0(rd);  // @h1_5b86a0
  u32 o = ext_41e290_cdecl1((u32)0x1c);  // @h2_5b86a0
  reg.state = 0;
  u32 r = 0;
  if (o) r = ext_4ccbe0_t2(o, 1, 0);  // @h3_5b86a0
  reg.state = -1;
  *(u32 *)(esi + 0x4c) = r;
  ext_4e6330_t1(rd, r);  // @h4_5b86a0
  *(u32 *)(esi + 0x50) = ext_4e5e60_t0(rd);  // @h5_5b86a0
  *(u32 *)(esi + 0x54) = ext_4e5e60_t0(rd);  // @h6_5b86a0
  float f1 = ext_4e5e80_f(rd);  // @h7_5b86a0
  float f2 = ext_4e5e80_f(rd);  // @h8_5b86a0
  *(volatile float *)(esi + 0x5c) = f2;
  u32 d = ext_4e5e60_t0(rd);  // @h9_5b86a0
  *(u32 *)(esi + 0xde) = d;
  u32 ebx = ext_4e5e60_t0(rd);  // @h10_5b86a0
  u8 *p = (u8 *)ext_4e5ea0_t0(rd);  // @h11_5b86a0
  u8 *dst = (u8 *)(esi + 0x60);
  for (;;) {
    u8 ch = *p++;
    *dst++ = ch;
    if (ch == 0) break;  // @h12_5b86a0
  }
  u32 g = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  if (ebx != 0) {  // @h13_5b86a0
    *(u32 *)(esi + 0xe2) = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x58))(g, ebx);  // @h14_5b86a0
  }
  u32 e2 = *(u32 *)(esi + 0xde);
  if (e2 != 0) {  // @h15_5b86a0
    g = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    *(u32 *)(esi + 0xe6) = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x58))(g, e2);  // @h16_5b86a0
  }
  g = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 v = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x58))(g, *(u32 *)(esi + 0x48));  // @h17_5b86a0
  float m = f1 * G(float, 0x68af2c);  // @h18_5b86a0
  *(u32 *)(esi + 0x7e) = v;
  float q = m / G(float, 0x6a87fc);  // @h19_5b86a0
  *(volatile float *)(esi + 0x58) = q;
  SEH_LEAVE();
  return v;
}
PCREG(5b86a0, hand_5b86a0);

extern "C" u32 THISCALL hand_49b490(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66832a);  // @h_49b490
  u32 esi = ecx_in;
  ext_4e6b30_t0(esi + 4);  // @h1_49b490
  reg.state = 0;
  W32(esi, 0, 0x68ece4);  // @h2_49b490
  if (a0 == 0) {  // @h3_49b490
    W32(esi, 0x35, 0);
    SEH_LEAVE();
    return esi;
  }
  W32(esi, 0x19, *(u32 *)a0);  // @h4_49b490
  W32(esi, 0x21, *(u32 *)(a0 + 4));  // @h5_49b490
  W32(esi, 0x29, *(u32 *)(a0 + 8));  // @h6_49b490
  W32(esi, 0x1d, a0);  // @h7_49b490
  W32(esi, 0x2d, 0);
  u32 o = ext_41e290_cdecl1((u32)0x15);  // @h8_49b490
  reg.state = 1;
  u32 e = 0;
  if (o) e = ext_4e6b30_t0(o);  // @h9_49b490
  W32(esi, 0x2d, e);
  reg.state = 0;
  u32 p1 = *(u32 *)(esi + 0x1d) + (*(u32 *)(esi + 0x29) + *(u32 *)(esi + 0x19)) * 4;  // @h10_49b490
  ext_4e6c80_t4(esi + 4, 0x10, (*(u32 *)(esi + 0x21) << 2) >> 4, p1, 1);  // @h11_49b490
  u32 p2 = *(u32 *)(esi + 0x1d) + *(u32 *)(esi + 0x19) * 4;  // @h12_49b490
  ext_4e6c80_t4(*(u32 *)(esi + 0x2d), 8, (*(u32 *)(esi + 0x29) << 2) >> 3, p2, 1);  // @h13_49b490
  W32(esi, 0x25, *(u32 *)(esi + 4));  // @h14_49b490
  W32(esi, 0x31, 0x200);  // @h15_49b490
  W32(esi, 0x35, 0);
  u32 b = ext_41e290_cdecl1((u32)0x1800);  // @h16_49b490
  u32 c4 = *(u32 *)(esi + 0x31) << 2;  // @h17_49b490
  W32(esi, 0x35, b);
  W32(esi, 0x39, b + c4);  // @h18_49b490
  W32(esi, 0x3d, b + c4 + c4);  // @h19_49b490
  SEH_LEAVE();
  return esi;
}
PCREG(49b490, hand_49b490);

extern "C" u32 STDCALL hand_555d10(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_555d10
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 edi = a0;
  u32 P = ext_5003d0_t1(*(u32 *)(edi + 4), 0);  // @h1_555d10
  u32 e = *(u32 *)P;
  u32 g = *(u32 *)(G(u32, 0x70039c) + 0x9b);  // @h2_555d10
  u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x58))(g, e);  // @h3_555d10
  u32 Q = ext_5003d0_t1(*(u32 *)(edi + 8), 0);  // @h4_555d10
  u32 eax = ext_5002f0_t1(Q, 0);  // @h5_555d10
  if (esi == 0) {  // @h6_555d10
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6a57fc, 0x301);  // @h7_555d10
    eax = ((u32(*)(u32, u32))VSLOT(L, 0x2c))(L, 0x6a5a64);  // @h8_555d10
  } else {
    bool send = false;
    u32 arg = 0;
    if ((u8)((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x1e0))(esi, 0x2007f9) != 0) {  // @h9_555d10
      send = true;
      u32 fl = ((u32(THISCALL *)(u32))VSLOT(esi, 0x674))(esi);  // @h10_555d10
      if (fl != 0) {  // @h11_555d10
        u8 b = (u8)((u32(THISCALL *)(u32))VSLOT(esi, 0x670))(esi);  // @h12_555d10
        arg = (b != 0) ? 1 : 0;  // @h13_555d10
      } else {
        arg = 1;  // @h14_555d10
      }
    } else if ((u8)((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x1e0))(esi, 0x2003e8) != 0) {  // @h15_555d10
      send = true;
      arg = 0;
    }
    if (send) {
      u32 Q2 = ext_5003d0_t1(*(u32 *)(edi + 8), 0);  // @h16_555d10
      eax = ext_5002f0_t1(Q2, arg);  // @h17_555d10
    } else {
      u32 m = G(u32, 0x700390);
      u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6a57fc, 0x30d);  // @h18_555d10
      u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x1d8))(esi, (u32)s90, 1);  // @h19_555d10
      reg.state = 0;
      u32 cs = ext_4cc1d0_t0(r1);  // @h20_555d10
      ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x6a5a98, cs);  // @h21_555d10
      eax = ext_4cbec0_t0((u32)s90);  // @h22_555d10
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(555d10, hand_555d10);

extern "C" u32 THISCALL hand_42c9a0(u32 ecx_in) {
  SEH_ENTER(0x664dc6);  // @h_42c9a0
  u8 s110[0x80] __attribute__((aligned(16)));
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 edi = ecx_in;
  u32 sobj = edi + 0x4a3;
  u8 *c = (u8 *)ext_4cc1d0_t0(sobj);  // @h1_42c9a0
  if (c[0] != 0x25) {  // @h2_42c9a0
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return (u32)c;
  }
  u32 esi = 1;
  c = (u8 *)ext_4cc1d0_t0(sobj);  // @h3_42c9a0
  if (c[1] != 0x25) {  // @h4_42c9a0
    do {
      esi++;
      c = (u8 *)ext_4cc1d0_t0(sobj);  // @h5_42c9a0
    } while (c[esi] != 0x25);  // @h6_42c9a0
  }
  do {
    esi++;  // @h7_42c9a0
    c = (u8 *)ext_4cc1d0_t0(sobj);
    if (c[esi] == 0x5c) continue;  // @h8_42c9a0
    c = (u8 *)ext_4cc1d0_t0(sobj);
    if (c[esi] == 0x2f) continue;  // @h9_42c9a0
    break;
  } while (true);
  c = (u8 *)ext_4cc1d0_t0(sobj);  // @h10_42c9a0
  u32 r = ((u32(*)(u32, u32, u32))G(u32, 0x676410))((u32)c + 1, 0x679e88, 7);  // @h11_42c9a0
  if (r != 0) {  // @h12_42c9a0
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return r;
  }
  u8 *buf = (u8 *)ext_41e290_cdecl1((u32)0x104);  // @h13_42c9a0
  u32 R = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x19c))(edi, (u32)s110);  // @h14_42c9a0
  reg.state = 0;
  u8 *src = (u8 *)ext_4cc1d0_t0(R);  // @h15_42c9a0
  u8 *d = buf;
  for (;;) {
    u8 ch = *src++;
    *d++ = ch;
    if (ch == 0) break;  // @h16_42c9a0
  }
  reg.state = -1;
  ext_4cbec0_t0((u32)s110);  // @h17_42c9a0
  c = (u8 *)ext_4cc1d0_t0(sobj);  // @h18_42c9a0
  u8 *rest = c + esi;  // @h19_42c9a0
  u32 len = 0;
  while (rest[len]) len++;
  len += 1;  // @h20_42c9a0
  u8 *e = buf;
  while (*e) e++;  // @h21_42c9a0
  for (u32 i = 0; i < len; i++) e[i] = rest[i];  // @h22_42c9a0
  ext_4cbe80_t1((u32)s90, (u32)buf);  // @h23_42c9a0
  reg.state = 1;
  ext_4cbee0_t1(sobj, (u32)s90);  // @h24_42c9a0
  u32 ret = ext_4cbec0_t0((u32)s90);  // @h25_42c9a0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(42c9a0, hand_42c9a0);

extern "C" u32 THISCALL hand_4c8e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669176);  // @h_4c8e20
  u8 A[0xac] __attribute__((aligned(16)));
  u8 B[0xac] __attribute__((aligned(16)));
  volatile u32 iter[3];
  u32 edi = ecx_in, rd = a0;
  ext_4ccba0_t0((u32)A);  // @h1_4c8e20
  reg.state = 0;
  ext_4ccba0_t0((u32)B);  // @h2_4c8e20
  reg.state = 1;
  ext_4e6330_t1(rd, (u32)A);  // @h3_4c8e20
  ext_4e6330_t1(rd, (u32)B);  // @h4_4c8e20
  u32 n1 = ext_4cdd40_t0((u32)A);  // @h5_4c8e20
  *(u32 *)(edi + 0x50) = n1;
  u32 n2 = ext_4cdd40_t0((u32)B);  // @h6_4c8e20
  *(u32 *)(edi + 0x54) = n2;
  u64 prod = (u64)(n2 + *(u32 *)(edi + 0x50)) * 4;  // @h7_4c8e20
  u32 sz = (u32)prod | ((prod >> 32) ? 0xffffffffu : 0u);
  u32 buf = ext_41e290_cdecl1(sz);  // @h8_4c8e20
  u32 esi = buf;
  *(u32 *)(edi + 0x48) = buf;
  *(u32 *)(edi + 0x4c) = buf + *(u32 *)(edi + 0x50) * 4;  // @h9_4c8e20
  u32 va = *(u32 *)A;
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(va + 0x4c)))((u32)A, (u32)iter);  // @h10_4c8e20
  va = *(u32 *)A;
  u32 v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(va + 0x5c)))((u32)A, (u32)iter);  // @h11_4c8e20
  while (iter[0] != 0) {  // @h12_4c8e20
    *(u32 *)esi = v;  // @h13_4c8e20
    esi += 4;
    va = *(u32 *)A;
    v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(va + 0x5c)))((u32)A, (u32)iter);  // @h14_4c8e20
  }
  u32 vb = *(u32 *)B;
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(vb + 0x4c)))((u32)B, (u32)iter);  // @h15_4c8e20
  vb = *(u32 *)B;
  v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vb + 0x5c)))((u32)B, (u32)iter);  // @h16_4c8e20
  while (iter[0] != 0) {  // @h17_4c8e20
    *(u32 *)esi = v;  // @h18_4c8e20
    vb = *(u32 *)B;
    esi += 4;
    v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vb + 0x5c)))((u32)B, (u32)iter);  // @h19_4c8e20
  }
  ext_4c8fe0_t0(edi);  // @h20_4c8e20
  ext_4ccf60_t0((u32)B);  // @h21_4c8e20
  u32 ret = ext_4ccf60_t0((u32)A);  // @h22_4c8e20
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4c8e20, hand_4c8e20);

extern "C" u32 THISCALL hand_5fa910(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d31a);  // @h_5fa910
  u32 edi = ecx_in;
  W32(edi, 0, ext_603090_t0(edi));  // @h1_5fa910
  u32 esi = edi + 8;
  W32(esi, 0, 0);
  W32(esi, 4, 0);
  W32(esi, 8, 0);
  u32 e = ext_6014a0_t2(esi, 8);  // @h2_5fa910
  W32(esi, 0, e);
  W32(esi, 4, e);
  W32(esi, 8, e + 8);  // @h3_5fa910
  *(volatile u8 *)e = 0;
  reg.state = 0;
  W32(edi, 0x1c, 0xa);  // @h4_5fa910
  W32(edi, 0x20, 0);
  u32 buf = ext_41e290_cdecl1((u32)40);  // @h5_5fa910
  W32(edi, 0x18, buf);
  W32(edi, 0x24, a0);  // @h6_5fa910
  esi = edi + 0x41;
  W32(edi, 0x28, 0);
  W32(edi, 0x2c, 0);
  W32(edi, 0x30, 0);
  W32(edi, 0x34, 0);
  reg.state = 1;
  W32(esi, 0, 0);
  W32(esi, 4, 0);
  W32(esi, 8, 0);
  e = ext_6014a0_t2(esi, 8);  // @h7_5fa910
  W32(esi, 0, e);
  W32(esi, 4, e);
  W32(esi, 8, e + 8);  // @h8_5fa910
  *(volatile u8 *)e = 0;
  reg.state = 2;
  ext_4690b0_t0(e + 8);  // @h9_5fa910
  G(u32, 0x724278) = edi;  // @h10_5fa910
  u32 o = ext_41e290_cdecl1((u32)0xa);  // @h11_5fa910
  reg.state = 3;
  u32 ebx = 0;
  if (o) {  // @h12_5fa910
    esi = o + 1;
    W32(esi, 0, 0);
    u32 e3 = ext_6014a0_t2(esi, 0x1d);  // @h13_5fa910
    W32(esi, 0, e3);
    W32(esi, 4, 0);
    *(volatile u8 *)e3 = 0;
    W32(*(u32 *)esi, 1, 0);  // @h14_5fa910
    W32(*(u32 *)esi, 5, *(u32 *)esi);  // @h15_5fa910
    W32(*(u32 *)esi, 9, *(u32 *)esi);  // @h16_5fa910
    reg.state = 4;
    ext_5fb660_t0(o);  // @h17_5fa910
    ebx = o;
  }
  reg.state = 2;
  W32(edi, 4, ebx);  // @h18_5fa910
  W32(edi, 0x38, 0);  // @h19_5fa910
  u32 p = ext_41e290_cdecl1((u32)0x33);  // @h20_5fa910
  reg.state = 5;
  u32 r = 0;
  if (p) r = ext_606b80_t0(p);  // @h21_5fa910
  W32(edi, 0x3c, r);  // @h22_5fa910
  *(volatile u8 *)(edi + 0x40) = 0;  // @h23_5fa910
  SEH_LEAVE();
  return edi;
}
PCREG(5fa910, hand_5fa910);

extern "C" u32 THISCALL hand_5853f0(u32 ecx_in) {
  SEH_ENTER(0x66b5c5);  // @h_5853f0
  u32 edi = ecx_in;
  ext_469870_t0(edi);  // @h1_5853f0
  W32(edi, 4, *(u32 *)(edi + 4) | 0x20);  // @h2_5853f0
  W32(edi, 0x44, 0);
  W32(edi, 0, 0x6ab818);  // @h3_5853f0
  *(volatile u8 *)(edi + 0x56) = 0;
  reg.state = 0;
  W32(edi, 0x5f, 0);
  W32(edi, 0x63, 0);
  W32(edi, 0x67, 0);
  W32(edi, 0x6b, 0);
  W32(edi, 0x6f, 0);  // @h4_5853f0
  u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  reg.state = 1;
  u32 v = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x6a53e4, 0, 0x6ab8a0, 0x31);  // @h5_5853f0
  *(volatile u16 *)(edi + 0x50) = (u16)v;  // @h6_5853f0
  c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  v = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x6a53d8, 0, 0x6ab8a0, 0x32);  // @h7_5853f0
  *(volatile u16 *)(edi + 0x52) = (u16)v;  // @h8_5853f0
  c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  v = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x6a4d6c, 0, 0x6ab8a0, 0x33);  // @h9_5853f0
  *(volatile u16 *)(edi + 0x54) = (u16)v;  // @h10_5853f0
  W32(edi, 0x73, 0);
  W32(edi, 0x4c, 1);  // @h11_5853f0
  u32 buf = ext_41e290_cdecl1((u32)10);  // @h12_5853f0
  W32(edi, 0x48, buf);
  s32 i = 0;
  if ((s32)*(u32 *)(edi + 0x4c) > 0) {  // @h13_5853f0
    u32 off = 0;
    do {
      u32 b = *(u32 *)(edi + 0x48);
      u32 w0 = *(u32 *)(0x6ecf70 + off);  // @h14_5853f0
      *(u32 *)(b + off) = w0;
      b = *(u32 *)(edi + 0x48);
      u32 w6 = *(u32 *)(0x6ecf76 + off);  // @h15_5853f0
      *(u32 *)(b + off + 6) = w6;
      c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      b = *(u32 *)(edi + 0x48);
      v = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, *(u32 *)(b + off), 0, 0x6ab8a0, 0x37);  // @h16_5853f0
      b = *(u32 *)(edi + 0x48);
      off += 10;
      i++;
      *(u16 *)(b + off - 6) = (u16)v;  // @h17_5853f0
    } while (i < (s32)*(u32 *)(edi + 0x4c));
  }
  u32 o = ext_41e290_cdecl1((u32)0x108);  // @h18_5853f0
  reg.state = 2;
  u32 edx = 0;
  if (o) edx = ext_4d8330_t3(o, 0x6ab8f4, 0x6ab8d4, 0x714290);  // @h19_5853f0
  W32(edi, 0x77, edx);  // @h20_5853f0
  u32 g = G(u32, 0x70039c);
  reg.state = 1;
  ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x1a4))(g, edx);  // @h21_5853f0
  SEH_LEAVE();
  return edi;
}
PCREG(5853f0, hand_5853f0);

extern "C" u32 THISCALL hand_443d60(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665ef8);  // @h_443d60
  u8 v60[0x18] __attribute__((aligned(16)));
  volatile u32 v64, v70, v74, v78;
  u8 v1c[12] __attribute__((aligned(16)));
  u8 v28[12] __attribute__((aligned(16)));
  u8 v38[16] __attribute__((aligned(16)));
  u8 v48[16] __attribute__((aligned(16)));
  u32 self = ecx_in, wr = a0;
  u32 acc = a1, esi = a1;
  *(u32 *)(self + 0x7f) = a1;  // @h1_443d60
  u32 p = self + 0x5d;
  int cnt = 5;
#define WRITE(ptr, len) ((u32(THISCALL *)(u32, u32, u32))VSLOT(wr, 0x1c))(wr, (u32)(ptr), (u32)(len))
  do {
    u32 obj = *(u32 *)p;
    if (obj == 0) {  // @h2_443d60
      v78 = 0;
      WRITE(&v78, 4);  // @h3_443d60
      for (int i = 0; i < 16; i++) v48[i] = 0;  // @h4_443d60
      WRITE(v48, 0xc);  // @h5_443d60
      esi = acc + 0x10;  // @h6_443d60
    } else {
      u32 data = ((u32(THISCALL *)(u32, u32))VSLOT(obj, 0x10))(obj, (u32)&v64);  // @h7_443d60
      *(u32 *)v60 = 0x67d138;
      reg.state = 0;
      ext_4e3d60_t1((u32)v60, data);  // @h8_443d60
      ext_4e3e40_t1((u32)v60, 0x443ac0);  // @h9_443d60
      v70 = v64;  // @h10_443d60
      WRITE(&v70, 4);  // @h11_443d60
      u32 obj2 = *(u32 *)p;
      v74 = *(u32 *)(obj2 + 0x10);  // @h12_443d60
      ext_4e3340_t1(obj2, (u32)v1c);  // @h13_443d60
      for (int i = 0; i < 12; i++) v28[i] = v1c[i];  // @h14_443d60
      WRITE(&v74, 4);  // @h15_443d60
      WRITE(v28, 0xc);  // @h16_443d60
      for (int i = 0; i < 16; i++) v38[i] = 0;  // @h17_443d60
      WRITE(v38, 0xc);  // @h18_443d60
      WRITE(data, v64);  // @h19_443d60
      u32 n = (0u - v64) & 0xf;  // @h20_443d60
      WRITE(v38, n);  // @h21_443d60
      ext_634273_cdecl2(data, 0);  // @h22_443d60
      u32 sz = v64;
      reg.state = -1;
      esi = acc + 0x20 + (((0u - sz) & 0xf) + sz);  // @h23_443d60
    }
    p += 4;
    acc = esi;
    cnt--;
  } while (cnt != 0);
#undef WRITE
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return esi;
}
PCREG(443d60, hand_443d60);

extern "C" u32 THISCALL hand_59f1a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_59f1a0
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 ebx = ecx_in;
  u32 eax = 0;
  if (*(u32 *)(ebx + 0x78a) == 0) {  // @h1_59f1a0
    u32 t = *(u32 *)(ebx + 0x792);
    if (t != 0) {  // @h2_59f1a0
      u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x72c))(ebx, t);  // @h3_59f1a0
      u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      eax = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, esi);  // @h4_59f1a0
      *(u32 *)(ebx + 0x78a) = eax;
      if (esi != 0) {  // @h5_59f1a0
        if (*(u32 *)(ebx + 0x79a) != 0) {  // @h6_59f1a0
          u32 o = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x4f8))(ebx);  // @h7_59f1a0
          eax = ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 8))(o, ebx, *(u32 *)(ebx + 0x78a));  // @h8_59f1a0
        } else {
          eax = ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x2d0))(esi, 1, 0);  // @h9_59f1a0
        }
      } else {
        u32 m = G(u32, 0x700390);
        u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6ae6a0, 0x56c);  // @h10_59f1a0
        u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x1d8))(ebx, (u32)s90, 1);  // @h11_59f1a0
        reg.state = 0;
        u32 cs = ext_4cc1d0_t0(r1);  // @h12_59f1a0
        ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x6aea98, cs);  // @h13_59f1a0
        reg.state = -1;
        eax = ext_4cbec0_t0((u32)s90);  // @h14_59f1a0
      }
    }
  }
  if (*(u32 *)(ebx + 0x78e) == 0) {  // @h15_59f1a0
    u32 t = *(u32 *)(ebx + 0x796);
    if (t != 0) {  // @h16_59f1a0
      u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x72c))(ebx, t);  // @h17_59f1a0
      u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      eax = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, esi);  // @h18_59f1a0
      *(u32 *)(ebx + 0x78e) = eax;
      if (esi != 0) {  // @h19_59f1a0
        u32 o = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x4fc))(ebx);  // @h20_59f1a0
        eax = ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 8))(o, ebx, *(u32 *)(ebx + 0x78e));  // @h21_59f1a0
      } else {
        u32 m = G(u32, 0x700390);
        u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x6ae6a0, 0x57b);  // @h22_59f1a0
        u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x1d8))(ebx, (u32)s110, 1);  // @h23_59f1a0
        reg.state = 1;
        u32 cs = ext_4cc1d0_t0(r1);  // @h24_59f1a0
        ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x6aeac8, cs);  // @h25_59f1a0
        eax = ext_4cbec0_t0((u32)s110);  // @h26_59f1a0
      }
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(59f1a0, hand_59f1a0);

extern "C" u32 THISCALL hand_48fcb0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667cb1);  // @h_48fcb0
  u8 s110[0x80] __attribute__((aligned(16)));
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 self = ecx_in, edi = a0, esi = a1;
  u32 m = G(u32, 0x700390);
  if (*(u32 *)(m + 0xc) == 0) *(u32 *)(esi + 0x34) = 0;  // @h1_48fcb0
  u32 g = G(u32, 0x70039c);
  u32 t0 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(g, 0x1c8))(g, 0x68d798, 0x148f);  // @h2_48fcb0
  float f = *(float *)(self + 0x10);
  if (f == G(float, 0x678858)) {  // @h3_48fcb0
    ext_4cbe80_t1((u32)s110, **(u32 **)(edi + 0xc));  // @h4_48fcb0
    reg.state = 0;
    ext_4cbe80_t1((u32)s90, 0x68e288);  // @h5_48fcb0
    reg.state = 1;
    ext_4cc2c0_t1((u32)s110, (u32)s90);  // @h6_48fcb0
    reg.state = 0;
    ext_4cbec0_t0((u32)s90);  // @h7_48fcb0
    u32 nm = *(u32 *)(edi + 4);
    if (nm == 0) nm = 0x67c8e8;  // @h8_48fcb0
    ext_4cbe80_t1((u32)s90, nm);  // @h9_48fcb0
    reg.state = 2;
    ext_4cc2c0_t1((u32)s110, (u32)s90);  // @h10_48fcb0
    reg.state = 0;
    ext_4cbec0_t0((u32)s90);  // @h11_48fcb0
    ext_494b40_t1(self, 0x68e28c);  // @h12_48fcb0
    ((u32(THISCALL *)(u32))VSLOT(edi, 0x160))(edi);  // @h13_48fcb0
    u32 cs = ext_4cc1d0_t0((u32)s110);  // @h14_48fcb0
    ext_494ac0_t1(self, cs);  // @h15_48fcb0
    reg.state = -1;
    ext_4cbec0_t0((u32)s110);  // @h16_48fcb0
  } else {
    ((u32(THISCALL *)(u32))VSLOT(edi, 0x160))(edi);  // @h17_48fcb0
  }
  u32 m2 = G(u32, 0x700390);
  u32 eax = m2;
  if (*(u32 *)(m2 + 0xc) != 0) {  // @h18_48fcb0
    g = G(u32, 0x70039c);
    u32 t1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(g, 0x1c8))(g, 0x68d798, 0x14a0);  // @h19_48fcb0
    u32 delta = t1 - t0;  // @h20_48fcb0
    if (*(u32 *)(esi + 0x34) == 0) {  // @h21_48fcb0
      u32 mc = *(u32 *)(G(u32, 0x700390) + 0xc);
      u32 blk = ((u32(THISCALL *)(u32, u32))VSLOT(mc, 4))(mc, 0) - 4;  // @h22_48fcb0
      *(u32 *)(esi + 0x34) = blk;
      for (int i = 0; i < 6; i++) ((volatile u32 *)blk)[i] = 0;  // @h23_48fcb0
      u32 gg = G(u32, 0x70039c);
      u32 c = *(u32 *)(gg + 0x9b);
      u32 v = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, edi);  // @h24_48fcb0
      *(u32 *)(*(u32 *)(esi + 0x34) + 8) = v;
      u32 w = ext_41e680_t0(esi);  // @h25_48fcb0
      *(u32 *)(*(u32 *)(esi + 0x34) + 0xc) = w;  // @h26_48fcb0
      *(u32 *)(*(u32 *)(esi + 0x34) + 4) = 0x8000010;  // @h27_48fcb0
      *(u32 *)(*(u32 *)(esi + 0x34) + 0x10) = **(u32 **)(edi + 0xc);  // @h28_48fcb0
    }
    eax = *(u32 *)(esi + 0x34);
    *(u32 *)eax += delta;  // @h29_48fcb0
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(48fcb0, hand_48fcb0);

extern "C" u32 THISCALL hand_505510(u32 ecx_in, u32 a0, u32 a1, float a2, float a3, u32 a4, float a5) {
  SEH_ENTER(0x669cf1);  // @h_505510
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u8 s41d4[0x4000] __attribute__((aligned(16)));
  u32 self = ecx_in, edi = a0;
  u32 Y = *(u32 *)(self + 0x14);
  if (edi != 0) {  // @h1_505510
    u32 edx = (a1 & 1) * 4 + 1;  // @h2_505510
    u32 code = ((a1 & 2) != 0) ? (edx | 0x800) : edx;  // @h3_505510
    u32 r = ((u32(THISCALL *)(u32, u32, u32, float, float, float))VSLOT(Y, 0x228))(Y, edi, code, a2, a3, a5);  // @h4_505510
    if (r != 0) {  // @h5_505510
      u32 ret = *(u32 *)(r + 0x48);  // @h6_505510
      SEH_LEAVE();
      ext_633654(G(u32, 0x6f5630));
      return ret;
    }
    if ((*(u8 *)(edi + 0x7c) & 0x20) == 0) {  // @h7_505510
      u32 m = G(u32, 0x700390);
      u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x69cd2c, 0x180);  // @h8_505510
      u32 Y2 = *(u32 *)(self + 0x14);
      u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(Y2, 0x1d8))(Y2, (u32)s90, 1);  // @h9_505510
      reg.state = 0;
      u32 cs = ext_4cc1d0_t0(r1);  // @h10_505510
      ((u32(*)(u32, u32, u32, u32))VSLOT(L, 0x30))(L, 0x69cea8, edi, cs);  // @h11_505510
      reg.state = -1;
      ext_4cbec0_t0((u32)s90);  // @h12_505510
    }
  } else {
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x69cd2c, 0x183);  // @h13_505510
    u32 Y2 = *(u32 *)(self + 0x14);
    u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(Y2, 0x1d8))(Y2, (u32)s110, 1);  // @h14_505510
    reg.state = 1;
    u32 cs = ext_4cc1d0_t0(r1);  // @h15_505510
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x30))(L, 0x69cee0, cs);  // @h16_505510
    reg.state = -1;
    ext_4cbec0_t0((u32)s110);  // @h17_505510
  }
  ext_4d2280_t0((u32)s41d4);  // @h18_505510
  reg.state = 2;
  ext_4d3ab0_t2b((u32)s41d4, 0x685924, 0);  // @h19_505510
  Y = *(u32 *)(self + 0x14);
  u32 gg = G(u32, 0x70039c);
  u32 c = *(u32 *)(gg + 0x9b);
  u32 v = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x685874, 0, 0x69cd2c, 0x188, (u32)s41d4, 0);  // @h20_505510
  Y = *(u32 *)(self + 0x14);
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)Y + 0x128)))(Y, v & 0xffff);  // @h21_505510
  ext_4d2330_t0((u32)s41d4);  // @h22_505510
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(505510, hand_505510);

extern "C" u32 THISCALL hand_499670(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x668228);  // @h_499670
  u8 ob[0x24] __attribute__((aligned(16)));
  u8 it[12] __attribute__((aligned(16)));
  volatile u32 vA, vB, vC;
  u32 self = ecx_in;
  u32 base = *(u32 *)(*(u32 *)(self + 0x14) + 4);  // @h1_499670
  u32 esi = *(u32 *)(a1 + 0x50);  // @h2_499670
  u32 edi = esi, ebx = esi;
  ext_4ccb40_t2((u32)ob, 0x80, 0);  // @h3_499670
  reg.state = 0;
  while (esi != 0) {  // @h4_499670
    u32 q = esi + 0x60;
    esi = *(u32 *)q;
    if (ebx + 0x70 != esi) {  // @h5_499670
      if (edi - 0x70 == esi) {  // @h6_499670
        edi = esi;
        continue;
      }
      s32 ib = (s32)(ebx - base) / 112;  // @h7_499670
      s32 id = (s32)(edi - base) / 112;  // @h8_499670
      ext_4cd6f0_t2((u32)ob, (u32)id, (u32)ib);  // @h9_499670
      esi = *(u32 *)q;
      edi = esi;
    }
    ebx = esi;  // @h10_499670
  }
  ext_4cf690_t0((u32)ob);  // @h11_499670
  u32 eax = ext_4cdd40_t0((u32)ob);  // @h12_499670
  if (eax != 0) {  // @h13_499670
    u32 P = a0;
    u32 W = *(u32 *)P;
    ((u32(THISCALL *)(u32, u32))VSLOT(W, 8))(W, 0xa);  // @h14_499670
    s32 idx = (s32)(*(u32 *)(a1 + 8) - base) / 112;  // @h15_499670
    vA = (u32)idx & 0xffff;
    W = *(u32 *)P;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(W, 0x10))(W, (u32)&vA, 2);  // @h16_499670
    u32 vt = *(u32 *)ob;
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x4c)))((u32)ob, (u32)it);  // @h17_499670
    vt = *(u32 *)ob;
    u32 r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x64)))((u32)ob, (u32)it);  // @h18_499670
    while (r != 0) {  // @h19_499670
      vB = (u32) * (u16 *)r;  // @h20_499670
      vC = (u32) * (u16 *)(r + 4);  // @h21_499670
      W = *(u32 *)P;
      ((u32(THISCALL *)(u32, u32, u32))VSLOT(W, 0x10))(W, (u32)&vB, 2);  // @h22_499670
      W = *(u32 *)P;
      ((u32(THISCALL *)(u32, u32, u32))VSLOT(W, 0x10))(W, (u32)&vC, 2);  // @h23_499670
      vt = *(u32 *)ob;
      r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x64)))((u32)ob, (u32)it);  // @h24_499670
    }
    W = *(u32 *)P;
    vA = 0xffff;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(W, 0x10))(W, (u32)&vA, 2);  // @h25_499670
  }
  u32 ret = ext_4ccef0_t0((u32)ob);  // @h26_499670
  SEH_LEAVE();
  return ret;
}
PCREG(499670, hand_499670);

extern "C" u32 THISCALL hand_478780(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66723f);  // @h_478780
  volatile float v1c[3];
  u32 ebx = ecx_in;
  *(volatile u8 *)(ebx + 0x74e) = 0;  // @h1_478780
  if (*(u8 *)(ebx + 0x690) == 0) {  // @h2_478780
    u32 o = ext_41e290_cdecl1((u32)0x18);  // @h3_478780
    reg.state = 0;
    if (o) o = ext_476dc0_t1(o, 2);  // @h4_478780
    reg.state = -1;
    ext_43e920_f((u32)v1c, a1, a0);  // @h5_478780
    float x = v1c[0], y = v1c[1], z = v1c[2];
    float s2 = x * x;  // @h6_478780
    s2 = s2 + y * y;  // @h7_478780
    s2 = s2 + z * z;  // @h8_478780
    float f = (float)ext_634d7c_vc((double)s2);  // @h9_478780
    u32 blk = *(u32 *)(o + 0xc);
    *(volatile float *)(o + 4) = f;
    *(u32 *)blk = 0;  // @h10_478780
    blk = *(u32 *)(o + 0xc);
    *(volatile float *)(blk + 0x10) = f;  // @h11_478780
    blk = *(u32 *)(o + 0xc);
    *(u32 *)(blk + 4) = *(u32 *)a0;  // @h12_478780
    *(u32 *)(blk + 8) = *(u32 *)(a0 + 4);
    *(u32 *)(blk + 0xc) = *(u32 *)(a0 + 8);
    blk = *(u32 *)(o + 0xc);
    *(u32 *)(blk + 0x14) = *(u32 *)a1;  // @h13_478780
    *(u32 *)(blk + 0x18) = *(u32 *)(a1 + 4);
    *(u32 *)(blk + 0x1c) = *(u32 *)(a1 + 8);
    u32 n = ext_41e290_cdecl1((u32)0x20);  // @h14_478780
    *(u32 *)(n + 0x1c) = o;  // @h15_478780
    *(u32 *)(ebx + 0x691) = 1;  // @h16_478780
    *(u32 *)(n + 0x18) = 1;  // @h17_478780
    u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x5e4))(ebx, n);  // @h18_478780
    SEH_LEAVE();
    return r;
  }
  u32 esi = *(u32 *)(ebx + 0x5b2);
  if (esi == 0) {  // @h19_478780
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x68a7c4, 0x4fb);  // @h20_478780
    u32 r = ((u32(*)(u32, u32))VSLOT(L, 0x2c))(L, 0x68aad4);  // @h21_478780
    SEH_LEAVE();
    return r;
  }
  *(u32 *)(ebx + 0x691) = 0x12345678;  // @h22_478780
  u32 loc = 0;
  if (*(u8 *)(ebx + 0x6c4) != 0 && *(u8 *)(ebx + 0x6c3) == 0) loc = 1;  // @h23_478780
  u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 t = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))VSLOT(c, 0x4c))(c, ebx, a0, a1, 0, 0, 0, 0xcccccc00u | loc);  // @h24_478780
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x214))(esi, t);  // @h25_478780
  *(u32 *)(ebx + 0x691) = r;  // @h26_478780
  SEH_LEAVE();
  return r;
}
PCREG(478780, hand_478780);

extern "C" u32 THISCALL hand_4901f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ce8);  // @h_4901f0
  u8 S[0x24] __attribute__((aligned(16)));
  volatile u32 it[3];
  u32 edi = ecx_in;
  if (a0 == 0) {  // @h1_4901f0
    ext_4ccd10_t2((u32)S, 0x20, 0);  // @h2_4901f0
    reg.state = 0;
    ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x170))(edi, (u32)S);  // @h3_4901f0
    u32 vt = *(u32 *)S;
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x4c)))((u32)S, (u32)it);  // @h4_4901f0
    vt = *(u32 *)S;
    u32 r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)S, (u32)it);  // @h5_4901f0
    if (it[0] != 0) {  // @h6_4901f0
      do {
        ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x168))(edi, r);  // @h7_4901f0
        vt = *(u32 *)S;
        r = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)S, (u32)it);  // @h8_4901f0
      } while (it[0] != 0);  // @h9_4901f0
    }
    reg.state = -1;
    ext_4cd0e0_t0((u32)S);  // @h10_4901f0
  } else {
    u32 esi = ext_45e420_s1(0x46434c44);  // @h11_4901f0
    u32 t = *(u32 *)(esi + 4) & 0xc0000000u;  // @h12_4901f0
    u32 ebx = 8;
    if (t == 0x40000000u || t == 0x80000000u || t == 0xc0000000u) ebx = *(u32 *)(esi + 8);  // @h13_4901f0
    s32 count = (s32)ext_48db70_t0(esi);  // @h14_4901f0
    esi += ebx;
    if (count != 0) {  // @h15_4901f0
      u32 (*cmpf)(u32, u32) = (u32(*)(u32, u32))G(u32, 0x676414);
      float fc = (float)count;  // @h16_4901f0
      s32 i = 0;
      do {
        i++;
        float q = (float)i / fc;  // @h17_4901f0
        { volatile float ign = ((float(THISCALL *)(u32, u32, u32, float))VSLOT(edi, 0x90))(edi, 1, 0, q); (void)ign; }  // @h18_4901f0
        u32 len = 0;
        while (*(u8 *)(esi + len)) len++;
        if (cmpf(esi + len - 3, 0x68d8c0) != 0) {  // @h19_4901f0
          len = 0;
          while (*(u8 *)(esi + len)) len++;
          if (cmpf(esi + len - 3, 0x68d8c4) != 0) {  // @h20_4901f0
            ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x168))(edi, esi);  // @h21_4901f0
          }
        }
        len = 0;
        while (*(u8 *)(esi + len)) len++;
        esi += len + 1;  // @h22_4901f0
      } while (i != count);  // @h23_4901f0
    }
  }
  u32 ret = ((u32(THISCALL *)(u32))VSLOT(edi, 0xc0))(edi);  // @h24_4901f0
  SEH_LEAVE();
  return ret;
}
PCREG(4901f0, hand_4901f0);

extern "C" u32 THISCALL hand_4780f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6671fd);  // @h_4780f0
  u8 L[0xac] __attribute__((aligned(16)));
  volatile u32 it[3];
  volatile u32 vC0, vC4;
  u32 edi = ecx_in, rd = a0;
  ext_473370_t1(edi, rd);  // @h1_4780f0
  ext_4e11d0_t2(rd, edi + 0x5be, 1);  // @h2_4780f0
  ext_4e11d0_t2(rd, edi + 0x5c0, 1);  // @h3_4780f0
  ext_4ccba0_t0((u32)L);  // @h4_4780f0
  reg.state = 0;
  ext_4e0fd0_t1(rd, (u32)L);  // @h5_4780f0
  u32 cnt = ext_4cdd40_t0((u32)L);  // @h6_4780f0
  if (cnt != 0) {  // @h7_4780f0
    u32 o = ext_41e290_cdecl1((u32)0x1c);  // @h8_4780f0
    reg.state = 1;
    u32 r = 0;
    if (o) {
      u32 n = ext_4cdd40_t0((u32)L);  // @h9_4780f0
      r = ext_4ccbe0_t2(o, n, 0);  // @h10_4780f0
    }
    *(u32 *)(edi + 0x5ca) = r;  // @h11_4780f0
    reg.state = 0;
    u32 vt = *(u32 *)L;
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x4c)))((u32)L, (u32)it);  // @h12_4780f0
    vt = *(u32 *)L;
    u32 v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)L, (u32)it);  // @h13_4780f0
    if (it[0] != 0) {  // @h14_4780f0
      do {
        u32 ob = *(u32 *)(edi + 0x5ca);
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 4))(ob, v);  // @h15_4780f0
        vt = *(u32 *)L;
        v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)L, (u32)it);  // @h16_4780f0
      } while (it[0] != 0);  // @h17_4780f0
    }
  }
  ext_4e11e0_t2(rd, edi + 0x5c2, 1);  // @h18_4780f0
  if (*(u32 *)(edi + 0x5c2) == 0) {  // @h19_4780f0
    u32 m = G(u32, 0x700390);
    u32 L1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x68a7c4, 0x186);  // @h20_4780f0
    u32 ob = ((u32(THISCALL *)(u32))VSLOT(edi, 0x20))(edi);  // @h21_4780f0
    u32 name = *(u32 *)(ob + 4);
    if (name == 0) name = 0x67c8e8;  // @h22_4780f0
    ((u32(*)(u32, u32, u32))VSLOT(L1, 0x2c))(L1, 0x68a9a4, name);  // @h23_4780f0
  }
  ext_4e11e0_t2(rd, edi + 0x5c6, 1);  // @h24_4780f0
  ext_4e12e0_t2(rd, (u32)&vC0, 1);  // @h25_4780f0
  ext_4e12e0_t2(rd, (u32)&vC4, 1);  // @h26_4780f0
  ext_4e1b30_t0(rd);  // @h27_4780f0
  u32 x0 = vC0;
  if (x0 != 0) {  // @h28_4780f0
    u32 g = G(u32, 0x70039c);
    u32 ob = *(u32 *)(g + 0x1aa3);
    ob = *(u32 *)(ob + 0x18);
    u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0xc))(ob, x0);  // @h29_4780f0
    ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x5a4))(edi, q);  // @h30_4780f0
  }
  u32 x1 = vC4;
  if (x1 != 0) {  // @h31_4780f0
    u32 g = G(u32, 0x70039c);
    u32 ob = *(u32 *)(g + 0x1aa3);
    ob = *(u32 *)(ob + 0x18);
    u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0xc))(ob, x1);  // @h32_4780f0
    ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x5a4))(edi, q);  // @h33_4780f0
  }
  u32 ret = ext_4ccf60_t0((u32)L);  // @h34_4780f0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4780f0, hand_4780f0);

extern "C" u32 THISCALL hand_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 s9c[0x80] __attribute__((aligned(16)));
  u8 s11c[0x80] __attribute__((aligned(16)));
  volatile u32 slot120, f1, f2, f3, v1c, v18, v14;
  u32 ebx = ecx_in, rd = a0;
  slot120 = rd;
  ext_448a30_t1(ebx, rd);  // @h1_452bc0
  f1 = 1;  // @h2_452bc0
  f2 = 1;
  f3 = 0;
  volatile u32 f4 = 0;
  if ((u8)ext_4e1600_t1(rd) == 2) {  // @h3_452bc0
    u32 obj = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x20))(ebx);  // @h4_452bc0
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x681aa4, 0x3f);  // @h5_452bc0
    u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1d8))(obj, (u32)s9c, 1);  // @h6_452bc0
    reg.state = 0;
    u32 cs = ext_4cc1d0_t0(r1);  // @h7_452bc0
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x30))(L, 0x67f574, cs);  // @h8_452bc0
    reg.state = -1;
    ext_4cbec0_t0((u32)s9c);  // @h9_452bc0
    if ((u8)ext_4e1600_t1(rd) == 3) {  // @h10_452bc0
      ext_4e11e0_t3(rd, (u32)&slot120, 1);  // @h11_452bc0
    } else {
      obj = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x20))(ebx);  // @h12_452bc0
      m = G(u32, 0x700390);
      L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x681aa4, 0x44);  // @h13_452bc0
      r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1d8))(obj, (u32)s11c, 1);  // @h14_452bc0
      reg.state = 1;
      cs = ext_4cc1d0_t0(r1);  // @h15_452bc0
      ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x681ad4, cs);  // @h16_452bc0
      reg.state = -1;
      ext_4cbec0_t0((u32)s11c);  // @h17_452bc0
      ext_4e12f0_t2(rd, (u32)&v1c, 1);  // @h18_452bc0
      ext_4e12f0_t2(rd, (u32)&v18, 1);  // @h19_452bc0
      ext_4e12f0_t2(rd, (u32)&v14, 1);  // @h20_452bc0
    }
  }
  ext_4e11e0_t3(rd, (u32)&f1, 1);  // @h21_452bc0
  ext_4e11e0_t3(rd, (u32)&f2, 1);  // @h22_452bc0
  if ((u8)ext_4e1600_t1(rd) == 3) ext_4e11e0_t3(rd, (u32)&f3, 1);  // @h23_452bc0
  if ((u8)ext_4e1600_t1(rd) == 3) ext_4e11e0_t3(rd, (u32)&f4, 1);  // @h24_452bc0
  u32 fl = *(u32 *)(ebx + 0x18) & 0xffffcfffu;  // @h25_452bc0
  if (f1 != 0) fl |= 0x1000;  // @h26_452bc0
  if (f2 != 0) fl |= 0x2000;  // @h27_452bc0
  if (f3 != 0) fl |= 0x4000;  // @h28_452bc0
  if (f4 != 0) fl |= 0x8000;  // @h29_452bc0
  *(u32 *)(ebx + 0x18) = fl;
  u32 ret = ext_4e1b30_t1(rd);  // @h30_452bc0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(452bc0, hand_452bc0);

extern "C" u32 THISCALL hand_5c6f40(u32 ecx_in) {
  SEH_ENTER(0x66c75c);  // @h_5c6f40
  volatile u32 it[3];
  u32 ebx = ecx_in;
  u32 c = *(u32 *)(*(u32 *)(ebx + 0x44) + 0x18);  // @h1_5c6f40
  if (c != 0) {  // @h2_5c6f40
    ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, (u32)it);  // @h3_5c6f40
    c = *(u32 *)(*(u32 *)(ebx + 0x44) + 0x18);
    u32 edi = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x5c))(c, (u32)it);  // @h4_5c6f40
    if (it[0] != 0) {  // @h5_5c6f40
      do {
        u32 s = ext_41e290_cdecl1((u32)0x2d);  // @h6_5c6f40
        *(u32 *)s = edi;  // @h7_5c6f40
        u32 c2 = *(u32 *)(G(u32, 0x70039c) + 0x9b);
        u32 ent = ((u32(THISCALL *)(u32, u32))VSLOT(c2, 0x58))(c2, edi);  // @h8_5c6f40
        *(u32 *)(s + 0x1c) = ent;  // @h9_5c6f40
        float f1 = ((float(THISCALL *)(u32))VSLOT(ent, 0x248))(ent);  // @h10_5c6f40
        ent = *(u32 *)(s + 0x1c);
        *(volatile float *)(s + 0x18) = f1;  // @h11_5c6f40
        float f2 = ((float(THISCALL *)(u32))VSLOT(ent, 0x240))(ent);  // @h12_5c6f40
        *(volatile float *)(s + 0x14) = f2 * *(float *)(ebx + 0x71);  // @h13_5c6f40
        u32 o = ext_41e290_cdecl1((u32)0x1c);  // @h14_5c6f40
        reg.state = 0;
        u32 r = 0;
        if (o) r = ext_4ccbe0_t2(o, 1, 0);  // @h15_5c6f40
        reg.state = -1;
        *(u32 *)(s + 4) = r;  // @h16_5c6f40
        o = ext_41e290_cdecl1((u32)0x1c);  // @h17_5c6f40
        reg.state = 1;
        r = 0;
        if (o) r = ext_4ccbe0_t2(o, 1, 0);  // @h18_5c6f40
        reg.state = -1;
        *(u32 *)(s + 0xc) = r;  // @h19_5c6f40
        o = ext_41e290_cdecl1((u32)0x1c);  // @h20_5c6f40
        reg.state = 2;
        r = 0;
        if (o) r = ext_4ccbe0_t2(o, 1, 0);  // @h21_5c6f40
        reg.state = -1;
        *(u32 *)(s + 8) = r;  // @h22_5c6f40
        o = ext_41e290_cdecl1((u32)0x1c);  // @h23_5c6f40
        reg.state = 3;
        r = 0;
        if (o) r = ext_4ccbe0_t2(o, 1, 0);  // @h24_5c6f40
        reg.state = -1;
        *(u32 *)(s + 0x10) = r;  // @h25_5c6f40
        *(u32 *)(s + 0x20) = 0;
        *(volatile u8 *)(s + 0x2c) = 0;  // @h26_5c6f40
        *(u32 *)(s + 0x24) = 0;
        *(u32 *)(s + 0x28) = 0;  // @h27_5c6f40
        ext_5c7570_t1(ebx, s);  // @h28_5c6f40
        u32 h = *(u32 *)(ebx + 0x60);
        ((u32(THISCALL *)(u32, u32))VSLOT(h, 4))(h, s);  // @h29_5c6f40
        c = *(u32 *)(*(u32 *)(ebx + 0x44) + 0x18);
        edi = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x5c))(c, (u32)it);  // @h30_5c6f40
      } while (it[0] != 0);  // @h31_5c6f40
    }
  }
  u32 a = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 c3 = *(u32 *)(a + 0xadc);  // @h32_5c6f40
  u32 rr = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c3, 0x25c))(c3, 0x685f44, 0);  // @h33_5c6f40
  *(u32 *)(ebx + 0x48) = rr;  // @h34_5c6f40
  a = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 hh = ((u32(THISCALL *)(u32))VSLOT(a, 0x138))(a);  // @h35_5c6f40
  a = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 r2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(a, 0x4c))(a, *(u32 *)(ebx + 0x44), 0x10);  // @h36_5c6f40
  u32 ret = ((u32(THISCALL *)(u32, u32, u32))VSLOT(hh, 0x60))(hh, 0x6b43a0, r2);  // @h37_5c6f40
  SEH_LEAVE();
  return ret;
}
PCREG(5c6f40, hand_5c6f40);

extern "C" u32 THISCALL hand_483b60(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6675ab);  // @h_483b60
  float v4c[9] __attribute__((aligned(16)));
  float v70[9] __attribute__((aligned(16)));
  float v2148[3] __attribute__((aligned(16)));
  float v1c[3] __attribute__((aligned(16)));
  float v28[3] __attribute__((aligned(16)));
  float v213c[3] __attribute__((aligned(16)));
  u8 L[0xac] __attribute__((aligned(16)));
  u32 list[0x800];
  u32 self = ecx_in, esi = a0, edi = a1;
  u32 best_obj = 0;
  float best = G(float, 0x67cd44);  // @h1_483b60
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(self, 0x384))(self, (u32)v4c, (u32)v1c);  // @h2_483b60
  ext_441970_f((u32)v2148, esi, (u32)v4c);  // @h3_483b60
  ext_441940_f((u32)v1c, (u32)v2148);  // @h4_483b60
  ext_4ccba0_t0((u32)L);  // @h5_483b60
  reg.state = 0;
  u32 g = G(u32, 0x70039c);
  u32 q = *(u32 *)(*(u32 *)(g + 0x1aa3) + 0x1c);  // @h6_483b60
  u32 n = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))VSLOT(q, 0x38))(q, (u32)list, (u32)v70, 3, (u32)v4c, (u32)v1c, edi, 2, 0, 1, 1);  // @h7_483b60
  for (u32 i = 0; i != n; i++) {  // @h8_483b60
    u32 ob = list[i];
    u32 e = *(u32 *)(ob + 0x54);  // @h9_483b60
    if (e == 0) continue;
    if ((u8)((u32(THISCALL *)(u32, u32))VSLOT(e, 0x1e0))(e, 0x100001) == 0) continue;  // @h10_483b60
    u32 f = ((u32(THISCALL *)(u32, u32, u32))VSLOT(e, 0x25c))(e, 0x6858e0, 0);  // @h11_483b60
    if (f == 0) continue;
    if ((u8)((u32(THISCALL *)(u32, u32))VSLOT(f, 0x1e0))(f, 0x2007d0) == 0) continue;  // @h12_483b60
    if (((u32(THISCALL *)(u32))VSLOT(f, 0x588))(f) == 0) continue;  // @h13_483b60
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(f, 0x384))(f, (u32)v70, (u32)v28);  // @h14_483b60
    ext_43e920_f((u32)v213c, (u32)v28, (u32)v1c);  // @h15_483b60
    ext_4419f0_f((u32)v213c, (u32)v4c);  // @h16_483b60
    const float *lim = (const float *)edi;
    if (__builtin_fabsf(v213c[0]) > lim[0]) continue;  // @h17_483b60
    if (__builtin_fabsf(v213c[1]) > lim[1]) continue;  // @h18_483b60
    if (__builtin_fabsf(v213c[2]) > lim[2]) continue;  // @h19_483b60
    float d = ext_4e0870_f((u32)v1c, (u32)v28);  // @h20_483b60
    if (best > d) {  // @h21_483b60
      u32 gg = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      best_obj = ((u32(THISCALL *)(u32, u32))VSLOT(gg, 0x4c))(gg, f);  // @h22_483b60
      best = d;
    }
  }
  ext_4ccf60_t0((u32)L);  // @h23_483b60
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return best_obj;
}
PCREG(483b60, hand_483b60);

extern "C" u32 THISCALL hand_595570(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66ba81);  // @h_595570
  u8 T[0x40c4] __attribute__((aligned(16)));
  u8 s90[0x80] __attribute__((aligned(16)));
  volatile u32 v4158;
  u32 edi = ecx_in, ebx = a0;
  u32 eax = 0;
  if (ebx == *(u32 *)(edi + 0x688)) {  // @h1_595570
    u32 S = edi + 0x698;
    if (ebx == 0) {  // @h2_595570
      eax = ext_4cc5f0_t0(S);  // @h3_595570
      if (eax == 0) {  // @h4_595570
        SEH_LEAVE();
        ext_633654(G(u32, 0x6f5630));
        return eax;
      }
    } else {
      u32 esi = *(u32 *)(ebx + 0x7a);  // @h5_595570
      u32 cs = ext_4cc1d0_t0(S);
      eax = ((u32(*)(u32, u32))G(u32, 0x676414))(esi, cs);  // @h6_595570
      if (eax == 0) {  // @h7_595570
        SEH_LEAVE();
        ext_633654(G(u32, 0x6f5630));
        return eax;
      }
    }
  }
  ext_4d2280_t0((u32)T);  // @h8_595570
  reg.state = 0;
  u32 gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 h = ((u32(THISCALL *)(u32))VSLOT(gb, 0x138))(gb);  // @h9_595570
  v4158 = 0;
  eax = ((u32(THISCALL *)(u32, u32, u32))VSLOT(h, 0x88))(h, 0x68be98, (u32)&v4158);  // @h10_595570
  u32 S = edi + 0x698;
  u32 esi = S;
  if (ext_4cc1d0_t0(S) != 0 && *(u8 *)ext_4cc1d0_t0(S) != 0) {  // @h11_595570
    u32 cs = ext_4cc1d0_t0(S);
    ext_4d3a00_t3((u32)T, 0x6acb50, cs, 0xc);  // @h12_595570
    u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    u32 v = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x6acb60, 0, 0x6ac6d0, 0x918, (u32)T);  // @h13_595570
    eax = ((u32(THISCALL *)(u32, u32, u32))VSLOT(edi, 0x12c))(edi, v4158, v & 0xffff);  // @h14_595570
  }
  if (ebx == 0) {  // @h15_595570
    ext_4cbe80_t1((u32)s90, 0x677b5a);  // @h16_595570
    reg.state = 2;
    ext_4cbee0_t1(S, (u32)s90);  // @h17_595570
    eax = ext_4cbec0_t0((u32)s90);  // @h18_595570
  } else {
    ext_4d39a0_t2((u32)T, 0x6acb50, *(u32 *)(ebx + 0x7a));  // @h19_595570
    u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    u32 hh = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, edi);  // @h20_595570
    ext_4d3ad0_t3((u32)T, 0x6acb74, hh, 4);  // @h21_595570
    u32 r41 = ext_41e680_t0(ebx);  // @h22_595570
    ext_4d3a00_t3((u32)T, 0x6acb80, r41, 5);  // @h23_595570
    ext_4d3ad0_t3((u32)T, 0x6acb88, (u32)*(u16 *)(edi + 0x165), 0x12);  // @h24_595570
    ext_4d3ad0_t3((u32)T, 0x6acb94, *(u32 *)(ebx + 0x52), 2);  // @h25_595570
    ext_4cbe80_t1((u32)s90, *(u32 *)(ebx + 0x7a));  // @h26_595570
    reg.state = 1;
    ext_4cbee0_t1(S, (u32)s90);  // @h27_595570
    reg.state = 0;
    ext_4cbec0_t0((u32)s90);  // @h28_595570
    c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    u32 v = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(c, 0x114))(c, 0x6acb9c, 0, 0x6ac6d0, 0x926, (u32)T);  // @h29_595570
    eax = ((u32(THISCALL *)(u32, u32, u32))VSLOT(edi, 0x12c))(edi, v4158, v & 0xffff);  // @h30_595570
  }
  *(u32 *)(edi + 0x688) = ebx;  // @h31_595570
  eax = ext_4d2330_t0((u32)T);  // @h32_595570
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(595570, hand_595570);

extern "C" u32 THISCALL hand_5f9be0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d20f);  // @h_5f9be0
  volatile u8 tmpb;
  u32 edi = ecx_in;
  u32 V = *(u32 *)(edi + 4);
  u32 keylen = 0;
  while (*(u8 *)(a0 + keylen)) keylen++;  // @h1_5f9be0
  for (u32 ebx = 0; ebx < *(u32 *)(V + 0x14); ebx++) {  // @h2_5f9be0
    u32 s = *(u32 *)(*(u32 *)(V + 0xc) + ebx * 4);
    u32 begin = *(u32 *)s;
    u32 slen = *(u32 *)(s + 4) - begin;  // @h3_5f9be0
    if (slen != keylen) continue;  // @h4_5f9be0
    u32 i = 0;
    while (i < slen && *(u8 *)(begin + i) == *(u8 *)(a0 + i)) i++;  // @h5_5f9be0
    if (i == slen) {  // @h6_5f9be0
      SEH_LEAVE();
      return ebx;
    }
  }
  u32 p = ext_41e290_cdecl1((u32)0xc);  // @h7_5f9be0
  reg.state = 0;
  u32 ns = 0;
  if (p) ns = ext_42b390_t2(p, a0, (u32)&tmpb);  // @h8_5f9be0
  reg.state = -1;
  V = *(u32 *)(edi + 4);
  u32 cap = *(u32 *)(V + 0x10);
  if (*(u32 *)(V + 0x14) >= cap) {  // @h9_5f9be0
    u32 old = *(u32 *)(V + 0xc);
    u32 ncap = cap + cap;  // @h10_5f9be0
    u64 bytes = (u64)ncap * 4;
    u32 nb = ext_41e290_cdecl1((u32)bytes | ((bytes >> 32) ? 0xffffffffu : 0u));  // @h11_5f9be0
    *(u32 *)(V + 0xc) = nb;
    for (u32 j = 0; j < *(u32 *)(V + 0x10); j++) *(u32 *)(nb + j * 4) = *(u32 *)(old + j * 4);  // @h12_5f9be0
    ext_41e2c0_c1(old);  // @h13_5f9be0
    *(u32 *)(V + 0x10) = ncap;  // @h14_5f9be0
  }
  u32 sz = *(u32 *)(V + 0x14);
  *(u32 *)(*(u32 *)(V + 0xc) + sz * 4) = ns;  // @h15_5f9be0
  *(u32 *)(V + 0x14) = sz + 1;
  u32 ret = *(u32 *)(*(u32 *)(edi + 4) + 0x14) - 1;  // @h16_5f9be0
  SEH_LEAVE();
  return ret;
}
PCREG(5f9be0, hand_5f9be0);

extern "C" u32 THISCALL hand_5bd630(u32 ecx_in) {
  SEH_ENTER(0x66c831);  // @h_5bd630
  u32 esi = ecx_in;
  reg.state = 0;
  if (esi == 0) {  // @h1_5bd630
    SEH_LEAVE();
    return 0;
  }
  ext_469870_t0(esi);  // @h2_5bd630
  W32(esi, 4, *(u32 *)(esi + 4) | 0x20);  // @h3_5bd630
  W32(esi, 0x44, 0);  // @h4_5bd630
  W32(esi, 0, 0x6b33b4);  // @h5_5bd630
  for (int i = 0; i < 8; i++) W32(esi, 0x48 + 4 * i, 0);  // @h6_5bd630
  W32(esi, 0x68, 0);  // @h7_5bd630
  W32(esi, 0x6c, 0);  // @h8_5bd630
  W32(esi, 0x70, 0xffffffff);  // @h9_5bd630
  W32(esi, 0x7d, 0);  // @h10_5bd630
  SEH_LEAVE();
  return esi;
}
PCREG(5bd630, hand_5bd630);

extern "C" u32 THISCALL hand_46a5e0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_46a5e0
  u32 esi = ecx_in;
  W32(esi, 0, 0x6872ac);  // @h1_46a5e0
  u32 a = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 ent = ((u32(THISCALL *)(u32, u32))VSLOT(a, 0x58))(a, *(u32 *)(esi + 0xed));  // @h2_46a5e0
  if (ent != 0) ((u32(THISCALL *)(u32, u32))VSLOT(ent, 0x210))(ent, 1);  // @h3_46a5e0
  u32 o = *(u32 *)(esi + 0xd9);
  if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 0))(o, 1);  // @h4_46a5e0
  u32 g = G(u32, 0x70039c);
  ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x1a8))(g, *(u32 *)(esi + 0x9e));  // @h5_46a5e0
  u32 p = *(u32 *)(esi + 0x9e);
  if (p != 0) ((u32(THISCALL *)(u32, u32))VSLOT(p, 0))(p, 1);  // @h6_46a5e0
  u32 ret = ext_46a4f0_t0(esi);  // @h7_46a5e0
  SEH_LEAVE();
  return ret;
}
PCREG(46a5e0, hand_46a5e0);

extern "C" u32 THISCALL hand_4b1320(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_4b1320
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 edi = ecx_in, rd = a0;
  W32(edi, 0x48, ext_4e5e60_t0(rd));  // @h1_4b1320
  W32(edi, 0x50, ext_4e5e60_t0(rd));  // @h2_4b1320
  u32 f = ext_4e5e60_t0(rd);  // @h3_4b1320
  *(volatile u8 *)(edi + 0x54) = (f != 0) ? 1 : 0;  // @h4_4b1320
  u32 p = ext_4e5ea0_t0(rd);  // @h5_4b1320
  u32 ret = p;
  if (p != 0 && *(u8 *)p != 0) {  // @h6_4b1320
    ext_4cbe80_t1((u32)s90, p);  // @h7_4b1320
    reg.state = 0;
    ext_4cbee0_t1(edi + 0x55, (u32)s90);  // @h8_4b1320
    ret = ext_4cbec0_t0((u32)s90);  // @h9_4b1320
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4b1320, hand_4b1320);

extern "C" u32 THISCALL hand_4bb830(u32 ecx_in, u32 a0, u32 rd) {
  SEH_ENTER(0x66976b);  // @h_4bb830
  u8 s90[0x80] __attribute__((aligned(16)));
  u32 g = G(u32, 0x70039c);
  u32 ret = g;
  if (*(u32 *)(g + 0x1a9f) != 0) {  // @h1_4bb830
    u32 ebx = 1;
    u32 name = ext_4e5ea0_t0(rd);  // @h2_4bb830
    ext_4cbe80_t1((u32)s90, name);  // @h3_4bb830
    reg.state = 0;
    u32 e = *(u32 *)(G(u32, 0x70039c) + 0x1a9f);
    u32 cs = ext_4cc1d0_t0((u32)s90);  // @h4_4bb830
    u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x6c))(*(u32 *)(G(u32, 0x70039c) + 0x1a9f), cs);  // @h5_4bb830
    float f = ext_4e5e80_f(rd);  // @h6_4bb830
    u8 b = **(u8 **)rd;  // @h7_4bb830
    if (b != 0xff && (b & 0x3f) == 3) ebx = ext_4e5e60_t0(rd);  // @h8_4bb830
    u32 c = *(u32 *)(*(u32 *)(G(u32, 0x70039c) + 0x9b) + 0xadc);  // @h9_4bb830
    u32 r1 = ext_43eb80_t1(c, esi);  // @h10_4bb830
    u32 m = *(u32 *)(G(u32, 0x70039c) + 0x9b);
    u32 ent = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x60))(m, r1);  // @h11_4bb830
    if (ent != 0) {  // @h12_4bb830
      *(volatile float *)(ent + 0x88) = f;  // @h13_4bb830
      if (ebx != 0) *(u32 *)(ent + 0x40) |= 8;  // @h14_4bb830
      else *(u32 *)(ent + 0x40) &= 0xfffffff7u;  // @h15_4bb830
      *(u32 *)(ent + 0x40) |= 0x80;  // @h16_4bb830
      *(u32 *)(ent + 0x2c) = 3;  // @h17_4bb830
    }
    ret = ext_4cbec0_t0((u32)s90);  // @h18_4bb830
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4bb830, hand_4bb830);

extern "C" u32 THISCALL hand_4a1460(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668522);  // @h_4a1460
  u32 edi = ecx_in, rd = a0;
  W32(edi, 4, *(u32 *)(edi + 4) & 0xffffffbfu);  // @h1_4a1460
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x44))(rd, edi + 0x8b0);  // @h2_4a1460
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x44))(rd, edi + 0x8b2);  // @h3_4a1460
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x48))(rd, edi + 0x48);  // @h4_4a1460
  s32 i = 0;
  if ((s32)*(u32 *)(edi + 0x48) > 0) {  // @h5_4a1460
    u32 p = edi + 0x4c;
    do {
      u32 o = ext_41e290_cdecl1((u32)0x844);  // @h6_4a1460
      reg.state = 0;
      if (o != 0) {  // @h7_4a1460
        for (int k = 0; k < 4; k++) {
          W32(o, 0x804 + 4 * k, G(u32, 0x67a290 + 4 * k));  // @h8_4a1460
          W32(o, 0x814 + 4 * k, G(u32, 0x67a290 + 4 * k));  // @h9_4a1460
        }
        for (int k = 0; k < 4; k++) {
          W32(o, 0x824 + 4 * k, G(u32, 0x68f920 + 4 * k));  // @h10_4a1460
          W32(o, 0x834 + 4 * k, G(u32, 0x68f920 + 4 * k));  // @h11_4a1460
        }
        u32 gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
        u32 h = ((u32(THISCALL *)(u32))VSLOT(gb, 0x138))(gb);  // @h12_4a1460
        volatile u32 out = 0;
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(h, 0x88))(h, 0x681320, (u32)&out);  // @h13_4a1460
        W32(o, 0, out);  // @h14_4a1460
      }
      reg.state = -1;
      W32(p, 0x10, o);  // @h15_4a1460
      ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x40))(rd, o);  // @h16_4a1460
      i++;
      W32(p, 0, 0);  // @h17_4a1460
      p += 4;
    } while (i < (s32)*(u32 *)(edi + 0x48));  // @h18_4a1460
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x40))(rd, edi + 0x6c);  // @h19_4a1460
  G(u32, 0x7002a8) = 0;  // @h20_4a1460
  SEH_LEAVE();
  return 1;
}
PCREG(4a1460, hand_4a1460);

extern "C" u32 THISCALL hand_4b56b0(u32 ecx_in) {
  SEH_ENTER(0x6685bb);  // @h_4b56b0
  u8 s90[0x80] __attribute__((aligned(16)));
  volatile u32 v94;
  u32 ebx = ecx_in;
  u32 gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 h = ((u32(THISCALL *)(u32))VSLOT(gb, 0x138))(gb);  // @h1_4b56b0
  v94 = 0;
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(h, 0x88))(h, 0x688f80, (u32)&v94);  // @h2_4b56b0
  W32(ebx, 0x8c, v94);  // @h3_4b56b0
  s32 i = 0;
  if ((s32)*(u32 *)(ebx + 0xee) > 0) {  // @h4_4b56b0
    do {
      u32 edi = ext_4b5620_t1(ebx, (u32)i);  // @h5_4b56b0
      if (edi != 0) {  // @h6_4b56b0
        u32 o = *(u32 *)(ebx + 0x44);
        v94 = 0;
        ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o, 0x130))(o, edi, (u32)*(u16 *)(ebx + 0x56), (u32)&v94);  // @h7_4b56b0
        u32 pp = v94;
        u32 nm = *(u32 *)(edi + 4);
        if (nm == 0) nm = 0x67c8e8;  // @h8_4b56b0
        if (pp == 0) {  // @h9_4b56b0
          u32 m = G(u32, 0x700390);
          u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x691edc, 0x206);  // @h10_4b56b0
          ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x692080, nm);  // @h11_4b56b0
        } else {
          float f = *(float *)(pp + 4);
          if (f > *(float *)(ebx + 0xde)) *(volatile float *)(ebx + 0xde) = f;  // @h12_4b56b0
          const u8 *a = (const u8 *)nm, *b = (const u8 *)0x6920a8;
          while (*a == *b && *a != 0) { a++; b++; }  // @h13_4b56b0
          if (*a == *b) W32(ebx, 0xde, 0);  // @h14_4b56b0
        }
      }
      i++;
    } while (i < (s32)*(u32 *)(ebx + 0xee));  // @h15_4b56b0
  }
  if (*(u8 *)(ebx + 0x9b) != 0) {  // @h16_4b56b0
    u32 m = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x20))(m, 0x691edc, 0x216);  // @h17_4b56b0
    u32 o = *(u32 *)(ebx + 0x44);
    u32 r1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x1dc))(o, (u32)s90, 1);  // @h18_4b56b0
    reg.state = 0;
    u32 cs = ext_4cc1d0_t0(r1);  // @h19_4b56b0
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x6920bc, cs);  // @h20_4b56b0
    reg.state = -1;
    ext_4cbec0_t0((u32)s90);  // @h21_4b56b0
    o = *(u32 *)(ebx + 0x44);
    W32(ebx, 4, *(u32 *)(ebx + 4) | 8);  // @h22_4b56b0
    *(volatile u16 *)(ebx + 0x9b) = 0x100;  // @h23_4b56b0
    ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(o, 0x124))(o, 2, 0, 0, 0);  // @h24_4b56b0
    o = *(u32 *)(ebx + 0x44);
    ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o, 0x130))(o, o, (u32)*(u16 *)(ebx + 0x4e), 0);  // @h25_4b56b0
  }
  u32 ret = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x8c))(ebx);  // @h26_4b56b0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4b56b0, hand_4b56b0);

extern "C" u32 THISCALL hand_4fe9e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b4b);  // @h_4fe9e0
  u8 W[0x13c] __attribute__((aligned(16)));
  u32 self = ecx_in, rd = a0;
  W32(self, 4, *(u32 *)(self + 4) & 0xffffffbfu);  // @h1_4fe9e0
  ((u32(THISCALL *)(u32))VSLOT(self, 8))(self);  // @h2_4fe9e0
#define OUT(off, n) ((u32(THISCALL *)(u32, u32, u32))VSLOT(rd, 0x18))(rd, self + (off), (n))
  OUT(0x48, 1);  // @h3_4fe9e0
  OUT(0x5f, 4);  // @h4_4fe9e0
  OUT(0x63, 4);  // @h5_4fe9e0
  OUT(0x67, 1);  // @h6_4fe9e0
  OUT(0x68, 4);  // @h7_4fe9e0
  OUT(0x6c, 4);  // @h8_4fe9e0
  OUT(0x70, 4);  // @h9_4fe9e0
  OUT(0xe4, 4);  // @h10_4fe9e0
  OUT(0xe8, 4);  // @h11_4fe9e0
#undef OUT
  for (int k = 0; k < 8; k++) *(u32 *)(W + 4 + 4 * k) = *(u32 *)(rd + 4 + 4 * k);  // @h12_4fe9e0
  u32 last = *(u32 *)(rd + 0x138);
  *(u32 *)W = 0x68e9cc;  // @h13_4fe9e0
  for (int k = 0; k < 0x45; k++) *(u32 *)(W + 0x24 + 4 * k) = *(u32 *)(rd + 0x24 + 4 * k);  // @h14_4fe9e0
  *(u32 *)(W + 0x138) = last;  // @h15_4fe9e0
  reg.state = 0;
  ext_4999c0_t1((u32)W, self + 0x49);  // @h16_4fe9e0
  u32 vt = *(u32 *)W;
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x44)))((u32)W, self + 0x4b);  // @h17_4fe9e0
  vt = *(u32 *)W;
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x44)))((u32)W, self + 0x4d);  // @h18_4fe9e0
  vt = *(u32 *)W;
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x44)))((u32)W, self + 0x4f);  // @h19_4fe9e0
  u32 gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 h = ((u32(THISCALL *)(u32))VSLOT(gb, 0x138))(gb);  // @h20_4fe9e0
  gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 v = ((u32(THISCALL *)(u32, u32, u32))VSLOT(gb, 0x4c))(gb, *(u32 *)(self + 0x44), 0x10);  // @h21_4fe9e0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(h, 0x60))(h, 0x69268c, v);  // @h22_4fe9e0
  W32(self, 0xd4, 0);  // @h23_4fe9e0
  W32(self, 0xd8, 0);
  W32(self, 0xdc, 0);
  W32(self, 0xe0, 0);  // @h24_4fe9e0
  ext_499970_t0((u32)W);  // @h25_4fe9e0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 1;
}
PCREG(4fe9e0, hand_4fe9e0);

extern "C" u32 THISCALL hand_5ebbd0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5ebbd0
  u32 edi = ecx_in;
  u32 esi = *(u32 *)(edi + 0x62);  // @h1_5ebbd0
  W32(edi, 0, 0x6b80f4);  // @h2_5ebbd0
  while (esi != *(u32 *)(edi + 0x66)) {  // @h3_5ebbd0
    ext_634273_cdecl2(*(u32 *)esi, 0x2c);  // @h4_5ebbd0
    esi += 4;
  }
  u32 h = *(u32 *)(edi + 0x3a);
  ext_634273_cdecl2(*(u32 *)(h + 4), 0x28);  // @h5_5ebbd0
  ext_634273_cdecl2(*(u32 *)(edi + 0x3a), 8);  // @h6_5ebbd0
  u32 ecx = *(u32 *)(edi + 0x62);
  s32 n = (s32)(*(u32 *)(edi + 0x6a) - ecx) >> 2;  // @h7_5ebbd0
  reg.state = 0;
  u32 ret = 0;
  if (n != 0)  // @h8_5ebbd0
    ret = ext_54f870_t2(edi + 0x62, ecx, (u32)n << 2);  // @h9_5ebbd0
  W32(edi, 0, 0x6b01dc);  // @h10_5ebbd0
  SEH_LEAVE();
  return ret;
}
PCREG(5ebbd0, hand_5ebbd0);

extern "C" u32 THISCALL hand_45cb50(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666666);  // @h_45cb50
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 esi = ecx_in, edi = a0;
  u32 edx = *(u32 *)(*(u32 *)(esi + 8) + 0x50);  // @h1_45cb50
  if (edx != 0) {  // @h2_45cb50
    bool go = true;
    if ((u8)a1 == 0) {  // @h3_45cb50
      u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      if (*(u32 *)(edx + 0x54) == *(u32 *)(c + 0xadc)) go = false;  // @h4_45cb50
    }
    if (go) {
      u32 t = *(u32 *)(edx + 0x54);
      ((u32(THISCALL *)(u32, u32, u32))VSLOT(t, 0x1d4))(t, edi, a1);  // @h5_45cb50
      ext_4cbe80_t1((u32)s90, 0x67856c);  // @h6_45cb50
      reg.state = 0;
      ext_4cc2c0_t1(edi, (u32)s90);  // @h7_45cb50
      reg.state = -1;
      ext_4cbec0_t0((u32)s90);  // @h8_45cb50
    }
  }
  ext_4cbe80_t1((u32)s110, *(u32 *)(esi + 4));  // @h9_45cb50
  reg.state = 1;
  ext_4cc2c0_t1(edi, (u32)s110);  // @h10_45cb50
  u32 ret = ext_4cbec0_t0((u32)s110);  // @h11_45cb50
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(45cb50, hand_45cb50);

extern "C" u32 THISCALL hand_430010(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66528c);  // @h_430010
  u32 self = ecx_in;
  u32 esi = a0;
  while (esi != 0) {  // @h1_430010
    hand_430010(self, *(u32 *)(esi + 9));  // @h2_430010
    u32 next = *(u32 *)(esi + 5);  // @h3_430010
    u32 c = esi + 0x19;
    u32 b = *(u32 *)c;
    u32 n = *(u32 *)(c + 8) - b;  // @h4_430010
    reg.state = 0;
    if (b != 0 && n != 0) ext_54f870_t2(c, b, n);  // @h5_430010
    b = *(u32 *)(esi + 0xd);
    n = *(u32 *)(esi + 0x15) - b;  // @h6_430010
    reg.state = 1;
    if (b != 0 && n != 0) ext_54f870_t2(esi + 0xd, b, n);  // @h7_430010
    reg.state = -1;
    ext_54f870_t2(self, esi, 0x25);  // @h8_430010
    esi = next;
  }
  SEH_LEAVE();
  return self;
}
PCREG(430010, hand_430010);

extern "C" u32 THISCALL hand_4385e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66606f);  // @h_4385e0
  u32 esi = ecx_in;
  if (*(u32 *)(esi + 0x3e) == 0) {  // @h1_4385e0
    u32 o = ext_41e290_cdecl1((u32)0x1c);  // @h2_4385e0
    reg.state = 0;
    u32 r = 0;
    if (o) r = ext_4ccbe0_t2(o, 2, 2);  // @h3_4385e0
    reg.state = -1;
    W32(esi, 0x3e, r);  // @h4_4385e0
  }
  u32 h = *(u32 *)(esi + 0x3e);
  u32 edi = ((u32(THISCALL *)(u32, u32))VSLOT(h, 4))(h, 0);  // @h5_4385e0
  u32 len = 0;
  while (*(u8 *)(a0 + len)) len++;
  u32 buf = ext_41e290_cdecl1(len + 1);  // @h6_4385e0
  *(u32 *)(edi - 4) = buf;  // @h7_4385e0
  u32 i = 0;
  for (;;) { u8 ch = *(u8 *)(a0 + i); *(u8 *)(buf + i) = ch; i++; if (!ch) break; }  // @h8_4385e0
  *(u8 *)(edi + 4) = (u8)a1;  // @h9_4385e0
  W32(edi, 0, 0);  // @h10_4385e0
  SEH_LEAVE();
  return ((buf + i) & 0xffffff00u) | (a1 & 0xff);
}
PCREG(4385e0, hand_4385e0);

extern "C" u32 THISCALL hand_4d1530(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4d1530
  u32 esi = ecx_in;
  u32 a = *(u32 *)(esi + 0x14);
  W32(esi, 0, 0x695f78);  // @h1_4d1530
  if (a != 0) {  // @h2_4d1530
    ext_634273_cdecl2(a, 4);  // @h3_4d1530
    W32(esi, 0x14, 0);  // @h4_4d1530
  }
  a = *(u32 *)(esi + 0xc);
  W32(esi, 0x10, 0);  // @h5_4d1530
  if (a != 0) ext_634273_cdecl2(a, 4);  // @h6_4d1530
  while (*(u32 *)(esi + 0x24) != 0) {  // @h7_4d1530
    u32 o = *(u32 *)(esi + 0x24);
    ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x14))(o, 1);  // @h8_4d1530
  }
  u32 ret = ext_4d2030_t1(esi, (u32)-1);  // @h9_4d1530
  u32 ec = *(u32 *)(esi + 0x2c);
  if (ec != 0) {  // @h10_4d1530
    u32 edx = *(u32 *)(esi + 0x34);
    u32 eax = *(u32 *)(esi + 0x30);
    if (edx != 0) W32(edx, 0x30, eax);  // @h11_4d1530
    else W32(ec, 0x24, eax);  // @h12_4d1530
    u32 c2 = *(u32 *)(esi + 0x30);
    eax = *(u32 *)(esi + 0x34);
    if (c2 != 0) W32(c2, 0x34, eax);  // @h13_4d1530
    else { u32 c3 = *(u32 *)(esi + 0x2c); W32(c3, 0x28, eax); }  // @h14_4d1530
    W32(esi, 0x30, 0);  // @h15_4d1530
    W32(esi, 0x34, 0);  // @h16_4d1530
    ret = eax;
  }
  SEH_LEAVE();
  return ret;
}
PCREG(4d1530, hand_4d1530);

extern "C" u32 THISCALL hand_4c90a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_4c90a0
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 ebx = ecx_in, rd = a1;
  ext_4cbe80_t1((u32)s90, *(u32 *)(*(u32 *)(ebx + 0x44) + 4));  // @h1_4c90a0
  reg.state = 0;
  u8 b = **(u8 **)rd;  // @h2_4c90a0
  if (b != 0xff && (b & 0x3f) == 4) {  // @h3_4c90a0
    u32 nm = ext_4e5ea0_t0(rd);  // @h4_4c90a0
    ext_4cbe80_t1((u32)s110, nm);  // @h5_4c90a0
    reg.state = 1;
    ext_4cbee0_t1((u32)s90, (u32)s110);  // @h6_4c90a0
    reg.state = 0;
    ext_4cbec0_t0((u32)s110);  // @h7_4c90a0
  }
  u32 gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 h = ((u32(THISCALL *)(u32))VSLOT(gb, 0x138))(gb);  // @h8_4c90a0
  gb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 v = ((u32(THISCALL *)(u32, u32, u32))VSLOT(gb, 0x4c))(gb, *(u32 *)(ebx + 0x44), 2);  // @h9_4c90a0
  u32 cs = ext_4cc1d0_t0((u32)s90);  // @h10_4c90a0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(h, 0x60))(h, cs, v);  // @h11_4c90a0
  ((u32(THISCALL *)(u32))VSLOT(ebx, 0x58))(ebx);  // @h12_4c90a0
  u32 ret = ext_4cbec0_t0((u32)s90);  // @h13_4c90a0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(4c90a0, hand_4c90a0);

extern "C" u32 THISCALL hand_4c4630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4c4630
  u8 s90[0x80] __attribute__((aligned(16)));
  volatile u32 v94, v98;
  u32 edi = ecx_in, rd = a0;
  W32(edi, 4, *(u32 *)(edi + 4) & 0xffffffbfu);  // @h1_4c4630
  u32 r1 = ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x40))(rd, edi + 0x82);  // @h2_4c4630
  ((u32(THISCALL *)(u32, u32))VSLOT(r1, 0x40))(r1, edi + 0x86);  // @h3_4c4630
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x58))(rd, edi + 0x8a);  // @h4_4c4630
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x50))(rd, edi + 0x8e);  // @h5_4c4630
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x50))(rd, edi + 0x92);  // @h6_4c4630
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x6c))(rd, edi + 0x96);  // @h7_4c4630
  ((u32(THISCALL *)(u32, u32))VSLOT(rd, 0x50))(rd, edi + 0xa2);  // @h8_4c4630
  ext_4cbeb0_t0b((u32)s90);  // @h9_4c4630
  reg.state = 0;
  v94 = 0;
  ext_6352f0_t1(edi, (u32)&v94);  // @h10_4c4630
  ext_4c4740_t3(edi, (u32)&v94, (u32)&v98, (u32)s90);  // @h11_4c4630
  ext_4cbec0_t0((u32)s90);  // @h12_4c4630
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 1;
}
PCREG(4c4630, hand_4c4630);

extern "C" u32 THISCALL hand_442ad0(u32 ecx_in) {
  SEH_ENTER(0x665e7b);  // @h_442ad0
  u8 C[0x60] __attribute__((aligned(16)));
  u8 L[0xac] __attribute__((aligned(16)));
  volatile u32 it[3];
  u32 self = ecx_in;
  ext_44a1f0_t0(self);  // @h1_442ad0
  u32 h = ((u32(THISCALL *)(u32))VSLOT(self, 0x314))(self);  // @h2_442ad0
  u32 ret = 0;
  if (h != 0) {  // @h3_442ad0
    ext_4ccba0_t0((u32)L);  // @h4_442ad0
    reg.state = 0;
    ext_4e3180_t0((u32)C);  // @h5_442ad0
    *(u32 *)(C + 4) = 0x4e32d0;  // @h6_442ad0
    *(u32 *)(C + 0x5c) = (u32)L;  // @h7_442ad0
    ext_4e49d0_t1(h, (u32)C);  // @h8_442ad0
    u32 vt = *(u32 *)L;
    ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x4c)))((u32)L, (u32)it);  // @h9_442ad0
    vt = *(u32 *)L;
    u32 v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)L, (u32)it);  // @h10_442ad0
    if (it[0] != 0) {  // @h11_442ad0
      do {
        u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
        u32 e = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x54))(c, v);  // @h12_442ad0
        if (e != 0) {  // @h13_442ad0
          ext_4da720_t1(e, 0);  // @h14_442ad0
          ext_4d9ce0_t0(e);  // @h15_442ad0
        }
        vt = *(u32 *)L;
        v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)L, (u32)it);  // @h16_442ad0
      } while (it[0] != 0);  // @h17_442ad0
    }
    ret = ext_4ccf60_t0((u32)L);  // @h18_442ad0
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(442ad0, hand_442ad0);

extern "C" u32 THISCALL hand_44a200(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6660dd);  // @h_44a200
  u8 L[0xac] __attribute__((aligned(16)));
  volatile u32 it[3];
  u32 edi = ecx_in, rd = a0;
  ext_610100_s1(rd);  // @h1_44a200
  ext_4ccba0_t0((u32)L);  // @h2_44a200
  reg.state = 0;
  ext_4e0fd0_t1(rd, (u32)L);  // @h3_44a200
  if (*(u32 *)(edi + 0x18) == 0) {  // @h4_44a200
    u32 o = ext_41e290_cdecl1((u32)0x1c);  // @h5_44a200
    reg.state = 1;
    u32 r = 0;
    if (o) r = ext_4ccbe0_t2(o, 0x20, 0);  // @h6_44a200
    reg.state = 0;
    W32(edi, 0x18, r);  // @h7_44a200
  }
  u32 vt = *(u32 *)L;
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x4c)))((u32)L, (u32)it);  // @h8_44a200
  vt = *(u32 *)L;
  u32 v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)L, (u32)it);  // @h9_44a200
  if (it[0] != 0) {  // @h10_44a200
    do {
      u32 c = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      u32 e = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x58))(c, v);  // @h11_44a200
      if (e != 0) {  // @h12_44a200
        u32 h = *(u32 *)(edi + 0x18);
        ((u32(THISCALL *)(u32, u32))VSLOT(h, 4))(h, v);  // @h13_44a200
      }
      vt = *(u32 *)L;
      v = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))((u32)L, (u32)it);  // @h14_44a200
    } while (it[0] != 0);  // @h15_44a200
  }
  ext_4e1b30_t0(rd);  // @h16_44a200
  u32 ret = ext_4ccf60_t0((u32)L);  // @h17_44a200
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(44a200, hand_44a200);

extern "C" u32 THISCALL hand_497750(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66818f);  // @h_497750
  u32 edi = ecx_in;
  u32 m = G(u32, 0x70038c);
  u32 old = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x48))(m, 0x20a0ff);  // @h1_497750
  if (*(u32 *)(edi + 0x30) != 0 || *(u32 *)(edi + 0x2c) != 0) {  // @h2_497750
    m = G(u32, 0x70038c);
    ((u32(THISCALL *)(u32))VSLOT(m, 0xdc))(m);  // @h3_497750
    u32 p = *(u32 *)(edi + 0x30);
    if (p != 0) {  // @h4_497750
      ext_634273_cdecl2(p, 1);  // @h5_497750
      W32(edi, 0x30, 0);  // @h6_497750
    }
    u32 o = *(u32 *)(edi + 0x2c);
    if (o != 0) {  // @h7_497750
      ((u32(THISCALL *)(u32, u32))VSLOT(o, 0))(o, 1);  // @h8_497750
      W32(edi, 0x2c, 0);  // @h9_497750
    }
    W32(edi, 0x34, 0);  // @h10_497750
    W32(edi, 0x38, 0);  // @h11_497750
  }
  W32(edi, 0x34, a0);  // @h12_497750
  u32 buf = ext_41e290_cdecl1(a0);  // @h13_497750
  W32(edi, 0x30, buf);  // @h14_497750
  u32 o2 = ext_41e290_cdecl1((u32)0x10);  // @h15_497750
  reg.state = 0;
  u32 r = 0;
  if (o2 != 0) r = ext_4ccdd0_t3(o2, 0, *(u32 *)(edi + 0x34), 0x200);  // @h16_497750
  u32 edx = *(u32 *)(edi + 0x30);
  W32(edi, 0x2c, r);  // @h17_497750
  m = G(u32, 0x70038c);
  u32 endp = *(u32 *)(edi + 0x34) + edx;  // @h18_497750
  reg.state = -1;
  ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(m, 0xd8))(m, edx, endp, 0x4964b0);  // @h19_497750
  m = G(u32, 0x70038c);
  u32 ret = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x48))(m, old);  // @h20_497750
  m = G(u32, 0x70038c);
  if (m != 0)  // @h21_497750
    ret = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x24))(m, 0x68e524, a0);  // @h22_497750
  SEH_LEAVE();
  return ret;
}
PCREG(497750, hand_497750);

extern "C" u32 THISCALL hand_492250(u32 ecx_in) {
  SEH_ENTER(0x667d5b);  // @h_492250
  u8 B[0x7530] __attribute__((aligned(16)));
  u8 W[0x13c] __attribute__((aligned(16)));
  u32 esi = ecx_in;
  u32 g = G(u32, 0x70039c);
  u32 ret = g;
  if (*(u32 *)(g + 0x1aab) != 0) {  // @h1_492250
    ext_499880_t2((u32)W, (u32)B, 0x7530);  // @h2_492250
    reg.state = 0;
    u32 ok = ext_49a790_t2((u32)W, *(u32 *)(G(u32, 0x70039c) + 0x1aab), 2) & 0xff;  // @h3_492250
    if (ok == 0) {  // @h4_492250
      *(volatile u8 *)(esi + 0xbb2) = 1;  // @h5_492250
    } else {
#define WV(off) (*(u32 *)(*(u32 *)W + (off)))
      ext_49b340_t2((u32)W, 1, 4);  // @h6_492250
      ext_49b2e0_t1((u32)W, 1);  // @h7_492250
      *(volatile u8 *)(esi + 0xbc0) = 1;  // @h8_492250
      ((u32(THISCALL *)(u32, u32))WV(0x68))((u32)W, esi + 0xbb0);  // @h9_492250
      ((u32(THISCALL *)(u32, u32))WV(0x68))((u32)W, esi + 0xbb1);  // @h10_492250
      ((u32(THISCALL *)(u32, u32))WV(0x58))((u32)W, esi + 0xbb3);  // @h11_492250
      ((u32(THISCALL *)(u32, u32))WV(0x40))((u32)W, esi + 0x5d41);  // @h12_492250
      ((u32(THISCALL *)(u32, u32))WV(0x68))((u32)W, esi + 0xbac);  // @h13_492250
#undef WV
      u32 g2 = G(u32, 0x70039c);
      ((u32(THISCALL *)(u32, u32))VSLOT(g2, 4))(g2, (u32)W);  // @h14_492250
      ext_492200_t1(esi, (u32)W);  // @h15_492250
      ext_492880_t1(esi, (u32)W);  // @h16_492250
      u32 g3 = G(u32, 0x70039c);
      u32 r = ((u32(THISCALL *)(u32))VSLOT(g3, 0xbc))(g3);  // @h17_492250
      ((u32(THISCALL *)(u32))VSLOT(r, 0x70))(r);  // @h18_492250
    }
    ret = ext_499970_t0b((u32)W);  // @h19_492250
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ret;
}
PCREG(492250, hand_492250);

extern "C" u32 STDCALL hand_601b10(u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_601b10
  u8 S[0x80] __attribute__((aligned(16)));
  u32 ebx = a1;
  u32 pa1 = a1;
  u32 g = G(u32, 0x70039c);
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(g, 0x144))(g, (u32)S, a0);  // @h1_601b10
  reg.state = 0;
  u32 m = G(u32, 0x700394);
  u32 esi = *(u32 *)m;
  u32 p = ext_4cc1d0_t0((u32)S);
  u32 edi;
  u32 ok = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 0x34)))(G(u32, 0x700394), p, 0) & 0xff;  // @h2_601b10
  if (ok != 0) {  // @h3_601b10
    m = G(u32, 0x700394);
    esi = *(u32 *)m;
    p = ext_4cc1d0_t0((u32)S);
    u32 len = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 0x30)))(G(u32, 0x700394), p, 0);  // @h4_601b10
    *(u32 *)ebx = len;
    edi = ext_41e290_cdecl1((u32)(len + 1));  // @h5_601b10
    ebx = *(u32 *)ebx;
    m = G(u32, 0x700394);
    esi = *(u32 *)m;
    u32 cnt = *(u32 *)pa1;
    p = ext_4cc1d0_t0((u32)S);
    u32 got = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 0x60)))(G(u32, 0x700394), p, edi, cnt, 0, 0);  // @h6_601b10
    if (got == ebx) {  // @h7_601b10
      *(volatile u8 *)(ebx + edi) = 0;  // @h8_601b10
    } else {
      ext_41e2c0_c1(edi);  // @h9_601b10
      edi = 0;
    }
  } else {
    u32 c = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6b9834, 0x79);  // @h10_601b10
    esi = o;
    u32 edi2 = *(u32 *)esi;
    p = ext_4cc1d0_t0((u32)S);
    ((u32(*)(u32, u32, u32))(*(u32 *)(edi2 + 0x2c)))(esi, 0x6b986c, p);  // @h11_601b10
    edi = 0;
  }
  ext_4cbec0_t0((u32)S);
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return edi;
}
PCREG(601b10, hand_601b10);

extern "C" u32 THISCALL hand_492640(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ddb);  // @h_492640
  u8 B[0x7530] __attribute__((aligned(16)));
  u8 W[0x13c] __attribute__((aligned(16)));
  volatile u32 type_ = 0, size_ = 0;
  u32 esi = ecx_in;
  u32 g = G(u32, 0x70039c);
  u32 o = *(u32 *)(g + 0x190f);
  ((u32(THISCALL *)(u32))VSLOT(o, 0x40))(o);  // @h1_492640
  ext_499880_t2((u32)W, (u32)B, 0x7530);  // @h2_492640
  u32 edi = a0;
  reg.state = 0;
  u32 bl;
  u32 ok = ext_49a790_t2((u32)W, edi, 1) & 0xff;  // @h3_492640
  bool fail = (ok == 0);
  if (!fail) {
    ext_49b340_t2((u32)W, 0, 0);  // @h4_492640
    ext_49b2e0_t1((u32)W, 0);  // @h5_492640
    ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x40))((u32)W, (u32)&type_);  // @h6_492640
    if (type_ != 0x40) {  // @h7_492640
      u32 c = G(u32, 0x700390);
      u32 lg = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x68d798, 0x2f5);  // @h8_492640
      ((u32(*)(u32, u32))VSLOT(lg, 0x2c))(lg, 0x68d7e4);  // @h9_492640
      bl = 0;
      goto done;
    }
    size_ = 0;
    ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x60))((u32)W, (u32)&size_);  // @h10_492640
    if (size_ == 0) fail = true;  // @h11_492640
  }
  if (fail) {
    ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x188))(esi, 1);  // @h12_492640
    bl = 0;
  } else {
    ((u32(THISCALL *)(u32))VSLOT(esi, 0xa8))(esi);  // @h13_492640
    ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0xa0))(esi, size_);  // @h14_492640
    *(u32 *)(G(u32, 0x70039c) + 0x1aab) = edi;  // @h15_492640
    ext_634273_cdecl2(size_, 1);  // @h16_492640
    bl = 1;
  }
done:
  ext_499970_t0b((u32)W);  // @h17_492640
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return bl;
}
PCREG(492640, hand_492640);

extern "C" u32 THISCALL ext_4febf0_t1(u32, u32) __asm__("ext_4febf0");
extern "C" u32 THISCALL ext_499980_t0(u32) __asm__("ext_499980");
extern "C" u32 THISCALL hand_4fe8a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b8b);  // @h_4fe8a0
  u8 O[0x13c] __attribute__((aligned(16)));
  u32 edi = ecx_in;
  u32 esi = a0;
  *(u32 *)(edi + 4) &= 0xffffffbf;  // @h1_4fe8a0
#define RD(off, sz) ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x10))(esi, edi + (off), (sz))
  RD(0x48, 1);  // @h2_4fe8a0
  RD(0x5f, 4);  // @h3_4fe8a0
  RD(0x63, 4);  // @h4_4fe8a0
  RD(0x67, 1);  // @h5_4fe8a0
  RD(0x68, 4);  // @h6_4fe8a0
  RD(0x6c, 4);  // @h7_4fe8a0
  RD(0x70, 4);  // @h8_4fe8a0
  RD(0xe4, 4);  // @h9_4fe8a0
  RD(0xe8, 4);  // @h10_4fe8a0
#undef RD
  ext_4febf0_t1((u32)O, esi);  // @h11_4fe8a0
  reg.state = 0;
#define WR(off) ((u32(THISCALL *)(u32, u32))VSLOT(O, 0x40))((u32)O, (u32)*(u16 *)(edi + (off)))
  WR(0x49);  // @h12_4fe8a0
  WR(0x4b);  // @h13_4fe8a0
  WR(0x4d);  // @h14_4fe8a0
  WR(0x4f);  // @h15_4fe8a0
#undef WR
  ext_499980_t0((u32)O);  // @h16_4fe8a0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 1;
}
PCREG(4fe8a0, hand_4fe8a0);

#define ST32(off, v) (*(volatile u32 *)(esi + (off)) = (v))
#define ST16(off, v) (*(volatile u16 *)(esi + (off)) = (v))
#define ST8(off, v) (*(volatile u8 *)(esi + (off)) = (v))
extern "C" u32 THISCALL ext_5c9530_t0(u32) __asm__("ext_5c9530");
extern "C" u32 THISCALL ext_4d83b0_t3(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL hand_5ca720(u32 ecx_in) {
  SEH_ENTER(0x66c7fa);  // @h_5ca720
  u32 esi = ecx_in;
  ext_5c9530_t0(esi);  // @c1_5ca720
  ST32(0, 0x6b4be8);  // @h0_5ca720
  ST32(0x4b6, 0);  // @hx_5ca720
  ST32(0x4e4, 0);  // @h1_5ca720
  ST32(0x4e8, 0);  // @h2_5ca720
  ST32(0x4ec, 0);  // @h3_5ca720
  ST32(0x4f0, 0);  // @h4_5ca720
  ST8(0x4f4, 1);  // @h5_5ca720
  ST32(0x4f5, 0);  // @h6_5ca720
  ST32(0x4f9, 0);  // @h7_5ca720
  ST32(0x4fd, 0x3f800000);  // @h8_5ca720
  ST32(0x501, 0);  // @h9_5ca720
  ST32(0x505, 0);  // @h10_5ca720
  ST32(0x509, 0);  // @h11_5ca720
  ST32(0x50d, 0x3ba3d70a);  // @h12_5ca720
  ST32(0x511, 0);  // @h13_5ca720
  ST32(0x515, 0);  // @h14_5ca720
  ST32(0x519, 0);  // @h15_5ca720
  ST32(0x51d, 0);  // @h16_5ca720
  ST8(0x521, 1);  // @h17_5ca720
  ST32(0x522, 0);  // @h18_5ca720
  ST32(0x526, 0);  // @h19_5ca720
  ST32(0x52a, 0x3f800000);  // @h20_5ca720
  ST32(0x52e, 0);  // @h21_5ca720
  ST32(0x532, 0);  // @h22_5ca720
  ST32(0x536, 0);  // @h23_5ca720
  ST32(0x53a, 0x3ba3d70a);  // @h24_5ca720
  ST32(0x53e, 0);  // @h25_5ca720
  ST32(0x542, 0);  // @h26_5ca720
  ST32(0x546, 0);  // @h27_5ca720
  ST32(0x54a, 0);  // @h28_5ca720
  ST8(0x54e, 1);  // @h29_5ca720
  ST32(0x54f, 0);  // @h30_5ca720
  ST32(0x553, 0);  // @h31_5ca720
  ST32(0x557, 0x3f800000);  // @h32_5ca720
  ST32(0x55b, 0);  // @h33_5ca720
  ST32(0x55f, 0);  // @h34_5ca720
  ST32(0x563, 0);  // @h35_5ca720
  ST32(0x567, 0x3ba3d70a);  // @h36_5ca720
  ST32(0x56b, 0);  // @h37_5ca720
  ST32(0x56f, 0);  // @h38_5ca720
  ST32(0x573, 0);  // @h39_5ca720
  ST32(0x577, 0);  // @h40_5ca720
  ST8(0x57b, 1);  // @h41_5ca720
  ST32(0x57c, 0);  // @h42_5ca720
  ST32(0x580, 0);  // @h43_5ca720
  ST32(0x584, 0x3f800000);  // @h44_5ca720
  ST32(0x588, 0);  // @h45_5ca720
  ST32(0x58c, 0);  // @h46_5ca720
  ST32(0x590, 0);  // @h47_5ca720
  ST32(0x594, 0x3ba3d70a);  // @h48_5ca720
  ST32(0x5ac, 0);  // @h49_5ca720
  ST32(0x471, 0);  // @h50_5ca720
  ST8(0x4ca, 0);  // @h51_5ca720
  ST16(0x598, 0);  // @h52_5ca720
  ST32(0x2fa, 0x40a00000);  // @h53_5ca720
  ST8(0x30a, 0);  // @h54_5ca720
  ST32(0x68, 0);  // @h55_5ca720
  ST32(0x64, 0xffffffff);  // @h56_5ca720
  ST32(0x4be, 0);  // @h57_5ca720
  ST32(0x4ba, 0);  // @h58_5ca720
  ST32(0x4c2, 0);  // @h59_5ca720
  ST32(0x4c6, 0);  // @h60_5ca720
  ST32(0x451, 0);  // @h61_5ca720
  ST32(0x455, 0);  // @h62_5ca720
  ST32(0x459, 0x80000000);  // @h63_5ca720
  ST32(0x45d, 0);  // @h64_5ca720
  ST32(0x461, 0);  // @h65_5ca720
  ST32(0x465, 0x80000000);  // @h66_5ca720
  reg.state = 0;  // @s_5ca720
  ST32(0x4b2, 0x3e800000);  // @h67_5ca720
  ST32(0x4d8, 0);  // @h68_5ca720
  ST32(0x485, 0x42480000);  // @h69_5ca720
  ST32(0x479, 0x43fa0000);  // @h70_5ca720
  ST32(0x47d, 0x43fa0000);  // @h71_5ca720
  ST32(0x489, 0x43fa0000);  // @h72_5ca720
  ST32(0x4cb, 0);  // @h73_5ca720
  ST32(0x4cf, 0);  // @h74_5ca720
  ST32(0x4d3, 0);  // @h75_5ca720
  ST32(0x4dc, 0);  // @h76_5ca720
  ST32(0x4e0, 0);  // @h77_5ca720
  ST32(0x4ae, 0xfe967699);  // @h78_5ca720
  ST8(0xd8, 1);  // @h79_5ca720
  ST32(0xd9, 0x44bb8000);  // @h80_5ca720
  ST8(0x15a, 1);  // @h81_5ca720
  ST32(0x15b, 0x44bb8000);  // @h82_5ca720
  ST8(0x1dc, 1);  // @h83_5ca720
  ST32(0x1dd, 0x44bb8000);  // @h84_5ca720
  ST8(0x25e, 1);  // @h85_5ca720
  ST32(0x25f, 0x44bb8000);  // @h86_5ca720
  ST8(0x2e0, 1);  // @h87_5ca720
  ST32(0x2e1, 0x44bb8000);  // @h88_5ca720
  u32 mg = G(u32, 0x70039c);
  u32 tbl = *(u32 *)(mg + 0x9b);
  u32 ax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(tbl, 0x114))(tbl, 0x6b4ce4, 0, 0x6b4cb4, 0xa5) & 0xffff;  // @c2_5ca720
  u32 edi = esi + 0x7b0;
  ST16(0x59a, ax);  // @h_59a_5ca720
  *(volatile u8 *)edi = 0;  // @h_7b0_5ca720
  ST32(0x7b1, 0);  // @h90_5ca720
  ST32(0x7b5, 0);  // @h91_5ca720
  ST8(0x7b9, 0);  // @h92_5ca720
  ST8(0x4d7, 0);  // @h93_5ca720
  ST32(0x46d, 0x3fb4f4ab);  // @h94_5ca720
  ST32(0x50d, 0x3ba3d70a);  // @h95_5ca720
  ST32(0x53a, 0x3ba3d70a);  // @h96_5ca720
  ST32(0x567, 0x3ba3d70a);  // @h97_5ca720
  ST32(0x594, 0x3ba3d70a);  // @h98_5ca720
  ST32(0x475, 0);  // @h99_5ca720
  u32 obj = ext_41e290_cdecl1((u32)0x108);  // @c3_5ca720
  reg.state = 1;
  u32 edx;
  if (obj != 0) {  // @c4_5ca720
    edx = ext_4d83b0_t3(obj, 0x6b4d14, 0x6b4cf4, edi);  // @c5_5ca720
  } else {
    edx = 0;
  }
  ST32(0x5a8, edx);  // @h_5a8_5ca720
  u32 g2 = G(u32, 0x70039c);
  reg.state = 0;
  ((u32(THISCALL *)(u32, u32))VSLOT(g2, 0x1a4))(g2, edx);  // @c6_5ca720
  SEH_LEAVE();
  return esi;
}
#undef ST32
#undef ST16
#undef ST8
PCREG(5ca720, hand_5ca720);

extern "C" u32 THISCALL ext_431330_t2(u32, u32, u32) __asm__("ext_431330");
extern "C" u32 THISCALL ext_431110_t2(u32, u32, u32) __asm__("ext_431110");
extern "C" u32 THISCALL ext_42b0f0_t3(u32, u32, u32, u32) __asm__("ext_42b0f0");
extern "C" u32 THISCALL ext_430a20_t2(u32, u32, u32) __asm__("ext_430a20");
extern "C" u32 FASTCALL ext_4309b0_f(u32 ecx, u32 edx, u32 st) __asm__("ext_4309b0");
extern "C" u32 THISCALL hand_42d420(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664e4c);  // @h_42d420
  volatile u32 L24[3] __attribute__((aligned(16)));
  volatile u32 L30[3] __attribute__((aligned(16)));
  volatile u8 t0d[4], t11[4], t15[4];
  volatile u32 slot = 0;
  u32 ebx = ecx_in;
  u32 esi = a0;
#define VEC_END (*(u32 *)(*(u32 *)(ebx + 0x1b6d) + 4))
#define CUR (*(volatile u32 *)esi)
  ext_42b390_t3((u32)L24, 0x677b5a, (u32)t0d);  // @h1_42d420
  reg.state = 0;
  ext_42b390_t3((u32)L30, 0x679e54, (u32)t0d);  // @h2_42d420
  reg.state = 1;
  if (CUR != VEC_END) CUR = CUR + 0xc;  // @h3_42d420
  while (CUR != VEC_END) {  // @h4_42d420
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e != 1) break;  // @h5_42d420
    if (*(u8 *)*(u32 *)e != 0x20) break;  // @h6_42d420
    CUR = e + 0xc;  // @h7_42d420
    if (e + 0xc == VEC_END) break;
  }
  u32 edi = CUR;
  u32 len = *(u32 *)(edi + 4) - *(u32 *)edi;
  bool doit = true;
  if (len == 1) {  // @h8_42d420
    u32 r = ext_4309b0_f(*(u32 *)edi, 0x676c04, len);  // @h9_42d420
    if (r == 0) doit = false;  // @h10_42d420
  }
  if (doit) {
    if (edi != (u32)L24) ext_5f2d60_t3((u32)L24, *(u32 *)edi, *(u32 *)(edi + 4));  // @h11_42d420
    CUR = CUR + 0xc;  // @h12_42d420
  }
  while (CUR != VEC_END) {  // @h13_42d420
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e == 1) {  // @h14_42d420
      if (*(u8 *)*(u32 *)e == 0xa) break;  // @h15_42d420
    }
    CUR = e + 0xc;  // @h16_42d420
    if (e + 0xc == VEC_END) break;
  }
  while (CUR != VEC_END) {  // @h17_42d420
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e != 1) break;  // @h18_42d420
    if (*(u8 *)*(u32 *)e != 0xa) break;  // @h19_42d420
    CUR = e + 0xc;  // @h20_42d420
    if (e + 0xc == VEC_END) break;
  }
  u32 map = *(u32 *)(ebx + 0x1b65);
  u32 p1 = ext_431330_t2(map, (u32)t11, (u32)L24);  // @h21_42d420
  u32 v1 = *(u32 *)p1;
  u32 p2 = ext_431110_t2(map, (u32)t15, (u32)L24);  // @h22_42d420
  u32 v2 = *(u32 *)p2;
  slot = 0;
  ext_42b0f0_t3((u32)&slot, v2, v1, slot);  // @h23_42d420
  ext_430a20_t2(map, v2, v1);  // @h24_42d420
  u32 b30 = L30[0], n30 = L30[2] - L30[0];
  reg.state = 2;
  if (b30 != 0 && n30 != 0) ext_54f870_t2((u32)L30, b30, n30);  // @h25_42d420
  u32 b24 = L24[0], n24 = L24[2] - L24[0];
  reg.state = 3;
  if (b24 != 0 && n24 != 0) ext_54f870_t2((u32)L24, b24, n24);  // @h26_42d420
  SEH_LEAVE();
  return 0;
#undef VEC_END
#undef CUR
}
PCREG(42d420, hand_42d420);

extern "C" u32 THISCALL ext_4ccbe0_t2(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccad0_t2(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 ext_634d22_cdecl3b(...) __asm__("ext_634d22");
extern "C" u32 THISCALL hand_493550(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667e9e);  // @h_493550
  u32 ebx = ecx_in;
  u32 P = a0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 c = G(u32, 0x700390);
  u32 lg = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x68d798, 0x101c);  // @h1_493550
  ((u32(*)(u32, u32, u32))VSLOT(lg, 0x2c))(lg, 0x68dfbc, P + 2);  // @h2_493550
  F32(ebx, 0x18) = 0;  // @h3_493550
  u32 obj = ext_41e290_cdecl1((u32)0x1c);  // @h4_493550
  reg.state = 0;
  u32 r = 0;
  if (obj != 0) r = ext_4ccbe0_t2(obj, 0x80, 0);  // @h5_493550
  F32(ebx, 0xc) = r;  // @h6_493550
  u32 v = F32(ebx, 0xbc9);
  F32(ebx, 0x10) = 0;  // @h7_493550
  F32(P, 0x1150) = v;  // @h8_493550
  F32(ebx, 0x5d25) = F32(ebx, 0x5d25) + 1;  // @h9_493550
  F32(ebx, 0xbc9) = 0;  // @h10_493550
  u32 g = G(u32, 0x70039c);
  reg.state = -1;
  u32 o1 = F32(g, 0x1aa3);
  if (o1 != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o1, 0x14))(o1, 0x677b5a);  // @h11_493550
  if (F32(ebx, 0xadc) != 0) {  // @h12_493550
    F32(P, 0x80) = 0;  // @h13_493550
    g = G(u32, 0x70039c);
    F32(P, 0x1138) = F32(g, 0x1907);  // @h14_493550
    g = G(u32, 0x70039c);
    F32(g, 0x1907) = 0;  // @h15_493550
    F32(P, 0x1144) = F32(ebx, 0x1c5d);  // @h16_493550
    u32 t = F32(ebx, 0x44);
    F32(ebx, 0x1c5d) = 0;  // @h17_493550
    F32(P, 0x1148) = t;  // @h18_493550
    t = F32(ebx, 8);
    F32(ebx, 0x44) = 0;  // @h19_493550
    F32(P, 0x114c) = t;  // @h20_493550
    t = F32(ebx, 0xaec);
    F32(ebx, 8) = 0;  // @h21_493550
    F32(P, 0x1154) = t;  // @h22_493550
    t = F32(ebx, 0xadc);
    F32(ebx, 0xaec) = 0;  // @h23_493550
    F32(P, 0x84) = t;  // @h24_493550
    F32(P, 0x110) = 0;  // @h25_493550
    for (u32 i = 0; i < 0x20; i++) F32(P, 0x8c + 4 * i) = F32(ebx, 0x48 + 4 * i);  // @h26_493550
    g = G(u32, 0x70039c);
    u32 e = F32(g, 0x190f);
    u32 x = ((u32(THISCALL *)(u32))VSLOT(e, 0x98))(e);  // @h27_493550
    F32(P, 0x110) = x;  // @h28_493550
    g = G(u32, 0x70039c);
    e = F32(g, 0x190f);
    ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x9c))(e, 0);  // @h29_493550
    u32 obj2 = ext_41e290_cdecl1((u32)0x2c);  // @h30_493550
    reg.state = 1;
    u32 edx = 0;
    if (obj2 != 0) edx = ext_4ccad0_t2(obj2, 8, 0);  // @h31_493550
    g = G(u32, 0x70039c);
    reg.state = -1;
    e = F32(g, 0x190f);
    ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x9c))(e, edx);  // @h32_493550
    F32(ebx, 0xadc) = 0;  // @h33_493550
    ext_634d10_cdecl3(ebx + 0x48, 0, 0x80);  // @h34_493550
    u32 edi = ebx + 0xc4d;
    ext_634d22_cdecl3b(P + 0x11c, edi, 0x1008);  // @h35_493550
    F32(P, 0x1124) = F32(ebx, 0x1c55);  // @h36_493550
    g = G(u32, 0x70039c);
    if (P + 0x112c != g + 0x40) { F32(P, 0x112c) = F32(g, 0x40); g = G(u32, 0x70039c); }
    if (P + 0x1130 != g + 0x44) { F32(P, 0x1130) = F32(g, 0x44); g = G(u32, 0x70039c); }
    if (P + 0x1134 != g + 0x30) F32(P, 0x1134) = F32(g, 0x30);  // @h37_493550
    v = F32(ebx, 0xc8);
    F32(P, 0x1158) = v;  // @h38_493550
    F32(ebx, 0xc8) = 0;  // @h39_493550
    g = G(u32, 0x70039c);
    ((u32(THISCALL *)(u32))VSLOT(g, 0x16c))(g);  // @h40_493550
    ext_634d10_cdecl3(edi, 0, 0x1008);  // @h41_493550
    u32 vt = *(u32 *)ebx;
    F32(ebx, 0x1c59) = 0;  // @h42_493550
    F32(ebx, 0x1c55) = 0;  // @h43_493550
    ((u32(THISCALL *)(u32))(*(u32 *)(vt + 0x194)))(ebx);  // @h44_493550
  }
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(493550, hand_493550);

extern "C" u32 THISCALL hand_4a9600(u32 ecx_in) {
  SEH_ENTER(0x66866c);  // @h_4a9600
  u32 esi = ecx_in;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  ext_469870_t0(esi);  // @h1_4a9600
  F32(esi, 4) = F32(esi, 4) | 0x20;  // @h2_4a9600
  F32(esi, 0x44) = 0;  // @h3_4a9600
  u32 edi = esi + 0x694;
  reg.state = 0;
  F32(esi, 0) = 0x690544;  // @h4_4a9600
  for (u32 i = 0; i < 0xc8; i++) F32(edi + 0x20, 0x1b8 * i) = 0;  // @h5_4a9600
  F32(esi, 0x15e54) = 0;  // @h6_4a9600
  F32(esi, 0x15e58) = 0;  // @h7_4a9600
  ext_4ccbe0_t2(esi + 0x15e5c, 0x20, 0);  // @h8_4a9600
  reg.state = 1;
  F32(esi, 0x15e78) = 0x3f800000;  // @h9_4a9600
  ext_634d10_cdecl3(esi + 0x54, 0, 0x640);  // @h10_4a9600
  ext_634d10_cdecl3(edi, 0, 0x157c0);  // @h11_4a9600
  u32 g = G(u32, 0x70039c);
  u32 t = F32(g, 0x9b);
  u32 ax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(t, 0x114))(t, 0x690640, 0, 0x690610, 0x4e);  // @h12_4a9600
  *(volatile u16 *)(esi + 0x50) = (u16)ax;  // @h13_4a9600
  g = G(u32, 0x70039c);
  t = F32(g, 0x9b);
  ax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(t, 0x114))(t, 0x690650, 0, 0x690610, 0x4f);  // @h14_4a9600
  *(volatile u16 *)(esi + 0x52) = (u16)ax;  // @h15_4a9600
  F32(esi, 0x4c) = 0xf;  // @h16_4a9600
  u32 buf = ext_41e290_cdecl1((u32)150);  // @h17_4a9600
  F32(esi, 0x48) = buf;  // @h18_4a9600
  edi = 0;
  for (int ebx = 0; ebx < (int)F32(esi, 0x4c); ebx++) {  // @h19_4a9600
    u32 b = F32(esi, 0x48);
    *(volatile u32 *)(edi + b) = *(u32 *)(edi + 0x6e65b8);  // @h20_4a9600
    b = F32(esi, 0x48);
    *(volatile u32 *)(edi + b + 6) = *(u32 *)(edi + 0x6e65be);  // @h21_4a9600
    g = G(u32, 0x70039c);
    t = F32(g, 0x9b);
    b = F32(esi, 0x48);
    u32 val = *(volatile u32 *)(edi + b);
    ax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(t, 0x114))(t, val, 0, 0x690610, 0x51);  // @h22_4a9600
    b = F32(esi, 0x48);
    *(volatile u16 *)(edi + b + 4) = (u16)ax;  // @h23_4a9600
    edi += 10;
  }
#define MK(state_, c1, c2, c3, field)                                                  \
  {                                                                                    \
    u32 o = ext_41e290_cdecl1((u32)0x108);                                             \
    reg.state = (state_);                                                              \
    u32 edx = 0;                                                                       \
    if (o != 0) edx = ext_4d8330_t3(o, (c3), (c2), (c1));                              \
    F32(esi, (field)) = edx;                                                           \
    u32 gg = G(u32, 0x70039c);                                                         \
    reg.state = 1;                                                                     \
    ((u32(THISCALL *)(u32, u32))VSLOT(gg, 0x1a4))(gg, edx);                            \
  }
  MK(2, 0x700324, 0x690664, 0x690688, 0x15e7c)  // @h24_4a9600
  MK(3, 0x700328, 0x690698, 0x6906dc, 0x15e80)  // @h25_4a9600
  MK(4, 0x70032c, 0x6906ec, 0x690728, 0x15e84)  // @h26_4a9600
#undef MK
  SEH_LEAVE();
  return esi;
#undef F32
}
PCREG(4a9600, hand_4a9600);

extern "C" u32 THISCALL ext_542110_t0(u32) __asm__("ext_542110");
extern "C" void ext_545260_v(void) __asm__("ext_545260");
static inline u32 satmul_540c70(u32 a, u32 b) {
  unsigned long long p = (unsigned long long)a * b;
  return (p >> 32) ? 0xffffffffu : (u32)p;
}
extern "C" u32 THISCALL hand_540c70(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ab39);  // @h_540c70
  u32 esi = ecx_in;
  u32 edi = a1;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  reg.state = 0;
  F32(esi, 0) = 0x6a2e14;  // @h1_540c70
  F32(esi, 0x61) = 0xbf800000;  // @h2_540c70
  F32(esi, 0x1c) = 0;  // @h3_540c70
  F32(esi, 0x20) = 0;  // @h4_540c70
  F32(esi, 0x24) = 0;  // @h5_540c70
  F32(esi, 0x59) = 0;  // @h6_540c70
  *(volatile u16 *)(esi + 8) = 0;  // @h7_540c70
  *(volatile u8 *)(esi + 0xe) = 0;  // @h8_540c70
  F32(esi, 0xa) = 0;  // @h9_540c70
  F32(esi, 0x5d) = 0;  // @h10_540c70
  F32(esi, 0xf) = 0;  // @h11_540c70
  F32(esi, 0x13) = 0;  // @h12_540c70
  F32(esi, 0x17) = 0;  // @h13_540c70
  F32(esi, 0x34) = 0;  // @h14_540c70
  F32(esi, 0x30) = 0;  // @h15_540c70
  F32(esi, 0x2c) = 0;  // @h16_540c70
  F32(esi, 0x28) = 0;  // @h17_540c70
  if (edi == 0) {  // @h18_540c70
    u32 c = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6a2e20, 0xcc1);  // @h19_540c70
    ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x6a2f80);  // @h20_540c70
    c = G(u32, 0x700390);
    o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6a2e20, 0xcc2);  // @h21_540c70
    ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x6a2fc8);  // @h22_540c70
    SEH_LEAVE();
    return esi;
  }
  F32(esi, 0x28) = edi;  // @h23_540c70
  u32 base = ext_41e290_cdecl1(satmul_540c70(edi, 0x34));  // @h24_540c70
  reg.state = 1;
  u32 eax;
  if (base != 0) {  // @h25_540c70
    u32 ebx = base;
    for (u32 n = edi; n != 0; n--) {  // @h26_540c70
      ext_542110_t0(ebx);  // @h27_540c70
      ebx += 0x34;
    }
    eax = base;
  } else {
    eax = 0;
  }
  edi = F32(esi, 0x28);
  edi <<= 2;  // @h28_540c70
  F32(esi, 0xf) = eax;  // @h29_540c70
  reg.state = 0;
  F32(esi, 0x2c) = edi;  // @h30_540c70
  u32 ecx = ext_41e290_cdecl1(satmul_540c70(edi, 0xc));  // @h31_540c70
  if (ecx != 0) {  // @h32_540c70
    for (u32 n = edi; n != 0; n--) {  // @h33_540c70
      u32 p = ecx + 0xc * (edi - n);
      F32(p, 4) = 0xffffffff;  // @h34_540c70
      F32(p, 0) = 0xffffffff;  // @h35_540c70
      F32(p, 8) = 0;  // @h36_540c70
    }
  }
  F32(esi, 0x13) = ecx;  // @h37_540c70
  F32(esi, 0x30) = 0x96;  // @h38_540c70
  eax = ext_41e290_cdecl1(0x96 * 0xc);  // @h39_540c70
  if (eax != 0) {  // @h40_540c70
    for (u32 n = 0; n < 0x96; n++) {  // @h41_540c70
      u32 p = eax + 0xc * n;
      F32(p, 4) = 0xffffffff;  // @h42_540c70
      F32(p, 0) = 0xffffffff;  // @h43_540c70
      F32(p, 8) = 0;  // @h44_540c70
    }
  }
  F32(esi, 0x17) = eax;  // @h45_540c70
  *(volatile u8 *)(esi + 0x1b) = 0;  // @h46_540c70
  if (a0 == 3) {  // @h47_540c70
    *(volatile u8 *)(esi + 0x50) = 0;  // @h48_540c70
    *(volatile u8 *)(esi + 0x1b) = 1;  // @h49_540c70
  }
  u32 edx = F32(esi, 0xf);
  for (int i = 0; i < (int)F32(esi, 0x28); i++) {  // @h50_540c70
    F32(edx, 0) = F32(edx, 0xc);  // @h51_540c70
    F32(edx, 4) = F32(edx, 0x10);  // @h52_540c70
    F32(edx, 8) = F32(edx, 0x14);  // @h53_540c70
    edx += 0x34;
  }
  ext_545260_v();  // @h54_540c70
  SEH_LEAVE();
  return esi;
#undef F32
}
PCREG(540c70, hand_540c70);

extern "C" u32 THISCALL hand_434010(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6656fa);  // @h_434010
  u32 edi = ecx_in;
  u32 A[40] __attribute__((aligned(16)));
  u32 B[40] __attribute__((aligned(16)));
  volatile u32 it[3] = {0, 0, 0};
  u32 esi, ebx;
  ext_4cbe80_t2((u32)A, a0);  // @h1_434010
  reg.state = 0;
  ebx = ext_4cc5f0_t1((u32)A);  // @h2_434010
  esi = 0;
  if (ebx != 0) {  // @h3_434010
    do {
      u32 p = ext_4cc1d0_t0((u32)A);
      if (*(u8 *)(p + esi) == 0x5c) {  // @h4_434010
        p = ext_4cc1d0_t0((u32)A);
        *(volatile u8 *)(p + esi) = 0x2f;  // @h5_434010
      }
      esi++;
    } while (esi != ebx);
  }
  ext_4cbe50_t2((u32)B, (u32)A);  // @h6_434010
  reg.state = 1;
  u32 (*dot)(u32, u32) = *(u32 (**)(u32, u32))0x676258;
  u32 res = 0;
  bool err = false;
  u32 p = ext_4cc1d0_t0((u32)B);
  u32 r = dot(p, 0x2e);  // @h7_434010
  if (r != 0) {  // @h8_434010
    *(volatile u32 *)r = 0x50495a2e;  // @h9_434010
    esi = *(u32 *)edi;
    p = ext_4cc1d0_t0((u32)B);
    u32 al = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 0xa0)))(edi, p) & 0xff;  // @h10_434010
    if (al == 0) {  // @h11_434010
      esi = *(u32 *)edi;
      p = ext_4cc1d0_t0((u32)B);
      al = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 0x34)))(edi, p, 1) & 0xff;  // @h12_434010
      if (al == 0) {  // @h13_434010
        err = true;
      } else {
        if (*(u32 *)(edi + 4) == 0) {  // @h14_434010
          u32 o = ext_41e290_cdecl1((u32)0x28);  // @h15_434010
          reg.state = 2;
          u32 eax = 0;
          if (o != 0) eax = ext_4cca60_t2(o, 4, 1);  // @h16_434010
          reg.state = 1;
          *(volatile u32 *)(edi + 4) = eax;  // @h17_434010
        }
        u32 o2 = ext_41e290_cdecl1((u32)0x6f);  // @h18_434010
        reg.state = 3;
        if (o2 != 0) ebx = ext_4d5440_t1(o2); else ebx = 0;  // @h19_434010
        u32 mode = ((a1 & 0xff) != 0) ? 5 : 2;  // @h20_434010
        esi = *(u32 *)ebx;
        reg.state = 1;
        p = ext_4cc1d0_t0((u32)B);
        al = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 0x34)))(ebx, p, mode) & 0xff;  // @h21_434010
        if (al == 0) {  // @h22_434010
          err = true;
        } else {
          u32 c = *(u32 *)(edi + 4);
          if (c != 0) {  // @h23_434010
            ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, (u32)it);  // @h24_434010
            c = *(u32 *)(edi + 4);
            u32 n = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x64))(c, (u32)it);  // @h25_434010
            while (n != 0) {  // @h26_434010
              u32 ob = *(u32 *)n;
              ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x2c))(ob, ebx);  // @h27_434010
              c = *(u32 *)(edi + 4);
              n = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x64))(c, (u32)it);  // @h28_434010
            }
          }
          c = *(u32 *)(edi + 4);
          res = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x84))(c, ebx);  // @h29_434010
        }
      }
    }
  }
  if (err) {
    u32 c = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x67a4ec, 0x1bd);  // @h30_434010
    ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x67a568, a0);  // @h31_434010
    res = 0;
  }
  ext_4cbec0_t0((u32)B);  // @h32_434010
  ext_4cbec0_t0((u32)A);  // @h33_434010
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return res;
}
PCREG(434010, hand_434010);

extern "C" u32 THISCALL hand_4af780(u32 ecx_in) {
  SEH_ENTER(0x668936);  // @h_4af780
  u32 ebx = ecx_in;
  u32 S90[32] __attribute__((aligned(16)));
  u32 S110[32] __attribute__((aligned(16)));
  volatile u32 loc = 0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define T0 (G(u32, 0x70039c))
  if (F32(ebx, 0x4c) == 0 && *(u8 *)(ebx + 0x56) == 0) {  // @h1_4af780
    u32 m = F32(T0, 0x9b);
    u32 o = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h2_4af780
    loc = 0;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x88))(o, 0x681320, (u32)&loc);  // @h3_4af780
    F32(ebx, 0x4c) = loc;  // @h4_4af780
  }
  if (F32(ebx, 0x48) == 0) {  // @h5_4af780
    u32 m = F32(T0, 0x9b);
    u32 o = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h6_4af780
    loc = 0;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x88))(o, 0x681320, (u32)&loc);  // @h7_4af780
    F32(ebx, 0x48) = loc;  // @h8_4af780
  }
  if (F32(ebx, 0x4c) == 0) {  // @h9_4af780
    u32 m = F32(T0, 0x9b);
    u32 obj = F32(m, 0xadc);
    u32 vm = *(u32 *)m;
    u32 r = ((u32(THISCALL *)(u32))VSLOT(obj, 0x25c))(obj);  // @h10_4af780
    m = F32(T0, 0x9b);
    u32 e = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(vm + 0x4c)))(m, r, 0x685f44, 0);  // @h11_4af780
    u8 f56 = *(u8 *)(ebx + 0x56);
    F32(ebx, 0x4c) = e;  // @h12_4af780
    if (f56 != 0) {  // @h13_4af780
      u32 c = G(u32, 0x700390);
      u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x690e98, 0x32);  // @h14_4af780
      u32 p = F32(ebx, 0x44);
      u32 edx = 0x67c8e8;
      u32 q = F32(p, 4);
      if (q != 0) edx = q;  // @h15_4af780
      ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x690ee8, edx);  // @h16_4af780
    }
  }
  if (*(u8 *)(ebx + 0x54) != 0) {  // @h17_4af780
    u32 p = F32(ebx, 0x44);
    ((u32(THISCALL *)(u32, u32))VSLOT(p, 0xbc))(p, 1);  // @h18_4af780
  }
  u32 m = F32(T0, 0x9b);
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, F32(ebx, 0x48));  // @h19_4af780
  int path;  // 0 = final, 1 = check 0x58, 2 = error A
  if (r != 0) {  // @h20_4af780
    path = (*(u8 *)(ebx + 0x55) == 0) ? 0 : 1;  // @h21_4af780
  } else {
    path = (*(u8 *)(ebx + 0x55) != 0) ? 1 : 2;  // @h22_4af780
  }
  if (path == 2) {
    u32 c = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x690e98, 0x3a);  // @h23_4af780
    u32 p = F32(ebx, 0x44);
    u32 s = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1d8))(p, (u32)S90, 1);  // @h24_4af780
    u32 vo = *(u32 *)o;
    reg.state = 0;
    u32 str = ext_4cc1d0_t0(s);
    ((u32(*)(u32, u32, u32))(*(u32 *)(vo + 0x2c)))(o, 0x690f24, str);  // @h25_4af780
    reg.state = -1;
    ext_4cbec0_t0((u32)S90);  // @h26_4af780
    u32 vb = *(u32 *)ebx;
    ((u32(THISCALL *)(u32))(*(u32 *)(vb + 0x58)))(ebx);  // @h27_4af780
  } else {
    if (path == 1) {
      m = F32(T0, 0x9b);
      u32 r2 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, F32(ebx, 0x58));  // @h28_4af780
      if (r2 == 0) path = 3;  // @h29_4af780
    }
    if (path == 3) {
      u32 c = G(u32, 0x700390);
      u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x690e98, 0x41);  // @h30_4af780
      u32 p = F32(ebx, 0x44);
      u32 s = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1d8))(p, (u32)S110, 1);  // @h31_4af780
      u32 vo = *(u32 *)o;
      reg.state = 1;
      u32 str = ext_4cc1d0_t0(s);
      ((u32(*)(u32, u32, u32))(*(u32 *)(vo + 0x2c)))(o, 0x690f60, str);  // @h32_4af780
      reg.state = -1;
      ext_4cbec0_t0((u32)S110);  // @h33_4af780
      u32 vb = *(u32 *)ebx;
      ((u32(THISCALL *)(u32))(*(u32 *)(vb + 0x58)))(ebx);  // @h34_4af780
    } else {
      u32 p = F32(ebx, 0x44);
      ((u32(THISCALL *)(u32, u32))VSLOT(p, 0xcc))(p, 1);  // @h35_4af780
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef T0
}
PCREG(4af780, hand_4af780);

extern "C" u32 THISCALL ext_42de30_t0(u32) __asm__("ext_42de30");
extern "C" u32 THISCALL ext_42da80_t1(u32, u32) __asm__("ext_42da80");
extern "C" u32 THISCALL hand_42a820(u32 ecx_in) {
  SEH_ENTER(0x66496c);  // @h_42a820
  u32 edi = ecx_in;
  u32 S90[32] __attribute__((aligned(16)));
  u32 S110[32] __attribute__((aligned(16)));
  volatile u32 loc;
#define LK(key) ({ u32 t_ = G(u32, 0x70039c); (((u32(THISCALL *)(u32, u32, u32))VSLOT(t_, 0x5c))(t_, (key), (u32)&loc) & 0xff); })
  ext_42de30_t0(edi);  // @h1_42a820
  if (LK(0x6781a4)) *(volatile u8 *)(edi + 0x62) = 1;  // @h2_42a820
  if (LK(0x678250)) {  // @h3_42a820
    if (*(u8 *)(edi + 0x1b5b) != 0) {  // @h4_42a820
      u32 c = G(u32, 0x700390);
      u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x679720, 0x50);  // @h5_42a820
      ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x67825c);  // @h6_42a820
      u32 fp = G(u32, 0x7003b0);
      if (fp) ((void (*)(void))fp)(); else __asm__ volatile("int3");  // @h7_42a820
    }
    u32 m = G(u32, 0x700394);
    ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x78))(m, loc);  // @h8_42a820
  }
  if (LK(0x6782a8)) {  // @h9_42a820
    ext_4cbe80_t2((u32)S90, loc);  // @h10_42a820
    reg.state = 0;
    ext_4cbee0_t2(edi + 0x1bf1, (u32)S90);  // @h11_42a820
    reg.state = -1;
    ext_4cbec0_t0((u32)S90);  // @h12_42a820
  }
  if (LK(0x6782b4)) {  // @h13_42a820
    ext_4cbe80_t2((u32)S90, loc);  // @h14_42a820
    reg.state = 1;
    ext_4cbee0_t2(edi + 0x1b71, (u32)S90);  // @h15_42a820
    reg.state = -1;
    ext_4cbec0_t0((u32)S90);  // @h16_42a820
    ext_42da80_t1(edi, edi + 0x1b71);  // @h17_42a820
    *(volatile u8 *)(edi + 0x62) = 1;  // @h18_42a820
  }
  if (LK(0x6782bc) || LK(0x6782c4) || LK(0x6782d0)) {  // @h19_42a820
    ext_4cbe80_t2((u32)S90, loc);  // @h20_42a820
    reg.state = 2;
    ext_4cbee0_t2(edi + 0x1b71, (u32)S90);  // @h21_42a820
    reg.state = -1;
    ext_4cbec0_t0((u32)S90);  // @h22_42a820
    ext_42da80_t1(edi, edi + 0x1b71);  // @h23_42a820
    *(volatile u8 *)(edi + 0x62) = 1;  // @h24_42a820
  }
  if (LK(0x6782dc)) {  // @h25_42a820
    ext_4cbe80_t2((u32)S110, loc);  // @h26_42a820
    reg.state = 3;
    ext_4cbee0_t2(edi + 0x1b71, (u32)S110);  // @h27_42a820
    reg.state = -1;
    ext_4cbec0_t0((u32)S110);  // @h28_42a820
    ext_42da80_t1(edi, edi + 0x1b71);  // @h29_42a820
    *(volatile u8 *)(edi + 0x62) = 1;  // @h30_42a820
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef LK
}
PCREG(42a820, hand_42a820);

extern "C" u32 THISCALL ext_617360_t0(u32) __asm__("ext_617360");
extern "C" u32 THISCALL ext_658db0_t0(u32) __asm__("ext_658db0");
extern "C" u32 THISCALL ext_616490_t3(u32, u32, u32, u32) __asm__("ext_616490");
extern "C" u32 THISCALL ext_616580_t3(u32, u32, u32, u32) __asm__("ext_616580");
extern "C" u32 THISCALL ext_616620_t3(u32, u32, u32, u32) __asm__("ext_616620");
extern "C" u32 THISCALL hand_617150(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e6f4);  // @h_617150
  u32 ebx = ecx_in, edi = a0, esi = a1;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 A = F32(edi, 0xc);
  if ((*(u8 *)(A + 0x3c) & 0x10) && F32(A, 0x44) != 0) {  // @h1_617150
    u32 obj = ext_41e290_cdecl1((u32)0xc);  // @h2_617150
    reg.state = 0;
    if (obj == 0) { SEH_LEAVE(); return 0; }  // @h3_617150
    F32(obj, 4) = ebx;  // @h4_617150
    reg.state = 1;
    F32(obj, 0) = 0x6bdcc0;  // @h5_617150
    ext_617360_t0(ebx);  // @h6_617150
    u32 c = F32(edi, 0xc);
    if ((*(u8 *)(c + 0x3c) & 0x10) == 0) c = 0; else c = F32(c, 0x44);  // @h7_617150
    u32 v = ext_658db0_t0(c);  // @h8_617150
    F32(obj, 8) = v;  // @h9_617150
    SEH_LEAVE();
    return obj;
  }
  u32 ret;
  u32 eax = F32(esi, 0xb9a4);
  u8 flag = *(u8 *)(eax + 0x13f0);
  if (flag != 0) {  // @h10_617150
    u32 o = ext_41e290_cdecl1((u32)0x14);  // @h11_617150
    reg.state = 2;
    if (o == 0) { SEH_LEAVE(); return 0; }  // @h12_617150
    ret = ext_616490_t3(o, ebx, edi, esi);  // @h13_617150
    SEH_LEAVE();
    return ret;
  }
  u32 T = G(u32, 0x70039c);
  u32 ecx = F32(edi, 0x10);
  u32 oo = F32(T, 0x1aa3);
  u32 edx = F32(ecx, 8);
  u32 X = F32(oo, 0x20);
  float f1 = *(volatile float *)(edx + 0x54);
  u32 al = 0;
  if (f1 != *(volatile float *)0x678858) al = 1;  // @h14_617150
  float f2 = *(volatile float *)(edx + 0x58);
  if (f2 != *(volatile float *)0x6785d0) al = 1;  // @h15_617150
  u32 e2 = F32(edx, 0x10) + X;
  u32 dl = 1;
  if ((F32(edx, 0x20) & 0x1100) == 0) dl = al;  // @h16_617150
  float lim = *(volatile float *)0x680a60;
  bool gt = lim > *(volatile float *)(e2 + 0x10);  // @h17_617150
  if (!gt && (dl & 0xff) == 0) {  // @h18_617150
    u32 o = ext_41e290_cdecl1((u32)0x14);  // @h19_617150
    reg.state = 3;
    if (o == 0) { SEH_LEAVE(); return 0; }
    ret = ext_616580_t3(o, ebx, edi, esi);  // @h20_617150
    SEH_LEAVE();
    return ret;
  }
  u32 o = ext_41e290_cdecl1((u32)0x14);  // @h21_617150
  reg.state = 4;
  if (o == 0) { SEH_LEAVE(); return 0; }
  ret = ext_616620_t3(o, ebx, edi, esi);  // @h22_617150
  SEH_LEAVE();
  return ret;
#undef F32
}
PCREG(617150, hand_617150);

extern "C" u32 THISCALL ext_4e5ea0_t0(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e5e60_t0(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e6250_t1(u32, u32) __asm__("ext_4e6250");
extern "C" u32 THISCALL ext_4e6180_t1(u32, u32) __asm__("ext_4e6180");
extern "C" u32 THISCALL ext_4e6050_t1(u32, u32) __asm__("ext_4e6050");
extern "C" u32 THISCALL ext_4e6330_t1(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_4e6420_t0(u32) __asm__("ext_4e6420");
extern "C" u32 THISCALL ext_4ccfe0_t0(u32) __asm__("ext_4ccfe0");
extern "C" u32 STDCALL hand_5f18e0(u32 obj, u32 a1) {
  SEH_ENTER(0x66ce86);  // @h_5f18e0
  u8 S290[0x80] __attribute__((aligned(16)));
  u8 S2b8[0x80] __attribute__((aligned(16)));
  volatile u32 L210[8];
  volatile u32 P = 0;
  u32 ecx = a1 + 1;
  u32 len1 = 0;
  while (*(u8 *)(ecx + len1)) len1++;  // @h1_5f18e0
  P = 0;
  u32 edx = a1 + 3 + len1;  // @h2_5f18e0
  u32 len2 = 0;
  while (*(u8 *)(edx + len2)) len2++;  // @h3_5f18e0
  P = edx + len2 + 1;  // @h4_5f18e0
  ext_4cbe80_t2((u32)S290, edx);  // @h5_5f18e0
  reg.state = 0;
  u32 ebx = ext_4cc1d0_t0((u32)S290);
  u32 (*schr)(u32, u32) = *(u32 (**)(u32, u32))0x676254;
  u32 (*srchr)(u32, u32) = *(u32 (**)(u32, u32))0x676258;
  u32 edi = schr(ebx, 0x3b);  // @h6_5f18e0
  while (edi != 0) {  // @h7_5f18e0
    *(volatile u8 *)edi = 0;
    u32 esi = srchr(ebx, 0x20);  // @h8_5f18e0
    if (esi == 0) break;  // @h9_5f18e0
    esi++;
    edi++;
    u32 saved = edi;
    u32 eq = srchr(esi, 0x3d);  // @h10_5f18e0
    if (eq != 0) *(volatile u8 *)eq = 0;  // @h11_5f18e0
    u8 bl = *(u8 *)P;
    if (bl != 0xff) bl &= 0x3f;  // @h12_5f18e0
    u32 idx = (u32)bl - 1;
    if (idx > 10) {  // @h13_5f18e0
      u32 c = G(u32, 0x700390);
      u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6b8738, 0x233);  // @h14_5f18e0
      ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x6b8834, (u32)bl);  // @h15_5f18e0
      break;
    }
    bool stop = false;
    switch (idx) {
      case 3: {  // t=4
        u32 v = ext_4e5ea0_t0((u32)&P);  // @h16_5f18e0
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1c))(obj, esi, v);  // @h17_5f18e0
        break;
      }
      case 4:  // t=5
        ext_4e5ea0_t0((u32)&P);  // @h18_5f18e0
        break;
      case 0:  // t=1
        ext_4e6250_t1((u32)&P, (u32)L210);  // @h19_5f18e0
        break;
      case 1: {  // t=2
        ext_4e6180_t1((u32)&P, (u32)L210);  // @h20_5f18e0
        u32 f = L210[0];
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x20))(obj, esi, f);  // @h21_5f18e0
        break;
      }
      case 2: {  // t=3
        ext_4e6050_t1((u32)&P, (u32)L210);  // @h22_5f18e0
        u32 v = L210[0];
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x24))(obj, esi, v);  // @h23_5f18e0
        break;
      }
      case 7:
      case 10: {  // t=8, 11
        u32 v = ext_4e5e60_t0((u32)&P);  // @h24_5f18e0
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x24))(obj, esi, v);  // @h25_5f18e0
        break;
      }
      case 9:  // t=10
        ext_4e5e60_t0((u32)&P);  // @h26_5f18e0
        break;
      case 8: {  // t=9
        ext_4ccbe0_t2((u32)S2b8, 0x20, 0);  // @h27_5f18e0
        reg.state = 1;
        ext_4e6330_t1((u32)&P, (u32)S2b8);  // @h28_5f18e0
        reg.state = 0;
        ext_4ccfe0_t0((u32)S2b8);  // @h29_5f18e0
        break;
      }
      case 6:  // t=7
        ext_4e6420_t0((u32)&P);  // @h30_5f18e0
        break;
      default:  // t=6
        stop = true;  // @h31_5f18e0
        break;
    }
    if (stop) break;
    ebx = saved;
    edi = schr(ebx, 0x3b);  // @h32_5f18e0
  }
  ext_4cbec0_t0((u32)S290);  // @h33_5f18e0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(5f18e0, hand_5f18e0);

extern "C" u32 THISCALL ext_4ccba0_t0(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_t0(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_t1(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da340_t4(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4dc630_t2(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL hand_4402a0(u32 ecx_in, u32 a0, u32 a1, u32 pA, u32 pB, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66c60b);  // @h_4402a0
  u32 ebx = ecx_in;
  u32 C[48] __attribute__((aligned(16)));
  volatile u32 L = 0;
  volatile u32 X = 0;
#define MGR (F32(G(u32, 0x70039c), 0x9b))
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 edi = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(ebx, 0x1c0))(ebx, a0, a1, a4, a5, a6 & 0xff);  // @h1_4402a0
  if (edi == 0) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return 0; }  // @h2_4402a0
  u32 m = MGR;
  u32 r4c = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x4c))(m, edi);  // @h3_4402a0
  ebx = r4c;
  if (pA != 0 && pB != 0) ((u32(THISCALL *)(u32, u32, u32))VSLOT(edi, 0x74))(edi, pA, pB);  // @h4_4402a0
  ext_4ccba0_t0((u32)C);  // @h5_4402a0
  reg.state = 0;
  X = F32(edi, 8);  // @h6_4402a0
  while (X != 0) {  // @h7_4402a0
    m = MGR;
    u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x50))(m, X);  // @h8_4402a0
    ext_4cd540_t1((u32)C, r);  // @h9_4402a0
    ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x50))(edi, (u32)&X);  // @h10_4402a0
  }
  ((u32(THISCALL *)(u32, u32))VSLOT((u32)C, 0x4c))((u32)C, (u32)&L);  // @h11_4402a0
  u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT((u32)C, 0x5c))((u32)C, (u32)&L);  // @h12_4402a0
  if (L != 0) {  // @h13_4402a0
    do {
      m = MGR;
      u32 obj = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x54))(m, esi);  // @h14_4402a0
      X = obj;
      if (obj != 0 && (F32(obj, 0x3c) & 0x800000) == 0) {  // @h15_4402a0
        u32 w = F32(obj, 0x54);
        if (w != 0) ((u32(THISCALL *)(u32))VSLOT(w, 0x154))(w);  // @h16_4402a0
        m = MGR;
        if (((u32(THISCALL *)(u32, u32))VSLOT(m, 0x54))(m, esi) != 0) {  // @h17_4402a0
          ext_4da340_t4(X, 1, 0, 0, 0);  // @h18_4402a0
          m = MGR;
          if (((u32(THISCALL *)(u32, u32))VSLOT(m, 0x54))(m, esi) != 0) {  // @h19_4402a0
            ext_4da340_t4(X, 2, 0, 0, 0);  // @h20_4402a0
            m = MGR;
            if (((u32(THISCALL *)(u32, u32))VSLOT(m, 0x54))(m, esi) != 0) {  // @h21_4402a0
              ext_4dc630_t2(X, 0x800000, 0);  // @h22_4402a0
              u32 w2 = F32(X, 0x54);
              if (w2 != 0) ((u32(THISCALL *)(u32))VSLOT(w2, 0x158))(w2);  // @h23_4402a0
              m = MGR;
              ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x54))(m, esi);  // @h24_4402a0
            }
          }
        }
      }
      esi = ((u32(THISCALL *)(u32, u32))VSLOT((u32)C, 0x5c))((u32)C, (u32)&L);  // @h25_4402a0
    } while (L != 0);  // @h26_4402a0
  }
  m = MGR;
  u32 r54 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x54))(m, ebx);  // @h27_4402a0
  esi = (r54 != 0) ? edi : 0;  // @h28_4402a0
  ext_4ccf60_t0((u32)C);  // @h29_4402a0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return esi;
#undef MGR
#undef F32
}
PCREG(4402a0, hand_4402a0);

extern "C" u32 FASTCALL ext_4cc850_f(u32 ecx, u32 edx) __asm__("ext_4cc850");
extern "C" u32 THISCALL ext_4dc110_t0(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_515630_t0(u32) __asm__("ext_515630");
extern "C" u32 THISCALL hand_5207e0(u32 ecx_in) {
  SEH_ENTER(0x66583b);  // @h_5207e0
  u32 esi = ecx_in;
  u32 S90[32] __attribute__((aligned(16)));
  volatile u32 loc = 0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  ext_515630_t0(esi);  // @h1_5207e0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x80))(esi, esi + 0x6c, esi + 0x60);  // @h2_5207e0
  u32 ebx = F32(esi, 0x50);
  while (ebx != 0) {  // @h3_5207e0
    bool body = false;
    u32 a = ext_4dc110_t0(ebx);  // @h4_5207e0
    if (ext_4cc850_f(a, 0x6a04e8) == 0) body = true;  // @h5_5207e0
    else {
      a = ext_4dc110_t0(ebx);
      if (ext_4cc850_f(a, 0x6a04f0) == 0) body = true;  // @h6_5207e0
    }
    if (body) {
      u32 d = F32(ebx, 0x54);
      F32(esi, 0x25d1) = d;  // @h7_5207e0
      u32 e = F32(d, 0xc);
      if ((F32(e, 0x23) & 0x100000) == 0) {  // @h8_5207e0
        u32 c = G(u32, 0x700390);
        u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6a04a8, 0xc2);  // @h9_5207e0
        u32 obj = F32(esi, 0x25d1);
        u32 s = ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1d8))(obj, (u32)S90, 1);  // @h10_5207e0
        u32 vo = *(u32 *)o;
        reg.state = 0;
        u32 p = ext_4cc1d0_t0(s);
        ((u32(*)(u32, u32, u32))(*(u32 *)(vo + 0x2c)))(o, 0x6a04fc, p);  // @h11_5207e0
        reg.state = -1;
        ext_4cbec0_t0((u32)S90);  // @h12_5207e0
      }
    }
    ebx = F32(ebx, 0x60);  // @h13_5207e0
  }
  u32 bl, bh;
  u32 r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x25c))(esi, 0x6a0528, 0);  // @h14_5207e0
  if (r != 0) {  // @h15_5207e0
    u32 q = esi + 0x25e5;
    bl = 1;
    F32(q, 0) = 0;  // @h16_5207e0
    F32(q, 4) = 0;  // @h17_5207e0
    F32(q, 8) = 0;  // @h18_5207e0
    ((u32(THISCALL *)(u32, u32))VSLOT(r, 0x84))(r, q);  // @h19_5207e0
    u32 d = F32(esi, 0x25d1);
    ((u32(THISCALL *)(u32, u32))VSLOT(d, 0x8c))(d, q);  // @h20_5207e0
  } else {
    bl = 0;
  }
  r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x25c))(esi, 0x6a0538, 0);  // @h21_5207e0
  if (r != 0) {  // @h22_5207e0
    u32 q = esi + 0x25f1;
    bh = 1;
    F32(q, 0) = 0;  // @h23_5207e0
    F32(q, 4) = 0;  // @h24_5207e0
    F32(q, 8) = 0;  // @h25_5207e0
    ((u32(THISCALL *)(u32, u32))VSLOT(r, 0x84))(r, q);  // @h26_5207e0
    u32 d = F32(esi, 0x25d1);
    ((u32(THISCALL *)(u32, u32))VSLOT(d, 0x8c))(d, q);  // @h27_5207e0
  } else {
    bh = 0;
  }
  u32 edi = 0x67c8e8;
  if (bl == 0) {  // @h28_5207e0
    u32 c = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6a04a8, 0xdc);  // @h29_5207e0
    u32 edx = edi;
    u32 n = F32(esi, 4);
    if (n != 0) edx = n;  // @h30_5207e0
    ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x6a054c, edx);  // @h31_5207e0
    F32(esi, 0x25e5) = 0;  // @h32_5207e0
    F32(esi, 0x25e9) = 0;  // @h33_5207e0
    F32(esi, 0x25ed) = 0;  // @h34_5207e0
  }
  if (bh == 0) {  // @h35_5207e0
    u32 c = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6a04a8, 0xe1);  // @h36_5207e0
    u32 n = F32(esi, 4);
    if (n != 0) edi = n;  // @h37_5207e0
    ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x6a0584, edi);  // @h38_5207e0
    F32(esi, 0x25f1) = 0;  // @h39_5207e0
    F32(esi, 0x25f5) = 0;  // @h40_5207e0
    F32(esi, 0x25f9) = 0;  // @h41_5207e0
  }
  u32 m = F32(G(u32, 0x70039c), 0x9b);
  u32 o = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h42_5207e0
  loc = 0;
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x88))(o, 0x681320, (u32)&loc);  // @h43_5207e0
  m = F32(G(u32, 0x70039c), 0x9b);
  u32 rr = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, loc);  // @h44_5207e0
  F32(esi, 0x2707) = rr;  // @h45_5207e0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return rr;
#undef F32
}
PCREG(5207e0, hand_5207e0);

extern "C" u32 THISCALL hand_4ad4d0(u32 ecx_in) {
  SEH_ENTER(0x668851);  // @h_4ad4d0
  u32 esi = ecx_in;
  u32 S90[32] __attribute__((aligned(16)));
  u32 S110[32] __attribute__((aligned(16)));
  u32 S190[32] __attribute__((aligned(16)));
  volatile u32 L = 0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define MGR (F32(G(u32, 0x70039c), 0x9b))
  u32 B = esi + 0x11a;
  while (((u32(THISCALL *)(u32))VSLOT(B, 0x14))(B) != 0) {  // @h1_4ad4d0
    u32 edi = ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x30))(B, 0);  // @h2_4ad4d0
    u32 m = MGR;
    u32 x1ac = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edi);  // @h3_4ad4d0
    if (x1ac == 0) continue;  // @h4_4ad4d0
    m = MGR;
    u32 x1a0 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edi);  // @h5_4ad4d0
    if (x1a0 == 0) {  // @h6_4ad4d0
      u32 c = G(u32, 0x700390);
      u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6909a4, 0x290);  // @h7_4ad4d0
      u32 p = F32(esi, 0x44);
      u32 s = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1d8))(p, (u32)S90, 1);  // @h8_4ad4d0
      u32 vo = *(u32 *)o;
      reg.state = 0;
      u32 str = ext_4cc1d0_t0(s);
      ((u32(*)(u32, u32, u32))(*(u32 *)(vo + 0x2c)))(o, 0x690c24, str);  // @h9_4ad4d0
      reg.state = -1;
      ext_4cbec0_t0((u32)S90);  // @h10_4ad4d0
    } else {
      u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x28))(B, edi);  // @h11_4ad4d0
      if (r == 0) {  // @h12_4ad4d0
        u32 c = G(u32, 0x700390);
        u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6909a4, 0x295);  // @h13_4ad4d0
        u32 p = F32(esi, 0x44);
        u32 s1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1d8))(p, (u32)S190, 1);  // @h14_4ad4d0
        reg.state = 1;
        u32 s2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(x1a0, 0x1d8))(x1a0, (u32)S110, 1);  // @h15_4ad4d0
        u32 vo = *(u32 *)o;
        reg.state = 2;
        u32 p1 = ext_4cc1d0_t0(s1);
        u32 p2 = ext_4cc1d0_t0(s2);
        ((u32(*)(u32, u32, u32, u32))(*(u32 *)(vo + 0x2c)))(o, 0x690c60, p2, p1);  // @h16_4ad4d0
        ext_4cbec0_t0((u32)S110);  // @h17_4ad4d0
        reg.state = -1;
        ext_4cbec0_t0((u32)S190);  // @h18_4ad4d0
      } else {
        ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x3c))(B, edi);  // @h19_4ad4d0
        u32 edx = F32(esi, 0x6a);
        if (edx != 0) {  // @h20_4ad4d0
          m = MGR;
          u32 o = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edx);  // @h21_4ad4d0
          u32 w = *(volatile u16 *)(esi + 0x4a);
          ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o, 0x128))(o, w, edi, 0);  // @h22_4ad4d0
        }
        u32 q = esi + 0x1c6;
        if (q != 0) {
          ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x4c))(q, (u32)&L);  // @h23_4ad4d0
          u32 item = ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x5c))(q, (u32)&L);  // @h24_4ad4d0
          if (L != 0) {  // @h25_4ad4d0
            do {
              u32 g = G(u32, 0x70038c);
              u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0xcc))(g, item);  // @h26_4ad4d0
              bool call44 = true;
              if (ob != 0) {  // @h27_4ad4d0
                if (F32(ob, 0x106) == edi) ((u32(THISCALL *)(u32))VSLOT(ob, 0xac))(ob);  // @h28_4ad4d0
                else call44 = false;
              }
              if (call44) ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x44))(q, (u32)&L);  // @h29_4ad4d0
              item = ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x5c))(q, (u32)&L);  // @h30_4ad4d0
            } while (L != 0);  // @h31_4ad4d0
          }
        }
      }
    }
    ((u32(THISCALL *)(u32, u32))VSLOT(x1ac, 0x210))(x1ac, 1);  // @h32_4ad4d0
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef MGR
}
PCREG(4ad4d0, hand_4ad4d0);

extern "C" u32 THISCALL ext_4cc130_t1(u32, u32) __asm__("ext_4cc130");
extern "C" u32 THISCALL ext_439fd0_t1(u32, u32) __asm__("ext_439fd0");
extern "C" u32 THISCALL hand_439970(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665b80);  // @h_439970
  u32 esi = ecx_in, edi = a0, ebx = 0;
  volatile u32 L24[3] = {0, 0, 0};
  u32 lst, r, eax, p, ecx, i;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  lst = F32(esi, 0x1338);
  if (lst == 0) {  // @h1_439970
    u32 obj = ext_41e290_cdecl1((u32)0x1c);  // @h2_439970
    reg.state = 0;
    eax = 0;
    if (obj != 0) eax = ext_4ccbe0_t2(obj, 0x20, 0x2d);  // @h3_439970
    reg.state = -1;
    F32(esi, 0x1338) = eax;  // @h4_439970
    goto lblA;
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(lst, 0x4c))(lst, (u32)L24);  // @h5_439970
  lst = F32(esi, 0x1338);
  ebx = ((u32(THISCALL *)(u32, u32))VSLOT(lst, 0x64))(lst, (u32)L24);  // @h6_439970
  if (ebx == 0) goto lblA;  // @h7_439970
lblC:
  if ((ext_4cc130_t1(ebx, edi) & 0xff) != 0) {  // @h8_439970
    u32 s1 = F32(ebx, 0xaf), s2 = F32(edi, 0xaf);
    if (s1 != 0 && s2 != 0) {  // @h9_439970
      u32 x = s1, y = s2;
      bool eq = true;
      for (;;) {
        u8 dl = *(u8 *)x;
        if (dl != *(u8 *)y) { eq = false; break; }  // @h10_439970
        if (dl == 0) break;
        x++; y++;
      }
      if (eq) goto lblE;  // @h11_439970
    }
  }
  lst = F32(esi, 0x1338);
  ebx = ((u32(THISCALL *)(u32, u32))VSLOT(lst, 0x64))(lst, (u32)L24);  // @h12_439970
  if (ebx != 0) goto lblC;
lblA:
  lst = F32(esi, 0x1338);
  r = ((u32(THISCALL *)(u32, u32))VSLOT(lst, 4))(lst, 0);  // @h13_439970
  ebx = r - 4;
  reg.state = 1;
  if (r == 4) {  // @h14_439970
    ebx = 0;
  } else {
    ext_4cbeb0_t0(ebx);  // @h15_439970
  }
  reg.state = -1;
  edi = a0;
lblE:
  *(volatile u8 *)(ebx + 0xa0) = *(u8 *)(edi + 0xa0);  // @h16_439970
  F32(ebx, 0xa1) = F32(edi, 0xa1);  // @h17_439970
  *(volatile u8 *)(ebx + 0xa5) = *(u8 *)(edi + 0xa5);  // @h18_439970
  *(volatile u8 *)(ebx + 0xa6) = *(u8 *)(edi + 0xa6);  // @h19_439970
  F32(ebx, 0xa7) = F32(edi, 0xa7);  // @h20_439970
  F32(ebx, 0xab) = F32(edi, 0xab);  // @h21_439970
  eax = F32(edi, 0xaf);
  F32(ebx, 0xaf) = eax;  // @h22_439970
  ext_4cbee0_t2(ebx, edi);  // @h23_439970
  for (i = 0; i < 4; i++) {  // @h24_439970
    ecx = F32(edi, 0x80 + 4 * i);
    if (ecx == 0xffffffff) {  // @h25_439970
      for (u32 j = i; j < 4; j++) F32(ebx, 0x80 + 4 * j) = 0xffffffff;  // @h26_439970
      break;
    }
    F32(ebx, 0x80 + 4 * i) = ecx;  // @h27_439970
  }
  for (i = 0; i < 4; i++) {  // @h28_439970
    ecx = F32(edi, 0x90 + 4 * i);
    if (ecx == 0xffffffff) {  // @h29_439970
      for (u32 j = i; j < 4; j++) F32(ebx, 0x90 + 4 * j) = 0xffffffff;  // @h30_439970
      break;
    }
    F32(ebx, 0x90 + 4 * i) = ecx;  // @h31_439970
  }
  ecx = F32(ebx, 0xaf);
  if (ecx == 0) {  // @h32_439970
    u32 vt = *(u32 *)esi;
    p = ext_4cc1d0_t0(ebx);
    eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x58)))(esi, p);  // @h33_439970
  } else {
    u32 w = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x60))(esi, ecx);  // @h34_439970
    if (w == 0) { SEH_LEAVE(); return 0; }  // @h35_439970
    u32 vt = *(u32 *)w;
    p = ext_4cc1d0_t0(ebx);
    eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x10)))(w, p);  // @h36_439970
  }
  if (eax != 0 && F32(eax, 0) == 0) {  // @h37_439970
    ext_439fd0_t1(eax - 4, ebx);  // @h38_439970
  }
  SEH_LEAVE();
  return eax;
#undef F32
}
PCREG(439970, hand_439970);

extern "C" u32 THISCALL hand_4ad9a0(u32 ecx_in) {
  SEH_ENTER(0x6688f1);  // @h_4ad9a0
  u32 esi = ecx_in;
  u32 S90[32] __attribute__((aligned(16)));
  u32 S110[32] __attribute__((aligned(16)));
  u32 S190[32] __attribute__((aligned(16)));
  volatile u32 L1 = 0, L2 = 0;
  u32 edi = 0, m, o, r, x1a4;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define MGR (F32(G(u32, 0x70039c), 0x9b))
  u32 B = esi + 0x11a;  // @m1_4ad9a0
  for (;;) {  // top
    if (((u32(THISCALL *)(u32))VSLOT(B, 0x14))(B) == 0) break;  // @h1_4ad9a0
    ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x4c))(B, (u32)&L1);  // @h2_4ad9a0
    edi = ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x5c))(B, (u32)&L1);  // @h3_4ad9a0
    if (L1 == 0) continue;  // @h4_4ad9a0
    for (;;) {
      m = MGR;
      o = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edi);  // @h5_4ad9a0
      if (o != 0) {  // @h6_4ad9a0
        r = ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x1e0))(o, 0x1007d2) & 0xff;  // @h7_4ad9a0
        if (r != 0) goto process;  // @h8_4ad9a0
      }
      edi = ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x5c))(B, (u32)&L1);  // @h9_4ad9a0
      if (L1 == 0) goto done;  // @h10_4ad9a0
    }
  process:
    m = MGR;
    x1a4 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edi);  // @h11_4ad9a0
    if (x1a4 == 0) {  // @h12_4ad9a0
      u32 c = G(u32, 0x700390);
      u32 oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6909a4, 0x290);  // @h13_4ad9a0
      u32 p = F32(esi, 0x44);  // @m2_4ad9a0
      u32 s = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1d8))(p, (u32)S90, 1);  // @h14_4ad9a0
      u32 vo = *(u32 *)oo;
      reg.state = 0;  // @m3_4ad9a0
      u32 str = ext_4cc1d0_t0(s);
      ((u32(*)(u32, u32, u32))(*(u32 *)(vo + 0x2c)))(oo, 0x690c24, str);  // @h15_4ad9a0
      reg.state = -1;
      ext_4cbec0_t0((u32)S90);  // @h16_4ad9a0
      continue;
    }
    r = ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x28))(B, edi);  // @h17_4ad9a0
    if (r == 0) {  // @h18_4ad9a0
      u32 c = G(u32, 0x700390);
      u32 oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6909a4, 0x295);  // @h19_4ad9a0
      u32 p = F32(esi, 0x44);
      u32 s1 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1d8))(p, (u32)S190, 1);  // @h20_4ad9a0
      reg.state = 1;
      u32 s2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(x1a4, 0x1d8))(x1a4, (u32)S110, 1);  // @h21_4ad9a0
      u32 vo = *(u32 *)oo;
      reg.state = 2;
      u32 p1 = ext_4cc1d0_t0(s1);
      u32 p2 = ext_4cc1d0_t0(s2);
      ((u32(*)(u32, u32, u32, u32))(*(u32 *)(vo + 0x2c)))(oo, 0x690c60, p2, p1);  // @h22_4ad9a0
      ext_4cbec0_t0((u32)S110);  // @h23_4ad9a0
      reg.state = -1;
      ext_4cbec0_t0((u32)S190);  // @h24_4ad9a0
      continue;
    }
    ((u32(THISCALL *)(u32, u32))VSLOT(B, 0x3c))(B, edi);  // @h25_4ad9a0
    {
      u32 edx = F32(esi, 0x6a);  // @m4_4ad9a0
      if (edx != 0) {  // @h26_4ad9a0
        m = MGR;
        o = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edx);  // @h27_4ad9a0
        u32 w = *(volatile u16 *)(esi + 0x4a);  // @m5_4ad9a0
        ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o, 0x128))(o, w, edi, 0);  // @h28_4ad9a0
      }
    }
    u32 q = esi + 0x1c6;  // @m6_4ad9a0
    if (q == 0) continue;
    ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x4c))(q, (u32)&L2);  // @h29_4ad9a0
    u32 item = ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x5c))(q, (u32)&L2);  // @h30_4ad9a0
    if (L2 == 0) continue;  // @h31_4ad9a0
    do {
      u32 g = G(u32, 0x70038c);  // @m7_4ad9a0
      u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0xcc))(g, item);  // @h32_4ad9a0
      bool call44 = true;
      if (ob != 0) {  // @h33_4ad9a0
        if (F32(ob, 0x106) == edi) ((u32(THISCALL *)(u32))VSLOT(ob, 0xac))(ob);  // @h34_4ad9a0
        else call44 = false;  // @m8_4ad9a0
      }
      if (call44) ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x44))(q, (u32)&L2);  // @h35_4ad9a0
      item = ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x5c))(q, (u32)&L2);  // @h36_4ad9a0
    } while (L2 != 0);  // @h37_4ad9a0
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef MGR
}
PCREG(4ad9a0, hand_4ad9a0);

extern "C" u32 THISCALL ext_42be20_t1(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_5f2c60_t2(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL hand_42d000(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664e0c);  // @h_42d000
  volatile u32 L28[3] __attribute__((aligned(16)));
  volatile u32 L1c[3] __attribute__((aligned(16)));
  volatile u8 t0d[4];
  u32 edi = ecx_in;
  u32 esi = a0;
#define VEC_END (*(u32 *)(*(u32 *)(edi + 0x1b6d) + 4))
#define CUR (*(volatile u32 *)esi)
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  ext_42b390_t3((u32)L28, 0x677b5a, (u32)t0d);  // @h1_42d000
  reg.state = 0;
  ext_42b390_t3((u32)L1c, 0x677b5a, (u32)t0d);  // @h2_42d000
  reg.state = 1;
  if (CUR != VEC_END) CUR = CUR + 0xc;  // @h3_42d000
  while (CUR != VEC_END) {  // @h4_42d000
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e != 1) break;  // @h5_42d000
    if (*(u8 *)*(u32 *)e != 0x20) break;  // @h6_42d000
    CUR = e + 0xc;  // @h7_42d000
    if (e + 0xc == VEC_END) break;
  }
  u32 ebx = CUR;
  u32 len = *(u32 *)(ebx + 4) - *(u32 *)ebx;
  bool doit = true;
  if (len == 1) {  // @h8_42d000
    u32 r = ext_4309b0_f(*(u32 *)ebx, 0x676c04, len);  // @h9_42d000
    if (r == 0) doit = false;  // @h10_42d000
  }
  if (doit) {
    if (ebx != (u32)L28) ext_5f2d60_t3((u32)L28, *(u32 *)ebx, *(u32 *)(ebx + 4));  // @h11_42d000
    CUR = CUR + 0xc;  // @h12_42d000
  }
  while (CUR != VEC_END) {  // @h13_42d000
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e != 1) break;  // @h14_42d000
    if (*(u8 *)*(u32 *)e != 0x20) break;  // @h15_42d000
    CUR = e + 0xc;  // @h16_42d000
    if (e + 0xc == VEC_END) break;
  }
  if (CUR != VEC_END) {  // @h17_42d000
    do {
      u32 e = CUR;
      u32 b = *(u32 *)e, en = *(u32 *)(e + 4);
      if (en - b == 1 && *(u8 *)b == 0xa) break;  // @h18_42d000
      if (en - b == 1 && *(u8 *)b == 0x20) break;  // @h19_42d000
      if (en - b == 1 && *(u8 *)b == 0x24) {  // @h20_42d000
        u32 nx = e + 0xc;
        CUR = nx;  // @h21_42d000
        u32 mp = F32(edi, 0x1b65);
        u32 so = ext_42be20_t1(mp, nx);  // @h22_42d000
        ext_5f2c60_t2((u32)L1c, *(u32 *)so, *(u32 *)(so + 4));  // @h23_42d000
        u32 c2 = CUR;
        if (c2 != VEC_END) CUR = c2 + 0xc;  // @h24_42d000
      } else {
        ext_5f2c60_t2((u32)L1c, b, en);  // @h25_42d000
        CUR = CUR + 0xc;  // @h26_42d000
      }
    } while (CUR != VEC_END);  // @h27_42d000
  }
  while (CUR != VEC_END) {  // @h28_42d000
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e == 1 && *(u8 *)*(u32 *)e == 0xa) break;  // @h29_42d000
    CUR = e + 0xc;  // @h30_42d000
    if (e + 0xc == VEC_END) break;
  }
  while (CUR != VEC_END) {  // @h31_42d000
    u32 e = CUR;
    if (*(u32 *)(e + 4) - *(u32 *)e != 1) break;  // @h32_42d000
    if (*(u8 *)*(u32 *)e != 0xa) break;  // @h33_42d000
    CUR = e + 0xc;  // @h34_42d000
    if (e + 0xc == VEC_END) break;
  }
  u32 mp = F32(edi, 0x1b65);
  u32 so = ext_42be20_t1(mp, (u32)L28);  // @h35_42d000
  if ((u32)L1c != so) ext_5f2d60_t3(so, L1c[0], L1c[1]);  // @h36_42d000
  u32 b1 = L1c[0], n1 = L1c[2] - L1c[0];
  reg.state = 2;
  if (b1 != 0 && n1 != 0) ext_54f870_t2((u32)L1c, b1, n1);  // @h37_42d000
  u32 b2 = L28[0], n2 = L28[2] - L28[0];
  reg.state = 3;
  if (b2 != 0 && n2 != 0) ext_54f870_t2((u32)L28, b2, n2);  // @h38_42d000
  SEH_LEAVE();
  return 0;
#undef VEC_END
#undef CUR
#undef F32
}
PCREG(42d000, hand_42d000);

extern "C" u32 THISCALL ext_5eaaf0_t0(u32) __asm__("ext_5eaaf0");
extern "C" u32 THISCALL hand_598a50(u32 ecx_in) {
  SEH_ENTER(0x66bb8c);  // @h_598a50
  u32 esi = ecx_in;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 edi = F32(esi, 0x22d7);
  F32(esi, 0) = 0x6ad5ac;  // @h1_598a50
  if (edi != 0) {  // @h2_598a50
    ext_5eaaf0_t0(edi);  // @h3_598a50
    ext_634273_cdecl2(edi, 0x4c);  // @h4_598a50
  }
  static const u32 offs[8] = {0x75, 0x48, 0x4c, 0x50, 0x71, 0x79, 0x7d, 0x81};
  for (int k = 0; k < 8; k++) {  // @h5_598a50
    u32 t = G(u32, 0x70039c);
    ((u32(THISCALL *)(u32, u32))VSLOT(t, 0x1a8))(t, F32(esi, offs[k]));  // @h6_598a50
    u32 o = F32(esi, offs[k]);
    if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 0))(o, 1);  // @h7_598a50
  }
  u32 V = esi + 0x1da2;
  edi = F32(esi, 0x1da2);
  if (edi != F32(esi, 0x1da6)) {  // @h8_598a50
    do {
      u32 node = F32(edi, 0);
      u32 x = F32(node, 8);
      if (x != 0) { ext_4690b0_t0(x); ext_634273_cdecl2(x, 0x10); }  // @h9_598a50
      x = F32(node, 0xc);
      if (x != 0) { ext_4690b0_t0(x); ext_634273_cdecl2(x, 0x29); }  // @h10_598a50
      x = F32(node, 0x10);
      if (x != 0) { ext_4690b0_t0(x); ext_634273_cdecl2(x, 0x29); }  // @h11_598a50
      x = F32(node, 0x14);
      if (x != 0) { ext_4690b0_t0(x); ext_634273_cdecl2(x, 0x29); }  // @h12_598a50
      ext_634273_cdecl2(F32(edi, 0), 0x1c);  // @h13_598a50
      edi += 4;  // @h14_598a50
    } while (edi != F32(esi, 0x1da6));  // @h15_598a50
  }
  u32 vb = F32(V, 0), ve = F32(V, 4);
  int n = ((int)(ve - vb)) >> 2;
  F32(V, 4) = F32(V, 4) + (u32)(-(n) << 2);  // @h16_598a50
  u32 e = F32(esi, 0x5c);
  if (e != 0) ((u32(THISCALL *)(u32, u32))VSLOT(e, 0))(e, 1);  // @h17_598a50
  u32 begin = F32(V, 0);
  int cnt = ((int)(F32(V, 8) - begin)) >> 2;
  reg.state = 0;
  if (cnt != 0) ext_54f870_t2(V, begin, (u32)cnt << 2);  // @h18_598a50
  F32(esi, 0x44) = 0;  // @h19_598a50
  F32(esi, 0x30) = 0;  // @h20_598a50
  F32(esi, 0) = 0x686874;  // @h21_598a50
  u32 m = F32(G(u32, 0x70039c), 0x9b);
  reg.state = 1;
  ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x34))(m, esi);  // @h22_598a50
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(598a50, hand_598a50);

extern "C" u32 THISCALL ext_440ce0_t1(u32, u32) __asm__("ext_440ce0");
extern "C" u32 THISCALL ext_4da770_t1(u32, u32) __asm__("ext_4da770");
extern "C" u32 THISCALL ext_4444a0_t0(u32) __asm__("ext_4444a0");
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define SCAN_RANGE(KEYOFF, T)                                                             \
  {                                                                                       \
    volatile u32 R[3];                                                                    \
    ext_440ce0_t1((u32)R, F32(esi, (KEYOFF)));  /* @h_scan_##T##_444530 */                \
    u32 ebx = R[1];                                                                       \
    if (ebx != 0) {                                                                       \
      u32 node = R[0], limit = R[2];                                                      \
      do {                                                                                \
        u32 lo = F32(ebx, 0) & 0xfffffff8u;  /* @h_lo_##T##_444530 */                     \
        u32 hi = F32(ebx, 4) & 0xfffffff8u;  /* @h_hi_##T##_444530 */                     \
        ebx += 8;                                                                         \
        if (lo <= hi) {  /* @h_cmp_##T##_444530 */                                        \
          u32 e = lo;                                                                     \
          do {                                                                            \
            ext_4cd540_t1((u32)C, e);  /* @h_call_##T##_444530 */                         \
            e += 0x70;  /* @h_step_##T##_444530 */                                        \
          } while (e <= hi);  /* @h_cond_##T##_444530 */                                  \
        }                                                                                 \
        if (ebx == limit) {  /* @h_lim_##T##_444530 */                                    \
          if (node == 0) break;                                                           \
          for (;;) {                                                                      \
            if ((*(u8 *)(node + 8) & 1) == 0) goto out_##T;  /* @h_bit_##T##_444530 */    \
            node = F32(node, 0xc);  /* @h_next_##T##_444530 */                            \
            if (node == 0) goto out_##T;                                                  \
            u32 al = *(u8 *)(node + 8);                                                   \
            if (al < 2) continue;  /* @h_al_##T##_444530 */                               \
            ebx = node + 0xc;                                                             \
            if (al & 1) ebx += 4;  /* @h_odd_##T##_444530 */                              \
            limit = node + (al + 3) * 4;  /* @h_newlim_##T##_444530 */                    \
            break;                                                                        \
          }                                                                               \
        }                                                                                 \
      } while (ebx != 0);                                                                 \
    }                                                                                     \
  out_##T:;                                                                               \
  }
extern "C" u32 THISCALL hand_444530(u32 ecx_in) {
  SEH_ENTER(0x665f5b);  // @h_444530
  u32 esi = ecx_in;
  u32 C[48] __attribute__((aligned(16)));
  volatile u32 L = 0;
  ext_4444a0_t0(esi);  // @h1_444530
  ext_4ccba0_t0((u32)C);  // @h2_444530
  reg.state = 0;
  SCAN_RANGE(0xb8, a)
  SCAN_RANGE(0xb4, b)
  SCAN_RANGE(0xbc, c)
  ((u32(THISCALL *)(u32, u32))VSLOT((u32)C, 0x4c))((u32)C, (u32)&L);  // @h3_444530
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT((u32)C, 0x5c))((u32)C, (u32)&L);  // @h4_444530
  if (L != 0) {  // @h5_444530
    do {
      ext_4da770_t1(r, esi);  // @h6_444530
      r = ((u32(THISCALL *)(u32, u32))VSLOT((u32)C, 0x5c))((u32)C, (u32)&L);  // @h7_444530
    } while (L != 0);  // @h8_444530
  }
  ext_4ccf60_t0((u32)C);  // @h9_444530
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
#undef SCAN_RANGE
#undef F32
PCREG(444530, hand_444530);

extern "C" u32 THISCALL ext_5f9680_t1(u32, u32) __asm__("ext_5f9680");
extern "C" u32 THISCALL ext_5f3e40_t1(u32, u32) __asm__("ext_5f3e40");
extern "C" u32 THISCALL ext_5fb770_t2(u32, u32, u32) __asm__("ext_5fb770");
extern "C" u32 THISCALL ext_5fbf90_t1(u32, u32) __asm__("ext_5fbf90");
extern "C" u32 THISCALL ext_5f9be0_t1(u32, u32) __asm__("ext_5f9be0");
extern "C" u32 THISCALL ext_5fa4f0_t1(u32, u32) __asm__("ext_5fa4f0");
extern "C" u32 THISCALL ext_5fa0d0_t2(u32, u32, u32) __asm__("ext_5fa0d0");
extern "C" u32 THISCALL ext_5f92c0_t2(u32, u32, u32) __asm__("ext_5f92c0");
extern "C" u32 THISCALL ext_5fda30_t3(u32, u32, u32, u32) __asm__("ext_5fda30");
extern "C" u32 THISCALL ext_5f98a0_t0(u32) __asm__("ext_5f98a0");
extern "C" u32 THISCALL hand_5fd7c0(u32 ecx_in, u32 W) {
  SEH_ENTER(0x66d6a8);  // @h_5fd7c0
  u32 esi = ecx_in;
  u8 S18[32] __attribute__((aligned(16)));
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define CHK(i) do { if (!((u32)(i) < F32(esi, 0x20))) { u32 fp_ = G(u32, 0x7003b0); if (fp_) ((void (*)(void))fp_)(); else __asm__ volatile("int3"); } } while (0)
  ext_5f9680_t1((u32)S18, 0xdac);  // @h1_5fd7c0
  reg.state = 0;
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x38))(W, 0x3f7d70a4);  // @h2_5fd7c0
  u32 edi, ebx, cnt;
  edi = 0;
  if (F32(esi, 0x20) > edi) {  // @h3_5fd7c0
    do {
      CHK(edi);
      u32 el = F32(F32(esi, 0x18), edi * 4);
      ext_5f3e40_t1(el, (u32)S18);  // @h4_5fd7c0
      CHK(edi);
      el = F32(F32(esi, 0x18), edi * 4);
      ext_5fb770_t2(F32(esi, 4), el, (u32)S18);  // @h5_5fd7c0
      CHK(edi);
      el = F32(F32(esi, 0x18), edi * 4);
      u32 r = ext_5fbf90_t1(F32(esi, 4), F32(el, 0x96));  // @h6_5fd7c0
      ext_5f9be0_t1((u32)S18, r);  // @h7_5fd7c0
      edi++;
    } while (edi < F32(esi, 0x20));  // @h8_5fd7c0
  }
  ext_5fa4f0_t1((u32)S18, W);  // @h9_5fd7c0
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x2c))(W, F32(esi, 0x20));  // @h10_5fd7c0
  ebx = 0;
  if (F32(esi, 0x20) > ebx) {  // @h11_5fd7c0
    do {
      CHK(ebx);
      u32 el = F32(F32(esi, 0x18), ebx * 4);
      u32 r = ext_5fbf90_t1(F32(esi, 4), F32(el, 0x96));  // @h12_5fd7c0
      u32 idx = ext_5fa0d0_t2((u32)S18, r, 0);  // @h13_5fd7c0
      if (idx == 0xffffffffu) { u32 fp_ = G(u32, 0x7003b0); if (fp_) ((void (*)(void))fp_)(); else __asm__ volatile("int3"); }  // @h14_5fd7c0
      ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x2c))(W, idx);  // @h15_5fd7c0
      CHK(ebx);
      cnt = F32(esi, 0x20);
      u32 ecx = 0;
      if (cnt != 0) {  // @h16_5fd7c0
        u32 base = F32(esi, 0x18);
        u32 key = F32(F32(base, ebx * 4), 0x20);
        u32 j = 0;
        for (;;) {
          if (key == F32(base + 4 * j, 0)) break;  // @h17_5fd7c0
          j++;
          if (j >= cnt) { j = 0xffffffffu; break; }  // @h18_5fd7c0
        }
        ecx = j;
      } else {
        ecx = 0xffffffffu;
      }
      ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x30))(W, ecx);  // @h19_5fd7c0
      CHK(ebx);
      cnt = F32(esi, 0x20);
      ecx = 0;
      bool found = false;
      if (cnt != 0) {  // @h20_5fd7c0
        u32 base = F32(esi, 0x18);
        u32 key = F32(F32(base, ebx * 4), 0x20);
        u32 j = 0;
        for (;;) {
          if (key == F32(base + 4 * j, 0)) { found = true; ecx = j; break; }  // @h21_5fd7c0
          j++;
          if (j >= cnt) break;  // @h22_5fd7c0
        }
      }
      if (found && (int)ecx >= 0) {  // @h23_5fd7c0
        if (!(ebx < cnt)) { u32 fp_ = G(u32, 0x7003b0); if (fp_) ((void (*)(void))fp_)(); else __asm__ volatile("int3"); }
        u32 el2 = F32(F32(esi, 0x18), ebx * 4);
        ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x2c))(W, F32(el2, 0x64));  // @h24_5fd7c0
      }
      CHK(ebx);
      el = F32(F32(esi, 0x18), ebx * 4);
      ext_5f92c0_t2(el, W, (u32)S18);  // @h25_5fd7c0
      CHK(ebx);
      el = F32(F32(esi, 0x18), ebx * 4);
      ext_5fda30_t3(F32(esi, 4), el, W, (u32)S18);  // @h26_5fd7c0
      ebx++;
    } while (ebx < F32(esi, 0x20));  // @h27_5fd7c0
  }
  ext_5f98a0_t0((u32)S18);  // @h28_5fd7c0
  SEH_LEAVE();
  return 0;
#undef F32
#undef CHK
}
PCREG(5fd7c0, hand_5fd7c0);

extern "C" u32 THISCALL ext_4dcdf0_t1(u32, u32) __asm__("ext_4dcdf0");
extern "C" u32 THISCALL ext_4d2280_t0(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_t0(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d39a0_t2(u32, u32, u32) __asm__("ext_4d39a0");
extern "C" u32 THISCALL ext_4d3ab0_t2(u32, u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL hand_4620d0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6668fb);  // @h_4620d0
  u32 esi = ecx_in;
  u8 Sb[0x40c8] __attribute__((aligned(16)));
  volatile u32 It[4];
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define MGR2 (F32(F32(G(u32, 0x70039c), 0x1aa3), 0x18))
  u32 A = F32(esi, 8);
  if (*(volatile u16 *)(A + 0x5a) != 0) {  // @h1_4620d0
    u32 o = F32(esi, 0x6c);
    u32 edi = ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x58))(o, esi);  // @h2_4620d0
    u32 vt = *(u32 *)esi;
    u32 r2 = ((u32(THISCALL *)(u32))(*(u32 *)(vt + 0x2cc)))(esi);  // @h3_4620d0
    ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(vt + 0x284)))(esi, edi, r2);  // @h4_4620d0
  }
  A = F32(esi, 8);
  u32 edx = F32(A, 0x6c);
  u32 mg = MGR2;
  u32 x40e8 = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0xc8))(mg, edx);  // @h5_4620d0
  u32 edi = F32(esi, 0x6c);
  u32 x40ec = F32(esi, 0x18);
  u32 x40e0 = F32(esi, 0x1c);
  u32 vt0 = *(u32 *)esi;
  F32(esi, 0x1c) = 0;  // @h6_4620d0
  F32(esi, 0x18) = 0;  // @h7_4620d0
  F32(esi, 0x6c) = 0;  // @h8_4620d0
  ((u32(THISCALL *)(u32))(*(u32 *)(vt0 + 0x218)))(esi);  // @h9_4620d0
  F32(esi, 0x6c) = edi;  // @h10_4620d0
  u32 ebx = F32(F32(a0, 8), 0x6c);
  u32 x40d8 = ebx;
  mg = MGR2;
  u32 n = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0xb0))(mg, ebx);  // @h11_4620d0
  F32(esi, 0x20) = n;  // @h12_4620d0
  unsigned long long prod = (unsigned long long)n * 0x18;
  u32 sz = (prod >> 32) ? 0xffffffffu : (u32)prod;
  u32 buf = ext_41e290_cdecl1(sz);  // @h13_4620d0
  F32(esi, 0x1c) = buf;  // @h14_4620d0
  ext_634d10_cdecl3(buf, 0, F32(esi, 0x20) * 24);  // @h15_4620d0
  mg = MGR2;
  u32 x40dc = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0xc8))(mg, ebx);  // @h16_4620d0
  mg = MGR2;
  u32 x40e4 = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0xc4))(mg, ebx);  // @h17_4620d0
  mg = MGR2;
  edi = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0xbc))(mg, ebx);  // @h18_4620d0
  u32 vt1 = *(u32 *)esi;
  mg = MGR2;
  u32 r3 = ((u32(THISCALL *)(u32, u32))VSLOT(mg, 0xc4))(mg, x40d8);  // @h19_4620d0
  ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(vt1 + 0x284)))(esi, edi, r3);  // @h20_4620d0
  if (F32(esi, 0x20) != 0) {  // @h21_4620d0
    u32 pe = x40e4 + 0x2e;
    u32 k = 0;
    do {
      u32 idx = *(volatile u8 *)pe;
      u8 cl = *(volatile u8 *)(idx + x40e8);  // @h22_4620d0
      u8 ch = *(volatile u8 *)(idx + x40dc);  // @h23_4620d0
      if (cl != 0xff) {  // @h24_4620d0
        u32 src = x40e0 + (u32)cl * 24;  // @h25_4620d0
        u32 dst = F32(esi, 0x1c) + (u32)ch * 24;  // @h26_4620d0
        for (u32 q = 0; q < 6; q++) F32(dst, q * 4) = F32(src, q * 4);  // @h27_4620d0
      }
      k++;
      pe += 0x30;  // @h28_4620d0
    } while (k != F32(esi, 0x20));  // @h29_4620d0
  }
  ext_4dcdf0_t1(F32(esi, 8), x40d8);  // @h30_4620d0
  u32 o2 = F32(esi, 0x6c);
  ((u32(THISCALL *)(u32, u32))VSLOT(o2, 8))(o2, esi);  // @h31_4620d0
  ext_634273_cdecl2(x40e0, 0x18);  // @h32_4620d0
  if (x40ec != 0) {  // @h33_4620d0
    F32(esi, 0x18) = x40ec;  // @h34_4620d0
    ((u32(THISCALL *)(u32, u32))VSLOT(x40ec, 0x4c))(x40ec, (u32)It);  // @h35_4620d0
    u32 c = F32(esi, 0x18);
    u32 nd = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x64))(c, (u32)It);  // @h36_4620d0
    while (nd != 0) {  // @h37_4620d0
      u32 e = nd + 4;
      F32(e, 0x44) = 0;  // @h38_4620d0
      if (F32(esi, 0x20) != 0) {  // @h39_4620d0
        u32 cnt = F32(esi, 0x20);
        u32 off = 0;
        for (u32 j = 0; j < cnt; j++, off += 0x18) {  // @h40_4620d0
          u32 base = F32(esi, 0x1c);
          if ((*(volatile u8 *)(base + off + 4) & 1) && F32(base + off, 0x14) == e)  // @h41_4620d0
            F32(e, 0x44) = F32(e, 0x44) + 1;  // @h42_4620d0
        }
      }
      if (F32(e, 0x44) == 0) {  // @h43_4620d0
        F32(e, 0x44) = 0xffffffffu;  // @h44_4620d0
        ext_4d2280_t0((u32)Sb);  // @h45_4620d0
        reg.state = 0;
        u32 nm = e + 0x4c;
        ext_4d39a0_t2((u32)Sb, 0x685918, nm);  // @h46_4620d0
        ext_4d3ab0_t2((u32)Sb, 0x685924, F32(e, 0x48));  // @h47_4620d0
        u32 A2 = F32(esi, 8);
        if (F32(A2, 0x3c) & 0x800000) {  // @h48_4620d0
          u32 v2 = *(u32 *)esi;
          ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(v2 + 0x130)))(esi, esi, *(volatile u16 *)(esi + 0x128), (u32)Sb);  // @h49_4620d0
        }
        u32 v3 = *(u32 *)esi;
        ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(v3 + 0x344)))(esi, nm, F32(e, 0x14));  // @h50_4620d0
        reg.state = -1;
        ext_4d2330_t0((u32)Sb);  // @h51_4620d0
      }
      c = F32(esi, 0x18);
      nd = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x64))(c, (u32)It);  // @h52_4620d0
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef MGR2
}
PCREG(4620d0, hand_4620d0);

extern "C" u32 THISCALL ext_52cfd0_t0(u32) __asm__("ext_52cfd0");
extern "C" u32 THISCALL ext_530fb0_t2(u32, u32, u32) __asm__("ext_530fb0");
extern "C" u32 THISCALL ext_531270_t3(u32, u32, u32, u32) __asm__("ext_531270");
#define LOG3(LINE, MSG, ARG) { u32 c_ = G(u32, 0x700390); u32 o_ = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c_, 0x20))(c_, 0x6a0f54, (LINE)); ((u32(*)(u32, u32, u32))VSLOT(o_, 0x2c))(o_, (MSG), (ARG)); }
#define LOG2(LINE, MSG) { u32 c_ = G(u32, 0x700390); u32 o_ = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c_, 0x20))(c_, 0x6a0f54, (LINE)); ((u32(*)(u32, u32))VSLOT(o_, 0x2c))(o_, (MSG)); }
extern "C" u32 THISCALL hand_52cb60(u32 ecx_in, u32 a0, u32 m) {
  SEH_ENTER(0x66a6b2);  // @h_52cb60
  u32 edi = ecx_in, ebx = a0, esi = 0x1923484;
  u32 al;
  volatile u8 *dbg = (volatile u8 *)0x701b58;
  if (m == 1) {  // @h1_52cb60
    esi = *(volatile u32 *)ebx;  // @h2_52cb60
    if (*dbg != 0) LOG3(0x22a9, 0x6a0f98, esi)  // @h3_52cb60
  } else if (m == 2) {  // @h4_52cb60
    if (*dbg != 0) LOG3(0x22a9, 0x6a0fac, 0x1923484)  // @h5_52cb60
    *(volatile u32 *)ebx = esi;  // @h6_52cb60
  }
  if (esi == 0x1923483 || esi == 0x83349201) {  // @h7_52cb60
    LOG2(0x22ab, 0x6a0fc0)  // @h8_52cb60
    LOG2(0x22ac, 0x6a1008)  // @h9_52cb60
  }
  bool bad = false;
  u32 badline = 0;
  bool direct1 = false;
  if (m == 1) {
    if (esi == 0x1923482 || esi == 0x1923484) {  // @h10_52cb60
    } else if (esi == 0x1923483) {  // @h11_52cb60
      direct1 = true;
    } else if (esi == 0x82349201 || esi == 0x83349201 || esi == 0x84349201) {  // @h12_52cb60
      bad = true; badline = 0x22b9;
    } else {
      bad = true; badline = 0x22b1;
    }
  }
  if (bad) {
    LOG2(badline, 0x6a103c)  // @h13_52cb60
    *(volatile u8 *)(edi + 0x24) = 1;  // @h14_52cb60
    SEH_LEAVE();
    return 0;
  }
  al = 0;
  if (direct1 || esi == 0x1923483 || esi == 0x1923484 || esi == 0x83349201 || esi == 0x84349201) al = 1;  // @h15_52cb60
  *(volatile u8 *)(edi + 0x47) = (u8)al;  // @h16_52cb60
  al = (esi == 0x1923484 || esi == 0x84349201) ? 1 : 0;  // @h17_52cb60
  *(volatile u8 *)(edi + 0x48) = (u8)al;  // @h18_52cb60
  *(volatile u8 *)(edi + 0x24) = 0;  // @h19_52cb60
  u32 x;
  if (m == 2) {  // @h20_52cb60
    x = *(volatile u8 *)(edi + 0x31);  // @h21_52cb60
    if (*dbg != 0) LOG3(0x22c8, 0x6a1090, (u32)(int)(s8)x)  // @h22_52cb60
    *(volatile u8 *)(ebx + 4) = (u8)x;  // @h23_52cb60
    al = x;
  } else if (m == 1) {  // @h24_52cb60
    x = *(volatile u8 *)(ebx + 4);  // @h25_52cb60
    if (*dbg != 0) LOG3(0x22c8, 0x6a1078, (u32)(int)(s8)x)  // @h26_52cb60
    al = x;
  } else {
    al = a0 >> 24;  // @h27_52cb60
  }
  ebx += 5;  // @h28_52cb60
  if (m == 1) *(volatile u8 *)(edi + 0x31) = ((al & 0xff) != 0);  // @h29_52cb60
  if (*(volatile u8 *)(edi + 0x31) == 0) {  // @h30_52cb60
    LOG2(0x22cc, 0x6a10a4)  // @h31_52cb60
    u32 fp = G(u32, 0x7003b0);
    if (fp) ((void (*)(void))fp)(); else __asm__ volatile("int3");  // @h32_52cb60
  } else {
    if (m == 2) {  // @h33_52cb60
      LOG2(0x22d4, 0x6a10c0)  // @h34_52cb60
    } else if (m == 1) {  // @h35_52cb60
      u32 obj = ext_41e290_cdecl1((u32)0xd1e);  // @h36_52cb60
      reg.state = 0;
      u32 ecx = 0;
      if (obj != 0) ecx = ext_52cfd0_t0(obj);  // @h37_52cb60
      u32 b48 = *(volatile u8 *)(edi + 0x48), b47 = *(volatile u8 *)(edi + 0x47);
      reg.state = -1;
      *(volatile u32 *)(edi + 0x65) = ecx;  // @h38_52cb60
      ext_530fb0_t2(ecx, b47, b48);  // @h39_52cb60
    }
    u32 oo = *(volatile u32 *)(edi + 0x65);
    u32 r = ext_531270_t3(oo, ebx, m, 0);  // @h40_52cb60
    ebx += r;
  }
  SEH_LEAVE();
  return ebx - a0;
}
#undef LOG3
#undef LOG2
PCREG(52cb60, hand_52cb60);

extern "C" u32 THISCALL ext_596d30_t1(u32, u32) __asm__("ext_596d30");
extern "C" u32 THISCALL ext_59a9b0_t1(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5b7dd0_t0(u32) __asm__("ext_5b7dd0");
extern "C" u32 THISCALL ext_49e250_t1(u32, u32) __asm__("ext_49e250");
extern "C" u32 THISCALL ext_5b7b90_t2(u32, u32, u32) __asm__("ext_5b7b90");
extern "C" u32 THISCALL ext_5fe3b0_t2(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL hand_599f10(u32 ecx_in) {
  SEH_ENTER(0x66bc1c);  // @h_599f10
  u32 esi = ecx_in;
  volatile u32 L18 = 0, L3c[4] = {0, 0, 0, 0};
  volatile u8 L0d = 0;
  volatile u32 X14 = 0;
  volatile u32 X1c = 0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define MGR (F32(G(u32, 0x70039c), 0x9b))
  u32 T = G(u32, 0x70039c);
  u32 found = ((u32(THISCALL *)(u32, u32, u32))VSLOT(T, 0x5c))(T, 0x6ad804, (u32)&L18) & 0xff;  // @h1_599f10
  if (found) {  // @h2_599f10
    u32 (*iat)(u32) = *(u32 (**)(u32))0x6762d8;
    u32 v = iat(L18);  // @h3_599f10
    ext_596d30_t1(esi, v);  // @h4_599f10
  }
  u32 ecx = F32(G(u32, 0x7003b8), 0x4ac);
  F32(esi, 0x4f3) = ecx;  // @h5_599f10
  if (ecx == 0) goto done;  // @h6_599f10
  {
    u32 r100 = ((u32(THISCALL *)(u32, u32))VSLOT(ecx, 0x100))(ecx, 0x6a5cf0);  // @h7_599f10
    F32(esi, 0x4f7) = r100;  // @h8_599f10
    u32 edi = esi + 0x1da2;
    u32 c18 = F32(F32(esi, 0x4f3), 0x18);
    u32 r14 = ((u32(THISCALL *)(u32))VSLOT(c18, 0x14))(c18);  // @h9_599f10
    ext_59a9b0_t1(edi, r14);  // @h10_599f10
    c18 = F32(F32(esi, 0x4f3), 0x18);
    if (c18 != 0) {  // @h11_599f10
      ((u32(THISCALL *)(u32, u32))VSLOT(c18, 0x4c))(c18, (u32)L3c);  // @h12_599f10
      c18 = F32(F32(esi, 0x4f3), 0x18);
      X14 = ((u32(THISCALL *)(u32, u32))VSLOT(c18, 0x5c))(c18, (u32)L3c);  // @h13_599f10
      if (L3c[0] != 0) {  // @h14_599f10
        do {
          u32 m = MGR;
          u32 it = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, X14);  // @h15_599f10
          u32 ok = ((u32(THISCALL *)(u32, u32))VSLOT(it, 0x1e0))(it, 0x2007f9) & 0xff;  // @h16_599f10
          bool body = false;
          if (ok != 0) {  // @h17_599f10
            u32 p54 = F32(it, 0x54);
            if (p54 != 0) {  // @h18_599f10
              u32 kind = F32(p54, 4);
              if (kind == 0 || kind == 2 || kind == 3 || kind == 4 || kind == 5 || kind == 6 || kind == 7) body = true;  // @h19_599f10
            }
          }
          if (body) {
            u32 key = X14;
            u32 node = ext_41e290_cdecl1((u32)0x1c);  // @h20_599f10
            X1c = node;
            for (u32 q = 0; q < 7; q++) F32(node, 4 * q) = 0;  // @h21_599f10
            F32(node, 0) = key;  // @h22_599f10
            m = MGR;
            u32 r58 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, key);  // @h23_599f10
            F32(node, 4) = r58;  // @h24_599f10
            u32 o1 = ext_41e290_cdecl1((u32)0x10);  // @h25_599f10
            reg.state = 0;
            u32 e1 = 0;
            if (o1 != 0) e1 = ext_5b7dd0_t0(o1);  // @h26_599f10
            F32(node, 8) = e1;  // @h27_599f10
            reg.state = -1;
            ext_49e250_t1(e1, F32(node, 4));  // @h28_599f10
            u32 o2 = ext_41e290_cdecl1((u32)0x29);  // @h29_599f10
            reg.state = 1;
            u32 e2 = 0;
            if (o2 != 0) e2 = ext_5b7b90_t2(o2, 2, 0x40400000);  // @h30_599f10
            reg.state = -1;
            F32(node, 0xc) = e2;  // @h31_599f10
            u32 o3 = ext_41e290_cdecl1((u32)0x29);  // @h32_599f10
            reg.state = 2;
            u32 e3 = 0;
            if (o3 != 0) e3 = ext_5b7b90_t2(o3, 3, 0x40400000);  // @h33_599f10
            reg.state = -1;
            F32(node, 0x10) = e3;  // @h34_599f10
            u32 o4 = ext_41e290_cdecl1((u32)0x29);  // @h35_599f10
            reg.state = 3;
            u32 e4 = 0;
            if (o4 != 0) e4 = ext_5b7b90_t2(o4, 3, 0x40400000);  // @h36_599f10
            F32(node, 0x14) = e4;  // @h37_599f10
            F32(node, 0x18) = 0;  // @h38_599f10
            u32 end = F32(edi, 4);
            reg.state = -1;
            if (end == F32(edi, 8)) {  // @h39_599f10
              ext_5fe3b0_t2(edi, end, (u32)&X1c);  // @h40_599f10
            } else {
              if (end != 0) F32(end, 0) = node;  // @h41_599f10
              F32(edi, 4) = F32(edi, 4) + 4;  // @h42_599f10
            }
          }
          c18 = F32(F32(esi, 0x4f3), 0x18);
          X14 = ((u32(THISCALL *)(u32, u32))VSLOT(c18, 0x5c))(c18, (u32)L3c);  // @h43_599f10
        } while (L3c[0] != 0);  // @h44_599f10
      }
    }
  }
  {
    u32 m = MGR;
    u32 o = ((u32(THISCALL *)(u32))VSLOT(m, 0x134))(m);  // @h45_599f10
    L0d = 0;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x90))(o, 0x68a9d4, (u32)&L0d);  // @h46_599f10
    *(volatile u8 *)(esi + 0x60) = L0d;  // @h47_599f10
    m = MGR;
    u32 o2 = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h48_599f10
    X14 = 0;
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(o2, 0x88))(o2, 0x6a8324, (u32)&X14);  // @h49_599f10
    u32 g = G(u32, 0x70038c);
    u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0xcc))(g, X14);  // @h50_599f10
    F32(esi, 0x58) = r;  // @h51_599f10
    if (r == 0 && *(volatile u8 *)(esi + 0x60) != 0) {  // @h52_599f10
      u32 c = G(u32, 0x700390);
      u32 lg = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c, 0x20))(c, 0x6ad784, 0x15b);  // @h53_599f10
      ((u32(*)(u32, u32))VSLOT(lg, 0x2c))(lg, 0x6ad810);  // @h54_599f10
    }
  }
done:
  SEH_LEAVE();
  return 0;
#undef F32
#undef MGR
}
PCREG(599f10, hand_599f10);

extern "C" u32 THISCALL ext_439320_t3(u32, u32, u32, u32) __asm__("ext_439320");
extern "C" u32 THISCALL ext_5acbf0_t1(u32, u32) __asm__("ext_5acbf0");
extern "C" u32 THISCALL hand_5ac140(u32 ecx_in, u32 S) {
  SEH_ENTER(0x66c23b);  // @h_5ac140
  u32 thisp = ecx_in;
  u8 buf_name[0x420] __attribute__((aligned(16)));  // exe: name sits right after buf (ebp-0x430 / ebp-0x30)
  u8 *const buf = buf_name;
  u8 *const name = buf_name + 0x400;
  u8 Xb0[0x80] __attribute__((aligned(16)));
  volatile u8 X4d4[8];
  for (u32 q = 0; q < 0x400; q++) buf[q] = 0;
  for (u32 q = 0; q < 0x20; q++) name[q] = 0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define STRLEN(p) ({ u32 n_ = 0; while (*(volatile u8 *)((p) + n_)) n_++; n_; })
#define SCAN_END(p) ({ u32 e_ = (p); while (*(volatile u8 *)e_) e_++; e_; })
#define FATAL() do { ext_634047_v(); goto done; } while (0)
  u32 (*sncat)(u32, u32, u32) = *(u32 (**)(u32, u32, u32))0x676428;
  u32 V = thisp + 0x6e;
  u32 begin = F32(V, 0), vend = F32(thisp, 0x72);
  int vn = ((int)(vend - begin)) >> 4;
  F32(V, 4) = F32(V, 4) + (u32)(-(vn) << 4);  // @h1_5ac140
  if (S == 0) goto done;  // @h2_5ac140
  if (*(u8 *)S == 0) goto done;  // @h3_5ac140
  for (u32 q = 0; q < 6; q++) X4d4[q] = 0;  // @h4_5ac140
  {
    u32 len = STRLEN(S);
    u32 segStart = 0, i = 0;
    do {
      if (*(u8 *)(S + i) != 0x24) { i++; continue; }  // @h5_5ac140
      u32 n = 0;
      u8 cl = *(u8 *)(S + i + 1);
      i++;
      if (cl != 0x24) {  // @h6_5ac140
        do {
          i++;
          name[n++] = cl;  // @h7_5ac140
          cl = *(u8 *)(S + i);
        } while (cl != 0x24);  // @h8_5ac140
        if (n >= 0x20) FATAL();  // @h9_5ac140
      }
      name[n] = 0;
      i++;
      u32 nlen = STRLEN((u32)name);
      u32 seg = i - nlen - segStart - 2;  // @h10_5ac140
      u32 curLen = STRLEN((u32)buf);
      sncat((u32)buf, S + segStart, seg);  // @h11_5ac140
      if (curLen + seg >= 0x400) FATAL();  // @h12_5ac140
      buf[curLen + seg] = 0;
      u32 T = G(u32, 0x70039c);
      u32 ob = F32(T, 0x1907);
      u32 r44 = ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x44))(ob, (u32)name);  // @h13_5ac140
      T = G(u32, 0x70039c);
      ob = F32(T, 0x1907);
      u32 rr = ext_439320_t3(ob, r44, 0, 0);  // @h14_5ac140
      bool unknown = true;
      if (rr != 0) {  // @h15_5ac140
        T = G(u32, 0x70039c);
        ob = F32(T, 0x1907);
        u32 r64 = ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x64))(ob, rr);  // @h16_5ac140
        T = G(u32, 0x70039c);
        ob = F32(T, 0x1907);
        u32 so = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ob, 0xbc))(ob, (u32)Xb0, r64);  // @h17_5ac140
        reg.state = 0;
        u32 cs = ext_4cc1d0_t0(so);
        reg.state = -1;
        ext_4cbec0_t0((u32)Xb0);  // @h18_5ac140
        if (cs != 0) {  // @h19_5ac140
          u32 e1 = SCAN_END((u32)buf);
          *(volatile u16 *)e1 = *(volatile u16 *)0x6b0208;  // @h20_5ac140
          u32 slen = STRLEN(cs);
          u32 p = SCAN_END((u32)buf);
          for (u32 q = 0; q < slen; q++) *(volatile u8 *)(p + q) = *(volatile u8 *)(cs + q);  // @h21_5ac140
          u32 e2 = SCAN_END((u32)buf);
          *(volatile u16 *)e2 = *(volatile u16 *)0x6b020c;  // @h22_5ac140
          unknown = false;
        }
      }
      if (unknown) {
        u32 e3 = SCAN_END((u32)buf);
        *(volatile u32 *)e3 = *(volatile u32 *)0x6aeb20;  // @h23_5ac140
        *(volatile u16 *)(e3 + 4) = *(volatile u16 *)0x6aeb24;  // @h24_5ac140
      }
      segStart = i;  // @h25_5ac140
      i++;  // @h26_5ac140
    } while (i < len);  // @h27_5ac140
    u32 seg = i - segStart;  // @h28_5ac140
    u32 curLen = STRLEN((u32)buf);
    sncat((u32)buf, S + segStart, seg);  // @h29_5ac140
    if (curLen + seg >= 0x400) FATAL();  // @h30_5ac140
    buf[curLen + seg] = 0;
    u32 o1 = F32(thisp, 0x1a);
    ((u32(THISCALL *)(u32, u32))VSLOT(o1, 0x284))(o1, (u32)buf);  // @h31_5ac140
    if (*(volatile u8 *)(thisp + 0x19) != 0) {  // @h32_5ac140
      u32 o2 = F32(thisp, 0x42);
      ((u32(THISCALL *)(u32, u32))VSLOT(o2, 0x284))(o2, (u32)buf);  // @h33_5ac140
    }
    ext_5acbf0_t1(V, (u32)X4d4);  // @h34_5ac140
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef STRLEN
#undef SCAN_END
#undef FATAL
}
PCREG(5ac140, hand_5ac140);

extern "C" u32 THISCALL ext_600ba0_t1(u32, u32) __asm__("ext_600ba0");
extern "C" u32 THISCALL ext_5ffb00_t1(u32, u32) __asm__("ext_5ffb00");
extern "C" u32 THISCALL ext_6000b0_t1(u32, u32) __asm__("ext_6000b0");
extern "C" u32 ext_5fa630_v(void) __asm__("ext_5fa630");
extern "C" u32 ext_634d22_cdecl3c(...) __asm__("ext_634d22");
extern "C" u32 THISCALL hand_5fe980(u32 ecx_in, u32 a0, u32 a1, u32 a2);
#define FPCALL() do { u32 fp_ = G(u32, 0x7003b0); if (fp_) ((void (*)(void))fp_)(); else __asm__ volatile("int3"); } while (0)
#define LOG3H(LINE, A, B, C) { u32 c_ = G(u32, 0x700390); u32 o_ = ((u32(THISCALL *)(u32, u32, u32))VSLOT(c_, 0x20))(c_, (A), (LINE)); ((u32(*)(u32, u32, u32))VSLOT(o_, 0x2c))(o_, (B), (C)); }
extern "C" u32 THISCALL hand_5fe980(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d761);  // @h_5fe980
  u32 esi = ecx_in, ebx = a0, edi = a1;
  u8 X74[0x60] __attribute__((aligned(16)));
  u32 S9c[3];
  volatile u8 X85[4];
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define RANGE_OK(edx_, okvar, chkline)                                                  \
  {                                                                                     \
    u32 ecx_ = F32(esi, 0x4c);                                                          \
    bool inr_ = false;                                                                  \
    if (!(ecx_ > (edx_))) { u32 e_ = F32(esi, 0x64) - F32(esi, 0x60) + ecx_; if (e_ > (edx_)) inr_ = true; }  \
    if (inr_) okvar = true;                                                             \
    else { u32 ch_ = F32(esi, 0x9c); okvar = (ch_ != 0) && ((ext_600ba0_t1(ch_, (edx_)) & 0xff) != 0); }    \
  }
  u32 child = F32(esi, 0x9c);
  if (child != 0) hand_5fe980(child, a0, a1, a2);  // @h1_5fe980
  u32 n = F32(esi, 0x64) - F32(esi, 0x60);
  u32 dst = F32(edi, 0) + F32(ebx, 0x9e);
  if (dst + n < F32(ebx, 0xa2)) {  // @h2_5fe980
    ext_634d22_cdecl3c(dst, F32(esi, 0x60), n);  // @h3_5fe980
  } else {
    FPCALL();  // @h4_5fe980
  }
  F32(edi, 0) = F32(edi, 0) + (F32(esi, 0x64) - F32(esi, 0x60));  // @h5_5fe980
  if (a2 == 0) goto done;  // @h6_5fe980
  {
    u32 P = F32(esi, 0x84) + F32(esi, 0x98);
    u32 cnt = F32(P, 0);
    u32 off = 0;
    if (cnt != 0) {  // @h7_5fe980
      do {
        u32 edx = F32(P + off, 4);
        bool ok;
        RANGE_OK(edx, ok, 0)  // @h8_5fe980
        if (ok) {
          u32 id = *(volatile u16 *)(P + off + 8);
          u32 e5 = ext_5ffb00_t1(esi, id);  // @h9_5fe980
          u32 r = ext_6000b0_t1(F32(a0, 0x96), e5);  // @h10_5fe980
          if (r == 0) {  // @h11_5fe980
            u32 lg = ext_5fa630_v();  // @h12_5fe980
            ((u32(*)(u32, u32, u32, u32))VSLOT(lg, 0x14))(lg, (u32)X74, 0x6b94e8, e5);  // @h13_5fe980
            lg = ext_5fa630_v();  // @h14_5fe980
            ((u32(*)(u32, u32))VSLOT(lg, 0xc))(lg, (u32)X74);  // @h15_5fe980
          }
          u32 rr = ((u32(THISCALL *)(u32, u32))VSLOT(a0, 0x30))(a0, e5);  // @h16_5fe980
          F32(F32(a0, 0x9e), F32(P + off, 4)) = rr;  // @h17_5fe980
        } else {
          LOG3H(0x249, 0x6b94a0, 0x69c6b0, 0x677b5a)  // @h18_5fe980
          FPCALL();  // @h19_5fe980
        }
        off += 6;  // @h20_5fe980
        cnt--;
      } while (cnt != 0);  // @h21_5fe980
    }
    u32 P2 = F32(esi, 0x80) + F32(esi, 0x98);
    u32 cnt2 = F32(P2, 0);
    if (cnt2 == 0) goto done;  // @h22_5fe980
    ebx = esi;
    edi = esi;
    u32 off2 = 0;
    do {
      u32 edx = F32(P2 + off2, 4);
      bool ok;
      RANGE_OK(edx, ok, 0)  // @h23_5fe980
      if (!ok) {
        LOG3H(0x273, 0x6b94a0, 0x69c6b0, 0x677b5a)  // @h24_5fe980
        FPCALL();  // @h25_5fe980
      } else {
        u32 w = *(volatile u16 *)(P2 + off2 + 8);
        u32 a8 = F32(esi, 0xa8);
        if (a8 != 0 && !(F32(esi, 0xa0) > w)) {  // @h26_5fe980
          u32 idx = (u16)((u16)w - (u16)F32(esi, 0xa0));  // @h27_5fe980
          if (idx >= F32(esi, 0xa8)) {  // @h28_5fe980
            LOG3H(0x137, 0x6b9420, 0x69c6b0, 0x6b9474)  // @h29_5fe980
            FPCALL();
            ebx = edi;  // @h30_5fe980
          } else {
            edi = F32(F32(esi, 0xac), idx * 4) + F32(esi, 0xb0);  // @h31_5fe980
            ebx = edi;
          }
        } else {
          u32 ch = F32(esi, 0x9c);
          if (ch != 0) ebx = ext_5ffb00_t1(ch, w);  // @h32_5fe980
          else FPCALL();  // @h33_5fe980
        }
        ext_42b390_t3((u32)S9c, ebx, (u32)X85);  // @h34_5fe980
        reg.state = 0;
        u32 rr = ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(a2, 0x10))(a2, ebx, (u32)S9c, a0 + 0xaca);  // @h35_5fe980
        F32(F32(a0, 0x9e), F32(P2 + off2, 4)) = rr;  // @h36_5fe980
        u32 begin = S9c[0], sz = S9c[2] - begin;
        reg.state = 1;
        if (begin != 0 && sz != 0) ext_54f870_t2((u32)S9c, begin, sz);  // @h37_5fe980
        reg.state = -1;
      }
      off2 += 6;  // @h38_5fe980
      cnt2--;
    } while (cnt2 != 0);  // @h39_5fe980
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef RANGE_OK
}
PCREG(5fe980, hand_5fe980);

extern "C" u32 THISCALL ext_600780_t2(u32, u32, u32) __asm__("ext_600780");
extern "C" u32 THISCALL ext_5ffc10_t1(u32, u32) __asm__("ext_5ffc10");
extern "C" u32 THISCALL ext_600540_t3(u32, u32, u32, u32) __asm__("ext_600540");
extern "C" u32 THISCALL ext_600610_t3(u32, u32, u32, u32) __asm__("ext_600610");
extern "C" u32 THISCALL hand_5fdd20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d72f);  // @h_5fdd20
  u32 ebx = ecx_in;
  u8 st[32] __attribute__((aligned(16)));
  u8 pr16[8] __attribute__((aligned(8)));
  u8 pr0[8] __attribute__((aligned(8)));
  u32 pr32[2];
  volatile u32 X28 = 0, X2c = 0, X30 = 0, X20 = 0;
  u32 x14 = 0xccccccccu, x1c = 0xccccccccu;  // fresh-stack fill of the harness
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 child0 = F32(ebx, 0x9c);
  if (child0 != 0) {  // @h1_5fdd20
    u32 e = F32(child0, 0x121);
    ext_600780_t2(a0, F32(e, 5), e);  // @h2_5fdd20
  }
  u32 cnt = F32(ebx, 0xd8);
  if (cnt == 0) goto done;  // @h3_5fdd20
  {
    u32 i = 0;
    do {
      u32 recp = F32(F32(ebx, 0xe8), i * 4);
      u32 x24 = F32(recp, F32(ebx, 0x100));  // @h4_5fdd20
      u32 m = ext_41e290_cdecl1((u32)9);  // @h5_5fdd20
      reg.state = 0;
      if (m != 0) {  // @h6_5fdd20
        F32(m, 0) = 0; F32(m, 4) = 0;
        *(volatile u8 *)(m + 8) = 0;
        u32 hdr = ext_6014a0_s1(0x13);  // @h7_5fdd20
        F32(m, 0) = hdr;
        F32(m, 4) = 0;  // @h8_5fdd20
        *(volatile u8 *)hdr = 0;
        F32(hdr, 1) = 0;  // @h9_5fdd20
        F32(hdr, 5) = hdr;  // @h10_5fdd20
        F32(hdr, 9) = hdr;  // @h11_5fdd20
      }
      reg.state = -1;
      X20 = m;
      u32 V = ebx + 0x10c;
      u32 vend = F32(V, 4);
      if (vend == F32(V, 8)) {  // @h12_5fdd20
        ext_5fe3b0_t2(V, vend, (u32)&X20);  // @h13_5fdd20
      } else {
        if (vend != 0) F32(vend, 0) = m;  // @h14_5fdd20
        F32(V, 4) = F32(V, 4) + 4;  // @h15_5fdd20
      }
      u32 R = F32(F32(ebx, 0xe8), i * 4) + F32(ebx, 0x100);
      u32 f0 = F32(R, 0);
      u16 n16 = *(volatile u16 *)(R + 4);
      u32 arr16 = R + 6;
      *(volatile u32 *)(st + 0) = f0;  // @h16_5fdd20
      *(volatile u16 *)(st + 4) = n16;  // @h17_5fdd20
      *(volatile u32 *)(st + 6) = arr16;  // @h18_5fdd20
      *(volatile u32 *)(st + 10) = arr16 + ((u32)n16 + ((~(u32)n16) & 1)) * 2;  // @h19_5fdd20
      *(volatile u32 *)(st + 14) = ebx;  // @h20_5fdd20
      X20 = 0;
      u32 edi = m;
      u32 esi;
      if (n16 != 0) {  // @h21_5fdd20
        do {
          u32 j = X20;
          esi = *(volatile u16 *)(arr16 + j * 2);  // @h22_5fdd20
          bool haveEax = false;
          u32 eax = 0;
          if (F32(ebx, 0xa8) != 0 && !(F32(ebx, 0xa0) > esi)) {  // @h23_5fdd20
            u32 idx = (u16)((u16)esi - (u16)F32(ebx, 0xa0));
            if (idx >= F32(ebx, 0xa8)) {  // @h24_5fdd20
              LOG3H(0x137, 0x6b9420, 0x69c6b0, 0x6b9474)
              FPCALL();
              eax = x1c; haveEax = true;
            } else {
              eax = F32(F32(ebx, 0xac), idx * 4) + F32(ebx, 0xb0);  // @h25_5fdd20
              x1c = eax; haveEax = true;
            }
          } else {
            u32 ch = F32(ebx, 0x9c);
            if (ch != 0) { eax = ext_5ffb00_t1(ch, esi); haveEax = true; }  // @h26_5fdd20
            else FPCALL();  // @h27_5fdd20
          }
          if (haveEax) x14 = eax;  // @h28_5fdd20
          u32 hobj = F32(G(u32, 0x724278), 0x3c);
          u32 hs = ((u32(THISCALL *)(u32, u32))VSLOT(hobj, 0))(hobj, x14);  // @h29_5fdd20
          u32 key = hs & 0xffff;
          hobj = F32(G(u32, 0x724278), 0x3c);
          ((u32(THISCALL *)(u32, u32, u32))VSLOT(hobj, 0x10))(hobj, key, esi);  // @h30_5fdd20
          // lower_bound on the 16-bit map
          u32 H = F32(m, 0);
          u32 cand = H;
          u32 node = F32(H, 1);
          while (node != 0) {  // @h31_5fdd20
            if (*(volatile u16 *)(node + 0xd) < (u16)key) node = F32(node, 9);  // @h32_5fdd20
            else { cand = node; node = F32(node, 5); }  // @h33_5fdd20
          }
          if (cand == H || (u16)key < *(volatile u16 *)(cand + 0xd)) {  // @h34_5fdd20
            *(volatile u16 *)pr16 = (u16)key;
            *(volatile u32 *)(pr16 + 2) = 0;
            ext_600540_t3(m, (u32)&X28, cand, (u32)pr16);  // @h35_5fdd20
            cand = X28;
          }
          edi = m;
          u32 v = ext_5ffc10_t1((u32)st, x14);  // @h36_5fdd20
          F32(cand, 0xf) = v;  // @h37_5fdd20
          X20 = X20 + 1;
          esi = cand;
        } while (X20 < n16);  // @h38_5fdd20
      }
      // after the ids: entry for key 0
      {
        u32 H = F32(edi, 0);
        u32 cand = H;
        u32 node = F32(H, 1);
        if (node != 0) {  // @h39_5fdd20
          do { cand = node; node = F32(node, 5); } while (node != 0);  // @h40_5fdd20
        }
        if (cand == H || !(0 >= *(volatile u16 *)(cand + 0xd))) {  // @h41_5fdd20
          *(volatile u16 *)pr0 = 0;
          *(volatile u32 *)(pr0 + 2) = 0;
          ext_600540_t3(edi, (u32)&X2c, cand, (u32)pr0);  // @h42_5fdd20
          cand = X2c;
        }
        u32 v = ext_5ffc10_t1((u32)st, 0x6b9490);  // @h43_5fdd20
        F32(cand, 0xf) = v;  // @h44_5fdd20
      }
      // 32-bit map lookup / insert in a0
      {
        u32 H2 = F32(a0, 0);
        u32 best = H2;
        u32 nd = F32(H2, 1);
        while (nd != 0) {  // @h45_5fdd20
          if (F32(nd, 0xd) < x24) nd = F32(nd, 9);  // @h46_5fdd20
          else { best = nd; nd = F32(nd, 5); }  // @h47_5fdd20
        }
        if (best == H2 || x24 < F32(best, 0xd)) {  // @h48_5fdd20
          pr32[0] = x24; pr32[1] = 0;
          ext_600610_t3(a0, (u32)&X30, best, (u32)pr32);  // @h49_5fdd20
          best = X30;
        }
        F32(best, 0x11) = edi;  // @h50_5fdd20
      }
      i++;
    } while (i < F32(ebx, 0xd8));  // @h51_5fdd20
  }
done:
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(5fdd20, hand_5fdd20);

extern "C" u32 FASTCALL ext_42aee0_f(u32 ecx, u32 edx, u32 s1, u32 s2, u32 s3) __asm__("ext_42aee0");
extern "C" u32 FASTCALL ext_42b080_f(u32 ecx, u32 edx, u32 s1) __asm__("ext_42b080");
extern "C" u32 THISCALL ext_4cc180_t1(u32, u32) __asm__("ext_4cc180");
extern "C" u32 THISCALL hand_42ee70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665118);  // @h_42ee70
  u32 T = ecx_in;
  u8 S3f90[0x80] __attribute__((aligned(16)));
  u8 S3f10[0x80] __attribute__((aligned(16)));
  u32 V3fb0[3], V3f9c[3];
  u8 buf[0x3e84] __attribute__((aligned(16)));
  volatile u32 cur;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  ext_4cbe80_t2((u32)S3f90, a0);  // @h1_42ee70
  reg.state = 0;
  cur = ext_4cc1d0_t0((u32)S3f90);  // @h2_42ee70
  ext_4cbe80_t2((u32)S3f10, 0x677b5a);  // @h3_42ee70
  reg.state = 1;
  u32 M = T + 0x1a17;
  ext_4cbee0_t2(M, (u32)S3f10);  // @h4_42ee70
  reg.state = 0;
  ext_4cbec0_t0((u32)S3f10);  // @h5_42ee70
  u32 V = F32(T, 0x1b69);
  u32 vend = F32(V, 4), vbeg = F32(V, 0);
  u32 r1 = ext_42aee0_f(vend, vend, vbeg, a0, 0);  // @h6_42ee70
  ext_42b080_f(r1, F32(V, 4), a0);  // @h7_42ee70
  int dx = (int)(vend - vbeg);
  int q = dx / -12;  // @h8_42ee70
  F32(V, 4) = F32(V, 4) + (u32)(q * 12);  // @h9_42ee70
  V3fb0[0] = 0; V3fb0[1] = 0; V3fb0[2] = 0;
  u32 al1 = ext_6014a0_s1(8);  // @h10_42ee70
  V3fb0[0] = al1; V3fb0[1] = al1; V3fb0[2] = al1 + 8;  // @h11_42ee70
  *(volatile u8 *)al1 = 0;
  reg.state = 2;
  V3f9c[0] = 0; V3f9c[1] = 0; V3f9c[2] = 0;
  u32 al2 = ext_6014a0_s1(8);  // @h12_42ee70
  V3f9c[0] = al2; V3f9c[1] = al2; V3f9c[2] = al2 + 8;  // @h13_42ee70
  *(volatile u8 *)al2 = 0;
  reg.state = 3;
  ext_634d10_cdecl3((u32)buf, 0, 0x3e80);  // @h14_42ee70
  u32 bl;
  u32 eq = ext_4cc180_t1(M, 0x677b5a) & 0xff;  // @h15_42ee70
  bool fail = false;
  if (eq != 0) {  // @h16_42ee70
    u32 r = ((u32(THISCALL *)(u32))VSLOT(T, 0x74))(T) & 0xff;  // @h17_42ee70
    if (r == 0) {  // @h18_42ee70
      u32 o = G(u32, 0x700390);
      ((u32(*)(u32, u32))VSLOT(o, 0x34))(o, 0x679d20);  // @h19_42ee70
      bl = 0;
      fail = true;
    }
  }
  if (!fail) {
    while (*(u8 *)cur != 0) {  // @h20_42ee70
      ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x7c))(T, (u32)&cur);  // @h21_42ee70
    }
    u32 cs = ext_4cc1d0_t0(M);
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(T, 0x70))(T, (u32)buf, cs);  // @h22_42ee70
    u32 len = 0;
    while (buf[len]) len++;
    ext_5f2d60_t3((u32)V3f9c, (u32)buf, (u32)buf + len);  // @h23_42ee70
    ((u32(THISCALL *)(u32, u32))VSLOT(T, 0xb0))(T, (u32)V3f9c);  // @h24_42ee70
    u32 hit = ((u32(*)(u32, u32))G(u32, 0x67625c))(a0, 0x679d48);  // @h25_42ee70
    if (hit != 0) {  // @h26_42ee70
      LOG3H(0x379, 0x6799ac, 0x679d54, 0)
      LOG3H(0x37a, 0x6799ac, 0x679d7c, 0)
      LOG3H(0x37b, 0x6799ac, 0x679d94, 0)
      LOG3H(0x37c, 0x6799ac, 0x676c18, V3f9c[0])
      LOG3H(0x37d, 0x6799ac, 0x679d94, 0)
      LOG3H(0x37e, 0x6799ac, 0x679db8, 0)
      LOG3H(0x37f, 0x6799ac, 0x679dd8, 0)
    }
    u32 p = V3f9c[0];
    u32 k = 0;
    do { buf[k] = *(u8 *)(p + k); } while (*(u8 *)(p + k++) != 0);  // @h27_42ee70
    bl = ((u32(THISCALL *)(u32, u32))VSLOT(T, 0xb4))(T, (u32)buf) & 0xff;  // @h28_42ee70
  }
  {
    u32 n9 = V3f9c[2] - V3f9c[0];
    reg.state = 4;
    if (V3f9c[0] != 0 && n9 != 0) ext_54f870_t2((u32)V3f9c, V3f9c[0], n9);  // @h29_42ee70
    u32 n8 = V3fb0[2] - V3fb0[0];
    reg.state = 5;
    if (V3fb0[0] != 0 && n8 != 0) ext_54f870_t2((u32)V3fb0, V3fb0[0], n8);  // @h30_42ee70
    ext_4cbec0_t0((u32)S3f90);  // @h31_42ee70
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return bl;
#undef F32
}
PCREG(42ee70, hand_42ee70);

extern "C" u32 THISCALL ext_600800_t0(u32) __asm__("ext_600800");
extern "C" u32 FASTCALL ext_5fa640_f(u32 ecx, u32 edx, u32 s1, u32 s2, u32 s3, u32 s4, u32 s5) __asm__("ext_5fa640");
extern "C" u32 THISCALL ext_4312f0_t3(u32, u32, u32, u32) __asm__("ext_4312f0");
extern "C" u32 THISCALL ext_5f10c0_t1(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fccb0_t0(u32) __asm__("ext_5fccb0");
extern "C" u32 THISCALL ext_5fc010_t0(u32) __asm__("ext_5fc010");
extern "C" u32 THISCALL ext_5fb8b0_t1(u32, u32) __asm__("ext_5fb8b0");
extern "C" u32 THISCALL hand_5fd2a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d680);  // @h_5fd2a0
  u32 ebx = ecx_in;
  u32 S30[3], X3c[3];
  volatile u8 X0d[4];
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  if (a0 == 0) goto done;  // @h1_5fd2a0
  if (F32(a0, 0x20) != 0) goto done;  // @h2_5fd2a0
  {
    u32 r6 = ext_600800_t0(F32(a0, 0x96));  // @h3_5fd2a0
    ext_42b390_t3((u32)S30, r6, (u32)X0d);  // @h4_5fd2a0
    reg.state = 0;
    u32 len = S30[1] - S30[0];
    if (len >= 1) {  // @h5_5fd2a0
      u32 e1 = len - 1;
      u32 esi = S30[0] + 1 + e1;
      u32 r = ext_5fa640_f(S30[0], esi, 0x67b1b0, 0x67b1b1, a0, a0, a0);  // @h6_5fd2a0
      if (r != esi) {  // @h7_5fd2a0
        u32 idx = r - S30[0];
        if (idx != 0xffffffffu) {  // @h8_5fd2a0
          u32 edx2 = idx - 1;
          u32 len2 = S30[1] - S30[0];
          if (len2 >= 1) {  // @h9_5fd2a0
            u32 m = len2 - 1;
            u32 pick = (edx2 >= m) ? m : edx2;  // @h10_5fd2a0
            u32 esi2 = S30[0] + 1 + pick;
            u32 r2 = ext_5fa640_f(S30[0], esi2, 0x67b1b0, 0x67b1b1, a0, a0, a0);  // @h11_5fd2a0
            if (r2 != esi2) {  // @h12_5fd2a0
              u32 pos = r2 - S30[0];
              if (pos != 0xffffffffu) {  // @h13_5fd2a0
                u32 start = pos + 1;
                u32 cntleft = (S30[1] - S30[0]) - start;
                u32 res = ext_4312f0_t3((u32)S30, (u32)X3c, start, cntleft);  // @h14_5fd2a0
                reg.state = 1;
                if (res != (u32)S30) ext_5f2d60_t3((u32)S30, F32(res, 0), F32(res, 4));  // @h15_5fd2a0
                u32 n = X3c[2] - X3c[0];
                reg.state = 2;
                if (X3c[0] != 0 && n != 0) ext_54f870_t2((u32)X3c, X3c[0], n);  // @h16_5fd2a0
                reg.state = 0;
              }
            }
          }
        }
      }
    }
    ext_5fccb0_t0((u32)S30);  // @h17_5fd2a0
    u32 x24 = (*(u8 *)S30[0] == 0x5c) ? 0u : 0xffffffffu;  // @h18_5fd2a0
    u32 H = F32(ebx, 1);
    u32 nd = F32(H, 5);
    if (nd != H) {  // @h19_5fd2a0
      for (;;) {
        ext_5f10c0_t1((u32)X3c, nd + 0xd);  // @h20_5fd2a0
        reg.state = 3;
        ext_5fccb0_t0((u32)X3c);  // @h21_5fd2a0
        u32 xb = X3c[0];
        u32 lenS = S30[1] - S30[0];
        u32 lenX = X3c[1] - xb;
        bool found = false;
        u32 fidx = 0;
        if (!(lenS > lenX)) {  // @h22_5fd2a0
          if (lenS == 0) {  // @h23_5fd2a0
            fidx = lenX; found = (fidx != 0xffffffffu);
          } else {
            u32 rem = lenX - lenS;
            u32 xend = rem + lenS + xb;
            u32 rr = ext_5fa640_f(xb, xend, S30[0], S30[0] + lenS, a0, a0, a0);  // @h24_5fd2a0
            if (rr != xend) {  // @h25_5fd2a0
              fidx = rr - X3c[0];
              found = (fidx != 0xffffffffu);
            }
          }
        }
        if (found) {
          if (fidx != 0 && *(u8 *)(fidx + x24 + xb) == 0x5c) {  // @h26_5fd2a0
            u32 val = F32(nd, 0x19);
            u32 it = ext_5fc010_t0(val);  // @h27_5fd2a0
            while (it != 0) {  // @h28_5fd2a0
              u32 kind = F32(it, 0) - 0x14;
              if (kind > 0x10) {  // @h29_5fd2a0
                FPCALL();
              } else if (kind == 1) {  // @h30_5fd2a0
                ext_5fb8b0_t1(it + 0x20, 0x6b87a8);  // @h31_5fd2a0
                u32 o = F32(F32(a0, 0x9e), F32(it, 8));  // @h32_5fd2a0
                ((u32(THISCALL *)(u32))VSLOT(o, 0x28))(o);  // @h33_5fd2a0
              } else if (kind != 0 && kind != 2 && kind != 0x10) {  // @h34_5fd2a0
                FPCALL();
              }
              u32 vp = F32(val, 0x30);
              u32 ix = F32(val, 0x34);
              if (ix < F32(vp, 8)) F32(val, 0x34) = ix + 1;  // @h35_5fd2a0
              u32 vp2 = F32(val, 0x30);
              u32 ix2 = F32(val, 0x34);
              if (ix2 >= F32(vp2, 8)) break;  // @h36_5fd2a0
              it = F32(F32(val, 0x30), 0);
              it = F32(it, ix2 * 4);  // @h37_5fd2a0
            }
          }
          u32 n2 = X3c[2] - X3c[0];
          reg.state = 4;
          if (X3c[0] != 0 && n2 != 0) ext_54f870_t2((u32)X3c, X3c[0], n2);  // @h38_5fd2a0
          break;
        }
        // advance to the next node (in-order successor)
        u32 rgt = F32(nd, 9);
        if (rgt != 0) {  // @h39_5fd2a0
          nd = rgt;
          u32 lf = F32(nd, 5);
          while (lf != 0) { nd = lf; lf = F32(nd, 5); }  // @h40_5fd2a0
        } else {
          u32 par = F32(nd, 1);
          if (nd == F32(par, 9)) {  // @h41_5fd2a0
            do { nd = par; par = F32(par, 1); } while (nd == F32(par, 9));  // @h42_5fd2a0
          }
          if (F32(nd, 9) != par) nd = par;  // @h43_5fd2a0
        }
        u32 n3 = X3c[2] - X3c[0];
        reg.state = 5;
        if (X3c[0] != 0 && n3 != 0) ext_54f870_t2((u32)X3c, X3c[0], n3);  // @h44_5fd2a0
        reg.state = 0;
        if (nd == F32(ebx, 1)) break;  // @h45_5fd2a0
      }
    }
    u32 n4 = S30[2] - S30[0];
    reg.state = 6;
    if (S30[0] != 0 && n4 != 0) ext_54f870_t2((u32)S30, S30[0], n4);  // @h46_5fd2a0
  }
done:
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(5fd2a0, hand_5fd2a0);

extern "C" u32 THISCALL ext_471b50_t3(u32, u32, u32, u32) __asm__("ext_471b50");
extern "C" u32 THISCALL ext_4d8180_t2(u32, u32, u32) __asm__("ext_4d8180");
extern "C" u32 THISCALL hand_480a40(u32 ecx_in, u32 A1, u32 A2, u32 A3) {
  SEH_ENTER(0x667403);  // @h_480a40
  u32 edi = ecx_in;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
#define MGR (F32(G(u32, 0x70039c), 0x9b))
#define REG1A4(x) { u32 t_ = G(u32, 0x70039c); ((u32(THISCALL *)(u32, u32))VSLOT(t_, 0x1a4))(t_, (x)); }
#define LOOK(off, str, line)                                                                   \
  { u32 m_ = MGR; u32 ax_ = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m_, 0x114))(m_, (str), 0, 0x68bcbc, (line)); F16(edi, (off)) = (u16)ax_; }
  ext_471b50_t3(edi, A1, A2, A3);  // @h1_480a40
  F32(edi, 0) = 0x68b650;  // @h2_480a40
  F8(edi, 0x423) = 0;  // @h3_480a40
  F32(edi, 0x42d) = 0;  // @h4_480a40
  F32(edi, 0x431) = 0xc0266666;  // @h5_480a40
  F32(edi, 0x435) = 0;  // @h6_480a40
  reg.state = 0;
  F32(edi, 0x459) = 0;  // @h7_480a40
  F32(edi, 0x455) = 0;  // @h8_480a40
  ext_634d10_cdecl3(edi + 0x45d, 0, 0x80);  // @h9_480a40
  F8(edi, 0x42c) = 0;  // @h10_480a40
  u32 ebx = edi + 0x601;
  F32(edi, 0x60a) = 0;  // @h11_480a40
  F32(edi, 0x606) = 0;  // @h12_480a40
  F32(edi, 0x602) = 0;  // @h13_480a40
  F16(edi, 0x5ff) = 0x101;  // @h14_480a40
  F8(ebx, 0) = 0;  // @h15_480a40
  F32(edi, 0x596) = 0;  // @h16_480a40
  F8(edi, 0x5fe) = 0;  // @h17_480a40
  F32(edi, 0x424) = 0;  // @h18_480a40
  F32(edi, 0x445) = 0;  // @h19_480a40
  F32(edi, 0x449) = 0;  // @h20_480a40
  F32(edi, 0x44d) = 0;  // @h21_480a40
  F32(edi, 0x417) = 0x100;  // @h22_480a40
  {
    u32 o = ext_41e290_cdecl1((u32)0x28);  // @h23_480a40
    reg.state = 1;
    u32 e = 0;
    if (o != 0) e = ext_4cca60_t2(o, 8, 3);  // @h24_480a40
    reg.state = 0;
    F32(edi, 0x61a) = e;  // @h25_480a40
    F32(edi, 0x596) = 0;  // @h26_480a40
    ext_4de7a0_t0(edi + 0x59a);  // @h27_480a40
    F32(edi, 0x5be) = 0;  // @h28_480a40
    F32(edi, 0x5c2) = 0;  // @h29_480a40
    F32(edi, 0x5c6) = 0;  // @h30_480a40
    ext_4de7a0_t0(edi + 0x4f5);  // @h31_480a40
    F32(edi, 0x519) = 0;  // @h32_480a40
    F32(edi, 0x51d) = 0;  // @h33_480a40
    F32(edi, 0x521) = 0;  // @h34_480a40
    F32(edi, 0x439) = 0x420c0000;  // @h35_480a40
    F32(edi, 0x43d) = 0x42c80000;  // @h36_480a40
    F32(edi, 0x441) = 0x420c0000;  // @h37_480a40
    F32(edi, 0x5ca) = 0;  // @h38_480a40
    F32(edi, 0x451) = 0x42c80000;  // @h39_480a40
    F8(edi, 0x412) = 0;  // @h40_480a40
    F8(edi, 0x64a) = 0;  // @h41_480a40
  }
  LOOK(0x61e, 0x68bce8, 0x91)  // @h42_480a40
  LOOK(0x620, 0x68bcf8, 0x92)  // @h43_480a40
  LOOK(0x622, 0x68bd08, 0x93)  // @h44_480a40
  LOOK(0x624, 0x68bd18, 0x94)  // @h45_480a40
  LOOK(0x626, 0x68bd2c, 0x95)  // @h46_480a40
  LOOK(0x628, 0x68bd40, 0x96)  // @h47_480a40
  {
    u32 o = ext_41e290_cdecl1((u32)0x108);  // @h48_480a40
    reg.state = 2;
    u32 d = 0;
    if (o != 0) d = ext_4d8330_t3(o, 0x68bd6c, 0x68bd50, 0x6ffa60);  // @h49_480a40
    F32(edi, 0x632) = d;  // @h50_480a40
    reg.state = 0;
    REG1A4(d)  // @h51_480a40
  }
  {
    u32 o = ext_41e290_cdecl1((u32)0x108);  // @h52_480a40
    reg.state = 3;
    u32 d = 0;
    if (o != 0) d = ext_4d8330_t3(o, 0x68bd98, 0x68bd70, 0x6ffa64);  // @h53_480a40
    F32(edi, 0x62e) = d;  // @h54_480a40
    reg.state = 0;
    REG1A4(d)  // @h55_480a40
  }
  {
    u32 o = ext_41e290_cdecl1((u32)0x108);  // @h56_480a40
    reg.state = 4;
    u32 d = 0;
    if (o != 0) {  // @h57_480a40
      ext_4d8180_t2(o, 0x68bdd0, 0x68bdac);  // @h58_480a40
      F32(o, 0) = 0x68b638;  // @h59_480a40
      F32(o, 0x104) = edi;  // @h60_480a40
      d = o;
    }
    F32(edi, 0x636) = d;  // @h61_480a40
    reg.state = 0;
    REG1A4(d)  // @h62_480a40
  }
  {
    u32 o = ext_41e290_cdecl1((u32)0x108);  // @h63_480a40
    reg.state = 5;
    u32 d = 0;
    if (o != 0) d = ext_4d83b0_t3(o, 0x68be24, 0x68bdd8, edi + 0x64a);  // @h64_480a40
    F32(edi, 0x63a) = d;  // @h65_480a40
    reg.state = 0;
    REG1A4(d)  // @h66_480a40
  }
  {
    u32 o = ext_41e290_cdecl1((u32)0x108);  // @h67_480a40
    reg.state = 6;
    u32 d = 0;
    if (o != 0) {  // @h68_480a40
      ext_4d8180_t2(o, 0x68be5c, 0x68be34);  // @h69_480a40
      F32(o, 0) = 0x68bc9c;  // @h70_480a40
      F32(o, 0x104) = edi;  // @h71_480a40
      d = o;
    }
    F32(edi, 0x62a) = d;  // @h72_480a40
    reg.state = 0;
    REG1A4(d)  // @h73_480a40
  }
  {
    u32 o = ext_41e290_cdecl1((u32)0x108);  // @h74_480a40
    reg.state = 7;
    u32 d = 0;
    if (o != 0) d = ext_4d83b0_t3(o, 0x68be80, 0x68be64, ebx);  // @h75_480a40
    F32(edi, 0x63e) = d;  // @h76_480a40
    reg.state = 0;
    REG1A4(d)  // @h77_480a40
  }
  u32 fl = F32(edi, 0x417);
  if (fl & 0x1800) {  // @h78_480a40
    u32 id = F32(edi, 0x413);
    F32(edi, 0x417) = fl & 0xffffe7ffu;  // @h79_480a40
    u32 m = MGR;
    u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, id);  // @h80_480a40
    if (ob != 0) {  // @h81_480a40
      u32 vt = *(u32 *)ob;
      u32 m2 = MGR;
      u32 ax2 = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))VSLOT(m2, 0x114))(m2, 0x68bedc, 0, 0x68bcbc, 0x280, 0, 0);  // @h82_480a40
      ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x128)))(ob, ax2 & 0xffff);  // @h83_480a40
    }
  }
  F32(edi, 0x413) = 0;  // @h84_480a40
  F32(edi, 0x60e) = 0;  // @h85_480a40
  F32(edi, 0x616) = 0;  // @h86_480a40
  F8(edi, 0x144) = 1;  // @h87_480a40
  F8(edi, 0x146) = 1;  // @h88_480a40
  u32 gl = G(u32, 0x7003b8);
  u32 cnt = F32(gl, 0x408);
  F32(gl + cnt * 4, 0x40c) = edi;  // @h89_480a40
  F32(gl, 0x408) = F32(gl, 0x408) + 1;  // @h90_480a40
  F32(edi, 0x4dd) = 0x7e967699;  // @h91_480a40
  SEH_LEAVE();
  return edi;
#undef F32
#undef F16
#undef F8
#undef MGR
#undef REG1A4
#undef LOOK
}
PCREG(480a40, hand_480a40);

extern "C" u32 THISCALL ext_4998c0_t2(u32, u32, u32) __asm__("ext_4998c0");
extern "C" u32 THISCALL ext_49b360_t2(u32, u32, u32) __asm__("ext_49b360");
extern "C" u32 THISCALL ext_49b330_t1(u32, u32) __asm__("ext_49b330");
extern "C" u32 THISCALL ext_49ab80_t2(u32, u32, u32) __asm__("ext_49ab80");
extern "C" u32 THISCALL ext_499980_t0(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_4989a0_t1(u32, u32) __asm__("ext_4989a0");
extern "C" u32 THISCALL ext_4dc420_t1(u32, u32) __asm__("ext_4dc420");
extern "C" u32 ext_67640c_dummy(...) __asm__("ext_67640c_unused");
extern "C" u32 THISCALL hand_494060(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667f47);  // @h_494060
  u32 esi = ecx_in;
  u8 S90[0x80] __attribute__((aligned(16)));
  u8 S110[0x80] __attribute__((aligned(16)));
  u8 Wb[0x1bc] __attribute__((aligned(16)));
  volatile u32 X250 = 0;
  u32 W = (u32)Wb;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define WVC(off, ...) ((u32(THISCALL *)(u32, ...))0)
#define T0 (G(u32, 0x70039c))
#define NODEITER(ARG)                                                                      \
  {                                                                                        \
    u32 t_ = T0; u32 m_ = F32(t_, 0x9b); u32 oo_ = F32(m_, 0xadc);                         \
    X250 = F32(oo_, 8);                                                                    \
    if (X250 != 0) {                                                                       \
      do {                                                                                 \
        ext_4dc420_t1(X250, (ARG));                                                        \
        t_ = T0; m_ = F32(t_, 0x9b); oo_ = F32(m_, 0xadc);                                 \
        ((u32(THISCALL *)(u32, u32))VSLOT(oo_, 0x50))(oo_, (u32)&X250);                    \
      } while (X250 != 0);                                                                 \
    }                                                                                      \
  }
  {
    u32 t = T0;
    u32 o = F32(t, 0x190f);
    ((u32(THISCALL *)(u32))VSLOT(o, 0x40))(o);  // @h1_494060
  }
  u32 buf = ext_41e290_cdecl1((u32)0x3d0900);  // @h2_494060
  NODEITER(1)  // @h3_494060
  u32 r34 = ((u32(THISCALL *)(u32, u32))VSLOT(esi + 0x1c, 0x34))(esi + 0x1c, 0);  // @h4_494060
  ext_4cbe80_t2((u32)S90, r34 + 6);  // @h5_494060
  reg.state = 0;
  {
    u32 t = T0;
    ((u32(THISCALL *)(u32, u32))VSLOT(t, 0x128))(t, (u32)S110);  // @h6_494060
  }
  reg.state = 1;
  u32 p110 = ext_4cc1d0_t0((u32)S110);
  u32 len = 0;
  while (*(u8 *)(p110 + len)) len++;  // @h7_494060
  u32 q110 = ext_4cc1d0_t0((u32)S110);
  u32 q90 = ext_4cc1d0_t0((u32)S90);
  u32 cmp = ((u32(*)(u32, u32, u32))G(u32, 0x67640c))(q90, q110, len);  // @h8_494060
  u32 sk = (cmp != 0) ? 0 : len;  // @h9_494060
  u32 c90 = ext_4cc1d0_t0((u32)S90);
  if (*(u8 *)(c90 + sk) == 0x5c) sk++;  // @h10_494060
  else {
    c90 = ext_4cc1d0_t0((u32)S90);
    if (*(u8 *)(c90 + sk) == 0x2f) sk++;  // @h11_494060
  }
  ext_4998c0_t2(W, buf, 0x3d0900);  // @h12_494060
  reg.state = 2;
  ext_49b360_t2(W, 0, 0);  // @h13_494060
  ext_49b330_t1(W, 0);  // @h14_494060
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x3c))(W, 0x40);  // @h15_494060
  u32 vt = *(u32 *)W;
  u32 c90b = ext_4cc1d0_t0((u32)S90);
  ((u32(THISCALL *)(u32, u32))(*(u32 *)(vt + 0x5c)))(W, c90b + sk);  // @h16_494060
  u32 bl = ext_49ab80_t2(W, a0, 1) & 0xff;  // @h17_494060
  reg.state = 1;
  ext_499980_t0(W);  // @h18_494060
  ext_4998c0_t2(W, buf, 0x3d0900);  // @h19_494060
  reg.state = 3;
  ext_49b360_t2(W, 5, 0x15);  // @h20_494060
  {
    u32 t = T0;
    u32 o = F32(t, 0x1a9f);
    if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x8c))(o, W);  // @h21_494060
  }
  ext_4989a0_t1(F32(esi, 8), W);  // @h22_494060
  {
    u32 t = T0;
    u32 o = F32(t, 0x1aa3);
    if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x40))(o, W);  // @h23_494060
  }
  {
    u32 o = G(u32, 0x7003a4);
    if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 0xd8))(o, W);  // @h24_494060
  }
  if (G(u32, 0x7003b8) != 0) {  // @h25_494060
    ext_49b330_t1(W, 0x15);  // @h26_494060
    u32 o = G(u32, 0x7003b8);
    ((u32(THISCALL *)(u32, u32))VSLOT(o, 4))(o, W);  // @h27_494060
  }
  ext_49b330_t1(W, 0xa);  // @h28_494060
  {
    u32 t = T0;
    u32 o = F32(t, 0x1907);
    ((u32(THISCALL *)(u32, u32))VSLOT(o, 0xb0))(o, W);  // @h29_494060
  }
  bl |= ext_49ab80_t2(W, a0, 3) & 0xff;  // @h30_494060
  reg.state = 1;
  ext_499980_t0(W);  // @h31_494060
  ext_4998c0_t2(W, buf, 0x3d0900);  // @h32_494060
  reg.state = 4;
  ext_49b360_t2(W, 1, 4);  // @h33_494060
  ext_49b330_t1(W, 1);  // @h34_494060
  vt = *(u32 *)W;
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x60))(W, *(volatile u8 *)(esi + 0xbb0));  // @h35_494060
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x60))(W, *(volatile u8 *)(esi + 0xbb1));  // @h36_494060
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x54))(W, F32(esi, 0xbb3));  // @h37_494060
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x3c))(W, F32(esi, 0x5d41));  // @h38_494060
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x60))(W, *(volatile u8 *)(esi + 0xbac));  // @h39_494060
  {
    u32 t = T0;
    ((u32(THISCALL *)(u32, u32))VSLOT(t, 0))(t, W);  // @h40_494060
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 8))(W, 3);  // @h41_494060
  {
    u32 t = T0; u32 m = F32(t, 0x9b);
    u32 o = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h42_494060
    ((u32(THISCALL *)(u32, u32))VSLOT(o, 4))(o, W);  // @h43_494060
    t = T0; m = F32(t, 0x9b);
    o = ((u32(THISCALL *)(u32))VSLOT(m, 0x134))(m);  // @h44_494060
    ((u32(THISCALL *)(u32, u32))VSLOT(o, 4))(o, W);  // @h45_494060
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(W, 8))(W, 4);  // @h46_494060
  {
    u32 pp = esi + 0xc4d;
    for (u32 q = 0x402; q != 0; q--) {  // @h47_494060
      ((u32(THISCALL *)(u32, u32))VSLOT(W, 0x5c))(W, F32(pp, 0));  // @h48_494060
      pp += 4;  // @h49_494060
    }
  }
  bl |= ext_49ab80_t2(W, a0, 2) & 0xff;  // @h50_494060
  reg.state = 1;
  ext_499980_t0(W);  // @h51_494060
  ext_634273_cdecl2(buf, 1);  // @h52_494060
  NODEITER(0)  // @h53_494060
  ext_4cbec0_t0((u32)S110);  // @h54_494060
  ext_4cbec0_t0((u32)S90);  // @h55_494060
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return bl;
#undef F32
#undef T0
#undef NODEITER
#undef WVC
}
PCREG(494060, hand_494060);

extern "C" u32 THISCALL hand_4d3200(u32 ecx_in) {
  SEH_ENTER(0x6693eb);  // @h_4d3200
  u32 thisp = ecx_in;
  u8 b28[0x2710] __attribute__((aligned(16)));
  u8 b418[0x400] __attribute__((aligned(16)));
  u8 X18[8];
  u8 S2ba8[0x80] __attribute__((aligned(16)));
  volatile u32 X2bbc = 0;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define OBJLOG(LINE) ({ u32 c_ = G(u32, 0x700390); ((u32(THISCALL *)(u32, u32, u32))VSLOT(c_, 0x20))(c_, 0x696418, (LINE)); })
#define CALL2C(o_, ...) ((u32(*)(u32, ...))VSLOT((o_), 0x2c))((o_), __VA_ARGS__)
#define SPF(o2_, ...) ((u32(*)(u32, ...))VSLOT((o2_), 0x198))((o2_), __VA_ARGS__)
#define GETO2() ({ u32 g_ = G(u32, 0x70039c); ((u32(THISCALL *)(u32))VSLOT(g_, 0x190))(g_); })
  {
    u32 o0 = OBJLOG(0x27d);  // @h1_4d3200
    CALL2C(o0, 0x69643c);  // @h2_4d3200
  }
  u32 L = thisp + 0x4008;
  u32 edx = 0;
  if (L == 0) goto done;  // @h3_4d3200
  ((u32(THISCALL *)(u32, u32))VSLOT(L, 0x4c))(L, (u32)&X2bbc);  // @h4_4d3200
  edx = ((u32(THISCALL *)(u32, u32))VSLOT(L, 0x5c))(L, (u32)&X2bbc);  // @h5_4d3200
  if (X2bbc == 0) goto done;  // @h6_4d3200
  for (;;) {
    u32 hdr = F32(edx, 4);
    u32 esi = edx + 0xc;
    u32 edi = F32(edx, 0) + 0xc + edx;  // @h7_4d3200
    X18[0] = *(u8 *)(hdr + 3);  // @h8_4d3200
    X18[1] = *(u8 *)(hdr + 2);  // @h9_4d3200
    X18[2] = *(u8 *)(hdr + 1);  // @h10_4d3200
    X18[3] = *(u8 *)hdr;  // @h11_4d3200
    X18[4] = 0;
    b28[0] = 0;
    u32 t = F32(hdr, 8) - 2;  // @h12_4d3200
    u32 sel;
    if (t > 0xf) sel = 7;  // @h13_4d3200
    else { static const u8 tb[16] = {0, 1, 2, 7, 7, 7, 7, 7, 7, 7, 3, 7, 3, 4, 5, 6}; sel = tb[t]; }
    switch (sel) {
      case 0:
      case 1: {
        bool isf = (sel == 1);
        u32 cntw = F32(edx, 8) >> 2;  // @h14_4d3200
        if (cntw == 1) {  // @h15_4d3200
          u32 o = OBJLOG(isf ? 0x2a1 : 0x293);  // @h16_4d3200
          if (isf) CALL2C(o, 0x696480, esi, (double)*(volatile float *)edi);  // @h17_4d3200
          else CALL2C(o, 0x696450, esi, F32(edi, 0));  // @h18_4d3200
        } else {
          u32 o2 = GETO2();  // @h19_4d3200
          SPF(o2, (u32)b418, 0x696460, esi, cntw);  // @h20_4d3200
          for (u32 k = 0; cntw != 0 && k != cntw; k++) {  // @h21_4d3200
            o2 = GETO2();  // @h22_4d3200
            if (isf) SPF(o2, (u32)b28, 0x696494, (u32)b28, (double)*(volatile float *)(edi + k * 4));  // @h23_4d3200
            else SPF(o2, (u32)b28, 0x696468, (u32)b28, F32(edi, k * 4));  // @h24_4d3200
          }
          u32 sl = 0;
          while (b28[sl]) sl++;  // @h25_4d3200
          u32 idx = sl - 1;
          if (idx >= 0x2710) { ext_634047_v(); goto done; }  // @h26_4d3200
          b28[idx] = 0;  // @h27_4d3200
          u32 o = OBJLOG(isf ? 0x2a6 : 0x298);  // @h28_4d3200
          CALL2C(o, isf ? 0x69649c : 0x696470, (u32)b418, (u32)b28);  // @h29_4d3200
        }
        break;
      }
      case 2: {
        u32 o = OBJLOG(0x2e7);  // @h30_4d3200
        CALL2C(o, 0x69650c, esi, F32(edi, 0));  // @h31_4d3200
        break;
      }
      case 3: {
        u32 o = OBJLOG(0x2bd);  // @h32_4d3200
        CALL2C(o, 0x6964ac, esi, edi, (u32)X18);  // @h33_4d3200
        break;
      }
      case 4:
      case 6: {
        if (sel == 6) FPCALL();  // @h34_4d3200
        u32 o = OBJLOG(0x2e2);  // @h35_4d3200
        CALL2C(o, 0x6964f0, esi, F32(edi, 0), (u32)X18);  // @h36_4d3200
        break;
      }
      case 5: {
        u32 id = F32(edi, 0);
        u32 ebx = 0;
        if ((int)id >= 0) {  // @h37_4d3200
          u32 g = G(u32, 0x70039c);
          u32 m = F32(g, 0x9b);
          ebx = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, id);  // @h38_4d3200
        }
        u32 clg = G(u32, 0x700390);
        if (ebx != 0) {  // @h39_4d3200
          u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(clg, 0x20))(clg, 0x696418, 0x2c7);  // @h40_4d3200
          u32 so = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x1d8))(ebx, (u32)S2ba8, 1);  // @h41_4d3200
          u32 vo = *(u32 *)o;
          reg.state = 0;
          u32 cs = ext_4cc1d0_t0(so);
          ((u32(*)(u32, ...))(*(u32 *)(vo + 0x2c)))(o, 0x6964ac, esi, cs, (u32)X18);  // @h42_4d3200
          reg.state = -1;
          ext_4cbec0_t0((u32)S2ba8);  // @h43_4d3200
        } else {
          u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(clg, 0x20))(clg, 0x696418, 0x2c9);  // @h44_4d3200
          CALL2C(o, 0x6964cc, esi, (u32)X18);  // @h45_4d3200
        }
        break;
      }
      default: {
        u32 o = OBJLOG(0x2ec);  // @h46_4d3200
        CALL2C(o, 0x69651c, esi, (u32)X18);  // @h47_4d3200
        break;
      }
    }
    edx = ((u32(THISCALL *)(u32, u32))VSLOT(L, 0x5c))(L, (u32)&X2bbc);  // @h48_4d3200
    if (X2bbc == 0) break;  // @h49_4d3200
  }
done:
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef OBJLOG
#undef CALL2C
#undef SPF
#undef GETO2
}
PCREG(4d3200, hand_4d3200);

extern "C" u32 THISCALL ext_526ef0_t0(u32) __asm__("ext_526ef0");
extern "C" u32 THISCALL ext_5273b0_t0(u32) __asm__("ext_5273b0");
extern "C" u32 THISCALL ext_5167d0_t0(u32) __asm__("ext_5167d0");
extern "C" u32 THISCALL ext_4e1b60_t0(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_511c60_t0(u32) __asm__("ext_511c60");
extern "C" u32 THISCALL ext_511cd0_t3(u32, u32, u32, u32) __asm__("ext_511cd0");
extern "C" u32 THISCALL hand_51b790(u32 ecx_in, u32 A1, u32 A2, u32 A3) {
  SEH_ENTER(0x66a2b6);  // @h_51b790
  u32 edi = ecx_in;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define BITS(off) F32(edi, (off))
  ext_511cd0_t3(edi, A1, A2, A3);  // @h0_51b790
  reg.state = 0;
  F32(edi, 0) = 0x69f514;  // @h0a_51b790
  ext_526ef0_t0(edi + 0x29a);  // @h0b_51b790
  for (u32 k = 0; k < 3; k++) ext_526ef0_t0(edi + 0x2c3 + k * 0x29);  // @h0c_51b790
  ext_5273b0_t0(edi + 0x34e);  // @h0d_51b790
  ext_526ef0_t0(edi + 0x39f);  // @h0e_51b790
  ext_526ef0_t0(edi + 0x3c8);  // @h0f_51b790
  ext_5167d0_t0(edi + 0x4ad);  // @h0g_51b790
  reg.state = 1;
  ext_4e1b60_t0(edi + 0x526);  // @h0h_51b790
  ext_511c60_t0(edi + 0x59b);  // @h0i_51b790
  F32(edi, 0x22e) = 0x0;  // @h1_51b790
  F32(edi, 0x232) = 0x0;  // @h2_51b790
  F32(edi, 0x236) = 0x0;  // @h3_51b790
  F32(edi, 0x23a) = 0x0;  // @h4_51b790
  F32(edi, 0x3fd) = 0x0;  // @h5_51b790
  F32(edi, 0x44d) = 0x0;  // @h6_51b790
  F32(edi, 0x469) = 0x0;  // @h7_51b790
  F32(edi, 0x46d) = 0x0;  // @h8_51b790
  F32(edi, 0x471) = 0x0;  // @h9_51b790
  F32(edi, 0x475) = 0x0;  // @h10_51b790
  F32(edi, 0x479) = 0x0;  // @h11_51b790
  F32(edi, 0x465) = 0x0;  // @h12_51b790
  F32(edi, 0x461) = 0x0;  // @h13_51b790
  F32(edi, 0x45d) = 0x0;  // @h14_51b790
  F32(edi, 0x405) = 0x0;  // @h15_51b790
  F32(edi, 0x409) = 0x0;  // @h16_51b790
  F32(edi, 0x40d) = 0x0;  // @h17_51b790
  ext_634d10_cdecl3(edi + 0x411, 0, 0x38);  // @hm_51b790
  F32(edi, 0x449) = 0x0;  // @h18_51b790
  F32(edi, 0x455) = 0x0;  // @h19_51b790
  F32(edi, 0x459) = 0x0;  // @h20_51b790
  F32(edi, 0x481) = 0x0;  // @h21_51b790
  F32(edi, 0x47d) = 0x0;  // @h22_51b790
  F32(edi, 0x485) = 0x7e967699;  // @h23_51b790
  F32(edi, 0x489) = 0x7e967699;  // @h24_51b790
  F32(edi, 0x48d) = 0x7e967699;  // @h25_51b790
  F32(edi, 0x26e) = 0x0;  // @h26_51b790
  F32(edi, 0x272) = 0x0;  // @h27_51b790
  F32(edi, 0x276) = 0x0;  // @h28_51b790
  F32(edi, 0x27a) = 0x0;  // @h29_51b790
  F32(edi, 0x27e) = 0x0;  // @h30_51b790
  F32(edi, 0x282) = 0x0;  // @h31_51b790
  F32(edi, 0x286) = 0x0;  // @h32_51b790
  F32(edi, 0x28a) = 0x0;  // @h33_51b790
  F32(edi, 0x28e) = 0x0;  // @h34_51b790
  F32(edi, 0x292) = 0x0;  // @h35_51b790
  F32(edi, 0x296) = 0x0;  // @h36_51b790
  { u32 ob_ = edi + 0x29a; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x39000000, 0, 0); }  // @h37_51b790
  { u32 ob_ = edi + 0x29a; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 4))(ob_, BITS(0x26e), BITS(0x272), 0); }  // @h38_51b790
  { u32 ob_ = edi + 0x2c3; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x39000000, 0, 0); }  // @h39_51b790
  { u32 ob_ = edi + 0x2ec; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x39000000, 0, 0); }  // @h40_51b790
  { u32 ob_ = edi + 0x315; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x39000000, 0, 0); }  // @h41_51b790
  { u32 ob_ = edi + 0x2c3; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 4))(ob_, BITS(0x276), BITS(0x282), 0); }  // @h42_51b790
  { u32 ob_ = edi + 0x2ec; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 4))(ob_, BITS(0x27a), BITS(0x286), 0); }  // @h43_51b790
  { u32 ob_ = edi + 0x315; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 4))(ob_, BITS(0x27e), BITS(0x28a), 0); }  // @h44_51b790
  F32(edi, 0x33e) = 0x0;  // @h45_51b790
  F32(edi, 0x346) = 0x0;  // @h46_51b790
  F32(edi, 0x342) = 0x0;  // @h47_51b790
  F32(edi, 0x34a) = 0x0;  // @h48_51b790
  { u32 ob_ = edi + 0x39f; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x3e32b8c2, 0x3d0efa35, 0x3f860a92); }  // @h49_51b790
  { u32 ob_ = edi + 0x3c8; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x3e32b8c2, 0x3d0efa35, 0x3f860a92); }  // @h50_51b790
  { u32 ob_ = edi + 0x34e; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 0))(ob_, 0x3f32b8c2, 0x3d0efa35, 0x40c90fdb); }  // @h51_51b790
  { u32 ob_ = edi + 0x39f; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 4))(ob_, BITS(0x236), BITS(0x23a), 0); }  // @h52_51b790
  { u32 ob_ = edi + 0x3c8; ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ob_, 4))(ob_, BITS(0x22e), BITS(0x232), 0); }  // @h53_51b790
  F32(edi, 0x593) = 0xfe967699;  // @h54_51b790
  F32(edi, 0x597) = 0x7e967699;  // @h55_51b790
  { u32 m_ = F32(G(u32, 0x70039c), 0x9b); u32 ax_ = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m_, 0x114))(m_, 0x69ea9c, 0, 0x69f8b8, 0x5e); *(volatile u16 *)(edi + 0x5d3) = (u16)ax_; }  // @h56_51b790
  { u32 m_ = F32(G(u32, 0x70039c), 0x9b); u32 ax_ = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m_, 0x114))(m_, 0x69f8e4, 0, 0x69f8b8, 0x5f); *(volatile u16 *)(edi + 0x5d5) = (u16)ax_; }  // @h57_51b790
  { u32 m_ = F32(G(u32, 0x70039c), 0x9b); u32 ax_ = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m_, 0x114))(m_, 0x692af4, 0, 0x69f8b8, 0x60); *(volatile u16 *)(edi + 0x5d7) = (u16)ax_; }  // @h58_51b790
  F32(edi, 0x491) = 0x0;  // @h59_51b790
  F32(edi, 0x495) = 0x0;  // @h60_51b790
  F32(edi, 0x499) = 0x0;  // @h61_51b790
  F32(edi, 0x49d) = 0x0;  // @h62_51b790
  F32(edi, 0x4a1) = 0x0;  // @h63_51b790
  F32(edi, 0x4a5) = 0x0;  // @h64_51b790
  F32(edi, 0x4a9) = 0x0;  // @h65_51b790
  SEH_LEAVE();
  return edi;
#undef F32
#undef BITS
}
PCREG(51b790, hand_51b790);

extern "C" u32 THISCALL ext_42c9a0_t0(u32) __asm__("ext_42c9a0");
extern "C" u32 THISCALL hand_42b460(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x664b9e);  // @h_42b460
  u32 esi = ecx_in;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  F32(esi, 0x0) = 0x6797a0;  // @h1_42b460
  F32(esi, 0x1c) = 0x0;  // @h2_42b460
  F32(esi, 0x24) = 0x0;  // @h3_42b460
  F32(esi, 0x30) = 0x0;  // @h4_42b460
  F32(esi, 0x38) = 0x0;  // @h5_42b460
  F32(esi, 0x40) = 0x0;  // @h6_42b460
  F32(esi, 0x44) = 0x0;  // @h7_42b460
  F32(esi, 0x4c) = 0x0;  // @h8_42b460
  F32(esi, 0x50) = 0x0;  // @h9_42b460
  ext_4cbeb0_t0(esi + 0xa3);  // @h10_42b460
  reg.state = 0;
  ext_4cbeb0_t0(esi + 0x123);  // @h11_42b460
  reg.state = 1;
  ext_4cbeb0_t0(esi + 0x1a3);  // @h12_42b460
  reg.state = 2;
  ext_4cbeb0_t0(esi + 0x223);  // @h13_42b460
  reg.state = 3;
  ext_4cbe80_t2(esi + 0x2a3, 0x679970);  // @h14_42b460
  reg.state = 4;
  ext_4cbeb0_t0(esi + 0x323);  // @h15_42b460
  reg.state = 5;
  ext_4cbeb0_t0(esi + 0x3a3);  // @h16_42b460
  reg.state = 6;
  ext_4cbeb0_t0(esi + 0x423);  // @h17_42b460
  reg.state = 7;
  ext_4cbe80_t2(esi + 0x4a3, 0x679980);  // @h18_42b460
  reg.state = 8;
  ext_4cbeb0_t0(esi + 0x523);  // @h19_42b460
  reg.state = 9;
  ext_4cbeb0_t0(esi + 0x5a3);  // @h20_42b460
  reg.state = 10;
  ext_4cbeb0_t0(esi + 0x623);  // @h21_42b460
  reg.state = 11;
  ext_4cbeb0_t0(esi + 0x6a3);  // @h22_42b460
  reg.state = 12;
  ext_4cbeb0_t0(esi + 0x723);  // @h23_42b460
  reg.state = 13;
  ext_4cbeb0_t0(esi + 0x7a3);  // @h24_42b460
  reg.state = 14;
  ext_4cbeb0_t0(esi + 0x823);  // @h25_42b460
  reg.state = 15;
  ext_4cbeb0_t0(esi + 0x8a3);  // @h26_42b460
  reg.state = 16;
  ext_4cbeb0_t0(esi + 0x923);  // @h27_42b460
  reg.state = 17;
  F32(esi, 0x9cf) = A1;  // @h28_42b460
  ext_4cbeb0_t0(esi + 0x1917);  // @h29_42b460
  reg.state = 18;
  ext_4cbeb0_t0(esi + 0x1997);  // @h30_42b460
  reg.state = 19;
  ext_4cbeb0_t0(esi + 0x1a17);  // @h31_42b460
  reg.state = 20;
  F32(esi, 0x1a9f) = 0x0;  // @h32_42b460
  F32(esi, 0x1aa3) = 0x0;  // @h33_42b460
  F32(esi, 0x1aa7) = 0x0;  // @h34_42b460
  ext_4cbeb0_t0(esi + 0x1ab7);  // @h35_42b460
  F8(esi, 0x1b5c) = 0x0;  // @h36_42b460
  F8(esi, 0x1a98) = 0x1;  // @h37_42b460
  F32(esi, 0x1b51) = 0x0;  // @h38_42b460
  F32(esi, 0x1b55) = 0x0;  // @h39_42b460
  F8(esi, 0x1b59) = 0x0;  // @h40_42b460
  G(u32, 0x70039c) = esi;  // @h41_42b460
  F32(esi, 0x1aab) = 0x0;  // @h42_42b460
  F16(esi, 0x9b7) = 0x0;  // @h43_42b460
  F32(esi, 0x64) = 0x1000000;  // @h44_42b460
  F32(esi, 0x60) = 0x0;  // @h45_42b460
  F32(esi, 0x1b40) = 0x3f800000;  // @h46_42b460
  F32(esi, 0x1b44) = 0x0;  // @h47_42b460
  F8(esi, 0x1b48) = 0x1;  // @h48_42b460
  F8(esi, 0x1a9c) = 0x0;  // @h49_42b460
  F32(esi, 0x9e3) = 0x0;  // @h50_42b460
  F8(esi, 0x1a97) = 0x0;  // @h51_42b460
  F32(esi, 0x7f) = 0x0;  // @h52_42b460
  F32(esi, 0x93) = 0x0;  // @h53_42b460
  F32(esi, 0x97) = 0x1;  // @h54_42b460
  F32(esi, 0x8f) = 0x2;  // @h55_42b460
  F32(esi, 0x68) = 0x1;  // @h56_42b460
  F16(esi, 0x6c) = 0x0;  // @h57_42b460
  F8(esi, 0x6e) = 0x0;  // @h58_42b460
  F8(esi, 0x9b9) = 0x0;  // @h59_42b460
  F32(esi, 0x9a3) = 0xffffffff;  // @h60_42b460
  F32(esi, 0x1b37) = 0x0;  // @h61_42b460
  F32(esi, 0x9c7) = 0x0;  // @h62_42b460
  F32(esi, 0x58) = 0x0;  // @h63_42b460
  F32(esi, 0x9bb) = 0x0;  // @h64_42b460
  F32(esi, 0x9bf) = 0x0;  // @h65_42b460
  F32(esi, 0x190b) = 0x6e48b8;  // @h66_42b460
  F8(esi, 0x1b3e) = 0x0;  // @h67_42b460
  F32(esi, 0x190f) = 0x0;  // @h68_42b460
  F32(esi, 0x9a7) = 0x3e000000;  // @h69_42b460
  F32(esi, 0x9ab) = 0x3ef5c28f;  // @h70_42b460
  F32(esi, 0x9af) = 0x3f400000;  // @h71_42b460
  F32(esi, 0x9b3) = 0x3d23d70a;  // @h72_42b460
  reg.state = 21;
  F32(esi, 0x1b4d) = 0x0;  // @h73_42b460
  F32(esi, 0x54) = 0x42700000;  // @h74_42b460
  F32(esi, 0x4c) = 0x0;  // @h75_42b460
  F32(esi, 0x48) = 0x0;  // @h76_42b460
  F32(esi, 0x34) = 0x0;  // @h77_42b460
  F32(esi, 0x20) = 0x0;  // @h78_42b460
  F32(esi, 0x1c) = 0x0;  // @h79_42b460
  F32(esi, 0x24) = 0x0;  // @h80_42b460
  F32(esi, 0x54) = 0x42700000;  // @h81_42b460
  F32(esi, 0x3c) = 0x1;  // @h82_42b460
  F32(esi, 0x5c) = 0x0;  // @h83_42b460
  F8(esi, 0x1b5b) = 0x0;  // @h84_42b460
  {
    u8 S90[0x80] __attribute__((aligned(16)));
    ext_4cbe80_t2((u32)S90, 0x679998);  // @h85_42b460
    reg.state = 22;
    ext_4cbee0_t2(esi + 0x8a3, (u32)S90);  // @h86_42b460
    reg.state = 21;
    ext_4cbec0_t0((u32)S90);  // @h87_42b460
    ext_4cbf30_t1(esi + 0x7a3, 0);  // @h88_42b460
    ext_4cbf30_t1(esi + 0x823, 0);  // @h89_42b460
    ext_4cbe80_t2((u32)S90, 0x6799a4);  // @h90_42b460
    reg.state = 23;
    ext_4cbee0_t2(esi + 0x1a3, (u32)S90);  // @h91_42b460
    reg.state = 21;
    ext_4cbec0_t0((u32)S90);  // @h92_42b460
  }
  F32(esi, 0x1b5d) = 0;  // @h93_42b460
  F16(esi, 0x1b3b) = 0x100;  // @h94_42b460
  F8(esi, 0x1b3d) = 1;  // @h95_42b460
  u32 a1 = ext_41e290_cdecl1((u32)0xc);  // @h96_42b460
  if (a1 != 0) { F32(a1, 0) = 0; F32(a1, 4) = 0; F32(a1, 8) = 0; }  // @h97_42b460
  F32(esi, 0x1b61) = a1;  // @h98_42b460
  u32 hv = ext_41e290_cdecl1((u32)9);  // @h99_42b460
  reg.state = 24;
  if (hv != 0) {
    F32(hv, 0) = 0;
    u32 hdr = ext_6014a0_s1(0x25);  // @h100_42b460
    F32(hv, 0) = hdr;
    F32(hv, 4) = 0;  // @h101_42b460
    *(volatile u8 *)hdr = 0;
    F32(hdr, 1) = 0;  // @h102_42b460
    F32(hdr, 5) = hdr;  // @h103_42b460
    F32(hdr, 9) = hdr;  // @h104_42b460
  }
  reg.state = 21;
  F32(esi, 0x1b65) = hv;  // @h105_42b460
  u32 a2 = ext_41e290_cdecl1((u32)0xc);  // @h106_42b460
  if (a2 != 0) { F32(a2, 0) = 0; F32(a2, 4) = 0; F32(a2, 8) = 0; }  // @h107_42b460
  F32(esi, 0x1b69) = a2;  // @h108_42b460
  u32 a3 = ext_41e290_cdecl1((u32)0xc);  // @h109_42b460
  if (a3 != 0) { F32(a3, 0) = 0; F32(a3, 4) = 0; F32(a3, 8) = 0; }  // @h110_42b460
  F32(esi, 0x1b6d) = a3;  // @h111_42b460
  ext_42c9a0_t0(esi);  // @h112_42b460
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return esi;
#undef F32
#undef F16
#undef F8
}
PCREG(42b460, hand_42b460);
extern "C" u32 THISCALL ext_662750_t0(u32) __asm__("ext_662750");
extern "C" u32 THISCALL ext_662be0_t0(u32) __asm__("ext_662be0");
extern "C" u32 THISCALL ext_662ed0_t0(u32) __asm__("ext_662ed0");
extern "C" u32 THISCALL hand_5cce70(u32 ecx_in) {
  SEH_ENTER(0x66c86a);
  u32 esi = ecx_in;
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  ext_469870_t0(esi);  // @h1_5cce70
  F32(esi, 4) |= 0x20;  // @h2_5cce70
  F32(esi, 0x44) = 0x0;  // @h3_5cce70
  F32(esi, 0x0) = 0x6b4dd4;  // @h4_5cce70
  F32(esi, 0x48) = 0x0;  // @h5_5cce70
  F32(esi, 0xa54) = 0x0;  // @h6_5cce70
  F32(esi, 0xa58) = 0x0;  // @h7_5cce70
  F32(esi, 0xaa6) = 0x0;  // @h8_5cce70
  F32(esi, 0xab7) = 0x0;  // @h9_5cce70
  reg.state = 0;
  F32(esi, 0xae9) = 0x0;  // @h10_5cce70
  ext_4e1b60_t0(esi + 0xb5b);  // @h11_5cce70
  F32(esi, 0xbc9) = 0x0;  // @h12_5cce70
  ext_662750_t0(esi + 0xbd5);  // @h13_5cce70
  ext_662750_t0(esi + 0xbf2);  // @h14_5cce70
  F32(esi, 0xc0f) = 0x0;  // @h15_5cce70
  F32(esi, 0xc13) = 0x0;  // @h16_5cce70
  F32(esi, 0xc17) = 0x0;  // @h17_5cce70
  F32(esi, 0xc1b) = 0x0;  // @h18_5cce70
  F8(esi, 0xc1f) = 0x1;  // @h19_5cce70
  F32(esi, 0xc20) = 0x0;  // @h20_5cce70
  F32(esi, 0xc24) = 0x0;  // @h21_5cce70
  F32(esi, 0xc28) = 0x3f800000;  // @h22_5cce70
  F32(esi, 0xc2c) = 0x0;  // @h23_5cce70
  F32(esi, 0xc30) = 0x0;  // @h24_5cce70
  F32(esi, 0xc34) = 0x0;  // @h25_5cce70
  F32(esi, 0xc38) = 0x3ba3d70a;  // @h26_5cce70
  F32(esi, 0xc3c) = 0x0;  // @h27_5cce70
  F32(esi, 0xc40) = 0x0;  // @h28_5cce70
  F32(esi, 0xc44) = 0x0;  // @h29_5cce70
  F32(esi, 0xc48) = 0x0;  // @h30_5cce70
  F8(esi, 0xc4c) = 0x1;  // @h31_5cce70
  F32(esi, 0xc4d) = 0x0;  // @h32_5cce70
  F32(esi, 0xc51) = 0x0;  // @h33_5cce70
  F32(esi, 0xc55) = 0x3f800000;  // @h34_5cce70
  F32(esi, 0xc59) = 0x0;  // @h35_5cce70
  F32(esi, 0xc5d) = 0x0;  // @h36_5cce70
  F32(esi, 0xc61) = 0x0;  // @h37_5cce70
  F32(esi, 0xc65) = 0x3ba3d70a;  // @h38_5cce70
  ext_662be0_t0(esi + 0xd36);  // @h39_5cce70
  ext_662ed0_t0(esi + 0xd87);  // @h40_5cce70
  F32(esi, 0xe1c) = 0x1;  // @h41_5cce70
  u32 sysobj = G(u32, 0x70039c);
  volatile u32 loc10 = 0xcccccccc;
  u8 vr = ((u8(THISCALL *)(u32, u32, u32))VSLOT(sysobj, 0x5c))(sysobj, 0x6b4e68, (u32)&loc10);  // @h42_5cce70
  if (vr != 0) {
    u32 cr = ((u32(*)(u32, u32))G(u32, 0x676414))(0x67b0d8, loc10);  // @h43_5cce70
    if (cr == 0) F32(esi, 0xe1c) = cr;  // @h44_5cce70
  }
  F32(esi, 0xe18) = 0x0;  // @h45_5cce70
  F32(esi, 0xa54) = 0x0;  // @h46_5cce70
  F32(esi, 0xa5c) = 0x0;  // @h47_5cce70
  F32(esi, 0xa60) = 0x0;  // @h48_5cce70
  F32(esi, 0xa64) = 0x0;  // @h49_5cce70
  F32(esi, 0xa68) = 0x0;  // @h50_5cce70
  F32(esi, 0xa6c) = 0x0;  // @h51_5cce70
  F16(esi, 0xa70) = 0x0;  // @h52_5cce70
  F16(esi, 0xd33) = 0x0;  // @h53_5cce70
  F32(esi, 0xe0f) = 0x0;  // @h54_5cce70
  F32(esi, 0xe13) = 0x0;  // @h55_5cce70
  F32(esi, 0xb35) = 0x0;  // @h56_5cce70
  F32(esi, 0xad5) = 0x0;  // @h57_5cce70
  F32(esi, 0xad9) = 0x3f800000;  // @h58_5cce70
  F32(esi, 0xadd) = 0x3f800000;  // @h59_5cce70
  F8(esi, 0xad4) = 0x1;  // @h60_5cce70
  F32(esi, 0xae9) = 0x0;  // @h61_5cce70
  F32(esi, 0xaed) = 0x0;  // @h62_5cce70
  F32(esi, 0xaf1) = 0x0;  // @h63_5cce70
  F32(esi, 0xaf5) = 0x0;  // @h64_5cce70
  F32(esi, 0xaf9) = 0x3e7a35dd;  // @h65_5cce70
  F32(esi, 0xb0d) = 0x40a00000;  // @h66_5cce70
  F32(esi, 0xb01) = 0x3f800000;  // @h67_5cce70
  F32(esi, 0xb09) = 0x3f000000;  // @h68_5cce70
  F32(esi, 0xafd) = 0x3edf66f3;  // @h69_5cce70
  F16(esi, 0xb19) = 0x100;  // @h70_5cce70
  F32(esi, 0xb05) = 0x3f800000;  // @h71_5cce70
  F32(esi, 0xa96) = 0xbf9c61aa;  // @h72_5cce70
  F32(esi, 0xa9a) = 0x3f860a92;  // @h73_5cce70
  F32(esi, 0xa9e) = 0xbf9c61aa;  // @h74_5cce70
  F32(esi, 0xaa2) = 0x3f860a92;  // @h75_5cce70
  F32(esi, 0xb1b) = 0x0;  // @h76_5cce70
  F32(esi, 0xd0d) = 0x0;  // @h77_5cce70
  F32(esi, 0xdf5) = 0x3ea0d97c;  // @h78_5cce70
  F32(esi, 0xdf9) = 0x3ea0d97c;  // @h79_5cce70
  F32(esi, 0xdfd) = 0x453b8000;  // @h80_5cce70
  F32(esi, 0xe01) = 0x4b095440;  // @h81_5cce70
  F8(esi, 0xd32) = 0x1;  // @h82_5cce70
  F32(esi, 0xb1f) = 0x0;  // @h83_5cce70
  F32(esi, 0xb23) = 0x0;  // @h84_5cce70
  F32(esi, 0xb27) = 0x0;  // @h85_5cce70
  F32(esi, 0xb2b) = 0x0;  // @h86_5cce70
  F32(esi, 0xb2f) = 0x0;  // @h87_5cce70
  F16(esi, 0xb33) = 0x0;  // @h88_5cce70
  F16(esi, 0xe0d) = 0x0;  // @h89_5cce70
  F32(esi, 0xb54) = 0x0;  // @h90_5cce70
  F8(esi, 0xb4f) = 0x0;  // @h91_5cce70
  F32(esi, 0xae5) = 0x0;  // @h92_5cce70
  F32(esi, 0xb45) = 0x0;  // @h93_5cce70
  F8(esi, 0xb4d) = 0x0;  // @h94_5cce70
  F8(esi, 0xab6) = 0x0;  // @h95_5cce70
  F32(esi, 0xab7) = 0x0;  // @h96_5cce70
  F8(esi, 0xd35) = 0x0;  // @h97_5cce70
  F8(esi, 0xdd8) = 0x0;  // @h98_5cce70
  F32(esi, 0xdd9) = 0x0;  // @h99_5cce70
  F32(esi, 0xd15) = 0x0;  // @h100_5cce70
  F32(esi, 0xd19) = 0x0;  // @h101_5cce70
  F32(esi, 0xd1d) = 0x0;  // @h102_5cce70
  F32(esi, 0xd22) = 0x0;  // @h103_5cce70
  F32(esi, 0xd26) = 0x0;  // @h104_5cce70
  F32(esi, 0xd2a) = 0x0;  // @h105_5cce70
  F32(esi, 0xa72) = 0x0;  // @h106_5cce70
  F32(esi, 0xa76) = 0x0;  // @h107_5cce70
  F32(esi, 0xa7a) = 0x42c80000;  // @h108_5cce70
  F32(esi, 0xa8a) = 0x0;  // @h109_5cce70
  F32(esi, 0xa8e) = 0x0;  // @h110_5cce70
  F32(esi, 0xa92) = 0x0;  // @h111_5cce70
  F32(esi, 0xa7e) = 0x0;  // @h112_5cce70
  F32(esi, 0xa82) = 0x0;  // @h113_5cce70
  F32(esi, 0xa86) = 0x0;  // @h114_5cce70
  F32(esi, 0xc7d) = 0x0;  // @h115_5cce70
  F32(esi, 0xc81) = 0x0;  // @h116_5cce70
  F32(esi, 0xc85) = 0x0;  // @h117_5cce70
  F32(esi, 0xc71) = 0x0;  // @h118_5cce70
  F32(esi, 0xc75) = 0x0;  // @h119_5cce70
  F32(esi, 0xc79) = 0x0;  // @h120_5cce70
  ext_4de7a0_t0(esi + 0xc89);  // @h121_5cce70
  F32(esi, 0xb35) = 0x0;  // @h122_5cce70
  F32(esi, 0xb50) = 0x0;  // @h123_5cce70
  F32(esi, 0xbcd) = 0xfffffffb;  // @h124_5cce70
  F32(esi, 0xd2e) = 0x0;  // @h125_5cce70
  F32(esi, 0xd11) = 0x0;  // @h126_5cce70
  F32(esi, 0xbd1) = 0x0;  // @h127_5cce70
  F32(esi, 0xb11) = 0x43fa0000;  // @h128_5cce70
  F32(esi, 0xc69) = 0x43960000;  // @h129_5cce70
  u32 so2 = G(u32, 0x70039c);
  u32 mgr = F32(so2, 0x9b);
  u32 wv = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(mgr, 0x114))(mgr, 0x6acfa4, 0, 0x6b4e78, 0xe4);  // @h130_5cce70
  F16(esi, 0xb59) = (u16)wv;  // @h131_5cce70
  F32(esi, 0xbea) = 0x4;  // @h132_5cce70
  F32(esi, 0xc07) = 0x4;  // @h133_5cce70
  F32(esi, 0xbc9) = 0;  // @h134_5cce70
  u32 nw = ext_41e290_cdecl1((u32)0x108);  // @h135_5cce70
  reg.state = 1;
  u32 edx = 0;
  if (nw != 0) edx = ext_4d8330_t3(nw, 0x6b4ec4, 0x6b4ea8, esi + 0xdf5);  // @h136_5cce70
  F32(esi, 0xa50) = edx;  // @h137_5cce70
  u32 so3 = G(u32, 0x70039c);
  reg.state = 0;
  ((u32(THISCALL *)(u32, u32))VSLOT(so3, 0x1a4))(so3, edx);  // @h138_5cce70
  SEH_LEAVE();
  return esi;
#undef F32
#undef F16
#undef F8
}
PCREG(5cce70, hand_5cce70);

extern "C" u32 THISCALL ext_4cc5a0_t0(u32) __asm__("ext_4cc5a0");
extern "C" u32 THISCALL ext_4db520_t0(u32) __asm__("ext_4db520");
extern "C" u32 THISCALL ext_4db550_t0(u32) __asm__("ext_4db550");
extern "C" u32 THISCALL hand_440f50(u32 ecx_in, u32 A1, u32 A2) {
  SEH_ENTER(0x665ddb);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
#define BEND(e) { e = (u8 *)buf; while (*(volatile u8 *)e) e++; }
#define CPYC(e, addr, n) { for (u32 i_ = 0; i_ < (n); i_++) e[i_] = *(volatile u8 *)((addr) + i_); }
  u32 ebx = ecx_in;
  volatile u8 buf[0x100];
  u32 ecx = F32(ebx, 0x54);
  while (ecx != 0) {  // @h1_440f50
    u32 p = F32(ecx, 0x54);
    u32 fl = 0x200002;
    if (p != 0) fl = F32(F32(p, 0xc), 0x23);
    if (fl & 0x100000) break;  // @h2_440f50
    ecx = ext_4db520_t0(ecx);  // @h3_440f50
  }
  if (F32(ebx, 0x30) & 0x800) LOG3H(0x119, 0x67cbbc, 0x67cc20, ext_4cc5a0_t0(A1));  // @h4_440f50
  if (F8(ebx, 0x30) & 2) LOG3H(0x11a, 0x67cbbc, 0x67cc34, ext_4cc5a0_t0(A1));  // @h5_440f50
  u8 *e;
  buf[0] = 0;  // @h6_440f50
  if (F32(ebx, 0x30) & 0x40000000) { BEND(e); CPYC(e, 0x67cc48, 8); }  // @h7_440f50
  else { BEND(e); CPYC(e, 0x67cc50, 10); }  // @h8_440f50
  u32 edx = F32(ebx, 8);
  if (F32(edx, 0x3c) & 0x40000) { BEND(e); CPYC(e, 0x67cc5c, 9); }  // @h9_440f50
  if (F32(edx, 0x3c) & 0x800) { BEND(e); CPYC(e, 0x67cc68, 8); }  // @h10_440f50
  if (F32(edx, 0x3c) & 0x400) { BEND(e); CPYC(e, 0x67cc70, 10); }  // @h11_440f50
  u32 fa = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x2a8))(ebx);  // @h12_440f50
  if (fa & 0x1000000) { BEND(e); CPYC(e, 0x67cc7c, 10); }  // @h13_440f50
  fa = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x2a8))(ebx);  // @h14_440f50
  if (fa & 0x2000000) { BEND(e); CPYC(e, 0x67cc88, 11); }  // @h15_440f50
  fa = ((u32(THISCALL *)(u32))VSLOT(ebx, 0x2a8))(ebx);  // @h16_440f50
  if (fa & 0x10000) { BEND(e); CPYC(e, 0x67cc94, 15); }  // @h17_440f50
  u32 c2 = F32(ebx, 8);
  if (F32(c2, 0x3c) & 0x4000) {  // @h18_440f50
    BEND(e); CPYC(e, 0x67cca4, 12);  // @h19_440f50
    u32 q = ext_4db550_t0(c2);  // @h20_440f50
    if (q != 0 && F8(q, 0x1c) != 0) {  // @h21_440f50
      BEND(e); CPYC(e, 0x67ccb0, 2);  // @h22_440f50
      u32 obj = F32(q, 0);  // @h23_440f50
      volatile u8 tmp[0x80];
      u32 r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1d8))(obj, (u32)(u8 *)tmp, 1);  // @h24_440f50
      reg.state = 0;
      u32 sp = ext_4cc1d0_t0(r);  // @h25_440f50
      u32 len = 0;
      while (*(volatile u8 *)(sp + len)) len++;
      len++;
      BEND(e);
      for (u32 i = 0; i < len; i++) e[i] = *(volatile u8 *)(sp + i);  // @h26_440f50
      reg.state = -1;
      ext_4cbec0_t0((u32)(u8 *)tmp);  // @h27_440f50
      BEND(e); CPYC(e, 0x67ccb4, 2);  // @h28_440f50
    } else {
      BEND(e); CPYC(e, 0x67ccb8, 10);  // @h29_440f50
    }
  }
  {
    u32 lg = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x67cbbc, 0x138);
    u32 edx2 = 0x67c8e8;
    u32 c4 = F32(ebx, 4);
    if (c4 != 0) edx2 = c4;  // @h30_440f50
    u32 s = ext_4cc5a0_t0(A1);
    ((u32(*)(u32, u32, u32, u32, u32, u32, u32))VSLOT(o, 0x2c))(o, 0x67ccc4, s, F32(F32(ebx, 0xc), 0), edx2, F32(ebx, 8) + 0x24, (u32)(u8 *)buf);  // @h31_440f50
  }
  LOG3H(0x139, 0x67cbbc, 0x67ccd8, ext_4cc5a0_t0(A1));  // @h32_440f50
  u32 node = F32(ebx, 0x50);
  while (node != 0) {  // @h33_440f50
    u32 sub = F32(node, 0x54);
    if (sub != 0) ((u32(THISCALL *)(u32, u32, u32))VSLOT(sub, 0x20c))(sub, A1 + 4, A2);  // @h34_440f50
    node = F32(node, 0x60);  // @h35_440f50
  }
  LOG3H(0x140, 0x67cbbc, 0x67cce0, ext_4cc5a0_t0(A1));  // @h36_440f50
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef F8
}
PCREG(440f50, hand_440f50);

extern "C" u32 THISCALL ext_4d5440_t0(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4d5580_t0(u32) __asm__("ext_4d5580");
extern "C" u32 THISCALL ext_4d7540_t0(u32) __asm__("ext_4d7540");
extern "C" u32 THISCALL ext_4d6aa0_t2(u32, u32, u32) __asm__("ext_4d6aa0");
extern "C" u32 THISCALL ext_4d6520_t3(u32, u32, u32, u32) __asm__("ext_4d6520");
extern "C" u32 THISCALL ext_4d62c0_t4(u32, u32, u32, u32, u32) __asm__("ext_4d62c0");
extern "C" u32 THISCALL ext_4d7c30_t4(u32, u32, u32, u32, u32) __asm__("ext_4d7c30");
extern "C" u32 THISCALL hand_4d5880(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x66954b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
  u32 esi = ecx_in;
  u32 kind = F32(esi, 9);
  if (kind != 1 && kind != 4) {  // @h1_4d5880
    u32 lg = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x696924, 0x533);
    ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x696af8);  // @h2_4d5880
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
  u8 bl = 0;
  u8 *bufA = (u8 *)__builtin_alloca(0x10004);
  u8 *bufB = (u8 *)__builtin_alloca(0x10004);
  volatile u8 ob[0x70];
  volatile u8 hdr[0x30];
  volatile u8 s2c[0x20];
  volatile u32 sig = 0xcccccccc;
  volatile u8 ft[8];
  u32 ob_ = (u32)(u8 *)ob, hd = (u32)(u8 *)hdr, sc = (u32)(u8 *)s2c, ftp = (u32)(u8 *)ft;
  u32 a0 = A1;
  ext_4d5440_t0(ob_);  // @h3_4d5880
  reg.state = 0;
  if (ext_4d6aa0_t2(ob_, a0, 3) & 0xff) {  // @h4_4d5880
    u32 h = F32(ob_, 0x11);
    u32 st = F32(esi, 0x15);
    ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x10))(st, h, F32(ob_, 0x2e), 0);  // @h5_4d5880
    st = F32(esi, 0x15);
    u32 eof = ((u32(THISCALL *)(u32, u32))VSLOT(st, 0x1c))(st, h);  // @h6_4d5880
    while (eof == 0 && bl == 0) {  // @h7_4d5880
      st = F32(esi, 0x15);
      ((u32(THISCALL *)(u32, u32))VSLOT(st, 0xc))(st, h);  // @h8_4d5880
      st = F32(esi, 0x15);
      ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x14))(st, (u32)&sig, 4, h);  // @h9_4d5880
      st = F32(esi, 0x15);
      ((u32(THISCALL *)(u32, u32))VSLOT(st, 0xc))(st, h);  // @h10_4d5880
      u32 sg = sig;
      if (sg == 0x2014b50) {  // @h11_4d5880
        st = F32(esi, 0x15);
        ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x14))(st, hd, 0x2a, h);  // @h12_4d5880
        u16 nl = F16(hd, 0x18);
        if (nl != 0) {  // @h13_4d5880
          st = F32(esi, 0x15);
          ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x14))(st, (u32)bufA, nl, h);  // @h14_4d5880
          st = F32(esi, 0x15);
          a0 = ((u32(THISCALL *)(u32, u32))VSLOT(st, 0xc))(st, h);  // @h15_4d5880
          bufA[nl] = 0;  // @h16_4d5880
          u32 nb = ext_41e290_cdecl1((u32)(F32(hd, 0x14) + 1));  // @h17_4d5880
          u32 edi = F32(hd, 0x14);
          if (ext_4d6520_t3(ob_, (u32)bufA, sc, 0) & 0xff) {  // @h18_4d5880
            if (edi == 0) edi = F32(sc, 0x12);  // @h19_4d5880
            ext_4d62c0_t4(ob_, sc, nb, 0, edi);  // @h20_4d5880
          }
          st = F32(esi, 0x15);
          ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x10))(st, h, a0, 0);  // @h21_4d5880
          ((u32 (STDCALL *)(u32, u32, u32))G(u32, 0x676138))(F32(hd, 0xa), F32(hd, 8), ftp);  // @h22_4d5880
          ext_4d7c30_t4(esi, (u32)bufA, ftp, nb, F32(hd, 0x14));  // @h23_4d5880
          ext_634273_cdecl2(nb, 1);  // @h24_4d5880
        }
        u16 xl = F16(hd, 0x1a);
        if (xl != 0) {  // @h25_4d5880
          st = F32(esi, 0x15);
          ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x14))(st, (u32)bufB, xl, h);  // @h26_4d5880
        }
        u16 cl = F16(hd, 0x1c);
        if (cl != 0) {  // @h27_4d5880
          st = F32(esi, 0x15);
          ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(st, 0x14))(st, (u32)bufB, cl, h);  // @h28_4d5880
        }
      } else if (sg == 0x6054b50 || sg == 0x52756e65) {  // @h29_4d5880
        bl = 1;
      } else {
        u32 lg = G(u32, 0x700390);
        u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x696924, 0x560);
        ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x6969dc);  // @h30_4d5880
        FPCALL();  // @h31_4d5880
      }
      st = F32(esi, 0x15);
      eof = ((u32(THISCALL *)(u32, u32))VSLOT(st, 0x1c))(st, h);  // @h32_4d5880
    }
    ext_4d7540_t0(ob_);  // @h33_4d5880
    bl = 1;
  } else {
    bl = 0;
  }
  ext_4d5580_t0(ob_);  // @h34_4d5880
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return bl;
#undef F32
#undef F16
}
PCREG(4d5880, hand_4d5880);

extern "C" u32 THISCALL ext_4ccba0_t0(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_t0(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cdb90_t0(u32) __asm__("ext_4cdb90");
extern "C" u32 THISCALL ext_4dbbc0_t0(u32) __asm__("ext_4dbbc0");
extern "C" u32 THISCALL ext_4dbbd0_t0(u32) __asm__("ext_4dbbd0");
extern "C" u32 THISCALL ext_496530_t0(u32) __asm__("ext_496530");
extern "C" u32 THISCALL ext_496620_t1(u32, u32) __asm__("ext_496620");
extern "C" u32 THISCALL ext_496690_t1(u32, u32) __asm__("ext_496690");
extern "C" u32 THISCALL ext_496700_t1(u32, u32) __asm__("ext_496700");
extern "C" u32 THISCALL ext_497470_t1(u32, u32) __asm__("ext_497470");
extern "C" u32 THISCALL ext_498270_t1(u32, u32) __asm__("ext_498270");
extern "C" u32 THISCALL ext_498430_t1(u32, u32) __asm__("ext_498430");
extern "C" u32 THISCALL ext_498650_t1(u32, u32) __asm__("ext_498650");
extern "C" u32 THISCALL ext_496160_t1(u32, u32) __asm__("ext_496160");
extern "C" u32 THISCALL ext_497fe0_t1(u32, u32) __asm__("ext_497fe0");
#define RT_BEGIN(o, it) ((u32(THISCALL *)(u32, u32))VSLOT((o), 0x4c))((o), (u32)(it))
#define RT_NEXT(o, it) ((u32(THISCALL *)(u32, u32))VSLOT((o), 0x5c))((o), (u32)(it))
extern "C" u32 THISCALL hand_497990(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x6681bb);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
#define SV(off) ((u32(THISCALL *)(u32, u32))VSLOT(S, (off)))
  u32 ebx = ecx_in, S = A1;
  volatile u32 vdc = 0xcccccccc, vd4 = 0xcccccccc, vd8 = 0xcccccccc, v104 = 0xcccccccc, v108 = 0xcccccccc;
  volatile u32 L[4];
  volatile u32 itc[2], itf4[2], it100[2], ite8[2], itcc[2];
  volatile u32 vd0 = 0xcccccccc, vc0 = 0xcccccccc;
  u32 Lp = (u32)(u32 *)L;
  SV(0xc)(S, 0xe);  // @h1_497990
  if (F32(ebx, 0x4c) != 0) {
    u32 i = 0;
    do {  // @h2_497990
      u32 p = F32(ebx, 0x44) + i * 8 + 4;
      SV(0x14)(S, p);  // @h3_497990
      i++;
    } while (i != F32(ebx, 0x4c));
  }
  SV(0xc)(S, 0xd);  // @h4_497990
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, (u32)&vdc, 4);  // @h5_497990
  ext_496620_t1(ebx, S);  // @h6_497990
  SV(0xc)(S, 9);  // @h7_497990
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, (u32)&vd4, 4);  // @h8_497990
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, (u32)&vd8, 4);  // @h9_497990
  if (vd4 != 0xd || vd8 != 0x2000) {  // @h10_497990
    u32 lg = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68e36c, 0x465);
    ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x68e3d8);  // @h11_497990
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
#define RD(off, dst, n) ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, (dst), (n))
  SV(0xc)(S, 7);  // @h12_497990
  RD(0x18, ebx + 0x20, 4);  // @h13_497990
  RD(0x18, ebx + 0x28, 4);  // @h14_497990
  RD(0x18, ebx + 0x24, 4);  // @h15_497990
  RD(0x18, ebx + 0x50, 1);  // @h16_497990
  RD(0x18, ebx + 0x61, 4);  // @h17_497990
  RD(0x18, (u32)&v104, 4);  // @h18_497990
  SV(0xc)(S, 8);  // @h19_497990
  RD(0x18, (u32)&v108, 4);  // @h20_497990
  ext_4ccba0_t0(Lp);  // @h21_497990
  reg.state = 0;
  ext_497470_t1(ebx, Lp);  // @h22_497990
  {
    u32 Lo = L[0];
    RT_BEGIN(Lp, itc);  // @h23_497990
    u32 r = RT_NEXT(Lp, itc);  // @h24_497990
    if (itc[0] != 0) {  // @h25_497990
      do {
        u32 xx = F32(r, 0x54);
        u32 fl = 0x200002;
        if (xx != 0) fl = F32(F32(xx, 0xc), 0x23);
        if (fl & 0x100000) ext_496700_t1(ebx, xx);  // @h26_497990
        r = RT_NEXT(Lp, itc);  // @h27_497990
      } while (itc[0] != 0);
    }
    (void)Lo;
  }
  ext_496690_t1(ebx, S);  // @h28_497990
  ext_496530_t0(ebx);  // @h29_497990
  u32 g = G(u32, 0x70038c);
  u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x48))(g, 0x4f004f);  // @h30_497990
  ext_498270_t1(ebx, S);  // @h31_497990
  g = G(u32, 0x70038c);
  ((u32(THISCALL *)(u32, u32))VSLOT(g, 0x48))(g, esi);  // @h32_497990
  u32 sy = G(u32, 0x70039c);
  ((u32(THISCALL *)(u32))VSLOT(sy, 0x10))(sy);  // @h33_497990
  ext_498430_t1(ebx, S);  // @h34_497990
  sy = G(u32, 0x70039c);
  ((u32(THISCALL *)(u32))VSLOT(sy, 0x14))(sy);  // @h35_497990
  sy = G(u32, 0x70039c);
  u32 m = F32(sy, 0x9b);
  u32 m8 = F32(m, 8);
  ((u32(THISCALL *)(u32))VSLOT(m8, 0x28))(m8);  // @h36_497990
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  ((u32(THISCALL *)(u32))VSLOT(m, 0x74))(m);  // @h37_497990
  ext_498650_t1(ebx, S);  // @h38_497990
  ext_496160_t1(ebx, S);  // @h39_497990
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  ((u32(THISCALL *)(u32))VSLOT(m, 0x78))(m);  // @h40_497990
  ext_497fe0_t1(ebx, S);  // @h41_497990
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  ((u32(THISCALL *)(u32))VSLOT(m, 0x74))(m);  // @h42_497990
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  F32(m, 0x10) = vdc;  // @h43_497990
  ext_4cdb90_t0(Lp);  // @h44_497990
  ext_497470_t1(ebx, Lp);  // @h45_497990
  u32 pass = 0;
  do {
    RT_BEGIN(Lp, itf4);  // @h46_497990
    esi = RT_NEXT(Lp, itf4);  // @h47_497990
    while (itf4[0] != 0) {  // @h48_497990
      u32 xx = F32(esi, 0x54);
      u32 fl = 0x200002;
      if (xx != 0) fl = F32(F32(xx, 0xc), 0x23);
      if (fl & 0x100000) {  // @h49_497990
        u32 ch = F32(xx, 8);
        vd0 = ch;
        if (ch != 0) {  // @h50_497990
          do {
            if (pass != 0) ext_4dbbd0_t0(ch); else ext_4dbbc0_t0(ch);  // @h51_497990
            xx = F32(esi, 0x54);
            ((u32(THISCALL *)(u32, u32))VSLOT(xx, 0x50))(xx, (u32)&vd0);  // @h52_497990
            ch = vd0;
          } while (ch != 0);
        }
      } else {
        if (pass != 0) ext_4dbbd0_t0(esi); else ext_4dbbc0_t0(esi);  // @h53_497990
      }
      esi = RT_NEXT(Lp, itf4);  // @h54_497990
    }
    RT_BEGIN(Lp, it100);  // @h55_497990
    u32 nd = RT_NEXT(Lp, it100);  // @h56_497990
    while (it100[0] != 0) {  // @h57_497990
      u32 xx = F32(nd, 0x54);
      u32 fl = 0x200002;
      if (xx != 0) fl = F32(F32(xx, 0xc), 0x23);
      if (fl & 0x100000) {  // @h58_497990
        u32 ch = F32(xx, 8);
        vc0 = ch;
        if (ch != 0) {
          do {
            u32 y = F32(ch, 0x54);
            u32 h1, rt;
            if (y != 0 && (h1 = F32(y, 0x10)) != 0 && (rt = F32(h1, 8)) != 0) {  // @h59_497990
              RT_BEGIN(rt, ite8);  // @h60_497990
              u32 yy = F32(vc0, 0x54);
              u32 rr = RT_NEXT(F32(F32(yy, 0x10), 8), ite8);  // @h61_497990
              while (ite8[0] != 0) {  // @h62_497990
                u32 gg = G(u32, 0x70038c);
                esi = ((u32(THISCALL *)(u32, u32))VSLOT(gg, 0xcc))(gg, rr);  // @h63_497990
                if (esi == 0) {  // @h64_497990
                  u32 yz = F32(vc0, 0x54);
                  u32 q = F32(F32(yz, 0x10), 8);
                  ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x44))(q, (u32)ite8);  // @h65_497990
                } else if (F8(esi, 4) & 0x80) {  // @h66_497990
                  if (pass != 0) {
                    ((u32(THISCALL *)(u32))VSLOT(esi, 0x34))(esi);  // @h67_497990
                    F32(esi, 4) &= 0xffffff7f;  // @h68_497990
                  } else {
                    ((u32(THISCALL *)(u32))VSLOT(esi, 0x30))(esi);  // @h69_497990
                  }
                }
                u32 yw = F32(vc0, 0x54);
                rr = RT_NEXT(F32(F32(yw, 0x10), 8), ite8);  // @h70_497990
              }
            }
            xx = F32(nd, 0x54);
            ((u32(THISCALL *)(u32, u32))VSLOT(xx, 0x50))(xx, (u32)&vc0);  // @h71_497990
            ch = vc0;
          } while (ch != 0);
        }
      } else if (xx != 0) {  // @h72_497990
        u32 h1, rt;
        if ((h1 = F32(xx, 0x10)) != 0 && (rt = F32(h1, 8)) != 0) {  // @h73_497990
          RT_BEGIN(rt, itcc);  // @h74_497990
          u32 nb = F32(nd, 0x54);
          u32 rr = RT_NEXT(F32(F32(nb, 0x10), 8), itcc);  // @h75_497990
          while (itcc[0] != 0) {  // @h76_497990
            u32 gg = G(u32, 0x70038c);
            esi = ((u32(THISCALL *)(u32, u32))VSLOT(gg, 0xcc))(gg, rr);  // @h77_497990
            if (esi == 0) {  // @h78_497990
              u32 nb2 = F32(nd, 0x54);
              u32 q = F32(F32(nb2, 0x10), 8);
              ((u32(THISCALL *)(u32, u32))VSLOT(q, 0x44))(q, (u32)itcc);  // @h79_497990
            } else if (F8(esi, 4) & 0x80) {  // @h80_497990
              if (pass != 0) {
                ((u32(THISCALL *)(u32))VSLOT(esi, 0x34))(esi);  // @h81_497990
                F32(esi, 4) &= 0xffffff7f;  // @h82_497990
              } else {
                ((u32(THISCALL *)(u32))VSLOT(esi, 0x30))(esi);  // @h83_497990
              }
            }
            u32 nb3 = F32(nd, 0x54);
            rr = RT_NEXT(F32(F32(nb3, 0x10), 8), itcc);  // @h84_497990
          }
        }
      }
      nd = RT_NEXT(Lp, it100);  // @h85_497990
    }
    sy = G(u32, 0x70039c);
    F8(F32(sy, 0x9b), 0xbc0) = 0;  // @h86_497990
    pass++;
  } while (pass <= 1);
  sy = G(u32, 0x70039c);
  F8(F32(sy, 0x9b), 0xbc0) = 1;  // @h87_497990
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  m8 = F32(m, 8);
  ((u32(THISCALL *)(u32))VSLOT(m8, 0x2c))(m8);  // @h88_497990
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  ((u32(THISCALL *)(u32))VSLOT(m, 0x78))(m);  // @h89_497990
  ext_4ccf60_t0(Lp);  // @h90_497990
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef F8
#undef SV
#undef RD
}
PCREG(497990, hand_497990);

extern "C" u32 THISCALL ext_6033c0_w1(u32, u32) __asm__("ext_6033c0");
extern "C" u32 THISCALL ext_5f5490_w2(u32, u32, u32) __asm__("ext_5f5490");
extern "C" u32 THISCALL ext_603850_w0(u32) __asm__("ext_603850");
extern "C" u32 THISCALL hand_603500(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x66dc73);
  u32 ebx = ecx_in;
  volatile u32 loc[2];
  *(volatile u32 *)(ebx + 4) = 1;  // @h1_603500
  *(volatile u32 *)(ebx + 8) = 0;  // @h2_603500
  reg.state = 0;
  *(volatile u32 *)ebx = 0x6b9a24;  // @h3_603500
  ext_6033c0_w1(ebx + 0xc, A1);  // @h4_603500
  reg.state = 1;
  loc[0] = 0;  // @h5_603500
  *(volatile u8 *)&loc[1] = 0;  // @h6_603500
  ext_5f5490_w2(ebx + 0xc, (u32)(u32 *)loc, A1);  // @h7_603500
  if (G(u32, 0x724698) == 0) ext_603850_w0(ebx);  // @h8_603500
  SEH_LEAVE();
  return ebx;
}
PCREG(603500, hand_603500);

extern "C" u32 THISCALL ext_6071c0_w0(u32) __asm__("ext_6071c0");
extern "C" u32 THISCALL ext_59a9b0_w1(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_606ee0_w3(u32, u32, u32, u32) __asm__("ext_606ee0");
extern "C" u32 THISCALL hand_606a70(u32 ecx_in) {
  SEH_ENTER(0x66df2b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 ebx = ecx_in;
  F32(ebx, 3) = 0;  // @h1_606a70
  F32(ebx, 7) = 0;  // @h2_606a70
  F32(ebx, 0xb) = 0;  // @h3_606a70
  reg.state = 0;
  F32(ebx, 0xf) = 0;  // @h4_606a70
  u32 esi = ext_6071c0_w0(0x64);  // @h5_606a70
  ext_59a9b0_w1(ebx + 3, esi);  // @h6_606a70
  volatile u32 loc = 0;
  ext_606ee0_w3(ebx + 3, F32(ebx, 7), esi, (u32)&loc);  // @h7_606a70
  F32(ebx, 0xf) = 0;  // @h8_606a70
  SEH_LEAVE();
  return ebx;
#undef F32
}
PCREG(606a70, hand_606a70);

extern "C" u32 THISCALL ext_5f9700_w2(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_603c80_w2(u32, u32, u32) __asm__("ext_603c80");
extern "C" u32 THISCALL hand_603430(u32 ecx_in, u32 A1, u32 A2) {
  SEH_ENTER(0x66dc43);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  ext_5f9700_w2(esi, A1, A2);  // @h1_603430
  F32(esi, 0) = 0x6b9a24;  // @h2_603430
  reg.state = 0;
  F32(esi, 0x10) = 0xa;  // @h3_603430
  F32(esi, 0x14) = 0;  // @h4_603430
  u32 p = ext_41e290_cdecl1((u32)0x50);  // @h5_603430
  if (p != 0) {
    u32 q = p;
    for (u32 i = 10; i != 0; i--) {  // @h6_603430
      F32(q, 0) = 0;  // @h7_603430
      *(volatile u8 *)(q + 4) = 0;  // @h8_603430
      q += 8;
    }
  }
  F32(esi, 0xc) = p;  // @h9_603430
  reg.state = 1;
  if (G(u32, 0x724698) == 0) ext_603850_w0(esi);  // @h10_603430
  ext_603c80_w2(esi, A1, A2);  // @h11_603430
  SEH_LEAVE();
  return esi;
#undef F32
}
PCREG(603430, hand_603430);

extern "C" u32 THISCALL ext_54f870_w2(u32, u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_5fae50_w0(u32) __asm__("ext_5fae50");
extern "C" u32 THISCALL ext_5fdb70_w0(u32) __asm__("ext_5fdb70");
extern "C" u32 THISCALL ext_5fb370_w1(u32, u32) __asm__("ext_5fb370");
extern "C" u32 THISCALL hand_5fb660(u32 ecx_in) {
  SEH_ENTER(0x66d496);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 edi = ecx_in;
  u32 ebx = edi + 1;
  u32 head = F32(edi, 1);
  u32 esi = F32(head, 5);
  if (esi != head) {  // @h1_5fb660
    do {
      u32 val = F32(esi, 0x19);
      if (val != 0) {  // @h2_5fb660
        u32 ecx = val + 0x172;
        u32 edx = F32(ecx, 0);
        u32 len = F32(ecx, 8) - edx;
        reg.state = 0;
        if (edx != 0 && len != 0) ext_54f870_w2(ecx, edx, len);  // @h3_5fb660
        reg.state = -1;
        ext_5fdb70_w0(val + 0x3c);  // @h4_5fb660
        ext_5fae50_w0(val);  // @h5_5fb660
        ext_634273_cdecl2(val, 0x17e);  // @h6_5fb660
      }
      u32 r = F32(esi, 9);
      if (r != 0) {  // @h7_5fb660
        esi = r;
        u32 l = F32(esi, 5);
        while (l != 0) { esi = l; l = F32(esi, 5); }  // @h8_5fb660
      } else {
        u32 p = F32(esi, 1);
        if (esi == F32(p, 9)) {  // @h9_5fb660
          do {
            esi = p;
            p = F32(p, 1);
          } while (esi == F32(p, 9));  // @h10_5fb660
        }
        if (F32(esi, 9) != p) esi = p;  // @h11_5fb660
      }
    } while (esi != F32(ebx, 0));  // @h12_5fb660
  }
  if (F32(ebx, 4) != 0) {  // @h13_5fb660
    u32 h = F32(ebx, 0);
    ext_5fb370_w1(ebx, F32(h, 1));  // @h14_5fb660
    h = F32(ebx, 0);
    F32(h, 5) = h;  // @h15_5fb660
    h = F32(ebx, 0);
    F32(h, 1) = 0;  // @h16_5fb660
    h = F32(ebx, 0);
    F32(h, 9) = h;  // @h17_5fb660
    F32(ebx, 4) = 0;  // @h18_5fb660
  }
  *(volatile u8 *)edi = 0;  // @h19_5fb660
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(5fb660, hand_5fb660);

extern "C" u32 THISCALL ext_4cca60_w2(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_462460_w2(u32, u32, u32) __asm__("ext_462460");
extern "C" u32 THISCALL hand_461250(u32 ecx_in, u32 A1, u32 A2, u32 A3, u32 A4, u32 A5) {
  SEH_ENTER(0x66689f);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in, ebx = A1;
  if (ebx == 0) {  // @h1_461250
    SEH_LEAVE();
    return 0;
  }
  if (F32(esi, 0x18) == 0) {  // @h2_461250
    u32 p = ext_41e290_cdecl1((u32)0x28);  // @h3_461250
    reg.state = 0;
    u32 r = 0;
    if (p != 0) r = ext_4cca60_w2(p, 8, 0x1e);  // @h4_461250
    reg.state = -1;
    F32(esi, 0x18) = r;  // @h5_461250
  }
  u32 cont = F32(esi, 0x18);
  u32 edi = ((u32(THISCALL *)(u32, u32))VSLOT(cont, 4))(cont, A2);  // @h6_461250
  ext_462460_w2(edi, esi, ebx);  // @h7_461250
  F32(edi, 0x30) = A3;  // @h8_461250
  F32(edi, 0x34) = A4;  // @h9_461250
  F32(edi, 0x70) = ebx;  // @h10_461250
  F32(edi, 0x28) = A5;  // @h11_461250
  F32(edi, 0x2c) = 0;  // @h12_461250
  u32 e = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x288))(esi, ebx);  // @h13_461250
  F32(edi, 0x10) = e;  // @h14_461250
  if (A2 & 1) {  // @h15_461250
    u8 ok = ((u8(THISCALL *)(u32, u32, u32))VSLOT(esi, 0x34c))(esi, edi, A2);  // @h16_461250
    if (ok == 0) {  // @h17_461250
      u32 c2 = F32(esi, 0x18);
      ((u32(THISCALL *)(u32, u32))VSLOT(c2, 0x20))(c2, edi - 4);  // @h18_461250
      SEH_LEAVE();
      return 0;
    }
  } else {
    F32(edi, 0x44) = 0xfffffffe;  // @h19_461250
  }
  u32 o = F32(esi, 0x5c);
  u32 ev = ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x20))(o, ebx);  // @h20_461250
  if (ev != 0)  // @h21_461250
    ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(esi, 0x228))(esi, ev, A2, A3, A4, 0x3f800000);  // @h22_461250
  SEH_LEAVE();
  return edi;
#undef F32
}
PCREG(461250, hand_461250);

extern "C" u32 THISCALL ext_4da2f0_w2(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4dc630_w2(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4d9f90_w0(u32) __asm__("ext_4d9f90");
extern "C" u32 THISCALL ext_4dae60_w0(u32) __asm__("ext_4dae60");
extern "C" u32 THISCALL ext_4d95f0_w2(u32, u32, u32) __asm__("ext_4d95f0");
extern "C" u32 THISCALL hand_4dc440(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x666666);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  volatile u8 S90[0x80];
  volatile u8 S110[0x80];
  u32 flags = F32(esi, 0x3c);
  if (!(flags & 0x40000)) {  // @h1_4dc440
    u32 lg = G(u32, 0x700390);
    u32 edi = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x696e24, 0x9e2);  // @h2_4dc440
    u32 s = ext_4da2f0_w2(esi, (u32)(u8 *)S90, 1);  // @h3_4dc440
    reg.state = 0;
    u32 str = ext_4cc1d0_t0(s);  // @h4_4dc440
    ((u32(*)(u32, u32, u32))VSLOT(edi, 0x2c))(edi, 0x696f88, str);  // @h5_4dc440
    ext_4cbec0_t0((u32)(u8 *)S90);  // @h6_4dc440
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
  if ((A1 & 0xff) != 0) {  // @h7_4dc440
    if (flags & 0x4000) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return 0; }  // @h8_4dc440
    ext_4dc630_w2(esi, 0x4000, 0);  // @h9_4dc440
  } else {
    if (!(flags & 0x4000)) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return 0; }  // @h10_4dc440
    ext_4dc630_w2(esi, 0, 0x4000);  // @h11_4dc440
  }
  flags = F32(esi, 0x3c);
  if (flags & 0x4000) {  // @h12_4dc440
    if (!(flags & 0x200c00)) ext_4d9f90_w0(esi);  // @h13_4dc440
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
  ext_4dae60_w0(esi);  // @h14_4dc440
  u32 node = F32(esi, 0x50);
  while (node != 0) {  // @h15_4dc440
    u32 a = F32(node, 0x54);
    if (a != 0) {
      u32 b = F32(a, 0xc);
      while (b != 0) {  // @h16_4dc440
        if (F32(b, 0x23) == 0x100021) {  // @h17_4dc440
          ext_4d95f0_w2(esi, F32(node, 0x54), 0);  // @h18_4dc440
          SEH_LEAVE();
          ext_633654(G(u32, 0x6f5630));
          return 0;
        }
        b = F32(b, 0xc);  // @h19_4dc440
      }
    }
    node = F32(node, 0x50);  // @h20_4dc440
  }
  u32 lg = G(u32, 0x700390);
  u32 edi = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x696e24, 0xa00);  // @h21_4dc440
  u32 s = ext_4da2f0_w2(esi, (u32)(u8 *)S110, 1);  // @h22_4dc440
  reg.state = 1;
  u32 str = ext_4cc1d0_t0(s);  // @h23_4dc440
  ((u32(*)(u32, u32, u32))VSLOT(edi, 0x2c))(edi, 0x696ef0, str);  // @h24_4dc440
  ext_4cbec0_t0((u32)(u8 *)S110);  // @h25_4dc440
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
}
PCREG(4dc440, hand_4dc440);

extern "C" u32 THISCALL ext_4da770_w1(u32, u32) __asm__("ext_4da770");
extern "C" u32 THISCALL ext_4dc840_w1(u32, u32) __asm__("ext_4dc840");
extern "C" u32 THISCALL ext_4d9ce0_w0(u32) __asm__("ext_4d9ce0");
extern "C" u32 THISCALL ext_4d9bf0_w0(u32) __asm__("ext_4d9bf0");
extern "C" u32 THISCALL ext_4daff0_w0(u32) __asm__("ext_4daff0");
extern "C" u32 THISCALL ext_4dc1a0_w0(u32) __asm__("ext_4dc1a0");
extern "C" u32 THISCALL ext_4d9d20_w1(u32, u32) __asm__("ext_4d9d20");
extern "C" u32 THISCALL ext_4dc440_w1(u32, u32) __asm__("ext_4dc440");
extern "C" u32 THISCALL hand_4dbe30(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x6686a6);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  volatile u8 S90[0x80];
  volatile u8 S110[0x80];
  u32 flags = F32(esi, 0x3c);
  u8 want = (u8)A1;
  u8 cur = (flags >> 0x12) & 1;
  if (want != cur) {  // @h1_4dbe30
    if (want != 0) {  // @h2_4dbe30
      if (flags & 0x40000000) {  // @h3_4dbe30
        u32 ebx = F32(esi, 0x50);
        if (ebx != 0) {  // @h4_4dbe30
          while (!(F32(ebx, 0x3c) & 0x40000)) {  // @h5_4dbe30
            ebx = F32(ebx, 0x50);  // @h6_4dbe30
            if (ebx == 0) break;
          }
        }
        u32 lg = G(u32, 0x700390);
        u32 edi = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x696e24, 0x386);  // @h7_4dbe30
        u32 s1 = ext_4da2f0_w2(ebx, (u32)(u8 *)S110, 1);  // @h8_4dbe30
        reg.state = 0;
        u32 s2 = ext_4da2f0_w2(esi, (u32)(u8 *)S90, 1);  // @h9_4dbe30
        reg.state = 1;
        u32 str1 = ext_4cc1d0_t0(s1);  // @h10_4dbe30
        u32 str2 = ext_4cc1d0_t0(s2);  // @h11_4dbe30
        ((u32(*)(u32, u32, u32, u32))VSLOT(edi, 0x2c))(edi, 0x696ed0, str2, str1);  // @h12_4dbe30
        ext_4cbec0_t0((u32)(u8 *)S90);  // @h13_4dbe30
        ext_4cbec0_t0((u32)(u8 *)S110);  // @h14_4dbe30
      } else {
        ext_4da770_w1(esi, 0);  // @h15_4dbe30
        ext_4dc630_w2(esi, 0x40000, 0);  // @h16_4dbe30
        ext_4dc840_w1(esi, esi);  // @h17_4dbe30
        u32 c = F32(esi, 0x50);
        if (c != 0) {  // @h18_4dbe30
          c = F32(c, 0x54);
          if (c != 0) ((u32(THISCALL *)(u32))VSLOT(c, 0x284))(c);  // @h19_4dbe30
        }
        if (!(F32(esi, 0x3c) & 0x200c00)) {  // @h20_4dbe30
          if (F32(esi, 0x64) == 0) ext_4d9ce0_w0(esi);  // @h21_4dbe30
          ext_4d9bf0_w0(esi);  // @h22_4dbe30
        }
      }
    } else {
      if (!(flags & 0x200c00) && F32(esi, 0x64) != 0 && (flags & 0xff) != 0) {  // @h23_4dbe30
        u32 a = F32(esi, 0x50);
        u32 c = 0;
        if (a != 0) c = F32(a, 0x54);  // @h24_4dbe30
        c = F32(c, 8);
        u32 e = ext_4daff0_w0(c);  // @h25_4dbe30
        if (e != 0) {  // @h26_4dbe30
          ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x320))(e, esi);  // @h27_4dbe30
          F32(esi, 0x64) = 0;  // @h28_4dbe30
        }
      }
      F32(esi, 0x64) = 0;  // @h29_4dbe30
      ext_4dae60_w0(esi);  // @h30_4dbe30
      ext_4dc440_w1(esi, 0);  // @h31_4dbe30
      ext_4dae60_w0(esi);  // @h32_4dbe30
      ext_4dc630_w2(esi, 0, 0x40000);  // @h33_4dbe30
      ext_4dc1a0_w0(esi);  // @h34_4dbe30
      if (!(F32(esi, 0x3c) & 0x200c00)) ext_4d9d20_w1(esi, 0);  // @h35_4dbe30
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
}
PCREG(4dbe30, hand_4dbe30);

extern "C" u32 THISCALL ext_4d5510_w0(u32) __asm__("ext_4d5510");
extern "C" u32 THISCALL ext_4d5640_w0(u32) __asm__("ext_4d5640");
extern "C" u32 THISCALL ext_4d7530_w1(u32, u32) __asm__("ext_4d7530");
extern "C" u32 THISCALL ext_4d7610_w2(u32, u32, u32) __asm__("ext_4d7610");
extern "C" u32 THISCALL hand_49a790(u32 ecx_in, u32 A1, u32 A2) {
  SEH_ENTER(0x6682b8);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  u32 g394 = G(u32, 0x700394);
  u32 sz = ((u32(THISCALL *)(u32, u32, u32))VSLOT(g394, 0xe0))(g394, A1, A2);  // @h1_49a790
  if (sz == 0xffffffff) {  // @h2_49a790
    SEH_LEAVE();
    return 0;
  }
  u32 ebx = ext_41e290_cdecl1(sz);  // @h3_49a790
  g394 = G(u32, 0x700394);
  u8 ok = ((u8(THISCALL *)(u32, u32, u32, u32))VSLOT(g394, 0xdc))(g394, ebx, A1, A2);  // @h4_49a790
  if (ok == 0) {  // @h5_49a790
    ext_634273_cdecl2(ebx, 1);  // @h6_49a790
    SEH_LEAVE();
    return 0;
  }
  volatile u8 O[0x30];
  u32 o = (u32)(u8 *)O;
  ext_4d5510_w0(o);  // @h7_49a790
  O[0] = 1;  // @h8_49a790
  u32 p = ebx + 0xc;
  F32(o, 1) = p;  // @h9_49a790
  F32(o, 9) = F32(p, 0);  // @h10_49a790
  F32(o, 5) = F32(p, 4);  // @h11_49a790
  u32 flag = (*(volatile u8 *)(p + 8) != 0) ? 1 : 0;  // @h12_49a790
  reg.state = 0;
  F32(o, 0x11) = flag;  // @h13_49a790
  F32(o, 5) = F32(ebx, 0);  // @h14_49a790
  u32 edi = F32(ebx, 4);
  F32(o, 9) = edi;  // @h15_49a790
  {
    u32 lg = G(u32, 0x700390);
    u32 oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68ea50, 0x45c);  // @h16_49a790
    ((u32(*)(u32, u32, u32))VSLOT(oo, 0x2c))(oo, 0x68ec44, edi);  // @h17_49a790
    lg = G(u32, 0x700390);
    oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68ea50, 0x45d);  // @h18_49a790
    ((u32(*)(u32, u32, u32))VSLOT(oo, 0x2c))(oo, 0x68ec68, F32(ebx, 0));  // @h19_49a790
    lg = G(u32, 0x700390);
    oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68ea50, 0x45e);  // @h20_49a790
    ((u32(*)(u32, u32, u32))VSLOT(oo, 0x2c))(oo, 0x68ec94, F32(esi, 0x20));  // @h21_49a790
  }
  ext_4d7530_w1(o, F32(ebx, 8));  // @h22_49a790
  u32 eax = F32(esi, 0x1c);
  F32(esi, 4) = eax;  // @h23_49a790
  ext_4d7610_w2(o, eax, edi);  // @h24_49a790
  ext_634273_cdecl2(ebx, 1);  // @h25_49a790
  u32 base = F32(esi, 4);
  u32 cnt = F32(base, 0);
  F32(esi, 8) = cnt;  // @h26_49a790
  unsigned long long prod = (unsigned long long)cnt * 0x10;
  u32 bytes = (prod >> 32) ? 0xffffffffu : (u32)prod;
  u32 d = ext_41e290_cdecl1(bytes);  // @h27_49a790
  F32(esi, 0x10) = d;  // @h28_49a790
  if (F32(esi, 8) != 0) {  // @h29_49a790
    u32 i = 0;
    do {
      u32 src = base + 4 + 0xc * i;
      u32 dst = F32(esi, 0x10) + 0x10 * i;
      F32(dst, 0) = F32(src, 0);  // @h30_49a790
      F32(dst, 8) = F32(src, 4);  // @h31_49a790
      F32(dst, 4) = F32(src, 8) + F32(esi, 4);  // @h32_49a790
      F32(dst, 0xc) = 0;  // @h33_49a790
      i++;
    } while (i != F32(esi, 8));
  }
  {
    u32 lg = G(u32, 0x700390);
    u32 oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68ea50, 0x474);  // @h34_49a790
    ((u32(*)(u32, u32))VSLOT(oo, 0x2c))(oo, 0x68ecbc);  // @h35_49a790
  }
  ext_4d5640_w0(o);  // @h36_49a790
  SEH_LEAVE();
  return 1;
#undef F32
}
PCREG(49a790, hand_49a790);

extern "C" u32 THISCALL ext_43de40_w3(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_52cea0_w1(u32, u32) __asm__("ext_52cea0");
extern "C" u32 THISCALL ext_52cec0_w2(u32, u32, u32) __asm__("ext_52cec0");
extern "C" u32 THISCALL ext_52a300_w1(u32, u32) __asm__("ext_52a300");
extern "C" u32 THISCALL hand_52a370(u32 ecx_in, u32 A1, u32 A2, u32 A3) {
  SEH_ENTER(0x66a5c8);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u32 ebx = ecx_in;
  ext_43de40_w3(ebx, A1, A2, A3);  // @h40_52a370
  reg.state = 0;
  F32(ebx, 0x0) = 0x6a0c7c;  // @h1_52a370
  F32(ebx, 0x36) = 0x0;  // @h2_52a370
  F32(ebx, 0x3a) = 0x0;  // @h3_52a370
  F16(ebx, 0x47) = 0x0;  // @h4_52a370
  F32(ebx, 0x65) = 0x0;  // @h5_52a370
  F32(ebx, 0x18) = 0x0;  // @h6_52a370
  u32 p = ext_41e290_cdecl1((u32)0x11);  // @h41_52a370
  reg.state = 1;
  u32 r = 0;
  if (p != 0) r = ext_52cec0_w2(p, 0x2dc6c0, 0x3c);  // @h42_52a370
  reg.state = 0;
  F32(ebx, 0x18) = r;  // @h43_52a370
  u32 edi = ext_41e290_cdecl1((u32)0x231);  // @h44_52a370
  reg.state = 2;
  if (edi != 0) {  // @h45_52a370
    u32 esi = F32(ebx, 0x18);
    ext_52cea0_w1(edi, esi);  // @h46_52a370
    ext_52a300_w1(edi + 0x51, esi);  // @h47_52a370
    F8(edi, 0x230) = 0;  // @h48_52a370
    for (u32 i = 0; i < 16; i++) *(volatile u8 *)(edi + i) = *(volatile u8 *)(0x6a0f2c + i);  // @h49_52a370
    for (u32 i = 0; i < 8; i++) *(volatile u8 *)(edi + 0x10 + i) = *(volatile u8 *)(0x6a0f3c + i);  // @h50_52a370
    F8(edi, 0x18) = *(volatile u8 *)0x6a0f44;  // @h51_52a370
  } else {
    edi = 0;
  }
  F32(ebx, 0x1c) = edi;  // @h52_52a370
  F32(ebx, 0x20) = 0x0;  // @h7_52a370
  F8(ebx, 0x46) = 0x0;  // @h8_52a370
  G(u8, 0x6e8fbc) = 0x1;  // @h9_52a370
  F32(ebx, 0x25) = 0x3;  // @h10_52a370
  F8(ebx, 0x24) = 0x0;  // @h11_52a370
  F32(ebx, 0x2d) = 0x0;  // @h12_52a370
  F32(ebx, 0x32) = 0x0;  // @h13_52a370
  F32(ebx, 0x7d) = 0x0;  // @h14_52a370
  F8(ebx, 0x31) = 0x1;  // @h15_52a370
  F32(ebx, 0x69) = 0x4e20;  // @h16_52a370
  F32(ebx, 0x81) = 0x0;  // @h17_52a370
  F32(ebx, 0x59) = 0x8;  // @h18_52a370
  F32(ebx, 0x5d) = 0x8;  // @h19_52a370
  F32(ebx, 0x61) = 0x8;  // @h20_52a370
  F32(ebx, 0x4d) = 0x0;  // @h21_52a370
  F32(ebx, 0x51) = 0x0;  // @h22_52a370
  F32(ebx, 0x55) = 0x0;  // @h23_52a370
  reg.state = 0;
  u32 sy = G(u32, 0x70039c);
  u32 m = F32(sy, 0x9b);
  u32 w = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m, 0x114))(m, 0x6a11f8, 0, 0x6a0f54, 0x254a);  // @h53_52a370
  F16(ebx, 0x93) = (u16)w;  // @h54_52a370
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  w = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m, 0x114))(m, 0x68a88c, 0, 0x6a0f54, 0x254b);  // @h55_52a370
  F16(ebx, 0x95) = (u16)w;  // @h56_52a370
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  w = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m, 0x114))(m, 0x6a1204, 0, 0x6a0f54, 0x254c);  // @h57_52a370
  F16(ebx, 0x97) = (u16)w;  // @h58_52a370
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  u32 obj = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h59_52a370
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x4c))(m, ebx);  // @h60_52a370
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x4c))(obj, 0x68a9e0, q);  // @h61_52a370
  F32(ebx, 0x49) = 0;  // @h62_52a370
  u32 s = ext_41e290_cdecl1((u32)0x14);  // @h63_52a370
  reg.state = 3;
  if (s != 0) {  // @h64_52a370
    F32(s, 4) = 0x32;  // @h65_52a370
    u32 buf = ext_41e290_cdecl1((u32)2500);  // @h66_52a370
    F32(s, 0) = buf;  // @h67_52a370
    F32(s, 8) = 0;  // @h68_52a370
    F32(s, 0xc) = 0;  // @h69_52a370
  } else {
    s = 0;
  }
  F32(ebx, 0x79) = s;  // @h70_52a370
  F32(ebx, 0x75) = 1;  // @h71_52a370
  SEH_LEAVE();
  return ebx;
#undef F32
#undef F16
#undef F8
}
PCREG(52a370, hand_52a370);

extern "C" u32 THISCALL ext_5ec720_w1(u32, u32) __asm__("ext_5ec720");
extern "C" u32 THISCALL hand_5aba60(u32 ecx_in, u32 A1, u32 A2, u32 A3, u32 A4) {
  SEH_ENTER(0x66c1e2);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u32 ebx = ecx_in;
  u32 e72 = F32(ebx, 0x72);
  u32 e6e = F32(ebx, 0x6e);
  s32 d = (s32)(e72 - e6e) >> 4;  // @h1_5aba60
  F32(ebx, 0x72) = F32(ebx, 0x72) + ((u32)(-d) << 4);  // @h2_5aba60
  u32 sy = G(u32, 0x70039c);
  u32 m = F32(sy, 0x9b);
  u32 dev = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, A1);  // @h3_5aba60
  F32(ebx, 4) = A2;  // @h4_5aba60
  F8(ebx, 0x19) = (u8)A4;  // @h5_5aba60
  u32 g = G(u32, 0x7142fc) + F32(ebx, 0x7f);
  G(u32, 0x7142fc) = g;  // @h6_5aba60
  if (F8(ebx, 0x19) != 0) {  // @h7_5aba60
    g += F32(ebx, 0x7f);
    G(u32, 0x7142fc) = g;  // @h8_5aba60
  }
  u32 i = 0;
  if (F32(ebx, 0x7f) != 0) {  // @h9_5aba60
    u32 edi = ebx + 0x42;
    do {
      if (F32(edi, -0x28) == 0) {  // @h10_5aba60
        u32 vt = F32(dev, 0);
        u32 r = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))F32(vt, 0x20))(dev, 0x5a434f42, 0, 0, 0, 0, 0);  // @h11_5aba60
        u32 o = ((u32(THISCALL *)(u32, u32))F32(vt, 0x1c4))(dev, r);  // @h12_5aba60
        F32(edi, -0x28) = o;  // @h13_5aba60
      }
      u32 o = F32(edi, -0x28);
      ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o, 0x26c))(o, 0, 0, 0);  // @h14_5aba60
      o = F32(edi, -0x28);
      u32 ovt = F32(o, 0);
      sy = G(u32, 0x70039c);
      m = F32(sy, 0x9b);
      u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, F32(ebx, 4));  // @h15_5aba60
      o = F32(edi, -0x28);
      ((u32(THISCALL *)(u32, u32))F32(ovt, 0x27c))(o, q);  // @h16_5aba60
      o = F32(edi, -0x28);
      ((u32(THISCALL *)(u32, u32))VSLOT(o, 0x248))(o, 0xffffffff);  // @h17_5aba60
      o = F32(edi, -0x28);
      F32(o, 0xa3) = 0x10;  // @h18_5aba60
      if (F8(ebx, 0x19) != 0) {  // @h19_5aba60
        if (F32(edi, 0) == 0) {  // @h20_5aba60
          u32 vt = F32(dev, 0);
          u32 r = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))F32(vt, 0x20))(dev, 0x5a434f42, 0, 0, 0, 0, 0);  // @h21_5aba60
          u32 oo = ((u32(THISCALL *)(u32, u32))F32(vt, 0x1c4))(dev, r);  // @h22_5aba60
          F32(edi, 0) = oo;  // @h23_5aba60
        }
        u32 o2 = F32(edi, 0);
        ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(o2, 0x26c))(o2, 0, 0, 0);  // @h24_5aba60
        o2 = F32(edi, 0);
        u32 ovt2 = F32(o2, 0);
        sy = G(u32, 0x70039c);
        m = F32(sy, 0x9b);
        u32 q2 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, F32(ebx, 4));  // @h25_5aba60
        o2 = F32(edi, 0);
        ((u32(THISCALL *)(u32, u32))F32(ovt2, 0x27c))(o2, q2);  // @h26_5aba60
        o2 = F32(edi, 0);
        ((u32(THISCALL *)(u32, u32))VSLOT(o2, 0x248))(o2, 0xff000000);  // @h27_5aba60
        o2 = F32(edi, 0);
        F32(o2, 0xa3) = 0x10;  // @h28_5aba60
      }
      edi += 4;
      i++;
    } while (i < F32(ebx, 0x7f));  // @h29_5aba60
  }
  if (A3 != 0) {  // @h30_5aba60
    u32 p = ext_41e290_cdecl1((u32)0xd7);  // @h31_5aba60
    reg.state = 0;
    u32 ecx = 0;
    if (p != 0) ecx = ext_5ec720_w1(p, F32(ebx, 0x7f));  // @h32_5aba60
    F32(ebx, 0x6a) = ecx;  // @h33_5aba60
    reg.state = -1;
    ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(ecx, 0x14))(ecx, A3, 0, 0, 0, 0);  // @h34_5aba60
    u32 n = F32(ebx, 0x6a);
    F8(n, 0x35) = 0;  // @h35_5aba60
    F8(ebx, 0x7e) = 1;  // @h36_5aba60
  }
  SEH_LEAVE();
  return 0;
#undef F32
#undef F8
}
PCREG(5aba60, hand_5aba60);

extern "C" u32 THISCALL ext_57edf0_w3(u32, u32, u32, u32) __asm__("ext_57edf0");
static inline u32 w3c_differ(u32 a, u32 b) {
  for (u32 i = 0;; i++) {
    u8 c = *(volatile u8 *)(a + i);
    if (c != *(volatile u8 *)(b + i)) return 1;
    if (c == 0) return 0;
  }
}
extern "C" u32 THISCALL hand_57ee90(u32 ecx_in) {
  SEH_ENTER(0x66b3fb);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 A = ecx_in;
  s32 v = 0x154;
  u8 bl = 0;
  volatile u8 S[0x90];
  volatile u8 Lb[0x14];
  u32 esi = A + 0xac;
  for (u32 i = 0; i < 4; i++, esi += 4) {  // @h1_57ee90
    u32 val = F32(esi, 0);
    if (val != 0xffffffff) {  // @h2_57ee90
      u32 g = G(u32, 0x70039c);
      u32 ob = F32(g, 0x1907);
      u32 r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ob, 0xbc))(ob, (u32)(u8 *)S, val);  // @h3_57ee90
      reg.state = 0;
      u32 str = ext_4cc1d0_t0(r);  // @h4_57ee90
      reg.state = -1;
      ext_4cbec0_t0((u32)(u8 *)S);  // @h5_57ee90
      for (u32 k = 0; k < 16; k++) Lb[k] = *(volatile u8 *)(0x6aad18 + k);  // @h6_57ee90
      Lb[0x10] = *(volatile u8 *)0x6aad28;  // @h7_57ee90
      Lb[0x11] = *(volatile u8 *)0x6aad29;  // @h8_57ee90
      Lb[0x12] = *(volatile u8 *)0x6aad2a;  // @h9_57ee90
      u32 arg;
      if (w3c_differ(0x6aad2c, str) == 0) {  // @h10_57ee90
        u32 e = F32(esi, 0);
        if (e == 0x82) {  // @h11_57ee90
          Lb[0] = 0x2f;  // @h12_57ee90
        } else {
          u8 al = Lb[0];
          if (e == 0x36) al = 0x2a;  // @h13_57ee90
          Lb[0] = al;  // @h14_57ee90
        }
        arg = (u32)(u8 *)Lb;
      } else {
        arg = (w3c_differ(0x6aad40, str) == 0) ? 0x6aad4c : str;  // @h15_57ee90
      }
      ext_57edf0_w3(A, arg, i, (u32)v);  // @h16_57ee90
      u32 obj = F32(esi, -0xa0);
      u32 o8 = F32(obj, 8);
      bl = 1;
      float f = *(volatile float *)(o8 + 0x40);
      f = f + f;  // @h17_57ee90
      f = f + *(volatile float *)0x680a70;  // @h18_57ee90
      f = f + (float)v;  // @h19_57ee90
      v = (s32)f;  // @h20_57ee90
    } else {
      u32 o1 = F32(esi, -0xa0);
      ((u32(THISCALL *)(u32))VSLOT(o1, 0x28c))(o1);  // @h21_57ee90
      u32 o2 = F32(esi, -0x90);
      ((u32(THISCALL *)(u32))VSLOT(o2, 0x28c))(o2);  // @h22_57ee90
    }
  }
  if (bl == 0) {  // @h23_57ee90
    u32 g = G(u32, 0x70039c);
    u32 m = F32(g, 0x9b);
    u32 ec = F32(m, 0xae4);
    u32 esi2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ec, 0))(ec, 0x6a67e8, 0x6aad54);  // @h24_57ee90
    u32 c1 = F32(A, 0xc);
    ((u32(THISCALL *)(u32, u32))VSLOT(c1, 0x284))(c1, esi2);  // @h25_57ee90
    float f = (float)(double)(u32)v;  // @h26_57ee90
    union { float fl; u32 u; } fu;
    fu.fl = f;
    u32 fb = fu.u;
    c1 = F32(A, 0xc);
    ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(c1, 0x26c))(c1, fb, 0, 0);  // @h27_57ee90
    u32 c2 = F32(A, 0x1c);
    ((u32(THISCALL *)(u32, u32))VSLOT(c2, 0x284))(c2, esi2);  // @h28_57ee90
    c2 = F32(A, 0x1c);
    ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(c2, 0x26c))(c2, fb, 0, 0);  // @h29_57ee90
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
}
PCREG(57ee90, hand_57ee90);

extern "C" u32 THISCALL ext_600240_w1(u32, u32) __asm__("ext_600240");
extern "C" u32 THISCALL ext_5f9130_w2(u32, u32, u32) __asm__("ext_5f9130");
extern "C" u32 THISCALL ext_5f5620_w1(u32, u32) __asm__("ext_5f5620");
extern "C" u32 THISCALL hand_5f37f0(u32 ecx_in, u32 A1, u32 A2) {
  SEH_ENTER(0x66d137);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
  u32 edi = ecx_in, ebx = A1;
  F16(edi, 8) = 0xa;  // @h1_5f37f0
  F32(edi, 0) = 0x6b8a2c;  // @h2_5f37f0
  F32(edi, 0xa) = 0;  // @h3_5f37f0
  F32(edi, 0x12) = 0xffffffff;  // @h4_5f37f0
  F32(edi, 0x16) = 0;  // @h5_5f37f0
  F32(edi, 0x1a) = 0x6b8b40;  // @h6_5f37f0
  F32(edi, 0x20) = ebx;  // @h7_5f37f0
  F32(edi, 0x2c) = 0x14;  // @h8_5f37f0
  F32(edi, 0x30) = 0;  // @h9_5f37f0
  u32 p = ext_41e290_cdecl1((u32)0xa0);  // @h10_5f37f0
  u32 q = p;
  if (p != 0) {
    for (u32 i = 0x14; i != 0; i--) {  // @h11_5f37f0
      F32(q, 0) = 0;  // @h12_5f37f0
      *(volatile u8 *)(q + 4) = 0;  // @h13_5f37f0
      q += 8;
    }
  }
  F32(edi, 0x28) = p;  // @h14_5f37f0
  reg.state = 0;
  F32(edi, 0x38) = 0x28;  // @h15_5f37f0
  F32(edi, 0x3c) = 0;  // @h16_5f37f0
  p = ext_41e290_cdecl1((u32)0x140);  // @h17_5f37f0
  q = p;
  if (p != 0) {
    for (u32 i = 0x28; i != 0; i--) {  // @h18_5f37f0
      F32(q, 0) = 0;  // @h19_5f37f0
      *(volatile u8 *)(q + 4) = 0;  // @h20_5f37f0
      q += 8;
    }
  }
  F32(edi, 0x34) = p;  // @h21_5f37f0
  reg.state = 1;
  F32(edi, 0x44) = 0x28;  // @h22_5f37f0
  F32(edi, 0x48) = 0;  // @h23_5f37f0
  p = ext_41e290_cdecl1((u32)0x140);  // @h24_5f37f0
  q = p;
  if (p != 0) {
    for (u32 i = 0x28; i != 0; i--) {  // @h25_5f37f0
      F32(q, 0) = 0;  // @h26_5f37f0
      *(volatile u8 *)(q + 4) = 0;  // @h27_5f37f0
      q += 8;
    }
  }
  F32(edi, 0x40) = p;  // @h28_5f37f0
  reg.state = 2;
  F32(edi, 0x50) = 0xa;  // @h29_5f37f0
  F32(edi, 0x54) = 0;  // @h30_5f37f0
  p = ext_41e290_cdecl1((u32)0x28);  // @h31_5f37f0
  F32(edi, 0x4c) = p;  // @h32_5f37f0
  reg.state = 3;
  F32(edi, 0x5c) = 2;  // @h33_5f37f0
  F32(edi, 0x60) = 0;  // @h34_5f37f0
  p = ext_41e290_cdecl1((u32)8);  // @h35_5f37f0
  F32(edi, 0x58) = p;  // @h36_5f37f0
  F32(edi, 0x82) = 0x6b89f8;  // @h37_5f37f0
  F32(edi, 0x64) = 0xffffffff;  // @h38_5f37f0
  F16(edi, 0x86) = 0;  // @h39_5f37f0
  F32(edi, 0x88) = 0;  // @h40_5f37f0
  F32(edi, 0x90) = 0;  // @h41_5f37f0
  F16(edi, 0x94) = 0xffff;  // @h42_5f37f0
  F32(edi, 0x68) = 0xffffffff;  // @h43_5f37f0
  F32(edi, 0x6c) = 0xffffffff;  // @h44_5f37f0
  F32(edi, 0x8c) = 0xffffffff;  // @h45_5f37f0
  F32(edi, 0x96) = F32(ebx, 0x96);  // @h46_5f37f0
  u32 sub = edi + 0x9a;
  F32(sub, 0) = 0x6b89f0;  // @h47_5f37f0
  F32(sub, 4) = 0;  // @h48_5f37f0
  F32(sub, 8) = 0;  // @h49_5f37f0
  F32(edi, 0xaa) = 0;  // @h50_5f37f0
  F32(edi, 0xa6) = 0;  // @h51_5f37f0
  F32(edi, 0xae) = 0;  // @h52_5f37f0
  F32(edi, 0xb2) = 0;  // @h53_5f37f0
  F32(edi, 0xba) = 0;  // @h54_5f37f0
  F32(edi, 0xaca) = 0x6b8a10;  // @h55_5f37f0
  reg.state = 4;
  F32(edi, 0xace) = edi;  // @h56_5f37f0
  ext_600240_w1(sub, ebx + 0x9a);  // @h57_5f37f0
  for (u32 k = 0; k < 0x30; k++) *(volatile u8 *)(edi + 0x64 + k) = *(volatile u8 *)(ebx + 0x64 + k);  // @h58_5f37f0
  F16(edi, 0x94) = F16(ebx, 0x94);  // @h59_5f37f0
  F32(edi, 0x12) = F32(ebx, 0x12);  // @h60_5f37f0
  ext_5f9130_w2(edi, A2, 1);  // @h61_5f37f0
  u32 r = ext_5f5620_w1(edi, A2);  // @h62_5f37f0
  F32(edi, 0xa6) = r;  // @h63_5f37f0
  F32(edi, 0x24) = F32(ebx, 0x24);  // @h64_5f37f0
  F32(edi, 4) = F32(ebx, 4);  // @h65_5f37f0
  F32(edi, 0xac2) = 0;  // @h66_5f37f0
  F32(edi, 0xac6) = 0;  // @h67_5f37f0
  SEH_LEAVE();
  return edi;
#undef F32
#undef F16
}
PCREG(5f37f0, hand_5f37f0);

extern "C" u32 THISCALL ext_5f9720_w0(u32) __asm__("ext_5f9720");
extern "C" u32 THISCALL ext_6014a0_w1(u32, u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_5f2c60_w2(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_605ba0_w1(u32, u32) __asm__("ext_605ba0");
extern "C" u32 THISCALL ext_5fe3b0_w2(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 ext_634d22_c3(u32, u32, u32) __asm__("ext_634d22");
static inline u32 w3c_strlen(u32 p) { u32 n = 0; while (*(volatile u8 *)(p + n)) n++; return n; }
extern "C" u32 THISCALL hand_5f9940(u32 ecx_in, u32 A1, u32 A2, u32 A3) {
  SEH_ENTER(0x66d1e5);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 ebx = ecx_in;
  volatile u32 loc10 = 0xcccccccc;
  u32 cnt = (F32(ebx, 4) - F32(ebx, 0)) >> 2;
  if (cnt != 0) {  // @h1_5f9940
    u32 i = 0;
    do {
      u32 ent = F32(F32(ebx, 0), i * 4);
      s32 len = (s32)w3c_strlen(A1);
      u32 sp = F32(ent, 4);
      s32 elen = (s32)(F32(ent, 8) - sp);
      s32 n = (len >= elen) ? elen : len;  // @h2_5f9940
      u32 cmp = ((u32(*)(u32, u32, u32))G(u32, 0x676408))(sp, A1, (u32)n);  // @h3_5f9940
      if (cmp == 0 && elen >= len && !(elen > len)) {  // @h4_5f9940
        u32 lg = G(u32, 0x700390);
        u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x6b90a0, 0x1a);  // @h5_5f9940
        ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x69c6b0, 0x6b90f8);  // @h6_5f9940
        FPCALL();  // @h7_5f9940
      }
      i++;
    } while (i < ((F32(ebx, 4) - F32(ebx, 0)) >> 2));  // @h8_5f9940
  }
  u32 edi = ext_41e290_cdecl1((u32)0x48);  // @h9_5f9940
  reg.state = 0;
  if (edi != 0) {  // @h10_5f9940
    u32 esi = edi + 4;
    F32(edi, 0) = 0;  // @h11_5f9940
    F32(esi, 0) = 0;  // @h12_5f9940
    F32(esi, 4) = 0;  // @h13_5f9940
    F32(esi, 8) = 0;  // @h14_5f9940
    u32 p = ext_6014a0_w1(esi, 8);  // @h15_5f9940
    F32(esi, 0) = p;  // @h16_5f9940
    F32(esi, 4) = p;  // @h17_5f9940
    F32(esi, 8) = p + 8;  // @h18_5f9940
    if (p != 0) *(volatile u8 *)p = 0;
    *(volatile u8 *)p = 0;  // @h19_5f9940
    reg.state = 1;
    ext_5f9720_w0(edi + 0x10);  // @h20_5f9940
    reg.state = 2;
    ext_5f9720_w0(edi + 0x2c);  // @h21_5f9940
  } else {
    edi = 0;
  }
  reg.state = -1;
  loc10 = edi;  // @h22_5f9940
  u32 len = w3c_strlen(A1);
  u32 endp = A1 + len;
  u32 cap = F32(edi, 8) - F32(edi, 4);
  if (len > cap) {  // @h23_5f9940
    ext_634d22_c3(F32(edi, 4), A1, cap);  // @h24_5f9940
    u32 q = (F32(edi, 8) - F32(edi, 4)) + A1;
    ext_5f2c60_w2(edi + 4, q, endp);  // @h25_5f9940
  } else {
    ext_634d22_c3(F32(edi, 4), A1, len);  // @h26_5f9940
    u32 dstp = F32(edi, 4) + len;
    u32 edx = F32(edi, 8);
    if (dstp != edx) {  // @h27_5f9940
      ((u32(*)(u32, u32, u32))G(u32, 0x676278))(dstp, edx, 1);  // @h28_5f9940
      F32(edi, 8) = F32(edi, 8) + (dstp - edx);  // @h29_5f9940
    }
  }
  ext_605ba0_w1(edi + 0x10, A2);  // @h30_5f9940
  ext_605ba0_w1(edi + 0x2c, A3);  // @h31_5f9940
  u32 e = F32(ebx, 4);
  if (e != F32(ebx, 8)) {  // @h32_5f9940
    if (e != 0) F32(e, 0) = edi;  // @h33_5f9940
    F32(ebx, 4) = F32(ebx, 4) + 4;  // @h34_5f9940
  } else {
    ext_5fe3b0_w2(ebx, e, (u32)&loc10);  // @h35_5f9940
  }
  F32(edi, 0) = ((F32(ebx, 4) - F32(ebx, 0)) >> 2) - 1;  // @h36_5f9940
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(5f9940, hand_5f9940);

extern "C" u32 THISCALL ext_44a1f0_w0(u32) __asm__("ext_44a1f0");
extern "C" u32 THISCALL ext_4dc110_w0(u32) __asm__("ext_4dc110");
extern "C" u32 FASTCALL ext_4cc850_g(u32, u32) __asm__("ext_4cc850");
extern "C" u32 THISCALL ext_4db860_w1(u32, u32) __asm__("ext_4db860");
extern "C" u32 THISCALL hand_512590(u32 ecx_in) {
  SEH_ENTER(0x664d1b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  u32 ebx = ecx_in;
  volatile u8 S[0x90];
  ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(ebx, 0x124))(ebx, 1, 0, 0, 0);  // @h1_512590
  ext_44a1f0_w0(ebx);  // @h2_512590
  u32 edi = F32(ebx, 0x50);
  F32(ebx, 0x123) = 0;  // @h3_512590
  if (edi != 0) {  // @h4_512590
    do {
      u32 g;
      int found = 0;
      if (F32(ebx, 0x123) == 0) {  // @h5_512590
        if (ext_4cc850_g(ext_4dc110_w0(edi), 0x69e524) == 0) {  // @h6_512590
          u32 o = F32(edi, 0x54);
          if (((u8(THISCALL *)(u32, u32))VSLOT(o, 0x1e0))(o, 0x200002) != 0) found = 1;  // @h7_512590
        }
        if (!found && F32(ebx, 0x123) == 0) {  // @h8_512590
          if (ext_4cc850_g(ext_4dc110_w0(edi), 0x69e534) == 0) {  // @h9_512590
            u32 o = F32(edi, 0x54);
            if (((u8(THISCALL *)(u32, u32))VSLOT(o, 0x1e0))(o, 0x200002) != 0) found = 1;  // @h10_512590
          }
          if (!found && F32(ebx, 0x123) == 0) {  // @h11_512590
            if (ext_4cc850_g(ext_4dc110_w0(edi), 0x69e53c) == 0) {  // @h12_512590
              u32 o = F32(edi, 0x54);
              if (((u8(THISCALL *)(u32, u32))VSLOT(o, 0x1e0))(o, 0x200002) != 0) found = 1;  // @h13_512590
            }
          }
        }
      }
      if (found) {
        u32 sy = G(u32, 0x70039c);
        u32 m = F32(sy, 0x9b);
        g = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x50))(m, edi);  // @h14_512590
        F32(ebx, 0x123) = g;  // @h15_512590
      } else {
        if (ext_4cc850_g(ext_4dc110_w0(edi), 0x69e544) == 0) {  // @h16_512590
          ext_4db860_w1(edi, 1);  // @h17_512590
          u32 vec = F32(ebx, 0x127);
          u32 vt = F32(vec, 0);
          u32 sy = G(u32, 0x70039c);
          u32 m = F32(sy, 0x9b);
          u32 e = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x50))(m, edi);  // @h18_512590
          vec = F32(ebx, 0x127);
          ((u32(THISCALL *)(u32, u32))F32(vt, 4))(vec, e);  // @h19_512590
        } else if (ext_4cc850_g(ext_4dc110_w0(edi), 0x69e550) == 0) {  // @h20_512590
          ext_4db860_w1(edi, 1);  // @h21_512590
          u32 vec = F32(ebx, 0x12b);
          u32 vt = F32(vec, 0);
          u32 sy = G(u32, 0x70039c);
          u32 m = F32(sy, 0x9b);
          u32 e = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x50))(m, edi);  // @h22_512590
          vec = F32(ebx, 0x12b);
          u32 r = ((u32(THISCALL *)(u32, u32))F32(vt, 4))(vec, e);  // @h23_512590
          F32(r, 0) = 0;  // @h24_512590
        }
      }
      edi = F32(edi, 0x60);  // @h25_512590
    } while (edi != 0);
  }
  u32 edx = F32(ebx, 0x123);
  if (edx != 0) {  // @h26_512590
    u32 sy = G(u32, 0x70039c);
    u32 m = F32(sy, 0x9b);
    u32 e2 = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edx);  // @h27_512590
    u32 esi = ((u32(THISCALL *)(u32, u32, u32))VSLOT(e2, 0x10c))(e2, 0x68f47c, 0xffffffff);  // @h28_512590
    int skip = 0;
    if (!(F8(esi, 4) & 1)) {  // @h29_512590
      ((u32(THISCALL *)(u32))VSLOT(esi, 8))(esi);  // @h30_512590
      F32(esi, 4) = F32(esi, 4) | 4;  // @h31_512590
      if (!(F8(esi, 4) & 1)) skip = 1;  // @h32_512590
    }
    if (!skip) {
      ((u32(THISCALL *)(u32))VSLOT(esi, 0x4c))(esi);  // @h33_512590
      u32 a = F32(esi, 0x30);
      F32(esi, 4) = F32(esi, 4) | 0x100;  // @h34_512590
      ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x54))(esi, a);  // @h35_512590
    }
    ((u32(THISCALL *)(u32, u32))VSLOT(e2, 0x3c))(e2, 1);  // @h36_512590
  }
  if (F32(ebx, 0x123) == 0) {  // @h37_512590
    u32 lg = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x69e4bc, 0x13a);  // @h38_512590
    u32 r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x1d8))(ebx, (u32)(u8 *)S, 1);  // @h39_512590
    reg.state = 0;
    u32 str = ext_4cc1d0_t0(r);  // @h40_512590
    ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x69e560, str);  // @h41_512590
    reg.state = -1;
    ext_4cbec0_t0((u32)(u8 *)S);  // @h42_512590
    FPCALL();  // @h43_512590
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
#undef F8
}
PCREG(512590, hand_512590);

extern "C" u32 THISCALL ext_514940_w3(u32, u32, u32, u32) __asm__("ext_514940");
extern "C" u32 THISCALL ext_527570_w0(u32) __asm__("ext_527570");
extern "C" u32 THISCALL ext_5273b0_w0(u32) __asm__("ext_5273b0");
extern "C" u32 THISCALL hand_520110(u32 ebx_this, u32 A1, u32 A2, u32 A3) {
  SEH_ENTER(0x66a3a6);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
  ext_514940_w3(ebx_this, A1, A2, A3);
  reg.state = 0;  // @h1_520110
  F32(ebx_this, 0x0) = 0x6a010c;  // @h2_520110
  ext_527570_w0(ebx_this + 0x2fd);
  reg.state = 1;  // @h3_520110
  ext_5273b0_w0(ebx_this + 0x263c);  // @h4_520110
  ext_5273b0_w0(ebx_this + 0x2695);  // @h5_520110
  ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ebx_this + 0x263c, 0))(ebx_this + 0x263c, 0x3f32b8c2, 0x3d567750, 0x41490fdb);  // @h6_520110
  ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(ebx_this + 0x2695, 0))(ebx_this + 0x2695, 0x3f860a92, 0x3f060a92, 0x40c90fdb);  // @h7_520110
  F32(ebx_this, 0x25d5) = 0x0;  // @h8_520110
  F32(ebx_this, 0x25d9) = 0x0;  // @h9_520110
  F32(ebx_this, 0x25dd) = 0x0;  // @h10_520110
  F32(ebx_this, 0x25e1) = 0x0;  // @h11_520110
  F32(ebx_this, 0x25d1) = 0x0;  // @h12_520110
  F32(ebx_this, 0x260c) = 0x0;  // @h13_520110
  F32(ebx_this, 0x2610) = 0x0;  // @h14_520110
  F32(ebx_this, 0x2614) = 0x0;  // @h15_520110
  F32(ebx_this, 0x2620) = 0x0;  // @h16_520110
  F32(ebx_this, 0x25cd) = 0x42a00000;  // @h17_520110
  u32 w = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(F32(G(u32, 0x70039c), 0x9b), 0x114))(F32(G(u32, 0x70039c), 0x9b), 0x6a04d4, 0, 0x6a04a8, 0x26);  // @h18_520110
  F16(ebx_this, 0x270b) = (u16)w;  // @h19_520110
  F32(ebx_this, 0x268d) = 0x0;  // @h20_520110
  F32(ebx_this, 0x2691) = 0x0;  // @h21_520110
  F32(ebx_this, 0x2f0) = 0x0;  // @h22_520110
  F32(ebx_this, 0x2f4) = 0x0;  // @h23_520110
  F32(ebx_this, 0x2f8) = 0x0;  // @h24_520110
  F8(ebx_this, 0x2fc) = 0x1;  // @h25_520110
  F32(ebx_this, 0x2624) = 0x0;  // @h26_520110
  F32(ebx_this, 0x2628) = 0x0;  // @h27_520110
  F32(ebx_this, 0x262c) = 0x3f800000;  // @h28_520110
  F32(ebx_this, 0x2630) = 0x0;  // @h29_520110
  F32(ebx_this, 0x2634) = 0x0;  // @h30_520110
  F32(ebx_this, 0x2638) = 0x3f800000;  // @h31_520110
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx_this + 0x263c, 4))(ebx_this + 0x263c, ebx_this + 0x2624, ebx_this + 0x2630);  // @h32_520110
  F16(ebx_this, 0x260a) = 0x0;  // @h33_520110
  F32(ebx_this, 0x2d8) = 0x0;  // @h34_520110
  F32(ebx_this, 0x2dc) = 0x0;  // @h35_520110
  F32(ebx_this, 0x2e0) = 0x3f800000;  // @h36_520110
  F32(ebx_this, 0x2e4) = 0x0;  // @h37_520110
  F32(ebx_this, 0x2e8) = 0x0;  // @h38_520110
  F32(ebx_this, 0x2ec) = 0x3f800000;  // @h39_520110
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx_this + 0x2695, 4))(ebx_this + 0x2695, ebx_this + 0x2d8, ebx_this + 0x2e4);  // @h40_520110
  F32(ebx_this, 0x2707) = 0x0;  // @h41_520110
  F32(ebx_this, 0x2618) = 0x49afc800;  // @h42_520110
  F32(ebx_this, 0x261c) = 0x4945c100;  // @h43_520110
  F32(ebx_this, 0x26ea) = 0x0;  // @h44_520110
  F32(ebx_this, 0x26e6) = 0x0;  // @h45_520110
  F8(ebx_this, 0x2706) = 0x1;  // @h46_520110
  SEH_LEAVE();
  return ebx_this;
#undef F32
#undef F16
#undef F8
}
PCREG(520110, hand_520110);

extern "C" u32 THISCALL hand_4e6ce0(u32 ecx_in) {
  SEH_ENTER(0x666500);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in + 0xc;
  volatile u32 it[2];
  F32(ecx_in, 0) = 0x68f068;  // @h1_4e6ce0
  if (esi != 0) {  // @h2_4e6ce0
    ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x4c))(esi, (u32)it);  // @h3_4e6ce0
    u32 e = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x5c))(esi, (u32)it);  // @h4_4e6ce0
    if (it[0] != 0) {  // @h5_4e6ce0
      do {
        ext_634273_cdecl2(e, 0x18);  // @h6_4e6ce0
        e = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x5c))(esi, (u32)it);  // @h7_4e6ce0
      } while (it[0] != 0);
    }
  }
  ext_4ccf60_t0(esi);  // @h8_4e6ce0
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(4e6ce0, hand_4e6ce0);

extern "C" u32 THISCALL hand_5fb370(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x66d436);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 ebx = ecx_in;
  u32 esi = A1;
  while (esi != 0) {  // @h1_5fb370
    hand_5fb370(ebx, F32(esi, 9));  // @h2_5fb370
    u32 edi = F32(esi, 5);  // @h3_5fb370
    u32 ecx = esi + 0xd;
    u32 edx = F32(ecx, 0);
    u32 len = F32(ecx, 8) - edx;
    reg.state = 0;
    if (edx != 0 && len != 0) ext_54f870_w2(ecx, edx, len);  // @h4_5fb370
    reg.state = -1;
    ext_54f870_w2(ebx, esi, 0x1d);  // @h5_5fb370
    esi = edi;
  }
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(5fb370, hand_5fb370);

extern "C" u32 THISCALL hand_5afef0(u32 ecx_in, u32 A1) {
  SEH_ENTER(0x66681b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 edi = ecx_in;
  volatile u32 L[4];
  volatile u32 it[2];
  u32 Lp = (u32)(u32 *)L;
  ext_4ccba0_t0(Lp);  // @h1_5afef0
  reg.state = 0;
  u32 ebx = ((u32(THISCALL *)(u32))VSLOT(A1, 0x2e8))(A1);  // @h2_5afef0
  u32 c = F32(edi, 0x44);
  ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(c, 0x130))(c, F32(edi, 0x1d0b), (u32)*(volatile u16 *)(edi + 0x1d2b), Lp);  // @h3_5afef0
  u32 esi = 0;
  ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x4c))(Lp, (u32)it);  // @h4_5afef0
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x5c))(Lp, (u32)it);  // @h5_5afef0
  if (it[0] != 0) {  // @h6_5afef0
    do {
      u32 sy = G(u32, 0x70039c);
      u32 m = F32(sy, 0x9b);
      u32 o = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, r);  // @h7_5afef0
      u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x2e8))(o);  // @h8_5afef0
      if (v == ebx) esi++;  // @h9_5afef0
      r = ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x5c))(Lp, (u32)it);  // @h10_5afef0
    } while (it[0] != 0);
  }
  ext_4ccf60_t0(Lp);  // @h11_5afef0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return esi;
#undef F32
}
PCREG(5afef0, hand_5afef0);

extern "C" u32 THISCALL ext_4ff920_w0(u32) __asm__("ext_4ff920");
extern "C" u32 THISCALL hand_4ff9d0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 ebx = ecx_in;
  u32 cnt = (F32(ebx, 4) - F32(ebx, 0)) >> 2;
  if (cnt != 0) {  // @h1_4ff9d0
    u32 i = 0;
    do {
      u32 p = F32(F32(ebx, 0), i * 4);
      if (p != 0) {  // @h2_4ff9d0
        ext_4ff920_w0(p);  // @h3_4ff9d0
        ext_634273_cdecl2(p, 0x48);  // @h4_4ff9d0
      }
      i++;
    } while (i < ((F32(ebx, 4) - F32(ebx, 0)) >> 2));  // @h5_4ff9d0
  }
  u32 esi = F32(ebx, 4);
  u32 begin = F32(ebx, 0);
  s32 d = (s32)(esi - begin) >> 2;  // @h6_4ff9d0
  F32(ebx, 4) = F32(ebx, 4) + (u32)(-d) * 4;  // @h7_4ff9d0
  u32 n = (F32(ebx, 8) - F32(ebx, 0)) >> 2;
  reg.state = 0;
  if (n != 0) ext_54f870_w2(ebx, F32(ebx, 0), n << 2);  // @h8_4ff9d0
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(4ff9d0, hand_4ff9d0);

extern "C" u32 THISCALL ext_603430_x(u32, u32, u32) __asm__("ext_603430");
extern "C" u32 THISCALL hand_6041e0(u32 ecx_in, u32 A1, u32 A2) {
  SEH_ENTER(0x66dd06);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  volatile u32 S[3];
  u32 Sp = (u32)(u32 *)S;
  ext_603430_x(esi, A1, A2);  // @h1_6041e0
  F32(esi, 0) = 0x6b97b4;  // @h2_6041e0
  F32(esi, 0x18) = esi + 0xc;  // @h3_6041e0
  F32(esi, 0x1c) = 0;  // @h4_6041e0
  F32(esi, 0x20) = 0;  // @h5_6041e0
  reg.state = 0;
  F32(esi, 0x26) = 0;  // @h6_6041e0
  S[0] = 0;  // @h7_6041e0
  S[1] = 0;  // @h8_6041e0
  S[2] = 0;  // @h9_6041e0
  u32 p = ext_6014a0_w1(Sp, 8);  // @h10_6041e0
  S[0] = p;  // @h11_6041e0
  S[1] = p;  // @h12_6041e0
  S[2] = p + 8;  // @h13_6041e0
  if (p != 0) *(volatile u8 *)p = 0;
  *(volatile u8 *)p = 0;  // @h14_6041e0
  reg.state = 1;
  ((u32(THISCALL *)(u32, u32))VSLOT(A1, 0x6c))(A1, Sp);  // @h15_6041e0
  if (S[1] - S[0] > 0x20) FPCALL();  // @h16_6041e0
  u32 g = G(u32, 0x724278);
  u32 ob = F32(g, 0x3c);
  u32 w = ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0))(ob, S[0]);  // @h17_6041e0
  *(volatile u16 *)(esi + 0x24) = (u16)w;  // @h18_6041e0
  u32 cap = S[2] - S[0];
  reg.state = 2;
  if (S[0] != 0 && cap != 0) ext_54f870_w2(Sp, S[0], cap);  // @h19_6041e0
  SEH_LEAVE();
  return esi;
#undef F32
}
PCREG(6041e0, hand_6041e0);

extern "C" u32 THISCALL hand_5bfac0(u32 ecx_in) {
  SEH_ENTER(0x66c558);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  volatile u32 loc10 = 0xcccccccc;
  ext_469870_t0(esi);  // @h1_5bfac0
  F32(esi, 4) = F32(esi, 4) | 0x20;  // @h2_5bfac0
  F32(esi, 0x44) = 0;  // @h3_5bfac0
  F32(esi, 0) = 0x6b38b4;  // @h4_5bfac0
  F32(esi, 0x54) = 0;  // @h5_5bfac0
  F32(esi, 0x50) = 0;  // @h6_5bfac0
  F32(esi, 0x4c) = 0;  // @h7_5bfac0
  F32(esi, 0x64) = 0;  // @h8_5bfac0
  reg.state = 0;
  u32 sy = G(u32, 0x70039c);
  u32 m = F32(sy, 0x9b);
  u32 w = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m, 0x114))(m, 0x6a557c, 0, 0x6b3950, 0x3f);  // @h9_5bfac0
  *(volatile u16 *)(esi + 0x48) = (u16)w;  // @h10_5bfac0
  sy = G(u32, 0x70039c);
  m = F32(sy, 0x9b);
  w = ((u32(THISCALL *)(u32, u32, u32, u32, u32))VSLOT(m, 0x114))(m, 0x6a558c, 0, 0x6b3950, 0x40);  // @h11_5bfac0
  *(volatile u16 *)(esi + 0x4a) = (u16)w;  // @h12_5bfac0
  u32 g = G(u32, 0x7003b8);
  F32(g, 0x2c11) = esi;  // @h13_5bfac0
  *(volatile u8 *)(esi + 0x68) = 1;  // @h14_5bfac0
  u32 s2 = G(u32, 0x70039c);
  u8 ok = ((u8(THISCALL *)(u32, u32, u32))VSLOT(s2, 0x5c))(s2, 0x6b3984, (u32)&loc10);  // @h15_5bfac0
  if (ok != 0) {  // @h16_5bfac0
    u32 a = loc10;
    u32 diff = 0;
    for (u32 i = 0;; i++) {
      u8 x = *(volatile u8 *)(a + i), y = *(volatile u8 *)(0x67a6d8 + i);
      if (x != y) { diff = 1; break; }
      if (x == 0) break;
    }
    if (diff == 0) *(volatile u8 *)(esi + 0x68) = 0;  // @h17_5bfac0
  }
  SEH_LEAVE();
  return esi;
#undef F32
}
PCREG(5bfac0, hand_5bfac0);

extern "C" u32 THISCALL ext_471f60_w0(u32) __asm__("ext_471f60");
extern "C" u32 THISCALL hand_480ff0(u32 ecx_in) {
  SEH_ENTER(0x667420);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 esi = ecx_in;
  F32(esi, 0) = 0x68b650;  // @h1_480ff0
  u32 ebx = esi + 0x45d;
  u32 edi = 0;
  do {
    u32 o = F32(ebx, 0);
    if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 4))(o, 1);  // @h2_480ff0
    edi++;
    ebx += 4;
  } while (edi <= F32(esi, 0x459));  // @h3_480ff0
  u32 o = F32(esi, 0x61a);
  if (o != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o, 0))(o, 1);  // @h4_480ff0
  static const u32 offs[6] = {0x62e, 0x632, 0x636, 0x63a, 0x62a, 0x63e};
  for (u32 k = 0; k < 6; k++) {  // @h5_480ff0
    u32 sy = G(u32, 0x70039c);
    ((u32(THISCALL *)(u32, u32))VSLOT(sy, 0x1a8))(sy, F32(esi, offs[k]));  // @h6_480ff0
    u32 f = F32(esi, offs[k]);
    if (f != 0) ((u32(THISCALL *)(u32, u32))VSLOT(f, 0))(f, 1);  // @h7_480ff0
  }
  ext_471f60_w0(esi);  // @h8_480ff0
  SEH_LEAVE();
  return 0;
#undef F32
}
PCREG(480ff0, hand_480ff0);

extern "C" u32 THISCALL ext_52a850_w3(u32, u32, u32, u32) __asm__("ext_52a850");
extern "C" u32 THISCALL ext_52a970_w3(u32, u32, u32, u32) __asm__("ext_52a970");
extern "C" u32 THISCALL ext_52b9d0_w0(u32) __asm__("ext_52b9d0");
extern "C" u32 FASTCALL ext_451890_f(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 THISCALL hand_52b4e0(u32 ecx_in, u32 P) {
  SEH_ENTER(0x66a66f);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define FL(a) (*(volatile float *)(a))
#define FBITS(x) ({ union { float f_; u32 u_; } t_; t_.f_ = (x); t_.u_; })
  u32 A = ecx_in;
  volatile float V0[3], V1[3], V2[3], V3[3], V4[3], V5[3], V6[3];  // l28, l1c, l6c, l60, l34, l78, l84
  volatile float l38;
  u32 pV0 = (u32)(float *)V0, pV1 = (u32)(float *)V1, pV2 = (u32)(float *)V2, pV3 = (u32)(float *)V3;
  u32 pV4 = (u32)(float *)V4, pV5 = (u32)(float *)V5, pV6 = (u32)(float *)V6, p38 = (u32)(float *)&l38;
  if (F32(A, 0x2d) != 0) ext_52b9d0_w0(A);  // @h1_52b4e0
  if (P == 0) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return P; }  // @h2_52b4e0
  {
    u32 pts = F32(P, 0xc);
    u32 q = pts + F32(P, 8) * 16;
    FL((u32)(float *)V4 + 0) = FL(q - 0x1c);  // @h3_52b4e0
    FL((u32)(float *)V4 + 4) = FL(q - 0x18);  // @h4_52b4e0
    FL((u32)(float *)V4 + 8) = FL(q - 0x14);  // @h5_52b4e0
    FL((u32)(float *)V5 + 0) = FL(q - 0xc);  // @h6_52b4e0
    FL((u32)(float *)V5 + 4) = FL(q - 8);  // @h7_52b4e0
    FL((u32)(float *)V5 + 8) = FL(q - 4);  // @h8_52b4e0
  }
  if (ext_52a970_w3(A, pV4, pV5, p38) != 0) {  // @h9_52b4e0
    u32 lg = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x6a0f54, 0x24bb);  // @h10_52b4e0
    ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x6a11bc);  // @h11_52b4e0
    u32 a = F32(P, 0xc);
    if (a != 0) ext_41e2c0_c1(a);  // @h12_52b4e0
    a = F32(P, 0x10);
    if (a != 0) ext_634273_cdecl2(a, 4);  // @h13_52b4e0
    a = F32(P, 0x14);
    if (a != 0) ext_634273_cdecl2(a, 4);  // @h14_52b4e0
    ext_634273_cdecl2(P, 0x18);  // @h15_52b4e0
    SEH_LEAVE();
    ext_633654(G(u32, 0x6f5630));
    return 0;
  }
  s32 nseg = (s32)F32(P, 8) - 1;
  s32 edi = 0;
  if (nseg <= 0) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return P; }  // @h16_52b4e0
  const float c1 = *(volatile float *)0x680a84;
  s32 oi = 0;
  do {  // @h17_52b4e0
    s32 i = oi;
    u32 base = F32(P, 0xc) + 16 * i;
    FL(pV0 + 0) = FL(base + 4);  // @h18_52b4e0
    float y0 = FL(base + 8) + c1;  // @h19_52b4e0
    FL(pV0 + 4) = y0;
    FL(pV0 + 8) = FL(base + 0xc);  // @h20_52b4e0
    FL(pV2 + 0) = FL(base + 0x14);  // @h21_52b4e0
    float y1 = FL(base + 0x18) + c1;  // @h22_52b4e0
    FL(pV2 + 4) = y1;
    FL(pV2 + 8) = FL(base + 0x1c);  // @h23_52b4e0
    for (s32 k = 0; k < 5;) {  // @h24_52b4e0
      u32 r = ext_52a850_w3(A, pV0, pV2, p38);  // @h25_52b4e0
      if (r == 0) break;  // @h26_52b4e0
      float d = l38;
      if (d < 0.0f) break;  // @h27_52b4e0
      if (*(volatile float *)0x678858 < d) break;  // @h28_52b4e0
      ext_43e920_f(pV3, pV2, pV0);  // @h29_52b4e0
      float f = l38 + *(volatile float *)0x68c730;  // @h30_52b4e0
      ext_451890_f(pV0, pV3, FBITS(f));  // @h31_52b4e0
      k++;
      edi++;  // @h32_52b4e0
    }
    oi++;
  } while (oi < (s32)F32(P, 8) - 1);
  if (edi == 0) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return P; }  // @h33_52b4e0
  u32 raw = ext_41e290_cdecl1((u32)0x18);  // @h34_52b4e0
  reg.state = 0;
  u32 N = 0;
  if (raw != 0) N = ext_476dc0_t1(raw, F32(P, 8) + (u32)edi);  // @h35_52b4e0
  reg.state = -1;
  F32(N, 4) = F32(P, 4);  // @h36_52b4e0
  F32(F32(N, 0xc), 0) = 0;  // @h37_52b4e0
  s32 j = 0;
  if ((s32)F32(P, 8) > 0) {  // @h38_52b4e0
    for (s32 i = 0; i < (s32)F32(P, 8); i++) {  // @h39_52b4e0
      u32 base = F32(P, 0xc) + 16 * i;
      u32 dest = F32(N, 0xc);
      u32 dj = dest + 16 * j;
      float l1c = FL(base + 4), l18 = FL(base + 8), l14 = FL(base + 0xc);
      FL(pV1 + 0) = l1c; FL(pV1 + 4) = l18; FL(pV1 + 8) = l14;  // @h40_52b4e0
      FL(dj + 4) = l1c; FL(dj + 8) = l18; FL(dj + 0xc) = l14;  // @h41_52b4e0
      if (j != 0) {  // @h42_52b4e0
        float dd = ext_4e0870_f(pV1, dest + 16 * j - 0xc);  // @h43_52b4e0
        FL(dj) = FL(dj - 0x10) + dd;  // @h44_52b4e0
      }
      F32(F32(N, 0x10), j * 4) = 0;  // @h45_52b4e0
      j++;
      if (i >= (s32)F32(P, 8) - 1) continue;  // @h46_52b4e0
      FL(pV3 + 0) = FL(base + 0x14);  // @h47_52b4e0
      FL(pV3 + 4) = FL(base + 0x18) + c1;  // @h48_52b4e0
      FL(pV3 + 8) = FL(base + 0x1c);  // @h49_52b4e0
      FL(pV1 + 4) = FL(pV1 + 4) + c1;  // @h50_52b4e0
      for (s32 k = 0; k < 5;) {  // @h51_52b4e0
        u32 rr = ext_52a850_w3(A, pV1, pV3, p38);  // @h52_52b4e0
        if (rr == 0) break;
        float d = l38;
        if (d < 0.0f) break;
        if (*(volatile float *)0x678858 < d) break;
        ext_43e920_f(pV6, pV3, pV1);  // @h53_52b4e0
        float f = l38 + *(volatile float *)0x68c730;  // @h54_52b4e0
        ext_451890_f(pV1, pV6, FBITS(f));  // @h55_52b4e0
        u32 dest2 = F32(N, 0xc);
        u32 dk = dest2 + 16 * j;
        FL(dk + 4) = FL(pV1 + 0); FL(dk + 8) = FL(pV1 + 4); FL(dk + 0xc) = FL(pV1 + 8);  // @h56_52b4e0
        FL(dk + 8) = FL(dk + 8) - c1;  // @h57_52b4e0
        float d2 = ext_4e0870_f(dk + 4, dk - 0xc);  // @h58_52b4e0
        FL(dk) = FL(dk - 0x10) + d2;  // @h59_52b4e0
        F32(F32(N, 0x10), j * 4) = F32(rr, 0x30);  // @h60_52b4e0
        j++;
        k++;
      }
    }
  }
  {
    u32 dest = F32(N, 0xc);
    F32(N, 4) = F32(dest + 16 * j, -0x10);  // @h61_52b4e0
  }
  {
    u32 a = F32(P, 0xc);
    if (a != 0) ext_41e2c0_c1(a);  // @h62_52b4e0
    a = F32(P, 0x10);
    if (a != 0) ext_634273_cdecl2(a, 4);  // @h63_52b4e0
    a = F32(P, 0x14);
    if (a != 0) ext_634273_cdecl2(a, 4);  // @h64_52b4e0
    ext_634273_cdecl2(P, 0x18);  // @h65_52b4e0
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return N;
#undef F32
#undef FL
#undef FBITS
}
PCREG(52b4e0, hand_52b4e0);

struct W3B48 { u8 b[0x48]; };
extern "C" void THISCALL ext_5ab190_s(u32, W3B48) __asm__("ext_5ab190");
extern "C" u32 THISCALL hand_5e94c0(u32 ecx_in) {
  SEH_ENTER(0x66c9eb);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  u32 A = ecx_in;
  volatile u32 L[4];
  volatile u32 it[2];
  volatile u8 Sx[0x50];
  u32 Lp = (u32)(u32 *)L, S = (u32)(u8 *)Sx;
  ext_4ccba0_t0(Lp);  // @h1_5e94c0
  reg.state = 0;
  ext_634d10_cdecl3(S, 0, 0x45);  // @h2_5e94c0
  u32 c = F32(A, 0x44);
  ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(c, 0x130))(c, F32(A, 0x1d0b), (u32)*(volatile u16 *)(A + 0x1d2b), Lp);  // @h3_5e94c0
  ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x4c))(Lp, (u32)it);  // @h4_5e94c0
  u32 edx = ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x5c))(Lp, (u32)it);  // @h5_5e94c0
  u32 cnt8 = 0;
  u32 (*cmpf)(u32, u32) = (u32(*)(u32, u32))G(u32, 0x676414);
  if (it[0] != 0) {  // @h6_5e94c0
    cnt8 = F32(S, 8);
#define NAME(o) ({ u32 n_ = ((u32(THISCALL *)(u32))VSLOT(o, 0x2e8))(o); u32 p_ = F32(n_, 4); p_ != 0 ? p_ : 0x67c8e8u; })
#define SK(o, k) cmpf(NAME(o), (k))
    do {
      u32 sy = G(u32, 0x70039c);
      u32 m = F32(sy, 0x9b);
      u32 o = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, edx);  // @h7_5e94c0
      if (((u8(THISCALL *)(u32, u32))VSLOT(o, 0x1e0))(o, 0x1007d8) != 0) goto next;  // @h8_5e94c0
      if (SK(o, 0x6ad8a8) == 0) {  // @h9_5e94c0
        F32(S, 0x10) = F32(S, 0x10) + 1; F32(S, 0x41) = o; goto next;  // @h10_5e94c0
      }
      if (SK(o, 0x690aec) == 0) {  // @h11_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h12_5e94c0
        F32(S, 4) = v; F32(S, 0x29) = o;  // @h13_5e94c0
        u32 mm = F32(A, 0x1d0b);
        u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(mm, 0x55c))(mm, o);  // @h14_5e94c0
        if (q == 0) goto next;  // @h15_5e94c0
        u32 w = ((u32(THISCALL *)(u32))VSLOT(q, 0x320))(q);  // @h16_5e94c0
        F32(S, 4) = F32(S, 4) + w; goto next;  // @h17_5e94c0
      }
      if (SK(o, 0x6ad8b4) == 0) {  // @h18_5e94c0
        *(volatile u8 *)(S + 0x14) = 1; F32(S, 0x35) = o; goto next;  // @h19_5e94c0
      }
      if (SK(o, 0x690af4) == 0) {  // @h20_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h21_5e94c0
        F32(S, 0xc) = v; F32(S, 0x31) = o;  // @h22_5e94c0
        u32 mm = F32(A, 0x1d0b);
        u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(mm, 0x55c))(mm, o);  // @h23_5e94c0
        if (q == 0) goto next;  // @h24_5e94c0
        u32 w = ((u32(THISCALL *)(u32))VSLOT(q, 0x320))(q);  // @h25_5e94c0
        F32(S, 0xc) = F32(S, 0xc) + w; goto next;  // @h26_5e94c0
      }
      if (SK(o, 0x6ad894) == 0) {  // @h27_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h28_5e94c0
        F32(S, 0x15) = v; F32(S, 0x21) = 2; F32(S, 0x3d) = o; goto next;  // @h29_5e94c0
      }
      if (SK(o, 0x6ad870) == 0) {  // @h30_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h31_5e94c0
        F32(S, 0x21) = 5; F32(S, 0x15) = v; F32(S, 0x3d) = o;  // @h32_5e94c0
        u32 mm = F32(A, 0x1d0b);
        u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(mm, 0x55c))(mm, o);  // @h33_5e94c0
        if (q == 0) goto next;  // @h34_5e94c0
        u32 w = ((u32(THISCALL *)(u32))VSLOT(q, 0x320))(q);  // @h35_5e94c0
        F32(S, 0x15) = F32(S, 0x15) + w; goto next;  // @h36_5e94c0
      }
      if (SK(o, 0x6ad858) == 0) {  // @h37_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h38_5e94c0
        F32(S, 0x21) = 6;  // @h39_5e94c0
        F32(S, 0x15) = v; F32(S, 0x3d) = o;  // @h40_5e94c0
        u32 mm = F32(A, 0x1d0b);
        u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(mm, 0x55c))(mm, o);  // @h41_5e94c0
        if (q == 0) goto next;  // @h42_5e94c0
        u32 w = ((u32(THISCALL *)(u32))VSLOT(q, 0x320))(q);  // @h43_5e94c0
        F32(S, 0x15) = F32(S, 0x15) + w; goto next;  // @h44_5e94c0
      }
      if (SK(o, 0x6b0090) == 0) {  // @h45_5e94c0
        F32(S, 0x1d) = 2; F32(S, 0x39) = o; goto next;  // @h46_5e94c0
      }
      if (SK(o, 0x6b8050) == 0) {  // @h47_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h48_5e94c0
        F32(S, 0x15) = v; F32(S, 0x21) = 3; F32(S, 0x3d) = o; goto next;  // @h49_5e94c0
      }
      if (SK(o, 0x6ad838) == 0) {  // @h50_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h51_5e94c0
        F32(S, 0x15) = v; F32(S, 0x21) = 4; F32(S, 0x3d) = o; goto next;  // @h52_5e94c0
      }
      {
        int hit = 0, v1 = 0;
        if (SK(o, 0x6ad84c) == 0) { hit = 1; v1 = 1; }  // @h53_5e94c0
        else if (SK(o, 0x6ad884) == 0) { hit = 1; v1 = 3; }  // @h54_5e94c0
        if (hit) {
          u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h55_5e94c0
          F32(S, 0x1d) = v1; F32(S, 0x19) = v; F32(S, 0x39) = o;  // @h56_5e94c0
          u32 mm = F32(A, 0x1d0b);
          u32 q = ((u32(THISCALL *)(u32, u32))VSLOT(mm, 0x55c))(mm, o);  // @h57_5e94c0
          if (q == 0) goto next;  // @h58_5e94c0
          u32 w = ((u32(THISCALL *)(u32))VSLOT(q, 0x320))(q);  // @h59_5e94c0
          F32(S, 0x19) = F32(S, 0x19) + w; goto next;  // @h60_5e94c0
        }
      }
      if (SK(o, 0x6b00b4) == 0) {  // @h61_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h62_5e94c0
        F32(S, 0x15) = v; F32(S, 0x21) = 1; F32(S, 0x3d) = o; goto next;  // @h63_5e94c0
      }
      if (SK(o, 0x6ad858) == 0) {  // @h64_5e94c0
        u32 v = ((u32(THISCALL *)(u32))VSLOT(o, 0x35c))(o);  // @h65_5e94c0
        F32(S, 0x15) = v; F32(S, 0x21) = 0; F32(S, 0x3d) = o; goto next;  // @h66_5e94c0
      }
      if (SK(o, 0x6ad8a0) == 0) {  // @h67_5e94c0
        F32(S, 0) = F32(S, 0) + 1; F32(S, 0x25) = o; goto next;  // @h68_5e94c0
      }
      if (SK(o, 0x6ace88) != 0 && SK(o, 0x6ace98) != 0 && SK(o, 0x6acb04) != 0) goto next;  // @h69_5e94c0
      cnt8++; F32(S, 0x2d) = o; F32(S, 8) = cnt8;  // @h70_5e94c0
    next:
      edx = ((u32(THISCALL *)(u32, u32))VSLOT(Lp, 0x5c))(Lp, (u32)it);  // @h71_5e94c0
    } while (it[0] != 0);  // @h72_5e94c0
  }
  if (F32(A, 0x1d0f) != 0) {  // @h73_5e94c0
    W3B48 arg;
    for (u32 k = 0; k < 0x45; k++) arg.b[k] = Sx[k];  // @h74_5e94c0
    ext_5ab190_s(F32(A, 0x1d0f), arg);  // @h75_5e94c0
  }
  ext_4ccf60_t0(Lp);  // @h76_5e94c0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return 0;
#undef F32
}
PCREG(5e94c0, hand_5e94c0);

extern "C" u32 THISCALL ext_4ccbe0_w2(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccfe0_w0(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4db7c0_w1(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4db6c0_w2(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4daf90_w1(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db670_w1(u32, u32) __asm__("ext_4db670");
extern "C" u32 FASTCALL ext_4de420_f2(u32, u32) __asm__("ext_4de420");
extern "C" u8 FASTCALL ext_4df330_f(u32, u32, u32, u32, u32, u32) __asm__("ext_4df330");
extern "C" u8 FASTCALL ext_49b9a0_f(u32, u32, u32, u32) __asm__("ext_49b9a0");
extern "C" u8 FASTCALL ext_49bbc0_f(u32, u32, u32, u32, u32) __asm__("ext_49bbc0");
extern "C" u8 FASTCALL ext_49be80_f(u32, u32, u32, u32, u32, u32) __asm__("ext_49be80");
extern "C" u32 THISCALL ext_4da2f0_w2(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL hand_49cda0(u32 T, u32 cntp, u32 obj) {
  SEH_ENTER(0x668396);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  volatile u32 R[8], M94[9], M70[9], V4c[3], V40[3], V34[3], V28[3], V1c[3], AREA[15], S114[32];
  u32 pR = (u32)(u32 *)R, p94 = (u32)(u32 *)M94, p70 = (u32)(u32 *)M70, p4c = (u32)(u32 *)V4c, p40 = (u32)(u32 *)V40;
  u32 p34 = (u32)(u32 *)V34, p28 = (u32)(u32 *)V28, p1c = (u32)(u32 *)V1c, pA = (u32)(u32 *)AREA;
  F32(cntp, 0) = 0;  // @h1_49cda0
  if (obj == 0) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return 0; }  // @h2_49cda0
  ext_4ccbe0_w2(pR, 0x20, 9);  // @h3_49cda0
  reg.state = 0;
  {
    u32 g = G(u32, 0x70039c);
    u32 o1 = F32(g, 0x1aa3);
    u32 c1 = F32(o1, 0x18);
    u32 rr = ((u32(THISCALL *)(u32, u32))VSLOT(c1, 0x54))(c1, F32(obj, 0x6c));  // @h4_49cda0
    if (rr == 0) {  // @h5_49cda0
      g = G(u32, 0x70039c);
      o1 = F32(g, 0x1aa3);
      c1 = F32(o1, 0x18);
      ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(c1, 8))(c1, pR, F32(obj, 0x6c), 0xffffffff);  // @h6_49cda0
    }
  }
  ext_4de7a0_t0(p94);  // @h7_49cda0
  ext_4db7c0_w1(obj, p4c);  // @h8_49cda0
  ext_4db6c0_w2(obj, p94, p40);  // @h9_49cda0
  ext_4daf90_w1(obj, p28);  // @h10_49cda0
  ext_4db670_w1(obj, p28);  // @h11_49cda0
  u32 edi = F32(obj, 0x54);
  u32 keep = edi;
  u8 al = ((u8(THISCALL *)(u32, u32))VSLOT(edi, 0x1e0))(edi, 0x100021);  // @h12_49cda0
  if (al == 0) {  // @h13_49cda0
    do {
      edi = ((u32(THISCALL *)(u32))VSLOT(edi, 0x20))(edi);  // @h14_49cda0
      al = ((u8(THISCALL *)(u32, u32))VSLOT(edi, 0x1e0))(edi, 0x100021);  // @h15_49cda0
    } while (al == 0);
    keep = edi;
  }
  u32 esi = edi;
  u8 flag = 0;
  u32 cur = 0;
  while (flag == 0) {  // @h16_49cda0
    cur = F32(esi, 0x54);
    while (cur != 0) {  // @h17_49cda0
      u32 edx = F32(cur, 0x54);
      u32 kind = 0x200002;
      if (edx != 0) kind = F32(F32(edx, 0xc), 0x23);
      if (kind & 0x100000) break;  // @h18_49cda0
      if (edx != 0 && F32(F32(edx, 0xc), 0x23) == 0x80000d) {  // @h19_49cda0
        flag = 1;
        F32(T, F32(cntp, 0) * 4 + 0x41) = cur;  // @h20_49cda0
        F32(cntp, 0) = F32(cntp, 0) + 1;  // @h21_49cda0
        break;
      }
      cur = ext_4db520_t0(cur);  // @h22_49cda0
    }
    esi = ((u32(THISCALL *)(u32))VSLOT(esi, 0x20))(esi);  // @h23_49cda0
    if (esi == 0) break;  // @h24_49cda0
  }
  edi = keep;
  volatile u32 cur2;
  u32 nodeP = F32(edi, 8);
  cur2 = nodeP;
  if (nodeP != 0) {  // @h25_49cda0
    int overflow = 0;
    do {
      u32 e = F32(cur2, 0x54);
      int add = 0;
      int skip = 0;
      if (e == 0) skip = 1;  // @h26_49cda0
      else if (!(F32(F32(e, 0xc), 0x23) & 0x800000)) skip = 1;  // @h27_49cda0
      if (!skip) {
        u32 edx = ((u32(THISCALL *)(u32))VSLOT(e, 0x20))(e);  // @h28_49cda0
        while (edx != 0) {  // @h29_49cda0
          if (F32(F32(edx, 0xc), 0x23) == 0x1000ea) { skip = 1; break; }  // @h30_49cda0
          edx = ((u32(THISCALL *)(u32))VSLOT(edx, 0x20))(edx);  // @h31_49cda0
        }
      }
      if (!skip) {
        for (u32 k = 0; k < 12; k++) *(volatile u8 *)(p34 + k) = *(volatile u8 *)(p28 + k);  // @h32_49cda0
        ext_4de420_f2(p70, p94);  // @h33_49cda0
        for (u32 k = 0; k < 12; k++) *(volatile u8 *)(p1c + k) = *(volatile u8 *)(p40 + k);  // @h34_49cda0
        ((u32(THISCALL *)(u32, u32, u32))VSLOT(e, 0x94))(e, p70, p1c);  // @h35_49cda0
        ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x8c))(e, p34);  // @h36_49cda0
        u32 ec = F32(e, 8);
        u8 ok = ext_4df330_f(ec, ec + 0x30, ec + 0x40, p70, p34, p4c);  // @h37_49cda0
        if (ok == 0) skip = 1;  // @h38_49cda0
        if (!skip) {
          u32 key = F32(F32(e, 8), 0x6c);
          u8 r2;
          if (((u8(THISCALL *)(u32, u32))VSLOT(e, 0x1e0))(e, 0x800024)) {  // @h39_49cda0
            u32 g = G(u32, 0x70039c);
            u32 o1 = F32(g, 0x1aa3);
            u32 c1 = F32(o1, 0x18);
            ((u32(THISCALL *)(u32, u32, u32))VSLOT(c1, 0x80))(c1, key, pA + 0x18);  // @h40_49cda0
            u32 f = AREA[(0x184 - 0x150) / 4];
            r2 = ext_49b9a0_f(p70, p1c, f, pR);  // @h41_49cda0
          } else if (((u8(THISCALL *)(u32, u32))VSLOT(e, 0x1e0))(e, 0x800023)) {  // @h42_49cda0
            u32 g = G(u32, 0x70039c);
            u32 o1 = F32(g, 0x1aa3);
            u32 c1 = F32(o1, 0x18);
            ((u32(THISCALL *)(u32, u32, u32))VSLOT(c1, 0x84))(c1, key, pA + 4);  // @h43_49cda0
            u32 f2 = AREA[(0x184 - 0x154) / 4];
            u32 f1 = AREA[(0x184 - 0x164) / 4];
            r2 = ext_49bbc0_f(p70, p1c, f1, f2, pR);  // @h44_49cda0
          } else if (((u8(THISCALL *)(u32, u32))VSLOT(e, 0x1e0))(e, 0x800020)) {  // @h45_49cda0
            u32 g = G(u32, 0x70039c);
            u32 o1 = F32(g, 0x1aa3);
            u32 c1 = F32(o1, 0x18);
            ((u32(THISCALL *)(u32, u32, u32))VSLOT(c1, 0x88))(c1, key, pA + 0);  // @h46_49cda0
            u32 f3 = AREA[(0x184 - 0x14c) / 4];
            u32 f2 = AREA[(0x184 - 0x158) / 4];
            u32 f1 = AREA[(0x184 - 0x168) / 4];
            r2 = ext_49be80_f(p70, p1c, f1, f2, f3, pR);  // @h47_49cda0
          } else {
            r2 = 1;
          }
          if (r2 != 0) {  // @h48_49cda0
            u32 n = F32(cntp, 0);
            if (n == 8) { overflow = 1; break; }  // @h49_49cda0
            F32(T, n * 4 + 0x41) = cur2;  // @h50_49cda0
            F32(cntp, 0) = F32(cntp, 0) + 1;  // @h51_49cda0
          }
        }
      }
      ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x50))(edi, (u32)&cur2);  // @h52_49cda0
    } while (cur2 != 0);  // @h53_49cda0
    if (overflow) {
      u32 lg = G(u32, 0x700390);
      u32 oo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68ed40, 0x544);  // @h54_49cda0
      u32 sp = ext_4da2f0_w2(obj, (u32)(u32 *)S114, 1);  // @h55_49cda0
      reg.state = 1;
      ((u32(*)(u32, u32, u32))VSLOT(oo, 0x30))(oo, 0x68ee58, F32(sp, 0));  // @h56_49cda0
      ext_4cbec0_t0((u32)(u32 *)S114);  // @h57_49cda0
    }
  }
  ext_4ccfe0_w0(pR);  // @h58_49cda0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return T + 0x41;
#undef F32
}
PCREG(49cda0, hand_49cda0);

extern "C" u32 STDCALL ext_6352f0_s(u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_59a6e0_w1(u32, u32) __asm__("ext_59a6e0");
extern "C" u32 THISCALL ext_5b7bd0_w0(u32) __asm__("ext_5b7bd0");
extern "C" u32 THISCALL ext_5b7c00_w1(u32, u32) __asm__("ext_5b7c00");
extern "C" u32 THISCALL ext_5b7dd0_w0b(u32) __asm__("ext_5b7dd0");
extern "C" u32 THISCALL ext_5b7e40_w1(u32, u32) __asm__("ext_5b7e40");
extern "C" u32 THISCALL ext_5eaab0_w2(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL hand_5e9e20(u32 this_, u32 S) {
  SEH_ENTER(0x66ca6b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define MGR58(v) { u32 sy_ = G(u32, 0x70039c); u32 m_ = F32(sy_, 0x9b); mgr_r = ((u32(THISCALL *)(u32, u32))VSLOT(m_, 0x58))(m_, (v)); }
  volatile u32 loc20 = 0, loc28 = 0xcccccccc, loc2c = 0xcccccccc, loc18 = 0xcccccccc;
  u32 mgr_r = 0;
  F32(this_, 4) = F32(this_, 4) & 0xffffffbf;  // @h200_5e9e20
  ext_6352f0_s((u32)&loc20);  // @h201_5e9e20
  ext_59a6e0_w1(this_, (u32)&loc20);  // @h202_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1fb6);  // @h1_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1fba);  // @h2_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1fbe);  // @h3_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1cff);  // @h4_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x22c2);  // @h5_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x68))(S, this_ + 0x22ce);  // @h6_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x22cf);  // @h7_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1fb2);  // @h8_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1fae);  // @h9_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x68))(S, this_ + 0x1d95);  // @h10_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d91);  // @h11_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x6c))(S, this_ + 0x1d96);  // @h12_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1d4b);  // @h13_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x1d47);  // @h14_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d17);  // @h15_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x68))(S, this_ + 0x2ee);  // @h16_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x2ea);  // @h17_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x2e6);  // @h18_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x6d);  // @h19_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x69);  // @h20_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x65);  // @h21_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x48))(S, this_ + 0x4ef);  // @h22_5e9e20
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, this_ + 0x1fc2, 0x300);  // @h23_5e9e20
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, this_ + 0x4ff, 0x1800);  // @h24_5e9e20
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, this_ + 0x2ef, 0x200);  // @h25_5e9e20
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x18))(S, this_ + 0xe6, 0x200);  // @h26_5e9e20
  { u32 q = this_ + 0x1dae;
    for (u32 k = 0; k < 0x80; k++, q += 4) ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, q);  // @h27_5e9e20
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x54);  // @h28_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x6d);  // @h29_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d1b);  // @h30_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d1f);  // @h31_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d23);  // @h32_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d27);  // @h33_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, (u32)&loc28);  // @h34_5e9e20
  MGR58(loc28);  // @h35_5e9e20
  F32(this_, 0x1d0b) = mgr_r;  // @h36_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, (u32)&loc28);  // @h37_5e9e20
  MGR58(loc28);  // @h38_5e9e20
  F32(this_, 0x1d07) = mgr_r;  // @h39_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, (u32)&loc28);  // @h40_5e9e20
  MGR58(loc28);  // @h41_5e9e20
  F32(this_, 0x4f3) = mgr_r;  // @h42_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x61);  // @h43_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x50))(S, this_ + 0x1d13);  // @h44_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d3b);  // @h45_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d3f);  // @h46_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d43);  // @h47_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x68))(S, this_ + 0x60);  // @h48_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x68))(S, this_ + 0x1d4f);  // @h49_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x6c))(S, this_ + 0x1d50);  // @h50_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x6c))(S, this_ + 0x1d5c);  // @h51_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x6c))(S, this_ + 0x1d68);  // @h52_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x6c))(S, this_ + 0x1d74);  // @h53_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d80);  // @h54_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d84);  // @h55_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d88);  // @h56_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x68))(S, this_ + 0x1d8c);  // @h57_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x1d8d);  // @h58_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, (u32)&loc2c);  // @h59_5e9e20
  MGR58(loc2c);  // @h60_5e9e20
  F32(this_, 0x1d0f) = mgr_r;  // @h61_5e9e20
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, (u32)&loc18);  // @h62_5e9e20
  u32 V = this_ + 0x1da2;
  u32 begin = F32(V, 0);
  u32 n = loc18;
  u32 capc = (u32)((s32)(F32(V, 8) - begin) >> 2);
  if (capc < n) {  // @h203_5e9e20
    u32 end = F32(V, 4);
    u32 size = (u32)((s32)(end - begin) >> 2);
    u32 nb = 0;
    if (n != 0) nb = ext_6014a0_w1(V, n * 4);  // @h204_5e9e20
    u32 cnt = (end - begin + 3) >> 2;
    if (begin > end) cnt = 0;  // @h205_5e9e20
    u32 dst = nb;
    for (u32 k = 0; k < cnt; k++, dst += 4) {  // @h206_5e9e20
      if (dst != 0) F32(dst, 0) = F32(begin, k * 4);  // @h207_5e9e20
    }
    u32 oc = (u32)((s32)(F32(V, 8) - F32(V, 0)) >> 2);
    if (oc != 0) ext_54f870_w2(V, F32(V, 0), oc << 2);  // @h208_5e9e20
    F32(V, 0) = nb;  // @h209_5e9e20
    F32(V, 4) = nb + size * 4;  // @h210_5e9e20
    F32(V, 8) = nb + n * 4;  // @h211_5e9e20
  }
  volatile u32 entry;
  for (u32 i = 0; n != 0 && i < n; i++) {  // @h212_5e9e20
    u32 e = ext_41e290_cdecl1((u32)0x1c);  // @h213_5e9e20
    entry = e;
    F32(e, 0) = 0; F32(e, 4) = 0; F32(e, 8) = 0; F32(e, 0xc) = 0; F32(e, 0x10) = 0; F32(e, 0x14) = 0; F32(e, 0x18) = 0;  // @h214_5e9e20
    u32 b = ext_41e290_cdecl1((u32)0x10);  // @h215_5e9e20
    reg.state = 0;
    u32 rb = 0;
    if (b != 0) rb = ext_5b7dd0_w0b(b);  // @h216_5e9e20
    reg.state = -1;
    F32(e, 8) = rb;  // @h217_5e9e20
    u32 c1 = ext_41e290_cdecl1((u32)0x29);  // @h218_5e9e20
    reg.state = 1;
    u32 r1 = 0;
    if (c1 != 0) r1 = ext_5b7bd0_w0(c1);  // @h219_5e9e20
    reg.state = -1;
    F32(e, 0xc) = r1;  // @h220_5e9e20
    u32 c2 = ext_41e290_cdecl1((u32)0x29);  // @h221_5e9e20
    reg.state = 2;
    u32 r2 = 0;
    if (c2 != 0) r2 = ext_5b7bd0_w0(c2);  // @h222_5e9e20
    reg.state = -1;
    F32(e, 0x10) = r2;  // @h223_5e9e20
    u32 c3 = ext_41e290_cdecl1((u32)0x29);  // @h224_5e9e20
    reg.state = 3;
    u32 r3 = 0;
    if (c3 != 0) r3 = ext_5b7bd0_w0(c3);  // @h225_5e9e20
    F32(e, 0x14) = r3;  // @h226_5e9e20
    reg.state = -1;
    ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, e);  // @h227_5e9e20
    MGR58(F32(e, 0)); F32(e, 4) = mgr_r;  // @h228_5e9e20
    ext_5b7e40_w1(F32(e, 8), S);  // @h229_5e9e20
    ext_5b7c00_w1(F32(e, 0xc), S);  // @h230_5e9e20
    ext_5b7c00_w1(F32(e, 0x10), S);  // @h231_5e9e20
    ext_5b7c00_w1(F32(e, 0x14), S);  // @h232_5e9e20
    u32 end2 = F32(this_, 0x1da6);
    if (end2 == F32(this_, 0x1daa)) {  // @h233_5e9e20
      ext_5fe3b0_w2(V, end2, (u32)&entry);  // @h234_5e9e20
    } else {
      if (end2 != 0) F32(end2, 0) = e;  // @h235_5e9e20
      F32(this_, 0x1da6) = F32(this_, 0x1da6) + 4;  // @h236_5e9e20
    }
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x40))(S, this_ + 0x22df);  // @h237_5e9e20
  F32(this_, 0x22d3) = 0;  // @h238_5e9e20
  u32 o = ext_41e290_cdecl1((u32)0x4c);  // @h239_5e9e20
  reg.state = 4;
  if (o != 0) {  // @h240_5e9e20
    u32 rr = ext_5eaab0_w2(o, F32(this_, 0x1d0f), 0x10);  // @h241_5e9e20
    F32(this_, 0x22d7) = rr;  // @h242_5e9e20
  } else {
    F32(this_, 0x22d7) = 0;  // @h243_5e9e20
  }
  SEH_LEAVE();
  return 1;
#undef F32
#undef MGR58
}
PCREG(5e9e20, hand_5e9e20);

extern "C" u32 ext_63456a_c1(...) __asm__("ext_63456a");
extern "C" u32 ext_63452b_c1(...) __asm__("ext_63452b");
static inline double w3c_crtmath(double x) {
  double out;
  __asm__ volatile("movsd %1, %%xmm0\n\tcall ext_634de8\n\tmovsd %%xmm0, %0" : "=m"(out) : "m"(x) : "xmm0", "xmm1", "xmm2", "eax", "ecx", "edx", "cc", "memory");
  return out;
}
extern "C" float STDCALL hand_4e6910(float a) {
  u32 tls;
  __asm__ volatile("movl %%fs:0x2c, %0" : "=r"(tls));  // @h1_4e6910
  u32 idx = G(u32, 0x7257d4);
  u32 p = *(volatile u32 *)(tls + idx * 4);  // @h2_4e6910
  s32 flag = (s32)G(u32, 0x700564);
  if (flag > (s32)*(volatile u32 *)(p + 4)) {  // @h3_4e6910
    ext_63456a_c1((u32)0x700564);  // @h4_4e6910
    if ((s32)G(u32, 0x700564) == -1) {  // @h5_4e6910
      double d = w3c_crtmath(G(double, 0x697520));  // @h6_4e6910
      float f = (float)d;
      float q = G(float, 0x678858) / f;  // @h7_4e6910
      G(float, 0x700560) = q;  // @h8_4e6910
      ext_63452b_c1((u32)0x700564);  // @h9_4e6910
    }
  }
  double d2 = w3c_crtmath((double)a);  // @h10_4e6910
  double m = d2 * (double)G(float, 0x700560);  // @h11_4e6910
  return (float)m;
}
PCREG(4e6910, hand_4e6910);

extern "C" u32 THISCALL ext_48aad0_w0(u32) __asm__("ext_48aad0");
extern "C" u32 THISCALL ext_48f700_w0(u32) __asm__("ext_48f700");
extern "C" u32 THISCALL ext_496a40_w0(u32) __asm__("ext_496a40");
extern "C" u32 THISCALL ext_496760_w0(u32) __asm__("ext_496760");
extern "C" u32 THISCALL ext_49d480_w0(u32) __asm__("ext_49d480");
static inline u8 w3c_call258(u32 obj, u32 fn, u32 arg) {
  __asm__ volatile("pushl %2\n\tcall *%%eax\n\taddl $4, %%esp" : "+a"(fn), "+c"(obj) : "g"(arg) : "edx", "memory", "cc");
  return (u8)fn;
}
extern "C" u32 THISCALL hand_48c6c0(u32 T, u32 A1, u32 cmd, u32 argp) {
  SEH_ENTER(0x667af8);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define LOG2(line, fmt) { u32 lg_ = G(u32, 0x700390); u32 o_ = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg_, 0x20))(lg_, 0x68d798, (line)); ((u32(*)(u32, u32))VSLOT(o_, 0x2c))(o_, (fmt)); }
#define RET(v) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return (v); }
  u32 (*cmpf)(u32, u32) = (u32(*)(u32, u32))G(u32, 0x676414);
  u32 (*ncmp)(u32, u32, u32) = (u32(*)(u32, u32, u32))G(u32, 0x676408);
  volatile u8 S0ac[0x80], S12c[0x80];
  volatile u32 it150[2], V20[4], V2c[3], r13c[2];
  u32 ebx = 0;
  u32 name = 0;
  if (cmpf(cmd, 0x68db3c) == 0) {  // @h1_48c6c0
    u32 v = 0;
    if (argp != 0) v = ((u32(*)(u32))G(u32, 0x6762d8))(argp);  // @h2_48c6c0
    u32 o = F32(T, 0xadc);
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x20c))(o, 0, v);  // @h3_48c6c0
    RET(1);
  }
  if (cmpf(cmd, 0x68da24) == 0) {  // @h4_48c6c0
    u32 g = G(u32, 0x70039c);
    u32 l1 = F32(g, 0x190f);
    u32 list = ((u32(THISCALL *)(u32))VSLOT(l1, 0x98))(l1);  // @h5_48c6c0
    if (list == 0) RET(0);  // @h6_48c6c0
    ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x4c))(list, (u32)(u32 *)it150);  // @h7_48c6c0
    u32 edi = ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x64))(list, (u32)(u32 *)it150);  // @h8_48c6c0
    while (edi != 0) {  // @h9_48c6c0
      float f = ((float(THISCALL *)(u32, u32))VSLOT(list, 0x9c))(list, edi);  // @h10_48c6c0
      g = G(u32, 0x70039c);
      u32 m = F32(g, 0x9b);
      u32 obj = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, F32(edi, 0));  // @h11_48c6c0
      ((u32(THISCALL *)(u32, u32))VSLOT(obj, 0x240))(obj, (u32)(u32 *)V20);  // @h12_48c6c0
      g = G(u32, 0x70039c);
      float fx = (float)(s32)F32(g, 0x6f), fy = (float)(s32)F32(g, 0x73);
      float t0 = fx * *(volatile float *)&V20[0];  // @h13_48c6c0
      *(volatile float *)&V20[0] = t0;
      float t1 = fy * *(volatile float *)&V20[1];  // @h14_48c6c0
      *(volatile float *)&V20[1] = t1;
      float t2 = fx * *(volatile float *)&V20[2];  // @h15_48c6c0
      *(volatile float *)&V20[2] = t2;
      float t3 = fy * *(volatile float *)&V20[3];  // @h16_48c6c0
      V2c[0] = 0; V2c[1] = 0; V2c[2] = 0;
      *(volatile float *)&V20[3] = t3;
      ((u32(THISCALL *)(u32, u32))VSLOT(obj, 0x84))(obj, (u32)(u32 *)V2c);  // @h17_48c6c0
      u32 p = ((u32(THISCALL *)(u32))VSLOT(obj, 0x24c))(obj);  // @h18_48c6c0
      if (p != 0) {  // @h19_48c6c0
        u32 sr = ((u32(THISCALL *)(u32, u32, u32))VSLOT(p, 0x1dc))(p, (u32)(u8 *)S12c, 1);  // @h20_48c6c0
        ebx |= 1;
        reg.state = 0;
        name = ext_4cc1d0_t0(sr);  // @h21_48c6c0
      } else {
        name = 0x68dd04;
      }
      u32 lg = G(u32, 0x700390);
      u32 lo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68d798, 0xd58);  // @h22_48c6c0
      u32 sr2 = ((u32(THISCALL *)(u32, u32, u32))VSLOT(obj, 0x1dc))(obj, (u32)(u8 *)S0ac, 1);  // @h23_48c6c0
      reg.state = 1;
      u32 str2 = ext_4cc1d0_t0(sr2);  // @h24_48c6c0
      u8 yes = w3c_call258(obj, VSLOT(obj, 0x258), str2);  // @h25_48c6c0
      u32 sel = yes ? 0x677b5au : 0x68dd0cu;
      ((u32(*)(u32, u32, u32, u32, double, double, double, double, double, u32))VSLOT(lo, 0x2c))(lo, 0x68dd18, sel, str2, (double)f, (double)*(volatile float *)&V20[0], (double)*(volatile float *)&V20[1], (double)*(volatile float *)&V20[2], (double)*(volatile float *)&V20[3], name);  // @h26_48c6c0
      ext_4cbec0_t0((u32)(u8 *)S0ac);  // @h27_48c6c0
      reg.state = -1;
      if (ebx & 1) {  // @h28_48c6c0
        ebx &= 0xfffffffe;
        ext_4cbec0_t0((u32)(u8 *)S12c);  // @h29_48c6c0
      }
      edi = ((u32(THISCALL *)(u32, u32))VSLOT(list, 0x64))(list, (u32)(u32 *)it150);  // @h30_48c6c0
    }
    RET(0);
  }
  if (ncmp(cmd, 0x68da3c, 10) == 0) {  // @h31_48c6c0
    if (argp != 0) {  // @h32_48c6c0
      u32 v = ((u32(*)(u32))G(u32, 0x6762d8))(argp);  // @h33_48c6c0
      if (v != 0) LOG2(0xd65, 0x68dd4c)  // @h34_48c6c0
      else LOG2(0xd67, 0x68dd7c)  // @h35_48c6c0
    } else LOG2(0xd6a, 0x68dd7c)  // @h36_48c6c0
    RET(0);
  }
  if (ncmp(cmd, 0x68da94, 10) == 0) {  // @h37_48c6c0
    u32 e = G(u32, 0x7003a4);
    if (e != 0) {  // @h38_48c6c0
      ((u32(THISCALL *)(u32))VSLOT(e, 0x70))(e);  // @h39_48c6c0
      e = G(u32, 0x7003a4);
      u32 esi = ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x74))(e, 1);  // @h40_48c6c0
      while (esi != 0) {  // @h41_48c6c0
        u32 lg = G(u32, 0x700390);
        u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68d798, 0xd82);  // @h42_48c6c0
        ((u32(*)(u32, u32, u32))VSLOT(o, 0x2c))(o, 0x677368, esi);  // @h43_48c6c0
        e = G(u32, 0x7003a4);
        esi = ((u32(THISCALL *)(u32, u32))VSLOT(e, 0x74))(e, 0);  // @h44_48c6c0
      }
    } else LOG2(0xd87, 0x68dd94)  // @h45_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68dad0) == 0) {  // @h46_48c6c0
    u32 e = G(u32, 0x7003ac);
    ((u32(THISCALL *)(u32))VSLOT(e, 0x10))(e);  // @h47_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68db04) == 0) {  // @h48_48c6c0
    u32 e = T + 0x1c61;
    ((u32(THISCALL *)(u32))VSLOT(e, 0x10))(e);  // @h49_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68db10) == 0) {  // @h50_48c6c0
    LOG2(0xd96, 0x68ddb0)
    RET(0);
  }
  if (cmpf(cmd, 0x68db14) == 0 || cmpf(cmd, 0x68db3c) == 0) {  // @h51_48c6c0
    u32 o = F32(T, 0xadc);
    ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0x20c))(o, 0, 0);  // @h52_48c6c0
    RET(0);
  }
  {
    u32 c10 = cmpf(cmd, 0x68db70);  // @h53_48c6c0
    if (c10 == 0 && argp != 0) {  // @h54_48c6c0
      u32 g = G(u32, 0x70039c);
      u32 l1 = F32(g, 0x190f);
      ((u32(THISCALL *)(u32, u32))VSLOT(l1, 0x90))(l1, argp);  // @h55_48c6c0
      RET(0);
    }
  }
  if (cmpf(cmd, 0x686794) == 0) {  // @h56_48c6c0
    u32 eb = T;
    u32 w = ((u32(THISCALL *)(u32))VSLOT(eb, 0xb0))(eb);  // @h57_48c6c0
    ext_4cbe80_t1((u32)(u8 *)S0ac, w);  // @h58_48c6c0
    reg.state = 2;
    ((u32(THISCALL *)(u32))VSLOT(eb, 0xa4))(eb);  // @h59_48c6c0
    u32 vt = F32(eb, 0);
    u32 s = ext_4cc1d0_t0((u32)(u8 *)S0ac);  // @h60_48c6c0
    ((u32(THISCALL *)(u32, u32))F32(vt, 0xa0))(eb, s);  // @h61_48c6c0
    ext_4cbec0_t0((u32)(u8 *)S0ac);  // @h62_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68db94) == 0) {  // @h63_48c6c0
    *(volatile u8 *)(T + 0xbac) = 1;  // @h64_48c6c0
    LOG2(0xdae, 0x68dddc)
    RET(0);
  }
  if (cmpf(cmd, 0x68ddf0) == 0) {  // @h65_48c6c0
    u32 g = G(u32, 0x70039c);
    ((u32(THISCALL *)(u32))VSLOT(g, 0x14))(g);  // @h66_48c6c0
    ((u32(STDCALL *)(u32))G(u32, 0x676374))(0);  // @h67_48c6c0
  }
  u32 pa = 0, pb = 0;
  if (cmpf(cmd, 0x68dba8) == 0) { pa = 0x68dba8; pb = 0xdba; }  // @h68_48c6c0
  else if (cmpf(cmd, 0x68dbc0) == 0) { pa = 0x68dbc0; pb = 0xdc2; }  // @h69_48c6c0
  if (pa != 0) {
    u32 g = G(u32, 0x70039c);
    u32 m = F32(g, 0x9b);
    r13c[0] = ((u32(THISCALL *)(u32))VSLOT(m, 0x138))(m);  // @h70_48c6c0
    r13c[1] = 0x68be98;
    u32 eb = ext_48aad0_w0((u32)(u32 *)r13c);  // @h71_48c6c0
    u32 o = F32(T, 0xadc);
    if (o != 0) {  // @h72_48c6c0
      u32 vt = F32(o, 0);
      g = G(u32, 0x70039c);
      m = F32(g, 0x9b);
      u32 ax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(m, 0x114))(m, pa, 0, 0x68d798, pb, 0) & 0xffff;  // @h73_48c6c0
      o = F32(T, 0xadc);
      ((u32(THISCALL *)(u32, u32, u32))F32(vt, 0x12c))(o, eb, ax);  // @h74_48c6c0
    } else {
      if (pa == 0x68dba8) LOG2(0xdbc, 0x68ddfc) else LOG2(0xdc4, 0x68de1c)  // @h75_48c6c0
    }
    RET(0);
  }
  if (cmpf(cmd, 0x68de38) == 0) {  // @h76_48c6c0
    LOG2(0xdd0, 0x68de44)
    RET(1);
  }
  if (cmpf(cmd, 0x68de60) == 0) {  // @h77_48c6c0
    u32 g = G(u32, 0x70039c);
    ext_496a40_w0(F32(F32(g, 0x9b), 8));  // @h78_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68de6c) == 0) {  // @h79_48c6c0
    u32 g = G(u32, 0x70039c);
    ext_496760_w0(F32(F32(g, 0x9b), 8));  // @h80_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68de7c) == 0) {  // @h81_48c6c0
    ext_49d480_w0(F32(T, 0xc8));  // @h82_48c6c0
    RET(0);
  }
  if (cmpf(cmd, 0x68de8c) == 0) {  // @h83_48c6c0
    ext_48f700_w0(T);  // @h84_48c6c0
    RET(0);
  }
  {
    u32 lg = G(u32, 0x700390);
    u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68d798, 0xdf1);  // @h85_48c6c0
    ((u32(*)(u32, u32, u32, u32))VSLOT(o, 0x2c))(o, 0x68dea0, cmd, argp);  // @h86_48c6c0
  }
  RET(0);
#undef F32
#undef LOG2
#undef RET
}
PCREG(48c6c0, hand_48c6c0);

extern "C" u32 FASTCALL ext_446ee0_f3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4e0d80_f3(u32, u32, u32) __asm__("ext_4e0d80");
extern "C" u32 FASTCALL ext_4de040_f3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4e29c0_f6(u32, u32, u32, u32, u32, u32) __asm__("ext_4e29c0");
extern "C" float FASTCALL ext_4e2bb0_f2(u32, u32) __asm__("ext_4e2bb0");
extern "C" u32 THISCALL ext_453a50_w1(u32, u32) __asm__("ext_453a50");
extern "C" u32 THISCALL hand_453bf0(u32 T) {
  SEH_ENTER(0x66639b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define FLT(a) (*(volatile float *)(a))
  volatile u32 R218[8], it23c[2], it248[2];
  volatile float V1c[3], Ve8[16], Vac[24], V26c[4], V64[3], V58[12], V278[4], V284[4], Vc4[4], V10c[16], V28[4], Vb8[4], V70[3], V260[4], VA[12], V16c[16];
  u32 pR = (u32)(u32 *)R218, pVe8 = (u32)(float *)Ve8, pVac = (u32)(float *)Vac, p1c = (u32)(float *)V1c;
  ext_4ccba0_t0(pR);  // @h1_453bf0
  reg.state = 0;
  ext_4db7c0_w1(F32(T, 8), p1c);  // @h2_453bf0
  u32 si = 0;
  if (V1c[0] > V1c[1]) si = 1;  // @h3_453bf0
  if (V1c[si] > V1c[2]) si = 2;  // @h4_453bf0
  V1c[si] = 5.0f;  // @h5_453bf0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(T, 0x80))(T, pVe8, pVac);  // @h6_453bf0
  ext_441970_f((u32)(float *)V26c, F32(T, 8) + 0x30, pVe8);  // @h7_453bf0
  ext_441940_f(pVac, (u32)(float *)V26c);  // @h8_453bf0
  u32 p228 = ((u32(THISCALL *)(u32))VSLOT(T, 0x244))(T);  // @h9_453bf0
  V64[0] = FLT(p228); V64[1] = FLT(p228 + 4); V64[2] = FLT(p228 + 8);  // @h10_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V64);  // @h11_453bf0
  {
    u32 sy = G(u32, 0x70039c);
    u32 m = F32(sy, 0x9b);
    u32 oa = F32(m, 0xadc);
    ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))VSLOT(oa, 0x2dc))(oa, 0, pR, pVe8, pVac, p1c, 0xffffffff, 0xffffffff, 0);  // @h12_453bf0
  }
  *(volatile u32 *)&V1c[si] = F32(T, 0x56);  // @h13_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x4c))(pR, (u32)(u32 *)it23c);  // @h14_453bf0
  u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x5c))(pR, (u32)(u32 *)it23c);  // @h15_453bf0
  while (it23c[0] != 0) {  // @h16_453bf0
    u32 sy = G(u32, 0x70039c);
    u32 m = F32(sy, 0x9b);
    u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, r);  // @h17_453bf0
    if (ob != 0) {  // @h18_453bf0
      u32 inf = F32(ob, 8);
      if (!(FLT(inf + 0x4c) > *(volatile float *)0x680a90)) ext_4dc630_w2(inf, 0x200, 0);  // @h19_453bf0
    }
    r = ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x5c))(pR, (u32)(u32 *)it23c);  // @h20_453bf0
  }
  ext_4cdb90_t0(pR);  // @h21_453bf0
  {
    u32 sy = G(u32, 0x70039c);
    u32 m = F32(sy, 0x9b);
    u32 oa = F32(m, 0xadc);
    ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))VSLOT(oa, 0x2dc))(oa, 2, pR, pVe8, pVac, p1c, 0x400000, 0xffffffff, 0);  // @h22_453bf0
  }
  for (u32 k = 0; k < 12; k++) *(volatile u32 *)((u32)(float *)V58 + 4 * k) = F32(p228, 4 * k);  // @h23_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58);  // @h24_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58 + 12);  // @h25_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58 + 24);  // @h26_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x84))(T, (u32)(float *)V58 + 36);  // @h27_453bf0
  ext_43e920_f((u32)(float *)V278, (u32)(float *)V58 + 12, (u32)(float *)V58);  // @h28_453bf0
  ext_43e920_f((u32)(float *)V284, (u32)(float *)V58 + 24, (u32)(float *)V58);  // @h29_453bf0
  ext_446ee0_f3((u32)(float *)Vc4, (u32)(float *)V284, (u32)(float *)V278);  // @h30_453bf0
  ext_4e0d80_f3((u32)(float *)Vc4, 0, 0x3f800000);  // @h31_453bf0
  ext_4de040_f3((u32)(float *)V10c, (u32)(float *)Vc4, 0);  // @h32_453bf0
  u32 edi = F32(T, 0x52);  // @h33_453bf0
  F32(T, 0x52) = 0;  // @h34_453bf0
  u32 hnd;
  {
    u32 sy = G(u32, 0x70039c);
    u32 m = F32(sy, 0x9b);
    hnd = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x4c))(m, T);  // @h35_453bf0
  }
  float f250 = ((float(THISCALL *)(u32))VSLOT(T, 0x214))(T);  // @h36_453bf0
  ext_453a50_w1(T, (u32)(float *)V28);  // @h37_453bf0
  ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x4c))(pR, (u32)(u32 *)it248);  // @h38_453bf0
  u32 edx = ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x5c))(pR, (u32)(u32 *)it248);  // @h39_453bf0
  u32 elem = edx;
  if (it248[0] != 0) {
    do {  // @h40_453bf0
      u32 sy = G(u32, 0x70039c);
      u32 m = F32(sy, 0x9b);
      u32 ob = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, elem);  // @h41_453bf0
      if (ob == 0) goto nextl;  // @h42_453bf0
      if (F32(F32(ob, 0xc), 0x23) != 0x200015) goto nextl;  // @h43_453bf0
      if (ob == T) goto nextl;  // @h44_453bf0
      ext_453a50_w1(ob, (u32)(float *)Vb8);  // @h45_453bf0
      {
        float t0 = V28[1] * Vb8[1];  // @h46_453bf0
        float t1 = V28[0] * Vb8[0];
        t1 = t1 + t0;  // @h47_453bf0
        float t2 = V28[2] * Vb8[2];
        t1 = t1 + t2;  // @h48_453bf0
        if (t1 > *(volatile float *)0x681dd0) goto nextl;  // @h49_453bf0
      }
      {
        u32 p230 = ((u32(THISCALL *)(u32))VSLOT(ob, 0x244))(ob);  // @h50_453bf0
        V70[0] = FLT(p230); V70[1] = FLT(p230 + 4); V70[2] = FLT(p230 + 8);  // @h51_453bf0
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)V70);  // @h52_453bf0
        ext_43e920_f((u32)(float *)V260, (u32)(float *)V70, (u32)(float *)V64);  // @h53_453bf0
        float u0 = V260[1] * V28[1];  // @h54_453bf0
        float u1 = V260[0] * V28[0];
        u1 = u1 + u0;  // @h55_453bf0
        float u2 = V260[2] * V28[2];
        u1 = u1 + u2;  // @h56_453bf0
        float ab = (float)__builtin_fabs((double)u1);  // @h57_453bf0
        if (ab > *(volatile float *)0x681dc8) goto nextl;  // @h58_453bf0
        u32 a = ((u32(THISCALL *)(u32))VSLOT(ob, 0x20))(ob);  // @h59_453bf0
        u32 b = ((u32(THISCALL *)(u32))VSLOT(T, 0x20))(T);  // @h60_453bf0
        if (a == b) {  // @h61_453bf0
          u32 lg = G(u32, 0x700390);
          u32 lo = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x681d70, 0x271);  // @h62_453bf0
          u32 n1 = F32(ob, 4); if (n1 == 0) n1 = 0x67c8e8;  // @h63_453bf0
          u32 x = ((u32(THISCALL *)(u32))VSLOT(ob, 0x20))(ob);  // @h64_453bf0
          u32 xn = F32(x, 4); if (xn == 0) xn = 0x67c8e8;  // @h65_453bf0
          u32 tn = F32(T, 4); if (tn == 0) tn = 0x67c8e8;  // @h66_453bf0
          u32 y = ((u32(THISCALL *)(u32))VSLOT(T, 0x20))(T);  // @h67_453bf0
          u32 yn = F32(y, 4); if (yn == 0) yn = 0x67c8e8;  // @h68_453bf0
          ((u32(*)(u32, u32, u32, u32, u32, u32))VSLOT(lo, 0x2c))(lo, 0x681d98, yn, tn, xn, n1);  // @h69_453bf0
          goto nextl;
        }
        float f22c = ((float(THISCALL *)(u32))VSLOT(ob, 0x214))(ob);  // @h70_453bf0
        float sc = *(volatile float *)0x681dcc;
        float m0 = f250 * sc;  // @h71_453bf0
        if (f22c > m0) goto nextl;  // @h72_453bf0
        float m1 = f22c * sc;  // @h73_453bf0
        if (f250 > m1) goto nextl;  // @h74_453bf0
        for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 36 + 4 * k) = F32(p230, 4 * k);  // @h75_453bf0
        for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 24 + 4 * k) = F32(p230, 12 + 4 * k);  // @h76_453bf0
        for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 12 + 4 * k) = F32(p230, 24 + 4 * k);  // @h77_453bf0
        for (u32 k = 0; k < 3; k++) *(volatile u32 *)((u32)(float *)VA + 0 + 4 * k) = F32(p230, 36 + 4 * k);  // @h78_453bf0
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA);  // @h79_453bf0
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA + 12);  // @h80_453bf0
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA + 24);  // @h81_453bf0
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x84))(ob, (u32)(float *)VA + 36);  // @h82_453bf0
        u32 es = ext_4e29c0_f6((u32)(float *)V16c, (u32)(float *)VA, 4, (u32)(float *)V58, 4, (u32)(float *)Vc4);  // @h83_453bf0
        float g22c = ext_4e2bb0_f2((u32)(float *)V58, 4);  // @h84_453bf0
        float g230 = ext_4e2bb0_f2((u32)(float *)VA, 4);  // @h85_453bf0
        float g254 = ext_4e2bb0_f2((u32)(float *)V16c, es);  // @h86_453bf0
        float mn = (g230 < g22c) ? g230 : g22c;  // @h87_453bf0
        mn = mn * *(volatile float *)0x681dc4;  // @h88_453bf0
        if (mn > g254) goto nextl;  // @h89_453bf0
        ((u32(THISCALL *)(u32, u32))VSLOT(T, 0x220))(T, elem);  // @h90_453bf0
        int found = 0;
        if (edi != 0) {  // @h91_453bf0
          ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x4c))(edi, (u32)(u32 *)it23c);  // @h92_453bf0
          u32 rr = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x5c))(edi, (u32)(u32 *)it23c);  // @h93_453bf0
          while (it23c[0] != 0) {  // @h94_453bf0
            if (elem == rr) {  // @h95_453bf0
              ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x44))(edi, (u32)(u32 *)it23c);  // @h96_453bf0
              found = 1;
              break;
            }
            rr = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x5c))(edi, (u32)(u32 *)it23c);  // @h97_453bf0
          }
        }
        if (found) goto nextl;
        ((u32(THISCALL *)(u32, u32))VSLOT(ob, 0x220))(ob, hnd);  // @h98_453bf0
      }
    nextl:
      elem = ((u32(THISCALL *)(u32, u32))VSLOT(pR, 0x5c))(pR, (u32)(u32 *)it248);  // @h99_453bf0
    } while (it248[0] != 0);  // @h100_453bf0
  }
  if (edi != 0) {  // @h101_453bf0
    ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x4c))(edi, (u32)(u32 *)it248);  // @h102_453bf0
    u32 rr = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x5c))(edi, (u32)(u32 *)it248);  // @h103_453bf0
    while (it248[0] != 0) {  // @h104_453bf0
      u32 sy = G(u32, 0x70039c);
      u32 m = F32(sy, 0x9b);
      u32 x = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x58))(m, rr);  // @h105_453bf0
      if (x != 0) ((u32(THISCALL *)(u32, u32))VSLOT(x, 0x224))(x, hnd);  // @h106_453bf0
      rr = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x5c))(edi, (u32)(u32 *)it248);  // @h107_453bf0
    }
    ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0))(edi, 1);  // @h108_453bf0
  }
  u32 rv_ = ext_4ccf60_t0(pR);  // @h109_453bf0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return rv_;
#undef F32
#undef FLT
}
PCREG(453bf0, hand_453bf0);

extern "C" u32 THISCALL ext_600420_w1(u32, u32) __asm__("ext_600420");
extern "C" u32 STDCALL ext_634123_s5(u32, u32, u32, u32, u32) __asm__("ext_634123");
extern "C" u32 THISCALL ext_5fe4e0_w0(u32) __asm__("ext_5fe4e0");
extern "C" u32 THISCALL ext_5fe080_w1(u32, u32) __asm__("ext_5fe080");
extern "C" u32 THISCALL ext_5fdd20_w1(u32, u32) __asm__("ext_5fdd20");
static inline u32 w3c_call602(u32 arg) {
  u32 res;
  __asm__ volatile("pushl %1\n\tcall ext_602d30\n\tmovl %%eax, %%ecx\n\tcall ext_602ff0" : "=a"(res) : "g"(arg) : "ecx", "edx", "memory", "cc");
  return res;
}
extern "C" u32 THISCALL hand_5ff2b0(u32 T, u32 S, u32 A2, u32 A3) {
  SEH_ENTER(0x66d7c3);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define FP() { u32 fp_ = G(u32, 0x7003b0); if (fp_) ((void (*)(void))fp_)(); else __asm__ volatile("int3"); }
#define LOGERR(line, tail) { u32 lg_ = G(u32, 0x700390); u32 o_ = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg_, 0x20))(lg_, 0x6b9420, (line)); ((u32(*)(u32, u32, u32))VSLOT(o_, 0x2c))(o_, 0x69c6b0, (tail)); }
  volatile u32 loc_c8 = 0xcccccccc, loc_94 = 0xcccccccc, loc_bc = 0xcccccccc, loc_a0 = 0xcccccccc, loc_b4 = 0xcccccccc;
  volatile float loc_b0;
  u8 buf90[0x40];
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x74))(S, 0);  // @h27_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, (u32)&loc_c8);  // @h28_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x64))(S, (u32)&loc_b0);  // @h29_5ff2b0
  if (!(loc_b0 == *(volatile float *)0x678858)) {  // @h30_5ff2b0
    u32 lg = ext_5fa630_v();
    double dd = (double)loc_b0;
    ((u32(*)(u32, u32, u32, double, double))VSLOT(lg, 0x14))(lg, (u32)buf90, 0x6b95cc, dd, *(volatile double *)0x678610);  // @h31_5ff2b0
    FP()  // @h32_5ff2b0
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x8);  // @h1_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0xc);  // @h2_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x54))(S, T + 0x10);  // @h3_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x54))(S, T + 0x12);  // @h4_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x54))(S, T + 0x14);  // @h5_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x54))(S, T + 0x16);  // @h6_5ff2b0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x70))(S, T + 0x18, 0x10);  // @h7_5ff2b0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x70))(S, T + 0x28, 0x10);  // @h8_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x38);  // @h9_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x3c);  // @h10_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x40);  // @h11_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x44);  // @h12_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x48);  // @h13_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x4c);  // @h14_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x68);  // @h15_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x6c);  // @h16_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x70);  // @h17_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x74);  // @h18_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x78);  // @h19_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x7c);  // @h20_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x80);  // @h21_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x84);  // @h22_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x88);  // @h23_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x8c);  // @h24_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x90);  // @h25_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x94);  // @h26_5ff2b0

  u32 sz = F32(T, 0x94);
  u32 bl = ext_41e290_cdecl1(sz);  // @h33_5ff2b0
  F32(T, 0x98) = bl;  // @h34_5ff2b0
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(S, 0x70))(S, bl, sz);  // @h35_5ff2b0
  {
    u32 c = F32(T, 0x74) + F32(T, 0x98);
    F32(T, 0xb4) = F32(c, 0); F32(T, 0xb8) = F32(c, 4); F32(T, 0xbc) = c + 8;  // @h36_5ff2b0
    c = F32(T, 0x78) + F32(T, 0x98);
    F32(T, 0xc0) = F32(c, 0); F32(T, 0xc4) = F32(c, 4); F32(T, 0xc8) = c + 8;  // @h37_5ff2b0
    c = F32(T, 0x98) + F32(T, 0x7c);
    F32(T, 0xa0) = F32(c, 0); F32(T, 0xa8) = F32(c, 4); F32(T, 0xac) = c + 8;  // @h38_5ff2b0
    F32(T, 0xb0) = c + (F32(T, 0xa8) + 2) * 4;  // @h39_5ff2b0
    c = F32(T, 0x98);
    u32 e1 = F32(c, F32(T, 0x90));
    u32 p1 = F32(T, 0x90) + c + 4;
    F32(T, 0x54) = p1; F32(T, 0x58) = p1 + e1;  // @h40_5ff2b0
    c = F32(T, 0x98);
    u32 e2 = F32(c, F32(T, 0x8c));
    u32 p2 = F32(T, 0x8c) + c + 4;
    F32(T, 0x60) = p2; F32(T, 0x64) = p2 + e2;  // @h41_5ff2b0
  }
  ext_600420_w1(T + 0xcc, F32(T, 0x98) + F32(T, 0x70));  // @h42_5ff2b0
  {
    u32 c = F32(T, 0x98) + F32(T, 0x6c);
    F32(T, 0x104) = F32(c, 0); F32(T, 0x108) = c + 4;  // @h43_5ff2b0
  }
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x12e);  // @h44_5ff2b0
  ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, T + 0x12a);  // @h45_5ff2b0
  u32 n1 = F32(T, 0x12e);
  if (n1 != 0) {  // @h46_5ff2b0
    unsigned long long pr = (unsigned long long)n1 * 0x1c;
    u32 bytes = (pr >> 32) ? 0xffffffffu : (u32)pr;
    u32 b4 = bytes + 4; if (b4 < bytes) b4 = 0xffffffffu;
    u32 raw = ext_41e290_cdecl1(b4);  // @h47_5ff2b0
    reg.state = 0;
    u32 ev = 0;
    if (raw != 0) {  // @h48_5ff2b0
      F32(raw, 0) = n1;
      ev = raw + 4;
      ext_634123_s5(ev, 0x1c, n1, 0x5f9720, 0x5f98d0);  // @h49_5ff2b0
    }
    F32(T, 0x132) = ev;  // @h50_5ff2b0
    reg.state = -1;
    if (F32(T, 0x12e) != 0) {  // @h51_5ff2b0
      u32 off = 0;
      for (u32 i = 0; i < F32(T, 0x12e); i++, off += 0x1c) {  // @h52_5ff2b0
        ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, F32(T, 0x132) + off + 0x18);  // @h53_5ff2b0
        ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, (u32)&loc_bc);  // @h54_5ff2b0
        u32 cnt = loc_bc;
        for (u32 j = 0; j < cnt; j++) {  // @h201_5ff2b0
          ((u32(THISCALL *)(u32, u32))VSLOT(S, 0x5c))(S, (u32)&loc_94);  // @h202_5ff2b0
          u32 V = loc_94;
          u32 eax;
          u32 d;
          if (!(F32(T, 0xa8) != 0 && F32(T, 0xa0) <= (V & 0xffff))) goto Lb;  // @h203_5ff2b0
          d = (u16)((u16)V - (u16)F32(T, 0xa0));
          if (d < F32(T, 0xa8)) goto Lc;  // @h204_5ff2b0
          LOGERR(0x137, 0x6b9474)  // @h205_5ff2b0
          FP()  // @h206_5ff2b0
          goto Ld;
        Lb: {
            u32 h = F32(T, 0x9c);
            if (h != 0) ((u32(THISCALL *)(u32, u32))ext_5ffb00_t1)(h, V);  // @h207_5ff2b0
            else FP()  // @h208_5ff2b0
          }
        Ld:
          V = loc_94;
        Lc:
          if (!(F32(T, 0xa8) != 0 && F32(T, 0xa0) <= (V & 0xffff))) goto Le;  // @h209_5ff2b0
          d = (u16)((u16)V - (u16)F32(T, 0xa0));
          if (d >= F32(T, 0xa8)) goto Lf;  // @h210_5ff2b0
          eax = F32(F32(T, 0xac), d * 4) + F32(T, 0xb0);  // @h211_5ff2b0
          loc_b4 = eax;
          goto Lg;
        Lf:
          LOGERR(0x137, 0x6b9474)  // @h212_5ff2b0
          FP()  // @h213_5ff2b0
          eax = loc_b4;
          goto Lg;
        Le: {
            u32 h = F32(T, 0x9c);
            if (h != 0) {  // @h214_5ff2b0
              eax = ext_5ffb00_t1(h, V);  // @h215_5ff2b0
              goto Lg;
            }
            FP()  // @h216_5ff2b0
            eax = loc_a0;
            goto Lh;
          }
        Lg:
          loc_a0 = eax;  // @h217_5ff2b0
        Lh: {
            u32 w = w3c_call602(eax);  // @h218_5ff2b0
            if (w == 0) FP()  // @h219_5ff2b0
            u32 ev2 = F32(T, 0x132) + off;
            if (!(F32(ev2, 8) < F32(ev2, 4))) {  // @h220_5ff2b0
              u32 cap = F32(ev2, 4);
              u32 oldb = F32(ev2, 0);
              u32 ncap = cap * 2;
              unsigned long long pr2 = (unsigned long long)ncap * 4;
              u32 nb = ext_41e290_cdecl1((pr2 >> 32) ? 0xffffffffu : (u32)pr2);  // @h221_5ff2b0
              F32(ev2, 0) = nb;
              for (u32 k = 0; k < F32(ev2, 4); k++) F32(nb, k * 4) = F32(oldb, k * 4);  // @h222_5ff2b0
              ext_41e2c0_c1(oldb);  // @h223_5ff2b0
              F32(ev2, 4) = ncap;  // @h224_5ff2b0
            }
            F32(F32(ev2, 0), F32(ev2, 8) * 4) = w;  // @h225_5ff2b0
            F32(ev2, 8) = F32(ev2, 8) + 1;  // @h226_5ff2b0
          }
        }
      }
    }
  }
  if ((u8)A3 != 0) {  // @h227_5ff2b0
    u32 ok = ext_5fe4e0_w0(T) & 0xff;  // @h228_5ff2b0
    if (ok == 0) *(volatile u8 *)A2 = 1;  // @h229_5ff2b0
  }
  ext_5fe080_w1(T, T + 0x118);  // @h230_5ff2b0
  u32 rv_ = ext_5fdd20_w1(T, T + 0x121);  // @h231_5ff2b0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return rv_;
#undef F32
#undef F16
#undef FP
#undef LOGERR
}
PCREG(5ff2b0, hand_5ff2b0);

extern "C" u32 THISCALL ext_4e1b60_x52e(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_531220_x52e(u32) __asm__("ext_531220");
extern "C" u32 THISCALL ext_52b0c0_x52e(u32) __asm__("ext_52b0c0");
extern "C" u32 THISCALL ext_52b080_x52e(u32) __asm__("ext_52b080");
extern "C" u32 THISCALL ext_530ca0_x52e(u32, u32, u32, u32) __asm__("ext_530ca0");
extern "C" u32 THISCALL ext_530130_x52e(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_530130");
extern "C" u32 THISCALL ext_52f2b0_x52e(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_52f2b0");
extern "C" u32 THISCALL ext_52d1c0_x52e(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_52d1c0");
extern "C" u32 THISCALL hand_52e830(u32 T, u32 A8, u32 A12, u32 A16, u32 A20, u32 A24, u32 C, u32 D) {
  SEH_ENTER(0x66a6e2);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
#define F16(base, off) (*(volatile u16 *)((base) + (off)))
#define F8(base, off) (*(volatile u8 *)((base) + (off)))
#define FL(a) (*(volatile float *)(a))
#define EXIT0() do { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return 0; } while (0)
#define TIMING() do { \
    u32 p44_ = F32(C, 0x44); \
    if (p44_ != 0 && F8(p44_, 0x10) != 0) { \
      u32 sy_ = G(u32, 0x70039c); \
      u32 e_ = ((u32(THISCALL *)(u32, u32, u32))VSLOT(sy_, 0x1c8))(sy_, 0x6a0ea8, 0x3d); \
      u32 d_ = e_ - F32(p44_, 0); \
      if (d_ > F32(p44_, 4)) F32(p44_, 0) = e_; \
    } } while (0)
  volatile float L[9];
  volatile u32 Q[0x1c];
  volatile u32 O118[3];
  volatile u32 l_a8;
  volatile float l_ac;
  for (int z = 0; z < 9; z++) ((volatile u32 *)L)[z] = 0xcccccccc;
  for (int z = 0; z < 0x1c; z++) Q[z] = 0xcccccccc;
  for (int z = 0; z < 3; z++) O118[z] = 0xcccccccc;
  l_a8 = 0xcccccccc; *(volatile u32 *)&l_ac = 0xcccccccc;
  const u32 pa8 = (u32)(unsigned long)&l_a8, pac = (u32)(unsigned long)&l_ac;
  const u32 pL34 = (u32)(unsigned long)&L[0], pL28 = (u32)(unsigned long)&L[3], pL1c = (u32)(unsigned long)&L[6];
  const u32 pQ = (u32)(unsigned long)&Q[0], pO118 = (u32)(unsigned long)&O118[0];
  auto stage = [&](u32 cnt) -> bool {
    u32 p = F32(C, 0x44);
    if (p == 0) return true;
    if (F8(p, 0x10) == 0) return true;
    if (F8(C, 0x48) != 0) return false;
    return cnt == F32(C, 0x49);
  };
  G(u32, 0x701b60) = 0;  // @h1_52e830
  F32(C, 0x4d) = 0;  // @h2_52e830
  if (F8(C, 0x48) != 0) {  // @h3_52e830
    F8(C, 0x48) = 0;
    F32(C, 0x49) = 0;  // @h4_52e830
  }
  F32(C, 0x4d) = 1;  // @h5_52e830
  const u32 pFB = C + 0xfb;
  if (stage(0)) {  // @h6_52e830
    F32(C, 0xe3) = F32(A12, 0);  // @h7_52e830
    F32(C, 0xe7) = F32(A12, 4);  // @h8_52e830
    F32(C, 0xeb) = F32(A12, 8);  // @h9_52e830
    F32(C, 0xef) = F32(A8, 0);  // @h10_52e830
    F32(C, 0xf3) = F32(A8, 4);  // @h11_52e830
    F32(C, 0xf7) = F32(A8, 8);  // @h12_52e830
    float c1 = FL(0x67da24);
    FL(C + 0xe7) = FL(C + 0xe7) + c1;  // @h13_52e830
    FL(C + 0xf3) = FL(C + 0xf3) + c1;  // @h14_52e830
    ext_531220_x52e(T);  // @h15_52e830
    if ((ext_52b0c0_x52e(C) & 0xff) != 0) EXIT0();  // @h16_52e830
  }
  {
    u32 cnt = F32(C, 0x4d);
    F32(C, 0x4d) = cnt + 1;  // @h17_52e830
    if (stage(cnt)) {  // @h18_52e830
      u32 n = F16(T, 0x96);
      u32 p = F32(T, 0x98);
      if (n != 0) {  // @h19_52e830
        u32 e = n;
        float ref = FL(0x68af2c);
        do {
          float v = FL(p + 0xa);
          if (!(v == ref)) {  // @h20_52e830
            F32(p, 0xa) = 0x47c35000;  // @h21_52e830
            F16(p, 0) = 0;  // @h22_52e830
            F8(p, 0x14) = 0;  // @h23_52e830
            F32(p, 0x10) = 0;  // @h24_52e830
            F16(p, 0xe) = 0;  // @h25_52e830
          }
          p += 0x15;
          e--;
        } while (e != 0);
      }
      F16(T, 0x96) = 2;  // @h26_52e830
      if ((ext_52b0c0_x52e(C) & 0xff) != 0) EXIT0();  // @h27_52e830
    }
  }
  {
    u32 cnt = F32(C, 0x4d);
    F32(C, 0x4d) = cnt + 1;  // @h28_52e830
    if (stage(cnt)) {  // @h29_52e830
      if (T != 0) {  // @h30_52e830
        O118[0] = T;
        O118[1] = T + 0x96;  // @h31_52e830
        O118[2] = 0x40;  // @h32_52e830
      }
      if (ext_530ca0_x52e(pO118, pFB, C + 0xe3, C + 0x107) == 0) {  // @h33_52e830
        ext_52b080_x52e(C);  // @h34_52e830
        EXIT0();
      }
      u32 r = ext_530ca0_x52e(pO118, C + 0x101, C + 0xef, C + 0x108);  // @h35_52e830
      if (r == 0) {  // @h36_52e830
        ext_52b080_x52e(C);  // @h37_52e830
        EXIT0();
      }
      if ((ext_52b0c0_x52e(C) & 0xff) != 0) EXIT0();  // @h38_52e830
    }
  }
  {
    u32 cnt = F32(C, 0x4d);
    F32(C, 0x4d) = cnt + 1;  // @h39_52e830
    if (stage(cnt)) {  // @h40_52e830
      u32 a = F32(T, 0x38) - F32(T, 0x4c);
      u32 ax = ext_530130_x52e(T, pFB, C + 0x101, A16, a, 1, D) & 0xffff;  // @h41_52e830
      if (ax == 0xffff || ax == 0) {  // @h42_52e830
        G(u32, 0x701b60) = 0xffff;  // @h43_52e830
        ext_52b080_x52e(C);  // @h44_52e830
        EXIT0();
      }
      if ((ext_52b0c0_x52e(C) & 0xff) != 0) EXIT0();  // @h45_52e830
    }
  }
  if ((s32)F32(T, 0x4c) > 1) {  // @h46_52e830
    s32 k = 1;
    do {
      u32 cnt = F32(C, 0x4d);
      F32(C, 0x4d) = cnt + 1;  // @h47_52e830
      if (stage(cnt)) {  // @h48_52e830
        u32 a = F32(T, 0x38) - F32(T, 0x4c) + (u32)k;  // @h49_52e830
        u32 ax = ext_530130_x52e(T, pFB, C + 0x101, A16, a, 2, D) & 0xffff;  // @h50_52e830
        if (ax == 0xffff || ax == 0) {  // @h51_52e830
          G(u32, 0x701b60) = 0xffff;  // @h52_52e830
          TIMING();  // @h53_52e830
          F8(C, 0x48) = 1;  // @h54_52e830
          EXIT0();
        }
        if ((ext_52b0c0_x52e(C) & 0xff) != 0) EXIT0();  // @h55_52e830
      }
      k++;
    } while (k < (s32)F32(T, 0x4c));  // @h56_52e830
  }
  {
    u32 cnt = F32(C, 0x4d);
    F32(C, 0x4d) = cnt + 1;  // @h57_52e830
    if (stage(cnt)) {  // @h58_52e830
      u32 ax = ext_52f2b0_x52e(T, pFB, C + 0x101, A16, 2, C + 0x51, 0) & 0xffff;  // @h59_52e830
      F16(C, 0x109) = (u16)ax;  // @h60_52e830
      if (F8(C, 0x99) == 0) EXIT0();  // @h61_52e830
      if (ax == 0xffff || ax == 0) {  // @h62_52e830
        ext_52b080_x52e(C);  // @h63_52e830
        EXIT0();
      }
      if ((ext_52b0c0_x52e(C) & 0xff) != 0) EXIT0();  // @h64_52e830
    }
  }
  u32 cur = F16(C, 0x109);
  u32 cntB = 0, ebxc = 0;
  if ((cur & 0xffff) != 0) {  // @h65_52e830
    u8 ch = F8(T, 5);
    u32 ax = cur & 0xffff;
    u32 es = 0;
    do {
      es++;
      u32 rec = (ax & 0xffff) * 0x15 + F32(T, 0x98);
      u8 cl = F8(rec, 0x14);
      u32 edx = F16(rec, 0xe);
      ax = edx;
      cl &= 1;
      if (cl != 0) ax = F16(T, (edx << 5) + 0x9e);  // @h66_52e830
      if (ch != 0 && cl != 0) ebxc++;  // @h67_52e830
    } while ((ax & 0xffff) != 0);
    cntB = es;
  }
  u32 b4 = cntB;
  if (F8(C, 0x107) == 0 && (u8)A24 == 0) b4 = cntB + 1;  // @h68_52e830
  if (F8(C, 0x108) == 0 && (u8)A20 == 0) b4 = b4 + 1;  // @h69_52e830
  u32 raw = ext_41e290_cdecl1((u32)0x18);  // @h70_52e830
  reg.state = 0;
  u32 N = 0;
  if (raw != 0) N = ext_476dc0_t1(raw, b4 + ebxc);  // @h71_52e830
  reg.state = -1;
  l_a8 = 0;
  l_ac = 0;  // @h72_52e830
  if (F8(C, 0x108) == 0 && (u8)A20 == 0) {  // @h73_52e830
    F32(pL1c, 0) = F32(C, 0xef);  // @h74_52e830
    F32(pL1c, 4) = F32(C, 0xf3);  // @h75_52e830
    F32(pL1c, 8) = F32(C, 0xf7);  // @h76_52e830
    ext_52d1c0_x52e(T, N, pa8, pac, pL28, pL1c, b4, D, 0);  // @h77_52e830
  }
  u32 cl = 0;
  s32 i = 0;
  if ((s32)cntB > 0) {  // @h78_52e830
    const u32 last = cntB - 1;
    const float h = FL(0x67a6ac);
    do {
      u32 flag = cl & 1;
      u32 eax = cur & 0xffff;
      if (flag != 0) eax = F16(T, (eax << 5) + 0x9e);  // @h79_52e830
      u32 rec = F32(T, 0x98) + (eax & 0xffff) * 0x15;
      float d0 = (float)(s32)F16(rec, 4) + h;  // @h80_52e830
      float d1 = (float)(s32)F16(rec, 6) + h;  // @h81_52e830
      float d2 = (float)(s32)F16(rec, 8) + h;  // @h82_52e830
      ext_43e920_f(pL34, T + 0x12, T + 6);  // @h83_52e830
      {
        float f = FL(pL34 + 0) * d0;
        f = f / (float)(s32)F32(T, 0x3c);
        f = f + FL(T + 6);  // @h84_52e830
        FL(pL1c + 0) = f;
        f = FL(pL34 + 8) * d1;
        f = f / (float)(s32)F32(T, 0x40);
        f = f + FL(T + 0xe);  // @h85_52e830
        FL(pL1c + 8) = f;
        f = FL(pL34 + 4) * d2;
        f = f / (float)(s32)F32(T, 0x44);
        f = f + FL(T + 0xa);
        f = f + FL(0x67da24);  // @h86_52e830
        FL(pL1c + 4) = f;
      }
      if (i == 0 && F8(C, 0x108) != 0 && (u8)A20 == 0) {  // @h87_52e830
        F32(pL1c, 0) = F32(C, 0xef);  // @h88_52e830
        F32(pL1c, 8) = F32(C, 0xf7);  // @h89_52e830
      }
      if ((u32)i == last && F8(C, 0x107) != 0 && (u8)A24 == 0) {  // @h90_52e830
        F32(pL1c, 0) = F32(C, 0xe3);  // @h91_52e830
        F32(pL1c, 8) = F32(C, 0xeb);  // @h92_52e830
      }
      if (flag != 0) {
        u32 w = T + ((cur & 0xffff) << 5) + 0x9e;
        if (F8(T, 5) != 0) {  // @h93_52e830
          F32(pL1c, 0) = F32(w, 4);  // @h94_52e830
          float y = FL(w + 8);
          F32(pL1c, 8) = F32(w, 0xc);  // @h95_52e830
          FL(pL1c + 4) = y + FL(0x680a80);  // @h96_52e830
          ext_52d1c0_x52e(T, N, pa8, pac, pL28, pL1c, b4, D, w);  // @h97_52e830
          F32(pL1c, 0) = F32(w, 0x10);  // @h98_52e830
          float y2 = FL(w + 0x14);
          F32(pL1c, 8) = F32(w, 0x18);  // @h99_52e830
          FL(pL1c + 4) = y2 + FL(0x680a80);  // @h100_52e830
          ext_52d1c0_x52e(T, N, pa8, pac, pL28, pL1c, b4, D, w);  // @h101_52e830
        } else {
          u32 lg = G(u32, 0x700390);
          u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x6a1438, 0x46e);  // @h102_52e830
          ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x6a0fc0);  // @h103_52e830
          lg = G(u32, 0x700390);
          o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x6a1438, 0x46f);  // @h104_52e830
          ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x6a1008);  // @h105_52e830
        }
      } else {
        u32 cc = l_a8;
        if (cc != 0) {  // @h106_52e830
          float dd = ext_4e0870_f(pL28, pL1c);  // @h107_52e830
          l_ac = dd + FL(pac);  // @h108_52e830
        }
        u32 idx = l_a8;
        F32(pL28, 0) = F32(pL1c, 0);  // @h109_52e830
        F32(pL28, 4) = F32(pL1c, 4);
        F32(pL28, 8) = F32(pL1c, 8);  // @h110_52e830
        u32 pts = F32(N, 0xc);
        u32 eo = idx << 4;
        F32(pts, eo) = F32(pac, 0);  // @h111_52e830
        F32(F32(N, 0x10), idx * 4) = 0;  // @h112_52e830
        F32(F32(N, 0x14), idx * 4) = 0;  // @h113_52e830
        idx++;
        pts = F32(N, 0xc);
        l_a8 = idx;  // @h114_52e830
        F32(pts, eo + 4) = F32(pL1c, 0);  // @h115_52e830
        F32(pts, eo + 8) = F32(pL1c, 4);  // @h116_52e830
        F32(pts, eo + 0xc) = F32(pL1c, 8);  // @h117_52e830
      }
      cur = F16(rec, 0xe);
      cl = F8(rec, 0x14);
      i++;
    } while (i < (s32)cntB);  // @h118_52e830
  }
  if (F8(C, 0x107) == 0 && (u8)A24 == 0) {  // @h119_52e830
    F32(pL34, 0) = F32(C, 0xe3);  // @h120_52e830
    F32(pL34, 4) = F32(C, 0xe7);
    F32(pL34, 8) = F32(C, 0xeb);  // @h121_52e830
    ext_4e1b60_x52e(pQ);  // @h122_52e830
    F32(pQ, 0) = F32(pL28, 0);  // @h123_52e830
    F32(pQ, 4) = F32(pL28, 4);
    F32(pQ, 8) = F32(pL28, 8);  // @h124_52e830
    ext_43e920_f(pQ + 0xc, pL34, pL28);  // @h125_52e830
    u32 sy = G(u32, 0x70039c);
    u32 rc = F32(F32(sy, 0x9b), 0xadc);
    u32 hit = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))VSLOT(rc, 0x2e0))(rc, pQ, 0, 0x21, 0x200000, 1, 0) & 0xff;  // @h126_52e830
    if (hit != 0) {  // @h127_52e830
      if (N != 0) {  // @h128_52e830
        u32 a = F32(N, 0xc);
        if (a != 0) ext_41e2c0_c1(a);  // @h129_52e830
        a = F32(N, 0x10);
        if (a != 0) ext_634273_cdecl2(a, 4);  // @h130_52e830
        a = F32(N, 0x14);
        if (a != 0) ext_634273_cdecl2(a, 4);  // @h131_52e830
        ext_634273_cdecl2(N, 0x18);  // @h132_52e830
      }
      TIMING();  // @h133_52e830
      F8(C, 0x48) = 1;  // @h134_52e830
      EXIT0();
    }
    ext_52d1c0_x52e(T, N, pa8, pac, pL28, pL34, b4, D, 0);  // @h135_52e830
  }
  F32(N, 8) = l_a8;  // @h136_52e830
  F32(N, 4) = F32(pac, 0);  // @h137_52e830
  TIMING();  // @h138_52e830
  F8(C, 0x48) = 1;  // @h139_52e830
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return N;
#undef F32
#undef F16
#undef F8
#undef FL
#undef EXIT0
#undef TIMING
}
PCREG(52e830, hand_52e830);

extern "C" u32 THISCALL ext_421080_x41c(u32) __asm__("ext_421080");
extern "C" u32 THISCALL ext_420ae0_x41c(u32) __asm__("ext_420ae0");
extern "C" u32 FASTCALL ext_41c820_x41c(u32, u32) __asm__("ext_41c820");
extern "C" u32 ext_41c780_x41c(void) __asm__("ext_41c780");
extern "C" u32 ext_41cf80_x41c(void) __asm__("ext_41cf80");
extern "C" u32 ext_41cfd0_x41c(void) __asm__("ext_41cfd0");
extern "C" u32 ext_6078a0_x41c(void) __asm__("ext_6078a0");
extern "C" u32 ext_6078d0_x41c(void) __asm__("ext_6078d0");
extern "C" u32 THISCALL ext_5f12d0_x41c(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_4ff7b0_x41c(u32) __asm__("ext_4ff7b0");
extern "C" u32 STDCALL hand_41ca80(u32 hInst, u32 hPrev, u32 cmd, u32 show) {
  SEH_ENTER(0x663f44);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  volatile u32 S[0x20], TMP[0x20], S39[0x20];
  volatile char B118[0x104], B21c[0x104];
  const u32 pS = (u32)(unsigned long)&S[0], pT = (u32)(unsigned long)&TMP[0], p39 = (u32)(unsigned long)&S39[0];
  const u32 p118 = (u32)(unsigned long)&B118[0], p21c = (u32)(unsigned long)&B21c[0];
  G(u32, 0x6fcd40) = hInst;  // @h1_41ca80
  ((u32(STDCALL *)(u32, u32, u32))G(u32, 0x676074))(0, 0, 0x676ab0);  // @h2_41ca80
  ext_4cbeb0_t1(pS);  // @h3_41ca80
  reg.state = 0;
  if (((u32(*)(u32, u32))G(u32, 0x676254))(cmd, 0x40) != 0) {  // @h4_41ca80
    ext_4cbe80_t2(pT, cmd);  // @h5_41ca80
    reg.state = 1;
    ext_4cbee0_t2(pS, pT);  // @h6_41ca80
    reg.state = 0;
    ext_4cbec0_t1(pT);  // @h7_41ca80
  } else {
    ext_634d10_cdecl3(p118, 0, 0x104);  // @h8_41ca80
    ext_421080_x41c(p39);  // @h9_41ca80
    reg.state = 2;
    {
      volatile u8 *src = (volatile u8 *)F32(p39, 0);
      volatile u8 *dst = (volatile u8 *)p118;
      u8 ch;
      do { ch = *src++; *dst++ = ch; } while (ch != 0);  // @h10_41ca80
    }
    ext_634d10_cdecl3(p21c, 0, 0x104);  // @h11_41ca80
    ((u32(STDCALL *)(u32, u32, u32))G(u32, 0x67607c))(hInst, p21c, 0x104);  // @h12_41ca80
    u32 sl = ((u32(*)(u32, u32))G(u32, 0x676258))(p21c, 0x5c);  // @h13_41ca80
    {
      volatile u8 *e = (volatile u8 *)p118;
      while (*e != 0) e++;
      volatile u8 *src = (volatile u8 *)(sl + 1);
      u8 ch;
      do { ch = *src++; *e++ = ch; } while (ch != 0);  // @h14_41ca80
    }
    {
      u32 len = 0;
      while (B118[len] != 0) len++;
      F32(p118, len - 4) = G(u32, 0x676ab8);  // @h15_41ca80
      *(volatile u8 *)(p118 + len) = G(u8, 0x676abc);  // @h16_41ca80
    }
    ext_420ae0_x41c(p118);  // @h17_41ca80
    u32 h = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32, u32))G(u32, 0x676068))(p118, 0x80000000, 3, 0, 3, 0x80, 0);  // @h18_41ca80
    if (h != 0xffffffffu) {  // @h19_41ca80
      ((u32(STDCALL *)(u32))G(u32, 0x676070))(h);  // @h20_41ca80
      ext_4cbe80_t2(pT, 0x676ac0);  // @h21_41ca80
      reg.state = 3;
      ext_4cbee0_t2(pS, pT);  // @h22_41ca80
      reg.state = 2;
      ext_4cbec0_t1(pT);  // @h23_41ca80
      ext_4cbe80_t2(pT, p118);  // @h24_41ca80
      reg.state = 4;
      ext_4cc2c0_t2(pS, pT);  // @h25_41ca80
      reg.state = 2;
      ext_4cbec0_t1(pT);  // @h26_41ca80
      ext_4cbe80_t2(pT, 0x676ac4);  // @h27_41ca80
      reg.state = 5;
      ext_4cc2c0_t2(pS, pT);  // @h28_41ca80
      reg.state = 2;
      ext_4cbec0_t1(pT);  // @h29_41ca80
      ext_4cbe80_t2(pT, cmd);  // @h30_41ca80
      reg.state = 6;
      ext_4cc2c0_t2(pS, pT);  // @h31_41ca80
      ext_4cbec0_t1(pT);  // @h32_41ca80
    }
    reg.state = 0;
    ext_4cbec0_t1(p39);  // @h33_41ca80
  }
  u32 rcode = 0;
  u32 (*pstrstr)(u32, u32) = *(u32(**)(u32, u32))0x67625c;
  if (pstrstr(ext_4cc1d0_t1(pS), 0x676ac8) != 0) {  // @h34_41ca80
    ext_41c820_x41c(hInst, 0);  // @h35_41ca80
    u32 raw = ext_41e290_cdecl1((u32)0x1014);  // @h36_41ca80
    reg.state = 7;
    u32 o1 = 0;
    if (raw != 0) o1 = ext_5f12d0_x41c(raw);  // @h37_41ca80
    G(u32, 0x7003a4) = o1;  // @h38_41ca80
    reg.state = 0;
    ((u32(THISCALL *)(u32, u32))VSLOT(o1, 0x94))(o1, 1);  // @h39_41ca80
    o1 = G(u32, 0x7003a4);
    ((u32(THISCALL *)(u32))VSLOT(o1, 0x78))(o1);  // @h40_41ca80
    u32 raw2 = ext_41e290_cdecl1((u32)0x34);  // @h41_41ca80
    reg.state = 8;
    u32 o2 = 0;
    if (raw2 != 0) o2 = ext_4ff7b0_x41c(raw2);  // @h42_41ca80
    G(u32, 0x7003a8) = o2;  // @h43_41ca80
    reg.state = 0;
    ((u32(THISCALL *)(u32))VSLOT(o2, 0xc))(o2);  // @h44_41ca80
    ext_41cfd0_x41c();  // @h45_41ca80
    ext_41cf80_x41c();  // @h46_41ca80
    o2 = G(u32, 0x7003a8);
    ((u32(THISCALL *)(u32))VSLOT(o2, 0x10))(o2);  // @h47_41ca80
    o2 = G(u32, 0x7003a8);
    if (o2 != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o2, 0))(o2, 1);  // @h48_41ca80
    o1 = G(u32, 0x7003a4);
    ((u32(THISCALL *)(u32))VSLOT(o1, 0x10))(o1);  // @h49_41ca80
    o1 = G(u32, 0x7003a4);
    if (o1 != 0) ((u32(THISCALL *)(u32, u32))VSLOT(o1, 0))(o1, 1);  // @h50_41ca80
    ext_41c780_x41c();  // @h51_41ca80
  } else {
    if ((ext_6078a0_x41c() & 0xff) == 0) {  // @h52_41ca80
      ext_6078d0_x41c();  // @h53_41ca80
      ext_4cbec0_t1(pS);  // @h54_41ca80
      SEH_LEAVE();
      ext_633654(G(u32, 0x6f5630));
      return 1;
    }
    u32 f2 = pstrstr(ext_4cc1d0_t1(pS), 0x676ad4);  // @h55_41ca80
    if (f2 != 0) {  // @h56_41ca80
      reg.state = 9;
      ext_41c820_x41c(hInst, 0);  // @h57_41ca80
      u32 lg = G(u32, 0x700390);
      u32 o = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x676ad8, 0x68);  // @h58_41ca80
      ((u32(*)(u32, u32))VSLOT(o, 0x2c))(o, 0x676b10);  // @h59_41ca80
    } else {
      ext_41c820_x41c(hInst, 0x676b74);  // @h60_41ca80
    }
    u32 sy = G(u32, 0x70039c);
    u32 cs = ext_4cc1d0_t1(pS);
    ((u32(THISCALL *)(u32, u32))VSLOT(sy, 0x150))(sy, cs);  // @h61_41ca80
    ext_41c780_x41c();  // @h62_41ca80
    ext_6078d0_x41c();  // @h63_41ca80
    if (G(u32, 0x6e4004) == 0) ((u32(*)(void))G(u32, 0x6e400c))();  // @h64_41ca80
  }
  ext_4cbec0_t1(pS);  // @h65_41ca80
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return rcode;
#undef F32
}
PCREG(41ca80, hand_41ca80);

extern "C" u32 THISCALL ext_4690b0_x58(u32) __asm__("ext_4690b0");
extern "C" u32 THISCALL ext_469870_x58(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4ccba0_x58(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_x58(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4f6b20_x58(u32) __asm__("ext_4f6b20");
extern "C" u32 THISCALL ext_57fad0_x58(u32) __asm__("ext_57fad0");
extern "C" u32 THISCALL ext_581200_x58(u32) __asm__("ext_581200");
extern "C" u32 THISCALL ext_5853f0_x58(u32) __asm__("ext_5853f0");
extern "C" u32 THISCALL ext_585620_x58(u32) __asm__("ext_585620");
extern "C" u32 THISCALL ext_588a00_x58(u32) __asm__("ext_588a00");
extern "C" u32 THISCALL ext_589600_x58(u32) __asm__("ext_589600");
extern "C" u32 THISCALL ext_58ab50_x58(u32,u32,u32,u32) __asm__("ext_58ab50");
extern "C" u32 THISCALL ext_58b5a0_x58(u32) __asm__("ext_58b5a0");
extern "C" u32 THISCALL ext_598440_x58(u32) __asm__("ext_598440");
extern "C" u32 THISCALL ext_598a50_x58(u32) __asm__("ext_598a50");
extern "C" u32 THISCALL ext_59aa30_x58(u32) __asm__("ext_59aa30");
extern "C" u32 THISCALL ext_59ac70_x58(u32) __asm__("ext_59ac70");
extern "C" u32 THISCALL ext_59d580_x58(u32,u32,u32,u32) __asm__("ext_59d580");
extern "C" u32 THISCALL ext_59d930_x58(u32) __asm__("ext_59d930");
extern "C" u32 THISCALL ext_5a3710_x58(u32) __asm__("ext_5a3710");
extern "C" u32 THISCALL ext_5a3dc0_x58(u32) __asm__("ext_5a3dc0");
extern "C" u32 THISCALL ext_5a50e0_x58(u32,u32,u32,u32) __asm__("ext_5a50e0");
extern "C" u32 THISCALL ext_5a54b0_x58(u32) __asm__("ext_5a54b0");
extern "C" u32 THISCALL ext_5acc20_x58(u32) __asm__("ext_5acc20");
extern "C" u32 THISCALL ext_5ad790_x58(u32) __asm__("ext_5ad790");
extern "C" u32 THISCALL ext_5afc10_x58(u32) __asm__("ext_5afc10");
extern "C" u32 THISCALL ext_5b02b0_x58(u32) __asm__("ext_5b02b0");
extern "C" u32 THISCALL ext_5b0990_x58(u32) __asm__("ext_5b0990");
extern "C" u32 THISCALL ext_5b14b0_x58(u32) __asm__("ext_5b14b0");
extern "C" u32 THISCALL ext_5b1910_x58(u32) __asm__("ext_5b1910");
extern "C" u32 THISCALL ext_5b2100_x58(u32,u32,u32,u32) __asm__("ext_5b2100");
extern "C" u32 THISCALL ext_5b21a0_x58(u32) __asm__("ext_5b21a0");
extern "C" u32 THISCALL ext_5b2550_x58(u32) __asm__("ext_5b2550");
extern "C" u32 THISCALL ext_5b2a00_x58(u32) __asm__("ext_5b2a00");
extern "C" u32 THISCALL ext_5b5930_x58(u32) __asm__("ext_5b5930");
extern "C" u32 THISCALL ext_5b7580_x58(u32) __asm__("ext_5b7580");
extern "C" u32 THISCALL ext_5b7790_x58(u32) __asm__("ext_5b7790");
extern "C" u32 THISCALL ext_5b7960_x58(u32) __asm__("ext_5b7960");
extern "C" u32 THISCALL ext_5b7b90_x58(u32,u32,u32) __asm__("ext_5b7b90");
extern "C" u32 THISCALL ext_5b7dd0_x58(u32) __asm__("ext_5b7dd0");
extern "C" u32 THISCALL ext_5b7f00_x58(u32) __asm__("ext_5b7f00");
extern "C" u32 THISCALL ext_5b8340_x58(u32) __asm__("ext_5b8340");
extern "C" u32 THISCALL ext_5b9380_x58(u32) __asm__("ext_5b9380");
extern "C" u32 THISCALL ext_5b9880_x58(u32) __asm__("ext_5b9880");
extern "C" u32 THISCALL ext_5b9a60_x58(u32) __asm__("ext_5b9a60");
extern "C" u32 THISCALL ext_5ba890_x58(u32) __asm__("ext_5ba890");
extern "C" u32 THISCALL ext_5bbc00_x58(u32) __asm__("ext_5bbc00");
extern "C" u32 THISCALL ext_5bc270_x58(u32) __asm__("ext_5bc270");
extern "C" u32 THISCALL ext_5bc4b0_x58(u32) __asm__("ext_5bc4b0");
extern "C" u32 THISCALL ext_5bcab0_x58(u32) __asm__("ext_5bcab0");
extern "C" u32 THISCALL ext_5bd6d0_x58(u32) __asm__("ext_5bd6d0");
extern "C" u32 THISCALL ext_5bdb00_x58(u32) __asm__("ext_5bdb00");
extern "C" u32 THISCALL ext_5bde30_x58(u32) __asm__("ext_5bde30");
extern "C" u32 THISCALL ext_5bdfa0_x58(u32) __asm__("ext_5bdfa0");
extern "C" u32 THISCALL ext_5bf4a0_x58(u32) __asm__("ext_5bf4a0");
extern "C" u32 THISCALL ext_5bf5c0_x58(u32) __asm__("ext_5bf5c0");
extern "C" u32 THISCALL ext_5bfac0_x58(u32) __asm__("ext_5bfac0");
extern "C" u32 THISCALL ext_5bfc00_x58(u32) __asm__("ext_5bfc00");
extern "C" u32 THISCALL ext_5c0a60_x58(u32) __asm__("ext_5c0a60");
extern "C" u32 THISCALL ext_5c2330_x58(u32) __asm__("ext_5c2330");
extern "C" u32 THISCALL ext_5c2440_x58(u32) __asm__("ext_5c2440");
extern "C" u32 THISCALL ext_5c2a00_x58(u32) __asm__("ext_5c2a00");
extern "C" u32 THISCALL ext_5c37e0_x58(u32) __asm__("ext_5c37e0");
extern "C" u32 THISCALL ext_5c3e70_x58(u32) __asm__("ext_5c3e70");
extern "C" u32 THISCALL ext_5c3f10_x58(u32) __asm__("ext_5c3f10");
extern "C" u32 THISCALL ext_5c4530_x58(u32) __asm__("ext_5c4530");
extern "C" u32 THISCALL ext_5c4580_x58(u32) __asm__("ext_5c4580");
extern "C" u32 THISCALL ext_5c5260_x58(u32) __asm__("ext_5c5260");
extern "C" u32 THISCALL ext_5c5a40_x58(u32) __asm__("ext_5c5a40");
extern "C" u32 THISCALL ext_5c5d20_x58(u32) __asm__("ext_5c5d20");
extern "C" u32 THISCALL ext_5c5f30_x58(u32) __asm__("ext_5c5f30");
extern "C" u32 THISCALL ext_5c7ac0_x58(u32) __asm__("ext_5c7ac0");
extern "C" u32 THISCALL ext_5c7ce0_x58(u32) __asm__("ext_5c7ce0");
extern "C" u32 THISCALL ext_5c7ed0_x58(u32) __asm__("ext_5c7ed0");
extern "C" u32 THISCALL ext_5c7f00_x58(u32) __asm__("ext_5c7f00");
extern "C" u32 THISCALL ext_5c7f50_x58(u32) __asm__("ext_5c7f50");
extern "C" u32 THISCALL ext_5c9530_x58(u32) __asm__("ext_5c9530");
extern "C" u32 THISCALL ext_5ca720_x58(u32) __asm__("ext_5ca720");
extern "C" u32 THISCALL ext_5cabb0_x58(u32) __asm__("ext_5cabb0");
extern "C" u32 THISCALL ext_5cce70_x58(u32) __asm__("ext_5cce70");
extern "C" u32 THISCALL ext_5cd450_x58(u32) __asm__("ext_5cd450");
extern "C" u32 THISCALL ext_5d3360_x58(u32) __asm__("ext_5d3360");
extern "C" u32 THISCALL ext_5d38a0_x58(u32) __asm__("ext_5d38a0");
extern "C" u32 THISCALL ext_5d4090_x58(u32) __asm__("ext_5d4090");
extern "C" u32 THISCALL ext_5d48e0_x58(u32) __asm__("ext_5d48e0");
extern "C" u32 THISCALL ext_5d51a0_x58(u32) __asm__("ext_5d51a0");
extern "C" u32 THISCALL ext_5d5570_x58(u32) __asm__("ext_5d5570");
extern "C" u32 THISCALL ext_5d5730_x58(u32,u32,u32,u32) __asm__("ext_5d5730");
extern "C" u32 THISCALL ext_5d5790_x58(u32) __asm__("ext_5d5790");
extern "C" u32 THISCALL ext_5d5c90_x58(u32) __asm__("ext_5d5c90");
extern "C" u32 THISCALL ext_5d6040_x58(u32) __asm__("ext_5d6040");
extern "C" u32 THISCALL ext_5d6a40_x58(u32) __asm__("ext_5d6a40");
extern "C" u32 THISCALL ext_5d6c70_x58(u32) __asm__("ext_5d6c70");
extern "C" u32 THISCALL ext_5d70b0_x58(u32) __asm__("ext_5d70b0");
extern "C" u32 THISCALL ext_5d7f90_x58(u32) __asm__("ext_5d7f90");
extern "C" u32 THISCALL ext_5d8520_x58(u32) __asm__("ext_5d8520");
extern "C" u32 THISCALL ext_5d8840_x58(u32,u32,u32,u32) __asm__("ext_5d8840");
extern "C" u32 THISCALL ext_5d8880_x58(u32) __asm__("ext_5d8880");
extern "C" u32 THISCALL ext_5d8fa0_x58(u32) __asm__("ext_5d8fa0");
extern "C" u32 THISCALL ext_5d9360_x58(u32) __asm__("ext_5d9360");
extern "C" u32 THISCALL ext_5d9f60_x58(u32) __asm__("ext_5d9f60");
extern "C" u32 THISCALL ext_5dac20_x58(u32) __asm__("ext_5dac20");
extern "C" u32 THISCALL ext_5dae30_x58(u32) __asm__("ext_5dae30");
extern "C" u32 THISCALL ext_5daf20_x58(u32) __asm__("ext_5daf20");
extern "C" u32 THISCALL ext_5db5b0_x58(u32) __asm__("ext_5db5b0");
extern "C" u32 THISCALL ext_5dbd10_x58(u32) __asm__("ext_5dbd10");
extern "C" u32 THISCALL ext_5dbfb0_x58(u32) __asm__("ext_5dbfb0");
extern "C" u32 THISCALL ext_5dc060_x58(u32) __asm__("ext_5dc060");
extern "C" u32 THISCALL ext_5dc4f0_x58(u32) __asm__("ext_5dc4f0");
extern "C" u32 THISCALL ext_5dc5f0_x58(u32) __asm__("ext_5dc5f0");
extern "C" u32 THISCALL ext_5dd020_x58(u32) __asm__("ext_5dd020");
extern "C" u32 THISCALL ext_5dd5e0_x58(u32) __asm__("ext_5dd5e0");
extern "C" u32 THISCALL ext_5dd750_x58(u32) __asm__("ext_5dd750");
extern "C" u32 THISCALL ext_5dd870_x58(u32) __asm__("ext_5dd870");
extern "C" u32 THISCALL ext_5ddcc0_x58(u32) __asm__("ext_5ddcc0");
extern "C" u32 THISCALL ext_5ddf10_x58(u32) __asm__("ext_5ddf10");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 THISCALL ext_65e090_x58(u32) __asm__("ext_65e090");
extern "C" u32 hand_580000(void) {
  SEH_ENTER(0x66b56b);
#define F32(base, off) (*(volatile u32 *)((base) + (off)))
  static_assert(sizeof(unsigned long) == 4, "i386");
  volatile u32 FRW[0x16fe0 / 4] __attribute__((aligned(16)));
  for (u32 z = 0; z < 0x16fe0 / 4; z++) FRW[z] = (z >= (0x16fd4 - 0x10000) / 4) ? 0xcccccccc : 0;  // @h0_580000
  const u32 EBP = (u32)(unsigned long)&FRW[0] + 0x16fd4;
  u32 eax = 0, ecx = 0, edx = 0;
  ecx = EBP - 0xa0;  // @h1_580000
  ext_5b1910_x58(ecx);  // @h2_580000
  ecx = EBP - 0xa0;  // @h3_580000
  ext_4f6b20_x58(ecx);  // @h4_580000
  ecx = EBP - 0x60;  // @h5_580000
  ext_5b7790_x58(ecx);  // @h6_580000
  ecx = EBP - 0x60;  // @h7_580000
  ext_4f6b20_x58(ecx);  // @h8_580000
  ecx = EBP - 0x3c;  // @h9_580000
  ext_5b7b90_x58(ecx, 0, 0);  // @h10_580000
  ecx = EBP - 0x3c;  // @h11_580000
  ext_4690b0_x58(ecx);  // @h12_580000
  ecx = EBP - 0x16f64;  // @h13_580000
  ext_5b7dd0_x58(ecx);  // @h14_580000
  ecx = EBP - 0x16f64;  // @h15_580000
  ext_4690b0_x58(ecx);  // @h16_580000
  ecx = EBP - 0x1e0;  // @h17_580000
  ext_5b2100_x58(ecx, 0, 0, 0);  // @h18_580000
  ecx = EBP - 0x1e0;  // @h19_580000
  ext_5b21a0_x58(ecx);  // @h20_580000
  ecx = EBP - 0x32e0;  // @h21_580000
  ext_598440_x58(ecx);  // @h22_580000
  ecx = EBP - 0x32e0;  // @h23_580000
  ext_598a50_x58(ecx);  // @h24_580000
  ecx = EBP - 0x6a;  // @h25_580000
  ext_5b7580_x58(ecx);  // @h26_580000
  ecx = EBP - 0x6a;  // @h27_580000
  ext_4f6b20_x58(ecx);  // @h28_580000
  ecx = EBP - 0x8ec;  // @h29_580000
  ext_5a50e0_x58(ecx, 0, 0, 0);  // @h30_580000
  ecx = EBP - 0x8ec;  // @h31_580000
  ext_5a54b0_x58(ecx);  // @h32_580000
  ecx = EBP - 0xf74;  // @h33_580000
  ext_58ab50_x58(ecx, 0, 0, 0);  // @h34_580000
  ecx = EBP - 0xf74;  // @h35_580000
  ext_58b5a0_x58(ecx);  // @h36_580000
  ecx = EBP - 0x964;  // @h37_580000
  ext_59d580_x58(ecx, 0, 0, 0);  // @h38_580000
  ecx = EBP - 0x964;  // @h39_580000
  ext_59d930_x58(ecx);  // @h40_580000
  ecx = EBP - 0x72;  // @h41_580000
  ext_5b7f00_x58(ecx);  // @h42_580000
  F32(EBP - 0x2e, 0) = 0;  // @h43_580000
  F32(EBP - 0x42, 0) = 0;  // @h44_580000
  eax = G(u32, 0x70039c);  // @h45_580000
  edx = EBP - 0x72;  // @h46_580000
  F32(EBP - 0x72, 0) = 0x686874;  // @h47_580000
  reg.state = 0;  // @h48_580000
  ecx = F32(eax, 0x9b);  // @h49_580000
  eax = F32(ecx, 0);  // @h50_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h51_580000
  ecx = EBP - 0x108;  // @h52_580000
  reg.state = -1;  // @h53_580000
  ext_5b8340_x58(ecx);  // @h54_580000
  F32(EBP - 0xc4, 0) = 0;  // @h55_580000
  F32(EBP - 0xd8, 0) = 0;  // @h56_580000
  eax = G(u32, 0x70039c);  // @h57_580000
  edx = EBP - 0x108;  // @h58_580000
  F32(EBP - 0x108, 0) = 0x686874;  // @h59_580000
  reg.state = 1;  // @h60_580000
  ecx = F32(eax, 0x9b);  // @h61_580000
  eax = F32(ecx, 0);  // @h62_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h63_580000
  ecx = EBP - 0x62;  // @h64_580000
  reg.state = -1;  // @h65_580000
  ext_5b5930_x58(ecx);  // @h66_580000
  ecx = EBP - 0x62;  // @h67_580000
  ext_4f6b20_x58(ecx);  // @h68_580000
  ecx = EBP - 0x76;  // @h69_580000
  ext_5b9380_x58(ecx);  // @h70_580000
  F32(EBP - 0x32, 0) = 0;  // @h71_580000
  F32(EBP - 0x46, 0) = 0;  // @h72_580000
  eax = G(u32, 0x70039c);  // @h73_580000
  edx = EBP - 0x76;  // @h74_580000
  F32(EBP - 0x76, 0) = 0x686874;  // @h75_580000
  reg.state = 2;  // @h76_580000
  ecx = F32(eax, 0x9b);  // @h77_580000
  eax = F32(ecx, 0);  // @h78_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h79_580000
  ecx = EBP - 0xdc;  // @h80_580000
  reg.state = -1;  // @h81_580000
  ext_5b9880_x58(ecx);  // @h82_580000
  ecx = EBP - 0xdc;  // @h83_580000
  ext_5b9a60_x58(ecx);  // @h84_580000
  ecx = EBP - 0x394;  // @h85_580000
  ext_5ba890_x58(ecx);  // @h86_580000
  ecx = EBP - 0x394;  // @h87_580000
  ext_57fad0_x58(ecx);  // @h88_580000
  ecx = EBP - 0x73;  // @h89_580000
  ext_5bbc00_x58(ecx);  // @h90_580000
  F32(EBP - 0x2f, 0) = 0;  // @h91_580000
  F32(EBP - 0x43, 0) = 0;  // @h92_580000
  eax = G(u32, 0x70039c);  // @h93_580000
  edx = EBP - 0x73;  // @h94_580000
  F32(EBP - 0x73, 0) = 0x686874;  // @h95_580000
  reg.state = 3;  // @h96_580000
  ecx = F32(eax, 0x9b);  // @h97_580000
  eax = F32(ecx, 0);  // @h98_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h99_580000
  ecx = EBP - 0x5c;  // @h100_580000
  reg.state = -1;  // @h101_580000
  ext_5bc270_x58(ecx);  // @h102_580000
  F32(EBP - 0x18, 0) = 0;  // @h103_580000
  F32(EBP - 0x2c, 0) = 0;  // @h104_580000
  eax = G(u32, 0x70039c);  // @h105_580000
  edx = EBP - 0x5c;  // @h106_580000
  F32(EBP - 0x5c, 0) = 0x686874;  // @h107_580000
  reg.state = 4;  // @h108_580000
  ecx = F32(eax, 0x9b);  // @h109_580000
  eax = F32(ecx, 0);  // @h110_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h111_580000
  ecx = EBP - 0x73;  // @h112_580000
  reg.state = -1;  // @h113_580000
  ext_5bc4b0_x58(ecx);  // @h114_580000
  F32(EBP - 0x2f, 0) = 0;  // @h115_580000
  F32(EBP - 0x43, 0) = 0;  // @h116_580000
  eax = G(u32, 0x70039c);  // @h117_580000
  edx = EBP - 0x73;  // @h118_580000
  F32(EBP - 0x73, 0) = 0x686874;  // @h119_580000
  reg.state = 5;  // @h120_580000
  ecx = F32(eax, 0x9b);  // @h121_580000
  eax = F32(ecx, 0);  // @h122_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h123_580000
  eax = EBP - 0x6c;  // @h124_580000
  reg.state = -1;  // @h125_580000
  ext_634d10_cdecl3(eax, 0, 90);  // @h126_580000
  ecx = EBP - 0x6c;  // @h127_580000
  ext_469870_x58(ecx);  // @h128_580000
  F32(EBP - 0x68, 0) |= 0x20;  // @h129_580000
  F32(EBP - 0x28, 0) = 0;  // @h130_580000
  F32(EBP - 0x3c, 0) = 0;  // @h131_580000
  eax = G(u32, 0x70039c);  // @h132_580000
  edx = EBP - 0x6c;  // @h133_580000
  F32(EBP - 0x6c, 0) = 0x686874;  // @h134_580000
  reg.state = 6;  // @h135_580000
  ecx = F32(eax, 0x9b);  // @h136_580000
  eax = F32(ecx, 0);  // @h137_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h138_580000
  ecx = EBP - 0x85;  // @h139_580000
  reg.state = -1;  // @h140_580000
  ext_5bcab0_x58(ecx);  // @h141_580000
  F32(EBP - 0x41, 0) = 0;  // @h142_580000
  F32(EBP - 0x55, 0) = 0;  // @h143_580000
  eax = G(u32, 0x70039c);  // @h144_580000
  edx = EBP - 0x85;  // @h145_580000
  F32(EBP - 0x85, 0) = 0x686874;  // @h146_580000
  reg.state = 7;  // @h147_580000
  ecx = F32(eax, 0x9b);  // @h148_580000
  eax = F32(ecx, 0);  // @h149_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h150_580000
  eax = EBP - 0x10c;  // @h151_580000
  reg.state = -1;  // @h152_580000
  ext_634d10_cdecl3(eax, 0, 248);  // @h153_580000
  ecx = EBP - 0x10c;  // @h154_580000
  ext_469870_x58(ecx);  // @h155_580000
  F32(EBP - 0x108, 0) |= 0x20;  // @h156_580000
  F32(EBP - 0xc8, 0) = 0;  // @h157_580000
  ecx = EBP - 0xc0;  // @h158_580000
  reg.state = 8;  // @h159_580000
  F32(EBP - 0x10c, 0) = 0x6aafec;  // @h160_580000
  ext_4ccba0_x58(ecx);  // @h161_580000
  ecx = EBP - 0xc0;  // @h162_580000
  ext_4ccf60_x58(ecx);  // @h163_580000
  F32(EBP - 0xc8, 0) = 0;  // @h164_580000
  F32(EBP - 0xdc, 0) = 0;  // @h165_580000
  eax = G(u32, 0x70039c);  // @h166_580000
  edx = EBP - 0x10c;  // @h167_580000
  F32(EBP - 0x10c, 0) = 0x686874;  // @h168_580000
  reg.state = 9;  // @h169_580000
  ecx = F32(eax, 0x9b);  // @h170_580000
  eax = F32(ecx, 0);  // @h171_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h172_580000
  eax = EBP - 0x10c;  // @h173_580000
  reg.state = -1;  // @h174_580000
  ext_634d10_cdecl3(eax, 0, 248);  // @h175_580000
  ecx = EBP - 0x10c;  // @h176_580000
  ext_469870_x58(ecx);  // @h177_580000
  F32(EBP - 0x108, 0) |= 0x20;  // @h178_580000
  F32(EBP - 0xc8, 0) = 0;  // @h179_580000
  ecx = EBP - 0xc0;  // @h180_580000
  reg.state = 10;  // @h181_580000
  F32(EBP - 0x10c, 0) = 0x6ab074;  // @h182_580000
  ext_4ccba0_x58(ecx);  // @h183_580000
  ecx = EBP - 0xc0;  // @h184_580000
  ext_4ccf60_x58(ecx);  // @h185_580000
  F32(EBP - 0xc8, 0) = 0;  // @h186_580000
  F32(EBP - 0xdc, 0) = 0;  // @h187_580000
  eax = G(u32, 0x70039c);  // @h188_580000
  edx = EBP - 0x10c;  // @h189_580000
  F32(EBP - 0x10c, 0) = 0x686874;  // @h190_580000
  reg.state = 11;  // @h191_580000
  ecx = F32(eax, 0x9b);  // @h192_580000
  eax = F32(ecx, 0);  // @h193_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h194_580000
  ecx = EBP - 0x98;  // @h195_580000
  reg.state = -1;  // @h196_580000
  ext_5bd6d0_x58(ecx);  // @h197_580000
  ecx = EBP - 0x98;  // @h198_580000
  ext_4f6b20_x58(ecx);  // @h199_580000
  ecx = EBP - 0x6f;  // @h200_580000
  ext_5bdb00_x58(ecx);  // @h201_580000
  F32(EBP - 0x2b, 0) = 0;  // @h202_580000
  F32(EBP - 0x3f, 0) = 0;  // @h203_580000
  eax = G(u32, 0x70039c);  // @h204_580000
  edx = EBP - 0x6f;  // @h205_580000
  F32(EBP - 0x6f, 0) = 0x686874;  // @h206_580000
  reg.state = 12;  // @h207_580000
  ecx = F32(eax, 0x9b);  // @h208_580000
  eax = F32(ecx, 0);  // @h209_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h210_580000
  ecx = EBP - 0x9a8;  // @h211_580000
  reg.state = -1;  // @h212_580000
  ext_5bde30_x58(ecx);  // @h213_580000
  ecx = EBP - 0x9a8;  // @h214_580000
  ext_5bdfa0_x58(ecx);  // @h215_580000
  ecx = EBP - 0x7b;  // @h216_580000
  ext_5bfac0_x58(ecx);  // @h217_580000
  ecx = EBP - 0x7b;  // @h218_580000
  ext_5bfc00_x58(ecx);  // @h219_580000
  ecx = EBP - 0x74;  // @h220_580000
  ext_581200_x58(ecx);  // @h221_580000
  ecx = EBP - 0x74;  // @h222_580000
  ext_4f6b20_x58(ecx);  // @h223_580000
  ecx = EBP - 0x8d;  // @h224_580000
  ext_5853f0_x58(ecx);  // @h225_580000
  ecx = EBP - 0x8d;  // @h226_580000
  ext_585620_x58(ecx);  // @h227_580000
  ecx = EBP - 0x138;  // @h228_580000
  ext_469870_x58(ecx);  // @h229_580000
  F32(EBP - 0x134, 0) |= 0x20;  // @h230_580000
  F32(EBP - 0xf4, 0) = 0;  // @h231_580000
  ecx = EBP - 0xf0;  // @h232_580000
  reg.state = 13;  // @h233_580000
  F32(EBP - 0x138, 0) = 0x6ab0fc;  // @h234_580000
  ext_4ccba0_x58(ecx);  // @h235_580000
  ecx = EBP - 0xf0;  // @h236_580000
  ext_4ccf60_x58(ecx);  // @h237_580000
  F32(EBP - 0xf4, 0) = 0;  // @h238_580000
  F32(EBP - 0x108, 0) = 0;  // @h239_580000
  eax = G(u32, 0x70039c);  // @h240_580000
  edx = EBP - 0x138;  // @h241_580000
  F32(EBP - 0x138, 0) = 0x686874;  // @h242_580000
  reg.state = 14;  // @h243_580000
  ecx = F32(eax, 0x9b);  // @h244_580000
  eax = F32(ecx, 0);  // @h245_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h246_580000
  ecx = EBP - 0x270;  // @h247_580000
  reg.state = -1;  // @h248_580000
  ext_5c2330_x58(ecx);  // @h249_580000
  ecx = EBP - 0x270;  // @h250_580000
  ext_5c2440_x58(ecx);  // @h251_580000
  ecx = EBP - 0x5a;  // @h252_580000
  ext_5bf4a0_x58(ecx);  // @h253_580000
  F32(EBP - 0x16, 0) = 0;  // @h254_580000
  F32(EBP - 0x2a, 0) = 0;  // @h255_580000
  eax = G(u32, 0x70039c);  // @h256_580000
  edx = EBP - 0x5a;  // @h257_580000
  F32(EBP - 0x5a, 0) = 0x686874;  // @h258_580000
  reg.state = 15;  // @h259_580000
  ecx = F32(eax, 0x9b);  // @h260_580000
  eax = F32(ecx, 0);  // @h261_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h262_580000
  ecx = EBP - 0x85;  // @h263_580000
  reg.state = -1;  // @h264_580000
  ext_5bf5c0_x58(ecx);  // @h265_580000
  ecx = EBP - 0x85;  // @h266_580000
  ext_4f6b20_x58(ecx);  // @h267_580000
  ecx = EBP - 0x130;  // @h268_580000
  ext_5c0a60_x58(ecx);  // @h269_580000
  F32(EBP - 0xec, 0) = 0;  // @h270_580000
  F32(EBP - 0x100, 0) = 0;  // @h271_580000
  eax = G(u32, 0x70039c);  // @h272_580000
  edx = EBP - 0x130;  // @h273_580000
  F32(EBP - 0x130, 0) = 0x686874;  // @h274_580000
  reg.state = 16;  // @h275_580000
  ecx = F32(eax, 0x9b);  // @h276_580000
  eax = F32(ecx, 0);  // @h277_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h278_580000
  ecx = EBP - 0x16f54;  // @h279_580000
  reg.state = -1;  // @h280_580000
  ext_59aa30_x58(ecx);  // @h281_580000
  ecx = EBP - 0x16f54;  // @h282_580000
  ext_59ac70_x58(ecx);  // @h283_580000
  ecx = EBP - 0x5a;  // @h284_580000
  ext_5c37e0_x58(ecx);  // @h285_580000
  F32(EBP - 0x16, 0) = 0;  // @h286_580000
  F32(EBP - 0x2a, 0) = 0;  // @h287_580000
  eax = G(u32, 0x70039c);  // @h288_580000
  edx = EBP - 0x5a;  // @h289_580000
  F32(EBP - 0x5a, 0) = 0x686874;  // @h290_580000
  reg.state = 17;  // @h291_580000
  ecx = F32(eax, 0x9b);  // @h292_580000
  eax = F32(ecx, 0);  // @h293_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h294_580000
  eax = EBP - 0x5f;  // @h295_580000
  reg.state = -1;  // @h296_580000
  ext_634d10_cdecl3(eax, 0, 77);  // @h297_580000
  ecx = EBP - 0x5f;  // @h298_580000
  ext_469870_x58(ecx);  // @h299_580000
  F32(EBP - 0x5b, 0) |= 0x20;  // @h300_580000
  F32(EBP - 0x1b, 0) = 0;  // @h301_580000
  F32(EBP - 0x2f, 0) = 0;  // @h302_580000
  eax = G(u32, 0x70039c);  // @h303_580000
  edx = EBP - 0x5f;  // @h304_580000
  F32(EBP - 0x5f, 0) = 0x686874;  // @h305_580000
  reg.state = 18;  // @h306_580000
  ecx = F32(eax, 0x9b);  // @h307_580000
  eax = F32(ecx, 0);  // @h308_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h309_580000
  ecx = EBP - 0x66;  // @h310_580000
  reg.state = -1;  // @h311_580000
  ext_5c3e70_x58(ecx);  // @h312_580000
  ecx = EBP - 0x66;  // @h313_580000
  ext_5c3f10_x58(ecx);  // @h314_580000
  ecx = EBP - 0x90;  // @h315_580000
  ext_5c4530_x58(ecx);  // @h316_580000
  ecx = EBP - 0x90;  // @h317_580000
  ext_5c4580_x58(ecx);  // @h318_580000
  ecx = EBP - 0x168;  // @h319_580000
  ext_5c5260_x58(ecx);  // @h320_580000
  ecx = EBP - 0x168;  // @h321_580000
  ext_4f6b20_x58(ecx);  // @h322_580000
  ecx = EBP - 0x66;  // @h323_580000
  ext_5b7960_x58(ecx);  // @h324_580000
  ecx = EBP - 0x66;  // @h325_580000
  ext_4f6b20_x58(ecx);  // @h326_580000
  eax = EBP - 0x66;  // @h327_580000
  ext_634d10_cdecl3(eax, 0, 84);  // @h328_580000
  ecx = EBP - 0x66;  // @h329_580000
  ext_469870_x58(ecx);  // @h330_580000
  F32(EBP - 0x62, 0) |= 0x20;  // @h331_580000
  F32(EBP - 0x22, 0) = 0;  // @h332_580000
  F32(EBP - 0x36, 0) = 0;  // @h333_580000
  reg.state = 19;  // @h334_580000
  eax = G(u32, 0x70039c);  // @h335_580000
  edx = EBP - 0x66;  // @h336_580000
  F32(EBP - 0x66, 0) = 0x686874;  // @h337_580000
  ecx = F32(eax, 0x9b);  // @h338_580000
  eax = F32(ecx, 0);  // @h339_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h340_580000
  ecx = EBP - 0x62;  // @h341_580000
  reg.state = -1;  // @h342_580000
  ext_5c5a40_x58(ecx);  // @h343_580000
  F32(EBP - 0x1e, 0) = 0;  // @h344_580000
  F32(EBP - 0x32, 0) = 0;  // @h345_580000
  eax = G(u32, 0x70039c);  // @h346_580000
  edx = EBP - 0x62;  // @h347_580000
  F32(EBP - 0x62, 0) = 0x686874;  // @h348_580000
  reg.state = 20;  // @h349_580000
  ecx = F32(eax, 0x9b);  // @h350_580000
  eax = F32(ecx, 0);  // @h351_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h352_580000
  ecx = EBP - 0x87;  // @h353_580000
  reg.state = -1;  // @h354_580000
  ext_5c5d20_x58(ecx);  // @h355_580000
  ecx = EBP - 0x87;  // @h356_580000
  ext_5c5f30_x58(ecx);  // @h357_580000
  eax = EBP - 0x9a0;  // @h358_580000
  ext_634d10_cdecl3(eax, 0, 2444);  // @h359_580000
  ecx = EBP - 0x9a0;  // @h360_580000
  ext_469870_x58(ecx);  // @h361_580000
  F32(EBP - 0x99c, 0) |= 0x20;  // @h362_580000
  F32(EBP - 0x95c, 0) = 0;  // @h363_580000
  F32(EBP - 0x970, 0) = 0;  // @h364_580000
  eax = G(u32, 0x70039c);  // @h365_580000
  edx = EBP - 0x9a0;  // @h366_580000
  F32(EBP - 0x9a0, 0) = 0x686874;  // @h367_580000
  reg.state = 21;  // @h368_580000
  ecx = F32(eax, 0x9b);  // @h369_580000
  eax = F32(ecx, 0);  // @h370_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h371_580000
  ecx = EBP - 0x64;  // @h372_580000
  reg.state = -1;  // @h373_580000
  ext_5c7ac0_x58(ecx);  // @h374_580000
  F32(EBP - 0x20, 0) = 0;  // @h375_580000
  F32(EBP - 0x34, 0) = 0;  // @h376_580000
  eax = G(u32, 0x70039c);  // @h377_580000
  edx = EBP - 0x64;  // @h378_580000
  F32(EBP - 0x64, 0) = 0x686874;  // @h379_580000
  reg.state = 22;  // @h380_580000
  ecx = F32(eax, 0x9b);  // @h381_580000
  eax = F32(ecx, 0);  // @h382_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h383_580000
  ecx = EBP - 0x62;  // @h384_580000
  reg.state = -1;  // @h385_580000
  ext_5c7ce0_x58(ecx);  // @h386_580000
  F32(EBP - 0x1e, 0) = 0;  // @h387_580000
  F32(EBP - 0x32, 0) = 0;  // @h388_580000
  eax = G(u32, 0x70039c);  // @h389_580000
  edx = EBP - 0x62;  // @h390_580000
  F32(EBP - 0x62, 0) = 0x686874;  // @h391_580000
  reg.state = 23;  // @h392_580000
  ecx = F32(eax, 0x9b);  // @h393_580000
  eax = F32(ecx, 0);  // @h394_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h395_580000
  ecx = EBP - 0xe34;  // @h396_580000
  reg.state = -1;  // @h397_580000
  ext_5cce70_x58(ecx);  // @h398_580000
  ecx = EBP - 0xe34;  // @h399_580000
  ext_5cd450_x58(ecx);  // @h400_580000
  ecx = EBP - 0x464;  // @h401_580000
  ext_5c9530_x58(ecx);  // @h402_580000
  ecx = EBP - 0x464;  // @h403_580000
  ext_4f6b20_x58(ecx);  // @h404_580000
  ecx = EBP - 0x7cc;  // @h405_580000
  ext_5ca720_x58(ecx);  // @h406_580000
  ecx = EBP - 0x7cc;  // @h407_580000
  ext_5cabb0_x58(ecx);  // @h408_580000
  ecx = EBP - 0x48;  // @h409_580000
  ext_5c7ed0_x58(ecx);  // @h410_580000
  ecx = EBP - 0x48;  // @h411_580000
  ext_5c7f00_x58(ecx);  // @h412_580000
  eax = EBP - 0x5a;  // @h413_580000
  ext_634d10_cdecl3(eax, 0, 72);  // @h414_580000
  ecx = EBP - 0x5a;  // @h415_580000
  ext_469870_x58(ecx);  // @h416_580000
  F32(EBP - 0x56, 0) |= 0x20;  // @h417_580000
  F32(EBP - 0x16, 0) = 0;  // @h418_580000
  F32(EBP - 0x2a, 0) = 0;  // @h419_580000
  eax = G(u32, 0x70039c);  // @h420_580000
  edx = EBP - 0x5a;  // @h421_580000
  F32(EBP - 0x5a, 0) = 0x686874;  // @h422_580000
  reg.state = 24;  // @h423_580000
  ecx = F32(eax, 0x9b);  // @h424_580000
  eax = F32(ecx, 0);  // @h425_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h426_580000
  ecx = EBP - 0x77;  // @h427_580000
  reg.state = -1;  // @h428_580000
  ext_5d3360_x58(ecx);  // @h429_580000
  F32(EBP - 0x33, 0) = 0;  // @h430_580000
  F32(EBP - 0x47, 0) = 0;  // @h431_580000
  eax = G(u32, 0x70039c);  // @h432_580000
  edx = EBP - 0x77;  // @h433_580000
  F32(EBP - 0x77, 0) = 0x686874;  // @h434_580000
  reg.state = 25;  // @h435_580000
  ecx = F32(eax, 0x9b);  // @h436_580000
  eax = F32(ecx, 0);  // @h437_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h438_580000
  ecx = EBP - 0x9c;  // @h439_580000
  reg.state = -1;  // @h440_580000
  ext_5d38a0_x58(ecx);  // @h441_580000
  ecx = EBP - 0x9c;  // @h442_580000
  ext_4f6b20_x58(ecx);  // @h443_580000
  ecx = EBP - 0x14c;  // @h444_580000
  ext_5a3710_x58(ecx);  // @h445_580000
  ecx = EBP - 0x14c;  // @h446_580000
  ext_5a3dc0_x58(ecx);  // @h447_580000
  ecx = EBP - 0x81;  // @h448_580000
  ext_5d4090_x58(ecx);  // @h449_580000
  ecx = EBP - 0x81;  // @h450_580000
  ext_4f6b20_x58(ecx);  // @h451_580000
  ecx = EBP - 0x77;  // @h452_580000
  ext_5d48e0_x58(ecx);  // @h453_580000
  F32(EBP - 0x33, 0) = 0;  // @h454_580000
  F32(EBP - 0x47, 0) = 0;  // @h455_580000
  eax = G(u32, 0x70039c);  // @h456_580000
  edx = EBP - 0x77;  // @h457_580000
  F32(EBP - 0x77, 0) = 0x686874;  // @h458_580000
  reg.state = 26;  // @h459_580000
  ecx = F32(eax, 0x9b);  // @h460_580000
  eax = F32(ecx, 0);  // @h461_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h462_580000
  ecx = EBP - 0x16f60;  // @h463_580000
  reg.state = -1;  // @h464_580000
  ext_65e090_x58(ecx);  // @h465_580000
  ecx = EBP - 0x38;  // @h466_580000
  ext_5afc10_x58(ecx);  // @h467_580000
  eax = EBP - 0x74;  // @h468_580000
  ext_634d10_cdecl3(eax, 0, 98);  // @h469_580000
  ecx = EBP - 0x74;  // @h470_580000
  ext_469870_x58(ecx);  // @h471_580000
  F32(EBP - 0x70, 0) |= 0x20;  // @h472_580000
  F32(EBP - 0x30, 0) = 0;  // @h473_580000
  F32(EBP - 0x44, 0) = 0;  // @h474_580000
  eax = G(u32, 0x70039c);  // @h475_580000
  edx = EBP - 0x74;  // @h476_580000
  F32(EBP - 0x74, 0) = 0x686874;  // @h477_580000
  reg.state = 27;  // @h478_580000
  ecx = F32(eax, 0x9b);  // @h479_580000
  eax = F32(ecx, 0);  // @h480_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h481_580000
  ecx = EBP - 0x5e;  // @h482_580000
  reg.state = -1;  // @h483_580000
  ext_469870_x58(ecx);  // @h484_580000
  F32(EBP - 0x5a, 0) |= 0x20;  // @h485_580000
  F32(EBP - 0x16, 0) = 0xfffffc00;  // @h486_580000
  F32(EBP - 0x1a, 0) = 0;  // @h487_580000
  F32(EBP - 0x2e, 0) = 0;  // @h488_580000
  eax = G(u32, 0x70039c);  // @h489_580000
  edx = EBP - 0x5e;  // @h490_580000
  F32(EBP - 0x5e, 0) = 0x686874;  // @h491_580000
  reg.state = 28;  // @h492_580000
  ecx = F32(eax, 0x9b);  // @h493_580000
  eax = F32(ecx, 0);  // @h494_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h495_580000
  ecx = EBP - 0x6a;  // @h496_580000
  reg.state = -1;  // @h497_580000
  ext_5d51a0_x58(ecx);  // @h498_580000
  F32(EBP - 0x26, 0) = 0;  // @h499_580000
  F32(EBP - 0x3a, 0) = 0;  // @h500_580000
  eax = G(u32, 0x70039c);  // @h501_580000
  edx = EBP - 0x6a;  // @h502_580000
  F32(EBP - 0x6a, 0) = 0x686874;  // @h503_580000
  reg.state = 29;  // @h504_580000
  ecx = F32(eax, 0x9b);  // @h505_580000
  eax = F32(ecx, 0);  // @h506_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h507_580000
  ecx = EBP - 0x62;  // @h508_580000
  reg.state = -1;  // @h509_580000
  ext_5d5570_x58(ecx);  // @h510_580000
  F32(EBP - 0x1e, 0) = 0;  // @h511_580000
  F32(EBP - 0x32, 0) = 0;  // @h512_580000
  eax = G(u32, 0x70039c);  // @h513_580000
  edx = EBP - 0x62;  // @h514_580000
  F32(EBP - 0x62, 0) = 0x686874;  // @h515_580000
  reg.state = 30;  // @h516_580000
  ecx = F32(eax, 0x9b);  // @h517_580000
  eax = F32(ecx, 0);  // @h518_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h519_580000
  ecx = EBP - 0x7c;  // @h520_580000
  reg.state = -1;  // @h521_580000
  ext_5d5c90_x58(ecx);  // @h522_580000
  F32(EBP - 0x38, 0) = 0;  // @h523_580000
  F32(EBP - 0x4c, 0) = 0;  // @h524_580000
  eax = G(u32, 0x70039c);  // @h525_580000
  edx = EBP - 0x7c;  // @h526_580000
  F32(EBP - 0x7c, 0) = 0x686874;  // @h527_580000
  reg.state = 31;  // @h528_580000
  ecx = F32(eax, 0x9b);  // @h529_580000
  eax = F32(ecx, 0);  // @h530_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h531_580000
  ecx = EBP - 0x94;  // @h532_580000
  reg.state = -1;  // @h533_580000
  ext_5d6040_x58(ecx);  // @h534_580000
  F32(EBP - 0x50, 0) = 0;  // @h535_580000
  F32(EBP - 0x64, 0) = 0;  // @h536_580000
  eax = G(u32, 0x70039c);  // @h537_580000
  reg.state = 32;  // @h538_580000
  F32(EBP - 0x94, 0) = 0x686874;  // @h539_580000
  ecx = F32(eax, 0x9b);  // @h540_580000
  edx = EBP - 0x94;  // @h541_580000
  eax = F32(ecx, 0);  // @h542_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h543_580000
  ecx = EBP - 0x5a;  // @h544_580000
  reg.state = -1;  // @h545_580000
  ext_5d6a40_x58(ecx);  // @h546_580000
  F32(EBP - 0x16, 0) = 0;  // @h547_580000
  F32(EBP - 0x2a, 0) = 0;  // @h548_580000
  eax = G(u32, 0x70039c);  // @h549_580000
  edx = EBP - 0x5a;  // @h550_580000
  F32(EBP - 0x5a, 0) = 0x686874;  // @h551_580000
  reg.state = 33;  // @h552_580000
  ecx = F32(eax, 0x9b);  // @h553_580000
  eax = F32(ecx, 0);  // @h554_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h555_580000
  ecx = EBP - 0x72;  // @h556_580000
  reg.state = -1;  // @h557_580000
  ext_5d6c70_x58(ecx);  // @h558_580000
  F32(EBP - 0x2e, 0) = 0;  // @h559_580000
  F32(EBP - 0x42, 0) = 0;  // @h560_580000
  eax = G(u32, 0x70039c);  // @h561_580000
  edx = EBP - 0x72;  // @h562_580000
  F32(EBP - 0x72, 0) = 0x686874;  // @h563_580000
  reg.state = 34;  // @h564_580000
  ecx = F32(eax, 0x9b);  // @h565_580000
  eax = F32(ecx, 0);  // @h566_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h567_580000
  ecx = EBP - 0x1fc;  // @h568_580000
  reg.state = -1;  // @h569_580000
  ext_5d70b0_x58(ecx);  // @h570_580000
  F32(EBP - 0x1b8, 0) = 0;  // @h571_580000
  F32(EBP - 0x1cc, 0) = 0;  // @h572_580000
  eax = G(u32, 0x70039c);  // @h573_580000
  edx = EBP - 0x1fc;  // @h574_580000
  F32(EBP - 0x1fc, 0) = 0x686874;  // @h575_580000
  reg.state = 35;  // @h576_580000
  ecx = F32(eax, 0x9b);  // @h577_580000
  eax = F32(ecx, 0);  // @h578_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h579_580000
  ecx = EBP - 0xd4;  // @h580_580000
  reg.state = -1;  // @h581_580000
  ext_5d7f90_x58(ecx);  // @h582_580000
  F32(EBP - 0x90, 0) = 0;  // @h583_580000
  F32(EBP - 0xa4, 0) = 0;  // @h584_580000
  eax = G(u32, 0x70039c);  // @h585_580000
  edx = EBP - 0xd4;  // @h586_580000
  F32(EBP - 0xd4, 0) = 0x686874;  // @h587_580000
  reg.state = 36;  // @h588_580000
  ecx = F32(eax, 0x9b);  // @h589_580000
  eax = F32(ecx, 0);  // @h590_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h591_580000
  ecx = EBP - 0x67;  // @h592_580000
  reg.state = -1;  // @h593_580000
  ext_5d8520_x58(ecx);  // @h594_580000
  F32(EBP - 0x23, 0) = 0;  // @h595_580000
  F32(EBP - 0x37, 0) = 0;  // @h596_580000
  eax = G(u32, 0x70039c);  // @h597_580000
  edx = EBP - 0x67;  // @h598_580000
  F32(EBP - 0x67, 0) = 0x686874;  // @h599_580000
  reg.state = 37;  // @h600_580000
  ecx = F32(eax, 0x9b);  // @h601_580000
  eax = F32(ecx, 0);  // @h602_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h603_580000
  ecx = EBP - 0x5a;  // @h604_580000
  reg.state = -1;  // @h605_580000
  ext_5d8840_x58(ecx, 0, 0, 0);  // @h606_580000
  ecx = EBP - 0x5a;  // @h607_580000
  ext_5d8880_x58(ecx);  // @h608_580000
  ecx = EBP - 0x7c;  // @h609_580000
  ext_5d8fa0_x58(ecx);  // @h610_580000
  F32(EBP - 0x38, 0) = 0;  // @h611_580000
  F32(EBP - 0x4c, 0) = 0;  // @h612_580000
  eax = G(u32, 0x70039c);  // @h613_580000
  edx = EBP - 0x7c;  // @h614_580000
  F32(EBP - 0x7c, 0) = 0x686874;  // @h615_580000
  reg.state = 38;  // @h616_580000
  ecx = F32(eax, 0x9b);  // @h617_580000
  eax = F32(ecx, 0);  // @h618_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h619_580000
  ecx = EBP - 0xae;  // @h620_580000
  reg.state = -1;  // @h621_580000
  ext_5d9360_x58(ecx);  // @h622_580000
  ecx = EBP - 0xae;  // @h623_580000
  ext_4f6b20_x58(ecx);  // @h624_580000
  ecx = EBP - 0x98;  // @h625_580000
  ext_5d9f60_x58(ecx);  // @h626_580000
  F32(EBP - 0x54, 0) = 0;  // @h627_580000
  F32(EBP - 0x68, 0) = 0;  // @h628_580000
  eax = G(u32, 0x70039c);  // @h629_580000
  edx = EBP - 0x98;  // @h630_580000
  F32(EBP - 0x98, 0) = 0x686874;  // @h631_580000
  reg.state = 39;  // @h632_580000
  ecx = F32(eax, 0x9b);  // @h633_580000
  eax = F32(ecx, 0);  // @h634_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h635_580000
  ecx = EBP - 0x2dc;  // @h636_580000
  reg.state = -1;  // @h637_580000
  ext_5c2a00_x58(ecx);  // @h638_580000
  ecx = EBP - 0x80;  // @h639_580000
  ext_5b02b0_x58(ecx);  // @h640_580000
  ecx = EBP - 0xff4;  // @h641_580000
  ext_5ad790_x58(ecx);  // @h642_580000
  ecx = EBP - 0x170;  // @h643_580000
  ext_5acc20_x58(ecx);  // @h644_580000
  ecx = EBP - 0x974;  // @h645_580000
  ext_5b0990_x58(ecx);  // @h646_580000
  ecx = EBP - 0x170;  // @h647_580000
  ext_5b14b0_x58(ecx);  // @h648_580000
  ecx = EBP - 0x274;  // @h649_580000
  ext_5b2550_x58(ecx);  // @h650_580000
  ecx = EBP - 0x274;  // @h651_580000
  ext_5b2a00_x58(ecx);  // @h652_580000
  ecx = EBP - 0x5a;  // @h653_580000
  ext_5dac20_x58(ecx);  // @h654_580000
  F32(EBP - 0x16, 0) = 0;  // @h655_580000
  F32(EBP - 0x2a, 0) = 0;  // @h656_580000
  eax = G(u32, 0x70039c);  // @h657_580000
  edx = EBP - 0x5a;  // @h658_580000
  F32(EBP - 0x5a, 0) = 0x686874;  // @h659_580000
  reg.state = 40;  // @h660_580000
  ecx = F32(eax, 0x9b);  // @h661_580000
  eax = F32(ecx, 0);  // @h662_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h663_580000
  ecx = EBP - 0x9c;  // @h664_580000
  reg.state = -1;  // @h665_580000
  ext_5dae30_x58(ecx);  // @h666_580000
  ecx = EBP - 0x9c;  // @h667_580000
  ext_5daf20_x58(ecx);  // @h668_580000
  ecx = EBP - 0xb4;  // @h669_580000
  ext_5db5b0_x58(ecx);  // @h670_580000
  ecx = EBP - 0xb4;  // @h671_580000
  ext_4f6b20_x58(ecx);  // @h672_580000
  ecx = EBP - 0x5e;  // @h673_580000
  ext_5dbd10_x58(ecx);  // @h674_580000
  ecx = EBP - 0x5e;  // @h675_580000
  ext_4f6b20_x58(ecx);  // @h676_580000
  ecx = EBP - 0x94;  // @h677_580000
  ext_5dbfb0_x58(ecx);  // @h678_580000
  ecx = EBP - 0x94;  // @h679_580000
  ext_5dc060_x58(ecx);  // @h680_580000
  ecx = EBP - 0xa2;  // @h681_580000
  ext_5c7f50_x58(ecx);  // @h682_580000
  ecx = EBP - 0xa2;  // @h683_580000
  ext_4f6b20_x58(ecx);  // @h684_580000
  ecx = EBP - 0x87;  // @h685_580000
  ext_5dc4f0_x58(ecx);  // @h686_580000
  ecx = EBP - 0x87;  // @h687_580000
  ext_5dc5f0_x58(ecx);  // @h688_580000
  ecx = EBP - 0x90;  // @h689_580000
  ext_5dd020_x58(ecx);  // @h690_580000
  F32(EBP - 0x4c, 0) = 0;  // @h691_580000
  F32(EBP - 0x60, 0) = 0;  // @h692_580000
  eax = G(u32, 0x70039c);  // @h693_580000
  edx = EBP - 0x90;  // @h694_580000
  F32(EBP - 0x90, 0) = 0x686874;  // @h695_580000
  reg.state = 41;  // @h696_580000
  ecx = F32(eax, 0x9b);  // @h697_580000
  eax = F32(ecx, 0);  // @h698_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h699_580000
  ecx = EBP - 0x5a;  // @h700_580000
  reg.state = -1;  // @h701_580000
  ext_5dd5e0_x58(ecx);  // @h702_580000
  F32(EBP - 0x16, 0) = 0;  // @h703_580000
  F32(EBP - 0x2a, 0) = 0;  // @h704_580000
  eax = G(u32, 0x70039c);  // @h705_580000
  edx = EBP - 0x5a;  // @h706_580000
  F32(EBP - 0x5a, 0) = 0x686874;  // @h707_580000
  reg.state = 42;  // @h708_580000
  ecx = F32(eax, 0x9b);  // @h709_580000
  eax = F32(ecx, 0);  // @h710_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h711_580000
  ecx = EBP - 0x98;  // @h712_580000
  reg.state = -1;  // @h713_580000
  ext_5d9f60_x58(ecx);  // @h714_580000
  F32(EBP - 0x54, 0) = 0;  // @h715_580000
  F32(EBP - 0x68, 0) = 0;  // @h716_580000
  eax = G(u32, 0x70039c);  // @h717_580000
  edx = EBP - 0x98;  // @h718_580000
  F32(EBP - 0x98, 0) = 0x686874;  // @h719_580000
  reg.state = 43;  // @h720_580000
  ecx = F32(eax, 0x9b);  // @h721_580000
  eax = F32(ecx, 0);  // @h722_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h723_580000
  ecx = EBP - 0x7c;  // @h724_580000
  reg.state = -1;  // @h725_580000
  ext_5d8fa0_x58(ecx);  // @h726_580000
  F32(EBP - 0x38, 0) = 0;  // @h727_580000
  F32(EBP - 0x4c, 0) = 0;  // @h728_580000
  eax = G(u32, 0x70039c);  // @h729_580000
  edx = EBP - 0x7c;  // @h730_580000
  F32(EBP - 0x7c, 0) = 0x686874;  // @h731_580000
  reg.state = 44;  // @h732_580000
  ecx = F32(eax, 0x9b);  // @h733_580000
  eax = F32(ecx, 0);  // @h734_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h735_580000
  ecx = EBP - 0x62;  // @h736_580000
  reg.state = -1;  // @h737_580000
  ext_5d5570_x58(ecx);  // @h738_580000
  F32(EBP - 0x1e, 0) = 0;  // @h739_580000
  F32(EBP - 0x32, 0) = 0;  // @h740_580000
  eax = G(u32, 0x70039c);  // @h741_580000
  edx = EBP - 0x62;  // @h742_580000
  F32(EBP - 0x62, 0) = 0x686874;  // @h743_580000
  reg.state = 45;  // @h744_580000
  ecx = F32(eax, 0x9b);  // @h745_580000
  eax = F32(ecx, 0);  // @h746_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h747_580000
  ecx = EBP - 0x5c;  // @h748_580000
  reg.state = -1;  // @h749_580000
  ext_5dd750_x58(ecx);  // @h750_580000
  F32(EBP - 0x18, 0) = 0;  // @h751_580000
  F32(EBP - 0x2c, 0) = 0;  // @h752_580000
  eax = G(u32, 0x70039c);  // @h753_580000
  edx = EBP - 0x5c;  // @h754_580000
  F32(EBP - 0x5c, 0) = 0x686874;  // @h755_580000
  reg.state = 46;  // @h756_580000
  ecx = F32(eax, 0x9b);  // @h757_580000
  eax = F32(ecx, 0);  // @h758_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h759_580000
  ecx = EBP - 0x48;  // @h760_580000
  reg.state = -1;  // @h761_580000
  ext_5d5730_x58(ecx, 0, 0, 0);  // @h762_580000
  ecx = EBP - 0x48;  // @h763_580000
  ext_5d5790_x58(ecx);  // @h764_580000
  ecx = EBP - 0x3c84;  // @h765_580000
  ext_588a00_x58(ecx);  // @h766_580000
  ecx = EBP - 0x3c84;  // @h767_580000
  ext_589600_x58(ecx);  // @h768_580000
  ecx = EBP - 0x74;  // @h769_580000
  ext_5ddcc0_x58(ecx);  // @h770_580000
  F32(EBP - 0x30, 0) = 0;  // @h771_580000
  F32(EBP - 0x44, 0) = 0;  // @h772_580000
  eax = G(u32, 0x70039c);  // @h773_580000
  edx = EBP - 0x74;  // @h774_580000
  F32(EBP - 0x74, 0) = 0x686874;  // @h775_580000
  reg.state = 47;  // @h776_580000
  ecx = F32(eax, 0x9b);  // @h777_580000
  eax = F32(ecx, 0);  // @h778_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h779_580000
  ecx = EBP - 0x14c;  // @h780_580000
  reg.state = -1;  // @h781_580000
  ext_5ddf10_x58(ecx);  // @h782_580000
  F32(EBP - 0x108, 0) = 0;  // @h783_580000
  F32(EBP - 0x11c, 0) = 0;  // @h784_580000
  eax = G(u32, 0x70039c);  // @h785_580000
  edx = EBP - 0x14c;  // @h786_580000
  F32(EBP - 0x14c, 0) = 0x686874;  // @h787_580000
  reg.state = 48;  // @h788_580000
  ecx = F32(eax, 0x9b);  // @h789_580000
  eax = F32(ecx, 0);  // @h790_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h791_580000
  ecx = EBP - 0x16fc4;  // @h792_580000
  reg.state = -1;  // @h793_580000
  ext_5dd870_x58(ecx);  // @h794_580000
  F32(EBP - 0x16f80, 0) = 0;  // @h795_580000
  F32(EBP - 0x16f94, 0) = 0;  // @h796_580000
  eax = G(u32, 0x70039c);  // @h797_580000
  edx = EBP - 0x16fc4;  // @h798_580000
  F32(EBP - 0x16fc4, 0) = 0x686874;  // @h799_580000
  reg.state = 49;  // @h800_580000
  ecx = F32(eax, 0x9b);  // @h801_580000
  eax = F32(ecx, 0);  // @h802_580000
  ((u32(THISCALL *)(u32,u32))F32(eax, 0x34))(ecx, edx);  // @h803_580000
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return ecx;
#undef F32
}
PCREG(580000, hand_580000);
