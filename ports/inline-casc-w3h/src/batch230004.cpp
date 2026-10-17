// batch230004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4cc500_fastcall2(u32, u32) __asm__("ext_4cc500");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de440_fastcall3(u32, u32, u32) __asm__("ext_4de440");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 FASTCALL ext_4de520_fastcall4(u32, u32, u32, u32) __asm__("ext_4de520");
extern "C" u32 FASTCALL ext_4df1e0_fastcall2(u32, u32) __asm__("ext_4df1e0");
extern "C" u32 FASTCALL ext_4e08d0_fastcall2(u32, u32) __asm__("ext_4e08d0");
extern "C" u32 FASTCALL ext_4e0900_fastcall2(u32, u32) __asm__("ext_4e0900");
extern "C" u32 FASTCALL ext_4e09e0_fastcall2(u32, u32) __asm__("ext_4e09e0");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_4e2c60_fastcall2(u32, u32) __asm__("ext_4e2c60");
extern "C" u32 FASTCALL ext_52d250_fastcall4(u32, u32, u32, u32) __asm__("ext_52d250");
extern "C" u32 FASTCALL ext_588940_fastcall2(u32, u32) __asm__("ext_588940");
extern "C" u32 STDCALL ext_439320_stdcall3(u32, u32, u32) __asm__("ext_439320");
extern "C" u32 STDCALL ext_562280_stdcall2(u32, u32) __asm__("ext_562280");
extern "C" u32 STDCALL ext_574680_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_574680");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_455dd0_thiscall1(u32) __asm__("ext_455dd0");
extern "C" u32 THISCALL ext_45f960_thiscall2(u32, u32) __asm__("ext_45f960");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db1f0_thiscall2(u32, u32) __asm__("ext_4db1f0");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_4db520_thiscall1(u32) __asm__("ext_4db520");
extern "C" u32 THISCALL ext_4db670_thiscall2(u32, u32) __asm__("ext_4db670");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e0f60_thiscall2(u32, u32) __asm__("ext_4e0f60");
extern "C" u32 THISCALL ext_4e1070_thiscall2(u32, u32) __asm__("ext_4e1070");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1440_thiscall2(u32, u32) __asm__("ext_4e1440");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e2aa0_thiscall1(u32) __asm__("ext_4e2aa0");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_513f50_thiscall2(u32, u32) __asm__("ext_513f50");
extern "C" u32 THISCALL ext_513ff0_thiscall2(u32, u32) __asm__("ext_513ff0");
extern "C" u32 THISCALL ext_515b70_thiscall2(u32, u32) __asm__("ext_515b70");
extern "C" u32 THISCALL ext_516520_thiscall2(u32, u32) __asm__("ext_516520");
extern "C" u32 THISCALL ext_516e20_thiscall2(u32, u32) __asm__("ext_516e20");
extern "C" u32 THISCALL ext_527190_thiscall2(u32, u32) __asm__("ext_527190");
extern "C" u32 THISCALL ext_5274f0_thiscall2(u32, u32) __asm__("ext_5274f0");
extern "C" u32 THISCALL ext_528c80_thiscall2(u32, u32) __asm__("ext_528c80");
extern "C" u32 THISCALL ext_529f40_thiscall2(u32, u32) __asm__("ext_529f40");
extern "C" u32 THISCALL ext_529fa0_thiscall2(u32, u32) __asm__("ext_529fa0");
extern "C" u32 THISCALL ext_562390_thiscall1(u32) __asm__("ext_562390");
extern "C" u32 THISCALL ext_566850_thiscall1(u32) __asm__("ext_566850");
extern "C" u32 THISCALL ext_566b20_thiscall1(u32) __asm__("ext_566b20");
extern "C" u32 THISCALL ext_589710_thiscall2(u32, u32) __asm__("ext_589710");
extern "C" u32 THISCALL ext_589b50_thiscall2(u32, u32) __asm__("ext_589b50");
extern "C" u32 THISCALL ext_5950c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5950c0");
extern "C" u32 THISCALL ext_59d370_thiscall1(u32) __asm__("ext_59d370");
extern "C" u32 THISCALL ext_59ffc0_thiscall1(u32) __asm__("ext_59ffc0");
extern "C" u32 THISCALL ext_5aabe0_thiscall2(u32, u32) __asm__("ext_5aabe0");
extern "C" u32 THISCALL ext_5acad0_thiscall3(u32, u32, u32) __asm__("ext_5acad0");
extern "C" u32 THISCALL ext_5adda0_thiscall1(u32) __asm__("ext_5adda0");
extern "C" u32 THISCALL ext_5addc0_thiscall2(u32, u32) __asm__("ext_5addc0");
extern "C" u32 THISCALL ext_5ade90_thiscall1(u32) __asm__("ext_5ade90");
extern "C" u32 THISCALL ext_5adef0_thiscall2(u32, u32) __asm__("ext_5adef0");
extern "C" u32 THISCALL ext_5ae680_thiscall1(u32) __asm__("ext_5ae680");
extern "C" u32 THISCALL ext_5ca270_thiscall2(u32, u32) __asm__("ext_5ca270");
extern "C" u32 THISCALL ext_662660_thiscall2(u32, u32) __asm__("ext_662660");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_572850(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2162), sizeof v); (u32)v; });  // @1_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @3_572850
  ecx = edx = 0;  // @4_572850
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_572850
  ecx = esi;  // @6_572850
  edx = (u32)(ecx + 1);  // @7_572850
  L572872:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @9_572850
  ecx = (ecx + 1);  // @10_572850
  FL[3] = ecx;  // @11_572850
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @12_572850
  if (FL[2] != 0) goto L572872;  // @13_572850
  ecx = (ecx - edx);  // @14_572850
  FL[3] = ecx;  // @15_572850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 2140), &v, sizeof v); }  // @16_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2162), sizeof v); (u32)v; });  // @17_572850
  PV[0] = (u32)(esi);  // @18_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[0]);  // @20_572850
  ecx = edx = 0;  // @21_572850
  eax = (u32)(32);  // @22_572850
  ecx = (u32)(EBP - 44);  // @23_572850
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @24_572850
  eax = (u32)(EBP - 4);  // @25_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @26_572850
  eax = ext_4cc500_fastcall2(ecx, edx);  // @27_572850
  ecx = edx = 0;  // @28_572850
  edx = (u32)(ebx + 92);  // @29_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @30_572850
  edi = edx;  // @31_572850
  edi = (edi - esi);  // @32_572850
  FL[3] = edi;  // @33_572850
  L5728b2:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @35_572850
  esi = (u32)(esi + 1);  // @36_572850
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edi + esi - 1), &v, sizeof v); }  // @37_572850
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @38_572850
  if (FL[2] != 0) goto L5728b2;  // @39_572850
  ecx = edx;  // @40_572850
  esi = (u32)(ecx + 1);  // @41_572850
  L5728c4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @43_572850
  ecx = (ecx + 1);  // @44_572850
  FL[3] = ecx;  // @45_572850
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @46_572850
  if (FL[2] != 0) goto L5728c4;  // @47_572850
  ecx = (ecx - esi);  // @48_572850
  FL[3] = ecx;  // @49_572850
  FL[2] = (ecx & ecx);  // @50_572850
  if ((s32)FL[2] <= 0) goto L5728e1;  // @51_572850
  eax = edx;  // @52_572850
  L5728d3:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @54_572850
  if (FL[0] != FL[1]) goto L5728db;  // @55_572850
  { u8 v = (u8)((u32)(32)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @56_572850
  L5728db:;
  eax = (eax + 1);  // @58_572850
  FL[3] = eax;  // @59_572850
  ecx = (ecx - (u32)(1));  // @60_572850
  FL[3] = ecx;  // @61_572850
  if (FL[3] != 0) goto L5728d3;  // @62_572850
  L5728e1:;
  esi = 0;  // @64_572850
  FL[3] = esi;  // @65_572850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @66_572850
  edi = 0;  // @67_572850
  FL[3] = edi;  // @68_572850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @69_572850
  ecx = (u32)(EBP - 40);  // @70_572850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @71_572850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @72_572850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @73_572850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @74_572850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @75_572850
  eax = ext_4cc500_fastcall2(ecx, edx);  // @76_572850
  ecx = edx = 0;  // @77_572850
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2174), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @78_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @80_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; });  // @81_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @82_572850
  if (FL[0] == FL[1]) goto L57297b;  // @83_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @84_572850
  FL[2] = (eax & eax);  // @85_572850
  if (FL[2] == 0) goto L572939;  // @86_572850
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @87_572850
  if (FL[0] != FL[1]) goto L572964;  // @88_572850
  L572939:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @90_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_572850
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @92_572850
  ecx = edx = 0;  // @93_572850
  ecx = (u32)(EBP + 11);  // @94_572850
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @95_572850
  PV[1] = (u32)(ecx);  // @96_572850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @97_572850
  ecx = eax;  // @98_572850
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6805980), PV[1]);  // @99_572850
  ecx = edx = 0;  // @100_572850
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @101_572850
  if (FL[0] == FL[1]) goto L57297b;  // @102_572850
  L572964:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @104_572850
  X0[0] = F2U((float)(s32)X0[0]);  // @105_572850
  X0[1] = F2U((float)(s32)X0[1]);  // @106_572850
  X0[2] = F2U((float)(s32)X0[2]);  // @107_572850
  X0[3] = F2U((float)(s32)X0[3]);  // @108_572850
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6835428) + 0), 4); v; })));  // @109_572850
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @110_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @111_572850
  L57297b:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @113_572850
  FL[2] = (edx & edx);  // @114_572850
  if (FL[2] == 0) goto L572a41;  // @115_572850
  L572986:;
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @117_572850
  if (FL[0] != FL[1]) goto L572994;  // @118_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @119_572850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @120_572850
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @121_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @122_572850
  L572994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2162), sizeof v); (u32)v; });  // @124_572850
  PV[2] = (u32)(edx);  // @125_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 159), sizeof v); (u32)v; });  // @126_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[2]);  // @128_572850
  ecx = edx = 0;  // @129_572850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @130_572850
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }));  // @131_572850
  edx = (edx + eax);  // @132_572850
  FL[3] = edx;  // @133_572850
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @134_572850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @135_572850
  if (FL[0] == FL[1]) goto L5729dd;  // @136_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2162), sizeof v); (u32)v; });  // @137_572850
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @138_572850
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @139_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 159), sizeof v); (u32)v; });  // @140_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_572850
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 652)))(ecx, PV[4], PV[3]);  // @142_572850
  ecx = edx = 0;  // @143_572850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @144_572850
  edx = (edx + eax);  // @145_572850
  FL[3] = edx;  // @146_572850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @147_572850
  L5729dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @149_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @150_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @151_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2148), sizeof v); (u32)v; });  // @152_572850
  eax = (eax + eax);  // @153_572850
  FL[3] = eax;  // @154_572850
  ecx = (ecx - eax);  // @155_572850
  FL[3] = ecx;  // @156_572850
  eax = edx;  // @157_572850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @158_572850
  FL[3] = eax;  // @159_572850
  FL[0] = eax; FL[1] = ecx;  // @160_572850
  if ((s32)FL[0] <= (s32)FL[1]) goto L572a2c;  // @161_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2140), sizeof v); (u32)v; });  // @162_572850
  FL[0] = esi; FL[1] = eax;  // @163_572850
  if ((s32)FL[0] >= (s32)FL[1]) goto L572a2c;  // @164_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @165_572850
  L572a06:;
  FL[0] = edi; FL[1] = ecx;  // @167_572850
  if ((s32)FL[0] >= (s32)FL[1]) goto L572a1a;  // @168_572850
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + esi + 92), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @169_572850
  if (FL[0] != FL[1]) goto L572a15;  // @170_572850
  edi = (edi + 1);  // @171_572850
  FL[3] = edi;  // @172_572850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @173_572850
  L572a15:;
  esi = (esi + 1);  // @175_572850
  FL[3] = esi;  // @176_572850
  FL[0] = esi; FL[1] = eax;  // @177_572850
  if ((s32)FL[0] < (s32)FL[1]) goto L572a06;  // @178_572850
  L572a1a:;
  FL[0] = esi; FL[1] = eax;  // @180_572850
  if ((s32)FL[0] >= (s32)FL[1]) goto L572a2c;  // @181_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @182_572850
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(ebx + eax + 92), &v, sizeof v); }  // @183_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @184_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @185_572850
  L572a2c:;
  ecx = (u32)(EBP - 40);  // @187_572850
  eax = ext_4cc500_fastcall2(ecx, edx);  // @188_572850
  ecx = edx = 0;  // @189_572850
  edx = eax;  // @190_572850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @191_572850
  FL[2] = (edx & edx);  // @192_572850
  if (FL[2] != 0) goto L572986;  // @193_572850
  L572a41:;
  edx = (edx & 0xffffff00u) | ((0) & 0xff);  // @195_572850
  FL[3] = (edx & 0xff);  // @196_572850
  esi = (u32)(ebx + 92);  // @197_572850
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2140), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @198_572850
  edi = (u32)(1);  // @199_572850
  if ((s32)FL[0] <= (s32)FL[1]) goto L572b1d;  // @200_572850
  eax = (u32)(4294967204);  // @201_572850
  ecx = esi;  // @202_572850
  eax = (eax - ebx);  // @203_572850
  FL[3] = eax;  // @204_572850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @205_572850
  L572a64:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @207_572850
  if (FL[0] != FL[1]) goto L572a76;  // @208_572850
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @209_572850
  if (FL[2] == 0) goto L572a73;  // @210_572850
  edi = (edi + 1);  // @211_572850
  FL[3] = edi;  // @212_572850
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @213_572850
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @214_572850
  L572a73:;
  edx = (edx & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @216_572850
  L572a76:;
  ecx = (ecx + 1);  // @218_572850
  FL[3] = ecx;  // @219_572850
  eax = (eax + ecx);  // @220_572850
  FL[3] = eax;  // @221_572850
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2140), sizeof v); (u32)v; });  // @222_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @223_572850
  if ((s32)FL[0] < (s32)FL[1]) goto L572a64;  // @224_572850
  FL[0] = edi; FL[1] = (u32)(1);  // @225_572850
  if ((s32)FL[0] <= (s32)FL[1]) goto L572b1d;  // @226_572850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2140), sizeof v); (u32)v; });  // @227_572850
  ecx = 0;  // @228_572850
  FL[3] = ecx;  // @229_572850
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ebx + 91), sizeof v); (u32)v; }); FL[1] = (ecx & 0xff);  // @230_572850
  eax = (u32)(edx - 1);  // @231_572850
  if (FL[0] == FL[1]) goto L572aac;  // @232_572850
  L572aa0:;
  FL[2] = (eax & eax);  // @234_572850
  if (FL[2] == 0) goto L572aac;  // @235_572850
  eax = (eax - 1);  // @236_572850
  FL[3] = eax;  // @237_572850
  ecx = (ecx + 1);  // @238_572850
  FL[3] = ecx;  // @239_572850
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @240_572850
  if (FL[0] != FL[1]) goto L572aa0;  // @241_572850
  L572aac:;
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @243_572850
  eax = (u32)(edi - 1);  // @244_572850
  X0[0] = edx; X0[1] = X0[2] = X0[3] = 0;  // @245_572850
  X1[0] = F2U((float)(s32)X1[0]);  // @246_572850
  X1[1] = F2U((float)(s32)X1[1]);  // @247_572850
  X1[2] = F2U((float)(s32)X1[2]);  // @248_572850
  X1[3] = F2U((float)(s32)X1[3]);  // @249_572850
  X0[0] = F2U((float)(s32)X0[0]);  // @250_572850
  X0[1] = F2U((float)(s32)X0[1]);  // @251_572850
  X0[2] = F2U((float)(s32)X0[2]);  // @252_572850
  X0[3] = F2U((float)(s32)X0[3]);  // @253_572850
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @254_572850
  X3[1] = 0;  // @255_572850
  X3[2] = 0;  // @256_572850
  X3[3] = 0;  // @257_572850
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @258_572850
  X4[0] = eax; X4[1] = X4[2] = X4[3] = 0;  // @259_572850
  X2[0] = X3[0];  // @260_572850
  X2[1] = X3[1];  // @261_572850
  X2[2] = X3[2];  // @262_572850
  X2[3] = X3[3];  // @263_572850
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @264_572850
  X4[0] = F2U((float)(s32)X4[0]);  // @265_572850
  X4[1] = F2U((float)(s32)X4[1]);  // @266_572850
  X4[2] = F2U((float)(s32)X4[2]);  // @267_572850
  X4[3] = F2U((float)(s32)X4[3]);  // @268_572850
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @269_572850
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @270_572850
  X0[1] = 0;  // @271_572850
  X0[2] = 0;  // @272_572850
  X0[3] = 0;  // @273_572850
  X2[0] = F2U(U2F(X2[0]) / U2F(X4[0]));  // @274_572850
  __builtin_memcpy((void *)((u32)(ebx + 84) + 0), &X2[0], 4);  // @275_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @276_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @277_572850
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L572b0f;  // @278_572850
  X2[0] = F2U(U2F(X2[0]) * U2F(X4[0]));  // @279_572850
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @280_572850
  { float f_ = U2F(X2[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @281_572850
  eax = (eax - ecx);  // @282_572850
  FL[3] = eax;  // @283_572850
  eax = (eax + (u32)(2048));  // @284_572850
  FL[3] = eax;  // @285_572850
  goto L572b3d;  // @286_572850
  L572b0f:;
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @288_572850
  { float f_ = U2F(X3[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @289_572850
  goto L572b3b;  // @290_572850
  L572b1d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @292_572850
  X0[1] = 0;  // @293_572850
  X0[2] = 0;  // @294_572850
  X0[3] = 0;  // @295_572850
  __builtin_memcpy((void *)((u32)(ebx + 84) + 0), &X0[0], 4);  // @296_572850
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @297_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @298_572850
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @299_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @300_572850
  L572b3b:;
  eax = (eax - ecx);  // @302_572850
  FL[3] = eax;  // @303_572850
  L572b3d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2162), sizeof v); (u32)v; });  // @305_572850
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @306_572850
  X0[0] = F2U((float)(s32)X0[0]);  // @307_572850
  X0[1] = F2U((float)(s32)X0[1]);  // @308_572850
  X0[2] = F2U((float)(s32)X0[2]);  // @309_572850
  X0[3] = F2U((float)(s32)X0[3]);  // @310_572850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 2144), &v, sizeof v); }  // @311_572850
  PV[5] = (u32)(esi);  // @312_572850
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @313_572850
  __builtin_memcpy((void *)((u32)(ebx + 88) + 0), &X0[0], 4);  // @314_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @315_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[5]);  // @316_572850
  ecx = edx = 0;  // @317_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2162), sizeof v); (u32)v; });  // @318_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @319_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @320_572850
  ecx = edx = 0;  // @321_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2166), sizeof v); (u32)v; });  // @322_572850
  FL[2] = (ecx & ecx);  // @323_572850
  if (FL[2] == 0) goto L572b9e;  // @324_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @325_572850
  PV[6] = (u32)(esi);  // @326_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, PV[6]);  // @327_572850
  ecx = edx = 0;  // @328_572850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2166), sizeof v); (u32)v; });  // @329_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @330_572850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @331_572850
  ecx = edx = 0;  // @332_572850
  L572b9e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 84) + 0), 4); v; });  // @334_572850
  X0[1] = 0;  // @335_572850
  X0[2] = 0;  // @336_572850
  X0[3] = 0;  // @337_572850
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @338_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @339_572850
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @340_572850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @341_572850
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 2156), &v, sizeof v); }  // @342_572850
  eax = (eax - ecx);  // @343_572850
  FL[3] = eax;  // @344_572850
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @345_572850
  X0[0] = F2U((float)(s32)X0[0]);  // @346_572850
  X0[1] = F2U((float)(s32)X0[1]);  // @347_572850
  X0[2] = F2U((float)(s32)X0[2]);  // @348_572850
  X0[3] = F2U((float)(s32)X0[3]);  // @349_572850
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @350_572850
  __builtin_memcpy((void *)((u32)(ebx + 80) + 0), &X0[0], 4);  // @351_572850
  return eax;  // @352_572850
}
PCREG(572850, lifted_572850);

extern "C" u32 THISCALL lifted_561400(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ecx;  // @0_561400
  edi = 0;  // @1_561400
  FL[3] = edi;  // @2_561400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @3_561400
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @4_561400
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 216), sizeof v); (u32)v; }); FL[1] = edi;  // @5_561400
  if ((s32)FL[0] <= (s32)FL[1]) goto L56170d;  // @6_561400
  ebx = (u32)(eax + 152);  // @7_561400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @8_561400
  L561432:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_561400
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @11_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_561400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @14_561400
  ecx = edx = 0;  // @15_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_561400
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_561400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @18_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_561400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_561400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[1]);  // @21_561400
  ecx = edx = 0;  // @22_561400
  ebx = eax;  // @23_561400
  esi = 0;  // @24_561400
  FL[3] = esi;  // @25_561400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @26_561400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @27_561400
  FL[2] = (ebx & ebx);  // @28_561400
  if (FL[2] == 0) goto L5616ef;  // @29_561400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @30_561400
  ecx = ebx;  // @31_561400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @32_561400
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(1048622));  // @33_561400
  ecx = edx = 0;  // @34_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @35_561400
  if (FL[2] == 0) goto L5614b0;  // @36_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_561400
  ecx = ebx;  // @38_561400
  PV[2] = (u32)(esi);  // @39_561400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6972848), PV[2]);  // @40_561400
  ecx = edx = 0;  // @41_561400
  esi = eax;  // @42_561400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @43_561400
  FL[2] = (esi & esi);  // @44_561400
  if (FL[2] != 0) goto L5614b0;  // @45_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @46_561400
  ecx = ebx;  // @47_561400
  PV[3] = (u32)(esi);  // @48_561400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6923868), PV[3]);  // @49_561400
  ecx = edx = 0;  // @50_561400
  esi = eax;  // @51_561400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @52_561400
  L5614b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @54_561400
  ecx = ebx;  // @55_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @56_561400
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097197));  // @57_561400
  ecx = edx = 0;  // @58_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @59_561400
  if (FL[2] != 0) goto L5614da;  // @60_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_561400
  ecx = ebx;  // @62_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @63_561400
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097208));  // @64_561400
  ecx = edx = 0;  // @65_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @66_561400
  if (FL[2] == 0) goto L5614df;  // @67_561400
  L5614da:;
  esi = ebx;  // @69_561400
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @70_561400
  L5614df:;
  FL[2] = (esi & esi);  // @72_561400
  if (FL[2] == 0) goto L5616ef;  // @73_561400
  eax = 0;  // @74_561400
  FL[3] = eax;  // @75_561400
  ecx = esi;  // @76_561400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @77_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @79_561400
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097208));  // @80_561400
  ecx = edx = 0;  // @81_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @82_561400
  if (FL[2] != 0) goto L56151a;  // @83_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_561400
  ecx = esi;  // @85_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @86_561400
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097197));  // @87_561400
  ecx = edx = 0;  // @88_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @89_561400
  if (FL[2] == 0) goto L5616b9;  // @90_561400
  L56151a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 151), sizeof v); (u32)v; });  // @92_561400
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @93_561400
  FL[2] = (ecx & ecx);  // @94_561400
  if (FL[2] == 0) goto L5616b9;  // @95_561400
  edi = ecx;  // @96_561400
  edx = (u32)(edi + 1);  // @97_561400
  L561530:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @99_561400
  edi = (edi + 1);  // @100_561400
  FL[3] = edi;  // @101_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @102_561400
  if (FL[2] != 0) goto L561530;  // @103_561400
  edi = (edi - edx);  // @104_561400
  FL[3] = edi;  // @105_561400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @106_561400
  ebx = 0;  // @107_561400
  FL[3] = ebx;  // @108_561400
  FL[0] = ebx; FL[1] = edi;  // @109_561400
  L561544:;
  if (FL[0] == FL[1]) goto L56154f;  // @111_561400
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @112_561400
  eax = (u32)(ebx + 1);  // @113_561400
  if (FL[0] != FL[1]) goto L561586;  // @114_561400
  L56154f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_561400
  ecx = esi;  // @117_561400
  PV[4] = (u32)(ebx);  // @118_561400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, PV[4]);  // @119_561400
  ecx = edx = 0;  // @120_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @121_561400
  esi = eax;  // @122_561400
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @123_561400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_561400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 656)))(ecx, PV[5]);  // @125_561400
  ecx = edx = 0;  // @126_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @127_561400
  esi = (esi - eax);  // @128_561400
  FL[3] = esi;  // @129_561400
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @130_561400
  eax = (u32)(ebx + 1);  // @131_561400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @132_561400
  if ((s32)FL[0] <= (s32)FL[1]) esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @133_561400
  edx = esi;  // @134_561400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @135_561400
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @136_561400
  goto L561589;  // @137_561400
  L561586:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @139_561400
  L561589:;
  ebx = eax;  // @141_561400
  FL[0] = ebx; FL[1] = edi;  // @142_561400
  if (FL[0] <= FL[1]) goto L561544;  // @143_561400
  FL[2] = (edx & edx);  // @144_561400
  if (FL[2] == 0) goto L5616b3;  // @145_561400
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @146_561400
  FL[2] = (ebx & ebx);  // @147_561400
  if (FL[2] == 0) goto L5616ec;  // @148_561400
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @149_561400
  eax = (u32)(EBP - 40);  // @150_561400
  PV[6] = (u32)(eax);  // @151_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @152_561400
  eax = ext_4db500_thiscall2(ecx, PV[6]);  // @153_561400
  ecx = edx = 0;  // @154_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @155_561400
  eax = (u32)(EBP - 52);  // @156_561400
  PV[7] = (u32)(eax);  // @157_561400
  eax = ext_4db500_thiscall2(ecx, PV[7]);  // @158_561400
  ecx = edx = 0;  // @159_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @160_561400
  FL[0] = edi; FL[1] = esi;  // @161_561400
  if (FL[0] == FL[1]) goto L5615db;  // @162_561400
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @163_561400
  X1[1] = 0;  // @164_561400
  X1[2] = 0;  // @165_561400
  X1[3] = 0;  // @166_561400
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @167_561400
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @168_561400
  X0[0] = F2U((float)(s32)X0[0]);  // @169_561400
  X0[1] = F2U((float)(s32)X0[1]);  // @170_561400
  X0[2] = F2U((float)(s32)X0[2]);  // @171_561400
  X0[3] = F2U((float)(s32)X0[3]);  // @172_561400
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @173_561400
  goto L5615e7;  // @174_561400
  L5615db:;
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @176_561400
  X1[0] = F2U((float)(s32)X1[0]);  // @177_561400
  X1[1] = F2U((float)(s32)X1[1]);  // @178_561400
  X1[2] = F2U((float)(s32)X1[2]);  // @179_561400
  X1[3] = F2U((float)(s32)X1[3]);  // @180_561400
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @181_561400
  L5615e7:;
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @183_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @184_561400
  eax = (u32)(EBP - 16);  // @185_561400
  PV[8] = (u32)(eax);  // @186_561400
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X1[0], 4);  // @187_561400
  eax = ext_4db500_thiscall2(ecx, PV[8]);  // @188_561400
  ecx = edx = 0;  // @189_561400
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @190_561400
  X0[1] = 0;  // @191_561400
  X0[2] = 0;  // @192_561400
  X0[3] = 0;  // @193_561400
  ecx = (u32)(EBP - 16);  // @194_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @195_561400
  X1[0] = X0[0];  // @196_561400
  X1[1] = X0[1];  // @197_561400
  X1[2] = X0[2];  // @198_561400
  X1[3] = X0[3];  // @199_561400
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @200_561400
  PV[9] = (u32)(ecx);  // @201_561400
  ecx = ebx;  // @202_561400
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @203_561400
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X1[0], 4);  // @204_561400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[9]);  // @205_561400
  ecx = edx = 0;  // @206_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @207_561400
  ecx = ebx;  // @208_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @209_561400
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048622));  // @210_561400
  ecx = edx = 0;  // @211_561400
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @212_561400
  if (FL[2] == 0) goto L5616ec;  // @213_561400
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @214_561400
  L561640:;
  FL[2] = (edi & edi);  // @216_561400
  if (FL[2] == 0) goto L5616ec;  // @217_561400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @218_561400
  FL[2] = (esi & esi);  // @219_561400
  if (FL[2] == 0) goto L561657;  // @220_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @221_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @222_561400
  goto L56165c;  // @223_561400
  L561657:;
  eax = (u32)(2097154);  // @225_561400
  L56165c:;
  FL[2] = (eax & (u32)(1048576));  // @227_561400
  if (FL[2] != 0) goto L5616ec;  // @228_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @229_561400
  ecx = (u32)(6801640);  // @230_561400
  FL[2] = (eax & eax);  // @231_561400
  edx = (u32)(6972856);  // @232_561400
  if (FL[2] != 0) ecx = eax;  // @233_561400
  eax = ext_4cc850_fastcall2(ecx, edx);  // @234_561400
  ecx = edx = 0;  // @235_561400
  FL[2] = (eax & eax);  // @236_561400
  if (FL[2] != 0) goto L5616a8;  // @237_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @238_561400
  eax = (u32)(EBP - 28);  // @239_561400
  PV[10] = (u32)(eax);  // @240_561400
  eax = ext_4db500_thiscall2(ecx, PV[10]);  // @241_561400
  ecx = edx = 0;  // @242_561400
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @243_561400
  X0[1] = 0;  // @244_561400
  X0[2] = 0;  // @245_561400
  X0[3] = 0;  // @246_561400
  ecx = (u32)(EBP - 28);  // @247_561400
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; })));  // @248_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @249_561400
  PV[11] = (u32)(ecx);  // @250_561400
  ecx = esi;  // @251_561400
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @252_561400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[11]);  // @253_561400
  ecx = edx = 0;  // @254_561400
  L5616a8:;
  ecx = edi;  // @256_561400
  eax = ext_4db520_thiscall1(ecx);  // @257_561400
  ecx = edx = 0;  // @258_561400
  edi = eax;  // @259_561400
  goto L561640;  // @260_561400
  L5616b3:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @262_561400
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @263_561400
  L5616b9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @265_561400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @266_561400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6972596), (u32)(351));  // @267_561400
  ecx = edx = 0;  // @268_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @269_561400
  edx = (u32)(6801640);  // @270_561400
  FL[2] = (ecx & ecx);  // @271_561400
  if (FL[2] != 0) edx = ecx;  // @272_561400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @273_561400
  PV[12] = (u32)(edx);  // @274_561400
  PV[13] = (u32)(eax);  // @275_561400
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[13], (u32)(6972864), PV[12]);  // @276_561400
  ecx = edx = 0;  // @277_561400
  goto L5616ef;  // @278_561400
  L5616ec:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @280_561400
  L5616ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @282_561400
  edi = (edi + 1);  // @283_561400
  FL[3] = edi;  // @284_561400
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @285_561400
  ebx = (ebx + (u32)(8));  // @286_561400
  FL[3] = ebx;  // @287_561400
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @288_561400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @289_561400
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 216), sizeof v); (u32)v; });  // @290_561400
  if ((s32)FL[0] < (s32)FL[1]) goto L561432;  // @291_561400
  L56170d:;
  ext_633654(G(u32, 0x6f5630));  // @293_561400
  return eax;  // @294_561400
}
PCREG(561400, lifted_561400);

extern "C" u32 THISCALL lifted_51cbd0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[67], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_51cbd0
  ebx = ecx;  // @1_51cbd0
  PV[0] = (u32)(esi);  // @2_51cbd0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_51cbd0
  eax = ext_513ff0_thiscall2(ecx, PV[0]);  // @4_51cbd0
  ecx = edx = 0;  // @5_51cbd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_51cbd0
  if (FL[2] != 0) goto L51cbf0;  // @7_51cbd0
  return eax;  // @8_51cbd0
  L51cbf0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_51cbd0
  eax = (u32)(ebx + 534);  // @11_51cbd0
  PV[1] = (u32)(eax);  // @12_51cbd0
  ecx = esi;  // @13_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[1]);  // @14_51cbd0
  ecx = edx = 0;  // @15_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_51cbd0
  eax = (u32)(ebx + 546);  // @17_51cbd0
  PV[2] = (u32)(eax);  // @18_51cbd0
  ecx = esi;  // @19_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[2]);  // @20_51cbd0
  ecx = edx = 0;  // @21_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 558) + 0), 4); v; });  // @23_51cbd0
  X0[1] = 0;  // @24_51cbd0
  X0[2] = 0;  // @25_51cbd0
  X0[3] = 0;  // @26_51cbd0
  PV[3] = (u32)(ecx);  // @27_51cbd0
  ecx = esi;  // @28_51cbd0
  PV[4] = X0[0];  // @29_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @30_51cbd0
  ecx = edx = 0;  // @31_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 562) + 0), 4); v; });  // @33_51cbd0
  X0[1] = 0;  // @34_51cbd0
  X0[2] = 0;  // @35_51cbd0
  X0[3] = 0;  // @36_51cbd0
  PV[5] = (u32)(ecx);  // @37_51cbd0
  ecx = esi;  // @38_51cbd0
  PV[6] = X0[0];  // @39_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @40_51cbd0
  ecx = edx = 0;  // @41_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 566) + 0), 4); v; });  // @43_51cbd0
  X0[1] = 0;  // @44_51cbd0
  X0[2] = 0;  // @45_51cbd0
  X0[3] = 0;  // @46_51cbd0
  PV[7] = (u32)(ecx);  // @47_51cbd0
  ecx = esi;  // @48_51cbd0
  PV[8] = X0[0];  // @49_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @50_51cbd0
  ecx = edx = 0;  // @51_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 570) + 0), 4); v; });  // @53_51cbd0
  X0[1] = 0;  // @54_51cbd0
  X0[2] = 0;  // @55_51cbd0
  X0[3] = 0;  // @56_51cbd0
  PV[9] = (u32)(ecx);  // @57_51cbd0
  ecx = esi;  // @58_51cbd0
  PV[10] = X0[0];  // @59_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[10]);  // @60_51cbd0
  ecx = edx = 0;  // @61_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_51cbd0
  eax = (u32)(ebx + 574);  // @63_51cbd0
  PV[11] = (u32)(eax);  // @64_51cbd0
  ecx = esi;  // @65_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[11]);  // @66_51cbd0
  ecx = edx = 0;  // @67_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @68_51cbd0
  eax = (u32)(ebx + 586);  // @69_51cbd0
  PV[12] = (u32)(eax);  // @70_51cbd0
  ecx = esi;  // @71_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[12]);  // @72_51cbd0
  ecx = edx = 0;  // @73_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_51cbd0
  eax = (u32)(ebx + 598);  // @75_51cbd0
  PV[13] = (u32)(eax);  // @76_51cbd0
  ecx = esi;  // @77_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[13]);  // @78_51cbd0
  ecx = edx = 0;  // @79_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_51cbd0
  eax = (u32)(ebx + 1009);  // @81_51cbd0
  PV[14] = (u32)(eax);  // @82_51cbd0
  ecx = esi;  // @83_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[14]);  // @84_51cbd0
  ecx = edx = 0;  // @85_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_51cbd0
  eax = (u32)(ebx + 610);  // @87_51cbd0
  PV[15] = (u32)(eax);  // @88_51cbd0
  ecx = esi;  // @89_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[15]);  // @90_51cbd0
  ecx = edx = 0;  // @91_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 622) + 0), 4); v; });  // @93_51cbd0
  X0[1] = 0;  // @94_51cbd0
  X0[2] = 0;  // @95_51cbd0
  X0[3] = 0;  // @96_51cbd0
  PV[16] = (u32)(ecx);  // @97_51cbd0
  ecx = esi;  // @98_51cbd0
  PV[17] = X0[0];  // @99_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @100_51cbd0
  ecx = edx = 0;  // @101_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 626) + 0), 4); v; });  // @103_51cbd0
  X0[1] = 0;  // @104_51cbd0
  X0[2] = 0;  // @105_51cbd0
  X0[3] = 0;  // @106_51cbd0
  PV[18] = (u32)(ecx);  // @107_51cbd0
  ecx = esi;  // @108_51cbd0
  PV[19] = X0[0];  // @109_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[19]);  // @110_51cbd0
  ecx = edx = 0;  // @111_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_51cbd0
  eax = (u32)(ebx + 630);  // @113_51cbd0
  PV[20] = (u32)(eax);  // @114_51cbd0
  ecx = esi;  // @115_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[20]);  // @116_51cbd0
  ecx = edx = 0;  // @117_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @118_51cbd0
  eax = (u32)(ebx + 642);  // @119_51cbd0
  PV[21] = (u32)(eax);  // @120_51cbd0
  ecx = esi;  // @121_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[21]);  // @122_51cbd0
  ecx = edx = 0;  // @123_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_51cbd0
  eax = (u32)(ebx + 654);  // @125_51cbd0
  PV[22] = (u32)(eax);  // @126_51cbd0
  ecx = esi;  // @127_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[22]);  // @128_51cbd0
  ecx = edx = 0;  // @129_51cbd0
  PV[23] = (u32)(esi);  // @130_51cbd0
  ecx = (u32)(ebx + 666);  // @131_51cbd0
  eax = ext_527190_thiscall2(ecx, PV[23]);  // @132_51cbd0
  ecx = edx = 0;  // @133_51cbd0
  PV[24] = (u32)(esi);  // @134_51cbd0
  ecx = (u32)(ebx + 707);  // @135_51cbd0
  eax = ext_527190_thiscall2(ecx, PV[24]);  // @136_51cbd0
  ecx = edx = 0;  // @137_51cbd0
  PV[25] = (u32)(esi);  // @138_51cbd0
  ecx = (u32)(ebx + 748);  // @139_51cbd0
  eax = ext_527190_thiscall2(ecx, PV[25]);  // @140_51cbd0
  ecx = edx = 0;  // @141_51cbd0
  PV[26] = (u32)(esi);  // @142_51cbd0
  ecx = (u32)(ebx + 789);  // @143_51cbd0
  eax = ext_527190_thiscall2(ecx, PV[26]);  // @144_51cbd0
  ecx = edx = 0;  // @145_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 830) + 0), 4); v; });  // @147_51cbd0
  X0[1] = 0;  // @148_51cbd0
  X0[2] = 0;  // @149_51cbd0
  X0[3] = 0;  // @150_51cbd0
  PV[27] = (u32)(ecx);  // @151_51cbd0
  ecx = esi;  // @152_51cbd0
  PV[28] = X0[0];  // @153_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[28]);  // @154_51cbd0
  ecx = edx = 0;  // @155_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 834) + 0), 4); v; });  // @157_51cbd0
  X0[1] = 0;  // @158_51cbd0
  X0[2] = 0;  // @159_51cbd0
  X0[3] = 0;  // @160_51cbd0
  PV[29] = (u32)(ecx);  // @161_51cbd0
  ecx = esi;  // @162_51cbd0
  PV[30] = X0[0];  // @163_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[30]);  // @164_51cbd0
  ecx = edx = 0;  // @165_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @166_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 838) + 0), 4); v; });  // @167_51cbd0
  X0[1] = 0;  // @168_51cbd0
  X0[2] = 0;  // @169_51cbd0
  X0[3] = 0;  // @170_51cbd0
  PV[31] = (u32)(ecx);  // @171_51cbd0
  ecx = esi;  // @172_51cbd0
  PV[32] = X0[0];  // @173_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[32]);  // @174_51cbd0
  ecx = edx = 0;  // @175_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_51cbd0
  ecx = esi;  // @177_51cbd0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 842), sizeof v); (u32)v; });  // @178_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[33]);  // @179_51cbd0
  ecx = edx = 0;  // @180_51cbd0
  PV[34] = (u32)(esi);  // @181_51cbd0
  ecx = (u32)(ebx + 846);  // @182_51cbd0
  eax = ext_5274f0_thiscall2(ecx, PV[34]);  // @183_51cbd0
  ecx = edx = 0;  // @184_51cbd0
  PV[35] = (u32)(esi);  // @185_51cbd0
  ecx = (u32)(ebx + 927);  // @186_51cbd0
  eax = ext_527190_thiscall2(ecx, PV[35]);  // @187_51cbd0
  ecx = edx = 0;  // @188_51cbd0
  PV[36] = (u32)(esi);  // @189_51cbd0
  ecx = (u32)(ebx + 968);  // @190_51cbd0
  eax = ext_527190_thiscall2(ecx, PV[36]);  // @191_51cbd0
  ecx = edx = 0;  // @192_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @193_51cbd0
  ecx = esi;  // @194_51cbd0
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1021), sizeof v); (u32)v; });  // @195_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[37]);  // @196_51cbd0
  ecx = edx = 0;  // @197_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_51cbd0
  ecx = esi;  // @199_51cbd0
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1101), sizeof v); (u32)v; });  // @200_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[38]);  // @201_51cbd0
  ecx = edx = 0;  // @202_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @203_51cbd0
  eax = (u32)(ebx + 1117);  // @204_51cbd0
  PV[39] = (u32)(eax);  // @205_51cbd0
  ecx = esi;  // @206_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[39]);  // @207_51cbd0
  ecx = edx = 0;  // @208_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @209_51cbd0
  ecx = esi;  // @210_51cbd0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1129), sizeof v); (u32)v; });  // @211_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[40]);  // @212_51cbd0
  ecx = edx = 0;  // @213_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @214_51cbd0
  ecx = esi;  // @215_51cbd0
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1145), sizeof v); (u32)v; });  // @216_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[41]);  // @217_51cbd0
  ecx = edx = 0;  // @218_51cbd0
  PV[42] = (u32)(esi);  // @219_51cbd0
  ecx = (u32)(ebx + 1197);  // @220_51cbd0
  eax = ext_516e20_thiscall2(ecx, PV[42]);  // @221_51cbd0
  ecx = edx = 0;  // @222_51cbd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @223_51cbd0
  eax = (u32)(ebx + 1318);  // @224_51cbd0
  PV[43] = (u32)(eax);  // @225_51cbd0
  ecx = esi;  // @226_51cbd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[43], (u32)(109));  // @227_51cbd0
  ecx = edx = 0;  // @228_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @229_51cbd0
  PV[44] = (u32)(ecx);  // @230_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1427) + 0), 4); v; });  // @231_51cbd0
  X0[1] = 0;  // @232_51cbd0
  X0[2] = 0;  // @233_51cbd0
  X0[3] = 0;  // @234_51cbd0
  ecx = esi;  // @235_51cbd0
  PV[45] = X0[0];  // @236_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[45]);  // @237_51cbd0
  ecx = edx = 0;  // @238_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @239_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1431) + 0), 4); v; });  // @240_51cbd0
  X0[1] = 0;  // @241_51cbd0
  X0[2] = 0;  // @242_51cbd0
  X0[3] = 0;  // @243_51cbd0
  PV[46] = (u32)(ecx);  // @244_51cbd0
  ecx = esi;  // @245_51cbd0
  PV[47] = X0[0];  // @246_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[47]);  // @247_51cbd0
  ecx = edx = 0;  // @248_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @249_51cbd0
  ecx = esi;  // @250_51cbd0
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1169), sizeof v); (u32)v; });  // @251_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[48]);  // @252_51cbd0
  ecx = edx = 0;  // @253_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @254_51cbd0
  ecx = esi;  // @255_51cbd0
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1173), sizeof v); (u32)v; });  // @256_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[49]);  // @257_51cbd0
  ecx = edx = 0;  // @258_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @259_51cbd0
  ecx = esi;  // @260_51cbd0
  PV[50] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1177), sizeof v); (u32)v; });  // @261_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[50]);  // @262_51cbd0
  ecx = edx = 0;  // @263_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @264_51cbd0
  ecx = esi;  // @265_51cbd0
  PV[51] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1181), sizeof v); (u32)v; });  // @266_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[51]);  // @267_51cbd0
  ecx = edx = 0;  // @268_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @269_51cbd0
  ecx = esi;  // @270_51cbd0
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1185), sizeof v); (u32)v; });  // @271_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[52]);  // @272_51cbd0
  ecx = edx = 0;  // @273_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @274_51cbd0
  ecx = esi;  // @275_51cbd0
  PV[53] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1189), sizeof v); (u32)v; });  // @276_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[53]);  // @277_51cbd0
  ecx = edx = 0;  // @278_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @279_51cbd0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1193) + 0), 4); v; });  // @280_51cbd0
  X0[1] = 0;  // @281_51cbd0
  X0[2] = 0;  // @282_51cbd0
  X0[3] = 0;  // @283_51cbd0
  PV[54] = (u32)(ecx);  // @284_51cbd0
  ecx = esi;  // @285_51cbd0
  PV[55] = X0[0];  // @286_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[55]);  // @287_51cbd0
  ecx = edx = 0;  // @288_51cbd0
  edi = (u32)(ebx + 1061);  // @289_51cbd0
  ebx = (u32)(5);  // @290_51cbd0
  L51ce91:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @292_51cbd0
  ecx = esi;  // @293_51cbd0
  PV[56] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 20), sizeof v); (u32)v; });  // @294_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[56]);  // @295_51cbd0
  ecx = edx = 0;  // @296_51cbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @297_51cbd0
  ecx = esi;  // @298_51cbd0
  PV[57] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @299_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[57]);  // @300_51cbd0
  ecx = edx = 0;  // @301_51cbd0
  edi = (u32)(edi + 4);  // @302_51cbd0
  ebx = (ebx - (u32)(1));  // @303_51cbd0
  FL[3] = ebx;  // @304_51cbd0
  if (FL[3] != 0) goto L51ce91;  // @305_51cbd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @306_51cbd0
  ebx = (u32)(4);  // @307_51cbd0
  edi = (edi + (u32)(1081));  // @308_51cbd0
  FL[3] = edi;  // @309_51cbd0
  L51cec0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @311_51cbd0
  ecx = esi;  // @312_51cbd0
  PV[58] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @313_51cbd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[58]);  // @314_51cbd0
  ecx = edx = 0;  // @315_51cbd0
  edi = (u32)(edi + 4);  // @316_51cbd0
  ebx = (ebx - (u32)(1));  // @317_51cbd0
  FL[3] = ebx;  // @318_51cbd0
  if (FL[3] != 0) goto L51cec0;  // @319_51cbd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @320_51cbd0
  PV[59] = (u32)(esi);  // @321_51cbd0
  ecx = (u32)(ecx + 1435);  // @322_51cbd0
  eax = ext_513f50_thiscall2(ecx, PV[59]);  // @323_51cbd0
  ecx = edx = 0;  // @324_51cbd0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @325_51cbd0
  return eax;  // @326_51cbd0
}
PCREG(51cbd0, lifted_51cbd0);

extern "C" u32 THISCALL lifted_5aac30(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5aac30
  PV[0] = (u32)(ebx);  // @1_5aac30
  esi = ecx;  // @2_5aac30
  eax = ext_45f960_thiscall2(ecx, PV[0]);  // @3_5aac30
  ecx = edx = 0;  // @4_5aac30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @5_5aac30
  if (FL[2] != 0) goto L5aac4a;  // @6_5aac30
  return eax;  // @7_5aac30
  L5aac4a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_5aac30
  ecx = ebx;  // @10_5aac30
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1693), sizeof v); (u32)v; });  // @11_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[1]);  // @12_5aac30
  ecx = edx = 0;  // @13_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 764) + 0), 4); v; });  // @15_5aac30
  X0[1] = 0;  // @16_5aac30
  X0[2] = 0;  // @17_5aac30
  X0[3] = 0;  // @18_5aac30
  PV[2] = (u32)(ecx);  // @19_5aac30
  ecx = ebx;  // @20_5aac30
  PV[3] = X0[0];  // @21_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @22_5aac30
  ecx = edx = 0;  // @23_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_5aac30
  ecx = ebx;  // @25_5aac30
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 852), sizeof v); (u32)v; });  // @26_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[4]);  // @27_5aac30
  ecx = edx = 0;  // @28_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 856) + 0), 4); v; });  // @30_5aac30
  X0[1] = 0;  // @31_5aac30
  X0[2] = 0;  // @32_5aac30
  X0[3] = 0;  // @33_5aac30
  PV[5] = (u32)(ecx);  // @34_5aac30
  ecx = ebx;  // @35_5aac30
  PV[6] = X0[0];  // @36_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @37_5aac30
  ecx = edx = 0;  // @38_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @39_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 860) + 0), 4); v; });  // @40_5aac30
  X0[1] = 0;  // @41_5aac30
  X0[2] = 0;  // @42_5aac30
  X0[3] = 0;  // @43_5aac30
  PV[7] = (u32)(ecx);  // @44_5aac30
  ecx = ebx;  // @45_5aac30
  PV[8] = X0[0];  // @46_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @47_5aac30
  ecx = edx = 0;  // @48_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 1068) + 0), 4); v; });  // @50_5aac30
  X0[1] = 0;  // @51_5aac30
  X0[2] = 0;  // @52_5aac30
  X0[3] = 0;  // @53_5aac30
  PV[9] = (u32)(ecx);  // @54_5aac30
  ecx = ebx;  // @55_5aac30
  PV[10] = X0[0];  // @56_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[10]);  // @57_5aac30
  ecx = edx = 0;  // @58_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @59_5aac30
  ecx = ebx;  // @60_5aac30
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 980), sizeof v); (u32)v; });  // @61_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[11]);  // @62_5aac30
  ecx = edx = 0;  // @63_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_5aac30
  ecx = ebx;  // @65_5aac30
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 984), sizeof v); (u32)v; });  // @66_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[12]);  // @67_5aac30
  ecx = edx = 0;  // @68_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @69_5aac30
  ecx = ebx;  // @70_5aac30
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 988), sizeof v); (u32)v; });  // @71_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[13]);  // @72_5aac30
  ecx = edx = 0;  // @73_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @74_5aac30
  ecx = ebx;  // @75_5aac30
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 992), sizeof v); (u32)v; });  // @76_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[14]);  // @77_5aac30
  ecx = edx = 0;  // @78_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @79_5aac30
  ecx = ebx;  // @80_5aac30
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 996), sizeof v); (u32)v; });  // @81_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[15]);  // @82_5aac30
  ecx = edx = 0;  // @83_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @84_5aac30
  ecx = ebx;  // @85_5aac30
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1000), sizeof v); (u32)v; });  // @86_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[16]);  // @87_5aac30
  ecx = edx = 0;  // @88_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @89_5aac30
  ecx = ebx;  // @90_5aac30
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1004), sizeof v); (u32)v; });  // @91_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[17]);  // @92_5aac30
  ecx = edx = 0;  // @93_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @94_5aac30
  ecx = ebx;  // @95_5aac30
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1008), sizeof v); (u32)v; });  // @96_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[18]);  // @97_5aac30
  ecx = edx = 0;  // @98_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @99_5aac30
  ecx = ebx;  // @100_5aac30
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1012), sizeof v); (u32)v; });  // @101_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[19]);  // @102_5aac30
  ecx = edx = 0;  // @103_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_5aac30
  ecx = ebx;  // @105_5aac30
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1016), sizeof v); (u32)v; });  // @106_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[20]);  // @107_5aac30
  ecx = edx = 0;  // @108_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @109_5aac30
  ecx = ebx;  // @110_5aac30
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1020), sizeof v); (u32)v; });  // @111_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[21]);  // @112_5aac30
  ecx = edx = 0;  // @113_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @114_5aac30
  ecx = ebx;  // @115_5aac30
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1024), sizeof v); (u32)v; });  // @116_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[22]);  // @117_5aac30
  ecx = edx = 0;  // @118_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_5aac30
  ecx = ebx;  // @120_5aac30
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1028), sizeof v); (u32)v; });  // @121_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[23]);  // @122_5aac30
  ecx = edx = 0;  // @123_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @124_5aac30
  ecx = ebx;  // @125_5aac30
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1032), sizeof v); (u32)v; });  // @126_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[24]);  // @127_5aac30
  ecx = edx = 0;  // @128_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @129_5aac30
  ecx = ebx;  // @130_5aac30
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1036), sizeof v); (u32)v; });  // @131_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[25]);  // @132_5aac30
  ecx = edx = 0;  // @133_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @134_5aac30
  ecx = ebx;  // @135_5aac30
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1040), sizeof v); (u32)v; });  // @136_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[26]);  // @137_5aac30
  ecx = edx = 0;  // @138_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @139_5aac30
  ecx = ebx;  // @140_5aac30
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1044), sizeof v); (u32)v; });  // @141_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[27]);  // @142_5aac30
  ecx = edx = 0;  // @143_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @144_5aac30
  ecx = ebx;  // @145_5aac30
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1048), sizeof v); (u32)v; });  // @146_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[28]);  // @147_5aac30
  ecx = edx = 0;  // @148_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @149_5aac30
  ecx = ebx;  // @150_5aac30
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 962), sizeof v); (u32)v; });  // @151_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[29]);  // @152_5aac30
  ecx = edx = 0;  // @153_5aac30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @154_5aac30
  ecx = ebx;  // @155_5aac30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 966), sizeof v); (u32)v; });  // @156_5aac30
  PV[30] = (u32)(eax);  // @157_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[30]);  // @158_5aac30
  ecx = edx = 0;  // @159_5aac30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @160_5aac30
  ecx = ebx;  // @161_5aac30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 967), sizeof v); (u32)v; });  // @162_5aac30
  PV[31] = (u32)(eax);  // @163_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[31]);  // @164_5aac30
  ecx = edx = 0;  // @165_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @166_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 968) + 0), 4); v; });  // @167_5aac30
  X0[1] = 0;  // @168_5aac30
  X0[2] = 0;  // @169_5aac30
  X0[3] = 0;  // @170_5aac30
  PV[32] = (u32)(ecx);  // @171_5aac30
  ecx = ebx;  // @172_5aac30
  PV[33] = X0[0];  // @173_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[33]);  // @174_5aac30
  ecx = edx = 0;  // @175_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_5aac30
  ecx = ebx;  // @177_5aac30
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 972), sizeof v); (u32)v; });  // @178_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[34]);  // @179_5aac30
  ecx = edx = 0;  // @180_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @181_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 976) + 0), 4); v; });  // @182_5aac30
  X0[1] = 0;  // @183_5aac30
  X0[2] = 0;  // @184_5aac30
  X0[3] = 0;  // @185_5aac30
  PV[35] = (u32)(ecx);  // @186_5aac30
  ecx = ebx;  // @187_5aac30
  PV[36] = X0[0];  // @188_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @189_5aac30
  ecx = edx = 0;  // @190_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @191_5aac30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 884) + 0), 4); v; });  // @192_5aac30
  X0[1] = 0;  // @193_5aac30
  X0[2] = 0;  // @194_5aac30
  X0[3] = 0;  // @195_5aac30
  PV[37] = (u32)(ecx);  // @196_5aac30
  ecx = ebx;  // @197_5aac30
  PV[38] = X0[0];  // @198_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @199_5aac30
  ecx = edx = 0;  // @200_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @201_5aac30
  ecx = ebx;  // @202_5aac30
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 888), sizeof v); (u32)v; });  // @203_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[39]);  // @204_5aac30
  ecx = edx = 0;  // @205_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @206_5aac30
  ecx = ebx;  // @207_5aac30
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 880), sizeof v); (u32)v; });  // @208_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[40]);  // @209_5aac30
  ecx = edx = 0;  // @210_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @211_5aac30
  ecx = ebx;  // @212_5aac30
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 868), sizeof v); (u32)v; });  // @213_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[41]);  // @214_5aac30
  ecx = edx = 0;  // @215_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @216_5aac30
  ecx = ebx;  // @217_5aac30
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 864), sizeof v); (u32)v; });  // @218_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[42]);  // @219_5aac30
  ecx = edx = 0;  // @220_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @221_5aac30
  ecx = ebx;  // @222_5aac30
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 840), sizeof v); (u32)v; });  // @223_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[43]);  // @224_5aac30
  ecx = edx = 0;  // @225_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @226_5aac30
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 844), sizeof v); (u32)v; });  // @227_5aac30
  ecx = ebx;  // @228_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[44]);  // @229_5aac30
  ecx = edx = 0;  // @230_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @231_5aac30
  ecx = ebx;  // @232_5aac30
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 768), sizeof v); (u32)v; });  // @233_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[45]);  // @234_5aac30
  ecx = edx = 0;  // @235_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @236_5aac30
  ecx = ebx;  // @237_5aac30
  PV[46] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2206), sizeof v); (u32)v; });  // @238_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[46]);  // @239_5aac30
  ecx = edx = 0;  // @240_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @241_5aac30
  ecx = ebx;  // @242_5aac30
  PV[47] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2202), sizeof v); (u32)v; });  // @243_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[47]);  // @244_5aac30
  ecx = edx = 0;  // @245_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @246_5aac30
  ecx = ebx;  // @247_5aac30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @248_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @249_5aac30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 129), sizeof v); (u32)v; });  // @250_5aac30
  PV[48] = (u32)(eax);  // @251_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[48]);  // @252_5aac30
  ecx = edx = 0;  // @253_5aac30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @254_5aac30
  eax = (u32)(esi + 24);  // @255_5aac30
  PV[49] = (u32)(eax);  // @256_5aac30
  ecx = ebx;  // @257_5aac30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[49], (u32)(696));  // @258_5aac30
  ecx = edx = 0;  // @259_5aac30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @260_5aac30
  eax = (u32)(esi + 893);  // @261_5aac30
  PV[50] = (u32)(eax);  // @262_5aac30
  ecx = ebx;  // @263_5aac30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[50], (u32)(69));  // @264_5aac30
  ecx = edx = 0;  // @265_5aac30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1625), sizeof v); (u32)v; });  // @266_5aac30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1629), sizeof v); (u32)v; });  // @267_5aac30
  if (FL[0] == FL[1]) goto L5aaeea;  // @268_5aac30
  L5aaed7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @270_5aac30
  PV[51] = (u32)(ebx);  // @271_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @272_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[51]);  // @273_5aac30
  ecx = edx = 0;  // @274_5aac30
  edi = (edi + (u32)(4));  // @275_5aac30
  FL[3] = edi;  // @276_5aac30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1629), sizeof v); (u32)v; });  // @277_5aac30
  if (FL[0] != FL[1]) goto L5aaed7;  // @278_5aac30
  L5aaeea:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1637), sizeof v); (u32)v; });  // @280_5aac30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1641), sizeof v); (u32)v; });  // @281_5aac30
  if (FL[0] == FL[1]) goto L5aaf0b;  // @282_5aac30
  L5aaef8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @284_5aac30
  PV[52] = (u32)(ebx);  // @285_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[52]);  // @287_5aac30
  ecx = edx = 0;  // @288_5aac30
  edi = (edi + (u32)(4));  // @289_5aac30
  FL[3] = edi;  // @290_5aac30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1641), sizeof v); (u32)v; });  // @291_5aac30
  if (FL[0] != FL[1]) goto L5aaef8;  // @292_5aac30
  L5aaf0b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1649), sizeof v); (u32)v; });  // @294_5aac30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1653), sizeof v); (u32)v; });  // @295_5aac30
  if (FL[0] == FL[1]) goto L5aaf33;  // @296_5aac30
  L5aaf20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @298_5aac30
  PV[53] = (u32)(ebx);  // @299_5aac30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @300_5aac30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[53]);  // @301_5aac30
  ecx = edx = 0;  // @302_5aac30
  edi = (edi + (u32)(4));  // @303_5aac30
  FL[3] = edi;  // @304_5aac30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1653), sizeof v); (u32)v; });  // @305_5aac30
  if (FL[0] != FL[1]) goto L5aaf20;  // @306_5aac30
  L5aaf33:;
  PV[54] = (u32)(ebx);  // @308_5aac30
  ecx = (u32)(esi + 1340);  // @309_5aac30
  eax = ext_5aabe0_thiscall2(ecx, PV[54]);  // @310_5aac30
  ecx = edx = 0;  // @311_5aac30
  PV[55] = (u32)(ebx);  // @312_5aac30
  ecx = (u32)(esi + 1354);  // @313_5aac30
  eax = ext_5aabe0_thiscall2(ecx, PV[55]);  // @314_5aac30
  ecx = edx = 0;  // @315_5aac30
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @316_5aac30
  return eax;  // @317_5aac30
}
PCREG(5aac30, lifted_5aac30);

extern "C" u32 STDCALL lifted_5019e0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @1_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_5019e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6791500), (u32)(0));  // @3_5019e0
  ecx = edx = 0;  // @4_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @5_5019e0
  ebx = eax;  // @6_5019e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @7_5019e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @8_5019e0
  ecx = edx = 0;  // @9_5019e0
  esi = eax;  // @10_5019e0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @11_5019e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @12_5019e0
  if (FL[2] == 0) goto L501a27;  // @13_5019e0
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @14_5019e0
  if (FL[0] != FL[1]) goto L501a34;  // @15_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5019e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @18_5019e0
  ecx = edx = 0;  // @19_5019e0
  L501a27:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_5019e0
  ecx = ebx;  // @22_5019e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @23_5019e0
  ecx = edx = 0;  // @24_5019e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @25_5019e0
  { u8 v = (u8)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @26_5019e0
  L501a34:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @28_5019e0
  ecx = ebx;  // @29_5019e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @30_5019e0
  ecx = edx = 0;  // @31_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @32_5019e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @33_5019e0
  ecx = edx = 0;  // @34_5019e0
  esi = eax;  // @35_5019e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @36_5019e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @37_5019e0
  if (FL[2] == 0) goto L501a89;  // @38_5019e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @39_5019e0
  if (FL[0] == FL[1]) goto L501a89;  // @40_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @41_5019e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5019e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @43_5019e0
  ecx = edx = 0;  // @44_5019e0
  PV[0] = (u32)(eax);  // @45_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_5019e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @47_5019e0
  ecx = edx = 0;  // @48_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @49_5019e0
  FL[2] = (eax & eax);  // @50_5019e0
  if (FL[2] == 0) goto L501a88;  // @51_5019e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @52_5019e0
  ecx = edx = 0;  // @53_5019e0
  goto L501a89;  // @54_5019e0
  L501a88:;
  __builtin_trap();  // @56_5019e0
  L501a89:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @58_5019e0
  if (FL[0] == FL[1]) goto L501cae;  // @59_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @60_5019e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @61_5019e0
  ecx = edx = 0;  // @62_5019e0
  esi = eax;  // @63_5019e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @64_5019e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @65_5019e0
  if (FL[2] == 0) goto L501ae0;  // @66_5019e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @67_5019e0
  if (FL[0] == FL[1]) goto L501ae0;  // @68_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @69_5019e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_5019e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @71_5019e0
  ecx = edx = 0;  // @72_5019e0
  PV[1] = (u32)(eax);  // @73_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @74_5019e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6932144), (u32)(6932792));  // @75_5019e0
  ecx = edx = 0;  // @76_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @77_5019e0
  FL[2] = (eax & eax);  // @78_5019e0
  if (FL[2] == 0) goto L501adf;  // @79_5019e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_5019e0
  ecx = edx = 0;  // @81_5019e0
  goto L501ae0;  // @82_5019e0
  L501adf:;
  __builtin_trap();  // @84_5019e0
  L501ae0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @86_5019e0
  if (FL[0] == FL[1]) goto L501cae;  // @87_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @88_5019e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @89_5019e0
  ecx = edx = 0;  // @90_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @91_5019e0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @92_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @93_5019e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[2]);  // @95_5019e0
  ecx = edx = 0;  // @96_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @97_5019e0
  esi = eax;  // @98_5019e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @99_5019e0
  ecx = edx = 0;  // @100_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_5019e0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @102_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @103_5019e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[3]);  // @105_5019e0
  ecx = edx = 0;  // @106_5019e0
  ebx = eax;  // @107_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @108_5019e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }); FL[1] = (u32)(134217754);  // @109_5019e0
  if (FL[0] != FL[1]) goto L501c7d;  // @110_5019e0
  eax = (u32)(EBP - 16);  // @111_5019e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @112_5019e0
  PV[4] = (u32)(eax);  // @113_5019e0
  ecx = esi;  // @114_5019e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @115_5019e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @116_5019e0
  eax = ext_4db670_thiscall2(ecx, PV[4]);  // @117_5019e0
  ecx = edx = 0;  // @118_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @119_5019e0
  FL[2] = (ecx & ecx);  // @120_5019e0
  if (FL[2] == 0) goto L501cae;  // @121_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_5019e0
  edx = (u32)(EBP - 56);  // @123_5019e0
  PV[5] = (u32)(edx);  // @124_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @125_5019e0
  ecx = edx = 0;  // @126_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @127_5019e0
  edx = (u32)(EBP - 56);  // @128_5019e0
  PV[6] = (u32)(edx);  // @129_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @131_5019e0
  ecx = edx = 0;  // @132_5019e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @133_5019e0
  edx = eax;  // @134_5019e0
  if (FL[0] == FL[1]) goto L501cae;  // @135_5019e0
  edi = (u32)(6801640);  // @136_5019e0
  L501b90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_5019e0
  PV[7] = (u32)(edx);  // @139_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @140_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[7]);  // @142_5019e0
  ecx = edx = 0;  // @143_5019e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @144_5019e0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @145_5019e0
  X0[2] = 0;  // @146_5019e0
  X0[3] = 0;  // @147_5019e0
  esi = eax;  // @148_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @149_5019e0
  eax = (u32)(EBP - 28);  // @150_5019e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @151_5019e0
  ecx = esi;  // @152_5019e0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @153_5019e0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @154_5019e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_5019e0
  PV[8] = (u32)(eax);  // @156_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[8]);  // @157_5019e0
  ecx = edx = 0;  // @158_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @159_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @160_5019e0
  FL[0] = eax; FL[1] = (u32)(2097154);  // @161_5019e0
  if (FL[0] == FL[1]) goto L501c06;  // @162_5019e0
  FL[0] = eax; FL[1] = (u32)(2097377);  // @163_5019e0
  if (FL[0] == FL[1]) goto L501c06;  // @164_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @165_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @166_5019e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6933008), (u32)(395));  // @167_5019e0
  ecx = edx = 0;  // @168_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @169_5019e0
  edx = edi;  // @170_5019e0
  FL[2] = (ecx & ecx);  // @171_5019e0
  if (FL[2] != 0) edx = ecx;  // @172_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @173_5019e0
  PV[9] = (u32)(edx);  // @174_5019e0
  PV[10] = (u32)(eax);  // @175_5019e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[10], (u32)(6933136), PV[9]);  // @176_5019e0
  ecx = edx = 0;  // @177_5019e0
  goto L501c2e;  // @178_5019e0
  L501c06:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @180_5019e0
  eax = (u32)(EBP - 40);  // @181_5019e0
  PV[11] = (u32)(eax);  // @182_5019e0
  eax = ext_4db7c0_thiscall2(ecx, PV[11]);  // @183_5019e0
  ecx = edx = 0;  // @184_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @185_5019e0
  PV[12] = (u32)(ecx);  // @186_5019e0
  ecx = (u32)(EBP - 28);  // @187_5019e0
  PV[13] = (u32)(ecx);  // @188_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @189_5019e0
  ecx = esi;  // @190_5019e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[13], (u32)(0));  // @191_5019e0
  ecx = edx = 0;  // @192_5019e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @193_5019e0
  if (FL[2] != 0) goto L501c59;  // @194_5019e0
  L501c2e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @196_5019e0
  edx = (u32)(EBP - 56);  // @197_5019e0
  PV[14] = (u32)(edx);  // @198_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[14]);  // @200_5019e0
  ecx = edx = 0;  // @201_5019e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @202_5019e0
  edx = eax;  // @203_5019e0
  if (FL[0] != FL[1]) goto L501b90;  // @204_5019e0
  ext_633654(G(u32, 0x6f5630));  // @205_5019e0
  return eax;  // @206_5019e0
  L501c59:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @208_5019e0
  FL[2] = (eax & eax);  // @209_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @210_5019e0
  if (FL[2] != 0) edi = eax;  // @211_5019e0
  PV[15] = (u32)(edi);  // @212_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_5019e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[15]);  // @214_5019e0
  ecx = edx = 0;  // @215_5019e0
  ext_633654(G(u32, 0x6f5630));  // @216_5019e0
  return eax;  // @217_5019e0
  L501c7d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @219_5019e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @220_5019e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6933008), (u32)(399));  // @221_5019e0
  ecx = edx = 0;  // @222_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @223_5019e0
  edx = (u32)(6801640);  // @224_5019e0
  FL[2] = (ecx & ecx);  // @225_5019e0
  if (FL[2] != 0) edx = ecx;  // @226_5019e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @227_5019e0
  PV[16] = (u32)(edx);  // @228_5019e0
  PV[17] = (u32)(eax);  // @229_5019e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[17], (u32)(6933136), PV[16]);  // @230_5019e0
  ecx = edx = 0;  // @231_5019e0
  L501cae:;
  ext_633654(G(u32, 0x6f5630));  // @233_5019e0
  return eax;  // @234_5019e0
}
PCREG(5019e0, lifted_5019e0);

extern "C" u32 THISCALL lifted_528c80(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_528c80
  ebx = ecx;  // @1_528c80
  PV[0] = (u32)(ebx);  // @2_528c80
  ecx = esi;  // @3_528c80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[0]);  // @6_528c80
  ecx = edx = 0;  // @7_528c80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_528c80
  eax = (u32)(ebx + 12);  // @9_528c80
  PV[1] = (u32)(eax);  // @10_528c80
  ecx = esi;  // @11_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[1]);  // @12_528c80
  ecx = edx = 0;  // @13_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 48) + 0), 4); v; });  // @15_528c80
  X0[1] = 0;  // @16_528c80
  X0[2] = 0;  // @17_528c80
  X0[3] = 0;  // @18_528c80
  PV[2] = (u32)(ecx);  // @19_528c80
  ecx = esi;  // @20_528c80
  PV[3] = X0[0];  // @21_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @22_528c80
  ecx = edx = 0;  // @23_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 52) + 0), 4); v; });  // @25_528c80
  X0[1] = 0;  // @26_528c80
  X0[2] = 0;  // @27_528c80
  X0[3] = 0;  // @28_528c80
  PV[4] = (u32)(ecx);  // @29_528c80
  ecx = esi;  // @30_528c80
  PV[5] = X0[0];  // @31_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @32_528c80
  ecx = edx = 0;  // @33_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 56) + 0), 4); v; });  // @35_528c80
  X0[1] = 0;  // @36_528c80
  X0[2] = 0;  // @37_528c80
  X0[3] = 0;  // @38_528c80
  PV[6] = (u32)(ecx);  // @39_528c80
  ecx = esi;  // @40_528c80
  PV[7] = X0[0];  // @41_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @42_528c80
  ecx = edx = 0;  // @43_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @44_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 60) + 0), 4); v; });  // @45_528c80
  X0[1] = 0;  // @46_528c80
  X0[2] = 0;  // @47_528c80
  X0[3] = 0;  // @48_528c80
  PV[8] = (u32)(ecx);  // @49_528c80
  ecx = esi;  // @50_528c80
  PV[9] = X0[0];  // @51_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[9]);  // @52_528c80
  ecx = edx = 0;  // @53_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_528c80
  ecx = esi;  // @55_528c80
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; });  // @56_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[10]);  // @57_528c80
  ecx = edx = 0;  // @58_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_528c80
  ecx = esi;  // @60_528c80
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @61_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[11]);  // @62_528c80
  ecx = edx = 0;  // @63_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; });  // @65_528c80
  X0[1] = 0;  // @66_528c80
  X0[2] = 0;  // @67_528c80
  X0[3] = 0;  // @68_528c80
  PV[12] = (u32)(ecx);  // @69_528c80
  ecx = esi;  // @70_528c80
  PV[13] = X0[0];  // @71_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @72_528c80
  ecx = edx = 0;  // @73_528c80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_528c80
  eax = (u32)(ebx + 76);  // @75_528c80
  PV[14] = (u32)(eax);  // @76_528c80
  ecx = esi;  // @77_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[14]);  // @78_528c80
  ecx = edx = 0;  // @79_528c80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_528c80
  eax = (u32)(ebx + 88);  // @81_528c80
  PV[15] = (u32)(eax);  // @82_528c80
  ecx = esi;  // @83_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[15]);  // @84_528c80
  ecx = edx = 0;  // @85_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 100) + 0), 4); v; });  // @87_528c80
  X0[1] = 0;  // @88_528c80
  X0[2] = 0;  // @89_528c80
  X0[3] = 0;  // @90_528c80
  PV[16] = (u32)(ecx);  // @91_528c80
  ecx = esi;  // @92_528c80
  PV[17] = X0[0];  // @93_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @94_528c80
  ecx = edx = 0;  // @95_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 104) + 0), 4); v; });  // @97_528c80
  X0[1] = 0;  // @98_528c80
  X0[2] = 0;  // @99_528c80
  X0[3] = 0;  // @100_528c80
  PV[18] = (u32)(ecx);  // @101_528c80
  ecx = esi;  // @102_528c80
  PV[19] = X0[0];  // @103_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[19]);  // @104_528c80
  ecx = edx = 0;  // @105_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 108) + 0), 4); v; });  // @107_528c80
  X0[1] = 0;  // @108_528c80
  X0[2] = 0;  // @109_528c80
  X0[3] = 0;  // @110_528c80
  PV[20] = (u32)(ecx);  // @111_528c80
  ecx = esi;  // @112_528c80
  PV[21] = X0[0];  // @113_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[21]);  // @114_528c80
  ecx = edx = 0;  // @115_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 112) + 0), 4); v; });  // @117_528c80
  X0[1] = 0;  // @118_528c80
  X0[2] = 0;  // @119_528c80
  X0[3] = 0;  // @120_528c80
  PV[22] = (u32)(ecx);  // @121_528c80
  ecx = esi;  // @122_528c80
  PV[23] = X0[0];  // @123_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[23]);  // @124_528c80
  ecx = edx = 0;  // @125_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 116) + 0), 4); v; });  // @127_528c80
  X0[1] = 0;  // @128_528c80
  X0[2] = 0;  // @129_528c80
  X0[3] = 0;  // @130_528c80
  PV[24] = (u32)(ecx);  // @131_528c80
  ecx = esi;  // @132_528c80
  PV[25] = X0[0];  // @133_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[25]);  // @134_528c80
  ecx = edx = 0;  // @135_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @136_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 120) + 0), 4); v; });  // @137_528c80
  X0[1] = 0;  // @138_528c80
  X0[2] = 0;  // @139_528c80
  X0[3] = 0;  // @140_528c80
  PV[26] = (u32)(ecx);  // @141_528c80
  ecx = esi;  // @142_528c80
  PV[27] = X0[0];  // @143_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @144_528c80
  ecx = edx = 0;  // @145_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_528c80
  ecx = esi;  // @147_528c80
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 137), sizeof v); (u32)v; });  // @148_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[28]);  // @149_528c80
  ecx = edx = 0;  // @150_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_528c80
  ecx = esi;  // @152_528c80
  PV[29] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 141), sizeof v); (u32)v; });  // @153_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[29]);  // @154_528c80
  ecx = edx = 0;  // @155_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_528c80
  ecx = esi;  // @157_528c80
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 145), sizeof v); (u32)v; });  // @158_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[30]);  // @159_528c80
  ecx = edx = 0;  // @160_528c80
  edi = (u32)(ebx + 149);  // @161_528c80
  ebx = (u32)(8);  // @162_528c80
  L528dc4:;
  PV[31] = (u32)(esi);  // @164_528c80
  ecx = edi;  // @165_528c80
  eax = ext_516520_thiscall2(ecx, PV[31]);  // @166_528c80
  ecx = edx = 0;  // @167_528c80
  edi = (edi + (u32)(222));  // @168_528c80
  FL[3] = edi;  // @169_528c80
  ebx = (ebx - (u32)(1));  // @170_528c80
  FL[3] = ebx;  // @171_528c80
  if (FL[3] != 0) goto L528dc4;  // @172_528c80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @173_528c80
  ebx = (u32)(8);  // @174_528c80
  edi = (edi + (u32)(1925));  // @175_528c80
  FL[3] = edi;  // @176_528c80
  L528de5:;
  PV[32] = (u32)(esi);  // @178_528c80
  ecx = edi;  // @179_528c80
  eax = ext_516520_thiscall2(ecx, PV[32]);  // @180_528c80
  ecx = edx = 0;  // @181_528c80
  edi = (edi + (u32)(222));  // @182_528c80
  FL[3] = edi;  // @183_528c80
  ebx = (ebx - (u32)(1));  // @184_528c80
  FL[3] = ebx;  // @185_528c80
  if (FL[3] != 0) goto L528de5;  // @186_528c80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @187_528c80
  ebx = (u32)(8);  // @188_528c80
  edi = (edi + (u32)(3701));  // @189_528c80
  FL[3] = edi;  // @190_528c80
  L528e06:;
  PV[33] = (u32)(esi);  // @192_528c80
  ecx = edi;  // @193_528c80
  eax = ext_529fa0_thiscall2(ecx, PV[33]);  // @194_528c80
  ecx = edx = 0;  // @195_528c80
  edi = (edi + (u32)(307));  // @196_528c80
  FL[3] = edi;  // @197_528c80
  ebx = (ebx - (u32)(1));  // @198_528c80
  FL[3] = ebx;  // @199_528c80
  if (FL[3] != 0) goto L528e06;  // @200_528c80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @201_528c80
  ebx = (u32)(8);  // @202_528c80
  edi = (edi + (u32)(6157));  // @203_528c80
  FL[3] = edi;  // @204_528c80
  L528e27:;
  PV[34] = (u32)(esi);  // @206_528c80
  ecx = edi;  // @207_528c80
  eax = ext_529fa0_thiscall2(ecx, PV[34]);  // @208_528c80
  ecx = edx = 0;  // @209_528c80
  edi = (edi + (u32)(307));  // @210_528c80
  FL[3] = edi;  // @211_528c80
  ebx = (ebx - (u32)(1));  // @212_528c80
  FL[3] = ebx;  // @213_528c80
  if (FL[3] != 0) goto L528e27;  // @214_528c80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @215_528c80
  ecx = esi;  // @216_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @217_528c80
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8613), sizeof v); (u32)v; });  // @218_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[35]);  // @219_528c80
  ecx = edx = 0;  // @220_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_528c80
  ecx = esi;  // @222_528c80
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8617), sizeof v); (u32)v; });  // @223_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[36]);  // @224_528c80
  ecx = edx = 0;  // @225_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @226_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8621) + 0), 4); v; });  // @227_528c80
  X0[1] = 0;  // @228_528c80
  X0[2] = 0;  // @229_528c80
  X0[3] = 0;  // @230_528c80
  PV[37] = (u32)(ecx);  // @231_528c80
  ecx = esi;  // @232_528c80
  PV[38] = X0[0];  // @233_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @234_528c80
  ecx = edx = 0;  // @235_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @236_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8625) + 0), 4); v; });  // @237_528c80
  X0[1] = 0;  // @238_528c80
  X0[2] = 0;  // @239_528c80
  X0[3] = 0;  // @240_528c80
  PV[39] = (u32)(ecx);  // @241_528c80
  ecx = esi;  // @242_528c80
  PV[40] = X0[0];  // @243_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @244_528c80
  ecx = edx = 0;  // @245_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @246_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8629) + 0), 4); v; });  // @247_528c80
  X0[1] = 0;  // @248_528c80
  X0[2] = 0;  // @249_528c80
  X0[3] = 0;  // @250_528c80
  PV[41] = (u32)(ecx);  // @251_528c80
  ecx = esi;  // @252_528c80
  PV[42] = X0[0];  // @253_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[42]);  // @254_528c80
  ecx = edx = 0;  // @255_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @256_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8633) + 0), 4); v; });  // @257_528c80
  X0[1] = 0;  // @258_528c80
  X0[2] = 0;  // @259_528c80
  X0[3] = 0;  // @260_528c80
  PV[43] = (u32)(ecx);  // @261_528c80
  ecx = esi;  // @262_528c80
  PV[44] = X0[0];  // @263_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[44]);  // @264_528c80
  ecx = edx = 0;  // @265_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @266_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8637) + 0), 4); v; });  // @267_528c80
  X0[1] = 0;  // @268_528c80
  X0[2] = 0;  // @269_528c80
  X0[3] = 0;  // @270_528c80
  PV[45] = (u32)(ecx);  // @271_528c80
  ecx = esi;  // @272_528c80
  PV[46] = X0[0];  // @273_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[46]);  // @274_528c80
  ecx = edx = 0;  // @275_528c80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @276_528c80
  eax = (u32)(ebx + 8641);  // @277_528c80
  PV[47] = (u32)(eax);  // @278_528c80
  ecx = esi;  // @279_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[47]);  // @280_528c80
  ecx = edx = 0;  // @281_528c80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @282_528c80
  ecx = esi;  // @283_528c80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8653), sizeof v); (u32)v; });  // @284_528c80
  PV[48] = (u32)(eax);  // @285_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[48]);  // @286_528c80
  ecx = edx = 0;  // @287_528c80
  PV[49] = (u32)(esi);  // @288_528c80
  ecx = (u32)(ebx + 8654);  // @289_528c80
  eax = ext_516e20_thiscall2(ecx, PV[49]);  // @290_528c80
  ecx = edx = 0;  // @291_528c80
  PV[50] = (u32)(esi);  // @292_528c80
  ecx = (u32)(ebx + 8775);  // @293_528c80
  eax = ext_516e20_thiscall2(ecx, PV[50]);  // @294_528c80
  ecx = edx = 0;  // @295_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @296_528c80
  ecx = esi;  // @297_528c80
  PV[51] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8896), sizeof v); (u32)v; });  // @298_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[51]);  // @299_528c80
  ecx = edx = 0;  // @300_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @301_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8900) + 0), 4); v; });  // @302_528c80
  X0[1] = 0;  // @303_528c80
  X0[2] = 0;  // @304_528c80
  X0[3] = 0;  // @305_528c80
  PV[52] = (u32)(ecx);  // @306_528c80
  ecx = esi;  // @307_528c80
  PV[53] = X0[0];  // @308_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[53]);  // @309_528c80
  ecx = edx = 0;  // @310_528c80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @311_528c80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8904) + 0), 4); v; });  // @312_528c80
  X0[1] = 0;  // @313_528c80
  X0[2] = 0;  // @314_528c80
  X0[3] = 0;  // @315_528c80
  PV[54] = (u32)(ecx);  // @316_528c80
  ecx = esi;  // @317_528c80
  PV[55] = X0[0];  // @318_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[55]);  // @319_528c80
  ecx = edx = 0;  // @320_528c80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @321_528c80
  ecx = esi;  // @322_528c80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 132), sizeof v); (u32)v; });  // @323_528c80
  PV[56] = (u32)(eax);  // @324_528c80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[56]);  // @325_528c80
  ecx = edx = 0;  // @326_528c80
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @327_528c80
  return eax;  // @328_528c80
}
PCREG(528c80, lifted_528c80);

extern "C" u32 THISCALL lifted_526090(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[65], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_526090
  ebx = ecx;  // @1_526090
  PV[0] = (u32)(ebx);  // @2_526090
  ecx = esi;  // @3_526090
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[0]);  // @6_526090
  ecx = edx = 0;  // @7_526090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_526090
  eax = (u32)(ebx + 12);  // @9_526090
  PV[1] = (u32)(eax);  // @10_526090
  ecx = esi;  // @11_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[1]);  // @12_526090
  ecx = edx = 0;  // @13_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 48) + 0), 4); v; });  // @15_526090
  X0[1] = 0;  // @16_526090
  X0[2] = 0;  // @17_526090
  X0[3] = 0;  // @18_526090
  PV[2] = (u32)(ecx);  // @19_526090
  ecx = esi;  // @20_526090
  PV[3] = X0[0];  // @21_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @22_526090
  ecx = edx = 0;  // @23_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 52) + 0), 4); v; });  // @25_526090
  X0[1] = 0;  // @26_526090
  X0[2] = 0;  // @27_526090
  X0[3] = 0;  // @28_526090
  PV[4] = (u32)(ecx);  // @29_526090
  ecx = esi;  // @30_526090
  PV[5] = X0[0];  // @31_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @32_526090
  ecx = edx = 0;  // @33_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 56) + 0), 4); v; });  // @35_526090
  X0[1] = 0;  // @36_526090
  X0[2] = 0;  // @37_526090
  X0[3] = 0;  // @38_526090
  PV[6] = (u32)(ecx);  // @39_526090
  ecx = esi;  // @40_526090
  PV[7] = X0[0];  // @41_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @42_526090
  ecx = edx = 0;  // @43_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @44_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 60) + 0), 4); v; });  // @45_526090
  X0[1] = 0;  // @46_526090
  X0[2] = 0;  // @47_526090
  X0[3] = 0;  // @48_526090
  PV[8] = (u32)(ecx);  // @49_526090
  ecx = esi;  // @50_526090
  PV[9] = X0[0];  // @51_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[9]);  // @52_526090
  ecx = edx = 0;  // @53_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_526090
  ecx = esi;  // @55_526090
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; });  // @56_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[10]);  // @57_526090
  ecx = edx = 0;  // @58_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_526090
  ecx = esi;  // @60_526090
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @61_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[11]);  // @62_526090
  ecx = edx = 0;  // @63_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 72) + 0), 4); v; });  // @65_526090
  X0[1] = 0;  // @66_526090
  X0[2] = 0;  // @67_526090
  X0[3] = 0;  // @68_526090
  PV[12] = (u32)(ecx);  // @69_526090
  ecx = esi;  // @70_526090
  PV[13] = X0[0];  // @71_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @72_526090
  ecx = edx = 0;  // @73_526090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_526090
  eax = (u32)(ebx + 76);  // @75_526090
  PV[14] = (u32)(eax);  // @76_526090
  ecx = esi;  // @77_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[14]);  // @78_526090
  ecx = edx = 0;  // @79_526090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_526090
  eax = (u32)(ebx + 88);  // @81_526090
  PV[15] = (u32)(eax);  // @82_526090
  ecx = esi;  // @83_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[15]);  // @84_526090
  ecx = edx = 0;  // @85_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 100) + 0), 4); v; });  // @87_526090
  X0[1] = 0;  // @88_526090
  X0[2] = 0;  // @89_526090
  X0[3] = 0;  // @90_526090
  PV[16] = (u32)(ecx);  // @91_526090
  ecx = esi;  // @92_526090
  PV[17] = X0[0];  // @93_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @94_526090
  ecx = edx = 0;  // @95_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 104) + 0), 4); v; });  // @97_526090
  X0[1] = 0;  // @98_526090
  X0[2] = 0;  // @99_526090
  X0[3] = 0;  // @100_526090
  PV[18] = (u32)(ecx);  // @101_526090
  ecx = esi;  // @102_526090
  PV[19] = X0[0];  // @103_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[19]);  // @104_526090
  ecx = edx = 0;  // @105_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 108) + 0), 4); v; });  // @107_526090
  X0[1] = 0;  // @108_526090
  X0[2] = 0;  // @109_526090
  X0[3] = 0;  // @110_526090
  PV[20] = (u32)(ecx);  // @111_526090
  ecx = esi;  // @112_526090
  PV[21] = X0[0];  // @113_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[21]);  // @114_526090
  ecx = edx = 0;  // @115_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 112) + 0), 4); v; });  // @117_526090
  X0[1] = 0;  // @118_526090
  X0[2] = 0;  // @119_526090
  X0[3] = 0;  // @120_526090
  PV[22] = (u32)(ecx);  // @121_526090
  ecx = esi;  // @122_526090
  PV[23] = X0[0];  // @123_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[23]);  // @124_526090
  ecx = edx = 0;  // @125_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 116) + 0), 4); v; });  // @127_526090
  X0[1] = 0;  // @128_526090
  X0[2] = 0;  // @129_526090
  X0[3] = 0;  // @130_526090
  PV[24] = (u32)(ecx);  // @131_526090
  ecx = esi;  // @132_526090
  PV[25] = X0[0];  // @133_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[25]);  // @134_526090
  ecx = edx = 0;  // @135_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @136_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 120) + 0), 4); v; });  // @137_526090
  X0[1] = 0;  // @138_526090
  X0[2] = 0;  // @139_526090
  X0[3] = 0;  // @140_526090
  PV[26] = (u32)(ecx);  // @141_526090
  ecx = esi;  // @142_526090
  PV[27] = X0[0];  // @143_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @144_526090
  ecx = edx = 0;  // @145_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 124) + 0), 4); v; });  // @147_526090
  X0[1] = 0;  // @148_526090
  X0[2] = 0;  // @149_526090
  X0[3] = 0;  // @150_526090
  PV[28] = (u32)(ecx);  // @151_526090
  ecx = esi;  // @152_526090
  PV[29] = X0[0];  // @153_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[29]);  // @154_526090
  ecx = edx = 0;  // @155_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 128) + 0), 4); v; });  // @157_526090
  X0[1] = 0;  // @158_526090
  X0[2] = 0;  // @159_526090
  X0[3] = 0;  // @160_526090
  PV[30] = (u32)(ecx);  // @161_526090
  ecx = esi;  // @162_526090
  PV[31] = X0[0];  // @163_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[31]);  // @164_526090
  ecx = edx = 0;  // @165_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @166_526090
  ecx = esi;  // @167_526090
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 136), sizeof v); (u32)v; });  // @168_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[32]);  // @169_526090
  ecx = edx = 0;  // @170_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @171_526090
  ecx = esi;  // @172_526090
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; });  // @173_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[33]);  // @174_526090
  ecx = edx = 0;  // @175_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_526090
  ecx = esi;  // @177_526090
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @178_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[34]);  // @179_526090
  ecx = edx = 0;  // @180_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @181_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 148) + 0), 4); v; });  // @182_526090
  X0[1] = 0;  // @183_526090
  X0[2] = 0;  // @184_526090
  X0[3] = 0;  // @185_526090
  PV[35] = (u32)(ecx);  // @186_526090
  ecx = esi;  // @187_526090
  PV[36] = X0[0];  // @188_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @189_526090
  ecx = edx = 0;  // @190_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @191_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 152) + 0), 4); v; });  // @192_526090
  X0[1] = 0;  // @193_526090
  X0[2] = 0;  // @194_526090
  X0[3] = 0;  // @195_526090
  PV[37] = (u32)(ecx);  // @196_526090
  ecx = esi;  // @197_526090
  PV[38] = X0[0];  // @198_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @199_526090
  ecx = edx = 0;  // @200_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @201_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 156) + 0), 4); v; });  // @202_526090
  X0[1] = 0;  // @203_526090
  X0[2] = 0;  // @204_526090
  X0[3] = 0;  // @205_526090
  PV[39] = (u32)(ecx);  // @206_526090
  ecx = esi;  // @207_526090
  PV[40] = X0[0];  // @208_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @209_526090
  ecx = edx = 0;  // @210_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @211_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 160) + 0), 4); v; });  // @212_526090
  X0[1] = 0;  // @213_526090
  X0[2] = 0;  // @214_526090
  X0[3] = 0;  // @215_526090
  PV[41] = (u32)(ecx);  // @216_526090
  ecx = esi;  // @217_526090
  PV[42] = X0[0];  // @218_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[42]);  // @219_526090
  ecx = edx = 0;  // @220_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 164) + 0), 4); v; });  // @222_526090
  X0[1] = 0;  // @223_526090
  X0[2] = 0;  // @224_526090
  X0[3] = 0;  // @225_526090
  PV[43] = (u32)(ecx);  // @226_526090
  ecx = esi;  // @227_526090
  PV[44] = X0[0];  // @228_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[44]);  // @229_526090
  ecx = edx = 0;  // @230_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @231_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 168) + 0), 4); v; });  // @232_526090
  X0[1] = 0;  // @233_526090
  X0[2] = 0;  // @234_526090
  X0[3] = 0;  // @235_526090
  PV[45] = (u32)(ecx);  // @236_526090
  ecx = esi;  // @237_526090
  PV[46] = X0[0];  // @238_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[46]);  // @239_526090
  ecx = edx = 0;  // @240_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @241_526090
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 172) + 0), 4); v; });  // @242_526090
  X0[1] = 0;  // @243_526090
  X0[2] = 0;  // @244_526090
  X0[3] = 0;  // @245_526090
  PV[47] = (u32)(ecx);  // @246_526090
  ecx = esi;  // @247_526090
  PV[48] = X0[0];  // @248_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[48]);  // @249_526090
  ecx = edx = 0;  // @250_526090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @251_526090
  eax = (u32)(ebx + 176);  // @252_526090
  PV[49] = (u32)(eax);  // @253_526090
  ecx = esi;  // @254_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[49]);  // @255_526090
  ecx = edx = 0;  // @256_526090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @257_526090
  ecx = esi;  // @258_526090
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 188), sizeof v); (u32)v; });  // @259_526090
  PV[50] = (u32)(eax);  // @260_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[50]);  // @261_526090
  ecx = edx = 0;  // @262_526090
  edi = (u32)(ebx + 189);  // @263_526090
  ebx = (u32)(4);  // @264_526090
  L5262b0:;
  PV[51] = (u32)(esi);  // @266_526090
  ecx = edi;  // @267_526090
  eax = ext_516520_thiscall2(ecx, PV[51]);  // @268_526090
  ecx = edx = 0;  // @269_526090
  edi = (edi + (u32)(222));  // @270_526090
  FL[3] = edi;  // @271_526090
  ebx = (ebx - (u32)(1));  // @272_526090
  FL[3] = ebx;  // @273_526090
  if (FL[3] != 0) goto L5262b0;  // @274_526090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @275_526090
  ebx = (u32)(4);  // @276_526090
  edi = (edi + (u32)(1077));  // @277_526090
  FL[3] = edi;  // @278_526090
  L5262d1:;
  PV[52] = (u32)(esi);  // @280_526090
  ecx = edi;  // @281_526090
  eax = ext_516520_thiscall2(ecx, PV[52]);  // @282_526090
  ecx = edx = 0;  // @283_526090
  edi = (edi + (u32)(222));  // @284_526090
  FL[3] = edi;  // @285_526090
  ebx = (ebx - (u32)(1));  // @286_526090
  FL[3] = ebx;  // @287_526090
  if (FL[3] != 0) goto L5262d1;  // @288_526090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @289_526090
  ebx = (u32)(4);  // @290_526090
  edi = (edi + (u32)(1965));  // @291_526090
  FL[3] = edi;  // @292_526090
  L5262f2:;
  PV[53] = (u32)(esi);  // @294_526090
  ecx = edi;  // @295_526090
  eax = ext_529f40_thiscall2(ecx, PV[53]);  // @296_526090
  ecx = edx = 0;  // @297_526090
  edi = (edi + (u32)(355));  // @298_526090
  FL[3] = edi;  // @299_526090
  ebx = (ebx - (u32)(1));  // @300_526090
  FL[3] = ebx;  // @301_526090
  if (FL[3] != 0) goto L5262f2;  // @302_526090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @303_526090
  ebx = (u32)(4);  // @304_526090
  edi = (edi + (u32)(3385));  // @305_526090
  FL[3] = edi;  // @306_526090
  L526313:;
  PV[54] = (u32)(esi);  // @308_526090
  ecx = edi;  // @309_526090
  eax = ext_529fa0_thiscall2(ecx, PV[54]);  // @310_526090
  ecx = edx = 0;  // @311_526090
  edi = (edi + (u32)(307));  // @312_526090
  FL[3] = edi;  // @313_526090
  ebx = (ebx - (u32)(1));  // @314_526090
  FL[3] = ebx;  // @315_526090
  if (FL[3] != 0) goto L526313;  // @316_526090
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @317_526090
  PV[55] = (u32)(esi);  // @318_526090
  ecx = (u32)(ebx + 4613);  // @319_526090
  eax = ext_516e20_thiscall2(ecx, PV[55]);  // @320_526090
  ecx = edx = 0;  // @321_526090
  PV[56] = (u32)(esi);  // @322_526090
  ecx = (u32)(ebx + 4734);  // @323_526090
  eax = ext_516e20_thiscall2(ecx, PV[56]);  // @324_526090
  ecx = edx = 0;  // @325_526090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_526090
  ecx = esi;  // @327_526090
  PV[57] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4855), sizeof v); (u32)v; });  // @328_526090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[57]);  // @329_526090
  ecx = edx = 0;  // @330_526090
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @331_526090
  return eax;  // @332_526090
}
PCREG(526090, lifted_526090);

extern "C" u32 THISCALL lifted_4464e0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4464e0
  ebx = ecx;  // @1_4464e0
  PV[0] = (u32)(edi);  // @2_4464e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4464e0
  eax = ext_45f960_thiscall2(ecx, PV[0]);  // @4_4464e0
  ecx = edx = 0;  // @5_4464e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_4464e0
  if (FL[2] != 0) goto L446500;  // @7_4464e0
  return eax;  // @8_4464e0
  L446500:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_4464e0
  ecx = edi;  // @11_4464e0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 44), sizeof v); (u32)v; });  // @12_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[1]);  // @13_4464e0
  ecx = edx = 0;  // @14_4464e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 44), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @15_4464e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @16_4464e0
  if ((s32)FL[0] <= (s32)FL[1]) goto L446551;  // @17_4464e0
  ebx = (ebx + (u32)(36));  // @18_4464e0
  FL[3] = ebx;  // @19_4464e0
  L446520:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4464e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_4464e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4464e0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @26_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[2]);  // @27_4464e0
  ecx = edx = 0;  // @28_4464e0
  PV[3] = (u32)(eax);  // @29_4464e0
  ecx = edi;  // @30_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 60)))(ecx, PV[3]);  // @31_4464e0
  ecx = edx = 0;  // @32_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_4464e0
  ebx = (u32)(ebx + 4);  // @34_4464e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @35_4464e0
  eax = (eax + 1);  // @36_4464e0
  FL[3] = eax;  // @37_4464e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @38_4464e0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @39_4464e0
  if ((s32)FL[0] < (s32)FL[1]) goto L446520;  // @40_4464e0
  ebx = ecx;  // @41_4464e0
  L446551:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4464e0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @44_4464e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_4464e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @48_4464e0
  ecx = edx = 0;  // @49_4464e0
  PV[5] = (u32)(eax);  // @50_4464e0
  ecx = edi;  // @51_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 60)))(ecx, PV[5]);  // @52_4464e0
  ecx = edx = 0;  // @53_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_4464e0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 402), sizeof v); (u32)v; });  // @55_4464e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_4464e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @57_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @59_4464e0
  ecx = edx = 0;  // @60_4464e0
  PV[7] = (u32)(eax);  // @61_4464e0
  ecx = edi;  // @62_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 60)))(ecx, PV[7]);  // @63_4464e0
  ecx = edx = 0;  // @64_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_4464e0
  ecx = edi;  // @66_4464e0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @67_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[8]);  // @68_4464e0
  ecx = edx = 0;  // @69_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_4464e0
  ecx = edi;  // @71_4464e0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; });  // @72_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[9]);  // @73_4464e0
  ecx = edx = 0;  // @74_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_4464e0
  ecx = edi;  // @76_4464e0
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 52), sizeof v); (u32)v; });  // @77_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[10]);  // @78_4464e0
  ecx = edx = 0;  // @79_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 56) + 0), 4); v; });  // @81_4464e0
  X0[1] = 0;  // @82_4464e0
  X0[2] = 0;  // @83_4464e0
  X0[3] = 0;  // @84_4464e0
  PV[11] = (u32)(ecx);  // @85_4464e0
  ecx = edi;  // @86_4464e0
  PV[12] = X0[0];  // @87_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @88_4464e0
  ecx = edx = 0;  // @89_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @90_4464e0
  eax = (u32)(ebx + 60);  // @91_4464e0
  PV[13] = (u32)(eax);  // @92_4464e0
  ecx = edi;  // @93_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[13]);  // @94_4464e0
  ecx = edx = 0;  // @95_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @96_4464e0
  ecx = edi;  // @97_4464e0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @98_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[14]);  // @99_4464e0
  ecx = edx = 0;  // @100_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @101_4464e0
  ecx = edi;  // @102_4464e0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; });  // @103_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[15]);  // @104_4464e0
  ecx = edx = 0;  // @105_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @106_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 80) + 0), 4); v; });  // @107_4464e0
  X0[1] = 0;  // @108_4464e0
  X0[2] = 0;  // @109_4464e0
  X0[3] = 0;  // @110_4464e0
  PV[16] = (u32)(ecx);  // @111_4464e0
  ecx = edi;  // @112_4464e0
  PV[17] = X0[0];  // @113_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[17]);  // @114_4464e0
  ecx = edx = 0;  // @115_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @116_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 84) + 0), 4); v; });  // @117_4464e0
  X0[1] = 0;  // @118_4464e0
  X0[2] = 0;  // @119_4464e0
  X0[3] = 0;  // @120_4464e0
  PV[18] = (u32)(ecx);  // @121_4464e0
  ecx = edi;  // @122_4464e0
  PV[19] = X0[0];  // @123_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[19]);  // @124_4464e0
  ecx = edx = 0;  // @125_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @126_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 88) + 0), 4); v; });  // @127_4464e0
  X0[1] = 0;  // @128_4464e0
  X0[2] = 0;  // @129_4464e0
  X0[3] = 0;  // @130_4464e0
  PV[20] = (u32)(ecx);  // @131_4464e0
  ecx = edi;  // @132_4464e0
  PV[21] = X0[0];  // @133_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[21]);  // @134_4464e0
  ecx = edx = 0;  // @135_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @136_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 92) + 0), 4); v; });  // @137_4464e0
  X0[1] = 0;  // @138_4464e0
  X0[2] = 0;  // @139_4464e0
  X0[3] = 0;  // @140_4464e0
  PV[22] = (u32)(ecx);  // @141_4464e0
  ecx = edi;  // @142_4464e0
  PV[23] = X0[0];  // @143_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[23]);  // @144_4464e0
  ecx = edx = 0;  // @145_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @146_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 96) + 0), 4); v; });  // @147_4464e0
  X0[1] = 0;  // @148_4464e0
  X0[2] = 0;  // @149_4464e0
  X0[3] = 0;  // @150_4464e0
  PV[24] = (u32)(ecx);  // @151_4464e0
  ecx = edi;  // @152_4464e0
  PV[25] = X0[0];  // @153_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[25]);  // @154_4464e0
  ecx = edx = 0;  // @155_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @156_4464e0
  PV[26] = (u32)(ecx);  // @157_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 100) + 0), 4); v; });  // @158_4464e0
  X0[1] = 0;  // @159_4464e0
  X0[2] = 0;  // @160_4464e0
  X0[3] = 0;  // @161_4464e0
  ecx = edi;  // @162_4464e0
  PV[27] = X0[0];  // @163_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @164_4464e0
  ecx = edx = 0;  // @165_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 104) + 0), 4); v; });  // @167_4464e0
  X0[1] = 0;  // @168_4464e0
  X0[2] = 0;  // @169_4464e0
  X0[3] = 0;  // @170_4464e0
  PV[28] = (u32)(ecx);  // @171_4464e0
  ecx = edi;  // @172_4464e0
  PV[29] = X0[0];  // @173_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[29]);  // @174_4464e0
  ecx = edx = 0;  // @175_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @176_4464e0
  ecx = edi;  // @177_4464e0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @178_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[30]);  // @179_4464e0
  ecx = edx = 0;  // @180_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @181_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 112) + 0), 4); v; });  // @182_4464e0
  X0[1] = 0;  // @183_4464e0
  X0[2] = 0;  // @184_4464e0
  X0[3] = 0;  // @185_4464e0
  PV[31] = (u32)(ecx);  // @186_4464e0
  ecx = edi;  // @187_4464e0
  PV[32] = X0[0];  // @188_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[32]);  // @189_4464e0
  ecx = edx = 0;  // @190_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @191_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 116) + 0), 4); v; });  // @192_4464e0
  X0[1] = 0;  // @193_4464e0
  X0[2] = 0;  // @194_4464e0
  X0[3] = 0;  // @195_4464e0
  PV[33] = (u32)(ecx);  // @196_4464e0
  ecx = edi;  // @197_4464e0
  PV[34] = X0[0];  // @198_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @199_4464e0
  ecx = edx = 0;  // @200_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @201_4464e0
  ecx = edi;  // @202_4464e0
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 120), sizeof v); (u32)v; });  // @203_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[35]);  // @204_4464e0
  ecx = edx = 0;  // @205_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @206_4464e0
  eax = (u32)(ebx + 124);  // @207_4464e0
  PV[36] = (u32)(eax);  // @208_4464e0
  ecx = edi;  // @209_4464e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[36], (u32)(52));  // @210_4464e0
  ecx = edx = 0;  // @211_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @212_4464e0
  eax = (u32)(ebx + 176);  // @213_4464e0
  PV[37] = (u32)(eax);  // @214_4464e0
  ecx = edi;  // @215_4464e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[37], (u32)(192));  // @216_4464e0
  ecx = edx = 0;  // @217_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @218_4464e0
  ecx = edi;  // @219_4464e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; });  // @220_4464e0
  PV[38] = (u32)(eax);  // @221_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[38]);  // @222_4464e0
  ecx = edx = 0;  // @223_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @224_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 369) + 0), 4); v; });  // @225_4464e0
  X0[1] = 0;  // @226_4464e0
  X0[2] = 0;  // @227_4464e0
  X0[3] = 0;  // @228_4464e0
  PV[39] = (u32)(ecx);  // @229_4464e0
  ecx = edi;  // @230_4464e0
  PV[40] = X0[0];  // @231_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @232_4464e0
  ecx = edx = 0;  // @233_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @234_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 373) + 0), 4); v; });  // @235_4464e0
  X0[1] = 0;  // @236_4464e0
  X0[2] = 0;  // @237_4464e0
  X0[3] = 0;  // @238_4464e0
  PV[41] = (u32)(ecx);  // @239_4464e0
  ecx = edi;  // @240_4464e0
  PV[42] = X0[0];  // @241_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[42]);  // @242_4464e0
  ecx = edx = 0;  // @243_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @244_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 377) + 0), 4); v; });  // @245_4464e0
  X0[1] = 0;  // @246_4464e0
  X0[2] = 0;  // @247_4464e0
  X0[3] = 0;  // @248_4464e0
  PV[43] = (u32)(ecx);  // @249_4464e0
  ecx = edi;  // @250_4464e0
  PV[44] = X0[0];  // @251_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[44]);  // @252_4464e0
  ecx = edx = 0;  // @253_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @254_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 381) + 0), 4); v; });  // @255_4464e0
  X0[1] = 0;  // @256_4464e0
  X0[2] = 0;  // @257_4464e0
  X0[3] = 0;  // @258_4464e0
  PV[45] = (u32)(ecx);  // @259_4464e0
  ecx = edi;  // @260_4464e0
  PV[46] = X0[0];  // @261_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[46]);  // @262_4464e0
  ecx = edx = 0;  // @263_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @264_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 385) + 0), 4); v; });  // @265_4464e0
  X0[1] = 0;  // @266_4464e0
  X0[2] = 0;  // @267_4464e0
  X0[3] = 0;  // @268_4464e0
  PV[47] = (u32)(ecx);  // @269_4464e0
  ecx = edi;  // @270_4464e0
  PV[48] = X0[0];  // @271_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[48]);  // @272_4464e0
  ecx = edx = 0;  // @273_4464e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 389) + 0), 4); v; });  // @274_4464e0
  X0[1] = 0;  // @275_4464e0
  X0[2] = 0;  // @276_4464e0
  X0[3] = 0;  // @277_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @278_4464e0
  PV[49] = (u32)(ecx);  // @279_4464e0
  PV[50] = X0[0];  // @280_4464e0
  ecx = edi;  // @281_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[50]);  // @282_4464e0
  ecx = edx = 0;  // @283_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @284_4464e0
  ecx = edi;  // @285_4464e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 397), sizeof v); (u32)v; });  // @286_4464e0
  PV[51] = (u32)(eax);  // @287_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[51]);  // @288_4464e0
  ecx = edx = 0;  // @289_4464e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @290_4464e0
  ecx = edi;  // @291_4464e0
  PV[52] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 398), sizeof v); (u32)v; });  // @292_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[52]);  // @293_4464e0
  ecx = edx = 0;  // @294_4464e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @295_4464e0
  ecx = edi;  // @296_4464e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 406), sizeof v); (u32)v; });  // @297_4464e0
  PV[53] = (u32)(eax);  // @298_4464e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[53]);  // @299_4464e0
  ecx = edx = 0;  // @300_4464e0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @301_4464e0
  return eax;  // @302_4464e0
}
PCREG(4464e0, lifted_4464e0);

extern "C" u32 STDCALL lifted_5618b0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_5618b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5618b0
  esi = 0;  // @2_5618b0
  FL[3] = esi;  // @3_5618b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @4_5618b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @5_5618b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @6_5618b0
  FL[2] = (ebx & ebx);  // @7_5618b0
  if (FL[2] == 0) goto L561b58;  // @8_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_5618b0
  ecx = ebx;  // @10_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @11_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048622));  // @12_5618b0
  ecx = edx = 0;  // @13_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @14_5618b0
  if (FL[2] == 0) goto L56191e;  // @15_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_5618b0
  ecx = ebx;  // @17_5618b0
  PV[0] = (u32)(esi);  // @18_5618b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6972848), PV[0]);  // @19_5618b0
  ecx = edx = 0;  // @20_5618b0
  esi = eax;  // @21_5618b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @22_5618b0
  FL[2] = (esi & esi);  // @23_5618b0
  if (FL[2] != 0) goto L56191e;  // @24_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_5618b0
  ecx = ebx;  // @26_5618b0
  PV[1] = (u32)(esi);  // @27_5618b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6923868), PV[1]);  // @28_5618b0
  ecx = edx = 0;  // @29_5618b0
  esi = eax;  // @30_5618b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @31_5618b0
  L56191e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @33_5618b0
  ecx = ebx;  // @34_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @35_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097197));  // @36_5618b0
  ecx = edx = 0;  // @37_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @38_5618b0
  if (FL[2] != 0) goto L561948;  // @39_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @40_5618b0
  ecx = ebx;  // @41_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @42_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097208));  // @43_5618b0
  ecx = edx = 0;  // @44_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @45_5618b0
  if (FL[2] == 0) goto L56194d;  // @46_5618b0
  L561948:;
  esi = ebx;  // @48_5618b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @49_5618b0
  L56194d:;
  FL[2] = (esi & esi);  // @51_5618b0
  if (FL[2] == 0) goto L561b58;  // @52_5618b0
  eax = 0;  // @53_5618b0
  FL[3] = eax;  // @54_5618b0
  ecx = esi;  // @55_5618b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @56_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @58_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097208));  // @59_5618b0
  ecx = edx = 0;  // @60_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @61_5618b0
  if (FL[2] != 0) goto L561989;  // @62_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_5618b0
  ecx = esi;  // @64_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @65_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097197));  // @66_5618b0
  ecx = edx = 0;  // @67_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @68_5618b0
  if (FL[2] == 0) goto L561b26;  // @69_5618b0
  L561989:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 151), sizeof v); (u32)v; });  // @71_5618b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @72_5618b0
  FL[2] = (ecx & ecx);  // @73_5618b0
  if (FL[2] == 0) goto L561b26;  // @74_5618b0
  edi = ecx;  // @75_5618b0
  edx = (u32)(edi + 1);  // @76_5618b0
  L5619a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @78_5618b0
  edi = (edi + 1);  // @79_5618b0
  FL[3] = edi;  // @80_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @81_5618b0
  if (FL[2] != 0) goto L5619a0;  // @82_5618b0
  edi = (edi - edx);  // @83_5618b0
  FL[3] = edi;  // @84_5618b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @85_5618b0
  ebx = 0;  // @86_5618b0
  FL[3] = ebx;  // @87_5618b0
  goto L5619b7;  // @88_5618b0
  L5619b4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @90_5618b0
  L5619b7:;
  FL[0] = ebx; FL[1] = edi;  // @92_5618b0
  if (FL[0] == FL[1]) goto L5619c4;  // @93_5618b0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @94_5618b0
  eax = (u32)(ebx + 1);  // @95_5618b0
  if (FL[0] != FL[1]) goto L5619f8;  // @96_5618b0
  L5619c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_5618b0
  ecx = esi;  // @99_5618b0
  PV[2] = (u32)(ebx);  // @100_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, PV[2]);  // @101_5618b0
  ecx = edx = 0;  // @102_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @103_5618b0
  esi = eax;  // @104_5618b0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @105_5618b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 656)))(ecx, PV[3]);  // @107_5618b0
  ecx = edx = 0;  // @108_5618b0
  esi = (esi - eax);  // @109_5618b0
  FL[3] = esi;  // @110_5618b0
  eax = (u32)(ebx + 1);  // @111_5618b0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @112_5618b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @113_5618b0
  if ((s32)FL[0] <= (s32)FL[1]) esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @114_5618b0
  ecx = esi;  // @115_5618b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @116_5618b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @117_5618b0
  goto L5619fb;  // @118_5618b0
  L5619f8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @120_5618b0
  L5619fb:;
  ebx = eax;  // @122_5618b0
  FL[0] = ebx; FL[1] = edi;  // @123_5618b0
  if (FL[0] <= FL[1]) goto L5619b4;  // @124_5618b0
  FL[2] = (ecx & ecx);  // @125_5618b0
  if (FL[2] == 0) goto L561b23;  // @126_5618b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @127_5618b0
  FL[2] = (ebx & ebx);  // @128_5618b0
  if (FL[2] == 0) goto L561b57;  // @129_5618b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @130_5618b0
  eax = (u32)(EBP - 40);  // @131_5618b0
  PV[4] = (u32)(eax);  // @132_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @133_5618b0
  eax = ext_4db500_thiscall2(ecx, PV[4]);  // @134_5618b0
  ecx = edx = 0;  // @135_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @136_5618b0
  eax = (u32)(EBP - 52);  // @137_5618b0
  PV[5] = (u32)(eax);  // @138_5618b0
  eax = ext_4db500_thiscall2(ecx, PV[5]);  // @139_5618b0
  ecx = edx = 0;  // @140_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @141_5618b0
  FL[0] = edi; FL[1] = esi;  // @142_5618b0
  if (FL[0] == FL[1]) goto L561a4d;  // @143_5618b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @144_5618b0
  X1[1] = 0;  // @145_5618b0
  X1[2] = 0;  // @146_5618b0
  X1[3] = 0;  // @147_5618b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; })));  // @148_5618b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @149_5618b0
  X0[0] = F2U((float)(s32)X0[0]);  // @150_5618b0
  X0[1] = F2U((float)(s32)X0[1]);  // @151_5618b0
  X0[2] = F2U((float)(s32)X0[2]);  // @152_5618b0
  X0[3] = F2U((float)(s32)X0[3]);  // @153_5618b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @154_5618b0
  goto L561a59;  // @155_5618b0
  L561a4d:;
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @157_5618b0
  X1[0] = F2U((float)(s32)X1[0]);  // @158_5618b0
  X1[1] = F2U((float)(s32)X1[1]);  // @159_5618b0
  X1[2] = F2U((float)(s32)X1[2]);  // @160_5618b0
  X1[3] = F2U((float)(s32)X1[3]);  // @161_5618b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @162_5618b0
  L561a59:;
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @164_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @165_5618b0
  eax = (u32)(EBP - 16);  // @166_5618b0
  PV[6] = (u32)(eax);  // @167_5618b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X1[0], 4);  // @168_5618b0
  eax = ext_4db500_thiscall2(ecx, PV[6]);  // @169_5618b0
  ecx = edx = 0;  // @170_5618b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @171_5618b0
  X0[1] = 0;  // @172_5618b0
  X0[2] = 0;  // @173_5618b0
  X0[3] = 0;  // @174_5618b0
  ecx = (u32)(EBP - 16);  // @175_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_5618b0
  X1[0] = X0[0];  // @177_5618b0
  X1[1] = X0[1];  // @178_5618b0
  X1[2] = X0[2];  // @179_5618b0
  X1[3] = X0[3];  // @180_5618b0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @181_5618b0
  PV[7] = (u32)(ecx);  // @182_5618b0
  ecx = ebx;  // @183_5618b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @184_5618b0
  __builtin_memcpy((void *)((u32)(EBP - 64) + 0), &X1[0], 4);  // @185_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[7]);  // @186_5618b0
  ecx = edx = 0;  // @187_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @188_5618b0
  ecx = ebx;  // @189_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @190_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1048622));  // @191_5618b0
  ecx = edx = 0;  // @192_5618b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @193_5618b0
  if (FL[2] == 0) goto L561b57;  // @194_5618b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @195_5618b0
  L561ab0:;
  FL[2] = (edi & edi);  // @197_5618b0
  if (FL[2] == 0) goto L561b57;  // @198_5618b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @199_5618b0
  FL[2] = (esi & esi);  // @200_5618b0
  if (FL[2] == 0) goto L561ac7;  // @201_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @202_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @203_5618b0
  goto L561acc;  // @204_5618b0
  L561ac7:;
  eax = (u32)(2097154);  // @206_5618b0
  L561acc:;
  FL[2] = (eax & (u32)(1048576));  // @208_5618b0
  if (FL[2] != 0) goto L561b57;  // @209_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @210_5618b0
  ecx = (u32)(6801640);  // @211_5618b0
  FL[2] = (eax & eax);  // @212_5618b0
  edx = (u32)(6972856);  // @213_5618b0
  if (FL[2] != 0) ecx = eax;  // @214_5618b0
  eax = ext_4cc850_fastcall2(ecx, edx);  // @215_5618b0
  ecx = edx = 0;  // @216_5618b0
  FL[2] = (eax & eax);  // @217_5618b0
  if (FL[2] != 0) goto L561b18;  // @218_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @219_5618b0
  eax = (u32)(EBP - 28);  // @220_5618b0
  PV[8] = (u32)(eax);  // @221_5618b0
  eax = ext_4db500_thiscall2(ecx, PV[8]);  // @222_5618b0
  ecx = edx = 0;  // @223_5618b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @224_5618b0
  X0[1] = 0;  // @225_5618b0
  X0[2] = 0;  // @226_5618b0
  X0[3] = 0;  // @227_5618b0
  ecx = (u32)(EBP - 28);  // @228_5618b0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; })));  // @229_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @230_5618b0
  PV[9] = (u32)(ecx);  // @231_5618b0
  ecx = esi;  // @232_5618b0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @233_5618b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[9]);  // @234_5618b0
  ecx = edx = 0;  // @235_5618b0
  L561b18:;
  ecx = edi;  // @237_5618b0
  eax = ext_4db520_thiscall1(ecx);  // @238_5618b0
  ecx = edx = 0;  // @239_5618b0
  edi = eax;  // @240_5618b0
  goto L561ab0;  // @241_5618b0
  L561b23:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @243_5618b0
  L561b26:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @245_5618b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @246_5618b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6972596), (u32)(351));  // @247_5618b0
  ecx = edx = 0;  // @248_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @249_5618b0
  edx = (u32)(6801640);  // @250_5618b0
  FL[2] = (ecx & ecx);  // @251_5618b0
  if (FL[2] != 0) edx = ecx;  // @252_5618b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @253_5618b0
  PV[10] = (u32)(edx);  // @254_5618b0
  PV[11] = (u32)(eax);  // @255_5618b0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[11], (u32)(6972864), PV[10]);  // @256_5618b0
  ecx = edx = 0;  // @257_5618b0
  L561b57:;
  L561b58:;
  ext_633654(G(u32, 0x6f5630));  // @260_5618b0
  return eax;  // @261_5618b0
}
PCREG(5618b0, lifted_5618b0);

extern "C" u32 THISCALL lifted_455b10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_455b10
  esi = ecx;  // @1_455b10
  PV[0] = (u32)(ebx);  // @2_455b10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @3_455b10
  eax = ext_610100_stdcall1(PV[0]);  // @4_455b10
  ecx = edx = 0;  // @5_455b10
  eax = (u32)(esi + 24);  // @6_455b10
  ecx = ebx;  // @7_455b10
  PV[1] = (u32)(eax);  // @8_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[1], (u32)(3));  // @9_455b10
  ecx = edx = 0;  // @10_455b10
  eax = (u32)(esi + 36);  // @11_455b10
  ecx = ebx;  // @12_455b10
  PV[2] = (u32)(eax);  // @13_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[2], (u32)(1));  // @14_455b10
  ecx = edx = 0;  // @15_455b10
  eax = (u32)(esi + 40);  // @16_455b10
  ecx = ebx;  // @17_455b10
  PV[3] = (u32)(eax);  // @18_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[3], (u32)(1));  // @19_455b10
  ecx = edx = 0;  // @20_455b10
  eax = (u32)(esi + 44);  // @21_455b10
  ecx = ebx;  // @22_455b10
  PV[4] = (u32)(eax);  // @23_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[4], (u32)(1));  // @24_455b10
  ecx = edx = 0;  // @25_455b10
  eax = (u32)(esi + 48);  // @26_455b10
  ecx = ebx;  // @27_455b10
  PV[5] = (u32)(eax);  // @28_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[5], (u32)(1));  // @29_455b10
  ecx = edx = 0;  // @30_455b10
  eax = (u32)(esi + 52);  // @31_455b10
  ecx = ebx;  // @32_455b10
  PV[6] = (u32)(eax);  // @33_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[6], (u32)(1));  // @34_455b10
  ecx = edx = 0;  // @35_455b10
  edi = (u32)(esi + 60);  // @36_455b10
  ecx = ebx;  // @37_455b10
  PV[7] = (u32)(edi);  // @38_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[7], (u32)(1));  // @39_455b10
  ecx = edx = 0;  // @40_455b10
  esi = (esi + (u32)(64));  // @41_455b10
  FL[3] = esi;  // @42_455b10
  ecx = ebx;  // @43_455b10
  PV[8] = (u32)(esi);  // @44_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[8], (u32)(1));  // @45_455b10
  ecx = edx = 0;  // @46_455b10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @47_455b10
  X0[1] = 0;  // @48_455b10
  X0[2] = 0;  // @49_455b10
  X0[3] = 0;  // @50_455b10
  ecx = ebx;  // @51_455b10
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806020) + 0), 4); v; })));  // @52_455b10
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @53_455b10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @54_455b10
  X0[1] = 0;  // @55_455b10
  X0[2] = 0;  // @56_455b10
  X0[3] = 0;  // @57_455b10
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806020) + 0), 4); v; })));  // @58_455b10
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @59_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @60_455b10
  ecx = edx = 0;  // @61_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(5);  // @62_455b10
  if (FL[0] == FL[1]) goto L455c1d;  // @63_455b10
  ecx = ebx;  // @64_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @65_455b10
  ecx = edx = 0;  // @66_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @67_455b10
  if (FL[0] == FL[1]) goto L455c1d;  // @68_455b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @69_455b10
  ecx = ebx;  // @70_455b10
  edi = (u32)(esi + 56);  // @71_455b10
  PV[9] = (u32)(edi);  // @72_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[9], (u32)(1));  // @73_455b10
  ecx = edx = 0;  // @74_455b10
  esi = (esi + (u32)(68));  // @75_455b10
  FL[3] = esi;  // @76_455b10
  ecx = ebx;  // @77_455b10
  PV[10] = (u32)(esi);  // @78_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[10], (u32)(1));  // @79_455b10
  ecx = edx = 0;  // @80_455b10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @81_455b10
  X0[1] = 0;  // @82_455b10
  X0[2] = 0;  // @83_455b10
  X0[3] = 0;  // @84_455b10
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806020) + 0), 4); v; })));  // @85_455b10
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @86_455b10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @87_455b10
  X0[1] = 0;  // @88_455b10
  X0[2] = 0;  // @89_455b10
  X0[3] = 0;  // @90_455b10
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806020) + 0), 4); v; })));  // @91_455b10
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @92_455b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @93_455b10
  goto L455c31;  // @94_455b10
  L455c1d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @96_455b10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @97_455b10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @98_455b10
  L455c31:;
  ecx = ebx;  // @100_455b10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @101_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @102_455b10
  ecx = edx = 0;  // @103_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @104_455b10
  if (FL[0] != FL[1]) goto L455c5d;  // @105_455b10
  eax = (u32)(EBP - 520);  // @106_455b10
  ecx = ebx;  // @107_455b10
  PV[11] = (u32)(eax);  // @108_455b10
  eax = ext_4e11e0_thiscall3(ecx, PV[11], (u32)(1));  // @109_455b10
  ecx = edx = 0;  // @110_455b10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @111_455b10
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @112_455b10
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @113_455b10
  L455c5d:;
  eax = (u32)(EBP - 516);  // @115_455b10
  ecx = ebx;  // @116_455b10
  PV[12] = (u32)(eax);  // @117_455b10
  eax = ext_4e1070_thiscall2(ecx, PV[12]);  // @118_455b10
  ecx = edx = 0;  // @119_455b10
  eax = (u32)(esi + 73);  // @120_455b10
  ecx = ebx;  // @121_455b10
  PV[13] = (u32)(eax);  // @122_455b10
  eax = ext_4e12e0_thiscall3(ecx, PV[13], (u32)(1));  // @123_455b10
  ecx = edx = 0;  // @124_455b10
  ecx = ebx;  // @125_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @126_455b10
  ecx = edx = 0;  // @127_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @128_455b10
  if (FL[0] != FL[1]) goto L455ccf;  // @129_455b10
  eax = (u32)(EBP - 520);  // @130_455b10
  ecx = ebx;  // @131_455b10
  PV[14] = (u32)(eax);  // @132_455b10
  eax = ext_4e1440_thiscall2(ecx, PV[14]);  // @133_455b10
  ecx = edx = 0;  // @134_455b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @135_455b10
  FL[2] = (ecx & ecx);  // @136_455b10
  if (FL[2] == 0) goto L455ccf;  // @137_455b10
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @138_455b10
  if (FL[0] == FL[1]) goto L455ccf;  // @139_455b10
  edx = (u32)(ecx + 1);  // @140_455b10
  L455ca3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @142_455b10
  ecx = (ecx + 1);  // @143_455b10
  FL[3] = ecx;  // @144_455b10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @145_455b10
  if (FL[2] != 0) goto L455ca3;  // @146_455b10
  ecx = (ecx - edx);  // @147_455b10
  FL[3] = ecx;  // @148_455b10
  eax = (u32)(ecx + 1);  // @149_455b10
  PV[15] = (u32)(eax);  // @150_455b10
  eax = ext_41e290_cdecl1(PV[15]);  // @151_455b10
  ecx = edx = 0;  // @152_455b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @153_455b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 77), &v, sizeof v); }  // @154_455b10
  L455cc1:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @156_455b10
  edx = (u32)(edx + 1);  // @157_455b10
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @158_455b10
  eax = (u32)(eax + 1);  // @159_455b10
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @160_455b10
  if (FL[2] != 0) goto L455cc1;  // @161_455b10
  L455ccf:;
  ecx = ebx;  // @163_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @164_455b10
  ecx = edx = 0;  // @165_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @166_455b10
  if (FL[0] != FL[1]) goto L455cea;  // @167_455b10
  eax = (u32)(EBP - 520);  // @168_455b10
  ecx = ebx;  // @169_455b10
  PV[16] = (u32)(eax);  // @170_455b10
  eax = ext_4e12e0_thiscall3(ecx, PV[16], (u32)(1));  // @171_455b10
  ecx = edx = 0;  // @172_455b10
  L455cea:;
  ecx = ebx;  // @174_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @175_455b10
  ecx = edx = 0;  // @176_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @177_455b10
  if (FL[0] != FL[1]) goto L455d04;  // @178_455b10
  eax = (u32)(esi + 89);  // @179_455b10
  ecx = ebx;  // @180_455b10
  PV[17] = (u32)(eax);  // @181_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[17], (u32)(1));  // @182_455b10
  ecx = edx = 0;  // @183_455b10
  goto L455d0b;  // @184_455b10
  L455d04:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @186_455b10
  L455d0b:;
  ecx = ebx;  // @188_455b10
  eax = ext_4e1600_thiscall1(ecx);  // @189_455b10
  ecx = edx = 0;  // @190_455b10
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @191_455b10
  eax = (u32)(esi + 93);  // @192_455b10
  if (FL[0] != FL[1]) goto L455d25;  // @193_455b10
  PV[18] = (u32)(eax);  // @194_455b10
  ecx = ebx;  // @195_455b10
  eax = ext_4e12f0_thiscall3(ecx, PV[18], (u32)(32));  // @196_455b10
  ecx = edx = 0;  // @197_455b10
  goto L455d35;  // @198_455b10
  L455d25:;
  PV[19] = (u32)(eax);  // @200_455b10
  eax = ext_634d10_cdecl3(PV[19], (u32)(0), (u32)(128));  // @201_455b10
  ecx = edx = 0;  // @202_455b10
  L455d35:;
  eax = (u32)(esi + 81);  // @204_455b10
  ecx = ebx;  // @205_455b10
  PV[20] = (u32)(eax);  // @206_455b10
  eax = ext_4e12e0_thiscall3(ecx, PV[20], (u32)(1));  // @207_455b10
  ecx = edx = 0;  // @208_455b10
  ecx = ebx;  // @209_455b10
  eax = ext_4e1b30_thiscall1(ecx);  // @210_455b10
  ecx = edx = 0;  // @211_455b10
  ecx = (u32)(EBP - 516);  // @212_455b10
  edx = (u32)(ecx + 1);  // @213_455b10
  L455d52:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @215_455b10
  ecx = (ecx + 1);  // @216_455b10
  FL[3] = ecx;  // @217_455b10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @218_455b10
  if (FL[2] != 0) goto L455d52;  // @219_455b10
  ecx = (ecx - edx);  // @220_455b10
  FL[3] = ecx;  // @221_455b10
  eax = (u32)(ecx + 1);  // @222_455b10
  PV[21] = (u32)(eax);  // @223_455b10
  eax = ext_41e290_cdecl1(PV[21]);  // @224_455b10
  ecx = edx = 0;  // @225_455b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @226_455b10
  edx = (u32)(EBP - 516);  // @227_455b10
  L455d70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @229_455b10
  edx = (u32)(edx + 1);  // @230_455b10
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @231_455b10
  eax = (u32)(eax + 1);  // @232_455b10
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @233_455b10
  if (FL[2] != 0) goto L455d70;  // @234_455b10
  ecx = esi;  // @235_455b10
  eax = ext_455dd0_thiscall1(ecx);  // @236_455b10
  ecx = edx = 0;  // @237_455b10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; });  // @238_455b10
  X0[1] = 0;  // @239_455b10
  X0[2] = 0;  // @240_455b10
  X0[3] = 0;  // @241_455b10
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; }))))) goto L455d9a;  // @242_455b10
  { u32 v = (u32)((u32)(1008981770)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @243_455b10
  L455d9a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @245_455b10
  X0[1] = 0;  // @246_455b10
  X0[2] = 0;  // @247_455b10
  X0[3] = 0;  // @248_455b10
  edx = (u32)(esi + 24);  // @249_455b10
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; })));  // @250_455b10
  PV[22] = (u32)(ecx);  // @251_455b10
  ecx = (u32)(esi + 225);  // @252_455b10
  PV[23] = X0[0];  // @253_455b10
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[23]);  // @254_455b10
  ecx = edx = 0;  // @255_455b10
  ext_633654(G(u32, 0x6f5630));  // @256_455b10
  return eax;  // @257_455b10
}
PCREG(455b10, lifted_455b10);

extern "C" u32 THISCALL lifted_566020(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_566020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2569), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_566020
  if (FL[0] == FL[1]) goto L5661f6;  // @2_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2591), sizeof v); (u32)v; });  // @3_566020
  eax = ext_5adda0_thiscall1(ecx);  // @4_566020
  ecx = edx = 0;  // @5_566020
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @6_566020
  if (FL[2] == 0) goto L56605b;  // @7_566020
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2570), &v, sizeof v); }  // @8_566020
  goto L5661b0;  // @9_566020
  L56605b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 384), sizeof v); (u32)v; });  // @11_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @12_566020
  FL[2] = (ecx & ecx);  // @13_566020
  if (FL[2] == 0) goto L5660c0;  // @14_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_566020
  edx = (u32)(EBP - 40);  // @16_566020
  PV[0] = (u32)(edx);  // @17_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @18_566020
  ecx = edx = 0;  // @19_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 384), sizeof v); (u32)v; });  // @20_566020
  edx = (u32)(EBP - 40);  // @21_566020
  PV[1] = (u32)(edx);  // @22_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @23_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @25_566020
  ecx = edx = 0;  // @26_566020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_566020
  edi = eax;  // @28_566020
  if (FL[0] == FL[1]) goto L5660c0;  // @29_566020
  L566090:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @31_566020
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 408), sizeof v); (u32)v; });  // @32_566020
  PV[2] = (u32)(eax);  // @33_566020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_566020
  PV[3] = (u32)(edi);  // @35_566020
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[3], PV[2], (u32)(0));  // @36_566020
  ecx = edx = 0;  // @37_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 384), sizeof v); (u32)v; });  // @38_566020
  edx = (u32)(EBP - 40);  // @39_566020
  PV[4] = (u32)(edx);  // @40_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @41_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @43_566020
  ecx = edx = 0;  // @44_566020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @45_566020
  edi = eax;  // @46_566020
  if (FL[0] != FL[1]) goto L566090;  // @47_566020
  L5660c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2591), sizeof v); (u32)v; });  // @49_566020
  eax = (u32)(EBP - 20);  // @50_566020
  PV[5] = (u32)(eax);  // @51_566020
  eax = ext_5addc0_thiscall2(ecx, PV[5]);  // @52_566020
  ecx = edx = 0;  // @53_566020
  ebx = (u32)(4);  // @54_566020
  edi = (u32)(EBP - 20);  // @55_566020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @56_566020
  L5660e0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @58_566020
  if (FL[0] == FL[1]) goto L566152;  // @59_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 384), sizeof v); (u32)v; });  // @60_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @61_566020
  FL[2] = (ecx & ecx);  // @62_566020
  if (FL[2] == 0) goto L566152;  // @63_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_566020
  edx = (u32)(EBP - 52);  // @65_566020
  PV[6] = (u32)(edx);  // @66_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @67_566020
  ecx = edx = 0;  // @68_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 384), sizeof v); (u32)v; });  // @69_566020
  edx = (u32)(EBP - 52);  // @70_566020
  PV[7] = (u32)(edx);  // @71_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @72_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @74_566020
  ecx = edx = 0;  // @75_566020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @76_566020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @77_566020
  if (FL[0] == FL[1]) goto L566152;  // @78_566020
  ebx = eax;  // @79_566020
  L566120:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @81_566020
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 402), sizeof v); (u32)v; });  // @82_566020
  PV[8] = (u32)(edi);  // @83_566020
  PV[9] = (u32)(eax);  // @84_566020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_566020
  PV[10] = (u32)(ebx);  // @86_566020
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[10], PV[9], PV[8]);  // @87_566020
  ecx = edx = 0;  // @88_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 384), sizeof v); (u32)v; });  // @89_566020
  edx = (u32)(EBP - 52);  // @90_566020
  PV[11] = (u32)(edx);  // @91_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @92_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[11]);  // @94_566020
  ecx = edx = 0;  // @95_566020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_566020
  ebx = eax;  // @97_566020
  if (FL[0] != FL[1]) goto L566120;  // @98_566020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @99_566020
  L566152:;
  edi = (edi + (u32)(4));  // @101_566020
  FL[3] = edi;  // @102_566020
  ebx = (ebx - (u32)(1));  // @103_566020
  FL[3] = ebx;  // @104_566020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @105_566020
  if (FL[3] != 0) goto L5660e0;  // @106_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2591), sizeof v); (u32)v; });  // @107_566020
  eax = (u32)(esi + 410);  // @108_566020
  PV[12] = (u32)(eax);  // @109_566020
  eax = ext_5adef0_thiscall2(ecx, PV[12]);  // @110_566020
  ecx = edx = 0;  // @111_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 446), sizeof v); (u32)v; });  // @112_566020
  FL[2] = (eax & eax);  // @113_566020
  if (FL[2] == 0) goto L5661ae;  // @114_566020
  ebx = 0;  // @115_566020
  FL[3] = ebx;  // @116_566020
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2571), &v, sizeof v); }  // @117_566020
  FL[2] = (eax & eax);  // @118_566020
  if ((s32)FL[2] <= 0) goto L5661ae;  // @119_566020
  edi = (u32)(esi + 450);  // @120_566020
  L566190:;
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi - 36), sizeof v); (u32)v; });  // @122_566020
  ecx = esi;  // @123_566020
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 410), sizeof v); (u32)v; });  // @124_566020
  eax = ext_562280_stdcall2(PV[14], PV[13]);  // @125_566020
  ecx = edx = 0;  // @126_566020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @127_566020
  edi = (u32)(edi + 4);  // @128_566020
  ebx = (ebx + 1);  // @129_566020
  FL[3] = ebx;  // @130_566020
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 446), sizeof v); (u32)v; });  // @131_566020
  if ((s32)FL[0] < (s32)FL[1]) goto L566190;  // @132_566020
  L5661ae:;
  L5661b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @135_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @136_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6932112));  // @138_566020
  ecx = edx = 0;  // @139_566020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2575), &v, sizeof v); }  // @140_566020
  ecx = eax;  // @141_566020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @142_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(6974956));  // @143_566020
  ecx = edx = 0;  // @144_566020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2579), &v, sizeof v); }  // @145_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @146_566020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2569), &v, sizeof v); }  // @147_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @148_566020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2583), &v, sizeof v); }  // @149_566020
  L5661f6:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2573), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @151_566020
  if (FL[0] == FL[1]) goto L566294;  // @152_566020
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 486) + 0), 4); v; });  // @153_566020
  X0[1] = 0;  // @154_566020
  X0[2] = 0;  // @155_566020
  X0[3] = 0;  // @156_566020
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @157_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_566020
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @159_566020
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @160_566020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); FL[1] = ecx;  // @161_566020
  if ((s32)FL[0] <= (s32)FL[1]) goto L566250;  // @162_566020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2570), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @163_566020
  if (FL[0] == FL[1]) goto L566240;  // @164_566020
  ecx = esi;  // @165_566020
  eax = ext_566850_thiscall1(ecx);  // @166_566020
  ecx = edx = 0;  // @167_566020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2570), &v, sizeof v); }  // @168_566020
  L566240:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2571), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @170_566020
  if (FL[0] == FL[1]) goto L566250;  // @171_566020
  ecx = esi;  // @172_566020
  eax = ext_566b20_thiscall1(ecx);  // @173_566020
  ecx = edx = 0;  // @174_566020
  L566250:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2570), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @176_566020
  if (FL[0] != FL[1]) goto L566294;  // @177_566020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2571), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @178_566020
  if (FL[0] != FL[1]) goto L566294;  // @179_566020
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2572), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @180_566020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2573), &v, sizeof v); }  // @181_566020
  if (FL[0] == FL[1]) goto L566294;  // @182_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @183_566020
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 398), sizeof v); (u32)v; });  // @184_566020
  PV[15] = (u32)(eax);  // @185_566020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_566020
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2564), sizeof v); (u32)v; });  // @187_566020
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 300)))(ecx, PV[16], PV[15], (u32)(0));  // @188_566020
  ecx = edx = 0;  // @189_566020
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2572), &v, sizeof v); }  // @190_566020
  L566294:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2574), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @192_566020
  if (FL[0] == FL[1]) goto L566306;  // @193_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @194_566020
  ecx = esi;  // @195_566020
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @196_566020
  ecx = edx = 0;  // @197_566020
  ecx = (u32)(eax + 203);  // @198_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_566020
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @200_566020
  ecx = edx = 0;  // @201_566020
  FL[2] = (eax & eax);  // @202_566020
  if (FL[2] != 0) goto L5662f5;  // @203_566020
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2556), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 2556), &v, sizeof v); }  // @204_566020
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2556), sizeof v); (u32)v; });  // @205_566020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2556), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @206_566020
  if ((s32)FL[0] <= (s32)FL[1]) goto L566306;  // @207_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @208_566020
  ecx = esi;  // @209_566020
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @210_566020
  ecx = edx = 0;  // @211_566020
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2560), sizeof v); (u32)v; });  // @212_566020
  ecx = eax;  // @213_566020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @214_566020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 760)))(ecx, PV[17]);  // @215_566020
  ecx = edx = 0;  // @216_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2591), sizeof v); (u32)v; });  // @217_566020
  eax = ext_5ade90_thiscall1(ecx);  // @218_566020
  ecx = edx = 0;  // @219_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2591), sizeof v); (u32)v; });  // @220_566020
  eax = ext_5ae680_thiscall1(ecx);  // @221_566020
  ecx = edx = 0;  // @222_566020
  L5662f5:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2574), &v, sizeof v); }  // @224_566020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2556), &v, sizeof v); }  // @225_566020
  L566306:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2568), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @227_566020
  if (FL[0] == FL[1]) goto L56634f;  // @228_566020
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2548), sizeof v); (u32)v; });  // @229_566020
  PV[19] = (u32)(ecx);  // @230_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 144), sizeof v); (u32)v; });  // @231_566020
  eax = ext_5950c0_thiscall4(ecx, (u32)(17), (u32)(1128792064), PV[18]);  // @232_566020
  ecx = edx = 0;  // @233_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @234_566020
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2579), sizeof v); (u32)v; });  // @235_566020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @236_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @237_566020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @238_566020
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[20], (u32)(0));  // @239_566020
  ecx = edx = 0;  // @240_566020
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @241_566020
  if (FL[2] == 0) goto L56634f;  // @242_566020
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2574), &v, sizeof v); }  // @243_566020
  L56634f:;
  ext_633654(G(u32, 0x6f5630));  // @245_566020
  return eax;  // @246_566020
}
PCREG(566020, lifted_566020);

extern "C" u32 FASTCALL lifted_563a50(u32 ecx_in, u32 edx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_563a50
  esi = ecx;  // @1_563a50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @2_563a50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @4_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @5_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @6_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @7_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @8_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @9_563a50
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @10_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @11_563a50
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @12_563a50
  edx = (edx & (u32)(127));  // @13_563a50
  FL[3] = edx;  // @14_563a50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @15_563a50
  eax = (eax + edx);  // @16_563a50
  FL[3] = eax;  // @17_563a50
  eax = (u32)((s32)eax >> (u32)(7));  // @18_563a50
  FL[3] = eax;  // @19_563a50
  eax = (eax + 1);  // @20_563a50
  FL[3] = eax;  // @21_563a50
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @22_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @23_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @24_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @25_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @26_563a50
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @27_563a50
  FL[2] = (ecx & ecx);  // @28_563a50
  if (FL[2] == 0) goto L563ba8;  // @29_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_563a50
  edx = (u32)(EBP - 28);  // @31_563a50
  PV[0] = (u32)(edx);  // @32_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[0]);  // @33_563a50
  ecx = edx = 0;  // @34_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @35_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6972708), (u32)(0));  // @37_563a50
  ecx = edx = 0;  // @38_563a50
  edi = eax;  // @39_563a50
  FL[2] = (edi & edi);  // @40_563a50
  if (FL[2] == 0) goto L563b1e;  // @41_563a50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_563a50
  eax = (u32)(EBP - 36);  // @43_563a50
  PV[1] = (u32)(eax);  // @44_563a50
  ecx = edi;  // @45_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 600)))(ecx, PV[1], (u32)(0));  // @46_563a50
  ecx = edx = 0;  // @47_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @48_563a50
  eax = (u32)(EBP - 16);  // @49_563a50
  PV[2] = (u32)(eax);  // @50_563a50
  eax = ext_4db500_thiscall2(ecx, PV[2]);  // @51_563a50
  ecx = edx = 0;  // @52_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @53_563a50
  X0[1] = 0;  // @54_563a50
  X0[2] = 0;  // @55_563a50
  X0[3] = 0;  // @56_563a50
  ecx = (u32)(EBP - 16);  // @57_563a50
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @58_563a50
  PV[3] = (u32)(ecx);  // @59_563a50
  ecx = edi;  // @60_563a50
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @61_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @62_563a50
  X0[1] = 0;  // @63_563a50
  X0[2] = 0;  // @64_563a50
  X0[3] = 0;  // @65_563a50
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @66_563a50
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @67_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @68_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[3]);  // @69_563a50
  ecx = edx = 0;  // @70_563a50
  L563b1e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @72_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6973132), (u32)(0));  // @74_563a50
  ecx = edx = 0;  // @75_563a50
  edi = eax;  // @76_563a50
  FL[2] = (edi & edi);  // @77_563a50
  if (FL[2] == 0) goto L563ba8;  // @78_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; });  // @79_563a50
  ecx = (u32)(EBP - 36);  // @80_563a50
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @81_563a50
  edx = (edx & (u32)(7));  // @82_563a50
  FL[3] = edx;  // @83_563a50
  eax = (eax + edx);  // @84_563a50
  FL[3] = eax;  // @85_563a50
  eax = (u32)((s32)eax >> (u32)(3));  // @86_563a50
  FL[3] = eax;  // @87_563a50
  PV[4] = (u32)(ecx);  // @88_563a50
  ecx = edi;  // @89_563a50
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @90_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @91_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @92_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @93_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @94_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @95_563a50
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @96_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @97_563a50
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @98_563a50
  edx = (edx & (u32)(15));  // @99_563a50
  FL[3] = edx;  // @100_563a50
  eax = (eax + edx);  // @101_563a50
  FL[3] = eax;  // @102_563a50
  eax = (u32)((s32)eax >> (u32)(4));  // @103_563a50
  FL[3] = eax;  // @104_563a50
  eax = (eax + 1);  // @105_563a50
  FL[3] = eax;  // @106_563a50
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @107_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @108_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @109_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @110_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @111_563a50
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @112_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @113_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[4], (u32)(0));  // @114_563a50
  ecx = edx = 0;  // @115_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @116_563a50
  eax = (u32)(EBP - 16);  // @117_563a50
  PV[5] = (u32)(eax);  // @118_563a50
  eax = ext_4db500_thiscall2(ecx, PV[5]);  // @119_563a50
  ecx = edx = 0;  // @120_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @121_563a50
  X0[1] = 0;  // @122_563a50
  X0[2] = 0;  // @123_563a50
  X0[3] = 0;  // @124_563a50
  ecx = (u32)(EBP - 16);  // @125_563a50
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @126_563a50
  PV[6] = (u32)(ecx);  // @127_563a50
  ecx = edi;  // @128_563a50
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @129_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @130_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[6]);  // @131_563a50
  ecx = edx = 0;  // @132_563a50
  L563ba8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @134_563a50
  FL[2] = (ecx & ecx);  // @135_563a50
  if (FL[2] == 0) goto L563cd6;  // @136_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_563a50
  edx = (u32)(EBP - 28);  // @138_563a50
  PV[7] = (u32)(edx);  // @139_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[7]);  // @140_563a50
  ecx = edx = 0;  // @141_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @142_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @143_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6972708), (u32)(0));  // @144_563a50
  ecx = edx = 0;  // @145_563a50
  edi = eax;  // @146_563a50
  FL[2] = (edi & edi);  // @147_563a50
  if (FL[2] == 0) goto L563c32;  // @148_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_563a50
  ecx = (u32)(EBP - 36);  // @150_563a50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @151_563a50
  PV[8] = (u32)(ecx);  // @152_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @153_563a50
  ecx = edi;  // @154_563a50
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @155_563a50
  edx = (edx & (u32)(127));  // @156_563a50
  FL[3] = edx;  // @157_563a50
  eax = (eax + edx);  // @158_563a50
  FL[3] = eax;  // @159_563a50
  eax = (u32)((s32)eax >> (u32)(7));  // @160_563a50
  FL[3] = eax;  // @161_563a50
  eax = (eax + 1);  // @162_563a50
  FL[3] = eax;  // @163_563a50
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @164_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @165_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @166_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @167_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @168_563a50
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @169_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @170_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[8], (u32)(0));  // @171_563a50
  ecx = edx = 0;  // @172_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @173_563a50
  eax = (u32)(EBP - 16);  // @174_563a50
  PV[9] = (u32)(eax);  // @175_563a50
  eax = ext_4db500_thiscall2(ecx, PV[9]);  // @176_563a50
  ecx = edx = 0;  // @177_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @178_563a50
  X0[1] = 0;  // @179_563a50
  X0[2] = 0;  // @180_563a50
  X0[3] = 0;  // @181_563a50
  ecx = (u32)(EBP - 16);  // @182_563a50
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @183_563a50
  PV[10] = (u32)(ecx);  // @184_563a50
  ecx = edi;  // @185_563a50
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @186_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @187_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[10]);  // @188_563a50
  ecx = edx = 0;  // @189_563a50
  L563c32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @191_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6973132), (u32)(0));  // @193_563a50
  ecx = edx = 0;  // @194_563a50
  edi = eax;  // @195_563a50
  FL[2] = (edi & edi);  // @196_563a50
  if (FL[2] == 0) goto L563cd6;  // @197_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @198_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; });  // @199_563a50
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }));  // @200_563a50
  FL[3] = eax;  // @201_563a50
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @202_563a50
  edx = (edx & (u32)(7));  // @203_563a50
  FL[3] = edx;  // @204_563a50
  eax = (eax + edx);  // @205_563a50
  FL[3] = eax;  // @206_563a50
  eax = (u32)((s32)eax >> (u32)(3));  // @207_563a50
  FL[3] = eax;  // @208_563a50
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @209_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @210_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @211_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @212_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @213_563a50
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @214_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; });  // @215_563a50
  ecx = (u32)(EBP - 36);  // @216_563a50
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @217_563a50
  edx = (edx & (u32)(15));  // @218_563a50
  FL[3] = edx;  // @219_563a50
  eax = (eax + edx);  // @220_563a50
  FL[3] = eax;  // @221_563a50
  eax = (u32)((s32)eax >> (u32)(4));  // @222_563a50
  FL[3] = eax;  // @223_563a50
  eax = (eax + 1);  // @224_563a50
  FL[3] = eax;  // @225_563a50
  PV[11] = (u32)(ecx);  // @226_563a50
  ecx = edi;  // @227_563a50
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @228_563a50
  X0[0] = F2U((float)(s32)X0[0]);  // @229_563a50
  X0[1] = F2U((float)(s32)X0[1]);  // @230_563a50
  X0[2] = F2U((float)(s32)X0[2]);  // @231_563a50
  X0[3] = F2U((float)(s32)X0[3]);  // @232_563a50
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @233_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @234_563a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 600)))(ecx, PV[11], (u32)(0));  // @235_563a50
  ecx = edx = 0;  // @236_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @237_563a50
  eax = (u32)(EBP - 16);  // @238_563a50
  PV[12] = (u32)(eax);  // @239_563a50
  eax = ext_4db500_thiscall2(ecx, PV[12]);  // @240_563a50
  ecx = edx = 0;  // @241_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @242_563a50
  X0[1] = 0;  // @243_563a50
  X0[2] = 0;  // @244_563a50
  X0[3] = 0;  // @245_563a50
  ecx = (u32)(EBP - 16);  // @246_563a50
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @247_563a50
  PV[13] = (u32)(ecx);  // @248_563a50
  ecx = edi;  // @249_563a50
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @250_563a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @251_563a50
  X0[1] = 0;  // @252_563a50
  X0[2] = 0;  // @253_563a50
  X0[3] = 0;  // @254_563a50
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })));  // @255_563a50
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @256_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @257_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[13]);  // @258_563a50
  ecx = edx = 0;  // @259_563a50
  L563cd6:;
  ecx = esi;  // @261_563a50
  eax = ext_562390_thiscall1(ecx);  // @262_563a50
  ecx = edx = 0;  // @263_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @264_563a50
  ecx = esi;  // @265_563a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @266_563a50
  ecx = edx = 0;  // @267_563a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 248), sizeof v); (u32)v; });  // @268_563a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @269_563a50
  FL[2] = (ecx & ecx);  // @270_563a50
  if (FL[2] == 0) goto L563d0d;  // @271_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @272_563a50
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @273_563a50
  ecx = edi;  // @274_563a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[14]);  // @275_563a50
  ecx = edx = 0;  // @276_563a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 248), sizeof v); (u32)v; });  // @277_563a50
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 2206), &v, sizeof v); }  // @278_563a50
  L563d0d:;
  ext_633654(G(u32, 0x6f5630));  // @280_563a50
  return eax;  // @281_563a50
}
PCREG(563a50, lifted_563a50);

extern "C" u32 THISCALL lifted_5d3af0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1_5d3af0
  edi = ecx;  // @2_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @3_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5d3af0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @5_5d3af0
  ecx = edx = 0;  // @6_5d3af0
  ebx = (ebx | (u32)(4294967295));  // @7_5d3af0
  FL[3] = ebx;  // @8_5d3af0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @9_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @10_5d3af0
  esi = (esi | ebx);  // @11_5d3af0
  FL[3] = esi;  // @12_5d3af0
  FL[2] = (eax & eax);  // @13_5d3af0
  if (FL[2] == 0) goto L5d3b4d;  // @14_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5d3af0
  PV[0] = (u32)(eax);  // @16_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @17_5d3af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @19_5d3af0
  ecx = edx = 0;  // @20_5d3af0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @21_5d3af0
  FL[2] = (eax & eax);  // @22_5d3af0
  if (FL[2] != 0) goto L5d3b53;  // @23_5d3af0
  L5d3b4d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @25_5d3af0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @26_5d3af0
  L5d3b53:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @28_5d3af0
  X0[0] = 0;  // @29_5d3af0
  X0[1] = 0;  // @30_5d3af0
  X0[2] = 0;  // @31_5d3af0
  X0[3] = 0;  // @32_5d3af0
  __builtin_memcpy((void *)((u32)(edi + 88) + 0), &X0[0], 4);  // @33_5d3af0
  __builtin_memcpy((void *)((u32)(edi + 88) + 4), &X0[1], 4);  // @34_5d3af0
  __builtin_memcpy((void *)((u32)(edi + 88) + 8), &X0[2], 4);  // @35_5d3af0
  __builtin_memcpy((void *)((u32)(edi + 88) + 12), &X0[3], 4);  // @36_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @37_5d3af0
  FL[2] = (ecx & ecx);  // @38_5d3af0
  if (FL[2] == 0) goto L5d3c7b;  // @39_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5d3af0
  edx = (u32)(EBP - 40);  // @41_5d3af0
  PV[1] = (u32)(edx);  // @42_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @43_5d3af0
  ecx = edx = 0;  // @44_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @45_5d3af0
  edx = (u32)(EBP - 40);  // @46_5d3af0
  PV[2] = (u32)(edx);  // @47_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @48_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @50_5d3af0
  ecx = edx = 0;  // @51_5d3af0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @52_5d3af0
  edx = eax;  // @53_5d3af0
  if (FL[0] == FL[1]) goto L5d3c7b;  // @54_5d3af0
  L5d3b90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_5d3af0
  PV[3] = (u32)(edx);  // @57_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @58_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @60_5d3af0
  ecx = edx = 0;  // @61_5d3af0
  esi = eax;  // @62_5d3af0
  ecx = esi;  // @63_5d3af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_5d3af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @65_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2099193));  // @66_5d3af0
  ecx = edx = 0;  // @67_5d3af0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @68_5d3af0
  ecx = esi;  // @69_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_5d3af0
  if (FL[2] == 0) goto L5d3bdf;  // @71_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @72_5d3af0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @73_5d3af0
  ecx = edx = 0;  // @74_5d3af0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @75_5d3af0
  if (FL[2] != 0) goto L5d3c5b;  // @76_5d3af0
  ecx = esi;  // @77_5d3af0
  eax = ext_59ffc0_thiscall1(ecx);  // @78_5d3af0
  ecx = edx = 0;  // @79_5d3af0
  FL[0] = eax; FL[1] = (u32)(5);  // @80_5d3af0
  if (FL[0] == FL[1]) goto L5d3c5b;  // @81_5d3af0
  goto L5d3c00;  // @82_5d3af0
  L5d3bdf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @84_5d3af0
  eax = ((u32(STDCALL *)(u32))(eax))((u32)(2098152));  // @85_5d3af0
  ecx = edx = 0;  // @86_5d3af0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @87_5d3af0
  if (FL[2] == 0) goto L5d3c5b;  // @88_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @89_5d3af0
  ecx = esi;  // @90_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @91_5d3af0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @92_5d3af0
  ecx = edx = 0;  // @93_5d3af0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @94_5d3af0
  if (FL[2] != 0) goto L5d3c5b;  // @95_5d3af0
  L5d3c00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @97_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @98_5d3af0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @99_5d3af0
  eax = (u32)(EBP - 16);  // @100_5d3af0
  PV[4] = (u32)(eax);  // @101_5d3af0
  eax = ext_4daf90_thiscall2(ecx, PV[4]);  // @102_5d3af0
  ecx = edx = 0;  // @103_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_5d3af0
  ecx = (u32)(EBP - 16);  // @105_5d3af0
  PV[5] = (u32)(ecx);  // @106_5d3af0
  ecx = esi;  // @107_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[5]);  // @108_5d3af0
  ecx = edx = 0;  // @109_5d3af0
  FL[0] = ebx; FL[1] = (u32)(2);  // @110_5d3af0
  if (FL[0] == FL[1]) goto L5d3c5b;  // @111_5d3af0
  FL[0] = ebx; FL[1] = (u32)(7);  // @112_5d3af0
  if (FL[0] == FL[1]) goto L5d3c5b;  // @113_5d3af0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @114_5d3af0
  ecx = (u32)(EBP - 16);  // @115_5d3af0
  PV[6] = (u32)(ecx);  // @116_5d3af0
  ecx = esi;  // @117_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @118_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[6]);  // @119_5d3af0
  ecx = edx = 0;  // @120_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_5d3af0
  PV[7] = (u32)(ecx);  // @122_5d3af0
  ecx = (u32)(EBP - 16);  // @123_5d3af0
  PV[8] = (u32)(ecx);  // @124_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @125_5d3af0
  ecx = esi;  // @126_5d3af0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[8], (u32)(3240099840));  // @127_5d3af0
  ecx = edx = 0;  // @128_5d3af0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @129_5d3af0
  if (FL[2] == 0) goto L5d3c5b;  // @130_5d3af0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*4 + 76), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + ebx*4 + 76), &v, sizeof v); }  // @131_5d3af0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*4 + 76), sizeof v); (u32)v; });  // @132_5d3af0
  L5d3c5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @134_5d3af0
  edx = (u32)(EBP - 40);  // @135_5d3af0
  PV[9] = (u32)(edx);  // @136_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @137_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @139_5d3af0
  ecx = edx = 0;  // @140_5d3af0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @141_5d3af0
  edx = eax;  // @142_5d3af0
  if (FL[0] != FL[1]) goto L5d3b90;  // @143_5d3af0
  ebx = (ebx | (u32)(4294967295));  // @144_5d3af0
  FL[3] = ebx;  // @145_5d3af0
  esi = (esi | ebx);  // @146_5d3af0
  FL[3] = esi;  // @147_5d3af0
  L5d3c7b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 88), sizeof v); (u32)v; });  // @149_5d3af0
  FL[2] = (eax & eax);  // @150_5d3af0
  if ((s32)FL[2] <= 0) goto L5d3c8b;  // @151_5d3af0
  FL[0] = eax; FL[1] = (u32)(-1);  // @152_5d3af0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5d3c8b;  // @153_5d3af0
  esi = eax;  // @154_5d3af0
  ebx = 0;  // @155_5d3af0
  FL[3] = ebx;  // @156_5d3af0
  L5d3c8b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @158_5d3af0
  FL[2] = (eax & eax);  // @159_5d3af0
  if ((s32)FL[2] <= 0) goto L5d3c9d;  // @160_5d3af0
  FL[0] = eax; FL[1] = esi;  // @161_5d3af0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5d3c9d;  // @162_5d3af0
  esi = eax;  // @163_5d3af0
  ebx = (u32)(1);  // @164_5d3af0
  L5d3c9d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @166_5d3af0
  FL[2] = (eax & eax);  // @167_5d3af0
  if ((s32)FL[2] <= 0) goto L5d3caf;  // @168_5d3af0
  FL[0] = eax; FL[1] = esi;  // @169_5d3af0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5d3caf;  // @170_5d3af0
  esi = eax;  // @171_5d3af0
  ebx = (u32)(2);  // @172_5d3af0
  L5d3caf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; });  // @174_5d3af0
  FL[2] = (eax & eax);  // @175_5d3af0
  if ((s32)FL[2] <= 0) goto L5d3cc1;  // @176_5d3af0
  FL[0] = eax; FL[1] = esi;  // @177_5d3af0
  if ((s32)FL[0] <= (s32)FL[1]) goto L5d3cc1;  // @178_5d3af0
  ebx = (u32)(3);  // @179_5d3af0
  goto L5d3cc6;  // @180_5d3af0
  L5d3cc1:;
  FL[0] = ebx; FL[1] = (u32)(-1);  // @182_5d3af0
  if (FL[0] == FL[1]) goto L5d3d09;  // @183_5d3af0
  L5d3cc6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 128), sizeof v); (u32)v; });  // @185_5d3af0
  FL[0] = ecx; FL[1] = (u32)(-1);  // @186_5d3af0
  if (FL[0] == FL[1]) goto L5d3cf5;  // @187_5d3af0
  FL[0] = ebx; FL[1] = ecx;  // @188_5d3af0
  if (FL[0] == FL[1]) goto L5d3cdf;  // @189_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*4 + 88), sizeof v); (u32)v; });  // @190_5d3af0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx*4 + 88), sizeof v); (u32)v; });  // @191_5d3af0
  if ((s32)FL[0] > (s32)FL[1]) goto L5d3cf5;  // @192_5d3af0
  L5d3cdf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_5d3af0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @195_5d3af0
  X0[1] = 0;  // @196_5d3af0
  X0[2] = 0;  // @197_5d3af0
  X0[3] = 0;  // @198_5d3af0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; })));  // @199_5d3af0
  __builtin_memcpy((void *)((u32)(edi + 84) + 0), &X0[0], 4);  // @200_5d3af0
  goto L5d3d09;  // @201_5d3af0
  L5d3cf5:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @203_5d3af0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @204_5d3af0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 128), &v, sizeof v); }  // @205_5d3af0
  L5d3d09:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 128), sizeof v); (u32)v; });  // @207_5d3af0
  FL[0] = eax; FL[1] = (u32)(-1);  // @208_5d3af0
  if (FL[0] == FL[1]) goto L5d3d76;  // @209_5d3af0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @210_5d3af0
  if (FL[0] != FL[1]) goto L5d3d76;  // @211_5d3af0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @212_5d3af0
  eax = (eax + (u32)(3));  // @213_5d3af0
  FL[3] = eax;  // @214_5d3af0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @215_5d3af0
  ecx = esi;  // @216_5d3af0
  eax = (u32)(EBP - 20);  // @217_5d3af0
  PV[10] = (u32)(eax);  // @218_5d3af0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @219_5d3af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @220_5d3af0
  PV[11] = (u32)(eax);  // @221_5d3af0
  PV[12] = (u32)(esi);  // @222_5d3af0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[12], PV[11], PV[10]);  // @223_5d3af0
  ecx = edx = 0;  // @224_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @225_5d3af0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @226_5d3af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @227_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @228_5d3af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @229_5d3af0
  ecx = edx = 0;  // @230_5d3af0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @231_5d3af0
  ecx = esi;  // @232_5d3af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @233_5d3af0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @234_5d3af0
  eax = (u32)(EBP - 28);  // @235_5d3af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @236_5d3af0
  PV[14] = (u32)(eax);  // @237_5d3af0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @238_5d3af0
  PV[15] = (u32)(eax);  // @239_5d3af0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 133), sizeof v); (u32)v; });  // @240_5d3af0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, PV[16], PV[15], PV[14]);  // @241_5d3af0
  ecx = edx = 0;  // @242_5d3af0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 132), &v, sizeof v); }  // @243_5d3af0
  L5d3d76:;
  ext_633654(G(u32, 0x6f5630));  // @245_5d3af0
  return eax;  // @246_5d3af0
}
PCREG(5d3af0, lifted_5d3af0);

extern "C" u32 THISCALL lifted_5066e0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5066e0
  ebx = ecx;  // @1_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_5066e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @3_5066e0
  ecx = edx = 0;  // @4_5066e0
  edi = eax;  // @5_5066e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @6_5066e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @7_5066e0
  if (FL[2] == 0) goto L506746;  // @8_5066e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @9_5066e0
  if (FL[0] == FL[1]) goto L506746;  // @10_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_5066e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @13_5066e0
  ecx = edx = 0;  // @14_5066e0
  PV[0] = (u32)(eax);  // @15_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5066e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @17_5066e0
  ecx = edx = 0;  // @18_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @19_5066e0
  FL[2] = (eax & eax);  // @20_5066e0
  if (FL[2] == 0) goto L506745;  // @21_5066e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5066e0
  ecx = edx = 0;  // @23_5066e0
  goto L506746;  // @24_5066e0
  L506745:;
  __builtin_trap();  // @26_5066e0
  L506746:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @28_5066e0
  X0[1] = 0;  // @29_5066e0
  X0[2] = 0;  // @30_5066e0
  X0[3] = 0;  // @31_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @32_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @33_5066e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @34_5066e0
  ecx = edx = 0;  // @35_5066e0
  edi = eax;  // @36_5066e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @37_5066e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @38_5066e0
  if (FL[2] == 0) goto L50679d;  // @39_5066e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @40_5066e0
  if (FL[0] == FL[1]) goto L50679d;  // @41_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @42_5066e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @44_5066e0
  ecx = edx = 0;  // @45_5066e0
  PV[1] = (u32)(eax);  // @46_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_5066e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6932144), (u32)(6932792));  // @48_5066e0
  ecx = edx = 0;  // @49_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @50_5066e0
  FL[2] = (eax & eax);  // @51_5066e0
  if (FL[2] == 0) goto L50679c;  // @52_5066e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @53_5066e0
  ecx = edx = 0;  // @54_5066e0
  goto L50679d;  // @55_5066e0
  L50679c:;
  __builtin_trap();  // @57_5066e0
  L50679d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @59_5066e0
  X0[1] = 0;  // @60_5066e0
  X0[2] = 0;  // @61_5066e0
  X0[3] = 0;  // @62_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @63_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @64_5066e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @65_5066e0
  ecx = edx = 0;  // @66_5066e0
  edi = eax;  // @67_5066e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @68_5066e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @69_5066e0
  if (FL[2] == 0) goto L5067f4;  // @70_5066e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @71_5066e0
  if (FL[0] == FL[1]) goto L5067f4;  // @72_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @73_5066e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @75_5066e0
  ecx = edx = 0;  // @76_5066e0
  PV[2] = (u32)(eax);  // @77_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @78_5066e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @79_5066e0
  ecx = edx = 0;  // @80_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @81_5066e0
  FL[2] = (eax & eax);  // @82_5066e0
  if (FL[2] == 0) goto L5067f3;  // @83_5066e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @84_5066e0
  ecx = edx = 0;  // @85_5066e0
  goto L5067f4;  // @86_5066e0
  L5067f3:;
  __builtin_trap();  // @88_5066e0
  L5067f4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @90_5066e0
  X0[1] = 0;  // @91_5066e0
  X0[2] = 0;  // @92_5066e0
  X0[3] = 0;  // @93_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @94_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @95_5066e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @96_5066e0
  X0[1] = 0;  // @97_5066e0
  X0[2] = 0;  // @98_5066e0
  X0[3] = 0;  // @99_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @100_5066e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @101_5066e0
  X0[1] = 0;  // @102_5066e0
  X0[2] = 0;  // @103_5066e0
  X0[3] = 0;  // @104_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @105_5066e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(5));  // @106_5066e0
  ecx = edx = 0;  // @107_5066e0
  edi = eax;  // @108_5066e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @109_5066e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @110_5066e0
  if (FL[2] == 0) goto L50685f;  // @111_5066e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @112_5066e0
  if (FL[0] == FL[1]) goto L50685f;  // @113_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @114_5066e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @116_5066e0
  ecx = edx = 0;  // @117_5066e0
  PV[3] = (u32)(eax);  // @118_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @119_5066e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @120_5066e0
  ecx = edx = 0;  // @121_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @122_5066e0
  FL[2] = (eax & eax);  // @123_5066e0
  if (FL[2] == 0) goto L50685e;  // @124_5066e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @125_5066e0
  ecx = edx = 0;  // @126_5066e0
  goto L50685f;  // @127_5066e0
  L50685e:;
  __builtin_trap();  // @129_5066e0
  L50685f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @131_5066e0
  X0[1] = 0;  // @132_5066e0
  X0[2] = 0;  // @133_5066e0
  X0[3] = 0;  // @134_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @135_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @136_5066e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @137_5066e0
  ecx = edx = 0;  // @138_5066e0
  edi = eax;  // @139_5066e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @140_5066e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @141_5066e0
  if (FL[2] == 0) goto L5068b6;  // @142_5066e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @143_5066e0
  if (FL[0] == FL[1]) goto L5068b6;  // @144_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @145_5066e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @147_5066e0
  ecx = edx = 0;  // @148_5066e0
  PV[4] = (u32)(eax);  // @149_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @150_5066e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6932144), (u32)(6932792));  // @151_5066e0
  ecx = edx = 0;  // @152_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @153_5066e0
  FL[2] = (eax & eax);  // @154_5066e0
  if (FL[2] == 0) goto L5068b5;  // @155_5066e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @156_5066e0
  ecx = edx = 0;  // @157_5066e0
  goto L5068b6;  // @158_5066e0
  L5068b5:;
  __builtin_trap();  // @160_5066e0
  L5068b6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @162_5066e0
  X0[1] = 0;  // @163_5066e0
  X0[2] = 0;  // @164_5066e0
  X0[3] = 0;  // @165_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @166_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @167_5066e0
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @168_5066e0
  ecx = edx = 0;  // @169_5066e0
  esi = eax;  // @170_5066e0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @171_5066e0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @172_5066e0
  if (FL[2] == 0) goto L50690d;  // @173_5066e0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @174_5066e0
  if (FL[0] == FL[1]) goto L50690d;  // @175_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @176_5066e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @178_5066e0
  ecx = edx = 0;  // @179_5066e0
  PV[5] = (u32)(eax);  // @180_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @181_5066e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6932144), (u32)(6932792));  // @182_5066e0
  ecx = edx = 0;  // @183_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @184_5066e0
  FL[2] = (eax & eax);  // @185_5066e0
  if (FL[2] == 0) goto L50690c;  // @186_5066e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @187_5066e0
  ecx = edx = 0;  // @188_5066e0
  goto L50690d;  // @189_5066e0
  L50690c:;
  __builtin_trap();  // @191_5066e0
  L50690d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @193_5066e0
  X0[1] = 0;  // @194_5066e0
  X0[2] = 0;  // @195_5066e0
  X0[3] = 0;  // @196_5066e0
  edx = (u32)(EBP - 16);  // @197_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @198_5066e0
  ecx = (u32)(EBP - 64);  // @199_5066e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @200_5066e0
  X0[1] = 0;  // @201_5066e0
  X0[2] = 0;  // @202_5066e0
  X0[3] = 0;  // @203_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @204_5066e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @205_5066e0
  X0[1] = 0;  // @206_5066e0
  X0[2] = 0;  // @207_5066e0
  X0[3] = 0;  // @208_5066e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @209_5066e0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @210_5066e0
  ecx = edx = 0;  // @211_5066e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @212_5066e0
  edx = (u32)(EBP - 28);  // @213_5066e0
  PV[6] = (u32)(edx);  // @214_5066e0
  edx = (u32)(EBP - 64);  // @215_5066e0
  PV[7] = (u32)(edx);  // @216_5066e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @217_5066e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 880)))(ecx, PV[7], PV[6]);  // @218_5066e0
  ecx = edx = 0;  // @219_5066e0
  ext_633654(G(u32, 0x6f5630));  // @220_5066e0
  return eax;  // @221_5066e0
}
PCREG(5066e0, lifted_5066e0);

extern "C" u32 THISCALL lifted_5747e0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5747e0
  edx = ecx;  // @1_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5747e0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 444), sizeof v); (u32)v; });  // @3_5747e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @4_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @6_5747e0
  ecx = edx = 0;  // @7_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_5747e0
  ebx = eax;  // @9_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @10_5747e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_5747e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_5747e0
  ecx = ebx;  // @13_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edi + 32)))(ecx);  // @14_5747e0
  ecx = edx = 0;  // @15_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_5747e0
  PV[1] = (u32)(eax);  // @17_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @18_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[1]);  // @19_5747e0
  ecx = edx = 0;  // @20_5747e0
  PV[2] = (u32)(eax);  // @21_5747e0
  ecx = ebx;  // @22_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 636)))(ecx, PV[2]);  // @23_5747e0
  ecx = edx = 0;  // @24_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_5747e0
  ecx = ebx;  // @26_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @27_5747e0
  ecx = edx = 0;  // @28_5747e0
  ecx = ebx;  // @29_5747e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) | (u32)(1024))); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @30_5747e0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @31_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_5747e0
  { u32 v = (u32)((u32)(2719744)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @33_5747e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @34_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 596)))(ecx);  // @35_5747e0
  ecx = edx = 0;  // @36_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @37_5747e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @38_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @39_5747e0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 440), sizeof v); (u32)v; });  // @40_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @42_5747e0
  ecx = edx = 0;  // @43_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_5747e0
  ebx = eax;  // @45_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @46_5747e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_5747e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_5747e0
  ecx = ebx;  // @49_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edi + 32)))(ecx);  // @50_5747e0
  ecx = edx = 0;  // @51_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_5747e0
  PV[4] = (u32)(eax);  // @53_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @54_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[4]);  // @55_5747e0
  ecx = edx = 0;  // @56_5747e0
  PV[5] = (u32)(eax);  // @57_5747e0
  ecx = ebx;  // @58_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 636)))(ecx, PV[5]);  // @59_5747e0
  ecx = edx = 0;  // @60_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_5747e0
  ecx = ebx;  // @62_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @63_5747e0
  ecx = edx = 0;  // @64_5747e0
  ecx = ebx;  // @65_5747e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) | (u32)(1024))); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @66_5747e0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @67_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_5747e0
  { u32 v = (u32)((u32)(2719744)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @69_5747e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @70_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 596)))(ecx);  // @71_5747e0
  ecx = edx = 0;  // @72_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_5747e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @74_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @75_5747e0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 448), sizeof v); (u32)v; });  // @76_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[6]);  // @78_5747e0
  ecx = edx = 0;  // @79_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @80_5747e0
  ebx = eax;  // @81_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @82_5747e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @83_5747e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_5747e0
  ecx = ebx;  // @85_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edi + 32)))(ecx);  // @86_5747e0
  ecx = edx = 0;  // @87_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_5747e0
  PV[7] = (u32)(eax);  // @89_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @90_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[7]);  // @91_5747e0
  ecx = edx = 0;  // @92_5747e0
  PV[8] = (u32)(eax);  // @93_5747e0
  ecx = ebx;  // @94_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 636)))(ecx, PV[8]);  // @95_5747e0
  ecx = edx = 0;  // @96_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @97_5747e0
  ecx = ebx;  // @98_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @99_5747e0
  ecx = edx = 0;  // @100_5747e0
  ecx = ebx;  // @101_5747e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) | (u32)(1024))); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @102_5747e0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @103_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_5747e0
  { u32 v = (u32)((u32)(2719744)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @105_5747e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @106_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 596)))(ecx);  // @107_5747e0
  ecx = edx = 0;  // @108_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_5747e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @110_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @111_5747e0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 452), sizeof v); (u32)v; });  // @112_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[9]);  // @114_5747e0
  ecx = edx = 0;  // @115_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_5747e0
  ebx = eax;  // @117_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @118_5747e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_5747e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_5747e0
  ecx = ebx;  // @121_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edi + 32)))(ecx);  // @122_5747e0
  ecx = edx = 0;  // @123_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_5747e0
  PV[10] = (u32)(eax);  // @125_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @126_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[10]);  // @127_5747e0
  ecx = edx = 0;  // @128_5747e0
  PV[11] = (u32)(eax);  // @129_5747e0
  ecx = ebx;  // @130_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 636)))(ecx, PV[11]);  // @131_5747e0
  ecx = edx = 0;  // @132_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @133_5747e0
  ecx = ebx;  // @134_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @135_5747e0
  ecx = edx = 0;  // @136_5747e0
  ecx = ebx;  // @137_5747e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; }) | (u32)(1024))); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @138_5747e0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @139_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_5747e0
  { u32 v = (u32)((u32)(2686976)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @141_5747e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @142_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 596)))(ecx);  // @143_5747e0
  ecx = edx = 0;  // @144_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806028) + 0), 4); v; });  // @146_5747e0
  X0[1] = 0;  // @147_5747e0
  X0[2] = 0;  // @148_5747e0
  X0[3] = 0;  // @149_5747e0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @150_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6957812) + 0), 4); v; });  // @151_5747e0
  X0[1] = 0;  // @152_5747e0
  X0[2] = 0;  // @153_5747e0
  X0[3] = 0;  // @154_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_5747e0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @156_5747e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @157_5747e0
  ecx = edx = 0;  // @158_5747e0
  ecx = eax;  // @159_5747e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @160_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 220), sizeof v); (u32)v; });  // @161_5747e0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @162_5747e0
  ecx = edx = 0;  // @163_5747e0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @164_5747e0
  if (FL[2] == 0) goto L574a03;  // @165_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6983996) + 0), 4); v; });  // @166_5747e0
  X0[1] = 0;  // @167_5747e0
  X0[2] = 0;  // @168_5747e0
  X0[3] = 0;  // @169_5747e0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @170_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6983992) + 0), 4); v; });  // @171_5747e0
  X0[1] = 0;  // @172_5747e0
  X0[2] = 0;  // @173_5747e0
  X0[3] = 0;  // @174_5747e0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @175_5747e0
  L574a03:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @177_5747e0
  eax = (u32)(EBP - 28);  // @178_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @179_5747e0
  X0[1] = 0;  // @180_5747e0
  X0[2] = 0;  // @181_5747e0
  X0[3] = 0;  // @182_5747e0
  PV[12] = (u32)(ecx);  // @183_5747e0
  PV[13] = (u32)(eax);  // @184_5747e0
  PV[14] = (u32)(ecx);  // @185_5747e0
  PV[15] = X0[0];  // @186_5747e0
  ecx = ebx;  // @187_5747e0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 484), sizeof v); (u32)v; });  // @188_5747e0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 448), sizeof v); (u32)v; });  // @189_5747e0
  eax = ext_574680_stdcall5(PV[17], PV[16], PV[15], PV[13], (u32)(3212836864));  // @190_5747e0
  ecx = edx = 0;  // @191_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @192_5747e0
  X0[1] = 0;  // @193_5747e0
  X0[2] = 0;  // @194_5747e0
  X0[3] = 0;  // @195_5747e0
  eax = (u32)(ebx + 498);  // @196_5747e0
  PV[18] = (u32)(ecx);  // @197_5747e0
  PV[19] = (u32)(eax);  // @198_5747e0
  PV[20] = (u32)(ecx);  // @199_5747e0
  PV[21] = X0[0];  // @200_5747e0
  ecx = ebx;  // @201_5747e0
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 468), sizeof v); (u32)v; });  // @202_5747e0
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 452), sizeof v); (u32)v; });  // @203_5747e0
  eax = ext_574680_stdcall5(PV[23], PV[22], PV[21], PV[19], (u32)(3212836864));  // @204_5747e0
  ecx = edx = 0;  // @205_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @206_5747e0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 452), sizeof v); (u32)v; });  // @207_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @208_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[24]);  // @210_5747e0
  ecx = edx = 0;  // @211_5747e0
  esi = eax;  // @212_5747e0
  eax = (u32)(EBP - 16);  // @213_5747e0
  PV[25] = (u32)(eax);  // @214_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @215_5747e0
  eax = ext_4db500_thiscall2(ecx, PV[25]);  // @216_5747e0
  ecx = edx = 0;  // @217_5747e0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 506) + 0), 4); v; });  // @218_5747e0
  X1[1] = 0;  // @219_5747e0
  X1[2] = 0;  // @220_5747e0
  X1[3] = 0;  // @221_5747e0
  ecx = (u32)(EBP - 16);  // @222_5747e0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896928) + 0), 4); v; })));  // @223_5747e0
  PV[26] = (u32)(ecx);  // @224_5747e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @225_5747e0
  X0[1] = 0;  // @226_5747e0
  X0[2] = 0;  // @227_5747e0
  X0[3] = 0;  // @228_5747e0
  ecx = esi;  // @229_5747e0
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @230_5747e0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @231_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @232_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[26]);  // @233_5747e0
  ecx = edx = 0;  // @234_5747e0
  ecx = ebx;  // @235_5747e0
  eax = ext_562390_thiscall1(ecx);  // @236_5747e0
  ecx = edx = 0;  // @237_5747e0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 248), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @238_5747e0
  if (FL[0] == FL[1]) goto L574adc;  // @239_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @240_5747e0
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 440), sizeof v); (u32)v; });  // @241_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @242_5747e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @243_5747e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[27]);  // @244_5747e0
  ecx = edx = 0;  // @245_5747e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 248), sizeof v); (u32)v; });  // @246_5747e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 2202), &v, sizeof v); }  // @247_5747e0
  L574adc:;
  ext_633654(G(u32, 0x6f5630));  // @249_5747e0
  return eax;  // @250_5747e0
}
PCREG(5747e0, lifted_5747e0);

extern "C" u32 THISCALL lifted_506be0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_506be0
  edi = ecx;  // @1_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @2_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @3_506be0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1576) + 0), 4); v; });  // @4_506be0
  X0[1] = 0;  // @5_506be0
  X0[2] = 0;  // @6_506be0
  X0[3] = 0;  // @7_506be0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @8_506be0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @9_506be0
  ecx = edx = 0;  // @10_506be0
  esi = eax;  // @11_506be0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @12_506be0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @13_506be0
  if (FL[2] == 0) goto L506c4a;  // @14_506be0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @15_506be0
  if (FL[0] == FL[1]) goto L506c4a;  // @16_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @17_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_506be0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @19_506be0
  ecx = edx = 0;  // @20_506be0
  PV[0] = (u32)(eax);  // @21_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_506be0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @23_506be0
  ecx = edx = 0;  // @24_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @25_506be0
  FL[2] = (eax & eax);  // @26_506be0
  if (FL[2] == 0) goto L506c49;  // @27_506be0
  eax = ((u32(STDCALL *)(void))(eax))();  // @28_506be0
  ecx = edx = 0;  // @29_506be0
  goto L506c4a;  // @30_506be0
  L506c49:;
  __builtin_trap();  // @32_506be0
  L506c4a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @34_506be0
  X0[1] = 0;  // @35_506be0
  X0[2] = 0;  // @36_506be0
  X0[3] = 0;  // @37_506be0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @38_506be0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @39_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @40_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @41_506be0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1580) + 0), 4); v; });  // @42_506be0
  X0[1] = 0;  // @43_506be0
  X0[2] = 0;  // @44_506be0
  X0[3] = 0;  // @45_506be0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @46_506be0
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @47_506be0
  ecx = edx = 0;  // @48_506be0
  esi = eax;  // @49_506be0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @50_506be0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @51_506be0
  if (FL[2] == 0) goto L506cb5;  // @52_506be0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @53_506be0
  if (FL[0] == FL[1]) goto L506cb5;  // @54_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @55_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_506be0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @57_506be0
  ecx = edx = 0;  // @58_506be0
  PV[1] = (u32)(eax);  // @59_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_506be0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6932144), (u32)(6932792));  // @61_506be0
  ecx = edx = 0;  // @62_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @63_506be0
  FL[2] = (eax & eax);  // @64_506be0
  if (FL[2] == 0) goto L506cb4;  // @65_506be0
  eax = ((u32(STDCALL *)(void))(eax))();  // @66_506be0
  ecx = edx = 0;  // @67_506be0
  goto L506cb5;  // @68_506be0
  L506cb4:;
  __builtin_trap();  // @70_506be0
  L506cb5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @72_506be0
  X0[1] = 0;  // @73_506be0
  X0[2] = 0;  // @74_506be0
  X0[3] = 0;  // @75_506be0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @76_506be0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @77_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @78_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @79_506be0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1584) + 0), 4); v; });  // @80_506be0
  X0[1] = 0;  // @81_506be0
  X0[2] = 0;  // @82_506be0
  X0[3] = 0;  // @83_506be0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @84_506be0
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @85_506be0
  ecx = edx = 0;  // @86_506be0
  esi = eax;  // @87_506be0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @88_506be0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @89_506be0
  if (FL[2] == 0) goto L506d20;  // @90_506be0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @91_506be0
  if (FL[0] == FL[1]) goto L506d20;  // @92_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @93_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_506be0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @95_506be0
  ecx = edx = 0;  // @96_506be0
  PV[2] = (u32)(eax);  // @97_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @98_506be0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @99_506be0
  ecx = edx = 0;  // @100_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @101_506be0
  FL[2] = (eax & eax);  // @102_506be0
  if (FL[2] == 0) goto L506d1f;  // @103_506be0
  eax = ((u32(STDCALL *)(void))(eax))();  // @104_506be0
  ecx = edx = 0;  // @105_506be0
  goto L506d20;  // @106_506be0
  L506d1f:;
  __builtin_trap();  // @108_506be0
  L506d20:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @110_506be0
  X0[1] = 0;  // @111_506be0
  X0[2] = 0;  // @112_506be0
  X0[3] = 0;  // @113_506be0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @114_506be0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @115_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @116_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @117_506be0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1588) + 0), 4); v; });  // @118_506be0
  X0[1] = 0;  // @119_506be0
  X0[2] = 0;  // @120_506be0
  X0[3] = 0;  // @121_506be0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @122_506be0
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @123_506be0
  ecx = edx = 0;  // @124_506be0
  esi = eax;  // @125_506be0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @126_506be0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @127_506be0
  if (FL[2] == 0) goto L506d8b;  // @128_506be0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @129_506be0
  if (FL[0] == FL[1]) goto L506d8b;  // @130_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @131_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_506be0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @133_506be0
  ecx = edx = 0;  // @134_506be0
  PV[3] = (u32)(eax);  // @135_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @136_506be0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @137_506be0
  ecx = edx = 0;  // @138_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @139_506be0
  FL[2] = (eax & eax);  // @140_506be0
  if (FL[2] == 0) goto L506d8a;  // @141_506be0
  eax = ((u32(STDCALL *)(void))(eax))();  // @142_506be0
  ecx = edx = 0;  // @143_506be0
  goto L506d8b;  // @144_506be0
  L506d8a:;
  __builtin_trap();  // @146_506be0
  L506d8b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @148_506be0
  X0[1] = 0;  // @149_506be0
  X0[2] = 0;  // @150_506be0
  X0[3] = 0;  // @151_506be0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @152_506be0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @153_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @154_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @155_506be0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1592) + 0), 4); v; });  // @156_506be0
  X0[1] = 0;  // @157_506be0
  X0[2] = 0;  // @158_506be0
  X0[3] = 0;  // @159_506be0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @160_506be0
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @161_506be0
  ecx = edx = 0;  // @162_506be0
  esi = eax;  // @163_506be0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @164_506be0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @165_506be0
  if (FL[2] == 0) goto L506df6;  // @166_506be0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @167_506be0
  if (FL[0] == FL[1]) goto L506df6;  // @168_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @169_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_506be0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @171_506be0
  ecx = edx = 0;  // @172_506be0
  PV[4] = (u32)(eax);  // @173_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @174_506be0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6932144), (u32)(6932792));  // @175_506be0
  ecx = edx = 0;  // @176_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @177_506be0
  FL[2] = (eax & eax);  // @178_506be0
  if (FL[2] == 0) goto L506df5;  // @179_506be0
  eax = ((u32(STDCALL *)(void))(eax))();  // @180_506be0
  ecx = edx = 0;  // @181_506be0
  goto L506df6;  // @182_506be0
  L506df5:;
  __builtin_trap();  // @184_506be0
  L506df6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @186_506be0
  X0[1] = 0;  // @187_506be0
  X0[2] = 0;  // @188_506be0
  X0[3] = 0;  // @189_506be0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @190_506be0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @191_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @192_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @193_506be0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1596) + 0), 4); v; });  // @194_506be0
  X0[1] = 0;  // @195_506be0
  X0[2] = 0;  // @196_506be0
  X0[3] = 0;  // @197_506be0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @198_506be0
  eax = ext_5003d0_thiscall2(ecx, (u32)(5));  // @199_506be0
  ecx = edx = 0;  // @200_506be0
  esi = eax;  // @201_506be0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @202_506be0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @203_506be0
  if (FL[2] == 0) goto L506e60;  // @204_506be0
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @205_506be0
  if (FL[0] == FL[1]) goto L506e60;  // @206_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @207_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @208_506be0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @209_506be0
  ecx = edx = 0;  // @210_506be0
  PV[5] = (u32)(eax);  // @211_506be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @212_506be0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6932144), (u32)(6932792));  // @213_506be0
  ecx = edx = 0;  // @214_506be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @215_506be0
  FL[2] = (eax & eax);  // @216_506be0
  if (FL[2] == 0) goto L506e5f;  // @217_506be0
  eax = ((u32(STDCALL *)(void))(eax))();  // @218_506be0
  ecx = edx = 0;  // @219_506be0
  goto L506e60;  // @220_506be0
  L506e5f:;
  __builtin_trap();  // @222_506be0
  L506e60:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @224_506be0
  X0[1] = 0;  // @225_506be0
  X0[2] = 0;  // @226_506be0
  X0[3] = 0;  // @227_506be0
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @228_506be0
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @229_506be0
  return eax;  // @230_506be0
}
PCREG(506be0, lifted_506be0);

extern "C" u32 THISCALL lifted_44ead0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_44ead0
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_44ead0
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @2_44ead0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @3_44ead0
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_44ead0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_44ead0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @6_44ead0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @7_44ead0
  L44eb12:;
  FL[2] = (edi & edi);  // @9_44ead0
  if (FL[2] == 0) goto L44eb79;  // @10_44ead0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @11_44ead0
  FL[2] = (esi & esi);  // @12_44ead0
  if (FL[2] == 0) goto L44eb25;  // @13_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @14_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @15_44ead0
  goto L44eb2a;  // @16_44ead0
  L44eb25:;
  eax = (u32)(2097154);  // @18_44ead0
  L44eb2a:;
  FL[2] = (eax & (u32)(1048576));  // @20_44ead0
  if (FL[2] == 0) goto L44eb79;  // @21_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @22_44ead0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(1048616);  // @23_44ead0
  if (FL[0] != FL[1]) goto L44eb74;  // @24_44ead0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @25_44ead0
  ecx = (u32)(EBP - 52);  // @26_44ead0
  PV[0] = (u32)(edx);  // @27_44ead0
  edx = (edx + (u32)(48));  // @28_44ead0
  FL[3] = edx;  // @29_44ead0
  eax = ext_441970_fastcall3(ecx, edx, PV[0]);  // @30_44ead0
  ecx = edx = 0;  // @31_44ead0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_44ead0
  ecx = (u32)(EBP - 52);  // @33_44ead0
  edx = (edx + (u32)(36));  // @34_44ead0
  FL[3] = edx;  // @35_44ead0
  eax = ext_441940_fastcall2(ecx, edx);  // @36_44ead0
  ecx = edx = 0;  // @37_44ead0
  edx = (u32)(EBP - 52);  // @38_44ead0
  ecx = (u32)(EBP - 28);  // @39_44ead0
  eax = ext_4e08d0_fastcall2(ecx, edx);  // @40_44ead0
  ecx = edx = 0;  // @41_44ead0
  edx = (u32)(EBP - 52);  // @42_44ead0
  ecx = (u32)(EBP - 16);  // @43_44ead0
  eax = ext_4e0900_fastcall2(ecx, edx);  // @44_44ead0
  ecx = edx = 0;  // @45_44ead0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 124), &v, sizeof v); }  // @46_44ead0
  L44eb74:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @48_44ead0
  goto L44eb12;  // @49_44ead0
  L44eb79:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @51_44ead0
  if (FL[0] == FL[1]) goto L44edb5;  // @52_44ead0
  eax = (u32)(EBP - 16);  // @53_44ead0
  PV[1] = (u32)(eax);  // @54_44ead0
  edx = (u32)(EBP - 28);  // @55_44ead0
  ecx = (u32)(EBP - 64);  // @56_44ead0
  eax = ext_43e920_fastcall3(ecx, edx, PV[1]);  // @57_44ead0
  ecx = edx = 0;  // @58_44ead0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @59_44ead0
  PV[2] = (u32)(ecx);  // @60_44ead0
  edx = (edx + (u32)(64));  // @61_44ead0
  FL[3] = edx;  // @62_44ead0
  ecx = (u32)(EBP - 40);  // @63_44ead0
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1056964608));  // @64_44ead0
  ecx = edx = 0;  // @65_44ead0
  edx = (u32)(EBP - 40);  // @66_44ead0
  ecx = (u32)(EBP - 64);  // @67_44ead0
  eax = ext_4e08d0_fastcall2(ecx, edx);  // @68_44ead0
  ecx = edx = 0;  // @69_44ead0
  PV[3] = (u32)(ecx);  // @70_44ead0
  ecx = (u32)(EBP - 64);  // @71_44ead0
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @72_44ead0
  ecx = edx = 0;  // @73_44ead0
  PV[4] = (u32)(ecx);  // @74_44ead0
  edx = (u32)(EBP - 64);  // @75_44ead0
  ecx = (u32)(EBP - 40);  // @76_44ead0
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1060320051));  // @77_44ead0
  ecx = edx = 0;  // @78_44ead0
  ecx = (u32)(ebx + 92);  // @79_44ead0
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @80_44ead0
  edx = (u32)(EBP - 40);  // @81_44ead0
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @82_44ead0
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @83_44ead0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @84_44ead0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @85_44ead0
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @86_44ead0
  eax = ext_4e09e0_fastcall2(ecx, edx);  // @87_44ead0
  ecx = edx = 0;  // @88_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @89_44ead0
  X0[1] = 0;  // @90_44ead0
  X0[2] = 0;  // @91_44ead0
  X0[3] = 0;  // @92_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 104) + 0), &X0[0], 4);  // @93_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @94_44ead0
  X0[1] = 0;  // @95_44ead0
  X0[2] = 0;  // @96_44ead0
  X0[3] = 0;  // @97_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 108) + 0), &X0[0], 4);  // @98_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @99_44ead0
  X0[1] = 0;  // @100_44ead0
  X0[2] = 0;  // @101_44ead0
  X0[3] = 0;  // @102_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 112) + 0), &X0[0], 4);  // @103_44ead0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @104_44ead0
  L44ec30:;
  FL[2] = (edi & edi);  // @106_44ead0
  if (FL[2] == 0) goto L44ed79;  // @107_44ead0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @108_44ead0
  FL[2] = (esi & esi);  // @109_44ead0
  if (FL[2] == 0) goto L44ec47;  // @110_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @111_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @112_44ead0
  goto L44ec4c;  // @113_44ead0
  L44ec47:;
  eax = (u32)(2097154);  // @115_44ead0
  L44ec4c:;
  FL[2] = (eax & (u32)(1048576));  // @117_44ead0
  if (FL[2] == 0) goto L44ed79;  // @118_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @119_44ead0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(1048616);  // @120_44ead0
  if (FL[0] != FL[1]) goto L44ed71;  // @121_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @122_44ead0
  edx = (u32)(EBP - 40);  // @123_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @124_44ead0
  X0[1] = 0;  // @125_44ead0
  X0[2] = 0;  // @126_44ead0
  X0[3] = 0;  // @127_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @128_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @129_44ead0
  X0[1] = 0;  // @130_44ead0
  X0[2] = 0;  // @131_44ead0
  X0[3] = 0;  // @132_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @133_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @134_44ead0
  X0[1] = 0;  // @135_44ead0
  X0[2] = 0;  // @136_44ead0
  X0[3] = 0;  // @137_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @138_44ead0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @139_44ead0
  eax = ext_4e2c60_fastcall2(ecx, edx);  // @140_44ead0
  ecx = edx = 0;  // @141_44ead0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @142_44ead0
  ecx = (u32)(EBP - 52);  // @143_44ead0
  PV[5] = (u32)(edx);  // @144_44ead0
  edx = (edx + (u32)(48));  // @145_44ead0
  FL[3] = edx;  // @146_44ead0
  eax = ext_441970_fastcall3(ecx, edx, PV[5]);  // @147_44ead0
  ecx = edx = 0;  // @148_44ead0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @149_44ead0
  ecx = (u32)(EBP - 52);  // @150_44ead0
  edx = (edx + (u32)(36));  // @151_44ead0
  FL[3] = edx;  // @152_44ead0
  eax = ext_441940_fastcall2(ecx, edx);  // @153_44ead0
  ecx = edx = 0;  // @154_44ead0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @155_44ead0
  ecx = (u32)(EBP - 52);  // @156_44ead0
  edx = (edx + (u32)(48));  // @157_44ead0
  FL[3] = edx;  // @158_44ead0
  eax = ext_43e960_fastcall2(ecx, edx);  // @159_44ead0
  ecx = edx = 0;  // @160_44ead0
  eax = (u32)(EBP - 40);  // @161_44ead0
  PV[6] = (u32)(eax);  // @162_44ead0
  edx = (u32)(EBP - 52);  // @163_44ead0
  ecx = (u32)(EBP - 76);  // @164_44ead0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[6]);  // @165_44ead0
  ecx = edx = 0;  // @166_44ead0
  eax = (u32)(EBP - 40);  // @167_44ead0
  PV[7] = (u32)(eax);  // @168_44ead0
  edx = (u32)(EBP - 52);  // @169_44ead0
  ecx = (u32)(EBP - 88);  // @170_44ead0
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @171_44ead0
  ecx = edx = 0;  // @172_44ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @173_44ead0
  ecx = (u32)(EBP - 52);  // @174_44ead0
  PV[8] = (u32)(ecx);  // @175_44ead0
  ecx = ebx;  // @176_44ead0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 708)))(ecx, PV[8]);  // @177_44ead0
  ecx = edx = 0;  // @178_44ead0
  FL[2] = ((eax & 0xff) & (u32)(1));  // @179_44ead0
  if (FL[2] == 0) goto L44ecfe;  // @180_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @181_44ead0
  X0[1] = 0;  // @182_44ead0
  X0[2] = 0;  // @183_44ead0
  X0[3] = 0;  // @184_44ead0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; }))))))) goto L44ecfe;  // @185_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @186_44ead0
  L44ecfe:;
  FL[2] = ((eax & 0xff) & (u32)(2));  // @188_44ead0
  if (FL[2] == 0) goto L44ed16;  // @189_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @190_44ead0
  X0[1] = 0;  // @191_44ead0
  X0[2] = 0;  // @192_44ead0
  X0[3] = 0;  // @193_44ead0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @194_44ead0
  X1[1] = 0;  // @195_44ead0
  X1[2] = 0;  // @196_44ead0
  X1[3] = 0;  // @197_44ead0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L44ed16;  // @198_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X1[0], 4);  // @199_44ead0
  L44ed16:;
  FL[2] = ((eax & 0xff) & (u32)(4));  // @201_44ead0
  if (FL[2] == 0) goto L44ed2a;  // @202_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @203_44ead0
  X0[1] = 0;  // @204_44ead0
  X0[2] = 0;  // @205_44ead0
  X0[3] = 0;  // @206_44ead0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; }))))))) goto L44ed2a;  // @207_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @208_44ead0
  L44ed2a:;
  FL[2] = ((eax & 0xff) & (u32)(8));  // @210_44ead0
  if (FL[2] == 0) goto L44ed42;  // @211_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @212_44ead0
  X0[1] = 0;  // @213_44ead0
  X0[2] = 0;  // @214_44ead0
  X0[3] = 0;  // @215_44ead0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @216_44ead0
  X1[1] = 0;  // @217_44ead0
  X1[2] = 0;  // @218_44ead0
  X1[3] = 0;  // @219_44ead0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L44ed42;  // @220_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X1[0], 4);  // @221_44ead0
  L44ed42:;
  FL[2] = ((eax & 0xff) & (u32)(16));  // @223_44ead0
  if (FL[2] == 0) goto L44ed56;  // @224_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @225_44ead0
  X0[1] = 0;  // @226_44ead0
  X0[2] = 0;  // @227_44ead0
  X0[3] = 0;  // @228_44ead0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; }))))))) goto L44ed56;  // @229_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @230_44ead0
  L44ed56:;
  FL[2] = ((eax & 0xff) & (u32)(32));  // @232_44ead0
  if (FL[2] == 0) goto L44ed6e;  // @233_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @234_44ead0
  X0[1] = 0;  // @235_44ead0
  X0[2] = 0;  // @236_44ead0
  X0[3] = 0;  // @237_44ead0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @238_44ead0
  X1[1] = 0;  // @239_44ead0
  X1[2] = 0;  // @240_44ead0
  X1[3] = 0;  // @241_44ead0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L44ed6e;  // @242_44ead0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X1[0], 4);  // @243_44ead0
  L44ed6e:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @245_44ead0
  L44ed71:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @247_44ead0
  goto L44ec30;  // @248_44ead0
  L44ed79:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @250_44ead0
  X0[1] = 0;  // @251_44ead0
  X0[2] = 0;  // @252_44ead0
  X0[3] = 0;  // @253_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 92) + 0), &X0[0], 4);  // @254_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @255_44ead0
  X0[1] = 0;  // @256_44ead0
  X0[2] = 0;  // @257_44ead0
  X0[3] = 0;  // @258_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 96) + 0), &X0[0], 4);  // @259_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @260_44ead0
  X0[1] = 0;  // @261_44ead0
  X0[2] = 0;  // @262_44ead0
  X0[3] = 0;  // @263_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 100) + 0), &X0[0], 4);  // @264_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @265_44ead0
  X0[1] = 0;  // @266_44ead0
  X0[2] = 0;  // @267_44ead0
  X0[3] = 0;  // @268_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 104) + 0), &X0[0], 4);  // @269_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @270_44ead0
  X0[1] = 0;  // @271_44ead0
  X0[2] = 0;  // @272_44ead0
  X0[3] = 0;  // @273_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 108) + 0), &X0[0], 4);  // @274_44ead0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @275_44ead0
  X0[1] = 0;  // @276_44ead0
  X0[2] = 0;  // @277_44ead0
  X0[3] = 0;  // @278_44ead0
  __builtin_memcpy((void *)((u32)(ebx + 112) + 0), &X0[0], 4);  // @279_44ead0
  L44edb5:;
  ext_633654(G(u32, 0x6f5630));  // @281_44ead0
  return eax;  // @282_44ead0
}
PCREG(44ead0, lifted_44ead0);

extern "C" u32 STDCALL lifted_50cd60(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_50cd60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @1_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @2_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_50cd60
  ecx = edx = 0;  // @4_50cd60
  ecx = eax;  // @5_50cd60
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @6_50cd60
  ecx = edx = 0;  // @7_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @8_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @9_50cd60
  ecx = edx = 0;  // @10_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_50cd60
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @13_50cd60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[0]);  // @15_50cd60
  ecx = edx = 0;  // @16_50cd60
  ebx = eax;  // @17_50cd60
  FL[2] = (ebx & ebx);  // @18_50cd60
  if (FL[2] != 0) goto L50cde3;  // @19_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @20_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_50cd60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6935584), (u32)(605));  // @22_50cd60
  ecx = edx = 0;  // @23_50cd60
  PV[1] = (u32)(eax);  // @24_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @25_50cd60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6936448));  // @26_50cd60
  ecx = edx = 0;  // @27_50cd60
  ext_633654(G(u32, 0x6f5630));  // @28_50cd60
  return eax;  // @29_50cd60
  L50cde3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_50cd60
  ecx = ebx;  // @32_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @33_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050577));  // @34_50cd60
  ecx = edx = 0;  // @35_50cd60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @36_50cd60
  if (FL[2] != 0) goto L50ce30;  // @37_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @38_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_50cd60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6935584), (u32)(610));  // @40_50cd60
  ecx = edx = 0;  // @41_50cd60
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @42_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @43_50cd60
  PV[3] = (u32)(eax);  // @44_50cd60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6936060), PV[2]);  // @45_50cd60
  ecx = edx = 0;  // @46_50cd60
  ext_633654(G(u32, 0x6f5630));  // @47_50cd60
  return eax;  // @48_50cd60
  L50ce30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @50_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @51_50cd60
  ecx = edx = 0;  // @52_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_50cd60
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @55_50cd60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[4]);  // @57_50cd60
  ecx = edx = 0;  // @58_50cd60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @59_50cd60
  FL[2] = (eax & eax);  // @60_50cd60
  if (FL[2] != 0) goto L50ce89;  // @61_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @62_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_50cd60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6935584), (u32)(616));  // @64_50cd60
  ecx = edx = 0;  // @65_50cd60
  PV[5] = (u32)(eax);  // @66_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @67_50cd60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6936480));  // @68_50cd60
  ecx = edx = 0;  // @69_50cd60
  ext_633654(G(u32, 0x6f5630));  // @70_50cd60
  return eax;  // @71_50cd60
  L50ce89:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @73_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(4));  // @74_50cd60
  ecx = edx = 0;  // @75_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @76_50cd60
  edi = eax;  // @77_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @78_50cd60
  ecx = edx = 0;  // @79_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @80_50cd60
  esi = eax;  // @81_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @82_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @83_50cd60
  ecx = edx = 0;  // @84_50cd60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @85_50cd60
  X1[1] = 0;  // @86_50cd60
  X1[2] = 0;  // @87_50cd60
  X1[3] = 0;  // @88_50cd60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @89_50cd60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @90_50cd60
  X2[1] = 0;  // @91_50cd60
  X2[2] = 0;  // @92_50cd60
  X2[3] = 0;  // @93_50cd60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @94_50cd60
  X0[1] = 0;  // @95_50cd60
  X0[2] = 0;  // @96_50cd60
  X0[3] = 0;  // @97_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @98_50cd60
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @99_50cd60
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X1[0], 4);  // @100_50cd60
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @101_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(7));  // @102_50cd60
  ecx = edx = 0;  // @103_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @104_50cd60
  edi = eax;  // @105_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(6));  // @106_50cd60
  ecx = edx = 0;  // @107_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @108_50cd60
  esi = eax;  // @109_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @110_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(5));  // @111_50cd60
  ecx = edx = 0;  // @112_50cd60
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @113_50cd60
  X1[1] = 0;  // @114_50cd60
  X1[2] = 0;  // @115_50cd60
  X1[3] = 0;  // @116_50cd60
  ecx = (u32)(EBP - 16);  // @117_50cd60
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @118_50cd60
  X2[1] = 0;  // @119_50cd60
  X2[2] = 0;  // @120_50cd60
  X2[3] = 0;  // @121_50cd60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @122_50cd60
  X0[1] = 0;  // @123_50cd60
  X0[2] = 0;  // @124_50cd60
  X0[3] = 0;  // @125_50cd60
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @126_50cd60
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @127_50cd60
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @128_50cd60
  eax = ext_44c840_thiscall1(ecx);  // @129_50cd60
  ecx = edx = 0;  // @130_50cd60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @131_50cd60
  ecx = (u32)(EBP - 28);  // @132_50cd60
  PV[6] = (u32)(ecx);  // @133_50cd60
  ecx = edi;  // @134_50cd60
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @135_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @136_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[6]);  // @137_50cd60
  ecx = edx = 0;  // @138_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @139_50cd60
  ecx = (u32)(EBP - 16);  // @140_50cd60
  PV[7] = (u32)(ecx);  // @141_50cd60
  ecx = edi;  // @142_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[7]);  // @143_50cd60
  ecx = edx = 0;  // @144_50cd60
  edx = (u32)(EBP - 16);  // @145_50cd60
  ecx = (u32)(EBP - 76);  // @146_50cd60
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @147_50cd60
  ecx = edx = 0;  // @148_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @149_50cd60
  eax = (u32)(EBP - 40);  // @150_50cd60
  PV[8] = (u32)(eax);  // @151_50cd60
  eax = ext_4db7c0_thiscall2(ecx, PV[8]);  // @152_50cd60
  ecx = edx = 0;  // @153_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @154_50cd60
  ecx = (u32)(EBP - 40);  // @155_50cd60
  PV[9] = (u32)(ecx);  // @156_50cd60
  ecx = ebx;  // @157_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[9]);  // @158_50cd60
  ecx = edx = 0;  // @159_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @160_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @161_50cd60
  eax = (eax >> (u32)(10));  // @162_50cd60
  FL[3] = eax;  // @163_50cd60
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @164_50cd60
  FL[2] = ((eax & 0xff) & (u32)(1));  // @165_50cd60
  if (FL[2] == 0) goto L50cf90;  // @166_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @167_50cd60
  ecx = edi;  // @168_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @169_50cd60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @170_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @171_50cd60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @172_50cd60
  ecx = edx = 0;  // @173_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @174_50cd60
  PV[10] = (u32)(eax);  // @175_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @176_50cd60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 76)))(ecx, PV[10]);  // @177_50cd60
  ecx = edx = 0;  // @178_50cd60
  L50cf90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @180_50cd60
  ecx = (u32)(EBP - 28);  // @181_50cd60
  PV[11] = (u32)(ecx);  // @182_50cd60
  ecx = (u32)(EBP - 76);  // @183_50cd60
  PV[12] = (u32)(ecx);  // @184_50cd60
  ecx = ebx;  // @185_50cd60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[12], PV[11]);  // @186_50cd60
  ecx = edx = 0;  // @187_50cd60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @188_50cd60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @189_50cd60
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @190_50cd60
  ecx = edx = 0;  // @191_50cd60
  ecx = eax;  // @192_50cd60
  eax = ext_5002f0_thiscall2(ecx, (u32)(1));  // @193_50cd60
  ecx = edx = 0;  // @194_50cd60
  ext_633654(G(u32, 0x6f5630));  // @195_50cd60
  return eax;  // @196_50cd60
}
PCREG(50cd60, lifted_50cd60);

extern "C" u32 THISCALL lifted_58a000(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_58a000
  ebx = ecx;  // @1_58a000
  ecx = (u32)(EBP - 260);  // @2_58a000
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @3_58a000
  PV[0] = (u32)(ecx);  // @4_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_58a000
  ecx = esi;  // @6_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[0]);  // @7_58a000
  ecx = edx = 0;  // @8_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @9_58a000
  FL[2] = (eax & eax);  // @10_58a000
  if (FL[2] == 0) goto L58a086;  // @11_58a000
  L58a040:;
  eax = (eax - 1);  // @13_58a000
  FL[3] = eax;  // @14_58a000
  ecx = (u32)(EBP - 280);  // @15_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @16_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_58a000
  PV[1] = (u32)(ecx);  // @18_58a000
  ecx = esi;  // @19_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[1]);  // @20_58a000
  ecx = edx = 0;  // @21_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @22_58a000
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @23_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[2]);  // @25_58a000
  ecx = edx = 0;  // @26_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3045), sizeof v); (u32)v; });  // @27_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + ecx*4 + 3049), &v, sizeof v); }  // @28_58a000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3045), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 3045), &v, sizeof v); }  // @29_58a000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3045), sizeof v); (u32)v; });  // @30_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @31_58a000
  FL[2] = (eax & eax);  // @32_58a000
  if (FL[2] != 0) goto L58a040;  // @33_58a000
  L58a086:;
  eax = (eax - 1);  // @35_58a000
  FL[3] = eax;  // @36_58a000
  ecx = (u32)(EBP - 264);  // @37_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @38_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_58a000
  PV[3] = (u32)(ecx);  // @40_58a000
  ecx = esi;  // @41_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[3]);  // @42_58a000
  ecx = edx = 0;  // @43_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @44_58a000
  FL[2] = (eax & eax);  // @45_58a000
  if (FL[2] == 0) goto L58a142;  // @46_58a000
  L58a0b0:;
  eax = (eax - 1);  // @48_58a000
  FL[3] = eax;  // @49_58a000
  ecx = (u32)(EBP - 284);  // @50_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @51_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_58a000
  PV[4] = (u32)(ecx);  // @53_58a000
  ecx = esi;  // @54_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[4]);  // @55_58a000
  ecx = edx = 0;  // @56_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_58a000
  ecx = (u32)(EBP - 288);  // @58_58a000
  PV[5] = (u32)(ecx);  // @59_58a000
  ecx = esi;  // @60_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[5]);  // @61_58a000
  ecx = edx = 0;  // @62_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_58a000
  ecx = (u32)(EBP - 249);  // @64_58a000
  PV[6] = (u32)(ecx);  // @65_58a000
  ecx = esi;  // @66_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[6]);  // @67_58a000
  ecx = edx = 0;  // @68_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @69_58a000
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @70_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[7]);  // @72_58a000
  ecx = edx = 0;  // @73_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3177), sizeof v); (u32)v; });  // @74_58a000
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 249), sizeof v); (u32)v; })) & 0xff);  // @75_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @76_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @77_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @78_58a000
  eax = (u32)(ebx + ecx*8);  // @79_58a000
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 304) + 0), 4); v; });  // @80_58a000
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 304) + 4), 4); v; });  // @81_58a000
  X0[2] = 0;  // @82_58a000
  X0[3] = 0;  // @83_58a000
  __builtin_memcpy((void *)((u32)(ecx + eax + 3181) + 0), &X0[0], 4);  // @84_58a000
  __builtin_memcpy((void *)((u32)(ecx + eax + 3181) + 4), &X0[1], 4);  // @85_58a000
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(ecx + eax + 3189), &v, sizeof v); }  // @86_58a000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3177), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 3177), &v, sizeof v); }  // @87_58a000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3177), sizeof v); (u32)v; });  // @88_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @89_58a000
  FL[2] = (eax & eax);  // @90_58a000
  if (FL[2] != 0) goto L58a0b0;  // @91_58a000
  L58a142:;
  eax = (eax - 1);  // @93_58a000
  FL[3] = eax;  // @94_58a000
  ecx = (u32)(EBP - 268);  // @95_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @96_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_58a000
  PV[8] = (u32)(ecx);  // @98_58a000
  ecx = esi;  // @99_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[8]);  // @100_58a000
  ecx = edx = 0;  // @101_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @102_58a000
  FL[2] = (eax & eax);  // @103_58a000
  if (FL[2] == 0) goto L58a25f;  // @104_58a000
  L58a165:;
  eax = (eax - 1);  // @106_58a000
  FL[3] = eax;  // @107_58a000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @108_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 268), &v, sizeof v); }  // @109_58a000
  ecx = (u32)(EBP - 292);  // @110_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_58a000
  PV[9] = (u32)(ecx);  // @112_58a000
  ecx = esi;  // @113_58a000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @114_58a000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @115_58a000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @116_58a000
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @117_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[9]);  // @118_58a000
  ecx = edx = 0;  // @119_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @120_58a000
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @121_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @122_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @124_58a000
  ecx = edx = 0;  // @125_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @126_58a000
  ecx = (u32)(EBP - 256);  // @127_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @128_58a000
  PV[11] = (u32)(ecx);  // @129_58a000
  ecx = esi;  // @130_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[11]);  // @131_58a000
  ecx = edx = 0;  // @132_58a000
  edi = 0;  // @133_58a000
  FL[3] = edi;  // @134_58a000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; }); FL[1] = edi;  // @135_58a000
  if ((s32)FL[0] <= (s32)FL[1]) goto L58a220;  // @136_58a000
  L58a1e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_58a000
  ecx = (u32)(EBP - 272);  // @139_58a000
  PV[12] = (u32)(ecx);  // @140_58a000
  ecx = esi;  // @141_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[12]);  // @142_58a000
  ecx = edx = 0;  // @143_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_58a000
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @145_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @146_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @147_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[13]);  // @148_58a000
  ecx = edx = 0;  // @149_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @150_58a000
  edi = (edi + 1);  // @151_58a000
  FL[3] = edi;  // @152_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + ecx*4 - 244), &v, sizeof v); }  // @153_58a000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @154_58a000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @155_58a000
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; });  // @156_58a000
  if ((s32)FL[0] < (s32)FL[1]) goto L58a1e0;  // @157_58a000
  L58a220:;
  edx = (u32)(EBP - 192);  // @159_58a000
  ecx = esi;  // @160_58a000
  eax = ext_588940_fastcall2(ecx, edx);  // @161_58a000
  ecx = edx = 0;  // @162_58a000
  eax = (u32)(EBP - 248);  // @163_58a000
  PV[14] = (u32)(eax);  // @164_58a000
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3469), sizeof v); (u32)v; }) * (s32)(u32)(244));  // @165_58a000
  ecx = (u32)(ebx + 3473);  // @166_58a000
  ecx = (ecx + eax);  // @167_58a000
  FL[3] = ecx;  // @168_58a000
  eax = ext_589710_thiscall2(ecx, PV[14]);  // @169_58a000
  ecx = edx = 0;  // @170_58a000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3469), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 3469), &v, sizeof v); }  // @171_58a000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 3469), sizeof v); (u32)v; });  // @172_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @173_58a000
  FL[2] = (eax & eax);  // @174_58a000
  if (FL[2] != 0) goto L58a165;  // @175_58a000
  L58a25f:;
  eax = (eax - 1);  // @177_58a000
  FL[3] = eax;  // @178_58a000
  edi = (u32)(ebx + 11325);  // @179_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 268), &v, sizeof v); }  // @180_58a000
  ebx = (u32)(4);  // @181_58a000
  L58a271:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @183_58a000
  ecx = (u32)(EBP - 272);  // @184_58a000
  PV[15] = (u32)(ecx);  // @185_58a000
  ecx = esi;  // @186_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[15]);  // @187_58a000
  ecx = edx = 0;  // @188_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @189_58a000
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @190_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @191_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[16]);  // @193_58a000
  ecx = edx = 0;  // @194_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @195_58a000
  edi = (u32)(edi + 4);  // @196_58a000
  ebx = (ebx - (u32)(1));  // @197_58a000
  FL[3] = ebx;  // @198_58a000
  if (FL[3] != 0) goto L58a271;  // @199_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_58a000
  ecx = (u32)(EBP - 256);  // @201_58a000
  PV[17] = (u32)(ecx);  // @202_58a000
  ecx = esi;  // @203_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[17]);  // @204_58a000
  ecx = edx = 0;  // @205_58a000
  edi = 0;  // @206_58a000
  FL[3] = edi;  // @207_58a000
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; }); FL[1] = edi;  // @208_58a000
  if ((s32)FL[0] <= (s32)FL[1]) goto L58a300;  // @209_58a000
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @210_58a000
  L58a2c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @212_58a000
  ecx = (u32)(EBP - 276);  // @213_58a000
  PV[18] = (u32)(ecx);  // @214_58a000
  ecx = esi;  // @215_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[18]);  // @216_58a000
  ecx = edx = 0;  // @217_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @218_58a000
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @219_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @220_58a000
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @221_58a000
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[19]);  // @222_58a000
  ecx = edx = 0;  // @223_58a000
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 11349), sizeof v); (u32)v; });  // @224_58a000
  edi = (edi + 1);  // @225_58a000
  FL[3] = edi;  // @226_58a000
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + ecx*4 + 11353), &v, sizeof v); }  // @227_58a000
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 11349), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 11349), &v, sizeof v); }  // @228_58a000
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 11349), sizeof v); (u32)v; });  // @229_58a000
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 256), sizeof v); (u32)v; });  // @230_58a000
  if ((s32)FL[0] < (s32)FL[1]) goto L58a2c0;  // @231_58a000
  L58a300:;
  ext_633654(G(u32, 0x6f5630));  // @233_58a000
  return eax;  // @234_58a000
}
PCREG(58a000, lifted_58a000);

extern "C" u32 THISCALL lifted_531e70(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u32 a10, u32 a11, u32 a12, u32 a13) {
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
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 + 44, &a9, 4);
  __builtin_memcpy(F + 0x300 + 48, &a10, 4);
  __builtin_memcpy(F + 0x300 + 52, &a11, 4);
  __builtin_memcpy(F + 0x300 + 56, &a12, 4);
  __builtin_memcpy(F + 0x300 + 60, &a13, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 52), sizeof v); (u32)v; });  // @0_531e70
  ebx = (u32)(1);  // @1_531e70
  eax = (u32)(edx + 1);  // @2_531e70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @3_531e70
  edi = ecx;  // @4_531e70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @5_531e70
  FL[0] = eax; FL[1] = ebx;  // @6_531e70
  if ((s32)FL[0] <= (s32)FL[1]) goto L5320a2;  // @7_531e70
  ecx = 0;  // @8_531e70
  FL[3] = ecx;  // @9_531e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @10_531e70
  L531ea0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 56), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @12_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 44), sizeof v); (u32)v; });  // @13_531e70
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 3), sizeof v); (u32)v; });  // @14_531e70
  if (FL[0] == FL[1]) goto L531eba;  // @15_531e70
  eax = (eax + ecx);  // @16_531e70
  FL[3] = eax;  // @17_531e70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 60), sizeof v); (u32)v; });  // @18_531e70
  ecx = (ecx - 1);  // @19_531e70
  FL[3] = ecx;  // @20_531e70
  ecx = (ecx + eax);  // @21_531e70
  FL[3] = ecx;  // @22_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 40), sizeof v); (u32)v; });  // @23_531e70
  goto L531ec9;  // @24_531e70
  L531eba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 60), sizeof v); (u32)v; });  // @26_531e70
  eax = (eax - 1);  // @27_531e70
  FL[3] = eax;  // @28_531e70
  eax = (u32)((s32)eax * (s32)edx);  // @29_531e70
  FL[3] = eax;  // @30_531e70
  ecx = (ecx - 1);  // @31_531e70
  FL[3] = ecx;  // @32_531e70
  eax = (eax + ebx);  // @33_531e70
  FL[3] = eax;  // @34_531e70
  ecx = (ecx + eax);  // @35_531e70
  FL[3] = ecx;  // @36_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @37_531e70
  L531ec9:;
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6), sizeof v); (u32)v; });  // @39_531e70
  eax = ecx;  // @40_531e70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @41_531e70
  ecx = (ecx & (u32)(31));  // @42_531e70
  FL[3] = ecx;  // @43_531e70
  eax = (u32)((s32)eax >> (u32)(5));  // @44_531e70
  FL[3] = eax;  // @45_531e70
  esi = (esi + eax);  // @46_531e70
  FL[3] = esi;  // @47_531e70
  eax = (u32)(1);  // @48_531e70
  eax = (eax << (ecx & 0xff));  // @49_531e70
  FL[3] = eax;  // @50_531e70
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; }) & eax);  // @51_531e70
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @52_531e70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @53_531e70
  if (FL[2] == 0) goto L532079;  // @54_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @55_531e70
  X0[0] = 0;  // @56_531e70
  X0[1] = 0;  // @57_531e70
  X0[2] = 0;  // @58_531e70
  X0[3] = 0;  // @59_531e70
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @60_531e70
  X3[1] = 0;  // @61_531e70
  X3[2] = 0;  // @62_531e70
  X3[3] = 0;  // @63_531e70
  eax = (eax - 1);  // @64_531e70
  FL[3] = eax;  // @65_531e70
  eax = (eax + ebx);  // @66_531e70
  FL[3] = eax;  // @67_531e70
  X1[0] = 0;  // @68_531e70
  X1[1] = 0;  // @69_531e70
  X1[2] = 0;  // @70_531e70
  X1[3] = 0;  // @71_531e70
  esi = (eax & 0xffff);  // @72_531e70
  eax = (esi & 0xffff);  // @73_531e70
  ecx = (u32)((s32)eax * (s32)(u32)(21));  // @74_531e70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @75_531e70
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; }));  // @76_531e70
  FL[3] = ecx;  // @77_531e70
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7245824), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @78_531e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @79_531e70
  if (FL[0] == FL[1]) goto L532007;  // @80_531e70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @81_531e70
  if (FL[0] == FL[1]) goto L532007;  // @82_531e70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @83_531e70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @84_531e70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xffff);  // @85_531e70
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; })) & 0xffff);  // @86_531e70
  edx = (edx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; })) & 0xffff);  // @87_531e70
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_531e70
  eax = (eax & 0xffff);  // @89_531e70
  edi = ebx;  // @90_531e70
  edi = (edi - eax);  // @91_531e70
  FL[3] = edi;  // @92_531e70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @93_531e70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @94_531e70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @95_531e70
  edx = (edx & 0xffff);  // @96_531e70
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @97_531e70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @98_531e70
  ebx = (ecx & 0xffff);  // @99_531e70
  ecx = eax;  // @100_531e70
  ecx = (ecx - ebx);  // @101_531e70
  FL[3] = ecx;  // @102_531e70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @103_531e70
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @104_531e70
  eax = ebx;  // @105_531e70
  eax = (eax - edx);  // @106_531e70
  FL[3] = eax;  // @107_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @108_531e70
  esi = eax;  // @109_531e70
  eax = ecx;  // @110_531e70
  esi = (esi ^ edx);  // @111_531e70
  FL[3] = esi;  // @112_531e70
  esi = (esi - edx);  // @113_531e70
  FL[3] = esi;  // @114_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @115_531e70
  eax = (eax ^ edx);  // @116_531e70
  FL[3] = eax;  // @117_531e70
  eax = (eax - edx);  // @118_531e70
  FL[3] = eax;  // @119_531e70
  esi = (esi + eax);  // @120_531e70
  FL[3] = esi;  // @121_531e70
  eax = edi;  // @122_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @123_531e70
  eax = (eax ^ edx);  // @124_531e70
  FL[3] = eax;  // @125_531e70
  eax = (eax - edx);  // @126_531e70
  FL[3] = eax;  // @127_531e70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 44), sizeof v); (u32)v; });  // @128_531e70
  esi = (esi + eax);  // @129_531e70
  FL[3] = esi;  // @130_531e70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @131_531e70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @132_531e70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @133_531e70
  edi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 6), sizeof v); (u32)v; });  // @134_531e70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) - edi)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @135_531e70
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @136_531e70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @137_531e70
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @138_531e70
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @139_531e70
  ebx = (ebx - esi);  // @140_531e70
  FL[3] = ebx;  // @141_531e70
  edi = (edi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @142_531e70
  FL[3] = edi;  // @143_531e70
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @144_531e70
  FL[3] = esi;  // @145_531e70
  eax = ebx;  // @146_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @147_531e70
  ecx = eax;  // @148_531e70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @149_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @150_531e70
  ecx = (ecx ^ edx);  // @151_531e70
  FL[3] = ecx;  // @152_531e70
  ecx = (ecx - edx);  // @153_531e70
  FL[3] = ecx;  // @154_531e70
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @155_531e70
  FL[3] = ebx;  // @156_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @157_531e70
  eax = (eax ^ edx);  // @158_531e70
  FL[3] = eax;  // @159_531e70
  eax = (eax - edx);  // @160_531e70
  FL[3] = eax;  // @161_531e70
  ecx = (ecx + eax);  // @162_531e70
  FL[3] = ecx;  // @163_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @164_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @165_531e70
  eax = (eax ^ edx);  // @166_531e70
  FL[3] = eax;  // @167_531e70
  eax = (eax - edx);  // @168_531e70
  FL[3] = eax;  // @169_531e70
  ecx = (ecx + eax);  // @170_531e70
  FL[3] = ecx;  // @171_531e70
  eax = esi;  // @172_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @173_531e70
  X0[0] = F2U((float)(s32)X0[0]);  // @174_531e70
  X0[1] = F2U((float)(s32)X0[1]);  // @175_531e70
  X0[2] = F2U((float)(s32)X0[2]);  // @176_531e70
  X0[3] = F2U((float)(s32)X0[3]);  // @177_531e70
  X1[0] = ecx; X1[1] = X1[2] = X1[3] = 0;  // @178_531e70
  ecx = eax;  // @179_531e70
  ecx = (ecx ^ edx);  // @180_531e70
  FL[3] = ecx;  // @181_531e70
  eax = edi;  // @182_531e70
  ecx = (ecx - edx);  // @183_531e70
  FL[3] = ecx;  // @184_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @185_531e70
  eax = (eax ^ edx);  // @186_531e70
  FL[3] = eax;  // @187_531e70
  eax = (eax - edx);  // @188_531e70
  FL[3] = eax;  // @189_531e70
  ecx = (ecx + eax);  // @190_531e70
  FL[3] = ecx;  // @191_531e70
  eax = ebx;  // @192_531e70
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @193_531e70
  eax = (eax ^ edx);  // @194_531e70
  FL[3] = eax;  // @195_531e70
  X1[0] = F2U((float)(s32)X1[0]);  // @196_531e70
  X1[1] = F2U((float)(s32)X1[1]);  // @197_531e70
  X1[2] = F2U((float)(s32)X1[2]);  // @198_531e70
  X1[3] = F2U((float)(s32)X1[3]);  // @199_531e70
  eax = (eax - edx);  // @200_531e70
  FL[3] = eax;  // @201_531e70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @202_531e70
  ecx = (ecx + eax);  // @203_531e70
  FL[3] = ecx;  // @204_531e70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @205_531e70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @206_531e70
  X3[0] = ecx; X3[1] = X3[2] = X3[3] = 0;  // @207_531e70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @208_531e70
  X3[0] = F2U((float)(s32)X3[0]);  // @209_531e70
  X3[1] = F2U((float)(s32)X3[1]);  // @210_531e70
  X3[2] = F2U((float)(s32)X3[2]);  // @211_531e70
  X3[3] = F2U((float)(s32)X3[3]);  // @212_531e70
  L532007:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 44), sizeof v); (u32)v; });  // @214_531e70
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 10) + 0), 4); v; });  // @215_531e70
  X2[1] = 0;  // @216_531e70
  X2[2] = 0;  // @217_531e70
  X2[3] = 0;  // @218_531e70
  X2[0] = F2U(U2F(X2[0]) + U2F(X3[0]));  // @219_531e70
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @220_531e70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 10) + 0), 4); v; });  // @221_531e70
  X0[1] = 0;  // @222_531e70
  X0[2] = 0;  // @223_531e70
  X0[3] = 0;  // @224_531e70
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @225_531e70
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866736) + 0), 4); v; })));  // @226_531e70
  X1[0] = X2[0];  // @227_531e70
  X1[1] = X2[1];  // @228_531e70
  X1[2] = X2[2];  // @229_531e70
  X1[3] = X2[3];  // @230_531e70
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @231_531e70
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L532079;  // @232_531e70
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @233_531e70
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @234_531e70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @235_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @236_531e70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 14), &v, sizeof v); }  // @237_531e70
  __builtin_memcpy((void *)((u32)(ecx + 10) + 0), &X2[0], 4);  // @238_531e70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @239_531e70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @240_531e70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @241_531e70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 6), &v, sizeof v); }  // @242_531e70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @243_531e70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @244_531e70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @245_531e70
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 3), &v, sizeof v); }  // @246_531e70
  PV[0] = (u32)(esi);  // @247_531e70
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @248_531e70
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @249_531e70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @250_531e70
  ecx = edi;  // @251_531e70
  eax = ext_52d250_fastcall4(ecx, edx, PV[1], PV[0]);  // @252_531e70
  ecx = edx = 0;  // @253_531e70
  L532079:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 52), sizeof v); (u32)v; });  // @255_531e70
  ebx = (ebx + 1);  // @256_531e70
  FL[3] = ebx;  // @257_531e70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @258_531e70
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 48), sizeof v); (u32)v; }));  // @259_531e70
  FL[3] = ecx;  // @260_531e70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @261_531e70
  eax = (u32)(edx + 1);  // @262_531e70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @263_531e70
  FL[0] = ebx; FL[1] = eax;  // @264_531e70
  if ((s32)FL[0] < (s32)FL[1]) goto L531ea0;  // @265_531e70
  eax = (u32)(1);  // @266_531e70
  return eax;  // @267_531e70
  L5320a2:;
  eax = ebx;  // @269_531e70
  return eax;  // @270_531e70
}
PCREG(531e70, lifted_531e70);

extern "C" u32 THISCALL lifted_5abf00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5abf00
  eax = ecx;  // @1_5abf00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @2_5abf00
  FL[2] = (edi & edi);  // @3_5abf00
  if (FL[2] == 0) goto L5ac11b;  // @4_5abf00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 114), sizeof v); (u32)v; });  // @5_5abf00
  ebx = (u32)(eax + 110);  // @6_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_5abf00
  ecx = eax;  // @8_5abf00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @9_5abf00
  eax = edx;  // @10_5abf00
  eax = (eax - edx);  // @11_5abf00
  FL[3] = eax;  // @12_5abf00
  eax = (u32)((s32)eax >> (u32)(4));  // @13_5abf00
  FL[3] = eax;  // @14_5abf00
  FL[2] = (eax & eax);  // @15_5abf00
  if ((s32)FL[2] <= 0) goto L5abf50;  // @16_5abf00
  esi = edx;  // @17_5abf00
  esi = (esi - ecx);  // @18_5abf00
  FL[3] = esi;  // @19_5abf00
  L5abf40:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx) + 0), 4); v; });  // @21_5abf00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx) + 4), 4); v; });  // @22_5abf00
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx) + 8), 4); v; });  // @23_5abf00
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + ecx) + 12), 4); v; });  // @24_5abf00
  eax = (eax - 1);  // @25_5abf00
  FL[3] = eax;  // @26_5abf00
  ecx = (u32)(ecx + 16);  // @27_5abf00
  __builtin_memcpy((void *)((u32)(ecx - 16) + 0), &X0[0], 4);  // @28_5abf00
  __builtin_memcpy((void *)((u32)(ecx - 16) + 4), &X0[1], 4);  // @29_5abf00
  __builtin_memcpy((void *)((u32)(ecx - 16) + 8), &X0[2], 4);  // @30_5abf00
  __builtin_memcpy((void *)((u32)(ecx - 16) + 12), &X0[3], 4);  // @31_5abf00
  FL[2] = (eax & eax);  // @32_5abf00
  if ((s32)FL[2] > 0) goto L5abf40;  // @33_5abf00
  L5abf50:;
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }));  // @35_5abf00
  FL[3] = edx;  // @36_5abf00
  ecx = edi;  // @37_5abf00
  edx = (u32)((s32)edx >> (u32)(4));  // @38_5abf00
  FL[3] = edx;  // @39_5abf00
  esi = 0;  // @40_5abf00
  FL[3] = esi;  // @41_5abf00
  FL[1] = edx;  // @42_5abf00
  edx = (0u - edx);  // @43_5abf00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @44_5abf00
  edx = (edx << (u32)(4));  // @45_5abf00
  FL[3] = edx;  // @46_5abf00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + edx)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @47_5abf00
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @48_5abf00
  eax = (u32)(ecx + 1);  // @49_5abf00
  edx = 0;  // @50_5abf00
  FL[3] = edx;  // @51_5abf00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @52_5abf00
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @53_5abf00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @54_5abf00
  L5abf74:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @56_5abf00
  ecx = (ecx + 1);  // @57_5abf00
  FL[3] = ecx;  // @58_5abf00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @59_5abf00
  if (FL[2] != 0) goto L5abf74;  // @60_5abf00
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; }));  // @61_5abf00
  FL[3] = ecx;  // @62_5abf00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @63_5abf00
  if (FL[3] == 0) goto L5ac09d;  // @64_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @65_5abf00
  eax = (eax + (u32)(66));  // @66_5abf00
  FL[3] = eax;  // @67_5abf00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @68_5abf00
  L5abf90:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi), sizeof v); (u32)v; }); FL[1] = (u32)(36);  // @70_5abf00
  if (FL[0] != FL[1]) goto L5ac094;  // @71_5abf00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi + 1), sizeof v); (u32)v; })) & 0xff);  // @72_5abf00
  esi = (esi + 1);  // @73_5abf00
  FL[3] = esi;  // @74_5abf00
  eax = 0;  // @75_5abf00
  FL[3] = eax;  // @76_5abf00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(36);  // @77_5abf00
  if (FL[0] == FL[1]) goto L5abfbd;  // @78_5abf00
  L5abfa6:;
  esi = (esi + 1);  // @80_5abf00
  FL[3] = esi;  // @81_5abf00
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP + eax - 36), &v, sizeof v); }  // @82_5abf00
  eax = (eax + 1);  // @83_5abf00
  FL[3] = eax;  // @84_5abf00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi), sizeof v); (u32)v; })) & 0xff);  // @85_5abf00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(36);  // @86_5abf00
  if (FL[0] != FL[1]) goto L5abfa6;  // @87_5abf00
  FL[0] = eax; FL[1] = (u32)(32);  // @88_5abf00
  if (FL[0] >= FL[1]) goto L5ac12c;  // @89_5abf00
  L5abfbd:;
  ecx = (u32)(EBP - 36);  // @91_5abf00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 36), &v, sizeof v); }  // @92_5abf00
  eax = (u32)(ecx + 1);  // @93_5abf00
  esi = (esi + 1);  // @94_5abf00
  FL[3] = esi;  // @95_5abf00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @96_5abf00
  L5abfd0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @98_5abf00
  ecx = (ecx + 1);  // @99_5abf00
  FL[3] = ecx;  // @100_5abf00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @101_5abf00
  if (FL[2] != 0) goto L5abfd0;  // @102_5abf00
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; }));  // @103_5abf00
  FL[3] = ecx;  // @104_5abf00
  eax = (edx & 0xffff);  // @105_5abf00
  edx = esi;  // @106_5abf00
  edx = (edx - eax);  // @107_5abf00
  FL[3] = edx;  // @108_5abf00
  eax = (eax + edi);  // @109_5abf00
  FL[3] = eax;  // @110_5abf00
  edx = (edx - ecx);  // @111_5abf00
  FL[3] = edx;  // @112_5abf00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @113_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @114_5abf00
  edx = (edx - (u32)(2));  // @115_5abf00
  FL[3] = edx;  // @116_5abf00
  PV[0] = (u32)(edx);  // @117_5abf00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @118_5abf00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @119_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 40), sizeof v); (u32)v; });  // @120_5abf00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @121_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_5abf00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[1], PV[0]);  // @123_5abf00
  ecx = edx = 0;  // @124_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @125_5abf00
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @126_5abf00
  if (FL[0] == FL[1]) goto L5ac022;  // @127_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @128_5abf00
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @129_5abf00
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @130_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @131_5abf00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @132_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_5abf00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[3], PV[2]);  // @134_5abf00
  ecx = edx = 0;  // @135_5abf00
  L5ac022:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_5abf00
  edx = (u32)(EBP - 36);  // @138_5abf00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @139_5abf00
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @140_5abf00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @141_5abf00
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @142_5abf00
  PV[4] = (u32)(edx);  // @143_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @144_5abf00
  { u16 v = (u16)((esi & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 66), &v, sizeof v); }  // @145_5abf00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @146_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @147_5abf00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[4]);  // @148_5abf00
  ecx = edx = 0;  // @149_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @150_5abf00
  PV[5] = (u32)(eax);  // @151_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6407), sizeof v); (u32)v; });  // @152_5abf00
  eax = ext_439320_stdcall3(PV[5], (u32)(0), (u32)(0));  // @153_5abf00
  ecx = edx = 0;  // @154_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @155_5abf00
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @156_5abf00
  if (FL[0] == FL[1]) goto L5ac077;  // @157_5abf00
  FL[2] = (eax & eax);  // @158_5abf00
  if (FL[2] == 0) goto L5ac071;  // @159_5abf00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @160_5abf00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 4), 4); v; });  // @161_5abf00
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 8), 4); v; });  // @162_5abf00
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 12), 4); v; });  // @163_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @164_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @165_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @166_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @167_5abf00
  L5ac071:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + (u32)(16))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @169_5abf00
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @170_5abf00
  goto L5ac083;  // @171_5abf00
  L5ac077:;
  ecx = (u32)(EBP - 72);  // @173_5abf00
  PV[6] = (u32)(ecx);  // @174_5abf00
  PV[7] = (u32)(eax);  // @175_5abf00
  ecx = ebx;  // @176_5abf00
  eax = ext_5acad0_thiscall3(ecx, PV[7], PV[6]);  // @177_5abf00
  ecx = edx = 0;  // @178_5abf00
  L5ac083:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @180_5abf00
  edx = (edx & 0xffff0000u) | (((esi & 0xffff)) & 0xffff);  // @181_5abf00
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @182_5abf00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @183_5abf00
  L5ac094:;
  esi = (esi + 1);  // @185_5abf00
  FL[3] = esi;  // @186_5abf00
  FL[0] = esi; FL[1] = ecx;  // @187_5abf00
  if (FL[0] < FL[1]) goto L5abf90;  // @188_5abf00
  L5ac09d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @190_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @191_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 26), sizeof v); (u32)v; });  // @192_5abf00
  eax = (edx & 0xffff);  // @193_5abf00
  edx = esi;  // @194_5abf00
  edx = (edx - eax);  // @195_5abf00
  FL[3] = edx;  // @196_5abf00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @197_5abf00
  edi = (edi + eax);  // @198_5abf00
  FL[3] = edi;  // @199_5abf00
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @200_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_5abf00
  PV[8] = (u32)(edx);  // @202_5abf00
  PV[9] = (u32)(edi);  // @203_5abf00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[9], PV[8]);  // @204_5abf00
  ecx = edx = 0;  // @205_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @206_5abf00
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @207_5abf00
  if (FL[0] == FL[1]) goto L5ac0df;  // @208_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @209_5abf00
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @210_5abf00
  PV[11] = (u32)(edi);  // @211_5abf00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 66), sizeof v); (u32)v; });  // @212_5abf00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @213_5abf00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_5abf00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 640)))(ecx, PV[11], PV[10]);  // @215_5abf00
  ecx = edx = 0;  // @216_5abf00
  L5ac0df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @218_5abf00
  { u16 v = (u16)((esi & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 66), &v, sizeof v); }  // @219_5abf00
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @220_5abf00
  if (FL[0] == FL[1]) goto L5ac10d;  // @221_5abf00
  FL[2] = (eax & eax);  // @222_5abf00
  if (FL[2] == 0) goto L5ac0f6;  // @223_5abf00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @224_5abf00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 4), 4); v; });  // @225_5abf00
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 8), 4); v; });  // @226_5abf00
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 12), 4); v; });  // @227_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @228_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @229_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @230_5abf00
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @231_5abf00
  L5ac0f6:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + (u32)(16))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @233_5abf00
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @234_5abf00
  ext_633654(G(u32, 0x6f5630));  // @235_5abf00
  return eax;  // @236_5abf00
  L5ac10d:;
  ecx = (u32)(EBP - 72);  // @238_5abf00
  PV[12] = (u32)(ecx);  // @239_5abf00
  PV[13] = (u32)(eax);  // @240_5abf00
  ecx = ebx;  // @241_5abf00
  eax = ext_5acad0_thiscall3(ecx, PV[13], PV[12]);  // @242_5abf00
  ecx = edx = 0;  // @243_5abf00
  L5ac11b:;
  ext_633654(G(u32, 0x6f5630));  // @245_5abf00
  return eax;  // @246_5abf00
  L5ac12c:;
  eax = ext_634047_cdecl0();  // @248_5abf00
  ecx = edx = 0;  // @249_5abf00
}
PCREG(5abf00, lifted_5abf00);

extern "C" u32 STDCALL lifted_500a50(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_500a50
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @2_500a50
  ecx = edx = 0;  // @3_500a50
  edi = eax;  // @4_500a50
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @5_500a50
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @6_500a50
  if (FL[2] == 0) goto L500ab4;  // @7_500a50
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @8_500a50
  if (FL[0] == FL[1]) goto L500ab4;  // @9_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_500a50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @12_500a50
  ecx = edx = 0;  // @13_500a50
  PV[0] = (u32)(eax);  // @14_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_500a50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @16_500a50
  ecx = edx = 0;  // @17_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_500a50
  FL[2] = (eax & eax);  // @19_500a50
  if (FL[2] == 0) goto L500ab3;  // @20_500a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @21_500a50
  ecx = edx = 0;  // @22_500a50
  goto L500ab4;  // @23_500a50
  L500ab3:;
  __builtin_trap();  // @25_500a50
  L500ab4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_500a50
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_500a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[1]);  // @31_500a50
  ecx = edx = 0;  // @32_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @33_500a50
  ebx = eax;  // @34_500a50
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @35_500a50
  ecx = edx = 0;  // @36_500a50
  edi = eax;  // @37_500a50
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @38_500a50
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @39_500a50
  if (FL[2] == 0) goto L500b16;  // @40_500a50
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @41_500a50
  if (FL[0] == FL[1]) goto L500b16;  // @42_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_500a50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @45_500a50
  ecx = edx = 0;  // @46_500a50
  PV[2] = (u32)(eax);  // @47_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_500a50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @49_500a50
  ecx = edx = 0;  // @50_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @51_500a50
  FL[2] = (eax & eax);  // @52_500a50
  if (FL[2] == 0) goto L500b15;  // @53_500a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @54_500a50
  ecx = edx = 0;  // @55_500a50
  goto L500b16;  // @56_500a50
  L500b15:;
  __builtin_trap();  // @58_500a50
  L500b16:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @60_500a50
  X0[1] = 0;  // @61_500a50
  X0[2] = 0;  // @62_500a50
  X0[3] = 0;  // @63_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @64_500a50
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @65_500a50
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @66_500a50
  ecx = edx = 0;  // @67_500a50
  edi = eax;  // @68_500a50
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @69_500a50
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @70_500a50
  if (FL[2] == 0) goto L500b6d;  // @71_500a50
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @72_500a50
  if (FL[0] == FL[1]) goto L500b6d;  // @73_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @74_500a50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @76_500a50
  ecx = edx = 0;  // @77_500a50
  PV[3] = (u32)(eax);  // @78_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @79_500a50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @80_500a50
  ecx = edx = 0;  // @81_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @82_500a50
  FL[2] = (eax & eax);  // @83_500a50
  if (FL[2] == 0) goto L500b6c;  // @84_500a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @85_500a50
  ecx = edx = 0;  // @86_500a50
  goto L500b6d;  // @87_500a50
  L500b6c:;
  __builtin_trap();  // @89_500a50
  L500b6d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @91_500a50
  X0[1] = 0;  // @92_500a50
  X0[2] = 0;  // @93_500a50
  X0[3] = 0;  // @94_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @95_500a50
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @96_500a50
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @97_500a50
  ecx = edx = 0;  // @98_500a50
  edi = eax;  // @99_500a50
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @100_500a50
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @101_500a50
  if (FL[2] == 0) goto L500bc4;  // @102_500a50
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @103_500a50
  if (FL[0] == FL[1]) goto L500bc4;  // @104_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @105_500a50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @107_500a50
  ecx = edx = 0;  // @108_500a50
  PV[4] = (u32)(eax);  // @109_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_500a50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6932144), (u32)(6932792));  // @111_500a50
  ecx = edx = 0;  // @112_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @113_500a50
  FL[2] = (eax & eax);  // @114_500a50
  if (FL[2] == 0) goto L500bc3;  // @115_500a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @116_500a50
  ecx = edx = 0;  // @117_500a50
  goto L500bc4;  // @118_500a50
  L500bc3:;
  __builtin_trap();  // @120_500a50
  L500bc4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @122_500a50
  X0[1] = 0;  // @123_500a50
  X0[2] = 0;  // @124_500a50
  X0[3] = 0;  // @125_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @126_500a50
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @127_500a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @128_500a50
  X0[1] = 0;  // @129_500a50
  X0[2] = 0;  // @130_500a50
  X0[3] = 0;  // @131_500a50
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @132_500a50
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @133_500a50
  X0[1] = 0;  // @134_500a50
  X0[2] = 0;  // @135_500a50
  X0[3] = 0;  // @136_500a50
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @137_500a50
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @138_500a50
  ecx = edx = 0;  // @139_500a50
  ecx = eax;  // @140_500a50
  eax = ext_5002f0_thiscall2(ecx, (u32)(0));  // @141_500a50
  ecx = edx = 0;  // @142_500a50
  FL[2] = (ebx & ebx);  // @143_500a50
  if (FL[2] != 0) goto L500c2e;  // @144_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @145_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6933008), (u32)(764));  // @147_500a50
  ecx = edx = 0;  // @148_500a50
  PV[5] = (u32)(eax);  // @149_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @150_500a50
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6933368));  // @151_500a50
  ecx = edx = 0;  // @152_500a50
  ext_633654(G(u32, 0x6f5630));  // @153_500a50
  return eax;  // @154_500a50
  L500c2e:;
  ecx = ebx;  // @156_500a50
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097377));  // @157_500a50
  ecx = edx = 0;  // @158_500a50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @159_500a50
  if (FL[2] != 0) goto L500c61;  // @160_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @161_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6933008), (u32)(771));  // @163_500a50
  ecx = edx = 0;  // @164_500a50
  PV[6] = (u32)(eax);  // @165_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @166_500a50
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[6], (u32)(6933568));  // @167_500a50
  ecx = edx = 0;  // @168_500a50
  L500c61:;
  eax = (u32)(EBP - 16);  // @170_500a50
  ecx = ebx;  // @171_500a50
  PV[7] = (u32)(eax);  // @172_500a50
  eax = ext_4db1f0_thiscall2(ecx, PV[7]);  // @173_500a50
  ecx = edx = 0;  // @174_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @175_500a50
  edx = (u32)(EBP - 16);  // @176_500a50
  PV[8] = (u32)(ecx);  // @177_500a50
  PV[9] = (u32)(edx);  // @178_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @179_500a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @180_500a50
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[9], (u32)(3240099840));  // @181_500a50
  ecx = edx = 0;  // @182_500a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @183_500a50
  eax = (eax & 0xff);  // @184_500a50
  PV[10] = (u32)(eax);  // @185_500a50
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @186_500a50
  ecx = edx = 0;  // @187_500a50
  ecx = eax;  // @188_500a50
  eax = ext_5002f0_thiscall2(ecx, PV[10]);  // @189_500a50
  ecx = edx = 0;  // @190_500a50
  ext_633654(G(u32, 0x6f5630));  // @191_500a50
  return eax;  // @192_500a50
}
PCREG(500a50, lifted_500a50);

extern "C" u32 THISCALL lifted_463a30(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @1_463a30
  X0[1] = 0;  // @2_463a30
  X0[2] = 0;  // @3_463a30
  X0[3] = 0;  // @4_463a30
  ebx = ecx;  // @5_463a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 220), &v, sizeof v); }  // @6_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_463a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @8_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @9_463a30
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @10_463a30
  eax = (u32)(EBP - 68);  // @11_463a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @12_463a30
  PV[0] = (u32)(ecx);  // @13_463a30
  PV[1] = X0[0];  // @14_463a30
  PV[2] = (u32)(eax);  // @15_463a30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_463a30
  eax = (u32)(EBP - 16);  // @17_463a30
  PV[3] = (u32)(eax);  // @18_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @19_463a30
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @20_463a30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 12)))(ecx, PV[4], (u32)(0), PV[3], PV[2], PV[1]);  // @21_463a30
  ecx = edx = 0;  // @22_463a30
  edx = (u32)(EBP - 68);  // @23_463a30
  ecx = (u32)(EBP - 104);  // @24_463a30
  eax = ext_4df1e0_fastcall2(ecx, edx);  // @25_463a30
  ecx = edx = 0;  // @26_463a30
  edi = (u32)(ebx + 166);  // @27_463a30
  PV[5] = (u32)(edi);  // @28_463a30
  edx = (u32)(EBP - 16);  // @29_463a30
  ecx = (u32)(EBP - 212);  // @30_463a30
  eax = ext_43e920_fastcall3(ecx, edx, PV[5]);  // @31_463a30
  ecx = edx = 0;  // @32_463a30
  esi = (u32)(ebx + 130);  // @33_463a30
  edx = esi;  // @34_463a30
  ecx = (u32)(EBP - 212);  // @35_463a30
  eax = ext_441a60_fastcall2(ecx, edx);  // @36_463a30
  ecx = edx = 0;  // @37_463a30
  PV[6] = (u32)(esi);  // @38_463a30
  edx = (u32)(EBP - 104);  // @39_463a30
  ecx = (u32)(EBP - 52);  // @40_463a30
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[6]);  // @41_463a30
  ecx = edx = 0;  // @42_463a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @43_463a30
  edx = (u32)(EBP - 52);  // @44_463a30
  eax = ext_4de420_fastcall2(ecx, edx);  // @45_463a30
  ecx = edx = 0;  // @46_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @47_463a30
  edx = (u32)(EBP - 104);  // @48_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 212) + 0), 4); v; });  // @49_463a30
  X0[1] = 0;  // @50_463a30
  X0[2] = 0;  // @51_463a30
  X0[3] = 0;  // @52_463a30
  ecx = esi;  // @53_463a30
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @54_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 208) + 0), 4); v; });  // @55_463a30
  X0[1] = 0;  // @56_463a30
  X0[2] = 0;  // @57_463a30
  X0[3] = 0;  // @58_463a30
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X0[0], 4);  // @59_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 204) + 0), 4); v; });  // @60_463a30
  X0[1] = 0;  // @61_463a30
  X0[2] = 0;  // @62_463a30
  X0[3] = 0;  // @63_463a30
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X0[0], 4);  // @64_463a30
  eax = ext_4de420_fastcall2(ecx, edx);  // @65_463a30
  ecx = edx = 0;  // @66_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @67_463a30
  X0[1] = 0;  // @68_463a30
  X0[2] = 0;  // @69_463a30
  X0[3] = 0;  // @70_463a30
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @71_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @72_463a30
  X0[1] = 0;  // @73_463a30
  X0[2] = 0;  // @74_463a30
  X0[3] = 0;  // @75_463a30
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @76_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @77_463a30
  X0[1] = 0;  // @78_463a30
  X0[2] = 0;  // @79_463a30
  X0[3] = 0;  // @80_463a30
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @81_463a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @82_463a30
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) & (u32)(2));  // @83_463a30
  if (FL[2] == 0) goto L463d8c;  // @84_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @85_463a30
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 278) + 0), 4); v; });  // @86_463a30
  X1[1] = 0;  // @87_463a30
  X1[2] = 0;  // @88_463a30
  X1[3] = 0;  // @89_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 274) + 0), 4); v; });  // @90_463a30
  X0[1] = 0;  // @91_463a30
  X0[2] = 0;  // @92_463a30
  X0[3] = 0;  // @93_463a30
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @94_463a30
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @95_463a30
  X2[1] = 0;  // @96_463a30
  X2[2] = 0;  // @97_463a30
  X2[3] = 0;  // @98_463a30
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @99_463a30
  X2[0] = F2U(U2F(X2[0]) / U2F(X0[0]));  // @100_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @101_463a30
  X0[1] = 0;  // @102_463a30
  X0[2] = 0;  // @103_463a30
  X0[3] = 0;  // @104_463a30
  __builtin_memcpy((void *)((u32)(EBP - 216) + 0), &X2[0], 4);  // @105_463a30
  if ((!(U2F(X2[0]) >= U2F(X0[0])))) goto L463b80;  // @106_463a30
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(ebx + 278), &v, sizeof v); }  // @107_463a30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) & (u32)(4294967293))); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @108_463a30
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @109_463a30
  __builtin_memcpy((void *)((u32)(EBP - 216) + 0), &X0[0], 4);  // @110_463a30
  L463b80:;
  ecx = (u32)(EBP - 152);  // @112_463a30
  eax = ext_4de7a0_thiscall1(ecx);  // @113_463a30
  ecx = edx = 0;  // @114_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 262) + 0), 4); v; });  // @115_463a30
  X0[1] = 0;  // @116_463a30
  X0[2] = 0;  // @117_463a30
  X0[3] = 0;  // @118_463a30
  eax = (u32)(ebx + 226);  // @119_463a30
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 216) + 0), 4); v; });  // @120_463a30
  X2[1] = 0;  // @121_463a30
  X2[2] = 0;  // @122_463a30
  X2[3] = 0;  // @123_463a30
  edx = (u32)(EBP - 152);  // @124_463a30
  X1[0] = 0;  // @125_463a30
  X1[1] = 0;  // @126_463a30
  X1[2] = 0;  // @127_463a30
  X1[3] = 0;  // @128_463a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @129_463a30
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @130_463a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @131_463a30
  PV[7] = (u32)(ecx);  // @132_463a30
  PV[8] = X2[0];  // @133_463a30
  ecx = (u32)(EBP - 200);  // @134_463a30
  PV[9] = (u32)(eax);  // @135_463a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @136_463a30
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @137_463a30
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @138_463a30
  __builtin_memcpy((void *)((u32)(EBP - 164) + 0), &X0[0], 4);  // @139_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 266) + 0), 4); v; });  // @140_463a30
  X0[1] = 0;  // @141_463a30
  X0[2] = 0;  // @142_463a30
  X0[3] = 0;  // @143_463a30
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @144_463a30
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @145_463a30
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @146_463a30
  __builtin_memcpy((void *)((u32)(EBP - 160) + 0), &X0[0], 4);  // @147_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 270) + 0), 4); v; });  // @148_463a30
  X0[1] = 0;  // @149_463a30
  X0[2] = 0;  // @150_463a30
  X0[3] = 0;  // @151_463a30
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @152_463a30
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @153_463a30
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @154_463a30
  __builtin_memcpy((void *)((u32)(EBP - 156) + 0), &X0[0], 4);  // @155_463a30
  eax = ext_4de520_fastcall4(ecx, edx, PV[9], PV[8]);  // @156_463a30
  ecx = edx = 0;  // @157_463a30
  esi = (u32)(ebx + 178);  // @158_463a30
  PV[10] = (u32)(esi);  // @159_463a30
  edx = (u32)(EBP - 104);  // @160_463a30
  ecx = (u32)(EBP - 52);  // @161_463a30
  eax = ext_4de440_fastcall3(ecx, edx, PV[10]);  // @162_463a30
  ecx = edx = 0;  // @163_463a30
  PV[11] = (u32)(esi);  // @164_463a30
  edx = (u32)(EBP - 16);  // @165_463a30
  ecx = (u32)(EBP - 212);  // @166_463a30
  eax = ext_441970_fastcall3(ecx, edx, PV[11]);  // @167_463a30
  ecx = edx = 0;  // @168_463a30
  edx = (u32)(ebx + 214);  // @169_463a30
  ecx = (u32)(EBP - 212);  // @170_463a30
  eax = ext_441940_fastcall2(ecx, edx);  // @171_463a30
  ecx = edx = 0;  // @172_463a30
  edx = (u32)(EBP - 52);  // @173_463a30
  ecx = (u32)(EBP - 152);  // @174_463a30
  eax = ext_4de420_fastcall2(ecx, edx);  // @175_463a30
  ecx = edx = 0;  // @176_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 212) + 0), 4); v; });  // @177_463a30
  X0[1] = 0;  // @178_463a30
  X0[2] = 0;  // @179_463a30
  X0[3] = 0;  // @180_463a30
  eax = (u32)(EBP - 152);  // @181_463a30
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @182_463a30
  edx = (u32)(EBP - 200);  // @183_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 208) + 0), 4); v; });  // @184_463a30
  X0[1] = 0;  // @185_463a30
  X0[2] = 0;  // @186_463a30
  X0[3] = 0;  // @187_463a30
  ecx = (u32)(EBP - 52);  // @188_463a30
  __builtin_memcpy((void *)((u32)(EBP - 112) + 0), &X0[0], 4);  // @189_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 204) + 0), 4); v; });  // @190_463a30
  X0[1] = 0;  // @191_463a30
  X0[2] = 0;  // @192_463a30
  X0[3] = 0;  // @193_463a30
  PV[12] = (u32)(eax);  // @194_463a30
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @195_463a30
  eax = ext_4de440_fastcall3(ecx, edx, PV[12]);  // @196_463a30
  ecx = edx = 0;  // @197_463a30
  eax = (u32)(EBP - 152);  // @198_463a30
  PV[13] = (u32)(eax);  // @199_463a30
  edx = (u32)(EBP - 164);  // @200_463a30
  ecx = (u32)(EBP - 212);  // @201_463a30
  eax = ext_441970_fastcall3(ecx, edx, PV[13]);  // @202_463a30
  ecx = edx = 0;  // @203_463a30
  edx = (u32)(EBP - 116);  // @204_463a30
  ecx = (u32)(EBP - 212);  // @205_463a30
  eax = ext_441940_fastcall2(ecx, edx);  // @206_463a30
  ecx = edx = 0;  // @207_463a30
  edx = (u32)(EBP - 52);  // @208_463a30
  ecx = (u32)(EBP - 152);  // @209_463a30
  eax = ext_4de420_fastcall2(ecx, edx);  // @210_463a30
  ecx = edx = 0;  // @211_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 212) + 0), 4); v; });  // @212_463a30
  X0[1] = 0;  // @213_463a30
  X0[2] = 0;  // @214_463a30
  X0[3] = 0;  // @215_463a30
  ecx = (u32)(EBP - 164);  // @216_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @217_463a30
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @218_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 208) + 0), 4); v; });  // @219_463a30
  X0[1] = 0;  // @220_463a30
  X0[2] = 0;  // @221_463a30
  X0[3] = 0;  // @222_463a30
  PV[14] = (u32)(ecx);  // @223_463a30
  ecx = (u32)(EBP - 200);  // @224_463a30
  __builtin_memcpy((void *)((u32)(EBP - 112) + 0), &X0[0], 4);  // @225_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 204) + 0), 4); v; });  // @226_463a30
  X0[1] = 0;  // @227_463a30
  X0[2] = 0;  // @228_463a30
  X0[3] = 0;  // @229_463a30
  PV[15] = (u32)(ecx);  // @230_463a30
  ecx = ebx;  // @231_463a30
  __builtin_memcpy((void *)((u32)(EBP - 108) + 0), &X0[0], 4);  // @232_463a30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[15], PV[14]);  // @233_463a30
  ecx = edx = 0;  // @234_463a30
  ecx = (u32)(EBP - 200);  // @235_463a30
  eax = ext_4e2aa0_thiscall1(ecx);  // @236_463a30
  ecx = edx = 0;  // @237_463a30
  eax = (u32)(EBP - 164);  // @238_463a30
  PV[16] = (u32)(eax);  // @239_463a30
  edx = (u32)(EBP - 116);  // @240_463a30
  ecx = (u32)(EBP - 212);  // @241_463a30
  eax = ext_43e920_fastcall3(ecx, edx, PV[16]);  // @242_463a30
  ecx = edx = 0;  // @243_463a30
  edx = (u32)(EBP - 200);  // @244_463a30
  ecx = (u32)(EBP - 212);  // @245_463a30
  eax = ext_441a60_fastcall2(ecx, edx);  // @246_463a30
  ecx = edx = 0;  // @247_463a30
  eax = (u32)(EBP - 200);  // @248_463a30
  PV[17] = (u32)(eax);  // @249_463a30
  edx = (u32)(EBP - 152);  // @250_463a30
  ecx = (u32)(EBP - 52);  // @251_463a30
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[17]);  // @252_463a30
  ecx = edx = 0;  // @253_463a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @254_463a30
  edx = (u32)(EBP - 52);  // @255_463a30
  eax = ext_4de420_fastcall2(ecx, edx);  // @256_463a30
  ecx = edx = 0;  // @257_463a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @258_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 212) + 0), 4); v; });  // @259_463a30
  X0[1] = 0;  // @260_463a30
  X0[2] = 0;  // @261_463a30
  X0[3] = 0;  // @262_463a30
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @263_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 208) + 0), 4); v; });  // @264_463a30
  X0[1] = 0;  // @265_463a30
  X0[2] = 0;  // @266_463a30
  X0[3] = 0;  // @267_463a30
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X0[0], 4);  // @268_463a30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 204) + 0), 4); v; });  // @269_463a30
  X0[1] = 0;  // @270_463a30
  X0[2] = 0;  // @271_463a30
  X0[3] = 0;  // @272_463a30
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X0[0], 4);  // @273_463a30
  L463d8c:;
  ext_633654(G(u32, 0x6f5630));  // @275_463a30
  return eax;  // @276_463a30
}
PCREG(463a30, lifted_463a30);

extern "C" u32 THISCALL lifted_5cc620(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5cc620
  PV[0] = (u32)(esi);  // @1_5cc620
  edi = ecx;  // @2_5cc620
  eax = ext_5ca270_thiscall2(ecx, PV[0]);  // @3_5cc620
  ecx = edx = 0;  // @4_5cc620
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @5_5cc620
  if (FL[2] != 0) goto L5cc63a;  // @6_5cc620
  return eax;  // @7_5cc620
  L5cc63a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5cc620
  eax = (u32)(edi + 1105);  // @10_5cc620
  PV[1] = (u32)(eax);  // @11_5cc620
  ecx = esi;  // @12_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[1]);  // @13_5cc620
  ecx = edx = 0;  // @14_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5cc620
  eax = (u32)(edi + 1117);  // @16_5cc620
  PV[2] = (u32)(eax);  // @17_5cc620
  ecx = esi;  // @18_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[2]);  // @19_5cc620
  ecx = edx = 0;  // @20_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1129) + 0), 4); v; });  // @22_5cc620
  X0[1] = 0;  // @23_5cc620
  X0[2] = 0;  // @24_5cc620
  X0[3] = 0;  // @25_5cc620
  PV[3] = (u32)(ecx);  // @26_5cc620
  ecx = esi;  // @27_5cc620
  PV[4] = X0[0];  // @28_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @29_5cc620
  ecx = edx = 0;  // @30_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1133) + 0), 4); v; });  // @32_5cc620
  X0[1] = 0;  // @33_5cc620
  X0[2] = 0;  // @34_5cc620
  X0[3] = 0;  // @35_5cc620
  PV[5] = (u32)(ecx);  // @36_5cc620
  ecx = esi;  // @37_5cc620
  PV[6] = X0[0];  // @38_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @39_5cc620
  ecx = edx = 0;  // @40_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1145) + 0), 4); v; });  // @42_5cc620
  X0[1] = 0;  // @43_5cc620
  X0[2] = 0;  // @44_5cc620
  X0[3] = 0;  // @45_5cc620
  PV[7] = (u32)(ecx);  // @46_5cc620
  ecx = esi;  // @47_5cc620
  PV[8] = X0[0];  // @48_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @49_5cc620
  ecx = edx = 0;  // @50_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1149) + 0), 4); v; });  // @52_5cc620
  X0[1] = 0;  // @53_5cc620
  X0[2] = 0;  // @54_5cc620
  X0[3] = 0;  // @55_5cc620
  PV[9] = (u32)(ecx);  // @56_5cc620
  ecx = esi;  // @57_5cc620
  PV[10] = X0[0];  // @58_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[10]);  // @59_5cc620
  ecx = edx = 0;  // @60_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1153) + 0), 4); v; });  // @62_5cc620
  X0[1] = 0;  // @63_5cc620
  X0[2] = 0;  // @64_5cc620
  X0[3] = 0;  // @65_5cc620
  PV[11] = (u32)(ecx);  // @66_5cc620
  ecx = esi;  // @67_5cc620
  PV[12] = X0[0];  // @68_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @69_5cc620
  ecx = edx = 0;  // @70_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1157) + 0), 4); v; });  // @72_5cc620
  X0[1] = 0;  // @73_5cc620
  X0[2] = 0;  // @74_5cc620
  X0[3] = 0;  // @75_5cc620
  PV[13] = (u32)(ecx);  // @76_5cc620
  ecx = esi;  // @77_5cc620
  PV[14] = X0[0];  // @78_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @79_5cc620
  ecx = edx = 0;  // @80_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @81_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1161) + 0), 4); v; });  // @82_5cc620
  X0[1] = 0;  // @83_5cc620
  X0[2] = 0;  // @84_5cc620
  X0[3] = 0;  // @85_5cc620
  PV[15] = (u32)(ecx);  // @86_5cc620
  ecx = esi;  // @87_5cc620
  PV[16] = X0[0];  // @88_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[16]);  // @89_5cc620
  ecx = edx = 0;  // @90_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @91_5cc620
  eax = (u32)(edi + 1165);  // @92_5cc620
  PV[17] = (u32)(eax);  // @93_5cc620
  ecx = esi;  // @94_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[17]);  // @95_5cc620
  ecx = edx = 0;  // @96_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_5cc620
  eax = (u32)(edi + 1177);  // @98_5cc620
  PV[18] = (u32)(eax);  // @99_5cc620
  ecx = esi;  // @100_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[18]);  // @101_5cc620
  ecx = edx = 0;  // @102_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @103_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1189) + 0), 4); v; });  // @104_5cc620
  X0[1] = 0;  // @105_5cc620
  X0[2] = 0;  // @106_5cc620
  X0[3] = 0;  // @107_5cc620
  PV[19] = (u32)(ecx);  // @108_5cc620
  ecx = esi;  // @109_5cc620
  PV[20] = X0[0];  // @110_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @111_5cc620
  ecx = edx = 0;  // @112_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @113_5cc620
  ecx = esi;  // @114_5cc620
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1193), sizeof v); (u32)v; });  // @115_5cc620
  PV[21] = (u32)(eax);  // @116_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[21]);  // @117_5cc620
  ecx = edx = 0;  // @118_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @119_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1194) + 0), 4); v; });  // @120_5cc620
  X0[1] = 0;  // @121_5cc620
  X0[2] = 0;  // @122_5cc620
  X0[3] = 0;  // @123_5cc620
  PV[22] = (u32)(ecx);  // @124_5cc620
  ecx = esi;  // @125_5cc620
  PV[23] = X0[0];  // @126_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[23]);  // @127_5cc620
  ecx = edx = 0;  // @128_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_5cc620
  PV[24] = (u32)(ecx);  // @130_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1198) + 0), 4); v; });  // @131_5cc620
  X0[1] = 0;  // @132_5cc620
  X0[2] = 0;  // @133_5cc620
  X0[3] = 0;  // @134_5cc620
  ecx = esi;  // @135_5cc620
  PV[25] = X0[0];  // @136_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[25]);  // @137_5cc620
  ecx = edx = 0;  // @138_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @139_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1202) + 0), 4); v; });  // @140_5cc620
  X0[1] = 0;  // @141_5cc620
  X0[2] = 0;  // @142_5cc620
  X0[3] = 0;  // @143_5cc620
  PV[26] = (u32)(ecx);  // @144_5cc620
  ecx = esi;  // @145_5cc620
  PV[27] = X0[0];  // @146_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @147_5cc620
  ecx = edx = 0;  // @148_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1206), sizeof v); (u32)v; });  // @149_5cc620
  PV[28] = (u32)(ecx);  // @150_5cc620
  ecx = 0;  // @151_5cc620
  PV[29] = eax;  // @152_5cc620
  ecx = esi;  // @153_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @154_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[29]);  // @155_5cc620
  ecx = edx = 0;  // @156_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @157_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1210) + 0), 4); v; });  // @158_5cc620
  X0[1] = 0;  // @159_5cc620
  X0[2] = 0;  // @160_5cc620
  X0[3] = 0;  // @161_5cc620
  PV[30] = (u32)(ecx);  // @162_5cc620
  ecx = esi;  // @163_5cc620
  PV[31] = X0[0];  // @164_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[31]);  // @165_5cc620
  ecx = edx = 0;  // @166_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @167_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1214) + 0), 4); v; });  // @168_5cc620
  X0[1] = 0;  // @169_5cc620
  X0[2] = 0;  // @170_5cc620
  X0[3] = 0;  // @171_5cc620
  PV[32] = (u32)(ecx);  // @172_5cc620
  ecx = esi;  // @173_5cc620
  PV[33] = X0[0];  // @174_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[33]);  // @175_5cc620
  ecx = edx = 0;  // @176_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @177_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1218) + 0), 4); v; });  // @178_5cc620
  X0[1] = 0;  // @179_5cc620
  X0[2] = 0;  // @180_5cc620
  X0[3] = 0;  // @181_5cc620
  PV[34] = (u32)(ecx);  // @182_5cc620
  ecx = esi;  // @183_5cc620
  PV[35] = X0[0];  // @184_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[35]);  // @185_5cc620
  ecx = edx = 0;  // @186_5cc620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @187_5cc620
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1222) + 0), 4); v; });  // @188_5cc620
  X0[1] = 0;  // @189_5cc620
  X0[2] = 0;  // @190_5cc620
  X0[3] = 0;  // @191_5cc620
  PV[36] = (u32)(ecx);  // @192_5cc620
  ecx = esi;  // @193_5cc620
  PV[37] = X0[0];  // @194_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[37]);  // @195_5cc620
  ecx = edx = 0;  // @196_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @197_5cc620
  ecx = esi;  // @198_5cc620
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1226), sizeof v); (u32)v; });  // @199_5cc620
  PV[38] = (u32)(eax);  // @200_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[38]);  // @201_5cc620
  ecx = edx = 0;  // @202_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @203_5cc620
  eax = (u32)(edi + 1227);  // @204_5cc620
  PV[39] = (u32)(eax);  // @205_5cc620
  ecx = esi;  // @206_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[39]);  // @207_5cc620
  ecx = edx = 0;  // @208_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @209_5cc620
  eax = (u32)(edi + 1240);  // @210_5cc620
  PV[40] = (u32)(eax);  // @211_5cc620
  ecx = esi;  // @212_5cc620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[40], (u32)(4));  // @213_5cc620
  ecx = edx = 0;  // @214_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @215_5cc620
  eax = (u32)(edi + 1244);  // @216_5cc620
  PV[41] = (u32)(eax);  // @217_5cc620
  ecx = esi;  // @218_5cc620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[41], (u32)(4));  // @219_5cc620
  ecx = edx = 0;  // @220_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_5cc620
  eax = (u32)(edi + 1248);  // @222_5cc620
  PV[42] = (u32)(eax);  // @223_5cc620
  ecx = esi;  // @224_5cc620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[42], (u32)(4));  // @225_5cc620
  ecx = edx = 0;  // @226_5cc620
  PV[43] = (u32)(esi);  // @227_5cc620
  ecx = (u32)(edi + 1252);  // @228_5cc620
  eax = ext_662660_thiscall2(ecx, PV[43]);  // @229_5cc620
  ecx = edx = 0;  // @230_5cc620
  PV[44] = (u32)(esi);  // @231_5cc620
  ecx = (u32)(edi + 1297);  // @232_5cc620
  eax = ext_662660_thiscall2(ecx, PV[44]);  // @233_5cc620
  ecx = edx = 0;  // @234_5cc620
  PV[45] = (u32)(esi);  // @235_5cc620
  ecx = (u32)(edi + 1342);  // @236_5cc620
  eax = ext_662660_thiscall2(ecx, PV[45]);  // @237_5cc620
  ecx = edx = 0;  // @238_5cc620
  PV[46] = (u32)(esi);  // @239_5cc620
  ecx = (u32)(edi + 1387);  // @240_5cc620
  eax = ext_662660_thiscall2(ecx, PV[46]);  // @241_5cc620
  ecx = edx = 0;  // @242_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @243_5cc620
  ecx = esi;  // @244_5cc620
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1432), sizeof v); (u32)v; });  // @245_5cc620
  PV[47] = (u32)(eax);  // @246_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[47]);  // @247_5cc620
  ecx = edx = 0;  // @248_5cc620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @249_5cc620
  ecx = esi;  // @250_5cc620
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1433), sizeof v); (u32)v; });  // @251_5cc620
  PV[48] = (u32)(eax);  // @252_5cc620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[48]);  // @253_5cc620
  ecx = edx = 0;  // @254_5cc620
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @255_5cc620
  return eax;  // @256_5cc620
}
PCREG(5cc620, lifted_5cc620);

extern "C" u32 THISCALL lifted_451d00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_451d00
  edi = ecx;  // @1_451d00
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @2_451d00
  PV[0] = (u32)(ebx);  // @3_451d00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @4_451d00
  eax = ext_610100_stdcall1(PV[0]);  // @5_451d00
  ecx = edx = 0;  // @6_451d00
  eax = (u32)(EBP - 52);  // @7_451d00
  ecx = ebx;  // @8_451d00
  PV[1] = (u32)(eax);  // @9_451d00
  eax = ext_4e0f60_thiscall2(ecx, PV[1]);  // @10_451d00
  ecx = edx = 0;  // @11_451d00
  ecx = eax;  // @12_451d00
  FL[2] = (ecx & ecx);  // @13_451d00
  if ((s32)FL[2] <= 0) goto L451e98;  // @14_451d00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @15_451d00
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @16_451d00
  X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 4), 4); v; });  // @17_451d00
  X1[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 8), 4); v; });  // @18_451d00
  X1[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 12), 4); v; });  // @19_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @20_451d00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 4), 4); v; });  // @21_451d00
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 8), 4); v; });  // @22_451d00
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 12), 4); v; });  // @23_451d00
  eax = X1[0];  // @24_451d00
  __builtin_memcpy((void *)((u32)(EBP - 96) + 0), &X1[0], 4);  // @25_451d00
  __builtin_memcpy((void *)((u32)(EBP - 96) + 4), &X1[1], 4);  // @26_451d00
  __builtin_memcpy((void *)((u32)(EBP - 96) + 8), &X1[2], 4);  // @27_451d00
  __builtin_memcpy((void *)((u32)(EBP - 96) + 12), &X1[3], 4);  // @28_451d00
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @29_451d00
  __builtin_memcpy((void *)((u32)(EBP - 80) + 4), &X0[1], 4);  // @30_451d00
  __builtin_memcpy((void *)((u32)(EBP - 80) + 8), &X0[2], 4);  // @31_451d00
  __builtin_memcpy((void *)((u32)(EBP - 80) + 12), &X0[3], 4);  // @32_451d00
  FL[0] = eax; FL[1] = (u32)(1);  // @33_451d00
  if (FL[0] < FL[1]) goto L451dda;  // @34_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @35_451d00
  X0[1] = 0;  // @36_451d00
  X0[2] = 0;  // @37_451d00
  X0[3] = 0;  // @38_451d00
  ecx = (ecx + (u32)(-32));  // @39_451d00
  FL[3] = ecx;  // @40_451d00
  eax = (u32)(138547333);  // @41_451d00
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @42_451d00
  ecx = (ecx - edx);  // @43_451d00
  FL[3] = ecx;  // @44_451d00
  ecx = (ecx >> (u32)(1));  // @45_451d00
  FL[3] = ecx;  // @46_451d00
  ecx = (ecx + edx);  // @47_451d00
  FL[3] = ecx;  // @48_451d00
  edx = (u32)(124);  // @49_451d00
  ecx = (ecx >> (u32)(6));  // @50_451d00
  FL[3] = ecx;  // @51_451d00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @52_451d00
  ecx = 0;  // @53_451d00
  FL[3] = ecx;  // @54_451d00
  __builtin_memcpy((void *)((u32)(edi + 24) + 0), &X0[0], 4);  // @55_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @56_451d00
  X0[1] = 0;  // @57_451d00
  X0[2] = 0;  // @58_451d00
  X0[3] = 0;  // @59_451d00
  __builtin_memcpy((void *)((u32)(edi + 28) + 0), &X0[0], 4);  // @60_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @61_451d00
  X0[1] = 0;  // @62_451d00
  X0[2] = 0;  // @63_451d00
  X0[3] = 0;  // @64_451d00
  __builtin_memcpy((void *)((u32)(edi + 32) + 0), &X0[0], 4);  // @65_451d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @66_451d00
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @67_451d00
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @68_451d00
  FL[1] = ecx;  // @69_451d00
  ecx = (0u - ecx);  // @70_451d00
  ecx = (ecx | eax);  // @71_451d00
  FL[3] = ecx;  // @72_451d00
  PV[2] = (u32)(ecx);  // @73_451d00
  eax = ext_41e290_cdecl1(PV[2]);  // @74_451d00
  ecx = edx = 0;  // @75_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @76_451d00
  X0[1] = 0;  // @77_451d00
  X0[2] = 0;  // @78_451d00
  X0[3] = 0;  // @79_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @80_451d00
  __builtin_memcpy((void *)((u32)(edi + 48) + 0), &X0[0], 4);  // @81_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @82_451d00
  X0[1] = 0;  // @83_451d00
  X0[2] = 0;  // @84_451d00
  X0[3] = 0;  // @85_451d00
  __builtin_memcpy((void *)((u32)(edi + 52) + 0), &X0[0], 4);  // @86_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @87_451d00
  X0[1] = 0;  // @88_451d00
  X0[2] = 0;  // @89_451d00
  X0[3] = 0;  // @90_451d00
  __builtin_memcpy((void *)((u32)(edi + 56) + 0), &X0[0], 4);  // @91_451d00
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }) * (s32)(u32)(124));  // @92_451d00
  PV[3] = (u32)(eax);  // @93_451d00
  eax = (u32)(esi + 32);  // @94_451d00
  PV[4] = (u32)(eax);  // @95_451d00
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @96_451d00
  eax = ext_634d22_cdecl3(PV[5], PV[4], PV[3]);  // @97_451d00
  ecx = edx = 0;  // @98_451d00
  L451dda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @100_451d00
  ecx = 0;  // @101_451d00
  FL[3] = ecx;  // @102_451d00
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @103_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @104_451d00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @105_451d00
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; }); FL[1] = ecx;  // @106_451d00
  if (FL[0] == FL[1]) goto L451e68;  // @107_451d00
  L451df0:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) & (u32)(128));  // @109_451d00
  if (FL[2] != 0) goto L451e59;  // @110_451d00
  esi = (u32)(eax + 28);  // @111_451d00
  edi = (u32)(8);  // @112_451d00
  eax = (eax + (u32)(16));  // @113_451d00
  FL[3] = eax;  // @114_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @115_451d00
  L451e04:;
  PV[6] = (u32)(esi);  // @117_451d00
  edx = eax;  // @118_451d00
  ecx = (u32)(EBP - 16);  // @119_451d00
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[6]);  // @120_451d00
  ecx = edx = 0;  // @121_451d00
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @122_451d00
  if (FL[2] == 0) goto L451e2f;  // @123_451d00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @124_451d00
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @125_451d00
  X0[2] = 0;  // @126_451d00
  X0[3] = 0;  // @127_451d00
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @128_451d00
  FL[3] = (ebx & 0xff);  // @129_451d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @130_451d00
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @131_451d00
  __builtin_memcpy((void *)((u32)(EBP - 40) + 4), &X0[1], 4);  // @132_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @133_451d00
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @134_451d00
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @135_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @136_451d00
  goto L451e45;  // @137_451d00
  L451e2f:;
  edx = (u32)(EBP - 16);  // @139_451d00
  ecx = (u32)(EBP - 40);  // @140_451d00
  eax = ext_4e0900_fastcall2(ecx, edx);  // @141_451d00
  ecx = edx = 0;  // @142_451d00
  edx = (u32)(EBP - 16);  // @143_451d00
  ecx = (u32)(EBP - 28);  // @144_451d00
  eax = ext_4e08d0_fastcall2(ecx, edx);  // @145_451d00
  ecx = edx = 0;  // @146_451d00
  L451e45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @148_451d00
  esi = (esi + (u32)(12));  // @149_451d00
  FL[3] = esi;  // @150_451d00
  edi = (edi - (u32)(1));  // @151_451d00
  FL[3] = edi;  // @152_451d00
  if (FL[3] != 0) goto L451e04;  // @153_451d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @154_451d00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @155_451d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @156_451d00
  L451e59:;
  ecx = (ecx + 1);  // @158_451d00
  FL[3] = ecx;  // @159_451d00
  eax = (eax + (u32)(124));  // @160_451d00
  FL[3] = eax;  // @161_451d00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @162_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @163_451d00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @164_451d00
  if (FL[0] != FL[1]) goto L451df0;  // @165_451d00
  L451e68:;
  eax = (u32)(EBP - 40);  // @167_451d00
  esi = (u32)(edi + 24);  // @168_451d00
  PV[7] = (u32)(eax);  // @169_451d00
  edx = (u32)(EBP - 28);  // @170_451d00
  ecx = esi;  // @171_451d00
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @172_451d00
  ecx = edx = 0;  // @173_451d00
  PV[8] = (u32)(ecx);  // @174_451d00
  ecx = esi;  // @175_451d00
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1056964608));  // @176_451d00
  ecx = edx = 0;  // @177_451d00
  PV[9] = (u32)(esi);  // @178_451d00
  ecx = (u32)(edi + 36);  // @179_451d00
  edx = (u32)(EBP - 28);  // @180_451d00
  eax = ext_43e920_fastcall3(ecx, edx, PV[9]);  // @181_451d00
  ecx = edx = 0;  // @182_451d00
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @183_451d00
  L451e98:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @185_451d00
  if (FL[0] != FL[1]) goto L451f9d;  // @186_451d00
  eax = ext_41e290_cdecl1((u32)(124));  // @187_451d00
  ecx = edx = 0;  // @188_451d00
  PV[10] = (u32)(eax);  // @189_451d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @190_451d00
  eax = ext_634d10_cdecl3(PV[10], (u32)(0), (u32)(124));  // @191_451d00
  ecx = edx = 0;  // @192_451d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @193_451d00
  ecx = (u32)(1);  // @194_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @195_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @196_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @197_451d00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 64), &v, sizeof v); }  // @198_451d00
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @199_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @200_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 32), &v, sizeof v); }  // @201_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 36), &v, sizeof v); }  // @202_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 40), &v, sizeof v); }  // @203_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 44), &v, sizeof v); }  // @204_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @205_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 52), &v, sizeof v); }  // @206_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 56), &v, sizeof v); }  // @207_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 60), &v, sizeof v); }  // @208_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 64), &v, sizeof v); }  // @209_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @210_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 72), &v, sizeof v); }  // @211_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 76), &v, sizeof v); }  // @212_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 80), &v, sizeof v); }  // @213_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 84), &v, sizeof v); }  // @214_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 88), &v, sizeof v); }  // @215_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 92), &v, sizeof v); }  // @216_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 96), &v, sizeof v); }  // @217_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 100), &v, sizeof v); }  // @218_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 104), &v, sizeof v); }  // @219_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 108), &v, sizeof v); }  // @220_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 112), &v, sizeof v); }  // @221_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(eax + 116), &v, sizeof v); }  // @222_451d00
  { u32 v = (u32)((u32)(3267887104)); __builtin_memcpy((void *)(u32)(eax + 120), &v, sizeof v); }  // @223_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @224_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @225_451d00
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @226_451d00
  L451f9d:;
  ecx = ebx;  // @228_451d00
  eax = ext_4e1b30_thiscall1(ecx);  // @229_451d00
  ecx = edx = 0;  // @230_451d00
  ext_633654(G(u32, 0x6f5630));  // @231_451d00
  return eax;  // @232_451d00
}
PCREG(451d00, lifted_451d00);

extern "C" u32 THISCALL lifted_58a680(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_58a680
  ebx = (u32)(esi + 4);  // @2_58a680
  eax = (eax + 1);  // @3_58a680
  FL[3] = eax;  // @4_58a680
  eax = (u32)(esi + eax*4);  // @5_58a680
  FL[0] = ebx; FL[1] = eax;  // @6_58a680
  if (FL[0] == FL[1]) goto L58a79a;  // @7_58a680
  edi = (u32)(4294967292);  // @8_58a680
  edi = (edi - esi);  // @9_58a680
  FL[3] = edi;  // @10_58a680
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @11_58a680
  L58a6b0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_58a680
  edx = (u32)(EBP - 16);  // @14_58a680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @15_58a680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @16_58a680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @17_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_58a680
  PV[0] = (u32)(edx);  // @19_58a680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[0]);  // @20_58a680
  ecx = edx = 0;  // @21_58a680
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @22_58a680
  X0[1] = 0;  // @23_58a680
  X0[2] = 0;  // @24_58a680
  X0[3] = 0;  // @25_58a680
  eax = (u32)(esi + 4);  // @26_58a680
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @27_58a680
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @28_58a680
  FL[0] = ebx; FL[1] = eax;  // @29_58a680
  if (FL[0] == FL[1]) goto L58a779;  // @30_58a680
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @31_58a680
  X0[1] = 0;  // @32_58a680
  X0[2] = 0;  // @33_58a680
  X0[3] = 0;  // @34_58a680
  edi = (edi + ebx);  // @35_58a680
  FL[3] = edi;  // @36_58a680
  edi = (u32)((s32)edi >> (u32)(2));  // @37_58a680
  FL[3] = edi;  // @38_58a680
  X1[0] = 0;  // @39_58a680
  X1[1] = 0;  // @40_58a680
  X1[2] = 0;  // @41_58a680
  X1[3] = 0;  // @42_58a680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*4 + 128), sizeof v); (u32)v; });  // @43_58a680
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L58a74d;  // @44_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_58a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @47_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_58a680
  FL[2] = (edx & edx);  // @49_58a680
  if (FL[2] != 0) goto L58a73c;  // @50_58a680
  edx = (u32)(EBP - 16);  // @51_58a680
  PV[1] = (u32)(edx);  // @52_58a680
  edx = (u32)(EBP - 28);  // @53_58a680
  PV[2] = (u32)(edx);  // @54_58a680
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[2], PV[1], (u32)(16776960));  // @55_58a680
  ecx = edx = 0;  // @56_58a680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi*4 + 128), &v, sizeof v); }  // @57_58a680
  goto L58a776;  // @58_58a680
  L58a73c:;
  edi = (u32)(EBP - 16);  // @60_58a680
  PV[3] = (u32)(edi);  // @61_58a680
  edi = (u32)(EBP - 28);  // @62_58a680
  PV[4] = (u32)(edi);  // @63_58a680
  PV[5] = (u32)(edx);  // @64_58a680
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[5], PV[4], PV[3]);  // @65_58a680
  ecx = edx = 0;  // @66_58a680
  goto L58a776;  // @67_58a680
  L58a74d:;
  FL[2] = (edx & edx);  // @69_58a680
  if (FL[2] == 0) goto L58a776;  // @70_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_58a680
  PV[6] = (u32)(edx);  // @72_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @73_58a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @74_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_58a680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[6]);  // @76_58a680
  ecx = edx = 0;  // @77_58a680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edi*4 + 128), &v, sizeof v); }  // @78_58a680
  L58a776:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @80_58a680
  L58a779:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @82_58a680
  ebx = (ebx + (u32)(4));  // @83_58a680
  FL[3] = ebx;  // @84_58a680
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @85_58a680
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @86_58a680
  X0[2] = 0;  // @87_58a680
  X0[3] = 0;  // @88_58a680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @89_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_58a680
  eax = (eax + 1);  // @91_58a680
  FL[3] = eax;  // @92_58a680
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @93_58a680
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @94_58a680
  eax = (u32)(esi + eax*4);  // @95_58a680
  FL[0] = ebx; FL[1] = eax;  // @96_58a680
  if (FL[0] != FL[1]) goto L58a6b0;  // @97_58a680
  L58a79a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @99_58a680
  ebx = (u32)(esi + 60);  // @100_58a680
  eax = (eax + (u32)(15));  // @101_58a680
  FL[3] = eax;  // @102_58a680
  edi = ebx;  // @103_58a680
  eax = (u32)(esi + eax*4);  // @104_58a680
  FL[0] = edi; FL[1] = eax;  // @105_58a680
  if (FL[0] == FL[1]) goto L58a7d9;  // @106_58a680
  L58a7b0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @108_58a680
  eax = ext_59d370_thiscall1(ecx);  // @109_58a680
  ecx = edx = 0;  // @110_58a680
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @111_58a680
  if (FL[2] == 0) goto L58a7c9;  // @112_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @113_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4 + 56), sizeof v); (u32)v; });  // @114_58a680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @115_58a680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @116_58a680
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @117_58a680
  goto L58a7cc;  // @118_58a680
  L58a7c9:;
  edi = (edi + (u32)(4));  // @120_58a680
  FL[3] = edi;  // @121_58a680
  L58a7cc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @123_58a680
  eax = (eax + (u32)(15));  // @124_58a680
  FL[3] = eax;  // @125_58a680
  eax = (u32)(esi + eax*4);  // @126_58a680
  FL[0] = edi; FL[1] = eax;  // @127_58a680
  if (FL[0] != FL[1]) goto L58a7b0;  // @128_58a680
  L58a7d9:;
  eax = (u32)(EBP - 40);  // @130_58a680
  ecx = esi;  // @131_58a680
  PV[7] = (u32)(eax);  // @132_58a680
  eax = ext_589b50_thiscall2(ecx, PV[7]);  // @133_58a680
  ecx = edx = 0;  // @134_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @135_58a680
  eax = (eax + (u32)(15));  // @136_58a680
  FL[3] = eax;  // @137_58a680
  eax = (u32)(esi + eax*4);  // @138_58a680
  FL[0] = ebx; FL[1] = eax;  // @139_58a680
  if (FL[0] == FL[1]) goto L58a8b5;  // @140_58a680
  edi = ebx;  // @141_58a680
  edi = (edi - esi);  // @142_58a680
  FL[3] = edi;  // @143_58a680
  edi = (edi - (u32)(60));  // @144_58a680
  FL[3] = edi;  // @145_58a680
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @146_58a680
  L58a800:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @148_58a680
  edx = (u32)(EBP - 16);  // @149_58a680
  PV[8] = (u32)(edx);  // @150_58a680
  edx = (u32)(EBP - 76);  // @151_58a680
  PV[9] = (u32)(edx);  // @152_58a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @153_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_58a680
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[9], PV[8]);  // @155_58a680
  ecx = edx = 0;  // @156_58a680
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @157_58a680
  X0[1] = 0;  // @158_58a680
  X0[2] = 0;  // @159_58a680
  X0[3] = 0;  // @160_58a680
  X1[0] = 0;  // @161_58a680
  X1[1] = 0;  // @162_58a680
  X1[2] = 0;  // @163_58a680
  X1[3] = 0;  // @164_58a680
  edi = (u32)((s32)edi >> (u32)(2));  // @165_58a680
  FL[3] = edi;  // @166_58a680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi*4 + 180), sizeof v); (u32)v; });  // @167_58a680
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L58a86f;  // @168_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @170_58a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @171_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_58a680
  FL[2] = (edx & edx);  // @173_58a680
  if (FL[2] != 0) goto L58a85e;  // @174_58a680
  edx = (u32)(EBP - 16);  // @175_58a680
  PV[10] = (u32)(edx);  // @176_58a680
  edx = (u32)(EBP - 40);  // @177_58a680
  PV[11] = (u32)(edx);  // @178_58a680
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[11], PV[10], (u32)(16711680));  // @179_58a680
  ecx = edx = 0;  // @180_58a680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi*4 + 180), &v, sizeof v); }  // @181_58a680
  goto L58a898;  // @182_58a680
  L58a85e:;
  edi = (u32)(EBP - 16);  // @184_58a680
  PV[12] = (u32)(edi);  // @185_58a680
  edi = (u32)(EBP - 40);  // @186_58a680
  PV[13] = (u32)(edi);  // @187_58a680
  PV[14] = (u32)(edx);  // @188_58a680
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[14], PV[13], PV[12]);  // @189_58a680
  ecx = edx = 0;  // @190_58a680
  goto L58a898;  // @191_58a680
  L58a86f:;
  FL[2] = (edx & edx);  // @193_58a680
  if (FL[2] == 0) goto L58a898;  // @194_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @195_58a680
  PV[15] = (u32)(edx);  // @196_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @197_58a680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @198_58a680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_58a680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[15]);  // @200_58a680
  ecx = edx = 0;  // @201_58a680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edi*4 + 180), &v, sizeof v); }  // @202_58a680
  L58a898:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @204_58a680
  ebx = (ebx + (u32)(4));  // @205_58a680
  FL[3] = ebx;  // @206_58a680
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @207_58a680
  eax = (eax + (u32)(15));  // @208_58a680
  FL[3] = eax;  // @209_58a680
  edi = (edi + (u32)(4));  // @210_58a680
  FL[3] = edi;  // @211_58a680
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @212_58a680
  eax = (u32)(esi + eax*4);  // @213_58a680
  FL[0] = ebx; FL[1] = eax;  // @214_58a680
  if (FL[0] != FL[1]) goto L58a800;  // @215_58a680
  L58a8b5:;
  ext_633654(G(u32, 0x6f5630));  // @217_58a680
  return eax;  // @218_58a680
}
PCREG(58a680, lifted_58a680);

extern "C" u32 THISCALL lifted_5213f0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5213f0
  PV[0] = (u32)(esi);  // @1_5213f0
  edi = ecx;  // @2_5213f0
  eax = ext_515b70_thiscall2(ecx, PV[0]);  // @3_5213f0
  ecx = edx = 0;  // @4_5213f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @5_5213f0
  if (FL[2] != 0) goto L52140a;  // @6_5213f0
  return eax;  // @7_5213f0
  L52140a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_5213f0
  eax = (u32)(edi + 728);  // @10_5213f0
  PV[1] = (u32)(eax);  // @11_5213f0
  ecx = esi;  // @12_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[1]);  // @13_5213f0
  ecx = edx = 0;  // @14_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5213f0
  eax = (u32)(edi + 740);  // @16_5213f0
  PV[2] = (u32)(eax);  // @17_5213f0
  ecx = esi;  // @18_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[2]);  // @19_5213f0
  ecx = edx = 0;  // @20_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_5213f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 752) + 0), 4); v; });  // @22_5213f0
  X0[1] = 0;  // @23_5213f0
  X0[2] = 0;  // @24_5213f0
  X0[3] = 0;  // @25_5213f0
  PV[3] = (u32)(ecx);  // @26_5213f0
  ecx = esi;  // @27_5213f0
  PV[4] = X0[0];  // @28_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @29_5213f0
  ecx = edx = 0;  // @30_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_5213f0
  eax = (u32)(edi + 756);  // @32_5213f0
  PV[5] = (u32)(eax);  // @33_5213f0
  ecx = esi;  // @34_5213f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[5], (u32)(4));  // @35_5213f0
  ecx = edx = 0;  // @36_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_5213f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 760) + 0), 4); v; });  // @38_5213f0
  X0[1] = 0;  // @39_5213f0
  X0[2] = 0;  // @40_5213f0
  X0[3] = 0;  // @41_5213f0
  PV[6] = (u32)(ecx);  // @42_5213f0
  ecx = esi;  // @43_5213f0
  PV[7] = X0[0];  // @44_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @45_5213f0
  ecx = edx = 0;  // @46_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_5213f0
  ecx = esi;  // @48_5213f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 764), sizeof v); (u32)v; });  // @49_5213f0
  PV[8] = (u32)(eax);  // @50_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[8]);  // @51_5213f0
  ecx = edx = 0;  // @52_5213f0
  PV[9] = (u32)(esi);  // @53_5213f0
  ecx = (u32)(edi + 765);  // @54_5213f0
  eax = ext_528c80_thiscall2(ecx, PV[9]);  // @55_5213f0
  ecx = edx = 0;  // @56_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_5213f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 9677) + 0), 4); v; });  // @58_5213f0
  X0[1] = 0;  // @59_5213f0
  X0[2] = 0;  // @60_5213f0
  X0[3] = 0;  // @61_5213f0
  PV[10] = (u32)(ecx);  // @62_5213f0
  ecx = esi;  // @63_5213f0
  PV[11] = X0[0];  // @64_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[11]);  // @65_5213f0
  ecx = edx = 0;  // @66_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @67_5213f0
  ecx = esi;  // @68_5213f0
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9681), sizeof v); (u32)v; });  // @69_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[12]);  // @70_5213f0
  ecx = edx = 0;  // @71_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_5213f0
  ecx = esi;  // @73_5213f0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9685), sizeof v); (u32)v; });  // @74_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[13]);  // @75_5213f0
  ecx = edx = 0;  // @76_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_5213f0
  ecx = esi;  // @78_5213f0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9689), sizeof v); (u32)v; });  // @79_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[14]);  // @80_5213f0
  ecx = edx = 0;  // @81_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_5213f0
  ecx = esi;  // @83_5213f0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9693), sizeof v); (u32)v; });  // @84_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[15]);  // @85_5213f0
  ecx = edx = 0;  // @86_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @87_5213f0
  ecx = esi;  // @88_5213f0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9697), sizeof v); (u32)v; });  // @89_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[16]);  // @90_5213f0
  ecx = edx = 0;  // @91_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_5213f0
  eax = (u32)(edi + 9701);  // @93_5213f0
  PV[17] = (u32)(eax);  // @94_5213f0
  ecx = esi;  // @95_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[17]);  // @96_5213f0
  ecx = edx = 0;  // @97_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_5213f0
  eax = (u32)(edi + 9713);  // @99_5213f0
  PV[18] = (u32)(eax);  // @100_5213f0
  ecx = esi;  // @101_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[18]);  // @102_5213f0
  ecx = edx = 0;  // @103_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_5213f0
  eax = (u32)(edi + 9725);  // @105_5213f0
  PV[19] = (u32)(eax);  // @106_5213f0
  ecx = esi;  // @107_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[19]);  // @108_5213f0
  ecx = edx = 0;  // @109_5213f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9737), sizeof v); (u32)v; });  // @110_5213f0
  ecx = esi;  // @111_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_5213f0
  PV[20] = (u32)(eax);  // @113_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[20]);  // @114_5213f0
  ecx = edx = 0;  // @115_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_5213f0
  ecx = esi;  // @117_5213f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9738), sizeof v); (u32)v; });  // @118_5213f0
  PV[21] = (u32)(eax);  // @119_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[21]);  // @120_5213f0
  ecx = edx = 0;  // @121_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_5213f0
  ecx = esi;  // @123_5213f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9739), sizeof v); (u32)v; });  // @124_5213f0
  PV[22] = (u32)(eax);  // @125_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[22]);  // @126_5213f0
  ecx = edx = 0;  // @127_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @128_5213f0
  ecx = esi;  // @129_5213f0
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9740), sizeof v); (u32)v; });  // @130_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[23]);  // @131_5213f0
  ecx = edx = 0;  // @132_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @133_5213f0
  ecx = esi;  // @134_5213f0
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9744), sizeof v); (u32)v; });  // @135_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[24]);  // @136_5213f0
  ecx = edx = 0;  // @137_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_5213f0
  ecx = esi;  // @139_5213f0
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9748), sizeof v); (u32)v; });  // @140_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[25]);  // @141_5213f0
  ecx = edx = 0;  // @142_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @143_5213f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 9752) + 0), 4); v; });  // @144_5213f0
  X0[1] = 0;  // @145_5213f0
  X0[2] = 0;  // @146_5213f0
  X0[3] = 0;  // @147_5213f0
  PV[26] = (u32)(ecx);  // @148_5213f0
  ecx = esi;  // @149_5213f0
  PV[27] = X0[0];  // @150_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @151_5213f0
  ecx = edx = 0;  // @152_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @153_5213f0
  ecx = esi;  // @154_5213f0
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9760), sizeof v); (u32)v; });  // @155_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[28]);  // @156_5213f0
  ecx = edx = 0;  // @157_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_5213f0
  eax = (u32)(edi + 9764);  // @159_5213f0
  PV[29] = (u32)(eax);  // @160_5213f0
  ecx = esi;  // @161_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[29]);  // @162_5213f0
  ecx = edx = 0;  // @163_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @164_5213f0
  eax = (u32)(edi + 9776);  // @165_5213f0
  PV[30] = (u32)(eax);  // @166_5213f0
  ecx = esi;  // @167_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[30]);  // @168_5213f0
  ecx = edx = 0;  // @169_5213f0
  PV[31] = (u32)(esi);  // @170_5213f0
  ecx = (u32)(edi + 9788);  // @171_5213f0
  eax = ext_5274f0_thiscall2(ecx, PV[31]);  // @172_5213f0
  ecx = edx = 0;  // @173_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_5213f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 9869) + 0), 4); v; });  // @175_5213f0
  X0[1] = 0;  // @176_5213f0
  X0[2] = 0;  // @177_5213f0
  X0[3] = 0;  // @178_5213f0
  PV[32] = (u32)(ecx);  // @179_5213f0
  ecx = esi;  // @180_5213f0
  PV[33] = X0[0];  // @181_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[33]);  // @182_5213f0
  ecx = edx = 0;  // @183_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @184_5213f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 9873) + 0), 4); v; });  // @185_5213f0
  X0[1] = 0;  // @186_5213f0
  X0[2] = 0;  // @187_5213f0
  X0[3] = 0;  // @188_5213f0
  PV[34] = (u32)(ecx);  // @189_5213f0
  ecx = esi;  // @190_5213f0
  PV[35] = X0[0];  // @191_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[35]);  // @192_5213f0
  ecx = edx = 0;  // @193_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @194_5213f0
  ecx = esi;  // @195_5213f0
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9958), sizeof v); (u32)v; });  // @196_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[36]);  // @197_5213f0
  ecx = edx = 0;  // @198_5213f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @199_5213f0
  ecx = esi;  // @200_5213f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9990), sizeof v); (u32)v; });  // @201_5213f0
  PV[37] = (u32)(eax);  // @202_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[37]);  // @203_5213f0
  ecx = edx = 0;  // @204_5213f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @205_5213f0
  ecx = esi;  // @206_5213f0
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 9962), sizeof v); (u32)v; });  // @207_5213f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[38]);  // @208_5213f0
  ecx = edx = 0;  // @209_5213f0
  PV[39] = (u32)(esi);  // @210_5213f0
  ecx = (u32)(edi + 9877);  // @211_5213f0
  eax = ext_5274f0_thiscall2(ecx, PV[39]);  // @212_5213f0
  ecx = edx = 0;  // @213_5213f0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @214_5213f0
  return eax;  // @215_5213f0
}
PCREG(5213f0, lifted_5213f0);

