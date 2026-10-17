// batch242034.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 ext_633910_cdecl0(void) __asm__("ext_633910");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_44d590(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_44d590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1_44d590
  ebx = ecx;  // @2_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @3_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 180) + 56), &v, sizeof v); }  // @4_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @5_44d590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 180) + 16), &v, sizeof v); }  // @6_44d590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 180) + 40), &v, sizeof v); }  // @7_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 180) + 20), &v, sizeof v); }  // @8_44d590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_44d590
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 184) + 16), &v, sizeof v); }  // @10_44d590
  FL[2] = (ecx & ecx);  // @11_44d590
  if (FL[2] == 0) goto L44dc6d;  // @12_44d590
  ecx = (u32)((EBP - 184) + 108);  // @13_44d590
  { u32 v = (u32)((u32)(1097859072)); __builtin_memcpy((void *)(u32)((EBP - 184) + 72), &v, sizeof v); }  // @14_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 76), &v, sizeof v); }  // @15_44d590
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)((EBP - 184) + 80), &v, sizeof v); }  // @16_44d590
  eax = ext_4de7a0_thiscall1(ecx);  // @17_44d590
    // @18_44d590
  edx = esi;  // @19_44d590
  ecx = (u32)((EBP - 184) + 72);  // @20_44d590
  eax = ext_4419f0_fastcall2(ecx, edx);  // @21_44d590
  ecx = edx = 0;  // @22_44d590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 24), sizeof v); (u32)v; });  // @23_44d590
  ecx = (u32)((EBP - 184) + 72);  // @24_44d590
  eax = ext_441940_fastcall2(ecx, edx);  // @25_44d590
  ecx = edx = 0;  // @26_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @27_44d590
  X0[1] = 0;  // @28_44d590
  X0[2] = 0;  // @29_44d590
  X0[3] = 0;  // @30_44d590
  edx = (u32)((EBP - 184) + 72);  // @31_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 44), sizeof v); (u32)v; });  // @32_44d590
  __builtin_memcpy((void *)((u32)((EBP - 184) + 108) + 0), &X0[0], 4);  // @33_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @34_44d590
  X0[1] = 0;  // @35_44d590
  X0[2] = 0;  // @36_44d590
  X0[3] = 0;  // @37_44d590
  PV[0] = (u32)(edx);  // @38_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_44d590
  edx = (u32)((EBP - 188) + 112);  // @40_44d590
  __builtin_memcpy((void *)((u32)((EBP - 188) + 116) + 0), &X0[0], 4);  // @41_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @42_44d590
  X0[1] = 0;  // @43_44d590
  X0[2] = 0;  // @44_44d590
  X0[3] = 0;  // @45_44d590
  PV[1] = (u32)(edx);  // @46_44d590
  __builtin_memcpy((void *)((u32)((EBP - 192) + 124) + 0), &X0[0], 4);  // @47_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[1], PV[0]);  // @48_44d590
  ecx = edx = 0;  // @49_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @50_44d590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @51_44d590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @52_44d590
  if (FL[0] == FL[1]) goto L44d9de;  // @53_44d590
  L44d660:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @55_44d590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @56_44d590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(6);  // @57_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @58_44d590
  if (FL[0] > FL[1]) goto L44d9d4;  // @59_44d590
  ecx = (u32)(edi + edi);  // @60_44d590
  eax = (eax + ecx);  // @61_44d590
  FL[3] = eax;  // @62_44d590
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 184) + 56), &v, sizeof v); }  // @63_44d590
  eax = (u32)(eax + eax*2);  // @64_44d590
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 188) + 0), 4); v; });  // @65_44d590
  X1[1] = 0;  // @66_44d590
  X1[2] = 0;  // @67_44d590
  X1[3] = 0;  // @68_44d590
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 184) + 0), 4); v; });  // @69_44d590
  X2[1] = 0;  // @70_44d590
  X2[2] = 0;  // @71_44d590
  X2[3] = 0;  // @72_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4 + 192) + 0), 4); v; });  // @73_44d590
  X0[1] = 0;  // @74_44d590
  X0[2] = 0;  // @75_44d590
  X0[3] = 0;  // @76_44d590
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @77_44d590
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @78_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @79_44d590
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @80_44d590
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @81_44d590
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @82_44d590
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @83_44d590
  ecx = edx = 0;  // @84_44d590
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @85_44d590
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))))))) goto L44d6ce;  // @86_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @87_44d590
  FL[2] = (eax & eax);  // @88_44d590
  if (FL[2] == 0) goto L44d6cd;  // @89_44d590
  eax = ((u32(STDCALL *)(void))(eax))();  // @90_44d590
  ecx = edx = 0;  // @91_44d590
  goto L44d6ce;  // @92_44d590
  L44d6cd:;
  __builtin_trap();  // @94_44d590
  L44d6ce:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @96_44d590
  PV[2] = (u32)(ecx);  // @97_44d590
  eax = (u32)(eax + edi*2);  // @98_44d590
  eax = (u32)(eax + eax*2);  // @99_44d590
  eax = (u32)(eax + 46);  // @100_44d590
  ecx = (u32)(ebx + eax*4);  // @101_44d590
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1107296256));  // @102_44d590
    // @103_44d590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @104_44d590
  eax = (u32)(esi + 4);  // @105_44d590
  ecx = (u32)((EBP - 184) + 64);  // @106_44d590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 184) + 32), &v, sizeof v); }  // @107_44d590
  FL[0] = eax; FL[1] = ecx;  // @108_44d590
  if (FL[0] == FL[1]) goto L44d702;  // @109_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @110_44d590
  L44d702:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) + (u32)(6))); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @112_44d590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @113_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_44d590
  eax = (eax + (u32)(64));  // @115_44d590
  FL[3] = eax;  // @116_44d590
  FL[0] = esi; FL[1] = eax;  // @117_44d590
  if (FL[0] == FL[1]) goto L44d716;  // @118_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @120_44d590
  L44d716:;
  eax = (u32)(ebx + 6);  // @122_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 40), &v, sizeof v); }  // @123_44d590
  FL[0] = ebx; FL[1] = eax;  // @124_44d590
  if (FL[0] >= FL[1]) goto L44d9d0;  // @125_44d590
  eax = (u32)(ebx + 2);  // @126_44d590
  edi = (u32)(ebx + ebx*2);  // @127_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 36), &v, sizeof v); }  // @128_44d590
  ebx = (u32)(ebx + ebx*2);  // @129_44d590
  edi = (edi << (u32)(4));  // @130_44d590
  FL[3] = edi;  // @131_44d590
  ebx = (ebx << (u32)(3));  // @132_44d590
  FL[3] = ebx;  // @133_44d590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 184) + 24), &v, sizeof v); }  // @134_44d590
  L44d740:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @136_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 72) + 0), 4); v; });  // @137_44d590
  X0[1] = 0;  // @138_44d590
  X0[2] = 0;  // @139_44d590
  X0[3] = 0;  // @140_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 36) + 0), &X0[0], 4);  // @141_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 192) + 84) + 0), 4); v; });  // @142_44d590
  X0[1] = 0;  // @143_44d590
  X0[2] = 0;  // @144_44d590
  X0[3] = 0;  // @145_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 40) + 0), &X0[0], 4);  // @146_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 192) + 88) + 0), 4); v; });  // @147_44d590
  X0[1] = 0;  // @148_44d590
  X0[2] = 0;  // @149_44d590
  X0[3] = 0;  // @150_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 44) + 0), &X0[0], 4);  // @151_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @152_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + eax), &v, sizeof v); }  // @153_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @154_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + eax + 16), &v, sizeof v); }  // @155_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @157_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @158_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(319));  // @159_44d590
  ecx = edx = 0;  // @160_44d590
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6806044)) : "st");  // @161_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @162_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 16), sizeof v); (u32)v; });  // @163_44d590
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(6818420)) : "st");  // @164_44d590
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 184) + 28)) :: "st");  // @165_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 28) + 0), 4); v; });  // @166_44d590
  X0[1] = 0;  // @167_44d590
  X0[2] = 0;  // @168_44d590
  X0[3] = 0;  // @169_44d590
  __builtin_memcpy((void *)((u32)(ebx + eax + 12) + 0), &X0[0], 4);  // @170_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @171_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ebx), &v, sizeof v); }  // @172_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ebx + 4), &v, sizeof v); }  // @173_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ebx + 8), &v, sizeof v); }  // @174_44d590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 20), sizeof v); (u32)v; });  // @175_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @176_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4 + 3736) + 0), 4); v; });  // @177_44d590
  X0[1] = 0;  // @178_44d590
  X0[2] = 0;  // @179_44d590
  X0[3] = 0;  // @180_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; })));  // @181_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 4) + 0), &X0[0], 4);  // @182_44d590
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx + 3752), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @183_44d590
  if (FL[0] == FL[1]) goto L44d812;  // @184_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @185_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 4) + 0), 4); v; });  // @186_44d590
  X0[1] = 0;  // @187_44d590
  X0[2] = 0;  // @188_44d590
  X0[3] = 0;  // @189_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @190_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 4) + 0), &X0[0], 4);  // @191_44d590
  L44d812:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @193_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; });  // @194_44d590
  X0[1] = 0;  // @195_44d590
  X0[2] = 0;  // @196_44d590
  X0[3] = 0;  // @197_44d590
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 4) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 4) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 4) + 0), 4); v; }))))))) goto L44d82c;  // @198_44d590
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)(edi + eax + 4), &v, sizeof v); }  // @199_44d590
  L44d82c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @201_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @203_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(324));  // @204_44d590
  ecx = edx = 0;  // @205_44d590
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6792876)) : "st");  // @206_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @207_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 16), sizeof v); (u32)v; });  // @208_44d590
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(6818408)) : "st");  // @209_44d590
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 192) + 36)) :: "st");  // @210_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 192) + 36) + 0), 4); v; });  // @211_44d590
  X0[1] = 0;  // @212_44d590
  X0[2] = 0;  // @213_44d590
  X0[3] = 0;  // @214_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 8) + 0), &X0[0], 4);  // @215_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @216_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx*4 + 3736) + 0), 4); v; });  // @217_44d590
  X0[1] = 0;  // @218_44d590
  X0[2] = 0;  // @219_44d590
  X0[3] = 0;  // @220_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 8) + 0), 4); v; })));  // @221_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 8) + 0), &X0[0], 4);  // @222_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_44d590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @224_44d590
  ebx = (ebx + edi);  // @225_44d590
  FL[3] = ebx;  // @226_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @228_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(329));  // @229_44d590
  ecx = edx = 0;  // @230_44d590
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6818400)) : "st");  // @231_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @232_44d590
  __asm__ volatile("fld1" ::: "st");  // @233_44d590
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @234_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_44d590
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 192) + 36)) :: "st");  // @236_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @237_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(330));  // @238_44d590
  ecx = edx = 0;  // @239_44d590
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6818400)) : "st");  // @240_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @241_44d590
  __asm__ volatile("fld1" ::: "st");  // @242_44d590
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @243_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @244_44d590
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 192) + 56)) :: "st");  // @245_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @246_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6818324), (u32)(331));  // @247_44d590
  ecx = edx = 0;  // @248_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 28) + 0), 4); v; });  // @249_44d590
  X0[1] = 0;  // @250_44d590
  X0[2] = 0;  // @251_44d590
  X0[3] = 0;  // @252_44d590
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6818400)) : "st");  // @253_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @254_44d590
  __asm__ volatile("fld1" ::: "st");  // @255_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 20), sizeof v); (u32)v; });  // @256_44d590
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @257_44d590
  ecx = (ecx + (u32)(184));  // @258_44d590
  FL[3] = ecx;  // @259_44d590
  __builtin_memcpy((void *)((u32)(ebx + 12) + 0), &X0[0], 4);  // @260_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 48) + 0), 4); v; });  // @261_44d590
  X0[1] = 0;  // @262_44d590
  X0[2] = 0;  // @263_44d590
  X0[3] = 0;  // @264_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @265_44d590
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 184) + 52)) :: "st");  // @266_44d590
  __builtin_memcpy((void *)((u32)(ebx + 16) + 0), &X0[0], 4);  // @267_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 52) + 0), 4); v; });  // @268_44d590
  X0[1] = 0;  // @269_44d590
  X0[2] = 0;  // @270_44d590
  X0[3] = 0;  // @271_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @272_44d590
  __builtin_memcpy((void *)((u32)(ebx + 20) + 0), &X0[0], 4);  // @273_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @274_44d590
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 56), sizeof v); (u32)v; }));  // @275_44d590
  FL[3] = eax;  // @276_44d590
  eax = (u32)(eax + eax*2);  // @277_44d590
  edx = (u32)(ecx + eax*4);  // @278_44d590
  ecx = (u32)(ebx + 12);  // @279_44d590
  eax = ext_441940_fastcall2(ecx, edx);  // @280_44d590
  ecx = edx = 0;  // @281_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 36), sizeof v); (u32)v; });  // @282_44d590
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 32), sizeof v); (u32)v; }); FL[1] = eax;  // @283_44d590
  if (FL[0] >= FL[1]) goto L44d986;  // @284_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 12) + 0), 4); v; });  // @285_44d590
  X0[1] = 0;  // @286_44d590
  X0[2] = 0;  // @287_44d590
  X0[3] = 0;  // @288_44d590
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @289_44d590
  X1[1] = 0;  // @290_44d590
  X1[2] = 0;  // @291_44d590
  X1[3] = 0;  // @292_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @293_44d590
  __builtin_memcpy((void *)((u32)(ebx + 12) + 0), &X0[0], 4);  // @294_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 16) + 0), 4); v; });  // @295_44d590
  X0[1] = 0;  // @296_44d590
  X0[2] = 0;  // @297_44d590
  X0[3] = 0;  // @298_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @299_44d590
  __builtin_memcpy((void *)((u32)(ebx + 16) + 0), &X0[0], 4);  // @300_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 20) + 0), 4); v; });  // @301_44d590
  X0[1] = 0;  // @302_44d590
  X0[2] = 0;  // @303_44d590
  X0[3] = 0;  // @304_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @305_44d590
  __builtin_memcpy((void *)((u32)(ebx + 20) + 0), &X0[0], 4);  // @306_44d590
  L44d986:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @308_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 72) + 0), 4); v; });  // @309_44d590
  X0[1] = 0;  // @310_44d590
  X0[2] = 0;  // @311_44d590
  X0[3] = 0;  // @312_44d590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 32), sizeof v); (u32)v; });  // @313_44d590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 24), sizeof v); (u32)v; }) + (u32)(24))); __builtin_memcpy((void *)(u32)((EBP - 184) + 24), &v, sizeof v); }  // @314_44d590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 24), sizeof v); (u32)v; });  // @315_44d590
  ebx = (ebx + 1);  // @316_44d590
  FL[3] = ebx;  // @317_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 24) + 0), &X0[0], 4);  // @318_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 76) + 0), 4); v; });  // @319_44d590
  X0[1] = 0;  // @320_44d590
  X0[2] = 0;  // @321_44d590
  X0[3] = 0;  // @322_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 28) + 0), &X0[0], 4);  // @323_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 80) + 0), 4); v; });  // @324_44d590
  X0[1] = 0;  // @325_44d590
  X0[2] = 0;  // @326_44d590
  X0[3] = 0;  // @327_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 32) + 0), &X0[0], 4);  // @328_44d590
  edi = (edi + (u32)(48));  // @329_44d590
  FL[3] = edi;  // @330_44d590
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 40), sizeof v); (u32)v; });  // @331_44d590
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 184) + 32), &v, sizeof v); }  // @332_44d590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 24), sizeof v); (u32)v; });  // @333_44d590
  if (FL[0] < FL[1]) goto L44d740;  // @334_44d590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 16), sizeof v); (u32)v; });  // @335_44d590
  L44d9d0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 20), sizeof v); (u32)v; });  // @337_44d590
  L44d9d4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @339_44d590
  if (FL[0] != FL[1]) goto L44d660;  // @340_44d590
  L44d9de:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @342_44d590
  edx = (u32)(esi + 24);  // @343_44d590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 184) + 36), &v, sizeof v); }  // @344_44d590
  if (FL[0] == FL[1]) goto L44dc6d;  // @345_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @346_44d590
  edi = (u32)(ebx + 36);  // @347_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @348_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @349_44d590
  X0[1] = 0;  // @350_44d590
  X0[2] = 0;  // @351_44d590
  X0[3] = 0;  // @352_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @353_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @354_44d590
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @355_44d590
  ecx = (ecx - eax);  // @356_44d590
  FL[3] = ecx;  // @357_44d590
  eax = (u32)((EBP - 184) + 68);  // @358_44d590
  X2[0] = ecx; X2[1] = X2[2] = X2[3] = 0;  // @359_44d590
  X2[0] = F2U((float)(s32)X2[0]);  // @360_44d590
  X2[1] = F2U((float)(s32)X2[1]);  // @361_44d590
  X2[2] = F2U((float)(s32)X2[2]);  // @362_44d590
  X2[3] = F2U((float)(s32)X2[3]);  // @363_44d590
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @364_44d590
  __builtin_memcpy((void *)((u32)((EBP - 184) + 40) + 0), &X2[0], 4);  // @365_44d590
  FL[0] = edi; FL[1] = eax;  // @366_44d590
  if (FL[0] == FL[1]) goto L44da51;  // @367_44d590
  { float f_ = U2F(X2[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @368_44d590
  X1[0] = X2[0];  // @369_44d590
  X1[1] = X2[1];  // @370_44d590
  X1[2] = X2[2];  // @371_44d590
  X1[3] = X2[3];  // @372_44d590
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @373_44d590
  X0[0] = F2U((float)(s32)X0[0]);  // @374_44d590
  X0[1] = F2U((float)(s32)X0[1]);  // @375_44d590
  X0[2] = F2U((float)(s32)X0[2]);  // @376_44d590
  X0[3] = F2U((float)(s32)X0[3]);  // @377_44d590
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @378_44d590
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @379_44d590
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @380_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @381_44d590
  L44da51:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @383_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 16), &v, sizeof v); }  // @384_44d590
  if (FL[0] <= FL[1]) goto L44dbee;  // @385_44d590
  edi = 0;  // @386_44d590
  FL[3] = edi;  // @387_44d590
  X1[0] = 0;  // @388_44d590
  X1[1] = 0;  // @389_44d590
  X1[2] = 0;  // @390_44d590
  X1[3] = 0;  // @391_44d590
  ebx = 0;  // @392_44d590
  FL[3] = ebx;  // @393_44d590
  L44da70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @395_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 4) + 0), 4); v; });  // @396_44d590
  X0[1] = 0;  // @397_44d590
  X0[2] = 0;  // @398_44d590
  X0[3] = 0;  // @399_44d590
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L44dad2;  // @400_44d590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @401_44d590
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @402_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @403_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @404_44d590
  eax = (u32)(eax + eax*2);  // @405_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 0), 4); v; });  // @406_44d590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 4), 4); v; });  // @407_44d590
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 8), 4); v; });  // @408_44d590
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 12), 4); v; });  // @409_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 0), &X0[0], 4);  // @410_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 4), &X0[1], 4);  // @411_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 8), &X0[2], 4);  // @412_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx) + 12), &X0[3], 4);  // @413_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 0), 4); v; });  // @414_44d590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 4), 4); v; });  // @415_44d590
  X0[2] = 0;  // @416_44d590
  X0[3] = 0;  // @417_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx + 16) + 0), &X0[0], 4);  // @418_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx + 16) + 4), &X0[1], 4);  // @419_44d590
  ebx = (ebx - (u32)(24));  // @420_44d590
  FL[3] = ebx;  // @421_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @422_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @423_44d590
  eax = (u32)(eax + eax*2);  // @424_44d590
  eax = (eax + eax);  // @425_44d590
  FL[3] = eax;  // @426_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 0), 4); v; });  // @427_44d590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 4), 4); v; });  // @428_44d590
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 8), 4); v; });  // @429_44d590
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8) + 12), 4); v; });  // @430_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx) + 0), &X0[0], 4);  // @431_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx) + 4), &X0[1], 4);  // @432_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx) + 8), &X0[2], 4);  // @433_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx) + 12), &X0[3], 4);  // @434_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 0), 4); v; });  // @435_44d590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 4), 4); v; });  // @436_44d590
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 8), 4); v; });  // @437_44d590
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 16) + 12), 4); v; });  // @438_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 16) + 0), &X0[0], 4);  // @439_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 16) + 4), &X0[1], 4);  // @440_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 16) + 8), &X0[2], 4);  // @441_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 16) + 12), &X0[3], 4);  // @442_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 0), 4); v; });  // @443_44d590
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 4), 4); v; });  // @444_44d590
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 8), 4); v; });  // @445_44d590
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax*8 + 32) + 12), 4); v; });  // @446_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 16), sizeof v); (u32)v; });  // @447_44d590
  eax = (eax - 1);  // @448_44d590
  FL[3] = eax;  // @449_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 32) + 0), &X0[0], 4);  // @450_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 32) + 4), &X0[1], 4);  // @451_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 32) + 8), &X0[2], 4);  // @452_44d590
  __builtin_memcpy((void *)((u32)(edi + ecx + 32) + 12), &X0[3], 4);  // @453_44d590
  edi = (edi - (u32)(48));  // @454_44d590
  FL[3] = edi;  // @455_44d590
  goto L44dbd7;  // @456_44d590
  L44dad2:;
  { float f_ = U2F(X0[0]); u32 r_; __asm__ volatile("call ext_633910" : "=a"(r_) : "Yz"(f_) : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "memory", "cc"); eax = r_; }   // hand fix: the CRT classifier takes its argument in xmm0  // @458_44d590
  ecx = 0;  // @459_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @460_44d590
  edx = eax;  // @461_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @462_44d590
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 184) + 40) + 0), 4); v; });  // @463_44d590
  X2[1] = 0;  // @464_44d590
  X2[2] = 0;  // @465_44d590
  X2[3] = 0;  // @466_44d590
  edx = (edx << (u32)(28));  // @467_44d590
  FL[3] = edx;  // @468_44d590
  edx = (edx | (u32)(16777215));  // @469_44d590
  FL[3] = edx;  // @470_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 8) + 0), 4); v; });  // @471_44d590
  X0[1] = 0;  // @472_44d590
  X0[2] = 0;  // @473_44d590
  X0[3] = 0;  // @474_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @475_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + ecx + 12) + 0), 4); v; })));  // @476_44d590
  __builtin_memcpy((void *)((u32)(ebx + ecx + 12) + 0), &X0[0], 4);  // @477_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @478_44d590
  { float f_ = U2F(X2[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @479_44d590
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + eax + 20), &v, sizeof v); }  // @480_44d590
  FL[0] = ecx; FL[1] = (u32)(1);  // @481_44d590
  if ((s32)FL[0] < (s32)FL[1]) goto L44db9d;  // @482_44d590
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818392) + 0), 4); v; });  // @483_44d590
  X1[1] = 0;  // @484_44d590
  X1[2] = 0;  // @485_44d590
  X1[3] = 0;  // @486_44d590
  L44db20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @488_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 12) + 0), 4); v; });  // @489_44d590
  X0[1] = 0;  // @490_44d590
  X0[2] = 0;  // @491_44d590
  X0[3] = 0;  // @492_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 24) + 0), 4); v; })));  // @493_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 24) + 0), &X0[0], 4);  // @494_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @495_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 12) + 0), 4); v; });  // @496_44d590
  X0[1] = 0;  // @497_44d590
  X0[2] = 0;  // @498_44d590
  X0[3] = 0;  // @499_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @500_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 12) + 0), &X0[0], 4);  // @501_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @502_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 16) + 0), 4); v; });  // @503_44d590
  X0[1] = 0;  // @504_44d590
  X0[2] = 0;  // @505_44d590
  X0[3] = 0;  // @506_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 28) + 0), 4); v; })));  // @507_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 28) + 0), &X0[0], 4);  // @508_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @509_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 16) + 0), 4); v; });  // @510_44d590
  X0[1] = 0;  // @511_44d590
  X0[2] = 0;  // @512_44d590
  X0[3] = 0;  // @513_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @514_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 16) + 0), &X0[0], 4);  // @515_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @516_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 20) + 0), 4); v; });  // @517_44d590
  X0[1] = 0;  // @518_44d590
  X0[2] = 0;  // @519_44d590
  X0[3] = 0;  // @520_44d590
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 32) + 0), 4); v; })));  // @521_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 32) + 0), &X0[0], 4);  // @522_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @523_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 20) + 0), 4); v; });  // @524_44d590
  X0[1] = 0;  // @525_44d590
  X0[2] = 0;  // @526_44d590
  X0[3] = 0;  // @527_44d590
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @528_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 20) + 0), &X0[0], 4);  // @529_44d590
  ecx = (ecx - (u32)(1));  // @530_44d590
  FL[3] = ecx;  // @531_44d590
  if (FL[3] != 0) goto L44db20;  // @532_44d590
  L44db9d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @534_44d590
  X1[0] = 0;  // @535_44d590
  X1[1] = 0;  // @536_44d590
  X1[2] = 0;  // @537_44d590
  X1[3] = 0;  // @538_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @539_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx + 24), sizeof v); (u32)v; });  // @540_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx), &v, sizeof v); }  // @541_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx + 28), sizeof v); (u32)v; });  // @542_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx + 4), &v, sizeof v); }  // @543_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx + 32), sizeof v); (u32)v; });  // @544_44d590
  edx = (u32)(esi + 24);  // @545_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx + 8), &v, sizeof v); }  // @546_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @547_44d590
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 4) + 0), 4); v; });  // @548_44d590
  X0[1] = 0;  // @549_44d590
  X0[2] = 0;  // @550_44d590
  X0[3] = 0;  // @551_44d590
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @552_44d590
  __builtin_memcpy((void *)((u32)(edi + eax + 4) + 0), &X0[0], 4);  // @553_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 16), sizeof v); (u32)v; });  // @554_44d590
  L44dbd7:;
  eax = (eax + 1);  // @556_44d590
  FL[3] = eax;  // @557_44d590
  ebx = (ebx + (u32)(24));  // @558_44d590
  FL[3] = ebx;  // @559_44d590
  edi = (edi + (u32)(48));  // @560_44d590
  FL[3] = edi;  // @561_44d590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 184) + 16), &v, sizeof v); }  // @562_44d590
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @563_44d590
  if (FL[0] < FL[1]) goto L44da70;  // @564_44d590
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 20), sizeof v); (u32)v; });  // @565_44d590
  L44dbee:;
  ecx = (u32)((EBP - 184) + 144);  // @567_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 96), &v, sizeof v); }  // @568_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 100), &v, sizeof v); }  // @569_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 184) + 104), &v, sizeof v); }  // @570_44d590
  eax = ext_4de7a0_thiscall1(ecx);  // @571_44d590
    // @572_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 44), sizeof v); (u32)v; });  // @573_44d590
  edx = (u32)((EBP - 184) + 84);  // @574_44d590
  PV[3] = (u32)(edx);  // @575_44d590
  edx = (u32)((EBP - 188) + 148);  // @576_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 188) + 88), &v, sizeof v); }  // @577_44d590
  PV[4] = (u32)(edx);  // @578_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @579_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 192) + 96), &v, sizeof v); }  // @580_44d590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 192) + 100), &v, sizeof v); }  // @581_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[4], PV[3]);  // @582_44d590
  ecx = edx = 0;  // @583_44d590
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 184) + 36), sizeof v); (u32)v; });  // @584_44d590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 188) + 64), sizeof v); (u32)v; });  // @585_44d590
  edx = (u32)((EBP - 188) + 100);  // @586_44d590
  PV[6] = (u32)(ecx);  // @587_44d590
  PV[7] = (u32)(edx);  // @588_44d590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @589_44d590
  edx = (u32)((EBP - 196) + 96);  // @590_44d590
  PV[8] = (u32)(edx);  // @591_44d590
  edx = (u32)((EBP - 200) + 160);  // @592_44d590
  PV[9] = (u32)(edx);  // @593_44d590
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @594_44d590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, PV[10], PV[9], PV[8], PV[7], (u32)(1343554297), PV[5]);  // @595_44d590
  ecx = edx = 0;  // @596_44d590
  L44dc6d:;
  ext_633654(G(u32, 0x6f5630));  // @598_44d590
  return eax;  // @599_44d590
}
PCREG(44d590, lifted_44d590);

