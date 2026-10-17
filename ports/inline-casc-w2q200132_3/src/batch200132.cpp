// batch200132.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_65f690_fastcall3(u32, u32, u32) __asm__("ext_65f690");
extern "C" u32 THISCALL ext_5ae900_thiscall2(u32, u32) __asm__("ext_5ae900");
extern "C" u32 THISCALL ext_6604c0_thiscall4(u32, u32, u32, u32) __asm__("ext_6604c0");
extern "C" u32 THISCALL ext_6616f0_thiscall10(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_6616f0");
extern "C" u32 THISCALL ext_663680_thiscall1(u32) __asm__("ext_663680");
extern "C" u32 THISCALL ext_663b60_thiscall3(u32, u32, u32) __asm__("ext_663b60");
extern "C" u32 ext_633ed4_cdecl1(...) __asm__("ext_633ed4");
extern "C" u32 ext_633f0f_cdecl1(...) __asm__("ext_633f0f");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_6344f2_cdecl1(...) __asm__("ext_6344f2");
extern "C" u32 ext_634879_cdecl1(...) __asm__("ext_634879");
extern "C" u32 ext_634aae_cdecl1(...) __asm__("ext_634aae");
extern "C" u32 ext_634d46_cdecl3(...) __asm__("ext_634d46");
extern "C" u32 ext_634e8a_cdecl3(...) __asm__("ext_634e8a");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_634823(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ext_634e8a_cdecl3((u32)(0), (u32)(65536), (u32)(196608));  // @0_634823
  ecx = edx = 0;  // @1_634823
  if ((eax & eax) != 0) goto L63483c;  // @2_634823
  return eax;  // @3_634823
  L63483c:;
  eax = ext_634879_cdecl1((u32)(7));  // @5_634823
  ecx = edx = 0;  // @6_634823
}
PCREG(634823, lifted_634823);

extern "C" u32 lifted_633f0f(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ext_633ed4_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @0_633f0f
  ecx = edx = 0;  // @1_633f0f
  eax = (0u - eax);  // @2_633f0f
  eax = 0;  // @3_633f0f
  eax = (0u - eax);  // @4_633f0f
  eax = (eax - 1);  // @5_633f0f
  return eax;  // @6_633f0f
}
PCREG(633f0f, lifted_633f0f);

extern "C" u32 lifted_66ab18(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = 0;  // @0_66ab18
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_66ab18
  ecx = (u32)(52);  // @2_66ab18
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66ab18
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66ab18
  ebx = (0u - ebx);  // @5_66ab18
  ebx = (ebx | eax);  // @6_66ab18
  p0_ = ebx;  // @7_66ab18
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_66ab18
  p1_ = eax;  // @9_66ab18
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @10_66ab18
  ecx = edx = 0;  // @11_66ab18
  return eax;  // @12_66ab18
}
PCREG(66ab18, lifted_66ab18);

extern "C" u32 lifted_66ab68(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = 0;  // @0_66ab68
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @1_66ab68
  ecx = (u32)(52);  // @2_66ab68
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66ab68
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66ab68
  ebx = (0u - ebx);  // @5_66ab68
  ebx = (ebx | eax);  // @6_66ab68
  p0_ = ebx;  // @7_66ab68
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @8_66ab68
  p1_ = eax;  // @9_66ab68
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @10_66ab68
  ecx = edx = 0;  // @11_66ab68
  return eax;  // @12_66ab68
}
PCREG(66ab68, lifted_66ab68);

extern "C" u32 lifted_665950(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = 0;  // @0_665950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @1_665950
  ecx = (u32)(10);  // @2_665950
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_665950
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_665950
  ebx = (0u - ebx);  // @5_665950
  ebx = (ebx | eax);  // @6_665950
  eax = 0;  // @7_665950
  ebx = (ebx + (u32)(4));  // @8_665950
  eax = (eax & 0xffffff00u) | (((u32)(0 && ebx)) & 0xff);  // @9_665950
  eax = (0u - eax);  // @10_665950
  eax = (eax | ebx);  // @11_665950
  p0_ = eax;  // @12_665950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @13_665950
  p1_ = eax;  // @14_665950
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @15_665950
  ecx = edx = 0;  // @16_665950
  return eax;  // @17_665950
}
PCREG(665950, lifted_665950);

extern "C" u32 lifted_66d790(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = 0;  // @0_66d790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @1_66d790
  ecx = (u32)(28);  // @2_66d790
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66d790
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66d790
  ebx = (0u - ebx);  // @5_66d790
  ebx = (ebx | eax);  // @6_66d790
  eax = 0;  // @7_66d790
  ebx = (ebx + (u32)(4));  // @8_66d790
  eax = (eax & 0xffffff00u) | (((u32)(0 && ebx)) & 0xff);  // @9_66d790
  eax = (0u - eax);  // @10_66d790
  eax = (eax | ebx);  // @11_66d790
  p0_ = eax;  // @12_66d790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @13_66d790
  p1_ = eax;  // @14_66d790
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @15_66d790
  ecx = edx = 0;  // @16_66d790
  return eax;  // @17_66d790
}
PCREG(66d790, lifted_66d790);

extern "C" u32 lifted_633cbc(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_633cbc
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @1_633cbc
  ecx = (ecx + eax);  // @2_633cbc
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @3_633cbc
  edx = (u32)(ecx + 24);  // @4_633cbc
  edx = (edx + eax);  // @5_633cbc
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @6_633cbc
  esi = (u32)((s32)eax * (s32)(u32)(40));  // @7_633cbc
  esi = (esi + edx);  // @8_633cbc
  if (edx == esi) goto L633cf7;  // @9_633cbc
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @10_633cbc
  L633ce1:;
  if (ecx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; })) goto L633cf0;  // @12_633cbc
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @13_633cbc
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; }));  // @14_633cbc
  if (ecx < eax) goto L633cfc;  // @15_633cbc
  L633cf0:;
  edx = (edx + (u32)(40));  // @17_633cbc
  if (edx != esi) goto L633ce1;  // @18_633cbc
  L633cf7:;
  eax = 0;  // @20_633cbc
  L633cf9:;
  return eax;  // @22_633cbc
  L633cfc:;
  eax = edx;  // @24_633cbc
  goto L633cf9;  // @25_633cbc
}
PCREG(633cbc, lifted_633cbc);

extern "C" u32 FASTCALL lifted_660c00(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_660c00
  ebx = ecx;  // @1_660c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_660c00
  edi = edx;  // @3_660c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_660c00
  p0_ = esi;  // @5_660c00
  eax = ext_6604c0_thiscall4(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @6_660c00
  ecx = edx = 0;  // @7_660c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @8_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @10_660c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(8471088), &v, sizeof v); }  // @11_660c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(8471092), &v, sizeof v); }  // @12_660c00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(8471096), &v, sizeof v); }  // @13_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(8471100), &v, sizeof v); }  // @14_660c00
  if ((s32)(edi & edi) <= 0) goto L660c79;  // @15_660c00
  ecx = (u32)(83);  // @16_660c00
  L660c57:;
  esi = edi;  // @18_660c00
  edx = ebx;  // @19_660c00
  if ((s32)edi > (s32)(u32)(83)) esi = ecx;  // @20_660c00
  ecx = eax;  // @21_660c00
  p1_ = esi;  // @22_660c00
  eax = ext_65f690_fastcall3(ecx, edx, (u32)(p1_));  // @23_660c00
  ecx = edx = 0;  // @24_660c00
  edi = (edi - esi);  // @25_660c00
  ecx = (u32)(83);  // @26_660c00
  esi = (esi << (u32)(6));  // @27_660c00
  ebx = (ebx + esi);  // @28_660c00
  if ((s32)(edi & edi) > 0) goto L660c57;  // @29_660c00
  L660c79:;
  return eax;  // @31_660c00
}
PCREG(660c00, lifted_660c00);

extern "C" u32 STDCALL lifted_6639a0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @0_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 228)))(ecx, (u32)(1));  // @2_6639a0
  ecx = edx = 0;  // @3_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @7_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1));  // @8_6639a0
  ecx = edx = 0;  // @9_6639a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6639f4;  // @10_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_6639a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @14_6639a0
  ecx = edx = 0;  // @15_6639a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_6639a0
  ecx = eax;  // @17_6639a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6973164), (u32)(1), (u32)(2));  // @18_6639a0
  ecx = edx = 0;  // @19_6639a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @20_6639a0
  return eax;  // @21_6639a0
  L6639f4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @23_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 228)))(ecx, (u32)(1));  // @25_6639a0
  ecx = edx = 0;  // @26_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_6639a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @30_6639a0
  ecx = edx = 0;  // @31_6639a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_6639a0
  ecx = eax;  // @33_6639a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6973164), (u32)(0), (u32)(2));  // @34_6639a0
  ecx = edx = 0;  // @35_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_6639a0
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_6639a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @38_6639a0
  return eax;  // @39_6639a0
}
PCREG(6639a0, lifted_6639a0);

extern "C" u32 lifted_634432(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ext_634d46_cdecl3((u32)(7493592), (u32)(4000), (u32)(0));  // @0_634432
  ecx = edx = 0;  // @1_634432
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676060))((u32)(7083676));  // @2_634432
  ecx = edx = 0;  // @3_634432
  esi = eax;  // @4_634432
  if ((esi & esi) == 0) goto L6344ea;  // @5_634432
  p0_ = esi;  // @6_634432
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p0_), (u32)(7083704));  // @7_634432
  ecx = edx = 0;  // @8_634432
  p1_ = esi;  // @9_634432
  ebx = eax;  // @10_634432
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p1_), (u32)(7083732));  // @11_634432
  ecx = edx = 0;  // @12_634432
  p2_ = esi;  // @13_634432
  edi = eax;  // @14_634432
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760b4))((u32)(p2_), (u32)(7083760));  // @15_634432
  ecx = edx = 0;  // @16_634432
  esi = eax;  // @17_634432
  if ((ebx & ebx) == 0) goto L6344c3;  // @18_634432
  if ((edi & edi) == 0) goto L6344c3;  // @19_634432
  if ((esi & esi) == 0) goto L6344c3;  // @20_634432
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7493620), sizeof v); (u32)v; }) & (u32)(0))); __builtin_memcpy((void *)(u32)(7493620), &v, sizeof v); }  // @21_634432
  ecx = ebx;  // @22_634432
  eax = ext_634aae_cdecl1((u32)(7493616));  // @23_634432
  ecx = edx = 0;  // @24_634432
  eax = ((u32(STDCALL *)(void))(ebx))();  // @25_634432
  ecx = edx = 0;  // @26_634432
  p3_ = edi;  // @27_634432
  eax = ext_6344f2_cdecl1((u32)(p3_));  // @28_634432
  ecx = edx = 0;  // @29_634432
  p4_ = esi;  // @30_634432
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7493624), &v, sizeof v); }  // @31_634432
  eax = ext_6344f2_cdecl1((u32)(p4_));  // @32_634432
  ecx = edx = 0;  // @33_634432
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7493628), &v, sizeof v); }  // @34_634432
  goto L6344d9;  // @35_634432
  L6344c3:;
  eax = 0;  // @37_634432
  p5_ = eax;  // @38_634432
  p6_ = eax;  // @39_634432
  p7_ = eax;  // @40_634432
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x676064))((u32)(p7_), (u32)(1), (u32)(p6_), (u32)(p5_));  // @41_634432
  ecx = edx = 0;  // @42_634432
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7493620), &v, sizeof v); }  // @43_634432
  if ((eax & eax) == 0) goto L6344ea;  // @44_634432
  L6344d9:;
  eax = ext_633f0f_cdecl1((u32)(6505743));  // @46_634432
  ecx = edx = 0;  // @47_634432
  eax = 0;  // @48_634432
  return eax;  // @49_634432
  L6344ea:;
  eax = ext_634879_cdecl1((u32)(7));  // @51_634432
  ecx = edx = 0;  // @52_634432
}
PCREG(634432, lifted_634432);

extern "C" u32 THISCALL lifted_661650(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @1_661650
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_661650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @3_661650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @4_661650
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_661650
  esi = edx;  // @6_661650
  eax = edx;  // @7_661650
  ebx = (edx & 0xffff);  // @8_661650
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_661650
  eax = (eax >> (u32)(31));  // @10_661650
  edx = (edx + ecx);  // @11_661650
  esi = (esi >> (u32)(16));  // @12_661650
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @13_661650
  esi = (esi & (u32)(32767));  // @14_661650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @15_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @16_661650
  ebx = (ebx + esi);  // @17_661650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @18_661650
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax) == 0) goto L6616e5;  // @19_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @20_661650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @21_661650
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @22_661650
  eax = (u32)(eax + esi*2);  // @23_661650
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @24_661650
  p0_ = ebx;  // @25_661650
  p1_ = esi;  // @26_661650
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @27_661650
  p2_ = eax;  // @28_661650
  p3_ = ecx;  // @29_661650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @30_661650
  p4_ = esi;  // @31_661650
  eax = ext_6616f0_thiscall10(ecx, (u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }));  // @32_661650
  ecx = edx = 0;  // @33_661650
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L6616e5;  // @34_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @35_661650
  eax = (eax << (u32)(16));  // @36_661650
  eax = (eax | (u32)(3));  // @37_661650
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @38_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @39_661650
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @40_661650
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @41_661650
  return eax;  // @42_661650
  L6616e5:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @44_661650
  return eax;  // @45_661650
}
PCREG(661650, lifted_661650);

extern "C" u32 THISCALL lifted_663520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_663520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L663573;  // @1_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @2_663520
  ebx = (u32)(esi + 74124);  // @3_663520
  ecx = ebx;  // @4_663520
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @5_663520
  ecx = edx = 0;  // @6_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @7_663520
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @11_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @13_663520
  ecx = edx = 0;  // @14_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @15_663520
  p0_ = eax;  // @16_663520
  p1_ = ebx;  // @17_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 308)))(ecx, (u32)(p1_), (u32)(p0_));  // @18_663520
  ecx = edx = 0;  // @19_663520
  L663573:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @21_663520
  ecx = (u32)(esi + 74124);  // @22_663520
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @23_663520
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @24_663520
  ecx = edx = 0;  // @25_663520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @26_663520
  if ((s32)(eax & eax) <= 0) goto L6635e7;  // @27_663520
  edi = 0;  // @28_663520
  if ((s32)(eax & eax) <= 0) goto L6635e7;  // @29_663520
  L6635a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @31_663520
  ecx = (u32)(esi + 74124);  // @32_663520
  p2_ = edi;  // @33_663520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(p2_));  // @34_663520
  ecx = edx = 0;  // @35_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; });  // @36_663520
  p3_ = eax;  // @37_663520
  eax = ext_5ae900_thiscall2(ecx, (u32)(p3_));  // @38_663520
  ecx = edx = 0;  // @39_663520
  ecx = esi;  // @40_663520
  eax = ext_663680_thiscall1(ecx);  // @41_663520
  ecx = edx = 0;  // @42_663520
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L6635f8;  // @43_663520
  ecx = (u32)(esi + 4);  // @44_663520
  eax = ext_663b60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }));  // @45_663520
  ecx = edx = 0;  // @46_663520
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @47_663520
  edi = (edi + 1);  // @48_663520
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L6635a0;  // @49_663520
  L6635e7:;
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @51_663520
  return eax;  // @52_663520
  L6635f8:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @54_663520
  return eax;  // @55_663520
}
PCREG(663520, lifted_663520);

