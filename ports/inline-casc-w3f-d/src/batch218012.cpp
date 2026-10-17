// batch218012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_430620_fastcall4(u32, u32, u32, u32) __asm__("ext_430620");
extern "C" u32 FASTCALL ext_49f9b0_fastcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_49f9b0");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4cd9b0_fastcall4(u32, u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 STDCALL ext_4c4f10_stdcall3(u32, u32, u32) __asm__("ext_4c4f10");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_5c6370_stdcall2(u32, u32) __asm__("ext_5c6370");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_45c560_thiscall2(u32, u32) __asm__("ext_45c560");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_49f2d0_thiscall1(u32) __asm__("ext_49f2d0");
extern "C" u32 THISCALL ext_4a3280_thiscall1(u32) __asm__("ext_4a3280");
extern "C" u32 THISCALL ext_4a3360_thiscall1(u32) __asm__("ext_4a3360");
extern "C" u32 THISCALL ext_4a3b40_thiscall1(u32) __asm__("ext_4a3b40");
extern "C" u32 THISCALL ext_4a4700_thiscall1(u32) __asm__("ext_4a4700");
extern "C" u32 THISCALL ext_4a4fb0_thiscall1(u32) __asm__("ext_4a4fb0");
extern "C" u32 THISCALL ext_4a6270_thiscall1(u32) __asm__("ext_4a6270");
extern "C" u32 THISCALL ext_4a7960_thiscall1(u32) __asm__("ext_4a7960");
extern "C" u32 THISCALL ext_4a80a0_thiscall1(u32) __asm__("ext_4a80a0");
extern "C" u32 THISCALL ext_4a86c0_thiscall1(u32) __asm__("ext_4a86c0");
extern "C" u32 THISCALL ext_4a9600_thiscall1(u32) __asm__("ext_4a9600");
extern "C" u32 THISCALL ext_4a9880_thiscall1(u32) __asm__("ext_4a9880");
extern "C" u32 THISCALL ext_4ae4f0_thiscall1(u32) __asm__("ext_4ae4f0");
extern "C" u32 THISCALL ext_4af440_thiscall1(u32) __asm__("ext_4af440");
extern "C" u32 THISCALL ext_4b1c70_thiscall1(u32) __asm__("ext_4b1c70");
extern "C" u32 THISCALL ext_4b8610_thiscall1(u32) __asm__("ext_4b8610");
extern "C" u32 THISCALL ext_4b86b0_thiscall1(u32) __asm__("ext_4b86b0");
extern "C" u32 THISCALL ext_4b8fd0_thiscall1(u32) __asm__("ext_4b8fd0");
extern "C" u32 THISCALL ext_4b9160_thiscall1(u32) __asm__("ext_4b9160");
extern "C" u32 THISCALL ext_4baeb0_thiscall1(u32) __asm__("ext_4baeb0");
extern "C" u32 THISCALL ext_4bb160_thiscall1(u32) __asm__("ext_4bb160");
extern "C" u32 THISCALL ext_4bb350_thiscall1(u32) __asm__("ext_4bb350");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d93e0_thiscall1(u32) __asm__("ext_4d93e0");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0f60_thiscall2(u32, u32) __asm__("ext_4e0f60");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e6ce0_thiscall1(u32) __asm__("ext_4e6ce0");
extern "C" u32 THISCALL ext_4e7160_thiscall1(u32) __asm__("ext_4e7160");
extern "C" u32 THISCALL ext_4e8450_thiscall2(u32, u32) __asm__("ext_4e8450");
extern "C" u32 THISCALL ext_4f6b20_thiscall1(u32) __asm__("ext_4f6b20");
extern "C" u32 THISCALL ext_52cb60_thiscall3(u32, u32, u32) __asm__("ext_52cb60");
extern "C" u32 THISCALL ext_530fd0_thiscall2(u32, u32) __asm__("ext_530fd0");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5b6ab0_thiscall2(u32, u32) __asm__("ext_5b6ab0");
extern "C" u32 THISCALL ext_5b6d00_thiscall1(u32) __asm__("ext_5b6d00");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_46bca0_cdecl0(void) __asm__("ext_46bca0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)










extern "C" u32 THISCALL lifted_495c30(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6680d1);  // @h_495c30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_495c30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @2_495c30
  { u8 v = (u8)(((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }) != (u32)(0)) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_495c30
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @4_495c30
  eax = (u32)((s32)edi * (s32)(u32)(112));  // @5_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_495c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @7_495c30
  eax = (eax + (u32)(15));  // @8_495c30
  eax = (eax & (u32)(4294967280));  // @9_495c30
  PV[1] = (u32)(eax);  // @10_495c30
  eax = ext_4cd9b0_fastcall4(ecx, edx, PV[1], PV[0]);  // @11_495c30
  ecx = edx = 0;  // @12_495c30
  esi = eax;  // @13_495c30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_495c30
  if (esi != (u32)(-1)) goto L495ca5;  // @15_495c30
  eax = ext_42ab62_cdecl1((u32)(6874268));  // @16_495c30
  ecx = edx = 0;  // @17_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_495c30
  if ((ecx & ecx) == 0) goto L495ca4;  // @19_495c30
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @20_495c30
  ecx = edx = 0;  // @21_495c30
  goto L495ca5;  // @22_495c30
  L495ca4:;
  __builtin_trap();  // @24_495c30
  L495ca5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @26_495c30
  if ((ecx & ecx) == 0) goto L495cc4;  // @27_495c30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @28_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_495c30
  PV[2] = (u32)(edx);  // @30_495c30
  PV[3] = (u32)(esi);  // @31_495c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(6873924), PV[3], PV[2]);  // @32_495c30
  ecx = edx = 0;  // @33_495c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @34_495c30
  L495cc4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @36_495c30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_495c30
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @38_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @39_495c30
  eax = (eax + esi);  // @40_495c30
  PV[5] = (u32)(eax);  // @41_495c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[5], PV[4], (u32)(11468975));  // @42_495c30
  ecx = edx = 0;  // @43_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @44_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @45_495c30
  eax = (eax + esi);  // @46_495c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @47_495c30
  if ((edi & edi) == 0) goto L495d31;  // @48_495c30
  esi = eax;  // @49_495c30
  L495cf0:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @51_495c30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @52_495c30
  reg.state = (s32)((u32)(0));  // @53_495c30
  if ((esi & esi) == 0) goto L495d08;  // @54_495c30
  ecx = esi;  // @55_495c30
  eax = ext_4d93e0_thiscall1(ecx);  // @56_495c30
  ecx = edx = 0;  // @57_495c30
  L495d08:;
  reg.state = (s32)((u32)(4294967295));  // @59_495c30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L495d23;  // @60_495c30
  ecx = esi;  // @61_495c30
  eax = ext_4dc630_thiscall3(ecx, (u32)(134217728), (u32)(0));  // @62_495c30
  ecx = edx = 0;  // @63_495c30
  L495d23:;
  esi = (esi + (u32)(112));  // @65_495c30
  edi = (edi - (u32)(1));  // @66_495c30
  if (edi != 0) goto L495cf0;  // @67_495c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @68_495c30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @69_495c30
  L495d31:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @71_495c30
  ecx = (ecx + esi);  // @72_495c30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) >= ecx) goto L495d3e;  // @73_495c30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @74_495c30
  L495d3e:;
  SEH_LEAVE();  // @76_495c30
  return eax;  // @77_495c30
}
PCREG(495c30, lifted_495c30);

extern "C" u32 THISCALL lifted_498270(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66713b);  // @h_498270
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_498270
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_498270
  ecx = esi;  // @2_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_498270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(9));  // @4_498270
  ecx = edx = 0;  // @5_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @6_498270
  ecx = esi;  // @7_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_498270
  eax = (eax + (u32)(12));  // @9_498270
  PV[0] = (u32)(eax);  // @10_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[0], (u32)(4));  // @11_498270
  ecx = edx = 0;  // @12_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @13_498270
  ecx = esi;  // @14_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_498270
  eax = (eax + (u32)(16));  // @16_498270
  PV[1] = (u32)(eax);  // @17_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[1], (u32)(4));  // @18_498270
  ecx = edx = 0;  // @19_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @20_498270
  ecx = esi;  // @21_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_498270
  eax = (eax + (u32)(20));  // @23_498270
  PV[2] = (u32)(eax);  // @24_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[2], (u32)(4));  // @25_498270
  ecx = edx = 0;  // @26_498270
  ecx = (u32)(EBP - 188);  // @27_498270
  eax = ext_4ccba0_thiscall1(ecx);  // @28_498270
  ecx = edx = 0;  // @29_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_498270
  ecx = (u32)(EBP - 192);  // @31_498270
  PV[3] = (u32)(ecx);  // @32_498270
  ecx = esi;  // @33_498270
  reg.state = (s32)((u32)(0));  // @34_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[3], (u32)(4));  // @35_498270
  ecx = edx = 0;  // @36_498270
  edi = 0;  // @37_498270
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; }) == edi) goto L49833a;  // @38_498270
  L498310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_498270
  ecx = (u32)(EBP - 200);  // @41_498270
  PV[4] = (u32)(ecx);  // @42_498270
  ecx = esi;  // @43_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[4], (u32)(4));  // @44_498270
  ecx = edx = 0;  // @45_498270
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @46_498270
  ecx = (u32)(EBP - 188);  // @47_498270
  eax = ext_4cd540_thiscall2(ecx, PV[5]);  // @48_498270
  ecx = edx = 0;  // @49_498270
  edi = (edi + 1);  // @50_498270
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; })) goto L498310;  // @51_498270
  L49833a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @53_498270
  edx = (u32)(EBP - 188);  // @54_498270
  PV[6] = (u32)(edx);  // @55_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_498270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 36)))(ecx, PV[6]);  // @57_498270
  ecx = edx = 0;  // @58_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_498270
  ecx = (u32)(EBP - 196);  // @60_498270
  PV[7] = (u32)(ecx);  // @61_498270
  ecx = esi;  // @62_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[7], (u32)(4));  // @63_498270
  ecx = edx = 0;  // @64_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @65_498270
  ecx = esi;  // @66_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @67_498270
  eax = (eax << (u32)(2));  // @68_498270
  PV[8] = (u32)(eax);  // @69_498270
  eax = (u32)(EBP - 204);  // @70_498270
  PV[9] = (u32)(eax);  // @71_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[9], PV[8]);  // @72_498270
  ecx = edx = 0;  // @73_498270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @74_498270
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @75_498270
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @76_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[11], PV[10]);  // @78_498270
  ecx = edx = 0;  // @79_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_498270
  ecx = esi;  // @81_498270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(1280266803));  // @82_498270
  ecx = edx = 0;  // @83_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @84_498270
  ecx = esi;  // @85_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @87_498270
  eax = (u32)(eax*4 + 4);  // @88_498270
  PV[12] = (u32)(eax);  // @89_498270
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @90_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[13], PV[12]);  // @91_498270
  ecx = edx = 0;  // @92_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @93_498270
  esi = 0;  // @94_498270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @95_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @96_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @97_498270
  eax = (eax + (u32)(1));  // @98_498270
  if (eax == 0) goto L498406;  // @99_498270
  L4983c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @101_498270
  ecx = (u32)(eax + esi*4);  // @102_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_498270
  if (eax == (u32)(-1)) goto L4983f4;  // @104_498270
  eax = (u32)((s32)eax * (s32)(u32)(112));  // @105_498270
  eax = (eax + edi);  // @106_498270
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @107_498270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @108_498270
  if ((ecx & ecx) == 0) goto L4983fa;  // @109_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_498270
  eax = (u32)(esi*4);  // @111_498270
  PV[14] = (u32)(eax);  // @112_498270
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(6873948), PV[14], (u32)(4));  // @113_498270
  ecx = edx = 0;  // @114_498270
  goto L4983fa;  // @115_498270
  L4983f4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @117_498270
  L4983fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @119_498270
  esi = (esi + 1);  // @120_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @121_498270
  eax = (eax + 1);  // @122_498270
  if (esi != eax) goto L4983c0;  // @123_498270
  L498406:;
  ecx = (u32)(EBP - 188);  // @125_498270
  eax = ext_4ccf60_thiscall1(ecx);  // @126_498270
  ecx = edx = 0;  // @127_498270
  SEH_LEAVE();  // @128_498270
  ext_633654(G(u32, 0x6f5630));  // @129_498270
  return eax;  // @130_498270
}
PCREG(498270, lifted_498270);

extern "C" u32 lifted_4c8360(void) {
  SEH_ENTER(0x6690eb);  // @h_4c8360
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 128);  // @0_4c8360
  eax = ext_4e1b60_thiscall1(ecx);  // @1_4c8360
  ecx = edx = 0;  // @2_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4c8360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892260), (u32)(0), (u32)(6900440), (u32)(864));  // @6_4c8360
  ecx = edx = 0;  // @7_4c8360
  ecx = (u32)(EBP - 172);  // @8_4c8360
  esi = (eax & 0xffff);  // @9_4c8360
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(10240), (u32)(0));  // @10_4c8360
  ecx = edx = 0;  // @11_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4c8360
  reg.state = (s32)((u32)(0));  // @13_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @14_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @15_4c8360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @16_4c8360
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @17_4c8360
  if ((edx & edx) == 0) goto L4c843a;  // @18_4c8360
  L4c83f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @20_4c8360
  PV[0] = (u32)(edx);  // @21_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[0]);  // @23_4c8360
  ecx = edx = 0;  // @24_4c8360
  PV[1] = (u32)(eax);  // @25_4c8360
  ecx = (u32)(EBP - 172);  // @26_4c8360
  eax = ext_4cd540_thiscall2(ecx, PV[1]);  // @27_4c8360
  ecx = edx = 0;  // @28_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4c8360
  edx = (u32)(EBP - 132);  // @30_4c8360
  PV[2] = (u32)(edx);  // @31_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @33_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[2]);  // @35_4c8360
  ecx = edx = 0;  // @36_4c8360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @37_4c8360
  if ((edx & edx) == 0) goto L4c843a;  // @38_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4c8360
  goto L4c83f3;  // @40_4c8360
  L4c843a:;
  eax = (u32)(EBP - 144);  // @42_4c8360
  PV[3] = (u32)(eax);  // @43_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @44_4c8360
  ecx = (u32)(EBP - 172);  // @45_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @46_4c8360
  ecx = edx = 0;  // @47_4c8360
  eax = (u32)(EBP - 144);  // @48_4c8360
  PV[4] = (u32)(eax);  // @49_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @50_4c8360
  ecx = (u32)(EBP - 172);  // @51_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @52_4c8360
  ecx = edx = 0;  // @53_4c8360
  edx = eax;  // @54_4c8360
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; }) == (u32)(0)) goto L4c853b;  // @55_4c8360
  L4c8480:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_4c8360
  PV[5] = (u32)(edx);  // @58_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @59_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[5]);  // @61_4c8360
  ecx = edx = 0;  // @62_4c8360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @63_4c8360
  if ((eax & eax) == 0) goto L4c8516;  // @64_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_4c8360
  PV[6] = (u32)(eax);  // @66_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @67_4c8360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[6]);  // @69_4c8360
  ecx = edx = 0;  // @70_4c8360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @71_4c8360
  eax = (u32)(EBP - 128);  // @72_4c8360
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @73_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @74_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @75_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @76_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @77_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @78_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @79_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @80_4c8360
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @81_4c8360
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @82_4c8360
  if ((ecx & ecx) == 0) goto L4c8516;  // @83_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_4c8360
  edx = (u32)(EBP - 196);  // @85_4c8360
  PV[7] = (u32)(edx);  // @86_4c8360
  PV[8] = (u32)(esi);  // @87_4c8360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 296)))(ecx, PV[8], PV[7], (u32)(0));  // @88_4c8360
  ecx = edx = 0;  // @89_4c8360
  L4c8516:;
  eax = (u32)(EBP - 144);  // @91_4c8360
  PV[9] = (u32)(eax);  // @92_4c8360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @93_4c8360
  ecx = (u32)(EBP - 172);  // @94_4c8360
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @95_4c8360
  ecx = edx = 0;  // @96_4c8360
  edx = eax;  // @97_4c8360
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; }) != (u32)(0)) goto L4c8480;  // @98_4c8360
  L4c853b:;
  ecx = (u32)(EBP - 172);  // @100_4c8360
  eax = ext_4ccfe0_thiscall1(ecx);  // @101_4c8360
  ecx = edx = 0;  // @102_4c8360
  SEH_LEAVE();  // @103_4c8360
  ext_633654(G(u32, 0x6f5630));  // @104_4c8360
  return eax;  // @105_4c8360
}
PCREG(4c8360, lifted_4c8360);






extern "C" u32 THISCALL lifted_5b6e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c39e);  // @h_5b6e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @1_5b6e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @2_5b6e20
  eax = ext_5b6d00_thiscall1(ecx);  // @3_5b6e20
  ecx = edx = 0;  // @4_5b6e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5b6e20
  ecx = (u32)(EBP - 24);  // @6_5b6e20
  PV[0] = (u32)(ecx);  // @7_5b6e20
  ecx = esi;  // @8_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[0], (u32)(4));  // @10_5b6e20
  ecx = edx = 0;  // @11_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @12_5b6e20
  if ((eax & eax) == 0) goto L5b7078;  // @13_5b6e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_5b6e20
  if ((s32)(eax & eax) <= 0) goto L5b7078;  // @15_5b6e20
  L5b6e80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_5b6e20
  ecx = (u32)(EBP - 28);  // @18_5b6e20
  PV[1] = (u32)(ecx);  // @19_5b6e20
  ecx = esi;  // @20_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[1], (u32)(4));  // @21_5b6e20
  ecx = edx = 0;  // @22_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @23_5b6e20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @24_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[2]);  // @26_5b6e20
  ecx = edx = 0;  // @27_5b6e20
  edi = eax;  // @28_5b6e20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @29_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @30_5b6e20
  ecx = edx = 0;  // @31_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @32_5b6e20
  reg.state = (s32)((u32)(0));  // @33_5b6e20
  if ((eax & eax) == 0) goto L5b6ec2;  // @34_5b6e20
  ecx = eax;  // @35_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(29));  // @36_5b6e20
  ecx = edx = 0;  // @37_5b6e20
  goto L5b6ec4;  // @38_5b6e20
  L5b6ec2:;
  eax = 0;  // @40_5b6e20
  L5b6ec4:;
  reg.state = (s32)((u32)(4294967295));  // @42_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @44_5b6e20
  ecx = edx = 0;  // @45_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @46_5b6e20
  reg.state = (s32)((u32)(1));  // @47_5b6e20
  if ((eax & eax) == 0) goto L5b6ef2;  // @48_5b6e20
  ecx = eax;  // @49_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(32));  // @50_5b6e20
  ecx = edx = 0;  // @51_5b6e20
  goto L5b6ef4;  // @52_5b6e20
  L5b6ef2:;
  eax = 0;  // @54_5b6e20
  L5b6ef4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @56_5b6e20
  ecx = esi;  // @57_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_5b6e20
  eax = (u32)(edi + 56);  // @59_5b6e20
  PV[3] = (u32)(eax);  // @60_5b6e20
  reg.state = (s32)((u32)(4294967295));  // @61_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[3], (u32)(4));  // @62_5b6e20
  ecx = edx = 0;  // @63_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_5b6e20
  eax = (u32)(edi + 96);  // @65_5b6e20
  PV[4] = (u32)(eax);  // @66_5b6e20
  ecx = esi;  // @67_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[4], (u32)(36));  // @68_5b6e20
  ecx = edx = 0;  // @69_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_5b6e20
  eax = (u32)(edi + 72);  // @71_5b6e20
  PV[5] = (u32)(eax);  // @72_5b6e20
  ecx = esi;  // @73_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[5], (u32)(12));  // @74_5b6e20
  ecx = edx = 0;  // @75_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_5b6e20
  eax = (u32)(edi + 84);  // @77_5b6e20
  PV[6] = (u32)(eax);  // @78_5b6e20
  ecx = esi;  // @79_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[6], (u32)(12));  // @80_5b6e20
  ecx = edx = 0;  // @81_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_5b6e20
  eax = (u32)(edi + 60);  // @83_5b6e20
  PV[7] = (u32)(eax);  // @84_5b6e20
  ecx = esi;  // @85_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[7], (u32)(12));  // @86_5b6e20
  ecx = edx = 0;  // @87_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_5b6e20
  eax = (u32)(edi + 8);  // @89_5b6e20
  PV[8] = (u32)(eax);  // @90_5b6e20
  ecx = esi;  // @91_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[8], (u32)(48));  // @92_5b6e20
  ecx = edx = 0;  // @93_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @94_5b6e20
  eax = (u32)(edi + 132);  // @95_5b6e20
  PV[9] = (u32)(eax);  // @96_5b6e20
  ecx = esi;  // @97_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[9], (u32)(4));  // @98_5b6e20
  ecx = edx = 0;  // @99_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_5b6e20
  eax = (u32)(edi + 136);  // @101_5b6e20
  PV[10] = (u32)(eax);  // @102_5b6e20
  ecx = esi;  // @103_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[10], (u32)(4));  // @104_5b6e20
  ecx = edx = 0;  // @105_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_5b6e20
  eax = (u32)(edi + 140);  // @107_5b6e20
  PV[11] = (u32)(eax);  // @108_5b6e20
  ecx = esi;  // @109_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[11], (u32)(1));  // @110_5b6e20
  ecx = edx = 0;  // @111_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_5b6e20
  ecx = (u32)(EBP + 8);  // @113_5b6e20
  PV[12] = (u32)(ecx);  // @114_5b6e20
  ecx = esi;  // @115_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[12], (u32)(4));  // @116_5b6e20
  ecx = edx = 0;  // @117_5b6e20
  ebx = 0;  // @118_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b6ffd;  // @119_5b6e20
  L5b6f90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_5b6e20
  ecx = (u32)(EBP - 32);  // @122_5b6e20
  PV[13] = (u32)(ecx);  // @123_5b6e20
  ecx = esi;  // @124_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[13], (u32)(4));  // @125_5b6e20
  ecx = edx = 0;  // @126_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @127_5b6e20
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @128_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[14]);  // @130_5b6e20
  ecx = edx = 0;  // @131_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5b6e20
  edi = eax;  // @133_5b6e20
  PV[15] = (u32)(edi);  // @134_5b6e20
  ecx = esi;  // @135_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[15], (u32)(4));  // @136_5b6e20
  ecx = edx = 0;  // @137_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_5b6e20
  ecx = (u32)(edi + 4);  // @139_5b6e20
  PV[16] = (u32)(ecx);  // @140_5b6e20
  ecx = esi;  // @141_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[16], (u32)(4));  // @142_5b6e20
  ecx = edx = 0;  // @143_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_5b6e20
  eax = (u32)(edi + 8);  // @145_5b6e20
  PV[17] = (u32)(eax);  // @146_5b6e20
  ecx = esi;  // @147_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[17], (u32)(4));  // @148_5b6e20
  ecx = edx = 0;  // @149_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_5b6e20
  eax = (u32)(edi + 12);  // @151_5b6e20
  PV[18] = (u32)(eax);  // @152_5b6e20
  ecx = esi;  // @153_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[18], (u32)(1));  // @154_5b6e20
  ecx = edx = 0;  // @155_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_5b6e20
  eax = (u32)(edi + 13);  // @157_5b6e20
  PV[19] = (u32)(eax);  // @158_5b6e20
  ecx = esi;  // @159_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[19], (u32)(4));  // @160_5b6e20
  ecx = edx = 0;  // @161_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @162_5b6e20
  eax = (u32)(edi + 17);  // @163_5b6e20
  PV[20] = (u32)(eax);  // @164_5b6e20
  ecx = esi;  // @165_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[20], (u32)(12));  // @166_5b6e20
  ecx = edx = 0;  // @167_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @168_5b6e20
  ebx = (ebx + 1);  // @169_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b6f90;  // @170_5b6e20
  L5b6ffd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @172_5b6e20
  ecx = (u32)(EBP + 8);  // @173_5b6e20
  PV[21] = (u32)(ecx);  // @174_5b6e20
  ecx = esi;  // @175_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[21], (u32)(4));  // @176_5b6e20
  ecx = edx = 0;  // @177_5b6e20
  ebx = 0;  // @178_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b7065;  // @179_5b6e20
  L5b7011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @181_5b6e20
  ecx = (u32)(EBP - 36);  // @182_5b6e20
  PV[22] = (u32)(ecx);  // @183_5b6e20
  ecx = esi;  // @184_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[22], (u32)(4));  // @185_5b6e20
  ecx = edx = 0;  // @186_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @187_5b6e20
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @188_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[23]);  // @190_5b6e20
  ecx = edx = 0;  // @191_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_5b6e20
  edi = eax;  // @193_5b6e20
  PV[24] = (u32)(edi);  // @194_5b6e20
  ecx = esi;  // @195_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[24], (u32)(12));  // @196_5b6e20
  ecx = edx = 0;  // @197_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_5b6e20
  ecx = (u32)(edi + 12);  // @199_5b6e20
  PV[25] = (u32)(ecx);  // @200_5b6e20
  ecx = esi;  // @201_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[25], (u32)(12));  // @202_5b6e20
  ecx = edx = 0;  // @203_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @204_5b6e20
  eax = (u32)(edi + 28);  // @205_5b6e20
  PV[26] = (u32)(eax);  // @206_5b6e20
  ecx = esi;  // @207_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[26], (u32)(4));  // @208_5b6e20
  ecx = edx = 0;  // @209_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @210_5b6e20
  eax = (u32)(edi + 24);  // @211_5b6e20
  PV[27] = (u32)(eax);  // @212_5b6e20
  ecx = esi;  // @213_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[27], (u32)(4));  // @214_5b6e20
  ecx = edx = 0;  // @215_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @216_5b6e20
  ebx = (ebx + 1);  // @217_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b7011;  // @218_5b6e20
  L5b7065:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @220_5b6e20
  ebx = (ebx + 1);  // @221_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @222_5b6e20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @223_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5b6e80;  // @224_5b6e20
  L5b7078:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @226_5b6e20
  SEH_LEAVE();  // @227_5b6e20
  return eax;  // @228_5b6e20
}
PCREG(5b6e20, lifted_5b6e20);

extern "C" u32 lifted_49e680(void) {
  SEH_ENTER(0x66847f);  // @h_49e680
  u8 F[0x16430] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x16330);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(EBP - 111);  // @0_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340924), &v, sizeof v); }  // @1_49e680
  PV[0] = (u32)(eax);  // @2_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340884), &v, sizeof v); }  // @3_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340876), &v, sizeof v); }  // @4_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7341424), &v, sizeof v); }  // @5_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7341428), &v, sizeof v); }  // @6_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7341420), &v, sizeof v); }  // @7_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340860), &v, sizeof v); }  // @8_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340864), &v, sizeof v); }  // @9_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340868), &v, sizeof v); }  // @10_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340928), &v, sizeof v); }  // @11_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340932), &v, sizeof v); }  // @12_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340880), &v, sizeof v); }  // @13_49e680
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(7340936), &v, sizeof v); }  // @14_49e680
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(93));  // @15_49e680
  ecx = edx = 0;  // @16_49e680
  ecx = (u32)(EBP - 111);  // @17_49e680
  eax = ext_469870_thiscall1(ecx);  // @18_49e680
  ecx = edx = 0;  // @19_49e680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 107), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 107), &v, sizeof v); }  // @20_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 43), &v, sizeof v); }  // @21_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 63), &v, sizeof v); }  // @22_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_49e680
  edx = (u32)(EBP - 111);  // @24_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 111), &v, sizeof v); }  // @25_49e680
  PV[1] = (u32)(edx);  // @26_49e680
  reg.state = (s32)((u32)(0));  // @27_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[1]);  // @30_49e680
  ecx = edx = 0;  // @31_49e680
  ecx = (u32)(EBP - 106);  // @32_49e680
  reg.state = (s32)((u32)(4294967295));  // @33_49e680
  eax = ext_4b8610_thiscall1(ecx);  // @34_49e680
  ecx = edx = 0;  // @35_49e680
  ecx = (u32)(EBP - 106);  // @36_49e680
  eax = ext_4b86b0_thiscall1(ecx);  // @37_49e680
  ecx = edx = 0;  // @38_49e680
  ecx = (u32)(EBP - 120);  // @39_49e680
  eax = ext_4a4700_thiscall1(ecx);  // @40_49e680
  ecx = edx = 0;  // @41_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @42_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @43_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_49e680
  edx = (u32)(EBP - 120);  // @45_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @46_49e680
  PV[2] = (u32)(edx);  // @47_49e680
  reg.state = (s32)((u32)(1));  // @48_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[2]);  // @51_49e680
  ecx = edx = 0;  // @52_49e680
  ecx = (u32)(EBP - 232);  // @53_49e680
  reg.state = (s32)((u32)(4294967295));  // @54_49e680
  eax = ext_4a4fb0_thiscall1(ecx);  // @55_49e680
  ecx = edx = 0;  // @56_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @57_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @58_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_49e680
  edx = (u32)(EBP - 232);  // @60_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @61_49e680
  PV[3] = (u32)(edx);  // @62_49e680
  reg.state = (s32)((u32)(2));  // @63_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[3]);  // @66_49e680
  ecx = edx = 0;  // @67_49e680
  ecx = (u32)(EBP - 328);  // @68_49e680
  reg.state = (s32)((u32)(4294967295));  // @69_49e680
  eax = ext_4a6270_thiscall1(ecx);  // @70_49e680
  ecx = edx = 0;  // @71_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @72_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @73_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_49e680
  edx = (u32)(EBP - 328);  // @75_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @76_49e680
  PV[4] = (u32)(edx);  // @77_49e680
  reg.state = (s32)((u32)(3));  // @78_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[4]);  // @81_49e680
  ecx = edx = 0;  // @82_49e680
  reg.state = (s32)((u32)(4294967295));  // @83_49e680
  ecx = (u32)(EBP - 148);  // @84_49e680
  eax = ext_4a7960_thiscall1(ecx);  // @85_49e680
  ecx = edx = 0;  // @86_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @87_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @88_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_49e680
  edx = (u32)(EBP - 148);  // @90_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @91_49e680
  PV[5] = (u32)(edx);  // @92_49e680
  reg.state = (s32)((u32)(4));  // @93_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @94_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[5]);  // @96_49e680
  ecx = edx = 0;  // @97_49e680
  ecx = (u32)(EBP - 232);  // @98_49e680
  reg.state = (s32)((u32)(4294967295));  // @99_49e680
  eax = ext_4a86c0_thiscall1(ecx);  // @100_49e680
  ecx = edx = 0;  // @101_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @102_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @103_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @104_49e680
  edx = (u32)(EBP - 232);  // @105_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @106_49e680
  PV[6] = (u32)(edx);  // @107_49e680
  reg.state = (s32)((u32)(5));  // @108_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @109_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[6]);  // @111_49e680
  ecx = edx = 0;  // @112_49e680
  ecx = (u32)(EBP - 90860);  // @113_49e680
  reg.state = (s32)((u32)(4294967295));  // @114_49e680
  eax = ext_4a9600_thiscall1(ecx);  // @115_49e680
  ecx = edx = 0;  // @116_49e680
  ecx = (u32)(EBP - 90860);  // @117_49e680
  eax = ext_4a9880_thiscall1(ecx);  // @118_49e680
  ecx = edx = 0;  // @119_49e680
  ecx = (u32)(EBP - 284);  // @120_49e680
  eax = ext_49f2d0_thiscall1(ecx);  // @121_49e680
  ecx = edx = 0;  // @122_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 216), &v, sizeof v); }  // @123_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 236), &v, sizeof v); }  // @124_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_49e680
  edx = (u32)(EBP - 284);  // @126_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @127_49e680
  PV[7] = (u32)(edx);  // @128_49e680
  reg.state = (s32)((u32)(6));  // @129_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @130_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[7]);  // @132_49e680
  ecx = edx = 0;  // @133_49e680
  ecx = (u32)(EBP - 90);  // @134_49e680
  reg.state = (s32)((u32)(4294967295));  // @135_49e680
  eax = ext_4ae4f0_thiscall1(ecx);  // @136_49e680
  ecx = edx = 0;  // @137_49e680
  ecx = (u32)(EBP - 90);  // @138_49e680
  eax = ext_4f6b20_thiscall1(ecx);  // @139_49e680
  ecx = edx = 0;  // @140_49e680
  ecx = (u32)(EBP - 64);  // @141_49e680
  eax = ext_4e7160_thiscall1(ecx);  // @142_49e680
  ecx = edx = 0;  // @143_49e680
  ecx = (u32)(EBP - 114);  // @144_49e680
  eax = ext_4af440_thiscall1(ecx);  // @145_49e680
  ecx = edx = 0;  // @146_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 46), &v, sizeof v); }  // @147_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 66), &v, sizeof v); }  // @148_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_49e680
  edx = (u32)(EBP - 114);  // @150_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 114), &v, sizeof v); }  // @151_49e680
  PV[8] = (u32)(edx);  // @152_49e680
  reg.state = (s32)((u32)(7));  // @153_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @154_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[8]);  // @156_49e680
  ecx = edx = 0;  // @157_49e680
  ecx = (u32)(EBP - 108);  // @158_49e680
  reg.state = (s32)((u32)(4294967295));  // @159_49e680
  eax = ext_4b1c70_thiscall1(ecx);  // @160_49e680
  ecx = edx = 0;  // @161_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @162_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @163_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @164_49e680
  edx = (u32)(EBP - 108);  // @165_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @166_49e680
  PV[9] = (u32)(edx);  // @167_49e680
  reg.state = (s32)((u32)(8));  // @168_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @169_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[9]);  // @171_49e680
  ecx = edx = 0;  // @172_49e680
  reg.state = (s32)((u32)(4294967295));  // @173_49e680
  eax = (u32)(EBP - 308);  // @174_49e680
  PV[10] = (u32)(eax);  // @175_49e680
  eax = ext_634d10_cdecl3(PV[10], (u32)(0), (u32)(290));  // @176_49e680
  ecx = edx = 0;  // @177_49e680
  ecx = (u32)(EBP - 308);  // @178_49e680
  eax = ext_469870_thiscall1(ecx);  // @179_49e680
  ecx = edx = 0;  // @180_49e680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @181_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @182_49e680
  ecx = (u32)(EBP - 207);  // @183_49e680
  reg.state = (s32)((u32)(9));  // @184_49e680
  { u32 v = (u32)((u32)(6877320)); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @185_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 235), &v, sizeof v); }  // @186_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 231), &v, sizeof v); }  // @187_49e680
  { u32 v = (u32)((u32)(6877288)); __builtin_memcpy((void *)(u32)(EBP - 219), &v, sizeof v); }  // @188_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @189_49e680
  ecx = edx = 0;  // @190_49e680
  ecx = (u32)(EBP - 219);  // @191_49e680
  eax = ext_4e6ce0_thiscall1(ecx);  // @192_49e680
  ecx = edx = 0;  // @193_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @194_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @195_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @196_49e680
  edx = (u32)(EBP - 308);  // @197_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @198_49e680
  PV[11] = (u32)(edx);  // @199_49e680
  reg.state = (s32)((u32)(10));  // @200_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @201_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[11]);  // @203_49e680
  ecx = edx = 0;  // @204_49e680
  ecx = (u32)(EBP - 106);  // @205_49e680
  reg.state = (s32)((u32)(4294967295));  // @206_49e680
  eax = ext_4a80a0_thiscall1(ecx);  // @207_49e680
  ecx = edx = 0;  // @208_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 38), &v, sizeof v); }  // @209_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 58), &v, sizeof v); }  // @210_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @211_49e680
  edx = (u32)(EBP - 106);  // @212_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 106), &v, sizeof v); }  // @213_49e680
  PV[12] = (u32)(edx);  // @214_49e680
  reg.state = (s32)((u32)(11));  // @215_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @216_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @217_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[12]);  // @218_49e680
  ecx = edx = 0;  // @219_49e680
  eax = (u32)(EBP - 644);  // @220_49e680
  reg.state = (s32)((u32)(4294967295));  // @221_49e680
  PV[13] = (u32)(eax);  // @222_49e680
  eax = ext_634d10_cdecl3(PV[13], (u32)(0), (u32)(626));  // @223_49e680
  ecx = edx = 0;  // @224_49e680
  ecx = (u32)(EBP - 644);  // @225_49e680
  eax = ext_469870_thiscall1(ecx);  // @226_49e680
  ecx = edx = 0;  // @227_49e680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 640), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 640), &v, sizeof v); }  // @228_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 576), &v, sizeof v); }  // @229_49e680
  ecx = (u32)(EBP - 534);  // @230_49e680
  reg.state = (s32)((u32)(12));  // @231_49e680
  { u32 v = (u32)((u32)(6877600)); __builtin_memcpy((void *)(u32)(EBP - 644), &v, sizeof v); }  // @232_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @233_49e680
  ecx = edx = 0;  // @234_49e680
  ecx = (u32)(EBP - 362);  // @235_49e680
  reg.state = (s32)((u32)(13));  // @236_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @237_49e680
  ecx = edx = 0;  // @238_49e680
  ecx = (u32)(EBP - 190);  // @239_49e680
  reg.state = (s32)((u32)(14));  // @240_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @241_49e680
  ecx = edx = 0;  // @242_49e680
  ecx = (u32)(EBP - 190);  // @243_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @244_49e680
  ecx = edx = 0;  // @245_49e680
  ecx = (u32)(EBP - 362);  // @246_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @247_49e680
  ecx = edx = 0;  // @248_49e680
  ecx = (u32)(EBP - 534);  // @249_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @250_49e680
  ecx = edx = 0;  // @251_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 576), &v, sizeof v); }  // @252_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 596), &v, sizeof v); }  // @253_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @254_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 644), &v, sizeof v); }  // @255_49e680
  reg.state = (s32)((u32)(15));  // @256_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @257_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_49e680
  edx = (u32)(EBP - 644);  // @259_49e680
  PV[14] = (u32)(edx);  // @260_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[14]);  // @261_49e680
  ecx = edx = 0;  // @262_49e680
  eax = (u32)(EBP - 102);  // @263_49e680
  reg.state = (s32)((u32)(4294967295));  // @264_49e680
  PV[15] = (u32)(eax);  // @265_49e680
  eax = ext_634d10_cdecl3(PV[15], (u32)(0), (u32)(84));  // @266_49e680
  ecx = edx = 0;  // @267_49e680
  ecx = (u32)(EBP - 102);  // @268_49e680
  eax = ext_469870_thiscall1(ecx);  // @269_49e680
  ecx = edx = 0;  // @270_49e680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 98), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 98), &v, sizeof v); }  // @271_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @272_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 54), &v, sizeof v); }  // @273_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @274_49e680
  edx = (u32)(EBP - 102);  // @275_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 102), &v, sizeof v); }  // @276_49e680
  PV[16] = (u32)(edx);  // @277_49e680
  reg.state = (s32)((u32)(16));  // @278_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @279_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @280_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[16]);  // @281_49e680
  ecx = edx = 0;  // @282_49e680
  ecx = (u32)(EBP - 180);  // @283_49e680
  reg.state = (s32)((u32)(4294967295));  // @284_49e680
  eax = ext_4b8fd0_thiscall1(ecx);  // @285_49e680
  ecx = edx = 0;  // @286_49e680
  ecx = (u32)(EBP - 180);  // @287_49e680
  eax = ext_4b9160_thiscall1(ecx);  // @288_49e680
  ecx = edx = 0;  // @289_49e680
  ecx = (u32)(EBP - 136);  // @290_49e680
  eax = ext_4baeb0_thiscall1(ecx);  // @291_49e680
  ecx = edx = 0;  // @292_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @293_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @294_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @295_49e680
  edx = (u32)(EBP - 136);  // @296_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @297_49e680
  PV[17] = (u32)(edx);  // @298_49e680
  reg.state = (s32)((u32)(17));  // @299_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @300_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @301_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[17]);  // @302_49e680
  ecx = edx = 0;  // @303_49e680
  ecx = (u32)(EBP - 100);  // @304_49e680
  reg.state = (s32)((u32)(4294967295));  // @305_49e680
  eax = ext_4bb160_thiscall1(ecx);  // @306_49e680
  ecx = edx = 0;  // @307_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @308_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @309_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @310_49e680
  edx = (u32)(EBP - 100);  // @311_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @312_49e680
  PV[18] = (u32)(edx);  // @313_49e680
  reg.state = (s32)((u32)(18));  // @314_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @315_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @316_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[18]);  // @317_49e680
  ecx = edx = 0;  // @318_49e680
  ecx = (u32)(EBP - 107);  // @319_49e680
  reg.state = (s32)((u32)(4294967295));  // @320_49e680
  eax = ext_4bb350_thiscall1(ecx);  // @321_49e680
  ecx = edx = 0;  // @322_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 39), &v, sizeof v); }  // @323_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 59), &v, sizeof v); }  // @324_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @325_49e680
  edx = (u32)(EBP - 107);  // @326_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 107), &v, sizeof v); }  // @327_49e680
  PV[19] = (u32)(edx);  // @328_49e680
  reg.state = (s32)((u32)(19));  // @329_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @330_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @331_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[19]);  // @332_49e680
  ecx = edx = 0;  // @333_49e680
  ecx = (u32)(EBP - 364);  // @334_49e680
  reg.state = (s32)((u32)(4294967295));  // @335_49e680
  eax = ext_4a3280_thiscall1(ecx);  // @336_49e680
  ecx = edx = 0;  // @337_49e680
  ecx = (u32)(EBP - 364);  // @338_49e680
  eax = ext_4a3360_thiscall1(ecx);  // @339_49e680
  ecx = edx = 0;  // @340_49e680
  ecx = (u32)(EBP - 436);  // @341_49e680
  eax = ext_469870_thiscall1(ecx);  // @342_49e680
  ecx = edx = 0;  // @343_49e680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @344_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @345_49e680
  reg.state = (s32)((u32)(20));  // @346_49e680
  ecx = (u32)(EBP - 364);  // @347_49e680
  { u32 v = (u32)((u32)(6878052)); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @348_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @349_49e680
  ecx = edx = 0;  // @350_49e680
  ecx = (u32)(EBP - 192);  // @351_49e680
  reg.state = (s32)((u32)(21));  // @352_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @353_49e680
  ecx = edx = 0;  // @354_49e680
  ecx = (u32)(EBP - 192);  // @355_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @356_49e680
  ecx = edx = 0;  // @357_49e680
  ecx = (u32)(EBP - 364);  // @358_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @359_49e680
  ecx = edx = 0;  // @360_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @361_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 388), &v, sizeof v); }  // @362_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @363_49e680
  edx = (u32)(EBP - 436);  // @364_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @365_49e680
  PV[20] = (u32)(edx);  // @366_49e680
  reg.state = (s32)((u32)(22));  // @367_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @368_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @369_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[20]);  // @370_49e680
  ecx = edx = 0;  // @371_49e680
  eax = (u32)(EBP - 320);  // @372_49e680
  reg.state = (s32)((u32)(4294967295));  // @373_49e680
  PV[21] = (u32)(eax);  // @374_49e680
  eax = ext_634d10_cdecl3(PV[21], (u32)(0), (u32)(300));  // @375_49e680
  ecx = edx = 0;  // @376_49e680
  ecx = (u32)(EBP - 320);  // @377_49e680
  eax = ext_469870_thiscall1(ecx);  // @378_49e680
  ecx = edx = 0;  // @379_49e680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @380_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 252), &v, sizeof v); }  // @381_49e680
  ecx = (u32)(EBP - 200);  // @382_49e680
  reg.state = (s32)((u32)(23));  // @383_49e680
  { u32 v = (u32)((u32)(6877456)); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @384_49e680
  eax = ext_4ccba0_thiscall1(ecx);  // @385_49e680
  ecx = edx = 0;  // @386_49e680
  ecx = (u32)(EBP - 200);  // @387_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @388_49e680
  ecx = edx = 0;  // @389_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 252), &v, sizeof v); }  // @390_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @391_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @392_49e680
  edx = (u32)(EBP - 320);  // @393_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @394_49e680
  PV[22] = (u32)(edx);  // @395_49e680
  reg.state = (s32)((u32)(24));  // @396_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @397_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @398_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[22]);  // @399_49e680
  ecx = edx = 0;  // @400_49e680
  ecx = (u32)(EBP - 1124);  // @401_49e680
  reg.state = (s32)((u32)(4294967295));  // @402_49e680
  eax = ext_4a3b40_thiscall1(ecx);  // @403_49e680
  ecx = edx = 0;  // @404_49e680
  ecx = (u32)(EBP - 860);  // @405_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @406_49e680
  ecx = edx = 0;  // @407_49e680
  ecx = (u32)(EBP - 1032);  // @408_49e680
  eax = ext_4ccf60_thiscall1(ecx);  // @409_49e680
  ecx = edx = 0;  // @410_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1056), &v, sizeof v); }  // @411_49e680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1076), &v, sizeof v); }  // @412_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @413_49e680
  edx = (u32)(EBP - 1124);  // @414_49e680
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 1124), &v, sizeof v); }  // @415_49e680
  PV[23] = (u32)(edx);  // @416_49e680
  reg.state = (s32)((u32)(25));  // @417_49e680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @418_49e680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @419_49e680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[23]);  // @420_49e680
  ecx = edx = 0;  // @421_49e680
  SEH_LEAVE();  // @422_49e680
  ext_633654(G(u32, 0x6f5630));  // @423_49e680
  return eax;  // @424_49e680
}
PCREG(49e680, lifted_49e680);








