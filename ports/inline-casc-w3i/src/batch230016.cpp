// batch230016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 STDCALL ext_5d6960_stdcall4(u32, u32, u32, u32) __asm__("ext_5d6960");
extern "C" u32 THISCALL ext_446320_thiscall3(u32, u32, u32) __asm__("ext_446320");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5d6280(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5d6280
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_5d6280
  if (FL[0] == FL[1]) goto L5d67c7;  // @2_5d6280
  esi = (u32)(edi + 94);  // @3_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @5_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 102), &v, sizeof v); }  // @6_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @7_5d6280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 122), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 110), &v, sizeof v); }  // @9_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 114), &v, sizeof v); }  // @10_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 118), &v, sizeof v); }  // @11_5d6280
  if (FL[0] == FL[1]) goto L5d6318;  // @12_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @14_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @15_5d6280
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 180), sizeof v); (u32)v; });  // @18_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(0));  // @19_5d6280
  ecx = edx = 0;  // @20_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_5d6280
  PV[0] = (u32)(eax);  // @22_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @23_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @24_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @25_5d6280
  ecx = edx = 0;  // @26_5d6280
  esi = (u32)(edi + 94);  // @27_5d6280
  goto L5d632d;  // @28_5d6280
  L5d6318:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_5d6280
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @31_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @34_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @35_5d6280
  ecx = edx = 0;  // @36_5d6280
  L5d632d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 12), &v, sizeof v); }  // @38_5d6280
  FL[2] = (eax & eax);  // @39_5d6280
  if (FL[2] != 0) goto L5d636b;  // @40_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @41_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @43_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7035464), (u32)(111));  // @44_5d6280
  ecx = edx = 0;  // @45_5d6280
  PV[2] = (u32)(eax);  // @46_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_5d6280
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(7035540));  // @48_5d6280
  ecx = edx = 0;  // @49_5d6280
  ext_633654(G(u32, 0x6f5630));  // @50_5d6280
  return eax;  // @51_5d6280
  L5d636b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_5d6280
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @54_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @57_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[3]);  // @58_5d6280
  ecx = edx = 0;  // @59_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 20), &v, sizeof v); }  // @60_5d6280
  FL[2] = (eax & eax);  // @61_5d6280
  if (FL[2] == 0) goto L5d67c7;  // @62_5d6280
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 123), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 123), &v, sizeof v); }  // @63_5d6280
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 123), sizeof v); (u32)v; });  // @64_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @65_5d6280
  FL[2] = (ecx & ecx);  // @66_5d6280
  if (FL[2] == 0) goto L5d679c;  // @67_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_5d6280
  edx = (u32)((EBP - 296) + 28);  // @69_5d6280
  PV[4] = (u32)(edx);  // @70_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @71_5d6280
  ecx = edx = 0;  // @72_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 20), sizeof v); (u32)v; });  // @73_5d6280
  edx = (u32)((EBP - 296) + 28);  // @74_5d6280
  PV[5] = (u32)(edx);  // @75_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @76_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @78_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[5]);  // @79_5d6280
  ecx = edx = 0;  // @80_5d6280
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @81_5d6280
  edx = eax;  // @82_5d6280
  if (FL[0] == FL[1]) goto L5d679c;  // @83_5d6280
  L5d63c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_5d6280
  PV[6] = (u32)(edx);  // @86_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @87_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @89_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[6]);  // @90_5d6280
  ecx = edx = 0;  // @91_5d6280
  esi = eax;  // @92_5d6280
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 296) + 64), &v, sizeof v); }  // @93_5d6280
  eax = (u32)((EBP - 296) + 220);  // @94_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 220), &v, sizeof v); }  // @95_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 224), &v, sizeof v); }  // @96_5d6280
  ecx = esi;  // @97_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 228), &v, sizeof v); }  // @98_5d6280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @99_5d6280
  PV[7] = (u32)(eax);  // @100_5d6280
  eax = (u32)((EBP - 300) + 260);  // @101_5d6280
  PV[8] = (u32)(eax);  // @102_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[8], PV[7]);  // @103_5d6280
  ecx = edx = 0;  // @104_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @105_5d6280
  edx = (u32)((EBP - 296) + 92);  // @106_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 220) + 0), 4); v; });  // @107_5d6280
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 220) + 4), 4); v; });  // @108_5d6280
  X0[2] = 0;  // @109_5d6280
  X0[3] = 0;  // @110_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 228), sizeof v); (u32)v; });  // @111_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 92) + 0), &X0[0], 4);  // @112_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 92) + 4), &X0[1], 4);  // @113_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 296) + 100), &v, sizeof v); }  // @114_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_5d6280
  PV[9] = (u32)(edx);  // @116_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[9]);  // @117_5d6280
  ecx = edx = 0;  // @118_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @119_5d6280
  eax = (u32)((EBP - 296) + 92);  // @120_5d6280
  PV[10] = (u32)(eax);  // @121_5d6280
  eax = (u32)((EBP - 300) + 72);  // @122_5d6280
  PV[11] = (u32)(eax);  // @123_5d6280
  eax = ext_446320_thiscall3(ecx, PV[11], PV[10]);  // @124_5d6280
  ecx = edx = 0;  // @125_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @126_5d6280
  edx = (u32)((EBP - 296) + 76);  // @127_5d6280
  PV[12] = (u32)(edx);  // @128_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[12]);  // @130_5d6280
  ecx = edx = 0;  // @131_5d6280
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 84) + 0), 4); v; });  // @132_5d6280
  X5[1] = 0;  // @133_5d6280
  X5[2] = 0;  // @134_5d6280
  X5[3] = 0;  // @135_5d6280
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 72) + 0), 4); v; });  // @136_5d6280
  X4[1] = 0;  // @137_5d6280
  X4[2] = 0;  // @138_5d6280
  X4[3] = 0;  // @139_5d6280
  X0[0] = X5[0];  // @140_5d6280
  X0[1] = X5[1];  // @141_5d6280
  X0[2] = X5[2];  // @142_5d6280
  X0[3] = X5[3];  // @143_5d6280
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 68) + 0), 4); v; })));  // @144_5d6280
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @145_5d6280
  X7[1] = 0;  // @146_5d6280
  X7[2] = 0;  // @147_5d6280
  X7[3] = 0;  // @148_5d6280
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X6[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X6[2] = X6[3] = 0;  // @149_5d6280
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 88) + 0), 4); v; });  // @150_5d6280
  X3[1] = 0;  // @151_5d6280
  X3[2] = 0;  // @152_5d6280
  X3[3] = 0;  // @153_5d6280
  X4[0] = F2U(U2F(X4[0]) * U2F(X5[0]));  // @154_5d6280
  X5[0] = F2U(U2F(X5[0]) * U2F(X7[0]));  // @155_5d6280
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X2[0], a_); SD(&X2[2], b_); }  // @156_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 68) + 0), &X0[0], 4);  // @157_5d6280
  { double a_ = (double)U2F(X5[0]), b_ = (double)U2F(X5[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @158_5d6280
  X2[0] = X2[0] & X6[0];  // @159_5d6280
  X2[1] = X2[1] & X6[1];  // @160_5d6280
  X2[2] = X2[2] & X6[2];  // @161_5d6280
  X2[3] = X2[3] & X6[3];  // @162_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 72) + 0), &X4[0], 4);  // @163_5d6280
  if ((!(!(U2D(X2[0], X2[1]) >= U2D(X0[0], X0[1]))) && !(!((U2D(X2[0], X2[1]) < U2D(X0[0], X0[1])) || (U2D(X2[0], X2[1]) > U2D(X0[0], X0[1])))))) goto L5d64d7;  // @164_5d6280
  X0[0] = X3[0];  // @165_5d6280
  X0[1] = X3[1];  // @166_5d6280
  X0[2] = X3[2];  // @167_5d6280
  X0[3] = X3[3];  // @168_5d6280
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @169_5d6280
  { double a_ = (double)U2F(X4[0]), b_ = (double)U2F(X4[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @170_5d6280
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @171_5d6280
  X1[0] = X1[0] & X6[0];  // @172_5d6280
  X1[1] = X1[1] & X6[1];  // @173_5d6280
  X1[2] = X1[2] & X6[2];  // @174_5d6280
  X1[3] = X1[3] & X6[3];  // @175_5d6280
  if ((!(!(U2D(X1[0], X1[1]) >= U2D(X0[0], X0[1]))) && !(!((U2D(X1[0], X1[1]) < U2D(X0[0], X0[1])) || (U2D(X1[0], X1[1]) > U2D(X0[0], X0[1])))))) goto L5d64d7;  // @176_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 0), 4); v; });  // @177_5d6280
  X0[1] = 0;  // @178_5d6280
  X0[2] = 0;  // @179_5d6280
  X0[3] = 0;  // @180_5d6280
  goto L5d6532;  // @181_5d6280
  L5d64d7:;
  { double a_ = (double)U2F(X5[0]), b_ = (double)U2F(X5[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @183_5d6280
  X3[0] = F2U(U2F(X3[0]) * U2F(X7[0]));  // @184_5d6280
  SD(&X2[0], U2D(X2[0], X2[1]) - U2D(X0[0], X0[1]));  // @185_5d6280
  { double a_ = (double)U2F(X4[0]), b_ = (double)U2F(X4[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @186_5d6280
  { double a_ = (double)U2F(X3[0]), b_ = (double)U2F(X3[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @187_5d6280
  X1[0] = X1[0] & X6[0];  // @188_5d6280
  X1[1] = X1[1] & X6[1];  // @189_5d6280
  X1[2] = X1[2] & X6[2];  // @190_5d6280
  X1[3] = X1[3] & X6[3];  // @191_5d6280
  SD(&X1[0], U2D(X1[0], X1[1]) - U2D(X0[0], X0[1]));  // @192_5d6280
  { float a_ = (float)U2D(X2[0], X2[1]), b_ = (float)U2D(X2[2], X2[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @193_5d6280
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @194_5d6280
  { float a_ = U2F(X2[0]), b_ = U2F(X0[0]); X2[0] = (a_ > b_) ? X2[0] : F2U(b_); }  // @195_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6945228) + 0), 4); v; });  // @196_5d6280
  X0[1] = 0;  // @197_5d6280
  X0[2] = 0;  // @198_5d6280
  X0[3] = 0;  // @199_5d6280
  if ((!(U2F(X2[0]) >= U2F(X0[0])))) goto L5d6516;  // @200_5d6280
  X0[0] = 0;  // @201_5d6280
  X0[1] = 0;  // @202_5d6280
  X0[2] = 0;  // @203_5d6280
  X0[3] = 0;  // @204_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 64) + 0), &X0[0], 4);  // @205_5d6280
  goto L5d667f;  // @206_5d6280
  L5d6516:;
  X2[0] = F2U(U2F(X2[0]) / U2F(X0[0]));  // @208_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @209_5d6280
  X0[1] = 0;  // @210_5d6280
  X0[2] = 0;  // @211_5d6280
  X0[3] = 0;  // @212_5d6280
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @213_5d6280
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 0), 4); v; })));  // @214_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 64) + 0), &X0[0], 4);  // @215_5d6280
  L5d6532:;
  X1[0] = 0;  // @217_5d6280
  X1[1] = 0;  // @218_5d6280
  X1[2] = 0;  // @219_5d6280
  X1[3] = 0;  // @220_5d6280
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @221_5d6280
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @222_5d6280
  if (__builtin_parity(FL[2] & 0xff)) goto L5d6682;  // @223_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @224_5d6280
  ecx = esi;  // @225_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @226_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(8388643));  // @227_5d6280
  ecx = edx = 0;  // @228_5d6280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @229_5d6280
  if (FL[2] == 0) goto L5d6679;  // @230_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @231_5d6280
  edx = (u32)((EBP - 296) + 244);  // @232_5d6280
  PV[13] = (u32)(edx);  // @233_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 248), &v, sizeof v); }  // @234_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 252), &v, sizeof v); }  // @235_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @236_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 256), &v, sizeof v); }  // @237_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[13]);  // @238_5d6280
  ecx = edx = 0;  // @239_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @240_5d6280
  ecx = esi;  // @241_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 576), sizeof v); (u32)v; });  // @242_5d6280
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @243_5d6280
  ecx = edx = 0;  // @244_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 256) + 0), 4); v; });  // @245_5d6280
  X0[1] = 0;  // @246_5d6280
  X0[2] = 0;  // @247_5d6280
  X0[3] = 0;  // @248_5d6280
  eax = (u32)((EBP - 296) + 40);  // @249_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 40) + 0), &X0[0], 4);  // @250_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 260) + 0), 4); v; });  // @251_5d6280
  X0[1] = 0;  // @252_5d6280
  X0[2] = 0;  // @253_5d6280
  X0[3] = 0;  // @254_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 44) + 0), &X0[0], 4);  // @255_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 264) + 0), 4); v; });  // @256_5d6280
  X0[1] = 0;  // @257_5d6280
  X0[2] = 0;  // @258_5d6280
  X0[3] = 0;  // @259_5d6280
  PV[14] = (u32)(ecx);  // @260_5d6280
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 300) + 20)) :: "st");  // @261_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 300) + 52) + 0), &X0[0], 4);  // @262_5d6280
  ecx = edi;  // @263_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 300) + 20) + 0), 4); v; });  // @264_5d6280
  X0[1] = 0;  // @265_5d6280
  X0[2] = 0;  // @266_5d6280
  X0[3] = 0;  // @267_5d6280
  PV[15] = X0[0];  // @268_5d6280
  PV[16] = (u32)(eax);  // @269_5d6280
  eax = (u32)((EBP - 304) + 228);  // @270_5d6280
  PV[17] = (u32)(eax);  // @271_5d6280
  eax = (u32)((EBP - 308) + 256);  // @272_5d6280
  PV[18] = (u32)(eax);  // @273_5d6280
  eax = ext_5d6960_stdcall4(PV[18], PV[17], PV[16], PV[15]);  // @274_5d6280
  ecx = edx = 0;  // @275_5d6280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @276_5d6280
  if (FL[2] != 0) goto L5d6601;  // @277_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 296) + 64), &v, sizeof v); }  // @278_5d6280
  L5d6601:;
  eax = (u32)((EBP - 296) + 220);  // @280_5d6280
  PV[19] = (u32)(eax);  // @281_5d6280
  edx = (u32)((EBP - 300) + 248);  // @282_5d6280
  ecx = (u32)((EBP - 300) + 56);  // @283_5d6280
  eax = ext_43e920_fastcall3(ecx, edx, PV[19]);  // @284_5d6280
  ecx = edx = 0;  // @285_5d6280
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 52) + 0), 4); v; });  // @286_5d6280
  X1[1] = 0;  // @287_5d6280
  X1[2] = 0;  // @288_5d6280
  X1[3] = 0;  // @289_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 56) + 0), 4); v; });  // @290_5d6280
  X0[1] = 0;  // @291_5d6280
  X0[2] = 0;  // @292_5d6280
  X0[3] = 0;  // @293_5d6280
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @294_5d6280
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @295_5d6280
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @296_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 60) + 0), 4); v; });  // @297_5d6280
  X0[1] = 0;  // @298_5d6280
  X0[2] = 0;  // @299_5d6280
  X0[3] = 0;  // @300_5d6280
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @301_5d6280
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @302_5d6280
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @303_5d6280
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @304_5d6280
  ecx = edx = 0;  // @305_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @306_5d6280
  ecx = esi;  // @307_5d6280
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @308_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 584), sizeof v); (u32)v; });  // @309_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 16) + 0), &X0[0], 4);  // @310_5d6280
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @311_5d6280
  ecx = edx = 0;  // @312_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 16) + 0), 4); v; });  // @313_5d6280
  X0[1] = 0;  // @314_5d6280
  X0[2] = 0;  // @315_5d6280
  X0[3] = 0;  // @316_5d6280
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 296) + 24)) :: "st");  // @317_5d6280
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 24) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 24) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 24) + 0), 4); v; }))))))) goto L5d6679;  // @318_5d6280
  X0[0] = 0;  // @319_5d6280
  X0[1] = 0;  // @320_5d6280
  X0[2] = 0;  // @321_5d6280
  X0[3] = 0;  // @322_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 64) + 0), &X0[0], 4);  // @323_5d6280
  goto L5d667f;  // @324_5d6280
  L5d6679:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 0), 4); v; });  // @326_5d6280
  X0[1] = 0;  // @327_5d6280
  X0[2] = 0;  // @328_5d6280
  X0[3] = 0;  // @329_5d6280
  L5d667f:;
  X1[0] = 0;  // @331_5d6280
  X1[1] = 0;  // @332_5d6280
  X1[2] = 0;  // @333_5d6280
  X1[3] = 0;  // @334_5d6280
  L5d6682:;
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @336_5d6280
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @337_5d6280
  if (__builtin_parity(FL[2] & 0xff)) goto L5d6759;  // @338_5d6280
  ecx = (u32)((EBP - 296) + 104);  // @339_5d6280
  eax = ext_4e1b60_thiscall1(ecx);  // @340_5d6280
    // @341_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 12), sizeof v); (u32)v; });  // @342_5d6280
  edx = (u32)((EBP - 296) + 232);  // @343_5d6280
  PV[20] = (u32)(edx);  // @344_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 236), &v, sizeof v); }  // @345_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 240), &v, sizeof v); }  // @346_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @347_5d6280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 244), &v, sizeof v); }  // @348_5d6280
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 300) + 216), &v, sizeof v); }  // @349_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[20]);  // @350_5d6280
  ecx = edx = 0;  // @351_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 232) + 0), 4); v; });  // @352_5d6280
  X0[1] = 0;  // @353_5d6280
  X0[2] = 0;  // @354_5d6280
  X0[3] = 0;  // @355_5d6280
  eax = (u32)((EBP - 296) + 232);  // @356_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 104) + 0), &X0[0], 4);  // @357_5d6280
  edx = (u32)((EBP - 296) + 220);  // @358_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 236) + 0), 4); v; });  // @359_5d6280
  X0[1] = 0;  // @360_5d6280
  X0[2] = 0;  // @361_5d6280
  X0[3] = 0;  // @362_5d6280
  ecx = (u32)((EBP - 296) + 116);  // @363_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 108) + 0), &X0[0], 4);  // @364_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 240) + 0), 4); v; });  // @365_5d6280
  X0[1] = 0;  // @366_5d6280
  X0[2] = 0;  // @367_5d6280
  X0[3] = 0;  // @368_5d6280
  PV[21] = (u32)(eax);  // @369_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 300) + 116) + 0), &X0[0], 4);  // @370_5d6280
  eax = ext_43e920_fastcall3(ecx, edx, PV[21]);  // @371_5d6280
  ecx = edx = 0;  // @372_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @373_5d6280
  edx = (u32)((EBP - 296) + 104);  // @374_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @375_5d6280
  PV[22] = (u32)(edx);  // @376_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @377_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @378_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @379_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[22], (u32)(0), (u32)(2), (u32)(-1), (u32)(1), (u32)(1));  // @380_5d6280
  ecx = edx = 0;  // @381_5d6280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @382_5d6280
  if (FL[2] == 0) goto L5d6753;  // @383_5d6280
  X0[0] = 0;  // @384_5d6280
  X0[1] = 0;  // @385_5d6280
  X0[2] = 0;  // @386_5d6280
  X0[3] = 0;  // @387_5d6280
  __builtin_memcpy((void *)((u32)((EBP - 296) + 64) + 0), &X0[0], 4);  // @388_5d6280
  goto L5d6759;  // @389_5d6280
  L5d6753:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 0), 4); v; });  // @391_5d6280
  X0[1] = 0;  // @392_5d6280
  X0[2] = 0;  // @393_5d6280
  X0[3] = 0;  // @394_5d6280
  L5d6759:;
  esi = (u32)(edi + 94);  // @396_5d6280
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 94) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 94) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 94) + 0), 4); v; }))))))) goto L5d677c;  // @397_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 0), 4); v; });  // @398_5d6280
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 4), 4); v; });  // @399_5d6280
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 8), 4); v; });  // @400_5d6280
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 64) + 12), 4); v; });  // @401_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 88), sizeof v); (u32)v; });  // @402_5d6280
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @403_5d6280
  __builtin_memcpy((void *)((u32)(esi) + 4), &X0[1], 4);  // @404_5d6280
  __builtin_memcpy((void *)((u32)(esi) + 8), &X0[2], 4);  // @405_5d6280
  __builtin_memcpy((void *)((u32)(esi) + 12), &X0[3], 4);  // @406_5d6280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 80) + 0), 4); v; });  // @407_5d6280
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 296) + 80) + 4), 4); v; });  // @408_5d6280
  X0[2] = 0;  // @409_5d6280
  X0[3] = 0;  // @410_5d6280
  __builtin_memcpy((void *)((u32)(esi + 16) + 0), &X0[0], 4);  // @411_5d6280
  __builtin_memcpy((void *)((u32)(esi + 16) + 4), &X0[1], 4);  // @412_5d6280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @413_5d6280
  L5d677c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 20), sizeof v); (u32)v; });  // @415_5d6280
  edx = (u32)((EBP - 296) + 28);  // @416_5d6280
  PV[23] = (u32)(edx);  // @417_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @418_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @419_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @420_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[23]);  // @421_5d6280
  ecx = edx = 0;  // @422_5d6280
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 296) + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @423_5d6280
  edx = eax;  // @424_5d6280
  if (FL[0] != FL[1]) goto L5d63c4;  // @425_5d6280
  L5d679c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @427_5d6280
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @428_5d6280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @429_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @430_5d6280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @431_5d6280
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[24]);  // @432_5d6280
  ecx = edx = 0;  // @433_5d6280
  FL[2] = (eax & eax);  // @434_5d6280
  if (FL[2] == 0) goto L5d67c7;  // @435_5d6280
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @436_5d6280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @437_5d6280
  PV[25] = (u32)(esi);  // @438_5d6280
  PV[26] = (u32)(ecx);  // @439_5d6280
  ecx = eax;  // @440_5d6280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 312)))(ecx, PV[26], PV[25], (u32)(0));  // @441_5d6280
  ecx = edx = 0;  // @442_5d6280
  L5d67c7:;
  ext_633654(G(u32, 0x6f5630));  // @444_5d6280
  return eax;  // @445_5d6280
}
PCREG(5d6280, lifted_5d6280);

