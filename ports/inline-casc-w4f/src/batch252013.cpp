// batch252013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de440_fastcall3(u32, u32, u32) __asm__("ext_4de440");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4f3ab0_thiscall1(u32) __asm__("ext_4f3ab0");
extern "C" u32 THISCALL ext_5359f0_thiscall3(u32, u32, u32) __asm__("ext_5359f0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_63fea0(u32 ecx_in, u32 a0) {
  u8 F[0x610] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x510);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
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

extern "C" u32 THISCALL lifted_536990(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ecx;  // @0_536990
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 56) + 12), &v, sizeof v); }  // @1_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_536990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @3_536990
  ecx = edx = 0;  // @4_536990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_536990
  ecx = esi;  // @6_536990
  PV[0] = (u32)(eax);  // @7_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 544)))(ecx, PV[0]);  // @8_536990
  ecx = edx = 0;  // @9_536990
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_536990
  edx = eax;  // @11_536990
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @12_536990
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 56) + 16), &v, sizeof v); }  // @13_536990
  FL[2] = (ebx & ebx);  // @14_536990
  if (FL[2] == 0) goto L536bbc;  // @15_536990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_536990
  eax = (u32)((EBP - 56) + 32);  // @17_536990
  PV[1] = (u32)(eax);  // @18_536990
  ecx = ebx;  // @19_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[1]);  // @20_536990
  ecx = edx = 0;  // @21_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @22_536990
  ecx = (u32)((EBP - 56) + 32);  // @23_536990
  PV[2] = (u32)(ecx);  // @24_536990
  ecx = ebx;  // @25_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @26_536990
  ecx = edx = 0;  // @27_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @28_536990
  ebx = eax;  // @29_536990
  if (FL[0] == FL[1]) goto L536bb8;  // @30_536990
  L5369f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_536990
  PV[3] = (u32)(ebx);  // @33_536990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[3]);  // @36_536990
  ecx = edx = 0;  // @37_536990
  esi = eax;  // @38_536990
  FL[2] = (esi & esi);  // @39_536990
  if (FL[2] == 0) goto L536b9a;  // @40_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(11);  // @41_536990
  if (FL[0] == FL[1]) goto L536b9a;  // @42_536990
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(16));  // @43_536990
  if (FL[2] == 0) goto L536a91;  // @44_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 12), sizeof v); (u32)v; });  // @45_536990
  edx = (u32)(esi + 212);  // @46_536990
  eax = (eax + (u32)(110));  // @47_536990
  FL[3] = eax;  // @48_536990
  ecx = (u32)((EBP - 56) + 20);  // @49_536990
  PV[4] = (u32)(eax);  // @50_536990
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @51_536990
  ecx = edx = 0;  // @52_536990
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 20) + 0), 4); v; });  // @53_536990
  X1[1] = 0;  // @54_536990
  X1[2] = 0;  // @55_536990
  X1[3] = 0;  // @56_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; });  // @57_536990
  X0[1] = 0;  // @58_536990
  X0[2] = 0;  // @59_536990
  X0[3] = 0;  // @60_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @61_536990
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @62_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @63_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 28) + 0), 4); v; });  // @64_536990
  X0[1] = 0;  // @65_536990
  X0[2] = 0;  // @66_536990
  X0[3] = 0;  // @67_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @68_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @69_536990
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @70_536990
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @71_536990
  ecx = edx = 0;  // @72_536990
  X1[0] = 0;  // @73_536990
  X1[1] = 0;  // @74_536990
  X1[2] = 0;  // @75_536990
  X1[3] = 0;  // @76_536990
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(4294967279))); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @77_536990
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @78_536990
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @79_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; });  // @80_536990
  X0[1] = 0;  // @81_536990
  X0[2] = 0;  // @82_536990
  X0[3] = 0;  // @83_536990
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956272) + 0), 4); v; })));  // @84_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; })));  // @85_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @86_536990
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; })));  // @87_536990
  __builtin_memcpy((void *)((u32)(esi + 120) + 0), &X1[0], 4);  // @88_536990
  L536a91:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; });  // @90_536990
  X0[1] = 0;  // @91_536990
  X0[2] = 0;  // @92_536990
  X0[3] = 0;  // @93_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @94_536990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @95_536990
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @96_536990
  ecx = (ecx - eax);  // @97_536990
  FL[3] = ecx;  // @98_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = ecx;  // @100_536990
  if ((s32)FL[0] >= (s32)FL[1]) goto L536abd;  // @101_536990
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @102_536990
  goto L536b9a;  // @103_536990
  L536abd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @105_536990
  FL[0] = eax; FL[1] = (u32)(2);  // @106_536990
  if (FL[0] == FL[1]) goto L536aca;  // @107_536990
  FL[0] = eax; FL[1] = (u32)(10);  // @108_536990
  if (FL[0] != FL[1]) goto L536ad1;  // @109_536990
  L536aca:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @111_536990
  L536ad1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @113_536990
  FL[0] = eax; FL[1] = (u32)(4);  // @114_536990
  if (FL[0] == FL[1]) goto L536b91;  // @115_536990
  FL[0] = eax; FL[1] = (u32)(5);  // @116_536990
  if (FL[0] == FL[1]) goto L536b91;  // @117_536990
  FL[0] = eax; FL[1] = (u32)(8);  // @118_536990
  if (FL[0] == FL[1]) goto L536b91;  // @119_536990
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 16), sizeof v); (u32)v; });  // @120_536990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 60) + 16), sizeof v); (u32)v; });  // @121_536990
  PV[6] = (u32)(esi);  // @122_536990
  eax = ext_5359f0_thiscall3(ecx, PV[6], PV[5]);  // @123_536990
  ecx = edx = 0;  // @124_536990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @125_536990
  if (FL[2] == 0) goto L536b85;  // @126_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @127_536990
  if (FL[0] == FL[1]) goto L536b14;  // @128_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @129_536990
  ecx = edi;  // @130_536990
  goto L536b96;  // @131_536990
  L536b14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 12), sizeof v); (u32)v; });  // @133_536990
  edx = (u32)(esi + 212);  // @134_536990
  eax = (eax + (u32)(110));  // @135_536990
  FL[3] = eax;  // @136_536990
  ecx = (u32)((EBP - 56) + 44);  // @137_536990
  PV[7] = (u32)(eax);  // @138_536990
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @139_536990
  ecx = edx = 0;  // @140_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 48) + 0), 4); v; });  // @141_536990
  X0[1] = 0;  // @142_536990
  X0[2] = 0;  // @143_536990
  X0[3] = 0;  // @144_536990
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 44) + 0), 4); v; });  // @145_536990
  X1[1] = 0;  // @146_536990
  X1[2] = 0;  // @147_536990
  X1[3] = 0;  // @148_536990
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 92) + 0), 4); v; });  // @149_536990
  X2[1] = 0;  // @150_536990
  X2[2] = 0;  // @151_536990
  X2[3] = 0;  // @152_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @153_536990
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @154_536990
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @155_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @156_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 52) + 0), 4); v; });  // @157_536990
  X0[1] = 0;  // @158_536990
  X0[2] = 0;  // @159_536990
  X0[3] = 0;  // @160_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @161_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @162_536990
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @163_536990
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L536b75;  // @164_536990
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(1));  // @165_536990
  PV[8] = (u32)(ebx);  // @166_536990
  if (FL[2] == 0) goto L536b6f;  // @167_536990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @168_536990
  ecx = esi;  // @169_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @170_536990
  goto L536b97;  // @171_536990
  L536b6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @173_536990
  ecx = edi;  // @174_536990
  goto L536b97;  // @175_536990
  L536b75:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @177_536990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @178_536990
  ecx = esi;  // @179_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @180_536990
  goto L536b96;  // @181_536990
  L536b85:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @183_536990
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @184_536990
  goto L536b94;  // @185_536990
  L536b91:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @187_536990
  L536b94:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_536990
  L536b96:;
  PV[9] = (u32)(ebx);  // @191_536990
  L536b97:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ebx);  // @193_536990
  ecx = edx = 0;  // @194_536990
  L536b9a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @196_536990
  edx = (u32)((EBP - 56) + 32);  // @197_536990
  PV[10] = (u32)(edx);  // @198_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[10]);  // @200_536990
  ecx = edx = 0;  // @201_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @202_536990
  ebx = eax;  // @203_536990
  if (FL[0] != FL[1]) goto L5369f0;  // @204_536990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 12), sizeof v); (u32)v; });  // @205_536990
  L536bb8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 16), sizeof v); (u32)v; });  // @207_536990
  L536bbc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @209_536990
  FL[2] = (ecx & ecx);  // @210_536990
  if (FL[2] == 0) goto L536bd9;  // @211_536990
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @212_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_536990
  PV[12] = (u32)(edi);  // @214_536990
  PV[13] = (u32)(edx);  // @215_536990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[13], PV[12], PV[11]);  // @216_536990
  ecx = edx = 0;  // @217_536990
  return eax;  // @218_536990
  L536bd9:;
  FL[2] = (edi & edi);  // @220_536990
  if (FL[2] == 0) goto L536c2c;  // @221_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @222_536990
  ecx = (u32)((EBP - 56) + 20);  // @223_536990
  PV[14] = (u32)(ecx);  // @224_536990
  ecx = edi;  // @225_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @226_536990
  ecx = edx = 0;  // @227_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @228_536990
  ecx = (u32)((EBP - 56) + 20);  // @229_536990
  PV[15] = (u32)(ecx);  // @230_536990
  ecx = edi;  // @231_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @232_536990
  ecx = edx = 0;  // @233_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @234_536990
  ecx = eax;  // @235_536990
  if (FL[0] == FL[1]) goto L536c2c;  // @236_536990
  L536c00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @238_536990
  PV[16] = (u32)(ecx);  // @239_536990
  ecx = eax;  // @240_536990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @241_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[16]);  // @242_536990
  ecx = edx = 0;  // @243_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @244_536990
  ecx = (u32)((EBP - 56) + 20);  // @245_536990
  PV[17] = (u32)(ecx);  // @246_536990
  ecx = edi;  // @247_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[17]);  // @248_536990
  ecx = edx = 0;  // @249_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @250_536990
  ecx = (u32)((EBP - 56) + 20);  // @251_536990
  PV[18] = (u32)(ecx);  // @252_536990
  ecx = edi;  // @253_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[18]);  // @254_536990
  ecx = edx = 0;  // @255_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @256_536990
  ecx = eax;  // @257_536990
  if (FL[0] != FL[1]) goto L536c00;  // @258_536990
  L536c2c:;
  return eax;  // @260_536990
}
PCREG(536990, lifted_536990);

extern "C" u32 THISCALL lifted_4f1d60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  edi = ecx;  // @0_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @2_4f1d60
  ecx = edx = 0;  // @3_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_4f1d60
  ecx = edi;  // @5_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 728)))(ecx);  // @6_4f1d60
  ecx = edx = 0;  // @7_4f1d60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1530), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_4f1d60
  if (FL[0] == FL[1]) goto L4f1fe4;  // @9_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_4f1d60
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 419), sizeof v); (u32)v; });  // @11_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @14_4f1d60
  ecx = edx = 0;  // @15_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_4f1d60
  esi = eax;  // @17_4f1d60
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 415), sizeof v); (u32)v; });  // @18_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[1]);  // @21_4f1d60
  ecx = edx = 0;  // @22_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @23_4f1d60
  FL[2] = (esi & esi);  // @24_4f1d60
  if (FL[2] == 0) goto L4f1de5;  // @25_4f1d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 123) + 0), 4); v; });  // @26_4f1d60
  X0[1] = 0;  // @27_4f1d60
  X0[2] = 0;  // @28_4f1d60
  X0[3] = 0;  // @29_4f1d60
  PV[2] = (u32)(esi);  // @30_4f1d60
  PV[3] = (u32)(ecx);  // @31_4f1d60
  ecx = 0;  // @32_4f1d60
  PV[4] = (u32)(ecx);  // @33_4f1d60
  eax = 0;  // @34_4f1d60
  PV[5] = X0[0];  // @35_4f1d60
  ecx = edi;  // @36_4f1d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 119) + 0), 4); v; });  // @37_4f1d60
  X0[1] = 0;  // @38_4f1d60
  X0[2] = 0;  // @39_4f1d60
  X0[3] = 0;  // @40_4f1d60
  PV[6] = X0[0];  // @41_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_4f1d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 732)))(ecx, (u32)(2), PV[6], PV[5], PV[2]);  // @43_4f1d60
  ecx = edx = 0;  // @44_4f1d60
  L4f1de5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4f1d60
  ecx = edi;  // @47_4f1d60
  ebx = 0;  // @48_4f1d60
  FL[3] = ebx;  // @49_4f1d60
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2576), sizeof v); (u32)v; })) & 0xff);  // @50_4f1d60
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @51_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 784)))(ecx);  // @53_4f1d60
  ecx = edx = 0;  // @54_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4f1d60
  PV[7] = (u32)(eax);  // @56_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @57_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @58_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[7]);  // @60_4f1d60
  ecx = edx = 0;  // @61_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @62_4f1d60
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 467), &v, sizeof v); }  // @63_4f1d60
  FL[2] = (eax & eax);  // @64_4f1d60
  if (FL[2] == 0) goto L4f1e58;  // @65_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @66_4f1d60
  ecx = eax;  // @67_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @68_4f1d60
  ecx = edx = 0;  // @69_4f1d60
  FL[2] = (eax & eax);  // @70_4f1d60
  if (FL[2] == 0) goto L4f1e58;  // @71_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @72_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @74_4f1d60
  ecx = edx = 0;  // @75_4f1d60
  ecx = eax;  // @76_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @77_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @78_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @79_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2148532274));  // @80_4f1d60
  ecx = edx = 0;  // @81_4f1d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @82_4f1d60
  if (FL[2] == 0) goto L4f1e58;  // @83_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @84_4f1d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @85_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 467), &v, sizeof v); }  // @86_4f1d60
  L4f1e58:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }); FL[1] = (u32)(128);  // @88_4f1d60
  if (FL[0] < FL[1]) goto L4f1ef5;  // @89_4f1d60
  FL[2] = (ebx & ebx);  // @90_4f1d60
  if (FL[2] == 0) goto L4f1ed1;  // @91_4f1d60
  FL[2] = (esi & esi);  // @92_4f1d60
  if (FL[2] != 0) goto L4f1ea2;  // @93_4f1d60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1527), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_4f1d60
  if (FL[0] != FL[1]) goto L4f1ea2;  // @95_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_4f1d60
  ecx = ebx;  // @97_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 768)))(ecx, (u32)(1));  // @98_4f1d60
  ecx = edx = 0;  // @99_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4f1d60
  PV[8] = (u32)(ebx);  // @101_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @104_4f1d60
  ecx = edx = 0;  // @105_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 419), &v, sizeof v); }  // @106_4f1d60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @107_4f1d60
  goto L4f1fe4;  // @108_4f1d60
  L4f1ea2:;
  FL[0] = esi; FL[1] = ebx;  // @110_4f1d60
  if (FL[0] != FL[1]) goto L4f1eb2;  // @111_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @112_4f1d60
  ecx = ebx;  // @113_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 768)))(ecx, (u32)(0));  // @114_4f1d60
  ecx = edx = 0;  // @115_4f1d60
  L4f1eb2:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); FL[1] = esi;  // @117_4f1d60
  if (FL[0] == FL[1]) goto L4f1ee9;  // @118_4f1d60
  FL[2] = (esi & esi);  // @119_4f1d60
  if (FL[2] == 0) goto L4f1ee9;  // @120_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_4f1d60
  ecx = esi;  // @122_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @123_4f1d60
  ecx = edx = 0;  // @124_4f1d60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @125_4f1d60
  goto L4f1fe4;  // @126_4f1d60
  L4f1ed1:;
  FL[2] = (esi & esi);  // @128_4f1d60
  if (FL[2] == 0) goto L4f1edf;  // @129_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_4f1d60
  ecx = esi;  // @131_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @132_4f1d60
  ecx = edx = 0;  // @133_4f1d60
  L4f1edf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 415), &v, sizeof v); }  // @135_4f1d60
  L4f1ee9:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @137_4f1d60
  goto L4f1fe4;  // @138_4f1d60
  L4f1ef5:;
  FL[2] = (ebx & ebx);  // @140_4f1d60
  if (FL[2] == 0) goto L4f1fac;  // @141_4f1d60
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @142_4f1d60
  if (FL[0] == FL[1]) goto L4f1f1f;  // @143_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @144_4f1d60
  ecx = ebx;  // @145_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 764)))(ecx, (u32)(0));  // @146_4f1d60
  ecx = edx = 0;  // @147_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @148_4f1d60
  FL[2] = (ecx & ecx);  // @149_4f1d60
  if (FL[2] == 0) goto L4f1f8f;  // @150_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @152_4f1d60
  ecx = edx = 0;  // @153_4f1d60
  goto L4f1f8f;  // @154_4f1d60
  L4f1f1f:;
  FL[0] = ebx; FL[1] = esi;  // @156_4f1d60
  if (FL[0] != FL[1]) goto L4f1f8f;  // @157_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @158_4f1d60
  ecx = ebx;  // @159_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 772)))(ecx);  // @160_4f1d60
  ecx = edx = 0;  // @161_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @162_4f1d60
  ecx = ebx;  // @163_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 764)))(ecx, (u32)(1));  // @164_4f1d60
  ecx = edx = 0;  // @165_4f1d60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 419), &v, sizeof v); }  // @166_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @167_4f1d60
  PV[9] = (u32)(ebx);  // @168_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @169_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[9]);  // @171_4f1d60
  ecx = edx = 0;  // @172_4f1d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 123) + 0), 4); v; });  // @173_4f1d60
  X0[1] = 0;  // @174_4f1d60
  X0[2] = 0;  // @175_4f1d60
  X0[3] = 0;  // @176_4f1d60
  esi = eax;  // @177_4f1d60
  PV[10] = (u32)(ebx);  // @178_4f1d60
  PV[11] = (u32)(ecx);  // @179_4f1d60
  ecx = 0;  // @180_4f1d60
  PV[12] = (u32)(ecx);  // @181_4f1d60
  PV[13] = X0[0];  // @182_4f1d60
  ecx = 0;  // @183_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 119), sizeof v); (u32)v; });  // @184_4f1d60
  PV[14] = eax;  // @185_4f1d60
  ecx = edi;  // @186_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @187_4f1d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 732)))(ecx, (u32)(128), PV[14], PV[13], PV[10]);  // @188_4f1d60
  ecx = edx = 0;  // @189_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @190_4f1d60
  PV[15] = (u32)(esi);  // @191_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @192_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @193_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @194_4f1d60
  ecx = edx = 0;  // @195_4f1d60
  ebx = eax;  // @196_4f1d60
  esi = 0;  // @197_4f1d60
  FL[3] = esi;  // @198_4f1d60
  L4f1f8f:;
  FL[2] = (ebx & ebx);  // @200_4f1d60
  if (FL[2] == 0) goto L4f1fbb;  // @201_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @202_4f1d60
  PV[16] = (u32)(ebx);  // @203_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @204_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @205_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[16]);  // @206_4f1d60
  ecx = edx = 0;  // @207_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 415), &v, sizeof v); }  // @208_4f1d60
  goto L4f1fc5;  // @209_4f1d60
  L4f1fac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @211_4f1d60
  FL[2] = (ecx & ecx);  // @212_4f1d60
  if (FL[2] == 0) goto L4f1fc5;  // @213_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @215_4f1d60
  ecx = edx = 0;  // @216_4f1d60
  L4f1fbb:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 415), &v, sizeof v); }  // @218_4f1d60
  L4f1fc5:;
  FL[2] = (esi & esi);  // @220_4f1d60
  if (FL[2] == 0) goto L4f1fd3;  // @221_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @222_4f1d60
  ecx = esi;  // @223_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @224_4f1d60
  ecx = edx = 0;  // @225_4f1d60
  L4f1fd3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 419), &v, sizeof v); }  // @227_4f1d60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @228_4f1d60
  L4f1fe4:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @230_4f1d60
  if (FL[0] == FL[1]) goto L4f1ff1;  // @231_4f1d60
  ecx = edi;  // @232_4f1d60
  eax = ext_4f3ab0_thiscall1(ecx);  // @233_4f1d60
  ecx = edx = 0;  // @234_4f1d60
  L4f1ff1:;
  return eax;  // @236_4f1d60
}
PCREG(4f1d60, lifted_4f1d60);

