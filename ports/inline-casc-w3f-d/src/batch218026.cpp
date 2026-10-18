// batch218026.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 STDCALL ext_635380_stdcall1(u32) __asm__("ext_635380");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccb40_thiscall3(u32, u32, u32) __asm__("ext_4ccb40");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccef0_thiscall1(u32) __asm__("ext_4ccef0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cd6f0_thiscall3(u32, u32, u32) __asm__("ext_4cd6f0");
extern "C" u32 THISCALL ext_4cf690_thiscall1(u32) __asm__("ext_4cf690");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4da1d0_thiscall2(u32, u32) __asm__("ext_4da1d0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_506040_thiscall1(u32) __asm__("ext_506040");
extern "C" u32 THISCALL ext_50d7b0_thiscall2(u32, u32) __asm__("ext_50d7b0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_5556b0(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5556b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @1_5556b0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @2_5556b0
  ecx = edx = 0;  // @3_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_5556b0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @5_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @6_5556b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5556b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @8_5556b0
  ecx = edx = 0;  // @9_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @10_5556b0
  esi = eax;  // @11_5556b0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @12_5556b0
  ecx = edx = 0;  // @13_5556b0
  ecx = eax;  // @14_5556b0
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @15_5556b0
  ecx = edx = 0;  // @16_5556b0
  FL[2] = (esi & esi);  // @17_5556b0
  if (FL[2] != 0) goto L55573e;  // @18_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5556b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(747));  // @21_5556b0
  ecx = edx = 0;  // @22_5556b0
  PV[1] = (u32)(eax);  // @23_5556b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_5556b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6969796));  // @25_5556b0
  ecx = edx = 0;  // @26_5556b0
  goto L555812;  // @27_5556b0
  L55573e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_5556b0
  ecx = esi;  // @30_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @31_5556b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2099193));  // @32_5556b0
  ecx = edx = 0;  // @33_5556b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @34_5556b0
  ecx = esi;  // @35_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_5556b0
  if (FL[2] == 0) goto L55578c;  // @37_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @38_5556b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @39_5556b0
  ecx = edx = 0;  // @40_5556b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @41_5556b0
  if (FL[2] != 0) goto L555785;  // @42_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_5556b0
  ecx = esi;  // @44_5556b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1652)))(ecx);  // @45_5556b0
  ecx = edx = 0;  // @46_5556b0
  FL[2] = (eax & eax);  // @47_5556b0
  if (FL[2] == 0) goto L555785;  // @48_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_5556b0
  ecx = esi;  // @50_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1648), sizeof v); (u32)v; });  // @51_5556b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @52_5556b0
  ecx = edx = 0;  // @53_5556b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @54_5556b0
  if (FL[2] != 0) goto L555785;  // @55_5556b0
  eax = 0;  // @56_5556b0
  FL[3] = eax;  // @57_5556b0
  goto L5557ac;  // @58_5556b0
  L555785:;
  eax = (u32)(1);  // @60_5556b0
  goto L5557ac;  // @61_5556b0
  L55578c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @63_5556b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(esi, (u32)(2098152));  // @64_5556b0
  ecx = edx = 0;  // @65_5556b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @66_5556b0
  if (FL[2] == 0) goto L5557c0;  // @67_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @68_5556b0
  ecx = esi;  // @69_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @70_5556b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @71_5556b0
  ecx = edx = 0;  // @72_5556b0
  eax = (eax & 0xff);  // @73_5556b0
  L5557ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @75_5556b0
  PV[2] = (u32)(eax);  // @76_5556b0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @77_5556b0
  ecx = edx = 0;  // @78_5556b0
  ecx = eax;  // @79_5556b0
  eax = ext_5002f0_thiscall2(ecx, PV[2]);  // @80_5556b0
  ecx = edx = 0;  // @81_5556b0
  goto L555812;  // @82_5556b0
  L5557c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @84_5556b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_5556b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6969340), (u32)(760));  // @86_5556b0
  ecx = edx = 0;  // @87_5556b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_5556b0
  edi = eax;  // @89_5556b0
  eax = (u32)(EBP - 144);  // @90_5556b0
  ecx = esi;  // @91_5556b0
  PV[3] = (u32)(eax);  // @92_5556b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[3], (u32)(1));  // @93_5556b0
  ecx = edx = 0;  // @94_5556b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @95_5556b0
  ecx = eax;  // @96_5556b0
  reg.state = (s32)((u32)(0));  // @97_5556b0
  eax = ext_4cc1d0_thiscall1(ecx);  // @98_5556b0
  ecx = edx = 0;  // @99_5556b0
  PV[4] = (u32)(eax);  // @100_5556b0
  PV[5] = (u32)(edi);  // @101_5556b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[5], (u32)(6969856), PV[4]);  // @102_5556b0
  ecx = edx = 0;  // @103_5556b0
  ecx = (u32)(EBP - 144);  // @104_5556b0
  eax = ext_4cbec0_thiscall1(ecx);  // @105_5556b0
  ecx = edx = 0;  // @106_5556b0
  L555812:;
  SEH_LEAVE();  // @108_5556b0
  ext_633654(G(u32, 0x6f5630));  // @109_5556b0
  return eax;  // @110_5556b0
}
PCREG(5556b0, lifted_5556b0);

extern "C" u32 STDCALL lifted_50c610(u32 a0) {
  SEH_ENTER(0x66713b);  // @h_50c610
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @1_50c610
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @2_50c610
  ecx = edx = 0;  // @3_50c610
  ecx = eax;  // @4_50c610
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @5_50c610
  ecx = edx = 0;  // @6_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @7_50c610
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @8_50c610
  ecx = edx = 0;  // @9_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_50c610
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @11_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @12_50c610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_50c610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @14_50c610
  ecx = edx = 0;  // @15_50c610
  edi = eax;  // @16_50c610
  FL[2] = (edi & edi);  // @17_50c610
  if (FL[2] != 0) goto L50c69f;  // @18_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @19_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_50c610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6935584), (u32)(304));  // @21_50c610
  ecx = edx = 0;  // @22_50c610
  PV[1] = (u32)(eax);  // @23_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_50c610
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6936096));  // @25_50c610
  ecx = edx = 0;  // @26_50c610
  goto L50c7c1;  // @27_50c610
  L50c69f:;
  ecx = (u32)(EBP - 188);  // @29_50c610
  eax = ext_4ccba0_thiscall1(ecx);  // @30_50c610
  ecx = edx = 0;  // @31_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_50c610
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @33_50c610
  reg.state = (s32)((u32)(0));  // @34_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_50c610
  eax = (u32)(EBP - 188);  // @36_50c610
  PV[2] = (u32)(eax);  // @37_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_50c610
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6883888), (u32)(0), (u32)(6935584), (u32)(310));  // @39_50c610
  ecx = edx = 0;  // @40_50c610
  eax = (eax & 0xffff);  // @41_50c610
  ecx = edi;  // @42_50c610
  PV[3] = (u32)(eax);  // @43_50c610
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[3], PV[2], (u32)(0));  // @44_50c610
  ecx = edx = 0;  // @45_50c610
  eax = (u32)(EBP - 204);  // @46_50c610
  PV[4] = (u32)(eax);  // @47_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @48_50c610
  ecx = (u32)(EBP - 188);  // @49_50c610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @50_50c610
  ecx = edx = 0;  // @51_50c610
  eax = (u32)(EBP - 204);  // @52_50c610
  PV[5] = (u32)(eax);  // @53_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @54_50c610
  ecx = (u32)(EBP - 188);  // @55_50c610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @56_50c610
  ecx = edx = 0;  // @57_50c610
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @58_50c610
  edi = eax;  // @59_50c610
  if (FL[0] == FL[1]) goto L50c7b6;  // @60_50c610
  L50c730:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_50c610
  PV[6] = (u32)(edi);  // @63_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @64_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_50c610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[6]);  // @66_50c610
  ecx = edx = 0;  // @67_50c610
  FL[2] = (eax & eax);  // @68_50c610
  if (FL[2] == 0) goto L50c791;  // @69_50c610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @70_50c610
  ecx = eax;  // @71_50c610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @72_50c610
  ecx = edx = 0;  // @73_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @74_50c610
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @75_50c610
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @76_50c610
  ecx = edx = 0;  // @77_50c610
  ecx = eax;  // @78_50c610
  eax = ext_506040_thiscall1(ecx);  // @79_50c610
  ecx = edx = 0;  // @80_50c610
  PV[7] = (u32)(eax);  // @81_50c610
  PV[8] = (u32)(esi);  // @82_50c610
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[8], PV[7]);  // @83_50c610
  ecx = edx = 0;  // @84_50c610
  FL[2] = (eax & eax);  // @85_50c610
  if (FL[2] != 0) goto L50c791;  // @86_50c610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @87_50c610
  eax = (u32)(EBP - 192);  // @88_50c610
  PV[9] = (u32)(eax);  // @89_50c610
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @90_50c610
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @91_50c610
  ecx = edx = 0;  // @92_50c610
  ecx = eax;  // @93_50c610
  eax = ext_50d7b0_thiscall2(ecx, PV[9]);  // @94_50c610
  ecx = edx = 0;  // @95_50c610
  L50c791:;
  eax = (u32)(EBP - 204);  // @97_50c610
  PV[10] = (u32)(eax);  // @98_50c610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @99_50c610
  ecx = (u32)(EBP - 188);  // @100_50c610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[10]);  // @101_50c610
  ecx = edx = 0;  // @102_50c610
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @103_50c610
  edi = eax;  // @104_50c610
  if (FL[0] != FL[1]) goto L50c730;  // @105_50c610
  L50c7b6:;
  ecx = (u32)(EBP - 188);  // @107_50c610
  eax = ext_4ccf60_thiscall1(ecx);  // @108_50c610
  ecx = edx = 0;  // @109_50c610
  L50c7c1:;
  SEH_LEAVE();  // @111_50c610
  ext_633654(G(u32, 0x6f5630));  // @112_50c610
  return eax;  // @113_50c610
}
PCREG(50c610, lifted_50c610);

extern "C" u32 STDCALL lifted_50e310(u32 a0) {
  SEH_ENTER(0x669f2b);  // @h_50e310
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_50e310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_50e310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @2_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @3_50e310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @4_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @5_50e310
  ecx = edx = 0;  // @6_50e310
  esi = eax;  // @7_50e310
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @8_50e310
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @9_50e310
  if (FL[2] == 0) goto L50e3a4;  // @10_50e310
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @11_50e310
  if (FL[0] == FL[1]) goto L50e3a4;  // @12_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @13_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @15_50e310
  ecx = edx = 0;  // @16_50e310
  PV[0] = (u32)(eax);  // @17_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @19_50e310
  ecx = edx = 0;  // @20_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @21_50e310
  FL[2] = (eax & eax);  // @22_50e310
  if (FL[2] == 0) goto L50e3a3;  // @23_50e310
  eax = ((u32(STDCALL *)(void))(eax))();  // @24_50e310
  ecx = edx = 0;  // @25_50e310
  goto L50e3a4;  // @26_50e310
  L50e3a3:;
  __builtin_trap();  // @28_50e310
  L50e3a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_50e310
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_50e310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @34_50e310
  ecx = edx = 0;  // @35_50e310
  esi = eax;  // @36_50e310
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @37_50e310
  FL[2] = (esi & esi);  // @38_50e310
  if (FL[2] != 0) goto L50e4c1;  // @39_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @40_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6937396), (u32)(709));  // @42_50e310
  ecx = edx = 0;  // @43_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @44_50e310
  edi = eax;  // @45_50e310
  PV[2] = (u32)(esi);  // @46_50e310
  eax = ext_5003d0_thiscall2(ecx, PV[2]);  // @47_50e310
  ecx = edx = 0;  // @48_50e310
  esi = eax;  // @49_50e310
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @50_50e310
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @51_50e310
  if (FL[2] == 0) goto L50e42a;  // @52_50e310
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @53_50e310
  if (FL[0] == FL[1]) goto L50e42a;  // @54_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @55_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @57_50e310
  ecx = edx = 0;  // @58_50e310
  PV[3] = (u32)(eax);  // @59_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @61_50e310
  ecx = edx = 0;  // @62_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @63_50e310
  FL[2] = (eax & eax);  // @64_50e310
  if (FL[2] == 0) goto L50e429;  // @65_50e310
  eax = ((u32(STDCALL *)(void))(eax))();  // @66_50e310
  ecx = edx = 0;  // @67_50e310
  goto L50e42a;  // @68_50e310
  L50e429:;
  __builtin_trap();  // @70_50e310
  L50e42a:;
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @73_50e310
  PV[5] = (u32)(edi);  // @74_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[5], (u32)(6938464), PV[4]);  // @75_50e310
  ecx = edx = 0;  // @76_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @77_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @78_50e310
  ecx = edx = 0;  // @79_50e310
  ecx = eax;  // @80_50e310
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @81_50e310
  ecx = edx = 0;  // @82_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @83_50e310
  edi = eax;  // @84_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @85_50e310
  ecx = edx = 0;  // @86_50e310
  esi = eax;  // @87_50e310
  FL[0] = edi; FL[1] = esi;  // @88_50e310
  if (FL[0] == FL[1]) goto L50e485;  // @89_50e310
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @90_50e310
  if (FL[0] != FL[1]) goto L50e46c;  // @91_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @94_50e310
  ecx = edx = 0;  // @95_50e310
  L50e46c:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @97_50e310
  if (FL[0] == FL[1]) goto L50e476;  // @98_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @99_50e310
  goto L50e47d;  // @100_50e310
  L50e476:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @102_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @104_50e310
  ecx = edx = 0;  // @105_50e310
  L50e47d:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @107_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @108_50e310
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @109_50e310
  L50e485:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @111_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @112_50e310
  ecx = edx = 0;  // @113_50e310
  edi = eax;  // @114_50e310
  FL[0] = esi; FL[1] = edi;  // @115_50e310
  if (FL[0] == FL[1]) goto L50e4bb;  // @116_50e310
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @117_50e310
  if (FL[0] != FL[1]) goto L50e4a2;  // @118_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @119_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @121_50e310
  ecx = edx = 0;  // @122_50e310
  L50e4a2:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @124_50e310
  if (FL[0] == FL[1]) goto L50e4ac;  // @125_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_50e310
  goto L50e4b3;  // @127_50e310
  L50e4ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @131_50e310
  ecx = edx = 0;  // @132_50e310
  L50e4b3:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @134_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @135_50e310
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @136_50e310
  L50e4bb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @138_50e310
  L50e4c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_50e310
  ecx = esi;  // @141_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @142_50e310
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097191));  // @143_50e310
  ecx = edx = 0;  // @144_50e310
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @145_50e310
  if (FL[2] != 0) goto L50e5ba;  // @146_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @147_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6937396), (u32)(714));  // @149_50e310
  ecx = edx = 0;  // @150_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_50e310
  edi = eax;  // @152_50e310
  eax = (u32)(EBP - 156);  // @153_50e310
  ecx = esi;  // @154_50e310
  PV[6] = (u32)(eax);  // @155_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(1));  // @156_50e310
  ecx = edx = 0;  // @157_50e310
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @158_50e310
  ecx = eax;  // @159_50e310
  reg.state = (s32)((u32)(0));  // @160_50e310
  eax = ext_4cc1d0_thiscall1(ecx);  // @161_50e310
  ecx = edx = 0;  // @162_50e310
  PV[7] = (u32)(eax);  // @163_50e310
  PV[8] = (u32)(edi);  // @164_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[8], (u32)(6938528), PV[7]);  // @165_50e310
  ecx = edx = 0;  // @166_50e310
  reg.state = (s32)((u32)(4294967295));  // @167_50e310
  ecx = (u32)(EBP - 156);  // @168_50e310
  eax = ext_4cbec0_thiscall1(ecx);  // @169_50e310
  ecx = edx = 0;  // @170_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @171_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @172_50e310
  ecx = edx = 0;  // @173_50e310
  ecx = eax;  // @174_50e310
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @175_50e310
  ecx = edx = 0;  // @176_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @177_50e310
  edi = eax;  // @178_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @179_50e310
  ecx = edx = 0;  // @180_50e310
  esi = eax;  // @181_50e310
  FL[0] = edi; FL[1] = esi;  // @182_50e310
  if (FL[0] == FL[1]) goto L50e57e;  // @183_50e310
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @184_50e310
  if (FL[0] != FL[1]) goto L50e565;  // @185_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @186_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @187_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @188_50e310
  ecx = edx = 0;  // @189_50e310
  L50e565:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @191_50e310
  if (FL[0] == FL[1]) goto L50e56f;  // @192_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @193_50e310
  goto L50e576;  // @194_50e310
  L50e56f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @196_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @198_50e310
  ecx = edx = 0;  // @199_50e310
  L50e576:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @201_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @202_50e310
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @203_50e310
  L50e57e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @205_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @206_50e310
  ecx = edx = 0;  // @207_50e310
  edi = eax;  // @208_50e310
  FL[0] = esi; FL[1] = edi;  // @209_50e310
  if (FL[0] == FL[1]) goto L50e5b4;  // @210_50e310
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @211_50e310
  if (FL[0] != FL[1]) goto L50e59b;  // @212_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @213_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @215_50e310
  ecx = edx = 0;  // @216_50e310
  L50e59b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(4);  // @218_50e310
  if (FL[0] == FL[1]) goto L50e5a5;  // @219_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @220_50e310
  goto L50e5ac;  // @221_50e310
  L50e5a5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @223_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @225_50e310
  ecx = edx = 0;  // @226_50e310
  L50e5ac:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @228_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @229_50e310
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @230_50e310
  L50e5b4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @232_50e310
  L50e5ba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @234_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @235_50e310
  ecx = edx = 0;  // @236_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @237_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @238_50e310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @239_50e310
  ecx = edx = 0;  // @240_50e310
  PV[9] = (u32)(eax);  // @241_50e310
  ecx = (u32)(EBP - 161);  // @242_50e310
  eax = ext_635380_stdcall1(PV[9]);  // @243_50e310
  ecx = edx = 0;  // @244_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @245_50e310
  ecx = esi;  // @246_50e310
  eax = (eax & 0xff);  // @247_50e310
  PV[10] = (u32)(eax);  // @248_50e310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 692)))(ecx, PV[10]);  // @249_50e310
  ecx = edx = 0;  // @250_50e310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @251_50e310
  ecx = (u32)(EBP - 28);  // @252_50e310
  PV[11] = (u32)(ecx);  // @253_50e310
  PV[12] = (u32)(eax);  // @254_50e310
  ecx = esi;  // @255_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 920)))(ecx, PV[12], PV[11]);  // @256_50e310
  ecx = edx = 0;  // @257_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @258_50e310
  ecx = (u32)(EBP - 28);  // @259_50e310
  PV[13] = (u32)(ecx);  // @260_50e310
  ecx = esi;  // @261_50e310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[13]);  // @262_50e310
  ecx = edx = 0;  // @263_50e310
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @264_50e310
  X0[1] = 0;  // @265_50e310
  X0[2] = 0;  // @266_50e310
  X0[3] = 0;  // @267_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @268_50e310
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X0[0], 4);  // @269_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @270_50e310
  ecx = edx = 0;  // @271_50e310
  esi = eax;  // @272_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @273_50e310
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @274_50e310
  if (FL[2] == 0) goto L50e65c;  // @275_50e310
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @276_50e310
  if (FL[0] == FL[1]) goto L50e65c;  // @277_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @278_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @279_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @280_50e310
  ecx = edx = 0;  // @281_50e310
  PV[14] = (u32)(eax);  // @282_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @283_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[14], (u32)(6932144), (u32)(6932792));  // @284_50e310
  ecx = edx = 0;  // @285_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @286_50e310
  FL[2] = (eax & eax);  // @287_50e310
  if (FL[2] == 0) goto L50e65b;  // @288_50e310
  eax = ((u32(STDCALL *)(void))(eax))();  // @289_50e310
  ecx = edx = 0;  // @290_50e310
  goto L50e65c;  // @291_50e310
  L50e65b:;
  __builtin_trap();  // @293_50e310
  L50e65c:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @295_50e310
  X0[1] = 0;  // @296_50e310
  X0[2] = 0;  // @297_50e310
  X0[3] = 0;  // @298_50e310
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @299_50e310
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @300_50e310
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @301_50e310
  X0[1] = 0;  // @302_50e310
  X0[2] = 0;  // @303_50e310
  X0[3] = 0;  // @304_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @305_50e310
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X0[0], 4);  // @306_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @307_50e310
  ecx = edx = 0;  // @308_50e310
  esi = eax;  // @309_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @310_50e310
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @311_50e310
  if (FL[2] == 0) goto L50e6c6;  // @312_50e310
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @313_50e310
  if (FL[0] == FL[1]) goto L50e6c6;  // @314_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @315_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @316_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @317_50e310
  ecx = edx = 0;  // @318_50e310
  PV[15] = (u32)(eax);  // @319_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @320_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[15], (u32)(6932144), (u32)(6932792));  // @321_50e310
  ecx = edx = 0;  // @322_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @323_50e310
  FL[2] = (eax & eax);  // @324_50e310
  if (FL[2] == 0) goto L50e6c5;  // @325_50e310
  eax = ((u32(STDCALL *)(void))(eax))();  // @326_50e310
  ecx = edx = 0;  // @327_50e310
  goto L50e6c6;  // @328_50e310
  L50e6c5:;
  __builtin_trap();  // @330_50e310
  L50e6c6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @332_50e310
  X0[1] = 0;  // @333_50e310
  X0[2] = 0;  // @334_50e310
  X0[3] = 0;  // @335_50e310
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @336_50e310
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @337_50e310
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @338_50e310
  X0[1] = 0;  // @339_50e310
  X0[2] = 0;  // @340_50e310
  X0[3] = 0;  // @341_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @342_50e310
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X0[0], 4);  // @343_50e310
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @344_50e310
  ecx = edx = 0;  // @345_50e310
  esi = eax;  // @346_50e310
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @347_50e310
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @348_50e310
  if (FL[2] == 0) goto L50e730;  // @349_50e310
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @350_50e310
  if (FL[0] == FL[1]) goto L50e730;  // @351_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @352_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @353_50e310
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @354_50e310
  ecx = edx = 0;  // @355_50e310
  PV[16] = (u32)(eax);  // @356_50e310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @357_50e310
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[16], (u32)(6932144), (u32)(6932792));  // @358_50e310
  ecx = edx = 0;  // @359_50e310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @360_50e310
  FL[2] = (eax & eax);  // @361_50e310
  if (FL[2] == 0) goto L50e72f;  // @362_50e310
  eax = ((u32(STDCALL *)(void))(eax))();  // @363_50e310
  ecx = edx = 0;  // @364_50e310
  goto L50e730;  // @365_50e310
  L50e72f:;
  __builtin_trap();  // @367_50e310
  L50e730:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @369_50e310
  X0[1] = 0;  // @370_50e310
  X0[2] = 0;  // @371_50e310
  X0[3] = 0;  // @372_50e310
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @373_50e310
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @374_50e310
  SEH_LEAVE();  // @375_50e310
  ext_633654(G(u32, 0x6f5630));  // @376_50e310
  return eax;  // @377_50e310
}
PCREG(50e310, lifted_50e310);

extern "C" u32 THISCALL lifted_476100(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6670a6);  // @h_476100
  u8 F[0x42c0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x41c0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x41c0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x41c0 + 12, &a1, 4);
  edi = ecx;  // @0_476100
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_476100
  ecx = (u32)(EBP - 16768);  // @2_476100
  eax = ext_4d2280_thiscall1(ecx);  // @3_476100
  ecx = edx = 0;  // @4_476100
  ecx = (u32)(EBP - 188);  // @5_476100
  reg.state = (s32)((u32)(0));  // @6_476100
  eax = ext_4ccba0_thiscall1(ecx);  // @7_476100
  ecx = edx = 0;  // @8_476100
  reg.state = (s32)((u32)(1));  // @9_476100
  FL[2] = (esi & esi);  // @10_476100
  PV[1] = 0;  if (FL[2] == 0) goto L47616f;  // @11_476100
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_476100
  PV[0] = (u32)(esi);  // @13_476100
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @14_476100
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_476100
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @16_476100
  ecx = edx = 0;  // @17_476100
  PV[1] = (u32)(eax);  // @18_476100
  goto L476171;  // @19_476100
  L47616f:;
  if (0) {} 
  L476171:;
  ecx = (u32)(EBP - 188);  // @22_476100
  eax = ext_4cd540_thiscall2(ecx, PV[1]);  // @23_476100
  ecx = edx = 0;  // @24_476100
  eax = (u32)(EBP - 188);  // @25_476100
  PV[2] = (u32)(eax);  // @26_476100
  ecx = (u32)(EBP - 16768);  // @27_476100
  eax = ext_4d3ab0_stdcall2((u32)(6854716), PV[2]);  // @28_476100
  ecx = edx = 0;  // @29_476100
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @30_476100
  ecx = (u32)(EBP - 16768);  // @31_476100
  eax = ext_4d3ab0_stdcall2((u32)(6854724), PV[3]);  // @32_476100
  ecx = edx = 0;  // @33_476100
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_476100
  eax = (u32)(EBP - 16768);  // @35_476100
  PV[4] = (u32)(eax);  // @36_476100
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338408), sizeof v); (u32)v; });  // @37_476100
  ecx = edi;  // @38_476100
  PV[5] = (u32)(eax);  // @39_476100
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, PV[5], PV[4]);  // @40_476100
  ecx = edx = 0;  // @41_476100
  ecx = (u32)(EBP - 188);  // @42_476100
  eax = ext_4ccf60_thiscall1(ecx);  // @43_476100
  ecx = edx = 0;  // @44_476100
  ecx = (u32)(EBP - 16768);  // @45_476100
  eax = ext_4d2330_thiscall1(ecx);  // @46_476100
  ecx = edx = 0;  // @47_476100
  SEH_LEAVE();  // @48_476100
  ext_633654(G(u32, 0x6f5630));  // @49_476100
  return eax;  // @50_476100
}
PCREG(476100, lifted_476100);

extern "C" u32 STDCALL lifted_48c300(u32 a0) {
  SEH_ENTER(0x667a38);  // @h_48c300
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = (u32)(EBP - 60);  // @0_48c300
  eax = ext_4ccb40_thiscall3(ecx, (u32)(32), (u32)(0));  // @1_48c300
  ecx = edx = 0;  // @2_48c300
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_48c300
  reg.state = (s32)((u32)(0));  // @4_48c300
  FL[2] = (ebx & ebx);  // @5_48c300
  if (FL[2] == 0) goto L48c408;  // @6_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_48c300
  ecx = (u32)(EBP - 24);  // @8_48c300
  PV[0] = (u32)(ecx);  // @9_48c300
  ecx = ebx;  // @10_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @11_48c300
  ecx = edx = 0;  // @12_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_48c300
  ecx = (u32)(EBP - 24);  // @14_48c300
  PV[1] = (u32)(ecx);  // @15_48c300
  ecx = ebx;  // @16_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @17_48c300
  ecx = edx = 0;  // @18_48c300
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @19_48c300
  if (FL[0] == FL[1]) goto L48c408;  // @20_48c300
  L48c370:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_48c300
  PV[2] = (u32)(eax);  // @23_48c300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @24_48c300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[2]);  // @26_48c300
  ecx = edx = 0;  // @27_48c300
  edi = eax;  // @28_48c300
  FL[2] = (edi & edi);  // @29_48c300
  if (FL[2] == 0) goto L48c3f3;  // @30_48c300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @31_48c300
  FL[2] = (ecx & ecx);  // @32_48c300
  if (FL[2] == 0) goto L48c397;  // @33_48c300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @34_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; });  // @35_48c300
  goto L48c39c;  // @36_48c300
  L48c397:;
  eax = (u32)(2097154);  // @38_48c300
  L48c39c:;
  FL[2] = (eax & (u32)(1048576));  // @40_48c300
  if (FL[2] != 0) goto L48c3af;  // @41_48c300
  ecx = edi;  // @42_48c300
  eax = ext_4da1d0_thiscall2(ecx, (u32)(0));  // @43_48c300
  ecx = edx = 0;  // @44_48c300
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @45_48c300
  L48c3af:;
  FL[2] = (edi & edi);  // @47_48c300
  if (FL[2] == 0) goto L48c3f3;  // @48_48c300
  L48c3b3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @50_48c300
  ecx = esi;  // @51_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_48c300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 680)))(ecx);  // @53_48c300
  ecx = edx = 0;  // @54_48c300
  FL[2] = (eax & (u32)(16384));  // @55_48c300
  if (FL[2] != 0) goto L48c3f3;  // @56_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_48c300
  ecx = esi;  // @58_48c300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 676)))(ecx, (u32)(16384), (u32)(0));  // @59_48c300
  ecx = edx = 0;  // @60_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_48c300
  ecx = esi;  // @62_48c300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 608)))(ecx);  // @63_48c300
  ecx = edx = 0;  // @64_48c300
  PV[3] = (u32)(eax);  // @65_48c300
  PV[4] = (u32)(esi);  // @66_48c300
  ecx = (u32)(EBP - 60);  // @67_48c300
  eax = ext_4cd6f0_thiscall3(ecx, PV[4], PV[3]);  // @68_48c300
  ecx = edx = 0;  // @69_48c300
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @70_48c300
  FL[2] = (edi & edi);  // @71_48c300
  if (FL[2] != 0) goto L48c3b3;  // @72_48c300
  L48c3f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_48c300
  ecx = (u32)(EBP - 24);  // @75_48c300
  PV[5] = (u32)(ecx);  // @76_48c300
  ecx = ebx;  // @77_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @78_48c300
  ecx = edx = 0;  // @79_48c300
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @80_48c300
  if (FL[0] != FL[1]) goto L48c370;  // @81_48c300
  L48c408:;
  ecx = (u32)(EBP - 60);  // @83_48c300
  eax = ext_4cf690_thiscall1(ecx);  // @84_48c300
  ecx = edx = 0;  // @85_48c300
  eax = (u32)(EBP - 24);  // @86_48c300
  PV[6] = (u32)(eax);  // @87_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @88_48c300
  ecx = (u32)(EBP - 60);  // @89_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[6]);  // @90_48c300
  ecx = edx = 0;  // @91_48c300
  eax = (u32)(EBP - 24);  // @92_48c300
  PV[7] = (u32)(eax);  // @93_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @94_48c300
  ecx = (u32)(EBP - 60);  // @95_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[7]);  // @96_48c300
  ecx = edx = 0;  // @97_48c300
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @98_48c300
  esi = eax;  // @99_48c300
  if (FL[0] == FL[1]) goto L48c45e;  // @100_48c300
  L48c432:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_48c300
  ecx = esi;  // @103_48c300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 0)))(ecx);  // @104_48c300
  ecx = edx = 0;  // @105_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_48c300
  ecx = esi;  // @107_48c300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 676)))(ecx, (u32)(0), (u32)(16384));  // @108_48c300
  ecx = edx = 0;  // @109_48c300
  eax = (u32)(EBP - 24);  // @110_48c300
  PV[8] = (u32)(eax);  // @111_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @112_48c300
  ecx = (u32)(EBP - 60);  // @113_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[8]);  // @114_48c300
  ecx = edx = 0;  // @115_48c300
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @116_48c300
  esi = eax;  // @117_48c300
  if (FL[0] != FL[1]) goto L48c432;  // @118_48c300
  L48c45e:;
  ecx = (u32)(EBP - 60);  // @120_48c300
  eax = ext_4ccef0_thiscall1(ecx);  // @121_48c300
  ecx = edx = 0;  // @122_48c300
  SEH_LEAVE();  // @123_48c300
  return eax;  // @124_48c300
}
PCREG(48c300, lifted_48c300);

