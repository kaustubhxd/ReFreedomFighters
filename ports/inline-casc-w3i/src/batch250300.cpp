// batch250300.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5a8360_thiscall2(u32, u32) __asm__("ext_5a8360");
extern "C" u32 THISCALL ext_5aba60_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5aba60");
extern "C" u32 THISCALL ext_5ac5d0_thiscall2(u32, u32) __asm__("ext_5ac5d0");
extern "C" u32 THISCALL ext_5ac600_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5ac600");
extern "C" u32 THISCALL ext_5acac0_thiscall2(u32, u32) __asm__("ext_5acac0");
extern "C" u32 THISCALL ext_5ec090_thiscall3(u32, u32, u32) __asm__("ext_5ec090");
extern "C" u32 THISCALL ext_5ec2b0_thiscall3(u32, u32, u32) __asm__("ext_5ec2b0");
extern "C" u32 THISCALL ext_5ec340_thiscall3(u32, u32, u32) __asm__("ext_5ec340");
extern "C" u32 THISCALL ext_5ec5a0_thiscall2(u32, u32) __asm__("ext_5ec5a0");
extern "C" u32 THISCALL ext_5ec660_thiscall2(u32, u32) __asm__("ext_5ec660");
extern "C" u32 THISCALL ext_5ec670_thiscall3(u32, u32, u32) __asm__("ext_5ec670");
extern "C" u32 THISCALL ext_5ed1e0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5ed1e0");
extern "C" u32 THISCALL ext_5edb00_thiscall2(u32, u32) __asm__("ext_5edb00");
extern "C" u32 THISCALL ext_5edb20_thiscall4(u32, u32, u32, u32) __asm__("ext_5edb20");
extern "C" u32 THISCALL ext_5edb70_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5edb70");
extern "C" u32 THISCALL ext_5edc60_thiscall2(u32, u32) __asm__("ext_5edc60");
extern "C" u32 THISCALL ext_5ee590_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5ee590");
extern "C" u32 THISCALL ext_5eeb00_thiscall2(u32, u32) __asm__("ext_5eeb00");
extern "C" u32 THISCALL ext_5eeb10_thiscall2(u32, u32) __asm__("ext_5eeb10");
extern "C" u32 THISCALL ext_5eeb30_thiscall2(u32, u32) __asm__("ext_5eeb30");
extern "C" u32 THISCALL ext_5eeb40_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5eeb40");
extern "C" u32 THISCALL ext_5eeb80_thiscall2(u32, u32) __asm__("ext_5eeb80");
extern "C" u32 THISCALL ext_5eeb90_thiscall2(u32, u32) __asm__("ext_5eeb90");
extern "C" u32 THISCALL ext_5eeba0_thiscall2(u32, u32) __asm__("ext_5eeba0");
extern "C" u32 THISCALL ext_5eebb0_thiscall2(u32, u32) __asm__("ext_5eebb0");
extern "C" u32 THISCALL ext_5eebc0_thiscall2(u32, u32) __asm__("ext_5eebc0");
extern "C" u32 THISCALL ext_5eebd0_thiscall2(u32, u32) __asm__("ext_5eebd0");
extern "C" u32 THISCALL ext_5eee70_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5eee70");
extern "C" u32 THISCALL ext_5ef000_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5ef000");
extern "C" u32 THISCALL ext_5ef3a0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5ef3a0");
extern "C" u32 THISCALL ext_5f0180_thiscall2(u32, u32) __asm__("ext_5f0180");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5a86c0(u32 ecx_in) {
  u32 W3I_A = 0, W3I_B = 0, W3I_C = 0, W3I_D = 0, W3I_E = 0, W3I_F = 0;
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  { u8 *d_ = (u8 *)(EBP - 0x78); const u8 *s_ = (const u8 *)0x20201000; u32 n_ = 0x70 / 4; __asm__ volatile("rep movsl" : "+D"(d_), "+S"(s_), "+c"(n_) : : "memory"); }   // w3i: same per-case garbage as the exe frame (spec fills both)
  u32 PV[115], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5a86c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @1_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_5a86c0
  if (FL[0] == FL[1]) goto L5a88e4;  // @3_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012088));  // @4_5a86c0
  ecx = edx = 0;  // @5_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @6_5a86c0
  PV[0] = (u32)(eax);  // @7_5a86c0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @8_5a86c0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @9_5a86c0
  eax = ext_5ee590_thiscall6(ecx, PV[2], PV[1], PV[0], (u32)(1), (u32)(0));  // @10_5a86c0
  ecx = edx = 0;  // @11_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @12_5a86c0
  eax = ext_5eeb40_thiscall5(ecx, (u32)(2), (u32)(1), (u32)(48), (u32)(100));  // @13_5a86c0
  edx = 0;  // @14_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @15_5a86c0
  eax = ext_5eebd0_thiscall2(ecx, (u32)(64));  // @16_5a86c0
    // @17_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @18_5a86c0
  eax = ext_5eeb10_thiscall2(ecx, (u32)(16));  // @19_5a86c0
    // @20_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @21_5a86c0
  eax = ext_5eeb30_thiscall2(ecx, (u32)(0));  // @22_5a86c0
    // @23_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @24_5a86c0
  eax = ext_5eeb90_thiscall2(ecx, (u32)(16));  // @25_5a86c0
    // @26_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @27_5a86c0
  eax = ext_5eebb0_thiscall2(ecx, (u32)(10));  // @28_5a86c0
    // @29_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @30_5a86c0
  eax = ext_5eebc0_thiscall2(ecx, (u32)(3));  // @31_5a86c0
    // @32_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @33_5a86c0
  eax = ext_5eeb80_thiscall2(ecx, (u32)(0));  // @34_5a86c0
    // @35_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1596), sizeof v); (u32)v; });  // @36_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(6792920), (u32)(-1));  // @38_5a86c0
  ecx = edx = 0;  // @39_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @40_5a86c0
  if (FL[0] == FL[1]) goto L5a88e4;  // @41_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @43_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_5a86c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @45_5a86c0
  ecx = edx = 0;  // @46_5a86c0
  ecx = (u32)(EBP - 112);  // @47_5a86c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @48_5a86c0
  PV[3] = (u32)(ecx);  // @49_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_5a86c0
  ecx = eax;  // @51_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6880492), PV[3]);  // @52_5a86c0
  ecx = edx = 0;  // @53_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @54_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 2256), &v, sizeof v); }  // @55_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_5a86c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @58_5a86c0
  ecx = edx = 0;  // @59_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 864), sizeof v); (u32)v; });  // @60_5a86c0
  ecx = (ecx - 1);  // @61_5a86c0
  FL[3] = ecx;  // @62_5a86c0
  PV[4] = (u32)(ecx);  // @63_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_5a86c0
  ecx = (u32)(EBP - 68);  // @65_5a86c0
  PV[5] = (u32)(ecx);  // @66_5a86c0
  PV[6] = (u32)(eax);  // @67_5a86c0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 408)))(PV[6], PV[5], (u32)(7012100), PV[4]);  // @68_5a86c0
  ecx = edx = 0;  // @69_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5a86c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @73_5a86c0
  ecx = edx = 0;  // @74_5a86c0
  ecx = (u32)(EBP - 112);  // @75_5a86c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @76_5a86c0
  PV[7] = (u32)(ecx);  // @77_5a86c0
  ecx = (u32)(EBP - 68);  // @78_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @79_5a86c0
  PV[8] = (u32)(ecx);  // @80_5a86c0
  ecx = eax;  // @81_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[8], PV[7]);  // @82_5a86c0
  ecx = edx = 0;  // @83_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2215), sizeof v); (u32)v; });  // @84_5a86c0
  ecx = ebx;  // @85_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012116));  // @87_5a86c0
  ecx = edx = 0;  // @88_5a86c0
  PV[9] = (u32)(eax);  // @89_5a86c0
  ecx = esi;  // @90_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[9], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @91_5a86c0
  ecx = edx = 0;  // @92_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2219), sizeof v); (u32)v; });  // @93_5a86c0
  ecx = ebx;  // @94_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012116));  // @96_5a86c0
  ecx = edx = 0;  // @97_5a86c0
  PV[10] = (u32)(eax);  // @98_5a86c0
  ecx = esi;  // @99_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[10], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @100_5a86c0
  ecx = edx = 0;  // @101_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @102_5a86c0
  FL[0] = eax; FL[1] = (u32)(3);  // @103_5a86c0
  if (FL[0] > FL[1]) goto L5a88c1;  // @104_5a86c0
  switch (eax) {  // @105_5a86c0
  case 0: goto L5a8878;  // @106_5a86c0
  case 1: goto L5a8892;  // @107_5a86c0
  case 2: goto L5a8896;  // @108_5a86c0
  case 3: goto L5a88a7;  // @109_5a86c0
  default: __builtin_trap(); }  // @110_5a86c0
  L5a8878:;
  W3I_A = 1;   // w3i: push 1 (0x5a8878) falls into 0x5a887a
  L5a887a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2215), sizeof v); (u32)v; });  // @113_5a86c0
  eax = ext_5f0180_thiscall2(ecx, W3I_A);  // @114_5a86c0
    // @115_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2256), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @116_5a86c0
  if (FL[0] <= FL[1]) goto L5a88c1;  // @117_5a86c0
  W3I_B = 3; goto L5a88b6;  // @118_5a86c0 (w3i: push 3; jmp)
  L5a8892:;
  W3I_A = 0; goto L5a887a;  // @120_5a86c0 (w3i: push 0; jmp)
  L5a8896:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2215), sizeof v); (u32)v; });  // @122_5a86c0
  eax = ext_5f0180_thiscall2(ecx, (u32)(2));  // @123_5a86c0
    // @124_5a86c0
  W3I_B = 1; goto L5a88b6;  // @125_5a86c0 (w3i: push 1; jmp)
  L5a88a7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2215), sizeof v); (u32)v; });  // @127_5a86c0
  eax = ext_5f0180_thiscall2(ecx, (u32)(2));  // @128_5a86c0
    // @129_5a86c0
  W3I_B = 0;   // w3i: push 0 (0x5a88b4)
  L5a88b6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2219), sizeof v); (u32)v; });  // @131_5a86c0
  eax = ext_5f0180_thiscall2(ecx, W3I_B);  // @132_5a86c0
    // @133_5a86c0
  L5a88c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2215), sizeof v); (u32)v; });  // @135_5a86c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @136_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2256), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @137_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2219), sizeof v); (u32)v; });  // @138_5a86c0
  if (FL[0] <= FL[1]) goto L5a88e0;  // @139_5a86c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @140_5a86c0
  goto L5a88e4;  // @141_5a86c0
  L5a88e0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @143_5a86c0
  L5a88e4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1072), sizeof v); (u32)v; });  // @145_5a86c0
  ecx = ebx;  // @146_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @147_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012132));  // @148_5a86c0
  ecx = edx = 0;  // @149_5a86c0
  PV[11] = (u32)(eax);  // @150_5a86c0
  ecx = esi;  // @151_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[11], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  /*w3i: arity from the exe stack depth*/  // @152_5a86c0
  ecx = edx = 0;  // @153_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @154_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1072), sizeof v); (u32)v; });  // @155_5a86c0
  if (FL[0] == FL[1]) goto L5a893b;  // @156_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(2), (u32)(1), (u32)(58), (u32)(34), (u32)(-1));  // @157_5a86c0
  ecx = edx = 0;  // @158_5a86c0
  PV[12] = (u32)(ecx);  // @159_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1072), sizeof v); (u32)v; });  // @160_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @161_5a86c0
  ecx = edx = 0;  // @162_5a86c0
  goto L5a8946;  // @163_5a86c0
  L5a893b:;
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(2), (u32)(1), (u32)(48), (u32)(34), (u32)(-1));  // @165_5a86c0
  ecx = edx = 0;  // @166_5a86c0
  L5a8946:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1136), sizeof v); (u32)v; });  // @168_5a86c0
  ecx = ebx;  // @169_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @170_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012088));  // @171_5a86c0
  ecx = edx = 0;  // @172_5a86c0
  PV[13] = (u32)(eax);  // @173_5a86c0
  ecx = esi;  // @174_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[13], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @175_5a86c0
  ecx = edx = 0;  // @176_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @177_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1136), sizeof v); (u32)v; });  // @178_5a86c0
  if (FL[0] != FL[1]) goto L5a8997;  // @179_5a86c0
  eax = ext_5edb70_thiscall6(ecx, (u32)(2), (u32)(1), (u32)(48), (u32)(34), (u32)(-1));  // @180_5a86c0
  edx = 0;  // @181_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1136), sizeof v); (u32)v; });  // @182_5a86c0
  eax = ext_5edc60_thiscall2(ecx, (u32)(102));  // @183_5a86c0
    // @184_5a86c0
  W3I_C = 0x40; goto L5a89ab;  // @185_5a86c0 (w3i: push 0x40; jmp)
  L5a8997:;
  eax = ext_5edb70_thiscall6(ecx, (u32)(2), (u32)(1), (u32)(48), (u32)(34), (u32)(-1));  // @187_5a86c0
  edx = 0;  // @188_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1136), sizeof v); (u32)v; });  // @189_5a86c0
  eax = ext_5edc60_thiscall2(ecx, (u32)(64));  // @190_5a86c0
    // @191_5a86c0
  W3I_C = 0x20;   // w3i: push 0x20 (0x5a89a9)
  L5a89ab:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1136), sizeof v); (u32)v; });  // @193_5a86c0
  eax = ext_5edb00_thiscall2(ecx, W3I_C);  // @194_5a86c0
    // @195_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1600), sizeof v); (u32)v; });  // @196_5a86c0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1661), sizeof v); (u32)v; });  // @197_5a86c0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @198_5a86c0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @199_5a86c0
  eax = ext_5aba60_thiscall5(ecx, PV[16], PV[15], PV[14], (u32)(0));  // @200_5a86c0
  ecx = edx = 0;  // @201_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1600), sizeof v); (u32)v; });  // @202_5a86c0
  eax = ext_5ac5d0_thiscall2(ecx, (u32)(-1));  // @203_5a86c0
  ecx = edx = 0;  // @204_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1600), sizeof v); (u32)v; });  // @205_5a86c0
  eax = ext_5acac0_thiscall2(ecx, (u32)(0));  // @206_5a86c0
    // @207_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @208_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1600), sizeof v); (u32)v; });  // @209_5a86c0
  if (FL[0] == FL[1]) goto L5a8a04;  // @210_5a86c0
  W3I_D = 0x6d; W3I_E = 0x3d; goto L5a8a0b;  // @211_5a86c0 (w3i: push 0x3d; push 0x6d; jmp)
  L5a8a04:;
  W3I_D = 0x8d; W3I_E = 0x52;   // w3i: push 0x52; push 0x8d
  L5a8a0b:;
  eax = ext_5ac600_thiscall5(ecx, (u32)(2), (u32)(1), W3I_D, W3I_E);  // @214_5a86c0
    // @215_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1604), sizeof v); (u32)v; });  // @216_5a86c0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1661), sizeof v); (u32)v; });  // @217_5a86c0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1060), sizeof v); (u32)v; });  // @218_5a86c0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @219_5a86c0
  eax = ext_5aba60_thiscall5(ecx, PV[19], PV[18], PV[17], (u32)(0));  // @220_5a86c0
  ecx = edx = 0;  // @221_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1604), sizeof v); (u32)v; });  // @222_5a86c0
  eax = ext_5ac5d0_thiscall2(ecx, (u32)(-1));  // @223_5a86c0
  ecx = edx = 0;  // @224_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1608), sizeof v); (u32)v; });  // @225_5a86c0
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @226_5a86c0
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @227_5a86c0
  eax = ext_5aba60_thiscall5(ecx, PV[21], PV[20], (u32)(0), (u32)(0));  // @228_5a86c0
  ecx = edx = 0;  // @229_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1608), sizeof v); (u32)v; });  // @230_5a86c0
  eax = ext_5ac5d0_thiscall2(ecx, (u32)(-1));  // @231_5a86c0
  ecx = edx = 0;  // @232_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1608), sizeof v); (u32)v; });  // @233_5a86c0
  eax = ext_5ac600_thiscall5(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(0));  // @234_5a86c0
    // @235_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1608), sizeof v); (u32)v; });  // @236_5a86c0
  eax = ext_5acac0_thiscall2(ecx, (u32)(0));  // @237_5a86c0
    // @238_5a86c0
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @239_5a86c0
  ecx = ebx;  // @240_5a86c0
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @241_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012088));  // @242_5a86c0
  ecx = edx = 0;  // @243_5a86c0
  PV[24] = (u32)(eax);  // @244_5a86c0
  ecx = ebx;  // @245_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012144));  // @246_5a86c0
  ecx = edx = 0;  // @247_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1580), sizeof v); (u32)v; });  // @248_5a86c0
  PV[25] = (u32)(eax);  // @249_5a86c0
  eax = ext_5eee70_thiscall5(ecx, PV[25], PV[24], PV[23], PV[22]);  // @250_5a86c0
  ecx = edx = 0;  // @251_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1580), sizeof v); (u32)v; });  // @252_5a86c0
  eax = ext_5ef000_thiscall5(ecx, (u32)(2), (u32)(1), (u32)(48), (u32)(101));  // @253_5a86c0
  ecx = edx = 0;  // @254_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1576), sizeof v); (u32)v; });  // @255_5a86c0
  ecx = ebx;  // @256_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @257_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012088));  // @258_5a86c0
  ecx = edx = 0;  // @259_5a86c0
  PV[26] = (u32)(eax);  // @260_5a86c0
  ecx = esi;  // @261_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[26], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  /*w3i: arity from the exe stack depth*/  // @262_5a86c0
  ecx = edx = 0;  // @263_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1576), sizeof v); (u32)v; });  // @264_5a86c0
  eax = ext_5edb20_thiscall4(ecx, (u32)(1111490560), (u32)(1107820544), (u32)(-1));  // @265_5a86c0
    // @266_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @267_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1576), sizeof v); (u32)v; });  // @268_5a86c0
  if (FL[0] == FL[1]) goto L5a8b20;  // @269_5a86c0
  W3I_F = 0x40; goto L5a8b25;  // @270_5a86c0 (w3i: push 0x40; jmp)
  L5a8b20:;
  W3I_F = 0x80;   // w3i: push 0x80
  L5a8b25:;
  eax = ext_5edc60_thiscall2(ecx, W3I_F);  // @273_5a86c0
    // @274_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1576), sizeof v); (u32)v; });  // @275_5a86c0
  eax = ext_5edb00_thiscall2(ecx, (u32)(16));  // @276_5a86c0
    // @277_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1076), sizeof v); (u32)v; });  // @278_5a86c0
  ecx = ebx;  // @279_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @280_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012156));  // @281_5a86c0
  ecx = edx = 0;  // @282_5a86c0
  PV[27] = (u32)(eax);  // @283_5a86c0
  ecx = esi;  // @284_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[27], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  /*w3i: arity from the exe stack depth*/  // @285_5a86c0
  ecx = edx = 0;  // @286_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1076), sizeof v); (u32)v; });  // @287_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(1), (u32)(1), (u32)(52), (u32)(38), (u32)(-1));  // @288_5a86c0
  ecx = edx = 0;  // @289_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @290_5a86c0
  if (FL[0] != FL[1]) goto L5a8c22;  // @291_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1080), sizeof v); (u32)v; });  // @292_5a86c0
  ecx = ebx;  // @293_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @294_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012088));  // @295_5a86c0
  ecx = edx = 0;  // @296_5a86c0
  PV[28] = (u32)(eax);  // @297_5a86c0
  ecx = esi;  // @298_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[28], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @299_5a86c0
  ecx = edx = 0;  // @300_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1080), sizeof v); (u32)v; });  // @301_5a86c0
  eax = ext_5edb20_thiscall4(ecx, (u32)(1111490560), (u32)(1113587712), (u32)(-1));  // @302_5a86c0
    // @303_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1080), sizeof v); (u32)v; });  // @304_5a86c0
  eax = ext_5edc60_thiscall2(ecx, (u32)(128));  // @305_5a86c0
    // @306_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1080), sizeof v); (u32)v; });  // @307_5a86c0
  eax = ext_5edb00_thiscall2(ecx, (u32)(16));  // @308_5a86c0
    // @309_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1084), sizeof v); (u32)v; });  // @310_5a86c0
  ecx = ebx;  // @311_5a86c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @312_5a86c0
  eax = ext_5a8360_thiscall2(ecx, (u32)(7012156));  // @313_5a86c0
  ecx = edx = 0;  // @314_5a86c0
  PV[29] = (u32)(eax);  // @315_5a86c0
  ecx = esi;  // @316_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 20)))(ecx, PV[29], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @317_5a86c0
  ecx = edx = 0;  // @318_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1084), sizeof v); (u32)v; });  // @319_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(1), (u32)(1), (u32)(52), (u32)(60), (u32)(-1));  // @320_5a86c0
  ecx = edx = 0;  // @321_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1084), sizeof v); (u32)v; });  // @322_5a86c0
  eax = ext_5ec340_thiscall3(ecx, (u32)(4294950400), (u32)(-1));  // @323_5a86c0
  ecx = edx = 0;  // @324_5a86c0
  L5a8c22:;
  eax = (u32)(ebx + 1088);  // @326_5a86c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @327_5a86c0
  { u32 v = (u32)((u32)(48)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @328_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @329_5a86c0
  L5a8c40:;
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @331_5a86c0
  eax = ((u32(*)(u32, u32))(*(u32 *)0x67625c))(PV[30], (u32)(7012068));  // @332_5a86c0
  ecx = edx = 0;  // @333_5a86c0
  edx = 0;  // @334_5a86c0
  FL[3] = edx;  // @335_5a86c0
  edi = eax;  // @336_5a86c0
  edi = (edi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @337_5a86c0
  FL[3] = edi;  // @338_5a86c0
  esi = 0;  // @339_5a86c0
  FL[3] = esi;  // @340_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @341_5a86c0
  if (FL[0] > FL[1]) edi = edx;  // @342_5a86c0
  FL[2] = (edi & edi);  // @343_5a86c0
  if (FL[2] == 0) goto L5a8c88;  // @344_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @345_5a86c0
  L5a8c73:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx), sizeof v); (u32)v; })) & 0xff);  // @347_5a86c0
  ecx = (u32)(esi + 1);  // @348_5a86c0
  edx = (edx + 1);  // @349_5a86c0
  FL[3] = edx;  // @350_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @351_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @352_5a86c0
  esi = ecx;  // @353_5a86c0
  FL[0] = edx; FL[1] = edi;  // @354_5a86c0
  if (FL[0] < FL[1]) goto L5a8c73;  // @355_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @356_5a86c0
  L5a8c88:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @358_5a86c0
  eax = (u32)(esi + 2);  // @359_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @360_5a86c0
  eax = (u32)(eax + eax*2);  // @361_5a86c0
  eax = (u32)(ebx + eax*4);  // @362_5a86c0
  PV[31] = (u32)(eax);  // @363_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[31], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @365_5a86c0
  ecx = edx = 0;  // @366_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @367_5a86c0
  if (FL[0] == FL[1]) goto L5a8ccb;  // @368_5a86c0
  PV[32] = (u32)(ecx);  // @369_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @370_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @371_5a86c0
  ecx = edx = 0;  // @372_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @373_5a86c0
  ecx = (u32)(53);  // @374_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @375_5a86c0
  goto L5a8cf0;  // @376_5a86c0
  L5a8ccb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @378_5a86c0
  eax = (u32)(2863311531);  // @379_5a86c0
  { u64 p_ = (u64)eax * (u64)(u32)(esi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @380_5a86c0
  eax = esi;  // @381_5a86c0
  edx = (edx >> (u32)(2));  // @382_5a86c0
  FL[3] = edx;  // @383_5a86c0
  ecx = (u32)(edx + edx*2);  // @384_5a86c0
  ecx = (ecx + ecx);  // @385_5a86c0
  FL[3] = ecx;  // @386_5a86c0
  eax = (eax - ecx);  // @387_5a86c0
  FL[3] = eax;  // @388_5a86c0
  ecx = (u32)(edx + 3);  // @389_5a86c0
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @390_5a86c0
  ecx = (u32)(ecx + ecx*2);  // @391_5a86c0
  eax = (eax + (u32)(43));  // @392_5a86c0
  FL[3] = eax;  // @393_5a86c0
  ecx = (ecx << (u32)(3));  // @394_5a86c0
  FL[3] = ecx;  // @395_5a86c0
  L5a8cf0:;
  PV[33] = (u32)(ecx);  // @397_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @398_5a86c0
  PV[34] = (u32)(eax);  // @399_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(1), (u32)(1), PV[34], PV[33], (u32)(-1));  // @400_5a86c0
  ecx = edx = 0;  // @401_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @402_5a86c0
  esi = (esi + 1);  // @403_5a86c0
  FL[3] = esi;  // @404_5a86c0
  eax = (eax + (u32)(12));  // @405_5a86c0
  FL[3] = eax;  // @406_5a86c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @407_5a86c0
  edi = (edi + (u32)(4));  // @408_5a86c0
  FL[3] = edi;  // @409_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @410_5a86c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @411_5a86c0
  FL[0] = eax; FL[1] = (u32)(192);  // @412_5a86c0
  if (FL[0] < FL[1]) goto L5a8c40;  // @413_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775388), sizeof v); (u32)v; });  // @414_5a86c0
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @415_5a86c0
  eax = ((u32(*)(u32, u32))(esi))(PV[35], (u32)(7012088));  // @416_5a86c0
  ecx = edx = 0;  // @417_5a86c0
  edx = 0;  // @418_5a86c0
  FL[3] = edx;  // @419_5a86c0
  ecx = eax;  // @420_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @421_5a86c0
  FL[3] = ecx;  // @422_5a86c0
  edi = 0;  // @423_5a86c0
  FL[3] = edi;  // @424_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @425_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @426_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @427_5a86c0
  FL[2] = (ecx & ecx);  // @428_5a86c0
  if (FL[2] == 0) goto L5a8d6b;  // @429_5a86c0
  ebx = ecx;  // @430_5a86c0
  L5a8d51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @432_5a86c0
  ecx = (u32)(edi + 1);  // @433_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax), sizeof v); (u32)v; })) & 0xff);  // @434_5a86c0
  edx = (edx + 1);  // @435_5a86c0
  FL[3] = edx;  // @436_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @437_5a86c0
  if (FL[0] != FL[1]) ecx = edi;  // @438_5a86c0
  edi = ecx;  // @439_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @440_5a86c0
  if (FL[0] < FL[1]) goto L5a8d51;  // @441_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @442_5a86c0
  L5a8d6b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1140), sizeof v); (u32)v; });  // @444_5a86c0
  edi = (u32)(edi + 2);  // @445_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @446_5a86c0
  eax = (u32)(edi + edi*2);  // @447_5a86c0
  eax = (u32)(ebx + eax*4);  // @448_5a86c0
  PV[36] = (u32)(eax);  // @449_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[36], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @450_5a86c0
  ecx = edx = 0;  // @451_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1140), sizeof v); (u32)v; });  // @452_5a86c0
  eax = ext_5edb70_thiscall6(ecx, (u32)(3), (u32)(2), (u32)(0), (u32)(99), (u32)(-1));  // @453_5a86c0
  edx = 0;  // @454_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1140), sizeof v); (u32)v; });  // @455_5a86c0
  eax = ext_5edc60_thiscall2(ecx, (u32)(128));  // @456_5a86c0
    // @457_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1140), sizeof v); (u32)v; });  // @458_5a86c0
  eax = ext_5edb00_thiscall2(ecx, (u32)(16));  // @459_5a86c0
    // @460_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1140), sizeof v); (u32)v; });  // @461_5a86c0
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @462_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @463_5a86c0
  eax = ((u32(*)(u32, u32))(esi))(PV[37], (u32)(7012164));  // @464_5a86c0
  ecx = edx = 0;  // @465_5a86c0
  edx = 0;  // @466_5a86c0
  FL[3] = edx;  // @467_5a86c0
  ecx = eax;  // @468_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @469_5a86c0
  FL[3] = ecx;  // @470_5a86c0
  edi = 0;  // @471_5a86c0
  FL[3] = edi;  // @472_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @473_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @474_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @475_5a86c0
  FL[2] = (ecx & ecx);  // @476_5a86c0
  if (FL[2] == 0) goto L5a8e0c;  // @477_5a86c0
  ebx = ecx;  // @478_5a86c0
  L5a8df2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @480_5a86c0
  ecx = (u32)(edi + 1);  // @481_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax), sizeof v); (u32)v; })) & 0xff);  // @482_5a86c0
  edx = (edx + 1);  // @483_5a86c0
  FL[3] = edx;  // @484_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @485_5a86c0
  if (FL[0] != FL[1]) ecx = edi;  // @486_5a86c0
  edi = ecx;  // @487_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @488_5a86c0
  if (FL[0] < FL[1]) goto L5a8df2;  // @489_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @490_5a86c0
  L5a8e0c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1144), sizeof v); (u32)v; });  // @492_5a86c0
  eax = (u32)(edi + 2);  // @493_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @494_5a86c0
  eax = (u32)(eax + eax*2);  // @495_5a86c0
  eax = (u32)(ebx + eax*4);  // @496_5a86c0
  PV[38] = (u32)(eax);  // @497_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[38], (u32)(0), (u32)(5), (u32)(128), (u32)(14));  // @498_5a86c0
  ecx = edx = 0;  // @499_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1144), sizeof v); (u32)v; });  // @500_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(2), (u32)(0), (u32)(99), (u32)(-1));  // @501_5a86c0
  ecx = edx = 0;  // @502_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1144), sizeof v); (u32)v; });  // @503_5a86c0
  eax = ext_5ec340_thiscall3(ecx, (u32)(2144391168), (u32)(-1));  // @504_5a86c0
  ecx = edx = 0;  // @505_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1144), sizeof v); (u32)v; });  // @506_5a86c0
  { u32 v = (u32)((u32)(7012180)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @507_5a86c0
  { u32 v = (u32)((u32)(7012192)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @508_5a86c0
  { u32 v = (u32)((u32)(7012204)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @509_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @510_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1528), sizeof v); (u32)v; });  // @511_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @512_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1532), sizeof v); (u32)v; });  // @513_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @514_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1536), sizeof v); (u32)v; });  // @515_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @516_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1540), sizeof v); (u32)v; });  // @517_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @518_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1544), sizeof v); (u32)v; });  // @519_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @520_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1548), sizeof v); (u32)v; });  // @521_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @522_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1552), sizeof v); (u32)v; });  // @523_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @524_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1556), sizeof v); (u32)v; });  // @525_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @526_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1560), sizeof v); (u32)v; });  // @527_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @528_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1568), sizeof v); (u32)v; });  // @529_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @530_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1572), sizeof v); (u32)v; });  // @531_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @532_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1564), sizeof v); (u32)v; });  // @533_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @534_5a86c0
  eax = 0;  // @535_5a86c0
  FL[3] = eax;  // @536_5a86c0
  { u32 v = (u32)((u32)(7012212)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @537_5a86c0
  { u32 v = (u32)((u32)(7012224)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @538_5a86c0
  { u32 v = (u32)((u32)(7012236)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @539_5a86c0
  { u32 v = (u32)((u32)(7012244)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @540_5a86c0
  { u32 v = (u32)((u32)(7012256)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @541_5a86c0
  { u32 v = (u32)((u32)(7012264)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @542_5a86c0
  { u32 v = (u32)((u32)(7012272)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @543_5a86c0
  { u32 v = (u32)((u32)(7012280)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @544_5a86c0
  { u32 v = (u32)((u32)(7012288)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @545_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @546_5a86c0
  L5a8f22:;
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax*8 - 96), sizeof v); (u32)v; });  // @548_5a86c0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @549_5a86c0
  eax = ((u32(*)(u32, u32))(esi))(PV[40], PV[39]);  // @550_5a86c0
  ecx = edx = 0;  // @551_5a86c0
  edx = 0;  // @552_5a86c0
  FL[3] = edx;  // @553_5a86c0
  esi = eax;  // @554_5a86c0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @555_5a86c0
  FL[3] = esi;  // @556_5a86c0
  edi = 0;  // @557_5a86c0
  FL[3] = edi;  // @558_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @559_5a86c0
  if (FL[0] > FL[1]) esi = edx;  // @560_5a86c0
  FL[2] = (esi & esi);  // @561_5a86c0
  if (FL[2] == 0) goto L5a8f65;  // @562_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @563_5a86c0
  L5a8f50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx), sizeof v); (u32)v; })) & 0xff);  // @565_5a86c0
  ecx = (u32)(edi + 1);  // @566_5a86c0
  edx = (edx + 1);  // @567_5a86c0
  FL[3] = edx;  // @568_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @569_5a86c0
  if (FL[0] != FL[1]) ecx = edi;  // @570_5a86c0
  edi = ecx;  // @571_5a86c0
  FL[0] = edx; FL[1] = esi;  // @572_5a86c0
  if (FL[0] < FL[1]) goto L5a8f50;  // @573_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @574_5a86c0
  L5a8f65:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @576_5a86c0
  eax = (u32)(edi + 2);  // @577_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 100), sizeof v); (u32)v; });  // @578_5a86c0
  eax = (u32)(eax + eax*2);  // @579_5a86c0
  eax = (u32)(ebx + eax*4);  // @580_5a86c0
  ecx = esi;  // @581_5a86c0
  PV[41] = (u32)(eax);  // @582_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @583_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[41], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @584_5a86c0
  ecx = edx = 0;  // @585_5a86c0
  ecx = esi;  // @586_5a86c0
  eax = ext_5ec5a0_thiscall2(ecx, (u32)(0));  // @587_5a86c0
  edx = 0;  // @588_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @589_5a86c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775388), sizeof v); (u32)v; });  // @590_5a86c0
  eax = (eax + 1);  // @591_5a86c0
  FL[3] = eax;  // @592_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @593_5a86c0
  FL[0] = eax; FL[1] = (u32)(12);  // @594_5a86c0
  if (FL[0] < FL[1]) goto L5a8f22;  // @595_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @596_5a86c0
  edi = esi;  // @597_5a86c0
  if (FL[0] != FL[1]) goto L5a9076;  // @598_5a86c0
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @599_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[42], (u32)(7012088));  // @600_5a86c0
  ecx = edx = 0;  // @601_5a86c0
  edx = 0;  // @602_5a86c0
  FL[3] = edx;  // @603_5a86c0
  ecx = eax;  // @604_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @605_5a86c0
  FL[3] = ecx;  // @606_5a86c0
  esi = 0;  // @607_5a86c0
  FL[3] = esi;  // @608_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @609_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @610_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @611_5a86c0
  FL[2] = (ecx & ecx);  // @612_5a86c0
  if (FL[2] == 0) goto L5a8ffa;  // @613_5a86c0
  ebx = ecx;  // @614_5a86c0
  L5a8fe0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @616_5a86c0
  ecx = (u32)(esi + 1);  // @617_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @618_5a86c0
  edx = (edx + 1);  // @619_5a86c0
  FL[3] = edx;  // @620_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @621_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @622_5a86c0
  esi = ecx;  // @623_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @624_5a86c0
  if (FL[0] < FL[1]) goto L5a8fe0;  // @625_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @626_5a86c0
  L5a8ffa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @628_5a86c0
  eax = (u32)(esi + 2);  // @629_5a86c0
  eax = (u32)(eax + eax*2);  // @630_5a86c0
  eax = (u32)(ebx + eax*4);  // @631_5a86c0
  PV[43] = (u32)(eax);  // @632_5a86c0
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @633_5a86c0
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @634_5a86c0
  eax = ext_5ee590_thiscall6(ecx, PV[45], PV[44], PV[43], (u32)(3), (u32)(0));  // @635_5a86c0
  ecx = edx = 0;  // @636_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @637_5a86c0
  eax = ext_5eeb40_thiscall5(ecx, (u32)(1), (u32)(1), (u32)(183), (u32)(34));  // @638_5a86c0
  edx = 0;  // @639_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @640_5a86c0
  eax = ext_5eebd0_thiscall2(ecx, (u32)(300));  // @641_5a86c0
    // @642_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @643_5a86c0
  eax = ext_5eeb10_thiscall2(ecx, (u32)(16));  // @644_5a86c0
    // @645_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @646_5a86c0
  eax = ext_5eeb90_thiscall2(ecx, (u32)(3));  // @647_5a86c0
    // @648_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @649_5a86c0
  eax = ext_5eeb80_thiscall2(ecx, (u32)(0));  // @650_5a86c0
    // @651_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1592), sizeof v); (u32)v; });  // @652_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @653_5a86c0
  L5a9076:;
  PV[46] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @655_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[46], (u32)(7012088));  // @656_5a86c0
  ecx = edx = 0;  // @657_5a86c0
  edx = 0;  // @658_5a86c0
  FL[3] = edx;  // @659_5a86c0
  ecx = eax;  // @660_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @661_5a86c0
  FL[3] = ecx;  // @662_5a86c0
  esi = 0;  // @663_5a86c0
  FL[3] = esi;  // @664_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @665_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @666_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @667_5a86c0
  FL[2] = (ecx & ecx);  // @668_5a86c0
  if (FL[2] == 0) goto L5a90be;  // @669_5a86c0
  ebx = ecx;  // @670_5a86c0
  L5a90a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @672_5a86c0
  ecx = (u32)(esi + 1);  // @673_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @674_5a86c0
  edx = (edx + 1);  // @675_5a86c0
  FL[3] = edx;  // @676_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @677_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @678_5a86c0
  esi = ecx;  // @679_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @680_5a86c0
  if (FL[0] < FL[1]) goto L5a90a4;  // @681_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @682_5a86c0
  L5a90be:;
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1661), sizeof v); (u32)v; });  // @684_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @685_5a86c0
  eax = (u32)(esi + 2);  // @686_5a86c0
  eax = (u32)(eax + eax*2);  // @687_5a86c0
  eax = (u32)(ebx + eax*4);  // @688_5a86c0
  PV[48] = (u32)(eax);  // @689_5a86c0
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @690_5a86c0
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @691_5a86c0
  eax = ext_5ee590_thiscall6(ecx, PV[50], PV[49], PV[48], (u32)(8), PV[47]);  // @692_5a86c0
  ecx = edx = 0;  // @693_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @694_5a86c0
  eax = ext_5eeb40_thiscall5(ecx, (u32)(1), (u32)(1), (u32)(48), (u32)(130));  // @695_5a86c0
  edx = 0;  // @696_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @697_5a86c0
  eax = ext_5eeb00_thiscall2(ecx, (u32)(1));  // @698_5a86c0
    // @699_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @700_5a86c0
  eax = ext_5eeba0_thiscall2(ecx, (u32)(0));  // @701_5a86c0
    // @702_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @703_5a86c0
  eax = ext_5eeb90_thiscall2(ecx, (u32)(8));  // @704_5a86c0
    // @705_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @706_5a86c0
  eax = ext_5eeb30_thiscall2(ecx, (u32)(8));  // @707_5a86c0
    // @708_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1588), sizeof v); (u32)v; });  // @709_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @710_5a86c0
  PV[51] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1661), sizeof v); (u32)v; });  // @711_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1584), sizeof v); (u32)v; });  // @712_5a86c0
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @713_5a86c0
  PV[53] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @714_5a86c0
  eax = ext_5aba60_thiscall5(ecx, PV[53], PV[52], PV[51], (u32)(0));  // @715_5a86c0
  ecx = edx = 0;  // @716_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1584), sizeof v); (u32)v; });  // @717_5a86c0
  eax = ext_5ac5d0_thiscall2(ecx, (u32)(-1));  // @718_5a86c0
  ecx = edx = 0;  // @719_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1584), sizeof v); (u32)v; });  // @720_5a86c0
  eax = ext_5ac600_thiscall5(ecx, (u32)(3), (u32)(2), (u32)(0), (u32)(49));  // @721_5a86c0
    // @722_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1584), sizeof v); (u32)v; });  // @723_5a86c0
  eax = ext_5acac0_thiscall2(ecx, (u32)(0));  // @724_5a86c0
    // @725_5a86c0
  PV[54] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @726_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[54], (u32)(7012088));  // @727_5a86c0
  ecx = edx = 0;  // @728_5a86c0
  edx = 0;  // @729_5a86c0
  FL[3] = edx;  // @730_5a86c0
  ecx = eax;  // @731_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @732_5a86c0
  FL[3] = ecx;  // @733_5a86c0
  esi = 0;  // @734_5a86c0
  FL[3] = esi;  // @735_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @736_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @737_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @738_5a86c0
  FL[2] = (ecx & ecx);  // @739_5a86c0
  if (FL[2] == 0) goto L5a91cf;  // @740_5a86c0
  ebx = ecx;  // @741_5a86c0
  L5a91b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @743_5a86c0
  ecx = (u32)(esi + 1);  // @744_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @745_5a86c0
  edx = (edx + 1);  // @746_5a86c0
  FL[3] = edx;  // @747_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @748_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @749_5a86c0
  esi = ecx;  // @750_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @751_5a86c0
  if (FL[0] < FL[1]) goto L5a91b5;  // @752_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @753_5a86c0
  L5a91cf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1612), sizeof v); (u32)v; });  // @755_5a86c0
  eax = (u32)(esi + 2);  // @756_5a86c0
  eax = (u32)(eax + eax*2);  // @757_5a86c0
  eax = (u32)(ebx + eax*4);  // @758_5a86c0
  PV[55] = (u32)(eax);  // @759_5a86c0
  PV[56] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1661), sizeof v); (u32)v; });  // @760_5a86c0
  PV[57] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1052), sizeof v); (u32)v; });  // @761_5a86c0
  PV[58] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1056), sizeof v); (u32)v; });  // @762_5a86c0
  eax = ext_5ef3a0_thiscall6(ecx, PV[58], PV[57], PV[56], (u32)(1), PV[55]);  // @763_5a86c0
  ecx = edx = 0;  // @764_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @765_5a86c0
  if (FL[0] == FL[1]) goto L5a92da;  // @766_5a86c0
  PV[59] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @767_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[59], (u32)(7012116));  // @768_5a86c0
  ecx = edx = 0;  // @769_5a86c0
  edx = 0;  // @770_5a86c0
  FL[3] = edx;  // @771_5a86c0
  ecx = eax;  // @772_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @773_5a86c0
  FL[3] = ecx;  // @774_5a86c0
  esi = 0;  // @775_5a86c0
  FL[3] = esi;  // @776_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @777_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @778_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @779_5a86c0
  FL[2] = (ecx & ecx);  // @780_5a86c0
  if (FL[2] == 0) goto L5a924d;  // @781_5a86c0
  ebx = ecx;  // @782_5a86c0
  L5a9233:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @784_5a86c0
  ecx = (u32)(esi + 1);  // @785_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @786_5a86c0
  edx = (edx + 1);  // @787_5a86c0
  FL[3] = edx;  // @788_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @789_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @790_5a86c0
  esi = ecx;  // @791_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @792_5a86c0
  if (FL[0] < FL[1]) goto L5a9233;  // @793_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @794_5a86c0
  L5a924d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @796_5a86c0
  eax = (u32)(esi + 2);  // @797_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @798_5a86c0
  eax = (u32)(eax + eax*2);  // @799_5a86c0
  eax = (u32)(ebx + eax*4);  // @800_5a86c0
  PV[60] = (u32)(eax);  // @801_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[60], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @802_5a86c0
  ecx = edx = 0;  // @803_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @804_5a86c0
  eax = ext_5ec660_thiscall2(ecx, (u32)(10));  // @805_5a86c0
    // @806_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @807_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(1), (u32)(1), (u32)(0), (u32)(0), (u32)(-1));  // @808_5a86c0
  ecx = edx = 0;  // @809_5a86c0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 760) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @810_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @811_5a86c0
  PV[61] = (u32)(eax);  // @812_5a86c0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 756) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @813_5a86c0
  PV[62] = (u32)(eax);  // @814_5a86c0
  eax = ext_5ec090_thiscall3(ecx, PV[62], PV[61]);  // @815_5a86c0
  ecx = edx = 0;  // @816_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @817_5a86c0
  eax = ext_5ec340_thiscall3(ecx, (u32)(16717056), (u32)(-1));  // @818_5a86c0
  ecx = edx = 0;  // @819_5a86c0
  PV[63] = (u32)(ecx);  // @820_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @821_5a86c0
  eax = ext_5ec2b0_thiscall3(ecx, (u32)(0), (u32)(-1));  // @822_5a86c0
  ecx = edx = 0;  // @823_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1673), sizeof v); (u32)v; });  // @824_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @825_5a86c0
  L5a92da:;
  PV[64] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @827_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[64], (u32)(7012296));  // @828_5a86c0
  ecx = edx = 0;  // @829_5a86c0
  edx = 0;  // @830_5a86c0
  FL[3] = edx;  // @831_5a86c0
  ecx = eax;  // @832_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @833_5a86c0
  FL[3] = ecx;  // @834_5a86c0
  esi = 0;  // @835_5a86c0
  FL[3] = esi;  // @836_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @837_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @838_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @839_5a86c0
  FL[2] = (ecx & ecx);  // @840_5a86c0
  if (FL[2] == 0) goto L5a932a;  // @841_5a86c0
  ebx = ecx;  // @842_5a86c0
  L5a9310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @844_5a86c0
  ecx = (u32)(esi + 1);  // @845_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @846_5a86c0
  edx = (edx + 1);  // @847_5a86c0
  FL[3] = edx;  // @848_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @849_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @850_5a86c0
  esi = ecx;  // @851_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @852_5a86c0
  if (FL[0] < FL[1]) goto L5a9310;  // @853_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @854_5a86c0
  L5a932a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1196), sizeof v); (u32)v; });  // @856_5a86c0
  eax = (u32)(esi + 2);  // @857_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @858_5a86c0
  eax = (u32)(eax + eax*2);  // @859_5a86c0
  eax = (u32)(ebx + eax*4);  // @860_5a86c0
  PV[65] = (u32)(eax);  // @861_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[65], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @862_5a86c0
  ecx = edx = 0;  // @863_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1196), sizeof v); (u32)v; });  // @864_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-110), (u32)(-1));  // @865_5a86c0
  ecx = edx = 0;  // @866_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1196), sizeof v); (u32)v; });  // @867_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @868_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @869_5a86c0
  if (FL[0] == FL[1]) goto L5a9399;  // @870_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1196), sizeof v); (u32)v; });  // @871_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-60), (u32)(-1));  // @872_5a86c0
  ecx = edx = 0;  // @873_5a86c0
  PV[66] = (u32)(ecx);  // @874_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1196), sizeof v); (u32)v; });  // @875_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @876_5a86c0
  ecx = edx = 0;  // @877_5a86c0
  L5a9399:;
  PV[67] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @879_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[67], (u32)(7012308));  // @880_5a86c0
  ecx = edx = 0;  // @881_5a86c0
  edx = 0;  // @882_5a86c0
  FL[3] = edx;  // @883_5a86c0
  ecx = eax;  // @884_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @885_5a86c0
  FL[3] = ecx;  // @886_5a86c0
  esi = 0;  // @887_5a86c0
  FL[3] = esi;  // @888_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @889_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @890_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @891_5a86c0
  FL[2] = (ecx & ecx);  // @892_5a86c0
  if (FL[2] == 0) goto L5a93ea;  // @893_5a86c0
  ebx = ecx;  // @894_5a86c0
  L5a93d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @896_5a86c0
  ecx = (u32)(esi + 1);  // @897_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @898_5a86c0
  edx = (edx + 1);  // @899_5a86c0
  FL[3] = edx;  // @900_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @901_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @902_5a86c0
  esi = ecx;  // @903_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @904_5a86c0
  if (FL[0] < FL[1]) goto L5a93d0;  // @905_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @906_5a86c0
  L5a93ea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1204), sizeof v); (u32)v; });  // @908_5a86c0
  eax = (u32)(esi + 2);  // @909_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @910_5a86c0
  eax = (u32)(eax + eax*2);  // @911_5a86c0
  eax = (u32)(ebx + eax*4);  // @912_5a86c0
  PV[68] = (u32)(eax);  // @913_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[68], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @914_5a86c0
  ecx = edx = 0;  // @915_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1204), sizeof v); (u32)v; });  // @916_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-110), (u32)(-1));  // @917_5a86c0
  ecx = edx = 0;  // @918_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1204), sizeof v); (u32)v; });  // @919_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @920_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @921_5a86c0
  if (FL[0] == FL[1]) goto L5a9459;  // @922_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1204), sizeof v); (u32)v; });  // @923_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-60), (u32)(-1));  // @924_5a86c0
  ecx = edx = 0;  // @925_5a86c0
  PV[69] = (u32)(ecx);  // @926_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1204), sizeof v); (u32)v; });  // @927_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @928_5a86c0
  ecx = edx = 0;  // @929_5a86c0
  L5a9459:;
  PV[70] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @931_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[70], (u32)(7012320));  // @932_5a86c0
  ecx = edx = 0;  // @933_5a86c0
  edx = 0;  // @934_5a86c0
  FL[3] = edx;  // @935_5a86c0
  ecx = eax;  // @936_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @937_5a86c0
  FL[3] = ecx;  // @938_5a86c0
  esi = 0;  // @939_5a86c0
  FL[3] = esi;  // @940_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @941_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @942_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @943_5a86c0
  FL[2] = (ecx & ecx);  // @944_5a86c0
  if (FL[2] == 0) goto L5a94aa;  // @945_5a86c0
  ebx = ecx;  // @946_5a86c0
  L5a9490:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @948_5a86c0
  ecx = (u32)(esi + 1);  // @949_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @950_5a86c0
  edx = (edx + 1);  // @951_5a86c0
  FL[3] = edx;  // @952_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @953_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @954_5a86c0
  esi = ecx;  // @955_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @956_5a86c0
  if (FL[0] < FL[1]) goto L5a9490;  // @957_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @958_5a86c0
  L5a94aa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1192), sizeof v); (u32)v; });  // @960_5a86c0
  eax = (u32)(esi + 2);  // @961_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @962_5a86c0
  eax = (u32)(eax + eax*2);  // @963_5a86c0
  eax = (u32)(ebx + eax*4);  // @964_5a86c0
  PV[71] = (u32)(eax);  // @965_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[71], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @966_5a86c0
  ecx = edx = 0;  // @967_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1192), sizeof v); (u32)v; });  // @968_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-110), (u32)(-1));  // @969_5a86c0
  ecx = edx = 0;  // @970_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1192), sizeof v); (u32)v; });  // @971_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @972_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @973_5a86c0
  if (FL[0] == FL[1]) goto L5a9519;  // @974_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1192), sizeof v); (u32)v; });  // @975_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-60), (u32)(-1));  // @976_5a86c0
  ecx = edx = 0;  // @977_5a86c0
  PV[72] = (u32)(ecx);  // @978_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1192), sizeof v); (u32)v; });  // @979_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @980_5a86c0
  ecx = edx = 0;  // @981_5a86c0
  L5a9519:;
  PV[73] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @983_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[73], (u32)(7012328));  // @984_5a86c0
  ecx = edx = 0;  // @985_5a86c0
  edx = 0;  // @986_5a86c0
  FL[3] = edx;  // @987_5a86c0
  ecx = eax;  // @988_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @989_5a86c0
  FL[3] = ecx;  // @990_5a86c0
  esi = 0;  // @991_5a86c0
  FL[3] = esi;  // @992_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @993_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @994_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @995_5a86c0
  FL[2] = (ecx & ecx);  // @996_5a86c0
  if (FL[2] == 0) goto L5a956a;  // @997_5a86c0
  ebx = ecx;  // @998_5a86c0
  L5a9550:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1000_5a86c0
  ecx = (u32)(esi + 1);  // @1001_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1002_5a86c0
  edx = (edx + 1);  // @1003_5a86c0
  FL[3] = edx;  // @1004_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1005_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1006_5a86c0
  esi = ecx;  // @1007_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1008_5a86c0
  if (FL[0] < FL[1]) goto L5a9550;  // @1009_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1010_5a86c0
  L5a956a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1188), sizeof v); (u32)v; });  // @1012_5a86c0
  eax = (u32)(esi + 2);  // @1013_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1014_5a86c0
  eax = (u32)(eax + eax*2);  // @1015_5a86c0
  eax = (u32)(ebx + eax*4);  // @1016_5a86c0
  PV[74] = (u32)(eax);  // @1017_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[74], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1018_5a86c0
  ecx = edx = 0;  // @1019_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1188), sizeof v); (u32)v; });  // @1020_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-110), (u32)(-1));  // @1021_5a86c0
  ecx = edx = 0;  // @1022_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1188), sizeof v); (u32)v; });  // @1023_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1024_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1025_5a86c0
  if (FL[0] == FL[1]) goto L5a95d9;  // @1026_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1188), sizeof v); (u32)v; });  // @1027_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-60), (u32)(-1));  // @1028_5a86c0
  ecx = edx = 0;  // @1029_5a86c0
  PV[75] = (u32)(ecx);  // @1030_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1188), sizeof v); (u32)v; });  // @1031_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1032_5a86c0
  ecx = edx = 0;  // @1033_5a86c0
  L5a95d9:;
  PV[76] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1035_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[76], (u32)(7012340));  // @1036_5a86c0
  ecx = edx = 0;  // @1037_5a86c0
  edx = 0;  // @1038_5a86c0
  FL[3] = edx;  // @1039_5a86c0
  ecx = eax;  // @1040_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1041_5a86c0
  FL[3] = ecx;  // @1042_5a86c0
  esi = 0;  // @1043_5a86c0
  FL[3] = esi;  // @1044_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1045_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1046_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1047_5a86c0
  FL[2] = (ecx & ecx);  // @1048_5a86c0
  if (FL[2] == 0) goto L5a962a;  // @1049_5a86c0
  ebx = ecx;  // @1050_5a86c0
  L5a9610:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1052_5a86c0
  ecx = (u32)(esi + 1);  // @1053_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1054_5a86c0
  edx = (edx + 1);  // @1055_5a86c0
  FL[3] = edx;  // @1056_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1057_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1058_5a86c0
  esi = ecx;  // @1059_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1060_5a86c0
  if (FL[0] < FL[1]) goto L5a9610;  // @1061_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1062_5a86c0
  L5a962a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1184), sizeof v); (u32)v; });  // @1064_5a86c0
  eax = (u32)(esi + 2);  // @1065_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1066_5a86c0
  eax = (u32)(eax + eax*2);  // @1067_5a86c0
  eax = (u32)(ebx + eax*4);  // @1068_5a86c0
  PV[77] = (u32)(eax);  // @1069_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[77], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1070_5a86c0
  ecx = edx = 0;  // @1071_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1184), sizeof v); (u32)v; });  // @1072_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-110), (u32)(-1));  // @1073_5a86c0
  ecx = edx = 0;  // @1074_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1184), sizeof v); (u32)v; });  // @1075_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1076_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1077_5a86c0
  if (FL[0] == FL[1]) goto L5a9699;  // @1078_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1184), sizeof v); (u32)v; });  // @1079_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-60), (u32)(-1));  // @1080_5a86c0
  ecx = edx = 0;  // @1081_5a86c0
  PV[78] = (u32)(ecx);  // @1082_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1184), sizeof v); (u32)v; });  // @1083_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1084_5a86c0
  ecx = edx = 0;  // @1085_5a86c0
  L5a9699:;
  PV[79] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1087_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[79], (u32)(7012352));  // @1088_5a86c0
  ecx = edx = 0;  // @1089_5a86c0
  edx = 0;  // @1090_5a86c0
  FL[3] = edx;  // @1091_5a86c0
  ecx = eax;  // @1092_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1093_5a86c0
  FL[3] = ecx;  // @1094_5a86c0
  esi = 0;  // @1095_5a86c0
  FL[3] = esi;  // @1096_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1097_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1098_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1099_5a86c0
  FL[2] = (ecx & ecx);  // @1100_5a86c0
  if (FL[2] == 0) goto L5a96ea;  // @1101_5a86c0
  ebx = ecx;  // @1102_5a86c0
  L5a96d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1104_5a86c0
  ecx = (u32)(esi + 1);  // @1105_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1106_5a86c0
  edx = (edx + 1);  // @1107_5a86c0
  FL[3] = edx;  // @1108_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1109_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1110_5a86c0
  esi = ecx;  // @1111_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1112_5a86c0
  if (FL[0] < FL[1]) goto L5a96d0;  // @1113_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1114_5a86c0
  L5a96ea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1180), sizeof v); (u32)v; });  // @1116_5a86c0
  eax = (u32)(esi + 2);  // @1117_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1118_5a86c0
  eax = (u32)(eax + eax*2);  // @1119_5a86c0
  eax = (u32)(ebx + eax*4);  // @1120_5a86c0
  PV[80] = (u32)(eax);  // @1121_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[80], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1122_5a86c0
  ecx = edx = 0;  // @1123_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1180), sizeof v); (u32)v; });  // @1124_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-110), (u32)(-1));  // @1125_5a86c0
  ecx = edx = 0;  // @1126_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1180), sizeof v); (u32)v; });  // @1127_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1128_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1129_5a86c0
  if (FL[0] == FL[1]) goto L5a9759;  // @1130_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1180), sizeof v); (u32)v; });  // @1131_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(-60), (u32)(-1));  // @1132_5a86c0
  ecx = edx = 0;  // @1133_5a86c0
  PV[81] = (u32)(ecx);  // @1134_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1180), sizeof v); (u32)v; });  // @1135_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1136_5a86c0
  ecx = edx = 0;  // @1137_5a86c0
  L5a9759:;
  PV[82] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1139_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[82], (u32)(7012360));  // @1140_5a86c0
  ecx = edx = 0;  // @1141_5a86c0
  edx = 0;  // @1142_5a86c0
  FL[3] = edx;  // @1143_5a86c0
  ecx = eax;  // @1144_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1145_5a86c0
  FL[3] = ecx;  // @1146_5a86c0
  esi = 0;  // @1147_5a86c0
  FL[3] = esi;  // @1148_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1149_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1150_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1151_5a86c0
  FL[2] = (ecx & ecx);  // @1152_5a86c0
  if (FL[2] == 0) goto L5a97aa;  // @1153_5a86c0
  ebx = ecx;  // @1154_5a86c0
  L5a9790:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1156_5a86c0
  ecx = (u32)(esi + 1);  // @1157_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1158_5a86c0
  edx = (edx + 1);  // @1159_5a86c0
  FL[3] = edx;  // @1160_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1161_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1162_5a86c0
  esi = ecx;  // @1163_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1164_5a86c0
  if (FL[0] < FL[1]) goto L5a9790;  // @1165_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1166_5a86c0
  L5a97aa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1176), sizeof v); (u32)v; });  // @1168_5a86c0
  eax = (u32)(esi + 2);  // @1169_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1170_5a86c0
  eax = (u32)(eax + eax*2);  // @1171_5a86c0
  eax = (u32)(ebx + eax*4);  // @1172_5a86c0
  PV[83] = (u32)(eax);  // @1173_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[83], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1174_5a86c0
  ecx = edx = 0;  // @1175_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1176), sizeof v); (u32)v; });  // @1176_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(84), (u32)(-78), (u32)(-1));  // @1177_5a86c0
  ecx = edx = 0;  // @1178_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1176), sizeof v); (u32)v; });  // @1179_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1180_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1181_5a86c0
  if (FL[0] == FL[1]) goto L5a9819;  // @1182_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1176), sizeof v); (u32)v; });  // @1183_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(42), (u32)(-40), (u32)(-1));  // @1184_5a86c0
  ecx = edx = 0;  // @1185_5a86c0
  PV[84] = (u32)(ecx);  // @1186_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1176), sizeof v); (u32)v; });  // @1187_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1188_5a86c0
  ecx = edx = 0;  // @1189_5a86c0
  L5a9819:;
  PV[85] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1191_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[85], (u32)(7012372));  // @1192_5a86c0
  ecx = edx = 0;  // @1193_5a86c0
  edx = 0;  // @1194_5a86c0
  FL[3] = edx;  // @1195_5a86c0
  ecx = eax;  // @1196_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1197_5a86c0
  FL[3] = ecx;  // @1198_5a86c0
  esi = 0;  // @1199_5a86c0
  FL[3] = esi;  // @1200_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1201_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1202_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1203_5a86c0
  FL[2] = (ecx & ecx);  // @1204_5a86c0
  if (FL[2] == 0) goto L5a986a;  // @1205_5a86c0
  ebx = ecx;  // @1206_5a86c0
  L5a9850:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1208_5a86c0
  ecx = (u32)(esi + 1);  // @1209_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1210_5a86c0
  edx = (edx + 1);  // @1211_5a86c0
  FL[3] = edx;  // @1212_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1213_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1214_5a86c0
  esi = ecx;  // @1215_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1216_5a86c0
  if (FL[0] < FL[1]) goto L5a9850;  // @1217_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1218_5a86c0
  L5a986a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1172), sizeof v); (u32)v; });  // @1220_5a86c0
  eax = (u32)(esi + 2);  // @1221_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1222_5a86c0
  eax = (u32)(eax + eax*2);  // @1223_5a86c0
  eax = (u32)(ebx + eax*4);  // @1224_5a86c0
  PV[86] = (u32)(eax);  // @1225_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[86], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1226_5a86c0
  ecx = edx = 0;  // @1227_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1172), sizeof v); (u32)v; });  // @1228_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(110), (u32)(0), (u32)(-1));  // @1229_5a86c0
  ecx = edx = 0;  // @1230_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1172), sizeof v); (u32)v; });  // @1231_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1232_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1233_5a86c0
  if (FL[0] == FL[1]) goto L5a98d9;  // @1234_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1172), sizeof v); (u32)v; });  // @1235_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(60), (u32)(0), (u32)(-1));  // @1236_5a86c0
  ecx = edx = 0;  // @1237_5a86c0
  PV[87] = (u32)(ecx);  // @1238_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1172), sizeof v); (u32)v; });  // @1239_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1240_5a86c0
  ecx = edx = 0;  // @1241_5a86c0
  L5a98d9:;
  PV[88] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1243_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[88], (u32)(7012384));  // @1244_5a86c0
  ecx = edx = 0;  // @1245_5a86c0
  edx = 0;  // @1246_5a86c0
  FL[3] = edx;  // @1247_5a86c0
  ecx = eax;  // @1248_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1249_5a86c0
  FL[3] = ecx;  // @1250_5a86c0
  esi = 0;  // @1251_5a86c0
  FL[3] = esi;  // @1252_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1253_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1254_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1255_5a86c0
  FL[2] = (ecx & ecx);  // @1256_5a86c0
  if (FL[2] == 0) goto L5a992a;  // @1257_5a86c0
  ebx = ecx;  // @1258_5a86c0
  L5a9910:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1260_5a86c0
  ecx = (u32)(esi + 1);  // @1261_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1262_5a86c0
  edx = (edx + 1);  // @1263_5a86c0
  FL[3] = edx;  // @1264_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1265_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1266_5a86c0
  esi = ecx;  // @1267_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1268_5a86c0
  if (FL[0] < FL[1]) goto L5a9910;  // @1269_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1270_5a86c0
  L5a992a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1168), sizeof v); (u32)v; });  // @1272_5a86c0
  eax = (u32)(esi + 2);  // @1273_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1274_5a86c0
  eax = (u32)(eax + eax*2);  // @1275_5a86c0
  eax = (u32)(ebx + eax*4);  // @1276_5a86c0
  PV[89] = (u32)(eax);  // @1277_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[89], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1278_5a86c0
  ecx = edx = 0;  // @1279_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1168), sizeof v); (u32)v; });  // @1280_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(80), (u32)(80), (u32)(-1));  // @1281_5a86c0
  ecx = edx = 0;  // @1282_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1168), sizeof v); (u32)v; });  // @1283_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1284_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1285_5a86c0
  if (FL[0] == FL[1]) goto L5a9999;  // @1286_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1168), sizeof v); (u32)v; });  // @1287_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(40), (u32)(40), (u32)(-1));  // @1288_5a86c0
  ecx = edx = 0;  // @1289_5a86c0
  PV[90] = (u32)(ecx);  // @1290_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1168), sizeof v); (u32)v; });  // @1291_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1292_5a86c0
  ecx = edx = 0;  // @1293_5a86c0
  L5a9999:;
  PV[91] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1295_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[91], (u32)(7012396));  // @1296_5a86c0
  ecx = edx = 0;  // @1297_5a86c0
  edx = 0;  // @1298_5a86c0
  FL[3] = edx;  // @1299_5a86c0
  ecx = eax;  // @1300_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1301_5a86c0
  FL[3] = ecx;  // @1302_5a86c0
  esi = 0;  // @1303_5a86c0
  FL[3] = esi;  // @1304_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1305_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1306_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1307_5a86c0
  FL[2] = (ecx & ecx);  // @1308_5a86c0
  if (FL[2] == 0) goto L5a99ea;  // @1309_5a86c0
  ebx = ecx;  // @1310_5a86c0
  L5a99d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1312_5a86c0
  ecx = (u32)(esi + 1);  // @1313_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1314_5a86c0
  edx = (edx + 1);  // @1315_5a86c0
  FL[3] = edx;  // @1316_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1317_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1318_5a86c0
  esi = ecx;  // @1319_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1320_5a86c0
  if (FL[0] < FL[1]) goto L5a99d0;  // @1321_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1322_5a86c0
  L5a99ea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1164), sizeof v); (u32)v; });  // @1324_5a86c0
  eax = (u32)(esi + 2);  // @1325_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1326_5a86c0
  eax = (u32)(eax + eax*2);  // @1327_5a86c0
  eax = (u32)(ebx + eax*4);  // @1328_5a86c0
  PV[92] = (u32)(eax);  // @1329_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[92], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1330_5a86c0
  ecx = edx = 0;  // @1331_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1164), sizeof v); (u32)v; });  // @1332_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(110), (u32)(-1));  // @1333_5a86c0
  ecx = edx = 0;  // @1334_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1164), sizeof v); (u32)v; });  // @1335_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1336_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1337_5a86c0
  if (FL[0] == FL[1]) goto L5a9a59;  // @1338_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1164), sizeof v); (u32)v; });  // @1339_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(60), (u32)(-1));  // @1340_5a86c0
  ecx = edx = 0;  // @1341_5a86c0
  PV[93] = (u32)(ecx);  // @1342_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1164), sizeof v); (u32)v; });  // @1343_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1344_5a86c0
  ecx = edx = 0;  // @1345_5a86c0
  L5a9a59:;
  PV[94] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1347_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[94], (u32)(7012408));  // @1348_5a86c0
  ecx = edx = 0;  // @1349_5a86c0
  edx = 0;  // @1350_5a86c0
  FL[3] = edx;  // @1351_5a86c0
  ecx = eax;  // @1352_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1353_5a86c0
  FL[3] = ecx;  // @1354_5a86c0
  esi = 0;  // @1355_5a86c0
  FL[3] = esi;  // @1356_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1357_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1358_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1359_5a86c0
  FL[2] = (ecx & ecx);  // @1360_5a86c0
  if (FL[2] == 0) goto L5a9aaa;  // @1361_5a86c0
  ebx = ecx;  // @1362_5a86c0
  L5a9a90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1364_5a86c0
  ecx = (u32)(esi + 1);  // @1365_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1366_5a86c0
  edx = (edx + 1);  // @1367_5a86c0
  FL[3] = edx;  // @1368_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1369_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1370_5a86c0
  esi = ecx;  // @1371_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1372_5a86c0
  if (FL[0] < FL[1]) goto L5a9a90;  // @1373_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1374_5a86c0
  L5a9aaa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1200), sizeof v); (u32)v; });  // @1376_5a86c0
  eax = (u32)(esi + 2);  // @1377_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1378_5a86c0
  eax = (u32)(eax + eax*2);  // @1379_5a86c0
  eax = (u32)(ebx + eax*4);  // @1380_5a86c0
  PV[95] = (u32)(eax);  // @1381_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[95], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1382_5a86c0
  ecx = edx = 0;  // @1383_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1200), sizeof v); (u32)v; });  // @1384_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(110), (u32)(-1));  // @1385_5a86c0
  ecx = edx = 0;  // @1386_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1200), sizeof v); (u32)v; });  // @1387_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1388_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1389_5a86c0
  if (FL[0] == FL[1]) goto L5a9b19;  // @1390_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1200), sizeof v); (u32)v; });  // @1391_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(60), (u32)(-1));  // @1392_5a86c0
  ecx = edx = 0;  // @1393_5a86c0
  PV[96] = (u32)(ecx);  // @1394_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1200), sizeof v); (u32)v; });  // @1395_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1396_5a86c0
  ecx = edx = 0;  // @1397_5a86c0
  L5a9b19:;
  PV[97] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1399_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[97], (u32)(7012424));  // @1400_5a86c0
  ecx = edx = 0;  // @1401_5a86c0
  edx = 0;  // @1402_5a86c0
  FL[3] = edx;  // @1403_5a86c0
  ecx = eax;  // @1404_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1405_5a86c0
  FL[3] = ecx;  // @1406_5a86c0
  esi = 0;  // @1407_5a86c0
  FL[3] = esi;  // @1408_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1409_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1410_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1411_5a86c0
  FL[2] = (ecx & ecx);  // @1412_5a86c0
  if (FL[2] == 0) goto L5a9b6a;  // @1413_5a86c0
  ebx = ecx;  // @1414_5a86c0
  L5a9b50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1416_5a86c0
  ecx = (u32)(esi + 1);  // @1417_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1418_5a86c0
  edx = (edx + 1);  // @1419_5a86c0
  FL[3] = edx;  // @1420_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1421_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1422_5a86c0
  esi = ecx;  // @1423_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1424_5a86c0
  if (FL[0] < FL[1]) goto L5a9b50;  // @1425_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1426_5a86c0
  L5a9b6a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1152), sizeof v); (u32)v; });  // @1428_5a86c0
  eax = (u32)(esi + 2);  // @1429_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1430_5a86c0
  eax = (u32)(eax + eax*2);  // @1431_5a86c0
  eax = (u32)(ebx + eax*4);  // @1432_5a86c0
  PV[98] = (u32)(eax);  // @1433_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[98], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1434_5a86c0
  ecx = edx = 0;  // @1435_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1152), sizeof v); (u32)v; });  // @1436_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(-80), (u32)(80), (u32)(-1));  // @1437_5a86c0
  ecx = edx = 0;  // @1438_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1152), sizeof v); (u32)v; });  // @1439_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1440_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1441_5a86c0
  if (FL[0] == FL[1]) goto L5a9bd9;  // @1442_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1152), sizeof v); (u32)v; });  // @1443_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(-40), (u32)(40), (u32)(-1));  // @1444_5a86c0
  ecx = edx = 0;  // @1445_5a86c0
  PV[99] = (u32)(ecx);  // @1446_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1152), sizeof v); (u32)v; });  // @1447_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1448_5a86c0
  ecx = edx = 0;  // @1449_5a86c0
  L5a9bd9:;
  PV[100] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1451_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[100], (u32)(7012440));  // @1452_5a86c0
  ecx = edx = 0;  // @1453_5a86c0
  edx = 0;  // @1454_5a86c0
  FL[3] = edx;  // @1455_5a86c0
  ecx = eax;  // @1456_5a86c0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }));  // @1457_5a86c0
  FL[3] = ecx;  // @1458_5a86c0
  esi = 0;  // @1459_5a86c0
  FL[3] = esi;  // @1460_5a86c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; }); FL[1] = eax;  // @1461_5a86c0
  if (FL[0] > FL[1]) ecx = edx;  // @1462_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1463_5a86c0
  FL[2] = (ecx & ecx);  // @1464_5a86c0
  if (FL[2] == 0) goto L5a9c2a;  // @1465_5a86c0
  ebx = ecx;  // @1466_5a86c0
  L5a9c10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1468_5a86c0
  ecx = (u32)(esi + 1);  // @1469_5a86c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; })) & 0xff);  // @1470_5a86c0
  edx = (edx + 1);  // @1471_5a86c0
  FL[3] = edx;  // @1472_5a86c0
  FL[0] = (eax & 0xff); FL[1] = (u32)(59);  // @1473_5a86c0
  if (FL[0] != FL[1]) ecx = esi;  // @1474_5a86c0
  esi = ecx;  // @1475_5a86c0
  FL[0] = edx; FL[1] = ebx;  // @1476_5a86c0
  if (FL[0] < FL[1]) goto L5a9c10;  // @1477_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1478_5a86c0
  L5a9c2a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1156), sizeof v); (u32)v; });  // @1480_5a86c0
  eax = (u32)(esi + 2);  // @1481_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1482_5a86c0
  eax = (u32)(eax + eax*2);  // @1483_5a86c0
  eax = (u32)(ebx + eax*4);  // @1484_5a86c0
  PV[101] = (u32)(eax);  // @1485_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[101], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1486_5a86c0
  ecx = edx = 0;  // @1487_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1156), sizeof v); (u32)v; });  // @1488_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(-110), (u32)(0), (u32)(-1));  // @1489_5a86c0
  ecx = edx = 0;  // @1490_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1156), sizeof v); (u32)v; });  // @1491_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1492_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1493_5a86c0
  if (FL[0] == FL[1]) goto L5a9c99;  // @1494_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1156), sizeof v); (u32)v; });  // @1495_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(-60), (u32)(0), (u32)(-1));  // @1496_5a86c0
  ecx = edx = 0;  // @1497_5a86c0
  PV[102] = (u32)(ecx);  // @1498_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1156), sizeof v); (u32)v; });  // @1499_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1500_5a86c0
  ecx = edx = 0;  // @1501_5a86c0
  L5a9c99:;
  PV[103] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1503_5a86c0
  eax = ((u32(*)(u32, u32))(edi))(PV[103], (u32)(7012452));  // @1504_5a86c0
  ecx = edx = 0;  // @1505_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1506_5a86c0
  esi = 0;  // @1507_5a86c0
  FL[3] = esi;  // @1508_5a86c0
  ecx = eax;  // @1509_5a86c0
  ecx = (ecx - edx);  // @1510_5a86c0
  FL[3] = ecx;  // @1511_5a86c0
  edi = 0;  // @1512_5a86c0
  FL[3] = edi;  // @1513_5a86c0
  FL[0] = edx; FL[1] = eax;  // @1514_5a86c0
  if (FL[0] > FL[1]) ecx = esi;  // @1515_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1516_5a86c0
  FL[2] = (ecx & ecx);  // @1517_5a86c0
  if (FL[2] == 0) goto L5a9cdd;  // @1518_5a86c0
  ebx = ecx;  // @1519_5a86c0
  L5a9cc5:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @1521_5a86c0
  eax = (u32)(esi + 1);  // @1522_5a86c0
  edi = (edi + 1);  // @1523_5a86c0
  FL[3] = edi;  // @1524_5a86c0
  edx = (u32)(edx + 1);  // @1525_5a86c0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(59);  // @1526_5a86c0
  if (FL[0] != FL[1]) eax = esi;  // @1527_5a86c0
  esi = eax;  // @1528_5a86c0
  FL[0] = edi; FL[1] = ebx;  // @1529_5a86c0
  if (FL[0] < FL[1]) goto L5a9cc5;  // @1530_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1531_5a86c0
  L5a9cdd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1160), sizeof v); (u32)v; });  // @1533_5a86c0
  eax = (u32)(esi + 2);  // @1534_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1535_5a86c0
  eax = (u32)(eax + eax*2);  // @1536_5a86c0
  eax = (u32)(ebx + eax*4);  // @1537_5a86c0
  PV[104] = (u32)(eax);  // @1538_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[104], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1539_5a86c0
  ecx = edx = 0;  // @1540_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1160), sizeof v); (u32)v; });  // @1541_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(-80), (u32)(-80), (u32)(-1));  // @1542_5a86c0
  ecx = edx = 0;  // @1543_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1160), sizeof v); (u32)v; });  // @1544_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1545_5a86c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1546_5a86c0
  if (FL[0] == FL[1]) goto L5a9d4c;  // @1547_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1160), sizeof v); (u32)v; });  // @1548_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(-40), (u32)(-40), (u32)(-1));  // @1549_5a86c0
  ecx = edx = 0;  // @1550_5a86c0
  PV[105] = (u32)(ecx);  // @1551_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1160), sizeof v); (u32)v; });  // @1552_5a86c0
  eax = ext_5ec670_thiscall3(ecx, (u32)(1056964608), (u32)(0));  // @1553_5a86c0
  ecx = edx = 0;  // @1554_5a86c0
  L5a9d4c:;
  eax = (u32)(ebx + 1228);  // @1556_5a86c0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @1557_5a86c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @1558_5a86c0
  L5a9d60:;
  PV[106] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1560_5a86c0
  eax = ((u32(*)(u32, u32))(*(u32 *)0x67625c))(PV[106], (u32)(7012460));  // @1561_5a86c0
  ecx = edx = 0;  // @1562_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262832), sizeof v); (u32)v; });  // @1563_5a86c0
  esi = 0;  // @1564_5a86c0
  FL[3] = esi;  // @1565_5a86c0
  ecx = eax;  // @1566_5a86c0
  ecx = (ecx - edx);  // @1567_5a86c0
  FL[3] = ecx;  // @1568_5a86c0
  edi = 0;  // @1569_5a86c0
  FL[3] = edi;  // @1570_5a86c0
  FL[0] = edx; FL[1] = eax;  // @1571_5a86c0
  if (FL[0] > FL[1]) ecx = esi;  // @1572_5a86c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @1573_5a86c0
  FL[2] = (ecx & ecx);  // @1574_5a86c0
  if (FL[2] == 0) goto L5a9da8;  // @1575_5a86c0
  ebx = ecx;  // @1576_5a86c0
  L5a9d90:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @1578_5a86c0
  eax = (u32)(esi + 1);  // @1579_5a86c0
  edi = (edi + 1);  // @1580_5a86c0
  FL[3] = edi;  // @1581_5a86c0
  edx = (u32)(edx + 1);  // @1582_5a86c0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(59);  // @1583_5a86c0
  if (FL[0] != FL[1]) eax = esi;  // @1584_5a86c0
  esi = eax;  // @1585_5a86c0
  FL[0] = edi; FL[1] = ebx;  // @1586_5a86c0
  if (FL[0] < FL[1]) goto L5a9d90;  // @1587_5a86c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @1588_5a86c0
  L5a9da8:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @1590_5a86c0
  eax = (u32)(esi + 2);  // @1591_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1592_5a86c0
  eax = (u32)(eax + eax*2);  // @1593_5a86c0
  eax = (u32)(ebx + eax*4);  // @1594_5a86c0
  PV[107] = (u32)(eax);  // @1595_5a86c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1596_5a86c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[107], (u32)(0), (u32)(0), (u32)(102), (u32)(64));  // @1597_5a86c0
  ecx = edx = 0;  // @1598_5a86c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1599_5a86c0
  eax = ext_5ed1e0_thiscall6(ecx, (u32)(3), (u32)(3), (u32)(0), (u32)(0), (u32)(-1));  // @1600_5a86c0
  ecx = edx = 0;  // @1601_5a86c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1602_5a86c0
  edi = (edi + (u32)(4));  // @1603_5a86c0
  FL[3] = edi;  // @1604_5a86c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @1605_5a86c0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @1606_5a86c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @1607_5a86c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 53), &v, sizeof v); }  // @1608_5a86c0
  if (FL[3] != 0) goto L5a9d60;  // @1609_5a86c0
  ext_633654(G(u32, 0x6f5630));  // @1610_5a86c0
  return eax;  // @1611_5a86c0
}
PCREG(5a86c0, lifted_5a86c0);

