// batch216008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_460f90_thiscall1(u32) __asm__("ext_460f90");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_480a40_thiscall4(u32, u32, u32, u32) __asm__("ext_480a40");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4dcdf0_thiscall2(u32, u32) __asm__("ext_4dcdf0");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_500150_thiscall1(u32) __asm__("ext_500150");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_5fb000_thiscall1(u32) __asm__("ext_5fb000");
extern "C" u32 THISCALL ext_5fb600_thiscall1(u32) __asm__("ext_5fb600");
extern "C" u32 THISCALL ext_6042f0_thiscall1(u32) __asm__("ext_6042f0");
extern "C" u32 THISCALL ext_604ca0_thiscall1(u32) __asm__("ext_604ca0");
extern "C" u32 THISCALL ext_6052f0_thiscall3(u32, u32, u32) __asm__("ext_6052f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_45c4f0_cdecl2(...) __asm__("ext_45c4f0");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c4a70(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_4c4a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_4c4a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @1_4c4a70
  { u32 v = (u32)((u32)(6897948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4c4a70
  if ((ecx & ecx) == 0) goto L4c4aa8;  // @3_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4c4a70
  ecx = edx = 0;  // @6_4c4a70
  L4c4aa8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @8_4c4a70
  if ((ecx & ecx) == 0) goto L4c4ab5;  // @9_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @11_4c4a70
  ecx = edx = 0;  // @12_4c4a70
  L4c4ab5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @14_4c4a70
  if ((ecx & ecx) == 0) goto L4c4ac2;  // @15_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_4c4a70
  ecx = edx = 0;  // @18_4c4a70
  L4c4ac2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @20_4c4a70
  if ((ecx & ecx) == 0) goto L4c4acf;  // @21_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_4c4a70
  ecx = edx = 0;  // @24_4c4a70
  L4c4acf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @26_4c4a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @27_4c4a70
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @28_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4c4a70
  PS[0] = esi;  // @30_4c4a70
  reg.state = (s32)((u32)(0));  // @31_4c4a70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_4c4a70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4c4a70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @34_4c4a70
  ecx = edx = 0;  // @35_4c4a70
  SEH_LEAVE();  // @36_4c4a70
  return eax;  // @37_4c4a70
}
PCREG(4c4a70, lifted_4c4a70);

extern "C" u32 THISCALL lifted_500220(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66ae60);  // @h_500220
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_500220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_500220
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(0));  // @2_500220
  ecx = edx = 0;  // @3_500220
  edi = eax;  // @4_500220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_500220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_500220
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @7_500220
  ecx = (u32)(EBP - 28);  // @8_500220
  reg.state = (s32)((u32)(0));  // @9_500220
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @10_500220
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @11_500220
  ecx = edx = 0;  // @12_500220
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_500220
  ecx = (u32)(EBP - 28);  // @14_500220
  PS[0] = ecx;  // @15_500220
  ecx = edi;  // @16_500220
  reg.state = (s32)((u32)(1));  // @17_500220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(PS[0]));  // @18_500220
  ecx = edx = 0;  // @19_500220
  ecx = (u32)(EBP - 28);  // @20_500220
  eax = ext_500150_thiscall1(ecx);  // @21_500220
  ecx = edx = 0;  // @22_500220
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @23_500220
  ecx = ebx;  // @24_500220
  PS[0] = edi;  // @25_500220
  esi = eax;  // @26_500220
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, (u32)(PS[0]));  // @27_500220
  ecx = edx = 0;  // @28_500220
  ecx = (u32)(EBP - 28);  // @29_500220
  eax = ext_4ff9d0_thiscall1(ecx);  // @30_500220
  ecx = edx = 0;  // @31_500220
  eax = (u32)(esi + 4);  // @32_500220
  SEH_LEAVE();  // @33_500220
  return eax;  // @34_500220
}
PCREG(500220, lifted_500220);

extern "C" u32 THISCALL lifted_5dc5f0(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_5dc5f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_5dc5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 101), sizeof v); (u32)v; });  // @1_5dc5f0
  { u32 v = (u32)((u32)(7039908)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_5dc5f0
  if ((eax & eax) == 0) goto L5dc62b;  // @3_5dc5f0
  PS[0] = eax;  // @4_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(PS[0]));  // @5_5dc5f0
  ecx = edx = 0;  // @6_5dc5f0
  L5dc62b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 105), sizeof v); (u32)v; });  // @8_5dc5f0
  if ((eax & eax) == 0) goto L5dc63b;  // @9_5dc5f0
  PS[0] = eax;  // @10_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(PS[0]));  // @11_5dc5f0
  ecx = edx = 0;  // @12_5dc5f0
  L5dc63b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 109), sizeof v); (u32)v; });  // @14_5dc5f0
  if ((eax & eax) == 0) goto L5dc64b;  // @15_5dc5f0
  PS[0] = eax;  // @16_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(PS[0]));  // @17_5dc5f0
  ecx = edx = 0;  // @18_5dc5f0
  L5dc64b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @20_5dc5f0
  if ((eax & eax) == 0) goto L5dc65b;  // @21_5dc5f0
  PS[0] = eax;  // @22_5dc5f0
  eax = ext_41e2c0_cdecl1((u32)(PS[0]));  // @23_5dc5f0
  ecx = edx = 0;  // @24_5dc5f0
  L5dc65b:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @26_5dc5f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @27_5dc5f0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @28_5dc5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5dc5f0
  PS[0] = esi;  // @30_5dc5f0
  reg.state = (s32)((u32)(0));  // @31_5dc5f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_5dc5f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5dc5f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @34_5dc5f0
  ecx = edx = 0;  // @35_5dc5f0
  SEH_LEAVE();  // @36_5dc5f0
  return eax;  // @37_5dc5f0
}
PCREG(5dc5f0, lifted_5dc5f0);

extern "C" u32 THISCALL lifted_46a870(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_46a870
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_46a870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @1_46a870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @2_46a870
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @3_46a870
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_46a870
  PS[0] = esi;  // @6_46a870
  reg.state = (s32)((u32)(0));  // @7_46a870
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_46a870
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @10_46a870
  ecx = edx = 0;  // @11_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_46a870
  reg.state = (s32)((u32)(4294967295));  // @13_46a870
  if (((eax & 0xff) & (u32)(1)) == 0) goto L46a920;  // @14_46a870
  if (((eax & 0xff) & (u32)(4)) != 0) goto L46a915;  // @15_46a870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @16_46a870
  reg.state = (s32)((u32)(1));  // @17_46a870
  if ((eax & eax) == 0) goto L46a900;  // @18_46a870
  eax = ((u32(STDCALL *)(void))(eax))();  // @19_46a870
  ecx = edx = 0;  // @20_46a870
  eax = esi;  // @21_46a870
  SEH_LEAVE();  // @22_46a870
  return eax;  // @23_46a870
  L46a900:;
  __builtin_trap();  // @25_46a870
  L46a915:;
  PS[1] = esi;  // @27_46a870
  eax = ext_4690b0_cdecl2((u32)(PS[1]), (u32)(94));  // @28_46a870
  ecx = edx = 0;  // @29_46a870
  L46a920:;
  eax = esi;  // @31_46a870
  SEH_LEAVE();  // @32_46a870
  return eax;  // @33_46a870
}
PCREG(46a870, lifted_46a870);

extern "C" u32 THISCALL lifted_5c6050(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);  // @h_5c6050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5c6050
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @1_5c6050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @2_5c6050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @3_5c6050
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5c6050
  PS[0] = esi;  // @6_5c6050
  reg.state = (s32)((u32)(0));  // @7_5c6050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_5c6050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @10_5c6050
  ecx = edx = 0;  // @11_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_5c6050
  reg.state = (s32)((u32)(4294967295));  // @13_5c6050
  if (((eax & 0xff) & (u32)(1)) == 0) goto L5c60fd;  // @14_5c6050
  if (((eax & 0xff) & (u32)(4)) != 0) goto L5c60f2;  // @15_5c6050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @16_5c6050
  reg.state = (s32)((u32)(1));  // @17_5c6050
  if ((eax & eax) == 0) goto L5c60dd;  // @18_5c6050
  eax = ((u32(STDCALL *)(void))(eax))();  // @19_5c6050
  ecx = edx = 0;  // @20_5c6050
  eax = esi;  // @21_5c6050
  SEH_LEAVE();  // @22_5c6050
  return eax;  // @23_5c6050
  L5c60dd:;
  __builtin_trap();  // @25_5c6050
  L5c60f2:;
  PS[1] = esi;  // @27_5c6050
  eax = ext_4690b0_cdecl2((u32)(PS[1]), (u32)(85));  // @28_5c6050
  ecx = edx = 0;  // @29_5c6050
  L5c60fd:;
  eax = esi;  // @31_5c6050
  SEH_LEAVE();  // @32_5c6050
  return eax;  // @33_5c6050
}
PCREG(5c6050, lifted_5c6050);

extern "C" u32 THISCALL lifted_449ed0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_449ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
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
  PS[0] = edi;  // @19_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(PS[0]));  // @21_449ed0
  ecx = edx = 0;  // @22_449ed0
  if ((eax & eax) != 0) goto L449f47;  // @23_449ed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @24_449ed0
  PS[0] = edi;  // @25_449ed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_449ed0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @27_449ed0
  ecx = edx = 0;  // @28_449ed0
  L449f47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_449ed0
  ecx = esi;  // @31_449ed0
  PS[1] = edi;  // @32_449ed0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 560)))(ecx, (u32)(PS[1]), (u32)(1));  // @33_449ed0
  ecx = edx = 0;  // @34_449ed0
  SEH_LEAVE();  // @35_449ed0
  return eax;  // @36_449ed0
}
PCREG(449ed0, lifted_449ed0);

extern "C" u32 FASTCALL lifted_45ace0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666539);  // @h_45ace0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_45ace0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_45ace0
  PS[0] = ecx;  // @2_45ace0
  eax = ext_45c4f0_cdecl2((u32)(36), (u32)(PS[0]));  // @3_45ace0
  ecx = edx = 0;  // @4_45ace0
  esi = eax;  // @5_45ace0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @6_45ace0
  reg.state = (s32)((u32)(0));  // @7_45ace0
  if ((esi & esi) == 0) goto L45ad73;  // @8_45ace0
  ecx = esi;  // @9_45ace0
  PS[2] = edi;  // @10_45ace0
  eax = ext_43de40_thiscall4(ecx, (u32)(PS[2]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @11_45ace0
  ecx = edx = 0;  // @12_45ace0
  { u32 v = (u32)((u32)(6831696)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @13_45ace0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @14_45ace0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @15_45ace0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @16_45ace0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @17_45ace0
  reg.state = (s32)((u32)(1));  // @18_45ace0
  eax = ext_4dcdf0_thiscall2(ecx, (u32)(0));  // @19_45ace0
  ecx = edx = 0;  // @20_45ace0
  eax = esi;  // @21_45ace0
  SEH_LEAVE();  // @22_45ace0
  return eax;  // @23_45ace0
  L45ad73:;
  eax = 0;  // @25_45ace0
  SEH_LEAVE();  // @26_45ace0
  return eax;  // @27_45ace0
}
PCREG(45ace0, lifted_45ace0);

extern "C" u32 THISCALL lifted_5dae30(u32 ecx_in) {
  SEH_ENTER(0x668ea7);  // @h_5dae30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_5dae30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5dae30
  eax = ext_469870_thiscall1(ecx);  // @2_5dae30
  ecx = edx = 0;  // @3_5dae30
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5dae30
  reg.state = (s32)((u32)(0));  // @6_5dae30
  { u32 v = (u32)((u32)(7038804)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @8_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @9_5dae30
  { u32 v = (u32)((u32)(1045220557)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @10_5dae30
  eax = ext_41e290_cdecl1((u32)(28));  // @11_5dae30
  ecx = edx = 0;  // @12_5dae30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_5dae30
  reg.state = (s32)((u32)(1));  // @14_5dae30
  if ((eax & eax) == 0) goto L5daeaf;  // @15_5dae30
  ecx = eax;  // @16_5dae30
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @17_5dae30
  ecx = edx = 0;  // @18_5dae30
  goto L5daeb1;  // @19_5dae30
  L5daeaf:;
  eax = 0;  // @21_5dae30
  L5daeb1:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @23_5dae30
  eax = esi;  // @24_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @25_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @26_5dae30
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @27_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @28_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @29_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @30_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @31_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @32_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @33_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @34_5dae30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @35_5dae30
  SEH_LEAVE();  // @36_5dae30
  return eax;  // @37_5dae30
}
PCREG(5dae30, lifted_5dae30);

extern "C" u32 THISCALL lifted_5ebbd0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5ebbd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  edi = ecx;  // @0_5ebbd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @1_5ebbd0
  { u32 v = (u32)((u32)(7045364)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_5ebbd0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; })) goto L5ebc19;  // @3_5ebbd0
  L5ebc05:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(44));  // @5_5ebbd0
  ecx = edx = 0;  // @6_5ebbd0
  esi = (esi + (u32)(4));  // @7_5ebbd0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; })) goto L5ebc05;  // @8_5ebbd0
  L5ebc19:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; });  // @10_5ebbd0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }), (u32)(40));  // @11_5ebbd0
  ecx = edx = 0;  // @12_5ebbd0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 58), sizeof v); (u32)v; }), (u32)(8));  // @13_5ebbd0
  ecx = edx = 0;  // @14_5ebbd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @15_5ebbd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @16_5ebbd0
  eax = (eax - ecx);  // @17_5ebbd0
  eax = (u32)((s32)eax >> (u32)(2));  // @18_5ebbd0
  reg.state = (s32)((u32)(0));  // @19_5ebbd0
  if ((eax & eax) == 0) goto L5ebc56;  // @20_5ebbd0
  eax = (eax << (u32)(2));  // @21_5ebbd0
  PS[0] = eax;  // @22_5ebbd0
  PS[1] = ecx;  // @23_5ebbd0
  ecx = (u32)(edi + 98);  // @24_5ebbd0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @25_5ebbd0
  ecx = edx = 0;  // @26_5ebbd0
  L5ebc56:;
  { u32 v = (u32)((u32)(7012828)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @28_5ebbd0
  SEH_LEAVE();  // @29_5ebbd0
  return eax;  // @30_5ebbd0
}

extern "C" u32 THISCALL lifted_5f1370(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_5f1370
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_5f1370
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; }), (u32)(8));  // @1_5f1370
  ecx = edx = 0;  // @2_5f1370
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @3_5f1370
  if ((edi & edi) == 0) goto L5f13bf;  // @4_5f1370
  ecx = edi;  // @5_5f1370
  eax = ext_5fb000_thiscall1(ecx);  // @6_5f1370
  ecx = edx = 0;  // @7_5f1370
  PS[1] = edi;  // @8_5f1370
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(77));  // @9_5f1370
  ecx = edx = 0;  // @10_5f1370
  L5f13bf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_5f1370
  if ((ecx & ecx) == 0) goto L5f13cb;  // @13_5f1370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5f1370
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @15_5f1370
  ecx = edx = 0;  // @16_5f1370
  L5f13cb:;
  ecx = (u32)(esi + 172);  // @18_5f1370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @19_5f1370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5f1370
  eax = (eax - edx);  // @21_5f1370
  eax = (u32)((s32)eax >> (u32)(2));  // @22_5f1370
  reg.state = (s32)((u32)(0));  // @23_5f1370
  if ((eax & eax) == 0) goto L5f13f0;  // @24_5f1370
  eax = (eax << (u32)(2));  // @25_5f1370
  PS[0] = eax;  // @26_5f1370
  PS[1] = edx;  // @27_5f1370
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @28_5f1370
  ecx = edx = 0;  // @29_5f1370
  L5f13f0:;
  ecx = (u32)(esi + 20);  // @31_5f1370
  eax = ext_4cbec0_thiscall1(ecx);  // @32_5f1370
  ecx = edx = 0;  // @33_5f1370
  ecx = (u32)(esi + 8);  // @34_5f1370
  eax = ext_6042f0_thiscall1(ecx);  // @35_5f1370
  ecx = edx = 0;  // @36_5f1370
  SEH_LEAVE();  // @37_5f1370
  return eax;  // @38_5f1370
}
PCREG(5f1370, lifted_5f1370);

extern "C" u32 THISCALL lifted_435920(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66588e);  // @h_435920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
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
  PS[0] = edx;  // @31_435920
  reg.state = (s32)((u32)(4294967295));  // @32_435920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_435920
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(PS[0]));  // @34_435920
  ecx = edx = 0;  // @35_435920
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @36_435920
  SEH_LEAVE();  // @37_435920
  return eax;  // @38_435920
}
PCREG(435920, lifted_435920);

extern "C" u32 THISCALL lifted_5898c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_5898c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_5898c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5898c0
  if (eax != (u32)(12)) goto L58994d;  // @2_5898c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_5898c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5898c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6995856), (u32)(392));  // @5_5898c0
  ecx = edx = 0;  // @6_5898c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_5898c0
  edi = eax;  // @8_5898c0
  eax = (u32)(EBP - 144);  // @9_5898c0
  ecx = esi;  // @10_5898c0
  PS[1] = eax;  // @11_5898c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @12_5898c0
  ecx = edx = 0;  // @13_5898c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @14_5898c0
  ecx = eax;  // @15_5898c0
  reg.state = (s32)((u32)(0));  // @16_5898c0
  eax = ext_4cc1d0_thiscall1(ecx);  // @17_5898c0
  ecx = edx = 0;  // @18_5898c0
  PS[0] = eax;  // @19_5898c0
  PS[2] = edi;  // @20_5898c0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6995992), (u32)(PS[0]));  // @21_5898c0
  ecx = edx = 0;  // @22_5898c0
  ecx = (u32)(EBP - 144);  // @23_5898c0
  eax = ext_4cbec0_thiscall1(ecx);  // @24_5898c0
  ecx = edx = 0;  // @25_5898c0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @26_5898c0
  goto L589955;  // @27_5898c0
  L58994d:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 4), &v, sizeof v); }  // @29_5898c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @30_5898c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @31_5898c0
  L589955:;
  SEH_LEAVE();  // @33_5898c0
  ext_633654(G(u32, 0x6f5630));  // @34_5898c0
  return eax;  // @35_5898c0
}
PCREG(5898c0, lifted_5898c0);

extern "C" u32 THISCALL lifted_5faf50(u32 ecx_in) {
  SEH_ENTER(0x66d3c8);  // @h_5faf50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_5faf50
  ecx = (u32)(esi + 35);  // @1_5faf50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @2_5faf50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5faf50
  eax = (eax - edx);  // @4_5faf50
  eax = (u32)((s32)eax >> (u32)(1));  // @5_5faf50
  reg.state = (s32)((u32)(0));  // @6_5faf50
  if (eax == 0) goto L5faf93;  // @7_5faf50
  eax = (eax + eax);  // @8_5faf50
  PS[0] = eax;  // @9_5faf50
  PS[1] = edx;  // @10_5faf50
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @11_5faf50
  ecx = edx = 0;  // @12_5faf50
  L5faf93:;
  ecx = (u32)(esi + 23);  // @14_5faf50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @15_5faf50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5faf50
  eax = (eax - edx);  // @17_5faf50
  eax = (u32)((s32)eax >> (u32)(2));  // @18_5faf50
  reg.state = (s32)((u32)(1));  // @19_5faf50
  if ((eax & eax) == 0) goto L5fafb5;  // @20_5faf50
  eax = (eax << (u32)(2));  // @21_5faf50
  PS[0] = eax;  // @22_5faf50
  PS[1] = edx;  // @23_5faf50
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @24_5faf50
  ecx = edx = 0;  // @25_5faf50
  L5fafb5:;
  ecx = (u32)(esi + 4);  // @27_5faf50
  reg.state = (s32)((u32)(2));  // @28_5faf50
  eax = ext_5fb600_thiscall1(ecx);  // @29_5faf50
  ecx = edx = 0;  // @30_5faf50
  ecx = (u32)(esi + 7);  // @31_5faf50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @32_5faf50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_5faf50
  eax = (eax - edx);  // @34_5faf50
  eax = (u32)((s32)eax >> (u32)(2));  // @35_5faf50
  reg.state = (s32)((u32)(3));  // @36_5faf50
  if ((eax & eax) == 0) goto L5fafe3;  // @37_5faf50
  eax = (eax << (u32)(2));  // @38_5faf50
  PS[0] = eax;  // @39_5faf50
  PS[1] = edx;  // @40_5faf50
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @41_5faf50
  ecx = edx = 0;  // @42_5faf50
  L5fafe3:;
  SEH_LEAVE();  // @44_5faf50
  return eax;  // @45_5faf50
}
PCREG(5faf50, lifted_5faf50);

extern "C" u32 THISCALL lifted_465660(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_465660
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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
  PS[0] = edi;  // @12_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @13_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(PS[0]));  // @15_465660
  ecx = edx = 0;  // @16_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_465660
  esi = eax;  // @18_465660
  PS[0] = esi;  // @19_465660
  ecx = ebx;  // @20_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 556)))(ecx, (u32)(PS[0]));  // @21_465660
  ecx = edx = 0;  // @22_465660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @23_465660
  PS[0] = esi;  // @24_465660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_465660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @26_465660
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

extern "C" u32 FASTCALL lifted_4808d0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x667359);  // @h_4808d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = edx;  // @0_4808d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4808d0
  PS[0] = ecx;  // @2_4808d0
  eax = ext_45c4f0_cdecl2((u32)(1611), (u32)(PS[0]));  // @3_4808d0
  ecx = edx = 0;  // @4_4808d0
  esi = eax;  // @5_4808d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @6_4808d0
  reg.state = (s32)((u32)(0));  // @7_4808d0
  if ((esi & esi) == 0) goto L480967;  // @8_4808d0
  ecx = esi;  // @9_4808d0
  PS[2] = edi;  // @10_4808d0
  eax = ext_480a40_thiscall4(ecx, (u32)(PS[2]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @11_4808d0
  ecx = edx = 0;  // @12_4808d0
  { u32 v = (u32)((u32)(6865084)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @13_4808d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4808d0
  reg.state = (s32)((u32)(1));  // @15_4808d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @16_4808d0
  if ((ecx & ecx) == 0) goto L480952;  // @17_4808d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4808d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 12)))(ecx, (u32)(7233608), (u32)(6866696), (u32)(0));  // @19_4808d0
  ecx = edx = 0;  // @20_4808d0
  L480952:;
  eax = esi;  // @22_4808d0
  SEH_LEAVE();  // @23_4808d0
  return eax;  // @24_4808d0
  L480967:;
  eax = 0;  // @26_4808d0
  SEH_LEAVE();  // @27_4808d0
  return eax;  // @28_4808d0
}
PCREG(4808d0, lifted_4808d0);

extern "C" u32 FASTCALL lifted_6054b0(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x66dde7);  // @h_6054b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, PS[16];
  edi = edx;  // @0_6054b0
  ebx = ecx;  // @1_6054b0
  eax = ext_41e290_cdecl1((u32)(18));  // @2_6054b0
  ecx = edx = 0;  // @3_6054b0
  esi = eax;  // @4_6054b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_6054b0
  reg.state = (s32)((u32)(0));  // @6_6054b0
  if ((esi & esi) == 0) goto L605534;  // @7_6054b0
  PS[0] = edi;  // @8_6054b0
  PS[1] = ebx;  // @9_6054b0
  ecx = esi;  // @10_6054b0
  eax = ext_5f9700_thiscall3(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @11_6054b0
  ecx = edx = 0;  // @12_6054b0
  reg.state = (s32)((u32)(1));  // @13_6054b0
  { u32 v = (u32)((u32)(7052156)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_6054b0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489384), sizeof v); (u32)v; }) != (u32)(0)) goto L605517;  // @15_6054b0
  ecx = esi;  // @16_6054b0
  eax = ext_604ca0_thiscall1(ecx);  // @17_6054b0
  ecx = edx = 0;  // @18_6054b0
  L605517:;
  PS[0] = edi;  // @20_6054b0
  PS[1] = ebx;  // @21_6054b0
  ecx = esi;  // @22_6054b0
  eax = ext_6052f0_thiscall3(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @23_6054b0
  ecx = edx = 0;  // @24_6054b0
  eax = esi;  // @25_6054b0
  SEH_LEAVE();  // @26_6054b0
  return eax;  // @27_6054b0
  L605534:;
  eax = 0;  // @29_6054b0
  SEH_LEAVE();  // @30_6054b0
  return eax;  // @31_6054b0
}
PCREG(6054b0, lifted_6054b0);

