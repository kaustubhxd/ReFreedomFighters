// batch228008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4c4f10_stdcall3(u32, u32, u32) __asm__("ext_4c4f10");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_45e190(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665bff);  // @h_45e190
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_45e190
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_45e190
  ebx = (ebx & (u32)(280));  // @3_45e190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @4_45e190
  ecx = edx = 0;  // @5_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @6_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_45e190
  if ((ecx & ecx) == 0) goto L45e25e;  // @8_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_45e190
  edx = (u32)(EBP - 24);  // @10_45e190
  PV[0] = (u32)(edx);  // @11_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @12_45e190
  ecx = edx = 0;  // @13_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @14_45e190
  edx = (u32)(EBP - 24);  // @15_45e190
  PV[1] = (u32)(edx);  // @16_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @17_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @19_45e190
  ecx = edx = 0;  // @20_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45e294;  // @21_45e190
  L45e200:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @23_45e190
  PV[2] = (u32)(eax);  // @24_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @26_45e190
  ecx = edx = 0;  // @27_45e190
  esi = eax;  // @28_45e190
  if ((esi & esi) != 0) goto L45e226;  // @29_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @30_45e190
  edx = (u32)(EBP - 24);  // @31_45e190
  PV[3] = (u32)(edx);  // @32_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @33_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[3]);  // @35_45e190
  ecx = edx = 0;  // @36_45e190
  goto L45e22c;  // @37_45e190
  L45e226:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L45e243;  // @39_45e190
  L45e22c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @41_45e190
  edx = (u32)(EBP - 24);  // @42_45e190
  PV[4] = (u32)(edx);  // @43_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @44_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @46_45e190
  ecx = edx = 0;  // @47_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L45e200;  // @48_45e190
  goto L45e294;  // @49_45e190
  L45e243:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_45e190
  ecx = (u32)(esi + 16);  // @52_45e190
  eax = (eax + (u32)(64));  // @53_45e190
  if (ecx == eax) goto L45e256;  // @54_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @55_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @56_45e190
  L45e256:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) | ebx)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @58_45e190
  goto L45e2fe;  // @59_45e190
  L45e25e:;
  eax = ext_41e290_cdecl1((u32)(28));  // @61_45e190
  ecx = edx = 0;  // @62_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @63_45e190
  reg.state = (s32)((u32)(0));  // @64_45e190
  if ((eax & eax) == 0) goto L45e285;  // @65_45e190
  ecx = eax;  // @66_45e190
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @67_45e190
  ecx = edx = 0;  // @68_45e190
  ecx = eax;  // @69_45e190
  goto L45e287;  // @70_45e190
  L45e285:;
  ecx = 0;  // @72_45e190
  L45e287:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @74_45e190
  reg.state = (s32)((u32)(4294967295));  // @75_45e190
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @76_45e190
  L45e294:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_45e190
  PV[5] = (u32)(edi);  // @79_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @80_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, PV[5]);  // @82_45e190
  ecx = edx = 0;  // @83_45e190
  esi = eax;  // @84_45e190
  PV[6] = (u32)(esi);  // @85_45e190
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @86_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @87_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[6]);  // @89_45e190
  ecx = edx = 0;  // @90_45e190
  if ((eax & eax) == 0) goto L45e2c1;  // @91_45e190
  edx = 0;  // @92_45e190
  goto L45e2f2;  // @93_45e190
  L45e2c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @95_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @96_45e190
  if ((eax & eax) == 0) goto L45e2e0;  // @97_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L45e2e0;  // @98_45e190
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L45e2e0;  // @99_45e190
  ecx = esi;  // @100_45e190
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @101_45e190
  ecx = edx = 0;  // @102_45e190
  edx = eax;  // @103_45e190
  goto L45e2f2;  // @104_45e190
  L45e2e0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L45e2ef;  // @106_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_45e190
  PV[7] = (u32)(esi);  // @108_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[7]);  // @109_45e190
  ecx = edx = 0;  // @110_45e190
  L45e2ef:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @112_45e190
  L45e2f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @114_45e190
  PV[8] = (u32)(edx);  // @115_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @116_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[8]);  // @118_45e190
  ecx = edx = 0;  // @119_45e190
  L45e2fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @121_45e190
  ecx = edi;  // @122_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @123_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @124_45e190
  PV[9] = (u32)(eax);  // @125_45e190
  PV[10] = (u32)(esi);  // @126_45e190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 284)))(ecx, PV[10], PV[9]);  // @127_45e190
  ecx = edx = 0;  // @128_45e190
  if (((ebx & 0xff) & (u32)(8)) == 0) goto L45e36b;  // @129_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @130_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L45e36b;  // @131_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @132_45e190
  PV[11] = (u32)(esi);  // @133_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[11]);  // @135_45e190
  ecx = edx = 0;  // @136_45e190
  if ((eax & eax) == 0) goto L45e332;  // @137_45e190
  ecx = 0;  // @138_45e190
  goto L45e363;  // @139_45e190
  L45e332:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @141_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @142_45e190
  if ((eax & eax) == 0) goto L45e351;  // @143_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L45e351;  // @144_45e190
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L45e351;  // @145_45e190
  ecx = esi;  // @146_45e190
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @147_45e190
  ecx = edx = 0;  // @148_45e190
  ecx = eax;  // @149_45e190
  goto L45e363;  // @150_45e190
  L45e351:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L45e360;  // @152_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_45e190
  PV[12] = (u32)(esi);  // @154_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[12]);  // @155_45e190
  ecx = edx = 0;  // @156_45e190
  L45e360:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @158_45e190
  L45e363:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @160_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @161_45e190
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @162_45e190
  L45e36b:;
  eax = esi;  // @164_45e190
  SEH_LEAVE();  // @165_45e190
  return eax;  // @166_45e190
}
PCREG(45e190, lifted_45e190);

extern "C" u32 THISCALL lifted_4c5090(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66997b);  // @h_4c5090
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c5090
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @1_4c5090
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4c5090
  ecx = (u32)(EBP - 188);  // @3_4c5090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4c5090
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @5_4c5090
  eax = ext_4ccba0_thiscall1(ecx);  // @6_4c5090
  ecx = edx = 0;  // @7_4c5090
  PV[0] = (u32)(esi);  // @8_4c5090
  PV[1] = (u32)(edi);  // @9_4c5090
  eax = (u32)(EBP - 188);  // @10_4c5090
  reg.state = (s32)((u32)(0));  // @11_4c5090
  PV[2] = (u32)(eax);  // @12_4c5090
  ecx = ebx;  // @13_4c5090
  eax = ext_4c4f10_stdcall3(PV[2], PV[1], PV[0]);  // @14_4c5090
  ecx = edx = 0;  // @15_4c5090
  eax = (u32)(EBP - 200);  // @16_4c5090
  PV[3] = (u32)(eax);  // @17_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @18_4c5090
  ecx = (u32)(EBP - 188);  // @19_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @20_4c5090
  ecx = edx = 0;  // @21_4c5090
  eax = (u32)(EBP - 200);  // @22_4c5090
  PV[4] = (u32)(eax);  // @23_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @24_4c5090
  ecx = (u32)(EBP - 188);  // @25_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @26_4c5090
  ecx = edx = 0;  // @27_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L4c51c7;  // @28_4c5090
  L4c5130:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4c5090
  PV[5] = (u32)(eax);  // @31_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @32_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[5]);  // @34_4c5090
  ecx = edx = 0;  // @35_4c5090
  esi = eax;  // @36_4c5090
  if ((esi & esi) == 0) goto L4c519e;  // @37_4c5090
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }) == (u32)(0)) goto L4c5197;  // @38_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4c5090
  PV[6] = (u32)(esi);  // @40_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @41_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[6]);  // @43_4c5090
  ecx = edx = 0;  // @44_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @45_4c5090
  PV[7] = (u32)(eax);  // @46_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 44)))(ecx, PV[7]);  // @48_4c5090
  ecx = edx = 0;  // @49_4c5090
  if ((eax & eax) == 0) goto L4c5172;  // @50_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @51_4c5090
  goto L4c5174;  // @52_4c5090
  L4c5172:;
  edx = 0;  // @54_4c5090
  L4c5174:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_4c5090
  PV[8] = (u32)(edx);  // @57_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @58_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[8]);  // @60_4c5090
  ecx = edx = 0;  // @61_4c5090
  if ((eax & eax) == 0) goto L4c519e;  // @62_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_4c5090
  ecx = eax;  // @64_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @65_4c5090
  ecx = edx = 0;  // @66_4c5090
  goto L4c519e;  // @67_4c5090
  L4c5197:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_4c5090
  ecx = esi;  // @70_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @71_4c5090
  ecx = edx = 0;  // @72_4c5090
  L4c519e:;
  eax = (u32)(EBP - 200);  // @74_4c5090
  PV[9] = (u32)(eax);  // @75_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @76_4c5090
  ecx = (u32)(EBP - 188);  // @77_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @78_4c5090
  ecx = edx = 0;  // @79_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L4c5130;  // @80_4c5090
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @81_4c5090
  L4c51c7:;
  PV[10] = (u32)(edi);  // @83_4c5090
  PV[11] = (u32)(esi);  // @84_4c5090
  eax = (u32)(EBP - 188);  // @85_4c5090
  ecx = ebx;  // @86_4c5090
  PV[12] = (u32)(eax);  // @87_4c5090
  eax = ext_4c4f10_stdcall3(PV[12], PV[11], PV[10]);  // @88_4c5090
  ecx = edx = 0;  // @89_4c5090
  eax = (u32)(EBP - 200);  // @90_4c5090
  PV[13] = (u32)(eax);  // @91_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @92_4c5090
  ecx = (u32)(EBP - 188);  // @93_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @94_4c5090
  ecx = edx = 0;  // @95_4c5090
  eax = (u32)(EBP - 200);  // @96_4c5090
  PV[14] = (u32)(eax);  // @97_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @98_4c5090
  ecx = (u32)(EBP - 188);  // @99_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[14]);  // @100_4c5090
  ecx = edx = 0;  // @101_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L4c52be;  // @102_4c5090
  L4c5210:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @104_4c5090
  PV[15] = (u32)(eax);  // @105_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @106_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[15]);  // @108_4c5090
  ecx = edx = 0;  // @109_4c5090
  esi = eax;  // @110_4c5090
  if ((esi & esi) == 0) goto L4c529b;  // @111_4c5090
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }) == (u32)(0)) goto L4c528a;  // @112_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @113_4c5090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4c5090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @116_4c5090
  ecx = edx = 0;  // @117_4c5090
  PV[16] = (u32)(eax);  // @118_4c5090
  ecx = esi;  // @119_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 440)))(ecx, PV[16]);  // @120_4c5090
  ecx = edx = 0;  // @121_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @122_4c5090
  ebx = eax;  // @123_4c5090
  PV[17] = (u32)(ebx);  // @124_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @125_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @126_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[17]);  // @127_4c5090
  ecx = edx = 0;  // @128_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @129_4c5090
  edi = eax;  // @130_4c5090
  PV[18] = (u32)(esi);  // @131_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @132_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[18]);  // @134_4c5090
  ecx = edx = 0;  // @135_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @136_4c5090
  PV[19] = (u32)(eax);  // @137_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 106), sizeof v); (u32)v; });  // @138_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[19]);  // @140_4c5090
  ecx = edx = 0;  // @141_4c5090
  esi = ebx;  // @142_4c5090
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @143_4c5090
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @144_4c5090
  L4c528a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_4c5090
  ecx = esi;  // @147_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @148_4c5090
  ecx = edx = 0;  // @149_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_4c5090
  ecx = esi;  // @151_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 456)))(ecx);  // @152_4c5090
  ecx = edx = 0;  // @153_4c5090
  L4c529b:;
  eax = (u32)(EBP - 200);  // @155_4c5090
  PV[20] = (u32)(eax);  // @156_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @157_4c5090
  ecx = (u32)(EBP - 188);  // @158_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[20]);  // @159_4c5090
  ecx = edx = 0;  // @160_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L4c5210;  // @161_4c5090
  L4c52be:;
  ecx = (u32)(EBP - 188);  // @163_4c5090
  eax = ext_4ccf60_thiscall1(ecx);  // @164_4c5090
  ecx = edx = 0;  // @165_4c5090
  SEH_LEAVE();  // @166_4c5090
  ext_633654(G(u32, 0x6f5630));  // @167_4c5090
  return eax;  // @168_4c5090
}
PCREG(4c5090, lifted_4c5090);

extern "C" u32 THISCALL lifted_437440(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665ac2);  // @h_437440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_437440
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @2_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @3_437440
  eax = ext_41e290_cdecl1((u32)(28));  // @4_437440
  ecx = edx = 0;  // @5_437440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @6_437440
  reg.state = (s32)((u32)(0));  // @7_437440
  if ((eax & eax) == 0) goto L4374a3;  // @8_437440
  ecx = eax;  // @9_437440
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @10_437440
  ecx = edx = 0;  // @11_437440
  goto L4374a5;  // @12_437440
  L4374a3:;
  eax = 0;  // @14_437440
  L4374a5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @16_437440
  reg.state = (s32)((u32)(4294967295));  // @17_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L437632;  // @18_437440
  L4374c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @20_437440
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @21_437440
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[1], PV[0]);  // @24_437440
  ecx = edx = 0;  // @25_437440
  edi = eax;  // @26_437440
  if ((edi & edi) == 0) goto L437538;  // @27_437440
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; }) == (u32)(0)) goto L4374e5;  // @28_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @29_437440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 161), &v, sizeof v); }  // @30_437440
  L4374e5:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L43752e;  // @32_437440
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; }) != (u32)(0)) goto L43752e;  // @33_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2574));  // @36_437440
  ecx = edx = 0;  // @37_437440
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_437440
  PV[3] = (u32)(eax);  // @40_437440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, PV[3], (u32)(6793848), PV[2]);  // @41_437440
  ecx = edx = 0;  // @42_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @43_437440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @44_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_437440
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @46_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[4]);  // @47_437440
  ecx = edx = 0;  // @48_437440
  L43752e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_437440
  ecx = ebx;  // @51_437440
  PV[5] = (u32)(edi);  // @52_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[5]);  // @53_437440
  ecx = edx = 0;  // @54_437440
  goto L437540;  // @55_437440
  L437538:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_437440
  ecx = ebx;  // @58_437440
  PV[6] = (u32)(esi);  // @59_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[6]);  // @60_437440
  ecx = edx = 0;  // @61_437440
  L437540:;
  esi = (esi + (u32)(28));  // @63_437440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @64_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != 0) goto L4374c0;  // @65_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; })) & 0xff);  // @66_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @67_437440
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L437638;  // @68_437440
  if ((esi & esi) == 0) goto L437644;  // @69_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_437440
  ecx = (u32)(EBP - 164);  // @71_437440
  PV[7] = (u32)(ecx);  // @72_437440
  ecx = esi;  // @73_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @74_437440
  ecx = edx = 0;  // @75_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_437440
  ecx = (u32)(EBP - 164);  // @77_437440
  PV[8] = (u32)(ecx);  // @78_437440
  ecx = esi;  // @79_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @80_437440
  ecx = edx = 0;  // @81_437440
  ecx = eax;  // @82_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) == (u32)(0)) goto L437638;  // @83_437440
  L437594:;
  edx = (u32)(EBP - 144);  // @85_437440
  edx = (edx - ecx);  // @86_437440
  L4375a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @88_437440
  ecx = (u32)(ecx + 1);  // @89_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @90_437440
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4375a0;  // @91_437440
  esi = (u32)(EBP - 144);  // @92_437440
  L4375b3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @94_437440
  edi = esi;  // @95_437440
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L43760d;  // @96_437440
  if ((eax & 0xff) == (u32)(48)) goto L43760d;  // @97_437440
  L4375c0:;
  if ((eax & 0xff) == (u32)(43)) goto L4375d0;  // @99_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @100_437440
  esi = (esi + 1);  // @101_437440
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4375c0;  // @102_437440
  if ((eax & 0xff) != (u32)(43)) goto L4375d4;  // @103_437440
  L4375d0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @105_437440
  esi = (esi + 1);  // @106_437440
  L4375d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @108_437440
  PV[9] = (u32)(edi);  // @109_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @111_437440
  ecx = edx = 0;  // @112_437440
  if ((eax & eax) == 0) goto L4375e7;  // @113_437440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @114_437440
  goto L4375b3;  // @115_437440
  L4375e7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @117_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2603));  // @119_437440
  ecx = edx = 0;  // @120_437440
  PV[10] = (u32)(edi);  // @121_437440
  PV[11] = (u32)(eax);  // @122_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @123_437440
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[11], (u32)(6793964), PV[10]);  // @124_437440
  ecx = edx = 0;  // @125_437440
  goto L4375b3;  // @126_437440
  L43760d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @128_437440
  ecx = (u32)(EBP - 164);  // @129_437440
  PV[12] = (u32)(ecx);  // @130_437440
  ecx = esi;  // @131_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[12]);  // @133_437440
  ecx = edx = 0;  // @134_437440
  ecx = eax;  // @135_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) != (u32)(0)) goto L437594;  // @136_437440
  goto L437638;  // @137_437440
  L437632:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @139_437440
  L437638:;
  if ((esi & esi) == 0) goto L437644;  // @141_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_437440
  ecx = esi;  // @143_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @144_437440
  ecx = edx = 0;  // @145_437440
  L437644:;
  SEH_LEAVE();  // @147_437440
  ext_633654(G(u32, 0x6f5630));  // @148_437440
  return eax;  // @149_437440
}
PCREG(437440, lifted_437440);

extern "C" u32 THISCALL lifted_4627d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66693b);  // @h_4627d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @2_4627d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16604), &v, sizeof v); }  // @3_4627d0
  ecx = (u32)(edi + edi*2);  // @4_4627d0
  ecx = (u32)(eax + ecx*8);  // @5_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @6_4627d0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4629f7;  // @7_4627d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @8_4627d0
  eax = (eax & (u32)(4294967292));  // @9_4627d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @10_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @11_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @12_4627d0
  ecx = esi;  // @13_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_4627d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16612), &v, sizeof v); }  // @15_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @16_4627d0
  ecx = edx = 0;  // @17_4627d0
  edi = (u32)(edi + edi*2);  // @18_4627d0
  edi = (edi + edi);  // @19_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 47), sizeof v); (u32)v; }) == (u32)(3)) goto L462909;  // @20_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L462909;  // @21_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }) != (u32)(0)) goto L462909;  // @22_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4627d0
  ecx = esi;  // @24_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @25_4627d0
  ecx = edx = 0;  // @26_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 12), sizeof v); (u32)v; });  // @27_4627d0
  if ((s32)(edi & edi) < 0) goto L462909;  // @28_4627d0
  L462880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @30_4627d0
  ecx = (u32)(edi + edi*2);  // @31_4627d0
  ebx = (u32)(eax + ecx*8);  // @32_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @33_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16608), &v, sizeof v); }  // @34_4627d0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4628a1;  // @35_4627d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; })) goto L4628ba;  // @36_4627d0
  L4628a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4627d0
  ecx = esi;  // @39_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @40_4627d0
  ecx = edx = 0;  // @41_4627d0
  ecx = (u32)(edi + edi*2);  // @42_4627d0
  ecx = (ecx + ecx);  // @43_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 12), sizeof v); (u32)v; });  // @44_4627d0
  if ((s32)(edi & edi) >= 0) goto L462880;  // @45_4627d0
  goto L462903;  // @46_4627d0
  L4628ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_4627d0
  ecx = esi;  // @49_4627d0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; });  // @50_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 700)))(ecx, PV[0]);  // @51_4627d0
  ecx = edx = 0;  // @52_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @53_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16608), sizeof v); (u32)v; });  // @54_4627d0
  PV[1] = (u32)(eax);  // @55_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_4627d0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @57_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, PV[2], PV[1]);  // @58_4627d0
  ecx = edx = 0;  // @59_4627d0
  ecx = eax;  // @60_4627d0
  if ((ecx & ecx) == 0) goto L462903;  // @61_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_4627d0
  PV[3] = (u32)(edi);  // @63_4627d0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; });  // @64_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 848), sizeof v); (u32)v; });  // @65_4627d0
  PV[5] = (u32)(ecx);  // @66_4627d0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; });  // @67_4627d0
  ecx = esi;  // @68_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[6], PV[5], PV[4], PV[3]);  // @69_4627d0
  ecx = edx = 0;  // @70_4627d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462903;  // @71_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @72_4627d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @73_4627d0
  L462903:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @75_4627d0
  L462909:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @77_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) != 0) goto L4629f7;  // @78_4627d0
  ecx = (u32)(EBP - 16596);  // @79_4627d0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @80_4627d0
  eax = ext_4d2280_thiscall1(ecx);  // @81_4627d0
  ecx = edx = 0;  // @82_4627d0
  edi = (u32)(ebx + 76);  // @83_4627d0
  reg.state = (s32)((u32)(0));  // @84_4627d0
  PV[7] = (u32)(edi);  // @85_4627d0
  ecx = (u32)(EBP - 16596);  // @86_4627d0
  eax = ext_4d39a0_stdcall2((u32)(6838552), PV[7]);  // @87_4627d0
  ecx = edx = 0;  // @88_4627d0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @89_4627d0
  ecx = (u32)(EBP - 16596);  // @90_4627d0
  eax = ext_4d3ab0_stdcall2((u32)(6838564), PV[8]);  // @91_4627d0
  ecx = edx = 0;  // @92_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @93_4627d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) == 0) goto L462979;  // @94_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_4627d0
  eax = (u32)(EBP - 16596);  // @96_4627d0
  PV[9] = (u32)(eax);  // @97_4627d0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 296), sizeof v); (u32)v; });  // @98_4627d0
  ecx = esi;  // @99_4627d0
  PV[10] = (u32)(eax);  // @100_4627d0
  PV[11] = (u32)(esi);  // @101_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[11], PV[10], PV[9]);  // @102_4627d0
  ecx = edx = 0;  // @103_4627d0
  L462979:;
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16612), sizeof v); (u32)v; });  // @105_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_4627d0
  ecx = esi;  // @107_4627d0
  PV[13] = (u32)(edi);  // @108_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 836)))(ecx, PV[13], PV[12]);  // @109_4627d0
  ecx = edx = 0;  // @110_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @111_4627d0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @112_4627d0
  if ((ecx & ecx) == 0) goto L4629ec;  // @113_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_4627d0
  edx = (u32)(EBP - 16624);  // @115_4627d0
  PV[14] = (u32)(edx);  // @116_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @117_4627d0
  ecx = edx = 0;  // @118_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @119_4627d0
  edx = (u32)(EBP - 16624);  // @120_4627d0
  PV[15] = (u32)(edx);  // @121_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[15]);  // @123_4627d0
  ecx = edx = 0;  // @124_4627d0
  edx = eax;  // @125_4627d0
  if ((edx & edx) == 0) goto L4629ec;  // @126_4627d0
  L4629b4:;
  ecx = (u32)(edx + 4);  // @128_4627d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L4629d7;  // @129_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }) != (u32)(-2)) goto L4629d7;  // @130_4627d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 68), &v, sizeof v); }  // @131_4627d0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @132_4627d0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @133_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @134_4627d0
  PV[17] = (u32)(ecx);  // @135_4627d0
  ecx = esi;  // @136_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 844)))(ecx, PV[17], PV[16]);  // @137_4627d0
  ecx = edx = 0;  // @138_4627d0
  L4629d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @140_4627d0
  edx = (u32)(EBP - 16624);  // @141_4627d0
  PV[18] = (u32)(edx);  // @142_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[18]);  // @144_4627d0
  ecx = edx = 0;  // @145_4627d0
  edx = eax;  // @146_4627d0
  if ((edx & edx) != 0) goto L4629b4;  // @147_4627d0
  L4629ec:;
  ecx = (u32)(EBP - 16596);  // @149_4627d0
  eax = ext_4d2330_thiscall1(ecx);  // @150_4627d0
  ecx = edx = 0;  // @151_4627d0
  L4629f7:;
  SEH_LEAVE();  // @153_4627d0
  ext_633654(G(u32, 0x6f5630));  // @154_4627d0
  return eax;  // @155_4627d0
}
PCREG(4627d0, lifted_4627d0);

