// batch242032.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_457840_thiscall2(u32, u32) __asm__("ext_457840");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4587d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  edi = ecx;  // @0_4587d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 64) + 44), &v, sizeof v); }  // @1_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @2_4587d0
  FL[2] = (eax & eax);  // @3_4587d0
  if (FL[2] == 0) goto L4587ff;  // @4_4587d0
  PV[0] = (u32)(eax);  // @5_4587d0
  eax = ext_634273_cdecl2(PV[0], (u32)(112));  // @6_4587d0
  ecx = edx = 0;  // @7_4587d0
  L4587ff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_4587d0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @10_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4587d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @13_4587d0
  ecx = edx = 0;  // @14_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @15_4587d0
  ecx = 0;  // @16_4587d0
  FL[3] = ecx;  // @17_4587d0
  esi = (u32)(112);  // @18_4587d0
  { u64 p_ = (u64)eax * (u64)(u32)(esi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @19_4587d0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @20_4587d0
  FL[1] = ecx;  // @21_4587d0
  ecx = (0u - ecx);  // @22_4587d0
  ecx = (ecx | eax);  // @23_4587d0
  FL[3] = ecx;  // @24_4587d0
  PV[2] = (u32)(ecx);  // @25_4587d0
  eax = ext_41e290_cdecl1(PV[2]);  // @26_4587d0
  ecx = edx = 0;  // @27_4587d0
  ecx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }) * (s32)(u32)(112));  // @28_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @29_4587d0
  PV[3] = (u32)(ecx);  // @30_4587d0
  PV[4] = (u32)(eax);  // @31_4587d0
  eax = ext_634d10_cdecl3(PV[4], (u32)(0), PV[3]);  // @32_4587d0
    // @33_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @34_4587d0
  ecx = 0;  // @35_4587d0
  FL[3] = ecx;  // @36_4587d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @37_4587d0
  { u64 p_ = (u64)eax * (u64)(u32)(esi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @38_4587d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 80) + 36), &v, sizeof v); }  // @39_4587d0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @40_4587d0
  FL[1] = ecx;  // @41_4587d0
  ecx = (0u - ecx);  // @42_4587d0
  ecx = (ecx | eax);  // @43_4587d0
  FL[3] = ecx;  // @44_4587d0
  PV[5] = (u32)(ecx);  // @45_4587d0
  eax = ext_41e290_cdecl1(PV[5]);  // @46_4587d0
  ecx = edx = 0;  // @47_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @48_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 64) + 36), &v, sizeof v); }  // @49_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @50_4587d0
  eax = 0;  // @51_4587d0
  FL[3] = eax;  // @52_4587d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 64) + 16), &v, sizeof v); }  // @53_4587d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @54_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 64) + 40), &v, sizeof v); }  // @55_4587d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }); FL[1] = eax;  // @56_4587d0
  if (FL[0] == FL[1]) goto L458aad;  // @57_4587d0
  ecx = (u32)(edx + 44);  // @58_4587d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 64) + 12), &v, sizeof v); }  // @59_4587d0
  L458884:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2), sizeof v); (u32)v; }) & (u32)(128));  // @61_4587d0
  if (FL[2] != 0) goto L458a98;  // @62_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; });  // @63_4587d0
  esi = (u32)(ebx + 28);  // @64_4587d0
  ebx = (u32)(ecx - 8);  // @65_4587d0
  edx = esi;  // @66_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @67_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @68_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @69_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @70_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @71_4587d0
  ecx = (ecx + (u32)(40));  // @72_4587d0
  FL[3] = ecx;  // @73_4587d0
  PV[6] = (u32)(ebx);  // @74_4587d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 68) + 28), &v, sizeof v); }  // @75_4587d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[6]);  // @76_4587d0
  ecx = edx = 0;  // @77_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 12), sizeof v); (u32)v; });  // @78_4587d0
  edx = (u32)(esi + 48);  // @79_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @80_4587d0
  edi = (u32)(ecx - 20);  // @81_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @82_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @83_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 16), &v, sizeof v); }  // @84_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @85_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 12), &v, sizeof v); }  // @86_4587d0
  ecx = (ecx + (u32)(28));  // @87_4587d0
  FL[3] = ecx;  // @88_4587d0
  PV[7] = (u32)(edi);  // @89_4587d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @90_4587d0
  ecx = edx = 0;  // @91_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 12), sizeof v); (u32)v; });  // @92_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 24), sizeof v); (u32)v; });  // @93_4587d0
  esi = (u32)(ecx - 32);  // @94_4587d0
  PV[8] = (u32)(esi);  // @95_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 24), sizeof v); (u32)v; });  // @96_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @97_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @98_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 28), &v, sizeof v); }  // @99_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @100_4587d0
  edx = (edx + (u32)(12));  // @101_4587d0
  FL[3] = edx;  // @102_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 24), &v, sizeof v); }  // @103_4587d0
  ecx = (ecx + (u32)(16));  // @104_4587d0
  FL[3] = ecx;  // @105_4587d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @106_4587d0
  ecx = edx = 0;  // @107_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 24), sizeof v); (u32)v; });  // @108_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 16), sizeof v); (u32)v; });  // @109_4587d0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 16), sizeof v); (u32)v; });  // @110_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 72), sizeof v); (u32)v; });  // @111_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @112_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @113_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 76), sizeof v); (u32)v; });  // @114_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx - 40), &v, sizeof v); }  // @115_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; });  // @116_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx - 36), &v, sizeof v); }  // @117_4587d0
  edx = (u32)(ecx + 60);  // @118_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 68) + 16), sizeof v); (u32)v; });  // @119_4587d0
  ecx = (ecx + (u32)(4));  // @120_4587d0
  FL[3] = ecx;  // @121_4587d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[9]);  // @122_4587d0
  ecx = edx = 0;  // @123_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 20), sizeof v); (u32)v; });  // @124_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 16), sizeof v); (u32)v; });  // @125_4587d0
  eax = (eax + (u32)(16));  // @126_4587d0
  FL[3] = eax;  // @127_4587d0
  edx = eax;  // @128_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 64) + 28), &v, sizeof v); }  // @129_4587d0
  eax = ext_441940_fastcall2(ecx, edx);  // @130_4587d0
  ecx = edx = 0;  // @131_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 28), sizeof v); (u32)v; });  // @132_4587d0
  ecx = esi;  // @133_4587d0
  eax = ext_441940_fastcall2(ecx, edx);  // @134_4587d0
  ecx = edx = 0;  // @135_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 28), sizeof v); (u32)v; });  // @136_4587d0
  ecx = edi;  // @137_4587d0
  eax = ext_441940_fastcall2(ecx, edx);  // @138_4587d0
  ecx = edx = 0;  // @139_4587d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 28), sizeof v); (u32)v; });  // @140_4587d0
  ecx = ebx;  // @141_4587d0
  eax = ext_441940_fastcall2(ecx, edx);  // @142_4587d0
  ecx = edx = 0;  // @143_4587d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 24), sizeof v); (u32)v; });  // @144_4587d0
  X0[0] = 0;  // @145_4587d0
  X0[1] = 0;  // @146_4587d0
  X0[2] = 0;  // @147_4587d0
  X0[3] = 0;  // @148_4587d0
  __builtin_memcpy((void *)((u32)((EBP - 64) + 32) + 0), &X0[0], 4);  // @149_4587d0
  esi = (u32)(8);  // @150_4587d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 64) + 48), &v, sizeof v); }  // @151_4587d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 64) + 52), &v, sizeof v); }  // @152_4587d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 64) + 56), &v, sizeof v); }  // @153_4587d0
  L458990:;
  edx = ebx;  // @155_4587d0
  ecx = (u32)((EBP - 64) + 48);  // @156_4587d0
  eax = ext_441940_fastcall2(ecx, edx);  // @157_4587d0
  ecx = edx = 0;  // @158_4587d0
  ebx = (ebx + (u32)(12));  // @159_4587d0
  FL[3] = ebx;  // @160_4587d0
  esi = (esi - (u32)(1));  // @161_4587d0
  FL[3] = esi;  // @162_4587d0
  if (FL[3] != 0) goto L458990;  // @163_4587d0
  PV[10] = (u32)(ecx);  // @164_4587d0
  ecx = (u32)((EBP - 68) + 52);  // @165_4587d0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1040187392));  // @166_4587d0
    // @167_4587d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 20), sizeof v); (u32)v; });  // @168_4587d0
  edi = (u32)(8);  // @169_4587d0
  esi = (u32)(ebx + 28);  // @170_4587d0
  L4589c0:;
  edx = (u32)((EBP - 64) + 48);  // @172_4587d0
  ecx = esi;  // @173_4587d0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @174_4587d0
  ecx = edx = 0;  // @175_4587d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @176_4587d0
  X1[1] = 0;  // @177_4587d0
  X1[2] = 0;  // @178_4587d0
  X1[3] = 0;  // @179_4587d0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @180_4587d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @181_4587d0
  X2[1] = 0;  // @182_4587d0
  X2[2] = 0;  // @183_4587d0
  X2[3] = 0;  // @184_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @185_4587d0
  X0[1] = 0;  // @186_4587d0
  X0[2] = 0;  // @187_4587d0
  X0[3] = 0;  // @188_4587d0
  esi = (esi + (u32)(12));  // @189_4587d0
  FL[3] = esi;  // @190_4587d0
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @191_4587d0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @192_4587d0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @193_4587d0
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @194_4587d0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @195_4587d0
  { float a_ = U2F(X2[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 64) + 32) + 0), 4); v; })); X2[0] = (a_ > b_) ? X2[0] : F2U(b_); }  // @196_4587d0
  __builtin_memcpy((void *)((u32)((EBP - 64) + 32) + 0), &X2[0], 4);  // @197_4587d0
  edi = (edi - (u32)(1));  // @198_4587d0
  FL[3] = edi;  // @199_4587d0
  if (FL[3] != 0) goto L4589c0;  // @200_4587d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 44), sizeof v); (u32)v; });  // @201_4587d0
  ecx = edi;  // @202_4587d0
  PV[11] = (u32)(ebx);  // @203_4587d0
  eax = ext_457840_thiscall2(ecx, PV[11]);  // @204_4587d0
  ecx = edx = 0;  // @205_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 28) + 0), 4); v; });  // @206_4587d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 28) + 4), 4); v; });  // @207_4587d0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 28) + 8), 4); v; });  // @208_4587d0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 28) + 12), 4); v; });  // @209_4587d0
  esi = eax;  // @210_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 28), sizeof v); (u32)v; });  // @211_4587d0
  eax = (u32)(ebx + 28);  // @212_4587d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 36), sizeof v); (u32)v; });  // @213_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 16) + 0), &X0[0], 4);  // @214_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 16) + 4), &X0[1], 4);  // @215_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 16) + 8), &X0[2], 4);  // @216_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 16) + 12), &X0[3], 4);  // @217_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 0), 4); v; });  // @218_4587d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 4), 4); v; });  // @219_4587d0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 8), 4); v; });  // @220_4587d0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 12), 4); v; });  // @221_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 32) + 0), &X0[0], 4);  // @222_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 32) + 4), &X0[1], 4);  // @223_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 32) + 8), &X0[2], 4);  // @224_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 32) + 12), &X0[3], 4);  // @225_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @226_4587d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 4), 4); v; });  // @227_4587d0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 8), 4); v; });  // @228_4587d0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 12), 4); v; });  // @229_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 48) + 0), &X0[0], 4);  // @230_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 48) + 4), &X0[1], 4);  // @231_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 48) + 8), &X0[2], 4);  // @232_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 48) + 12), &X0[3], 4);  // @233_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 0), 4); v; });  // @234_4587d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 4), 4); v; });  // @235_4587d0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 8), 4); v; });  // @236_4587d0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 12), 4); v; });  // @237_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 64) + 0), &X0[0], 4);  // @238_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 64) + 4), &X0[1], 4);  // @239_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 64) + 8), &X0[2], 4);  // @240_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 64) + 12), &X0[3], 4);  // @241_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @242_4587d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 4), 4); v; });  // @243_4587d0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 8), 4); v; });  // @244_4587d0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 12), 4); v; });  // @245_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 80) + 0), &X0[0], 4);  // @246_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 80) + 4), &X0[1], 4);  // @247_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 80) + 8), &X0[2], 4);  // @248_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 80) + 12), &X0[3], 4);  // @249_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 80) + 0), 4); v; });  // @250_4587d0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 80) + 4), 4); v; });  // @251_4587d0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 80) + 8), 4); v; });  // @252_4587d0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 80) + 12), 4); v; });  // @253_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 96) + 0), &X0[0], 4);  // @254_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 96) + 4), &X0[1], 4);  // @255_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 96) + 8), &X0[2], 4);  // @256_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 96) + 12), &X0[3], 4);  // @257_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_4587d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 64) + 32) + 0), 4); v; });  // @259_4587d0
  X0[1] = 0;  // @260_4587d0
  X0[2] = 0;  // @261_4587d0
  X0[3] = 0;  // @262_4587d0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @263_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @264_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @265_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @266_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @267_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @268_4587d0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @269_4587d0
  ecx = edx = 0;  // @270_4587d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 12), sizeof v); (u32)v; });  // @271_4587d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 16), sizeof v); (u32)v; }) + (u32)(112))); __builtin_memcpy((void *)(u32)((EBP - 64) + 16), &v, sizeof v); }  // @272_4587d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 16), sizeof v); (u32)v; });  // @273_4587d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 40), sizeof v); (u32)v; });  // @274_4587d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @275_4587d0
  __builtin_memcpy((void *)((u32)(ebx + 12) + 0), &X0[0], 4);  // @276_4587d0
  ebx = (ebx + (u32)(112));  // @277_4587d0
  FL[3] = ebx;  // @278_4587d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @279_4587d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @280_4587d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @281_4587d0
  ecx = (ecx + (u32)(112));  // @282_4587d0
  FL[3] = ecx;  // @283_4587d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 64) + 36), &v, sizeof v); }  // @284_4587d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 64) + 20), sizeof v); (u32)v; });  // @285_4587d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 64) + 12), &v, sizeof v); }  // @286_4587d0
  L458a98:;
  eax = (eax + 1);  // @288_4587d0
  FL[3] = eax;  // @289_4587d0
  ebx = (ebx + (u32)(124));  // @290_4587d0
  FL[3] = ebx;  // @291_4587d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 64) + 40), &v, sizeof v); }  // @292_4587d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 64) + 20), &v, sizeof v); }  // @293_4587d0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @294_4587d0
  if (FL[0] != FL[1]) goto L458884;  // @295_4587d0
  L458aad:;
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @297_4587d0
  eax = ext_634273_cdecl2(PV[12], (u32)(124));  // @298_4587d0
  ecx = edx = 0;  // @299_4587d0
  ext_633654(G(u32, 0x6f5630));  // @300_4587d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @301_4587d0
  return eax;  // @302_4587d0
}
PCREG(4587d0, lifted_4587d0);

