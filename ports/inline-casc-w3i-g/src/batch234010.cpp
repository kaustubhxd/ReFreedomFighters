// batch234010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_45d380_thiscall3(u32, u32, u32) __asm__("ext_45d380");
extern "C" u32 THISCALL ext_48aad0_thiscall1(u32) __asm__("ext_48aad0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_589c20_thiscall2(u32, u32) __asm__("ext_589c20");
extern "C" u32 THISCALL ext_58b6a0_thiscall1(u32) __asm__("ext_58b6a0");
extern "C" u32 THISCALL ext_596940_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_596940");
extern "C" u32 THISCALL ext_59b710_thiscall1(u32) __asm__("ext_59b710");
extern "C" u32 THISCALL ext_59be70_thiscall1(u32) __asm__("ext_59be70");
extern "C" u32 THISCALL ext_59c420_thiscall1(u32) __asm__("ext_59c420");
extern "C" u32 THISCALL ext_5b0af0_thiscall2(u32, u32) __asm__("ext_5b0af0");
extern "C" u32 THISCALL ext_5c2120_thiscall2(u32, u32) __asm__("ext_5c2120");
extern "C" u32 THISCALL ext_5c21e0_thiscall2(u32, u32) __asm__("ext_5c21e0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_472ae0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_472ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_472ae0
  edi = ecx;  // @2_472ae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @3_472ae0
  ecx = 0;  // @4_472ae0
  FL[3] = ecx;  // @5_472ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @6_472ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @7_472ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @8_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338396), sizeof v); (u32)v; });  // @9_472ae0
  if (FL[0] == FL[1]) goto L472bb1;  // @10_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338404), sizeof v); (u32)v; });  // @11_472ae0
  if (FL[0] == FL[1]) goto L472b53;  // @12_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338408), sizeof v); (u32)v; });  // @13_472ae0
  if (FL[0] == FL[1]) goto L472b53;  // @14_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338416), sizeof v); (u32)v; });  // @15_472ae0
  if (FL[0] == FL[1]) goto L472b53;  // @16_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338412), sizeof v); (u32)v; });  // @17_472ae0
  if (FL[0] == FL[1]) goto L472b53;  // @18_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338428), sizeof v); (u32)v; });  // @19_472ae0
  if (FL[0] == FL[1]) goto L472b53;  // @20_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338400), sizeof v); (u32)v; });  // @21_472ae0
  if (FL[0] != FL[1]) goto L472bb1;  // @22_472ae0
  L472b53:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_472ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @25_472ae0
  ecx = (u32)(EBP - 120);  // @26_472ae0
  PV[0] = (u32)(ecx);  // @27_472ae0
  ecx = esi;  // @28_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6851120), PV[0]);  // @29_472ae0
  ecx = edx = 0;  // @30_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @32_472ae0
  PV[1] = (u32)(edx);  // @33_472ae0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @34_472ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @37_472ae0
  ecx = edx = 0;  // @38_472ae0
  ecx = eax;  // @39_472ae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @40_472ae0
  FL[2] = (ecx & ecx);  // @41_472ae0
  if (FL[2] == 0) goto L472b97;  // @42_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @44_472ae0
  ecx = edx = 0;  // @45_472ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @46_472ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @47_472ae0
  L472b97:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338416), sizeof v); (u32)v; });  // @49_472ae0
  if (FL[0] != FL[1]) goto L472bb1;  // @50_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_472ae0
  ecx = esi;  // @52_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(6854708), (u32)(1));  // @53_472ae0
  ecx = edx = 0;  // @54_472ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @55_472ae0
  L472bb1:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338404), sizeof v); (u32)v; });  // @57_472ae0
  if (FL[0] != FL[1]) goto L472bca;  // @58_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @59_472ae0
  PV[2] = (u32)(ecx);  // @60_472ae0
  ecx = edi;  // @61_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1160)))(ecx, PV[2]);  // @62_472ae0
  ecx = edx = 0;  // @63_472ae0
  goto L472fb4;  // @64_472ae0
  L472bca:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338400), sizeof v); (u32)v; });  // @66_472ae0
  if (FL[0] != FL[1]) goto L472be3;  // @67_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @68_472ae0
  PV[3] = (u32)(ecx);  // @69_472ae0
  ecx = edi;  // @70_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1164)))(ecx, PV[3]);  // @71_472ae0
  ecx = edx = 0;  // @72_472ae0
  goto L472fb4;  // @73_472ae0
  L472be3:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338408), sizeof v); (u32)v; });  // @75_472ae0
  if (FL[0] != FL[1]) goto L472ca0;  // @76_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_472ae0
  ecx = (u32)(EBP - 128);  // @78_472ae0
  PV[4] = (u32)(ecx);  // @79_472ae0
  ecx = esi;  // @80_472ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @81_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6854716), PV[4]);  // @82_472ae0
  ecx = edx = 0;  // @83_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_472ae0
  ecx = (u32)(EBP - 124);  // @85_472ae0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @86_472ae0
  PV[5] = (u32)(ecx);  // @87_472ae0
  ecx = esi;  // @88_472ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @89_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(6854724), PV[5]);  // @90_472ae0
  ecx = edx = 0;  // @91_472ae0
  FL[2] = (ebx & ebx);  // @92_472ae0
  if (FL[2] == 0) goto L472fb4;  // @93_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @94_472ae0
  ecx = ebx;  // @95_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @96_472ae0
  ecx = edx = 0;  // @97_472ae0
  FL[2] = (eax & eax);  // @98_472ae0
  if (FL[2] == 0) goto L472fb4;  // @99_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @100_472ae0
  ecx = ebx;  // @101_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @102_472ae0
  ecx = edx = 0;  // @103_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_472ae0
  ecx = ebx;  // @105_472ae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @106_472ae0
  esi = 0;  // @107_472ae0
  FL[3] = esi;  // @108_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @109_472ae0
  ecx = edx = 0;  // @110_472ae0
  FL[0] = eax; FL[1] = (u32)(2);  // @111_472ae0
  if (FL[0] != FL[1]) goto L472c63;  // @112_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @113_472ae0
  ecx = ebx;  // @114_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 48)))(ecx, (u32)(1));  // @115_472ae0
  ecx = edx = 0;  // @116_472ae0
  esi = eax;  // @117_472ae0
  L472c63:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @119_472ae0
  ecx = edi;  // @120_472ae0
  if (FL[0] != FL[1]) goto L472c90;  // @121_472ae0
  FL[2] = (esi & esi);  // @122_472ae0
  if (FL[2] == 0) goto L472c80;  // @123_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @124_472ae0
  PV[6] = (u32)(esi);  // @125_472ae0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @126_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 1156)))(ecx, PV[7], PV[6]);  // @127_472ae0
  ecx = edx = 0;  // @128_472ae0
  goto L472fb4;  // @129_472ae0
  L472c80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @131_472ae0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @132_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1148)))(ecx, PV[8]);  // @133_472ae0
  ecx = edx = 0;  // @134_472ae0
  goto L472fb4;  // @135_472ae0
  L472c90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @137_472ae0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @138_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1152)))(ecx, PV[9]);  // @139_472ae0
  ecx = edx = 0;  // @140_472ae0
  goto L472fb4;  // @141_472ae0
  L472ca0:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338420), sizeof v); (u32)v; });  // @143_472ae0
  if (FL[0] != FL[1]) goto L472cb6;  // @144_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @145_472ae0
  ecx = edi;  // @146_472ae0
  PV[10] = (u32)(esi);  // @147_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1096)))(ecx, PV[10]);  // @148_472ae0
  ecx = edx = 0;  // @149_472ae0
  goto L472cca;  // @150_472ae0
  L472cb6:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338424), sizeof v); (u32)v; });  // @152_472ae0
  if (FL[0] != FL[1]) goto L472cca;  // @153_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @154_472ae0
  ecx = edi;  // @155_472ae0
  PV[11] = (u32)(esi);  // @156_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1100)))(ecx, PV[11]);  // @157_472ae0
  ecx = edx = 0;  // @158_472ae0
  L472cca:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338412), sizeof v); (u32)v; });  // @160_472ae0
  if (FL[0] == FL[1]) goto L472ce0;  // @161_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338416), sizeof v); (u32)v; });  // @162_472ae0
  if (FL[0] != FL[1]) goto L472f5a;  // @163_472ae0
  L472ce0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @165_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 768)))(ecx);  // @167_472ae0
  ecx = edx = 0;  // @168_472ae0
  FL[2] = (eax & eax);  // @169_472ae0
  if (FL[2] == 0) goto L472f5a;  // @170_472ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @171_472ae0
  ecx = (u32)(EBP - 40);  // @172_472ae0
  PV[12] = (u32)(ecx);  // @173_472ae0
  ecx = (u32)(EBP - 112);  // @174_472ae0
  PV[13] = (u32)(ecx);  // @175_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_472ae0
  ecx = esi;  // @177_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 736)))(ecx, PV[13], PV[12]);  // @178_472ae0
  ecx = edx = 0;  // @179_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @180_472ae0
  ecx = (u32)(EBP - 40);  // @181_472ae0
  PV[14] = (u32)(ecx);  // @182_472ae0
  ecx = (u32)(EBP - 112);  // @183_472ae0
  PV[15] = (u32)(ecx);  // @184_472ae0
  ecx = esi;  // @185_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[15], PV[14]);  // @186_472ae0
  ecx = edx = 0;  // @187_472ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @188_472ae0
  eax = (u32)(EBP - 28);  // @189_472ae0
  PV[16] = (u32)(eax);  // @190_472ae0
  eax = (u32)(EBP - 76);  // @191_472ae0
  ecx = edi;  // @192_472ae0
  PV[17] = (u32)(eax);  // @193_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 936)))(ecx, PV[17], PV[16]);  // @194_472ae0
  ecx = edx = 0;  // @195_472ae0
  PV[18] = (u32)(eax);  // @196_472ae0
  ecx = edi;  // @197_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[18]);  // @198_472ae0
  ecx = edx = 0;  // @199_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @200_472ae0
  ecx = (u32)(EBP - 28);  // @201_472ae0
  PV[19] = (u32)(ecx);  // @202_472ae0
  ecx = (u32)(EBP - 76);  // @203_472ae0
  PV[20] = (u32)(ecx);  // @204_472ae0
  ecx = edi;  // @205_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[20], PV[19]);  // @206_472ae0
  ecx = edx = 0;  // @207_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @208_472ae0
  ecx = (u32)(EBP - 16);  // @209_472ae0
  PV[21] = (u32)(ecx);  // @210_472ae0
  ecx = (u32)(EBP - 76);  // @211_472ae0
  PV[22] = (u32)(ecx);  // @212_472ae0
  ecx = edi;  // @213_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[22], PV[21]);  // @214_472ae0
  ecx = edx = 0;  // @215_472ae0
  eax = (u32)(EBP - 28);  // @216_472ae0
  PV[23] = (u32)(eax);  // @217_472ae0
  edx = (u32)(EBP - 40);  // @218_472ae0
  ecx = (u32)(EBP - 16);  // @219_472ae0
  eax = ext_43e920_fastcall3(ecx, edx, PV[23]);  // @220_472ae0
  ecx = edx = 0;  // @221_472ae0
  edx = (u32)(EBP - 76);  // @222_472ae0
  ecx = (u32)(EBP - 16);  // @223_472ae0
  eax = ext_441a60_fastcall2(ecx, edx);  // @224_472ae0
  ecx = edx = 0;  // @225_472ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @226_472ae0
  X1[1] = 0;  // @227_472ae0
  X1[2] = 0;  // @228_472ae0
  X1[3] = 0;  // @229_472ae0
  FA = U2F(X1[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6855972) + 0), 4); v; }));  // @230_472ae0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L472f57;  // @231_472ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @232_472ae0
  X0[1] = 0;  // @233_472ae0
  X0[2] = 0;  // @234_472ae0
  X0[3] = 0;  // @235_472ae0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @236_472ae0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L472f57;  // @237_472ae0
  X0[0] = 0;  // @238_472ae0
  X0[1] = 0;  // @239_472ae0
  X0[2] = 0;  // @240_472ae0
  X0[3] = 0;  // @241_472ae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @242_472ae0
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338416), sizeof v); (u32)v; });  // @243_472ae0
  if (FL[0] != FL[1]) goto L472de6;  // @244_472ae0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @245_472ae0
  X1[1] = 0;  // @246_472ae0
  X1[2] = 0;  // @247_472ae0
  X1[3] = 0;  // @248_472ae0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @249_472ae0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @250_472ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @251_472ae0
  X0[1] = 0;  // @252_472ae0
  X0[2] = 0;  // @253_472ae0
  X0[3] = 0;  // @254_472ae0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @255_472ae0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @256_472ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6855968) + 0), 4); v; });  // @257_472ae0
  X0[1] = 0;  // @258_472ae0
  X0[2] = 0;  // @259_472ae0
  X0[3] = 0;  // @260_472ae0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @261_472ae0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L472de6;  // @262_472ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @263_472ae0
  ecx = esi;  // @264_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @265_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(6854708), (u32)(0));  // @266_472ae0
  ecx = edx = 0;  // @267_472ae0
  goto L472f5a;  // @268_472ae0
  L472de6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @270_472ae0
  ecx = edi;  // @271_472ae0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @272_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1144)))(ecx, PV[24]);  // @273_472ae0
  ecx = edx = 0;  // @274_472ae0
  FL[0] = eax; FL[1] = (u32)(6);  // @275_472ae0
  if (FL[0] != FL[1]) goto L472e1a;  // @276_472ae0
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @277_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @278_472ae0
  ecx = edi;  // @279_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(4), PV[25]);  // @280_472ae0
  ecx = edx = 0;  // @281_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @282_472ae0
  ecx = edi;  // @283_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(11), (u32)(0));  // @284_472ae0
  ecx = edx = 0;  // @285_472ae0
  goto L472f57;  // @286_472ae0
  L472e1a:;
  FL[0] = eax; FL[1] = (u32)(1);  // @288_472ae0
  if (FL[0] != FL[1]) goto L472e33;  // @289_472ae0
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @290_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @291_472ae0
  ecx = edi;  // @292_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(3), PV[26]);  // @293_472ae0
  ecx = edx = 0;  // @294_472ae0
  goto L472f57;  // @295_472ae0
  L472e33:;
  FL[0] = eax; FL[1] = (u32)(2);  // @297_472ae0
  if (FL[0] != FL[1]) goto L472e4c;  // @298_472ae0
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @299_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @300_472ae0
  ecx = edi;  // @301_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(4), PV[27]);  // @302_472ae0
  ecx = edx = 0;  // @303_472ae0
  goto L472f57;  // @304_472ae0
  L472e4c:;
  FL[0] = eax; FL[1] = (u32)(3);  // @306_472ae0
  if (FL[0] != FL[1]) goto L472e7f;  // @307_472ae0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @308_472ae0
  X0[1] = 0;  // @309_472ae0
  X0[2] = 0;  // @310_472ae0
  X0[3] = 0;  // @311_472ae0
  X1[0] = 0;  // @312_472ae0
  X1[1] = 0;  // @313_472ae0
  X1[2] = 0;  // @314_472ae0
  X1[3] = 0;  // @315_472ae0
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @316_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @317_472ae0
  ecx = edi;  // @318_472ae0
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @319_472ae0
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L472e72;  // @320_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(3), PV[28]);  // @321_472ae0
  ecx = edx = 0;  // @322_472ae0
  goto L472f57;  // @323_472ae0
  L472e72:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(4));  // @325_472ae0
  ecx = edx = 0;  // @326_472ae0
  goto L472f57;  // @327_472ae0
  L472e7f:;
  FL[0] = eax; FL[1] = (u32)(4);  // @329_472ae0
  if (FL[0] != FL[1]) goto L472eea;  // @330_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @331_472ae0
  ecx = edi;  // @332_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1280)))(ecx);  // @333_472ae0
  ecx = edx = 0;  // @334_472ae0
  esi = eax;  // @335_472ae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @336_472ae0
  FL[2] = (esi & esi);  // @337_472ae0
  if (FL[2] == 0) goto L472ea8;  // @338_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @339_472ae0
  ecx = edi;  // @340_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 1116)))(ecx, (u32)(5), (u32)(0));  // @341_472ae0
  ecx = edx = 0;  // @342_472ae0
  L472ea8:;
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @344_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @345_472ae0
  ecx = edi;  // @346_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(3), PV[29]);  // @347_472ae0
  ecx = edx = 0;  // @348_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @349_472ae0
  ecx = edi;  // @350_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(5), (u32)(0));  // @351_472ae0
  ecx = edx = 0;  // @352_472ae0
  FL[2] = (esi & esi);  // @353_472ae0
  if (FL[2] == 0) goto L472f57;  // @354_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @355_472ae0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @356_472ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @357_472ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @358_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @359_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[30]);  // @360_472ae0
  ecx = edx = 0;  // @361_472ae0
  PV[31] = (u32)(eax);  // @362_472ae0
  goto L472f4f;  // @363_472ae0
  L472eea:;
  FL[0] = eax; FL[1] = (u32)(5);  // @365_472ae0
  if (FL[0] != FL[1]) goto L472f57;  // @366_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @367_472ae0
  ecx = edi;  // @368_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1284)))(ecx, (u32)(7), PV[31]);  // @369_472ae0
  ecx = edx = 0;  // @370_472ae0
  esi = eax;  // @371_472ae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @372_472ae0
  FL[2] = (esi & esi);  // @373_472ae0
  if (FL[2] == 0) goto L472f13;  // @374_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @375_472ae0
  ecx = edi;  // @376_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 1116)))(ecx, (u32)(6), (u32)(0));  // @377_472ae0
  ecx = edx = 0;  // @378_472ae0
  L472f13:;
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @380_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @381_472ae0
  ecx = edi;  // @382_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(4), PV[32]);  // @383_472ae0
  ecx = edx = 0;  // @384_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @385_472ae0
  ecx = edi;  // @386_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1116)))(ecx, (u32)(6), (u32)(0));  // @387_472ae0
  ecx = edx = 0;  // @388_472ae0
  FL[2] = (esi & esi);  // @389_472ae0
  if (FL[2] == 0) goto L472f57;  // @390_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @391_472ae0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @392_472ae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @393_472ae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @394_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[33]);  // @396_472ae0
  ecx = edx = 0;  // @397_472ae0
  PV[34] = (u32)(eax);  // @398_472ae0
  L472f4f:;
  ecx = edi;  // @400_472ae0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 1116)))(ecx, (u32)(8), PV[34]);  // @401_472ae0
  ecx = edx = 0;  // @402_472ae0
  L472f57:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @404_472ae0
  L472f5a:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 359), sizeof v); (u32)v; });  // @406_472ae0
  if (FL[0] != FL[1]) goto L472f8f;  // @407_472ae0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 361), sizeof v); (u32)v; }); FL[1] = esi;  // @408_472ae0
  if (FL[0] != FL[1]) goto L472f8f;  // @409_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @410_472ae0
  ecx = edi;  // @411_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1280)))(ecx);  // @412_472ae0
  ecx = edx = 0;  // @413_472ae0
  FL[2] = (eax & eax);  // @414_472ae0
  if (FL[2] == 0) goto L472f8f;  // @415_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @416_472ae0
  ecx = edi;  // @417_472ae0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1280)))(ecx);  // @418_472ae0
  ecx = edx = 0;  // @419_472ae0
  ecx = eax;  // @420_472ae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @421_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @422_472ae0
  ecx = edx = 0;  // @423_472ae0
  L472f8f:;
  FL[0] = (ebx & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338428), sizeof v); (u32)v; });  // @425_472ae0
  if (FL[0] != FL[1]) goto L472fa5;  // @426_472ae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @427_472ae0
  ecx = edi;  // @428_472ae0
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @429_472ae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1260)))(ecx, PV[35]);  // @430_472ae0
  ecx = edx = 0;  // @431_472ae0
  L472fa5:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @433_472ae0
  if (FL[0] != FL[1]) goto L472fb4;  // @434_472ae0
  PV[36] = (u32)(esi);  // @435_472ae0
  PV[37] = (u32)(ebx);  // @436_472ae0
  ecx = edi;  // @437_472ae0
  eax = ext_45d380_thiscall3(ecx, PV[37], PV[36]);  // @438_472ae0
  ecx = edx = 0;  // @439_472ae0
  L472fb4:;
  ext_633654(G(u32, 0x6f5630));  // @441_472ae0
  eax = 0;  // @442_472ae0
  FL[3] = eax;  // @443_472ae0
  return eax;  // @444_472ae0
}
PCREG(472ae0, lifted_472ae0);

extern "C" u32 THISCALL lifted_5c0fc0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 PT = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0d0d0d0d, esi = 0x0d0d0d0d, edi = 0x0d0d0d0d;   // w3g: the harness enters with 0x0d0d0d0d in the callee-saved registers and the code pushes `esi` after a 16-bit write
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = (esi & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @0_5c0fc0
  eax = (u32)(1025);  // @1_5c0fc0
  ebx = ecx;  // @2_5c0fc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_5c0fc0
  FL[0] = (esi & 0xffff); FL[1] = (eax & 0xffff);  // @4_5c0fc0
  if (FL[0] != FL[1]) goto L5c100e;  // @5_5c0fc0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @6_5c0fc0
  eax = ext_5c2120_thiscall2(ecx, PV[0]);  // @7_5c0fc0
  ecx = edx = 0;  // @8_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_5c0fc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7005), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @10_5c0fc0
  if (FL[0] != FL[1]) goto L5c161d;  // @11_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_5c0fc0
  ecx = ebx;  // @13_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(16));  // @14_5c0fc0
  ecx = edx = 0;  // @15_5c0fc0
  goto L5c161d;  // @16_5c0fc0
  L5c100e:;
  eax = (u32)(1024);  // @18_5c0fc0
  FL[0] = (esi & 0xffff); FL[1] = (eax & 0xffff);  // @19_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_5c0fc0
  if (FL[0] != FL[1]) goto L5c1038;  // @21_5c0fc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7005), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_5c0fc0
  if (FL[0] != FL[1]) goto L5c161d;  // @23_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @25_5c0fc0
  ecx = edx = 0;  // @26_5c0fc0
  goto L5c161d;  // @27_5c0fc0
  L5c1038:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027660), (u32)(0), (u32)(7027316), (u32)(270));  // @31_5c0fc0
  ecx = edx = 0;  // @32_5c0fc0
  FL[0] = (esi & 0xffff); FL[1] = (eax & 0xffff);  // @33_5c0fc0
  if (FL[0] != FL[1]) goto L5c1068;  // @34_5c0fc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 261), &v, sizeof v); }  // @35_5c0fc0
  goto L5c161d;  // @36_5c0fc0
  L5c1068:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @39_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027676), (u32)(0), (u32)(7027316), (u32)(273));  // @41_5c0fc0
  ecx = edx = 0;  // @42_5c0fc0
  FL[0] = (esi & 0xffff); FL[1] = (eax & 0xffff);  // @43_5c0fc0
  if (FL[0] != FL[1]) goto L5c10a4;  // @44_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @45_5c0fc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 261), &v, sizeof v); }  // @46_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @47_5c0fc0
  PV[1] = (u32)(eax);  // @48_5c0fc0
  PT = PV[1]; goto L5c1616;  // @49_5c0fc0
  L5c10a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7027692), (u32)(0), (u32)(7027316), (u32)(277));  // @54_5c0fc0   (w3g hand fix: PV[1] was a stale `push eax` of the jumped-over path)
  ecx = edx = 0;  // @55_5c0fc0
  FL[0] = (esi & 0xffff); FL[1] = (eax & 0xffff);  // @56_5c0fc0
  if (FL[0] != FL[1]) goto L5c10db;  // @57_5c0fc0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 261), sizeof v); (u32)v; });  // @58_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @59_5c0fc0
  goto L5c161d;  // @60_5c0fc0
  L5c10db:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422728), sizeof v); (u32)v; });  // @62_5c0fc0
  if (FL[0] != FL[1]) goto L5c1552;  // @63_5c0fc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 261), &v, sizeof v); }  // @64_5c0fc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 263), &v, sizeof v); }  // @65_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @69_5c0fc0
  ecx = edx = 0;  // @70_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @71_5c0fc0
  ecx = (u32)(EBP - 24);  // @72_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_5c0fc0
  { u32 v = (u32)((u32)(6970440)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @74_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @75_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_5c0fc0
  eax = ext_48aad0_thiscall1(ecx);  // @77_5c0fc0
  ecx = edx = 0;  // @78_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_5c0fc0
  PV[2] = (u32)(eax);  // @80_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @81_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[2]);  // @82_5c0fc0
  ecx = edx = 0;  // @83_5c0fc0
  edi = eax;  // @84_5c0fc0
  FL[2] = (edi & edi);  // @85_5c0fc0
  if (FL[2] == 0) goto L5c1175;  // @86_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @87_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @89_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6967104), (u32)(0), (u32)(7027316), (u32)(291), (u32)(0), (u32)(0));  // @91_5c0fc0
  ecx = edx = 0;  // @92_5c0fc0
  eax = (eax & 0xffff);  // @93_5c0fc0
  ecx = edi;  // @94_5c0fc0
  PV[3] = (u32)(eax);  // @95_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[3]);  // @96_5c0fc0
  ecx = edx = 0;  // @97_5c0fc0
  L5c1175:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_5c0fc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7005), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @100_5c0fc0
  if (FL[0] != FL[1]) goto L5c120a;  // @101_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @102_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @104_5c0fc0
  ecx = edx = 0;  // @105_5c0fc0
  ecx = (u32)(EBP - 24);  // @106_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @107_5c0fc0
  { u32 v = (u32)((u32)(6791608)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @108_5c0fc0
  eax = ext_48aad0_thiscall1(ecx);  // @109_5c0fc0
  ecx = edx = 0;  // @110_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @111_5c0fc0
  edi = eax;  // @112_5c0fc0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 264), sizeof v); (u32)v; });  // @113_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @114_5c0fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[4]);  // @116_5c0fc0
  ecx = edx = 0;  // @117_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @118_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @119_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @120_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @121_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @122_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @123_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @124_5c0fc0
  eax = (u32)(EBP - 12);  // @125_5c0fc0
  PV[5] = (u32)(eax);  // @126_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7008536), (u32)(0), (u32)(7027316), (u32)(306), PV[5]);  // @128_5c0fc0
  ecx = edx = 0;  // @129_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @130_5c0fc0
  eax = (eax & 0xffff);  // @131_5c0fc0
  PV[6] = (u32)(eax);  // @132_5c0fc0
  PV[7] = (u32)(edi);  // @133_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, PV[7], PV[6]);  // @134_5c0fc0
  ecx = edx = 0;  // @135_5c0fc0
  goto L5c161d;  // @136_5c0fc0
  L5c120a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @138_5c0fc0
  eax = ext_589c20_thiscall2(ecx, (u32)(0));  // @139_5c0fc0
    // @140_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @141_5c0fc0
  FL[2] = (ecx & ecx);  // @142_5c0fc0
  if (FL[2] == 0) goto L5c1264;  // @143_5c0fc0
  eax = ext_610100_stdcall1((u32)(1));  // @144_5c0fc0
    // @145_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @146_5c0fc0
  edx = (u32)(EBP - 16);  // @147_5c0fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @148_5c0fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @149_5c0fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @150_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_5c0fc0
  PV[8] = (u32)(edx);  // @152_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[8]);  // @153_5c0fc0
  ecx = edx = 0;  // @154_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 264), sizeof v); (u32)v; });  // @155_5c0fc0
  eax = (u32)(EBP - 16);  // @156_5c0fc0
  PV[9] = (u32)(eax);  // @157_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @158_5c0fc0
  eax = ext_596940_thiscall5(ecx, (u32)(2), PV[9], (u32)(1), (u32)(-1));  // @159_5c0fc0
  ecx = edx = 0;  // @160_5c0fc0
  L5c1264:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @162_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @163_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @165_5c0fc0
  ecx = edx = 0;  // @166_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @167_5c0fc0
  ecx = (u32)(EBP - 12);  // @168_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_5c0fc0
  { u32 v = (u32)((u32)(6970440)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @170_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @171_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @172_5c0fc0
  eax = ext_48aad0_thiscall1(ecx);  // @173_5c0fc0
  ecx = edx = 0;  // @174_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @175_5c0fc0
  PV[10] = (u32)(eax);  // @176_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @177_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[10]);  // @178_5c0fc0
  ecx = edx = 0;  // @179_5c0fc0
  edi = eax;  // @180_5c0fc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @181_5c0fc0
  FL[2] = (edi & edi);  // @182_5c0fc0
  if (FL[2] == 0) goto L5c161d;  // @183_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @184_5c0fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @185_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(7027316), (u32)(329));  // @186_5c0fc0
  ecx = edx = 0;  // @187_5c0fc0
  esi = (u32)(ebx + 112);  // @188_5c0fc0
  PV[11] = (u32)(esi);  // @189_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @190_5c0fc0
  PV[12] = (u32)(eax);  // @191_5c0fc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[12], (u32)(7027712), PV[11]);  // @192_5c0fc0
  ecx = edx = 0;  // @193_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_5c0fc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @195_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @196_5c0fc0
  PV[13] = (u32)(esi);  // @197_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @198_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6970456), (u32)(0), (u32)(7027316), (u32)(330), PV[13], (u32)(0));  // @199_5c0fc0
  ecx = edx = 0;  // @200_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @201_5c0fc0
  eax = (eax & 0xffff);  // @202_5c0fc0
  PV[14] = (u32)(eax);  // @203_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 296)))(ecx, PV[14]);  // @204_5c0fc0
  ecx = edx = 0;  // @205_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 264), sizeof v); (u32)v; });  // @206_5c0fc0
  FL[2] = (eax & eax);  // @207_5c0fc0
  if (FL[2] == 0) goto L5c1514;  // @208_5c0fc0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @209_5c0fc0
  if (FL[0] != FL[1]) goto L5c1514;  // @210_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @211_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11285), sizeof v); (u32)v; });  // @212_5c0fc0
  eax = ext_59be70_thiscall1(ecx);  // @213_5c0fc0
  ecx = edx = 0;  // @214_5c0fc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @215_5c0fc0
  if (FL[2] == 0) goto L5c1514;  // @216_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @217_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11285), sizeof v); (u32)v; });  // @218_5c0fc0
  eax = (u32)(esi + 72);  // @219_5c0fc0
  PV[15] = (u32)(eax);  // @220_5c0fc0
  ecx = (u32)(esi + 1295);  // @221_5c0fc0
  eax = ext_5b0af0_thiscall2(ecx, PV[15]);  // @222_5c0fc0
  ecx = edx = 0;  // @223_5c0fc0
  ecx = esi;  // @224_5c0fc0
  eax = ext_59b710_thiscall1(ecx);  // @225_5c0fc0
  ecx = edx = 0;  // @226_5c0fc0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4164), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @227_5c0fc0
  if (FL[0] != FL[1]) goto L5c1374;  // @228_5c0fc0
  ecx = esi;  // @229_5c0fc0
  eax = ext_59c420_thiscall1(ecx);  // @230_5c0fc0
  ecx = edx = 0;  // @231_5c0fc0
  L5c1374:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @234_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @236_5c0fc0
  ecx = edx = 0;  // @237_5c0fc0
  ecx = (u32)(EBP - 12);  // @238_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @239_5c0fc0
  { u32 v = (u32)((u32)(6981356)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @240_5c0fc0
  eax = ext_48aad0_thiscall1(ecx);  // @241_5c0fc0
  ecx = edx = 0;  // @242_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @243_5c0fc0
  edi = eax;  // @244_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @245_5c0fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 308)))(ecx);  // @247_5c0fc0
  ecx = edx = 0;  // @248_5c0fc0
  ecx = (u32)(EBP - 12);  // @249_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @250_5c0fc0
  { u32 v = (u32)((u32)(6976892)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @251_5c0fc0
  eax = ext_58b6a0_thiscall1(ecx);  // @252_5c0fc0
  ecx = edx = 0;  // @253_5c0fc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @254_5c0fc0
  if (FL[2] != 0) goto L5c13ee;  // @255_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @256_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @257_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @259_5c0fc0
  ecx = edx = 0;  // @260_5c0fc0
  ecx = (u32)(EBP - 12);  // @261_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @262_5c0fc0
  { u32 v = (u32)((u32)(6977388)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @263_5c0fc0
  eax = ext_58b6a0_thiscall1(ecx);  // @264_5c0fc0
  ecx = edx = 0;  // @265_5c0fc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @266_5c0fc0
  if (FL[2] == 0) goto L5c1415;  // @267_5c0fc0
  L5c13ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @269_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @270_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @271_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @272_5c0fc0
  ecx = edx = 0;  // @273_5c0fc0
  ecx = (u32)(EBP - 12);  // @274_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @275_5c0fc0
  { u32 v = (u32)((u32)(7027736)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @276_5c0fc0
  eax = ext_48aad0_thiscall1(ecx);  // @277_5c0fc0
  ecx = edx = 0;  // @278_5c0fc0
  edi = eax;  // @279_5c0fc0
  L5c1415:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @281_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @282_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @283_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @284_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @285_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6973080), (u32)(0), (u32)(7027316), (u32)(347), (u32)(0));  // @286_5c0fc0
  ecx = edx = 0;  // @287_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @288_5c0fc0
  eax = (eax & 0xffff);  // @289_5c0fc0
  PV[16] = (u32)(eax);  // @290_5c0fc0
  PV[17] = (u32)(edi);  // @291_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, PV[17], PV[16]);  // @292_5c0fc0
  ecx = edx = 0;  // @293_5c0fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338592) + 0), 4); v; });  // @294_5c0fc0
  X0[1] = 0;  // @295_5c0fc0
  X0[2] = 0;  // @296_5c0fc0
  X0[3] = 0;  // @297_5c0fc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @298_5c0fc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @299_5c0fc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @300_5c0fc0
  if (__builtin_parity(FL[2] & 0xff)) goto L5c1489;  // @301_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @302_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @303_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @304_5c0fc0
  ecx = edx = 0;  // @305_5c0fc0
  ecx = eax;  // @306_5c0fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @307_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 100)))(ecx, (u32)(6977492), (u32)(1));  // @308_5c0fc0
  ecx = edx = 0;  // @309_5c0fc0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(7338592), &v, sizeof v); }  // @310_5c0fc0
  L5c1489:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @312_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @313_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @314_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @315_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @316_5c0fc0
  ecx = edx = 0;  // @317_5c0fc0
  ecx = eax;  // @318_5c0fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @319_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 256)))(ecx, (u32)(6882344));  // @320_5c0fc0
  ecx = edx = 0;  // @321_5c0fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7340836) + 0), 4); v; });  // @322_5c0fc0
  X0[1] = 0;  // @323_5c0fc0
  X0[2] = 0;  // @324_5c0fc0
  X0[3] = 0;  // @325_5c0fc0
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }));  // @326_5c0fc0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @327_5c0fc0
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @328_5c0fc0
  if (__builtin_parity(FL[2] & 0xff)) goto L5c14f3;  // @329_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @330_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @331_5c0fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @332_5c0fc0
  ecx = edx = 0;  // @333_5c0fc0
  ecx = eax;  // @334_5c0fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @335_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 100)))(ecx, (u32)(6977512), (u32)(1));  // @336_5c0fc0
  ecx = edx = 0;  // @337_5c0fc0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(7340836), &v, sizeof v); }  // @338_5c0fc0
  L5c14f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @340_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @341_5c0fc0
  FL[2] = (ecx & ecx);  // @342_5c0fc0
  if (FL[2] == 0) goto L5c1514;  // @343_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @344_5c0fc0
  PV[18] = (u32)(ecx);  // @345_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(5), (u32)(1082130432));  // @346_5c0fc0
  ecx = edx = 0;  // @347_5c0fc0
  L5c1514:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @349_5c0fc0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @350_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @351_5c0fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @352_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @353_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6967128), (u32)(0), (u32)(7027316), (u32)(378), (u32)(0), (u32)(0));  // @354_5c0fc0
  ecx = edx = 0;  // @355_5c0fc0
  eax = (eax & 0xffff);  // @356_5c0fc0
  ecx = ebx;  // @357_5c0fc0
  PV[19] = (u32)(eax);  // @358_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[19]);  // @359_5c0fc0
  ecx = edx = 0;  // @360_5c0fc0
  goto L5c161d;  // @361_5c0fc0
  L5c1552:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422752), sizeof v); (u32)v; });  // @363_5c0fc0
  if (FL[0] != FL[1]) goto L5c15bc;  // @364_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @365_5c0fc0
  PV[20] = (u32)(edi);  // @366_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @367_5c0fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @368_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[20]);  // @369_5c0fc0
  ecx = edx = 0;  // @370_5c0fc0
  esi = eax;  // @371_5c0fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @372_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @373_5c0fc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @374_5c0fc0
  FL[2] = (ecx & ecx);  // @375_5c0fc0
  if (FL[2] == 0) goto L5c15a8;  // @376_5c0fc0
  L5c1582:;
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2099193));  // @378_5c0fc0
  ecx = 0;  // @379_5c0fc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @380_5c0fc0
  if (FL[2] == 0) goto L5c1596;  // @381_5c0fc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @382_5c0fc0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; });  // @383_5c0fc0
  L5c1596:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @385_5c0fc0
  ecx = (u32)(EBP - 20);  // @386_5c0fc0
  PV[21] = (u32)(ecx);  // @387_5c0fc0
  ecx = esi;  // @388_5c0fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[21]);  // @389_5c0fc0
  ecx = edx = 0;  // @390_5c0fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @391_5c0fc0
  FL[2] = (ecx & ecx);  // @392_5c0fc0
  if (FL[2] != 0) goto L5c1582;  // @393_5c0fc0
  L5c15a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; });  // @395_5c0fc0
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @396_5c0fc0
  eax = (eax - edx);  // @397_5c0fc0
  FL[3] = eax;  // @398_5c0fc0
  eax = (u32)((s32)eax >> (u32)(1));  // @399_5c0fc0
  FL[3] = eax;  // @400_5c0fc0
  eax = (eax + 1);  // @401_5c0fc0
  FL[3] = eax;  // @402_5c0fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @403_5c0fc0
  goto L5c161d;  // @404_5c0fc0
  L5c15bc:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422748), sizeof v); (u32)v; });  // @406_5c0fc0
  if (FL[0] != FL[1]) goto L5c160c;  // @407_5c0fc0
  ecx = 0;  // @408_5c0fc0
  FL[3] = ecx;  // @409_5c0fc0
  eax = (u32)(ebx + 144);  // @410_5c0fc0
  L5c15d0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @412_5c0fc0
  FL[0] = edx; FL[1] = edi;  // @413_5c0fc0
  if (FL[0] == FL[1]) goto L5c15ec;  // @414_5c0fc0
  FL[2] = (edx & edx);  // @415_5c0fc0
  if (FL[2] == 0) goto L5c15e5;  // @416_5c0fc0
  ecx = (ecx + 1);  // @417_5c0fc0
  FL[3] = ecx;  // @418_5c0fc0
  eax = (eax + (u32)(8));  // @419_5c0fc0
  FL[3] = eax;  // @420_5c0fc0
  FL[0] = ecx; FL[1] = (u32)(10);  // @421_5c0fc0
  if (FL[0] < FL[1]) goto L5c15d0;  // @422_5c0fc0
  goto L5c161d;  // @423_5c0fc0
  L5c15e5:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + ecx*8 + 144), &v, sizeof v); }  // @425_5c0fc0
  L5c15ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @427_5c0fc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @428_5c0fc0
  X0[0] = F2U((float)(s32)X0[0]);  // @429_5c0fc0
  X0[1] = F2U((float)(s32)X0[1]);  // @430_5c0fc0
  X0[2] = F2U((float)(s32)X0[2]);  // @431_5c0fc0
  X0[3] = F2U((float)(s32)X0[3]);  // @432_5c0fc0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @433_5c0fc0
  __builtin_memcpy((void *)((u32)(ebx + ecx*8 + 148) + 0), &X0[0], 4);  // @434_5c0fc0
  goto L5c161d;  // @435_5c0fc0
  L5c160c:;
  FL[0] = (esi & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422756), sizeof v); (u32)v; });  // @437_5c0fc0
  if (FL[0] != FL[1]) goto L5c161d;  // @438_5c0fc0
  PV[22] = (u32)(edi);  // @439_5c0fc0
  PT = PV[22];
  L5c1616:;
  ecx = ebx;  // @441_5c0fc0
  eax = ext_5c21e0_thiscall2(ecx, PT);  // @442_5c0fc0   (w3g hand fix: the pushed argument depends on the path; PV[22] was uninitialised on the jumped path = UB, clang deleted the branch)
  ecx = edx = 0;  // @443_5c0fc0
  L5c161d:;
  ext_633654(G(u32, 0x6f5630));  // @445_5c0fc0
  eax = 0;  // @446_5c0fc0
  FL[3] = eax;  // @447_5c0fc0
  return eax;  // @448_5c0fc0
}
PCREG(5c0fc0, lifted_5c0fc0);

