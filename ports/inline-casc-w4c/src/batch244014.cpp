// batch244014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_63ee70_thiscall2(u32, u32) __asm__("ext_63ee70");
extern "C" u32 THISCALL ext_63faa0_thiscall2(u32, u32) __asm__("ext_63faa0");
extern "C" u32 THISCALL ext_658fd0_thiscall2(u32, u32) __asm__("ext_658fd0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_657490(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_657490
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_657490
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[0]);  // @2_657490
  ecx = edx = 0;  // @3_657490
  edi = eax;  // @4_657490
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5_657490
  if (FL[0] == FL[1]) goto L6574ac;  // @6_657490
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @7_657490
  FL[3] = (eax & 0xff);  // @8_657490
  return eax;  // @9_657490
  L6574ac:;
  eax = 0;  // @11_657490
  FL[3] = eax;  // @12_657490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @13_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_657490
  esi = 0;  // @15_657490
  FL[3] = esi;  // @16_657490
  ebx = 0;  // @17_657490
  FL[3] = ebx;  // @18_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @19_657490
  PV[1] = (u32)(esi);  // @20_657490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @21_657490
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @22_657490
  PV[2] = (u32)(eax);  // @23_657490
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_657490
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[2], PV[1]);  // @25_657490
  ecx = edx = 0;  // @26_657490
  FL[2] = (eax & eax);  // @27_657490
  if (FL[2] == 0) goto L6574dd;  // @28_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @29_657490
  FL[2] = (eax & eax);  // @30_657490
  if (FL[2] == 0) goto L6574dd;  // @31_657490
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_657490
  L6574dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_657490
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @35_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @36_657490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @37_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_657490
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[3], (u32)(0));  // @39_657490
  ecx = edx = 0;  // @40_657490
  FL[2] = (eax & eax);  // @41_657490
  if (FL[2] == 0) goto L657505;  // @42_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @43_657490
  FL[2] = (eax & eax);  // @44_657490
  if (FL[2] == 0) goto L657505;  // @45_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_657490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @47_657490
  L657505:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_657490
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; });  // @50_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @51_657490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @52_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_657490
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[4], (u32)(0));  // @54_657490
  ecx = edx = 0;  // @55_657490
  FL[2] = (eax & eax);  // @56_657490
  if (FL[2] == 0) goto L65752a;  // @57_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @58_657490
  FL[2] = (eax & eax);  // @59_657490
  if (FL[2] == 0) goto L65752a;  // @60_657490
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @61_657490
  L65752a:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = esi;  // @63_657490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @64_657490
  if (FL[0] > FL[1]) esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @65_657490
  FL[0] = ebx; FL[1] = esi;  // @66_657490
  if (FL[0] > FL[1]) esi = ebx;  // @67_657490
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_657490
  FL[2] = (esi & esi);  // @69_657490
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @70_657490
  return eax;  // @71_657490
}
PCREG(657490, lifted_657490);

extern "C" u32 THISCALL lifted_537400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6954540), (u32)(1168));  // @54_537400
  ecx = edx = 0;  // @55_537400
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @56_537400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @57_537400
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @58_537400
  X0[0] = F2U((float)(s32)X0[0]);  // @59_537400
  X0[1] = F2U((float)(s32)X0[1]);  // @60_537400
  X0[2] = F2U((float)(s32)X0[2]);  // @61_537400
  X0[3] = F2U((float)(s32)X0[3]);  // @62_537400
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @63_537400
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(EBP + 8)) : "st");  // @64_537400
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(6806016)) : "st");  // @65_537400
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @66_537400
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

extern "C" u32 THISCALL lifted_537a90(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_537a90
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_537a90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; })) & 0xff);  // @1_537a90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_537a90
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @3_537a90
  if (FL[2] == 0) goto L537b81;  // @4_537a90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_537a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20901), sizeof v); (u32)v; });  // @6_537a90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @7_537a90
  FL[0] = edi; FL[1] = (u32)(-1);  // @8_537a90
  if (FL[0] != FL[1]) goto L537aec;  // @9_537a90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @10_537a90
  FL[3] = (eax & 0xff);  // @11_537a90
  goto L537b83;  // @12_537a90
  L537aec:;
  ecx = (u32)(EBP - 144);  // @14_537a90
  eax = ext_4cbeb0_thiscall1(ecx);  // @15_537a90
    // @16_537a90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @17_537a90
  edx = (u32)(EBP - 272);  // @18_537a90
  PV[0] = (u32)(ebx);  // @19_537a90
  PV[1] = (u32)(edx);  // @20_537a90
  reg.state = (s32)((u32)(0));  // @21_537a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_537a90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, PV[1], PV[0]);  // @23_537a90
  ecx = edx = 0;  // @24_537a90
  PV[2] = (u32)(eax);  // @25_537a90
  ecx = (u32)(EBP - 144);  // @26_537a90
  reg.state = (s32)((u32)(1));  // @27_537a90
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @28_537a90
  ecx = edx = 0;  // @29_537a90
  ecx = (u32)(EBP - 272);  // @30_537a90
  reg.state = (s32)((u32)(0));  // @31_537a90
  eax = ext_4cbec0_thiscall1(ecx);  // @32_537a90
  ecx = edx = 0;  // @33_537a90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @34_537a90
  ecx = (u32)(EBP - 144);  // @35_537a90
  { u32 v = (u32)((u32)(258)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @36_537a90
  { u32 v = (u32)((u32)(140)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @37_537a90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @38_537a90
  eax = ext_4cc1d0_thiscall1(ecx);  // @39_537a90
    // @40_537a90
  edx = (u32)(ebx + 12);  // @41_537a90
  edx = (edx - eax);  // @42_537a90
  FL[3] = edx;  // @43_537a90
  L537b60:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @45_537a90
  eax = (u32)(eax + 1);  // @46_537a90
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @47_537a90
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @48_537a90
  if (FL[2] != 0) goto L537b60;  // @49_537a90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @50_537a90
  ecx = (u32)(EBP - 144);  // @51_537a90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @52_537a90
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @53_537a90
  eax = ext_4cbec0_thiscall1(ecx);  // @54_537a90
  ecx = edx = 0;  // @55_537a90
  L537b81:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @57_537a90
  L537b83:;
  SEH_LEAVE();  // @59_537a90
  ext_633654(G(u32, 0x6f5630));  // @60_537a90
  return eax;  // @61_537a90
}
PCREG(537a90, lifted_537a90);

extern "C" u32 THISCALL lifted_63fb40(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63fb40
  ebx = ecx;  // @1_63fb40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @2_63fb40
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @3_63fb40
  if (FL[2] == 0) goto L63fbf8;  // @4_63fb40
  esi = eax;  // @5_63fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @6_63fb40
  edx = esi;  // @7_63fb40
  edx = (edx & (u32)(4095));  // @8_63fb40
  FL[3] = edx;  // @9_63fb40
  PV[0] = (u32)(esi);  // @10_63fb40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @11_63fb40
  eax = ext_63ee70_thiscall2(ecx, PV[0]);  // @12_63fb40
  ecx = edx = 0;  // @13_63fb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_63fb40
  ecx = 0;  // @15_63fb40
  FL[3] = ecx;  // @16_63fb40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(4294963199))); __builtin_memcpy((void *)(u32)(eax + 60), &v, sizeof v); }  // @17_63fb40
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @18_63fb40
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 90), &v, sizeof v); }  // @19_63fb40
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @20_63fb40
  eax = (eax - 1);  // @21_63fb40
  FL[3] = eax;  // @22_63fb40
  FL[0] = eax; FL[1] = (u32)(3);  // @23_63fb40
  if (FL[0] > FL[1]) goto L63fbe3;  // @24_63fb40
  switch (eax) {  // @25_63fb40
  case 0: goto L63fbce;  // @26_63fb40
  case 1: goto L63fbc4;  // @27_63fb40
  case 2: goto L63fb8f;  // @28_63fb40
  case 3: goto L63fbba;  // @29_63fb40
  default: __builtin_trap(); }  // @30_63fb40
  L63fb8f:;
  PV[1] = (u32)(edi);  // @32_63fb40
  ecx = ebx;  // @33_63fb40
  eax = ext_63faa0_thiscall2(ecx, PV[1]);  // @34_63fb40
  ecx = edx = 0;  // @35_63fb40
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; }) & (u32)(16));  // @36_63fb40
  if (FL[2] == 0) goto L63fbac;  // @37_63fb40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @38_63fb40
  if (FL[0] == FL[1]) goto L63fbac;  // @39_63fb40
  ecx = edi;  // @40_63fb40
  eax = ext_658fd0_thiscall2(ecx, (u32)(0));  // @41_63fb40
    // @42_63fb40
  L63fbac:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @44_63fb40
  return eax;  // @45_63fb40
  L63fbba:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @47_63fb40
  return eax;  // @48_63fb40
  L63fbc4:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @50_63fb40
  return eax;  // @51_63fb40
  L63fbce:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @53_63fb40
  ecx = ebx;  // @54_63fb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 96)))(ecx);  // @55_63fb40
  ecx = edx = 0;  // @56_63fb40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @57_63fb40
  return eax;  // @58_63fb40
  L63fbe3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @60_63fb40
  FL[2] = (eax & eax);  // @61_63fb40
  if (FL[2] == 0) goto L63fbf5;  // @62_63fb40
  eax = ((u32(STDCALL *)(void))(eax))();  // @63_63fb40
  ecx = edx = 0;  // @64_63fb40
  return eax;  // @65_63fb40
  L63fbf5:;
  __builtin_trap();  // @67_63fb40
  L63fbf8:;
  return eax;  // @69_63fb40
}
PCREG(63fb40, lifted_63fb40);

extern "C" u32 THISCALL lifted_4f6450(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d1b);  // @h_4f6450
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 151), sizeof v); (u32)v; });  // @1_4f6450
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @2_4f6450
  eax = (u32)(EBP + 8);  // @3_4f6450
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; });  // @4_4f6450
  PV[2] = (u32)(eax);  // @5_4f6450
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)0x676448))(PV[2], PV[1], PV[0], (u32)(20), (u32)(5215504));  // @6_4f6450
  ecx = edx = 0;  // @7_4f6450
  FL[2] = (eax & eax);  // @8_4f6450
  if (FL[2] != 0) goto L4f6533;  // @9_4f6450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4f6450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6924584), (u32)(66));  // @12_4f6450
  ecx = edx = 0;  // @13_4f6450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4f6450
  edi = eax;  // @15_4f6450
  eax = (u32)(EBP - 144);  // @16_4f6450
  ecx = ebx;  // @17_4f6450
  PV[3] = (u32)(eax);  // @18_4f6450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[3], (u32)(1));  // @19_4f6450
  ecx = edx = 0;  // @20_4f6450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_4f6450
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_4f6450
  PV[4] = (u32)(ecx);  // @23_4f6450
  PV[5] = (u32)(ecx);  // @24_4f6450
  ecx = eax;  // @25_4f6450
  reg.state = (s32)((u32)(0));  // @26_4f6450
  eax = ext_4cc1d0_thiscall1(ecx);  // @27_4f6450
    // @28_4f6450
  PV[6] = (u32)(eax);  // @29_4f6450
  PV[7] = (u32)(edi);  // @30_4f6450
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 48)))(PV[7], (u32)(6924624), PV[6], PV[5], PV[4]);  // @31_4f6450
  ecx = edx = 0;  // @32_4f6450
  ecx = (u32)(EBP - 144);  // @33_4f6450
  eax = ext_4cbec0_thiscall1(ecx);  // @34_4f6450
  ecx = edx = 0;  // @35_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 151), sizeof v); (u32)v; });  // @36_4f6450
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @37_4f6450
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @38_4f6450
  eax = (u32)(EBP + 8);  // @39_4f6450
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; });  // @40_4f6450
  PV[10] = (u32)(eax);  // @41_4f6450
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)0x676448))(PV[10], PV[9], PV[8], (u32)(20), (u32)(5215504));  // @42_4f6450
  ecx = edx = 0;  // @43_4f6450
  FL[2] = (eax & eax);  // @44_4f6450
  if (FL[2] != 0) goto L4f6533;  // @45_4f6450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 155), sizeof v); (u32)v; });  // @46_4f6450
  L4f6533:;
  SEH_LEAVE();  // @48_4f6450
  ext_633654(G(u32, 0x6f5630));  // @49_4f6450
  return eax;  // @50_4f6450
}
PCREG(4f6450, lifted_4f6450);

