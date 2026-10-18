// batch244039.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_425b10_fastcall4(u32, u32, u32, u32) __asm__("ext_425b10");
extern "C" u32 FASTCALL ext_663bd0_fastcall2(u32, u32) __asm__("ext_663bd0");
extern "C" u32 THISCALL ext_64a7f0_thiscall4(u32, u32, u32, u32) __asm__("ext_64a7f0");
extern "C" u32 ext_42ac56_cdecl4(...) __asm__("ext_42ac56");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_4253e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u32 nm_ = 0;
  u8 F[0x12b0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x11b0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x11b0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x11b0 + 12, &a1, 4);
  __builtin_memcpy(F + 0x11b0 + 16, &a2, 4);
  __builtin_memcpy(F + 0x11b0 + 20, &a3, 4);
  __builtin_memcpy(F + 0x11b0 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_4253e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4464), &v, sizeof v); }  // @1_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @2_4253e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4448), &v, sizeof v); }  // @3_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4253e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_4253e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @6_4253e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_4253e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4460), &v, sizeof v); }  // @8_4253e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_4253e0
  FL[2] = (ecx & ecx);  // @10_4253e0
  if (FL[2] == 0) goto L42542f;  // @11_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4253e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @13_4253e0
  ecx = edx = 0;  // @14_4253e0
  L42542f:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4448), sizeof v); (u32)v; });  // @16_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6761bc))((u32)(0), PV[0], (u32)(6785016), (u32)(262164));  // @17_4253e0
  ecx = edx = 0;  // @18_4253e0
  FL[0] = eax; FL[1] = (u32)(6);  // @19_4253e0
  if (FL[0] != FL[1]) goto L425796;  // @20_4253e0
  eax = (u32)(EBP - 4456);  // @21_4253e0
  { u32 v = (u32)((u32)(257)); __builtin_memcpy((void *)(u32)(EBP - 4444), &v, sizeof v); }  // @22_4253e0
  PV[1] = (u32)(eax);  // @23_4253e0
  eax = (u32)(EBP - 64);  // @24_4253e0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 4456), &v, sizeof v); }  // @25_4253e0
  PV[2] = (u32)(eax);  // @26_4253e0
  edx = (u32)(EBP - 4444);  // @27_4253e0
  ecx = (u32)(EBP - 324);  // @28_4253e0
  eax = ext_425b10_fastcall4(ecx, edx, PV[2], PV[1]);  // @29_4253e0
  ecx = edx = 0;  // @30_4253e0
  FL[2] = (eax & eax);  // @31_4253e0
  if (FL[2] != 0) goto L4254b4;  // @32_4253e0
  eax = (u32)(EBP - 4444);  // @33_4253e0
  { u32 v = (u32)((u32)(257)); __builtin_memcpy((void *)(u32)(EBP - 4444), &v, sizeof v); }  // @34_4253e0
  PV[3] = (u32)(eax);  // @35_4253e0
  eax = (u32)(EBP - 324);  // @36_4253e0
  PV[4] = (u32)(eax);  // @37_4253e0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676008))(PV[4], PV[3]);  // @38_4253e0
  ecx = edx = 0;  // @39_4253e0
  FL[1] = eax;  // @40_4253e0
  eax = (0u - eax);  // @41_4253e0
  eax = (eax & 0xffffff00u) | (((0u - (u32)(FL[1] != 0))) & 0xff);  // @42_4253e0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; }))) & 0xff);  // @43_4253e0
  FL[3] = (eax & 0xff);  // @44_4253e0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @45_4253e0
  goto L4254ba;  // @46_4253e0
  L4254b4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 324), sizeof v); (u32)v; })) & 0xff);  // @48_4253e0
  L4254ba:;
  FL[2] = (ebx & ebx);  // @50_4253e0
  if (FL[2] == 0) goto L425796;  // @51_4253e0
  FL[2] = (edi & edi);  // @52_4253e0
  if (FL[2] != 0) goto L42550b;  // @53_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @54_4253e0
  eax = (u32)(EBP - 324);  // @55_4253e0
  PV[5] = (u32)(eax);  // @56_4253e0
  eax = (u32)(EBP - 4420);  // @57_4253e0
  nm_ = (FL[2] == 0) ? 0x67881c : 0x678808;  // @58_4253e0 (diamond of pushes: one format argument)
  L4254de:;
  L4254e3:;
  PV[6] = (u32)(eax);  // @62_4253e0
  eax = ext_42ac56_cdecl4(PV[6], nm_, PV[5]);  // @63_4253e0
  ecx = edx = 0;  // @64_4253e0
  ecx = eax;  // @65_4253e0
  eax = (u32)(4095);  // @66_4253e0
  eax = (eax - ecx);  // @67_4253e0
  FL[3] = eax;  // @68_4253e0
  PV[7] = (u32)(eax);  // @69_4253e0
  eax = (u32)(EBP - 4420);  // @70_4253e0
  eax = (eax + ecx);  // @71_4253e0
  FL[3] = eax;  // @72_4253e0
  PV[8] = (u32)(eax);  // @73_4253e0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6762a4))(PV[8], PV[7]);  // @74_4253e0
  ecx = edx = 0;  // @75_4253e0
  edi = (u32)(EBP - 4420);  // @76_4253e0
  L42550b:;
  eax = (u32)(2);  // @78_4253e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 4436), &v, sizeof v); }  // @79_4253e0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6762c0))((u32)(25));  // @80_4253e0
  ecx = edx = 0;  // @81_4253e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 4434), &v, sizeof v); }  // @82_4253e0
  X0[0] = 0;  // @83_4253e0
  X0[1] = 0;  // @84_4253e0
  X0[2] = 0;  // @85_4253e0
  X0[3] = 0;  // @86_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 4428) + 0), &X0[0], 4);  // @87_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 4428) + 4), &X0[1], 4);  // @88_4253e0
  FL[2] = (esi & esi);  // @89_4253e0
  if (FL[2] == 0) goto L425549;  // @90_4253e0
  PV[9] = (u32)(esi);  // @91_4253e0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6762a0))(PV[9]);  // @92_4253e0
  ecx = edx = 0;  // @93_4253e0
  FL[2] = (eax & eax);  // @94_4253e0
  if (FL[2] != 0) goto L425563;  // @95_4253e0
  PV[10] = (u32)(esi);  // @96_4253e0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6762b8))(PV[10]);  // @97_4253e0
  ecx = edx = 0;  // @98_4253e0
  goto L42555d;  // @99_4253e0
  L425549:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7330096), sizeof v); (u32)v; });  // @101_4253e0
  FL[2] = (eax & eax);  // @102_4253e0
  if (FL[2] == 0) goto L425796;  // @103_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @104_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @105_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @106_4253e0
  L42555d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4432), &v, sizeof v); }  // @108_4253e0
  L425563:;
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6762b4))((u32)(2), (u32)(1), (u32)(6));  // @110_4253e0
  ecx = edx = 0;  // @111_4253e0
  esi = eax;  // @112_4253e0
  FL[0] = esi; FL[1] = (u32)(-1);  // @113_4253e0
  if (FL[0] == FL[1]) goto L425796;  // @114_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6785076), sizeof v); (u32)v; });  // @115_4253e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785068) + 0), 4); v; });  // @116_4253e0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785068) + 4), 4); v; });  // @117_4253e0
  X0[2] = 0;  // @118_4253e0
  X0[3] = 0;  // @119_4253e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @120_4253e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6785088), sizeof v); (u32)v; });  // @121_4253e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @122_4253e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6785092), sizeof v); (u32)v; });  // @123_4253e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @124_4253e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6785096), sizeof v); (u32)v; });  // @125_4253e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @126_4253e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6785108), sizeof v); (u32)v; });  // @127_4253e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @128_4253e0
  eax = (u32)(10);  // @129_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @130_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 48) + 4), &X0[1], 4);  // @131_4253e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785080) + 0), 4); v; });  // @132_4253e0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785080) + 4), 4); v; });  // @133_4253e0
  X0[2] = 0;  // @134_4253e0
  X0[3] = 0;  // @135_4253e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 4440), &v, sizeof v); }  // @136_4253e0
  eax = (u32)(EBP - 4436);  // @137_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @138_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 4), &X0[1], 4);  // @139_4253e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785100) + 0), 4); v; });  // @140_4253e0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785100) + 4), 4); v; });  // @141_4253e0
  X0[2] = 0;  // @142_4253e0
  X0[3] = 0;  // @143_4253e0
  PV[11] = (u32)(eax);  // @144_4253e0
  PV[12] = (u32)(esi);  // @145_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @146_4253e0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 4), &X0[1], 4);  // @147_4253e0
  { u32 v = (u32)((u32)(667146)); __builtin_memcpy((void *)(u32)(EBP - 4452), &v, sizeof v); }  // @148_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6762bc))(PV[12], PV[11], (u32)(16));  // @149_4253e0
  ecx = edx = 0;  // @150_4253e0
  FL[0] = eax; FL[1] = (u32)(-1);  // @151_4253e0
  if (FL[0] == FL[1]) goto L425796;  // @152_4253e0
  ecx = (u32)(EBP - 48);  // @153_4253e0
  edx = (u32)(ecx + 1);  // @154_4253e0
  L425607:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @156_4253e0
  ecx = (ecx + 1);  // @157_4253e0
  FL[3] = ecx;  // @158_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @159_4253e0
  if (FL[2] != 0) goto L425607;  // @160_4253e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775452), sizeof v); (u32)v; });  // @161_4253e0
  eax = (u32)(EBP - 48);  // @162_4253e0
  ecx = (ecx - edx);  // @163_4253e0
  FL[3] = ecx;  // @164_4253e0
  PV[13] = (u32)(ecx);  // @165_4253e0
  PV[14] = (u32)(eax);  // @166_4253e0
  PV[15] = (u32)(esi);  // @167_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[15], PV[14], PV[13], (u32)(0));  // @168_4253e0
  ecx = edx = 0;  // @169_4253e0
  ecx = edi;  // @170_4253e0
  edx = (u32)(ecx + 1);  // @171_4253e0
  L425625:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @173_4253e0
  ecx = (ecx + 1);  // @174_4253e0
  FL[3] = ecx;  // @175_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @176_4253e0
  if (FL[2] != 0) goto L425625;  // @177_4253e0
  ecx = (ecx - edx);  // @178_4253e0
  FL[3] = ecx;  // @179_4253e0
  PV[16] = (u32)(ecx);  // @180_4253e0
  PV[17] = (u32)(edi);  // @181_4253e0
  PV[18] = (u32)(esi);  // @182_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[18], PV[17], PV[16], (u32)(0));  // @183_4253e0
  ecx = edx = 0;  // @184_4253e0
  ecx = (u32)(EBP - 4440);  // @185_4253e0
  edx = (u32)(ecx + 1);  // @186_4253e0
  L425640:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @188_4253e0
  ecx = (ecx + 1);  // @189_4253e0
  FL[3] = ecx;  // @190_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @191_4253e0
  if (FL[2] != 0) goto L425640;  // @192_4253e0
  ecx = (ecx - edx);  // @193_4253e0
  FL[3] = ecx;  // @194_4253e0
  eax = (u32)(EBP - 4440);  // @195_4253e0
  PV[19] = (u32)(ecx);  // @196_4253e0
  PV[20] = (u32)(eax);  // @197_4253e0
  PV[21] = (u32)(esi);  // @198_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[21], PV[20], PV[19], (u32)(0));  // @199_4253e0
  ecx = edx = 0;  // @200_4253e0
  ecx = (u32)(EBP - 24);  // @201_4253e0
  edx = (u32)(ecx + 1);  // @202_4253e0
  L425660:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @204_4253e0
  ecx = (ecx + 1);  // @205_4253e0
  FL[3] = ecx;  // @206_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @207_4253e0
  if (FL[2] != 0) goto L425660;  // @208_4253e0
  ecx = (ecx - edx);  // @209_4253e0
  FL[3] = ecx;  // @210_4253e0
  eax = (u32)(EBP - 24);  // @211_4253e0
  PV[22] = (u32)(ecx);  // @212_4253e0
  PV[23] = (u32)(eax);  // @213_4253e0
  PV[24] = (u32)(esi);  // @214_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[24], PV[23], PV[22], (u32)(0));  // @215_4253e0
  ecx = edx = 0;  // @216_4253e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4460), sizeof v); (u32)v; });  // @217_4253e0
  ecx = edi;  // @218_4253e0
  edx = (u32)(ecx + 1);  // @219_4253e0
  L425680:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @221_4253e0
  ecx = (ecx + 1);  // @222_4253e0
  FL[3] = ecx;  // @223_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @224_4253e0
  if (FL[2] != 0) goto L425680;  // @225_4253e0
  ecx = (ecx - edx);  // @226_4253e0
  FL[3] = ecx;  // @227_4253e0
  PV[25] = (u32)(ecx);  // @228_4253e0
  PV[26] = (u32)(edi);  // @229_4253e0
  PV[27] = (u32)(esi);  // @230_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[27], PV[26], PV[25], (u32)(0));  // @231_4253e0
  ecx = edx = 0;  // @232_4253e0
  ecx = (u32)(EBP - 4440);  // @233_4253e0
  edx = (u32)(ecx + 1);  // @234_4253e0
  L4256a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @236_4253e0
  ecx = (ecx + 1);  // @237_4253e0
  FL[3] = ecx;  // @238_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @239_4253e0
  if (FL[2] != 0) goto L4256a0;  // @240_4253e0
  ecx = (ecx - edx);  // @241_4253e0
  FL[3] = ecx;  // @242_4253e0
  eax = (u32)(EBP - 4440);  // @243_4253e0
  PV[28] = (u32)(ecx);  // @244_4253e0
  PV[29] = (u32)(eax);  // @245_4253e0
  PV[30] = (u32)(esi);  // @246_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[30], PV[29], PV[28], (u32)(0));  // @247_4253e0
  ecx = edx = 0;  // @248_4253e0
  ecx = (u32)(EBP - 12);  // @249_4253e0
  edx = (u32)(ecx + 1);  // @250_4253e0
  L4256c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @252_4253e0
  ecx = (ecx + 1);  // @253_4253e0
  FL[3] = ecx;  // @254_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @255_4253e0
  if (FL[2] != 0) goto L4256c0;  // @256_4253e0
  ecx = (ecx - edx);  // @257_4253e0
  FL[3] = ecx;  // @258_4253e0
  eax = (u32)(EBP - 12);  // @259_4253e0
  PV[31] = (u32)(ecx);  // @260_4253e0
  PV[32] = (u32)(eax);  // @261_4253e0
  PV[33] = (u32)(esi);  // @262_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[33], PV[32], PV[31], (u32)(0));  // @263_4253e0
  ecx = edx = 0;  // @264_4253e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4464), sizeof v); (u32)v; });  // @265_4253e0
  FL[2] = (edi & edi);  // @266_4253e0
  if (FL[2] == 0) goto L425736;  // @267_4253e0
  ecx = (u32)(EBP - 36);  // @268_4253e0
  edx = (u32)(ecx + 1);  // @269_4253e0
  L4256e3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @271_4253e0
  ecx = (ecx + 1);  // @272_4253e0
  FL[3] = ecx;  // @273_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @274_4253e0
  if (FL[2] != 0) goto L4256e3;  // @275_4253e0
  ecx = (ecx - edx);  // @276_4253e0
  FL[3] = ecx;  // @277_4253e0
  eax = (u32)(EBP - 36);  // @278_4253e0
  PV[34] = (u32)(ecx);  // @279_4253e0
  PV[35] = (u32)(eax);  // @280_4253e0
  PV[36] = (u32)(esi);  // @281_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[36], PV[35], PV[34], (u32)(0));  // @282_4253e0
  ecx = edx = 0;  // @283_4253e0
  ecx = edi;  // @284_4253e0
  edx = (u32)(ecx + 1);  // @285_4253e0
  L425700:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @287_4253e0
  ecx = (ecx + 1);  // @288_4253e0
  FL[3] = ecx;  // @289_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @290_4253e0
  if (FL[2] != 0) goto L425700;  // @291_4253e0
  ecx = (ecx - edx);  // @292_4253e0
  FL[3] = ecx;  // @293_4253e0
  PV[37] = (u32)(ecx);  // @294_4253e0
  PV[38] = (u32)(edi);  // @295_4253e0
  PV[39] = (u32)(esi);  // @296_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[39], PV[38], PV[37], (u32)(0));  // @297_4253e0
  ecx = edx = 0;  // @298_4253e0
  ecx = (u32)(EBP - 4440);  // @299_4253e0
  edx = (u32)(ecx + 1);  // @300_4253e0
  L425720:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @302_4253e0
  ecx = (ecx + 1);  // @303_4253e0
  FL[3] = ecx;  // @304_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @305_4253e0
  if (FL[2] != 0) goto L425720;  // @306_4253e0
  ecx = (ecx - edx);  // @307_4253e0
  FL[3] = ecx;  // @308_4253e0
  eax = (u32)(EBP - 4440);  // @309_4253e0
  PV[40] = (u32)(ecx);  // @310_4253e0
  PV[41] = (u32)(eax);  // @311_4253e0
  PV[42] = (u32)(esi);  // @312_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[42], PV[41], PV[40], (u32)(0));  // @313_4253e0
  ecx = edx = 0;  // @314_4253e0
  L425736:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4448), sizeof v); (u32)v; });  // @316_4253e0
  ecx = edi;  // @317_4253e0
  edx = (u32)(ecx + 1);  // @318_4253e0
  L425741:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @320_4253e0
  ecx = (ecx + 1);  // @321_4253e0
  FL[3] = ecx;  // @322_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @323_4253e0
  if (FL[2] != 0) goto L425741;  // @324_4253e0
  ecx = (ecx - edx);  // @325_4253e0
  FL[3] = ecx;  // @326_4253e0
  PV[43] = (u32)(ecx);  // @327_4253e0
  PV[44] = (u32)(edi);  // @328_4253e0
  PV[45] = (u32)(esi);  // @329_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[45], PV[44], PV[43], (u32)(0));  // @330_4253e0
  ecx = edx = 0;  // @331_4253e0
  ecx = (u32)(EBP - 4452);  // @332_4253e0
  edx = (u32)(ecx + 1);  // @333_4253e0
  L425760:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @335_4253e0
  ecx = (ecx + 1);  // @336_4253e0
  FL[3] = ecx;  // @337_4253e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @338_4253e0
  if (FL[2] != 0) goto L425760;  // @339_4253e0
  ecx = (ecx - edx);  // @340_4253e0
  FL[3] = ecx;  // @341_4253e0
  eax = (u32)(EBP - 4452);  // @342_4253e0
  PV[46] = (u32)(ecx);  // @343_4253e0
  PV[47] = (u32)(eax);  // @344_4253e0
  PV[48] = (u32)(esi);  // @345_4253e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(ebx))(PV[48], PV[47], PV[46], (u32)(0));  // @346_4253e0
  ecx = edx = 0;  // @347_4253e0
  PV[49] = (u32)(esi);  // @348_4253e0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6762b0))(PV[49]);  // @349_4253e0
  ecx = edx = 0;  // @350_4253e0
  FL[0] = eax; FL[1] = (u32)(-1);  // @351_4253e0
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @352_4253e0
  ext_633654(G(u32, 0x6f5630));  // @353_4253e0
  return eax;  // @354_4253e0
  L425796:;
  ext_633654(G(u32, 0x6f5630));  // @356_4253e0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @357_4253e0
  FL[3] = (eax & 0xff);  // @358_4253e0
  return eax;  // @359_4253e0
}
PCREG(4253e0, lifted_4253e0);

extern "C" u32 THISCALL lifted_64bb90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @0_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_64bb90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_64bb90
  edx = edi;  // @3_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @4_64bb90
  X0[1] = 0;  // @5_64bb90
  X0[2] = 0;  // @6_64bb90
  X0[3] = 0;  // @7_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @8_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @9_64bb90
  X0[1] = 0;  // @10_64bb90
  X0[2] = 0;  // @11_64bb90
  X0[3] = 0;  // @12_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @13_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @14_64bb90
  X0[1] = 0;  // @15_64bb90
  X0[2] = 0;  // @16_64bb90
  X0[3] = 0;  // @17_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @18_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @19_64bb90
  X0[1] = 0;  // @20_64bb90
  X0[2] = 0;  // @21_64bb90
  X0[3] = 0;  // @22_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @23_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 0), 4); v; });  // @24_64bb90
  X0[1] = 0;  // @25_64bb90
  X0[2] = 0;  // @26_64bb90
  X0[3] = 0;  // @27_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @28_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 20) + 0), 4); v; });  // @29_64bb90
  X0[1] = 0;  // @30_64bb90
  X0[2] = 0;  // @31_64bb90
  X0[3] = 0;  // @32_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @33_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 24) + 0), 4); v; });  // @34_64bb90
  X0[1] = 0;  // @35_64bb90
  X0[2] = 0;  // @36_64bb90
  X0[3] = 0;  // @37_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @38_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 28) + 0), 4); v; });  // @39_64bb90
  X0[1] = 0;  // @40_64bb90
  X0[2] = 0;  // @41_64bb90
  X0[3] = 0;  // @42_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @43_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @44_64bb90
  X0[1] = 0;  // @45_64bb90
  X0[2] = 0;  // @46_64bb90
  X0[3] = 0;  // @47_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @48_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 36) + 0), 4); v; });  // @49_64bb90
  X0[1] = 0;  // @50_64bb90
  X0[2] = 0;  // @51_64bb90
  X0[3] = 0;  // @52_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @53_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 40) + 0), 4); v; });  // @54_64bb90
  X0[1] = 0;  // @55_64bb90
  X0[2] = 0;  // @56_64bb90
  X0[3] = 0;  // @57_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @58_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 44) + 0), 4); v; });  // @59_64bb90
  X0[1] = 0;  // @60_64bb90
  X0[2] = 0;  // @61_64bb90
  X0[3] = 0;  // @62_64bb90
  ecx = (u32)(EBP - 56);  // @63_64bb90
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @64_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @65_64bb90
    // @66_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 12)) :: "st");  // @67_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @68_64bb90
  X0[1] = 0;  // @69_64bb90
  X0[2] = 0;  // @70_64bb90
  X0[3] = 0;  // @71_64bb90
  ecx = (u32)(EBP - 32);  // @72_64bb90
  X1[0] = 0;  // @73_64bb90
  X1[1] = 0;  // @74_64bb90
  X1[2] = 0;  // @75_64bb90
  X1[3] = 0;  // @76_64bb90
  edx = edi;  // @77_64bb90
  { u8 v = (u8)((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @78_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @79_64bb90
    // @80_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 12)) :: "st");  // @81_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @82_64bb90
  X0[1] = 0;  // @83_64bb90
  X0[2] = 0;  // @84_64bb90
  X0[3] = 0;  // @85_64bb90
  ecx = (u32)(EBP - 44);  // @86_64bb90
  X1[0] = 0;  // @87_64bb90
  X1[1] = 0;  // @88_64bb90
  X1[2] = 0;  // @89_64bb90
  X1[3] = 0;  // @90_64bb90
  edx = edi;  // @91_64bb90
  { u8 v = (u8)((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @92_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @93_64bb90
    // @94_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @95_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @96_64bb90
  X0[1] = 0;  // @97_64bb90
  X0[2] = 0;  // @98_64bb90
  X0[3] = 0;  // @99_64bb90
  ecx = (u32)(EBP - 68);  // @100_64bb90
  X1[0] = 0;  // @101_64bb90
  X1[1] = 0;  // @102_64bb90
  X1[2] = 0;  // @103_64bb90
  X1[3] = 0;  // @104_64bb90
  edx = edi;  // @105_64bb90
  ebx = (ebx & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @106_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @107_64bb90
    // @108_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @109_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @110_64bb90
  X0[1] = 0;  // @111_64bb90
  X0[2] = 0;  // @112_64bb90
  X0[3] = 0;  // @113_64bb90
  X1[0] = 0;  // @114_64bb90
  X1[1] = 0;  // @115_64bb90
  X1[2] = 0;  // @116_64bb90
  X1[3] = 0;  // @117_64bb90
  ebxh = (ebxh & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @118_64bb90
  eax = (eax & 0xffffff00u) | (((ebxh & 0xff)) & 0xff);  // @119_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (ebx & 0xff))) & 0xff);  // @120_64bb90
  FL[3] = (eax & 0xff);  // @121_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }))) & 0xff);  // @122_64bb90
  FL[3] = (eax & 0xff);  // @123_64bb90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) & (eax & 0xff));  // @124_64bb90
  if (FL[2] == 0) goto L64bc9c;  // @125_64bb90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @126_64bb90
  FL[3] = (eax & 0xff);  // @127_64bb90
  return eax;  // @128_64bb90
  L64bc9c:;
  esi = (u32)(edi + 12);  // @130_64bb90
  edx = esi;  // @131_64bb90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @132_64bb90
  ecx = (u32)(EBP - 56);  // @133_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @134_64bb90
    // @135_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @136_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @137_64bb90
  X0[1] = 0;  // @138_64bb90
  X0[2] = 0;  // @139_64bb90
  X0[3] = 0;  // @140_64bb90
  ecx = (u32)(EBP - 32);  // @141_64bb90
  X1[0] = 0;  // @142_64bb90
  X1[1] = 0;  // @143_64bb90
  X1[2] = 0;  // @144_64bb90
  X1[3] = 0;  // @145_64bb90
  edx = esi;  // @146_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @147_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @148_64bb90
  FL[3] = (eax & 0xff);  // @149_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(2))) & 0xff);  // @150_64bb90
  FL[3] = (eax & 0xff);  // @151_64bb90
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) | (eax & 0xff))); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @152_64bb90
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; });  // @153_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @154_64bb90
    // @155_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @156_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @157_64bb90
  X0[1] = 0;  // @158_64bb90
  X0[2] = 0;  // @159_64bb90
  X0[3] = 0;  // @160_64bb90
  ecx = (u32)(EBP - 44);  // @161_64bb90
  X1[0] = 0;  // @162_64bb90
  X1[1] = 0;  // @163_64bb90
  X1[2] = 0;  // @164_64bb90
  X1[3] = 0;  // @165_64bb90
  edx = esi;  // @166_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @167_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @168_64bb90
  FL[3] = (eax & 0xff);  // @169_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(2))) & 0xff);  // @170_64bb90
  FL[3] = (eax & 0xff);  // @171_64bb90
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }) | (eax & 0xff))); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @172_64bb90
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; });  // @173_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @174_64bb90
    // @175_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @176_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @177_64bb90
  X0[1] = 0;  // @178_64bb90
  X0[2] = 0;  // @179_64bb90
  X0[3] = 0;  // @180_64bb90
  ecx = (u32)(EBP - 68);  // @181_64bb90
  X1[0] = 0;  // @182_64bb90
  X1[1] = 0;  // @183_64bb90
  X1[2] = 0;  // @184_64bb90
  X1[3] = 0;  // @185_64bb90
  edx = esi;  // @186_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @187_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @188_64bb90
  FL[3] = (eax & 0xff);  // @189_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(2))) & 0xff);  // @190_64bb90
  FL[3] = (eax & 0xff);  // @191_64bb90
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @192_64bb90
  FL[3] = (ebx & 0xff);  // @193_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @194_64bb90
    // @195_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @196_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @197_64bb90
  X0[1] = 0;  // @198_64bb90
  X0[2] = 0;  // @199_64bb90
  X0[3] = 0;  // @200_64bb90
  X1[0] = 0;  // @201_64bb90
  X1[1] = 0;  // @202_64bb90
  X1[2] = 0;  // @203_64bb90
  X1[3] = 0;  // @204_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @205_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @206_64bb90
  FL[3] = (eax & 0xff);  // @207_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(2))) & 0xff);  // @208_64bb90
  FL[3] = (eax & 0xff);  // @209_64bb90
  ebxh = (ebxh & 0xffffff00u) | ((((ebxh & 0xff) | (eax & 0xff))) & 0xff);  // @210_64bb90
  FL[3] = (ebxh & 0xff);  // @211_64bb90
  eax = (eax & 0xffffff00u) | (((ebxh & 0xff)) & 0xff);  // @212_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (ebx & 0xff))) & 0xff);  // @213_64bb90
  FL[3] = (eax & 0xff);  // @214_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }))) & 0xff);  // @215_64bb90
  FL[3] = (eax & 0xff);  // @216_64bb90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) & (eax & 0xff));  // @217_64bb90
  if (FL[2] != 0) goto L64be71;  // @218_64bb90
  esi = (u32)(edi + 24);  // @219_64bb90
  edx = esi;  // @220_64bb90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @221_64bb90
  ecx = (u32)(EBP - 56);  // @222_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @223_64bb90
    // @224_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @225_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @226_64bb90
  X0[1] = 0;  // @227_64bb90
  X0[2] = 0;  // @228_64bb90
  X0[3] = 0;  // @229_64bb90
  ecx = (u32)(EBP - 32);  // @230_64bb90
  X1[0] = 0;  // @231_64bb90
  X1[1] = 0;  // @232_64bb90
  X1[2] = 0;  // @233_64bb90
  X1[3] = 0;  // @234_64bb90
  edx = esi;  // @235_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @236_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @237_64bb90
  FL[3] = (eax & 0xff);  // @238_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(4))) & 0xff);  // @239_64bb90
  FL[3] = (eax & 0xff);  // @240_64bb90
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) | (eax & 0xff))); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @241_64bb90
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; });  // @242_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @243_64bb90
    // @244_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @245_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @246_64bb90
  X0[1] = 0;  // @247_64bb90
  X0[2] = 0;  // @248_64bb90
  X0[3] = 0;  // @249_64bb90
  ecx = (u32)(EBP - 44);  // @250_64bb90
  X1[0] = 0;  // @251_64bb90
  X1[1] = 0;  // @252_64bb90
  X1[2] = 0;  // @253_64bb90
  X1[3] = 0;  // @254_64bb90
  edx = esi;  // @255_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @256_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @257_64bb90
  FL[3] = (eax & 0xff);  // @258_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(4))) & 0xff);  // @259_64bb90
  FL[3] = (eax & 0xff);  // @260_64bb90
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }) | (eax & 0xff))); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @261_64bb90
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; });  // @262_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @263_64bb90
    // @264_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @265_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @266_64bb90
  X0[1] = 0;  // @267_64bb90
  X0[2] = 0;  // @268_64bb90
  X0[3] = 0;  // @269_64bb90
  ecx = (u32)(EBP - 68);  // @270_64bb90
  X1[0] = 0;  // @271_64bb90
  X1[1] = 0;  // @272_64bb90
  X1[2] = 0;  // @273_64bb90
  X1[3] = 0;  // @274_64bb90
  edx = esi;  // @275_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @276_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @277_64bb90
  FL[3] = (eax & 0xff);  // @278_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(4))) & 0xff);  // @279_64bb90
  FL[3] = (eax & 0xff);  // @280_64bb90
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @281_64bb90
  FL[3] = (ebx & 0xff);  // @282_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @283_64bb90
    // @284_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @285_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @286_64bb90
  X0[1] = 0;  // @287_64bb90
  X0[2] = 0;  // @288_64bb90
  X0[3] = 0;  // @289_64bb90
  X1[0] = 0;  // @290_64bb90
  X1[1] = 0;  // @291_64bb90
  X1[2] = 0;  // @292_64bb90
  X1[3] = 0;  // @293_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @294_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @295_64bb90
  FL[3] = (eax & 0xff);  // @296_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(4))) & 0xff);  // @297_64bb90
  FL[3] = (eax & 0xff);  // @298_64bb90
  ebxh = (ebxh & 0xffffff00u) | ((((ebxh & 0xff) | (eax & 0xff))) & 0xff);  // @299_64bb90
  FL[3] = (ebxh & 0xff);  // @300_64bb90
  eax = (eax & 0xffffff00u) | (((ebxh & 0xff)) & 0xff);  // @301_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (ebx & 0xff))) & 0xff);  // @302_64bb90
  FL[3] = (eax & 0xff);  // @303_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }))) & 0xff);  // @304_64bb90
  FL[3] = (eax & 0xff);  // @305_64bb90
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) & (eax & 0xff));  // @306_64bb90
  if (FL[2] != 0) goto L64be71;  // @307_64bb90
  edi = (edi + (u32)(36));  // @308_64bb90
  FL[3] = edi;  // @309_64bb90
  ecx = (u32)(EBP - 56);  // @310_64bb90
  edx = edi;  // @311_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @312_64bb90
    // @313_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @314_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @315_64bb90
  X0[1] = 0;  // @316_64bb90
  X0[2] = 0;  // @317_64bb90
  X0[3] = 0;  // @318_64bb90
  ecx = (u32)(EBP - 32);  // @319_64bb90
  X1[0] = 0;  // @320_64bb90
  X1[1] = 0;  // @321_64bb90
  X1[2] = 0;  // @322_64bb90
  X1[3] = 0;  // @323_64bb90
  edx = edi;  // @324_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @325_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @326_64bb90
  FL[3] = (eax & 0xff);  // @327_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(8))) & 0xff);  // @328_64bb90
  FL[3] = (eax & 0xff);  // @329_64bb90
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) | (eax & 0xff))); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @330_64bb90
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; });  // @331_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @332_64bb90
    // @333_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @334_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @335_64bb90
  X0[1] = 0;  // @336_64bb90
  X0[2] = 0;  // @337_64bb90
  X0[3] = 0;  // @338_64bb90
  ecx = (u32)(EBP - 44);  // @339_64bb90
  X1[0] = 0;  // @340_64bb90
  X1[1] = 0;  // @341_64bb90
  X1[2] = 0;  // @342_64bb90
  X1[3] = 0;  // @343_64bb90
  edx = edi;  // @344_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @345_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @346_64bb90
  FL[3] = (eax & 0xff);  // @347_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(8))) & 0xff);  // @348_64bb90
  FL[3] = (eax & 0xff);  // @349_64bb90
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }) | (eax & 0xff))); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @350_64bb90
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; });  // @351_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @352_64bb90
    // @353_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @354_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @355_64bb90
  X0[1] = 0;  // @356_64bb90
  X0[2] = 0;  // @357_64bb90
  X0[3] = 0;  // @358_64bb90
  ecx = (u32)(EBP - 68);  // @359_64bb90
  X1[0] = 0;  // @360_64bb90
  X1[1] = 0;  // @361_64bb90
  X1[2] = 0;  // @362_64bb90
  X1[3] = 0;  // @363_64bb90
  edx = edi;  // @364_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @365_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @366_64bb90
  FL[3] = (eax & 0xff);  // @367_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(8))) & 0xff);  // @368_64bb90
  FL[3] = (eax & 0xff);  // @369_64bb90
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @370_64bb90
  FL[3] = (ebx & 0xff);  // @371_64bb90
  eax = ext_663bd0_fastcall2(ecx, edx);  // @372_64bb90
    // @373_64bb90
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; })) & 0xff);  // @374_64bb90
  X1[0] = 0;  // @375_64bb90
  X1[1] = 0;  // @376_64bb90
  X1[2] = 0;  // @377_64bb90
  X1[3] = 0;  // @378_64bb90
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @379_64bb90
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 20)) :: "st");  // @380_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @381_64bb90
  X0[1] = 0;  // @382_64bb90
  X0[2] = 0;  // @383_64bb90
  X0[3] = 0;  // @384_64bb90
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @385_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @386_64bb90
  FL[3] = (eax & 0xff);  // @387_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(8))) & 0xff);  // @388_64bb90
  FL[3] = (eax & 0xff);  // @389_64bb90
  ebxh = (ebxh & 0xffffff00u) | ((((ebxh & 0xff) | (eax & 0xff))) & 0xff);  // @390_64bb90
  FL[3] = (ebxh & 0xff);  // @391_64bb90
  eax = (eax & 0xffffff00u) | (((ebxh & 0xff)) & 0xff);  // @392_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (ebx & 0xff))) & 0xff);  // @393_64bb90
  FL[3] = (eax & 0xff);  // @394_64bb90
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 2), &v, sizeof v); }  // @395_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (edx & 0xff))) & 0xff);  // @396_64bb90
  FL[3] = (eax & 0xff);  // @397_64bb90
  FL[2] = ((ecx & 0xff) & (eax & 0xff));  // @398_64bb90
  if (FL[2] == 0) goto L64be7c;  // @399_64bb90
  L64be71:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @401_64bb90
  FL[3] = (eax & 0xff);  // @402_64bb90
  return eax;  // @403_64bb90
  L64be7c:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @405_64bb90
  eax = (eax & 0xffffff00u) | (((edx & 0xff)) & 0xff);  // @406_64bb90
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (ecx & 0xff))) & 0xff);  // @407_64bb90
  FL[3] = (eax & 0xff);  // @408_64bb90
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (edx & 0xff))) & 0xff);  // @409_64bb90
  FL[3] = (ebx & 0xff);  // @410_64bb90
  ebxh = (ebxh & 0xffffff00u) | ((((ebxh & 0xff) & (ecx & 0xff))) & 0xff);  // @411_64bb90
  FL[3] = (ebxh & 0xff);  // @412_64bb90
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @413_64bb90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @414_64bb90
  if (FL[2] != 0) goto L64be9f;  // @415_64bb90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @416_64bb90
  eax = (u32)(EBP - 32);  // @417_64bb90
  PV[0] = (u32)(eax);  // @418_64bb90
  eax = (u32)(EBP - 56);  // @419_64bb90
  PV[1] = (u32)(eax);  // @420_64bb90
  PV[2] = (u32)(esi);  // @421_64bb90
  eax = ext_64a7f0_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @422_64bb90
  ecx = edx = 0;  // @423_64bb90
  L64be9f:;
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @425_64bb90
  if (FL[2] != 0) goto L64beb7;  // @426_64bb90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @427_64bb90
  eax = (u32)(EBP - 44);  // @428_64bb90
  PV[3] = (u32)(eax);  // @429_64bb90
  eax = (u32)(EBP - 32);  // @430_64bb90
  PV[4] = (u32)(eax);  // @431_64bb90
  eax = (u32)(esi + 12);  // @432_64bb90
  PV[5] = (u32)(eax);  // @433_64bb90
  eax = ext_64a7f0_thiscall4(ecx, PV[5], PV[4], PV[3]);  // @434_64bb90
  ecx = edx = 0;  // @435_64bb90
  L64beb7:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @437_64bb90
  if (FL[0] != FL[1]) goto L64bed1;  // @438_64bb90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @439_64bb90
  eax = (u32)(EBP - 68);  // @440_64bb90
  PV[6] = (u32)(eax);  // @441_64bb90
  eax = (u32)(EBP - 44);  // @442_64bb90
  PV[7] = (u32)(eax);  // @443_64bb90
  eax = (u32)(esi + 24);  // @444_64bb90
  PV[8] = (u32)(eax);  // @445_64bb90
  eax = ext_64a7f0_thiscall4(ecx, PV[8], PV[7], PV[6]);  // @446_64bb90
  ecx = edx = 0;  // @447_64bb90
  L64bed1:;
  FL[2] = ((ebxh & 0xff) & (ebxh & 0xff));  // @449_64bb90
  if (FL[2] != 0) goto L64bee9;  // @450_64bb90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @451_64bb90
  eax = (u32)(EBP - 56);  // @452_64bb90
  PV[9] = (u32)(eax);  // @453_64bb90
  eax = (u32)(EBP - 68);  // @454_64bb90
  PV[10] = (u32)(eax);  // @455_64bb90
  eax = (u32)(esi + 36);  // @456_64bb90
  PV[11] = (u32)(eax);  // @457_64bb90
  eax = ext_64a7f0_thiscall4(ecx, PV[11], PV[10], PV[9]);  // @458_64bb90
  ecx = edx = 0;  // @459_64bb90
  L64bee9:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; })) & 0xff);  // @461_64bb90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @462_64bb90
  FL[2] = ((edx & 0xff) & (u32)(1));  // @463_64bb90
  if (FL[2] == 0) goto L64bf02;  // @464_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @465_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @466_64bb90
  X0[2] = 0;  // @467_64bb90
  X0[3] = 0;  // @468_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @469_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 4), &X0[1], 4);  // @470_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @471_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @472_64bb90
  L64bf02:;
  FL[2] = ((ebx & 0xff) & (u32)(1));  // @474_64bb90
  if (FL[2] == 0) goto L64bf16;  // @475_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @476_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @477_64bb90
  X0[2] = 0;  // @478_64bb90
  X0[3] = 0;  // @479_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X0[0], 4);  // @480_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 4), &X0[1], 4);  // @481_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @482_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @483_64bb90
  L64bf16:;
  edxh = (edxh & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 2), sizeof v); (u32)v; })) & 0xff);  // @485_64bb90
  FL[2] = ((edxh & 0xff) & (u32)(1));  // @486_64bb90
  if (FL[2] == 0) goto L64bf2d;  // @487_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @488_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @489_64bb90
  X0[2] = 0;  // @490_64bb90
  X0[3] = 0;  // @491_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 0), &X0[0], 4);  // @492_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 4), &X0[1], 4);  // @493_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @494_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @495_64bb90
  L64bf2d:;
  FL[2] = ((ebxh & 0xff) & (u32)(1));  // @497_64bb90
  if (FL[2] == 0) goto L64bf41;  // @498_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @499_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @500_64bb90
  X0[2] = 0;  // @501_64bb90
  X0[3] = 0;  // @502_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @503_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 4), &X0[1], 4);  // @504_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @505_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @506_64bb90
  L64bf41:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @508_64bb90
  FL[2] = ((edx & 0xff) & (u32)(2));  // @509_64bb90
  if (FL[2] == 0) goto L64bf57;  // @510_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @511_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @512_64bb90
  X0[2] = 0;  // @513_64bb90
  X0[3] = 0;  // @514_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @515_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 4), &X0[1], 4);  // @516_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @517_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @518_64bb90
  L64bf57:;
  FL[2] = ((ebx & 0xff) & (u32)(2));  // @520_64bb90
  if (FL[2] == 0) goto L64bf6b;  // @521_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @522_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @523_64bb90
  X0[2] = 0;  // @524_64bb90
  X0[3] = 0;  // @525_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X0[0], 4);  // @526_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 4), &X0[1], 4);  // @527_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @528_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @529_64bb90
  L64bf6b:;
  FL[2] = ((edxh & 0xff) & (u32)(2));  // @531_64bb90
  if (FL[2] == 0) goto L64bf7f;  // @532_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @533_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @534_64bb90
  X0[2] = 0;  // @535_64bb90
  X0[3] = 0;  // @536_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 0), &X0[0], 4);  // @537_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 4), &X0[1], 4);  // @538_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @539_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @540_64bb90
  L64bf7f:;
  FL[2] = ((ebxh & 0xff) & (u32)(2));  // @542_64bb90
  if (FL[2] == 0) goto L64bf93;  // @543_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @544_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @545_64bb90
  X0[2] = 0;  // @546_64bb90
  X0[3] = 0;  // @547_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @548_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 4), &X0[1], 4);  // @549_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @550_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @551_64bb90
  L64bf93:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @553_64bb90
  FL[2] = ((edx & 0xff) & (u32)(4));  // @554_64bb90
  if (FL[2] == 0) goto L64bfa9;  // @555_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @556_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @557_64bb90
  X0[2] = 0;  // @558_64bb90
  X0[3] = 0;  // @559_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @560_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 4), &X0[1], 4);  // @561_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @562_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @563_64bb90
  L64bfa9:;
  FL[2] = ((ebx & 0xff) & (u32)(4));  // @565_64bb90
  if (FL[2] == 0) goto L64bfbd;  // @566_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @567_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @568_64bb90
  X0[2] = 0;  // @569_64bb90
  X0[3] = 0;  // @570_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X0[0], 4);  // @571_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 4), &X0[1], 4);  // @572_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @573_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @574_64bb90
  L64bfbd:;
  FL[2] = ((edxh & 0xff) & (u32)(4));  // @576_64bb90
  if (FL[2] == 0) goto L64bfd1;  // @577_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @578_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @579_64bb90
  X0[2] = 0;  // @580_64bb90
  X0[3] = 0;  // @581_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 0), &X0[0], 4);  // @582_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 4), &X0[1], 4);  // @583_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @584_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @585_64bb90
  L64bfd1:;
  FL[2] = ((ebxh & 0xff) & (u32)(4));  // @587_64bb90
  if (FL[2] == 0) goto L64bfe5;  // @588_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @589_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @590_64bb90
  X0[2] = 0;  // @591_64bb90
  X0[3] = 0;  // @592_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @593_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 4), &X0[1], 4);  // @594_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @595_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @596_64bb90
  L64bfe5:;
  FL[2] = ((edx & 0xff) & (u32)(8));  // @598_64bb90
  if (FL[2] == 0) goto L64bff8;  // @599_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @600_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 4), 4); v; });  // @601_64bb90
  X0[2] = 0;  // @602_64bb90
  X0[3] = 0;  // @603_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @604_64bb90
  __builtin_memcpy((void *)((u32)(esi) + 4), &X0[1], 4);  // @605_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @606_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @607_64bb90
  L64bff8:;
  FL[2] = ((ebx & 0xff) & (u32)(8));  // @609_64bb90
  if (FL[2] == 0) goto L64c00c;  // @610_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @611_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 4), 4); v; });  // @612_64bb90
  X0[2] = 0;  // @613_64bb90
  X0[3] = 0;  // @614_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 0), &X0[0], 4);  // @615_64bb90
  __builtin_memcpy((void *)((u32)(esi + 12) + 4), &X0[1], 4);  // @616_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @617_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @618_64bb90
  L64c00c:;
  FL[2] = ((edxh & 0xff) & (u32)(8));  // @620_64bb90
  if (FL[2] == 0) goto L64c020;  // @621_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @622_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 4), 4); v; });  // @623_64bb90
  X0[2] = 0;  // @624_64bb90
  X0[3] = 0;  // @625_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 0), &X0[0], 4);  // @626_64bb90
  __builtin_memcpy((void *)((u32)(esi + 24) + 4), &X0[1], 4);  // @627_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @628_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @629_64bb90
  L64c020:;
  FL[2] = ((ebxh & 0xff) & (u32)(8));  // @631_64bb90
  if (FL[2] == 0) goto L64c034;  // @632_64bb90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @633_64bb90
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 4), 4); v; });  // @634_64bb90
  X0[2] = 0;  // @635_64bb90
  X0[3] = 0;  // @636_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 0), &X0[0], 4);  // @637_64bb90
  __builtin_memcpy((void *)((u32)(esi + 36) + 4), &X0[1], 4);  // @638_64bb90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @639_64bb90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @640_64bb90
  L64c034:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @642_64bb90
  return eax;  // @643_64bb90
}
PCREG(64bb90, lifted_64bb90);

