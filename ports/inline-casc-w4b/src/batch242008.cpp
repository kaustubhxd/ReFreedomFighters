// batch242008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c0e20(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c0e20
  esi = ecx;  // @1_4c0e20
  ecx = edi;  // @2_4c0e20
  eax = ext_4e5e80_thiscall1(ecx);  // @3_4c0e20
  ecx = edx = 0;  // @4_4c0e20
  ecx = edi;  // @5_4c0e20
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 72)) :: "st");  // @6_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @7_4c0e20
  ecx = edx = 0;  // @8_4c0e20
  ecx = edi;  // @9_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @10_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4c0e20
  ecx = edx = 0;  // @12_4c0e20
  ecx = edi;  // @13_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @14_4c0e20
  eax = ext_4e5e80_thiscall1(ecx);  // @15_4c0e20
  ecx = edx = 0;  // @16_4c0e20
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 84)) :: "st");  // @17_4c0e20
  ecx = edi;  // @18_4c0e20
  eax = ext_4e5e80_thiscall1(ecx);  // @19_4c0e20
  ecx = edx = 0;  // @20_4c0e20
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 88)) :: "st");  // @21_4c0e20
  ecx = edi;  // @22_4c0e20
  eax = ext_4e5e80_thiscall1(ecx);  // @23_4c0e20
  ecx = edx = 0;  // @24_4c0e20
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 92)) :: "st");  // @25_4c0e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @27_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @28_4c0e20
  if (FL[0] == FL[1]) goto L4c0e80;  // @29_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @30_4c0e20
  FL[3] = (eax & 0xff);  // @31_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @32_4c0e20
  if (FL[0] != FL[1]) goto L4c0e80;  // @33_4c0e20
  ecx = edi;  // @34_4c0e20
  eax = ext_4e5e80_thiscall1(ecx);  // @35_4c0e20
  ecx = edx = 0;  // @36_4c0e20
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 96)) :: "st");  // @37_4c0e20
  goto L4c0e87;  // @38_4c0e20
  L4c0e80:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @40_4c0e20
  L4c0e87:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @43_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @44_4c0e20
  if (FL[0] == FL[1]) goto L4c0ea1;  // @45_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @46_4c0e20
  FL[3] = (eax & 0xff);  // @47_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @48_4c0e20
  if (FL[0] != FL[1]) goto L4c0ea1;  // @49_4c0e20
  ecx = edi;  // @50_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @51_4c0e20
  ecx = edx = 0;  // @52_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @53_4c0e20
  goto L4c0ea8;  // @54_4c0e20
  L4c0ea1:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @56_4c0e20
  L4c0ea8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @59_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @60_4c0e20
  if (FL[0] == FL[1]) goto L4c0ec7;  // @61_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @62_4c0e20
  FL[3] = (eax & 0xff);  // @63_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @64_4c0e20
  if (FL[0] != FL[1]) goto L4c0ec7;  // @65_4c0e20
  ecx = edi;  // @66_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @67_4c0e20
  ecx = edx = 0;  // @68_4c0e20
  FL[2] = (eax & eax);  // @69_4c0e20
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @70_4c0e20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @71_4c0e20
  goto L4c0ecb;  // @72_4c0e20
  L4c0ec7:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @74_4c0e20
  L4c0ecb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @77_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @78_4c0e20
  if (FL[0] == FL[1]) goto L4c0ee5;  // @79_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @80_4c0e20
  FL[3] = (eax & 0xff);  // @81_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @82_4c0e20
  if (FL[0] != FL[1]) goto L4c0ee5;  // @83_4c0e20
  ecx = edi;  // @84_4c0e20
  eax = ext_4e5e80_thiscall1(ecx);  // @85_4c0e20
  ecx = edx = 0;  // @86_4c0e20
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 105)) :: "st");  // @87_4c0e20
  goto L4c0eec;  // @88_4c0e20
  L4c0ee5:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @90_4c0e20
  L4c0eec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @92_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @93_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @94_4c0e20
  if (FL[0] == FL[1]) goto L4c0f06;  // @95_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @96_4c0e20
  FL[3] = (eax & 0xff);  // @97_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @98_4c0e20
  if (FL[0] != FL[1]) goto L4c0f06;  // @99_4c0e20
  ecx = edi;  // @100_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @101_4c0e20
  ecx = edx = 0;  // @102_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @103_4c0e20
  goto L4c0f0d;  // @104_4c0e20
  L4c0f06:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @106_4c0e20
  L4c0f0d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @108_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @109_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @110_4c0e20
  if (FL[0] == FL[1]) goto L4c0f50;  // @111_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @112_4c0e20
  FL[3] = (eax & 0xff);  // @113_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @114_4c0e20
  if (FL[0] != FL[1]) goto L4c0f50;  // @115_4c0e20
  ecx = edi;  // @116_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @117_4c0e20
  ecx = edx = 0;  // @118_4c0e20
  FL[0] = eax; FL[1] = (u32)(3);  // @119_4c0e20
  if (FL[0] > FL[1]) goto L4c0f50;  // @120_4c0e20
  switch (eax) {  // @121_4c0e20
  case 0: goto L4c0f2e;  // @122_4c0e20
  case 1: goto L4c0f37;  // @123_4c0e20
  case 2: goto L4c0f40;  // @124_4c0e20
  case 3: goto L4c0f49;  // @125_4c0e20
  default: __builtin_trap(); }  // @126_4c0e20
  L4c0f2e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @128_4c0e20
  goto L4c0f50;  // @129_4c0e20
  L4c0f37:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @131_4c0e20
  goto L4c0f50;  // @132_4c0e20
  L4c0f40:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @134_4c0e20
  goto L4c0f50;  // @135_4c0e20
  L4c0f49:;
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @137_4c0e20
  L4c0f50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @139_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @140_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @141_4c0e20
  if (FL[0] == FL[1]) goto L4c0f6a;  // @142_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @143_4c0e20
  FL[3] = (eax & 0xff);  // @144_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @145_4c0e20
  if (FL[0] != FL[1]) goto L4c0f6a;  // @146_4c0e20
  ecx = edi;  // @147_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @148_4c0e20
  ecx = edx = 0;  // @149_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @150_4c0e20
  goto L4c0f71;  // @151_4c0e20
  L4c0f6a:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @153_4c0e20
  L4c0f71:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @155_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @156_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @157_4c0e20
  if (FL[0] == FL[1]) goto L4c0f8b;  // @158_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @159_4c0e20
  FL[3] = (eax & 0xff);  // @160_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @161_4c0e20
  if (FL[0] != FL[1]) goto L4c0f8b;  // @162_4c0e20
  ecx = edi;  // @163_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @164_4c0e20
  ecx = edx = 0;  // @165_4c0e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 125), &v, sizeof v); }  // @166_4c0e20
  goto L4c0f92;  // @167_4c0e20
  L4c0f8b:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 125), &v, sizeof v); }  // @169_4c0e20
  L4c0f92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @171_4c0e20
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @172_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @173_4c0e20
  if (FL[0] == FL[1]) goto L4c1022;  // @174_4c0e20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @175_4c0e20
  FL[3] = (eax & 0xff);  // @176_4c0e20
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @177_4c0e20
  if (FL[0] != FL[1]) goto L4c1022;  // @178_4c0e20
  ecx = edi;  // @179_4c0e20
  eax = ext_4e5e60_thiscall1(ecx);  // @180_4c0e20
  ecx = edx = 0;  // @181_4c0e20
  FL[0] = eax; FL[1] = (u32)(4);  // @182_4c0e20
  if (FL[0] > FL[1]) goto L4c1022;  // @183_4c0e20
  switch (eax) {  // @184_4c0e20
  case 0: goto L4c0fb7;  // @185_4c0e20
  case 1: goto L4c0fd0;  // @186_4c0e20
  case 2: goto L4c0fe9;  // @187_4c0e20
  case 3: goto L4c1002;  // @188_4c0e20
  case 4: goto L4c101b;  // @189_4c0e20
  default: __builtin_trap(); }  // @190_4c0e20
  L4c0fb7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_4c0e20
  ecx = esi;  // @193_4c0e20
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @194_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @195_4c0e20
  ecx = edx = 0;  // @196_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @197_4c0e20
  return eax;  // @198_4c0e20
  L4c0fd0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_4c0e20
  ecx = esi;  // @201_4c0e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @202_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @203_4c0e20
  ecx = edx = 0;  // @204_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @205_4c0e20
  return eax;  // @206_4c0e20
  L4c0fe9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @208_4c0e20
  ecx = esi;  // @209_4c0e20
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @210_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @211_4c0e20
  ecx = edx = 0;  // @212_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @213_4c0e20
  return eax;  // @214_4c0e20
  L4c1002:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @216_4c0e20
  ecx = esi;  // @217_4c0e20
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @218_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @219_4c0e20
  ecx = edx = 0;  // @220_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @221_4c0e20
  return eax;  // @222_4c0e20
  L4c101b:;
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @224_4c0e20
  L4c1022:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @226_4c0e20
  ecx = esi;  // @227_4c0e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @228_4c0e20
  ecx = edx = 0;  // @229_4c0e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @230_4c0e20
  return eax;  // @231_4c0e20
}
PCREG(4c0e20, lifted_4c0e20);

extern "C" u32 THISCALL lifted_4fe0f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4fe0f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @1_4fe0f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 103), &v, sizeof v); }  // @2_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6932052), (u32)(0), (u32)(6932004), (u32)(81));  // @6_4fe0f0
  ecx = edx = 0;  // @7_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 81), &v, sizeof v); }  // @8_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6932072), (u32)(0), (u32)(6932004), (u32)(82));  // @12_4fe0f0
  ecx = edx = 0;  // @13_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 83), &v, sizeof v); }  // @14_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6932092), (u32)(0), (u32)(6932004), (u32)(83));  // @18_4fe0f0
  ecx = edx = 0;  // @19_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 85), &v, sizeof v); }  // @20_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @22_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6931080), (u32)(0), (u32)(6932004), (u32)(84));  // @24_4fe0f0
  ecx = edx = 0;  // @25_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 87), &v, sizeof v); }  // @26_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6931116), (u32)(0), (u32)(6932004), (u32)(85));  // @30_4fe0f0
  ecx = edx = 0;  // @31_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 89), &v, sizeof v); }  // @32_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6852500), (u32)(0), (u32)(6932004), (u32)(86));  // @36_4fe0f0
  ecx = edx = 0;  // @37_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 91), &v, sizeof v); }  // @38_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889456), (u32)(0), (u32)(6932004), (u32)(87));  // @42_4fe0f0
  ecx = edx = 0;  // @43_4fe0f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 93), &v, sizeof v); }  // @44_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4fe0f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @48_4fe0f0
  ecx = edx = 0;  // @49_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_4fe0f0
  esi = eax;  // @51_4fe0f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @52_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @53_4fe0f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[0], (u32)(16));  // @56_4fe0f0
  ecx = edx = 0;  // @57_4fe0f0
  PV[1] = (u32)(eax);  // @58_4fe0f0
  ecx = esi;  // @59_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6891148), PV[1]);  // @60_4fe0f0
  ecx = edx = 0;  // @61_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4fe0f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @65_4fe0f0
  ecx = edx = 0;  // @66_4fe0f0
  ecx = (u32)(EBP - 24);  // @67_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @68_4fe0f0
  PV[2] = (u32)(ecx);  // @69_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @70_4fe0f0
  ecx = eax;  // @71_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6838796), PV[2]);  // @72_4fe0f0
  ecx = edx = 0;  // @73_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @74_4fe0f0
  edx = (u32)(EBP - 20);  // @75_4fe0f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6932128) + 0), 4); v; });  // @76_4fe0f0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6932128) + 4), 4); v; });  // @77_4fe0f0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6932128) + 8), 4); v; });  // @78_4fe0f0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6932128) + 12), 4); v; });  // @79_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @80_4fe0f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 232), &v, sizeof v); }  // @81_4fe0f0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @82_4fe0f0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 4), &X0[1], 4);  // @83_4fe0f0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 8), &X0[2], 4);  // @84_4fe0f0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 12), &X0[3], 4);  // @85_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_4fe0f0
  PV[3] = (u32)(edx);  // @87_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[3]);  // @88_4fe0f0
  ecx = edx = 0;  // @89_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @90_4fe0f0
  PV[4] = (u32)(ecx);  // @91_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 580)))(ecx, (u32)(1061158912));  // @93_4fe0f0
  ecx = edx = 0;  // @94_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @95_4fe0f0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @96_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 212), &v, sizeof v); }  // @97_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 216), &v, sizeof v); }  // @98_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 220), &v, sizeof v); }  // @99_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 224), &v, sizeof v); }  // @100_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_4fe0f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @104_4fe0f0
  ecx = edx = 0;  // @105_4fe0f0
  ecx = (u32)(EBP - 24);  // @106_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @107_4fe0f0
  PV[5] = (u32)(ecx);  // @108_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @109_4fe0f0
  ecx = eax;  // @110_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(6890172), PV[5]);  // @111_4fe0f0
  ecx = edx = 0;  // @112_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @114_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_4fe0f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @116_4fe0f0
  ecx = edx = 0;  // @117_4fe0f0
  ecx = (u32)(EBP - 28);  // @118_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @119_4fe0f0
  PV[6] = (u32)(ecx);  // @120_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @121_4fe0f0
  ecx = eax;  // @122_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(6890184), PV[6]);  // @123_4fe0f0
  ecx = edx = 0;  // @124_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @126_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_4fe0f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @128_4fe0f0
  ecx = edx = 0;  // @129_4fe0f0
  ecx = eax;  // @130_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @131_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 156)))(ecx, (u32)(6930968), (u32)(4));  // @132_4fe0f0
  ecx = edx = 0;  // @133_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_4fe0f0
  esi = eax;  // @135_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @136_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_4fe0f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 312)))(ecx);  // @138_4fe0f0
  ecx = edx = 0;  // @139_4fe0f0
  ecx = (u32)(EBP - 32);  // @140_4fe0f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @141_4fe0f0
  PV[7] = (u32)(ecx);  // @142_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @143_4fe0f0
  ecx = eax;  // @144_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(6930952), PV[7]);  // @145_4fe0f0
  ecx = edx = 0;  // @146_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @147_4fe0f0
  PV[8] = (u32)(ecx);  // @148_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_4fe0f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @150_4fe0f0
  X0[1] = 0;  // @151_4fe0f0
  X0[2] = 0;  // @152_4fe0f0
  X0[3] = 0;  // @153_4fe0f0
  PV[9] = X0[0];  // @154_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, PV[9]);  // @155_4fe0f0
  ecx = edx = 0;  // @156_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @157_4fe0f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @158_4fe0f0
  X0[1] = 0;  // @159_4fe0f0
  X0[2] = 0;  // @160_4fe0f0
  X0[3] = 0;  // @161_4fe0f0
  PV[10] = (u32)(ecx);  // @162_4fe0f0
  PV[11] = X0[0];  // @163_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[11]);  // @165_4fe0f0
  ecx = edx = 0;  // @166_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @167_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @168_4fe0f0
  eax = (eax << (u32)(8));  // @169_4fe0f0
  FL[3] = eax;  // @170_4fe0f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @171_4fe0f0
  FL[3] = eax;  // @172_4fe0f0
  eax = (eax << (u32)(8));  // @173_4fe0f0
  FL[3] = eax;  // @174_4fe0f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_4fe0f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @176_4fe0f0
  FL[3] = eax;  // @177_4fe0f0
  PV[12] = (u32)(eax);  // @178_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 540)))(ecx, PV[12]);  // @179_4fe0f0
  ecx = edx = 0;  // @180_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @181_4fe0f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @182_4fe0f0
  X0[1] = 0;  // @183_4fe0f0
  X0[2] = 0;  // @184_4fe0f0
  X0[3] = 0;  // @185_4fe0f0
  PV[13] = (u32)(ecx);  // @186_4fe0f0
  PV[14] = X0[0];  // @187_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @188_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[14]);  // @189_4fe0f0
  ecx = edx = 0;  // @190_4fe0f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @191_4fe0f0
  PV[15] = (u32)(ecx);  // @192_4fe0f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @193_4fe0f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 548)))(ecx, (u32)(1116130509));  // @194_4fe0f0
  ecx = edx = 0;  // @195_4fe0f0
  ext_633654(G(u32, 0x6f5630));  // @196_4fe0f0
  return eax;  // @197_4fe0f0
}
PCREG(4fe0f0, lifted_4fe0f0);

