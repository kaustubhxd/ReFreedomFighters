// batch234019.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_52b9d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_52b9d0
  edi = ecx;  // @1_52b9d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @2_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @4_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @5_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @6_52b9d0
  FL[2] = (eax & eax);  // @7_52b9d0
  if (FL[2] == 0) goto L52ba3e;  // @8_52b9d0
  L52ba01:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @10_52b9d0
  FL[2] = (ecx & ecx);  // @11_52b9d0
  if (FL[2] == 0) goto L52ba1d;  // @12_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @13_52b9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(2097173);  // @14_52b9d0
  if (FL[0] != FL[1]) goto L52ba1d;  // @15_52b9d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 91), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_52b9d0
  if (FL[0] == FL[1]) goto L52ba1d;  // @17_52b9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 54), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 54), &v, sizeof v); }  // @18_52b9d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 54), sizeof v); (u32)v; });  // @19_52b9d0
  L52ba1d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_52b9d0
  edx = (u32)(EBP - 36);  // @22_52b9d0
  PV[0] = (u32)(edx);  // @23_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @25_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[0]);  // @27_52b9d0
  ecx = edx = 0;  // @28_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @29_52b9d0
  FL[2] = (eax & eax);  // @30_52b9d0
  if (FL[2] != 0) goto L52ba01;  // @31_52b9d0
  L52ba3e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 54), sizeof v); (u32)v; });  // @33_52b9d0
  ecx = 0;  // @34_52b9d0
  FL[3] = ecx;  // @35_52b9d0
  edx = (u32)(52);  // @36_52b9d0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @37_52b9d0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @38_52b9d0
  FL[1] = ecx;  // @39_52b9d0
  ecx = (0u - ecx);  // @40_52b9d0
  ecx = (ecx | eax);  // @41_52b9d0
  FL[3] = ecx;  // @42_52b9d0
  PV[1] = (u32)(ecx);  // @43_52b9d0
  eax = ext_41e290_cdecl1(PV[1]);  // @44_52b9d0
  ecx = edx = 0;  // @45_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 58), &v, sizeof v); }  // @46_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @48_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @49_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @50_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @51_52b9d0
  FL[2] = (eax & eax);  // @52_52b9d0
  if (FL[2] == 0) goto L52bb97;  // @53_52b9d0
  esi = 0;  // @54_52b9d0
  FL[3] = esi;  // @55_52b9d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @56_52b9d0
  L52ba83:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @58_52b9d0
  FL[2] = (ebx & ebx);  // @59_52b9d0
  if (FL[2] == 0) goto L52bb72;  // @60_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @61_52b9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(2097173);  // @62_52b9d0
  if (FL[0] != FL[1]) goto L52bb72;  // @63_52b9d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 91), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @64_52b9d0
  if (FL[0] == FL[1]) goto L52bb72;  // @65_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @66_52b9d0
  ecx = ebx;  // @67_52b9d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + eax + 48), &v, sizeof v); }  // @68_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @69_52b9d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 580)))(ecx);  // @70_52b9d0
  ecx = edx = 0;  // @71_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @72_52b9d0
  esi = eax;  // @73_52b9d0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @74_52b9d0
  FL[3] = edx;  // @75_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_52b9d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @77_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @78_52b9d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @79_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @80_52b9d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @81_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @82_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @83_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @84_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 12), &v, sizeof v); }  // @85_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @86_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 16), &v, sizeof v); }  // @87_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @88_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 20), &v, sizeof v); }  // @89_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @90_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @91_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 24), &v, sizeof v); }  // @92_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @93_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 28), &v, sizeof v); }  // @94_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @95_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 32), &v, sizeof v); }  // @96_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @97_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @98_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 36), &v, sizeof v); }  // @99_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @100_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 40), &v, sizeof v); }  // @101_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @102_52b9d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @103_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 44), &v, sizeof v); }  // @104_52b9d0
  ecx = ebx;  // @105_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @106_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @107_52b9d0
  eax = (eax + esi);  // @108_52b9d0
  FL[3] = eax;  // @109_52b9d0
  PV[2] = (u32)(eax);  // @110_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[2]);  // @111_52b9d0
  ecx = edx = 0;  // @112_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @113_52b9d0
  ecx = ebx;  // @114_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @115_52b9d0
  eax = (eax + (u32)(12));  // @116_52b9d0
  FL[3] = eax;  // @117_52b9d0
  eax = (eax + esi);  // @118_52b9d0
  FL[3] = eax;  // @119_52b9d0
  PV[3] = (u32)(eax);  // @120_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[3]);  // @121_52b9d0
  ecx = edx = 0;  // @122_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @123_52b9d0
  ecx = ebx;  // @124_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @125_52b9d0
  eax = (eax + (u32)(24));  // @126_52b9d0
  FL[3] = eax;  // @127_52b9d0
  eax = (eax + esi);  // @128_52b9d0
  FL[3] = eax;  // @129_52b9d0
  PV[4] = (u32)(eax);  // @130_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[4]);  // @131_52b9d0
  ecx = edx = 0;  // @132_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @133_52b9d0
  ecx = ebx;  // @134_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @135_52b9d0
  eax = (eax + (u32)(36));  // @136_52b9d0
  FL[3] = eax;  // @137_52b9d0
  eax = (eax + esi);  // @138_52b9d0
  FL[3] = eax;  // @139_52b9d0
  PV[5] = (u32)(eax);  // @140_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[5]);  // @141_52b9d0
  ecx = edx = 0;  // @142_52b9d0
  esi = (esi + (u32)(52));  // @143_52b9d0
  FL[3] = esi;  // @144_52b9d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @145_52b9d0
  L52bb72:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @147_52b9d0
  edx = (u32)(EBP - 36);  // @148_52b9d0
  PV[6] = (u32)(edx);  // @149_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @150_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @151_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[6]);  // @153_52b9d0
  ecx = edx = 0;  // @154_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @155_52b9d0
  FL[2] = (eax & eax);  // @156_52b9d0
  if (FL[2] != 0) goto L52ba83;  // @157_52b9d0
  L52bb97:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 45), sizeof v); (u32)v; });  // @159_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_52b9d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @161_52b9d0
  ecx = edx = 0;  // @162_52b9d0
  ecx = 0;  // @163_52b9d0
  FL[3] = ecx;  // @164_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 62), &v, sizeof v); }  // @165_52b9d0
  edx = (u32)(52);  // @166_52b9d0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @167_52b9d0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @168_52b9d0
  FL[1] = ecx;  // @169_52b9d0
  ecx = (0u - ecx);  // @170_52b9d0
  ecx = (ecx | eax);  // @171_52b9d0
  FL[3] = ecx;  // @172_52b9d0
  PV[7] = (u32)(ecx);  // @173_52b9d0
  eax = ext_41e290_cdecl1(PV[7]);  // @174_52b9d0
  ecx = edx = 0;  // @175_52b9d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 62), sizeof v); (u32)v; });  // @176_52b9d0
  ecx = 0;  // @177_52b9d0
  FL[3] = ecx;  // @178_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 66), &v, sizeof v); }  // @179_52b9d0
  edx = (u32)(8);  // @180_52b9d0
  eax = esi;  // @181_52b9d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @182_52b9d0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @183_52b9d0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @184_52b9d0
  FL[1] = ecx;  // @185_52b9d0
  ecx = (0u - ecx);  // @186_52b9d0
  ecx = (ecx | eax);  // @187_52b9d0
  FL[3] = ecx;  // @188_52b9d0
  PV[8] = (u32)(ecx);  // @189_52b9d0
  eax = ext_41e290_cdecl1(PV[8]);  // @190_52b9d0
  ecx = edx = 0;  // @191_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @192_52b9d0
  FL[2] = (eax & eax);  // @193_52b9d0
  if (FL[2] == 0) goto L52bc07;  // @194_52b9d0
  ecx = eax;  // @195_52b9d0
  FL[2] = (esi & esi);  // @196_52b9d0
  if (FL[2] == 0) goto L52bc09;  // @197_52b9d0
  L52bbf0:;
  { u32 v = (u32)((u32)(6949992)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @199_52b9d0
  ecx = (u32)(ecx + 8);  // @200_52b9d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @201_52b9d0
  esi = (esi - (u32)(1));  // @202_52b9d0
  FL[3] = esi;  // @203_52b9d0
  if (FL[3] != 0) goto L52bbf0;  // @204_52b9d0
  goto L52bc09;  // @205_52b9d0
  L52bc07:;
  eax = 0;  // @207_52b9d0
  FL[3] = eax;  // @208_52b9d0
  L52bc09:;
  edx = 0;  // @210_52b9d0
  FL[3] = edx;  // @211_52b9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 125), &v, sizeof v); }  // @212_52b9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 62), sizeof v); (u32)v; }); FL[1] = edx;  // @213_52b9d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L52bc29;  // @214_52b9d0
  ecx = 0;  // @215_52b9d0
  FL[3] = ecx;  // @216_52b9d0
  L52bc15:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 66), sizeof v); (u32)v; });  // @218_52b9d0
  ecx = (u32)(ecx + 52);  // @219_52b9d0
  edx = (edx + 1);  // @220_52b9d0
  FL[3] = edx;  // @221_52b9d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx - 4), &v, sizeof v); }  // @222_52b9d0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 62), sizeof v); (u32)v; });  // @223_52b9d0
  if ((s32)FL[0] < (s32)FL[1]) goto L52bc15;  // @224_52b9d0
  L52bc29:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 45), sizeof v); (u32)v; });  // @226_52b9d0
  FL[2] = (ecx & ecx);  // @227_52b9d0
  if (FL[2] == 0) goto L52bfd8;  // @228_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_52b9d0
  edx = (u32)(EBP - 60);  // @230_52b9d0
  PV[9] = (u32)(edx);  // @231_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[9]);  // @232_52b9d0
  ecx = edx = 0;  // @233_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 45), sizeof v); (u32)v; });  // @234_52b9d0
  edx = (u32)(EBP - 60);  // @235_52b9d0
  PV[10] = (u32)(edx);  // @236_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @237_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[10]);  // @238_52b9d0
  ecx = edx = 0;  // @239_52b9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @240_52b9d0
  ebx = eax;  // @241_52b9d0
  if (FL[0] == FL[1]) goto L52bfd8;  // @242_52b9d0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @243_52b9d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @244_52b9d0
  L52bc63:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @246_52b9d0
  eax = (u32)(EBP - 28);  // @247_52b9d0
  PV[11] = (u32)(eax);  // @248_52b9d0
  eax = ext_4db7c0_thiscall2(ecx, PV[11]);  // @249_52b9d0
  edx = 0;  // @250_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6951868) + 0), 4); v; });  // @251_52b9d0
  X2[1] = 0;  // @252_52b9d0
  X2[2] = 0;  // @253_52b9d0
  X2[3] = 0;  // @254_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @255_52b9d0
  X1[1] = 0;  // @256_52b9d0
  X1[2] = 0;  // @257_52b9d0
  X1[3] = 0;  // @258_52b9d0
  X0[0] = X2[0];  // @259_52b9d0
  X0[1] = X2[1];  // @260_52b9d0
  X0[2] = X2[2];  // @261_52b9d0
  X0[3] = X2[3];  // @262_52b9d0
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @263_52b9d0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52bc87;  // @264_52b9d0
  X0[0] = X1[0];  // @265_52b9d0
  X0[1] = X1[1];  // @266_52b9d0
  X0[2] = X1[2];  // @267_52b9d0
  X0[3] = X1[3];  // @268_52b9d0
  L52bc87:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @270_52b9d0
  X1[1] = 0;  // @271_52b9d0
  X1[2] = 0;  // @272_52b9d0
  X1[3] = 0;  // @273_52b9d0
  esi = 0;  // @274_52b9d0
  FL[3] = esi;  // @275_52b9d0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @276_52b9d0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L52bc9b;  // @277_52b9d0
  X0[0] = X1[0];  // @278_52b9d0
  X0[1] = X1[1];  // @279_52b9d0
  X0[2] = X1[2];  // @280_52b9d0
  X0[3] = X1[3];  // @281_52b9d0
  esi = (u32)(1);  // @282_52b9d0
  L52bc9b:;
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; }));  // @284_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @285_52b9d0
  eax = (u32)(2);  // @286_52b9d0
  if ((!(!(FA >= FB)) && !(!((FA < FB) || (FA > FB))))) esi = eax;  // @287_52b9d0
  eax = (u32)(EBP - 16);  // @288_52b9d0
  PV[12] = (u32)(eax);  // @289_52b9d0
  eax = ext_4daf90_thiscall2(ecx, PV[12]);  // @290_52b9d0
  edx = 0;  // @291_52b9d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 66), sizeof v); (u32)v; });  // @292_52b9d0
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @293_52b9d0
  FL[3] = edi;  // @294_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @295_52b9d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @296_52b9d0
  PV[13] = (u32)(edx);  // @297_52b9d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @298_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @299_52b9d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @300_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 552)))(ecx, PV[13]);  // @301_52b9d0
  ecx = edx = 0;  // @302_52b9d0
  ecx = (u32)(6801640);  // @303_52b9d0
  edx = (u32)(6951340);  // @304_52b9d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @305_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @306_52b9d0
  FL[2] = (eax & eax);  // @307_52b9d0
  if (FL[2] != 0) ecx = eax;  // @308_52b9d0
  eax = ext_4cc850_fastcall2(ecx, edx);  // @309_52b9d0
  ecx = edx = 0;  // @310_52b9d0
  FL[2] = (eax & eax);  // @311_52b9d0
  if (FL[2] != 0) goto L52bd8f;  // @312_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @313_52b9d0
  X2[1] = 0;  // @314_52b9d0
  X2[2] = 0;  // @315_52b9d0
  X2[3] = 0;  // @316_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @317_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @318_52b9d0
  X1[1] = 0;  // @319_52b9d0
  X1[2] = 0;  // @320_52b9d0
  X1[3] = 0;  // @321_52b9d0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @322_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @323_52b9d0
  X0[1] = 0;  // @324_52b9d0
  X0[2] = 0;  // @325_52b9d0
  X0[3] = 0;  // @326_52b9d0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @327_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X2[0], 4);  // @328_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X1[0], 4);  // @329_52b9d0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @330_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @331_52b9d0
  X2[1] = 0;  // @332_52b9d0
  X2[2] = 0;  // @333_52b9d0
  X2[3] = 0;  // @334_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @335_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @336_52b9d0
  X1[1] = 0;  // @337_52b9d0
  X1[2] = 0;  // @338_52b9d0
  X1[3] = 0;  // @339_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @340_52b9d0
  X0[1] = 0;  // @341_52b9d0
  X0[2] = 0;  // @342_52b9d0
  X0[3] = 0;  // @343_52b9d0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @344_52b9d0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @345_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X2[0], 4);  // @346_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @347_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X1[0], 4);  // @348_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @349_52b9d0
  X2[1] = 0;  // @350_52b9d0
  X2[2] = 0;  // @351_52b9d0
  X2[3] = 0;  // @352_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @353_52b9d0
  X0[1] = 0;  // @354_52b9d0
  X0[2] = 0;  // @355_52b9d0
  X0[3] = 0;  // @356_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @357_52b9d0
  X1[1] = 0;  // @358_52b9d0
  X1[2] = 0;  // @359_52b9d0
  X1[3] = 0;  // @360_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @361_52b9d0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @362_52b9d0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @363_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X2[0], 4);  // @364_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @365_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X1[0], 4);  // @366_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @367_52b9d0
  X2[1] = 0;  // @368_52b9d0
  X2[2] = 0;  // @369_52b9d0
  X2[3] = 0;  // @370_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @371_52b9d0
  X0[1] = 0;  // @372_52b9d0
  X0[2] = 0;  // @373_52b9d0
  X0[3] = 0;  // @374_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @375_52b9d0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @376_52b9d0
  goto L52bf64;  // @377_52b9d0
  L52bd8f:;
  esi = (esi - (u32)(0));  // @379_52b9d0
  FL[3] = esi;  // @380_52b9d0
  if (FL[3] == 0) goto L52bede;  // @381_52b9d0
  esi = (esi - (u32)(1));  // @382_52b9d0
  FL[3] = esi;  // @383_52b9d0
  if (FL[3] == 0) goto L52be3f;  // @384_52b9d0
  esi = (esi - (u32)(1));  // @385_52b9d0
  FL[3] = esi;  // @386_52b9d0
  if (FL[3] != 0) goto L52bf7d;  // @387_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @388_52b9d0
  X2[1] = 0;  // @389_52b9d0
  X2[2] = 0;  // @390_52b9d0
  X2[3] = 0;  // @391_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @392_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @393_52b9d0
  X0[1] = 0;  // @394_52b9d0
  X0[2] = 0;  // @395_52b9d0
  X0[3] = 0;  // @396_52b9d0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @397_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @398_52b9d0
  X1[1] = 0;  // @399_52b9d0
  X1[2] = 0;  // @400_52b9d0
  X1[3] = 0;  // @401_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X1[0], 4);  // @402_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X2[0], 4);  // @403_52b9d0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @404_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @405_52b9d0
  X2[1] = 0;  // @406_52b9d0
  X2[2] = 0;  // @407_52b9d0
  X2[3] = 0;  // @408_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @409_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @410_52b9d0
  X0[1] = 0;  // @411_52b9d0
  X0[2] = 0;  // @412_52b9d0
  X0[3] = 0;  // @413_52b9d0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @414_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @415_52b9d0
  X1[1] = 0;  // @416_52b9d0
  X1[2] = 0;  // @417_52b9d0
  X1[3] = 0;  // @418_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X1[0], 4);  // @419_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X2[0], 4);  // @420_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @421_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @422_52b9d0
  X2[1] = 0;  // @423_52b9d0
  X2[2] = 0;  // @424_52b9d0
  X2[3] = 0;  // @425_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @426_52b9d0
  X0[1] = 0;  // @427_52b9d0
  X0[2] = 0;  // @428_52b9d0
  X0[3] = 0;  // @429_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @430_52b9d0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @431_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @432_52b9d0
  X1[1] = 0;  // @433_52b9d0
  X1[2] = 0;  // @434_52b9d0
  X1[3] = 0;  // @435_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X1[0], 4);  // @436_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X2[0], 4);  // @437_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @438_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @439_52b9d0
  X2[1] = 0;  // @440_52b9d0
  X2[2] = 0;  // @441_52b9d0
  X2[3] = 0;  // @442_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @443_52b9d0
  X0[1] = 0;  // @444_52b9d0
  X0[2] = 0;  // @445_52b9d0
  X0[3] = 0;  // @446_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @447_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @448_52b9d0
  X1[1] = 0;  // @449_52b9d0
  X1[2] = 0;  // @450_52b9d0
  X1[3] = 0;  // @451_52b9d0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @452_52b9d0
  goto L52bf6e;  // @453_52b9d0
  L52be3f:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @455_52b9d0
  X2[1] = 0;  // @456_52b9d0
  X2[2] = 0;  // @457_52b9d0
  X2[3] = 0;  // @458_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @459_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @460_52b9d0
  X0[1] = 0;  // @461_52b9d0
  X0[2] = 0;  // @462_52b9d0
  X0[3] = 0;  // @463_52b9d0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @464_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @465_52b9d0
  X1[1] = 0;  // @466_52b9d0
  X1[2] = 0;  // @467_52b9d0
  X1[3] = 0;  // @468_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X1[0], 4);  // @469_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X2[0], 4);  // @470_52b9d0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @471_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @472_52b9d0
  X2[1] = 0;  // @473_52b9d0
  X2[2] = 0;  // @474_52b9d0
  X2[3] = 0;  // @475_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @476_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @477_52b9d0
  X0[1] = 0;  // @478_52b9d0
  X0[2] = 0;  // @479_52b9d0
  X0[3] = 0;  // @480_52b9d0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @481_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @482_52b9d0
  X1[1] = 0;  // @483_52b9d0
  X1[2] = 0;  // @484_52b9d0
  X1[3] = 0;  // @485_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X1[0], 4);  // @486_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X2[0], 4);  // @487_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @488_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @489_52b9d0
  X2[1] = 0;  // @490_52b9d0
  X2[2] = 0;  // @491_52b9d0
  X2[3] = 0;  // @492_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @493_52b9d0
  X0[1] = 0;  // @494_52b9d0
  X0[2] = 0;  // @495_52b9d0
  X0[3] = 0;  // @496_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @497_52b9d0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; })));  // @498_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @499_52b9d0
  X1[1] = 0;  // @500_52b9d0
  X1[2] = 0;  // @501_52b9d0
  X1[3] = 0;  // @502_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X1[0], 4);  // @503_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X2[0], 4);  // @504_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @505_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @506_52b9d0
  X2[1] = 0;  // @507_52b9d0
  X2[2] = 0;  // @508_52b9d0
  X2[3] = 0;  // @509_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @510_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @511_52b9d0
  X0[1] = 0;  // @512_52b9d0
  X0[2] = 0;  // @513_52b9d0
  X0[3] = 0;  // @514_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @515_52b9d0
  X1[1] = 0;  // @516_52b9d0
  X1[2] = 0;  // @517_52b9d0
  X1[3] = 0;  // @518_52b9d0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @519_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 40) + 0), &X1[0], 4);  // @520_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 44) + 0), &X2[0], 4);  // @521_52b9d0
  goto L52bf78;  // @522_52b9d0
  L52bede:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @524_52b9d0
  X2[1] = 0;  // @525_52b9d0
  X2[2] = 0;  // @526_52b9d0
  X2[3] = 0;  // @527_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @528_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @529_52b9d0
  X1[1] = 0;  // @530_52b9d0
  X1[2] = 0;  // @531_52b9d0
  X1[3] = 0;  // @532_52b9d0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @533_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @534_52b9d0
  X0[1] = 0;  // @535_52b9d0
  X0[2] = 0;  // @536_52b9d0
  X0[3] = 0;  // @537_52b9d0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @538_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X2[0], 4);  // @539_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X1[0], 4);  // @540_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @541_52b9d0
  X2[1] = 0;  // @542_52b9d0
  X2[2] = 0;  // @543_52b9d0
  X2[3] = 0;  // @544_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @545_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @546_52b9d0
  X1[1] = 0;  // @547_52b9d0
  X1[2] = 0;  // @548_52b9d0
  X1[3] = 0;  // @549_52b9d0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @550_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @551_52b9d0
  X0[1] = 0;  // @552_52b9d0
  X0[2] = 0;  // @553_52b9d0
  X0[3] = 0;  // @554_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X0[0], 4);  // @555_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X2[0], 4);  // @556_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X1[0], 4);  // @557_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @558_52b9d0
  X2[1] = 0;  // @559_52b9d0
  X2[2] = 0;  // @560_52b9d0
  X2[3] = 0;  // @561_52b9d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @562_52b9d0
  X1[1] = 0;  // @563_52b9d0
  X1[2] = 0;  // @564_52b9d0
  X1[3] = 0;  // @565_52b9d0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @566_52b9d0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @567_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @568_52b9d0
  X0[1] = 0;  // @569_52b9d0
  X0[2] = 0;  // @570_52b9d0
  X0[3] = 0;  // @571_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @572_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X2[0], 4);  // @573_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X1[0], 4);  // @574_52b9d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @575_52b9d0
  X2[1] = 0;  // @576_52b9d0
  X2[2] = 0;  // @577_52b9d0
  X2[3] = 0;  // @578_52b9d0
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @579_52b9d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @580_52b9d0
  X0[1] = 0;  // @581_52b9d0
  X0[2] = 0;  // @582_52b9d0
  X0[3] = 0;  // @583_52b9d0
  L52bf64:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @585_52b9d0
  X1[1] = 0;  // @586_52b9d0
  X1[2] = 0;  // @587_52b9d0
  X1[3] = 0;  // @588_52b9d0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @589_52b9d0
  L52bf6e:;
  __builtin_memcpy((void *)((u32)(edi + 44) + 0), &X1[0], 4);  // @591_52b9d0
  __builtin_memcpy((void *)((u32)(edi + 40) + 0), &X2[0], 4);  // @592_52b9d0
  L52bf78:;
  __builtin_memcpy((void *)((u32)(edi + 36) + 0), &X0[0], 4);  // @594_52b9d0
  L52bf7d:;
  esi = edi;  // @596_52b9d0
  edi = (u32)(4);  // @597_52b9d0
  L52bf84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @599_52b9d0
  ecx = ebx;  // @600_52b9d0
  PV[14] = (u32)(esi);  // @601_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[14]);  // @602_52b9d0
  ecx = edx = 0;  // @603_52b9d0
  esi = (esi + (u32)(12));  // @604_52b9d0
  FL[3] = esi;  // @605_52b9d0
  edi = (edi - (u32)(1));  // @606_52b9d0
  FL[3] = edi;  // @607_52b9d0
  if (FL[3] != 0) goto L52bf84;  // @608_52b9d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @609_52b9d0
  ecx = (u32)(EBP - 72);  // @610_52b9d0
  edx = edi;  // @611_52b9d0
  esi = (u32)(edi + 12);  // @612_52b9d0
  PV[15] = (u32)(esi);  // @613_52b9d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[15]);  // @614_52b9d0
  ecx = edx = 0;  // @615_52b9d0
  eax = (u32)(edi + 24);  // @616_52b9d0
  edx = esi;  // @617_52b9d0
  PV[16] = (u32)(eax);  // @618_52b9d0
  ecx = (u32)(EBP - 84);  // @619_52b9d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[16]);  // @620_52b9d0
  ecx = edx = 0;  // @621_52b9d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @622_52b9d0
  edx = (u32)(EBP - 60);  // @623_52b9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) + (u32)(52))); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @624_52b9d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @625_52b9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @626_52b9d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @627_52b9d0
  PV[17] = (u32)(edx);  // @628_52b9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 45), sizeof v); (u32)v; });  // @629_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @630_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[17]);  // @631_52b9d0
  ecx = edx = 0;  // @632_52b9d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @633_52b9d0
  ebx = eax;  // @634_52b9d0
  if (FL[0] != FL[1]) goto L52bc63;  // @635_52b9d0
  L52bfd8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 45), sizeof v); (u32)v; });  // @637_52b9d0
  FL[2] = (ecx & ecx);  // @638_52b9d0
  if (FL[2] == 0) goto L52bfe7;  // @639_52b9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @640_52b9d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @641_52b9d0
  ecx = edx = 0;  // @642_52b9d0
  L52bfe7:;
  ext_633654(G(u32, 0x6f5630));  // @644_52b9d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 45), &v, sizeof v); }  // @645_52b9d0
  return eax;  // @646_52b9d0
}
PCREG(52b9d0, lifted_52b9d0);

