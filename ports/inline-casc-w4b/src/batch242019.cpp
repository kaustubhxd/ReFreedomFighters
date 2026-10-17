// batch242019.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634db2_dbl2(double, double) __asm__("ext_634db2");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4b6440(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668bcb);  // @h_4b6440
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4b6440
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b6440
  X0[0] = 0;  // @2_4b6440
  X0[1] = 0;  // @3_4b6440
  X0[2] = 0;  // @4_4b6440
  X0[3] = 0;  // @5_4b6440
  ecx = edi;  // @6_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 276) + 0), &X0[0], 4);  // @7_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 388) + 0), &X0[0], 4);  // @8_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 388) + 4), &X0[1], 4);  // @9_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 388) + 8), &X0[2], 4);  // @10_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 388) + 12), &X0[3], 4);  // @11_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 404) + 0), &X0[0], 4);  // @12_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 404) + 4), &X0[1], 4);  // @13_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 404) + 8), &X0[2], 4);  // @14_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 404) + 12), &X0[3], 4);  // @15_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @16_4b6440
  ecx = edx = 0;  // @17_4b6440
  ecx = edi;  // @18_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 312), &v, sizeof v); }  // @19_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @20_4b6440
  ecx = edx = 0;  // @21_4b6440
  ecx = edi;  // @22_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @23_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @24_4b6440
  ecx = edx = 0;  // @25_4b6440
  ecx = edi;  // @26_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @27_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @28_4b6440
  ecx = edx = 0;  // @29_4b6440
  ecx = edi;  // @30_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @31_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @32_4b6440
  ecx = edx = 0;  // @33_4b6440
  ecx = edi;  // @34_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @35_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @36_4b6440
  ecx = edx = 0;  // @37_4b6440
  ecx = edi;  // @38_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @39_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @40_4b6440
  ecx = edx = 0;  // @41_4b6440
  ecx = edi;  // @42_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @43_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @44_4b6440
  ecx = edx = 0;  // @45_4b6440
  ecx = edi;  // @46_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @47_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @48_4b6440
  ecx = edx = 0;  // @49_4b6440
  ecx = edi;  // @50_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @51_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @52_4b6440
  ecx = edx = 0;  // @53_4b6440
  ecx = edi;  // @54_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @55_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @56_4b6440
  ecx = edx = 0;  // @57_4b6440
  ecx = edi;  // @58_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @59_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @60_4b6440
  ecx = edx = 0;  // @61_4b6440
  ecx = edi;  // @62_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @63_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @64_4b6440
  ecx = edx = 0;  // @65_4b6440
  ecx = edi;  // @66_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @67_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @68_4b6440
  ecx = edx = 0;  // @69_4b6440
  ecx = edi;  // @70_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 364), &v, sizeof v); }  // @71_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @72_4b6440
  ecx = edx = 0;  // @73_4b6440
  ecx = edi;  // @74_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @75_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @76_4b6440
  ecx = edx = 0;  // @77_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 372), &v, sizeof v); }  // @79_4b6440
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @80_4b6440
  FL[0] = (edx & 0xff); FL[1] = (u32)(255);  // @81_4b6440
  if (FL[0] == FL[1]) goto L4b66b0;  // @82_4b6440
  ecx = (ecx & 0xffffff00u) | (((edx & 0xff)) & 0xff);  // @83_4b6440
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @84_4b6440
  FL[3] = (ecx & 0xff);  // @85_4b6440
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @86_4b6440
  if (FL[0] != FL[1]) goto L4b660a;  // @87_4b6440
  ecx = edi;  // @88_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @89_4b6440
  ecx = edx = 0;  // @90_4b6440
  ecx = edi;  // @91_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @92_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @93_4b6440
  ecx = edx = 0;  // @94_4b6440
  ecx = edi;  // @95_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @96_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @97_4b6440
  ecx = edx = 0;  // @98_4b6440
  ecx = edi;  // @99_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @100_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @101_4b6440
  ecx = edx = 0;  // @102_4b6440
  ecx = edi;  // @103_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @104_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @105_4b6440
  ecx = edx = 0;  // @106_4b6440
  ecx = edi;  // @107_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @108_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @109_4b6440
  ecx = edx = 0;  // @110_4b6440
  ecx = edi;  // @111_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @112_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @113_4b6440
  ecx = edx = 0;  // @114_4b6440
  ecx = edi;  // @115_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @116_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @117_4b6440
  ecx = edx = 0;  // @118_4b6440
  ecx = edi;  // @119_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @120_4b6440
  eax = ext_4e5e80_thiscall1(ecx);  // @121_4b6440
  ecx = edx = 0;  // @122_4b6440
  ecx = edi;  // @123_4b6440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 276)) :: "st");  // @124_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @125_4b6440
  ecx = edx = 0;  // @126_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 276) + 0), 4); v; });  // @127_4b6440
  X0[1] = 0;  // @128_4b6440
  X0[2] = 0;  // @129_4b6440
  X0[3] = 0;  // @130_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @131_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 276) + 0), &X0[0], 4);  // @132_4b6440
  goto L4b6710;  // @133_4b6440
  L4b660a:;
  FL[0] = (edx & 0xff); FL[1] = (u32)(255);  // @135_4b6440
  if (FL[0] == FL[1]) goto L4b66b0;  // @136_4b6440
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) & (u32)(63))) & 0xff);  // @137_4b6440
  FL[3] = (edx & 0xff);  // @138_4b6440
  FL[0] = (edx & 0xff); FL[1] = (u32)(3);  // @139_4b6440
  if (FL[0] != FL[1]) goto L4b66b0;  // @140_4b6440
  ecx = edi;  // @141_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @142_4b6440
  ecx = edx = 0;  // @143_4b6440
  ecx = edi;  // @144_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @145_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @146_4b6440
  ecx = edx = 0;  // @147_4b6440
  ecx = edi;  // @148_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @149_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @150_4b6440
  ecx = edx = 0;  // @151_4b6440
  ecx = edi;  // @152_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @153_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @154_4b6440
  ecx = edx = 0;  // @155_4b6440
  ecx = edi;  // @156_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @157_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @158_4b6440
  ecx = edx = 0;  // @159_4b6440
  ecx = edi;  // @160_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @161_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @162_4b6440
  ecx = edx = 0;  // @163_4b6440
  ecx = edi;  // @164_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @165_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @166_4b6440
  ecx = edx = 0;  // @167_4b6440
  ecx = edi;  // @168_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @169_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @170_4b6440
  ecx = edx = 0;  // @171_4b6440
  ecx = edi;  // @172_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @173_4b6440
  eax = ext_4e5e80_thiscall1(ecx);  // @174_4b6440
  ecx = edx = 0;  // @175_4b6440
  ecx = edi;  // @176_4b6440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 276)) :: "st");  // @177_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @178_4b6440
  ecx = edx = 0;  // @179_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 276) + 0), 4); v; });  // @180_4b6440
  X0[1] = 0;  // @181_4b6440
  X0[2] = 0;  // @182_4b6440
  X0[3] = 0;  // @183_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @184_4b6440
  __builtin_memcpy((void *)((u32)(EBP - 276) + 0), &X0[0], 4);  // @185_4b6440
  goto L4b6710;  // @186_4b6440
  L4b66b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 376), sizeof v); (u32)v; });  // @188_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @189_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 380), sizeof v); (u32)v; });  // @190_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @191_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 384), sizeof v); (u32)v; });  // @192_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @193_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 388), sizeof v); (u32)v; });  // @194_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @195_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 392), sizeof v); (u32)v; });  // @196_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @197_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 396), sizeof v); (u32)v; });  // @198_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @199_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 400), sizeof v); (u32)v; });  // @200_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @201_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @202_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @203_4b6440
  L4b6710:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @205_4b6440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @206_4b6440
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @207_4b6440
  if (FL[0] == FL[1]) goto L4b673f;  // @208_4b6440
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @209_4b6440
  FL[3] = (eax & 0xff);  // @210_4b6440
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @211_4b6440
  if (FL[0] != FL[1]) goto L4b673f;  // @212_4b6440
  ecx = edi;  // @213_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @214_4b6440
  ecx = edx = 0;  // @215_4b6440
  eax = (eax - (u32)(0));  // @216_4b6440
  FL[3] = eax;  // @217_4b6440
  if (FL[3] == 0) goto L4b6738;  // @218_4b6440
  eax = (eax - (u32)(1));  // @219_4b6440
  FL[3] = eax;  // @220_4b6440
  if (FL[3] != 0) goto L4b673f;  // @221_4b6440
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @222_4b6440
  goto L4b673f;  // @223_4b6440
  L4b6738:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @225_4b6440
  L4b673f:;
  ecx = edi;  // @227_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @228_4b6440
  ecx = edx = 0;  // @229_4b6440
  ecx = edi;  // @230_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 133), &v, sizeof v); }  // @231_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @232_4b6440
  ecx = edx = 0;  // @233_4b6440
  ecx = edi;  // @234_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @235_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @236_4b6440
  ecx = edx = 0;  // @237_4b6440
  ecx = edi;  // @238_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @239_4b6440
  eax = ext_4e5ea0_thiscall1(ecx);  // @240_4b6440
  ecx = edx = 0;  // @241_4b6440
  FL[2] = (eax & eax);  // @242_4b6440
  if (FL[2] == 0) goto L4b67a8;  // @243_4b6440
  PV[0] = (u32)(eax);  // @244_4b6440
  ecx = (u32)(EBP - 144);  // @245_4b6440
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @246_4b6440
  ecx = edx = 0;  // @247_4b6440
  eax = (u32)(EBP - 144);  // @248_4b6440
  reg.state = (s32)((u32)(0));  // @249_4b6440
  PV[1] = (u32)(eax);  // @250_4b6440
  ecx = (u32)(esi + 149);  // @251_4b6440
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @252_4b6440
  ecx = edx = 0;  // @253_4b6440
  ecx = (u32)(EBP - 144);  // @254_4b6440
  reg.state = (s32)((u32)(4294967295));  // @255_4b6440
  eax = ext_4cbec0_thiscall1(ecx);  // @256_4b6440
  ecx = edx = 0;  // @257_4b6440
  L4b67a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @259_4b6440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @260_4b6440
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @261_4b6440
  if (FL[0] == FL[1]) goto L4b67ee;  // @262_4b6440
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @263_4b6440
  FL[3] = (eax & 0xff);  // @264_4b6440
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @265_4b6440
  if (FL[0] != FL[1]) goto L4b67ee;  // @266_4b6440
  ecx = edi;  // @267_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @268_4b6440
  ecx = edx = 0;  // @269_4b6440
  eax = (eax - (u32)(0));  // @270_4b6440
  FL[3] = eax;  // @271_4b6440
  if (FL[3] == 0) goto L4b67e4;  // @272_4b6440
  eax = (eax - (u32)(1));  // @273_4b6440
  FL[3] = eax;  // @274_4b6440
  if (FL[3] == 0) goto L4b67d8;  // @275_4b6440
  eax = (eax - (u32)(1));  // @276_4b6440
  FL[3] = eax;  // @277_4b6440
  if (FL[3] != 0) goto L4b67ee;  // @278_4b6440
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @279_4b6440
  goto L4b67ee;  // @280_4b6440
  L4b67d8:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @282_4b6440
  goto L4b67ee;  // @283_4b6440
  L4b67e4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @285_4b6440
  L4b67ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @287_4b6440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @288_4b6440
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @289_4b6440
  if (FL[0] == FL[1]) goto L4b680e;  // @290_4b6440
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @291_4b6440
  FL[3] = (eax & 0xff);  // @292_4b6440
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @293_4b6440
  if (FL[0] != FL[1]) goto L4b680e;  // @294_4b6440
  ecx = edi;  // @295_4b6440
  eax = ext_4e5e60_thiscall1(ecx);  // @296_4b6440
  ecx = edx = 0;  // @297_4b6440
  FL[2] = (eax & eax);  // @298_4b6440
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @299_4b6440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @300_4b6440
  L4b680e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 312), sizeof v); (u32)v; });  // @302_4b6440
  eax = (eax << (u32)(4));  // @303_4b6440
  FL[3] = eax;  // @304_4b6440
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 312), sizeof v); (u32)v; }));  // @305_4b6440
  FL[3] = eax;  // @306_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @307_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @308_4b6440
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; });  // @309_4b6440
  X1[1] = 0;  // @310_4b6440
  X1[2] = 0;  // @311_4b6440
  X1[3] = 0;  // @312_4b6440
  X0[0] = F2U((float)(s32)X0[0]);  // @313_4b6440
  X0[1] = F2U((float)(s32)X0[1]);  // @314_4b6440
  X0[2] = F2U((float)(s32)X0[2]);  // @315_4b6440
  X0[3] = F2U((float)(s32)X0[3]);  // @316_4b6440
  ecx = (u32)(ecx + eax*4);  // @317_4b6440
  eax = ecx;  // @318_4b6440
  eax = (eax << (u32)(4));  // @319_4b6440
  FL[3] = eax;  // @320_4b6440
  eax = (eax - ecx);  // @321_4b6440
  FL[3] = eax;  // @322_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 320), sizeof v); (u32)v; });  // @323_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @324_4b6440
  eax = (u32)(ecx + eax*4);  // @325_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @326_4b6440
  X7[0] = eax; X7[1] = X7[2] = X7[3] = 0;  // @327_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @328_4b6440
  eax = (eax << (u32)(4));  // @329_4b6440
  FL[3] = eax;  // @330_4b6440
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }));  // @331_4b6440
  FL[3] = eax;  // @332_4b6440
  X7[0] = F2U((float)(s32)X7[0]);  // @333_4b6440
  X7[1] = F2U((float)(s32)X7[1]);  // @334_4b6440
  X7[2] = F2U((float)(s32)X7[2]);  // @335_4b6440
  X7[3] = F2U((float)(s32)X7[3]);  // @336_4b6440
  ecx = (u32)(ecx + eax*4);  // @337_4b6440
  eax = ecx;  // @338_4b6440
  eax = (eax << (u32)(4));  // @339_4b6440
  FL[3] = eax;  // @340_4b6440
  eax = (eax - ecx);  // @341_4b6440
  FL[3] = eax;  // @342_4b6440
  X7[0] = F2U(U2F(X7[0]) + U2F(X0[0]));  // @343_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 336), sizeof v); (u32)v; });  // @344_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 340), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @345_4b6440
  X0[0] = F2U((float)(s32)X0[0]);  // @346_4b6440
  X0[1] = F2U((float)(s32)X0[1]);  // @347_4b6440
  X0[2] = F2U((float)(s32)X0[2]);  // @348_4b6440
  X0[3] = F2U((float)(s32)X0[3]);  // @349_4b6440
  eax = (u32)(ecx + eax*4);  // @350_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @351_4b6440
  X3[0] = eax; X3[1] = X3[2] = X3[3] = 0;  // @352_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @353_4b6440
  eax = (eax << (u32)(4));  // @354_4b6440
  FL[3] = eax;  // @355_4b6440
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; }));  // @356_4b6440
  FL[3] = eax;  // @357_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @358_4b6440
  X3[0] = F2U((float)(s32)X3[0]);  // @359_4b6440
  X3[1] = F2U((float)(s32)X3[1]);  // @360_4b6440
  X3[2] = F2U((float)(s32)X3[2]);  // @361_4b6440
  X3[3] = F2U((float)(s32)X3[3]);  // @362_4b6440
  ecx = (u32)(ecx + eax*4);  // @363_4b6440
  eax = ecx;  // @364_4b6440
  eax = (eax << (u32)(4));  // @365_4b6440
  FL[3] = eax;  // @366_4b6440
  eax = (eax - ecx);  // @367_4b6440
  FL[3] = eax;  // @368_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 352), sizeof v); (u32)v; });  // @369_4b6440
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @370_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @371_4b6440
  X0[0] = F2U((float)(s32)X0[0]);  // @372_4b6440
  X0[1] = F2U((float)(s32)X0[1]);  // @373_4b6440
  X0[2] = F2U((float)(s32)X0[2]);  // @374_4b6440
  X0[3] = F2U((float)(s32)X0[3]);  // @375_4b6440
  eax = (u32)(ecx + eax*4);  // @376_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 364), sizeof v); (u32)v; });  // @377_4b6440
  X4[0] = eax; X4[1] = X4[2] = X4[3] = 0;  // @378_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; });  // @379_4b6440
  eax = (eax << (u32)(4));  // @380_4b6440
  FL[3] = eax;  // @381_4b6440
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; }));  // @382_4b6440
  FL[3] = eax;  // @383_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @384_4b6440
  X4[0] = F2U((float)(s32)X4[0]);  // @385_4b6440
  X4[1] = F2U((float)(s32)X4[1]);  // @386_4b6440
  X4[2] = F2U((float)(s32)X4[2]);  // @387_4b6440
  X4[3] = F2U((float)(s32)X4[3]);  // @388_4b6440
  ecx = (u32)(ecx + eax*4);  // @389_4b6440
  eax = ecx;  // @390_4b6440
  eax = (eax << (u32)(4));  // @391_4b6440
  FL[3] = eax;  // @392_4b6440
  eax = (eax - ecx);  // @393_4b6440
  FL[3] = eax;  // @394_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 368), sizeof v); (u32)v; });  // @395_4b6440
  X4[0] = F2U(U2F(X4[0]) + U2F(X0[0]));  // @396_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @397_4b6440
  X0[0] = F2U((float)(s32)X0[0]);  // @398_4b6440
  X0[1] = F2U((float)(s32)X0[1]);  // @399_4b6440
  X0[2] = F2U((float)(s32)X0[2]);  // @400_4b6440
  X0[3] = F2U((float)(s32)X0[3]);  // @401_4b6440
  eax = (u32)(ecx + eax*4);  // @402_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @403_4b6440
  X5[0] = eax; X5[1] = X5[2] = X5[3] = 0;  // @404_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @405_4b6440
  eax = (eax << (u32)(4));  // @406_4b6440
  FL[3] = eax;  // @407_4b6440
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }));  // @408_4b6440
  FL[3] = eax;  // @409_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @410_4b6440
  X5[0] = F2U((float)(s32)X5[0]);  // @411_4b6440
  X5[1] = F2U((float)(s32)X5[1]);  // @412_4b6440
  X5[2] = F2U((float)(s32)X5[2]);  // @413_4b6440
  X5[3] = F2U((float)(s32)X5[3]);  // @414_4b6440
  ecx = (u32)(ecx + eax*4);  // @415_4b6440
  eax = ecx;  // @416_4b6440
  eax = (eax << (u32)(4));  // @417_4b6440
  FL[3] = eax;  // @418_4b6440
  eax = (eax - ecx);  // @419_4b6440
  FL[3] = eax;  // @420_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @421_4b6440
  X5[0] = F2U(U2F(X5[0]) + U2F(X0[0]));  // @422_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @423_4b6440
  X0[0] = F2U((float)(s32)X0[0]);  // @424_4b6440
  X0[1] = F2U((float)(s32)X0[1]);  // @425_4b6440
  X0[2] = F2U((float)(s32)X0[2]);  // @426_4b6440
  X0[3] = F2U((float)(s32)X0[3]);  // @427_4b6440
  eax = (u32)(ecx + eax*4);  // @428_4b6440
  X6[0] = eax; X6[1] = X6[2] = X6[3] = 0;  // @429_4b6440
  X6[0] = F2U((float)(s32)X6[0]);  // @430_4b6440
  X6[1] = F2U((float)(s32)X6[1]);  // @431_4b6440
  X6[2] = F2U((float)(s32)X6[2]);  // @432_4b6440
  X6[3] = F2U((float)(s32)X6[3]);  // @433_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @434_4b6440
  X6[0] = F2U(U2F(X6[0]) + U2F(X0[0]));  // @435_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @436_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; });  // @437_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 308), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @438_4b6440
  eax = (eax << (u32)(4));  // @439_4b6440
  FL[3] = eax;  // @440_4b6440
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }));  // @441_4b6440
  FL[3] = eax;  // @442_4b6440
  X0[0] = F2U((float)(s32)X0[0]);  // @443_4b6440
  X0[1] = F2U((float)(s32)X0[1]);  // @444_4b6440
  X0[2] = F2U((float)(s32)X0[2]);  // @445_4b6440
  X0[3] = F2U((float)(s32)X0[3]);  // @446_4b6440
  ecx = (u32)(ecx + eax*4);  // @447_4b6440
  eax = ecx;  // @448_4b6440
  eax = (eax << (u32)(4));  // @449_4b6440
  FL[3] = eax;  // @450_4b6440
  eax = (eax - ecx);  // @451_4b6440
  FL[3] = eax;  // @452_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @453_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; });  // @454_4b6440
  eax = (u32)(ecx + eax*4);  // @455_4b6440
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; });  // @456_4b6440
  X1[1] = 0;  // @457_4b6440
  X1[2] = 0;  // @458_4b6440
  X1[3] = 0;  // @459_4b6440
  X2[0] = eax; X2[1] = X2[2] = X2[3] = 0;  // @460_4b6440
  X2[0] = F2U((float)(s32)X2[0]);  // @461_4b6440
  X2[1] = F2U((float)(s32)X2[1]);  // @462_4b6440
  X2[2] = F2U((float)(s32)X2[2]);  // @463_4b6440
  X2[3] = F2U((float)(s32)X2[3]);  // @464_4b6440
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @465_4b6440
  X0[0] = X7[0];  // @466_4b6440
  X0[1] = X7[1];  // @467_4b6440
  X0[2] = X7[2];  // @468_4b6440
  X0[3] = X7[3];  // @469_4b6440
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @470_4b6440
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @471_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @472_4b6440
  if (((!(U2F(X7[0]) >= U2F(X3[0]))) || (!((U2F(X7[0]) < U2F(X3[0])) || (U2F(X7[0]) > U2F(X3[0])))))) goto L4b69c6;  // @473_4b6440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @474_4b6440
  goto L4b69d5;  // @475_4b6440
  L4b69c6:;
  X3[0] = F2U(U2F(X3[0]) - U2F(X7[0]));  // @477_4b6440
  X3[0] = F2U(U2F(X3[0]) * U2F(X1[0]));  // @478_4b6440
  { float f_ = U2F(X3[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @479_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @480_4b6440
  L4b69d5:;
  X4[0] = F2U(U2F(X4[0]) * U2F(X1[0]));  // @482_4b6440
  X5[0] = F2U(U2F(X5[0]) * U2F(X1[0]));  // @483_4b6440
  { float f_ = U2F(X4[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @484_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @485_4b6440
  { float f_ = U2F(X5[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @486_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @487_4b6440
  if ((!(U2F(X6[0]) >= U2F(X2[0])))) goto L4b69f9;  // @488_4b6440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @489_4b6440
  goto L4b6a1d;  // @490_4b6440
  L4b69f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 120), sizeof v); (u32)v; });  // @492_4b6440
  X2[0] = F2U(U2F(X2[0]) - U2F(X6[0]));  // @493_4b6440
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @494_4b6440
  X0[0] = X6[0];  // @495_4b6440
  X0[1] = X6[1];  // @496_4b6440
  X0[2] = X6[2];  // @497_4b6440
  X0[3] = X6[3];  // @498_4b6440
  X0[0] = F2U(U2F(X0[0]) - U2F(X7[0]));  // @499_4b6440
  X2[0] = F2U(U2F(X2[0]) * U2F(X1[0]));  // @500_4b6440
  __builtin_memcpy((void *)((u32)(esi + 96) + 0), &X0[0], 4);  // @501_4b6440
  { float f_ = U2F(X2[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @502_4b6440
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @503_4b6440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @504_4b6440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @505_4b6440
  L4b6a1d:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 276) + 0), 4); v; });  // @507_4b6440
  X1[1] = 0;  // @508_4b6440
  X1[2] = 0;  // @509_4b6440
  X1[3] = 0;  // @510_4b6440
  X0[0] = 0;  // @511_4b6440
  X0[1] = 0;  // @512_4b6440
  X0[2] = 0;  // @513_4b6440
  X0[3] = 0;  // @514_4b6440
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L4b6a5a;  // @515_4b6440
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806064) + 0), 4); v; })));  // @516_4b6440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @517_4b6440
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @518_4b6440
  { double r_ = ext_634db2_dbl2(U2D(X0[0], X0[1]), U2D(X1[0], X1[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @519_4b6440
  ecx = edx = 0;  // @520_4b6440
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @521_4b6440
  X1[1] = 0;  // @522_4b6440
  X1[2] = 0;  // @523_4b6440
  X1[3] = 0;  // @524_4b6440
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @525_4b6440
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @526_4b6440
  __builtin_memcpy((void *)((u32)(esi + 84) + 0), &X1[0], 4);  // @527_4b6440
  L4b6a5a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @529_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @530_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @531_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 276), sizeof v); (u32)v; });  // @532_4b6440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6840116), (u32)(0), (u32)(6889180), (u32)(2874));  // @533_4b6440
  ecx = edx = 0;  // @534_4b6440
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 277), &v, sizeof v); }  // @535_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @536_4b6440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @537_4b6440
  FL[2] = (ecx & ecx);  // @538_4b6440
  if (FL[2] == 0) goto L4b6b60;  // @539_4b6440
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 137), sizeof v); (u32)v; });  // @540_4b6440
  FL[2] = (edx & edx);  // @541_4b6440
  if (FL[2] != 0) goto L4b6ab2;  // @542_4b6440
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 133), sizeof v); (u32)v; });  // @543_4b6440
  FL[2] = (edx & edx);  // @544_4b6440
  if (FL[2] == 0) goto L4b6b60;  // @545_4b6440
  L4b6ab2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @547_4b6440
  PV[2] = (u32)(edx);  // @548_4b6440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 120), sizeof v); (u32)v; });  // @549_4b6440
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[2]);  // @550_4b6440
  ecx = edx = 0;  // @551_4b6440
  edx = eax;  // @552_4b6440
  FL[2] = (edx & edx);  // @553_4b6440
  if (FL[2] == 0) goto L4b6b60;  // @554_4b6440
  ecx = edx;  // @555_4b6440
  edi = (u32)(ecx + 1);  // @556_4b6440
  L4b6ad0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @558_4b6440
  ecx = (ecx + 1);  // @559_4b6440
  FL[3] = ecx;  // @560_4b6440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @561_4b6440
  if (FL[2] != 0) goto L4b6ad0;  // @562_4b6440
  eax = (u32)(0);  // @563_4b6440
  ecx = (ecx - edi);  // @564_4b6440
  FL[3] = ecx;  // @565_4b6440
  if (FL[3] == 0) goto L4b6aeb;  // @566_4b6440
  L4b6ae0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @568_4b6440
  if (FL[0] == FL[1]) goto L4b6aeb;  // @569_4b6440
  eax = (eax + 1);  // @570_4b6440
  FL[3] = eax;  // @571_4b6440
  FL[0] = eax; FL[1] = ecx;  // @572_4b6440
  if (FL[0] < FL[1]) goto L4b6ae0;  // @573_4b6440
  L4b6aeb:;
  eax = (eax + 1);  // @575_4b6440
  FL[3] = eax;  // @576_4b6440
  FL[0] = eax; FL[1] = ecx;  // @577_4b6440
  if (FL[0] >= FL[1]) goto L4b6afb;  // @578_4b6440
  L4b6af0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @580_4b6440
  if (FL[0] == FL[1]) goto L4b6afb;  // @581_4b6440
  eax = (eax + 1);  // @582_4b6440
  FL[3] = eax;  // @583_4b6440
  FL[0] = eax; FL[1] = ecx;  // @584_4b6440
  if (FL[0] < FL[1]) goto L4b6af0;  // @585_4b6440
  L4b6afb:;
  ecx = (u32)(eax + edx);  // @587_4b6440
  edx = (u32)(EBP - 272);  // @588_4b6440
  edx = (edx - ecx);  // @589_4b6440
  FL[3] = edx;  // @590_4b6440
  L4b6b06:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @592_4b6440
  ecx = (u32)(ecx + 1);  // @593_4b6440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + edx - 1), &v, sizeof v); }  // @594_4b6440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @595_4b6440
  if (FL[2] != 0) goto L4b6b06;  // @596_4b6440
  ecx = (u32)(EBP - 272);  // @597_4b6440
  edx = (u32)(ecx + 1);  // @598_4b6440
  L4b6b20:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @600_4b6440
  ecx = (ecx + 1);  // @601_4b6440
  FL[3] = ecx;  // @602_4b6440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @603_4b6440
  if (FL[2] != 0) goto L4b6b20;  // @604_4b6440
  ecx = (ecx - edx);  // @605_4b6440
  FL[3] = ecx;  // @606_4b6440
  ecx = (ecx + (u32)(-4));  // @607_4b6440
  FL[3] = ecx;  // @608_4b6440
  FL[0] = ecx; FL[1] = (u32)(256);  // @609_4b6440
  if (FL[0] >= FL[1]) goto L4b6b7d;  // @610_4b6440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + ecx - 272), &v, sizeof v); }  // @611_4b6440
  ecx = (u32)(EBP - 272);  // @612_4b6440
  eax = ecx;  // @613_4b6440
  esi = (esi - eax);  // @614_4b6440
  FL[3] = esi;  // @615_4b6440
  L4b6b50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @617_4b6440
  ecx = (u32)(ecx + 1);  // @618_4b6440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi + 290), &v, sizeof v); }  // @619_4b6440
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @620_4b6440
  if (FL[2] != 0) goto L4b6b50;  // @621_4b6440
  L4b6b60:;
  SEH_LEAVE();  // @623_4b6440
  ext_633654(G(u32, 0x6f5630));  // @624_4b6440
  return eax;  // @625_4b6440
  L4b6b7d:;
  eax = ext_634047_cdecl0();  // @627_4b6440
  ecx = edx = 0;  // @628_4b6440
}
PCREG(4b6440, lifted_4b6440);

