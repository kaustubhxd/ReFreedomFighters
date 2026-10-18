// batch244025.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 STDCALL ext_54a0e0_stdcall2(u32, u32) __asm__("ext_54a0e0");
extern "C" u32 THISCALL ext_441790_thiscall2(u32, u32) __asm__("ext_441790");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_610f20_thiscall2(u32, u32) __asm__("ext_610f20");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_54c4b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_54c4b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_54c4b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @2_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @3_54c4b0
  eax = (eax + (u32)(32873));  // @4_54c4b0
  FL[3] = eax;  // @5_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @6_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_54c4b0
  FL[2] = (ecx & ecx);  // @8_54c4b0
  if (FL[2] == 0) goto L54c643;  // @9_54c4b0
  ebx = 0;  // @10_54c4b0
  FL[3] = ebx;  // @11_54c4b0
  FL[2] = (ecx & ecx);  // @12_54c4b0
  if ((s32)FL[2] <= 0) goto L54c636;  // @13_54c4b0
  edi = (u32)(eax + 16);  // @14_54c4b0
  L54c4f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_54c4b0
  eax = (eax - (u32)(2));  // @17_54c4b0
  FL[3] = eax;  // @18_54c4b0
  if (FL[3] == 0) goto L54c606;  // @19_54c4b0
  eax = (eax - (u32)(1));  // @20_54c4b0
  FL[3] = eax;  // @21_54c4b0
  if (FL[3] == 0) goto L54c520;  // @22_54c4b0
  eax = (eax - (u32)(2));  // @23_54c4b0
  FL[3] = eax;  // @24_54c4b0
  if (FL[3] != 0) goto L54c623;  // @25_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @26_54c4b0
  FL[2] = (eax & eax);  // @27_54c4b0
  if (FL[2] == 0) goto L54c51a;  // @28_54c4b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @29_54c4b0
  ecx = edx = 0;  // @30_54c4b0
  goto L54c623;  // @31_54c4b0
  L54c51a:;
  __builtin_trap();  // @33_54c4b0
  L54c520:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @35_54c4b0
  FL[2] = (eax & eax);  // @36_54c4b0
  if (FL[2] == 0) goto L54c606;  // @37_54c4b0
  { u32 v = (u32)((u32)(17)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @38_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @39_54c4b0
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @40_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @41_54c4b0
  { u32 v = (u32)((u32)(1049247089)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @42_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @43_54c4b0
  { u32 v = (u32)((u32)(4294966296)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @44_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @45_54c4b0
  { u32 v = (u32)((u32)(4294964796)); __builtin_memcpy((void *)(u32)(eax + 32), &v, sizeof v); }  // @46_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @47_54c4b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 36), &v, sizeof v); }  // @48_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @49_54c4b0
  { u32 v = (u32)((u32)(1062836634)); __builtin_memcpy((void *)(u32)(eax + 40), &v, sizeof v); }  // @50_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @51_54c4b0
  { u32 v = (u32)((u32)(1045891645)); __builtin_memcpy((void *)(u32)(eax + 44), &v, sizeof v); }  // @52_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @53_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @54_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @55_54c4b0
  { u32 v = (u32)((u32)(4294964516)); __builtin_memcpy((void *)(u32)(eax + 52), &v, sizeof v); }  // @56_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @57_54c4b0
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(eax + 56), &v, sizeof v); }  // @58_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @59_54c4b0
  { u32 v = (u32)((u32)(4294965862)); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @60_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @61_54c4b0
  { u32 v = (u32)((u32)(1036831949)); __builtin_memcpy((void *)(u32)(eax + 76), &v, sizeof v); }  // @62_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @63_54c4b0
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(eax + 92), &v, sizeof v); }  // @64_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @65_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 96), &v, sizeof v); }  // @66_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @67_54c4b0
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(eax + 100), &v, sizeof v); }  // @68_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @69_54c4b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 104), &v, sizeof v); }  // @70_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @71_54c4b0
  { u32 v = (u32)((u32)(3231711232)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @72_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @73_54c4b0
  { u32 v = (u32)((u32)(1167867904)); __builtin_memcpy((void *)(u32)(eax + 112), &v, sizeof v); }  // @74_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @75_54c4b0
  { u32 v = (u32)((u32)(1132068864)); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @76_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @77_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 120), &v, sizeof v); }  // @78_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @79_54c4b0
  { u32 v = (u32)((u32)(31)); __builtin_memcpy((void *)(u32)(eax + 124), &v, sizeof v); }  // @80_54c4b0
  goto L54c623;  // @81_54c4b0
  L54c606:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @83_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_54c4b0
  FL[2] = (ecx & ecx);  // @85_54c4b0
  if (FL[2] == 0) goto L54c623;  // @86_54c4b0
  FL[2] = (eax & eax);  // @87_54c4b0
  if (FL[2] == 0) goto L54c623;  // @88_54c4b0
  eax = (eax + (u32)(12));  // @89_54c4b0
  FL[3] = eax;  // @90_54c4b0
  PV[0] = (u32)(eax);  // @91_54c4b0
  eax = (u32)(ecx + 16);  // @92_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @93_54c4b0
  PV[1] = (u32)(eax);  // @94_54c4b0
  eax = ext_54a0e0_stdcall2(PV[1], PV[0]);  // @95_54c4b0
  ecx = edx = 0;  // @96_54c4b0
  L54c623:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @98_54c4b0
  ebx = (ebx + 1);  // @99_54c4b0
  FL[3] = ebx;  // @100_54c4b0
  edi = (edi + (u32)(8));  // @101_54c4b0
  FL[3] = edi;  // @102_54c4b0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @103_54c4b0
  if ((s32)FL[0] < (s32)FL[1]) goto L54c4f0;  // @104_54c4b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @105_54c4b0
  L54c636:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @107_54c4b0
  FL[2] = (ecx & ecx);  // @108_54c4b0
  if (FL[2] == 0) goto L54c643;  // @109_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_54c4b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @111_54c4b0
  ecx = edx = 0;  // @112_54c4b0
  L54c643:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @114_54c4b0
  edx = (u32)(EBP - 68);  // @115_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @116_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @117_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @118_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @119_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @120_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @121_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @122_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @123_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @124_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @125_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @126_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @127_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @128_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @129_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @130_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @131_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @132_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @133_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @134_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @135_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @136_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @137_54c4b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @138_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @139_54c4b0
  X0[1] = 0;  // @140_54c4b0
  X0[2] = 0;  // @141_54c4b0
  X0[3] = 0;  // @142_54c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @143_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @144_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @145_54c4b0
  X0[1] = 0;  // @146_54c4b0
  X0[2] = 0;  // @147_54c4b0
  X0[3] = 0;  // @148_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @149_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @150_54c4b0
  X0[1] = 0;  // @151_54c4b0
  X0[2] = 0;  // @152_54c4b0
  X0[3] = 0;  // @153_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @154_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 32) + 0), 4); v; });  // @155_54c4b0
  X0[1] = 0;  // @156_54c4b0
  X0[2] = 0;  // @157_54c4b0
  X0[3] = 0;  // @158_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @159_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; });  // @160_54c4b0
  X0[1] = 0;  // @161_54c4b0
  X0[2] = 0;  // @162_54c4b0
  X0[3] = 0;  // @163_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @164_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @165_54c4b0
  X0[1] = 0;  // @166_54c4b0
  X0[2] = 0;  // @167_54c4b0
  X0[3] = 0;  // @168_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @169_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 0), 4); v; });  // @170_54c4b0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 4), 4); v; });  // @171_54c4b0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 8), 4); v; });  // @172_54c4b0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 12), 4); v; });  // @173_54c4b0
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @174_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @175_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 4), &X0[1], 4);  // @176_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 8), &X0[2], 4);  // @177_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 12), &X0[3], 4);  // @178_54c4b0
  { u32 v = (u32)((u32)(1008981770)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @179_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 60) + 0), 4); v; });  // @180_54c4b0
  X0[1] = 0;  // @181_54c4b0
  X0[2] = 0;  // @182_54c4b0
  X0[3] = 0;  // @183_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @184_54c4b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 64) + 0), 4); v; });  // @185_54c4b0
  X0[1] = 0;  // @186_54c4b0
  X0[2] = 0;  // @187_54c4b0
  X0[3] = 0;  // @188_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @189_54c4b0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @190_54c4b0
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @191_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @192_54c4b0
  PV[2] = (u32)(edx);  // @193_54c4b0
  PV[3] = (u32)(eax);  // @194_54c4b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 40)))(ecx, PV[3], PV[2], (u32)(1));  // @195_54c4b0
  ecx = edx = 0;  // @196_54c4b0
  FL[2] = (eax & eax);  // @197_54c4b0
  if (FL[2] == 0) goto L54c719;  // @198_54c4b0
  edx = (u32)(6961668);  // @199_54c4b0
  goto L54c72b;  // @200_54c4b0
  L54c719:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @202_54c4b0
  PV[4] = (u32)(eax);  // @203_54c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @204_54c4b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(ecx + 68)))(ecx, PV[4]);  // @205_54c4b0
  ecx = edx = 0;  // @206_54c4b0
  FL[2] = (eax & eax);  // @207_54c4b0
  if (FL[2] == 0) goto L54c732;  // @208_54c4b0
  edx = (u32)(6961704);  // @209_54c4b0
  L54c72b:;
  ecx = eax;  // @211_54c4b0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @212_54c4b0
  ecx = edx = 0;  // @213_54c4b0
  L54c732:;
  ext_633654(G(u32, 0x6f5630));  // @215_54c4b0
  return eax;  // @216_54c4b0
}
PCREG(54c4b0, lifted_54c4b0);

extern "C" u32 THISCALL lifted_610430(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_610430
  edx = (u32)(7273616);  // @1_610430
  ebx = ecx;  // @2_610430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @3_610430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_610430
  ecx = (u32)(ebx + 5226);  // @5_610430
  edi = (u32)(60);  // @6_610430
  L610460:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_610430
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @9_610430
  if (FL[0] != FL[1]) goto L610473;  // @10_610430
  ecx = (ecx + (u32)(4));  // @11_610430
  FL[3] = ecx;  // @12_610430
  edx = (edx + (u32)(4));  // @13_610430
  FL[3] = edx;  // @14_610430
  edi = (edi - (u32)(4));  // @15_610430
  FL[3] = edi;  // @16_610430
  if (1 || FL[3]) goto L610460;  // @17_610430
  goto L6104b6;  // @18_610430
  L610473:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 0), 4); v; });  // @20_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 4), 4); v; });  // @21_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 8), 4); v; });  // @22_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 12), 4); v; });  // @23_610430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4983), sizeof v); (u32)v; });  // @24_610430
  edx = (u32)(ebx + 5226);  // @25_610430
  PV[0] = (u32)(edx);  // @26_610430
  __builtin_memcpy((void *)((u32)(edx) + 0), &X0[0], 4);  // @27_610430
  __builtin_memcpy((void *)((u32)(edx) + 4), &X0[1], 4);  // @28_610430
  __builtin_memcpy((void *)((u32)(edx) + 8), &X0[2], 4);  // @29_610430
  __builtin_memcpy((void *)((u32)(edx) + 12), &X0[3], 4);  // @30_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 0), 4); v; });  // @31_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 4), 4); v; });  // @32_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 8), 4); v; });  // @33_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 12), 4); v; });  // @34_610430
  PV[1] = (u32)(eax);  // @35_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 0), &X0[0], 4);  // @36_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 4), &X0[1], 4);  // @37_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 8), &X0[2], 4);  // @38_610430
  __builtin_memcpy((void *)((u32)(edx + 16) + 12), &X0[3], 4);  // @39_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 0), 4); v; });  // @40_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 4), 4); v; });  // @41_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 8), 4); v; });  // @42_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 12), 4); v; });  // @43_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 0), &X0[0], 4);  // @44_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 4), &X0[1], 4);  // @45_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 8), &X0[2], 4);  // @46_610430
  __builtin_memcpy((void *)((u32)(edx + 32) + 12), &X0[3], 4);  // @47_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 0), 4); v; });  // @48_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 4), 4); v; });  // @49_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 8), 4); v; });  // @50_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 12), 4); v; });  // @51_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 0), &X0[0], 4);  // @52_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 4), &X0[1], 4);  // @53_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 8), &X0[2], 4);  // @54_610430
  __builtin_memcpy((void *)((u32)(edx + 48) + 12), &X0[3], 4);  // @55_610430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_610430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[1], (u32)(2), PV[0]);  // @57_610430
  ecx = edx = 0;  // @58_610430
  L6104b6:;
  FL[2] = (esi & esi);  // @60_610430
  if (FL[2] == 0) goto L610634;  // @61_610430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @62_610430
  FL[2] = (ecx & ecx);  // @63_610430
  if (FL[2] == 0) goto L610634;  // @64_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @65_610430
  X0[1] = 0;  // @66_610430
  X0[2] = 0;  // @67_610430
  X0[3] = 0;  // @68_610430
  X1[0] = 0;  // @69_610430
  X1[1] = 0;  // @70_610430
  X1[2] = 0;  // @71_610430
  X1[3] = 0;  // @72_610430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @73_610430
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @74_610430
  if (__builtin_parity(FL[2] & 0xff)) goto L610504;  // @75_610430
  edx = ecx;  // @76_610430
  ecx = (u32)(EBP - 20);  // @77_610430
  eax = ext_44e630_fastcall2(ecx, edx);  // @78_610430
  ecx = edx = 0;  // @79_610430
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 72)) :: "st");  // @80_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @81_610430
  X0[1] = 0;  // @82_610430
  X0[2] = 0;  // @83_610430
  X0[3] = 0;  // @84_610430
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })));  // @85_610430
  PV[2] = (u32)(ecx);  // @86_610430
  ecx = (u32)(EBP - 20);  // @87_610430
  PV[3] = X0[0];  // @88_610430
  eax = ext_4e0d00_thiscall2(ecx, PV[3]);  // @89_610430
    // @90_610430
  X1[0] = 0;  // @91_610430
  X1[1] = 0;  // @92_610430
  X1[2] = 0;  // @93_610430
  X1[3] = 0;  // @94_610430
  goto L610521;  // @95_610430
  L610504:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @97_610430
  X0[1] = 0;  // @98_610430
  X0[2] = 0;  // @99_610430
  X0[3] = 0;  // @100_610430
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @101_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; });  // @102_610430
  X0[1] = 0;  // @103_610430
  X0[2] = 0;  // @104_610430
  X0[3] = 0;  // @105_610430
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @106_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 8) + 0), 4); v; });  // @107_610430
  X0[1] = 0;  // @108_610430
  X0[2] = 0;  // @109_610430
  X0[3] = 0;  // @110_610430
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @111_610430
  L610521:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4807), sizeof v); (u32)v; }) & (u32)(16384));  // @113_610430
  if (FL[2] != 0) goto L6105a1;  // @114_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 5362) + 0), 4); v; });  // @115_610430
  X0[1] = 0;  // @116_610430
  X0[2] = 0;  // @117_610430
  X0[3] = 0;  // @118_610430
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @119_610430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @120_610430
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @121_610430
  if (__builtin_parity(FL[2] & 0xff)) goto L6105a1;  // @122_610430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @123_610430
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @124_610430
  if (__builtin_parity(FL[2] & 0xff)) goto L6105a1;  // @125_610430
  PV[4] = (u32)(ecx);  // @126_610430
  edx = (u32)(esi + 24);  // @127_610430
  PV[5] = X0[0];  // @128_610430
  ecx = (u32)(EBP - 68);  // @129_610430
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[5]);  // @130_610430
    // @131_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @132_610430
  X0[1] = 0;  // @133_610430
  X0[2] = 0;  // @134_610430
  X0[3] = 0;  // @135_610430
  edx = (u32)(esi + 12);  // @136_610430
  PV[6] = (u32)(ecx);  // @137_610430
  ecx = (u32)(EBP - 52);  // @138_610430
  PV[7] = X0[0];  // @139_610430
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[7]);  // @140_610430
    // @141_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @142_610430
  X0[1] = 0;  // @143_610430
  X0[2] = 0;  // @144_610430
  X0[3] = 0;  // @145_610430
  edx = esi;  // @146_610430
  PV[8] = (u32)(ecx);  // @147_610430
  ecx = (u32)(EBP - 36);  // @148_610430
  PV[9] = X0[0];  // @149_610430
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[9]);  // @150_610430
    // @151_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @152_610430
  X0[1] = 0;  // @153_610430
  X0[2] = 0;  // @154_610430
  X0[3] = 0;  // @155_610430
  PV[10] = (u32)(ecx);  // @156_610430
  ecx = (u32)(EBP - 20);  // @157_610430
  PV[11] = X0[0];  // @158_610430
  eax = ext_4e0d00_thiscall2(ecx, PV[11]);  // @159_610430
    // @160_610430
  goto L6105fa;  // @161_610430
  L6105a1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @163_610430
  X0[1] = 0;  // @164_610430
  X0[2] = 0;  // @165_610430
  X0[3] = 0;  // @166_610430
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @167_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @168_610430
  X0[1] = 0;  // @169_610430
  X0[2] = 0;  // @170_610430
  X0[3] = 0;  // @171_610430
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @172_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 32) + 0), 4); v; });  // @173_610430
  X0[1] = 0;  // @174_610430
  X0[2] = 0;  // @175_610430
  X0[3] = 0;  // @176_610430
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @177_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @178_610430
  X0[1] = 0;  // @179_610430
  X0[2] = 0;  // @180_610430
  X0[3] = 0;  // @181_610430
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @182_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @183_610430
  X0[1] = 0;  // @184_610430
  X0[2] = 0;  // @185_610430
  X0[3] = 0;  // @186_610430
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @187_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @188_610430
  X0[1] = 0;  // @189_610430
  X0[2] = 0;  // @190_610430
  X0[3] = 0;  // @191_610430
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @192_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @193_610430
  X0[1] = 0;  // @194_610430
  X0[2] = 0;  // @195_610430
  X0[3] = 0;  // @196_610430
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @197_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @198_610430
  X0[1] = 0;  // @199_610430
  X0[2] = 0;  // @200_610430
  X0[3] = 0;  // @201_610430
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @202_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @203_610430
  X0[1] = 0;  // @204_610430
  X0[2] = 0;  // @205_610430
  X0[3] = 0;  // @206_610430
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @207_610430
  L6105fa:;
  eax = (u32)(EBP - 68);  // @209_610430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @210_610430
  PV[12] = (u32)(eax);  // @211_610430
  ecx = ebx;  // @212_610430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @213_610430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @214_610430
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @215_610430
  eax = ext_610f20_thiscall2(ecx, PV[12]);  // @216_610430
  ecx = edx = 0;  // @217_610430
  ext_633654(G(u32, 0x6f5630));  // @218_610430
  return eax;  // @219_610430
  L610634:;
  edi = (u32)(ebx + 5290);  // @221_610430
  edx = (u32)(7273616);  // @222_610430
  ecx = edi;  // @223_610430
  esi = (u32)(60);  // @224_610430
  L610646:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @226_610430
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @227_610430
  if (FL[0] != FL[1]) goto L61066a;  // @228_610430
  ecx = (ecx + (u32)(4));  // @229_610430
  FL[3] = ecx;  // @230_610430
  edx = (edx + (u32)(4));  // @231_610430
  FL[3] = edx;  // @232_610430
  esi = (esi - (u32)(4));  // @233_610430
  FL[3] = esi;  // @234_610430
  if (1 || FL[3]) goto L610646;  // @235_610430
  ext_633654(G(u32, 0x6f5630));  // @236_610430
  return eax;  // @237_610430
  L61066a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 0), 4); v; });  // @239_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 4), 4); v; });  // @240_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 8), 4); v; });  // @241_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273616) + 12), 4); v; });  // @242_610430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4983), sizeof v); (u32)v; });  // @243_610430
  PV[13] = (u32)(edi);  // @244_610430
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @245_610430
  __builtin_memcpy((void *)((u32)(edi) + 4), &X0[1], 4);  // @246_610430
  __builtin_memcpy((void *)((u32)(edi) + 8), &X0[2], 4);  // @247_610430
  __builtin_memcpy((void *)((u32)(edi) + 12), &X0[3], 4);  // @248_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 0), 4); v; });  // @249_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 4), 4); v; });  // @250_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 8), 4); v; });  // @251_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273632) + 12), 4); v; });  // @252_610430
  PV[14] = (u32)(eax);  // @253_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @254_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 4), &X0[1], 4);  // @255_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 8), &X0[2], 4);  // @256_610430
  __builtin_memcpy((void *)((u32)(edi + 16) + 12), &X0[3], 4);  // @257_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 0), 4); v; });  // @258_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 4), 4); v; });  // @259_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 8), 4); v; });  // @260_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273648) + 12), 4); v; });  // @261_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X0[0], 4);  // @262_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 4), &X0[1], 4);  // @263_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 8), &X0[2], 4);  // @264_610430
  __builtin_memcpy((void *)((u32)(edi + 32) + 12), &X0[3], 4);  // @265_610430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 0), 4); v; });  // @266_610430
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 4), 4); v; });  // @267_610430
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 8), 4); v; });  // @268_610430
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7273664) + 12), 4); v; });  // @269_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 0), &X0[0], 4);  // @270_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 4), &X0[1], 4);  // @271_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 8), &X0[2], 4);  // @272_610430
  __builtin_memcpy((void *)((u32)(edi + 48) + 12), &X0[3], 4);  // @273_610430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @274_610430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 148)))(ecx, PV[14], (u32)(256), PV[13]);  // @275_610430
  ecx = edx = 0;  // @276_610430
  ext_633654(G(u32, 0x6f5630));  // @277_610430
  return eax;  // @278_610430
}
PCREG(610430, lifted_610430);

extern "C" u32 THISCALL lifted_4f2d80(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f2d80
  edi = ecx;  // @1_4f2d80
  PV[0] = (u32)(ebx);  // @2_4f2d80
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4f2d80
  eax = ext_441790_thiscall2(ecx, PV[0]);  // @4_4f2d80
  ecx = edx = 0;  // @5_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4f2d80
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 111), sizeof v); (u32)v; });  // @7_4f2d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @10_4f2d80
  ecx = edx = 0;  // @11_4f2d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4f2d80
  esi = eax;  // @13_4f2d80
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 475), sizeof v); (u32)v; });  // @14_4f2d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @15_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[2]);  // @17_4f2d80
  ecx = edx = 0;  // @18_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_4f2d80
  ecx = ebx;  // @20_4f2d80
  PV[3] = (u32)(esi);  // @21_4f2d80
  edi = eax;  // @22_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[3]);  // @23_4f2d80
  ecx = edx = 0;  // @24_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @25_4f2d80
  ecx = ebx;  // @26_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_4f2d80
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; });  // @28_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[4]);  // @29_4f2d80
  ecx = edx = 0;  // @30_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_4f2d80
  ecx = ebx;  // @32_4f2d80
  PV[5] = (u32)(edi);  // @33_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[5]);  // @34_4f2d80
  ecx = edx = 0;  // @35_4f2d80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @36_4f2d80
  ecx = ebx;  // @37_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_4f2d80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1531), sizeof v); (u32)v; });  // @39_4f2d80
  PV[6] = (u32)(eax);  // @40_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[6]);  // @41_4f2d80
  ecx = edx = 0;  // @42_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @43_4f2d80
  ecx = ebx;  // @44_4f2d80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1532), sizeof v); (u32)v; });  // @45_4f2d80
  PV[7] = (u32)(eax);  // @46_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[7]);  // @47_4f2d80
  ecx = edx = 0;  // @48_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_4f2d80
  ecx = ebx;  // @50_4f2d80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1530), sizeof v); (u32)v; });  // @51_4f2d80
  PV[8] = (u32)(eax);  // @52_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[8]);  // @53_4f2d80
  ecx = edx = 0;  // @54_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_4f2d80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 151) + 0), 4); v; });  // @56_4f2d80
  X0[1] = 0;  // @57_4f2d80
  X0[2] = 0;  // @58_4f2d80
  X0[3] = 0;  // @59_4f2d80
  PV[9] = (u32)(ecx);  // @60_4f2d80
  ecx = ebx;  // @61_4f2d80
  PV[10] = X0[0];  // @62_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[10]);  // @63_4f2d80
  ecx = edx = 0;  // @64_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 423), sizeof v); (u32)v; });  // @65_4f2d80
  esi = (u32)(edi + 423);  // @66_4f2d80
  ecx = esi;  // @67_4f2d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @68_4f2d80
  ecx = edx = 0;  // @69_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @70_4f2d80
  ecx = ebx;  // @71_4f2d80
  PV[11] = (u32)(eax);  // @72_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, PV[11]);  // @73_4f2d80
  ecx = edx = 0;  // @74_4f2d80
  FL[2] = (esi & esi);  // @75_4f2d80
  if (FL[2] == 0) goto L4f2e79;  // @76_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_4f2d80
  ecx = (u32)(EBP - 16);  // @78_4f2d80
  PV[12] = (u32)(ecx);  // @79_4f2d80
  ecx = esi;  // @80_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @81_4f2d80
  ecx = edx = 0;  // @82_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @83_4f2d80
  ecx = (u32)(EBP - 16);  // @84_4f2d80
  PV[13] = (u32)(ecx);  // @85_4f2d80
  ecx = esi;  // @86_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[13]);  // @87_4f2d80
  ecx = edx = 0;  // @88_4f2d80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @89_4f2d80
  if (FL[0] == FL[1]) goto L4f2e79;  // @90_4f2d80
  L4f2e60:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_4f2d80
  ecx = ebx;  // @93_4f2d80
  PV[14] = (u32)(eax);  // @94_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[14]);  // @95_4f2d80
  ecx = edx = 0;  // @96_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_4f2d80
  ecx = (u32)(EBP - 16);  // @98_4f2d80
  PV[15] = (u32)(ecx);  // @99_4f2d80
  ecx = esi;  // @100_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @101_4f2d80
  ecx = edx = 0;  // @102_4f2d80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @103_4f2d80
  if (FL[0] != FL[1]) goto L4f2e60;  // @104_4f2d80
  L4f2e79:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 203), sizeof v); (u32)v; });  // @106_4f2d80
  esi = (u32)(edi + 203);  // @107_4f2d80
  ecx = esi;  // @108_4f2d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @109_4f2d80
  ecx = edx = 0;  // @110_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @111_4f2d80
  ecx = ebx;  // @112_4f2d80
  PV[16] = (u32)(eax);  // @113_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, PV[16]);  // @114_4f2d80
  ecx = edx = 0;  // @115_4f2d80
  FL[2] = (esi & esi);  // @116_4f2d80
  if (FL[2] == 0) goto L4f2ecb;  // @117_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @118_4f2d80
  ecx = (u32)(EBP - 16);  // @119_4f2d80
  PV[17] = (u32)(ecx);  // @120_4f2d80
  ecx = esi;  // @121_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @122_4f2d80
  ecx = edx = 0;  // @123_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_4f2d80
  ecx = (u32)(EBP - 16);  // @125_4f2d80
  PV[18] = (u32)(ecx);  // @126_4f2d80
  ecx = esi;  // @127_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[18]);  // @128_4f2d80
  ecx = edx = 0;  // @129_4f2d80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @130_4f2d80
  if (FL[0] == FL[1]) goto L4f2ecb;  // @131_4f2d80
  L4f2eb2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @133_4f2d80
  ecx = ebx;  // @134_4f2d80
  PV[19] = (u32)(eax);  // @135_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[19]);  // @136_4f2d80
  ecx = edx = 0;  // @137_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_4f2d80
  ecx = (u32)(EBP - 16);  // @139_4f2d80
  PV[20] = (u32)(ecx);  // @140_4f2d80
  ecx = esi;  // @141_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[20]);  // @142_4f2d80
  ecx = edx = 0;  // @143_4f2d80
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @144_4f2d80
  if (FL[0] != FL[1]) goto L4f2eb2;  // @145_4f2d80
  L4f2ecb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 159), sizeof v); (u32)v; });  // @147_4f2d80
  edi = (edi + (u32)(159));  // @148_4f2d80
  FL[3] = edi;  // @149_4f2d80
  ecx = edi;  // @150_4f2d80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @151_4f2d80
  ecx = edx = 0;  // @152_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @153_4f2d80
  ecx = ebx;  // @154_4f2d80
  PV[21] = (u32)(eax);  // @155_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 68)))(ecx, PV[21]);  // @156_4f2d80
  ecx = edx = 0;  // @157_4f2d80
  FL[2] = (edi & edi);  // @158_4f2d80
  if (FL[2] == 0) goto L4f2f4a;  // @159_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @160_4f2d80
  ecx = (u32)(EBP - 16);  // @161_4f2d80
  PV[22] = (u32)(ecx);  // @162_4f2d80
  ecx = edi;  // @163_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @164_4f2d80
  ecx = edx = 0;  // @165_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_4f2d80
  ecx = (u32)(EBP - 16);  // @167_4f2d80
  PV[23] = (u32)(ecx);  // @168_4f2d80
  ecx = edi;  // @169_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[23]);  // @170_4f2d80
  ecx = edx = 0;  // @171_4f2d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @172_4f2d80
  FL[2] = (eax & eax);  // @173_4f2d80
  if (FL[2] == 0) goto L4f2f4a;  // @174_4f2d80
  L4f2f05:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_4f2d80
  ecx = ebx;  // @177_4f2d80
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @178_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 60)))(ecx, PV[24]);  // @179_4f2d80
  ecx = edx = 0;  // @180_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @181_4f2d80
  ecx = edi;  // @182_4f2d80
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @183_4f2d80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @184_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 156), sizeof v); (u32)v; });  // @185_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[25]);  // @186_4f2d80
  ecx = edx = 0;  // @187_4f2d80
  PV[26] = (u32)(ecx);  // @188_4f2d80
  ecx = ebx;  // @189_4f2d80
  { float f_; __asm__ volatile("fstps %0" : "=m"(f_) :: "st"); PV[27] = F2U(f_); }  // @190_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[27]);  // @191_4f2d80
  ecx = edx = 0;  // @192_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @193_4f2d80
  ecx = ebx;  // @194_4f2d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @195_4f2d80
  eax = (eax + (u32)(4));  // @196_4f2d80
  FL[3] = eax;  // @197_4f2d80
  PV[28] = (u32)(eax);  // @198_4f2d80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[28], (u32)(13));  // @199_4f2d80
  ecx = edx = 0;  // @200_4f2d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @201_4f2d80
  ecx = (u32)(EBP - 16);  // @202_4f2d80
  PV[29] = (u32)(ecx);  // @203_4f2d80
  ecx = edi;  // @204_4f2d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[29]);  // @205_4f2d80
  ecx = edx = 0;  // @206_4f2d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @207_4f2d80
  FL[2] = (eax & eax);  // @208_4f2d80
  if (FL[2] != 0) goto L4f2f05;  // @209_4f2d80
  L4f2f4a:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @211_4f2d80
  return eax;  // @212_4f2d80
}
PCREG(4f2d80, lifted_4f2d80);

