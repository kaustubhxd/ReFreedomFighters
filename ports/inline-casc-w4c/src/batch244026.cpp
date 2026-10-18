// batch244026.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_54abf0_thiscall1(u32) __asm__("ext_54abf0");
extern "C" u32 THISCALL ext_6361e0_thiscall1(u32) __asm__("ext_6361e0");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_637a30_thiscall3(u32, u32, u32) __asm__("ext_637a30");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_612c00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e338);  // @h_612c00
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_612c00
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_612c00
  ecx = (u32)(EBP - 64);  // @2_612c00
  eax = ext_6361e0_thiscall1(ecx);  // @3_612c00
    // @4_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_612c00
  ecx = ebx;  // @6_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139296), sizeof v); (u32)v; });  // @7_612c00
  reg.state = (s32)((u32)(0));  // @8_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @9_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @10_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @11_612c00
  ecx = edx = 0;  // @12_612c00
  FL[0] = eax; FL[1] = (u32)(1146639409);  // @13_612c00
  if (FL[0] != FL[1]) goto L612c65;  // @14_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139304), sizeof v); (u32)v; });  // @15_612c00
  goto L612c79;  // @16_612c00
  L612c65:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_612c00
  ecx = ebx;  // @19_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @20_612c00
  ecx = edx = 0;  // @21_612c00
  FL[0] = eax; FL[1] = (u32)(1146639411);  // @22_612c00
  if (FL[0] != FL[1]) goto L612c83;  // @23_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139308), sizeof v); (u32)v; });  // @24_612c00
  L612c79:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @26_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @27_612c00
  L612c83:;
  FL[2] = (edi & edi);  // @29_612c00
  if (FL[2] != 0) goto L612c97;  // @30_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139296), sizeof v); (u32)v; });  // @31_612c00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @32_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @33_612c00
  L612c97:;
  FL[0] = edi; FL[1] = (u32)(25);  // @35_612c00
  if (FL[0] == FL[1]) goto L612ca1;  // @36_612c00
  FL[0] = edi; FL[1] = (u32)(26);  // @37_612c00
  if (FL[0] != FL[1]) goto L612ca8;  // @38_612c00
  L612ca1:;
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @40_612c00
  L612ca8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_612c00
  ecx = ebx;  // @43_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @44_612c00
  ecx = edx = 0;  // @45_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @48_612c00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 147), sizeof v); (u32)v; });  // @49_612c00
  ecx = (u32)(eax - 1);  // @50_612c00
  FL[0] = ecx; FL[1] = edi;  // @51_612c00
  if (FL[0] < FL[1]) edi = ecx;  // @52_612c00
  ecx = ebx;  // @53_612c00
  PV[0] = (u32)(edi);  // @54_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[0]);  // @55_612c00
  ecx = edx = 0;  // @56_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @57_612c00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139316), sizeof v); (u32)v; });  // @58_612c00
  if (FL[0] > FL[1]) goto L612ce4;  // @59_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @60_612c00
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139320), sizeof v); (u32)v; });  // @61_612c00
  if (FL[0] <= FL[1]) goto L612d24;  // @62_612c00
  L612ce4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @64_612c00
  if (FL[0] != FL[1]) goto L612d03;  // @65_612c00
  PV[1] = (u32)(ebx);  // @66_612c00
  ecx = (u32)(EBP - 64);  // @67_612c00
  eax = ext_637a30_thiscall3(ecx, PV[1], (u32)(1));  // @68_612c00
  ecx = edx = 0;  // @69_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @70_612c00
  ebx = (u32)(EBP - 64);  // @71_612c00
  ecx = ebx;  // @72_612c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @73_612c00
  ecx = edx = 0;  // @74_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @75_612c00
  L612d03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @77_612c00
  ecx = ebx;  // @78_612c00
  PV[2] = (u32)(edi);  // @79_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[2]);  // @80_612c00
  ecx = edx = 0;  // @81_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @82_612c00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139316), sizeof v); (u32)v; });  // @83_612c00
  if (FL[0] > FL[1]) goto L612d21;  // @84_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @85_612c00
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139320), sizeof v); (u32)v; });  // @86_612c00
  if (FL[0] <= FL[1]) goto L612d24;  // @87_612c00
  L612d21:;
  edi = (edi + 1);  // @89_612c00
  FL[3] = edi;  // @90_612c00
  goto L612d03;  // @91_612c00
  L612d24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @93_612c00
  ecx = ebx;  // @94_612c00
  PV[3] = (u32)(edi);  // @95_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[3]);  // @96_612c00
  ecx = edx = 0;  // @97_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139268), sizeof v); (u32)v; });  // @98_612c00
  ecx = (u32)(EBP - 84);  // @99_612c00
  PV[4] = (u32)(ecx);  // @100_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @101_612c00
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @102_612c00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @103_612c00
  ecx = (ecx - edi);  // @104_612c00
  FL[3] = ecx;  // @105_612c00
  PV[6] = (u32)(ecx);  // @106_612c00
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @107_612c00
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @108_612c00
  PV[9] = (u32)(edx);  // @109_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 80)))(ecx, PV[9], PV[8], PV[7], PV[6], (u32)(0), PV[5], (u32)(1), PV[4]);  // @110_612c00
  ecx = edx = 0;  // @111_612c00
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @112_612c00
  if (FL[0] != FL[1]) goto L612d7a;  // @113_612c00
  { u32 v = (u32)((u32)(4278190080)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @114_612c00
  { u32 v = (u32)((u32)(16711680)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @115_612c00
  { u32 v = (u32)((u32)(65280)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @116_612c00
  { u32 v = (u32)((u32)(255)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @117_612c00
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @118_612c00
  goto L612dc1;  // @119_612c00
  L612d7a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }); FL[1] = (u32)(25);  // @121_612c00
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @122_612c00
  if (FL[0] != FL[1]) goto L612da5;  // @123_612c00
  { u32 v = (u32)((u32)(32768)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @124_612c00
  { u32 v = (u32)((u32)(31744)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @125_612c00
  { u32 v = (u32)((u32)(992)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @126_612c00
  { u32 v = (u32)((u32)(31)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @127_612c00
  goto L612dc1;  // @128_612c00
  L612da5:;
  { u32 v = (u32)((u32)(61440)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @130_612c00
  { u32 v = (u32)((u32)(3840)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @131_612c00
  { u32 v = (u32)((u32)(240)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @132_612c00
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @133_612c00
  L612dc1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @135_612c00
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @136_612c00
  if (FL[0] >= FL[1]) goto L612e3e;  // @137_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @138_612c00
  L612dd1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_612c00
  ecx = ebx;  // @141_612c00
  PV[10] = (u32)(edi);  // @142_612c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 56)))(ecx, PV[10]);  // @143_612c00
  ecx = edx = 0;  // @144_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @145_612c00
  esi = eax;  // @146_612c00
  eax = (u32)(EBP - 80);  // @147_612c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_612c00
  PV[11] = (u32)(eax);  // @149_612c00
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @150_612c00
  PV[13] = (u32)(ecx);  // @151_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[13], PV[12], PV[11], (u32)(0), (u32)(0));  // @152_612c00
  ecx = edx = 0;  // @153_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @154_612c00
  ecx = (u32)(EBP - 132);  // @155_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @156_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @157_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @158_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @159_612c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @160_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @161_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @162_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @163_612c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @164_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @165_612c00
  PV[14] = (u32)(edi);  // @166_612c00
  PV[15] = (u32)(ecx);  // @167_612c00
  ecx = ebx;  // @168_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[15], PV[14]);  // @169_612c00
  ecx = edx = 0;  // @170_612c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @171_612c00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @172_612c00
  PV[16] = (u32)(esi);  // @173_612c00
  PV[17] = (u32)(eax);  // @174_612c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @175_612c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 68)))(ecx, PV[17], PV[16]);  // @176_612c00
  ecx = edx = 0;  // @177_612c00
  edi = (edi + 1);  // @178_612c00
  FL[3] = edi;  // @179_612c00
  esi = (esi + 1);  // @180_612c00
  FL[3] = esi;  // @181_612c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @182_612c00
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @183_612c00
  if (FL[0] < FL[1]) goto L612dd1;  // @184_612c00
  L612e3e:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @186_612c00
  ecx = (u32)(EBP - 64);  // @187_612c00
  eax = ext_6363a0_thiscall1(ecx);  // @188_612c00
  ecx = edx = 0;  // @189_612c00
  eax = esi;  // @190_612c00
  SEH_LEAVE();  // @191_612c00
  ext_633654(G(u32, 0x6f5630));  // @192_612c00
  return eax;  // @193_612c00
}
PCREG(612c00, lifted_612c00);

extern "C" u32 THISCALL lifted_5338b0(u32 ecx_in) {
  SEH_ENTER(0x66a7d2);  // @h_5338b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5338b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21614), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_5338b0
  if (FL[0] == FL[1]) goto L533ad2;  // @2_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 592)))(ecx);  // @4_5338b0
  ecx = edx = 0;  // @5_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_5338b0
  ecx = esi;  // @7_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 396)))(ecx);  // @8_5338b0
  ecx = edx = 0;  // @9_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @12_5338b0
  ecx = edx = 0;  // @13_5338b0
  edi = eax;  // @14_5338b0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @15_5338b0
  ebx = 0;  // @16_5338b0
  FL[3] = ebx;  // @17_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @18_5338b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 14), &v, sizeof v); }  // @19_5338b0
  FL[2] = (edi & edi);  // @20_5338b0
  if (FL[2] == 0) goto L533979;  // @21_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_5338b0
  ecx = edi;  // @23_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(6953324));  // @24_5338b0
  ecx = edx = 0;  // @25_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_5338b0
  ebx = eax;  // @27_5338b0
  PV[0] = (u32)(ebx);  // @28_5338b0
  ecx = esi;  // @29_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 580)))(ecx, PV[0]);  // @30_5338b0
  ecx = edx = 0;  // @31_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_5338b0
  ecx = edi;  // @33_5338b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 262), sizeof v); (u32)v; })) & 0xff);  // @34_5338b0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @35_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6792092), (u32)(16));  // @36_5338b0
  ecx = edx = 0;  // @37_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @38_5338b0
  ecx = edi;  // @39_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @40_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6791240), (u32)(3));  // @41_5338b0
  ecx = edx = 0;  // @42_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_5338b0
  ecx = edi;  // @44_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6953336), (u32)(0));  // @45_5338b0
  ecx = edx = 0;  // @46_5338b0
  FL[2] = (eax & eax);  // @47_5338b0
  if (FL[2] == 0) goto L533979;  // @48_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 14), &v, sizeof v); }  // @49_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @50_5338b0
  L533979:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_5338b0
  ecx = esi;  // @53_5338b0
  PV[1] = (u32)(ebx);  // @54_5338b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @55_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 580)))(ecx, PV[1]);  // @56_5338b0
  ecx = edx = 0;  // @57_5338b0
  FL[2] = (eax & eax);  // @58_5338b0
  if (FL[2] == 0) goto L5339cf;  // @59_5338b0
  eax = ext_41e290_cdecl1((u32)(41693));  // @60_5338b0
  ecx = edx = 0;  // @61_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @62_5338b0
  reg.state = (s32)((u32)(0));  // @63_5338b0
  FL[2] = (eax & eax);  // @64_5338b0
  if (FL[2] == 0) goto L5339b5;  // @65_5338b0
  ecx = eax;  // @66_5338b0
  eax = ext_54abf0_thiscall1(ecx);  // @67_5338b0
  ecx = edx = 0;  // @68_5338b0
  ecx = eax;  // @69_5338b0
  goto L5339b7;  // @70_5338b0
  L5339b5:;
  ecx = 0;  // @72_5338b0
  FL[3] = ecx;  // @73_5338b0
  L5339b7:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 21642), &v, sizeof v); }  // @75_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_5338b0
  reg.state = (s32)((u32)(4294967295));  // @77_5338b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @78_5338b0
  ecx = edx = 0;  // @79_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @80_5338b0
  L5339cf:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @82_5338b0
  if (FL[0] == FL[1]) goto L533b1e;  // @83_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_5338b0
  ecx = esi;  // @85_5338b0
  PV[2] = (u32)(ebx);  // @86_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 580)))(ecx, PV[2]);  // @87_5338b0
  ecx = edx = 0;  // @88_5338b0
  edi = eax;  // @89_5338b0
  FL[2] = (edi & edi);  // @90_5338b0
  if (FL[2] == 0) goto L533a26;  // @91_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @92_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_5338b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6953036), (u32)(812));  // @94_5338b0
  ecx = edx = 0;  // @95_5338b0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 200), sizeof v); (u32)v; });  // @96_5338b0
  PV[3] = (u32)(ecx);  // @97_5338b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 196), sizeof v); (u32)v; });  // @98_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @99_5338b0
  ecx = (u32)(edi + 4);  // @100_5338b0
  PV[5] = (u32)(ecx);  // @101_5338b0
  ecx = (u32)(edi + 68);  // @102_5338b0
  PV[6] = (u32)(ecx);  // @103_5338b0
  PV[7] = (u32)(eax);  // @104_5338b0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))(PV[7], (u32)(6953356), PV[6], PV[5], PV[4], PV[3]);  // @105_5338b0
  ecx = edx = 0;  // @106_5338b0
  L533a26:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 196), sizeof v); (u32)v; });  // @108_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @109_5338b0
  FL[0] = ecx; FL[1] = eax;  // @110_5338b0
  if ((s32)FL[0] < (s32)FL[1]) ecx = eax;  // @111_5338b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; });  // @112_5338b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @113_5338b0
  ecx = 0;  // @114_5338b0
  FL[3] = ecx;  // @115_5338b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 200), sizeof v); (u32)v; }); FL[1] = (ecx & 0xff);  // @116_5338b0
  if (FL[0] != FL[1]) ecx = eax;  // @117_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @118_5338b0
  ebx = (ebx & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @119_5338b0
  eax = (eax + (u32)(-4));  // @120_5338b0
  FL[3] = eax;  // @121_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @122_5338b0
  PV[8] = (u32)(eax);  // @123_5338b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 160)))(ecx, PV[8]);  // @125_5338b0
  ecx = edx = 0;  // @126_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @127_5338b0
  PV[9] = (u32)(ebx);  // @128_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, PV[9]);  // @130_5338b0
  ecx = edx = 0;  // @131_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @132_5338b0
  FL[2] = (eax & eax);  // @133_5338b0
  if (FL[2] == 0) goto L533a94;  // @134_5338b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 201), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @135_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @136_5338b0
  if (FL[0] != FL[1]) goto L533a8b;  // @137_5338b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 41596), &v, sizeof v); }  // @138_5338b0
  goto L533a94;  // @139_5338b0
  L533a8b:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 14), sizeof v); (u32)v; })) & 0xff);  // @141_5338b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 41596), &v, sizeof v); }  // @142_5338b0
  L533a94:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @144_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21634), sizeof v); (u32)v; });  // @145_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 41582), &v, sizeof v); }  // @146_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @147_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @149_5338b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @150_5338b0
  ecx = edx = 0;  // @151_5338b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @152_5338b0
  if (FL[2] != 0) goto L533ae6;  // @153_5338b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @154_5338b0
  FL[2] = (ecx & ecx);  // @155_5338b0
  if (FL[2] == 0) goto L533ac8;  // @156_5338b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @157_5338b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(1));  // @158_5338b0
  ecx = edx = 0;  // @159_5338b0
  L533ac8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21642), &v, sizeof v); }  // @161_5338b0
  L533ad2:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @163_5338b0
  FL[3] = (eax & 0xff);  // @164_5338b0
  SEH_LEAVE();  // @165_5338b0
  return eax;  // @166_5338b0
  L533ae6:;
  eax = (u32)(EBP - 28);  // @168_5338b0
  PV[10] = (u32)(eax);  // @169_5338b0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @170_5338b0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)0x67614c))((u32)(0), (u32)(0), (u32)(5454944), PV[11], (u32)(0), PV[10]);  // @171_5338b0
  ecx = edx = 0;  // @172_5338b0
  PV[12] = (u32)(eax);  // @173_5338b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21638), &v, sizeof v); }  // @174_5338b0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676150))(PV[12], (u32)(15));  // @175_5338b0
  ecx = edx = 0;  // @176_5338b0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21638), sizeof v); (u32)v; });  // @177_5338b0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676154))(PV[13], (u32)(1));  // @178_5338b0
  ecx = edx = 0;  // @179_5338b0
  L533b1e:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @181_5338b0
  SEH_LEAVE();  // @182_5338b0
  return eax;  // @183_5338b0
}
PCREG(5338b0, lifted_5338b0);

