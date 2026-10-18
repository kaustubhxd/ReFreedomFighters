// batch244018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_54f870_thiscall2(u32, u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_606b10_thiscall4(u32, u32, u32, u32) __asm__("ext_606b10");
extern "C" u32 THISCALL ext_6071c0_thiscall1(u32) __asm__("ext_6071c0");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6073b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66df96);  // @h_6073b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_6073b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_6073b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7), sizeof v); (u32)v; });  // @2_6073b0
  edi = (edi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3), sizeof v); (u32)v; }));  // @3_6073b0
  FL[3] = edi;  // @4_6073b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_6073b0
  edi = (u32)((s32)edi >> (u32)(2));  // @6_6073b0
  FL[3] = edi;  // @7_6073b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @8_6073b0
  FL[0] = ecx; FL[1] = edi;  // @9_6073b0
  if (FL[0] <= FL[1]) goto L6074db;  // @10_6073b0
  eax = ext_6071c0_thiscall1(ecx);  // @11_6073b0
  ecx = edx = 0;  // @12_6073b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @13_6073b0
  FL[0] = eax; FL[1] = edi;  // @14_6073b0
  if (FL[0] <= FL[1]) goto L6074db;  // @15_6073b0
  ecx = (u32)(EBP + 11);  // @16_6073b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @17_6073b0
  PV[0] = (u32)(ecx);  // @18_6073b0
  ecx = (u32)(EBP - 20);  // @19_6073b0
  PV[1] = (u32)(ecx);  // @20_6073b0
  PV[2] = (u32)(eax);  // @21_6073b0
  ecx = (u32)(EBP - 40);  // @22_6073b0
  eax = ext_606b10_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @23_6073b0
  ecx = edx = 0;  // @24_6073b0
  ebx = 0;  // @25_6073b0
  FL[3] = ebx;  // @26_6073b0
  FL[2] = (edi & edi);  // @27_6073b0
  if (FL[2] == 0) goto L607496;  // @28_6073b0
  eax = edi;  // @29_6073b0
  L607424:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3), sizeof v); (u32)v; });  // @31_6073b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @32_6073b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*4), sizeof v); (u32)v; });  // @33_6073b0
  FL[2] = (edi & edi);  // @34_6073b0
  if (FL[2] == 0) goto L607491;  // @35_6073b0
  L607431:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @37_6073b0
  eax = 0;  // @38_6073b0
  FL[3] = eax;  // @39_6073b0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @40_6073b0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @41_6073b0
  if (FL[2] == 0) goto L607466;  // @42_6073b0
  L607440:;
  ecx = (u32)(edx - 65);  // @44_6073b0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(25);  // @45_6073b0
  if (FL[0] > FL[1]) goto L607453;  // @46_6073b0
  ecx = (u32)(eax + eax*4);  // @47_6073b0
  eax = (u32)(s32)(s8)((edx & 0xff));  // @48_6073b0
  eax = (eax + (u32)(32));  // @49_6073b0
  FL[3] = eax;  // @50_6073b0
  goto L607459;  // @51_6073b0
  L607453:;
  eax = (u32)(eax + eax*4);  // @53_6073b0
  ecx = (u32)(s32)(s8)((edx & 0xff));  // @54_6073b0
  L607459:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @56_6073b0
  esi = (esi + 1);  // @57_6073b0
  FL[3] = esi;  // @58_6073b0
  eax = (eax + ecx);  // @59_6073b0
  FL[3] = eax;  // @60_6073b0
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @61_6073b0
  if (FL[2] != 0) goto L607440;  // @62_6073b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @63_6073b0
  L607466:;
  edx = 0;  // @65_6073b0
  FL[3] = edx;  // @66_6073b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @67_6073b0
  { u32 d_ = (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })); u32 q_, r_; __asm__ volatile("divl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = q_; edx = r_; }  // @68_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_6073b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*4), &v, sizeof v); }  // @70_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @71_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @72_6073b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @73_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @74_6073b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + edx*4), &v, sizeof v); }  // @75_6073b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3), sizeof v); (u32)v; });  // @76_6073b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @77_6073b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*4), sizeof v); (u32)v; });  // @78_6073b0
  FL[2] = (edi & edi);  // @79_6073b0
  if (FL[2] != 0) goto L607431;  // @80_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @81_6073b0
  L607491:;
  ebx = (ebx + 1);  // @83_6073b0
  FL[3] = ebx;  // @84_6073b0
  FL[0] = ebx; FL[1] = eax;  // @85_6073b0
  if (FL[0] < FL[1]) goto L607424;  // @86_6073b0
  L607496:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3), sizeof v); (u32)v; });  // @88_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @89_6073b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 3), &v, sizeof v); }  // @90_6073b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7), sizeof v); (u32)v; });  // @91_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @92_6073b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7), &v, sizeof v); }  // @93_6073b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @94_6073b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @95_6073b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 11), sizeof v); (u32)v; });  // @96_6073b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @97_6073b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 11), &v, sizeof v); }  // @98_6073b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @99_6073b0
  ecx = (ecx - edx);  // @100_6073b0
  FL[3] = ecx;  // @101_6073b0
  reg.state = (s32)((u32)(0));  // @102_6073b0
  ecx = (u32)((s32)ecx >> (u32)(2));  // @103_6073b0
  FL[3] = ecx;  // @104_6073b0
  FL[2] = (ecx & ecx);  // @105_6073b0
  if (FL[2] == 0) goto L6074db;  // @106_6073b0
  eax = (u32)(ecx*4);  // @107_6073b0
  PV[3] = (u32)(eax);  // @108_6073b0
  PV[4] = (u32)(edx);  // @109_6073b0
  ecx = (u32)(EBP - 40);  // @110_6073b0
  eax = ext_54f870_thiscall2(ecx, PV[4], PV[3]);  // @111_6073b0
  ecx = edx = 0;  // @112_6073b0
  L6074db:;
  SEH_LEAVE();  // @114_6073b0
  return eax;  // @115_6073b0
}
PCREG(6073b0, lifted_6073b0);

extern "C" u32 THISCALL lifted_535780(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_535780
  esi = ecx;  // @1_535780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_535780
  FL[2] = (ebx & ebx);  // @3_535780
  if (FL[2] == 0) goto L535911;  // @4_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_535780
  ecx = (u32)(EBP - 20);  // @6_535780
  PV[0] = (u32)(ecx);  // @7_535780
  ecx = ebx;  // @8_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @9_535780
  ecx = edx = 0;  // @10_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_535780
  ecx = (u32)(EBP - 20);  // @12_535780
  PV[1] = (u32)(ecx);  // @13_535780
  ecx = ebx;  // @14_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @15_535780
  ecx = edx = 0;  // @16_535780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @17_535780
  edx = eax;  // @18_535780
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @19_535780
  if (FL[0] == FL[1]) goto L535911;  // @20_535780
  L5357c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_535780
  PV[2] = (u32)(edx);  // @23_535780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[2]);  // @26_535780
  ecx = edx = 0;  // @27_535780
  edi = eax;  // @28_535780
  FL[2] = (edi & edi);  // @29_535780
  if (FL[2] == 0) goto L5358f6;  // @30_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @31_535780
  FL[2] = (eax & eax);  // @32_535780
  if (FL[2] == 0) goto L5358f6;  // @33_535780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_535780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @35_535780
  PV[3] = (u32)(eax);  // @36_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 64)))(ecx, PV[3]);  // @37_535780
  ecx = edx = 0;  // @38_535780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_535780
  PV[4] = (u32)(eax);  // @40_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 476)))(ecx, PV[4]);  // @41_535780
  ecx = edx = 0;  // @42_535780
  FL[2] = (eax & eax);  // @43_535780
  if (FL[2] == 0) goto L5358f3;  // @44_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @45_535780
  eax = (eax + (u32)(-2));  // @46_535780
  FL[3] = eax;  // @47_535780
  FL[0] = eax; FL[1] = (u32)(7);  // @48_535780
  if (FL[0] > FL[1]) goto L535847;  // @49_535780
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5462308), sizeof v); (u32)v; });  // @50_535780
  switch (eax) {  // @51_535780
  case 0: goto L53581a;  // @52_535780
  case 1: goto L535833;  // @53_535780
  default: __builtin_trap(); }  // @54_535780
  L53581a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 132) + 0), 4); v; });  // @56_535780
  X1[1] = 0;  // @57_535780
  X1[2] = 0;  // @58_535780
  X1[3] = 0;  // @59_535780
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @60_535780
  X0[1] = 0;  // @61_535780
  X0[2] = 0;  // @62_535780
  X0[3] = 0;  // @63_535780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @64_535780
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @65_535780
  goto L535895;  // @66_535780
  L535833:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; });  // @68_535780
  X1[1] = 0;  // @69_535780
  X1[2] = 0;  // @70_535780
  X1[3] = 0;  // @71_535780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @72_535780
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @73_535780
  goto L53588d;  // @74_535780
  L535847:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @76_535780
  edx = (u32)(edi + 212);  // @77_535780
  ecx = (u32)(esi + 110);  // @78_535780
  eax = ext_4e0870_fastcall2(ecx, edx);  // @79_535780
  ecx = edx = 0;  // @80_535780
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @81_535780
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @82_535780
  X0[1] = 0;  // @83_535780
  X0[2] = 0;  // @84_535780
  X0[3] = 0;  // @85_535780
  X1[0] = 0;  // @86_535780
  X1[1] = 0;  // @87_535780
  X1[2] = 0;  // @88_535780
  X1[3] = 0;  // @89_535780
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @90_535780
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @91_535780
  if (!__builtin_parity(FL[2] & 0xff)) goto L535874;  // @92_535780
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @93_535780
  X0[1] = 0;  // @94_535780
  X0[2] = 0;  // @95_535780
  X0[3] = 0;  // @96_535780
  L535874:;
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; })));  // @98_535780
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 136) + 0), 4); v; });  // @99_535780
  X1[1] = 0;  // @100_535780
  X1[2] = 0;  // @101_535780
  X1[3] = 0;  // @102_535780
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 132) + 0), 4); v; })));  // @103_535780
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @104_535780
  L53588d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @106_535780
  X0[1] = 0;  // @107_535780
  X0[2] = 0;  // @108_535780
  X0[3] = 0;  // @109_535780
  L535895:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @111_535780
  FL[0] = eax; FL[1] = (u32)(4);  // @112_535780
  if (FL[0] > FL[1]) goto L5358c6;  // @113_535780
  switch (eax) {  // @114_535780
  case 0: goto L5358a4;  // @115_535780
  case 1: goto L5358ae;  // @116_535780
  case 2: goto L5358c6;  // @117_535780
  case 3: goto L5358b8;  // @118_535780
  case 4: goto L5358c2;  // @119_535780
  default: __builtin_trap(); }  // @120_535780
  L5358a4:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; })));  // @122_535780
  goto L5358c6;  // @123_535780
  L5358ae:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @125_535780
  goto L5358c6;  // @126_535780
  L5358b8:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @128_535780
  goto L5358c6;  // @129_535780
  L5358c2:;
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @131_535780
  L5358c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @133_535780
  X0[0] = X1[0];  // @134_535780
  X0[1] = X1[1];  // @135_535780
  X0[2] = X1[2];  // @136_535780
  X0[3] = X1[3];  // @137_535780
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @138_535780
  PV[5] = (u32)(ecx);  // @139_535780
  PV[6] = X1[0];  // @140_535780
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @141_535780
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @142_535780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 208), &v, sizeof v); }  // @143_535780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_535780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[7], PV[6], (u32)(0));  // @145_535780
  ecx = edx = 0;  // @146_535780
  goto L5358f6;  // @147_535780
  L5358f3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @149_535780
  L5358f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @151_535780
  ecx = (u32)(EBP - 20);  // @152_535780
  PV[8] = (u32)(ecx);  // @153_535780
  ecx = ebx;  // @154_535780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @155_535780
  ecx = edx = 0;  // @156_535780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @157_535780
  edx = eax;  // @158_535780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @159_535780
  if (FL[0] != FL[1]) goto L5357c0;  // @160_535780
  L535911:;
  return eax;  // @162_535780
}
PCREG(535780, lifted_535780);

