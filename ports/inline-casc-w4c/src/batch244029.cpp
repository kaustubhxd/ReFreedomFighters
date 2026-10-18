// batch244029.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de440_fastcall3(u32, u32, u32) __asm__("ext_4de440");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_6361e0_thiscall1(u32) __asm__("ext_6361e0");
extern "C" u32 THISCALL ext_636230_thiscall1(u32) __asm__("ext_636230");
extern "C" u32 THISCALL ext_636280_thiscall1(u32) __asm__("ext_636280");
extern "C" u32 THISCALL ext_6362d0_thiscall1(u32) __asm__("ext_6362d0");
extern "C" u32 THISCALL ext_636330_thiscall1(u32) __asm__("ext_636330");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_636400_thiscall1(u32) __asm__("ext_636400");
extern "C" u32 THISCALL ext_636430_thiscall1(u32) __asm__("ext_636430");
extern "C" u32 THISCALL ext_638f20_thiscall2(u32, u32) __asm__("ext_638f20");
extern "C" u32 THISCALL ext_639240_thiscall2(u32, u32) __asm__("ext_639240");
extern "C" u32 THISCALL ext_639270_thiscall2(u32, u32) __asm__("ext_639270");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634da6_cdecl2(...) __asm__("ext_634da6");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_535b70(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @1_535b70
  X0[1] = 0;  // @2_535b70
  X0[2] = 0;  // @3_535b70
  X0[3] = 0;  // @4_535b70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_535b70
  ebx = ecx;  // @6_535b70
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2503) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2503) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2503) + 0), 4); v; }))))))) goto L535e80;  // @7_535b70
  FL[2] = (edi & edi);  // @8_535b70
  if (FL[2] == 0) goto L535e80;  // @9_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_535b70
  ecx = (u32)(EBP - 72);  // @11_535b70
  PV[0] = (u32)(ecx);  // @12_535b70
  ecx = edi;  // @13_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @14_535b70
  ecx = edx = 0;  // @15_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_535b70
  ecx = (u32)(EBP - 72);  // @17_535b70
  PV[1] = (u32)(ecx);  // @18_535b70
  ecx = edi;  // @19_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @20_535b70
  ecx = edx = 0;  // @21_535b70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_535b70
  edx = eax;  // @23_535b70
  if (FL[0] == FL[1]) goto L535e80;  // @24_535b70
  L535bd0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_535b70
  PV[2] = (u32)(edx);  // @27_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[2]);  // @30_535b70
  ecx = edx = 0;  // @31_535b70
  esi = eax;  // @32_535b70
  FL[2] = (esi & esi);  // @33_535b70
  if (FL[2] == 0) goto L535e68;  // @34_535b70
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(64));  // @35_535b70
  if (FL[2] != 0) goto L535e68;  // @36_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_535b70
  ecx = ebx;  // @38_535b70
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @39_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[3]);  // @40_535b70
  ecx = edx = 0;  // @41_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_535b70
  ecx = ebx;  // @43_535b70
  PV[4] = (u32)(eax);  // @44_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 476)))(ecx, PV[4]);  // @45_535b70
  ecx = edx = 0;  // @46_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 212) + 0), 4); v; });  // @47_535b70
  X0[1] = 0;  // @48_535b70
  X0[2] = 0;  // @49_535b70
  X0[3] = 0;  // @50_535b70
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @51_535b70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 216) + 0), 4); v; });  // @52_535b70
  X1[1] = 0;  // @53_535b70
  X1[2] = 0;  // @54_535b70
  X1[3] = 0;  // @55_535b70
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @56_535b70
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; })));  // @57_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 220) + 0), 4); v; });  // @58_535b70
  X0[1] = 0;  // @59_535b70
  X0[2] = 0;  // @60_535b70
  X0[3] = 0;  // @61_535b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @62_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_535b70
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @64_535b70
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @65_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @66_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @68_535b70
  ecx = edx = 0;  // @69_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_535b70
  PV[5] = (u32)(eax);  // @71_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @72_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[5]);  // @74_535b70
  ecx = edx = 0;  // @75_535b70
  esi = eax;  // @76_535b70
  FL[2] = (esi & esi);  // @77_535b70
  if (FL[2] == 0) goto L535e7f;  // @78_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_535b70
  eax = (u32)(EBP - 16);  // @80_535b70
  PV[6] = (u32)(eax);  // @81_535b70
  ecx = esi;  // @82_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[6]);  // @83_535b70
  ecx = edx = 0;  // @84_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @85_535b70
  X0[1] = 0;  // @86_535b70
  X0[2] = 0;  // @87_535b70
  X0[3] = 0;  // @88_535b70
  X1[0] = 0;  // @89_535b70
  X1[1] = 0;  // @90_535b70
  X1[2] = 0;  // @91_535b70
  X1[3] = 0;  // @92_535b70
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L535e68;  // @93_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @94_535b70
  ecx = (u32)(EBP - 32);  // @95_535b70
  PV[7] = (u32)(ecx);  // @96_535b70
  ecx = esi;  // @97_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[7]);  // @98_535b70
  ecx = edx = 0;  // @99_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @100_535b70
  X0[1] = 0;  // @101_535b70
  X0[2] = 0;  // @102_535b70
  X0[3] = 0;  // @103_535b70
  ecx = esi;  // @104_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; })));  // @105_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_535b70
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @107_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 584), sizeof v); (u32)v; });  // @108_535b70
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @109_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @110_535b70
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @111_535b70
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @112_535b70
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @113_535b70
  ecx = edx = 0;  // @114_535b70
  __asm__ volatile("fdivrs %0" :: "m"(*(float *)(u32)(EBP - 20)) : "st");  // @115_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @117_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_535b70
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @119_535b70
  X2[1] = 0;  // @120_535b70
  X2[2] = 0;  // @121_535b70
  X2[3] = 0;  // @122_535b70
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; })));  // @123_535b70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @124_535b70
  X1[1] = 0;  // @125_535b70
  X1[2] = 0;  // @126_535b70
  X1[3] = 0;  // @127_535b70
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @128_535b70
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @129_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @130_535b70
  X0[1] = 0;  // @131_535b70
  X0[2] = 0;  // @132_535b70
  X0[3] = 0;  // @133_535b70
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 64) + 0), 4); v; })));  // @134_535b70
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @135_535b70
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 36)) :: "st");  // @136_535b70
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @137_535b70
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @138_535b70
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @139_535b70
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X2[0], 4);  // @140_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @141_535b70
  ecx = edx = 0;  // @142_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @143_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @144_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @145_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @146_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @147_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @148_535b70
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @149_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @150_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 4), &X0[1], 4);  // @151_535b70
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 44)) : "st");  // @152_535b70
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[8] = (u32)v_; PV[9] = (u32)(v_ >> 32); }  // @153_535b70
  eax = ext_634da6_cdecl2(PV[8], PV[9]);  // @154_535b70
    // @155_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_535b70
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 60)) :: "st");  // @157_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @158_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 240)))(ecx);  // @160_535b70
  ecx = edx = 0;  // @161_535b70
  FL[1] = eax;  // @162_535b70
  eax = (0u - eax);  // @163_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @164_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @165_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @166_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @167_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @168_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @169_535b70
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @170_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @171_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 4), &X0[1], 4);  // @172_535b70
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 44)) : "st");  // @173_535b70
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[10] = (u32)v_; PV[11] = (u32)(v_ >> 32); }  // @174_535b70
  eax = ext_634da6_cdecl2(PV[10], PV[11]);  // @175_535b70
    // @176_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @177_535b70
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 56)) :: "st");  // @178_535b70
  FL[2] = (eax & eax);  // @179_535b70
  if (FL[2] == 0) goto L535e68;  // @180_535b70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @181_535b70
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @182_535b70
  FL[3] = esi;  // @183_535b70
  if (FL[3] == 0) goto L535e68;  // @184_535b70
  ecx = esi;  // @185_535b70
  edx = (u32)(ecx + 1);  // @186_535b70
  L535db0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @188_535b70
  ecx = (ecx + 1);  // @189_535b70
  FL[3] = ecx;  // @190_535b70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @191_535b70
  if (FL[2] != 0) goto L535db0;  // @192_535b70
  ecx = (ecx - edx);  // @193_535b70
  FL[3] = ecx;  // @194_535b70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @195_535b70
  X1[1] = 0;  // @196_535b70
  X1[2] = 0;  // @197_535b70
  X1[3] = 0;  // @198_535b70
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @199_535b70
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @200_535b70
  ecx = (ecx >> (u32)(31));  // @201_535b70
  FL[3] = ecx;  // @202_535b70
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 4), 4); v; })));  // @203_535b70
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @204_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @205_535b70
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @206_535b70
  X0[0] = 0;  // @207_535b70
  X0[1] = 0;  // @208_535b70
  X0[2] = 0;  // @209_535b70
  X0[3] = 0;  // @210_535b70
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X1[0], 4);  // @211_535b70
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L535e68;  // @212_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @213_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @214_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @215_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @216_535b70
  ecx = edx = 0;  // @217_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @218_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @219_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @220_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @221_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @222_535b70
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))))))) goto L535e68;  // @223_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @224_535b70
  X0[1] = 0;  // @225_535b70
  X0[2] = 0;  // @226_535b70
  X0[3] = 0;  // @227_535b70
  X1[0] = 0;  // @228_535b70
  X1[1] = 0;  // @229_535b70
  X1[2] = 0;  // @230_535b70
  X1[3] = 0;  // @231_535b70
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L535e68;  // @232_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @234_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @236_535b70
  ecx = edx = 0;  // @237_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @238_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @239_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @240_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @241_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @242_535b70
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; }))))))) goto L535e68;  // @243_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @244_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @245_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @246_535b70
  ecx = edx = 0;  // @247_535b70
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @248_535b70
  PV[12] = (u32)(esi);  // @249_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @250_535b70
  PV[13] = (u32)(ecx);  // @251_535b70
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @252_535b70
  PV[14] = (u32)(ecx);  // @253_535b70
  PV[15] = (u32)(eax);  // @254_535b70
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[15], PV[14], PV[13], (u32)(6779752), PV[12]);  // @255_535b70
  ecx = edx = 0;  // @256_535b70
  L535e68:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @258_535b70
  ecx = (u32)(EBP - 72);  // @259_535b70
  PV[16] = (u32)(ecx);  // @260_535b70
  ecx = edi;  // @261_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[16]);  // @262_535b70
  ecx = edx = 0;  // @263_535b70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @264_535b70
  edx = eax;  // @265_535b70
  if (FL[0] != FL[1]) goto L535bd0;  // @266_535b70
  L535e7f:;
  L535e80:;
  ext_633654(G(u32, 0x6f5630));  // @269_535b70
  return eax;  // @270_535b70
}
PCREG(535b70, lifted_535b70);

extern "C" u32 THISCALL lifted_63fea0(u32 ecx_in, u32 a0) {
  u8 F[0x610] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x510);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x510 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63fea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1112), &v, sizeof v); }  // @1_63fea0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 1104), &v, sizeof v); }  // @2_63fea0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @3_63fea0
  eax = (u32)(edi + 44);  // @4_63fea0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 66), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edi + 66), &v, sizeof v); }  // @5_63fea0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 66), sizeof v); (u32)v; });  // @6_63fea0
  ecx = esi;  // @7_63fea0
  PV[0] = (u32)(eax);  // @8_63fea0
  eax = (u32)(edi + 8);  // @9_63fea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_63fea0
  PV[1] = (u32)(eax);  // @11_63fea0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[1], PV[0]);  // @12_63fea0
  ecx = edx = 0;  // @13_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @14_63fea0
  ecx = (u32)(EBP - 76);  // @15_63fea0
  PV[2] = (u32)(ecx);  // @16_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1116), &v, sizeof v); }  // @17_63fea0
  ecx = (u32)(EBP - 1100);  // @18_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_63fea0
  PV[3] = (u32)(ecx);  // @20_63fea0
  ecx = esi;  // @21_63fea0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 904)))(ecx, PV[3], PV[2]);  // @22_63fea0
  ecx = edx = 0;  // @23_63fea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_63fea0
  ecx = (u32)(EBP - 76);  // @25_63fea0
  PV[4] = (u32)(ecx);  // @26_63fea0
  PV[5] = (u32)(eax);  // @27_63fea0
  ecx = esi;  // @28_63fea0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 900)))(ecx, PV[5], PV[4]);  // @29_63fea0
  ecx = edx = 0;  // @30_63fea0
  ecx = (u32)(EBP - 1100);  // @31_63fea0
  eax = (eax - ecx);  // @32_63fea0
  FL[3] = eax;  // @33_63fea0
  eax = (u32)((s32)eax >> (u32)(3));  // @34_63fea0
  FL[3] = eax;  // @35_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1120), &v, sizeof v); }  // @36_63fea0
  FL[2] = (eax & eax);  // @37_63fea0
  if (FL[2] != 0) goto L63ff3b;  // @38_63fea0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @39_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @40_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @41_63fea0
  ext_633654(G(u32, 0x6f5630));  // @42_63fea0
  return eax;  // @43_63fea0
  L63ff3b:;
  esi = (u32)(EBP - 1100);  // @45_63fea0
  ebx = 0;  // @46_63fea0
  FL[3] = ebx;  // @47_63fea0
  edi = eax;  // @48_63fea0
  L63ff46:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @50_63fea0
  esi = (u32)(esi + 8);  // @51_63fea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @52_63fea0
  ecx = (ecx - eax);  // @53_63fea0
  FL[3] = ecx;  // @54_63fea0
  eax = (u32)(2454267027);  // @55_63fea0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @56_63fea0
  edx = (edx + ecx);  // @57_63fea0
  FL[3] = edx;  // @58_63fea0
  edx = (u32)((s32)edx >> (u32)(6));  // @59_63fea0
  FL[3] = edx;  // @60_63fea0
  eax = edx;  // @61_63fea0
  eax = (eax >> (u32)(31));  // @62_63fea0
  FL[3] = eax;  // @63_63fea0
  eax = (eax + 1);  // @64_63fea0
  FL[3] = eax;  // @65_63fea0
  eax = (eax + edx);  // @66_63fea0
  FL[3] = eax;  // @67_63fea0
  ebx = (ebx + eax);  // @68_63fea0
  FL[3] = ebx;  // @69_63fea0
  edi = (edi - (u32)(1));  // @70_63fea0
  FL[3] = edi;  // @71_63fea0
  if (FL[3] != 0) goto L63ff46;  // @72_63fea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1112), sizeof v); (u32)v; });  // @73_63fea0
  esi = ebx;  // @74_63fea0
  esi = (esi << (u32)(6));  // @75_63fea0
  FL[3] = esi;  // @76_63fea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_63fea0
  eax = (u32)(esi + ebx*4);  // @78_63fea0
  PV[6] = (u32)(eax);  // @79_63fea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[6]);  // @80_63fea0
  ecx = edx = 0;  // @81_63fea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1104), sizeof v); (u32)v; });  // @82_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1108), &v, sizeof v); }  // @83_63fea0
  FL[2] = (eax & eax);  // @84_63fea0
  if (FL[2] != 0) goto L63ffd5;  // @85_63fea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_63fea0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7087708), (u32)(1116));  // @88_63fea0
  ecx = edx = 0;  // @89_63fea0
  PV[7] = (u32)(eax);  // @90_63fea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_63fea0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(7088060));  // @92_63fea0
  ecx = edx = 0;  // @93_63fea0
  eax = 0;  // @94_63fea0
  FL[3] = eax;  // @95_63fea0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 66), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(edi + 66), &v, sizeof v); }  // @96_63fea0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 66), sizeof v); (u32)v; });  // @97_63fea0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @98_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @99_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @100_63fea0
  ext_633654(G(u32, 0x6f5630));  // @101_63fea0
  return eax;  // @102_63fea0
  L63ffd5:;
  ecx = (u32)(eax + esi);  // @104_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @105_63fea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1112), &v, sizeof v); }  // @106_63fea0
  eax = (u32)(EBP - 1100);  // @107_63fea0
  { u16 v = (u16)((ebx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @108_63fea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @109_63fea0
  L63fff0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @111_63fea0
  ecx = (u32)(EBP - 40);  // @112_63fea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @113_63fea0
  eax = (eax + (u32)(8));  // @114_63fea0
  FL[3] = eax;  // @115_63fea0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 1104), &v, sizeof v); }  // @116_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1136), &v, sizeof v); }  // @117_63fea0
  eax = ext_4de7a0_thiscall1(ecx);  // @118_63fea0
    // @119_63fea0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1148), &v, sizeof v); }  // @120_63fea0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1144), &v, sizeof v); }  // @121_63fea0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1140), &v, sizeof v); }  // @122_63fea0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @123_63fea0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1116), sizeof v); (u32)v; });  // @124_63fea0
  if (FL[0] == FL[1]) goto L640072;  // @125_63fea0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1116), sizeof v); (u32)v; });  // @126_63fea0
  L640040:;
  edx = esi;  // @128_63fea0
  ecx = (u32)(EBP - 1148);  // @129_63fea0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @130_63fea0
  ecx = edx = 0;  // @131_63fea0
  edx = (u32)(esi + 36);  // @132_63fea0
  ecx = (u32)(EBP - 1148);  // @133_63fea0
  eax = ext_441940_fastcall2(ecx, edx);  // @134_63fea0
  ecx = edx = 0;  // @135_63fea0
  edx = esi;  // @136_63fea0
  ecx = (u32)(EBP - 40);  // @137_63fea0
  eax = ext_4de480_fastcall2(ecx, edx);  // @138_63fea0
  ecx = edx = 0;  // @139_63fea0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @140_63fea0
  FL[0] = esi; FL[1] = ebx;  // @141_63fea0
  if (FL[0] != FL[1]) goto L640040;  // @142_63fea0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1104), sizeof v); (u32)v; });  // @143_63fea0
  L640072:;
  FL[0] = ebx; FL[1] = edi;  // @145_63fea0
  if (FL[0] > FL[1]) goto L64017d;  // @146_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1104), sizeof v); (u32)v; });  // @147_63fea0
  edi = (edi - eax);  // @148_63fea0
  FL[3] = edi;  // @149_63fea0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1108), sizeof v); (u32)v; });  // @150_63fea0
  ebx = (ebx + (u32)(60));  // @151_63fea0
  FL[3] = ebx;  // @152_63fea0
  ecx = (u32)(eax + 72);  // @153_63fea0
  eax = (u32)(613566757);  // @154_63fea0
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @155_63fea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1104), &v, sizeof v); }  // @156_63fea0
  edi = (edi - edx);  // @157_63fea0
  FL[3] = edi;  // @158_63fea0
  edi = (edi >> (u32)(1));  // @159_63fea0
  FL[3] = edi;  // @160_63fea0
  edi = (edi + edx);  // @161_63fea0
  FL[3] = edi;  // @162_63fea0
  edi = (edi >> (u32)(6));  // @163_63fea0
  FL[3] = edi;  // @164_63fea0
  edi = (edi + 1);  // @165_63fea0
  FL[3] = edi;  // @166_63fea0
  L6400a5:;
  esi = (u32)(ecx - 72);  // @168_63fea0
  edx = (u32)(ecx - 24);  // @169_63fea0
  PV[8] = (u32)(esi);  // @170_63fea0
  ecx = (u32)(EBP - 1132);  // @171_63fea0
  eax = ext_441970_fastcall3(ecx, edx, PV[8]);  // @172_63fea0
  ecx = edx = 0;  // @173_63fea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1104), sizeof v); (u32)v; });  // @174_63fea0
  ecx = (u32)(EBP - 1132);  // @175_63fea0
  edx = (u32)(edx - 36);  // @176_63fea0
  eax = ext_441940_fastcall2(ecx, edx);  // @177_63fea0
  ecx = edx = 0;  // @178_63fea0
  PV[9] = (u32)(esi);  // @179_63fea0
  edx = (u32)(EBP - 40);  // @180_63fea0
  ecx = (u32)(EBP - 76);  // @181_63fea0
  eax = ext_4de440_fastcall3(ecx, edx, PV[9]);  // @182_63fea0
  ecx = edx = 0;  // @183_63fea0
  edx = (u32)(EBP - 40);  // @184_63fea0
  ecx = (u32)(EBP - 1132);  // @185_63fea0
  eax = ext_4419f0_fastcall2(ecx, edx);  // @186_63fea0
  ecx = edx = 0;  // @187_63fea0
  edx = (u32)(EBP - 1148);  // @188_63fea0
  ecx = (u32)(EBP - 1132);  // @189_63fea0
  eax = ext_441940_fastcall2(ecx, edx);  // @190_63fea0
  ecx = edx = 0;  // @191_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1108), sizeof v); (u32)v; });  // @192_63fea0
  ecx = (u32)(ebx - 44);  // @193_63fea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1132) + 0), 4); v; });  // @194_63fea0
  X0[1] = 0;  // @195_63fea0
  X0[2] = 0;  // @196_63fea0
  X0[3] = 0;  // @197_63fea0
  edx = (u32)(EBP - 76);  // @198_63fea0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @199_63fea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1128) + 0), 4); v; });  // @200_63fea0
  X0[1] = 0;  // @201_63fea0
  X0[2] = 0;  // @202_63fea0
  X0[3] = 0;  // @203_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1104), sizeof v); (u32)v; });  // @204_63fea0
  __builtin_memcpy((void *)((u32)(ebx - 56) + 0), &X0[0], 4);  // @205_63fea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1124) + 0), 4); v; });  // @206_63fea0
  X0[1] = 0;  // @207_63fea0
  X0[2] = 0;  // @208_63fea0
  X0[3] = 0;  // @209_63fea0
  __builtin_memcpy((void *)((u32)(ebx - 52) + 0), &X0[0], 4);  // @210_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @211_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 48), &v, sizeof v); }  // @212_63fea0
  eax = ext_4de420_fastcall2(ecx, edx);  // @213_63fea0
    // @214_63fea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1104), sizeof v); (u32)v; });  // @215_63fea0
  ebx = (u32)(ebx + 64);  // @216_63fea0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1108), sizeof v); (u32)v; }) + (u32)(64))); __builtin_memcpy((void *)(u32)(EBP - 1108), &v, sizeof v); }  // @217_63fea0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1108), sizeof v); (u32)v; });  // @218_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @219_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 72), &v, sizeof v); }  // @220_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 4), sizeof v); (u32)v; });  // @221_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 68), &v, sizeof v); }  // @222_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @223_63fea0
  ecx = (ecx + (u32)(112));  // @224_63fea0
  FL[3] = ecx;  // @225_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx - 64), &v, sizeof v); }  // @226_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1112), sizeof v); (u32)v; });  // @227_63fea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 1104), &v, sizeof v); }  // @228_63fea0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @229_63fea0
  eax = (eax + (u32)(4));  // @230_63fea0
  FL[3] = eax;  // @231_63fea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1112), &v, sizeof v); }  // @232_63fea0
  edi = (edi - (u32)(1));  // @233_63fea0
  FL[3] = edi;  // @234_63fea0
  if (FL[3] != 0) goto L6400a5;  // @235_63fea0
  L64017d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1120), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 1120), &v, sizeof v); }  // @237_63fea0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1120), sizeof v); (u32)v; });  // @238_63fea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1136), sizeof v); (u32)v; });  // @239_63fea0
  if (FL[3] != 0) goto L63fff0;  // @240_63fea0
  ext_633654(G(u32, 0x6f5630));  // @241_63fea0
  return eax;  // @242_63fea0
}
PCREG(63fea0, lifted_63fea0);

extern "C" u32 THISCALL lifted_613380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e3d1);  // @h_613380
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_613380
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @1_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_613380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_613380
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @4_613380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @5_613380
  ecx = edx = 0;  // @6_613380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @7_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_613380
  eax = (eax + ebx);  // @9_613380
  FL[3] = eax;  // @10_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @11_613380
  eax = (u32)(ebx + ecx);  // @12_613380
  ecx = (u32)(EBP - 160);  // @13_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @14_613380
  eax = ext_6361e0_thiscall1(ecx);  // @15_613380
    // @16_613380
  ecx = (u32)(EBP - 216);  // @17_613380
  reg.state = (s32)((u32)(0));  // @18_613380
  eax = ext_6362d0_thiscall1(ecx);  // @19_613380
    // @20_613380
  ecx = (u32)(EBP - 276);  // @21_613380
  reg.state = (s32)((u32)(1));  // @22_613380
  eax = ext_636330_thiscall1(ecx);  // @23_613380
    // @24_613380
  ecx = (u32)(EBP - 112);  // @25_613380
  reg.state = (s32)((u32)(2));  // @26_613380
  eax = ext_636230_thiscall1(ecx);  // @27_613380
    // @28_613380
  ecx = (u32)(EBP - 64);  // @29_613380
  reg.state = (s32)((u32)(3));  // @30_613380
  eax = ext_636280_thiscall1(ecx);  // @31_613380
    // @32_613380
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @33_613380
  eax = 0;  // @34_613380
  FL[3] = eax;  // @35_613380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @36_613380
  reg.state = (s32)((u32)(4));  // @37_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @38_613380
  L613440:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @40_613380
  FL[2] = (eax & eax);  // @41_613380
  if (FL[2] == 0) goto L61361d;  // @42_613380
  ecx = (u32)(ebx + 8);  // @43_613380
  ecx = (ecx + eax);  // @44_613380
  FL[3] = ecx;  // @45_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 4), sizeof v); (u32)v; });  // @46_613380
  FL[0] = eax; FL[1] = (u32)(1346456654);  // @47_613380
  if (FL[0] > FL[1]) goto L6134fe;  // @48_613380
  if (FL[0] == FL[1]) goto L6134c7;  // @49_613380
  eax = (eax - (u32)(1146639409));  // @50_613380
  FL[3] = eax;  // @51_613380
  if (FL[3] == 0) goto L61349c;  // @52_613380
  eax = (eax - (u32)(2));  // @53_613380
  FL[3] = eax;  // @54_613380
  if (FL[3] != 0) goto L61350c;  // @55_613380
  PV[0] = (u32)(ecx);  // @56_613380
  ecx = (u32)(EBP - 64);  // @57_613380
  eax = ext_638f20_thiscall2(ecx, PV[0]);  // @58_613380
  ecx = edx = 0;  // @59_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @60_613380
  ecx = eax;  // @61_613380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_613380
  eax = (eax + 1);  // @63_613380
  FL[3] = eax;  // @64_613380
  ecx = (ecx << (u32)(4));  // @65_613380
  FL[3] = ecx;  // @66_613380
  ecx = (ecx + eax);  // @67_613380
  FL[3] = ecx;  // @68_613380
  eax = (u32)(esi + ecx*4);  // @69_613380
  ecx = esi;  // @70_613380
  PV[1] = (u32)(eax);  // @71_613380
  eax = (u32)(EBP - 64);  // @72_613380
  PV[2] = (u32)(eax);  // @73_613380
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[2], PV[1]);  // @74_613380
  ecx = edx = 0;  // @75_613380
  edi = (u32)(EBP - 64);  // @76_613380
  goto L613582;  // @77_613380
  L61349c:;
  PV[3] = (u32)(ecx);  // @79_613380
  ecx = (u32)(EBP - 112);  // @80_613380
  eax = ext_638f20_thiscall2(ecx, PV[3]);  // @81_613380
  ecx = edx = 0;  // @82_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @83_613380
  ecx = eax;  // @84_613380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_613380
  eax = (eax + 1);  // @86_613380
  FL[3] = eax;  // @87_613380
  ecx = (ecx << (u32)(4));  // @88_613380
  FL[3] = ecx;  // @89_613380
  ecx = (ecx + eax);  // @90_613380
  FL[3] = ecx;  // @91_613380
  eax = (u32)(esi + ecx*4);  // @92_613380
  ecx = esi;  // @93_613380
  PV[4] = (u32)(eax);  // @94_613380
  eax = (u32)(EBP - 112);  // @95_613380
  PV[5] = (u32)(eax);  // @96_613380
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[5], PV[4]);  // @97_613380
  ecx = edx = 0;  // @98_613380
  edi = (u32)(EBP - 112);  // @99_613380
  goto L613582;  // @100_613380
  L6134c7:;
  PV[6] = (u32)(ecx);  // @102_613380
  ecx = (u32)(EBP - 216);  // @103_613380
  eax = ext_639240_thiscall2(ecx, PV[6]);  // @104_613380
  ecx = edx = 0;  // @105_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @106_613380
  ecx = eax;  // @107_613380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_613380
  eax = (eax + 1);  // @109_613380
  FL[3] = eax;  // @110_613380
  ecx = (ecx << (u32)(4));  // @111_613380
  FL[3] = ecx;  // @112_613380
  ecx = (ecx + eax);  // @113_613380
  FL[3] = ecx;  // @114_613380
  eax = (u32)(esi + ecx*4);  // @115_613380
  ecx = esi;  // @116_613380
  PV[7] = (u32)(eax);  // @117_613380
  eax = (u32)(EBP - 216);  // @118_613380
  PV[8] = (u32)(eax);  // @119_613380
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[8], PV[7]);  // @120_613380
  ecx = edx = 0;  // @121_613380
  edi = (u32)(EBP - 216);  // @122_613380
  goto L613582;  // @123_613380
  L6134fe:;
  FL[0] = eax; FL[1] = (u32)(1346456655);  // @125_613380
  if (FL[0] == FL[1]) goto L613550;  // @126_613380
  FL[0] = eax; FL[1] = (u32)(1380401729);  // @127_613380
  if (FL[0] == FL[1]) goto L61351c;  // @128_613380
  L61350c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @130_613380
  FL[2] = (eax & eax);  // @131_613380
  if (FL[2] == 0) goto L613519;  // @132_613380
  eax = ((u32(STDCALL *)(void))(eax))();  // @133_613380
  ecx = edx = 0;  // @134_613380
  goto L613582;  // @135_613380
  L613519:;
  __builtin_trap();  // @137_613380
  L61351c:;
  PV[9] = (u32)(ecx);  // @139_613380
  ecx = (u32)(EBP - 160);  // @140_613380
  eax = ext_638f20_thiscall2(ecx, PV[9]);  // @141_613380
  ecx = edx = 0;  // @142_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @143_613380
  ecx = eax;  // @144_613380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_613380
  eax = (eax + 1);  // @146_613380
  FL[3] = eax;  // @147_613380
  ecx = (ecx << (u32)(4));  // @148_613380
  FL[3] = ecx;  // @149_613380
  ecx = (ecx + eax);  // @150_613380
  FL[3] = ecx;  // @151_613380
  eax = (u32)(esi + ecx*4);  // @152_613380
  ecx = esi;  // @153_613380
  PV[10] = (u32)(eax);  // @154_613380
  eax = (u32)(EBP - 160);  // @155_613380
  PV[11] = (u32)(eax);  // @156_613380
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[11], PV[10]);  // @157_613380
  ecx = edx = 0;  // @158_613380
  edi = (u32)(EBP - 160);  // @159_613380
  goto L613582;  // @160_613380
  L613550:;
  PV[12] = (u32)(ecx);  // @162_613380
  ecx = (u32)(EBP - 276);  // @163_613380
  eax = ext_639270_thiscall2(ecx, PV[12]);  // @164_613380
  ecx = edx = 0;  // @165_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @166_613380
  ecx = eax;  // @167_613380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_613380
  eax = (eax + 1);  // @169_613380
  FL[3] = eax;  // @170_613380
  ecx = (ecx << (u32)(4));  // @171_613380
  FL[3] = ecx;  // @172_613380
  ecx = (ecx + eax);  // @173_613380
  FL[3] = ecx;  // @174_613380
  eax = (u32)(esi + ecx*4);  // @175_613380
  ecx = esi;  // @176_613380
  PV[13] = (u32)(eax);  // @177_613380
  eax = (u32)(EBP - 276);  // @178_613380
  PV[14] = (u32)(eax);  // @179_613380
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[14], PV[13]);  // @180_613380
  ecx = edx = 0;  // @181_613380
  edi = (u32)(EBP - 276);  // @182_613380
  L613582:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @184_613380
  ecx = edi;  // @185_613380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 72)))(ecx);  // @186_613380
  ecx = edx = 0;  // @187_613380
  FL[2] = (u32)(s32)(s8)(eax & 0xff);   /* w4c: sign of the byte, the next jump is jns */  // @188_613380
  if ((s32)FL[2] >= 0) goto L613617;  // @189_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @190_613380
  ecx = edi;  // @191_613380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 80)))(ecx);  // @192_613380
  ecx = edx = 0;  // @193_613380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @194_613380
  edx = (u32)(4);  // @195_613380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @196_613380
  ecx = 0;  // @197_613380
  FL[3] = ecx;  // @198_613380
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; }));  // @199_613380
  FL[3] = ebx;  // @200_613380
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @201_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @202_613380
  eax = (eax + 1);  // @203_613380
  FL[3] = eax;  // @204_613380
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @205_613380
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @206_613380
  FL[1] = ecx;  // @207_613380
  ecx = (0u - ecx);  // @208_613380
  ecx = (ecx | eax);  // @209_613380
  FL[3] = ecx;  // @210_613380
  PV[15] = (u32)(ecx);  // @211_613380
  eax = ext_41e290_cdecl1(PV[15]);  // @212_613380
  ecx = edx = 0;  // @213_613380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @214_613380
  edx = 0;  // @215_613380
  FL[3] = edx;  // @216_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @217_613380
  ecx = (ecx + (u32)(1));  // @218_613380
  FL[3] = ecx;  // @219_613380
  if (FL[3] == 0) goto L6135f9;  // @220_613380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; });  // @221_613380
  ecx = eax;  // @222_613380
  ebx = (ebx - eax);  // @223_613380
  FL[3] = ebx;  // @224_613380
  L6135e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx), sizeof v); (u32)v; });  // @226_613380
  ecx = (u32)(ecx + 4);  // @227_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @228_613380
  edx = (edx + 1);  // @229_613380
  FL[3] = edx;  // @230_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @231_613380
  eax = (eax + 1);  // @232_613380
  FL[3] = eax;  // @233_613380
  FL[0] = edx; FL[1] = eax;  // @234_613380
  if (FL[0] < FL[1]) goto L6135e2;  // @235_613380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; });  // @236_613380
  L6135f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @238_613380
  ecx = edi;  // @239_613380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 80)))(ecx);  // @240_613380
  ecx = edx = 0;  // @241_613380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @242_613380
  ecx = eax;  // @243_613380
  ecx = (ecx << (u32)(4));  // @244_613380
  FL[3] = ecx;  // @245_613380
  ecx = (ecx + eax);  // @246_613380
  FL[3] = ecx;  // @247_613380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @248_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 64), &v, sizeof v); }  // @249_613380
  L613617:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @251_613380
  L61361d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @253_613380
  eax = (eax + 1);  // @254_613380
  FL[3] = eax;  // @255_613380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @256_613380
  FL[0] = eax; FL[1] = (u32)(2048);  // @257_613380
  if (FL[0] < FL[1]) goto L613440;  // @258_613380
  ecx = (u32)(EBP - 64);  // @259_613380
  eax = ext_6363a0_thiscall1(ecx);  // @260_613380
  ecx = edx = 0;  // @261_613380
  ecx = (u32)(EBP - 112);  // @262_613380
  eax = ext_6363a0_thiscall1(ecx);  // @263_613380
  ecx = edx = 0;  // @264_613380
  ecx = (u32)(EBP - 276);  // @265_613380
  eax = ext_636430_thiscall1(ecx);  // @266_613380
  ecx = edx = 0;  // @267_613380
  ecx = (u32)(EBP - 216);  // @268_613380
  eax = ext_636400_thiscall1(ecx);  // @269_613380
  ecx = edx = 0;  // @270_613380
  ecx = (u32)(EBP - 160);  // @271_613380
  eax = ext_6363a0_thiscall1(ecx);  // @272_613380
  ecx = edx = 0;  // @273_613380
  SEH_LEAVE();  // @274_613380
  ext_633654(G(u32, 0x6f5630));  // @275_613380
  return eax;  // @276_613380
}
PCREG(613380, lifted_613380);

