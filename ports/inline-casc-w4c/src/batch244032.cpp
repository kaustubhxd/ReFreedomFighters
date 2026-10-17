// batch244032.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 THISCALL ext_650f30_thiscall2(u32, u32) __asm__("ext_650f30");
extern "C" u32 THISCALL ext_640c90_thiscall2(u32, u32) __asm__("ext_640c90");
extern "C" u32 THISCALL ext_428440_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_428440");
extern "C" u32 THISCALL ext_4284f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4284f0");
extern "C" u32 THISCALL ext_428560_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_428560");
extern "C" u32 THISCALL ext_429470_thiscall1(u32) __asm__("ext_429470");
extern "C" u32 THISCALL ext_435d30_thiscall2(u32, u32) __asm__("ext_435d30");
extern "C" u32 THISCALL ext_435d50_thiscall2(u32, u32) __asm__("ext_435d50");
extern "C" u32 THISCALL ext_435d70_thiscall2(u32, u32) __asm__("ext_435d70");
extern "C" u32 THISCALL ext_4361a0_thiscall2(u32, u32) __asm__("ext_4361a0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4d8180_thiscall3(u32, u32, u32) __asm__("ext_4d8180");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4dafb0_thiscall1(u32) __asm__("ext_4dafb0");
extern "C" u32 THISCALL ext_4db2a0_thiscall2(u32, u32) __asm__("ext_4db2a0");
extern "C" u32 THISCALL ext_4db550_thiscall1(u32) __asm__("ext_4db550");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_640c10_thiscall2(u32, u32) __asm__("ext_640c10");
extern "C" u32 THISCALL ext_65ca80_thiscall2(u32, u32) __asm__("ext_65ca80");
extern "C" u32 THISCALL ext_65cb00_thiscall2(u32, u32) __asm__("ext_65cb00");
extern "C" u32 THISCALL ext_65da30_thiscall2(u32, u32) __asm__("ext_65da30");
extern "C" u32 THISCALL ext_660c80_thiscall1(u32) __asm__("ext_660c80");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_64ee10(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ebfb);  // @h_64ee10
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_64ee10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_64ee10
  ecx = (u32)(esi + 148);  // @2_64ee10
  { u32 v = (u32)((u32)(7089924)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 30), &v, sizeof v); }  // @4_64ee10
  eax = ext_660c80_thiscall1(ecx);  // @5_64ee10
    // @6_64ee10
  reg.state = (s32)((u32)(0));  // @7_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 258), &v, sizeof v); }  // @8_64ee10
  eax = ext_41e290_cdecl1((u32)(44));  // @9_64ee10
  ecx = edx = 0;  // @10_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @11_64ee10
  reg.state = (s32)((u32)(1));  // @12_64ee10
  FL[2] = (eax & eax);  // @13_64ee10
  if (FL[2] == 0) goto L64ee84;  // @14_64ee10
  ecx = eax;  // @15_64ee10
  eax = ext_4ccad0_thiscall3(ecx, (u32)(8), (u32)(0));  // @16_64ee10
  ecx = edx = 0;  // @17_64ee10
  goto L64ee86;  // @18_64ee10
  L64ee84:;
  eax = 0;  // @20_64ee10
  FL[3] = eax;  // @21_64ee10
  L64ee86:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @23_64ee10
  edi = (u32)(esi + 112);  // @24_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 51), &v, sizeof v); }  // @25_64ee10
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @26_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @27_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @28_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @29_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @30_64ee10
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @31_64ee10
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @32_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @33_64ee10
  { u32 v = (u32)((u32)(60)); __builtin_memcpy((void *)(u32)(esi + 26), &v, sizeof v); }  // @34_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @35_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @36_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @37_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @38_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @39_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @40_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @41_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @42_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @43_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @44_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @45_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 253), &v, sizeof v); }  // @46_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @47_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @48_64ee10
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 181), &v, sizeof v); }  // @49_64ee10
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 185), &v, sizeof v); }  // @50_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @51_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_64ee10
  reg.state = (s32)((u32)(0));  // @53_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @54_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @55_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @57_64ee10
  FL[2] = (ecx & ecx);  // @58_64ee10
  if (FL[2] == 0) goto L64ef7a;  // @59_64ee10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @60_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_64ee10
  L64ef7a:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 6415), &v, sizeof v); }  // @63_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @64_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @65_64ee10
  ecx = edx = 0;  // @66_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @67_64ee10
  reg.state = (s32)((u32)(2));  // @68_64ee10
  FL[2] = (eax & eax);  // @69_64ee10
  if (FL[2] == 0) goto L64efc1;  // @70_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_64ee10
  ecx = (ecx + (u32)(2503));  // @72_64ee10
  FL[3] = ecx;  // @73_64ee10
  PV[0] = (u32)(ecx);  // @74_64ee10
  ecx = eax;  // @75_64ee10
  eax = ext_4d8330_thiscall4(ecx, (u32)(7090680), (u32)(7090624), PV[0]);  // @76_64ee10
  ecx = edx = 0;  // @77_64ee10
  edx = eax;  // @78_64ee10
  goto L64efc3;  // @79_64ee10
  L64efc1:;
  edx = 0;  // @81_64ee10
  FL[3] = edx;  // @82_64ee10
  L64efc3:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 263), &v, sizeof v); }  // @84_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_64ee10
  PV[1] = (u32)(edx);  // @86_64ee10
  reg.state = (s32)((u32)(0));  // @87_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[1]);  // @89_64ee10
  ecx = edx = 0;  // @90_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @91_64ee10
  ecx = edx = 0;  // @92_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @93_64ee10
  reg.state = (s32)((u32)(3));  // @94_64ee10
  FL[2] = (eax & eax);  // @95_64ee10
  if (FL[2] == 0) goto L64f016;  // @96_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_64ee10
  ecx = (ecx + (u32)(2499));  // @98_64ee10
  FL[3] = ecx;  // @99_64ee10
  PV[2] = (u32)(ecx);  // @100_64ee10
  ecx = eax;  // @101_64ee10
  eax = ext_4d8330_thiscall4(ecx, (u32)(7090748), (u32)(7090692), PV[2]);  // @102_64ee10
  ecx = edx = 0;  // @103_64ee10
  edx = eax;  // @104_64ee10
  goto L64f018;  // @105_64ee10
  L64f016:;
  edx = 0;  // @107_64ee10
  FL[3] = edx;  // @108_64ee10
  L64f018:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 267), &v, sizeof v); }  // @110_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @111_64ee10
  PV[3] = (u32)(edx);  // @112_64ee10
  reg.state = (s32)((u32)(0));  // @113_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[3]);  // @115_64ee10
  ecx = edx = 0;  // @116_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @117_64ee10
  ecx = edx = 0;  // @118_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @119_64ee10
  reg.state = (s32)((u32)(4));  // @120_64ee10
  FL[2] = (eax & eax);  // @121_64ee10
  if (FL[2] == 0) goto L64f06b;  // @122_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_64ee10
  ecx = (ecx + (u32)(6976));  // @124_64ee10
  FL[3] = ecx;  // @125_64ee10
  PV[4] = (u32)(ecx);  // @126_64ee10
  ecx = eax;  // @127_64ee10
  eax = ext_4d8330_thiscall4(ecx, (u32)(7090808), (u32)(7090760), PV[4]);  // @128_64ee10
  ecx = edx = 0;  // @129_64ee10
  edx = eax;  // @130_64ee10
  goto L64f06d;  // @131_64ee10
  L64f06b:;
  edx = 0;  // @133_64ee10
  FL[3] = edx;  // @134_64ee10
  L64f06d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 271), &v, sizeof v); }  // @136_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_64ee10
  PV[5] = (u32)(edx);  // @138_64ee10
  reg.state = (s32)((u32)(0));  // @139_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[5]);  // @141_64ee10
  ecx = edx = 0;  // @142_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @143_64ee10
  ecx = edx = 0;  // @144_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @145_64ee10
  reg.state = (s32)((u32)(5));  // @146_64ee10
  FL[2] = (eax & eax);  // @147_64ee10
  if (FL[2] == 0) goto L64f0b4;  // @148_64ee10
  PV[6] = (u32)(edi);  // @149_64ee10
  ecx = eax;  // @150_64ee10
  eax = ext_4d8330_thiscall4(ecx, (u32)(7090872), (u32)(7090828), PV[6]);  // @151_64ee10
  ecx = edx = 0;  // @152_64ee10
  edx = eax;  // @153_64ee10
  goto L64f0b6;  // @154_64ee10
  L64f0b4:;
  edx = 0;  // @156_64ee10
  FL[3] = edx;  // @157_64ee10
  L64f0b6:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 275), &v, sizeof v); }  // @159_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @160_64ee10
  PV[7] = (u32)(edx);  // @161_64ee10
  reg.state = (s32)((u32)(0));  // @162_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[7]);  // @164_64ee10
  ecx = edx = 0;  // @165_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @166_64ee10
  ecx = edx = 0;  // @167_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @168_64ee10
  reg.state = (s32)((u32)(6));  // @169_64ee10
  FL[2] = (eax & eax);  // @170_64ee10
  if (FL[2] == 0) goto L64f106;  // @171_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @172_64ee10
  ecx = (ecx + (u32)(100));  // @173_64ee10
  FL[3] = ecx;  // @174_64ee10
  PV[8] = (u32)(ecx);  // @175_64ee10
  ecx = eax;  // @176_64ee10
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7090924), (u32)(7090888), PV[8]);  // @177_64ee10
  ecx = edx = 0;  // @178_64ee10
  edx = eax;  // @179_64ee10
  goto L64f108;  // @180_64ee10
  L64f106:;
  edx = 0;  // @182_64ee10
  FL[3] = edx;  // @183_64ee10
  L64f108:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 279), &v, sizeof v); }  // @185_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @186_64ee10
  PV[9] = (u32)(edx);  // @187_64ee10
  reg.state = (s32)((u32)(0));  // @188_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[9]);  // @190_64ee10
  ecx = edx = 0;  // @191_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @192_64ee10
  ecx = edx = 0;  // @193_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @194_64ee10
  reg.state = (s32)((u32)(7));  // @195_64ee10
  FL[2] = (eax & eax);  // @196_64ee10
  if (FL[2] == 0) goto L64f15e;  // @197_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @198_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @199_64ee10
  ecx = (ecx + (u32)(122));  // @200_64ee10
  FL[3] = ecx;  // @201_64ee10
  PV[10] = (u32)(ecx);  // @202_64ee10
  ecx = eax;  // @203_64ee10
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7090980), (u32)(7090944), PV[10]);  // @204_64ee10
  ecx = edx = 0;  // @205_64ee10
  edx = eax;  // @206_64ee10
  goto L64f160;  // @207_64ee10
  L64f15e:;
  edx = 0;  // @209_64ee10
  FL[3] = edx;  // @210_64ee10
  L64f160:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 283), &v, sizeof v); }  // @212_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @213_64ee10
  PV[11] = (u32)(edx);  // @214_64ee10
  reg.state = (s32)((u32)(0));  // @215_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @216_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[11]);  // @217_64ee10
  ecx = edx = 0;  // @218_64ee10
  eax = ext_41e290_cdecl1((u32)(264));  // @219_64ee10
  ecx = edx = 0;  // @220_64ee10
  edi = eax;  // @221_64ee10
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @222_64ee10
  reg.state = (s32)((u32)(8));  // @223_64ee10
  FL[2] = (edi & edi);  // @224_64ee10
  if (FL[2] == 0) goto L64f1b2;  // @225_64ee10
  ecx = edi;  // @226_64ee10
  eax = ext_4d8180_thiscall3(ecx, (u32)(7091064), (u32)(7091000));  // @227_64ee10
  ecx = edx = 0;  // @228_64ee10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @229_64ee10
  { u32 v = (u32)((u32)(7090540)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @230_64ee10
  goto L64f1b4;  // @231_64ee10
  L64f1b2:;
  edi = 0;  // @233_64ee10
  FL[3] = edi;  // @234_64ee10
  L64f1b4:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 287), &v, sizeof v); }  // @236_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @237_64ee10
  PV[12] = (u32)(edi);  // @238_64ee10
  reg.state = (s32)((u32)(0));  // @239_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @240_64ee10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[12]);  // @241_64ee10
  ecx = edx = 0;  // @242_64ee10
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7297688), sizeof v); (u32)v; });  // @243_64ee10
  eax = ext_41e290_cdecl1(PV[13]);  // @244_64ee10
  ecx = edx = 0;  // @245_64ee10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @246_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @247_64ee10
  ecx = esi;  // @248_64ee10
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 151), sizeof v); (u32)v; });  // @249_64ee10
  eax = ext_650f30_thiscall2(ecx, PV[14]);  // @250_64ee10
  ecx = edx = 0;  // @251_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 262), &v, sizeof v); }  // @252_64ee10
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @253_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @254_64ee10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 257), &v, sizeof v); }  // @255_64ee10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 189), &v, sizeof v); }  // @256_64ee10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @257_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_64ee10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @259_64ee10
  ecx = edx = 0;  // @260_64ee10
  ecx = eax;  // @261_64ee10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @262_64ee10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 220), sizeof v); (u32)v; });  // @263_64ee10
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @264_64ee10
  ecx = edx = 0;  // @265_64ee10
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 129), &v, sizeof v); }  // @266_64ee10
  eax = (u32)(esi + 193);  // @267_64ee10
  PV[15] = (u32)(eax);  // @268_64ee10
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @269_64ee10
  eax = ext_634d10_cdecl3(PV[15], (u32)(0), (u32)(60));  // @270_64ee10
    // @271_64ee10
  eax = esi;  // @272_64ee10
  SEH_LEAVE();  // @273_64ee10
  return eax;  // @274_64ee10
}
PCREG(64ee10, lifted_64ee10);

extern "C" u32 THISCALL lifted_65cc70(u32 ecx_in) {
  SEH_ENTER(0x66edeb);  // @h_65cc70
  u8 F[0x1220] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x1120);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_65cc70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4284), &v, sizeof v); }  // @1_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1060), sizeof v); (u32)v; });  // @2_65cc70
  edx = (u32)(EBP - 4308);  // @3_65cc70
  ecx = (ecx + (u32)(456));  // @4_65cc70
  FL[3] = ecx;  // @5_65cc70
  PV[0] = (u32)(edx);  // @6_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @8_65cc70
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @9_65cc70
  ecx = edx = 0;  // @10_65cc70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @11_65cc70
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @12_65cc70
  X0[2] = 0;  // @13_65cc70
  X0[3] = 0;  // @14_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @15_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @16_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @17_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4280), &v, sizeof v); }  // @18_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @19_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4268), &v, sizeof v); }  // @20_65cc70
  FL[2] = (eax & eax);  // @21_65cc70
  if (FL[2] == 0) goto L65d055;  // @22_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @23_65cc70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4264), &v, sizeof v); }  // @24_65cc70
  L65ccf0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1060), sizeof v); (u32)v; });  // @27_65cc70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @28_65cc70
  PV[1] = (u32)(edi);  // @29_65cc70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4272), &v, sizeof v); }  // @30_65cc70
  eax = ext_640c10_thiscall2(ecx, PV[1]);  // @31_65cc70
  ecx = edx = 0;  // @32_65cc70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @33_65cc70
  if (FL[2] == 0) goto L65d00d;  // @34_65cc70
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; }) & (u32)(4096));  // @35_65cc70
  if (FL[2] == 0) goto L65d00d;  // @36_65cc70
  eax = (u32)(EBP - 64);  // @37_65cc70
  ecx = edi;  // @38_65cc70
  PV[2] = (u32)(eax);  // @39_65cc70
  eax = ext_4daf90_thiscall2(ecx, PV[2]);  // @40_65cc70
  edx = 0;  // @41_65cc70
  eax = (u32)(EBP - 64);  // @42_65cc70
  ecx = edi;  // @43_65cc70
  PV[3] = (u32)(eax);  // @44_65cc70
  eax = ext_4db670_thiscall2(ecx, PV[3]);  // @45_65cc70
  ecx = edx = 0;  // @46_65cc70
  eax = (u32)(EBP - 40);  // @47_65cc70
  ecx = edi;  // @48_65cc70
  PV[4] = (u32)(eax);  // @49_65cc70
  eax = ext_4db7c0_thiscall2(ecx, PV[4]);  // @50_65cc70
  edx = 0;  // @51_65cc70
  ecx = edi;  // @52_65cc70
  eax = ext_4dafb0_thiscall1(ecx);  // @53_65cc70
  ecx = edx = 0;  // @54_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4288), &v, sizeof v); }  // @55_65cc70
  FL[2] = (eax & eax);  // @56_65cc70
  if (FL[2] == 0) goto L65d00d;  // @57_65cc70
  ecx = eax;  // @58_65cc70
  eax = ext_4db550_thiscall1(ecx);  // @59_65cc70
  ecx = edx = 0;  // @60_65cc70
  edi = eax;  // @61_65cc70
  FL[2] = (edi & edi);  // @62_65cc70
  if (FL[2] == 0) goto L65d00d;  // @63_65cc70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; })) & 0xff);  // @64_65cc70
  ecx = 0;  // @65_65cc70
  FL[3] = ecx;  // @66_65cc70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @67_65cc70
  if (FL[2] == 0) goto L65cd6e;  // @68_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_65cc70
  L65cd6e:;
  FL[2] = (ecx & ecx);  // @71_65cc70
  if (FL[2] != 0) goto L65cdd9;  // @72_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @73_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @75_65cc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7096360), (u32)(923));  // @76_65cc70
  ecx = edx = 0;  // @77_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4272), sizeof v); (u32)v; });  // @78_65cc70
  edi = eax;  // @79_65cc70
  eax = (u32)(EBP - 4252);  // @80_65cc70
  PV[5] = (u32)(eax);  // @81_65cc70
  eax = ext_4da2f0_thiscall3(ecx, PV[5], (u32)(1));  // @82_65cc70
  ecx = edx = 0;  // @83_65cc70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_65cc70
  ecx = eax;  // @85_65cc70
  reg.state = (s32)((u32)(0));  // @86_65cc70
  eax = ext_4cc1d0_thiscall1(ecx);  // @87_65cc70
    // @88_65cc70
  PV[6] = (u32)(eax);  // @89_65cc70
  PV[7] = (u32)(edi);  // @90_65cc70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[7], (u32)(7096480), PV[6]);  // @91_65cc70
  ecx = edx = 0;  // @92_65cc70
  reg.state = (s32)((u32)(4294967295));  // @93_65cc70
  ecx = (u32)(EBP - 4252);  // @94_65cc70
  eax = ext_4cbec0_thiscall1(ecx);  // @95_65cc70
  ecx = edx = 0;  // @96_65cc70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4284), sizeof v); (u32)v; });  // @97_65cc70
  goto L65d00d;  // @98_65cc70
  L65cdd9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 856), sizeof v); (u32)v; });  // @101_65cc70
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @102_65cc70
  ecx = edx = 0;  // @103_65cc70
  FL[2] = (eax & eax);  // @104_65cc70
  if (FL[2] == 0) goto L65d00d;  // @105_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @106_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 576), sizeof v); (u32)v; });  // @108_65cc70
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @109_65cc70
  ecx = edx = 0;  // @110_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @111_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4276), &v, sizeof v); }  // @112_65cc70
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @113_65cc70
  edi = 0;  // @114_65cc70
  FL[3] = edi;  // @115_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4296), &v, sizeof v); }  // @116_65cc70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4260), &v, sizeof v); }  // @117_65cc70
  FL[2] = (eax & eax);  // @118_65cc70
  if (FL[2] == 0) goto L65d00d;  // @119_65cc70
  L65ce20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4288), sizeof v); (u32)v; });  // @121_65cc70
  eax = ext_4db550_thiscall1(ecx);  // @122_65cc70
  ecx = edx = 0;  // @123_65cc70
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @124_65cc70
  FL[0] = edi; FL[1] = ecx;  // @125_65cc70
  if (FL[0] >= FL[1]) goto L65ce3e;  // @126_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @127_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4256), &v, sizeof v); }  // @128_65cc70
  goto L65ce48;  // @129_65cc70
  L65ce3e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4256), &v, sizeof v); }  // @131_65cc70
  L65ce48:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4276), sizeof v); (u32)v; });  // @133_65cc70
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(65536));  // @134_65cc70
  if (FL[2] == 0) goto L65cffa;  // @135_65cc70
  PV[8] = (u32)(eax);  // @136_65cc70
  ecx = esi;  // @137_65cc70
  eax = ext_65cb00_thiscall2(ecx, PV[8]);  // @138_65cc70
  ecx = edx = 0;  // @139_65cc70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @140_65cc70
  if (FL[2] == 0) goto L65cffa;  // @141_65cc70
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4272), sizeof v); (u32)v; });  // @142_65cc70
  ecx = esi;  // @143_65cc70
  eax = ext_65ca80_thiscall2(ecx, PV[9]);  // @144_65cc70
  ecx = edx = 0;  // @145_65cc70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @146_65cc70
  if (FL[2] == 0) goto L65cfd6;  // @147_65cc70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4276), sizeof v); (u32)v; });  // @148_65cc70
  eax = (u32)(EBP - 124);  // @149_65cc70
  PV[10] = (u32)(eax);  // @150_65cc70
  ecx = edi;  // @151_65cc70
  eax = ext_4db2a0_thiscall2(ecx, PV[10]);  // @152_65cc70
  ecx = edx = 0;  // @153_65cc70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @154_65cc70
  X0[1] = 0;  // @155_65cc70
  X0[2] = 0;  // @156_65cc70
  X0[3] = 0;  // @157_65cc70
  edx = (u32)(EBP - 52);  // @158_65cc70
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @159_65cc70
  X2[1] = 0;  // @160_65cc70
  X2[2] = 0;  // @161_65cc70
  X2[3] = 0;  // @162_65cc70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @163_65cc70
  X1[1] = 0;  // @164_65cc70
  X1[2] = 0;  // @165_65cc70
  X1[3] = 0;  // @166_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @167_65cc70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @168_65cc70
  X0[1] = 0;  // @169_65cc70
  X0[2] = 0;  // @170_65cc70
  X0[3] = 0;  // @171_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @172_65cc70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @173_65cc70
  X0[1] = 0;  // @174_65cc70
  X0[2] = 0;  // @175_65cc70
  X0[3] = 0;  // @176_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @177_65cc70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @178_65cc70
  X0[1] = 0;  // @179_65cc70
  X0[2] = 0;  // @180_65cc70
  X0[3] = 0;  // @181_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @182_65cc70
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @183_65cc70
  PV[11] = (u32)(ecx);  // @184_65cc70
  ecx = (u32)(EBP - 88);  // @185_65cc70
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @186_65cc70
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @187_65cc70
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @188_65cc70
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @189_65cc70
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @190_65cc70
  SD(&X1[0], U2D(X1[0], X1[1]) / U2D(X0[0], X0[1]));  // @191_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X2[0], 4);  // @192_65cc70
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @193_65cc70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7096556) + 0), 4); v; })));  // @194_65cc70
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @195_65cc70
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @196_65cc70
  PV[12] = X0[0];  // @197_65cc70
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[12]);  // @198_65cc70
    // @199_65cc70
  eax = (u32)(EBP - 88);  // @200_65cc70
  PV[13] = (u32)(eax);  // @201_65cc70
  edx = (u32)(EBP - 64);  // @202_65cc70
  ecx = (u32)(EBP - 76);  // @203_65cc70
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[13]);  // @204_65cc70
  ecx = edx = 0;  // @205_65cc70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4256), sizeof v); (u32)v; });  // @206_65cc70
  ecx = (u32)(EBP - 76);  // @207_65cc70
  PV[14] = (u32)(ecx);  // @208_65cc70
  ecx = (u32)(EBP - 124);  // @209_65cc70
  PV[15] = (u32)(ecx);  // @210_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @211_65cc70
  ecx = edi;  // @212_65cc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[15], PV[14]);  // @213_65cc70
  ecx = edx = 0;  // @214_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @215_65cc70
  edx = (u32)(EBP - 28);  // @216_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @217_65cc70
  PV[16] = (u32)(edx);  // @218_65cc70
  edx = (u32)(EBP - 76);  // @219_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @220_65cc70
  PV[17] = (u32)(edx);  // @221_65cc70
  edx = (u32)(EBP - 124);  // @222_65cc70
  PV[18] = (u32)(edx);  // @223_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_65cc70
  edx = (u32)(EBP - 124);  // @225_65cc70
  PV[19] = (u32)(edi);  // @226_65cc70
  PV[20] = (u32)(edx);  // @227_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @228_65cc70
  edx = (u32)(EBP - 4124);  // @229_65cc70
  PV[21] = (u32)(edx);  // @230_65cc70
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[21], PV[20], PV[19], (u32)(0), PV[18], PV[17], PV[16], (u32)(-1), (u32)(1), (u32)(0), (u32)(1));  // @231_65cc70
  ecx = edx = 0;  // @232_65cc70
  edi = 0;  // @233_65cc70
  FL[3] = edi;  // @234_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4292), &v, sizeof v); }  // @235_65cc70
  FL[2] = (eax & eax);  // @236_65cc70
  if (FL[2] == 0) goto L65cfb4;  // @237_65cc70
  L65cf70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi*4 - 4124), sizeof v); (u32)v; });  // @239_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4256), &v, sizeof v); }  // @240_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @241_65cc70
  ecx = (ecx & (u32)(135168));  // @242_65cc70
  FL[3] = ecx;  // @243_65cc70
  FL[0] = ecx; FL[1] = (u32)(135168);  // @244_65cc70
  if (FL[0] != FL[1]) goto L65cfab;  // @245_65cc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1060), sizeof v); (u32)v; });  // @246_65cc70
  PV[22] = (u32)(eax);  // @247_65cc70
  eax = ext_640c90_thiscall2(ecx, PV[22]);  // @248_65cc70
    // @249_65cc70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @250_65cc70
  if (FL[2] == 0) goto L65cfab;  // @251_65cc70
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4256), sizeof v); (u32)v; });  // @252_65cc70
  ecx = esi;  // @253_65cc70
  eax = ext_65da30_thiscall2(ecx, PV[23]);  // @254_65cc70
  ecx = edx = 0;  // @255_65cc70
  L65cfab:;
  edi = (edi + 1);  // @257_65cc70
  FL[3] = edi;  // @258_65cc70
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4292), sizeof v); (u32)v; });  // @259_65cc70
  if (FL[0] < FL[1]) goto L65cf70;  // @260_65cc70
  L65cfb4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1036), sizeof v); (u32)v; });  // @262_65cc70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4260), sizeof v); (u32)v; });  // @263_65cc70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @264_65cc70
  if (FL[0] != FL[1]) goto L65cfd6;  // @265_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1032), sizeof v); (u32)v; });  // @266_65cc70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1052), sizeof v); (u32)v; }) + (u32)(-8))); __builtin_memcpy((void *)(u32)(esi + 1052), &v, sizeof v); }  // @267_65cc70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1052), sizeof v); (u32)v; });  // @268_65cc70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @269_65cc70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @270_65cc70
  L65cfd6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1032), sizeof v); (u32)v; });  // @272_65cc70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @273_65cc70
  if (FL[0] != FL[1]) goto L65cff1;  // @274_65cc70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1052), sizeof v); (u32)v; }) + (u32)(-12))); __builtin_memcpy((void *)(u32)(esi + 1052), &v, sizeof v); }  // @275_65cc70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1052), sizeof v); (u32)v; });  // @276_65cc70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1040), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 1040), &v, sizeof v); }  // @277_65cc70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1040), sizeof v); (u32)v; });  // @278_65cc70
  goto L65cffa;  // @279_65cc70
  L65cff1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1052), sizeof v); (u32)v; });  // @281_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @282_65cc70
  L65cffa:;
  edi = (edi + 1);  // @284_65cc70
  FL[3] = edi;  // @285_65cc70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4260), &v, sizeof v); }  // @286_65cc70
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4296), sizeof v); (u32)v; });  // @287_65cc70
  if ((s32)FL[0] < (s32)FL[1]) goto L65ce20;  // @288_65cc70
  L65d00d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4264), sizeof v); (u32)v; });  // @290_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4280), sizeof v); (u32)v; });  // @291_65cc70
  ecx = (ecx + 1);  // @292_65cc70
  FL[3] = ecx;  // @293_65cc70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4264), &v, sizeof v); }  // @294_65cc70
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @295_65cc70
  if (FL[0] != FL[1]) goto L65d03e;  // @296_65cc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @297_65cc70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4280), &v, sizeof v); }  // @298_65cc70
  FL[2] = (eax & eax);  // @299_65cc70
  if (FL[2] == 0) goto L65d055;  // @300_65cc70
  ecx = 0;  // @301_65cc70
  FL[3] = ecx;  // @302_65cc70
  eax = (eax + (u32)(16));  // @303_65cc70
  FL[3] = eax;  // @304_65cc70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4264), &v, sizeof v); }  // @305_65cc70
  goto L65d047;  // @306_65cc70
  L65d03e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4268), sizeof v); (u32)v; });  // @308_65cc70
  eax = (eax + (u32)(4));  // @309_65cc70
  FL[3] = eax;  // @310_65cc70
  L65d047:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4268), &v, sizeof v); }  // @312_65cc70
  FL[2] = (eax & eax);  // @313_65cc70
  if (FL[2] != 0) goto L65ccf0;  // @314_65cc70
  L65d055:;
  SEH_LEAVE();  // @316_65cc70
  ext_633654(G(u32, 0x6f5630));  // @317_65cc70
  return eax;  // @318_65cc70
}
PCREG(65cc70, lifted_65cc70);

extern "C" u32 STDCALL lifted_428b60(u32 a0, u32 a1) {
  u32 nm_ = 0;
  SEH_ENTER(0x664847);  // @h_428b60
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @1_428b60
  FL[2] = (eax & (u32)(65536));  // @2_428b60
  if (FL[2] != 0) goto L428e0a;  // @3_428b60
  eax = (eax & 0xff);  // @4_428b60
  eax = (eax + (u32)(-17));  // @5_428b60
  FL[3] = eax;  // @6_428b60
  FL[0] = eax; FL[1] = (u32)(11);  // @7_428b60
  if (FL[0] > FL[1]) goto L428dfb;  // @8_428b60
  switch (eax) {  // @9_428b60
  case 0: goto L428bab;  // @10_428b60
  case 1: goto L428cf5;  // @11_428b60
  case 2: goto L428c8c;  // @12_428b60
  case 3: goto L428dfb;  // @13_428b60
  case 4: goto L428c23;  // @14_428b60
  case 5: goto L428bd3;  // @15_428b60
  case 6: goto L428bfb;  // @16_428b60
  case 7: goto L428dab;  // @17_428b60
  case 8: goto L428dd3;  // @18_428b60
  case 9: goto L428d5b;  // @19_428b60
  case 10: goto L428dfb;  // @20_428b60
  case 11: goto L428d83;  // @21_428b60
  default: __builtin_trap(); }  // @22_428b60
  L428bab:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @24_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(303));  // @26_428b60
  ecx = edx = 0;  // @27_428b60
  PV[0] = (u32)(eax);  // @28_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @29_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6786960));  // @30_428b60
  ecx = edx = 0;  // @31_428b60
  goto L428f50;  // @32_428b60
  L428bd3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(308));  // @36_428b60
  ecx = edx = 0;  // @37_428b60
  PV[1] = (u32)(eax);  // @38_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6786992));  // @40_428b60
  ecx = edx = 0;  // @41_428b60
  goto L428f50;  // @42_428b60
  L428bfb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @44_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(313));  // @46_428b60
  ecx = edx = 0;  // @47_428b60
  PV[2] = (u32)(eax);  // @48_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @49_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6787052));  // @50_428b60
  ecx = edx = 0;  // @51_428b60
  goto L428f50;  // @52_428b60
  L428c23:;
  ecx = (u32)(esi + 20);  // @54_428b60
  eax = ext_429470_thiscall1(ecx);  // @55_428b60
  ecx = edx = 0;  // @56_428b60
  FL[2] = (eax & eax);  // @57_428b60
  if (FL[2] != 0) goto L428f50;  // @58_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(320));  // @61_428b60
  ecx = edx = 0;  // @62_428b60
  PV[3] = (u32)(eax);  // @63_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_428b60
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6787112));  // @65_428b60
  ecx = edx = 0;  // @66_428b60
  eax = ext_41e290_cdecl1((u32)(178));  // @67_428b60
  ecx = edx = 0;  // @68_428b60
  ecx = eax;  // @69_428b60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @70_428b60
  reg.state = (s32)((u32)(0));  // @71_428b60
  FL[2] = (ecx & ecx);  // @72_428b60
  if (FL[2] == 0) goto L428f30;  // @73_428b60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @74_428b60
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 4), 4); v; });  // @75_428b60
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 8), 4); v; });  // @76_428b60
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 12), 4); v; });  // @77_428b60
  eax = 0;  // @78_428b60
  PV[4] = X0[0];  // @79_428b60
  PV[5] = X0[1];  // @80_428b60
  PV[6] = X0[2];  // @81_428b60
  PV[7] = X0[3];  // @82_428b60
  eax = ext_428440_thiscall5(ecx, PV[4], PV[5], PV[6], PV[7]);  // @83_428b60
  ecx = edx = 0;  // @84_428b60
  edi = eax;  // @85_428b60
  goto L428f32;  // @86_428b60
  L428c8c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @88_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(330));  // @90_428b60
  ecx = edx = 0;  // @91_428b60
  PV[8] = (u32)(eax);  // @92_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @93_428b60
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[8], (u32)(6787152));  // @94_428b60
  ecx = edx = 0;  // @95_428b60
  eax = ext_41e290_cdecl1((u32)(434));  // @96_428b60
  ecx = edx = 0;  // @97_428b60
  ecx = eax;  // @98_428b60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @99_428b60
  reg.state = (s32)((u32)(1));  // @100_428b60
  FL[2] = (ecx & ecx);  // @101_428b60
  if (FL[2] == 0) goto L428cde;  // @102_428b60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @103_428b60
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 4), 4); v; });  // @104_428b60
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 8), 4); v; });  // @105_428b60
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 12), 4); v; });  // @106_428b60
  eax = 0;  // @107_428b60
  PV[9] = X0[0];  // @108_428b60
  PV[10] = X0[1];  // @109_428b60
  PV[11] = X0[2];  // @110_428b60
  PV[12] = X0[3];  // @111_428b60
  eax = ext_4284f0_thiscall5(ecx, PV[9], PV[10], PV[11], PV[12]);  // @112_428b60
  ecx = edx = 0;  // @113_428b60
  edi = eax;  // @114_428b60
  goto L428ce0;  // @115_428b60
  L428cde:;
  edi = 0;  // @117_428b60
  FL[3] = edi;  // @118_428b60
  L428ce0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @120_428b60
  PV[13] = (u32)(edi);  // @121_428b60
  reg.state = (s32)((u32)(4294967295));  // @122_428b60
  eax = ext_435d50_thiscall2(ecx, PV[13]);  // @123_428b60
  edx = 0;  // @124_428b60
  goto L428f42;  // @125_428b60
  L428cf5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @127_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(340));  // @129_428b60
  ecx = edx = 0;  // @130_428b60
  PV[14] = (u32)(eax);  // @131_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @132_428b60
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[14], (u32)(6787196));  // @133_428b60
  ecx = edx = 0;  // @134_428b60
  eax = ext_41e290_cdecl1((u32)(70));  // @135_428b60
  ecx = edx = 0;  // @136_428b60
  ecx = eax;  // @137_428b60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @138_428b60
  reg.state = (s32)((u32)(2));  // @139_428b60
  FL[2] = (ecx & ecx);  // @140_428b60
  if (FL[2] == 0) goto L428d44;  // @141_428b60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @142_428b60
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 4), 4); v; });  // @143_428b60
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 8), 4); v; });  // @144_428b60
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 12), 4); v; });  // @145_428b60
  eax = 0;  // @146_428b60
  PV[15] = X0[0];  // @147_428b60
  PV[16] = X0[1];  // @148_428b60
  PV[17] = X0[2];  // @149_428b60
  PV[18] = X0[3];  // @150_428b60
  eax = ext_428560_thiscall5(ecx, PV[15], PV[16], PV[17], PV[18]);  // @151_428b60
  ecx = edx = 0;  // @152_428b60
  edi = eax;  // @153_428b60
  goto L428d46;  // @154_428b60
  L428d44:;
  edi = 0;  // @156_428b60
  FL[3] = edi;  // @157_428b60
  L428d46:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @159_428b60
  PV[19] = (u32)(edi);  // @160_428b60
  reg.state = (s32)((u32)(4294967295));  // @161_428b60
  eax = ext_435d70_thiscall2(ecx, PV[19]);  // @162_428b60
  edx = 0;  // @163_428b60
  goto L428f42;  // @164_428b60
  L428d5b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @166_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(350));  // @168_428b60
  ecx = edx = 0;  // @169_428b60
  PV[20] = (u32)(eax);  // @170_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @171_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[20], (u32)(6787236));  // @172_428b60
  ecx = edx = 0;  // @173_428b60
  goto L428f50;  // @174_428b60
  L428d83:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @176_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(355));  // @178_428b60
  ecx = edx = 0;  // @179_428b60
  PV[21] = (u32)(eax);  // @180_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @181_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[21], (u32)(6787296));  // @182_428b60
  ecx = edx = 0;  // @183_428b60
  goto L428f50;  // @184_428b60
  L428dab:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @186_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @187_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(360));  // @188_428b60
  ecx = edx = 0;  // @189_428b60
  PV[22] = (u32)(eax);  // @190_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @191_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[22], (u32)(6787360));  // @192_428b60
  ecx = edx = 0;  // @193_428b60
  goto L428f50;  // @194_428b60
  L428dd3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @196_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(365));  // @198_428b60
  ecx = edx = 0;  // @199_428b60
  PV[23] = (u32)(eax);  // @200_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @201_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[23], (u32)(6787432));  // @202_428b60
  ecx = edx = 0;  // @203_428b60
  goto L428f50;  // @204_428b60
  L428dfb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @206_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_428b60
  nm_ = 370; goto L428e2e;  // @208_428b60
  L428e0a:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 37), sizeof v); (u32)v; });  // @210_428b60
  eax = (eax - (u32)(1));  // @211_428b60
  FL[3] = eax;  // @212_428b60
  if (FL[3] == 0) goto L428ed2;  // @213_428b60
  eax = (eax - (u32)(1));  // @214_428b60
  FL[3] = eax;  // @215_428b60
  if (FL[3] == 0) goto L428e70;  // @216_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @217_428b60
  eax = (eax - (u32)(1));  // @218_428b60
  FL[3] = eax;  // @219_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @220_428b60
  if (FL[3] == 0) goto L428e50;  // @221_428b60
  nm_ = 418;
  L428e2e:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), nm_);  // @223_428b60
  ecx = edx = 0;  // @224_428b60
  ecx = (u32)(esi + 300);  // @225_428b60
  PV[24] = (u32)(ecx);  // @226_428b60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @227_428b60
  PV[25] = (u32)(eax);  // @228_428b60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[25], (u32)(6787504), PV[24]);  // @229_428b60
  ecx = edx = 0;  // @230_428b60
  goto L428f50;  // @231_428b60
  L428e50:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(412));  // @233_428b60
  ecx = edx = 0;  // @234_428b60
  PV[26] = (u32)(eax);  // @235_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @236_428b60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[26], (u32)(6787688));  // @237_428b60
  ecx = edx = 0;  // @238_428b60
  goto L428f50;  // @239_428b60
  L428e70:;
  ecx = (u32)(esi + 20);  // @241_428b60
  eax = ext_429470_thiscall1(ecx);  // @242_428b60
  ecx = edx = 0;  // @243_428b60
  FL[2] = (eax & eax);  // @244_428b60
  if (FL[2] != 0) goto L428f50;  // @245_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @246_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @247_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(401));  // @248_428b60
  ecx = edx = 0;  // @249_428b60
  PV[27] = (u32)(eax);  // @250_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @251_428b60
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[27], (u32)(6787620));  // @252_428b60
  ecx = edx = 0;  // @253_428b60
  eax = ext_41e290_cdecl1((u32)(178));  // @254_428b60
  ecx = edx = 0;  // @255_428b60
  ecx = eax;  // @256_428b60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @257_428b60
  reg.state = (s32)((u32)(4));  // @258_428b60
  FL[2] = (ecx & ecx);  // @259_428b60
  if (FL[2] == 0) goto L428f30;  // @260_428b60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @261_428b60
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 4), 4); v; });  // @262_428b60
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 8), 4); v; });  // @263_428b60
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 12), 4); v; });  // @264_428b60
  eax = 0;  // @265_428b60
  PV[28] = X0[0];  // @266_428b60
  PV[29] = X0[1];  // @267_428b60
  PV[30] = X0[2];  // @268_428b60
  PV[31] = X0[3];  // @269_428b60
  eax = ext_428440_thiscall5(ecx, PV[28], PV[29], PV[30], PV[31]);  // @270_428b60
  ecx = edx = 0;  // @271_428b60
  edi = eax;  // @272_428b60
  goto L428f32;  // @273_428b60
  L428ed2:;
  ecx = (u32)(esi + 20);  // @275_428b60
  eax = ext_429470_thiscall1(ecx);  // @276_428b60
  ecx = edx = 0;  // @277_428b60
  FL[2] = (eax & eax);  // @278_428b60
  if (FL[2] != 0) goto L428f50;  // @279_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @280_428b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @281_428b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6786908), (u32)(388));  // @282_428b60
  ecx = edx = 0;  // @283_428b60
  PV[32] = (u32)(eax);  // @284_428b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @285_428b60
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[32], (u32)(6787556));  // @286_428b60
  ecx = edx = 0;  // @287_428b60
  eax = ext_41e290_cdecl1((u32)(178));  // @288_428b60
  ecx = edx = 0;  // @289_428b60
  ecx = eax;  // @290_428b60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @291_428b60
  reg.state = (s32)((u32)(3));  // @292_428b60
  FL[2] = (ecx & ecx);  // @293_428b60
  if (FL[2] == 0) goto L428f30;  // @294_428b60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @295_428b60
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 4), 4); v; });  // @296_428b60
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 8), 4); v; });  // @297_428b60
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 12), 4); v; });  // @298_428b60
  eax = 0;  // @299_428b60
  PV[33] = X0[0];  // @300_428b60
  PV[34] = X0[1];  // @301_428b60
  PV[35] = X0[2];  // @302_428b60
  PV[36] = X0[3];  // @303_428b60
  eax = ext_428440_thiscall5(ecx, PV[33], PV[34], PV[35], PV[36]);  // @304_428b60
  ecx = edx = 0;  // @305_428b60
  edi = eax;  // @306_428b60
  goto L428f32;  // @307_428b60
  L428f30:;
  edi = 0;  // @309_428b60
  FL[3] = edi;  // @310_428b60
  L428f32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @312_428b60
  PV[37] = (u32)(edi);  // @313_428b60
  reg.state = (s32)((u32)(4294967295));  // @314_428b60
  eax = ext_435d30_thiscall2(ecx, PV[37]);  // @315_428b60
  edx = 0;  // @316_428b60
  L428f42:;
  eax = (u32)(esi + 300);  // @318_428b60
  ecx = edi;  // @319_428b60
  PV[38] = (u32)(eax);  // @320_428b60
  eax = ext_4361a0_thiscall2(ecx, PV[38]);  // @321_428b60
  ecx = edx = 0;  // @322_428b60
  L428f50:;
  eax = (u32)(1);  // @324_428b60
  SEH_LEAVE();  // @325_428b60
  return eax;  // @326_428b60
}
PCREG(428b60, lifted_428b60);

