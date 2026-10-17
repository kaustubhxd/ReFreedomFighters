// batch200117.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_42da80_stdcall1(u32) __asm__("ext_42da80");
extern "C" u32 STDCALL ext_4d8db0_stdcall2(u32, u32) __asm__("ext_4d8db0");
extern "C" u32 STDCALL ext_4d8ef0_stdcall3(u32, u32, u32) __asm__("ext_4d8ef0");
extern "C" u32 STDCALL ext_62f5d0_stdcall2(u32, u32) __asm__("ext_62f5d0");
extern "C" u32 STDCALL ext_62f980_stdcall1(u32) __asm__("ext_62f980");
extern "C" u32 STDCALL ext_62f9d0_stdcall4(u32, u32, u32, u32) __asm__("ext_62f9d0");
extern "C" u32 THISCALL ext_42de30_thiscall1(u32) __asm__("ext_42de30");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_448a30_thiscall2(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_45dcd0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_45dcd0");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4cc690_thiscall1(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_562b50_thiscall2(u32, u32) __asm__("ext_562b50");
extern "C" u32 THISCALL ext_562c20_thiscall2(u32, u32) __asm__("ext_562c20");
extern "C" u32 THISCALL ext_5c5620_thiscall1(u32) __asm__("ext_5c5620");
extern "C" u32 THISCALL ext_5c5810_thiscall1(u32) __asm__("ext_5c5810");
extern "C" u32 THISCALL ext_5f9db0_thiscall2(u32, u32) __asm__("ext_5f9db0");
extern "C" u32 THISCALL ext_5fa1e0_thiscall2(u32, u32) __asm__("ext_5fa1e0");
extern "C" u32 THISCALL ext_5fa220_thiscall2(u32, u32) __asm__("ext_5fa220");
extern "C" u32 THISCALL ext_5fb210_thiscall3(u32, u32, u32) __asm__("ext_5fb210");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_64fc60_thiscall1(u32) __asm__("ext_64fc60");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_563500_cdecl0(void) __asm__("ext_563500");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5c55a0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5c55a0
  eax = ext_5c5620_thiscall1(ecx);  // @1_5c55a0
  ecx = edx = 0;  // @2_5c55a0
  if ((eax & eax) == 0) goto L5c5605;  // @3_5c55a0
  ecx = ebx;  // @4_5c55a0
  eax = ext_5c5810_thiscall1(ecx);  // @5_5c55a0
  ecx = edx = 0;  // @6_5c55a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @7_5c55a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 332), sizeof v); (u32)v; });  // @8_5c55a0
  p0_ = eax;  // @9_5c55a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5c55a0
  p1_ = ecx;  // @11_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(p1_), (u32)(p0_), (u32)(0));  // @12_5c55a0
  ecx = edx = 0;  // @13_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @14_5c55a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @15_5c55a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5c55a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_5c55a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6993692), (u32)(0), (u32)(7029252), (u32)(87), (u32)(0));  // @20_5c55a0
  ecx = edx = 0;  // @21_5c55a0
  eax = (eax & 0xffff);  // @22_5c55a0
  ecx = esi;  // @23_5c55a0
  p2_ = eax;  // @24_5c55a0
  p3_ = esi;  // @25_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 304)))(ecx, (u32)(p3_), (u32)(p2_));  // @26_5c55a0
  ecx = edx = 0;  // @27_5c55a0
  L5c5605:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_5c55a0
  ecx = ebx;  // @30_5c55a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @31_5c55a0
  ecx = edx = 0;  // @32_5c55a0
  return eax;  // @33_5c55a0
}
PCREG(5c55a0, lifted_5c55a0);

extern "C" u32 THISCALL lifted_4cdd50(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4cdd50
  edi = ecx;  // @1_4cdd50
  eax = (eax + (u32)(-8));  // @2_4cdd50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @3_4cdd50
  esi = (u32)(eax + esi*4);  // @4_4cdd50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L4cddb1;  // @5_4cdd50
  eax = ext_41e290_cdecl1((u32)(28));  // @6_4cdd50
  ecx = edx = 0;  // @7_4cdd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @8_4cdd50
  if ((eax & eax) == 0) goto L4cddac;  // @9_4cdd50
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @10_4cdd50
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @12_4cdd50
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @13_4cdd50
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @14_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @15_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @16_4cdd50
  goto L4cddae;  // @17_4cdd50
  L4cddac:;
  eax = 0;  // @19_4cdd50
  L4cddae:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @21_4cdd50
  L4cddb1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 36), sizeof v); (u32)v; });  // @23_4cdd50
  p0_ = esi;  // @24_4cdd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4cdd50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p0_));  // @26_4cdd50
  ecx = edx = 0;  // @27_4cdd50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_4cdd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @29_4cdd50
  if ((ecx & ecx) == 0) goto L4cddc8;  // @30_4cdd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @31_4cdd50
  goto L4cddcb;  // @32_4cdd50
  L4cddc8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @34_4cdd50
  L4cddcb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @36_4cdd50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_4cdd50
  if ((ecx & ecx) == 0) goto L4cddd8;  // @38_4cdd50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @39_4cdd50
  goto L4cdddb;  // @40_4cdd50
  L4cddd8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @42_4cdd50
  L4cdddb:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @44_4cdd50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_4cdd50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @46_4cdd50
  return eax;  // @47_4cdd50
}
PCREG(4cdd50, lifted_4cdd50);

extern "C" u32 THISCALL lifted_43ff00(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ecx;  // @0_43ff00
  eax = ext_45dcd0_thiscall6(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(0));  // @1_43ff00
  ecx = edx = 0;  // @2_43ff00
  ebx = eax;  // @3_43ff00
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }) == (u32)(0)) goto L43ff87;  // @4_43ff00
  if ((ebx & ebx) == 0) goto L43ff87;  // @5_43ff00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @6_43ff00
  if ((esi & esi) == 0) goto L43ff85;  // @7_43ff00
  L43ff30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @9_43ff00
  if ((ecx & ecx) != 0) goto L43ff5c;  // @10_43ff00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_43ff00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_43ff00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6802364), (u32)(419));  // @13_43ff00
  ecx = edx = 0;  // @14_43ff00
  p0_ = eax;  // @15_43ff00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_43ff00
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6802664));  // @17_43ff00
  ecx = edx = 0;  // @18_43ff00
  goto L43ff7d;  // @19_43ff00
  L43ff5c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @21_43ff00
  edx = (u32)(6801640);  // @22_43ff00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_43ff00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @24_43ff00
  p1_ = edi;  // @25_43ff00
  if ((eax & eax) != 0) edx = eax;  // @26_43ff00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_43ff00
  p2_ = edx;  // @28_43ff00
  p3_ = ebx;  // @29_43ff00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 440)))(ecx, (u32)(p3_), (u32)(0), (u32)(p2_), (u32)(p1_), (u32)(1));  // @30_43ff00
  ecx = edx = 0;  // @31_43ff00
  L43ff7d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @33_43ff00
  if ((esi & esi) != 0) goto L43ff30;  // @34_43ff00
  L43ff85:;
  eax = ebx;  // @36_43ff00
  L43ff87:;
  return eax;  // @38_43ff00
}
PCREG(43ff00, lifted_43ff00);

extern "C" u32 THISCALL lifted_41ed40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_41ed40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @1_41ed40
  if ((ecx & ecx) == 0) goto L41edc7;  // @2_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_41ed40
  edx = (u32)(EBP - 12);  // @4_41ed40
  p0_ = edx;  // @5_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_41ed40
  ecx = edx = 0;  // @7_41ed40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @8_41ed40
  edx = (u32)(EBP - 12);  // @9_41ed40
  p1_ = edx;  // @10_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @12_41ed40
  ecx = edx = 0;  // @13_41ed40
  esi = eax;  // @14_41ed40
  if ((esi & esi) == 0) goto L41edb2;  // @15_41ed40
  L41ed70:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_41ed40
  if ((eax & eax) == 0) goto L41ed87;  // @18_41ed40
  p2_ = eax;  // @19_41ed40
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(1));  // @20_41ed40
  ecx = edx = 0;  // @21_41ed40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @22_41ed40
  L41ed87:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @24_41ed40
  if ((eax & eax) == 0) goto L41eda0;  // @25_41ed40
  p3_ = eax;  // @26_41ed40
  eax = ext_634273_cdecl2((u32)(p3_), (u32)(4));  // @27_41ed40
  ecx = edx = 0;  // @28_41ed40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @29_41ed40
  L41eda0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @31_41ed40
  edx = (u32)(EBP - 12);  // @32_41ed40
  p4_ = edx;  // @33_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @35_41ed40
  ecx = edx = 0;  // @36_41ed40
  esi = eax;  // @37_41ed40
  if ((esi & esi) != 0) goto L41ed70;  // @38_41ed40
  L41edb2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @40_41ed40
  if ((ecx & ecx) == 0) goto L41edc0;  // @41_41ed40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_41ed40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @43_41ed40
  ecx = edx = 0;  // @44_41ed40
  L41edc0:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @46_41ed40
  L41edc7:;
  return eax;  // @48_41ed40
}
PCREG(41ed40, lifted_41ed40);

extern "C" u32 THISCALL lifted_5d5b40(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ecx;  // @0_5d5b40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 49), sizeof v); (u32)v; }) == (u32)(0)) goto L5d5b75;  // @1_5d5b40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 45), sizeof v); (u32)v; }) <= (u32)(1)) goto L5d5b6e;  // @2_5d5b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_5d5b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 272)))(ecx, (u32)(16), (u32)(0));  // @4_5d5b40
  ecx = edx = 0;  // @5_5d5b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 37), sizeof v); (u32)v; });  // @6_5d5b40
  if ((ecx & ecx) == 0) goto L5d5b6a;  // @7_5d5b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5d5b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @9_5d5b40
  ecx = edx = 0;  // @10_5d5b40
  L5d5b6a:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @12_5d5b40
  L5d5b6e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 45), &v, sizeof v); }  // @14_5d5b40
  L5d5b75:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @16_5d5b40
  if ((ecx & ecx) == 0) goto L5d5c13;  // @17_5d5b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5d5b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @19_5d5b40
  ecx = edx = 0;  // @20_5d5b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @21_5d5b40
  eax = ext_64fc60_thiscall1(ecx);  // @22_5d5b40
  ecx = edx = 0;  // @23_5d5b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @24_5d5b40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @25_5d5b40
  eax = ext_64fc60_thiscall1(ecx);  // @26_5d5b40
  ecx = edx = 0;  // @27_5d5b40
  if (eax >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 50), sizeof v); (u32)v; })) goto L5d5c0d;  // @28_5d5b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5d5b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @30_5d5b40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_5d5b40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 312)))(ecx);  // @32_5d5b40
  ecx = edx = 0;  // @33_5d5b40
  ecx = (u32)(EBP + 12);  // @34_5d5b40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @35_5d5b40
  p0_ = ecx;  // @36_5d5b40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @37_5d5b40
  ecx = eax;  // @38_5d5b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(7035020), (u32)(p0_));  // @39_5d5b40
  ecx = edx = 0;  // @40_5d5b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_5d5b40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @42_5d5b40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @43_5d5b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @44_5d5b40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_5d5b40
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7035004), (u32)(0), (u32)(7034940), (u32)(152), (u32)(0));  // @46_5d5b40
  ecx = edx = 0;  // @47_5d5b40
  eax = (eax & 0xffff);  // @48_5d5b40
  ecx = ebx;  // @49_5d5b40
  p1_ = eax;  // @50_5d5b40
  p2_ = esi;  // @51_5d5b40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 300)))(ecx, (u32)(p2_), (u32)(p1_));  // @52_5d5b40
  ecx = edx = 0;  // @53_5d5b40
  L5d5c0d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_5d5b40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 50), &v, sizeof v); }  // @56_5d5b40
  L5d5c13:;
  return eax;  // @58_5d5b40
}
PCREG(5d5b40, lifted_5d5b40);

extern "C" u32 THISCALL lifted_425310(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @1_425310
  if ((ecx & ecx) == 0) goto L42539e;  // @2_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_425310
  edx = (u32)(EBP - 12);  // @4_425310
  p0_ = edx;  // @5_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @6_425310
  ecx = edx = 0;  // @7_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @8_425310
  edx = (u32)(EBP - 12);  // @9_425310
  p1_ = edx;  // @10_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @12_425310
  ecx = edx = 0;  // @13_425310
  edi = eax;  // @14_425310
  if ((edi & edi) == 0) goto L425381;  // @15_425310
  L425340:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @17_425310
  if ((edx & edx) == 0) goto L42536f;  // @18_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @19_425310
  p2_ = edx;  // @20_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(p2_));  // @22_425310
  ecx = edx = 0;  // @23_425310
  if ((eax & eax) == 0) goto L425361;  // @24_425310
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 52), &v, sizeof v); }  // @25_425310
  L425361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_425310
  ecx = esi;  // @28_425310
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(21), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }), (u32)(0));  // @29_425310
  ecx = edx = 0;  // @30_425310
  L42536f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @32_425310
  edx = (u32)(EBP - 12);  // @33_425310
  p3_ = edx;  // @34_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @36_425310
  ecx = edx = 0;  // @37_425310
  edi = eax;  // @38_425310
  if ((edi & edi) != 0) goto L425340;  // @39_425310
  L425381:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @41_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_425310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @43_425310
  ecx = edx = 0;  // @44_425310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @45_425310
  if ((ecx & ecx) == 0) goto L425397;  // @46_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_425310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @48_425310
  ecx = edx = 0;  // @49_425310
  L425397:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @51_425310
  L42539e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }) == (u32)(0)) goto L4253b5;  // @53_425310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_425310
  ecx = esi;  // @55_425310
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(22), (u32)(0), (u32)(0));  // @56_425310
  ecx = edx = 0;  // @57_425310
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @58_425310
  L4253b5:;
  return eax;  // @60_425310
}
PCREG(425310, lifted_425310);

extern "C" u32 THISCALL lifted_4d7610(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @0_4d7610
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 17), sizeof v); (u32)v; }) != (u32)(1)) goto L4d7641;  // @1_4d7610
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4d7610
  if ((s32)edx > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; })) edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 9), sizeof v); (u32)v; });  // @3_4d7610
  eax = (eax + (u32)(9));  // @4_4d7610
  p0_ = edx;  // @5_4d7610
  p1_ = eax;  // @6_4d7610
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @7_4d7610
  ecx = edx = 0;  // @8_4d7610
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @9_4d7610
  return eax;  // @10_4d7610
  L4d7641:;
  eax = (eax + (u32)(9));  // @12_4d7610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @13_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @14_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; });  // @15_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @16_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @18_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @19_4d7610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @20_4d7610
  eax = (u32)(EBP - 56);  // @21_4d7610
  p2_ = eax;  // @22_4d7610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @23_4d7610
  eax = ext_62f9d0_stdcall4((u32)(p2_), (u32)(-15), (u32)(6908044), (u32)(56));  // @24_4d7610
  ecx = edx = 0;  // @25_4d7610
  if ((eax & eax) == 0) goto L4d76a8;  // @26_4d7610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @27_4d7610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4d7610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6908196), (u32)(1574));  // @29_4d7610
  ecx = edx = 0;  // @30_4d7610
  p3_ = eax;  // @31_4d7610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_4d7610
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6908824));  // @33_4d7610
  ecx = edx = 0;  // @34_4d7610
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @35_4d7610
  return eax;  // @36_4d7610
  L4d76a8:;
  eax = (u32)(EBP - 56);  // @38_4d7610
  p4_ = eax;  // @39_4d7610
  eax = ext_62f5d0_stdcall2((u32)(p4_), (u32)(4));  // @40_4d7610
  ecx = edx = 0;  // @41_4d7610
  esi = eax;  // @42_4d7610
  eax = (u32)(EBP - 56);  // @43_4d7610
  p5_ = eax;  // @44_4d7610
  eax = ext_62f980_stdcall1((u32)(p5_));  // @45_4d7610
  ecx = edx = 0;  // @46_4d7610
  if (esi == (u32)(1)) goto L4d76d8;  // @47_4d7610
  if (esi != (u32)(-5)) goto L4d76cf;  // @48_4d7610
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; }) == (u32)(0)) goto L4d76d8;  // @49_4d7610
  L4d76cf:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @51_4d7610
  return eax;  // @52_4d7610
  L4d76d8:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @54_4d7610
  return eax;  // @55_4d7610
}
PCREG(4d7610, lifted_4d7610);

extern "C" u32 THISCALL lifted_4a1710(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4a1710
  edi = ecx;  // @1_4a1710
  ecx = 0;  // @2_4a1710
  eax = (u32)(edi + 2052);  // @3_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @4_4a1710
  if ((s32)esi <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4a1760;  // @5_4a1710
  L4a1730:;
  eax = (u32)(eax + 4);  // @7_4a1710
  ecx = (ecx + 1);  // @8_4a1710
  if ((s32)esi > (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4a1730;  // @9_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @10_4a1710
  if (ecx != (u32)(7)) goto L4a1753;  // @11_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2080), sizeof v); (u32)v; });  // @12_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 4), sizeof v); (u32)v; });  // @13_4a1710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @14_4a1710
  goto L4a180b;  // @15_4a1710
  L4a1753:;
  if ((s32)ecx >= (s32)(u32)(7)) goto L4a180b;  // @17_4a1710
  L4a1760:;
  if ((s32)esi >= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2080), sizeof v); (u32)v; })) goto L4a180b;  // @19_4a1710
  eax = 0;  // @20_4a1710
  L4a1770:;
  if ((eax & eax) == 0) goto L4a177e;  // @22_4a1710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 2048), sizeof v); (u32)v; });  // @23_4a1710
  ecx = (ecx + 1);  // @24_4a1710
  goto L4a1780;  // @25_4a1710
  L4a177e:;
  ecx = 0;  // @27_4a1710
  L4a1780:;
  if ((s32)esi < (s32)ecx) goto L4a178d;  // @29_4a1710
  if ((s32)esi <= (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 2052), sizeof v); (u32)v; })) goto L4a17a3;  // @30_4a1710
  L4a178d:;
  eax = (eax + 1);  // @32_4a1710
  if ((s32)eax < (s32)(u32)(8)) goto L4a1770;  // @33_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_4a1710
  if ((eax & eax) == 0) goto L4a17a0;  // @35_4a1710
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @36_4a1710
  ecx = edx = 0;  // @37_4a1710
  goto L4a17a1;  // @38_4a1710
  L4a17a0:;
  __builtin_trap();  // @40_4a1710
  L4a17a1:;
  eax = 0;  // @42_4a1710
  L4a17a3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 2052), sizeof v); (u32)v; });  // @44_4a1710
  ebx = (u32)(edi + eax*4);  // @45_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @46_4a1710
  if (ecx == esi) goto L4a17c9;  // @47_4a1710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 4), sizeof v); (u32)v; });  // @48_4a1710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx*4 + 4), sizeof v); (u32)v; });  // @49_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @50_4a1710
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @51_4a1710
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @52_4a1710
  goto L4a17cc;  // @53_4a1710
  L4a17c9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_4a1710
  L4a17cc:;
  edx = (u32)(eax - 1);  // @57_4a1710
  if ((s32)(edx & edx) <= 0) goto L4a17f5;  // @58_4a1710
  ecx = (u32)(edi + 2052);  // @59_4a1710
  ecx = (u32)(ecx + edx*4);  // @60_4a1710
  L4a17e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4a1710
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2052), sizeof v); (u32)v; })) goto L4a17f5;  // @63_4a1710
  eax = (eax - 1);  // @64_4a1710
  edx = (edx - 1);  // @65_4a1710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @66_4a1710
  ecx = (ecx - (u32)(4));  // @67_4a1710
  if ((s32)(edx & edx) > 0) goto L4a17e0;  // @68_4a1710
  L4a17f5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @70_4a1710
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2052), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(ebx + 2052), &v, sizeof v); }  // @71_4a1710
  ecx = (ecx + 1);  // @72_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @73_4a1710
  if ((s32)ecx < (s32)(u32)(7)) goto L4a1760;  // @74_4a1710
  L4a180b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2080), sizeof v); (u32)v; });  // @76_4a1710
  edx = (u32)(edi + 2080);  // @77_4a1710
  if ((s32)esi >= (s32)ebx) goto L4a182b;  // @78_4a1710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 4), sizeof v); (u32)v; });  // @79_4a1710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ebx*4 + 4), sizeof v); (u32)v; });  // @80_4a1710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 4), &v, sizeof v); }  // @81_4a1710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + ebx*4 + 4), &v, sizeof v); }  // @82_4a1710
  L4a182b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @84_4a1710
  eax = edx;  // @85_4a1710
  L4a1832:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @87_4a1710
  eax = (eax - (u32)(4));  // @88_4a1710
  edx = eax;  // @89_4a1710
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == ecx) goto L4a1832;  // @90_4a1710
  return eax;  // @91_4a1710
}
PCREG(4a1710, lifted_4a1710);

extern "C" u32 STDCALL lifted_601d80(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ext_41e290_cdecl1((u32)(42));  // @0_601d80
  ecx = edx = 0;  // @1_601d80
  esi = eax;  // @2_601d80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601d80
  reg.state = (s32)((u32)(0));  // @4_601d80
  if ((esi & esi) == 0) goto L601df0;  // @5_601d80
  ecx = esi;  // @6_601d80
  eax = ext_603500_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_601d80
  ecx = edx = 0;  // @8_601d80
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_601d80
  eax = (u32)(esi + 12);  // @10_601d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @11_601d80
  eax = 0;  // @12_601d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @13_601d80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @14_601d80
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @15_601d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @16_601d80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @17_601d80
  goto L601df2;  // @18_601d80
  L601df0:;
  esi = 0;  // @20_601d80
  L601df2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_601d80
  ecx = esi;  // @23_601d80
  reg.state = (s32)((u32)(4294967295));  // @24_601d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @25_601d80
  ecx = edx = 0;  // @26_601d80
  eax = esi;  // @27_601d80
  SEH_LEAVE();  // @28_601d80
  return eax;  // @29_601d80
}
PCREG(601d80, lifted_601d80);

extern "C" u32 THISCALL lifted_49a240(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66825f);  // @h_49a240
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_49a240
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; }) != (u32)(0)) goto L49a2a6;  // @1_49a240
  eax = ext_41e290_cdecl1((u32)(28));  // @2_49a240
  ecx = edx = 0;  // @3_49a240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_49a240
  reg.state = (s32)((u32)(0));  // @5_49a240
  if ((eax & eax) == 0) goto L49a297;  // @6_49a240
  ecx = eax;  // @7_49a240
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(2));  // @8_49a240
  ecx = edx = 0;  // @9_49a240
  goto L49a299;  // @10_49a240
  L49a297:;
  eax = 0;  // @12_49a240
  L49a299:;
  reg.state = (s32)((u32)(4294967295));  // @14_49a240
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 312), &v, sizeof v); }  // @15_49a240
  L49a2a6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @17_49a240
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_49a240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @19_49a240
  ecx = edx = 0;  // @20_49a240
  ecx = eax;  // @21_49a240
  if ((ecx & ecx) != 0) goto L49a2d8;  // @22_49a240
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 312), sizeof v); (u32)v; });  // @23_49a240
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_49a240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @25_49a240
  ecx = edx = 0;  // @26_49a240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @27_49a240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @28_49a240
  ecx = (u32)(eax - 4);  // @29_49a240
  L49a2d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_49a240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @32_49a240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @33_49a240
  SEH_LEAVE();  // @34_49a240
  return eax;  // @35_49a240
}
PCREG(49a240, lifted_49a240);

extern "C" u32 THISCALL lifted_449ed0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_449ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_449ed0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L449f2e;  // @1_449ed0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_449ed0
  ecx = edx = 0;  // @3_449ed0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_449ed0
  reg.state = (s32)((u32)(0));  // @5_449ed0
  if ((eax & eax) == 0) goto L449f22;  // @6_449ed0
  ecx = eax;  // @7_449ed0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @8_449ed0
  ecx = edx = 0;  // @9_449ed0
  goto L449f24;  // @10_449ed0
  L449f22:;
  eax = 0;  // @12_449ed0
  L449f24:;
  reg.state = (s32)((u32)(4294967295));  // @14_449ed0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @15_449ed0
  L449f2e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @17_449ed0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_449ed0
  p0_ = edi;  // @19_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(p0_));  // @21_449ed0
  ecx = edx = 0;  // @22_449ed0
  if ((eax & eax) != 0) goto L449f47;  // @23_449ed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @24_449ed0
  p1_ = edi;  // @25_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @27_449ed0
  ecx = edx = 0;  // @28_449ed0
  L449f47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_449ed0
  ecx = esi;  // @31_449ed0
  p2_ = edi;  // @32_449ed0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 560)))(ecx, (u32)(p2_), (u32)(1));  // @33_449ed0
  ecx = edx = 0;  // @34_449ed0
  SEH_LEAVE();  // @35_449ed0
  return eax;  // @36_449ed0
}
PCREG(449ed0, lifted_449ed0);

extern "C" u32 THISCALL lifted_453b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_453b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_453b50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; }) != (u32)(0)) goto L453bae;  // @1_453b50
  eax = ext_41e290_cdecl1((u32)(28));  // @2_453b50
  ecx = edx = 0;  // @3_453b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_453b50
  reg.state = (s32)((u32)(0));  // @5_453b50
  if ((eax & eax) == 0) goto L453ba2;  // @6_453b50
  ecx = eax;  // @7_453b50
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @8_453b50
  ecx = edx = 0;  // @9_453b50
  goto L453ba4;  // @10_453b50
  L453ba2:;
  eax = 0;  // @12_453b50
  L453ba4:;
  reg.state = (s32)((u32)(4294967295));  // @14_453b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @15_453b50
  L453bae:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; });  // @17_453b50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_453b50
  p0_ = edi;  // @19_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(p0_));  // @21_453b50
  ecx = edx = 0;  // @22_453b50
  if ((eax & eax) != 0) goto L453bd8;  // @23_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 82), sizeof v); (u32)v; });  // @24_453b50
  p1_ = edi;  // @25_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p1_));  // @27_453b50
  ecx = edx = 0;  // @28_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_453b50
  p2_ = edi;  // @30_453b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_453b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_453b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(p2_));  // @33_453b50
  ecx = edx = 0;  // @34_453b50
  L453bd8:;
  SEH_LEAVE();  // @36_453b50
  return eax;  // @37_453b50
}
PCREG(453b50, lifted_453b50);

extern "C" u32 THISCALL lifted_435920(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66588e);  // @h_435920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_435920
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L43597d;  // @1_435920
  eax = ext_41e290_cdecl1((u32)(40));  // @2_435920
  ecx = edx = 0;  // @3_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_435920
  reg.state = (s32)((u32)(0));  // @5_435920
  if ((eax & eax) == 0) goto L435971;  // @6_435920
  ecx = eax;  // @7_435920
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(1));  // @8_435920
  ecx = edx = 0;  // @9_435920
  goto L435973;  // @10_435920
  L435971:;
  eax = 0;  // @12_435920
  L435973:;
  reg.state = (s32)((u32)(4294967295));  // @14_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_435920
  L43597d:;
  eax = ext_41e290_cdecl1((u32)(21));  // @17_435920
  ecx = edx = 0;  // @18_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @19_435920
  reg.state = (s32)((u32)(1));  // @20_435920
  if ((eax & eax) == 0) goto L4359a6;  // @21_435920
  ecx = eax;  // @22_435920
  eax = ext_4d4c90_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @23_435920
  ecx = edx = 0;  // @24_435920
  edx = eax;  // @25_435920
  goto L4359a8;  // @26_435920
  L4359a6:;
  edx = 0;  // @28_435920
  L4359a8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @30_435920
  p0_ = edx;  // @31_435920
  reg.state = (s32)((u32)(4294967295));  // @32_435920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_435920
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p0_));  // @34_435920
  ecx = edx = 0;  // @35_435920
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @36_435920
  SEH_LEAVE();  // @37_435920
  return eax;  // @38_435920
}
PCREG(435920, lifted_435920);

extern "C" u32 THISCALL lifted_465660(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_465660
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_465660
  { u32 v = (u32)((u32)(6838980)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @4_465660
  if ((ecx & ecx) == 0) goto L4656df;  // @5_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_465660
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @7_465660
  ecx = edx = 0;  // @8_465660
  ebx = eax;  // @9_465660
  if ((ebx & ebx) == 0) goto L4656df;  // @10_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_465660
  p0_ = edi;  // @12_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @13_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(p0_));  // @15_465660
  ecx = edx = 0;  // @16_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_465660
  esi = eax;  // @18_465660
  p1_ = esi;  // @19_465660
  ecx = ebx;  // @20_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 556)))(ecx, (u32)(p1_));  // @21_465660
  ecx = edx = 0;  // @22_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @23_465660
  p2_ = esi;  // @24_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(p2_));  // @26_465660
  ecx = edx = 0;  // @27_465660
  L4656df:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 462), sizeof v); (u32)v; });  // @29_465660
  if ((ecx & ecx) == 0) goto L4656ef;  // @30_465660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @32_465660
  ecx = edx = 0;  // @33_465660
  L4656ef:;
  ecx = edi;  // @35_465660
  eax = ext_460f90_thiscall1(ecx);  // @36_465660
  ecx = edx = 0;  // @37_465660
  SEH_LEAVE();  // @38_465660
  return eax;  // @39_465660
}
PCREG(465660, lifted_465660);

extern "C" u32 THISCALL lifted_444df0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66825f);  // @h_444df0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_444df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @1_444df0
  if ((ecx & ecx) != 0) goto L444e63;  // @2_444df0
  eax = ext_41e290_cdecl1((u32)(28));  // @3_444df0
  ecx = edx = 0;  // @4_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_444df0
  reg.state = (s32)((u32)(0));  // @6_444df0
  if ((eax & eax) == 0) goto L444e52;  // @7_444df0
  ecx = eax;  // @8_444df0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @9_444df0
  ecx = edx = 0;  // @10_444df0
  reg.state = (s32)((u32)(4294967295));  // @11_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @12_444df0
  goto L444e6f;  // @13_444df0
  L444e52:;
  eax = 0;  // @15_444df0
  reg.state = (s32)((u32)(4294967295));  // @16_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @17_444df0
  goto L444e6f;  // @18_444df0
  L444e63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @21_444df0
  ecx = edx = 0;  // @22_444df0
  if ((eax & eax) != 0) goto L444e9c;  // @23_444df0
  L444e6f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @25_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @27_444df0
  ecx = edx = 0;  // @28_444df0
  L444e80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @30_444df0
  eax = ext_4dc630_thiscall3(ecx, (u32)(4194304), (u32)(0));  // @31_444df0
  ecx = edx = 0;  // @32_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_444df0
  ecx = esi;  // @34_444df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @35_444df0
  ecx = edx = 0;  // @36_444df0
  esi = eax;  // @37_444df0
  if ((esi & esi) != 0) goto L444e80;  // @38_444df0
  L444e9c:;
  SEH_LEAVE();  // @40_444df0
  return eax;  // @41_444df0
}
PCREG(444df0, lifted_444df0);

extern "C" u32 THISCALL lifted_441d90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_441d90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_441d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; }) != (u32)(0)) goto L441dee;  // @1_441d90
  eax = ext_41e290_cdecl1((u32)(28));  // @2_441d90
  ecx = edx = 0;  // @3_441d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_441d90
  reg.state = (s32)((u32)(0));  // @5_441d90
  if ((eax & eax) == 0) goto L441de2;  // @6_441d90
  ecx = eax;  // @7_441d90
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @8_441d90
  ecx = edx = 0;  // @9_441d90
  goto L441de4;  // @10_441d90
  L441de2:;
  eax = 0;  // @12_441d90
  L441de4:;
  reg.state = (s32)((u32)(4294967295));  // @14_441d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @15_441d90
  L441dee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @17_441d90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_441d90
  p0_ = edi;  // @19_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_441d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p0_));  // @21_441d90
  ecx = edx = 0;  // @22_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_441d90
  ecx = edi;  // @24_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @25_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @26_441d90
  ecx = edx = 0;  // @27_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e12;  // @28_441d90
  p1_ = edi;  // @29_441d90
  ecx = esi;  // @30_441d90
  eax = ext_442050_thiscall2(ecx, (u32)(p1_));  // @31_441d90
  ecx = edx = 0;  // @32_441d90
  L441e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_441d90
  ecx = edi;  // @35_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @36_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @37_441d90
  ecx = edx = 0;  // @38_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e2a;  // @39_441d90
  p2_ = edi;  // @40_441d90
  ecx = esi;  // @41_441d90
  eax = ext_441e40_thiscall2(ecx, (u32)(p2_));  // @42_441d90
  ecx = edx = 0;  // @43_441d90
  L441e2a:;
  SEH_LEAVE();  // @45_441d90
  return eax;  // @46_441d90
}
PCREG(441d90, lifted_441d90);

extern "C" u32 THISCALL lifted_5082c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66428b);  // @h_5082c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @2_5082c0
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_5082c0
  ecx = edx = 0;  // @4_5082c0
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @5_5082c0
  edx = (edx - (u32)(3));  // @6_5082c0
  if (edx == 0) goto L50834e;  // @7_5082c0
  edx = (edx - (u32)(1));  // @8_5082c0
  if (edx == 0) goto L508345;  // @9_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(273));  // @12_5082c0
  ecx = edx = 0;  // @13_5082c0
  p0_ = eax;  // @14_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_5082c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p0_), (u32)(6932144), (u32)(6932912));  // @16_5082c0
  ecx = edx = 0;  // @17_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_5082c0
  if ((eax & eax) == 0) goto L508340;  // @19_5082c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_5082c0
  ecx = edx = 0;  // @21_5082c0
  eax = 0;  // @22_5082c0
  goto L508350;  // @23_5082c0
  L508340:;
  __builtin_trap();  // @25_5082c0
  L508345:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_5082c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5082c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @29_5082c0
  ecx = edx = 0;  // @30_5082c0
  goto L508350;  // @31_5082c0
  L50834e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_5082c0
  L508350:;
  p1_ = eax;  // @35_5082c0
  ecx = (u32)(EBP - 144);  // @36_5082c0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @37_5082c0
  ecx = edx = 0;  // @38_5082c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @39_5082c0
  eax = (u32)(EBP - 144);  // @40_5082c0
  p2_ = eax;  // @41_5082c0
  ecx = (ecx + (u32)(1042));  // @42_5082c0
  reg.state = (s32)((u32)(0));  // @43_5082c0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @44_5082c0
  ecx = edx = 0;  // @45_5082c0
  ecx = (u32)(EBP - 144);  // @46_5082c0
  eax = ext_4cbec0_thiscall1(ecx);  // @47_5082c0
  ecx = edx = 0;  // @48_5082c0
  SEH_LEAVE();  // @49_5082c0
  ext_633654(G(u32, 0x6f5630));  // @50_5082c0
  return eax;  // @51_5082c0
}
PCREG(5082c0, lifted_5082c0);

extern "C" u32 THISCALL lifted_4d8fc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d1b);  // @h_4d8fc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4d8fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d8fc0
  ecx = (u32)(EBP - 144);  // @2_4d8fc0
  p0_ = eax;  // @3_4d8fc0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_4d8fc0
  ecx = edx = 0;  // @5_4d8fc0
  ecx = (u32)(EBP - 144);  // @6_4d8fc0
  reg.state = (s32)((u32)(0));  // @7_4d8fc0
  eax = ext_4cc690_thiscall1(ecx);  // @8_4d8fc0
  ecx = edx = 0;  // @9_4d8fc0
  ecx = (u32)(EBP - 144);  // @10_4d8fc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @11_4d8fc0
  ecx = edx = 0;  // @12_4d8fc0
  edi = eax;  // @13_4d8fc0
  esi = edi;  // @14_4d8fc0
  eax = (u32)(esi + 1);  // @15_4d8fc0
  L4d9023:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @17_4d8fc0
  esi = (esi + 1);  // @18_4d8fc0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L4d9023;  // @19_4d8fc0
  esi = (esi - eax);  // @20_4d8fc0
  ecx = ebx;  // @21_4d8fc0
  p1_ = esi;  // @22_4d8fc0
  p2_ = edi;  // @23_4d8fc0
  eax = ext_4d8db0_stdcall2((u32)(p2_), (u32)(p1_));  // @24_4d8fc0
  ecx = edx = 0;  // @25_4d8fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4d8fc0
  p3_ = eax;  // @27_4d8fc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4d8fc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, (u32)(p3_));  // @29_4d8fc0
  ecx = edx = 0;  // @30_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @31_4d8fc0
  p4_ = esi;  // @32_4d8fc0
  p5_ = edi;  // @33_4d8fc0
  p6_ = eax;  // @34_4d8fc0
  ecx = ebx;  // @35_4d8fc0
  eax = ext_4d8ef0_stdcall3((u32)(p6_), (u32)(p5_), (u32)(p4_));  // @36_4d8fc0
  ecx = edx = 0;  // @37_4d8fc0
  if ((eax & eax) == 0) goto L4d9054;  // @38_4d8fc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @39_4d8fc0
  goto L4d9056;  // @40_4d8fc0
  L4d9054:;
  esi = 0;  // @42_4d8fc0
  L4d9056:;
  ecx = (u32)(EBP - 144);  // @44_4d8fc0
  eax = ext_4cbec0_thiscall1(ecx);  // @45_4d8fc0
  ecx = edx = 0;  // @46_4d8fc0
  eax = esi;  // @47_4d8fc0
  SEH_LEAVE();  // @48_4d8fc0
  ext_633654(G(u32, 0x6f5630));  // @49_4d8fc0
  return eax;  // @50_4d8fc0
}
PCREG(4d8fc0, lifted_4d8fc0);

extern "C" u32 THISCALL lifted_4afc70(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4afc70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4afc70
  eax = (u32)(EBP - 148);  // @1_4afc70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_4afc70
  p0_ = eax;  // @3_4afc70
  eax = ext_6352f0_thiscall2(ecx, (u32)(p0_));  // @4_4afc70
  ecx = edx = 0;  // @5_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_4afc70
  ecx = (u32)(EBP - 148);  // @7_4afc70
  p1_ = ecx;  // @8_4afc70
  ecx = ebx;  // @9_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p1_));  // @10_4afc70
  ecx = edx = 0;  // @11_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @12_4afc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L4afd33;  // @13_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2305));  // @16_4afc70
  ecx = edx = 0;  // @17_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @18_4afc70
  edi = eax;  // @19_4afc70
  eax = (u32)(EBP - 144);  // @20_4afc70
  p2_ = eax;  // @21_4afc70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p2_), (u32)(1));  // @23_4afc70
  ecx = edx = 0;  // @24_4afc70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4afc70
  ecx = eax;  // @26_4afc70
  reg.state = (s32)((u32)(0));  // @27_4afc70
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_4afc70
  ecx = edx = 0;  // @29_4afc70
  p3_ = eax;  // @30_4afc70
  p4_ = edi;  // @31_4afc70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p4_), (u32)(6890728), (u32)(p3_));  // @32_4afc70
  ecx = edx = 0;  // @33_4afc70
  ecx = (u32)(EBP - 144);  // @34_4afc70
  eax = ext_4cbec0_thiscall1(ecx);  // @35_4afc70
  ecx = edx = 0;  // @36_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @37_4afc70
  if ((ecx & ecx) == 0) goto L4afd33;  // @38_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @40_4afc70
  ecx = edx = 0;  // @41_4afc70
  L4afd33:;
  SEH_LEAVE();  // @43_4afc70
  ext_633654(G(u32, 0x6f5630));  // @44_4afc70
  return eax;  // @45_4afc70
}
PCREG(4afc70, lifted_4afc70);

extern "C" u32 THISCALL lifted_53b2a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66aa2b);  // @h_53b2a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_53b2a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_53b2a0
  ecx = (u32)(EBP - 188);  // @2_53b2a0
  eax = ext_4ccba0_thiscall1(ecx);  // @3_53b2a0
  ecx = edx = 0;  // @4_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_53b2a0
  reg.state = (s32)((u32)(0));  // @6_53b2a0
  if ((ecx & ecx) == 0) goto L53b344;  // @7_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_53b2a0
  edx = (u32)(EBP - 200);  // @9_53b2a0
  p0_ = edx;  // @10_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p0_));  // @11_53b2a0
  ecx = edx = 0;  // @12_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @13_53b2a0
  edx = (u32)(EBP - 200);  // @14_53b2a0
  p1_ = edx;  // @15_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p1_));  // @17_53b2a0
  ecx = edx = 0;  // @18_53b2a0
  edx = eax;  // @19_53b2a0
  if ((edx & edx) == 0) goto L53b344;  // @20_53b2a0
  L53b310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @25_53b2a0
  ecx = edx = 0;  // @26_53b2a0
  p2_ = eax;  // @27_53b2a0
  ecx = (u32)(EBP - 188);  // @28_53b2a0
  eax = ext_4cd540_thiscall2(ecx, (u32)(p2_));  // @29_53b2a0
  ecx = edx = 0;  // @30_53b2a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @31_53b2a0
  edx = (u32)(EBP - 200);  // @32_53b2a0
  p3_ = edx;  // @33_53b2a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p3_));  // @35_53b2a0
  ecx = edx = 0;  // @36_53b2a0
  edx = eax;  // @37_53b2a0
  if ((edx & edx) != 0) goto L53b310;  // @38_53b2a0
  L53b344:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_53b2a0
  ecx = (u32)(EBP - 188);  // @41_53b2a0
  p4_ = ecx;  // @42_53b2a0
  ecx = edi;  // @43_53b2a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p4_));  // @44_53b2a0
  ecx = edx = 0;  // @45_53b2a0
  ecx = (u32)(EBP - 188);  // @46_53b2a0
  eax = ext_4ccf60_thiscall1(ecx);  // @47_53b2a0
  ecx = edx = 0;  // @48_53b2a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @49_53b2a0
  SEH_LEAVE();  // @50_53b2a0
  ext_633654(G(u32, 0x6f5630));  // @51_53b2a0
  return eax;  // @52_53b2a0
}
PCREG(53b2a0, lifted_53b2a0);

extern "C" u32 THISCALL lifted_42d820(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664efc);  // @h_42d820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_42d820
  ecx = (u32)(EBP - 532);  // @2_42d820
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_42d820
  p0_ = ecx;  // @4_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @5_42d820
  ecx = esi;  // @6_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @7_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @8_42d820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789660), (u32)(p0_));  // @9_42d820
  ecx = edx = 0;  // @10_42d820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42d8f5;  // @11_42d820
  ecx = (u32)(EBP - 272);  // @12_42d820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; }));  // @13_42d820
  ecx = edx = 0;  // @14_42d820
  ecx = (u32)(EBP - 144);  // @15_42d820
  reg.state = (s32)((u32)(0));  // @16_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789668));  // @17_42d820
  ecx = edx = 0;  // @18_42d820
  eax = (u32)(EBP - 144);  // @19_42d820
  reg.state = (s32)((u32)(1));  // @20_42d820
  p1_ = eax;  // @21_42d820
  eax = (u32)(EBP - 528);  // @22_42d820
  p2_ = eax;  // @23_42d820
  ecx = (u32)(esi + 291);  // @24_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p2_), (u32)(p1_));  // @25_42d820
  ecx = edx = 0;  // @26_42d820
  ecx = (u32)(EBP - 272);  // @27_42d820
  reg.state = (s32)((u32)(2));  // @28_42d820
  p3_ = ecx;  // @29_42d820
  p4_ = edi;  // @30_42d820
  ecx = eax;  // @31_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p4_), (u32)(p3_));  // @32_42d820
  ecx = edx = 0;  // @33_42d820
  ecx = (u32)(EBP - 528);  // @34_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @35_42d820
  ecx = edx = 0;  // @36_42d820
  ecx = (u32)(EBP - 144);  // @37_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @38_42d820
  ecx = edx = 0;  // @39_42d820
  ecx = (u32)(EBP - 272);  // @40_42d820
  goto L42d925;  // @41_42d820
  L42d8f5:;
  ecx = (u32)(EBP - 400);  // @43_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789660));  // @44_42d820
  ecx = edx = 0;  // @45_42d820
  eax = (u32)(EBP - 400);  // @46_42d820
  reg.state = (s32)((u32)(3));  // @47_42d820
  p5_ = eax;  // @48_42d820
  p6_ = edi;  // @49_42d820
  ecx = (u32)(esi + 291);  // @50_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(p6_), (u32)(p5_));  // @51_42d820
  ecx = edx = 0;  // @52_42d820
  ecx = (u32)(EBP - 400);  // @53_42d820
  L42d925:;
  eax = ext_4cbec0_thiscall1(ecx);  // @55_42d820
  ecx = edx = 0;  // @56_42d820
  eax = edi;  // @57_42d820
  SEH_LEAVE();  // @58_42d820
  ext_633654(G(u32, 0x6f5630));  // @59_42d820
  return eax;  // @60_42d820
}
PCREG(42d820, lifted_42d820);

extern "C" u32 THISCALL lifted_4346e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4346e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4346e0
  ecx = (u32)(EBP - 144);  // @2_4346e0
  p0_ = eax;  // @3_4346e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @4_4346e0
  ecx = edx = 0;  // @5_4346e0
  ecx = (u32)(EBP - 144);  // @6_4346e0
  reg.state = (s32)((u32)(0));  // @7_4346e0
  esi = 0;  // @8_4346e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @9_4346e0
  ecx = edx = 0;  // @10_4346e0
  if ((eax & eax) == 0) goto L434770;  // @11_4346e0
  L434740:;
  ecx = (u32)(EBP - 144);  // @13_4346e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @14_4346e0
  ecx = edx = 0;  // @15_4346e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L434760;  // @16_4346e0
  ecx = (u32)(EBP - 144);  // @17_4346e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @18_4346e0
  ecx = edx = 0;  // @19_4346e0
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @20_4346e0
  L434760:;
  ecx = (u32)(EBP - 144);  // @22_4346e0
  esi = (esi + 1);  // @23_4346e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @24_4346e0
  ecx = edx = 0;  // @25_4346e0
  if (esi != eax) goto L434740;  // @26_4346e0
  L434770:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @28_4346e0
  if ((ecx & ecx) == 0) goto L4347cd;  // @29_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4346e0
  edx = (u32)(EBP - 156);  // @31_4346e0
  p1_ = edx;  // @32_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @33_4346e0
  ecx = edx = 0;  // @34_4346e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @35_4346e0
  edx = (u32)(EBP - 156);  // @36_4346e0
  p2_ = edx;  // @37_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @39_4346e0
  ecx = edx = 0;  // @40_4346e0
  if ((eax & eax) == 0) goto L4347cd;  // @41_4346e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @42_4346e0
  L4347a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_4346e0
  ecx = (u32)(EBP - 144);  // @45_4346e0
  eax = ext_4cc1d0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13), sizeof v); (u32)v; }));  // @46_4346e0
  ecx = edx = 0;  // @47_4346e0
  p3_ = eax;  // @48_4346e0
  eax = ((u32(STDCALL *)(u32))(esi))((u32)(p3_));  // @49_4346e0
  ecx = edx = 0;  // @50_4346e0
  if ((eax & eax) == 0) goto L4347fa;  // @51_4346e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @52_4346e0
  edx = (u32)(EBP - 156);  // @53_4346e0
  p4_ = edx;  // @54_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @56_4346e0
  ecx = edx = 0;  // @57_4346e0
  if ((eax & eax) != 0) goto L4347a0;  // @58_4346e0
  L4347cd:;
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @60_4346e0
  L4347cf:;
  ecx = (u32)(EBP - 144);  // @62_4346e0
  eax = ext_4cbec0_thiscall1(ecx);  // @63_4346e0
  ecx = edx = 0;  // @64_4346e0
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @65_4346e0
  SEH_LEAVE();  // @66_4346e0
  ext_633654(G(u32, 0x6f5630));  // @67_4346e0
  return eax;  // @68_4346e0
  L4347fa:;
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_4346e0
  goto L4347cf;  // @71_4346e0
}
PCREG(4346e0, lifted_4346e0);

extern "C" u32 THISCALL lifted_4356e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4356e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4356e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4357df;  // @2_4356e0
  p0_ = eax;  // @3_4356e0
  ecx = (u32)(EBP - 144);  // @4_4356e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @5_4356e0
  ecx = edx = 0;  // @6_4356e0
  ecx = (u32)(EBP - 144);  // @7_4356e0
  reg.state = (s32)((u32)(0));  // @8_4356e0
  esi = 0;  // @9_4356e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_4356e0
  ecx = edx = 0;  // @11_4356e0
  if ((eax & eax) == 0) goto L435771;  // @12_4356e0
  L435741:;
  ecx = (u32)(EBP - 144);  // @14_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_4356e0
  ecx = edx = 0;  // @16_4356e0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L435761;  // @17_4356e0
  ecx = (u32)(EBP - 144);  // @18_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_4356e0
  ecx = edx = 0;  // @20_4356e0
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @21_4356e0
  L435761:;
  ecx = (u32)(EBP - 144);  // @23_4356e0
  esi = (esi + 1);  // @24_4356e0
  eax = ext_4cc5f0_thiscall1(ecx);  // @25_4356e0
  ecx = edx = 0;  // @26_4356e0
  if (esi != eax) goto L435741;  // @27_4356e0
  L435771:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @29_4356e0
  if ((ecx & ecx) == 0) goto L4357d4;  // @30_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4356e0
  edx = (u32)(EBP - 156);  // @32_4356e0
  p1_ = edx;  // @33_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @34_4356e0
  ecx = edx = 0;  // @35_4356e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_4356e0
  edx = (u32)(EBP - 156);  // @37_4356e0
  p2_ = edx;  // @38_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @40_4356e0
  ecx = edx = 0;  // @41_4356e0
  if ((eax & eax) == 0) goto L4357d4;  // @42_4356e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @43_4356e0
  L4357a0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_4356e0
  ecx = (u32)(EBP - 144);  // @46_4356e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_4356e0
  ecx = edx = 0;  // @48_4356e0
  p3_ = eax;  // @49_4356e0
  eax = ((u32( *)(u32, u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; }), (u32)(p3_));  // @50_4356e0
  ecx = edx = 0;  // @51_4356e0
  if ((eax & eax) != 0) goto L4357c1;  // @52_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_4356e0
  ecx = esi;  // @54_4356e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @55_4356e0
  ecx = edx = 0;  // @56_4356e0
  L4357c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @58_4356e0
  edx = (u32)(EBP - 156);  // @59_4356e0
  p4_ = edx;  // @60_4356e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_4356e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @62_4356e0
  ecx = edx = 0;  // @63_4356e0
  if ((eax & eax) != 0) goto L4357a0;  // @64_4356e0
  L4357d4:;
  ecx = (u32)(EBP - 144);  // @66_4356e0
  eax = ext_4cbec0_thiscall1(ecx);  // @67_4356e0
  ecx = edx = 0;  // @68_4356e0
  L4357df:;
  SEH_LEAVE();  // @70_4356e0
  ext_633654(G(u32, 0x6f5630));  // @71_4356e0
  return eax;  // @72_4356e0
}
PCREG(4356e0, lifted_4356e0);

extern "C" u32 THISCALL lifted_435800(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_435800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435800
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4358ff;  // @2_435800
  p0_ = eax;  // @3_435800
  ecx = (u32)(EBP - 144);  // @4_435800
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @5_435800
  ecx = edx = 0;  // @6_435800
  ecx = (u32)(EBP - 144);  // @7_435800
  reg.state = (s32)((u32)(0));  // @8_435800
  esi = 0;  // @9_435800
  eax = ext_4cc5f0_thiscall1(ecx);  // @10_435800
  ecx = edx = 0;  // @11_435800
  if ((eax & eax) == 0) goto L435891;  // @12_435800
  L435861:;
  ecx = (u32)(EBP - 144);  // @14_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_435800
  ecx = edx = 0;  // @16_435800
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L435881;  // @17_435800
  ecx = (u32)(EBP - 144);  // @18_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_435800
  ecx = edx = 0;  // @20_435800
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @21_435800
  L435881:;
  ecx = (u32)(EBP - 144);  // @23_435800
  esi = (esi + 1);  // @24_435800
  eax = ext_4cc5f0_thiscall1(ecx);  // @25_435800
  ecx = edx = 0;  // @26_435800
  if (esi != eax) goto L435861;  // @27_435800
  L435891:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @29_435800
  if ((ecx & ecx) == 0) goto L4358f4;  // @30_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_435800
  edx = (u32)(EBP - 156);  // @32_435800
  p1_ = edx;  // @33_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p1_));  // @34_435800
  ecx = edx = 0;  // @35_435800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_435800
  edx = (u32)(EBP - 156);  // @37_435800
  p2_ = edx;  // @38_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p2_));  // @40_435800
  ecx = edx = 0;  // @41_435800
  if ((eax & eax) == 0) goto L4358f4;  // @42_435800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @43_435800
  L4358c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_435800
  ecx = (u32)(EBP - 144);  // @46_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_435800
  ecx = edx = 0;  // @48_435800
  p3_ = eax;  // @49_435800
  eax = ((u32( *)(u32, u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; }), (u32)(p3_));  // @50_435800
  ecx = edx = 0;  // @51_435800
  if ((eax & eax) != 0) goto L4358e1;  // @52_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_435800
  ecx = esi;  // @54_435800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @55_435800
  ecx = edx = 0;  // @56_435800
  L4358e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @58_435800
  edx = (u32)(EBP - 156);  // @59_435800
  p4_ = edx;  // @60_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(p4_));  // @62_435800
  ecx = edx = 0;  // @63_435800
  if ((eax & eax) != 0) goto L4358c0;  // @64_435800
  L4358f4:;
  ecx = (u32)(EBP - 144);  // @66_435800
  eax = ext_4cbec0_thiscall1(ecx);  // @67_435800
  ecx = edx = 0;  // @68_435800
  L4358ff:;
  SEH_LEAVE();  // @70_435800
  ext_633654(G(u32, 0x6f5630));  // @71_435800
  return eax;  // @72_435800
}
PCREG(435800, lifted_435800);

extern "C" u32 THISCALL lifted_4f91f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669acb);  // @h_4f91f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4f91f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @1_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4f91f0
  ecx = (u32)(EBP - 144);  // @3_4f91f0
  p0_ = esi;  // @4_4f91f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @5_4f91f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @6_4f91f0
  ecx = edx = 0;  // @7_4f91f0
  eax = (u32)(edi + 143);  // @8_4f91f0
  reg.state = (s32)((u32)(0));  // @9_4f91f0
  ecx = (u32)(EBP - 144);  // @10_4f91f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @11_4f91f0
  p1_ = ecx;  // @12_4f91f0
  ecx = eax;  // @13_4f91f0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @14_4f91f0
  ecx = edx = 0;  // @15_4f91f0
  ecx = (u32)(EBP - 144);  // @16_4f91f0
  reg.state = (s32)((u32)(4294967295));  // @17_4f91f0
  eax = ext_4cbec0_thiscall1(ecx);  // @18_4f91f0
  ecx = edx = 0;  // @19_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 271), sizeof v); (u32)v; });  // @20_4f91f0
  ecx = (u32)(edi + 271);  // @21_4f91f0
  ebx = 0;  // @22_4f91f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @23_4f91f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @24_4f91f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @25_4f91f0
  ecx = edx = 0;  // @26_4f91f0
  if ((s32)(eax & eax) <= 0) goto L4f92f6;  // @27_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @28_4f91f0
  L4f9295:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4f91f0
  ecx = esi;  // @31_4f91f0
  p2_ = ebx;  // @32_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_4f91f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @35_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(p2_));  // @36_4f91f0
  ecx = edx = 0;  // @37_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_4f91f0
  p3_ = eax;  // @39_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @40_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 88)))(ecx, (u32)(p3_));  // @41_4f91f0
  ecx = edx = 0;  // @42_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @43_4f91f0
  edi = eax;  // @44_4f91f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_4f91f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_4f91f0
  ecx = edx = 0;  // @47_4f91f0
  p4_ = eax;  // @48_4f91f0
  ecx = edi;  // @49_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(ebx + 644)))(ecx, (u32)(p4_));  // @50_4f91f0
  ecx = edx = 0;  // @51_4f91f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @52_4f91f0
  ecx = esi;  // @53_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4f91f0
  ebx = (ebx + 1);  // @55_4f91f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @56_4f91f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @57_4f91f0
  ecx = edx = 0;  // @58_4f91f0
  if ((s32)ebx < (s32)eax) goto L4f9295;  // @59_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @60_4f91f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @61_4f91f0
  L4f92f6:;
  ecx = (u32)(esi + 1);  // @63_4f91f0
  L4f9300:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @65_4f91f0
  esi = (esi + 1);  // @66_4f91f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4f9300;  // @67_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @68_4f91f0
  esi = (esi - ecx);  // @69_4f91f0
  p5_ = esi;  // @70_4f91f0
  ecx = edi;  // @71_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 868)))(ecx, (u32)(p5_));  // @72_4f91f0
  ecx = edx = 0;  // @73_4f91f0
  SEH_LEAVE();  // @74_4f91f0
  ext_633654(G(u32, 0x6f5630));  // @75_4f91f0
  return eax;  // @76_4f91f0
}
PCREG(4f91f0, lifted_4f91f0);

extern "C" u32 THISCALL lifted_497750(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66818f);  // @h_497750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  edi = ecx;  // @0_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @1_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(2138367));  // @3_497750
  ecx = edx = 0;  // @4_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_497750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L497797;  // @6_497750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; }) == (u32)(0)) goto L4977e0;  // @7_497750
  L497797:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @9_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_497750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @11_497750
  ecx = edx = 0;  // @12_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @13_497750
  if ((eax & eax) == 0) goto L4977be;  // @14_497750
  p0_ = eax;  // @15_497750
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(1));  // @16_497750
  ecx = edx = 0;  // @17_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @18_497750
  L4977be:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @20_497750
  if ((ecx & ecx) == 0) goto L4977d2;  // @21_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_497750
  ecx = edx = 0;  // @24_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @25_497750
  L4977d2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @27_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @28_497750
  L4977e0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_497750
  p1_ = ebx;  // @31_497750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @32_497750
  eax = ext_41e290_cdecl1((u32)(p1_));  // @33_497750
  ecx = edx = 0;  // @34_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @35_497750
  eax = ext_41e290_cdecl1((u32)(16));  // @36_497750
  ecx = edx = 0;  // @37_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @38_497750
  reg.state = (s32)((u32)(0));  // @39_497750
  if ((eax & eax) == 0) goto L49781a;  // @40_497750
  ecx = eax;  // @41_497750
  eax = ext_4ccdd0_thiscall4(ecx, (u32)(0), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; }), (u32)(512));  // @42_497750
  ecx = edx = 0;  // @43_497750
  goto L49781c;  // @44_497750
  L49781a:;
  eax = 0;  // @46_497750
  L49781c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @48_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @49_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @50_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @51_497750
  eax = (eax + edx);  // @52_497750
  reg.state = (s32)((u32)(4294967295));  // @53_497750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_497750
  p2_ = eax;  // @55_497750
  p3_ = edx;  // @56_497750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 216)))(ecx, (u32)(p3_), (u32)(p2_), (u32)(4809904));  // @57_497750
  ecx = edx = 0;  // @58_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @59_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @61_497750
  ecx = edx = 0;  // @62_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @63_497750
  if ((ecx & ecx) == 0) goto L497866;  // @64_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_497750
  p4_ = ebx;  // @66_497750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6874404), (u32)(p4_));  // @67_497750
  ecx = edx = 0;  // @68_497750
  L497866:;
  SEH_LEAVE();  // @70_497750
  return eax;  // @71_497750
}
PCREG(497750, lifted_497750);

extern "C" u32 THISCALL lifted_6633d0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_6633d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_6633d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_6633d0
  edx = (u32)(EBP - 144);  // @3_6633d0
  p0_ = edx;  // @4_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_6633d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 412)))(ecx, (u32)(p0_));  // @6_6633d0
  ecx = edx = 0;  // @7_6633d0
  ecx = eax;  // @8_6633d0
  reg.state = (s32)((u32)(0));  // @9_6633d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @10_6633d0
  ecx = edx = 0;  // @11_6633d0
  ebx = (ebx + (u32)(74164));  // @12_6633d0
  edx = ebx;  // @13_6633d0
  edx = (edx - eax);  // @14_6633d0
  L663433:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @16_6633d0
  eax = (u32)(eax + 1);  // @17_6633d0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @18_6633d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663433;  // @19_6633d0
  ecx = (u32)(EBP - 144);  // @20_6633d0
  reg.state = (s32)((u32)(4294967295));  // @21_6633d0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_6633d0
  ecx = edx = 0;  // @23_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @26_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_6633d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @28_6633d0
  ecx = edx = 0;  // @29_6633d0
  esi = eax;  // @30_6633d0
  L663473:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @32_6633d0
  eax = (eax + 1);  // @33_6633d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663473;  // @34_6633d0
  eax = (eax - esi);  // @35_6633d0
  edi = (u32)(ebx - 1);  // @36_6633d0
  L663480:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @38_6633d0
  edi = (edi + 1);  // @39_6633d0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663480;  // @40_6633d0
  ecx = eax;  // @41_6633d0
  ecx = (ecx >> (u32)(2));  // @42_6633d0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @43_6633d0
  ecx = eax;  // @44_6633d0
  ecx = (ecx & (u32)(3));  // @45_6633d0
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @46_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @47_6633d0
  p1_ = ebx;  // @48_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @50_6633d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(p1_), (u32)(0));  // @51_6633d0
  ecx = edx = 0;  // @52_6633d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6634d1;  // @53_6633d0
  edi = (u32)(ebx - 1);  // @54_6633d0
  L6634b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @56_6633d0
  edi = (u32)(edi + 1);  // @57_6633d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6634b0;  // @58_6633d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @59_6633d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @60_6633d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @61_6633d0
  p2_ = ebx;  // @62_6633d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_6633d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(p2_));  // @64_6633d0
  ecx = edx = 0;  // @65_6633d0
  goto L6634e5;  // @66_6633d0
  L6634d1:;
  ebx = (ebx - 1);  // @68_6633d0
  L6634d2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; })) & 0xff);  // @70_6633d0
  ebx = (ebx + 1);  // @71_6633d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6634d2;  // @72_6633d0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @73_6633d0
  edi = ebx;  // @74_6633d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @75_6633d0
  L6634e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @77_6633d0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 73992), &v, sizeof v); }  // @78_6633d0
  SEH_LEAVE();  // @79_6633d0
  ext_633654(G(u32, 0x6f5630));  // @80_6633d0
  return eax;  // @81_6633d0
}
PCREG(6633d0, lifted_6633d0);

extern "C" u32 THISCALL lifted_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_452bc0
  p0_ = esi;  // @2_452bc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @3_452bc0
  eax = ext_448a30_thiscall2(ecx, (u32)(p0_));  // @4_452bc0
  ecx = edx = 0;  // @5_452bc0
  ecx = esi;  // @6_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @7_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @8_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @9_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @10_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @11_452bc0
  ecx = edx = 0;  // @12_452bc0
  if ((eax & 0xff) != (u32)(2)) goto L452d47;  // @13_452bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_452bc0
  ecx = ebx;  // @15_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @16_452bc0
  ecx = edx = 0;  // @17_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @18_452bc0
  esi = eax;  // @19_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(63));  // @21_452bc0
  ecx = edx = 0;  // @22_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_452bc0
  edi = eax;  // @24_452bc0
  eax = (u32)(EBP - 156);  // @25_452bc0
  ecx = esi;  // @26_452bc0
  p1_ = eax;  // @27_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p1_), (u32)(1));  // @28_452bc0
  ecx = edx = 0;  // @29_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_452bc0
  ecx = eax;  // @31_452bc0
  reg.state = (s32)((u32)(0));  // @32_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @33_452bc0
  ecx = edx = 0;  // @34_452bc0
  p2_ = eax;  // @35_452bc0
  p3_ = edi;  // @36_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 48)))((u32)(p3_), (u32)(6813044), (u32)(p2_));  // @37_452bc0
  ecx = edx = 0;  // @38_452bc0
  reg.state = (s32)((u32)(4294967295));  // @39_452bc0
  ecx = (u32)(EBP - 156);  // @40_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @41_452bc0
  ecx = edx = 0;  // @42_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @43_452bc0
  ecx = esi;  // @44_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @45_452bc0
  ecx = edx = 0;  // @46_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452cbb;  // @47_452bc0
  eax = (u32)(EBP - 288);  // @48_452bc0
  ecx = esi;  // @49_452bc0
  p4_ = eax;  // @50_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @51_452bc0
  ecx = edx = 0;  // @52_452bc0
  goto L452d47;  // @53_452bc0
  L452cbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_452bc0
  ecx = ebx;  // @56_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @57_452bc0
  ecx = edx = 0;  // @58_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_452bc0
  esi = eax;  // @60_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(68));  // @62_452bc0
  ecx = edx = 0;  // @63_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_452bc0
  edi = eax;  // @65_452bc0
  eax = (u32)(EBP - 284);  // @66_452bc0
  ecx = esi;  // @67_452bc0
  p5_ = eax;  // @68_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(p5_), (u32)(1));  // @69_452bc0
  ecx = edx = 0;  // @70_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @71_452bc0
  ecx = eax;  // @72_452bc0
  reg.state = (s32)((u32)(1));  // @73_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @74_452bc0
  ecx = edx = 0;  // @75_452bc0
  p6_ = eax;  // @76_452bc0
  p7_ = edi;  // @77_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(p7_), (u32)(6822612), (u32)(p6_));  // @78_452bc0
  ecx = edx = 0;  // @79_452bc0
  reg.state = (s32)((u32)(4294967295));  // @80_452bc0
  ecx = (u32)(EBP - 284);  // @81_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @82_452bc0
  ecx = edx = 0;  // @83_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @84_452bc0
  eax = (u32)(EBP - 28);  // @85_452bc0
  p8_ = eax;  // @86_452bc0
  ecx = esi;  // @87_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p8_), (u32)(1));  // @88_452bc0
  ecx = edx = 0;  // @89_452bc0
  eax = (u32)(EBP - 24);  // @90_452bc0
  ecx = esi;  // @91_452bc0
  p9_ = eax;  // @92_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p9_), (u32)(1));  // @93_452bc0
  ecx = edx = 0;  // @94_452bc0
  eax = (u32)(EBP - 20);  // @95_452bc0
  ecx = esi;  // @96_452bc0
  p10_ = eax;  // @97_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(p10_), (u32)(1));  // @98_452bc0
  ecx = edx = 0;  // @99_452bc0
  L452d47:;
  eax = (u32)(EBP - 292);  // @101_452bc0
  ecx = esi;  // @102_452bc0
  p11_ = eax;  // @103_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p11_), (u32)(1));  // @104_452bc0
  ecx = edx = 0;  // @105_452bc0
  eax = (u32)(EBP - 296);  // @106_452bc0
  ecx = esi;  // @107_452bc0
  p12_ = eax;  // @108_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p12_), (u32)(1));  // @109_452bc0
  ecx = edx = 0;  // @110_452bc0
  ecx = esi;  // @111_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @112_452bc0
  ecx = edx = 0;  // @113_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d82;  // @114_452bc0
  eax = (u32)(EBP - 300);  // @115_452bc0
  ecx = esi;  // @116_452bc0
  p13_ = eax;  // @117_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p13_), (u32)(1));  // @118_452bc0
  ecx = edx = 0;  // @119_452bc0
  L452d82:;
  ecx = esi;  // @121_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @122_452bc0
  ecx = edx = 0;  // @123_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d9d;  // @124_452bc0
  eax = (u32)(EBP - 304);  // @125_452bc0
  ecx = esi;  // @126_452bc0
  p14_ = eax;  // @127_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(p14_), (u32)(1));  // @128_452bc0
  ecx = edx = 0;  // @129_452bc0
  L452d9d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) & (u32)(4294955007))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @131_452bc0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }) == (u32)(0)) goto L452db4;  // @132_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @133_452bc0
  L452db4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L452dc4;  // @135_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(8192))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @136_452bc0
  L452dc4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; }) == (u32)(0)) goto L452dd4;  // @138_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(16384))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @139_452bc0
  L452dd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; }) == (u32)(0)) goto L452de4;  // @141_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(32768))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @142_452bc0
  L452de4:;
  ecx = esi;  // @144_452bc0
  eax = ext_4e1b30_thiscall1(ecx);  // @145_452bc0
  ecx = edx = 0;  // @146_452bc0
  SEH_LEAVE();  // @147_452bc0
  ext_633654(G(u32, 0x6f5630));  // @148_452bc0
  return eax;  // @149_452bc0
}
PCREG(452bc0, lifted_452bc0);

extern "C" u32 THISCALL lifted_42a820(u32 ecx_in) {
  SEH_ENTER(0x66496c);  // @h_42a820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_42a820
  eax = ext_42de30_thiscall1(ecx);  // @1_42a820
  ecx = edx = 0;  // @2_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_42a820
  edx = (u32)(EBP - 276);  // @4_42a820
  p0_ = edx;  // @5_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @7_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783396), (u32)(p0_));  // @8_42a820
  ecx = edx = 0;  // @9_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a875;  // @10_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @11_42a820
  L42a875:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_42a820
  edx = (u32)(EBP - 276);  // @14_42a820
  p1_ = edx;  // @15_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @17_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783568), (u32)(p1_));  // @18_42a820
  ecx = edx = 0;  // @19_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a8da;  // @20_42a820
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7003), sizeof v); (u32)v; }) == (u32)(0)) goto L42a8c9;  // @21_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @22_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6788896), (u32)(80));  // @24_42a820
  ecx = edx = 0;  // @25_42a820
  p2_ = eax;  // @26_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(p2_), (u32)(6783580));  // @28_42a820
  ecx = edx = 0;  // @29_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_42a820
  if ((eax & eax) == 0) goto L42a8c8;  // @31_42a820
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_42a820
  ecx = edx = 0;  // @33_42a820
  goto L42a8c9;  // @34_42a820
  L42a8c8:;
  __builtin_trap();  // @36_42a820
  L42a8c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @38_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_42a820
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @40_42a820
  ecx = edx = 0;  // @41_42a820
  L42a8da:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_42a820
  edx = (u32)(EBP - 276);  // @44_42a820
  p3_ = edx;  // @45_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @47_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783656), (u32)(p3_));  // @48_42a820
  ecx = edx = 0;  // @49_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a933;  // @50_42a820
  ecx = (u32)(EBP - 144);  // @51_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @52_42a820
  ecx = edx = 0;  // @53_42a820
  eax = (u32)(EBP - 144);  // @54_42a820
  reg.state = (s32)((u32)(0));  // @55_42a820
  p4_ = eax;  // @56_42a820
  ecx = (u32)(edi + 7153);  // @57_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p4_));  // @58_42a820
  ecx = edx = 0;  // @59_42a820
  ecx = (u32)(EBP - 144);  // @60_42a820
  reg.state = (s32)((u32)(4294967295));  // @61_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @62_42a820
  ecx = edx = 0;  // @63_42a820
  L42a933:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_42a820
  edx = (u32)(EBP - 276);  // @66_42a820
  p5_ = edx;  // @67_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @69_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783668), (u32)(p5_));  // @70_42a820
  ecx = edx = 0;  // @71_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a99a;  // @72_42a820
  ecx = (u32)(EBP - 144);  // @73_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @74_42a820
  ecx = edx = 0;  // @75_42a820
  eax = (u32)(EBP - 144);  // @76_42a820
  reg.state = (s32)((u32)(1));  // @77_42a820
  esi = (u32)(edi + 7025);  // @78_42a820
  p6_ = eax;  // @79_42a820
  ecx = esi;  // @80_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p6_));  // @81_42a820
  ecx = edx = 0;  // @82_42a820
  ecx = (u32)(EBP - 144);  // @83_42a820
  reg.state = (s32)((u32)(4294967295));  // @84_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @85_42a820
  ecx = edx = 0;  // @86_42a820
  p7_ = esi;  // @87_42a820
  ecx = edi;  // @88_42a820
  eax = ext_42da80_stdcall1((u32)(p7_));  // @89_42a820
  ecx = edx = 0;  // @90_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @91_42a820
  L42a99a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_42a820
  edx = (u32)(EBP - 276);  // @94_42a820
  p8_ = edx;  // @95_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @97_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783676), (u32)(p8_));  // @98_42a820
  ecx = edx = 0;  // @99_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @100_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_42a820
  edx = (u32)(EBP - 276);  // @102_42a820
  p9_ = edx;  // @103_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @105_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783684), (u32)(p9_));  // @106_42a820
  ecx = edx = 0;  // @107_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @108_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_42a820
  edx = (u32)(EBP - 276);  // @110_42a820
  p10_ = edx;  // @111_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @113_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783696), (u32)(p10_));  // @114_42a820
  ecx = edx = 0;  // @115_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aa3b;  // @116_42a820
  L42a9f1:;
  ecx = (u32)(EBP - 144);  // @118_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @119_42a820
  ecx = edx = 0;  // @120_42a820
  eax = (u32)(EBP - 144);  // @121_42a820
  reg.state = (s32)((u32)(2));  // @122_42a820
  esi = (u32)(edi + 7025);  // @123_42a820
  p11_ = eax;  // @124_42a820
  ecx = esi;  // @125_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p11_));  // @126_42a820
  ecx = edx = 0;  // @127_42a820
  ecx = (u32)(EBP - 144);  // @128_42a820
  reg.state = (s32)((u32)(4294967295));  // @129_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @130_42a820
  ecx = edx = 0;  // @131_42a820
  p12_ = esi;  // @132_42a820
  ecx = edi;  // @133_42a820
  eax = ext_42da80_stdcall1((u32)(p12_));  // @134_42a820
  ecx = edx = 0;  // @135_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @136_42a820
  L42aa3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @138_42a820
  edx = (u32)(EBP - 276);  // @139_42a820
  p13_ = edx;  // @140_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @142_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783708), (u32)(p13_));  // @143_42a820
  ecx = edx = 0;  // @144_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aaa2;  // @145_42a820
  ecx = (u32)(EBP - 272);  // @146_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @147_42a820
  ecx = edx = 0;  // @148_42a820
  eax = (u32)(EBP - 272);  // @149_42a820
  reg.state = (s32)((u32)(3));  // @150_42a820
  esi = (u32)(edi + 7025);  // @151_42a820
  p14_ = eax;  // @152_42a820
  ecx = esi;  // @153_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p14_));  // @154_42a820
  ecx = edx = 0;  // @155_42a820
  ecx = (u32)(EBP - 272);  // @156_42a820
  reg.state = (s32)((u32)(4294967295));  // @157_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @158_42a820
  ecx = edx = 0;  // @159_42a820
  p15_ = esi;  // @160_42a820
  ecx = edi;  // @161_42a820
  eax = ext_42da80_stdcall1((u32)(p15_));  // @162_42a820
  ecx = edx = 0;  // @163_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @164_42a820
  L42aaa2:;
  SEH_LEAVE();  // @166_42a820
  ext_633654(G(u32, 0x6f5630));  // @167_42a820
  return eax;  // @168_42a820
}
PCREG(42a820, lifted_42a820);

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

extern "C" u32 THISCALL lifted_577550(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_577550
  esi = ecx;  // @1_577550
  p0_ = edi;  // @2_577550
  eax = ext_562c20_thiscall2(ecx, (u32)(p0_));  // @3_577550
  ecx = edx = 0;  // @4_577550
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L57756c;  // @5_577550
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @6_577550
  return eax;  // @7_577550
  L57756c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_577550
  edx = (u32)(EBP + 8);  // @10_577550
  p1_ = edx;  // @11_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_577550
  ebx = 0;  // @13_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @14_577550
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6976900), (u32)(p1_));  // @15_577550
  ecx = edx = 0;  // @16_577550
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L577597;  // @17_577550
  eax = ((u32( *)(u32))(*(u32 *)0x6762d8))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @18_577550
  ecx = edx = 0;  // @19_577550
  ebx = eax;  // @20_577550
  L577597:;
  eax = (u32)(ebx + ebx*4);  // @22_577550
  eax = (eax + eax);  // @23_577550
  if (edi < eax) goto L57778f;  // @24_577550
  edi = (edi + (u32)(-11));  // @25_577550
  if (edi > (u32)(71)) goto L57776f;  // @26_577550
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5732316), sizeof v); (u32)v; });  // @27_577550
  switch (eax) { case 0: goto L5775bf; case 1: goto L577754; case 2: goto L5775da; case 3: goto L577697; case 4: goto L5775f5; case 5: goto L5776b2; case 6: goto L577610; case 7: goto L5776cd; case 8: goto L57762b; case 9: goto L5776e8; case 10: goto L577646; case 11: goto L577703; case 12: goto L577661; case 13: goto L57771e; case 14: goto L57767c; case 15: goto L577739; case 16: goto L57776f; default: __builtin_trap(); }  // @28_577550
  L5775bf:;
  ecx = esi;  // @30_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981620));  // @31_577550
  ecx = edx = 0;  // @32_577550
  ecx = esi;  // @33_577550
  eax = ext_563500_cdecl0();  // @34_577550
  ecx = edx = 0;  // @35_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @36_577550
  return eax;  // @37_577550
  L5775da:;
  ecx = esi;  // @39_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981564));  // @40_577550
  ecx = edx = 0;  // @41_577550
  ecx = esi;  // @42_577550
  eax = ext_563500_cdecl0();  // @43_577550
  ecx = edx = 0;  // @44_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @45_577550
  return eax;  // @46_577550
  L5775f5:;
  ecx = esi;  // @48_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981572));  // @49_577550
  ecx = edx = 0;  // @50_577550
  ecx = esi;  // @51_577550
  eax = ext_563500_cdecl0();  // @52_577550
  ecx = edx = 0;  // @53_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @54_577550
  return eax;  // @55_577550
  L577610:;
  ecx = esi;  // @57_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981580));  // @58_577550
  ecx = edx = 0;  // @59_577550
  ecx = esi;  // @60_577550
  eax = ext_563500_cdecl0();  // @61_577550
  ecx = edx = 0;  // @62_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @63_577550
  return eax;  // @64_577550
  L57762b:;
  ecx = esi;  // @66_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981588));  // @67_577550
  ecx = edx = 0;  // @68_577550
  ecx = esi;  // @69_577550
  eax = ext_563500_cdecl0();  // @70_577550
  ecx = edx = 0;  // @71_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @72_577550
  return eax;  // @73_577550
  L577646:;
  ecx = esi;  // @75_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981604));  // @76_577550
  ecx = edx = 0;  // @77_577550
  ecx = esi;  // @78_577550
  eax = ext_563500_cdecl0();  // @79_577550
  ecx = edx = 0;  // @80_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @81_577550
  return eax;  // @82_577550
  L577661:;
  ecx = esi;  // @84_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981612));  // @85_577550
  ecx = edx = 0;  // @86_577550
  ecx = esi;  // @87_577550
  eax = ext_563500_cdecl0();  // @88_577550
  ecx = edx = 0;  // @89_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @90_577550
  return eax;  // @91_577550
  L57767c:;
  ecx = esi;  // @93_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6984788));  // @94_577550
  ecx = edx = 0;  // @95_577550
  ecx = esi;  // @96_577550
  eax = ext_563500_cdecl0();  // @97_577550
  ecx = edx = 0;  // @98_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @99_577550
  return eax;  // @100_577550
  L577697:;
  ecx = esi;  // @102_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985408));  // @103_577550
  ecx = edx = 0;  // @104_577550
  ecx = esi;  // @105_577550
  eax = ext_563500_cdecl0();  // @106_577550
  ecx = edx = 0;  // @107_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @108_577550
  return eax;  // @109_577550
  L5776b2:;
  ecx = esi;  // @111_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985416));  // @112_577550
  ecx = edx = 0;  // @113_577550
  ecx = esi;  // @114_577550
  eax = ext_563500_cdecl0();  // @115_577550
  ecx = edx = 0;  // @116_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @117_577550
  return eax;  // @118_577550
  L5776cd:;
  ecx = esi;  // @120_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985424));  // @121_577550
  ecx = edx = 0;  // @122_577550
  ecx = esi;  // @123_577550
  eax = ext_563500_cdecl0();  // @124_577550
  ecx = edx = 0;  // @125_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @126_577550
  return eax;  // @127_577550
  L5776e8:;
  ecx = esi;  // @129_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985432));  // @130_577550
  ecx = edx = 0;  // @131_577550
  ecx = esi;  // @132_577550
  eax = ext_563500_cdecl0();  // @133_577550
  ecx = edx = 0;  // @134_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @135_577550
  return eax;  // @136_577550
  L577703:;
  ecx = esi;  // @138_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6981596));  // @139_577550
  ecx = edx = 0;  // @140_577550
  ecx = esi;  // @141_577550
  eax = ext_563500_cdecl0();  // @142_577550
  ecx = edx = 0;  // @143_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @144_577550
  return eax;  // @145_577550
  L57771e:;
  ecx = esi;  // @147_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985440));  // @148_577550
  ecx = edx = 0;  // @149_577550
  ecx = esi;  // @150_577550
  eax = ext_563500_cdecl0();  // @151_577550
  ecx = edx = 0;  // @152_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @153_577550
  return eax;  // @154_577550
  L577739:;
  ecx = esi;  // @156_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6985448));  // @157_577550
  ecx = edx = 0;  // @158_577550
  ecx = esi;  // @159_577550
  eax = ext_563500_cdecl0();  // @160_577550
  ecx = edx = 0;  // @161_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @162_577550
  return eax;  // @163_577550
  L577754:;
  ecx = esi;  // @165_577550
  eax = ext_562b50_thiscall2(ecx, (u32)(6980864));  // @166_577550
  ecx = edx = 0;  // @167_577550
  ecx = esi;  // @168_577550
  eax = ext_563500_cdecl0();  // @169_577550
  ecx = edx = 0;  // @170_577550
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @171_577550
  return eax;  // @172_577550
  L57776f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @174_577550
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_577550
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6985456), (u32)(97));  // @176_577550
  ecx = edx = 0;  // @177_577550
  p2_ = eax;  // @178_577550
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @179_577550
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p2_), (u32)(6985504));  // @180_577550
  ecx = edx = 0;  // @181_577550
  L57778f:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @183_577550
  return eax;  // @184_577550
}
PCREG(577550, lifted_577550);

