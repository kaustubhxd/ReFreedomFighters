// batch244037.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" s32 VECTORCALL ext_633910(float f);
extern "C" u32 FASTCALL ext_60feb0_fastcall4(u32, u32, u32, u32) __asm__("ext_60feb0");
extern "C" u32 FASTCALL ext_60ff30_fastcall4(u32, u32, u32, u32) __asm__("ext_60ff30");
extern "C" u32 THISCALL ext_610070_thiscall2(u32, u32) __asm__("ext_610070");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_60f340(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @0_60f340
  X0[1] = 0;  // @1_60f340
  X0[2] = 0;  // @2_60f340
  X0[3] = 0;  // @3_60f340
  X2[0] = 0;  // @4_60f340
  X2[1] = 0;  // @5_60f340
  X2[2] = 0;  // @6_60f340
  X2[3] = 0;  // @7_60f340
  esi = ecx;  // @8_60f340
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @9_60f340
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X2[0], 4);  // @10_60f340
  if ((!(!(U2F(X2[0]) >= U2F(X0[0]))) && !(!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L60f385;  // @11_60f340
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @12_60f340
  X2[1] = 0;  // @13_60f340
  X2[2] = 0;  // @14_60f340
  X2[3] = 0;  // @15_60f340
  { float a_ = U2F(X2[0]), b_ = U2F(X0[0]); X2[0] = (a_ < b_) ? X2[0] : F2U(b_); }  // @16_60f340
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X2[0], 4);  // @17_60f340
  L60f385:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7490372) + 0), 4); v; });  // @19_60f340
  X0[1] = 0;  // @20_60f340
  X0[2] = 0;  // @21_60f340
  X0[3] = 0;  // @22_60f340
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @23_60f340
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @24_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959432) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959432) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @25_60f340
  X1[0] = X1[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @26_60f340
  X1[1] = X1[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @27_60f340
  X1[2] = X1[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @28_60f340
  X1[3] = X1[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @29_60f340
  if ((!(!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) && !(!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L60f8cd;  // @30_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_60f340
  __builtin_memcpy((void *)((u32)(7490372) + 0), &X2[0], 4);  // @32_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @33_60f340
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @34_60f340
  ecx = edx = 0;  // @35_60f340
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @36_60f340
  if (FL[2] == 0) goto L60f8c6;  // @37_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_60f340
  ecx = esi;  // @39_60f340
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @40_60f340
  ecx = edx = 0;  // @41_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_60f340
  ecx = esi;  // @43_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 216), sizeof v); (u32)v; });  // @44_60f340
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @45_60f340
  ecx = edx = 0;  // @46_60f340
  ecx = esi;  // @47_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @48_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_60f340
  X0[0] = F2U((float)(s32)X0[0]);  // @50_60f340
  X0[1] = F2U((float)(s32)X0[1]);  // @51_60f340
  X0[2] = F2U((float)(s32)X0[2]);  // @52_60f340
  X0[3] = F2U((float)(s32)X0[3]);  // @53_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 220), sizeof v); (u32)v; });  // @54_60f340
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X0[0], 4);  // @55_60f340
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @56_60f340
  ecx = edx = 0;  // @57_60f340
  ecx = esi;  // @58_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @59_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_60f340
  X0[0] = F2U((float)(s32)X0[0]);  // @61_60f340
  X0[1] = F2U((float)(s32)X0[1]);  // @62_60f340
  X0[2] = F2U((float)(s32)X0[2]);  // @63_60f340
  X0[3] = F2U((float)(s32)X0[3]);  // @64_60f340
  PV[0] = X0[0];  // @65_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @66_60f340
  X0[1] = 0;  // @67_60f340
  X0[2] = 0;  // @68_60f340
  X0[3] = 0;  // @69_60f340
  PV[1] = X0[0];  // @70_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 308)))(ecx, (u32)(0), (u32)(0), PV[1], PV[0]);  // @71_60f340
  ecx = edx = 0;  // @72_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_60f340
  PV[2] = (u32)(ecx);  // @74_60f340
  ecx = esi;  // @75_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 652)))(ecx, (u32)(0), (u32)(0), (u32)(0));  // @76_60f340
  ecx = edx = 0;  // @77_60f340
  PV[3] = (u32)(ecx);  // @78_60f340
  ecx = esi;  // @79_60f340
  eax = ext_610070_thiscall2(ecx, (u32)(0));  // @80_60f340
  ecx = edx = 0;  // @81_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_60f340
  ecx = esi;  // @83_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 332)))(ecx, (u32)(3204448256), (u32)(1056964608), (u32)(3204448256), (u32)(1056964608), (u32)(1056964608), (u32)(1092616192), (u32)(0));  // @84_60f340
  ecx = edx = 0;  // @85_60f340
  edi = (u32)(3);  // @86_60f340
  ecx = 0;  // @87_60f340
  FL[3] = ecx;  // @88_60f340
  edx = edi;  // @89_60f340
  eax = ext_60ff30_fastcall4(ecx, edx, (u32)(2), (u32)(0));  // @90_60f340
  ecx = edx = 0;  // @91_60f340
  edx = edi;  // @92_60f340
  ecx = 0;  // @93_60f340
  FL[3] = ecx;  // @94_60f340
  eax = ext_60feb0_fastcall4(ecx, edx, (u32)(2), (u32)(0));  // @95_60f340
  ecx = edx = 0;  // @96_60f340
  esi = (u32)(1);  // @97_60f340
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490056), sizeof v); (u32)v; }); FL[1] = esi;  // @98_60f340
  if (FL[0] <= FL[1]) goto L60f4d4;  // @99_60f340
  PV[4] = (u32)(esi);  // @100_60f340
  edx = esi;  // @101_60f340
  ecx = esi;  // @102_60f340
  eax = ext_60ff30_fastcall4(ecx, edx, (u32)(2), PV[4]);  // @103_60f340
  ecx = edx = 0;  // @104_60f340
  PV[5] = (u32)(esi);  // @105_60f340
  edx = esi;  // @106_60f340
  ecx = esi;  // @107_60f340
  eax = ext_60feb0_fastcall4(ecx, edx, (u32)(2), PV[5]);  // @108_60f340
  ecx = edx = 0;  // @109_60f340
  L60f4d4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489832), sizeof v); (u32)v; }); FL[1] = (u32)(5);  // @111_60f340
  if (FL[0] == FL[1]) goto L60f4f9;  // @112_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @113_60f340
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(7489832), &v, sizeof v); }  // @114_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @115_60f340
  PV[6] = (u32)(eax);  // @116_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[6], (u32)(19), (u32)(5));  // @117_60f340
  ecx = edx = 0;  // @118_60f340
  L60f4f9:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489836), sizeof v); (u32)v; }); FL[1] = (u32)(6);  // @120_60f340
  if (FL[0] == FL[1]) goto L60f51e;  // @121_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @122_60f340
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(7489836), &v, sizeof v); }  // @123_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @124_60f340
  PV[7] = (u32)(eax);  // @125_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[7], (u32)(20), (u32)(6));  // @126_60f340
  ecx = edx = 0;  // @127_60f340
  L60f51e:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489844), sizeof v); (u32)v; }); FL[1] = esi;  // @129_60f340
  if (FL[0] == FL[1]) goto L60f53e;  // @130_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @131_60f340
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7489844), &v, sizeof v); }  // @132_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @133_60f340
  PV[8] = (u32)(eax);  // @134_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[8], (u32)(27), (u32)(1));  // @135_60f340
  ecx = edx = 0;  // @136_60f340
  L60f53e:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489852), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @138_60f340
  if (FL[0] == FL[1]) goto L60f563;  // @139_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @140_60f340
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489852), &v, sizeof v); }  // @141_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @142_60f340
  PV[9] = (u32)(eax);  // @143_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[9], (u32)(14), (u32)(0));  // @144_60f340
  ecx = edx = 0;  // @145_60f340
  L60f563:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489896), sizeof v); (u32)v; }); FL[1] = (u32)(8);  // @147_60f340
  if (FL[0] == FL[1]) goto L60f588;  // @148_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @149_60f340
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(7489896), &v, sizeof v); }  // @150_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @151_60f340
  PV[10] = (u32)(eax);  // @152_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[10], (u32)(23), (u32)(8));  // @153_60f340
  ecx = edx = 0;  // @154_60f340
  L60f588:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489856), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @156_60f340
  if (FL[0] != FL[1]) goto L60f5b6;  // @157_60f340
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489840), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @158_60f340
  if (FL[0] == FL[1]) goto L60f5b6;  // @159_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @160_60f340
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489840), &v, sizeof v); }  // @161_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @162_60f340
  PV[11] = (u32)(eax);  // @163_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[11], (u32)(28), (u32)(0));  // @164_60f340
  ecx = edx = 0;  // @165_60f340
  L60f5b6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489864), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @167_60f340
  if (FL[0] == FL[1]) goto L60f5de;  // @168_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @169_60f340
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7489864), &v, sizeof v); }  // @170_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @171_60f340
  PV[12] = (u32)(eax);  // @172_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 200)))(ecx, PV[12], (u32)(137), (u32)(0));  // @173_60f340
  ecx = edx = 0;  // @174_60f340
  L60f5de:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @176_60f340
  eax = edi;  // @177_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273680), sizeof v); (u32)v; });  // @178_60f340
  eax = (eax >> (ecx & 0xff));  // @179_60f340
  FL[3] = eax;  // @180_60f340
  eax = (eax & 0xff);  // @181_60f340
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @182_60f340
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6827704) + 0), 4); v; });  // @183_60f340
  X2[1] = 0;  // @184_60f340
  X2[2] = 0;  // @185_60f340
  X2[3] = 0;  // @186_60f340
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @187_60f340
  X3[1] = 0;  // @188_60f340
  X3[2] = 0;  // @189_60f340
  X3[3] = 0;  // @190_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @191_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @192_60f340
  eax = (eax >> (u32)(31));  // @193_60f340
  FL[3] = eax;  // @194_60f340
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @195_60f340
  { u32 v = (u32)((u32)(196610)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @196_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @197_60f340
  eax = edx;  // @198_60f340
  eax = (eax >> (ecx & 0xff));  // @199_60f340
  FL[3] = eax;  // @200_60f340
  eax = (eax & 0xff);  // @201_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273684), sizeof v); (u32)v; });  // @202_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @203_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @204_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @205_60f340
  eax = (eax >> (u32)(31));  // @206_60f340
  FL[3] = eax;  // @207_60f340
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @208_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @209_60f340
  eax = edi;  // @210_60f340
  eax = (eax >> (ecx & 0xff));  // @211_60f340
  FL[3] = eax;  // @212_60f340
  eax = (eax & 0xff);  // @213_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @214_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @215_60f340
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @216_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @217_60f340
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @218_60f340
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X0[0], 4);  // @219_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @220_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @221_60f340
  eax = (eax >> (u32)(31));  // @222_60f340
  FL[3] = eax;  // @223_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @224_60f340
  eax = edx;  // @225_60f340
  eax = (eax >> (ecx & 0xff));  // @226_60f340
  FL[3] = eax;  // @227_60f340
  eax = (eax & 0xff);  // @228_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273688), sizeof v); (u32)v; });  // @229_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @230_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @231_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @232_60f340
  eax = (eax >> (u32)(31));  // @233_60f340
  FL[3] = eax;  // @234_60f340
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @235_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @236_60f340
  eax = edi;  // @237_60f340
  eax = (eax >> (ecx & 0xff));  // @238_60f340
  FL[3] = eax;  // @239_60f340
  eax = (eax & 0xff);  // @240_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @241_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @242_60f340
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @243_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @244_60f340
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @245_60f340
  __builtin_memcpy((void *)((u32)(EBP - 168) + 0), &X0[0], 4);  // @246_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @247_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @248_60f340
  eax = (eax >> (u32)(31));  // @249_60f340
  FL[3] = eax;  // @250_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @251_60f340
  eax = edx;  // @252_60f340
  eax = (eax >> (ecx & 0xff));  // @253_60f340
  FL[3] = eax;  // @254_60f340
  eax = (eax & 0xff);  // @255_60f340
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273692), sizeof v); (u32)v; });  // @256_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @257_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @258_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @259_60f340
  eax = (eax >> (u32)(31));  // @260_60f340
  FL[3] = eax;  // @261_60f340
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @262_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @263_60f340
  eax = edi;  // @264_60f340
  eax = (eax >> (ecx & 0xff));  // @265_60f340
  FL[3] = eax;  // @266_60f340
  eax = (eax & 0xff);  // @267_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @268_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @269_60f340
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @270_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @271_60f340
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @272_60f340
  __builtin_memcpy((void *)((u32)(EBP - 172) + 0), &X0[0], 4);  // @273_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @274_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @275_60f340
  eax = (eax >> (u32)(31));  // @276_60f340
  FL[3] = eax;  // @277_60f340
  edx = (edx >> (ecx & 0xff));  // @278_60f340
  FL[3] = edx;  // @279_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @280_60f340
  eax = (edx & 0xff);  // @281_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @282_60f340
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @283_60f340
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @284_60f340
  eax = (eax >> (u32)(31));  // @285_60f340
  FL[3] = eax;  // @286_60f340
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @287_60f340
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @288_60f340
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @289_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @290_60f340
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @291_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @292_60f340
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @293_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @294_60f340
  eax = (u32)ext_633910(U2F(X0[0]));  // @295_60f340
  ecx = edx = 0;  // @296_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 164) + 0), 4); v; });  // @297_60f340
  X0[1] = 0;  // @298_60f340
  X0[2] = 0;  // @299_60f340
  X0[3] = 0;  // @300_60f340
  esi = eax;  // @301_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @302_60f340
  esi = (esi << (u32)(8));  // @303_60f340
  FL[3] = esi;  // @304_60f340
  eax = (u32)ext_633910(U2F(X0[0]));  // @305_60f340
  ecx = edx = 0;  // @306_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 168) + 0), 4); v; });  // @307_60f340
  X0[1] = 0;  // @308_60f340
  X0[2] = 0;  // @309_60f340
  X0[3] = 0;  // @310_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @311_60f340
  ecx = (eax & 0xff);  // @312_60f340
  esi = (esi | ecx);  // @313_60f340
  FL[3] = esi;  // @314_60f340
  esi = (esi << (u32)(8));  // @315_60f340
  FL[3] = esi;  // @316_60f340
  eax = (u32)ext_633910(U2F(X0[0]));  // @317_60f340
  ecx = edx = 0;  // @318_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 172) + 0), 4); v; });  // @319_60f340
  X0[1] = 0;  // @320_60f340
  X0[2] = 0;  // @321_60f340
  X0[3] = 0;  // @322_60f340
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; })));  // @323_60f340
  eax = (eax & 0xff);  // @324_60f340
  esi = (esi | eax);  // @325_60f340
  FL[3] = esi;  // @326_60f340
  esi = (esi << (u32)(8));  // @327_60f340
  FL[3] = esi;  // @328_60f340
  eax = (u32)ext_633910(U2F(X0[0]));  // @329_60f340
  ecx = edx = 0;  // @330_60f340
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @331_60f340
  X5[1] = 0;  // @332_60f340
  X5[2] = 0;  // @333_60f340
  X5[3] = 0;  // @334_60f340
  ecx = (u32)(EBP - 12);  // @335_60f340
  eax = (eax & 0xff);  // @336_60f340
  esi = (esi | eax);  // @337_60f340
  FL[3] = esi;  // @338_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @339_60f340
  PV[13] = (u32)(ecx);  // @340_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2471) + 0), 4); v; });  // @341_60f340
  X0[1] = 0;  // @342_60f340
  X0[2] = 0;  // @343_60f340
  X0[3] = 0;  // @344_60f340
  ecx = (u32)(EBP - 156);  // @345_60f340
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2479) + 0), 4); v; });  // @346_60f340
  X4[1] = 0;  // @347_60f340
  X4[2] = 0;  // @348_60f340
  X4[3] = 0;  // @349_60f340
  X3[0] = X0[0];  // @350_60f340
  X3[1] = X0[1];  // @351_60f340
  X3[2] = X0[2];  // @352_60f340
  X3[3] = X0[3];  // @353_60f340
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2483) + 0), 4); v; });  // @354_60f340
  X1[1] = 0;  // @355_60f340
  X1[2] = 0;  // @356_60f340
  X1[3] = 0;  // @357_60f340
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @358_60f340
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; })));  // @359_60f340
  PV[14] = (u32)(ecx);  // @360_60f340
  X4[0] = F2U(U2F(X4[0]) + U2F(X0[0]));  // @361_60f340
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2475) + 0), 4); v; });  // @362_60f340
  X0[1] = 0;  // @363_60f340
  X0[2] = 0;  // @364_60f340
  X0[3] = 0;  // @365_60f340
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @366_60f340
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @367_60f340
  X2[0] = X0[0];  // @368_60f340
  X2[1] = X0[1];  // @369_60f340
  X2[2] = X0[2];  // @370_60f340
  X2[3] = X0[3];  // @371_60f340
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @372_60f340
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @373_60f340
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @374_60f340
  X3[0] = F2U(U2F(X3[0]) - U2F(X5[0]));  // @375_60f340
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @376_60f340
  X4[0] = F2U(U2F(X4[0]) + U2F(X4[0]));  // @377_60f340
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @378_60f340
  X1[0] = F2U(U2F(X1[0]) + U2F(X1[0]));  // @379_60f340
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @380_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @381_60f340
  ecx = esi;  // @382_60f340
  X2[0] = F2U(U2F(X2[0]) - U2F(X5[0]));  // @383_60f340
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @384_60f340
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X3[0], 4);  // @385_60f340
  X4[0] = F2U(U2F(X4[0]) - U2F(X5[0]));  // @386_60f340
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @387_60f340
  X1[0] = F2U(U2F(X1[0]) - U2F(X5[0]));  // @388_60f340
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X3[0], 4);  // @389_60f340
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @390_60f340
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X2[0], 4);  // @391_60f340
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X2[0], 4);  // @392_60f340
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X4[0], 4);  // @393_60f340
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X1[0], 4);  // @394_60f340
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X1[0], 4);  // @395_60f340
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X4[0], 4);  // @396_60f340
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(0), PV[14], (u32)(4), PV[13], (u32)(4));  // @397_60f340
  ecx = edx = 0;  // @398_60f340
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @399_60f340
  ecx = esi;  // @400_60f340
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @401_60f340
  ecx = edx = 0;  // @402_60f340
  L60f8c6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @404_60f340
  ecx = esi;  // @405_60f340
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 80)))(ecx);  // @406_60f340
  ecx = edx = 0;  // @407_60f340
  L60f8cd:;
  ext_633654(G(u32, 0x6f5630));  // @409_60f340
  return eax;  // @410_60f340
}
PCREG(60f340, lifted_60f340);

