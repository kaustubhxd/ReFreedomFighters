// batch218009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_49f9b0_fastcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_49f9b0");
extern "C" u32 FASTCALL ext_4cd9b0_fastcall4(u32, u32, u32, u32) __asm__("ext_4cd9b0");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_436640_thiscall3(u32, u32, u32) __asm__("ext_436640");
extern "C" u32 THISCALL ext_4368b0_thiscall3(u32, u32, u32) __asm__("ext_4368b0");
extern "C" u32 THISCALL ext_436a80_thiscall3(u32, u32, u32) __asm__("ext_436a80");
extern "C" u32 THISCALL ext_45c560_thiscall2(u32, u32) __asm__("ext_45c560");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4d9350_thiscall3(u32, u32, u32) __asm__("ext_4d9350");
extern "C" u32 THISCALL ext_4d93e0_thiscall1(u32) __asm__("ext_4d93e0");
extern "C" u32 THISCALL ext_4db2c0_thiscall3(u32, u32, u32) __asm__("ext_4db2c0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" u32 ext_46bca0_cdecl0(void) __asm__("ext_46bca0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)


extern "C" u32 THISCALL lifted_4370a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665a0d);  // @h_4370a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4370a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4370a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4370a0
  ecx = ebx;  // @3_4370a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_4370a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @5_4370a0
  ecx = edx = 0;  // @6_4370a0
  PV[0] = (u32)(eax);  // @7_4370a0
  ecx = edi;  // @8_4370a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 16)))(ecx, PV[0]);  // @9_4370a0
  ecx = edx = 0;  // @10_4370a0
  if ((eax & eax) == 0) goto L4370f7;  // @11_4370a0
  eax = 0;  // @12_4370a0
  SEH_LEAVE();  // @13_4370a0
  return eax;  // @14_4370a0
  L4370f7:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 165), sizeof v); (u32)v; }) == (u32)(0)) goto L437125;  // @16_4370a0
  eax = ext_41e290_cdecl1((u32)(18));  // @17_4370a0
  ecx = edx = 0;  // @18_4370a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_4370a0
  reg.state = (s32)((u32)(0));  // @20_4370a0
  if ((eax & eax) == 0) goto L437153;  // @21_4370a0
  PV[1] = (u32)(ebx);  // @22_4370a0
  PV[2] = (u32)(edi);  // @23_4370a0
  ecx = eax;  // @24_4370a0
  eax = ext_4368b0_thiscall3(ecx, PV[2], PV[1]);  // @25_4370a0
  ecx = edx = 0;  // @26_4370a0
  edi = eax;  // @27_4370a0
  goto L437155;  // @28_4370a0
  L437125:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 166), sizeof v); (u32)v; }) == (u32)(0)) goto L437181;  // @30_4370a0
  eax = ext_41e290_cdecl1((u32)(26));  // @31_4370a0
  ecx = edx = 0;  // @32_4370a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @33_4370a0
  reg.state = (s32)((u32)(1));  // @34_4370a0
  if ((eax & eax) == 0) goto L437153;  // @35_4370a0
  PV[3] = (u32)(ebx);  // @36_4370a0
  PV[4] = (u32)(edi);  // @37_4370a0
  ecx = eax;  // @38_4370a0
  eax = ext_436a80_thiscall3(ecx, PV[4], PV[3]);  // @39_4370a0
  ecx = edx = 0;  // @40_4370a0
  edi = eax;  // @41_4370a0
  goto L437155;  // @42_4370a0
  L437153:;
  edi = 0;  // @44_4370a0
  L437155:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @46_4370a0
  PV[5] = (u32)(edi);  // @47_4370a0
  reg.state = (s32)((u32)(4294967295));  // @48_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @49_4370a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4370a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[5]);  // @51_4370a0
  ecx = edx = 0;  // @52_4370a0
  PV[6] = (u32)(edi);  // @53_4370a0
  ecx = ebx;  // @54_4370a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @55_4370a0
  ecx = edx = 0;  // @56_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @57_4370a0
  PV[7] = (u32)(eax);  // @58_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @59_4370a0
  eax = ext_4d9350_thiscall3(ecx, PV[7], PV[6]);  // @60_4370a0
  ecx = edx = 0;  // @61_4370a0
  goto L4371ed;  // @62_4370a0
  L437181:;
  eax = ext_41e290_cdecl1((u32)(74));  // @64_4370a0
  ecx = edx = 0;  // @65_4370a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @66_4370a0
  reg.state = (s32)((u32)(2));  // @67_4370a0
  if ((eax & eax) == 0) goto L4371a7;  // @68_4370a0
  PV[8] = (u32)(ebx);  // @69_4370a0
  ecx = (u32)(edi + 4);  // @70_4370a0
  PV[9] = (u32)(ecx);  // @71_4370a0
  ecx = eax;  // @72_4370a0
  eax = ext_436640_thiscall3(ecx, PV[9], PV[8]);  // @73_4370a0
  ecx = edx = 0;  // @74_4370a0
  goto L4371a9;  // @75_4370a0
  L4371a7:;
  eax = 0;  // @77_4370a0
  L4371a9:;
  ecx = 0;  // @79_4370a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @80_4370a0
  edi = (u32)(eax + 4);  // @81_4370a0
  reg.state = (s32)((u32)(4294967295));  // @82_4370a0
  esi = edi;  // @83_4370a0
  if ((eax & eax) == 0) esi = ecx;  // @84_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @85_4370a0
  PV[10] = (u32)(esi);  // @86_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 25), sizeof v); (u32)v; });  // @87_4370a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_4370a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[10]);  // @89_4370a0
  ecx = edx = 0;  // @90_4370a0
  PV[11] = (u32)(esi);  // @91_4370a0
  ecx = ebx;  // @92_4370a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @93_4370a0
  ecx = edx = 0;  // @94_4370a0
  PV[12] = (u32)(eax);  // @95_4370a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @96_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 17), sizeof v); (u32)v; });  // @97_4370a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @98_4370a0
  eax = ext_4d9350_thiscall3(ecx, PV[12], PV[11]);  // @99_4370a0
  ecx = edx = 0;  // @100_4370a0
  eax = 0;  // @101_4370a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == eax) edi = eax;  // @102_4370a0
  L4371ed:;
  eax = edi;  // @104_4370a0
  SEH_LEAVE();  // @105_4370a0
  return eax;  // @106_4370a0
}
PCREG(4370a0, lifted_4370a0);

extern "C" u32 STDCALL lifted_468d80(u32 a0) {
  SEH_ENTER(0x66bdd6);  // @h_468d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_468d80
  ecx = esi;  // @1_468d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_468d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @3_468d80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050578));  // @4_468d80
  ecx = edx = 0;  // @5_468d80
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L468e37;  // @6_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @7_468d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_468d80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(4243));  // @9_468d80
  ecx = edx = 0;  // @10_468d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_468d80
  ebx = eax;  // @12_468d80
  eax = (u32)(EBP - 144);  // @13_468d80
  ecx = esi;  // @14_468d80
  PV[0] = (u32)(eax);  // @15_468d80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[0], (u32)(1));  // @16_468d80
  ecx = edx = 0;  // @17_468d80
  edi = eax;  // @18_468d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_468d80
  ecx = esi;  // @20_468d80
  reg.state = (s32)((u32)(0));  // @21_468d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @22_468d80
  ecx = edx = 0;  // @23_468d80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_468d80
  edx = (u32)(6801640);  // @25_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @26_468d80
  if ((ecx & ecx) != 0) edx = ecx;  // @27_468d80
  ecx = edi;  // @28_468d80
  PV[1] = (u32)(edx);  // @29_468d80
  eax = ext_4cc1d0_thiscall1(ecx);  // @30_468d80
  ecx = edx = 0;  // @31_468d80
  PV[2] = (u32)(eax);  // @32_468d80
  PV[3] = (u32)(ebx);  // @33_468d80
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 48)))(PV[3], (u32)(6852516), PV[2], PV[1]);  // @34_468d80
  ecx = edx = 0;  // @35_468d80
  ecx = (u32)(EBP - 144);  // @36_468d80
  eax = ext_4cbec0_thiscall1(ecx);  // @37_468d80
  ecx = edx = 0;  // @38_468d80
  goto L468ef4;  // @39_468d80
  L468e37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_468d80
  ecx = esi;  // @42_468d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 808)))(ecx);  // @43_468d80
  ecx = edx = 0;  // @44_468d80
  edi = eax;  // @45_468d80
  if ((edi & edi) != 0) goto L468eb5;  // @46_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @47_468d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_468d80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(4251));  // @49_468d80
  ecx = edx = 0;  // @50_468d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_468d80
  ebx = eax;  // @52_468d80
  eax = (u32)(EBP - 272);  // @53_468d80
  ecx = esi;  // @54_468d80
  PV[4] = (u32)(eax);  // @55_468d80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[4], (u32)(1));  // @56_468d80
  ecx = edx = 0;  // @57_468d80
  edi = eax;  // @58_468d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_468d80
  ecx = esi;  // @60_468d80
  reg.state = (s32)((u32)(1));  // @61_468d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @62_468d80
  ecx = edx = 0;  // @63_468d80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_468d80
  edx = (u32)(6801640);  // @65_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @66_468d80
  if ((ecx & ecx) != 0) edx = ecx;  // @67_468d80
  ecx = edi;  // @68_468d80
  PV[5] = (u32)(edx);  // @69_468d80
  eax = ext_4cc1d0_thiscall1(ecx);  // @70_468d80
  ecx = edx = 0;  // @71_468d80
  PV[6] = (u32)(eax);  // @72_468d80
  PV[7] = (u32)(ebx);  // @73_468d80
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 48)))(PV[7], (u32)(6852556), PV[6], PV[5]);  // @74_468d80
  ecx = edx = 0;  // @75_468d80
  ecx = (u32)(EBP - 272);  // @76_468d80
  eax = ext_4cbec0_thiscall1(ecx);  // @77_468d80
  ecx = edx = 0;  // @78_468d80
  goto L468ef4;  // @79_468d80
  L468eb5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_468d80
  ecx = edi;  // @82_468d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 824)))(ecx);  // @83_468d80
  ecx = edx = 0;  // @84_468d80
  if ((eax & eax) != 0) goto L468ef6;  // @85_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_468d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_468d80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(4258));  // @88_468d80
  ecx = edx = 0;  // @89_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @90_468d80
  edx = (u32)(6801640);  // @91_468d80
  if ((ecx & ecx) != 0) edx = ecx;  // @92_468d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @93_468d80
  PV[8] = (u32)(edx);  // @94_468d80
  PV[9] = (u32)(eax);  // @95_468d80
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 48)))(PV[9], (u32)(6852640), PV[8]);  // @96_468d80
  ecx = edx = 0;  // @97_468d80
  L468ef4:;
  eax = 0;  // @99_468d80
  L468ef6:;
  SEH_LEAVE();  // @101_468d80
  ext_633654(G(u32, 0x6f5630));  // @102_468d80
  return eax;  // @103_468d80
}
PCREG(468d80, lifted_468d80);



extern "C" u32 THISCALL lifted_6166c0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e658);  // @h_6166c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @0_6166c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6166c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6166c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @3_6166c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @4_6166c0
  { u32 v = (u32)((u32)(7069160)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @5_6166c0
  eax = (u32)(ecx + 12);  // @6_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @7_6166c0
  edi = (u32)(ecx + 36);  // @8_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @9_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @11_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @12_6166c0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47536), sizeof v); (u32)v; });  // @13_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47524), sizeof v); (u32)v; });  // @14_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_6166c0
  reg.state = (s32)((u32)(0));  // @17_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @18_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @19_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @20_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @21_6166c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @23_6166c0
  eax = (eax + ecx);  // @24_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_6166c0
  PV[1] = (u32)(eax);  // @26_6166c0
  eax = ext_659220_thiscall3(ecx, PV[1], PV[0]);  // @27_6166c0
  ecx = edx = 0;  // @28_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @29_6166c0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47528), sizeof v); (u32)v; });  // @30_6166c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @31_6166c0
  ecx = edi;  // @32_6166c0
  ebx = eax;  // @33_6166c0
  PV[3] = (u32)(ebx);  // @34_6166c0
  eax = ext_659330_thiscall3(ecx, PV[3], PV[2]);  // @35_6166c0
  ecx = edx = 0;  // @36_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5114), sizeof v); (u32)v; });  // @37_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @38_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @39_6166c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @40_6166c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @41_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) == (u32)(0)) goto L616815;  // @42_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L6167aa;  // @43_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_6166c0
  ecx = edi;  // @45_6166c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @46_6166c0
  ecx = edx = 0;  // @47_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @48_6166c0
  L6167aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @50_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @51_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @52_6166c0
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @53_6166c0
  ecx = (u32)(eax + eax*8);  // @54_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @55_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @56_6166c0
  eax = (u32)(eax + ecx*4);  // @57_6166c0
  if ((ebx & ebx) == 0) goto L616812;  // @58_6166c0
  edx = (u32)(edi + 12);  // @59_6166c0
  edi = (edi - eax);  // @60_6166c0
  ecx = (u32)(eax + 4);  // @61_6166c0
  L6167d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 12), sizeof v); (u32)v; });  // @63_6166c0
  edx = (u32)(edx + 36);  // @64_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @65_6166c0
  ecx = (u32)(ecx + 36);  // @66_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx - 36), sizeof v); (u32)v; });  // @67_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 36), &v, sizeof v); }  // @68_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 40), sizeof v); (u32)v; });  // @69_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 32), &v, sizeof v); }  // @70_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 36), sizeof v); (u32)v; });  // @71_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 28), &v, sizeof v); }  // @72_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 32), sizeof v); (u32)v; });  // @73_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 24), &v, sizeof v); }  // @74_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 28), sizeof v); (u32)v; });  // @75_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 20), &v, sizeof v); }  // @76_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 24), sizeof v); (u32)v; });  // @77_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 16), &v, sizeof v); }  // @78_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 20), sizeof v); (u32)v; });  // @79_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 12), &v, sizeof v); }  // @80_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 16), sizeof v); (u32)v; });  // @81_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 8), &v, sizeof v); }  // @82_6166c0
  ebx = (ebx - (u32)(1));  // @83_6166c0
  if (ebx != 0) goto L6167d0;  // @84_6166c0
  L616812:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @86_6166c0
  L616815:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L61689f;  // @88_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L616834;  // @89_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_6166c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @91_6166c0
  ecx = edx = 0;  // @92_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @93_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @94_6166c0
  L616834:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @96_6166c0
  ebx = 0;  // @97_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @98_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @99_6166c0
  edi = (edi + (u32)(2));  // @100_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @101_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @102_6166c0
  edi = (edi + eax);  // @103_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L61689f;  // @104_6166c0
  L616850:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @106_6166c0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @107_6166c0
  edi = (edi + (u32)(2));  // @108_6166c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @109_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*8 + 4), sizeof v); (u32)v; });  // @110_6166c0
  if ((s32)(eax & eax) >= 0) goto L616896;  // @111_6166c0
  eax = (eax & (u32)(2147483647));  // @112_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*8 + 4), &v, sizeof v); }  // @113_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @114_6166c0
  ecx = (u32)(ecx + eax*2);  // @115_6166c0
  if ((edx & edx) == 0) goto L616896;  // @116_6166c0
  esi = edi;  // @117_6166c0
  esi = (esi - ecx);  // @118_6166c0
  L616880:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + ecx), sizeof v); (u32)v; })) & 0xffff);  // @120_6166c0
  ecx = (u32)(ecx + 2);  // @121_6166c0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx - 2), &v, sizeof v); }  // @122_6166c0
  edx = (edx - (u32)(1));  // @123_6166c0
  if (edx != 0) goto L616880;  // @124_6166c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @125_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @126_6166c0
  L616896:;
  ebx = (ebx + 1);  // @128_6166c0
  edi = (u32)(edi + edx*2);  // @129_6166c0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L616850;  // @130_6166c0
  L61689f:;
  eax = esi;  // @132_6166c0
  SEH_LEAVE();  // @133_6166c0
  return eax;  // @134_6166c0
}
PCREG(6166c0, lifted_6166c0);









