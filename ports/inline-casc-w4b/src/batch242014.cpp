// batch242014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_53eaa0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_53eaa0
  ebx = 0;  // @1_53eaa0
  FL[3] = ebx;  // @2_53eaa0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_53eaa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @4_53eaa0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @5_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @7_53eaa0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @8_53eaa0
  ecx = edx = 0;  // @9_53eaa0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @10_53eaa0
  if (FL[2] == 0) goto L53eb32;  // @11_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @12_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @13_53eaa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @14_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_53eaa0
  PV[0] = (u32)(edx);  // @16_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @17_53eaa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @18_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_53eaa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[0]);  // @20_53eaa0
  ecx = edx = 0;  // @21_53eaa0
  edi = eax;  // @22_53eaa0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @23_53eaa0
  FL[2] = (edi & edi);  // @24_53eaa0
  if (FL[2] != 0) goto L53eb5c;  // @25_53eaa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @26_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_53eaa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6958240), (u32)(408));  // @28_53eaa0
  ecx = edx = 0;  // @29_53eaa0
  edx = eax;  // @30_53eaa0
  ecx = (u32)(6801640);  // @31_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @32_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @33_53eaa0
  FL[2] = (eax & eax);  // @34_53eaa0
  if (FL[2] != 0) ecx = eax;  // @35_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @36_53eaa0
  PV[1] = (u32)(ecx);  // @37_53eaa0
  PV[2] = (u32)(edx);  // @38_53eaa0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[2], (u32)(6958448), PV[1]);  // @39_53eaa0
  ecx = edx = 0;  // @40_53eaa0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @41_53eaa0
  L53eb32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @43_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @44_53eaa0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }) & (u32)(1048576));  // @45_53eaa0
  if (FL[2] == 0) goto L53ec9b;  // @46_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_53eaa0
  edx = (u32)(EBP - 28);  // @48_53eaa0
  PV[3] = (u32)(edx);  // @49_53eaa0
  edx = (u32)(EBP - 16);  // @50_53eaa0
  PV[4] = (u32)(edx);  // @51_53eaa0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 700)))(ecx, PV[4], PV[3], (u32)(1));  // @52_53eaa0
  ecx = edx = 0;  // @53_53eaa0
  goto L53ecb6;  // @54_53eaa0
  L53eb5c:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @56_53eaa0
  ecx = 0;  // @57_53eaa0
  FL[3] = ecx;  // @58_53eaa0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @59_53eaa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @60_53eaa0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = ecx;  // @61_53eaa0
  if (FL[0] <= FL[1]) goto L53ec65;  // @62_53eaa0
  L53eb70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @64_53eaa0
  edx = 0;  // @65_53eaa0
  FL[3] = edx;  // @66_53eaa0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @67_53eaa0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; }); FL[1] = edx;  // @68_53eaa0
  if (FL[0] <= FL[1]) goto L53ec49;  // @69_53eaa0
  ecx = (u32)(esi + 8);  // @70_53eaa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @71_53eaa0
  L53eb90:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx - 8) + 0), 4); v; });  // @73_53eaa0
  X0[1] = 0;  // @74_53eaa0
  X0[2] = 0;  // @75_53eaa0
  X0[3] = 0;  // @76_53eaa0
  esi = 0;  // @77_53eaa0
  FL[3] = esi;  // @78_53eaa0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx - 4) + 0), 4); v; });  // @79_53eaa0
  X1[1] = 0;  // @80_53eaa0
  X1[2] = 0;  // @81_53eaa0
  X1[3] = 0;  // @82_53eaa0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @83_53eaa0
  X2[1] = 0;  // @84_53eaa0
  X2[2] = 0;  // @85_53eaa0
  X2[3] = 0;  // @86_53eaa0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @87_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @88_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @89_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @90_53eaa0
  FL[2] = (ebx & ebx);  // @91_53eaa0
  if ((s32)FL[2] <= 0) goto L53ec11;  // @92_53eaa0
  L53ebb6:;
  eax = (u32)(EBP - 16);  // @94_53eaa0
  edx = edi;  // @95_53eaa0
  PV[5] = (u32)(eax);  // @96_53eaa0
  ecx = (u32)(EBP - 28);  // @97_53eaa0
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @98_53eaa0
  ecx = edx = 0;  // @99_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @100_53eaa0
  X0[1] = 0;  // @101_53eaa0
  X0[2] = 0;  // @102_53eaa0
  X0[3] = 0;  // @103_53eaa0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @104_53eaa0
  X1[1] = 0;  // @105_53eaa0
  X1[2] = 0;  // @106_53eaa0
  X1[3] = 0;  // @107_53eaa0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @108_53eaa0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @109_53eaa0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @110_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @111_53eaa0
  X0[1] = 0;  // @112_53eaa0
  X0[2] = 0;  // @113_53eaa0
  X0[3] = 0;  // @114_53eaa0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @115_53eaa0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @116_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @117_53eaa0
  X0[1] = 0;  // @118_53eaa0
  X0[2] = 0;  // @119_53eaa0
  X0[3] = 0;  // @120_53eaa0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L53ec22;  // @121_53eaa0
  esi = (esi + 1);  // @122_53eaa0
  FL[3] = esi;  // @123_53eaa0
  edi = (edi + (u32)(12));  // @124_53eaa0
  FL[3] = edi;  // @125_53eaa0
  FL[0] = esi; FL[1] = ebx;  // @126_53eaa0
  if ((s32)FL[0] < (s32)FL[1]) goto L53ebb6;  // @127_53eaa0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @128_53eaa0
  X2[1] = 0;  // @129_53eaa0
  X2[2] = 0;  // @130_53eaa0
  X2[3] = 0;  // @131_53eaa0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @132_53eaa0
  X1[1] = 0;  // @133_53eaa0
  X1[2] = 0;  // @134_53eaa0
  X1[3] = 0;  // @135_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @136_53eaa0
  X0[1] = 0;  // @137_53eaa0
  X0[2] = 0;  // @138_53eaa0
  X0[3] = 0;  // @139_53eaa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @140_53eaa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @141_53eaa0
  L53ec11:;
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @143_53eaa0
  ebx = (ebx + 1);  // @144_53eaa0
  FL[3] = ebx;  // @145_53eaa0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X1[0], 4);  // @146_53eaa0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X2[0], 4);  // @147_53eaa0
  goto L53ec28;  // @148_53eaa0
  L53ec22:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @150_53eaa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @151_53eaa0
  L53ec28:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @153_53eaa0
  edx = (edx + 1);  // @154_53eaa0
  FL[3] = edx;  // @155_53eaa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @156_53eaa0
  ecx = (ecx + (u32)(12));  // @157_53eaa0
  FL[3] = ecx;  // @158_53eaa0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @159_53eaa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @160_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @161_53eaa0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @162_53eaa0
  if (FL[0] < FL[1]) goto L53eb90;  // @163_53eaa0
  ecx = esi;  // @164_53eaa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @165_53eaa0
  L53ec49:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @167_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @168_53eaa0
  ecx = (ecx + 1);  // @169_53eaa0
  FL[3] = ecx;  // @170_53eaa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @171_53eaa0
  eax = (u32)(eax + eax*2);  // @172_53eaa0
  esi = (u32)(esi + eax*4);  // @173_53eaa0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @174_53eaa0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @175_53eaa0
  if (FL[0] < FL[1]) goto L53eb70;  // @176_53eaa0
  L53ec65:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @178_53eaa0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @179_53eaa0
  eax = ext_634273_cdecl2(PV[6], (u32)(4));  // @180_53eaa0
  ecx = edx = 0;  // @181_53eaa0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @182_53eaa0
  eax = ext_634273_cdecl2(PV[7], (u32)(4));  // @183_53eaa0
  ecx = edx = 0;  // @184_53eaa0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @185_53eaa0
  eax = ext_634273_cdecl2(PV[8], (u32)(8));  // @186_53eaa0
  ecx = edx = 0;  // @187_53eaa0
  PV[9] = (u32)(edi);  // @188_53eaa0
  eax = ext_634273_cdecl2(PV[9], (u32)(52));  // @189_53eaa0
  ecx = edx = 0;  // @190_53eaa0
  edi = esi;  // @191_53eaa0
  FL[2] = (esi & esi);  // @192_53eaa0
  if (FL[2] != 0) goto L53ec65;  // @193_53eaa0
  goto L53ee55;  // @194_53eaa0
  L53ec9b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @196_53eaa0
  eax = (u32)(EBP - 16);  // @197_53eaa0
  PV[10] = (u32)(eax);  // @198_53eaa0
  eax = ext_4daf90_thiscall2(ecx, PV[10]);  // @199_53eaa0
  edx = 0;  // @200_53eaa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @201_53eaa0
  eax = (u32)(EBP - 28);  // @202_53eaa0
  PV[11] = (u32)(eax);  // @203_53eaa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @204_53eaa0
  eax = ext_4db7c0_thiscall2(ecx, PV[11]);  // @205_53eaa0
  edx = 0;  // @206_53eaa0
  L53ecb6:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @208_53eaa0
  X1[1] = 0;  // @209_53eaa0
  X1[2] = 0;  // @210_53eaa0
  X1[3] = 0;  // @211_53eaa0
  eax = 0;  // @212_53eaa0
  FL[3] = eax;  // @213_53eaa0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @214_53eaa0
  X2[1] = 0;  // @215_53eaa0
  X2[2] = 0;  // @216_53eaa0
  X2[3] = 0;  // @217_53eaa0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @218_53eaa0
  X3[1] = 0;  // @219_53eaa0
  X3[2] = 0;  // @220_53eaa0
  X3[3] = 0;  // @221_53eaa0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @222_53eaa0
  X4[1] = 0;  // @223_53eaa0
  X4[2] = 0;  // @224_53eaa0
  X4[3] = 0;  // @225_53eaa0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @226_53eaa0
  X5[1] = 0;  // @227_53eaa0
  X5[2] = 0;  // @228_53eaa0
  X5[3] = 0;  // @229_53eaa0
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @230_53eaa0
  X6[1] = 0;  // @231_53eaa0
  X6[2] = 0;  // @232_53eaa0
  X6[3] = 0;  // @233_53eaa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @234_53eaa0
  L53ece0:;
  FL[0] = eax; FL[1] = (u32)(7);  // @236_53eaa0
  if (FL[0] > FL[1]) goto L53edb6;  // @237_53eaa0
  switch (eax) {  // @238_53eaa0
  case 0: goto L53ecf0;  // @239_53eaa0
  case 1: goto L53ed14;  // @240_53eaa0
  case 2: goto L53ed29;  // @241_53eaa0
  case 3: goto L53ed4a;  // @242_53eaa0
  case 4: goto L53ed53;  // @243_53eaa0
  case 5: goto L53ed5c;  // @244_53eaa0
  case 6: goto L53ed71;  // @245_53eaa0
  case 7: goto L53ed92;  // @246_53eaa0
  default: __builtin_trap(); }  // @247_53eaa0
  L53ecf0:;
  X0[0] = X3[0];  // @249_53eaa0
  X0[1] = X3[1];  // @250_53eaa0
  X0[2] = X3[2];  // @251_53eaa0
  X0[3] = X3[3];  // @252_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X6[0]));  // @253_53eaa0
  L53ecf7:;
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @255_53eaa0
  X0[0] = X2[0];  // @256_53eaa0
  X0[1] = X2[1];  // @257_53eaa0
  X0[2] = X2[2];  // @258_53eaa0
  X0[3] = X2[3];  // @259_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X5[0]));  // @260_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @261_53eaa0
  X0[0] = X1[0];  // @262_53eaa0
  X0[1] = X1[1];  // @263_53eaa0
  X0[2] = X1[2];  // @264_53eaa0
  X0[3] = X1[3];  // @265_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X4[0]));  // @266_53eaa0
  goto L53edb1;  // @267_53eaa0
  L53ed14:;
  X0[0] = X3[0];  // @269_53eaa0
  X0[1] = X3[1];  // @270_53eaa0
  X0[2] = X3[2];  // @271_53eaa0
  X0[3] = X3[3];  // @272_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X6[0]));  // @273_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @274_53eaa0
  X0[0] = X2[0];  // @275_53eaa0
  X0[1] = X2[1];  // @276_53eaa0
  X0[2] = X2[2];  // @277_53eaa0
  X0[3] = X2[3];  // @278_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X5[0]));  // @279_53eaa0
  goto L53eda5;  // @280_53eaa0
  L53ed29:;
  X0[0] = X3[0];  // @282_53eaa0
  X0[1] = X3[1];  // @283_53eaa0
  X0[2] = X3[2];  // @284_53eaa0
  X0[3] = X3[3];  // @285_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X6[0]));  // @286_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @287_53eaa0
  X0[0] = X5[0];  // @288_53eaa0
  X0[1] = X5[1];  // @289_53eaa0
  X0[2] = X5[2];  // @290_53eaa0
  X0[3] = X5[3];  // @291_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @292_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @293_53eaa0
  X0[0] = X1[0];  // @294_53eaa0
  X0[1] = X1[1];  // @295_53eaa0
  X0[2] = X1[2];  // @296_53eaa0
  X0[3] = X1[3];  // @297_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X4[0]));  // @298_53eaa0
  goto L53edb1;  // @299_53eaa0
  L53ed4a:;
  X0[0] = X3[0];  // @301_53eaa0
  X0[1] = X3[1];  // @302_53eaa0
  X0[2] = X3[2];  // @303_53eaa0
  X0[3] = X3[3];  // @304_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X6[0]));  // @305_53eaa0
  goto L53ed99;  // @306_53eaa0
  L53ed53:;
  X0[0] = X6[0];  // @308_53eaa0
  X0[1] = X6[1];  // @309_53eaa0
  X0[2] = X6[2];  // @310_53eaa0
  X0[3] = X6[3];  // @311_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @312_53eaa0
  goto L53ecf7;  // @313_53eaa0
  L53ed5c:;
  X0[0] = X6[0];  // @315_53eaa0
  X0[1] = X6[1];  // @316_53eaa0
  X0[2] = X6[2];  // @317_53eaa0
  X0[3] = X6[3];  // @318_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @319_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @320_53eaa0
  X0[0] = X2[0];  // @321_53eaa0
  X0[1] = X2[1];  // @322_53eaa0
  X0[2] = X2[2];  // @323_53eaa0
  X0[3] = X2[3];  // @324_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X5[0]));  // @325_53eaa0
  goto L53eda5;  // @326_53eaa0
  L53ed71:;
  X0[0] = X6[0];  // @328_53eaa0
  X0[1] = X6[1];  // @329_53eaa0
  X0[2] = X6[2];  // @330_53eaa0
  X0[3] = X6[3];  // @331_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @332_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @333_53eaa0
  X0[0] = X5[0];  // @334_53eaa0
  X0[1] = X5[1];  // @335_53eaa0
  X0[2] = X5[2];  // @336_53eaa0
  X0[3] = X5[3];  // @337_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @338_53eaa0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @339_53eaa0
  X0[0] = X1[0];  // @340_53eaa0
  X0[1] = X1[1];  // @341_53eaa0
  X0[2] = X1[2];  // @342_53eaa0
  X0[3] = X1[3];  // @343_53eaa0
  X0[0] = F2U(U2F(X0[0]) + U2F(X4[0]));  // @344_53eaa0
  goto L53edb1;  // @345_53eaa0
  L53ed92:;
  X0[0] = X6[0];  // @347_53eaa0
  X0[1] = X6[1];  // @348_53eaa0
  X0[2] = X6[2];  // @349_53eaa0
  X0[3] = X6[3];  // @350_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @351_53eaa0
  L53ed99:;
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @353_53eaa0
  X0[0] = X5[0];  // @354_53eaa0
  X0[1] = X5[1];  // @355_53eaa0
  X0[2] = X5[2];  // @356_53eaa0
  X0[3] = X5[3];  // @357_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @358_53eaa0
  L53eda5:;
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @360_53eaa0
  X0[0] = X4[0];  // @361_53eaa0
  X0[1] = X4[1];  // @362_53eaa0
  X0[2] = X4[2];  // @363_53eaa0
  X0[3] = X4[3];  // @364_53eaa0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @365_53eaa0
  L53edb1:;
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @367_53eaa0
  L53edb6:;
  esi = edi;  // @369_53eaa0
  edi = 0;  // @370_53eaa0
  FL[3] = edi;  // @371_53eaa0
  FL[2] = (ebx & ebx);  // @372_53eaa0
  if ((s32)FL[2] <= 0) goto L53ee27;  // @373_53eaa0
  L53edc0:;
  eax = (u32)(EBP - 40);  // @375_53eaa0
  edx = esi;  // @376_53eaa0
  PV[12] = (u32)(eax);  // @377_53eaa0
  ecx = (u32)(EBP - 76);  // @378_53eaa0
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @379_53eaa0
  ecx = edx = 0;  // @380_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @381_53eaa0
  X0[1] = 0;  // @382_53eaa0
  X0[2] = 0;  // @383_53eaa0
  X0[3] = 0;  // @384_53eaa0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @385_53eaa0
  X1[1] = 0;  // @386_53eaa0
  X1[2] = 0;  // @387_53eaa0
  X1[3] = 0;  // @388_53eaa0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @389_53eaa0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @390_53eaa0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @391_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @392_53eaa0
  X0[1] = 0;  // @393_53eaa0
  X0[2] = 0;  // @394_53eaa0
  X0[3] = 0;  // @395_53eaa0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @396_53eaa0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @397_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; });  // @398_53eaa0
  X0[1] = 0;  // @399_53eaa0
  X0[2] = 0;  // @400_53eaa0
  X0[3] = 0;  // @401_53eaa0
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L53ee6a;  // @402_53eaa0
  edi = (edi + 1);  // @403_53eaa0
  FL[3] = edi;  // @404_53eaa0
  esi = (esi + (u32)(12));  // @405_53eaa0
  FL[3] = esi;  // @406_53eaa0
  FL[0] = edi; FL[1] = ebx;  // @407_53eaa0
  if ((s32)FL[0] < (s32)FL[1]) goto L53edc0;  // @408_53eaa0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @409_53eaa0
  X1[1] = 0;  // @410_53eaa0
  X1[2] = 0;  // @411_53eaa0
  X1[3] = 0;  // @412_53eaa0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @413_53eaa0
  X2[1] = 0;  // @414_53eaa0
  X2[2] = 0;  // @415_53eaa0
  X2[3] = 0;  // @416_53eaa0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @417_53eaa0
  X3[1] = 0;  // @418_53eaa0
  X3[2] = 0;  // @419_53eaa0
  X3[3] = 0;  // @420_53eaa0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @421_53eaa0
  X4[1] = 0;  // @422_53eaa0
  X4[2] = 0;  // @423_53eaa0
  X4[3] = 0;  // @424_53eaa0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @425_53eaa0
  X5[1] = 0;  // @426_53eaa0
  X5[2] = 0;  // @427_53eaa0
  X5[3] = 0;  // @428_53eaa0
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @429_53eaa0
  X6[1] = 0;  // @430_53eaa0
  X6[2] = 0;  // @431_53eaa0
  X6[3] = 0;  // @432_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @433_53eaa0
  L53ee27:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @435_53eaa0
  X0[1] = 0;  // @436_53eaa0
  X0[2] = 0;  // @437_53eaa0
  X0[3] = 0;  // @438_53eaa0
  ebx = (ebx + 1);  // @439_53eaa0
  FL[3] = ebx;  // @440_53eaa0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @441_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @442_53eaa0
  X0[1] = 0;  // @443_53eaa0
  X0[2] = 0;  // @444_53eaa0
  X0[3] = 0;  // @445_53eaa0
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @446_53eaa0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @447_53eaa0
  X0[1] = 0;  // @448_53eaa0
  X0[2] = 0;  // @449_53eaa0
  X0[3] = 0;  // @450_53eaa0
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @451_53eaa0
  L53ee45:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @453_53eaa0
  eax = (eax + 1);  // @454_53eaa0
  FL[3] = eax;  // @455_53eaa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @456_53eaa0
  FL[0] = eax; FL[1] = (u32)(8);  // @457_53eaa0
  if ((s32)FL[0] < (s32)FL[1]) goto L53ece0;  // @458_53eaa0
  L53ee55:;
  ext_633654(G(u32, 0x6f5630));  // @460_53eaa0
  eax = ebx;  // @461_53eaa0
  return eax;  // @462_53eaa0
  L53ee6a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @464_53eaa0
  X1[1] = 0;  // @465_53eaa0
  X1[2] = 0;  // @466_53eaa0
  X1[3] = 0;  // @467_53eaa0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @468_53eaa0
  X2[1] = 0;  // @469_53eaa0
  X2[2] = 0;  // @470_53eaa0
  X2[3] = 0;  // @471_53eaa0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @472_53eaa0
  X3[1] = 0;  // @473_53eaa0
  X3[2] = 0;  // @474_53eaa0
  X3[3] = 0;  // @475_53eaa0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @476_53eaa0
  X4[1] = 0;  // @477_53eaa0
  X4[2] = 0;  // @478_53eaa0
  X4[3] = 0;  // @479_53eaa0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @480_53eaa0
  X5[1] = 0;  // @481_53eaa0
  X5[2] = 0;  // @482_53eaa0
  X5[3] = 0;  // @483_53eaa0
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @484_53eaa0
  X6[1] = 0;  // @485_53eaa0
  X6[2] = 0;  // @486_53eaa0
  X6[3] = 0;  // @487_53eaa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @488_53eaa0
  goto L53ee45;  // @489_53eaa0
}
PCREG(53eaa0, lifted_53eaa0);

