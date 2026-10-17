// batch200112.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc4d0_fastcall2(u32, u32) __asm__("ext_4cc4d0");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_4d2c00_stdcall1(u32) __asm__("ext_4d2c00");
extern "C" u32 STDCALL ext_56b460_stdcall1(u32) __asm__("ext_56b460");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 STDCALL ext_62f5d0_stdcall2(u32, u32) __asm__("ext_62f5d0");
extern "C" u32 THISCALL ext_4870b0_thiscall2(u32, u32) __asm__("ext_4870b0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ce180_thiscall2(u32, u32) __asm__("ext_4ce180");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1590_thiscall1(u32) __asm__("ext_4e1590");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_562bc0_thiscall1(u32) __asm__("ext_562bc0");
extern "C" u32 THISCALL ext_563400_thiscall1(u32) __asm__("ext_563400");
extern "C" u32 THISCALL ext_563440_thiscall1(u32) __asm__("ext_563440");
extern "C" u32 THISCALL ext_564600_thiscall2(u32, u32) __asm__("ext_564600");
extern "C" u32 THISCALL ext_5646e0_thiscall2(u32, u32) __asm__("ext_5646e0");
extern "C" u32 THISCALL ext_565020_thiscall3(u32, u32, u32) __asm__("ext_565020");
extern "C" u32 THISCALL ext_565100_thiscall2(u32, u32) __asm__("ext_565100");
extern "C" u32 THISCALL ext_56c6a0_thiscall1(u32) __asm__("ext_56c6a0");
extern "C" u32 THISCALL ext_5ae710_thiscall2(u32, u32) __asm__("ext_5ae710");
extern "C" u32 THISCALL ext_5ec390_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5ec390");
extern "C" u32 THISCALL ext_5f9db0_thiscall2(u32, u32) __asm__("ext_5f9db0");
extern "C" u32 THISCALL ext_5fa1e0_thiscall2(u32, u32) __asm__("ext_5fa1e0");
extern "C" u32 THISCALL ext_5fa220_thiscall2(u32, u32) __asm__("ext_5fa220");
extern "C" u32 THISCALL ext_5fb210_thiscall3(u32, u32, u32) __asm__("ext_5fb210");
extern "C" u32 THISCALL ext_63db40_thiscall2(u32, u32) __asm__("ext_63db40");
extern "C" u32 THISCALL ext_64c1e0_thiscall2(u32, u32) __asm__("ext_64c1e0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_61c790_cdecl6(...) __asm__("ext_61c790");
extern "C" u32 ext_61fd60_cdecl3(...) __asm__("ext_61fd60");
extern "C" u32 ext_620180_cdecl4(...) __asm__("ext_620180");
extern "C" u32 ext_6206e0_cdecl1(...) __asm__("ext_6206e0");
extern "C" u32 ext_620c00_cdecl4(...) __asm__("ext_620c00");
extern "C" u32 ext_620cb0_cdecl4(...) __asm__("ext_620cb0");
extern "C" u32 ext_620d50_cdecl4(...) __asm__("ext_620d50");
extern "C" u32 ext_6218c0_cdecl4(...) __asm__("ext_6218c0");
extern "C" u32 ext_626e10_cdecl2(...) __asm__("ext_626e10");
extern "C" u32 ext_626ed0_cdecl4(...) __asm__("ext_626ed0");
extern "C" u32 ext_626f60_cdecl4(...) __asm__("ext_626f60");
extern "C" u32 ext_627420_cdecl4(...) __asm__("ext_627420");
extern "C" u32 ext_627470_cdecl4(...) __asm__("ext_627470");
extern "C" u32 ext_627520_cdecl4(...) __asm__("ext_627520");
extern "C" u32 ext_627640_cdecl4(...) __asm__("ext_627640");
extern "C" u32 ext_6277b0_cdecl4(...) __asm__("ext_6277b0");
extern "C" u32 ext_627a80_cdecl5(...) __asm__("ext_627a80");
extern "C" u32 ext_627bb0_cdecl4(...) __asm__("ext_627bb0");
extern "C" u32 ext_627fd0_cdecl4(...) __asm__("ext_627fd0");
extern "C" u32 ext_6281a0_cdecl4(...) __asm__("ext_6281a0");
extern "C" u32 ext_628470_cdecl4(...) __asm__("ext_628470");
extern "C" u32 ext_628630_cdecl4(...) __asm__("ext_628630");
extern "C" u32 ext_628f30_cdecl4(...) __asm__("ext_628f30");
extern "C" u32 ext_628fc0_cdecl4(...) __asm__("ext_628fc0");
extern "C" u32 ext_629480_cdecl4(...) __asm__("ext_629480");
extern "C" u32 ext_6294d0_cdecl4(...) __asm__("ext_6294d0");
extern "C" u32 ext_629580_cdecl4(...) __asm__("ext_629580");
extern "C" u32 ext_6296a0_cdecl4(...) __asm__("ext_6296a0");
extern "C" u32 ext_629810_cdecl4(...) __asm__("ext_629810");
extern "C" u32 ext_629ae0_cdecl5(...) __asm__("ext_629ae0");
extern "C" u32 ext_629c10_cdecl4(...) __asm__("ext_629c10");
extern "C" u32 ext_62a030_cdecl4(...) __asm__("ext_62a030");
extern "C" u32 ext_62a200_cdecl4(...) __asm__("ext_62a200");
extern "C" u32 ext_62a4d0_cdecl4(...) __asm__("ext_62a4d0");
extern "C" u32 ext_62a690_cdecl4(...) __asm__("ext_62a690");
extern "C" u32 ext_62a870_cdecl4(...) __asm__("ext_62a870");
extern "C" u32 ext_62a8e0_cdecl4(...) __asm__("ext_62a8e0");
extern "C" u32 ext_62ad10_cdecl4(...) __asm__("ext_62ad10");
extern "C" u32 ext_62ad60_cdecl4(...) __asm__("ext_62ad60");
extern "C" u32 ext_62add0_cdecl4(...) __asm__("ext_62add0");
extern "C" u32 ext_62add0_cdecl5(...) __asm__("ext_62add0");
extern "C" u32 ext_62af10_cdecl4(...) __asm__("ext_62af10");
extern "C" u32 ext_62b040_cdecl4(...) __asm__("ext_62b040");
extern "C" u32 ext_62b2f0_cdecl5(...) __asm__("ext_62b2f0");
extern "C" u32 ext_62b2f0_cdecl6(...) __asm__("ext_62b2f0");
extern "C" u32 ext_62b450_cdecl6(...) __asm__("ext_62b450");
extern "C" u32 ext_62b900_cdecl4(...) __asm__("ext_62b900");
extern "C" u32 ext_62bb10_cdecl4(...) __asm__("ext_62bb10");
extern "C" u32 ext_62be60_cdecl4(...) __asm__("ext_62be60");
extern "C" u32 ext_62c060_cdecl4(...) __asm__("ext_62c060");
extern "C" u32 ext_62c060_cdecl6(...) __asm__("ext_62c060");
extern "C" u32 ext_62c640_cdecl2(...) __asm__("ext_62c640");
extern "C" u32 ext_62c640_cdecl3(...) __asm__("ext_62c640");
extern "C" u32 ext_62c640_cdecl4(...) __asm__("ext_62c640");
extern "C" u32 ext_62c640_cdecl5(...) __asm__("ext_62c640");
extern "C" u32 ext_6328b0_cdecl5(...) __asm__("ext_6328b0");
extern "C" u32 ext_632940_cdecl9(...) __asm__("ext_632940");
extern "C" u32 ext_632a70_cdecl8(...) __asm__("ext_632a70");
extern "C" u32 ext_632aa0_cdecl3(...) __asm__("ext_632aa0");
extern "C" u32 ext_633170_cdecl2(...) __asm__("ext_633170");
extern "C" u32 ext_633190_cdecl5(...) __asm__("ext_633190");
extern "C" u32 ext_6331d0_cdecl3(...) __asm__("ext_6331d0");
extern "C" u32 ext_6331d0_cdecl4(...) __asm__("ext_6331d0");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 FASTCALL lifted_6403a0(u32 ecx_in, u32 edx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6403a0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @1_6403a0
  if (((edx & 0xffff) & (edx & 0xffff)) == 0) goto L6403e4;  // @2_6403a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 104), sizeof v); (u32)v; });  // @3_6403a0
  edx = (edx & (u32)(4095));  // @4_6403a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @5_6403a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @6_6403a0
  eax = (eax - 1);  // @7_6403a0
  if (eax > (u32)(3)) goto L6403d4;  // @8_6403a0
  switch (eax) { case 0: goto L6403e4; case 1: goto L6403cc; case 2: goto L6403e4; case 3: goto L6403e4; default: __builtin_trap(); }  // @9_6403a0
  L6403cc:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 66), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ecx + 66), &v, sizeof v); }  // @11_6403a0
  return eax;  // @12_6403a0
  L6403d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @14_6403a0
  if ((eax & eax) == 0) goto L6403e3;  // @15_6403a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @16_6403a0
  ecx = edx = 0;  // @17_6403a0
  return eax;  // @18_6403a0
  L6403e3:;
  __builtin_trap();  // @20_6403a0
  L6403e4:;
  return eax;  // @22_6403a0
}
PCREG(6403a0, lifted_6403a0);

extern "C" u32 THISCALL lifted_4f90c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f90c0
  eax = (eax + (u32)(-37));  // @1_4f90c0
  if (eax > (u32)(3)) goto L4f911d;  // @2_4f90c0
  switch (eax) { case 0: goto L4f90d5; case 1: goto L4f90ef; case 2: goto L4f90e2; case 3: goto L4f90fc; default: __builtin_trap(); }  // @3_4f90c0
  L4f90d5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 475), sizeof v); (u32)v; }) == (u32)(0)) goto L4f911d;  // @5_4f90c0
  goto L4f9107;  // @6_4f90c0
  L4f90e2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 476), sizeof v); (u32)v; }) == (u32)(0)) goto L4f911d;  // @8_4f90c0
  goto L4f9107;  // @9_4f90c0
  L4f90ef:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 477), sizeof v); (u32)v; }) == (u32)(0)) goto L4f911d;  // @11_4f90c0
  goto L4f9107;  // @12_4f90c0
  L4f90fc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 478), sizeof v); (u32)v; }) == (u32)(0)) goto L4f911d;  // @14_4f90c0
  L4f9107:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4f90c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4), (u32)(3), (u32)(2), (u32)(1));  // @17_4f90c0
  ecx = edx = 0;  // @18_4f90c0
  ecx = eax;  // @19_4f90c0
  if ((ecx & ecx) == 0) goto L4f911d;  // @20_4f90c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4f90c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 788)))(ecx);  // @22_4f90c0
  ecx = edx = 0;  // @23_4f90c0
  L4f911d:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @25_4f90c0
  return eax;  // @26_4f90c0
}
PCREG(4f90c0, lifted_4f90c0);

extern "C" u32 THISCALL lifted_4fa390(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4fa390
  eax = (eax + (u32)(4294967040));  // @1_4fa390
  esi = ecx;  // @2_4fa390
  p0_ = edi;  // @3_4fa390
  if (eax > (u32)(3)) goto L4fa3dc;  // @4_4fa390
  switch (eax) { case 0: goto L4fa3b7; case 1: goto L4fa3b3; case 2: goto L4fa3ab; case 3: goto L4fa3af; default: __builtin_trap(); }  // @5_4fa390
  L4fa3ab:;
  goto L4fa3b9;  // @7_4fa390
  L4fa3af:;
  goto L4fa3b9;  // @9_4fa390
  L4fa3b3:;
  goto L4fa3b9;  // @11_4fa390
  L4fa3b7:;
  L4fa3b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_4fa390
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4), (u32)(3), (u32)(2), (u32)(1), (u32)(p0_));  // @15_4fa390
  ecx = edx = 0;  // @16_4fa390
  edi = eax;  // @17_4fa390
  if ((edi & edi) == 0) goto L4fa3dc;  // @18_4fa390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_4fa390
  ecx = esi;  // @20_4fa390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @21_4fa390
  ecx = edx = 0;  // @22_4fa390
  p1_ = edi;  // @23_4fa390
  ecx = eax;  // @24_4fa390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @25_4fa390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, (u32)(p1_));  // @26_4fa390
  ecx = edx = 0;  // @27_4fa390
  L4fa3dc:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @29_4fa390
  return eax;  // @30_4fa390
}
PCREG(4fa390, lifted_4fa390);

extern "C" u32 THISCALL lifted_656fe0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_656fe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @1_656fe0
  ecx = edx = 0;  // @2_656fe0
  edx = eax;  // @3_656fe0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; }) != (u32)(0)) goto L65702c;  // @4_656fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_656fe0
  ecx = (ecx - 1);  // @6_656fe0
  if (ecx > (u32)(15)) goto L65701e;  // @7_656fe0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6647884), sizeof v); (u32)v; });  // @8_656fe0
  switch (ecx) { case 0: goto L657012; case 1: goto L65700b; case 2: goto L65701e; default: __builtin_trap(); }  // @9_656fe0
  L65700b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @11_656fe0
  return eax;  // @12_656fe0
  L657012:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 14), sizeof v); (u32)v; });  // @14_656fe0
  eax = (u32)((s32)eax * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 80), sizeof v); (u32)v; }));  // @15_656fe0
  return eax;  // @16_656fe0
  L65701e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_656fe0
  if ((eax & eax) == 0) goto L65702b;  // @19_656fe0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @20_656fe0
  ecx = edx = 0;  // @21_656fe0
  goto L65702c;  // @22_656fe0
  L65702b:;
  __builtin_trap();  // @24_656fe0
  L65702c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @26_656fe0
  if ((eax & eax) == 0) goto L65703b;  // @27_656fe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @28_656fe0
  ecx = edx = 0;  // @29_656fe0
  return eax;  // @30_656fe0
  L65703b:;
  __builtin_trap();  // @32_656fe0
}
PCREG(656fe0, lifted_656fe0);

extern "C" u32 THISCALL lifted_4fa720(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4fa720
  eax = (eax - 1);  // @1_4fa720
  esi = ecx;  // @2_4fa720
  if (eax > (u32)(3)) goto L4fa7a3;  // @3_4fa720
  switch (eax) { case 0: goto L4fa736; case 1: goto L4fa751; case 2: goto L4fa76c; case 3: goto L4fa78a; default: __builtin_trap(); }  // @4_4fa720
  L4fa736:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @9_4fa720
  ecx = edx = 0;  // @10_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @11_4fa720
  return eax;  // @12_4fa720
  L4fa751:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @17_4fa720
  ecx = edx = 0;  // @18_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @19_4fa720
  return eax;  // @20_4fa720
  L4fa76c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @25_4fa720
  ecx = edx = 0;  // @26_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @27_4fa720
  return eax;  // @28_4fa720
  L4fa78a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @33_4fa720
  ecx = edx = 0;  // @34_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @35_4fa720
  L4fa7a3:;
  return eax;  // @37_4fa720
}
PCREG(4fa720, lifted_4fa720);

extern "C" u32 STDCALL lifted_658290(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_658290
  eax = (eax - 1);  // @1_658290
  if (eax > (u32)(8)) goto L65833b;  // @2_658290
  switch (eax) { case 0: goto L6582a7; case 1: goto L6582c1; case 2: goto L65830f; case 3: goto L65833b; case 4: goto L65833b; case 5: goto L65833b; case 6: goto L6582db; case 7: goto L6582f7; case 8: goto L65832b; default: __builtin_trap(); }  // @3_658290
  L6582a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @6_658290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 141), sizeof v); (u32)v; });  // @7_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_658290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_658290
  return eax;  // @10_658290
  L6582c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @13_658290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 137), sizeof v); (u32)v; });  // @14_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_658290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @16_658290
  return eax;  // @17_658290
  L6582db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_658290
  ecx = 0;  // @20_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @21_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @22_658290
  ecx = (ecx & 0xffffff00u) | (((u32)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; }) == (ecx & 0xff))) & 0xff);  // @23_658290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_658290
  return eax;  // @25_658290
  L6582f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @28_658290
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 114), sizeof v); (u32)v; });  // @29_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @30_658290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @31_658290
  return eax;  // @32_658290
  L65830f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_658290
  ecx = 0;  // @35_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @36_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @37_658290
  ecx = (ecx & 0xffffff00u) | (((u32)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 109), sizeof v); (u32)v; }) == (ecx & 0xff))) & 0xff);  // @38_658290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @39_658290
  return eax;  // @40_658290
  L65832b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_658290
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 151), sizeof v); (u32)v; });  // @43_658290
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @44_658290
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @45_658290
  L65833b:;
  return eax;  // @47_658290
}
PCREG(658290, lifted_658290);

extern "C" u32 STDCALL lifted_657360(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_657360
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @1_657360
  if (eax > (u32)(6)) goto L6573db;  // @2_657360
  switch (eax) { case 0: goto L657377; case 1: goto L657381; case 2: goto L6573db; case 3: goto L6573db; case 4: goto L65738b; case 5: goto L6573db; case 6: goto L657395; case 7: goto L6573af; case 8: goto L6573a5; case 9: goto L6573c3; case 10: goto L6573b9; default: __builtin_trap(); }  // @3_657360
  L657377:;
  eax = (u32)(124);  // @5_657360
  return eax;  // @6_657360
  L657381:;
  eax = (u32)(160);  // @8_657360
  return eax;  // @9_657360
  L65738b:;
  eax = (u32)(132);  // @11_657360
  return eax;  // @12_657360
  L657395:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @14_657360
  if (eax > (u32)(3)) goto L6573cd;  // @15_657360
  switch (eax) { case 0: goto L6573af; case 1: goto L6573a5; case 2: goto L6573c3; case 3: goto L6573b9; default: __builtin_trap(); }  // @16_657360
  L6573a5:;
  eax = (u32)(36);  // @18_657360
  return eax;  // @19_657360
  L6573af:;
  eax = (u32)(56);  // @21_657360
  return eax;  // @22_657360
  L6573b9:;
  eax = (u32)(28);  // @24_657360
  return eax;  // @25_657360
  L6573c3:;
  eax = (u32)(60);  // @27_657360
  return eax;  // @28_657360
  L6573cd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_657360
  if ((eax & eax) == 0) goto L6573da;  // @31_657360
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_657360
  ecx = edx = 0;  // @33_657360
  goto L6573db;  // @34_657360
  L6573da:;
  __builtin_trap();  // @36_657360
  L6573db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @38_657360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_657360
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7094156), (u32)(47));  // @40_657360
  ecx = edx = 0;  // @41_657360
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2), sizeof v); (u32)v; });  // @42_657360
  p0_ = ecx;  // @43_657360
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_657360
  p1_ = eax;  // @45_657360
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(p1_), (u32)(7094216), (u32)(p0_));  // @46_657360
  ecx = edx = 0;  // @47_657360
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @48_657360
  if ((eax & eax) == 0) goto L657410;  // @49_657360
  eax = ((u32(STDCALL *)(void))(eax))();  // @50_657360
  ecx = edx = 0;  // @51_657360
  return eax;  // @52_657360
  L657410:;
  __builtin_trap();  // @54_657360
}
PCREG(657360, lifted_657360);

extern "C" u32 lifted_62af10(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62af10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_62af10
  if (ecx != edx) goto L62af22;  // @2_62af10
  eax = (eax | (u32)(4294967295));  // @3_62af10
  return eax;  // @4_62af10
  L62af22:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_62af10
  p0_ = esi;  // @7_62af10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62af10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @9_62af10
  eax = (eax + (u32)(-20));  // @10_62af10
  if (eax > (u32)(7)) goto L62afcb;  // @11_62af10
  switch (eax) { case 0: goto L62af55; case 1: goto L62afcb; case 2: goto L62af63; case 3: goto L62afcb; case 4: goto L62af63; case 5: goto L62afcb; case 6: goto L62afcb; case 7: goto L62af41; case 8: goto L62afbe; case 9: goto L62af8e; case 10: goto L62af99; case 11: goto L62afcb; default: __builtin_trap(); }  // @12_62af10
  L62af41:;
  eax = (u32)(ecx + 1);  // @14_62af10
  p1_ = edx;  // @15_62af10
  p2_ = eax;  // @16_62af10
  p3_ = esi;  // @17_62af10
  eax = ext_62add0_cdecl5((u32)(p3_), (u32)(p2_), (u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p0_));  // @18_62af10
  ecx = edx = 0;  // @19_62af10
  return eax;  // @20_62af10
  L62af55:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @22_62af10
  ecx = (ecx + 1);  // @23_62af10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_62af10
  eax = (u32)(33);  // @25_62af10
  return eax;  // @26_62af10
  L62af63:;
  ecx = (ecx + 1);  // @28_62af10
  if (ecx == edx) goto L62af93;  // @29_62af10
  L62af70:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_62af10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @32_62af10
  eax = (eax + (u32)(-9));  // @33_62af10
  if (eax > (u32)(21)) goto L62afcb;  // @34_62af10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6467592), sizeof v); (u32)v; });  // @35_62af10
  switch (eax) { case 0: goto L62afbe; case 1: goto L62af8e; case 2: goto L62af99; case 3: goto L62afcb; default: __builtin_trap(); }  // @36_62af10
  L62af8e:;
  ecx = (ecx + 1);  // @38_62af10
  if (ecx != edx) goto L62af70;  // @39_62af10
  L62af93:;
  eax = (eax | (u32)(4294967295));  // @41_62af10
  return eax;  // @42_62af10
  L62af99:;
  eax = (u32)(ecx + 1);  // @44_62af10
  if (eax == edx) goto L62af93;  // @45_62af10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_62af10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @47_62af10
  eax = (eax + (u32)(-9));  // @48_62af10
  if (eax > (u32)(21)) goto L62afbe;  // @49_62af10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6467624), sizeof v); (u32)v; });  // @50_62af10
  switch (eax) { case 0: goto L62afcb; case 1: goto L62afbe; default: __builtin_trap(); }  // @51_62af10
  L62afbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @53_62af10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @54_62af10
  eax = (u32)(16);  // @55_62af10
  return eax;  // @56_62af10
  L62afcb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @58_62af10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @59_62af10
  eax = 0;  // @60_62af10
  return eax;  // @61_62af10
}
PCREG(62af10, lifted_62af10);

extern "C" u32 STDCALL lifted_6496e0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6496e0
  esi = 0;  // @1_6496e0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @2_6496e0
  if (eax > (u32)(5)) goto L64977a;  // @3_6496e0
  switch (eax) { case 0: goto L6496fe; case 1: goto L64973b; case 2: goto L649765; case 3: goto L649750; case 4: goto L649750; case 5: goto L649796; default: __builtin_trap(); }  // @4_6496e0
  L6496fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @6_6496e0
  esi = (u32)(1);  // @7_6496e0
  if (((eax & 0xff) & (u32)(6)) == 0) goto L64971f;  // @8_6496e0
  esi = (u32)(5);  // @9_6496e0
  eax = (u32)(esi + 7);  // @10_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @11_6496e0
  return eax;  // @12_6496e0
  L64971f:;
  if ((eax & (u32)(4204033)) == 0) goto L649796;  // @14_6496e0
  esi = (u32)(4);  // @15_6496e0
  eax = (u32)(esi + 7);  // @16_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @17_6496e0
  return eax;  // @18_6496e0
  L64973b:;
  esi = (u32)(2);  // @20_6496e0
  eax = (u32)(esi + 7);  // @21_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @22_6496e0
  return eax;  // @23_6496e0
  L649750:;
  esi = (u32)(3);  // @25_6496e0
  eax = (u32)(esi + 7);  // @26_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @27_6496e0
  return eax;  // @28_6496e0
  L649765:;
  esi = (u32)(6);  // @30_6496e0
  eax = (u32)(esi + 7);  // @31_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @32_6496e0
  return eax;  // @33_6496e0
  L64977a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @35_6496e0
  if ((eax & eax) == 0) goto L649795;  // @36_6496e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @37_6496e0
  ecx = edx = 0;  // @38_6496e0
  eax = (u32)(esi + 7);  // @39_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @40_6496e0
  return eax;  // @41_6496e0
  L649795:;
  __builtin_trap();  // @43_6496e0
  L649796:;
  eax = (u32)(esi + 7);  // @45_6496e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(16)) eax = esi;  // @46_6496e0
  return eax;  // @47_6496e0
}
PCREG(6496e0, lifted_6496e0);

extern "C" u32 THISCALL lifted_56c5a0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_56c5a0
  eax = ext_565020_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @1_56c5a0
  ecx = edx = 0;  // @2_56c5a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L56c651;  // @3_56c5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @4_56c5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_56c5a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @6_56c5a0
  ecx = edx = 0;  // @7_56c5a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 3306), &v, sizeof v); }  // @8_56c5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3310), sizeof v); (u32)v; });  // @9_56c5a0
  if (eax > (u32)(5)) goto L56c678;  // @10_56c5a0
  switch (eax) { case 0: goto L56c5f2; case 1: goto L56c5e2; case 2: goto L56c5e2; case 3: goto L56c602; case 4: goto L56c631; case 5: goto L56c641; default: __builtin_trap(); }  // @11_56c5a0
  L56c5e2:;
  ecx = esi;  // @13_56c5a0
  eax = ext_564600_thiscall2(ecx, (u32)(1));  // @14_56c5a0
  ecx = edx = 0;  // @15_56c5a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @16_56c5a0
  return eax;  // @17_56c5a0
  L56c5f2:;
  ecx = esi;  // @19_56c5a0
  eax = ext_564600_thiscall2(ecx, (u32)(8));  // @20_56c5a0
  ecx = edx = 0;  // @21_56c5a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @22_56c5a0
  return eax;  // @23_56c5a0
  L56c602:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @25_56c5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_56c5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @27_56c5a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @28_56c5a0
  ecx = edx = 0;  // @29_56c5a0
  ecx = esi;  // @30_56c5a0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L56c623;  // @31_56c5a0
  eax = ext_564600_thiscall2(ecx, (u32)(8));  // @32_56c5a0
  ecx = edx = 0;  // @33_56c5a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @34_56c5a0
  return eax;  // @35_56c5a0
  L56c623:;
  eax = ext_564600_thiscall2(ecx, (u32)(0));  // @37_56c5a0
  ecx = edx = 0;  // @38_56c5a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @39_56c5a0
  return eax;  // @40_56c5a0
  L56c631:;
  ecx = esi;  // @42_56c5a0
  eax = ext_565100_thiscall2(ecx, (u32)(21));  // @43_56c5a0
  ecx = edx = 0;  // @44_56c5a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @45_56c5a0
  return eax;  // @46_56c5a0
  L56c641:;
  ecx = esi;  // @48_56c5a0
  eax = ext_565100_thiscall2(ecx, (u32)(24));  // @49_56c5a0
  ecx = edx = 0;  // @50_56c5a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @51_56c5a0
  return eax;  // @52_56c5a0
  L56c651:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3310), sizeof v); (u32)v; }) != (u32)(1)) goto L56c66e;  // @54_56c5a0
  ecx = esi;  // @55_56c5a0
  eax = ext_56c6a0_thiscall1(ecx);  // @56_56c5a0
  ecx = edx = 0;  // @57_56c5a0
  ecx = esi;  // @58_56c5a0
  eax = ext_56b460_stdcall1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3298), sizeof v); (u32)v; }));  // @59_56c5a0
  ecx = edx = 0;  // @60_56c5a0
  L56c66e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_56c5a0
  ecx = esi;  // @63_56c5a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 260)))(ecx);  // @64_56c5a0
  ecx = edx = 0;  // @65_56c5a0
  L56c678:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @67_56c5a0
  return eax;  // @68_56c5a0
}
PCREG(56c5a0, lifted_56c5a0);

extern "C" u32 lifted_62d030(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62d030
  p0_ = edi;  // @1_62d030
  eax = (u32)(esi - 15);  // @2_62d030
  if (eax > (u32)(10)) goto L62d0cd;  // @3_62d030
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6476036), sizeof v); (u32)v; });  // @4_62d030
  switch (eax) { case 0: goto L62d052; case 1: goto L62d06a; case 2: goto L62d07c; case 3: goto L62d058; case 4: goto L62d0cd; default: __builtin_trap(); }  // @5_62d030
  L62d052:;
  eax = 0;  // @7_62d030
  return eax;  // @8_62d030
  L62d058:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_62d030
  { u32 v = (u32)((u32)(6478944)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @11_62d030
  eax = (u32)(6);  // @12_62d030
  return eax;  // @13_62d030
  L62d06a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_62d030
  { u32 v = (u32)((u32)(6480160)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @16_62d030
  eax = (u32)(7);  // @17_62d030
  return eax;  // @18_62d030
  L62d07c:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @20_62d030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @21_62d030
  p1_ = edi;  // @22_62d030
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))((u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078408), (u32)(p0_));  // @23_62d030
  ecx = edx = 0;  // @24_62d030
  if ((eax & eax) == 0) goto L62d0a6;  // @25_62d030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_62d030
  { u32 v = (u32)((u32)(6476128)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @27_62d030
  eax = 0;  // @28_62d030
  return eax;  // @29_62d030
  L62d0a6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @31_62d030
  p2_ = edi;  // @32_62d030
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078388));  // @33_62d030
  ecx = edx = 0;  // @34_62d030
  if ((eax & eax) == 0) goto L62d0cd;  // @35_62d030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_62d030
  { u32 v = (u32)((u32)(6476048)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_62d030
  eax = 0;  // @38_62d030
  return eax;  // @39_62d030
  L62d0cd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @41_62d030
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L62d0e2;  // @42_62d030
  if (esi != (u32)(28)) goto L62d0e2;  // @43_62d030
  eax = (u32)(esi + 24);  // @44_62d030
  return eax;  // @45_62d030
  L62d0e2:;
  { u32 v = (u32)((u32)(5370416)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_62d030
  eax = (eax | (u32)(4294967295));  // @48_62d030
  return eax;  // @49_62d030
}
PCREG(62d030, lifted_62d030);

extern "C" u32 THISCALL lifted_4e14a0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4e14a0
  esi = 0;  // @1_4e14a0
  edi = ecx;  // @2_4e14a0
  if ((s32)(ebx & ebx) <= 0) goto L4e1564;  // @3_4e14a0
  L4e14b5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @5_4e14a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @6_4e14a0
  if ((eax & 0xff) == (u32)(255)) goto L4e14d3;  // @7_4e14a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @8_4e14a0
  if ((eax & 0xff) != (u32)(3)) goto L4e14d3;  // @9_4e14a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_4e14a0
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @11_4e14a0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + ecx), &v, sizeof v); }  // @12_4e14a0
  goto L4e1504;  // @13_4e14a0
  L4e14d3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @15_4e14a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4e14a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6910228), (u32)(583));  // @17_4e14a0
  ecx = edx = 0;  // @18_4e14a0
  p0_ = eax;  // @19_4e14a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_4e14a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6910392));  // @21_4e14a0
  ecx = edx = 0;  // @22_4e14a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @23_4e14a0
  if ((eax & eax) == 0) goto L4e1503;  // @24_4e14a0
  eax = ((u32(STDCALL *)(void))(eax))();  // @25_4e14a0
  ecx = edx = 0;  // @26_4e14a0
  goto L4e1504;  // @27_4e14a0
  L4e1503:;
  __builtin_trap();  // @29_4e14a0
  L4e1504:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @31_4e14a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @32_4e14a0
  if ((eax & 0xff) != (u32)(255)) goto L4e1511;  // @33_4e14a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (eax & 0xff))) & 0xff);  // @34_4e14a0
  goto L4e1513;  // @35_4e14a0
  L4e1511:;
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @37_4e14a0
  L4e1513:;
  eax = (eax & 0xff);  // @39_4e14a0
  eax = (eax - 1);  // @40_4e14a0
  if (eax > (u32)(11)) goto L4e1553;  // @41_4e14a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5117312), sizeof v); (u32)v; });  // @42_4e14a0
  switch (eax) { case 0: goto L4e152f; case 1: goto L4e1536; case 2: goto L4e153d; case 3: goto L4e152a; case 4: goto L4e1553; default: __builtin_trap(); }  // @43_4e14a0
  L4e152a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @45_4e14a0
  goto L4e1555;  // @46_4e14a0
  L4e152f:;
  eax = (u32)(8);  // @48_4e14a0
  goto L4e1555;  // @49_4e14a0
  L4e1536:;
  eax = (u32)(4);  // @51_4e14a0
  goto L4e1555;  // @52_4e14a0
  L4e153d:;
  eax = (u32)(edx + 1);  // @54_4e14a0
  ecx = (u32)(eax + 1);  // @55_4e14a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @56_4e14a0
  L4e1546:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @58_4e14a0
  eax = (eax + 1);  // @59_4e14a0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4e1546;  // @60_4e14a0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @61_4e14a0
  eax = (eax + 1);  // @62_4e14a0
  goto L4e1555;  // @63_4e14a0
  L4e1553:;
  eax = 0;  // @65_4e14a0
  L4e1555:;
  eax = (eax + 1);  // @67_4e14a0
  esi = (esi + 1);  // @68_4e14a0
  eax = (eax + edx);  // @69_4e14a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @70_4e14a0
  if ((s32)esi < (s32)ebx) goto L4e14b5;  // @71_4e14a0
  L4e1564:;
  return eax;  // @73_4e14a0
}
PCREG(4e14a0, lifted_4e14a0);

extern "C" u32 THISCALL lifted_471ff0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_471ff0
  esi = ecx;  // @1_471ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @4_471ff0
  ecx = edx = 0;  // @5_471ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_471ff0
  ebx = eax;  // @7_471ff0
  eax = (u32)(ecx - 1);  // @8_471ff0
  if (eax > (u32)(14)) goto L47208c;  // @9_471ff0
  switch (eax) { case 0: goto L472046; case 1: goto L472046; case 2: goto L472046; case 3: goto L472046; case 4: goto L47206d; case 5: goto L47206d; case 6: goto L47201f; case 7: goto L472046; case 8: goto L47206d; case 9: goto L47206d; case 10: goto L47206d; case 11: goto L47206d; case 12: goto L47206d; case 13: goto L47206d; case 14: goto L47206d; default: __builtin_trap(); }  // @10_471ff0
  L47201f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_471ff0
  p0_ = ecx;  // @13_471ff0
  ecx = esi;  // @14_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 1004)))(ecx, (u32)(p0_));  // @15_471ff0
  ecx = edx = 0;  // @16_471ff0
  edi = eax;  // @17_471ff0
  p1_ = ebx;  // @18_471ff0
  ecx = edi;  // @19_471ff0
  eax = ext_4870b0_thiscall2(ecx, (u32)(p1_));  // @20_471ff0
  ecx = edx = 0;  // @21_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_471ff0
  ecx = esi;  // @23_471ff0
  p2_ = edi;  // @24_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p2_));  // @25_471ff0
  ecx = edx = 0;  // @26_471ff0
  return eax;  // @27_471ff0
  L472046:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @29_471ff0
  p3_ = ecx;  // @30_471ff0
  ecx = esi;  // @31_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1004)))(ecx, (u32)(p3_));  // @32_471ff0
  ecx = edx = 0;  // @33_471ff0
  edi = eax;  // @34_471ff0
  p4_ = ebx;  // @35_471ff0
  ecx = edi;  // @36_471ff0
  eax = ext_4870b0_thiscall2(ecx, (u32)(p4_));  // @37_471ff0
  ecx = edx = 0;  // @38_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_471ff0
  ecx = esi;  // @40_471ff0
  p5_ = edi;  // @41_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p5_));  // @42_471ff0
  ecx = edx = 0;  // @43_471ff0
  return eax;  // @44_471ff0
  L47206d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_471ff0
  p6_ = ecx;  // @47_471ff0
  ecx = esi;  // @48_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1004)))(ecx, (u32)(p6_));  // @49_471ff0
  ecx = edx = 0;  // @50_471ff0
  edi = eax;  // @51_471ff0
  ecx = esi;  // @52_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_471ff0
  p7_ = edi;  // @54_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p7_));  // @55_471ff0
  ecx = edx = 0;  // @56_471ff0
  return eax;  // @57_471ff0
  L47208c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @59_471ff0
  if ((eax & eax) == 0) goto L472099;  // @60_471ff0
  eax = ((u32(STDCALL *)(void))(eax))();  // @61_471ff0
  ecx = edx = 0;  // @62_471ff0
  goto L47209a;  // @63_471ff0
  L472099:;
  __builtin_trap();  // @65_471ff0
  L47209a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @67_471ff0
  ecx = esi;  // @68_471ff0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @69_471ff0
  p8_ = edi;  // @70_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p8_));  // @71_471ff0
  ecx = edx = 0;  // @72_471ff0
  return eax;  // @73_471ff0
}
PCREG(471ff0, lifted_471ff0);

extern "C" u32 THISCALL lifted_470b00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_470b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_470b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @2_470b00
  ecx = edx = 0;  // @3_470b00
  if ((eax & eax) != 0) goto L470b4b;  // @4_470b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_470b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_470b00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(2043));  // @7_470b00
  ecx = edx = 0;  // @8_470b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_470b00
  edx = (u32)(6801640);  // @10_470b00
  if ((ecx & ecx) != 0) edx = ecx;  // @11_470b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_470b00
  p0_ = edx;  // @13_470b00
  p1_ = eax;  // @14_470b00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 48)))(ecx, (u32)(p1_), (u32)(6851364), (u32)(p0_));  // @15_470b00
  ecx = edx = 0;  // @16_470b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_470b00
  return eax;  // @18_470b00
  L470b4b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_470b00
  L470b50:;
  if (esi > (u32)(3)) goto L470b5c;  // @22_470b00
  switch (esi) { case 0: goto L470ba1; case 1: goto L470bb8; case 2: goto L470b8d; case 3: goto L470b76; default: __builtin_trap(); }  // @23_470b00
  L470b5c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_470b00
  ecx = edi;  // @26_470b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @27_470b00
  ecx = edx = 0;  // @28_470b00
  ecx = esi;  // @29_470b00
  eax = (eax >> (ecx & 0xff));  // @30_470b00
  if (((eax & 0xff) & (u32)(1)) == 0) goto L470b50;  // @31_470b00
  eax = esi;  // @32_470b00
  return eax;  // @33_470b00
  L470b76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_470b00
  ecx = edi;  // @36_470b00
  esi = (u32)(2);  // @37_470b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @38_470b00
  ecx = edx = 0;  // @39_470b00
  ecx = esi;  // @40_470b00
  eax = (eax >> (ecx & 0xff));  // @41_470b00
  if (((eax & 0xff) & (u32)(1)) != 0) goto L470bcf;  // @42_470b00
  L470b8d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_470b00
  ecx = edi;  // @45_470b00
  esi = 0;  // @46_470b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @47_470b00
  ecx = edx = 0;  // @48_470b00
  ecx = esi;  // @49_470b00
  eax = (eax >> (ecx & 0xff));  // @50_470b00
  if (((eax & 0xff) & (u32)(1)) != 0) goto L470bcf;  // @51_470b00
  L470ba1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @53_470b00
  ecx = edi;  // @54_470b00
  esi = (u32)(1);  // @55_470b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @56_470b00
  ecx = edx = 0;  // @57_470b00
  ecx = esi;  // @58_470b00
  eax = (eax >> (ecx & 0xff));  // @59_470b00
  if (((eax & 0xff) & (u32)(1)) != 0) goto L470bcf;  // @60_470b00
  L470bb8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_470b00
  ecx = edi;  // @63_470b00
  esi = (u32)(3);  // @64_470b00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @65_470b00
  ecx = edx = 0;  // @66_470b00
  ecx = esi;  // @67_470b00
  eax = (eax >> (ecx & 0xff));  // @68_470b00
  if (((eax & 0xff) & (u32)(1)) == 0) goto L470b76;  // @69_470b00
  L470bcf:;
  eax = esi;  // @71_470b00
  return eax;  // @72_470b00
}
PCREG(470b00, lifted_470b00);

extern "C" u32 THISCALL lifted_486aa0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_486aa0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_486aa0
  ecx = edi;  // @2_486aa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @3_486aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_486aa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 816)))(ecx);  // @5_486aa0
  ecx = edx = 0;  // @6_486aa0
  if (eax > (u32)(12)) goto L486b33;  // @7_486aa0
  switch (eax) { case 0: goto L486ac7; case 1: goto L486b64; case 2: goto L486ad0; case 3: goto L486ad9; case 4: goto L486ad9; case 5: goto L486afd; case 6: goto L486aed; case 7: goto L486b1b; case 8: goto L486b33; case 9: goto L486b33; case 10: goto L486b33; case 11: goto L486b2b; case 12: goto L486b2b; default: __builtin_trap(); }  // @8_486aa0
  L486ac7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @10_486aa0
  return eax;  // @11_486aa0
  L486ad0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @13_486aa0
  return eax;  // @14_486aa0
  L486ad9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @16_486aa0
  if ((eax & eax) != 0) goto L486b67;  // @17_486aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @18_486aa0
  return eax;  // @19_486aa0
  L486aed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @21_486aa0
  if ((eax & eax) != 0) goto L486b67;  // @22_486aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @23_486aa0
  return eax;  // @24_486aa0
  L486afd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @26_486aa0
  { u32 v = (u32)((u32)(1054951342)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @27_486aa0
  { u32 v = (u32)((u32)(1059984507)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @28_486aa0
  if ((eax & eax) != 0) goto L486b67;  // @29_486aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @30_486aa0
  return eax;  // @31_486aa0
  L486b1b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @33_486aa0
  if ((eax & eax) != 0) goto L486b67;  // @34_486aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @35_486aa0
  return eax;  // @36_486aa0
  L486b2b:;
  eax = 0;  // @38_486aa0
  return eax;  // @39_486aa0
  L486b33:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @41_486aa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_486aa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6868420), (u32)(639));  // @43_486aa0
  ecx = edx = 0;  // @44_486aa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @45_486aa0
  edx = (u32)(6801640);  // @46_486aa0
  if ((ecx & ecx) != 0) edx = ecx;  // @47_486aa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_486aa0
  p0_ = edx;  // @49_486aa0
  p1_ = eax;  // @50_486aa0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p1_), (u32)(6868560), (u32)(p0_));  // @51_486aa0
  ecx = edx = 0;  // @52_486aa0
  L486b64:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @54_486aa0
  L486b67:;
  return eax;  // @56_486aa0
}
PCREG(486aa0, lifted_486aa0);

extern "C" u32 THISCALL lifted_486cc0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_486cc0
  esi = ecx;  // @1_486cc0
  ecx = edi;  // @2_486cc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_486cc0
  eax = (u32)(esi + 44);  // @4_486cc0
  p0_ = eax;  // @5_486cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(p0_));  // @6_486cc0
  ecx = edx = 0;  // @7_486cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_486cc0
  ecx = (u32)(EBP + 11);  // @9_486cc0
  p1_ = ecx;  // @10_486cc0
  ecx = edi;  // @11_486cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(p1_));  // @12_486cc0
  ecx = edx = 0;  // @13_486cc0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; }) == (u32)(0)) goto L486d6e;  // @14_486cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_486cc0
  ecx = (u32)(EBP - 4);  // @16_486cc0
  p2_ = ecx;  // @17_486cc0
  ecx = edi;  // @18_486cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(p2_));  // @19_486cc0
  ecx = edx = 0;  // @20_486cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @21_486cc0
  eax = (eax - 1);  // @22_486cc0
  if (eax > (u32)(5)) goto L486d5a;  // @23_486cc0
  switch (eax) { case 0: goto L486d06; case 1: goto L486d14; case 2: goto L486d22; case 3: goto L486d30; case 4: goto L486d3e; case 5: goto L486d4c; default: __builtin_trap(); }  // @24_486cc0
  L486d06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @26_486cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @27_486cc0
  return eax;  // @28_486cc0
  L486d14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @30_486cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @31_486cc0
  return eax;  // @32_486cc0
  L486d22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @34_486cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @35_486cc0
  return eax;  // @36_486cc0
  L486d30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @38_486cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @39_486cc0
  return eax;  // @40_486cc0
  L486d3e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @42_486cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @43_486cc0
  return eax;  // @44_486cc0
  L486d4c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @46_486cc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @47_486cc0
  return eax;  // @48_486cc0
  L486d5a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @50_486cc0
  if ((eax & eax) == 0) goto L486d6d;  // @51_486cc0
  eax = ((u32(STDCALL *)(void))(eax))();  // @52_486cc0
  ecx = edx = 0;  // @53_486cc0
  return eax;  // @54_486cc0
  L486d6d:;
  __builtin_trap();  // @56_486cc0
  L486d6e:;
  return eax;  // @58_486cc0
}
PCREG(486cc0, lifted_486cc0);

extern "C" u32 THISCALL lifted_4e11e0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4e11e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4e11e0
  esi = ecx;  // @2_4e11e0
  L4e11f0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @4_4e11e0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @5_4e11e0
  if ((eax & 0xff) == (u32)(255)) goto L4e11ff;  // @6_4e11e0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @7_4e11e0
  if ((eax & 0xff) == (u32)(3)) goto L4e1244;  // @8_4e11e0
  L4e11ff:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @10_4e11e0
  if ((eax & 0xff) == (u32)(255)) goto L4e120b;  // @11_4e11e0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @12_4e11e0
  if ((eax & 0xff) == (u32)(10)) goto L4e1244;  // @13_4e11e0
  L4e120b:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @15_4e11e0
  if ((eax & 0xff) == (u32)(255)) goto L4e1217;  // @16_4e11e0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @17_4e11e0
  if ((eax & 0xff) == (u32)(11)) goto L4e1244;  // @18_4e11e0
  L4e1217:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @20_4e11e0
  if ((eax & 0xff) == (u32)(255)) goto L4e1223;  // @21_4e11e0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @22_4e11e0
  if ((eax & 0xff) == (u32)(8)) goto L4e1244;  // @23_4e11e0
  L4e1223:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @25_4e11e0
  if ((eax & eax) == 0) goto L4e1230;  // @26_4e11e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @27_4e11e0
  ecx = edx = 0;  // @28_4e11e0
  goto L4e1231;  // @29_4e11e0
  L4e1230:;
  __builtin_trap();  // @31_4e11e0
  L4e1231:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @33_4e11e0
  p0_ = eax;  // @34_4e11e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_4e11e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 36)))((u32)(p0_), (u32)(6910200));  // @36_4e11e0
  ecx = edx = 0;  // @37_4e11e0
  L4e1244:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @39_4e11e0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @40_4e11e0
  if ((eax & 0xff) != (u32)(255)) goto L4e1251;  // @41_4e11e0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (eax & 0xff))) & 0xff);  // @42_4e11e0
  goto L4e1253;  // @43_4e11e0
  L4e1251:;
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @45_4e11e0
  L4e1253:;
  eax = (eax & 0xff);  // @47_4e11e0
  eax = (eax + (u32)(-3));  // @48_4e11e0
  if (eax > (u32)(8)) goto L4e126c;  // @49_4e11e0
  switch (eax) { case 0: goto L4e1265; case 1: goto L4e126c; case 2: goto L4e126c; case 3: goto L4e126c; case 4: goto L4e126c; case 5: goto L4e1265; case 6: goto L4e126c; case 7: goto L4e1265; case 8: goto L4e1265; default: __builtin_trap(); }  // @50_4e11e0
  L4e1265:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @52_4e11e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @53_4e11e0
  goto L4e128d;  // @54_4e11e0
  L4e126c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @56_4e11e0
  if ((eax & eax) == 0) goto L4e1279;  // @57_4e11e0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @58_4e11e0
  ecx = edx = 0;  // @59_4e11e0
  goto L4e127a;  // @60_4e11e0
  L4e1279:;
  __builtin_trap();  // @62_4e11e0
  L4e127a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @64_4e11e0
  p1_ = eax;  // @65_4e11e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @66_4e11e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 36)))((u32)(p1_), (u32)(6910200));  // @67_4e11e0
  ecx = edx = 0;  // @68_4e11e0
  L4e128d:;
  ecx = esi;  // @70_4e11e0
  eax = ext_4e1590_thiscall1(ecx);  // @71_4e11e0
  ecx = edx = 0;  // @72_4e11e0
  eax = (eax + 1);  // @73_4e11e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @74_4e11e0
  if (ebx == (u32)(1)) goto L4e12a6;  // @75_4e11e0
  ebx = (ebx - 1);  // @76_4e11e0
  edi = (edi + (u32)(4));  // @77_4e11e0
  goto L4e11f0;  // @78_4e11e0
  L4e12a6:;
  return eax;  // @80_4e11e0
}
PCREG(4e11e0, lifted_4e11e0);

extern "C" u32 THISCALL lifted_622980(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_622980
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_622980
  p0_ = esi;  // @2_622980
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_622980
  p1_ = edi;  // @4_622980
  L622990:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @6_622980
  edi = (u32)(edx + 1);  // @7_622980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_622980
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L6229a3;  // @9_622980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @10_622980
  goto L6229ad;  // @11_622980
  L6229a3:;
  p2_ = eax;  // @13_622980
  p3_ = ecx;  // @14_622980
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @15_622980
  ecx = edx = 0;  // @16_622980
  L6229ad:;
  eax = (eax - (u32)(5));  // @18_622980
  if (eax > (u32)(24)) goto L622a0d;  // @19_622980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6433372), sizeof v); (u32)v; });  // @20_622980
  switch (eax) { case 0: goto L6229d6; case 1: goto L6229cc; case 2: goto L6229c3; case 3: goto L6229f3; case 4: goto L622a0d; default: __builtin_trap(); }  // @21_622980
  L6229c3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @23_622980
  edx = edi;  // @24_622980
  esi = (esi + 1);  // @25_622980
  if ((ecx & 0xff) != (eax & 0xff)) goto L6229ec;  // @26_622980
  L6229cc:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @28_622980
  edx = (edx + 1);  // @29_622980
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @30_622980
  esi = (esi + 1);  // @31_622980
  if ((ecx & 0xff) != (eax & 0xff)) goto L6229ec;  // @32_622980
  L6229d6:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @34_622980
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) goto L6229ec;  // @35_622980
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @36_622980
  edx = (edx + (u32)(2));  // @37_622980
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @38_622980
  esi = (esi + (u32)(2));  // @39_622980
  if ((ecx & 0xff) == (eax & 0xff)) goto L622990;  // @40_622980
  L6229ec:;
  eax = 0;  // @42_622980
  return eax;  // @43_622980
  L6229f3:;
  edx = edi;  // @45_622980
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (ecx & 0xff)) goto L6229ec;  // @46_622980
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @47_622980
  esi = (esi + (u32)(2));  // @48_622980
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @49_622980
  edx = (edx + 1);  // @50_622980
  if ((ecx & 0xff) == (eax & 0xff)) goto L622990;  // @51_622980
  eax = 0;  // @52_622980
  return eax;  // @53_622980
  L622a0d:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @55_622980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; });  // @56_622980
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L622a1e;  // @57_622980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @58_622980
  goto L622a28;  // @59_622980
  L622a1e:;
  p4_ = eax;  // @61_622980
  p5_ = ecx;  // @62_622980
  eax = ext_62c640_cdecl2((u32)(p5_), (u32)(p4_));  // @63_622980
  ecx = edx = 0;  // @64_622980
  L622a28:;
  eax = (eax - (u32)(5));  // @66_622980
  if (eax > (u32)(24)) goto L622a3e;  // @67_622980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6433408), sizeof v); (u32)v; });  // @68_622980
  switch (eax) { case 0: goto L6229ec; case 1: goto L622a3e; default: __builtin_trap(); }  // @69_622980
  L622a3e:;
  eax = (u32)(1);  // @71_622980
  return eax;  // @72_622980
}
PCREG(622980, lifted_622980);

extern "C" u32 THISCALL lifted_6253b0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6253b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6253b0
  p0_ = esi;  // @2_6253b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_6253b0
  p1_ = edi;  // @4_6253b0
  L6253c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @6_6253b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_6253b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6253d3;  // @8_6253b0
  eax = (ecx & 0xff);  // @9_6253b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @10_6253b0
  goto L6253dd;  // @11_6253b0
  L6253d3:;
  p2_ = ecx;  // @13_6253b0
  p3_ = eax;  // @14_6253b0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @15_6253b0
  ecx = edx = 0;  // @16_6253b0
  L6253dd:;
  eax = (eax - (u32)(5));  // @18_6253b0
  if (eax > (u32)(24)) goto L625441;  // @19_6253b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6444176), sizeof v); (u32)v; });  // @20_6253b0
  switch (eax) { case 0: goto L625405; case 1: goto L6253fb; case 2: goto L6253f3; case 3: goto L625424; case 4: goto L625441; default: __builtin_trap(); }  // @21_6253b0
  L6253f3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @23_6253b0
  edx = (edx + 1);  // @24_6253b0
  esi = (esi + 1);  // @25_6253b0
  if ((ecx & 0xff) != (eax & 0xff)) goto L62541d;  // @26_6253b0
  L6253fb:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @28_6253b0
  edx = (edx + 1);  // @29_6253b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @30_6253b0
  esi = (esi + 1);  // @31_6253b0
  if ((ecx & 0xff) != (eax & 0xff)) goto L62541d;  // @32_6253b0
  L625405:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @34_6253b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @35_6253b0
  if ((ecx & 0xff) != (eax & 0xff)) goto L62541d;  // @36_6253b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @37_6253b0
  edx = (edx + (u32)(2));  // @38_6253b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @39_6253b0
  esi = (esi + (u32)(2));  // @40_6253b0
  if ((ecx & 0xff) == (eax & 0xff)) goto L6253c0;  // @41_6253b0
  L62541d:;
  eax = 0;  // @43_6253b0
  return eax;  // @44_6253b0
  L625424:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @46_6253b0
  if ((eax & 0xff) != (ecx & 0xff)) goto L62541d;  // @47_6253b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @48_6253b0
  esi = (esi + (u32)(2));  // @49_6253b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @50_6253b0
  edx = (edx + (u32)(2));  // @51_6253b0
  if ((ecx & 0xff) == (eax & 0xff)) goto L6253c0;  // @52_6253b0
  eax = 0;  // @53_6253b0
  return eax;  // @54_6253b0
  L625441:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @56_6253b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @57_6253b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L625452;  // @58_6253b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @59_6253b0
  goto L62545c;  // @60_6253b0
  L625452:;
  p4_ = eax;  // @62_6253b0
  p5_ = ecx;  // @63_6253b0
  eax = ext_62c640_cdecl2((u32)(p5_), (u32)(p4_));  // @64_6253b0
  ecx = edx = 0;  // @65_6253b0
  L62545c:;
  eax = (eax - (u32)(5));  // @67_6253b0
  if (eax > (u32)(24)) goto L625472;  // @68_6253b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6444212), sizeof v); (u32)v; });  // @69_6253b0
  switch (eax) { case 0: goto L62541d; case 1: goto L625472; default: __builtin_trap(); }  // @70_6253b0
  L625472:;
  eax = (u32)(1);  // @72_6253b0
  return eax;  // @73_6253b0
}
PCREG(6253b0, lifted_6253b0);

extern "C" u32 THISCALL lifted_4d24e0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d24e0
  eax = ecx;  // @1_4d24e0
  p0_ = ebx;  // @2_4d24e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4d24e0
  eax = ext_4d2c00_stdcall1((u32)(p0_));  // @4_4d24e0
  ecx = edx = 0;  // @5_4d24e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_4d24e0
  edi = eax;  // @7_4d24e0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) & edx) != 0) goto L4d2514;  // @8_4d24e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_4d24e0
  p1_ = ebx;  // @10_4d24e0
  p2_ = ecx;  // @11_4d24e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4d24e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 36)))((u32)(p2_), (u32)(6906828), (u32)(p1_));  // @13_4d24e0
  ecx = edx = 0;  // @14_4d24e0
  L4d2514:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @16_4d24e0
  eax = (u32)(EBP + 16);  // @17_4d24e0
  ecx = ebx;  // @18_4d24e0
  if (edx != (u32)(5)) eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @19_4d24e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_4d24e0
  esi = (u32)(ecx + 1);  // @21_4d24e0
  L4d2530:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @23_4d24e0
  ecx = (ecx + 1);  // @24_4d24e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d2530;  // @25_4d24e0
  ecx = (ecx - esi);  // @26_4d24e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @27_4d24e0
  eax = (u32)(ecx + 1);  // @28_4d24e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @29_4d24e0
  if ((esi & esi) != 0) goto L4d258a;  // @30_4d24e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @31_4d24e0
  if ((esi & esi) != 0) goto L4d258a;  // @32_4d24e0
  eax = (u32)(edx - 12);  // @33_4d24e0
  if (eax > (u32)(5)) goto L4d2577;  // @34_4d24e0
  switch (eax) { case 0: goto L4d255c; case 1: goto L4d2577; case 2: goto L4d255c; case 3: goto L4d2570; case 4: goto L4d2577; case 5: goto L4d2570; default: __builtin_trap(); }  // @35_4d24e0
  L4d255c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @37_4d24e0
  edx = (u32)(ecx + 1);  // @38_4d24e0
  L4d2562:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @40_4d24e0
  ecx = (ecx + 1);  // @41_4d24e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d2562;  // @42_4d24e0
  ecx = (ecx - edx);  // @43_4d24e0
  esi = (u32)(ecx + 1);  // @44_4d24e0
  goto L4d258a;  // @45_4d24e0
  L4d2570:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_4d24e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_4d24e0
  goto L4d258a;  // @49_4d24e0
  L4d2577:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @51_4d24e0
  p3_ = eax;  // @52_4d24e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @53_4d24e0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 36)))((u32)(p3_), (u32)(6906884));  // @54_4d24e0
  ecx = edx = 0;  // @55_4d24e0
  L4d258a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @57_4d24e0
  ecx = 0;  // @58_4d24e0
  eax = (u32)(7240248);  // @59_4d24e0
  L4d2594:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == edx) goto L4d25a7;  // @61_4d24e0
  eax = (eax + (u32)(20));  // @62_4d24e0
  ecx = (ecx + 1);  // @63_4d24e0
  if (eax != (u32)(7240608)) goto L4d2594;  // @64_4d24e0
  ecx = 0;  // @65_4d24e0
  goto L4d25b1;  // @66_4d24e0
  L4d25a7:;
  eax = (u32)(ecx + ecx*4);  // @68_4d24e0
  ecx = (u32)(eax*4 + 7240240);  // @69_4d24e0
  L4d25b1:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @71_4d24e0
  p4_ = esi;  // @72_4d24e0
  p5_ = ecx;  // @73_4d24e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @74_4d24e0
  ecx = edx;  // @75_4d24e0
  p6_ = ebx;  // @76_4d24e0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(p6_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @77_4d24e0
  ecx = edx = 0;  // @78_4d24e0
  return eax;  // @79_4d24e0
}
PCREG(4d24e0, lifted_4d24e0);

extern "C" u32 lifted_627520(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_627520
  p0_ = ebx;  // @1_627520
  p1_ = esi;  // @2_627520
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_627520
  p2_ = edi;  // @4_627520
  if (ecx == esi) goto L62758e;  // @5_627520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L6275f3;  // @6_627520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(45)) goto L6275f3;  // @7_627520
  ecx = (ecx + (u32)(2));  // @8_627520
  if (ecx == esi) goto L62758e;  // @9_627520
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_627520
  edx = esi;  // @11_627520
  edx = (edx - ecx);  // @12_627520
  L627551:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @14_627520
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @15_627520
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L627562;  // @16_627520
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @17_627520
  goto L62756c;  // @18_627520
  L627562:;
  p3_ = eax;  // @20_627520
  p4_ = ebx;  // @21_627520
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @22_627520
  ecx = edx = 0;  // @23_627520
  L62756c:;
  if (eax > (u32)(27)) goto L627584;  // @25_627520
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6452760), sizeof v); (u32)v; });  // @26_627520
  switch (eax) { case 0: goto L6275f3; case 1: goto L62757f; case 2: goto L627596; case 3: goto L6275a3; case 4: goto L6275b0; case 5: goto L627584; default: __builtin_trap(); }  // @27_627520
  L62757f:;
  if ((s32)edx < (s32)(u32)(2)) goto L6275e9;  // @29_627520
  L627584:;
  ecx = (ecx + (u32)(2));  // @31_627520
  edx = (edx - (u32)(2));  // @32_627520
  L62758a:;
  if (ecx != esi) goto L627551;  // @34_627520
  L62758e:;
  eax = (eax | (u32)(4294967295));  // @36_627520
  return eax;  // @37_627520
  L627596:;
  if ((s32)edx < (s32)(u32)(3)) goto L6275e9;  // @39_627520
  ecx = (ecx + (u32)(3));  // @40_627520
  edx = (edx - (u32)(3));  // @41_627520
  goto L62758a;  // @42_627520
  L6275a3:;
  if ((s32)edx < (s32)(u32)(4)) goto L6275e9;  // @44_627520
  ecx = (ecx + (u32)(4));  // @45_627520
  edx = (edx - (u32)(4));  // @46_627520
  goto L62758a;  // @47_627520
  L6275b0:;
  ecx = (ecx + (u32)(2));  // @49_627520
  edx = (edx - (u32)(2));  // @50_627520
  if (ecx == esi) goto L62758e;  // @51_627520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L62758a;  // @52_627520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(45)) goto L62758a;  // @53_627520
  ecx = (ecx + (u32)(2));  // @54_627520
  if (ecx == esi) goto L62758e;  // @55_627520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L6275f3;  // @56_627520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(62)) goto L6275f3;  // @57_627520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @58_627520
  ecx = (ecx + (u32)(2));  // @59_627520
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @60_627520
  eax = (u32)(13);  // @61_627520
  return eax;  // @62_627520
  L6275e9:;
  eax = (u32)(4294967294);  // @64_627520
  return eax;  // @65_627520
  L6275f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @67_627520
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_627520
  eax = 0;  // @69_627520
  return eax;  // @70_627520
}
PCREG(627520, lifted_627520);

extern "C" u32 lifted_629580(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_629580
  p0_ = ebx;  // @1_629580
  p1_ = esi;  // @2_629580
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_629580
  p2_ = edi;  // @4_629580
  if (ecx == esi) goto L6295ee;  // @5_629580
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L629653;  // @6_629580
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(45)) goto L629653;  // @7_629580
  ecx = (ecx + (u32)(2));  // @8_629580
  if (ecx == esi) goto L6295ee;  // @9_629580
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_629580
  edx = esi;  // @11_629580
  edx = (edx - ecx);  // @12_629580
  L6295b1:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @14_629580
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_629580
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6295c2;  // @16_629580
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @17_629580
  goto L6295cc;  // @18_629580
  L6295c2:;
  p3_ = eax;  // @20_629580
  p4_ = ebx;  // @21_629580
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @22_629580
  ecx = edx = 0;  // @23_629580
  L6295cc:;
  if (eax > (u32)(27)) goto L6295e4;  // @25_629580
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6461048), sizeof v); (u32)v; });  // @26_629580
  switch (eax) { case 0: goto L629653; case 1: goto L6295df; case 2: goto L6295f6; case 3: goto L629603; case 4: goto L629610; case 5: goto L6295e4; default: __builtin_trap(); }  // @27_629580
  L6295df:;
  if ((s32)edx < (s32)(u32)(2)) goto L629649;  // @29_629580
  L6295e4:;
  ecx = (ecx + (u32)(2));  // @31_629580
  edx = (edx - (u32)(2));  // @32_629580
  L6295ea:;
  if (ecx != esi) goto L6295b1;  // @34_629580
  L6295ee:;
  eax = (eax | (u32)(4294967295));  // @36_629580
  return eax;  // @37_629580
  L6295f6:;
  if ((s32)edx < (s32)(u32)(3)) goto L629649;  // @39_629580
  ecx = (ecx + (u32)(3));  // @40_629580
  edx = (edx - (u32)(3));  // @41_629580
  goto L6295ea;  // @42_629580
  L629603:;
  if ((s32)edx < (s32)(u32)(4)) goto L629649;  // @44_629580
  ecx = (ecx + (u32)(4));  // @45_629580
  edx = (edx - (u32)(4));  // @46_629580
  goto L6295ea;  // @47_629580
  L629610:;
  ecx = (ecx + (u32)(2));  // @49_629580
  edx = (edx - (u32)(2));  // @50_629580
  if (ecx == esi) goto L6295ee;  // @51_629580
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6295ea;  // @52_629580
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(45)) goto L6295ea;  // @53_629580
  ecx = (ecx + (u32)(2));  // @54_629580
  if (ecx == esi) goto L6295ee;  // @55_629580
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L629653;  // @56_629580
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(62)) goto L629653;  // @57_629580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @58_629580
  ecx = (ecx + (u32)(2));  // @59_629580
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @60_629580
  eax = (u32)(13);  // @61_629580
  return eax;  // @62_629580
  L629649:;
  eax = (u32)(4294967294);  // @64_629580
  return eax;  // @65_629580
  L629653:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @67_629580
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_629580
  eax = 0;  // @69_629580
  return eax;  // @70_629580
}
PCREG(629580, lifted_629580);

extern "C" u32 THISCALL lifted_4f8e20(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 271), sizeof v); (u32)v; });  // @1_4f8e20
  ecx = (u32)(ebx + 271);  // @2_4f8e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @3_4f8e20
  ecx = edx = 0;  // @4_4f8e20
  if ((eax & eax) != 0) goto L4f8e40;  // @5_4f8e20
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @6_4f8e20
  return eax;  // @7_4f8e20
  L4f8e40:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_4f8e20
  p0_ = edi;  // @10_4f8e20
  eax = (u32)(ecx - 8);  // @11_4f8e20
  if (eax > (u32)(32)) goto L4f8f20;  // @12_4f8e20
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5214036), sizeof v); (u32)v; });  // @13_4f8e20
  switch (eax) { case 0: goto L4f8e7d; case 1: goto L4f8f2b; case 2: goto L4f8e5e; case 3: goto L4f8ee4; case 4: goto L4f8f02; case 5: goto L4f8ef3; case 6: goto L4f8f11; case 7: goto L4f8f20; default: __builtin_trap(); }  // @14_4f8e20
  L4f8e5e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_4f8e20
  ecx = ebx;  // @17_4f8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 708)))(ecx, (u32)(p0_));  // @18_4f8e20
  ecx = edx = 0;  // @19_4f8e20
  p1_ = ebx;  // @20_4f8e20
  ecx = eax;  // @21_4f8e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_4f8e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 756)))(ecx, (u32)(p1_), (u32)(1));  // @23_4f8e20
  ecx = edx = 0;  // @24_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @25_4f8e20
  return eax;  // @26_4f8e20
  L4f8e7d:;
  ecx = (u32)(ebx + 143);  // @28_4f8e20
  eax = ext_4cc5f0_thiscall1(ecx);  // @29_4f8e20
  ecx = edx = 0;  // @30_4f8e20
  if ((eax & eax) == 0) goto L4f8f2b;  // @31_4f8e20
  p2_ = esi;  // @32_4f8e20
  ecx = (u32)(ebx + 143);  // @33_4f8e20
  eax = ext_4cc1d0_cdecl1((u32)(p2_));  // @34_4f8e20
  ecx = edx = 0;  // @35_4f8e20
  ecx = (u32)(ebx + 143);  // @36_4f8e20
  edi = (u32)(eax - 1);  // @37_4f8e20
  eax = ext_4cc5f0_thiscall1(ecx);  // @38_4f8e20
  ecx = edx = 0;  // @39_4f8e20
  ecx = (u32)(ebx + 143);  // @40_4f8e20
  edi = (edi + eax);  // @41_4f8e20
  eax = ext_4cc1d0_thiscall1(ecx);  // @42_4f8e20
  ecx = edx = 0;  // @43_4f8e20
  edx = edi;  // @44_4f8e20
  ecx = edi;  // @45_4f8e20
  edx = (edx - eax);  // @46_4f8e20
  eax = ext_4cc4d0_fastcall2(ecx, edx);  // @47_4f8e20
  ecx = edx = 0;  // @48_4f8e20
  ecx = (u32)(ebx + 143);  // @49_4f8e20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @50_4f8e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @51_4f8e20
  eax = ext_4cc1d0_thiscall1(ecx);  // @52_4f8e20
  ecx = edx = 0;  // @53_4f8e20
  p3_ = eax;  // @54_4f8e20
  ecx = ebx;  // @55_4f8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, (u32)(p3_));  // @56_4f8e20
  ecx = edx = 0;  // @57_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @58_4f8e20
  return eax;  // @59_4f8e20
  L4f8ee4:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 475), &v, sizeof v); }  // @61_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @62_4f8e20
  return eax;  // @63_4f8e20
  L4f8ef3:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 476), &v, sizeof v); }  // @65_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @66_4f8e20
  return eax;  // @67_4f8e20
  L4f8f02:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 477), &v, sizeof v); }  // @69_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_4f8e20
  return eax;  // @71_4f8e20
  L4f8f11:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 478), &v, sizeof v); }  // @73_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @74_4f8e20
  return eax;  // @75_4f8e20
  L4f8f20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @77_4f8e20
  p4_ = ecx;  // @78_4f8e20
  ecx = ebx;  // @79_4f8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 856)))(ecx, (u32)(p4_));  // @80_4f8e20
  ecx = edx = 0;  // @81_4f8e20
  L4f8f2b:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @83_4f8e20
  return eax;  // @84_4f8e20
}
PCREG(4f8e20, lifted_4f8e20);

extern "C" u32 THISCALL lifted_64ba70(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_64ba70
  esi = 0;  // @1_64ba70
  ebx = ecx;  // @2_64ba70
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @3_64ba70
  eax = (eax - 1);  // @4_64ba70
  if (eax > (u32)(6)) goto L64bb58;  // @5_64ba70
  switch (eax) { case 0: goto L64bb18; case 1: goto L64ba92; case 2: goto L64baad; case 3: goto L64bb03; case 4: goto L64bae1; case 5: goto L64bac8; case 6: goto L64baf2; default: __builtin_trap(); }  // @6_64ba70
  L64ba92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @8_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @9_64ba70
  if ((eax & eax) == 0) goto L64baa2;  // @10_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @11_64ba70
  esi = (esi + (u32)(90));  // @12_64ba70
  L64baa2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65877), sizeof v); (u32)v; });  // @14_64ba70
  goto L64bb31;  // @15_64ba70
  L64baad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @17_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @18_64ba70
  if ((eax & eax) == 0) goto L64baba;  // @19_64ba70
  esi = (u32)(eax + 90);  // @20_64ba70
  L64baba:;
  p0_ = edi;  // @22_64ba70
  eax = ext_64c1e0_thiscall2(ecx, (u32)(p0_));  // @23_64ba70
  ecx = edx = 0;  // @24_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65881), sizeof v); (u32)v; });  // @25_64ba70
  goto L64bb31;  // @26_64ba70
  L64bac8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @28_64ba70
  p1_ = edi;  // @29_64ba70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p1_));  // @30_64ba70
  ecx = edx = 0;  // @31_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65885), sizeof v); (u32)v; });  // @32_64ba70
  p2_ = edi;  // @33_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_64ba70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p2_));  // @35_64ba70
  ecx = edx = 0;  // @36_64ba70
  return eax;  // @37_64ba70
  L64bae1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @39_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65889), sizeof v); (u32)v; });  // @40_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @41_64ba70
  esi = (esi + (u32)(6));  // @42_64ba70
  goto L64bb31;  // @43_64ba70
  L64baf2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @45_64ba70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65897), sizeof v); (u32)v; });  // @46_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @47_64ba70
  esi = (esi + (u32)(64));  // @48_64ba70
  goto L64bb31;  // @49_64ba70
  L64bb03:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @51_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @52_64ba70
  if ((eax & eax) == 0) goto L64bb10;  // @53_64ba70
  esi = (u32)(eax + 90);  // @54_64ba70
  L64bb10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65901), sizeof v); (u32)v; });  // @56_64ba70
  goto L64bb31;  // @57_64ba70
  L64bb18:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @59_64ba70
  edi = (edi + (u32)(-4));  // @60_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @61_64ba70
  if ((eax & eax) == 0) goto L64bb2b;  // @62_64ba70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @63_64ba70
  esi = (esi + (u32)(90));  // @64_64ba70
  L64bb2b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65873), sizeof v); (u32)v; });  // @66_64ba70
  L64bb31:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_64ba70
  p3_ = edi;  // @69_64ba70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p3_));  // @70_64ba70
  ecx = edx = 0;  // @71_64ba70
  if ((esi & esi) == 0) goto L64bb6b;  // @72_64ba70
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_64ba70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 65649), sizeof v); (u32)v; });  // @74_64ba70
  ecx = (ecx & (u32)(4095));  // @75_64ba70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @76_64ba70
  return eax;  // @77_64ba70
  L64bb58:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @79_64ba70
  if ((eax & eax) == 0) goto L64bb6a;  // @80_64ba70
  eax = ((u32(STDCALL *)(void))(eax))();  // @81_64ba70
  ecx = edx = 0;  // @82_64ba70
  return eax;  // @83_64ba70
  L64bb6a:;
  __builtin_trap();  // @85_64ba70
  L64bb6b:;
  return eax;  // @87_64ba70
}
PCREG(64ba70, lifted_64ba70);

extern "C" u32 THISCALL lifted_627a80(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_627a80
  p0_ = esi;  // @1_627a80
  p1_ = edi;  // @2_627a80
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @3_627a80
  if (edx == edi) goto L627ad4;  // @4_627a80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_627a80
  esi = edi;  // @6_627a80
  esi = (esi - edx);  // @7_627a80
  L627a97:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @9_627a80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @10_627a80
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L627aa8;  // @11_627a80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @12_627a80
  goto L627ab2;  // @13_627a80
  L627aa8:;
  p2_ = eax;  // @15_627a80
  p3_ = ecx;  // @16_627a80
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @17_627a80
  ecx = edx = 0;  // @18_627a80
  L627ab2:;
  if (eax > (u32)(13)) goto L627aca;  // @20_627a80
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6454144), sizeof v); (u32)v; });  // @21_627a80
  switch (ecx) { case 0: goto L627b59; case 1: goto L627ac5; case 2: goto L627adc; case 3: goto L627ae9; case 4: goto L627af6; case 5: goto L627aca; default: __builtin_trap(); }  // @22_627a80
  L627ac5:;
  if ((s32)esi < (s32)(u32)(2)) goto L627b0f;  // @24_627a80
  L627aca:;
  edx = (edx + (u32)(2));  // @26_627a80
  esi = (esi - (u32)(2));  // @27_627a80
  L627ad0:;
  if (edx != edi) goto L627a97;  // @29_627a80
  L627ad4:;
  eax = (eax | (u32)(4294967295));  // @31_627a80
  return eax;  // @32_627a80
  L627adc:;
  if ((s32)esi < (s32)(u32)(3)) goto L627b0f;  // @34_627a80
  edx = (edx + (u32)(3));  // @35_627a80
  esi = (esi - (u32)(3));  // @36_627a80
  goto L627ad0;  // @37_627a80
  L627ae9:;
  if ((s32)esi < (s32)(u32)(4)) goto L627b0f;  // @39_627a80
  edx = (edx + (u32)(4));  // @40_627a80
  esi = (esi - (u32)(4));  // @41_627a80
  goto L627ad0;  // @42_627a80
  L627af6:;
  edx = (edx + (u32)(2));  // @44_627a80
  esi = (esi - (u32)(2));  // @45_627a80
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L627ad0;  // @46_627a80
  if (edx != edi) goto L627b19;  // @47_627a80
  eax = (u32)(4294967269);  // @48_627a80
  return eax;  // @49_627a80
  L627b0f:;
  eax = (u32)(4294967294);  // @51_627a80
  return eax;  // @52_627a80
  L627b19:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @54_627a80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @55_627a80
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @56_627a80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @57_627a80
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L627b2f;  // @58_627a80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @59_627a80
  goto L627b39;  // @60_627a80
  L627b2f:;
  p4_ = eax;  // @62_627a80
  p5_ = ecx;  // @63_627a80
  eax = ext_62c640_cdecl2((u32)(p5_), (u32)(p4_));  // @64_627a80
  ecx = edx = 0;  // @65_627a80
  L627b39:;
  eax = (eax - (u32)(9));  // @67_627a80
  if (eax > (u32)(21)) goto L627b5e;  // @68_627a80
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6454168), sizeof v); (u32)v; });  // @69_627a80
  switch (eax) { case 0: goto L627b4f; case 1: goto L627b5e; default: __builtin_trap(); }  // @70_627a80
  L627b4f:;
  eax = (u32)(27);  // @72_627a80
  return eax;  // @73_627a80
  L627b59:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @75_627a80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @76_627a80
  L627b5e:;
  eax = 0;  // @78_627a80
  return eax;  // @79_627a80
}
PCREG(627a80, lifted_627a80);

extern "C" u32 THISCALL lifted_629ae0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_629ae0
  p0_ = esi;  // @1_629ae0
  p1_ = edi;  // @2_629ae0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @3_629ae0
  if (edx == edi) goto L629b34;  // @4_629ae0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_629ae0
  esi = edi;  // @6_629ae0
  esi = (esi - edx);  // @7_629ae0
  L629af7:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @9_629ae0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @10_629ae0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L629b08;  // @11_629ae0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @12_629ae0
  goto L629b12;  // @13_629ae0
  L629b08:;
  p2_ = eax;  // @15_629ae0
  p3_ = ecx;  // @16_629ae0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @17_629ae0
  ecx = edx = 0;  // @18_629ae0
  L629b12:;
  if (eax > (u32)(13)) goto L629b2a;  // @20_629ae0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6462432), sizeof v); (u32)v; });  // @21_629ae0
  switch (ecx) { case 0: goto L629bb9; case 1: goto L629b25; case 2: goto L629b3c; case 3: goto L629b49; case 4: goto L629b56; case 5: goto L629b2a; default: __builtin_trap(); }  // @22_629ae0
  L629b25:;
  if ((s32)esi < (s32)(u32)(2)) goto L629b6f;  // @24_629ae0
  L629b2a:;
  edx = (edx + (u32)(2));  // @26_629ae0
  esi = (esi - (u32)(2));  // @27_629ae0
  L629b30:;
  if (edx != edi) goto L629af7;  // @29_629ae0
  L629b34:;
  eax = (eax | (u32)(4294967295));  // @31_629ae0
  return eax;  // @32_629ae0
  L629b3c:;
  if ((s32)esi < (s32)(u32)(3)) goto L629b6f;  // @34_629ae0
  edx = (edx + (u32)(3));  // @35_629ae0
  esi = (esi - (u32)(3));  // @36_629ae0
  goto L629b30;  // @37_629ae0
  L629b49:;
  if ((s32)esi < (s32)(u32)(4)) goto L629b6f;  // @39_629ae0
  edx = (edx + (u32)(4));  // @40_629ae0
  esi = (esi - (u32)(4));  // @41_629ae0
  goto L629b30;  // @42_629ae0
  L629b56:;
  edx = (edx + (u32)(2));  // @44_629ae0
  esi = (esi - (u32)(2));  // @45_629ae0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L629b30;  // @46_629ae0
  if (edx != edi) goto L629b79;  // @47_629ae0
  eax = (u32)(4294967269);  // @48_629ae0
  return eax;  // @49_629ae0
  L629b6f:;
  eax = (u32)(4294967294);  // @51_629ae0
  return eax;  // @52_629ae0
  L629b79:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @54_629ae0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @55_629ae0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @56_629ae0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @57_629ae0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L629b8f;  // @58_629ae0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @59_629ae0
  goto L629b99;  // @60_629ae0
  L629b8f:;
  p4_ = eax;  // @62_629ae0
  p5_ = ecx;  // @63_629ae0
  eax = ext_62c640_cdecl2((u32)(p5_), (u32)(p4_));  // @64_629ae0
  ecx = edx = 0;  // @65_629ae0
  L629b99:;
  eax = (eax - (u32)(9));  // @67_629ae0
  if (eax > (u32)(21)) goto L629bbe;  // @68_629ae0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6462456), sizeof v); (u32)v; });  // @69_629ae0
  switch (eax) { case 0: goto L629baf; case 1: goto L629bbe; default: __builtin_trap(); }  // @70_629ae0
  L629baf:;
  eax = (u32)(27);  // @72_629ae0
  return eax;  // @73_629ae0
  L629bb9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @75_629ae0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @76_629ae0
  L629bbe:;
  eax = 0;  // @78_629ae0
  return eax;  // @79_629ae0
}
PCREG(629ae0, lifted_629ae0);

extern "C" u32 THISCALL lifted_4d2700(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4d2700
  edx = 0;  // @1_4d2700
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_4d2700
  eax = (u32)(7240248);  // @3_4d2700
  L4d2714:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == esi) goto L4d2727;  // @5_4d2700
  eax = (eax + (u32)(20));  // @6_4d2700
  edx = (edx + 1);  // @7_4d2700
  if (eax != (u32)(7240608)) goto L4d2714;  // @8_4d2700
  esi = 0;  // @9_4d2700
  goto L4d2731;  // @10_4d2700
  L4d2727:;
  eax = (u32)(edx + edx*4);  // @12_4d2700
  esi = (u32)(eax*4 + 7240240);  // @13_4d2700
  L4d2731:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_4d2700
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_4d2700
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) & eax) != 0) goto L4d2750;  // @17_4d2700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @18_4d2700
  p0_ = edi;  // @19_4d2700
  p1_ = eax;  // @20_4d2700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @21_4d2700
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 36)))((u32)(p1_), (u32)(6906828), (u32)(p0_));  // @22_4d2700
  ecx = edx = 0;  // @23_4d2700
  L4d2750:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @25_4d2700
  ebx = (u32)(EBP + 20);  // @26_4d2700
  ecx = edi;  // @27_4d2700
  if (edx != (u32)(5)) ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @28_4d2700
  edi = (u32)(ecx + 1);  // @29_4d2700
  L4d2762:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @31_4d2700
  ecx = (ecx + 1);  // @32_4d2700
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d2762;  // @33_4d2700
  ecx = (ecx - edi);  // @34_4d2700
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @35_4d2700
  eax = (u32)(ecx + 1);  // @36_4d2700
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @37_4d2700
  if ((edi & edi) != 0) goto L4d27b8;  // @38_4d2700
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @39_4d2700
  if ((edi & edi) != 0) goto L4d27b8;  // @40_4d2700
  eax = (u32)(edx - 12);  // @41_4d2700
  if (eax > (u32)(5)) goto L4d27a5;  // @42_4d2700
  switch (eax) { case 0: goto L4d278e; case 1: goto L4d27a5; case 2: goto L4d278e; case 3: goto L4d27a1; case 4: goto L4d27a5; case 5: goto L4d27a1; default: __builtin_trap(); }  // @43_4d2700
  L4d278e:;
  ecx = ebx;  // @45_4d2700
  edx = (u32)(ecx + 1);  // @46_4d2700
  L4d2793:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @48_4d2700
  ecx = (ecx + 1);  // @49_4d2700
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d2793;  // @50_4d2700
  ecx = (ecx - edx);  // @51_4d2700
  edi = (u32)(ecx + 1);  // @52_4d2700
  goto L4d27b8;  // @53_4d2700
  L4d27a1:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_4d2700
  goto L4d27b8;  // @56_4d2700
  L4d27a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @58_4d2700
  p2_ = eax;  // @59_4d2700
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @60_4d2700
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 36)))((u32)(p2_), (u32)(6906884));  // @61_4d2700
  ecx = edx = 0;  // @62_4d2700
  L4d27b8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @64_4d2700
  ecx = 0;  // @65_4d2700
  eax = (u32)(7240248);  // @66_4d2700
  L4d27c2:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == edx) goto L4d27d5;  // @68_4d2700
  eax = (eax + (u32)(20));  // @69_4d2700
  ecx = (ecx + 1);  // @70_4d2700
  if (eax != (u32)(7240608)) goto L4d27c2;  // @71_4d2700
  ecx = 0;  // @72_4d2700
  goto L4d27df;  // @73_4d2700
  L4d27d5:;
  eax = (u32)(ecx + ecx*4);  // @75_4d2700
  ecx = (u32)(eax*4 + 7240240);  // @76_4d2700
  L4d27df:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @78_4d2700
  p3_ = ebx;  // @79_4d2700
  p4_ = edi;  // @80_4d2700
  p5_ = ecx;  // @81_4d2700
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @82_4d2700
  ecx = edx;  // @83_4d2700
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), (u32)(p5_), (u32)(p4_), (u32)(p3_));  // @84_4d2700
  ecx = edx = 0;  // @85_4d2700
  return eax;  // @86_4d2700
}
PCREG(4d2700, lifted_4d2700);

extern "C" u32 lifted_61dba0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_61dba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_61dba0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_61dba0
  p0_ = edi;  // @3_61dba0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_61dba0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; })) goto L61dbca;  // @5_61dba0
  ebx = (u32)(esi + 280);  // @6_61dba0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @7_61dba0
  edx = (u32)(esi + 284);  // @8_61dba0
  goto L61dbd3;  // @9_61dba0
  L61dbca:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 292), sizeof v); (u32)v; });  // @11_61dba0
  edx = (u32)(ebx + 4);  // @12_61dba0
  L61dbd3:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @14_61dba0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @15_61dba0
  ecx = (u32)(EBP + 8);  // @16_61dba0
  p1_ = ecx;  // @17_61dba0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @18_61dba0
  p2_ = edi;  // @19_61dba0
  p3_ = eax;  // @20_61dba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @21_61dba0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p3_), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @22_61dba0
  ecx = edx = 0;  // @23_61dba0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @24_61dba0
  eax = (eax + (u32)(4));  // @25_61dba0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_61dba0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @27_61dba0
  if (eax > (u32)(46)) goto L61dc76;  // @28_61dba0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6413468), sizeof v); (u32)v; });  // @29_61dba0
  switch (eax) { case 0: goto L61dc63; case 1: goto L61dc45; case 2: goto L61dc34; case 3: goto L61dc0d; case 4: goto L61dc76; default: __builtin_trap(); }  // @30_61dba0
  L61dc0d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L61dc23;  // @32_61dba0
  p4_ = edi;  // @33_61dba0
  p5_ = esi;  // @34_61dba0
  eax = ext_620cb0_cdecl4((u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @35_61dba0
  ecx = edx = 0;  // @36_61dba0
  L61dc23:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @38_61dba0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @39_61dba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @40_61dba0
  eax = 0;  // @41_61dba0
  return eax;  // @42_61dba0
  L61dc34:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_61dba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @45_61dba0
  eax = (u32)(4);  // @46_61dba0
  return eax;  // @47_61dba0
  L61dc45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @49_61dba0
  if ((eax & eax) == 0) goto L61dc57;  // @50_61dba0
  L61dc4c:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @52_61dba0
  eax = 0;  // @53_61dba0
  return eax;  // @54_61dba0
  L61dc57:;
  eax = (u32)(6);  // @56_61dba0
  return eax;  // @57_61dba0
  L61dc63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @59_61dba0
  if ((eax & eax) != 0) goto L61dc4c;  // @60_61dba0
  eax = (u32)(2);  // @61_61dba0
  return eax;  // @62_61dba0
  L61dc76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @64_61dba0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @65_61dba0
  eax = (u32)(23);  // @66_61dba0
  return eax;  // @67_61dba0
}
PCREG(61dba0, lifted_61dba0);

extern "C" u32 THISCALL lifted_5fbe50(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fbe50
  if ((ebx & ebx) == 0) goto L5fbf64;  // @1_5fbe50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5fbf64;  // @2_5fbe50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @3_5fbe50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 150), sizeof v); (u32)v; });  // @4_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @5_5fbe50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_5fbe50
  if (eax == esi) goto L5fbea0;  // @7_5fbe50
  L5fbe81:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @9_5fbe50
  ecx = (ecx + (u32)(60));  // @10_5fbe50
  if (edi == ecx) goto L5fbeb8;  // @11_5fbe50
  eax = (u32)(EBP - 8);  // @12_5fbe50
  p0_ = eax;  // @13_5fbe50
  ecx = (u32)(EBP + 8);  // @14_5fbe50
  eax = ext_5fb210_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @15_5fbe50
  ecx = edx = 0;  // @16_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5fbe50
  if (eax != esi) goto L5fbe81;  // @18_5fbe50
  L5fbea0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5fbe50
  if ((eax & eax) == 0) goto L5fbf61;  // @21_5fbe50
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5fbe50
  ecx = edx = 0;  // @23_5fbe50
  return eax;  // @24_5fbe50
  L5fbeb8:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @26_5fbe50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @27_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @28_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_5fbe50
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fbf62;  // @30_5fbe50
  ecx = eax;  // @31_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5fbe50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @34_5fbe50
  if ((edi & edi) == 0) goto L5fbf62;  // @35_5fbe50
  L5fbee3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_5fbe50
  eax = (eax + (u32)(-20));  // @38_5fbe50
  if (eax > (u32)(16)) goto L5fbf20;  // @39_5fbe50
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6274936), sizeof v); (u32)v; });  // @40_5fbe50
  switch (eax) { case 0: goto L5fbf2e; case 1: goto L5fbefb; case 2: goto L5fbf20; default: __builtin_trap(); }  // @41_5fbe50
  L5fbefb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @43_5fbe50
  edx = (u32)(EBP - 4);  // @44_5fbe50
  p1_ = edx;  // @45_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_5fbe50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(p1_));  // @47_5fbe50
  ecx = edx = 0;  // @48_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @49_5fbe50
  eax = ext_5fa1e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @50_5fbe50
  ecx = edx = 0;  // @51_5fbe50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @52_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @53_5fbe50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx), &v, sizeof v); }  // @54_5fbe50
  goto L5fbf2e;  // @55_5fbe50
  L5fbf20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_5fbe50
  if ((eax & eax) == 0) goto L5fbf2d;  // @58_5fbe50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @59_5fbe50
  ecx = edx = 0;  // @60_5fbe50
  goto L5fbf2e;  // @61_5fbe50
  L5fbf2d:;
  __builtin_trap();  // @63_5fbe50
  L5fbf2e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @65_5fbe50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @66_5fbe50
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L5fbf3f;  // @67_5fbe50
  eax = (u32)(ecx + 1);  // @68_5fbe50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @69_5fbe50
  L5fbf3f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @71_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @72_5fbe50
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fbf62;  // @73_5fbe50
  ecx = eax;  // @74_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @75_5fbe50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_5fbe50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @77_5fbe50
  if ((edi & edi) != 0) goto L5fbee3;  // @78_5fbe50
  return eax;  // @79_5fbe50
  L5fbf61:;
  __builtin_trap();  // @81_5fbe50
  L5fbf62:;
  L5fbf64:;
  return eax;  // @84_5fbe50
}
PCREG(5fbe50, lifted_5fbe50);

extern "C" u32 FASTCALL lifted_627640(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_627640
  p0_ = esi;  // @1_627640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_627640
  if (ecx != esi) goto L627654;  // @3_627640
  eax = (eax | (u32)(4294967295));  // @4_627640
  return eax;  // @5_627640
  L627654:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @7_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @8_627640
  p1_ = edi;  // @9_627640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_627640
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L627669;  // @11_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @12_627640
  goto L627673;  // @13_627640
  L627669:;
  p2_ = eax;  // @15_627640
  p3_ = edx;  // @16_627640
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @17_627640
  ecx = edx = 0;  // @18_627640
  L627673:;
  eax = (eax - (u32)(20));  // @20_627640
  if (eax > (u32)(7)) goto L627738;  // @21_627640
  switch (eax) { case 0: goto L62769b; case 1: goto L627738; case 2: goto L6276ac; case 3: goto L627738; case 4: goto L6276ac; case 5: goto L627738; case 6: goto L627738; case 7: goto L627686; case 8: goto L62772a; case 9: goto L6276e4; case 10: goto L6276f2; case 11: goto L627738; default: __builtin_trap(); }  // @22_627640
  L627686:;
  eax = (u32)(ecx + 2);  // @24_627640
  p4_ = esi;  // @25_627640
  p5_ = eax;  // @26_627640
  p6_ = edi;  // @27_627640
  eax = ext_627520_cdecl4((u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @28_627640
  ecx = edx = 0;  // @29_627640
  return eax;  // @30_627640
  L62769b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @32_627640
  ecx = (ecx + (u32)(2));  // @33_627640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_627640
  eax = (u32)(33);  // @35_627640
  return eax;  // @36_627640
  L6276ac:;
  ecx = (ecx + (u32)(2));  // @38_627640
  if (ecx == esi) goto L6276eb;  // @39_627640
  L6276b3:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @41_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @42_627640
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L6276c4;  // @43_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @44_627640
  goto L6276ce;  // @45_627640
  L6276c4:;
  p7_ = eax;  // @47_627640
  p8_ = edx;  // @48_627640
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @49_627640
  ecx = edx = 0;  // @50_627640
  L6276ce:;
  eax = (eax - (u32)(9));  // @52_627640
  if (eax > (u32)(21)) goto L627738;  // @53_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6453108), sizeof v); (u32)v; });  // @54_627640
  switch (eax) { case 0: goto L62772a; case 1: goto L6276e4; case 2: goto L6276f2; case 3: goto L627738; default: __builtin_trap(); }  // @55_627640
  L6276e4:;
  ecx = (ecx + (u32)(2));  // @57_627640
  if (ecx != esi) goto L6276b3;  // @58_627640
  L6276eb:;
  eax = (eax | (u32)(4294967295));  // @60_627640
  return eax;  // @61_627640
  L6276f2:;
  eax = (u32)(ecx + 2);  // @63_627640
  if (eax == esi) goto L6276eb;  // @64_627640
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @65_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 3), sizeof v); (u32)v; });  // @66_627640
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L62770a;  // @67_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @68_627640
  goto L627714;  // @69_627640
  L62770a:;
  p9_ = eax;  // @71_627640
  p10_ = edx;  // @72_627640
  eax = ext_62c640_cdecl2((u32)(p10_), (u32)(p9_));  // @73_627640
  ecx = edx = 0;  // @74_627640
  L627714:;
  eax = (eax - (u32)(9));  // @76_627640
  if (eax > (u32)(21)) goto L62772a;  // @77_627640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6453140), sizeof v); (u32)v; });  // @78_627640
  switch (eax) { case 0: goto L627738; case 1: goto L62772a; default: __builtin_trap(); }  // @79_627640
  L62772a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @81_627640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @82_627640
  eax = (u32)(16);  // @83_627640
  return eax;  // @84_627640
  L627738:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @86_627640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @87_627640
  eax = 0;  // @88_627640
  return eax;  // @89_627640
}
PCREG(627640, lifted_627640);

extern "C" u32 FASTCALL lifted_6296a0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6296a0
  p0_ = esi;  // @1_6296a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_6296a0
  if (ecx != esi) goto L6296b4;  // @3_6296a0
  eax = (eax | (u32)(4294967295));  // @4_6296a0
  return eax;  // @5_6296a0
  L6296b4:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @7_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_6296a0
  p1_ = edi;  // @9_6296a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_6296a0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L6296c9;  // @11_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @12_6296a0
  goto L6296d3;  // @13_6296a0
  L6296c9:;
  p2_ = eax;  // @15_6296a0
  p3_ = edx;  // @16_6296a0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @17_6296a0
  ecx = edx = 0;  // @18_6296a0
  L6296d3:;
  eax = (eax - (u32)(20));  // @20_6296a0
  if (eax > (u32)(7)) goto L629798;  // @21_6296a0
  switch (eax) { case 0: goto L6296fb; case 1: goto L629798; case 2: goto L62970c; case 3: goto L629798; case 4: goto L62970c; case 5: goto L629798; case 6: goto L629798; case 7: goto L6296e6; case 8: goto L62978a; case 9: goto L629744; case 10: goto L629752; case 11: goto L629798; default: __builtin_trap(); }  // @22_6296a0
  L6296e6:;
  eax = (u32)(ecx + 2);  // @24_6296a0
  p4_ = esi;  // @25_6296a0
  p5_ = eax;  // @26_6296a0
  p6_ = edi;  // @27_6296a0
  eax = ext_629580_cdecl4((u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @28_6296a0
  ecx = edx = 0;  // @29_6296a0
  return eax;  // @30_6296a0
  L6296fb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @32_6296a0
  ecx = (ecx + (u32)(2));  // @33_6296a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_6296a0
  eax = (u32)(33);  // @35_6296a0
  return eax;  // @36_6296a0
  L62970c:;
  ecx = (ecx + (u32)(2));  // @38_6296a0
  if (ecx == esi) goto L62974b;  // @39_6296a0
  L629713:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @41_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_6296a0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L629724;  // @43_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @44_6296a0
  goto L62972e;  // @45_6296a0
  L629724:;
  p7_ = eax;  // @47_6296a0
  p8_ = edx;  // @48_6296a0
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @49_6296a0
  ecx = edx = 0;  // @50_6296a0
  L62972e:;
  eax = (eax - (u32)(9));  // @52_6296a0
  if (eax > (u32)(21)) goto L629798;  // @53_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6461396), sizeof v); (u32)v; });  // @54_6296a0
  switch (eax) { case 0: goto L62978a; case 1: goto L629744; case 2: goto L629752; case 3: goto L629798; default: __builtin_trap(); }  // @55_6296a0
  L629744:;
  ecx = (ecx + (u32)(2));  // @57_6296a0
  if (ecx != esi) goto L629713;  // @58_6296a0
  L62974b:;
  eax = (eax | (u32)(4294967295));  // @60_6296a0
  return eax;  // @61_6296a0
  L629752:;
  eax = (u32)(ecx + 2);  // @63_6296a0
  if (eax == esi) goto L62974b;  // @64_6296a0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 3), sizeof v); (u32)v; })) & 0xff);  // @65_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @66_6296a0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L62976a;  // @67_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @68_6296a0
  goto L629774;  // @69_6296a0
  L62976a:;
  p9_ = eax;  // @71_6296a0
  p10_ = edx;  // @72_6296a0
  eax = ext_62c640_cdecl2((u32)(p10_), (u32)(p9_));  // @73_6296a0
  ecx = edx = 0;  // @74_6296a0
  L629774:;
  eax = (eax - (u32)(9));  // @76_6296a0
  if (eax > (u32)(21)) goto L62978a;  // @77_6296a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6461428), sizeof v); (u32)v; });  // @78_6296a0
  switch (eax) { case 0: goto L629798; case 1: goto L62978a; default: __builtin_trap(); }  // @79_6296a0
  L62978a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @81_6296a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @82_6296a0
  eax = (u32)(16);  // @83_6296a0
  return eax;  // @84_6296a0
  L629798:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @86_6296a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @87_6296a0
  eax = 0;  // @88_6296a0
  return eax;  // @89_6296a0
}
PCREG(6296a0, lifted_6296a0);

extern "C" u32 THISCALL lifted_5fb770(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fb770
  if ((ebx & ebx) == 0) goto L5fb888;  // @1_5fb770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5fb888;  // @2_5fb770
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @3_5fb770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 150), sizeof v); (u32)v; });  // @4_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @5_5fb770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_5fb770
  if (eax == esi) goto L5fb7bf;  // @7_5fb770
  L5fb7a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @9_5fb770
  ecx = (ecx + (u32)(60));  // @10_5fb770
  if (edi == ecx) goto L5fb7d7;  // @11_5fb770
  eax = (u32)(EBP - 4);  // @12_5fb770
  p0_ = eax;  // @13_5fb770
  ecx = (u32)(EBP + 8);  // @14_5fb770
  eax = ext_5fb210_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @15_5fb770
  ecx = edx = 0;  // @16_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5fb770
  if (eax != esi) goto L5fb7a0;  // @18_5fb770
  L5fb7bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5fb770
  if ((eax & eax) == 0) goto L5fb885;  // @21_5fb770
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5fb770
  ecx = edx = 0;  // @23_5fb770
  return eax;  // @24_5fb770
  L5fb7d7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @26_5fb770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @27_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @28_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_5fb770
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fb886;  // @30_5fb770
  ecx = eax;  // @31_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5fb770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @34_5fb770
  if ((edi & edi) == 0) goto L5fb886;  // @35_5fb770
  L5fb802:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_5fb770
  eax = (eax + (u32)(-20));  // @38_5fb770
  if (eax > (u32)(16)) goto L5fb844;  // @39_5fb770
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6273180), sizeof v); (u32)v; });  // @40_5fb770
  switch (eax) { case 0: goto L5fb852; case 1: goto L5fb81a; case 2: goto L5fb844; default: __builtin_trap(); }  // @41_5fb770
  L5fb81a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @43_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @44_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; });  // @45_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_5fb770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @47_5fb770
  ecx = edx = 0;  // @48_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @49_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @50_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @51_5fb770
  eax = ext_5f9db0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }));  // @52_5fb770
  ecx = edx = 0;  // @53_5fb770
  goto L5fb852;  // @54_5fb770
  L5fb844:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @56_5fb770
  if ((eax & eax) == 0) goto L5fb851;  // @57_5fb770
  eax = ((u32(STDCALL *)(void))(eax))();  // @58_5fb770
  ecx = edx = 0;  // @59_5fb770
  goto L5fb852;  // @60_5fb770
  L5fb851:;
  __builtin_trap();  // @62_5fb770
  L5fb852:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @64_5fb770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @65_5fb770
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L5fb863;  // @66_5fb770
  eax = (u32)(ecx + 1);  // @67_5fb770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @68_5fb770
  L5fb863:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @70_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @71_5fb770
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fb886;  // @72_5fb770
  ecx = eax;  // @73_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @74_5fb770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_5fb770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @76_5fb770
  if ((edi & edi) != 0) goto L5fb802;  // @77_5fb770
  return eax;  // @78_5fb770
  L5fb885:;
  __builtin_trap();  // @80_5fb770
  L5fb886:;
  L5fb888:;
  return eax;  // @83_5fb770
}
PCREG(5fb770, lifted_5fb770);

extern "C" u32 THISCALL lifted_5fda30(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fda30
  if ((ebx & ebx) == 0) goto L5fdb3e;  // @1_5fda30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5fdb3e;  // @2_5fda30
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @3_5fda30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 150), sizeof v); (u32)v; });  // @4_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @5_5fda30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @6_5fda30
  if (eax == esi) goto L5fda7f;  // @7_5fda30
  L5fda60:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @9_5fda30
  ecx = (ecx + (u32)(60));  // @10_5fda30
  if (edi == ecx) goto L5fda97;  // @11_5fda30
  eax = (u32)(EBP - 4);  // @12_5fda30
  p0_ = eax;  // @13_5fda30
  ecx = (u32)(EBP + 8);  // @14_5fda30
  eax = ext_5fb210_thiscall3(ecx, (u32)(p0_), (u32)(0));  // @15_5fda30
  ecx = edx = 0;  // @16_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_5fda30
  if (eax != esi) goto L5fda60;  // @18_5fda30
  L5fda7f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_5fda30
  if ((eax & eax) == 0) goto L5fdb3b;  // @21_5fda30
  eax = ((u32(STDCALL *)(void))(eax))();  // @22_5fda30
  ecx = edx = 0;  // @23_5fda30
  return eax;  // @24_5fda30
  L5fda97:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @26_5fda30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @27_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @28_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_5fda30
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fdb3c;  // @30_5fda30
  ecx = eax;  // @31_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5fda30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @34_5fda30
  if ((edx & edx) == 0) goto L5fdb3c;  // @35_5fda30
  L5fdac0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @37_5fda30
  eax = (eax + (u32)(-20));  // @38_5fda30
  if (eax > (u32)(16)) goto L5fdafa;  // @39_5fda30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6282068), sizeof v); (u32)v; });  // @40_5fda30
  switch (eax) { case 0: goto L5fdb08; case 1: goto L5fdad8; case 2: goto L5fdafa; default: __builtin_trap(); }  // @41_5fda30
  L5fdad8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 158), sizeof v); (u32)v; });  // @43_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @44_5fda30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @45_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @46_5fda30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_5fda30
  eax = ext_5fa220_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax), sizeof v); (u32)v; }));  // @48_5fda30
  ecx = edx = 0;  // @49_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @50_5fda30
  p1_ = eax;  // @51_5fda30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 44)))(ecx, (u32)(p1_));  // @52_5fda30
  ecx = edx = 0;  // @53_5fda30
  goto L5fdb08;  // @54_5fda30
  L5fdafa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @56_5fda30
  if ((eax & eax) == 0) goto L5fdb07;  // @57_5fda30
  eax = ((u32(STDCALL *)(void))(eax))();  // @58_5fda30
  ecx = edx = 0;  // @59_5fda30
  goto L5fdb08;  // @60_5fda30
  L5fdb07:;
  __builtin_trap();  // @62_5fda30
  L5fdb08:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @64_5fda30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @65_5fda30
  if (ecx >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L5fdb19;  // @66_5fda30
  eax = (u32)(ecx + 1);  // @67_5fda30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @68_5fda30
  L5fdb19:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @70_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @71_5fda30
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L5fdb3c;  // @72_5fda30
  ecx = eax;  // @73_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @74_5fda30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_5fda30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @76_5fda30
  if ((edx & edx) != 0) goto L5fdac0;  // @77_5fda30
  return eax;  // @78_5fda30
  L5fdb3b:;
  __builtin_trap();  // @80_5fda30
  L5fdb3c:;
  L5fdb3e:;
  return eax;  // @83_5fda30
}
PCREG(5fda30, lifted_5fda30);

extern "C" u32 lifted_625f20(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_625f20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_625f20
  if (ecx != edx) goto L625f34;  // @2_625f20
  eax = (u32)(4294967292);  // @3_625f20
  return eax;  // @4_625f20
  L625f34:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_625f20
  p0_ = edi;  // @7_625f20
  edi = ecx;  // @8_625f20
  p1_ = ebx;  // @9_625f20
  L625f40:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_625f20
  ebx = ecx;  // @12_625f20
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @13_625f20
  eax = (eax + (u32)(-3));  // @14_625f20
  if (eax > (u32)(27)) goto L625f75;  // @15_625f20
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6447152), sizeof v); (u32)v; });  // @16_625f20
  switch (eax) { case 0: goto L625f8f; case 1: goto L625f60; case 2: goto L625f67; case 3: goto L625f6e; case 4: goto L625fdf; case 5: goto L625fcb; case 6: goto L625fa9; case 7: goto L625f75; default: __builtin_trap(); }  // @17_625f20
  L625f60:;
  eax = (u32)(2);  // @19_625f20
  goto L625f7a;  // @20_625f20
  L625f67:;
  eax = (u32)(3);  // @22_625f20
  goto L625f7a;  // @23_625f20
  L625f6e:;
  eax = (u32)(4);  // @25_625f20
  goto L625f7a;  // @26_625f20
  L625f75:;
  eax = (u32)(1);  // @28_625f20
  L625f7a:;
  ecx = (ecx + eax);  // @30_625f20
  if (ecx != edx) goto L625f40;  // @31_625f20
  L625f80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @33_625f20
  L625f83:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @35_625f20
  eax = (u32)(6);  // @36_625f20
  return eax;  // @37_625f20
  L625f8f:;
  if (ecx != edi) goto L625f80;  // @39_625f20
  eax = (u32)(ecx + 1);  // @40_625f20
  p2_ = edx;  // @41_625f20
  p3_ = eax;  // @42_625f20
  p4_ = esi;  // @43_625f20
  eax = ext_62c060_cdecl6((u32)(p4_), (u32)(p3_), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @44_625f20
  ecx = edx = 0;  // @45_625f20
  return eax;  // @46_625f20
  L625fa9:;
  if (ecx != edi) goto L625f80;  // @48_625f20
  eax = (u32)(ecx + 1);  // @49_625f20
  p5_ = edx;  // @50_625f20
  p6_ = eax;  // @51_625f20
  p7_ = esi;  // @52_625f20
  eax = ext_62b900_cdecl4((u32)(p7_), (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @53_625f20
  ecx = edx = 0;  // @54_625f20
  ecx = 0;  // @55_625f20
  if (eax == (u32)(22)) eax = ecx;  // @56_625f20
  return eax;  // @57_625f20
  L625fcb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @59_625f20
  if (ecx != edi) goto L625f83;  // @60_625f20
  ecx = (ecx + 1);  // @61_625f20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @62_625f20
  eax = (u32)(7);  // @63_625f20
  return eax;  // @64_625f20
  L625fdf:;
  if (ecx != edi) goto L625f80;  // @66_625f20
  ecx = (ecx + 1);  // @67_625f20
  if (ecx != edx) goto L625ff2;  // @68_625f20
  eax = (u32)(4294967293);  // @69_625f20
  return eax;  // @70_625f20
  L625ff2:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_625f20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @73_625f20
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; }) != (u32)(10)) ecx = ebx;  // @74_625f20
  ecx = (ecx + 1);  // @75_625f20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @76_625f20
  eax = (u32)(7);  // @77_625f20
  return eax;  // @78_625f20
}
PCREG(625f20, lifted_625f20);

extern "C" u32 THISCALL lifted_62b2f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_62b2f0
  p0_ = esi;  // @1_62b2f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_62b2f0
  p1_ = edi;  // @3_62b2f0
  if (esi == ebx) goto L62b3b5;  // @4_62b2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_62b2f0
  edi = ebx;  // @6_62b2f0
  edi = (edi - esi);  // @7_62b2f0
  L62b310:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_62b2f0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @10_62b2f0
  if (ecx > (u32)(13)) goto L62b3ab;  // @11_62b2f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6468632), sizeof v); (u32)v; });  // @12_62b2f0
  switch (eax) { case 0: goto L62b3bd; case 1: goto L62b32f; case 2: goto L62b354; case 3: goto L62b375; case 4: goto L62b396; case 5: goto L62b3ab; default: __builtin_trap(); }  // @13_62b2f0
  L62b32f:;
  if ((s32)edi < (s32)(u32)(2)) goto L62b3c9;  // @15_62b2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 356), sizeof v); (u32)v; });  // @16_62b2f0
  p2_ = esi;  // @17_62b2f0
  p3_ = edx;  // @18_62b2f0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(eax))((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_62b2f0
  ecx = edx = 0;  // @20_62b2f0
  if ((eax & eax) != 0) goto L62b3bd;  // @21_62b2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @22_62b2f0
  esi = (esi + (u32)(2));  // @23_62b2f0
  edi = (edi - (u32)(2));  // @24_62b2f0
  goto L62b3ad;  // @25_62b2f0
  L62b354:;
  if ((s32)edi < (s32)(u32)(3)) goto L62b3c9;  // @27_62b2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 360), sizeof v); (u32)v; });  // @28_62b2f0
  p4_ = esi;  // @29_62b2f0
  p5_ = edx;  // @30_62b2f0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p5_), (u32)(p4_));  // @31_62b2f0
  ecx = edx = 0;  // @32_62b2f0
  if ((eax & eax) != 0) goto L62b3bd;  // @33_62b2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @34_62b2f0
  esi = (esi + (u32)(3));  // @35_62b2f0
  edi = (edi - (u32)(3));  // @36_62b2f0
  goto L62b3ad;  // @37_62b2f0
  L62b375:;
  if ((s32)edi < (s32)(u32)(4)) goto L62b3c9;  // @39_62b2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 364), sizeof v); (u32)v; });  // @40_62b2f0
  p6_ = esi;  // @41_62b2f0
  p7_ = edx;  // @42_62b2f0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p7_), (u32)(p6_));  // @43_62b2f0
  ecx = edx = 0;  // @44_62b2f0
  if ((eax & eax) != 0) goto L62b3bd;  // @45_62b2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @46_62b2f0
  esi = (esi + (u32)(4));  // @47_62b2f0
  edi = (edi - (u32)(4));  // @48_62b2f0
  goto L62b3ad;  // @49_62b2f0
  L62b396:;
  esi = (esi + 1);  // @51_62b2f0
  edi = (edi - 1);  // @52_62b2f0
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L62b3ad;  // @53_62b2f0
  if (esi != ebx) goto L62b3d3;  // @54_62b2f0
  eax = (u32)(4294967269);  // @55_62b2f0
  return eax;  // @56_62b2f0
  L62b3ab:;
  esi = (esi + 1);  // @58_62b2f0
  edi = (edi - 1);  // @59_62b2f0
  L62b3ad:;
  if (esi != ebx) goto L62b310;  // @61_62b2f0
  L62b3b5:;
  eax = (eax | (u32)(4294967295));  // @63_62b2f0
  return eax;  // @64_62b2f0
  L62b3bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @66_62b2f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @67_62b2f0
  L62b3c2:;
  eax = 0;  // @69_62b2f0
  return eax;  // @70_62b2f0
  L62b3c9:;
  eax = (u32)(4294967294);  // @72_62b2f0
  return eax;  // @73_62b2f0
  L62b3d3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @75_62b2f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @76_62b2f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_62b2f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @78_62b2f0
  eax = (eax + (u32)(-9));  // @79_62b2f0
  if (eax > (u32)(21)) goto L62b3c2;  // @80_62b2f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6468656), sizeof v); (u32)v; });  // @81_62b2f0
  switch (eax) { case 0: goto L62b3f6; case 1: goto L62b3c2; default: __builtin_trap(); }  // @82_62b2f0
  L62b3f6:;
  eax = (u32)(27);  // @84_62b2f0
  return eax;  // @85_62b2f0
}
PCREG(62b2f0, lifted_62b2f0);

extern "C" u32 THISCALL lifted_63e480(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63e480
  ebx = ecx;  // @1_63e480
  edi = 0;  // @2_63e480
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3_63e480
  eax = (eax - 1);  // @4_63e480
  if (eax > (u32)(6)) goto L63e5b4;  // @5_63e480
  switch (eax) { case 0: goto L63e567; case 1: goto L63e4a2; case 2: goto L63e4c3; case 3: goto L63e555; case 4: goto L63e4fd; case 5: goto L63e4e1; case 6: goto L63e514; default: __builtin_trap(); }  // @6_63e480
  L63e4a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_63e480
  p0_ = esi;  // @9_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(p0_));  // @10_63e480
  ecx = edx = 0;  // @11_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @12_63e480
  if ((eax & eax) == 0) goto L63e4b8;  // @13_63e480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @14_63e480
  edi = (edi + (u32)(90));  // @15_63e480
  L63e4b8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 540), sizeof v); (u32)v; });  // @17_63e480
  goto L63e57a;  // @18_63e480
  L63e4c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_63e480
  p1_ = esi;  // @21_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, (u32)(p1_));  // @22_63e480
  ecx = edx = 0;  // @23_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @24_63e480
  if ((eax & eax) == 0) goto L63e4d6;  // @25_63e480
  edi = (u32)(eax + 90);  // @26_63e480
  L63e4d6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 544), sizeof v); (u32)v; });  // @28_63e480
  goto L63e57a;  // @29_63e480
  L63e4e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_63e480
  p2_ = esi;  // @32_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(p2_));  // @33_63e480
  ecx = edx = 0;  // @34_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 548), sizeof v); (u32)v; });  // @35_63e480
  p3_ = esi;  // @36_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p3_));  // @38_63e480
  ecx = edx = 0;  // @39_63e480
  return eax;  // @40_63e480
  L63e4fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_63e480
  p4_ = esi;  // @43_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 152)))(ecx, (u32)(p4_));  // @44_63e480
  ecx = edx = 0;  // @45_63e480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @46_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 552), sizeof v); (u32)v; });  // @47_63e480
  edi = (edi + (u32)(6));  // @48_63e480
  goto L63e57a;  // @49_63e480
  L63e514:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @51_63e480
  eax = (u32)(EBP + 8);  // @52_63e480
  ecx = (u32)(ebx + 368);  // @53_63e480
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @54_63e480
  p5_ = eax;  // @55_63e480
  edi = (edi + (u32)(64));  // @56_63e480
  eax = ext_63db40_thiscall2(ecx, (u32)(p5_));  // @57_63e480
  ecx = edx = 0;  // @58_63e480
  edx = eax;  // @59_63e480
  if (edx == (u32)(-1)) goto L63e54d;  // @60_63e480
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(ebx + 368), &v, sizeof v); }  // @61_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 368), sizeof v); (u32)v; });  // @62_63e480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx*4 + 372), sizeof v); (u32)v; });  // @63_63e480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + edx*4 + 372), &v, sizeof v); }  // @64_63e480
  L63e54d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 556), sizeof v); (u32)v; });  // @66_63e480
  goto L63e57a;  // @67_63e480
  L63e555:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @69_63e480
  if ((eax & eax) == 0) goto L63e55f;  // @70_63e480
  edi = (u32)(eax + 90);  // @71_63e480
  L63e55f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 560), sizeof v); (u32)v; });  // @73_63e480
  goto L63e57a;  // @74_63e480
  L63e567:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @76_63e480
  if ((eax & eax) == 0) goto L63e574;  // @77_63e480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @78_63e480
  edi = (edi + (u32)(90));  // @79_63e480
  L63e574:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 536), sizeof v); (u32)v; });  // @81_63e480
  L63e57a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_63e480
  p6_ = esi;  // @84_63e480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(p6_));  // @85_63e480
  ecx = edx = 0;  // @86_63e480
  if ((edi & edi) == 0) goto L63e5c7;  // @87_63e480
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @88_63e480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 104), sizeof v); (u32)v; });  // @89_63e480
  ecx = edx;  // @90_63e480
  ecx = (ecx & (u32)(4095));  // @91_63e480
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @92_63e480
  eax = (u32)(edx - 1);  // @93_63e480
  p7_ = eax;  // @94_63e480
  ecx = (u32)(ebx + 47504);  // @95_63e480
  eax = ext_4ce180_thiscall2(ecx, (u32)(p7_));  // @96_63e480
  ecx = edx = 0;  // @97_63e480
  eax = 0;  // @98_63e480
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @99_63e480
  return eax;  // @100_63e480
  L63e5b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @102_63e480
  if ((eax & eax) == 0) goto L63e5c6;  // @103_63e480
  eax = ((u32(STDCALL *)(void))(eax))();  // @104_63e480
  ecx = edx = 0;  // @105_63e480
  return eax;  // @106_63e480
  L63e5c6:;
  __builtin_trap();  // @108_63e480
  L63e5c7:;
  return eax;  // @110_63e480
}
PCREG(63e480, lifted_63e480);

extern "C" u32 lifted_624350(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_624350
  p0_ = ebx;  // @1_624350
  p1_ = esi;  // @2_624350
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_624350
  eax = esi;  // @4_624350
  p2_ = edi;  // @5_624350
  eax = (eax - ecx);  // @6_624350
  edi = 0;  // @7_624350
  if (((eax & 0xff) & (u32)(1)) == 0) goto L62436d;  // @8_624350
  esi = eax;  // @9_624350
  esi = (esi & (u32)(4294967294));  // @10_624350
  esi = (esi + ecx);  // @11_624350
  L62436d:;
  if (ecx == esi) goto L6243b2;  // @13_624350
  edx = esi;  // @14_624350
  edx = (edx - ecx);  // @15_624350
  L624375:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @17_624350
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_624350
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L624389;  // @19_624350
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_624350
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @21_624350
  goto L624393;  // @22_624350
  L624389:;
  p3_ = eax;  // @24_624350
  p4_ = ebx;  // @25_624350
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @26_624350
  ecx = edx = 0;  // @27_624350
  L624393:;
  if (eax > (u32)(8)) goto L6243a8;  // @29_624350
  switch (eax) { case 0: goto L624454; case 1: goto L624454; case 2: goto L6243d4; case 3: goto L6243a8; case 4: goto L624401; case 5: goto L62439f; case 6: goto L6243ba; case 7: goto L6243c7; case 8: goto L624454; default: __builtin_trap(); }  // @30_624350
  L62439f:;
  if ((s32)edx < (s32)(u32)(2)) goto L62443b;  // @32_624350
  L6243a8:;
  ecx = (ecx + (u32)(2));  // @34_624350
  edx = (edx - (u32)(2));  // @35_624350
  L6243ae:;
  if (ecx != esi) goto L624375;  // @37_624350
  L6243b2:;
  eax = (eax | (u32)(4294967295));  // @39_624350
  return eax;  // @40_624350
  L6243ba:;
  if ((s32)edx < (s32)(u32)(3)) goto L62443b;  // @42_624350
  ecx = (ecx + (u32)(3));  // @43_624350
  edx = (edx - (u32)(3));  // @44_624350
  goto L6243ae;  // @45_624350
  L6243c7:;
  if ((s32)edx < (s32)(u32)(4)) goto L62443b;  // @47_624350
  ecx = (ecx + (u32)(4));  // @48_624350
  edx = (edx - (u32)(4));  // @49_624350
  goto L6243ae;  // @50_624350
  L6243d4:;
  ecx = (ecx + (u32)(2));  // @52_624350
  edx = (edx - (u32)(2));  // @53_624350
  if (ecx == esi) goto L6243b2;  // @54_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6243ae;  // @55_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(33)) goto L6243ae;  // @56_624350
  ecx = (ecx + (u32)(2));  // @57_624350
  edx = (edx - (u32)(2));  // @58_624350
  if (ecx == esi) goto L6243b2;  // @59_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6243ae;  // @60_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(91)) goto L6243ae;  // @61_624350
  edi = (edi + 1);  // @62_624350
  goto L6243a8;  // @63_624350
  L624401:;
  ecx = (ecx + (u32)(2));  // @65_624350
  edx = (edx - (u32)(2));  // @66_624350
  if (ecx == esi) goto L6243b2;  // @67_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6243ae;  // @68_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(93)) goto L6243ae;  // @69_624350
  ecx = (ecx + (u32)(2));  // @70_624350
  edx = (edx - (u32)(2));  // @71_624350
  if (ecx == esi) goto L6243b2;  // @72_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6243ae;  // @73_624350
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(62)) goto L6243ae;  // @74_624350
  ecx = (ecx + (u32)(2));  // @75_624350
  edx = (edx - (u32)(2));  // @76_624350
  if ((edi & edi) == 0) goto L624445;  // @77_624350
  edi = (edi - 1);  // @78_624350
  goto L6243ae;  // @79_624350
  L62443b:;
  eax = (u32)(4294967294);  // @81_624350
  return eax;  // @82_624350
  L624445:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @84_624350
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @85_624350
  eax = (u32)(42);  // @86_624350
  return eax;  // @87_624350
  L624454:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @89_624350
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @90_624350
  eax = 0;  // @91_624350
  return eax;  // @92_624350
}
PCREG(624350, lifted_624350);

extern "C" u32 lifted_626500(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_626500
  p0_ = ebx;  // @1_626500
  p1_ = esi;  // @2_626500
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_626500
  eax = esi;  // @4_626500
  p2_ = edi;  // @5_626500
  eax = (eax - ecx);  // @6_626500
  edi = 0;  // @7_626500
  if (((eax & 0xff) & (u32)(1)) == 0) goto L62651d;  // @8_626500
  esi = eax;  // @9_626500
  esi = (esi & (u32)(4294967294));  // @10_626500
  esi = (esi + ecx);  // @11_626500
  L62651d:;
  if (ecx == esi) goto L626562;  // @13_626500
  edx = esi;  // @14_626500
  edx = (edx - ecx);  // @15_626500
  L626525:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @17_626500
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @18_626500
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L626539;  // @19_626500
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_626500
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @21_626500
  goto L626543;  // @22_626500
  L626539:;
  p3_ = eax;  // @24_626500
  p4_ = ebx;  // @25_626500
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @26_626500
  ecx = edx = 0;  // @27_626500
  L626543:;
  if (eax > (u32)(8)) goto L626558;  // @29_626500
  switch (eax) { case 0: goto L626604; case 1: goto L626604; case 2: goto L626584; case 3: goto L626558; case 4: goto L6265b1; case 5: goto L62654f; case 6: goto L62656a; case 7: goto L626577; case 8: goto L626604; default: __builtin_trap(); }  // @30_626500
  L62654f:;
  if ((s32)edx < (s32)(u32)(2)) goto L6265eb;  // @32_626500
  L626558:;
  ecx = (ecx + (u32)(2));  // @34_626500
  edx = (edx - (u32)(2));  // @35_626500
  L62655e:;
  if (ecx != esi) goto L626525;  // @37_626500
  L626562:;
  eax = (eax | (u32)(4294967295));  // @39_626500
  return eax;  // @40_626500
  L62656a:;
  if ((s32)edx < (s32)(u32)(3)) goto L6265eb;  // @42_626500
  ecx = (ecx + (u32)(3));  // @43_626500
  edx = (edx - (u32)(3));  // @44_626500
  goto L62655e;  // @45_626500
  L626577:;
  if ((s32)edx < (s32)(u32)(4)) goto L6265eb;  // @47_626500
  ecx = (ecx + (u32)(4));  // @48_626500
  edx = (edx - (u32)(4));  // @49_626500
  goto L62655e;  // @50_626500
  L626584:;
  ecx = (ecx + (u32)(2));  // @52_626500
  edx = (edx - (u32)(2));  // @53_626500
  if (ecx == esi) goto L626562;  // @54_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L62655e;  // @55_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(33)) goto L62655e;  // @56_626500
  ecx = (ecx + (u32)(2));  // @57_626500
  edx = (edx - (u32)(2));  // @58_626500
  if (ecx == esi) goto L626562;  // @59_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L62655e;  // @60_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(91)) goto L62655e;  // @61_626500
  edi = (edi + 1);  // @62_626500
  goto L626558;  // @63_626500
  L6265b1:;
  ecx = (ecx + (u32)(2));  // @65_626500
  edx = (edx - (u32)(2));  // @66_626500
  if (ecx == esi) goto L626562;  // @67_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L62655e;  // @68_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(93)) goto L62655e;  // @69_626500
  ecx = (ecx + (u32)(2));  // @70_626500
  edx = (edx - (u32)(2));  // @71_626500
  if (ecx == esi) goto L626562;  // @72_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L62655e;  // @73_626500
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(62)) goto L62655e;  // @74_626500
  ecx = (ecx + (u32)(2));  // @75_626500
  edx = (edx - (u32)(2));  // @76_626500
  if ((edi & edi) == 0) goto L6265f5;  // @77_626500
  edi = (edi - 1);  // @78_626500
  goto L62655e;  // @79_626500
  L6265eb:;
  eax = (u32)(4294967294);  // @81_626500
  return eax;  // @82_626500
  L6265f5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @84_626500
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @85_626500
  eax = (u32)(42);  // @86_626500
  return eax;  // @87_626500
  L626604:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @89_626500
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @90_626500
  eax = 0;  // @91_626500
  return eax;  // @92_626500
}
PCREG(626500, lifted_626500);

extern "C" u32 THISCALL lifted_4f9f50(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f9f50
  edx = 0;  // @1_4f9f50
  esi = ecx;  // @2_4f9f50
  if (eax > (u32)(4)) goto L4fa0af;  // @3_4f9f50
  switch (eax) { case 0: goto L4f9f6b; case 1: goto L4f9fbe; case 2: goto L4fa000; case 3: goto L4fa042; case 4: goto L4fa07b; default: __builtin_trap(); }  // @4_4f9f50
  L4f9f6b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4));  // @7_4f9f50
  ecx = edx = 0;  // @8_4f9f50
  edx = eax;  // @9_4f9f50
  if ((edx & edx) != 0) goto L4fa0af;  // @10_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_4f9f50
  ecx = esi;  // @12_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(2));  // @13_4f9f50
  ecx = edx = 0;  // @14_4f9f50
  edx = eax;  // @15_4f9f50
  if ((edx & edx) != 0) goto L4fa0af;  // @16_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_4f9f50
  ecx = esi;  // @18_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(3));  // @19_4f9f50
  ecx = edx = 0;  // @20_4f9f50
  edx = eax;  // @21_4f9f50
  if ((edx & edx) != 0) goto L4fa0af;  // @22_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4f9f50
  ecx = esi;  // @24_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(1));  // @25_4f9f50
  ecx = edx = 0;  // @26_4f9f50
  edx = eax;  // @27_4f9f50
  return eax;  // @28_4f9f50
  L4f9fbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 120), sizeof v); (u32)v; }));  // @33_4f9f50
  ecx = edx = 0;  // @34_4f9f50
  edx = eax;  // @35_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @36_4f9f50
  if (edx == esi) goto L4fa0af;  // @37_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @38_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @39_4f9f50
  ecx = edx;  // @40_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(1));  // @41_4f9f50
  ecx = edx = 0;  // @42_4f9f50
  edx = eax;  // @43_4f9f50
  return eax;  // @44_4f9f50
  L4fa000:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @47_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }));  // @49_4f9f50
  ecx = edx = 0;  // @50_4f9f50
  edx = eax;  // @51_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @52_4f9f50
  if (edx == esi) goto L4fa0af;  // @53_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @54_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @55_4f9f50
  ecx = edx;  // @56_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(2));  // @57_4f9f50
  ecx = edx = 0;  // @58_4f9f50
  edx = eax;  // @59_4f9f50
  return eax;  // @60_4f9f50
  L4fa042:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @63_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }));  // @65_4f9f50
  ecx = edx = 0;  // @66_4f9f50
  edx = eax;  // @67_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @68_4f9f50
  if (edx == esi) goto L4fa0af;  // @69_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @70_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @71_4f9f50
  ecx = edx;  // @72_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(3));  // @73_4f9f50
  ecx = edx = 0;  // @74_4f9f50
  edx = eax;  // @75_4f9f50
  return eax;  // @76_4f9f50
  L4fa07b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }));  // @81_4f9f50
  ecx = edx = 0;  // @82_4f9f50
  edx = eax;  // @83_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @84_4f9f50
  if (edx == esi) goto L4fa0af;  // @85_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @86_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @87_4f9f50
  ecx = edx;  // @88_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4));  // @89_4f9f50
  ecx = edx = 0;  // @90_4f9f50
  edx = eax;  // @91_4f9f50
  L4fa0af:;
  eax = edx;  // @93_4f9f50
  return eax;  // @94_4f9f50
}
PCREG(4f9f50, lifted_4f9f50);

extern "C" u32 FASTCALL lifted_623fa0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_623fa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_623fa0
  if (ecx != esi) goto L623fb6;  // @2_623fa0
  eax = (u32)(4294967292);  // @3_623fa0
  return eax;  // @4_623fa0
  L623fb6:;
  p0_ = ebx;  // @6_623fa0
  p1_ = edi;  // @7_623fa0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_623fa0
  ebx = ecx;  // @9_623fa0
  L623fc0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @11_623fa0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_623fa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @13_623fa0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L623fd4;  // @14_623fa0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @15_623fa0
  goto L623fde;  // @16_623fa0
  L623fd4:;
  p2_ = eax;  // @18_623fa0
  p3_ = edx;  // @19_623fa0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @20_623fa0
  ecx = edx = 0;  // @21_623fa0
  L623fde:;
  eax = (eax - (u32)(3));  // @23_623fa0
  if (eax > (u32)(27)) goto L624002;  // @24_623fa0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6439128), sizeof v); (u32)v; });  // @25_623fa0
  switch (eax) { case 0: goto L62401c; case 1: goto L624002; case 2: goto L623ff4; case 3: goto L623ffb; case 4: goto L62406e; case 5: goto L624058; case 6: goto L624036; case 7: goto L624002; default: __builtin_trap(); }  // @26_623fa0
  L623ff4:;
  eax = (u32)(3);  // @28_623fa0
  goto L624007;  // @29_623fa0
  L623ffb:;
  eax = (u32)(4);  // @31_623fa0
  goto L624007;  // @32_623fa0
  L624002:;
  eax = (u32)(2);  // @34_623fa0
  L624007:;
  ecx = (ecx + eax);  // @36_623fa0
  if (ecx != esi) goto L623fc0;  // @37_623fa0
  L62400d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @39_623fa0
  L624010:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @41_623fa0
  eax = (u32)(6);  // @42_623fa0
  return eax;  // @43_623fa0
  L62401c:;
  if (ecx != ebx) goto L62400d;  // @45_623fa0
  ecx = (ecx + (u32)(2));  // @46_623fa0
  p4_ = esi;  // @47_623fa0
  p5_ = ecx;  // @48_623fa0
  p6_ = edi;  // @49_623fa0
  eax = ext_62a690_cdecl4((u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @50_623fa0
  ecx = edx = 0;  // @51_623fa0
  return eax;  // @52_623fa0
  L624036:;
  if (ecx != ebx) goto L62400d;  // @54_623fa0
  ecx = (ecx + (u32)(2));  // @55_623fa0
  p7_ = esi;  // @56_623fa0
  p8_ = ecx;  // @57_623fa0
  p9_ = edi;  // @58_623fa0
  eax = ext_62a030_cdecl4((u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @59_623fa0
  ecx = edx = 0;  // @60_623fa0
  ecx = 0;  // @61_623fa0
  if (eax == (u32)(22)) eax = ecx;  // @62_623fa0
  return eax;  // @63_623fa0
  L624058:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @65_623fa0
  if (ecx != ebx) goto L624010;  // @66_623fa0
  ecx = (ecx + (u32)(2));  // @67_623fa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_623fa0
  eax = (u32)(7);  // @69_623fa0
  return eax;  // @70_623fa0
  L62406e:;
  if (ecx != ebx) goto L62400d;  // @72_623fa0
  ecx = (ecx + (u32)(2));  // @73_623fa0
  if (ecx != esi) goto L624083;  // @74_623fa0
  eax = (u32)(4294967293);  // @75_623fa0
  return eax;  // @76_623fa0
  L624083:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @78_623fa0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_623fa0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L624094;  // @80_623fa0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @81_623fa0
  goto L62409e;  // @82_623fa0
  L624094:;
  p10_ = eax;  // @84_623fa0
  p11_ = edx;  // @85_623fa0
  eax = ext_62c640_cdecl2((u32)(p11_), (u32)(p10_));  // @86_623fa0
  ecx = edx = 0;  // @87_623fa0
  L62409e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @89_623fa0
  if (eax != (u32)(10)) ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @90_623fa0
  ecx = (ecx + (u32)(2));  // @91_623fa0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @92_623fa0
  eax = (u32)(7);  // @93_623fa0
  return eax;  // @94_623fa0
}
PCREG(623fa0, lifted_623fa0);

extern "C" u32 FASTCALL lifted_626310(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_626310
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_626310
  if (ecx != esi) goto L626326;  // @2_626310
  eax = (u32)(4294967292);  // @3_626310
  return eax;  // @4_626310
  L626326:;
  p0_ = ebx;  // @6_626310
  p1_ = edi;  // @7_626310
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_626310
  ebx = ecx;  // @9_626310
  L626330:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @11_626310
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @12_626310
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @13_626310
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L626344;  // @14_626310
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @15_626310
  goto L62634e;  // @16_626310
  L626344:;
  p2_ = eax;  // @18_626310
  p3_ = edx;  // @19_626310
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @20_626310
  ecx = edx = 0;  // @21_626310
  L62634e:;
  eax = (eax - (u32)(3));  // @23_626310
  if (eax > (u32)(27)) goto L626372;  // @24_626310
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6448200), sizeof v); (u32)v; });  // @25_626310
  switch (eax) { case 0: goto L62638c; case 1: goto L626372; case 2: goto L626364; case 3: goto L62636b; case 4: goto L6263de; case 5: goto L6263c8; case 6: goto L6263a6; case 7: goto L626372; default: __builtin_trap(); }  // @26_626310
  L626364:;
  eax = (u32)(3);  // @28_626310
  goto L626377;  // @29_626310
  L62636b:;
  eax = (u32)(4);  // @31_626310
  goto L626377;  // @32_626310
  L626372:;
  eax = (u32)(2);  // @34_626310
  L626377:;
  ecx = (ecx + eax);  // @36_626310
  if (ecx != esi) goto L626330;  // @37_626310
  L62637d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @39_626310
  L626380:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @41_626310
  eax = (u32)(6);  // @42_626310
  return eax;  // @43_626310
  L62638c:;
  if (ecx != ebx) goto L62637d;  // @45_626310
  ecx = (ecx + (u32)(2));  // @46_626310
  p4_ = esi;  // @47_626310
  p5_ = ecx;  // @48_626310
  p6_ = edi;  // @49_626310
  eax = ext_628630_cdecl4((u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @50_626310
  ecx = edx = 0;  // @51_626310
  return eax;  // @52_626310
  L6263a6:;
  if (ecx != ebx) goto L62637d;  // @54_626310
  ecx = (ecx + (u32)(2));  // @55_626310
  p7_ = esi;  // @56_626310
  p8_ = ecx;  // @57_626310
  p9_ = edi;  // @58_626310
  eax = ext_627fd0_cdecl4((u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @59_626310
  ecx = edx = 0;  // @60_626310
  ecx = 0;  // @61_626310
  if (eax == (u32)(22)) eax = ecx;  // @62_626310
  return eax;  // @63_626310
  L6263c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @65_626310
  if (ecx != ebx) goto L626380;  // @66_626310
  ecx = (ecx + (u32)(2));  // @67_626310
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @68_626310
  eax = (u32)(7);  // @69_626310
  return eax;  // @70_626310
  L6263de:;
  if (ecx != ebx) goto L62637d;  // @72_626310
  ecx = (ecx + (u32)(2));  // @73_626310
  if (ecx != esi) goto L6263f3;  // @74_626310
  eax = (u32)(4294967293);  // @75_626310
  return eax;  // @76_626310
  L6263f3:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @78_626310
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @79_626310
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L626404;  // @80_626310
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @81_626310
  goto L62640e;  // @82_626310
  L626404:;
  p10_ = eax;  // @84_626310
  p11_ = edx;  // @85_626310
  eax = ext_62c640_cdecl2((u32)(p11_), (u32)(p10_));  // @86_626310
  ecx = edx = 0;  // @87_626310
  L62640e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @89_626310
  if (eax != (u32)(10)) ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @90_626310
  ecx = (ecx + (u32)(2));  // @91_626310
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @92_626310
  eax = (u32)(7);  // @93_626310
  return eax;  // @94_626310
}
PCREG(626310, lifted_626310);

extern "C" u32 THISCALL lifted_628470(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_628470
  p0_ = edi;  // @1_628470
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_628470
  if (edx != edi) goto L628484;  // @3_628470
  eax = (eax | (u32)(4294967295));  // @4_628470
  return eax;  // @5_628470
  L628484:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @7_628470
  p1_ = ebx;  // @8_628470
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @9_628470
  p2_ = esi;  // @10_628470
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L62849c;  // @11_628470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_628470
  eax = (ecx & 0xff);  // @13_628470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @14_628470
  goto L6284a6;  // @15_628470
  L62849c:;
  p3_ = ecx;  // @17_628470
  p4_ = ebx;  // @18_628470
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_628470
  ecx = edx = 0;  // @20_628470
  L6284a6:;
  eax = (eax - (u32)(5));  // @22_628470
  if (eax > (u32)(24)) goto L6285a8;  // @23_628470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6456780), sizeof v); (u32)v; });  // @24_628470
  switch (eax) { case 0: goto L628566; case 1: goto L628577; case 2: goto L628597; case 3: goto L6284ec; case 4: goto L6284c0; case 5: goto L6285a8; default: __builtin_trap(); }  // @25_628470
  L6284c0:;
  eax = (ebx & 0xff);  // @27_628470
  ecx = (ecx & 0xff);  // @28_628470
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @29_628470
  eax = ecx;  // @30_628470
  eax = (eax >> (u32)(5));  // @31_628470
  ecx = (ecx & (u32)(31));  // @32_628470
  esi = (u32)(eax + esi*8);  // @33_628470
  eax = (u32)(1);  // @34_628470
  eax = (eax << (ecx & 0xff));  // @35_628470
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L6285a8;  // @36_628470
  L6284ec:;
  edx = (edx + (u32)(2));  // @38_628470
  if (edx == edi) goto L62855c;  // @39_628470
  L6284f3:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @41_628470
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @42_628470
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L628509;  // @43_628470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_628470
  eax = (ecx & 0xff);  // @45_628470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @46_628470
  goto L628513;  // @47_628470
  L628509:;
  p5_ = ecx;  // @49_628470
  p6_ = ebx;  // @50_628470
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @51_628470
  ecx = edx = 0;  // @52_628470
  L628513:;
  eax = (eax - (u32)(5));  // @54_628470
  if (eax > (u32)(31)) goto L6285a8;  // @55_628470
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6456836), sizeof v); (u32)v; });  // @56_628470
  switch (eax) { case 0: goto L628566; case 1: goto L628577; case 2: goto L628597; case 3: goto L628588; case 4: goto L628555; case 5: goto L62852d; case 6: goto L6285a8; default: __builtin_trap(); }  // @57_628470
  L62852d:;
  eax = (ebx & 0xff);  // @59_628470
  ecx = (ecx & 0xff);  // @60_628470
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @61_628470
  eax = ecx;  // @62_628470
  eax = (eax >> (u32)(5));  // @63_628470
  ecx = (ecx & (u32)(31));  // @64_628470
  esi = (u32)(eax + esi*8);  // @65_628470
  eax = (u32)(1);  // @66_628470
  eax = (eax << (ecx & 0xff));  // @67_628470
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L6285a8;  // @68_628470
  L628555:;
  edx = (edx + (u32)(2));  // @70_628470
  if (edx != edi) goto L6284f3;  // @71_628470
  L62855c:;
  eax = (u32)(4294967276);  // @73_628470
  return eax;  // @74_628470
  L628566:;
  edi = (edi - edx);  // @76_628470
  if ((s32)edi >= (s32)(u32)(2)) goto L6285a8;  // @77_628470
  eax = (u32)(4294967294);  // @78_628470
  return eax;  // @79_628470
  L628577:;
  edi = (edi - edx);  // @81_628470
  if ((s32)edi >= (s32)(u32)(3)) goto L6285a8;  // @82_628470
  eax = (u32)(4294967294);  // @83_628470
  return eax;  // @84_628470
  L628588:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @86_628470
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @87_628470
  eax = (u32)(20);  // @88_628470
  return eax;  // @89_628470
  L628597:;
  edi = (edi - edx);  // @91_628470
  if ((s32)edi >= (s32)(u32)(4)) goto L6285a8;  // @92_628470
  eax = (u32)(4294967294);  // @93_628470
  return eax;  // @94_628470
  L6285a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @96_628470
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_628470
  eax = 0;  // @98_628470
  return eax;  // @99_628470
}
PCREG(628470, lifted_628470);

extern "C" u32 THISCALL lifted_62a4d0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62a4d0
  p0_ = edi;  // @1_62a4d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_62a4d0
  if (edx != edi) goto L62a4e4;  // @3_62a4d0
  eax = (eax | (u32)(4294967295));  // @4_62a4d0
  return eax;  // @5_62a4d0
  L62a4e4:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_62a4d0
  p1_ = ebx;  // @8_62a4d0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @9_62a4d0
  p2_ = esi;  // @10_62a4d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L62a4fc;  // @11_62a4d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_62a4d0
  eax = (ecx & 0xff);  // @13_62a4d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @14_62a4d0
  goto L62a506;  // @15_62a4d0
  L62a4fc:;
  p3_ = ecx;  // @17_62a4d0
  p4_ = ebx;  // @18_62a4d0
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_62a4d0
  ecx = edx = 0;  // @20_62a4d0
  L62a506:;
  eax = (eax - (u32)(5));  // @22_62a4d0
  if (eax > (u32)(24)) goto L62a608;  // @23_62a4d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6465068), sizeof v); (u32)v; });  // @24_62a4d0
  switch (eax) { case 0: goto L62a5c6; case 1: goto L62a5d7; case 2: goto L62a5f7; case 3: goto L62a54c; case 4: goto L62a520; case 5: goto L62a608; default: __builtin_trap(); }  // @25_62a4d0
  L62a520:;
  eax = (ebx & 0xff);  // @27_62a4d0
  ecx = (ecx & 0xff);  // @28_62a4d0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @29_62a4d0
  eax = ecx;  // @30_62a4d0
  eax = (eax >> (u32)(5));  // @31_62a4d0
  ecx = (ecx & (u32)(31));  // @32_62a4d0
  esi = (u32)(eax + esi*8);  // @33_62a4d0
  eax = (u32)(1);  // @34_62a4d0
  eax = (eax << (ecx & 0xff));  // @35_62a4d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a608;  // @36_62a4d0
  L62a54c:;
  edx = (edx + (u32)(2));  // @38_62a4d0
  if (edx == edi) goto L62a5bc;  // @39_62a4d0
  L62a553:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @41_62a4d0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @42_62a4d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L62a569;  // @43_62a4d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_62a4d0
  eax = (ecx & 0xff);  // @45_62a4d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @46_62a4d0
  goto L62a573;  // @47_62a4d0
  L62a569:;
  p5_ = ecx;  // @49_62a4d0
  p6_ = ebx;  // @50_62a4d0
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @51_62a4d0
  ecx = edx = 0;  // @52_62a4d0
  L62a573:;
  eax = (eax - (u32)(5));  // @54_62a4d0
  if (eax > (u32)(31)) goto L62a608;  // @55_62a4d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6465124), sizeof v); (u32)v; });  // @56_62a4d0
  switch (eax) { case 0: goto L62a5c6; case 1: goto L62a5d7; case 2: goto L62a5f7; case 3: goto L62a5e8; case 4: goto L62a5b5; case 5: goto L62a58d; case 6: goto L62a608; default: __builtin_trap(); }  // @57_62a4d0
  L62a58d:;
  eax = (ebx & 0xff);  // @59_62a4d0
  ecx = (ecx & 0xff);  // @60_62a4d0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @61_62a4d0
  eax = ecx;  // @62_62a4d0
  eax = (eax >> (u32)(5));  // @63_62a4d0
  ecx = (ecx & (u32)(31));  // @64_62a4d0
  esi = (u32)(eax + esi*8);  // @65_62a4d0
  eax = (u32)(1);  // @66_62a4d0
  eax = (eax << (ecx & 0xff));  // @67_62a4d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a608;  // @68_62a4d0
  L62a5b5:;
  edx = (edx + (u32)(2));  // @70_62a4d0
  if (edx != edi) goto L62a553;  // @71_62a4d0
  L62a5bc:;
  eax = (u32)(4294967276);  // @73_62a4d0
  return eax;  // @74_62a4d0
  L62a5c6:;
  edi = (edi - edx);  // @76_62a4d0
  if ((s32)edi >= (s32)(u32)(2)) goto L62a608;  // @77_62a4d0
  eax = (u32)(4294967294);  // @78_62a4d0
  return eax;  // @79_62a4d0
  L62a5d7:;
  edi = (edi - edx);  // @81_62a4d0
  if ((s32)edi >= (s32)(u32)(3)) goto L62a608;  // @82_62a4d0
  eax = (u32)(4294967294);  // @83_62a4d0
  return eax;  // @84_62a4d0
  L62a5e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @86_62a4d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @87_62a4d0
  eax = (u32)(20);  // @88_62a4d0
  return eax;  // @89_62a4d0
  L62a5f7:;
  edi = (edi - edx);  // @91_62a4d0
  if ((s32)edi >= (s32)(u32)(4)) goto L62a608;  // @92_62a4d0
  eax = (u32)(4294967294);  // @93_62a4d0
  return eax;  // @94_62a4d0
  L62a608:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @96_62a4d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_62a4d0
  eax = 0;  // @98_62a4d0
  return eax;  // @99_62a4d0
}
PCREG(62a4d0, lifted_62a4d0);

extern "C" u32 lifted_623e40(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_623e40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_623e40
  if (ecx != esi) goto L623e56;  // @2_623e40
  eax = (u32)(4294967292);  // @3_623e40
  return eax;  // @4_623e40
  L623e56:;
  p0_ = edi;  // @6_623e40
  edi = ecx;  // @7_623e40
  p1_ = ebx;  // @8_623e40
  L623e60:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @10_623e40
  ebx = ecx;  // @11_623e40
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_623e40
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L623e76;  // @13_623e40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_623e40
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @15_623e40
  goto L623e83;  // @16_623e40
  L623e76:;
  p2_ = eax;  // @18_623e40
  p3_ = edx;  // @19_623e40
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @20_623e40
  ecx = edx = 0;  // @21_623e40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_623e40
  L623e83:;
  eax = (eax - (u32)(2));  // @24_623e40
  if (eax > (u32)(19)) goto L623ea7;  // @25_623e40
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6438792), sizeof v); (u32)v; });  // @26_623e40
  switch (eax) { case 0: goto L623edb; case 1: goto L623ec1; case 2: goto L623ea7; case 3: goto L623e99; case 4: goto L623ea0; case 5: goto L623efd; case 6: goto L623ee7; case 7: goto L623f48; case 8: goto L623ea7; default: __builtin_trap(); }  // @27_623e40
  L623e99:;
  eax = (u32)(3);  // @29_623e40
  goto L623eac;  // @30_623e40
  L623ea0:;
  eax = (u32)(4);  // @32_623e40
  goto L623eac;  // @33_623e40
  L623ea7:;
  eax = (u32)(2);  // @35_623e40
  L623eac:;
  ecx = (ecx + eax);  // @37_623e40
  if (ecx != esi) goto L623e60;  // @38_623e40
  L623eb2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @40_623e40
  L623eb5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @42_623e40
  eax = (u32)(6);  // @43_623e40
  return eax;  // @44_623e40
  L623ec1:;
  if (ecx != edi) goto L623eb2;  // @46_623e40
  eax = (u32)(ecx + 2);  // @47_623e40
  p4_ = esi;  // @48_623e40
  p5_ = eax;  // @49_623e40
  p6_ = edx;  // @50_623e40
  eax = ext_62a690_cdecl4((u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @51_623e40
  ecx = edx = 0;  // @52_623e40
  return eax;  // @53_623e40
  L623edb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @55_623e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @56_623e40
  eax = 0;  // @57_623e40
  return eax;  // @58_623e40
  L623ee7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @60_623e40
  if (ecx != edi) goto L623eb5;  // @61_623e40
  ecx = (ecx + (u32)(2));  // @62_623e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @63_623e40
  eax = (u32)(7);  // @64_623e40
  return eax;  // @65_623e40
  L623efd:;
  if (ecx != edi) goto L623eb2;  // @67_623e40
  ecx = (ecx + (u32)(2));  // @68_623e40
  if (ecx != esi) goto L623f12;  // @69_623e40
  eax = (u32)(4294967293);  // @70_623e40
  return eax;  // @71_623e40
  L623f12:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @73_623e40
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_623e40
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L623f26;  // @75_623e40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @76_623e40
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @77_623e40
  goto L623f30;  // @78_623e40
  L623f26:;
  p7_ = eax;  // @80_623e40
  p8_ = edx;  // @81_623e40
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @82_623e40
  ecx = edx = 0;  // @83_623e40
  L623f30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @85_623e40
  if (eax != (u32)(10)) ecx = ebx;  // @86_623e40
  ecx = (ecx + (u32)(2));  // @87_623e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @88_623e40
  eax = (u32)(7);  // @89_623e40
  return eax;  // @90_623e40
  L623f48:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @92_623e40
  if (ecx != edi) goto L623eb5;  // @93_623e40
  ecx = (ecx + (u32)(2));  // @94_623e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @95_623e40
  eax = (u32)(39);  // @96_623e40
  return eax;  // @97_623e40
}
PCREG(623e40, lifted_623e40);

extern "C" u32 lifted_626050(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_626050
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_626050
  if (ecx != esi) goto L626066;  // @2_626050
  eax = (u32)(4294967292);  // @3_626050
  return eax;  // @4_626050
  L626066:;
  p0_ = edi;  // @6_626050
  edi = ecx;  // @7_626050
  p1_ = ebx;  // @8_626050
  L626070:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @10_626050
  ebx = ecx;  // @11_626050
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @12_626050
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L626086;  // @13_626050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_626050
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @15_626050
  goto L626093;  // @16_626050
  L626086:;
  p2_ = eax;  // @18_626050
  p3_ = edx;  // @19_626050
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @20_626050
  ecx = edx = 0;  // @21_626050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_626050
  L626093:;
  eax = (eax - (u32)(2));  // @24_626050
  if (eax > (u32)(19)) goto L6260b7;  // @25_626050
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6447512), sizeof v); (u32)v; });  // @26_626050
  switch (eax) { case 0: goto L6260eb; case 1: goto L6260d1; case 2: goto L6260b7; case 3: goto L6260a9; case 4: goto L6260b0; case 5: goto L62610d; case 6: goto L6260f7; case 7: goto L626158; case 8: goto L6260b7; default: __builtin_trap(); }  // @27_626050
  L6260a9:;
  eax = (u32)(3);  // @29_626050
  goto L6260bc;  // @30_626050
  L6260b0:;
  eax = (u32)(4);  // @32_626050
  goto L6260bc;  // @33_626050
  L6260b7:;
  eax = (u32)(2);  // @35_626050
  L6260bc:;
  ecx = (ecx + eax);  // @37_626050
  if (ecx != esi) goto L626070;  // @38_626050
  L6260c2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @40_626050
  L6260c5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @42_626050
  eax = (u32)(6);  // @43_626050
  return eax;  // @44_626050
  L6260d1:;
  if (ecx != edi) goto L6260c2;  // @46_626050
  eax = (u32)(ecx + 2);  // @47_626050
  p4_ = esi;  // @48_626050
  p5_ = eax;  // @49_626050
  p6_ = edx;  // @50_626050
  eax = ext_628630_cdecl4((u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @51_626050
  ecx = edx = 0;  // @52_626050
  return eax;  // @53_626050
  L6260eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @55_626050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @56_626050
  eax = 0;  // @57_626050
  return eax;  // @58_626050
  L6260f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @60_626050
  if (ecx != edi) goto L6260c5;  // @61_626050
  ecx = (ecx + (u32)(2));  // @62_626050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @63_626050
  eax = (u32)(7);  // @64_626050
  return eax;  // @65_626050
  L62610d:;
  if (ecx != edi) goto L6260c2;  // @67_626050
  ecx = (ecx + (u32)(2));  // @68_626050
  if (ecx != esi) goto L626122;  // @69_626050
  eax = (u32)(4294967293);  // @70_626050
  return eax;  // @71_626050
  L626122:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @73_626050
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @74_626050
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L626136;  // @75_626050
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @76_626050
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @77_626050
  goto L626140;  // @78_626050
  L626136:;
  p7_ = eax;  // @80_626050
  p8_ = edx;  // @81_626050
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @82_626050
  ecx = edx = 0;  // @83_626050
  L626140:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @85_626050
  if (eax != (u32)(10)) ecx = ebx;  // @86_626050
  ecx = (ecx + (u32)(2));  // @87_626050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @88_626050
  eax = (u32)(7);  // @89_626050
  return eax;  // @90_626050
  L626158:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @92_626050
  if (ecx != edi) goto L6260c5;  // @93_626050
  ecx = (ecx + (u32)(2));  // @94_626050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @95_626050
  eax = (u32)(39);  // @96_626050
  return eax;  // @97_626050
}
PCREG(626050, lifted_626050);

extern "C" u32 lifted_61f400(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_61f400
  ecx = (u32)(EBP + 8);  // @1_61f400
  p0_ = esi;  // @2_61f400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_61f400
  p1_ = edi;  // @4_61f400
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_61f400
  p2_ = ecx;  // @6_61f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @7_61f400
  p3_ = ebx;  // @8_61f400
  p4_ = edi;  // @9_61f400
  { u32 v = (u32)((u32)(6419456)); __builtin_memcpy((void *)(u32)(esi + 272), &v, sizeof v); }  // @10_61f400
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 280), &v, sizeof v); }  // @11_61f400
  p5_ = eax;  // @12_61f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_61f400
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p5_), (u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @14_61f400
  ecx = edx = 0;  // @15_61f400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_61f400
  eax = (eax + (u32)(15));  // @17_61f400
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 284), &v, sizeof v); }  // @18_61f400
  if (eax > (u32)(30)) goto L61f4cc;  // @19_61f400
  L61f450:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6419820), sizeof v); (u32)v; });  // @21_61f400
  switch (eax) { case 0: goto L61f4e0; case 1: goto L61f4fd; case 2: goto L61f537; case 3: goto L61f51d; case 4: goto L61f50d; case 5: goto L61f477; case 6: goto L61f487; case 7: goto L61f45e; case 8: goto L61f4cc; default: __builtin_trap(); }  // @22_61f400
  L61f45e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L61f49f;  // @24_61f400
  p6_ = ecx;  // @25_61f400
  p7_ = edi;  // @26_61f400
  p8_ = esi;  // @27_61f400
  eax = ext_620cb0_cdecl4((u32)(p8_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; }), (u32)(p7_), (u32)(p6_));  // @28_61f400
  ecx = edx = 0;  // @29_61f400
  goto L61f49c;  // @30_61f400
  L61f477:;
  p9_ = ecx;  // @32_61f400
  p10_ = edi;  // @33_61f400
  p11_ = esi;  // @34_61f400
  eax = ext_620d50_cdecl4((u32)(p11_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; }), (u32)(p10_), (u32)(p9_));  // @35_61f400
  ecx = edx = 0;  // @36_61f400
  goto L61f495;  // @37_61f400
  L61f487:;
  p12_ = ecx;  // @39_61f400
  p13_ = edi;  // @40_61f400
  p14_ = esi;  // @41_61f400
  eax = ext_620c00_cdecl4((u32)(p14_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; }), (u32)(p13_), (u32)(p12_));  // @42_61f400
  ecx = edx = 0;  // @43_61f400
  L61f495:;
  if ((eax & eax) == 0) goto L61f4d6;  // @45_61f400
  L61f49c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_61f400
  L61f49f:;
  edx = (u32)(EBP + 8);  // @49_61f400
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 280), &v, sizeof v); }  // @50_61f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; });  // @51_61f400
  edi = ecx;  // @52_61f400
  p15_ = edx;  // @53_61f400
  p16_ = ebx;  // @54_61f400
  p17_ = ecx;  // @55_61f400
  p18_ = eax;  // @56_61f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_61f400
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p18_), (u32)(p17_), (u32)(p16_), (u32)(p15_));  // @58_61f400
  ecx = edx = 0;  // @59_61f400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @60_61f400
  eax = (eax + (u32)(15));  // @61_61f400
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 284), &v, sizeof v); }  // @62_61f400
  if (eax <= (u32)(30)) goto L61f450;  // @63_61f400
  L61f4cc:;
  eax = (u32)(9);  // @65_61f400
  return eax;  // @66_61f400
  L61f4d6:;
  eax = (u32)(1);  // @68_61f400
  return eax;  // @69_61f400
  L61f4e0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L61f4fd;  // @71_61f400
  p19_ = ebx;  // @72_61f400
  p20_ = edi;  // @73_61f400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 284), &v, sizeof v); }  // @74_61f400
  p21_ = esi;  // @75_61f400
  eax = ext_620cb0_cdecl4((u32)(p21_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 140), sizeof v); (u32)v; }), (u32)(p20_), (u32)(p19_));  // @76_61f400
  ecx = edx = 0;  // @77_61f400
  L61f4fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @79_61f400
  if ((eax & eax) == 0) goto L61f506;  // @80_61f400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_61f400
  L61f506:;
  eax = 0;  // @83_61f400
  return eax;  // @84_61f400
  L61f50d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 280), &v, sizeof v); }  // @86_61f400
  eax = (u32)(4);  // @87_61f400
  return eax;  // @88_61f400
  L61f51d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @90_61f400
  if ((eax & eax) == 0) goto L61f52d;  // @91_61f400
  L61f524:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @93_61f400
  eax = 0;  // @94_61f400
  return eax;  // @95_61f400
  L61f52d:;
  eax = (u32)(5);  // @97_61f400
  return eax;  // @98_61f400
  L61f537:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @100_61f400
  if ((eax & eax) != 0) goto L61f524;  // @101_61f400
  eax = (u32)(6);  // @102_61f400
  return eax;  // @103_61f400
}
PCREG(61f400, lifted_61f400);

extern "C" u32 THISCALL lifted_56b730(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3202), sizeof v); (u32)v; });  // @1_56b730
  eax = (eax + (u32)(-8));  // @2_56b730
  if (eax > (u32)(24)) goto L56b8ce;  // @3_56b730
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5683472), sizeof v); (u32)v; });  // @4_56b730
  switch (eax) { case 0: goto L56b80f; case 1: goto L56b82b; case 2: goto L56b78a; case 3: goto L56b7b7; case 4: goto L56b856; case 5: goto L56b887; case 6: goto L56b8ad; case 7: goto L56b756; case 8: goto L56b7d0; case 9: goto L56b7ab; case 10: goto L56b84c; case 11: goto L56b81c; case 12: goto L56b8ce; default: __builtin_trap(); }  // @5_56b730
  L56b756:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3166), sizeof v); (u32)v; });  // @7_56b730
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3298), &v, sizeof v); }  // @8_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_56b730
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @10_56b730
  ecx = edx = 0;  // @11_56b730
  ecx = esi;  // @12_56b730
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 3302), &v, sizeof v); }  // @13_56b730
  eax = ext_56c6a0_thiscall1(ecx);  // @14_56b730
  ecx = edx = 0;  // @15_56b730
  ecx = esi;  // @16_56b730
  eax = ext_56b460_stdcall1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3298), sizeof v); (u32)v; }));  // @17_56b730
  ecx = edx = 0;  // @18_56b730
  return eax;  // @19_56b730
  L56b78a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_56b730
  if (eax == (u32)(1111)) goto L56b7ab;  // @22_56b730
  L56b794:;
  if (eax != (u32)(2222)) goto L56b8d6;  // @24_56b730
  eax = ext_564600_thiscall2(ecx, (u32)(3));  // @25_56b730
  ecx = edx = 0;  // @26_56b730
  return eax;  // @27_56b730
  L56b7ab:;
  eax = ext_564600_thiscall2(ecx, (u32)(1));  // @29_56b730
  ecx = edx = 0;  // @30_56b730
  return eax;  // @31_56b730
  L56b7b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_56b730
  if (eax != (u32)(1111)) goto L56b794;  // @34_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_56b730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, (u32)(0));  // @36_56b730
  ecx = edx = 0;  // @37_56b730
  return eax;  // @38_56b730
  L56b7d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 148), sizeof v); (u32)v; });  // @40_56b730
  ecx = (ecx + (u32)(87));  // @41_56b730
  eax = ext_5ae710_thiscall2(ecx, (u32)(0));  // @42_56b730
  ecx = edx = 0;  // @43_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_56b730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_56b730
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @47_56b730
  ecx = edx = 0;  // @48_56b730
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @49_56b730
  ecx = eax;  // @50_56b730
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6977404), (u32)(0), (u32)(2));  // @51_56b730
  ecx = edx = 0;  // @52_56b730
  ecx = esi;  // @53_56b730
  eax = ext_562bc0_thiscall1(ecx);  // @54_56b730
  ecx = edx = 0;  // @55_56b730
  return eax;  // @56_56b730
  L56b80f:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (u32)(3333)) goto L56b8d6;  // @58_56b730
  L56b81c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_56b730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(0));  // @61_56b730
  ecx = edx = 0;  // @62_56b730
  return eax;  // @63_56b730
  L56b82b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @65_56b730
  if (eax == (u32)(1111)) goto L56b81c;  // @66_56b730
  if (eax != (u32)(2222)) goto L56b8d6;  // @67_56b730
  eax = ext_564600_thiscall2(ecx, (u32)(0));  // @68_56b730
  ecx = edx = 0;  // @69_56b730
  return eax;  // @70_56b730
  L56b84c:;
  eax = ext_563440_thiscall1(ecx);  // @72_56b730
  ecx = edx = 0;  // @73_56b730
  return eax;  // @74_56b730
  L56b856:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3310), sizeof v); (u32)v; }) != (u32)(4)) goto L56b8d6;  // @76_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @77_56b730
  if (eax == (u32)(1111)) goto L56b81c;  // @78_56b730
  if (eax != (u32)(2222)) goto L56b8d6;  // @79_56b730
  eax = ext_563400_thiscall1(ecx);  // @80_56b730
  ecx = edx = 0;  // @81_56b730
  ecx = esi;  // @82_56b730
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L56b8a1;  // @83_56b730
  eax = ext_565100_thiscall2(ecx, (u32)(23));  // @84_56b730
  ecx = edx = 0;  // @85_56b730
  return eax;  // @86_56b730
  L56b887:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 3310), sizeof v); (u32)v; }) != (u32)(4)) goto L56b8d6;  // @88_56b730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @89_56b730
  if (eax == (u32)(1111)) goto L56b81c;  // @90_56b730
  if (eax != (u32)(2222)) goto L56b8d6;  // @91_56b730
  L56b8a1:;
  eax = ext_564600_thiscall2(ecx, (u32)(4));  // @93_56b730
  ecx = edx = 0;  // @94_56b730
  return eax;  // @95_56b730
  L56b8ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @97_56b730
  if (eax == (u32)(1111)) goto L56b81c;  // @98_56b730
  if (eax != (u32)(2222)) goto L56b8d6;  // @99_56b730
  eax = ext_564600_thiscall2(ecx, (u32)(5));  // @100_56b730
  ecx = edx = 0;  // @101_56b730
  return eax;  // @102_56b730
  L56b8ce:;
  eax = ext_5646e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @104_56b730
  ecx = edx = 0;  // @105_56b730
  L56b8d6:;
  return eax;  // @107_56b730
}
PCREG(56b730, lifted_56b730);

extern "C" u32 lifted_6261b0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_6261b0
  edx = 0;  // @1_6261b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6261b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_6261b0
  p0_ = edi;  // @4_6261b0
  if (esi == ebx) goto L626289;  // @5_6261b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_6261b0
  edi = ebx;  // @7_6261b0
  edi = (edi - esi);  // @8_6261b0
  L6261d1:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_6261b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @11_6261b0
  if (eax > (u32)(8)) goto L62627f;  // @12_6261b0
  switch (eax) { case 0: goto L6262b5; case 1: goto L6262b5; case 2: goto L626265; case 3: goto L62627f; case 4: goto L626293; case 5: goto L6261e9; case 6: goto L626215; case 7: goto L626241; case 8: goto L6262b5; default: __builtin_trap(); }  // @13_6261b0
  L6261e9:;
  if ((s32)edi < (s32)(u32)(2)) goto L6262c3;  // @15_6261b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 356), sizeof v); (u32)v; });  // @16_6261b0
  p1_ = esi;  // @17_6261b0
  p2_ = ecx;  // @18_6261b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_6261b0
  ecx = edx = 0;  // @20_6261b0
  if ((eax & eax) != 0) goto L6262b5;  // @21_6261b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_6261b0
  esi = (esi + (u32)(2));  // @23_6261b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @24_6261b0
  edi = (edi - (u32)(2));  // @25_6261b0
  goto L626281;  // @26_6261b0
  L626215:;
  if ((s32)edi < (s32)(u32)(3)) goto L6262c3;  // @28_6261b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 360), sizeof v); (u32)v; });  // @29_6261b0
  p3_ = esi;  // @30_6261b0
  p4_ = ecx;  // @31_6261b0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @32_6261b0
  ecx = edx = 0;  // @33_6261b0
  if ((eax & eax) != 0) goto L6262b5;  // @34_6261b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @35_6261b0
  esi = (esi + (u32)(3));  // @36_6261b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @37_6261b0
  edi = (edi - (u32)(3));  // @38_6261b0
  goto L626281;  // @39_6261b0
  L626241:;
  if ((s32)edi < (s32)(u32)(4)) goto L6262c3;  // @41_6261b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 364), sizeof v); (u32)v; });  // @42_6261b0
  p5_ = esi;  // @43_6261b0
  p6_ = ecx;  // @44_6261b0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @45_6261b0
  ecx = edx = 0;  // @46_6261b0
  if ((eax & eax) != 0) goto L6262b5;  // @47_6261b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @48_6261b0
  esi = (esi + (u32)(4));  // @49_6261b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @50_6261b0
  edi = (edi - (u32)(4));  // @51_6261b0
  goto L626281;  // @52_6261b0
  L626265:;
  esi = (esi + 1);  // @54_6261b0
  edi = (edi - 1);  // @55_6261b0
  if (esi == ebx) goto L626289;  // @56_6261b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(33)) goto L626281;  // @57_6261b0
  esi = (esi + 1);  // @58_6261b0
  edi = (edi - 1);  // @59_6261b0
  if (esi == ebx) goto L626289;  // @60_6261b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(91)) goto L626281;  // @61_6261b0
  edx = (edx + 1);  // @62_6261b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @63_6261b0
  L62627f:;
  esi = (esi + 1);  // @65_6261b0
  edi = (edi - 1);  // @66_6261b0
  L626281:;
  if (esi != ebx) goto L6261d1;  // @68_6261b0
  L626289:;
  eax = (eax | (u32)(4294967295));  // @70_6261b0
  return eax;  // @71_6261b0
  L626293:;
  esi = (esi + 1);  // @73_6261b0
  edi = (edi - 1);  // @74_6261b0
  if (esi == ebx) goto L626289;  // @75_6261b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(93)) goto L626281;  // @76_6261b0
  esi = (esi + 1);  // @77_6261b0
  edi = (edi - 1);  // @78_6261b0
  if (esi == ebx) goto L626289;  // @79_6261b0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(62)) goto L626281;  // @80_6261b0
  esi = (esi + 1);  // @81_6261b0
  edi = (edi - 1);  // @82_6261b0
  if ((edx & edx) == 0) goto L6262cf;  // @83_6261b0
  edx = (edx - 1);  // @84_6261b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @85_6261b0
  goto L626281;  // @86_6261b0
  L6262b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @88_6261b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @89_6261b0
  eax = 0;  // @90_6261b0
  return eax;  // @91_6261b0
  L6262c3:;
  eax = (u32)(4294967294);  // @93_6261b0
  return eax;  // @94_6261b0
  L6262cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @96_6261b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_6261b0
  eax = (u32)(42);  // @98_6261b0
  return eax;  // @99_6261b0
}
PCREG(6261b0, lifted_6261b0);

extern "C" u32 lifted_62dc60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62dc60
  eax = (u32)(edi - 11);  // @1_62dc60
  if (eax > (u32)(17)) goto L62dd5e;  // @2_62dc60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6479256), sizeof v); (u32)v; });  // @3_62dc60
  switch (eax) { case 0: goto L62dc83; case 1: goto L62dc8a; case 2: goto L62dd4e; case 3: goto L62dd44; case 4: goto L62dd5e; default: __builtin_trap(); }  // @4_62dc60
  L62dc83:;
  eax = 0;  // @6_62dc60
  return eax;  // @7_62dc60
  L62dc8a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @9_62dc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_62dc60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @11_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @12_62dc60
  p0_ = ebx;  // @13_62dc60
  eax = (u32)(ecx + eax*2);  // @14_62dc60
  p1_ = eax;  // @15_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @16_62dc60
  p2_ = esi;  // @17_62dc60
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(p2_), (u32)(p1_), (u32)(p0_), (u32)(7078280));  // @18_62dc60
  ecx = edx = 0;  // @19_62dc60
  if ((eax & eax) == 0) goto L62dcbd;  // @20_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_62dc60
  { u32 v = (u32)((u32)(6477712)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @22_62dc60
  eax = 0;  // @23_62dc60
  return eax;  // @24_62dc60
  L62dcbd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @26_62dc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @27_62dc60
  p3_ = ebx;  // @28_62dc60
  eax = (u32)(ecx + eax*2);  // @29_62dc60
  p4_ = eax;  // @30_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @31_62dc60
  p5_ = esi;  // @32_62dc60
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(p5_), (u32)(p4_), (u32)(p3_), (u32)(7078228));  // @33_62dc60
  ecx = edx = 0;  // @34_62dc60
  if ((eax & eax) == 0) goto L62dcea;  // @35_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_62dc60
  { u32 v = (u32)((u32)(6474192)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_62dc60
  eax = 0;  // @38_62dc60
  return eax;  // @39_62dc60
  L62dcea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @41_62dc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @42_62dc60
  p6_ = ebx;  // @43_62dc60
  eax = (u32)(ecx + eax*2);  // @44_62dc60
  p7_ = eax;  // @45_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @46_62dc60
  p8_ = esi;  // @47_62dc60
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(p8_), (u32)(p7_), (u32)(p6_), (u32)(7078252));  // @48_62dc60
  ecx = edx = 0;  // @49_62dc60
  if ((eax & eax) == 0) goto L62dd17;  // @50_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @51_62dc60
  { u32 v = (u32)((u32)(6476384)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @52_62dc60
  eax = 0;  // @53_62dc60
  return eax;  // @54_62dc60
  L62dd17:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @56_62dc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @57_62dc60
  p9_ = ebx;  // @58_62dc60
  eax = (u32)(ecx + eax*2);  // @59_62dc60
  p10_ = eax;  // @60_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @61_62dc60
  p11_ = esi;  // @62_62dc60
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(p11_), (u32)(p10_), (u32)(p9_), (u32)(7078368));  // @63_62dc60
  ecx = edx = 0;  // @64_62dc60
  if ((eax & eax) == 0) goto L62dd5e;  // @65_62dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @66_62dc60
  { u32 v = (u32)((u32)(6479280)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @67_62dc60
  eax = 0;  // @68_62dc60
  return eax;  // @69_62dc60
  L62dd44:;
  eax = (u32)(53);  // @71_62dc60
  return eax;  // @72_62dc60
  L62dd4e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @74_62dc60
  { u32 v = (u32)((u32)(6476304)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @75_62dc60
  eax = 0;  // @76_62dc60
  return eax;  // @77_62dc60
  L62dd5e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @79_62dc60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L62dd74;  // @80_62dc60
  if (edi != (u32)(28)) goto L62dd74;  // @81_62dc60
  eax = (u32)(edi + 24);  // @82_62dc60
  return eax;  // @83_62dc60
  L62dd74:;
  { u32 v = (u32)((u32)(5370416)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @85_62dc60
  eax = (eax | (u32)(4294967295));  // @86_62dc60
  return eax;  // @87_62dc60
}
PCREG(62dc60, lifted_62dc60);

extern "C" u32 THISCALL lifted_623080(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_623080
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1_623080
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6231c7;  // @2_623080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_623080
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_623080
  L6230a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @6_623080
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @7_623080
  ecx = (eax & 0xff);  // @8_623080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @9_623080
  if (ecx > (u32)(219)) goto L623179;  // @10_623080
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6435296), sizeof v); (u32)v; });  // @11_623080
  switch (ecx) { case 0: goto L6230c5; case 1: goto L6230e0; case 2: goto L623105; case 3: goto L623179; default: __builtin_trap(); }  // @12_623080
  L6230c5:;
  if ((ebx & 0xff) >= (u32)(128)) goto L6230e0;  // @14_623080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_623080
  if (eax != edx) goto L6231b4;  // @16_623080
  L6230d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @18_623080
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_623080
  return eax;  // @20_623080
  L6230e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_623080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @23_623080
  ecx = edx;  // @24_623080
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @25_623080
  if ((s32)ecx < (s32)(u32)(2)) goto L6230d4;  // @26_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(240))) & 0xff);  // @27_623080
  ecx = (ecx & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @28_623080
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) >> (u32)(6))) & 0xff);  // @29_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (u32)(2))) & 0xff);  // @30_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (ecx & 0xff))) & 0xff);  // @31_623080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @32_623080
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @33_623080
  goto L6231aa;  // @34_623080
  L623105:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_623080
  eax = edx;  // @37_623080
  eax = (eax - ecx);  // @38_623080
  if ((s32)eax < (s32)(u32)(4)) goto L6230d4;  // @39_623080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @40_623080
  edi = (edi + (u32)(2));  // @41_623080
  eax = (eax & (u32)(3));  // @42_623080
  edx = (ebx & 0xff);  // @43_623080
  eax = (eax << (u32)(2));  // @44_623080
  edx = (edx >> (u32)(6));  // @45_623080
  edx = (edx | eax);  // @46_623080
  edx = (edx + 1);  // @47_623080
  eax = edx;  // @48_623080
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) & (u32)(3))) & 0xff);  // @49_623080
  eax = (u32)((s32)eax >> (u32)(2));  // @50_623080
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) | (u32)(248))) & 0xff);  // @51_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(240))) & 0xff);  // @52_623080
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) << (u32)(4))) & 0xff);  // @53_623080
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @54_623080
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @55_623080
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @56_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(3))) & 0xff);  // @57_623080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (u32)(248))) & 0xff);  // @59_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) >> (u32)(2))) & 0xff);  // @60_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @61_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) << (u32)(2))) & 0xff);  // @62_623080
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) | (eax & 0xff))) & 0xff);  // @63_623080
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @64_623080
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @65_623080
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @66_623080
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @67_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(3))) & 0xff);  // @68_623080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @70_623080
  eax = (eax & 0xffffff00u) | (((edx & 0xff)) & 0xff);  // @71_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) << (u32)(2))) & 0xff);  // @72_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) >> (u32)(6))) & 0xff);  // @73_623080
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) & (u32)(63))) & 0xff);  // @74_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @75_623080
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @76_623080
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @77_623080
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) | (u32)(128))) & 0xff);  // @78_623080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_623080
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @80_623080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @81_623080
  goto L6231b6;  // @82_623080
  L623179:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @84_623080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_623080
  ecx = (ecx - edx);  // @86_623080
  if ((s32)ecx < (s32)(u32)(3)) goto L6230d4;  // @87_623080
  ecx = (ecx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @88_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @89_623080
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) >> (u32)(4))) & 0xff);  // @90_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(224))) & 0xff);  // @91_623080
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(224))) & 0xff);  // @92_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (u32)(2))) & 0xff);  // @93_623080
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @94_623080
  ecx = (ecx & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @95_623080
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @96_623080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_623080
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) >> (u32)(6))) & 0xff);  // @98_623080
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (ecx & 0xff))) & 0xff);  // @99_623080
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @100_623080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @101_623080
  L6231aa:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @103_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(63))) & 0xff);  // @104_623080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_623080
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (u32)(128))) & 0xff);  // @106_623080
  L6231b4:;
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @108_623080
  L6231b6:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @110_623080
  edi = (edi + (u32)(2));  // @111_623080
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6230a0;  // @112_623080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @113_623080
  L6231c7:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @115_623080
  return eax;  // @116_623080
}
PCREG(623080, lifted_623080);

extern "C" u32 THISCALL lifted_623940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_623940
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1_623940
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L623a87;  // @2_623940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_623940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_623940
  L623960:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @6_623940
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @7_623940
  ecx = (eax & 0xff);  // @8_623940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @9_623940
  if (ecx > (u32)(219)) goto L623a39;  // @10_623940
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6437536), sizeof v); (u32)v; });  // @11_623940
  switch (ecx) { case 0: goto L623985; case 1: goto L6239a0; case 2: goto L6239c5; case 3: goto L623a39; default: __builtin_trap(); }  // @12_623940
  L623985:;
  if ((ebx & 0xff) >= (u32)(128)) goto L6239a0;  // @14_623940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_623940
  if (eax != edx) goto L623a74;  // @16_623940
  L623994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @18_623940
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @19_623940
  return eax;  // @20_623940
  L6239a0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_623940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @23_623940
  ecx = edx;  // @24_623940
  ecx = (ecx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @25_623940
  if ((s32)ecx < (s32)(u32)(2)) goto L623994;  // @26_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(240))) & 0xff);  // @27_623940
  ecx = (ecx & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @28_623940
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) >> (u32)(6))) & 0xff);  // @29_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (u32)(2))) & 0xff);  // @30_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (ecx & 0xff))) & 0xff);  // @31_623940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @32_623940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @33_623940
  goto L623a6a;  // @34_623940
  L6239c5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_623940
  eax = edx;  // @37_623940
  eax = (eax - ecx);  // @38_623940
  if ((s32)eax < (s32)(u32)(4)) goto L623994;  // @39_623940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @40_623940
  edi = (edi + (u32)(2));  // @41_623940
  eax = (eax & (u32)(3));  // @42_623940
  edx = (ebx & 0xff);  // @43_623940
  eax = (eax << (u32)(2));  // @44_623940
  edx = (edx >> (u32)(6));  // @45_623940
  edx = (edx | eax);  // @46_623940
  edx = (edx + 1);  // @47_623940
  eax = edx;  // @48_623940
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) & (u32)(3))) & 0xff);  // @49_623940
  eax = (u32)((s32)eax >> (u32)(2));  // @50_623940
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) | (u32)(248))) & 0xff);  // @51_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(240))) & 0xff);  // @52_623940
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) << (u32)(4))) & 0xff);  // @53_623940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @54_623940
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @55_623940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @56_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(3))) & 0xff);  // @57_623940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (u32)(248))) & 0xff);  // @59_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) >> (u32)(2))) & 0xff);  // @60_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @61_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) << (u32)(2))) & 0xff);  // @62_623940
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) | (eax & 0xff))) & 0xff);  // @63_623940
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @64_623940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @65_623940
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @66_623940
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @67_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(3))) & 0xff);  // @68_623940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @70_623940
  eax = (eax & 0xffffff00u) | (((edx & 0xff)) & 0xff);  // @71_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) << (u32)(2))) & 0xff);  // @72_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) >> (u32)(6))) & 0xff);  // @73_623940
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) & (u32)(63))) & 0xff);  // @74_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (eax & 0xff))) & 0xff);  // @75_623940
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @76_623940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @77_623940
  edx = (edx & 0xffffff00u) | ((((edx & 0xff) | (u32)(128))) & 0xff);  // @78_623940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_623940
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @80_623940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @81_623940
  goto L623a76;  // @82_623940
  L623a39:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @84_623940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_623940
  ecx = (ecx - edx);  // @86_623940
  if ((s32)ecx < (s32)(u32)(3)) goto L623994;  // @87_623940
  ecx = (ecx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @88_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(15))) & 0xff);  // @89_623940
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) >> (u32)(4))) & 0xff);  // @90_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (u32)(224))) & 0xff);  // @91_623940
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) | (u32)(224))) & 0xff);  // @92_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (u32)(2))) & 0xff);  // @93_623940
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @94_623940
  ecx = (ecx & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @95_623940
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @96_623940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_623940
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) >> (u32)(6))) & 0xff);  // @98_623940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) | (ecx & 0xff))) & 0xff);  // @99_623940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @100_623940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @101_623940
  L623a6a:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @103_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(63))) & 0xff);  // @104_623940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_623940
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) | (u32)(128))) & 0xff);  // @106_623940
  L623a74:;
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @108_623940
  L623a76:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @110_623940
  edi = (edi + (u32)(2));  // @111_623940
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L623960;  // @112_623940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @113_623940
  L623a87:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @115_623940
  return eax;  // @116_623940
}
PCREG(623940, lifted_623940);

extern "C" u32 THISCALL lifted_627fd0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_627fd0
  p0_ = edi;  // @1_627fd0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_627fd0
  if (edx != edi) goto L627fe4;  // @3_627fd0
  eax = (eax | (u32)(4294967295));  // @4_627fd0
  return eax;  // @5_627fd0
  L627fe4:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @7_627fd0
  p1_ = ebx;  // @8_627fd0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @9_627fd0
  p2_ = esi;  // @10_627fd0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L627ffc;  // @11_627fd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_627fd0
  eax = (ecx & 0xff);  // @13_627fd0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @14_627fd0
  goto L628006;  // @15_627fd0
  L627ffc:;
  p3_ = ecx;  // @17_627fd0
  p4_ = ebx;  // @18_627fd0
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_627fd0
  ecx = edx = 0;  // @20_627fd0
  L628006:;
  eax = (eax - (u32)(5));  // @22_627fd0
  if (eax > (u32)(25)) goto L628118;  // @23_627fd0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6455616), sizeof v); (u32)v; });  // @24_627fd0
  switch (eax) { case 0: goto L6280c4; case 1: goto L6280d5; case 2: goto L6280e6; case 3: goto L628109; case 4: goto L62804c; case 5: goto L628020; case 6: goto L628118; default: __builtin_trap(); }  // @25_627fd0
  L628020:;
  eax = (ebx & 0xff);  // @27_627fd0
  ecx = (ecx & 0xff);  // @28_627fd0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @29_627fd0
  eax = ecx;  // @30_627fd0
  eax = (eax >> (u32)(5));  // @31_627fd0
  ecx = (ecx & (u32)(31));  // @32_627fd0
  esi = (u32)(eax + esi*8);  // @33_627fd0
  eax = (u32)(1);  // @34_627fd0
  eax = (eax << (ecx & 0xff));  // @35_627fd0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L628118;  // @36_627fd0
  L62804c:;
  edx = (edx + (u32)(2));  // @38_627fd0
  if (edx == edi) goto L6280bc;  // @39_627fd0
  L628053:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @41_627fd0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @42_627fd0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L628069;  // @43_627fd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_627fd0
  eax = (ecx & 0xff);  // @45_627fd0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @46_627fd0
  goto L628073;  // @47_627fd0
  L628069:;
  p5_ = ecx;  // @49_627fd0
  p6_ = ebx;  // @50_627fd0
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @51_627fd0
  ecx = edx = 0;  // @52_627fd0
  L628073:;
  eax = (eax - (u32)(5));  // @54_627fd0
  if (eax > (u32)(24)) goto L628118;  // @55_627fd0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6455672), sizeof v); (u32)v; });  // @56_627fd0
  switch (eax) { case 0: goto L6280c4; case 1: goto L6280d5; case 2: goto L6280e6; case 3: goto L6280f7; case 4: goto L6280b5; case 5: goto L62808d; case 6: goto L628118; default: __builtin_trap(); }  // @57_627fd0
  L62808d:;
  eax = (ebx & 0xff);  // @59_627fd0
  ecx = (ecx & 0xff);  // @60_627fd0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @61_627fd0
  eax = ecx;  // @62_627fd0
  eax = (eax >> (u32)(5));  // @63_627fd0
  ecx = (ecx & (u32)(31));  // @64_627fd0
  esi = (u32)(eax + esi*8);  // @65_627fd0
  eax = (u32)(1);  // @66_627fd0
  eax = (eax << (ecx & 0xff));  // @67_627fd0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L628118;  // @68_627fd0
  L6280b5:;
  edx = (edx + (u32)(2));  // @70_627fd0
  if (edx != edi) goto L628053;  // @71_627fd0
  L6280bc:;
  eax = (eax | (u32)(4294967295));  // @73_627fd0
  return eax;  // @74_627fd0
  L6280c4:;
  edi = (edi - edx);  // @76_627fd0
  if ((s32)edi >= (s32)(u32)(2)) goto L628118;  // @77_627fd0
  eax = (u32)(4294967294);  // @78_627fd0
  return eax;  // @79_627fd0
  L6280d5:;
  edi = (edi - edx);  // @81_627fd0
  if ((s32)edi >= (s32)(u32)(3)) goto L628118;  // @82_627fd0
  eax = (u32)(4294967294);  // @83_627fd0
  return eax;  // @84_627fd0
  L6280e6:;
  edi = (edi - edx);  // @86_627fd0
  if ((s32)edi >= (s32)(u32)(4)) goto L628118;  // @87_627fd0
  eax = (u32)(4294967294);  // @88_627fd0
  return eax;  // @89_627fd0
  L6280f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @91_627fd0
  edx = (edx + (u32)(2));  // @92_627fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @93_627fd0
  eax = (u32)(28);  // @94_627fd0
  return eax;  // @95_627fd0
  L628109:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @97_627fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @98_627fd0
  eax = (u32)(22);  // @99_627fd0
  return eax;  // @100_627fd0
  L628118:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @102_627fd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @103_627fd0
  eax = 0;  // @104_627fd0
  return eax;  // @105_627fd0
}
PCREG(627fd0, lifted_627fd0);

extern "C" u32 THISCALL lifted_62a030(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62a030
  p0_ = edi;  // @1_62a030
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_62a030
  if (edx != edi) goto L62a044;  // @3_62a030
  eax = (eax | (u32)(4294967295));  // @4_62a030
  return eax;  // @5_62a030
  L62a044:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_62a030
  p1_ = ebx;  // @8_62a030
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @9_62a030
  p2_ = esi;  // @10_62a030
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L62a05c;  // @11_62a030
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_62a030
  eax = (ecx & 0xff);  // @13_62a030
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @14_62a030
  goto L62a066;  // @15_62a030
  L62a05c:;
  p3_ = ecx;  // @17_62a030
  p4_ = ebx;  // @18_62a030
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_62a030
  ecx = edx = 0;  // @20_62a030
  L62a066:;
  eax = (eax - (u32)(5));  // @22_62a030
  if (eax > (u32)(25)) goto L62a178;  // @23_62a030
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6463904), sizeof v); (u32)v; });  // @24_62a030
  switch (eax) { case 0: goto L62a124; case 1: goto L62a135; case 2: goto L62a146; case 3: goto L62a169; case 4: goto L62a0ac; case 5: goto L62a080; case 6: goto L62a178; default: __builtin_trap(); }  // @25_62a030
  L62a080:;
  eax = (ebx & 0xff);  // @27_62a030
  ecx = (ecx & 0xff);  // @28_62a030
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @29_62a030
  eax = ecx;  // @30_62a030
  eax = (eax >> (u32)(5));  // @31_62a030
  ecx = (ecx & (u32)(31));  // @32_62a030
  esi = (u32)(eax + esi*8);  // @33_62a030
  eax = (u32)(1);  // @34_62a030
  eax = (eax << (ecx & 0xff));  // @35_62a030
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a178;  // @36_62a030
  L62a0ac:;
  edx = (edx + (u32)(2));  // @38_62a030
  if (edx == edi) goto L62a11c;  // @39_62a030
  L62a0b3:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @41_62a030
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @42_62a030
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L62a0c9;  // @43_62a030
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_62a030
  eax = (ecx & 0xff);  // @45_62a030
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @46_62a030
  goto L62a0d3;  // @47_62a030
  L62a0c9:;
  p5_ = ecx;  // @49_62a030
  p6_ = ebx;  // @50_62a030
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @51_62a030
  ecx = edx = 0;  // @52_62a030
  L62a0d3:;
  eax = (eax - (u32)(5));  // @54_62a030
  if (eax > (u32)(24)) goto L62a178;  // @55_62a030
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6463960), sizeof v); (u32)v; });  // @56_62a030
  switch (eax) { case 0: goto L62a124; case 1: goto L62a135; case 2: goto L62a146; case 3: goto L62a157; case 4: goto L62a115; case 5: goto L62a0ed; case 6: goto L62a178; default: __builtin_trap(); }  // @57_62a030
  L62a0ed:;
  eax = (ebx & 0xff);  // @59_62a030
  ecx = (ecx & 0xff);  // @60_62a030
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @61_62a030
  eax = ecx;  // @62_62a030
  eax = (eax >> (u32)(5));  // @63_62a030
  ecx = (ecx & (u32)(31));  // @64_62a030
  esi = (u32)(eax + esi*8);  // @65_62a030
  eax = (u32)(1);  // @66_62a030
  eax = (eax << (ecx & 0xff));  // @67_62a030
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a178;  // @68_62a030
  L62a115:;
  edx = (edx + (u32)(2));  // @70_62a030
  if (edx != edi) goto L62a0b3;  // @71_62a030
  L62a11c:;
  eax = (eax | (u32)(4294967295));  // @73_62a030
  return eax;  // @74_62a030
  L62a124:;
  edi = (edi - edx);  // @76_62a030
  if ((s32)edi >= (s32)(u32)(2)) goto L62a178;  // @77_62a030
  eax = (u32)(4294967294);  // @78_62a030
  return eax;  // @79_62a030
  L62a135:;
  edi = (edi - edx);  // @81_62a030
  if ((s32)edi >= (s32)(u32)(3)) goto L62a178;  // @82_62a030
  eax = (u32)(4294967294);  // @83_62a030
  return eax;  // @84_62a030
  L62a146:;
  edi = (edi - edx);  // @86_62a030
  if ((s32)edi >= (s32)(u32)(4)) goto L62a178;  // @87_62a030
  eax = (u32)(4294967294);  // @88_62a030
  return eax;  // @89_62a030
  L62a157:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @91_62a030
  edx = (edx + (u32)(2));  // @92_62a030
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @93_62a030
  eax = (u32)(28);  // @94_62a030
  return eax;  // @95_62a030
  L62a169:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @97_62a030
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @98_62a030
  eax = (u32)(22);  // @99_62a030
  return eax;  // @100_62a030
  L62a178:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @102_62a030
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @103_62a030
  eax = 0;  // @104_62a030
  return eax;  // @105_62a030
}
PCREG(62a030, lifted_62a030);

extern "C" u32 THISCALL lifted_474070(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_474070
  ebx = ecx;  // @1_474070
  p0_ = edi;  // @2_474070
  edi = 0;  // @3_474070
  if ((esi & esi) == 0) goto L47408d;  // @4_474070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_474070
  ecx = esi;  // @6_474070
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 816)))(ecx, (u32)(p0_));  // @7_474070
  ecx = edx = 0;  // @8_474070
  edi = eax;  // @9_474070
  L47408d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_474070
  ecx = ebx;  // @12_474070
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @13_474070
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2149580820));  // @14_474070
  ecx = edx = 0;  // @15_474070
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @16_474070
  edx = 0;  // @17_474070
  if (((eax & 0xff) & (eax & 0xff)) != 0) ecx = edx;  // @18_474070
  if (edi != (u32)(9)) goto L4740dd;  // @19_474070
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @20_474070
  ecx = (u32)(6801640);  // @21_474070
  edx = (u32)(6855348);  // @22_474070
  if ((eax & eax) != 0) ecx = eax;  // @23_474070
  eax = ext_4cc850_fastcall2(ecx, edx);  // @24_474070
  ecx = edx = 0;  // @25_474070
  ecx = (u32)(6855360);  // @26_474070
  edx = (u32)(6855372);  // @27_474070
  if ((eax & eax) != 0) ecx = edx;  // @28_474070
  eax = ecx;  // @29_474070
  return eax;  // @30_474070
  L4740dd:;
  if (edi != (u32)(8)) goto L4740f2;  // @32_474070
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L4740f2;  // @33_474070
  eax = (u32)(6855372);  // @34_474070
  return eax;  // @35_474070
  L4740f2:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @37_474070
  esi = 0;  // @38_474070
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_474070
  if (eax > (u32)(9)) goto L4741f9;  // @40_474070
  switch (eax) { case 0: goto L47410a; case 1: goto L4741cc; case 2: goto L4741f4; case 3: goto L4741f4; case 4: goto L474138; case 5: goto L474138; case 6: goto L47417c; case 7: goto L474151; case 8: goto L474151; case 9: goto L4741a4; default: __builtin_trap(); }  // @41_474070
  L47410a:;
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L474123;  // @43_474070
  L47410e:;
  esi = (u32)(6855384);  // @45_474070
  eax = (u32)(6855412);  // @46_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @47_474070
  goto L4741f9;  // @48_474070
  L474123:;
  esi = (u32)(6855436);  // @50_474070
  eax = (u32)(6855464);  // @51_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @52_474070
  goto L4741f9;  // @53_474070
  L474138:;
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L47410e;  // @55_474070
  esi = (u32)(6855492);  // @56_474070
  eax = (u32)(6855516);  // @57_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @58_474070
  goto L4741f9;  // @59_474070
  L474151:;
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L47416a;  // @61_474070
  esi = (u32)(6855540);  // @62_474070
  eax = (u32)(6855568);  // @63_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @64_474070
  goto L4741f9;  // @65_474070
  L47416a:;
  esi = (u32)(6855596);  // @67_474070
  eax = (u32)(6855620);  // @68_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @69_474070
  goto L4741f9;  // @70_474070
  L47417c:;
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L474192;  // @72_474070
  esi = (u32)(6855644);  // @73_474070
  eax = (u32)(6855664);  // @74_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @75_474070
  goto L4741f9;  // @76_474070
  L474192:;
  esi = (u32)(6855684);  // @78_474070
  eax = (u32)(6855708);  // @79_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @80_474070
  goto L4741f9;  // @81_474070
  L4741a4:;
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L4741ba;  // @83_474070
  esi = (u32)(6855732);  // @84_474070
  eax = (u32)(6855756);  // @85_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @86_474070
  goto L4741f9;  // @87_474070
  L4741ba:;
  esi = (u32)(6855776);  // @89_474070
  eax = (u32)(6855800);  // @90_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @91_474070
  goto L4741f9;  // @92_474070
  L4741cc:;
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L4741e2;  // @94_474070
  esi = (u32)(6855824);  // @95_474070
  eax = (u32)(6855844);  // @96_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @97_474070
  goto L4741f9;  // @98_474070
  L4741e2:;
  esi = (u32)(6855864);  // @100_474070
  eax = (u32)(6855884);  // @101_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (edx & 0xff)) esi = eax;  // @102_474070
  goto L4741f9;  // @103_474070
  L4741f4:;
  esi = (u32)(6855904);  // @105_474070
  L4741f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @107_474070
  ecx = ebx;  // @108_474070
  p1_ = esi;  // @109_474070
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 540)))(ecx, (u32)(p1_));  // @110_474070
  ecx = edx = 0;  // @111_474070
  if ((eax & eax) != 0) goto L474219;  // @112_474070
  esi = (u32)(6855924);  // @113_474070
  eax = (u32)(6855940);  // @114_474070
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) == (u32)(0)) esi = eax;  // @115_474070
  L474219:;
  eax = esi;  // @117_474070
  return eax;  // @118_474070
}
PCREG(474070, lifted_474070);

extern "C" u32 THISCALL lifted_628630(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_628630
  p0_ = edi;  // @1_628630
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_628630
  if (edx != edi) goto L628644;  // @3_628630
  eax = (eax | (u32)(4294967295));  // @4_628630
  return eax;  // @5_628630
  L628644:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_628630
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @8_628630
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @9_628630
  p1_ = ebx;  // @10_628630
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L62865e;  // @11_628630
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_628630
  eax = (ecx & 0xff);  // @13_628630
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @14_628630
  goto L62866b;  // @15_628630
  L62865e:;
  p2_ = ecx;  // @17_628630
  p3_ = eax;  // @18_628630
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_628630
  ecx = edx = 0;  // @20_628630
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_628630
  L62866b:;
  eax = (eax - (u32)(5));  // @23_628630
  p4_ = esi;  // @24_628630
  if (eax > (u32)(24)) goto L62878c;  // @25_628630
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6457268), sizeof v); (u32)v; });  // @26_628630
  switch (eax) { case 0: goto L628731; case 1: goto L628742; case 2: goto L628753; case 3: goto L628776; case 4: goto L6286b5; case 5: goto L628686; case 6: goto L62878c; default: __builtin_trap(); }  // @27_628630
  L628686:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @29_628630
  eax = (eax & 0xff);  // @30_628630
  ecx = (ecx & 0xff);  // @31_628630
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @32_628630
  eax = ecx;  // @33_628630
  eax = (eax >> (u32)(5));  // @34_628630
  ecx = (ecx & (u32)(31));  // @35_628630
  esi = (u32)(eax + esi*8);  // @36_628630
  eax = (u32)(1);  // @37_628630
  eax = (eax << (ecx & 0xff));  // @38_628630
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62878c;  // @39_628630
  L6286b5:;
  edx = (edx + (u32)(2));  // @41_628630
  if (edx == edi) goto L628729;  // @42_628630
  L6286c0:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @44_628630
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @45_628630
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6286d6;  // @46_628630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_628630
  eax = (ecx & 0xff);  // @48_628630
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @49_628630
  goto L6286e0;  // @50_628630
  L6286d6:;
  p5_ = ecx;  // @52_628630
  p6_ = ebx;  // @53_628630
  eax = ext_62c640_cdecl3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @54_628630
  ecx = edx = 0;  // @55_628630
  L6286e0:;
  eax = (eax - (u32)(5));  // @57_628630
  if (eax > (u32)(24)) goto L62878c;  // @58_628630
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6457324), sizeof v); (u32)v; });  // @59_628630
  switch (eax) { case 0: goto L628731; case 1: goto L628742; case 2: goto L628753; case 3: goto L628764; case 4: goto L628722; case 5: goto L6286fa; case 6: goto L62878c; default: __builtin_trap(); }  // @60_628630
  L6286fa:;
  eax = (ebx & 0xff);  // @62_628630
  ecx = (ecx & 0xff);  // @63_628630
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @64_628630
  eax = ecx;  // @65_628630
  eax = (eax >> (u32)(5));  // @66_628630
  ecx = (ecx & (u32)(31));  // @67_628630
  esi = (u32)(eax + esi*8);  // @68_628630
  eax = (u32)(1);  // @69_628630
  eax = (eax << (ecx & 0xff));  // @70_628630
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62878c;  // @71_628630
  L628722:;
  edx = (edx + (u32)(2));  // @73_628630
  if (edx != edi) goto L6286c0;  // @74_628630
  L628729:;
  eax = (eax | (u32)(4294967295));  // @76_628630
  return eax;  // @77_628630
  L628731:;
  edi = (edi - edx);  // @79_628630
  if ((s32)edi >= (s32)(u32)(2)) goto L62878c;  // @80_628630
  eax = (u32)(4294967294);  // @81_628630
  return eax;  // @82_628630
  L628742:;
  edi = (edi - edx);  // @84_628630
  if ((s32)edi >= (s32)(u32)(3)) goto L62878c;  // @85_628630
  eax = (u32)(4294967294);  // @86_628630
  return eax;  // @87_628630
  L628753:;
  edi = (edi - edx);  // @89_628630
  if ((s32)edi >= (s32)(u32)(4)) goto L62878c;  // @90_628630
  eax = (u32)(4294967294);  // @91_628630
  return eax;  // @92_628630
  L628764:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @94_628630
  edx = (edx + (u32)(2));  // @95_628630
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @96_628630
  eax = (u32)(9);  // @97_628630
  return eax;  // @98_628630
  L628776:;
  edx = (edx + (u32)(2));  // @100_628630
  p7_ = edi;  // @101_628630
  p8_ = edx;  // @102_628630
  p9_ = ebx;  // @103_628630
  eax = ext_627470_cdecl4((u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @104_628630
  ecx = edx = 0;  // @105_628630
  return eax;  // @106_628630
  L62878c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @108_628630
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @109_628630
  eax = 0;  // @110_628630
  return eax;  // @111_628630
}
PCREG(628630, lifted_628630);

extern "C" u32 THISCALL lifted_62a690(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62a690
  p0_ = edi;  // @1_62a690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_62a690
  if (edx != edi) goto L62a6a4;  // @3_62a690
  eax = (eax | (u32)(4294967295));  // @4_62a690
  return eax;  // @5_62a690
  L62a6a4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @7_62a690
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @8_62a690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @9_62a690
  p1_ = ebx;  // @10_62a690
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L62a6be;  // @11_62a690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_62a690
  eax = (ecx & 0xff);  // @13_62a690
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @14_62a690
  goto L62a6cb;  // @15_62a690
  L62a6be:;
  p2_ = ecx;  // @17_62a690
  p3_ = eax;  // @18_62a690
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_62a690
  ecx = edx = 0;  // @20_62a690
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_62a690
  L62a6cb:;
  eax = (eax - (u32)(5));  // @23_62a690
  p4_ = esi;  // @24_62a690
  if (eax > (u32)(24)) goto L62a7ec;  // @25_62a690
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6465556), sizeof v); (u32)v; });  // @26_62a690
  switch (eax) { case 0: goto L62a791; case 1: goto L62a7a2; case 2: goto L62a7b3; case 3: goto L62a7d6; case 4: goto L62a715; case 5: goto L62a6e6; case 6: goto L62a7ec; default: __builtin_trap(); }  // @27_62a690
  L62a6e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @29_62a690
  eax = (eax & 0xff);  // @30_62a690
  ecx = (ecx & 0xff);  // @31_62a690
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @32_62a690
  eax = ecx;  // @33_62a690
  eax = (eax >> (u32)(5));  // @34_62a690
  ecx = (ecx & (u32)(31));  // @35_62a690
  esi = (u32)(eax + esi*8);  // @36_62a690
  eax = (u32)(1);  // @37_62a690
  eax = (eax << (ecx & 0xff));  // @38_62a690
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a7ec;  // @39_62a690
  L62a715:;
  edx = (edx + (u32)(2));  // @41_62a690
  if (edx == edi) goto L62a789;  // @42_62a690
  L62a720:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @44_62a690
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @45_62a690
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L62a736;  // @46_62a690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_62a690
  eax = (ecx & 0xff);  // @48_62a690
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @49_62a690
  goto L62a740;  // @50_62a690
  L62a736:;
  p5_ = ecx;  // @52_62a690
  p6_ = ebx;  // @53_62a690
  eax = ext_62c640_cdecl3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @54_62a690
  ecx = edx = 0;  // @55_62a690
  L62a740:;
  eax = (eax - (u32)(5));  // @57_62a690
  if (eax > (u32)(24)) goto L62a7ec;  // @58_62a690
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6465612), sizeof v); (u32)v; });  // @59_62a690
  switch (eax) { case 0: goto L62a791; case 1: goto L62a7a2; case 2: goto L62a7b3; case 3: goto L62a7c4; case 4: goto L62a782; case 5: goto L62a75a; case 6: goto L62a7ec; default: __builtin_trap(); }  // @60_62a690
  L62a75a:;
  eax = (ebx & 0xff);  // @62_62a690
  ecx = (ecx & 0xff);  // @63_62a690
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @64_62a690
  eax = ecx;  // @65_62a690
  eax = (eax >> (u32)(5));  // @66_62a690
  ecx = (ecx & (u32)(31));  // @67_62a690
  esi = (u32)(eax + esi*8);  // @68_62a690
  eax = (u32)(1);  // @69_62a690
  eax = (eax << (ecx & 0xff));  // @70_62a690
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a7ec;  // @71_62a690
  L62a782:;
  edx = (edx + (u32)(2));  // @73_62a690
  if (edx != edi) goto L62a720;  // @74_62a690
  L62a789:;
  eax = (eax | (u32)(4294967295));  // @76_62a690
  return eax;  // @77_62a690
  L62a791:;
  edi = (edi - edx);  // @79_62a690
  if ((s32)edi >= (s32)(u32)(2)) goto L62a7ec;  // @80_62a690
  eax = (u32)(4294967294);  // @81_62a690
  return eax;  // @82_62a690
  L62a7a2:;
  edi = (edi - edx);  // @84_62a690
  if ((s32)edi >= (s32)(u32)(3)) goto L62a7ec;  // @85_62a690
  eax = (u32)(4294967294);  // @86_62a690
  return eax;  // @87_62a690
  L62a7b3:;
  edi = (edi - edx);  // @89_62a690
  if ((s32)edi >= (s32)(u32)(4)) goto L62a7ec;  // @90_62a690
  eax = (u32)(4294967294);  // @91_62a690
  return eax;  // @92_62a690
  L62a7c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @94_62a690
  edx = (edx + (u32)(2));  // @95_62a690
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @96_62a690
  eax = (u32)(9);  // @97_62a690
  return eax;  // @98_62a690
  L62a7d6:;
  edx = (edx + (u32)(2));  // @100_62a690
  p7_ = edi;  // @101_62a690
  p8_ = edx;  // @102_62a690
  p9_ = ebx;  // @103_62a690
  eax = ext_6294d0_cdecl4((u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @104_62a690
  ecx = edx = 0;  // @105_62a690
  return eax;  // @106_62a690
  L62a7ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @108_62a690
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @109_62a690
  eax = 0;  // @110_62a690
  return eax;  // @111_62a690
}
PCREG(62a690, lifted_62a690);

extern "C" u32 lifted_62be60(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62be60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_62be60
  if (esi != ebx) goto L62be76;  // @2_62be60
  eax = (eax | (u32)(4294967295));  // @3_62be60
  return eax;  // @4_62be60
  L62be76:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_62be60
  p0_ = edi;  // @7_62be60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62be60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @9_62be60
  eax = (eax + (u32)(-5));  // @10_62be60
  if (eax > (u32)(24)) goto L62bfd9;  // @11_62be60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6471680), sizeof v); (u32)v; });  // @12_62be60
  switch (eax) { case 0: goto L62bea3; case 1: goto L62bec8; case 2: goto L62beed; case 3: goto L62be9c; case 4: goto L62bfd9; case 5: goto L62bfd9; default: __builtin_trap(); }  // @13_62be60
  L62be9c:;
  eax = (u32)(1);  // @15_62be60
  goto L62bf1a;  // @16_62be60
  L62bea3:;
  eax = ebx;  // @18_62be60
  eax = (eax - esi);  // @19_62be60
  if ((s32)eax < (s32)(u32)(2)) goto L62bef6;  // @20_62be60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 344), sizeof v); (u32)v; });  // @21_62be60
  p1_ = esi;  // @22_62be60
  p2_ = edi;  // @23_62be60
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @24_62be60
  ecx = edx = 0;  // @25_62be60
  if ((eax & eax) == 0) goto L62bfd9;  // @26_62be60
  eax = (u32)(2);  // @27_62be60
  goto L62bf1a;  // @28_62be60
  L62bec8:;
  eax = ebx;  // @30_62be60
  eax = (eax - esi);  // @31_62be60
  if ((s32)eax < (s32)(u32)(3)) goto L62bef6;  // @32_62be60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 348), sizeof v); (u32)v; });  // @33_62be60
  p3_ = esi;  // @34_62be60
  p4_ = edi;  // @35_62be60
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @36_62be60
  ecx = edx = 0;  // @37_62be60
  if ((eax & eax) == 0) goto L62bfd9;  // @38_62be60
  eax = (u32)(3);  // @39_62be60
  goto L62bf1a;  // @40_62be60
  L62beed:;
  eax = ebx;  // @42_62be60
  eax = (eax - esi);  // @43_62be60
  if ((s32)eax >= (s32)(u32)(4)) goto L62bf00;  // @44_62be60
  L62bef6:;
  eax = (u32)(4294967294);  // @46_62be60
  return eax;  // @47_62be60
  L62bf00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 352), sizeof v); (u32)v; });  // @49_62be60
  p5_ = esi;  // @50_62be60
  p6_ = edi;  // @51_62be60
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @52_62be60
  ecx = edx = 0;  // @53_62be60
  if ((eax & eax) == 0) goto L62bfd9;  // @54_62be60
  eax = (u32)(4);  // @55_62be60
  L62bf1a:;
  esi = (esi + eax);  // @57_62be60
  if (esi == ebx) goto L62bfc0;  // @58_62be60
  L62bf24:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_62be60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @61_62be60
  eax = (eax + (u32)(-5));  // @62_62be60
  if (eax > (u32)(31)) goto L62bfd9;  // @63_62be60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6471736), sizeof v); (u32)v; });  // @64_62be60
  switch (eax) { case 0: goto L62bf4d; case 1: goto L62bf6e; case 2: goto L62bf93; case 3: goto L62bfca; case 4: goto L62bf46; case 5: goto L62bfd9; case 6: goto L62bfd9; default: __builtin_trap(); }  // @65_62be60
  L62bf46:;
  eax = (u32)(1);  // @67_62be60
  goto L62bfb6;  // @68_62be60
  L62bf4d:;
  eax = ebx;  // @70_62be60
  eax = (eax - esi);  // @71_62be60
  if ((s32)eax < (s32)(u32)(2)) goto L62bef6;  // @72_62be60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 332), sizeof v); (u32)v; });  // @73_62be60
  p7_ = esi;  // @74_62be60
  p8_ = edi;  // @75_62be60
  eax = ((u32( *)(u32, u32))(eax))((u32)(p8_), (u32)(p7_));  // @76_62be60
  ecx = edx = 0;  // @77_62be60
  if ((eax & eax) == 0) goto L62bfd9;  // @78_62be60
  eax = (u32)(2);  // @79_62be60
  goto L62bfb6;  // @80_62be60
  L62bf6e:;
  eax = ebx;  // @82_62be60
  eax = (eax - esi);  // @83_62be60
  if ((s32)eax < (s32)(u32)(3)) goto L62bef6;  // @84_62be60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 336), sizeof v); (u32)v; });  // @85_62be60
  p9_ = esi;  // @86_62be60
  p10_ = edi;  // @87_62be60
  eax = ((u32( *)(u32, u32))(eax))((u32)(p10_), (u32)(p9_));  // @88_62be60
  ecx = edx = 0;  // @89_62be60
  if ((eax & eax) == 0) goto L62bfd9;  // @90_62be60
  eax = (u32)(3);  // @91_62be60
  goto L62bfb6;  // @92_62be60
  L62bf93:;
  eax = ebx;  // @94_62be60
  eax = (eax - esi);  // @95_62be60
  if ((s32)eax < (s32)(u32)(4)) goto L62bef6;  // @96_62be60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 340), sizeof v); (u32)v; });  // @97_62be60
  p11_ = esi;  // @98_62be60
  p12_ = edi;  // @99_62be60
  eax = ((u32( *)(u32, u32))(eax))((u32)(p12_), (u32)(p11_));  // @100_62be60
  ecx = edx = 0;  // @101_62be60
  if ((eax & eax) == 0) goto L62bfd9;  // @102_62be60
  eax = (u32)(4);  // @103_62be60
  L62bfb6:;
  esi = (esi + eax);  // @105_62be60
  if (esi != ebx) goto L62bf24;  // @106_62be60
  L62bfc0:;
  eax = (u32)(4294967276);  // @108_62be60
  return eax;  // @109_62be60
  L62bfca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @111_62be60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @112_62be60
  eax = (u32)(20);  // @113_62be60
  return eax;  // @114_62be60
  L62bfd9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @116_62be60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @117_62be60
  eax = 0;  // @118_62be60
  return eax;  // @119_62be60
}
PCREG(62be60, lifted_62be60);

extern "C" u32 lifted_62b900(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62b900
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_62b900
  if (esi != ebx) goto L62b916;  // @2_62b900
  eax = (eax | (u32)(4294967295));  // @3_62b900
  return eax;  // @4_62b900
  L62b916:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_62b900
  p0_ = edi;  // @7_62b900
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62b900
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @9_62b900
  eax = (eax + (u32)(-5));  // @10_62b900
  if (eax > (u32)(25)) goto L62ba8d;  // @11_62b900
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6470328), sizeof v); (u32)v; });  // @12_62b900
  switch (eax) { case 0: goto L62b943; case 1: goto L62b968; case 2: goto L62b98d; case 3: goto L62ba7e; case 4: goto L62b93c; case 5: goto L62ba8d; case 6: goto L62ba8d; default: __builtin_trap(); }  // @13_62b900
  L62b93c:;
  eax = (u32)(1);  // @15_62b900
  goto L62b9ba;  // @16_62b900
  L62b943:;
  eax = ebx;  // @18_62b900
  eax = (eax - esi);  // @19_62b900
  if ((s32)eax < (s32)(u32)(2)) goto L62b996;  // @20_62b900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 344), sizeof v); (u32)v; });  // @21_62b900
  p1_ = esi;  // @22_62b900
  p2_ = edi;  // @23_62b900
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @24_62b900
  ecx = edx = 0;  // @25_62b900
  if ((eax & eax) == 0) goto L62ba8d;  // @26_62b900
  eax = (u32)(2);  // @27_62b900
  goto L62b9ba;  // @28_62b900
  L62b968:;
  eax = ebx;  // @30_62b900
  eax = (eax - esi);  // @31_62b900
  if ((s32)eax < (s32)(u32)(3)) goto L62b996;  // @32_62b900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 348), sizeof v); (u32)v; });  // @33_62b900
  p3_ = esi;  // @34_62b900
  p4_ = edi;  // @35_62b900
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @36_62b900
  ecx = edx = 0;  // @37_62b900
  if ((eax & eax) == 0) goto L62ba8d;  // @38_62b900
  eax = (u32)(3);  // @39_62b900
  goto L62b9ba;  // @40_62b900
  L62b98d:;
  eax = ebx;  // @42_62b900
  eax = (eax - esi);  // @43_62b900
  if ((s32)eax >= (s32)(u32)(4)) goto L62b9a0;  // @44_62b900
  L62b996:;
  eax = (u32)(4294967294);  // @46_62b900
  return eax;  // @47_62b900
  L62b9a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 352), sizeof v); (u32)v; });  // @49_62b900
  p5_ = esi;  // @50_62b900
  p6_ = edi;  // @51_62b900
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @52_62b900
  ecx = edx = 0;  // @53_62b900
  if ((eax & eax) == 0) goto L62ba8d;  // @54_62b900
  eax = (u32)(4);  // @55_62b900
  L62b9ba:;
  esi = (esi + eax);  // @57_62b900
  if (esi == ebx) goto L62ba64;  // @58_62b900
  L62b9c4:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_62b900
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @61_62b900
  eax = (eax + (u32)(-5));  // @62_62b900
  if (eax > (u32)(24)) goto L62ba8d;  // @63_62b900
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6470384), sizeof v); (u32)v; });  // @64_62b900
  switch (eax) { case 0: goto L62b9ed; case 1: goto L62ba12; case 2: goto L62ba37; case 3: goto L62ba6c; case 4: goto L62b9e6; case 5: goto L62ba8d; case 6: goto L62ba8d; default: __builtin_trap(); }  // @65_62b900
  L62b9e6:;
  eax = (u32)(1);  // @67_62b900
  goto L62ba5a;  // @68_62b900
  L62b9ed:;
  eax = ebx;  // @70_62b900
  eax = (eax - esi);  // @71_62b900
  if ((s32)eax < (s32)(u32)(2)) goto L62b996;  // @72_62b900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 332), sizeof v); (u32)v; });  // @73_62b900
  p7_ = esi;  // @74_62b900
  p8_ = edi;  // @75_62b900
  eax = ((u32( *)(u32, u32))(eax))((u32)(p8_), (u32)(p7_));  // @76_62b900
  ecx = edx = 0;  // @77_62b900
  if ((eax & eax) == 0) goto L62ba8d;  // @78_62b900
  eax = (u32)(2);  // @79_62b900
  goto L62ba5a;  // @80_62b900
  L62ba12:;
  eax = ebx;  // @82_62b900
  eax = (eax - esi);  // @83_62b900
  if ((s32)eax < (s32)(u32)(3)) goto L62b996;  // @84_62b900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 336), sizeof v); (u32)v; });  // @85_62b900
  p9_ = esi;  // @86_62b900
  p10_ = edi;  // @87_62b900
  eax = ((u32( *)(u32, u32))(eax))((u32)(p10_), (u32)(p9_));  // @88_62b900
  ecx = edx = 0;  // @89_62b900
  if ((eax & eax) == 0) goto L62ba8d;  // @90_62b900
  eax = (u32)(3);  // @91_62b900
  goto L62ba5a;  // @92_62b900
  L62ba37:;
  eax = ebx;  // @94_62b900
  eax = (eax - esi);  // @95_62b900
  if ((s32)eax < (s32)(u32)(4)) goto L62b996;  // @96_62b900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 340), sizeof v); (u32)v; });  // @97_62b900
  p11_ = esi;  // @98_62b900
  p12_ = edi;  // @99_62b900
  eax = ((u32( *)(u32, u32))(eax))((u32)(p12_), (u32)(p11_));  // @100_62b900
  ecx = edx = 0;  // @101_62b900
  if ((eax & eax) == 0) goto L62ba8d;  // @102_62b900
  eax = (u32)(4);  // @103_62b900
  L62ba5a:;
  esi = (esi + eax);  // @105_62b900
  if (esi != ebx) goto L62b9c4;  // @106_62b900
  L62ba64:;
  eax = (eax | (u32)(4294967295));  // @108_62b900
  return eax;  // @109_62b900
  L62ba6c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @111_62b900
  ecx = (u32)(esi + 1);  // @112_62b900
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @113_62b900
  eax = (u32)(28);  // @114_62b900
  return eax;  // @115_62b900
  L62ba7e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @117_62b900
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @118_62b900
  eax = (u32)(22);  // @119_62b900
  return eax;  // @120_62b900
  L62ba8d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @122_62b900
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @123_62b900
  eax = 0;  // @124_62b900
  return eax;  // @125_62b900
}
PCREG(62b900, lifted_62b900);

extern "C" u32 lifted_6277b0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6277b0
  p0_ = edi;  // @1_6277b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_6277b0
  if (edx != edi) goto L6277c4;  // @3_6277b0
  eax = (eax | (u32)(4294967295));  // @4_6277b0
  return eax;  // @5_6277b0
  L6277c4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_6277b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @8_6277b0
  p1_ = ebx;  // @9_6277b0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @10_6277b0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6277de;  // @11_6277b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_6277b0
  eax = (ebx & 0xff);  // @13_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @14_6277b0
  goto L6277e8;  // @15_6277b0
  L6277de:;
  p2_ = ebx;  // @17_6277b0
  p3_ = eax;  // @18_6277b0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_6277b0
  ecx = edx = 0;  // @20_6277b0
  L6277e8:;
  eax = (eax - (u32)(5));  // @22_6277b0
  p4_ = esi;  // @23_6277b0
  if (eax > (u32)(24)) goto L627948;  // @24_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6453612), sizeof v); (u32)v; });  // @25_6277b0
  switch (eax) { case 0: goto L6278b8; case 1: goto L6278cd; case 2: goto L627937; case 3: goto L627832; case 4: goto L627803; case 5: goto L627948; default: __builtin_trap(); }  // @26_6277b0
  L627803:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @28_6277b0
  eax = (eax & 0xff);  // @29_6277b0
  ecx = (ebx & 0xff);  // @30_6277b0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @31_6277b0
  eax = ecx;  // @32_6277b0
  eax = (eax >> (u32)(5));  // @33_6277b0
  ecx = (ecx & (u32)(31));  // @34_6277b0
  esi = (u32)(eax + esi*8);  // @35_6277b0
  eax = (u32)(1);  // @36_6277b0
  eax = (eax << (ecx & 0xff));  // @37_6277b0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L627948;  // @38_6277b0
  L627832:;
  edx = (edx + (u32)(2));  // @40_6277b0
  if (edx == edi) goto L6278b0;  // @41_6277b0
  L627840:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @43_6277b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @44_6277b0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L627856;  // @45_6277b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @46_6277b0
  eax = (ecx & 0xff);  // @47_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @48_6277b0
  goto L627863;  // @49_6277b0
  L627856:;
  p5_ = ecx;  // @51_6277b0
  p6_ = ebx;  // @52_6277b0
  eax = ext_62c640_cdecl3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @53_6277b0
  ecx = edx = 0;  // @54_6277b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_6277b0
  L627863:;
  eax = (eax - (u32)(5));  // @57_6277b0
  if (eax > (u32)(24)) goto L627948;  // @58_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6453672), sizeof v); (u32)v; });  // @59_6277b0
  switch (eax) { case 0: goto L6278b8; case 1: goto L6278cd; case 2: goto L627937; case 3: goto L6278de; case 4: goto L627925; case 5: goto L6278a9; case 6: goto L62787d; case 7: goto L627948; default: __builtin_trap(); }  // @60_6277b0
  L62787d:;
  eax = (ebx & 0xff);  // @62_6277b0
  ecx = (ecx & 0xff);  // @63_6277b0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @64_6277b0
  eax = ecx;  // @65_6277b0
  eax = (eax >> (u32)(5));  // @66_6277b0
  ecx = (ecx & (u32)(31));  // @67_6277b0
  esi = (u32)(eax + esi*8);  // @68_6277b0
  eax = (u32)(1);  // @69_6277b0
  eax = (eax << (ecx & 0xff));  // @70_6277b0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L627948;  // @71_6277b0
  L6278a9:;
  edx = (edx + (u32)(2));  // @73_6277b0
  if (edx != edi) goto L627840;  // @74_6277b0
  L6278b0:;
  eax = (eax | (u32)(4294967295));  // @76_6277b0
  return eax;  // @77_6277b0
  L6278b8:;
  edi = (edi - edx);  // @79_6277b0
  if ((s32)edi >= (s32)(u32)(2)) goto L627948;  // @80_6277b0
  eax = (u32)(4294967294);  // @81_6277b0
  return eax;  // @82_6277b0
  L6278cd:;
  edi = (edi - edx);  // @84_6277b0
  if ((s32)edi >= (s32)(u32)(3)) goto L627948;  // @85_6277b0
  eax = (u32)(4294967294);  // @86_6277b0
  return eax;  // @87_6277b0
  L6278de:;
  edx = (edx + (u32)(2));  // @89_6277b0
  if (edx == edi) goto L6278b0;  // @90_6277b0
  L6278e5:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @92_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @93_6277b0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L6278f6;  // @94_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @95_6277b0
  goto L627900;  // @96_6277b0
  L6278f6:;
  p7_ = eax;  // @98_6277b0
  p8_ = ecx;  // @99_6277b0
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @100_6277b0
  ecx = edx = 0;  // @101_6277b0
  L627900:;
  eax = (eax - (u32)(9));  // @103_6277b0
  if (eax > (u32)(12)) goto L627948;  // @104_6277b0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6453712), sizeof v); (u32)v; });  // @105_6277b0
  switch (eax) { case 0: goto L627916; case 1: goto L627925; case 2: goto L627948; default: __builtin_trap(); }  // @106_6277b0
  L627916:;
  edx = (edx + (u32)(2));  // @108_6277b0
  if (edx != edi) goto L6278e5;  // @109_6277b0
  eax = (eax | (u32)(4294967295));  // @110_6277b0
  return eax;  // @111_6277b0
  L627925:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @113_6277b0
  edx = (edx + (u32)(2));  // @114_6277b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @115_6277b0
  eax = (u32)(5);  // @116_6277b0
  return eax;  // @117_6277b0
  L627937:;
  edi = (edi - edx);  // @119_6277b0
  if ((s32)edi >= (s32)(u32)(4)) goto L627948;  // @120_6277b0
  eax = (u32)(4294967294);  // @121_6277b0
  return eax;  // @122_6277b0
  L627948:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @124_6277b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @125_6277b0
  eax = 0;  // @126_6277b0
  return eax;  // @127_6277b0
}
PCREG(6277b0, lifted_6277b0);

extern "C" u32 lifted_629810(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_629810
  p0_ = edi;  // @1_629810
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_629810
  if (edx != edi) goto L629824;  // @3_629810
  eax = (eax | (u32)(4294967295));  // @4_629810
  return eax;  // @5_629810
  L629824:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @7_629810
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @8_629810
  p1_ = ebx;  // @9_629810
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @10_629810
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L62983e;  // @11_629810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_629810
  eax = (ebx & 0xff);  // @13_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @14_629810
  goto L629848;  // @15_629810
  L62983e:;
  p2_ = ebx;  // @17_629810
  p3_ = eax;  // @18_629810
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_629810
  ecx = edx = 0;  // @20_629810
  L629848:;
  eax = (eax - (u32)(5));  // @22_629810
  p4_ = esi;  // @23_629810
  if (eax > (u32)(24)) goto L6299a8;  // @24_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6461900), sizeof v); (u32)v; });  // @25_629810
  switch (eax) { case 0: goto L629918; case 1: goto L62992d; case 2: goto L629997; case 3: goto L629892; case 4: goto L629863; case 5: goto L6299a8; default: __builtin_trap(); }  // @26_629810
  L629863:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @28_629810
  eax = (eax & 0xff);  // @29_629810
  ecx = (ebx & 0xff);  // @30_629810
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @31_629810
  eax = ecx;  // @32_629810
  eax = (eax >> (u32)(5));  // @33_629810
  ecx = (ecx & (u32)(31));  // @34_629810
  esi = (u32)(eax + esi*8);  // @35_629810
  eax = (u32)(1);  // @36_629810
  eax = (eax << (ecx & 0xff));  // @37_629810
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L6299a8;  // @38_629810
  L629892:;
  edx = (edx + (u32)(2));  // @40_629810
  if (edx == edi) goto L629910;  // @41_629810
  L6298a0:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @43_629810
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @44_629810
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6298b6;  // @45_629810
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @46_629810
  eax = (ecx & 0xff);  // @47_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @48_629810
  goto L6298c3;  // @49_629810
  L6298b6:;
  p5_ = ecx;  // @51_629810
  p6_ = ebx;  // @52_629810
  eax = ext_62c640_cdecl3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @53_629810
  ecx = edx = 0;  // @54_629810
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_629810
  L6298c3:;
  eax = (eax - (u32)(5));  // @57_629810
  if (eax > (u32)(24)) goto L6299a8;  // @58_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6461960), sizeof v); (u32)v; });  // @59_629810
  switch (eax) { case 0: goto L629918; case 1: goto L62992d; case 2: goto L629997; case 3: goto L62993e; case 4: goto L629985; case 5: goto L629909; case 6: goto L6298dd; case 7: goto L6299a8; default: __builtin_trap(); }  // @60_629810
  L6298dd:;
  eax = (ebx & 0xff);  // @62_629810
  ecx = (ecx & 0xff);  // @63_629810
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @64_629810
  eax = ecx;  // @65_629810
  eax = (eax >> (u32)(5));  // @66_629810
  ecx = (ecx & (u32)(31));  // @67_629810
  esi = (u32)(eax + esi*8);  // @68_629810
  eax = (u32)(1);  // @69_629810
  eax = (eax << (ecx & 0xff));  // @70_629810
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L6299a8;  // @71_629810
  L629909:;
  edx = (edx + (u32)(2));  // @73_629810
  if (edx != edi) goto L6298a0;  // @74_629810
  L629910:;
  eax = (eax | (u32)(4294967295));  // @76_629810
  return eax;  // @77_629810
  L629918:;
  edi = (edi - edx);  // @79_629810
  if ((s32)edi >= (s32)(u32)(2)) goto L6299a8;  // @80_629810
  eax = (u32)(4294967294);  // @81_629810
  return eax;  // @82_629810
  L62992d:;
  edi = (edi - edx);  // @84_629810
  if ((s32)edi >= (s32)(u32)(3)) goto L6299a8;  // @85_629810
  eax = (u32)(4294967294);  // @86_629810
  return eax;  // @87_629810
  L62993e:;
  edx = (edx + (u32)(2));  // @89_629810
  if (edx == edi) goto L629910;  // @90_629810
  L629945:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @92_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @93_629810
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L629956;  // @94_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @95_629810
  goto L629960;  // @96_629810
  L629956:;
  p7_ = eax;  // @98_629810
  p8_ = ecx;  // @99_629810
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @100_629810
  ecx = edx = 0;  // @101_629810
  L629960:;
  eax = (eax - (u32)(9));  // @103_629810
  if (eax > (u32)(12)) goto L6299a8;  // @104_629810
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6462000), sizeof v); (u32)v; });  // @105_629810
  switch (eax) { case 0: goto L629976; case 1: goto L629985; case 2: goto L6299a8; default: __builtin_trap(); }  // @106_629810
  L629976:;
  edx = (edx + (u32)(2));  // @108_629810
  if (edx != edi) goto L629945;  // @109_629810
  eax = (eax | (u32)(4294967295));  // @110_629810
  return eax;  // @111_629810
  L629985:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @113_629810
  edx = (edx + (u32)(2));  // @114_629810
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @115_629810
  eax = (u32)(5);  // @116_629810
  return eax;  // @117_629810
  L629997:;
  edi = (edi - edx);  // @119_629810
  if ((s32)edi >= (s32)(u32)(4)) goto L6299a8;  // @120_629810
  eax = (u32)(4294967294);  // @121_629810
  return eax;  // @122_629810
  L6299a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @124_629810
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @125_629810
  eax = 0;  // @126_629810
  return eax;  // @127_629810
}
PCREG(629810, lifted_629810);

extern "C" u32 lifted_62c060(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62c060
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_62c060
  if (esi != ebx) goto L62c076;  // @2_62c060
  eax = (eax | (u32)(4294967295));  // @3_62c060
  return eax;  // @4_62c060
  L62c076:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_62c060
  p0_ = edi;  // @7_62c060
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62c060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @9_62c060
  eax = (eax + (u32)(-5));  // @10_62c060
  if (eax > (u32)(24)) goto L62c1f4;  // @11_62c060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6472220), sizeof v); (u32)v; });  // @12_62c060
  switch (eax) { case 0: goto L62c0a3; case 1: goto L62c0c8; case 2: goto L62c0ed; case 3: goto L62c1de; case 4: goto L62c09c; case 5: goto L62c1f4; case 6: goto L62c1f4; default: __builtin_trap(); }  // @13_62c060
  L62c09c:;
  eax = (u32)(1);  // @15_62c060
  goto L62c11a;  // @16_62c060
  L62c0a3:;
  eax = ebx;  // @18_62c060
  eax = (eax - esi);  // @19_62c060
  if ((s32)eax < (s32)(u32)(2)) goto L62c0f6;  // @20_62c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 344), sizeof v); (u32)v; });  // @21_62c060
  p1_ = esi;  // @22_62c060
  p2_ = edi;  // @23_62c060
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @24_62c060
  ecx = edx = 0;  // @25_62c060
  if ((eax & eax) == 0) goto L62c1f4;  // @26_62c060
  eax = (u32)(2);  // @27_62c060
  goto L62c11a;  // @28_62c060
  L62c0c8:;
  eax = ebx;  // @30_62c060
  eax = (eax - esi);  // @31_62c060
  if ((s32)eax < (s32)(u32)(3)) goto L62c0f6;  // @32_62c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 348), sizeof v); (u32)v; });  // @33_62c060
  p3_ = esi;  // @34_62c060
  p4_ = edi;  // @35_62c060
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @36_62c060
  ecx = edx = 0;  // @37_62c060
  if ((eax & eax) == 0) goto L62c1f4;  // @38_62c060
  eax = (u32)(3);  // @39_62c060
  goto L62c11a;  // @40_62c060
  L62c0ed:;
  eax = ebx;  // @42_62c060
  eax = (eax - esi);  // @43_62c060
  if ((s32)eax >= (s32)(u32)(4)) goto L62c100;  // @44_62c060
  L62c0f6:;
  eax = (u32)(4294967294);  // @46_62c060
  return eax;  // @47_62c060
  L62c100:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 352), sizeof v); (u32)v; });  // @49_62c060
  p5_ = esi;  // @50_62c060
  p6_ = edi;  // @51_62c060
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @52_62c060
  ecx = edx = 0;  // @53_62c060
  if ((eax & eax) == 0) goto L62c1f4;  // @54_62c060
  eax = (u32)(4);  // @55_62c060
  L62c11a:;
  esi = (esi + eax);  // @57_62c060
  if (esi == ebx) goto L62c1c4;  // @58_62c060
  L62c124:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_62c060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @61_62c060
  eax = (eax + (u32)(-5));  // @62_62c060
  if (eax > (u32)(24)) goto L62c1f4;  // @63_62c060
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6472276), sizeof v); (u32)v; });  // @64_62c060
  switch (eax) { case 0: goto L62c14d; case 1: goto L62c172; case 2: goto L62c197; case 3: goto L62c1cc; case 4: goto L62c146; case 5: goto L62c1f4; case 6: goto L62c1f4; default: __builtin_trap(); }  // @65_62c060
  L62c146:;
  eax = (u32)(1);  // @67_62c060
  goto L62c1ba;  // @68_62c060
  L62c14d:;
  eax = ebx;  // @70_62c060
  eax = (eax - esi);  // @71_62c060
  if ((s32)eax < (s32)(u32)(2)) goto L62c0f6;  // @72_62c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 332), sizeof v); (u32)v; });  // @73_62c060
  p7_ = esi;  // @74_62c060
  p8_ = edi;  // @75_62c060
  eax = ((u32( *)(u32, u32))(eax))((u32)(p8_), (u32)(p7_));  // @76_62c060
  ecx = edx = 0;  // @77_62c060
  if ((eax & eax) == 0) goto L62c1f4;  // @78_62c060
  eax = (u32)(2);  // @79_62c060
  goto L62c1ba;  // @80_62c060
  L62c172:;
  eax = ebx;  // @82_62c060
  eax = (eax - esi);  // @83_62c060
  if ((s32)eax < (s32)(u32)(3)) goto L62c0f6;  // @84_62c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 336), sizeof v); (u32)v; });  // @85_62c060
  p9_ = esi;  // @86_62c060
  p10_ = edi;  // @87_62c060
  eax = ((u32( *)(u32, u32))(eax))((u32)(p10_), (u32)(p9_));  // @88_62c060
  ecx = edx = 0;  // @89_62c060
  if ((eax & eax) == 0) goto L62c1f4;  // @90_62c060
  eax = (u32)(3);  // @91_62c060
  goto L62c1ba;  // @92_62c060
  L62c197:;
  eax = ebx;  // @94_62c060
  eax = (eax - esi);  // @95_62c060
  if ((s32)eax < (s32)(u32)(4)) goto L62c0f6;  // @96_62c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 340), sizeof v); (u32)v; });  // @97_62c060
  p11_ = esi;  // @98_62c060
  p12_ = edi;  // @99_62c060
  eax = ((u32( *)(u32, u32))(eax))((u32)(p12_), (u32)(p11_));  // @100_62c060
  ecx = edx = 0;  // @101_62c060
  if ((eax & eax) == 0) goto L62c1f4;  // @102_62c060
  eax = (u32)(4);  // @103_62c060
  L62c1ba:;
  esi = (esi + eax);  // @105_62c060
  if (esi != ebx) goto L62c124;  // @106_62c060
  L62c1c4:;
  eax = (eax | (u32)(4294967295));  // @108_62c060
  return eax;  // @109_62c060
  L62c1cc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @111_62c060
  ecx = (u32)(esi + 1);  // @112_62c060
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @113_62c060
  eax = (u32)(9);  // @114_62c060
  return eax;  // @115_62c060
  L62c1de:;
  eax = (u32)(esi + 1);  // @117_62c060
  p13_ = ebx;  // @118_62c060
  p14_ = eax;  // @119_62c060
  p15_ = edi;  // @120_62c060
  eax = ext_62ad60_cdecl4((u32)(p15_), (u32)(p14_), (u32)(p13_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @121_62c060
  ecx = edx = 0;  // @122_62c060
  return eax;  // @123_62c060
  L62c1f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @125_62c060
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @126_62c060
  eax = 0;  // @127_62c060
  return eax;  // @128_62c060
}
PCREG(62c060, lifted_62c060);

extern "C" u32 THISCALL lifted_4d7350(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ecx;  // @0_4d7350
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21), sizeof v); (u32)v; });  // @2_4d7350
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 30), sizeof v); (u32)v; }), (u32)(0));  // @5_4d7350
  ecx = edx = 0;  // @6_4d7350
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @7_4d7350
  if ((eax & eax) == 0) goto L4d74de;  // @8_4d7350
  p0_ = edi;  // @9_4d7350
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @10_4d7350
  if (eax == (u32)(8)) goto L4d73b7;  // @11_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @12_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(1133), (u32)(p0_));  // @14_4d7350
  ecx = edx = 0;  // @15_4d7350
  p1_ = eax;  // @16_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p1_), (u32)(6908312));  // @18_4d7350
  ecx = edx = 0;  // @19_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @20_4d7350
  edi = (edi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; }));  // @21_4d7350
  eax = edi;  // @22_4d7350
  return eax;  // @23_4d7350
  L4d73b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1070), sizeof v); (u32)v; });  // @25_4d7350
  eax = (eax - (u32)(0));  // @26_4d7350
  if (eax == 0) goto L4d73de;  // @27_4d7350
  eax = (eax - (u32)(1));  // @28_4d7350
  if (eax == 0) goto L4d73d3;  // @29_4d7350
  eax = (eax | (u32)(4294967295));  // @30_4d7350
  return eax;  // @31_4d7350
  L4d73d3:;
  eax = 0;  // @33_4d7350
  return eax;  // @34_4d7350
  L4d73de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @36_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @37_4d7350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @38_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @39_4d7350
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @40_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @41_4d7350
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L4d74bf;  // @42_4d7350
  L4d7400:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1070), sizeof v); (u32)v; }) != (u32)(0)) goto L4d74b9;  // @44_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @45_4d7350
  ebx = (u32)(esi + 46);  // @46_4d7350
  edi = (u32)(1024);  // @47_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @48_4d7350
  edi = (edi - eax);  // @49_4d7350
  p2_ = eax;  // @50_4d7350
  eax = (u32)(ebx + edi);  // @51_4d7350
  p3_ = eax;  // @52_4d7350
  p4_ = ebx;  // @53_4d7350
  eax = ext_634d22_cdecl3((u32)(p4_), (u32)(p3_), (u32)(p2_));  // @54_4d7350
  ecx = edx = 0;  // @55_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; });  // @56_4d7350
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 30), sizeof v); (u32)v; }));  // @57_4d7350
  if (eax < edi) edi = eax;  // @58_4d7350
  if ((edi & edi) == 0) goto L4d7450;  // @59_4d7350
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @60_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21), sizeof v); (u32)v; });  // @61_4d7350
  p5_ = edi;  // @62_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_4d7350
  p6_ = ebx;  // @64_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 17), sizeof v); (u32)v; }));  // @65_4d7350
  ecx = edx = 0;  // @66_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @67_4d7350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @68_4d7350
  L4d7450:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @70_4d7350
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @71_4d7350
  eax = ext_62f5d0_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; }), (u32)(3));  // @72_4d7350
  ecx = edx = 0;  // @73_4d7350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1070), &v, sizeof v); }  // @74_4d7350
  eax = (eax + (u32)(3));  // @75_4d7350
  if (eax > (u32)(4)) goto L4d7489;  // @76_4d7350
  switch (eax) { case 0: goto L4d7474; case 1: goto L4d747b; case 2: goto L4d7482; case 3: goto L4d74ac; case 4: goto L4d74ac; default: __builtin_trap(); }  // @77_4d7350
  L4d7474:;
  goto L4d748e;  // @79_4d7350
  L4d747b:;
  goto L4d748e;  // @81_4d7350
  L4d7482:;
  goto L4d748e;  // @83_4d7350
  L4d7489:;
  L4d748e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(1119), (u32)(1113), (u32)(1110), (u32)(1107));  // @88_4d7350
  ecx = edx = 0;  // @89_4d7350
  p7_ = eax;  // @90_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_4d7350
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p7_), (u32)(6908576));  // @92_4d7350
  ecx = edx = 0;  // @93_4d7350
  L4d74ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @95_4d7350
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }) != (u32)(0)) goto L4d7400;  // @96_4d7350
  L4d74b9:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @98_4d7350
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @99_4d7350
  L4d74bf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21), sizeof v); (u32)v; });  // @101_4d7350
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_4d7350
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; }));  // @103_4d7350
  ecx = edx = 0;  // @104_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 38), sizeof v); (u32)v; });  // @105_4d7350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 30), &v, sizeof v); }  // @106_4d7350
  edi = (edi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; }));  // @107_4d7350
  eax = edi;  // @108_4d7350
  return eax;  // @109_4d7350
  L4d74de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21), sizeof v); (u32)v; });  // @111_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 30), sizeof v); (u32)v; }), (u32)(0));  // @113_4d7350
  ecx = edx = 0;  // @114_4d7350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21), sizeof v); (u32)v; });  // @115_4d7350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_4d7350
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; }));  // @117_4d7350
  ecx = edx = 0;  // @118_4d7350
  return eax;  // @119_4d7350
}
PCREG(4d7350, lifted_4d7350);

extern "C" u32 lifted_62b040(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62b040
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_62b040
  if (esi != ebx) goto L62b056;  // @2_62b040
  eax = (eax | (u32)(4294967295));  // @3_62b040
  return eax;  // @4_62b040
  L62b056:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_62b040
  p0_ = edi;  // @7_62b040
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62b040
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @9_62b040
  eax = (eax + (u32)(-5));  // @10_62b040
  if (eax > (u32)(24)) goto L62b1ee;  // @11_62b040
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6468116), sizeof v); (u32)v; });  // @12_62b040
  switch (eax) { case 0: goto L62b083; case 1: goto L62b0a8; case 2: goto L62b0cd; case 3: goto L62b07c; case 4: goto L62b1ee; case 5: goto L62b1ee; default: __builtin_trap(); }  // @13_62b040
  L62b07c:;
  eax = (u32)(1);  // @15_62b040
  goto L62b0fa;  // @16_62b040
  L62b083:;
  eax = ebx;  // @18_62b040
  eax = (eax - esi);  // @19_62b040
  if ((s32)eax < (s32)(u32)(2)) goto L62b0d6;  // @20_62b040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 344), sizeof v); (u32)v; });  // @21_62b040
  p1_ = esi;  // @22_62b040
  p2_ = edi;  // @23_62b040
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @24_62b040
  ecx = edx = 0;  // @25_62b040
  if ((eax & eax) == 0) goto L62b1ee;  // @26_62b040
  eax = (u32)(2);  // @27_62b040
  goto L62b0fa;  // @28_62b040
  L62b0a8:;
  eax = ebx;  // @30_62b040
  eax = (eax - esi);  // @31_62b040
  if ((s32)eax < (s32)(u32)(3)) goto L62b0d6;  // @32_62b040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 348), sizeof v); (u32)v; });  // @33_62b040
  p3_ = esi;  // @34_62b040
  p4_ = edi;  // @35_62b040
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @36_62b040
  ecx = edx = 0;  // @37_62b040
  if ((eax & eax) == 0) goto L62b1ee;  // @38_62b040
  eax = (u32)(3);  // @39_62b040
  goto L62b0fa;  // @40_62b040
  L62b0cd:;
  eax = ebx;  // @42_62b040
  eax = (eax - esi);  // @43_62b040
  if ((s32)eax >= (s32)(u32)(4)) goto L62b0e0;  // @44_62b040
  L62b0d6:;
  eax = (u32)(4294967294);  // @46_62b040
  return eax;  // @47_62b040
  L62b0e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 352), sizeof v); (u32)v; });  // @49_62b040
  p5_ = esi;  // @50_62b040
  p6_ = edi;  // @51_62b040
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @52_62b040
  ecx = edx = 0;  // @53_62b040
  if ((eax & eax) == 0) goto L62b1ee;  // @54_62b040
  eax = (u32)(4);  // @55_62b040
  L62b0fa:;
  esi = (esi + eax);  // @57_62b040
  if (esi == ebx) goto L62b1a4;  // @58_62b040
  L62b104:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_62b040
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @61_62b040
  eax = (eax + (u32)(-5));  // @62_62b040
  if (eax > (u32)(24)) goto L62b1ee;  // @63_62b040
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6468176), sizeof v); (u32)v; });  // @64_62b040
  switch (eax) { case 0: goto L62b126; case 1: goto L62b14b; case 2: goto L62b170; case 3: goto L62b1ac; case 4: goto L62b1dc; case 5: goto L62b195; case 6: goto L62b1ee; case 7: goto L62b1ee; default: __builtin_trap(); }  // @65_62b040
  L62b126:;
  eax = ebx;  // @67_62b040
  eax = (eax - esi);  // @68_62b040
  if ((s32)eax < (s32)(u32)(2)) goto L62b0d6;  // @69_62b040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 332), sizeof v); (u32)v; });  // @70_62b040
  p7_ = esi;  // @71_62b040
  p8_ = edi;  // @72_62b040
  eax = ((u32( *)(u32, u32))(eax))((u32)(p8_), (u32)(p7_));  // @73_62b040
  ecx = edx = 0;  // @74_62b040
  if ((eax & eax) == 0) goto L62b1ee;  // @75_62b040
  eax = (u32)(2);  // @76_62b040
  goto L62b19a;  // @77_62b040
  L62b14b:;
  eax = ebx;  // @79_62b040
  eax = (eax - esi);  // @80_62b040
  if ((s32)eax < (s32)(u32)(3)) goto L62b0d6;  // @81_62b040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 336), sizeof v); (u32)v; });  // @82_62b040
  p9_ = esi;  // @83_62b040
  p10_ = edi;  // @84_62b040
  eax = ((u32( *)(u32, u32))(eax))((u32)(p10_), (u32)(p9_));  // @85_62b040
  ecx = edx = 0;  // @86_62b040
  if ((eax & eax) == 0) goto L62b1ee;  // @87_62b040
  eax = (u32)(3);  // @88_62b040
  goto L62b19a;  // @89_62b040
  L62b170:;
  eax = ebx;  // @91_62b040
  eax = (eax - esi);  // @92_62b040
  if ((s32)eax < (s32)(u32)(4)) goto L62b0d6;  // @93_62b040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 340), sizeof v); (u32)v; });  // @94_62b040
  p11_ = esi;  // @95_62b040
  p12_ = edi;  // @96_62b040
  eax = ((u32( *)(u32, u32))(eax))((u32)(p12_), (u32)(p11_));  // @97_62b040
  ecx = edx = 0;  // @98_62b040
  if ((eax & eax) == 0) goto L62b1ee;  // @99_62b040
  eax = (u32)(4);  // @100_62b040
  goto L62b19a;  // @101_62b040
  L62b195:;
  eax = (u32)(1);  // @103_62b040
  L62b19a:;
  esi = (esi + eax);  // @105_62b040
  if (esi != ebx) goto L62b104;  // @106_62b040
  L62b1a4:;
  eax = (eax | (u32)(4294967295));  // @108_62b040
  return eax;  // @109_62b040
  L62b1ac:;
  esi = (esi + 1);  // @111_62b040
  if (esi == ebx) goto L62b1a4;  // @112_62b040
  L62b1b1:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_62b040
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @115_62b040
  eax = (eax + (u32)(-9));  // @116_62b040
  if (eax > (u32)(12)) goto L62b1ee;  // @117_62b040
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6468216), sizeof v); (u32)v; });  // @118_62b040
  switch (eax) { case 0: goto L62b1cf; case 1: goto L62b1dc; case 2: goto L62b1ee; default: __builtin_trap(); }  // @119_62b040
  L62b1cf:;
  esi = (esi + 1);  // @121_62b040
  if (esi != ebx) goto L62b1b1;  // @122_62b040
  eax = (eax | (u32)(4294967295));  // @123_62b040
  return eax;  // @124_62b040
  L62b1dc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @126_62b040
  ecx = (u32)(esi + 1);  // @127_62b040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @128_62b040
  eax = (u32)(5);  // @129_62b040
  return eax;  // @130_62b040
  L62b1ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @132_62b040
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @133_62b040
  eax = 0;  // @134_62b040
  return eax;  // @135_62b040
}
PCREG(62b040, lifted_62b040);

extern "C" u32 lifted_626640(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_626640
  edx = (u32)(1);  // @1_626640
  edi = 0;  // @2_626640
  ecx = (ecx + 1);  // @3_626640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_626640
  ebx = (u32)(ecx + 1);  // @5_626640
  L626658:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @7_626640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_626640
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 15), &v, sizeof v); }  // @9_626640
  eax = (eax & 0xff);  // @10_626640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @11_626640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @12_626640
  eax = (eax + (u32)(-3));  // @13_626640
  if (eax > (u32)(26)) goto L6267f6;  // @14_626640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6449204), sizeof v); (u32)v; });  // @15_626640
  switch (eax) { case 0: goto L6267e1; case 1: goto L626685; case 2: goto L62669f; case 3: goto L6266bd; case 4: goto L6267ce; case 5: goto L6267f1; case 6: goto L6266fd; case 7: goto L62673f; case 8: goto L626781; case 9: goto L6266de; case 10: goto L6267f6; default: __builtin_trap(); }  // @16_626640
  L626685:;
  if ((edx & edx) != 0) goto L626699;  // @18_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L626694;  // @19_626640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @20_626640
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @21_626640
  L626694:;
  edx = (u32)(1);  // @23_626640
  L626699:;
  ecx = (ecx + 1);  // @25_626640
  ebx = (ebx + 1);  // @26_626640
  ecx = (ecx + 1);  // @27_626640
  ebx = (ebx + 1);  // @28_626640
  goto L626658;  // @29_626640
  L62669f:;
  if ((edx & edx) != 0) goto L6266b3;  // @31_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6266ae;  // @32_626640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @33_626640
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @34_626640
  L6266ae:;
  edx = (u32)(1);  // @36_626640
  L6266b3:;
  ecx = (ecx + (u32)(2));  // @38_626640
  ebx = (ebx + (u32)(2));  // @39_626640
  ecx = (ecx + 1);  // @40_626640
  ebx = (ebx + 1);  // @41_626640
  goto L626658;  // @42_626640
  L6266bd:;
  if ((edx & edx) != 0) goto L6266d1;  // @44_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6266cc;  // @45_626640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @46_626640
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @47_626640
  L6266cc:;
  edx = (u32)(1);  // @49_626640
  L6266d1:;
  ecx = (ecx + (u32)(3));  // @51_626640
  ebx = (ebx + (u32)(3));  // @52_626640
  ecx = (ecx + 1);  // @53_626640
  ebx = (ebx + 1);  // @54_626640
  goto L626658;  // @55_626640
  L6266de:;
  if ((edx & edx) != 0) goto L6267f6;  // @57_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6266f1;  // @58_626640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @59_626640
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @60_626640
  L6266f1:;
  ecx = (ecx + 1);  // @62_626640
  edx = (u32)(1);  // @63_626640
  ebx = (ebx + 1);  // @64_626640
  goto L626658;  // @65_626640
  L6266fd:;
  if (edx == (u32)(2)) goto L62671d;  // @67_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L62670a;  // @68_626640
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @69_626640
  L62670a:;
  ecx = (ecx + 1);  // @71_626640
  { u32 v = (u32)((u32)(12)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @72_626640
  edx = (u32)(2);  // @73_626640
  ebx = (ebx + 1);  // @74_626640
  goto L626658;  // @75_626640
  L62671d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) != (u32)(12)) goto L6267f6;  // @77_626640
  edx = 0;  // @78_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L626731;  // @79_626640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @80_626640
  L626731:;
  esi = (esi + (u32)(16));  // @82_626640
  edi = (edi + 1);  // @83_626640
  ecx = (ecx + 1);  // @84_626640
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @85_626640
  ebx = (ebx + 1);  // @86_626640
  goto L626658;  // @87_626640
  L62673f:;
  if (edx == (u32)(2)) goto L62675f;  // @89_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L62674c;  // @90_626640
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @91_626640
  L62674c:;
  ecx = (ecx + 1);  // @93_626640
  { u32 v = (u32)((u32)(13)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @94_626640
  edx = (u32)(2);  // @95_626640
  ebx = (ebx + 1);  // @96_626640
  goto L626658;  // @97_626640
  L62675f:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) != (u32)(13)) goto L6267f6;  // @99_626640
  edx = 0;  // @100_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L626731;  // @101_626640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @102_626640
  edi = (edi + 1);  // @103_626640
  esi = (esi + (u32)(16));  // @104_626640
  ecx = (ecx + 1);  // @105_626640
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @106_626640
  ebx = (ebx + 1);  // @107_626640
  goto L626658;  // @108_626640
  L626781:;
  if (edx != (u32)(1)) goto L62678f;  // @110_626640
  edx = 0;  // @111_626640
  ecx = (ecx + 1);  // @112_626640
  ebx = (ebx + 1);  // @113_626640
  goto L626658;  // @114_626640
  L62678f:;
  if (edx != (u32)(2)) goto L6267f6;  // @116_626640
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6267f6;  // @117_626640
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L6267f6;  // @118_626640
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) goto L6267c3;  // @119_626640
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 15), sizeof v); (u32)v; }) != (u32)(32)) goto L6267c3;  // @120_626640
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @121_626640
  if ((eax & 0xff) == (u32)(32)) goto L6267c3;  // @122_626640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @123_626640
  eax = (eax & 0xff);  // @124_626640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @125_626640
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @126_626640
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })) goto L6267f6;  // @127_626640
  L6267c3:;
  ecx = (ecx + 1);  // @129_626640
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @130_626640
  ebx = (ebx + 1);  // @131_626640
  goto L626658;  // @132_626640
  L6267ce:;
  if (edx != (u32)(1)) goto L6267dc;  // @134_626640
  edx = 0;  // @135_626640
  ecx = (ecx + 1);  // @136_626640
  ebx = (ebx + 1);  // @137_626640
  goto L626658;  // @138_626640
  L6267dc:;
  if (edx != (u32)(2)) goto L6267f6;  // @140_626640
  L6267e1:;
  if ((s32)edi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L6267f6;  // @142_626640
  ecx = (ecx + 1);  // @143_626640
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @144_626640
  ebx = (ebx + 1);  // @145_626640
  goto L626658;  // @146_626640
  L6267f1:;
  if (edx != (u32)(2)) goto L6267fd;  // @148_626640
  L6267f6:;
  ecx = (ecx + 1);  // @150_626640
  ebx = (ebx + 1);  // @151_626640
  goto L626658;  // @152_626640
  L6267fd:;
  eax = edi;  // @154_626640
  return eax;  // @155_626640
}
PCREG(626640, lifted_626640);

extern "C" u32 lifted_622080(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_622080
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_622080
  p0_ = edi;  // @2_622080
  edi = ecx;  // @3_622080
  if (ecx != edx) goto L622098;  // @4_622080
  eax = (u32)(4294967292);  // @5_622080
  return eax;  // @6_622080
  L622098:;
  eax = edx;  // @8_622080
  eax = (eax - ecx);  // @9_622080
  if (((eax & 0xff) & (u32)(1)) == 0) goto L6220ae;  // @10_622080
  eax = (eax & (u32)(4294967294));  // @11_622080
  if (eax != 0) goto L6220ab;  // @12_622080
  eax = (eax | (u32)(4294967295));  // @13_622080
  return eax;  // @14_622080
  L6220ab:;
  edx = (u32)(eax + ecx);  // @16_622080
  L6220ae:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @18_622080
  p1_ = ebx;  // @19_622080
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @20_622080
  p2_ = esi;  // @21_622080
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_622080
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6220c4;  // @23_622080
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @24_622080
  goto L6220ce;  // @25_622080
  L6220c4:;
  p3_ = eax;  // @27_622080
  p4_ = ebx;  // @28_622080
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @29_622080
  ecx = edx = 0;  // @30_622080
  L6220ce:;
  if (eax > (u32)(10)) goto L6221a2;  // @32_622080
  switch (eax) { case 0: goto L622196; case 1: goto L622196; case 2: goto L6221a2; case 3: goto L6221a2; case 4: goto L6220de; case 5: goto L622167; case 6: goto L62217a; case 7: goto L622188; case 8: goto L622196; case 9: goto L622125; case 10: goto L622155; case 11: goto L6221f2; case 12: goto L6221de; case 13: goto L622201; case 14: goto L622211; case 15: goto L6221e7; default: __builtin_trap(); }  // @33_622080
  L6220de:;
  ecx = (ecx + (u32)(2));  // @35_622080
  eax = ecx;  // @36_622080
  if (ecx == edx) goto L62212c;  // @37_622080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L6221a5;  // @38_622080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(93)) goto L6221a5;  // @39_622080
  ecx = (ecx + (u32)(2));  // @40_622080
  if (ecx == edx) goto L62212c;  // @41_622080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L62211e;  // @42_622080
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(62)) goto L62211e;  // @43_622080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @44_622080
  ecx = (ecx + (u32)(2));  // @45_622080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_622080
  eax = (u32)(40);  // @47_622080
  return eax;  // @48_622080
  L62211e:;
  ecx = eax;  // @50_622080
  goto L6221a5;  // @51_622080
  L622125:;
  ecx = (ecx + (u32)(2));  // @53_622080
  if (ecx != edx) goto L622134;  // @54_622080
  L62212c:;
  eax = (eax | (u32)(4294967295));  // @56_622080
  return eax;  // @57_622080
  L622134:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @59_622080
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @60_622080
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L622145;  // @61_622080
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @62_622080
  goto L62214f;  // @63_622080
  L622145:;
  p5_ = eax;  // @65_622080
  p6_ = edx;  // @66_622080
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @67_622080
  ecx = edx = 0;  // @68_622080
  L62214f:;
  if (eax != (u32)(10)) ecx = edi;  // @70_622080
  L622155:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @72_622080
  ecx = (ecx + (u32)(2));  // @73_622080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @74_622080
  eax = (u32)(7);  // @75_622080
  return eax;  // @76_622080
  L622167:;
  eax = edx;  // @78_622080
  eax = (eax - ecx);  // @79_622080
  if ((s32)eax >= (s32)(u32)(2)) goto L6221a2;  // @80_622080
  L622170:;
  eax = (u32)(4294967294);  // @82_622080
  return eax;  // @83_622080
  L62217a:;
  eax = edx;  // @85_622080
  eax = (eax - ecx);  // @86_622080
  if ((s32)eax < (s32)(u32)(3)) goto L622170;  // @87_622080
  ecx = (ecx + (u32)(3));  // @88_622080
  goto L6221a5;  // @89_622080
  L622188:;
  eax = edx;  // @91_622080
  eax = (eax - ecx);  // @92_622080
  if ((s32)eax < (s32)(u32)(4)) goto L622170;  // @93_622080
  ecx = (ecx + (u32)(4));  // @94_622080
  goto L6221a5;  // @95_622080
  L622196:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @97_622080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @98_622080
  eax = 0;  // @99_622080
  return eax;  // @100_622080
  L6221a2:;
  ecx = (ecx + (u32)(2));  // @102_622080
  L6221a5:;
  if (ecx == edx) goto L6221f2;  // @104_622080
  L6221b0:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @106_622080
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @107_622080
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6221c1;  // @108_622080
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @109_622080
  goto L6221cb;  // @110_622080
  L6221c1:;
  p7_ = eax;  // @112_622080
  p8_ = ebx;  // @113_622080
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @114_622080
  ecx = edx = 0;  // @115_622080
  L6221cb:;
  if (eax > (u32)(10)) goto L6221e7;  // @117_622080
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6431332), sizeof v); (u32)v; });  // @118_622080
  switch (eax) { case 0: goto L6221f2; case 1: goto L6221de; case 2: goto L622201; case 3: goto L622211; case 4: goto L6221e7; default: __builtin_trap(); }  // @119_622080
  L6221de:;
  eax = edx;  // @121_622080
  eax = (eax - ecx);  // @122_622080
  if ((s32)eax < (s32)(u32)(2)) goto L6221f2;  // @123_622080
  L6221e7:;
  eax = (u32)(2);  // @125_622080
  L6221ec:;
  ecx = (ecx + eax);  // @127_622080
  if (ecx != edx) goto L6221b0;  // @128_622080
  L6221f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @130_622080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @131_622080
  eax = (u32)(6);  // @132_622080
  return eax;  // @133_622080
  L622201:;
  eax = edx;  // @135_622080
  eax = (eax - ecx);  // @136_622080
  if ((s32)eax < (s32)(u32)(3)) goto L6221f2;  // @137_622080
  eax = (u32)(3);  // @138_622080
  goto L6221ec;  // @139_622080
  L622211:;
  eax = edx;  // @141_622080
  eax = (eax - ecx);  // @142_622080
  if ((s32)eax < (s32)(u32)(4)) goto L6221f2;  // @143_622080
  eax = (u32)(4);  // @144_622080
  goto L6221ec;  // @145_622080
}
PCREG(622080, lifted_622080);

extern "C" u32 lifted_624980(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_624980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_624980
  p0_ = edi;  // @2_624980
  edi = ecx;  // @3_624980
  if (ecx != edx) goto L624998;  // @4_624980
  eax = (u32)(4294967292);  // @5_624980
  return eax;  // @6_624980
  L624998:;
  eax = edx;  // @8_624980
  eax = (eax - ecx);  // @9_624980
  if (((eax & 0xff) & (u32)(1)) == 0) goto L6249ae;  // @10_624980
  eax = (eax & (u32)(4294967294));  // @11_624980
  if (eax != 0) goto L6249ab;  // @12_624980
  eax = (eax | (u32)(4294967295));  // @13_624980
  return eax;  // @14_624980
  L6249ab:;
  edx = (u32)(eax + ecx);  // @16_624980
  L6249ae:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_624980
  p1_ = ebx;  // @19_624980
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @20_624980
  p2_ = esi;  // @21_624980
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_624980
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6249c4;  // @23_624980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @24_624980
  goto L6249ce;  // @25_624980
  L6249c4:;
  p3_ = eax;  // @27_624980
  p4_ = ebx;  // @28_624980
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @29_624980
  ecx = edx = 0;  // @30_624980
  L6249ce:;
  if (eax > (u32)(10)) goto L624aa2;  // @32_624980
  switch (eax) { case 0: goto L624a96; case 1: goto L624a96; case 2: goto L624aa2; case 3: goto L624aa2; case 4: goto L6249de; case 5: goto L624a67; case 6: goto L624a7a; case 7: goto L624a88; case 8: goto L624a96; case 9: goto L624a25; case 10: goto L624a55; case 11: goto L624af2; case 12: goto L624ade; case 13: goto L624b01; case 14: goto L624b11; case 15: goto L624ae7; default: __builtin_trap(); }  // @33_624980
  L6249de:;
  ecx = (ecx + (u32)(2));  // @35_624980
  eax = ecx;  // @36_624980
  if (ecx == edx) goto L624a2c;  // @37_624980
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L624aa5;  // @38_624980
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(93)) goto L624aa5;  // @39_624980
  ecx = (ecx + (u32)(2));  // @40_624980
  if (ecx == edx) goto L624a2c;  // @41_624980
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L624a1e;  // @42_624980
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(62)) goto L624a1e;  // @43_624980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @44_624980
  ecx = (ecx + (u32)(2));  // @45_624980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_624980
  eax = (u32)(40);  // @47_624980
  return eax;  // @48_624980
  L624a1e:;
  ecx = eax;  // @50_624980
  goto L624aa5;  // @51_624980
  L624a25:;
  ecx = (ecx + (u32)(2));  // @53_624980
  if (ecx != edx) goto L624a34;  // @54_624980
  L624a2c:;
  eax = (eax | (u32)(4294967295));  // @56_624980
  return eax;  // @57_624980
  L624a34:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @59_624980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_624980
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L624a45;  // @61_624980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @62_624980
  goto L624a4f;  // @63_624980
  L624a45:;
  p5_ = eax;  // @65_624980
  p6_ = edx;  // @66_624980
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @67_624980
  ecx = edx = 0;  // @68_624980
  L624a4f:;
  if (eax != (u32)(10)) ecx = edi;  // @70_624980
  L624a55:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @72_624980
  ecx = (ecx + (u32)(2));  // @73_624980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @74_624980
  eax = (u32)(7);  // @75_624980
  return eax;  // @76_624980
  L624a67:;
  eax = edx;  // @78_624980
  eax = (eax - ecx);  // @79_624980
  if ((s32)eax >= (s32)(u32)(2)) goto L624aa2;  // @80_624980
  L624a70:;
  eax = (u32)(4294967294);  // @82_624980
  return eax;  // @83_624980
  L624a7a:;
  eax = edx;  // @85_624980
  eax = (eax - ecx);  // @86_624980
  if ((s32)eax < (s32)(u32)(3)) goto L624a70;  // @87_624980
  ecx = (ecx + (u32)(3));  // @88_624980
  goto L624aa5;  // @89_624980
  L624a88:;
  eax = edx;  // @91_624980
  eax = (eax - ecx);  // @92_624980
  if ((s32)eax < (s32)(u32)(4)) goto L624a70;  // @93_624980
  ecx = (ecx + (u32)(4));  // @94_624980
  goto L624aa5;  // @95_624980
  L624a96:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @97_624980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @98_624980
  eax = 0;  // @99_624980
  return eax;  // @100_624980
  L624aa2:;
  ecx = (ecx + (u32)(2));  // @102_624980
  L624aa5:;
  if (ecx == edx) goto L624af2;  // @104_624980
  L624ab0:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @106_624980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @107_624980
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L624ac1;  // @108_624980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @109_624980
  goto L624acb;  // @110_624980
  L624ac1:;
  p7_ = eax;  // @112_624980
  p8_ = ebx;  // @113_624980
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @114_624980
  ecx = edx = 0;  // @115_624980
  L624acb:;
  if (eax > (u32)(10)) goto L624ae7;  // @117_624980
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6441828), sizeof v); (u32)v; });  // @118_624980
  switch (eax) { case 0: goto L624af2; case 1: goto L624ade; case 2: goto L624b01; case 3: goto L624b11; case 4: goto L624ae7; default: __builtin_trap(); }  // @119_624980
  L624ade:;
  eax = edx;  // @121_624980
  eax = (eax - ecx);  // @122_624980
  if ((s32)eax < (s32)(u32)(2)) goto L624af2;  // @123_624980
  L624ae7:;
  eax = (u32)(2);  // @125_624980
  L624aec:;
  ecx = (ecx + eax);  // @127_624980
  if (ecx != edx) goto L624ab0;  // @128_624980
  L624af2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @130_624980
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @131_624980
  eax = (u32)(6);  // @132_624980
  return eax;  // @133_624980
  L624b01:;
  eax = edx;  // @135_624980
  eax = (eax - ecx);  // @136_624980
  if ((s32)eax < (s32)(u32)(3)) goto L624af2;  // @137_624980
  eax = (u32)(3);  // @138_624980
  goto L624aec;  // @139_624980
  L624b11:;
  eax = edx;  // @141_624980
  eax = (eax - ecx);  // @142_624980
  if ((s32)eax < (s32)(u32)(4)) goto L624af2;  // @143_624980
  eax = (u32)(4);  // @144_624980
  goto L624aec;  // @145_624980
}
PCREG(624980, lifted_624980);

extern "C" u32 THISCALL lifted_4ef660(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4ef660
  esi = ecx;  // @1_4ef660
  p0_ = edi;  // @2_4ef660
  eax = ext_610100_stdcall1((u32)(p0_));  // @3_4ef660
  ecx = edx = 0;  // @4_4ef660
  eax = (u32)(EBP - 8);  // @5_4ef660
  ecx = edi;  // @6_4ef660
  p1_ = eax;  // @7_4ef660
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p1_), (u32)(1));  // @8_4ef660
  ecx = edx = 0;  // @9_4ef660
  eax = (u32)(esi + 28);  // @10_4ef660
  ecx = edi;  // @11_4ef660
  p2_ = eax;  // @12_4ef660
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p2_), (u32)(1));  // @13_4ef660
  ecx = edx = 0;  // @14_4ef660
  eax = (u32)(EBP + 8);  // @15_4ef660
  ecx = edi;  // @16_4ef660
  p3_ = eax;  // @17_4ef660
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p3_), (u32)(1));  // @18_4ef660
  ecx = edx = 0;  // @19_4ef660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_4ef660
  ecx = (u32)(255);  // @21_4ef660
  if (eax > ecx) eax = ecx;  // @22_4ef660
  ecx = edi;  // @23_4ef660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @24_4ef660
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 142), &v, sizeof v); }  // @25_4ef660
  eax = (u32)(EBP - 12);  // @26_4ef660
  p4_ = eax;  // @27_4ef660
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @28_4ef660
  ecx = edx = 0;  // @29_4ef660
  ecx = edi;  // @30_4ef660
  eax = ext_4e1600_thiscall1(ecx);  // @31_4ef660
  ecx = edx = 0;  // @32_4ef660
  if ((eax & 0xff) != (u32)(3)) goto L4ef6e8;  // @33_4ef660
  eax = (u32)(EBP - 4);  // @34_4ef660
  ecx = edi;  // @35_4ef660
  p5_ = eax;  // @36_4ef660
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p5_), (u32)(1));  // @37_4ef660
  ecx = edx = 0;  // @38_4ef660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_4ef660
  ecx = (u32)(16);  // @40_4ef660
  if (eax > ecx) eax = ecx;  // @41_4ef660
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 143), &v, sizeof v); }  // @42_4ef660
  L4ef6e8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @44_4ef660
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @45_4ef660
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (ecx & 0xff))) & 0xff);  // @46_4ef660
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @47_4ef660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @48_4ef660
  if (eax > (u32)(15)) goto L4ef826;  // @49_4ef660
  switch (eax) { case 0: goto L4ef705; case 1: goto L4ef718; case 2: goto L4ef72b; case 3: goto L4ef73e; case 4: goto L4ef751; case 5: goto L4ef764; case 6: goto L4ef777; case 7: goto L4ef78a; case 8: goto L4ef79d; case 9: goto L4ef7b0; case 10: goto L4ef7c3; case 11: goto L4ef7d6; case 12: goto L4ef7e9; case 13: goto L4ef7fc; case 14: goto L4ef80f; case 15: goto L4ef822; default: __builtin_trap(); }  // @50_4ef660
  L4ef705:;
  ecx = edi;  // @52_4ef660
  { u8 v = (u8)((u32)(17)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @53_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @54_4ef660
  ecx = edx = 0;  // @55_4ef660
  return eax;  // @56_4ef660
  L4ef718:;
  ecx = edi;  // @58_4ef660
  { u8 v = (u8)((u32)(18)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @59_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @60_4ef660
  ecx = edx = 0;  // @61_4ef660
  return eax;  // @62_4ef660
  L4ef72b:;
  ecx = edi;  // @64_4ef660
  { u8 v = (u8)((u32)(20)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @65_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @66_4ef660
  ecx = edx = 0;  // @67_4ef660
  return eax;  // @68_4ef660
  L4ef73e:;
  ecx = edi;  // @70_4ef660
  { u8 v = (u8)((u32)(33)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @71_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @72_4ef660
  ecx = edx = 0;  // @73_4ef660
  return eax;  // @74_4ef660
  L4ef751:;
  ecx = edi;  // @76_4ef660
  { u8 v = (u8)((u32)(34)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @77_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @78_4ef660
  ecx = edx = 0;  // @79_4ef660
  return eax;  // @80_4ef660
  L4ef764:;
  ecx = edi;  // @82_4ef660
  { u8 v = (u8)((u32)(36)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @83_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @84_4ef660
  ecx = edx = 0;  // @85_4ef660
  return eax;  // @86_4ef660
  L4ef777:;
  ecx = edi;  // @88_4ef660
  { u8 v = (u8)((u32)(65)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @89_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @90_4ef660
  ecx = edx = 0;  // @91_4ef660
  return eax;  // @92_4ef660
  L4ef78a:;
  ecx = edi;  // @94_4ef660
  { u8 v = (u8)((u32)(66)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @95_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @96_4ef660
  ecx = edx = 0;  // @97_4ef660
  return eax;  // @98_4ef660
  L4ef79d:;
  ecx = edi;  // @100_4ef660
  { u8 v = (u8)((u32)(68)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @101_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @102_4ef660
  ecx = edx = 0;  // @103_4ef660
  return eax;  // @104_4ef660
  L4ef7b0:;
  ecx = edi;  // @106_4ef660
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @107_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @108_4ef660
  ecx = edx = 0;  // @109_4ef660
  return eax;  // @110_4ef660
  L4ef7c3:;
  ecx = edi;  // @112_4ef660
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @113_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @114_4ef660
  ecx = edx = 0;  // @115_4ef660
  return eax;  // @116_4ef660
  L4ef7d6:;
  ecx = edi;  // @118_4ef660
  { u8 v = (u8)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @119_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @120_4ef660
  ecx = edx = 0;  // @121_4ef660
  return eax;  // @122_4ef660
  L4ef7e9:;
  ecx = edi;  // @124_4ef660
  { u8 v = (u8)((u32)(16)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @125_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @126_4ef660
  ecx = edx = 0;  // @127_4ef660
  return eax;  // @128_4ef660
  L4ef7fc:;
  ecx = edi;  // @130_4ef660
  { u8 v = (u8)((u32)(32)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @131_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @132_4ef660
  ecx = edx = 0;  // @133_4ef660
  return eax;  // @134_4ef660
  L4ef80f:;
  ecx = edi;  // @136_4ef660
  { u8 v = (u8)((u32)(64)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @137_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @138_4ef660
  ecx = edx = 0;  // @139_4ef660
  return eax;  // @140_4ef660
  L4ef822:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @142_4ef660
  L4ef826:;
  ecx = edi;  // @144_4ef660
  eax = ext_4e1b30_thiscall1(ecx);  // @145_4ef660
  ecx = edx = 0;  // @146_4ef660
  return eax;  // @147_4ef660
}
PCREG(4ef660, lifted_4ef660);

extern "C" u32 STDCALL lifted_5ac660(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 106), sizeof v); (u32)v; });  // @0_5ac660
  if ((ecx & ecx) == 0) goto L5ac851;  // @1_5ac660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5ac660
  eax = (eax - 1);  // @3_5ac660
  if (eax > (u32)(55)) goto L5ac851;  // @4_5ac660
  switch (eax) { case 0: goto L5ac682; case 1: goto L5ac696; case 2: goto L5ac6aa; case 3: goto L5ac6be; case 4: goto L5ac6d2; case 5: goto L5ac6e9; case 6: goto L5ac700; case 7: goto L5ac714; case 8: goto L5ac728; case 9: goto L5ac73c; case 10: goto L5ac750; case 11: goto L5ac767; case 12: goto L5ac77e; case 13: goto L5ac795; case 14: goto L5ac7a9; case 15: goto L5ac7bd; case 16: goto L5ac7d4; case 17: goto L5ac83e; case 18: goto L5ac682; case 19: goto L5ac696; case 20: goto L5ac6aa; case 21: goto L5ac6be; case 22: goto L5ac6d2; case 23: goto L5ac6e9; case 24: goto L5ac7e8; case 25: goto L5ac7ff; case 26: goto L5ac700; case 27: goto L5ac714; case 28: goto L5ac728; case 29: goto L5ac73c; case 30: goto L5ac750; case 31: goto L5ac767; case 32: goto L5ac77e; case 33: goto L5ac816; case 34: goto L5ac82a; case 35: goto L5ac7bd; case 36: goto L5ac7d4; case 37: goto L5ac83e; case 38: goto L5ac682; case 39: goto L5ac696; case 40: goto L5ac6aa; case 41: goto L5ac6be; case 42: goto L5ac7e8; case 43: goto L5ac7a9; case 44: goto L5ac73c; case 45: goto L5ac750; case 46: goto L5ac77e; case 47: goto L5ac767; case 48: goto L5ac6d2; case 49: goto L5ac6e9; case 50: goto L5ac6d2; case 51: goto L5ac6e9; case 52: goto L5ac728; case 53: goto L5ac7bd; case 54: goto L5ac7d4; case 55: goto L5ac83e; default: __builtin_trap(); }  // @5_5ac660
  L5ac682:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(0), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_5ac660
  ecx = edx = 0;  // @8_5ac660
  return eax;  // @9_5ac660
  L5ac696:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(32), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @11_5ac660
  ecx = edx = 0;  // @12_5ac660
  return eax;  // @13_5ac660
  L5ac6aa:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(64), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @15_5ac660
  ecx = edx = 0;  // @16_5ac660
  return eax;  // @17_5ac660
  L5ac6be:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(96), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @19_5ac660
  ecx = edx = 0;  // @20_5ac660
  return eax;  // @21_5ac660
  L5ac6d2:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(128), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @23_5ac660
  ecx = edx = 0;  // @24_5ac660
  return eax;  // @25_5ac660
  L5ac6e9:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(160), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @27_5ac660
  ecx = edx = 0;  // @28_5ac660
  return eax;  // @29_5ac660
  L5ac700:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(0), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @31_5ac660
  ecx = edx = 0;  // @32_5ac660
  return eax;  // @33_5ac660
  L5ac714:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(32), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @35_5ac660
  ecx = edx = 0;  // @36_5ac660
  return eax;  // @37_5ac660
  L5ac728:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(64), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @39_5ac660
  ecx = edx = 0;  // @40_5ac660
  return eax;  // @41_5ac660
  L5ac73c:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(96), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @43_5ac660
  ecx = edx = 0;  // @44_5ac660
  return eax;  // @45_5ac660
  L5ac750:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(128), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @47_5ac660
  ecx = edx = 0;  // @48_5ac660
  return eax;  // @49_5ac660
  L5ac767:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(160), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @51_5ac660
  ecx = edx = 0;  // @52_5ac660
  return eax;  // @53_5ac660
  L5ac77e:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(192), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @55_5ac660
  ecx = edx = 0;  // @56_5ac660
  return eax;  // @57_5ac660
  L5ac795:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(0), (u32)(64), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @59_5ac660
  ecx = edx = 0;  // @60_5ac660
  return eax;  // @61_5ac660
  L5ac7a9:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(32), (u32)(64), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @63_5ac660
  ecx = edx = 0;  // @64_5ac660
  return eax;  // @65_5ac660
  L5ac7bd:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(224), (u32)(32), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @67_5ac660
  ecx = edx = 0;  // @68_5ac660
  return eax;  // @69_5ac660
  L5ac7d4:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(96), (u32)(64), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @71_5ac660
  ecx = edx = 0;  // @72_5ac660
  return eax;  // @73_5ac660
  L5ac7e8:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(192), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @75_5ac660
  ecx = edx = 0;  // @76_5ac660
  return eax;  // @77_5ac660
  L5ac7ff:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(224), (u32)(0), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @79_5ac660
  ecx = edx = 0;  // @80_5ac660
  return eax;  // @81_5ac660
  L5ac816:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(0), (u32)(64), (u32)(64), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @83_5ac660
  ecx = edx = 0;  // @84_5ac660
  return eax;  // @85_5ac660
  L5ac82a:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(64), (u32)(64), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @87_5ac660
  ecx = edx = 0;  // @88_5ac660
  return eax;  // @89_5ac660
  L5ac83e:;
  eax = ext_5ec390_thiscall6(ecx, (u32)(128), (u32)(64), (u32)(32), (u32)(32), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @91_5ac660
  ecx = edx = 0;  // @92_5ac660
  L5ac851:;
  return eax;  // @94_5ac660
}
PCREG(5ac660, lifted_5ac660);

extern "C" u32 lifted_626850(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_626850
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_626850
  ecx = esi;  // @2_626850
  if (esi != ebx) goto L62686a;  // @3_626850
  eax = (u32)(4294967292);  // @4_626850
  return eax;  // @5_626850
  L62686a:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_626850
  p0_ = edi;  // @8_626850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_626850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @10_626850
  if (eax > (u32)(10)) goto L626966;  // @11_626850
  switch (eax) { case 0: goto L62695a; case 1: goto L62695a; case 2: goto L626966; case 3: goto L626966; case 4: goto L626886; case 5: goto L6268f3; case 6: goto L626912; case 7: goto L626931; case 8: goto L62695a; case 9: goto L6268b9; case 10: goto L6268e1; case 11: goto L6269fd; case 12: goto L62698b; case 13: goto L6269ac; case 14: goto L6269cd; case 15: goto L6269ee; default: __builtin_trap(); }  // @12_626850
  L626886:;
  esi = (esi + 1);  // @14_626850
  eax = esi;  // @15_626850
  if (esi == ebx) goto L6268be;  // @16_626850
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(93)) goto L626967;  // @17_626850
  esi = (esi + 1);  // @18_626850
  if (esi == ebx) goto L6268be;  // @19_626850
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(62)) goto L6268a7;  // @20_626850
  esi = eax;  // @21_626850
  goto L626967;  // @22_626850
  L6268a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @24_626850
  ecx = (u32)(esi + 1);  // @25_626850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @26_626850
  eax = (u32)(40);  // @27_626850
  return eax;  // @28_626850
  L6268b9:;
  esi = (esi + 1);  // @30_626850
  if (esi != ebx) goto L6268c6;  // @31_626850
  L6268be:;
  eax = (eax | (u32)(4294967295));  // @33_626850
  return eax;  // @34_626850
  L6268c6:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_626850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @37_626850
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; }) != (u32)(10)) esi = ecx;  // @38_626850
  esi = (esi + 1);  // @39_626850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @40_626850
  eax = (u32)(7);  // @41_626850
  return eax;  // @42_626850
  L6268e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @44_626850
  ecx = (u32)(esi + 1);  // @45_626850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_626850
  eax = (u32)(7);  // @47_626850
  return eax;  // @48_626850
  L6268f3:;
  eax = ebx;  // @50_626850
  eax = (eax - esi);  // @51_626850
  if ((s32)eax < (s32)(u32)(2)) goto L62693a;  // @52_626850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 356), sizeof v); (u32)v; });  // @53_626850
  p1_ = esi;  // @54_626850
  p2_ = edi;  // @55_626850
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @56_626850
  ecx = edx = 0;  // @57_626850
  if ((eax & eax) != 0) goto L62695a;  // @58_626850
  esi = (esi + (u32)(2));  // @59_626850
  goto L626967;  // @60_626850
  L626912:;
  eax = ebx;  // @62_626850
  eax = (eax - esi);  // @63_626850
  if ((s32)eax < (s32)(u32)(3)) goto L62693a;  // @64_626850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 360), sizeof v); (u32)v; });  // @65_626850
  p3_ = esi;  // @66_626850
  p4_ = edi;  // @67_626850
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @68_626850
  ecx = edx = 0;  // @69_626850
  if ((eax & eax) != 0) goto L62695a;  // @70_626850
  esi = (esi + (u32)(3));  // @71_626850
  goto L626967;  // @72_626850
  L626931:;
  eax = ebx;  // @74_626850
  eax = (eax - esi);  // @75_626850
  if ((s32)eax >= (s32)(u32)(4)) goto L626944;  // @76_626850
  L62693a:;
  eax = (u32)(4294967294);  // @78_626850
  return eax;  // @79_626850
  L626944:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 364), sizeof v); (u32)v; });  // @81_626850
  p5_ = esi;  // @82_626850
  p6_ = edi;  // @83_626850
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @84_626850
  ecx = edx = 0;  // @85_626850
  if ((eax & eax) != 0) goto L62695a;  // @86_626850
  esi = (esi + (u32)(4));  // @87_626850
  goto L626967;  // @88_626850
  L62695a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @90_626850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @91_626850
  eax = 0;  // @92_626850
  return eax;  // @93_626850
  L626966:;
  esi = (esi + 1);  // @95_626850
  L626967:;
  if (esi == ebx) goto L6269fd;  // @97_626850
  L626970:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @99_626850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @100_626850
  if (eax > (u32)(10)) goto L6269ee;  // @101_626850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6449740), sizeof v); (u32)v; });  // @102_626850
  switch (eax) { case 0: goto L6269fd; case 1: goto L62698b; case 2: goto L6269ac; case 3: goto L6269cd; case 4: goto L6269ee; default: __builtin_trap(); }  // @103_626850
  L62698b:;
  eax = ebx;  // @105_626850
  eax = (eax - esi);  // @106_626850
  if ((s32)eax < (s32)(u32)(2)) goto L6269fd;  // @107_626850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 356), sizeof v); (u32)v; });  // @108_626850
  p7_ = esi;  // @109_626850
  p8_ = edi;  // @110_626850
  eax = ((u32( *)(u32, u32))(eax))((u32)(p8_), (u32)(p7_));  // @111_626850
  ecx = edx = 0;  // @112_626850
  if ((eax & eax) != 0) goto L6269fd;  // @113_626850
  eax = (u32)(2);  // @114_626850
  goto L6269f3;  // @115_626850
  L6269ac:;
  eax = ebx;  // @117_626850
  eax = (eax - esi);  // @118_626850
  if ((s32)eax < (s32)(u32)(3)) goto L6269fd;  // @119_626850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 360), sizeof v); (u32)v; });  // @120_626850
  p9_ = esi;  // @121_626850
  p10_ = edi;  // @122_626850
  eax = ((u32( *)(u32, u32))(eax))((u32)(p10_), (u32)(p9_));  // @123_626850
  ecx = edx = 0;  // @124_626850
  if ((eax & eax) != 0) goto L6269fd;  // @125_626850
  eax = (u32)(3);  // @126_626850
  goto L6269f3;  // @127_626850
  L6269cd:;
  eax = ebx;  // @129_626850
  eax = (eax - esi);  // @130_626850
  if ((s32)eax < (s32)(u32)(4)) goto L6269fd;  // @131_626850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 364), sizeof v); (u32)v; });  // @132_626850
  p11_ = esi;  // @133_626850
  p12_ = edi;  // @134_626850
  eax = ((u32( *)(u32, u32))(eax))((u32)(p12_), (u32)(p11_));  // @135_626850
  ecx = edx = 0;  // @136_626850
  if ((eax & eax) != 0) goto L6269fd;  // @137_626850
  eax = (u32)(4);  // @138_626850
  goto L6269f3;  // @139_626850
  L6269ee:;
  eax = (u32)(1);  // @141_626850
  L6269f3:;
  esi = (esi + eax);  // @143_626850
  if (esi != ebx) goto L626970;  // @144_626850
  L6269fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @146_626850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @147_626850
  eax = (u32)(6);  // @148_626850
  return eax;  // @149_626850
}
PCREG(626850, lifted_626850);

extern "C" u32 FASTCALL lifted_62a200(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62a200
  p0_ = edi;  // @1_62a200
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_62a200
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_62a200
  if (esi != edi) goto L62a21c;  // @4_62a200
  eax = (eax | (u32)(4294967295));  // @5_62a200
  return eax;  // @6_62a200
  L62a21c:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @8_62a200
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @9_62a200
  p1_ = ebx;  // @10_62a200
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_62a200
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L62a233;  // @12_62a200
  eax = (ecx & 0xff);  // @13_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @14_62a200
  goto L62a23d;  // @15_62a200
  L62a233:;
  p2_ = ecx;  // @17_62a200
  p3_ = edx;  // @18_62a200
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_62a200
  ecx = edx = 0;  // @20_62a200
  L62a23d:;
  eax = (eax - (u32)(5));  // @22_62a200
  if (eax > (u32)(24)) goto L62a426;  // @23_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6464588), sizeof v); (u32)v; });  // @24_62a200
  switch (eax) { case 0: goto L62a304; case 1: goto L62a31b; case 2: goto L62a413; case 3: goto L62a283; case 4: goto L62a257; case 5: goto L62a426; default: __builtin_trap(); }  // @25_62a200
  L62a257:;
  eax = (edx & 0xff);  // @27_62a200
  ecx = (ecx & 0xff);  // @28_62a200
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @29_62a200
  eax = ecx;  // @30_62a200
  eax = (eax >> (u32)(5));  // @31_62a200
  ecx = (ecx & (u32)(31));  // @32_62a200
  edx = (u32)(eax + edx*8);  // @33_62a200
  eax = (u32)(1);  // @34_62a200
  eax = (eax << (ecx & 0xff));  // @35_62a200
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a426;  // @36_62a200
  L62a283:;
  esi = (esi + (u32)(2));  // @38_62a200
  if (esi == edi) goto L62a2fa;  // @39_62a200
  L62a290:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @41_62a200
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @42_62a200
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L62a2a3;  // @43_62a200
  eax = (ecx & 0xff);  // @44_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @45_62a200
  goto L62a2ad;  // @46_62a200
  L62a2a3:;
  p4_ = ecx;  // @48_62a200
  p5_ = edx;  // @49_62a200
  eax = ext_62c640_cdecl2((u32)(p5_), (u32)(p4_));  // @50_62a200
  ecx = edx = 0;  // @51_62a200
  L62a2ad:;
  eax = (eax - (u32)(5));  // @53_62a200
  if (eax > (u32)(24)) goto L62a426;  // @54_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6464648), sizeof v); (u32)v; });  // @55_62a200
  switch (eax) { case 0: goto L62a304; case 1: goto L62a31b; case 2: goto L62a413; case 3: goto L62a332; case 4: goto L62a3d6; case 5: goto L62a2f3; case 6: goto L62a2c7; case 7: goto L62a426; default: __builtin_trap(); }  // @56_62a200
  L62a2c7:;
  eax = (edx & 0xff);  // @58_62a200
  ecx = (ecx & 0xff);  // @59_62a200
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @60_62a200
  eax = ecx;  // @61_62a200
  eax = (eax >> (u32)(5));  // @62_62a200
  ecx = (ecx & (u32)(31));  // @63_62a200
  edx = (u32)(eax + edx*8);  // @64_62a200
  eax = (u32)(1);  // @65_62a200
  eax = (eax << (ecx & 0xff));  // @66_62a200
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62a426;  // @67_62a200
  L62a2f3:;
  esi = (esi + (u32)(2));  // @69_62a200
  if (esi != edi) goto L62a290;  // @70_62a200
  L62a2fa:;
  eax = (eax | (u32)(4294967295));  // @72_62a200
  return eax;  // @73_62a200
  L62a304:;
  edi = (edi - esi);  // @75_62a200
  if ((s32)edi >= (s32)(u32)(2)) goto L62a426;  // @76_62a200
  eax = (u32)(4294967294);  // @77_62a200
  return eax;  // @78_62a200
  L62a31b:;
  edi = (edi - esi);  // @80_62a200
  if ((s32)edi >= (s32)(u32)(3)) goto L62a426;  // @81_62a200
  eax = (u32)(4294967294);  // @82_62a200
  return eax;  // @83_62a200
  L62a332:;
  eax = (u32)(EBP + 12);  // @85_62a200
  p6_ = eax;  // @86_62a200
  p7_ = esi;  // @87_62a200
  p8_ = ebx;  // @88_62a200
  eax = ext_628f30_cdecl4((u32)(p8_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p7_), (u32)(p6_));  // @89_62a200
  ecx = edx = 0;  // @90_62a200
  if ((eax & eax) == 0) goto L62a426;  // @91_62a200
  esi = (esi + (u32)(2));  // @92_62a200
  if (esi == edi) goto L62a2fa;  // @93_62a200
  ecx = edi;  // @94_62a200
  ecx = (ecx - esi);  // @95_62a200
  L62a356:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @97_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_62a200
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L62a367;  // @99_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @100_62a200
  goto L62a371;  // @101_62a200
  L62a367:;
  p9_ = eax;  // @103_62a200
  p10_ = edx;  // @104_62a200
  eax = ext_62c640_cdecl2((u32)(p10_), (u32)(p9_));  // @105_62a200
  ecx = edx = 0;  // @106_62a200
  L62a371:;
  if (eax > (u32)(15)) goto L62a38d;  // @108_62a200
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6464700), sizeof v); (u32)v; });  // @109_62a200
  switch (eax) { case 0: goto L62a426; case 1: goto L62a384; case 2: goto L62a3a1; case 3: goto L62a3ae; case 4: goto L62a3bb; case 5: goto L62a38d; default: __builtin_trap(); }  // @110_62a200
  L62a384:;
  if ((s32)ecx < (s32)(u32)(2)) goto L62a41a;  // @112_62a200
  L62a38d:;
  esi = (esi + (u32)(2));  // @114_62a200
  ecx = (ecx - (u32)(2));  // @115_62a200
  L62a393:;
  if (esi != edi) goto L62a356;  // @117_62a200
  eax = (eax | (u32)(4294967295));  // @118_62a200
  return eax;  // @119_62a200
  L62a3a1:;
  if ((s32)ecx < (s32)(u32)(3)) goto L62a41a;  // @121_62a200
  esi = (esi + (u32)(3));  // @122_62a200
  ecx = (ecx - (u32)(3));  // @123_62a200
  goto L62a393;  // @124_62a200
  L62a3ae:;
  if ((s32)ecx < (s32)(u32)(4)) goto L62a41a;  // @126_62a200
  esi = (esi + (u32)(4));  // @127_62a200
  ecx = (ecx - (u32)(4));  // @128_62a200
  goto L62a393;  // @129_62a200
  L62a3bb:;
  esi = (esi + (u32)(2));  // @131_62a200
  ecx = (ecx - (u32)(2));  // @132_62a200
  if (esi == edi) goto L62a2fa;  // @133_62a200
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L62a393;  // @134_62a200
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(62)) goto L62a401;  // @135_62a200
  goto L62a393;  // @136_62a200
  L62a3d6:;
  eax = (u32)(EBP + 12);  // @138_62a200
  p11_ = eax;  // @139_62a200
  p12_ = esi;  // @140_62a200
  p13_ = ebx;  // @141_62a200
  eax = ext_628f30_cdecl4((u32)(p13_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p12_), (u32)(p11_));  // @142_62a200
  ecx = edx = 0;  // @143_62a200
  if ((eax & eax) == 0) goto L62a426;  // @144_62a200
  esi = (esi + (u32)(2));  // @145_62a200
  if (esi == edi) goto L62a2fa;  // @146_62a200
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L62a426;  // @147_62a200
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(62)) goto L62a426;  // @148_62a200
  L62a401:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @150_62a200
  esi = (esi + (u32)(2));  // @151_62a200
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @152_62a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @153_62a200
  return eax;  // @154_62a200
  L62a413:;
  edi = (edi - esi);  // @156_62a200
  if ((s32)edi >= (s32)(u32)(4)) goto L62a426;  // @157_62a200
  L62a41a:;
  eax = (u32)(4294967294);  // @159_62a200
  return eax;  // @160_62a200
  L62a426:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @162_62a200
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @163_62a200
  eax = 0;  // @164_62a200
  return eax;  // @165_62a200
}
PCREG(62a200, lifted_62a200);

extern "C" u32 FASTCALL lifted_6281a0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6281a0
  p0_ = edi;  // @1_6281a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_6281a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_6281a0
  if (esi != edi) goto L6281bc;  // @4_6281a0
  eax = (eax | (u32)(4294967295));  // @5_6281a0
  return eax;  // @6_6281a0
  L6281bc:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @8_6281a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @9_6281a0
  p1_ = ebx;  // @10_6281a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_6281a0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L6281d3;  // @12_6281a0
  eax = (ecx & 0xff);  // @13_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @14_6281a0
  goto L6281dd;  // @15_6281a0
  L6281d3:;
  p2_ = ecx;  // @17_6281a0
  p3_ = edx;  // @18_6281a0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_6281a0
  ecx = edx = 0;  // @20_6281a0
  L6281dd:;
  eax = (eax - (u32)(5));  // @22_6281a0
  if (eax > (u32)(24)) goto L6283c6;  // @23_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6456300), sizeof v); (u32)v; });  // @24_6281a0
  switch (eax) { case 0: goto L6282a4; case 1: goto L6282bb; case 2: goto L6283b3; case 3: goto L628223; case 4: goto L6281f7; case 5: goto L6283c6; default: __builtin_trap(); }  // @25_6281a0
  L6281f7:;
  eax = (edx & 0xff);  // @27_6281a0
  ecx = (ecx & 0xff);  // @28_6281a0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @29_6281a0
  eax = ecx;  // @30_6281a0
  eax = (eax >> (u32)(5));  // @31_6281a0
  ecx = (ecx & (u32)(31));  // @32_6281a0
  edx = (u32)(eax + edx*8);  // @33_6281a0
  eax = (u32)(1);  // @34_6281a0
  eax = (eax << (ecx & 0xff));  // @35_6281a0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L6283c6;  // @36_6281a0
  L628223:;
  esi = (esi + (u32)(2));  // @38_6281a0
  if (esi == edi) goto L62829a;  // @39_6281a0
  L628230:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @41_6281a0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @42_6281a0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L628243;  // @43_6281a0
  eax = (ecx & 0xff);  // @44_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @45_6281a0
  goto L62824d;  // @46_6281a0
  L628243:;
  p4_ = ecx;  // @48_6281a0
  p5_ = edx;  // @49_6281a0
  eax = ext_62c640_cdecl2((u32)(p5_), (u32)(p4_));  // @50_6281a0
  ecx = edx = 0;  // @51_6281a0
  L62824d:;
  eax = (eax - (u32)(5));  // @53_6281a0
  if (eax > (u32)(24)) goto L6283c6;  // @54_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6456360), sizeof v); (u32)v; });  // @55_6281a0
  switch (eax) { case 0: goto L6282a4; case 1: goto L6282bb; case 2: goto L6283b3; case 3: goto L6282d2; case 4: goto L628376; case 5: goto L628293; case 6: goto L628267; case 7: goto L6283c6; default: __builtin_trap(); }  // @56_6281a0
  L628267:;
  eax = (edx & 0xff);  // @58_6281a0
  ecx = (ecx & 0xff);  // @59_6281a0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @60_6281a0
  eax = ecx;  // @61_6281a0
  eax = (eax >> (u32)(5));  // @62_6281a0
  ecx = (ecx & (u32)(31));  // @63_6281a0
  edx = (u32)(eax + edx*8);  // @64_6281a0
  eax = (u32)(1);  // @65_6281a0
  eax = (eax << (ecx & 0xff));  // @66_6281a0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L6283c6;  // @67_6281a0
  L628293:;
  esi = (esi + (u32)(2));  // @69_6281a0
  if (esi != edi) goto L628230;  // @70_6281a0
  L62829a:;
  eax = (eax | (u32)(4294967295));  // @72_6281a0
  return eax;  // @73_6281a0
  L6282a4:;
  edi = (edi - esi);  // @75_6281a0
  if ((s32)edi >= (s32)(u32)(2)) goto L6283c6;  // @76_6281a0
  eax = (u32)(4294967294);  // @77_6281a0
  return eax;  // @78_6281a0
  L6282bb:;
  edi = (edi - esi);  // @80_6281a0
  if ((s32)edi >= (s32)(u32)(3)) goto L6283c6;  // @81_6281a0
  eax = (u32)(4294967294);  // @82_6281a0
  return eax;  // @83_6281a0
  L6282d2:;
  eax = (u32)(EBP + 12);  // @85_6281a0
  p6_ = eax;  // @86_6281a0
  p7_ = esi;  // @87_6281a0
  p8_ = ebx;  // @88_6281a0
  eax = ext_626ed0_cdecl4((u32)(p8_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p7_), (u32)(p6_));  // @89_6281a0
  ecx = edx = 0;  // @90_6281a0
  if ((eax & eax) == 0) goto L6283c6;  // @91_6281a0
  esi = (esi + (u32)(2));  // @92_6281a0
  if (esi == edi) goto L62829a;  // @93_6281a0
  ecx = edi;  // @94_6281a0
  ecx = (ecx - esi);  // @95_6281a0
  L6282f6:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @97_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; });  // @98_6281a0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L628307;  // @99_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @100_6281a0
  goto L628311;  // @101_6281a0
  L628307:;
  p9_ = eax;  // @103_6281a0
  p10_ = edx;  // @104_6281a0
  eax = ext_62c640_cdecl2((u32)(p10_), (u32)(p9_));  // @105_6281a0
  ecx = edx = 0;  // @106_6281a0
  L628311:;
  if (eax > (u32)(15)) goto L62832d;  // @108_6281a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6456412), sizeof v); (u32)v; });  // @109_6281a0
  switch (eax) { case 0: goto L6283c6; case 1: goto L628324; case 2: goto L628341; case 3: goto L62834e; case 4: goto L62835b; case 5: goto L62832d; default: __builtin_trap(); }  // @110_6281a0
  L628324:;
  if ((s32)ecx < (s32)(u32)(2)) goto L6283ba;  // @112_6281a0
  L62832d:;
  esi = (esi + (u32)(2));  // @114_6281a0
  ecx = (ecx - (u32)(2));  // @115_6281a0
  L628333:;
  if (esi != edi) goto L6282f6;  // @117_6281a0
  eax = (eax | (u32)(4294967295));  // @118_6281a0
  return eax;  // @119_6281a0
  L628341:;
  if ((s32)ecx < (s32)(u32)(3)) goto L6283ba;  // @121_6281a0
  esi = (esi + (u32)(3));  // @122_6281a0
  ecx = (ecx - (u32)(3));  // @123_6281a0
  goto L628333;  // @124_6281a0
  L62834e:;
  if ((s32)ecx < (s32)(u32)(4)) goto L6283ba;  // @126_6281a0
  esi = (esi + (u32)(4));  // @127_6281a0
  ecx = (ecx - (u32)(4));  // @128_6281a0
  goto L628333;  // @129_6281a0
  L62835b:;
  esi = (esi + (u32)(2));  // @131_6281a0
  ecx = (ecx - (u32)(2));  // @132_6281a0
  if (esi == edi) goto L62829a;  // @133_6281a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L628333;  // @134_6281a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; }) == (u32)(62)) goto L6283a1;  // @135_6281a0
  goto L628333;  // @136_6281a0
  L628376:;
  eax = (u32)(EBP + 12);  // @138_6281a0
  p11_ = eax;  // @139_6281a0
  p12_ = esi;  // @140_6281a0
  p13_ = ebx;  // @141_6281a0
  eax = ext_626ed0_cdecl4((u32)(p13_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p12_), (u32)(p11_));  // @142_6281a0
  ecx = edx = 0;  // @143_6281a0
  if ((eax & eax) == 0) goto L6283c6;  // @144_6281a0
  esi = (esi + (u32)(2));  // @145_6281a0
  if (esi == edi) goto L62829a;  // @146_6281a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L6283c6;  // @147_6281a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; }) != (u32)(62)) goto L6283c6;  // @148_6281a0
  L6283a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @150_6281a0
  esi = (esi + (u32)(2));  // @151_6281a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @152_6281a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @153_6281a0
  return eax;  // @154_6281a0
  L6283b3:;
  edi = (edi - esi);  // @156_6281a0
  if ((s32)edi >= (s32)(u32)(4)) goto L6283c6;  // @157_6281a0
  L6283ba:;
  eax = (u32)(4294967294);  // @159_6281a0
  return eax;  // @160_6281a0
  L6283c6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @162_6281a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @163_6281a0
  eax = 0;  // @164_6281a0
  return eax;  // @165_6281a0
}
PCREG(6281a0, lifted_6281a0);

extern "C" u32 lifted_622650(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_622650
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_622650
  p0_ = edi;  // @2_622650
  edi = ecx;  // @3_622650
  if (ecx != edx) goto L622668;  // @4_622650
  eax = (u32)(4294967292);  // @5_622650
  return eax;  // @6_622650
  L622668:;
  eax = edx;  // @8_622650
  eax = (eax - ecx);  // @9_622650
  if (((eax & 0xff) & (u32)(1)) == 0) goto L62267e;  // @10_622650
  eax = (eax & (u32)(4294967294));  // @11_622650
  if (eax != 0) goto L62267b;  // @12_622650
  eax = (eax | (u32)(4294967295));  // @13_622650
  return eax;  // @14_622650
  L62267b:;
  edx = (u32)(eax + ecx);  // @16_622650
  L62267e:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_622650
  p1_ = ebx;  // @19_622650
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @20_622650
  p2_ = esi;  // @21_622650
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_622650
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L622694;  // @23_622650
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @24_622650
  goto L62269e;  // @25_622650
  L622694:;
  p3_ = eax;  // @27_622650
  p4_ = ebx;  // @28_622650
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @29_622650
  ecx = edx = 0;  // @30_622650
  L62269e:;
  if (eax > (u32)(10)) goto L622785;  // @32_622650
  switch (eax) { case 0: goto L62283b; case 1: goto L62283b; case 2: goto L6226ae; case 3: goto L6226c4; case 4: goto L62271e; case 5: goto L622756; case 6: goto L622769; case 7: goto L622777; case 8: goto L62283b; case 9: goto L6226da; case 10: goto L62270c; case 11: goto L6227c7; case 12: goto L6227f6; case 13: goto L6227be; case 14: goto L6227d6; case 15: goto L6227e6; default: __builtin_trap(); }  // @33_622650
  L6226ae:;
  eax = (u32)(ecx + 2);  // @35_622650
  p5_ = edx;  // @36_622650
  p6_ = eax;  // @37_622650
  p7_ = esi;  // @38_622650
  eax = ext_629c10_cdecl4((u32)(p7_), (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @39_622650
  ecx = edx = 0;  // @40_622650
  return eax;  // @41_622650
  L6226c4:;
  eax = (u32)(ecx + 2);  // @43_622650
  p8_ = edx;  // @44_622650
  p9_ = eax;  // @45_622650
  p10_ = esi;  // @46_622650
  eax = ext_62a690_cdecl4((u32)(p10_), (u32)(p9_), (u32)(p8_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @47_622650
  ecx = edx = 0;  // @48_622650
  return eax;  // @49_622650
  L6226da:;
  ecx = (ecx + (u32)(2));  // @51_622650
  if (ecx != edx) goto L6226eb;  // @52_622650
  eax = (u32)(4294967293);  // @53_622650
  return eax;  // @54_622650
  L6226eb:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @56_622650
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_622650
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L6226fc;  // @58_622650
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @59_622650
  goto L622706;  // @60_622650
  L6226fc:;
  p11_ = eax;  // @62_622650
  p12_ = edx;  // @63_622650
  eax = ext_62c640_cdecl2((u32)(p12_), (u32)(p11_));  // @64_622650
  ecx = edx = 0;  // @65_622650
  L622706:;
  if (eax != (u32)(10)) ecx = edi;  // @67_622650
  L62270c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @69_622650
  ecx = (ecx + (u32)(2));  // @70_622650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @71_622650
  eax = (u32)(7);  // @72_622650
  return eax;  // @73_622650
  L62271e:;
  ecx = (ecx + (u32)(2));  // @75_622650
  eax = ecx;  // @76_622650
  if (ecx == edx) goto L622739;  // @77_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L622788;  // @78_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(93)) goto L622788;  // @79_622650
  ecx = (ecx + (u32)(2));  // @80_622650
  if (ecx != edx) goto L622743;  // @81_622650
  L622739:;
  eax = (u32)(4294967291);  // @83_622650
  return eax;  // @84_622650
  L622743:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L622752;  // @86_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) == (u32)(62)) goto L62283b;  // @87_622650
  L622752:;
  ecx = eax;  // @89_622650
  goto L622788;  // @90_622650
  L622756:;
  eax = edx;  // @92_622650
  eax = (eax - ecx);  // @93_622650
  if ((s32)eax >= (s32)(u32)(2)) goto L622785;  // @94_622650
  L62275f:;
  eax = (u32)(4294967294);  // @96_622650
  return eax;  // @97_622650
  L622769:;
  eax = edx;  // @99_622650
  eax = (eax - ecx);  // @100_622650
  if ((s32)eax < (s32)(u32)(3)) goto L62275f;  // @101_622650
  ecx = (ecx + (u32)(3));  // @102_622650
  goto L622788;  // @103_622650
  L622777:;
  eax = edx;  // @105_622650
  eax = (eax - ecx);  // @106_622650
  if ((s32)eax < (s32)(u32)(4)) goto L62275f;  // @107_622650
  ecx = (ecx + (u32)(4));  // @108_622650
  goto L622788;  // @109_622650
  L622785:;
  ecx = (ecx + (u32)(2));  // @111_622650
  L622788:;
  if (ecx == edx) goto L6227c7;  // @113_622650
  L622790:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @115_622650
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_622650
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L6227a1;  // @117_622650
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @118_622650
  goto L6227ab;  // @119_622650
  L6227a1:;
  p13_ = eax;  // @121_622650
  p14_ = ebx;  // @122_622650
  eax = ext_62c640_cdecl2((u32)(p14_), (u32)(p13_));  // @123_622650
  ecx = edx = 0;  // @124_622650
  L6227ab:;
  if (eax > (u32)(10)) goto L62281a;  // @126_622650
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6432904), sizeof v); (u32)v; });  // @127_622650
  switch (eax) { case 0: goto L6227c7; case 1: goto L6227f6; case 2: goto L6227be; case 3: goto L6227d6; case 4: goto L6227e6; default: __builtin_trap(); }  // @128_622650
  L6227be:;
  eax = edx;  // @130_622650
  eax = (eax - ecx);  // @131_622650
  if ((s32)eax >= (s32)(u32)(2)) goto L62281a;  // @132_622650
  L6227c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @134_622650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @135_622650
  eax = (u32)(6);  // @136_622650
  return eax;  // @137_622650
  L6227d6:;
  eax = edx;  // @139_622650
  eax = (eax - ecx);  // @140_622650
  if ((s32)eax < (s32)(u32)(3)) goto L6227c7;  // @141_622650
  eax = (u32)(3);  // @142_622650
  goto L62281f;  // @143_622650
  L6227e6:;
  eax = edx;  // @145_622650
  eax = (eax - ecx);  // @146_622650
  if ((s32)eax < (s32)(u32)(4)) goto L6227c7;  // @147_622650
  eax = (u32)(4);  // @148_622650
  goto L62281f;  // @149_622650
  L6227f6:;
  eax = (u32)(ecx + 2);  // @151_622650
  if (eax == edx) goto L6227c7;  // @152_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 3), sizeof v); (u32)v; }) != (u32)(0)) goto L62281a;  // @153_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(93)) goto L62281a;  // @154_622650
  eax = (u32)(ecx + 4);  // @155_622650
  if (eax == edx) goto L6227c7;  // @156_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; }) != (u32)(0)) goto L62281a;  // @157_622650
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(62)) goto L622838;  // @158_622650
  L62281a:;
  eax = (u32)(2);  // @160_622650
  L62281f:;
  ecx = (ecx + eax);  // @162_622650
  if (ecx != edx) goto L622790;  // @163_622650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @164_622650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @165_622650
  eax = (u32)(6);  // @166_622650
  return eax;  // @167_622650
  L622838:;
  ecx = (ecx + (u32)(4));  // @169_622650
  L62283b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @171_622650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @172_622650
  eax = 0;  // @173_622650
  return eax;  // @174_622650
}
PCREG(622650, lifted_622650);

extern "C" u32 lifted_624100(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_624100
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_624100
  p0_ = edi;  // @2_624100
  edi = ecx;  // @3_624100
  if (ecx != edx) goto L624118;  // @4_624100
  eax = (u32)(4294967292);  // @5_624100
  return eax;  // @6_624100
  L624118:;
  eax = edx;  // @8_624100
  eax = (eax - ecx);  // @9_624100
  if (((eax & 0xff) & (u32)(1)) == 0) goto L62412e;  // @10_624100
  eax = (eax & (u32)(4294967294));  // @11_624100
  if (eax != 0) goto L62412b;  // @12_624100
  eax = (eax | (u32)(4294967295));  // @13_624100
  return eax;  // @14_624100
  L62412b:;
  edx = (u32)(eax + ecx);  // @16_624100
  L62412e:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @18_624100
  p1_ = ebx;  // @19_624100
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @20_624100
  p2_ = esi;  // @21_624100
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_624100
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L624144;  // @23_624100
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @24_624100
  goto L62414e;  // @25_624100
  L624144:;
  p3_ = eax;  // @27_624100
  p4_ = ebx;  // @28_624100
  eax = ext_62c640_cdecl5((u32)(p4_), (u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @29_624100
  ecx = edx = 0;  // @30_624100
  L62414e:;
  if (eax > (u32)(10)) goto L624235;  // @32_624100
  switch (eax) { case 0: goto L6242eb; case 1: goto L6242eb; case 2: goto L62415e; case 3: goto L624174; case 4: goto L6241ce; case 5: goto L624206; case 6: goto L624219; case 7: goto L624227; case 8: goto L6242eb; case 9: goto L62418a; case 10: goto L6241bc; case 11: goto L624277; case 12: goto L6242a6; case 13: goto L62426e; case 14: goto L624286; case 15: goto L624296; default: __builtin_trap(); }  // @33_624100
  L62415e:;
  eax = (u32)(ecx + 2);  // @35_624100
  p5_ = edx;  // @36_624100
  p6_ = eax;  // @37_624100
  p7_ = esi;  // @38_624100
  eax = ext_627bb0_cdecl4((u32)(p7_), (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @39_624100
  ecx = edx = 0;  // @40_624100
  return eax;  // @41_624100
  L624174:;
  eax = (u32)(ecx + 2);  // @43_624100
  p8_ = edx;  // @44_624100
  p9_ = eax;  // @45_624100
  p10_ = esi;  // @46_624100
  eax = ext_628630_cdecl4((u32)(p10_), (u32)(p9_), (u32)(p8_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @47_624100
  ecx = edx = 0;  // @48_624100
  return eax;  // @49_624100
  L62418a:;
  ecx = (ecx + (u32)(2));  // @51_624100
  if (ecx != edx) goto L62419b;  // @52_624100
  eax = (u32)(4294967293);  // @53_624100
  return eax;  // @54_624100
  L62419b:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @56_624100
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @57_624100
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L6241ac;  // @58_624100
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @59_624100
  goto L6241b6;  // @60_624100
  L6241ac:;
  p11_ = eax;  // @62_624100
  p12_ = edx;  // @63_624100
  eax = ext_62c640_cdecl2((u32)(p12_), (u32)(p11_));  // @64_624100
  ecx = edx = 0;  // @65_624100
  L6241b6:;
  if (eax != (u32)(10)) ecx = edi;  // @67_624100
  L6241bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @69_624100
  ecx = (ecx + (u32)(2));  // @70_624100
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @71_624100
  eax = (u32)(7);  // @72_624100
  return eax;  // @73_624100
  L6241ce:;
  ecx = (ecx + (u32)(2));  // @75_624100
  eax = ecx;  // @76_624100
  if (ecx == edx) goto L6241e9;  // @77_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L624238;  // @78_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) != (u32)(93)) goto L624238;  // @79_624100
  ecx = (ecx + (u32)(2));  // @80_624100
  if (ecx != edx) goto L6241f3;  // @81_624100
  L6241e9:;
  eax = (u32)(4294967291);  // @83_624100
  return eax;  // @84_624100
  L6241f3:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (u32)(0)) goto L624202;  // @86_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; }) == (u32)(62)) goto L6242eb;  // @87_624100
  L624202:;
  ecx = eax;  // @89_624100
  goto L624238;  // @90_624100
  L624206:;
  eax = edx;  // @92_624100
  eax = (eax - ecx);  // @93_624100
  if ((s32)eax >= (s32)(u32)(2)) goto L624235;  // @94_624100
  L62420f:;
  eax = (u32)(4294967294);  // @96_624100
  return eax;  // @97_624100
  L624219:;
  eax = edx;  // @99_624100
  eax = (eax - ecx);  // @100_624100
  if ((s32)eax < (s32)(u32)(3)) goto L62420f;  // @101_624100
  ecx = (ecx + (u32)(3));  // @102_624100
  goto L624238;  // @103_624100
  L624227:;
  eax = edx;  // @105_624100
  eax = (eax - ecx);  // @106_624100
  if ((s32)eax < (s32)(u32)(4)) goto L62420f;  // @107_624100
  ecx = (ecx + (u32)(4));  // @108_624100
  goto L624238;  // @109_624100
  L624235:;
  ecx = (ecx + (u32)(2));  // @111_624100
  L624238:;
  if (ecx == edx) goto L624277;  // @113_624100
  L624240:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @115_624100
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @116_624100
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L624251;  // @117_624100
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @118_624100
  goto L62425b;  // @119_624100
  L624251:;
  p13_ = eax;  // @121_624100
  p14_ = ebx;  // @122_624100
  eax = ext_62c640_cdecl2((u32)(p14_), (u32)(p13_));  // @123_624100
  ecx = edx = 0;  // @124_624100
  L62425b:;
  if (eax > (u32)(10)) goto L6242ca;  // @126_624100
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6439736), sizeof v); (u32)v; });  // @127_624100
  switch (eax) { case 0: goto L624277; case 1: goto L6242a6; case 2: goto L62426e; case 3: goto L624286; case 4: goto L624296; default: __builtin_trap(); }  // @128_624100
  L62426e:;
  eax = edx;  // @130_624100
  eax = (eax - ecx);  // @131_624100
  if ((s32)eax >= (s32)(u32)(2)) goto L6242ca;  // @132_624100
  L624277:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @134_624100
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @135_624100
  eax = (u32)(6);  // @136_624100
  return eax;  // @137_624100
  L624286:;
  eax = edx;  // @139_624100
  eax = (eax - ecx);  // @140_624100
  if ((s32)eax < (s32)(u32)(3)) goto L624277;  // @141_624100
  eax = (u32)(3);  // @142_624100
  goto L6242cf;  // @143_624100
  L624296:;
  eax = edx;  // @145_624100
  eax = (eax - ecx);  // @146_624100
  if ((s32)eax < (s32)(u32)(4)) goto L624277;  // @147_624100
  eax = (u32)(4);  // @148_624100
  goto L6242cf;  // @149_624100
  L6242a6:;
  eax = (u32)(ecx + 2);  // @151_624100
  if (eax == edx) goto L624277;  // @152_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L6242ca;  // @153_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 3), sizeof v); (u32)v; }) != (u32)(93)) goto L6242ca;  // @154_624100
  eax = (u32)(ecx + 4);  // @155_624100
  if (eax == edx) goto L624277;  // @156_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L6242ca;  // @157_624100
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; }) == (u32)(62)) goto L6242e8;  // @158_624100
  L6242ca:;
  eax = (u32)(2);  // @160_624100
  L6242cf:;
  ecx = (ecx + eax);  // @162_624100
  if (ecx != edx) goto L624240;  // @163_624100
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @164_624100
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @165_624100
  eax = (u32)(6);  // @166_624100
  return eax;  // @167_624100
  L6242e8:;
  ecx = (ecx + (u32)(4));  // @169_624100
  L6242eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @171_624100
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @172_624100
  eax = 0;  // @173_624100
  return eax;  // @174_624100
}
PCREG(624100, lifted_624100);

extern "C" u32 lifted_623be0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_623be0
  ecx = esi;  // @1_623be0
  p0_ = edi;  // @2_623be0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_623be0
  if (esi != edi) goto L623bfa;  // @4_623be0
  eax = (u32)(4294967292);  // @5_623be0
  return eax;  // @6_623be0
  L623bfa:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_623be0
  p1_ = ebx;  // @9_623be0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_623be0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @11_623be0
  if (eax > (u32)(10)) goto L623d19;  // @12_623be0
  switch (eax) { case 0: goto L623d0d; case 1: goto L623d0d; case 2: goto L623c16; case 3: goto L623c2c; case 4: goto L623c7e; case 5: goto L623ca6; case 6: goto L623cc5; case 7: goto L623ce4; case 8: goto L623d0d; case 9: goto L623c42; case 10: goto L623c6c; case 11: goto L623dcf; case 12: goto L623da8; case 13: goto L623d41; case 14: goto L623d66; case 15: goto L623d87; default: __builtin_trap(); }  // @13_623be0
  L623c16:;
  eax = (u32)(esi + 1);  // @15_623be0
  p2_ = edi;  // @16_623be0
  p3_ = eax;  // @17_623be0
  p4_ = ebx;  // @18_623be0
  eax = ext_62b450_cdecl6((u32)(p4_), (u32)(p3_), (u32)(p2_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @19_623be0
  ecx = edx = 0;  // @20_623be0
  return eax;  // @21_623be0
  L623c2c:;
  eax = (u32)(esi + 1);  // @23_623be0
  p5_ = edi;  // @24_623be0
  p6_ = eax;  // @25_623be0
  p7_ = ebx;  // @26_623be0
  eax = ext_62c060_cdecl4((u32)(p7_), (u32)(p6_), (u32)(p5_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @27_623be0
  ecx = edx = 0;  // @28_623be0
  return eax;  // @29_623be0
  L623c42:;
  esi = (esi + 1);  // @31_623be0
  if (esi != edi) goto L623c51;  // @32_623be0
  eax = (u32)(4294967293);  // @33_623be0
  return eax;  // @34_623be0
  L623c51:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_623be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @37_623be0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; }) != (u32)(10)) esi = ecx;  // @38_623be0
  esi = (esi + 1);  // @39_623be0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @40_623be0
  eax = (u32)(7);  // @41_623be0
  return eax;  // @42_623be0
  L623c6c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @44_623be0
  ecx = (u32)(esi + 1);  // @45_623be0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_623be0
  eax = (u32)(7);  // @47_623be0
  return eax;  // @48_623be0
  L623c7e:;
  esi = (esi + 1);  // @50_623be0
  eax = esi;  // @51_623be0
  if (esi == edi) goto L623c93;  // @52_623be0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(93)) goto L623d1a;  // @53_623be0
  esi = (esi + 1);  // @54_623be0
  if (esi != edi) goto L623c9d;  // @55_623be0
  L623c93:;
  eax = (u32)(4294967291);  // @57_623be0
  return eax;  // @58_623be0
  L623c9d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(62)) goto L623d0d;  // @60_623be0
  esi = eax;  // @61_623be0
  goto L623d1a;  // @62_623be0
  L623ca6:;
  eax = edi;  // @64_623be0
  eax = (eax - esi);  // @65_623be0
  if ((s32)eax < (s32)(u32)(2)) goto L623ced;  // @66_623be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 356), sizeof v); (u32)v; });  // @67_623be0
  p8_ = esi;  // @68_623be0
  p9_ = ebx;  // @69_623be0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p9_), (u32)(p8_));  // @70_623be0
  ecx = edx = 0;  // @71_623be0
  if ((eax & eax) != 0) goto L623d0d;  // @72_623be0
  esi = (esi + (u32)(2));  // @73_623be0
  goto L623d1a;  // @74_623be0
  L623cc5:;
  eax = edi;  // @76_623be0
  eax = (eax - esi);  // @77_623be0
  if ((s32)eax < (s32)(u32)(3)) goto L623ced;  // @78_623be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 360), sizeof v); (u32)v; });  // @79_623be0
  p10_ = esi;  // @80_623be0
  p11_ = ebx;  // @81_623be0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p11_), (u32)(p10_));  // @82_623be0
  ecx = edx = 0;  // @83_623be0
  if ((eax & eax) != 0) goto L623d0d;  // @84_623be0
  esi = (esi + (u32)(3));  // @85_623be0
  goto L623d1a;  // @86_623be0
  L623ce4:;
  eax = edi;  // @88_623be0
  eax = (eax - esi);  // @89_623be0
  if ((s32)eax >= (s32)(u32)(4)) goto L623cf7;  // @90_623be0
  L623ced:;
  eax = (u32)(4294967294);  // @92_623be0
  return eax;  // @93_623be0
  L623cf7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 364), sizeof v); (u32)v; });  // @95_623be0
  p12_ = esi;  // @96_623be0
  p13_ = ebx;  // @97_623be0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p13_), (u32)(p12_));  // @98_623be0
  ecx = edx = 0;  // @99_623be0
  if ((eax & eax) != 0) goto L623d0d;  // @100_623be0
  esi = (esi + (u32)(4));  // @101_623be0
  goto L623d1a;  // @102_623be0
  L623d0d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @104_623be0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @105_623be0
  eax = 0;  // @106_623be0
  return eax;  // @107_623be0
  L623d19:;
  esi = (esi + 1);  // @109_623be0
  L623d1a:;
  if (esi == edi) goto L623dcf;  // @111_623be0
  L623d22:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @113_623be0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @114_623be0
  if (eax > (u32)(10)) goto L623dc0;  // @115_623be0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6438448), sizeof v); (u32)v; });  // @116_623be0
  switch (eax) { case 0: goto L623dcf; case 1: goto L623da8; case 2: goto L623d41; case 3: goto L623d66; case 4: goto L623d87; default: __builtin_trap(); }  // @117_623be0
  L623d41:;
  eax = edi;  // @119_623be0
  eax = (eax - esi);  // @120_623be0
  if ((s32)eax < (s32)(u32)(2)) goto L623dcf;  // @121_623be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 356), sizeof v); (u32)v; });  // @122_623be0
  p14_ = esi;  // @123_623be0
  p15_ = ebx;  // @124_623be0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p15_), (u32)(p14_));  // @125_623be0
  ecx = edx = 0;  // @126_623be0
  if ((eax & eax) != 0) goto L623dcf;  // @127_623be0
  eax = (u32)(2);  // @128_623be0
  goto L623dc5;  // @129_623be0
  L623d66:;
  eax = edi;  // @131_623be0
  eax = (eax - esi);  // @132_623be0
  if ((s32)eax < (s32)(u32)(3)) goto L623dcf;  // @133_623be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 360), sizeof v); (u32)v; });  // @134_623be0
  p16_ = esi;  // @135_623be0
  p17_ = ebx;  // @136_623be0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p17_), (u32)(p16_));  // @137_623be0
  ecx = edx = 0;  // @138_623be0
  if ((eax & eax) != 0) goto L623dcf;  // @139_623be0
  eax = (u32)(3);  // @140_623be0
  goto L623dc5;  // @141_623be0
  L623d87:;
  eax = edi;  // @143_623be0
  eax = (eax - esi);  // @144_623be0
  if ((s32)eax < (s32)(u32)(4)) goto L623dcf;  // @145_623be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 364), sizeof v); (u32)v; });  // @146_623be0
  p18_ = esi;  // @147_623be0
  p19_ = ebx;  // @148_623be0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p19_), (u32)(p18_));  // @149_623be0
  ecx = edx = 0;  // @150_623be0
  if ((eax & eax) != 0) goto L623dcf;  // @151_623be0
  eax = (u32)(4);  // @152_623be0
  goto L623dc5;  // @153_623be0
  L623da8:;
  eax = (u32)(esi + 1);  // @155_623be0
  if (eax == edi) goto L623dcf;  // @156_623be0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(93)) goto L623dc0;  // @157_623be0
  eax = (u32)(esi + 2);  // @158_623be0
  if (eax == edi) goto L623dcf;  // @159_623be0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(62)) goto L623dde;  // @160_623be0
  L623dc0:;
  eax = (u32)(1);  // @162_623be0
  L623dc5:;
  esi = (esi + eax);  // @164_623be0
  if (esi != edi) goto L623d22;  // @165_623be0
  L623dcf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @167_623be0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @168_623be0
  eax = (u32)(6);  // @169_623be0
  return eax;  // @170_623be0
  L623dde:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @172_623be0
  ecx = (u32)(esi + 2);  // @173_623be0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @174_623be0
  eax = 0;  // @175_623be0
  return eax;  // @176_623be0
}
PCREG(623be0, lifted_623be0);

extern "C" u32 lifted_62bb10(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62bb10
  p0_ = edi;  // @1_62bb10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_62bb10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_62bb10
  if (esi != edi) goto L62bb2c;  // @4_62bb10
  eax = (eax | (u32)(4294967295));  // @5_62bb10
  return eax;  // @6_62bb10
  L62bb2c:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_62bb10
  p1_ = ebx;  // @9_62bb10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_62bb10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @11_62bb10
  eax = (eax + (u32)(-5));  // @12_62bb10
  if (eax > (u32)(24)) goto L62bdb1;  // @13_62bb10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6471128), sizeof v); (u32)v; });  // @14_62bb10
  switch (eax) { case 0: goto L62bb59; case 1: goto L62bb82; case 2: goto L62bbab; case 3: goto L62bb52; case 4: goto L62bdb1; case 5: goto L62bdb1; default: __builtin_trap(); }  // @15_62bb10
  L62bb52:;
  eax = (u32)(1);  // @17_62bb10
  goto L62bbd2;  // @18_62bb10
  L62bb59:;
  eax = edi;  // @20_62bb10
  eax = (eax - esi);  // @21_62bb10
  if ((s32)eax < (s32)(u32)(2)) goto L62bd70;  // @22_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 344), sizeof v); (u32)v; });  // @23_62bb10
  p2_ = esi;  // @24_62bb10
  p3_ = ebx;  // @25_62bb10
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(eax))((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @26_62bb10
  ecx = edx = 0;  // @27_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @28_62bb10
  eax = (u32)(2);  // @29_62bb10
  goto L62bbd2;  // @30_62bb10
  L62bb82:;
  eax = edi;  // @32_62bb10
  eax = (eax - esi);  // @33_62bb10
  if ((s32)eax < (s32)(u32)(3)) goto L62bd70;  // @34_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 348), sizeof v); (u32)v; });  // @35_62bb10
  p4_ = esi;  // @36_62bb10
  p5_ = ebx;  // @37_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p5_), (u32)(p4_));  // @38_62bb10
  ecx = edx = 0;  // @39_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @40_62bb10
  eax = (u32)(3);  // @41_62bb10
  goto L62bbd2;  // @42_62bb10
  L62bbab:;
  eax = edi;  // @44_62bb10
  eax = (eax - esi);  // @45_62bb10
  if ((s32)eax < (s32)(u32)(4)) goto L62bd70;  // @46_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 352), sizeof v); (u32)v; });  // @47_62bb10
  p6_ = esi;  // @48_62bb10
  p7_ = ebx;  // @49_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p7_), (u32)(p6_));  // @50_62bb10
  ecx = edx = 0;  // @51_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @52_62bb10
  eax = (u32)(4);  // @53_62bb10
  L62bbd2:;
  esi = (esi + eax);  // @55_62bb10
  if (esi == edi) goto L62bc8c;  // @56_62bb10
  L62bbe0:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_62bb10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @59_62bb10
  eax = (eax + (u32)(-5));  // @60_62bb10
  if (eax > (u32)(24)) goto L62bdb1;  // @61_62bb10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6471188), sizeof v); (u32)v; });  // @62_62bb10
  switch (eax) { case 0: goto L62bc09; case 1: goto L62bc32; case 2: goto L62bc5b; case 3: goto L62bc96; case 4: goto L62bd7c; case 5: goto L62bc02; case 6: goto L62bdb1; case 7: goto L62bdb1; default: __builtin_trap(); }  // @63_62bb10
  L62bc02:;
  eax = (u32)(1);  // @65_62bb10
  goto L62bc82;  // @66_62bb10
  L62bc09:;
  eax = edi;  // @68_62bb10
  eax = (eax - esi);  // @69_62bb10
  if ((s32)eax < (s32)(u32)(2)) goto L62bd70;  // @70_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @71_62bb10
  p8_ = esi;  // @72_62bb10
  p9_ = ebx;  // @73_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p9_), (u32)(p8_));  // @74_62bb10
  ecx = edx = 0;  // @75_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @76_62bb10
  eax = (u32)(2);  // @77_62bb10
  goto L62bc82;  // @78_62bb10
  L62bc32:;
  eax = edi;  // @80_62bb10
  eax = (eax - esi);  // @81_62bb10
  if ((s32)eax < (s32)(u32)(3)) goto L62bd70;  // @82_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 336), sizeof v); (u32)v; });  // @83_62bb10
  p10_ = esi;  // @84_62bb10
  p11_ = ebx;  // @85_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p11_), (u32)(p10_));  // @86_62bb10
  ecx = edx = 0;  // @87_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @88_62bb10
  eax = (u32)(3);  // @89_62bb10
  goto L62bc82;  // @90_62bb10
  L62bc5b:;
  eax = edi;  // @92_62bb10
  eax = (eax - esi);  // @93_62bb10
  if ((s32)eax < (s32)(u32)(4)) goto L62bd70;  // @94_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 340), sizeof v); (u32)v; });  // @95_62bb10
  p12_ = esi;  // @96_62bb10
  p13_ = ebx;  // @97_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p13_), (u32)(p12_));  // @98_62bb10
  ecx = edx = 0;  // @99_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @100_62bb10
  eax = (u32)(4);  // @101_62bb10
  L62bc82:;
  esi = (esi + eax);  // @103_62bb10
  if (esi != edi) goto L62bbe0;  // @104_62bb10
  L62bc8c:;
  eax = (eax | (u32)(4294967295));  // @106_62bb10
  return eax;  // @107_62bb10
  L62bc96:;
  eax = (u32)(EBP + 12);  // @109_62bb10
  p14_ = eax;  // @110_62bb10
  p15_ = esi;  // @111_62bb10
  p16_ = ebx;  // @112_62bb10
  eax = ext_62a870_cdecl4((u32)(p16_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p15_), (u32)(p14_));  // @113_62bb10
  ecx = edx = 0;  // @114_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @115_62bb10
  esi = (esi + 1);  // @116_62bb10
  if (esi == edi) goto L62bc8c;  // @117_62bb10
  edi = (edi - esi);  // @118_62bb10
  L62bcc0:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_62bb10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @121_62bb10
  if (eax > (u32)(15)) goto L62bd59;  // @122_62bb10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6471240), sizeof v); (u32)v; });  // @123_62bb10
  switch (eax) { case 0: goto L62bdb1; case 1: goto L62bcdf; case 2: goto L62bd05; case 3: goto L62bd27; case 4: goto L62bd45; case 5: goto L62bd59; default: __builtin_trap(); }  // @124_62bb10
  L62bcdf:;
  if ((s32)edi < (s32)(u32)(2)) goto L62bd70;  // @126_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 356), sizeof v); (u32)v; });  // @127_62bb10
  p17_ = esi;  // @128_62bb10
  p18_ = ebx;  // @129_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p18_), (u32)(p17_));  // @130_62bb10
  ecx = edx = 0;  // @131_62bb10
  if ((eax & eax) != 0) goto L62bdb1;  // @132_62bb10
  esi = (esi + (u32)(2));  // @133_62bb10
  edi = (edi - (u32)(2));  // @134_62bb10
  goto L62bd5b;  // @135_62bb10
  L62bd05:;
  if ((s32)edi < (s32)(u32)(3)) goto L62bd70;  // @137_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 360), sizeof v); (u32)v; });  // @138_62bb10
  p19_ = esi;  // @139_62bb10
  p20_ = ebx;  // @140_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p20_), (u32)(p19_));  // @141_62bb10
  ecx = edx = 0;  // @142_62bb10
  if ((eax & eax) != 0) goto L62bdb1;  // @143_62bb10
  esi = (esi + (u32)(3));  // @144_62bb10
  edi = (edi - (u32)(3));  // @145_62bb10
  goto L62bd5b;  // @146_62bb10
  L62bd27:;
  if ((s32)edi < (s32)(u32)(4)) goto L62bd70;  // @148_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 364), sizeof v); (u32)v; });  // @149_62bb10
  p21_ = esi;  // @150_62bb10
  p22_ = ebx;  // @151_62bb10
  eax = ((u32( *)(u32, u32))(eax))((u32)(p22_), (u32)(p21_));  // @152_62bb10
  ecx = edx = 0;  // @153_62bb10
  if ((eax & eax) != 0) goto L62bdb1;  // @154_62bb10
  esi = (esi + (u32)(4));  // @155_62bb10
  edi = (edi - (u32)(4));  // @156_62bb10
  goto L62bd5b;  // @157_62bb10
  L62bd45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @159_62bb10
  esi = (esi + 1);  // @160_62bb10
  edi = (edi - 1);  // @161_62bb10
  if (esi == eax) goto L62bc8c;  // @162_62bb10
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(62)) goto L62bd9f;  // @163_62bb10
  goto L62bd5e;  // @164_62bb10
  L62bd59:;
  esi = (esi + 1);  // @166_62bb10
  edi = (edi - 1);  // @167_62bb10
  L62bd5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @169_62bb10
  L62bd5e:;
  if (esi != eax) goto L62bcc0;  // @171_62bb10
  eax = (eax | (u32)(4294967295));  // @172_62bb10
  return eax;  // @173_62bb10
  L62bd70:;
  eax = (u32)(4294967294);  // @175_62bb10
  return eax;  // @176_62bb10
  L62bd7c:;
  eax = (u32)(EBP + 12);  // @178_62bb10
  p23_ = eax;  // @179_62bb10
  p24_ = esi;  // @180_62bb10
  p25_ = ebx;  // @181_62bb10
  eax = ext_62a870_cdecl4((u32)(p25_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }), (u32)(p24_), (u32)(p23_));  // @182_62bb10
  ecx = edx = 0;  // @183_62bb10
  if ((eax & eax) == 0) goto L62bdb1;  // @184_62bb10
  esi = (esi + 1);  // @185_62bb10
  if (esi == edi) goto L62bc8c;  // @186_62bb10
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(62)) goto L62bdb1;  // @187_62bb10
  L62bd9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @189_62bb10
  ecx = (u32)(esi + 1);  // @190_62bb10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @191_62bb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @192_62bb10
  return eax;  // @193_62bb10
  L62bdb1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @195_62bb10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @196_62bb10
  eax = 0;  // @197_62bb10
  return eax;  // @198_62bb10
}
PCREG(62bb10, lifted_62bb10);

extern "C" u32 lifted_6218c0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  eax = (u32)(EBP + 8);  // @0_6218c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6218c0
  p0_ = esi;  // @2_6218c0
  p1_ = edi;  // @3_6218c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_6218c0
  p2_ = eax;  // @5_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_6218c0
  esi = (u32)(ebx + 424);  // @7_6218c0
  p3_ = edi;  // @8_6218c0
  p4_ = eax;  // @9_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @10_6218c0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32))(eax))((u32)(p4_), (u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @11_6218c0
  ecx = edx = 0;  // @12_6218c0
  eax = (eax + (u32)(4));  // @13_6218c0
  if (eax > (u32)(32)) goto L621ad1;  // @14_6218c0
  L621900:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6429664), sizeof v); (u32)v; });  // @16_6218c0
  switch (eax) { case 0: goto L621b74; case 1: goto L621a25; case 2: goto L621b7d; case 3: goto L621b9a; case 4: goto L621a00; case 5: goto L621a30; case 6: goto L621a50; case 7: goto L62190e; case 8: goto L621ad1; default: __builtin_trap(); }  // @17_6218c0
  L62190e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @19_6218c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 624), sizeof v); (u32)v; }) != (u32)(0)) goto L621926;  // @20_6218c0
  if (edx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621aee;  // @21_6218c0
  L621926:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 68), sizeof v); (u32)v; });  // @23_6218c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @24_6218c0
  ecx = (ecx - eax);  // @25_6218c0
  eax = (eax + edi);  // @26_6218c0
  p5_ = ecx;  // @27_6218c0
  p6_ = eax;  // @28_6218c0
  p7_ = edx;  // @29_6218c0
  eax = (u32)(ebx + 556);  // @30_6218c0
  p8_ = eax;  // @31_6218c0
  eax = ext_620180_cdecl4((u32)(p8_), (u32)(p7_), (u32)(p6_), (u32)(p5_));  // @32_6218c0
  ecx = edx = 0;  // @33_6218c0
  esi = (u32)(ebx + 424);  // @34_6218c0
  if ((eax & eax) == 0) goto L621a19;  // @35_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 568), sizeof v); (u32)v; });  // @36_6218c0
  ecx = (u32)(ebx + 556);  // @37_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L621978;  // @38_6218c0
  p9_ = ecx;  // @39_6218c0
  eax = ext_6206e0_cdecl1((u32)(p9_));  // @40_6218c0
  ecx = edx = 0;  // @41_6218c0
  if ((eax & eax) == 0) goto L621a19;  // @42_6218c0
  ecx = (u32)(ebx + 556);  // @43_6218c0
  L621978:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @45_6218c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @46_6218c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @47_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @48_6218c0
  if ((eax & eax) == 0) goto L621a19;  // @49_6218c0
  p10_ = eax;  // @50_6218c0
  eax = (u32)(ebx + 456);  // @51_6218c0
  p11_ = eax;  // @52_6218c0
  eax = ext_61fd60_cdecl3((u32)(p11_), (u32)(p10_), (u32)(0));  // @53_6218c0
  ecx = edx = 0;  // @54_6218c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 572), sizeof v); (u32)v; });  // @55_6218c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @56_6218c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 568), &v, sizeof v); }  // @57_6218c0
  if ((eax & eax) == 0) goto L621b3a;  // @58_6218c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L621b1d;  // @59_6218c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L621b00;  // @60_6218c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @61_6218c0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @62_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @63_6218c0
  eax = (eax + ecx);  // @64_6218c0
  p12_ = eax;  // @65_6218c0
  p13_ = ecx;  // @66_6218c0
  p14_ = ebx;  // @67_6218c0
  eax = ext_6218c0_cdecl4((u32)(p14_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 224), sizeof v); (u32)v; }), (u32)(p13_), (u32)(p12_));  // @68_6218c0
  ecx = edx = 0;  // @69_6218c0
  ecx = eax;  // @70_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @71_6218c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @72_6218c0
  if ((ecx & ecx) == 0) goto L621aae;  // @73_6218c0
  eax = ecx;  // @74_6218c0
  return eax;  // @75_6218c0
  L621a00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @77_6218c0
  p15_ = edi;  // @78_6218c0
  p16_ = eax;  // @79_6218c0
  p17_ = esi;  // @80_6218c0
  eax = ext_620180_cdecl4((u32)(p17_), (u32)(p16_), (u32)(p15_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @81_6218c0
  ecx = edx = 0;  // @82_6218c0
  if ((eax & eax) != 0) goto L621aae;  // @83_6218c0
  L621a19:;
  eax = (u32)(1);  // @85_6218c0
  return eax;  // @86_6218c0
  L621a25:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @88_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @89_6218c0
  eax = (eax + edi);  // @90_6218c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @91_6218c0
  L621a30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @93_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L621a45;  // @94_6218c0
  p18_ = esi;  // @95_6218c0
  eax = ext_6206e0_cdecl1((u32)(p18_));  // @96_6218c0
  ecx = edx = 0;  // @97_6218c0
  if ((eax & eax) == 0) goto L621a19;  // @98_6218c0
  L621a45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @100_6218c0
  { u8 v = (u8)((u32)(10)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @101_6218c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @102_6218c0
  goto L621aae;  // @103_6218c0
  L621a50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @105_6218c0
  p19_ = edi;  // @106_6218c0
  p20_ = eax;  // @107_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @108_6218c0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p20_), (u32)(p19_));  // @109_6218c0
  ecx = edx = 0;  // @110_6218c0
  if ((s32)(eax & eax) < 0) goto L621b57;  // @111_6218c0
  ecx = (u32)(EBP - 8);  // @112_6218c0
  p21_ = ecx;  // @113_6218c0
  p22_ = eax;  // @114_6218c0
  eax = ext_626e10_cdecl2((u32)(p22_), (u32)(p21_));  // @115_6218c0
  ecx = edx = 0;  // @116_6218c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @117_6218c0
  if ((eax & eax) == 0) goto L621b57;  // @118_6218c0
  edi = 0;  // @119_6218c0
  if ((s32)(eax & eax) <= 0) goto L621aae;  // @120_6218c0
  L621a83:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @122_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L621a9c;  // @123_6218c0
  p23_ = esi;  // @124_6218c0
  eax = ext_6206e0_cdecl1((u32)(p23_));  // @125_6218c0
  ecx = edx = 0;  // @126_6218c0
  if ((eax & eax) == 0) goto L621a19;  // @127_6218c0
  L621a9c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @129_6218c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi - 8), sizeof v); (u32)v; })) & 0xff);  // @130_6218c0
  edi = (edi + 1);  // @131_6218c0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @132_6218c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @133_6218c0
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; })) goto L621a83;  // @134_6218c0
  L621aae:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @136_6218c0
  eax = (u32)(EBP + 8);  // @137_6218c0
  p24_ = eax;  // @138_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @139_6218c0
  p25_ = edi;  // @140_6218c0
  p26_ = eax;  // @141_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @142_6218c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p26_), (u32)(p25_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p24_));  // @143_6218c0
  ecx = edx = 0;  // @144_6218c0
  eax = (eax + (u32)(4));  // @145_6218c0
  if (eax <= (u32)(32)) goto L621900;  // @146_6218c0
  L621ad1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @148_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621ae2;  // @149_6218c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @150_6218c0
  L621ae2:;
  eax = (u32)(23);  // @152_6218c0
  return eax;  // @153_6218c0
  L621aee:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @155_6218c0
  eax = (u32)(2);  // @156_6218c0
  return eax;  // @157_6218c0
  L621b00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @159_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621b11;  // @160_6218c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @161_6218c0
  L621b11:;
  eax = (u32)(10);  // @163_6218c0
  return eax;  // @164_6218c0
  L621b1d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @166_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621b2e;  // @167_6218c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @168_6218c0
  L621b2e:;
  eax = (u32)(12);  // @170_6218c0
  return eax;  // @171_6218c0
  L621b3a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @173_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621b4b;  // @174_6218c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @175_6218c0
  L621b4b:;
  eax = (u32)(11);  // @177_6218c0
  return eax;  // @178_6218c0
  L621b57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @180_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621b68;  // @181_6218c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @182_6218c0
  L621b68:;
  eax = (u32)(14);  // @184_6218c0
  return eax;  // @185_6218c0
  L621b74:;
  eax = 0;  // @187_6218c0
  return eax;  // @188_6218c0
  L621b7d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @190_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621b8e;  // @191_6218c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @192_6218c0
  L621b8e:;
  eax = (u32)(4);  // @194_6218c0
  return eax;  // @195_6218c0
  L621b9a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @197_6218c0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L621bae;  // @198_6218c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @199_6218c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @200_6218c0
  L621bae:;
  eax = (u32)(4);  // @202_6218c0
  return eax;  // @203_6218c0
}
PCREG(6218c0, lifted_6218c0);

extern "C" u32 lifted_62a8e0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_62a8e0
  edx = 0;  // @1_62a8e0
  p0_ = esi;  // @2_62a8e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_62a8e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_62a8e0
  p1_ = edi;  // @5_62a8e0
  if (esi == ebx) goto L62abb5;  // @6_62a8e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_62a8e0
  L62a900:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @10_62a8e0
  eax = (eax + (u32)(-5));  // @11_62a8e0
  if (eax > (u32)(24)) goto L62a9e8;  // @12_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6466616), sizeof v); (u32)v; });  // @13_62a8e0
  switch (eax) { case 0: goto L62a928; case 1: goto L62a952; case 2: goto L62a978; case 3: goto L62a9c3; case 4: goto L62a9f6; case 5: goto L62a922; case 6: goto L62a990; case 7: goto L62a9e8; case 8: goto L62a9e8; default: __builtin_trap(); }  // @14_62a8e0
  L62a922:;
  esi = (esi + 1);  // @16_62a8e0
  goto L62abad;  // @17_62a8e0
  L62a928:;
  eax = ebx;  // @19_62a8e0
  eax = (eax - esi);  // @20_62a8e0
  if ((s32)eax < (s32)(u32)(2)) goto L62abbf;  // @21_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 332), sizeof v); (u32)v; });  // @22_62a8e0
  L62a93b:;
  p2_ = esi;  // @24_62a8e0
  p3_ = edi;  // @25_62a8e0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(eax))((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @26_62a8e0
  ecx = edx = 0;  // @27_62a8e0
  if ((eax & eax) == 0) goto L62a9e8;  // @28_62a8e0
  esi = (esi + (u32)(2));  // @29_62a8e0
  goto L62abaa;  // @30_62a8e0
  L62a952:;
  eax = ebx;  // @32_62a8e0
  eax = (eax - esi);  // @33_62a8e0
  if ((s32)eax < (s32)(u32)(3)) goto L62abbf;  // @34_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 336), sizeof v); (u32)v; });  // @35_62a8e0
  L62a965:;
  p4_ = esi;  // @37_62a8e0
  p5_ = edi;  // @38_62a8e0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p5_), (u32)(p4_));  // @39_62a8e0
  ecx = edx = 0;  // @40_62a8e0
  if ((eax & eax) == 0) goto L62a9e8;  // @41_62a8e0
  esi = (esi + (u32)(3));  // @42_62a8e0
  goto L62abaa;  // @43_62a8e0
  L62a978:;
  eax = ebx;  // @45_62a8e0
  eax = (eax - esi);  // @46_62a8e0
  if ((s32)eax < (s32)(u32)(4)) goto L62abbf;  // @47_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 340), sizeof v); (u32)v; });  // @48_62a8e0
  goto L62ab98;  // @49_62a8e0
  L62a990:;
  if ((edx & edx) != 0) goto L62a9e8;  // @51_62a8e0
  esi = (esi + 1);  // @52_62a8e0
  edx = (u32)(1);  // @53_62a8e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @54_62a8e0
  if (esi == ebx) goto L62abb5;  // @55_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @57_62a8e0
  eax = (eax + (u32)(-5));  // @58_62a8e0
  if (eax > (u32)(24)) goto L62a9e8;  // @59_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6466668), sizeof v); (u32)v; });  // @60_62a8e0
  switch (eax) { case 0: goto L62ab61; case 1: goto L62ab75; case 2: goto L62ab89; case 3: goto L62a922; case 4: goto L62a9e8; case 5: goto L62a9e8; default: __builtin_trap(); }  // @61_62a8e0
  L62a9c3:;
  esi = (esi + 1);  // @63_62a8e0
  if (esi == ebx) goto L62abb5;  // @64_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @66_62a8e0
  if (eax == (u32)(14)) goto L62a9f6;  // @67_62a8e0
  if (eax < (u32)(9)) goto L62a9e8;  // @68_62a8e0
  if (eax <= (u32)(10)) goto L62a9c3;  // @69_62a8e0
  if (eax == (u32)(21)) goto L62a9c3;  // @70_62a8e0
  L62a9e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @72_62a8e0
  L62a9eb:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @74_62a8e0
  eax = 0;  // @75_62a8e0
  return eax;  // @76_62a8e0
  L62a9f6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @78_62a8e0
  L62aa00:;
  esi = (esi + 1);  // @80_62a8e0
  if (esi == ebx) goto L62abb5;  // @81_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_62a8e0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @83_62a8e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @84_62a8e0
  if (ecx == (u32)(12)) goto L62aa3b;  // @85_62a8e0
  if (ecx == (u32)(13)) goto L62aa3b;  // @86_62a8e0
  if (ecx < (u32)(9)) goto L62a9e8;  // @87_62a8e0
  if (ecx <= (u32)(10)) goto L62aa00;  // @88_62a8e0
  if (ecx == (u32)(21)) goto L62aa00;  // @89_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @90_62a8e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @91_62a8e0
  eax = 0;  // @92_62a8e0
  return eax;  // @93_62a8e0
  L62aa3b:;
  esi = (esi + 1);  // @95_62a8e0
  L62aa3c:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @97_62a8e0
  L62aa40:;
  if (esi == ebx) goto L62abb5;  // @99_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @101_62a8e0
  if (eax == ecx) goto L62ab0c;  // @102_62a8e0
  if (eax > (u32)(8)) goto L62aa3b;  // @103_62a8e0
  switch (eax) { case 0: goto L62a9e8; case 1: goto L62a9e8; case 2: goto L62a9e8; case 3: goto L62aae5; case 4: goto L62aa3b; case 5: goto L62aa64; case 6: goto L62aa8e; case 7: goto L62aab8; case 8: goto L62a9e8; case 9: goto L62ab37; case 10: goto L62ac00; case 11: goto L62abde; case 12: goto L62a9e8; default: __builtin_trap(); }  // @104_62a8e0
  L62aa64:;
  eax = ebx;  // @106_62a8e0
  eax = (eax - esi);  // @107_62a8e0
  if ((s32)eax < (s32)(u32)(2)) goto L62abbf;  // @108_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 356), sizeof v); (u32)v; });  // @109_62a8e0
  p6_ = esi;  // @110_62a8e0
  p7_ = edi;  // @111_62a8e0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p7_), (u32)(p6_));  // @112_62a8e0
  ecx = edx = 0;  // @113_62a8e0
  if ((eax & eax) != 0) goto L62a9e8;  // @114_62a8e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @115_62a8e0
  esi = (esi + (u32)(2));  // @116_62a8e0
  goto L62aa3c;  // @117_62a8e0
  L62aa8e:;
  eax = ebx;  // @119_62a8e0
  eax = (eax - esi);  // @120_62a8e0
  if ((s32)eax < (s32)(u32)(3)) goto L62abbf;  // @121_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 360), sizeof v); (u32)v; });  // @122_62a8e0
  p8_ = esi;  // @123_62a8e0
  p9_ = edi;  // @124_62a8e0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p9_), (u32)(p8_));  // @125_62a8e0
  ecx = edx = 0;  // @126_62a8e0
  if ((eax & eax) != 0) goto L62a9e8;  // @127_62a8e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @128_62a8e0
  esi = (esi + (u32)(3));  // @129_62a8e0
  goto L62aa3c;  // @130_62a8e0
  L62aab8:;
  eax = ebx;  // @132_62a8e0
  eax = (eax - esi);  // @133_62a8e0
  if ((s32)eax < (s32)(u32)(4)) goto L62abbf;  // @134_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 364), sizeof v); (u32)v; });  // @135_62a8e0
  p10_ = esi;  // @136_62a8e0
  p11_ = edi;  // @137_62a8e0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p11_), (u32)(p10_));  // @138_62a8e0
  ecx = edx = 0;  // @139_62a8e0
  if ((eax & eax) != 0) goto L62a9e8;  // @140_62a8e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @141_62a8e0
  esi = (esi + (u32)(4));  // @142_62a8e0
  goto L62aa3c;  // @143_62a8e0
  L62aae5:;
  eax = (u32)(EBP + 12);  // @145_62a8e0
  p12_ = eax;  // @146_62a8e0
  p13_ = ebx;  // @147_62a8e0
  eax = (u32)(esi + 1);  // @148_62a8e0
  p14_ = eax;  // @149_62a8e0
  p15_ = edi;  // @150_62a8e0
  eax = ext_62c060_cdecl4((u32)(p15_), (u32)(p14_), (u32)(p13_), (u32)(p12_));  // @151_62a8e0
  ecx = edx = 0;  // @152_62a8e0
  edx = eax;  // @153_62a8e0
  if ((s32)(edx & edx) <= 0) goto L62abcb;  // @154_62a8e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @155_62a8e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @156_62a8e0
  goto L62aa40;  // @157_62a8e0
  L62ab0c:;
  esi = (esi + 1);  // @159_62a8e0
  if (esi == ebx) goto L62abb5;  // @160_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @161_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @162_62a8e0
  eax = (eax + (u32)(-9));  // @163_62a8e0
  if (eax > (u32)(12)) goto L62a9e8;  // @164_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6466748), sizeof v); (u32)v; });  // @165_62a8e0
  switch (eax) { case 0: goto L62ab37; case 1: goto L62ac00; case 2: goto L62abde; case 3: goto L62a9e8; default: __builtin_trap(); }  // @166_62a8e0
  L62ab37:;
  esi = (esi + 1);  // @168_62a8e0
  if (esi == ebx) goto L62abb5;  // @169_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @170_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 76), sizeof v); (u32)v; });  // @171_62a8e0
  eax = (eax + (u32)(-5));  // @172_62a8e0
  if (eax > (u32)(24)) goto L62a9e8;  // @173_62a8e0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6466800), sizeof v); (u32)v; });  // @174_62a8e0
  switch (eax) { case 0: goto L62ab61; case 1: goto L62ab75; case 2: goto L62ab89; case 3: goto L62ab37; case 4: goto L62ac00; case 5: goto L62abde; case 6: goto L62ab5e; case 7: goto L62a9e8; case 8: goto L62a9e8; default: __builtin_trap(); }  // @175_62a8e0
  L62ab5e:;
  esi = (esi + 1);  // @177_62a8e0
  goto L62abaa;  // @178_62a8e0
  L62ab61:;
  eax = ebx;  // @180_62a8e0
  eax = (eax - esi);  // @181_62a8e0
  if ((s32)eax < (s32)(u32)(2)) goto L62abbf;  // @182_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 344), sizeof v); (u32)v; });  // @183_62a8e0
  goto L62a93b;  // @184_62a8e0
  L62ab75:;
  eax = ebx;  // @186_62a8e0
  eax = (eax - esi);  // @187_62a8e0
  if ((s32)eax < (s32)(u32)(3)) goto L62abbf;  // @188_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 348), sizeof v); (u32)v; });  // @189_62a8e0
  goto L62a965;  // @190_62a8e0
  L62ab89:;
  eax = ebx;  // @192_62a8e0
  eax = (eax - esi);  // @193_62a8e0
  if ((s32)eax < (s32)(u32)(4)) goto L62abbf;  // @194_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 352), sizeof v); (u32)v; });  // @195_62a8e0
  L62ab98:;
  p16_ = esi;  // @197_62a8e0
  p17_ = edi;  // @198_62a8e0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p17_), (u32)(p16_));  // @199_62a8e0
  ecx = edx = 0;  // @200_62a8e0
  if ((eax & eax) == 0) goto L62a9e8;  // @201_62a8e0
  esi = (esi + (u32)(4));  // @202_62a8e0
  L62abaa:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @204_62a8e0
  L62abad:;
  if (esi != ebx) goto L62a900;  // @206_62a8e0
  L62abb5:;
  eax = (eax | (u32)(4294967295));  // @208_62a8e0
  return eax;  // @209_62a8e0
  L62abbf:;
  eax = (u32)(4294967294);  // @211_62a8e0
  return eax;  // @212_62a8e0
  L62abcb:;
  if (eax != 0) goto L62abd5;  // @214_62a8e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @215_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @216_62a8e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @217_62a8e0
  L62abd5:;
  eax = edx;  // @219_62a8e0
  return eax;  // @220_62a8e0
  L62abde:;
  esi = (esi + 1);  // @222_62a8e0
  if (esi == ebx) goto L62abb5;  // @223_62a8e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @224_62a8e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(62)) goto L62a9eb;  // @225_62a8e0
  ecx = (u32)(esi + 1);  // @226_62a8e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @227_62a8e0
  eax = (u32)(3);  // @228_62a8e0
  return eax;  // @229_62a8e0
  L62ac00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @231_62a8e0
  ecx = (u32)(esi + 1);  // @232_62a8e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @233_62a8e0
  eax = (u32)(1);  // @234_62a8e0
  return eax;  // @235_62a8e0
}
PCREG(62a8e0, lifted_62a8e0);

extern "C" u32 lifted_629c10(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_629c10
  p0_ = edi;  // @1_629c10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_629c10
  if (edx != edi) goto L629c24;  // @3_629c10
  eax = (eax | (u32)(4294967295));  // @4_629c10
  return eax;  // @5_629c10
  L629c24:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @7_629c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @8_629c10
  p1_ = ebx;  // @9_629c10
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @10_629c10
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L629c3e;  // @11_629c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_629c10
  eax = (ebx & 0xff);  // @13_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @14_629c10
  goto L629c4b;  // @15_629c10
  L629c3e:;
  p2_ = ebx;  // @17_629c10
  p3_ = eax;  // @18_629c10
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_629c10
  ecx = edx = 0;  // @20_629c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_629c10
  L629c4b:;
  eax = (eax - (u32)(5));  // @23_629c10
  p4_ = esi;  // @24_629c10
  if (eax > (u32)(24)) goto L629f24;  // @25_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6463316), sizeof v); (u32)v; });  // @26_629c10
  switch (eax) { case 0: goto L629d82; case 1: goto L629d97; case 2: goto L629dac; case 3: goto L629ef8; case 4: goto L629e98; case 5: goto L629f0e; case 6: goto L629c95; case 7: goto L629c66; case 8: goto L629f24; default: __builtin_trap(); }  // @27_629c10
  L629c66:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @29_629c10
  eax = (eax & 0xff);  // @30_629c10
  ecx = (ebx & 0xff);  // @31_629c10
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @32_629c10
  eax = ecx;  // @33_629c10
  eax = (eax >> (u32)(5));  // @34_629c10
  ecx = (ecx & (u32)(31));  // @35_629c10
  esi = (u32)(eax + esi*8);  // @36_629c10
  eax = (u32)(1);  // @37_629c10
  eax = (eax << (ecx & 0xff));  // @38_629c10
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L629f24;  // @39_629c10
  L629c95:;
  edx = (edx + (u32)(2));  // @41_629c10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @42_629c10
  if (edx == edi) goto L629e9f;  // @43_629c10
  L629ca7:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @45_629c10
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @46_629c10
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L629cbd;  // @47_629c10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @48_629c10
  eax = (ecx & 0xff);  // @49_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @50_629c10
  goto L629cca;  // @51_629c10
  L629cbd:;
  p5_ = ecx;  // @53_629c10
  p6_ = ebx;  // @54_629c10
  eax = ext_62c640_cdecl3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @55_629c10
  ecx = edx = 0;  // @56_629c10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @57_629c10
  L629cca:;
  eax = (eax - (u32)(5));  // @59_629c10
  if (eax > (u32)(24)) goto L629f24;  // @60_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6463384), sizeof v); (u32)v; });  // @61_629c10
  switch (eax) { case 0: goto L629d82; case 1: goto L629d97; case 2: goto L629dac; case 3: goto L629dc1; case 4: goto L629e5a; case 5: goto L629e6c; case 6: goto L629d6f; case 7: goto L629cf0; case 8: goto L629ce4; case 9: goto L629f24; default: __builtin_trap(); }  // @62_629c10
  L629ce4:;
  eax = (ebx & 0xff);  // @64_629c10
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @65_629c10
  goto L629d4d;  // @66_629c10
  L629cf0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L629f24;  // @68_629c10
  edx = (edx + (u32)(2));  // @69_629c10
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @70_629c10
  if (edx == edi) goto L629e9f;  // @71_629c10
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @72_629c10
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @73_629c10
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L629d1f;  // @74_629c10
  eax = (ecx & 0xff);  // @75_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @76_629c10
  goto L629d29;  // @77_629c10
  L629d1f:;
  p7_ = ecx;  // @79_629c10
  p8_ = ebx;  // @80_629c10
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @81_629c10
  ecx = edx = 0;  // @82_629c10
  L629d29:;
  eax = (eax - (u32)(5));  // @84_629c10
  if (eax > (u32)(24)) goto L629f24;  // @85_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6463436), sizeof v); (u32)v; });  // @86_629c10
  switch (eax) { case 0: goto L629d82; case 1: goto L629d97; case 2: goto L629dac; case 3: goto L629d6f; case 4: goto L629d43; case 5: goto L629f24; default: __builtin_trap(); }  // @87_629c10
  L629d43:;
  eax = (ebx & 0xff);  // @89_629c10
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @90_629c10
  L629d4d:;
  ecx = (ecx & 0xff);  // @92_629c10
  eax = ecx;  // @93_629c10
  ecx = (ecx & (u32)(31));  // @94_629c10
  eax = (eax >> (u32)(5));  // @95_629c10
  esi = (u32)(eax + esi*8);  // @96_629c10
  eax = (u32)(1);  // @97_629c10
  eax = (eax << (ecx & 0xff));  // @98_629c10
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L629f24;  // @99_629c10
  L629d6f:;
  edx = (edx + (u32)(2));  // @101_629c10
  if (edx != edi) goto L629ca7;  // @102_629c10
  eax = (eax | (u32)(4294967295));  // @103_629c10
  return eax;  // @104_629c10
  L629d82:;
  edi = (edi - edx);  // @106_629c10
  if ((s32)edi >= (s32)(u32)(2)) goto L629f24;  // @107_629c10
  eax = (u32)(4294967294);  // @108_629c10
  return eax;  // @109_629c10
  L629d97:;
  edi = (edi - edx);  // @111_629c10
  if ((s32)edi >= (s32)(u32)(3)) goto L629f24;  // @112_629c10
  eax = (u32)(4294967294);  // @113_629c10
  return eax;  // @114_629c10
  L629dac:;
  edi = (edi - edx);  // @116_629c10
  if ((s32)edi >= (s32)(u32)(4)) goto L629f24;  // @117_629c10
  eax = (u32)(4294967294);  // @118_629c10
  return eax;  // @119_629c10
  L629dc1:;
  edx = (edx + (u32)(2));  // @121_629c10
  if (edx == edi) goto L629e9f;  // @122_629c10
  L629dd0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @124_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @125_629c10
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L629de1;  // @126_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @127_629c10
  goto L629deb;  // @128_629c10
  L629de1:;
  p9_ = eax;  // @130_629c10
  p10_ = ecx;  // @131_629c10
  eax = ext_62c640_cdecl2((u32)(p10_), (u32)(p9_));  // @132_629c10
  ecx = edx = 0;  // @133_629c10
  L629deb:;
  eax = (eax - (u32)(5));  // @135_629c10
  if (eax > (u32)(24)) goto L629f24;  // @136_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6463500), sizeof v); (u32)v; });  // @137_629c10
  switch (eax) { case 0: goto L629d82; case 1: goto L629d97; case 2: goto L629dac; case 3: goto L629e05; case 4: goto L629e5a; case 5: goto L629e6c; case 6: goto L629e41; case 7: goto L629e14; case 8: goto L629f24; default: __builtin_trap(); }  // @138_629c10
  L629e05:;
  edx = (edx + (u32)(2));  // @140_629c10
  if (edx != edi) goto L629dd0;  // @141_629c10
  eax = (eax | (u32)(4294967295));  // @142_629c10
  return eax;  // @143_629c10
  L629e14:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @145_629c10
  ebx = (u32)(1);  // @146_629c10
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @147_629c10
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @148_629c10
  eax = ecx;  // @149_629c10
  eax = (eax >> (u32)(5));  // @150_629c10
  ecx = (ecx & (u32)(31));  // @151_629c10
  ebx = (ebx << (ecx & 0xff));  // @152_629c10
  eax = (u32)(eax + esi*8);  // @153_629c10
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7075616), sizeof v); (u32)v; }) & ebx) == 0) goto L629f24;  // @154_629c10
  L629e41:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @156_629c10
  edx = (edx + (u32)(2));  // @157_629c10
  p11_ = edi;  // @158_629c10
  p12_ = edx;  // @159_629c10
  p13_ = ecx;  // @160_629c10
  eax = ext_628fc0_cdecl4((u32)(p13_), (u32)(p12_), (u32)(p11_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @161_629c10
  ecx = edx = 0;  // @162_629c10
  return eax;  // @163_629c10
  L629e5a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @165_629c10
  edx = (edx + (u32)(2));  // @166_629c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @167_629c10
  eax = (u32)(2);  // @168_629c10
  return eax;  // @169_629c10
  L629e6c:;
  edx = (edx + (u32)(2));  // @171_629c10
  if (edx == edi) goto L629e9f;  // @172_629c10
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L629f24;  // @173_629c10
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(62)) goto L629f24;  // @174_629c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @175_629c10
  edx = (edx + (u32)(2));  // @176_629c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @177_629c10
  eax = (u32)(4);  // @178_629c10
  return eax;  // @179_629c10
  L629e98:;
  edx = (edx + (u32)(2));  // @181_629c10
  if (edx != edi) goto L629ea7;  // @182_629c10
  L629e9f:;
  eax = (eax | (u32)(4294967295));  // @184_629c10
  return eax;  // @185_629c10
  L629ea7:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @187_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @188_629c10
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L629eb8;  // @189_629c10
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @190_629c10
  goto L629ec2;  // @191_629c10
  L629eb8:;
  p14_ = eax;  // @193_629c10
  p15_ = ebx;  // @194_629c10
  eax = ext_62c640_cdecl2((u32)(p15_), (u32)(p14_));  // @195_629c10
  ecx = edx = 0;  // @196_629c10
  L629ec2:;
  if (eax == (u32)(20)) goto L629ee2;  // @198_629c10
  if (eax != (u32)(27)) goto L629f24;  // @199_629c10
  edx = (edx + (u32)(2));  // @200_629c10
  p16_ = edi;  // @201_629c10
  p17_ = edx;  // @202_629c10
  p18_ = ecx;  // @203_629c10
  eax = ext_629580_cdecl4((u32)(p18_), (u32)(p17_), (u32)(p16_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @204_629c10
  ecx = edx = 0;  // @205_629c10
  return eax;  // @206_629c10
  L629ee2:;
  edx = (edx + (u32)(2));  // @208_629c10
  p19_ = edi;  // @209_629c10
  p20_ = edx;  // @210_629c10
  p21_ = ecx;  // @211_629c10
  eax = ext_629480_cdecl4((u32)(p21_), (u32)(p20_), (u32)(p19_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @212_629c10
  ecx = edx = 0;  // @213_629c10
  return eax;  // @214_629c10
  L629ef8:;
  edx = (edx + (u32)(2));  // @216_629c10
  p22_ = edi;  // @217_629c10
  p23_ = edx;  // @218_629c10
  p24_ = ecx;  // @219_629c10
  eax = ext_62a200_cdecl4((u32)(p24_), (u32)(p23_), (u32)(p22_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @220_629c10
  ecx = edx = 0;  // @221_629c10
  return eax;  // @222_629c10
  L629f0e:;
  edx = (edx + (u32)(2));  // @224_629c10
  p25_ = edi;  // @225_629c10
  p26_ = edx;  // @226_629c10
  p27_ = ecx;  // @227_629c10
  eax = ext_629810_cdecl4((u32)(p27_), (u32)(p26_), (u32)(p25_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @228_629c10
  ecx = edx = 0;  // @229_629c10
  return eax;  // @230_629c10
  L629f24:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @232_629c10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @233_629c10
  eax = 0;  // @234_629c10
  return eax;  // @235_629c10
}
PCREG(629c10, lifted_629c10);

extern "C" u32 lifted_627bb0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_627bb0
  p0_ = edi;  // @1_627bb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_627bb0
  if (edx != edi) goto L627bc4;  // @3_627bb0
  eax = (eax | (u32)(4294967295));  // @4_627bb0
  return eax;  // @5_627bb0
  L627bc4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @7_627bb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @8_627bb0
  p1_ = ebx;  // @9_627bb0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @10_627bb0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L627bde;  // @11_627bb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_627bb0
  eax = (ebx & 0xff);  // @13_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @14_627bb0
  goto L627beb;  // @15_627bb0
  L627bde:;
  p2_ = ebx;  // @17_627bb0
  p3_ = eax;  // @18_627bb0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @19_627bb0
  ecx = edx = 0;  // @20_627bb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_627bb0
  L627beb:;
  eax = (eax - (u32)(5));  // @23_627bb0
  p4_ = esi;  // @24_627bb0
  if (eax > (u32)(24)) goto L627ec4;  // @25_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6455028), sizeof v); (u32)v; });  // @26_627bb0
  switch (eax) { case 0: goto L627d22; case 1: goto L627d37; case 2: goto L627d4c; case 3: goto L627e98; case 4: goto L627e38; case 5: goto L627eae; case 6: goto L627c35; case 7: goto L627c06; case 8: goto L627ec4; default: __builtin_trap(); }  // @27_627bb0
  L627c06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @29_627bb0
  eax = (eax & 0xff);  // @30_627bb0
  ecx = (ebx & 0xff);  // @31_627bb0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @32_627bb0
  eax = ecx;  // @33_627bb0
  eax = (eax >> (u32)(5));  // @34_627bb0
  ecx = (ecx & (u32)(31));  // @35_627bb0
  esi = (u32)(eax + esi*8);  // @36_627bb0
  eax = (u32)(1);  // @37_627bb0
  eax = (eax << (ecx & 0xff));  // @38_627bb0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L627ec4;  // @39_627bb0
  L627c35:;
  edx = (edx + (u32)(2));  // @41_627bb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @42_627bb0
  if (edx == edi) goto L627e3f;  // @43_627bb0
  L627c47:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @45_627bb0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @46_627bb0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L627c5d;  // @47_627bb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @48_627bb0
  eax = (ecx & 0xff);  // @49_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @50_627bb0
  goto L627c6a;  // @51_627bb0
  L627c5d:;
  p5_ = ecx;  // @53_627bb0
  p6_ = ebx;  // @54_627bb0
  eax = ext_62c640_cdecl3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @55_627bb0
  ecx = edx = 0;  // @56_627bb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @57_627bb0
  L627c6a:;
  eax = (eax - (u32)(5));  // @59_627bb0
  if (eax > (u32)(24)) goto L627ec4;  // @60_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6455096), sizeof v); (u32)v; });  // @61_627bb0
  switch (eax) { case 0: goto L627d22; case 1: goto L627d37; case 2: goto L627d4c; case 3: goto L627d61; case 4: goto L627dfa; case 5: goto L627e0c; case 6: goto L627d0f; case 7: goto L627c90; case 8: goto L627c84; case 9: goto L627ec4; default: __builtin_trap(); }  // @62_627bb0
  L627c84:;
  eax = (ebx & 0xff);  // @64_627bb0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @65_627bb0
  goto L627ced;  // @66_627bb0
  L627c90:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L627ec4;  // @68_627bb0
  edx = (edx + (u32)(2));  // @69_627bb0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @70_627bb0
  if (edx == edi) goto L627e3f;  // @71_627bb0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @72_627bb0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @73_627bb0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L627cbf;  // @74_627bb0
  eax = (ecx & 0xff);  // @75_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @76_627bb0
  goto L627cc9;  // @77_627bb0
  L627cbf:;
  p7_ = ecx;  // @79_627bb0
  p8_ = ebx;  // @80_627bb0
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @81_627bb0
  ecx = edx = 0;  // @82_627bb0
  L627cc9:;
  eax = (eax - (u32)(5));  // @84_627bb0
  if (eax > (u32)(24)) goto L627ec4;  // @85_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6455148), sizeof v); (u32)v; });  // @86_627bb0
  switch (eax) { case 0: goto L627d22; case 1: goto L627d37; case 2: goto L627d4c; case 3: goto L627d0f; case 4: goto L627ce3; case 5: goto L627ec4; default: __builtin_trap(); }  // @87_627bb0
  L627ce3:;
  eax = (ebx & 0xff);  // @89_627bb0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @90_627bb0
  L627ced:;
  ecx = (ecx & 0xff);  // @92_627bb0
  eax = ecx;  // @93_627bb0
  ecx = (ecx & (u32)(31));  // @94_627bb0
  eax = (eax >> (u32)(5));  // @95_627bb0
  esi = (u32)(eax + esi*8);  // @96_627bb0
  eax = (u32)(1);  // @97_627bb0
  eax = (eax << (ecx & 0xff));  // @98_627bb0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L627ec4;  // @99_627bb0
  L627d0f:;
  edx = (edx + (u32)(2));  // @101_627bb0
  if (edx != edi) goto L627c47;  // @102_627bb0
  eax = (eax | (u32)(4294967295));  // @103_627bb0
  return eax;  // @104_627bb0
  L627d22:;
  edi = (edi - edx);  // @106_627bb0
  if ((s32)edi >= (s32)(u32)(2)) goto L627ec4;  // @107_627bb0
  eax = (u32)(4294967294);  // @108_627bb0
  return eax;  // @109_627bb0
  L627d37:;
  edi = (edi - edx);  // @111_627bb0
  if ((s32)edi >= (s32)(u32)(3)) goto L627ec4;  // @112_627bb0
  eax = (u32)(4294967294);  // @113_627bb0
  return eax;  // @114_627bb0
  L627d4c:;
  edi = (edi - edx);  // @116_627bb0
  if ((s32)edi >= (s32)(u32)(4)) goto L627ec4;  // @117_627bb0
  eax = (u32)(4294967294);  // @118_627bb0
  return eax;  // @119_627bb0
  L627d61:;
  edx = (edx + (u32)(2));  // @121_627bb0
  if (edx == edi) goto L627e3f;  // @122_627bb0
  L627d70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @124_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @125_627bb0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L627d81;  // @126_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @127_627bb0
  goto L627d8b;  // @128_627bb0
  L627d81:;
  p9_ = eax;  // @130_627bb0
  p10_ = ecx;  // @131_627bb0
  eax = ext_62c640_cdecl2((u32)(p10_), (u32)(p9_));  // @132_627bb0
  ecx = edx = 0;  // @133_627bb0
  L627d8b:;
  eax = (eax - (u32)(5));  // @135_627bb0
  if (eax > (u32)(24)) goto L627ec4;  // @136_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6455212), sizeof v); (u32)v; });  // @137_627bb0
  switch (eax) { case 0: goto L627d22; case 1: goto L627d37; case 2: goto L627d4c; case 3: goto L627da5; case 4: goto L627dfa; case 5: goto L627e0c; case 6: goto L627de1; case 7: goto L627db4; case 8: goto L627ec4; default: __builtin_trap(); }  // @138_627bb0
  L627da5:;
  edx = (edx + (u32)(2));  // @140_627bb0
  if (edx != edi) goto L627d70;  // @141_627bb0
  eax = (eax | (u32)(4294967295));  // @142_627bb0
  return eax;  // @143_627bb0
  L627db4:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @145_627bb0
  ebx = (u32)(1);  // @146_627bb0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @147_627bb0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @148_627bb0
  eax = ecx;  // @149_627bb0
  eax = (eax >> (u32)(5));  // @150_627bb0
  ecx = (ecx & (u32)(31));  // @151_627bb0
  ebx = (ebx << (ecx & 0xff));  // @152_627bb0
  eax = (u32)(eax + esi*8);  // @153_627bb0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7075616), sizeof v); (u32)v; }) & ebx) == 0) goto L627ec4;  // @154_627bb0
  L627de1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @156_627bb0
  edx = (edx + (u32)(2));  // @157_627bb0
  p11_ = edi;  // @158_627bb0
  p12_ = edx;  // @159_627bb0
  p13_ = ecx;  // @160_627bb0
  eax = ext_626f60_cdecl4((u32)(p13_), (u32)(p12_), (u32)(p11_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @161_627bb0
  ecx = edx = 0;  // @162_627bb0
  return eax;  // @163_627bb0
  L627dfa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @165_627bb0
  edx = (edx + (u32)(2));  // @166_627bb0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @167_627bb0
  eax = (u32)(2);  // @168_627bb0
  return eax;  // @169_627bb0
  L627e0c:;
  edx = (edx + (u32)(2));  // @171_627bb0
  if (edx == edi) goto L627e3f;  // @172_627bb0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(0)) goto L627ec4;  // @173_627bb0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; }) != (u32)(62)) goto L627ec4;  // @174_627bb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @175_627bb0
  edx = (edx + (u32)(2));  // @176_627bb0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @177_627bb0
  eax = (u32)(4);  // @178_627bb0
  return eax;  // @179_627bb0
  L627e38:;
  edx = (edx + (u32)(2));  // @181_627bb0
  if (edx != edi) goto L627e47;  // @182_627bb0
  L627e3f:;
  eax = (eax | (u32)(4294967295));  // @184_627bb0
  return eax;  // @185_627bb0
  L627e47:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @187_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @188_627bb0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L627e58;  // @189_627bb0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx + 76), sizeof v); (u32)v; });  // @190_627bb0
  goto L627e62;  // @191_627bb0
  L627e58:;
  p14_ = eax;  // @193_627bb0
  p15_ = ebx;  // @194_627bb0
  eax = ext_62c640_cdecl2((u32)(p15_), (u32)(p14_));  // @195_627bb0
  ecx = edx = 0;  // @196_627bb0
  L627e62:;
  if (eax == (u32)(20)) goto L627e82;  // @198_627bb0
  if (eax != (u32)(27)) goto L627ec4;  // @199_627bb0
  edx = (edx + (u32)(2));  // @200_627bb0
  p16_ = edi;  // @201_627bb0
  p17_ = edx;  // @202_627bb0
  p18_ = ecx;  // @203_627bb0
  eax = ext_627520_cdecl4((u32)(p18_), (u32)(p17_), (u32)(p16_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @204_627bb0
  ecx = edx = 0;  // @205_627bb0
  return eax;  // @206_627bb0
  L627e82:;
  edx = (edx + (u32)(2));  // @208_627bb0
  p19_ = edi;  // @209_627bb0
  p20_ = edx;  // @210_627bb0
  p21_ = ecx;  // @211_627bb0
  eax = ext_627420_cdecl4((u32)(p21_), (u32)(p20_), (u32)(p19_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @212_627bb0
  ecx = edx = 0;  // @213_627bb0
  return eax;  // @214_627bb0
  L627e98:;
  edx = (edx + (u32)(2));  // @216_627bb0
  p22_ = edi;  // @217_627bb0
  p23_ = edx;  // @218_627bb0
  p24_ = ecx;  // @219_627bb0
  eax = ext_6281a0_cdecl4((u32)(p24_), (u32)(p23_), (u32)(p22_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @220_627bb0
  ecx = edx = 0;  // @221_627bb0
  return eax;  // @222_627bb0
  L627eae:;
  edx = (edx + (u32)(2));  // @224_627bb0
  p25_ = edi;  // @225_627bb0
  p26_ = edx;  // @226_627bb0
  p27_ = ecx;  // @227_627bb0
  eax = ext_6277b0_cdecl4((u32)(p27_), (u32)(p26_), (u32)(p25_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @228_627bb0
  ecx = edx = 0;  // @229_627bb0
  return eax;  // @230_627bb0
  L627ec4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @232_627bb0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @233_627bb0
  eax = 0;  // @234_627bb0
  return eax;  // @235_627bb0
}
PCREG(627bb0, lifted_627bb0);

extern "C" u32 THISCALL lifted_626f60(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_626f60
  p0_ = edi;  // @1_626f60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_626f60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_626f60
  if (edi == esi) goto L62724a;  // @4_626f60
  L626f80:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @6_626f60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @7_626f60
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L626f96;  // @8_626f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_626f60
  eax = (ecx & 0xff);  // @10_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @11_626f60
  goto L626fa3;  // @12_626f60
  L626f96:;
  p1_ = ecx;  // @14_626f60
  p2_ = ebx;  // @15_626f60
  eax = ext_62c640_cdecl3((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @16_626f60
  ecx = edx = 0;  // @17_626f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_626f60
  L626fa3:;
  eax = (eax - (u32)(5));  // @20_626f60
  if (eax > (u32)(24)) goto L62706a;  // @21_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6451988), sizeof v); (u32)v; });  // @22_626f60
  switch (eax) { case 0: goto L6272a9; case 1: goto L6272c0; case 2: goto L6272d7; case 3: goto L627030; case 4: goto L627078; case 5: goto L62723f; case 6: goto L626fcf; case 7: goto L626fbd; case 8: goto L62706a; default: __builtin_trap(); }  // @23_626f60
  L626fbd:;
  eax = (ebx & 0xff);  // @25_626f60
  ecx = (ecx & 0xff);  // @26_626f60
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @27_626f60
  goto L627220;  // @28_626f60
  L626fcf:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L62706a;  // @30_626f60
  edi = (edi + (u32)(2));  // @31_626f60
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @32_626f60
  if (edi == esi) goto L62724a;  // @33_626f60
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @34_626f60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @35_626f60
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L626ffe;  // @36_626f60
  eax = (ecx & 0xff);  // @37_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @38_626f60
  goto L627008;  // @39_626f60
  L626ffe:;
  p3_ = ecx;  // @41_626f60
  p4_ = ebx;  // @42_626f60
  eax = ext_62c640_cdecl2((u32)(p4_), (u32)(p3_));  // @43_626f60
  ecx = edx = 0;  // @44_626f60
  L627008:;
  eax = (eax - (u32)(5));  // @46_626f60
  if (eax > (u32)(24)) goto L62706a;  // @47_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6452040), sizeof v); (u32)v; });  // @48_626f60
  switch (eax) { case 0: goto L6272a9; case 1: goto L6272c0; case 2: goto L6272d7; case 3: goto L62723f; case 4: goto L62701e; case 5: goto L62706a; default: __builtin_trap(); }  // @49_626f60
  L62701e:;
  ecx = (ecx & 0xff);  // @51_626f60
  eax = (ebx & 0xff);  // @52_626f60
  goto L627219;  // @53_626f60
  L627030:;
  edi = (edi + (u32)(2));  // @55_626f60
  if (edi == esi) goto L62724a;  // @56_626f60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @57_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @58_626f60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L62704c;  // @59_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @60_626f60
  goto L627056;  // @61_626f60
  L62704c:;
  p5_ = eax;  // @63_626f60
  p6_ = ecx;  // @64_626f60
  eax = ext_62c640_cdecl2((u32)(p6_), (u32)(p5_));  // @65_626f60
  ecx = edx = 0;  // @66_626f60
  L627056:;
  if (eax == (u32)(14)) goto L627078;  // @68_626f60
  if ((s32)eax < (s32)(u32)(9)) goto L62706a;  // @69_626f60
  if ((s32)eax <= (s32)(u32)(10)) goto L627030;  // @70_626f60
  if (eax == (u32)(21)) goto L627030;  // @71_626f60
  L62706a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @73_626f60
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @74_626f60
  eax = 0;  // @75_626f60
  return eax;  // @76_626f60
  L627078:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @78_626f60
  L627080:;
  edi = (edi + (u32)(2));  // @80_626f60
  if (edi == esi) goto L62724a;  // @81_626f60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @82_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @83_626f60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L62709c;  // @84_626f60
  ebx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @85_626f60
  goto L6270a8;  // @86_626f60
  L62709c:;
  p7_ = eax;  // @88_626f60
  p8_ = ecx;  // @89_626f60
  eax = ext_62c640_cdecl2((u32)(p8_), (u32)(p7_));  // @90_626f60
  ecx = edx = 0;  // @91_626f60
  ebx = eax;  // @92_626f60
  L6270a8:;
  if (ebx == (u32)(12)) goto L6270cf;  // @94_626f60
  if (ebx == (u32)(13)) goto L6270cf;  // @95_626f60
  if ((s32)ebx < (s32)(u32)(9)) goto L62706a;  // @96_626f60
  if ((s32)ebx <= (s32)(u32)(10)) goto L627080;  // @97_626f60
  if (ebx == (u32)(21)) goto L627080;  // @98_626f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @99_626f60
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @100_626f60
  eax = 0;  // @101_626f60
  return eax;  // @102_626f60
  L6270cf:;
  edi = (edi + (u32)(2));  // @104_626f60
  L6270d2:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @106_626f60
  L6270d5:;
  if (edi == esi) goto L62724a;  // @108_626f60
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @109_626f60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6270ee;  // @110_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @111_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @112_626f60
  goto L627126;  // @113_626f60
  L6270ee:;
  eax = (eax & 0xff);  // @115_626f60
  eax = (eax + (u32)(4294967080));  // @116_626f60
  if (eax > (u32)(39)) goto L627121;  // @117_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6452084), sizeof v); (u32)v; });  // @118_626f60
  switch (eax) { case 0: goto L627109; case 1: goto L627110; case 2: goto L627117; case 3: goto L627121; default: __builtin_trap(); }  // @119_626f60
  L627109:;
  eax = (u32)(7);  // @121_626f60
  goto L627126;  // @122_626f60
  L627110:;
  eax = (u32)(8);  // @124_626f60
  goto L627126;  // @125_626f60
  L627117:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) < (u32)(254)) goto L627121;  // @127_626f60
  eax = 0;  // @128_626f60
  goto L627126;  // @129_626f60
  L627121:;
  eax = (u32)(29);  // @131_626f60
  L627126:;
  if (eax == ebx) goto L627196;  // @133_626f60
  if (eax > (u32)(8)) goto L6270cf;  // @134_626f60
  switch (eax) { case 0: goto L62706a; case 1: goto L62706a; case 2: goto L62706a; case 3: goto L62716f; case 4: goto L6270cf; case 5: goto L627136; case 6: goto L627145; case 7: goto L62715a; case 8: goto L62706a; case 9: goto L6271d6; case 10: goto L627295; case 11: goto L627267; case 12: goto L62706a; default: __builtin_trap(); }  // @135_626f60
  L627136:;
  eax = esi;  // @137_626f60
  eax = (eax - edi);  // @138_626f60
  if ((s32)eax < (s32)(u32)(2)) goto L6272b4;  // @139_626f60
  goto L6270cf;  // @140_626f60
  L627145:;
  eax = esi;  // @142_626f60
  eax = (eax - edi);  // @143_626f60
  if ((s32)eax < (s32)(u32)(3)) goto L6272b4;  // @144_626f60
  edi = (edi + (u32)(3));  // @145_626f60
  goto L6270d2;  // @146_626f60
  L62715a:;
  eax = esi;  // @148_626f60
  eax = (eax - edi);  // @149_626f60
  if ((s32)eax < (s32)(u32)(4)) goto L6272b4;  // @150_626f60
  edi = (edi + (u32)(4));  // @151_626f60
  goto L6270d2;  // @152_626f60
  L62716f:;
  eax = (u32)(EBP + 12);  // @154_626f60
  p9_ = eax;  // @155_626f60
  p10_ = esi;  // @156_626f60
  eax = (u32)(edi + 2);  // @157_626f60
  p11_ = eax;  // @158_626f60
  p12_ = edx;  // @159_626f60
  eax = ext_628630_cdecl4((u32)(p12_), (u32)(p11_), (u32)(p10_), (u32)(p9_));  // @160_626f60
  ecx = edx = 0;  // @161_626f60
  edx = eax;  // @162_626f60
  if ((s32)(edx & edx) <= 0) goto L627254;  // @163_626f60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @164_626f60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @165_626f60
  goto L6270d5;  // @166_626f60
  L627196:;
  edi = (edi + (u32)(2));  // @168_626f60
  if (edi == esi) goto L62724a;  // @169_626f60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @170_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @171_626f60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L6271b2;  // @172_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @173_626f60
  goto L6271bc;  // @174_626f60
  L6271b2:;
  p13_ = eax;  // @176_626f60
  p14_ = ecx;  // @177_626f60
  eax = ext_62c640_cdecl2((u32)(p14_), (u32)(p13_));  // @178_626f60
  ecx = edx = 0;  // @179_626f60
  L6271bc:;
  eax = (eax - (u32)(9));  // @181_626f60
  if (eax > (u32)(12)) goto L62706a;  // @182_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6452176), sizeof v); (u32)v; });  // @183_626f60
  switch (eax) { case 0: goto L6271d6; case 1: goto L627295; case 2: goto L627267; case 3: goto L62706a; default: __builtin_trap(); }  // @184_626f60
  L6271d6:;
  edi = (edi + (u32)(2));  // @186_626f60
  if (edi == esi) goto L62724a;  // @187_626f60
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; })) & 0xff);  // @188_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @189_626f60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L6271ee;  // @190_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx + 76), sizeof v); (u32)v; });  // @191_626f60
  goto L6271f8;  // @192_626f60
  L6271ee:;
  p15_ = eax;  // @194_626f60
  p16_ = ecx;  // @195_626f60
  eax = ext_62c640_cdecl2((u32)(p16_), (u32)(p15_));  // @196_626f60
  ecx = edx = 0;  // @197_626f60
  L6271f8:;
  eax = (eax - (u32)(5));  // @199_626f60
  if (eax > (u32)(24)) goto L62706a;  // @200_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6452228), sizeof v); (u32)v; });  // @201_626f60
  switch (eax) { case 0: goto L6272a9; case 1: goto L6272c0; case 2: goto L6272d7; case 3: goto L6271d6; case 4: goto L627295; case 5: goto L627267; case 6: goto L62723f; case 7: goto L627212; case 8: goto L62706a; default: __builtin_trap(); }  // @202_626f60
  L627212:;
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @204_626f60
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @205_626f60
  L627219:;
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @207_626f60
  L627220:;
  eax = ecx;  // @209_626f60
  ecx = (ecx & (u32)(31));  // @210_626f60
  eax = (eax >> (u32)(5));  // @211_626f60
  edx = (u32)(eax + edx*8);  // @212_626f60
  eax = (u32)(1);  // @213_626f60
  eax = (eax << (ecx & 0xff));  // @214_626f60
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L62706a;  // @215_626f60
  L62723f:;
  edi = (edi + (u32)(2));  // @217_626f60
  if (edi != esi) goto L626f80;  // @218_626f60
  L62724a:;
  eax = (eax | (u32)(4294967295));  // @220_626f60
  return eax;  // @221_626f60
  L627254:;
  if (eax != 0) goto L62725e;  // @223_626f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @224_626f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @225_626f60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @226_626f60
  L62725e:;
  eax = edx;  // @228_626f60
  return eax;  // @229_626f60
  L627267:;
  edi = (edi + (u32)(2));  // @231_626f60
  if (edi == esi) goto L62724a;  // @232_626f60
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) != (u32)(0)) goto L62706a;  // @233_626f60
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; }) != (u32)(62)) goto L62706a;  // @234_626f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @235_626f60
  ecx = (u32)(edi + 2);  // @236_626f60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @237_626f60
  eax = (u32)(3);  // @238_626f60
  return eax;  // @239_626f60
  L627295:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @241_626f60
  edx = (u32)(edi + 2);  // @242_626f60
  eax = (u32)(1);  // @243_626f60
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @244_626f60
  return eax;  // @245_626f60
  L6272a9:;
  esi = (esi - edi);  // @247_626f60
  if ((s32)esi >= (s32)(u32)(2)) goto L62706a;  // @248_626f60
  L6272b4:;
  eax = (u32)(4294967294);  // @250_626f60
  return eax;  // @251_626f60
  L6272c0:;
  esi = (esi - edi);  // @253_626f60
  if ((s32)esi >= (s32)(u32)(3)) goto L62706a;  // @254_626f60
  eax = (u32)(4294967294);  // @255_626f60
  return eax;  // @256_626f60
  L6272d7:;
  esi = (esi - edi);  // @258_626f60
  if ((s32)esi >= (s32)(u32)(4)) goto L62706a;  // @259_626f60
  eax = (u32)(4294967294);  // @260_626f60
  return eax;  // @261_626f60
}
PCREG(626f60, lifted_626f60);

extern "C" u32 lifted_61c790(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = (u32)(EBP - 8);  // @0_61c790
  p0_ = esi;  // @1_61c790
  p1_ = edi;  // @2_61c790
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @3_61c790
  p2_ = eax;  // @4_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_61c790
  p3_ = edi;  // @6_61c790
  p4_ = eax;  // @7_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @8_61c790
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32))(eax))((u32)(p4_), (u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @9_61c790
  ecx = edx = 0;  // @10_61c790
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_61c790
  eax = (eax + (u32)(4));  // @12_61c790
  if (eax > (u32)(43)) goto L61ca36;  // @13_61c790
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @14_61c790
  L61c7c2:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6409020), sizeof v); (u32)v; });  // @16_61c790
  switch (eax) { case 0: goto L61cad0; case 1: goto L61c881; case 2: goto L61caf9; case 3: goto L61cad9; case 4: goto L61c85c; case 5: goto L61c88c; case 6: goto L61c8cd; case 7: goto L61c7d0; case 8: goto L61ca36; default: __builtin_trap(); }  // @17_61c790
  L61c7d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @19_61c790
  p5_ = edi;  // @20_61c790
  p6_ = eax;  // @21_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @22_61c790
  eax = ((u32(STDCALL *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @23_61c790
  ecx = edx = 0;  // @24_61c790
  ecx = eax;  // @25_61c790
  if ((s32)(ecx & ecx) < 0) goto L61ca53;  // @26_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @27_61c790
  if ((eax & eax) != 0) goto L61c80a;  // @28_61c790
  if (ecx != (u32)(32)) goto L61c80a;  // @29_61c790
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @30_61c790
  eax = edx;  // @31_61c790
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @32_61c790
  if (eax == 0) goto L61ca13;  // @33_61c790
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx - 1), sizeof v); (u32)v; }) == (ecx & 0xff)) goto L61ca13;  // @34_61c790
  L61c80a:;
  eax = (u32)(EBP - 12);  // @36_61c790
  p7_ = eax;  // @37_61c790
  p8_ = ecx;  // @38_61c790
  eax = ext_626e10_cdecl2((u32)(p8_), (u32)(p7_));  // @39_61c790
  ecx = edx = 0;  // @40_61c790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @41_61c790
  if ((eax & eax) == 0) goto L61ca53;  // @42_61c790
  edi = 0;  // @43_61c790
  if ((s32)(eax & eax) <= 0) goto L61ca13;  // @44_61c790
  L61c830:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @46_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L61c845;  // @47_61c790
  p9_ = esi;  // @48_61c790
  eax = ext_6206e0_cdecl1((u32)(p9_));  // @49_61c790
  ecx = edx = 0;  // @50_61c790
  if ((eax & eax) == 0) goto L61c875;  // @51_61c790
  L61c845:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @53_61c790
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi - 12), sizeof v); (u32)v; })) & 0xff);  // @54_61c790
  edi = (edi + 1);  // @55_61c790
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @56_61c790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @57_61c790
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; })) goto L61c830;  // @58_61c790
  goto L61ca13;  // @59_61c790
  L61c85c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @61_61c790
  p10_ = edi;  // @62_61c790
  p11_ = eax;  // @63_61c790
  p12_ = esi;  // @64_61c790
  eax = ext_620180_cdecl4((u32)(p12_), (u32)(p11_), (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }));  // @65_61c790
  ecx = edx = 0;  // @66_61c790
  if ((eax & eax) != 0) goto L61ca13;  // @67_61c790
  L61c875:;
  eax = (u32)(1);  // @69_61c790
  return eax;  // @70_61c790
  L61c881:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @72_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @73_61c790
  eax = (eax + edi);  // @74_61c790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @75_61c790
  L61c88c:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }) != (u32)(0)) goto L61c8aa;  // @77_61c790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @78_61c790
  eax = ecx;  // @79_61c790
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @80_61c790
  if (eax == 0) goto L61ca13;  // @81_61c790
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 1), sizeof v); (u32)v; }) == (u32)(32)) goto L61ca13;  // @82_61c790
  L61c8aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @84_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L61c8bf;  // @85_61c790
  p13_ = esi;  // @86_61c790
  eax = ext_6206e0_cdecl1((u32)(p13_));  // @87_61c790
  ecx = edx = 0;  // @88_61c790
  if ((eax & eax) == 0) goto L61c875;  // @89_61c790
  L61c8bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @91_61c790
  { u8 v = (u8)((u32)(32)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @92_61c790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @93_61c790
  goto L61ca13;  // @94_61c790
  L61c8cd:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @96_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @97_61c790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 68), sizeof v); (u32)v; });  // @98_61c790
  eax = (eax - ecx);  // @99_61c790
  p14_ = eax;  // @100_61c790
  eax = (u32)(ecx + edi);  // @101_61c790
  p15_ = eax;  // @102_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 48), sizeof v); (u32)v; });  // @103_61c790
  p16_ = edx;  // @104_61c790
  eax = ((u32( *)(u32, u32, u32))(eax))((u32)(p16_), (u32)(p15_), (u32)(p14_));  // @105_61c790
  ecx = edx = 0;  // @106_61c790
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @107_61c790
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L61c916;  // @108_61c790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @109_61c790
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L61c906;  // @110_61c790
  p17_ = esi;  // @111_61c790
  eax = ext_6206e0_cdecl1((u32)(p17_));  // @112_61c790
  ecx = edx = 0;  // @113_61c790
  if ((eax & eax) == 0) goto L61c875;  // @114_61c790
  L61c906:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @116_61c790
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @117_61c790
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @118_61c790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @119_61c790
  goto L61ca13;  // @120_61c790
  L61c916:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @122_61c790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @123_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 68), sizeof v); (u32)v; });  // @124_61c790
  ecx = (ecx - eax);  // @125_61c790
  p18_ = ecx;  // @126_61c790
  eax = (eax + edi);  // @127_61c790
  p19_ = eax;  // @128_61c790
  p20_ = edx;  // @129_61c790
  eax = (u32)(ebx + 580);  // @130_61c790
  p21_ = eax;  // @131_61c790
  eax = ext_620180_cdecl4((u32)(p21_), (u32)(p20_), (u32)(p19_), (u32)(p18_));  // @132_61c790
  ecx = edx = 0;  // @133_61c790
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @134_61c790
  if ((eax & eax) == 0) goto L61c875;  // @135_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 592), sizeof v); (u32)v; });  // @136_61c790
  ecx = (u32)(ebx + 580);  // @137_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; })) goto L61c968;  // @138_61c790
  p22_ = ecx;  // @139_61c790
  eax = ext_6206e0_cdecl1((u32)(p22_));  // @140_61c790
  ecx = edx = 0;  // @141_61c790
  if ((eax & eax) == 0) goto L61c875;  // @142_61c790
  ecx = (u32)(ebx + 580);  // @143_61c790
  L61c968:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @145_61c790
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @146_61c790
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @147_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @148_61c790
  if ((eax & eax) == 0) goto L61c875;  // @149_61c790
  p23_ = eax;  // @150_61c790
  eax = (u32)(ebx + 344);  // @151_61c790
  p24_ = eax;  // @152_61c790
  eax = ext_61fd60_cdecl3((u32)(p24_), (u32)(p23_), (u32)(0));  // @153_61c790
  ecx = edx = 0;  // @154_61c790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 596), sizeof v); (u32)v; });  // @155_61c790
  edx = eax;  // @156_61c790
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @157_61c790
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 592), &v, sizeof v); }  // @158_61c790
  if ((edx & edx) != 0) goto L61c9c8;  // @159_61c790
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 448), sizeof v); (u32)v; }) == eax) goto L61ca13;  // @160_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @161_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61c9bc;  // @162_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @163_61c790
  L61c9bc:;
  eax = (u32)(11);  // @165_61c790
  return eax;  // @166_61c790
  L61c9c8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L61cab3;  // @168_61c790
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L61ca96;  // @169_61c790
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @170_61c790
  if ((ecx & ecx) == 0) goto L61ca79;  // @171_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @172_61c790
  p25_ = esi;  // @173_61c790
  eax = (eax + ecx);  // @174_61c790
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + 28), &v, sizeof v); }  // @175_61c790
  p26_ = eax;  // @176_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @177_61c790
  p27_ = ecx;  // @178_61c790
  p28_ = eax;  // @179_61c790
  p29_ = ebx;  // @180_61c790
  eax = ext_61c790_cdecl6((u32)(p29_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 224), sizeof v); (u32)v; }), (u32)(p28_), (u32)(p27_), (u32)(p26_), (u32)(p25_));  // @181_61c790
  ecx = edx = 0;  // @182_61c790
  ecx = eax;  // @183_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @184_61c790
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @185_61c790
  if ((ecx & ecx) != 0) goto L61ca70;  // @186_61c790
  L61ca13:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @188_61c790
  eax = (u32)(EBP - 8);  // @189_61c790
  p30_ = eax;  // @190_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @191_61c790
  p31_ = edi;  // @192_61c790
  p32_ = eax;  // @193_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @194_61c790
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(p32_), (u32)(p31_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), (u32)(p30_));  // @195_61c790
  ecx = edx = 0;  // @196_61c790
  eax = (eax + (u32)(4));  // @197_61c790
  if (eax <= (u32)(43)) goto L61c7c2;  // @198_61c790
  L61ca36:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @200_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61ca47;  // @201_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @202_61c790
  L61ca47:;
  eax = (u32)(23);  // @204_61c790
  return eax;  // @205_61c790
  L61ca53:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @207_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61ca64;  // @208_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @209_61c790
  L61ca64:;
  eax = (u32)(14);  // @211_61c790
  return eax;  // @212_61c790
  L61ca70:;
  eax = ecx;  // @214_61c790
  return eax;  // @215_61c790
  L61ca79:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @217_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61ca8a;  // @218_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @219_61c790
  L61ca8a:;
  eax = (u32)(16);  // @221_61c790
  return eax;  // @222_61c790
  L61ca96:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @224_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61caa7;  // @225_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @226_61c790
  L61caa7:;
  eax = (u32)(15);  // @228_61c790
  return eax;  // @229_61c790
  L61cab3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @231_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61cac4;  // @232_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @233_61c790
  L61cac4:;
  eax = (u32)(12);  // @235_61c790
  return eax;  // @236_61c790
  L61cad0:;
  eax = 0;  // @238_61c790
  return eax;  // @239_61c790
  L61cad9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @241_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61caed;  // @242_61c790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @243_61c790
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @244_61c790
  L61caed:;
  eax = (u32)(4);  // @246_61c790
  return eax;  // @247_61c790
  L61caf9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @249_61c790
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 140), sizeof v); (u32)v; })) goto L61cb0a;  // @250_61c790
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 280), &v, sizeof v); }  // @251_61c790
  L61cb0a:;
  eax = (u32)(4);  // @253_61c790
  return eax;  // @254_61c790
}
PCREG(61c790, lifted_61c790);

extern "C" u32 lifted_62b450(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_, p37_, p38_, p39_, p40_, p41_, p42_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62b450
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_62b450
  if (esi != edi) goto L62b466;  // @2_62b450
  eax = (eax | (u32)(4294967295));  // @3_62b450
  return eax;  // @4_62b450
  L62b466:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_62b450
  p0_ = ebx;  // @7_62b450
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @9_62b450
  eax = (eax + (u32)(-5));  // @10_62b450
  if (eax > (u32)(24)) goto L62b7f6;  // @11_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6469672), sizeof v); (u32)v; });  // @12_62b450
  switch (eax) { case 0: goto L62b493; case 1: goto L62b4bc; case 2: goto L62b4e5; case 3: goto L62b7ca; case 4: goto L62b782; case 5: goto L62b7e0; case 6: goto L62b48c; case 7: goto L62b7f6; case 8: goto L62b7f6; default: __builtin_trap(); }  // @13_62b450
  L62b48c:;
  eax = (u32)(1);  // @15_62b450
  goto L62b50c;  // @16_62b450
  L62b493:;
  eax = edi;  // @18_62b450
  eax = (eax - esi);  // @19_62b450
  if ((s32)eax < (s32)(u32)(2)) goto L62b714;  // @20_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 344), sizeof v); (u32)v; });  // @21_62b450
  p1_ = esi;  // @22_62b450
  p2_ = ebx;  // @23_62b450
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(p2_), (u32)(p1_), (u32)(p0_));  // @24_62b450
  ecx = edx = 0;  // @25_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @26_62b450
  eax = (u32)(2);  // @27_62b450
  goto L62b50c;  // @28_62b450
  L62b4bc:;
  eax = edi;  // @30_62b450
  eax = (eax - esi);  // @31_62b450
  if ((s32)eax < (s32)(u32)(3)) goto L62b714;  // @32_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 348), sizeof v); (u32)v; });  // @33_62b450
  p3_ = esi;  // @34_62b450
  p4_ = ebx;  // @35_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p4_), (u32)(p3_));  // @36_62b450
  ecx = edx = 0;  // @37_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @38_62b450
  eax = (u32)(3);  // @39_62b450
  goto L62b50c;  // @40_62b450
  L62b4e5:;
  eax = edi;  // @42_62b450
  eax = (eax - esi);  // @43_62b450
  if ((s32)eax < (s32)(u32)(4)) goto L62b714;  // @44_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 352), sizeof v); (u32)v; });  // @45_62b450
  p5_ = esi;  // @46_62b450
  p6_ = ebx;  // @47_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p6_), (u32)(p5_));  // @48_62b450
  ecx = edx = 0;  // @49_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @50_62b450
  eax = (u32)(4);  // @51_62b450
  L62b50c:;
  esi = (esi + eax);  // @53_62b450
  ecx = 0;  // @54_62b450
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @55_62b450
  if (esi == edi) goto L62b787;  // @56_62b450
  edi = (edi - esi);  // @57_62b450
  L62b520:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @60_62b450
  eax = (eax + (u32)(-5));  // @61_62b450
  if (eax > (u32)(24)) goto L62b7f6;  // @62_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6469740), sizeof v); (u32)v; });  // @63_62b450
  switch (eax) { case 0: goto L62b542; case 1: goto L62b56b; case 2: goto L62b594; case 3: goto L62b646; case 4: goto L62b74d; case 5: goto L62b75f; case 6: goto L62b5e2; case 7: goto L62b5a5; case 8: goto L62b7f6; case 9: goto L62b7f6; default: __builtin_trap(); }  // @64_62b450
  L62b542:;
  if ((s32)edi < (s32)(u32)(2)) goto L62b714;  // @66_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @67_62b450
  L62b551:;
  p7_ = esi;  // @69_62b450
  p8_ = ebx;  // @70_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p8_), (u32)(p7_));  // @71_62b450
  ecx = edx = 0;  // @72_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @73_62b450
  esi = (esi + (u32)(2));  // @74_62b450
  edi = (edi - (u32)(2));  // @75_62b450
  goto L62b632;  // @76_62b450
  L62b56b:;
  if ((s32)edi < (s32)(u32)(3)) goto L62b714;  // @78_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 336), sizeof v); (u32)v; });  // @79_62b450
  L62b57a:;
  p9_ = esi;  // @81_62b450
  p10_ = ebx;  // @82_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p10_), (u32)(p9_));  // @83_62b450
  ecx = edx = 0;  // @84_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @85_62b450
  esi = (esi + (u32)(3));  // @86_62b450
  edi = (edi - (u32)(3));  // @87_62b450
  goto L62b632;  // @88_62b450
  L62b594:;
  if ((s32)edi < (s32)(u32)(4)) goto L62b714;  // @90_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 340), sizeof v); (u32)v; });  // @91_62b450
  goto L62b61d;  // @92_62b450
  L62b5a5:;
  if ((ecx & ecx) != 0) goto L62b7f6;  // @94_62b450
  esi = (esi + 1);  // @95_62b450
  ecx = (u32)(1);  // @96_62b450
  edi = (edi - 1);  // @97_62b450
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @98_62b450
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L62b787;  // @99_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @101_62b450
  eax = (eax + (u32)(-5));  // @102_62b450
  if (eax > (u32)(24)) goto L62b7f6;  // @103_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6469792), sizeof v); (u32)v; });  // @104_62b450
  switch (eax) { case 0: goto L62b5e6; case 1: goto L62b5fa; case 2: goto L62b60e; case 3: goto L62b5e2; case 4: goto L62b7f6; case 5: goto L62b7f6; default: __builtin_trap(); }  // @105_62b450
  L62b5e2:;
  esi = (esi + 1);  // @107_62b450
  edi = (edi - 1);  // @108_62b450
  goto L62b635;  // @109_62b450
  L62b5e6:;
  if ((s32)edi < (s32)(u32)(2)) goto L62b714;  // @111_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 344), sizeof v); (u32)v; });  // @112_62b450
  goto L62b551;  // @113_62b450
  L62b5fa:;
  if ((s32)edi < (s32)(u32)(3)) goto L62b714;  // @115_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 348), sizeof v); (u32)v; });  // @116_62b450
  goto L62b57a;  // @117_62b450
  L62b60e:;
  if ((s32)edi < (s32)(u32)(4)) goto L62b714;  // @119_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 352), sizeof v); (u32)v; });  // @120_62b450
  L62b61d:;
  p11_ = esi;  // @122_62b450
  p12_ = ebx;  // @123_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p12_), (u32)(p11_));  // @124_62b450
  ecx = edx = 0;  // @125_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @126_62b450
  esi = (esi + (u32)(4));  // @127_62b450
  edi = (edi - (u32)(4));  // @128_62b450
  L62b632:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @130_62b450
  L62b635:;
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L62b520;  // @132_62b450
  eax = (eax | (u32)(4294967295));  // @133_62b450
  return eax;  // @134_62b450
  L62b646:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @136_62b450
  esi = (esi + 1);  // @137_62b450
  if (esi == edi) goto L62b787;  // @138_62b450
  L62b652:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @141_62b450
  eax = (eax + (u32)(-5));  // @142_62b450
  if (eax > (u32)(24)) goto L62b7f6;  // @143_62b450
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6469856), sizeof v); (u32)v; });  // @144_62b450
  switch (eax) { case 0: goto L62b69b; case 1: goto L62b6d3; case 2: goto L62b70b; case 3: goto L62b674; case 4: goto L62b74d; case 5: goto L62b762; case 6: goto L62b681; case 7: goto L62b7f6; case 8: goto L62b7f6; default: __builtin_trap(); }  // @145_62b450
  L62b674:;
  esi = (esi + 1);  // @147_62b450
  if (esi != edi) goto L62b652;  // @148_62b450
  eax = (eax | (u32)(4294967295));  // @149_62b450
  return eax;  // @150_62b450
  L62b681:;
  eax = (u32)(1);  // @152_62b450
  p13_ = edi;  // @153_62b450
  eax = (eax + esi);  // @154_62b450
  p14_ = eax;  // @155_62b450
  p15_ = ebx;  // @156_62b450
  eax = ext_62a8e0_cdecl4((u32)(p15_), (u32)(p14_), (u32)(p13_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @157_62b450
  ecx = edx = 0;  // @158_62b450
  return eax;  // @159_62b450
  L62b69b:;
  eax = edi;  // @161_62b450
  eax = (eax - esi);  // @162_62b450
  if ((s32)eax < (s32)(u32)(2)) goto L62b714;  // @163_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 344), sizeof v); (u32)v; });  // @164_62b450
  p16_ = esi;  // @165_62b450
  p17_ = ebx;  // @166_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p17_), (u32)(p16_));  // @167_62b450
  ecx = edx = 0;  // @168_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @169_62b450
  eax = (u32)(2);  // @170_62b450
  p18_ = edi;  // @171_62b450
  eax = (eax + esi);  // @172_62b450
  p19_ = eax;  // @173_62b450
  p20_ = ebx;  // @174_62b450
  eax = ext_62a8e0_cdecl4((u32)(p20_), (u32)(p19_), (u32)(p18_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @175_62b450
  ecx = edx = 0;  // @176_62b450
  return eax;  // @177_62b450
  L62b6d3:;
  eax = edi;  // @179_62b450
  eax = (eax - esi);  // @180_62b450
  if ((s32)eax < (s32)(u32)(3)) goto L62b714;  // @181_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 348), sizeof v); (u32)v; });  // @182_62b450
  p21_ = esi;  // @183_62b450
  p22_ = ebx;  // @184_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p22_), (u32)(p21_));  // @185_62b450
  ecx = edx = 0;  // @186_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @187_62b450
  eax = (u32)(3);  // @188_62b450
  p23_ = edi;  // @189_62b450
  eax = (eax + esi);  // @190_62b450
  p24_ = eax;  // @191_62b450
  p25_ = ebx;  // @192_62b450
  eax = ext_62a8e0_cdecl4((u32)(p25_), (u32)(p24_), (u32)(p23_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @193_62b450
  ecx = edx = 0;  // @194_62b450
  return eax;  // @195_62b450
  L62b70b:;
  eax = edi;  // @197_62b450
  eax = (eax - esi);  // @198_62b450
  if ((s32)eax >= (s32)(u32)(4)) goto L62b71e;  // @199_62b450
  L62b714:;
  eax = (u32)(4294967294);  // @201_62b450
  return eax;  // @202_62b450
  L62b71e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 352), sizeof v); (u32)v; });  // @204_62b450
  p26_ = esi;  // @205_62b450
  p27_ = ebx;  // @206_62b450
  eax = ((u32( *)(u32, u32))(eax))((u32)(p27_), (u32)(p26_));  // @207_62b450
  ecx = edx = 0;  // @208_62b450
  if ((eax & eax) == 0) goto L62b7f6;  // @209_62b450
  eax = (u32)(4);  // @210_62b450
  p28_ = edi;  // @211_62b450
  eax = (eax + esi);  // @212_62b450
  p29_ = eax;  // @213_62b450
  p30_ = ebx;  // @214_62b450
  eax = ext_62a8e0_cdecl4((u32)(p30_), (u32)(p29_), (u32)(p28_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @215_62b450
  ecx = edx = 0;  // @216_62b450
  return eax;  // @217_62b450
  L62b74d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @219_62b450
  ecx = (u32)(esi + 1);  // @220_62b450
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @221_62b450
  eax = (u32)(2);  // @222_62b450
  return eax;  // @223_62b450
  L62b75f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @225_62b450
  L62b762:;
  esi = (esi + 1);  // @227_62b450
  if (esi == edi) goto L62b787;  // @228_62b450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @229_62b450
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(62)) goto L62b7f9;  // @230_62b450
  ecx = (u32)(esi + 1);  // @231_62b450
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @232_62b450
  eax = (u32)(4);  // @233_62b450
  return eax;  // @234_62b450
  L62b782:;
  esi = (esi + 1);  // @236_62b450
  if (esi != edi) goto L62b78f;  // @237_62b450
  L62b787:;
  eax = (eax | (u32)(4294967295));  // @239_62b450
  return eax;  // @240_62b450
  L62b78f:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_62b450
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; })) & 0xff);  // @243_62b450
  if ((eax & 0xff) == (u32)(20)) goto L62b7b4;  // @244_62b450
  if ((eax & 0xff) != (u32)(27)) goto L62b7f6;  // @245_62b450
  eax = (u32)(esi + 1);  // @246_62b450
  p31_ = edi;  // @247_62b450
  p32_ = eax;  // @248_62b450
  p33_ = ebx;  // @249_62b450
  eax = ext_62add0_cdecl4((u32)(p33_), (u32)(p32_), (u32)(p31_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @250_62b450
  ecx = edx = 0;  // @251_62b450
  return eax;  // @252_62b450
  L62b7b4:;
  eax = (u32)(esi + 1);  // @254_62b450
  p34_ = edi;  // @255_62b450
  p35_ = eax;  // @256_62b450
  p36_ = ebx;  // @257_62b450
  eax = ext_62ad10_cdecl4((u32)(p36_), (u32)(p35_), (u32)(p34_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @258_62b450
  ecx = edx = 0;  // @259_62b450
  return eax;  // @260_62b450
  L62b7ca:;
  eax = (u32)(esi + 1);  // @262_62b450
  p37_ = edi;  // @263_62b450
  p38_ = eax;  // @264_62b450
  p39_ = ebx;  // @265_62b450
  eax = ext_62bb10_cdecl4((u32)(p39_), (u32)(p38_), (u32)(p37_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @266_62b450
  ecx = edx = 0;  // @267_62b450
  return eax;  // @268_62b450
  L62b7e0:;
  eax = (u32)(esi + 1);  // @270_62b450
  p40_ = edi;  // @271_62b450
  p41_ = eax;  // @272_62b450
  p42_ = ebx;  // @273_62b450
  eax = ext_62b040_cdecl4((u32)(p42_), (u32)(p41_), (u32)(p40_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @274_62b450
  ecx = edx = 0;  // @275_62b450
  return eax;  // @276_62b450
  L62b7f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @278_62b450
  L62b7f9:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @280_62b450
  eax = 0;  // @281_62b450
  return eax;  // @282_62b450
}
PCREG(62b450, lifted_62b450);

extern "C" u32 lifted_624ca0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_, p32_, p33_, p34_, p35_, p36_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_624ca0
  ecx = esi;  // @1_624ca0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_624ca0
  if (esi != edi) goto L624cba;  // @3_624ca0
  eax = (u32)(4294967292);  // @4_624ca0
  return eax;  // @5_624ca0
  L624cba:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_624ca0
  p0_ = ebx;  // @8_624ca0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @10_624ca0
  eax = (eax + (u32)(-2));  // @11_624ca0
  if (eax > (u32)(34)) goto L625132;  // @12_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6443412), sizeof v); (u32)v; });  // @13_624ca0
  switch (eax) { case 0: goto L624d10; case 1: goto L624dfc; case 2: goto L624f07; case 3: goto L624f4f; case 4: goto L624f8d; case 5: goto L624d76; case 6: goto L624d87; case 7: goto L624edf; case 8: goto L624ce0; case 9: goto L624cf8; case 10: goto L624ef1; case 11: goto L624dea; case 12: goto L624fd5; case 13: goto L624fdd; case 14: goto L625132; case 15: goto L624dc2; case 16: goto L624e45; case 17: goto L624e57; case 18: goto L624dd8; case 19: goto L624ecd; case 20: goto L625132; default: __builtin_trap(); }  // @14_624ca0
  L624ce0:;
  eax = (u32)(esi + 1);  // @16_624ca0
  p1_ = edi;  // @17_624ca0
  p2_ = eax;  // @18_624ca0
  p3_ = ebx;  // @19_624ca0
  eax = ext_62b2f0_cdecl6((u32)(12), (u32)(p3_), (u32)(p2_), (u32)(p1_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(p0_));  // @20_624ca0
  ecx = edx = 0;  // @21_624ca0
  return eax;  // @22_624ca0
  L624cf8:;
  eax = (u32)(esi + 1);  // @24_624ca0
  p4_ = edi;  // @25_624ca0
  p5_ = eax;  // @26_624ca0
  p6_ = ebx;  // @27_624ca0
  eax = ext_62b2f0_cdecl5((u32)(13), (u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @28_624ca0
  ecx = edx = 0;  // @29_624ca0
  return eax;  // @30_624ca0
  L624d10:;
  esi = (esi + 1);  // @32_624ca0
  if (esi == edi) goto L624e17;  // @33_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @35_624ca0
  eax = (eax + (u32)(-5));  // @36_624ca0
  if (eax > (u32)(24)) goto L625132;  // @37_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6443464), sizeof v); (u32)v; });  // @38_624ca0
  switch (eax) { case 0: goto L624d67; case 1: goto L624d51; case 2: goto L624d3b; case 3: goto L625132; default: __builtin_trap(); }  // @39_624ca0
  L624d3b:;
  eax = (u32)(esi + 1);  // @41_624ca0
  p7_ = edi;  // @42_624ca0
  p8_ = eax;  // @43_624ca0
  p9_ = ebx;  // @44_624ca0
  eax = ext_62af10_cdecl4((u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @45_624ca0
  ecx = edx = 0;  // @46_624ca0
  return eax;  // @47_624ca0
  L624d51:;
  eax = (u32)(esi + 1);  // @49_624ca0
  p10_ = edi;  // @50_624ca0
  p11_ = eax;  // @51_624ca0
  p12_ = ebx;  // @52_624ca0
  eax = ext_62bb10_cdecl4((u32)(p12_), (u32)(p11_), (u32)(p10_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @53_624ca0
  ecx = edx = 0;  // @54_624ca0
  return eax;  // @55_624ca0
  L624d67:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @57_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @58_624ca0
  eax = (u32)(29);  // @59_624ca0
  return eax;  // @60_624ca0
  L624d76:;
  eax = (u32)(esi + 1);  // @62_624ca0
  if (eax != edi) goto L624d87;  // @63_624ca0
  eax = (u32)(4294967281);  // @64_624ca0
  return eax;  // @65_624ca0
  L624d87:;
  esi = (esi + 1);  // @67_624ca0
  if (esi == edi) goto L624db3;  // @68_624ca0
  ecx = (u32)(esi + 1);  // @69_624ca0
  L624d90:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @72_624ca0
  eax = (eax - (u32)(9));  // @73_624ca0
  if (eax == 0) goto L624da9;  // @74_624ca0
  eax = (eax - (u32)(1));  // @75_624ca0
  if (eax == 0) goto L624dad;  // @76_624ca0
  eax = (eax - (u32)(11));  // @77_624ca0
  if (eax != 0) goto L624db3;  // @78_624ca0
  goto L624dad;  // @79_624ca0
  L624da9:;
  if (ecx == edi) goto L624db3;  // @81_624ca0
  L624dad:;
  esi = (esi + 1);  // @83_624ca0
  ecx = (ecx + 1);  // @84_624ca0
  if (esi != edi) goto L624d90;  // @85_624ca0
  L624db3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @87_624ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @88_624ca0
  eax = (u32)(15);  // @89_624ca0
  return eax;  // @90_624ca0
  L624dc2:;
  eax = (u32)(esi + 1);  // @92_624ca0
  p13_ = edi;  // @93_624ca0
  p14_ = eax;  // @94_624ca0
  p15_ = ebx;  // @95_624ca0
  eax = ext_62b900_cdecl4((u32)(p15_), (u32)(p14_), (u32)(p13_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @96_624ca0
  ecx = edx = 0;  // @97_624ca0
  return eax;  // @98_624ca0
  L624dd8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @100_624ca0
  ecx = (u32)(esi + 1);  // @101_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @102_624ca0
  eax = (u32)(38);  // @103_624ca0
  return eax;  // @104_624ca0
  L624dea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @106_624ca0
  ecx = (u32)(esi + 1);  // @107_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @108_624ca0
  eax = (u32)(25);  // @109_624ca0
  return eax;  // @110_624ca0
  L624dfc:;
  esi = (esi + 1);  // @112_624ca0
  if (esi != edi) goto L624e0b;  // @113_624ca0
  eax = (u32)(4294967270);  // @114_624ca0
  return eax;  // @115_624ca0
  L624e0b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(93)) goto L624e36;  // @117_624ca0
  eax = (u32)(esi + 1);  // @118_624ca0
  if (eax != edi) goto L624e1f;  // @119_624ca0
  L624e17:;
  eax = (eax | (u32)(4294967295));  // @121_624ca0
  return eax;  // @122_624ca0
  L624e1f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(62)) goto L624e36;  // @124_624ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @125_624ca0
  ecx = (u32)(esi + 2);  // @126_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @127_624ca0
  eax = (u32)(34);  // @128_624ca0
  return eax;  // @129_624ca0
  L624e36:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @131_624ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @132_624ca0
  eax = (u32)(26);  // @133_624ca0
  return eax;  // @134_624ca0
  L624e45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @136_624ca0
  ecx = (u32)(esi + 1);  // @137_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @138_624ca0
  eax = (u32)(23);  // @139_624ca0
  return eax;  // @140_624ca0
  L624e57:;
  esi = (esi + 1);  // @142_624ca0
  if (esi != edi) goto L624e66;  // @143_624ca0
  eax = (u32)(4294967272);  // @144_624ca0
  return eax;  // @145_624ca0
  L624e66:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @147_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @148_624ca0
  eax = (eax + (u32)(-9));  // @149_624ca0
  if (eax > (u32)(27)) goto L625132;  // @150_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6443512), sizeof v); (u32)v; });  // @151_624ca0
  switch (eax) { case 0: goto L624ebe; case 1: goto L624e9a; case 2: goto L624e88; case 3: goto L624eac; case 4: goto L625132; default: __builtin_trap(); }  // @152_624ca0
  L624e88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @154_624ca0
  ecx = (u32)(esi + 1);  // @155_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @156_624ca0
  eax = (u32)(36);  // @157_624ca0
  return eax;  // @158_624ca0
  L624e9a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @160_624ca0
  ecx = (u32)(esi + 1);  // @161_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @162_624ca0
  eax = (u32)(35);  // @163_624ca0
  return eax;  // @164_624ca0
  L624eac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @166_624ca0
  ecx = (u32)(esi + 1);  // @167_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @168_624ca0
  eax = (u32)(37);  // @169_624ca0
  return eax;  // @170_624ca0
  L624ebe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @172_624ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @173_624ca0
  eax = (u32)(24);  // @174_624ca0
  return eax;  // @175_624ca0
  L624ecd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @177_624ca0
  ecx = (u32)(esi + 1);  // @178_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @179_624ca0
  eax = (u32)(21);  // @180_624ca0
  return eax;  // @181_624ca0
  L624edf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @183_624ca0
  ecx = (u32)(esi + 1);  // @184_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @185_624ca0
  eax = (u32)(17);  // @186_624ca0
  return eax;  // @187_624ca0
  L624ef1:;
  eax = (u32)(esi + 1);  // @189_624ca0
  p16_ = edi;  // @190_624ca0
  p17_ = eax;  // @191_624ca0
  p18_ = ebx;  // @192_624ca0
  eax = ext_62be60_cdecl4((u32)(p18_), (u32)(p17_), (u32)(p16_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @193_624ca0
  ecx = edx = 0;  // @194_624ca0
  return eax;  // @195_624ca0
  L624f07:;
  eax = edi;  // @197_624ca0
  eax = (eax - esi);  // @198_624ca0
  if ((s32)eax < (s32)(u32)(2)) goto L624f96;  // @199_624ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 344), sizeof v); (u32)v; });  // @200_624ca0
  p19_ = esi;  // @201_624ca0
  p20_ = ebx;  // @202_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p20_), (u32)(p19_));  // @203_624ca0
  ecx = edx = 0;  // @204_624ca0
  if ((eax & eax) == 0) goto L624f32;  // @205_624ca0
  esi = (esi + (u32)(2));  // @206_624ca0
  edx = (u32)(18);  // @207_624ca0
  goto L624fe3;  // @208_624ca0
  L624f32:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @210_624ca0
  p21_ = esi;  // @211_624ca0
  p22_ = ebx;  // @212_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p22_), (u32)(p21_));  // @213_624ca0
  ecx = edx = 0;  // @214_624ca0
  if ((eax & eax) == 0) goto L625132;  // @215_624ca0
  esi = (esi + (u32)(2));  // @216_624ca0
  goto L624fde;  // @217_624ca0
  L624f4f:;
  eax = edi;  // @219_624ca0
  eax = (eax - esi);  // @220_624ca0
  if ((s32)eax < (s32)(u32)(3)) goto L624f96;  // @221_624ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 348), sizeof v); (u32)v; });  // @222_624ca0
  p23_ = esi;  // @223_624ca0
  p24_ = ebx;  // @224_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p24_), (u32)(p23_));  // @225_624ca0
  ecx = edx = 0;  // @226_624ca0
  if ((eax & eax) == 0) goto L624f73;  // @227_624ca0
  esi = (esi + (u32)(3));  // @228_624ca0
  edx = (u32)(18);  // @229_624ca0
  goto L624fe3;  // @230_624ca0
  L624f73:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 336), sizeof v); (u32)v; });  // @232_624ca0
  p25_ = esi;  // @233_624ca0
  p26_ = ebx;  // @234_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p26_), (u32)(p25_));  // @235_624ca0
  ecx = edx = 0;  // @236_624ca0
  if ((eax & eax) == 0) goto L625132;  // @237_624ca0
  esi = (esi + (u32)(3));  // @238_624ca0
  goto L624fde;  // @239_624ca0
  L624f8d:;
  eax = edi;  // @241_624ca0
  eax = (eax - esi);  // @242_624ca0
  if ((s32)eax >= (s32)(u32)(4)) goto L624fa0;  // @243_624ca0
  L624f96:;
  eax = (u32)(4294967294);  // @245_624ca0
  return eax;  // @246_624ca0
  L624fa0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 352), sizeof v); (u32)v; });  // @248_624ca0
  p27_ = esi;  // @249_624ca0
  p28_ = ebx;  // @250_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p28_), (u32)(p27_));  // @251_624ca0
  ecx = edx = 0;  // @252_624ca0
  if ((eax & eax) == 0) goto L624fbb;  // @253_624ca0
  esi = (esi + (u32)(4));  // @254_624ca0
  edx = (u32)(18);  // @255_624ca0
  goto L624fe3;  // @256_624ca0
  L624fbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 340), sizeof v); (u32)v; });  // @258_624ca0
  p29_ = esi;  // @259_624ca0
  p30_ = ebx;  // @260_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p30_), (u32)(p29_));  // @261_624ca0
  ecx = edx = 0;  // @262_624ca0
  if ((eax & eax) == 0) goto L625132;  // @263_624ca0
  esi = (esi + (u32)(4));  // @264_624ca0
  goto L624fde;  // @265_624ca0
  L624fd5:;
  edx = (u32)(18);  // @267_624ca0
  esi = (esi + 1);  // @268_624ca0
  goto L624fe3;  // @269_624ca0
  L624fdd:;
  esi = (esi + 1);  // @271_624ca0
  L624fde:;
  edx = (u32)(19);  // @273_624ca0
  L624fe3:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @275_624ca0
  if (esi == edi) goto L625054;  // @276_624ca0
  edi = (edi - esi);  // @277_624ca0
  L624ff0:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @279_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @280_624ca0
  eax = (eax + (u32)(-5));  // @281_624ca0
  if (eax > (u32)(31)) goto L625132;  // @282_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6443584), sizeof v); (u32)v; });  // @283_624ca0
  switch (eax) { case 0: goto L625012; case 1: goto L625090; case 2: goto L6250b9; case 3: goto L6250e1; case 4: goto L62511b; case 5: goto L62508c; case 6: goto L62503b; case 7: goto L625132; case 8: goto L625104; case 9: goto L6250ed; case 10: goto L625132; default: __builtin_trap(); }  // @284_624ca0
  L625012:;
  if ((s32)edi < (s32)(u32)(2)) goto L624f96;  // @286_624ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @287_624ca0
  p31_ = esi;  // @288_624ca0
  p32_ = ebx;  // @289_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p32_), (u32)(p31_));  // @290_624ca0
  ecx = edx = 0;  // @291_624ca0
  if ((eax & eax) == 0) goto L625132;  // @292_624ca0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @293_624ca0
  esi = (esi + (u32)(2));  // @294_624ca0
  edi = (edi - (u32)(2));  // @295_624ca0
  goto L62504f;  // @296_624ca0
  L62503b:;
  esi = (esi + 1);  // @298_624ca0
  edi = (edi - 1);  // @299_624ca0
  if (edx == (u32)(18)) goto L62505d;  // @300_624ca0
  if (edx != (u32)(41)) goto L62504f;  // @301_624ca0
  L625047:;
  edx = (u32)(19);  // @303_624ca0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @304_624ca0
  L62504f:;
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L624ff0;  // @306_624ca0
  L625054:;
  edx = (0u - edx);  // @308_624ca0
  eax = edx;  // @309_624ca0
  return eax;  // @310_624ca0
  L62505d:;
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; })) goto L624e17;  // @312_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @313_624ca0
  edx = (u32)(41);  // @314_624ca0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @315_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx + 76), sizeof v); (u32)v; });  // @316_624ca0
  eax = (eax + (u32)(-5));  // @317_624ca0
  if (eax > (u32)(24)) goto L625047;  // @318_624ca0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6443640), sizeof v); (u32)v; });  // @319_624ca0
  switch (eax) { case 0: goto L625012; case 1: goto L625090; case 2: goto L6250b9; case 3: goto L62508c; case 4: goto L625132; case 5: goto L625047; default: __builtin_trap(); }  // @320_624ca0
  L62508c:;
  esi = (esi + 1);  // @322_624ca0
  edi = (edi - 1);  // @323_624ca0
  goto L62504f;  // @324_624ca0
  L625090:;
  if ((s32)edi < (s32)(u32)(3)) goto L624f96;  // @326_624ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 336), sizeof v); (u32)v; });  // @327_624ca0
  p33_ = esi;  // @328_624ca0
  p34_ = ebx;  // @329_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p34_), (u32)(p33_));  // @330_624ca0
  ecx = edx = 0;  // @331_624ca0
  if ((eax & eax) == 0) goto L625132;  // @332_624ca0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @333_624ca0
  esi = (esi + (u32)(3));  // @334_624ca0
  edi = (edi - (u32)(3));  // @335_624ca0
  goto L62504f;  // @336_624ca0
  L6250b9:;
  if ((s32)edi < (s32)(u32)(4)) goto L624f96;  // @338_624ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 340), sizeof v); (u32)v; });  // @339_624ca0
  p35_ = esi;  // @340_624ca0
  p36_ = ebx;  // @341_624ca0
  eax = ((u32( *)(u32, u32))(eax))((u32)(p36_), (u32)(p35_));  // @342_624ca0
  ecx = edx = 0;  // @343_624ca0
  if ((eax & eax) == 0) goto L625132;  // @344_624ca0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @345_624ca0
  esi = (esi + (u32)(4));  // @346_624ca0
  edi = (edi - (u32)(4));  // @347_624ca0
  goto L62504f;  // @348_624ca0
  L6250e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @350_624ca0
  eax = edx;  // @351_624ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @352_624ca0
  return eax;  // @353_624ca0
  L6250ed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @355_624ca0
  if (edx == (u32)(19)) goto L625135;  // @356_624ca0
  ecx = (u32)(esi + 1);  // @357_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @358_624ca0
  eax = (u32)(32);  // @359_624ca0
  return eax;  // @360_624ca0
  L625104:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @362_624ca0
  if (edx == (u32)(19)) goto L625135;  // @363_624ca0
  ecx = (u32)(esi + 1);  // @364_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @365_624ca0
  eax = (u32)(31);  // @366_624ca0
  return eax;  // @367_624ca0
  L62511b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @369_624ca0
  if (edx == (u32)(19)) goto L625135;  // @370_624ca0
  ecx = (u32)(esi + 1);  // @371_624ca0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @372_624ca0
  eax = (u32)(30);  // @373_624ca0
  return eax;  // @374_624ca0
  L625132:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @376_624ca0
  L625135:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @378_624ca0
  eax = 0;  // @379_624ca0
  return eax;  // @380_624ca0
}
PCREG(624ca0, lifted_624ca0);

extern "C" u32 THISCALL lifted_6232c0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6232c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @2_6232c0
  if (edx != edi) goto L6232d9;  // @3_6232c0
  eax = (u32)(4294967292);  // @4_6232c0
  return eax;  // @5_6232c0
  L6232d9:;
  eax = edi;  // @7_6232c0
  eax = (eax - edx);  // @8_6232c0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L6232ef;  // @9_6232c0
  eax = (eax & (u32)(4294967294));  // @10_6232c0
  if (eax != 0) goto L6232ec;  // @11_6232c0
  eax = (eax | (u32)(4294967295));  // @12_6232c0
  return eax;  // @13_6232c0
  L6232ec:;
  edi = (u32)(eax + edx);  // @15_6232c0
  L6232ef:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @17_6232c0
  p0_ = ebx;  // @18_6232c0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @19_6232c0
  p1_ = esi;  // @20_6232c0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L623307;  // @21_6232c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_6232c0
  eax = (ecx & 0xff);  // @23_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @24_6232c0
  goto L623314;  // @25_6232c0
  L623307:;
  p2_ = ecx;  // @27_6232c0
  p3_ = ebx;  // @28_6232c0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @29_6232c0
  ecx = edx = 0;  // @30_6232c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @31_6232c0
  L623314:;
  eax = (eax - (u32)(2));  // @33_6232c0
  if (eax > (u32)(34)) goto L623774;  // @34_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6436820), sizeof v); (u32)v; });  // @35_6232c0
  switch (eax) { case 0: goto L62335e; case 1: goto L623477; case 2: goto L6235a1; case 3: goto L6235b6; case 4: goto L6235cb; case 5: goto L6233dc; case 6: goto L6233ed; case 7: goto L623579; case 8: goto L62332e; case 9: goto L623346; case 10: goto L62358b; case 11: goto L623465; case 12: goto L623614; case 13: goto L623635; case 14: goto L6235e0; case 15: goto L62343d; case 16: goto L6234ca; case 17: goto L6234dc; case 18: goto L623453; case 19: goto L623567; case 20: goto L623774; default: __builtin_trap(); }  // @36_6232c0
  L62332e:;
  edx = (edx + (u32)(2));  // @38_6232c0
  p4_ = edi;  // @39_6232c0
  p5_ = edx;  // @40_6232c0
  p6_ = esi;  // @41_6232c0
  eax = ext_629ae0_cdecl5((u32)(12), (u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @42_6232c0
  ecx = edx = 0;  // @43_6232c0
  return eax;  // @44_6232c0
  L623346:;
  edx = (edx + (u32)(2));  // @46_6232c0
  p7_ = edi;  // @47_6232c0
  p8_ = edx;  // @48_6232c0
  p9_ = esi;  // @49_6232c0
  eax = ext_629ae0_cdecl5((u32)(13), (u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @50_6232c0
  ecx = edx = 0;  // @51_6232c0
  return eax;  // @52_6232c0
  L62335e:;
  edx = (edx + (u32)(2));  // @54_6232c0
  if (edx == edi) goto L623712;  // @55_6232c0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @56_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @57_6232c0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L62337a;  // @58_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @59_6232c0
  goto L623384;  // @60_6232c0
  L62337a:;
  p10_ = eax;  // @62_6232c0
  p11_ = ecx;  // @63_6232c0
  eax = ext_62c640_cdecl2((u32)(p11_), (u32)(p10_));  // @64_6232c0
  ecx = edx = 0;  // @65_6232c0
  L623384:;
  eax = (eax - (u32)(5));  // @67_6232c0
  if (eax > (u32)(24)) goto L623774;  // @68_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6436872), sizeof v); (u32)v; });  // @69_6232c0
  switch (eax) { case 0: goto L6233ca; case 1: goto L6233b4; case 2: goto L62339e; case 3: goto L623774; default: __builtin_trap(); }  // @70_6232c0
  L62339e:;
  edx = (edx + (u32)(2));  // @72_6232c0
  p12_ = edi;  // @73_6232c0
  p13_ = edx;  // @74_6232c0
  p14_ = esi;  // @75_6232c0
  eax = ext_6296a0_cdecl4((u32)(p14_), (u32)(p13_), (u32)(p12_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @76_6232c0
  ecx = edx = 0;  // @77_6232c0
  return eax;  // @78_6232c0
  L6233b4:;
  edx = (edx + (u32)(2));  // @80_6232c0
  p15_ = edi;  // @81_6232c0
  p16_ = edx;  // @82_6232c0
  p17_ = esi;  // @83_6232c0
  eax = ext_62a200_cdecl4((u32)(p17_), (u32)(p16_), (u32)(p15_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @84_6232c0
  ecx = edx = 0;  // @85_6232c0
  return eax;  // @86_6232c0
  L6233ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @88_6232c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @89_6232c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @90_6232c0
  eax = (u32)(29);  // @91_6232c0
  return eax;  // @92_6232c0
  L6233dc:;
  eax = (u32)(edx + 2);  // @94_6232c0
  if (eax != edi) goto L6233ed;  // @95_6232c0
  eax = (u32)(4294967281);  // @96_6232c0
  return eax;  // @97_6232c0
  L6233ed:;
  edx = (edx + (u32)(2));  // @99_6232c0
  if (edx == edi) goto L62342e;  // @100_6232c0
  L6233f4:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @102_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @103_6232c0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L623405;  // @104_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @105_6232c0
  goto L62340f;  // @106_6232c0
  L623405:;
  p18_ = eax;  // @108_6232c0
  p19_ = ecx;  // @109_6232c0
  eax = ext_62c640_cdecl2((u32)(p19_), (u32)(p18_));  // @110_6232c0
  ecx = edx = 0;  // @111_6232c0
  L62340f:;
  eax = (eax - (u32)(9));  // @113_6232c0
  if (eax == 0) goto L623420;  // @114_6232c0
  eax = (eax - (u32)(1));  // @115_6232c0
  if (eax == 0) goto L623427;  // @116_6232c0
  eax = (eax - (u32)(11));  // @117_6232c0
  if (eax != 0) goto L62342e;  // @118_6232c0
  goto L623427;  // @119_6232c0
  L623420:;
  eax = (u32)(edx + 2);  // @121_6232c0
  if (eax == edi) goto L62342e;  // @122_6232c0
  L623427:;
  edx = (edx + (u32)(2));  // @124_6232c0
  if (edx != edi) goto L6233f4;  // @125_6232c0
  L62342e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @127_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @128_6232c0
  eax = (u32)(15);  // @129_6232c0
  return eax;  // @130_6232c0
  L62343d:;
  edx = (edx + (u32)(2));  // @132_6232c0
  p20_ = edi;  // @133_6232c0
  p21_ = edx;  // @134_6232c0
  p22_ = esi;  // @135_6232c0
  eax = ext_62a030_cdecl4((u32)(p22_), (u32)(p21_), (u32)(p20_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @136_6232c0
  ecx = edx = 0;  // @137_6232c0
  return eax;  // @138_6232c0
  L623453:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @140_6232c0
  edx = (edx + (u32)(2));  // @141_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @142_6232c0
  eax = (u32)(38);  // @143_6232c0
  return eax;  // @144_6232c0
  L623465:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @146_6232c0
  edx = (edx + (u32)(2));  // @147_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @148_6232c0
  eax = (u32)(25);  // @149_6232c0
  return eax;  // @150_6232c0
  L623477:;
  edx = (edx + (u32)(2));  // @152_6232c0
  if (edx != edi) goto L623488;  // @153_6232c0
  eax = (u32)(4294967270);  // @154_6232c0
  return eax;  // @155_6232c0
  L623488:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; }) != (u32)(0)) goto L6234bb;  // @157_6232c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(93)) goto L6234bb;  // @158_6232c0
  eax = (u32)(edx + 2);  // @159_6232c0
  if (eax == edi) goto L623712;  // @160_6232c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 3), sizeof v); (u32)v; }) != (u32)(0)) goto L6234bb;  // @161_6232c0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(62)) goto L6234bb;  // @162_6232c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @163_6232c0
  edx = (edx + (u32)(4));  // @164_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @165_6232c0
  eax = (u32)(34);  // @166_6232c0
  return eax;  // @167_6232c0
  L6234bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @169_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @170_6232c0
  eax = (u32)(26);  // @171_6232c0
  return eax;  // @172_6232c0
  L6234ca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @174_6232c0
  edx = (edx + (u32)(2));  // @175_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @176_6232c0
  eax = (u32)(23);  // @177_6232c0
  return eax;  // @178_6232c0
  L6234dc:;
  edx = (edx + (u32)(2));  // @180_6232c0
  if (edx != edi) goto L6234ed;  // @181_6232c0
  eax = (u32)(4294967272);  // @182_6232c0
  return eax;  // @183_6232c0
  L6234ed:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @185_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @186_6232c0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L6234fe;  // @187_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @188_6232c0
  goto L623508;  // @189_6232c0
  L6234fe:;
  p23_ = eax;  // @191_6232c0
  p24_ = ecx;  // @192_6232c0
  eax = ext_62c640_cdecl2((u32)(p24_), (u32)(p23_));  // @193_6232c0
  ecx = edx = 0;  // @194_6232c0
  L623508:;
  eax = (eax - (u32)(9));  // @196_6232c0
  if (eax > (u32)(27)) goto L623774;  // @197_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6436920), sizeof v); (u32)v; });  // @198_6232c0
  switch (eax) { case 0: goto L623558; case 1: goto L623534; case 2: goto L623522; case 3: goto L623546; case 4: goto L623774; default: __builtin_trap(); }  // @199_6232c0
  L623522:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @201_6232c0
  edx = (edx + (u32)(2));  // @202_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @203_6232c0
  eax = (u32)(36);  // @204_6232c0
  return eax;  // @205_6232c0
  L623534:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @207_6232c0
  edx = (edx + (u32)(2));  // @208_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @209_6232c0
  eax = (u32)(35);  // @210_6232c0
  return eax;  // @211_6232c0
  L623546:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @213_6232c0
  edx = (edx + (u32)(2));  // @214_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @215_6232c0
  eax = (u32)(37);  // @216_6232c0
  return eax;  // @217_6232c0
  L623558:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @219_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @220_6232c0
  eax = (u32)(24);  // @221_6232c0
  return eax;  // @222_6232c0
  L623567:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @224_6232c0
  edx = (edx + (u32)(2));  // @225_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @226_6232c0
  eax = (u32)(21);  // @227_6232c0
  return eax;  // @228_6232c0
  L623579:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @230_6232c0
  edx = (edx + (u32)(2));  // @231_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @232_6232c0
  eax = (u32)(17);  // @233_6232c0
  return eax;  // @234_6232c0
  L62358b:;
  edx = (edx + (u32)(2));  // @236_6232c0
  p25_ = edi;  // @237_6232c0
  p26_ = edx;  // @238_6232c0
  p27_ = esi;  // @239_6232c0
  eax = ext_62a4d0_cdecl4((u32)(p27_), (u32)(p26_), (u32)(p25_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @240_6232c0
  ecx = edx = 0;  // @241_6232c0
  return eax;  // @242_6232c0
  L6235a1:;
  edi = (edi - edx);  // @244_6232c0
  if ((s32)edi >= (s32)(u32)(2)) goto L623774;  // @245_6232c0
  eax = (u32)(4294967294);  // @246_6232c0
  return eax;  // @247_6232c0
  L6235b6:;
  edi = (edi - edx);  // @249_6232c0
  if ((s32)edi >= (s32)(u32)(3)) goto L623774;  // @250_6232c0
  eax = (u32)(4294967294);  // @251_6232c0
  return eax;  // @252_6232c0
  L6235cb:;
  edi = (edi - edx);  // @254_6232c0
  if ((s32)edi >= (s32)(u32)(4)) goto L623774;  // @255_6232c0
  eax = (u32)(4294967294);  // @256_6232c0
  return eax;  // @257_6232c0
  L6235e0:;
  eax = (ebx & 0xff);  // @259_6232c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @260_6232c0
  eax = (u32)(1);  // @261_6232c0
  ecx = (ecx & 0xff);  // @262_6232c0
  ebx = ecx;  // @263_6232c0
  ecx = (ecx & (u32)(31));  // @264_6232c0
  eax = (eax << (ecx & 0xff));  // @265_6232c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @266_6232c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @267_6232c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @268_6232c0
  ebx = (ebx >> (u32)(5));  // @269_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @270_6232c0
  eax = (u32)(ebx + eax*8);  // @271_6232c0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7075616), sizeof v); (u32)v; }) & ecx) == 0) goto L62361b;  // @272_6232c0
  L623614:;
  ebx = (u32)(18);  // @274_6232c0
  goto L62363a;  // @275_6232c0
  L62361b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @277_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @278_6232c0
  eax = (u32)(ebx + eax*8);  // @279_6232c0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7075616), sizeof v); (u32)v; }) & ecx) == 0) goto L623774;  // @280_6232c0
  L623635:;
  ebx = (u32)(19);  // @282_6232c0
  L62363a:;
  edx = (edx + (u32)(2));  // @284_6232c0
  if (edx == edi) goto L62376b;  // @285_6232c0
  L623645:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @287_6232c0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @288_6232c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @289_6232c0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L62365b;  // @290_6232c0
  eax = (ecx & 0xff);  // @291_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @292_6232c0
  goto L623665;  // @293_6232c0
  L62365b:;
  p28_ = ecx;  // @295_6232c0
  p29_ = eax;  // @296_6232c0
  eax = ext_62c640_cdecl2((u32)(p29_), (u32)(p28_));  // @297_6232c0
  ecx = edx = 0;  // @298_6232c0
  L623665:;
  eax = (eax - (u32)(5));  // @300_6232c0
  if (eax > (u32)(31)) goto L623774;  // @301_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6436992), sizeof v); (u32)v; });  // @302_6232c0
  switch (eax) { case 0: goto L6235a1; case 1: goto L6235b6; case 2: goto L6235cb; case 3: goto L62371a; case 4: goto L623754; case 5: goto L62370d; case 6: goto L623684; case 7: goto L62367f; case 8: goto L62373d; case 9: goto L623726; case 10: goto L623774; default: __builtin_trap(); }  // @303_6232c0
  L62367f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @305_6232c0
  goto L6236e5;  // @306_6232c0
  L623684:;
  edx = (edx + (u32)(2));  // @308_6232c0
  if (ebx == (u32)(18)) goto L6236a3;  // @309_6232c0
  if (ebx != (u32)(41)) goto L623696;  // @310_6232c0
  L623691:;
  ebx = (u32)(19);  // @312_6232c0
  L623696:;
  if (edx == edi) goto L62376b;  // @314_6232c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @315_6232c0
  goto L623645;  // @316_6232c0
  L6236a3:;
  if (edx == edi) goto L623712;  // @318_6232c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @319_6232c0
  ebx = (u32)(41);  // @320_6232c0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @321_6232c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @322_6232c0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6236c2;  // @323_6232c0
  eax = (ecx & 0xff);  // @324_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @325_6232c0
  goto L6236cc;  // @326_6232c0
  L6236c2:;
  p30_ = ecx;  // @328_6232c0
  p31_ = eax;  // @329_6232c0
  eax = ext_62c640_cdecl2((u32)(p31_), (u32)(p30_));  // @330_6232c0
  ecx = edx = 0;  // @331_6232c0
  L6236cc:;
  eax = (eax - (u32)(5));  // @333_6232c0
  if (eax > (u32)(24)) goto L623691;  // @334_6232c0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6437048), sizeof v); (u32)v; });  // @335_6232c0
  switch (eax) { case 0: goto L6235a1; case 1: goto L6235b6; case 2: goto L6235cb; case 3: goto L62370d; case 4: goto L6236e2; case 5: goto L623691; default: __builtin_trap(); }  // @336_6232c0
  L6236e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @338_6232c0
  L6236e5:;
  eax = (eax & 0xff);  // @340_6232c0
  ecx = (ecx & 0xff);  // @341_6232c0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @342_6232c0
  eax = ecx;  // @343_6232c0
  eax = (eax >> (u32)(5));  // @344_6232c0
  ecx = (ecx & (u32)(31));  // @345_6232c0
  esi = (u32)(eax + esi*8);  // @346_6232c0
  eax = (u32)(1);  // @347_6232c0
  eax = (eax << (ecx & 0xff));  // @348_6232c0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L623774;  // @349_6232c0
  L62370d:;
  edx = (edx + (u32)(2));  // @351_6232c0
  goto L623696;  // @352_6232c0
  L623712:;
  eax = (eax | (u32)(4294967295));  // @354_6232c0
  return eax;  // @355_6232c0
  L62371a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @357_6232c0
  eax = ebx;  // @358_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @359_6232c0
  return eax;  // @360_6232c0
  L623726:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @362_6232c0
  if (ebx == (u32)(19)) goto L623777;  // @363_6232c0
  edx = (edx + (u32)(2));  // @364_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @365_6232c0
  eax = (u32)(32);  // @366_6232c0
  return eax;  // @367_6232c0
  L62373d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @369_6232c0
  if (ebx == (u32)(19)) goto L623777;  // @370_6232c0
  edx = (edx + (u32)(2));  // @371_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @372_6232c0
  eax = (u32)(31);  // @373_6232c0
  return eax;  // @374_6232c0
  L623754:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @376_6232c0
  if (ebx == (u32)(19)) goto L623777;  // @377_6232c0
  edx = (edx + (u32)(2));  // @378_6232c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @379_6232c0
  eax = (u32)(30);  // @380_6232c0
  return eax;  // @381_6232c0
  L62376b:;
  ebx = (0u - ebx);  // @383_6232c0
  eax = ebx;  // @384_6232c0
  return eax;  // @385_6232c0
  L623774:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @387_6232c0
  L623777:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @389_6232c0
  eax = 0;  // @390_6232c0
  return eax;  // @391_6232c0
}
PCREG(6232c0, lifted_6232c0);

extern "C" u32 THISCALL lifted_6254d0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6254d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @2_6254d0
  if (edx != edi) goto L6254e9;  // @3_6254d0
  eax = (u32)(4294967292);  // @4_6254d0
  return eax;  // @5_6254d0
  L6254e9:;
  eax = edi;  // @7_6254d0
  eax = (eax - edx);  // @8_6254d0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L6254ff;  // @9_6254d0
  eax = (eax & (u32)(4294967294));  // @10_6254d0
  if (eax != 0) goto L6254fc;  // @11_6254d0
  eax = (eax | (u32)(4294967295));  // @12_6254d0
  return eax;  // @13_6254d0
  L6254fc:;
  edi = (u32)(eax + edx);  // @15_6254d0
  L6254ff:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @17_6254d0
  p0_ = ebx;  // @18_6254d0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @19_6254d0
  p1_ = esi;  // @20_6254d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L625517;  // @21_6254d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_6254d0
  eax = (ecx & 0xff);  // @23_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @24_6254d0
  goto L625524;  // @25_6254d0
  L625517:;
  p2_ = ecx;  // @27_6254d0
  p3_ = ebx;  // @28_6254d0
  eax = ext_62c640_cdecl4((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @29_6254d0
  ecx = edx = 0;  // @30_6254d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @31_6254d0
  L625524:;
  eax = (eax - (u32)(2));  // @33_6254d0
  if (eax > (u32)(34)) goto L625984;  // @34_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6445540), sizeof v); (u32)v; });  // @35_6254d0
  switch (eax) { case 0: goto L62556e; case 1: goto L625687; case 2: goto L6257b1; case 3: goto L6257c6; case 4: goto L6257db; case 5: goto L6255ec; case 6: goto L6255fd; case 7: goto L625789; case 8: goto L62553e; case 9: goto L625556; case 10: goto L62579b; case 11: goto L625675; case 12: goto L625824; case 13: goto L625845; case 14: goto L6257f0; case 15: goto L62564d; case 16: goto L6256da; case 17: goto L6256ec; case 18: goto L625663; case 19: goto L625777; case 20: goto L625984; default: __builtin_trap(); }  // @36_6254d0
  L62553e:;
  edx = (edx + (u32)(2));  // @38_6254d0
  p4_ = edi;  // @39_6254d0
  p5_ = edx;  // @40_6254d0
  p6_ = esi;  // @41_6254d0
  eax = ext_627a80_cdecl5((u32)(12), (u32)(p6_), (u32)(p5_), (u32)(p4_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @42_6254d0
  ecx = edx = 0;  // @43_6254d0
  return eax;  // @44_6254d0
  L625556:;
  edx = (edx + (u32)(2));  // @46_6254d0
  p7_ = edi;  // @47_6254d0
  p8_ = edx;  // @48_6254d0
  p9_ = esi;  // @49_6254d0
  eax = ext_627a80_cdecl5((u32)(13), (u32)(p9_), (u32)(p8_), (u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @50_6254d0
  ecx = edx = 0;  // @51_6254d0
  return eax;  // @52_6254d0
  L62556e:;
  edx = (edx + (u32)(2));  // @54_6254d0
  if (edx == edi) goto L625922;  // @55_6254d0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @56_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @57_6254d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L62558a;  // @58_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @59_6254d0
  goto L625594;  // @60_6254d0
  L62558a:;
  p10_ = eax;  // @62_6254d0
  p11_ = ecx;  // @63_6254d0
  eax = ext_62c640_cdecl2((u32)(p11_), (u32)(p10_));  // @64_6254d0
  ecx = edx = 0;  // @65_6254d0
  L625594:;
  eax = (eax - (u32)(5));  // @67_6254d0
  if (eax > (u32)(24)) goto L625984;  // @68_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6445592), sizeof v); (u32)v; });  // @69_6254d0
  switch (eax) { case 0: goto L6255da; case 1: goto L6255c4; case 2: goto L6255ae; case 3: goto L625984; default: __builtin_trap(); }  // @70_6254d0
  L6255ae:;
  edx = (edx + (u32)(2));  // @72_6254d0
  p12_ = edi;  // @73_6254d0
  p13_ = edx;  // @74_6254d0
  p14_ = esi;  // @75_6254d0
  eax = ext_627640_cdecl4((u32)(p14_), (u32)(p13_), (u32)(p12_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @76_6254d0
  ecx = edx = 0;  // @77_6254d0
  return eax;  // @78_6254d0
  L6255c4:;
  edx = (edx + (u32)(2));  // @80_6254d0
  p15_ = edi;  // @81_6254d0
  p16_ = edx;  // @82_6254d0
  p17_ = esi;  // @83_6254d0
  eax = ext_6281a0_cdecl4((u32)(p17_), (u32)(p16_), (u32)(p15_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @84_6254d0
  ecx = edx = 0;  // @85_6254d0
  return eax;  // @86_6254d0
  L6255da:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @88_6254d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @89_6254d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @90_6254d0
  eax = (u32)(29);  // @91_6254d0
  return eax;  // @92_6254d0
  L6255ec:;
  eax = (u32)(edx + 2);  // @94_6254d0
  if (eax != edi) goto L6255fd;  // @95_6254d0
  eax = (u32)(4294967281);  // @96_6254d0
  return eax;  // @97_6254d0
  L6255fd:;
  edx = (edx + (u32)(2));  // @99_6254d0
  if (edx == edi) goto L62563e;  // @100_6254d0
  L625604:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @102_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @103_6254d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L625615;  // @104_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @105_6254d0
  goto L62561f;  // @106_6254d0
  L625615:;
  p18_ = eax;  // @108_6254d0
  p19_ = ecx;  // @109_6254d0
  eax = ext_62c640_cdecl2((u32)(p19_), (u32)(p18_));  // @110_6254d0
  ecx = edx = 0;  // @111_6254d0
  L62561f:;
  eax = (eax - (u32)(9));  // @113_6254d0
  if (eax == 0) goto L625630;  // @114_6254d0
  eax = (eax - (u32)(1));  // @115_6254d0
  if (eax == 0) goto L625637;  // @116_6254d0
  eax = (eax - (u32)(11));  // @117_6254d0
  if (eax != 0) goto L62563e;  // @118_6254d0
  goto L625637;  // @119_6254d0
  L625630:;
  eax = (u32)(edx + 2);  // @121_6254d0
  if (eax == edi) goto L62563e;  // @122_6254d0
  L625637:;
  edx = (edx + (u32)(2));  // @124_6254d0
  if (edx != edi) goto L625604;  // @125_6254d0
  L62563e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @127_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @128_6254d0
  eax = (u32)(15);  // @129_6254d0
  return eax;  // @130_6254d0
  L62564d:;
  edx = (edx + (u32)(2));  // @132_6254d0
  p20_ = edi;  // @133_6254d0
  p21_ = edx;  // @134_6254d0
  p22_ = esi;  // @135_6254d0
  eax = ext_627fd0_cdecl4((u32)(p22_), (u32)(p21_), (u32)(p20_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @136_6254d0
  ecx = edx = 0;  // @137_6254d0
  return eax;  // @138_6254d0
  L625663:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @140_6254d0
  edx = (edx + (u32)(2));  // @141_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @142_6254d0
  eax = (u32)(38);  // @143_6254d0
  return eax;  // @144_6254d0
  L625675:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @146_6254d0
  edx = (edx + (u32)(2));  // @147_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @148_6254d0
  eax = (u32)(25);  // @149_6254d0
  return eax;  // @150_6254d0
  L625687:;
  edx = (edx + (u32)(2));  // @152_6254d0
  if (edx != edi) goto L625698;  // @153_6254d0
  eax = (u32)(4294967270);  // @154_6254d0
  return eax;  // @155_6254d0
  L625698:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(0)) goto L6256cb;  // @157_6254d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; }) != (u32)(93)) goto L6256cb;  // @158_6254d0
  eax = (u32)(edx + 2);  // @159_6254d0
  if (eax == edi) goto L625922;  // @160_6254d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L6256cb;  // @161_6254d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 3), sizeof v); (u32)v; }) != (u32)(62)) goto L6256cb;  // @162_6254d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @163_6254d0
  edx = (edx + (u32)(4));  // @164_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @165_6254d0
  eax = (u32)(34);  // @166_6254d0
  return eax;  // @167_6254d0
  L6256cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @169_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @170_6254d0
  eax = (u32)(26);  // @171_6254d0
  return eax;  // @172_6254d0
  L6256da:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @174_6254d0
  edx = (edx + (u32)(2));  // @175_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @176_6254d0
  eax = (u32)(23);  // @177_6254d0
  return eax;  // @178_6254d0
  L6256ec:;
  edx = (edx + (u32)(2));  // @180_6254d0
  if (edx != edi) goto L6256fd;  // @181_6254d0
  eax = (u32)(4294967272);  // @182_6254d0
  return eax;  // @183_6254d0
  L6256fd:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @185_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; });  // @186_6254d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L62570e;  // @187_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @188_6254d0
  goto L625718;  // @189_6254d0
  L62570e:;
  p23_ = eax;  // @191_6254d0
  p24_ = ecx;  // @192_6254d0
  eax = ext_62c640_cdecl2((u32)(p24_), (u32)(p23_));  // @193_6254d0
  ecx = edx = 0;  // @194_6254d0
  L625718:;
  eax = (eax - (u32)(9));  // @196_6254d0
  if (eax > (u32)(27)) goto L625984;  // @197_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6445640), sizeof v); (u32)v; });  // @198_6254d0
  switch (eax) { case 0: goto L625768; case 1: goto L625744; case 2: goto L625732; case 3: goto L625756; case 4: goto L625984; default: __builtin_trap(); }  // @199_6254d0
  L625732:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @201_6254d0
  edx = (edx + (u32)(2));  // @202_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @203_6254d0
  eax = (u32)(36);  // @204_6254d0
  return eax;  // @205_6254d0
  L625744:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @207_6254d0
  edx = (edx + (u32)(2));  // @208_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @209_6254d0
  eax = (u32)(35);  // @210_6254d0
  return eax;  // @211_6254d0
  L625756:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @213_6254d0
  edx = (edx + (u32)(2));  // @214_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @215_6254d0
  eax = (u32)(37);  // @216_6254d0
  return eax;  // @217_6254d0
  L625768:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @219_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @220_6254d0
  eax = (u32)(24);  // @221_6254d0
  return eax;  // @222_6254d0
  L625777:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @224_6254d0
  edx = (edx + (u32)(2));  // @225_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @226_6254d0
  eax = (u32)(21);  // @227_6254d0
  return eax;  // @228_6254d0
  L625789:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @230_6254d0
  edx = (edx + (u32)(2));  // @231_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @232_6254d0
  eax = (u32)(17);  // @233_6254d0
  return eax;  // @234_6254d0
  L62579b:;
  edx = (edx + (u32)(2));  // @236_6254d0
  p25_ = edi;  // @237_6254d0
  p26_ = edx;  // @238_6254d0
  p27_ = esi;  // @239_6254d0
  eax = ext_628470_cdecl4((u32)(p27_), (u32)(p26_), (u32)(p25_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @240_6254d0
  ecx = edx = 0;  // @241_6254d0
  return eax;  // @242_6254d0
  L6257b1:;
  edi = (edi - edx);  // @244_6254d0
  if ((s32)edi >= (s32)(u32)(2)) goto L625984;  // @245_6254d0
  eax = (u32)(4294967294);  // @246_6254d0
  return eax;  // @247_6254d0
  L6257c6:;
  edi = (edi - edx);  // @249_6254d0
  if ((s32)edi >= (s32)(u32)(3)) goto L625984;  // @250_6254d0
  eax = (u32)(4294967294);  // @251_6254d0
  return eax;  // @252_6254d0
  L6257db:;
  edi = (edi - edx);  // @254_6254d0
  if ((s32)edi >= (s32)(u32)(4)) goto L625984;  // @255_6254d0
  eax = (u32)(4294967294);  // @256_6254d0
  return eax;  // @257_6254d0
  L6257f0:;
  eax = (ebx & 0xff);  // @259_6254d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @260_6254d0
  eax = (u32)(1);  // @261_6254d0
  ecx = (ecx & 0xff);  // @262_6254d0
  ebx = ecx;  // @263_6254d0
  ecx = (ecx & (u32)(31));  // @264_6254d0
  eax = (eax << (ecx & 0xff));  // @265_6254d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @266_6254d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @267_6254d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @268_6254d0
  ebx = (ebx >> (u32)(5));  // @269_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7076896), sizeof v); (u32)v; });  // @270_6254d0
  eax = (u32)(ebx + eax*8);  // @271_6254d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7075616), sizeof v); (u32)v; }) & ecx) == 0) goto L62582b;  // @272_6254d0
  L625824:;
  ebx = (u32)(18);  // @274_6254d0
  goto L62584a;  // @275_6254d0
  L62582b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @277_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @278_6254d0
  eax = (u32)(ebx + eax*8);  // @279_6254d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7075616), sizeof v); (u32)v; }) & ecx) == 0) goto L625984;  // @280_6254d0
  L625845:;
  ebx = (u32)(19);  // @282_6254d0
  L62584a:;
  edx = (edx + (u32)(2));  // @284_6254d0
  if (edx == edi) goto L62597b;  // @285_6254d0
  L625855:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @287_6254d0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @288_6254d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @289_6254d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L62586b;  // @290_6254d0
  eax = (ecx & 0xff);  // @291_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @292_6254d0
  goto L625875;  // @293_6254d0
  L62586b:;
  p28_ = ecx;  // @295_6254d0
  p29_ = eax;  // @296_6254d0
  eax = ext_62c640_cdecl2((u32)(p29_), (u32)(p28_));  // @297_6254d0
  ecx = edx = 0;  // @298_6254d0
  L625875:;
  eax = (eax - (u32)(5));  // @300_6254d0
  if (eax > (u32)(31)) goto L625984;  // @301_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6445712), sizeof v); (u32)v; });  // @302_6254d0
  switch (eax) { case 0: goto L6257b1; case 1: goto L6257c6; case 2: goto L6257db; case 3: goto L62592a; case 4: goto L625964; case 5: goto L62591d; case 6: goto L625894; case 7: goto L62588f; case 8: goto L62594d; case 9: goto L625936; case 10: goto L625984; default: __builtin_trap(); }  // @303_6254d0
  L62588f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @305_6254d0
  goto L6258f5;  // @306_6254d0
  L625894:;
  edx = (edx + (u32)(2));  // @308_6254d0
  if (ebx == (u32)(18)) goto L6258b3;  // @309_6254d0
  if (ebx != (u32)(41)) goto L6258a6;  // @310_6254d0
  L6258a1:;
  ebx = (u32)(19);  // @312_6254d0
  L6258a6:;
  if (edx == edi) goto L62597b;  // @314_6254d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @315_6254d0
  goto L625855;  // @316_6254d0
  L6258b3:;
  if (edx == edi) goto L625922;  // @318_6254d0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @319_6254d0
  ebx = (u32)(41);  // @320_6254d0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @321_6254d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @322_6254d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6258d2;  // @323_6254d0
  eax = (ecx & 0xff);  // @324_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 76), sizeof v); (u32)v; });  // @325_6254d0
  goto L6258dc;  // @326_6254d0
  L6258d2:;
  p30_ = ecx;  // @328_6254d0
  p31_ = eax;  // @329_6254d0
  eax = ext_62c640_cdecl2((u32)(p31_), (u32)(p30_));  // @330_6254d0
  ecx = edx = 0;  // @331_6254d0
  L6258dc:;
  eax = (eax - (u32)(5));  // @333_6254d0
  if (eax > (u32)(24)) goto L6258a1;  // @334_6254d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6445768), sizeof v); (u32)v; });  // @335_6254d0
  switch (eax) { case 0: goto L6257b1; case 1: goto L6257c6; case 2: goto L6257db; case 3: goto L62591d; case 4: goto L6258f2; case 5: goto L6258a1; default: __builtin_trap(); }  // @336_6254d0
  L6258f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @338_6254d0
  L6258f5:;
  eax = (eax & 0xff);  // @340_6254d0
  ecx = (ecx & 0xff);  // @341_6254d0
  esi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7077152), sizeof v); (u32)v; });  // @342_6254d0
  eax = ecx;  // @343_6254d0
  eax = (eax >> (u32)(5));  // @344_6254d0
  ecx = (ecx & (u32)(31));  // @345_6254d0
  esi = (u32)(eax + esi*8);  // @346_6254d0
  eax = (u32)(1);  // @347_6254d0
  eax = (eax << (ecx & 0xff));  // @348_6254d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi*4 + 7075616), sizeof v); (u32)v; }) & eax) == 0) goto L625984;  // @349_6254d0
  L62591d:;
  edx = (edx + (u32)(2));  // @351_6254d0
  goto L6258a6;  // @352_6254d0
  L625922:;
  eax = (eax | (u32)(4294967295));  // @354_6254d0
  return eax;  // @355_6254d0
  L62592a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @357_6254d0
  eax = ebx;  // @358_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @359_6254d0
  return eax;  // @360_6254d0
  L625936:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @362_6254d0
  if (ebx == (u32)(19)) goto L625987;  // @363_6254d0
  edx = (edx + (u32)(2));  // @364_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @365_6254d0
  eax = (u32)(32);  // @366_6254d0
  return eax;  // @367_6254d0
  L62594d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @369_6254d0
  if (ebx == (u32)(19)) goto L625987;  // @370_6254d0
  edx = (edx + (u32)(2));  // @371_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @372_6254d0
  eax = (u32)(31);  // @373_6254d0
  return eax;  // @374_6254d0
  L625964:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @376_6254d0
  if (ebx == (u32)(19)) goto L625987;  // @377_6254d0
  edx = (edx + (u32)(2));  // @378_6254d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @379_6254d0
  eax = (u32)(30);  // @380_6254d0
  return eax;  // @381_6254d0
  L62597b:;
  ebx = (0u - ebx);  // @383_6254d0
  eax = ebx;  // @384_6254d0
  return eax;  // @385_6254d0
  L625984:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @387_6254d0
  L625987:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @389_6254d0
  eax = 0;  // @390_6254d0
  return eax;  // @391_6254d0
}
PCREG(6254d0, lifted_6254d0);

extern "C" u32 lifted_631850(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_631850
  p0_ = ebx;  // @2_631850
  p1_ = esi;  // @3_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @5_631850
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @6_631850
  p2_ = edi;  // @7_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @9_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 52), sizeof v); (u32)v; });  // @11_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @12_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @13_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @14_631850
  if (edi >= eax) goto L631885;  // @15_631850
  eax = (eax - edi);  // @16_631850
  eax = (eax - 1);  // @17_631850
  goto L63188a;  // @18_631850
  L631885:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @20_631850
  eax = (eax - edi);  // @21_631850
  L63188a:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @23_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @24_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) > (u32)(9)) goto L631f8d;  // @25_631850
  L6318a0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_631850
  switch (ebx) { case 0: goto L6318a9; case 1: goto L631986; case 2: goto L6319f2; case 3: goto L631af4; case 4: goto L631b9b; case 5: goto L631c7f; case 6: goto L631eee; case 7: goto L632104; case 8: goto L632158; case 9: goto L63215f; case 10: goto L6318fb; case 11: goto L63191b; case 12: goto L63196f; case 13: goto L631fe0; default: __builtin_trap(); }  // @28_631850
  L6318a9:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @30_631850
  if (esi >= (u32)(3)) goto L6318dc;  // @31_631850
  L6318b1:;
  if ((ebx & ebx) == 0) goto L631fbe;  // @33_631850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_631850
  ecx = esi;  // @35_631850
  eax = (eax << (ecx & 0xff));  // @36_631850
  ebx = (ebx - 1);  // @37_631850
  edx = (edx | eax);  // @38_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @39_631850
  edi = (edi + 1);  // @40_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @41_631850
  esi = (esi + (u32)(8));  // @42_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @43_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @44_631850
  if (esi < (u32)(3)) goto L6318b1;  // @45_631850
  L6318dc:;
  ecx = edx;  // @47_631850
  ecx = (ecx & (u32)(7));  // @48_631850
  eax = ecx;  // @49_631850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @50_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @51_631850
  eax = (eax & (u32)(1));  // @52_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @53_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @54_631850
  ecx = (ecx >> (u32)(1));  // @55_631850
  switch (ecx) { case 0: goto L6318fb; case 1: goto L63191b; case 2: goto L63196f; case 3: goto L631fe0; default: __builtin_trap(); }  // @56_631850
  L6318fb:;
  esi = (esi - (u32)(3));  // @58_631850
  edx = (edx >> (u32)(3));  // @59_631850
  ecx = esi;  // @60_631850
  ecx = (ecx & (u32)(7));  // @61_631850
  edx = (edx >> (ecx & 0xff));  // @62_631850
  esi = (esi - ecx);  // @63_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @64_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @65_631850
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @66_631850
  goto L631f7e;  // @67_631850
  L63191b:;
  eax = (u32)(EBP - 36);  // @69_631850
  p3_ = eax;  // @70_631850
  eax = (u32)(EBP - 40);  // @71_631850
  p4_ = eax;  // @72_631850
  eax = (u32)(EBP - 44);  // @73_631850
  p5_ = eax;  // @74_631850
  eax = (u32)(EBP - 48);  // @75_631850
  p6_ = eax;  // @76_631850
  eax = ext_632a70_cdecl8((u32)(p6_), (u32)(p5_), (u32)(p4_), (u32)(p3_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), (u32)(p2_), (u32)(p1_), (u32)(p0_));  // @77_631850
  ecx = edx = 0;  // @78_631850
  eax = ext_633190_cdecl5(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @79_631850
  ecx = edx = 0;  // @80_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @81_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @82_631850
  if ((eax & eax) == 0) goto L631fd6;  // @83_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @84_631850
  edx = (edx >> (u32)(3));  // @85_631850
  esi = (esi - (u32)(3));  // @86_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @87_631850
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @88_631850
  goto L631f7e;  // @89_631850
  L63196f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @91_631850
  edx = (edx >> (u32)(3));  // @92_631850
  esi = (esi - (u32)(3));  // @93_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @94_631850
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @95_631850
  goto L631f7e;  // @96_631850
  L631986:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @98_631850
  if (esi >= (u32)(32)) goto L6319bb;  // @99_631850
  L631990:;
  if ((ebx & ebx) == 0) goto L631fbe;  // @101_631850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @102_631850
  ecx = esi;  // @103_631850
  eax = (eax << (ecx & 0xff));  // @104_631850
  ebx = (ebx - 1);  // @105_631850
  edi = (edi + 1);  // @106_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @107_631850
  esi = (esi + (u32)(8));  // @108_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @109_631850
  edx = (edx | eax);  // @110_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @111_631850
  if (esi < (u32)(32)) goto L631990;  // @112_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @113_631850
  L6319bb:;
  eax = (edx & 0xffff);  // @115_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @116_631850
  eax = edx;  // @117_631850
  eax = (~eax);  // @118_631850
  eax = (eax >> (u32)(16));  // @119_631850
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; })) goto L632002;  // @120_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @121_631850
  edx = 0;  // @122_631850
  esi = 0;  // @123_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @124_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @125_631850
  if ((eax & eax) == 0) goto L631ae3;  // @126_631850
  eax = (u32)(2);  // @127_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @128_631850
  goto L631f7e;  // @129_631850
  L6319f2:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @131_631850
  if ((ebx & ebx) == 0) goto L631fc1;  // @132_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @133_631850
  if ((eax & eax) != 0) goto L631aa0;  // @134_631850
  if (edx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; })) goto L631a34;  // @135_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @136_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @137_631850
  if (eax == edx) goto L631a31;  // @138_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @139_631850
  if (edx >= eax) goto L631a23;  // @140_631850
  eax = (eax - edx);  // @141_631850
  eax = (eax - 1);  // @142_631850
  goto L631a28;  // @143_631850
  L631a23:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @145_631850
  eax = (eax - edx);  // @146_631850
  L631a28:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @148_631850
  if ((eax & eax) != 0) goto L631aa0;  // @149_631850
  goto L631a34;  // @150_631850
  L631a31:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @152_631850
  L631a34:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @154_631850
  p7_ = ecx;  // @155_631850
  eax = ext_6331d0_cdecl3((u32)(p7_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @156_631850
  ecx = edx = 0;  // @157_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @158_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @159_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 52), sizeof v); (u32)v; });  // @160_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @161_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @162_631850
  if (edx >= eax) goto L631a61;  // @163_631850
  edx = eax;  // @164_631850
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @165_631850
  edx = (edx - 1);  // @166_631850
  goto L631a67;  // @167_631850
  L631a61:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @169_631850
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @170_631850
  L631a67:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @172_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @173_631850
  if (edx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; })) goto L631a95;  // @174_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @175_631850
  if (eax == edx) goto L631a92;  // @176_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @177_631850
  if (edx >= eax) goto L631a88;  // @178_631850
  eax = (eax - edx);  // @179_631850
  eax = (eax - 1);  // @180_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @181_631850
  goto L631a98;  // @182_631850
  L631a88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @184_631850
  eax = (eax - edx);  // @185_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @186_631850
  goto L631a98;  // @187_631850
  L631a92:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @189_631850
  L631a95:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @191_631850
  L631a98:;
  if ((eax & eax) == 0) goto L63205d;  // @193_631850
  L631aa0:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @195_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @196_631850
  if (edi > ebx) edi = ebx;  // @197_631850
  if (edi > eax) edi = eax;  // @198_631850
  p8_ = edi;  // @199_631850
  p9_ = edx;  // @200_631850
  eax = ext_634d22_cdecl3((u32)(p9_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }), (u32)(p8_));  // @201_631850
  ecx = edx = 0;  // @202_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @203_631850
  ebx = (ebx - edi);  // @204_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @205_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }) + edi)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @206_631850
  eax = (eax - edi);  // @207_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) + edi)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @208_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) - edi)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @209_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @210_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @211_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @212_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) != 0) goto L631f81;  // @213_631850
  L631ae3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @215_631850
  eax = (0u - eax);  // @216_631850
  eax = 0;  // @217_631850
  eax = (eax & (u32)(7));  // @218_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @219_631850
  goto L631f7e;  // @220_631850
  L631af4:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @222_631850
  if (esi >= (u32)(14)) goto L631b2e;  // @223_631850
  L631b00:;
  if ((ebx & ebx) == 0) goto L631fbe;  // @225_631850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @226_631850
  ecx = esi;  // @227_631850
  eax = (eax << (ecx & 0xff));  // @228_631850
  ebx = (ebx - 1);  // @229_631850
  edx = (edx | eax);  // @230_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @231_631850
  edi = (edi + 1);  // @232_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @233_631850
  esi = (esi + (u32)(8));  // @234_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @235_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @236_631850
  if (esi < (u32)(14)) goto L631b00;  // @237_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @238_631850
  L631b2e:;
  eax = edx;  // @240_631850
  eax = (eax & (u32)(16383));  // @241_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @242_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) & (u32)(31))); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @243_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @244_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) > (u32)(29)) goto L63201e;  // @245_631850
  eax = (eax >> (u32)(5));  // @246_631850
  eax = (eax & (u32)(31));  // @247_631850
  if (eax > (u32)(29)) goto L63201e;  // @248_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @249_631850
  ecx = (ecx + (u32)(258));  // @250_631850
  eax = (eax + ecx);  // @251_631850
  p10_ = eax;  // @252_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @253_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @254_631850
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; }), (u32)(p10_), (u32)(4));  // @255_631850
  ecx = edx = 0;  // @256_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @257_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @258_631850
  if ((eax & eax) == 0) goto L631fd6;  // @259_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @260_631850
  edx = (edx >> (u32)(14));  // @261_631850
  esi = (esi - (u32)(14));  // @262_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @263_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @264_631850
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @265_631850
  L631b9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @267_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @268_631850
  eax = (eax >> (u32)(10));  // @269_631850
  eax = (eax + (u32)(4));  // @270_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) >= eax) goto L631c19;  // @271_631850
  L631bb0:;
  if (esi >= (u32)(3)) goto L631be3;  // @273_631850
  L631bb5:;
  if ((ebx & ebx) == 0) goto L631fbe;  // @275_631850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @276_631850
  ecx = esi;  // @277_631850
  eax = (eax << (ecx & 0xff));  // @278_631850
  ebx = (ebx - 1);  // @279_631850
  edx = (edx | eax);  // @280_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @281_631850
  edi = (edi + 1);  // @282_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @283_631850
  esi = (esi + (u32)(8));  // @284_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @285_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @286_631850
  if (esi < (u32)(3)) goto L631bb5;  // @287_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @288_631850
  L631be3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @290_631850
  edx = (edx & (u32)(7));  // @291_631850
  esi = (esi - (u32)(3));  // @292_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7082472), sizeof v); (u32)v; });  // @293_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @294_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @295_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @296_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @297_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @298_631850
  edx = (edx >> (u32)(3));  // @299_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @300_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @301_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @302_631850
  eax = (eax >> (u32)(10));  // @303_631850
  eax = (eax + (u32)(4));  // @304_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) < eax) goto L631bb0;  // @305_631850
  L631c19:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) >= (u32)(19)) goto L631c43;  // @307_631850
  L631c20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @309_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7082472), sizeof v); (u32)v; });  // @310_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @311_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @312_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @313_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @314_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @315_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) < (u32)(19)) goto L631c20;  // @316_631850
  L631c43:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @318_631850
  ecx = (ecx + (u32)(16));  // @319_631850
  eax = (u32)(edx + 20);  // @320_631850
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @321_631850
  p11_ = eax;  // @322_631850
  p12_ = ecx;  // @323_631850
  eax = ext_6328b0_cdecl5(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; }), (u32)(p12_), (u32)(p11_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 36), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @324_631850
  ecx = edx = 0;  // @325_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @326_631850
  if ((eax & eax) != 0) goto L63203a;  // @327_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @328_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @329_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @330_631850
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @331_631850
  L631c7f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @333_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @334_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @335_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @336_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @337_631850
  eax = ecx;  // @338_631850
  eax = (eax >> (u32)(5));  // @339_631850
  ecx = (ecx & (u32)(31));  // @340_631850
  eax = (eax & (u32)(31));  // @341_631850
  eax = (eax + (u32)(258));  // @342_631850
  eax = (eax + ecx);  // @343_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) >= eax) goto L631e51;  // @344_631850
  L631cb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @346_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @347_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @348_631850
  if (esi >= eax) goto L631cea;  // @349_631850
  L631cc0:;
  if ((ebx & ebx) == 0) goto L631fbe;  // @351_631850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @352_631850
  ecx = esi;  // @353_631850
  eax = (eax << (ecx & 0xff));  // @354_631850
  ebx = (ebx - 1);  // @355_631850
  edx = (edx | eax);  // @356_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @357_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @358_631850
  edi = (edi + 1);  // @359_631850
  esi = (esi + (u32)(8));  // @360_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @361_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @362_631850
  if (esi < eax) goto L631cc0;  // @363_631850
  L631cea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7296488), sizeof v); (u32)v; });  // @365_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @366_631850
  ecx = (ecx & edx);  // @367_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @368_631850
  ebx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 1), sizeof v); (u32)v; });  // @369_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 4), sizeof v); (u32)v; });  // @370_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @371_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @372_631850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @373_631850
  if (ecx >= (u32)(16)) goto L631d36;  // @374_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @375_631850
  ecx = eax;  // @376_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @377_631850
  esi = (esi - eax);  // @378_631850
  edx = (edx >> (ecx & 0xff));  // @379_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @380_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @381_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @382_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @383_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @384_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @385_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @386_631850
  goto L631e27;  // @387_631850
  L631d36:;
  if (ecx != (u32)(18)) goto L631d44;  // @389_631850
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @390_631850
  goto L631d4a;  // @391_631850
  L631d44:;
  eax = (u32)(ecx - 14);  // @393_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @394_631850
  L631d4a:;
  eax = 0;  // @396_631850
  eax = (eax & 0xffffff00u) | (((u32)(ecx == (u32)(18))) & 0xff);  // @397_631850
  eax = (u32)(eax*8 + 3);  // @398_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @399_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @400_631850
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }));  // @401_631850
  if (esi >= eax) goto L631d93;  // @402_631850
  L631d66:;
  if ((ebx & ebx) == 0) goto L631fbe;  // @404_631850
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @405_631850
  ecx = esi;  // @406_631850
  eax = (eax << (ecx & 0xff));  // @407_631850
  ebx = (ebx - 1);  // @408_631850
  edx = (edx | eax);  // @409_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @410_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @411_631850
  edi = (edi + 1);  // @412_631850
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }));  // @413_631850
  esi = (esi + (u32)(8));  // @414_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @415_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @416_631850
  if (esi < eax) goto L631d66;  // @417_631850
  L631d93:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @419_631850
  ecx = edi;  // @420_631850
  edx = (edx >> (ecx & 0xff));  // @421_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @422_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx*4 + 7296488), sizeof v); (u32)v; });  // @423_631850
  eax = (eax & edx);  // @424_631850
  edx = (edx >> (ecx & 0xff));  // @425_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @426_631850
  eax = (u32)(ecx + edi);  // @427_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @428_631850
  esi = (esi - eax);  // @429_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @430_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @431_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @432_631850
  eax = ecx;  // @433_631850
  eax = (eax >> (u32)(5));  // @434_631850
  ecx = (ecx & (u32)(31));  // @435_631850
  eax = (eax & (u32)(31));  // @436_631850
  ecx = (ecx + (u32)(258));  // @437_631850
  ecx = (ecx + eax);  // @438_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @439_631850
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @440_631850
  if (eax > ecx) goto L63206b;  // @441_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) != (u32)(16)) goto L631dff;  // @442_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) < (u32)(1)) goto L63206b;  // @443_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @444_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @445_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @446_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 - 4), sizeof v); (u32)v; });  // @447_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @448_631850
  goto L631e06;  // @449_631850
  L631dff:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @451_631850
  L631e06:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @453_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @454_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @455_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @456_631850
  L631e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @458_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax + edx*4), &v, sizeof v); }  // @459_631850
  edx = (edx + 1);  // @460_631850
  edi = (edi - (u32)(1));  // @461_631850
  if (edi != 0) goto L631e12;  // @462_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @463_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @464_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @465_631850
  L631e27:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @467_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @468_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @469_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @470_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @471_631850
  eax = ecx;  // @472_631850
  eax = (eax >> (u32)(5));  // @473_631850
  ecx = (ecx & (u32)(31));  // @474_631850
  eax = (eax & (u32)(31));  // @475_631850
  eax = (eax + (u32)(258));  // @476_631850
  eax = (eax + ecx);  // @477_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) < eax) goto L631cb0;  // @478_631850
  L631e51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @480_631850
  edx = (u32)(EBP - 52);  // @481_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @482_631850
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @483_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @484_631850
  p13_ = edx;  // @485_631850
  edx = (u32)(EBP - 56);  // @486_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @487_631850
  p14_ = edx;  // @488_631850
  edx = (u32)(EBP - 32);  // @489_631850
  p15_ = edx;  // @490_631850
  edx = (u32)(EBP - 28);  // @491_631850
  p16_ = edx;  // @492_631850
  eax = ecx;  // @493_631850
  ecx = (ecx & (u32)(31));  // @494_631850
  eax = (eax >> (u32)(5));  // @495_631850
  ecx = (ecx + (u32)(257));  // @496_631850
  eax = (eax & (u32)(31));  // @497_631850
  eax = (eax + 1);  // @498_631850
  p17_ = eax;  // @499_631850
  p18_ = ecx;  // @500_631850
  eax = ext_632940_cdecl9((u32)(p18_), (u32)(p17_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }), (u32)(p16_), (u32)(p15_), (u32)(p14_), (u32)(p13_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @501_631850
  ecx = edx = 0;  // @502_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @503_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @504_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @505_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @506_631850
  eax = ((u32(THISCALL *)(u32, u32, u32))(ecx))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }));  // @507_631850
  ecx = edx = 0;  // @508_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @509_631850
  if ((eax & eax) != 0) goto L6320bd;  // @510_631850
  eax = ext_633190_cdecl5(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @511_631850
  ecx = edx = 0;  // @512_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @513_631850
  if ((eax & eax) == 0) goto L631fd6;  // @514_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @515_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @516_631850
  { u32 v = (u32)((u32)(6)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @517_631850
  L631eee:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @519_631850
  eax = edi;  // @520_631850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @521_631850
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @522_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @523_631850
  p19_ = esi;  // @524_631850
  p20_ = ecx;  // @525_631850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @526_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @527_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @528_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @529_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @530_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @531_631850
  eax = ext_632aa0_cdecl3((u32)(p20_), (u32)(p19_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @532_631850
  ecx = edx = 0;  // @533_631850
  if (eax != (u32)(1)) goto L63213b;  // @534_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @535_631850
  p21_ = esi;  // @536_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @537_631850
  eax = ext_633170_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }), (u32)(p21_));  // @538_631850
  ecx = edx = 0;  // @539_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @540_631850
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @541_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @542_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @543_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 52), sizeof v); (u32)v; });  // @544_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; });  // @545_631850
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @546_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @547_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @548_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @549_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @550_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) >= eax) goto L631f63;  // @551_631850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @552_631850
  eax = (eax - 1);  // @553_631850
  goto L631f69;  // @554_631850
  L631f63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @556_631850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @557_631850
  L631f69:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @559_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L6320fe;  // @560_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @561_631850
  goto L631f81;  // @562_631850
  L631f7e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @564_631850
  L631f81:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @566_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) <= (u32)(9)) goto L6318a0;  // @567_631850
  L631f8d:;
  L631f8f:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @570_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @571_631850
  L631f95:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @573_631850
  L631f98:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @575_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @576_631850
  L631f9e:;
  eax = edi;  // @578_631850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @579_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @580_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @581_631850
  p22_ = edx;  // @582_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @583_631850
  p23_ = ecx;  // @584_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @585_631850
  eax = ext_6331d0_cdecl3((u32)(p23_), (u32)(p22_), (u32)(-2));  // @586_631850
  ecx = edx = 0;  // @587_631850
  return eax;  // @588_631850
  L631fbe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @590_631850
  L631fc1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @592_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @593_631850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @594_631850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @595_631850
  goto L631f9e;  // @596_631850
  L631fd6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @598_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @599_631850
  goto L631f95;  // @600_631850
  L631fe0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @602_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @603_631850
  edx = (edx >> (u32)(3));  // @604_631850
  esi = (esi + (u32)(-3));  // @605_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @606_631850
  { u32 v = (u32)((u32)(7082548)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @607_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @608_631850
  edx = eax;  // @609_631850
  goto L631f98;  // @610_631850
  L632002:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @612_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @613_631850
  { u32 v = (u32)((u32)(7082568)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @614_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @615_631850
  edx = eax;  // @616_631850
  goto L631f98;  // @617_631850
  L63201e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @619_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @620_631850
  { u32 v = (u32)((u32)(7082600)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @621_631850
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @622_631850
  edx = eax;  // @623_631850
  goto L631f98;  // @624_631850
  L63203a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @626_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @627_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @628_631850
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }), (u32)(-3), (u32)(-3), (u32)(-3), (u32)(-4), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @629_631850
  ecx = edx = 0;  // @630_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @631_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) != (u32)(-3)) goto L63205d;  // @632_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @633_631850
  L63205d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @635_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @636_631850
  goto L631f95;  // @637_631850
  L63206b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @639_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @640_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @641_631850
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @642_631850
  ecx = edx = 0;  // @643_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @644_631850
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @645_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @646_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @647_631850
  { u32 v = (u32)((u32)(7082636)); __builtin_memcpy((void *)(u32)(edx + 24), &v, sizeof v); }  // @648_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @649_631850
  eax = edi;  // @650_631850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @651_631850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @652_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @653_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @654_631850
  p24_ = edx;  // @655_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @656_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @657_631850
  p25_ = ecx;  // @658_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @659_631850
  eax = ext_6331d0_cdecl3((u32)(p25_), (u32)(p24_), (u32)(-3));  // @660_631850
  ecx = edx = 0;  // @661_631850
  return eax;  // @662_631850
  L6320bd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @664_631850
  if (eax != (u32)(-3)) goto L6320cb;  // @665_631850
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @666_631850
  L6320cb:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @668_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @669_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @670_631850
  eax = edi;  // @671_631850
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @672_631850
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @673_631850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @674_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @675_631850
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @676_631850
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @677_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @678_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @679_631850
  p26_ = eax;  // @680_631850
  p27_ = edx;  // @681_631850
  p28_ = ecx;  // @682_631850
  eax = ext_6331d0_cdecl3((u32)(p28_), (u32)(p27_), (u32)(p26_));  // @683_631850
  ecx = edx = 0;  // @684_631850
  return eax;  // @685_631850
  L6320fe:;
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @687_631850
  L632104:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @689_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @690_631850
  p29_ = ecx;  // @691_631850
  eax = ext_6331d0_cdecl3((u32)(p29_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @692_631850
  ecx = edx = 0;  // @693_631850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @694_631850
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @695_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @696_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 52), sizeof v); (u32)v; });  // @697_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @698_631850
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; }) == eax) goto L63214f;  // @699_631850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @700_631850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @701_631850
  goto L631f95;  // @702_631850
  L63213b:;
  p30_ = eax;  // @704_631850
  p31_ = esi;  // @705_631850
  eax = ext_6331d0_cdecl4(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p31_), (u32)(p30_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }));  // @706_631850
  ecx = edx = 0;  // @707_631850
  return eax;  // @708_631850
  L63214f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @710_631850
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @711_631850
  L632158:;
  goto L631f8f;  // @713_631850
  L63215f:;
  goto L631f8f;  // @715_631850
}
PCREG(631850, lifted_631850);

