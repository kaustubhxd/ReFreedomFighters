// batch252003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_63f030_stdcall1(u32) __asm__("ext_63f030");
extern "C" u32 THISCALL ext_63cc50_thiscall3(u32, u32, u32) __asm__("ext_63cc50");
extern "C" u32 THISCALL ext_63ef00_thiscall2(u32, u32) __asm__("ext_63ef00");
extern "C" u32 THISCALL ext_63f600_thiscall2(u32, u32) __asm__("ext_63f600");
extern "C" u32 THISCALL ext_64b3c0_thiscall2(u32, u32) __asm__("ext_64b3c0");
extern "C" u32 THISCALL ext_64c240_thiscall2(u32, u32) __asm__("ext_64c240");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_64b480(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  esi = ecx;  // @0_64b480
  eax = (u32)(esi + 40);  // @1_64b480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @2_64b480
  PV[0] = (u32)(eax);  // @3_64b480
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(65536));  // @4_64b480
    // @5_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65893), sizeof v); (u32)v; });  // @6_64b480
  FL[2] = (ecx & ecx);  // @7_64b480
  if (FL[2] == 0) goto L64b4b3;  // @8_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @10_64b480
  ecx = edx = 0;  // @11_64b480
  L64b4b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65965), sizeof v); (u32)v; });  // @13_64b480
  ecx = (u32)(esi + 65965);  // @14_64b480
  edx = (u32)(EBP - 36);  // @15_64b480
  PV[1] = (u32)(edx);  // @16_64b480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[1]);  // @17_64b480
  ecx = edx = 0;  // @18_64b480
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @19_64b480
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @20_64b480
  X0[2] = 0;  // @21_64b480
  X0[3] = 0;  // @22_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @23_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @24_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @25_64b480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @26_64b480
  FL[2] = (edi & edi);  // @27_64b480
  if (FL[2] == 0) goto L64b513;  // @28_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @29_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @30_64b480
  L64b4e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_64b480
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }); FL[1] = (u32)(6);  // @33_64b480
  if (FL[0] != FL[1]) goto L64b4f3;  // @34_64b480
  PV[2] = (u32)(ecx);  // @35_64b480
  ecx = esi;  // @36_64b480
  eax = ext_64b3c0_thiscall2(ecx, PV[2]);  // @37_64b480
  ecx = edx = 0;  // @38_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_64b480
  L64b4f3:;
  eax = (eax + 1);  // @41_64b480
  FL[3] = eax;  // @42_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @43_64b480
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_64b480
  if (FL[0] != FL[1]) goto L64b50c;  // @45_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @46_64b480
  FL[2] = (ebx & ebx);  // @47_64b480
  if (FL[2] == 0) goto L64b513;  // @48_64b480
  eax = 0;  // @49_64b480
  FL[3] = eax;  // @50_64b480
  edi = (u32)(ebx + 16);  // @51_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @52_64b480
  goto L64b50f;  // @53_64b480
  L64b50c:;
  edi = (edi + (u32)(4));  // @55_64b480
  FL[3] = edi;  // @56_64b480
  L64b50f:;
  FL[2] = (edi & edi);  // @58_64b480
  if (FL[2] != 0) goto L64b4e0;  // @59_64b480
  L64b513:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @61_64b480
  ecx = (u32)(esi + 12);  // @62_64b480
  edx = (u32)(EBP - 36);  // @63_64b480
  PV[3] = (u32)(edx);  // @64_64b480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[3]);  // @65_64b480
  ecx = edx = 0;  // @66_64b480
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @67_64b480
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @68_64b480
  X0[2] = 0;  // @69_64b480
  X0[3] = 0;  // @70_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @71_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @72_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @73_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @74_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @75_64b480
  FL[2] = (ebx & ebx);  // @76_64b480
  if (FL[2] == 0) goto L64b5d5;  // @77_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @78_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @79_64b480
  L64b540:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @81_64b480
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edi + 5), &v, sizeof v); }  // @82_64b480
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; });  // @83_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @85_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @86_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @87_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_64b480
  edx = (edx + (u32)(616));  // @89_64b480
  FL[3] = edx;  // @90_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @91_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @92_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @93_64b480
  eax = ecx;  // @94_64b480
  eax = (eax - edx);  // @95_64b480
  FL[3] = eax;  // @96_64b480
  eax = (eax - (u32)(8));  // @97_64b480
  FL[3] = eax;  // @98_64b480
  eax = (u32)((s32)eax >> (u32)(2));  // @99_64b480
  FL[3] = eax;  // @100_64b480
  eax = (eax & 0xffff);  // @101_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @102_64b480
  eax = (u32)(edx + 32776);  // @103_64b480
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @104_64b480
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @105_64b480
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @106_64b480
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = eax;  // @107_64b480
  if (FL[0] != FL[1]) goto L64b58c;  // @108_64b480
  eax = (u32)(edx + 8);  // @109_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @110_64b480
  L64b58c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @112_64b480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 6), &v, sizeof v); }  // @113_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @114_64b480
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 67), sizeof v); (u32)v; }) + (u32)(255))); __builtin_memcpy((void *)(u32)(eax + 67), &v, sizeof v); }  // @115_64b480
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 67), sizeof v); (u32)v; });  // @116_64b480
  if (FL[3] != 0) goto L64b5a8;  // @117_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @118_64b480
  PV[4] = (u32)(eax);  // @119_64b480
  eax = ext_63ef00_thiscall2(ecx, PV[4]);  // @120_64b480
  ecx = edx = 0;  // @121_64b480
  L64b5a8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @123_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @124_64b480
  ecx = (ecx + 1);  // @125_64b480
  FL[3] = ecx;  // @126_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @127_64b480
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @128_64b480
  if (FL[0] != FL[1]) goto L64b5ca;  // @129_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @130_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @131_64b480
  FL[2] = (eax & eax);  // @132_64b480
  if (FL[2] == 0) goto L64b5d5;  // @133_64b480
  ecx = 0;  // @134_64b480
  FL[3] = ecx;  // @135_64b480
  ebx = (u32)(eax + 16);  // @136_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @137_64b480
  goto L64b5cd;  // @138_64b480
  L64b5ca:;
  ebx = (ebx + (u32)(4));  // @140_64b480
  FL[3] = ebx;  // @141_64b480
  L64b5cd:;
  FL[2] = (ebx & ebx);  // @143_64b480
  if (FL[2] != 0) goto L64b540;  // @144_64b480
  L64b5d5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65905), sizeof v); (u32)v; });  // @146_64b480
  ecx = (u32)(esi + 65905);  // @147_64b480
  edx = (u32)(EBP - 36);  // @148_64b480
  PV[5] = (u32)(edx);  // @149_64b480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[5]);  // @150_64b480
  ecx = edx = 0;  // @151_64b480
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @152_64b480
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @153_64b480
  X0[2] = 0;  // @154_64b480
  X0[3] = 0;  // @155_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @156_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @157_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @158_64b480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @159_64b480
  FL[2] = (edi & edi);  // @160_64b480
  if (FL[2] == 0) goto L64b678;  // @161_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @162_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @163_64b480
  L64b605:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @165_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @167_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 616), sizeof v); (u32)v; });  // @168_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 620), sizeof v); (u32)v; });  // @169_64b480
  FL[0] = eax; FL[1] = ecx;  // @170_64b480
  if (FL[0] >= FL[1]) goto L64b62e;  // @171_64b480
  ecx = (ecx - eax);  // @172_64b480
  FL[3] = ecx;  // @173_64b480
  eax = (u32)(8192);  // @174_64b480
  ecx = (u32)((s32)ecx >> (u32)(2));  // @175_64b480
  FL[3] = ecx;  // @176_64b480
  eax = (eax - ecx);  // @177_64b480
  FL[3] = eax;  // @178_64b480
  goto L64b633;  // @179_64b480
  L64b62e:;
  eax = (eax - ecx);  // @181_64b480
  FL[3] = eax;  // @182_64b480
  eax = (u32)((s32)eax >> (u32)(2));  // @183_64b480
  FL[3] = eax;  // @184_64b480
  L64b633:;
  FL[0] = eax; FL[1] = (u32)(4096);  // @186_64b480
  if (FL[0] <= FL[1]) goto L64b64b;  // @187_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_64b480
  ecx = edx;  // @189_64b480
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @190_64b480
  eax = ext_63cc50_thiscall3(ecx, (u32)(0), PV[6]);  // @191_64b480
  ecx = edx = 0;  // @192_64b480
  L64b64b:;
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @194_64b480
  ecx = esi;  // @195_64b480
  eax = ext_64c240_thiscall2(ecx, PV[7]);  // @196_64b480
  ecx = edx = 0;  // @197_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @198_64b480
  edx = (edx + 1);  // @199_64b480
  FL[3] = edx;  // @200_64b480
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @201_64b480
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @202_64b480
  if (FL[0] != FL[1]) goto L64b671;  // @203_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @204_64b480
  FL[2] = (ebx & ebx);  // @205_64b480
  if (FL[2] == 0) goto L64b678;  // @206_64b480
  eax = 0;  // @207_64b480
  FL[3] = eax;  // @208_64b480
  edi = (u32)(ebx + 16);  // @209_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @210_64b480
  goto L64b674;  // @211_64b480
  L64b671:;
  edi = (edi + (u32)(4));  // @213_64b480
  FL[3] = edi;  // @214_64b480
  L64b674:;
  FL[2] = (edi & edi);  // @216_64b480
  if (FL[2] != 0) goto L64b605;  // @217_64b480
  L64b678:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65925), sizeof v); (u32)v; });  // @219_64b480
  ecx = (u32)(esi + 65925);  // @220_64b480
  edx = (u32)(EBP - 36);  // @221_64b480
  PV[8] = (u32)(edx);  // @222_64b480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[8]);  // @223_64b480
  ecx = edx = 0;  // @224_64b480
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @225_64b480
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @226_64b480
  X0[2] = 0;  // @227_64b480
  X0[3] = 0;  // @228_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @229_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @230_64b480
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @231_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @232_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @233_64b480
  FL[2] = (ebx & ebx);  // @234_64b480
  if (FL[2] == 0) goto L64b745;  // @235_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @236_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @237_64b480
  L64b6b0:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @239_64b480
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edi + 5), &v, sizeof v); }  // @240_64b480
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; });  // @241_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @242_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @243_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @244_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @245_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @246_64b480
  edx = (edx + (u32)(616));  // @247_64b480
  FL[3] = edx;  // @248_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @249_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @250_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @251_64b480
  eax = ecx;  // @252_64b480
  eax = (eax - edx);  // @253_64b480
  FL[3] = eax;  // @254_64b480
  eax = (eax - (u32)(8));  // @255_64b480
  FL[3] = eax;  // @256_64b480
  eax = (u32)((s32)eax >> (u32)(2));  // @257_64b480
  FL[3] = eax;  // @258_64b480
  eax = (eax & 0xffff);  // @259_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @260_64b480
  eax = (u32)(edx + 32776);  // @261_64b480
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @262_64b480
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @263_64b480
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @264_64b480
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = eax;  // @265_64b480
  if (FL[0] != FL[1]) goto L64b6fc;  // @266_64b480
  eax = (u32)(edx + 8);  // @267_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @268_64b480
  L64b6fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @270_64b480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 6), &v, sizeof v); }  // @271_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @272_64b480
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) + (u32)(255))); __builtin_memcpy((void *)(u32)(eax + 60), &v, sizeof v); }  // @273_64b480
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @274_64b480
  if (FL[3] != 0) goto L64b718;  // @275_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @276_64b480
  PV[9] = (u32)(eax);  // @277_64b480
  eax = ext_63f030_stdcall1(PV[9]);  // @278_64b480
  ecx = edx = 0;  // @279_64b480
  L64b718:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @281_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @282_64b480
  ecx = (ecx + 1);  // @283_64b480
  FL[3] = ecx;  // @284_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @285_64b480
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @286_64b480
  if (FL[0] != FL[1]) goto L64b73a;  // @287_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @288_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @289_64b480
  FL[2] = (eax & eax);  // @290_64b480
  if (FL[2] == 0) goto L64b745;  // @291_64b480
  ecx = 0;  // @292_64b480
  FL[3] = ecx;  // @293_64b480
  ebx = (u32)(eax + 16);  // @294_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @295_64b480
  goto L64b73d;  // @296_64b480
  L64b73a:;
  ebx = (ebx + (u32)(4));  // @298_64b480
  FL[3] = ebx;  // @299_64b480
  L64b73d:;
  FL[2] = (ebx & ebx);  // @301_64b480
  if (FL[2] != 0) goto L64b6b0;  // @302_64b480
  L64b745:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65673), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @304_64b480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @305_64b480
  if (FL[0] == FL[1]) goto L64b7f1;  // @306_64b480
  ecx = (u32)(esi + 65677);  // @307_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @308_64b480
  L64b762:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @310_64b480
  edx = ebx;  // @311_64b480
  FL[1] = edx;  // @312_64b480
  edx = (0u - edx);  // @313_64b480
  edx = (0u - (u32)(FL[1] != 0));  // @314_64b480
  eax = (u32)(ebx + 4);  // @315_64b480
  edx = (edx & eax);  // @316_64b480
  FL[3] = edx;  // @317_64b480
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(edx + 5), &v, sizeof v); }  // @318_64b480
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5), sizeof v); (u32)v; });  // @319_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @320_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @321_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @322_64b480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @323_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @324_64b480
  edi = (edi + (u32)(616));  // @325_64b480
  FL[3] = edi;  // @326_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @327_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @328_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @329_64b480
  eax = ecx;  // @330_64b480
  eax = (eax - edi);  // @331_64b480
  FL[3] = eax;  // @332_64b480
  eax = (eax - (u32)(8));  // @333_64b480
  FL[3] = eax;  // @334_64b480
  eax = (u32)((s32)eax >> (u32)(2));  // @335_64b480
  FL[3] = eax;  // @336_64b480
  eax = (eax & 0xffff);  // @337_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @338_64b480
  eax = (u32)(edi + 32776);  // @339_64b480
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @340_64b480
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @341_64b480
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @342_64b480
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = eax;  // @343_64b480
  if (FL[0] != FL[1]) goto L64b7b9;  // @344_64b480
  eax = (u32)(edi + 8);  // @345_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @346_64b480
  L64b7b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @348_64b480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 6), &v, sizeof v); }  // @349_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @350_64b480
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) + (u32)(255))); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @351_64b480
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @352_64b480
  if (FL[3] != 0) goto L64b7d5;  // @353_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @354_64b480
  PV[10] = (u32)(eax);  // @355_64b480
  eax = ext_63f600_thiscall2(ecx, PV[10]);  // @356_64b480
    // @357_64b480
  L64b7d5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @359_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @360_64b480
  eax = (eax + 1);  // @361_64b480
  FL[3] = eax;  // @362_64b480
  ecx = (ecx + (u32)(4));  // @363_64b480
  FL[3] = ecx;  // @364_64b480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @365_64b480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @366_64b480
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65673), sizeof v); (u32)v; });  // @367_64b480
  if (FL[0] != FL[1]) goto L64b762;  // @368_64b480
  L64b7f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @370_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @371_64b480
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @372_64b480
  eax = ext_63cc50_thiscall3(ecx, (u32)(0), PV[11]);  // @373_64b480
  ecx = edx = 0;  // @374_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65877), sizeof v); (u32)v; });  // @375_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @376_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @377_64b480
  ecx = edx = 0;  // @378_64b480
  FL[2] = (eax & eax);  // @379_64b480
  if (FL[2] != 0) goto L64b864;  // @380_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65881), sizeof v); (u32)v; });  // @381_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @382_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @383_64b480
  ecx = edx = 0;  // @384_64b480
  FL[2] = (eax & eax);  // @385_64b480
  if (FL[2] != 0) goto L64b864;  // @386_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; });  // @387_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @388_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @389_64b480
  ecx = edx = 0;  // @390_64b480
  FL[2] = (eax & eax);  // @391_64b480
  if (FL[2] != 0) goto L64b864;  // @392_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; });  // @393_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @394_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @395_64b480
  ecx = edx = 0;  // @396_64b480
  FL[2] = (eax & eax);  // @397_64b480
  if (FL[2] != 0) goto L64b864;  // @398_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65897), sizeof v); (u32)v; });  // @399_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @400_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @401_64b480
  ecx = edx = 0;  // @402_64b480
  FL[2] = (eax & eax);  // @403_64b480
  if (FL[2] != 0) goto L64b864;  // @404_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65901), sizeof v); (u32)v; });  // @405_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @406_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @407_64b480
  ecx = edx = 0;  // @408_64b480
  FL[2] = (eax & eax);  // @409_64b480
  if (FL[2] == 0) goto L64b9ec;  // @410_64b480
  L64b864:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @412_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @413_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(983));  // @414_64b480
  ecx = edx = 0;  // @415_64b480
  PV[12] = (u32)(eax);  // @416_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @417_64b480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[12], (u32)(7089848));  // @418_64b480
  ecx = edx = 0;  // @419_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @420_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @421_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(984));  // @422_64b480
  ecx = edx = 0;  // @423_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65873), sizeof v); (u32)v; });  // @424_64b480
  edi = eax;  // @425_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @426_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @427_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @428_64b480
  ecx = edx = 0;  // @429_64b480
  PV[13] = (u32)(eax);  // @430_64b480
  PV[14] = (u32)(edi);  // @431_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[14], (u32)(7087904), PV[13]);  // @432_64b480
  ecx = edx = 0;  // @433_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @434_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @435_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(985));  // @436_64b480
  ecx = edx = 0;  // @437_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65877), sizeof v); (u32)v; });  // @438_64b480
  edi = eax;  // @439_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @440_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @441_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @442_64b480
  ecx = edx = 0;  // @443_64b480
  PV[15] = (u32)(eax);  // @444_64b480
  PV[16] = (u32)(edi);  // @445_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[16], (u32)(7087916), PV[15]);  // @446_64b480
  ecx = edx = 0;  // @447_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @448_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @449_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(986));  // @450_64b480
  ecx = edx = 0;  // @451_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65881), sizeof v); (u32)v; });  // @452_64b480
  edi = eax;  // @453_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @454_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @455_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @456_64b480
  ecx = edx = 0;  // @457_64b480
  PV[17] = (u32)(eax);  // @458_64b480
  PV[18] = (u32)(edi);  // @459_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[18], (u32)(7087928), PV[17]);  // @460_64b480
  ecx = edx = 0;  // @461_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @462_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @463_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(987));  // @464_64b480
  ecx = edx = 0;  // @465_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; });  // @466_64b480
  edi = eax;  // @467_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @468_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @469_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @470_64b480
  ecx = edx = 0;  // @471_64b480
  PV[19] = (u32)(eax);  // @472_64b480
  PV[20] = (u32)(edi);  // @473_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[20], (u32)(7087936), PV[19]);  // @474_64b480
  ecx = edx = 0;  // @475_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @476_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @477_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(988));  // @478_64b480
  ecx = edx = 0;  // @479_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65889), sizeof v); (u32)v; });  // @480_64b480
  edi = eax;  // @481_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @482_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @483_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @484_64b480
  ecx = edx = 0;  // @485_64b480
  PV[21] = (u32)(eax);  // @486_64b480
  PV[22] = (u32)(edi);  // @487_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[22], (u32)(7087952), PV[21]);  // @488_64b480
  ecx = edx = 0;  // @489_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @490_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @491_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(989));  // @492_64b480
  ecx = edx = 0;  // @493_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65897), sizeof v); (u32)v; });  // @494_64b480
  edi = eax;  // @495_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @496_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @497_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @498_64b480
  ecx = edx = 0;  // @499_64b480
  PV[23] = (u32)(eax);  // @500_64b480
  PV[24] = (u32)(edi);  // @501_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[24], (u32)(7087964), PV[23]);  // @502_64b480
  ecx = edx = 0;  // @503_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @504_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @505_64b480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7089808), (u32)(990));  // @506_64b480
  ecx = edx = 0;  // @507_64b480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65901), sizeof v); (u32)v; });  // @508_64b480
  edi = eax;  // @509_64b480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @510_64b480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @511_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @512_64b480
  ecx = edx = 0;  // @513_64b480
  PV[25] = (u32)(eax);  // @514_64b480
  PV[26] = (u32)(edi);  // @515_64b480
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ebx + 44)))(PV[26], (u32)(7087976), PV[25]);  // @516_64b480
  ecx = edx = 0;  // @517_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @518_64b480
  FL[2] = (eax & eax);  // @519_64b480
  if (FL[2] == 0) goto L64b9eb;  // @520_64b480
  eax = ((u32(STDCALL *)(void))(eax))();  // @521_64b480
  ecx = edx = 0;  // @522_64b480
  goto L64b9ec;  // @523_64b480
  L64b9eb:;
  __builtin_trap();  // @525_64b480
  L64b9ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @527_64b480
  ecx = (u32)(esi + 12);  // @528_64b480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65673), &v, sizeof v); }  // @529_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @530_64b480
  ecx = edx = 0;  // @531_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65905), sizeof v); (u32)v; });  // @532_64b480
  ecx = (u32)(esi + 65905);  // @533_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @534_64b480
  ecx = edx = 0;  // @535_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65925), sizeof v); (u32)v; });  // @536_64b480
  ecx = (u32)(esi + 65925);  // @537_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @538_64b480
  ecx = edx = 0;  // @539_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65945), sizeof v); (u32)v; });  // @540_64b480
  ecx = (u32)(esi + 65945);  // @541_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @542_64b480
  ecx = edx = 0;  // @543_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65965), sizeof v); (u32)v; });  // @544_64b480
  ecx = (u32)(esi + 65965);  // @545_64b480
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @546_64b480
  ecx = edx = 0;  // @547_64b480
  edi = 0;  // @548_64b480
  FL[3] = edi;  // @549_64b480
  L64ba40:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65649), sizeof v); (u32)v; });  // @551_64b480
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @552_64b480
  if (FL[0] == FL[1]) goto L64ba5a;  // @553_64b480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @554_64b480
  FL[2] = (eax & eax);  // @555_64b480
  if (FL[2] == 0) goto L64ba59;  // @556_64b480
  eax = ((u32(STDCALL *)(void))(eax))();  // @557_64b480
  ecx = edx = 0;  // @558_64b480
  goto L64ba5a;  // @559_64b480
  L64ba59:;
  __builtin_trap();  // @561_64b480
  L64ba5a:;
  edi = (edi + (u32)(4));  // @563_64b480
  FL[3] = edi;  // @564_64b480
  FL[0] = edi; FL[1] = (u32)(16384);  // @565_64b480
  if (FL[0] != FL[1]) goto L64ba40;  // @566_64b480
  return eax;  // @567_64b480
}
PCREG(64b480, lifted_64b480);

