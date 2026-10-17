// batch242021.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_460aa0_thiscall3(u32, u32, u32) __asm__("ext_460aa0");
extern "C" u32 THISCALL ext_4b2470_thiscall2(u32, u32) __asm__("ext_4b2470");
extern "C" u32 THISCALL ext_4b3270_thiscall1(u32) __asm__("ext_4b3270");
extern "C" u32 THISCALL ext_4b4040_thiscall3(u32, u32, u32) __asm__("ext_4b4040");
extern "C" u32 THISCALL ext_4b5620_thiscall2(u32, u32) __asm__("ext_4b5620");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c5df0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4c5df0
  esi = ecx;  // @1_4c5df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4c5df0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @3_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4c5df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @5_4c5df0
  ecx = edx = 0;  // @6_4c5df0
  ecx = eax;  // @7_4c5df0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @8_4c5df0
  FL[2] = (ecx & ecx);  // @9_4c5df0
  if (FL[2] != 0) goto L4c5e35;  // @10_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_4c5df0
  ecx = esi;  // @12_4c5df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @13_4c5df0
  ecx = edx = 0;  // @14_4c5df0
  ext_633654(G(u32, 0x6f5630));  // @15_4c5df0
  return eax;  // @16_4c5df0
  L4c5e35:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 80) + 0), 4); v; });  // @18_4c5df0
  X0[1] = 0;  // @19_4c5df0
  X0[2] = 0;  // @20_4c5df0
  X0[3] = 0;  // @21_4c5df0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; });  // @22_4c5df0
  X2[1] = 0;  // @23_4c5df0
  X2[2] = 0;  // @24_4c5df0
  X2[3] = 0;  // @25_4c5df0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @26_4c5df0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4c5df0
  ebx = (u32)(esi + 76);  // @28_4c5df0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @29_4c5df0
  edi = (edi + (u32)(64));  // @30_4c5df0
  FL[3] = edi;  // @31_4c5df0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_4c5df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @33_4c5df0
  eax = edx;  // @34_4c5df0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @35_4c5df0
  FL[3] = eax;  // @36_4c5df0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @37_4c5df0
  if ((s32)FL[0] < (s32)FL[1]) goto L4c5f53;  // @38_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 98), sizeof v); (u32)v; });  // @39_4c5df0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 53), &v, sizeof v); }  // @40_4c5df0
  eax = (eax - (u32)(0));  // @41_4c5df0
  FL[3] = eax;  // @42_4c5df0
  if (FL[3] == 0) goto L4c6019;  // @43_4c5df0
  eax = (eax - (u32)(1));  // @44_4c5df0
  FL[3] = eax;  // @45_4c5df0
  if (FL[3] == 0) goto L4c5f64;  // @46_4c5df0
  eax = (eax - (u32)(1));  // @47_4c5df0
  FL[3] = eax;  // @48_4c5df0
  if (FL[3] != 0) goto L4c5eee;  // @49_4c5df0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @50_4c5df0
  X0[1] = 0;  // @51_4c5df0
  X0[2] = 0;  // @52_4c5df0
  X0[3] = 0;  // @53_4c5df0
  ecx = (u32)(1024);  // @54_4c5df0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 72) + 0), 4); v; })));  // @55_4c5df0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }));  // @56_4c5df0
  FL[3] = edx;  // @57_4c5df0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @58_4c5df0
  FL[3] = edx;  // @59_4c5df0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @60_4c5df0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @61_4c5df0
  X0[0] = 0;  // @62_4c5df0
  X0[1] = 0;  // @63_4c5df0
  X0[2] = 0;  // @64_4c5df0
  X0[3] = 0;  // @65_4c5df0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @66_4c5df0
  eax = ((eax >> 10) | (edx << 22));  // @67_4c5df0
  FL[3] = eax;  // @68_4c5df0
  ecx = (ecx - eax);  // @69_4c5df0
  FL[3] = ecx;  // @70_4c5df0
  edx = (u32)((s32)edx >> (u32)(10));  // @71_4c5df0
  FL[3] = edx;  // @72_4c5df0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @73_4c5df0
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @74_4c5df0
  X1[0] = F2U((float)(s32)X1[0]);  // @75_4c5df0
  X1[1] = F2U((float)(s32)X1[1]);  // @76_4c5df0
  X1[2] = F2U((float)(s32)X1[2]);  // @77_4c5df0
  X1[3] = F2U((float)(s32)X1[3]);  // @78_4c5df0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @79_4c5df0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X1[0], 4);  // @80_4c5df0
  if (FL[0] != FL[1]) goto L4c6059;  // @81_4c5df0
  L4c5ed3:;
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c5ef8;  // @83_4c5df0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @84_4c5df0
  if (FL[0] == FL[1]) goto L4c6093;  // @85_4c5df0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @86_4c5df0
  ecx = edi;  // @87_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_4c5df0
  goto L4c608b;  // @89_4c5df0
  L4c5eee:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @91_4c5df0
  X0[1] = 0;  // @92_4c5df0
  X0[2] = 0;  // @93_4c5df0
  X0[3] = 0;  // @94_4c5df0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @95_4c5df0
  L4c5ef8:;
  ecx = (u32)(EBP - 52);  // @97_4c5df0
  eax = ext_4de7a0_thiscall1(ecx);  // @98_4c5df0
    // @99_4c5df0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @100_4c5df0
  eax = (u32)(EBP - 16);  // @101_4c5df0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @102_4c5df0
  X0[1] = 0;  // @103_4c5df0
  X0[2] = 0;  // @104_4c5df0
  X0[3] = 0;  // @105_4c5df0
  PV[1] = (u32)(ecx);  // @106_4c5df0
  PV[2] = X0[0];  // @107_4c5df0
  PV[3] = (u32)(eax);  // @108_4c5df0
  ecx = (u32)(edi + 28);  // @109_4c5df0
  eax = ext_460aa0_thiscall3(ecx, PV[3], PV[2]);  // @110_4c5df0
  ecx = edx = 0;  // @111_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @112_4c5df0
  ecx = (u32)(EBP - 16);  // @113_4c5df0
  PV[4] = (u32)(ecx);  // @114_4c5df0
  ecx = edi;  // @115_4c5df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[4]);  // @116_4c5df0
  ecx = edx = 0;  // @117_4c5df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @118_4c5df0
  edx = (u32)(EBP - 16);  // @119_4c5df0
  PV[5] = (u32)(edx);  // @120_4c5df0
  edx = (u32)(EBP - 52);  // @121_4c5df0
  PV[6] = (u32)(edx);  // @122_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_4c5df0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[6], PV[5]);  // @124_4c5df0
  ecx = edx = 0;  // @125_4c5df0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 53), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @126_4c5df0
  if (FL[0] == FL[1]) goto L4c5f53;  // @127_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 90), sizeof v); (u32)v; });  // @128_4c5df0
  FL[0] = eax; FL[1] = (u32)(1);  // @129_4c5df0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4c5f53;  // @130_4c5df0
  eax = (eax - 1);  // @131_4c5df0
  FL[3] = eax;  // @132_4c5df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @133_4c5df0
  FL[0] = eax; FL[1] = (u32)(1);  // @134_4c5df0
  if (FL[0] != FL[1]) goto L4c5f53;  // @135_4c5df0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 102), &v, sizeof v); }  // @136_4c5df0
  L4c5f53:;
  ext_633654(G(u32, 0x6f5630));  // @138_4c5df0
  return eax;  // @139_4c5df0
  L4c5f64:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @141_4c5df0
  X0[1] = 0;  // @142_4c5df0
  X0[2] = 0;  // @143_4c5df0
  X0[3] = 0;  // @144_4c5df0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 72) + 0), 4); v; })));  // @145_4c5df0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }));  // @146_4c5df0
  FL[3] = edx;  // @147_4c5df0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @148_4c5df0
  FL[3] = edx;  // @149_4c5df0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @150_4c5df0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @151_4c5df0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @152_4c5df0
  eax = ((eax >> 10) | (edx << 22));  // @153_4c5df0
  FL[3] = eax;  // @154_4c5df0
  edx = (u32)((s32)edx >> (u32)(10));  // @155_4c5df0
  FL[3] = edx;  // @156_4c5df0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 103), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @157_4c5df0
  if (FL[0] != FL[1]) goto L4c5fc9;  // @158_4c5df0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @159_4c5df0
  X0[0] = F2U((float)(s32)X0[0]);  // @160_4c5df0
  X0[1] = F2U((float)(s32)X0[1]);  // @161_4c5df0
  X0[2] = F2U((float)(s32)X0[2]);  // @162_4c5df0
  X0[3] = F2U((float)(s32)X0[3]);  // @163_4c5df0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @164_4c5df0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @165_4c5df0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))))) goto L4c5ef8;  // @166_4c5df0
  FL[0] = ebx; FL[1] = edi;  // @167_4c5df0
  if (FL[0] == FL[1]) goto L4c5fb6;  // @168_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @169_4c5df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @170_4c5df0
  L4c5fb6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @172_4c5df0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 103), &v, sizeof v); }  // @173_4c5df0
  goto L4c5ef8;  // @174_4c5df0
  L4c5fc9:;
  ecx = (u32)(1024);  // @176_4c5df0
  X0[0] = 0;  // @177_4c5df0
  X0[1] = 0;  // @178_4c5df0
  X0[2] = 0;  // @179_4c5df0
  X0[3] = 0;  // @180_4c5df0
  ecx = (ecx - eax);  // @181_4c5df0
  FL[3] = ecx;  // @182_4c5df0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @183_4c5df0
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @184_4c5df0
  X1[0] = F2U((float)(s32)X1[0]);  // @185_4c5df0
  X1[1] = F2U((float)(s32)X1[1]);  // @186_4c5df0
  X1[2] = F2U((float)(s32)X1[2]);  // @187_4c5df0
  X1[3] = F2U((float)(s32)X1[3]);  // @188_4c5df0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @189_4c5df0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X1[0], 4);  // @190_4c5df0
  if (FL[0] == FL[1]) goto L4c5ed3;  // @191_4c5df0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c5ef8;  // @192_4c5df0
  FL[0] = ebx; FL[1] = edi;  // @193_4c5df0
  if (FL[0] == FL[1]) goto L4c6002;  // @194_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @195_4c5df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @196_4c5df0
  L4c6002:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 103), &v, sizeof v); }  // @198_4c5df0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @199_4c5df0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 53), &v, sizeof v); }  // @200_4c5df0
  goto L4c5ef8;  // @201_4c5df0
  L4c6019:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @203_4c5df0
  X1[1] = 0;  // @204_4c5df0
  X1[2] = 0;  // @205_4c5df0
  X1[3] = 0;  // @206_4c5df0
  X0[0] = X1[0];  // @207_4c5df0
  X0[1] = X1[1];  // @208_4c5df0
  X0[2] = X1[2];  // @209_4c5df0
  X0[3] = X1[3];  // @210_4c5df0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }));  // @211_4c5df0
  FL[3] = edx;  // @212_4c5df0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 72) + 0), 4); v; })));  // @213_4c5df0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @214_4c5df0
  FL[3] = edx;  // @215_4c5df0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @216_4c5df0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @217_4c5df0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @218_4c5df0
  eax = ((eax >> 10) | (edx << 22));  // @219_4c5df0
  FL[3] = eax;  // @220_4c5df0
  edx = (u32)((s32)edx >> (u32)(10));  // @221_4c5df0
  FL[3] = edx;  // @222_4c5df0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @223_4c5df0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @224_4c5df0
  X0[0] = F2U((float)(s32)X0[0]);  // @225_4c5df0
  X0[1] = F2U((float)(s32)X0[1]);  // @226_4c5df0
  X0[2] = F2U((float)(s32)X0[2]);  // @227_4c5df0
  X0[3] = F2U((float)(s32)X0[3]);  // @228_4c5df0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @229_4c5df0
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @230_4c5df0
  if (FL[0] == FL[1]) goto L4c607a;  // @231_4c5df0
  L4c6059:;
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c5ef8;  // @233_4c5df0
  FL[0] = ebx; FL[1] = edi;  // @234_4c5df0
  if (FL[0] == FL[1]) goto L4c606a;  // @235_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @236_4c5df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @237_4c5df0
  L4c606a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @239_4c5df0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 53), &v, sizeof v); }  // @240_4c5df0
  goto L4c5ef8;  // @241_4c5df0
  L4c607a:;
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c5ef8;  // @243_4c5df0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @244_4c5df0
  if (FL[0] == FL[1]) goto L4c6093;  // @245_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_4c5df0
  L4c608b:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @248_4c5df0
  ecx = edx = 0;  // @249_4c5df0
  L4c6093:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @251_4c5df0
  if (FL[0] == FL[1]) goto L4c60aa;  // @252_4c5df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @253_4c5df0
  FL[2] = (ecx & ecx);  // @254_4c5df0
  if (FL[2] == 0) goto L4c60aa;  // @255_4c5df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @256_4c5df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @257_4c5df0
  ecx = edx = 0;  // @258_4c5df0
  L4c60aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @260_4c5df0
  ecx = esi;  // @261_4c5df0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @262_4c5df0
  ecx = edx = 0;  // @263_4c5df0
  ext_633654(G(u32, 0x6f5630));  // @264_4c5df0
  return eax;  // @265_4c5df0
}
PCREG(4c5df0, lifted_4c5df0);

extern "C" u32 THISCALL lifted_4b4200(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 232), sizeof v); (u32)v; });  // @3_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(73));  // @4_4b4200
  ecx = edx = 0;  // @5_4b4200
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_4b4200
  if (FL[2] == 0) goto L4b4244;  // @7_4b4200
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_4b4200
  if (FL[0] != FL[1]) goto L4b4244;  // @9_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @10_4b4200
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; });  // @11_4b4200
  PV[0] = (u32)(eax);  // @12_4b4200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4b4200
  PV[1] = (u32)(ecx);  // @14_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[1], PV[0], (u32)(0));  // @15_4b4200
  ecx = edx = 0;  // @16_4b4200
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @17_4b4200
  goto L4b427d;  // @18_4b4200
  L4b4244:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 232), sizeof v); (u32)v; });  // @22_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(85));  // @23_4b4200
  ecx = edx = 0;  // @24_4b4200
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @25_4b4200
  if (FL[2] == 0) goto L4b427d;  // @26_4b4200
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_4b4200
  if (FL[0] != FL[1]) goto L4b428a;  // @28_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @29_4b4200
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 78), sizeof v); (u32)v; });  // @30_4b4200
  PV[2] = (u32)(eax);  // @31_4b4200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4b4200
  PV[3] = (u32)(ecx);  // @33_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[3], PV[2], (u32)(0));  // @34_4b4200
  ecx = edx = 0;  // @35_4b4200
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @36_4b4200
  L4b427d:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @38_4b4200
  if (FL[0] == FL[1]) goto L4b46af;  // @39_4b4200
  L4b428a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_4b4200
  edi = 0;  // @42_4b4200
  FL[3] = edi;  // @43_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @44_4b4200
  eax = (u32)(25600);  // @45_4b4200
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 218), sizeof v); (u32)v; }));  // @46_4b4200
  FL[3] = ecx;  // @47_4b4200
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @48_4b4200
  eax = ((eax >> 10) | (edx << 22));  // @49_4b4200
  FL[3] = eax;  // @50_4b4200
  edx = (u32)((s32)edx >> (u32)(10));  // @51_4b4200
  FL[3] = edx;  // @52_4b4200
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @53_4b4200
  X0[0] = F2U((float)(s32)X0[0]);  // @54_4b4200
  X0[1] = F2U((float)(s32)X0[1]);  // @55_4b4200
  X0[2] = F2U((float)(s32)X0[2]);  // @56_4b4200
  X0[3] = F2U((float)(s32)X0[3]);  // @57_4b4200
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @58_4b4200
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @59_4b4200
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; }); FL[1] = edi;  // @60_4b4200
  if ((s32)FL[0] <= (s32)FL[1]) goto L4b432b;  // @61_4b4200
  L4b42c6:;
  PV[4] = (u32)(edi);  // @63_4b4200
  ecx = ebx;  // @64_4b4200
  eax = ext_4b5620_thiscall2(ecx, PV[4]);  // @65_4b4200
  ecx = edx = 0;  // @66_4b4200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @67_4b4200
  FL[2] = (eax & eax);  // @68_4b4200
  if (FL[2] == 0) goto L4b4322;  // @69_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @70_4b4200
  edx = (u32)(EBP - 8);  // @71_4b4200
  PV[5] = (u32)(edx);  // @72_4b4200
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @73_4b4200
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @74_4b4200
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_4b4200
  PV[6] = (u32)(edx);  // @76_4b4200
  PV[7] = (u32)(eax);  // @77_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[7], PV[6], PV[5]);  // @78_4b4200
  ecx = edx = 0;  // @79_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @80_4b4200
  FL[2] = (ecx & ecx);  // @81_4b4200
  if (FL[2] == 0) goto L4b4322;  // @82_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @83_4b4200
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @84_4b4200
  if (FL[0] != FL[1]) goto L4b4322;  // @85_4b4200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @86_4b4200
  X0[1] = 0;  // @87_4b4200
  X0[2] = 0;  // @88_4b4200
  X0[3] = 0;  // @89_4b4200
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; }))))))) goto L4b4322;  // @90_4b4200
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @91_4b4200
  ecx = ebx;  // @92_4b4200
  eax = ext_4b2470_thiscall2(ecx, PV[8]);  // @93_4b4200
  ecx = edx = 0;  // @94_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @95_4b4200
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + eax), &v, sizeof v); }  // @96_4b4200
  L4b4322:;
  edi = (edi + 1);  // @98_4b4200
  FL[3] = edi;  // @99_4b4200
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; });  // @100_4b4200
  if ((s32)FL[0] < (s32)FL[1]) goto L4b42c6;  // @101_4b4200
  L4b432b:;
  edi = 0;  // @103_4b4200
  FL[3] = edi;  // @104_4b4200
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; }); FL[1] = edi;  // @105_4b4200
  if ((s32)FL[0] <= (s32)FL[1]) goto L4b43a0;  // @106_4b4200
  L4b4335:;
  PV[9] = (u32)(edi);  // @108_4b4200
  ecx = ebx;  // @109_4b4200
  eax = ext_4b5620_thiscall2(ecx, PV[9]);  // @110_4b4200
  ecx = edx = 0;  // @111_4b4200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @112_4b4200
  FL[2] = (eax & eax);  // @113_4b4200
  if (FL[2] == 0) goto L4b4397;  // @114_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @115_4b4200
  edx = (u32)(EBP - 8);  // @116_4b4200
  PV[10] = (u32)(edx);  // @117_4b4200
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @118_4b4200
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @119_4b4200
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_4b4200
  PV[11] = (u32)(edx);  // @121_4b4200
  PV[12] = (u32)(eax);  // @122_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[12], PV[11], PV[10]);  // @123_4b4200
  ecx = edx = 0;  // @124_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @125_4b4200
  FL[2] = (ecx & ecx);  // @126_4b4200
  if (FL[2] == 0) goto L4b4397;  // @127_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @128_4b4200
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @129_4b4200
  if (FL[0] != FL[1]) goto L4b4397;  // @130_4b4200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @131_4b4200
  X0[1] = 0;  // @132_4b4200
  X0[2] = 0;  // @133_4b4200
  X0[3] = 0;  // @134_4b4200
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; }))))))) goto L4b4397;  // @135_4b4200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @136_4b4200
  ecx = ebx;  // @137_4b4200
  PV[13] = (u32)(eax);  // @138_4b4200
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @139_4b4200
  eax = ext_4b4040_thiscall3(ecx, PV[14], PV[13]);  // @140_4b4200
  ecx = edx = 0;  // @141_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @142_4b4200
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + eax), &v, sizeof v); }  // @143_4b4200
  L4b4397:;
  edi = (edi + 1);  // @145_4b4200
  FL[3] = edi;  // @146_4b4200
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 238), sizeof v); (u32)v; });  // @147_4b4200
  if ((s32)FL[0] < (s32)FL[1]) goto L4b4335;  // @148_4b4200
  L4b43a0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 230), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @150_4b4200
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @151_4b4200
  X1[1] = 0;  // @152_4b4200
  X1[2] = 0;  // @153_4b4200
  X1[3] = 0;  // @154_4b4200
  X0[0] = F2U((float)(s32)X0[0]);  // @155_4b4200
  X0[1] = F2U((float)(s32)X0[1]);  // @156_4b4200
  X0[2] = F2U((float)(s32)X0[2]);  // @157_4b4200
  X0[3] = F2U((float)(s32)X0[3]);  // @158_4b4200
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4b449e;  // @159_4b4200
  esi = (u32)(ebx + 170);  // @160_4b4200
  L4b43c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 214), sizeof v); (u32)v; });  // @162_4b4200
  FL[2] = (ecx & ecx);  // @163_4b4200
  if (FL[2] == 0) goto L4b4426;  // @164_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_4b4200
  eax = (u32)(ebx + 270);  // @166_4b4200
  PV[15] = (u32)(eax);  // @167_4b4200
  eax = (u32)(ebx + 242);  // @168_4b4200
  PV[16] = (u32)(eax);  // @169_4b4200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[16], PV[15]);  // @171_4b4200
  ecx = edx = 0;  // @172_4b4200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 222) + 0), 4); v; });  // @173_4b4200
  X0[1] = 0;  // @174_4b4200
  X0[2] = 0;  // @175_4b4200
  X0[3] = 0;  // @176_4b4200
  ecx = esi;  // @177_4b4200
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891416) + 0), 4); v; })));  // @178_4b4200
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 214), sizeof v); (u32)v; });  // @179_4b4200
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @180_4b4200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 230), &v, sizeof v); }  // @181_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @182_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[17]);  // @183_4b4200
  ecx = edx = 0;  // @184_4b4200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 214), &v, sizeof v); }  // @185_4b4200
  FL[2] = (eax & eax);  // @186_4b4200
  if (FL[2] == 0) goto L4b4485;  // @187_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @188_4b4200
  FL[2] = (ecx & ecx);  // @189_4b4200
  if (FL[2] == 0) goto L4b4485;  // @190_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_4b4200
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @192_4b4200
  ecx = edx = 0;  // @193_4b4200
  goto L4b447f;  // @194_4b4200
  L4b4426:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @196_4b4200
  ecx = (u32)(EBP - 24);  // @197_4b4200
  PV[18] = (u32)(ecx);  // @198_4b4200
  ecx = esi;  // @199_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[18]);  // @200_4b4200
  ecx = edx = 0;  // @201_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_4b4200
  ecx = (u32)(EBP - 24);  // @203_4b4200
  PV[19] = (u32)(ecx);  // @204_4b4200
  ecx = esi;  // @205_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[19]);  // @206_4b4200
  ecx = edx = 0;  // @207_4b4200
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 222) + 0), 4); v; });  // @208_4b4200
  X1[1] = 0;  // @209_4b4200
  X1[2] = 0;  // @210_4b4200
  X1[3] = 0;  // @211_4b4200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 214), &v, sizeof v); }  // @212_4b4200
  X0[0] = X1[0];  // @213_4b4200
  X0[1] = X1[1];  // @214_4b4200
  X0[2] = X1[2];  // @215_4b4200
  X0[3] = X1[3];  // @216_4b4200
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860588) + 0), 4); v; })));  // @217_4b4200
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @218_4b4200
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 230), &v, sizeof v); }  // @219_4b4200
  FL[2] = (eax & eax);  // @220_4b4200
  if (FL[2] == 0) goto L4b4485;  // @221_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @222_4b4200
  FL[2] = (ecx & ecx);  // @223_4b4200
  if (FL[2] == 0) goto L4b4473;  // @224_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @225_4b4200
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @226_4b4200
  ecx = edx = 0;  // @227_4b4200
  goto L4b447f;  // @228_4b4200
  L4b4473:;
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; })));  // @230_4b4200
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @231_4b4200
  L4b447f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 230), &v, sizeof v); }  // @233_4b4200
  L4b4485:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 230), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @235_4b4200
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @236_4b4200
  X1[1] = 0;  // @237_4b4200
  X1[2] = 0;  // @238_4b4200
  X1[3] = 0;  // @239_4b4200
  X0[0] = F2U((float)(s32)X0[0]);  // @240_4b4200
  X0[1] = F2U((float)(s32)X0[1]);  // @241_4b4200
  X0[2] = F2U((float)(s32)X0[2]);  // @242_4b4200
  X0[3] = F2U((float)(s32)X0[3]);  // @243_4b4200
  if ((!(!(U2F(X1[0]) >= U2F(X0[0]))) && !(!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4b43c0;  // @244_4b4200
  L4b449e:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 159), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @246_4b4200
  if (FL[0] == FL[1]) goto L4b44ae;  // @247_4b4200
  ecx = ebx;  // @248_4b4200
  eax = ext_4b3270_thiscall1(ecx);  // @249_4b4200
  ecx = edx = 0;  // @250_4b4200
  L4b44ae:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @252_4b4200
  X0[1] = 0;  // @253_4b4200
  X0[2] = 0;  // @254_4b4200
  X0[3] = 0;  // @255_4b4200
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @256_4b4200
  FL[3] = (eax & 0xff);  // @257_4b4200
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @258_4b4200
  eax = (eax & 0xff);  // @259_4b4200
  ecx = (u32)(1);  // @260_4b4200
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 222) + 0), 4); v; })))))) eax = ecx;  // @261_4b4200
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 153), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @262_4b4200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @263_4b4200
  if (FL[0] != FL[1]) goto L4b45e4;  // @264_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @265_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @266_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @267_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @268_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6886624), (u32)(0));  // @269_4b4200
  ecx = edx = 0;  // @270_4b4200
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @271_4b4200
  if (FL[2] != 0) goto L4b4557;  // @272_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @273_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @274_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @275_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @276_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6886640), (u32)(0));  // @277_4b4200
  ecx = edx = 0;  // @278_4b4200
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @279_4b4200
  if (FL[2] != 0) goto L4b4557;  // @280_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @282_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @283_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @284_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6886660), (u32)(0));  // @285_4b4200
  ecx = edx = 0;  // @286_4b4200
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @287_4b4200
  if (FL[2] != 0) goto L4b4557;  // @288_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @289_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @290_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @291_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @292_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6886680), (u32)(0));  // @293_4b4200
  ecx = edx = 0;  // @294_4b4200
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @295_4b4200
  if (FL[2] != 0) goto L4b4557;  // @296_4b4200
  ecx = (ecx & 0xffffff00u) | ((0) & 0xff);  // @297_4b4200
  FL[3] = (ecx & 0xff);  // @298_4b4200
  goto L4b4559;  // @299_4b4200
  L4b4557:;
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @301_4b4200
  L4b4559:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 166), sizeof v); (u32)v; });  // @303_4b4200
  eax = (eax - (u32)(0));  // @304_4b4200
  FL[3] = eax;  // @305_4b4200
  if (FL[3] == 0) goto L4b45ce;  // @306_4b4200
  eax = (eax - (u32)(1));  // @307_4b4200
  FL[3] = eax;  // @308_4b4200
  if (FL[3] == 0) goto L4b45bb;  // @309_4b4200
  eax = (eax - (u32)(1));  // @310_4b4200
  FL[3] = eax;  // @311_4b4200
  if (FL[3] != 0) goto L4b45e1;  // @312_4b4200
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @313_4b4200
  if (FL[2] != 0) goto L4b45e1;  // @314_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @315_4b4200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @316_4b4200
  PV[20] = (u32)(edx);  // @317_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @318_4b4200
  esi = ecx;  // @319_4b4200
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @320_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @321_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @322_4b4200
  ecx = edx = 0;  // @323_4b4200
  PV[21] = (u32)(eax);  // @324_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @325_4b4200
  ecx = esi;  // @326_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6890512), (u32)(0), (u32)(6889180), (u32)(1963));  // @327_4b4200
  ecx = edx = 0;  // @328_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @329_4b4200
  eax = (eax & 0xffff);  // @330_4b4200
  PV[22] = (u32)(eax);  // @331_4b4200
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 136), sizeof v); (u32)v; });  // @332_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, PV[23], PV[22], PV[21]);  // @333_4b4200
  ecx = edx = 0;  // @334_4b4200
  goto L4b45ec;  // @335_4b4200
  L4b45bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @337_4b4200
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @338_4b4200
  if (FL[2] == 0) goto L4b45e4;  // @339_4b4200
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 166), &v, sizeof v); }  // @340_4b4200
  goto L4b45e4;  // @341_4b4200
  L4b45ce:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @343_4b4200
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @344_4b4200
  if (FL[2] != 0) goto L4b45e4;  // @345_4b4200
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 166), &v, sizeof v); }  // @346_4b4200
  goto L4b45e4;  // @347_4b4200
  L4b45e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @349_4b4200
  L4b45e4:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @351_4b4200
  if (FL[2] == 0) goto L4b46ad;  // @352_4b4200
  L4b45ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @354_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @355_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @356_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886624), (u32)(0));  // @357_4b4200
  ecx = edx = 0;  // @358_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @359_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @360_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @361_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886640), (u32)(0));  // @362_4b4200
  ecx = edx = 0;  // @363_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @364_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @365_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @366_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886660), (u32)(0));  // @367_4b4200
  ecx = edx = 0;  // @368_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @369_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @370_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @371_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(6886700), (u32)(0));  // @372_4b4200
  ecx = edx = 0;  // @373_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @374_4b4200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @375_4b4200
  PV[24] = (u32)(edx);  // @376_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @377_4b4200
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @378_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @379_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[24]);  // @380_4b4200
  ecx = edx = 0;  // @381_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @382_4b4200
  PV[25] = (u32)(eax);  // @383_4b4200
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @384_4b4200
  PV[26] = (u32)(eax);  // @385_4b4200
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 136), sizeof v); (u32)v; });  // @386_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, PV[27], PV[26], PV[25]);  // @387_4b4200
  ecx = edx = 0;  // @388_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @389_4b4200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @390_4b4200
  PV[28] = (u32)(edx);  // @391_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @392_4b4200
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @393_4b4200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @394_4b4200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[28]);  // @395_4b4200
  ecx = edx = 0;  // @396_4b4200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @397_4b4200
  PV[29] = (u32)(eax);  // @398_4b4200
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @399_4b4200
  PV[30] = (u32)(eax);  // @400_4b4200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[30], PV[29], (u32)(0));  // @401_4b4200
  ecx = edx = 0;  // @402_4b4200
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 159), &v, sizeof v); }  // @403_4b4200
  L4b46ad:;
  L4b46af:;
  return eax;  // @406_4b4200
}
PCREG(4b4200, lifted_4b4200);

