// batch216040.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_45d3a0_thiscall1(u32) __asm__("ext_45d3a0");
extern "C" u32 THISCALL ext_48fa10_thiscall1(u32) __asm__("ext_48fa10");
extern "C" u32 THISCALL ext_48fa70_thiscall1(u32) __asm__("ext_48fa70");
extern "C" u32 THISCALL ext_4958e0_thiscall1(u32) __asm__("ext_4958e0");
extern "C" u32 THISCALL ext_497990_thiscall2(u32, u32) __asm__("ext_497990");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_49b680_thiscall1(u32) __asm__("ext_49b680");
extern "C" u32 THISCALL ext_49d6c0_thiscall1(u32) __asm__("ext_49d6c0");
extern "C" u32 THISCALL ext_49df00_thiscall1(u32) __asm__("ext_49df00");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4dc030_thiscall1(u32) __asm__("ext_4dc030");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_5626d0_thiscall2(u32, u32) __asm__("ext_5626d0");
extern "C" u32 THISCALL ext_57c6f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_57c6f0");
extern "C" u32 THISCALL ext_5c9530_thiscall1(u32) __asm__("ext_5c9530");
extern "C" u32 THISCALL ext_5f2b90_thiscall1(u32) __asm__("ext_5f2b90");
extern "C" u32 THISCALL ext_5fb330_thiscall2(u32, u32) __asm__("ext_5fb330");
extern "C" u32 THISCALL ext_5fb5b0_thiscall1(u32) __asm__("ext_5fb5b0");
extern "C" u32 THISCALL ext_5fbbe0_thiscall2(u32, u32) __asm__("ext_5fbbe0");
extern "C" u32 THISCALL ext_5fd170_thiscall1(u32) __asm__("ext_5fd170");
extern "C" u32 THISCALL ext_5fe200_thiscall2(u32, u32) __asm__("ext_5fe200");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_638ce0_thiscall1(u32) __asm__("ext_638ce0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5fdb70(u32 ecx_in) {
  SEH_ENTER(0x66d6fa);  // @h_5fdb70
  u32 ebx = ecx_in, eax;
  u32 p98 = *(u32 *)(ebx + 0x98);
  *(u32 *)ebx = 0x6b92a4;
  if (p98) { ext_634273_cdecl2(p98, 1); *(u32 *)(ebx + 0x98) = 0; }  // @h1_5fdb70
  u32 vec = ebx + 0x10c;
  u32 edi = *(u32 *)vec;
  if (edi != *(u32 *)(ebx + 0x110)) {  // @h2_5fdb70
    do {
      u32 esi = *(u32 *)edi;
      if (esi) {  // @h3_5fdb70
        reg.state = 0;
        ext_5fb5b0_thiscall1(esi);
        reg.state = 1;
        ext_54f870_stdcall2(*(u32 *)esi, 0x13);  // @h4_5fdb70
        ext_634273_cdecl2(esi, 9);  // @h5_5fdb70
      }
      edi += 4;
    } while (edi != *(u32 *)(ebx + 0x110));  // @h6_5fdb70
  }
  edi = ebx + 0x121;
  reg.state = 2;
  if (*(u32 *)(edi + 4) != 0) {  // @h7_5fdb70
    u32 n = *(u32 *)(*(u32 *)edi + 1);
    while (n) {  // @h8_5fdb70
      ext_5fb330_thiscall2(edi, *(u32 *)(n + 9));  // @h9_5fdb70
      u32 nx = *(u32 *)(n + 5);
      ext_54f870_stdcall2(n, 0x15);  // @h10_5fdb70
      n = nx;
    }
    eax = *(u32 *)edi; *(u32 *)(eax + 5) = eax;
    eax = *(u32 *)edi; *(u32 *)(eax + 1) = 0;
    eax = *(u32 *)edi; *(u32 *)(eax + 9) = eax;
    *(u32 *)(edi + 4) = 0;  // @h11_5fdb70
  }
  reg.state = 3;
  ext_54f870_stdcall2(*(u32 *)edi, 0x15);  // @h12_5fdb70
  edi = ebx + 0x118;
  reg.state = 4;
  if (*(u32 *)(edi + 4) != 0) {  // @h13_5fdb70
    u32 n = *(u32 *)(*(u32 *)edi + 1);
    while (n) {  // @h14_5fdb70
      ext_5fe200_thiscall2(edi, *(u32 *)(n + 9));  // @h15_5fdb70
      u32 nx = *(u32 *)(n + 5);
      ext_54f870_stdcall2(n, 0x13);  // @h16_5fdb70
      n = nx;
    }
    eax = *(u32 *)edi; *(u32 *)(eax + 5) = eax;
    eax = *(u32 *)edi; *(u32 *)(eax + 1) = 0;
    eax = *(u32 *)edi; *(u32 *)(eax + 9) = eax;
    *(u32 *)(edi + 4) = 0;
  }
  reg.state = 5;
  eax = ext_54f870_stdcall2(*(u32 *)edi, 0x13);  // @h17_5fdb70
  reg.state = 6;
  u32 cnt = (*(u32 *)(vec + 8) - *(u32 *)vec) >> 2;
  eax = cnt;
  if (cnt) eax = ext_54f870_stdcall2(*(u32 *)vec, cnt << 2);  // @h18_5fdb70
  SEH_LEAVE();
  return eax;
}
PCREG(5fdb70, lifted_5fdb70);

extern "C" u32 THISCALL lifted_59f1a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_59f1a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_59f1a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; }) != (u32)(0)) goto L59f2a0;  // @1_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1938), sizeof v); (u32)v; });  // @2_59f1a0
  if ((ecx & ecx) == 0) goto L59f2a0;  // @3_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @4_59f1a0
  PS[0] = ecx;  // @5_59f1a0
  ecx = ebx;  // @6_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1836)))(ecx, (u32)(PS[0]));  // @7_59f1a0
  ecx = edx = 0;  // @8_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_59f1a0
  esi = eax;  // @10_59f1a0
  PS[0] = esi;  // @11_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @12_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(PS[0]));  // @14_59f1a0
  ecx = edx = 0;  // @15_59f1a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1930), &v, sizeof v); }  // @16_59f1a0
  if ((esi & esi) == 0) goto L59f247;  // @17_59f1a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1946), sizeof v); (u32)v; }) == (u32)(0)) goto L59f237;  // @18_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_59f1a0
  ecx = ebx;  // @20_59f1a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1272)))(ecx);  // @21_59f1a0
  ecx = edx = 0;  // @22_59f1a0
  PS[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; });  // @23_59f1a0
  ecx = eax;  // @24_59f1a0
  PS[1] = ebx;  // @25_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(PS[1]), PS[0]);  // @27_59f1a0
  ecx = edx = 0;  // @28_59f1a0
  goto L59f2a0;  // @29_59f1a0
  L59f237:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_59f1a0
  ecx = esi;  // @32_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @33_59f1a0
  ecx = edx = 0;  // @34_59f1a0
  goto L59f2a0;  // @35_59f1a0
  L59f247:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @37_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(1388));  // @39_59f1a0
  ecx = edx = 0;  // @40_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_59f1a0
  edi = eax;  // @42_59f1a0
  eax = (u32)(EBP - 144);  // @43_59f1a0
  ecx = ebx;  // @44_59f1a0
  PS[1] = eax;  // @45_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @46_59f1a0
  ecx = edx = 0;  // @47_59f1a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_59f1a0
  ecx = eax;  // @49_59f1a0
  reg.state = (s32)((u32)(0));  // @50_59f1a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @51_59f1a0
  ecx = edx = 0;  // @52_59f1a0
  PS[0] = eax;  // @53_59f1a0
  PS[2] = edi;  // @54_59f1a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(7006872), (u32)(PS[0]));  // @55_59f1a0
  ecx = edx = 0;  // @56_59f1a0
  reg.state = (s32)((u32)(4294967295));  // @57_59f1a0
  ecx = (u32)(EBP - 144);  // @58_59f1a0
  eax = ext_4cbec0_thiscall1(ecx);  // @59_59f1a0
  ecx = edx = 0;  // @60_59f1a0
  L59f2a0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; }) != (u32)(0)) goto L59f350;  // @62_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1942), sizeof v); (u32)v; });  // @63_59f1a0
  if ((ecx & ecx) == 0) goto L59f350;  // @64_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @65_59f1a0
  PS[0] = ecx;  // @66_59f1a0
  ecx = ebx;  // @67_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1836)))(ecx, (u32)(PS[0]));  // @68_59f1a0
  ecx = edx = 0;  // @69_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_59f1a0
  esi = eax;  // @71_59f1a0
  PS[0] = esi;  // @72_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @73_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(PS[0]));  // @75_59f1a0
  ecx = edx = 0;  // @76_59f1a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1934), &v, sizeof v); }  // @77_59f1a0
  if ((esi & esi) == 0) goto L59f2fe;  // @78_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @79_59f1a0
  ecx = ebx;  // @80_59f1a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1276)))(ecx);  // @81_59f1a0
  ecx = edx = 0;  // @82_59f1a0
  PS[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; });  // @83_59f1a0
  ecx = eax;  // @84_59f1a0
  PS[1] = ebx;  // @85_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @86_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(PS[1]), PS[0]);  // @87_59f1a0
  ecx = edx = 0;  // @88_59f1a0
  goto L59f350;  // @89_59f1a0
  L59f2fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @91_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(1403));  // @93_59f1a0
  ecx = edx = 0;  // @94_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @95_59f1a0
  edi = eax;  // @96_59f1a0
  eax = (u32)(EBP - 272);  // @97_59f1a0
  ecx = ebx;  // @98_59f1a0
  PS[1] = eax;  // @99_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @100_59f1a0
  ecx = edx = 0;  // @101_59f1a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @102_59f1a0
  ecx = eax;  // @103_59f1a0
  reg.state = (s32)((u32)(1));  // @104_59f1a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @105_59f1a0
  ecx = edx = 0;  // @106_59f1a0
  PS[0] = eax;  // @107_59f1a0
  PS[2] = edi;  // @108_59f1a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(7006920), (u32)(PS[0]));  // @109_59f1a0
  ecx = edx = 0;  // @110_59f1a0
  ecx = (u32)(EBP - 272);  // @111_59f1a0
  eax = ext_4cbec0_thiscall1(ecx);  // @112_59f1a0
  ecx = edx = 0;  // @113_59f1a0
  L59f350:;
  SEH_LEAVE();  // @115_59f1a0
  ext_633654(G(u32, 0x6f5630));  // @116_59f1a0
  return eax;  // @117_59f1a0
}

extern "C" u32 THISCALL lifted_5f2400(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cfa8);  // @h_5f2400
  u8 L[0x30] __attribute__((aligned(16)));
  u32 ebx = ecx_in, edi = a0, eax;
  u32 pc = *(u32 *)(ebx + 0xc);
  ext_5fd170_thiscall1(*(u32 *)(pc + 4));
  ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0xc))(edi, 0x12);  // @h1_5f2400
  u32 esi = *(u32 *)edi;
  u32 nm = ext_4cc1d0_thiscall1(*(u32 *)(ebx + 0xc) + 0x14);
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 0x64)))(edi, nm);  // @h2_5f2400
  eax = ((u32(THISCALL *)(u32, u32))VSLOT(eax, 0x40))(eax, *(u32 *)(ebx + 0xc) + 0x98);  // @h3_5f2400
  eax = ((u32(THISCALL *)(u32, u32))VSLOT(eax, 0x40))(eax, *(u32 *)(ebx + 0xc) + 0x9c);  // @h4_5f2400
  *(u32 *)(L + 4) = 0;
  *(u32 *)(L + 0xc) = 0;
  *(u8 *)(L + 0x14) = 0;
  *(u32 *)(L + 0) = 0x6b8604;
  __builtin_memcpy(L + 0x15, &edi, 4);
  *(u32 *)(L + 8) = 0;
  reg.state = 0;
  ext_5fbbe0_thiscall2(*(u32 *)(*(u32 *)(ebx + 0xc) + 4), (u32)(u8 *)L);  // @h5_5f2400
  edi = 0;
  u32 n = ext_638ce0_thiscall1(*(u32 *)(*(u32 *)(ebx + 0xc) + 4));
  if (n) {  // @h6_5f2400
    do {
      esi = *(u32 *)(*(u32 *)(ebx + 0xc) + 4);
      if (!(edi < *(u32 *)(esi + 0x20))) {  // @h7_5f2400
        u32 h = G(u32, 0x7003b0);
        if (h) ((u32(*)())h)(); else __builtin_trap();
      }
      u32 E = *(u32 *)(*(u32 *)(esi + 0x18) + edi * 4);
      if (*(u32 *)(E + 0x20) == 0) {  // @h8_5f2400
        u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
        u32 x = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, *(u32 *)(E + 0x24));  // @h9_5f2400
        if (x) {  // @h10_5f2400
          if (*(u32 *)(x + 0x10) == 0) ((u32(THISCALL *)(u32))VSLOT(x, 0x40))(x);  // @h11_5f2400
          u32 a = *(u32 *)(x + 0x10);
          if (*(u32 *)(a + 0x1c) == 0) {  // @h12_5f2400
            u32 nd = ext_41e290_cdecl1((u32)8);  // @h13_5f2400
            if (nd) { *(u32 *)nd = 0; *(u32 *)(nd + 4) = 0; }
            a = *(u32 *)(x + 0x10);
            *(u32 *)(a + 0x1c) = nd;  // @h14_5f2400
            u32 blk = ext_41e290_cdecl1((u32)0x10);  // @h15_5f2400
            if (blk) { *(u32 *)blk = 0; *(u32 *)(blk + 4) = 0; *(u32 *)(blk + 8) = 0; *(u32 *)(blk + 0xc) = 0; }
            u32 c2 = *(u32 *)(*(u32 *)(x + 0x10) + 0x1c);
            *(u32 *)(c2 + 4) = blk;  // @h16_5f2400
          }
          u32 c3 = *(u32 *)(*(u32 *)(x + 0x10) + 0x1c);
          u32 c4 = *(u32 *)(c3 + 4);
          *(u32 *)(c4 + 4) = E;  // @h17_5f2400
        }
      }
      edi++;
      n = ext_638ce0_thiscall1(*(u32 *)(*(u32 *)(ebx + 0xc) + 4));
    } while (edi < n);  // @h18_5f2400
  }
  ext_5f2b90_thiscall1(ebx);
  eax = ext_602240_thiscall1((u32)(u8 *)L);
  SEH_LEAVE();
  return eax;
}
PCREG(5f2400, lifted_5f2400);

#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 THISCALL lifted_48a880(u32 ecx_in) {
  SEH_ENTER(0x667760);  // @h_48a880
  volatile u32 it = 0;
  u32 esi = ecx_in, eax;
  u32 edi = *(u32 *)(esi + 0xae4);
  *(u32 *)esi = 0x68d53c;
  if (edi) { ext_49df00_thiscall1(edi); ext_634273_cdecl2(edi, 8); }  // @h1_48a880
  ext_48fa70_thiscall1(esi);
  eax = *(u32 *)(esi + 0xaec);
  if (eax) { ext_634273_cdecl2(eax, 0); *(u32 *)(esi + 0xaec) = 0; }  // @h2_48a880
  u32 c = *(u32 *)(esi + 0xadc);
  *(u32 *)(esi + 0xae8) = 0;  // @h3_48a880
  if (c) { ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x210))(c, 1); *(u32 *)(esi + 0xadc) = 0; }  // @h4_48a880
  edi = *(u32 *)(esi + 8);
  if (edi) { ext_4958e0_thiscall1(edi); ext_634273_cdecl2(edi, 0x69); *(u32 *)(esi + 8) = 0; }  // @h5_48a880
  edi = *(u32 *)(esi + 0x5d35);
  if (edi) { ext_49b680_thiscall1(edi); ext_634273_cdecl2(edi, 0x41); *(u32 *)(esi + 0x5d35) = 0; }  // @h6_48a880
  edi = esi + 0x1c;
  ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x4c))(edi, (u32)(u32 *)&it);  // @h7_48a880
  u32 n = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x64))(edi, (u32)(u32 *)&it);  // @h8_48a880
  while (n) {  // @h9_48a880
    u32 m = *(u32 *)(n + 0x114);
    if (m) ((u32(THISCALL *)(u32, u32))VSLOT(m, 0))(m, 1);  // @h10_48a880
    n = ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x64))(edi, (u32)(u32 *)&it);  // @h11_48a880
  }
  eax = *(u32 *)(esi + 0x1c5d);
  if (eax) { *(u32 *)(esi + 0x1c5d) = 0; ext_634273_cdecl2(eax, 0); }  // @h12_48a880
  eax = *(u32 *)(esi + 0x44);
  if (eax) ext_634273_cdecl2(eax, 0x18);  // @h13_48a880
  ext_48fa10_thiscall1(esi);
  eax = *(u32 *)(esi + 0xbb7);
  if (eax) { ext_634273_cdecl2(eax, 1); *(u32 *)(esi + 0xbb7) = 0; }  // @h14_48a880
  eax = *(u32 *)(esi + 0xbbb);
  if (eax) { ext_634273_cdecl2(eax, 1); *(u32 *)(esi + 0xbbb) = 0; }  // @h15_48a880
  u32 eng = G(u32, 0x70039c);
  ((u32(THISCALL *)(u32, u32))VSLOT(eng, 0x1a8))(eng, G(u32, 0x6ffa98));  // @h16_48a880
  u32 gobj = G(u32, 0x6ffa98);
  if (gobj) ((u32(THISCALL *)(u32, u32))VSLOT(gobj, 0))(gobj, 1);  // @h17_48a880
  ext_4d2330_thiscall1(esi + 0x1c61);
  ext_4cbec0_thiscall1(esi + 0xbcd);
  ext_4ccf60_thiscall1(esi + 0xb00);
  eax = ext_4cce40_thiscall1(edi);
  SEH_LEAVE();
  return eax;
}
PCREG(48a880, lifted_48a880);

extern "C" u32 THISCALL lifted_57db50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b342);  // @h_57db50
  volatile u32 tmp = 0;
  volatile u32 it = 0;
  u32 edi = ecx_in, ebx = a0, eax;
  eax = ext_5626d0_thiscall2(edi, ebx);  // @h1_57db50
  if (!(eax & 0xff)) { SEH_LEAVE(); return eax; }  // @h2_57db50
  u32 esi = edi + 0x264;
  ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x70))(ebx, esi);  // @h3_57db50
  ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x40))(ebx, (u32)(u32 *)&tmp);  // @h4_57db50
  u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  *(u32 *)(edi + 0x310) = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, tmp);  // @h5_57db50
  ((u32(THISCALL *)(u32, u32))VSLOT(ebx, 0x40))(ebx, (u32)(u32 *)&tmp);  // @h6_57db50
  tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  *(u32 *)(edi + 0x314) = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, tmp);  // @h7_57db50
  ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x4c))(esi, (u32)(u32 *)&it);  // @h8_57db50
  u32 node = eax = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x5c))(esi, (u32)(u32 *)&it);  // @h9_57db50
  if (it != 0) {  // @h10_57db50
    u32 name = 0x6aa8d0;
    do {
      tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, node);  // @h11_57db50
      u32 obj = ext_41e290_cdecl1((u32)0xe1);  // @h12_57db50
      reg.state = 0;
      u32 r;
      if (obj) r = ext_57c6f0_thiscall5(obj, *(u32 *)(edi + 0x310), name, *(u32 *)(edi + 0x31c), ebx);  // @h13_57db50
      else r = 0;
      reg.state = -1;
      u32 ecx;
      if (r == 0) ecx = 0;  // @h14_57db50
      else {
        u32 m = G(u32, 0x70038c);
        u32 k = ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x20))(m, r);  // @h15_57db50
        if (k) ecx = 0;  // @h16_57db50
        else {
          m = G(u32, 0x70038c);
          u32 fn = *(u32 *)(m + 8);
          if (fn && !(*(u32 *)(m + 0xc) > r) && r < *(u32 *)(m + 0x10))  // @h17_57db50
            ecx = ((u32(THISCALL *)(u32))fn)(r);  // @h18_57db50
          else {
            if (*(u32 *)(r - 4) == 0)  // @h19_57db50
              ((u32(THISCALL *)(u32, u32))VSLOT(m, 0xac))(m, r);  // @h20_57db50
            ecx = *(u32 *)(r - 4);
          }
        }
      }
      ((u32(THISCALL *)(u32, u32))VSLOT(edi + 0x23c, 4))(edi + 0x23c, ecx);  // @h21_57db50
      name += 8;
      node = eax = ((u32(THISCALL *)(u32, u32))VSLOT(edi + 0x264, 0x5c))(edi + 0x264, (u32)(u32 *)&it);  // @h22_57db50
    } while (it != 0);  // @h23_57db50
  }
  eax = (eax & 0xffffff00u) | 1;
  SEH_LEAVE();
  return eax;
}
PCREG(57db50, lifted_57db50);

extern "C" u32 THISCALL lifted_57c500(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  SEH_ENTER(0x66b18b);  // @h_57c500
  u32 ebx = ecx_in, esi = a0;
  *(u32 *)ebx = a1;
  *(u32 *)(ebx + 4) = a2;
  *(u32 *)(ebx + 8) = a5;
  ext_4cbeb0_thiscall1(ebx + 0x2c);
  *(u8 *)(ebx + 0xe0) = 0;
  reg.state = 0;
  u32 t = ((u32(THISCALL *)(u32))VSLOT(esi, 0x2c4))(esi);  // @h1_57c500
  ((u32(THISCALL *)(u32))VSLOT(t, 0x348))(t);  // @h2_57c500
  if (*(u32 *)(ebx + 8) == 0) {  // @h3_57c500
    u32 p = *(u32 *)(a4 + 0x50);
    if (p) *(u32 *)(ebx + 8) = *(u32 *)(p + 0x54);  // @h4_57c500
    ((u32(THISCALL *)(u32, u32, u32, u32))VSLOT(esi, 0x288))(esi, *(u32 *)(ebx + 8), 0, 1);  // @h5_57c500
    u32 m = *(u32 *)(ebx + 8);
    ((u32(THISCALL *)(u32, u32))VSLOT(m, 0x30c))(m, a3);  // @h6_57c500
    m = *(u32 *)(ebx + 8);
    ((u32(THISCALL *)(u32))VSLOT(m, 0x2c))(m);  // @h7_57c500
    u32 arr[2] = { 0x6aac60, 0x6aac68 };
    u32 idx = 0;
    do {
      m = *(u32 *)(ebx + 8);
      u32 r = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x25c))(m, arr[idx], 0);  // @h8_57c500
      u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
      u32 o = *(u32 *)(tbl + 0xae4);
      u32 e = ((u32(THISCALL *)(u32, u32, u32))VSLOT(o, 0))(o, 0x6aac70, *(u32 *)(a1 + 4));  // @h9_57c500
      ((u32(THISCALL *)(u32, u32))VSLOT(r, 0x284))(r, e);  // @h10_57c500
      idx++;
    } while (idx < 2);  // @h11_57c500
    static const u32 names[8] = { 0x6aac80, 0x6aac88, 0x6aac90, 0x6aac98, 0x6aaca0, 0x6aaca8, 0x6aacb0, 0x6aacb8 };
    static const u32 offs[8] = { 0xc, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28 };
    for (int k = 0; k < 8; k++) {
      m = *(u32 *)(ebx + 8);
      u32 v = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m, 0x25c))(m, names[k], 0);  // @h12_57c500
      *(u32 *)(ebx + offs[k]) = v;  // @h13_57c500
    }
    for (u32 q = ebx + 0xc, n = 7; n; n--, q += 4) {  // @h14_57c500
      u32 c = *(u32 *)q;
      ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x284))(c, 0x677b5a);  // @h15_57c500
    }
  }
  SEH_LEAVE();
  return ebx;
}
PCREG(57c500, lifted_57c500);

extern "C" u32 THISCALL ext_499880_t3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_49b340_t3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_49a790_t3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_499970_t1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_49b2e0_t2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_497990_t2(u32, u32) __asm__("ext_497990");
extern "C" u32 THISCALL ext_49d6c0_t1(u32) __asm__("ext_49d6c0");
extern "C" u32 THISCALL lifted_4923e0(u32 ecx_in) {
  SEH_ENTER(0x667d9b);  // @h_4923e0
  u8 L[0x100] __attribute__((aligned(16)));
  volatile u32 cur = 0;
  u32 esi = ecx_in, eax = G(u32, 0x70039c), edi;
  u32 eng = eax;
  if (*(u32 *)(eng + 0x1aab) != 0) {  // @h1_4923e0
    edi = ext_41e290_cdecl1((u32)0x989680);  // @h2_4923e0
    eng = G(u32, 0x70039c);
    ((u32(THISCALL *)(u32))VSLOT(eng, 0x14))(eng);  // @h3_4923e0
    ext_499880_t3((u32)(u8 *)L, edi, 0x989680);  // @h4_4923e0
    reg.state = 0;
    ext_49b340_t3((u32)(u8 *)L, 5, 0x15);  // @h5_4923e0
    eng = G(u32, 0x70039c);
    u32 ok = ext_49a790_t3((u32)(u8 *)L, *(u32 *)(eng + 0x1aab), 3) & 0xff;  // @h6_4923e0
    if (!ok) {  // @h7_4923e0
      ext_634273_cdecl2(edi, 1);
      *(u8 *)(esi + 0xbb2) = 1;  // @h8_4923e0
      eax = ext_499970_t1((u32)(u8 *)L);
    } else {
      eng = G(u32, 0x70039c);
      u32 c = *(u32 *)(eng + 0x1aa3);
      if (c) { ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x44))(c, (u32)(u8 *)L); }  // @h9_4923e0
      c = *(u32 *)(eng + 0x1a9f);
      if (c) ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x88))(c, (u32)(u8 *)L);  // @h10_4923e0
      ext_497990_t2(*(u32 *)(esi + 8), (u32)(u8 *)L);  // @h11_4923e0
      eng = G(u32, 0x70039c);
      c = *(u32 *)(eng + 0x1aa3);
      if (c) ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x48))(c, (u32)(u8 *)L);  // @h12_4923e0
      c = G(u32, 0x7003a4);
      if (c) ((u32(THISCALL *)(u32, u32))VSLOT(c, 0xd4))(c, (u32)(u8 *)L);  // @h13_4923e0
      if (G(u32, 0x7003b8) != 0) {  // @h14_4923e0
        ext_49b2e0_t2((u32)(u8 *)L, 0x15);  // @h15_4923e0
        u32 o = G(u32, 0x7003b8);
        ((u32(THISCALL *)(u32, u32))VSLOT(o, 8))(o, (u32)(u8 *)L);  // @h16_4923e0
      }
      ext_49b2e0_t2((u32)(u8 *)L, 0xa);  // @h17_4923e0
      eng = G(u32, 0x70039c);
      u32 t = *(u32 *)(eng + 0x1907);
      ((u32(THISCALL *)(u32, u32))VSLOT(t, 0xb4))(t, (u32)(u8 *)L);  // @h18_4923e0
      eng = G(u32, 0x70039c);
      *(u32 *)(eng + 0x1aab) = 0;  // @h19_4923e0
      eng = G(u32, 0x70039c);
      ((u32(THISCALL *)(u32))VSLOT(eng, 0x10))(eng);  // @h20_4923e0
      *(u8 *)(esi + 0xbc0) = 0;
      ext_634273_cdecl2(edi, 1);  // @h21_4923e0
      ext_49d6c0_t1(*(u32 *)(esi + 0xc8));  // @h22_4923e0
      u32 ecx = G(u32, 0x70039c);
      u32 lst = *(u32 *)(*(u32 *)(ecx + 0x9b) + 0xadc);
      cur = *(u32 *)(lst + 8);
      u32 edx = cur;
      if (edx) {  // @h23_4923e0
        for (;;) {
          if ((*(u32 *)(edx + 0x3c) & 0x46c00) == 0x44000) {  // @h24_4923e0
            u32 o = *(u32 *)(*(u32 *)(ecx + 0x9b) + 0x5d31);
            ((u32(THISCALL *)(u32, u32))VSLOT(o, 0))(o, edx);  // @h25_4923e0
            ecx = G(u32, 0x70039c);
          }
          u32 l2 = *(u32 *)(*(u32 *)(ecx + 0x9b) + 0xadc);
          ((u32(THISCALL *)(u32, u32))VSLOT(l2, 0x50))(l2, (u32)(u32 *)&cur);  // @h26_4923e0
          edx = cur;
          if (!edx) break;  // @h27_4923e0
          ecx = G(u32, 0x70039c);
        }
      }
      eax = ext_499970_t1((u32)(u8 *)L);  // @h28_4923e0
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(4923e0, lifted_4923e0);

extern "C" u32 THISCALL ext_45d3a0_q1(u32) __asm__("ext_45d3a0");
extern "C" u32 THISCALL ext_4ccba0_q1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4cd540_q2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da340_q5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4dc030_q1(u32) __asm__("ext_4dc030");
extern "C" u32 THISCALL ext_4dc630_q3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4ccf60_q1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL lifted_476720(u32 ecx_in) {
  SEH_ENTER(0x66713b);  // @h_476720
  u8 Lc[0x40] __attribute__((aligned(16)));
  volatile u32 cur = 0;
  volatile u32 it = 0;
  u32 ebx = ecx_in, eax = 0;
  eax = ext_45d3a0_q1(ebx);
  if (*(u8 *)(ebx + 0x72) == 0) {  // @h1_476720
    s32 edi = 0;
    if (*(s32 *)(ebx + 0x5c) > edi) {  // @h2_476720
      do {
        u32 esi = *(u32 *)(*(u32 *)(ebx + 0x64) + edi * 4);
        u32 obj = *(u32 *)(esi + 8);
        eax = obj;
        if ((*(u32 *)(obj + 0x3c) & 0x800000) == 0) {  // @h3_476720
          eax = ext_4ccba0_q1((u32)(u8 *)Lc);
          reg.state = 0;
          cur = *(u32 *)(esi + 8);
          while (cur != 0) {  // @h4_476720
            u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
            u32 key = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x50))(tbl, cur);  // @h5_476720
            ext_4cd540_q2((u32)(u8 *)Lc, key);  // @h6_476720
            ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0x50))(esi, (u32)(u32 *)&cur);  // @h7_476720
          }
          u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
          ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x4c))(tbl, esi);  // @h8_476720
          ((u32(THISCALL *)(u32, u32))VSLOT(Lc, 0x4c))((u32)(u8 *)Lc, (u32)(u32 *)&it);  // @h9_476720
          u32 node = ((u32(THISCALL *)(u32, u32))VSLOT(Lc, 0x5c))((u32)(u8 *)Lc, (u32)(u32 *)&it);  // @h10_476720
          while (it != 0) {  // @h11_476720
            tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
            u32 o = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x54))(tbl, node);  // @h12_476720
            cur = o;
            if (o && (*(u32 *)(o + 0x3c) & 0x800000) == 0) {  // @h13_476720
              u32 c = *(u32 *)(o + 0x54);
              if (c) ((u32(THISCALL *)(u32))VSLOT(c, 0x154))(c);  // @h14_476720
              tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
              if (((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x54))(tbl, node) != 0) {  // @h15_476720
                ext_4da340_q5(o, 1, 0, 0, 0);  // @h16_476720
                tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
                if (((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x54))(tbl, node) != 0) {  // @h17_476720
                  ext_4da340_q5(cur, 2, 0, 0, 0);  // @h18_476720
                  tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
                  if (((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x54))(tbl, node) != 0) {  // @h19_476720
                    ext_4dc630_q3(cur, 0x800000, 0);  // @h20_476720
                    u32 c2 = *(u32 *)(cur + 0x54);
                    if (c2) ((u32(THISCALL *)(u32))VSLOT(c2, 0x158))(c2);  // @h21_476720
                    ext_4dc030_q1(cur);  // @h22_476720
                  }
                }
              }
            }
            node = ((u32(THISCALL *)(u32, u32))VSLOT(Lc, 0x5c))((u32)(u8 *)Lc, (u32)(u32 *)&it);  // @h23_476720
          }
          reg.state = -1;
          eax = ext_4ccf60_q1((u32)(u8 *)Lc);
        }
        edi++;
      } while (edi < *(s32 *)(ebx + 0x5c));  // @h24_476720
    }
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(476720, lifted_476720);

extern "C" u32 THISCALL lifted_5ca720(u32 ecx_in) {
  SEH_ENTER(0x66c7fa);  // @h_5ca720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_5ca720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ca720
  eax = ext_5c9530_thiscall1(ecx);  // @2_5ca720
  ecx = edx = 0;  // @3_5ca720
  { u32 v = (u32)((u32)(7031784)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5ca720
  eax = (u32)(esi + 1206);  // @5_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @6_5ca720
  ecx = (u32)(EBP - 20);  // @7_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1252), &v, sizeof v); }  // @8_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1256), &v, sizeof v); }  // @9_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1260), &v, sizeof v); }  // @10_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1264), &v, sizeof v); }  // @11_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1268), &v, sizeof v); }  // @12_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1269), &v, sizeof v); }  // @13_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1273), &v, sizeof v); }  // @14_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1277), &v, sizeof v); }  // @15_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1281), &v, sizeof v); }  // @16_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1285), &v, sizeof v); }  // @17_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1289), &v, sizeof v); }  // @18_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1293), &v, sizeof v); }  // @19_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1297), &v, sizeof v); }  // @20_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1301), &v, sizeof v); }  // @21_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1305), &v, sizeof v); }  // @22_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1309), &v, sizeof v); }  // @23_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1313), &v, sizeof v); }  // @24_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1314), &v, sizeof v); }  // @25_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1318), &v, sizeof v); }  // @26_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1322), &v, sizeof v); }  // @27_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1326), &v, sizeof v); }  // @28_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1330), &v, sizeof v); }  // @29_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1334), &v, sizeof v); }  // @30_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1338), &v, sizeof v); }  // @31_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1342), &v, sizeof v); }  // @32_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1346), &v, sizeof v); }  // @33_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1350), &v, sizeof v); }  // @34_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1354), &v, sizeof v); }  // @35_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1358), &v, sizeof v); }  // @36_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1359), &v, sizeof v); }  // @37_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1363), &v, sizeof v); }  // @38_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1367), &v, sizeof v); }  // @39_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1371), &v, sizeof v); }  // @40_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1375), &v, sizeof v); }  // @41_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1379), &v, sizeof v); }  // @42_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1383), &v, sizeof v); }  // @43_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1387), &v, sizeof v); }  // @44_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1391), &v, sizeof v); }  // @45_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1395), &v, sizeof v); }  // @46_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1399), &v, sizeof v); }  // @47_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1403), &v, sizeof v); }  // @48_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1404), &v, sizeof v); }  // @49_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1408), &v, sizeof v); }  // @50_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1412), &v, sizeof v); }  // @51_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1416), &v, sizeof v); }  // @52_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1420), &v, sizeof v); }  // @53_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1424), &v, sizeof v); }  // @54_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1428), &v, sizeof v); }  // @55_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1452), &v, sizeof v); }  // @56_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1137), &v, sizeof v); }  // @57_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1226), &v, sizeof v); }  // @58_5ca720
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1432), &v, sizeof v); }  // @59_5ca720
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 762), &v, sizeof v); }  // @60_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 778), &v, sizeof v); }  // @61_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @62_5ca720
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @63_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1214), &v, sizeof v); }  // @64_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1210), &v, sizeof v); }  // @65_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1218), &v, sizeof v); }  // @66_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1222), &v, sizeof v); }  // @67_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1105), &v, sizeof v); }  // @68_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1109), &v, sizeof v); }  // @69_5ca720
  { u32 v = (u32)((u32)(2147483648)); __builtin_memcpy((void *)(u32)(esi + 1113), &v, sizeof v); }  // @70_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1117), &v, sizeof v); }  // @71_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1121), &v, sizeof v); }  // @72_5ca720
  { u32 v = (u32)((u32)(2147483648)); __builtin_memcpy((void *)(u32)(esi + 1125), &v, sizeof v); }  // @73_5ca720
  reg.state = (s32)((u32)(0));  // @74_5ca720
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(esi + 1202), &v, sizeof v); }  // @75_5ca720
  if (eax == ecx) goto L5ca9fc;  // @76_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @77_5ca720
  L5ca9fc:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1240), &v, sizeof v); }  // @79_5ca720
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(esi + 1157), &v, sizeof v); }  // @80_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1145), &v, sizeof v); }  // @81_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1149), &v, sizeof v); }  // @82_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1161), &v, sizeof v); }  // @83_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1227), &v, sizeof v); }  // @84_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1231), &v, sizeof v); }  // @85_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1235), &v, sizeof v); }  // @86_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1244), &v, sizeof v); }  // @87_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1248), &v, sizeof v); }  // @88_5ca720
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(esi + 1198), &v, sizeof v); }  // @89_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 216), &v, sizeof v); }  // @90_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 217), &v, sizeof v); }  // @91_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 346), &v, sizeof v); }  // @92_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 347), &v, sizeof v); }  // @93_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 476), &v, sizeof v); }  // @94_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 477), &v, sizeof v); }  // @95_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 606), &v, sizeof v); }  // @96_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 607), &v, sizeof v); }  // @97_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 736), &v, sizeof v); }  // @98_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 737), &v, sizeof v); }  // @99_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_5ca720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_5ca720
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7032036), (u32)(0), (u32)(7031988), (u32)(165));  // @103_5ca720
  ecx = edx = 0;  // @104_5ca720
  edi = (u32)(esi + 1968);  // @105_5ca720
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 1434), &v, sizeof v); }  // @106_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @107_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1969), &v, sizeof v); }  // @108_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1973), &v, sizeof v); }  // @109_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1977), &v, sizeof v); }  // @110_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1239), &v, sizeof v); }  // @111_5ca720
  { u32 v = (u32)((u32)(1068823723)); __builtin_memcpy((void *)(u32)(esi + 1133), &v, sizeof v); }  // @112_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1293), &v, sizeof v); }  // @113_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1338), &v, sizeof v); }  // @114_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1383), &v, sizeof v); }  // @115_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1428), &v, sizeof v); }  // @116_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1141), &v, sizeof v); }  // @117_5ca720
  eax = ext_41e290_cdecl1((u32)(264));  // @118_5ca720
  ecx = edx = 0;  // @119_5ca720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @120_5ca720
  reg.state = (s32)((u32)(1));  // @121_5ca720
  if ((eax & eax) == 0) goto L5cab7f;  // @122_5ca720
  PS[0] = edi;  // @123_5ca720
  ecx = eax;  // @124_5ca720
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7032084), (u32)(7032052), (u32)(PS[0]));  // @125_5ca720
  ecx = edx = 0;  // @126_5ca720
  edx = eax;  // @127_5ca720
  goto L5cab81;  // @128_5ca720
  L5cab7f:;
  edx = 0;  // @130_5ca720
  L5cab81:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 1448), &v, sizeof v); }  // @132_5ca720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @133_5ca720
  PS[0] = edx;  // @134_5ca720
  reg.state = (s32)((u32)(0));  // @135_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_5ca720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @137_5ca720
  ecx = edx = 0;  // @138_5ca720
  eax = esi;  // @139_5ca720
  SEH_LEAVE();  // @140_5ca720
  return eax;  // @141_5ca720
}

