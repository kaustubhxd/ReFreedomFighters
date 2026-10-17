// batch234013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1440_thiscall2(u32, u32) __asm__("ext_4e1440");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_445800(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_445800
  PV[0] = (u32)(esi);  // @1_445800
  edi = ecx;  // @2_445800
  eax = ext_610100_stdcall1(PV[0]);  // @3_445800
    // @4_445800
  ebx = (u32)(edi + 100);  // @5_445800
  ecx = esi;  // @6_445800
  PV[1] = (u32)(ebx);  // @7_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[1], (u32)(1));  // @8_445800
  ecx = edx = 0;  // @9_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @10_445800
  X0[1] = 0;  // @11_445800
  X0[2] = 0;  // @12_445800
  X0[3] = 0;  // @13_445800
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; }));  // @14_445800
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L44583e;  // @15_445800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @16_445800
  L44583e:;
  eax = (u32)(edi + 104);  // @18_445800
  ecx = esi;  // @19_445800
  PV[2] = (u32)(eax);  // @20_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[2], (u32)(1));  // @21_445800
  ecx = edx = 0;  // @22_445800
  eax = (u32)(EBP - 32);  // @23_445800
  ecx = esi;  // @24_445800
  PV[3] = (u32)(eax);  // @25_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[3], (u32)(3));  // @26_445800
  ecx = edx = 0;  // @27_445800
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @28_445800
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @29_445800
  ecx = (ecx << (u32)(8));  // @30_445800
  FL[3] = ecx;  // @31_445800
  ecx = (ecx + eax);  // @32_445800
  FL[3] = ecx;  // @33_445800
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @34_445800
  ecx = (ecx << (u32)(8));  // @35_445800
  FL[3] = ecx;  // @36_445800
  ecx = (ecx + eax);  // @37_445800
  FL[3] = ecx;  // @38_445800
  eax = (u32)(edi + 96);  // @39_445800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @40_445800
  ecx = esi;  // @41_445800
  PV[4] = (u32)(eax);  // @42_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[4], (u32)(1));  // @43_445800
  ecx = edx = 0;  // @44_445800
  eax = (u32)(EBP - 44);  // @45_445800
  ecx = esi;  // @46_445800
  PV[5] = (u32)(eax);  // @47_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[5], (u32)(1));  // @48_445800
  ecx = edx = 0;  // @49_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @50_445800
  X0[1] = 0;  // @51_445800
  X0[2] = 0;  // @52_445800
  X0[3] = 0;  // @53_445800
  eax = (u32)(EBP - 52);  // @54_445800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @55_445800
  ecx = esi;  // @56_445800
  PV[6] = (u32)(eax);  // @57_445800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806056) + 0), 4); v; })));  // @58_445800
  __builtin_memcpy((void *)((u32)(edi + 92) + 0), &X0[0], 4);  // @59_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[6], (u32)(1));  // @60_445800
  ecx = edx = 0;  // @61_445800
  eax = (u32)(EBP - 48);  // @62_445800
  ecx = esi;  // @63_445800
  PV[7] = (u32)(eax);  // @64_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[7], (u32)(1));  // @65_445800
  ecx = edx = 0;  // @66_445800
  eax = (u32)(edi + 76);  // @67_445800
  ecx = esi;  // @68_445800
  PV[8] = (u32)(eax);  // @69_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[8], (u32)(1));  // @70_445800
  ecx = edx = 0;  // @71_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @72_445800
  FL[2] = (ecx & ecx);  // @73_445800
  if (FL[2] == 0) goto L445928;  // @74_445800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_445800
  eax = (u32)(1);  // @76_445800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 6415), sizeof v); (u32)v; });  // @77_445800
  FL[0] = ecx; FL[1] = eax;  // @78_445800
  if (FL[0] == FL[1]) goto L4458f4;  // @79_445800
  L4458e8:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @81_445800
  FL[2] = (ebx & ebx);  // @82_445800
  if (FL[2] == 0) goto L445928;  // @83_445800
  eax = (eax + 1);  // @84_445800
  FL[3] = eax;  // @85_445800
  FL[0] = eax; FL[1] = ecx;  // @86_445800
  if (FL[0] != FL[1]) goto L4458e8;  // @87_445800
  L4458f4:;
  FL[2] = (ebx & ebx);  // @89_445800
  if (FL[2] == 0) goto L445928;  // @90_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 155), sizeof v); (u32)v; });  // @91_445800
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 108), sizeof v); (u32)v; });  // @92_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @93_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 840)))(ecx, PV[9]);  // @95_445800
  ecx = edx = 0;  // @96_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @97_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @98_445800
  X0[0] = F2U((float)(s32)X0[0]);  // @99_445800
  X0[1] = F2U((float)(s32)X0[1]);  // @100_445800
  X0[2] = F2U((float)(s32)X0[2]);  // @101_445800
  X0[3] = F2U((float)(s32)X0[3]);  // @102_445800
  PV[10] = (u32)(ecx);  // @103_445800
  ecx = ebx;  // @104_445800
  PV[11] = X0[0];  // @105_445800
  PV[12] = (u32)(edi);  // @106_445800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[12], PV[11]);  // @107_445800
  ecx = edx = 0;  // @108_445800
  L445928:;
  ecx = esi;  // @110_445800
  eax = ext_4e1600_thiscall1(ecx);  // @111_445800
    // @112_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @113_445800
  if (FL[0] != FL[1]) goto L445ae6;  // @114_445800
  eax = (u32)(EBP - 40);  // @115_445800
  ecx = esi;  // @116_445800
  PV[13] = (u32)(eax);  // @117_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[13], (u32)(1));  // @118_445800
  ecx = edx = 0;  // @119_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @120_445800
  FL[0] = eax; FL[1] = (u32)(1);  // @121_445800
  if (FL[0] != FL[1]) goto L4459b5;  // @122_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_445800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; });  // @124_445800
  X2[1] = 0;  // @125_445800
  X2[2] = 0;  // @126_445800
  X2[3] = 0;  // @127_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @128_445800
  if (FL[0] == FL[1]) goto L44599e;  // @129_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @130_445800
  FL[2] = (ecx & ecx);  // @131_445800
  if (FL[2] == 0) goto L44597a;  // @132_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @133_445800
  if (FL[0] == FL[1]) goto L44597a;  // @134_445800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @135_445800
  X2[1] = 0;  // @136_445800
  X2[2] = 0;  // @137_445800
  X2[3] = 0;  // @138_445800
  L44597a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @140_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @141_445800
  X0[0] = F2U((float)(s32)X0[0]);  // @142_445800
  X0[1] = F2U((float)(s32)X0[1]);  // @143_445800
  X0[2] = F2U((float)(s32)X0[2]);  // @144_445800
  X0[3] = F2U((float)(s32)X0[3]);  // @145_445800
  X1[0] = F2U((float)(s32)X1[0]);  // @146_445800
  X1[1] = F2U((float)(s32)X1[1]);  // @147_445800
  X1[2] = F2U((float)(s32)X1[2]);  // @148_445800
  X1[3] = F2U((float)(s32)X1[3]);  // @149_445800
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @150_445800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806036) + 0), 4); v; });  // @151_445800
  X0[1] = 0;  // @152_445800
  X0[2] = 0;  // @153_445800
  X0[3] = 0;  // @154_445800
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @155_445800
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @156_445800
  L44599e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @158_445800
  X0[1] = 0;  // @159_445800
  X0[2] = 0;  // @160_445800
  X0[3] = 0;  // @161_445800
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X2[0], 4);  // @162_445800
  X2[0] = F2U(U2F(X2[0]) + U2F(X2[0]));  // @163_445800
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @164_445800
  goto L445a29;  // @165_445800
  L4459b5:;
  FL[0] = eax; FL[1] = (u32)(2);  // @167_445800
  if (FL[0] != FL[1]) goto L445a56;  // @168_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @170_445800
  FL[2] = (eax & eax);  // @171_445800
  if (FL[2] == 0) goto L4459d7;  // @172_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @173_445800
  if (FL[0] != FL[1]) goto L445a02;  // @174_445800
  L4459d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @176_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_445800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @178_445800
  ecx = edx = 0;  // @179_445800
  ecx = (u32)(EBP - 33);  // @180_445800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 33), &v, sizeof v); }  // @181_445800
  PV[14] = (u32)(ecx);  // @182_445800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @183_445800
  ecx = eax;  // @184_445800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6805980), PV[14]);  // @185_445800
  ecx = edx = 0;  // @186_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 33), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @187_445800
  if (FL[0] == FL[1]) goto L445a0c;  // @188_445800
  L445a02:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806024) + 0), 4); v; });  // @190_445800
  X1[1] = 0;  // @191_445800
  X1[2] = 0;  // @192_445800
  X1[3] = 0;  // @193_445800
  goto L445a14;  // @194_445800
  L445a0c:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806032) + 0), 4); v; });  // @196_445800
  X1[1] = 0;  // @197_445800
  X1[2] = 0;  // @198_445800
  X1[3] = 0;  // @199_445800
  L445a14:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @201_445800
  X0[1] = 0;  // @202_445800
  X0[2] = 0;  // @203_445800
  X0[3] = 0;  // @204_445800
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @205_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X1[0]));  // @206_445800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @207_445800
  L445a29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @209_445800
  ecx = (u32)(EBP - 20);  // @210_445800
  PV[15] = (u32)(ecx);  // @211_445800
  ecx = edi;  // @212_445800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @213_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @214_445800
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @215_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[15]);  // @216_445800
  ecx = edx = 0;  // @217_445800
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @218_445800
  goto L445ae6;  // @219_445800
  L445a56:;
  FL[0] = eax; FL[1] = (u32)(3);  // @221_445800
  if (FL[0] != FL[1]) goto L445ae6;  // @222_445800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @224_445800
  FL[2] = (eax & eax);  // @225_445800
  if (FL[2] == 0) goto L445a78;  // @226_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @227_445800
  if (FL[0] != FL[1]) goto L445aa3;  // @228_445800
  L445a78:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @230_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @231_445800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @232_445800
  ecx = edx = 0;  // @233_445800
  ecx = (u32)(EBP - 33);  // @234_445800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 33), &v, sizeof v); }  // @235_445800
  PV[16] = (u32)(ecx);  // @236_445800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @237_445800
  ecx = eax;  // @238_445800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6805980), PV[16]);  // @239_445800
  ecx = edx = 0;  // @240_445800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 33), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @241_445800
  if (FL[0] == FL[1]) goto L445aad;  // @242_445800
  L445aa3:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; });  // @244_445800
  X1[1] = 0;  // @245_445800
  X1[2] = 0;  // @246_445800
  X1[3] = 0;  // @247_445800
  goto L445ab0;  // @248_445800
  L445aad:;
  X1[0] = 0;  // @250_445800
  X1[1] = 0;  // @251_445800
  X1[2] = 0;  // @252_445800
  X1[3] = 0;  // @253_445800
  L445ab0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @255_445800
  X0[1] = 0;  // @256_445800
  X0[2] = 0;  // @257_445800
  X0[3] = 0;  // @258_445800
  ecx = (u32)(EBP - 20);  // @259_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @260_445800
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @261_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X1[0]));  // @262_445800
  PV[17] = (u32)(ecx);  // @263_445800
  ecx = edi;  // @264_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @265_445800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @266_445800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @267_445800
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @268_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[17]);  // @269_445800
  ecx = edx = 0;  // @270_445800
  L445ae6:;
  ecx = esi;  // @272_445800
  eax = ext_4e1600_thiscall1(ecx);  // @273_445800
    // @274_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @275_445800
  if (FL[0] != FL[1]) goto L445b12;  // @276_445800
  eax = (u32)(EBP - 40);  // @277_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @278_445800
  PV[18] = (u32)(eax);  // @279_445800
  ecx = esi;  // @280_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[18], (u32)(1));  // @281_445800
  ecx = edx = 0;  // @282_445800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @283_445800
  if (FL[0] != FL[1]) goto L445b12;  // @284_445800
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) | (u32)(524288))); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @285_445800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @286_445800
  L445b12:;
  ecx = esi;  // @288_445800
  eax = ext_4e1600_thiscall1(ecx);  // @289_445800
    // @290_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @291_445800
  if (FL[0] != FL[1]) goto L445b2a;  // @292_445800
  eax = (u32)(edi + 112);  // @293_445800
  ecx = esi;  // @294_445800
  PV[19] = (u32)(eax);  // @295_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[19], (u32)(1));  // @296_445800
  ecx = edx = 0;  // @297_445800
  L445b2a:;
  ecx = esi;  // @299_445800
  eax = ext_4e1600_thiscall1(ecx);  // @300_445800
    // @301_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @302_445800
  if (FL[0] != FL[1]) goto L445b42;  // @303_445800
  eax = (u32)(edi + 116);  // @304_445800
  ecx = esi;  // @305_445800
  PV[20] = (u32)(eax);  // @306_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[20], (u32)(1));  // @307_445800
  ecx = edx = 0;  // @308_445800
  L445b42:;
  ecx = esi;  // @310_445800
  eax = ext_4e1600_thiscall1(ecx);  // @311_445800
    // @312_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @313_445800
  if (FL[0] != FL[1]) goto L445b58;  // @314_445800
  eax = (u32)(EBP - 40);  // @315_445800
  ecx = esi;  // @316_445800
  PV[21] = (u32)(eax);  // @317_445800
  eax = ext_4e1440_thiscall2(ecx, PV[21]);  // @318_445800
  ecx = edx = 0;  // @319_445800
  L445b58:;
  ecx = esi;  // @321_445800
  eax = ext_4e1600_thiscall1(ecx);  // @322_445800
    // @323_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @324_445800
  if (FL[0] != FL[1]) goto L445b84;  // @325_445800
  eax = (u32)(EBP - 40);  // @326_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @327_445800
  PV[22] = (u32)(eax);  // @328_445800
  ecx = esi;  // @329_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[22], (u32)(1));  // @330_445800
  ecx = edx = 0;  // @331_445800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @332_445800
  if (FL[0] == FL[1]) goto L445b84;  // @333_445800
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) | (u32)(65536))); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @334_445800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @335_445800
  L445b84:;
  ecx = esi;  // @337_445800
  eax = ext_4e1600_thiscall1(ecx);  // @338_445800
    // @339_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @340_445800
  if (FL[0] != FL[1]) goto L445c0a;  // @341_445800
  eax = (u32)(EBP - 20);  // @342_445800
  ecx = esi;  // @343_445800
  PV[23] = (u32)(eax);  // @344_445800
  eax = ext_4e12f0_thiscall3(ecx, PV[23], (u32)(4));  // @345_445800
  ecx = edx = 0;  // @346_445800
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 377) + 0), 4); v; });  // @347_445800
  X5[1] = 0;  // @348_445800
  X5[2] = 0;  // @349_445800
  X5[3] = 0;  // @350_445800
  ecx = (u32)(EBP - 20);  // @351_445800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 369) + 0), 4); v; });  // @352_445800
  X1[1] = 0;  // @353_445800
  X1[2] = 0;  // @354_445800
  X1[3] = 0;  // @355_445800
  X0[0] = X5[0];  // @356_445800
  X0[1] = X5[1];  // @357_445800
  X0[2] = X5[2];  // @358_445800
  X0[3] = X5[3];  // @359_445800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @360_445800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @361_445800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @362_445800
  PV[24] = (u32)(ecx);  // @363_445800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 381) + 0), 4); v; });  // @364_445800
  X3[1] = 0;  // @365_445800
  X3[2] = 0;  // @366_445800
  X3[3] = 0;  // @367_445800
  ecx = edi;  // @368_445800
  X5[0] = F2U(U2F(X5[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @369_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @370_445800
  X0[0] = X3[0];  // @371_445800
  X0[1] = X3[1];  // @372_445800
  X0[2] = X3[2];  // @373_445800
  X0[3] = X3[3];  // @374_445800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @375_445800
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @376_445800
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @377_445800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 373) + 0), 4); v; });  // @378_445800
  X1[1] = 0;  // @379_445800
  X1[2] = 0;  // @380_445800
  X1[3] = 0;  // @381_445800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @382_445800
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X5[0], 4);  // @383_445800
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X3[0], 4);  // @384_445800
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @385_445800
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X1[0], 4);  // @386_445800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[24]);  // @387_445800
  ecx = edx = 0;  // @388_445800
  L445c0a:;
  ecx = esi;  // @390_445800
  eax = ext_4e1600_thiscall1(ecx);  // @391_445800
    // @392_445800
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @393_445800
  if (FL[0] != FL[1]) goto L445c36;  // @394_445800
  eax = (u32)(EBP - 40);  // @395_445800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @396_445800
  PV[25] = (u32)(eax);  // @397_445800
  ecx = esi;  // @398_445800
  eax = ext_4e11e0_thiscall3(ecx, PV[25], (u32)(1));  // @399_445800
  ecx = edx = 0;  // @400_445800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @401_445800
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @402_445800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 368), &v, sizeof v); }  // @403_445800
  L445c36:;
  ecx = esi;  // @405_445800
  eax = ext_4e1b30_thiscall1(ecx);  // @406_445800
  ecx = edx = 0;  // @407_445800
  ext_633654(G(u32, 0x6f5630));  // @408_445800
  return eax;  // @409_445800
}
PCREG(445800, lifted_445800);

