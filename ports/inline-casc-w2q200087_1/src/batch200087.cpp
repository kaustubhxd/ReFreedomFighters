// batch200087.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_41f190_stdcall1(u32) __asm__("ext_41f190");
extern "C" u32 STDCALL ext_658fb0_stdcall1(u32) __asm__("ext_658fb0");
extern "C" u32 THISCALL ext_4cfbe0_thiscall1(u32) __asm__("ext_4cfbe0");
extern "C" u32 THISCALL ext_4db9e0_thiscall1(u32) __asm__("ext_4db9e0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4f9680_thiscall2(u32, u32) __asm__("ext_4f9680");
extern "C" u32 THISCALL ext_512850_thiscall2(u32, u32) __asm__("ext_512850");
extern "C" u32 THISCALL ext_63faa0_thiscall2(u32, u32) __asm__("ext_63faa0");
extern "C" u32 THISCALL ext_658d30_thiscall1(u32) __asm__("ext_658d30");
extern "C" u32 THISCALL ext_658d50_thiscall1(u32) __asm__("ext_658d50");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_449310(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_449310
  if ((ecx & ecx) == 0) goto L449372;  // @2_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_449310
  edx = (u32)(EBP - 12);  // @4_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @5_449310
  ecx = edx = 0;  // @6_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @7_449310
  edx = (u32)(EBP - 12);  // @8_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @10_449310
  ecx = edx = 0;  // @11_449310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) == (u32)(0)) goto L449372;  // @12_449310
  L449340:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_449310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @15_449310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @17_449310
  ecx = edx = 0;  // @18_449310
  if ((eax & eax) == 0) goto L449360;  // @19_449310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_449310
  ecx = eax;  // @21_449310
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 532)))(ecx);  // @22_449310
  ecx = edx = 0;  // @23_449310
  L449360:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @25_449310
  edx = (u32)(EBP - 12);  // @26_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_449310
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @28_449310
  ecx = edx = 0;  // @29_449310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) != (u32)(0)) goto L449340;  // @30_449310
  L449372:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_449310
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(8192));  // @33_449310
  ecx = edx = 0;  // @34_449310
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @35_449310
  eax = (eax & (u32)(4294967294));  // @36_449310
  eax = (eax | (u32)(8));  // @37_449310
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @38_449310
  return eax;  // @39_449310
}
PCREG(449310, lifted_449310);

extern "C" u32 THISCALL lifted_536750(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21250), sizeof v); (u32)v; });  // @0_536750
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_536750
  if ((edx & edx) != 0) goto L536769;  // @2_536750
  L536761:;
  eax = 0;  // @4_536750
  return eax;  // @5_536750
  L536769:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_536750
  if ((eax & eax) == 0) goto L536761;  // @8_536750
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @9_536750
  edx = (edx + eax);  // @10_536750
  esi = 0;  // @11_536750
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @12_536750
  if ((ebx & ebx) == 0) goto L5367a8;  // @13_536750
  L536781:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21250), sizeof v); (u32)v; });  // @15_536750
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi*4), sizeof v); (u32)v; });  // @16_536750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @17_536750
  edi = (edi + eax);  // @18_536750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @19_536750
  ecx = (ecx + eax);  // @20_536750
  eax = ext_4cc850_fastcall2(ecx, edx);  // @21_536750
  ecx = edx = 0;  // @22_536750
  if ((eax & eax) == 0) goto L5367b3;  // @23_536750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @24_536750
  esi = (esi + 1);  // @25_536750
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @26_536750
  if (esi < ebx) goto L536781;  // @27_536750
  L5367a8:;
  eax = 0;  // @29_536750
  return eax;  // @30_536750
  L5367b3:;
  eax = edi;  // @32_536750
  return eax;  // @33_536750
}
PCREG(536750, lifted_536750);

extern "C" u32 THISCALL lifted_562d90(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 216), sizeof v); (u32)v; });  // @2_562d90
  eax = ((u32(STDCALL *)(void))(eax))();  // @3_562d90
  ecx = edx = 0;  // @4_562d90
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L562e18;  // @5_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_562d90
  if (eax != (u32)(261)) goto L562e07;  // @7_562d90
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 135), sizeof v); (u32)v; }) == (u32)(0)) goto L562e18;  // @8_562d90
  ecx = (u32)(7343652);  // @9_562d90
  eax = ext_4f9680_thiscall2(ecx, (u32)(3));  // @10_562d90
  ecx = edx = 0;  // @11_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_562d90
  ecx = esi;  // @13_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 224)))(ecx);  // @14_562d90
  ecx = edx = 0;  // @15_562d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }) == (u32)(0)) goto L562dec;  // @16_562d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }) == (u32)(0)) goto L562dec;  // @17_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_562d90
  ecx = esi;  // @19_562d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(0));  // @20_562d90
  ecx = edx = 0;  // @21_562d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @22_562d90
  return eax;  // @23_562d90
  L562dec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_562d90
  ecx = esi;  // @26_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @27_562d90
  ecx = edx = 0;  // @28_562d90
  ecx = eax;  // @29_562d90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 768)))(ecx);  // @31_562d90
  ecx = edx = 0;  // @32_562d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @33_562d90
  return eax;  // @34_562d90
  L562e07:;
  if (eax != (u32)(262)) goto L562e18;  // @36_562d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_562d90
  ecx = esi;  // @38_562d90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @39_562d90
  ecx = edx = 0;  // @40_562d90
  L562e18:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @42_562d90
  return eax;  // @43_562d90
}
PCREG(562d90, lifted_562d90);

extern "C" u32 THISCALL lifted_63e850(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ecx;  // @0_63e850
  edx = (u32)(65535);  // @1_63e850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_63e850
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @3_63e850
  if ((eax & 0xffff) == (edx & 0xffff)) goto L63e877;  // @4_63e850
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 6), &v, sizeof v); }  // @5_63e850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + eax*4 + 624), &v, sizeof v); }  // @6_63e850
  L63e877:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 5), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ecx + 5), &v, sizeof v); }  // @8_63e850
  edx = (u32)(EBP + 8);  // @9_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @11_63e850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @12_63e850
  ecx = (u32)(esi + 496);  // @13_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @15_63e850
  ecx = edx = 0;  // @16_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_63e850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @18_63e850
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ecx + 60), &v, sizeof v); }  // @19_63e850
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(1074003968)) != 0) goto L63e8b3;  // @20_63e850
  eax = ext_4db9e0_thiscall1(ecx);  // @21_63e850
  ecx = edx = 0;  // @22_63e850
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L63e8c8;  // @23_63e850
  L63e8b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_63e850
  ecx = (u32)(esi + 436);  // @26_63e850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @27_63e850
  edx = (u32)(EBP - 4);  // @28_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @30_63e850
  ecx = edx = 0;  // @31_63e850
  L63e8c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_63e850
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L63e8e7;  // @34_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 476), sizeof v); (u32)v; });  // @35_63e850
  ecx = (u32)(esi + 476);  // @36_63e850
  edx = (u32)(EBP + 8);  // @37_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @38_63e850
  ecx = edx = 0;  // @39_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @40_63e850
  L63e8e7:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 63), sizeof v); (u32)v; }) == (u32)(0)) goto L63e900;  // @42_63e850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 456), sizeof v); (u32)v; });  // @43_63e850
  ecx = (u32)(esi + 456);  // @44_63e850
  edx = (u32)(EBP + 8);  // @45_63e850
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @46_63e850
  ecx = edx = 0;  // @47_63e850
  L63e900:;
  return eax;  // @49_63e850
}
PCREG(63e850, lifted_63e850);

extern "C" u32 THISCALL lifted_41f400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_41f400
  ebx = ecx;  // @1_41f400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @2_41f400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @3_41f400
  eax = (u32)(edi + 32);  // @4_41f400
  eax = ext_41f190_stdcall1((u32)(eax));  // @5_41f400
  ecx = edx = 0;  // @6_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == esi) goto L41f43e;  // @7_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_41f400
  ecx = ebx;  // @9_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780060), (u32)(edi));  // @10_41f400
  ecx = edx = 0;  // @11_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @12_41f400
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @13_41f400
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @14_41f400
  if ((eax & eax) == 0) goto L41f478;  // @15_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @16_41f400
  ecx = edx = 0;  // @17_41f400
  L41f43e:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @19_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @20_41f400
  eax = (eax & (u32)(536870911));  // @21_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 32), sizeof v); (u32)v; }) == (u32)(2271560481)) goto L41f487;  // @22_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @23_41f400
  ecx = ebx;  // @24_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780084), (u32)(edi));  // @25_41f400
  ecx = edx = 0;  // @26_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @27_41f400
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @28_41f400
  if ((eax & eax) == 0) goto L41f47b;  // @29_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @30_41f400
  ecx = edx = 0;  // @31_41f400
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @32_41f400
  return eax;  // @33_41f400
  L41f478:;
  __builtin_trap();  // @35_41f400
  L41f47b:;
  __builtin_trap();  // @37_41f400
  L41f487:;
  eax = (eax & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @39_41f400
  return eax;  // @40_41f400
}
PCREG(41f400, lifted_41f400);

extern "C" u32 THISCALL lifted_4cf2d0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cf2d0
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) >= (s32)(u32)(0)) goto L4cf30d;  // @1_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4cf2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6904700), (u32)(392));  // @4_4cf2d0
  ecx = edx = 0;  // @5_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_4cf2d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6904776));  // @7_4cf2d0
  ecx = edx = 0;  // @8_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @9_4cf2d0
  if ((eax & eax) == 0) goto L4cf30c;  // @10_4cf2d0
  eax = ((u32(STDCALL *)(void))(eax))();  // @11_4cf2d0
  ecx = edx = 0;  // @12_4cf2d0
  goto L4cf30d;  // @13_4cf2d0
  L4cf30c:;
  __builtin_trap();  // @15_4cf2d0
  L4cf30d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @18_4cf2d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; })) goto L4cf326;  // @19_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @20_4cf2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @21_4cf2d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @22_4cf2d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @23_4cf2d0
  L4cf326:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @25_4cf2d0
  if ((ecx & ecx) != 0) goto L4cf333;  // @26_4cf2d0
  eax = 0;  // @27_4cf2d0
  return eax;  // @28_4cf2d0
  L4cf333:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @30_4cf2d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @31_4cf2d0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L4cf353;  // @32_4cf2d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cf353;  // @33_4cf2d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @34_4cf2d0
  eax = 0;  // @35_4cf2d0
  return eax;  // @36_4cf2d0
  L4cf353:;
  eax = (u32)(ecx + 16);  // @38_4cf2d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @39_4cf2d0
  ecx = (ecx + edi);  // @40_4cf2d0
  eax = (u32)(eax + edi*4);  // @41_4cf2d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @42_4cf2d0
  return eax;  // @43_4cf2d0
}
PCREG(4cf2d0, lifted_4cf2d0);

extern "C" u32 THISCALL lifted_4d0590(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4d0590
  ebx = ecx;  // @1_4d0590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 460), sizeof v); (u32)v; });  // @2_4d0590
  ecx = (u32)(ebx + 460);  // @3_4d0590
  eax = (u32)(edi + 16);  // @4_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(eax), (u32)(0));  // @5_4d0590
  ecx = edx = 0;  // @6_4d0590
  esi = eax;  // @7_4d0590
  if ((esi & esi) != 0) goto L4d0602;  // @8_4d0590
  ecx = ebx;  // @9_4d0590
  eax = ext_4cfbe0_thiscall1(ecx);  // @10_4d0590
  ecx = edx = 0;  // @11_4d0590
  esi = eax;  // @12_4d0590
  if ((esi & esi) != 0) goto L4d0602;  // @13_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6905280), (u32)(1074));  // @16_4d0590
  ecx = edx = 0;  // @17_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_4d0590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6905496), (u32)(edi));  // @19_4d0590
  ecx = edx = 0;  // @20_4d0590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @21_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4d0590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 120)))(ecx);  // @23_4d0590
  ecx = edx = 0;  // @24_4d0590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @25_4d0590
  if ((eax & eax) == 0) goto L4d05ff;  // @26_4d0590
  eax = ((u32(STDCALL *)(void))(eax))();  // @27_4d0590
  ecx = edx = 0;  // @28_4d0590
  goto L4d060a;  // @29_4d0590
  L4d05ff:;
  __builtin_trap();  // @31_4d0590
  L4d0602:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @33_4d0590
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) >= (s32)edi) goto L4d061f;  // @34_4d0590
  L4d060a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_4d0590
  if ((eax & eax) == 0) goto L4d061e;  // @37_4d0590
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_4d0590
  ecx = edx = 0;  // @39_4d0590
  eax = esi;  // @40_4d0590
  return eax;  // @41_4d0590
  L4d061e:;
  __builtin_trap();  // @43_4d0590
  L4d061f:;
  eax = esi;  // @45_4d0590
  return eax;  // @46_4d0590
}
PCREG(4d0590, lifted_4d0590);

extern "C" u32 lifted_62ce70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62ce70
  if (esi == (u32)(15)) goto L62cef5;  // @1_62ce70
  if (esi != (u32)(18)) goto L62ced3;  // @2_62ce70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_62ce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @4_62ce70
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078332), (u32)(edi));  // @5_62ce70
  ecx = edx = 0;  // @6_62ce70
  if ((eax & eax) == 0) goto L62ceac;  // @7_62ce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_62ce70
  { u32 v = (u32)((u32)(6475520)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_62ce70
  eax = 0;  // @10_62ce70
  return eax;  // @11_62ce70
  L62ceac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @13_62ce70
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078316));  // @14_62ce70
  ecx = edx = 0;  // @15_62ce70
  if ((eax & eax) == 0) goto L62ced3;  // @16_62ce70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_62ce70
  { u32 v = (u32)((u32)(6475584)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @18_62ce70
  eax = 0;  // @19_62ce70
  return eax;  // @20_62ce70
  L62ced3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_62ce70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L62cee8;  // @23_62ce70
  if (esi != (u32)(28)) goto L62cee8;  // @24_62ce70
  eax = (u32)(esi + 24);  // @25_62ce70
  return eax;  // @26_62ce70
  L62cee8:;
  { u32 v = (u32)((u32)(5370416)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @28_62ce70
  eax = (eax | (u32)(4294967295));  // @29_62ce70
  return eax;  // @30_62ce70
  L62cef5:;
  eax = 0;  // @32_62ce70
  return eax;  // @33_62ce70
}
PCREG(62ce70, lifted_62ce70);

extern "C" u32 lifted_62d840(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_62d840
  if (esi == (u32)(15)) goto L62d8de;  // @1_62d840
  if (esi == (u32)(18)) goto L62d86b;  // @2_62d840
  if (esi != (u32)(27)) goto L62d8bc;  // @3_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_62d840
  { u32 v = (u32)((u32)(6475664)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @5_62d840
  eax = (u32)(esi - 17);  // @6_62d840
  return eax;  // @7_62d840
  L62d86b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @9_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @10_62d840
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078408), (u32)(edi));  // @11_62d840
  ecx = edx = 0;  // @12_62d840
  if ((eax & eax) == 0) goto L62d895;  // @13_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_62d840
  { u32 v = (u32)((u32)(6478144)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @15_62d840
  eax = 0;  // @16_62d840
  return eax;  // @17_62d840
  L62d895:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @19_62d840
  eax = ((u32( *)(u32, u32, u32, u32))(eax))((u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }), (u32)(7078388));  // @20_62d840
  ecx = edx = 0;  // @21_62d840
  if ((eax & eax) == 0) goto L62d8bc;  // @22_62d840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_62d840
  { u32 v = (u32)((u32)(6478064)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_62d840
  eax = 0;  // @25_62d840
  return eax;  // @26_62d840
  L62d8bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @28_62d840
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L62d8d1;  // @29_62d840
  if (esi != (u32)(28)) goto L62d8d1;  // @30_62d840
  eax = (u32)(esi + 24);  // @31_62d840
  return eax;  // @32_62d840
  L62d8d1:;
  { u32 v = (u32)((u32)(5370416)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_62d840
  eax = (eax | (u32)(4294967295));  // @35_62d840
  return eax;  // @36_62d840
  L62d8de:;
  eax = 0;  // @38_62d840
  return eax;  // @39_62d840
}
PCREG(62d840, lifted_62d840);

extern "C" u32 THISCALL lifted_51c210(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_51c210
  ebx = ecx;  // @1_51c210
  eax = ext_512850_thiscall2(ecx, (u32)(edi));  // @2_51c210
  ecx = edx = 0;  // @3_51c210
  esi = (u32)(ebx + 1101);  // @4_51c210
  ecx = edi;  // @5_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(esi), (u32)(1));  // @6_51c210
  ecx = edx = 0;  // @7_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c267;  // @8_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(258));  // @11_51c210
  ecx = edx = 0;  // @12_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @13_51c210
  edx = (u32)(6801640);  // @14_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @15_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6945012), (u32)(edx));  // @17_51c210
  ecx = edx = 0;  // @18_51c210
  L51c267:;
  ecx = edi;  // @20_51c210
  eax = ext_4e1600_thiscall1(ecx);  // @21_51c210
  ecx = edx = 0;  // @22_51c210
  if ((eax & 0xff) != (u32)(8)) goto L51c2c6;  // @23_51c210
  esi = (u32)(ebx + 1105);  // @24_51c210
  ecx = edi;  // @25_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(esi), (u32)(1));  // @26_51c210
  ecx = edx = 0;  // @27_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c2d0;  // @28_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @29_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(261));  // @31_51c210
  ecx = edx = 0;  // @32_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @33_51c210
  edx = (u32)(6801640);  // @34_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @35_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6945036), (u32)(edx));  // @37_51c210
  ecx = edx = 0;  // @38_51c210
  ecx = edi;  // @39_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @40_51c210
  ecx = edx = 0;  // @41_51c210
  return eax;  // @42_51c210
  L51c2c6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1105), &v, sizeof v); }  // @44_51c210
  L51c2d0:;
  ecx = edi;  // @46_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @47_51c210
  ecx = edx = 0;  // @48_51c210
  return eax;  // @49_51c210
}
PCREG(51c210, lifted_51c210);

extern "C" u32 THISCALL lifted_5c2e10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5c2e10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_5c2e10
  if ((edx & edx) != 0) goto L5c2e26;  // @2_5c2e10
  eax = 0;  // @3_5c2e10
  return eax;  // @4_5c2e10
  L5c2e26:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 708), sizeof v); (u32)v; });  // @6_5c2e10
  edi = 0;  // @7_5c2e10
  if ((s32)(ebx & ebx) <= 0) goto L5c2e7b;  // @8_5c2e10
  esi = (u32)(ecx + 248);  // @9_5c2e10
  L5c2e40:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_5c2e10
  ecx = edx;  // @12_5c2e10
  L5c2e44:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @14_5c2e10
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5c2e64;  // @15_5c2e10
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L5c2e60;  // @16_5c2e10
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @17_5c2e10
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5c2e64;  // @18_5c2e10
  ecx = (ecx + (u32)(2));  // @19_5c2e10
  eax = (eax + (u32)(2));  // @20_5c2e10
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L5c2e44;  // @21_5c2e10
  L5c2e60:;
  eax = 0;  // @23_5c2e10
  goto L5c2e69;  // @24_5c2e10
  L5c2e64:;
  eax = 0;  // @26_5c2e10
  eax = (eax | (u32)(1));  // @27_5c2e10
  L5c2e69:;
  if ((eax & eax) == 0) goto L5c2ea7;  // @29_5c2e10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_5c2e10
  edi = (edi + 1);  // @31_5c2e10
  esi = (esi + (u32)(76));  // @32_5c2e10
  if ((s32)edi < (s32)ebx) goto L5c2e40;  // @33_5c2e10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @34_5c2e10
  L5c2e7b:;
  if ((s32)ebx >= (s32)(u32)(6)) goto L5c2eb2;  // @36_5c2e10
  eax = (u32)((s32)ebx * (s32)(u32)(76));  // @37_5c2e10
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx + 248), &v, sizeof v); }  // @38_5c2e10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 708), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx + 708), &v, sizeof v); }  // @39_5c2e10
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 708), sizeof v); (u32)v; }) * (s32)(u32)(76));  // @40_5c2e10
  eax = (eax + (u32)(172));  // @41_5c2e10
  eax = (eax + ecx);  // @42_5c2e10
  return eax;  // @43_5c2e10
  L5c2ea7:;
  eax = esi;  // @45_5c2e10
  return eax;  // @46_5c2e10
  L5c2eb2:;
  eax = 0;  // @48_5c2e10
  return eax;  // @49_5c2e10
}
PCREG(5c2e10, lifted_5c2e10);

extern "C" u32 STDCALL lifted_62ee40(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_62ee40
  if ((esi & esi) == 0) goto L62eef8;  // @1_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @2_62ee40
  if ((eax & eax) == 0) goto L62eef8;  // @3_62ee40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_62ee40
  if (edi == (u32)(42)) goto L62ee7b;  // @5_62ee40
  if (edi == (u32)(113)) goto L62ee7b;  // @6_62ee40
  if (edi == (u32)(666)) goto L62ee7b;  // @7_62ee40
  eax = (u32)(4294967294);  // @8_62ee40
  return eax;  // @9_62ee40
  L62ee7b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @11_62ee40
  if ((eax & eax) == 0) goto L62ee8e;  // @12_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @13_62ee40
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax), (u32)(edi));  // @14_62ee40
  ecx = edx = 0;  // @15_62ee40
  L62ee8e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @17_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @18_62ee40
  if ((eax & eax) == 0) goto L62eea4;  // @19_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @20_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax));  // @21_62ee40
  ecx = edx = 0;  // @22_62ee40
  L62eea4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @24_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @25_62ee40
  if ((eax & eax) == 0) goto L62eeba;  // @26_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @27_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax));  // @28_62ee40
  ecx = edx = 0;  // @29_62ee40
  L62eeba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @31_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @32_62ee40
  if ((eax & eax) == 0) goto L62eed0;  // @33_62ee40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @34_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), (u32)(eax));  // @35_62ee40
  ecx = edx = 0;  // @36_62ee40
  L62eed0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @38_62ee40
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }));  // @39_62ee40
  ecx = edx = 0;  // @40_62ee40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @41_62ee40
  eax = 0;  // @42_62ee40
  ecx = (u32)(4294967293);  // @43_62ee40
  if (edi == (u32)(113)) eax = ecx;  // @44_62ee40
  return eax;  // @45_62ee40
  L62eef8:;
  eax = (u32)(4294967294);  // @47_62ee40
  return eax;  // @48_62ee40
}
PCREG(62ee40, lifted_62ee40);

extern "C" u32 THISCALL lifted_5dd1b0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5dd1b0
  esi = ecx;  // @1_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7040416), (u32)(0), (u32)(7040368), (u32)(56));  // @4_5dd1b0
  ecx = edx = 0;  // @5_5dd1b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_5dd1b0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L5dd239;  // @7_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; })) goto L5dd1ea;  // @8_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @9_5dd1b0
  L5dd1ea:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; })) goto L5dd1f3;  // @11_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @12_5dd1b0
  L5dd1f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @14_5dd1b0
  if (edi != eax) goto L5dd1fe;  // @15_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @16_5dd1b0
  L5dd1fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; });  // @18_5dd1b0
  if (edi != ecx) goto L5dd209;  // @19_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @20_5dd1b0
  L5dd209:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; })) goto L5dd212;  // @22_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @23_5dd1b0
  L5dd212:;
  if (edi == eax) goto L5dd21a;  // @25_5dd1b0
  if (edi != ecx) goto L5dd239;  // @26_5dd1b0
  L5dd21a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 93), sizeof v); (u32)v; }));  // @31_5dd1b0
  ecx = edx = 0;  // @32_5dd1b0
  ecx = eax;  // @33_5dd1b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @35_5dd1b0
  ecx = edx = 0;  // @36_5dd1b0
  L5dd239:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @39_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7040428), (u32)(0), (u32)(7040368), (u32)(74));  // @41_5dd1b0
  ecx = edx = 0;  // @42_5dd1b0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L5dd295;  // @43_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; })) goto L5dd269;  // @44_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @45_5dd1b0
  L5dd269:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; })) goto L5dd272;  // @47_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @48_5dd1b0
  L5dd272:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; })) goto L5dd27b;  // @50_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @51_5dd1b0
  L5dd27b:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; })) goto L5dd284;  // @53_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @54_5dd1b0
  L5dd284:;
  eax = 0;  // @56_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; })) goto L5dd297;  // @57_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @58_5dd1b0
  return eax;  // @59_5dd1b0
  L5dd295:;
  eax = 0;  // @61_5dd1b0
  L5dd297:;
  return eax;  // @63_5dd1b0
}
PCREG(5dd1b0, lifted_5dd1b0);

extern "C" u32 THISCALL lifted_63e910(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63e910
  ebx = ecx;  // @1_63e910
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @3_63e910
  if ((edx & edx) == 0) goto L63e960;  // @4_63e910
  edi = 0;  // @5_63e910
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; }) == (u32)(0)) goto L63e949;  // @6_63e910
  L63e930:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @8_63e910
  if ((eax & eax) == 0) goto L63e93d;  // @9_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_63e910
  L63e93d:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; });  // @12_63e910
  edi = (edi + 1);  // @13_63e910
  edx = (edx + (u32)(8));  // @14_63e910
  if (edi != eax) goto L63e930;  // @15_63e910
  L63e949:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 61), sizeof v); (u32)v; });  // @17_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_63e910
  eax = (eax << (u32)(3));  // @19_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }), (u32)(eax));  // @20_63e910
  ecx = edx = 0;  // @21_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @22_63e910
  L63e960:;
  ecx = esi;  // @24_63e910
  eax = ext_658d30_thiscall1(ecx);  // @25_63e910
  ecx = edx = 0;  // @26_63e910
  if ((eax & eax) == 0) goto L63e9cb;  // @27_63e910
  ecx = ebx;  // @28_63e910
  eax = ext_63faa0_thiscall2(ecx, (u32)(esi));  // @29_63e910
  ecx = edx = 0;  // @30_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @31_63e910
  if ((eax & eax) == 0) goto L63e9b2;  // @32_63e910
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @33_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @34_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @35_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @37_63e910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @38_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_63e910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 196)))(ecx, (u32)(edx));  // @40_63e910
  ecx = edx = 0;  // @41_63e910
  ecx = esi;  // @42_63e910
  edi = eax;  // @43_63e910
  eax = ext_658d30_thiscall1(ecx);  // @44_63e910
  ecx = edx = 0;  // @45_63e910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @46_63e910
  ecx = ebx;  // @47_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 644)))(ecx, (u32)(eax), (u32)(edi));  // @48_63e910
  ecx = edx = 0;  // @49_63e910
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @50_63e910
  L63e9b2:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_63e910
  ecx = esi;  // @53_63e910
  eax = ext_658d50_thiscall1(ecx);  // @54_63e910
  ecx = edx = 0;  // @55_63e910
  ecx = ebx;  // @56_63e910
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 36)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(eax));  // @57_63e910
  ecx = edx = 0;  // @58_63e910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @59_63e910
  L63e9cb:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(8)) == 0) goto L63e9ea;  // @61_63e910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @62_63e910
  if ((eax & eax) == 0) goto L63e9ea;  // @63_63e910
  ecx = (u32)(65535);  // @64_63e910
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 62), sizeof v); (u32)v; }) + (ecx & 0xffff))); __builtin_memcpy((void *)(u32)(eax + 62), &v, sizeof v); }  // @65_63e910
  ecx = esi;  // @66_63e910
  eax = ext_658fb0_stdcall1((u32)(0));  // @67_63e910
  ecx = edx = 0;  // @68_63e910
  L63e9ea:;
  return eax;  // @70_63e910
}
PCREG(63e910, lifted_63e910);

