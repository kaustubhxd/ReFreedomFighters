// batch262006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4dafb0_thiscall1(u32) __asm__("ext_4dafb0");
extern "C" u32 THISCALL ext_4db2f0_thiscall2(u32, u32) __asm__("ext_4db2f0");
extern "C" u32 THISCALL ext_4db550_thiscall1(u32) __asm__("ext_4db550");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c6cf0(u32 ecx_in) {
  SEH_ENTER(0x66902d);  // @h_4c6cf0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @0_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @2_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @4_4c6cf0
  ecx = edx = 0;  // @5_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4c6cf0
  PV[0] = (u32)(eax);  // @7_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @8_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @10_4c6cf0
  ecx = edx = 0;  // @11_4c6cf0
  ecx = eax;  // @12_4c6cf0
  FL[2] = (ecx & ecx);  // @13_4c6cf0
  if (FL[2] == 0) goto L4c72e5;  // @14_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4c6cf0
  edx = (u32)(EBP - 416);  // @16_4c6cf0
  PV[1] = (u32)(ecx);  // @17_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 652), sizeof v); (u32)v; });  // @18_4c6cf0
  PV[2] = (u32)(edx);  // @19_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[2], (u32)(1), (u32)(7), (u32)(0));  // @20_4c6cf0
  ecx = edx = 0;  // @21_4c6cf0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @22_4c6cf0
  if (FL[2] == 0) goto L4c729a;  // @23_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_4c6cf0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @25_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @26_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @28_4c6cf0
  ecx = edx = 0;  // @29_4c6cf0
  ecx = (u32)(EBP - 400);  // @30_4c6cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 440), &v, sizeof v); }  // @31_4c6cf0
  PV[4] = (u32)(ecx);  // @32_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_4c6cf0
  ecx = eax;  // @34_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[4], (u32)(0));  // @35_4c6cf0
  ecx = edx = 0;  // @36_4c6cf0
  ecx = eax;  // @37_4c6cf0
  reg.state = (s32)((u32)(0));  // @38_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @39_4c6cf0
    // @40_4c6cf0
  PV[5] = (u32)(eax);  // @41_4c6cf0
  ecx = (u32)(EBP - 272);  // @42_4c6cf0
  eax = ext_4cbe80_thiscall2(ecx, PV[5]);  // @43_4c6cf0
  ecx = edx = 0;  // @44_4c6cf0
  ecx = (u32)(EBP - 400);  // @45_4c6cf0
  reg.state = (s32)((u32)(2));  // @46_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_4c6cf0
  ecx = edx = 0;  // @48_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @50_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @52_4c6cf0
  ecx = edx = 0;  // @53_4c6cf0
  ecx = eax;  // @54_4c6cf0
  eax = (u32)(715827883);  // @55_4c6cf0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @56_4c6cf0
  MOF = (u32)(edx + (((s32)eax < 0) ? 1 : 0));  // @57_4c6cf0
  ecx = (u32)(EBP - 272);  // @58_4c6cf0
  ebx = edx;  // @59_4c6cf0
  ebx = (ebx >> (u32)(31));  // @60_4c6cf0
  FL[3] = ebx;  // @61_4c6cf0
  ebx = (ebx + edx);  // @62_4c6cf0
  FL[3] = ebx;  // @63_4c6cf0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @64_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_4c6cf0
    // @66_4c6cf0
  PV[6] = (u32)(eax);  // @67_4c6cf0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[6], (u32)(47));  // @68_4c6cf0
  ecx = edx = 0;  // @69_4c6cf0
  esi = eax;  // @70_4c6cf0
  FL[2] = (esi & esi);  // @71_4c6cf0
  if (FL[2] == 0) goto L4c6e21;  // @72_4c6cf0
  esi = (esi + 1);  // @73_4c6cf0
  FL[3] = esi;  // @74_4c6cf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @75_4c6cf0
  goto L4c6e34;  // @76_4c6cf0
  L4c6e21:;
  ecx = (u32)(EBP - 272);  // @78_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @79_4c6cf0
    // @80_4c6cf0
  esi = eax;  // @81_4c6cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @82_4c6cf0
  L4c6e34:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @86_4c6cf0
  ecx = edx = 0;  // @87_4c6cf0
  PV[7] = (u32)(esi);  // @88_4c6cf0
  ecx = (u32)(ebx - 3);  // @89_4c6cf0
  PV[8] = (u32)(ecx);  // @90_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_4c6cf0
  PV[9] = (u32)(eax);  // @92_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[9], (u32)(0), PV[8], PV[7]);  // @93_4c6cf0
  ecx = edx = 0;  // @94_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @97_4c6cf0
  ecx = edx = 0;  // @98_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_4c6cf0
  esi = eax;  // @100_4c6cf0
  edx = ebx;  // @101_4c6cf0
  edx = (edx >> (u32)(1));  // @102_4c6cf0
  FL[3] = edx;  // @103_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @104_4c6cf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_4c6cf0
  PV[10] = (u32)(edx);  // @106_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 216)))(ecx);  // @108_4c6cf0
  ecx = edx = 0;  // @109_4c6cf0
  ecx = eax;  // @110_4c6cf0
  eax = (u32)(1717986919);  // @111_4c6cf0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @112_4c6cf0
  MOF = (u32)(edx + (((s32)eax < 0) ? 1 : 0));  // @113_4c6cf0
  edx = (u32)((s32)edx >> (u32)(1));  // @114_4c6cf0
  FL[3] = edx;  // @115_4c6cf0
  eax = edx;  // @116_4c6cf0
  eax = (eax >> (u32)(31));  // @117_4c6cf0
  FL[3] = eax;  // @118_4c6cf0
  eax = (eax + edx);  // @119_4c6cf0
  FL[3] = eax;  // @120_4c6cf0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @121_4c6cf0
  eax = (eax - edx);  // @122_4c6cf0
  FL[3] = eax;  // @123_4c6cf0
  eax = (u32)((s32)eax >> (u32)(1));  // @124_4c6cf0
  FL[3] = eax;  // @125_4c6cf0
  PV[11] = (u32)(eax);  // @126_4c6cf0
  PV[12] = (u32)(esi);  // @127_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 388)))(PV[12], PV[11], PV[10], (u32)(6900856));  // @128_4c6cf0
  ecx = edx = 0;  // @129_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @130_4c6cf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @131_4c6cf0
  X0[1] = 0;  // @132_4c6cf0
  X0[2] = 0;  // @133_4c6cf0
  X0[3] = 0;  // @134_4c6cf0
  FC0 = U2F(X0[0]); FC1 = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @135_4c6cf0
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L4c728d;  // @136_4c6cf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; });  // @137_4c6cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @138_4c6cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @139_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @140_4c6cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @141_4c6cf0
  if (FL[0] == FL[1]) goto L4c6f0a;  // @142_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_4c6cf0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; });  // @144_4c6cf0
  edx = (u32)(EBP - 424);  // @145_4c6cf0
  PV[14] = (u32)(edx);  // @146_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @147_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23861), sizeof v); (u32)v; });  // @148_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[14], PV[13]);  // @150_4c6cf0
  ecx = edx = 0;  // @151_4c6cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @152_4c6cf0
  goto L4c6f43;  // @153_4c6cf0
  L4c6f0a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @155_4c6cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @156_4c6cf0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @157_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @158_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @159_4c6cf0
  ecx = edx = 0;  // @160_4c6cf0
  ecx = (u32)(ebx - 6);  // @161_4c6cf0
  PV[15] = (u32)(ecx);  // @162_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @163_4c6cf0
  PV[16] = (u32)(eax);  // @164_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[16], (u32)(0), PV[15], (u32)(6900860));  // @165_4c6cf0
  ecx = edx = 0;  // @166_4c6cf0
  L4c6f43:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @168_4c6cf0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(1074003968));  // @169_4c6cf0
  if (FL[2] == 0) goto L4c714c;  // @170_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @171_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6900440), (u32)(820));  // @173_4c6cf0
  ecx = edx = 0;  // @174_4c6cf0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @175_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @176_4c6cf0
  PV[18] = (u32)(eax);  // @177_4c6cf0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[18], (u32)(6900876), PV[17]);  // @178_4c6cf0
  ecx = edx = 0;  // @179_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @180_4c6cf0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(1073741824));  // @181_4c6cf0
  if (FL[2] == 0) goto L4c6f8f;  // @182_4c6cf0
  ecx = eax;  // @183_4c6cf0
  eax = ext_4dafb0_thiscall1(ecx);  // @184_4c6cf0
  ecx = edx = 0;  // @185_4c6cf0
  L4c6f8f:;
  ecx = eax;  // @187_4c6cf0
  eax = ext_4db550_thiscall1(ecx);  // @188_4c6cf0
  ecx = edx = 0;  // @189_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @190_4c6cf0
  esi = eax;  // @191_4c6cf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @192_4c6cf0
  FL[2] = (esi & esi);  // @193_4c6cf0
  if (FL[2] == 0) goto L4c6fb3;  // @194_4c6cf0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; })) & 0xff);  // @195_4c6cf0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @196_4c6cf0
  if (FL[2] == 0) goto L4c6fb3;  // @197_4c6cf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_4c6cf0
  goto L4c6fbf;  // @199_4c6cf0
  L4c6fb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @201_4c6cf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @202_4c6cf0
  L4c6fbf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @205_4c6cf0
  ecx = edx = 0;  // @206_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @207_4c6cf0
  ebx = eax;  // @208_4c6cf0
  eax = (u32)(EBP - 144);  // @209_4c6cf0
  PV[19] = (u32)(eax);  // @210_4c6cf0
  eax = ext_4da2f0_thiscall3(ecx, PV[19], (u32)(1));  // @211_4c6cf0
  ecx = edx = 0;  // @212_4c6cf0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @213_4c6cf0
  ecx = eax;  // @214_4c6cf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @215_4c6cf0
  reg.state = (s32)((u32)(3));  // @216_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @217_4c6cf0
    // @218_4c6cf0
  PV[20] = (u32)(eax);  // @219_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 436), sizeof v); (u32)v; });  // @220_4c6cf0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }));  // @221_4c6cf0
  FL[3] = eax;  // @222_4c6cf0
  PV[21] = (u32)(esi);  // @223_4c6cf0
  eax = (eax - (u32)(4));  // @224_4c6cf0
  FL[3] = eax;  // @225_4c6cf0
  PV[22] = (u32)(eax);  // @226_4c6cf0
  PV[23] = (u32)(ebx);  // @227_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 388)))(PV[23], (u32)(0), PV[22], (u32)(6900892), PV[21], PV[20]);  // @228_4c6cf0
  ecx = edx = 0;  // @229_4c6cf0
  reg.state = (s32)((u32)(2));  // @230_4c6cf0
  ecx = (u32)(EBP - 144);  // @231_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @232_4c6cf0
  ecx = edx = 0;  // @233_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @234_4c6cf0
  ebx = 0;  // @235_4c6cf0
  FL[3] = ebx;  // @236_4c6cf0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; })) & 0xff);  // @237_4c6cf0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @238_4c6cf0
  if (FL[2] == 0) goto L4c709d;  // @239_4c6cf0
  ecx = (ecx & 0xff);  // @240_4c6cf0
  FL[0] = ebx; FL[1] = ecx;  // @241_4c6cf0
  if (FL[0] >= FL[1]) goto L4c7038;  // @242_4c6cf0
  L4c7033:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @244_4c6cf0
  goto L4c703a;  // @245_4c6cf0
  L4c7038:;
  esi = 0;  // @247_4c6cf0
  FL[3] = esi;  // @248_4c6cf0
  L4c703a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @250_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @251_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6900440), (u32)(829));  // @252_4c6cf0
  ecx = edx = 0;  // @253_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @254_4c6cf0
  edi = eax;  // @255_4c6cf0
  eax = (u32)(EBP - 144);  // @256_4c6cf0
  ecx = esi;  // @257_4c6cf0
  PV[24] = (u32)(eax);  // @258_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[24], (u32)(1));  // @259_4c6cf0
  ecx = edx = 0;  // @260_4c6cf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @261_4c6cf0
  ecx = eax;  // @262_4c6cf0
  reg.state = (s32)((u32)(4));  // @263_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @264_4c6cf0
    // @265_4c6cf0
  PV[25] = (u32)(eax);  // @266_4c6cf0
  PV[26] = (u32)(ebx);  // @267_4c6cf0
  PV[27] = (u32)(edi);  // @268_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[27], (u32)(6900908), PV[26], PV[25]);  // @269_4c6cf0
  ecx = edx = 0;  // @270_4c6cf0
  reg.state = (s32)((u32)(2));  // @271_4c6cf0
  ecx = (u32)(EBP - 144);  // @272_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @273_4c6cf0
  ecx = edx = 0;  // @274_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @275_4c6cf0
  ebx = (ebx + 1);  // @276_4c6cf0
  FL[3] = ebx;  // @277_4c6cf0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @278_4c6cf0
  FL[0] = ebx; FL[1] = ecx;  // @279_4c6cf0
  if (FL[0] < FL[1]) goto L4c7033;  // @280_4c6cf0
  L4c709d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @282_4c6cf0
  FL[2] = (esi & esi);  // @283_4c6cf0
  if (FL[2] == 0) goto L4c7121;  // @284_4c6cf0
  ebx = 0;  // @285_4c6cf0
  FL[3] = ebx;  // @286_4c6cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; }); FL[1] = ebx;  // @287_4c6cf0
  if (FL[0] <= FL[1]) goto L4c7121;  // @288_4c6cf0
  L4c70c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @290_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @291_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6900440), (u32)(835));  // @292_4c6cf0
  ecx = edx = 0;  // @293_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx*4), sizeof v); (u32)v; });  // @294_4c6cf0
  edi = eax;  // @295_4c6cf0
  eax = (u32)(EBP - 144);  // @296_4c6cf0
  PV[28] = (u32)(eax);  // @297_4c6cf0
  eax = ext_4da2f0_thiscall3(ecx, PV[28], (u32)(1));  // @298_4c6cf0
  ecx = edx = 0;  // @299_4c6cf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @300_4c6cf0
  ecx = eax;  // @301_4c6cf0
  reg.state = (s32)((u32)(5));  // @302_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @303_4c6cf0
    // @304_4c6cf0
  PV[29] = (u32)(eax);  // @305_4c6cf0
  PV[30] = (u32)(ebx);  // @306_4c6cf0
  PV[31] = (u32)(edi);  // @307_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[31], (u32)(6900916), PV[30], PV[29]);  // @308_4c6cf0
  ecx = edx = 0;  // @309_4c6cf0
  reg.state = (s32)((u32)(2));  // @310_4c6cf0
  ecx = (u32)(EBP - 144);  // @311_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @312_4c6cf0
  ecx = edx = 0;  // @313_4c6cf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @314_4c6cf0
  ebx = (ebx + 1);  // @315_4c6cf0
  FL[3] = ebx;  // @316_4c6cf0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @317_4c6cf0
  if (FL[0] < FL[1]) goto L4c70c0;  // @318_4c6cf0
  L4c7121:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @320_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @321_4c6cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6900440), (u32)(838));  // @322_4c6cf0
  ecx = edx = 0;  // @323_4c6cf0
  PV[32] = (u32)(eax);  // @324_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @325_4c6cf0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[32], (u32)(6900928));  // @326_4c6cf0
  ecx = edx = 0;  // @327_4c6cf0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 436), sizeof v); (u32)v; });  // @328_4c6cf0
  goto L4c71b0;  // @329_4c6cf0
  L4c714c:;
  eax = ext_4db2f0_thiscall2(ecx, (u32)(0));  // @331_4c6cf0
  ecx = edx = 0;  // @332_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @333_4c6cf0
  esi = eax;  // @334_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @335_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 400)))(ecx);  // @336_4c6cf0
  ecx = edx = 0;  // @337_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @338_4c6cf0
  edi = eax;  // @339_4c6cf0
  eax = (u32)(EBP - 144);  // @340_4c6cf0
  PV[33] = (u32)(eax);  // @341_4c6cf0
  eax = ext_4da2f0_thiscall3(ecx, PV[33], (u32)(1));  // @342_4c6cf0
  ecx = edx = 0;  // @343_4c6cf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @344_4c6cf0
  ecx = eax;  // @345_4c6cf0
  reg.state = (s32)((u32)(6));  // @346_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @347_4c6cf0
    // @348_4c6cf0
  PV[34] = (u32)(eax);  // @349_4c6cf0
  eax = ebx;  // @350_4c6cf0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }));  // @351_4c6cf0
  FL[3] = eax;  // @352_4c6cf0
  eax = (eax - (u32)(4));  // @353_4c6cf0
  FL[3] = eax;  // @354_4c6cf0
  PV[35] = (u32)(eax);  // @355_4c6cf0
  PV[36] = (u32)(edi);  // @356_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 388)))(PV[36], (u32)(0), PV[35], (u32)(6900936), PV[34]);  // @357_4c6cf0
  ecx = edx = 0;  // @358_4c6cf0
  reg.state = (s32)((u32)(2));  // @359_4c6cf0
  ecx = (u32)(EBP - 144);  // @360_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @361_4c6cf0
  ecx = edx = 0;  // @362_4c6cf0
  L4c71b0:;
  eax = 0;  // @364_4c6cf0
  FL[3] = eax;  // @365_4c6cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; }); FL[1] = eax;  // @366_4c6cf0
  if (FL[0] <= FL[1]) goto L4c7252;  // @367_4c6cf0
  eax = (u32)(ebx - 5);  // @368_4c6cf0
  ebx = 0;  // @369_4c6cf0
  FL[3] = ebx;  // @370_4c6cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @371_4c6cf0
  L4c71d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @373_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @374_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @375_4c6cf0
  ecx = edx = 0;  // @376_4c6cf0
  edi = eax;  // @377_4c6cf0
  eax = (u32)(EBP - 144);  // @378_4c6cf0
  PV[37] = (u32)(eax);  // @379_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @380_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @381_4c6cf0
  eax = ext_4da2f0_thiscall3(ecx, PV[37], (u32)(1));  // @382_4c6cf0
  ecx = edx = 0;  // @383_4c6cf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @384_4c6cf0
  ecx = eax;  // @385_4c6cf0
  reg.state = (s32)((u32)(7));  // @386_4c6cf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @387_4c6cf0
    // @388_4c6cf0
  PV[38] = (u32)(eax);  // @389_4c6cf0
  PV[39] = (u32)(ebx);  // @390_4c6cf0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @391_4c6cf0
  PV[41] = (u32)(edi);  // @392_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 388)))(PV[41], (u32)(0), PV[40], (u32)(6900948), PV[39], PV[38]);  // @393_4c6cf0
  ecx = edx = 0;  // @394_4c6cf0
  reg.state = (s32)((u32)(2));  // @395_4c6cf0
  ecx = (u32)(EBP - 144);  // @396_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @397_4c6cf0
  ecx = edx = 0;  // @398_4c6cf0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @399_4c6cf0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @400_4c6cf0
  ebx = (ebx + 1);  // @401_4c6cf0
  FL[3] = ebx;  // @402_4c6cf0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @403_4c6cf0
  if (FL[0] < FL[1]) goto L4c71d0;  // @404_4c6cf0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 440), &v, sizeof v); }  // @405_4c6cf0
  FL[0] = ebx; FL[1] = (u32)(16);  // @406_4c6cf0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 436), sizeof v); (u32)v; });  // @407_4c6cf0
  if (FL[0] >= FL[1]) goto L4c728d;  // @408_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; });  // @409_4c6cf0
  L4c7252:;
  ebx = (ebx - eax);  // @411_4c6cf0
  FL[3] = ebx;  // @412_4c6cf0
  esi = (u32)(16);  // @413_4c6cf0
  ebx = (ebx - (u32)(5));  // @414_4c6cf0
  FL[3] = ebx;  // @415_4c6cf0
  esi = (esi - eax);  // @416_4c6cf0
  FL[3] = esi;  // @417_4c6cf0
  L4c7260:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @419_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @420_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @421_4c6cf0
  ecx = edx = 0;  // @422_4c6cf0
  PV[42] = (u32)(ebx);  // @423_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @424_4c6cf0
  PV[43] = (u32)(eax);  // @425_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[43], (u32)(0), PV[42], (u32)(6900956), (u32)(6790764));  // @426_4c6cf0
  ecx = edx = 0;  // @427_4c6cf0
  ebx = (ebx - 1);  // @428_4c6cf0
  FL[3] = ebx;  // @429_4c6cf0
  esi = (esi - (u32)(1));  // @430_4c6cf0
  FL[3] = esi;  // @431_4c6cf0
  if (FL[3] != 0) goto L4c7260;  // @432_4c6cf0
  L4c728d:;
  ecx = (u32)(EBP - 272);  // @434_4c6cf0
  eax = ext_4cbec0_thiscall1(ecx);  // @435_4c6cf0
  ecx = edx = 0;  // @436_4c6cf0
  goto L4c72e5;  // @437_4c6cf0
  L4c729a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @439_4c6cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @440_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @441_4c6cf0
  ecx = edx = 0;  // @442_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @443_4c6cf0
  esi = eax;  // @444_4c6cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @445_4c6cf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @446_4c6cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @447_4c6cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 220)))(ecx);  // @448_4c6cf0
  ecx = edx = 0;  // @449_4c6cf0
  ecx = eax;  // @450_4c6cf0
  eax = (u32)(715827883);  // @451_4c6cf0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @452_4c6cf0
  MOF = (u32)(edx + (((s32)eax < 0) ? 1 : 0));  // @453_4c6cf0
  eax = edx;  // @454_4c6cf0
  edx = (edx + (u32)(-3));  // @455_4c6cf0
  FL[3] = edx;  // @456_4c6cf0
  eax = (eax >> (u32)(31));  // @457_4c6cf0
  FL[3] = eax;  // @458_4c6cf0
  eax = (eax + edx);  // @459_4c6cf0
  FL[3] = eax;  // @460_4c6cf0
  PV[44] = (u32)(eax);  // @461_4c6cf0
  PV[45] = (u32)(esi);  // @462_4c6cf0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 388)))(PV[45], (u32)(0), PV[44], (u32)(6900964));  // @463_4c6cf0
  ecx = edx = 0;  // @464_4c6cf0
  L4c72e5:;
  SEH_LEAVE();  // @466_4c6cf0
  ext_633654(G(u32, 0x6f5630));  // @467_4c6cf0
  return eax;  // @468_4c6cf0
}
PCREG(4c6cf0, lifted_4c6cf0);

