// batch240014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4cc500_fastcall2(u32, u32) __asm__("ext_4cc500");
extern "C" u32 THISCALL ext_484b10_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_484b10");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4db550_thiscall1(u32) __asm__("ext_4db550");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e9200_thiscall4(u32, u32, u32, u32) __asm__("ext_4e9200");
extern "C" u32 THISCALL ext_4ea300_thiscall2(u32, u32) __asm__("ext_4ea300");
extern "C" u32 THISCALL ext_596d30_thiscall2(u32, u32) __asm__("ext_596d30");
extern "C" u32 THISCALL ext_59a580_thiscall4(u32, u32, u32, u32) __asm__("ext_59a580");
extern "C" u32 THISCALL ext_5ab950_thiscall1(u32) __asm__("ext_5ab950");
extern "C" u32 THISCALL ext_5aba60_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5aba60");
extern "C" u32 THISCALL ext_5ac5d0_thiscall2(u32, u32) __asm__("ext_5ac5d0");
extern "C" u32 THISCALL ext_5ac940_thiscall2(u32, u32) __asm__("ext_5ac940");
extern "C" u32 THISCALL ext_5acac0_thiscall2(u32, u32) __asm__("ext_5acac0");
extern "C" u32 THISCALL ext_5ae5a0_thiscall3(u32, u32, u32) __asm__("ext_5ae5a0");
extern "C" u32 THISCALL ext_5aedb0_thiscall1(u32) __asm__("ext_5aedb0");
extern "C" u32 THISCALL ext_5af2a0_thiscall3(u32, u32, u32) __asm__("ext_5af2a0");
extern "C" u32 THISCALL ext_5b04e0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5b04e0");
extern "C" u32 THISCALL ext_5b0560_thiscall2(u32, u32) __asm__("ext_5b0560");
extern "C" u32 THISCALL ext_5b07d0_thiscall3(u32, u32, u32) __asm__("ext_5b07d0");
extern "C" u32 THISCALL ext_5b07f0_thiscall3(u32, u32, u32) __asm__("ext_5b07f0");
extern "C" u32 THISCALL ext_5c2b00_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5c2b00");
extern "C" u32 THISCALL ext_5c4290_thiscall1(u32) __asm__("ext_5c4290");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 THISCALL ext_5edb00_thiscall2(u32, u32) __asm__("ext_5edb00");
extern "C" u32 THISCALL ext_5edc60_thiscall2(u32, u32) __asm__("ext_5edc60");
extern "C" u32 THISCALL ext_5ef240_thiscall1(u32) __asm__("ext_5ef240");
extern "C" u32 THISCALL ext_5ef880_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5ef880");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc500_cdecl12(...) __asm__("ext_4cc500");
extern "C" u32 ext_61cb70_cdecl1(...) __asm__("ext_61cb70");
extern "C" u32 ext_61cd60_cdecl6(...) __asm__("ext_61cd60");
extern "C" u32 ext_61d090_cdecl6(...) __asm__("ext_61d090");
extern "C" u32 ext_61dba0_cdecl5(...) __asm__("ext_61dba0");
extern "C" u32 ext_61f5a0_cdecl4(...) __asm__("ext_61f5a0");
extern "C" u32 ext_61fb10_cdecl4(...) __asm__("ext_61fb10");
extern "C" u32 ext_61fd60_cdecl3(...) __asm__("ext_61fd60");
extern "C" u32 ext_61ffb0_cdecl1(...) __asm__("ext_61ffb0");
extern "C" u32 ext_620120_cdecl1(...) __asm__("ext_620120");
extern "C" u32 ext_620180_cdecl4(...) __asm__("ext_620180");
extern "C" u32 ext_620320_cdecl2(...) __asm__("ext_620320");
extern "C" u32 ext_6204a0_cdecl1(...) __asm__("ext_6204a0");
extern "C" u32 ext_6206e0_cdecl1(...) __asm__("ext_6206e0");
extern "C" u32 ext_620840_cdecl4(...) __asm__("ext_620840");
extern "C" u32 ext_620840_cdecl7(...) __asm__("ext_620840");
extern "C" u32 ext_620890_cdecl2(...) __asm__("ext_620890");
extern "C" u32 ext_620910_cdecl4(...) __asm__("ext_620910");
extern "C" u32 ext_620c00_cdecl4(...) __asm__("ext_620c00");
extern "C" u32 ext_620cb0_cdecl4(...) __asm__("ext_620cb0");
extern "C" u32 ext_620d50_cdecl4(...) __asm__("ext_620d50");
extern "C" u32 ext_6211c0_cdecl6(...) __asm__("ext_6211c0");
extern "C" u32 ext_6218c0_cdecl4(...) __asm__("ext_6218c0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_570310(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_570310
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 419), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_570310
  if (FL[0] != FL[1]) goto L5703ae;  // @2_570310
  ebx = 0;  // @3_570310
  FL[3] = ebx;  // @4_570310
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 556), sizeof v); (u32)v; }); FL[1] = ebx;  // @5_570310
  if (FL[0] <= FL[1]) goto L570369;  // @6_570310
  esi = (u32)(edi + 460);  // @7_570310
  L570342:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_570310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_570310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, (u32)(6781786));  // @11_570310
  ecx = edx = 0;  // @12_570310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_570310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_570310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @15_570310
  ecx = edx = 0;  // @16_570310
  ebx = (ebx + 1);  // @17_570310
  FL[3] = ebx;  // @18_570310
  esi = (u32)(esi + 4);  // @19_570310
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 556), sizeof v); (u32)v; });  // @20_570310
  if (FL[0] < FL[1]) goto L570342;  // @21_570310
  L570369:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 560), &v, sizeof v); }  // @23_570310
  esi = (u32)(edi + 448);  // @24_570310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @25_570310
  ebx = (u32)(2);  // @26_570310
  { u32 v = (u32)((u32)(1094713344)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @27_570310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @28_570310
  L570393:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_570310
  edx = (u32)(EBP - 16);  // @31_570310
  PV[0] = (u32)(edx);  // @32_570310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_570310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[0]);  // @34_570310
  ecx = edx = 0;  // @35_570310
  esi = (u32)(esi + 4);  // @36_570310
  ebx = (ebx - (u32)(1));  // @37_570310
  FL[3] = ebx;  // @38_570310
  if (FL[3] != 0) goto L570393;  // @39_570310
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 564), &v, sizeof v); }  // @40_570310
  L5703ae:;
  ext_633654(G(u32, 0x6f5630));  // @42_570310
  return eax;  // @43_570310
}
PCREG(570310, lifted_570310);

extern "C" u32 THISCALL lifted_5ae710(u32 ecx_in, u32 a0) {
  u8 F[0x590] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x490);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x490 + 8, &a0, 4);
  eax = (u32)(EBP - 1028);  // @0_5ae710
  esi = ecx;  // @1_5ae710
  PV[0] = (u32)(eax);  // @2_5ae710
  eax = ext_5ae5a0_thiscall3(ecx, PV[0], (u32)(1));  // @3_5ae710
  ecx = edx = 0;  // @4_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5ae710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5ae710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @8_5ae710
  ecx = edx = 0;  // @9_5ae710
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @10_5ae710
  ecx = (u32)(EBP - 1028);  // @11_5ae710
  PV[1] = (u32)(ecx);  // @12_5ae710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_5ae710
  ecx = eax;  // @14_5ae710
  if (FL[0] == FL[1]) goto L5ae79b;  // @15_5ae710
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(7014828), (u32)(12), PV[1], (u32)(1024));  // @16_5ae710
  ecx = edx = 0;  // @17_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5ae710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5ae710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @21_5ae710
  ecx = edx = 0;  // @22_5ae710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_5ae710
  ecx = eax;  // @24_5ae710
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(7014800), (u32)(1), (u32)(0));  // @25_5ae710
  ecx = edx = 0;  // @26_5ae710
  ext_633654(G(u32, 0x6f5630));  // @27_5ae710
  return eax;  // @28_5ae710
  L5ae79b:;
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(6978144), (u32)(7), PV[1], (u32)(1024));  // @30_5ae710 (hand fix: the two pushes before the diamond are shared)
  ecx = edx = 0;  // @31_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_5ae710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5ae710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @35_5ae710
  ecx = edx = 0;  // @36_5ae710
  ecx = (u32)(esi + 6);  // @37_5ae710
  PV[2] = (u32)(ecx);  // @38_5ae710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_5ae710
  ecx = eax;  // @40_5ae710
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(7014844), (u32)(8), PV[2], (u32)(128));  // @41_5ae710
  ecx = edx = 0;  // @42_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_5ae710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @44_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_5ae710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @46_5ae710
  ecx = edx = 0;  // @47_5ae710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_5ae710
  ecx = eax;  // @49_5ae710
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(6976944), (u32)(1), (u32)(0));  // @50_5ae710
  ecx = edx = 0;  // @51_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_5ae710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5ae710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @55_5ae710
  ecx = edx = 0;  // @56_5ae710
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 134), sizeof v); (u32)v; });  // @57_5ae710
  ecx = eax;  // @58_5ae710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @59_5ae710
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(7014856), PV[3], (u32)(2));  // @60_5ae710
  ecx = edx = 0;  // @61_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_5ae710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_5ae710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_5ae710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @65_5ae710
  ecx = edx = 0;  // @66_5ae710
  ecx = (u32)(esi + 138);  // @67_5ae710
  PV[4] = (u32)(ecx);  // @68_5ae710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @69_5ae710
  ecx = eax;  // @70_5ae710
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(7014872), (u32)(22), PV[4], (u32)(8));  // @71_5ae710
  ecx = edx = 0;  // @72_5ae710
  ext_633654(G(u32, 0x6f5630));  // @73_5ae710
  return eax;  // @74_5ae710
}
PCREG(5ae710, lifted_5ae710);

extern "C" u32 THISCALL lifted_5ef3a0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  SEH_ENTER(0x66cce2);  // @h_5ef3a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  eax = ecx;  // @0_5ef3a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ef3a0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @2_5ef3a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @4_5ef3a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_5ef3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_5ef3a0
  PV[1] = (u32)(ebx);  // @7_5ef3a0
  PV[2] = (u32)(edi);  // @8_5ef3a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 195), &v, sizeof v); }  // @9_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 169), sizeof v); (u32)v; });  // @10_5ef3a0
  PV[3] = (u32)(esi);  // @11_5ef3a0
  eax = ext_5aba60_thiscall5(ecx, PV[3], PV[2], PV[1], PV[0]);  // @12_5ef3a0
  ecx = edx = 0;  // @13_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @14_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 169), sizeof v); (u32)v; });  // @15_5ef3a0
  eax = ext_5ac5d0_thiscall2(ecx, (u32)(4288716800));  // @16_5ef3a0
  ecx = edx = 0;  // @17_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @18_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 169), sizeof v); (u32)v; });  // @19_5ef3a0
  eax = ext_5ac940_thiscall2(ecx, (u32)(7045580));  // @20_5ef3a0
    // @21_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @22_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 169), sizeof v); (u32)v; });  // @23_5ef3a0
  eax = ext_5acac0_thiscall2(ecx, (u32)(0));  // @24_5ef3a0
    // @25_5ef3a0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @26_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @27_5ef3a0
  PV[5] = (u32)(ebx);  // @28_5ef3a0
  PV[6] = (u32)(edi);  // @29_5ef3a0
  PV[7] = (u32)(esi);  // @30_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 161), sizeof v); (u32)v; });  // @31_5ef3a0
  eax = ext_5aba60_thiscall5(ecx, PV[7], PV[6], PV[5], PV[4]);  // @32_5ef3a0
  ecx = edx = 0;  // @33_5ef3a0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @34_5ef3a0
  PV[9] = (u32)(ebx);  // @35_5ef3a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @36_5ef3a0
  PV[10] = (u32)(edi);  // @37_5ef3a0
  PV[11] = (u32)(esi);  // @38_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 165), sizeof v); (u32)v; });  // @39_5ef3a0
  eax = ext_5aba60_thiscall5(ecx, PV[11], PV[10], PV[9], PV[8]);  // @40_5ef3a0
  ecx = edx = 0;  // @41_5ef3a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @42_5ef3a0
  FL[2] = (esi & esi);  // @43_5ef3a0
  if (FL[2] == 0) goto L5ef4de;  // @44_5ef3a0
  eax = ext_41e290_cdecl1((u32)(247));  // @45_5ef3a0
  ecx = edx = 0;  // @46_5ef3a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @47_5ef3a0
  reg.state = (s32)((u32)(0));  // @48_5ef3a0
  FL[2] = (eax & eax);  // @49_5ef3a0
  if (FL[2] == 0) goto L5ef47d;  // @50_5ef3a0
  ecx = eax;  // @51_5ef3a0
  eax = ext_5ed460_thiscall1(ecx);  // @52_5ef3a0
  ecx = edx = 0;  // @53_5ef3a0
  ecx = eax;  // @54_5ef3a0
  goto L5ef47f;  // @55_5ef3a0
  L5ef47d:;
  ecx = 0;  // @57_5ef3a0
  FL[3] = ecx;  // @58_5ef3a0
  L5ef47f:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 177), &v, sizeof v); }  // @60_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_5ef3a0
  PV[12] = (u32)(esi);  // @62_5ef3a0
  reg.state = (s32)((u32)(4294967295));  // @63_5ef3a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[12], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @64_5ef3a0
  ecx = edx = 0;  // @65_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_5ef3a0
  ecx = (u32)(8);  // @67_5ef3a0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; }));  // @68_5ef3a0
  FL[3] = ecx;  // @69_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @70_5ef3a0
  eax = (u32)(eax + ecx*2);  // @71_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 177), sizeof v); (u32)v; });  // @72_5ef3a0
  PV[13] = (u32)(eax);  // @73_5ef3a0
  eax = ext_5edc60_thiscall2(ecx, PV[13]);  // @74_5ef3a0
    // @75_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 177), sizeof v); (u32)v; });  // @76_5ef3a0
  eax = ext_5edb00_thiscall2(ecx, (u32)(40));  // @77_5ef3a0
    // @78_5ef3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 177), sizeof v); (u32)v; });  // @79_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_5ef3a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @81_5ef3a0
  ecx = edx = 0;  // @82_5ef3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 177), sizeof v); (u32)v; });  // @83_5ef3a0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @84_5ef3a0
  L5ef4de:;
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 185), sizeof v); (u32)v; }));  // @86_5ef3a0
  ecx = ebx;  // @87_5ef3a0
  PV[14] = (u32)(eax);  // @88_5ef3a0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 183), sizeof v); (u32)v; }));  // @89_5ef3a0
  PV[15] = (u32)(eax);  // @90_5ef3a0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 191), sizeof v); (u32)v; });  // @91_5ef3a0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 187), sizeof v); (u32)v; });  // @92_5ef3a0
  eax = ext_5ef880_thiscall5(ecx, PV[17], PV[16], PV[15], PV[14]);  // @93_5ef3a0
  ecx = edx = 0;  // @94_5ef3a0
  SEH_LEAVE();  // @95_5ef3a0
  return eax;  // @96_5ef3a0
}
PCREG(5ef3a0, lifted_5ef3a0);

extern "C" u32 THISCALL lifted_5ae020(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5ae020
  edi = ecx;  // @1_5ae020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5ae020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5ae020
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @4_5ae020
  ecx = edx = 0;  // @5_5ae020
  ecx = (u32)(EBP - 25);  // @6_5ae020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 25), &v, sizeof v); }  // @7_5ae020
  PV[0] = (u32)(ecx);  // @8_5ae020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_5ae020
  ecx = eax;  // @10_5ae020
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6976892), PV[0]);  // @11_5ae020
  ecx = edx = 0;  // @12_5ae020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @13_5ae020
  if (FL[0] == FL[1]) goto L5ae0d7;  // @14_5ae020
  ecx = (u32)(edi + 3608);  // @15_5ae020
  eax = ext_5b07d0_thiscall3(ecx, (u32)(6), (u32)(30));  // @16_5ae020
    // @17_5ae020
  ecx = (u32)(edi + 3608);  // @18_5ae020
  eax = ext_5b07f0_thiscall3(ecx, (u32)(4), (u32)(16));  // @19_5ae020
    // @20_5ae020
  ecx = (u32)(EBP - 24);  // @21_5ae020
  eax = ext_5aedb0_thiscall1(ecx);  // @22_5ae020
    // @23_5ae020
  ecx = (u32)(EBP - 24);  // @24_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(12), (u32)(10));  // @25_5ae020
    // @26_5ae020
  ecx = (u32)(EBP - 24);  // @27_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(13), (u32)(10));  // @28_5ae020
    // @29_5ae020
  ecx = (u32)(EBP - 24);  // @30_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(14), (u32)(1));  // @31_5ae020
    // @32_5ae020
  ecx = (u32)(EBP - 24);  // @33_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(16), (u32)(5));  // @34_5ae020
    // @35_5ae020
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @36_5ae020
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 4), 4); v; });  // @37_5ae020
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 8), 4); v; });  // @38_5ae020
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 12), 4); v; });  // @39_5ae020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @40_5ae020
  ecx = (u32)(edi + 3608);  // @41_5ae020
  edx = 0;  // @42_5ae020
  PV[1] = X0[0];  // @43_5ae020
  PV[2] = X0[1];  // @44_5ae020
  PV[3] = X0[2];  // @45_5ae020
  PV[4] = X0[3];  // @46_5ae020
  PV[5] = eax;  // @47_5ae020
  eax = ext_5b04e0_thiscall6(ecx, PV[1], PV[2], PV[3], PV[4], PV[5]);  // @48_5ae020
  ecx = edx = 0;  // @49_5ae020
  L5ae0d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_5ae020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_5ae020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5ae020
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @54_5ae020
  ecx = edx = 0;  // @55_5ae020
  ecx = (u32)(EBP - 25);  // @56_5ae020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 25), &v, sizeof v); }  // @57_5ae020
  PV[6] = (u32)(ecx);  // @58_5ae020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @59_5ae020
  ecx = eax;  // @60_5ae020
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6977388), PV[6]);  // @61_5ae020
  ecx = edx = 0;  // @62_5ae020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_5ae020
  if (FL[0] == FL[1]) goto L5ae17a;  // @64_5ae020
  ecx = (u32)(edi + 3608);  // @65_5ae020
  eax = ext_5b07d0_thiscall3(ecx, (u32)(6), (u32)(30));  // @66_5ae020
    // @67_5ae020
  ecx = (u32)(edi + 3608);  // @68_5ae020
  eax = ext_5b07f0_thiscall3(ecx, (u32)(4), (u32)(16));  // @69_5ae020
    // @70_5ae020
  ecx = (u32)(EBP - 24);  // @71_5ae020
  eax = ext_5aedb0_thiscall1(ecx);  // @72_5ae020
    // @73_5ae020
  ecx = (u32)(EBP - 24);  // @74_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(12), (u32)(10));  // @75_5ae020
    // @76_5ae020
  ecx = (u32)(EBP - 24);  // @77_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(13), (u32)(10));  // @78_5ae020
    // @79_5ae020
  ecx = (u32)(EBP - 24);  // @80_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(14), (u32)(1));  // @81_5ae020
    // @82_5ae020
  ecx = (u32)(EBP - 24);  // @83_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(16), (u32)(5));  // @84_5ae020
    // @85_5ae020
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @86_5ae020
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 4), 4); v; });  // @87_5ae020
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 8), 4); v; });  // @88_5ae020
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 12), 4); v; });  // @89_5ae020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @90_5ae020
  ecx = (u32)(edi + 3608);  // @91_5ae020
  edx = 0;  // @92_5ae020
  PV[7] = X0[0];  // @93_5ae020
  PV[8] = X0[1];  // @94_5ae020
  PV[9] = X0[2];  // @95_5ae020
  PV[10] = X0[3];  // @96_5ae020
  PV[11] = eax;  // @97_5ae020
  eax = ext_5b04e0_thiscall6(ecx, PV[7], PV[8], PV[9], PV[10], PV[11]);  // @98_5ae020
  ecx = edx = 0;  // @99_5ae020
  L5ae17a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_5ae020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_5ae020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_5ae020
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @104_5ae020
  ecx = edx = 0;  // @105_5ae020
  ecx = (u32)(EBP - 25);  // @106_5ae020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 25), &v, sizeof v); }  // @107_5ae020
  PV[12] = (u32)(ecx);  // @108_5ae020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @109_5ae020
  ecx = eax;  // @110_5ae020
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6989292), PV[12]);  // @111_5ae020
  ecx = edx = 0;  // @112_5ae020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @113_5ae020
  if (FL[0] == FL[1]) goto L5ae211;  // @114_5ae020
  ecx = (u32)(edi + 3608);  // @115_5ae020
  eax = ext_5b07d0_thiscall3(ecx, (u32)(6), (u32)(30));  // @116_5ae020
    // @117_5ae020
  ecx = (u32)(edi + 3608);  // @118_5ae020
  eax = ext_5b07f0_thiscall3(ecx, (u32)(4), (u32)(16));  // @119_5ae020
    // @120_5ae020
  ecx = (u32)(EBP - 24);  // @121_5ae020
  eax = ext_5aedb0_thiscall1(ecx);  // @122_5ae020
    // @123_5ae020
  ecx = (u32)(EBP - 24);  // @124_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(12), (u32)(10));  // @125_5ae020
    // @126_5ae020
  ecx = (u32)(EBP - 24);  // @127_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(13), (u32)(10));  // @128_5ae020
    // @129_5ae020
  ecx = (u32)(EBP - 24);  // @130_5ae020
  eax = ext_5af2a0_thiscall3(ecx, (u32)(16), (u32)(5));  // @131_5ae020
    // @132_5ae020
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @133_5ae020
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 4), 4); v; });  // @134_5ae020
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 8), 4); v; });  // @135_5ae020
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 12), 4); v; });  // @136_5ae020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @137_5ae020
  ecx = (u32)(edi + 3608);  // @138_5ae020
  edx = 0;  // @139_5ae020
  PV[13] = X0[0];  // @140_5ae020
  PV[14] = X0[1];  // @141_5ae020
  PV[15] = X0[2];  // @142_5ae020
  PV[16] = X0[3];  // @143_5ae020
  PV[17] = eax;  // @144_5ae020
  eax = ext_5b04e0_thiscall6(ecx, PV[13], PV[14], PV[15], PV[16], PV[17]);  // @145_5ae020
  ecx = edx = 0;  // @146_5ae020
  L5ae211:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3), sizeof v); (u32)v; }); FL[1] = (u32)(82);  // @148_5ae020
  ecx = (u32)(edi + 3608);  // @149_5ae020
  eax = ext_5b0560_thiscall2(ecx, (u32)(FL[0] != FL[1] ? 1 : 0));  // @150_5ae020 (hand fix: push 0 / push 1 diamond before the shared call)
  ecx = edx = 0;  // @155_5ae020
  ext_633654(G(u32, 0x6f5630));  // @156_5ae020
  return eax;  // @157_5ae020
}
PCREG(5ae020, lifted_5ae020);

extern "C" u32 THISCALL lifted_660cf0(u32 ecx_in) {
  SEH_ENTER(0x66ee2f);  // @h_660cf0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_660cf0
  X1[0] = 0;  // @2_660cf0
  X1[1] = 0;  // @3_660cf0
  X1[2] = 0;  // @4_660cf0
  X1[3] = 0;  // @5_660cf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @6_660cf0
  X0[1] = 0;  // @7_660cf0
  X0[2] = 0;  // @8_660cf0
  X0[3] = 0;  // @9_660cf0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @10_660cf0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @11_660cf0
  if (__builtin_parity(FL[2] & 0xff)) goto L660f2e;  // @12_660cf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @13_660cf0
  X0[1] = 0;  // @14_660cf0
  X0[2] = 0;  // @15_660cf0
  X0[3] = 0;  // @16_660cf0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @17_660cf0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @18_660cf0
  if (__builtin_parity(FL[2] & 0xff)) goto L660f2e;  // @19_660cf0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_660cf0
  if (FL[0] != FL[1]) goto L660f2e;  // @21_660cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_660cf0
  if (FL[0] == FL[1]) goto L660e66;  // @23_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @24_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_660cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7096616), (u32)(130));  // @26_660cf0
  ecx = edx = 0;  // @27_660cf0
  PV[0] = (u32)(eax);  // @28_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @29_660cf0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(7096720));  // @30_660cf0
  ecx = edx = 0;  // @31_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @32_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_660cf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7096616), (u32)(131));  // @34_660cf0
  ecx = edx = 0;  // @35_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @36_660cf0
  ecx = (ecx + (u32)(440));  // @37_660cf0
  FL[3] = ecx;  // @38_660cf0
  PV[1] = (u32)(ecx);  // @39_660cf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @40_660cf0
  PV[2] = (u32)(eax);  // @41_660cf0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[2], (u32)(7096788), PV[1]);  // @42_660cf0
  ecx = edx = 0;  // @43_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @44_660cf0
  FL[2] = (ecx & ecx);  // @45_660cf0
  if (FL[2] == 0) goto L660dbc;  // @46_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @48_660cf0
  ecx = edx = 0;  // @49_660cf0
  L660dbc:;
  eax = ext_41e290_cdecl1((u32)(40));  // @51_660cf0
  ecx = edx = 0;  // @52_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @53_660cf0
  reg.state = (s32)((u32)(0));  // @54_660cf0
  FL[2] = (eax & eax);  // @55_660cf0
  if (FL[2] == 0) goto L660de3;  // @56_660cf0
  ecx = eax;  // @57_660cf0
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(122));  // @58_660cf0
  ecx = edx = 0;  // @59_660cf0
  ecx = eax;  // @60_660cf0
  goto L660de5;  // @61_660cf0
  L660de3:;
  ecx = 0;  // @63_660cf0
  FL[3] = ecx;  // @64_660cf0
  L660de5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @66_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_660cf0
  reg.state = (s32)((u32)(4294967295));  // @68_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @69_660cf0
  ecx = edx = 0;  // @70_660cf0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7096808) + 0), 4); v; });  // @71_660cf0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7096808) + 4), 4); v; });  // @72_660cf0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7096808) + 8), 4); v; });  // @73_660cf0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7096808) + 12), 4); v; });  // @74_660cf0
  __builtin_memcpy((void *)((u32)(eax + 444) + 0), &X0[0], 4);  // @75_660cf0
  __builtin_memcpy((void *)((u32)(eax + 444) + 4), &X0[1], 4);  // @76_660cf0
  __builtin_memcpy((void *)((u32)(eax + 444) + 8), &X0[2], 4);  // @77_660cf0
  __builtin_memcpy((void *)((u32)(eax + 444) + 12), &X0[3], 4);  // @78_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7096824), sizeof v); (u32)v; });  // @79_660cf0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 460), &v, sizeof v); }  // @80_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @81_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @82_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @83_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @84_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @85_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 32), &v, sizeof v); }  // @86_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 36), &v, sizeof v); }  // @87_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 40), &v, sizeof v); }  // @88_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 464), &v, sizeof v); }  // @89_660cf0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @90_660cf0
  SEH_LEAVE();  // @91_660cf0
  return eax;  // @92_660cf0
  L660e66:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @94_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_660cf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @96_660cf0
  ecx = edx = 0;  // @97_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @98_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @99_660cf0
  FL[2] = (ecx & ecx);  // @100_660cf0
  if (FL[2] == 0) goto L660f17;  // @101_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_660cf0
  edx = (u32)(EBP - 28);  // @103_660cf0
  PV[3] = (u32)(edx);  // @104_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @105_660cf0
  ecx = edx = 0;  // @106_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @107_660cf0
  edx = (u32)(EBP - 28);  // @108_660cf0
  PV[4] = (u32)(edx);  // @109_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[4]);  // @111_660cf0
  ecx = edx = 0;  // @112_660cf0
  edx = eax;  // @113_660cf0
  FL[2] = (edx & edx);  // @114_660cf0
  if (FL[2] == 0) goto L660f17;  // @115_660cf0
  L660ea0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @117_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @118_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*8 + 48), &v, sizeof v); }  // @119_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @120_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*8 + 52), &v, sizeof v); }  // @121_660cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 477), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @122_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @123_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @124_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @125_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @126_660cf0
  if (FL[0] == FL[1]) goto L660f3e;  // @127_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @128_660cf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 485), &v, sizeof v); }  // @129_660cf0
  L660edf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 477), &v, sizeof v); }  // @131_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 32), &v, sizeof v); }  // @132_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 36), &v, sizeof v); }  // @133_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 40), &v, sizeof v); }  // @134_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 44), &v, sizeof v); }  // @135_660cf0
  L660f05:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @137_660cf0
  edx = (u32)(EBP - 28);  // @138_660cf0
  PV[5] = (u32)(edx);  // @139_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @141_660cf0
  ecx = edx = 0;  // @142_660cf0
  edx = eax;  // @143_660cf0
  FL[2] = (edx & edx);  // @144_660cf0
  if (FL[2] != 0) goto L660ea0;  // @145_660cf0
  L660f17:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @147_660cf0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @148_660cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(50);  // @149_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @150_660cf0
  if (FL[0] != FL[1]) goto L660f2e;  // @151_660cf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @152_660cf0
  L660f2e:;
  SEH_LEAVE();  // @154_660cf0
  return eax;  // @155_660cf0
  L660f3e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 485), sizeof v); (u32)v; });  // @157_660cf0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @158_660cf0
  if (FL[0] != FL[1]) goto L660edf;  // @159_660cf0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 481), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @160_660cf0
  if (FL[0] != FL[1]) goto L660edf;  // @161_660cf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @162_660cf0
  edx = (u32)(EBP - 28);  // @163_660cf0
  PV[6] = (u32)(edx);  // @164_660cf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_660cf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[6]);  // @166_660cf0
  ecx = edx = 0;  // @167_660cf0
  goto L660f05;  // @168_660cf0
}
PCREG(660cf0, lifted_660cf0);

extern "C" u32 STDCALL lifted_53b380(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
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
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_53b380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_53b380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @2_53b380
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @4_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @5_53b380
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @6_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @7_53b380
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @8_53b380
  FL[2] = (edi & edi);  // @9_53b380
  if (FL[2] == 0) goto L53b5a6;  // @10_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_53b380
  ecx = (u32)(EBP - 52);  // @12_53b380
  PV[0] = (u32)(ecx);  // @13_53b380
  ecx = edi;  // @14_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @15_53b380
  ecx = edx = 0;  // @16_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_53b380
  ecx = (u32)(EBP - 52);  // @18_53b380
  PV[1] = (u32)(ecx);  // @19_53b380
  ecx = edi;  // @20_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @21_53b380
  ecx = edx = 0;  // @22_53b380
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_53b380
  edi = eax;  // @24_53b380
  if (FL[0] == FL[1]) goto L53b5a6;  // @25_53b380
  L53b3e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_53b380
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @28_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @29_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[2]);  // @31_53b380
  ecx = edx = 0;  // @32_53b380
  FL[2] = (eax & eax);  // @33_53b380
  if (FL[2] != 0) goto L53b409;  // @34_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @35_53b380
  edx = (u32)(EBP - 52);  // @36_53b380
  PV[3] = (u32)(edx);  // @37_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[3]);  // @39_53b380
  ecx = edx = 0;  // @40_53b380
  goto L53b58e;  // @41_53b380
  L53b409:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @43_53b380
  eax = ext_4db3b0_thiscall1(ecx);  // @44_53b380
  ecx = edx = 0;  // @45_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @47_53b380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @48_53b380
  ecx = (ecx - (u32)(1));  // @49_53b380
  FL[3] = ecx;  // @50_53b380
  if (FL[3] != 0) goto L53b429;  // @51_53b380
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @52_53b380
  L53b429:;
  FL[2] = (esi & esi);  // @54_53b380
  if (FL[2] == 0) goto L53b4d8;  // @55_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_53b380
  ecx = esi;  // @57_53b380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @58_53b380 (hand fix: the slot takes no arguments)
  ecx = edx = 0;  // @59_53b380
  FL[2] = (eax & eax);  // @60_53b380
  if (FL[2] == 0) goto L53b4d8;  // @61_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_53b380
  ecx = (u32)(EBP - 64);  // @63_53b380
  PV[4] = (u32)(ecx);  // @64_53b380
  ecx = esi;  // @65_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @66_53b380
  ecx = edx = 0;  // @67_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @68_53b380
  ecx = (u32)(EBP - 64);  // @69_53b380
  PV[5] = (u32)(ecx);  // @70_53b380
  ecx = esi;  // @71_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @72_53b380
  ecx = edx = 0;  // @73_53b380
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @74_53b380
  edx = eax;  // @75_53b380
  if (FL[0] == FL[1]) goto L53b58e;  // @76_53b380
  L53b462:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_53b380
  PV[6] = (u32)(edx);  // @79_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @80_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[6]);  // @82_53b380
  ecx = edx = 0;  // @83_53b380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 12) + 0), 4); v; });  // @84_53b380
  X0[1] = 0;  // @85_53b380
  X0[2] = 0;  // @86_53b380
  X0[3] = 0;  // @87_53b380
  esi = eax;  // @88_53b380
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @89_53b380
  eax = (u32)(EBP - 16);  // @90_53b380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 16) + 0), 4); v; });  // @91_53b380
  X0[1] = 0;  // @92_53b380
  X0[2] = 0;  // @93_53b380
  X0[3] = 0;  // @94_53b380
  ecx = esi;  // @95_53b380
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @96_53b380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @97_53b380
  X0[1] = 0;  // @98_53b380
  X0[2] = 0;  // @99_53b380
  X0[3] = 0;  // @100_53b380
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @101_53b380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_53b380
  PV[7] = (u32)(eax);  // @103_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[7]);  // @104_53b380
  ecx = edx = 0;  // @105_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_53b380
  PV[8] = (u32)(ecx);  // @107_53b380
  ecx = (u32)(EBP - 16);  // @108_53b380
  PV[9] = (u32)(ecx);  // @109_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @110_53b380
  ecx = esi;  // @111_53b380
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[9], (u32)(1092616192));  // @112_53b380
  ecx = edx = 0;  // @113_53b380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @114_53b380
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @115_53b380
  if (FL[2] != 0) goto L53b514;  // @116_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_53b380
  ecx = (u32)(EBP - 64);  // @118_53b380
  PV[10] = (u32)(ecx);  // @119_53b380
  ecx = esi;  // @120_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[10]);  // @121_53b380
  ecx = edx = 0;  // @122_53b380
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @123_53b380
  edx = eax;  // @124_53b380
  if (FL[0] != FL[1]) goto L53b462;  // @125_53b380
  goto L53b58e;  // @126_53b380
  L53b4d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @129_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 21246), sizeof v); (u32)v; });  // @130_53b380
  eax = (u32)(edi + 28);  // @131_53b380
  PV[11] = (u32)(eax);  // @132_53b380
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @133_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @134_53b380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_53b380
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @136_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @137_53b380
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; });  // @138_53b380
  eax = (u32)(edi + 12);  // @139_53b380
  PV[15] = (u32)(eax);  // @140_53b380
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @141_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @142_53b380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[16], PV[15], PV[14], PV[13], PV[12], PV[11]);  // @143_53b380
  ecx = edx = 0;  // @144_53b380
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @145_53b380
  if (FL[2] == 0) goto L53b58e;  // @146_53b380
  L53b514:;
  FL[2] = (ebx & ebx);  // @148_53b380
  if (FL[2] == 0) goto L53b554;  // @149_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @150_53b380
  ecx = (u32)(EBP - 76);  // @151_53b380
  PV[17] = (u32)(ecx);  // @152_53b380
  ecx = ebx;  // @153_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @154_53b380
  ecx = edx = 0;  // @155_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @156_53b380
  ecx = (u32)(EBP - 76);  // @157_53b380
  PV[18] = (u32)(ecx);  // @158_53b380
  ecx = ebx;  // @159_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[18]);  // @160_53b380
  ecx = edx = 0;  // @161_53b380
  edx = eax;  // @162_53b380
  FL[2] = (edx & edx);  // @163_53b380
  if (FL[2] == 0) goto L53b554;  // @164_53b380
  L53b534:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_53b380
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @167_53b380
  if (FL[0] != FL[1]) goto L53b543;  // @168_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @169_53b380
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @170_53b380
  if (FL[0] == FL[1]) goto L53b5b9;  // @171_53b380
  L53b543:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @173_53b380
  ecx = (u32)(EBP - 76);  // @174_53b380
  PV[19] = (u32)(ecx);  // @175_53b380
  ecx = ebx;  // @176_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[19]);  // @177_53b380
  ecx = edx = 0;  // @178_53b380
  edx = eax;  // @179_53b380
  FL[2] = (edx & edx);  // @180_53b380
  if (FL[2] != 0) goto L53b534;  // @181_53b380
  L53b554:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @183_53b380
  ecx = ebx;  // @184_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @185_53b380
  ecx = edx = 0;  // @186_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @187_53b380
  edx = eax;  // @188_53b380
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @189_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @190_53b380
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx - 4), &v, sizeof v); }  // @191_53b380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @192_53b380
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @193_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @194_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @195_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @196_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @197_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @198_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @199_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @200_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @201_53b380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @202_53b380
  L53b58e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @204_53b380
  edx = (u32)(EBP - 52);  // @205_53b380
  PV[20] = (u32)(edx);  // @206_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_53b380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[20]);  // @208_53b380
  ecx = edx = 0;  // @209_53b380
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @210_53b380
  edi = eax;  // @211_53b380
  if (FL[0] != FL[1]) goto L53b3e0;  // @212_53b380
  L53b5a6:;
  ext_633654(G(u32, 0x6f5630));  // @214_53b380
  return eax;  // @215_53b380
  L53b5b9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 16) + 0), 4); v; });  // @217_53b380
  X0[1] = 0;  // @218_53b380
  X0[2] = 0;  // @219_53b380
  X0[3] = 0;  // @220_53b380
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; }))))))) goto L53b58e;  // @221_53b380
  eax = ecx;  // @222_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @223_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @224_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @225_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @226_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @227_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @228_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @229_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @230_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @231_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @232_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @233_53b380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @234_53b380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @235_53b380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @236_53b380
  goto L53b58e;  // @237_53b380
}
PCREG(53b380, lifted_53b380);

extern "C" u32 THISCALL lifted_5ef950(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5ef950
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @1_5ef950
  X0[1] = 0;  // @2_5ef950
  X0[2] = 0;  // @3_5ef950
  X0[3] = 0;  // @4_5ef950
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_5ef950
  edi = ecx;  // @6_5ef950
  PV[0] = (u32)(eax);  // @7_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 169), sizeof v); (u32)v; });  // @8_5ef950
  __builtin_memcpy((void *)((u32)(edi + 148) + 0), &X0[0], 4);  // @9_5ef950
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @10_5ef950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 136), &v, sizeof v); }  // @11_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 173), &v, sizeof v); }  // @12_5ef950
  eax = ext_5ac940_thiscall2(ecx, PV[0]);  // @13_5ef950
    // @14_5ef950
  ecx = (u32)(esi + 1);  // @15_5ef950
  L5ef990:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @17_5ef950
  esi = (esi + 1);  // @18_5ef950
  FL[3] = esi;  // @19_5ef950
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @20_5ef950
  if (FL[2] != 0) goto L5ef990;  // @21_5ef950
  esi = (esi - ecx);  // @22_5ef950
  FL[3] = esi;  // @23_5ef950
  ecx = (u32)(EBP - 44);  // @24_5ef950
  eax = (u32)(esi - 1);  // @25_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @26_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @27_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @28_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @29_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @30_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @31_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @32_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @33_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @34_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @35_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @36_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @37_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @38_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @39_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @40_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @41_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @42_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @43_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @44_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @45_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 88), &v, sizeof v); }  // @46_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @47_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @48_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @49_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @50_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 108), &v, sizeof v); }  // @51_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 112), &v, sizeof v); }  // @52_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 116), &v, sizeof v); }  // @53_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 120), &v, sizeof v); }  // @54_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 124), &v, sizeof v); }  // @55_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 128), &v, sizeof v); }  // @56_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @57_5ef950
  eax = (u32)(32);  // @58_5ef950
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @59_5ef950
  eax = (u32)(EBP + 12);  // @60_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @61_5ef950
  ecx = (u32)(EBP - 44); eax = ext_4cc500_fastcall2(ecx, edx);  // @62_5ef950 (hand fix: thiscall on the tokenizer state, no stack arguments)
  ecx = edx = 0;  // @63_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @64_5ef950
  edx = 0;  // @65_5ef950
  FL[3] = edx;  // @66_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @67_5ef950
  ebx = 0;  // @68_5ef950
  FL[3] = ebx;  // @69_5ef950
  eax = (u32)(1);  // @70_5ef950
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @71_5ef950
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @72_5ef950
  esi = 0;  // @73_5ef950
  FL[3] = esi;  // @74_5ef950
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @75_5ef950
  edx = (u32)(ecx + 1);  // @76_5ef950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @77_5ef950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @78_5ef950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @79_5ef950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @80_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @81_5ef950
  L5efa51:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @83_5ef950
  ecx = (ecx + 1);  // @84_5ef950
  FL[3] = ecx;  // @85_5ef950
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @86_5ef950
  if (FL[2] != 0) goto L5efa51;  // @87_5ef950
  ecx = (ecx - edx);  // @88_5ef950
  FL[3] = ecx;  // @89_5ef950
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @90_5ef950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @91_5ef950
  ecx = (u32)(EBP - 40);  // @92_5ef950
  eax = ext_4cc500_fastcall2(ecx, edx);  // @93_5ef950
  ecx = edx = 0;  // @94_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @95_5ef950
  FL[2] = (eax & eax);  // @96_5ef950
  if (FL[2] == 0) goto L5efbeb;  // @97_5ef950
  ecx = (u32)(edi + 12);  // @98_5ef950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @99_5ef950
  L5efa80:;
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @101_5ef950
  if (FL[0] != FL[1]) goto L5efa8e;  // @102_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @103_5ef950
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @104_5ef950
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @105_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @106_5ef950
  L5efa8e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; });  // @108_5ef950
  eax = ext_5ab950_thiscall1(ecx);  // @109_5ef950
  ecx = edx = 0;  // @110_5ef950
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @111_5ef950
  ecx = eax;  // @112_5ef950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @113_5ef950
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 640)))(ecx, PV[1]);  // @114_5ef950
  ecx = edx = 0;  // @115_5ef950
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }));  // @116_5ef950
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @117_5ef950
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @118_5ef950
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_5ef950
  if (FL[0] == FL[1]) goto L5efad1;  // @120_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; });  // @121_5ef950
  eax = ext_5ab950_thiscall1(ecx);  // @122_5ef950
  ecx = edx = 0;  // @123_5ef950
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @124_5ef950
  ecx = eax;  // @125_5ef950
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @126_5ef950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @127_5ef950
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 652)))(ecx, PV[3], PV[2]);  // @128_5ef950
  ecx = edx = 0;  // @129_5ef950
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @130_5ef950
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @131_5ef950
  L5efad1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @133_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @134_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @135_5ef950
  ecx = (ecx + ecx);  // @136_5ef950
  FL[3] = ecx;  // @137_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_5ef950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @139_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @140_5ef950
  edx = (edx - ecx);  // @141_5ef950
  FL[3] = edx;  // @142_5ef950
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @143_5ef950
  FL[3] = eax;  // @144_5ef950
  FL[0] = eax; FL[1] = edx;  // @145_5ef950
  if ((s32)FL[0] <= (s32)FL[1]) goto L5efb3d;  // @146_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @147_5ef950
  FL[0] = esi; FL[1] = ecx;  // @148_5ef950
  if ((s32)FL[0] >= (s32)FL[1]) goto L5efb3d;  // @149_5ef950
  L5efb00:;
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @151_5ef950
  if ((s32)FL[0] >= (s32)FL[1]) goto L5efb19;  // @152_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @153_5ef950
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @154_5ef950
  if (FL[0] != FL[1]) goto L5efb12;  // @155_5ef950
  ebx = (ebx + 1);  // @156_5ef950
  FL[3] = ebx;  // @157_5ef950
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @158_5ef950
  L5efb12:;
  esi = (esi + 1);  // @160_5ef950
  FL[3] = esi;  // @161_5ef950
  FL[0] = esi; FL[1] = ecx;  // @162_5ef950
  if ((s32)FL[0] < (s32)FL[1]) goto L5efb00;  // @163_5ef950
  goto L5efb3d;  // @164_5ef950
  L5efb19:;
  FL[0] = esi; FL[1] = ecx;  // @166_5ef950
  if ((s32)FL[0] >= (s32)FL[1]) goto L5efb3d;  // @167_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @168_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @169_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @170_5ef950
  FL[0] = eax; FL[1] = (u32)(32);  // @171_5ef950
  if ((s32)FL[0] >= (s32)FL[1]) goto L5efb3d;  // @172_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @173_5ef950
  eax = (eax + 1);  // @174_5ef950
  FL[3] = eax;  // @175_5ef950
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @176_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @177_5ef950
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @178_5ef950
  ecx = (ecx + (u32)(4));  // @179_5ef950
  FL[3] = ecx;  // @180_5ef950
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @181_5ef950
  L5efb3d:;
  ecx = (u32)(EBP - 40);  // @183_5ef950
  eax = ext_4cc500_fastcall2(ecx, edx);  // @184_5ef950
  ecx = edx = 0;  // @185_5ef950
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @186_5ef950
  FL[2] = (eax & eax);  // @187_5ef950
  if (FL[2] != 0) goto L5efa80;  // @188_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @189_5ef950
  FL[0] = eax; FL[1] = (u32)(2);  // @190_5ef950
  if ((s32)FL[0] <= (s32)FL[1]) goto L5efbeb;  // @191_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @192_5ef950
  esi = ecx;  // @193_5ef950
  FL[2] = ((eax & 0xff) & (u32)(1));  // @194_5ef950
  if (FL[2] == 0) goto L5efb71;  // @195_5ef950
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; }));  // @196_5ef950
  FL[3] = esi;  // @197_5ef950
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @198_5ef950
  eax = (eax - edx);  // @199_5ef950
  FL[3] = eax;  // @200_5ef950
  eax = (u32)((s32)eax >> (u32)(1));  // @201_5ef950
  FL[3] = eax;  // @202_5ef950
  eax = (eax + 1);  // @203_5ef950
  FL[3] = eax;  // @204_5ef950
  goto L5efb79;  // @205_5ef950
  L5efb71:;
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; }));  // @207_5ef950
  FL[3] = esi;  // @208_5ef950
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @209_5ef950
  eax = (eax - edx);  // @210_5ef950
  FL[3] = eax;  // @211_5ef950
  eax = (u32)((s32)eax >> (u32)(1));  // @212_5ef950
  FL[3] = eax;  // @213_5ef950
  L5efb79:;
  X1[0] = esi; X1[1] = X1[2] = X1[3] = 0;  // @215_5ef950
  eax = (eax - 1);  // @216_5ef950
  FL[3] = eax;  // @217_5ef950
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @218_5ef950
  X1[0] = F2U((float)(s32)X1[0]);  // @219_5ef950
  X1[1] = F2U((float)(s32)X1[1]);  // @220_5ef950
  X1[2] = F2U((float)(s32)X1[2]);  // @221_5ef950
  X1[3] = F2U((float)(s32)X1[3]);  // @222_5ef950
  X0[0] = F2U((float)(s32)X0[0]);  // @223_5ef950
  X0[1] = F2U((float)(s32)X0[1]);  // @224_5ef950
  X0[2] = F2U((float)(s32)X0[2]);  // @225_5ef950
  X0[3] = F2U((float)(s32)X0[3]);  // @226_5ef950
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @227_5ef950
  X4[1] = 0;  // @228_5ef950
  X4[2] = 0;  // @229_5ef950
  X4[3] = 0;  // @230_5ef950
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @231_5ef950
  X3[0] = eax; X3[1] = X3[2] = X3[3] = 0;  // @232_5ef950
  X2[0] = X4[0];  // @233_5ef950
  X2[1] = X4[1];  // @234_5ef950
  X2[2] = X4[2];  // @235_5ef950
  X2[3] = X4[3];  // @236_5ef950
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @237_5ef950
  X3[0] = F2U((float)(s32)X3[0]);  // @238_5ef950
  X3[1] = F2U((float)(s32)X3[1]);  // @239_5ef950
  X3[2] = F2U((float)(s32)X3[2]);  // @240_5ef950
  X3[3] = F2U((float)(s32)X3[3]);  // @241_5ef950
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @242_5ef950
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @243_5ef950
  X0[1] = 0;  // @244_5ef950
  X0[2] = 0;  // @245_5ef950
  X0[3] = 0;  // @246_5ef950
  X2[0] = F2U(U2F(X2[0]) / U2F(X3[0]));  // @247_5ef950
  __builtin_memcpy((void *)((u32)(edi + 148) + 0), &X2[0], 4);  // @248_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @249_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @250_5ef950
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5efbdd;  // @251_5ef950
  X2[0] = F2U(U2F(X2[0]) * U2F(X3[0]));  // @252_5ef950
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @253_5ef950
  { float f_ = U2F(X2[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @254_5ef950
  eax = (eax - ecx);  // @255_5ef950
  FL[3] = eax;  // @256_5ef950
  eax = (eax + (u32)(2048));  // @257_5ef950
  FL[3] = eax;  // @258_5ef950
  goto L5efc0e;  // @259_5ef950
  L5efbdd:;
  X4[0] = F2U(U2F(X4[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @261_5ef950
  { float f_ = U2F(X4[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @262_5ef950
  goto L5efc0c;  // @263_5ef950
  L5efbeb:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @265_5ef950
  X0[1] = 0;  // @266_5ef950
  X0[2] = 0;  // @267_5ef950
  X0[3] = 0;  // @268_5ef950
  __builtin_memcpy((void *)((u32)(edi + 148) + 0), &X0[0], 4);  // @269_5ef950
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @270_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @271_5ef950
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @272_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @273_5ef950
  L5efc0c:;
  eax = (eax - ecx);  // @275_5ef950
  FL[3] = eax;  // @276_5ef950
  L5efc0e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; });  // @278_5ef950
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @279_5ef950
  X0[0] = F2U((float)(s32)X0[0]);  // @280_5ef950
  X0[1] = F2U((float)(s32)X0[1]);  // @281_5ef950
  X0[2] = F2U((float)(s32)X0[2]);  // @282_5ef950
  X0[3] = F2U((float)(s32)X0[3]);  // @283_5ef950
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @284_5ef950
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @285_5ef950
  __builtin_memcpy((void *)((u32)(edi + 152) + 0), &X0[0], 4);  // @286_5ef950
  eax = ext_5acac0_thiscall2(ecx, (u32)(1));  // @287_5ef950
    // @288_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; });  // @289_5ef950
  eax = ext_5acac0_thiscall2(ecx, (u32)(1));  // @290_5ef950
    // @291_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 177), sizeof v); (u32)v; });  // @292_5ef950
  FL[2] = (eax & eax);  // @293_5ef950
  if (FL[2] == 0) goto L5efc57;  // @294_5ef950
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @295_5ef950
  L5efc57:;
  ecx = edi;  // @297_5ef950
  eax = ext_5ef240_thiscall1(ecx);  // @298_5ef950
  ecx = edx = 0;  // @299_5ef950
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 148) + 0), 4); v; });  // @300_5ef950
  X0[1] = 0;  // @301_5ef950
  X0[2] = 0;  // @302_5ef950
  X0[3] = 0;  // @303_5ef950
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @304_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @305_5ef950
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @306_5ef950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @307_5ef950
  eax = (eax - ecx);  // @308_5ef950
  FL[3] = eax;  // @309_5ef950
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 173), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @310_5ef950
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @311_5ef950
  X0[0] = F2U((float)(s32)X0[0]);  // @312_5ef950
  X0[1] = F2U((float)(s32)X0[1]);  // @313_5ef950
  X0[2] = F2U((float)(s32)X0[2]);  // @314_5ef950
  X0[3] = F2U((float)(s32)X0[3]);  // @315_5ef950
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @316_5ef950
  __builtin_memcpy((void *)((u32)(edi + 156) + 0), &X0[0], 4);  // @317_5ef950
  if (FL[0] == FL[1]) goto L5efca9;  // @318_5ef950
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 169), sizeof v); (u32)v; });  // @319_5ef950
  eax = ext_5acac0_thiscall2(ecx, (u32)(1));  // @320_5ef950
    // @321_5ef950
  L5efca9:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 160), &v, sizeof v); }  // @323_5ef950
  return eax;  // @324_5ef950
}
PCREG(5ef950, lifted_5ef950);

extern "C" u32 THISCALL lifted_5ae940(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5ae940
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }));  // @1_5ae940
  eax = (eax + (u32)(-50));  // @2_5ae940
  FL[3] = eax;  // @3_5ae940
  FL[0] = eax; FL[1] = (u32)(6);  // @4_5ae940
  if (FL[0] > FL[1]) goto L5aed75;  // @5_5ae940
  switch (eax) {  // @6_5ae940
  case 0: goto L5ae95e;  // @7_5ae940
  case 1: goto L5aea44;  // @8_5ae940
  case 2: goto L5aeac8;  // @9_5ae940
  case 3: goto L5aeb91;  // @10_5ae940
  case 4: goto L5aed74;  // @11_5ae940
  case 5: goto L5aebe7;  // @12_5ae940
  case 6: goto L5aec54;  // @13_5ae940
  default: __builtin_trap(); }  // @14_5ae940
  L5ae95e:;
  esi = (u32)(ecx + 146);  // @16_5ae940
  ecx = esi;  // @17_5ae940
  { u32 v = (u32)((u32)(7014904)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @18_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7014916), (u32)(7013468), (u32)(1), (u32)(7013368), (u32)(0));  // @19_5ae940
  ecx = edx = 0;  // @20_5ae940
  ecx = esi;  // @21_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7014940), (u32)(7013468), (u32)(1), (u32)(7013368), (u32)(0));  // @22_5ae940
  ecx = edx = 0;  // @23_5ae940
  ecx = esi;  // @24_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7014964), (u32)(7013368), (u32)(0), (u32)(0), (u32)(0));  // @25_5ae940
  ecx = edx = 0;  // @26_5ae940
  ecx = esi;  // @27_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7014984), (u32)(7013468), (u32)(0), (u32)(0), (u32)(0));  // @28_5ae940
  ecx = edx = 0;  // @29_5ae940
  ecx = esi;  // @30_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015004), (u32)(7013468), (u32)(0), (u32)(0), (u32)(0));  // @31_5ae940
  ecx = edx = 0;  // @32_5ae940
  ecx = esi;  // @33_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015024), (u32)(7013404), (u32)(0), (u32)(0), (u32)(0));  // @34_5ae940
  ecx = edx = 0;  // @35_5ae940
  ecx = esi;  // @36_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015048), (u32)(7013404), (u32)(0), (u32)(0), (u32)(0));  // @37_5ae940
  ecx = edx = 0;  // @38_5ae940
  ecx = esi;  // @39_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015076), (u32)(7013468), (u32)(0), (u32)(0), (u32)(0));  // @40_5ae940
  ecx = edx = 0;  // @41_5ae940
  ecx = esi;  // @42_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015096), (u32)(7013368), (u32)(0), (u32)(0), (u32)(0));  // @43_5ae940
  ecx = edx = 0;  // @44_5ae940
  return eax;  // @45_5ae940
  L5aea44:;
  esi = (u32)(ecx + 146);  // @47_5ae940
  ecx = esi;  // @48_5ae940
  { u32 v = (u32)((u32)(7015116)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @49_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015128), (u32)(7013572), (u32)(0), (u32)(0), (u32)(0));  // @50_5ae940
  ecx = edx = 0;  // @51_5ae940
  ecx = esi;  // @52_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7013548), (u32)(7013572), (u32)(0), (u32)(0), (u32)(0));  // @53_5ae940
  ecx = edx = 0;  // @54_5ae940
  ecx = esi;  // @55_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015156), (u32)(7013664), (u32)(0), (u32)(0), (u32)(0));  // @56_5ae940
  ecx = edx = 0;  // @57_5ae940
  ecx = esi;  // @58_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7013772), (u32)(7015180), (u32)(0), (u32)(0), (u32)(0));  // @59_5ae940
  ecx = edx = 0;  // @60_5ae940
  ecx = esi;  // @61_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7013584), (u32)(7013536), (u32)(0), (u32)(0), (u32)(0));  // @62_5ae940
  ecx = edx = 0;  // @63_5ae940
  return eax;  // @64_5ae940
  L5aeac8:;
  esi = (u32)(ecx + 146);  // @66_5ae940
  ecx = esi;  // @67_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015196), (u32)(7013820), (u32)(0), (u32)(0), (u32)(0));  // @68_5ae940
  ecx = edx = 0;  // @69_5ae940
  ecx = esi;  // @70_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015220), (u32)(7013888), (u32)(0), (u32)(0), (u32)(0));  // @71_5ae940
  ecx = edx = 0;  // @72_5ae940
  ecx = esi;  // @73_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015244), (u32)(7014008), (u32)(0), (u32)(0), (u32)(0));  // @74_5ae940
  ecx = edx = 0;  // @75_5ae940
  ecx = esi;  // @76_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015268), (u32)(7014044), (u32)(0), (u32)(0), (u32)(0));  // @77_5ae940
  ecx = edx = 0;  // @78_5ae940
  ecx = esi;  // @79_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015292), (u32)(7013832), (u32)(0), (u32)(0), (u32)(0));  // @80_5ae940
  ecx = edx = 0;  // @81_5ae940
  ecx = esi;  // @82_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015316), (u32)(7013900), (u32)(0), (u32)(0), (u32)(0));  // @83_5ae940
  ecx = edx = 0;  // @84_5ae940
  ecx = esi;  // @85_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015344), (u32)(7013988), (u32)(0), (u32)(0), (u32)(0));  // @86_5ae940
  ecx = edx = 0;  // @87_5ae940
  ecx = esi;  // @88_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015372), (u32)(7013832), (u32)(0), (u32)(0), (u32)(0));  // @89_5ae940
  ecx = edx = 0;  // @90_5ae940
  { u32 v = (u32)((u32)(7015400)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @91_5ae940
  return eax;  // @92_5ae940
  L5aeb91:;
  esi = (u32)(ecx + 146);  // @94_5ae940
  ecx = esi;  // @95_5ae940
  { u32 v = (u32)((u32)(7015412)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @96_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015424), (u32)(7014100), (u32)(0), (u32)(0), (u32)(0));  // @97_5ae940
  ecx = edx = 0;  // @98_5ae940
  ecx = esi;  // @99_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015452), (u32)(7014100), (u32)(0), (u32)(0), (u32)(0));  // @100_5ae940
  ecx = edx = 0;  // @101_5ae940
  ecx = esi;  // @102_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015480), (u32)(7014100), (u32)(0), (u32)(0), (u32)(0));  // @103_5ae940
  ecx = edx = 0;  // @104_5ae940
  return eax;  // @105_5ae940
  L5aebe7:;
  esi = (u32)(ecx + 146);  // @107_5ae940
  ecx = esi;  // @108_5ae940
  { u32 v = (u32)((u32)(7015504)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @109_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015536), (u32)(7015516), (u32)(0), (u32)(0), (u32)(0));  // @110_5ae940
  ecx = edx = 0;  // @111_5ae940
  ecx = esi;  // @112_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015560), (u32)(7003232), (u32)(0), (u32)(0), (u32)(0));  // @113_5ae940
  ecx = edx = 0;  // @114_5ae940
  ecx = esi;  // @115_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015588), (u32)(7014296), (u32)(0), (u32)(0), (u32)(0));  // @116_5ae940
  ecx = edx = 0;  // @117_5ae940
  ecx = esi;  // @118_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015624), (u32)(7015612), (u32)(0), (u32)(0), (u32)(0));  // @119_5ae940
  ecx = edx = 0;  // @120_5ae940
  return eax;  // @121_5ae940
  L5aec54:;
  esi = (u32)(ecx + 146);  // @123_5ae940
  ecx = esi;  // @124_5ae940
  { u32 v = (u32)((u32)(7015644)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @125_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015656), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @126_5ae940
  ecx = edx = 0;  // @127_5ae940
  ecx = esi;  // @128_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015684), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @129_5ae940
  ecx = edx = 0;  // @130_5ae940
  ecx = esi;  // @131_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015712), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @132_5ae940
  ecx = edx = 0;  // @133_5ae940
  ecx = esi;  // @134_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015736), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @135_5ae940
  ecx = edx = 0;  // @136_5ae940
  ecx = esi;  // @137_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015760), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @138_5ae940
  ecx = edx = 0;  // @139_5ae940
  ecx = esi;  // @140_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015784), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @141_5ae940
  ecx = edx = 0;  // @142_5ae940
  ecx = esi;  // @143_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015808), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @144_5ae940
  ecx = edx = 0;  // @145_5ae940
  ecx = esi;  // @146_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015832), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @147_5ae940
  ecx = edx = 0;  // @148_5ae940
  ecx = esi;  // @149_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015832), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @150_5ae940
  ecx = edx = 0;  // @151_5ae940
  ecx = esi;  // @152_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015856), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @153_5ae940
  ecx = edx = 0;  // @154_5ae940
  ecx = esi;  // @155_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015880), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @156_5ae940
  ecx = edx = 0;  // @157_5ae940
  ecx = esi;  // @158_5ae940
  eax = ext_5c2b00_thiscall6(ecx, (u32)(7015904), (u32)(6978456), (u32)(0), (u32)(0), (u32)(0));  // @159_5ae940
  ecx = edx = 0;  // @160_5ae940
  L5aed74:;
  L5aed75:;
  return eax;  // @163_5ae940
}
PCREG(5ae940, lifted_5ae940);

extern "C" u32 THISCALL lifted_5b4b40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 w4a_cmp_1b40 = 0; u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5b4b40
  esi = ecx;  // @1_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @2_5b4b40
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 303), sizeof v); (u32)v; });  // @3_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @5_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[0], (u32)(0));  // @6_5b4b40
  ecx = edx = 0;  // @7_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @8_5b4b40
  if (FL[2] == 0) goto L5b4bad;  // @9_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @12_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7019284));  // @14_5b4b40
  ecx = edx = 0;  // @15_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @16_5b4b40
  PV[1] = (u32)(eax);  // @17_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @18_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[1], (u32)(4294967040), (u32)(1));  // @19_5b4b40
  ecx = edx = 0;  // @20_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @21_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @22_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 8931), &v, sizeof v); }  // @23_5b4b40
  L5b4bad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_5b4b40
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 307), sizeof v); (u32)v; });  // @26_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @27_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @29_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[2], (u32)(0));  // @30_5b4b40
  ecx = edx = 0;  // @31_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @32_5b4b40
  if (FL[2] == 0) goto L5b4c13;  // @33_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @36_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7019324));  // @38_5b4b40
  ecx = edx = 0;  // @39_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @40_5b4b40
  PV[3] = (u32)(eax);  // @41_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @42_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[3], (u32)(4294967040), (u32)(1));  // @43_5b4b40
  ecx = edx = 0;  // @44_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @45_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @46_5b4b40
  { u32 v = (u32)((u32)(1073741824)); __builtin_memcpy((void *)(u32)(eax + 8931), &v, sizeof v); }  // @47_5b4b40
  L5b4c13:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_5b4b40
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 311), sizeof v); (u32)v; });  // @50_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @51_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @53_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[4], (u32)(0));  // @54_5b4b40
  ecx = edx = 0;  // @55_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @56_5b4b40
  if (FL[2] == 0) goto L5b4c79;  // @57_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @59_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @60_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7019368));  // @62_5b4b40
  ecx = edx = 0;  // @63_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @64_5b4b40
  PV[5] = (u32)(eax);  // @65_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @66_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[5], (u32)(4294967040), (u32)(1));  // @67_5b4b40
  ecx = edx = 0;  // @68_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @69_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @70_5b4b40
  { u32 v = (u32)((u32)(1077936128)); __builtin_memcpy((void *)(u32)(eax + 8931), &v, sizeof v); }  // @71_5b4b40
  L5b4c79:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_5b4b40
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 315), sizeof v); (u32)v; });  // @74_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @75_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @77_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[6], (u32)(0));  // @78_5b4b40
  ecx = edx = 0;  // @79_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @80_5b4b40
  if (FL[2] == 0) goto L5b4cdf;  // @81_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @83_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @84_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7019404));  // @86_5b4b40
  ecx = edx = 0;  // @87_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @88_5b4b40
  PV[7] = (u32)(eax);  // @89_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @90_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[7], (u32)(4294967040), (u32)(1));  // @91_5b4b40
  ecx = edx = 0;  // @92_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @93_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @94_5b4b40
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)(eax + 8931), &v, sizeof v); }  // @95_5b4b40
  L5b4cdf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @97_5b4b40
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 319), sizeof v); (u32)v; });  // @98_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @99_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @101_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[8], (u32)(0));  // @102_5b4b40
  ecx = edx = 0;  // @103_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @104_5b4b40
  if (FL[2] == 0) goto L5b4d45;  // @105_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @107_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @108_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020672));  // @110_5b4b40
  ecx = edx = 0;  // @111_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @112_5b4b40
  PV[9] = (u32)(eax);  // @113_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @114_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[9], (u32)(4294967040), (u32)(1));  // @115_5b4b40
  ecx = edx = 0;  // @116_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @117_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @118_5b4b40
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(eax + 8931), &v, sizeof v); }  // @119_5b4b40
  L5b4d45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_5b4b40
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 327), sizeof v); (u32)v; });  // @122_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @123_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @125_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[10], (u32)(0));  // @126_5b4b40
  ecx = edx = 0;  // @127_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @128_5b4b40
  if (FL[2] == 0) goto L5b4def;  // @129_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @130_5b4b40
  w4a_cmp_1b40 = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 6976) + 0), 4); v; });  // hand fix: comiss operand is read before eax is reused
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @131_5b4b40
  X0[1] = 0;  // @132_5b4b40
  X0[2] = 0;  // @133_5b4b40
  X0[3] = 0;  // @134_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @135_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @136_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_5b4b40
  if ((!(U2F(X0[0]) >= U2F(w4a_cmp_1b40)))) goto L5b4dbe;  // @138_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020680));  // @139_5b4b40
  ecx = edx = 0;  // @140_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @141_5b4b40
  PV[11] = (u32)(eax);  // @142_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @143_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[11], (u32)(4294967040), (u32)(1));  // @144_5b4b40
  ecx = edx = 0;  // @145_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_5b4b40
  { u32 v = (u32)((u32)(1073741824)); __builtin_memcpy((void *)(u32)(eax + 6976), &v, sizeof v); }  // @147_5b4b40
  goto L5b4def;  // @148_5b4b40
  L5b4dbe:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020692));  // @150_5b4b40
  ecx = edx = 0;  // @151_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @152_5b4b40
  PV[12] = (u32)(eax);  // @153_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @154_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[12], (u32)(4294967040), (u32)(1));  // @155_5b4b40
  ecx = edx = 0;  // @156_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @157_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 6976), &v, sizeof v); }  // @158_5b4b40
  L5b4def:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @160_5b4b40
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 323), sizeof v); (u32)v; });  // @161_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @162_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @164_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[13], (u32)(0));  // @165_5b4b40
  ecx = edx = 0;  // @166_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @167_5b4b40
  if (FL[2] == 0) goto L5b4e99;  // @168_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_5b4b40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 6976) + 0), 4); v; });  // @170_5b4b40
  X0[1] = 0;  // @171_5b4b40
  X0[2] = 0;  // @172_5b4b40
  X0[3] = 0;  // @173_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @174_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @175_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_5b4b40
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))) goto L5b4e68;  // @177_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020704));  // @178_5b4b40
  ecx = edx = 0;  // @179_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @180_5b4b40
  PV[14] = (u32)(eax);  // @181_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @182_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[14], (u32)(4294967040), (u32)(1));  // @183_5b4b40
  ecx = edx = 0;  // @184_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @185_5b4b40
  { u32 v = (u32)((u32)(1045220557)); __builtin_memcpy((void *)(u32)(eax + 6976), &v, sizeof v); }  // @186_5b4b40
  goto L5b4e99;  // @187_5b4b40
  L5b4e68:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020716));  // @189_5b4b40
  ecx = edx = 0;  // @190_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @191_5b4b40
  PV[15] = (u32)(eax);  // @192_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @193_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[15], (u32)(4294967040), (u32)(1));  // @194_5b4b40
  ecx = edx = 0;  // @195_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @196_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 6976), &v, sizeof v); }  // @197_5b4b40
  L5b4e99:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @199_5b4b40
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 331), sizeof v); (u32)v; });  // @200_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @201_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @202_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @203_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[16], (u32)(0));  // @204_5b4b40
  ecx = edx = 0;  // @205_5b4b40
  X1[0] = 0;  // @206_5b4b40
  X1[1] = 0;  // @207_5b4b40
  X1[2] = 0;  // @208_5b4b40
  X1[3] = 0;  // @209_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @210_5b4b40
  if (FL[2] == 0) goto L5b4f4a;  // @211_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @212_5b4b40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1196), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @213_5b4b40
  if (FL[0] == FL[1]) goto L5b4f4a;  // @214_5b4b40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7340836) + 0), 4); v; });  // @215_5b4b40
  X0[1] = 0;  // @216_5b4b40
  X0[2] = 0;  // @217_5b4b40
  X0[3] = 0;  // @218_5b4b40
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @219_5b4b40
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @220_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @221_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @222_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @223_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_5b4b40
  if (__builtin_parity(FL[2] & 0xff)) goto L5b4f1e;  // @225_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020728));  // @226_5b4b40
  ecx = edx = 0;  // @227_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @228_5b4b40
  PV[17] = (u32)(eax);  // @229_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @230_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[17], (u32)(4294967040), (u32)(1));  // @231_5b4b40
  ecx = edx = 0;  // @232_5b4b40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340836), &v, sizeof v); }  // @233_5b4b40
  goto L5b4f4a;  // @234_5b4b40
  L5b4f1e:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020740));  // @236_5b4b40
  ecx = edx = 0;  // @237_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @238_5b4b40
  PV[18] = (u32)(eax);  // @239_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @240_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[18], (u32)(4294967040), (u32)(1));  // @241_5b4b40
  ecx = edx = 0;  // @242_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(7340836), &v, sizeof v); }  // @243_5b4b40
  L5b4f4a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @245_5b4b40
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 335), sizeof v); (u32)v; });  // @246_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @247_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @248_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @249_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[19], (u32)(0));  // @250_5b4b40
  ecx = edx = 0;  // @251_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @252_5b4b40
  if (FL[2] == 0) goto L5b4fef;  // @253_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @254_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @255_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @256_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @257_5b4b40
  ecx = edx = 0;  // @258_5b4b40
  ecx = (u32)(EBP - 4);  // @259_5b4b40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @260_5b4b40
  PV[20] = (u32)(ecx);  // @261_5b4b40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @262_5b4b40
  ecx = eax;  // @263_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(7020748), PV[20]);  // @264_5b4b40
  ecx = edx = 0;  // @265_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @266_5b4b40
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @267_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_5b4b40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[21]);  // @269_5b4b40
  ecx = edx = 0;  // @270_5b4b40
  edi = eax;  // @271_5b4b40
  FL[2] = (edi & edi);  // @272_5b4b40
  if (FL[2] == 0) goto L5b4fee;  // @273_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @274_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @275_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @276_5b4b40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @277_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(7020660), (u32)(7019624));  // @278_5b4b40
  ecx = edx = 0;  // @279_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @280_5b4b40
  PV[22] = (u32)(eax);  // @281_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @282_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[22], (u32)(4294967040), (u32)(1));  // @283_5b4b40
  ecx = edx = 0;  // @284_5b4b40
  ecx = edi;  // @285_5b4b40
  eax = ext_5c4290_thiscall1(ecx);  // @286_5b4b40
  ecx = edx = 0;  // @287_5b4b40
  L5b4fee:;
  L5b4fef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @290_5b4b40
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 339), sizeof v); (u32)v; });  // @291_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @292_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @293_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @294_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[23], (u32)(0));  // @295_5b4b40
  ecx = edx = 0;  // @296_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @297_5b4b40
  if (FL[2] == 0) goto L5b5054;  // @298_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @299_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @300_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @301_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @302_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7019664));  // @303_5b4b40
  ecx = edx = 0;  // @304_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @305_5b4b40
  PV[24] = (u32)(eax);  // @306_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @307_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[24], (u32)(4294967040), (u32)(1));  // @308_5b4b40
  ecx = edx = 0;  // @309_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @310_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @311_5b4b40
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 2988), &v, sizeof v); }  // @312_5b4b40
  L5b5054:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @314_5b4b40
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 343), sizeof v); (u32)v; });  // @315_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @316_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @317_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @318_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[25], (u32)(0));  // @319_5b4b40
  ecx = edx = 0;  // @320_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @321_5b4b40
  if (FL[2] == 0) goto L5b50b7;  // @322_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @323_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @324_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @325_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @326_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7001404));  // @327_5b4b40
  ecx = edx = 0;  // @328_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @329_5b4b40
  PV[26] = (u32)(eax);  // @330_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @331_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[26], (u32)(4294967040), (u32)(1));  // @332_5b4b40
  ecx = edx = 0;  // @333_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @334_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @335_5b4b40
  eax = ext_596d30_thiscall2(ecx, (u32)(12));  // @336_5b4b40
  ecx = edx = 0;  // @337_5b4b40
  L5b50b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @339_5b4b40
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 347), sizeof v); (u32)v; });  // @340_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @341_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @342_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @343_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[27], (u32)(0));  // @344_5b4b40
  ecx = edx = 0;  // @345_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @346_5b4b40
  if (FL[2] == 0) goto L5b5186;  // @347_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @348_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @349_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @351_5b4b40
  ecx = edx = 0;  // @352_5b4b40
  X1[0] = 0;  // @353_5b4b40
  X1[1] = 0;  // @354_5b4b40
  X1[2] = 0;  // @355_5b4b40
  X1[3] = 0;  // @356_5b4b40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @357_5b4b40
  X0[1] = 0;  // @358_5b4b40
  X0[2] = 0;  // @359_5b4b40
  X0[3] = 0;  // @360_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @361_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @362_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @363_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_5b4b40
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5b514a;  // @365_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020776));  // @366_5b4b40
  ecx = edx = 0;  // @367_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @368_5b4b40
  PV[28] = (u32)(eax);  // @369_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @370_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[28], (u32)(4294967040), (u32)(1));  // @371_5b4b40
  ecx = edx = 0;  // @372_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @373_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @374_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @375_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @376_5b4b40
  ecx = edx = 0;  // @377_5b4b40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @378_5b4b40
  goto L5b5186;  // @379_5b4b40
  L5b514a:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020788));  // @381_5b4b40
  ecx = edx = 0;  // @382_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @383_5b4b40
  PV[29] = (u32)(eax);  // @384_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @385_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[29], (u32)(4294967040), (u32)(1));  // @386_5b4b40
  ecx = edx = 0;  // @387_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @388_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @389_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @390_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @391_5b4b40
  ecx = edx = 0;  // @392_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @393_5b4b40
  L5b5186:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @395_5b4b40
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 351), sizeof v); (u32)v; });  // @396_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @397_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @398_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @399_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[30], (u32)(0));  // @400_5b4b40
  ecx = edx = 0;  // @401_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @402_5b4b40
  if (FL[2] == 0) goto L5b5256;  // @403_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @404_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @405_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @406_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @407_5b4b40
  ecx = edx = 0;  // @408_5b4b40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @409_5b4b40
  X0[1] = 0;  // @410_5b4b40
  X0[2] = 0;  // @411_5b4b40
  X0[3] = 0;  // @412_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @413_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @414_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @415_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @416_5b4b40
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))) goto L5b521a;  // @417_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020800));  // @418_5b4b40
  ecx = edx = 0;  // @419_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @420_5b4b40
  PV[31] = (u32)(eax);  // @421_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @422_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[31], (u32)(4294967040), (u32)(1));  // @423_5b4b40
  ecx = edx = 0;  // @424_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @425_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @426_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @427_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @428_5b4b40
  ecx = edx = 0;  // @429_5b4b40
  { u32 v = (u32)((u32)(1050253722)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @430_5b4b40
  goto L5b5256;  // @431_5b4b40
  L5b521a:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020808));  // @433_5b4b40
  ecx = edx = 0;  // @434_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @435_5b4b40
  PV[32] = (u32)(eax);  // @436_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @437_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[32], (u32)(4294967040), (u32)(1));  // @438_5b4b40
  ecx = edx = 0;  // @439_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @440_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @441_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @442_5b4b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 148)))(ecx);  // @443_5b4b40
  ecx = edx = 0;  // @444_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @445_5b4b40
  L5b5256:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @447_5b4b40
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 355), sizeof v); (u32)v; });  // @448_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @449_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @450_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @451_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[33], (u32)(0));  // @452_5b4b40
  ecx = edx = 0;  // @453_5b4b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @454_5b4b40
  if (FL[2] == 0) goto L5b52fc;  // @455_5b4b40
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338592) + 0), 4); v; });  // @456_5b4b40
  X0[1] = 0;  // @457_5b4b40
  X0[2] = 0;  // @458_5b4b40
  X0[3] = 0;  // @459_5b4b40
  X1[0] = 0;  // @460_5b4b40
  X1[1] = 0;  // @461_5b4b40
  X1[2] = 0;  // @462_5b4b40
  X1[3] = 0;  // @463_5b4b40
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @464_5b4b40
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @465_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @466_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @467_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @468_5b4b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @469_5b4b40
  if (__builtin_parity(FL[2] & 0xff)) goto L5b52d0;  // @470_5b4b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020820));  // @471_5b4b40
  ecx = edx = 0;  // @472_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @473_5b4b40
  PV[34] = (u32)(eax);  // @474_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @475_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[34], (u32)(4294967040), (u32)(1));  // @476_5b4b40
  ecx = edx = 0;  // @477_5b4b40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7338592), &v, sizeof v); }  // @478_5b4b40
  return eax;  // @479_5b4b40
  L5b52d0:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(7020660), (u32)(7020828));  // @481_5b4b40
  ecx = edx = 0;  // @482_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @483_5b4b40
  PV[35] = (u32)(eax);  // @484_5b4b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @485_5b4b40
  eax = ext_59a580_thiscall4(ecx, PV[35], (u32)(4294967040), (u32)(1));  // @486_5b4b40
  ecx = edx = 0;  // @487_5b4b40
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(7338592), &v, sizeof v); }  // @488_5b4b40
  L5b52fc:;
  return eax;  // @490_5b4b40
}
PCREG(5b4b40, lifted_5b4b40);

extern "C" u32 THISCALL lifted_536370(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_536370
  edi = ecx;  // @1_536370
  FL[2] = (ebx & ebx);  // @2_536370
  if (FL[2] != 0) goto L5363af;  // @3_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @4_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_536370
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(621));  // @6_536370
  ecx = edx = 0;  // @7_536370
  PV[0] = (u32)(eax);  // @8_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_536370
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6954856));  // @10_536370
  ecx = edx = 0;  // @11_536370
  L5363af:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_536370
  eax = (eax - 1);  // @14_536370
  FL[3] = eax;  // @15_536370
  FL[0] = eax; FL[1] = (u32)(15);  // @16_536370
  if (FL[0] > FL[1]) goto L53652e;  // @17_536370
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5465496), sizeof v); (u32)v; });  // @18_536370
  switch (eax) {  // @19_536370
  case 0: goto L5363c9;  // @20_536370
  case 1: goto L536409;  // @21_536370
  case 2: goto L53648e;  // @22_536370
  case 3: goto L53652e;  // @23_536370
  default: __builtin_trap(); }  // @24_536370
  L5363c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @26_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_536370
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(628));  // @28_536370
  ecx = edx = 0;  // @29_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; });  // @30_536370
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }));  // @31_536370
  FL[3] = ecx;  // @32_536370
  PV[1] = (u32)(ecx);  // @33_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_536370
  PV[2] = (u32)(eax);  // @35_536370
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[2], (u32)(6954864), PV[1]);  // @36_536370
  ecx = edx = 0;  // @37_536370
  ext_633654(G(u32, 0x6f5630));  // @38_536370
  return eax;  // @39_536370
  L536409:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @41_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @42_536370
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; }));  // @43_536370
  FL[3] = eax;  // @44_536370
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @45_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_536370
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(634));  // @47_536370
  ecx = edx = 0;  // @48_536370
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @49_536370
  PV[3] = (u32)(ecx);  // @50_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @51_536370
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; }));  // @52_536370
  FL[3] = ecx;  // @53_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_536370
  PV[4] = (u32)(ecx);  // @55_536370
  PV[5] = (u32)(eax);  // @56_536370
  eax = ((u32(__attribute__((cdecl)) *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(PV[5], (u32)(6954876), PV[4], PV[3]);  // @57_536370
  ecx = edx = 0;  // @58_536370
  eax = 0;  // @59_536370
  FL[3] = eax;  // @60_536370
  esi = 0;  // @61_536370
  FL[3] = esi;  // @62_536370
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @63_536370
  if (FL[0] >= FL[1]) goto L536572;  // @64_536370
  L536455:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @66_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @67_536370
  FL[2] = (ecx & ecx);  // @68_536370
  if (FL[2] == 0) goto L536472;  // @69_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; });  // @70_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @71_536370
  eax = (eax + ecx);  // @72_536370
  FL[3] = eax;  // @73_536370
  PV[6] = (u32)(eax);  // @74_536370
  ecx = edi;  // @75_536370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 492)))(ecx, PV[6]);  // @76_536370
  ecx = edx = 0;  // @77_536370
  L536472:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @79_536370
  esi = (esi + 1);  // @80_536370
  FL[3] = esi;  // @81_536370
  FL[0] = esi; FL[1] = eax;  // @82_536370
  if ((s32)FL[0] < (s32)FL[1]) goto L536455;  // @83_536370
  ext_633654(G(u32, 0x6f5630));  // @84_536370
  return eax;  // @85_536370
  L53648e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6781788), sizeof v); (u32)v; });  // @87_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @88_536370
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @89_536370
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @90_536370
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6781792), sizeof v); (u32)v; })) & 0xff);  // @91_536370
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @92_536370
  eax = (u32)(EBP - 12);  // @93_536370
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @94_536370
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @95_536370
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @96_536370
  FL[2] = (ecx & ecx);  // @97_536370
  if (FL[2] == 0) goto L5364ca;  // @98_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; });  // @99_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @100_536370
  eax = (eax + ecx);  // @101_536370
  FL[3] = eax;  // @102_536370
  PV[7] = (u32)(eax);  // @103_536370
  ecx = edi;  // @104_536370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 488)))(ecx, PV[7]);  // @105_536370
  ecx = edx = 0;  // @106_536370
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @107_536370
  L5364ca:;
  FL[2] = (esi & esi);  // @109_536370
  if (FL[2] == 0) goto L5364e4;  // @110_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; });  // @111_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @112_536370
  ecx = (ecx + esi);  // @113_536370
  FL[3] = ecx;  // @114_536370
  PV[8] = (u32)(ecx);  // @115_536370
  ecx = edi;  // @116_536370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 488)))(ecx, PV[8]);  // @117_536370
  ecx = edx = 0;  // @118_536370
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @119_536370
  L5364e4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @121_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_536370
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6954540), (u32)(655));  // @123_536370
  ecx = edx = 0;  // @124_536370
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @125_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21250), sizeof v); (u32)v; });  // @126_536370
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @127_536370
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }));  // @128_536370
  FL[3] = ecx;  // @129_536370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @130_536370
  PV[11] = (u32)(esi);  // @131_536370
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @132_536370
  PV[13] = (u32)(ecx);  // @133_536370
  PV[14] = (u32)(eax);  // @134_536370
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))(PV[14], (u32)(6954900), PV[13], PV[12], PV[11], PV[10], PV[9]);  // @135_536370
  ecx = edx = 0;  // @136_536370
  ext_633654(G(u32, 0x6f5630));  // @137_536370
  return eax;  // @138_536370
  L53652e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @140_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_536370
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(659));  // @142_536370
  ecx = edx = 0;  // @143_536370
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @144_536370
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @145_536370
  PV[16] = (u32)(eax);  // @146_536370
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[16], (u32)(6954928), PV[15]);  // @147_536370
  ecx = edx = 0;  // @148_536370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @149_536370
  FL[2] = (eax & eax);  // @150_536370
  if (FL[2] == 0) goto L536571;  // @151_536370
  eax = ((u32(STDCALL *)(void))(eax))();  // @152_536370
  ecx = edx = 0;  // @153_536370
  ext_633654(G(u32, 0x6f5630));  // @154_536370
  return eax;  // @155_536370
  L536571:;
  __builtin_trap();  // @157_536370
  L536572:;
  ext_633654(G(u32, 0x6f5630));  // @159_536370
  return eax;  // @160_536370
}
PCREG(536370, lifted_536370);

extern "C" u32 THISCALL old_lifted_482b80(u32 ecx_in) {
  SEH_ENTER(0x66756b);  // @h_482b80
  u8 F[0xcae0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0xc9e0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_482b80
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 51600), &v, sizeof v); }  // @1_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @3_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @5_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6865036), (u32)(0));  // @6_482b80
  ecx = edx = 0;  // @7_482b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @8_482b80
  if (FL[2] == 0) goto L482daa;  // @9_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @11_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @13_482b80
  ecx = edx = 0;  // @14_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_482b80
  PV[0] = (u32)(eax);  // @16_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @17_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @19_482b80
  ecx = edx = 0;  // @20_482b80
  esi = eax;  // @21_482b80
  FL[2] = (esi & esi);  // @22_482b80
  if (FL[2] == 0) goto L482daa;  // @23_482b80
  ecx = (u32)(EBP - 51464);  // @24_482b80
  eax = ext_4e1b60_thiscall1(ecx);  // @25_482b80
    // @26_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_482b80
  ecx = (u32)(EBP - 51464);  // @28_482b80
  PV[1] = (u32)(ecx);  // @29_482b80
  ecx = esi;  // @30_482b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 51464), &v, sizeof v); }  // @31_482b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 51460), &v, sizeof v); }  // @32_482b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 51456), &v, sizeof v); }  // @33_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[1]);  // @34_482b80
  ecx = edx = 0;  // @35_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_482b80
  PV[2] = (u32)(ecx);  // @37_482b80
  ecx = (u32)(EBP - 51352);  // @38_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 652), sizeof v); (u32)v; });  // @39_482b80
  PV[3] = (u32)(ecx);  // @40_482b80
  ecx = esi;  // @41_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[3], (u32)(0), (u32)(7), (u32)(0));  // @42_482b80
  ecx = edx = 0;  // @43_482b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @44_482b80
  if (FL[2] == 0) goto L482daa;  // @45_482b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 51352) + 0), 4); v; });  // @46_482b80
  X0[1] = 0;  // @47_482b80
  X0[2] = 0;  // @48_482b80
  X0[3] = 0;  // @49_482b80
  ecx = (u32)(EBP - 51300);  // @50_482b80
  __builtin_memcpy((void *)((u32)(EBP - 51228) + 0), &X0[0], 4);  // @51_482b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 51348) + 0), 4); v; });  // @52_482b80
  X0[1] = 0;  // @53_482b80
  X0[2] = 0;  // @54_482b80
  X0[3] = 0;  // @55_482b80
  __builtin_memcpy((void *)((u32)(EBP - 51224) + 0), &X0[0], 4);  // @56_482b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 51344) + 0), 4); v; });  // @57_482b80
  X0[1] = 0;  // @58_482b80
  X0[2] = 0;  // @59_482b80
  X0[3] = 0;  // @60_482b80
  __builtin_memcpy((void *)((u32)(EBP - 51220) + 0), &X0[0], 4);  // @61_482b80
  eax = ext_4de7a0_thiscall1(ecx);  // @62_482b80
    // @63_482b80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 51224) + 0), 4); v; });  // @64_482b80
  X0[1] = 0;  // @65_482b80
  X0[2] = 0;  // @66_482b80
  X0[3] = 0;  // @67_482b80
  edx = (u32)(EBP - 51216);  // @68_482b80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866764) + 0), 4); v; })));  // @69_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_482b80
  PV[4] = (u32)(edx);  // @71_482b80
  __builtin_memcpy((void *)((u32)(EBP - 51224) + 0), &X0[0], 4);  // @72_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @73_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @74_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[4], (u32)(51200));  // @76_482b80
  ecx = edx = 0;  // @77_482b80
  esi = eax;  // @78_482b80
  ecx = edi;  // @79_482b80
  eax = (u32)(EBP - 51228);  // @80_482b80
  PV[5] = (u32)(eax);  // @81_482b80
  PV[6] = (u32)(eax);  // @82_482b80
  PV[7] = (u32)(esi);  // @83_482b80
  eax = ext_484b10_thiscall6(ecx, PV[7], (u32)(0), PV[6], PV[5], (u32)(0));  // @84_482b80
  ecx = edx = 0;  // @85_482b80
  ecx = esi;  // @86_482b80
  eax = ext_4ea300_thiscall2(ecx, (u32)(32));  // @87_482b80
  ecx = edx = 0;  // @88_482b80
  eax = (u32)(edi + 1081);  // @89_482b80
  ecx = esi;  // @90_482b80
  PV[8] = (u32)(eax);  // @91_482b80
  eax = (u32)(EBP - 51228);  // @92_482b80
  PV[9] = (u32)(eax);  // @93_482b80
  eax = (u32)(EBP - 51300);  // @94_482b80
  PV[10] = (u32)(eax);  // @95_482b80
  eax = ext_4e9200_thiscall4(ecx, PV[10], PV[9], PV[8]);  // @96_482b80
  ecx = edx = 0;  // @97_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @98_482b80
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @99_482b80
  PV[11] = (u32)(esi);  // @100_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @101_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @102_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[11]);  // @104_482b80
  ecx = edx = 0;  // @105_482b80
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @106_482b80
  if (FL[2] != 0) goto L482daa;  // @107_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @108_482b80
  ecx = (u32)(EBP - 51352);  // @109_482b80
  PV[12] = (u32)(ecx);  // @110_482b80
  ecx = (u32)(EBP - 51300);  // @111_482b80
  PV[13] = (u32)(ecx);  // @112_482b80
  ecx = edi;  // @113_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 880)))(ecx, PV[13], PV[12]);  // @114_482b80
  ecx = edx = 0;  // @115_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @117_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @118_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @120_482b80
  ecx = edx = 0;  // @121_482b80
  ebx = eax;  // @122_482b80
  FL[2] = (ebx & ebx);  // @123_482b80
  if (FL[2] == 0) goto L482daa;  // @124_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_482b80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @126_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @127_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6865048), (u32)(0), (u32)(6864060), (u32)(2071), (u32)(0), (u32)(0));  // @129_482b80
  ecx = edx = 0;  // @130_482b80
  eax = (eax & 0xffff);  // @131_482b80
  ecx = ebx;  // @132_482b80
  PV[14] = (u32)(eax);  // @133_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[14]);  // @134_482b80
  ecx = edx = 0;  // @135_482b80
  L482daa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @138_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @140_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6862200), (u32)(0));  // @141_482b80
  ecx = edx = 0;  // @142_482b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @143_482b80
  if (FL[2] == 0) goto L482df5;  // @144_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @145_482b80
  ecx = edi;  // @146_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1020), sizeof v); (u32)v; });  // @147_482b80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1));  // @148_482b80
  ecx = edx = 0;  // @149_482b80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @150_482b80
  ecx = edi;  // @151_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @152_482b80
  if (FL[2] == 0) goto L482ded;  // @153_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1020)))(ecx, (u32)(0));  // @154_482b80
  ecx = edx = 0;  // @155_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @156_482b80
  ecx = edi;  // @157_482b80
  goto L482def;  // @158_482b80
  L482ded:;
  L482def:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1408)))(ecx, (u32)(1), (u32)(0));  // @161_482b80
  ecx = edx = 0;  // @162_482b80
  L482df5:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1610), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @164_482b80
  if (FL[0] == FL[1]) goto L48303d;  // @165_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_482b80
  ecx = edi;  // @167_482b80
  ebx = 0;  // @168_482b80
  FL[3] = ebx;  // @169_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @170_482b80
  ecx = edx = 0;  // @171_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @172_482b80
  eax = ext_4db550_thiscall1(ecx);  // @173_482b80
  ecx = edx = 0;  // @174_482b80
  edx = eax;  // @175_482b80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 51604), &v, sizeof v); }  // @176_482b80
  FL[2] = (edx & edx);  // @177_482b80
  if (FL[2] == 0) goto L482f10;  // @178_482b80
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; })) & 0xff);  // @179_482b80
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @180_482b80
  if (FL[2] == 0) goto L482f10;  // @181_482b80
  L482e30:;
  eax = (ecx & 0xff);  // @183_482b80
  FL[0] = ebx; FL[1] = eax;  // @184_482b80
  if (FL[0] >= FL[1]) goto L482e3c;  // @185_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx*4), sizeof v); (u32)v; });  // @186_482b80
  goto L482e3e;  // @187_482b80
  L482e3c:;
  ecx = 0;  // @189_482b80
  FL[3] = ecx;  // @190_482b80
  L482e3e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_482b80
  edx = (u32)(EBP - 51592);  // @193_482b80
  PV[15] = (u32)(edx);  // @194_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[15], (u32)(0));  // @195_482b80
  ecx = edx = 0;  // @196_482b80
  ecx = (u32)(EBP - 51592);  // @197_482b80
  reg.state = (s32)((u32)(0));  // @198_482b80
  eax = ext_4cc1d0_thiscall1(ecx);  // @199_482b80
    // @200_482b80
  PV[16] = (u32)(eax);  // @201_482b80
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[16], (u32)(47));  // @202_482b80
  ecx = edx = 0;  // @203_482b80
  FL[2] = (eax & eax);  // @204_482b80
  if (FL[2] == 0) goto L482e74;  // @205_482b80
  eax = (eax + 1);  // @206_482b80
  FL[3] = eax;  // @207_482b80
  goto L482e7f;  // @208_482b80
  L482e74:;
  ecx = (u32)(EBP - 51592);  // @210_482b80
  eax = ext_4cc1d0_thiscall1(ecx);  // @211_482b80
    // @212_482b80
  L482e7f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @214_482b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 51596), &v, sizeof v); }  // @215_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @216_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @217_482b80
  ecx = edx = 0;  // @218_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @219_482b80
  esi = eax;  // @220_482b80
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51596), sizeof v); (u32)v; });  // @221_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @222_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @223_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 220)))(ecx, (u32)(6865064), PV[17]);  // @225_482b80
  ecx = edx = 0;  // @226_482b80
  ecx = eax;  // @227_482b80
  eax = (u32)(715827883);  // @228_482b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @229_482b80
  eax = edx;  // @230_482b80
  eax = (eax >> (u32)(31));  // @231_482b80
  FL[3] = eax;  // @232_482b80
  eax = (eax + (u32)(-10));  // @233_482b80
  FL[3] = eax;  // @234_482b80
  eax = (eax + edx);  // @235_482b80
  FL[3] = eax;  // @236_482b80
  eax = (eax + ebx);  // @237_482b80
  FL[3] = eax;  // @238_482b80
  PV[18] = (u32)(eax);  // @239_482b80
  PV[19] = (u32)(esi);  // @240_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 388)))(ecx, PV[19], (u32)(0), PV[18]);  // @241_482b80
  ecx = edx = 0;  // @242_482b80
  reg.state = (s32)((u32)(4294967295));  // @243_482b80
  ecx = (u32)(EBP - 51592);  // @244_482b80
  eax = ext_4cbec0_thiscall1(ecx);  // @245_482b80
  ecx = edx = 0;  // @246_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51604), sizeof v); (u32)v; });  // @247_482b80
  ebx = (ebx + 1);  // @248_482b80
  FL[3] = ebx;  // @249_482b80
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; })) & 0xff);  // @250_482b80
  eax = (ecx & 0xff);  // @251_482b80
  FL[0] = ebx; FL[1] = eax;  // @252_482b80
  if (FL[0] != FL[1]) goto L482e30;  // @253_482b80
  FL[0] = ebx; FL[1] = (u32)(6);  // @254_482b80
  if (FL[0] >= FL[1]) goto L482f63;  // @255_482b80
  L482f10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @257_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @259_482b80
  ecx = edx = 0;  // @260_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @261_482b80
  esi = eax;  // @262_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @263_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @264_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @265_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 220)))(ecx, (u32)(6779512));  // @266_482b80
  ecx = edx = 0;  // @267_482b80
  ecx = eax;  // @268_482b80
  eax = (u32)(715827883);  // @269_482b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @270_482b80
  eax = edx;  // @271_482b80
  eax = (eax >> (u32)(31));  // @272_482b80
  FL[3] = eax;  // @273_482b80
  eax = (eax + (u32)(-10));  // @274_482b80
  FL[3] = eax;  // @275_482b80
  eax = (eax + edx);  // @276_482b80
  FL[3] = eax;  // @277_482b80
  eax = (eax + ebx);  // @278_482b80
  FL[3] = eax;  // @279_482b80
  PV[20] = (u32)(eax);  // @280_482b80
  PV[21] = (u32)(esi);  // @281_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 388)))(ecx, PV[21], (u32)(0), PV[20]);  // @282_482b80
  ecx = edx = 0;  // @283_482b80
  ebx = (ebx + 1);  // @284_482b80
  FL[3] = ebx;  // @285_482b80
  FL[0] = ebx; FL[1] = (u32)(6);  // @286_482b80
  if (FL[0] < FL[1]) goto L482f10;  // @287_482b80
  L482f63:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51600), sizeof v); (u32)v; });  // @289_482b80
  ecx = edi;  // @290_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @291_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @292_482b80
  ecx = edx = 0;  // @293_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @294_482b80
  eax = ext_4db3b0_thiscall1(ecx);  // @295_482b80
  ecx = edx = 0;  // @296_482b80
  esi = eax;  // @297_482b80
  eax = (u32)(EBP - 51240);  // @298_482b80
  PV[22] = (u32)(eax);  // @299_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @300_482b80
  eax = ext_4daf90_thiscall2(ecx, PV[22]);  // @301_482b80
  edx = 0;  // @302_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @303_482b80
  eax = (u32)(EBP - 51240);  // @304_482b80
  PV[23] = (u32)(eax);  // @305_482b80
  ecx = esi;  // @306_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[23]);  // @307_482b80
  ecx = edx = 0;  // @308_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @309_482b80
  ecx = (u32)(EBP - 51264);  // @310_482b80
  PV[24] = (u32)(ecx);  // @311_482b80
  ecx = (u32)(EBP - 51336);  // @312_482b80
  PV[25] = (u32)(ecx);  // @313_482b80
  ecx = esi;  // @314_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[25], PV[24]);  // @315_482b80
  ecx = edx = 0;  // @316_482b80
  edx = (u32)(EBP - 51264);  // @317_482b80
  ecx = (u32)(EBP - 51240);  // @318_482b80
  eax = ext_441940_fastcall2(ecx, edx);  // @319_482b80
  ecx = edx = 0;  // @320_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @321_482b80
  eax = (u32)(EBP - 51252);  // @322_482b80
  PV[26] = (u32)(eax);  // @323_482b80
  eax = ext_4db7c0_thiscall2(ecx, PV[26]);  // @324_482b80
  edx = 0;  // @325_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @326_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1602), sizeof v); (u32)v; });  // @327_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @328_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @329_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @330_482b80
  FL[2] = (edx & edx);  // @331_482b80
  if (FL[2] == 0) goto L483017;  // @332_482b80
  esi = (u32)(EBP - 51252);  // @333_482b80
  PV[27] = (u32)(esi);  // @334_482b80
  esi = (u32)(EBP - 51240);  // @335_482b80
  PV[28] = (u32)(esi);  // @336_482b80
  esi = (u32)(EBP - 51336);  // @337_482b80
  PV[29] = (u32)(esi);  // @338_482b80
  PV[30] = (u32)(edx);  // @339_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[30], PV[29], PV[28], PV[27], (u32)(11175936), (u32)(0));  // @340_482b80
  ecx = edx = 0;  // @341_482b80
  goto L4830c0;  // @342_482b80
  L483017:;
  edx = (u32)(EBP - 51252);  // @344_482b80
  PV[31] = (u32)(edx);  // @345_482b80
  edx = (u32)(EBP - 51240);  // @346_482b80
  PV[32] = (u32)(edx);  // @347_482b80
  edx = (u32)(EBP - 51336);  // @348_482b80
  PV[33] = (u32)(edx);  // @349_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 568)))(ecx, PV[33], PV[32], PV[31]);  // @350_482b80
  ecx = edx = 0;  // @351_482b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1602), &v, sizeof v); }  // @352_482b80
  goto L4830c0;  // @353_482b80
  L48303d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1602), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @355_482b80
  if (FL[0] == FL[1]) goto L4830c0;  // @356_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @357_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @358_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @359_482b80
  ecx = edx = 0;  // @360_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @361_482b80
  esi = eax;  // @362_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @363_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @364_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @365_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 220)))(ecx, (u32)(6790764));  // @366_482b80
  ecx = edx = 0;  // @367_482b80
  ecx = eax;  // @368_482b80
  eax = (u32)(715827883);  // @369_482b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @370_482b80
  eax = edx;  // @371_482b80
  eax = (eax >> (u32)(31));  // @372_482b80
  FL[3] = eax;  // @373_482b80
  eax = (eax + (u32)(-4));  // @374_482b80
  FL[3] = eax;  // @375_482b80
  eax = (eax + edx);  // @376_482b80
  FL[3] = eax;  // @377_482b80
  PV[34] = (u32)(eax);  // @378_482b80
  PV[35] = (u32)(esi);  // @379_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 388)))(ecx, PV[35], (u32)(0), PV[34]);  // @380_482b80
  ecx = edx = 0;  // @381_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @382_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51600), sizeof v); (u32)v; });  // @383_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @384_482b80
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1602), sizeof v); (u32)v; });  // @385_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @386_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @387_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[36]);  // @388_482b80
  ecx = edx = 0;  // @389_482b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1602), &v, sizeof v); }  // @390_482b80
  L4830c0:;
  SEH_LEAVE();  // @392_482b80
  ext_633654(G(u32, 0x6f5630));  // @393_482b80
  return eax;  // @394_482b80
}
// PCREG removed: re-lifted in batch240027.cpp

extern "C" u32 old_lifted_61dcd0(void) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[255], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_61dcd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_61dcd0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @2_61dcd0
  if (FL[0] != FL[1]) goto L61dcf8;  // @3_61dcd0
  eax = (u32)(esi + 280);  // @4_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @5_61dcd0
  eax = (u32)(esi + 284);  // @6_61dcd0
  goto L61dd04;  // @7_61dcd0
  L61dcf8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 292), sizeof v); (u32)v; });  // @9_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @10_61dcd0
  eax = (u32)(ecx + 4);  // @11_61dcd0
  L61dd04:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @13_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @14_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @15_61dcd0
  L61dd0d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @17_61dcd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @18_61dcd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @19_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @20_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @21_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @22_61dcd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_61dcd0
  FL[2] = (ecx & ecx);  // @24_61dcd0
  if ((s32)FL[2] > 0) goto L61dd4c;  // @25_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @26_61dcd0
  FL[2] = (eax & eax);  // @27_61dcd0
  if (FL[2] == 0) goto L61dd33;  // @28_61dcd0
  FL[2] = (ecx & ecx);  // @29_61dcd0
  if (FL[2] != 0) goto L61ee85;  // @30_61dcd0
  L61dd33:;
  eax = (u32)(ecx + 4);  // @32_61dcd0
  FL[0] = eax; FL[1] = (u32)(4);  // @33_61dcd0
  if (FL[0] > FL[1]) goto L61dd42;  // @34_61dcd0
  switch (eax) {  // @35_61dcd0
  case 0: goto L61eebc;  // @36_61dcd0
  case 1: goto L61dd42;  // @37_61dcd0
  case 2: goto L61eeb0;  // @38_61dcd0
  case 3: goto L61eea4;  // @39_61dcd0
  case 4: goto L61ee90;  // @40_61dcd0
  default: __builtin_trap(); }  // @41_61dcd0
  L61dd42:;
  FL[1] = ecx;  // @43_61dcd0
  ecx = (0u - ecx);  // @44_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 28), &v, sizeof v); }  // @45_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @46_61dcd0
  goto L61dd4f;  // @47_61dcd0
  L61dd4c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @49_61dcd0
  L61dd4f:;
  PV[0] = (u32)(ebx);  // @51_61dcd0
  PV[1] = (u32)(edx);  // @52_61dcd0
  PV[2] = (u32)(edi);  // @53_61dcd0
  eax = (u32)(esi + 256);  // @54_61dcd0
  PV[3] = (u32)(ecx);  // @55_61dcd0
  PV[4] = (u32)(eax);  // @56_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[4], PV[3], PV[2], PV[1], PV[0]);  // @58_61dcd0
  ecx = edx = 0;  // @59_61dcd0
  ecx = eax;  // @60_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @61_61dcd0
  eax = (u32)(ecx + 1);  // @62_61dcd0
  FL[0] = eax; FL[1] = (u32)(54);  // @63_61dcd0
  if (FL[0] > FL[1]) goto L61ee35;  // @64_61dcd0
  switch (eax) {  // @65_61dcd0
  case 0: goto L61ef81;  // @66_61dcd0
  case 1: goto L61ee03;  // @67_61dcd0
  case 2: goto L61dd79;  // @68_61dcd0
  case 3: goto L61ef58;  // @69_61dcd0
  case 4: goto L61dd9b;  // @70_61dcd0
  case 5: goto L61e462;  // @71_61dcd0
  case 6: goto L61de39;  // @72_61dcd0
  case 7: goto L61ddec;  // @73_61dcd0
  case 8: goto L61df09;  // @74_61dcd0
  case 9: goto L61e663;  // @75_61dcd0
  case 10: goto L61e711;  // @76_61dcd0
  case 11: goto L61e3bb;  // @77_61dcd0
  case 12: goto L61e507;  // @78_61dcd0
  case 13: goto L61de96;  // @79_61dcd0
  case 14: goto L61e564;  // @80_61dcd0
  case 15: goto L61e5af;  // @81_61dcd0
  case 16: goto L61e78c;  // @82_61dcd0
  case 17: goto L61e84d;  // @83_61dcd0
  case 18: goto L61e8b8;  // @84_61dcd0
  case 19: goto L61e7dd;  // @85_61dcd0
  case 20: goto L61dfec;  // @86_61dcd0
  case 21: goto L61e020;  // @87_61dcd0
  case 22: goto L61e036;  // @88_61dcd0
  case 23: goto L61e04c;  // @89_61dcd0
  case 24: goto L61e05b;  // @90_61dcd0
  case 25: goto L61e06a;  // @91_61dcd0
  case 26: goto L61e079;  // @92_61dcd0
  case 27: goto L61e088;  // @93_61dcd0
  case 28: goto L61e097;  // @94_61dcd0
  case 29: goto L61e0a6;  // @95_61dcd0
  case 30: goto L61e0a6;  // @96_61dcd0
  case 31: goto L61dfd6;  // @97_61dcd0
  case 32: goto L61e118;  // @98_61dcd0
  case 33: goto L61e118;  // @99_61dcd0
  case 34: goto L61e24b;  // @100_61dcd0
  case 35: goto L61e24b;  // @101_61dcd0
  case 36: goto L61ebce;  // @102_61dcd0
  case 37: goto L61ec17;  // @103_61dcd0
  case 38: goto L61ec17;  // @104_61dcd0
  case 39: goto L61ec8e;  // @105_61dcd0
  case 40: goto L61e942;  // @106_61dcd0
  case 41: goto L61ed68;  // @107_61dcd0
  case 42: goto L61ed73;  // @108_61dcd0
  case 43: goto L61ed6c;  // @109_61dcd0
  case 44: goto L61ed7a;  // @110_61dcd0
  case 45: goto L61ea3c;  // @111_61dcd0
  case 46: goto L61ea1d;  // @112_61dcd0
  case 47: goto L61ecc6;  // @113_61dcd0
  case 48: goto L61ecd1;  // @114_61dcd0
  case 49: goto L61ecca;  // @115_61dcd0
  case 50: goto L61ecd8;  // @116_61dcd0
  case 51: goto L61de2e;  // @117_61dcd0
  case 52: goto L61e8ff;  // @118_61dcd0
  case 53: goto L61eaa1;  // @119_61dcd0
  case 54: goto L61eaa1;  // @120_61dcd0
  default: __builtin_trap(); }  // @121_61dcd0
  L61dd79:;
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @123_61dcd0
  PV[6] = (u32)(edi);  // @124_61dcd0
  L61dd7f:;
  PV[7] = (u32)(esi);  // @126_61dcd0
  eax = ext_620910_cdecl4(PV[7], (u32)(0), PV[6], PV[5]);  // @127_61dcd0
  ecx = edx = 0;  // @128_61dcd0
  FL[2] = (eax & eax);  // @129_61dcd0
  if (FL[2] != 0) goto L61efa4;  // @130_61dcd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @131_61dcd0
  goto L61ee35;  // @132_61dcd0
  L61dd9b:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @134_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @135_61dcd0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @136_61dcd0
  eax = (u32)(esi + 556);  // @137_61dcd0
  PV[9] = (u32)(edi);  // @138_61dcd0
  PV[10] = (u32)(ebx);  // @139_61dcd0
  PV[11] = (u32)(eax);  // @140_61dcd0
  eax = ext_620840_cdecl4(PV[11], PV[10], PV[9], PV[8]);  // @141_61dcd0
  ecx = edx = 0;  // @142_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 308), &v, sizeof v); }  // @143_61dcd0
  FL[2] = (eax & eax);  // @144_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @145_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @146_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @147_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @148_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 316), &v, sizeof v); }  // @149_61dcd0
  goto L61ee35;  // @150_61dcd0
  L61ddec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @152_61dcd0
  FL[2] = (eax & eax);  // @153_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @154_61dcd0
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 316), sizeof v); (u32)v; });  // @155_61dcd0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @156_61dcd0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 308), sizeof v); (u32)v; });  // @157_61dcd0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @158_61dcd0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))(PV[15], PV[14], PV[13], PV[12], (u32)(1));  // @159_61dcd0
  ecx = edx = 0;  // @160_61dcd0
  eax = (u32)(esi + 556);  // @161_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 308), &v, sizeof v); }  // @162_61dcd0
  PV[16] = (u32)(eax);  // @163_61dcd0
  eax = ext_6204a0_cdecl1(PV[16]);  // @164_61dcd0
  ecx = edx = 0;  // @165_61dcd0
  goto L61ee35;  // @166_61dcd0
  L61de2e:;
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @168_61dcd0
  PV[18] = (u32)(edi);  // @169_61dcd0
  goto L61dd7f;  // @170_61dcd0
  L61de39:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @172_61dcd0
  if (FL[0] == FL[1]) goto L61de72;  // @173_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @174_61dcd0
  eax = (eax - 1);  // @175_61dcd0
  FL[3] = eax;  // @176_61dcd0
  PV[19] = (u32)(eax);  // @177_61dcd0
  eax = (u32)(edi + 1);  // @178_61dcd0
  PV[20] = (u32)(eax);  // @179_61dcd0
  eax = (u32)(esi + 556);  // @180_61dcd0
  PV[21] = (u32)(ebx);  // @181_61dcd0
  PV[22] = (u32)(eax);  // @182_61dcd0
  eax = ext_620840_cdecl7(PV[22], PV[21], PV[20], PV[19], (u32)(1), PV[18], PV[17]);  // @183_61dcd0
  ecx = edx = 0;  // @184_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 316), &v, sizeof v); }  // @185_61dcd0
  FL[2] = (eax & eax);  // @186_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @187_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @188_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @189_61dcd0
  L61de72:;
  eax = (u32)(esi + 456);  // @191_61dcd0
  PV[23] = (u32)(eax);  // @192_61dcd0
  eax = ext_61fd60_cdecl3(PV[23], (u32)(7070396), (u32)(32));  // @193_61dcd0
  ecx = edx = 0;  // @194_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @195_61dcd0
  FL[2] = (eax & eax);  // @196_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @197_61dcd0
  L61de96:;
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @199_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 56), sizeof v); (u32)v; });  // @200_61dcd0
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @201_61dcd0
  PV[26] = (u32)(edi);  // @202_61dcd0
  PV[27] = (u32)(ebx);  // @203_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32))(eax))(PV[27], PV[26], PV[25], PV[24]);  // @204_61dcd0
  ecx = edx = 0;  // @205_61dcd0
  FL[2] = (eax & eax);  // @206_61dcd0
  if (FL[2] == 0) goto L61eee5;  // @207_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @208_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @209_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @210_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @211_61dcd0
  eax = (eax - ecx);  // @212_61dcd0
  FL[3] = eax;  // @213_61dcd0
  PV[28] = (u32)(eax);  // @214_61dcd0
  eax = (u32)(ecx + edi);  // @215_61dcd0
  PV[29] = (u32)(eax);  // @216_61dcd0
  eax = (u32)(esi + 424);  // @217_61dcd0
  PV[30] = (u32)(ebx);  // @218_61dcd0
  PV[31] = (u32)(eax);  // @219_61dcd0
  eax = ext_620840_cdecl4(PV[31], PV[30], PV[29], PV[28]);  // @220_61dcd0
  ecx = edx = 0;  // @221_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @222_61dcd0
  FL[2] = (eax & eax);  // @223_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @224_61dcd0
  PV[32] = (u32)(eax);  // @225_61dcd0
  eax = ext_620120_cdecl1(PV[32]);  // @226_61dcd0
  ecx = edx = 0;  // @227_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @228_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @229_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @230_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @231_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @232_61dcd0
  goto L61ee35;  // @233_61dcd0
  L61df09:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 308), sizeof v); (u32)v; });  // @235_61dcd0
  FL[2] = (eax & eax);  // @236_61dcd0
  if (FL[2] == 0) goto L61df39;  // @237_61dcd0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 316), sizeof v); (u32)v; });  // @238_61dcd0
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @239_61dcd0
  PV[35] = (u32)(eax);  // @240_61dcd0
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @241_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @242_61dcd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[36], PV[35], PV[34], PV[33], (u32)(0));  // @243_61dcd0
  ecx = edx = 0;  // @244_61dcd0
  eax = (u32)(esi + 556);  // @245_61dcd0
  PV[37] = (u32)(eax);  // @246_61dcd0
  eax = ext_6204a0_cdecl1(PV[37]);  // @247_61dcd0
  ecx = edx = 0;  // @248_61dcd0
  L61df39:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @250_61dcd0
  if (FL[0] == FL[1]) goto L61dfbe;  // @251_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 612), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @252_61dcd0
  if (FL[0] == FL[1]) goto L61dfbe;  // @253_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 620), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @254_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }  // @255_61dcd0
  if (FL[0] == FL[1]) goto L61df95;  // @256_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @257_61dcd0
  if (FL[0] == FL[1]) goto L61df95;  // @258_61dcd0
  eax = (u32)(esi + 456);  // @259_61dcd0
  PV[38] = (u32)(eax);  // @260_61dcd0
  eax = ext_61fd60_cdecl3(PV[38], (u32)(7070396), (u32)(0));  // @261_61dcd0
  ecx = edx = 0;  // @262_61dcd0
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @263_61dcd0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @264_61dcd0
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @265_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; });  // @266_61dcd0
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; });  // @267_61dcd0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))(PV[42], (u32)(0), PV[41], PV[40], PV[39]);  // @268_61dcd0
  ecx = edx = 0;  // @269_61dcd0
  FL[2] = (eax & eax);  // @270_61dcd0
  if (FL[2] == 0) goto L61ef1c;  // @271_61dcd0
  L61df95:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @273_61dcd0
  if (FL[0] != FL[1]) goto L61dfbe;  // @274_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 452), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @275_61dcd0
  if (FL[0] != FL[1]) goto L61dfbe;  // @276_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @277_61dcd0
  FL[2] = (eax & eax);  // @278_61dcd0
  if (FL[2] == 0) goto L61dfbe;  // @279_61dcd0
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @280_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[43]);  // @281_61dcd0
  ecx = edx = 0;  // @282_61dcd0
  FL[2] = (eax & eax);  // @283_61dcd0
  if (FL[2] == 0) goto L61ef28;  // @284_61dcd0
  L61dfbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @286_61dcd0
  FL[2] = (eax & eax);  // @287_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @288_61dcd0
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @289_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[44]);  // @290_61dcd0
  ecx = edx = 0;  // @291_61dcd0
  goto L61ee35;  // @292_61dcd0
  L61dfd6:;
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @294_61dcd0
  PV[46] = (u32)(edi);  // @295_61dcd0
  PV[47] = (u32)(ebx);  // @296_61dcd0
  PV[48] = (u32)(esi);  // @297_61dcd0
  eax = ext_61fb10_cdecl4(PV[48], PV[47], PV[46], PV[45]);  // @298_61dcd0
  ecx = edx = 0;  // @299_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 332), &v, sizeof v); }  // @300_61dcd0
  goto L61ee2a;  // @301_61dcd0
  L61dfec:;
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @303_61dcd0
  PV[50] = (u32)(edi);  // @304_61dcd0
  PV[51] = (u32)(ebx);  // @305_61dcd0
  PV[52] = (u32)(esi);  // @306_61dcd0
  eax = ext_61f5a0_cdecl4(PV[52], PV[51], PV[50], PV[49]);  // @307_61dcd0
  ecx = edx = 0;  // @308_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 336), &v, sizeof v); }  // @309_61dcd0
  FL[2] = (eax & eax);  // @310_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @311_61dcd0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 340), &v, sizeof v); }  // @312_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @313_61dcd0
  goto L61ee35;  // @314_61dcd0
  L61e020:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 340), &v, sizeof v); }  // @316_61dcd0
  { u32 v = (u32)((u32)(7071064)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @317_61dcd0
  goto L61ee35;  // @318_61dcd0
  L61e036:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 341), &v, sizeof v); }  // @320_61dcd0
  { u32 v = (u32)((u32)(7071072)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @321_61dcd0
  goto L61ee35;  // @322_61dcd0
  L61e04c:;
  { u32 v = (u32)((u32)(7071076)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @324_61dcd0
  goto L61ee35;  // @325_61dcd0
  L61e05b:;
  { u32 v = (u32)((u32)(7071084)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @327_61dcd0
  goto L61ee35;  // @328_61dcd0
  L61e06a:;
  { u32 v = (u32)((u32)(7071092)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @330_61dcd0
  goto L61ee35;  // @331_61dcd0
  L61e079:;
  { u32 v = (u32)((u32)(7071100)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @333_61dcd0
  goto L61ee35;  // @334_61dcd0
  L61e088:;
  { u32 v = (u32)((u32)(7071112)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @336_61dcd0
  goto L61ee35;  // @337_61dcd0
  L61e097:;
  { u32 v = (u32)((u32)(7071120)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @339_61dcd0
  goto L61ee35;  // @340_61dcd0
  L61e0a6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @342_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @343_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @344_61dcd0
  if (FL[0] == FL[1]) goto L61e0c3;  // @345_61dcd0
  eax = (u32)(7071132);  // @346_61dcd0
  goto L61e0d3;  // @347_61dcd0
  L61e0c3:;
  FL[0] = ecx; FL[1] = (u32)(29);  // @349_61dcd0
  eax = (u32)(7071136);  // @350_61dcd0
  ecx = (u32)(6802608);  // @351_61dcd0
  if (FL[0] != FL[1]) eax = ecx;  // @352_61dcd0
  L61e0d3:;
  ecx = (u32)(esi + 556);  // @354_61dcd0
  PV[53] = (u32)(eax);  // @355_61dcd0
  PV[54] = (u32)(ecx);  // @356_61dcd0
  eax = ext_620320_cdecl2(PV[54], PV[53]);  // @357_61dcd0
  ecx = edx = 0;  // @358_61dcd0
  FL[2] = (eax & eax);  // @359_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @360_61dcd0
  PV[55] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @361_61dcd0
  eax = (u32)(esi + 556);  // @362_61dcd0
  PV[56] = (u32)(edi);  // @363_61dcd0
  PV[57] = (u32)(ebx);  // @364_61dcd0
  PV[58] = (u32)(eax);  // @365_61dcd0
  eax = ext_620180_cdecl4(PV[58], PV[57], PV[56], PV[55]);  // @366_61dcd0
  ecx = edx = 0;  // @367_61dcd0
  FL[2] = (eax & eax);  // @368_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @369_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @370_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @371_61dcd0
  goto L61ee35;  // @372_61dcd0
  L61e118:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @374_61dcd0
  if (FL[0] == FL[1]) goto L61e150;  // @375_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 341), sizeof v); (u32)v; }));  // @376_61dcd0
  PV[59] = (u32)(esi);  // @377_61dcd0
  PV[60] = (u32)(eax);  // @378_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 340), sizeof v); (u32)v; }));  // @379_61dcd0
  PV[61] = (u32)(eax);  // @380_61dcd0
  PV[62] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @381_61dcd0
  PV[63] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @382_61dcd0
  eax = ext_61cd60_cdecl6(PV[63], PV[62], PV[61], PV[60], (u32)(0), PV[59]);  // @383_61dcd0
  ecx = edx = 0;  // @384_61dcd0
  FL[2] = (eax & eax);  // @385_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @386_61dcd0
  L61e150:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @388_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @389_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @390_61dcd0
  FL[2] = (eax & eax);  // @391_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @392_61dcd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @393_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(40);  // @394_61dcd0
  if (FL[0] == FL[1]) goto L61e185;  // @395_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(78);  // @396_61dcd0
  if (FL[0] != FL[1]) goto L61e205;  // @397_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }); FL[1] = (u32)(79);  // @398_61dcd0
  if (FL[0] != FL[1]) goto L61e205;  // @399_61dcd0
  L61e185:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @401_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @402_61dcd0
  if (FL[0] != FL[1]) goto L61e1aa;  // @403_61dcd0
  eax = (u32)(esi + 556);  // @404_61dcd0
  PV[64] = (u32)(eax);  // @405_61dcd0
  eax = ext_6206e0_cdecl1(PV[64]);  // @406_61dcd0
  ecx = edx = 0;  // @407_61dcd0
  FL[2] = (eax & eax);  // @408_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @409_61dcd0
  L61e1aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @411_61dcd0
  { u8 v = (u8)((u32)(41)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @412_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @413_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @414_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @415_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @416_61dcd0
  if (FL[0] != FL[1]) goto L61e1de;  // @417_61dcd0
  eax = (u32)(esi + 556);  // @418_61dcd0
  PV[65] = (u32)(eax);  // @419_61dcd0
  eax = ext_6206e0_cdecl1(PV[65]);  // @420_61dcd0
  ecx = edx = 0;  // @421_61dcd0
  FL[2] = (eax & eax);  // @422_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @423_61dcd0
  L61e1de:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @425_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @426_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @427_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @428_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @429_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @430_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @431_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @432_61dcd0
  L61e205:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @434_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @435_61dcd0
  eax = 0;  // @436_61dcd0
  FL[3] = eax;  // @437_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @438_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @439_61dcd0
  PV[66] = (u32)(eax);  // @440_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @441_61dcd0
  PV[67] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @442_61dcd0
  PV[68] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @443_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @444_61dcd0
  PV[69] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @445_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @446_61dcd0
  PV[70] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @447_61dcd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[70], PV[69], PV[68], PV[67], (u32)(0), PV[66]);  // @448_61dcd0
  ecx = edx = 0;  // @449_61dcd0
  eax = (u32)(esi + 556);  // @450_61dcd0
  PV[71] = (u32)(eax);  // @451_61dcd0
  eax = ext_6204a0_cdecl1(PV[71]);  // @452_61dcd0
  ecx = edx = 0;  // @453_61dcd0
  goto L61ee35;  // @454_61dcd0
  L61e24b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @456_61dcd0
  eax = (u32)(esi + 424);  // @457_61dcd0
  PV[72] = (u32)(eax);  // @458_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @459_61dcd0
  eax = (eax - ecx);  // @460_61dcd0
  FL[3] = eax;  // @461_61dcd0
  PV[73] = (u32)(eax);  // @462_61dcd0
  eax = (u32)(ecx + edi);  // @463_61dcd0
  PV[74] = (u32)(eax);  // @464_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 340), sizeof v); (u32)v; }));  // @465_61dcd0
  PV[75] = (u32)(eax);  // @466_61dcd0
  PV[76] = (u32)(ebx);  // @467_61dcd0
  PV[77] = (u32)(esi);  // @468_61dcd0
  eax = ext_6211c0_cdecl6(PV[77], PV[76], PV[75], PV[74], PV[73], PV[72]);  // @469_61dcd0
  ecx = edx = 0;  // @470_61dcd0
  FL[2] = (eax & eax);  // @471_61dcd0
  if (FL[2] != 0) goto L61efa4;  // @472_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @473_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @474_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @475_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @476_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @477_61dcd0
  if (FL[0] == FL[1]) goto L61e2bf;  // @478_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 340), sizeof v); (u32)v; }));  // @479_61dcd0
  PV[78] = (u32)(esi);  // @480_61dcd0
  PV[79] = (u32)(ecx);  // @481_61dcd0
  PV[80] = (u32)(eax);  // @482_61dcd0
  PV[81] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @483_61dcd0
  PV[82] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @484_61dcd0
  eax = ext_61cd60_cdecl6(PV[82], PV[81], PV[80], (u32)(0), PV[79], PV[78]);  // @485_61dcd0
  ecx = edx = 0;  // @486_61dcd0
  FL[2] = (eax & eax);  // @487_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @488_61dcd0
  L61e2bf:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @490_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @491_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @492_61dcd0
  FL[2] = (eax & eax);  // @493_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @494_61dcd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @495_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(40);  // @496_61dcd0
  if (FL[0] == FL[1]) goto L61e2f4;  // @497_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(78);  // @498_61dcd0
  if (FL[0] != FL[1]) goto L61e374;  // @499_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }); FL[1] = (u32)(79);  // @500_61dcd0
  if (FL[0] != FL[1]) goto L61e374;  // @501_61dcd0
  L61e2f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @503_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @504_61dcd0
  if (FL[0] != FL[1]) goto L61e319;  // @505_61dcd0
  eax = (u32)(esi + 556);  // @506_61dcd0
  PV[83] = (u32)(eax);  // @507_61dcd0
  eax = ext_6206e0_cdecl1(PV[83]);  // @508_61dcd0
  ecx = edx = 0;  // @509_61dcd0
  FL[2] = (eax & eax);  // @510_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @511_61dcd0
  L61e319:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @513_61dcd0
  { u8 v = (u8)((u32)(41)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @514_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @515_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @516_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @517_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @518_61dcd0
  if (FL[0] != FL[1]) goto L61e34d;  // @519_61dcd0
  eax = (u32)(esi + 556);  // @520_61dcd0
  PV[84] = (u32)(eax);  // @521_61dcd0
  eax = ext_6206e0_cdecl1(PV[84]);  // @522_61dcd0
  ecx = edx = 0;  // @523_61dcd0
  FL[2] = (eax & eax);  // @524_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @525_61dcd0
  L61e34d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @527_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @528_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @529_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @530_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @531_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @532_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @533_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @534_61dcd0
  L61e374:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @536_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @537_61dcd0
  eax = 0;  // @538_61dcd0
  FL[3] = eax;  // @539_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(34);  // @540_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @541_61dcd0
  PV[85] = (u32)(eax);  // @542_61dcd0
  PV[86] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @543_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @544_61dcd0
  PV[87] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @545_61dcd0
  PV[88] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @546_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @547_61dcd0
  PV[89] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @548_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @549_61dcd0
  PV[90] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @550_61dcd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[90], PV[89], PV[88], PV[87], PV[86], PV[85]);  // @551_61dcd0
  ecx = edx = 0;  // @552_61dcd0
  eax = (u32)(esi + 556);  // @553_61dcd0
  PV[91] = (u32)(eax);  // @554_61dcd0
  eax = ext_6204a0_cdecl1(PV[91]);  // @555_61dcd0
  ecx = edx = 0;  // @556_61dcd0
  goto L61ee35;  // @557_61dcd0
  L61e3bb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @559_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @560_61dcd0
  eax = (eax - ecx);  // @561_61dcd0
  FL[3] = eax;  // @562_61dcd0
  PV[92] = (u32)(eax);  // @563_61dcd0
  eax = (u32)(ecx + edi);  // @564_61dcd0
  PV[93] = (u32)(eax);  // @565_61dcd0
  PV[94] = (u32)(ebx);  // @566_61dcd0
  PV[95] = (u32)(esi);  // @567_61dcd0
  eax = ext_6218c0_cdecl4(PV[95], PV[94], PV[93], PV[92]);  // @568_61dcd0
  ecx = edx = 0;  // @569_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @570_61dcd0
  edx = eax;  // @571_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @572_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @573_61dcd0
  FL[2] = (ecx & ecx);  // @574_61dcd0
  if (FL[2] == 0) goto L61e44b;  // @575_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @576_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @577_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @578_61dcd0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; }));  // @579_61dcd0
  FL[3] = ecx;  // @580_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @581_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @582_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @583_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @584_61dcd0
  if (FL[0] == FL[1]) goto L61e451;  // @585_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @586_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @587_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @588_61dcd0
  PV[96] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @589_61dcd0
  PV[97] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @590_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 29), sizeof v); (u32)v; }));  // @591_61dcd0
  PV[98] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @592_61dcd0
  PV[99] = (u32)(eax);  // @593_61dcd0
  PV[100] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @594_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @595_61dcd0
  PV[101] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @596_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(PV[101], PV[100], PV[99], PV[98], PV[97], PV[96], (u32)(0), (u32)(0), (u32)(0));  // @597_61dcd0
  ecx = edx = 0;  // @598_61dcd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @599_61dcd0
  goto L61e451;  // @600_61dcd0
  L61e44b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @602_61dcd0
  L61e451:;
  FL[2] = (edx & edx);  // @604_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @605_61dcd0
  eax = edx;  // @606_61dcd0
  return eax;  // @607_61dcd0
  L61e462:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @609_61dcd0
  if (FL[0] == FL[1]) goto L61e49b;  // @610_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @611_61dcd0
  eax = (eax - 1);  // @612_61dcd0
  FL[3] = eax;  // @613_61dcd0
  PV[102] = (u32)(eax);  // @614_61dcd0
  eax = (u32)(edi + 1);  // @615_61dcd0
  PV[103] = (u32)(eax);  // @616_61dcd0
  eax = (u32)(esi + 556);  // @617_61dcd0
  PV[104] = (u32)(ebx);  // @618_61dcd0
  PV[105] = (u32)(eax);  // @619_61dcd0
  eax = ext_620840_cdecl4(PV[105], PV[104], PV[103], PV[102]);  // @620_61dcd0
  ecx = edx = 0;  // @621_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @622_61dcd0
  FL[2] = (eax & eax);  // @623_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @624_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @625_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @626_61dcd0
  L61e49b:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 452), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @628_61dcd0
  if (FL[0] != FL[1]) goto L61e4c4;  // @629_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 620), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @630_61dcd0
  if (FL[0] != FL[1]) goto L61e4c4;  // @631_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @632_61dcd0
  FL[2] = (eax & eax);  // @633_61dcd0
  if (FL[2] == 0) goto L61e4c4;  // @634_61dcd0
  PV[106] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @635_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[106]);  // @636_61dcd0
  ecx = edx = 0;  // @637_61dcd0
  FL[2] = (eax & eax);  // @638_61dcd0
  if (FL[2] == 0) goto L61ef28;  // @639_61dcd0
  L61e4c4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @641_61dcd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 612), &v, sizeof v); }  // @642_61dcd0
  if (FL[0] != FL[1]) goto L61e514;  // @643_61dcd0
  eax = (u32)(esi + 456);  // @644_61dcd0
  PV[107] = (u32)(eax);  // @645_61dcd0
  eax = ext_61fd60_cdecl3(PV[107], (u32)(7070396), (u32)(32));  // @646_61dcd0
  ecx = edx = 0;  // @647_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @648_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @649_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @650_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @651_61dcd0
  L61e507:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @653_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @654_61dcd0
  L61e514:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @656_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @657_61dcd0
  eax = (eax - ecx);  // @658_61dcd0
  FL[3] = eax;  // @659_61dcd0
  PV[108] = (u32)(eax);  // @660_61dcd0
  eax = (u32)(ecx + edi);  // @661_61dcd0
  PV[109] = (u32)(eax);  // @662_61dcd0
  eax = (u32)(esi + 424);  // @663_61dcd0
  PV[110] = (u32)(ebx);  // @664_61dcd0
  PV[111] = (u32)(eax);  // @665_61dcd0
  eax = ext_620840_cdecl4(PV[111], PV[110], PV[109], PV[108]);  // @666_61dcd0
  ecx = edx = 0;  // @667_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @668_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @669_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @670_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @671_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @672_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @673_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @674_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @675_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @676_61dcd0
  goto L61ee35;  // @677_61dcd0
  L61e564:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @679_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @680_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @681_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @682_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @683_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @684_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @685_61dcd0
  PV[112] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @686_61dcd0
  PV[113] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @687_61dcd0
  PV[114] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @688_61dcd0
  PV[115] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @689_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @690_61dcd0
  PV[116] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @691_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(PV[116], PV[115], (u32)(0), (u32)(0), (u32)(0), PV[114], PV[113], PV[112], (u32)(0));  // @692_61dcd0
  ecx = edx = 0;  // @693_61dcd0
  goto L61ee35;  // @694_61dcd0
  L61e5af:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @696_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @697_61dcd0
  PV[117] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @698_61dcd0
  eax = (u32)(esi + 424);  // @699_61dcd0
  PV[118] = (u32)(edi);  // @700_61dcd0
  PV[119] = (u32)(ebx);  // @701_61dcd0
  PV[120] = (u32)(eax);  // @702_61dcd0
  eax = ext_620840_cdecl4(PV[120], PV[119], PV[118], PV[117]);  // @703_61dcd0
  ecx = edx = 0;  // @704_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @705_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @706_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @707_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @708_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @709_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @710_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @711_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @712_61dcd0
  if (FL[0] == FL[1]) goto L61e624;  // @713_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @714_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @715_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @716_61dcd0
  PV[121] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @717_61dcd0
  PV[122] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @718_61dcd0
  PV[123] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @719_61dcd0
  PV[124] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @720_61dcd0
  PV[125] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @721_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @722_61dcd0
  PV[126] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @723_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(eax))(PV[126], PV[125], PV[124], PV[123], PV[122], PV[121]);  // @724_61dcd0
  ecx = edx = 0;  // @725_61dcd0
  goto L61ee35;  // @726_61dcd0
  L61e624:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @728_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @729_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @730_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @731_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @732_61dcd0
  PV[127] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @733_61dcd0
  PV[128] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @734_61dcd0
  PV[129] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @735_61dcd0
  PV[130] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @736_61dcd0
  PV[131] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @737_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @738_61dcd0
  PV[132] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @739_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(PV[132], PV[131], (u32)(0), (u32)(0), (u32)(0), PV[130], PV[129], PV[128], PV[127]);  // @740_61dcd0
  ecx = edx = 0;  // @741_61dcd0
  goto L61ee35;  // @742_61dcd0
  L61e663:;
  PV[133] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @744_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; });  // @745_61dcd0
  PV[134] = (u32)(edi);  // @746_61dcd0
  PV[135] = (u32)(ebx);  // @747_61dcd0
  eax = ((u32( *)(u32, u32, u32))(eax))(PV[135], PV[134], PV[133]);  // @748_61dcd0
  ecx = edx = 0;  // @749_61dcd0
  FL[2] = (eax & eax);  // @750_61dcd0
  if (FL[2] == 0) goto L61e683;  // @751_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @752_61dcd0
  goto L61ee35;  // @753_61dcd0
  L61e683:;
  PV[136] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @755_61dcd0
  eax = (u32)(esi + 424);  // @756_61dcd0
  PV[137] = (u32)(edi);  // @757_61dcd0
  PV[138] = (u32)(ebx);  // @758_61dcd0
  PV[139] = (u32)(eax);  // @759_61dcd0
  eax = ext_620840_cdecl4(PV[139], PV[138], PV[137], PV[136]);  // @760_61dcd0
  ecx = edx = 0;  // @761_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @762_61dcd0
  FL[2] = (eax & eax);  // @763_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @764_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @765_61dcd0
  if (FL[0] == FL[1]) goto L61e6d4;  // @766_61dcd0
  PV[140] = (u32)(eax);  // @767_61dcd0
  eax = (u32)(esi + 344);  // @768_61dcd0
  PV[141] = (u32)(eax);  // @769_61dcd0
  eax = ext_61fd60_cdecl3(PV[141], PV[140], (u32)(32));  // @770_61dcd0
  ecx = edx = 0;  // @771_61dcd0
  ecx = eax;  // @772_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @773_61dcd0
  FL[2] = (ecx & ecx);  // @774_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @775_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @776_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = eax;  // @777_61dcd0
  if (FL[0] == FL[1]) goto L61e6ef;  // @778_61dcd0
  L61e6d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @780_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @781_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @782_61dcd0
  goto L61ee35;  // @783_61dcd0
  L61e6ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @785_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @786_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @787_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @788_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @789_61dcd0
  goto L61ee35;  // @790_61dcd0
  L61e711:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @792_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @793_61dcd0
  PV[142] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @794_61dcd0
  eax = (u32)(esi + 424);  // @795_61dcd0
  PV[143] = (u32)(edi);  // @796_61dcd0
  PV[144] = (u32)(ebx);  // @797_61dcd0
  PV[145] = (u32)(eax);  // @798_61dcd0
  eax = ext_620840_cdecl4(PV[145], PV[144], PV[143], PV[142]);  // @799_61dcd0
  ecx = edx = 0;  // @800_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @801_61dcd0
  FL[2] = (eax & eax);  // @802_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @803_61dcd0
  PV[146] = (u32)(eax);  // @804_61dcd0
  eax = (u32)(esi + 456);  // @805_61dcd0
  PV[147] = (u32)(eax);  // @806_61dcd0
  eax = ext_61fd60_cdecl3(PV[147], PV[146], (u32)(32));  // @807_61dcd0
  ecx = edx = 0;  // @808_61dcd0
  ecx = eax;  // @809_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @810_61dcd0
  FL[2] = (ecx & ecx);  // @811_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @812_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @813_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = eax;  // @814_61dcd0
  if (FL[0] != FL[1]) goto L61e6d4;  // @815_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @816_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @817_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @818_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @819_61dcd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @820_61dcd0
  goto L61ee35;  // @821_61dcd0
  L61e78c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @823_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 328), &v, sizeof v); }  // @824_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 324), &v, sizeof v); }  // @825_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @826_61dcd0
  PV[148] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @827_61dcd0
  eax = (u32)(esi + 556);  // @828_61dcd0
  PV[149] = (u32)(edi);  // @829_61dcd0
  PV[150] = (u32)(ebx);  // @830_61dcd0
  PV[151] = (u32)(eax);  // @831_61dcd0
  eax = ext_620840_cdecl4(PV[151], PV[150], PV[149], PV[148]);  // @832_61dcd0
  ecx = edx = 0;  // @833_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 324), &v, sizeof v); }  // @834_61dcd0
  FL[2] = (eax & eax);  // @835_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @836_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @837_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @838_61dcd0
  goto L61ee35;  // @839_61dcd0
  L61e7dd:;
  PV[152] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @841_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 56), sizeof v); (u32)v; });  // @842_61dcd0
  PV[153] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @843_61dcd0
  PV[154] = (u32)(edi);  // @844_61dcd0
  PV[155] = (u32)(ebx);  // @845_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32))(eax))(PV[155], PV[154], PV[153], PV[152]);  // @846_61dcd0
  ecx = edx = 0;  // @847_61dcd0
  FL[2] = (eax & eax);  // @848_61dcd0
  if (FL[2] == 0) goto L61eee5;  // @849_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @850_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @851_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @852_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @853_61dcd0
  eax = (eax - ecx);  // @854_61dcd0
  FL[3] = eax;  // @855_61dcd0
  PV[156] = (u32)(eax);  // @856_61dcd0
  eax = (u32)(ecx + edi);  // @857_61dcd0
  PV[157] = (u32)(eax);  // @858_61dcd0
  eax = (u32)(esi + 556);  // @859_61dcd0
  PV[158] = (u32)(ebx);  // @860_61dcd0
  PV[159] = (u32)(eax);  // @861_61dcd0
  eax = ext_620840_cdecl4(PV[159], PV[158], PV[157], PV[156]);  // @862_61dcd0
  ecx = edx = 0;  // @863_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @864_61dcd0
  FL[2] = (eax & eax);  // @865_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @866_61dcd0
  PV[160] = (u32)(eax);  // @867_61dcd0
  eax = ext_620120_cdecl1(PV[160]);  // @868_61dcd0
  ecx = edx = 0;  // @869_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @870_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 328), &v, sizeof v); }  // @871_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @872_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @873_61dcd0
  goto L61ee35;  // @874_61dcd0
  L61e84d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @876_61dcd0
  if (FL[0] == FL[1]) goto L61e8a4;  // @877_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @878_61dcd0
  if (FL[0] == FL[1]) goto L61e8a4;  // @879_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @880_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @881_61dcd0
  eax = (eax - ecx);  // @882_61dcd0
  FL[3] = eax;  // @883_61dcd0
  PV[161] = (u32)(eax);  // @884_61dcd0
  eax = (u32)(ecx + edi);  // @885_61dcd0
  PV[162] = (u32)(eax);  // @886_61dcd0
  eax = (u32)(esi + 556);  // @887_61dcd0
  PV[163] = (u32)(ebx);  // @888_61dcd0
  PV[164] = (u32)(eax);  // @889_61dcd0
  eax = ext_620840_cdecl4(PV[164], PV[163], PV[162], PV[161]);  // @890_61dcd0
  ecx = edx = 0;  // @891_61dcd0
  FL[2] = (eax & eax);  // @892_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @893_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @894_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @895_61dcd0
  PV[165] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 328), sizeof v); (u32)v; });  // @896_61dcd0
  PV[166] = (u32)(eax);  // @897_61dcd0
  PV[167] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @898_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @899_61dcd0
  PV[168] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; });  // @900_61dcd0
  PV[169] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @901_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[169], PV[168], PV[167], PV[166], PV[165]);  // @902_61dcd0
  ecx = edx = 0;  // @903_61dcd0
  L61e8a4:;
  eax = (u32)(esi + 556);  // @905_61dcd0
  PV[170] = (u32)(eax);  // @906_61dcd0
  eax = ext_6204a0_cdecl1(PV[170]);  // @907_61dcd0
  ecx = edx = 0;  // @908_61dcd0
  goto L61ee35;  // @909_61dcd0
  L61e8b8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 328), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @911_61dcd0
  if (FL[0] == FL[1]) goto L61e8eb;  // @912_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @913_61dcd0
  if (FL[0] == FL[1]) goto L61e8eb;  // @914_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @915_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @916_61dcd0
  PV[171] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 328), sizeof v); (u32)v; });  // @917_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @918_61dcd0
  PV[172] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @919_61dcd0
  PV[173] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; });  // @920_61dcd0
  PV[174] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @921_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[174], PV[173], PV[172], (u32)(0), PV[171]);  // @922_61dcd0
  ecx = edx = 0;  // @923_61dcd0
  L61e8eb:;
  eax = (u32)(esi + 556);  // @925_61dcd0
  PV[175] = (u32)(eax);  // @926_61dcd0
  eax = ext_6204a0_cdecl1(PV[175]);  // @927_61dcd0
  ecx = edx = 0;  // @928_61dcd0
  goto L61ee35;  // @929_61dcd0
  L61e8ff:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @931_61dcd0
  if (FL[0] == FL[1]) goto L61e913;  // @932_61dcd0
  PV[176] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @933_61dcd0
  PV[177] = (u32)(edi);  // @934_61dcd0
  PV[178] = (u32)(ebx);  // @935_61dcd0
  PV[179] = (u32)(esi);  // @936_61dcd0
  eax = ext_620cb0_cdecl4(PV[179], PV[178], PV[177], PV[176]);  // @937_61dcd0
  ecx = edx = 0;  // @938_61dcd0
  L61e913:;
  PV[180] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @940_61dcd0
  eax = (u32)(EBP + 28);  // @941_61dcd0
  PV[181] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @942_61dcd0
  PV[182] = (u32)(eax);  // @943_61dcd0
  PV[183] = (u32)(ebx);  // @944_61dcd0
  PV[184] = (u32)(esi);  // @945_61dcd0
  eax = ext_61dba0_cdecl5(PV[184], PV[183], PV[182], PV[181], PV[180]);  // @946_61dcd0
  ecx = edx = 0;  // @947_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @948_61dcd0
  if (FL[0] != FL[1]) goto L61ee35;  // @949_61dcd0
  { u32 v = (u32)((u32)(6421776)); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @950_61dcd0
  return eax;  // @951_61dcd0
  L61e942:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 608), sizeof v); (u32)v; });  // @953_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; }); FL[1] = eax;  // @954_61dcd0
  if (FL[0] < FL[1]) goto L61e9bd;  // @955_61dcd0
  FL[2] = (eax & eax);  // @956_61dcd0
  if (FL[2] == 0) goto L61e996;  // @957_61dcd0
  eax = (eax + eax);  // @958_61dcd0
  FL[3] = eax;  // @959_61dcd0
  PV[185] = (u32)(eax);  // @960_61dcd0
  PV[186] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @961_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 608), &v, sizeof v); }  // @962_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @963_61dcd0
  eax = ((u32( *)(u32, u32))(eax))(PV[186], PV[185]);  // @964_61dcd0
  ecx = edx = 0;  // @965_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @966_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 604), &v, sizeof v); }  // @967_61dcd0
  FL[2] = (ecx & ecx);  // @968_61dcd0
  if (FL[2] == 0) goto L61e9b0;  // @969_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 608), sizeof v); (u32)v; });  // @970_61dcd0
  eax = (eax << (u32)(2));  // @971_61dcd0
  FL[3] = eax;  // @972_61dcd0
  PV[187] = (u32)(eax);  // @973_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @974_61dcd0
  PV[188] = (u32)(ecx);  // @975_61dcd0
  eax = ((u32( *)(u32, u32))(eax))(PV[188], PV[187]);  // @976_61dcd0
  ecx = edx = 0;  // @977_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 508), &v, sizeof v); }  // @978_61dcd0
  goto L61e9b0;  // @979_61dcd0
  L61e996:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @981_61dcd0
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(esi + 608), &v, sizeof v); }  // @982_61dcd0
  eax = ((u32( *)(u32))(eax))((u32)(32));  // @983_61dcd0
  ecx = edx = 0;  // @984_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 604), &v, sizeof v); }  // @985_61dcd0
  L61e9b0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @987_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @988_61dcd0
  L61e9bd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @990_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @991_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @992_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @993_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @994_61dcd0
  PV[189] = (u32)(esi);  // @995_61dcd0
  eax = ext_61ffb0_cdecl1(PV[189]);  // @996_61dcd0
  ecx = edx = 0;  // @997_61dcd0
  edx = eax;  // @998_61dcd0
  FL[2] = (edx & edx);  // @999_61dcd0
  if ((s32)FL[2] < 0) goto L61ef10;  // @1000_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1001_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1002_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1003_61dcd0
  ecx = (u32)(edx*8);  // @1004_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 504), &v, sizeof v); }  // @1005_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1006_61dcd0
  ecx = (ecx - edx);  // @1007_61dcd0
  FL[3] = ecx;  // @1008_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1009_61dcd0
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1010_61dcd0
  goto L61ee35;  // @1011_61dcd0
  L61ea1d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @1013_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @1014_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }); FL[1] = (u32)(124);  // @1015_61dcd0
  if (FL[0] == FL[1]) goto L61eee5;  // @1016_61dcd0
  { u8 v = (u8)((u32)(44)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @1017_61dcd0
  goto L61ee35;  // @1018_61dcd0
  L61ea3c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @1020_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @1021_61dcd0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @1022_61dcd0
  FL[0] = (eax & 0xff); FL[1] = (u32)(44);  // @1023_61dcd0
  if (FL[0] == FL[1]) goto L61eee5;  // @1024_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1025_61dcd0
  if (FL[0] == FL[1]) goto L61ea8c;  // @1026_61dcd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1027_61dcd0
  if (FL[2] != 0) goto L61ea8c;  // @1028_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1029_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1030_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 - 4), sizeof v); (u32)v; });  // @1031_61dcd0
  ecx = (u32)(eax*8);  // @1032_61dcd0
  ecx = (ecx - eax);  // @1033_61dcd0
  FL[3] = ecx;  // @1034_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1035_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @1036_61dcd0
  if (FL[0] == FL[1]) goto L61ea8c;  // @1037_61dcd0
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1038_61dcd0
  L61ea8c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @1040_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @1041_61dcd0
  { u8 v = (u8)((u32)(124)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @1042_61dcd0
  goto L61ee35;  // @1043_61dcd0
  L61eaa1:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 620), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1045_61dcd0
  if (FL[0] == FL[1]) goto L61eb87;  // @1046_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1047_61dcd0
  if (FL[0] != FL[1]) goto L61eac0;  // @1048_61dcd0
  FL[0] = ecx; FL[1] = (u32)(52);  // @1049_61dcd0
  if (FL[0] != FL[1]) goto L61eb87;  // @1050_61dcd0
  L61eac0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1052_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1053_61dcd0
  eax = (eax - ecx);  // @1054_61dcd0
  FL[3] = eax;  // @1055_61dcd0
  PV[190] = (u32)(eax);  // @1056_61dcd0
  eax = (u32)(ecx + edi);  // @1057_61dcd0
  PV[191] = (u32)(eax);  // @1058_61dcd0
  eax = (u32)(esi + 424);  // @1059_61dcd0
  PV[192] = (u32)(ebx);  // @1060_61dcd0
  PV[193] = (u32)(eax);  // @1061_61dcd0
  eax = ext_620840_cdecl4(PV[193], PV[192], PV[191], PV[190]);  // @1062_61dcd0
  ecx = edx = 0;  // @1063_61dcd0
  FL[2] = (eax & eax);  // @1064_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1065_61dcd0
  PV[194] = (u32)(eax);  // @1066_61dcd0
  eax = (u32)(esi + 456);  // @1067_61dcd0
  PV[195] = (u32)(eax);  // @1068_61dcd0
  eax = ext_61fd60_cdecl3(PV[195], PV[194], (u32)(0));  // @1069_61dcd0
  ecx = edx = 0;  // @1070_61dcd0
  ecx = eax;  // @1071_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @1072_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1073_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @1074_61dcd0
  FL[2] = (ecx & ecx);  // @1075_61dcd0
  if (FL[2] == 0) goto L61ef4c;  // @1076_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1077_61dcd0
  if (FL[0] != FL[1]) goto L61ef40;  // @1078_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1079_61dcd0
  if (FL[0] == FL[1]) goto L61eb37;  // @1080_61dcd0
  PV[196] = (u32)(ecx);  // @1081_61dcd0
  PV[197] = (u32)(esi);  // @1082_61dcd0
  eax = ext_620890_cdecl2(PV[197], PV[196]);  // @1083_61dcd0
  ecx = edx = 0;  // @1084_61dcd0
  FL[2] = (eax & eax);  // @1085_61dcd0
  if (FL[2] != 0) goto L61efa4;  // @1086_61dcd0
  goto L61ee35;  // @1087_61dcd0
  L61eb37:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(52);  // @1089_61dcd0
  if (FL[0] == FL[1]) goto L61ef34;  // @1090_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1091_61dcd0
  if (FL[0] == FL[1]) goto L61eb87;  // @1092_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }  // @1093_61dcd0
  PV[198] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @1094_61dcd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @1095_61dcd0
  PV[199] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @1096_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; });  // @1097_61dcd0
  PV[200] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @1098_61dcd0
  PV[201] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; });  // @1099_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[201], (u32)(0), PV[200], PV[199], PV[198]);  // @1100_61dcd0
  ecx = edx = 0;  // @1101_61dcd0
  FL[2] = (eax & eax);  // @1102_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1103_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @1104_61dcd0
  if (FL[2] == 0) goto L61ef1c;  // @1105_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1106_61dcd0
  if (FL[0] != FL[1]) goto L61ee35;  // @1107_61dcd0
  L61eb87:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 452), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1109_61dcd0
  if (FL[0] != FL[1]) goto L61eba7;  // @1110_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @1111_61dcd0
  FL[2] = (eax & eax);  // @1112_61dcd0
  if (FL[2] == 0) goto L61eba7;  // @1113_61dcd0
  PV[202] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1114_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[202]);  // @1115_61dcd0
  ecx = edx = 0;  // @1116_61dcd0
  FL[2] = (eax & eax);  // @1117_61dcd0
  if (FL[2] == 0) goto L61ef28;  // @1118_61dcd0
  L61eba7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1120_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }  // @1121_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1122_61dcd0
  PV[203] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1123_61dcd0
  PV[204] = (u32)(edi);  // @1124_61dcd0
  PV[205] = (u32)(ebx);  // @1125_61dcd0
  PV[206] = (u32)(esi);  // @1126_61dcd0
  eax = ext_620cb0_cdecl4(PV[206], PV[205], PV[204], PV[203]);  // @1127_61dcd0
  ecx = edx = 0;  // @1128_61dcd0
  goto L61ee35;  // @1129_61dcd0
  L61ebce:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1131_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1132_61dcd0
  PV[207] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1133_61dcd0
  PV[208] = (u32)(edi);  // @1134_61dcd0
  PV[209] = (u32)(ebx);  // @1135_61dcd0
  PV[210] = (u32)(esi);  // @1136_61dcd0
  eax = ext_61fb10_cdecl4(PV[210], PV[209], PV[208], PV[207]);  // @1137_61dcd0
  ecx = edx = 0;  // @1138_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 332), &v, sizeof v); }  // @1139_61dcd0
  FL[2] = (eax & eax);  // @1140_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1141_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 504), &v, sizeof v); }  // @1142_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 500), &v, sizeof v); }  // @1143_61dcd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 484), &v, sizeof v); }  // @1144_61dcd0
  goto L61ee35;  // @1145_61dcd0
  L61ec17:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1147_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1148_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1149_61dcd0
  if (FL[0] == FL[1]) goto L61ec7f;  // @1150_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @1151_61dcd0
  eax = ((u32( *)(u32))(eax))((u32)(20));  // @1152_61dcd0
  ecx = edx = 0;  // @1153_61dcd0
  ecx = eax;  // @1154_61dcd0
  FL[2] = (ecx & ecx);  // @1155_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1156_61dcd0
  eax = 0;  // @1157_61dcd0
  FL[3] = eax;  // @1158_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @1159_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(36);  // @1160_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @1161_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @1162_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @1163_61dcd0
  eax = (eax + 1);  // @1164_61dcd0
  FL[3] = eax;  // @1165_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @1166_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1167_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1168_61dcd0
  PV[211] = (u32)(ecx);  // @1169_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @1170_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @1171_61dcd0
  PV[212] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1172_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @1173_61dcd0
  PV[213] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1174_61dcd0
  eax = ((u32( *)(u32, u32, u32))(eax))(PV[213], PV[212], PV[211]);  // @1175_61dcd0
  ecx = edx = 0;  // @1176_61dcd0
  L61ec7f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 484), &v, sizeof v); }  // @1178_61dcd0
  goto L61ee35;  // @1179_61dcd0
  L61ec8e:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1181_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1182_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1183_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1184_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 - 4), sizeof v); (u32)v; });  // @1185_61dcd0
  ecx = (u32)(eax*8);  // @1186_61dcd0
  ecx = (ecx - eax);  // @1187_61dcd0
  FL[3] = ecx;  // @1188_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1189_61dcd0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1190_61dcd0
  goto L61ee35;  // @1191_61dcd0
  L61ecc6:;
  eax = 0;  // @1193_61dcd0
  FL[3] = eax;  // @1194_61dcd0
  goto L61ecdd;  // @1195_61dcd0
  L61ecca:;
  eax = (u32)(1);  // @1197_61dcd0
  goto L61ecdd;  // @1198_61dcd0
  L61ecd1:;
  eax = (u32)(2);  // @1200_61dcd0
  goto L61ecdd;  // @1201_61dcd0
  L61ecd8:;
  eax = (u32)(3);  // @1203_61dcd0
  L61ecdd:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1205_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1206_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1207_61dcd0
  FL[2] = (eax & eax);  // @1208_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1209_61dcd0
  if (FL[2] == 0) goto L61ecf5;  // @1210_61dcd0
  eax = (eax - 1);  // @1211_61dcd0
  FL[3] = eax;  // @1212_61dcd0
  L61ecf5:;
  PV[214] = (u32)(esi);  // @1214_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1215_61dcd0
  eax = ext_61ffb0_cdecl1(PV[214]);  // @1216_61dcd0
  ecx = edx = 0;  // @1217_61dcd0
  FL[2] = (eax & eax);  // @1218_61dcd0
  if ((s32)FL[2] < 0) goto L61ef10;  // @1219_61dcd0
  PV[215] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1220_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @1221_61dcd0
  edx = (u32)(eax*8);  // @1222_61dcd0
  edx = (edx - eax);  // @1223_61dcd0
  FL[3] = edx;  // @1224_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1225_61dcd0
  edx = (edx << (u32)(2));  // @1226_61dcd0
  FL[3] = edx;  // @1227_61dcd0
  PV[216] = (u32)(edi);  // @1228_61dcd0
  PV[217] = (u32)(ebx);  // @1229_61dcd0
  PV[218] = (u32)(esi);  // @1230_61dcd0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edx + eax), &v, sizeof v); }  // @1231_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1232_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1233_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax + 4), &v, sizeof v); }  // @1234_61dcd0
  eax = ext_61fb10_cdecl4(PV[218], PV[217], PV[216], PV[215]);  // @1235_61dcd0
  ecx = edx = 0;  // @1236_61dcd0
  FL[2] = (eax & eax);  // @1237_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1238_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1239_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1240_61dcd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @1241_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 8), &v, sizeof v); }  // @1242_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1243_61dcd0
  eax = (eax - edi);  // @1244_61dcd0
  FL[3] = eax;  // @1245_61dcd0
  eax = (eax + 1);  // @1246_61dcd0
  FL[3] = eax;  // @1247_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 492), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 492), &v, sizeof v); }  // @1248_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 492), sizeof v); (u32)v; });  // @1249_61dcd0
  goto L61ee35;  // @1250_61dcd0
  L61ed68:;
  edx = 0;  // @1252_61dcd0
  FL[3] = edx;  // @1253_61dcd0
  goto L61ed7f;  // @1254_61dcd0
  L61ed6c:;
  edx = (u32)(1);  // @1256_61dcd0
  goto L61ed7f;  // @1257_61dcd0
  L61ed73:;
  edx = (u32)(2);  // @1259_61dcd0
  goto L61ed7f;  // @1260_61dcd0
  L61ed7a:;
  edx = (u32)(3);  // @1262_61dcd0
  L61ed7f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1264_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1265_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 504), &v, sizeof v); }  // @1266_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1267_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1268_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1269_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @1270_61dcd0
  ecx = (u32)(eax*8);  // @1271_61dcd0
  ecx = (ecx - eax);  // @1272_61dcd0
  FL[3] = ecx;  // @1273_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1274_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4 + 4), &v, sizeof v); }  // @1275_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1276_61dcd0
  if (FL[0] != FL[1]) goto L61ee35;  // @1277_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1278_61dcd0
  if (FL[0] == FL[1]) goto L61eded;  // @1279_61dcd0
  PV[219] = (u32)(esi);  // @1280_61dcd0
  eax = ext_61cb70_cdecl1(PV[219]);  // @1281_61dcd0
  ecx = edx = 0;  // @1282_61dcd0
  FL[2] = (eax & eax);  // @1283_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1284_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1285_61dcd0
  PV[220] = (u32)(eax);  // @1286_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1287_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @1288_61dcd0
  PV[221] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1289_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @1290_61dcd0
  PV[222] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1291_61dcd0
  eax = ((u32( *)(u32, u32, u32))(eax))(PV[222], PV[221], PV[220]);  // @1292_61dcd0
  ecx = edx = 0;  // @1293_61dcd0
  L61eded:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 484), &v, sizeof v); }  // @1295_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 492), &v, sizeof v); }  // @1296_61dcd0
  goto L61ee35;  // @1297_61dcd0
  L61ee03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1299_61dcd0
  ecx = eax;  // @1300_61dcd0
  ecx = (ecx - (u32)(11));  // @1301_61dcd0
  FL[3] = ecx;  // @1302_61dcd0
  if (FL[3] == 0) goto L61ee1f;  // @1303_61dcd0
  ecx = (ecx - (u32)(2));  // @1304_61dcd0
  FL[3] = ecx;  // @1305_61dcd0
  if (FL[3] != 0) goto L61ee38;  // @1306_61dcd0
  PV[223] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1307_61dcd0
  PV[224] = (u32)(edi);  // @1308_61dcd0
  PV[225] = (u32)(ebx);  // @1309_61dcd0
  PV[226] = (u32)(esi);  // @1310_61dcd0
  eax = ext_620c00_cdecl4(PV[226], PV[225], PV[224], PV[223]);  // @1311_61dcd0
  ecx = edx = 0;  // @1312_61dcd0
  goto L61ee2a;  // @1313_61dcd0
  L61ee1f:;
  PV[227] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1315_61dcd0
  PV[228] = (u32)(edi);  // @1316_61dcd0
  PV[229] = (u32)(ebx);  // @1317_61dcd0
  PV[230] = (u32)(esi);  // @1318_61dcd0
  eax = ext_620d50_cdecl4(PV[230], PV[229], PV[228], PV[227]);  // @1319_61dcd0
  ecx = edx = 0;  // @1320_61dcd0
  L61ee2a:;
  FL[2] = (eax & eax);  // @1322_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1323_61dcd0
  L61ee35:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1325_61dcd0
  L61ee38:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1327_61dcd0
  if (FL[0] == FL[1]) goto L61ee68;  // @1328_61dcd0
  eax = (eax + (u32)(-11));  // @1329_61dcd0
  FL[3] = eax;  // @1330_61dcd0
  FL[0] = eax; FL[1] = (u32)(31);  // @1331_61dcd0
  if (FL[0] > FL[1]) goto L61ee54;  // @1332_61dcd0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6418596), sizeof v); (u32)v; });  // @1333_61dcd0
  switch (eax) {  // @1334_61dcd0
  case 0: goto L61ee68;  // @1335_61dcd0
  case 1: goto L61ee54;  // @1336_61dcd0
  default: __builtin_trap(); }  // @1337_61dcd0
  L61ee54:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(51);  // @1339_61dcd0
  if (FL[0] == FL[1]) goto L61ee68;  // @1340_61dcd0
  PV[231] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1341_61dcd0
  PV[232] = (u32)(edi);  // @1342_61dcd0
  PV[233] = (u32)(ebx);  // @1343_61dcd0
  PV[234] = (u32)(esi);  // @1344_61dcd0
  eax = ext_620cb0_cdecl4(PV[234], PV[233], PV[232], PV[231]);  // @1345_61dcd0
  ecx = edx = 0;  // @1346_61dcd0
  L61ee68:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1348_61dcd0
  eax = (u32)(EBP + 28);  // @1349_61dcd0
  PV[235] = (u32)(eax);  // @1350_61dcd0
  PV[236] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1351_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1352_61dcd0
  PV[237] = (u32)(edi);  // @1353_61dcd0
  PV[238] = (u32)(ebx);  // @1354_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32))(eax))(PV[238], PV[237], PV[236], PV[235]);  // @1355_61dcd0
  ecx = edx = 0;  // @1356_61dcd0
  ecx = eax;  // @1357_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @1358_61dcd0
  goto L61dd0d;  // @1359_61dcd0
  L61ee85:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @1361_61dcd0
  L61ee87:;
  eax = 0;  // @1363_61dcd0
  FL[3] = eax;  // @1364_61dcd0
  return eax;  // @1365_61dcd0
  L61ee90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1367_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1368_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1369_61dcd0
  eax = (u32)(4);  // @1370_61dcd0
  return eax;  // @1371_61dcd0
  L61eea4:;
  eax = (u32)(5);  // @1373_61dcd0
  return eax;  // @1374_61dcd0
  L61eeb0:;
  eax = (u32)(6);  // @1376_61dcd0
  return eax;  // @1377_61dcd0
  L61eebc:;
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @1379_61dcd0
  if (FL[0] != FL[1]) goto L61ee87;  // @1380_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1381_61dcd0
  if (FL[0] == FL[1]) goto L61ef04;  // @1382_61dcd0
  PV[239] = (u32)(ebx);  // @1383_61dcd0
  PV[240] = (u32)(edx);  // @1384_61dcd0
  PV[241] = (u32)(edx);  // @1385_61dcd0
  eax = (u32)(esi + 256);  // @1386_61dcd0
  PV[242] = (u32)(eax);  // @1387_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1388_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[242], (u32)(-4), PV[241], PV[240], PV[239]);  // @1389_61dcd0
  ecx = edx = 0;  // @1390_61dcd0
  FL[0] = eax; FL[1] = (u32)(-1);  // @1391_61dcd0
  if (FL[0] != FL[1]) goto L61eef1;  // @1392_61dcd0
  L61eee5:;
  eax = (u32)(2);  // @1394_61dcd0
  return eax;  // @1395_61dcd0
  L61eef1:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 612), &v, sizeof v); }  // @1397_61dcd0
  eax = 0;  // @1398_61dcd0
  FL[3] = eax;  // @1399_61dcd0
  return eax;  // @1400_61dcd0
  L61ef04:;
  eax = (u32)(3);  // @1402_61dcd0
  return eax;  // @1403_61dcd0
  L61ef10:;
  eax = (u32)(1);  // @1405_61dcd0
  return eax;  // @1406_61dcd0
  L61ef1c:;
  eax = (u32)(21);  // @1408_61dcd0
  return eax;  // @1409_61dcd0
  L61ef28:;
  eax = (u32)(22);  // @1411_61dcd0
  return eax;  // @1412_61dcd0
  L61ef34:;
  eax = (u32)(10);  // @1414_61dcd0
  return eax;  // @1415_61dcd0
  L61ef40:;
  eax = (u32)(12);  // @1417_61dcd0
  return eax;  // @1418_61dcd0
  L61ef4c:;
  eax = (u32)(11);  // @1420_61dcd0
  return eax;  // @1421_61dcd0
  L61ef58:;
  PV[243] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @1423_61dcd0
  { u32 v = (u32)((u32)(6409520)); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @1424_61dcd0
  PV[244] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1425_61dcd0
  PV[245] = (u32)(edi);  // @1426_61dcd0
  PV[246] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @1427_61dcd0
  PV[247] = (u32)(esi);  // @1428_61dcd0
  eax = ext_61d090_cdecl6(PV[247], (u32)(0), PV[246], PV[245], PV[244], PV[243]);  // @1429_61dcd0
  ecx = edx = 0;  // @1430_61dcd0
  return eax;  // @1431_61dcd0
  L61ef81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1433_61dcd0
  FL[0] = ecx; FL[1] = (u32)(12);  // @1434_61dcd0
  if (FL[0] == FL[1]) goto L61ef9f;  // @1435_61dcd0
  eax = 0;  // @1436_61dcd0
  FL[3] = eax;  // @1437_61dcd0
  FL[0] = ecx; FL[1] = (u32)(28);  // @1438_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @1439_61dcd0
  eax = (u32)(eax*8 + 2);  // @1440_61dcd0
  return eax;  // @1441_61dcd0
  L61ef9f:;
  eax = (u32)(17);  // @1443_61dcd0
  L61efa4:;
  return eax;  // @1445_61dcd0
}
// PCREG removed: re-lifted in batch240027.cpp

