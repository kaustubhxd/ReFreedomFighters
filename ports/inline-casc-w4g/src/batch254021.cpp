// batch254021.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 THISCALL ext_53b380_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_53b380");
extern "C" u32 STDCALL ext_634123_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_634123");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cdd40_thiscall1(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4d8ce0_thiscall2(u32, u32) __asm__("ext_4d8ce0");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_436bd0(u32 ecx_in) {
  SEH_ENTER(0x6659b9);  // @h_436bd0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_436bd0
  { u32 v = (u32)((u32)(6792928)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_436bd0
  ecx = 0;  // @2_436bd0
  FL[3] = ecx;  // @3_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7227584), sizeof v); (u32)v; });  // @4_436bd0
  edx = 0;  // @5_436bd0
  FL[3] = edx;  // @6_436bd0
  FL[2] = (eax & eax);  // @7_436bd0
  if (FL[2] == 0) goto L436c30;  // @8_436bd0
  eax = 0;  // @9_436bd0
  FL[3] = eax;  // @10_436bd0
  L436c10:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 7227576), &v, sizeof v); }  // @12_436bd0
  edx = (edx + 1);  // @13_436bd0
  FL[3] = edx;  // @14_436bd0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227588), sizeof v); (u32)v; }));  // @15_436bd0
  FL[3] = ecx;  // @16_436bd0
  eax = edx;  // @17_436bd0
  eax = (eax << (u32)(4));  // @18_436bd0
  FL[3] = eax;  // @19_436bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227584), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_436bd0
  if (FL[0] != FL[1]) goto L436c10;  // @21_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7227584), sizeof v); (u32)v; });  // @22_436bd0
  L436c30:;
  edx = 0;  // @24_436bd0
  FL[3] = edx;  // @25_436bd0
  ecx = 0;  // @26_436bd0
  FL[3] = ecx;  // @27_436bd0
  FL[2] = (eax & eax);  // @28_436bd0
  if (FL[2] == 0) goto L436c55;  // @29_436bd0
  eax = 0;  // @30_436bd0
  FL[3] = eax;  // @31_436bd0
  L436c40:;
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227588), sizeof v); (u32)v; }));  // @33_436bd0
  FL[3] = edx;  // @34_436bd0
  ecx = (ecx + 1);  // @35_436bd0
  FL[3] = ecx;  // @36_436bd0
  eax = ecx;  // @37_436bd0
  eax = (eax << (u32)(4));  // @38_436bd0
  FL[3] = eax;  // @39_436bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7227584), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @40_436bd0
  if (FL[0] != FL[1]) goto L436c40;  // @41_436bd0
  L436c55:;
  PV[0] = (u32)(edx);  // @43_436bd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 4624), &v, sizeof v); }  // @44_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4616), &v, sizeof v); }  // @45_436bd0
  eax = ext_41e290_cdecl1(PV[0]);  // @46_436bd0
  ecx = edx = 0;  // @47_436bd0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; });  // @48_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4892), &v, sizeof v); }  // @49_436bd0
  PV[2] = (u32)(eax);  // @50_436bd0
  eax = ext_634d10_cdecl3(PV[2], (u32)(0), PV[1]);  // @51_436bd0
    // @52_436bd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; });  // @53_436bd0
  ecx = 0;  // @54_436bd0
  FL[3] = ecx;  // @55_436bd0
  eax = ebx;  // @56_436bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @57_436bd0
  edx = (u32)(10);  // @58_436bd0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @59_436bd0
  MOF = edx;  // @60_436bd0
  ecx = (ecx & 0xffffff00u) | ((((MOF) != 0 ? 1 : 0)) & 0xff);  // @61_436bd0
  FL[1] = ecx;  // @62_436bd0
  ecx = (0u - ecx);  // @63_436bd0
  ecx = (ecx | eax);  // @64_436bd0
  FL[3] = ecx;  // @65_436bd0
  eax = 0;  // @66_436bd0
  FL[3] = eax;  // @67_436bd0
  ecx = (ecx + (u32)(4));  // @68_436bd0
  FL[3] = ecx;  // @69_436bd0
  eax = (eax & 0xffffff00u) | ((((0 && FL[3]) ? 1 : 0)) & 0xff);  // @70_436bd0
  FL[1] = eax;  // @71_436bd0
  eax = (0u - eax);  // @72_436bd0
  eax = (eax | ecx);  // @73_436bd0
  FL[3] = eax;  // @74_436bd0
  PV[3] = (u32)(eax);  // @75_436bd0
  eax = ext_41e290_cdecl1(PV[3]);  // @76_436bd0
  ecx = edx = 0;  // @77_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @78_436bd0
  reg.state = (s32)((u32)(0));  // @79_436bd0
  FL[2] = (eax & eax);  // @80_436bd0
  if (FL[2] == 0) goto L436cd7;  // @81_436bd0
  PV[4] = (u32)(ebx);  // @82_436bd0
  edi = (u32)(eax + 4);  // @83_436bd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @84_436bd0
  PV[5] = (u32)(edi);  // @85_436bd0
  eax = ext_634123_stdcall5(PV[5], (u32)(10), PV[4], (u32)(4416720), (u32)(4624560));  // @86_436bd0
  ecx = edx = 0;  // @87_436bd0
  goto L436cd9;  // @88_436bd0
  L436cd7:;
  edi = 0;  // @90_436bd0
  FL[3] = edi;  // @91_436bd0
  L436cd9:;
  edx = 0;  // @93_436bd0
  FL[3] = edx;  // @94_436bd0
  reg.state = (s32)((u32)(4294967295));  // @95_436bd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 4932), &v, sizeof v); }  // @96_436bd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; }); FL[1] = edx;  // @97_436bd0
  if (FL[0] == FL[1]) goto L436d13;  // @98_436bd0
  ecx = 0;  // @99_436bd0
  FL[3] = ecx;  // @100_436bd0
  L436cf2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4932), sizeof v); (u32)v; });  // @102_436bd0
  ecx = (u32)(ecx + 10);  // @103_436bd0
  edx = (edx + 1);  // @104_436bd0
  FL[3] = edx;  // @105_436bd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + eax - 10), &v, sizeof v); }  // @106_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4932), sizeof v); (u32)v; });  // @107_436bd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax - 1), &v, sizeof v); }  // @108_436bd0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4624), sizeof v); (u32)v; });  // @109_436bd0
  if (FL[0] != FL[1]) goto L436cf2;  // @110_436bd0
  L436d13:;
  eax = ext_41e290_cdecl1((u32)(28));  // @112_436bd0
  ecx = edx = 0;  // @113_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @114_436bd0
  reg.state = (s32)((u32)(1));  // @115_436bd0
  FL[2] = (eax & eax);  // @116_436bd0
  if (FL[2] == 0) goto L436d38;  // @117_436bd0
  ecx = eax;  // @118_436bd0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @119_436bd0
  ecx = edx = 0;  // @120_436bd0
  goto L436d3a;  // @121_436bd0
  L436d38:;
  eax = 0;  // @123_436bd0
  FL[3] = eax;  // @124_436bd0
  L436d3a:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4628), &v, sizeof v); }  // @126_436bd0
  ecx = (u32)(512);  // @127_436bd0
  reg.state = (s32)((u32)(4294967295));  // @128_436bd0
  eax = (u32)(esi + 13);  // @129_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4936), &v, sizeof v); }  // @130_436bd0
  L436d60:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 5), &v, sizeof v); }  // @132_436bd0
  eax = (u32)(eax + 9);  // @133_436bd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 10), &v, sizeof v); }  // @134_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 9), &v, sizeof v); }  // @135_436bd0
  ecx = (ecx - (u32)(1));  // @136_436bd0
  FL[3] = ecx;  // @137_436bd0
  if (FL[3] != 0) goto L436d60;  // @138_436bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4632), &v, sizeof v); }  // @139_436bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4904), &v, sizeof v); }  // @140_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @141_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2543), sizeof v); (u32)v; });  // @142_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4896), &v, sizeof v); }  // @143_436bd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4900), &v, sizeof v); }  // @144_436bd0
  eax = ext_41e290_cdecl1((u32)(6));  // @145_436bd0
  ecx = edx = 0;  // @146_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @147_436bd0
  reg.state = (s32)((u32)(2));  // @148_436bd0
  FL[2] = (eax & eax);  // @149_436bd0
  if (FL[2] == 0) goto L436dc0;  // @150_436bd0
  ecx = eax;  // @151_436bd0
  eax = ext_4d8ce0_thiscall2(ecx, (u32)(32));  // @152_436bd0
  ecx = edx = 0;  // @153_436bd0
  goto L436dc2;  // @154_436bd0
  L436dc0:;
  eax = 0;  // @156_436bd0
  FL[3] = eax;  // @157_436bd0
  L436dc2:;
  reg.state = (s32)((u32)(4294967295));  // @159_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4912), &v, sizeof v); }  // @160_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4620), &v, sizeof v); }  // @161_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4916), &v, sizeof v); }  // @162_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4920), &v, sizeof v); }  // @163_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @164_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4908), &v, sizeof v); }  // @165_436bd0
  eax = ext_41e290_cdecl1((u32)(28));  // @166_436bd0
  ecx = edx = 0;  // @167_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @168_436bd0
  reg.state = (s32)((u32)(3));  // @169_436bd0
  FL[2] = (eax & eax);  // @170_436bd0
  if (FL[2] == 0) goto L436e23;  // @171_436bd0
  ecx = eax;  // @172_436bd0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(10), (u32)(0));  // @173_436bd0
  ecx = edx = 0;  // @174_436bd0
  goto L436e25;  // @175_436bd0
  L436e23:;
  eax = 0;  // @177_436bd0
  FL[3] = eax;  // @178_436bd0
  L436e25:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4924), &v, sizeof v); }  // @180_436bd0
  ecx = esi;  // @181_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @182_436bd0
  reg.state = (s32)((u32)(4294967295));  // @183_436bd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4928), &v, sizeof v); }  // @184_436bd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(7225804));  // @185_436bd0
  ecx = edx = 0;  // @186_436bd0
  FL[2] = (eax & eax);  // @187_436bd0
  if (FL[2] == 0) goto L436e63;  // @188_436bd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @189_436bd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; });  // @190_436bd0
  eax = esi;  // @191_436bd0
  SEH_LEAVE();  // @192_436bd0
  return eax;  // @193_436bd0
  L436e63:;
  eax = ext_41e290_cdecl1((u32)(35));  // @195_436bd0
  ecx = edx = 0;  // @196_436bd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @197_436bd0
  reg.state = (s32)((u32)(4));  // @198_436bd0
  FL[2] = (eax & eax);  // @199_436bd0
  if (FL[2] == 0) goto L436e93;  // @200_436bd0
  PV[6] = (u32)(esi);  // @201_436bd0
  ecx = eax;  // @202_436bd0
  eax = ext_4364e0_thiscall5(ecx, PV[6], (u32)(7225804), (u32)(6793340), (u32)(0));  // @203_436bd0
  ecx = edx = 0;  // @204_436bd0
  edx = eax;  // @205_436bd0
  goto L436e95;  // @206_436bd0
  L436e93:;
  edx = 0;  // @208_436bd0
  FL[3] = edx;  // @209_436bd0
  L436e95:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4628), sizeof v); (u32)v; });  // @211_436bd0
  PV[7] = (u32)(edx);  // @212_436bd0
  reg.state = (s32)((u32)(4294967295));  // @213_436bd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_436bd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7]);  // @215_436bd0
  ecx = edx = 0;  // @216_436bd0
  eax = esi;  // @217_436bd0
  SEH_LEAVE();  // @218_436bd0
  return eax;  // @219_436bd0
}
PCREG(436bd0, lifted_436bd0);

extern "C" u32 THISCALL lifted_53ac90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66a9f6);  // @h_53ac90
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @0_53ac90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_53ac90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 244), &v, sizeof v); }  // @2_53ac90
  FL[2] = (edi & edi);  // @3_53ac90
  if (FL[2] != 0) goto L53acd8;  // @4_53ac90
  L53acd1:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @6_53ac90
  FL[3] = (eax & 0xff);  // @7_53ac90
  goto L53b0d9;  // @8_53ac90
  L53acd8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @11_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @12_53ac90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 256), &v, sizeof v); }  // @13_53ac90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 21246), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @14_53ac90
  if (FL[0] == FL[1]) goto L53acd1;  // @15_53ac90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_53ac90
  ecx = (u32)(EBP - 236);  // @17_53ac90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @18_53ac90
  eax = ext_4ccba0_thiscall1(ecx);  // @19_53ac90
    // @20_53ac90
  ecx = (u32)(EBP - 316);  // @21_53ac90
  reg.state = (s32)((u32)(0));  // @22_53ac90
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(7));  // @23_53ac90
  ecx = edx = 0;  // @24_53ac90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @25_53ac90
  reg.state = (s32)((u32)(1));  // @26_53ac90
  if (FL[0] != FL[1]) goto L53ad57;  // @27_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_53ac90
  ecx = ebx;  // @29_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_53ac90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_53ac90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1632)))(ecx);  // @33_53ac90
  ecx = edx = 0;  // @34_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_53ac90
  PV[0] = (u32)(eax);  // @36_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @37_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 88)))(ecx, PV[0]);  // @38_53ac90
  ecx = edx = 0;  // @39_53ac90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; });  // @40_53ac90
  goto L53ad5f;  // @41_53ac90
  L53ad57:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @43_53ac90
  eax = ext_4db3b0_thiscall1(ecx);  // @44_53ac90
  ecx = edx = 0;  // @45_53ac90
  L53ad5f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @47_53ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @48_53ac90
  if (FL[0] != FL[1]) goto L53ad87;  // @49_53ac90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_53ac90
  eax = (u32)(EBP - 28);  // @51_53ac90
  PV[1] = (u32)(eax);  // @52_53ac90
  eax = (u32)(EBP - 64);  // @53_53ac90
  ecx = ebx;  // @54_53ac90
  PV[2] = (u32)(eax);  // @55_53ac90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 928)))(ecx, PV[2], PV[1]);  // @56_53ac90
  ecx = edx = 0;  // @57_53ac90
  PV[3] = (u32)(eax);  // @58_53ac90
  ecx = ebx;  // @59_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 912)))(ecx, PV[3]);  // @60_53ac90
  ecx = edx = 0;  // @61_53ac90
  goto L53ad9c;  // @62_53ac90
  L53ad87:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @64_53ac90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @65_53ac90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @66_53ac90
  L53ad9c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_53ac90
  ecx = (u32)(EBP - 28);  // @69_53ac90
  PV[4] = (u32)(ecx);  // @70_53ac90
  ecx = ebx;  // @71_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[4]);  // @72_53ac90
  ecx = edx = 0;  // @73_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_53ac90
  PV[5] = (u32)(ebx);  // @75_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @76_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @78_53ac90
  ecx = edx = 0;  // @79_53ac90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; });  // @80_53ac90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 252), &v, sizeof v); }  // @81_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_53ac90
  FL[2] = (ecx & ecx);  // @83_53ac90
  if (FL[2] == 0) goto L53aeb3;  // @84_53ac90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_53ac90
  eax = (u32)(EBP - 288);  // @86_53ac90
  PV[6] = (u32)(eax);  // @87_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[6]);  // @88_53ac90
  ecx = edx = 0;  // @89_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @90_53ac90
  edx = (u32)(EBP - 288);  // @91_53ac90
  PV[7] = (u32)(edx);  // @92_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[7]);  // @94_53ac90
  ecx = edx = 0;  // @95_53ac90
  edi = eax;  // @96_53ac90
  FL[2] = (edi & edi);  // @97_53ac90
  if (FL[2] == 0) goto L53aeb3;  // @98_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; });  // @99_53ac90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; });  // @100_53ac90
  L53ae01:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @102_53ac90
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @103_53ac90
  if ((s32)FL[0] <= (s32)FL[1]) goto L53ae8f;  // @104_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @105_53ac90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = eax;  // @106_53ac90
  if (FL[0] == FL[1]) goto L53ae8f;  // @107_53ac90
  eax = (u32)(EBP - 28);  // @108_53ac90
  PV[8] = (u32)(eax);  // @109_53ac90
  edx = (u32)(edi + 12);  // @110_53ac90
  ecx = (u32)(EBP - 272);  // @111_53ac90
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @112_53ac90
  ecx = edx = 0;  // @113_53ac90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 272) + 0), 4); v; });  // @114_53ac90
  X1[1] = 0;  // @115_53ac90
  X1[2] = 0;  // @116_53ac90
  X1[3] = 0;  // @117_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 268) + 0), 4); v; });  // @118_53ac90
  X0[1] = 0;  // @119_53ac90
  X0[2] = 0;  // @120_53ac90
  X0[3] = 0;  // @121_53ac90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @122_53ac90
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @123_53ac90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @124_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 0), 4); v; });  // @125_53ac90
  X0[1] = 0;  // @126_53ac90
  X0[2] = 0;  // @127_53ac90
  X0[3] = 0;  // @128_53ac90
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @129_53ac90
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @130_53ac90
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @131_53ac90
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @132_53ac90
  ecx = edx = 0;  // @133_53ac90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @134_53ac90
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @135_53ac90
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X0[0], 4);  // @136_53ac90
  if (FL[0] != FL[1]) goto L53ae76;  // @137_53ac90
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; });  // @138_53ac90
  X1[1] = 0;  // @139_53ac90
  X1[2] = 0;  // @140_53ac90
  X1[3] = 0;  // @141_53ac90
  goto L53ae7e;  // @142_53ac90
  L53ae76:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; });  // @144_53ac90
  X1[1] = 0;  // @145_53ac90
  X1[2] = 0;  // @146_53ac90
  X1[3] = 0;  // @147_53ac90
  L53ae7e:;
  FC0 = U2F(X1[0]); FC1 = U2F(X0[0]);  // @149_53ac90
  if (((!(FC0 >= FC1)) || (!((FC0 < FC1) || (FC0 > FC1))))) goto L53ae8f;  // @150_53ac90
  PV[9] = (u32)(edi);  // @151_53ac90
  ecx = (u32)(EBP - 236);  // @152_53ac90
  eax = ext_4cd540_thiscall2(ecx, PV[9]);  // @153_53ac90
  ecx = edx = 0;  // @154_53ac90
  L53ae8f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @156_53ac90
  edx = (u32)(EBP - 288);  // @157_53ac90
  PV[10] = (u32)(edx);  // @158_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[10]);  // @160_53ac90
  ecx = edx = 0;  // @161_53ac90
  edi = eax;  // @162_53ac90
  FL[2] = (edi & edi);  // @163_53ac90
  if (FL[2] != 0) goto L53ae01;  // @164_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; });  // @165_53ac90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @166_53ac90
  L53aeb3:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; });  // @168_53ac90
  ecx = (u32)(EBP - 276);  // @169_53ac90
  eax = (u32)(edi + 8);  // @170_53ac90
  FL[0] = eax; FL[1] = ecx;  // @171_53ac90
  if (FL[0] == FL[1]) goto L53aec8;  // @172_53ac90
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @173_53ac90
  L53aec8:;
  ecx = (u32)(EBP - 236);  // @175_53ac90
  eax = ext_4cdd40_thiscall1(ecx);  // @176_53ac90
    // @177_53ac90
  FL[2] = (eax & eax);  // @178_53ac90
  if (FL[2] == 0) goto L53b0c1;  // @179_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @180_53ac90
  X1[0] = 0;  // @181_53ac90
  X1[1] = 0;  // @182_53ac90
  X1[2] = 0;  // @183_53ac90
  X1[3] = 0;  // @184_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @185_53ac90
  X0[1] = 0;  // @186_53ac90
  X0[2] = 0;  // @187_53ac90
  X0[3] = 0;  // @188_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @189_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @190_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @191_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53af35;  // @192_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @193_53ac90
  X0[1] = 0;  // @194_53ac90
  X0[2] = 0;  // @195_53ac90
  X0[3] = 0;  // @196_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @197_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @198_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @199_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53af35;  // @200_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @202_53ac90
  { unsigned long long rv_ = ((unsigned long long(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)rv_; edx = (u32)(rv_ >> 32); }  // @203_53ac90
  ecx = 0;  // @204_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_53ac90
  PV[11] = (u32)(edx);  // @206_53ac90
  PV[12] = (u32)(eax);  // @207_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @208_53ac90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[12], PV[11], (u32)(6957900));  // @209_53ac90
  ecx = edx = 0;  // @210_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @211_53ac90
  L53af35:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @213_53ac90
  FL[2] = (esi & esi);  // @214_53ac90
  if (FL[2] == 0) goto L53af86;  // @215_53ac90
  ecx = (u32)(EBP - 236);  // @216_53ac90
  eax = ext_4cdd40_thiscall1(ecx);  // @217_53ac90
    // @218_53ac90
  FL[2] = (eax & eax);  // @219_53ac90
  if (FL[2] == 0) goto L53af80;  // @220_53ac90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @221_53ac90
  if (FL[0] != FL[1]) goto L53af60;  // @222_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @223_53ac90
  ecx = ebx;  // @224_53ac90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1672)))(ecx);  // @225_53ac90
  ecx = edx = 0;  // @226_53ac90
  PV[13] = (u32)(eax);  // @227_53ac90
  goto L53af62;  // @228_53ac90
  L53af60:;
  PV[13] = 0;
  L53af62:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; });  // @231_53ac90
  eax = (u32)(EBP - 28);  // @232_53ac90
  PV[14] = (u32)(eax);  // @233_53ac90
  eax = (u32)(EBP - 316);  // @234_53ac90
  PV[15] = (u32)(eax);  // @235_53ac90
  eax = (u32)(EBP - 236);  // @236_53ac90
  PV[16] = (u32)(eax);  // @237_53ac90
  PV[17] = (u32)(esi);  // @238_53ac90
  eax = ext_53b380_thiscall6(ecx, PV[17], PV[16], PV[15], PV[14], PV[13]);  // @239_53ac90
  ecx = edx = 0;  // @240_53ac90
  L53af80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @242_53ac90
  L53af86:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @244_53ac90
  X0[1] = 0;  // @245_53ac90
  X0[2] = 0;  // @246_53ac90
  X0[3] = 0;  // @247_53ac90
  X1[0] = 0;  // @248_53ac90
  X1[1] = 0;  // @249_53ac90
  X1[2] = 0;  // @250_53ac90
  X1[3] = 0;  // @251_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @252_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @253_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @254_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53afdd;  // @255_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @256_53ac90
  X0[1] = 0;  // @257_53ac90
  X0[2] = 0;  // @258_53ac90
  X0[3] = 0;  // @259_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @260_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @261_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @262_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53afdd;  // @263_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @264_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @265_53ac90
  { unsigned long long rv_ = ((unsigned long long(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)rv_; edx = (u32)(rv_ >> 32); }  // @266_53ac90 (hand fix: 2 args, no pending push)
  ecx = 0;  // @267_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @268_53ac90
  PV[18] = (u32)(edx);  // @269_53ac90
  PV[19] = (u32)(eax);  // @270_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @271_53ac90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[19], PV[18], (u32)(6957900));  // @272_53ac90
  ecx = edx = 0;  // @273_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @274_53ac90
  X1[0] = 0;  // @275_53ac90
  X1[1] = 0;  // @276_53ac90
  X1[2] = 0;  // @277_53ac90
  X1[3] = 0;  // @278_53ac90
  L53afdd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @280_53ac90
  X0[1] = 0;  // @281_53ac90
  X0[2] = 0;  // @282_53ac90
  X0[3] = 0;  // @283_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @284_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @285_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @286_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53b028;  // @287_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @288_53ac90
  X0[1] = 0;  // @289_53ac90
  X0[2] = 0;  // @290_53ac90
  X0[3] = 0;  // @291_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @292_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @293_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @294_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53b028;  // @295_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @296_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @297_53ac90
  { unsigned long long rv_ = ((unsigned long long(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)rv_; edx = (u32)(rv_ >> 32); }  // @298_53ac90
  ecx = 0;  // @299_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @300_53ac90
  PV[20] = (u32)(edx);  // @301_53ac90
  PV[21] = (u32)(eax);  // @302_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @303_53ac90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[21], PV[20], (u32)(6957916));  // @304_53ac90
  ecx = edx = 0;  // @305_53ac90
  L53b028:;
  ecx = (u32)(EBP - 316);  // @307_53ac90
  eax = ext_4cdd40_thiscall1(ecx);  // @308_53ac90
    // @309_53ac90
  FL[2] = (eax & eax);  // @310_53ac90
  if (FL[2] == 0) goto L53b06d;  // @311_53ac90
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @312_53ac90
  if (FL[0] != FL[1]) goto L53b04f;  // @313_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @314_53ac90
  ecx = (u32)(EBP - 316);  // @315_53ac90
  PV[22] = (u32)(ecx);  // @316_53ac90
  ecx = ebx;  // @317_53ac90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1628)))(ecx, PV[22]);  // @318_53ac90
  ecx = edx = 0;  // @319_53ac90
  goto L53b06d;  // @320_53ac90
  L53b04f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @322_53ac90
  eax = (u32)(EBP - 316);  // @323_53ac90
  PV[23] = (u32)(eax);  // @324_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; });  // @325_53ac90
  ecx = ebx;  // @326_53ac90
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @327_53ac90
  PV[24] = (u32)(eax);  // @328_53ac90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[24], PV[23], (u32)(0));  // @329_53ac90
  ecx = edx = 0;  // @330_53ac90
  L53b06d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @332_53ac90
  X1[0] = 0;  // @333_53ac90
  X1[1] = 0;  // @334_53ac90
  X1[2] = 0;  // @335_53ac90
  X1[3] = 0;  // @336_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @337_53ac90
  X0[1] = 0;  // @338_53ac90
  X0[2] = 0;  // @339_53ac90
  X0[3] = 0;  // @340_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @341_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @342_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @343_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53b0c1;  // @344_53ac90
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @345_53ac90
  X0[1] = 0;  // @346_53ac90
  X0[2] = 0;  // @347_53ac90
  X0[3] = 0;  // @348_53ac90
  FC0 = U2F(X0[0]); FC1 = U2F(X1[0]);  // @349_53ac90
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) << 8);  // @350_53ac90
  FL[2] = ((u32)(0x02 | (!(FC0 >= FC1) ? 1 : 0) | (((FC0 != FC0) || (FC1 != FC1)) ? 4 : 0) | ((!((FC0 < FC1) || (FC0 > FC1))) ? 0x40 : 0)) & 68);  // @351_53ac90
  if (__builtin_parity(FL[2] & 0xff)) goto L53b0c1;  // @352_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @353_53ac90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @354_53ac90
  { unsigned long long rv_ = ((unsigned long long(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)rv_; edx = (u32)(rv_ >> 32); }  // @355_53ac90
  ecx = 0;  // @356_53ac90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @357_53ac90
  PV[25] = (u32)(edx);  // @358_53ac90
  PV[26] = (u32)(eax);  // @359_53ac90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @360_53ac90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[26], PV[25], (u32)(6957916));  // @361_53ac90
  ecx = edx = 0;  // @362_53ac90
  L53b0c1:;
  ecx = (u32)(EBP - 316);  // @364_53ac90
  eax = ext_4ccfe0_thiscall1(ecx);  // @365_53ac90
  ecx = edx = 0;  // @366_53ac90
  ecx = (u32)(EBP - 236);  // @367_53ac90
  eax = ext_4ccf60_thiscall1(ecx);  // @368_53ac90
  ecx = edx = 0;  // @369_53ac90
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @370_53ac90
  L53b0d9:;
  SEH_LEAVE();  // @372_53ac90
  ext_633654(G(u32, 0x6f5630));  // @373_53ac90
  return eax;  // @374_53ac90
}
PCREG(53ac90, lifted_53ac90);

