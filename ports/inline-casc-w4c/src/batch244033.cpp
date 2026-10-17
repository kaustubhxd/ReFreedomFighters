// batch244033.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_459fc0_fastcall3(u32, u32, u32) __asm__("ext_459fc0");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 FASTCALL ext_4dfd10_fastcall2(u32, u32) __asm__("ext_4dfd10");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 FASTCALL ext_4e09e0_fastcall2(u32, u32) __asm__("ext_4e09e0");
extern "C" u32 STDCALL ext_410f26_stdcall3(u32, u32, u32) __asm__("ext_410f26");
extern "C" u32 STDCALL ext_411009_stdcall2(u32, u32) __asm__("ext_411009");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4db520_thiscall1(u32) __asm__("ext_4db520");
extern "C" u32 THISCALL ext_648a40_thiscall2(u32, u32) __asm__("ext_648a40");
extern "C" u32 THISCALL ext_64abb0_thiscall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_64abb0");
extern "C" u32 THISCALL ext_64d030_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_64d030");
extern "C" u32 THISCALL ext_658d80_thiscall1(u32) __asm__("ext_658d80");
extern "C" u32 THISCALL ext_658db0_thiscall1(u32) __asm__("ext_658db0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_54cec0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_54cec0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32797), sizeof v); (u32)v; });  // @1_54cec0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_54cec0
  FL[0] = edx; FL[1] = (u32)(65536);  // @3_54cec0
  if (FL[0] == FL[1]) goto L54d2e0;  // @4_54cec0
  L54cee0:;
  eax = edx;  // @6_54cec0
  FL[0] = eax; FL[1] = (u32)(4);  // @7_54cec0
  if (FL[0] > FL[1]) goto L54d00a;  // @8_54cec0
  if (FL[0] == FL[1]) goto L54cfd0;  // @9_54cec0
  eax = (eax - 1);  // @10_54cec0
  FL[3] = eax;  // @11_54cec0
  FL[0] = eax; FL[1] = (u32)(1);  // @12_54cec0
  if (FL[0] > FL[1]) goto L54d26a;  // @13_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_54cec0
  ecx = esi;  // @15_54cec0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @16_54cec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[0]);  // @17_54cec0
  ecx = edx = 0;  // @18_54cec0
  edx = eax;  // @19_54cec0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @20_54cec0
  FL[2] = (edx & edx);  // @21_54cec0
  if (FL[2] == 0) goto L54d2c0;  // @22_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_54cec0
  if (FL[0] == FL[1]) goto L54d2c0;  // @24_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32865), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @25_54cec0
  if (FL[0] != FL[1]) goto L54cf2f;  // @26_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_54cec0
  if ((s32)FL[0] < (s32)FL[1]) goto L54d2c0;  // @28_54cec0
  L54cf2f:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; });  // @30_54cec0
  ecx = 0;  // @31_54cec0
  FL[3] = ecx;  // @32_54cec0
  FL[2] = (ebx & ebx);  // @33_54cec0
  if ((s32)FL[2] <= 0) goto L54cf73;  // @34_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @35_54cec0
  L54cf41:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @37_54cec0
  FL[2] = (edx & edx);  // @38_54cec0
  if (FL[2] == 0) goto L54cf5c;  // @39_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 97), sizeof v); (u32)v; });  // @40_54cec0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @41_54cec0
  if (FL[0] != FL[1]) goto L54cf56;  // @42_54cec0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 125), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @43_54cec0
  if (FL[0] != FL[1]) goto L54cf63;  // @44_54cec0
  L54cf56:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @46_54cec0
  L54cf5c:;
  ecx = (ecx + 1);  // @48_54cec0
  FL[3] = ecx;  // @49_54cec0
  FL[0] = ecx; FL[1] = ebx;  // @50_54cec0
  if ((s32)FL[0] < (s32)FL[1]) goto L54cf41;  // @51_54cec0
  goto L54cf70;  // @52_54cec0
  L54cf63:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @54_54cec0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx*4), sizeof v); (u32)v; });  // @55_54cec0
  FL[2] = (ebx & ebx);  // @56_54cec0
  if (FL[2] != 0) goto L54cfc3;  // @57_54cec0
  L54cf70:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @59_54cec0
  L54cf73:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @61_54cec0
  if (FL[0] != FL[1]) goto L54cf83;  // @62_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_54cec0
  if (FL[0] == FL[1]) goto L54d2c0;  // @64_54cec0
  L54cf83:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_54cec0
  ecx = esi;  // @67_54cec0
  PV[1] = (u32)(edx);  // @68_54cec0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @69_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[2], PV[1], (u32)(1));  // @70_54cec0
  ecx = edx = 0;  // @71_54cec0
  ebx = eax;  // @72_54cec0
  FL[2] = (ebx & ebx);  // @73_54cec0
  if (FL[2] == 0) goto L54d2c0;  // @74_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @75_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @76_54cec0
  ecx = (ecx & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @77_54cec0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 123), &v, sizeof v); }  // @78_54cec0
  ecx = ebx;  // @79_54cec0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @80_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @81_54cec0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @82_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[4], PV[3]);  // @83_54cec0
  ecx = edx = 0;  // @84_54cec0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @85_54cec0
  if (FL[2] != 0) goto L54cfc3;  // @86_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_54cec0
  ecx = ebx;  // @88_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @89_54cec0
  ecx = edx = 0;  // @90_54cec0
  goto L54d2c0;  // @91_54cec0
  L54cfc3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @93_54cec0
  ecx = ebx;  // @94_54cec0
  PV[5] = (u32)(edi);  // @95_54cec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, PV[5]);  // @96_54cec0
  ecx = edx = 0;  // @97_54cec0
  goto L54d2c0;  // @98_54cec0
  L54cfd0:;
  ebx = 0;  // @100_54cec0
  FL[3] = ebx;  // @101_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; }); FL[1] = ebx;  // @102_54cec0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54d2c0;  // @103_54cec0
  L54cfe0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @105_54cec0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @106_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 97), sizeof v); (u32)v; });  // @107_54cec0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @108_54cec0
  if (FL[0] != FL[1]) goto L54cffc;  // @109_54cec0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 125), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @110_54cec0
  if (FL[0] == FL[1]) goto L54cffc;  // @111_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @113_54cec0
  ecx = edx = 0;  // @114_54cec0
  L54cffc:;
  ebx = (ebx + 1);  // @116_54cec0
  FL[3] = ebx;  // @117_54cec0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; });  // @118_54cec0
  if ((s32)FL[0] < (s32)FL[1]) goto L54cfe0;  // @119_54cec0
  goto L54d2c0;  // @120_54cec0
  L54d00a:;
  FL[0] = eax; FL[1] = (u32)(512);  // @122_54cec0
  if (FL[0] > FL[1]) goto L54d255;  // @123_54cec0
  if (FL[0] == FL[1]) goto L54d23a;  // @124_54cec0
  eax = (eax - (u32)(5));  // @125_54cec0
  FL[3] = eax;  // @126_54cec0
  FL[0] = eax; FL[1] = (u32)(253);  // @127_54cec0
  if (FL[0] > FL[1]) goto L54d26a;  // @128_54cec0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5559068), sizeof v); (u32)v; });  // @129_54cec0
  switch (eax) {  // @130_54cec0
  case 0: goto L54d100;  // @131_54cec0
  case 1: goto L54d0ef;  // @132_54cec0
  case 2: goto L54d142;  // @133_54cec0
  case 3: goto L54d12c;  // @134_54cec0
  case 4: goto L54d037;  // @135_54cec0
  case 5: goto L54d081;  // @136_54cec0
  case 6: goto L54d08d;  // @137_54cec0
  case 7: goto L54d099;  // @138_54cec0
  case 8: goto L54d0ac;  // @139_54cec0
  case 9: goto L54d0dc;  // @140_54cec0
  case 10: goto L54d26a;  // @141_54cec0
  default: __builtin_trap(); }  // @142_54cec0
  L54d037:;
  ebx = 0;  // @144_54cec0
  FL[3] = ebx;  // @145_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; }); FL[1] = ebx;  // @146_54cec0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54d2c0;  // @147_54cec0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @148_54cec0
  L54d050:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @150_54cec0
  FL[2] = (ecx & ecx);  // @151_54cec0
  if (FL[2] == 0) goto L54d064;  // @152_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 97), sizeof v); (u32)v; });  // @153_54cec0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @154_54cec0
  if (FL[0] != FL[1]) goto L54d064;  // @155_54cec0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 125), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @156_54cec0
  if (FL[0] != FL[1]) goto L54d075;  // @157_54cec0
  L54d064:;
  ebx = (ebx + 1);  // @159_54cec0
  FL[3] = ebx;  // @160_54cec0
  edx = (edx + (u32)(4));  // @161_54cec0
  FL[3] = edx;  // @162_54cec0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; });  // @163_54cec0
  if ((s32)FL[0] < (s32)FL[1]) goto L54d050;  // @164_54cec0
  goto L54d2c0;  // @165_54cec0
  L54d075:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_54cec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(1));  // @168_54cec0
  ecx = edx = 0;  // @169_54cec0
  goto L54d2c0;  // @170_54cec0
  L54d081:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @172_54cec0
  ecx = esi;  // @173_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @174_54cec0
  ecx = edx = 0;  // @175_54cec0
  goto L54d2c0;  // @176_54cec0
  L54d08d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @178_54cec0
  ecx = esi;  // @179_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @180_54cec0
  ecx = edx = 0;  // @181_54cec0
  goto L54d2c0;  // @182_54cec0
  L54d099:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @184_54cec0
  eax = (u32)(edi + 12);  // @185_54cec0
  PV[6] = (u32)(eax);  // @186_54cec0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @187_54cec0
  ecx = esi;  // @188_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 100)))(ecx, PV[7], PV[6]);  // @189_54cec0
  ecx = edx = 0;  // @190_54cec0
  goto L54d2c0;  // @191_54cec0
  L54d0ac:;
  edx = (u32)(edi + 12);  // @193_54cec0
  ecx = edx;  // @194_54cec0
  ebx = (u32)(ecx + 1);  // @195_54cec0
  L54d0b4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @197_54cec0
  ecx = (ecx + 1);  // @198_54cec0
  FL[3] = ecx;  // @199_54cec0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @200_54cec0
  if (FL[2] != 0) goto L54d0b4;  // @201_54cec0
  ecx = (ecx - ebx);  // @202_54cec0
  FL[3] = ecx;  // @203_54cec0
  if (FL[3] == 0) goto L54d2c0;  // @204_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @205_54cec0
  ecx = esi;  // @206_54cec0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32821), &v, sizeof v); }  // @207_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @208_54cec0
  PV[8] = (u32)(edx);  // @209_54cec0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @210_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[9], PV[8]);  // @211_54cec0
  ecx = edx = 0;  // @212_54cec0
  goto L54d2c0;  // @213_54cec0
  L54d0dc:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @215_54cec0
  eax = (u32)(edi + 12);  // @216_54cec0
  PV[10] = (u32)(eax);  // @217_54cec0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @218_54cec0
  ecx = esi;  // @219_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[11], PV[10]);  // @220_54cec0
  ecx = edx = 0;  // @221_54cec0
  goto L54d2c0;  // @222_54cec0
  L54d0ef:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32841), sizeof v); (u32)v; });  // @224_54cec0
  PV[12] = (u32)(edi);  // @225_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @226_54cec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[12]);  // @227_54cec0
  ecx = edx = 0;  // @228_54cec0
  goto L54d2c0;  // @229_54cec0
  L54d100:;
  ebx = 0;  // @231_54cec0
  FL[3] = ebx;  // @232_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; }); FL[1] = ebx;  // @233_54cec0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54d2c0;  // @234_54cec0
  L54d110:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @236_54cec0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @237_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @238_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @239_54cec0
  ecx = edx = 0;  // @240_54cec0
  ebx = (ebx + 1);  // @241_54cec0
  FL[3] = ebx;  // @242_54cec0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; });  // @243_54cec0
  if ((s32)FL[0] < (s32)FL[1]) goto L54d110;  // @244_54cec0
  goto L54d2c0;  // @245_54cec0
  L54d12c:;
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @247_54cec0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @248_54cec0
  eax = (u32)(edi + 12);  // @249_54cec0
  PV[14] = (u32)(eax);  // @250_54cec0
  ecx = esi;  // @251_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[14], PV[13]);  // @252_54cec0
  ecx = edx = 0;  // @253_54cec0
  goto L54d2c0;  // @254_54cec0
  L54d142:;
  eax = 0;  // @256_54cec0
  FL[3] = eax;  // @257_54cec0
  ecx = 0;  // @258_54cec0
  FL[3] = ecx;  // @259_54cec0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @260_54cec0
  FL[0] = edx; FL[1] = (u32)(49);  // @261_54cec0
  if (FL[0] == FL[1]) goto L54d1ad;  // @262_54cec0
  eax = (u32)(esi + 32873);  // @263_54cec0
  ebx = 0;  // @264_54cec0
  FL[3] = ebx;  // @265_54cec0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @266_54cec0
  L54d160:;
  edx = (edx + (u32)(-64));  // @268_54cec0
  FL[3] = edx;  // @269_54cec0
  FL[0] = edx; FL[1] = (u32)(49);  // @270_54cec0
  if (FL[0] > FL[1]) goto L54d1a0;  // @271_54cec0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 5559352), sizeof v); (u32)v; });  // @272_54cec0
  switch (eax) {  // @273_54cec0
  case 0: goto L54d20e;  // @274_54cec0
  case 1: goto L54d176;  // @275_54cec0
  case 2: goto L54d1e0;  // @276_54cec0
  case 3: goto L54d1f7;  // @277_54cec0
  case 4: goto L54d1c9;  // @278_54cec0
  case 5: goto L54d186;  // @279_54cec0
  case 6: goto L54d1a0;  // @280_54cec0
  default: __builtin_trap(); }  // @281_54cec0
  L54d176:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @283_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @284_54cec0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @285_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @286_54cec0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @287_54cec0
  goto L54d1a0;  // @288_54cec0
  L54d186:;
  eax = (u32)(ebx + ecx);  // @290_54cec0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32889), &v, sizeof v); }  // @291_54cec0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32893), &v, sizeof v); }  // @292_54cec0
  L54d19f:;
  ecx = (ecx + 1);  // @294_54cec0
  FL[3] = ecx;  // @295_54cec0
  L54d1a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @297_54cec0
  L54d1a3:;
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @299_54cec0
  FL[3] = edi;  // @300_54cec0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @301_54cec0
  FL[0] = edx; FL[1] = (u32)(49);  // @302_54cec0
  if (FL[0] != FL[1]) goto L54d160;  // @303_54cec0
  L54d1ad:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 32869), &v, sizeof v); }  // @305_54cec0
  ecx = esi;  // @306_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @307_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @308_54cec0
  ecx = edx = 0;  // @309_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @310_54cec0
  ecx = esi;  // @311_54cec0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 124)))(ecx);  // @312_54cec0
  ecx = edx = 0;  // @313_54cec0
  goto L54d2c0;  // @314_54cec0
  L54d1c9:;
  eax = (u32)(ebx + ecx);  // @316_54cec0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32889), &v, sizeof v); }  // @317_54cec0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32893), &v, sizeof v); }  // @318_54cec0
  goto L54d19f;  // @319_54cec0
  L54d1e0:;
  eax = (u32)(ebx + ecx);  // @321_54cec0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32889), &v, sizeof v); }  // @322_54cec0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32893), &v, sizeof v); }  // @323_54cec0
  goto L54d19f;  // @324_54cec0
  L54d1f7:;
  eax = (u32)(ebx + ecx);  // @326_54cec0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32889), &v, sizeof v); }  // @327_54cec0
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(esi + eax*8 + 32893), &v, sizeof v); }  // @328_54cec0
  goto L54d19f;  // @329_54cec0
  L54d20e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @331_54cec0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @332_54cec0
  PV[16] = (u32)(edx);  // @333_54cec0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @334_54cec0
  ecx = esi;  // @335_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @336_54cec0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[16], PV[15]);  // @337_54cec0
  ecx = edx = 0;  // @338_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @339_54cec0
  ebx = (ebx + (u32)(34));  // @340_54cec0
  FL[3] = ebx;  // @341_54cec0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }) + (u32)(272))); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @342_54cec0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @343_54cec0
  eax = (eax + 1);  // @344_54cec0
  FL[3] = eax;  // @345_54cec0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @346_54cec0
  ecx = 0;  // @347_54cec0
  FL[3] = ecx;  // @348_54cec0
  goto L54d1a3;  // @349_54cec0
  L54d23a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @351_54cec0
  { u32 v = (u32)((u32)(187)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @352_54cec0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @353_54cec0
  X0[1] = 0;  // @354_54cec0
  X0[2] = 0;  // @355_54cec0
  X0[3] = 0;  // @356_54cec0
  PV[17] = (u32)(ecx);  // @357_54cec0
  ecx = esi;  // @358_54cec0
  PV[18] = X0[0];  // @359_54cec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[18]);  // @360_54cec0
  ecx = edx = 0;  // @361_54cec0
  goto L54d2c0;  // @362_54cec0
  L54d255:;
  FL[0] = eax; FL[1] = (u32)(4096);  // @364_54cec0
  if (FL[0] == FL[1]) goto L54d2b9;  // @365_54cec0
  FL[0] = eax; FL[1] = (u32)(4352);  // @366_54cec0
  if (FL[0] == FL[1]) goto L54d2a9;  // @367_54cec0
  FL[0] = eax; FL[1] = (u32)(4608);  // @368_54cec0
  if (FL[0] == FL[1]) goto L54d27a;  // @369_54cec0
  L54d26a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @371_54cec0
  FL[2] = (eax & eax);  // @372_54cec0
  if (FL[2] == 0) goto L54d277;  // @373_54cec0
  eax = ((u32(STDCALL *)(void))(eax))();  // @374_54cec0
  ecx = edx = 0;  // @375_54cec0
  goto L54d2c0;  // @376_54cec0
  L54d277:;
  __builtin_trap();  // @378_54cec0
  L54d27a:;
  ebx = 0;  // @380_54cec0
  FL[3] = ebx;  // @381_54cec0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; }); FL[1] = ebx;  // @382_54cec0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54d2c0;  // @383_54cec0
  L54d284:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32829), sizeof v); (u32)v; });  // @385_54cec0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @386_54cec0
  FL[2] = (ecx & ecx);  // @387_54cec0
  if (FL[2] == 0) goto L54d29e;  // @388_54cec0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 125), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @389_54cec0
  if (FL[0] == FL[1]) goto L54d29e;  // @390_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @391_54cec0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(1));  // @392_54cec0
  ecx = edx = 0;  // @393_54cec0
  L54d29e:;
  ebx = (ebx + 1);  // @395_54cec0
  FL[3] = ebx;  // @396_54cec0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32861), sizeof v); (u32)v; });  // @397_54cec0
  if ((s32)FL[0] < (s32)FL[1]) goto L54d284;  // @398_54cec0
  goto L54d2c0;  // @399_54cec0
  L54d2a9:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7421464), &v, sizeof v); }  // @401_54cec0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7421465), &v, sizeof v); }  // @402_54cec0
  goto L54d2c0;  // @403_54cec0
  L54d2b9:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32796), &v, sizeof v); }  // @405_54cec0
  L54d2c0:;
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @407_54cec0
  FL[3] = edi;  // @408_54cec0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @409_54cec0
  FL[0] = edx; FL[1] = (u32)(65536);  // @410_54cec0
  if (FL[0] != FL[1]) goto L54cee0;  // @411_54cec0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32797), sizeof v); (u32)v; });  // @412_54cec0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @413_54cec0
  return eax;  // @414_54cec0
  L54d2e0:;
  eax = edi;  // @416_54cec0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @417_54cec0
  return eax;  // @418_54cec0
}
PCREG(54cec0, lifted_54cec0);

extern "C" u32 THISCALL lifted_617e20(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_617e20
  X1[0] = 0;  // @1_617e20
  X1[1] = 0;  // @2_617e20
  X1[2] = 0;  // @3_617e20
  X1[3] = 0;  // @4_617e20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 512), &v, sizeof v); }  // @5_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_617e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @8_617e20
  X0[1] = 0;  // @9_617e20
  X0[2] = 0;  // @10_617e20
  X0[3] = 0;  // @11_617e20
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 504), &v, sizeof v); }  // @12_617e20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @13_617e20
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @14_617e20
  if (__builtin_parity(FL[2] & 0xff)) goto L617ea1;  // @15_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @16_617e20
  X0[1] = 0;  // @17_617e20
  X0[2] = 0;  // @18_617e20
  X0[3] = 0;  // @19_617e20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @20_617e20
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @21_617e20
  if (__builtin_parity(FL[2] & 0xff)) goto L617ea1;  // @22_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @24_617e20
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @25_617e20
  ecx = 0;  // @26_617e20 (edx = high dword of the 64-bit result)
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_617e20
  PV[0] = (u32)(edx);  // @28_617e20
  PV[1] = (u32)(eax);  // @29_617e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(7069356));  // @31_617e20
  ecx = edx = 0;  // @32_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_617e20
  L617ea1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @35_617e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490132), sizeof v); (u32)v; });  // @36_617e20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4983), sizeof v); (u32)v; });  // @37_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @38_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @39_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 512), sizeof v); (u32)v; });  // @40_617e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @41_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @42_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 512), &v, sizeof v); }  // @43_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @44_617e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @45_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490040), sizeof v); (u32)v; }); FL[1] = edx;  // @46_617e20
  if (FL[0] == FL[1]) goto L617ef5;  // @47_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @48_617e20
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7490040), &v, sizeof v); }  // @49_617e20
  PV[2] = (u32)(edx);  // @50_617e20
  PV[3] = (u32)(eax);  // @51_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @52_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 304)))(ecx, PV[3], PV[2]);  // @53_617e20
  ecx = edx = 0;  // @54_617e20
  L617ef5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_617e20
  PV[4] = (u32)(ebx);  // @57_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[4], (u32)(0), (u32)(24), (u32)(0));  // @58_617e20
  ecx = edx = 0;  // @59_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_617e20
  PV[5] = (u32)(ebx);  // @61_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 200)))(ecx, PV[5], (u32)(140), (u32)(0));  // @62_617e20
  ecx = edx = 0;  // @63_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; });  // @64_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5122), sizeof v); (u32)v; });  // @65_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @66_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5130), sizeof v); (u32)v; });  // @67_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 516), &v, sizeof v); }  // @68_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @69_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @70_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @71_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 8), 4); v; });  // @72_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 12), 4); v; });  // @73_617e20
  __builtin_memcpy((void *)((u32)(EBP - 308) + 0), &X0[0], 4);  // @74_617e20
  __builtin_memcpy((void *)((u32)(EBP - 308) + 4), &X0[1], 4);  // @75_617e20
  __builtin_memcpy((void *)((u32)(EBP - 308) + 8), &X0[2], 4);  // @76_617e20
  __builtin_memcpy((void *)((u32)(EBP - 308) + 12), &X0[3], 4);  // @77_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 0), 4); v; });  // @78_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 4), 4); v; });  // @79_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 8), 4); v; });  // @80_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 12), 4); v; });  // @81_617e20
  __builtin_memcpy((void *)((u32)(EBP - 292) + 0), &X0[0], 4);  // @82_617e20
  __builtin_memcpy((void *)((u32)(EBP - 292) + 4), &X0[1], 4);  // @83_617e20
  __builtin_memcpy((void *)((u32)(EBP - 292) + 8), &X0[2], 4);  // @84_617e20
  __builtin_memcpy((void *)((u32)(EBP - 292) + 12), &X0[3], 4);  // @85_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @86_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 4), 4); v; });  // @87_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 8), 4); v; });  // @88_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 12), 4); v; });  // @89_617e20
  __builtin_memcpy((void *)((u32)(EBP - 276) + 0), &X0[0], 4);  // @90_617e20
  __builtin_memcpy((void *)((u32)(EBP - 276) + 4), &X0[1], 4);  // @91_617e20
  __builtin_memcpy((void *)((u32)(EBP - 276) + 8), &X0[2], 4);  // @92_617e20
  __builtin_memcpy((void *)((u32)(EBP - 276) + 12), &X0[3], 4);  // @93_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 0), 4); v; });  // @94_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 4), 4); v; });  // @95_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 8), 4); v; });  // @96_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 12), 4); v; });  // @97_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 36), sizeof v); (u32)v; });  // @98_617e20
  __builtin_memcpy((void *)((u32)(EBP - 260) + 0), &X0[0], 4);  // @99_617e20
  __builtin_memcpy((void *)((u32)(EBP - 260) + 4), &X0[1], 4);  // @100_617e20
  __builtin_memcpy((void *)((u32)(EBP - 260) + 8), &X0[2], 4);  // @101_617e20
  __builtin_memcpy((void *)((u32)(EBP - 260) + 12), &X0[3], 4);  // @102_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @103_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @104_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 8), 4); v; });  // @105_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 12), 4); v; });  // @106_617e20
  __builtin_memcpy((void *)((u32)(EBP - 244) + 0), &X0[0], 4);  // @107_617e20
  __builtin_memcpy((void *)((u32)(EBP - 244) + 4), &X0[1], 4);  // @108_617e20
  __builtin_memcpy((void *)((u32)(EBP - 244) + 8), &X0[2], 4);  // @109_617e20
  __builtin_memcpy((void *)((u32)(EBP - 244) + 12), &X0[3], 4);  // @110_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 0), 4); v; });  // @111_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 4), 4); v; });  // @112_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 8), 4); v; });  // @113_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 12), 4); v; });  // @114_617e20
  __builtin_memcpy((void *)((u32)(EBP - 228) + 0), &X0[0], 4);  // @115_617e20
  __builtin_memcpy((void *)((u32)(EBP - 228) + 4), &X0[1], 4);  // @116_617e20
  __builtin_memcpy((void *)((u32)(EBP - 228) + 8), &X0[2], 4);  // @117_617e20
  __builtin_memcpy((void *)((u32)(EBP - 228) + 12), &X0[3], 4);  // @118_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @119_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 4), 4); v; });  // @120_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 8), 4); v; });  // @121_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 12), 4); v; });  // @122_617e20
  __builtin_memcpy((void *)((u32)(EBP - 212) + 0), &X0[0], 4);  // @123_617e20
  __builtin_memcpy((void *)((u32)(EBP - 212) + 4), &X0[1], 4);  // @124_617e20
  __builtin_memcpy((void *)((u32)(EBP - 212) + 8), &X0[2], 4);  // @125_617e20
  __builtin_memcpy((void *)((u32)(EBP - 212) + 12), &X0[3], 4);  // @126_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 0), 4); v; });  // @127_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 4), 4); v; });  // @128_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 8), 4); v; });  // @129_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 12), 4); v; });  // @130_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @131_617e20
  __builtin_memcpy((void *)((u32)(EBP - 196) + 0), &X0[0], 4);  // @132_617e20
  __builtin_memcpy((void *)((u32)(EBP - 196) + 4), &X0[1], 4);  // @133_617e20
  __builtin_memcpy((void *)((u32)(EBP - 196) + 8), &X0[2], 4);  // @134_617e20
  __builtin_memcpy((void *)((u32)(EBP - 196) + 12), &X0[3], 4);  // @135_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @136_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @137_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 8), 4); v; });  // @138_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 12), 4); v; });  // @139_617e20
  __builtin_memcpy((void *)((u32)(EBP - 372) + 0), &X0[0], 4);  // @140_617e20
  __builtin_memcpy((void *)((u32)(EBP - 372) + 4), &X0[1], 4);  // @141_617e20
  __builtin_memcpy((void *)((u32)(EBP - 372) + 8), &X0[2], 4);  // @142_617e20
  __builtin_memcpy((void *)((u32)(EBP - 372) + 12), &X0[3], 4);  // @143_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 0), 4); v; });  // @144_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 4), 4); v; });  // @145_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 8), 4); v; });  // @146_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 16) + 12), 4); v; });  // @147_617e20
  __builtin_memcpy((void *)((u32)(EBP - 356) + 0), &X0[0], 4);  // @148_617e20
  __builtin_memcpy((void *)((u32)(EBP - 356) + 4), &X0[1], 4);  // @149_617e20
  __builtin_memcpy((void *)((u32)(EBP - 356) + 8), &X0[2], 4);  // @150_617e20
  __builtin_memcpy((void *)((u32)(EBP - 356) + 12), &X0[3], 4);  // @151_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 0), 4); v; });  // @152_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 4), 4); v; });  // @153_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 8), 4); v; });  // @154_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 32) + 12), 4); v; });  // @155_617e20
  __builtin_memcpy((void *)((u32)(EBP - 340) + 0), &X0[0], 4);  // @156_617e20
  __builtin_memcpy((void *)((u32)(EBP - 340) + 4), &X0[1], 4);  // @157_617e20
  __builtin_memcpy((void *)((u32)(EBP - 340) + 8), &X0[2], 4);  // @158_617e20
  __builtin_memcpy((void *)((u32)(EBP - 340) + 12), &X0[3], 4);  // @159_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 0), 4); v; });  // @160_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 4), 4); v; });  // @161_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 8), 4); v; });  // @162_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 48) + 12), 4); v; });  // @163_617e20
  eax = (u32)(EBP - 244);  // @164_617e20
  PV[6] = (u32)(eax);  // @165_617e20
  eax = (u32)(EBP - 308);  // @166_617e20
  PV[7] = (u32)(eax);  // @167_617e20
  eax = (u32)(EBP - 436);  // @168_617e20
  PV[8] = (u32)(eax);  // @169_617e20
  __builtin_memcpy((void *)((u32)(EBP - 324) + 0), &X0[0], 4);  // @170_617e20
  __builtin_memcpy((void *)((u32)(EBP - 324) + 4), &X0[1], 4);  // @171_617e20
  __builtin_memcpy((void *)((u32)(EBP - 324) + 8), &X0[2], 4);  // @172_617e20
  __builtin_memcpy((void *)((u32)(EBP - 324) + 12), &X0[3], 4);  // @173_617e20
  eax = ext_410f26_stdcall3(PV[8], PV[7], PV[6]);  // @174_617e20
  ecx = edx = 0;  // @175_617e20
  eax = (u32)(EBP - 372);  // @176_617e20
  PV[9] = (u32)(eax);  // @177_617e20
  eax = (u32)(EBP - 436);  // @178_617e20
  PV[10] = (u32)(eax);  // @179_617e20
  PV[11] = (u32)(eax);  // @180_617e20
  eax = ext_410f26_stdcall3(PV[11], PV[10], PV[9]);  // @181_617e20
  ecx = edx = 0;  // @182_617e20
  eax = (u32)(EBP - 436);  // @183_617e20
  PV[12] = (u32)(eax);  // @184_617e20
  eax = (u32)(EBP - 500);  // @185_617e20
  PV[13] = (u32)(eax);  // @186_617e20
  eax = ext_411009_stdcall2(PV[13], PV[12]);  // @187_617e20
  ecx = edx = 0;  // @188_617e20
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @189_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @190_617e20
  ecx = edi;  // @191_617e20
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @192_617e20
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @193_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 668)))(ecx, PV[16], PV[15], PV[14]);  // @194_617e20
  ecx = edx = 0;  // @195_617e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; });  // @196_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @197_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @198_617e20
  ecx = eax;  // @199_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 528), &v, sizeof v); }  // @200_617e20
  eax = ext_658d80_thiscall1(ecx);  // @201_617e20
  ecx = 0;  // @202_617e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; });  // @203_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; });  // @204_617e20
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; }));  // @205_617e20
  FL[3] = edi;  // @206_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 524), &v, sizeof v); }  // @207_617e20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @208_617e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 504), &v, sizeof v); }  // @209_617e20
  FL[2] = (ecx & ecx);  // @210_617e20
  if (FL[2] == 0) goto L618092;  // @211_617e20
  L618055:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @213_617e20
  edi = (u32)(edi + 8);  // @214_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 4), sizeof v); (u32)v; });  // @215_617e20
  eax = esi;  // @216_617e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @217_617e20
  eax = (eax >> (u32)(2));  // @218_617e20
  FL[3] = eax;  // @219_617e20
  PV[17] = (u32)(eax);  // @220_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 524), sizeof v); (u32)v; });  // @221_617e20
  eax = (u32)(eax + ecx*4);  // @222_617e20
  PV[18] = (u32)(eax);  // @223_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; });  // @224_617e20
  eax = (eax >> (u32)(2));  // @225_617e20
  FL[3] = eax;  // @226_617e20
  eax = (eax + (u32)(17));  // @227_617e20
  FL[3] = eax;  // @228_617e20
  PV[19] = (u32)(eax);  // @229_617e20
  PV[20] = (u32)(ebx);  // @230_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 316)))(ecx, PV[20], PV[19], PV[18], PV[17]);  // @231_617e20
  ecx = edx = 0;  // @232_617e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(EBP - 504), &v, sizeof v); }  // @233_617e20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; });  // @234_617e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @235_617e20
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; });  // @236_617e20
  if (FL[3] != 0) goto L618055;  // @237_617e20
  L618092:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 528), sizeof v); (u32)v; });  // @239_617e20
  ecx = esi;  // @240_617e20
  eax = ext_658db0_thiscall1(ecx);  // @241_617e20
    // @242_617e20
  edi = eax;  // @243_617e20
  ecx = (u32)(EBP - 164);  // @244_617e20
  esi = (esi + (u32)(8));  // @245_617e20
  FL[3] = esi;  // @246_617e20
  edx = edi;  // @247_617e20
  PV[21] = (u32)(esi);  // @248_617e20
  eax = ext_459fc0_fastcall3(ecx, edx, PV[21]);  // @249_617e20
  ecx = edx = 0;  // @250_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 16) + 0), 4); v; });  // @251_617e20
  X0[1] = 0;  // @252_617e20
  X0[2] = 0;  // @253_617e20
  X0[3] = 0;  // @254_617e20
  edx = (u32)(edi + 32);  // @255_617e20
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @256_617e20
  ecx = (u32)(EBP - 132);  // @257_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @258_617e20
  X0[1] = 0;  // @259_617e20
  X0[2] = 0;  // @260_617e20
  X0[3] = 0;  // @261_617e20
  __builtin_memcpy((void *)((u32)(EBP - 144) + 0), &X0[0], 4);  // @262_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @263_617e20
  X0[1] = 0;  // @264_617e20
  X0[2] = 0;  // @265_617e20
  X0[3] = 0;  // @266_617e20
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @267_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; });  // @268_617e20
  X0[1] = 0;  // @269_617e20
  X0[2] = 0;  // @270_617e20
  X0[3] = 0;  // @271_617e20
  PV[22] = (u32)(esi);  // @272_617e20
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @273_617e20
  eax = ext_459fc0_fastcall3(ecx, edx, PV[22]);  // @274_617e20
  ecx = edx = 0;  // @275_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 48) + 0), 4); v; });  // @276_617e20
  X0[1] = 0;  // @277_617e20
  X0[2] = 0;  // @278_617e20
  X0[3] = 0;  // @279_617e20
  edx = (u32)(edi + 64);  // @280_617e20
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @281_617e20
  ecx = (u32)(EBP - 100);  // @282_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 52) + 0), 4); v; });  // @283_617e20
  X0[1] = 0;  // @284_617e20
  X0[2] = 0;  // @285_617e20
  X0[3] = 0;  // @286_617e20
  __builtin_memcpy((void *)((u32)(EBP - 112) + 0), &X0[0], 4);  // @287_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 56) + 0), 4); v; });  // @288_617e20
  X0[1] = 0;  // @289_617e20
  X0[2] = 0;  // @290_617e20
  X0[3] = 0;  // @291_617e20
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @292_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 60) + 0), 4); v; });  // @293_617e20
  X0[1] = 0;  // @294_617e20
  X0[2] = 0;  // @295_617e20
  X0[3] = 0;  // @296_617e20
  PV[23] = (u32)(esi);  // @297_617e20
  __builtin_memcpy((void *)((u32)(EBP - 104) + 0), &X0[0], 4);  // @298_617e20
  eax = ext_459fc0_fastcall3(ecx, edx, PV[23]);  // @299_617e20
  ecx = edx = 0;  // @300_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 80) + 0), 4); v; });  // @301_617e20
  X0[1] = 0;  // @302_617e20
  X0[2] = 0;  // @303_617e20
  X0[3] = 0;  // @304_617e20
  ecx = (u32)(EBP - 500);  // @305_617e20
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7489892) + 0), 4); v; });  // @306_617e20
  X1[1] = 0;  // @307_617e20
  X1[2] = 0;  // @308_617e20
  X1[3] = 0;  // @309_617e20
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X0[0], 4);  // @310_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; });  // @311_617e20
  X0[1] = 0;  // @312_617e20
  X0[2] = 0;  // @313_617e20
  X0[3] = 0;  // @314_617e20
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @315_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 88) + 0), 4); v; });  // @316_617e20
  X0[1] = 0;  // @317_617e20
  X0[2] = 0;  // @318_617e20
  X0[3] = 0;  // @319_617e20
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @320_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 92) + 0), 4); v; });  // @321_617e20
  X0[1] = 0;  // @322_617e20
  X0[2] = 0;  // @323_617e20
  X0[3] = 0;  // @324_617e20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @325_617e20
  X0[0] = 0;  // @326_617e20
  X0[1] = 0;  // @327_617e20
  X0[2] = 0;  // @328_617e20
  X0[3] = 0;  // @329_617e20
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @330_617e20
  __builtin_memcpy((void *)((u32)(EBP - 68) + 4), &X0[1], 4);  // @331_617e20
  __builtin_memcpy((void *)((u32)(EBP - 68) + 8), &X0[2], 4);  // @332_617e20
  __builtin_memcpy((void *)((u32)(EBP - 68) + 12), &X0[3], 4);  // @333_617e20
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @334_617e20
  __builtin_memcpy((void *)((u32)(EBP - 52) + 4), &X0[1], 4);  // @335_617e20
  __builtin_memcpy((void *)((u32)(EBP - 52) + 8), &X0[2], 4);  // @336_617e20
  __builtin_memcpy((void *)((u32)(EBP - 52) + 12), &X0[3], 4);  // @337_617e20
  PV[24] = (u32)(ecx);  // @338_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 96) + 0), 4); v; });  // @339_617e20
  X0[1] = 0;  // @340_617e20
  X0[2] = 0;  // @341_617e20
  X0[3] = 0;  // @342_617e20
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @343_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 100) + 0), 4); v; });  // @344_617e20
  X0[1] = 0;  // @345_617e20
  X0[2] = 0;  // @346_617e20
  X0[3] = 0;  // @347_617e20
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @348_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 104) + 0), 4); v; });  // @349_617e20
  X0[1] = 0;  // @350_617e20
  X0[2] = 0;  // @351_617e20
  X0[3] = 0;  // @352_617e20
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @353_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 108) + 0), 4); v; });  // @354_617e20
  X0[1] = 0;  // @355_617e20
  X0[2] = 0;  // @356_617e20
  X0[3] = 0;  // @357_617e20
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @358_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7069456) + 0), 4); v; });  // @359_617e20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7069456) + 4), 4); v; });  // @360_617e20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7069456) + 8), 4); v; });  // @361_617e20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7069456) + 12), 4); v; });  // @362_617e20
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @363_617e20
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7489888) + 0), 4); v; })));  // @364_617e20
  __builtin_memcpy((void *)((u32)(EBP - 180) + 0), &X0[0], 4);  // @365_617e20
  __builtin_memcpy((void *)((u32)(EBP - 180) + 4), &X0[1], 4);  // @366_617e20
  __builtin_memcpy((void *)((u32)(EBP - 180) + 8), &X0[2], 4);  // @367_617e20
  __builtin_memcpy((void *)((u32)(EBP - 180) + 12), &X0[3], 4);  // @368_617e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @369_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @370_617e20
  X0[1] = 0;  // @371_617e20
  X0[2] = 0;  // @372_617e20
  X0[3] = 0;  // @373_617e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @374_617e20
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @375_617e20
  PV[25] = (u32)(ebx);  // @376_617e20
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @377_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @378_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 316)))(ecx, PV[25], (u32)(0), PV[24], (u32)(4));  // @379_617e20
  ecx = edx = 0;  // @380_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @381_617e20
  ecx = (u32)(EBP - 180);  // @382_617e20
  PV[26] = (u32)(ecx);  // @383_617e20
  PV[27] = (u32)(ebx);  // @384_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 316)))(ecx, PV[27], (u32)(7), PV[26], (u32)(1));  // @385_617e20
  ecx = edx = 0;  // @386_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @387_617e20
  ecx = (u32)(EBP - 164);  // @388_617e20
  PV[28] = (u32)(ecx);  // @389_617e20
  PV[29] = (u32)(ebx);  // @390_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 316)))(ecx, PV[29], (u32)(8), PV[28], (u32)(9));  // @391_617e20
  ecx = edx = 0;  // @392_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @393_617e20
  ecx = (u32)(EBP - 20);  // @394_617e20
  PV[30] = (u32)(ecx);  // @395_617e20
  PV[31] = (u32)(ebx);  // @396_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 316)))(ecx, PV[31], (u32)(95), PV[30], (u32)(1));  // @397_617e20
  ecx = edx = 0;  // @398_617e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @399_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @400_617e20
  if (FL[0] == FL[1]) goto L61822d;  // @401_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @402_617e20
  ecx = esi;  // @403_617e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @404_617e20
  ecx = edx = 0;  // @405_617e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @406_617e20
  L61822d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @408_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489904), sizeof v); (u32)v; }); FL[1] = edx;  // @409_617e20
  if (FL[0] != FL[1]) goto L618241;  // @410_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489968), sizeof v); (u32)v; }); FL[1] = (u32)(52);  // @411_617e20
  if (FL[0] == FL[1]) goto L618264;  // @412_617e20
  L618241:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @414_617e20
  PV[32] = (u32)(edx);  // @415_617e20
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7489904), &v, sizeof v); }  // @416_617e20
  { u32 v = (u32)((u32)(52)); __builtin_memcpy((void *)(u32)(7489968), &v, sizeof v); }  // @417_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @418_617e20
  PV[33] = (u32)(eax);  // @419_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 332)))(ecx, PV[33], (u32)(0), PV[32], (u32)(52));  // @420_617e20
  ecx = edx = 0;  // @421_617e20
  L618264:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 512), sizeof v); (u32)v; });  // @423_617e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @424_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @425_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @426_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @427_617e20
  if (FL[0] == FL[1]) goto L618293;  // @428_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @429_617e20
  ecx = edi;  // @430_617e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @431_617e20
  ecx = edx = 0;  // @432_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; });  // @433_617e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @434_617e20
  L618293:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @436_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490032), sizeof v); (u32)v; }); FL[1] = edx;  // @437_617e20
  if (FL[0] != FL[1]) goto L6182a6;  // @438_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490036), sizeof v); (u32)v; }); FL[1] = eax;  // @439_617e20
  if (FL[0] == FL[1]) goto L6182c6;  // @440_617e20
  L6182a6:;
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; });  // @442_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7490036), &v, sizeof v); }  // @443_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @444_617e20
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7490032), &v, sizeof v); }  // @445_617e20
  PV[35] = (u32)(edx);  // @446_617e20
  PV[36] = (u32)(eax);  // @447_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @448_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 340)))(ecx, PV[36], PV[35], PV[34]);  // @449_617e20
  ecx = edx = 0;  // @450_617e20
  L6182c6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @452_617e20
  edi = 0;  // @453_617e20
  FL[3] = edi;  // @454_617e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 516), &v, sizeof v); }  // @455_617e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); FL[1] = edi;  // @456_617e20
  if (FL[0] <= FL[1]) goto L618313;  // @457_617e20
  ebx = esi;  // @458_617e20
  L6182e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @460_617e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490048), sizeof v); (u32)v; });  // @461_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*8), sizeof v); (u32)v; });  // @462_617e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @463_617e20
  eax = (eax - (u32)(2));  // @464_617e20
  FL[3] = eax;  // @465_617e20
  PV[37] = (u32)(eax);  // @466_617e20
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*8 + 4), sizeof v); (u32)v; });  // @467_617e20
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @468_617e20
  PV[40] = (u32)(edx);  // @469_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 284)))(ecx, PV[40], (u32)(5), (u32)(0), PV[39], PV[38], PV[37]);  // @470_617e20
  ecx = edx = 0;  // @471_617e20
  edi = (edi + 1);  // @472_617e20
  FL[3] = edi;  // @473_617e20
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @474_617e20
  if (FL[0] < FL[1]) goto L6182e0;  // @475_617e20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @476_617e20
  L618313:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @478_617e20
  PV[41] = (u32)(ebx);  // @479_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[41], (u32)(0), (u32)(24), (u32)(2));  // @480_617e20
  ecx = edx = 0;  // @481_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @482_617e20
  PV[42] = (u32)(ebx);  // @483_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 200)))(ecx, PV[42], (u32)(140), (u32)(3));  // @484_617e20
  ecx = edx = 0;  // @485_617e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @486_617e20
  X1[0] = 0;  // @487_617e20
  X1[1] = 0;  // @488_617e20
  X1[2] = 0;  // @489_617e20
  X1[3] = 0;  // @490_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @491_617e20
  X0[1] = 0;  // @492_617e20
  X0[2] = 0;  // @493_617e20
  X0[3] = 0;  // @494_617e20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @495_617e20
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @496_617e20
  if (__builtin_parity(FL[2] & 0xff)) goto L618387;  // @497_617e20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @498_617e20
  X0[1] = 0;  // @499_617e20
  X0[2] = 0;  // @500_617e20
  X0[3] = 0;  // @501_617e20
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @502_617e20
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @503_617e20
  if (__builtin_parity(FL[2] & 0xff)) goto L618387;  // @504_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @505_617e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @506_617e20
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @507_617e20
  ecx = 0;  // @508_617e20 (edx = high dword of the 64-bit result)
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @509_617e20
  PV[43] = (u32)(edx);  // @510_617e20
  PV[44] = (u32)(eax);  // @511_617e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @512_617e20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[44], PV[43], (u32)(7069356));  // @513_617e20
  ecx = edx = 0;  // @514_617e20
  L618387:;
  ext_633654(G(u32, 0x6f5630));  // @516_617e20
  return eax;  // @517_617e20
}
PCREG(617e20, lifted_617e20);

extern "C" u32 THISCALL lifted_64abb0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
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
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @1_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @3_64abb0
  esi = ecx;  // @4_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @5_64abb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @7_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @8_64abb0
  PV[0] = (u32)(edi);  // @9_64abb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 252), &v, sizeof v); }  // @10_64abb0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 268), &v, sizeof v); }  // @11_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 256), &v, sizeof v); }  // @12_64abb0
  eax = ext_648a40_thiscall2(ecx, PV[0]);  // @13_64abb0
  ecx = edx = 0;  // @14_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @15_64abb0
  eax = ext_4db3b0_thiscall1(ecx);  // @16_64abb0
  ecx = edx = 0;  // @17_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @18_64abb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @19_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 80), &v, sizeof v); }  // @20_64abb0
  FL[2] = (edi & edi);  // @21_64abb0
  if (FL[2] == 0) goto L64acf1;  // @22_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @23_64abb0
  eax = (u32)(EBP - 240);  // @24_64abb0
  eax = (eax - ecx);  // @25_64abb0
  FL[3] = eax;  // @26_64abb0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @27_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @28_64abb0
  edi = ecx;  // @29_64abb0
  eax = (u32)(EBP - 236);  // @30_64abb0
  eax = (eax - ecx);  // @31_64abb0
  FL[3] = eax;  // @32_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @33_64abb0
  eax = (u32)(EBP - 232);  // @34_64abb0
  eax = (eax - ecx);  // @35_64abb0
  FL[3] = eax;  // @36_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @37_64abb0
  eax = (u32)(EBP - 244);  // @38_64abb0
  eax = (eax - ecx);  // @39_64abb0
  FL[3] = eax;  // @40_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @41_64abb0
  L64ac62:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @43_64abb0
  esi = (u32)(eax + edi);  // @44_64abb0
  edx = edi;  // @45_64abb0
  ecx = esi;  // @46_64abb0
  eax = ext_441970_fastcall3(ecx, edx, PV[1]);  // @47_64abb0
  ecx = edx = 0;  // @48_64abb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @49_64abb0
  X0[1] = 0;  // @50_64abb0
  X0[2] = 0;  // @51_64abb0
  X0[3] = 0;  // @52_64abb0
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @53_64abb0
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @54_64abb0
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @55_64abb0
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @56_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; });  // @57_64abb0
  PV[2] = (u32)(ecx);  // @58_64abb0
  PV[3] = X0[0];  // @59_64abb0
  ecx = (u32)(EBP - 16);  // @60_64abb0
  PV[4] = (u32)(esi);  // @61_64abb0
  eax = ext_443ef0_fastcall4(ecx, edx, PV[4], PV[3]);  // @62_64abb0
  ecx = edx = 0;  // @63_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @64_64abb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @65_64abb0
  X0[1] = 0;  // @66_64abb0
  X0[2] = 0;  // @67_64abb0
  X0[3] = 0;  // @68_64abb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @69_64abb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi) + 0), 4); v; });  // @70_64abb0
  X1[1] = 0;  // @71_64abb0
  X1[2] = 0;  // @72_64abb0
  X1[3] = 0;  // @73_64abb0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @74_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @75_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @76_64abb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi) + 0), 4); v; });  // @77_64abb0
  X0[1] = 0;  // @78_64abb0
  X0[2] = 0;  // @79_64abb0
  X0[3] = 0;  // @80_64abb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @81_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @82_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @83_64abb0
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @84_64abb0
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @85_64abb0
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @86_64abb0
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @87_64abb0
  __builtin_memcpy((void *)((u32)(eax + edi) + 0), &X1[0], 4);  // @88_64abb0
  edi = (edi + (u32)(16));  // @89_64abb0
  FL[3] = edi;  // @90_64abb0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @91_64abb0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @92_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @93_64abb0
  if (FL[3] != 0) goto L64ac62;  // @94_64abb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @95_64abb0
  L64acf1:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; });  // @97_64abb0
  ecx = (u32)(EBP - 16);  // @98_64abb0
  eax = ext_4e09e0_fastcall2(ecx, edx);  // @99_64abb0
    // @100_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @101_64abb0
  ecx = (u32)(EBP - 16);  // @102_64abb0
  eax = ext_441a60_fastcall2(ecx, edx);  // @103_64abb0
  ecx = edx = 0;  // @104_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @105_64abb0
  ecx = (u32)(EBP - 52);  // @106_64abb0
  eax = ext_4dfd10_fastcall2(ecx, edx);  // @107_64abb0
    // @108_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @109_64abb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 84), sizeof v); (u32)v; });  // @110_64abb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @111_64abb0
  L64ad30:;
  FL[2] = (esi & esi);  // @113_64abb0
  if (FL[2] == 0) goto L64aef1;  // @114_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @115_64abb0
  FL[2] = (ecx & ecx);  // @116_64abb0
  if (FL[2] == 0) goto L64ad47;  // @117_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @118_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @119_64abb0
  goto L64ad4c;  // @120_64abb0
  L64ad47:;
  eax = (u32)(2097154);  // @122_64abb0
  L64ad4c:;
  FL[2] = (eax & (u32)(1048576));  // @124_64abb0
  if (FL[2] != 0) goto L64aef1;  // @125_64abb0
  FL[2] = (ecx & ecx);  // @126_64abb0
  if (FL[2] == 0) goto L64ad63;  // @127_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @128_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @129_64abb0
  goto L64ad68;  // @130_64abb0
  L64ad63:;
  eax = (u32)(2097154);  // @132_64abb0
  L64ad68:;
  FL[2] = (eax & (u32)(69206016));  // @134_64abb0
  if (FL[2] == 0) goto L64aedd;  // @135_64abb0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(6302720));  // @136_64abb0
  if (FL[2] != 0) goto L64aedd;  // @137_64abb0
  FL[2] = (edi & edi);  // @138_64abb0
  if (FL[2] == 0) goto L64adfd;  // @139_64abb0
  PV[5] = (u32)(esi);  // @140_64abb0
  edx = (u32)(esi + 48);  // @141_64abb0
  ecx = (u32)(EBP - 16);  // @142_64abb0
  eax = ext_441970_fastcall3(ecx, edx, PV[5]);  // @143_64abb0
  ecx = edx = 0;  // @144_64abb0
  edx = (u32)(esi + 36);  // @145_64abb0
  ecx = (u32)(EBP - 16);  // @146_64abb0
  eax = ext_441940_fastcall2(ecx, edx);  // @147_64abb0
  ecx = edx = 0;  // @148_64abb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 76) + 0), 4); v; });  // @149_64abb0
  X2[1] = 0;  // @150_64abb0
  X2[2] = 0;  // @151_64abb0
  X2[3] = 0;  // @152_64abb0
  eax = (u32)(EBP - 236);  // @153_64abb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @154_64abb0
  X3[1] = 0;  // @155_64abb0
  X3[2] = 0;  // @156_64abb0
  X3[3] = 0;  // @157_64abb0
  ecx = 0;  // @158_64abb0
  FL[3] = ecx;  // @159_64abb0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @160_64abb0
  X4[1] = 0;  // @161_64abb0
  X4[2] = 0;  // @162_64abb0
  X4[3] = 0;  // @163_64abb0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @164_64abb0
  X5[1] = 0;  // @165_64abb0
  X5[2] = 0;  // @166_64abb0
  X5[3] = 0;  // @167_64abb0
  L64adc0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 4) + 0), 4); v; });  // @169_64abb0
  X0[1] = 0;  // @170_64abb0
  X0[2] = 0;  // @171_64abb0
  X0[3] = 0;  // @172_64abb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 8) + 0), 4); v; });  // @173_64abb0
  X1[1] = 0;  // @174_64abb0
  X1[2] = 0;  // @175_64abb0
  X1[3] = 0;  // @176_64abb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @177_64abb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @178_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @179_64abb0
  X0[0] = X3[0];  // @180_64abb0
  X0[1] = X3[1];  // @181_64abb0
  X0[2] = X3[2];  // @182_64abb0
  X0[3] = X3[3];  // @183_64abb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @184_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @185_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @186_64abb0
  if ((!(!(U2F(X1[0]) >= U2F(X2[0]))) && !(!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L64adf5;  // @187_64abb0
  ecx = (ecx + 1);  // @188_64abb0
  FL[3] = ecx;  // @189_64abb0
  eax = (eax + (u32)(16));  // @190_64abb0
  FL[3] = eax;  // @191_64abb0
  FL[0] = ecx; FL[1] = edi;  // @192_64abb0
  if (FL[0] != FL[1]) goto L64adc0;  // @193_64abb0
  goto L64adfd;  // @194_64abb0
  L64adf5:;
  FL[0] = ecx; FL[1] = edi;  // @196_64abb0
  if (FL[0] != FL[1]) goto L64aedd;  // @197_64abb0
  L64adfd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @199_64abb0
  PV[6] = (u32)(esi);  // @200_64abb0
  eax = (u32)(ecx + 65581);  // @201_64abb0
  PV[7] = (u32)(eax);  // @202_64abb0
  eax = ext_64d030_thiscall5(ecx, PV[7], PV[6], (u32)(0), (u32)(0));  // @203_64abb0
  ecx = edx = 0;  // @204_64abb0
  esi = eax;  // @205_64abb0
  FL[2] = (esi & esi);  // @206_64abb0
  if (FL[2] == 0) goto L64aed7;  // @207_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @208_64abb0
  FL[2] = (ecx & ecx);  // @209_64abb0
  if (FL[2] == 0) goto L64ae2a;  // @210_64abb0
  ecx = (ecx + (u32)(36));  // @211_64abb0
  FL[3] = ecx;  // @212_64abb0
  goto L64ae30;  // @213_64abb0
  L64ae2a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @215_64abb0
  ecx = (ecx + (u32)(44));  // @216_64abb0
  FL[3] = ecx;  // @217_64abb0
  L64ae30:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @219_64abb0
  edx = (u32)(edx + 98845);  // @220_64abb0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @221_64abb0
  ecx = edx = 0;  // @222_64abb0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(EBP + 32)) : "st");  // @223_64abb0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 264)) :: "st");  // @224_64abb0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @225_64abb0
  FL[2] = (eax & eax);  // @226_64abb0
  if ((s32)FL[2] >= 0) goto L64ae5a;  // @227_64abb0
  eax = 0;  // @228_64abb0
  FL[3] = eax;  // @229_64abb0
  goto L64ae67;  // @230_64abb0
  L64ae5a:;
  FL[0] = eax; FL[1] = (u32)(255);  // @232_64abb0
  ecx = (u32)(255);  // @233_64abb0
  if ((s32)FL[0] > (s32)FL[1]) eax = ecx;  // @234_64abb0
  L64ae67:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) & (u32)(64));  // @236_64abb0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @237_64abb0
  if (FL[2] == 0) goto L64aed7;  // @238_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @239_64abb0
  eax = (u32)(ecx + 65581);  // @240_64abb0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 65661), &v, sizeof v); }  // @241_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 65657), &v, sizeof v); }  // @242_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @243_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @244_64abb0
  FL[2] = (ecx & ecx);  // @245_64abb0
  if (FL[2] == 0) goto L64ae95;  // @246_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @247_64abb0
  L64ae95:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @249_64abb0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @250_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @251_64abb0
  eax = (eax + (u32)(65653));  // @252_64abb0
  FL[3] = eax;  // @253_64abb0
  PV[9] = (u32)(eax);  // @254_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 244), sizeof v); (u32)v; });  // @255_64abb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[9], PV[8]);  // @256_64abb0
  ecx = edx = 0;  // @257_64abb0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @258_64abb0
  if (FL[2] != 0) goto L64aed3;  // @259_64abb0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) & (u32)(239))); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @260_64abb0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @261_64abb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @262_64abb0
  ecx = esi;  // @263_64abb0
  eax = ext_4db520_thiscall1(ecx);  // @264_64abb0
  ecx = edx = 0;  // @265_64abb0
  esi = eax;  // @266_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @267_64abb0
  goto L64ad30;  // @268_64abb0
  L64aed3:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) | (u32)(16))); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @270_64abb0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @271_64abb0
  L64aed7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @273_64abb0
  L64aedd:;
  ecx = esi;  // @275_64abb0
  eax = ext_4db520_thiscall1(ecx);  // @276_64abb0
  ecx = edx = 0;  // @277_64abb0
  esi = eax;  // @278_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @279_64abb0
  goto L64ad30;  // @280_64abb0
  L64aef1:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @282_64abb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @283_64abb0
  L64af00:;
  FL[2] = (esi & esi);  // @285_64abb0
  if (FL[2] == 0) goto L64b055;  // @286_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @287_64abb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @288_64abb0
  FL[2] = (eax & eax);  // @289_64abb0
  if (FL[2] == 0) goto L64af23;  // @290_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @291_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @292_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @293_64abb0
  goto L64af28;  // @294_64abb0
  L64af23:;
  ecx = (u32)(2097154);  // @296_64abb0
  L64af28:;
  FL[2] = (ecx & (u32)(1048576));  // @298_64abb0
  if (FL[2] == 0) goto L64b055;  // @299_64abb0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(2108416));  // @300_64abb0
  if (FL[2] != 0) goto L64b04d;  // @301_64abb0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) & (u32)(1024));  // @302_64abb0
  if (FL[2] != 0) goto L64b04d;  // @303_64abb0
  PV[10] = (u32)(esi);  // @304_64abb0
  edx = (u32)(esi + 48);  // @305_64abb0
  ecx = (u32)(EBP - 16);  // @306_64abb0
  eax = ext_441970_fastcall3(ecx, edx, PV[10]);  // @307_64abb0
  ecx = edx = 0;  // @308_64abb0
  edx = (u32)(esi + 36);  // @309_64abb0
  ecx = (u32)(EBP - 16);  // @310_64abb0
  eax = ext_441940_fastcall2(ecx, edx);  // @311_64abb0
  ecx = edx = 0;  // @312_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @313_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @314_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 680), sizeof v); (u32)v; });  // @315_64abb0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @316_64abb0
  ecx = edx = 0;  // @317_64abb0
  FL[2] = (eax & (u32)(32768));  // @318_64abb0
  if (FL[2] != 0) goto L64afd9;  // @319_64abb0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 76) + 0), 4); v; });  // @320_64abb0
  X2[1] = 0;  // @321_64abb0
  X2[2] = 0;  // @322_64abb0
  X2[3] = 0;  // @323_64abb0
  ecx = 0;  // @324_64abb0
  FL[3] = ecx;  // @325_64abb0
  FL[2] = (edi & edi);  // @326_64abb0
  if (FL[2] == 0) goto L64afd9;  // @327_64abb0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @328_64abb0
  X3[1] = 0;  // @329_64abb0
  X3[2] = 0;  // @330_64abb0
  X3[3] = 0;  // @331_64abb0
  eax = (u32)(EBP - 236);  // @332_64abb0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @333_64abb0
  X4[1] = 0;  // @334_64abb0
  X4[2] = 0;  // @335_64abb0
  X4[3] = 0;  // @336_64abb0
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @337_64abb0
  X5[1] = 0;  // @338_64abb0
  X5[2] = 0;  // @339_64abb0
  X5[3] = 0;  // @340_64abb0
  L64afa0:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 4) + 0), 4); v; });  // @342_64abb0
  X0[1] = 0;  // @343_64abb0
  X0[2] = 0;  // @344_64abb0
  X0[3] = 0;  // @345_64abb0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax - 8) + 0), 4); v; });  // @346_64abb0
  X1[1] = 0;  // @347_64abb0
  X1[2] = 0;  // @348_64abb0
  X1[3] = 0;  // @349_64abb0
  X1[0] = F2U(U2F(X1[0]) * U2F(X5[0]));  // @350_64abb0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @351_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @352_64abb0
  X0[0] = X3[0];  // @353_64abb0
  X0[1] = X3[1];  // @354_64abb0
  X0[2] = X3[2];  // @355_64abb0
  X0[3] = X3[3];  // @356_64abb0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @357_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @358_64abb0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @359_64abb0
  if ((!(!(U2F(X1[0]) >= U2F(X2[0]))) && !(!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L64afd5;  // @360_64abb0
  ecx = (ecx + 1);  // @361_64abb0
  FL[3] = ecx;  // @362_64abb0
  eax = (eax + (u32)(16));  // @363_64abb0
  FL[3] = eax;  // @364_64abb0
  FL[0] = ecx; FL[1] = edi;  // @365_64abb0
  if (FL[0] != FL[1]) goto L64afa0;  // @366_64abb0
  goto L64afd9;  // @367_64abb0
  L64afd5:;
  FL[0] = ecx; FL[1] = edi;  // @369_64abb0
  if (FL[0] != FL[1]) goto L64b04d;  // @370_64abb0
  L64afd9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @372_64abb0
  ecx = (u32)(EBP - 16);  // @373_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; });  // @374_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @375_64abb0
  eax = (eax + (u32)(36));  // @376_64abb0
  FL[3] = eax;  // @377_64abb0
  PV[11] = (u32)(eax);  // @378_64abb0
  eax = ext_43e920_fastcall3(ecx, edx, PV[11]);  // @379_64abb0
  ecx = edx = 0;  // @380_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @381_64abb0
  ecx = (u32)(EBP - 16);  // @382_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @383_64abb0
  eax = ext_441a60_fastcall2(ecx, edx);  // @384_64abb0
  ecx = edx = 0;  // @385_64abb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @386_64abb0
  ecx = (u32)(EBP - 52);  // @387_64abb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @388_64abb0
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @389_64abb0
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[12]);  // @390_64abb0
  ecx = edx = 0;  // @391_64abb0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 32) + 0), 4); v; });  // @392_64abb0
  X0[1] = 0;  // @393_64abb0
  X0[2] = 0;  // @394_64abb0
  X0[3] = 0;  // @395_64abb0
  eax = (u32)(EBP - 16);  // @396_64abb0
  PV[13] = (u32)(ecx);  // @397_64abb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @398_64abb0
  PV[14] = X0[0];  // @399_64abb0
  PV[15] = (u32)(eax);  // @400_64abb0
  eax = (u32)(EBP - 52);  // @401_64abb0
  PV[16] = (u32)(eax);  // @402_64abb0
  PV[17] = (u32)(edi);  // @403_64abb0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @404_64abb0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @405_64abb0
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @406_64abb0
  eax = ext_64abb0_thiscall8(ecx, PV[20], PV[19], PV[18], PV[17], PV[16], PV[15], PV[14]);  // @407_64abb0
  ecx = edx = 0;  // @408_64abb0
  L64b04d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @410_64abb0
  goto L64af00;  // @411_64abb0
  L64b055:;
  ext_633654(G(u32, 0x6f5630));  // @413_64abb0
  return eax;  // @414_64abb0
}
PCREG(64abb0, lifted_64abb0);

