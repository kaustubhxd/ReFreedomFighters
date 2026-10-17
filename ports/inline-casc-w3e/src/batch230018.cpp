// batch230018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 ext_634da6_cdecl2(...) __asm__("ext_634da6");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_47b290(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338520) + 0), 4); v; });  // @0_47b290
  X0[1] = 0;  // @1_47b290
  X0[2] = 0;  // @2_47b290
  X0[3] = 0;  // @3_47b290
  X1[0] = 0;  // @4_47b290
  X1[1] = 0;  // @5_47b290
  X1[2] = 0;  // @6_47b290
  X1[3] = 0;  // @7_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_47b290
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @9_47b290
  edi = ecx;  // @10_47b290
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @11_47b290
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @12_47b290
  if (__builtin_parity(FL[2] & 0xff)) goto L47b779;  // @13_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @14_47b290
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @15_47b290
  if (FL[0] == FL[1]) goto L47b779;  // @16_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @17_47b290
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(4096));  // @18_47b290
  if (FL[2] == 0) goto L47b779;  // @19_47b290
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_47b290
  eax = (u32)(EBP - 16);  // @21_47b290
  PV[0] = (u32)(eax);  // @22_47b290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 928)))(ecx, PV[0]);  // @23_47b290
  ecx = edx = 0;  // @24_47b290
  PV[1] = (u32)(eax);  // @25_47b290
  ecx = edi;  // @26_47b290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 920)))(ecx, PV[1]);  // @27_47b290
  ecx = edx = 0;  // @28_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_47b290
  ecx = (u32)(EBP - 16);  // @30_47b290
  PV[2] = (u32)(ecx);  // @31_47b290
  ecx = edi;  // @32_47b290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[2]);  // @33_47b290
  ecx = edx = 0;  // @34_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @35_47b290
  X0[1] = 0;  // @36_47b290
  X0[2] = 0;  // @37_47b290
  X0[3] = 0;  // @38_47b290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @39_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_47b290
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @41_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @44_47b290
  ecx = edx = 0;  // @45_47b290
  ecx = (u32)(EBP - 40);  // @46_47b290
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @47_47b290
  PV[3] = (u32)(ecx);  // @48_47b290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @49_47b290
  ecx = eax;  // @50_47b290
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6838796), PV[3]);  // @51_47b290
  ecx = edx = 0;  // @52_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_47b290
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @54_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_47b290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @57_47b290
  ecx = edx = 0;  // @58_47b290
  esi = eax;  // @59_47b290
  eax = (u32)(EBP - 16);  // @60_47b290
  PV[5] = (u32)(eax);  // @61_47b290
  ecx = esi;  // @62_47b290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_47b290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[5]);  // @64_47b290
  ecx = edx = 0;  // @65_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @66_47b290
  X0[1] = 0;  // @67_47b290
  X0[2] = 0;  // @68_47b290
  X0[3] = 0;  // @69_47b290
  X1[0] = 0;  // @70_47b290
  X1[1] = 0;  // @71_47b290
  X1[2] = 0;  // @72_47b290
  X1[3] = 0;  // @73_47b290
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47b778;  // @74_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_47b290
  ecx = (u32)(EBP - 32);  // @76_47b290
  PV[6] = (u32)(ecx);  // @77_47b290
  ecx = esi;  // @78_47b290
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[6]);  // @79_47b290
  ecx = edx = 0;  // @80_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; });  // @81_47b290
  X0[1] = 0;  // @82_47b290
  X0[2] = 0;  // @83_47b290
  X0[3] = 0;  // @84_47b290
  ecx = esi;  // @85_47b290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @86_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @87_47b290
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @88_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 584), sizeof v); (u32)v; });  // @89_47b290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @90_47b290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @91_47b290
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @92_47b290
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @93_47b290
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @94_47b290
  ecx = edx = 0;  // @95_47b290
  __asm__ volatile("fdivrs %0" :: "m"(*(float *)(u32)(EBP - 20)) : "st");  // @96_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @98_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_47b290
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; });  // @100_47b290
  X2[1] = 0;  // @101_47b290
  X2[2] = 0;  // @102_47b290
  X2[3] = 0;  // @103_47b290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @104_47b290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @105_47b290
  X1[1] = 0;  // @106_47b290
  X1[2] = 0;  // @107_47b290
  X1[3] = 0;  // @108_47b290
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @109_47b290
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @110_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @111_47b290
  X0[1] = 0;  // @112_47b290
  X0[2] = 0;  // @113_47b290
  X0[3] = 0;  // @114_47b290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 64) + 0), 4); v; })));  // @115_47b290
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @116_47b290
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 44)) :: "st");  // @117_47b290
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @118_47b290
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })));  // @119_47b290
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @120_47b290
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X2[0], 4);  // @121_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @122_47b290
  ecx = edx = 0;  // @123_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @124_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @125_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @126_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @127_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @128_47b290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; })));  // @129_47b290
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @130_47b290
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @131_47b290
  __builtin_memcpy((void *)((u32)(EBP - 56) + 4), &X0[1], 4);  // @132_47b290
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 56)) : "st");  // @133_47b290
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[7] = (u32)v_; PV[8] = (u32)(v_ >> 32); }  // @134_47b290
  eax = ext_634da6_cdecl2(PV[7], PV[8]);  // @135_47b290
    // @136_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_47b290
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 68)) :: "st");  // @138_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @139_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 240)))(ecx);  // @141_47b290
  ecx = edx = 0;  // @142_47b290
  FL[1] = eax;  // @143_47b290
  eax = (0u - eax);  // @144_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @145_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @146_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @147_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @148_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @149_47b290
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })));  // @150_47b290
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @151_47b290
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @152_47b290
  __builtin_memcpy((void *)((u32)(EBP - 56) + 4), &X0[1], 4);  // @153_47b290
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 56)) : "st");  // @154_47b290
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[9] = (u32)v_; PV[10] = (u32)(v_ >> 32); }  // @155_47b290
  eax = ext_634da6_cdecl2(PV[9], PV[10]);  // @156_47b290
    // @157_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @158_47b290
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 64)) :: "st");  // @159_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @160_47b290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @161_47b290
  FL[2] = (edx & edx);  // @162_47b290
  if (FL[2] == 0) goto L47b586;  // @163_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @164_47b290
  esi = (u32)(EBP - 48);  // @165_47b290
  PV[11] = (u32)(esi);  // @166_47b290
  esi = (u32)(EBP - 52);  // @167_47b290
  PV[12] = (u32)(esi);  // @168_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_47b290
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @170_47b290
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 156)))(ecx, PV[13], PV[12], PV[11]);  // @171_47b290
  ecx = edx = 0;  // @172_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @173_47b290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @174_47b290
  X1[1] = 0;  // @175_47b290
  X1[2] = 0;  // @176_47b290
  X1[3] = 0;  // @177_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @178_47b290
  X0[1] = 0;  // @179_47b290
  X0[2] = 0;  // @180_47b290
  X0[3] = 0;  // @181_47b290
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @182_47b290
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @183_47b290
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @184_47b290
  if (FL[0] == FL[1]) goto L47b4e6;  // @185_47b290
  edx = (u32)(ecx + 1);  // @186_47b290
  L47b4c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @188_47b290
  ecx = (ecx + 1);  // @189_47b290
  FL[3] = ecx;  // @190_47b290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @191_47b290
  if (FL[2] != 0) goto L47b4c0;  // @192_47b290
  ecx = (ecx - edx);  // @193_47b290
  FL[3] = ecx;  // @194_47b290
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @195_47b290
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @196_47b290
  ecx = (ecx >> (u32)(31));  // @197_47b290
  FL[3] = ecx;  // @198_47b290
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 4), 4); v; })));  // @199_47b290
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @200_47b290
  X0[0] = 0;  // @201_47b290
  X0[1] = 0;  // @202_47b290
  X0[2] = 0;  // @203_47b290
  X0[3] = 0;  // @204_47b290
  goto L47b4ec;  // @205_47b290
  L47b4e6:;
  X0[0] = 0;  // @207_47b290
  X0[1] = 0;  // @208_47b290
  X0[2] = 0;  // @209_47b290
  X0[3] = 0;  // @210_47b290
  X2[0] = X0[0];  // @211_47b290
  X2[1] = X0[1];  // @212_47b290
  X2[2] = X0[2];  // @213_47b290
  X2[3] = X0[3];  // @214_47b290
  L47b4ec:;
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @216_47b290
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @217_47b290
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X1[0], 4);  // @218_47b290
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L47b59a;  // @219_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @220_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @221_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @223_47b290
  ecx = edx = 0;  // @224_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @225_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @226_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @227_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @228_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @229_47b290
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; }))))))) goto L47b59a;  // @230_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @231_47b290
  X0[1] = 0;  // @232_47b290
  X0[2] = 0;  // @233_47b290
  X0[3] = 0;  // @234_47b290
  X1[0] = 0;  // @235_47b290
  X1[1] = 0;  // @236_47b290
  X1[2] = 0;  // @237_47b290
  X1[3] = 0;  // @238_47b290
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L47b59a;  // @239_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @240_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @241_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @242_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @243_47b290
  ecx = edx = 0;  // @244_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @245_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @246_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @247_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @248_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @249_47b290
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; }))))))) goto L47b59a;  // @250_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @251_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @252_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @253_47b290
  ecx = edx = 0;  // @254_47b290
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @255_47b290
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @256_47b290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @257_47b290
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @258_47b290
  PV[16] = (u32)(ecx);  // @259_47b290
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @260_47b290
  PV[17] = (u32)(ecx);  // @261_47b290
  PV[18] = (u32)(eax);  // @262_47b290
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[18], PV[17], PV[16], (u32)(6859272), PV[15], PV[14]);  // @263_47b290
  ecx = edx = 0;  // @264_47b290
  goto L47b59a;  // @265_47b290
  L47b586:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @267_47b290
  X0[1] = 0;  // @268_47b290
  X0[2] = 0;  // @269_47b290
  X0[3] = 0;  // @270_47b290
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @271_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @272_47b290
  X0[1] = 0;  // @273_47b290
  X0[2] = 0;  // @274_47b290
  X0[3] = 0;  // @275_47b290
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @276_47b290
  L47b59a:;
  ebx = (u32)(edi + 1042);  // @278_47b290
  ecx = ebx;  // @279_47b290
  eax = ext_4cc5f0_thiscall1(ecx);  // @280_47b290
  ecx = edx = 0;  // @281_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @282_47b290
  X0[1] = 0;  // @283_47b290
  X0[2] = 0;  // @284_47b290
  X0[3] = 0;  // @285_47b290
  FL[2] = (eax & eax);  // @286_47b290
  if (FL[2] == 0) goto L47b69d;  // @287_47b290
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @288_47b290
  ecx = ebx;  // @289_47b290
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @290_47b290
  eax = ext_4cc1d0_thiscall1(ecx);  // @291_47b290
    // @292_47b290
  edx = (u32)(eax + 1);  // @293_47b290
  L47b5d0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @295_47b290
  eax = (eax + 1);  // @296_47b290
  FL[3] = eax;  // @297_47b290
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @298_47b290
  if (FL[2] != 0) goto L47b5d0;  // @299_47b290
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @300_47b290
  X3[1] = 0;  // @301_47b290
  X3[2] = 0;  // @302_47b290
  X3[3] = 0;  // @303_47b290
  eax = (eax - edx);  // @304_47b290
  FL[3] = eax;  // @305_47b290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @306_47b290
  X1[1] = 0;  // @307_47b290
  X1[2] = 0;  // @308_47b290
  X1[3] = 0;  // @309_47b290
  X2[0] = 0;  // @310_47b290
  X2[1] = 0;  // @311_47b290
  X2[2] = 0;  // @312_47b290
  X2[3] = 0;  // @313_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @314_47b290
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @315_47b290
  eax = (eax >> (u32)(31));  // @316_47b290
  FL[3] = eax;  // @317_47b290
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @318_47b290
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @319_47b290
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @320_47b290
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @321_47b290
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @322_47b290
  if ((!(U2F(X1[0]) >= U2F(X2[0])))) goto L47b78a;  // @323_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @324_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @325_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @326_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @327_47b290
  ecx = edx = 0;  // @328_47b290
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @329_47b290
  X1[1] = 0;  // @330_47b290
  X1[2] = 0;  // @331_47b290
  X1[3] = 0;  // @332_47b290
  X2[0] = 0;  // @333_47b290
  X2[1] = 0;  // @334_47b290
  X2[2] = 0;  // @335_47b290
  X2[3] = 0;  // @336_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @337_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @338_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @339_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @340_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @341_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @342_47b290
  X0[1] = 0;  // @343_47b290
  X0[2] = 0;  // @344_47b290
  X0[3] = 0;  // @345_47b290
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47b6a5;  // @346_47b290
  if ((!(U2F(X0[0]) >= U2F(X2[0])))) goto L47b6a5;  // @347_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @348_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @349_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @351_47b290
  ecx = edx = 0;  // @352_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @353_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @354_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @355_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @356_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @357_47b290
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))))))) goto L47b698;  // @358_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @359_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @360_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @361_47b290
  ecx = edx = 0;  // @362_47b290
  esi = eax;  // @363_47b290
  ecx = ebx;  // @364_47b290
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @365_47b290
  eax = ext_4cc1d0_thiscall1(ecx);  // @366_47b290
    // @367_47b290
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @368_47b290
  PV[19] = (u32)(eax);  // @369_47b290
  PV[20] = (u32)(ecx);  // @370_47b290
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @371_47b290
  PV[21] = (u32)(ecx);  // @372_47b290
  PV[22] = (u32)(esi);  // @373_47b290
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 388)))(PV[22], PV[21], PV[20], PV[19]);  // @374_47b290
  ecx = edx = 0;  // @375_47b290
  L47b698:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @377_47b290
  X0[1] = 0;  // @378_47b290
  X0[2] = 0;  // @379_47b290
  X0[3] = 0;  // @380_47b290
  L47b69d:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @382_47b290
  X1[1] = 0;  // @383_47b290
  X1[2] = 0;  // @384_47b290
  X1[3] = 0;  // @385_47b290
  X2[0] = 0;  // @386_47b290
  X2[1] = 0;  // @387_47b290
  X2[2] = 0;  // @388_47b290
  X2[3] = 0;  // @389_47b290
  L47b6a5:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @391_47b290
  X3[1] = 0;  // @392_47b290
  X3[2] = 0;  // @393_47b290
  X3[3] = 0;  // @394_47b290
  L47b6ad:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @396_47b290
  FL[2] = (ebx & ebx);  // @397_47b290
  if (FL[2] == 0) goto L47b777;  // @398_47b290
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @399_47b290
  ecx = ebx;  // @400_47b290
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @401_47b290
  edx = (u32)(ecx + 1);  // @402_47b290
  L47b6d0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @404_47b290
  ecx = (ecx + 1);  // @405_47b290
  FL[3] = ecx;  // @406_47b290
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @407_47b290
  if (FL[2] != 0) goto L47b6d0;  // @408_47b290
  ecx = (ecx - edx);  // @409_47b290
  FL[3] = ecx;  // @410_47b290
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @411_47b290
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @412_47b290
  ecx = (ecx >> (u32)(31));  // @413_47b290
  FL[3] = ecx;  // @414_47b290
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 4), 4); v; })));  // @415_47b290
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @416_47b290
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @417_47b290
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @418_47b290
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X1[0], 4);  // @419_47b290
  if ((!(U2F(X1[0]) >= U2F(X2[0])))) goto L47b777;  // @420_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @421_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @422_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @423_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @424_47b290
  ecx = edx = 0;  // @425_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @426_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @427_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @428_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @429_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @430_47b290
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; }))))))) goto L47b777;  // @431_47b290
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @432_47b290
  X0[1] = 0;  // @433_47b290
  X0[2] = 0;  // @434_47b290
  X0[3] = 0;  // @435_47b290
  X1[0] = 0;  // @436_47b290
  X1[1] = 0;  // @437_47b290
  X1[2] = 0;  // @438_47b290
  X1[3] = 0;  // @439_47b290
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L47b777;  // @440_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @441_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @442_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @443_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @444_47b290
  ecx = edx = 0;  // @445_47b290
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @446_47b290
  X0[0] = F2U((float)(s32)X0[0]);  // @447_47b290
  X0[1] = F2U((float)(s32)X0[1]);  // @448_47b290
  X0[2] = F2U((float)(s32)X0[2]);  // @449_47b290
  X0[3] = F2U((float)(s32)X0[3]);  // @450_47b290
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))))))) goto L47b777;  // @451_47b290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @452_47b290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @453_47b290
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @454_47b290
  ecx = edx = 0;  // @455_47b290
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @456_47b290
  PV[23] = (u32)(ebx);  // @457_47b290
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @458_47b290
  PV[24] = (u32)(ecx);  // @459_47b290
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @460_47b290
  PV[25] = (u32)(ecx);  // @461_47b290
  PV[26] = (u32)(eax);  // @462_47b290
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[26], PV[25], PV[24], PV[23]);  // @463_47b290
  ecx = edx = 0;  // @464_47b290
  L47b777:;
  L47b778:;
  L47b779:;
  ext_633654(G(u32, 0x6f5630));  // @468_47b290
  return eax;  // @469_47b290
  L47b78a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @471_47b290
  X0[1] = 0;  // @472_47b290
  X0[2] = 0;  // @473_47b290
  X0[3] = 0;  // @474_47b290
  goto L47b6ad;  // @475_47b290
}
PCREG(47b290, lifted_47b290);

