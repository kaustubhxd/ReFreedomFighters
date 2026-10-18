// batch228007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_482ac0_thiscall1(u32) __asm__("ext_482ac0");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5e0ee0_thiscall3(u32, u32, u32) __asm__("ext_5e0ee0");
extern "C" u32 THISCALL ext_5e0f80_thiscall3(u32, u32, u32) __asm__("ext_5e0f80");
extern "C" u32 THISCALL ext_5e0ff0_thiscall3(u32, u32, u32) __asm__("ext_5e0ff0");
extern "C" u32 THISCALL ext_5e10a0_thiscall3(u32, u32, u32) __asm__("ext_5e10a0");
extern "C" u32 THISCALL ext_5e1110_thiscall3(u32, u32, u32) __asm__("ext_5e1110");
extern "C" u32 THISCALL ext_5e1160_thiscall3(u32, u32, u32) __asm__("ext_5e1160");
extern "C" u32 THISCALL ext_5e1190_thiscall3(u32, u32, u32) __asm__("ext_5e1190");
extern "C" u32 THISCALL ext_5e11c0_thiscall3(u32, u32, u32) __asm__("ext_5e11c0");
extern "C" u32 THISCALL ext_5e1200_thiscall3(u32, u32, u32) __asm__("ext_5e1200");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5ee720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cbf2);  // @h_5ee720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ee720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5ee720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @2_5ee720
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5ee720
  PV[0] = (u32)(ebx);  // @4_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[0]);  // @6_5ee720
  ecx = edx = 0;  // @7_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_5ee720
  eax = (u32)(EBP + 11);  // @9_5ee720
  PV[1] = (u32)(eax);  // @10_5ee720
  PV[2] = (u32)(eax);  // @11_5ee720
  PV[3] = (u32)(eax);  // @12_5ee720
  PV[4] = (u32)(eax);  // @13_5ee720
  PV[5] = (u32)(eax);  // @14_5ee720
  eax = (u32)(esi + 106);  // @15_5ee720
  ecx = ebx;  // @16_5ee720
  PV[6] = (u32)(eax);  // @17_5ee720
  eax = (u32)(esi + 77);  // @18_5ee720
  PV[7] = (u32)(eax);  // @19_5ee720
  eax = (u32)(esi + 4);  // @20_5ee720
  PV[8] = (u32)(eax);  // @21_5ee720
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, PV[8], PV[7], PV[6], PV[5], PV[4], PV[3], PV[2], PV[1]);  // @22_5ee720
  ecx = edx = 0;  // @23_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_5ee720
  ecx = (u32)(EBP - 16);  // @25_5ee720
  PV[9] = (u32)(ecx);  // @26_5ee720
  ecx = ebx;  // @27_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[9]);  // @28_5ee720
  ecx = edx = 0;  // @29_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @30_5ee720
  ecx = ebx;  // @31_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @32_5ee720
  eax = (u32)(esi + 25);  // @33_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @34_5ee720
  PV[10] = (u32)(eax);  // @35_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[10]);  // @36_5ee720
  ecx = edx = 0;  // @37_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_5ee720
  eax = (u32)(esi + 65);  // @39_5ee720
  PV[11] = (u32)(eax);  // @40_5ee720
  ecx = ebx;  // @41_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[11]);  // @42_5ee720
  ecx = edx = 0;  // @43_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_5ee720
  eax = (u32)(esi + 69);  // @45_5ee720
  PV[12] = (u32)(eax);  // @46_5ee720
  ecx = ebx;  // @47_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[12]);  // @48_5ee720
  ecx = edx = 0;  // @49_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_5ee720
  eax = (u32)(esi + 73);  // @51_5ee720
  PV[13] = (u32)(eax);  // @52_5ee720
  ecx = ebx;  // @53_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[13]);  // @54_5ee720
  ecx = edx = 0;  // @55_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_5ee720
  eax = (u32)(esi + 78);  // @57_5ee720
  PV[14] = (u32)(eax);  // @58_5ee720
  ecx = ebx;  // @59_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[14]);  // @60_5ee720
  ecx = edx = 0;  // @61_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_5ee720
  eax = (u32)(esi + 82);  // @63_5ee720
  PV[15] = (u32)(eax);  // @64_5ee720
  ecx = ebx;  // @65_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[15]);  // @66_5ee720
  ecx = edx = 0;  // @67_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_5ee720
  eax = (u32)(esi + 86);  // @69_5ee720
  PV[16] = (u32)(eax);  // @70_5ee720
  ecx = ebx;  // @71_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[16]);  // @72_5ee720
  ecx = edx = 0;  // @73_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_5ee720
  ecx = (u32)(EBP - 16);  // @75_5ee720
  PV[17] = (u32)(ecx);  // @76_5ee720
  ecx = ebx;  // @77_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[17]);  // @78_5ee720
  ecx = edx = 0;  // @79_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @80_5ee720
  ecx = (u32)(EBP - 16);  // @81_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @82_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @83_5ee720
  PV[18] = (u32)(ecx);  // @84_5ee720
  ecx = ebx;  // @85_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[18]);  // @86_5ee720
  ecx = edx = 0;  // @87_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @88_5ee720
  ecx = ebx;  // @89_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @90_5ee720
  eax = (u32)(esi + 98);  // @91_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_5ee720
  PV[19] = (u32)(eax);  // @93_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[19]);  // @94_5ee720
  ecx = edx = 0;  // @95_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_5ee720
  eax = (u32)(esi + 102);  // @97_5ee720
  PV[20] = (u32)(eax);  // @98_5ee720
  ecx = ebx;  // @99_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[20]);  // @100_5ee720
  ecx = edx = 0;  // @101_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_5ee720
  eax = (u32)(esi + 107);  // @103_5ee720
  PV[21] = (u32)(eax);  // @104_5ee720
  ecx = ebx;  // @105_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[21]);  // @106_5ee720
  ecx = edx = 0;  // @107_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @108_5ee720
  ecx = (u32)(EBP - 16);  // @109_5ee720
  PV[22] = (u32)(ecx);  // @110_5ee720
  ecx = ebx;  // @111_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[22]);  // @112_5ee720
  ecx = edx = 0;  // @113_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @114_5ee720
  ecx = (u32)(EBP - 16);  // @115_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @116_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @117_5ee720
  PV[23] = (u32)(ecx);  // @118_5ee720
  ecx = ebx;  // @119_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[23]);  // @120_5ee720
  ecx = edx = 0;  // @121_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @122_5ee720
  ecx = ebx;  // @123_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @124_5ee720
  eax = (u32)(esi + 120);  // @125_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @126_5ee720
  PV[24] = (u32)(eax);  // @127_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[24]);  // @128_5ee720
  ecx = edx = 0;  // @129_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @130_5ee720
  eax = (u32)(esi + 124);  // @131_5ee720
  PV[25] = (u32)(eax);  // @132_5ee720
  ecx = ebx;  // @133_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[25]);  // @134_5ee720
  ecx = edx = 0;  // @135_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @136_5ee720
  ecx = (u32)(esi + 128);  // @137_5ee720
  PV[26] = (u32)(ecx);  // @138_5ee720
  ecx = ebx;  // @139_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[26]);  // @140_5ee720
  ecx = edx = 0;  // @141_5ee720
  ecx = (u32)(esi + 29);  // @142_5ee720
  eax = ext_4de7a0_thiscall1(ecx);  // @143_5ee720
  ecx = edx = 0;  // @144_5ee720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @145_5ee720
  ecx = (u32)(EBP - 24);  // @146_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @147_5ee720
  PV[27] = (u32)(ecx);  // @148_5ee720
  ecx = ebx;  // @149_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[27]);  // @150_5ee720
  ecx = edx = 0;  // @151_5ee720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @152_5ee720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) <= (u32)(0)) goto L5ee90b;  // @153_5ee720
  L5ee883:;
  eax = ext_41e290_cdecl1((u32)(8));  // @155_5ee720
  ecx = edx = 0;  // @156_5ee720
  edi = eax;  // @157_5ee720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @158_5ee720
  eax = ext_41e290_cdecl1((u32)(168));  // @159_5ee720
  ecx = edx = 0;  // @160_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @161_5ee720
  reg.state = (s32)((u32)(0));  // @162_5ee720
  if ((eax & eax) == 0) goto L5ee8be;  // @163_5ee720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @164_5ee720
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 128), sizeof v); (u32)v; });  // @165_5ee720
  ecx = eax;  // @166_5ee720
  eax = ext_5ab2e0_thiscall2(ecx, PV[28]);  // @167_5ee720
  ecx = edx = 0;  // @168_5ee720
  ecx = eax;  // @169_5ee720
  goto L5ee8c0;  // @170_5ee720
  L5ee8be:;
  ecx = 0;  // @172_5ee720
  L5ee8c0:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @174_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_5ee720
  PV[29] = (u32)(ebx);  // @176_5ee720
  reg.state = (s32)((u32)(4294967295));  // @177_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[29]);  // @178_5ee720
  ecx = edx = 0;  // @179_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @180_5ee720
  eax = (u32)(edi + 4);  // @181_5ee720
  PV[30] = (u32)(eax);  // @182_5ee720
  ecx = ebx;  // @183_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[30]);  // @184_5ee720
  ecx = edx = 0;  // @185_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @186_5ee720
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; })) goto L5ee8ee;  // @187_5ee720
  if ((eax & eax) == 0) goto L5ee8e8;  // @188_5ee720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @189_5ee720
  L5ee8e8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @191_5ee720
  goto L5ee8fb;  // @192_5ee720
  L5ee8ee:;
  ecx = (u32)(EBP - 32);  // @194_5ee720
  PV[31] = (u32)(ecx);  // @195_5ee720
  PV[32] = (u32)(eax);  // @196_5ee720
  ecx = (u32)(esi + 5);  // @197_5ee720
  eax = ext_5fe3b0_thiscall3(ecx, PV[32], PV[31]);  // @198_5ee720
  ecx = edx = 0;  // @199_5ee720
  L5ee8fb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @201_5ee720
  eax = (eax + 1);  // @202_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @203_5ee720
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5ee883;  // @204_5ee720
  L5ee90b:;
  SEH_LEAVE();  // @206_5ee720
  return eax;  // @207_5ee720
}
PCREG(5ee720, lifted_5ee720);

extern "C" u32 THISCALL lifted_590e20(u32 ecx_in) {
  SEH_ENTER(0x66b9ff);  // @h_590e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_590e20
  eax = ext_482ac0_thiscall1(ecx);  // @1_590e20
  ecx = edx = 0;  // @2_590e20
  eax = ext_41e290_cdecl1((u32)(1425));  // @3_590e20
  ecx = edx = 0;  // @4_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_590e20
  reg.state = (s32)((u32)(0));  // @6_590e20
  if ((eax & eax) == 0) goto L590e74;  // @7_590e20
  PV[0] = (u32)(esi);  // @8_590e20
  ecx = eax;  // @9_590e20
  eax = ext_5e1110_thiscall3(ecx, PV[0], (u32)(7));  // @10_590e20
  ecx = edx = 0;  // @11_590e20
  ecx = eax;  // @12_590e20
  goto L590e76;  // @13_590e20
  L590e74:;
  ecx = 0;  // @15_590e20
  L590e76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_590e20
  PV[1] = (u32)(ecx);  // @18_590e20
  ecx = esi;  // @19_590e20
  reg.state = (s32)((u32)(4294967295));  // @20_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[1]);  // @21_590e20
  ecx = edx = 0;  // @22_590e20
  eax = ext_41e290_cdecl1((u32)(1485));  // @23_590e20
  ecx = edx = 0;  // @24_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @25_590e20
  reg.state = (s32)((u32)(1));  // @26_590e20
  if ((eax & eax) == 0) goto L590eb1;  // @27_590e20
  PV[2] = (u32)(esi);  // @28_590e20
  ecx = eax;  // @29_590e20
  eax = ext_5e1200_thiscall3(ecx, PV[2], (u32)(8));  // @30_590e20
  ecx = edx = 0;  // @31_590e20
  ecx = eax;  // @32_590e20
  goto L590eb3;  // @33_590e20
  L590eb1:;
  ecx = 0;  // @35_590e20
  L590eb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_590e20
  PV[3] = (u32)(ecx);  // @38_590e20
  ecx = esi;  // @39_590e20
  reg.state = (s32)((u32)(4294967295));  // @40_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[3]);  // @41_590e20
  ecx = edx = 0;  // @42_590e20
  eax = ext_41e290_cdecl1((u32)(1471));  // @43_590e20
  ecx = edx = 0;  // @44_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @45_590e20
  reg.state = (s32)((u32)(2));  // @46_590e20
  if ((eax & eax) == 0) goto L590eee;  // @47_590e20
  PV[4] = (u32)(esi);  // @48_590e20
  ecx = eax;  // @49_590e20
  eax = ext_5e1160_thiscall3(ecx, PV[4], (u32)(15));  // @50_590e20
  ecx = edx = 0;  // @51_590e20
  ecx = eax;  // @52_590e20
  goto L590ef0;  // @53_590e20
  L590eee:;
  ecx = 0;  // @55_590e20
  L590ef0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_590e20
  PV[5] = (u32)(ecx);  // @58_590e20
  ecx = esi;  // @59_590e20
  reg.state = (s32)((u32)(4294967295));  // @60_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[5]);  // @61_590e20
  ecx = edx = 0;  // @62_590e20
  eax = ext_41e290_cdecl1((u32)(1467));  // @63_590e20
  ecx = edx = 0;  // @64_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @65_590e20
  reg.state = (s32)((u32)(3));  // @66_590e20
  if ((eax & eax) == 0) goto L590f2b;  // @67_590e20
  PV[6] = (u32)(esi);  // @68_590e20
  ecx = eax;  // @69_590e20
  eax = ext_5e1190_thiscall3(ecx, PV[6], (u32)(16));  // @70_590e20
  ecx = edx = 0;  // @71_590e20
  ecx = eax;  // @72_590e20
  goto L590f2d;  // @73_590e20
  L590f2b:;
  ecx = 0;  // @75_590e20
  L590f2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_590e20
  PV[7] = (u32)(ecx);  // @78_590e20
  ecx = esi;  // @79_590e20
  reg.state = (s32)((u32)(4294967295));  // @80_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[7]);  // @81_590e20
  ecx = edx = 0;  // @82_590e20
  eax = ext_41e290_cdecl1((u32)(1384));  // @83_590e20
  ecx = edx = 0;  // @84_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @85_590e20
  reg.state = (s32)((u32)(4));  // @86_590e20
  if ((eax & eax) == 0) goto L590f68;  // @87_590e20
  PV[8] = (u32)(esi);  // @88_590e20
  ecx = eax;  // @89_590e20
  eax = ext_5e11c0_thiscall3(ecx, PV[8], (u32)(17));  // @90_590e20
  ecx = edx = 0;  // @91_590e20
  ecx = eax;  // @92_590e20
  goto L590f6a;  // @93_590e20
  L590f68:;
  ecx = 0;  // @95_590e20
  L590f6a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_590e20
  PV[9] = (u32)(ecx);  // @98_590e20
  ecx = esi;  // @99_590e20
  reg.state = (s32)((u32)(4294967295));  // @100_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[9]);  // @101_590e20
  ecx = edx = 0;  // @102_590e20
  eax = ext_41e290_cdecl1((u32)(1455));  // @103_590e20
  ecx = edx = 0;  // @104_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @105_590e20
  reg.state = (s32)((u32)(5));  // @106_590e20
  if ((eax & eax) == 0) goto L590fa5;  // @107_590e20
  PV[10] = (u32)(esi);  // @108_590e20
  ecx = eax;  // @109_590e20
  eax = ext_5e10a0_thiscall3(ecx, PV[10], (u32)(9));  // @110_590e20
  ecx = edx = 0;  // @111_590e20
  ecx = eax;  // @112_590e20
  goto L590fa7;  // @113_590e20
  L590fa5:;
  ecx = 0;  // @115_590e20
  L590fa7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_590e20
  PV[11] = (u32)(ecx);  // @118_590e20
  ecx = esi;  // @119_590e20
  reg.state = (s32)((u32)(4294967295));  // @120_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[11]);  // @121_590e20
  ecx = edx = 0;  // @122_590e20
  eax = ext_41e290_cdecl1((u32)(122));  // @123_590e20
  ecx = edx = 0;  // @124_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @125_590e20
  reg.state = (s32)((u32)(6));  // @126_590e20
  if ((eax & eax) == 0) goto L590fdf;  // @127_590e20
  PV[12] = (u32)(esi);  // @128_590e20
  ecx = eax;  // @129_590e20
  eax = ext_5e0ee0_thiscall3(ecx, PV[12], (u32)(11));  // @130_590e20
  ecx = edx = 0;  // @131_590e20
  ecx = eax;  // @132_590e20
  goto L590fe1;  // @133_590e20
  L590fdf:;
  ecx = 0;  // @135_590e20
  L590fe1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_590e20
  PV[13] = (u32)(ecx);  // @138_590e20
  ecx = esi;  // @139_590e20
  reg.state = (s32)((u32)(4294967295));  // @140_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[13]);  // @141_590e20
  ecx = edx = 0;  // @142_590e20
  eax = ext_41e290_cdecl1((u32)(1553));  // @143_590e20
  ecx = edx = 0;  // @144_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @145_590e20
  reg.state = (s32)((u32)(7));  // @146_590e20
  if ((eax & eax) == 0) goto L59101c;  // @147_590e20
  PV[14] = (u32)(esi);  // @148_590e20
  ecx = eax;  // @149_590e20
  eax = ext_5e0f80_thiscall3(ecx, PV[14], (u32)(12));  // @150_590e20
  ecx = edx = 0;  // @151_590e20
  ecx = eax;  // @152_590e20
  goto L59101e;  // @153_590e20
  L59101c:;
  ecx = 0;  // @155_590e20
  L59101e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @157_590e20
  PV[15] = (u32)(ecx);  // @158_590e20
  ecx = esi;  // @159_590e20
  reg.state = (s32)((u32)(4294967295));  // @160_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[15]);  // @161_590e20
  ecx = edx = 0;  // @162_590e20
  eax = ext_41e290_cdecl1((u32)(1400));  // @163_590e20
  ecx = edx = 0;  // @164_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @165_590e20
  reg.state = (s32)((u32)(8));  // @166_590e20
  if ((eax & eax) == 0) goto L591059;  // @167_590e20
  PV[16] = (u32)(esi);  // @168_590e20
  ecx = eax;  // @169_590e20
  eax = ext_5e0ff0_thiscall3(ecx, PV[16], (u32)(14));  // @170_590e20
  ecx = edx = 0;  // @171_590e20
  ecx = eax;  // @172_590e20
  goto L59105b;  // @173_590e20
  L591059:;
  ecx = 0;  // @175_590e20
  L59105b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_590e20
  PV[17] = (u32)(ecx);  // @178_590e20
  ecx = esi;  // @179_590e20
  reg.state = (s32)((u32)(4294967295));  // @180_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, PV[17]);  // @181_590e20
  ecx = edx = 0;  // @182_590e20
  SEH_LEAVE();  // @183_590e20
  return eax;  // @184_590e20
}
PCREG(590e20, lifted_590e20);

extern "C" u32 THISCALL lifted_5b8b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x663fdf);  // @h_5b8b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5b8b50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5b8b50
  eax = (u32)(esi + 72);  // @2_5b8b50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_5b8b50
  ecx = edi;  // @4_5b8b50
  PV[0] = (u32)(eax);  // @5_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @6_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[0]);  // @7_5b8b50
  ecx = edx = 0;  // @8_5b8b50
  eax = ext_41e290_cdecl1((u32)(28));  // @9_5b8b50
  ecx = edx = 0;  // @10_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_5b8b50
  reg.state = (s32)((u32)(0));  // @12_5b8b50
  if ((eax & eax) == 0) goto L5b8bb0;  // @13_5b8b50
  ecx = eax;  // @14_5b8b50
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @15_5b8b50
  ecx = edx = 0;  // @16_5b8b50
  ecx = eax;  // @17_5b8b50
  goto L5b8bb2;  // @18_5b8b50
  L5b8bb0:;
  ecx = 0;  // @20_5b8b50
  L5b8bb2:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @22_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_5b8b50
  PV[1] = (u32)(ecx);  // @24_5b8b50
  ecx = edi;  // @25_5b8b50
  reg.state = (s32)((u32)(4294967295));  // @26_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[1]);  // @27_5b8b50
  ecx = edx = 0;  // @28_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_5b8b50
  eax = (u32)(esi + 80);  // @30_5b8b50
  PV[2] = (u32)(eax);  // @31_5b8b50
  ecx = edi;  // @32_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[2]);  // @33_5b8b50
  ecx = edx = 0;  // @34_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_5b8b50
  eax = (u32)(esi + 84);  // @36_5b8b50
  PV[3] = (u32)(eax);  // @37_5b8b50
  ecx = edi;  // @38_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[3]);  // @39_5b8b50
  ecx = edx = 0;  // @40_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_5b8b50
  eax = (u32)(esi + 88);  // @42_5b8b50
  PV[4] = (u32)(eax);  // @43_5b8b50
  ecx = edi;  // @44_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[4]);  // @45_5b8b50
  ecx = edx = 0;  // @46_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_5b8b50
  eax = (u32)(esi + 92);  // @48_5b8b50
  PV[5] = (u32)(eax);  // @49_5b8b50
  ecx = edi;  // @50_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[5]);  // @51_5b8b50
  ecx = edx = 0;  // @52_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @53_5b8b50
  ecx = (u32)(EBP + 8);  // @54_5b8b50
  PV[6] = (u32)(ecx);  // @55_5b8b50
  ecx = edi;  // @56_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[6]);  // @57_5b8b50
  ecx = edx = 0;  // @58_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_5b8b50
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @60_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[7]);  // @63_5b8b50
  ecx = edx = 0;  // @64_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @65_5b8b50
  ecx = (u32)(EBP + 8);  // @66_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_5b8b50
  PV[8] = (u32)(ecx);  // @68_5b8b50
  ecx = edi;  // @69_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[8]);  // @70_5b8b50
  ecx = edx = 0;  // @71_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_5b8b50
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @73_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @74_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @76_5b8b50
  ecx = edx = 0;  // @77_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @78_5b8b50
  ecx = (u32)(EBP + 8);  // @79_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_5b8b50
  PV[10] = (u32)(ecx);  // @81_5b8b50
  ecx = edi;  // @82_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[10]);  // @83_5b8b50
  ecx = edx = 0;  // @84_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_5b8b50
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @86_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @89_5b8b50
  ecx = edx = 0;  // @90_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 134), &v, sizeof v); }  // @91_5b8b50
  ecx = edi;  // @92_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @93_5b8b50
  eax = (u32)(esi + 138);  // @94_5b8b50
  PV[12] = (u32)(eax);  // @95_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[12]);  // @96_5b8b50
  ecx = edx = 0;  // @97_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @98_5b8b50
  eax = (u32)(esi + 150);  // @99_5b8b50
  PV[13] = (u32)(eax);  // @100_5b8b50
  ecx = edi;  // @101_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[13]);  // @102_5b8b50
  ecx = edx = 0;  // @103_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @104_5b8b50
  eax = (u32)(esi + 162);  // @105_5b8b50
  PV[14] = (u32)(eax);  // @106_5b8b50
  ecx = edi;  // @107_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[14]);  // @108_5b8b50
  ecx = edx = 0;  // @109_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @110_5b8b50
  eax = (u32)(esi + 174);  // @111_5b8b50
  PV[15] = (u32)(eax);  // @112_5b8b50
  ecx = edi;  // @113_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[15]);  // @114_5b8b50
  ecx = edx = 0;  // @115_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_5b8b50
  eax = (u32)(esi + 178);  // @117_5b8b50
  PV[16] = (u32)(eax);  // @118_5b8b50
  ecx = edi;  // @119_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[16]);  // @120_5b8b50
  ecx = edx = 0;  // @121_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @122_5b8b50
  eax = (u32)(esi + 179);  // @123_5b8b50
  PV[17] = (u32)(eax);  // @124_5b8b50
  ecx = edi;  // @125_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[17]);  // @126_5b8b50
  ecx = edx = 0;  // @127_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @128_5b8b50
  eax = (u32)(esi + 183);  // @129_5b8b50
  PV[18] = (u32)(eax);  // @130_5b8b50
  ecx = edi;  // @131_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, PV[18]);  // @132_5b8b50
  ecx = edx = 0;  // @133_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @134_5b8b50
  ecx = (u32)(EBP + 8);  // @135_5b8b50
  PV[19] = (u32)(ecx);  // @136_5b8b50
  ecx = edi;  // @137_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[19]);  // @138_5b8b50
  ecx = edx = 0;  // @139_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @140_5b8b50
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @141_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @142_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[20]);  // @144_5b8b50
  ecx = edx = 0;  // @145_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @146_5b8b50
  ecx = edi;  // @147_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @148_5b8b50
  eax = (u32)(esi + 222);  // @149_5b8b50
  PV[21] = (u32)(eax);  // @150_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[21]);  // @151_5b8b50
  ecx = edx = 0;  // @152_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @153_5b8b50
  ecx = (u32)(EBP + 8);  // @154_5b8b50
  PV[22] = (u32)(ecx);  // @155_5b8b50
  ecx = edi;  // @156_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[22]);  // @157_5b8b50
  ecx = edx = 0;  // @158_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @159_5b8b50
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @160_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @161_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[23]);  // @163_5b8b50
  ecx = edx = 0;  // @164_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @165_5b8b50
  ecx = (u32)(EBP - 16);  // @166_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @167_5b8b50
  PV[24] = (u32)(ecx);  // @168_5b8b50
  ecx = edi;  // @169_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[24]);  // @170_5b8b50
  ecx = edx = 0;  // @171_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @172_5b8b50
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @173_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @174_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[25]);  // @176_5b8b50
  ecx = edx = 0;  // @177_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 230), &v, sizeof v); }  // @178_5b8b50
  ecx = edi;  // @179_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @180_5b8b50
  eax = (u32)(esi + 234);  // @181_5b8b50
  PV[26] = (u32)(eax);  // @182_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[26]);  // @183_5b8b50
  ecx = edx = 0;  // @184_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @185_5b8b50
  eax = (u32)(esi + 221);  // @186_5b8b50
  PV[27] = (u32)(eax);  // @187_5b8b50
  ecx = edi;  // @188_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[27]);  // @189_5b8b50
  ecx = edx = 0;  // @190_5b8b50
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @191_5b8b50
  SEH_LEAVE();  // @192_5b8b50
  return eax;  // @193_5b8b50
}
PCREG(5b8b50, lifted_5b8b50);

extern "C" u32 THISCALL lifted_4335e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665608);  // @h_4335e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4335e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @1_4335e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4335e0
  esi = (esi + (u32)(200));  // @3_4335e0
  if (esi == 0) goto L43370a;  // @4_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_4335e0
  ecx = (u32)(EBP - 416);  // @6_4335e0
  PV[0] = (u32)(ecx);  // @7_4335e0
  ecx = esi;  // @8_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @9_4335e0
  ecx = edx = 0;  // @10_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_4335e0
  ecx = (u32)(EBP - 416);  // @12_4335e0
  PV[1] = (u32)(ecx);  // @13_4335e0
  ecx = esi;  // @14_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @15_4335e0
  ecx = edx = 0;  // @16_4335e0
  edi = eax;  // @17_4335e0
  if ((edi & edi) == 0) goto L43370a;  // @18_4335e0
  L433650:;
  ecx = (u32)(EBP - 144);  // @20_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791768));  // @21_4335e0
  ecx = edx = 0;  // @22_4335e0
  eax = (u32)(EBP - 144);  // @23_4335e0
  reg.state = (s32)((u32)(0));  // @24_4335e0
  PV[2] = (u32)(eax);  // @25_4335e0
  ecx = ebx;  // @26_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[2]);  // @27_4335e0
  ecx = edx = 0;  // @28_4335e0
  ecx = (u32)(EBP - 144);  // @29_4335e0
  reg.state = (s32)((u32)(4294967295));  // @30_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @31_4335e0
  ecx = edx = 0;  // @32_4335e0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @33_4335e0
  ecx = (u32)(EBP - 144);  // @34_4335e0
  eax = ext_4cbe80_thiscall2(ecx, PV[3]);  // @35_4335e0
  ecx = edx = 0;  // @36_4335e0
  eax = (u32)(EBP - 144);  // @37_4335e0
  reg.state = (s32)((u32)(1));  // @38_4335e0
  PV[4] = (u32)(eax);  // @39_4335e0
  ecx = ebx;  // @40_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[4]);  // @41_4335e0
  ecx = edx = 0;  // @42_4335e0
  ecx = (u32)(EBP - 144);  // @43_4335e0
  reg.state = (s32)((u32)(4294967295));  // @44_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @45_4335e0
  ecx = edx = 0;  // @46_4335e0
  ecx = (u32)(EBP - 144);  // @47_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6778092));  // @48_4335e0
  ecx = edx = 0;  // @49_4335e0
  eax = (u32)(EBP - 144);  // @50_4335e0
  reg.state = (s32)((u32)(2));  // @51_4335e0
  PV[5] = (u32)(eax);  // @52_4335e0
  ecx = ebx;  // @53_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[5]);  // @54_4335e0
  ecx = edx = 0;  // @55_4335e0
  ecx = (u32)(EBP - 144);  // @56_4335e0
  reg.state = (s32)((u32)(4294967295));  // @57_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @58_4335e0
  ecx = edx = 0;  // @59_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_4335e0
  ecx = (u32)(EBP - 416);  // @61_4335e0
  PV[6] = (u32)(ecx);  // @62_4335e0
  ecx = esi;  // @63_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[6]);  // @64_4335e0
  ecx = edx = 0;  // @65_4335e0
  edi = eax;  // @66_4335e0
  if ((edi & edi) != 0) goto L433650;  // @67_4335e0
  L43370a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @69_4335e0
  esi = (esi + (u32)(172));  // @70_4335e0
  if (esi == 0) goto L43386c;  // @71_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_4335e0
  ecx = (u32)(EBP - 428);  // @73_4335e0
  PV[7] = (u32)(ecx);  // @74_4335e0
  ecx = esi;  // @75_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @76_4335e0
  ecx = edx = 0;  // @77_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_4335e0
  ecx = (u32)(EBP - 428);  // @79_4335e0
  PV[8] = (u32)(ecx);  // @80_4335e0
  ecx = esi;  // @81_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @82_4335e0
  ecx = edx = 0;  // @83_4335e0
  edi = eax;  // @84_4335e0
  if ((edi & edi) == 0) goto L43386c;  // @85_4335e0
  L433750:;
  ecx = (u32)(EBP - 144);  // @87_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791760));  // @88_4335e0
  ecx = edx = 0;  // @89_4335e0
  eax = (u32)(EBP - 144);  // @90_4335e0
  reg.state = (s32)((u32)(3));  // @91_4335e0
  PV[9] = (u32)(eax);  // @92_4335e0
  ecx = ebx;  // @93_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[9]);  // @94_4335e0
  ecx = edx = 0;  // @95_4335e0
  ecx = (u32)(EBP - 144);  // @96_4335e0
  reg.state = (s32)((u32)(4294967295));  // @97_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @98_4335e0
  ecx = edx = 0;  // @99_4335e0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @100_4335e0
  ecx = (u32)(EBP - 144);  // @101_4335e0
  eax = ext_4cbe80_thiscall2(ecx, PV[10]);  // @102_4335e0
  ecx = edx = 0;  // @103_4335e0
  eax = (u32)(EBP - 144);  // @104_4335e0
  reg.state = (s32)((u32)(4));  // @105_4335e0
  PV[11] = (u32)(eax);  // @106_4335e0
  ecx = ebx;  // @107_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[11]);  // @108_4335e0
  ecx = edx = 0;  // @109_4335e0
  ecx = (u32)(EBP - 144);  // @110_4335e0
  reg.state = (s32)((u32)(4294967295));  // @111_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @112_4335e0
  ecx = edx = 0;  // @113_4335e0
  ecx = (u32)(EBP - 144);  // @114_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791776));  // @115_4335e0
  ecx = edx = 0;  // @116_4335e0
  eax = (u32)(EBP - 144);  // @117_4335e0
  reg.state = (s32)((u32)(5));  // @118_4335e0
  PV[12] = (u32)(eax);  // @119_4335e0
  ecx = ebx;  // @120_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[12]);  // @121_4335e0
  ecx = edx = 0;  // @122_4335e0
  ecx = (u32)(EBP - 144);  // @123_4335e0
  reg.state = (s32)((u32)(4294967295));  // @124_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @125_4335e0
  ecx = edx = 0;  // @126_4335e0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @127_4335e0
  ecx = (u32)(EBP - 400);  // @128_4335e0
  eax = ext_4cbe50_thiscall2(ecx, PV[13]);  // @129_4335e0
  ecx = edx = 0;  // @130_4335e0
  eax = (u32)(EBP - 400);  // @131_4335e0
  reg.state = (s32)((u32)(6));  // @132_4335e0
  PV[14] = (u32)(eax);  // @133_4335e0
  ecx = ebx;  // @134_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[14]);  // @135_4335e0
  ecx = edx = 0;  // @136_4335e0
  ecx = (u32)(EBP - 272);  // @137_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6778092));  // @138_4335e0
  ecx = edx = 0;  // @139_4335e0
  eax = (u32)(EBP - 272);  // @140_4335e0
  reg.state = (s32)((u32)(7));  // @141_4335e0
  PV[15] = (u32)(eax);  // @142_4335e0
  ecx = ebx;  // @143_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, PV[15]);  // @144_4335e0
  ecx = edx = 0;  // @145_4335e0
  ecx = (u32)(EBP - 272);  // @146_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @147_4335e0
  ecx = edx = 0;  // @148_4335e0
  ecx = (u32)(EBP - 400);  // @149_4335e0
  reg.state = (s32)((u32)(4294967295));  // @150_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @151_4335e0
  ecx = edx = 0;  // @152_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @153_4335e0
  ecx = (u32)(EBP - 428);  // @154_4335e0
  PV[16] = (u32)(ecx);  // @155_4335e0
  ecx = esi;  // @156_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[16]);  // @157_4335e0
  ecx = edx = 0;  // @158_4335e0
  edi = eax;  // @159_4335e0
  if ((edi & edi) != 0) goto L433750;  // @160_4335e0
  L43386c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @162_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_4335e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1134));  // @164_4335e0
  ecx = edx = 0;  // @165_4335e0
  esi = eax;  // @166_4335e0
  ecx = ebx;  // @167_4335e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_4335e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @169_4335e0
  ecx = edx = 0;  // @170_4335e0
  PV[17] = (u32)(eax);  // @171_4335e0
  PV[18] = (u32)(esi);  // @172_4335e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[18], (u32)(6791780), PV[17]);  // @173_4335e0
  ecx = edx = 0;  // @174_4335e0
  SEH_LEAVE();  // @175_4335e0
  ext_633654(G(u32, 0x6f5630));  // @176_4335e0
  return eax;  // @177_4335e0
}
PCREG(4335e0, lifted_4335e0);

