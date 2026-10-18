// batch252009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_435a10_thiscall1(u32) __asm__("ext_435a10");
extern "C" u32 THISCALL ext_435d30_thiscall2(u32, u32) __asm__("ext_435d30");
extern "C" u32 THISCALL ext_436170_thiscall2(u32, u32) __asm__("ext_436170");
extern "C" u32 THISCALL ext_4361a0_thiscall2(u32, u32) __asm__("ext_4361a0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4ef660_thiscall2(u32, u32) __asm__("ext_4ef660");
extern "C" u32 THISCALL ext_636020_thiscall9(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_636020");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_639d00_thiscall2(u32, u32) __asm__("ext_639d00");
extern "C" u32 THISCALL ext_63cc50_thiscall3(u32, u32, u32) __asm__("ext_63cc50");
extern "C" u32 THISCALL ext_63ead0_thiscall2(u32, u32) __asm__("ext_63ead0");
extern "C" u32 THISCALL ext_6500b0_thiscall1(u32) __asm__("ext_6500b0");
extern "C" u32 THISCALL ext_651180_thiscall1(u32) __asm__("ext_651180");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_428420_cdecl4(...) __asm__("ext_428420");
extern "C" u32 ext_42abee_cdecl3(...) __asm__("ext_42abee");
extern "C" u32 STDCALL ext_633648_stdcall2(u32, u32) __asm__("ext_633648");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }
static inline long double LDF(u32 a) { float f; __builtin_memcpy(&f, (void *)a, 4); return f; }
static inline long double LDD(u32 a) { double d; __builtin_memcpy(&d, (void *)a, 8); return d; }
static inline long double LDI16(u32 a) { short v; __builtin_memcpy(&v, (void *)a, 2); return v; }
static inline long double LDI32(u32 a) { int v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline long double LDI64(u32 a) { long long v; __builtin_memcpy(&v, (void *)a, 8); return v; }
static inline void STF(u32 a, long double x) { float f = (float)x; __builtin_memcpy((void *)a, &f, 4); }
static inline void STD(u32 a, long double x) { double d = (double)x; __builtin_memcpy((void *)a, &d, 8); }
static inline void STI16(u32 a, long double x) { short v; __asm__ volatile("fistps %0" : "=m"(v) : "t"(x) : "st"); __builtin_memcpy((void *)a, &v, 2); }
static inline void STI32(u32 a, long double x) { int v; __asm__ volatile("fistpl %0" : "=m"(v) : "t"(x) : "st"); __builtin_memcpy((void *)a, &v, 4); }
static inline void STI64(u32 a, long double x) { long long v; __asm__ volatile("fistpll %0" : "=m"(v) : "t"(x) : "st"); __builtin_memcpy((void *)a, &v, 8); }
static inline void FSQRT(long double &x) { __asm__("fsqrt" : "+t"(x)); }
static inline void FSIN(long double &x) { __asm__("fsin" : "+t"(x)); }
static inline void FCOS(long double &x) { __asm__("fcos" : "+t"(x)); }
static inline void FRNDINT(long double &x) { __asm__("frndint" : "+t"(x)); }
static inline void F2XM1(long double &x) { __asm__("f2xm1" : "+t"(x)); }
static inline void FABS(long double &x) { __asm__("fabs" : "+t"(x)); }
static inline u32 FCMPSW(long double a, long double b) { return (a != a || b != b) ? 0x4500u : (a < b ? 0x100u : (a == b ? 0x4000u : 0u)); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_537400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FS[12]; u32 FSW = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_537400
  ebx = ecx;  // @1_537400
  FL[2] = (esi & esi);  // @2_537400
  if (FL[2] != 0) goto L537416;  // @3_537400
  L53740e:;
  eax = 0;  // @5_537400
  FL[3] = eax;  // @6_537400
  return eax;  // @7_537400
  L537416:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @9_537400
  FL[2] = (edx & edx);  // @10_537400
  if (FL[2] == 0) goto L53740e;  // @11_537400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @12_537400
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @13_537400
  if (FL[0] != FL[1]) goto L53742f;  // @14_537400
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @15_537400
  if (FL[0] == FL[1]) goto L53740e;  // @16_537400
  L53742f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi), sizeof v); (u32)v; });  // @18_537400
  edi = (u32)(edx + esi);  // @19_537400
  ecx = (u32)(eax - 1);  // @20_537400
  FL[0] = ecx; FL[1] = (u32)(15);  // @21_537400
  if (FL[0] > FL[1]) goto L5374cf;  // @22_537400
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5469420), sizeof v); (u32)v; });  // @23_537400
  switch (ecx) {  // @24_537400
  case 0: goto L53745c;  // @25_537400
  case 1: goto L537465;  // @26_537400
  case 2: goto L5374cf;  // @27_537400
  case 3: goto L537450;  // @28_537400
  case 4: goto L5374cf;  // @29_537400
  default: __builtin_trap(); }  // @30_537400
  L537450:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @32_537400
  edi = (edi + edx);  // @33_537400
  FL[3] = edi;  // @34_537400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_537400
  L537457:;
  FL[0] = eax; FL[1] = (u32)(2);  // @37_537400
  if (FL[0] != FL[1]) goto L537470;  // @38_537400
  L53745c:;
  eax = edi;  // @40_537400
  return eax;  // @41_537400
  L537465:;
  FL[0] = eax; FL[1] = (u32)(2);  // @43_537400
  if (FL[0] == FL[1]) goto L53745c;  // @44_537400
  L537470:;
  FL[0] = eax; FL[1] = (u32)(1);  // @46_537400
  if (FL[0] == FL[1]) goto L53745c;  // @47_537400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_537400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @49_537400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_537400
  esi = (esi + edx);  // @51_537400
  FL[3] = esi;  // @52_537400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @53_537400
  FS[0] = ((long double(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6954540), (u32)(1168));  // @54_537400
  ecx = edx = 0;  // @55_537400
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @56_537400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @57_537400
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @58_537400
  X0[0] = F2U((float)(s32)X0[0]);  // @59_537400
  X0[1] = F2U((float)(s32)X0[1]);  // @60_537400
  X0[2] = F2U((float)(s32)X0[2]);  // @61_537400
  X0[3] = F2U((float)(s32)X0[3]);  // @62_537400
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @63_537400
  FS[0] = (FS[0] * LDF((u32)(EBP + 8)));  // @64_537400
  FS[0] = (FS[0] - LDF((u32)(6806016)));  // @65_537400
  STF((u32)(EBP + 8), FS[0]);  // @66_537400
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @67_537400
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax*4), sizeof v); (u32)v; });  // @68_537400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx), sizeof v); (u32)v; });  // @69_537400
  edi = (edi + edx);  // @70_537400
  FL[3] = edi;  // @71_537400
  FL[0] = eax; FL[1] = (u32)(3);  // @72_537400
  if (FL[0] != FL[1]) goto L537457;  // @73_537400
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @74_537400
  if (FL[0] != FL[1]) goto L537457;  // @75_537400
  L5374cf:;
  eax = 0;  // @77_537400
  FL[3] = eax;  // @78_537400
  return eax;  // @79_537400
}
PCREG(537400, lifted_537400);

extern "C" u32 THISCALL lifted_428990(u32 ecx_in) {
  SEH_ENTER(0x6647c7);  // @h_428990
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @0_428990
  edi = 0;  // @1_428990
  FL[3] = edi;  // @2_428990
  L4289c0:;
  eax = (u32)(EBP - 96);  // @4_428990
  X0[0] = 0;  // @5_428990
  X0[1] = 0;  // @6_428990
  X0[2] = 0;  // @7_428990
  X0[3] = 0;  // @8_428990
  PV[0] = (u32)(eax);  // @9_428990
  PV[1] = (u32)(edi);  // @10_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 0), &X0[0], 4);  // @11_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 4), &X0[1], 4);  // @12_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 8), &X0[2], 4);  // @13_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 12), &X0[3], 4);  // @14_428990
  eax = ext_633648_stdcall2(PV[1], PV[0]);  // @15_428990
    // @16_428990
  FL[2] = (eax & eax);  // @17_428990
  if (FL[2] != 0) goto L428a89;  // @18_428990
  eax = ext_41e290_cdecl1((u32)(118));  // @19_428990
  ecx = edx = 0;  // @20_428990
  esi = eax;  // @21_428990
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @22_428990
  reg.state = (s32)((u32)(0));  // @23_428990
  FL[2] = (esi & esi);  // @24_428990
  if (FL[2] == 0) goto L428a77;  // @25_428990
  ecx = esi;  // @26_428990
  eax = ext_435a10_thiscall1(ecx);  // @27_428990
  ecx = edx = 0;  // @28_428990
  eax = (u32)(EBP - 80);  // @29_428990
  reg.state = (s32)((u32)(1));  // @30_428990
  PV[2] = (u32)(eax);  // @31_428990
  { u32 v = (u32)((u32)(6786640)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @32_428990
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @33_428990
  eax = ext_634d10_cdecl3(PV[2], (u32)(0), (u32)(64));  // @34_428990
    // @35_428990
  PV[3] = (u32)(edi);  // @36_428990
  eax = (u32)(EBP - 80);  // @37_428990
  PV[4] = (u32)(eax);  // @38_428990
  eax = ext_428420_cdecl4(PV[4], (u32)(-1), (u32)(6788384), PV[3]);  // @39_428990
  ecx = edx = 0;  // @40_428990
  eax = (u32)(EBP - 80);  // @41_428990
  ecx = esi;  // @42_428990
  PV[5] = (u32)(eax);  // @43_428990
  eax = ext_4361a0_thiscall2(ecx, PV[5]);  // @44_428990
  ecx = edx = 0;  // @45_428990
  X0[0] = 0;  // @46_428990
  X0[1] = 0;  // @47_428990
  X0[2] = 0;  // @48_428990
  X0[3] = 0;  // @49_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @50_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @51_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @52_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @53_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 0), &X0[0], 4);  // @54_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 4), &X0[1], 4);  // @55_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 8), &X0[2], 4);  // @56_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 12), &X0[3], 4);  // @57_428990
  PV[6] = (u32)(ecx);  // @58_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 0), &X0[0], 4);  // @59_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 4), &X0[1], 4);  // @60_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 8), &X0[2], 4);  // @61_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 12), &X0[3], 4);  // @62_428990
  ecx = esi;  // @63_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 0), &X0[0], 4);  // @64_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 4), &X0[1], 4);  // @65_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 8), &X0[2], 4);  // @66_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 12), &X0[3], 4);  // @67_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 0), &X0[0], 4);  // @68_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 4), &X0[1], 4);  // @69_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 8), &X0[2], 4);  // @70_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 12), &X0[3], 4);  // @71_428990
  eax = ext_436170_thiscall2(ecx, (u32)(1050253722));  // @72_428990
    // @73_428990
  goto L428a79;  // @74_428990
  L428a77:;
  esi = 0;  // @76_428990
  FL[3] = esi;  // @77_428990
  L428a79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @79_428990
  PV[7] = (u32)(esi);  // @80_428990
  reg.state = (s32)((u32)(4294967295));  // @81_428990
  eax = ext_435d30_thiscall2(ecx, PV[7]);  // @82_428990
  edx = 0;  // @83_428990
  L428a89:;
  edi = (edi + 1);  // @85_428990
  FL[3] = edi;  // @86_428990
  FL[0] = edi; FL[1] = (u32)(4);  // @87_428990
  if (FL[0] < FL[1]) goto L4289c0;  // @88_428990
  SEH_LEAVE();  // @89_428990
  ext_633654(G(u32, 0x6f5630));  // @90_428990
  return eax;  // @91_428990
}
PCREG(428990, lifted_428990);

extern "C" u32 THISCALL lifted_4f6f10(u32 ecx_in) {
  SEH_ENTER(0x6699e7);  // @h_4f6f10
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  ebx = ecx;  // @0_4f6f10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 147), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4f6f10
  if (FL[0] != FL[1]) goto L4f704f;  // @2_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_4f6f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @4_4f6f10
  ecx = edx = 0;  // @5_4f6f10
  ecx = (u32)(EBP - 272);  // @6_4f6f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @7_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6925952));  // @8_4f6f10
  ecx = edx = 0;  // @9_4f6f10
  ecx = (u32)(EBP - 144);  // @10_4f6f10
  reg.state = (s32)((u32)(0));  // @11_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6838840));  // @12_4f6f10
  ecx = edx = 0;  // @13_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @14_4f6f10
  ecx = (u32)(6801640);  // @15_4f6f10
  FL[2] = (eax & eax);  // @16_4f6f10
  reg.state = (s32)((u32)(1));  // @17_4f6f10
  if (FL[2] != 0) ecx = eax;  // @18_4f6f10
  PV[0] = (u32)(ecx);  // @19_4f6f10
  ecx = (u32)(EBP - 656);  // @20_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @21_4f6f10
  ecx = edx = 0;  // @22_4f6f10
  ecx = (u32)(EBP - 144);  // @23_4f6f10
  reg.state = (s32)((u32)(2));  // @24_4f6f10
  PV[1] = (u32)(ecx);  // @25_4f6f10
  ecx = (u32)(EBP - 528);  // @26_4f6f10
  PV[2] = (u32)(ecx);  // @27_4f6f10
  ecx = eax;  // @28_4f6f10
  eax = ext_4cc1e0_thiscall3(ecx, PV[2], PV[1]);  // @29_4f6f10
  ecx = edx = 0;  // @30_4f6f10
  ecx = (u32)(EBP - 272);  // @31_4f6f10
  reg.state = (s32)((u32)(3));  // @32_4f6f10
  PV[3] = (u32)(ecx);  // @33_4f6f10
  ecx = (u32)(EBP - 400);  // @34_4f6f10
  PV[4] = (u32)(ecx);  // @35_4f6f10
  ecx = eax;  // @36_4f6f10
  eax = ext_4cc1e0_thiscall3(ecx, PV[4], PV[3]);  // @37_4f6f10
  ecx = edx = 0;  // @38_4f6f10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_4f6f10
  ecx = eax;  // @40_4f6f10
  reg.state = (s32)((u32)(4));  // @41_4f6f10
  eax = ext_4cc1d0_thiscall1(ecx);  // @42_4f6f10
    // @43_4f6f10
  PV[5] = (u32)(eax);  // @44_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4f6f10
  ecx = edi;  // @46_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @47_4f6f10
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @48_4f6f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 440)))(ecx, PV[6], (u32)(0), PV[5], (u32)(0), (u32)(0));  // @49_4f6f10
  ecx = edx = 0;  // @50_4f6f10
  ecx = (u32)(EBP - 400);  // @51_4f6f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 147), &v, sizeof v); }  // @52_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @53_4f6f10
  ecx = edx = 0;  // @54_4f6f10
  ecx = (u32)(EBP - 528);  // @55_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @56_4f6f10
  ecx = edx = 0;  // @57_4f6f10
  ecx = (u32)(EBP - 656);  // @58_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @59_4f6f10
  ecx = edx = 0;  // @60_4f6f10
  ecx = (u32)(EBP - 144);  // @61_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @62_4f6f10
  ecx = edx = 0;  // @63_4f6f10
  ecx = (u32)(EBP - 272);  // @64_4f6f10
  reg.state = (s32)((u32)(4294967295));  // @65_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @66_4f6f10
  ecx = edx = 0;  // @67_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_4f6f10
  ecx = ebx;  // @69_4f6f10
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 147), sizeof v); (u32)v; });  // @70_4f6f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 876)))(ecx, PV[7]);  // @71_4f6f10
  ecx = edx = 0;  // @72_4f6f10
  L4f704f:;
  SEH_LEAVE();  // @74_4f6f10
  ext_633654(G(u32, 0x6f5630));  // @75_4f6f10
  return eax;  // @76_4f6f10
}
PCREG(4f6f10, lifted_4f6f10);

extern "C" u32 lifted_4260a0(u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x664592);  // @h_4260a0
  u8 F[0x1160] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x1060);
  __builtin_memcpy(F + 0x1060 + 8, &a0, 4); __builtin_memcpy(F + 0x1060 + 12, &a1, 4); __builtin_memcpy(F + 0x1060 + 16, &a2, 4); __builtin_memcpy(F + 0x1060 + 20, &a3, 4);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4260a0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4260a0
  if (FL[0] == FL[1]) goto L4261a3;  // @2_4260a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_4260a0
  if (FL[0] != FL[1]) goto L426118;  // @4_4260a0
  eax = ext_41e290_cdecl1((u32)(28));  // @5_4260a0
  ecx = edx = 0;  // @6_4260a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4116), &v, sizeof v); }  // @7_4260a0
  reg.state = (s32)((u32)(0));  // @8_4260a0
  FL[2] = (eax & eax);  // @9_4260a0
  if (FL[2] == 0) goto L42610c;  // @10_4260a0
  ecx = eax;  // @11_4260a0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @12_4260a0
  ecx = edx = 0;  // @13_4260a0
  goto L42610e;  // @14_4260a0
  L42610c:;
  eax = 0;  // @16_4260a0
  FL[3] = eax;  // @17_4260a0
  L42610e:;
  reg.state = (s32)((u32)(4294967295));  // @19_4260a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @20_4260a0
  L426118:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @22_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_4260a0
  ecx = (u32)(EBP - 4112);  // @24_4260a0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @25_4260a0
  PV[2] = (u32)(ecx);  // @26_4260a0
  PV[3] = (u32)(edi);  // @27_4260a0
  eax = ((u32(*)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(PV[3], PV[2], (u32)(6784796), PV[1], PV[0]);  // @28_4260a0
  ecx = edx = 0;  // @29_4260a0
  ecx = (u32)(EBP - 4112);  // @30_4260a0
  edx = (u32)(ecx + 1);  // @31_4260a0
  L426140:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @33_4260a0
  ecx = (ecx + 1);  // @34_4260a0
  FL[3] = ecx;  // @35_4260a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @36_4260a0
  if (FL[2] != 0) goto L426140;  // @37_4260a0
  eax = (u32)(EBP + 16);  // @38_4260a0
  ecx = (ecx - edx);  // @39_4260a0
  FL[3] = ecx;  // @40_4260a0
  PV[4] = (u32)(eax);  // @41_4260a0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @42_4260a0
  esi = (u32)(EBP - 4112);  // @43_4260a0
  esi = (esi + ecx);  // @44_4260a0
  FL[3] = esi;  // @45_4260a0
  PV[6] = (u32)(esi);  // @46_4260a0
  eax = ext_42abee_cdecl3(PV[6], PV[5], PV[4]);  // @47_4260a0
  ecx = edx = 0;  // @48_4260a0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(40);  // @49_4260a0
  if (FL[0] != FL[1]) goto L42617d;  // @50_4260a0
  ecx = (u32)(EBP - 4112);  // @51_4260a0
  ecx = (ecx - esi);  // @52_4260a0
  FL[3] = ecx;  // @53_4260a0
  L426170:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @55_4260a0
  esi = (u32)(esi + 1);  // @56_4260a0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @57_4260a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @58_4260a0
  if (FL[2] != 0) goto L426170;  // @59_4260a0
  L42617d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @61_4260a0
  edx = (u32)(EBP - 4112);  // @62_4260a0
  PV[7] = (u32)(edx);  // @63_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4260a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[7]);  // @65_4260a0
  ecx = edx = 0;  // @66_4260a0
  FL[2] = (eax & eax);  // @67_4260a0
  if (FL[2] == 0) goto L4261a3;  // @68_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_4260a0
  ecx = (u32)(EBP - 4112);  // @70_4260a0
  PV[8] = (u32)(ecx);  // @71_4260a0
  PV[9] = (u32)(edi);  // @72_4260a0
  eax = ((u32( *)(u32, u32))(*(u32 *)(eax + 44)))(PV[9], PV[8]);  // @73_4260a0
  ecx = edx = 0;  // @74_4260a0
  L4261a3:;
  SEH_LEAVE();  // @76_4260a0
  ext_633654(G(u32, 0x6f5630));  // @77_4260a0
  return eax;  // @78_4260a0
}
PCREG(4260a0, lifted_4260a0);

extern "C" u32 THISCALL lifted_63d910(u32 ecx_in) {
  SEH_ENTER(0x66e878);  // @h_63d910
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  ebx = ecx;  // @0_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @2_63d910
  eax = (eax - (u32)(8));  // @3_63d910
  FL[3] = eax;  // @4_63d910
  PV[0] = (u32)(eax);  // @5_63d910
  eax = ext_63cc50_thiscall3(ecx, (u32)(400000), PV[0]);  // @6_63d910
  ecx = edx = 0;  // @7_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @9_63d910
  eax = ext_651180_thiscall1(ecx);  // @10_63d910
  ecx = edx = 0;  // @11_63d910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @12_63d910
  if (FL[2] == 0) goto L63da34;  // @13_63d910
  esi = 0;  // @14_63d910
  FL[3] = esi;  // @15_63d910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }); FL[1] = esi;  // @16_63d910
  if (FL[0] == FL[1]) goto L63d993;  // @17_63d910
  edi = (u32)(ebx + 240);  // @18_63d910
  L63d980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_63d910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @22_63d910
  ecx = edx = 0;  // @23_63d910
  esi = (esi + 1);  // @24_63d910
  FL[3] = esi;  // @25_63d910
  edi = (u32)(edi + 4);  // @26_63d910
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; });  // @27_63d910
  if (FL[0] != FL[1]) goto L63d980;  // @28_63d910
  L63d993:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @31_63d910
  eax = ext_6500b0_thiscall1(ecx);  // @32_63d910
  ecx = edx = 0;  // @33_63d910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @34_63d910
  if (FL[2] == 0) goto L63da34;  // @35_63d910
  ecx = (u32)(EBP - 52);  // @36_63d910
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(1));  // @37_63d910
  ecx = edx = 0;  // @38_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @39_63d910
  eax = (u32)(EBP - 52);  // @40_63d910
  PV[1] = (u32)(eax);  // @41_63d910
  reg.state = (s32)((u32)(0));  // @42_63d910
  eax = ext_63ead0_thiscall2(ecx, PV[1]);  // @43_63d910
  ecx = edx = 0;  // @44_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @45_63d910
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @46_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_63d910
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; });  // @48_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[3], PV[2], (u32)(12611839));  // @49_63d910
  ecx = edx = 0;  // @50_63d910
  eax = (u32)(EBP - 24);  // @51_63d910
  PV[4] = (u32)(eax);  // @52_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @53_63d910
  ecx = (u32)(EBP - 52);  // @54_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @55_63d910
  ecx = edx = 0;  // @56_63d910
  eax = (u32)(EBP - 24);  // @57_63d910
  PV[5] = (u32)(eax);  // @58_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @59_63d910
  ecx = (u32)(EBP - 52);  // @60_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @61_63d910
  ecx = edx = 0;  // @62_63d910
  FL[2] = (eax & eax);  // @63_63d910
  if (FL[2] == 0) goto L63da2c;  // @64_63d910
  L63da02:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @66_63d910
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @67_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @68_63d910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_63d910
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }));  // @70_63d910
  FL[3] = eax;  // @71_63d910
  PV[7] = (u32)(eax);  // @72_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[7], PV[6], (u32)(8405232));  // @73_63d910
  ecx = edx = 0;  // @74_63d910
  eax = (u32)(EBP - 24);  // @75_63d910
  PV[8] = (u32)(eax);  // @76_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @77_63d910
  ecx = (u32)(EBP - 52);  // @78_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @79_63d910
  ecx = edx = 0;  // @80_63d910
  FL[2] = (eax & eax);  // @81_63d910
  if (FL[2] != 0) goto L63da02;  // @82_63d910
  L63da2c:;
  ecx = (u32)(EBP - 52);  // @84_63d910
  eax = ext_4ccfe0_thiscall1(ecx);  // @85_63d910
  ecx = edx = 0;  // @86_63d910
  L63da34:;
  SEH_LEAVE();  // @88_63d910
  return eax;  // @89_63d910
}
PCREG(63d910, lifted_63d910);

extern "C" u32 THISCALL lifted_4f5170(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66997b);  // @h_4f5170
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4f5170
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @1_4f5170
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4f5170
  PV[0] = (u32)(esi);  // @3_4f5170
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @4_4f5170
  eax = ext_4ef660_thiscall2(ecx, PV[0]);  // @5_4f5170
  ecx = edx = 0;  // @6_4f5170
  ecx = (u32)(EBP - 188);  // @7_4f5170
  eax = ext_4ccba0_thiscall1(ecx);  // @8_4f5170
    // @9_4f5170
  eax = (u32)(EBP - 188);  // @10_4f5170
  reg.state = (s32)((u32)(0));  // @11_4f5170
  PV[1] = (u32)(eax);  // @12_4f5170
  ecx = esi;  // @13_4f5170
  eax = ext_4e0fd0_thiscall2(ecx, PV[1]);  // @14_4f5170
  ecx = edx = 0;  // @15_4f5170
  eax = (u32)(EBP - 208);  // @16_4f5170
  ebx = 0;  // @17_4f5170
  FL[3] = ebx;  // @18_4f5170
  PV[2] = (u32)(eax);  // @19_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @20_4f5170
  ecx = (u32)(EBP - 188);  // @21_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @22_4f5170
  ecx = edx = 0;  // @23_4f5170
  eax = (u32)(EBP - 208);  // @24_4f5170
  PV[3] = (u32)(eax);  // @25_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @26_4f5170
  ecx = (u32)(EBP - 188);  // @27_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @28_4f5170
  ecx = edx = 0;  // @29_4f5170
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }); FL[1] = ebx;  // @30_4f5170
  if (FL[0] == FL[1]) goto L4f523b;  // @31_4f5170
  esi = (u32)(edi + 147);  // @32_4f5170
  L4f5211:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @34_4f5170
  ecx = (u32)(EBP - 188);  // @35_4f5170
  eax = (u32)(EBP - 208);  // @36_4f5170
  ebx = (ebx + 1);  // @37_4f5170
  FL[3] = ebx;  // @38_4f5170
  PV[4] = (u32)(eax);  // @39_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @40_4f5170
  esi = (u32)(esi + 4);  // @41_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @42_4f5170
  ecx = edx = 0;  // @43_4f5170
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_4f5170
  if (FL[0] != FL[1]) goto L4f5211;  // @45_4f5170
  FL[0] = ebx; FL[1] = (u32)(9);  // @46_4f5170
  if ((s32)FL[0] >= (s32)FL[1]) goto L4f5262;  // @47_4f5170
  L4f523b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @49_4f5170
  edi = (u32)(edi + ebx*4);  // @50_4f5170
  esi = (esi + (u32)(143));  // @51_4f5170
  FL[3] = esi;  // @52_4f5170
  edi = (edi + (u32)(147));  // @53_4f5170
  FL[3] = edi;  // @54_4f5170
  ecx = (u32)(9);  // @55_4f5170
  ecx = (ecx - ebx);  // @56_4f5170
  FL[3] = ecx;  // @57_4f5170
  esi = (u32)(esi + ebx*4);  // @58_4f5170
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @59_4f5170
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @60_4f5170
  L4f5262:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @62_4f5170
  ecx = ebx;  // @63_4f5170
  eax = ext_4e1600_thiscall1(ecx);  // @64_4f5170
    // @65_4f5170
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @66_4f5170
  if (FL[0] != FL[1]) goto L4f5295;  // @67_4f5170
  eax = (u32)(edi + 187);  // @68_4f5170
  ecx = ebx;  // @69_4f5170
  PV[5] = (u32)(eax);  // @70_4f5170
  eax = ext_4e11e0_thiscall3(ecx, PV[5], (u32)(1));  // @71_4f5170
  ecx = edx = 0;  // @72_4f5170
  eax = (u32)(edi + 191);  // @73_4f5170
  ecx = ebx;  // @74_4f5170
  PV[6] = (u32)(eax);  // @75_4f5170
  eax = ext_4e11e0_thiscall3(ecx, PV[6], (u32)(1));  // @76_4f5170
  ecx = edx = 0;  // @77_4f5170
  goto L4f52a9;  // @78_4f5170
  L4f5295:;
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(edi + 187), &v, sizeof v); }  // @80_4f5170
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(edi + 191), &v, sizeof v); }  // @81_4f5170
  L4f52a9:;
  ecx = ebx;  // @83_4f5170
  eax = ext_4e1b30_thiscall1(ecx);  // @84_4f5170
  ecx = edx = 0;  // @85_4f5170
  ecx = (u32)(EBP - 188);  // @86_4f5170
  eax = ext_4ccf60_thiscall1(ecx);  // @87_4f5170
  ecx = edx = 0;  // @88_4f5170
  SEH_LEAVE();  // @89_4f5170
  ext_633654(G(u32, 0x6f5630));  // @90_4f5170
  return eax;  // @91_4f5170
}
PCREG(4f5170, lifted_4f5170);

extern "C" u32 THISCALL lifted_607a20(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e06b);  // @h_607a20
  u8 F[0x40190] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x40090);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x40090 + 8, &a0, 4);
  __builtin_memcpy(F + 0x40090 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @0_607a20
  ecx = esi;  // @1_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 262220), &v, sizeof v); }  // @3_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 262216), &v, sizeof v); }  // @5_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_607a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @7_607a20
  ecx = edx = 0;  // @8_607a20
  edi = eax;  // @9_607a20
  { u32 v = (u32)((u32)(4278255360)); __builtin_memcpy((void *)(u32)(EBP - 262212), &v, sizeof v); }  // @10_607a20
  ebx = 0;  // @11_607a20
  FL[3] = ebx;  // @12_607a20
  edx = (u32)(EBP - 262160);  // @13_607a20
  L607a82:;
  ecx = 0;  // @15_607a20
  FL[3] = ecx;  // @16_607a20
  L607a84:;
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @18_607a20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) ^ (ecx & 0xff))) & 0xff);  // @19_607a20
  FL[3] = (eax & 0xff);  // @20_607a20
  FL[2] = ((eax & 0xff) & (u32)(1));  // @21_607a20
  eax = (u32)(4294901760);  // @22_607a20
  if (FL[2] != 0) eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262212), sizeof v); (u32)v; });  // @23_607a20
  ecx = (ecx + 1);  // @24_607a20
  FL[3] = ecx;  // @25_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @26_607a20
  edx = (edx + (u32)(4));  // @27_607a20
  FL[3] = edx;  // @28_607a20
  FL[0] = ecx; FL[1] = (u32)(256);  // @29_607a20
  if (FL[0] < FL[1]) goto L607a84;  // @30_607a20
  ebx = (ebx + 1);  // @31_607a20
  FL[3] = ebx;  // @32_607a20
  FL[0] = ebx; FL[1] = (u32)(256);  // @33_607a20
  if (FL[0] < FL[1]) goto L607a82;  // @34_607a20
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262216), sizeof v); (u32)v; });  // @35_607a20
  eax = (u32)(EBP - 262160);  // @36_607a20
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262220), sizeof v); (u32)v; });  // @37_607a20
  ecx = (u32)(EBP - 262208);  // @38_607a20
  PV[2] = (u32)(eax);  // @39_607a20
  eax = ext_636020_thiscall9(ecx, PV[2], PV[1], PV[0], (u32)(16711680), (u32)(65280), (u32)(255), (u32)(4278190080), (u32)(0));  // @40_607a20
  ecx = edx = 0;  // @41_607a20
  ecx = (u32)(EBP - 262208);  // @42_607a20
  reg.state = (s32)((u32)(0));  // @43_607a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 262180), &v, sizeof v); }  // @44_607a20
  eax = ext_639d00_thiscall2(ecx, (u32)(7053240));  // @45_607a20
  ecx = edx = 0;  // @46_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_607a20
  ecx = esi;  // @48_607a20
  PV[3] = (u32)(edi);  // @49_607a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[3], (u32)(0));  // @50_607a20
  ecx = edx = 0;  // @51_607a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_607a20
  ecx = esi;  // @53_607a20
  PV[4] = (u32)(eax);  // @54_607a20
  eax = (u32)(EBP - 262208);  // @55_607a20
  PV[5] = (u32)(eax);  // @56_607a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[5], PV[4]);  // @57_607a20
  ecx = edx = 0;  // @58_607a20
  ecx = (u32)(EBP - 262208);  // @59_607a20
  eax = ext_6363a0_thiscall1(ecx);  // @60_607a20
  ecx = edx = 0;  // @61_607a20
  eax = edi;  // @62_607a20
  SEH_LEAVE();  // @63_607a20
  ext_633654(G(u32, 0x6f5630));  // @64_607a20
  return eax;  // @65_607a20
}
PCREG(607a20, lifted_607a20);

