// batch230006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_457680_fastcall3(u32, u32, u32) __asm__("ext_457680");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_459c40(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_459c40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_459c40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @2_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 24) + 0), 4); v; });  // @3_459c40
  X0[1] = 0;  // @4_459c40
  X0[2] = 0;  // @5_459c40
  X0[3] = 0;  // @6_459c40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 208), sizeof v); (u32)v; });  // @7_459c40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 204), sizeof v); (u32)v; });  // @8_459c40
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @9_459c40
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @10_459c40
  if (__builtin_parity(FL[2] & 0xff)) goto L459de3;  // @11_459c40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 52), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @12_459c40
  if (FL[0] == FL[1]) goto L459f30;  // @13_459c40
  L459c85:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @15_459c40
  X0[1] = 0;  // @16_459c40
  X0[2] = 0;  // @17_459c40
  X0[3] = 0;  // @18_459c40
  edx = edi;  // @19_459c40
  PV[0] = (u32)(ecx);  // @20_459c40
  ecx = esi;  // @21_459c40
  PV[1] = X0[0];  // @22_459c40
  eax = ext_451890_fastcall3(ecx, edx, PV[1]);  // @23_459c40
  ecx = 0;  // @24_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 24) + 0), 4); v; });  // @25_459c40
  X0[1] = 0;  // @26_459c40
  X0[2] = 0;  // @27_459c40
  X0[3] = 0;  // @28_459c40
  edx = edi;  // @29_459c40
  PV[2] = (u32)(ecx);  // @30_459c40
  ecx = (u32)(esi + 32);  // @31_459c40
  PV[3] = X0[0];  // @32_459c40
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[3]);  // @33_459c40
    // @34_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_459c40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @36_459c40
  FL[0] = eax; FL[1] = ecx;  // @37_459c40
  if ((s32)FL[0] <= (s32)FL[1]) goto L459cd9;  // @38_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @39_459c40
  ecx = ebx;  // @40_459c40
  eax = (eax << (u32)(3));  // @41_459c40
  FL[3] = eax;  // @42_459c40
  eax = (eax | (u32)(1));  // @43_459c40
  FL[3] = eax;  // @44_459c40
  PV[4] = (u32)(eax);  // @45_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @46_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[4]);  // @47_459c40
  ecx = edx = 0;  // @48_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @49_459c40
  X0[1] = 0;  // @50_459c40
  X0[2] = 0;  // @51_459c40
  X0[3] = 0;  // @52_459c40
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @53_459c40
  goto L459cf7;  // @54_459c40
  L459cd9:;
  FL[2] = (eax & eax);  // @56_459c40
  if ((s32)FL[2] >= 0) goto L459d07;  // @57_459c40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) << (u32)(3))); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @58_459c40
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @59_459c40
  ecx = ebx;  // @60_459c40
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @61_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[5]);  // @62_459c40
  ecx = edx = 0;  // @63_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @64_459c40
  X0[1] = 0;  // @65_459c40
  X0[2] = 0;  // @66_459c40
  X0[3] = 0;  // @67_459c40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @68_459c40
  L459cf7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @70_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @71_459c40
  eax = (eax >> (u32)(16));  // @72_459c40
  FL[3] = eax;  // @73_459c40
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @74_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @75_459c40
  L459d07:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @77_459c40
  FL[0] = eax; FL[1] = ecx;  // @78_459c40
  if ((s32)FL[0] <= (s32)FL[1]) goto L459d31;  // @79_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @80_459c40
  ecx = ebx;  // @81_459c40
  eax = (eax << (u32)(3));  // @82_459c40
  FL[3] = eax;  // @83_459c40
  eax = (eax | (u32)(3));  // @84_459c40
  FL[3] = eax;  // @85_459c40
  PV[6] = (u32)(eax);  // @86_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @87_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[6]);  // @88_459c40
  ecx = edx = 0;  // @89_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @90_459c40
  X0[1] = 0;  // @91_459c40
  X0[2] = 0;  // @92_459c40
  X0[3] = 0;  // @93_459c40
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @94_459c40
  goto L459d56;  // @95_459c40
  L459d31:;
  FL[2] = (eax & eax);  // @97_459c40
  if ((s32)FL[2] >= 0) goto L459d67;  // @98_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @99_459c40
  ecx = ebx;  // @100_459c40
  eax = (eax << (u32)(3));  // @101_459c40
  FL[3] = eax;  // @102_459c40
  eax = (eax | (u32)(2));  // @103_459c40
  FL[3] = eax;  // @104_459c40
  PV[7] = (u32)(eax);  // @105_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @106_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[7]);  // @107_459c40
  ecx = edx = 0;  // @108_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @109_459c40
  X0[1] = 0;  // @110_459c40
  X0[2] = 0;  // @111_459c40
  X0[3] = 0;  // @112_459c40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @113_459c40
  L459d56:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @115_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @116_459c40
  eax = (eax >> (u32)(16));  // @117_459c40
  FL[3] = eax;  // @118_459c40
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @119_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @120_459c40
  L459d67:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @122_459c40
  FL[0] = eax; FL[1] = ecx;  // @123_459c40
  if ((s32)FL[0] <= (s32)FL[1]) goto L459d91;  // @124_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @125_459c40
  ecx = ebx;  // @126_459c40
  eax = (eax << (u32)(3));  // @127_459c40
  FL[3] = eax;  // @128_459c40
  eax = (eax | (u32)(5));  // @129_459c40
  FL[3] = eax;  // @130_459c40
  PV[8] = (u32)(eax);  // @131_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @132_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[8]);  // @133_459c40
  ecx = edx = 0;  // @134_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @135_459c40
  X0[1] = 0;  // @136_459c40
  X0[2] = 0;  // @137_459c40
  X0[3] = 0;  // @138_459c40
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @139_459c40
  goto L459db6;  // @140_459c40
  L459d91:;
  FL[2] = (eax & eax);  // @142_459c40
  if ((s32)FL[2] >= 0) goto L459dc4;  // @143_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @144_459c40
  ecx = ebx;  // @145_459c40
  eax = (eax << (u32)(3));  // @146_459c40
  FL[3] = eax;  // @147_459c40
  eax = (eax | (u32)(4));  // @148_459c40
  FL[3] = eax;  // @149_459c40
  PV[9] = (u32)(eax);  // @150_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @151_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[9]);  // @152_459c40
  ecx = edx = 0;  // @153_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @154_459c40
  X0[1] = 0;  // @155_459c40
  X0[2] = 0;  // @156_459c40
  X0[3] = 0;  // @157_459c40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @158_459c40
  L459db6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @160_459c40
  eax = (eax >> (u32)(16));  // @161_459c40
  FL[3] = eax;  // @162_459c40
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @163_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @164_459c40
  L459dc4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @166_459c40
  edi = (edi + (u32)(16));  // @167_459c40
  FL[3] = edi;  // @168_459c40
  eax = (eax + 1);  // @169_459c40
  FL[3] = eax;  // @170_459c40
  esi = (esi + (u32)(48));  // @171_459c40
  FL[3] = esi;  // @172_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @173_459c40
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 52), sizeof v); (u32)v; });  // @174_459c40
  if (FL[0] != FL[1]) goto L459c85;  // @175_459c40
  return eax;  // @176_459c40
  L459de3:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 52), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @178_459c40
  if (FL[0] == FL[1]) goto L459f30;  // @179_459c40
  L459df0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @181_459c40
  X0[1] = 0;  // @182_459c40
  X0[2] = 0;  // @183_459c40
  X0[3] = 0;  // @184_459c40
  edx = edi;  // @185_459c40
  PV[10] = (u32)(ecx);  // @186_459c40
  ecx = esi;  // @187_459c40
  PV[11] = X0[0];  // @188_459c40
  eax = ext_451890_fastcall3(ecx, edx, PV[11]);  // @189_459c40
  ecx = 0;  // @190_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @191_459c40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @192_459c40
  FL[0] = eax; FL[1] = ecx;  // @193_459c40
  if ((s32)FL[0] <= (s32)FL[1]) goto L459e2f;  // @194_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @195_459c40
  ecx = ebx;  // @196_459c40
  eax = (eax << (u32)(3));  // @197_459c40
  FL[3] = eax;  // @198_459c40
  eax = (eax | (u32)(1));  // @199_459c40
  FL[3] = eax;  // @200_459c40
  PV[12] = (u32)(eax);  // @201_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @202_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[12]);  // @203_459c40
  ecx = edx = 0;  // @204_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @205_459c40
  X0[1] = 0;  // @206_459c40
  X0[2] = 0;  // @207_459c40
  X0[3] = 0;  // @208_459c40
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @209_459c40
  goto L459e4d;  // @210_459c40
  L459e2f:;
  FL[2] = (eax & eax);  // @212_459c40
  if ((s32)FL[2] >= 0) goto L459e5d;  // @213_459c40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) << (u32)(3))); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @214_459c40
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @215_459c40
  ecx = ebx;  // @216_459c40
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @217_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[13]);  // @218_459c40
  ecx = edx = 0;  // @219_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @220_459c40
  X0[1] = 0;  // @221_459c40
  X0[2] = 0;  // @222_459c40
  X0[3] = 0;  // @223_459c40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @224_459c40
  L459e4d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @226_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @227_459c40
  eax = (eax >> (u32)(16));  // @228_459c40
  FL[3] = eax;  // @229_459c40
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @230_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @231_459c40
  L459e5d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @233_459c40
  FL[0] = eax; FL[1] = ecx;  // @234_459c40
  if ((s32)FL[0] <= (s32)FL[1]) goto L459e87;  // @235_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @236_459c40
  ecx = ebx;  // @237_459c40
  eax = (eax << (u32)(3));  // @238_459c40
  FL[3] = eax;  // @239_459c40
  eax = (eax | (u32)(3));  // @240_459c40
  FL[3] = eax;  // @241_459c40
  PV[14] = (u32)(eax);  // @242_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @243_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[14]);  // @244_459c40
  ecx = edx = 0;  // @245_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @246_459c40
  X0[1] = 0;  // @247_459c40
  X0[2] = 0;  // @248_459c40
  X0[3] = 0;  // @249_459c40
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @250_459c40
  goto L459eac;  // @251_459c40
  L459e87:;
  FL[2] = (eax & eax);  // @253_459c40
  if ((s32)FL[2] >= 0) goto L459ebd;  // @254_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @255_459c40
  ecx = ebx;  // @256_459c40
  eax = (eax << (u32)(3));  // @257_459c40
  FL[3] = eax;  // @258_459c40
  eax = (eax | (u32)(2));  // @259_459c40
  FL[3] = eax;  // @260_459c40
  PV[15] = (u32)(eax);  // @261_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @262_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[15]);  // @263_459c40
  ecx = edx = 0;  // @264_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @265_459c40
  X0[1] = 0;  // @266_459c40
  X0[2] = 0;  // @267_459c40
  X0[3] = 0;  // @268_459c40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @269_459c40
  L459eac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @271_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @272_459c40
  eax = (eax >> (u32)(16));  // @273_459c40
  FL[3] = eax;  // @274_459c40
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @275_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @276_459c40
  L459ebd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @278_459c40
  FL[0] = eax; FL[1] = ecx;  // @279_459c40
  if ((s32)FL[0] <= (s32)FL[1]) goto L459ee7;  // @280_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @281_459c40
  ecx = ebx;  // @282_459c40
  eax = (eax << (u32)(3));  // @283_459c40
  FL[3] = eax;  // @284_459c40
  eax = (eax | (u32)(5));  // @285_459c40
  FL[3] = eax;  // @286_459c40
  PV[16] = (u32)(eax);  // @287_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @288_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[16]);  // @289_459c40
  ecx = edx = 0;  // @290_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @291_459c40
  X0[1] = 0;  // @292_459c40
  X0[2] = 0;  // @293_459c40
  X0[3] = 0;  // @294_459c40
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @295_459c40
  goto L459f0c;  // @296_459c40
  L459ee7:;
  FL[2] = (eax & eax);  // @298_459c40
  if ((s32)FL[2] >= 0) goto L459f1a;  // @299_459c40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @300_459c40
  ecx = ebx;  // @301_459c40
  eax = (eax << (u32)(3));  // @302_459c40
  FL[3] = eax;  // @303_459c40
  eax = (eax | (u32)(4));  // @304_459c40
  FL[3] = eax;  // @305_459c40
  PV[17] = (u32)(eax);  // @306_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @307_459c40
  eax = ext_457680_fastcall3(ecx, edx, PV[17]);  // @308_459c40
  ecx = edx = 0;  // @309_459c40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @310_459c40
  X0[1] = 0;  // @311_459c40
  X0[2] = 0;  // @312_459c40
  X0[3] = 0;  // @313_459c40
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @314_459c40
  L459f0c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @316_459c40
  eax = (eax >> (u32)(16));  // @317_459c40
  FL[3] = eax;  // @318_459c40
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @319_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @320_459c40
  L459f1a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @322_459c40
  edi = (edi + (u32)(16));  // @323_459c40
  FL[3] = edi;  // @324_459c40
  eax = (eax + 1);  // @325_459c40
  FL[3] = eax;  // @326_459c40
  esi = (esi + (u32)(32));  // @327_459c40
  FL[3] = esi;  // @328_459c40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @329_459c40
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 52), sizeof v); (u32)v; });  // @330_459c40
  if (FL[0] != FL[1]) goto L459df0;  // @331_459c40
  L459f30:;
  return eax;  // @333_459c40
}
PCREG(459c40, lifted_459c40);

