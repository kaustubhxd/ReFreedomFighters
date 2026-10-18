// batch234015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4947c0_stdcall1(u32) __asm__("ext_4947c0");
extern "C" u32 THISCALL ext_562b50_thiscall2(u32, u32) __asm__("ext_562b50");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_56d280(u32 ecx_in) {
  u32 PT = 0;
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_56d280
  edx = 0;  // @1_56d280
  FL[3] = edx;  // @2_56d280
  ecx = 0;  // @3_56d280
  FL[3] = ecx;  // @4_56d280
  edi = 0;  // @5_56d280
  FL[3] = edi;  // @6_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 412), sizeof v); (u32)v; }); FL[1] = (ecx & 0xff);  // @7_56d280
  if (FL[0] == FL[1]) goto L56d2b8;  // @8_56d280
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 416), sizeof v); (u32)v; })) & 0xff);  // @9_56d280
  edi = (u32)(edx + 1);  // @10_56d280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @11_56d280
  edx = (edx & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @12_56d280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @13_56d280
  ecx = (ecx & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @14_56d280
  L56d2b8:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 413), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_56d280
  if (FL[0] == FL[1]) goto L56d2cf;  // @17_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 417), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_56d280
  if (FL[0] == FL[1]) goto L56d2cd;  // @19_56d280
  edx = (edx + 1);  // @20_56d280
  FL[3] = edx;  // @21_56d280
  goto L56d2ce;  // @22_56d280
  L56d2cd:;
  ecx = (ecx + 1);  // @24_56d280
  FL[3] = ecx;  // @25_56d280
  L56d2ce:;
  edi = (edi + 1);  // @27_56d280
  FL[3] = edi;  // @28_56d280
  L56d2cf:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 414), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @30_56d280
  if (FL[0] == FL[1]) goto L56d2e6;  // @31_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 418), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @32_56d280
  if (FL[0] == FL[1]) goto L56d2e4;  // @33_56d280
  edx = (edx + 1);  // @34_56d280
  FL[3] = edx;  // @35_56d280
  goto L56d2e5;  // @36_56d280
  L56d2e4:;
  ecx = (ecx + 1);  // @38_56d280
  FL[3] = ecx;  // @39_56d280
  L56d2e5:;
  edi = (edi + 1);  // @41_56d280
  FL[3] = edi;  // @42_56d280
  L56d2e6:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 415), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_56d280
  if (FL[0] == FL[1]) goto L56d2fd;  // @45_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 419), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @46_56d280
  if (FL[0] == FL[1]) goto L56d2fb;  // @47_56d280
  edx = (edx + 1);  // @48_56d280
  FL[3] = edx;  // @49_56d280
  goto L56d2fc;  // @50_56d280
  L56d2fb:;
  ecx = (ecx + 1);  // @52_56d280
  FL[3] = ecx;  // @53_56d280
  L56d2fc:;
  edi = (edi + 1);  // @55_56d280
  FL[3] = edi;  // @56_56d280
  L56d2fd:;
  FL[2] = (edx & edx);  // @58_56d280
  if (FL[2] == 0) goto L56d73f;  // @59_56d280
  FL[2] = (ecx & ecx);  // @60_56d280
  if (FL[2] == 0) goto L56d73f;  // @61_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @65_56d280
  ecx = edx = 0;  // @66_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @67_56d280
  ecx = eax;  // @68_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(6859220), (u32)(1), (u32)(0));  // @69_56d280
  ecx = edx = 0;  // @70_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @72_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @74_56d280
  ecx = edx = 0;  // @75_56d280
  PV[0] = (u32)(edi);  // @76_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @77_56d280
  ecx = eax;  // @78_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6880492), PV[0], (u32)(2));  // @79_56d280
  ecx = edx = 0;  // @80_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @82_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @84_56d280
  ecx = edx = 0;  // @85_56d280
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 420), sizeof v); (u32)v; });  // @86_56d280
  PV[1] = (u32)(ecx);  // @87_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_56d280
  ecx = eax;  // @89_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(6979624), PV[1], (u32)(0));  // @90_56d280
  ecx = edx = 0;  // @91_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_56d280
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 7005), &v, sizeof v); }  // @93_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 437), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @96_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_56d280
  if (FL[0] == FL[1]) goto L56d3f2;  // @98_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @99_56d280
  ecx = edx = 0;  // @100_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @101_56d280
  ecx = eax;  // @102_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6979836), (u32)(1), (u32)(2));  // @103_56d280
  ecx = edx = 0;  // @104_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @105_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @106_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @108_56d280
  ecx = edx = 0;  // @109_56d280
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 438), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @110_56d280
  X0[0] = F2U((float)(s32)X0[0]);  // @111_56d280
  X0[1] = F2U((float)(s32)X0[1]);  // @112_56d280
  X0[2] = F2U((float)(s32)X0[2]);  // @113_56d280
  X0[3] = F2U((float)(s32)X0[3]);  // @114_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @115_56d280
  PV[2] = (u32)(ecx);  // @116_56d280
  ecx = eax;  // @117_56d280
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @118_56d280
  PV[3] = X0[0];  // @119_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(6979852), PV[3], (u32)(3));  // @120_56d280
  ecx = edx = 0;  // @121_56d280
  goto L56d433;  // @122_56d280
  L56d3f2:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @124_56d280
  ecx = edx = 0;  // @125_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @126_56d280
  ecx = eax;  // @127_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6979836), (u32)(0), (u32)(2));  // @128_56d280
  ecx = edx = 0;  // @129_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @130_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @131_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @133_56d280
  ecx = edx = 0;  // @134_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 442), sizeof v); (u32)v; });  // @135_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @136_56d280
  ecx = (u32)(ecx + ecx*2);  // @137_56d280
  PV[4] = (u32)(ecx);  // @138_56d280
  ecx = eax;  // @139_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6979852), PV[4], (u32)(2));  // @140_56d280
  ecx = edx = 0;  // @141_56d280
  L56d433:;
  eax = 0;  // @143_56d280
  FL[3] = eax;  // @144_56d280
  ecx = 0;  // @145_56d280
  FL[3] = ecx;  // @146_56d280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @147_56d280
  ebx = 0;  // @148_56d280
  FL[3] = ebx;  // @149_56d280
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @150_56d280
  edi = (u32)(7260012);  // @151_56d280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @152_56d280
  L56d451:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx + 412), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @154_56d280
  if (FL[0] == FL[1]) goto L56d56b;  // @155_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx + 416), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @156_56d280
  if (FL[0] == FL[1]) goto L56d47c;  // @157_56d280
  eax = (eax + 1);  // @158_56d280
  FL[3] = eax;  // @159_56d280
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @160_56d280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @161_56d280
  goto L56d490;  // @162_56d280
  L56d47c:;
  ecx = (ecx + 1);  // @164_56d280
  FL[3] = ecx;  // @165_56d280
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @166_56d280
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @167_56d280
  eax = (u32)(ecx + 3);  // @168_56d280
  L56d490:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @170_56d280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @171_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @173_56d280
  ecx = edx = 0;  // @174_56d280
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @175_56d280
  edx = (u32)(EBP - 132);  // @176_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @177_56d280
  PV[6] = (u32)(edx);  // @178_56d280
  PV[7] = (u32)(eax);  // @179_56d280
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[7], PV[6], (u32)(6979868), PV[5]);  // @180_56d280
  ecx = edx = 0;  // @181_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @182_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @183_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @185_56d280
  ecx = edx = 0;  // @186_56d280
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx + 412), sizeof v); (u32)v; });  // @187_56d280
  PV[8] = (u32)(ecx);  // @188_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @189_56d280
  ecx = eax;  // @190_56d280
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @191_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[9], PV[8], (u32)(0));  // @192_56d280
  ecx = edx = 0;  // @193_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @195_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @196_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @197_56d280
  ecx = edx = 0;  // @198_56d280
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @199_56d280
  ecx = eax;  // @200_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @201_56d280
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @202_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[11], PV[10], (u32)(2));  // @203_56d280
  ecx = edx = 0;  // @204_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @206_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @208_56d280
  ecx = edx = 0;  // @209_56d280
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @210_56d280
  ecx = eax;  // @211_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @212_56d280
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @213_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[13], PV[12], (u32)(2));  // @214_56d280
  ecx = edx = 0;  // @215_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @216_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @217_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @219_56d280
  ecx = edx = 0;  // @220_56d280
  ecx = (u32)(EBP - 132);  // @221_56d280
  PV[14] = (u32)(ecx);  // @222_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @223_56d280
  ecx = eax;  // @224_56d280
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @225_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[15], PV[14], (u32)(12));  // @226_56d280
  ecx = edx = 0;  // @227_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @228_56d280
  edx = (edx + 1);  // @229_56d280
  FL[3] = edx;  // @230_56d280
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @231_56d280
  goto L56d5f7;  // @232_56d280
  L56d56b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @234_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @235_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @236_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @237_56d280
  ecx = edx = 0;  // @238_56d280
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @239_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @240_56d280
  ecx = eax;  // @241_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[16], (u32)(0), (u32)(0));  // @242_56d280
  ecx = edx = 0;  // @243_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @244_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @245_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @247_56d280
  ecx = edx = 0;  // @248_56d280
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @249_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @250_56d280
  ecx = eax;  // @251_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[17], (u32)(3), (u32)(2));  // @252_56d280
  ecx = edx = 0;  // @253_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @254_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @255_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @256_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @257_56d280
  ecx = edx = 0;  // @258_56d280
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @259_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @260_56d280
  ecx = eax;  // @261_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[18], (u32)(3), (u32)(2));  // @262_56d280
  ecx = edx = 0;  // @263_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @264_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @265_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @266_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @267_56d280
  ecx = edx = 0;  // @268_56d280
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @269_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @270_56d280
  ecx = eax;  // @271_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[19], (u32)(6979884), (u32)(12));  // @272_56d280
  ecx = edx = 0;  // @273_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @274_56d280
  L56d5f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @276_56d280
  edi = (edi + (u32)(20));  // @277_56d280
  FL[3] = edi;  // @278_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @279_56d280
  ebx = (ebx + 1);  // @280_56d280
  FL[3] = ebx;  // @281_56d280
  FL[0] = edi; FL[1] = (u32)(7260092);  // @282_56d280
  if ((s32)FL[0] < (s32)FL[1]) goto L56d451;  // @283_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @284_56d280
  eax = (u32)(8);  // @285_56d280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @286_56d280
  FL[0] = edx; FL[1] = (u32)(4);  // @287_56d280
  if (FL[0] != FL[1]) goto L56d642;  // @288_56d280
  FL[0] = ecx; FL[1] = (u32)(1);  // @289_56d280
  if (FL[0] == FL[1]) goto L56d637;  // @290_56d280
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @291_56d280
  if (FL[0] != FL[1]) goto L56d642;  // @292_56d280
  L56d637:;
  eax = (u32)(9);  // @294_56d280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 140), &v, sizeof v); }  // @295_56d280
  L56d642:;
  edi = 0;  // @297_56d280
  FL[3] = edi;  // @298_56d280
  ebx = (u32)(7260024);  // @299_56d280
  L56d650:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi + 412), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @301_56d280
  if (FL[0] == FL[1]) goto L56d699;  // @302_56d280
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi + 416), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @303_56d280
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @304_56d280
  if (FL[0] == FL[1]) goto L56d669;  // @305_56d280
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @306_56d280
  goto L56d66f;  // @307_56d280
  L56d669:;
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @309_56d280
  L56d66f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @311_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @312_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @313_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @314_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @315_56d280
  ecx = edx = 0;  // @316_56d280
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 144), sizeof v); (u32)v; });  // @317_56d280
  ecx = eax;  // @318_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @319_56d280
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @320_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[21], PV[20], (u32)(2));  // @321_56d280
  ecx = edx = 0;  // @322_56d280
  L56d699:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 136), sizeof v); (u32)v; });  // @324_56d280
  ebx = (ebx + (u32)(20));  // @325_56d280
  FL[3] = ebx;  // @326_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; });  // @327_56d280
  edi = (edi + 1);  // @328_56d280
  FL[3] = edi;  // @329_56d280
  FL[0] = ebx; FL[1] = (u32)(7260104);  // @330_56d280
  if ((s32)FL[0] < (s32)FL[1]) goto L56d650;  // @331_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @332_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @333_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @334_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @335_56d280
  ecx = edx = 0;  // @336_56d280
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 446), sizeof v); (u32)v; });  // @337_56d280
  ecx = eax;  // @338_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @339_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6979900), PV[22], (u32)(2));  // @340_56d280
  ecx = edx = 0;  // @341_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @342_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @343_56d280
  eax = ext_4947c0_stdcall1((u32)(3));  // @344_56d280
  ecx = edx = 0;  // @345_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 446), sizeof v); (u32)v; });  // @346_56d280
  ecx = esi;  // @347_56d280
  eax = (eax - (u32)(1));  // @348_56d280
  FL[3] = eax;  // @349_56d280
  if (FL[3] == 0) goto L56d70c;  // @350_56d280
  eax = (eax - (u32)(1));  // @351_56d280
  FL[3] = eax;  // @352_56d280
  if (FL[3] == 0) goto L56d705;  // @353_56d280
  PT = 6979924; goto L56d711;  // @354_56d280
  L56d705:;
  PT = 0x6a8144; goto L56d711;  // @356_56d280
  L56d70c:;
  PT = 0x6a814c;
  L56d711:;
  eax = ext_562b50_thiscall2(ecx, PT);  // @359_56d280
  ecx = edx = 0;  // @360_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @361_56d280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @362_56d280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @363_56d280
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @364_56d280
  ecx = edx = 0;  // @365_56d280
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 420), sizeof v); (u32)v; });  // @366_56d280
  PV[23] = (u32)(ecx);  // @367_56d280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @368_56d280
  ecx = eax;  // @369_56d280
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(6979624), PV[23], (u32)(0));  // @370_56d280
  ecx = edx = 0;  // @371_56d280
  L56d73f:;
  ext_633654(G(u32, 0x6f5630));  // @373_56d280
  return eax;  // @374_56d280
}
PCREG(56d280, lifted_56d280);

