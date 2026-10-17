// batch218037.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_466f60_thiscall2(u32, u32) __asm__("ext_466f60");
extern "C" u32 THISCALL ext_476dc0_thiscall2(u32, u32) __asm__("ext_476dc0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_524350_thiscall1(u32) __asm__("ext_524350");
extern "C" u32 THISCALL ext_5244f0_thiscall2(u32, u32) __asm__("ext_5244f0");
extern "C" u32 THISCALL ext_524660_thiscall1(u32) __asm__("ext_524660");
extern "C" u32 THISCALL ext_524890_thiscall2(u32, u32) __asm__("ext_524890");
extern "C" u32 THISCALL ext_52c000_thiscall2(u32, u32) __asm__("ext_52c000");
extern "C" u32 THISCALL ext_596940_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_596940");
extern "C" u32 THISCALL ext_5a2e20_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5a2e20");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_634273_cdecl0(void) __asm__("ext_634273");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_515da0(u32 ecx_in) {
  SEH_ENTER(0x66a09e);  // @h_515da0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_515da0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_515da0
  ebx = (u32)(esi + 33);  // @2_515da0
  ecx = ebx;  // @3_515da0
  eax = ext_524660_thiscall1(ecx);  // @4_515da0
  ecx = edx = 0;  // @5_515da0
  edi = (u32)(esi + 65);  // @6_515da0
  ecx = edi;  // @7_515da0
  eax = ext_524350_thiscall1(ecx);  // @8_515da0
  ecx = edx = 0;  // @9_515da0
  esi = (esi + (u32)(85));  // @10_515da0
  FL[3] = esi;  // @11_515da0
  ecx = esi;  // @12_515da0
  eax = ext_524350_thiscall1(ecx);  // @13_515da0
  ecx = edx = 0;  // @14_515da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @15_515da0
  ecx = (ecx + (u32)(105));  // @16_515da0
  FL[3] = ecx;  // @17_515da0
  eax = ext_4e1b60_thiscall1(ecx);  // @18_515da0
  ecx = edx = 0;  // @19_515da0
  PV[0] = (u32)(ecx);  // @20_515da0
  ecx = edi;  // @21_515da0
  eax = ext_5244f0_thiscall2(ecx, (u32)((u32)(1101004800)));  // @22_515da0
  ecx = edx = 0;  // @23_515da0
  PV[1] = (u32)(ecx);  // @24_515da0
  ecx = esi;  // @25_515da0
  eax = ext_5244f0_thiscall2(ecx, (u32)((u32)(1128792064)));  // @26_515da0
  ecx = edx = 0;  // @27_515da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @28_515da0
  ecx = edi;  // @29_515da0
  { u32 v = (u32)((u32)(3296329728)); __builtin_memcpy((void *)(u32)(eax + 17), &v, sizeof v); }  // @30_515da0
  { u32 v = (u32)((u32)(1109393408)); __builtin_memcpy((void *)(u32)(eax + 21), &v, sizeof v); }  // @31_515da0
  { u32 v = (u32)((u32)(1121714176)); __builtin_memcpy((void *)(u32)(eax + 25), &v, sizeof v); }  // @32_515da0
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @33_515da0
  eax = ext_4690b0_cdecl0();  // @34_515da0
  ecx = edx = 0;  // @35_515da0
  ecx = esi;  // @36_515da0
  eax = ext_4690b0_cdecl0();  // @37_515da0
  ecx = edx = 0;  // @38_515da0
  PV[2] = (u32)(ecx);  // @39_515da0
  ecx = ebx;  // @40_515da0
  eax = ext_524890_thiscall2(ecx, (u32)((u32)(0)));  // @41_515da0
  ecx = edx = 0;  // @42_515da0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @43_515da0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @44_515da0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 213), &v, sizeof v); }  // @45_515da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 173), &v, sizeof v); }  // @46_515da0
  eax = ext_41e290_cdecl1((u32)(28));  // @47_515da0
  ecx = edx = 0;  // @48_515da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @49_515da0
  reg.state = (s32)((u32)(0));  // @50_515da0
  FL[2] = (eax & eax);  // @51_515da0
  if (FL[2] == 0) goto L515e8e;  // @52_515da0
  ecx = eax;  // @53_515da0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @54_515da0
  ecx = edx = 0;  // @55_515da0
  goto L515e90;  // @56_515da0
  L515e8e:;
  eax = 0;  // @58_515da0
  FL[3] = eax;  // @59_515da0
  L515e90:;
  reg.state = (s32)((u32)(4294967295));  // @61_515da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 214), &v, sizeof v); }  // @62_515da0
  eax = ext_41e290_cdecl1((u32)(28));  // @63_515da0
  ecx = edx = 0;  // @64_515da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @65_515da0
  reg.state = (s32)((u32)(1));  // @66_515da0
  FL[2] = (eax & eax);  // @67_515da0
  if (FL[2] == 0) goto L515eda;  // @68_515da0
  ecx = eax;  // @69_515da0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @70_515da0
  ecx = edx = 0;  // @71_515da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 218), &v, sizeof v); }  // @72_515da0
  eax = ebx;  // @73_515da0
  SEH_LEAVE();  // @74_515da0
  return eax;  // @75_515da0
  L515eda:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 218), &v, sizeof v); }  // @77_515da0
  eax = ebx;  // @78_515da0
  SEH_LEAVE();  // @79_515da0
  return eax;  // @80_515da0
}
PCREG(515da0, lifted_515da0);

extern "C" u32 THISCALL lifted_592410(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66ba2b);  // @h_592410
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0; u32 JA = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_592410
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_592410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @2_592410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(2099193);  // @3_592410
  if (FL[0] == FL[1]) goto L5924a6;  // @4_592410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_592410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_592410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6997712), (u32)(2285));  // @7_592410
  ecx = edx = 0;  // @8_592410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_592410
  edi = eax;  // @10_592410
  eax = (u32)(EBP - 192);  // @11_592410
  ecx = ebx;  // @12_592410
  PV[0] = (u32)(eax);  // @13_592410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[0], (u32)(1));  // @14_592410
  ecx = edx = 0;  // @15_592410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_592410
  ecx = eax;  // @17_592410
  reg.state = (s32)((u32)(0));  // @18_592410
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_592410
  ecx = edx = 0;  // @20_592410
  PV[1] = (u32)(eax);  // @21_592410
  PV[2] = (u32)(edi);  // @22_592410
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[2], (u32)(6998804), PV[1]);  // @23_592410
  ecx = edx = 0;  // @24_592410
  ecx = (u32)(EBP - 192);  // @25_592410
  eax = ext_4cbec0_thiscall1(ecx);  // @26_592410
  ecx = edx = 0;  // @27_592410
  goto L592555;  // @28_592410
  L5924a6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @30_592410
  ecx = ebx;  // @31_592410
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(esi + 1704)))(ecx);  // @32_592410
  ecx = edx = 0;  // @33_592410
  PV[3] = (u32)(eax);  // @34_592410
  ecx = ebx;  // @35_592410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1696)))(ecx, PV[3]);  // @36_592410
  ecx = edx = 0;  // @37_592410
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3846), sizeof v); (u32)v; });  // @38_592410
  ecx = edi;  // @39_592410
  eax = ext_466f60_thiscall2(ecx, PV[4]);  // @40_592410
  ecx = edx = 0;  // @41_592410
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3842), sizeof v); (u32)v; });  // @42_592410
  ecx = edi;  // @43_592410
  eax = ext_466f60_thiscall2(ecx, PV[5]);  // @44_592410
  ecx = edx = 0;  // @45_592410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @46_592410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @47_592410
  if (FL[0] != FL[1]) goto L592540;  // @48_592410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_592410
  eax = (u32)(EBP - 28);  // @50_592410
  PV[6] = (u32)(eax);  // @51_592410
  eax = (u32)(EBP - 64);  // @52_592410
  ecx = ebx;  // @53_592410
  PV[7] = (u32)(eax);  // @54_592410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 928)))(ecx, PV[7], PV[6]);  // @55_592410
  ecx = edx = 0;  // @56_592410
  PV[8] = (u32)(eax);  // @57_592410
  ecx = ebx;  // @58_592410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 912)))(ecx, PV[8]);  // @59_592410
  ecx = edx = 0;  // @60_592410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_592410
  ecx = ebx;  // @62_592410
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @63_592410
  ecx = edx = 0;  // @64_592410
  ecx = (u32)(EBP - 28);  // @65_592410
  PV[9] = (u32)(ecx);  // @66_592410
  ecx = eax;  // @67_592410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @68_592410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[9]);  // @69_592410
  ecx = edx = 0;  // @70_592410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @71_592410
  X0[1] = 0;  // @72_592410
  X0[2] = 0;  // @73_592410
  X0[3] = 0;  // @74_592410
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @75_592410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @76_592410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2130), sizeof v); (u32)v; });  // @77_592410
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @78_592410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @79_592410
  eax = (u32)(EBP - 28);  // @80_592410
  PV[10] = (u32)(eax);  // @81_592410
  if (FL[0] != FL[1]) { JA = 4; goto L59253b; }  // @82_592410 (hand: the push 5 / push 4 value)
  JA = 5; goto L59253b;  // @83_592410
  L592539:;
  L59253b:;
  eax = ext_596940_thiscall5(ecx, JA, PV[10], (u32)(1), (u32)(-1));  // @86_592410 (hand: args are JA, &S, 1, -1)
  ecx = edx = 0;  // @87_592410
  L592540:;
  PV[11] = (u32)(ecx);  // @89_592410
  ecx = ebx;  // @90_592410
  eax = ext_5a2e20_thiscall5(ecx, (u32)(0), (u32)(1), (u32)(0), (u32)((u32)(1084227584)));  // @91_592410
  ecx = edx = 0;  // @92_592410
  L592555:;
  SEH_LEAVE();  // @94_592410
  ext_633654(G(u32, 0x6f5630));  // @95_592410
  return eax;  // @96_592410
}
PCREG(592410, lifted_592410);

extern "C" u32 THISCALL lifted_5be220(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c49f);  // @h_5be220
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0; u32 JB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_5be220
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5be220
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @3_5be220
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 81), &v, sizeof v); }  // @4_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @6_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5be220
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @8_5be220
  ecx = edx = 0;  // @9_5be220
  ecx = (u32)(EBP - 96);  // @10_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @11_5be220
  PV[0] = (u32)(ecx);  // @12_5be220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_5be220
  ecx = eax;  // @14_5be220
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6859232), PV[0]);  // @15_5be220
  ecx = edx = 0;  // @16_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5be220
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @18_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5be220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @21_5be220
  ecx = edx = 0;  // @22_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_5be220
  ebx = eax;  // @24_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @25_5be220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_5be220
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @27_5be220
  ecx = edx = 0;  // @28_5be220
  ecx = eax;  // @29_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @30_5be220
  eax = esi;  // @31_5be220
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 57), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @32_5be220
  if (FL[0] == FL[1]) goto L5be2bb;  // @33_5be220
  ecx = (ecx + 1);  // @34_5be220
  FL[3] = ecx;  // @35_5be220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @36_5be220
  L5be2bb:;
  esi = 0;  // @38_5be220
  FL[3] = esi;  // @39_5be220
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @40_5be220
  FL[2] = (ecx & ecx);  // @41_5be220
  if ((s32)FL[2] <= 0) goto L5be3fc;  // @42_5be220
  L5be2c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @45_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_5be220
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @47_5be220
  ecx = edx = 0;  // @48_5be220
  FL[0] = esi; FL[1] = eax;  // @49_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @50_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @52_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5be220
  if ((s32)FL[0] >= (s32)FL[1]) { JB = 0; goto L5be2e5; }  // @54_5be220 (hand: min via push esi / push 0 diamond)
  JB = esi;  // @55_5be220
  goto L5be2e5;  // @56_5be220
  L5be2e3:;
  L5be2e5:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, JB);  // @59_5be220 (hand: one argument, JB)
  ecx = edx = 0;  // @60_5be220
  edx = eax;  // @61_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_5be220
  PV[3] = (u32)(edx);  // @63_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_5be220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @66_5be220
  ecx = edx = 0;  // @67_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @68_5be220
  ecx = (u32)(EBP - 28);  // @69_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @70_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @71_5be220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @72_5be220
  PV[4] = (u32)(ecx);  // @73_5be220
  ecx = eax;  // @74_5be220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[4]);  // @75_5be220
  ecx = edx = 0;  // @76_5be220
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 81), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @77_5be220
  if (FL[0] != FL[1]) goto L5be399;  // @78_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_5be220
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @80_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @81_5be220
  eax = (u32)(EBP - 28);  // @82_5be220
  PV[5] = (u32)(ecx);  // @83_5be220
  PV[6] = (u32)(eax);  // @84_5be220
  eax = (u32)(EBP - 40);  // @85_5be220
  PV[7] = (u32)(eax);  // @86_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_5be220
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @88_5be220
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8], PV[7], PV[6], (u32)(0), (u32)((u32)(0)), (u32)(1), (u32)(1));  // @89_5be220
  ecx = edx = 0;  // @90_5be220
  PV[9] = (u32)(eax);  // @91_5be220
  ecx = ebx;  // @92_5be220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 532)))(ecx, PV[9]);  // @93_5be220
  ecx = edx = 0;  // @94_5be220
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @95_5be220
  if (FL[0] != FL[1]) goto L5be36f;  // @96_5be220
  L5be360:;
  ecx = ebx;  // @98_5be220
  eax = ext_52c000_thiscall2(ecx, (u32)(1));  // @99_5be220
  ecx = edx = 0;  // @100_5be220
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @101_5be220
  if (FL[0] == FL[1]) goto L5be360;  // @102_5be220
  L5be36f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @104_5be220
  PV[10] = (u32)(edx);  // @105_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @106_5be220
  FL[2] = (ecx & ecx);  // @107_5be220
  if (FL[2] == 0) goto L5be3be;  // @108_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @109_5be220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + eax*4 - 80), &v, sizeof v); }  // @110_5be220
  eax = (eax + 1);  // @111_5be220
  FL[3] = eax;  // @112_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @113_5be220
  eax = ext_634273_cdecl2(PV[10], (u32)(32));  // @114_5be220
  ecx = edx = 0;  // @115_5be220
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @116_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @117_5be220
  L5be399:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @119_5be220
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @120_5be220
  X0[2] = 0;  // @121_5be220
  X0[3] = 0;  // @122_5be220
  esi = (esi + 1);  // @123_5be220
  FL[3] = esi;  // @124_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @125_5be220
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @126_5be220
  __builtin_memcpy((void *)((u32)(EBP - 40) + 4), &X0[1], 4);  // @127_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @128_5be220
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 81), &v, sizeof v); }  // @129_5be220
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @130_5be220
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @131_5be220
  if ((s32)FL[0] >= (s32)FL[1]) goto L5be3fc;  // @132_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @133_5be220
  goto L5be2c8;  // @134_5be220
  L5be3be:;
  eax = ext_634273_cdecl2(PV[10], (u32)(32));  // @136_5be220 (hand: pre-pushed (edx, 0x20) of the earlier push at 0x5be372)
  ecx = edx = 0;  // @137_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @138_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @139_5be220
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 7), &v, sizeof v); }  // @140_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @141_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_5be220
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7026156), (u32)(228));  // @143_5be220
  ecx = edx = 0;  // @144_5be220
  PV[11] = (u32)(eax);  // @145_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @146_5be220
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[11], (u32)(7026268));  // @147_5be220
  ecx = edx = 0;  // @148_5be220
  goto L5be586;  // @149_5be220
  L5be3fc:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @151_5be220
  edx = 0;  // @152_5be220
  FL[3] = edx;  // @153_5be220
  esi = 0;  // @154_5be220
  FL[3] = esi;  // @155_5be220
  ebx = 0;  // @156_5be220
  FL[3] = ebx;  // @157_5be220
  ecx = 0;  // @158_5be220
  FL[3] = ecx;  // @159_5be220
  FL[0] = edi; FL[1] = (u32)(2);  // @160_5be220
  if ((s32)FL[0] < (s32)FL[1]) goto L5be42c;  // @161_5be220
  eax = (u32)(edi - 1);  // @162_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @163_5be220
  edi = eax;  // @164_5be220
  L5be414:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx*4 - 80), sizeof v); (u32)v; });  // @166_5be220
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }));  // @167_5be220
  FL[3] = edx;  // @168_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx*4 - 76), sizeof v); (u32)v; });  // @169_5be220
  ecx = (ecx + (u32)(2));  // @170_5be220
  FL[3] = ecx;  // @171_5be220
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }));  // @172_5be220
  FL[3] = esi;  // @173_5be220
  FL[0] = ecx; FL[1] = edi;  // @174_5be220
  if ((s32)FL[0] < (s32)FL[1]) goto L5be414;  // @175_5be220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @176_5be220
  L5be42c:;
  FL[0] = ecx; FL[1] = edi;  // @178_5be220
  if ((s32)FL[0] >= (s32)FL[1]) goto L5be437;  // @179_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx*4 - 80), sizeof v); (u32)v; });  // @180_5be220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @181_5be220
  L5be437:;
  eax = (u32)(esi + edx);  // @183_5be220
  ebx = (ebx + eax);  // @184_5be220
  FL[3] = ebx;  // @185_5be220
  eax = ext_41e290_cdecl1((u32)(24));  // @186_5be220
  ecx = edx = 0;  // @187_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @188_5be220
  reg.state = (s32)((u32)(0));  // @189_5be220
  FL[2] = (eax & eax);  // @190_5be220
  if (FL[2] == 0) goto L5be463;  // @191_5be220
  PV[12] = (u32)(ebx);  // @192_5be220
  ecx = eax;  // @193_5be220
  eax = ext_476dc0_thiscall2(ecx, PV[12]);  // @194_5be220
  ecx = edx = 0;  // @195_5be220
  ecx = eax;  // @196_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @197_5be220
  goto L5be468;  // @198_5be220
  L5be463:;
  ecx = 0;  // @200_5be220
  FL[3] = ecx;  // @201_5be220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @202_5be220
  L5be468:;
  edx = 0;  // @204_5be220
  FL[3] = edx;  // @205_5be220
  ebx = 0;  // @206_5be220
  FL[3] = ebx;  // @207_5be220
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @208_5be220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @209_5be220
  FL[2] = (edi & edi);  // @210_5be220
  if ((s32)FL[2] <= 0) goto L5be580;  // @211_5be220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; });  // @212_5be220
  X1[1] = 0;  // @213_5be220
  X1[2] = 0;  // @214_5be220
  X1[3] = 0;  // @215_5be220
  L5be490:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ebx*4 - 80), sizeof v); (u32)v; });  // @217_5be220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @218_5be220
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @219_5be220
  if ((s32)FL[0] <= (s32)FL[1]) goto L5be514;  // @220_5be220
  edi = edx;  // @221_5be220
  edi = (edi << (u32)(4));  // @222_5be220
  FL[3] = edi;  // @223_5be220
  ebx = 0;  // @224_5be220
  FL[3] = ebx;  // @225_5be220
  L5be4b0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @227_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @228_5be220
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @229_5be220
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @230_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx + 4), sizeof v); (u32)v; });  // @231_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx + 4), &v, sizeof v); }  // @232_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx + 8), sizeof v); (u32)v; });  // @233_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx + 8), &v, sizeof v); }  // @234_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx + 12), sizeof v); (u32)v; });  // @235_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx + 12), &v, sizeof v); }  // @236_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @237_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @238_5be220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax + 8) + 0), 4); v; });  // @239_5be220
  X0[1] = 0;  // @240_5be220
  X0[2] = 0;  // @241_5be220
  X0[3] = 0;  // @242_5be220
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @243_5be220
  __builtin_memcpy((void *)((u32)(edi + eax + 8) + 0), &X0[0], 4);  // @244_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @245_5be220
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax) + 0), 4); v; });  // @246_5be220
  X0[1] = 0;  // @247_5be220
  X0[2] = 0;  // @248_5be220
  X0[3] = 0;  // @249_5be220
  ebx = (ebx + (u32)(16));  // @250_5be220
  FL[3] = ebx;  // @251_5be220
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; })));  // @252_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @253_5be220
  __builtin_memcpy((void *)((u32)(edi + eax) + 0), &X0[0], 4);  // @254_5be220
  edi = (edi + (u32)(16));  // @255_5be220
  FL[3] = edi;  // @256_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @257_5be220
  eax = (eax + 1);  // @258_5be220
  FL[3] = eax;  // @259_5be220
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @260_5be220
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @261_5be220
  if ((s32)FL[0] < (s32)FL[1]) goto L5be4b0;  // @262_5be220
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @263_5be220
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @264_5be220
  L5be514:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @266_5be220
  X0[1] = 0;  // @267_5be220
  X0[2] = 0;  // @268_5be220
  X0[3] = 0;  // @269_5be220
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 4) + 0), 4); v; })));  // @270_5be220
  __builtin_memcpy((void *)((u32)(ecx + 4) + 0), &X0[0], 4);  // @271_5be220
  FL[2] = (esi & esi);  // @272_5be220
  if (FL[2] == 0) goto L5be571;  // @273_5be220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @274_5be220
  FL[2] = (eax & eax);  // @275_5be220
  if (FL[2] == 0) goto L5be537;  // @276_5be220
  PV[13] = (u32)(eax);  // @277_5be220
  eax = ext_41e2c0_cdecl1(PV[13]);  // @278_5be220
  ecx = edx = 0;  // @279_5be220
  L5be537:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @281_5be220
  FL[2] = (eax & eax);  // @282_5be220
  if (FL[2] == 0) goto L5be549;  // @283_5be220
  PV[14] = (u32)(eax);  // @284_5be220
  eax = ext_634273_cdecl2(PV[14], (u32)(4));  // @285_5be220
  ecx = edx = 0;  // @286_5be220
  L5be549:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @288_5be220
  FL[2] = (eax & eax);  // @289_5be220
  if (FL[2] == 0) goto L5be55b;  // @290_5be220
  PV[15] = (u32)(eax);  // @291_5be220
  eax = ext_634273_cdecl2(PV[15], (u32)(4));  // @292_5be220
  ecx = edx = 0;  // @293_5be220
  L5be55b:;
  PV[16] = (u32)(esi);  // @295_5be220
  eax = ext_634273_cdecl2(PV[16], (u32)(24));  // @296_5be220
  ecx = edx = 0;  // @297_5be220
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; });  // @298_5be220
  X1[1] = 0;  // @299_5be220
  X1[2] = 0;  // @300_5be220
  X1[3] = 0;  // @301_5be220
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @302_5be220
  L5be571:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @304_5be220
  ebx = (ebx + 1);  // @305_5be220
  FL[3] = ebx;  // @306_5be220
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @307_5be220
  FL[0] = ebx; FL[1] = edi;  // @308_5be220
  if ((s32)FL[0] < (s32)FL[1]) goto L5be490;  // @309_5be220
  L5be580:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @311_5be220
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 13), &v, sizeof v); }  // @312_5be220
  L5be586:;
  SEH_LEAVE();  // @314_5be220
  ext_633654(G(u32, 0x6f5630));  // @315_5be220
  return eax;  // @316_5be220
}
PCREG(5be220, lifted_5be220);

