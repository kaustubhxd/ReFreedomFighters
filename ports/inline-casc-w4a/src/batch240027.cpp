// batch240027.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 THISCALL ext_484b10_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_484b10");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4db550_thiscall1(u32) __asm__("ext_4db550");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e9200_thiscall4(u32, u32, u32, u32) __asm__("ext_4e9200");
extern "C" u32 THISCALL ext_4ea300_thiscall2(u32, u32) __asm__("ext_4ea300");
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

static inline u32 w4a_ce1(u32 fn, u32 self, u32 a1) { u32 r; asm volatile("push %[a1]; call *%[f]; add $4, %%esp" : "=a"(r) : [f] "r"(fn), "c"(self), [a1] "r"(a1) : "edx", "memory", "cc"); return r; }
static inline u32 w4a_ce2(u32 fn, u32 self, u32 a1, u32 a2) { u32 r; asm volatile("push %[a2]; push %[a1]; call *%[f]; add $8, %%esp" : "=a"(r) : [f] "r"(fn), "c"(self), [a1] "r"(a1), [a2] "r"(a2) : "edx", "memory", "cc"); return r; }
extern "C" u32 THISCALL lifted_482b80(u32 ecx_in) {
  SEH_ENTER(0x66756b);  // @h_482b80
  u8 F[0xcae0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0xc9e0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0; u32 CFv = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 w4a_p = 0; u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  w4a_p = 0; goto L482def;  // @158_482b80
  L482ded:; w4a_p = 1;
  L482def:;
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1408)))(ecx, w4a_p);  // @161_482b80 (hand fix: one argument, 1 when the previous query was false, else 0)
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
  eax = w4a_ce2(*(u32 *)(edx + 220), ecx, (u32)(6865064), PV[17]);  // @225_482b80 (hand fix: variadic member call: cdecl with ecx = this)
  ecx = edx = 0;  // @226_482b80
  ecx = eax;  // @227_482b80
  eax = (u32)(715827883);  // @228_482b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @229_482b80
  eax = edx;  // @230_482b80
  eax = (eax >> (u32)(31));  // @231_482b80
  FL[3] = eax;  // @232_482b80
  CFv = ((u32)(eax + (u32)(-10)) < (u32)(eax));  // @233_482b80
  eax = (eax + (u32)(-10));  // @234_482b80
  FL[3] = eax;  // @235_482b80
  CFv = ((u32)(eax + edx) < (u32)(eax));  // @236_482b80
  eax = (eax + edx);  // @237_482b80
  FL[3] = eax;  // @238_482b80
  CFv = ((u32)(eax + ebx) < (u32)(eax));  // @239_482b80
  eax = (eax + ebx);  // @240_482b80
  FL[3] = eax;  // @241_482b80
  PV[18] = (u32)(eax);  // @242_482b80
  PV[19] = (u32)(esi);  // @243_482b80
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 388)))(PV[19], (u32)(0), PV[18]);  // @244_482b80
  ecx = edx = 0;  // @245_482b80
  reg.state = (s32)((u32)(4294967295));  // @246_482b80
  ecx = (u32)(EBP - 51592);  // @247_482b80
  eax = ext_4cbec0_thiscall1(ecx);  // @248_482b80
  ecx = edx = 0;  // @249_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51604), sizeof v); (u32)v; });  // @250_482b80
  ebx = (ebx + 1);  // @251_482b80
  FL[3] = ebx;  // @252_482b80
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; })) & 0xff);  // @253_482b80
  eax = (ecx & 0xff);  // @254_482b80
  FL[0] = ebx; FL[1] = eax;  // @255_482b80
  if (FL[0] != FL[1]) goto L482e30;  // @256_482b80
  FL[0] = ebx; FL[1] = (u32)(6);  // @257_482b80
  if (FL[0] >= FL[1]) goto L482f63;  // @258_482b80
  L482f10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @260_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @261_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @262_482b80
  ecx = edx = 0;  // @263_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @264_482b80
  esi = eax;  // @265_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @266_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @267_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @268_482b80
  eax = w4a_ce1(*(u32 *)(edx + 220), ecx, (u32)(6779512));  // @269_482b80 (hand fix)
  ecx = edx = 0;  // @270_482b80
  ecx = eax;  // @271_482b80
  eax = (u32)(715827883);  // @272_482b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @273_482b80
  eax = edx;  // @274_482b80
  eax = (eax >> (u32)(31));  // @275_482b80
  FL[3] = eax;  // @276_482b80
  CFv = ((u32)(eax + (u32)(-10)) < (u32)(eax));  // @277_482b80
  eax = (eax + (u32)(-10));  // @278_482b80
  FL[3] = eax;  // @279_482b80
  CFv = ((u32)(eax + edx) < (u32)(eax));  // @280_482b80
  eax = (eax + edx);  // @281_482b80
  FL[3] = eax;  // @282_482b80
  CFv = ((u32)(eax + ebx) < (u32)(eax));  // @283_482b80
  eax = (eax + ebx);  // @284_482b80
  FL[3] = eax;  // @285_482b80
  PV[20] = (u32)(eax);  // @286_482b80
  PV[21] = (u32)(esi);  // @287_482b80
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 388)))(PV[21], (u32)(0), PV[20]);  // @288_482b80
  ecx = edx = 0;  // @289_482b80
  ebx = (ebx + 1);  // @290_482b80
  FL[3] = ebx;  // @291_482b80
  FL[0] = ebx; FL[1] = (u32)(6);  // @292_482b80
  if (FL[0] < FL[1]) goto L482f10;  // @293_482b80
  L482f63:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51600), sizeof v); (u32)v; });  // @295_482b80
  ecx = edi;  // @296_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @297_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @298_482b80
  ecx = edx = 0;  // @299_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @300_482b80
  eax = ext_4db3b0_thiscall1(ecx);  // @301_482b80
  ecx = edx = 0;  // @302_482b80
  esi = eax;  // @303_482b80
  eax = (u32)(EBP - 51240);  // @304_482b80
  PV[22] = (u32)(eax);  // @305_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @306_482b80
  eax = ext_4daf90_thiscall2(ecx, PV[22]);  // @307_482b80
  edx = 0;  // @308_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @309_482b80
  eax = (u32)(EBP - 51240);  // @310_482b80
  PV[23] = (u32)(eax);  // @311_482b80
  ecx = esi;  // @312_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 136)))(ecx, PV[23]);  // @313_482b80
  ecx = edx = 0;  // @314_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @315_482b80
  ecx = (u32)(EBP - 51264);  // @316_482b80
  PV[24] = (u32)(ecx);  // @317_482b80
  ecx = (u32)(EBP - 51336);  // @318_482b80
  PV[25] = (u32)(ecx);  // @319_482b80
  ecx = esi;  // @320_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[25], PV[24]);  // @321_482b80
  ecx = edx = 0;  // @322_482b80
  edx = (u32)(EBP - 51264);  // @323_482b80
  ecx = (u32)(EBP - 51240);  // @324_482b80
  eax = ext_441940_fastcall2(ecx, edx);  // @325_482b80
  ecx = edx = 0;  // @326_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @327_482b80
  eax = (u32)(EBP - 51252);  // @328_482b80
  PV[26] = (u32)(eax);  // @329_482b80
  eax = ext_4db7c0_thiscall2(ecx, PV[26]);  // @330_482b80
  edx = 0;  // @331_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @332_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1602), sizeof v); (u32)v; });  // @333_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @334_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @335_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @336_482b80
  FL[2] = (edx & edx);  // @337_482b80
  if (FL[2] == 0) goto L483017;  // @338_482b80
  esi = (u32)(EBP - 51252);  // @339_482b80
  PV[27] = (u32)(esi);  // @340_482b80
  esi = (u32)(EBP - 51240);  // @341_482b80
  PV[28] = (u32)(esi);  // @342_482b80
  esi = (u32)(EBP - 51336);  // @343_482b80
  PV[29] = (u32)(esi);  // @344_482b80
  PV[30] = (u32)(edx);  // @345_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[30], PV[29], PV[28], PV[27], (u32)(11175936), (u32)(0));  // @346_482b80
  ecx = edx = 0;  // @347_482b80
  goto L4830c0;  // @348_482b80
  L483017:;
  edx = (u32)(EBP - 51252);  // @350_482b80
  PV[31] = (u32)(edx);  // @351_482b80
  edx = (u32)(EBP - 51240);  // @352_482b80
  PV[32] = (u32)(edx);  // @353_482b80
  edx = (u32)(EBP - 51336);  // @354_482b80
  PV[33] = (u32)(edx);  // @355_482b80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 568)))(ecx, PV[33], PV[32], PV[31], (u32)(11175936), (u32)(0));  // @356_482b80
  ecx = edx = 0;  // @357_482b80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 1602), &v, sizeof v); }  // @358_482b80
  goto L4830c0;  // @359_482b80
  L48303d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1602), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @361_482b80
  if (FL[0] == FL[1]) goto L4830c0;  // @362_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @363_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_482b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @365_482b80
  ecx = edx = 0;  // @366_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @367_482b80
  esi = eax;  // @368_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @369_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @370_482b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @371_482b80
  eax = w4a_ce1(*(u32 *)(edx + 220), ecx, (u32)(6790764));  // @372_482b80 (hand fix)
  ecx = edx = 0;  // @373_482b80
  ecx = eax;  // @374_482b80
  eax = (u32)(715827883);  // @375_482b80
  { long long p_ = (long long)(s32)eax * (long long)(s32)(ecx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @376_482b80
  eax = edx;  // @377_482b80
  eax = (eax >> (u32)(31));  // @378_482b80
  FL[3] = eax;  // @379_482b80
  CFv = ((u32)(eax + (u32)(-4)) < (u32)(eax));  // @380_482b80
  eax = (eax + (u32)(-4));  // @381_482b80
  FL[3] = eax;  // @382_482b80
  CFv = ((u32)(eax + edx) < (u32)(eax));  // @383_482b80
  eax = (eax + edx);  // @384_482b80
  FL[3] = eax;  // @385_482b80
  PV[34] = (u32)(eax);  // @386_482b80
  PV[35] = (u32)(esi);  // @387_482b80
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 388)))(PV[35], (u32)(0), PV[34]);  // @388_482b80
  ecx = edx = 0;  // @389_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @390_482b80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 51600), sizeof v); (u32)v; });  // @391_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @392_482b80
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1602), sizeof v); (u32)v; });  // @393_482b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @394_482b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_482b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[36]);  // @396_482b80
  ecx = edx = 0;  // @397_482b80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1602), &v, sizeof v); }  // @398_482b80
  L4830c0:;
  SEH_LEAVE();  // @400_482b80
  ext_633654(G(u32, 0x6f5630));  // @401_482b80
  return eax;  // @402_482b80
}
PCREG(482b80, lifted_482b80);

extern "C" u32 lifted_61dcd0(void) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[255], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0; u32 CFv = 0;
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
  CFv = ((u32)(eax) < (u32)(ecx));  // @212_61dcd0
  eax = (eax - ecx);  // @213_61dcd0
  FL[3] = eax;  // @214_61dcd0
  PV[28] = (u32)(eax);  // @215_61dcd0
  eax = (u32)(ecx + edi);  // @216_61dcd0
  PV[29] = (u32)(eax);  // @217_61dcd0
  eax = (u32)(esi + 424);  // @218_61dcd0
  PV[30] = (u32)(ebx);  // @219_61dcd0
  PV[31] = (u32)(eax);  // @220_61dcd0
  eax = ext_620840_cdecl4(PV[31], PV[30], PV[29], PV[28]);  // @221_61dcd0
  ecx = edx = 0;  // @222_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @223_61dcd0
  FL[2] = (eax & eax);  // @224_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @225_61dcd0
  PV[32] = (u32)(eax);  // @226_61dcd0
  eax = ext_620120_cdecl1(PV[32]);  // @227_61dcd0
  ecx = edx = 0;  // @228_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @229_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @230_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @231_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @232_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @233_61dcd0
  goto L61ee35;  // @234_61dcd0
  L61df09:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 308), sizeof v); (u32)v; });  // @236_61dcd0
  FL[2] = (eax & eax);  // @237_61dcd0
  if (FL[2] == 0) goto L61df39;  // @238_61dcd0
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 316), sizeof v); (u32)v; });  // @239_61dcd0
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @240_61dcd0
  PV[35] = (u32)(eax);  // @241_61dcd0
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @242_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @243_61dcd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[36], PV[35], PV[34], PV[33], (u32)(0));  // @244_61dcd0
  ecx = edx = 0;  // @245_61dcd0
  eax = (u32)(esi + 556);  // @246_61dcd0
  PV[37] = (u32)(eax);  // @247_61dcd0
  eax = ext_6204a0_cdecl1(PV[37]);  // @248_61dcd0
  ecx = edx = 0;  // @249_61dcd0
  L61df39:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @251_61dcd0
  if (FL[0] == FL[1]) goto L61dfbe;  // @252_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 612), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @253_61dcd0
  if (FL[0] == FL[1]) goto L61dfbe;  // @254_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 620), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @255_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }  // @256_61dcd0
  if (FL[0] == FL[1]) goto L61df95;  // @257_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @258_61dcd0
  if (FL[0] == FL[1]) goto L61df95;  // @259_61dcd0
  eax = (u32)(esi + 456);  // @260_61dcd0
  PV[38] = (u32)(eax);  // @261_61dcd0
  eax = ext_61fd60_cdecl3(PV[38], (u32)(7070396), (u32)(0));  // @262_61dcd0
  ecx = edx = 0;  // @263_61dcd0
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @264_61dcd0
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @265_61dcd0
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @266_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; });  // @267_61dcd0
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; });  // @268_61dcd0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))(PV[42], (u32)(0), PV[41], PV[40], PV[39]);  // @269_61dcd0
  ecx = edx = 0;  // @270_61dcd0
  FL[2] = (eax & eax);  // @271_61dcd0
  if (FL[2] == 0) goto L61ef1c;  // @272_61dcd0
  L61df95:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @274_61dcd0
  if (FL[0] != FL[1]) goto L61dfbe;  // @275_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 452), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @276_61dcd0
  if (FL[0] != FL[1]) goto L61dfbe;  // @277_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @278_61dcd0
  FL[2] = (eax & eax);  // @279_61dcd0
  if (FL[2] == 0) goto L61dfbe;  // @280_61dcd0
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @281_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[43]);  // @282_61dcd0
  ecx = edx = 0;  // @283_61dcd0
  FL[2] = (eax & eax);  // @284_61dcd0
  if (FL[2] == 0) goto L61ef28;  // @285_61dcd0
  L61dfbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @287_61dcd0
  FL[2] = (eax & eax);  // @288_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @289_61dcd0
  PV[44] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @290_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[44]);  // @291_61dcd0
  ecx = edx = 0;  // @292_61dcd0
  goto L61ee35;  // @293_61dcd0
  L61dfd6:;
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @295_61dcd0
  PV[46] = (u32)(edi);  // @296_61dcd0
  PV[47] = (u32)(ebx);  // @297_61dcd0
  PV[48] = (u32)(esi);  // @298_61dcd0
  eax = ext_61fb10_cdecl4(PV[48], PV[47], PV[46], PV[45]);  // @299_61dcd0
  ecx = edx = 0;  // @300_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 332), &v, sizeof v); }  // @301_61dcd0
  goto L61ee2a;  // @302_61dcd0
  L61dfec:;
  PV[49] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @304_61dcd0
  PV[50] = (u32)(edi);  // @305_61dcd0
  PV[51] = (u32)(ebx);  // @306_61dcd0
  PV[52] = (u32)(esi);  // @307_61dcd0
  eax = ext_61f5a0_cdecl4(PV[52], PV[51], PV[50], PV[49]);  // @308_61dcd0
  ecx = edx = 0;  // @309_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 336), &v, sizeof v); }  // @310_61dcd0
  FL[2] = (eax & eax);  // @311_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @312_61dcd0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 340), &v, sizeof v); }  // @313_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @314_61dcd0
  goto L61ee35;  // @315_61dcd0
  L61e020:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 340), &v, sizeof v); }  // @317_61dcd0
  { u32 v = (u32)((u32)(7071064)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @318_61dcd0
  goto L61ee35;  // @319_61dcd0
  L61e036:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 341), &v, sizeof v); }  // @321_61dcd0
  { u32 v = (u32)((u32)(7071072)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @322_61dcd0
  goto L61ee35;  // @323_61dcd0
  L61e04c:;
  { u32 v = (u32)((u32)(7071076)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @325_61dcd0
  goto L61ee35;  // @326_61dcd0
  L61e05b:;
  { u32 v = (u32)((u32)(7071084)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @328_61dcd0
  goto L61ee35;  // @329_61dcd0
  L61e06a:;
  { u32 v = (u32)((u32)(7071092)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @331_61dcd0
  goto L61ee35;  // @332_61dcd0
  L61e079:;
  { u32 v = (u32)((u32)(7071100)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @334_61dcd0
  goto L61ee35;  // @335_61dcd0
  L61e088:;
  { u32 v = (u32)((u32)(7071112)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @337_61dcd0
  goto L61ee35;  // @338_61dcd0
  L61e097:;
  { u32 v = (u32)((u32)(7071120)); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @340_61dcd0
  goto L61ee35;  // @341_61dcd0
  L61e0a6:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @343_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @344_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @345_61dcd0
  if (FL[0] == FL[1]) goto L61e0c3;  // @346_61dcd0
  eax = (u32)(7071132);  // @347_61dcd0
  goto L61e0d3;  // @348_61dcd0
  L61e0c3:;
  FL[0] = ecx; FL[1] = (u32)(29);  // @350_61dcd0
  eax = (u32)(7071136);  // @351_61dcd0
  ecx = (u32)(6802608);  // @352_61dcd0
  if (FL[0] != FL[1]) eax = ecx;  // @353_61dcd0
  L61e0d3:;
  ecx = (u32)(esi + 556);  // @355_61dcd0
  PV[53] = (u32)(eax);  // @356_61dcd0
  PV[54] = (u32)(ecx);  // @357_61dcd0
  eax = ext_620320_cdecl2(PV[54], PV[53]);  // @358_61dcd0
  ecx = edx = 0;  // @359_61dcd0
  FL[2] = (eax & eax);  // @360_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @361_61dcd0
  PV[55] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @362_61dcd0
  eax = (u32)(esi + 556);  // @363_61dcd0
  PV[56] = (u32)(edi);  // @364_61dcd0
  PV[57] = (u32)(ebx);  // @365_61dcd0
  PV[58] = (u32)(eax);  // @366_61dcd0
  eax = ext_620180_cdecl4(PV[58], PV[57], PV[56], PV[55]);  // @367_61dcd0
  ecx = edx = 0;  // @368_61dcd0
  FL[2] = (eax & eax);  // @369_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @370_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @371_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @372_61dcd0
  goto L61ee35;  // @373_61dcd0
  L61e118:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @375_61dcd0
  if (FL[0] == FL[1]) goto L61e150;  // @376_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 341), sizeof v); (u32)v; }));  // @377_61dcd0
  PV[59] = (u32)(esi);  // @378_61dcd0
  PV[60] = (u32)(eax);  // @379_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 340), sizeof v); (u32)v; }));  // @380_61dcd0
  PV[61] = (u32)(eax);  // @381_61dcd0
  PV[62] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @382_61dcd0
  PV[63] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @383_61dcd0
  eax = ext_61cd60_cdecl6(PV[63], PV[62], PV[61], PV[60], (u32)(0), PV[59]);  // @384_61dcd0
  ecx = edx = 0;  // @385_61dcd0
  FL[2] = (eax & eax);  // @386_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @387_61dcd0
  L61e150:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @389_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @390_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @391_61dcd0
  FL[2] = (eax & eax);  // @392_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @393_61dcd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @394_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(40);  // @395_61dcd0
  if (FL[0] == FL[1]) goto L61e185;  // @396_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(78);  // @397_61dcd0
  if (FL[0] != FL[1]) goto L61e205;  // @398_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }); FL[1] = (u32)(79);  // @399_61dcd0
  if (FL[0] != FL[1]) goto L61e205;  // @400_61dcd0
  L61e185:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @402_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @403_61dcd0
  if (FL[0] != FL[1]) goto L61e1aa;  // @404_61dcd0
  eax = (u32)(esi + 556);  // @405_61dcd0
  PV[64] = (u32)(eax);  // @406_61dcd0
  eax = ext_6206e0_cdecl1(PV[64]);  // @407_61dcd0
  ecx = edx = 0;  // @408_61dcd0
  FL[2] = (eax & eax);  // @409_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @410_61dcd0
  L61e1aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @412_61dcd0
  { u8 v = (u8)((u32)(41)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @413_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @414_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @415_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @416_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @417_61dcd0
  if (FL[0] != FL[1]) goto L61e1de;  // @418_61dcd0
  eax = (u32)(esi + 556);  // @419_61dcd0
  PV[65] = (u32)(eax);  // @420_61dcd0
  eax = ext_6206e0_cdecl1(PV[65]);  // @421_61dcd0
  ecx = edx = 0;  // @422_61dcd0
  FL[2] = (eax & eax);  // @423_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @424_61dcd0
  L61e1de:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @426_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @427_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @428_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @429_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @430_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @431_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @432_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @433_61dcd0
  L61e205:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @435_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @436_61dcd0
  eax = 0;  // @437_61dcd0
  FL[3] = eax;  // @438_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(32);  // @439_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @440_61dcd0
  PV[66] = (u32)(eax);  // @441_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @442_61dcd0
  PV[67] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @443_61dcd0
  PV[68] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @444_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @445_61dcd0
  PV[69] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @446_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @447_61dcd0
  PV[70] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @448_61dcd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[70], PV[69], PV[68], PV[67], (u32)(0), PV[66]);  // @449_61dcd0
  ecx = edx = 0;  // @450_61dcd0
  eax = (u32)(esi + 556);  // @451_61dcd0
  PV[71] = (u32)(eax);  // @452_61dcd0
  eax = ext_6204a0_cdecl1(PV[71]);  // @453_61dcd0
  ecx = edx = 0;  // @454_61dcd0
  goto L61ee35;  // @455_61dcd0
  L61e24b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @457_61dcd0
  eax = (u32)(esi + 424);  // @458_61dcd0
  PV[72] = (u32)(eax);  // @459_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @460_61dcd0
  CFv = ((u32)(eax) < (u32)(ecx));  // @461_61dcd0
  eax = (eax - ecx);  // @462_61dcd0
  FL[3] = eax;  // @463_61dcd0
  PV[73] = (u32)(eax);  // @464_61dcd0
  eax = (u32)(ecx + edi);  // @465_61dcd0
  PV[74] = (u32)(eax);  // @466_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 340), sizeof v); (u32)v; }));  // @467_61dcd0
  PV[75] = (u32)(eax);  // @468_61dcd0
  PV[76] = (u32)(ebx);  // @469_61dcd0
  PV[77] = (u32)(esi);  // @470_61dcd0
  eax = ext_6211c0_cdecl6(PV[77], PV[76], PV[75], PV[74], PV[73], PV[72]);  // @471_61dcd0
  ecx = edx = 0;  // @472_61dcd0
  FL[2] = (eax & eax);  // @473_61dcd0
  if (FL[2] != 0) goto L61efa4;  // @474_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @475_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @476_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @477_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @478_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @479_61dcd0
  if (FL[0] == FL[1]) goto L61e2bf;  // @480_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 340), sizeof v); (u32)v; }));  // @481_61dcd0
  PV[78] = (u32)(esi);  // @482_61dcd0
  PV[79] = (u32)(ecx);  // @483_61dcd0
  PV[80] = (u32)(eax);  // @484_61dcd0
  PV[81] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @485_61dcd0
  PV[82] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @486_61dcd0
  eax = ext_61cd60_cdecl6(PV[82], PV[81], PV[80], (u32)(0), PV[79], PV[78]);  // @487_61dcd0
  ecx = edx = 0;  // @488_61dcd0
  FL[2] = (eax & eax);  // @489_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @490_61dcd0
  L61e2bf:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @492_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @493_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @494_61dcd0
  FL[2] = (eax & eax);  // @495_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @496_61dcd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @497_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(40);  // @498_61dcd0
  if (FL[0] == FL[1]) goto L61e2f4;  // @499_61dcd0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(78);  // @500_61dcd0
  if (FL[0] != FL[1]) goto L61e374;  // @501_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }); FL[1] = (u32)(79);  // @502_61dcd0
  if (FL[0] != FL[1]) goto L61e374;  // @503_61dcd0
  L61e2f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @505_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @506_61dcd0
  if (FL[0] != FL[1]) goto L61e319;  // @507_61dcd0
  eax = (u32)(esi + 556);  // @508_61dcd0
  PV[83] = (u32)(eax);  // @509_61dcd0
  eax = ext_6206e0_cdecl1(PV[83]);  // @510_61dcd0
  ecx = edx = 0;  // @511_61dcd0
  FL[2] = (eax & eax);  // @512_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @513_61dcd0
  L61e319:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @515_61dcd0
  { u8 v = (u8)((u32)(41)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @516_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @517_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @518_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @519_61dcd0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; });  // @520_61dcd0
  if (FL[0] != FL[1]) goto L61e34d;  // @521_61dcd0
  eax = (u32)(esi + 556);  // @522_61dcd0
  PV[84] = (u32)(eax);  // @523_61dcd0
  eax = ext_6206e0_cdecl1(PV[84]);  // @524_61dcd0
  ecx = edx = 0;  // @525_61dcd0
  FL[2] = (eax & eax);  // @526_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @527_61dcd0
  L61e34d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @529_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @530_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 568), &v, sizeof v); }  // @531_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @532_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 572), sizeof v); (u32)v; });  // @533_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @534_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 320), &v, sizeof v); }  // @535_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @536_61dcd0
  L61e374:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @538_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @539_61dcd0
  eax = 0;  // @540_61dcd0
  FL[3] = eax;  // @541_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(34);  // @542_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @543_61dcd0
  PV[85] = (u32)(eax);  // @544_61dcd0
  PV[86] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @545_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 336), sizeof v); (u32)v; });  // @546_61dcd0
  PV[87] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 320), sizeof v); (u32)v; });  // @547_61dcd0
  PV[88] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @548_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @549_61dcd0
  PV[89] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @550_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; });  // @551_61dcd0
  PV[90] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @552_61dcd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[90], PV[89], PV[88], PV[87], PV[86], PV[85]);  // @553_61dcd0
  ecx = edx = 0;  // @554_61dcd0
  eax = (u32)(esi + 556);  // @555_61dcd0
  PV[91] = (u32)(eax);  // @556_61dcd0
  eax = ext_6204a0_cdecl1(PV[91]);  // @557_61dcd0
  ecx = edx = 0;  // @558_61dcd0
  goto L61ee35;  // @559_61dcd0
  L61e3bb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @561_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @562_61dcd0
  CFv = ((u32)(eax) < (u32)(ecx));  // @563_61dcd0
  eax = (eax - ecx);  // @564_61dcd0
  FL[3] = eax;  // @565_61dcd0
  PV[92] = (u32)(eax);  // @566_61dcd0
  eax = (u32)(ecx + edi);  // @567_61dcd0
  PV[93] = (u32)(eax);  // @568_61dcd0
  PV[94] = (u32)(ebx);  // @569_61dcd0
  PV[95] = (u32)(esi);  // @570_61dcd0
  eax = ext_6218c0_cdecl4(PV[95], PV[94], PV[93], PV[92]);  // @571_61dcd0
  ecx = edx = 0;  // @572_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @573_61dcd0
  edx = eax;  // @574_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @575_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @576_61dcd0
  FL[2] = (ecx & ecx);  // @577_61dcd0
  if (FL[2] == 0) goto L61e44b;  // @578_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @579_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @580_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @581_61dcd0
  CFv = ((u32)(ecx) < (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; })));  // @582_61dcd0
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; }));  // @583_61dcd0
  FL[3] = ecx;  // @584_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @585_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @586_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @587_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @588_61dcd0
  if (FL[0] == FL[1]) goto L61e451;  // @589_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @590_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @591_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @592_61dcd0
  PV[96] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @593_61dcd0
  PV[97] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @594_61dcd0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 29), sizeof v); (u32)v; }));  // @595_61dcd0
  PV[98] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @596_61dcd0
  PV[99] = (u32)(eax);  // @597_61dcd0
  PV[100] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @598_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @599_61dcd0
  PV[101] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @600_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(PV[101], PV[100], PV[99], PV[98], PV[97], PV[96], (u32)(0), (u32)(0), (u32)(0));  // @601_61dcd0
  ecx = edx = 0;  // @602_61dcd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @603_61dcd0
  goto L61e451;  // @604_61dcd0
  L61e44b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @606_61dcd0
  L61e451:;
  FL[2] = (edx & edx);  // @608_61dcd0
  if (FL[2] == 0) goto L61ee35;  // @609_61dcd0
  eax = edx;  // @610_61dcd0
  return eax;  // @611_61dcd0
  L61e462:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @613_61dcd0
  if (FL[0] == FL[1]) goto L61e49b;  // @614_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @615_61dcd0
  eax = (eax - 1);  // @616_61dcd0
  FL[3] = eax;  // @617_61dcd0
  PV[102] = (u32)(eax);  // @618_61dcd0
  eax = (u32)(edi + 1);  // @619_61dcd0
  PV[103] = (u32)(eax);  // @620_61dcd0
  eax = (u32)(esi + 556);  // @621_61dcd0
  PV[104] = (u32)(ebx);  // @622_61dcd0
  PV[105] = (u32)(eax);  // @623_61dcd0
  eax = ext_620840_cdecl4(PV[105], PV[104], PV[103], PV[102]);  // @624_61dcd0
  ecx = edx = 0;  // @625_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @626_61dcd0
  FL[2] = (eax & eax);  // @627_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @628_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @629_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @630_61dcd0
  L61e49b:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 452), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @632_61dcd0
  if (FL[0] != FL[1]) goto L61e4c4;  // @633_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 620), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @634_61dcd0
  if (FL[0] != FL[1]) goto L61e4c4;  // @635_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @636_61dcd0
  FL[2] = (eax & eax);  // @637_61dcd0
  if (FL[2] == 0) goto L61e4c4;  // @638_61dcd0
  PV[106] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @639_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[106]);  // @640_61dcd0
  ecx = edx = 0;  // @641_61dcd0
  FL[2] = (eax & eax);  // @642_61dcd0
  if (FL[2] == 0) goto L61ef28;  // @643_61dcd0
  L61e4c4:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @645_61dcd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 612), &v, sizeof v); }  // @646_61dcd0
  if (FL[0] != FL[1]) goto L61e514;  // @647_61dcd0
  eax = (u32)(esi + 456);  // @648_61dcd0
  PV[107] = (u32)(eax);  // @649_61dcd0
  eax = ext_61fd60_cdecl3(PV[107], (u32)(7070396), (u32)(32));  // @650_61dcd0
  ecx = edx = 0;  // @651_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @652_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @653_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @654_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @655_61dcd0
  L61e507:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @657_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @658_61dcd0
  L61e514:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @660_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @661_61dcd0
  CFv = ((u32)(eax) < (u32)(ecx));  // @662_61dcd0
  eax = (eax - ecx);  // @663_61dcd0
  FL[3] = eax;  // @664_61dcd0
  PV[108] = (u32)(eax);  // @665_61dcd0
  eax = (u32)(ecx + edi);  // @666_61dcd0
  PV[109] = (u32)(eax);  // @667_61dcd0
  eax = (u32)(esi + 424);  // @668_61dcd0
  PV[110] = (u32)(ebx);  // @669_61dcd0
  PV[111] = (u32)(eax);  // @670_61dcd0
  eax = ext_620840_cdecl4(PV[111], PV[110], PV[109], PV[108]);  // @671_61dcd0
  ecx = edx = 0;  // @672_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @673_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @674_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @675_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @676_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @677_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @678_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @679_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @680_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @681_61dcd0
  goto L61ee35;  // @682_61dcd0
  L61e564:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @684_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @685_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @686_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @687_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @688_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @689_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @690_61dcd0
  PV[112] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @691_61dcd0
  PV[113] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @692_61dcd0
  PV[114] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @693_61dcd0
  PV[115] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @694_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @695_61dcd0
  PV[116] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @696_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(PV[116], PV[115], (u32)(0), (u32)(0), (u32)(0), PV[114], PV[113], PV[112], (u32)(0));  // @697_61dcd0
  ecx = edx = 0;  // @698_61dcd0
  goto L61ee35;  // @699_61dcd0
  L61e5af:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @701_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @702_61dcd0
  PV[117] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @703_61dcd0
  eax = (u32)(esi + 424);  // @704_61dcd0
  PV[118] = (u32)(edi);  // @705_61dcd0
  PV[119] = (u32)(ebx);  // @706_61dcd0
  PV[120] = (u32)(eax);  // @707_61dcd0
  eax = ext_620840_cdecl4(PV[120], PV[119], PV[118], PV[117]);  // @708_61dcd0
  ecx = edx = 0;  // @709_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @710_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @711_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @712_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @713_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @714_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @715_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @716_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @717_61dcd0
  if (FL[0] == FL[1]) goto L61e624;  // @718_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @719_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @720_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @721_61dcd0
  PV[121] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @722_61dcd0
  PV[122] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @723_61dcd0
  PV[123] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @724_61dcd0
  PV[124] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @725_61dcd0
  PV[125] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @726_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @727_61dcd0
  PV[126] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @728_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(eax))(PV[126], PV[125], PV[124], PV[123], PV[122], PV[121]);  // @729_61dcd0
  ecx = edx = 0;  // @730_61dcd0
  goto L61ee35;  // @731_61dcd0
  L61e624:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @733_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @734_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @735_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @736_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @737_61dcd0
  PV[127] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @738_61dcd0
  PV[128] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @739_61dcd0
  PV[129] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @740_61dcd0
  PV[130] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @741_61dcd0
  PV[131] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @742_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @743_61dcd0
  PV[132] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @744_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(eax))(PV[132], PV[131], (u32)(0), (u32)(0), (u32)(0), PV[130], PV[129], PV[128], PV[127]);  // @745_61dcd0
  ecx = edx = 0;  // @746_61dcd0
  goto L61ee35;  // @747_61dcd0
  L61e663:;
  PV[133] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @749_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; });  // @750_61dcd0
  PV[134] = (u32)(edi);  // @751_61dcd0
  PV[135] = (u32)(ebx);  // @752_61dcd0
  eax = ((u32( *)(u32, u32, u32))(eax))(PV[135], PV[134], PV[133]);  // @753_61dcd0
  ecx = edx = 0;  // @754_61dcd0
  FL[2] = (eax & eax);  // @755_61dcd0
  if (FL[2] == 0) goto L61e683;  // @756_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @757_61dcd0
  goto L61ee35;  // @758_61dcd0
  L61e683:;
  PV[136] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @760_61dcd0
  eax = (u32)(esi + 424);  // @761_61dcd0
  PV[137] = (u32)(edi);  // @762_61dcd0
  PV[138] = (u32)(ebx);  // @763_61dcd0
  PV[139] = (u32)(eax);  // @764_61dcd0
  eax = ext_620840_cdecl4(PV[139], PV[138], PV[137], PV[136]);  // @765_61dcd0
  ecx = edx = 0;  // @766_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @767_61dcd0
  FL[2] = (eax & eax);  // @768_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @769_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @770_61dcd0
  if (FL[0] == FL[1]) goto L61e6d4;  // @771_61dcd0
  PV[140] = (u32)(eax);  // @772_61dcd0
  eax = (u32)(esi + 344);  // @773_61dcd0
  PV[141] = (u32)(eax);  // @774_61dcd0
  eax = ext_61fd60_cdecl3(PV[141], PV[140], (u32)(32));  // @775_61dcd0
  ecx = edx = 0;  // @776_61dcd0
  ecx = eax;  // @777_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @778_61dcd0
  FL[2] = (ecx & ecx);  // @779_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @780_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @781_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = eax;  // @782_61dcd0
  if (FL[0] == FL[1]) goto L61e6ef;  // @783_61dcd0
  L61e6d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @785_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @786_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @787_61dcd0
  goto L61ee35;  // @788_61dcd0
  L61e6ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @790_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @791_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @792_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @793_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @794_61dcd0
  goto L61ee35;  // @795_61dcd0
  L61e711:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @797_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @798_61dcd0
  PV[142] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @799_61dcd0
  eax = (u32)(esi + 424);  // @800_61dcd0
  PV[143] = (u32)(edi);  // @801_61dcd0
  PV[144] = (u32)(ebx);  // @802_61dcd0
  PV[145] = (u32)(eax);  // @803_61dcd0
  eax = ext_620840_cdecl4(PV[145], PV[144], PV[143], PV[142]);  // @804_61dcd0
  ecx = edx = 0;  // @805_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @806_61dcd0
  FL[2] = (eax & eax);  // @807_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @808_61dcd0
  PV[146] = (u32)(eax);  // @809_61dcd0
  eax = (u32)(esi + 456);  // @810_61dcd0
  PV[147] = (u32)(eax);  // @811_61dcd0
  eax = ext_61fd60_cdecl3(PV[147], PV[146], (u32)(32));  // @812_61dcd0
  ecx = edx = 0;  // @813_61dcd0
  ecx = eax;  // @814_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 304), &v, sizeof v); }  // @815_61dcd0
  FL[2] = (ecx & ecx);  // @816_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @817_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @818_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = eax;  // @819_61dcd0
  if (FL[0] != FL[1]) goto L61e6d4;  // @820_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 436), sizeof v); (u32)v; });  // @821_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 440), &v, sizeof v); }  // @822_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @823_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 304), sizeof v); (u32)v; });  // @824_61dcd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 29), &v, sizeof v); }  // @825_61dcd0
  goto L61ee35;  // @826_61dcd0
  L61e78c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @828_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 328), &v, sizeof v); }  // @829_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 324), &v, sizeof v); }  // @830_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @831_61dcd0
  PV[148] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @832_61dcd0
  eax = (u32)(esi + 556);  // @833_61dcd0
  PV[149] = (u32)(edi);  // @834_61dcd0
  PV[150] = (u32)(ebx);  // @835_61dcd0
  PV[151] = (u32)(eax);  // @836_61dcd0
  eax = ext_620840_cdecl4(PV[151], PV[150], PV[149], PV[148]);  // @837_61dcd0
  ecx = edx = 0;  // @838_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 324), &v, sizeof v); }  // @839_61dcd0
  FL[2] = (eax & eax);  // @840_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @841_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @842_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @843_61dcd0
  goto L61ee35;  // @844_61dcd0
  L61e7dd:;
  PV[152] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @846_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 56), sizeof v); (u32)v; });  // @847_61dcd0
  PV[153] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @848_61dcd0
  PV[154] = (u32)(edi);  // @849_61dcd0
  PV[155] = (u32)(ebx);  // @850_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32))(eax))(PV[155], PV[154], PV[153], PV[152]);  // @851_61dcd0
  ecx = edx = 0;  // @852_61dcd0
  FL[2] = (eax & eax);  // @853_61dcd0
  if (FL[2] == 0) goto L61eee5;  // @854_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @855_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @856_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @857_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @858_61dcd0
  CFv = ((u32)(eax) < (u32)(ecx));  // @859_61dcd0
  eax = (eax - ecx);  // @860_61dcd0
  FL[3] = eax;  // @861_61dcd0
  PV[156] = (u32)(eax);  // @862_61dcd0
  eax = (u32)(ecx + edi);  // @863_61dcd0
  PV[157] = (u32)(eax);  // @864_61dcd0
  eax = (u32)(esi + 556);  // @865_61dcd0
  PV[158] = (u32)(ebx);  // @866_61dcd0
  PV[159] = (u32)(eax);  // @867_61dcd0
  eax = ext_620840_cdecl4(PV[159], PV[158], PV[157], PV[156]);  // @868_61dcd0
  ecx = edx = 0;  // @869_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @870_61dcd0
  FL[2] = (eax & eax);  // @871_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @872_61dcd0
  PV[160] = (u32)(eax);  // @873_61dcd0
  eax = ext_620120_cdecl1(PV[160]);  // @874_61dcd0
  ecx = edx = 0;  // @875_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @876_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 328), &v, sizeof v); }  // @877_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 568), sizeof v); (u32)v; });  // @878_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 572), &v, sizeof v); }  // @879_61dcd0
  goto L61ee35;  // @880_61dcd0
  L61e84d:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @882_61dcd0
  if (FL[0] == FL[1]) goto L61e8a4;  // @883_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @884_61dcd0
  if (FL[0] == FL[1]) goto L61e8a4;  // @885_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @886_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @887_61dcd0
  CFv = ((u32)(eax) < (u32)(ecx));  // @888_61dcd0
  eax = (eax - ecx);  // @889_61dcd0
  FL[3] = eax;  // @890_61dcd0
  PV[161] = (u32)(eax);  // @891_61dcd0
  eax = (u32)(ecx + edi);  // @892_61dcd0
  PV[162] = (u32)(eax);  // @893_61dcd0
  eax = (u32)(esi + 556);  // @894_61dcd0
  PV[163] = (u32)(ebx);  // @895_61dcd0
  PV[164] = (u32)(eax);  // @896_61dcd0
  eax = ext_620840_cdecl4(PV[164], PV[163], PV[162], PV[161]);  // @897_61dcd0
  ecx = edx = 0;  // @898_61dcd0
  FL[2] = (eax & eax);  // @899_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @900_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @901_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @902_61dcd0
  PV[165] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 328), sizeof v); (u32)v; });  // @903_61dcd0
  PV[166] = (u32)(eax);  // @904_61dcd0
  PV[167] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @905_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @906_61dcd0
  PV[168] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; });  // @907_61dcd0
  PV[169] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @908_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[169], PV[168], PV[167], PV[166], PV[165]);  // @909_61dcd0
  ecx = edx = 0;  // @910_61dcd0
  L61e8a4:;
  eax = (u32)(esi + 556);  // @912_61dcd0
  PV[170] = (u32)(eax);  // @913_61dcd0
  eax = ext_6204a0_cdecl1(PV[170]);  // @914_61dcd0
  ecx = edx = 0;  // @915_61dcd0
  goto L61ee35;  // @916_61dcd0
  L61e8b8:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 328), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @918_61dcd0
  if (FL[0] == FL[1]) goto L61e8eb;  // @919_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @920_61dcd0
  if (FL[0] == FL[1]) goto L61e8eb;  // @921_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @922_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @923_61dcd0
  PV[171] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 328), sizeof v); (u32)v; });  // @924_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @925_61dcd0
  PV[172] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 512), sizeof v); (u32)v; });  // @926_61dcd0
  PV[173] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 324), sizeof v); (u32)v; });  // @927_61dcd0
  PV[174] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @928_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[174], PV[173], PV[172], (u32)(0), PV[171]);  // @929_61dcd0
  ecx = edx = 0;  // @930_61dcd0
  L61e8eb:;
  eax = (u32)(esi + 556);  // @932_61dcd0
  PV[175] = (u32)(eax);  // @933_61dcd0
  eax = ext_6204a0_cdecl1(PV[175]);  // @934_61dcd0
  ecx = edx = 0;  // @935_61dcd0
  goto L61ee35;  // @936_61dcd0
  L61e8ff:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @938_61dcd0
  if (FL[0] == FL[1]) goto L61e913;  // @939_61dcd0
  PV[176] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @940_61dcd0
  PV[177] = (u32)(edi);  // @941_61dcd0
  PV[178] = (u32)(ebx);  // @942_61dcd0
  PV[179] = (u32)(esi);  // @943_61dcd0
  eax = ext_620cb0_cdecl4(PV[179], PV[178], PV[177], PV[176]);  // @944_61dcd0
  ecx = edx = 0;  // @945_61dcd0
  L61e913:;
  PV[180] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @947_61dcd0
  eax = (u32)(EBP + 28);  // @948_61dcd0
  PV[181] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @949_61dcd0
  PV[182] = (u32)(eax);  // @950_61dcd0
  PV[183] = (u32)(ebx);  // @951_61dcd0
  PV[184] = (u32)(esi);  // @952_61dcd0
  eax = ext_61dba0_cdecl5(PV[184], PV[183], PV[182], PV[181], PV[180]);  // @953_61dcd0
  ecx = edx = 0;  // @954_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @955_61dcd0
  if (FL[0] != FL[1]) goto L61ee35;  // @956_61dcd0
  { u32 v = (u32)((u32)(6421776)); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @957_61dcd0
  return eax;  // @958_61dcd0
  L61e942:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 608), sizeof v); (u32)v; });  // @960_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; }); FL[1] = eax;  // @961_61dcd0
  if (FL[0] < FL[1]) goto L61e9bd;  // @962_61dcd0
  FL[2] = (eax & eax);  // @963_61dcd0
  if (FL[2] == 0) goto L61e996;  // @964_61dcd0
  CFv = ((u32)(eax + eax) < (u32)(eax));  // @965_61dcd0
  eax = (eax + eax);  // @966_61dcd0
  FL[3] = eax;  // @967_61dcd0
  PV[185] = (u32)(eax);  // @968_61dcd0
  PV[186] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @969_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 608), &v, sizeof v); }  // @970_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @971_61dcd0
  eax = ((u32( *)(u32, u32))(eax))(PV[186], PV[185]);  // @972_61dcd0
  ecx = edx = 0;  // @973_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @974_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 604), &v, sizeof v); }  // @975_61dcd0
  FL[2] = (ecx & ecx);  // @976_61dcd0
  if (FL[2] == 0) goto L61e9b0;  // @977_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 608), sizeof v); (u32)v; });  // @978_61dcd0
  eax = (eax << (u32)(2));  // @979_61dcd0
  FL[3] = eax;  // @980_61dcd0
  PV[187] = (u32)(eax);  // @981_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @982_61dcd0
  PV[188] = (u32)(ecx);  // @983_61dcd0
  eax = ((u32( *)(u32, u32))(eax))(PV[188], PV[187]);  // @984_61dcd0
  ecx = edx = 0;  // @985_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 508), &v, sizeof v); }  // @986_61dcd0
  goto L61e9b0;  // @987_61dcd0
  L61e996:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @989_61dcd0
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(esi + 608), &v, sizeof v); }  // @990_61dcd0
  eax = ((u32( *)(u32))(eax))((u32)(32));  // @991_61dcd0
  ecx = edx = 0;  // @992_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 604), &v, sizeof v); }  // @993_61dcd0
  L61e9b0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @995_61dcd0
  if (FL[0] == FL[1]) goto L61ef10;  // @996_61dcd0
  L61e9bd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @998_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @999_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @1000_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1001_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1002_61dcd0
  PV[189] = (u32)(esi);  // @1003_61dcd0
  eax = ext_61ffb0_cdecl1(PV[189]);  // @1004_61dcd0
  ecx = edx = 0;  // @1005_61dcd0
  edx = eax;  // @1006_61dcd0
  FL[2] = (edx & edx);  // @1007_61dcd0
  if ((s32)FL[2] < 0) goto L61ef10;  // @1008_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1009_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1010_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1011_61dcd0
  ecx = (u32)(edx*8);  // @1012_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 504), &v, sizeof v); }  // @1013_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1014_61dcd0
  CFv = ((u32)(ecx) < (u32)(edx));  // @1015_61dcd0
  ecx = (ecx - edx);  // @1016_61dcd0
  FL[3] = ecx;  // @1017_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1018_61dcd0
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1019_61dcd0
  goto L61ee35;  // @1020_61dcd0
  L61ea1d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @1022_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @1023_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }); FL[1] = (u32)(124);  // @1024_61dcd0
  if (FL[0] == FL[1]) goto L61eee5;  // @1025_61dcd0
  { u8 v = (u8)((u32)(44)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @1026_61dcd0
  goto L61ee35;  // @1027_61dcd0
  L61ea3c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @1029_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @1030_61dcd0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; })) & 0xff);  // @1031_61dcd0
  FL[0] = (eax & 0xff); FL[1] = (u32)(44);  // @1032_61dcd0
  if (FL[0] == FL[1]) goto L61eee5;  // @1033_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1034_61dcd0
  if (FL[0] == FL[1]) goto L61ea8c;  // @1035_61dcd0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1036_61dcd0
  if (FL[2] != 0) goto L61ea8c;  // @1037_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1038_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1039_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 - 4), sizeof v); (u32)v; });  // @1040_61dcd0
  ecx = (u32)(eax*8);  // @1041_61dcd0
  CFv = ((u32)(ecx) < (u32)(eax));  // @1042_61dcd0
  ecx = (ecx - eax);  // @1043_61dcd0
  FL[3] = ecx;  // @1044_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1045_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @1046_61dcd0
  if (FL[0] == FL[1]) goto L61ea8c;  // @1047_61dcd0
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1048_61dcd0
  L61ea8c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 604), sizeof v); (u32)v; });  // @1050_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 260), sizeof v); (u32)v; });  // @1051_61dcd0
  { u8 v = (u8)((u32)(124)); __builtin_memcpy((void *)(u32)(ecx + eax), &v, sizeof v); }  // @1052_61dcd0
  goto L61ee35;  // @1053_61dcd0
  L61eaa1:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 620), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1055_61dcd0
  if (FL[0] == FL[1]) goto L61eb87;  // @1056_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1057_61dcd0
  if (FL[0] != FL[1]) goto L61eac0;  // @1058_61dcd0
  FL[0] = ecx; FL[1] = (u32)(52);  // @1059_61dcd0
  if (FL[0] != FL[1]) goto L61eb87;  // @1060_61dcd0
  L61eac0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1062_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1063_61dcd0
  CFv = ((u32)(eax) < (u32)(ecx));  // @1064_61dcd0
  eax = (eax - ecx);  // @1065_61dcd0
  FL[3] = eax;  // @1066_61dcd0
  PV[190] = (u32)(eax);  // @1067_61dcd0
  eax = (u32)(ecx + edi);  // @1068_61dcd0
  PV[191] = (u32)(eax);  // @1069_61dcd0
  eax = (u32)(esi + 424);  // @1070_61dcd0
  PV[192] = (u32)(ebx);  // @1071_61dcd0
  PV[193] = (u32)(eax);  // @1072_61dcd0
  eax = ext_620840_cdecl4(PV[193], PV[192], PV[191], PV[190]);  // @1073_61dcd0
  ecx = edx = 0;  // @1074_61dcd0
  FL[2] = (eax & eax);  // @1075_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1076_61dcd0
  PV[194] = (u32)(eax);  // @1077_61dcd0
  eax = (u32)(esi + 456);  // @1078_61dcd0
  PV[195] = (u32)(eax);  // @1079_61dcd0
  eax = ext_61fd60_cdecl3(PV[195], PV[194], (u32)(0));  // @1080_61dcd0
  ecx = edx = 0;  // @1081_61dcd0
  ecx = eax;  // @1082_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 440), sizeof v); (u32)v; });  // @1083_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1084_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 436), &v, sizeof v); }  // @1085_61dcd0
  FL[2] = (ecx & ecx);  // @1086_61dcd0
  if (FL[2] == 0) goto L61ef4c;  // @1087_61dcd0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1088_61dcd0
  if (FL[0] != FL[1]) goto L61ef40;  // @1089_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1090_61dcd0
  if (FL[0] == FL[1]) goto L61eb37;  // @1091_61dcd0
  PV[196] = (u32)(ecx);  // @1092_61dcd0
  PV[197] = (u32)(esi);  // @1093_61dcd0
  eax = ext_620890_cdecl2(PV[197], PV[196]);  // @1094_61dcd0
  ecx = edx = 0;  // @1095_61dcd0
  FL[2] = (eax & eax);  // @1096_61dcd0
  if (FL[2] != 0) goto L61efa4;  // @1097_61dcd0
  goto L61ee35;  // @1098_61dcd0
  L61eb37:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(52);  // @1100_61dcd0
  if (FL[0] == FL[1]) goto L61ef34;  // @1101_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1102_61dcd0
  if (FL[0] == FL[1]) goto L61eb87;  // @1103_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }  // @1104_61dcd0
  PV[198] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @1105_61dcd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @1106_61dcd0
  PV[199] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @1107_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; });  // @1108_61dcd0
  PV[200] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @1109_61dcd0
  PV[201] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; });  // @1110_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[201], (u32)(0), PV[200], PV[199], PV[198]);  // @1111_61dcd0
  ecx = edx = 0;  // @1112_61dcd0
  FL[2] = (eax & eax);  // @1113_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1114_61dcd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @1115_61dcd0
  if (FL[2] == 0) goto L61ef1c;  // @1116_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 448), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1117_61dcd0
  if (FL[0] != FL[1]) goto L61ee35;  // @1118_61dcd0
  L61eb87:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 452), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1120_61dcd0
  if (FL[0] != FL[1]) goto L61eba7;  // @1121_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @1122_61dcd0
  FL[2] = (eax & eax);  // @1123_61dcd0
  if (FL[2] == 0) goto L61eba7;  // @1124_61dcd0
  PV[202] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1125_61dcd0
  eax = ((u32( *)(u32))(eax))(PV[202]);  // @1126_61dcd0
  ecx = edx = 0;  // @1127_61dcd0
  FL[2] = (eax & eax);  // @1128_61dcd0
  if (FL[2] == 0) goto L61ef28;  // @1129_61dcd0
  L61eba7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1131_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }  // @1132_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1133_61dcd0
  PV[203] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1134_61dcd0
  PV[204] = (u32)(edi);  // @1135_61dcd0
  PV[205] = (u32)(ebx);  // @1136_61dcd0
  PV[206] = (u32)(esi);  // @1137_61dcd0
  eax = ext_620cb0_cdecl4(PV[206], PV[205], PV[204], PV[203]);  // @1138_61dcd0
  ecx = edx = 0;  // @1139_61dcd0
  goto L61ee35;  // @1140_61dcd0
  L61ebce:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1142_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1143_61dcd0
  PV[207] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1144_61dcd0
  PV[208] = (u32)(edi);  // @1145_61dcd0
  PV[209] = (u32)(ebx);  // @1146_61dcd0
  PV[210] = (u32)(esi);  // @1147_61dcd0
  eax = ext_61fb10_cdecl4(PV[210], PV[209], PV[208], PV[207]);  // @1148_61dcd0
  ecx = edx = 0;  // @1149_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 332), &v, sizeof v); }  // @1150_61dcd0
  FL[2] = (eax & eax);  // @1151_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1152_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 504), &v, sizeof v); }  // @1153_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 500), &v, sizeof v); }  // @1154_61dcd0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 484), &v, sizeof v); }  // @1155_61dcd0
  goto L61ee35;  // @1156_61dcd0
  L61ec17:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1158_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1159_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1160_61dcd0
  if (FL[0] == FL[1]) goto L61ec7f;  // @1161_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @1162_61dcd0
  eax = ((u32( *)(u32))(eax))((u32)(20));  // @1163_61dcd0
  ecx = edx = 0;  // @1164_61dcd0
  ecx = eax;  // @1165_61dcd0
  FL[2] = (ecx & ecx);  // @1166_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1167_61dcd0
  eax = 0;  // @1168_61dcd0
  FL[3] = eax;  // @1169_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @1170_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(36);  // @1171_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @1172_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @1173_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @1174_61dcd0
  eax = (eax + 1);  // @1175_61dcd0
  FL[3] = eax;  // @1176_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @1177_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1178_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1179_61dcd0
  PV[211] = (u32)(ecx);  // @1180_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @1181_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @1182_61dcd0
  PV[212] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1183_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @1184_61dcd0
  PV[213] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1185_61dcd0
  eax = ((u32( *)(u32, u32, u32))(eax))(PV[213], PV[212], PV[211]);  // @1186_61dcd0
  ecx = edx = 0;  // @1187_61dcd0
  L61ec7f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 484), &v, sizeof v); }  // @1189_61dcd0
  goto L61ee35;  // @1190_61dcd0
  L61ec8e:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1192_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1193_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1194_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1195_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 - 4), sizeof v); (u32)v; });  // @1196_61dcd0
  ecx = (u32)(eax*8);  // @1197_61dcd0
  CFv = ((u32)(ecx) < (u32)(eax));  // @1198_61dcd0
  ecx = (ecx - eax);  // @1199_61dcd0
  FL[3] = ecx;  // @1200_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1201_61dcd0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @1202_61dcd0
  goto L61ee35;  // @1203_61dcd0
  L61ecc6:;
  eax = 0;  // @1205_61dcd0
  FL[3] = eax;  // @1206_61dcd0
  goto L61ecdd;  // @1207_61dcd0
  L61ecca:;
  eax = (u32)(1);  // @1209_61dcd0
  goto L61ecdd;  // @1210_61dcd0
  L61ecd1:;
  eax = (u32)(2);  // @1212_61dcd0
  goto L61ecdd;  // @1213_61dcd0
  L61ecd8:;
  eax = (u32)(3);  // @1215_61dcd0
  L61ecdd:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1217_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1218_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1219_61dcd0
  FL[2] = (eax & eax);  // @1220_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1221_61dcd0
  if (FL[2] == 0) goto L61ecf5;  // @1222_61dcd0
  eax = (eax - 1);  // @1223_61dcd0
  FL[3] = eax;  // @1224_61dcd0
  L61ecf5:;
  PV[214] = (u32)(esi);  // @1226_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @1227_61dcd0
  eax = ext_61ffb0_cdecl1(PV[214]);  // @1228_61dcd0
  ecx = edx = 0;  // @1229_61dcd0
  FL[2] = (eax & eax);  // @1230_61dcd0
  if ((s32)FL[2] < 0) goto L61ef10;  // @1231_61dcd0
  PV[215] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1232_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @1233_61dcd0
  edx = (u32)(eax*8);  // @1234_61dcd0
  CFv = ((u32)(edx) < (u32)(eax));  // @1235_61dcd0
  edx = (edx - eax);  // @1236_61dcd0
  FL[3] = edx;  // @1237_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1238_61dcd0
  edx = (edx << (u32)(2));  // @1239_61dcd0
  FL[3] = edx;  // @1240_61dcd0
  PV[216] = (u32)(edi);  // @1241_61dcd0
  PV[217] = (u32)(ebx);  // @1242_61dcd0
  PV[218] = (u32)(esi);  // @1243_61dcd0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(edx + eax), &v, sizeof v); }  // @1244_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1245_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1246_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + eax + 4), &v, sizeof v); }  // @1247_61dcd0
  eax = ext_61fb10_cdecl4(PV[218], PV[217], PV[216], PV[215]);  // @1248_61dcd0
  ecx = edx = 0;  // @1249_61dcd0
  FL[2] = (eax & eax);  // @1250_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1251_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1252_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1253_61dcd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @1254_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx + 8), &v, sizeof v); }  // @1255_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @1256_61dcd0
  CFv = ((u32)(eax) < (u32)(edi));  // @1257_61dcd0
  eax = (eax - edi);  // @1258_61dcd0
  FL[3] = eax;  // @1259_61dcd0
  eax = (eax + 1);  // @1260_61dcd0
  FL[3] = eax;  // @1261_61dcd0
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 492), sizeof v); (u32)v; }) + eax) < (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 492), sizeof v); (u32)v; })));  // @1262_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 492), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 492), &v, sizeof v); }  // @1263_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 492), sizeof v); (u32)v; });  // @1264_61dcd0
  goto L61ee35;  // @1265_61dcd0
  L61ed68:;
  edx = 0;  // @1267_61dcd0
  FL[3] = edx;  // @1268_61dcd0
  goto L61ed7f;  // @1269_61dcd0
  L61ed6c:;
  edx = (u32)(1);  // @1271_61dcd0
  goto L61ed7f;  // @1272_61dcd0
  L61ed73:;
  edx = (u32)(2);  // @1274_61dcd0
  goto L61ed7f;  // @1275_61dcd0
  L61ed7a:;
  edx = (u32)(3);  // @1277_61dcd0
  L61ed7f:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 484), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1279_61dcd0
  if (FL[0] == FL[1]) goto L61ee35;  // @1280_61dcd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 504), &v, sizeof v); }  // @1281_61dcd0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1282_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; });  // @1283_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 508), sizeof v); (u32)v; });  // @1284_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @1285_61dcd0
  ecx = (u32)(eax*8);  // @1286_61dcd0
  CFv = ((u32)(ecx) < (u32)(eax));  // @1287_61dcd0
  ecx = (ecx - eax);  // @1288_61dcd0
  FL[3] = ecx;  // @1289_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 488), sizeof v); (u32)v; });  // @1290_61dcd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4 + 4), &v, sizeof v); }  // @1291_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 504), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1292_61dcd0
  if (FL[0] != FL[1]) goto L61ee35;  // @1293_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1294_61dcd0
  if (FL[0] == FL[1]) goto L61eded;  // @1295_61dcd0
  PV[219] = (u32)(esi);  // @1296_61dcd0
  eax = ext_61cb70_cdecl1(PV[219]);  // @1297_61dcd0
  ecx = edx = 0;  // @1298_61dcd0
  FL[2] = (eax & eax);  // @1299_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1300_61dcd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1301_61dcd0
  PV[220] = (u32)(eax);  // @1302_61dcd0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1303_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 332), sizeof v); (u32)v; });  // @1304_61dcd0
  PV[221] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1305_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @1306_61dcd0
  PV[222] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1307_61dcd0
  eax = ((u32( *)(u32, u32, u32))(eax))(PV[222], PV[221], PV[220]);  // @1308_61dcd0
  ecx = edx = 0;  // @1309_61dcd0
  L61eded:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 484), &v, sizeof v); }  // @1311_61dcd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 492), &v, sizeof v); }  // @1312_61dcd0
  goto L61ee35;  // @1313_61dcd0
  L61ee03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1315_61dcd0
  ecx = eax;  // @1316_61dcd0
  CFv = ((u32)(ecx) < (u32)((u32)(11)));  // @1317_61dcd0
  ecx = (ecx - (u32)(11));  // @1318_61dcd0
  FL[3] = ecx;  // @1319_61dcd0
  if (FL[3] == 0) goto L61ee1f;  // @1320_61dcd0
  CFv = ((u32)(ecx) < (u32)((u32)(2)));  // @1321_61dcd0
  ecx = (ecx - (u32)(2));  // @1322_61dcd0
  FL[3] = ecx;  // @1323_61dcd0
  if (FL[3] != 0) goto L61ee38;  // @1324_61dcd0
  PV[223] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1325_61dcd0
  PV[224] = (u32)(edi);  // @1326_61dcd0
  PV[225] = (u32)(ebx);  // @1327_61dcd0
  PV[226] = (u32)(esi);  // @1328_61dcd0
  eax = ext_620c00_cdecl4(PV[226], PV[225], PV[224], PV[223]);  // @1329_61dcd0
  ecx = edx = 0;  // @1330_61dcd0
  goto L61ee2a;  // @1331_61dcd0
  L61ee1f:;
  PV[227] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1333_61dcd0
  PV[228] = (u32)(edi);  // @1334_61dcd0
  PV[229] = (u32)(ebx);  // @1335_61dcd0
  PV[230] = (u32)(esi);  // @1336_61dcd0
  eax = ext_620d50_cdecl4(PV[230], PV[229], PV[228], PV[227]);  // @1337_61dcd0
  ecx = edx = 0;  // @1338_61dcd0
  L61ee2a:;
  FL[2] = (eax & eax);  // @1340_61dcd0
  if (FL[2] == 0) goto L61ef10;  // @1341_61dcd0
  L61ee35:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1343_61dcd0
  L61ee38:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1345_61dcd0
  if (FL[0] == FL[1]) goto L61ee68;  // @1346_61dcd0
  CFv = ((u32)(eax + (u32)(-11)) < (u32)(eax));  // @1347_61dcd0
  eax = (eax + (u32)(-11));  // @1348_61dcd0
  FL[3] = eax;  // @1349_61dcd0
  FL[0] = eax; FL[1] = (u32)(31);  // @1350_61dcd0
  if (FL[0] > FL[1]) goto L61ee54;  // @1351_61dcd0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6418596), sizeof v); (u32)v; });  // @1352_61dcd0
  switch (eax) {  // @1353_61dcd0
  case 0: goto L61ee68;  // @1354_61dcd0
  case 1: goto L61ee54;  // @1355_61dcd0
  default: __builtin_trap(); }  // @1356_61dcd0
  L61ee54:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }); FL[1] = (u32)(51);  // @1358_61dcd0
  if (FL[0] == FL[1]) goto L61ee68;  // @1359_61dcd0
  PV[231] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1360_61dcd0
  PV[232] = (u32)(edi);  // @1361_61dcd0
  PV[233] = (u32)(ebx);  // @1362_61dcd0
  PV[234] = (u32)(esi);  // @1363_61dcd0
  eax = ext_620cb0_cdecl4(PV[234], PV[233], PV[232], PV[231]);  // @1364_61dcd0
  ecx = edx = 0;  // @1365_61dcd0
  L61ee68:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1367_61dcd0
  eax = (u32)(EBP + 28);  // @1368_61dcd0
  PV[235] = (u32)(eax);  // @1369_61dcd0
  PV[236] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1370_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1371_61dcd0
  PV[237] = (u32)(edi);  // @1372_61dcd0
  PV[238] = (u32)(ebx);  // @1373_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32))(eax))(PV[238], PV[237], PV[236], PV[235]);  // @1374_61dcd0
  ecx = edx = 0;  // @1375_61dcd0
  ecx = eax;  // @1376_61dcd0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 24), &v, sizeof v); }  // @1377_61dcd0
  goto L61dd0d;  // @1378_61dcd0
  L61ee85:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @1380_61dcd0
  L61ee87:;
  eax = 0;  // @1382_61dcd0
  FL[3] = eax;  // @1383_61dcd0
  return eax;  // @1384_61dcd0
  L61ee90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @1386_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1387_61dcd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1388_61dcd0
  eax = (u32)(4);  // @1389_61dcd0
  return eax;  // @1390_61dcd0
  L61eea4:;
  eax = (u32)(5);  // @1392_61dcd0
  return eax;  // @1393_61dcd0
  L61eeb0:;
  eax = (u32)(6);  // @1395_61dcd0
  return eax;  // @1396_61dcd0
  L61eebc:;
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @1398_61dcd0
  if (FL[0] != FL[1]) goto L61ee87;  // @1399_61dcd0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 624), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1400_61dcd0
  if (FL[0] == FL[1]) goto L61ef04;  // @1401_61dcd0
  PV[239] = (u32)(ebx);  // @1402_61dcd0
  PV[240] = (u32)(edx);  // @1403_61dcd0
  PV[241] = (u32)(edx);  // @1404_61dcd0
  eax = (u32)(esi + 256);  // @1405_61dcd0
  PV[242] = (u32)(eax);  // @1406_61dcd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1407_61dcd0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(eax))(PV[242], (u32)(-4), PV[241], PV[240], PV[239]);  // @1408_61dcd0
  ecx = edx = 0;  // @1409_61dcd0
  FL[0] = eax; FL[1] = (u32)(-1);  // @1410_61dcd0
  if (FL[0] != FL[1]) goto L61eef1;  // @1411_61dcd0
  L61eee5:;
  eax = (u32)(2);  // @1413_61dcd0
  return eax;  // @1414_61dcd0
  L61eef1:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 612), &v, sizeof v); }  // @1416_61dcd0
  eax = 0;  // @1417_61dcd0
  FL[3] = eax;  // @1418_61dcd0
  return eax;  // @1419_61dcd0
  L61ef04:;
  eax = (u32)(3);  // @1421_61dcd0
  return eax;  // @1422_61dcd0
  L61ef10:;
  eax = (u32)(1);  // @1424_61dcd0
  return eax;  // @1425_61dcd0
  L61ef1c:;
  eax = (u32)(21);  // @1427_61dcd0
  return eax;  // @1428_61dcd0
  L61ef28:;
  eax = (u32)(22);  // @1430_61dcd0
  return eax;  // @1431_61dcd0
  L61ef34:;
  eax = (u32)(10);  // @1433_61dcd0
  return eax;  // @1434_61dcd0
  L61ef40:;
  eax = (u32)(12);  // @1436_61dcd0
  return eax;  // @1437_61dcd0
  L61ef4c:;
  eax = (u32)(11);  // @1439_61dcd0
  return eax;  // @1440_61dcd0
  L61ef58:;
  PV[243] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @1442_61dcd0
  { u32 v = (u32)((u32)(6409520)); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @1443_61dcd0
  PV[244] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @1444_61dcd0
  PV[245] = (u32)(edi);  // @1445_61dcd0
  PV[246] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @1446_61dcd0
  PV[247] = (u32)(esi);  // @1447_61dcd0
  eax = ext_61d090_cdecl6(PV[247], (u32)(0), PV[246], PV[245], PV[244], PV[243]);  // @1448_61dcd0
  ecx = edx = 0;  // @1449_61dcd0
  return eax;  // @1450_61dcd0
  L61ef81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @1452_61dcd0
  FL[0] = ecx; FL[1] = (u32)(12);  // @1453_61dcd0
  if (FL[0] == FL[1]) goto L61ef9f;  // @1454_61dcd0
  eax = 0;  // @1455_61dcd0
  FL[3] = eax;  // @1456_61dcd0
  FL[0] = ecx; FL[1] = (u32)(28);  // @1457_61dcd0
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @1458_61dcd0
  eax = (u32)(eax*8 + 2);  // @1459_61dcd0
  return eax;  // @1460_61dcd0
  L61ef9f:;
  eax = (u32)(17);  // @1462_61dcd0
  L61efa4:;
  return eax;  // @1464_61dcd0
}
// PCREG(61dcd0, lifted_61dcd0);  // replaced by the asm copy in batch240028

