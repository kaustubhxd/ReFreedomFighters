// batch244023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_54f2b0_fastcall2(u32, u32) __asm__("ext_54f2b0");
extern "C" u32 THISCALL ext_440e10_thiscall2(u32, u32) __asm__("ext_440e10");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4f2610_thiscall1(u32) __asm__("ext_4f2610");
extern "C" u32 THISCALL ext_4f2be0_thiscall1(u32) __asm__("ext_4f2be0");
extern "C" u32 THISCALL ext_54d760_thiscall3(u32, u32, u32) __asm__("ext_54d760");
extern "C" u32 THISCALL ext_54e9d0_thiscall1(u32) __asm__("ext_54e9d0");
extern "C" u32 THISCALL ext_612900_thiscall2(u32, u32) __asm__("ext_612900");
extern "C" u32 THISCALL ext_612a20_thiscall2(u32, u32) __asm__("ext_612a20");
extern "C" u32 THISCALL ext_612c00_thiscall2(u32, u32) __asm__("ext_612c00");
extern "C" u32 THISCALL ext_6385c0_thiscall1(u32) __asm__("ext_6385c0");
extern "C" u32 THISCALL ext_649440_thiscall3(u32, u32, u32) __asm__("ext_649440");
extern "C" u32 THISCALL ext_64a410_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_64a410");
extern "C" u32 THISCALL ext_6528a0_thiscall1(u32) __asm__("ext_6528a0");
extern "C" u32 THISCALL ext_657da0_thiscall3(u32, u32, u32) __asm__("ext_657da0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d34_cdecl2(...) __asm__("ext_634d34");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4f2450(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f2450
  ebx = ecx;  // @1_4f2450
  PV[0] = (u32)(esi);  // @2_4f2450
  eax = ext_440e10_thiscall2(ecx, PV[0]);  // @3_4f2450
  ecx = edx = 0;  // @4_4f2450
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @5_4f2450
  if (FL[2] != 0) goto L4f246f;  // @6_4f2450
  return eax;  // @7_4f2450
  L4f246f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4f2450
  ecx = (u32)(EBP - 12);  // @10_4f2450
  PV[1] = (u32)(ecx);  // @11_4f2450
  ecx = esi;  // @12_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[1]);  // @13_4f2450
  ecx = edx = 0;  // @14_4f2450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_4f2450
  eax = (u32)(ebx + 115);  // @16_4f2450
  PV[2] = (u32)(eax);  // @17_4f2450
  ecx = esi;  // @18_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[2]);  // @19_4f2450
  ecx = edx = 0;  // @20_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_4f2450
  ecx = (u32)(EBP - 16);  // @22_4f2450
  PV[3] = (u32)(ecx);  // @23_4f2450
  ecx = esi;  // @24_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[3]);  // @25_4f2450
  ecx = edx = 0;  // @26_4f2450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4f2450
  eax = (u32)(ebx + 1531);  // @28_4f2450
  PV[4] = (u32)(eax);  // @29_4f2450
  ecx = esi;  // @30_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[4]);  // @31_4f2450
  ecx = edx = 0;  // @32_4f2450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4f2450
  eax = (u32)(ebx + 1532);  // @34_4f2450
  PV[5] = (u32)(eax);  // @35_4f2450
  ecx = esi;  // @36_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[5]);  // @37_4f2450
  ecx = edx = 0;  // @38_4f2450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_4f2450
  eax = (u32)(ebx + 1530);  // @40_4f2450
  PV[6] = (u32)(eax);  // @41_4f2450
  ecx = esi;  // @42_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[6]);  // @43_4f2450
  ecx = edx = 0;  // @44_4f2450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @45_4f2450
  eax = (u32)(ebx + 151);  // @46_4f2450
  PV[7] = (u32)(eax);  // @47_4f2450
  ecx = esi;  // @48_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[7]);  // @49_4f2450
  ecx = edx = 0;  // @50_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_4f2450
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @52_4f2450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[8]);  // @55_4f2450
  ecx = edx = 0;  // @56_4f2450
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @57_4f2450
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 111), &v, sizeof v); }  // @58_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_4f2450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @62_4f2450
  ecx = edx = 0;  // @63_4f2450
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 475), &v, sizeof v); }  // @64_4f2450
  ecx = (u32)(ebx + 423);  // @65_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 423), sizeof v); (u32)v; });  // @66_4f2450
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @67_4f2450
  ecx = edx = 0;  // @68_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 203), sizeof v); (u32)v; });  // @69_4f2450
  ecx = (u32)(ebx + 203);  // @70_4f2450
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @71_4f2450
  ecx = edx = 0;  // @72_4f2450
  ecx = ebx;  // @73_4f2450
  ecx = (ecx + (u32)(159));  // @74_4f2450
  FL[3] = ecx;  // @75_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_4f2450
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @77_4f2450
  ecx = edx = 0;  // @78_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_4f2450
  ecx = (u32)(EBP + 8);  // @80_4f2450
  PV[10] = (u32)(ecx);  // @81_4f2450
  ecx = esi;  // @82_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[10]);  // @83_4f2450
  ecx = edx = 0;  // @84_4f2450
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @85_4f2450
  if ((s32)FL[0] <= (s32)FL[1]) goto L4f255c;  // @86_4f2450
  L4f2534:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_4f2450
  ecx = (u32)(EBP - 4);  // @89_4f2450
  PV[11] = (u32)(ecx);  // @90_4f2450
  ecx = esi;  // @91_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[11]);  // @92_4f2450
  ecx = edx = 0;  // @93_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 423), sizeof v); (u32)v; });  // @94_4f2450
  ecx = (u32)(ebx + 423);  // @95_4f2450
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @96_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[12]);  // @97_4f2450
  ecx = edx = 0;  // @98_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @99_4f2450
  eax = (eax - 1);  // @100_4f2450
  FL[3] = eax;  // @101_4f2450
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @102_4f2450
  FL[2] = (eax & eax);  // @103_4f2450
  if ((s32)FL[2] > 0) goto L4f2534;  // @104_4f2450
  L4f255c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_4f2450
  ecx = (u32)(EBP + 8);  // @107_4f2450
  PV[13] = (u32)(ecx);  // @108_4f2450
  ecx = esi;  // @109_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[13]);  // @110_4f2450
  ecx = edx = 0;  // @111_4f2450
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @112_4f2450
  if ((s32)FL[0] <= (s32)FL[1]) goto L4f2598;  // @113_4f2450
  L4f2570:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_4f2450
  ecx = (u32)(EBP - 4);  // @116_4f2450
  PV[14] = (u32)(ecx);  // @117_4f2450
  ecx = esi;  // @118_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[14]);  // @119_4f2450
  ecx = edx = 0;  // @120_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 203), sizeof v); (u32)v; });  // @121_4f2450
  ecx = (u32)(ebx + 203);  // @122_4f2450
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @123_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[15]);  // @124_4f2450
  ecx = edx = 0;  // @125_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @126_4f2450
  eax = (eax - 1);  // @127_4f2450
  FL[3] = eax;  // @128_4f2450
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @129_4f2450
  FL[2] = (eax & eax);  // @130_4f2450
  if ((s32)FL[2] > 0) goto L4f2570;  // @131_4f2450
  L4f2598:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @133_4f2450
  ecx = (u32)(EBP + 8);  // @134_4f2450
  PV[16] = (u32)(ecx);  // @135_4f2450
  ecx = esi;  // @136_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[16]);  // @137_4f2450
  ecx = edx = 0;  // @138_4f2450
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @139_4f2450
  if ((s32)FL[0] <= (s32)FL[1]) goto L4f25f9;  // @140_4f2450
  edi = ebx;  // @141_4f2450
  L4f25b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @143_4f2450
  ecx = (u32)(EBP - 4);  // @144_4f2450
  PV[17] = (u32)(ecx);  // @145_4f2450
  ecx = esi;  // @146_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[17]);  // @147_4f2450
  ecx = edx = 0;  // @148_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @149_4f2450
  ecx = (u32)(EBP - 20);  // @150_4f2450
  PV[18] = (u32)(ecx);  // @151_4f2450
  ecx = esi;  // @152_4f2450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[18]);  // @153_4f2450
  ecx = edx = 0;  // @154_4f2450
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @155_4f2450
  X0[1] = 0;  // @156_4f2450
  X0[2] = 0;  // @157_4f2450
  X0[3] = 0;  // @158_4f2450
  ecx = (u32)(edi + 159);  // @159_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_4f2450
  PV[19] = (u32)(ecx);  // @161_4f2450
  PV[20] = X0[0];  // @162_4f2450
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @163_4f2450
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[21], PV[20], (u32)(0));  // @164_4f2450
  ecx = edx = 0;  // @165_4f2450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @166_4f2450
  ecx = esi;  // @167_4f2450
  PV[22] = (u32)(eax);  // @168_4f2450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[22], (u32)(13));  // @169_4f2450
  ecx = edx = 0;  // @170_4f2450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @171_4f2450
  eax = (eax - 1);  // @172_4f2450
  FL[3] = eax;  // @173_4f2450
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @174_4f2450
  FL[2] = (eax & eax);  // @175_4f2450
  if ((s32)FL[2] > 0) goto L4f25b0;  // @176_4f2450
  L4f25f9:;
  ecx = ebx;  // @178_4f2450
  eax = ext_4f2610_thiscall1(ecx);  // @179_4f2450
  ecx = edx = 0;  // @180_4f2450
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @181_4f2450
  return eax;  // @182_4f2450
}
PCREG(4f2450, lifted_4f2450);

extern "C" u32 THISCALL lifted_6515d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ecee);  // @h_6515d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_6515d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6515d0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6515d0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_6515d0
  eax = ext_657da0_thiscall3(ecx, PV[1], PV[0]);  // @4_6515d0
  ecx = edx = 0;  // @5_6515d0
  { u32 v = (u32)((u32)(7091948)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_6515d0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4757), &v, sizeof v); }  // @7_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 311), &v, sizeof v); }  // @8_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_6515d0
  reg.state = (s32)((u32)(0));  // @10_6515d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @11_6515d0
  if (FL[0] == FL[1]) goto L65163d;  // @12_6515d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @13_6515d0
  if (FL[0] != FL[1]) goto L6516e8;  // @14_6515d0
  L65163d:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676240))();  // @16_6515d0
  ecx = edx = 0;  // @17_6515d0
  PV[2] = (u32)(eax);  // @18_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @19_6515d0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6761f8))(PV[2]);  // @20_6515d0
  ecx = edx = 0;  // @21_6515d0
  ebx = eax;  // @22_6515d0
  PV[3] = (u32)(ebx);  // @23_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676038))(PV[3], (u32)(14));  // @24_6515d0
  ecx = edx = 0;  // @25_6515d0
  PV[4] = (u32)(ebx);  // @26_6515d0
  edi = eax;  // @27_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676038))(PV[4], (u32)(12));  // @28_6515d0
  ecx = edx = 0;  // @29_6515d0
  PV[5] = (u32)(ebx);  // @30_6515d0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_6515d0
  edi = (u32)((s32)edi * (s32)eax);  // @32_6515d0
  FL[3] = edi;  // @33_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67620c))(PV[6], PV[5]);  // @34_6515d0
  ecx = edx = 0;  // @35_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_6515d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 127), &v, sizeof v); }  // @37_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_6515d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }); FL[1] = (u32)(16);  // @39_6515d0
  if ((s32)FL[0] >= (s32)FL[1]) goto L6516a1;  // @40_6515d0
  eax = (u32)(EBP - 24);  // @41_6515d0
  { u32 v = (u32)((u32)(7092880)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @42_6515d0
  PV[7] = (u32)(eax);  // @43_6515d0
  { u32 v = (u32)((u32)(7092792)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @44_6515d0
  eax = ext_634d34_cdecl2(PV[7], (u32)(7197212));  // @45_6515d0
    // @46_6515d0
  L6516a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @48_6515d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 118), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @49_6515d0
  if (FL[0] == FL[1]) goto L6516df;  // @50_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @51_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_6515d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7092888), (u32)(455));  // @53_6515d0
  ecx = edx = 0;  // @54_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_6515d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_6515d0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; });  // @57_6515d0
  PV[9] = (u32)(eax);  // @58_6515d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[9], (u32)(7092940), PV[8]);  // @59_6515d0
  ecx = edx = 0;  // @60_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_6515d0
  L6516df:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_6515d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @64_6515d0
  if (FL[0] == FL[1]) goto L651701;  // @65_6515d0
  L6516e8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @67_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 139), &v, sizeof v); }  // @69_6515d0
  L651701:;
  { u32 v = (u32)((u32)(40000)); __builtin_memcpy((void *)(u32)(ebx + 4745), &v, sizeof v); }  // @71_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4585), &v, sizeof v); }  // @72_6515d0
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 4583), &v, sizeof v); }  // @73_6515d0
  eax = ((u32( *)(void))(*(u32 *)0x676234))();  // @74_6515d0
  ecx = edx = 0;  // @75_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 303), sizeof v); (u32)v; });  // @76_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4593), &v, sizeof v); }  // @77_6515d0
  eax = ext_6528a0_thiscall1(ecx);  // @78_6515d0
  ecx = edx = 0;  // @79_6515d0
  eax = (u32)(ebx + 4613);  // @80_6515d0
  PV[10] = (u32)(eax);  // @81_6515d0
  eax = ext_634d10_cdecl3(PV[10], (u32)(0), (u32)(128));  // @82_6515d0
    // @83_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4741), &v, sizeof v); }  // @84_6515d0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx + 4749), &v, sizeof v); }  // @85_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @86_6515d0
  ecx = edx = 0;  // @87_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @88_6515d0
  reg.state = (s32)((u32)(1));  // @89_6515d0
  FL[2] = (eax & eax);  // @90_6515d0
  if (FL[2] == 0) goto L65178b;  // @91_6515d0
  ecx = eax;  // @92_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092956), (u32)(0), (u32)(7493664));  // @93_6515d0
  ecx = edx = 0;  // @94_6515d0
  edx = eax;  // @95_6515d0
  goto L65178d;  // @96_6515d0
  L65178b:;
  edx = 0;  // @98_6515d0
  FL[3] = edx;  // @99_6515d0
  L65178d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4759), &v, sizeof v); }  // @101_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_6515d0
  PV[11] = (u32)(edx);  // @103_6515d0
  reg.state = (s32)((u32)(0));  // @104_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[11]);  // @106_6515d0
  ecx = edx = 0;  // @107_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @108_6515d0
  ecx = edx = 0;  // @109_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @110_6515d0
  reg.state = (s32)((u32)(2));  // @111_6515d0
  FL[2] = (eax & eax);  // @112_6515d0
  if (FL[2] == 0) goto L6517d5;  // @113_6515d0
  ecx = eax;  // @114_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092980), (u32)(0), (u32)(7298720));  // @115_6515d0
  ecx = edx = 0;  // @116_6515d0
  edx = eax;  // @117_6515d0
  goto L6517d7;  // @118_6515d0
  L6517d5:;
  edx = 0;  // @120_6515d0
  FL[3] = edx;  // @121_6515d0
  L6517d7:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4763), &v, sizeof v); }  // @123_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_6515d0
  PV[12] = (u32)(edx);  // @125_6515d0
  reg.state = (s32)((u32)(0));  // @126_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[12]);  // @128_6515d0
  ecx = edx = 0;  // @129_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @130_6515d0
  ecx = edx = 0;  // @131_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @132_6515d0
  reg.state = (s32)((u32)(3));  // @133_6515d0
  FL[2] = (eax & eax);  // @134_6515d0
  if (FL[2] == 0) goto L65181f;  // @135_6515d0
  ecx = eax;  // @136_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092992), (u32)(0), (u32)(7298724));  // @137_6515d0
  ecx = edx = 0;  // @138_6515d0
  edx = eax;  // @139_6515d0
  goto L651821;  // @140_6515d0
  L65181f:;
  edx = 0;  // @142_6515d0
  FL[3] = edx;  // @143_6515d0
  L651821:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4767), &v, sizeof v); }  // @145_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_6515d0
  PV[13] = (u32)(edx);  // @147_6515d0
  reg.state = (s32)((u32)(0));  // @148_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[13]);  // @150_6515d0
  ecx = edx = 0;  // @151_6515d0
  eax = ebx;  // @152_6515d0
  SEH_LEAVE();  // @153_6515d0
  return eax;  // @154_6515d0
}
PCREG(6515d0, lifted_6515d0);

extern "C" u32 THISCALL lifted_54afd0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ac9f);  // @h_54afd0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_54afd0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_54afd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_54afd0
  PV[1] = (u32)(esi);  // @3_54afd0
  eax = ext_54d760_thiscall3(ecx, PV[1], PV[0]);  // @4_54afd0
  ecx = edx = 0;  // @5_54afd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @6_54afd0
  eax = 0;  // @7_54afd0
  FL[3] = eax;  // @8_54afd0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @9_54afd0
  X0[0] = 0;  // @10_54afd0
  X0[1] = 0;  // @11_54afd0
  X0[2] = 0;  // @12_54afd0
  X0[3] = 0;  // @13_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @14_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 4), &X0[1], 4);  // @15_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 8), &X0[2], 4);  // @16_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 12), &X0[3], 4);  // @17_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @18_54afd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25563), &v, sizeof v); }  // @19_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25564), &v, sizeof v); }  // @20_54afd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 93), &v, sizeof v); }  // @21_54afd0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; })) & 0xffff);  // @22_54afd0
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + (eax & 0xffff))) & 0xffff);  // @23_54afd0
  FL[3] = (eax & 0xffff);  // @24_54afd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 73), &v, sizeof v); }  // @25_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @26_54afd0
  eax = (eax & 0xffff);  // @27_54afd0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));  // @28_54afd0
  FL[3] = eax;  // @29_54afd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 74), &v, sizeof v); }  // @30_54afd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @31_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @32_54afd0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @33_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 34), &v, sizeof v); }  // @34_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @35_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @36_54afd0
  eax = (u32)(16);  // @37_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 22), &v, sizeof v); }  // @38_54afd0
  eax = (u32)(1);  // @39_54afd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @40_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @41_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 4), &X0[1], 4);  // @42_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 8), &X0[2], 4);  // @43_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 12), &X0[3], 4);  // @44_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @45_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 0), &X0[0], 4);  // @46_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 4), &X0[1], 4);  // @47_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 8), &X0[2], 4);  // @48_54afd0
  __builtin_memcpy((void *)((u32)(EBP - 56) + 12), &X0[3], 4);  // @49_54afd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 41596), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @50_54afd0
  if (FL[0] == FL[1]) goto L54b09a;  // @51_54afd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 117), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @52_54afd0
  if (FL[0] == FL[1]) goto L54b09a;  // @53_54afd0
  ecx = (u32)(164);  // @54_54afd0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 74), &v, sizeof v); }  // @55_54afd0
  goto L54b09f;  // @56_54afd0
  L54b09a:;
  ecx = (u32)(160);  // @58_54afd0
  L54b09f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 57), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @60_54afd0
  eax = (u32)(65600);  // @61_54afd0
  esi = (u32)(196624);  // @62_54afd0
  { u32 v = (u32)((u32)(36)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @63_54afd0
  if (FL[0] == FL[1]) eax = esi;  // @64_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @65_54afd0
  ecx = (ecx | eax);  // @66_54afd0
  FL[3] = ecx;  // @67_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @68_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @69_54afd0
  eax = (u32)(EBP - 36);  // @70_54afd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @71_54afd0
  ecx = edx;  // @72_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @73_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @74_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 200), sizeof v); (u32)v; });  // @75_54afd0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @76_54afd0
  ecx = edx = 0;  // @77_54afd0
  esi = (u32)(edi + 25580);  // @78_54afd0
  PV[2] = (u32)(esi);  // @79_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @80_54afd0
  edx = (u32)(EBP - 72);  // @81_54afd0
  PV[3] = (u32)(edx);  // @82_54afd0
  PV[4] = (u32)(eax);  // @83_54afd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 12)))(ecx, PV[4], PV[3], PV[2], (u32)(0));  // @84_54afd0
  ecx = edx = 0;  // @85_54afd0
  FL[2] = (eax & eax);  // @86_54afd0
  if (FL[2] == 0) goto L54b105;  // @87_54afd0
  edx = (u32)(6961276);  // @88_54afd0
  ecx = eax;  // @89_54afd0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @90_54afd0
  ecx = edx = 0;  // @91_54afd0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @92_54afd0
  FL[3] = (eax & 0xff);  // @93_54afd0
  goto L54b1cc;  // @94_54afd0
  L54b105:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 57), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @96_54afd0
  if (FL[0] != FL[1]) goto L54b14b;  // @97_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_54afd0
  eax = (u32)(edi + 25584);  // @99_54afd0
  PV[5] = (u32)(eax);  // @100_54afd0
  PV[6] = (u32)(ecx);  // @101_54afd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_54afd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 73), &v, sizeof v); }  // @103_54afd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, PV[6], (u32)(7070112), PV[5]);  // @104_54afd0
  ecx = edx = 0;  // @105_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @106_54afd0
  FL[2] = (eax & eax);  // @107_54afd0
  if (FL[2] == 0) goto L54b14b;  // @108_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @109_54afd0
  PV[7] = (u32)(ecx);  // @110_54afd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_54afd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 8)))(ecx, PV[7]);  // @112_54afd0
  ecx = edx = 0;  // @113_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @114_54afd0
  edx = (u32)(6961300);  // @115_54afd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @116_54afd0
  eax = ext_54f2b0_fastcall2(ecx, edx);  // @117_54afd0
  ecx = edx = 0;  // @118_54afd0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @119_54afd0
  FL[3] = (eax & 0xff);  // @120_54afd0
  goto L54b1cc;  // @121_54afd0
  L54b14b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @123_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 204), sizeof v); (u32)v; });  // @125_54afd0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @126_54afd0
  ecx = edx = 0;  // @127_54afd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @128_54afd0
  if (FL[2] == 0) goto L54b1ca;  // @129_54afd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 73), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @130_54afd0
  if (FL[0] == FL[1]) goto L54b1ca;  // @131_54afd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 74), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @132_54afd0
  if (FL[0] == FL[1]) goto L54b1ca;  // @133_54afd0
  eax = ext_41e290_cdecl1((u32)(80));  // @134_54afd0
  ecx = edx = 0;  // @135_54afd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @136_54afd0
  reg.state = (s32)((u32)(0));  // @137_54afd0
  FL[2] = (eax & eax);  // @138_54afd0
  if (FL[2] == 0) goto L54b18b;  // @139_54afd0
  ecx = eax;  // @140_54afd0
  eax = ext_54e9d0_thiscall1(ecx);  // @141_54afd0
  ecx = edx = 0;  // @142_54afd0
  ecx = eax;  // @143_54afd0
  goto L54b18d;  // @144_54afd0
  L54b18b:;
  ecx = 0;  // @146_54afd0
  FL[3] = ecx;  // @147_54afd0
  L54b18d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 25588), &v, sizeof v); }  // @149_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_54afd0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_54afd0
  reg.state = (s32)((u32)(4294967295));  // @152_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @153_54afd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[8], (u32)(1));  // @154_54afd0
  ecx = edx = 0;  // @155_54afd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25588), sizeof v); (u32)v; });  // @156_54afd0
  FL[2] = (eax & eax);  // @157_54afd0
  if (FL[2] != 0) goto L54b1c5;  // @158_54afd0
  FL[2] = (ecx & ecx);  // @159_54afd0
  if (FL[2] == 0) goto L54b1b9;  // @160_54afd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_54afd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @162_54afd0
  ecx = edx = 0;  // @163_54afd0
  L54b1b9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 25588), &v, sizeof v); }  // @165_54afd0
  goto L54b1ca;  // @166_54afd0
  L54b1c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @168_54afd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @169_54afd0
  ecx = edx = 0;  // @170_54afd0
  L54b1ca:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @172_54afd0
  L54b1cc:;
  SEH_LEAVE();  // @174_54afd0
  ext_633654(G(u32, 0x6f5630));  // @175_54afd0
  return eax;  // @176_54afd0
}
PCREG(54afd0, lifted_54afd0);

extern "C" u32 THISCALL lifted_6130c0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6130c0
  esi = ecx;  // @1_6130c0
  ecx = ebx;  // @2_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 80)))(ecx);  // @4_6130c0
  ecx = edx = 0;  // @5_6130c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_6130c0
  ecx = ebx;  // @7_6130c0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @8_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 48)))(ecx);  // @10_6130c0
  ecx = edx = 0;  // @11_6130c0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 2), &v, sizeof v); }  // @12_6130c0
  ecx = ebx;  // @13_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @15_6130c0
  ecx = edx = 0;  // @16_6130c0
  edx = eax;  // @17_6130c0
  ecx = (u32)(eax + 1);  // @18_6130c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_6130c0
  L6130f1:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @21_6130c0
  eax = (eax + 1);  // @22_6130c0
  FL[3] = eax;  // @23_6130c0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @24_6130c0
  if (FL[2] != 0) goto L6130f1;  // @25_6130c0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @26_6130c0
  FL[3] = eax;  // @27_6130c0
  eax = (eax + 1);  // @28_6130c0
  FL[3] = eax;  // @29_6130c0
  FL[0] = eax; FL[1] = (u32)(24);  // @30_6130c0
  if (FL[0] <= FL[1]) goto L61311f;  // @31_6130c0
  ecx = edx;  // @32_6130c0
  eax = (u32)(ecx + 1);  // @33_6130c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @34_6130c0
  L613110:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @36_6130c0
  ecx = (ecx + 1);  // @37_6130c0
  FL[3] = ecx;  // @38_6130c0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @39_6130c0
  if (FL[2] != 0) goto L613110;  // @40_6130c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @41_6130c0
  FL[3] = ecx;  // @42_6130c0
  edx = (edx + (u32)(-23));  // @43_6130c0
  FL[3] = edx;  // @44_6130c0
  edx = (edx + ecx);  // @45_6130c0
  FL[3] = edx;  // @46_6130c0
  L61311f:;
  PV[0] = (u32)(edx);  // @48_6130c0
  eax = (u32)(edi + 32);  // @49_6130c0
  PV[1] = (u32)(eax);  // @50_6130c0
  eax = ((u32(*)(u32, u32, u32))(*(u32 *)0x67642c))(PV[1], PV[0], (u32)(24));  /* strncpy is cdecl */  // @51_6130c0
  ecx = edx = 0;  // @52_6130c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 55), &v, sizeof v); }  // @53_6130c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @54_6130c0
  ecx = ebx;  // @55_6130c0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @56_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 28)))(ecx);  // @58_6130c0
  ecx = edx = 0;  // @59_6130c0
  X0[0] = 0;  // @60_6130c0
  X0[1] = 0;  // @61_6130c0
  X0[2] = 0;  // @62_6130c0
  X0[3] = 0;  // @63_6130c0
  ecx = ebx;  // @64_6130c0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @65_6130c0
  X1[0] = F2U((float)(s32)X1[0]);  // @66_6130c0
  X1[1] = F2U((float)(s32)X1[1]);  // @67_6130c0
  X1[2] = F2U((float)(s32)X1[2]);  // @68_6130c0
  X1[3] = F2U((float)(s32)X1[3]);  // @69_6130c0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @70_6130c0
  __builtin_memcpy((void *)((u32)(edi + 16) + 0), &X0[0], 4);  // @71_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @72_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @73_6130c0
  ecx = edx = 0;  // @74_6130c0
  X1[0] = 0;  // @75_6130c0
  X1[1] = 0;  // @76_6130c0
  X1[2] = 0;  // @77_6130c0
  X1[3] = 0;  // @78_6130c0
  ecx = ebx;  // @79_6130c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @80_6130c0
  X0[0] = F2U((float)(s32)X0[0]);  // @81_6130c0
  X0[1] = F2U((float)(s32)X0[1]);  // @82_6130c0
  X0[2] = F2U((float)(s32)X0[2]);  // @83_6130c0
  X0[3] = F2U((float)(s32)X0[3]);  // @84_6130c0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @85_6130c0
  __builtin_memcpy((void *)((u32)(edi + 20) + 0), &X1[0], 4);  // @86_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 28)))(ecx);  // @88_6130c0
  ecx = edx = 0;  // @89_6130c0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @90_6130c0
  ecx = ebx;  // @91_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @92_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @93_6130c0
  ecx = edx = 0;  // @94_6130c0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @95_6130c0
  ecx = ebx;  // @96_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @97_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @98_6130c0
  ecx = edx = 0;  // @99_6130c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @100_6130c0
  ecx = ebx;  // @101_6130c0
  edi = eax;  // @102_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 72)))(ecx);  // @103_6130c0
  ecx = edx = 0;  // @104_6130c0
  FL[2] = ((eax & 0xff) & (u32)(16));  // @105_6130c0
  if (FL[2] != 0) goto L613257;  // @106_6130c0
  FL[0] = edi; FL[1] = (u32)(1162691149);  // @107_6130c0
  if (FL[0] > FL[1]) goto L613204;  // @108_6130c0
  if (FL[0] == FL[1]) goto L613257;  // @109_6130c0
  edi = (edi - (u32)(1146639409));  // @110_6130c0
  FL[3] = edi;  // @111_6130c0
  if (FL[3] == 0) goto L6131f8;  // @112_6130c0
  edi = (edi - (u32)(2));  // @113_6130c0
  FL[3] = edi;  // @114_6130c0
  if (FL[3] != 0) goto L613214;  // @115_6130c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139280), sizeof v); (u32)v; }); FL[1] = (u32)(861165636);  // @116_6130c0
  L6131c8:;
  if (FL[0] != FL[1]) goto L613286;  // @118_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @119_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @120_6130c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @121_6130c0
  if (FL[0] != FL[1]) goto L613286;  // @122_6130c0
  PV[2] = (u32)(ebx);  // @123_6130c0
  ecx = esi;  // @124_6130c0
  eax = ext_612900_thiscall2(ecx, PV[2]);  // @125_6130c0
  ecx = edx = 0;  // @126_6130c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @127_6130c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 56), &v, sizeof v); }  // @128_6130c0
  return eax;  // @129_6130c0
  L6131f8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139272), sizeof v); (u32)v; }); FL[1] = (u32)(827611204);  // @131_6130c0
  goto L6131c8;  // @132_6130c0
  L613204:;
  FL[0] = edi; FL[1] = (u32)(1346456654);  // @134_6130c0
  if (FL[0] == FL[1]) goto L613286;  // @135_6130c0
  FL[0] = edi; FL[1] = (u32)(1380401729);  // @136_6130c0
  if (FL[0] == FL[1]) goto L613286;  // @137_6130c0
  L613214:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @139_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_6130c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7067680), (u32)(746));  // @141_6130c0
  ecx = edx = 0;  // @142_6130c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @143_6130c0
  esi = eax;  // @144_6130c0
  ecx = ebx;  // @145_6130c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @147_6130c0
  ecx = edx = 0;  // @148_6130c0
  ecx = eax;  // @149_6130c0
  eax = ext_6385c0_thiscall1(ecx);  // @150_6130c0
  ecx = edx = 0;  // @151_6130c0
  PV[3] = (u32)(eax);  // @152_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @153_6130c0
  ecx = ebx;  // @154_6130c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 4)))(ecx);  // @155_6130c0 (w4c: PV[3] is the pending cdecl argument, not an argument of slot 4)
  ecx = edx = 0;  // @156_6130c0
  PV[4] = (u32)(eax);  // @157_6130c0
  PV[5] = (u32)(esi);  // @158_6130c0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[5], (u32)(7067748), PV[4], PV[3]);  /* cdecl, 4 stack arguments */  // @159_6130c0
  ecx = edx = 0;  // @160_6130c0
  return eax;  // @161_6130c0
  L613257:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139312), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @163_6130c0
  if (FL[0] == FL[1]) goto L613286;  // @164_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @165_6130c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @166_6130c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @167_6130c0
  if (FL[0] != FL[1]) goto L613286;  // @168_6130c0
  PV[6] = (u32)(ebx);  // @169_6130c0
  ecx = esi;  // @170_6130c0
  eax = ext_612a20_thiscall2(ecx, PV[6]);  // @171_6130c0
  ecx = edx = 0;  // @172_6130c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @173_6130c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 56), &v, sizeof v); }  // @174_6130c0
  return eax;  // @175_6130c0
  L613286:;
  PV[7] = (u32)(ebx);  // @177_6130c0
  ecx = esi;  // @178_6130c0
  eax = ext_612c00_thiscall2(ecx, PV[7]);  // @179_6130c0
  ecx = edx = 0;  // @180_6130c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @181_6130c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 56), &v, sizeof v); }  // @182_6130c0
  return eax;  // @183_6130c0
}
PCREG(6130c0, lifted_6130c0);

extern "C" u32 THISCALL lifted_64cdc0(u32 ecx_in, u32 a0) {
  u8 F[0x5f0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x4f0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x4f0 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1048), &v, sizeof v); }  // @1_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @2_64cdc0
  ebx = ecx;  // @3_64cdc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @4_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_64cdc0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @6_64cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_64cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @9_64cdc0
  ecx = edx = 0;  // @10_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_64cdc0
  edx = (u32)(EBP - 16);  // @12_64cdc0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @13_64cdc0
  edi = (u32)(ebx + 98809);  // @14_64cdc0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @15_64cdc0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @16_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @17_64cdc0
  PV[1] = (u32)(edx);  // @18_64cdc0
  edx = (u32)(ebx + 98845);  // @19_64cdc0
  PV[2] = (u32)(edx);  // @20_64cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @21_64cdc0
  edx = (u32)(EBP - 16);  // @22_64cdc0
  PV[3] = (u32)(edi);  // @23_64cdc0
  PV[4] = (u32)(edx);  // @24_64cdc0
  edx = (u32)(EBP - 1040);  // @25_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_64cdc0
  PV[5] = (u32)(edx);  // @27_64cdc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, PV[5], PV[4], PV[3], PV[2], PV[1]);  // @28_64cdc0
  ecx = edx = 0;  // @29_64cdc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_64cdc0
  edi = eax;  // @31_64cdc0
  PV[6] = (u32)(edi);  // @32_64cdc0
  eax = (u32)(EBP - 1040);  // @33_64cdc0
  ecx = esi;  // @34_64cdc0
  PV[7] = (u32)(eax);  // @35_64cdc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 564)))(ecx, PV[7], PV[6]);  // @36_64cdc0
  ecx = edx = 0;  // @37_64cdc0
  PV[8] = (u32)(esi);  // @38_64cdc0
  eax = (u32)(EBP - 1120);  // @39_64cdc0
  ecx = ebx;  // @40_64cdc0
  PV[9] = (u32)(eax);  // @41_64cdc0
  eax = ext_649440_thiscall3(ecx, PV[9], PV[8]);  // @42_64cdc0
  ecx = edx = 0;  // @43_64cdc0
  eax = 0;  // @44_64cdc0
  FL[3] = eax;  // @45_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1044), &v, sizeof v); }  // @46_64cdc0
  FL[2] = (edi & edi);  // @47_64cdc0
  if (FL[2] == 0) goto L64cecb;  // @48_64cdc0
  L64ce70:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax*4 - 1040), sizeof v); (u32)v; });  // @50_64cdc0
  ecx = ebx;  // @51_64cdc0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1048), sizeof v); (u32)v; });  // @52_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @53_64cdc0
  PV[11] = (u32)(esi);  // @54_64cdc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[11], PV[10]);  // @55_64cdc0
  ecx = edx = 0;  // @56_64cdc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 135), &v, sizeof v); }  // @57_64cdc0
  ecx = ebx;  // @58_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @59_64cdc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_64cdc0
  PV[12] = (u32)(eax);  // @61_64cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[12]);  // @62_64cdc0
  ecx = edx = 0;  // @63_64cdc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1120) + 0), 4); v; });  // @64_64cdc0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1120) + 4), 4); v; });  // @65_64cdc0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1120) + 8), 4); v; });  // @66_64cdc0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1120) + 12), 4); v; });  // @67_64cdc0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @68_64cdc0
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @69_64cdc0
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @70_64cdc0
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @71_64cdc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1104) + 0), 4); v; });  // @72_64cdc0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1104) + 4), 4); v; });  // @73_64cdc0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1104) + 8), 4); v; });  // @74_64cdc0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1104) + 12), 4); v; });  // @75_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 16) + 0), &X0[0], 4);  // @76_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 16) + 4), &X0[1], 4);  // @77_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 16) + 8), &X0[2], 4);  // @78_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 16) + 12), &X0[3], 4);  // @79_64cdc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1088) + 0), 4); v; });  // @80_64cdc0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1088) + 4), 4); v; });  // @81_64cdc0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1088) + 8), 4); v; });  // @82_64cdc0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 1088) + 12), 4); v; });  // @83_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 32) + 0), &X0[0], 4);  // @84_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 32) + 4), &X0[1], 4);  // @85_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 32) + 8), &X0[2], 4);  // @86_64cdc0
  __builtin_memcpy((void *)((u32)(eax + 32) + 12), &X0[3], 4);  // @87_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1044), sizeof v); (u32)v; });  // @88_64cdc0
  eax = (eax + 1);  // @89_64cdc0
  FL[3] = eax;  // @90_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1044), &v, sizeof v); }  // @91_64cdc0
  FL[0] = eax; FL[1] = edi;  // @92_64cdc0
  if (FL[0] != FL[1]) goto L64ce70;  // @93_64cdc0
  L64cecb:;
  esi = 0;  // @95_64cdc0
  FL[3] = esi;  // @96_64cdc0
  FL[2] = (edi & edi);  // @97_64cdc0
  if (FL[2] == 0) goto L64cf02;  // @98_64cdc0
  L64ced1:;
  eax = (u32)(ebx + 98845);  // @100_64cdc0
  ecx = ebx;  // @101_64cdc0
  PV[13] = (u32)(eax);  // @102_64cdc0
  eax = (u32)(ebx + 98809);  // @103_64cdc0
  PV[14] = (u32)(eax);  // @104_64cdc0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1048), sizeof v); (u32)v; });  // @105_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 1040), sizeof v); (u32)v; });  // @106_64cdc0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 136), sizeof v); (u32)v; });  // @107_64cdc0
  eax = ext_64a410_thiscall7(ecx, PV[16], (u32)(0), PV[15], PV[14], PV[13], (u32)(1));  // @108_64cdc0
  ecx = edx = 0;  // @109_64cdc0
  esi = (esi + 1);  // @110_64cdc0
  FL[3] = esi;  // @111_64cdc0
  FL[0] = esi; FL[1] = edi;  // @112_64cdc0
  if (FL[0] != FL[1]) goto L64ced1;  // @113_64cdc0
  L64cf02:;
  ecx = 0;  // @115_64cdc0
  FL[3] = ecx;  // @116_64cdc0
  FL[2] = (edi & edi);  // @117_64cdc0
  if (FL[2] == 0) goto L64cf36;  // @118_64cdc0
  L64cf10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx*4 - 1040), sizeof v); (u32)v; });  // @120_64cdc0
  edx = 0;  // @121_64cdc0
  FL[3] = edx;  // @122_64cdc0
  ecx = (ecx + 1);  // @123_64cdc0
  FL[3] = ecx;  // @124_64cdc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 135), &v, sizeof v); }  // @125_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 136), sizeof v); (u32)v; });  // @126_64cdc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @127_64cdc0
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 30), &v, sizeof v); }  // @128_64cdc0
  FL[0] = ecx; FL[1] = edi;  // @129_64cdc0
  if (FL[0] != FL[1]) goto L64cf10;  // @130_64cdc0
  L64cf36:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @132_64cdc0
  ecx = (u32)(ebx + 12);  // @133_64cdc0
  edx = (u32)(EBP - 1072);  // @134_64cdc0
  PV[17] = (u32)(edx);  // @135_64cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[17]);  // @136_64cdc0
  ecx = edx = 0;  // @137_64cdc0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @138_64cdc0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 4), 4); v; });  // @139_64cdc0
  X0[2] = 0;  // @140_64cdc0
  X0[3] = 0;  // @141_64cdc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @142_64cdc0
  __builtin_memcpy((void *)((u32)(EBP - 1060) + 0), &X0[0], 4);  // @143_64cdc0
  __builtin_memcpy((void *)((u32)(EBP - 1060) + 4), &X0[1], 4);  // @144_64cdc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1060), sizeof v); (u32)v; });  // @145_64cdc0
  FL[2] = (edi & edi);  // @146_64cdc0
  if (FL[2] == 0) goto L64cfe2;  // @147_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1056), sizeof v); (u32)v; });  // @148_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1044), &v, sizeof v); }  // @149_64cdc0
  L64cf70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @151_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @152_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @153_64cdc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 192), sizeof v); (u32)v; });  // @154_64cdc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 136), &v, sizeof v); }  // @155_64cdc0
  FL[2] = (edx & edx);  // @156_64cdc0
  if (FL[2] == 0) goto L64cfb6;  // @157_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_64cdc0
  PV[18] = (u32)(edx);  // @159_64cdc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @160_64cdc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_64cdc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[18]);  // @162_64cdc0
  ecx = edx = 0;  // @163_64cdc0
  FL[2] = (eax & eax);  // @164_64cdc0
  if (FL[2] == 0) goto L64cfb6;  // @165_64cdc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) | (u32)(128))); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @166_64cdc0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @167_64cdc0
  ecx = ebx;  // @168_64cdc0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1048), sizeof v); (u32)v; });  // @169_64cdc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @170_64cdc0
  PV[20] = (u32)(eax);  // @171_64cdc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[20], PV[19]);  // @172_64cdc0
  ecx = edx = 0;  // @173_64cdc0
  L64cfb6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1044), sizeof v); (u32)v; });  // @175_64cdc0
  eax = (eax + 1);  // @176_64cdc0
  FL[3] = eax;  // @177_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1044), &v, sizeof v); }  // @178_64cdc0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_64cdc0
  if (FL[0] != FL[1]) goto L64cfdb;  // @180_64cdc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @181_64cdc0
  FL[2] = (esi & esi);  // @182_64cdc0
  if (FL[2] == 0) goto L64cfe2;  // @183_64cdc0
  eax = 0;  // @184_64cdc0
  FL[3] = eax;  // @185_64cdc0
  edi = (u32)(esi + 16);  // @186_64cdc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 1044), &v, sizeof v); }  // @187_64cdc0
  goto L64cfde;  // @188_64cdc0
  L64cfdb:;
  edi = (edi + (u32)(4));  // @190_64cdc0
  FL[3] = edi;  // @191_64cdc0
  L64cfde:;
  FL[2] = (edi & edi);  // @193_64cdc0
  if (FL[2] != 0) goto L64cf70;  // @194_64cdc0
  L64cfe2:;
  ext_633654(G(u32, 0x6f5630));  // @196_64cdc0
  return eax;  // @197_64cdc0
}
PCREG(64cdc0, lifted_64cdc0);

extern "C" u32 THISCALL lifted_4f2f60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 nm_ = 6918184; u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4f2f60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1533), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4f2f60
  if (FL[0] == FL[1]) goto L4f31fc;  // @2_4f2f60
  eax = ext_4f2be0_thiscall1(ecx);  // @3_4f2f60
  ecx = edx = 0;  // @4_4f2f60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_4f2f60
  eax = (u32)(edi - 1);  // @6_4f2f60
  FL[0] = eax; FL[1] = (u32)(4);  // @7_4f2f60
  if (FL[0] > FL[1]) goto L4f30e2;  // @8_4f2f60
  switch (eax) {  // @9_4f2f60
  case 0: goto L4f3110;  // @10_4f2f60
  case 1: goto L4f2f9d;  // @11_4f2f60
  case 2: goto L4f2fef;  // @12_4f2f60
  case 3: goto L4f3041;  // @13_4f2f60
  case 4: goto L4f3093;  // @14_4f2f60
  default: __builtin_trap(); }  // @15_4f2f60
  L4f2f9d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @18_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6918200));  // @20_4f2f60
  ecx = edx = 0;  // @21_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1591), &v, sizeof v); }  // @22_4f2f60
  FL[2] = (eax & eax);  // @23_4f2f60
  if (FL[2] != 0) goto L4f3171;  // @24_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @26_4f2f60
  FL[2] = (ecx & ecx);  // @27_4f2f60
  if (FL[2] == 0) goto L4f2fe5;  // @28_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4f2f60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7244148), (u32)(6918200), (u32)(0));  // @30_4f2f60
  ecx = edx = 0;  // @31_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4f2f60
  L4f2fe5:;
  nm_ = 6918200; goto L4f3159;  // @34_4f2f60
  L4f2fef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @37_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6918216));  // @39_4f2f60
  ecx = edx = 0;  // @40_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1591), &v, sizeof v); }  // @41_4f2f60
  FL[2] = (eax & eax);  // @42_4f2f60
  if (FL[2] != 0) goto L4f3171;  // @43_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @45_4f2f60
  FL[2] = (ecx & ecx);  // @46_4f2f60
  if (FL[2] == 0) goto L4f3037;  // @47_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_4f2f60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7244152), (u32)(6918216), (u32)(0));  // @49_4f2f60
  ecx = edx = 0;  // @50_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_4f2f60
  L4f3037:;
  nm_ = 6918216; goto L4f3159;  // @53_4f2f60
  L4f3041:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @56_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6918232));  // @58_4f2f60
  ecx = edx = 0;  // @59_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1591), &v, sizeof v); }  // @60_4f2f60
  FL[2] = (eax & eax);  // @61_4f2f60
  if (FL[2] != 0) goto L4f3171;  // @62_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @64_4f2f60
  FL[2] = (ecx & ecx);  // @65_4f2f60
  if (FL[2] == 0) goto L4f3089;  // @66_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_4f2f60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7244156), (u32)(6918232), (u32)(0));  // @68_4f2f60
  ecx = edx = 0;  // @69_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_4f2f60
  L4f3089:;
  nm_ = 6918232; goto L4f3159;  // @72_4f2f60
  L4f3093:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @75_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6918248));  // @77_4f2f60
  ecx = edx = 0;  // @78_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1591), &v, sizeof v); }  // @79_4f2f60
  FL[2] = (eax & eax);  // @80_4f2f60
  if (FL[2] != 0) goto L4f3171;  // @81_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @83_4f2f60
  FL[2] = (ecx & ecx);  // @84_4f2f60
  if (FL[2] == 0) goto L4f30db;  // @85_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_4f2f60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7244160), (u32)(6918248), (u32)(0));  // @87_4f2f60
  ecx = edx = 0;  // @88_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_4f2f60
  L4f30db:;
  nm_ = 6918248; goto L4f3159;  // @91_4f2f60
  L4f30e2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @93_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_4f2f60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6918084), (u32)(1359));  // @95_4f2f60
  ecx = edx = 0;  // @96_4f2f60
  PV[0] = (u32)(edi);  // @97_4f2f60
  PV[1] = (u32)(eax);  // @98_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @99_4f2f60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 48)))(PV[1], (u32)(6918124), PV[0]);  // @100_4f2f60
  ecx = edx = 0;  // @101_4f2f60
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1535), &v, sizeof v); }  // @102_4f2f60
  L4f3110:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @104_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @105_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6918184));  // @107_4f2f60
  ecx = edx = 0;  // @108_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1591), &v, sizeof v); }  // @109_4f2f60
  FL[2] = (eax & eax);  // @110_4f2f60
  if (FL[2] != 0) goto L4f3171;  // @111_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @112_4f2f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @113_4f2f60
  FL[2] = (ecx & ecx);  // @114_4f2f60
  if (FL[2] == 0) goto L4f3154;  // @115_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_4f2f60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(7244144), (u32)(6918184), (u32)(0));  // @117_4f2f60
  ecx = edx = 0;  // @118_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @119_4f2f60
  L4f3154:;
  L4f3159:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @122_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, nm_);  // @124_4f2f60
  ecx = edx = 0;  // @125_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1591), &v, sizeof v); }  // @126_4f2f60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1534), &v, sizeof v); }  // @127_4f2f60
  L4f3171:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 1535), &v, sizeof v); }  // @129_4f2f60
  ebx = (u32)(esi + 1539);  // @130_4f2f60
  { u32 v = (u32)((u32)(6915696)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @131_4f2f60
  edi = 0;  // @132_4f2f60
  FL[3] = edi;  // @133_4f2f60
  { u32 v = (u32)((u32)(6915740)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @134_4f2f60
  { u32 v = (u32)((u32)(6915708)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @135_4f2f60
  { u32 v = (u32)((u32)(6915752)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @136_4f2f60
  { u32 v = (u32)((u32)(6915716)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @137_4f2f60
  { u32 v = (u32)((u32)(6915760)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @138_4f2f60
  { u32 v = (u32)((u32)(6915728)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @139_4f2f60
  { u32 v = (u32)((u32)(6915772)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @140_4f2f60
  { u32 v = (u32)((u32)(6915784)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @141_4f2f60
  { u32 v = (u32)((u32)(6918268)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @142_4f2f60
  { u32 v = (u32)((u32)(6915796)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @143_4f2f60
  { u32 v = (u32)((u32)(6915808)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @144_4f2f60
  { u32 v = (u32)((u32)(6915820)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @145_4f2f60
  L4f31e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1591), sizeof v); (u32)v; });  // @147_4f2f60
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi*4 - 56), sizeof v); (u32)v; });  // @148_4f2f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_4f2f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[2]);  // @150_4f2f60
  ecx = edx = 0;  // @151_4f2f60
  edi = (edi + 1);  // @152_4f2f60
  FL[3] = edi;  // @153_4f2f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @154_4f2f60
  ebx = (u32)(ebx + 4);  // @155_4f2f60
  FL[0] = edi; FL[1] = (u32)(13);  // @156_4f2f60
  if (FL[0] < FL[1]) goto L4f31e0;  // @157_4f2f60
  L4f31fc:;
  ext_633654(G(u32, 0x6f5630));  // @159_4f2f60
  return eax;  // @160_4f2f60
}
PCREG(4f2f60, lifted_4f2f60);

