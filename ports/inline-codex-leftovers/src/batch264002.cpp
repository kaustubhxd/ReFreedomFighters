// batch254025.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634db8_dbl(double) __asm__("ext_634db8");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 STDCALL ext_493020_stdcall1(u32) __asm__("ext_493020");
extern "C" u32 STDCALL ext_493090_stdcall1(u32) __asm__("ext_493090");
extern "C" u32 STDCALL ext_61a520_stdcall3(u32, u32, u32) __asm__("ext_61a520");
extern "C" u32 THISCALL ext_48c4b0_thiscall3(u32, u32, u32) __asm__("ext_48c4b0");
extern "C" u32 THISCALL ext_48d010_thiscall1(u32) __asm__("ext_48d010");
extern "C" u32 THISCALL ext_48d0e0_thiscall1(u32) __asm__("ext_48d0e0");
extern "C" u32 THISCALL ext_4923e0_thiscall1(u32) __asm__("ext_4923e0");
extern "C" u32 THISCALL ext_49e0e0_thiscall2(u32, u32) __asm__("ext_49e0e0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d5510_thiscall1(u32) __asm__("ext_4d5510");
extern "C" u32 THISCALL ext_4d5640_thiscall1(u32) __asm__("ext_4d5640");
extern "C" u32 THISCALL ext_4d7610_thiscall3(u32, u32, u32) __asm__("ext_4d7610");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_609af0_thiscall4(u32, u32, u32, u32) __asm__("ext_609af0");
extern "C" u32 THISCALL ext_60ee10_thiscall3(u32, u32, u32) __asm__("ext_60ee10");
extern "C" u32 THISCALL ext_610070_thiscall2(u32, u32) __asm__("ext_610070");
extern "C" u32 THISCALL ext_6107e0_thiscall2(u32, u32) __asm__("ext_6107e0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_48ede0_cdecl0(void) __asm__("ext_48ede0");
extern "C" u32 ext_61ce20_cdecl5(...) __asm__("ext_61ce20");
extern "C" u32 ext_61d090_cdecl6(...) __asm__("ext_61d090");
extern "C" u32 ext_61f400_cdecl4(...) __asm__("ext_61f400");
extern "C" u32 ext_61f7f0_cdecl1(...) __asm__("ext_61f7f0");
extern "C" u32 ext_61fd60_cdecl3(...) __asm__("ext_61fd60");
extern "C" u32 ext_620180_cdecl4(...) __asm__("ext_620180");
extern "C" u32 ext_6204a0_cdecl1(...) __asm__("ext_6204a0");
extern "C" u32 ext_6206e0_cdecl1(...) __asm__("ext_6206e0");
extern "C" u32 ext_620840_cdecl4(...) __asm__("ext_620840");
extern "C" u32 ext_620c00_cdecl4(...) __asm__("ext_620c00");
extern "C" u32 ext_620cb0_cdecl4(...) __asm__("ext_620cb0");
extern "C" u32 ext_620d50_cdecl4(...) __asm__("ext_620d50");
extern "C" u32 ext_621230_cdecl5(...) __asm__("ext_621230");
extern "C" u32 ext_626e10_cdecl2(...) __asm__("ext_626e10");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_48b780(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6679fd);  // @h_48b780
  u8 F[0x2390] __attribute__((aligned(4)));   // Candidate: per-invocation frame, no shared static locals
  u32 EBP = (u32)(F + 0x2290);
  u32 PV[81], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x2290 + 8, &a0, 4);
  ebx = ecx;  // @0_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340980), sizeof v); (u32)v; });  // @1_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8764), &v, sizeof v); }  // @3_48b780
  FL[2] = (ecx & ecx);  // @4_48b780
  if (FL[2] == 0) goto L48b7cb;  // @5_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 0)))(ecx);  // @7_48b780
  ecx = edx = 0;  // @8_48b780
  L48b7cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_48b780
  ecx = ebx;  // @11_48b780
  { u32 v = (u32)((u32)(262144)); __builtin_memcpy((void *)(u32)(ebx + 23869), &v, sizeof v); }  // @12_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @13_48b780
  ecx = edx = 0;  // @14_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 204)))(ecx);  // @17_48b780
  ecx = edx = 0;  // @18_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 196)))(ecx);  // @21_48b780
  ecx = edx = 0;  // @22_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @25_48b780
  ecx = edx = 0;  // @26_48b780
  ecx = eax;  // @27_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 120)))(ecx);  // @29_48b780
  ecx = edx = 0;  // @30_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2816), sizeof v); (u32)v; });  // @31_48b780
  ecx = (u32)(ebx + 2816);  // @32_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @33_48b780
  ecx = edx = 0;  // @34_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23857), sizeof v); (u32)v; });  // @37_48b780
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 208), &v, sizeof v); }  // @38_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @40_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 100)))(ecx);  // @42_48b780
  ecx = edx = 0;  // @43_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_48b780
  ecx = ebx;  // @45_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 424)))(ecx);  // @46_48b780
  ecx = edx = 0;  // @47_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @48_48b780
  esi = eax;  // @49_48b780
  ecx = ebx;  // @50_48b780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 8716), &v, sizeof v); }  // @51_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 448)))(ecx);  // @52_48b780
  ecx = edx = 0;  // @53_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @54_48b780
  ecx = ebx;  // @55_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8708), &v, sizeof v); }  // @56_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 440)))(ecx);  // @57_48b780
  ecx = edx = 0;  // @58_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @59_48b780
  edi = eax;  // @60_48b780
  PV[0] = (u32)(ecx);  // @61_48b780
  ecx = ebx;  // @62_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 144), sizeof v); (u32)v; });  // @63_48b780
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8712), &v, sizeof v); }  // @64_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(edx))(ecx, (u32)(1), (u32)(0), (u32)(0));  // @65_48b780
  ecx = edx = 0;  // @66_48b780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @67_48b780
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @68_48b780
  if ((s32)FL[0] < (s32)FL[1]) goto L48b8a8;  // @69_48b780
  FL[2] = (esi & esi);  // @70_48b780
  if ((s32)FL[2] < 0) goto L48b8a8;  // @71_48b780
  FL[2] = (edi & edi);  // @72_48b780
  if ((s32)FL[2] >= 0) goto L48b8c0;  // @73_48b780
  L48b8a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @75_48b780
  PV[1] = (u32)(eax);  // @76_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @77_48b780
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 36)))(PV[1], (u32)(6871368), (u32)(6871344));  // @78_48b780
  ecx = edx = 0;  // @79_48b780
  L48b8c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @81_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(57568));  // @83_48b780
  ecx = edx = 0;  // @84_48b780
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; });  // @85_48b780
  edi = eax;  // @86_48b780
  eax = ext_41e290_cdecl1(PV[2]);  // @87_48b780
  ecx = edx = 0;  // @88_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @89_48b780
  esi = eax;  // @90_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_48b780
  PV[3] = (u32)(edi);  // @92_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[3]);  // @93_48b780
  ecx = edx = 0;  // @94_48b780
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; });  // @95_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_48b780
  ecx = ebx;  // @97_48b780
  PV[5] = (u32)(esi);  // @98_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 452)))(ecx, PV[5], PV[4]);  // @99_48b780
  ecx = edx = 0;  // @100_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_48b780
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; });  // @102_48b780
  PV[7] = (u32)(esi);  // @103_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @104_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[7], PV[6]);  // @106_48b780
  ecx = edx = 0;  // @107_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @108_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(14737408));  // @110_48b780
  ecx = edx = 0;  // @111_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8716), sizeof v); (u32)v; });  // @112_48b780
  eax = (u32)(esi + 393216);  // @113_48b780
  PV[8] = (u32)(eax);  // @114_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8768), &v, sizeof v); }  // @115_48b780
  eax = ext_41e290_cdecl1(PV[8]);  // @116_48b780
  ecx = edx = 0;  // @117_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @118_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8732), &v, sizeof v); }  // @119_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(16711808));  // @121_48b780
  ecx = edx = 0;  // @122_48b780
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8712), sizeof v); (u32)v; });  // @123_48b780
  eax = ext_41e290_cdecl1(PV[9]);  // @124_48b780
  ecx = edx = 0;  // @125_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @126_48b780
  ecx = ebx;  // @127_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8716), &v, sizeof v); }  // @128_48b780
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8712), sizeof v); (u32)v; });  // @129_48b780
  PV[11] = (u32)(eax);  // @130_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 444)))(ecx, PV[11], PV[10]);  // @131_48b780
  ecx = edx = 0;  // @132_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8716), sizeof v); (u32)v; });  // @133_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 7261), &v, sizeof v); }  // @134_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @135_48b780
  PV[12] = (u32)(edi);  // @136_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @137_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[12]);  // @138_48b780
  ecx = edx = 0;  // @139_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_48b780
  ecx = ebx;  // @141_48b780
  PV[13] = (u32)(esi);  // @142_48b780
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8732), sizeof v); (u32)v; });  // @143_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 428)))(ecx, PV[14], PV[13]);  // @144_48b780
  ecx = edx = 0;  // @145_48b780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2788), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @146_48b780
  if (FL[0] == FL[1]) goto L48b9ed;  // @147_48b780
  eax = (u32)(EBP - 528);  // @148_48b780
  ecx = ebx;  // @149_48b780
  PV[15] = (u32)(eax);  // @150_48b780
  eax = ext_48c4b0_thiscall3(ecx, PV[15], (u32)(6871236));  // @151_48b780
  ecx = edx = 0;  // @152_48b780
  ecx = eax;  // @153_48b780
  reg.state = (s32)((u32)(0));  // @154_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @155_48b780
    // @156_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2788), sizeof v); (u32)v; });  // @157_48b780
  PV[16] = (u32)(eax);  // @158_48b780
  eax = ext_49e0e0_thiscall2(ecx, PV[16]);  // @159_48b780
  ecx = edx = 0;  // @160_48b780
  ecx = (u32)(EBP - 528);  // @161_48b780
  reg.state = (s32)((u32)(4294967295));  // @162_48b780
  eax = ext_4cbec0_thiscall1(ecx);  // @163_48b780
  ecx = edx = 0;  // @164_48b780
  L48b9ed:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @166_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(16742263));  // @168_48b780
  ecx = edx = 0;  // @169_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @170_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8712), &v, sizeof v); }  // @171_48b780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8728), &v, sizeof v); }  // @172_48b780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @173_48b780
  if (FL[0] == FL[1]) goto L48ba4a;  // @174_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @175_48b780
  ecx = ebx;  // @176_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 456)))(ecx);  // @177_48b780
  ecx = edx = 0;  // @178_48b780
  edi = eax;  // @179_48b780
  FL[0] = edi; FL[1] = (u32)(-1);  // @180_48b780
  if (FL[0] == FL[1]) goto L48ba4a;  // @181_48b780
  PV[17] = (u32)(edi);  // @182_48b780
  eax = ext_41e290_cdecl1(PV[17]);  // @183_48b780
  ecx = edx = 0;  // @184_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @185_48b780
  esi = eax;  // @186_48b780
  ecx = ebx;  // @187_48b780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 8728), &v, sizeof v); }  // @188_48b780
  PV[18] = (u32)(edi);  // @189_48b780
  PV[19] = (u32)(esi);  // @190_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 460)))(ecx, PV[19], PV[18]);  // @191_48b780
  ecx = edx = 0;  // @192_48b780
  L48ba4a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @194_48b780
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8712), sizeof v); (u32)v; });  // @195_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @196_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[20]);  // @197_48b780
  ecx = edx = 0;  // @198_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @199_48b780
  ecx = ebx;  // @200_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 480)))(ecx);  // @201_48b780
  ecx = edx = 0;  // @202_48b780
  esi = eax;  // @203_48b780
  FL[2] = (esi & esi);  // @204_48b780
  if ((s32)FL[2] <= 0) goto L48baa9;  // @205_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @206_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(8421440));  // @208_48b780
  ecx = edx = 0;  // @209_48b780
  edi = eax;  // @210_48b780
  PV[21] = (u32)(esi);  // @211_48b780
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8712), &v, sizeof v); }  // @212_48b780
  eax = ext_41e290_cdecl1(PV[21]);  // @213_48b780
  ecx = edx = 0;  // @214_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @215_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @216_48b780
  PV[22] = (u32)(edi);  // @217_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @218_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[22]);  // @219_48b780
  ecx = edx = 0;  // @220_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @221_48b780
  ecx = ebx;  // @222_48b780
  PV[23] = (u32)(esi);  // @223_48b780
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @224_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 484)))(ecx, PV[24], PV[23]);  // @225_48b780
  ecx = edx = 0;  // @226_48b780
  L48baa9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @228_48b780
  ecx = ebx;  // @229_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 240)))(ecx);  // @230_48b780
  ecx = edx = 0;  // @231_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @232_48b780
  ecx = ebx;  // @233_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 224)))(ecx);  // @234_48b780
  ecx = edx = 0;  // @235_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @236_48b780
  ecx = ebx;  // @237_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 244)))(ecx);  // @238_48b780
  ecx = edx = 0;  // @239_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @240_48b780
  ecx = ebx;  // @241_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 252)))(ecx);  // @242_48b780
  ecx = edx = 0;  // @243_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @244_48b780
  ecx = ebx;  // @245_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 264)))(ecx);  // @246_48b780
  ecx = edx = 0;  // @247_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @248_48b780
  ecx = ebx;  // @249_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 432)))(ecx);  // @250_48b780
  ecx = edx = 0;  // @251_48b780
  esi = eax;  // @252_48b780
  ecx = (u32)(esi + 15);  // @253_48b780
  ecx = (ecx & (u32)(4294967280));  // @254_48b780
  FL[3] = ecx;  // @255_48b780
  PV[25] = (u32)(ecx);  // @256_48b780
  eax = ext_41e290_cdecl1(PV[25]);  // @257_48b780
  ecx = edx = 0;  // @258_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @259_48b780
  edi = eax;  // @260_48b780
  ecx = ebx;  // @261_48b780
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8708), &v, sizeof v); }  // @262_48b780
  PV[26] = (u32)(esi);  // @263_48b780
  PV[27] = (u32)(edi);  // @264_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 436)))(ecx, PV[27], PV[26]);  // @265_48b780
  ecx = edx = 0;  // @266_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @267_48b780
  ecx = ebx;  // @268_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 488)))(ecx);  // @269_48b780
  ecx = edx = 0;  // @270_48b780
  esi = eax;  // @271_48b780
  ecx = (u32)(EBP - 8760);  // @272_48b780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 8736), &v, sizeof v); }  // @273_48b780
  eax = ext_4d5510_thiscall1(ecx);  // @274_48b780
    // @275_48b780
  reg.state = (s32)((u32)(1));  // @276_48b780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8724), &v, sizeof v); }  // @277_48b780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8720), &v, sizeof v); }  // @278_48b780
  FL[2] = (esi & esi);  // @279_48b780
  if ((s32)FL[2] <= 0) goto L48bc20;  // @280_48b780
  eax = (u32)(esi + 15);  // @281_48b780
  eax = (eax & (u32)(4294967280));  // @282_48b780
  FL[3] = eax;  // @283_48b780
  PV[28] = (u32)(eax);  // @284_48b780
  eax = ext_41e290_cdecl1(PV[28]);  // @285_48b780
  ecx = edx = 0;  // @286_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @287_48b780
  edi = eax;  // @288_48b780
  ecx = ebx;  // @289_48b780
  PV[29] = (u32)(esi);  // @290_48b780
  PV[30] = (u32)(edi);  // @291_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 492)))(ecx, PV[30], PV[29]);  // @292_48b780
  ecx = edx = 0;  // @293_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @294_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @295_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 164)))(ecx);  // @296_48b780
  ecx = edx = 0;  // @297_48b780
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 8760), &v, sizeof v); }  // @298_48b780
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8759), &v, sizeof v); }  // @299_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @300_48b780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 8751), &v, sizeof v); }  // @301_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @302_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8755), &v, sizeof v); }  // @303_48b780
  eax = 0;  // @304_48b780
  FL[3] = eax;  // @305_48b780
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @306_48b780
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @307_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8743), &v, sizeof v); }  // @308_48b780
  eax = (u32)(esi + 15);  // @309_48b780
  eax = (eax & (u32)(4294967280));  // @310_48b780
  FL[3] = eax;  // @311_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8720), &v, sizeof v); }  // @312_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @313_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @314_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @315_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @316_48b780
  ecx = edx = 0;  // @317_48b780
  ecx = eax;  // @318_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @319_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @320_48b780
  ecx = edx = 0;  // @321_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @322_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @323_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @324_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @325_48b780
  ecx = edx = 0;  // @326_48b780
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8720), sizeof v); (u32)v; });  // @327_48b780
  ecx = eax;  // @328_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @329_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, PV[31]);  // @330_48b780
  ecx = edx = 0;  // @331_48b780
  PV[32] = (u32)(esi);  // @332_48b780
  PV[33] = (u32)(eax);  // @333_48b780
  ecx = (u32)(EBP - 8760);  // @334_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8724), &v, sizeof v); }  // @335_48b780
  eax = ext_4d7610_thiscall3(ecx, PV[33], PV[32]);  // @336_48b780
  ecx = edx = 0;  // @337_48b780
  PV[34] = (u32)(edi);  // @338_48b780
  eax = ext_634273_cdecl2(PV[34], (u32)(1));  // @339_48b780
  ecx = edx = 0;  // @340_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @341_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @342_48b780
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8724), sizeof v); (u32)v; });  // @343_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[35], (u32)(6871428));  // @344_48b780
  ecx = edx = 0;  // @345_48b780
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; });  // @346_48b780
  goto L48bc45;  // @347_48b780
  L48bc20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @349_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 164)))(ecx);  // @351_48b780
  ecx = edx = 0;  // @352_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @353_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @354_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @355_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @356_48b780
  ecx = edx = 0;  // @357_48b780
  ecx = eax;  // @358_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @359_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 4)))(ecx);  // @360_48b780
  ecx = edx = 0;  // @361_48b780
  L48bc45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @363_48b780
  ecx = ebx;  // @364_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8764), sizeof v); (u32)v; });  // @365_48b780
  PV[36] = (u32)(esi);  // @366_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 372)))(ecx, PV[36]);  // @367_48b780
  ecx = edx = 0;  // @368_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @369_48b780
  ecx = ebx;  // @370_48b780
  PV[37] = (u32)(esi);  // @371_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, PV[37]);  // @372_48b780
  ecx = edx = 0;  // @373_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @374_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @375_48b780
  FL[2] = (esi & esi);  // @376_48b780
  if (FL[2] == 0) goto L48be80;  // @377_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8728), sizeof v); (u32)v; });  // @378_48b780
  FL[2] = (edx & edx);  // @379_48b780
  if (FL[2] == 0) goto L48bc90;  // @380_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @381_48b780
  ecx = esi;  // @382_48b780
  PV[38] = (u32)(edx);  // @383_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, PV[38]);  // @384_48b780
  ecx = edx = 0;  // @385_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @386_48b780
  L48bc90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @388_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @389_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(6786308));  // @390_48b780
  ecx = edx = 0;  // @391_48b780
  FL[2] = (eax & eax);  // @392_48b780
  if (FL[2] == 0) goto L48be80;  // @393_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @394_48b780
  edx = (u32)(EBP - 400);  // @395_48b780
  PV[39] = (u32)(edx);  // @396_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @397_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 272)))(ecx, PV[39]);  // @398_48b780
  ecx = edx = 0;  // @399_48b780
  ecx = (u32)(EBP - 400);  // @400_48b780
  reg.state = (s32)((u32)(2));  // @401_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @402_48b780
    // @403_48b780
  edx = (u32)(EBP - 272);  // @404_48b780
  edx = (edx - eax);  // @405_48b780
  FL[3] = edx;  // @406_48b780
  L48bcd4:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @408_48b780
  eax = (u32)(eax + 1);  // @409_48b780
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @410_48b780
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @411_48b780
  if (FL[2] != 0) goto L48bcd4;  // @412_48b780
  ecx = (u32)(EBP - 272);  // @413_48b780
  edx = (u32)(6789528);  // @414_48b780
  esi = (u32)(7);  // @415_48b780
  L48bcf1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @417_48b780
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @418_48b780
  if (FL[0] != FL[1]) goto L48bd96;  // @419_48b780
  ecx = (ecx + (u32)(4));  // @420_48b780
  FL[3] = ecx;  // @421_48b780
  edx = (edx + (u32)(4));  // @422_48b780
  FL[3] = edx;  // @423_48b780
  esi = (esi - (u32)(4));  // @424_48b780
  FL[3] = esi;  // @425_48b780
  if (esi <= 0xfffffffbu) goto L48bcf1;  // @426_48b780: SUB esi,4; JAE iff no unsigned borrow
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xffff);  // @427_48b780
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @428_48b780
  if (FL[0] != FL[1]) goto L48bd96;  // @429_48b780
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; })) & 0xff);  // @430_48b780
  FL[0] = (eax & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @431_48b780
  if (FL[0] != FL[1]) goto L48bd96;  // @432_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @433_48b780
  edx = (u32)(EBP - 144);  // @434_48b780
  PV[40] = (u32)(edx);  // @435_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @436_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 276)))(ecx, PV[40]);  // @437_48b780
  ecx = edx = 0;  // @438_48b780
  ecx = (u32)(EBP - 400);  // @439_48b780
  reg.state = (s32)((u32)(3));  // @440_48b780
  PV[41] = (u32)(ecx);  // @441_48b780
  ecx = (u32)(EBP - 528);  // @442_48b780
  PV[42] = (u32)(ecx);  // @443_48b780
  ecx = eax;  // @444_48b780
  eax = ext_4cc1e0_thiscall3(ecx, PV[42], PV[41]);  // @445_48b780
  ecx = edx = 0;  // @446_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @447_48b780
  reg.state = (s32)((u32)(4));  // @448_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @449_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @450_48b780
  ecx = eax;  // @451_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @452_48b780
    // @453_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @454_48b780
  PV[43] = (u32)(eax);  // @455_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @456_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 160)))(ecx, (u32)(0), PV[43]);  // @457_48b780
  ecx = edx = 0;  // @458_48b780
  ecx = (u32)(EBP - 528);  // @459_48b780
  eax = ext_4cbec0_thiscall1(ecx);  // @460_48b780
  ecx = edx = 0;  // @461_48b780
  ecx = (u32)(EBP - 144);  // @462_48b780
  reg.state = (s32)((u32)(2));  // @463_48b780
  eax = ext_4cbec0_thiscall1(ecx);  // @464_48b780
  ecx = edx = 0;  // @465_48b780
  goto L48bdc3;  // @466_48b780
  L48bd96:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @468_48b780
  ecx = (u32)(EBP - 400);  // @469_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @470_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @471_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @472_48b780
    // @473_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @474_48b780
  PV[44] = (u32)(eax);  // @475_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @476_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 160)))(ecx, (u32)(0), PV[44]);  // @477_48b780
  ecx = edx = 0;  // @478_48b780
  L48bdc3:;
  eax = (u32)(EBP - 144);  // @480_48b780
  ecx = ebx;  // @481_48b780
  PV[45] = (u32)(eax);  // @482_48b780
  eax = ext_48c4b0_thiscall3(ecx, PV[45], (u32)(6871132));  // @483_48b780
  ecx = edx = 0;  // @484_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @485_48b780
  reg.state = (s32)((u32)(5));  // @486_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @487_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @488_48b780
  ecx = eax;  // @489_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @490_48b780
    // @491_48b780
  PV[46] = (u32)(eax);  // @492_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @493_48b780
  ecx = ebx;  // @494_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[46]);  // @495_48b780
  ecx = edx = 0;  // @496_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @497_48b780
  PV[47] = (u32)(eax);  // @498_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @499_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 164)))(ecx, PV[47]);  // @500_48b780
  ecx = edx = 0;  // @501_48b780
  ecx = (u32)(EBP - 144);  // @502_48b780
  reg.state = (s32)((u32)(2));  // @503_48b780
  eax = ext_4cbec0_thiscall1(ecx);  // @504_48b780
  ecx = edx = 0;  // @505_48b780
  eax = (u32)(EBP - 144);  // @506_48b780
  ecx = ebx;  // @507_48b780
  PV[48] = (u32)(eax);  // @508_48b780
  eax = ext_48c4b0_thiscall3(ecx, PV[48], (u32)(6871128));  // @509_48b780
  ecx = edx = 0;  // @510_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @511_48b780
  reg.state = (s32)((u32)(6));  // @512_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @513_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @514_48b780
  ecx = eax;  // @515_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @516_48b780
    // @517_48b780
  PV[49] = (u32)(eax);  // @518_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @519_48b780
  ecx = ebx;  // @520_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 464)))(ecx, PV[49]);  // @521_48b780
  ecx = edx = 0;  // @522_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @523_48b780
  PV[50] = (u32)(eax);  // @524_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @525_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 152)))(ecx, PV[50]);  // @526_48b780
  ecx = edx = 0;  // @527_48b780
  ecx = (u32)(EBP - 144);  // @528_48b780
  eax = ext_4cbec0_thiscall1(ecx);  // @529_48b780
  ecx = edx = 0;  // @530_48b780
  ecx = (u32)(EBP - 400);  // @531_48b780
  reg.state = (s32)((u32)(1));  // @532_48b780
  eax = ext_4cbec0_thiscall1(ecx);  // @533_48b780
  ecx = edx = 0;  // @534_48b780
  L48be80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @536_48b780
  ecx = ebx;  // @537_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 376), sizeof v); (u32)v; });  // @538_48b780
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @539_48b780
  ecx = edx = 0;  // @540_48b780
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @541_48b780
  if (FL[2] != 0) goto L48bf16;  // @542_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; });  // @543_48b780
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 8760), &v, sizeof v); }  // @544_48b780
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8759), &v, sizeof v); }  // @545_48b780
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @546_48b780
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 8751), &v, sizeof v); }  // @547_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @548_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8755), &v, sizeof v); }  // @549_48b780
  eax = 0;  // @550_48b780
  FL[3] = eax;  // @551_48b780
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @552_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @553_48b780
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @554_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8743), &v, sizeof v); }  // @555_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @556_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, (u32)(-1));  // @557_48b780
  ecx = edx = 0;  // @558_48b780
  eax = (u32)(edi + 15);  // @559_48b780
  eax = (eax & (u32)(4294967280));  // @560_48b780
  FL[3] = eax;  // @561_48b780
  PV[51] = (u32)(eax);  // @562_48b780
  eax = ext_41e290_cdecl1(PV[51]);  // @563_48b780
  ecx = edx = 0;  // @564_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @565_48b780
  esi = eax;  // @566_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @567_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 156)))(ecx, (u32)(0));  // @568_48b780
  ecx = edx = 0;  // @569_48b780
  PV[52] = (u32)(edi);  // @570_48b780
  PV[53] = (u32)(esi);  // @571_48b780
  ecx = (u32)(EBP - 8760);  // @572_48b780
  eax = ext_4d7610_thiscall3(ecx, PV[53], PV[52]);  // @573_48b780
  ecx = edx = 0;  // @574_48b780
  PV[54] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8708), sizeof v); (u32)v; });  // @575_48b780
  eax = ext_634273_cdecl2(PV[54], (u32)(1));  // @576_48b780
  ecx = edx = 0;  // @577_48b780
  edi = esi;  // @578_48b780
  L48bf16:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @580_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @581_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @582_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @583_48b780
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @584_48b780
  ecx = edx = 0;  // @585_48b780
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @586_48b780
  if (FL[2] != 0) goto L48bf50;  // @587_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @588_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @589_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 360)))(ecx);  // @590_48b780
  ecx = edx = 0;  // @591_48b780
  eax = (u32)(ebx + 2995);  // @592_48b780
  ecx = (u32)(EBP - 8772);  // @593_48b780
  FL[0] = eax; FL[1] = ecx;  // @594_48b780
  if (FL[0] == FL[1]) goto L48bf50;  // @595_48b780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @596_48b780
  L48bf50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @598_48b780
  PV[55] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8768), sizeof v); (u32)v; });  // @599_48b780
  PV[56] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8732), sizeof v); (u32)v; });  // @600_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @601_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @602_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[56], PV[55]);  // @603_48b780
  ecx = edx = 0;  // @604_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @605_48b780
  ecx = ebx;  // @606_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 68)))(ecx);  // @607_48b780
  ecx = edx = 0;  // @608_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @609_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @610_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @611_48b780
  ecx = edx = 0;  // @612_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @613_48b780
  ecx = ebx;  // @614_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 104)))(ecx);  // @615_48b780
  ecx = edx = 0;  // @616_48b780
  ecx = (u32)(EBP - 700);  // @617_48b780
  eax = ext_4ccba0_thiscall1(ecx);  // @618_48b780
    // @619_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8716), sizeof v); (u32)v; });  // @620_48b780
  ecx = (u32)(EBP - 8704);  // @621_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @622_48b780
  PV[57] = (u32)(esi);  // @623_48b780
  PV[58] = (u32)(edi);  // @624_48b780
  PV[59] = (u32)(ecx);  // @625_48b780
  ecx = (u32)(EBP - 700);  // @626_48b780
  reg.state = (s32)((u32)(7));  // @627_48b780
  PV[60] = (u32)(ecx);  // @628_48b780
  ecx = ebx;  // @629_48b780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8704), &v, sizeof v); }  // @630_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, PV[60], PV[59], PV[58], PV[57]);  // @631_48b780
  ecx = edx = 0;  // @632_48b780
  PV[61] = (u32)(edi);  // @633_48b780
  eax = ext_634273_cdecl2(PV[61], (u32)(1));  // @634_48b780
  ecx = edx = 0;  // @635_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @636_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @637_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @638_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @639_48b780
  ecx = edx = 0;  // @640_48b780
  FL[2] = (eax & eax);  // @641_48b780
  if (FL[2] != 0) goto L48c00f;  // @642_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @643_48b780
  ecx = ebx;  // @644_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, (u32)(0));  // @645_48b780
  ecx = edx = 0;  // @646_48b780
  FL[2] = (eax & eax);  // @647_48b780
  if (FL[2] == 0) goto L48c00f;  // @648_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @649_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @650_48b780
  PV[62] = (u32)(ecx);  // @651_48b780
  PV[63] = (u32)(eax);  // @652_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @653_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 172)))(ecx, PV[63], (u32)(0));  // @654_48b780
  ecx = edx = 0;  // @655_48b780
  L48c00f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @657_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @658_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(4227232));  // @659_48b780
  ecx = edx = 0;  // @660_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @661_48b780
  ecx = ebx;  // @662_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @663_48b780
  ecx = edx = 0;  // @664_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @665_48b780
  ecx = ebx;  // @666_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 108)))(ecx);  // @667_48b780
  ecx = edx = 0;  // @668_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @669_48b780
  ecx = ebx;  // @670_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @671_48b780
  ecx = edx = 0;  // @672_48b780
  eax = (u32)(EBP - 8704);  // @673_48b780
  ecx = ebx;  // @674_48b780
  PV[64] = (u32)(eax);  // @675_48b780
  eax = ext_493090_stdcall1(PV[64]);  // @676_48b780
  ecx = edx = 0;  // @677_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @678_48b780
  ecx = ebx;  // @679_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 376), sizeof v); (u32)v; });  // @680_48b780
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @681_48b780
  ecx = edx = 0;  // @682_48b780
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @683_48b780
  if (FL[2] != 0) goto L48c08e;  // @684_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @685_48b780
  ecx = ebx;  // @686_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @687_48b780
  ecx = edx = 0;  // @688_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @689_48b780
  ecx = ebx;  // @690_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 228)))(ecx);  // @691_48b780
  ecx = edx = 0;  // @692_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2780), sizeof v); (u32)v; });  // @693_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @694_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 804)))(ecx);  // @695_48b780
  ecx = edx = 0;  // @696_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @697_48b780
  ecx = ebx;  // @698_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 248)))(ecx);  // @699_48b780
  ecx = edx = 0;  // @700_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @701_48b780
  ecx = ebx;  // @702_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 256)))(ecx);  // @703_48b780
  ecx = edx = 0;  // @704_48b780
  L48c08e:;
  ecx = ebx;  // @706_48b780
  eax = ext_48d0e0_thiscall1(ecx);  // @707_48b780
  ecx = edx = 0;  // @708_48b780
  eax = (u32)(EBP - 8704);  // @709_48b780
  ecx = ebx;  // @710_48b780
  PV[65] = (u32)(eax);  // @711_48b780
  eax = ext_493020_stdcall1(PV[65]);  // @712_48b780
  ecx = edx = 0;  // @713_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @714_48b780
  ecx = ebx;  // @715_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 260)))(ecx);  // @716_48b780
  ecx = edx = 0;  // @717_48b780
  ecx = ebx;  // @718_48b780
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 7261), &v, sizeof v); }  // @719_48b780
  eax = ext_48d010_thiscall1(ecx);  // @720_48b780
  ecx = edx = 0;  // @721_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @722_48b780
  ecx = ebx;  // @723_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 56)))(ecx);  // @724_48b780
  ecx = edx = 0;  // @725_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @726_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @727_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23857), sizeof v); (u32)v; });  // @728_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @729_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @730_48b780
  ecx = edx = 0;  // @731_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @732_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @733_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23857), sizeof v); (u32)v; });  // @734_48b780
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 208), &v, sizeof v); }  // @735_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @736_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @737_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(11579568));  // @738_48b780
  ecx = edx = 0;  // @739_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @740_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @741_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @742_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @743_48b780
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @744_48b780
  ecx = edx = 0;  // @745_48b780
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @746_48b780
  if (FL[2] != 0) goto L48c128;  // @747_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @748_48b780
  ecx = (u32)(EBP - 700);  // @749_48b780
  PV[66] = (u32)(ecx);  // @750_48b780
  ecx = ebx;  // @751_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 356)))(ecx, PV[66]);  // @752_48b780
  ecx = edx = 0;  // @753_48b780
  goto L48c14b;  // @754_48b780
  L48c128:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @756_48b780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6827), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @757_48b780
  if (FL[0] == FL[1]) goto L48c151;  // @758_48b780
  ecx = ebx;  // @759_48b780
  eax = ext_4923e0_thiscall1(ecx);  // @760_48b780
  ecx = edx = 0;  // @761_48b780
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2994), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @762_48b780
  if (FL[0] != FL[1]) goto L48c2c4;  // @763_48b780
  L48c14b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @765_48b780
  L48c151:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @767_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @768_48b780
  ecx = edx = 0;  // @769_48b780
  ecx = eax;  // @770_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @771_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @772_48b780
  ecx = edx = 0;  // @773_48b780
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8736), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @774_48b780
  if ((s32)FL[0] <= (s32)FL[1]) goto L48c19f;  // @775_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @776_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @777_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, (u32)(6871428));  // @778_48b780
  ecx = edx = 0;  // @779_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @780_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @781_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @782_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @783_48b780
  ecx = edx = 0;  // @784_48b780
  PV[67] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8720), sizeof v); (u32)v; });  // @785_48b780
  ecx = eax;  // @786_48b780
  PV[68] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8724), sizeof v); (u32)v; });  // @787_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @788_48b780
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 36)))(ecx, PV[68], PV[67]);  // @789_48b780
  ecx = edx = 0;  // @790_48b780
  L48c19f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @792_48b780
  PV[69] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8712), sizeof v); (u32)v; });  // @793_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @794_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[69]);  // @795_48b780
  ecx = edx = 0;  // @796_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @797_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @798_48b780
  FL[2] = (esi & esi);  // @799_48b780
  if (FL[2] == 0) goto L48c1ce;  // @800_48b780
  L48c1c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @802_48b780
  ecx = esi;  // @803_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 56)))(ecx);  // @804_48b780
  ecx = edx = 0;  // @805_48b780
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @806_48b780
  FL[2] = (esi & esi);  // @807_48b780
  if (FL[2] != 0) goto L48c1c0;  // @808_48b780
  L48c1ce:;
  ecx = ebx;  // @810_48b780
  eax = ext_48ede0_cdecl0();  // @811_48b780
  ecx = edx = 0;  // @812_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @813_48b780
  ecx = ebx;  // @814_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 104)))(ecx);  // @815_48b780
  ecx = edx = 0;  // @816_48b780
  eax = ext_41e290_cdecl1((u32)(264));  // @817_48b780
  ecx = edx = 0;  // @818_48b780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8736), &v, sizeof v); }  // @819_48b780
  reg.state = (s32)((u32)(8));  // @820_48b780
  FL[2] = (eax & eax);  // @821_48b780
  if (FL[2] == 0) goto L48c211;  // @822_48b780
  ecx = eax;  // @823_48b780
  eax = ext_4d8330_thiscall4(ecx, (u32)(6873700), (u32)(6873624), (u32)(7338644));  // @824_48b780
  ecx = edx = 0;  // @825_48b780
  edx = eax;  // @826_48b780
  goto L48c213;  // @827_48b780
  L48c211:;
  edx = 0;  // @829_48b780
  FL[3] = edx;  // @830_48b780
  L48c213:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @832_48b780
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7338648), &v, sizeof v); }  // @833_48b780
  PV[70] = (u32)(edx);  // @834_48b780
  reg.state = (s32)((u32)(7));  // @835_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @836_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[70]);  // @837_48b780
  ecx = edx = 0;  // @838_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @839_48b780
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7338632), &v, sizeof v); }  // @840_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @841_48b780
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @842_48b780
  ecx = edx = 0;  // @843_48b780
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7233985), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @844_48b780
  if (FL[0] == FL[1]) goto L48c2c4;  // @845_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @846_48b780
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7233985), &v, sizeof v); }  // @847_48b780
  ecx = (u32)(ecx + 6839);  // @848_48b780
  eax = ext_4cc5f0_thiscall1(ecx);  // @849_48b780
  ecx = edx = 0;  // @850_48b780
  FL[2] = (eax & eax);  // @851_48b780
  if (FL[2] == 0) goto L48c2b4;  // @852_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @853_48b780
  ecx = (u32)(ecx + 6839);  // @854_48b780
  eax = ext_4cc1d0_thiscall1(ecx);  // @855_48b780
    // @856_48b780
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775380), sizeof v); (u32)v; });  // @857_48b780
  edi = eax;  // @858_48b780
  PV[71] = (u32)(edi);  // @859_48b780
  eax = ((u32( *)(u32, u32))(ebx))(PV[71], (u32)(10));  // @860_48b780
  ecx = edx = 0;  // @861_48b780
  esi = eax;  // @862_48b780
  FL[2] = (esi & esi);  // @863_48b780
  if (FL[2] == 0) goto L48c2b4;  // @864_48b780
  L48c291:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @866_48b780
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @867_48b780
  PV[72] = (u32)(edi);  // @868_48b780
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @869_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 428)))(ecx, PV[72]);  // @870_48b780
  ecx = edx = 0;  // @871_48b780
  edi = (u32)(esi + 1);  // @872_48b780
  PV[73] = (u32)(edi);  // @873_48b780
  eax = ((u32( *)(u32, u32))(ebx))(PV[73], (u32)(10));  // @874_48b780
  ecx = edx = 0;  // @875_48b780
  esi = eax;  // @876_48b780
  FL[2] = (esi & esi);  // @877_48b780
  if (FL[2] != 0) goto L48c291;  // @878_48b780
  L48c2b4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @880_48b780
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @881_48b780
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(16777215));  // @882_48b780
  ecx = edx = 0;  // @883_48b780
  L48c2c4:;
  ecx = (u32)(EBP - 700);  // @885_48b780
  eax = ext_4ccf60_thiscall1(ecx);  // @886_48b780
  ecx = edx = 0;  // @887_48b780
  ecx = (u32)(EBP - 8760);  // @888_48b780
  eax = ext_4d5640_thiscall1(ecx);  // @889_48b780
  ecx = edx = 0;  // @890_48b780
  SEH_LEAVE(); __asm__ volatile("" :: "m"(F) : "memory");  // hand fix: keep F live (stack coloring)  // @891_48b780
  ext_633654(G(u32, 0x6f5630));  // @892_48b780
  return eax;  // @893_48b780
}
PCREG(48b780, lifted_48b780);
