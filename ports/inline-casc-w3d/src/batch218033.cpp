// batch218033.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_5fa640_fastcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5fa640");
extern "C" u32 FASTCALL ext_604570_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_604570");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_50d7b0_thiscall2(u32, u32) __asm__("ext_50d7b0");
extern "C" u32 THISCALL ext_57c870_thiscall2(u32, u32) __asm__("ext_57c870");
extern "C" u32 THISCALL ext_57c910_thiscall2(u32, u32) __asm__("ext_57c910");
extern "C" u32 THISCALL ext_57d460_thiscall2(u32, u32) __asm__("ext_57d460");
extern "C" u32 THISCALL ext_57d830_thiscall1(u32) __asm__("ext_57d830");
extern "C" u32 THISCALL ext_57dde0_thiscall1(u32) __asm__("ext_57dde0");
extern "C" u32 THISCALL ext_57ee90_thiscall1(u32) __asm__("ext_57ee90");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_57d950(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b301);  // @h_57d950
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_57d950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_57d950
  eax = ext_57d830_thiscall1(ecx);  // @2_57d950
  ecx = edx = 0;  // @3_57d950
  ecx = eax;  // @4_57d950
  eax = ext_57dde0_thiscall1(ecx);  // @5_57d950
  ecx = edx = 0;  // @6_57d950
  edi = eax;  // @7_57d950
  esi = (esi + (u32)(572));  // @8_57d950
  FL[3] = esi;  // @9_57d950
  if (FL[3] == 0) goto L57db1d;  // @10_57d950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_57d950
  eax = (u32)(EBP - 408);  // @12_57d950
  PV[0] = (u32)(eax);  // @13_57d950
  ecx = esi;  // @14_57d950
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[0]);  // @15_57d950
  ecx = edx = 0;  // @16_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_57d950
  ecx = (u32)(EBP - 408);  // @18_57d950
  PV[1] = (u32)(ecx);  // @19_57d950
  ecx = esi;  // @20_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @21_57d950
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @22_57d950
  ecx = edx = 0;  // @23_57d950
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 408), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @24_57d950
  edx = eax;  // @25_57d950
  if (FL[0] == FL[1]) goto L57db1d;  // @26_57d950
  L57d9d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @28_57d950
  PV[2] = (u32)(edx);  // @29_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 204), sizeof v); (u32)v; });  // @31_57d950
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[2]);  // @32_57d950
  ecx = edx = 0;  // @33_57d950
  ecx = (u32)(EBP - 32);  // @34_57d950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 396), &v, sizeof v); }  // @35_57d950
  PV[3] = (u32)(ecx);  // @36_57d950
  ecx = eax;  // @37_57d950
  eax = ext_57d460_thiscall2(ecx, PV[3]);  // @38_57d950
  ecx = edx = 0;  // @39_57d950
  ecx = 0;  // @40_57d950
  FL[3] = ecx;  // @41_57d950
  FL[2] = (eax & eax);  // @42_57d950
  if (FL[2] == 0) goto L57dafe;  // @43_57d950
  L57da00:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx*4 - 32), sizeof v); (u32)v; }); FL[1] = edi;  // @45_57d950
  if (FL[0] == FL[1]) goto L57da10;  // @46_57d950
  ecx = (ecx + 1);  // @47_57d950
  FL[3] = ecx;  // @48_57d950
  FL[0] = ecx; FL[1] = eax;  // @49_57d950
  if (FL[0] < FL[1]) goto L57da00;  // @50_57d950
  goto L57dafe;  // @51_57d950
  L57da10:;
  ecx = (u32)(EBP - 392);  // @53_57d950
  eax = ext_4cbeb0_thiscall1(ecx);  // @54_57d950
  ecx = edx = 0;  // @55_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 396), sizeof v); (u32)v; });  // @56_57d950
  ecx = (u32)(EBP - 164);  // @57_57d950
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @58_57d950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 231), &v, sizeof v); }  // @59_57d950
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 227), &v, sizeof v); }  // @60_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @61_57d950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 217), &v, sizeof v); }  // @62_57d950
  reg.state = (s32)((u32)(0));  // @63_57d950
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_57d950
  eax = ext_4cbe80_thiscall2(ecx, PV[4]);  // @65_57d950
  ecx = edx = 0;  // @66_57d950
  eax = (u32)(EBP - 164);  // @67_57d950
  reg.state = (s32)((u32)(1));  // @68_57d950
  PV[5] = (u32)(eax);  // @69_57d950
  ecx = (u32)(EBP - 392);  // @70_57d950
  eax = ext_4cbee0_thiscall2(ecx, PV[5]);  // @71_57d950
  ecx = edx = 0;  // @72_57d950
  ecx = (u32)(EBP - 164);  // @73_57d950
  reg.state = (s32)((u32)(0));  // @74_57d950
  eax = ext_4cbec0_thiscall1(ecx);  // @75_57d950
  ecx = edx = 0;  // @76_57d950
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 0), 4); v; });  // @77_57d950
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 4), 4); v; });  // @78_57d950
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 8), 4); v; });  // @79_57d950
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791824) + 12), 4); v; });  // @80_57d950
  eax = (u32)(EBP - 392);  // @81_57d950
  PV[6] = (u32)(eax);  // @82_57d950
  ecx = (u32)(EBP - 212);  // @83_57d950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 225), &v, sizeof v); }  // @84_57d950
  __builtin_memcpy((void *)((u32)(EBP - 264) + 0), &X0[0], 4);  // @85_57d950
  __builtin_memcpy((void *)((u32)(EBP - 264) + 4), &X0[1], 4);  // @86_57d950
  __builtin_memcpy((void *)((u32)(EBP - 264) + 8), &X0[2], 4);  // @87_57d950
  __builtin_memcpy((void *)((u32)(EBP - 264) + 12), &X0[3], 4);  // @88_57d950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 221), &v, sizeof v); }  // @89_57d950
  eax = ext_57c870_thiscall2(ecx, PV[6]);  // @90_57d950
  ecx = edx = 0;  // @91_57d950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 396), sizeof v); (u32)v; });  // @92_57d950
  eax = (u32)(EBP - 212);  // @93_57d950
  PV[7] = (u32)(eax);  // @94_57d950
  reg.state = (s32)((u32)(2));  // @95_57d950
  ecx = (u32)(ecx + 44);  // @96_57d950
  eax = ext_57c910_thiscall2(ecx, PV[7]);  // @97_57d950
  ecx = edx = 0;  // @98_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 396), sizeof v); (u32)v; });  // @99_57d950
  ecx = eax;  // @100_57d950
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 223), &v, sizeof v); }  // @101_57d950
  eax = ext_57ee90_thiscall1(ecx);  // @102_57d950
  ecx = edx = 0;  // @103_57d950
  ecx = (u32)(EBP - 212);  // @104_57d950
  eax = ext_4cbec0_thiscall1(ecx);  // @105_57d950
  ecx = edx = 0;  // @106_57d950
  ecx = (u32)(EBP - 392);  // @107_57d950
  reg.state = (s32)((u32)(4294967295));  // @108_57d950
  eax = ext_4cbec0_thiscall1(ecx);  // @109_57d950
  ecx = edx = 0;  // @110_57d950
  L57dafe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_57d950
  ecx = (u32)(EBP - 408);  // @113_57d950
  PV[8] = (u32)(ecx);  // @114_57d950
  ecx = esi;  // @115_57d950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @116_57d950
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[8]);  // @117_57d950
  ecx = edx = 0;  // @118_57d950
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 408), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_57d950
  edx = eax;  // @120_57d950
  if (FL[0] != FL[1]) goto L57d9d0;  // @121_57d950
  L57db1d:;
  SEH_LEAVE();  // @123_57d950
  ext_633654(G(u32, 0x6f5630));  // @124_57d950
  return eax;  // @125_57d950
}
PCREG(57d950, lifted_57d950);

extern "C" u32 THISCALL lifted_605630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66de1e);  // @h_605630
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_605630
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_605630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @2_605630
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_605630
  ecx = edx = 0;  // @4_605630
  ecx = (u32)(EBP - 24);  // @5_605630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_605630
  eax = (u32)(EBP + 11);  // @7_605630
  PV[0] = (u32)(eax);  // @8_605630
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @9_605630
  eax = ext_42b390_thiscall3(ecx, PV[1], PV[0]);  // @10_605630
  ecx = edx = 0;  // @11_605630
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @12_605630
  esi = edi;  // @13_605630
  reg.state = (s32)((u32)(0));  // @14_605630
  ecx = (u32)(esi + 1);  // @15_605630
  L605687:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @17_605630
  esi = (esi + 1);  // @18_605630
  FL[3] = esi;  // @19_605630
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @20_605630
  if (FL[2] != 0) goto L605687;  // @21_605630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @22_605630
  esi = (esi - ecx);  // @23_605630
  FL[3] = esi;  // @24_605630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @25_605630
  eax = edx;  // @26_605630
  eax = (eax - ecx);  // @27_605630
  FL[3] = eax;  // @28_605630
  FL[0] = esi; FL[1] = eax;  // @29_605630
  if (FL[0] > FL[1]) goto L60570b;  // @30_605630
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @31_605630
  eax = (u32)(esi + edi);  // @32_605630
  PV[3] = (u32)(eax);  // @33_605630
  PV[4] = (u32)(edi);  // @34_605630
  eax = ext_604570_fastcall5(ecx, edx, PV[4], PV[3], PV[2]);  // @35_605630
  ecx = edx = 0;  // @36_605630
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @37_605630
  if (FL[0] == FL[1]) goto L60570b;  // @38_605630
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @39_605630
  FL[3] = eax;  // @40_605630
  if (FL[3] != 0) goto L60570b;  // @41_605630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @42_605630
  PV[5] = (u32)(eax);  // @43_605630
  eax = ext_5003d0_thiscall2(ecx, PV[5]);  // @44_605630
  ecx = edx = 0;  // @45_605630
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @46_605630
  if (FL[0] > FL[1]) goto L6056d3;  // @47_605630
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @48_605630
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @49_605630
  goto L60575d;  // @50_605630
  L6056d3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @52_605630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_605630
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(196));  // @54_605630
  ecx = edx = 0;  // @55_605630
  PV[6] = (u32)(eax);  // @56_605630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_605630
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[6], (u32)(6932144), (u32)(6932792));  // @58_605630
  ecx = edx = 0;  // @59_605630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @60_605630
  FL[2] = (eax & eax);  // @61_605630
  if (FL[2] == 0) goto L605708;  // @62_605630
  eax = ((u32(STDCALL *)(void))(eax))();  // @63_605630
  ecx = edx = 0;  // @64_605630
  goto L60575d;  // @65_605630
  L605708:;
  __builtin_trap();  // @67_605630
  L60570b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @69_605630
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @70_605630
  ecx = edx = 0;  // @71_605630
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @72_605630
  if (FL[0] > FL[1]) goto L605727;  // @73_605630
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @74_605630
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @75_605630
  goto L60575d;  // @76_605630
  L605727:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @78_605630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_605630
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(196));  // @80_605630
  ecx = edx = 0;  // @81_605630
  PV[7] = (u32)(eax);  // @82_605630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @83_605630
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(6932144), (u32)(6932792));  // @84_605630
  ecx = edx = 0;  // @85_605630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @86_605630
  FL[2] = (eax & eax);  // @87_605630
  if (FL[2] == 0) goto L60575c;  // @88_605630
  eax = ((u32(STDCALL *)(void))(eax))();  // @89_605630
  ecx = edx = 0;  // @90_605630
  goto L60575d;  // @91_605630
  L60575c:;
  __builtin_trap();  // @93_605630
  L60575d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @95_605630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @96_605630
  eax = (eax - ecx);  // @97_605630
  FL[3] = eax;  // @98_605630
  reg.state = (s32)((u32)(1));  // @99_605630
  FL[2] = (ecx & ecx);  // @100_605630
  if (FL[2] == 0) goto L60577e;  // @101_605630
  FL[2] = (eax & eax);  // @102_605630
  if (FL[2] == 0) goto L60577e;  // @103_605630
  PV[8] = (u32)(eax);  // @104_605630
  PV[9] = (u32)(ecx);  // @105_605630
  ecx = (u32)(EBP - 24);  // @106_605630
  eax = ext_54f870_stdcall2(PV[9], PV[8]);  // @107_605630
  ecx = edx = 0;  // @108_605630
  L60577e:;
  SEH_LEAVE();  // @110_605630
  return eax;  // @111_605630
}
PCREG(605630, lifted_605630);

extern "C" u32 THISCALL lifted_605150(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dd6e);  // @h_605150
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_605150
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_605150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @2_605150
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_605150
  ecx = edx = 0;  // @4_605150
  ecx = (u32)(EBP - 36);  // @5_605150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_605150
  eax = (u32)(EBP + 11);  // @7_605150
  PV[0] = (u32)(eax);  // @8_605150
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @9_605150
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @10_605150
  eax = ext_42b390_thiscall3(ecx, PV[1], PV[0]);  // @11_605150
  ecx = edx = 0;  // @12_605150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @13_605150
  ecx = eax;  // @14_605150
  reg.state = (s32)((u32)(0));  // @15_605150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @16_605150
  edx = (u32)(ecx + 1);  // @17_605150
  L6051b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @19_605150
  ecx = (ecx + 1);  // @20_605150
  FL[3] = ecx;  // @21_605150
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @22_605150
  if (FL[2] != 0) goto L6051b0;  // @23_605150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @24_605150
  ecx = (ecx - edx);  // @25_605150
  FL[3] = ecx;  // @26_605150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @27_605150
  edx = esi;  // @28_605150
  edx = (edx - edi);  // @29_605150
  FL[3] = edx;  // @30_605150
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @31_605150
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @32_605150
  FL[0] = ecx; FL[1] = edx;  // @33_605150
  if (FL[0] > FL[1]) goto L605265;  // @34_605150
  eax = (u32)(EBP + 8);  // @35_605150
  FL[2] = (ecx & ecx);  // @36_605150
  if (FL[2] != 0) goto L6051e9;  // @37_605150
  ecx = (u32)(EBP - 16);  // @38_605150
  FL[0] = edx; FL[1] = (u32)(-1);  // @39_605150
  if (FL[0] <= FL[1]) eax = ecx;  // @40_605150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_605150
  goto L605225;  // @42_605150
  L6051e9:;
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_605150
  edx = (edx - ecx);  // @45_605150
  FL[3] = edx;  // @46_605150
  esi = (u32)(EBP - 16);  // @47_605150
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @48_605150
  FL[0] = edx; FL[1] = (u32)(-1);  // @49_605150
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @50_605150
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @51_605150
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @52_605150
  if (FL[0] <= FL[1]) eax = esi;  // @53_605150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_605150
  eax = (u32)(ecx + edx);  // @55_605150
  esi = (esi + ecx);  // @56_605150
  FL[3] = esi;  // @57_605150
  ecx = edi;  // @58_605150
  PV[5] = (u32)(eax);  // @59_605150
  esi = (esi + edi);  // @60_605150
  FL[3] = esi;  // @61_605150
  PV[6] = (u32)(edx);  // @62_605150
  edx = esi;  // @63_605150
  eax = ext_5fa640_fastcall7(ecx, edx, PV[6], PV[5], PV[4], PV[3], PV[2]);  // @64_605150
  ecx = edx = 0;  // @65_605150
  ecx = eax;  // @66_605150
  FL[0] = ecx; FL[1] = esi;  // @67_605150
  if (FL[0] == FL[1]) goto L605265;  // @68_605150
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @69_605150
  ecx = (ecx - edi);  // @70_605150
  FL[3] = ecx;  // @71_605150
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @72_605150
  L605225:;
  FL[2] = (ecx & ecx);  // @74_605150
  if ((s32)FL[2] <= 0) goto L605265;  // @75_605150
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @76_605150
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @77_605150
  eax = (u32)(edx + 1);  // @78_605150
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @79_605150
  L605235:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @81_605150
  edx = (edx + 1);  // @82_605150
  FL[3] = edx;  // @83_605150
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @84_605150
  if (FL[2] != 0) goto L605235;  // @85_605150
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @86_605150
  FL[3] = edx;  // @87_605150
  esi = (esi - edx);  // @88_605150
  FL[3] = esi;  // @89_605150
  esi = (esi - edi);  // @90_605150
  FL[3] = esi;  // @91_605150
  FL[0] = ecx; FL[1] = esi;  // @92_605150
  if (FL[0] != FL[1]) goto L605265;  // @93_605150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @94_605150
  eax = (u32)(EBP + 8);  // @95_605150
  PV[7] = (u32)(eax);  // @96_605150
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @97_605150
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @98_605150
  ecx = edx = 0;  // @99_605150
  ecx = eax;  // @100_605150
  eax = ext_50d7b0_thiscall2(ecx, PV[7]);  // @101_605150
  ecx = edx = 0;  // @102_605150
  goto L6052b7;  // @103_605150
  L605265:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @105_605150
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @106_605150
  ecx = edx = 0;  // @107_605150
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @108_605150
  if (FL[0] > FL[1]) goto L605281;  // @109_605150
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @110_605150
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @111_605150
  goto L6052b7;  // @112_605150
  L605281:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @114_605150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_605150
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(196));  // @116_605150
  ecx = edx = 0;  // @117_605150
  PV[8] = (u32)(eax);  // @118_605150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_605150
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[8], (u32)(6932144), (u32)(6932792));  // @120_605150
  ecx = edx = 0;  // @121_605150
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @122_605150
  FL[2] = (eax & eax);  // @123_605150
  if (FL[2] == 0) goto L6052b6;  // @124_605150
  eax = ((u32(STDCALL *)(void))(eax))();  // @125_605150
  ecx = edx = 0;  // @126_605150
  goto L6052b7;  // @127_605150
  L6052b6:;
  __builtin_trap();  // @129_605150
  L6052b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @131_605150
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @132_605150
  eax = (eax - ecx);  // @133_605150
  FL[3] = eax;  // @134_605150
  reg.state = (s32)((u32)(1));  // @135_605150
  FL[2] = (ecx & ecx);  // @136_605150
  if (FL[2] == 0) goto L6052d8;  // @137_605150
  FL[2] = (eax & eax);  // @138_605150
  if (FL[2] == 0) goto L6052d8;  // @139_605150
  PV[9] = (u32)(eax);  // @140_605150
  PV[10] = (u32)(ecx);  // @141_605150
  ecx = (u32)(EBP - 36);  // @142_605150
  eax = ext_54f870_stdcall2(PV[10], PV[9]);  // @143_605150
  ecx = edx = 0;  // @144_605150
  L6052d8:;
  SEH_LEAVE();  // @146_605150
  return eax;  // @147_605150
}
PCREG(605150, lifted_605150);

