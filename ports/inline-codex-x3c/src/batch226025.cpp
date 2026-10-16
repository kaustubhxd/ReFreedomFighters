// batch226025.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_448a30_thiscall2(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_452bc0
  PS[0] = esi;  // @2_452bc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @3_452bc0
  eax = ext_448a30_thiscall2(ecx, (u32)(PS[0]));  // @4_452bc0
  ecx = edx = 0;  // @5_452bc0
  ecx = esi;  // @6_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @7_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @8_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @9_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @10_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @11_452bc0
  ecx = edx = 0;  // @12_452bc0
  if ((eax & 0xff) != (u32)(2)) goto L452d47;  // @13_452bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_452bc0
  ecx = ebx;  // @15_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @16_452bc0
  ecx = edx = 0;  // @17_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @18_452bc0
  esi = eax;  // @19_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(63));  // @21_452bc0
  ecx = edx = 0;  // @22_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_452bc0
  edi = eax;  // @24_452bc0
  eax = (u32)(EBP - 156);  // @25_452bc0
  ecx = esi;  // @26_452bc0
  PS[1] = eax;  // @27_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @28_452bc0
  ecx = edx = 0;  // @29_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_452bc0
  ecx = eax;  // @31_452bc0
  reg.state = (s32)((u32)(0));  // @32_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @33_452bc0
  ecx = edx = 0;  // @34_452bc0
  PS[0] = eax;  // @35_452bc0
  PS[2] = edi;  // @36_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 48)))((u32)(PS[2]), (u32)(6813044), (u32)(PS[0]));  // @37_452bc0
  ecx = edx = 0;  // @38_452bc0
  reg.state = (s32)((u32)(4294967295));  // @39_452bc0
  ecx = (u32)(EBP - 156);  // @40_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @41_452bc0
  ecx = edx = 0;  // @42_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @43_452bc0
  ecx = esi;  // @44_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @45_452bc0
  ecx = edx = 0;  // @46_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452cbb;  // @47_452bc0
  eax = (u32)(EBP - 288);  // @48_452bc0
  ecx = esi;  // @49_452bc0
  PS[1] = eax;  // @50_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @51_452bc0
  ecx = edx = 0;  // @52_452bc0
  goto L452d47;  // @53_452bc0
  L452cbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_452bc0
  ecx = ebx;  // @56_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @57_452bc0
  ecx = edx = 0;  // @58_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_452bc0
  esi = eax;  // @60_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(68));  // @62_452bc0
  ecx = edx = 0;  // @63_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_452bc0
  edi = eax;  // @65_452bc0
  eax = (u32)(EBP - 284);  // @66_452bc0
  ecx = esi;  // @67_452bc0
  PS[1] = eax;  // @68_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @69_452bc0
  ecx = edx = 0;  // @70_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @71_452bc0
  ecx = eax;  // @72_452bc0
  reg.state = (s32)((u32)(1));  // @73_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @74_452bc0
  ecx = edx = 0;  // @75_452bc0
  PS[0] = eax;  // @76_452bc0
  PS[2] = edi;  // @77_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6822612), (u32)(PS[0]));  // @78_452bc0
  ecx = edx = 0;  // @79_452bc0
  reg.state = (s32)((u32)(4294967295));  // @80_452bc0
  ecx = (u32)(EBP - 284);  // @81_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @82_452bc0
  ecx = edx = 0;  // @83_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @84_452bc0
  eax = (u32)(EBP - 28);  // @85_452bc0
  PS[1] = eax;  // @86_452bc0
  ecx = esi;  // @87_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @88_452bc0
  ecx = edx = 0;  // @89_452bc0
  eax = (u32)(EBP - 24);  // @90_452bc0
  ecx = esi;  // @91_452bc0
  PS[1] = eax;  // @92_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @93_452bc0
  ecx = edx = 0;  // @94_452bc0
  eax = (u32)(EBP - 20);  // @95_452bc0
  ecx = esi;  // @96_452bc0
  PS[1] = eax;  // @97_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @98_452bc0
  ecx = edx = 0;  // @99_452bc0
  L452d47:;
  eax = (u32)(EBP - 292);  // @101_452bc0
  ecx = esi;  // @102_452bc0
  PS[1] = eax;  // @103_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @104_452bc0
  ecx = edx = 0;  // @105_452bc0
  eax = (u32)(EBP - 296);  // @106_452bc0
  ecx = esi;  // @107_452bc0
  PS[1] = eax;  // @108_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @109_452bc0
  ecx = edx = 0;  // @110_452bc0
  ecx = esi;  // @111_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @112_452bc0
  ecx = edx = 0;  // @113_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d82;  // @114_452bc0
  eax = (u32)(EBP - 300);  // @115_452bc0
  ecx = esi;  // @116_452bc0
  PS[1] = eax;  // @117_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @118_452bc0
  ecx = edx = 0;  // @119_452bc0
  L452d82:;
  ecx = esi;  // @121_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @122_452bc0
  ecx = edx = 0;  // @123_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d9d;  // @124_452bc0
  eax = (u32)(EBP - 304);  // @125_452bc0
  ecx = esi;  // @126_452bc0
  PS[1] = eax;  // @127_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @128_452bc0
  ecx = edx = 0;  // @129_452bc0
  L452d9d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) & (u32)(4294955007))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @131_452bc0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }) == (u32)(0)) goto L452db4;  // @132_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @133_452bc0
  L452db4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L452dc4;  // @135_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(8192))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @136_452bc0
  L452dc4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; }) == (u32)(0)) goto L452dd4;  // @138_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(16384))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @139_452bc0
  L452dd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; }) == (u32)(0)) goto L452de4;  // @141_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(32768))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @142_452bc0
  L452de4:;
  ecx = esi;  // @144_452bc0
  eax = ext_4e1b30_thiscall1(ecx);  // @145_452bc0
  ecx = edx = 0;  // @146_452bc0
  SEH_LEAVE();  // @147_452bc0
  ext_633654(G(u32, 0x6f5630));  // @148_452bc0
  return eax;  // @149_452bc0
}
PCREG(452bc0, lifted_452bc0);

