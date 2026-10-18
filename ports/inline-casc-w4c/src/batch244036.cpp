// batch244036.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4e0830_fastcall2(u32, u32) __asm__("ext_4e0830");
extern "C" u32 FASTCALL ext_4f9350_fastcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4f9350");
extern "C" u32 FASTCALL ext_53bec0_fastcall2(u32, u32) __asm__("ext_53bec0");
extern "C" u32 THISCALL ext_4dffb0_thiscall2(u32, u32) __asm__("ext_4dffb0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_661c10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @2_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @4_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @5_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_661c10
  edx = eax;  // @7_661c10
  ecx = eax;  // @8_661c10
  edx = (edx >> (u32)(16));  // @9_661c10
  FL[3] = edx;  // @10_661c10
  ecx = (ecx >> (u32)(31));  // @11_661c10
  FL[3] = ecx;  // @12_661c10
  edx = (edx & (u32)(32767));  // @13_661c10
  FL[3] = edx;  // @14_661c10
  ecx = (ecx & (u32)(4294967041));  // @15_661c10
  FL[3] = ecx;  // @16_661c10
  eax = (eax & 0xffff);  // @17_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @18_661c10
  eax = (eax + edx);  // @19_661c10
  FL[3] = eax;  // @20_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @22_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @23_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @24_661c10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @26_661c10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @27_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @28_661c10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @29_661c10
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @30_661c10
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 44), sizeof v); (u32)v; }) & ecx);  // @31_661c10
  if (FL[2] == 0) goto L661f3e;  // @32_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 20), sizeof v); (u32)v; });  // @33_661c10
  esi = (esi + (u32)(24));  // @34_661c10
  FL[3] = esi;  // @35_661c10
  ecx = (ecx + edi);  // @36_661c10
  FL[3] = ecx;  // @37_661c10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @38_661c10
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @39_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @40_661c10
  if (FL[0] == FL[1]) goto L661c98;  // @41_661c10
  edx = (edx - 1);  // @42_661c10
  FL[3] = edx;  // @43_661c10
  L661c98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 60), sizeof v); (u32)v; });  // @45_661c10
  edi = (u32)(eax + edx*2);  // @46_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @47_661c10
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }));  // @48_661c10
  FL[3] = edi;  // @49_661c10
  eax = (eax - edx);  // @50_661c10
  FL[3] = eax;  // @51_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @52_661c10
  FL[0] = eax; FL[1] = (u32)(17);  // @53_661c10
  if (FL[0] <= FL[1]) goto L661cc4;  // @54_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @55_661c10
  FL[2] = (ecx & ecx);  // @56_661c10
  if (FL[2] == 0) goto L661cc0;  // @57_661c10
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @58_661c10
  ecx = edx = 0;  // @59_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @60_661c10
  goto L661cc1;  // @61_661c10
  L661cc0:;
  __builtin_trap();  // @63_661c10
  L661cc1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @65_661c10
  L661cc4:;
  edx = 0;  // @67_661c10
  FL[3] = edx;  // @68_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @69_661c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @70_661c10
  FL[2] = (eax & eax);  // @71_661c10
  if (FL[2] == 0) goto L661f52;  // @72_661c10
  L661cd4:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_661c10
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @75_661c10
  eax = (u32)(eax + eax*8);  // @76_661c10
  edx = (u32)(ecx + eax*4);  // @77_661c10
  ecx = esi;  // @78_661c10
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @79_661c10
  ecx = edx = 0;  // @80_661c10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @81_661c10
  ecx = esi;  // @82_661c10
  eax = ext_441a60_fastcall2(ecx, edx);  // @83_661c10
  ecx = edx = 0;  // @84_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @85_661c10
  edx = 0;  // @86_661c10
  FL[3] = edx;  // @87_661c10
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @88_661c10
  X2[1] = 0;  // @89_661c10
  X2[2] = 0;  // @90_661c10
  X2[3] = 0;  // @91_661c10
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @92_661c10
  X1[1] = 0;  // @93_661c10
  X1[2] = 0;  // @94_661c10
  X1[3] = 0;  // @95_661c10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @96_661c10
  X0[1] = 0;  // @97_661c10
  X0[2] = 0;  // @98_661c10
  X0[3] = 0;  // @99_661c10
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L661d12;  // @100_661c10
  edx = (u32)(1);  // @101_661c10
  goto L661d20;  // @102_661c10
  L661d12:;
  X0[0] = X0[0] ^ X1[0];  // @104_661c10
  X0[1] = X0[1] ^ X1[1];  // @105_661c10
  X0[2] = X0[2] ^ X1[2];  // @106_661c10
  X0[3] = X0[3] ^ X1[3];  // @107_661c10
  ecx = (u32)(2);  // @108_661c10
  if ((!(!(U2F(X0[0]) >= U2F(X2[0]))) && !(!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) edx = ecx;  // @109_661c10
  L661d20:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @111_661c10
  X2[1] = 0;  // @112_661c10
  X2[2] = 0;  // @113_661c10
  X2[3] = 0;  // @114_661c10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @115_661c10
  X0[1] = 0;  // @116_661c10
  X0[2] = 0;  // @117_661c10
  X0[3] = 0;  // @118_661c10
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L661d34;  // @119_661c10
  edx = (edx | (u32)(4));  // @120_661c10
  FL[3] = edx;  // @121_661c10
  goto L661d3f;  // @122_661c10
  L661d34:;
  X0[0] = X0[0] ^ X1[0];  // @124_661c10
  X0[1] = X0[1] ^ X1[1];  // @125_661c10
  X0[2] = X0[2] ^ X1[2];  // @126_661c10
  X0[3] = X0[3] ^ X1[3];  // @127_661c10
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L661d3f;  // @128_661c10
  edx = (edx | (u32)(8));  // @129_661c10
  FL[3] = edx;  // @130_661c10
  L661d3f:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @132_661c10
  X2[1] = 0;  // @133_661c10
  X2[2] = 0;  // @134_661c10
  X2[3] = 0;  // @135_661c10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @136_661c10
  X0[1] = 0;  // @137_661c10
  X0[2] = 0;  // @138_661c10
  X0[3] = 0;  // @139_661c10
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L661d53;  // @140_661c10
  edx = (edx | (u32)(16));  // @141_661c10
  FL[3] = edx;  // @142_661c10
  goto L661d5e;  // @143_661c10
  L661d53:;
  X0[0] = X0[0] ^ X1[0];  // @145_661c10
  X0[1] = X0[1] ^ X1[1];  // @146_661c10
  X0[2] = X0[2] ^ X1[2];  // @147_661c10
  X0[3] = X0[3] ^ X1[3];  // @148_661c10
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L661d5e;  // @149_661c10
  edx = (edx | (u32)(32));  // @150_661c10
  FL[3] = edx;  // @151_661c10
  L661d5e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @153_661c10
  esi = (esi + (u32)(12));  // @154_661c10
  FL[3] = esi;  // @155_661c10
  edi = (edi + (u32)(2));  // @156_661c10
  FL[3] = edi;  // @157_661c10
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + eax - 36), &v, sizeof v); }  // @158_661c10
  FL[0] = eax; FL[1] = (u32)(2);  // @159_661c10
  if ((s32)FL[0] < (s32)FL[1]) goto L661d83;  // @160_661c10
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax - 38), sizeof v); (u32)v; });  // @161_661c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax - 37), sizeof v); (u32)v; });  // @162_661c10
  ecx = (ecx & eax);  // @163_661c10
  FL[3] = ecx;  // @164_661c10
  FL[2] = ((edx & 0xff) & (ecx & 0xff));  // @165_661c10
  if (FL[2] == 0) goto L661d98;  // @166_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @167_661c10
  L661d83:;
  eax = (eax + 1);  // @169_661c10
  FL[3] = eax;  // @170_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @171_661c10
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @172_661c10
  if (FL[0] == FL[1]) goto L661f52;  // @173_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @174_661c10
  goto L661cd4;  // @175_661c10
  L661d98:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @177_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @178_661c10
  FL[0] = edx; FL[1] = ecx;  // @179_661c10
  if (FL[0] == FL[1]) goto L661f52;  // @180_661c10
  FL[0] = edx; FL[1] = (u32)(3);  // @181_661c10
  if ((s32)FL[0] <= (s32)FL[1]) goto L661e14;  // @182_661c10
  eax = (u32)(2);  // @183_661c10
  eax = (eax - edx);  // @184_661c10
  FL[3] = eax;  // @185_661c10
  ecx = (ecx + eax);  // @186_661c10
  FL[3] = ecx;  // @187_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @188_661c10
  FL[2] = ((edx & 0xff) & (u32)(1));  // @189_661c10
  if (FL[2] == 0) goto L661dd9;  // @190_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 36), sizeof v); (u32)v; });  // @191_661c10
  ecx = (ecx + 1);  // @192_661c10
  FL[3] = ecx;  // @193_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @194_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @195_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @196_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 32), sizeof v); (u32)v; });  // @197_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @198_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 28), sizeof v); (u32)v; });  // @199_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @200_661c10
  ecx = (ecx + (u32)(12));  // @201_661c10
  FL[3] = ecx;  // @202_661c10
  goto L661ddc;  // @203_661c10
  L661dd9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @205_661c10
  L661ddc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 36), sizeof v); (u32)v; });  // @207_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @208_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 32), sizeof v); (u32)v; });  // @209_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @210_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 28), sizeof v); (u32)v; });  // @211_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @212_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 24), sizeof v); (u32)v; });  // @213_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @214_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 20), sizeof v); (u32)v; });  // @215_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @216_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 16), sizeof v); (u32)v; });  // @217_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @218_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 12), sizeof v); (u32)v; });  // @219_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @220_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 8), sizeof v); (u32)v; });  // @221_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @222_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @223_661c10
  esi = (u32)(ecx + 36);  // @224_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @225_661c10
  L661e14:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @227_661c10
  edx = (edx + 1);  // @228_661c10
  FL[3] = edx;  // @229_661c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @230_661c10
  eax = (u32)(edx - 3);  // @231_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @232_661c10
  FL[2] = ((edx & 0xff) & (u32)(1));  // @233_661c10
  if (FL[2] != 0) goto L661e2a;  // @234_661c10
  eax = (eax - 1);  // @235_661c10
  FL[3] = eax;  // @236_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @237_661c10
  L661e2a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @239_661c10
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @240_661c10
  if (FL[0] == FL[1]) goto L661f28;  // @241_661c10
  eax = (u32)(EBP - 36);  // @242_661c10
  eax = (eax - (u32)(2));  // @243_661c10
  FL[3] = eax;  // @244_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @245_661c10
  L661e43:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @247_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @248_661c10
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @249_661c10
  eax = (u32)(eax + eax*8);  // @250_661c10
  edx = (u32)(ecx + eax*4);  // @251_661c10
  ecx = esi;  // @252_661c10
  eax = ext_43e920_fastcall3(ecx, edx, PV[1]);  // @253_661c10
  ecx = edx = 0;  // @254_661c10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @255_661c10
  ecx = esi;  // @256_661c10
  eax = ext_441a60_fastcall2(ecx, edx);  // @257_661c10
  ecx = edx = 0;  // @258_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @259_661c10
  edx = 0;  // @260_661c10
  FL[3] = edx;  // @261_661c10
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @262_661c10
  X2[1] = 0;  // @263_661c10
  X2[2] = 0;  // @264_661c10
  X2[3] = 0;  // @265_661c10
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @266_661c10
  X1[1] = 0;  // @267_661c10
  X1[2] = 0;  // @268_661c10
  X1[3] = 0;  // @269_661c10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @270_661c10
  X0[1] = 0;  // @271_661c10
  X0[2] = 0;  // @272_661c10
  X0[3] = 0;  // @273_661c10
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L661e84;  // @274_661c10
  edx = (u32)(1);  // @275_661c10
  goto L661e92;  // @276_661c10
  L661e84:;
  X0[0] = X0[0] ^ X1[0];  // @278_661c10
  X0[1] = X0[1] ^ X1[1];  // @279_661c10
  X0[2] = X0[2] ^ X1[2];  // @280_661c10
  X0[3] = X0[3] ^ X1[3];  // @281_661c10
  ecx = (u32)(2);  // @282_661c10
  if ((!(!(U2F(X0[0]) >= U2F(X2[0]))) && !(!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) edx = ecx;  // @283_661c10
  L661e92:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @285_661c10
  X2[1] = 0;  // @286_661c10
  X2[2] = 0;  // @287_661c10
  X2[3] = 0;  // @288_661c10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @289_661c10
  X0[1] = 0;  // @290_661c10
  X0[2] = 0;  // @291_661c10
  X0[3] = 0;  // @292_661c10
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L661ea6;  // @293_661c10
  edx = (edx | (u32)(4));  // @294_661c10
  FL[3] = edx;  // @295_661c10
  goto L661eb1;  // @296_661c10
  L661ea6:;
  X0[0] = X0[0] ^ X1[0];  // @298_661c10
  X0[1] = X0[1] ^ X1[1];  // @299_661c10
  X0[2] = X0[2] ^ X1[2];  // @300_661c10
  X0[3] = X0[3] ^ X1[3];  // @301_661c10
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L661eb1;  // @302_661c10
  edx = (edx | (u32)(8));  // @303_661c10
  FL[3] = edx;  // @304_661c10
  L661eb1:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @306_661c10
  X2[1] = 0;  // @307_661c10
  X2[2] = 0;  // @308_661c10
  X2[3] = 0;  // @309_661c10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @310_661c10
  X0[1] = 0;  // @311_661c10
  X0[2] = 0;  // @312_661c10
  X0[3] = 0;  // @313_661c10
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L661ec5;  // @314_661c10
  edx = (edx | (u32)(16));  // @315_661c10
  FL[3] = edx;  // @316_661c10
  goto L661ed0;  // @317_661c10
  L661ec5:;
  X0[0] = X0[0] ^ X1[0];  // @319_661c10
  X0[1] = X0[1] ^ X1[1];  // @320_661c10
  X0[2] = X0[2] ^ X1[2];  // @321_661c10
  X0[3] = X0[3] ^ X1[3];  // @322_661c10
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L661ed0;  // @323_661c10
  edx = (edx | (u32)(32));  // @324_661c10
  FL[3] = edx;  // @325_661c10
  L661ed0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @327_661c10
  edi = (edi + (u32)(2));  // @328_661c10
  FL[3] = edi;  // @329_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @330_661c10
  esi = (esi + (u32)(12));  // @331_661c10
  FL[3] = esi;  // @332_661c10
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @333_661c10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @334_661c10
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(ecx + eax + 2), &v, sizeof v); }  // @335_661c10
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax + 1), sizeof v); (u32)v; });  // @336_661c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax), sizeof v); (u32)v; });  // @337_661c10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @338_661c10
  ecx = (ecx & eax);  // @339_661c10
  FL[3] = ecx;  // @340_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @341_661c10
  ecx = (ecx & edx);  // @342_661c10
  FL[3] = ecx;  // @343_661c10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @344_661c10
  eax = (eax + 1);  // @345_661c10
  FL[3] = eax;  // @346_661c10
  edx = (edx + 1);  // @347_661c10
  FL[3] = edx;  // @348_661c10
  FL[1] = ecx;  // @349_661c10
  ecx = (0u - ecx);  // @350_661c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @351_661c10
  ecx = (0u - (u32)(FL[1] != 0));  // @352_661c10
  eax = (eax & ecx);  // @353_661c10
  FL[3] = eax;  // @354_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @355_661c10
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @356_661c10
  if (FL[0] != FL[1]) goto L661e43;  // @357_661c10
  FL[2] = (eax & eax);  // @358_661c10
  if (FL[2] == 0) goto L661f28;  // @359_661c10
  ecx = (u32)(eax*4);  // @360_661c10
  ecx = (ecx - eax);  // @361_661c10
  FL[3] = ecx;  // @362_661c10
  FL[1] = ecx;  // @363_661c10
  ecx = (0u - ecx);  // @364_661c10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @365_661c10
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @366_661c10
  esi = (u32)(esi + ecx*4);  // @367_661c10
  L661f28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @369_661c10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @370_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @371_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @372_661c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @373_661c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @374_661c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @375_661c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @376_661c10
  L661f3e:;
  eax = esi;  // @378_661c10
  ext_633654(G(u32, 0x6f5630));  // @379_661c10
  return eax;  // @380_661c10
  L661f52:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @382_661c10
  ext_633654(G(u32, 0x6f5630));  // @383_661c10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @384_661c10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @385_661c10
  return eax;  // @386_661c10
}
PCREG(661c10, lifted_661c10);

extern "C" u32 THISCALL lifted_4f5300(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 560)))(ecx);  // @2_4f5300
  ecx = edx = 0;  // @3_4f5300
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(edi + 46), &v, sizeof v); }  // @4_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @6_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @7_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4f5300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(9));  // @9_4f5300
  ecx = edx = 0;  // @10_4f5300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 42), &v, sizeof v); }  // @11_4f5300
  ecx = edi;  // @12_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 580)))(ecx);  // @14_4f5300
  ecx = edx = 0;  // @15_4f5300
  edx = (u32)(edi + 147);  // @16_4f5300
  esi = 0;  // @17_4f5300
  FL[3] = esi;  // @18_4f5300
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @19_4f5300
  L4f5360:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4f5300
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @22_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4f5300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @25_4f5300
  ecx = edx = 0;  // @26_4f5300
  ebx = eax;  // @27_4f5300
  ecx = ebx;  // @28_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @30_4f5300
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097222));  // @31_4f5300
  ecx = edx = 0;  // @32_4f5300
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @33_4f5300
  if (FL[2] == 0) goto L4f5397;  // @34_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @35_4f5300
  ecx = ebx;  // @36_4f5300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 596)))(ecx, (u32)(0));  // @37_4f5300
  ecx = edx = 0;  // @38_4f5300
  goto L4f53b9;  // @39_4f5300
  L4f5397:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @41_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @42_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4f5300
  PV[1] = (u32)(edx);  // @44_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @45_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @46_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4f5300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 228)))(ecx, PV[1], (u32)(6786308));  // @48_4f5300
  ecx = edx = 0;  // @49_4f5300
  L4f53b9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @51_4f5300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + esi*8 - 220), &v, sizeof v); }  // @52_4f5300
  edx = (edx + (u32)(4));  // @53_4f5300
  FL[3] = edx;  // @54_4f5300
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + esi*8 - 216), &v, sizeof v); }  // @55_4f5300
  esi = (esi + 1);  // @56_4f5300
  FL[3] = esi;  // @57_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @58_4f5300
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @59_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @60_4f5300
  X0[1] = 0;  // @61_4f5300
  X0[2] = 0;  // @62_4f5300
  X0[3] = 0;  // @63_4f5300
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @64_4f5300
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @65_4f5300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 183), &v, sizeof v); }  // @66_4f5300
  FL[0] = esi; FL[1] = (u32)(9);  // @67_4f5300
  if ((s32)FL[0] < (s32)FL[1]) goto L4f5360;  // @68_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_4f5300
  ecx = edi;  // @70_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @71_4f5300
  ecx = edx = 0;  // @72_4f5300
  FL[2] = (eax & eax);  // @73_4f5300
  if (FL[2] == 0) goto L4f5432;  // @74_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_4f5300
  ecx = edi;  // @76_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @77_4f5300
  ecx = edx = 0;  // @78_4f5300
  ecx = eax;  // @79_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @80_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @81_4f5300
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048622));  // @82_4f5300
  ecx = edx = 0;  // @83_4f5300
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @84_4f5300
  if (FL[2] == 0) goto L4f5432;  // @85_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @86_4f5300
  ecx = edi;  // @87_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @88_4f5300
  ecx = edx = 0;  // @89_4f5300
  ecx = eax;  // @90_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 708)))(ecx);  // @92_4f5300
  ecx = edx = 0;  // @93_4f5300
  FL[2] = (eax & eax);  // @94_4f5300
  if (FL[2] != 0) goto L4f547b;  // @95_4f5300
  L4f5432:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @98_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @100_4f5300
  ecx = edx = 0;  // @101_4f5300
  ecx = (u32)(EBP - 224);  // @102_4f5300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @103_4f5300
  PV[2] = (u32)(ecx);  // @104_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @105_4f5300
  ecx = eax;  // @106_4f5300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6918004), PV[2]);  // @107_4f5300
  ecx = edx = 0;  // @108_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_4f5300
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @110_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @111_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4f5300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @113_4f5300
  ecx = edx = 0;  // @114_4f5300
  L4f547b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 187), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @116_4f5300
  X0[0] = F2U((float)(s32)X0[0]);  // @117_4f5300
  X0[1] = F2U((float)(s32)X0[1]);  // @118_4f5300
  X0[2] = F2U((float)(s32)X0[2]);  // @119_4f5300
  X0[3] = F2U((float)(s32)X0[3]);  // @120_4f5300
  PV[4] = (u32)(ecx);  // @121_4f5300
  ecx = (u32)(EBP - 232);  // @122_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 155) + 0), 4); v; })));  // @123_4f5300
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); esi = (u32)r_; }  // @124_4f5300
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @125_4f5300
  X0[0] = F2U((float)(s32)X0[0]);  // @126_4f5300
  X0[1] = F2U((float)(s32)X0[1]);  // @127_4f5300
  X0[2] = F2U((float)(s32)X0[2]);  // @128_4f5300
  X0[3] = F2U((float)(s32)X0[3]);  // @129_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 232) + 0), &X0[0], 4);  // @130_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 191), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @131_4f5300
  X0[0] = F2U((float)(s32)X0[0]);  // @132_4f5300
  X0[1] = F2U((float)(s32)X0[1]);  // @133_4f5300
  X0[2] = F2U((float)(s32)X0[2]);  // @134_4f5300
  X0[3] = F2U((float)(s32)X0[3]);  // @135_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 228) + 0), &X0[0], 4);  // @136_4f5300
  eax = ext_4dffb0_thiscall2(ecx, (u32)(1056964608));  // @137_4f5300
    // @138_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 183), sizeof v); (u32)v; });  // @139_4f5300
  esi = (esi & (u32)(1));  // @140_4f5300
  FL[3] = esi;  // @141_4f5300
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @142_4f5300
  X4[1] = 0;  // @143_4f5300
  X4[2] = 0;  // @144_4f5300
  X4[3] = 0;  // @145_4f5300
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @146_4f5300
  X7[1] = 0;  // @147_4f5300
  X7[2] = 0;  // @148_4f5300
  X7[3] = 0;  // @149_4f5300
  { u32 v = (u32)((u32)(1073741824)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @150_4f5300
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @151_4f5300
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @152_4f5300
  eax = (eax >> (u32)(31));  // @153_4f5300
  FL[3] = eax;  // @154_4f5300
  { u32 v = (u32)((u32)(1073741824)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @155_4f5300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @156_4f5300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @157_4f5300
  X6[0] = esi; X6[1] = X6[2] = X6[3] = 0;  // @158_4f5300
  esi = 0;  // @159_4f5300
  FL[3] = esi;  // @160_4f5300
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @161_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 191), sizeof v); (u32)v; });  // @162_4f5300
  eax = (eax & (u32)(1));  // @163_4f5300
  FL[3] = eax;  // @164_4f5300
  ebx = 0;  // @165_4f5300
  FL[3] = ebx;  // @166_4f5300
  X6[0] = F2U((float)(s32)X6[0]);  // @167_4f5300
  X6[1] = F2U((float)(s32)X6[1]);  // @168_4f5300
  X6[2] = F2U((float)(s32)X6[2]);  // @169_4f5300
  X6[3] = F2U((float)(s32)X6[3]);  // @170_4f5300
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X3[0] = F2U(a_); X3[1] = F2U(b_); X3[2] = X3[3] = 0; }  // @171_4f5300
  X0[0] = 0;  // @172_4f5300
  X0[1] = 0;  // @173_4f5300
  X0[2] = 0;  // @174_4f5300
  X0[3] = 0;  // @175_4f5300
  X5[0] = eax; X5[1] = X5[2] = X5[3] = 0;  // @176_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @177_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 148) + 4), &X0[1], 4);  // @178_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 148) + 8), &X0[2], 4);  // @179_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 148) + 12), &X0[3], 4);  // @180_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 132) + 0), &X0[0], 4);  // @181_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 132) + 4), &X0[1], 4);  // @182_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 132) + 8), &X0[2], 4);  // @183_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 132) + 12), &X0[3], 4);  // @184_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 0), 4); v; });  // @185_4f5300
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 4), 4); v; });  // @186_4f5300
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 8), 4); v; });  // @187_4f5300
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 12), 4); v; });  // @188_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @189_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 116) + 4), &X0[1], 4);  // @190_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 116) + 8), &X0[2], 4);  // @191_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 116) + 12), &X0[3], 4);  // @192_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 0), 4); v; });  // @193_4f5300
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 4), 4); v; });  // @194_4f5300
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 8), 4); v; });  // @195_4f5300
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922800) + 12), 4); v; });  // @196_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 100) + 0), &X0[0], 4);  // @197_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 100) + 4), &X0[1], 4);  // @198_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 100) + 8), &X0[2], 4);  // @199_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 100) + 12), &X0[3], 4);  // @200_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922784) + 0), 4); v; });  // @201_4f5300
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922784) + 4), 4); v; });  // @202_4f5300
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922784) + 8), 4); v; });  // @203_4f5300
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922784) + 12), 4); v; });  // @204_4f5300
  X5[0] = F2U((float)(s32)X5[0]);  // @205_4f5300
  X5[1] = F2U((float)(s32)X5[1]);  // @206_4f5300
  X5[2] = F2U((float)(s32)X5[2]);  // @207_4f5300
  X5[3] = F2U((float)(s32)X5[3]);  // @208_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @209_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 76) + 4), &X0[1], 4);  // @210_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 76) + 8), &X0[2], 4);  // @211_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 76) + 12), &X0[3], 4);  // @212_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922816) + 0), 4); v; });  // @213_4f5300
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922816) + 4), 4); v; });  // @214_4f5300
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922816) + 8), 4); v; });  // @215_4f5300
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922816) + 12), 4); v; });  // @216_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 60) + 0), &X0[0], 4);  // @217_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 60) + 4), &X0[1], 4);  // @218_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 60) + 8), &X0[2], 4);  // @219_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 60) + 12), &X0[3], 4);  // @220_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922768) + 0), 4); v; });  // @221_4f5300
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922768) + 4), 4); v; });  // @222_4f5300
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922768) + 8), 4); v; });  // @223_4f5300
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922768) + 12), 4); v; });  // @224_4f5300
  X6[0] = F2U(U2F(X6[0]) * U2F(X4[0]));  // @225_4f5300
  X5[0] = F2U(U2F(X5[0]) * U2F(X4[0]));  // @226_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @227_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 44) + 4), &X0[1], 4);  // @228_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 44) + 8), &X0[2], 4);  // @229_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 44) + 12), &X0[3], 4);  // @230_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922752) + 0), 4); v; });  // @231_4f5300
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922752) + 4), 4); v; });  // @232_4f5300
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922752) + 8), 4); v; });  // @233_4f5300
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6922752) + 12), 4); v; });  // @234_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 224) + 0), &X3[0], 4);  // @235_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 240) + 0), &X6[0], 4);  // @236_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 236) + 0), &X5[0], 4);  // @237_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @238_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @239_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 28) + 8), &X0[2], 4);  // @240_4f5300
  __builtin_memcpy((void *)((u32)(EBP - 28) + 12), &X0[3], 4);  // @241_4f5300
  L4f55a2:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + ebx - 76) + 0), 4); v; });  // @243_4f5300
  X1[1] = 0;  // @244_4f5300
  X1[2] = 0;  // @245_4f5300
  X1[3] = 0;  // @246_4f5300
  X2[0] = 0;  // @247_4f5300
  X2[1] = 0;  // @248_4f5300
  X2[2] = 0;  // @249_4f5300
  X2[3] = 0;  // @250_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @251_4f5300
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4f55d1;  // @252_4f5300
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 232) + 0), 4); v; })));  // @253_4f5300
  X0[0] = X3[0];  // @254_4f5300
  X0[1] = X3[1];  // @255_4f5300
  X0[2] = X3[2];  // @256_4f5300
  X0[3] = X3[3];  // @257_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @258_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X6[0]));  // @259_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @260_4f5300
  __builtin_memcpy((void *)((u32)(esi + eax) + 0), &X1[0], 4);  // @261_4f5300
  goto L4f55fb;  // @262_4f5300
  L4f55d1:;
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4f55f4;  // @264_4f5300
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 232) + 0), 4); v; })));  // @265_4f5300
  X0[0] = X3[0];  // @266_4f5300
  X0[1] = X3[1];  // @267_4f5300
  X0[2] = X3[2];  // @268_4f5300
  X0[3] = X3[3];  // @269_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @270_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X6[0]));  // @271_4f5300
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @272_4f5300
  __builtin_memcpy((void *)((u32)(esi + eax) + 0), &X1[0], 4);  // @273_4f5300
  goto L4f55fb;  // @274_4f5300
  L4f55f4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + eax), &v, sizeof v); }  // @276_4f5300
  L4f55fb:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + ebx - 72) + 0), 4); v; });  // @278_4f5300
  X1[1] = 0;  // @279_4f5300
  X1[2] = 0;  // @280_4f5300
  X1[3] = 0;  // @281_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @282_4f5300
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L4f5628;  // @283_4f5300
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 228) + 0), 4); v; })));  // @284_4f5300
  X0[0] = X3[0];  // @285_4f5300
  X0[1] = X3[1];  // @286_4f5300
  X0[2] = X3[2];  // @287_4f5300
  X0[3] = X3[3];  // @288_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @289_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X5[0]));  // @290_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @291_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 4) + 0), &X1[0], 4);  // @292_4f5300
  goto L4f5654;  // @293_4f5300
  L4f5628:;
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4f564c;  // @295_4f5300
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 228) + 0), 4); v; })));  // @296_4f5300
  X0[0] = X3[0];  // @297_4f5300
  X0[1] = X3[1];  // @298_4f5300
  X0[2] = X3[2];  // @299_4f5300
  X0[3] = X3[3];  // @300_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @301_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X5[0]));  // @302_4f5300
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @303_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 4) + 0), &X1[0], 4);  // @304_4f5300
  goto L4f5654;  // @305_4f5300
  L4f564c:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi + 4), &v, sizeof v); }  // @307_4f5300
  L4f5654:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + ebx - 148) + 0), 4); v; });  // @309_4f5300
  X1[1] = 0;  // @310_4f5300
  X1[2] = 0;  // @311_4f5300
  X1[3] = 0;  // @312_4f5300
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @313_4f5300
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @314_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @315_4f5300
  if (__builtin_parity(FL[2] & 0xff)) goto L4f568e;  // @316_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 232) + 0), 4); v; });  // @317_4f5300
  X0[1] = 0;  // @318_4f5300
  X0[2] = 0;  // @319_4f5300
  X0[3] = 0;  // @320_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @321_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 28) + 0), &X0[0], 4);  // @322_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @323_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + esi) + 0), 4); v; });  // @324_4f5300
  X0[1] = 0;  // @325_4f5300
  X0[2] = 0;  // @326_4f5300
  X0[3] = 0;  // @327_4f5300
  X0[0] = F2U(U2F(X0[0]) - U2F(X6[0]));  // @328_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi) + 0), &X0[0], 4);  // @329_4f5300
  goto L4f5694;  // @330_4f5300
  L4f568e:;
  __builtin_memcpy((void *)((u32)(eax + esi + 28) + 0), &X3[0], 4);  // @332_4f5300
  L4f5694:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + ebx - 144) + 0), 4); v; });  // @334_4f5300
  X0[1] = 0;  // @335_4f5300
  X0[2] = 0;  // @336_4f5300
  X0[3] = 0;  // @337_4f5300
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @338_4f5300
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @339_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @340_4f5300
  if (__builtin_parity(FL[2] & 0xff)) goto L4f56cc;  // @341_4f5300
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 228) + 0), 4); v; })));  // @342_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 32) + 0), &X0[0], 4);  // @343_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @344_4f5300
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + esi + 4) + 0), 4); v; });  // @345_4f5300
  X0[1] = 0;  // @346_4f5300
  X0[2] = 0;  // @347_4f5300
  X0[3] = 0;  // @348_4f5300
  X0[0] = F2U(U2F(X0[0]) - U2F(X5[0]));  // @349_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 4) + 0), &X0[0], 4);  // @350_4f5300
  goto L4f56d2;  // @351_4f5300
  L4f56cc:;
  __builtin_memcpy((void *)((u32)(eax + esi + 32) + 0), &X3[0], 4);  // @353_4f5300
  L4f56d2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @355_4f5300
  X1[0] = X7[0];  // @356_4f5300
  X1[1] = X7[1];  // @357_4f5300
  X1[2] = X7[2];  // @358_4f5300
  X1[3] = X7[3];  // @359_4f5300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi + 8), &v, sizeof v); }  // @360_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 183), sizeof v); (u32)v; });  // @361_4f5300
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @362_4f5300
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @363_4f5300
  eax = (eax >> (u32)(31));  // @364_4f5300
  FL[3] = eax;  // @365_4f5300
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @366_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @367_4f5300
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @368_4f5300
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @369_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 12) + 0), &X1[0], 4);  // @370_4f5300
  X1[0] = X7[0];  // @371_4f5300
  X1[1] = X7[1];  // @372_4f5300
  X1[2] = X7[2];  // @373_4f5300
  X1[3] = X7[3];  // @374_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 183), sizeof v); (u32)v; });  // @375_4f5300
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @376_4f5300
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @377_4f5300
  eax = (eax >> (u32)(31));  // @378_4f5300
  FL[3] = eax;  // @379_4f5300
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @380_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @381_4f5300
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @382_4f5300
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @383_4f5300
  __builtin_memcpy((void *)((u32)(eax + esi + 24) + 0), &X1[0], 4);  // @384_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 183), sizeof v); (u32)v; });  // @385_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @386_4f5300
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @387_4f5300
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + esi + 28) + 0), 4); v; });  // @388_4f5300
  X1[1] = 0;  // @389_4f5300
  X1[2] = 0;  // @390_4f5300
  X1[3] = 0;  // @391_4f5300
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @392_4f5300
  eax = (eax >> (u32)(31));  // @393_4f5300
  FL[3] = eax;  // @394_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X4[0]));  // @395_4f5300
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @396_4f5300
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @397_4f5300
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @398_4f5300
  __builtin_memcpy((void *)((u32)(ecx + esi + 16) + 0), &X1[0], 4);  // @399_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 183), sizeof v); (u32)v; });  // @400_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @401_4f5300
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @402_4f5300
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + esi + 32) + 0), 4); v; });  // @403_4f5300
  X1[1] = 0;  // @404_4f5300
  X1[2] = 0;  // @405_4f5300
  X1[3] = 0;  // @406_4f5300
  eax = (eax >> (u32)(31));  // @407_4f5300
  FL[3] = eax;  // @408_4f5300
  X1[0] = F2U(U2F(X1[0]) - U2F(X4[0]));  // @409_4f5300
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @410_4f5300
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @411_4f5300
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @412_4f5300
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @413_4f5300
  __builtin_memcpy((void *)((u32)(ecx + esi + 20) + 0), &X1[0], 4);  // @414_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @415_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @416_4f5300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @417_4f5300
  eax = (u32)(edi + 24);  // @418_4f5300
  PV[5] = (u32)(eax);  // @419_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @420_4f5300
  eax = (eax + (u32)(36));  // @421_4f5300
  FL[3] = eax;  // @422_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @423_4f5300
  eax = (eax + esi);  // @424_4f5300
  FL[3] = eax;  // @425_4f5300
  PV[6] = (u32)(eax);  // @426_4f5300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[6], PV[5]);  // @427_4f5300
  ecx = edx = 0;  // @428_4f5300
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 224) + 0), 4); v; });  // @429_4f5300
  X3[1] = 0;  // @430_4f5300
  X3[2] = 0;  // @431_4f5300
  X3[3] = 0;  // @432_4f5300
  ebx = (ebx + (u32)(8));  // @433_4f5300
  FL[3] = ebx;  // @434_4f5300
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @435_4f5300
  X4[1] = 0;  // @436_4f5300
  X4[2] = 0;  // @437_4f5300
  X4[3] = 0;  // @438_4f5300
  esi = (esi + (u32)(40));  // @439_4f5300
  FL[3] = esi;  // @440_4f5300
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 236) + 0), 4); v; });  // @441_4f5300
  X5[1] = 0;  // @442_4f5300
  X5[2] = 0;  // @443_4f5300
  X5[3] = 0;  // @444_4f5300
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 240) + 0), 4); v; });  // @445_4f5300
  X6[1] = 0;  // @446_4f5300
  X6[2] = 0;  // @447_4f5300
  X6[3] = 0;  // @448_4f5300
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792880) + 0), 4); v; });  // @449_4f5300
  X7[1] = 0;  // @450_4f5300
  X7[2] = 0;  // @451_4f5300
  X7[3] = 0;  // @452_4f5300
  FL[0] = ebx; FL[1] = (u32)(72);  // @453_4f5300
  if ((s32)FL[0] < (s32)FL[1]) goto L4f55a2;  // @454_4f5300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 42), sizeof v); (u32)v; });  // @455_4f5300
  eax = (u32)(edi + 58);  // @456_4f5300
  PV[7] = (u32)(edi);  // @457_4f5300
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @458_4f5300
  ecx = (u32)(EBP - 220);  // @459_4f5300
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 46), sizeof v); (u32)v; });  // @460_4f5300
  PV[10] = (u32)(eax);  // @461_4f5300
  eax = (u32)(edi + 54);  // @462_4f5300
  PV[11] = (u32)(eax);  // @463_4f5300
  eax = ext_4f9350_fastcall7(ecx, edx, PV[11], PV[10], PV[9], PV[8], PV[7]);  // @464_4f5300
  ecx = edx = 0;  // @465_4f5300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 50), &v, sizeof v); }  // @466_4f5300
  ecx = edi;  // @467_4f5300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @468_4f5300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 552)))(ecx);  // @469_4f5300
  ecx = edx = 0;  // @470_4f5300
  ext_633654(G(u32, 0x6f5630));  // @471_4f5300
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @472_4f5300
  return eax;  // @473_4f5300
}
PCREG(4f5300, lifted_4f5300);

extern "C" u32 FASTCALL lifted_54f2b0(u32 ecx_in, u32 edx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  esi = (u32)(EBP - 516);  // @0_54f2b0
  esi = (esi - edx);  // @1_54f2b0
  FL[3] = esi;  // @2_54f2b0
  L54f2d0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @4_54f2b0
  edx = (u32)(edx + 1);  // @5_54f2b0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + edx - 1), &v, sizeof v); }  // @6_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @7_54f2b0
  if (FL[2] != 0) goto L54f2d0;  // @8_54f2b0
  edi = (u32)(EBP - 516);  // @9_54f2b0
  edi = (edi - 1);  // @10_54f2b0
  FL[3] = edi;  // @11_54f2b0
  L54f2e4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @13_54f2b0
  edi = (u32)(edi + 1);  // @14_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @15_54f2b0
  if (FL[2] != 0) goto L54f2e4;  // @16_54f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6790764), sizeof v); (u32)v; })) & 0xffff);  // @17_54f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @18_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2289565706);  // @19_54f2b0
  if ((s32)FL[0] > (s32)FL[1]) goto L54f46c;  // @20_54f2b0
  if (FL[0] == FL[1]) goto L54f442;  // @21_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2147746064);  // @22_54f2b0
  if ((s32)FL[0] > (s32)FL[1]) goto L54f3c0;  // @23_54f2b0
  if (FL[0] == FL[1]) goto L54f39f;  // @24_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2147500033);  // @25_54f2b0
  if (FL[0] == FL[1]) goto L54f37c;  // @26_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2147500034);  // @27_54f2b0
  if (FL[0] == FL[1]) goto L54f35a;  // @28_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2147500037);  // @29_54f2b0
  if (FL[0] != FL[1]) goto L54f69b;  // @30_54f2b0
  edi = (u32)(EBP - 516);  // @31_54f2b0
  edi = (edi - 1);  // @32_54f2b0
  FL[3] = edi;  // @33_54f2b0
  L54f340:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @35_54f2b0
  edi = (edi + 1);  // @36_54f2b0
  FL[3] = edi;  // @37_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @38_54f2b0
  if (FL[2] != 0) goto L54f340;  // @39_54f2b0
  ecx = (u32)(16);  // @40_54f2b0
  esi = (u32)(6964832);  // @41_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @42_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @43_54f2b0
  goto L54f73e;  // @44_54f2b0
  L54f35a:;
  edi = (u32)(EBP - 516);  // @46_54f2b0
  edi = (edi - 1);  // @47_54f2b0
  FL[3] = edi;  // @48_54f2b0
  L54f361:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @50_54f2b0
  edi = (edi + 1);  // @51_54f2b0
  FL[3] = edi;  // @52_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @53_54f2b0
  if (FL[2] != 0) goto L54f361;  // @54_54f2b0
  ecx = (u32)(11);  // @55_54f2b0
  esi = (u32)(6965176);  // @56_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @57_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @58_54f2b0
  goto L54f73e;  // @59_54f2b0
  L54f37c:;
  edi = (u32)(EBP - 516);  // @61_54f2b0
  edi = (edi - 1);  // @62_54f2b0
  FL[3] = edi;  // @63_54f2b0
  L54f383:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @65_54f2b0
  edi = (edi + 1);  // @66_54f2b0
  FL[3] = edi;  // @67_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @68_54f2b0
  if (FL[2] != 0) goto L54f383;  // @69_54f2b0
  ecx = (u32)(12);  // @70_54f2b0
  esi = (u32)(6965720);  // @71_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @72_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @73_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @74_54f2b0
  goto L54f73e;  // @75_54f2b0
  L54f39f:;
  edi = (u32)(EBP - 516);  // @77_54f2b0
  edi = (edi - 1);  // @78_54f2b0
  FL[3] = edi;  // @79_54f2b0
  L54f3a6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @81_54f2b0
  edi = (edi + 1);  // @82_54f2b0
  FL[3] = edi;  // @83_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @84_54f2b0
  if (FL[2] != 0) goto L54f3a6;  // @85_54f2b0
  ecx = (u32)(10);  // @86_54f2b0
  esi = (u32)(6965032);  // @87_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @88_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @89_54f2b0
  goto L54f73e;  // @90_54f2b0
  L54f3c0:;
  FL[0] = ecx; FL[1] = (u32)(2147942405);  // @92_54f2b0
  if (FL[0] == FL[1]) goto L54f420;  // @93_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2147942414);  // @94_54f2b0
  if (FL[0] == FL[1]) goto L54f3ff;  // @95_54f2b0
  FL[0] = ecx; FL[1] = (u32)(2147942487);  // @96_54f2b0
  if (FL[0] != FL[1]) goto L54f69b;  // @97_54f2b0
  edi = (u32)(EBP - 516);  // @98_54f2b0
  edi = (edi - 1);  // @99_54f2b0
  FL[3] = edi;  // @100_54f2b0
  L54f3e3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @102_54f2b0
  edi = (edi + 1);  // @103_54f2b0
  FL[3] = edi;  // @104_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @105_54f2b0
  if (FL[2] != 0) goto L54f3e3;  // @106_54f2b0
  ecx = (u32)(14);  // @107_54f2b0
  esi = (u32)(6964972);  // @108_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @109_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @110_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @111_54f2b0
  goto L54f73e;  // @112_54f2b0
  L54f3ff:;
  edi = (u32)(EBP - 516);  // @114_54f2b0
  edi = (edi - 1);  // @115_54f2b0
  FL[3] = edi;  // @116_54f2b0
  L54f406:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @118_54f2b0
  edi = (edi + 1);  // @119_54f2b0
  FL[3] = edi;  // @120_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @121_54f2b0
  if (FL[2] != 0) goto L54f406;  // @122_54f2b0
  ecx = (u32)(24);  // @123_54f2b0
  esi = (u32)(6965352);  // @124_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @125_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @126_54f2b0
  goto L54f73e;  // @127_54f2b0
  L54f420:;
  edi = (u32)(EBP - 516);  // @129_54f2b0
  edi = (edi - 1);  // @130_54f2b0
  FL[3] = edi;  // @131_54f2b0
  L54f427:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @133_54f2b0
  edi = (edi + 1);  // @134_54f2b0
  FL[3] = edi;  // @135_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @136_54f2b0
  if (FL[2] != 0) goto L54f427;  // @137_54f2b0
  ecx = (u32)(11);  // @138_54f2b0
  esi = (u32)(6964160);  // @139_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @140_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @141_54f2b0
  goto L54f73e;  // @142_54f2b0
  L54f442:;
  edi = (u32)(EBP - 516);  // @144_54f2b0
  edi = (edi - 1);  // @145_54f2b0
  FL[3] = edi;  // @146_54f2b0
  L54f450:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @148_54f2b0
  edi = (edi + 1);  // @149_54f2b0
  FL[3] = edi;  // @150_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @151_54f2b0
  if (FL[2] != 0) goto L54f450;  // @152_54f2b0
  ecx = (u32)(25);  // @153_54f2b0
  esi = (u32)(6964208);  // @154_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @155_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @156_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @157_54f2b0
  goto L54f73e;  // @158_54f2b0
  L54f46c:;
  FL[0] = ecx; FL[1] = (u32)(2289570145);  // @160_54f2b0
  if ((s32)FL[0] > (s32)FL[1]) goto L54f689;  // @161_54f2b0
  if (FL[0] == FL[1]) goto L54f663;  // @162_54f2b0
  ecx = (ecx + (u32)(2005401570));  // @163_54f2b0
  FL[3] = ecx;  // @164_54f2b0
  FL[0] = ecx; FL[1] = (u32)(180);  // @165_54f2b0
  if (FL[0] > FL[1]) goto L54f69b;  // @166_54f2b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5568432), sizeof v); (u32)v; });  // @167_54f2b0
  switch (eax) {  // @168_54f2b0
  case 0: goto L54f54d;  // @169_54f2b0
  case 1: goto L54f58f;  // @170_54f2b0
  case 2: goto L54f5fc;  // @171_54f2b0
  case 3: goto L54f4c1;  // @172_54f2b0
  case 4: goto L54f5b0;  // @173_54f2b0
  case 5: goto L54f49e;  // @174_54f2b0
  case 6: goto L54f503;  // @175_54f2b0
  case 7: goto L54f5d2;  // @176_54f2b0
  case 8: goto L54f640;  // @177_54f2b0
  case 9: goto L54f52b;  // @178_54f2b0
  case 10: goto L54f56f;  // @179_54f2b0
  case 11: goto L54f61e;  // @180_54f2b0
  case 12: goto L54f4e1;  // @181_54f2b0
  case 13: goto L54f69b;  // @182_54f2b0
  default: __builtin_trap(); }  // @183_54f2b0
  L54f49e:;
  edi = (u32)(EBP - 516);  // @185_54f2b0
  edi = (edi - 1);  // @186_54f2b0
  FL[3] = edi;  // @187_54f2b0
  L54f4a5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @189_54f2b0
  edi = (edi + 1);  // @190_54f2b0
  FL[3] = edi;  // @191_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @192_54f2b0
  if (FL[2] != 0) goto L54f4a5;  // @193_54f2b0
  ecx = (u32)(8);  // @194_54f2b0
  esi = (u32)(6964312);  // @195_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @196_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @197_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @198_54f2b0
  goto L54f73e;  // @199_54f2b0
  L54f4c1:;
  edi = (u32)(EBP - 516);  // @201_54f2b0
  edi = (edi - 1);  // @202_54f2b0
  FL[3] = edi;  // @203_54f2b0
  L54f4c8:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @205_54f2b0
  edi = (edi + 1);  // @206_54f2b0
  FL[3] = edi;  // @207_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @208_54f2b0
  if (FL[2] != 0) goto L54f4c8;  // @209_54f2b0
  ecx = (u32)(11);  // @210_54f2b0
  esi = (u32)(6964348);  // @211_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @212_54f2b0
  goto L54f73e;  // @213_54f2b0
  L54f4e1:;
  edi = (u32)(EBP - 516);  // @215_54f2b0
  edi = (edi - 1);  // @216_54f2b0
  FL[3] = edi;  // @217_54f2b0
  L54f4e8:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @219_54f2b0
  edi = (edi + 1);  // @220_54f2b0
  FL[3] = edi;  // @221_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @222_54f2b0
  if (FL[2] != 0) goto L54f4e8;  // @223_54f2b0
  ecx = (u32)(19);  // @224_54f2b0
  esi = (u32)(6964392);  // @225_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @226_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @227_54f2b0
  goto L54f73e;  // @228_54f2b0
  L54f503:;
  edi = (u32)(EBP - 516);  // @230_54f2b0
  edi = (edi - 1);  // @231_54f2b0
  FL[3] = edi;  // @232_54f2b0
  L54f510:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @234_54f2b0
  edi = (edi + 1);  // @235_54f2b0
  FL[3] = edi;  // @236_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @237_54f2b0
  if (FL[2] != 0) goto L54f510;  // @238_54f2b0
  ecx = (u32)(13);  // @239_54f2b0
  esi = (u32)(6964472);  // @240_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @241_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @242_54f2b0
  goto L54f73e;  // @243_54f2b0
  L54f52b:;
  edi = (u32)(EBP - 516);  // @245_54f2b0
  edi = (edi - 1);  // @246_54f2b0
  FL[3] = edi;  // @247_54f2b0
  L54f532:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @249_54f2b0
  edi = (edi + 1);  // @250_54f2b0
  FL[3] = edi;  // @251_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @252_54f2b0
  if (FL[2] != 0) goto L54f532;  // @253_54f2b0
  ecx = (u32)(16);  // @254_54f2b0
  esi = (u32)(6964528);  // @255_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @256_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @257_54f2b0
  goto L54f73e;  // @258_54f2b0
  L54f54d:;
  edi = (u32)(EBP - 516);  // @260_54f2b0
  edi = (edi - 1);  // @261_54f2b0
  FL[3] = edi;  // @262_54f2b0
  L54f554:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @264_54f2b0
  edi = (edi + 1);  // @265_54f2b0
  FL[3] = edi;  // @266_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @267_54f2b0
  if (FL[2] != 0) goto L54f554;  // @268_54f2b0
  ecx = (u32)(21);  // @269_54f2b0
  esi = (u32)(6964600);  // @270_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @271_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @272_54f2b0
  goto L54f73e;  // @273_54f2b0
  L54f56f:;
  edi = (u32)(EBP - 516);  // @275_54f2b0
  edi = (edi - 1);  // @276_54f2b0
  FL[3] = edi;  // @277_54f2b0
  L54f576:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @279_54f2b0
  edi = (edi + 1);  // @280_54f2b0
  FL[3] = edi;  // @281_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @282_54f2b0
  if (FL[2] != 0) goto L54f576;  // @283_54f2b0
  ecx = (u32)(36);  // @284_54f2b0
  esi = (u32)(6964688);  // @285_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @286_54f2b0
  goto L54f73e;  // @287_54f2b0
  L54f58f:;
  edi = (u32)(EBP - 516);  // @289_54f2b0
  edi = (edi - 1);  // @290_54f2b0
  FL[3] = edi;  // @291_54f2b0
  L54f596:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @293_54f2b0
  edi = (edi + 1);  // @294_54f2b0
  FL[3] = edi;  // @295_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @296_54f2b0
  if (FL[2] != 0) goto L54f596;  // @297_54f2b0
  ecx = (u32)(16);  // @298_54f2b0
  esi = (u32)(6964904);  // @299_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @300_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @301_54f2b0
  goto L54f73e;  // @302_54f2b0
  L54f5b0:;
  edi = (u32)(EBP - 516);  // @304_54f2b0
  edi = (edi - 1);  // @305_54f2b0
  FL[3] = edi;  // @306_54f2b0
  L54f5b7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @308_54f2b0
  edi = (edi + 1);  // @309_54f2b0
  FL[3] = edi;  // @310_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @311_54f2b0
  if (FL[2] != 0) goto L54f5b7;  // @312_54f2b0
  ecx = (u32)(23);  // @313_54f2b0
  esi = (u32)(6965080);  // @314_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @315_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @316_54f2b0
  goto L54f73e;  // @317_54f2b0
  L54f5d2:;
  edi = (u32)(EBP - 516);  // @319_54f2b0
  edi = (edi - 1);  // @320_54f2b0
  FL[3] = edi;  // @321_54f2b0
  L54f5e0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @323_54f2b0
  edi = (edi + 1);  // @324_54f2b0
  FL[3] = edi;  // @325_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @326_54f2b0
  if (FL[2] != 0) goto L54f5e0;  // @327_54f2b0
  ecx = (u32)(21);  // @328_54f2b0
  esi = (u32)(6965264);  // @329_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @330_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @331_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @332_54f2b0
  goto L54f73e;  // @333_54f2b0
  L54f5fc:;
  edi = (u32)(EBP - 516);  // @335_54f2b0
  edi = (edi - 1);  // @336_54f2b0
  FL[3] = edi;  // @337_54f2b0
  L54f603:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @339_54f2b0
  edi = (edi + 1);  // @340_54f2b0
  FL[3] = edi;  // @341_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @342_54f2b0
  if (FL[2] != 0) goto L54f603;  // @343_54f2b0
  ecx = (u32)(20);  // @344_54f2b0
  esi = (u32)(6965456);  // @345_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @346_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @347_54f2b0
  goto L54f73e;  // @348_54f2b0
  L54f61e:;
  edi = (u32)(EBP - 516);  // @350_54f2b0
  edi = (edi - 1);  // @351_54f2b0
  FL[3] = edi;  // @352_54f2b0
  L54f625:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @354_54f2b0
  edi = (edi + 1);  // @355_54f2b0
  FL[3] = edi;  // @356_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @357_54f2b0
  if (FL[2] != 0) goto L54f625;  // @358_54f2b0
  ecx = (u32)(11);  // @359_54f2b0
  esi = (u32)(6965540);  // @360_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @361_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @362_54f2b0
  goto L54f73e;  // @363_54f2b0
  L54f640:;
  edi = (u32)(EBP - 516);  // @365_54f2b0
  edi = (edi - 1);  // @366_54f2b0
  FL[3] = edi;  // @367_54f2b0
  L54f647:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @369_54f2b0
  edi = (edi + 1);  // @370_54f2b0
  FL[3] = edi;  // @371_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @372_54f2b0
  if (FL[2] != 0) goto L54f647;  // @373_54f2b0
  ecx = (u32)(31);  // @374_54f2b0
  esi = (u32)(6965592);  // @375_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @376_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @377_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @378_54f2b0
  goto L54f73e;  // @379_54f2b0
  L54f663:;
  edi = (u32)(EBP - 516);  // @381_54f2b0
  edi = (edi - 1);  // @382_54f2b0
  FL[3] = edi;  // @383_54f2b0
  L54f670:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @385_54f2b0
  edi = (edi + 1);  // @386_54f2b0
  FL[3] = edi;  // @387_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @388_54f2b0
  if (FL[2] != 0) goto L54f670;  // @389_54f2b0
  ecx = (u32)(9);  // @390_54f2b0
  esi = (u32)(6965224);  // @391_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @392_54f2b0
  goto L54f73e;  // @393_54f2b0
  L54f689:;
  ecx = (ecx - (u32)(0));  // @395_54f2b0
  FL[3] = ecx;  // @396_54f2b0
  if (FL[3] == 0) goto L54f6fc;  // @397_54f2b0
  ecx = (ecx - (u32)(142082058));  // @398_54f2b0
  FL[3] = ecx;  // @399_54f2b0
  if (FL[3] == 0) goto L54f6dc;  // @400_54f2b0
  ecx = (ecx - (u32)(10));  // @401_54f2b0
  FL[3] = ecx;  // @402_54f2b0
  if (FL[3] == 0) goto L54f6bd;  // @403_54f2b0
  L54f69b:;
  edi = (u32)(EBP - 516);  // @405_54f2b0
  edi = (edi - 1);  // @406_54f2b0
  FL[3] = edi;  // @407_54f2b0
  L54f6a2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @409_54f2b0
  edi = (edi + 1);  // @410_54f2b0
  FL[3] = edi;  // @411_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @412_54f2b0
  if (FL[2] != 0) goto L54f6a2;  // @413_54f2b0
  ecx = (u32)(7);  // @414_54f2b0
  esi = (u32)(6965772);  // @415_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @416_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @417_54f2b0
  goto L54f73e;  // @418_54f2b0
  L54f6bd:;
  edi = (u32)(EBP - 516);  // @420_54f2b0
  edi = (edi - 1);  // @421_54f2b0
  FL[3] = edi;  // @422_54f2b0
  L54f6c4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @424_54f2b0
  edi = (edi + 1);  // @425_54f2b0
  FL[3] = edi;  // @426_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @427_54f2b0
  if (FL[2] != 0) goto L54f6c4;  // @428_54f2b0
  ecx = (u32)(17);  // @429_54f2b0
  esi = (u32)(6964088);  // @430_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @431_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @432_54f2b0
  goto L54f73e;  // @433_54f2b0
  L54f6dc:;
  edi = (u32)(EBP - 516);  // @435_54f2b0
  edi = (edi - 1);  // @436_54f2b0
  FL[3] = edi;  // @437_54f2b0
  L54f6e3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @439_54f2b0
  edi = (edi + 1);  // @440_54f2b0
  FL[3] = edi;  // @441_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @442_54f2b0
  if (FL[2] != 0) goto L54f6e3;  // @443_54f2b0
  ecx = (u32)(16);  // @444_54f2b0
  esi = (u32)(6964016);  // @445_54f2b0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @446_54f2b0
  { u16 v_; __builtin_memcpy(&v_, (void *)esi, 2); __builtin_memcpy((void *)edi, &v_, 2); esi += 2; edi += 2; }  // @447_54f2b0
  { *(u8 *)edi = *(u8 *)esi; esi++; edi++; }  // @448_54f2b0
  goto L54f73e;  // @449_54f2b0
  L54f6fc:;
  ecx = (u32)(EBP - 516);  // @451_54f2b0
  ecx = (ecx - 1);  // @452_54f2b0
  FL[3] = ecx;  // @453_54f2b0
  L54f703:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @455_54f2b0
  ecx = (u32)(ecx + 1);  // @456_54f2b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @457_54f2b0
  if (FL[2] != 0) goto L54f703;  // @458_54f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6963988), sizeof v); (u32)v; });  // @459_54f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @460_54f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6963992), sizeof v); (u32)v; });  // @461_54f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @462_54f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6963996), sizeof v); (u32)v; });  // @463_54f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @464_54f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6964000), sizeof v); (u32)v; });  // @465_54f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @466_54f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6964004), sizeof v); (u32)v; });  // @467_54f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @468_54f2b0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6964008), sizeof v); (u32)v; })) & 0xffff);  // @469_54f2b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @470_54f2b0
  L54f73e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @472_54f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @473_54f2b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6965804), (u32)(101));  // @474_54f2b0
  ecx = edx = 0;  // @475_54f2b0
  edx = (u32)(EBP - 516);  // @476_54f2b0
  PV[0] = (u32)(edx);  // @477_54f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @478_54f2b0
  PV[1] = (u32)(eax);  // @479_54f2b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6965864), PV[0]);  // @480_54f2b0
  ecx = edx = 0;  // @481_54f2b0
  ext_633654(G(u32, 0x6f5630));  // @482_54f2b0
  return eax;  // @483_54f2b0
}
PCREG(54f2b0, lifted_54f2b0);

extern "C" u32 THISCALL lifted_53c5b0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  esi = ecx;  // @0_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @1_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_53c5b0
  X2[0] = 0;  // @3_53c5b0
  X2[1] = 0;  // @4_53c5b0
  X2[2] = 0;  // @5_53c5b0
  X2[3] = 0;  // @6_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_53c5b0
  X0[0] = X2[0];  // @8_53c5b0
  X0[1] = X2[1];  // @9_53c5b0
  X0[2] = X2[2];  // @10_53c5b0
  X0[3] = X2[3];  // @11_53c5b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802756) + 0), 4); v; });  // @12_53c5b0
  X1[1] = 0;  // @13_53c5b0
  X1[2] = 0;  // @14_53c5b0
  X1[3] = 0;  // @15_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @16_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @17_53c5b0
  eax = (eax | (u32)(4294967295));  // @18_53c5b0
  FL[3] = eax;  // @19_53c5b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @20_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @21_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @22_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @23_53c5b0
  ecx = (ecx & 0xffffff00u) | ((0) & 0xff);  // @24_53c5b0
  FL[3] = (ecx & 0xff);  // @25_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @26_53c5b0
  eax = (eax | eax);  // @27_53c5b0
  FL[3] = eax;  // @28_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @29_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @30_53c5b0
  edi = 0;  // @31_53c5b0
  FL[3] = edi;  // @32_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @33_53c5b0
  edx = 0;  // @34_53c5b0
  FL[3] = edx;  // @35_53c5b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 57), &v, sizeof v); }  // @36_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @37_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @38_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @39_53c5b0
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X1[0], 4);  // @40_53c5b0
  L53c623:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edx*4 - 56), sizeof v); (u32)v; });  // @42_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edx*4 - 52), sizeof v); (u32)v; });  // @43_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @44_53c5b0
  FL[0] = eax; FL[1] = (u32)(-1);  // @45_53c5b0
  if (FL[0] == FL[1]) goto L53c734;  // @46_53c5b0
  FL[0] = ecx; FL[1] = (u32)(-1);  // @47_53c5b0
  if (FL[0] == FL[1]) goto L53c734;  // @48_53c5b0
  FL[0] = ecx; FL[1] = eax;  // @49_53c5b0
  if (FL[0] >= FL[1]) goto L53c64c;  // @50_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @51_53c5b0
  eax = ecx;  // @52_53c5b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @53_53c5b0
  L53c64c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4609), sizeof v); (u32)v; });  // @55_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*8), sizeof v); (u32)v; });  // @56_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*8 + 4), sizeof v); (u32)v; });  // @57_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @58_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4613), sizeof v); (u32)v; });  // @59_53c5b0
  edi = (u32)(eax + ecx*4);  // @60_53c5b0
  FL[2] = (esi & esi);  // @61_53c5b0
  if (FL[2] == 0) goto L53c6a6;  // @62_53c5b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 - 2), sizeof v); (u32)v; });  // @63_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @64_53c5b0
  eax = (eax & (u32)(16383));  // @65_53c5b0
  FL[3] = eax;  // @66_53c5b0
  FL[0] = ecx; FL[1] = eax;  // @67_53c5b0
  if (FL[0] > FL[1]) goto L53c6a6;  // @68_53c5b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @69_53c5b0
  eax = (eax & (u32)(16383));  // @70_53c5b0
  FL[3] = eax;  // @71_53c5b0
  FL[0] = ecx; FL[1] = eax;  // @72_53c5b0
  if (FL[0] < FL[1]) goto L53c6a6;  // @73_53c5b0
  ecx = 0;  // @74_53c5b0
  FL[3] = ecx;  // @75_53c5b0
  FL[2] = (esi & esi);  // @76_53c5b0
  if (FL[2] == 0) goto L53c6a6;  // @77_53c5b0
  L53c690:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @79_53c5b0
  eax = (eax & (u32)(16383));  // @80_53c5b0
  FL[3] = eax;  // @81_53c5b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }); FL[1] = eax;  // @82_53c5b0
  if (FL[0] == FL[1]) goto L53c6ba;  // @83_53c5b0
  ecx = (ecx + 1);  // @84_53c5b0
  FL[3] = ecx;  // @85_53c5b0
  edi = (edi + (u32)(4));  // @86_53c5b0
  FL[3] = edi;  // @87_53c5b0
  FL[0] = ecx; FL[1] = esi;  // @88_53c5b0
  if (FL[0] < FL[1]) goto L53c690;  // @89_53c5b0
  L53c6a6:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @91_53c5b0
  FL[3] = (eax & 0xff);  // @92_53c5b0
  ext_633654(G(u32, 0x6f5630));  // @93_53c5b0
  return eax;  // @94_53c5b0
  L53c6ba:;
  esi = (esi - ecx);  // @96_53c5b0
  FL[3] = esi;  // @97_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @98_53c5b0
  if (FL[3] == 0) goto L53c6a6;  // @99_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @100_53c5b0
  esi = 0;  // @101_53c5b0
  FL[3] = esi;  // @102_53c5b0
  X0[0] = X2[0];  // @103_53c5b0
  X0[1] = X2[1];  // @104_53c5b0
  X0[2] = X2[2];  // @105_53c5b0
  X0[3] = X2[3];  // @106_53c5b0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @107_53c5b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @108_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @109_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 37), &v, sizeof v); }  // @110_53c5b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; }); FL[1] = esi;  // @111_53c5b0
  if (FL[0] <= FL[1]) goto L53c731;  // @112_53c5b0
  L53c6e4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4), sizeof v); (u32)v; });  // @114_53c5b0
  eax = (ecx & 0xffff);  // @115_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @116_53c5b0
  eax = ecx;  // @117_53c5b0
  eax = (eax >> (u32)(16));  // @118_53c5b0
  FL[3] = eax;  // @119_53c5b0
  eax = (eax & (u32)(16383));  // @120_53c5b0
  FL[3] = eax;  // @121_53c5b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }); FL[1] = eax;  // @122_53c5b0
  if (FL[0] != FL[1]) goto L53c72e;  // @123_53c5b0
  ecx = (ecx >> (u32)(30));  // @124_53c5b0
  FL[3] = ecx;  // @125_53c5b0
  ecx = (ecx - (u32)(0));  // @126_53c5b0
  FL[3] = ecx;  // @127_53c5b0
  if (FL[3] == 0) goto L53c88e;  // @128_53c5b0
  ecx = (ecx - (u32)(1));  // @129_53c5b0
  FL[3] = ecx;  // @130_53c5b0
  if (FL[3] == 0) goto L53c77a;  // @131_53c5b0
  ecx = (ecx - (u32)(1));  // @132_53c5b0
  FL[3] = ecx;  // @133_53c5b0
  if (FL[3] == 0) goto L53c725;  // @134_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @135_53c5b0
  FL[2] = (eax & eax);  // @136_53c5b0
  if (FL[2] == 0) goto L53c777;  // @137_53c5b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @138_53c5b0
  ecx = edx = 0;  // @139_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @140_53c5b0
  L53c720:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @142_53c5b0
  X0[1] = 0;  // @143_53c5b0
  X0[2] = 0;  // @144_53c5b0
  X0[3] = 0;  // @145_53c5b0
  L53c725:;
  esi = (esi + 1);  // @147_53c5b0
  FL[3] = esi;  // @148_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @149_53c5b0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @150_53c5b0
  if (FL[0] < FL[1]) goto L53c6e4;  // @151_53c5b0
  L53c72e:;
  X2[0] = 0;  // @153_53c5b0
  X2[1] = 0;  // @154_53c5b0
  X2[2] = 0;  // @155_53c5b0
  X2[3] = 0;  // @156_53c5b0
  L53c731:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @158_53c5b0
  L53c734:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @160_53c5b0
  eax = (eax - 1);  // @161_53c5b0
  FL[3] = eax;  // @162_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @163_53c5b0
  FL[2] = (eax & eax);  // @164_53c5b0
  if (FL[2] != 0) goto L53c623;  // @165_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @166_53c5b0
  FL[0] = eax; FL[1] = (u32)(-1);  // @167_53c5b0
  if (FL[0] == FL[1]) goto L53ca35;  // @168_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @169_53c5b0
  edx = (edx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @170_53c5b0
  eax = (ecx & 0xffff);  // @171_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @172_53c5b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @173_53c5b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @174_53c5b0
  if (!__builtin_parity(FL[2] & 0xff)) goto L53c92f;  // @175_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @176_53c5b0
  edx = (edx & 0xffffff00u) | ((0) & 0xff);  // @177_53c5b0
  FL[3] = (edx & 0xff);  // @178_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @179_53c5b0
  edi = (ecx & 0xffff);  // @180_53c5b0
  goto L53c932;  // @181_53c5b0
  L53c777:;
  __builtin_trap();  // @183_53c5b0
  L53c77a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @185_53c5b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 57), &v, sizeof v); }  // @186_53c5b0
  edx = (u32)(eax + eax*2);  // @187_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @188_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4605), sizeof v); (u32)v; });  // @189_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4601), sizeof v); (u32)v; });  // @190_53c5b0
  esi = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @191_53c5b0
  esi = (esi + eax);  // @192_53c5b0
  FL[3] = esi;  // @193_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @194_53c5b0
  esi = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4 + 4), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @195_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @196_53c5b0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @197_53c5b0
  esi = (esi + eax);  // @198_53c5b0
  FL[3] = esi;  // @199_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @200_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @201_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @202_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @203_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @204_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @205_53c5b0
  ecx = edx = 0;  // @206_53c5b0
  ecx = eax;  // @207_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @208_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @209_53c5b0
  edx = (u32)(EBP - 16);  // @210_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @211_53c5b0
  PV[1] = (u32)(edx);  // @212_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[1]);  // @214_53c5b0
  ecx = edx = 0;  // @215_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @216_53c5b0
  ecx = (u32)(EBP - 16);  // @217_53c5b0
  eax = ext_4e0830_fastcall2(ecx, edx);  // @218_53c5b0
  ecx = edx = 0;  // @219_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @220_53c5b0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_53c5b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 124)) :: "st");  // @222_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @223_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @225_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[2]);  // @226_53c5b0
  ecx = edx = 0;  // @227_53c5b0
  ecx = eax;  // @228_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @229_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @230_53c5b0
  edx = (u32)(EBP - 28);  // @231_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @232_53c5b0
  PV[3] = (u32)(edx);  // @233_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @234_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[3]);  // @235_53c5b0
  ecx = edx = 0;  // @236_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @237_53c5b0
  ecx = (u32)(EBP - 28);  // @238_53c5b0
  eax = ext_4e0830_fastcall2(ecx, edx);  // @239_53c5b0
  ecx = edx = 0;  // @240_53c5b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @241_53c5b0
  X2[1] = 0;  // @242_53c5b0
  X2[2] = 0;  // @243_53c5b0
  X2[3] = 0;  // @244_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @245_53c5b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 132)) :: "st");  // @246_53c5b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 132) + 0), 4); v; });  // @247_53c5b0
  X0[1] = 0;  // @248_53c5b0
  X0[2] = 0;  // @249_53c5b0
  X0[3] = 0;  // @250_53c5b0
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @251_53c5b0
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L53c85e;  // @252_53c5b0
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X0[0], 4);  // @253_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @254_53c5b0
  L53c85e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @256_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @257_53c5b0
  edx = (edx + (u32)(2));  // @258_53c5b0
  FL[3] = edx;  // @259_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @260_53c5b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @261_53c5b0
  X0[1] = 0;  // @262_53c5b0
  X0[2] = 0;  // @263_53c5b0
  X0[3] = 0;  // @264_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @265_53c5b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @266_53c5b0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; }))))) goto L53c720;  // @267_53c5b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @268_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @269_53c5b0
  goto L53c725;  // @270_53c5b0
  L53c88e:;
  edx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @272_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @273_53c5b0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4601), sizeof v); (u32)v; }));  // @274_53c5b0
  FL[3] = edx;  // @275_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @276_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @277_53c5b0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @278_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @279_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @280_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @281_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[4]);  // @282_53c5b0
  ecx = edx = 0;  // @283_53c5b0
  ecx = eax;  // @284_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @285_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @286_53c5b0
  edx = (u32)(EBP - 40);  // @287_53c5b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @288_53c5b0
  PV[5] = (u32)(edx);  // @289_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @290_53c5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[5]);  // @291_53c5b0
  ecx = edx = 0;  // @292_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @293_53c5b0
  ecx = (u32)(EBP - 40);  // @294_53c5b0
  eax = ext_4e0830_fastcall2(ecx, edx);  // @295_53c5b0
  ecx = edx = 0;  // @296_53c5b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @297_53c5b0
  X2[1] = 0;  // @298_53c5b0
  X2[2] = 0;  // @299_53c5b0
  X2[3] = 0;  // @300_53c5b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 112)) :: "st");  // @301_53c5b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 112) + 0), 4); v; });  // @302_53c5b0
  X0[1] = 0;  // @303_53c5b0
  X0[2] = 0;  // @304_53c5b0
  X0[3] = 0;  // @305_53c5b0
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L53c900;  // @306_53c5b0
  X1[0] = X0[0];  // @307_53c5b0
  X1[1] = X0[1];  // @308_53c5b0
  X1[2] = X0[2];  // @309_53c5b0
  X1[3] = X0[3];  // @310_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @311_53c5b0
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X1[0], 4);  // @312_53c5b0
  L53c900:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @314_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @315_53c5b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @316_53c5b0
  X0[1] = 0;  // @317_53c5b0
  X0[2] = 0;  // @318_53c5b0
  X0[3] = 0;  // @319_53c5b0
  edx = (edx + (u32)(2));  // @320_53c5b0
  FL[3] = edx;  // @321_53c5b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @322_53c5b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @323_53c5b0
  X1[1] = 0;  // @324_53c5b0
  X1[2] = 0;  // @325_53c5b0
  X1[3] = 0;  // @326_53c5b0
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L53c926;  // @327_53c5b0
  X0[0] = X1[0];  // @328_53c5b0
  X0[1] = X1[1];  // @329_53c5b0
  X0[2] = X1[2];  // @330_53c5b0
  X0[3] = X1[3];  // @331_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @332_53c5b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X0[0], 4);  // @333_53c5b0
  L53c926:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 57), &v, sizeof v); }  // @335_53c5b0
  goto L53c725;  // @336_53c5b0
  L53c92f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @338_53c5b0
  L53c932:;
  ecx = (ecx >> (u32)(30));  // @340_53c5b0
  FL[3] = ecx;  // @341_53c5b0
  ecx = (ecx - (u32)(0));  // @342_53c5b0
  FL[3] = ecx;  // @343_53c5b0
  if (FL[3] == 0) goto L53c9b2;  // @344_53c5b0
  ecx = (ecx - (u32)(1));  // @345_53c5b0
  FL[3] = ecx;  // @346_53c5b0
  if (FL[3] != 0) goto L53ca35;  // @347_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @348_53c5b0
  esi = (u32)(edi + edi*2);  // @349_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @350_53c5b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @351_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @352_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4605), sizeof v); (u32)v; });  // @353_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @354_53c5b0
  eax = (u32)(eax + eax*2);  // @355_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @356_53c5b0
  esi = (u32)(edi + edi*2);  // @357_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @358_53c5b0
  ecx = (u32)(eax + eax*2);  // @359_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; });  // @360_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @361_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 41), &v, sizeof v); }  // @362_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @363_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 5), &v, sizeof v); }  // @365_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @366_53c5b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @367_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @368_53c5b0
  eax = (u32)(eax + eax*2);  // @369_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @370_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @371_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @372_53c5b0
  ecx = (u32)(eax + eax*2);  // @373_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4 + 4), sizeof v); (u32)v; });  // @374_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @375_53c5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 41), &v, sizeof v); }  // @376_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @377_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @378_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx + eax*4 + 5), &v, sizeof v); }  // @379_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @380_53c5b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @381_53c5b0
  goto L53ca35;  // @382_53c5b0
  L53c9b2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @384_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @385_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @386_53c5b0
  eax = (u32)(eax + eax*2);  // @387_53c5b0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @388_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @389_53c5b0
  eax = (u32)(eax + eax*2);  // @390_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 41), &v, sizeof v); }  // @391_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @392_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 5), &v, sizeof v); }  // @393_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @394_53c5b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @396_53c5b0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @397_53c5b0
  if (FL[2] == 0) goto L53ca35;  // @398_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @399_53c5b0
  edx = (u32)((s32)edi * (s32)(u32)(164));  // @400_53c5b0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4601), sizeof v); (u32)v; }));  // @401_53c5b0
  FL[3] = edx;  // @402_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @403_53c5b0
  eax = ext_53bec0_fastcall2(ecx, edx);  // @404_53c5b0
  ecx = edx = 0;  // @405_53c5b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @406_53c5b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @407_53c5b0
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)(EBP - 116)) :: "st");  // @408_53c5b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @409_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @410_53c5b0
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @411_53c5b0
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @412_53c5b0
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @413_53c5b0
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @414_53c5b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @415_53c5b0
  eax = (u32)(eax + eax*2);  // @416_53c5b0
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 45), &v, sizeof v); }  // @417_53c5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @418_53c5b0
  eax = (u32)(eax + eax*2);  // @419_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 41), &v, sizeof v); }  // @420_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @421_53c5b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + ecx*4 + 5), &v, sizeof v); }  // @422_53c5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @423_53c5b0
  ecx = (u32)(ecx + ecx*2);  // @424_53c5b0
  __builtin_memcpy((void *)((u32)(esi + ecx*4 + 49) + 0), &X0[0], 4);  // @425_53c5b0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @426_53c5b0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @427_53c5b0
  L53ca35:;
  ext_633654(G(u32, 0x6f5630));  // @429_53c5b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 57), sizeof v); (u32)v; })) & 0xff);  // @430_53c5b0
  return eax;  // @431_53c5b0
}
PCREG(53c5b0, lifted_53c5b0);

