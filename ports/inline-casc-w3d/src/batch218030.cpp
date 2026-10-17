// batch218030.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_43ff90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66c60b);  // @h_43ff90
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  ebx = ecx;  // @0_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @2_43ff90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_43ff90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_43ff90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @6_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @7_43ff90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @8_43ff90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; })) & 0xff);  // @9_43ff90
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @10_43ff90
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @11_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_43ff90
  PV[1] = (u32)(edx);  // @13_43ff90
  PV[2] = (u32)(esi);  // @14_43ff90
  PV[3] = (u32)(edi);  // @15_43ff90
  PV[4] = (u32)(ecx);  // @16_43ff90
  ecx = ebx;  // @17_43ff90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 440)))(ecx, PV[4], PV[3], PV[2], PV[1], PV[0]);  // @18_43ff90
  ecx = edx = 0;  // @19_43ff90
  edi = eax;  // @20_43ff90
  FL[2] = (edi & edi);  // @21_43ff90
  if (FL[2] == 0) goto L4401f6;  // @22_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_43ff90
  PV[5] = (u32)(edi);  // @24_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @27_43ff90
  ecx = edx = 0;  // @28_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @29_43ff90
  ebx = eax;  // @30_43ff90
  FL[2] = (ecx & ecx);  // @31_43ff90
  if (FL[2] == 0) goto L440035;  // @32_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @33_43ff90
  FL[2] = (eax & eax);  // @34_43ff90
  if (FL[2] == 0) goto L440035;  // @35_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_43ff90
  PV[6] = (u32)(eax);  // @37_43ff90
  PV[7] = (u32)(ecx);  // @38_43ff90
  ecx = edi;  // @39_43ff90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 116)))(ecx, PV[7], PV[6]);  // @40_43ff90
  ecx = edx = 0;  // @41_43ff90
  L440035:;
  ecx = (u32)(EBP - 188);  // @43_43ff90
  eax = ext_4ccba0_thiscall1(ecx);  // @44_43ff90
  ecx = edx = 0;  // @45_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @46_43ff90
  reg.state = (s32)((u32)(0));  // @47_43ff90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @48_43ff90
  FL[2] = (edx & edx);  // @49_43ff90
  if (FL[2] == 0) goto L440089;  // @50_43ff90
  L440054:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_43ff90
  PV[8] = (u32)(edx);  // @53_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @54_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[8]);  // @56_43ff90
  ecx = edx = 0;  // @57_43ff90
  PV[9] = (u32)(eax);  // @58_43ff90
  ecx = (u32)(EBP - 188);  // @59_43ff90
  eax = ext_4cd540_thiscall2(ecx, PV[9]);  // @60_43ff90
  ecx = edx = 0;  // @61_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_43ff90
  ecx = (u32)(EBP - 192);  // @63_43ff90
  PV[10] = (u32)(ecx);  // @64_43ff90
  ecx = edi;  // @65_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[10]);  // @66_43ff90
  ecx = edx = 0;  // @67_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @68_43ff90
  FL[2] = (edx & edx);  // @69_43ff90
  if (FL[2] != 0) goto L440054;  // @70_43ff90
  L440089:;
  eax = (u32)(EBP - 212);  // @72_43ff90
  PV[11] = (u32)(eax);  // @73_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @74_43ff90
  ecx = (u32)(EBP - 188);  // @75_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[11]);  // @76_43ff90
  ecx = edx = 0;  // @77_43ff90
  eax = (u32)(EBP - 212);  // @78_43ff90
  PV[12] = (u32)(eax);  // @79_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @80_43ff90
  ecx = (u32)(EBP - 188);  // @81_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[12]);  // @82_43ff90
  ecx = edx = 0;  // @83_43ff90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @84_43ff90
  esi = eax;  // @85_43ff90
  if (FL[0] == FL[1]) goto L4401d2;  // @86_43ff90
  L4400d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_43ff90
  PV[13] = (u32)(esi);  // @89_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @90_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[13]);  // @92_43ff90
  ecx = edx = 0;  // @93_43ff90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @94_43ff90
  FL[2] = (eax & eax);  // @95_43ff90
  if (FL[2] == 0) goto L4401ad;  // @96_43ff90
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608));  // @97_43ff90
  if (FL[2] != 0) goto L4401ad;  // @98_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @99_43ff90
  FL[2] = (ecx & ecx);  // @100_43ff90
  if (FL[2] == 0) goto L44010c;  // @101_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_43ff90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @103_43ff90
  ecx = edx = 0;  // @104_43ff90
  L44010c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_43ff90
  PV[14] = (u32)(esi);  // @107_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @108_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[14]);  // @110_43ff90
  ecx = edx = 0;  // @111_43ff90
  FL[2] = (eax & eax);  // @112_43ff90
  if (FL[2] == 0) goto L4401ad;  // @113_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @114_43ff90
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @115_43ff90
  ecx = edx = 0;  // @116_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @117_43ff90
  PV[15] = (u32)(esi);  // @118_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @119_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[15]);  // @121_43ff90
  ecx = edx = 0;  // @122_43ff90
  FL[2] = (eax & eax);  // @123_43ff90
  if (FL[2] == 0) goto L4401ad;  // @124_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @125_43ff90
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @126_43ff90
  ecx = edx = 0;  // @127_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_43ff90
  PV[16] = (u32)(esi);  // @129_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @130_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[16]);  // @132_43ff90
  ecx = edx = 0;  // @133_43ff90
  FL[2] = (eax & eax);  // @134_43ff90
  if (FL[2] == 0) goto L4401ad;  // @135_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @136_43ff90
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @137_43ff90
  ecx = edx = 0;  // @138_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @139_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @140_43ff90
  FL[2] = (ecx & ecx);  // @141_43ff90
  if (FL[2] == 0) goto L44019c;  // @142_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_43ff90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @144_43ff90
  ecx = edx = 0;  // @145_43ff90
  L44019c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @147_43ff90
  PV[17] = (u32)(esi);  // @148_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @149_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[17]);  // @151_43ff90
  ecx = edx = 0;  // @152_43ff90
  L4401ad:;
  eax = (u32)(EBP - 212);  // @154_43ff90
  PV[18] = (u32)(eax);  // @155_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @156_43ff90
  ecx = (u32)(EBP - 188);  // @157_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[18]);  // @158_43ff90
  ecx = edx = 0;  // @159_43ff90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @160_43ff90
  esi = eax;  // @161_43ff90
  if (FL[0] != FL[1]) goto L4400d0;  // @162_43ff90
  L4401d2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @164_43ff90
  PV[19] = (u32)(ebx);  // @165_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @166_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[19]);  // @168_43ff90
  ecx = edx = 0;  // @169_43ff90
  FL[1] = eax;  // @170_43ff90
  eax = (0u - eax);  // @171_43ff90
  ecx = (u32)(EBP - 188);  // @172_43ff90
  esi = (0u - (u32)(FL[1] != 0));  // @173_43ff90
  esi = (esi & edi);  // @174_43ff90
  FL[3] = esi;  // @175_43ff90
  eax = ext_4ccf60_thiscall1(ecx);  // @176_43ff90
  ecx = edx = 0;  // @177_43ff90
  eax = esi;  // @178_43ff90
  L4401f6:;
  SEH_LEAVE();  // @180_43ff90
  ext_633654(G(u32, 0x6f5630));  // @181_43ff90
  return eax;  // @182_43ff90
}
PCREG(43ff90, lifted_43ff90);

