// batch254020.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42aee0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42aee0");
extern "C" u32 FASTCALL ext_42b080_fastcall3(u32, u32, u32) __asm__("ext_42b080");
extern "C" u32 FASTCALL ext_42feb0_fastcall4(u32, u32, u32, u32) __asm__("ext_42feb0");
extern "C" u32 FASTCALL ext_4309b0_fastcall3(u32, u32, u32) __asm__("ext_4309b0");
extern "C" u32 FASTCALL ext_49b9a0_fastcall4(u32, u32, u32, u32) __asm__("ext_49b9a0");
extern "C" u32 FASTCALL ext_49bbc0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_49bbc0");
extern "C" u32 FASTCALL ext_49be80_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_49be80");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4df330_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_4df330");
extern "C" u32 THISCALL ext_49ab80_thiscall3(u32, u32, u32) __asm__("ext_49ab80");
extern "C" u32 STDCALL ext_4d7c30_stdcall4(u32, u32, u32, u32) __asm__("ext_4d7c30");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_42b0f0_thiscall4(u32, u32, u32, u32) __asm__("ext_42b0f0");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_42be20_thiscall2(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_430a20_thiscall3(u32, u32, u32) __asm__("ext_430a20");
extern "C" u32 THISCALL ext_430eb0_thiscall4(u32, u32, u32, u32) __asm__("ext_430eb0");
extern "C" u32 THISCALL ext_431110_thiscall3(u32, u32, u32) __asm__("ext_431110");
extern "C" u32 THISCALL ext_431330_thiscall3(u32, u32, u32) __asm__("ext_431330");
extern "C" u32 THISCALL ext_439fd0_thiscall2(u32, u32) __asm__("ext_439fd0");
extern "C" u32 THISCALL ext_45e420_thiscall2(u32, u32) __asm__("ext_45e420");
extern "C" u32 THISCALL ext_48db70_thiscall1(u32) __asm__("ext_48db70");
extern "C" u32 THISCALL ext_4989a0_thiscall2(u32, u32) __asm__("ext_4989a0");
extern "C" u32 THISCALL ext_4998c0_thiscall3(u32, u32, u32) __asm__("ext_4998c0");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_49b330_thiscall2(u32, u32) __asm__("ext_49b330");
extern "C" u32 THISCALL ext_49b360_thiscall3(u32, u32, u32) __asm__("ext_49b360");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc130_thiscall2(u32, u32) __asm__("ext_4cc130");
extern "C" u32 THISCALL ext_4cc180_thiscall2(u32, u32) __asm__("ext_4cc180");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccad0_thiscall3(u32, u32, u32) __asm__("ext_4ccad0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4d5440_thiscall1(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4d5580_thiscall1(u32) __asm__("ext_4d5580");
extern "C" u32 THISCALL ext_4d62c0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4d62c0");
extern "C" u32 THISCALL ext_4d6520_thiscall4(u32, u32, u32, u32) __asm__("ext_4d6520");
extern "C" u32 THISCALL ext_4d6aa0_thiscall3(u32, u32, u32) __asm__("ext_4d6aa0");
extern "C" u32 THISCALL ext_4d7540_thiscall1(u32) __asm__("ext_4d7540");
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db520_thiscall1(u32) __asm__("ext_4db520");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4dc420_thiscall2(u32, u32) __asm__("ext_4dc420");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f2d60_thiscall3(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }
static u8 ALB_[0x20000] __attribute__((aligned(16))); static u32 alo_, SPV_;

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_42be20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664c4a);  // @h_42be20
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_42be20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42be20
  eax = (u32)(EBP + 8);  // @2_42be20
  PV[0] = (u32)(edi);  // @3_42be20
  PV[1] = (u32)(eax);  // @4_42be20
  eax = ext_431110_thiscall3(ecx, PV[1], PV[0]);  // @5_42be20
  ecx = edx = 0;  // @6_42be20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_42be20
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_42be20
  if (FL[0] == FL[1]) goto L42be76;  // @9_42be20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @10_42be20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @11_42be20
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @12_42be20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_42be20
  eax = ext_42feb0_fastcall4(ecx, edx, PV[3], PV[2]);  // @14_42be20
  ecx = edx = 0;  // @15_42be20
  FL[2] = (eax & eax);  // @16_42be20
  if ((s32)FL[2] >= 0) goto L42bf43;  // @17_42be20
  L42be76:;
  ecx = (u32)(EBP - 24);  // @19_42be20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @20_42be20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @21_42be20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_42be20
  eax = ext_6014a0_stdcall1((u32)(8));  // @23_42be20
  ecx = edx = 0;  // @24_42be20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @25_42be20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @26_42be20
  ecx = (u32)(eax + 8);  // @27_42be20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @28_42be20
  FL[2] = (eax & eax);  // @29_42be20
  if (FL[2] == 0) goto L42bea8;  // @30_42be20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @31_42be20
  L42bea8:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @33_42be20
  PV[4] = (u32)(edi);  // @34_42be20
  ecx = (u32)(EBP - 48);  // @35_42be20
  reg.state = (s32)((u32)(0));  // @36_42be20
  eax = ext_5f10c0_thiscall2(ecx, PV[4]);  // @37_42be20
  ecx = edx = 0;  // @38_42be20
  eax = (u32)(EBP - 24);  // @39_42be20
  reg.state = (s32)((u32)(1));  // @40_42be20
  PV[5] = (u32)(eax);  // @41_42be20
  ecx = (u32)(EBP - 36);  // @42_42be20
  eax = ext_5f10c0_thiscall2(ecx, PV[5]);  // @43_42be20
  ecx = edx = 0;  // @44_42be20
  eax = (u32)(EBP - 48);  // @45_42be20
  reg.state = (s32)((u32)(2));  // @46_42be20
  PV[6] = (u32)(eax);  // @47_42be20
  PV[7] = (u32)(ecx);  // @48_42be20
  eax = 0;  // @49_42be20
  ecx = ebx;  // @50_42be20
  PV[8] = esi;  // @51_42be20
  eax = (u32)(EBP + 8);  // @52_42be20
  PV[9] = (u32)(eax);  // @53_42be20
  eax = ext_430eb0_thiscall4(ecx, PV[9], PV[8], PV[6]);  // @54_42be20
  ecx = edx = 0;  // @55_42be20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @56_42be20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @57_42be20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @58_42be20
  eax = (eax - ecx);  // @59_42be20
  FL[3] = eax;  // @60_42be20
  reg.state = (s32)((u32)(3));  // @61_42be20
  FL[2] = (ecx & ecx);  // @62_42be20
  if (FL[2] == 0) goto L42bf04;  // @63_42be20
  FL[2] = (eax & eax);  // @64_42be20
  if (FL[2] == 0) goto L42bf04;  // @65_42be20
  PV[10] = (u32)(eax);  // @66_42be20
  PV[11] = (u32)(ecx);  // @67_42be20
  ecx = (u32)(EBP - 36);  // @68_42be20
  eax = ext_54f870_stdcall2(PV[11], PV[10]);  // @69_42be20
  ecx = edx = 0;  // @70_42be20
  L42bf04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @72_42be20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @73_42be20
  eax = (eax - ecx);  // @74_42be20
  FL[3] = eax;  // @75_42be20
  reg.state = (s32)((u32)(4));  // @76_42be20
  FL[2] = (ecx & ecx);  // @77_42be20
  if (FL[2] == 0) goto L42bf22;  // @78_42be20
  FL[2] = (eax & eax);  // @79_42be20
  if (FL[2] == 0) goto L42bf22;  // @80_42be20
  PV[12] = (u32)(eax);  // @81_42be20
  PV[13] = (u32)(ecx);  // @82_42be20
  ecx = (u32)(EBP - 48);  // @83_42be20
  eax = ext_54f870_stdcall2(PV[13], PV[12]);  // @84_42be20
  ecx = edx = 0;  // @85_42be20
  L42bf22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @87_42be20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @88_42be20
  eax = (eax - ecx);  // @89_42be20
  FL[3] = eax;  // @90_42be20
  reg.state = (s32)((u32)(5));  // @91_42be20
  FL[2] = (ecx & ecx);  // @92_42be20
  if (FL[2] == 0) goto L42bf43;  // @93_42be20
  FL[2] = (eax & eax);  // @94_42be20
  if (FL[2] == 0) goto L42bf43;  // @95_42be20
  PV[14] = (u32)(eax);  // @96_42be20
  PV[15] = (u32)(ecx);  // @97_42be20
  ecx = (u32)(EBP - 24);  // @98_42be20
  eax = ext_54f870_stdcall2(PV[15], PV[14]);  // @99_42be20
  ecx = edx = 0;  // @100_42be20
  L42bf43:;
  eax = (u32)(esi + 25);  // @102_42be20
  SEH_LEAVE();  // @103_42be20
  return eax;  // @104_42be20
}
PCREG(42be20, lifted_42be20);

extern "C" u32 THISCALL lifted_42db40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664f46);  // @h_42db40
  u8 F[0x850] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x750);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x750 + 8, &a0, 4);
  ebx = ecx;  // @0_42db40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42db40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_42db40
  if (FL[0] == FL[1]) goto L42dcfe;  // @3_42db40
  L42db80:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @5_42db40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_42db40
  if (FL[2] == 0) goto L42db96;  // @7_42db40
  L42db86:;
  FL[0] = (eax & 0xff); FL[1] = (u32)(13);  // @9_42db40
  if (FL[0] == FL[1]) goto L42db8e;  // @10_42db40
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @11_42db40
  if (FL[0] != FL[1]) goto L42db96;  // @12_42db40
  L42db8e:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @14_42db40
  esi = (esi + 1);  // @15_42db40
  FL[3] = esi;  // @16_42db40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @17_42db40
  if (FL[2] != 0) goto L42db86;  // @18_42db40
  L42db96:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @20_42db40
  ecx = 0;  // @21_42db40
  FL[3] = ecx;  // @22_42db40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @23_42db40
  if (FL[2] == 0) goto L42dbc6;  // @24_42db40
  edx = (u32)(EBP - 528);  // @25_42db40
  edx = (edx - esi);  // @26_42db40
  FL[3] = edx;  // @27_42db40
  L42dba6:;
  FL[0] = (eax & 0xff); FL[1] = (u32)(13);  // @29_42db40
  if (FL[0] == FL[1]) goto L42dbba;  // @30_42db40
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @31_42db40
  if (FL[0] == FL[1]) goto L42dbba;  // @32_42db40
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + esi), &v, sizeof v); }  // @33_42db40
  ecx = (ecx + 1);  // @34_42db40
  FL[3] = ecx;  // @35_42db40
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @36_42db40
  esi = (esi + 1);  // @37_42db40
  FL[3] = esi;  // @38_42db40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @39_42db40
  if (FL[2] != 0) goto L42dba6;  // @40_42db40
  L42dbba:;
  FL[0] = ecx; FL[1] = (u32)(512);  // @42_42db40
  if (FL[0] >= FL[1]) goto L42dd1e;  // @43_42db40
  L42dbc6:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + ecx - 528), &v, sizeof v); }  // @45_42db40
  ecx = (u32)(EBP - 528);  // @46_42db40
  edx = (u32)(ecx + 1);  // @47_42db40
  L42dbd7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @49_42db40
  ecx = (ecx + 1);  // @50_42db40
  FL[3] = ecx;  // @51_42db40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @52_42db40
  if (FL[2] != 0) goto L42dbd7;  // @53_42db40
  ecx = (ecx - edx);  // @54_42db40
  FL[3] = ecx;  // @55_42db40
  FL[2] = (ecx & ecx);  // @56_42db40
  if ((s32)FL[2] <= 0) goto L42dc19;  // @57_42db40
  eax = (u32)(EBP + ecx - 529);  // @58_42db40
  ecx = (u32)(EBP - 528);  // @59_42db40
  FL[0] = eax; FL[1] = ecx;  // @60_42db40
  if (FL[0] == FL[1]) goto L42dc19;  // @61_42db40
  L42dbf5:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @63_42db40
  FL[0] = (ecx & 0xff); FL[1] = (u32)(32);  // @64_42db40
  if (FL[0] == FL[1]) goto L42dc0b;  // @65_42db40
  FL[0] = (ecx & 0xff); FL[1] = (u32)(9);  // @66_42db40
  if (FL[0] == FL[1]) goto L42dc0b;  // @67_42db40
  FL[0] = (ecx & 0xff); FL[1] = (u32)(13);  // @68_42db40
  if (FL[0] == FL[1]) goto L42dc0b;  // @69_42db40
  FL[0] = (ecx & 0xff); FL[1] = (u32)(10);  // @70_42db40
  if (FL[0] != FL[1]) goto L42dc19;  // @71_42db40
  L42dc0b:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @73_42db40
  ecx = (u32)(EBP - 528);  // @74_42db40
  eax = (eax - 1);  // @75_42db40
  FL[3] = eax;  // @76_42db40
  FL[0] = eax; FL[1] = ecx;  // @77_42db40
  if (FL[0] != FL[1]) goto L42dbf5;  // @78_42db40
  L42dc19:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 528), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @80_42db40
  if (FL[0] == FL[1]) goto L42dcf5;  // @81_42db40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 527), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @82_42db40
  if (FL[0] == FL[1]) goto L42dcf5;  // @83_42db40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @84_42db40
  ecx = (u32)(EBP - 1040);  // @85_42db40
  PV[0] = (u32)(ecx);  // @86_42db40
  ecx = (u32)(EBP - 1552);  // @87_42db40
  PV[1] = (u32)(ecx);  // @88_42db40
  ecx = (u32)(EBP - 528);  // @89_42db40
  PV[2] = (u32)(ecx);  // @90_42db40
  ecx = ebx;  // @91_42db40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[2], PV[1], PV[0]);  // @92_42db40
  ecx = edx = 0;  // @93_42db40
  eax = (u32)(EBP - 1552);  // @94_42db40
  PV[3] = (u32)(eax);  // @95_42db40
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[3], (u32)(6790780));  // @96_42db40
  ecx = edx = 0;  // @97_42db40
  FL[2] = (eax & eax);  // @98_42db40
  if (FL[2] != 0) goto L42dce0;  // @99_42db40
  eax = (u32)(EBP - 1040);  // @100_42db40
  PV[4] = (u32)(eax);  // @101_42db40
  ecx = (u32)(EBP - 1680);  // @102_42db40
  eax = ext_4cbe80_thiscall2(ecx, PV[4]);  // @103_42db40
  ecx = edx = 0;  // @104_42db40
  eax = (u32)(EBP - 1680);  // @105_42db40
  reg.state = (s32)((u32)(0));  // @106_42db40
  PV[5] = (u32)(eax);  // @107_42db40
  ecx = (u32)(ebx + 6839);  // @108_42db40
  eax = ext_4cc2c0_thiscall2(ecx, PV[5]);  // @109_42db40
  ecx = edx = 0;  // @110_42db40
  ecx = (u32)(EBP - 1680);  // @111_42db40
  reg.state = (s32)((u32)(4294967295));  // @112_42db40
  eax = ext_4cbec0_thiscall1(ecx);  // @113_42db40
  ecx = edx = 0;  // @114_42db40
  ecx = (u32)(EBP - 1808);  // @115_42db40
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6777860));  // @116_42db40
  ecx = edx = 0;  // @117_42db40
  eax = (u32)(EBP - 1808);  // @118_42db40
  reg.state = (s32)((u32)(1));  // @119_42db40
  PV[6] = (u32)(eax);  // @120_42db40
  ecx = (u32)(ebx + 6839);  // @121_42db40
  eax = ext_4cc2c0_thiscall2(ecx, PV[6]);  // @122_42db40
  ecx = edx = 0;  // @123_42db40
  ecx = (u32)(EBP - 1808);  // @124_42db40
  reg.state = (s32)((u32)(4294967295));  // @125_42db40
  eax = ext_4cbec0_thiscall1(ecx);  // @126_42db40
  ecx = edx = 0;  // @127_42db40
  L42dce0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @129_42db40
  ecx = (u32)(EBP - 1040);  // @130_42db40
  PV[7] = (u32)(ecx);  // @131_42db40
  ecx = (u32)(EBP - 1552);  // @132_42db40
  PV[8] = (u32)(ecx);  // @133_42db40
  ecx = ebx;  // @134_42db40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[8], PV[7]);  // @135_42db40
  ecx = edx = 0;  // @136_42db40
  L42dcf5:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @138_42db40
  if (FL[0] != FL[1]) goto L42db80;  // @139_42db40
  L42dcfe:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @141_42db40
  SEH_LEAVE();  // @142_42db40
  ext_633654(G(u32, 0x6f5630));  // @143_42db40
  return eax;  // @144_42db40
  L42dd1e:;
  eax = ext_634047_cdecl0();  // @146_42db40
  ecx = edx = 0;  // @147_42db40
}
PCREG(42db40, lifted_42db40);

extern "C" u32 THISCALL lifted_4901f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ce8);  // @h_4901f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4901f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4901f0
  FL[2] = (ecx & ecx);  // @2_4901f0
  if (FL[2] != 0) goto L490293;  // @3_4901f0
  PV[0] = (u32)(ecx);  // @4_4901f0
  ecx = (u32)(EBP - 60);  // @5_4901f0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), PV[0]);  // @6_4901f0
  ecx = edx = 0;  // @7_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_4901f0
  ecx = (u32)(EBP - 60);  // @9_4901f0
  PV[1] = (u32)(ecx);  // @10_4901f0
  ecx = edi;  // @11_4901f0
  reg.state = (s32)((u32)(0));  // @12_4901f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 368)))(ecx, PV[1]);  // @13_4901f0
  ecx = edx = 0;  // @14_4901f0
  eax = (u32)(EBP - 32);  // @15_4901f0
  PV[2] = (u32)(eax);  // @16_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @17_4901f0
  ecx = (u32)(EBP - 60);  // @18_4901f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @19_4901f0
  ecx = edx = 0;  // @20_4901f0
  eax = (u32)(EBP - 32);  // @21_4901f0
  PV[3] = (u32)(eax);  // @22_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @23_4901f0
  ecx = (u32)(EBP - 60);  // @24_4901f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @25_4901f0
  ecx = edx = 0;  // @26_4901f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_4901f0
  if (FL[0] == FL[1]) goto L49027f;  // @28_4901f0
  L490261:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_4901f0
  ecx = edi;  // @31_4901f0
  PV[4] = (u32)(eax);  // @32_4901f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 360)))(ecx, PV[4]);  // @33_4901f0
  ecx = edx = 0;  // @34_4901f0
  eax = (u32)(EBP - 32);  // @35_4901f0
  PV[5] = (u32)(eax);  // @36_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @37_4901f0
  ecx = (u32)(EBP - 60);  // @38_4901f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @39_4901f0
  ecx = edx = 0;  // @40_4901f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @41_4901f0
  if (FL[0] != FL[1]) goto L490261;  // @42_4901f0
  L49027f:;
  ecx = (u32)(EBP - 60);  // @44_4901f0
  reg.state = (s32)((u32)(4294967295));  // @45_4901f0
  eax = ext_4cd0e0_thiscall1(ecx);  // @46_4901f0
  ecx = edx = 0;  // @47_4901f0
  goto L49038d;  // @48_4901f0
  L490293:;
  eax = ext_45e420_thiscall2(ecx, (u32)(1178815556));  // @50_4901f0
  ecx = edx = 0;  // @51_4901f0
  esi = eax;  // @52_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @53_4901f0
  eax = (eax & (u32)(3221225472));  // @54_4901f0
  FL[3] = eax;  // @55_4901f0
  FL[0] = eax; FL[1] = (u32)(1073741824);  // @56_4901f0
  if (FL[0] == FL[1]) goto L4902c1;  // @57_4901f0
  FL[0] = eax; FL[1] = (u32)(2147483648);  // @58_4901f0
  if (FL[0] == FL[1]) goto L4902c1;  // @59_4901f0
  ebx = (u32)(8);  // @60_4901f0
  FL[0] = eax; FL[1] = (u32)(3221225472);  // @61_4901f0
  if (FL[0] != FL[1]) goto L4902c4;  // @62_4901f0
  L4902c1:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @64_4901f0
  L4902c4:;
  ecx = esi;  // @66_4901f0
  eax = ext_48db70_thiscall1(ecx);  // @67_4901f0
  edx = 0;  // @68_4901f0
  ecx = 0;  // @69_4901f0
  FL[3] = ecx;  // @70_4901f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @71_4901f0
  esi = (esi + ebx);  // @72_4901f0
  FL[3] = esi;  // @73_4901f0
  FL[2] = (eax & eax);  // @74_4901f0
  if (FL[2] == 0) goto L49038d;  // @75_4901f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @76_4901f0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @77_4901f0
  X1[0] = F2U((float)(s32)X1[0]);  // @78_4901f0
  X1[1] = F2U((float)(s32)X1[1]);  // @79_4901f0
  X1[2] = F2U((float)(s32)X1[2]);  // @80_4901f0
  X1[3] = F2U((float)(s32)X1[3]);  // @81_4901f0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @82_4901f0
  L4902f0:;
  ecx = (ecx + 1);  // @84_4901f0
  FL[3] = ecx;  // @85_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @86_4901f0
  PV[6] = (u32)(ecx);  // @87_4901f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @88_4901f0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @89_4901f0
  ecx = edi;  // @90_4901f0
  X0[0] = F2U((float)(s32)X0[0]);  // @91_4901f0
  X0[1] = F2U((float)(s32)X0[1]);  // @92_4901f0
  X0[2] = F2U((float)(s32)X0[2]);  // @93_4901f0
  X0[3] = F2U((float)(s32)X0[3]);  // @94_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @95_4901f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @96_4901f0
  PV[7] = X0[0];  // @97_4901f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(1), (u32)(0), PV[7]);  // @98_4901f0
  ecx = edx = 0;  // @99_4901f0
  ecx = esi;  // @100_4901f0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @101_4901f0
  edx = (u32)(ecx + 1);  // @102_4901f0
  L490320:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @104_4901f0
  ecx = (ecx + 1);  // @105_4901f0
  FL[3] = ecx;  // @106_4901f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @107_4901f0
  if (FL[2] != 0) goto L490320;  // @108_4901f0
  ecx = (ecx - edx);  // @109_4901f0
  FL[3] = ecx;  // @110_4901f0
  eax = (u32)(ecx - 3);  // @111_4901f0
  eax = (eax + esi);  // @112_4901f0
  FL[3] = eax;  // @113_4901f0
  PV[8] = (u32)(eax);  // @114_4901f0
  eax = ((u32( *)(u32, u32))(ebx))(PV[8], (u32)(6871232));  // @115_4901f0
  ecx = edx = 0;  // @116_4901f0
  FL[2] = (eax & eax);  // @117_4901f0
  if (FL[2] == 0) goto L49036a;  // @118_4901f0
  ecx = esi;  // @119_4901f0
  edx = (u32)(ecx + 1);  // @120_4901f0
  L490342:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @122_4901f0
  ecx = (ecx + 1);  // @123_4901f0
  FL[3] = ecx;  // @124_4901f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @125_4901f0
  if (FL[2] != 0) goto L490342;  // @126_4901f0
  ecx = (ecx - edx);  // @127_4901f0
  FL[3] = ecx;  // @128_4901f0
  eax = (u32)(ecx - 3);  // @129_4901f0
  eax = (eax + esi);  // @130_4901f0
  FL[3] = eax;  // @131_4901f0
  PV[9] = (u32)(eax);  // @132_4901f0
  eax = ((u32( *)(u32, u32))(ebx))(PV[9], (u32)(6871236));  // @133_4901f0
  ecx = edx = 0;  // @134_4901f0
  FL[2] = (eax & eax);  // @135_4901f0
  if (FL[2] == 0) goto L49036a;  // @136_4901f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @137_4901f0
  ecx = edi;  // @138_4901f0
  PV[10] = (u32)(esi);  // @139_4901f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 360)))(ecx, PV[10]);  // @140_4901f0
  ecx = edx = 0;  // @141_4901f0
  L49036a:;
  ecx = esi;  // @143_4901f0
  edx = (u32)(ecx + 1);  // @144_4901f0
  L490370:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @146_4901f0
  ecx = (ecx + 1);  // @147_4901f0
  FL[3] = ecx;  // @148_4901f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @149_4901f0
  if (FL[2] != 0) goto L490370;  // @150_4901f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @151_4901f0
  X1[1] = 0;  // @152_4901f0
  X1[2] = 0;  // @153_4901f0
  X1[3] = 0;  // @154_4901f0
  ecx = (ecx - edx);  // @155_4901f0
  FL[3] = ecx;  // @156_4901f0
  ecx = (ecx + 1);  // @157_4901f0
  FL[3] = ecx;  // @158_4901f0
  esi = (esi + ecx);  // @159_4901f0
  FL[3] = esi;  // @160_4901f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @161_4901f0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @162_4901f0
  if (FL[0] != FL[1]) goto L4902f0;  // @163_4901f0
  L49038d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @165_4901f0
  ecx = edi;  // @166_4901f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @167_4901f0
  ecx = edx = 0;  // @168_4901f0
  SEH_LEAVE();  // @169_4901f0
  return eax;  // @170_4901f0
}
PCREG(4901f0, lifted_4901f0);

extern "C" u32 THISCALL lifted_42d420(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664e4c);  // @h_42d420
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_42d420
  eax = (u32)(EBP - 13);  // @1_42d420
  PV[0] = (u32)(eax);  // @2_42d420
  ecx = (u32)(EBP - 36);  // @3_42d420
  eax = ext_42b390_thiscall3(ecx, (u32)(6781786), PV[0]);  // @4_42d420
  ecx = edx = 0;  // @5_42d420
  eax = (u32)(EBP - 13);  // @6_42d420
  reg.state = (s32)((u32)(0));  // @7_42d420
  PV[1] = (u32)(eax);  // @8_42d420
  ecx = (u32)(EBP - 48);  // @9_42d420
  eax = ext_42b390_thiscall3(ecx, (u32)(6790740), PV[1]);  // @10_42d420
  ecx = edx = 0;  // @11_42d420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @13_42d420
  reg.state = (s32)((u32)(1));  // @14_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_42d420
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @16_42d420
  if (FL[0] == FL[1]) goto L42d48c;  // @17_42d420
  eax = (u32)(ecx + 12);  // @18_42d420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_42d420
  L42d48c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @21_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @22_42d420
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @23_42d420
  if (FL[0] == FL[1]) goto L42d4c3;  // @24_42d420
  L42d4a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @27_42d420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_42d420
  eax = (eax - edx);  // @29_42d420
  FL[3] = eax;  // @30_42d420
  FL[0] = eax; FL[1] = (u32)(1);  // @31_42d420
  if (FL[0] != FL[1]) goto L42d4c3;  // @32_42d420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @33_42d420
  if (FL[0] != FL[1]) goto L42d4c3;  // @34_42d420
  ecx = (ecx + (u32)(12));  // @35_42d420
  FL[3] = ecx;  // @36_42d420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @37_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @38_42d420
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @39_42d420
  if (FL[0] != FL[1]) goto L42d4a0;  // @40_42d420
  L42d4c3:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @43_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_42d420
  eax = (eax - ecx);  // @45_42d420
  FL[3] = eax;  // @46_42d420
  FL[0] = eax; FL[1] = (u32)(1);  // @47_42d420
  if (FL[0] != FL[1]) goto L42d4e0;  // @48_42d420
  PV[2] = (u32)(eax);  // @49_42d420
  edx = (u32)(6777860);  // @50_42d420
  eax = ext_4309b0_fastcall3(ecx, edx, PV[2]);  // @51_42d420
  ecx = edx = 0;  // @52_42d420
  FL[2] = (eax & eax);  // @53_42d420
  if (FL[2] == 0) goto L42d4f6;  // @54_42d420
  L42d4e0:;
  eax = (u32)(EBP - 36);  // @56_42d420
  FL[0] = edi; FL[1] = eax;  // @57_42d420
  if (FL[0] == FL[1]) goto L42d4f3;  // @58_42d420
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @59_42d420
  ecx = eax;  // @60_42d420
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @61_42d420
  eax = ext_5f2d60_thiscall3(ecx, PV[4], PV[3]);  // @62_42d420
    // @63_42d420
  L42d4f3:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @65_42d420
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_42d420
  L42d4f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @68_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @69_42d420
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @70_42d420
  if (FL[0] == FL[1]) goto L42d526;  // @71_42d420
  L42d503:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @74_42d420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_42d420
  eax = (eax - edx);  // @76_42d420
  FL[3] = eax;  // @77_42d420
  FL[0] = eax; FL[1] = (u32)(1);  // @78_42d420
  if (FL[0] != FL[1]) goto L42d516;  // @79_42d420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @80_42d420
  if (FL[0] == FL[1]) goto L42d526;  // @81_42d420
  L42d516:;
  ecx = (ecx + (u32)(12));  // @83_42d420
  FL[3] = ecx;  // @84_42d420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @85_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @86_42d420
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @87_42d420
  if (FL[0] != FL[1]) goto L42d503;  // @88_42d420
  L42d526:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @90_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @91_42d420
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @92_42d420
  if (FL[0] == FL[1]) goto L42d556;  // @93_42d420
  L42d533:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @96_42d420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_42d420
  eax = (eax - edx);  // @98_42d420
  FL[3] = eax;  // @99_42d420
  FL[0] = eax; FL[1] = (u32)(1);  // @100_42d420
  if (FL[0] != FL[1]) goto L42d556;  // @101_42d420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @102_42d420
  if (FL[0] != FL[1]) goto L42d556;  // @103_42d420
  ecx = (ecx + (u32)(12));  // @104_42d420
  FL[3] = ecx;  // @105_42d420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @106_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7021), sizeof v); (u32)v; });  // @107_42d420
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @108_42d420
  if (FL[0] != FL[1]) goto L42d533;  // @109_42d420
  L42d556:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7013), sizeof v); (u32)v; });  // @111_42d420
  eax = (u32)(EBP - 36);  // @112_42d420
  PV[5] = (u32)(eax);  // @113_42d420
  eax = (u32)(EBP - 17);  // @114_42d420
  ecx = ebx;  // @115_42d420
  PV[6] = (u32)(eax);  // @116_42d420
  eax = ext_431330_thiscall3(ecx, PV[6], PV[5]);  // @117_42d420
  ecx = edx = 0;  // @118_42d420
  esi = eax;  // @119_42d420
  ecx = ebx;  // @120_42d420
  eax = (u32)(EBP - 36);  // @121_42d420
  PV[7] = (u32)(eax);  // @122_42d420
  eax = (u32)(EBP - 21);  // @123_42d420
  PV[8] = (u32)(eax);  // @124_42d420
  eax = ext_431110_thiscall3(ecx, PV[8], PV[7]);  // @125_42d420
  ecx = edx = 0;  // @126_42d420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @127_42d420
  ecx = (u32)(EBP + 8);  // @128_42d420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @129_42d420
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @130_42d420
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @131_42d420
  PV[10] = (u32)(ecx);  // @132_42d420
  eax = 0;  // @133_42d420
  PV[11] = (u32)(ecx);  // @134_42d420
  PV[12] = esi;  // @135_42d420
  eax = 0;  // @136_42d420
  PV[13] = edi;  // @137_42d420
  eax = ext_42b0f0_thiscall4(ecx, PV[13], PV[12], PV[9]);  // @138_42d420
  ecx = edx = 0;  // @139_42d420
  PV[14] = (u32)(ecx);  // @140_42d420
  eax = 0;  // @141_42d420
  PV[15] = (u32)(ecx);  // @142_42d420
  ecx = ebx;  // @143_42d420
  PV[16] = esi;  // @144_42d420
  eax = 0;  // @145_42d420
  PV[17] = edi;  // @146_42d420
  eax = ext_430a20_thiscall3(ecx, PV[17], PV[16]);  // @147_42d420
  ecx = edx = 0;  // @148_42d420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @149_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @150_42d420
  eax = (eax - ecx);  // @151_42d420
  FL[3] = eax;  // @152_42d420
  reg.state = (s32)((u32)(2));  // @153_42d420
  FL[2] = (ecx & ecx);  // @154_42d420
  if (FL[2] == 0) goto L42d5cb;  // @155_42d420
  FL[2] = (eax & eax);  // @156_42d420
  if (FL[2] == 0) goto L42d5cb;  // @157_42d420
  PV[18] = (u32)(eax);  // @158_42d420
  PV[19] = (u32)(ecx);  // @159_42d420
  ecx = (u32)(EBP - 48);  // @160_42d420
  eax = ext_54f870_stdcall2(PV[19], PV[18]);  // @161_42d420
  ecx = edx = 0;  // @162_42d420
  L42d5cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @164_42d420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @165_42d420
  eax = (eax - ecx);  // @166_42d420
  FL[3] = eax;  // @167_42d420
  reg.state = (s32)((u32)(3));  // @168_42d420
  FL[2] = (ecx & ecx);  // @169_42d420
  if (FL[2] == 0) goto L42d5ec;  // @170_42d420
  FL[2] = (eax & eax);  // @171_42d420
  if (FL[2] == 0) goto L42d5ec;  // @172_42d420
  PV[20] = (u32)(eax);  // @173_42d420
  PV[21] = (u32)(ecx);  // @174_42d420
  ecx = (u32)(EBP - 36);  // @175_42d420
  eax = ext_54f870_stdcall2(PV[21], PV[20]);  // @176_42d420
  ecx = edx = 0;  // @177_42d420
  L42d5ec:;
  SEH_LEAVE();  // @179_42d420
  return eax;  // @180_42d420
}
PCREG(42d420, lifted_42d420);

extern "C" u32 THISCALL lifted_493550(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667e9e);  // @h_493550
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_493550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @1_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_493550
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(4124));  // @3_493550
  ecx = edx = 0;  // @4_493550
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_493550
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_493550
  ecx = (u32)(esi + 2);  // @7_493550
  PV[0] = (u32)(ecx);  // @8_493550
  PV[1] = (u32)(eax);  // @9_493550
  eax = ((u32(*)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[1], (u32)(6873020), PV[0]);  // @10_493550 (cdecl varargs log, caller cleans; hand fix)
  ecx = edx = 0;  // @11_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @12_493550
  eax = ext_41e290_cdecl1((u32)(28));  // @13_493550
  ecx = edx = 0;  // @14_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @15_493550
  reg.state = (s32)((u32)(0));  // @16_493550
  FL[2] = (eax & eax);  // @17_493550
  if (FL[2] == 0) goto L4935ce;  // @18_493550
  ecx = eax;  // @19_493550
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(0));  // @20_493550
  ecx = edx = 0;  // @21_493550
  goto L4935d0;  // @22_493550
  L4935ce:;
  eax = 0;  // @24_493550
  FL[3] = eax;  // @25_493550
  L4935d0:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @27_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3017), sizeof v); (u32)v; });  // @28_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @29_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4432), &v, sizeof v); }  // @30_493550
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 23845), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 23845), &v, sizeof v); }  // @31_493550
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 23845), sizeof v); (u32)v; });  // @32_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 3017), &v, sizeof v); }  // @33_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_493550
  reg.state = (s32)((u32)(4294967295));  // @35_493550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @36_493550
  FL[2] = (ecx & ecx);  // @37_493550
  if (FL[2] == 0) goto L493616;  // @38_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_493550
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(6781786));  // @40_493550
  ecx = edx = 0;  // @41_493550
  L493616:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2780), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @43_493550
  if (FL[0] == FL[1]) goto L493809;  // @44_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @45_493550
  edi = (u32)(esi + 140);  // @46_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_493550
  ecx = (u32)(32);  // @48_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @49_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4408), &v, sizeof v); }  // @50_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 6407), &v, sizeof v); }  // @52_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7261), sizeof v); (u32)v; });  // @53_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4420), &v, sizeof v); }  // @54_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @55_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 7261), &v, sizeof v); }  // @56_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4424), &v, sizeof v); }  // @57_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @58_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @59_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4428), &v, sizeof v); }  // @60_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2796), sizeof v); (u32)v; });  // @61_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @62_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4436), &v, sizeof v); }  // @63_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2780), sizeof v); (u32)v; });  // @64_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 2796), &v, sizeof v); }  // @65_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @66_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @67_493550
  esi = (u32)(ebx + 72);  // @68_493550
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @69_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_493550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @71_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_493550
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 152)))(ecx);  // @73_493550
  ecx = edx = 0;  // @74_493550
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @75_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @76_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_493550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @78_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_493550
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, (u32)(0));  // @80_493550
  ecx = edx = 0;  // @81_493550
  eax = ext_41e290_cdecl1((u32)(44));  // @82_493550
  ecx = edx = 0;  // @83_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @84_493550
  reg.state = (s32)((u32)(1));  // @85_493550
  FL[2] = (eax & eax);  // @86_493550
  if (FL[2] == 0) goto L493717;  // @87_493550
  ecx = eax;  // @88_493550
  eax = ext_4ccad0_thiscall3(ecx, (u32)(8), (u32)(0));  // @89_493550
  ecx = edx = 0;  // @90_493550
  edx = eax;  // @91_493550
  goto L493719;  // @92_493550
  L493717:;
  edx = 0;  // @94_493550
  FL[3] = edx;  // @95_493550
  L493719:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_493550
  PV[2] = (u32)(edx);  // @98_493550
  reg.state = (s32)((u32)(4294967295));  // @99_493550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @100_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @101_493550
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, PV[2]);  // @102_493550
  ecx = edx = 0;  // @103_493550
  eax = (u32)(ebx + 72);  // @104_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 2780), &v, sizeof v); }  // @105_493550
  PV[3] = (u32)(eax);  // @106_493550
  eax = ext_634d10_cdecl3(PV[3], (u32)(0), (u32)(128));  // @107_493550
    // @108_493550
  edi = (u32)(ebx + 3149);  // @109_493550
  eax = (u32)(esi + 284);  // @110_493550
  PV[4] = (u32)(edi);  // @111_493550
  PV[5] = (u32)(eax);  // @112_493550
  eax = ext_634d22_cdecl3(PV[5], PV[4], (u32)(4104));  // @113_493550
    // @114_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7253), sizeof v); (u32)v; });  // @115_493550
  edx = (u32)(esi + 4396);  // @116_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4388), &v, sizeof v); }  // @117_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_493550
  ecx = (u32)(eax + 64);  // @119_493550
  FL[0] = edx; FL[1] = ecx;  // @120_493550
  if (FL[0] == FL[1]) goto L493790;  // @121_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @123_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_493550
  L493790:;
  ecx = (u32)(eax + 68);  // @126_493550
  edx = (u32)(esi + 4400);  // @127_493550
  FL[0] = edx; FL[1] = ecx;  // @128_493550
  if (FL[0] == FL[1]) goto L4937a6;  // @129_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @131_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_493550
  L4937a6:;
  eax = (eax + (u32)(48));  // @134_493550
  FL[3] = eax;  // @135_493550
  ecx = (u32)(esi + 4404);  // @136_493550
  FL[0] = ecx; FL[1] = eax;  // @137_493550
  if (FL[0] == FL[1]) goto L4937b7;  // @138_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @139_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @140_493550
  L4937b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 200), sizeof v); (u32)v; });  // @142_493550
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4440), &v, sizeof v); }  // @143_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 200), &v, sizeof v); }  // @144_493550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_493550
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 364)))(ecx);  // @147_493550
  ecx = edx = 0;  // @148_493550
  PV[6] = (u32)(edi);  // @149_493550
  eax = ext_634d10_cdecl3(PV[6], (u32)(0), (u32)(4104));  // @150_493550
    // @151_493550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @152_493550
  ecx = ebx;  // @153_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 7257), &v, sizeof v); }  // @154_493550
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 7253), &v, sizeof v); }  // @155_493550
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 404)))(ecx);  // @156_493550
  ecx = edx = 0;  // @157_493550
  L493809:;
  SEH_LEAVE();  // @159_493550
  return eax;  // @160_493550
}
PCREG(493550, lifted_493550);

extern "C" u32 THISCALL lifted_434010(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6656fa);  // @h_434010
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_434010
  ecx = (u32)(EBP - 272);  // @2_434010
  PV[0] = (u32)(eax);  // @3_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @4_434010
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @5_434010
  ecx = edx = 0;  // @6_434010
  ecx = (u32)(EBP - 272);  // @7_434010
  reg.state = (s32)((u32)(0));  // @8_434010
  eax = ext_4cc5f0_thiscall1(ecx);  // @9_434010
  ecx = edx = 0;  // @10_434010
  ebx = eax;  // @11_434010
  esi = 0;  // @12_434010
  FL[3] = esi;  // @13_434010
  FL[2] = (ebx & ebx);  // @14_434010
  if (FL[2] == 0) goto L434095;  // @15_434010
  L434070:;
  ecx = (u32)(EBP - 272);  // @17_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @18_434010
    // @19_434010
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }); FL[1] = (u32)(92);  // @20_434010
  if (FL[0] != FL[1]) goto L434090;  // @21_434010
  ecx = (u32)(EBP - 272);  // @22_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @23_434010
    // @24_434010
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @25_434010
  L434090:;
  esi = (esi + 1);  // @27_434010
  FL[3] = esi;  // @28_434010
  FL[0] = esi; FL[1] = ebx;  // @29_434010
  if (FL[0] != FL[1]) goto L434070;  // @30_434010
  L434095:;
  eax = (u32)(EBP - 272);  // @32_434010
  PV[1] = (u32)(eax);  // @33_434010
  ecx = (u32)(EBP - 144);  // @34_434010
  eax = ext_4cbe50_thiscall2(ecx, PV[1]);  // @35_434010
  ecx = edx = 0;  // @36_434010
  ecx = (u32)(EBP - 144);  // @37_434010
  reg.state = (s32)((u32)(1));  // @38_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @39_434010
    // @40_434010
  PV[2] = (u32)(eax);  // @41_434010
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[2], (u32)(46));  // @42_434010
  ecx = edx = 0;  // @43_434010
  FL[2] = (eax & eax);  // @44_434010
  if (FL[2] == 0) goto L434214;  // @45_434010
  { u32 v = (u32)((u32)(1346984494)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_434010
  ecx = (u32)(EBP - 144);  // @47_434010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @49_434010
    // @50_434010
  PV[3] = (u32)(eax);  // @51_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 160), sizeof v); (u32)v; });  // @52_434010
  ecx = edi;  // @53_434010
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[3]);  // @54_434010
  ecx = edx = 0;  // @55_434010
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @56_434010
  if (FL[2] != 0) goto L434214;  // @57_434010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_434010
  ecx = (u32)(EBP - 144);  // @59_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @60_434010
    // @61_434010
  PV[4] = (u32)(eax);  // @62_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @63_434010
  ecx = edi;  // @64_434010
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[4], (u32)(1));  // @65_434010
  ecx = edx = 0;  // @66_434010
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @67_434010
  if (FL[2] == 0) goto L4341eb;  // @68_434010
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @69_434010
  if (FL[0] != FL[1]) goto L434143;  // @70_434010
  eax = ext_41e290_cdecl1((u32)(40));  // @71_434010
  ecx = edx = 0;  // @72_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @73_434010
  reg.state = (s32)((u32)(2));  // @74_434010
  FL[2] = (eax & eax);  // @75_434010
  if (FL[2] == 0) goto L43413a;  // @76_434010
  ecx = eax;  // @77_434010
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(1));  // @78_434010
  ecx = edx = 0;  // @79_434010
  goto L43413c;  // @80_434010
  L43413a:;
  eax = 0;  // @82_434010
  FL[3] = eax;  // @83_434010
  L43413c:;
  reg.state = (s32)((u32)(1));  // @85_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @86_434010
  L434143:;
  eax = ext_41e290_cdecl1((u32)(111));  // @88_434010
  ecx = edx = 0;  // @89_434010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @90_434010
  reg.state = (s32)((u32)(3));  // @91_434010
  FL[2] = (eax & eax);  // @92_434010
  if (FL[2] == 0) goto L434166;  // @93_434010
  ecx = eax;  // @94_434010
  eax = ext_4d5440_thiscall1(ecx);  // @95_434010
  ecx = edx = 0;  // @96_434010
  ebx = eax;  // @97_434010
  goto L434168;  // @98_434010
  L434166:;
  ebx = 0;  // @100_434010
  FL[3] = ebx;  // @101_434010
  L434168:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @103_434010
  ecx = (u32)(5);  // @104_434010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @105_434010
  eax = (u32)(2);  // @106_434010
  if (FL[0] != FL[1]) eax = ecx;  // @107_434010
  reg.state = (s32)((u32)(1));  // @108_434010
  PV[5] = (u32)(eax);  // @109_434010
  ecx = (u32)(EBP - 144);  // @110_434010
  eax = ext_4cc1d0_thiscall1(ecx);  // @111_434010
    // @112_434010
  PV[6] = (u32)(eax);  // @113_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @114_434010
  ecx = ebx;  // @115_434010
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[6], PV[5]);  // @116_434010
  ecx = edx = 0;  // @117_434010
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @118_434010
  if (FL[2] == 0) goto L4341eb;  // @119_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @120_434010
  FL[2] = (ecx & ecx);  // @121_434010
  if (FL[2] == 0) goto L4341db;  // @122_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_434010
  edx = (u32)(EBP - 292);  // @124_434010
  PV[7] = (u32)(edx);  // @125_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @126_434010
  ecx = edx = 0;  // @127_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @128_434010
  edx = (u32)(EBP - 292);  // @129_434010
  PV[8] = (u32)(edx);  // @130_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @132_434010
  ecx = edx = 0;  // @133_434010
  FL[2] = (eax & eax);  // @134_434010
  if (FL[2] == 0) goto L4341db;  // @135_434010
  L4341c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @137_434010
  PV[9] = (u32)(ebx);  // @138_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[9]);  // @140_434010
  ecx = edx = 0;  // @141_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @142_434010
  edx = (u32)(EBP - 292);  // @143_434010
  PV[10] = (u32)(edx);  // @144_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[10]);  // @146_434010
  ecx = edx = 0;  // @147_434010
  FL[2] = (eax & eax);  // @148_434010
  if (FL[2] != 0) goto L4341c0;  // @149_434010
  L4341db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @151_434010
  PV[11] = (u32)(ebx);  // @152_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_434010
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[11]);  // @154_434010
  ecx = edx = 0;  // @155_434010
  esi = eax;  // @156_434010
  goto L434216;  // @157_434010
  L4341eb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @159_434010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_434010
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6792428), (u32)(445));  // @161_434010
  ecx = edx = 0;  // @162_434010
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @163_434010
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @164_434010
  PV[13] = (u32)(eax);  // @165_434010
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[13], (u32)(6792552), PV[12]);  // @166_434010
  ecx = edx = 0;  // @167_434010
  L434214:;
  esi = 0;  // @169_434010
  FL[3] = esi;  // @170_434010
  L434216:;
  ecx = (u32)(EBP - 144);  // @172_434010
  eax = ext_4cbec0_thiscall1(ecx);  // @173_434010
  ecx = edx = 0;  // @174_434010
  ecx = (u32)(EBP - 272);  // @175_434010
  eax = ext_4cbec0_thiscall1(ecx);  // @176_434010
  ecx = edx = 0;  // @177_434010
  eax = esi;  // @178_434010
  SEH_LEAVE();  // @179_434010
  ext_633654(G(u32, 0x6f5630));  // @180_434010
  return eax;  // @181_434010
}
PCREG(434010, lifted_434010);

extern "C" u32 THISCALL lifted_439970(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665b80);  // @h_439970
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_439970
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @2_439970
  FL[2] = (ecx & ecx);  // @3_439970
  if (FL[2] != 0) goto L439a0f;  // @4_439970
  eax = ext_41e290_cdecl1((u32)(28));  // @5_439970
  ecx = edx = 0;  // @6_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_439970
  reg.state = (s32)((u32)(0));  // @8_439970
  FL[2] = (eax & eax);  // @9_439970
  if (FL[2] == 0) goto L4399cc;  // @10_439970
  ecx = eax;  // @11_439970
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(45));  // @12_439970
  ecx = edx = 0;  // @13_439970
  goto L4399ce;  // @14_439970
  L4399cc:;
  eax = 0;  // @16_439970
  FL[3] = eax;  // @17_439970
  L4399ce:;
  reg.state = (s32)((u32)(4294967295));  // @19_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4920), &v, sizeof v); }  // @20_439970
  L4399db:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_439970
  L4399de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @24_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @26_439970
  ecx = edx = 0;  // @27_439970
  ebx = eax;  // @28_439970
  ebx = (ebx - (u32)(4));  // @29_439970
  FL[3] = ebx;  // @30_439970
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_439970
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @32_439970
  reg.state = (s32)((u32)(1));  // @33_439970
  if (FL[3] == 0) goto L439a93;  // @34_439970
  ecx = ebx;  // @35_439970
  eax = ext_4cbeb0_thiscall1(ecx);  // @36_439970
    // @37_439970
  goto L439a95;  // @38_439970
  L439a0f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_439970
  edx = (u32)(EBP - 36);  // @41_439970
  PV[0] = (u32)(edx);  // @42_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @43_439970
  ecx = edx = 0;  // @44_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @45_439970
  edx = (u32)(EBP - 36);  // @46_439970
  PV[1] = (u32)(edx);  // @47_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @49_439970
  ecx = edx = 0;  // @50_439970
  ebx = eax;  // @51_439970
  FL[2] = (ebx & ebx);  // @52_439970
  if (FL[2] == 0) goto L4399db;  // @53_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @54_439970
  L439a30:;
  PV[2] = (u32)(edi);  // @56_439970
  ecx = ebx;  // @57_439970
  eax = ext_4cc130_thiscall2(ecx, PV[2]);  // @58_439970
  ecx = edx = 0;  // @59_439970
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @60_439970
  if (FL[2] == 0) goto L439a79;  // @61_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 175), sizeof v); (u32)v; });  // @62_439970
  FL[2] = (eax & eax);  // @63_439970
  if (FL[2] == 0) goto L439a79;  // @64_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 175), sizeof v); (u32)v; });  // @65_439970
  FL[2] = (ecx & ecx);  // @66_439970
  if (FL[2] == 0) goto L439a79;  // @67_439970
  L439a50:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @69_439970
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_439970
  if (FL[0] != FL[1]) goto L439a70;  // @71_439970
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @72_439970
  if (FL[2] == 0) goto L439a6c;  // @73_439970
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @74_439970
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @75_439970
  if (FL[0] != FL[1]) goto L439a70;  // @76_439970
  eax = (eax + (u32)(2));  // @77_439970
  FL[3] = eax;  // @78_439970
  ecx = (ecx + (u32)(2));  // @79_439970
  FL[3] = ecx;  // @80_439970
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @81_439970
  if (FL[2] != 0) goto L439a50;  // @82_439970
  L439a6c:;
  eax = 0;  // @84_439970
  FL[3] = eax;  // @85_439970
  goto L439a75;  // @86_439970
  L439a70:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @88_439970
  eax = (eax | (u32)(1));  // @89_439970
  FL[3] = eax;  // @90_439970
  L439a75:;
  FL[2] = (eax & eax);  // @92_439970
  if (FL[2] == 0) goto L439a9c;  // @93_439970
  L439a79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @95_439970
  edx = (u32)(EBP - 36);  // @96_439970
  PV[3] = (u32)(edx);  // @97_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[3]);  // @99_439970
  ecx = edx = 0;  // @100_439970
  ebx = eax;  // @101_439970
  FL[2] = (ebx & ebx);  // @102_439970
  if (FL[2] != 0) goto L439a30;  // @103_439970
  goto L4399de;  // @104_439970
  L439a93:;
  ebx = 0;  // @106_439970
  FL[3] = ebx;  // @107_439970
  L439a95:;
  reg.state = (s32)((u32)(4294967295));  // @109_439970
  L439a9c:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; })) & 0xff);  // @111_439970
  ecx = ebx;  // @112_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @113_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; });  // @114_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 161), &v, sizeof v); }  // @115_439970
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; })) & 0xff);  // @116_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 165), &v, sizeof v); }  // @117_439970
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; })) & 0xff);  // @118_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 166), &v, sizeof v); }  // @119_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 167), sizeof v); (u32)v; });  // @120_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 167), &v, sizeof v); }  // @121_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 171), sizeof v); (u32)v; });  // @122_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 171), &v, sizeof v); }  // @123_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 175), sizeof v); (u32)v; });  // @124_439970
  PV[4] = (u32)(edi);  // @125_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 175), &v, sizeof v); }  // @126_439970
  eax = ext_4cbee0_thiscall2(ecx, PV[4]);  // @127_439970
  ecx = edx = 0;  // @128_439970
  esi = ebx;  // @129_439970
  eax = (u32)(edi + 128);  // @130_439970
  edx = 0;  // @131_439970
  FL[3] = edx;  // @132_439970
  esi = (esi - edi);  // @133_439970
  FL[3] = esi;  // @134_439970
  L439b04:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @136_439970
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @137_439970
  FL[0] = ecx; FL[1] = (u32)(-1);  // @138_439970
  if (FL[0] == FL[1]) goto L439b20;  // @139_439970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax), &v, sizeof v); }  // @140_439970
  edx = (edx + 1);  // @141_439970
  FL[3] = edx;  // @142_439970
  eax = (eax + (u32)(4));  // @143_439970
  FL[3] = eax;  // @144_439970
  FL[0] = edx; FL[1] = (u32)(4);  // @145_439970
  if ((s32)FL[0] < (s32)FL[1]) goto L439b04;  // @146_439970
  goto L439b38;  // @147_439970
  L439b20:;
  FL[0] = edx; FL[1] = (u32)(4);  // @149_439970
  if ((s32)FL[0] >= (s32)FL[1]) goto L439b38;  // @150_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @151_439970
  edi = (u32)(edx + 32);  // @152_439970
  ecx = (ecx - edx);  // @153_439970
  FL[3] = ecx;  // @154_439970
  edi = (u32)(ebx + edi*4);  // @155_439970
  eax = (eax | (u32)(4294967295));  // @156_439970
  FL[3] = eax;  // @157_439970
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @158_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @159_439970
  L439b38:;
  ecx = 0;  // @161_439970
  FL[3] = ecx;  // @162_439970
  eax = (u32)(edi + 144);  // @163_439970
  L439b40:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @165_439970
  FL[0] = edx; FL[1] = (u32)(-1);  // @166_439970
  if (FL[0] == FL[1]) goto L439b55;  // @167_439970
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @168_439970
  ecx = (ecx + 1);  // @169_439970
  FL[3] = ecx;  // @170_439970
  eax = (eax + (u32)(4));  // @171_439970
  FL[3] = eax;  // @172_439970
  FL[0] = ecx; FL[1] = (u32)(4);  // @173_439970
  if ((s32)FL[0] < (s32)FL[1]) goto L439b40;  // @174_439970
  goto L439b6c;  // @175_439970
  L439b55:;
  FL[0] = ecx; FL[1] = (u32)(4);  // @177_439970
  if ((s32)FL[0] >= (s32)FL[1]) goto L439b6c;  // @178_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @179_439970
  edi = (u32)(ecx + 36);  // @180_439970
  eax = (eax - ecx);  // @181_439970
  FL[3] = eax;  // @182_439970
  edi = (u32)(ebx + edi*4);  // @183_439970
  ecx = eax;  // @184_439970
  eax = (eax | (u32)(4294967295));  // @185_439970
  FL[3] = eax;  // @186_439970
  while (ecx) { __builtin_memcpy((void *)edi, &eax, 4); edi += 4; ecx--; }  // @187_439970
  L439b6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 175), sizeof v); (u32)v; });  // @189_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @190_439970
  FL[2] = (ecx & ecx);  // @191_439970
  if (FL[2] != 0) goto L439b8a;  // @192_439970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @193_439970
  ecx = ebx;  // @194_439970
  eax = ext_4cc1d0_thiscall1(ecx);  // @195_439970
    // @196_439970
  PV[5] = (u32)(eax);  // @197_439970
  ecx = edi;  // @198_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[5]);  // @199_439970
  ecx = edx = 0;  // @200_439970
  goto L439ba7;  // @201_439970
  L439b8a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @203_439970
  PV[6] = (u32)(ecx);  // @204_439970
  ecx = edi;  // @205_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[6]);  // @206_439970
  ecx = edx = 0;  // @207_439970
  edi = eax;  // @208_439970
  FL[2] = (edi & edi);  // @209_439970
  if (FL[2] == 0) goto L439bb9;  // @210_439970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @211_439970
  ecx = ebx;  // @212_439970
  eax = ext_4cc1d0_thiscall1(ecx);  // @213_439970
    // @214_439970
  PV[7] = (u32)(eax);  // @215_439970
  ecx = edi;  // @216_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 16)))(ecx, PV[7]);  // @217_439970
  ecx = edx = 0;  // @218_439970
  L439ba7:;
  FL[2] = (eax & eax);  // @220_439970
  if (FL[2] == 0) goto L439bb9;  // @221_439970
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @222_439970
  if (FL[0] != FL[1]) goto L439bb9;  // @223_439970
  PV[8] = (u32)(ebx);  // @224_439970
  ecx = (u32)(eax - 4);  // @225_439970
  eax = ext_439fd0_thiscall2(ecx, PV[8]);  // @226_439970
  ecx = edx = 0;  // @227_439970
  L439bb9:;
  SEH_LEAVE();  // @229_439970
  return eax;  // @230_439970
}
PCREG(439970, lifted_439970);

extern "C" u32 THISCALL lifted_42d000(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664e0c);  // @h_42d000
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_42d000
  eax = (u32)(EBP - 13);  // @1_42d000
  PV[0] = (u32)(eax);  // @2_42d000
  ecx = (u32)(EBP - 40);  // @3_42d000
  eax = ext_42b390_thiscall3(ecx, (u32)(6781786), PV[0]);  // @4_42d000
  ecx = edx = 0;  // @5_42d000
  eax = (u32)(EBP - 13);  // @6_42d000
  reg.state = (s32)((u32)(0));  // @7_42d000
  PV[1] = (u32)(eax);  // @8_42d000
  ecx = (u32)(EBP - 28);  // @9_42d000
  eax = ext_42b390_thiscall3(ecx, (u32)(6781786), PV[1]);  // @10_42d000
  ecx = edx = 0;  // @11_42d000
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @13_42d000
  reg.state = (s32)((u32)(1));  // @14_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @16_42d000
  if (FL[0] == FL[1]) goto L42d06c;  // @17_42d000
  eax = (u32)(ecx + 12);  // @18_42d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_42d000
  L42d06c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @21_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @22_42d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @23_42d000
  if (FL[0] == FL[1]) goto L42d0a3;  // @24_42d000
  L42d080:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @27_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_42d000
  eax = (eax - edx);  // @29_42d000
  FL[3] = eax;  // @30_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @31_42d000
  if (FL[0] != FL[1]) goto L42d0a3;  // @32_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @33_42d000
  if (FL[0] != FL[1]) goto L42d0a3;  // @34_42d000
  ecx = (ecx + (u32)(12));  // @35_42d000
  FL[3] = ecx;  // @36_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @37_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @38_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @39_42d000
  if (FL[0] != FL[1]) goto L42d080;  // @40_42d000
  L42d0a3:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @43_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_42d000
  eax = (eax - ecx);  // @45_42d000
  FL[3] = eax;  // @46_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @47_42d000
  if (FL[0] != FL[1]) goto L42d0c0;  // @48_42d000
  PV[2] = (u32)(eax);  // @49_42d000
  edx = (u32)(6777860);  // @50_42d000
  eax = ext_4309b0_fastcall3(ecx, edx, PV[2]);  // @51_42d000
  ecx = edx = 0;  // @52_42d000
  FL[2] = (eax & eax);  // @53_42d000
  if (FL[2] == 0) goto L42d0d6;  // @54_42d000
  L42d0c0:;
  eax = (u32)(EBP - 40);  // @56_42d000
  FL[0] = ebx; FL[1] = eax;  // @57_42d000
  if (FL[0] == FL[1]) goto L42d0d3;  // @58_42d000
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @59_42d000
  ecx = eax;  // @60_42d000
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_42d000
  eax = ext_5f2d60_thiscall3(ecx, PV[4], PV[3]);  // @62_42d000
    // @63_42d000
  L42d0d3:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @65_42d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_42d000
  L42d0d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @68_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @69_42d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @70_42d000
  if (FL[0] == FL[1]) goto L42d106;  // @71_42d000
  L42d0e3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @74_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_42d000
  eax = (eax - edx);  // @76_42d000
  FL[3] = eax;  // @77_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @78_42d000
  if (FL[0] != FL[1]) goto L42d106;  // @79_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @80_42d000
  if (FL[0] != FL[1]) goto L42d106;  // @81_42d000
  ecx = (ecx + (u32)(12));  // @82_42d000
  FL[3] = ecx;  // @83_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @84_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @85_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @86_42d000
  if (FL[0] != FL[1]) goto L42d0e3;  // @87_42d000
  L42d106:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @89_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @91_42d000
  if (FL[0] == FL[1]) goto L42d190;  // @92_42d000
  L42d113:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @94_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_42d000
  eax = (eax - edx);  // @96_42d000
  FL[3] = eax;  // @97_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @98_42d000
  if (FL[0] != FL[1]) goto L42d124;  // @99_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @100_42d000
  if (FL[0] == FL[1]) goto L42d190;  // @101_42d000
  L42d124:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @103_42d000
  eax = (eax - edx);  // @104_42d000
  FL[3] = eax;  // @105_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @106_42d000
  if (FL[0] != FL[1]) goto L42d133;  // @107_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @108_42d000
  if (FL[0] == FL[1]) goto L42d190;  // @109_42d000
  L42d133:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @111_42d000
  eax = (eax - edx);  // @112_42d000
  FL[3] = eax;  // @113_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @114_42d000
  if (FL[0] != FL[1]) goto L42d174;  // @115_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(36);  // @116_42d000
  if (FL[0] != FL[1]) goto L42d174;  // @117_42d000
  eax = (u32)(ecx + 12);  // @118_42d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @119_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @120_42d000
  PV[5] = (u32)(eax);  // @121_42d000
  eax = ext_42be20_thiscall2(ecx, PV[5]);  // @122_42d000
  ecx = edx = 0;  // @123_42d000
  ecx = (u32)(EBP - 28);  // @124_42d000
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @125_42d000
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @126_42d000
  eax = ext_5f2c60_thiscall3(ecx, PV[7], PV[6]);  // @127_42d000
  ecx = edx = 0;  // @128_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @129_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @131_42d000
  if (FL[0] == FL[1]) goto L42d183;  // @132_42d000
  eax = (u32)(ecx + 12);  // @133_42d000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @134_42d000
  goto L42d183;  // @135_42d000
  L42d174:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @137_42d000
  ecx = (u32)(EBP - 28);  // @138_42d000
  PV[9] = (u32)(edx);  // @139_42d000
  eax = ext_5f2c60_thiscall3(ecx, PV[9], PV[8]);  // @140_42d000
  ecx = edx = 0;  // @141_42d000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @142_42d000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @143_42d000
  L42d183:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @145_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @147_42d000
  if (FL[0] != FL[1]) goto L42d113;  // @148_42d000
  L42d190:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @150_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @151_42d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @152_42d000
  if (FL[0] == FL[1]) goto L42d1c3;  // @153_42d000
  L42d1a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @156_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @157_42d000
  eax = (eax - edx);  // @158_42d000
  FL[3] = eax;  // @159_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @160_42d000
  if (FL[0] != FL[1]) goto L42d1b3;  // @161_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @162_42d000
  if (FL[0] == FL[1]) goto L42d1c3;  // @163_42d000
  L42d1b3:;
  ecx = (ecx + (u32)(12));  // @165_42d000
  FL[3] = ecx;  // @166_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @167_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @168_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @169_42d000
  if (FL[0] != FL[1]) goto L42d1a0;  // @170_42d000
  L42d1c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @172_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @173_42d000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = eax;  // @174_42d000
  if (FL[0] == FL[1]) goto L42d1f3;  // @175_42d000
  L42d1d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @178_42d000
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @179_42d000
  eax = (eax - edx);  // @180_42d000
  FL[3] = eax;  // @181_42d000
  FL[0] = eax; FL[1] = (u32)(1);  // @182_42d000
  if (FL[0] != FL[1]) goto L42d1f3;  // @183_42d000
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @184_42d000
  if (FL[0] != FL[1]) goto L42d1f3;  // @185_42d000
  ecx = (ecx + (u32)(12));  // @186_42d000
  FL[3] = ecx;  // @187_42d000
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @188_42d000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @189_42d000
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @190_42d000
  if (FL[0] != FL[1]) goto L42d1d0;  // @191_42d000
  L42d1f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @193_42d000
  eax = (u32)(EBP - 40);  // @194_42d000
  PV[10] = (u32)(eax);  // @195_42d000
  eax = ext_42be20_thiscall2(ecx, PV[10]);  // @196_42d000
  ecx = edx = 0;  // @197_42d000
  ecx = (u32)(EBP - 28);  // @198_42d000
  FL[0] = ecx; FL[1] = eax;  // @199_42d000
  if (FL[0] == FL[1]) goto L42d216;  // @200_42d000
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @201_42d000
  ecx = eax;  // @202_42d000
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @203_42d000
  eax = ext_5f2d60_thiscall3(ecx, PV[12], PV[11]);  // @204_42d000
    // @205_42d000
  L42d216:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @207_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @208_42d000
  eax = (eax - ecx);  // @209_42d000
  FL[3] = eax;  // @210_42d000
  reg.state = (s32)((u32)(2));  // @211_42d000
  FL[2] = (ecx & ecx);  // @212_42d000
  if (FL[2] == 0) goto L42d234;  // @213_42d000
  FL[2] = (eax & eax);  // @214_42d000
  if (FL[2] == 0) goto L42d234;  // @215_42d000
  PV[13] = (u32)(eax);  // @216_42d000
  PV[14] = (u32)(ecx);  // @217_42d000
  ecx = (u32)(EBP - 28);  // @218_42d000
  eax = ext_54f870_stdcall2(PV[14], PV[13]);  // @219_42d000
  ecx = edx = 0;  // @220_42d000
  L42d234:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @222_42d000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @223_42d000
  eax = (eax - ecx);  // @224_42d000
  FL[3] = eax;  // @225_42d000
  reg.state = (s32)((u32)(3));  // @226_42d000
  FL[2] = (ecx & ecx);  // @227_42d000
  if (FL[2] == 0) goto L42d255;  // @228_42d000
  FL[2] = (eax & eax);  // @229_42d000
  if (FL[2] == 0) goto L42d255;  // @230_42d000
  PV[15] = (u32)(eax);  // @231_42d000
  PV[16] = (u32)(ecx);  // @232_42d000
  ecx = (u32)(EBP - 40);  // @233_42d000
  eax = ext_54f870_stdcall2(PV[16], PV[15]);  // @234_42d000
  ecx = edx = 0;  // @235_42d000
  L42d255:;
  SEH_LEAVE();  // @237_42d000
  return eax;  // @238_42d000
}
PCREG(42d000, lifted_42d000);

extern "C" u32 THISCALL lifted_4d5880(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66954b);  // @h_4d5880
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  alo_ = 0;  // @0_4d5880
  esi = ecx;  // @1_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4d5880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 212), &v, sizeof v); }  // @3_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @4_4d5880
  eax = (eax - (u32)(1));  // @5_4d5880
  FL[3] = eax;  // @6_4d5880
  if (FL[3] == 0) goto L4d58f0;  // @7_4d5880
  eax = (eax - (u32)(3));  // @8_4d5880
  FL[3] = eax;  // @9_4d5880
  if (FL[3] == 0) goto L4d58f0;  // @10_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(1331));  // @13_4d5880
  ecx = edx = 0;  // @14_4d5880
  PV[0] = (u32)(eax);  // @15_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_4d5880
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6908664));  // @17_4d5880
  ecx = edx = 0;  // @18_4d5880
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @19_4d5880
  FL[3] = (eax & 0xff);  // @20_4d5880
  goto L4d5b6f;  // @21_4d5880
  L4d58f0:;
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @23_4d5880
  FL[3] = (ebx & 0xff);  // @24_4d5880
  eax = (u32)(65540);  // @25_4d5880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 201), &v, sizeof v); }  // @26_4d5880
  { u32 n_ = (eax + 15) & ~15u; alo_ += n_; SPV_ = (u32)(ALB_ + sizeof ALB_ - alo_); eax = 0; }  // @27_4d5880
  eax = (u32)(65540);  // @28_4d5880
  { u32 v = (u32)(EBP); __builtin_memcpy((void *)(u32)(EBP - 208), &v, 4); }  // @29_4d5880
  { u32 n_ = (eax + 15) & ~15u; alo_ += n_; SPV_ = (u32)(ALB_ + sizeof ALB_ - alo_); eax = 0; }  // @30_4d5880
  edi = SPV_;  // @31_4d5880
  ecx = (u32)(EBP - 200);  // @32_4d5880
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 220), &v, sizeof v); }  // @33_4d5880
  eax = ext_4d5440_thiscall1(ecx);  // @34_4d5880
  ecx = edx = 0;  // @35_4d5880
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @36_4d5880
  ecx = (u32)(EBP - 200);  // @37_4d5880
  reg.state = (s32)((u32)(0));  // @38_4d5880
  eax = ext_4d6aa0_thiscall3(ecx, PV[1], (u32)(3));  // @39_4d5880
  ecx = edx = 0;  // @40_4d5880
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @41_4d5880
  if (FL[2] == 0) goto L4d5b60;  // @42_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @43_4d5880
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 154), sizeof v); (u32)v; });  // @44_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4d5880
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @46_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[3], PV[2], (u32)(0));  // @47_4d5880
  ecx = edx = 0;  // @48_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @49_4d5880
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @50_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_4d5880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, PV[4]);  // @52_4d5880
  ecx = edx = 0;  // @53_4d5880
  FL[2] = (eax & eax);  // @54_4d5880
  if (FL[2] != 0) goto L4d5b51;  // @55_4d5880
  L4d5973:;
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @57_4d5880
  if (FL[2] != 0) goto L4d5b51;  // @58_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @59_4d5880
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @60_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_4d5880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[5]);  // @62_4d5880
  ecx = edx = 0;  // @63_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @64_4d5880
  edx = (u32)(EBP - 216);  // @65_4d5880
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @66_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4d5880
  PV[7] = (u32)(edx);  // @68_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[7], (u32)(4), PV[6]);  // @69_4d5880
  ecx = edx = 0;  // @70_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @71_4d5880
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @72_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4d5880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[8]);  // @74_4d5880
  ecx = edx = 0;  // @75_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @76_4d5880
  FL[0] = eax; FL[1] = (u32)(33639248);  // @77_4d5880
  if (FL[0] == FL[1]) goto L4d5a0f;  // @78_4d5880
  FL[0] = eax; FL[1] = (u32)(101010256);  // @79_4d5880
  if (FL[0] == FL[1]) goto L4d5a02;  // @80_4d5880
  FL[0] = eax; FL[1] = (u32)(1383427685);  // @81_4d5880
  if (FL[0] == FL[1]) goto L4d5a02;  // @82_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @83_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(1376));  // @85_4d5880
  ecx = edx = 0;  // @86_4d5880
  PV[9] = (u32)(eax);  // @87_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_4d5880
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[9], (u32)(6908380));  // @89_4d5880
  ecx = edx = 0;  // @90_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @91_4d5880
  FL[2] = (eax & eax);  // @92_4d5880
  if (FL[2] == 0) goto L4d59fc;  // @93_4d5880
  eax = ((u32(STDCALL *)(void))(eax))();  // @94_4d5880
  ecx = edx = 0;  // @95_4d5880
  goto L4d5b3b;  // @96_4d5880
  L4d59fc:;
  __builtin_trap();  // @98_4d5880
  L4d5a02:;
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @100_4d5880
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 201), &v, sizeof v); }  // @101_4d5880
  goto L4d5b3b;  // @102_4d5880
  L4d5a0f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @104_4d5880
  edx = (u32)(EBP - 88);  // @105_4d5880
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @106_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_4d5880
  PV[11] = (u32)(edx);  // @108_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[11], (u32)(42), PV[10]);  // @109_4d5880
  ecx = edx = 0;  // @110_4d5880
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; })) & 0xffff);  // @111_4d5880
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @112_4d5880
  if (FL[2] == 0) goto L4d5b03;  // @113_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @114_4d5880
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @115_4d5880
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @116_4d5880
  eax = (eax & 0xffff);  // @117_4d5880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_4d5880
  PV[13] = (u32)(eax);  // @119_4d5880
  PV[14] = (u32)(ebx);  // @120_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[14], PV[13], PV[12]);  // @121_4d5880
  ecx = edx = 0;  // @122_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @123_4d5880
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @124_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_4d5880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[15]);  // @126_4d5880
  ecx = edx = 0;  // @127_4d5880
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @128_4d5880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 212), &v, sizeof v); }  // @129_4d5880
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + ebx), &v, sizeof v); }  // @130_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @131_4d5880
  ecx = (ecx + 1);  // @132_4d5880
  FL[3] = ecx;  // @133_4d5880
  PV[16] = (u32)(ecx);  // @134_4d5880
  eax = ext_41e290_cdecl1(PV[16]);  // @135_4d5880
  ecx = edx = 0;  // @136_4d5880
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @137_4d5880
  ecx = (u32)(EBP - 200);  // @138_4d5880
  ebx = eax;  // @139_4d5880
  eax = (u32)(EBP - 44);  // @140_4d5880
  PV[17] = (u32)(eax);  // @141_4d5880
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @142_4d5880
  eax = ext_4d6520_thiscall4(ecx, PV[18], PV[17], (u32)(0));  // @143_4d5880
  ecx = edx = 0;  // @144_4d5880
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @145_4d5880
  if (FL[2] == 0) goto L4d5aab;  // @146_4d5880
  FL[2] = (edi & edi);  // @147_4d5880
  eax = (u32)(EBP - 44);  // @148_4d5880
  ecx = (u32)(EBP - 200);  // @149_4d5880
  if (FL[2] == 0) edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 26), sizeof v); (u32)v; });  // @150_4d5880
  PV[19] = (u32)(edi);  // @151_4d5880
  PV[20] = (u32)(ebx);  // @152_4d5880
  PV[21] = (u32)(eax);  // @153_4d5880
  eax = ext_4d62c0_thiscall5(ecx, PV[21], PV[20], (u32)(0), PV[19]);  // @154_4d5880
  ecx = edx = 0;  // @155_4d5880
  L4d5aab:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @157_4d5880
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @158_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_4d5880
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @160_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[23], PV[22], (u32)(0));  // @161_4d5880
  ecx = edx = 0;  // @162_4d5880
  eax = (u32)(EBP - 228);  // @163_4d5880
  PV[24] = (u32)(eax);  // @164_4d5880
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @165_4d5880
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 78), sizeof v); (u32)v; });  // @166_4d5880
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676138))(PV[26], PV[25], PV[24]);  // @167_4d5880
  ecx = edx = 0;  // @168_4d5880
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @169_4d5880
  eax = (u32)(EBP - 228);  // @170_4d5880
  ecx = esi;  // @171_4d5880
  PV[28] = (u32)(ebx);  // @172_4d5880
  PV[29] = (u32)(eax);  // @173_4d5880
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @174_4d5880
  eax = ext_4d7c30_stdcall4(PV[30], PV[29], PV[28], PV[27]);  // @175_4d5880
  ecx = edx = 0;  // @176_4d5880
  PV[31] = (u32)(ebx);  // @177_4d5880
  eax = ext_634273_cdecl2(PV[31], (u32)(1));  // @178_4d5880
  ecx = edx = 0;  // @179_4d5880
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 201), sizeof v); (u32)v; })) & 0xff);  // @180_4d5880
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @181_4d5880
  L4d5b03:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 62), sizeof v); (u32)v; })) & 0xffff);  // @183_4d5880
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @184_4d5880
  if (FL[2] == 0) goto L4d5b1f;  // @185_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @186_4d5880
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @187_4d5880
  eax = (eax & 0xffff);  // @188_4d5880
  PV[33] = (u32)(eax);  // @189_4d5880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @190_4d5880
  PV[34] = (u32)(edi);  // @191_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[34], PV[33], PV[32]);  // @192_4d5880
  ecx = edx = 0;  // @193_4d5880
  L4d5b1f:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; })) & 0xffff);  // @195_4d5880
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @196_4d5880
  if (FL[2] == 0) goto L4d5b3b;  // @197_4d5880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @198_4d5880
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @199_4d5880
  eax = (eax & 0xffff);  // @200_4d5880
  PV[36] = (u32)(eax);  // @201_4d5880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_4d5880
  PV[37] = (u32)(edi);  // @203_4d5880
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[37], PV[36], PV[35]);  // @204_4d5880
  ecx = edx = 0;  // @205_4d5880
  L4d5b3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @207_4d5880
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 183), sizeof v); (u32)v; });  // @208_4d5880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_4d5880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, PV[38]);  // @210_4d5880
  ecx = edx = 0;  // @211_4d5880
  FL[2] = (eax & eax);  // @212_4d5880
  if (FL[2] == 0) goto L4d5973;  // @213_4d5880
  L4d5b51:;
  ecx = (u32)(EBP - 200);  // @215_4d5880
  eax = ext_4d7540_thiscall1(ecx);  // @216_4d5880
  ecx = edx = 0;  // @217_4d5880
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @218_4d5880
  goto L4d5b62;  // @219_4d5880
  L4d5b60:;
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @221_4d5880
  FL[3] = (ebx & 0xff);  // @222_4d5880
  L4d5b62:;
  ecx = (u32)(EBP - 200);  // @224_4d5880
  eax = ext_4d5580_thiscall1(ecx);  // @225_4d5880
  ecx = edx = 0;  // @226_4d5880
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @227_4d5880
  L4d5b6f:;
  SEH_LEAVE();  // @229_4d5880
  ext_633654(G(u32, 0x6f5630));  // @230_4d5880
  return eax;  // @231_4d5880
}
PCREG(4d5880, lifted_4d5880);

extern "C" u32 THISCALL lifted_42ee70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665118);  // @h_42ee70
  u8 F[0x4100] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x4000);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4000 + 8, &a0, 4);
  ebx = ecx;  // @0_42ee70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16308), &v, sizeof v); }  // @1_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42ee70
  ecx = (u32)(EBP - 16272);  // @3_42ee70
  PV[0] = (u32)(eax);  // @4_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16292), &v, sizeof v); }  // @5_42ee70
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @6_42ee70
  ecx = edx = 0;  // @7_42ee70
  ecx = (u32)(EBP - 16272);  // @8_42ee70
  reg.state = (s32)((u32)(0));  // @9_42ee70
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_42ee70
    // @11_42ee70
  ecx = (u32)(EBP - 16144);  // @12_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16288), &v, sizeof v); }  // @13_42ee70
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @14_42ee70
  ecx = edx = 0;  // @15_42ee70
  eax = (u32)(ebx + 6679);  // @16_42ee70
  reg.state = (s32)((u32)(1));  // @17_42ee70
  ecx = (u32)(EBP - 16144);  // @18_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16312), &v, sizeof v); }  // @19_42ee70
  PV[1] = (u32)(ecx);  // @20_42ee70
  ecx = eax;  // @21_42ee70
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @22_42ee70
  ecx = edx = 0;  // @23_42ee70
  ecx = (u32)(EBP - 16144);  // @24_42ee70
  reg.state = (s32)((u32)(0));  // @25_42ee70
  eax = ext_4cbec0_thiscall1(ecx);  // @26_42ee70
  ecx = edx = 0;  // @27_42ee70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7017), sizeof v); (u32)v; });  // @28_42ee70
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16292), sizeof v); (u32)v; });  // @29_42ee70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @30_42ee70
  edx = edi;  // @31_42ee70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_42ee70
  ecx = edi;  // @33_42ee70
  PV[3] = (u32)(esi);  // @34_42ee70
  eax = ext_42aee0_fastcall5(ecx, edx, PV[3], PV[2], (u32)(0));  // @35_42ee70
  ecx = edx = 0;  // @36_42ee70
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16292), sizeof v); (u32)v; });  // @37_42ee70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @38_42ee70
  ecx = eax;  // @39_42ee70
  eax = ext_42b080_fastcall3(ecx, edx, PV[4]);  // @40_42ee70
  ecx = edx = 0;  // @41_42ee70
  edi = (edi - esi);  // @42_42ee70
  FL[3] = edi;  // @43_42ee70
  ecx = (u32)(EBP - 16304);  // @44_42ee70
  eax = (u32)(3579139413);  // @45_42ee70
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edi); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @46_42ee70
  MOF = (u32)(edx + (((s32)eax < 0) ? 1 : 0));  // @47_42ee70
  edx = (u32)((s32)edx >> (u32)(1));  // @48_42ee70
  FL[3] = edx;  // @49_42ee70
  eax = edx;  // @50_42ee70
  eax = (eax >> (u32)(31));  // @51_42ee70
  FL[3] = eax;  // @52_42ee70
  eax = (eax + edx);  // @53_42ee70
  FL[3] = eax;  // @54_42ee70
  eax = (u32)(eax + eax*2);  // @55_42ee70
  eax = (eax << (u32)(2));  // @56_42ee70
  FL[3] = eax;  // @57_42ee70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @58_42ee70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @59_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16304), &v, sizeof v); }  // @60_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16300), &v, sizeof v); }  // @61_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16296), &v, sizeof v); }  // @62_42ee70
  eax = ext_6014a0_stdcall1((u32)(8));  // @63_42ee70
  ecx = edx = 0;  // @64_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16304), &v, sizeof v); }  // @65_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16300), &v, sizeof v); }  // @66_42ee70
  ecx = (u32)(eax + 8);  // @67_42ee70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16296), &v, sizeof v); }  // @68_42ee70
  FL[2] = (eax & eax);  // @69_42ee70
  if (FL[2] == 0) goto L42efa3;  // @70_42ee70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @71_42ee70
  L42efa3:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @73_42ee70
  ecx = (u32)(EBP - 16284);  // @74_42ee70
  reg.state = (s32)((u32)(2));  // @75_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16284), &v, sizeof v); }  // @76_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16280), &v, sizeof v); }  // @77_42ee70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16276), &v, sizeof v); }  // @78_42ee70
  eax = ext_6014a0_stdcall1((u32)(8));  // @79_42ee70
  ecx = edx = 0;  // @80_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16284), &v, sizeof v); }  // @81_42ee70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16280), &v, sizeof v); }  // @82_42ee70
  ecx = (u32)(eax + 8);  // @83_42ee70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16276), &v, sizeof v); }  // @84_42ee70
  FL[2] = (eax & eax);  // @85_42ee70
  if (FL[2] == 0) goto L42eff1;  // @86_42ee70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @87_42ee70
  L42eff1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @89_42ee70
  eax = (u32)(EBP - 16016);  // @90_42ee70
  reg.state = (s32)((u32)(3));  // @91_42ee70
  PV[5] = (u32)(eax);  // @92_42ee70
  eax = ext_634d10_cdecl3(PV[5], (u32)(0), (u32)(16000));  // @93_42ee70
    // @94_42ee70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16312), sizeof v); (u32)v; });  // @95_42ee70
  ecx = esi;  // @96_42ee70
  eax = ext_4cc180_thiscall2(ecx, (u32)(6781786));  // @97_42ee70
  ecx = edx = 0;  // @98_42ee70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16308), sizeof v); (u32)v; });  // @99_42ee70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @100_42ee70
  if (FL[2] == 0) goto L42f051;  // @101_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_42ee70
  ecx = ebx;  // @103_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; });  // @104_42ee70
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @105_42ee70
  ecx = edx = 0;  // @106_42ee70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @107_42ee70
  if (FL[2] != 0) goto L42f051;  // @108_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @109_42ee70
  PV[6] = (u32)(eax);  // @110_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @111_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 52)))(PV[6], (u32)(6790432));  // @112_42ee70
  ecx = edx = 0;  // @113_42ee70
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @114_42ee70
  FL[3] = (ebx & 0xff);  // @115_42ee70
  goto L42f212;  // @116_42ee70
  L42f051:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16288), sizeof v); (u32)v; });  // @118_42ee70
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_42ee70
  if (FL[0] == FL[1]) goto L42f079;  // @120_42ee70
  L42f060:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @122_42ee70
  ecx = (u32)(EBP - 16288);  // @123_42ee70
  PV[7] = (u32)(ecx);  // @124_42ee70
  ecx = ebx;  // @125_42ee70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[7]);  // @126_42ee70
  ecx = edx = 0;  // @127_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16288), sizeof v); (u32)v; });  // @128_42ee70
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @129_42ee70
  if (FL[0] != FL[1]) goto L42f060;  // @130_42ee70
  L42f079:;
  ecx = esi;  // @132_42ee70
  eax = ext_4cc1d0_thiscall1(ecx);  // @133_42ee70
    // @134_42ee70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @135_42ee70
  ecx = ebx;  // @136_42ee70
  PV[8] = (u32)(eax);  // @137_42ee70
  eax = (u32)(EBP - 16016);  // @138_42ee70
  PV[9] = (u32)(eax);  // @139_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[9], PV[8]);  // @140_42ee70
  ecx = edx = 0;  // @141_42ee70
  eax = (u32)(EBP - 16016);  // @142_42ee70
  edx = (u32)(eax + 1);  // @143_42ee70
  L42f098:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @145_42ee70
  eax = (eax + 1);  // @146_42ee70
  FL[3] = eax;  // @147_42ee70
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @148_42ee70
  if (FL[2] != 0) goto L42f098;  // @149_42ee70
  eax = (eax - edx);  // @150_42ee70
  FL[3] = eax;  // @151_42ee70
  ecx = (u32)(EBP - 16016);  // @152_42ee70
  eax = (eax + ecx);  // @153_42ee70
  FL[3] = eax;  // @154_42ee70
  PV[10] = (u32)(eax);  // @155_42ee70
  eax = ecx;  // @156_42ee70
  ecx = (u32)(EBP - 16284);  // @157_42ee70
  PV[11] = (u32)(eax);  // @158_42ee70
  eax = ext_5f2d60_thiscall3(ecx, PV[11], PV[10]);  // @159_42ee70
    // @160_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @161_42ee70
  ecx = (u32)(EBP - 16284);  // @162_42ee70
  PV[12] = (u32)(ecx);  // @163_42ee70
  ecx = ebx;  // @164_42ee70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 176)))(ecx, PV[12]);  // @165_42ee70
  ecx = edx = 0;  // @166_42ee70
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16292), sizeof v); (u32)v; });  // @167_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)0x67625c))(PV[13], (u32)(6790472));  // @168_42ee70
  ecx = edx = 0;  // @169_42ee70
  FL[2] = (eax & eax);  // @170_42ee70
  if (FL[2] == 0) goto L42f1e0;  // @171_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @172_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @173_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(889));  // @174_42ee70
  ecx = edx = 0;  // @175_42ee70
  PV[14] = (u32)(eax);  // @176_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @177_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[14], (u32)(6790484));  // @178_42ee70
  ecx = edx = 0;  // @179_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @180_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(890));  // @182_42ee70
  ecx = edx = 0;  // @183_42ee70
  PV[15] = (u32)(eax);  // @184_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @185_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[15], (u32)(6790524));  // @186_42ee70
  ecx = edx = 0;  // @187_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @188_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(891));  // @190_42ee70
  ecx = edx = 0;  // @191_42ee70
  PV[16] = (u32)(eax);  // @192_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @193_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[16], (u32)(6790548));  // @194_42ee70
  ecx = edx = 0;  // @195_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @196_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(892));  // @198_42ee70
  ecx = edx = 0;  // @199_42ee70
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16284), sizeof v); (u32)v; });  // @200_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @201_42ee70
  PV[18] = (u32)(eax);  // @202_42ee70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[18], (u32)(6777880), PV[17]);  // @203_42ee70
  ecx = edx = 0;  // @204_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @205_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @206_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(893));  // @207_42ee70
  ecx = edx = 0;  // @208_42ee70
  PV[19] = (u32)(eax);  // @209_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @210_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[19], (u32)(6790548));  // @211_42ee70
  ecx = edx = 0;  // @212_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @213_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(894));  // @215_42ee70
  ecx = edx = 0;  // @216_42ee70
  PV[20] = (u32)(eax);  // @217_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @218_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[20], (u32)(6790584));  // @219_42ee70
  ecx = edx = 0;  // @220_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @221_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_42ee70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(895));  // @223_42ee70
  ecx = edx = 0;  // @224_42ee70
  PV[21] = (u32)(eax);  // @225_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @226_42ee70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[21], (u32)(6790616));  // @227_42ee70
  ecx = edx = 0;  // @228_42ee70
  L42f1e0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16284), sizeof v); (u32)v; });  // @230_42ee70
  esi = (u32)(EBP - 16016);  // @231_42ee70
  esi = (esi - edx);  // @232_42ee70
  FL[3] = esi;  // @233_42ee70
  L42f1f0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @235_42ee70
  edx = (u32)(edx + 1);  // @236_42ee70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + edx - 1), &v, sizeof v); }  // @237_42ee70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @238_42ee70
  if (FL[2] != 0) goto L42f1f0;  // @239_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @240_42ee70
  ecx = (u32)(EBP - 16016);  // @241_42ee70
  PV[22] = (u32)(ecx);  // @242_42ee70
  ecx = ebx;  // @243_42ee70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 180), sizeof v); (u32)v; });  // @244_42ee70
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[22]);  // @245_42ee70
  ecx = edx = 0;  // @246_42ee70
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @247_42ee70
  L42f212:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16276), sizeof v); (u32)v; });  // @249_42ee70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16284), sizeof v); (u32)v; });  // @250_42ee70
  ecx = (ecx - edx);  // @251_42ee70
  FL[3] = ecx;  // @252_42ee70
  reg.state = (s32)((u32)(4));  // @253_42ee70
  FL[2] = (edx & edx);  // @254_42ee70
  if (FL[2] == 0) goto L42f239;  // @255_42ee70
  FL[2] = (ecx & ecx);  // @256_42ee70
  if (FL[2] == 0) goto L42f239;  // @257_42ee70
  PV[23] = (u32)(ecx);  // @258_42ee70
  PV[24] = (u32)(edx);  // @259_42ee70
  ecx = (u32)(EBP - 16284);  // @260_42ee70
  eax = ext_54f870_stdcall2(PV[24], PV[23]);  // @261_42ee70
  ecx = edx = 0;  // @262_42ee70
  L42f239:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16296), sizeof v); (u32)v; });  // @264_42ee70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16304), sizeof v); (u32)v; });  // @265_42ee70
  eax = (eax - ecx);  // @266_42ee70
  FL[3] = eax;  // @267_42ee70
  reg.state = (s32)((u32)(5));  // @268_42ee70
  FL[2] = (ecx & ecx);  // @269_42ee70
  if (FL[2] == 0) goto L42f260;  // @270_42ee70
  FL[2] = (eax & eax);  // @271_42ee70
  if (FL[2] == 0) goto L42f260;  // @272_42ee70
  PV[25] = (u32)(eax);  // @273_42ee70
  PV[26] = (u32)(ecx);  // @274_42ee70
  ecx = (u32)(EBP - 16304);  // @275_42ee70
  eax = ext_54f870_stdcall2(PV[26], PV[25]);  // @276_42ee70
  ecx = edx = 0;  // @277_42ee70
  L42f260:;
  ecx = (u32)(EBP - 16272);  // @279_42ee70
  eax = ext_4cbec0_thiscall1(ecx);  // @280_42ee70
  ecx = edx = 0;  // @281_42ee70
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @282_42ee70
  SEH_LEAVE();  // @283_42ee70
  ext_633654(G(u32, 0x6f5630));  // @284_42ee70
  return eax;  // @285_42ee70
}
PCREG(42ee70, lifted_42ee70);

extern "C" u32 THISCALL lifted_494060(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667f47);  // @h_494060
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_494060
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 600), &v, sizeof v); }  // @1_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @3_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_494060
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @5_494060
  ecx = edx = 0;  // @6_494060
  eax = ext_41e290_cdecl1((u32)(4000000));  // @7_494060
  ecx = edx = 0;  // @8_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_494060
  ebx = eax;  // @10_494060
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 596), &v, sizeof v); }  // @11_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @12_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @13_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @14_494060
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 592), &v, sizeof v); }  // @15_494060
  FL[2] = (ecx & ecx);  // @16_494060
  if (FL[2] == 0) goto L49410e;  // @17_494060
  L4940e0:;
  eax = ext_4dc420_thiscall2(ecx, (u32)(1));  // @19_494060
  ecx = 0;  // @20_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_494060
  edx = (u32)(EBP - 592);  // @22_494060
  PV[0] = (u32)(edx);  // @23_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @25_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[0]);  // @27_494060
  ecx = edx = 0;  // @28_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 592), sizeof v); (u32)v; });  // @29_494060
  FL[2] = (ecx & ecx);  // @30_494060
  if (FL[2] != 0) goto L4940e0;  // @31_494060
  L49410e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @33_494060
  ecx = (u32)(esi + 28);  // @34_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(0));  // @35_494060
  ecx = edx = 0;  // @36_494060
  eax = (eax + (u32)(6));  // @37_494060
  FL[3] = eax;  // @38_494060
  ecx = (u32)(EBP - 144);  // @39_494060
  PV[1] = (u32)(eax);  // @40_494060
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @41_494060
  ecx = edx = 0;  // @42_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_494060
  edx = (u32)(EBP - 272);  // @44_494060
  PV[2] = (u32)(edx);  // @45_494060
  reg.state = (s32)((u32)(0));  // @46_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 296)))(ecx, PV[2]);  // @48_494060
  ecx = edx = 0;  // @49_494060
  ecx = (u32)(EBP - 272);  // @50_494060
  reg.state = (s32)((u32)(1));  // @51_494060
  eax = ext_4cc1d0_thiscall1(ecx);  // @52_494060
    // @53_494060
  esi = eax;  // @54_494060
  ecx = (u32)(esi + 1);  // @55_494060
  L494158:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @57_494060
  esi = (esi + 1);  // @58_494060
  FL[3] = esi;  // @59_494060
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @60_494060
  if (FL[2] != 0) goto L494158;  // @61_494060
  esi = (esi - ecx);  // @62_494060
  FL[3] = esi;  // @63_494060
  ecx = (u32)(EBP - 272);  // @64_494060
  PV[3] = (u32)(esi);  // @65_494060
  eax = ext_4cc1d0_thiscall1(ecx);  // @66_494060
    // @67_494060
  PV[4] = (u32)(eax);  // @68_494060
  ecx = (u32)(EBP - 144);  // @69_494060
  eax = ext_4cc1d0_thiscall1(ecx);  // @70_494060
    // @71_494060
  PV[5] = (u32)(eax);  // @72_494060
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x67640c))(PV[5], PV[4], PV[3]);  // @73_494060
  ecx = edx = 0;  // @74_494060
  ecx = 0;  // @75_494060
  FL[3] = ecx;  // @76_494060
  FL[2] = (eax & eax);  // @77_494060
  if (FL[2] != 0) esi = ecx;  // @78_494060
  ecx = (u32)(EBP - 144);  // @79_494060
  eax = ext_4cc1d0_thiscall1(ecx);  // @80_494060
    // @81_494060
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }); FL[1] = (u32)(92);  // @82_494060
  if (FL[0] == FL[1]) goto L4941ac;  // @83_494060
  ecx = (u32)(EBP - 144);  // @84_494060
  eax = ext_4cc1d0_thiscall1(ecx);  // @85_494060
    // @86_494060
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @87_494060
  if (FL[0] != FL[1]) goto L4941ad;  // @88_494060
  L4941ac:;
  esi = (esi + 1);  // @90_494060
  FL[3] = esi;  // @91_494060
  L4941ad:;
  PV[6] = (u32)(ebx);  // @93_494060
  ecx = (u32)(EBP - 588);  // @94_494060
  eax = ext_4998c0_thiscall3(ecx, PV[6], (u32)(4000000));  // @95_494060
  ecx = edx = 0;  // @96_494060
  ecx = (u32)(EBP - 588);  // @97_494060
  reg.state = (s32)((u32)(2));  // @98_494060
  eax = ext_49b360_thiscall3(ecx, (u32)(0), (u32)(0));  // @99_494060
    // @100_494060
  ecx = (u32)(EBP - 588);  // @101_494060
  eax = ext_49b330_thiscall2(ecx, (u32)(0));  // @102_494060
    // @103_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @104_494060
  ecx = (u32)(EBP - 588);  // @105_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(64));  // @106_494060
  ecx = edx = 0;  // @107_494060
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @108_494060
  ecx = (u32)(EBP - 144);  // @109_494060
  eax = ext_4cc1d0_thiscall1(ecx);  // @110_494060
    // @111_494060
  eax = (eax + esi);  // @112_494060
  FL[3] = eax;  // @113_494060
  ecx = (u32)(EBP - 588);  // @114_494060
  PV[7] = (u32)(eax);  // @115_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 92)))(ecx, PV[7]);  // @116_494060
  ecx = edx = 0;  // @117_494060
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @118_494060
  ecx = (u32)(EBP - 588);  // @119_494060
  eax = ext_49ab80_thiscall3(ecx, PV[8], (u32)(1));  // @120_494060
  ecx = edx = 0;  // @121_494060
  ecx = (u32)(EBP - 588);  // @122_494060
  reg.state = (s32)((u32)(1));  // @123_494060
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @124_494060
  eax = ext_499980_thiscall1(ecx);  // @125_494060
  ecx = edx = 0;  // @126_494060
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 596), sizeof v); (u32)v; });  // @127_494060
  ecx = (u32)(EBP - 588);  // @128_494060
  PV[9] = (u32)(esi);  // @129_494060
  eax = ext_4998c0_thiscall3(ecx, PV[9], (u32)(4000000));  // @130_494060
  ecx = edx = 0;  // @131_494060
  ecx = (u32)(EBP - 588);  // @132_494060
  reg.state = (s32)((u32)(3));  // @133_494060
  eax = ext_49b360_thiscall3(ecx, (u32)(5), (u32)(21));  // @134_494060
    // @135_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @137_494060
  FL[2] = (ecx & ecx);  // @138_494060
  if (FL[2] == 0) goto L494275;  // @139_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_494060
  edx = (u32)(EBP - 588);  // @141_494060
  PV[10] = (u32)(edx);  // @142_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[10]);  // @143_494060
  ecx = edx = 0;  // @144_494060
  L494275:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 600), sizeof v); (u32)v; });  // @146_494060
  eax = (u32)(EBP - 588);  // @147_494060
  PV[11] = (u32)(eax);  // @148_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @149_494060
  eax = ext_4989a0_thiscall2(ecx, PV[11]);  // @150_494060
  ecx = edx = 0;  // @151_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @152_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @153_494060
  FL[2] = (ecx & ecx);  // @154_494060
  if (FL[2] == 0) goto L4942a5;  // @155_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @156_494060
  edx = (u32)(EBP - 588);  // @157_494060
  PV[12] = (u32)(edx);  // @158_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[12]);  // @159_494060
  ecx = edx = 0;  // @160_494060
  L4942a5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @162_494060
  FL[2] = (ecx & ecx);  // @163_494060
  if (FL[2] == 0) goto L4942be;  // @164_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_494060
  edx = (u32)(EBP - 588);  // @166_494060
  PV[13] = (u32)(edx);  // @167_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 216)))(ecx, PV[13]);  // @168_494060
  ecx = edx = 0;  // @169_494060
  L4942be:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @171_494060
  if (FL[0] == FL[1]) goto L4942e6;  // @172_494060
  ecx = (u32)(EBP - 588);  // @173_494060
  eax = ext_49b330_thiscall2(ecx, (u32)(21));  // @174_494060
    // @175_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @176_494060
  edx = (u32)(EBP - 588);  // @177_494060
  PV[14] = (u32)(edx);  // @178_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @179_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[14]);  // @180_494060
  ecx = edx = 0;  // @181_494060
  L4942e6:;
  ecx = (u32)(EBP - 588);  // @183_494060
  eax = ext_49b330_thiscall2(ecx, (u32)(10));  // @184_494060
    // @185_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @186_494060
  edx = (u32)(EBP - 588);  // @187_494060
  PV[15] = (u32)(edx);  // @188_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @189_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @190_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 176)))(ecx, PV[15]);  // @191_494060
  ecx = edx = 0;  // @192_494060
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @193_494060
  ecx = (u32)(EBP - 588);  // @194_494060
  eax = ext_49ab80_thiscall3(ecx, PV[16], (u32)(3));  // @195_494060
  ecx = edx = 0;  // @196_494060
  ecx = (u32)(EBP - 588);  // @197_494060
  reg.state = (s32)((u32)(1));  // @198_494060
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @199_494060
  FL[3] = (ebx & 0xff);  // @200_494060
  eax = ext_499980_thiscall1(ecx);  // @201_494060
  ecx = edx = 0;  // @202_494060
  PV[17] = (u32)(esi);  // @203_494060
  ecx = (u32)(EBP - 588);  // @204_494060
  eax = ext_4998c0_thiscall3(ecx, PV[17], (u32)(4000000));  // @205_494060
  ecx = edx = 0;  // @206_494060
  ecx = (u32)(EBP - 588);  // @207_494060
  reg.state = (s32)((u32)(4));  // @208_494060
  eax = ext_49b360_thiscall3(ecx, (u32)(1), (u32)(4));  // @209_494060
    // @210_494060
  ecx = (u32)(EBP - 588);  // @211_494060
  eax = ext_49b330_thiscall2(ecx, (u32)(1));  // @212_494060
    // @213_494060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2992), sizeof v); (u32)v; });  // @214_494060
  ecx = (u32)(EBP - 588);  // @215_494060
  PV[18] = (u32)(eax);  // @216_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @217_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[18]);  // @218_494060
  ecx = edx = 0;  // @219_494060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2993), sizeof v); (u32)v; });  // @220_494060
  ecx = (u32)(EBP - 588);  // @221_494060
  PV[19] = (u32)(eax);  // @222_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @223_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[19]);  // @224_494060
  ecx = edx = 0;  // @225_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2995), sizeof v); (u32)v; });  // @226_494060
  PV[20] = (u32)(ecx);  // @227_494060
  ecx = 0;  // @228_494060
  PV[21] = eax;  // @229_494060
  ecx = (u32)(EBP - 588);  // @230_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @231_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[21]);  // @232_494060
  ecx = edx = 0;  // @233_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @234_494060
  ecx = (u32)(EBP - 588);  // @235_494060
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 23873), sizeof v); (u32)v; });  // @236_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[22]);  // @237_494060
  ecx = edx = 0;  // @238_494060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2988), sizeof v); (u32)v; });  // @239_494060
  ecx = (u32)(EBP - 588);  // @240_494060
  PV[23] = (u32)(eax);  // @241_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @242_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[23]);  // @243_494060
  ecx = edx = 0;  // @244_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @245_494060
  edx = (u32)(EBP - 588);  // @246_494060
  PV[24] = (u32)(edx);  // @247_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @248_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[24]);  // @249_494060
  ecx = edx = 0;  // @250_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @251_494060
  ecx = (u32)(EBP - 588);  // @252_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(3));  // @253_494060
  ecx = edx = 0;  // @254_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @255_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @256_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @257_494060
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @258_494060
  ecx = edx = 0;  // @259_494060
  ecx = (u32)(EBP - 588);  // @260_494060
  PV[25] = (u32)(ecx);  // @261_494060
  ecx = eax;  // @262_494060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @263_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[25]);  // @264_494060
  ecx = edx = 0;  // @265_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @266_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @267_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_494060
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @269_494060
  ecx = edx = 0;  // @270_494060
  ecx = (u32)(EBP - 588);  // @271_494060
  PV[26] = (u32)(ecx);  // @272_494060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @273_494060
  ecx = eax;  // @274_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[26]);  // @275_494060
  ecx = edx = 0;  // @276_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @277_494060
  ecx = (u32)(EBP - 588);  // @278_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(4));  // @279_494060
  ecx = edx = 0;  // @280_494060
  esi = (u32)(edi + 3149);  // @281_494060
  edi = (u32)(1026);  // @282_494060
  L494460:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 588), sizeof v); (u32)v; });  // @284_494060
  ecx = (u32)(EBP - 588);  // @285_494060
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @286_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[27]);  // @287_494060
  ecx = edx = 0;  // @288_494060
  esi = (u32)(esi + 4);  // @289_494060
  edi = (edi - (u32)(1));  // @290_494060
  FL[3] = edi;  // @291_494060
  if (FL[3] != 0) goto L494460;  // @292_494060
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @293_494060
  ecx = (u32)(EBP - 588);  // @294_494060
  eax = ext_49ab80_thiscall3(ecx, PV[28], (u32)(2));  // @295_494060
  ecx = edx = 0;  // @296_494060
  ecx = (u32)(EBP - 588);  // @297_494060
  reg.state = (s32)((u32)(1));  // @298_494060
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @299_494060
  FL[3] = (ebx & 0xff);  // @300_494060
  eax = ext_499980_thiscall1(ecx);  // @301_494060
  ecx = edx = 0;  // @302_494060
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 596), sizeof v); (u32)v; });  // @303_494060
  eax = ext_634273_cdecl2(PV[29], (u32)(1));  // @304_494060
  ecx = edx = 0;  // @305_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @306_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @307_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @308_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @309_494060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 592), &v, sizeof v); }  // @310_494060
  FL[2] = (eax & eax);  // @311_494060
  if (FL[2] == 0) goto L494500;  // @312_494060
  L4944d0:;
  ecx = eax;  // @314_494060
  eax = ext_4dc420_thiscall2(ecx, (u32)(0));  // @315_494060
  ecx = 0;  // @316_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @317_494060
  edx = (u32)(EBP - 592);  // @318_494060
  PV[30] = (u32)(edx);  // @319_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @320_494060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @321_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @322_494060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[30]);  // @323_494060
  ecx = edx = 0;  // @324_494060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 592), sizeof v); (u32)v; });  // @325_494060
  FL[2] = (eax & eax);  // @326_494060
  if (FL[2] != 0) goto L4944d0;  // @327_494060
  L494500:;
  ecx = (u32)(EBP - 272);  // @329_494060
  eax = ext_4cbec0_thiscall1(ecx);  // @330_494060
  ecx = edx = 0;  // @331_494060
  ecx = (u32)(EBP - 144);  // @332_494060
  eax = ext_4cbec0_thiscall1(ecx);  // @333_494060
  ecx = edx = 0;  // @334_494060
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @335_494060
  SEH_LEAVE();  // @336_494060
  ext_633654(G(u32, 0x6f5630));  // @337_494060
  return eax;  // @338_494060
}
PCREG(494060, lifted_494060);

extern "C" u32 THISCALL lifted_49cda0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x668396);  // @h_49cda0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @0_49cda0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_49cda0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_49cda0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @3_49cda0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_49cda0
  FL[2] = (esi & esi);  // @5_49cda0
  if (FL[2] != 0) goto L49cdf1;  // @6_49cda0
  eax = 0;  // @7_49cda0
  FL[3] = eax;  // @8_49cda0
  goto L49d1f6;  // @9_49cda0
  L49cdf1:;
  ecx = (u32)(EBP - 328);  // @11_49cda0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(9));  // @12_49cda0
  ecx = edx = 0;  // @13_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_49cda0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @15_49cda0
  reg.state = (s32)((u32)(0));  // @16_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @17_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @18_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[0]);  // @20_49cda0
  ecx = edx = 0;  // @21_49cda0
  FL[2] = (eax & eax);  // @22_49cda0
  if (FL[2] != 0) goto L49ce40;  // @23_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_49cda0
  edx = (u32)(EBP - 328);  // @25_49cda0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @26_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @27_49cda0
  PV[2] = (u32)(edx);  // @28_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @29_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_49cda0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[2], PV[1], (u32)(-1));  // @31_49cda0
  ecx = edx = 0;  // @32_49cda0
  L49ce40:;
  ecx = (u32)(EBP - 148);  // @34_49cda0
  eax = ext_4de7a0_thiscall1(ecx);  // @35_49cda0
    // @36_49cda0
  eax = (u32)(EBP - 76);  // @37_49cda0
  ecx = esi;  // @38_49cda0
  PV[3] = (u32)(eax);  // @39_49cda0
  eax = ext_4db7c0_thiscall2(ecx, PV[3]);  // @40_49cda0
  edx = 0;  // @41_49cda0
  eax = (u32)(EBP - 64);  // @42_49cda0
  ecx = esi;  // @43_49cda0
  PV[4] = (u32)(eax);  // @44_49cda0
  eax = (u32)(EBP - 148);  // @45_49cda0
  PV[5] = (u32)(eax);  // @46_49cda0
  eax = ext_4db6c0_thiscall3(ecx, PV[5], PV[4]);  // @47_49cda0
  ecx = edx = 0;  // @48_49cda0
  eax = (u32)(EBP - 40);  // @49_49cda0
  ecx = esi;  // @50_49cda0
  PV[6] = (u32)(eax);  // @51_49cda0
  eax = ext_4daf90_thiscall2(ecx, PV[6]);  // @52_49cda0
  edx = 0;  // @53_49cda0
  eax = (u32)(EBP - 40);  // @54_49cda0
  ecx = esi;  // @55_49cda0
  PV[7] = (u32)(eax);  // @56_49cda0
  eax = ext_4db670_thiscall2(ecx, PV[7]);  // @57_49cda0
  ecx = edx = 0;  // @58_49cda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @59_49cda0
  ecx = edi;  // @60_49cda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @61_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @63_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048609));  // @64_49cda0
  ecx = edx = 0;  // @65_49cda0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @66_49cda0
  if (FL[2] != 0) goto L49cec4;  // @67_49cda0
  L49cea0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_49cda0
  ecx = edi;  // @70_49cda0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @71_49cda0
  ecx = edx = 0;  // @72_49cda0
  edi = eax;  // @73_49cda0
  ecx = edi;  // @74_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @76_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048609));  // @77_49cda0
  ecx = edx = 0;  // @78_49cda0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @79_49cda0
  if (FL[2] == 0) goto L49cea0;  // @80_49cda0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @81_49cda0
  L49cec4:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @83_49cda0
  FL[3] = (eax & 0xff);  // @84_49cda0
  esi = edi;  // @85_49cda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @86_49cda0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 277), &v, sizeof v); }  // @87_49cda0
  L49ced4:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @89_49cda0
  if (FL[2] != 0) goto L49cf3b;  // @90_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @91_49cda0
  L49cedb:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @93_49cda0
  FL[2] = (ecx & ecx);  // @94_49cda0
  if (FL[2] == 0) goto L49cf28;  // @95_49cda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @96_49cda0
  FL[2] = (edx & edx);  // @97_49cda0
  if (FL[2] == 0) goto L49cef4;  // @98_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @99_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @100_49cda0
  goto L49cef9;  // @101_49cda0
  L49cef4:;
  eax = (u32)(2097154);  // @103_49cda0
  L49cef9:;
  FL[2] = (eax & (u32)(1048576));  // @105_49cda0
  if (FL[2] != 0) goto L49cf28;  // @106_49cda0
  FL[2] = (edx & edx);  // @107_49cda0
  if (FL[2] == 0) goto L49cf10;  // @108_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @109_49cda0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(8388621);  // @110_49cda0
  if (FL[0] == FL[1]) goto L49cf19;  // @111_49cda0
  L49cf10:;
  eax = ext_4db520_thiscall1(ecx);  // @113_49cda0
  ecx = edx = 0;  // @114_49cda0
  ecx = eax;  // @115_49cda0
  goto L49cedb;  // @116_49cda0
  L49cf19:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @118_49cda0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 277), &v, sizeof v); }  // @119_49cda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + eax*4 + 65), &v, sizeof v); }  // @120_49cda0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @121_49cda0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @122_49cda0
  L49cf28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_49cda0
  ecx = esi;  // @125_49cda0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @126_49cda0
  ecx = edx = 0;  // @127_49cda0
  esi = eax;  // @128_49cda0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 277), sizeof v); (u32)v; })) & 0xff);  // @129_49cda0
  FL[2] = (esi & esi);  // @130_49cda0
  if (FL[2] != 0) goto L49ced4;  // @131_49cda0
  L49cf3b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @133_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @134_49cda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @135_49cda0
  FL[2] = (eax & eax);  // @136_49cda0
  if (FL[2] == 0) goto L49d1e2;  // @137_49cda0
  L49cf52:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @139_49cda0
  FL[2] = (esi & esi);  // @140_49cda0
  if (FL[2] == 0) goto L49d17a;  // @141_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @142_49cda0
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }) & (u32)(8388608));  // @143_49cda0
  if (FL[2] == 0) goto L49d17a;  // @144_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_49cda0
  ecx = esi;  // @146_49cda0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @147_49cda0
  ecx = edx = 0;  // @148_49cda0
  edx = eax;  // @149_49cda0
  FL[2] = (edx & edx);  // @150_49cda0
  if (FL[2] == 0) goto L49cf9d;  // @151_49cda0
  L49cf80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @153_49cda0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }); FL[1] = (u32)(1048810);  // @154_49cda0
  if (FL[0] == FL[1]) goto L49d17a;  // @155_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @156_49cda0
  ecx = edx;  // @157_49cda0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @158_49cda0
  ecx = edx = 0;  // @159_49cda0
  edx = eax;  // @160_49cda0
  FL[2] = (edx & edx);  // @161_49cda0
  if (FL[2] != 0) goto L49cf80;  // @162_49cda0
  L49cf9d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @164_49cda0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 4), 4); v; });  // @165_49cda0
  X0[2] = 0;  // @166_49cda0
  X0[3] = 0;  // @167_49cda0
  edx = (u32)(EBP - 148);  // @168_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @169_49cda0
  ecx = (u32)(EBP - 112);  // @170_49cda0
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @171_49cda0
  __builtin_memcpy((void *)((u32)(EBP - 52) + 4), &X0[1], 4);  // @172_49cda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @173_49cda0
  eax = ext_4de420_fastcall2(ecx, edx);  // @174_49cda0
    // @175_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @176_49cda0
  ecx = (u32)(EBP - 28);  // @177_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @178_49cda0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 4), 4); v; });  // @179_49cda0
  X0[2] = 0;  // @180_49cda0
  X0[3] = 0;  // @181_49cda0
  PV[8] = (u32)(ecx);  // @182_49cda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @183_49cda0
  ecx = (u32)(EBP - 112);  // @184_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @185_49cda0
  PV[9] = (u32)(ecx);  // @186_49cda0
  ecx = esi;  // @187_49cda0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @188_49cda0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @189_49cda0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[9], PV[8]);  // @190_49cda0
  ecx = edx = 0;  // @191_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_49cda0
  ecx = (u32)(EBP - 52);  // @193_49cda0
  PV[10] = (u32)(ecx);  // @194_49cda0
  ecx = esi;  // @195_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[10]);  // @196_49cda0
  ecx = edx = 0;  // @197_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @198_49cda0
  edi = (u32)(EBP - 76);  // @199_49cda0
  PV[11] = (u32)(edi);  // @200_49cda0
  edi = (u32)(EBP - 52);  // @201_49cda0
  PV[12] = (u32)(edi);  // @202_49cda0
  edi = (u32)(EBP - 112);  // @203_49cda0
  eax = (u32)(ecx + 64);  // @204_49cda0
  PV[13] = (u32)(edi);  // @205_49cda0
  edx = (u32)(ecx + 48);  // @206_49cda0
  PV[14] = (u32)(eax);  // @207_49cda0
  eax = ext_4df330_fastcall6(ecx, edx, PV[14], PV[13], PV[12], PV[11]);  // @208_49cda0
  ecx = edx = 0;  // @209_49cda0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @210_49cda0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @211_49cda0
  if (FL[2] == 0) goto L49d17a;  // @212_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @213_49cda0
  ecx = esi;  // @214_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @215_49cda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @216_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @217_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @218_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(8388644));  // @219_49cda0
  ecx = edx = 0;  // @220_49cda0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @221_49cda0
  if (FL[2] == 0) goto L49d07d;  // @222_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_49cda0
  edx = (u32)(EBP - 364);  // @224_49cda0
  PV[15] = (u32)(edx);  // @225_49cda0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @226_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @227_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @228_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_49cda0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[16], PV[15]);  // @230_49cda0
  ecx = edx = 0;  // @231_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 336) + 0), 4); v; });  // @232_49cda0
  X0[1] = 0;  // @233_49cda0
  X0[2] = 0;  // @234_49cda0
  X0[3] = 0;  // @235_49cda0
  eax = (u32)(EBP - 328);  // @236_49cda0
  PV[17] = (u32)(eax);  // @237_49cda0
  PV[18] = (u32)(ecx);  // @238_49cda0
  edx = (u32)(EBP - 28);  // @239_49cda0
  PV[19] = X0[0];  // @240_49cda0
  ecx = (u32)(EBP - 112);  // @241_49cda0
  eax = ext_49b9a0_fastcall4(ecx, edx, PV[19], PV[17]);  // @242_49cda0
  ecx = edx = 0;  // @243_49cda0
  goto L49d15d;  // @244_49cda0
  L49d07d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @246_49cda0
  ecx = esi;  // @247_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @248_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(8388643));  // @249_49cda0
  ecx = edx = 0;  // @250_49cda0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @251_49cda0
  if (FL[2] == 0) goto L49d0e7;  // @252_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @253_49cda0
  edx = (u32)(EBP - 384);  // @254_49cda0
  PV[20] = (u32)(edx);  // @255_49cda0
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @256_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @257_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @258_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @259_49cda0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[21], PV[20]);  // @260_49cda0
  ecx = edx = 0;  // @261_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 340) + 0), 4); v; });  // @262_49cda0
  X0[1] = 0;  // @263_49cda0
  X0[2] = 0;  // @264_49cda0
  X0[3] = 0;  // @265_49cda0
  eax = (u32)(EBP - 328);  // @266_49cda0
  PV[22] = (u32)(eax);  // @267_49cda0
  edx = (u32)(EBP - 28);  // @268_49cda0
  ecx = (u32)(EBP - 112);  // @269_49cda0
  PV[23] = X0[0];  // @270_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 356) + 0), 4); v; });  // @271_49cda0
  X0[1] = 0;  // @272_49cda0
  X0[2] = 0;  // @273_49cda0
  X0[3] = 0;  // @274_49cda0
  PV[24] = X0[0];  // @275_49cda0
  eax = ext_49bbc0_fastcall5(ecx, edx, PV[24], PV[23], PV[22]);  // @276_49cda0
  ecx = edx = 0;  // @277_49cda0
  goto L49d15d;  // @278_49cda0
  L49d0e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @280_49cda0
  ecx = esi;  // @281_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @282_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(8388640));  // @283_49cda0
  ecx = edx = 0;  // @284_49cda0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @285_49cda0
  if (FL[2] == 0) goto L49d161;  // @286_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @287_49cda0
  edx = (u32)(EBP - 388);  // @288_49cda0
  PV[25] = (u32)(edx);  // @289_49cda0
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @290_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @291_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @292_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @293_49cda0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[26], PV[25]);  // @294_49cda0
  ecx = edx = 0;  // @295_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 332) + 0), 4); v; });  // @296_49cda0
  X0[1] = 0;  // @297_49cda0
  X0[2] = 0;  // @298_49cda0
  X0[3] = 0;  // @299_49cda0
  eax = (u32)(EBP - 328);  // @300_49cda0
  PV[27] = (u32)(eax);  // @301_49cda0
  edx = (u32)(EBP - 28);  // @302_49cda0
  ecx = (u32)(EBP - 112);  // @303_49cda0
  PV[28] = X0[0];  // @304_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 344) + 0), 4); v; });  // @305_49cda0
  X0[1] = 0;  // @306_49cda0
  X0[2] = 0;  // @307_49cda0
  X0[3] = 0;  // @308_49cda0
  PV[29] = X0[0];  // @309_49cda0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 360) + 0), 4); v; });  // @310_49cda0
  X0[1] = 0;  // @311_49cda0
  X0[2] = 0;  // @312_49cda0
  X0[3] = 0;  // @313_49cda0
  PV[30] = X0[0];  // @314_49cda0
  eax = ext_49be80_fastcall6(ecx, edx, PV[30], PV[29], PV[28], PV[27]);  // @315_49cda0
  ecx = edx = 0;  // @316_49cda0
  L49d15d:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @318_49cda0
  if (FL[2] == 0) goto L49d17a;  // @319_49cda0
  L49d161:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @321_49cda0
  FL[0] = ecx; FL[1] = (u32)(8);  // @322_49cda0
  if (FL[0] == FL[1]) goto L49d198;  // @323_49cda0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @324_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @325_49cda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 65), &v, sizeof v); }  // @326_49cda0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @327_49cda0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @328_49cda0
  L49d17a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @330_49cda0
  ecx = (u32)(EBP - 284);  // @331_49cda0
  PV[31] = (u32)(ecx);  // @332_49cda0
  ecx = edi;  // @333_49cda0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[31]);  // @334_49cda0
  ecx = edx = 0;  // @335_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @336_49cda0
  FL[2] = (eax & eax);  // @337_49cda0
  if (FL[2] != 0) goto L49cf52;  // @338_49cda0
  goto L49d1e2;  // @339_49cda0
  L49d198:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @341_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @342_49cda0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876480), (u32)(1348));  // @343_49cda0
  ecx = edx = 0;  // @344_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; });  // @345_49cda0
  esi = eax;  // @346_49cda0
  eax = (u32)(EBP - 276);  // @347_49cda0
  PV[32] = (u32)(eax);  // @348_49cda0
  eax = ext_4da2f0_thiscall3(ecx, PV[32], (u32)(1));  // @349_49cda0
  ecx = edx = 0;  // @350_49cda0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @351_49cda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @352_49cda0
  PV[34] = (u32)(esi);  // @353_49cda0
  reg.state = (s32)((u32)(1));  // @354_49cda0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 48)))(PV[34], (u32)(6876760), PV[33]);  // @355_49cda0
  ecx = edx = 0;  // @356_49cda0
  ecx = (u32)(EBP - 276);  // @357_49cda0
  eax = ext_4cbec0_thiscall1(ecx);  // @358_49cda0
  ecx = edx = 0;  // @359_49cda0
  L49d1e2:;
  ecx = (u32)(EBP - 328);  // @361_49cda0
  eax = ext_4ccfe0_thiscall1(ecx);  // @362_49cda0
  ecx = edx = 0;  // @363_49cda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @364_49cda0
  eax = (eax + (u32)(65));  // @365_49cda0
  FL[3] = eax;  // @366_49cda0
  L49d1f6:;
  SEH_LEAVE();  // @368_49cda0
  ext_633654(G(u32, 0x6f5630));  // @369_49cda0
  return eax;  // @370_49cda0
}
PCREG(49cda0, lifted_49cda0);

