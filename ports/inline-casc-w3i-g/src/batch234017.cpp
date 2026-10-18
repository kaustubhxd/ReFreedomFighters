// batch234017.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" s32 VECTORCALL ext_633910(float f);
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_59a5e0_thiscall2(u32, u32) __asm__("ext_59a5e0");
extern "C" u32 THISCALL ext_5a4f70_thiscall3(u32, u32, u32) __asm__("ext_5a4f70");
extern "C" u32 THISCALL ext_648e50_thiscall2(u32, u32) __asm__("ext_648e50");
extern "C" u32 THISCALL ext_64dde0_thiscall2(u32, u32) __asm__("ext_64dde0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5a4750(u32 ecx_in) {
  u32 PT = 0;
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5a4750
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @1_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @2_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, (u32)(0));  // @4_5a4750
  ecx = edx = 0;  // @5_5a4750
  FL[2] = (eax & eax);  // @6_5a4750
  if (FL[2] == 0) goto L5a4791;  // @7_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_5a4750
  PV[0] = (u32)(eax);  // @9_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @10_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 168)))(ecx, PV[0]);  // @12_5a4750
  ecx = edx = 0;  // @13_5a4750
  L5a4791:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @16_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @18_5a4750
  ecx = edx = 0;  // @19_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @21_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @23_5a4750
  ecx = edx = 0;  // @24_5a4750
  ecx = (u32)(EBP - 56);  // @25_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @26_5a4750
  PV[1] = (u32)(ecx);  // @27_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_5a4750
  ecx = eax;  // @29_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6880492), PV[1]);  // @30_5a4750
  ecx = edx = 0;  // @31_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @33_5a4750
  FL[2] = (ecx & ecx);  // @34_5a4750
  if (FL[2] == 0) goto L5a47ea;  // @35_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 244)))(ecx, (u32)(1));  // @37_5a4750
  ecx = edx = 0;  // @38_5a4750
  L5a47ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @40_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @41_5a4750
  eax = (eax - (u32)(2));  // @42_5a4750
  FL[3] = eax;  // @43_5a4750
  if (FL[3] == 0) goto L5a4825;  // @44_5a4750
  eax = (eax - (u32)(1));  // @45_5a4750
  FL[3] = eax;  // @46_5a4750
  if (FL[3] == 0) goto L5a481c;  // @47_5a4750
  eax = (eax - (u32)(1));  // @48_5a4750
  FL[3] = eax;  // @49_5a4750
  if (FL[3] == 0) goto L5a4813;  // @50_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @51_5a4750
  FL[2] = (eax & eax);  // @52_5a4750
  if (FL[2] == 0) goto L5a4810;  // @53_5a4750
  eax = ((u32(STDCALL *)(void))(eax))();  // @54_5a4750
  ecx = edx = 0;  // @55_5a4750
  goto L5a482c;  // @56_5a4750
  L5a4810:;
  __builtin_trap();  // @58_5a4750
  L5a4813:;
  { u32 v = (u32)((u32)(7262544)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @60_5a4750
  goto L5a482c;  // @61_5a4750
  L5a481c:;
  { u32 v = (u32)((u32)(7262480)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @63_5a4750
  goto L5a482c;  // @64_5a4750
  L5a4825:;
  { u32 v = (u32)((u32)(7262416)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @66_5a4750
  L5a482c:;
  ebx = 0;  // @68_5a4750
  FL[3] = ebx;  // @69_5a4750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @70_5a4750
  L5a4834:;
  eax = (u32)(ebx*8);  // @72_5a4750
  eax = (eax - ebx);  // @73_5a4750
  FL[3] = eax;  // @74_5a4750
  eax = (eax << (u32)(2));  // @75_5a4750
  FL[3] = eax;  // @76_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @77_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7262608), sizeof v); (u32)v; });  // @78_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @80_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @82_5a4750
  ecx = edx = 0;  // @83_5a4750
  ecx = (u32)(EBP - 21);  // @84_5a4750
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 21), &v, sizeof v); }  // @85_5a4750
  PV[2] = (u32)(ecx);  // @86_5a4750
  PV[3] = (u32)(esi);  // @87_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_5a4750
  ecx = eax;  // @89_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, PV[3], PV[2]);  // @90_5a4750
  ecx = edx = 0;  // @91_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_5a4750
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @93_5a4750
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @94_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @95_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7262612), sizeof v); (u32)v; });  // @96_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @98_5a4750
  ecx = edx = 0;  // @99_5a4750
  ecx = (u32)(EBP - 32);  // @100_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @101_5a4750
  PV[4] = (u32)(ecx);  // @102_5a4750
  PV[5] = (u32)(esi);  // @103_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @104_5a4750
  ecx = eax;  // @105_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[5], PV[4]);  // @106_5a4750
  ecx = edx = 0;  // @107_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7262620), sizeof v); (u32)v; });  // @109_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @110_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @112_5a4750
  ecx = edx = 0;  // @113_5a4750
  ecx = (u32)(EBP - 28);  // @114_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @115_5a4750
  PV[6] = (u32)(ecx);  // @116_5a4750
  PV[7] = (u32)(esi);  // @117_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @118_5a4750
  ecx = eax;  // @119_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[7], PV[6]);  // @120_5a4750
  ecx = edx = 0;  // @121_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @122_5a4750
  FL[2] = (edx & edx);  // @123_5a4750
  if (FL[2] == 0) goto L5a4b06;  // @124_5a4750
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @125_5a4750
  if (FL[0] != FL[1]) goto L5a48fa;  // @126_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @127_5a4750
  ecx = (u32)(1);  // @128_5a4750
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @129_5a4750
  eax = (eax & 0xff);  // @130_5a4750
  if (FL[0] == FL[1]) eax = ecx;  // @131_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @132_5a4750
  L5a48fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_5a4750
  PV[8] = (u32)(edx);  // @135_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @136_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[8]);  // @138_5a4750
  ecx = edx = 0;  // @139_5a4750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 21), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @140_5a4750
  esi = eax;  // @141_5a4750
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @142_5a4750
  if (FL[0] != FL[1]) goto L5a4947;  // @143_5a4750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @144_5a4750
  if (FL[0] != FL[1]) goto L5a4947;  // @145_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_5a4750
  ecx = esi;  // @147_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 596)))(ecx);  // @148_5a4750
  ecx = edx = 0;  // @149_5a4750
  L5a4926:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @151_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @152_5a4750
  FL[2] = (ecx & ecx);  // @153_5a4750
  if (FL[2] == 0) goto L5a4b06;  // @154_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_5a4750
  PV[9] = (u32)(ebx);  // @156_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[9]);  // @157_5a4750
  ecx = edx = 0;  // @158_5a4750
  goto L5a4b06;  // @159_5a4750
  L5a4947:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @161_5a4750
  ecx = esi;  // @162_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6805992));  // @163_5a4750
  ecx = edx = 0;  // @164_5a4750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @165_5a4750
  if (FL[0] == FL[1]) goto L5a4972;  // @166_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @167_5a4750
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 267), &v, sizeof v); }  // @168_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 271), &v, sizeof v); }  // @169_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @170_5a4750
  L5a4972:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @172_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @173_5a4750
  eax = (u32)(ebx + 1);  // @174_5a4750
  PV[10] = (u32)(eax);  // @175_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 160)))(ecx, PV[10]);  // @177_5a4750
  ecx = edx = 0;  // @178_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @179_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @180_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @181_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @182_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 216)))(ecx);  // @183_5a4750
  ecx = edx = 0;  // @184_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @185_5a4750
  esi = eax;  // @186_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @187_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @188_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 220)))(ecx);  // @189_5a4750
  ecx = edx = 0;  // @190_5a4750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @191_5a4750
  edi = eax;  // @192_5a4750
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @193_5a4750
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @194_5a4750
  esi = (esi >> (u32)(31));  // @195_5a4750
  FL[3] = esi;  // @196_5a4750
  ebx = (ebx << (u32)(4));  // @197_5a4750
  FL[3] = ebx;  // @198_5a4750
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; }));  // @199_5a4750
  FL[3] = ebx;  // @200_5a4750
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @201_5a4750
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @202_5a4750
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @203_5a4750
  X0[1] = 0;  // @204_5a4750
  X0[2] = 0;  // @205_5a4750
  X0[3] = 0;  // @206_5a4750
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @207_5a4750
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X1[0], 4);  // @208_5a4750
  eax = (u32)ext_633910(U2F(X0[0]));  // @209_5a4750
  ecx = edx = 0;  // @210_5a4750
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @211_5a4750
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @212_5a4750
  edi = (edi >> (u32)(31));  // @213_5a4750
  FL[3] = edi;  // @214_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @215_5a4750
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @216_5a4750
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @217_5a4750
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @218_5a4750
  X0[1] = 0;  // @219_5a4750
  X0[2] = 0;  // @220_5a4750
  X0[3] = 0;  // @221_5a4750
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @222_5a4750
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X1[0], 4);  // @223_5a4750
  eax = (u32)ext_633910(U2F(X0[0]));  // @224_5a4750
  ecx = edx = 0;  // @225_5a4750
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @226_5a4750
  X0[1] = 0;  // @227_5a4750
  X0[2] = 0;  // @228_5a4750
  X0[3] = 0;  // @229_5a4750
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; })));  // @230_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @231_5a4750
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; })));  // @232_5a4750
  eax = (u32)ext_633910(U2F(X0[0]));  // @233_5a4750
  ecx = edx = 0;  // @234_5a4750
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 12) + 0), 4); v; });  // @235_5a4750
  X0[1] = 0;  // @236_5a4750
  X0[2] = 0;  // @237_5a4750
  X0[3] = 0;  // @238_5a4750
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; })));  // @239_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @240_5a4750
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; })));  // @241_5a4750
  eax = (u32)ext_633910(U2F(X0[0]));  // @242_5a4750
  ecx = edx = 0;  // @243_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @244_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @245_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7008460), (u32)(348));  // @247_5a4750
  ecx = edx = 0;  // @248_5a4750
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @249_5a4750
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @250_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @251_5a4750
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @252_5a4750
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @253_5a4750
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @254_5a4750
  PV[16] = (u32)(eax);  // @255_5a4750
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[16], (u32)(7008648), PV[15], PV[14], PV[13], PV[12], PV[11]);  // @256_5a4750
  ecx = edx = 0;  // @257_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @258_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @259_5a4750
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; }) | (u32)(4194304))); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @260_5a4750
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 72), sizeof v); (u32)v; });  // @261_5a4750
  PV[17] = (u32)(eax);  // @262_5a4750
  eax = ext_648e50_thiscall2(ecx, PV[17]);  // @263_5a4750
  ecx = edx = 0;  // @264_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @265_5a4750
  eax = (u32)(EBP - 20);  // @266_5a4750
  PV[18] = (u32)(eax);  // @267_5a4750
  eax = ext_64dde0_thiscall2(ecx, PV[18]);  // @268_5a4750
    // @269_5a4750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @270_5a4750
  if (FL[0] != FL[1]) goto L5a4afb;  // @271_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @272_5a4750
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @273_5a4750
  if (FL[0] == FL[1]) goto L5a4b03;  // @274_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @275_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @276_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7262632), sizeof v); (u32)v; });  // @278_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @279_5a4750
  ecx = edx = 0;  // @280_5a4750
  ecx = (u32)(EBP - 32);  // @281_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @282_5a4750
  PV[19] = (u32)(ecx);  // @283_5a4750
  PV[20] = (u32)(esi);  // @284_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @285_5a4750
  ecx = eax;  // @286_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[20], PV[19]);  // @287_5a4750
  ecx = edx = 0;  // @288_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @289_5a4750
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @290_5a4750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @291_5a4750
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @292_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @293_5a4750
  PV[23] = (u32)(ebx);  // @294_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @295_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 248)))(ecx, PV[23], PV[22], PV[21]);  // @296_5a4750
  ecx = edx = 0;  // @297_5a4750
  goto L5a4b06;  // @298_5a4750
  L5a4afb:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @300_5a4750
  goto L5a4926;  // @301_5a4750
  L5a4b03:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @303_5a4750
  L5a4b06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @305_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7262624), sizeof v); (u32)v; });  // @306_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @307_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @308_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @309_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @310_5a4750
  ecx = edx = 0;  // @311_5a4750
  ecx = (u32)(EBP - 28);  // @312_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @313_5a4750
  PV[24] = (u32)(ecx);  // @314_5a4750
  PV[25] = (u32)(esi);  // @315_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @316_5a4750
  ecx = eax;  // @317_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[25], PV[24]);  // @318_5a4750
  ecx = edx = 0;  // @319_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @320_5a4750
  FL[2] = (edx & edx);  // @321_5a4750
  if (FL[2] == 0) goto L5a4b5d;  // @322_5a4750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 21), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @323_5a4750
  if (FL[0] != FL[1]) goto L5a4b5d;  // @324_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @325_5a4750
  PV[26] = (u32)(edx);  // @326_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @327_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @328_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[26]);  // @329_5a4750
  ecx = edx = 0;  // @330_5a4750
  ecx = eax;  // @331_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @332_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @333_5a4750
  ecx = edx = 0;  // @334_5a4750
  L5a4b5d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @336_5a4750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7262632), sizeof v); (u32)v; });  // @337_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @338_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @339_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @340_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @341_5a4750
  ecx = edx = 0;  // @342_5a4750
  ecx = (u32)(EBP - 28);  // @343_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @344_5a4750
  PV[27] = (u32)(ecx);  // @345_5a4750
  PV[28] = (u32)(esi);  // @346_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @347_5a4750
  ecx = eax;  // @348_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[28], PV[27]);  // @349_5a4750
  ecx = edx = 0;  // @350_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @351_5a4750
  FL[2] = (edx & edx);  // @352_5a4750
  if (FL[2] == 0) goto L5a4ca7;  // @353_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @354_5a4750
  PV[29] = (u32)(edx);  // @355_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @356_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @357_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[29]);  // @358_5a4750
  ecx = edx = 0;  // @359_5a4750
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @360_5a4750
  esi = eax;  // @361_5a4750
  if (FL[0] == FL[1]) goto L5a4c9a;  // @362_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @363_5a4750
  ecx = ebx;  // @364_5a4750
  ecx = (ecx - (u32)(1));  // @365_5a4750
  FL[3] = ecx;  // @366_5a4750
  if (FL[3] == 0) goto L5a4c50;  // @367_5a4750
  ecx = (ecx - (u32)(1));  // @368_5a4750
  FL[3] = ecx;  // @369_5a4750
  if (FL[3] == 0) goto L5a4c23;  // @370_5a4750
  ecx = (ecx - (u32)(1));  // @371_5a4750
  FL[3] = ecx;  // @372_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @373_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @374_5a4750
  if (FL[3] == 0) goto L5a4bfe;  // @375_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @376_5a4750
  ecx = edx = 0;  // @377_5a4750
  ecx = (u32)(EBP - 60);  // @378_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @379_5a4750
  PV[30] = (u32)(ecx);  // @380_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @381_5a4750
  ecx = eax;  // @382_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973184), PV[30]);  // @383_5a4750
  ecx = edx = 0;  // @384_5a4750
  PT = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @385_5a4750
  goto L5a4c7b;  // @386_5a4750
  L5a4bfe:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @388_5a4750
  ecx = edx = 0;  // @389_5a4750
  ecx = (u32)(EBP - 64);  // @390_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @391_5a4750
  PV[32] = (u32)(ecx);  // @392_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @393_5a4750
  ecx = eax;  // @394_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973232), PV[32]);  // @395_5a4750
  ecx = edx = 0;  // @396_5a4750
  PT = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @397_5a4750
  goto L5a4c7b;  // @398_5a4750
  L5a4c23:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @400_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @401_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @402_5a4750
  ecx = edx = 0;  // @403_5a4750
  ecx = (u32)(EBP - 68);  // @404_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @405_5a4750
  PV[34] = (u32)(ecx);  // @406_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @407_5a4750
  ecx = eax;  // @408_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973216), PV[34]);  // @409_5a4750
  ecx = edx = 0;  // @410_5a4750
  PT = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @411_5a4750
  goto L5a4c7b;  // @412_5a4750
  L5a4c50:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @414_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @415_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @416_5a4750
  ecx = edx = 0;  // @417_5a4750
  ecx = (u32)(EBP - 44);  // @418_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @419_5a4750
  PV[36] = (u32)(ecx);  // @420_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @421_5a4750
  ecx = eax;  // @422_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973200), PV[36]);  // @423_5a4750
  ecx = edx = 0;  // @424_5a4750
  PT = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @425_5a4750
  L5a4c7b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @427_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @428_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @429_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PT);  // @430_5a4750
  ecx = edx = 0;  // @431_5a4750
  ecx = eax;  // @432_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @433_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, (u32)(268435456));  // @434_5a4750
  ecx = edx = 0;  // @435_5a4750
  L5a4c9a:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 21), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @437_5a4750
  if (FL[0] != FL[1]) goto L5a4ca7;  // @438_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @439_5a4750
  ecx = esi;  // @440_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @441_5a4750
  ecx = edx = 0;  // @442_5a4750
  L5a4ca7:;
  ebx = (ebx + 1);  // @444_5a4750
  FL[3] = ebx;  // @445_5a4750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @446_5a4750
  FL[0] = ebx; FL[1] = (u32)(4);  // @447_5a4750
  if ((s32)FL[0] < (s32)FL[1]) goto L5a4834;  // @448_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @449_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @450_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @451_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @452_5a4750
  ecx = edx = 0;  // @453_5a4750
  ecx = (u32)(EBP - 44);  // @454_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @455_5a4750
  PV[38] = (u32)(ecx);  // @456_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @457_5a4750
  ecx = eax;  // @458_5a4750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(7008680), PV[38]);  // @459_5a4750
  ecx = edx = 0;  // @460_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @461_5a4750
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @462_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @463_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @464_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[39]);  // @465_5a4750
  ecx = edx = 0;  // @466_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @467_5a4750
  edi = eax;  // @468_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @469_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @470_5a4750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 160)))(ecx, (u32)(0));  // @471_5a4750
  ecx = edx = 0;  // @472_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @473_5a4750
  esi = eax;  // @474_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @475_5a4750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @476_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @477_5a4750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @478_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 216)))(ecx);  // @479_5a4750
  ecx = edx = 0;  // @480_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @481_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @482_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @483_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @484_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @485_5a4750
  ecx = edx = 0;  // @486_5a4750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @487_5a4750
  ecx = esi;  // @488_5a4750
  eax = (u32)(EBP - 20);  // @489_5a4750
  PV[40] = (u32)(eax);  // @490_5a4750
  eax = ext_64dde0_thiscall2(ecx, PV[40]);  // @491_5a4750
    // @492_5a4750
  PV[41] = (u32)(edi);  // @493_5a4750
  ecx = esi;  // @494_5a4750
  eax = ext_648e50_thiscall2(ecx, PV[41]);  // @495_5a4750
  ecx = edx = 0;  // @496_5a4750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @497_5a4750
  ecx = edi;  // @498_5a4750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @499_5a4750
  ecx = edx = 0;  // @500_5a4750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @501_5a4750
  ecx = ebx;  // @502_5a4750
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) | (u32)(1024))); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @503_5a4750
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @504_5a4750
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 299), sizeof v); (u32)v; });  // @505_5a4750
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 283), sizeof v); (u32)v; });  // @506_5a4750
  eax = ext_5a4f70_thiscall3(ecx, PV[43], PV[42]);  // @507_5a4750
  ecx = edx = 0;  // @508_5a4750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @509_5a4750
  eax = ext_589c20_thiscall2(ecx, (u32)(0));  // @510_5a4750
    // @511_5a4750
  ecx = eax;  // @512_5a4750
  eax = ext_59a5e0_thiscall2(ecx, (u32)(7));  // @513_5a4750
  ecx = edx = 0;  // @514_5a4750
  ext_633654(G(u32, 0x6f5630));  // @515_5a4750
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 94), &v, sizeof v); }  // @516_5a4750
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 96), &v, sizeof v); }  // @517_5a4750
  return eax;  // @518_5a4750
}
PCREG(5a4750, lifted_5a4750);

