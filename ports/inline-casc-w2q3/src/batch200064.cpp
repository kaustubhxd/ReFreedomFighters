// batch200064.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_63418c_stdcall4(u32, u32, u32, u32) __asm__("ext_63418c");
extern "C" u32 THISCALL ext_43a800_thiscall1(u32) __asm__("ext_43a800");
extern "C" u32 THISCALL ext_43aa30_thiscall1(u32) __asm__("ext_43aa30");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43e0f0_thiscall1(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_460e40_thiscall4(u32, u32, u32, u32) __asm__("ext_460e40");
extern "C" u32 THISCALL ext_461f00_thiscall1(u32) __asm__("ext_461f00");
extern "C" u32 THISCALL ext_466220_thiscall1(u32) __asm__("ext_466220");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_477480_thiscall1(u32) __asm__("ext_477480");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd160_thiscall1(u32) __asm__("ext_4cd160");
extern "C" u32 THISCALL ext_4d1390_thiscall3(u32, u32, u32) __asm__("ext_4d1390");
extern "C" u32 THISCALL ext_4d2030_thiscall2(u32, u32) __asm__("ext_4d2030");
extern "C" u32 THISCALL ext_4d8d50_thiscall1(u32) __asm__("ext_4d8d50");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6680_thiscall1(u32) __asm__("ext_4e6680");
extern "C" u32 THISCALL ext_4e66a0_thiscall1(u32) __asm__("ext_4e66a0");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_533d60_thiscall1(u32) __asm__("ext_533d60");
extern "C" u32 THISCALL ext_53a8f0_thiscall1(u32) __asm__("ext_53a8f0");
extern "C" u32 THISCALL ext_540ed0_thiscall1(u32) __asm__("ext_540ed0");
extern "C" u32 THISCALL ext_545ee0_thiscall2(u32, u32) __asm__("ext_545ee0");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f37f0_thiscall3(u32, u32, u32) __asm__("ext_5f37f0");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 THISCALL ext_635490_thiscall1(u32) __asm__("ext_635490");
extern "C" u32 THISCALL ext_645120_thiscall2(u32, u32) __asm__("ext_645120");
extern "C" u32 THISCALL ext_648280_thiscall1(u32) __asm__("ext_648280");
extern "C" u32 THISCALL ext_64b070_thiscall1(u32) __asm__("ext_64b070");
extern "C" u32 THISCALL ext_64f380_thiscall1(u32) __asm__("ext_64f380");
extern "C" u32 THISCALL ext_651040_thiscall2(u32, u32) __asm__("ext_651040");
extern "C" u32 THISCALL ext_6593c0_thiscall1(u32) __asm__("ext_6593c0");
extern "C" u32 THISCALL ext_65c7f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_65c7f0");
extern "C" u32 THISCALL ext_65e130_thiscall1(u32) __asm__("ext_65e130");
extern "C" u32 THISCALL ext_65f0f0_thiscall1(u32) __asm__("ext_65f0f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_45c510_cdecl1(...) __asm__("ext_45c510");
extern "C" u32 ext_4690b0_cdecl2(...) __asm__("ext_4690b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_545350_cdecl0(void) __asm__("ext_545350");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_65e130(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_65e130
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_65e130
  { u32 v = (u32)((u32)(7096564)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_65e130
  eax = ext_65f0f0_thiscall1(ecx);  // @2_65e130
  ecx = edx = 0;  // @3_65e130
  eax = (u32)(esi + 4);  // @4_65e130
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(12), (u32)(16), (u32)(4624560));  // @5_65e130
  ecx = edx = 0;  // @6_65e130
  SEH_LEAVE();  // @7_65e130
  return eax;  // @8_65e130
}
PCREG(65e130, lifted_65e130);

extern "C" u32 STDCALL lifted_64f940(u32 a0) {
  SEH_ENTER(0x66ec62);  // @h_64f940
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ext_41e290_cdecl1((u32)(662));  // @0_64f940
  ecx = edx = 0;  // @1_64f940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_64f940
  reg.state = (s32)((u32)(0));  // @3_64f940
  if ((eax & eax) == 0) goto L64f999;  // @4_64f940
  ecx = eax;  // @5_64f940
  eax = ext_645120_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @6_64f940
  ecx = edx = 0;  // @7_64f940
  SEH_LEAVE();  // @8_64f940
  return eax;  // @9_64f940
  L64f999:;
  eax = 0;  // @11_64f940
  SEH_LEAVE();  // @12_64f940
  return eax;  // @13_64f940
}
PCREG(64f940, lifted_64f940);

extern "C" u32 THISCALL lifted_65e190(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_65e190
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_65e190
  reg.state = (s32)((u32)(0));  // @1_65e190
  { u32 v = (u32)((u32)(7096564)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_65e190
  eax = ext_65f0f0_thiscall1(ecx);  // @3_65e190
  ecx = edx = 0;  // @4_65e190
  eax = (u32)(esi + 4);  // @5_65e190
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(12), (u32)(16), (u32)(4624560));  // @6_65e190
  ecx = edx = 0;  // @7_65e190
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L65e1ed;  // @8_65e190
  eax = ext_634273_cdecl2((u32)(esi), (u32)(14036));  // @9_65e190
  ecx = edx = 0;  // @10_65e190
  L65e1ed:;
  eax = esi;  // @12_65e190
  SEH_LEAVE();  // @13_65e190
  return eax;  // @14_65e190
}
PCREG(65e190, lifted_65e190);

extern "C" u32 THISCALL lifted_65bd80(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66edc2);  // @h_65bd80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_65bd80
  eax = ext_41e290_cdecl1((u32)(98981));  // @1_65bd80
  ecx = edx = 0;  // @2_65bd80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_65bd80
  reg.state = (s32)((u32)(0));  // @4_65bd80
  if ((eax & eax) == 0) goto L65bde7;  // @5_65bd80
  ecx = eax;  // @6_65bd80
  eax = ext_65c7f0_thiscall5(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 236), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @7_65bd80
  ecx = edx = 0;  // @8_65bd80
  SEH_LEAVE();  // @9_65bd80
  return eax;  // @10_65bd80
  L65bde7:;
  eax = 0;  // @12_65bd80
  SEH_LEAVE();  // @13_65bd80
  return eax;  // @14_65bd80
}
PCREG(65bd80, lifted_65bd80);

extern "C" u32 THISCALL lifted_63ab30(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_63ab30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  ebx = ecx;  // @0_63ab30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_63ab30
  edi = 0;  // @2_63ab30
  { u32 v = (u32)((u32)(7086900)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @3_63ab30
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }) == edi) goto L63aba4;  // @4_63ab30
  ebx = (ebx + (u32)(240));  // @5_63ab30
  L63ab71:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_63ab30
  ecx = esi;  // @8_63ab30
  eax = ext_64b070_thiscall1(ecx);  // @9_63ab30
  ecx = edx = 0;  // @10_63ab30
  if ((esi & esi) == 0) goto L63ab93;  // @11_63ab30
  ecx = esi;  // @12_63ab30
  eax = ext_648280_thiscall1(ecx);  // @13_63ab30
  ecx = edx = 0;  // @14_63ab30
  eax = ext_634273_cdecl2((u32)(esi), (u32)(98977));  // @15_63ab30
  ecx = edx = 0;  // @16_63ab30
  L63ab93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @18_63ab30
  edi = (edi + 1);  // @19_63ab30
  ebx = (ebx + (u32)(4));  // @20_63ab30
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 236), sizeof v); (u32)v; })) goto L63ab71;  // @21_63ab30
  ebx = eax;  // @22_63ab30
  L63aba4:;
  ecx = (u32)(ebx + 47504);  // @24_63ab30
  eax = ext_4cd160_thiscall1(ecx);  // @25_63ab30
  ecx = edx = 0;  // @26_63ab30
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47433), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(ebx + 47433), &v, sizeof v); }  // @27_63ab30
  ecx = (u32)(ebx + 33392);  // @28_63ab30
  eax = ext_65e130_thiscall1(ecx);  // @29_63ab30
  ecx = edx = 0;  // @30_63ab30
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(ebx + 25), &v, sizeof v); }  // @31_63ab30
  SEH_LEAVE();  // @32_63ab30
  return eax;  // @33_63ab30
}
PCREG(63ab30, lifted_63ab30);

extern "C" u32 THISCALL lifted_64f270(u32 ecx_in) {
  SEH_ENTER(0x66ec33);  // @h_64f270
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_64f270
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_64f270
  eax = ext_4e6680_thiscall1(ecx);  // @2_64f270
  ecx = edx = 0;  // @3_64f270
  ecx = (u32)(esi + 64);  // @4_64f270
  reg.state = (s32)((u32)(0));  // @5_64f270
  { u32 v = (u32)((u32)(7090372)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_64f270
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(7));  // @7_64f270
  ecx = edx = 0;  // @8_64f270
  ecx = esi;  // @9_64f270
  reg.state = (s32)((u32)(1));  // @10_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @11_64f270
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @12_64f270
  eax = ext_651040_thiscall2(ecx, (u32)(0));  // @13_64f270
  ecx = edx = 0;  // @14_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @15_64f270
  eax = esi;  // @16_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @17_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @18_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @19_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @20_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @21_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @22_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @23_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @24_64f270
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }  // @25_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @26_64f270
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @27_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @28_64f270
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @29_64f270
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @30_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @31_64f270
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @32_64f270
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @33_64f270
  { u32 v = (u32)((u32)(4280295472)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @34_64f270
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @35_64f270
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 136), &v, sizeof v); }  // @36_64f270
  SEH_LEAVE();  // @37_64f270
  return eax;  // @38_64f270
}
PCREG(64f270, lifted_64f270);

extern "C" u32 THISCALL lifted_658020(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_658020
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_658020
  { u32 v = (u32)((u32)(7094276)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_658020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4575), sizeof v); (u32)v; }));  // @4_658020
  ecx = edx = 0;  // @5_658020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4575), sizeof v); (u32)v; });  // @6_658020
  if ((ecx & ecx) == 0) goto L65806f;  // @7_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @9_658020
  ecx = edx = 0;  // @10_658020
  L65806f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4571), sizeof v); (u32)v; }));  // @14_658020
  ecx = edx = 0;  // @15_658020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4571), sizeof v); (u32)v; });  // @16_658020
  if ((ecx & ecx) == 0) goto L658093;  // @17_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @19_658020
  ecx = edx = 0;  // @20_658020
  L658093:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4579), sizeof v); (u32)v; }));  // @24_658020
  ecx = edx = 0;  // @25_658020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4579), sizeof v); (u32)v; });  // @26_658020
  if ((ecx & ecx) == 0) goto L6580b7;  // @27_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @29_658020
  ecx = edx = 0;  // @30_658020
  L6580b7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4419), sizeof v); (u32)v; });  // @32_658020
  if ((ecx & ecx) == 0) goto L6580c7;  // @33_658020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_658020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @35_658020
  ecx = edx = 0;  // @36_658020
  L6580c7:;
  ecx = esi;  // @38_658020
  eax = ext_64f380_thiscall1(ecx);  // @39_658020
  ecx = edx = 0;  // @40_658020
  SEH_LEAVE();  // @41_658020
  return eax;  // @42_658020
}
PCREG(658020, lifted_658020);

extern "C" u32 THISCALL lifted_64f530(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_64f530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_64f530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @1_64f530
  { u32 v = (u32)((u32)(7090372)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_64f530
  if ((ecx & ecx) == 0) goto L64f569;  // @3_64f530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_64f530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_64f530
  ecx = edx = 0;  // @6_64f530
  L64f569:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @8_64f530
  if ((ecx & ecx) == 0) goto L64f57a;  // @9_64f530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_64f530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 352)))(ecx, (u32)(1));  // @11_64f530
  ecx = edx = 0;  // @12_64f530
  L64f57a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @14_64f530
  if ((eax & eax) == 0) goto L64f58c;  // @15_64f530
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @16_64f530
  ecx = edx = 0;  // @17_64f530
  L64f58c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; });  // @19_64f530
  if ((ecx & ecx) == 0) goto L64f59a;  // @20_64f530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_64f530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(1));  // @22_64f530
  ecx = edx = 0;  // @23_64f530
  L64f59a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @25_64f530
  if ((eax & eax) == 0) goto L64f5ac;  // @26_64f530
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @27_64f530
  ecx = edx = 0;  // @28_64f530
  L64f5ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @30_64f530
  ecx = (u32)(edi + 64);  // @31_64f530
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @32_64f530
  ecx = edx = 0;  // @33_64f530
  ecx = (u32)(edi + 64);  // @34_64f530
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @35_64f530
  eax = ext_4cce40_thiscall1(ecx);  // @36_64f530
  ecx = edx = 0;  // @37_64f530
  ecx = edi;  // @38_64f530
  eax = ext_4e66a0_thiscall1(ecx);  // @39_64f530
  ecx = edx = 0;  // @40_64f530
  SEH_LEAVE();  // @41_64f530
  return eax;  // @42_64f530
}
PCREG(64f530, lifted_64f530);

extern "C" u32 THISCALL lifted_644900(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e95f);  // @h_644900
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_644900
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_644900
  eax = (u32)(ebx + 58);  // @2_644900
  ecx = edi;  // @3_644900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @5_644900
  ecx = edx = 0;  // @6_644900
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_644900
  eax = (u32)(ebx + 8);  // @8_644900
  ecx = edi;  // @9_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @10_644900
  ecx = edx = 0;  // @11_644900
  eax = ext_41e290_cdecl1((u32)(101));  // @12_644900
  ecx = edx = 0;  // @13_644900
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_644900
  reg.state = (s32)((u32)(0));  // @15_644900
  if ((eax & eax) == 0) goto L644961;  // @16_644900
  ecx = eax;  // @17_644900
  eax = ext_540ed0_thiscall1(ecx);  // @18_644900
  ecx = edx = 0;  // @19_644900
  goto L644963;  // @20_644900
  L644961:;
  eax = 0;  // @22_644900
  L644963:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 383), &v, sizeof v); }  // @24_644900
  esi = (u32)(ebx + 21);  // @25_644900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_644900
  ecx = edi;  // @27_644900
  reg.state = (s32)((u32)(4294967295));  // @28_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(esi));  // @29_644900
  ecx = edx = 0;  // @30_644900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @31_644900
  ecx = (u32)(ebx + 62);  // @32_644900
  ecx = edi;  // @33_644900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(ecx));  // @34_644900
  ecx = edx = 0;  // @35_644900
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) == (u32)(0)) goto L64499d;  // @36_644900
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 62), sizeof v); (u32)v; }) == (u32)(0)) goto L64499d;  // @37_644900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 383), sizeof v); (u32)v; });  // @38_644900
  eax = ext_545ee0_thiscall2(ecx, (u32)(edi));  // @39_644900
  ecx = edx = 0;  // @40_644900
  L64499d:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @42_644900
  SEH_LEAVE();  // @43_644900
  return eax;  // @44_644900
}
PCREG(644900, lifted_644900);

extern "C" u32 THISCALL lifted_4afc70(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4afc70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4afc70
  eax = (u32)(EBP - 148);  // @1_4afc70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_4afc70
  eax = ext_6352f0_thiscall2(ecx, (u32)(eax));  // @3_4afc70
  ecx = edx = 0;  // @4_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_4afc70
  ecx = (u32)(EBP - 148);  // @6_4afc70
  ecx = ebx;  // @7_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(ecx));  // @8_4afc70
  ecx = edx = 0;  // @9_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @10_4afc70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L4afd33;  // @11_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @12_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2305));  // @14_4afc70
  ecx = edx = 0;  // @15_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @16_4afc70
  edi = eax;  // @17_4afc70
  eax = (u32)(EBP - 144);  // @18_4afc70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @20_4afc70
  ecx = edx = 0;  // @21_4afc70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_4afc70
  ecx = eax;  // @23_4afc70
  reg.state = (s32)((u32)(0));  // @24_4afc70
  eax = ext_4cc1d0_thiscall1(ecx);  // @25_4afc70
  ecx = edx = 0;  // @26_4afc70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6890728), (u32)(eax));  // @27_4afc70
  ecx = edx = 0;  // @28_4afc70
  ecx = (u32)(EBP - 144);  // @29_4afc70
  eax = ext_4cbec0_thiscall1(ecx);  // @30_4afc70
  ecx = edx = 0;  // @31_4afc70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @32_4afc70
  if ((ecx & ecx) == 0) goto L4afd33;  // @33_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @35_4afc70
  ecx = edx = 0;  // @36_4afc70
  L4afd33:;
  SEH_LEAVE();  // @38_4afc70
  ext_633654(G(u32, 0x6f5630));  // @39_4afc70
  return eax;  // @40_4afc70
}
PCREG(4afc70, lifted_4afc70);

extern "C" u32 THISCALL lifted_5fbb00(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d4d2);  // @h_5fbb00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_5fbb00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @2_5fbb00
  if ((eax & eax) == 0) goto L5fbb3a;  // @3_5fbb00
  L5fbb31:;
  esi = eax;  // @5_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @6_5fbb00
  if ((eax & eax) != 0) goto L5fbb31;  // @7_5fbb00
  L5fbb3a:;
  eax = ext_41e290_cdecl1((u32)(2770));  // @9_5fbb00
  ecx = edx = 0;  // @10_5fbb00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_5fbb00
  reg.state = (s32)((u32)(0));  // @12_5fbb00
  if ((eax & eax) == 0) goto L5fbb64;  // @13_5fbb00
  ecx = eax;  // @14_5fbb00
  eax = ext_5f37f0_thiscall3(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @15_5fbb00
  ecx = edx = 0;  // @16_5fbb00
  edi = eax;  // @17_5fbb00
  goto L5fbb66;  // @18_5fbb00
  L5fbb64:;
  edi = 0;  // @20_5fbb00
  L5fbb66:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @22_5fbb00
  reg.state = (s32)((u32)(4294967295));  // @23_5fbb00
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; })) goto L5fbb7d;  // @24_5fbb00
  ecx = (u32)(esi + 88);  // @25_5fbb00
  eax = ext_5f4630_thiscall1(ecx);  // @26_5fbb00
  ecx = edx = 0;  // @27_5fbb00
  L5fbb7d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @29_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 88), sizeof v); (u32)v; });  // @30_5fbb00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @31_5fbb00
  ecx = (u32)(65521);  // @32_5fbb00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @33_5fbb00
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 172), sizeof v); (u32)v; })) & 0xffff);  // @34_5fbb00
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) & (ecx & 0xffff))) & 0xffff);  // @35_5fbb00
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) | (u32)(1))) & 0xffff);  // @36_5fbb00
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 172), &v, sizeof v); }  // @37_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @38_5fbb00
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; })) goto L5fbbb3;  // @39_5fbb00
  ecx = (u32)(ebx + 24);  // @40_5fbb00
  eax = ext_5f4630_thiscall1(ecx);  // @41_5fbb00
  ecx = edx = 0;  // @42_5fbb00
  L5fbbb3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @44_5fbb00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @45_5fbb00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @46_5fbb00
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @47_5fbb00
  SEH_LEAVE();  // @48_5fbb00
  return eax;  // @49_5fbb00
}
PCREG(5fbb00, lifted_5fbb00);

extern "C" u32 THISCALL lifted_4d1530(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4d1530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @1_4d1530
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4d1530
  if ((eax & eax) == 0) goto L4d1574;  // @3_4d1530
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @4_4d1530
  ecx = edx = 0;  // @5_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @6_4d1530
  L4d1574:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @8_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @9_4d1530
  if ((eax & eax) == 0) goto L4d158d;  // @10_4d1530
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @11_4d1530
  ecx = edx = 0;  // @12_4d1530
  L4d158d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) == (u32)(0)) goto L4d15a7;  // @14_4d1530
  L4d1593:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @16_4d1530
  if ((ecx & ecx) == 0) goto L4d15a1;  // @17_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4d1530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @19_4d1530
  ecx = edx = 0;  // @20_4d1530
  L4d15a1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L4d1593;  // @22_4d1530
  L4d15a7:;
  ecx = esi;  // @24_4d1530
  eax = ext_4d2030_thiscall2(ecx, (u32)(-1));  // @25_4d1530
  ecx = edx = 0;  // @26_4d1530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @27_4d1530
  if ((ecx & ecx) == 0) goto L4d15ec;  // @28_4d1530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @29_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @30_4d1530
  if ((edx & edx) == 0) goto L4d15c6;  // @31_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 48), &v, sizeof v); }  // @32_4d1530
  goto L4d15c9;  // @33_4d1530
  L4d15c6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 36), &v, sizeof v); }  // @35_4d1530
  L4d15c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @37_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @38_4d1530
  if ((ecx & ecx) == 0) goto L4d15d8;  // @39_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @40_4d1530
  goto L4d15de;  // @41_4d1530
  L4d15d8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @43_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @44_4d1530
  L4d15de:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @46_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @47_4d1530
  L4d15ec:;
  SEH_LEAVE();  // @49_4d1530
  return eax;  // @50_4d1530
}
PCREG(4d1530, lifted_4d1530);

extern "C" u32 THISCALL lifted_475740(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_475740
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_475740
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_475740
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @3_475740
  if ((s32)(esi & esi) >= 0) goto L4757e7;  // @4_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_475740
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_475740
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6854172), (u32)(1000));  // @7_475740
  ecx = edx = 0;  // @8_475740
  edi = eax;  // @9_475740
  ecx = (u32)(EBP - 144);  // @10_475740
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @11_475740
  ecx = eax;  // @12_475740
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_475740
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(ecx), (u32)(1));  // @14_475740
  ecx = edx = 0;  // @15_475740
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_475740
  ecx = eax;  // @17_475740
  reg.state = (s32)((u32)(0));  // @18_475740
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_475740
  ecx = edx = 0;  // @20_475740
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6854632), (u32)(eax));  // @21_475740
  ecx = edx = 0;  // @22_475740
  reg.state = (s32)((u32)(4294967295));  // @23_475740
  ecx = (u32)(EBP - 144);  // @24_475740
  eax = ext_4cbec0_thiscall1(ecx);  // @25_475740
  ecx = edx = 0;  // @26_475740
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @27_475740
  esi = 0;  // @28_475740
  L4757e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @30_475740
  ecx = ebx;  // @31_475740
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1372)))(ecx, (u32)(ecx));  // @32_475740
  ecx = edx = 0;  // @33_475740
  if ((eax & eax) == 0) goto L475801;  // @34_475740
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @35_475740
  ecx = eax;  // @36_475740
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 804)))(ecx, (u32)(esi));  // @37_475740
  ecx = edx = 0;  // @38_475740
  L475801:;
  SEH_LEAVE();  // @40_475740
  ext_633654(G(u32, 0x6f5630));  // @41_475740
  return eax;  // @42_475740
}
PCREG(475740, lifted_475740);

extern "C" u32 THISCALL lifted_462b00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_462b00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_462b00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @1_462b00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @4_462b00
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(edi));  // @5_462b00
  ecx = edx = 0;  // @6_462b00
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462b46;  // @7_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @8_462b00
  goto L462bb2;  // @9_462b00
  L462b46:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @11_462b00
  if ((ecx & ecx) == 0) goto L462b5e;  // @12_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @14_462b00
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(edi));  // @15_462b00
  ecx = edx = 0;  // @16_462b00
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462b5e;  // @17_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; });  // @18_462b00
  goto L462bb2;  // @19_462b00
  L462b5e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @21_462b00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_462b00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6838324), (u32)(1389));  // @23_462b00
  ecx = edx = 0;  // @24_462b00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_462b00
  edi = eax;  // @26_462b00
  eax = (u32)(EBP - 144);  // @27_462b00
  ecx = esi;  // @28_462b00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @29_462b00
  ecx = edx = 0;  // @30_462b00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @31_462b00
  ecx = eax;  // @32_462b00
  reg.state = (s32)((u32)(0));  // @33_462b00
  eax = ext_4cc1d0_thiscall1(ecx);  // @34_462b00
  ecx = edx = 0;  // @35_462b00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6838576), (u32)(eax));  // @36_462b00
  ecx = edx = 0;  // @37_462b00
  ecx = (u32)(EBP - 144);  // @38_462b00
  eax = ext_4cbec0_thiscall1(ecx);  // @39_462b00
  ecx = edx = 0;  // @40_462b00
  eax = 0;  // @41_462b00
  L462bb2:;
  SEH_LEAVE();  // @43_462b00
  ext_633654(G(u32, 0x6f5630));  // @44_462b00
  return eax;  // @45_462b00
}
PCREG(462b00, lifted_462b00);

extern "C" u32 THISCALL lifted_601380(u32 ecx_in) {
  SEH_ENTER(0x66d8d2);  // @h_601380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_601380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_601380
  eax = (eax - (u32)(2));  // @3_601380
  if (eax == 0) goto L6013c4;  // @4_601380
  eax = (eax - (u32)(1));  // @5_601380
  if (eax != 0) goto L6013fc;  // @6_601380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @7_601380
  if ((esi & esi) == 0) goto L6013fc;  // @8_601380
  reg.state = (s32)((u32)(1));  // @9_601380
  goto L6013d2;  // @10_601380
  L6013c4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @12_601380
  if ((esi & esi) == 0) goto L6013fc;  // @13_601380
  reg.state = (s32)((u32)(0));  // @14_601380
  L6013d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @17_601380
  eax = (eax - ecx);  // @18_601380
  if ((ecx & ecx) == 0) goto L6013ea;  // @19_601380
  if ((eax & eax) == 0) goto L6013ea;  // @20_601380
  ecx = esi;  // @21_601380
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @22_601380
  ecx = edx = 0;  // @23_601380
  L6013ea:;
  reg.state = (s32)((u32)(4294967295));  // @25_601380
  eax = ext_634273_cdecl2((u32)(esi), (u32)(12));  // @26_601380
  ecx = edx = 0;  // @27_601380
  L6013fc:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_601380
  if ((esi & esi) == 0) goto L60142d;  // @30_601380
  ecx = (u32)(esi + 12);  // @31_601380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @33_601380
  eax = (eax - edx);  // @34_601380
  reg.state = (s32)((u32)(2));  // @35_601380
  if ((edx & edx) == 0) goto L601422;  // @36_601380
  if ((eax & eax) == 0) goto L601422;  // @37_601380
  eax = ext_54f870_stdcall2((u32)(edx), (u32)(eax));  // @38_601380
  ecx = edx = 0;  // @39_601380
  L601422:;
  eax = ext_634273_cdecl2((u32)(esi), (u32)(24));  // @41_601380
  ecx = edx = 0;  // @42_601380
  L60142d:;
  SEH_LEAVE();  // @44_601380
  return eax;  // @45_601380
}
PCREG(601380, lifted_601380);

extern "C" u32 THISCALL lifted_4558a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_4558a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4558a0
  eax = ext_43e0f0_thiscall1(ecx);  // @1_4558a0
  ecx = edx = 0;  // @2_4558a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) != (u32)(0)) goto L455981;  // @3_4558a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @4_4558a0
  if ((eax & eax) == 0) goto L455981;  // @5_4558a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L455981;  // @6_4558a0
  ecx = (u32)(EBP - 144);  // @7_4558a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @8_4558a0
  ecx = edx = 0;  // @9_4558a0
  ecx = (u32)(EBP - 144);  // @10_4558a0
  reg.state = (s32)((u32)(0));  // @11_4558a0
  eax = ext_456ab0_thiscall1(ecx);  // @12_4558a0
  ecx = edx = 0;  // @13_4558a0
  ecx = (u32)(EBP - 144);  // @14_4558a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 73), &v, sizeof v); }  // @15_4558a0
  reg.state = (s32)((u32)(4294967295));  // @16_4558a0
  eax = ext_4cbec0_thiscall1(ecx);  // @17_4558a0
  ecx = edx = 0;  // @18_4558a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) != (u32)(0)) goto L455981;  // @19_4558a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @20_4558a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4558a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(322));  // @22_4558a0
  ecx = edx = 0;  // @23_4558a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_4558a0
  edi = eax;  // @25_4558a0
  eax = (u32)(EBP - 272);  // @26_4558a0
  ecx = ebx;  // @27_4558a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @28_4558a0
  ecx = edx = 0;  // @29_4558a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_4558a0
  ecx = eax;  // @31_4558a0
  reg.state = (s32)((u32)(1));  // @32_4558a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @33_4558a0
  ecx = edx = 0;  // @34_4558a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6827488), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; }), (u32)(eax));  // @35_4558a0
  ecx = edx = 0;  // @36_4558a0
  ecx = (u32)(EBP - 272);  // @37_4558a0
  eax = ext_4cbec0_thiscall1(ecx);  // @38_4558a0
  ecx = edx = 0;  // @39_4558a0
  L455981:;
  SEH_LEAVE();  // @41_4558a0
  ext_633654(G(u32, 0x6f5630));  // @42_4558a0
  return eax;  // @43_4558a0
}
PCREG(4558a0, lifted_4558a0);

extern "C" u32 FASTCALL lifted_560440(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x66afdf);  // @h_560440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  edi = edx;  // @0_560440
  ebx = ecx;  // @1_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7422364), &v, sizeof v); }  // @2_560440
  eax = ext_41e290_cdecl1((u32)(12));  // @3_560440
  ecx = edx = 0;  // @4_560440
  esi = eax;  // @5_560440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_560440
  reg.state = (s32)((u32)(0));  // @7_560440
  if ((esi & esi) == 0) goto L5604a1;  // @8_560440
  ecx = esi;  // @9_560440
  eax = ext_5f9700_thiscall3(ecx, (u32)(ebx), (u32)(edi));  // @10_560440
  ecx = edx = 0;  // @11_560440
  { u32 v = (u32)((u32)(6971852)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_560440
  goto L5604a3;  // @13_560440
  L5604a1:;
  esi = 0;  // @15_560440
  L5604a3:;
  reg.state = (s32)((u32)(4294967295));  // @17_560440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7422364), &v, sizeof v); }  // @18_560440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422360), sizeof v); (u32)v; }) != (u32)(0)) goto L560514;  // @19_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @20_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @21_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @22_560440
  ecx = (u32)(EBP - 32);  // @23_560440
  reg.state = (s32)((u32)(1));  // @24_560440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @25_560440
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @26_560440
  ecx = edx = 0;  // @27_560440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_560440
  ecx = (u32)(EBP - 32);  // @29_560440
  ecx = esi;  // @30_560440
  reg.state = (s32)((u32)(2));  // @31_560440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(ecx));  // @32_560440
  ecx = edx = 0;  // @33_560440
  ecx = (u32)(EBP - 32);  // @34_560440
  eax = ext_4ff9d0_thiscall1(ecx);  // @35_560440
  ecx = edx = 0;  // @36_560440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422364), sizeof v); (u32)v; });  // @37_560440
  SEH_LEAVE();  // @38_560440
  return eax;  // @39_560440
  L560514:;
  eax = esi;  // @41_560440
  SEH_LEAVE();  // @42_560440
  return eax;  // @43_560440
}
PCREG(560440, lifted_560440);

extern "C" u32 THISCALL lifted_461020(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_461020
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_461020
  reg.state = (s32)((u32)(0));  // @1_461020
  { u32 v = (u32)((u32)(6837472)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_461020
  eax = ext_461f00_thiscall1(ecx);  // @3_461020
  ecx = edx = 0;  // @4_461020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; });  // @5_461020
  if ((ecx & ecx) == 0) goto L461064;  // @6_461020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_461020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @8_461020
  ecx = edx = 0;  // @9_461020
  L461064:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 118), sizeof v); (u32)v; });  // @11_461020
  if ((ecx & ecx) == 0) goto L461071;  // @12_461020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_461020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @14_461020
  ecx = edx = 0;  // @15_461020
  L461071:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @17_461020
  if ((ecx & ecx) == 0) goto L461083;  // @18_461020
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 114), sizeof v); (u32)v; }) == ecx) goto L461083;  // @19_461020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_461020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @21_461020
  ecx = edx = 0;  // @22_461020
  L461083:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @24_461020
  if ((ecx & ecx) == 0) goto L461095;  // @25_461020
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 118), sizeof v); (u32)v; })) goto L461095;  // @26_461020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_461020
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @28_461020
  ecx = edx = 0;  // @29_461020
  L461095:;
  ecx = esi;  // @31_461020
  eax = ext_43de70_thiscall1(ecx);  // @32_461020
  ecx = edx = 0;  // @33_461020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @34_461020
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4610d2;  // @35_461020
  if (((eax & 0xff) & (u32)(4)) != 0) goto L4610c4;  // @36_461020
  eax = ext_45c510_cdecl1((u32)(esi));  // @37_461020
  ecx = edx = 0;  // @38_461020
  eax = esi;  // @39_461020
  SEH_LEAVE();  // @40_461020
  return eax;  // @41_461020
  L4610c4:;
  eax = ext_4690b0_cdecl2((u32)(esi), (u32)(310));  // @43_461020
  ecx = edx = 0;  // @44_461020
  L4610d2:;
  eax = esi;  // @46_461020
  SEH_LEAVE();  // @47_461020
  return eax;  // @48_461020
}
PCREG(461020, lifted_461020);

extern "C" u32 THISCALL lifted_59d930(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_59d930
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2346), sizeof v); (u32)v; });  // @1_59d930
  { u32 v = (u32)((u32)(7004016)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_59d930
  if ((eax & eax) == 0) goto L59d970;  // @3_59d930
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @4_59d930
  ecx = edx = 0;  // @5_59d930
  L59d970:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_59d930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2282), sizeof v); (u32)v; }));  // @9_59d930
  ecx = edx = 0;  // @10_59d930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2282), sizeof v); (u32)v; });  // @11_59d930
  if ((ecx & ecx) == 0) goto L59d994;  // @12_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_59d930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @14_59d930
  ecx = edx = 0;  // @15_59d930
  L59d994:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_59d930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2274), sizeof v); (u32)v; }));  // @19_59d930
  ecx = edx = 0;  // @20_59d930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2274), sizeof v); (u32)v; });  // @21_59d930
  if ((ecx & ecx) == 0) goto L59d9b8;  // @22_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_59d930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @24_59d930
  ecx = edx = 0;  // @25_59d930
  L59d9b8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_59d930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2278), sizeof v); (u32)v; }));  // @29_59d930
  ecx = edx = 0;  // @30_59d930
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2278), sizeof v); (u32)v; });  // @31_59d930
  if ((ecx & ecx) == 0) goto L59d9dc;  // @32_59d930
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_59d930
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @34_59d930
  ecx = edx = 0;  // @35_59d930
  L59d9dc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @37_59d930
  if ((eax & eax) == 0) goto L59d9ee;  // @38_59d930
  eax = ext_634273_cdecl2((u32)(eax), (u32)(24));  // @39_59d930
  ecx = edx = 0;  // @40_59d930
  L59d9ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 2358), sizeof v); (u32)v; });  // @42_59d930
  if ((eax & eax) == 0) goto L59da03;  // @43_59d930
  eax = ext_634273_cdecl2((u32)(eax), (u32)(4));  // @44_59d930
  ecx = edx = 0;  // @45_59d930
  L59da03:;
  ecx = esi;  // @47_59d930
  eax = ext_477480_thiscall1(ecx);  // @48_59d930
  ecx = edx = 0;  // @49_59d930
  SEH_LEAVE();  // @50_59d930
  return eax;  // @51_59d930
}
PCREG(59d930, lifted_59d930);

extern "C" u32 FASTCALL lifted_42ae00(u32 ecx_in, u32 edx_in, u32 a0) {
  SEH_ENTER(0x66cd79);  // @h_42ae00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_42ae00
  edi = ecx;  // @1_42ae00
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @2_42ae00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_42ae00
  reg.state = (s32)((u32)(0));  // @4_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @5_42ae00
  ecx = (u32)(esi + 1);  // @6_42ae00
  L42ae44:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @8_42ae00
  esi = (esi + 1);  // @9_42ae00
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42ae44;  // @10_42ae00
  esi = (esi - ecx);  // @11_42ae00
  ebx = esi;  // @12_42ae00
  ebx = (ebx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @13_42ae00
  ebx = (ebx + 1);  // @14_42ae00
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @15_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @16_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @17_42ae00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @18_42ae00
  if (ebx > (u32)(-2)) goto L42ae8b;  // @19_42ae00
  if ((ebx & ebx) != 0) goto L42ae76;  // @20_42ae00
  eax = 0;  // @21_42ae00
  goto L42ae81;  // @22_42ae00
  L42ae76:;
  ecx = edi;  // @24_42ae00
  eax = ext_6014a0_stdcall1((u32)(ebx));  // @25_42ae00
  ecx = edx = 0;  // @26_42ae00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @27_42ae00
  L42ae81:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @29_42ae00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @30_42ae00
  eax = (eax + ebx);  // @31_42ae00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @32_42ae00
  L42ae8b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @34_42ae00
  if ((eax & eax) == 0) goto L42ae95;  // @35_42ae00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @36_42ae00
  L42ae95:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @38_42ae00
  ecx = edi;  // @39_42ae00
  reg.state = (s32)((u32)(0));  // @40_42ae00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @41_42ae00
  eax = ext_5f2c60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @42_42ae00
  ecx = edx = 0;  // @43_42ae00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @44_42ae00
  eax = (u32)(esi + ecx);  // @45_42ae00
  ecx = edi;  // @46_42ae00
  eax = ext_5f2c60_thiscall3(ecx, (u32)(ecx), (u32)(eax));  // @47_42ae00
  ecx = edx = 0;  // @48_42ae00
  eax = edi;  // @49_42ae00
  SEH_LEAVE();  // @50_42ae00
  return eax;  // @51_42ae00
}
PCREG(42ae00, lifted_42ae00);

extern "C" u32 THISCALL lifted_439e50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665bff);  // @h_439e50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_439e50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_439e50
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 50), sizeof v); (u32)v; }) & (u32)(207))); __builtin_memcpy((void *)(u32)(esi + 50), &v, sizeof v); }  // @2_439e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @3_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @4_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @5_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 66), &v, sizeof v); }  // @6_439e50
  eax = ext_41e290_cdecl1((u32)(28));  // @7_439e50
  ecx = edx = 0;  // @8_439e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @9_439e50
  reg.state = (s32)((u32)(0));  // @10_439e50
  if ((eax & eax) == 0) goto L439ebc;  // @11_439e50
  ecx = eax;  // @12_439e50
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @13_439e50
  ecx = edx = 0;  // @14_439e50
  goto L439ebe;  // @15_439e50
  L439ebc:;
  eax = 0;  // @17_439e50
  L439ebe:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 50), sizeof v); (u32)v; }) & (u32)(254))); __builtin_memcpy((void *)(u32)(esi + 50), &v, sizeof v); }  // @19_439e50
  ecx = (u32)(EBP - 16);  // @20_439e50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @21_439e50
  eax = (u32)(esi + 29);  // @22_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 62), &v, sizeof v); }  // @23_439e50
  if (eax == ecx) goto L439edc;  // @24_439e50
  { u32 v = (u32)((u32)(1073740800)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_439e50
  L439edc:;
  eax = (u32)(esi + 33);  // @27_439e50
  ecx = (u32)(EBP - 20);  // @28_439e50
  if (eax == ecx) goto L439eec;  // @29_439e50
  { u32 v = (u32)((u32)(1073740800)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @30_439e50
  L439eec:;
  eax = (u32)(esi + 37);  // @32_439e50
  ecx = (u32)(EBP - 24);  // @33_439e50
  if (eax == ecx) goto L439efc;  // @34_439e50
  { u32 v = (u32)((u32)(3221226496)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @35_439e50
  L439efc:;
  eax = (u32)(esi + 41);  // @37_439e50
  ecx = (u32)(EBP - 28);  // @38_439e50
  if (eax == ecx) goto L439f0c;  // @39_439e50
  { u32 v = (u32)((u32)(3221226496)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @40_439e50
  L439f0c:;
  eax = (u32)(esi + 45);  // @42_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 70), &v, sizeof v); }  // @43_439e50
  ecx = (u32)(EBP - 32);  // @44_439e50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 61), &v, sizeof v); }  // @45_439e50
  if (eax == ecx) goto L439f27;  // @46_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_439e50
  L439f27:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 50), sizeof v); (u32)v; }) & (u32)(63))); __builtin_memcpy((void *)(u32)(esi + 50), &v, sizeof v); }  // @49_439e50
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 51), sizeof v); (u32)v; }) & (u32)(1))); __builtin_memcpy((void *)(u32)(esi + 51), &v, sizeof v); }  // @50_439e50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @51_439e50
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @52_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @53_439e50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @54_439e50
  SEH_LEAVE();  // @55_439e50
  return eax;  // @56_439e50
}
PCREG(439e50, lifted_439e50);

extern "C" u32 THISCALL lifted_48b5b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66796b);  // @h_48b5b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 124), sizeof v); (u32)v; });  // @1_48b5b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2_48b5b0
  ecx = edx = 0;  // @3_48b5b0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L48b602;  // @4_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_48b5b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(3598));  // @7_48b5b0
  ecx = edx = 0;  // @8_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_48b5b0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6872776));  // @10_48b5b0
  ecx = edx = 0;  // @11_48b5b0
  L48b602:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @14_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @15_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_48b5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(64));  // @17_48b5b0
  ecx = edx = 0;  // @18_48b5b0
  esi = eax;  // @19_48b5b0
  if ((esi & esi) != 0) goto L48b62b;  // @20_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @21_48b5b0
  if ((eax & eax) == 0) goto L48b62a;  // @22_48b5b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @23_48b5b0
  ecx = edx = 0;  // @24_48b5b0
  goto L48b62b;  // @25_48b5b0
  L48b62a:;
  __builtin_trap();  // @27_48b5b0
  L48b62b:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @29_48b5b0
  reg.state = (s32)((u32)(0));  // @30_48b5b0
  if ((esi & esi) == 0) goto L48b644;  // @31_48b5b0
  ecx = esi;  // @32_48b5b0
  eax = ext_469870_thiscall1(ecx);  // @33_48b5b0
  ecx = edx = 0;  // @34_48b5b0
  esi = eax;  // @35_48b5b0
  goto L48b646;  // @36_48b5b0
  L48b644:;
  esi = 0;  // @38_48b5b0
  L48b646:;
  reg.state = (s32)((u32)(4294967295));  // @40_48b5b0
  if ((esi & esi) == 0) goto L48b67c;  // @41_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_48b5b0
  edx = (u32)(esi + 16);  // @43_48b5b0
  eax = (u32)(ecx + 64);  // @44_48b5b0
  if (edx == eax) goto L48b66b;  // @45_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_48b5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @47_48b5b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_48b5b0
  L48b66b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @50_48b5b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_48b5b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @52_48b5b0
  ecx = edx = 0;  // @53_48b5b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @54_48b5b0
  L48b67c:;
  eax = esi;  // @56_48b5b0
  SEH_LEAVE();  // @57_48b5b0
  return eax;  // @58_48b5b0
}
PCREG(48b5b0, lifted_48b5b0);

extern "C" u32 THISCALL lifted_42d820(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664efc);  // @h_42d820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_42d820
  ecx = (u32)(EBP - 532);  // @2_42d820
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_42d820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @4_42d820
  ecx = esi;  // @5_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @6_42d820
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @7_42d820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6789660), (u32)(ecx));  // @8_42d820
  ecx = edx = 0;  // @9_42d820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42d8f5;  // @10_42d820
  ecx = (u32)(EBP - 272);  // @11_42d820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; }));  // @12_42d820
  ecx = edx = 0;  // @13_42d820
  ecx = (u32)(EBP - 144);  // @14_42d820
  reg.state = (s32)((u32)(0));  // @15_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789668));  // @16_42d820
  ecx = edx = 0;  // @17_42d820
  eax = (u32)(EBP - 144);  // @18_42d820
  reg.state = (s32)((u32)(1));  // @19_42d820
  eax = (u32)(EBP - 528);  // @20_42d820
  ecx = (u32)(esi + 291);  // @21_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(eax), (u32)(eax));  // @22_42d820
  ecx = edx = 0;  // @23_42d820
  ecx = (u32)(EBP - 272);  // @24_42d820
  reg.state = (s32)((u32)(2));  // @25_42d820
  ecx = eax;  // @26_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(edi), (u32)(ecx));  // @27_42d820
  ecx = edx = 0;  // @28_42d820
  ecx = (u32)(EBP - 528);  // @29_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @30_42d820
  ecx = edx = 0;  // @31_42d820
  ecx = (u32)(EBP - 144);  // @32_42d820
  eax = ext_4cbec0_thiscall1(ecx);  // @33_42d820
  ecx = edx = 0;  // @34_42d820
  ecx = (u32)(EBP - 272);  // @35_42d820
  goto L42d925;  // @36_42d820
  L42d8f5:;
  ecx = (u32)(EBP - 400);  // @38_42d820
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789660));  // @39_42d820
  ecx = edx = 0;  // @40_42d820
  eax = (u32)(EBP - 400);  // @41_42d820
  reg.state = (s32)((u32)(3));  // @42_42d820
  ecx = (u32)(esi + 291);  // @43_42d820
  eax = ext_4cc1e0_thiscall3(ecx, (u32)(edi), (u32)(eax));  // @44_42d820
  ecx = edx = 0;  // @45_42d820
  ecx = (u32)(EBP - 400);  // @46_42d820
  L42d925:;
  eax = ext_4cbec0_thiscall1(ecx);  // @48_42d820
  ecx = edx = 0;  // @49_42d820
  eax = edi;  // @50_42d820
  SEH_LEAVE();  // @51_42d820
  ext_633654(G(u32, 0x6f5630));  // @52_42d820
  return eax;  // @53_42d820
}
PCREG(42d820, lifted_42d820);

extern "C" u32 THISCALL lifted_5421b0(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_5421b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5421b0
  { u32 v = (u32)((u32)(6958612)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5421b0
  eax = ext_545350_cdecl0();  // @2_5421b0
  ecx = edx = 0;  // @3_5421b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @4_5421b0
  if ((eax & eax) == 0) goto L5421f3;  // @5_5421b0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @6_5421b0
  ecx = edx = 0;  // @7_5421b0
  L5421f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @9_5421b0
  if ((eax & eax) == 0) goto L542203;  // @10_5421b0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @11_5421b0
  ecx = edx = 0;  // @12_5421b0
  L542203:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @14_5421b0
  if ((eax & eax) == 0) goto L542213;  // @15_5421b0
  eax = ext_41e2c0_cdecl1((u32)(eax));  // @16_5421b0
  ecx = edx = 0;  // @17_5421b0
  L542213:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 15), sizeof v); (u32)v; });  // @19_5421b0
  if ((eax & eax) == 0) goto L542225;  // @20_5421b0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(52));  // @21_5421b0
  ecx = edx = 0;  // @22_5421b0
  L542225:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 19), sizeof v); (u32)v; });  // @24_5421b0
  if ((eax & eax) == 0) goto L542237;  // @25_5421b0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(12));  // @26_5421b0
  ecx = edx = 0;  // @27_5421b0
  L542237:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 23), sizeof v); (u32)v; });  // @29_5421b0
  if ((eax & eax) == 0) goto L542249;  // @30_5421b0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(12));  // @31_5421b0
  ecx = edx = 0;  // @32_5421b0
  L542249:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 93), sizeof v); (u32)v; });  // @34_5421b0
  if ((edi & edi) == 0) goto L542265;  // @35_5421b0
  ecx = edi;  // @36_5421b0
  eax = ext_635490_thiscall1(ecx);  // @37_5421b0
  ecx = edx = 0;  // @38_5421b0
  eax = ext_634273_cdecl2((u32)(edi), (u32)(147));  // @39_5421b0
  ecx = edx = 0;  // @40_5421b0
  L542265:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 15), &v, sizeof v); }  // @42_5421b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @43_5421b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 23), &v, sizeof v); }  // @44_5421b0
  { u32 v = (u32)((u32)(6958600)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_5421b0
  SEH_LEAVE();  // @46_5421b0
  return eax;  // @47_5421b0
}
PCREG(5421b0, lifted_5421b0);

extern "C" u32 THISCALL lifted_614040(u32 ecx_in) {
  SEH_ENTER(0x66e46d);  // @h_614040
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_614040
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; }) != (u32)(0)) goto L6140b2;  // @1_614040
  eax = ext_41e290_cdecl1((u32)(20));  // @2_614040
  ecx = edx = 0;  // @3_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_614040
  if ((eax & eax) == 0) goto L6140a3;  // @5_614040
  ecx = (u32)(esi + 568);  // @6_614040
  { u32 v = (u32)((u32)(7068068)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @7_614040
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @8_614040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @11_614040
  goto L6140a5;  // @12_614040
  L6140a3:;
  eax = 0;  // @14_614040
  L6140a5:;
  reg.state = (s32)((u32)(4294967295));  // @16_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 544), &v, sizeof v); }  // @17_614040
  L6140b2:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 548), sizeof v); (u32)v; }) != (u32)(0)) goto L6140fe;  // @19_614040
  eax = ext_41e290_cdecl1((u32)(20));  // @20_614040
  ecx = edx = 0;  // @21_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_614040
  if ((eax & eax) == 0) goto L6140ef;  // @23_614040
  ecx = (u32)(esi + 568);  // @24_614040
  { u32 v = (u32)((u32)(7068128)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_614040
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @26_614040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @27_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @28_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @29_614040
  goto L6140f1;  // @30_614040
  L6140ef:;
  eax = 0;  // @32_614040
  L6140f1:;
  reg.state = (s32)((u32)(4294967295));  // @34_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 548), &v, sizeof v); }  // @35_614040
  L6140fe:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 552), sizeof v); (u32)v; }) != (u32)(0)) goto L61414a;  // @37_614040
  eax = ext_41e290_cdecl1((u32)(20));  // @38_614040
  ecx = edx = 0;  // @39_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_614040
  if ((eax & eax) == 0) goto L61413b;  // @41_614040
  ecx = (u32)(esi + 568);  // @42_614040
  { u32 v = (u32)((u32)(7068188)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @43_614040
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @44_614040
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @45_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @46_614040
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @47_614040
  goto L61413d;  // @48_614040
  L61413b:;
  eax = 0;  // @50_614040
  L61413d:;
  reg.state = (s32)((u32)(4294967295));  // @52_614040
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 552), &v, sizeof v); }  // @53_614040
  L61414a:;
  ecx = esi;  // @55_614040
  eax = ext_6593c0_thiscall1(ecx);  // @56_614040
  ecx = edx = 0;  // @57_614040
  SEH_LEAVE();  // @58_614040
  return eax;  // @59_614040
}
PCREG(614040, lifted_614040);

extern "C" u32 THISCALL lifted_4654b0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666a68);  // @h_4654b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_4654b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4654b0
  eax = ext_460e40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_4654b0
  ecx = edx = 0;  // @3_4654b0
  ecx = (u32)(esi + 365);  // @4_4654b0
  reg.state = (s32)((u32)(0));  // @5_4654b0
  { u32 v = (u32)((u32)(6838980)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4654b0
  eax = ext_466220_thiscall1(ecx);  // @7_4654b0
  ecx = edx = 0;  // @8_4654b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 344), &v, sizeof v); }  // @9_4654b0
  { u32 v = (u32)((u32)(1126170624)); __builtin_memcpy((void *)(u32)(esi + 458), &v, sizeof v); }  // @10_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 310), &v, sizeof v); }  // @11_4654b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4654b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_4654b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4654b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840076), (u32)(0), (u32)(6840032), (u32)(277));  // @15_4654b0
  ecx = edx = 0;  // @16_4654b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 353), &v, sizeof v); }  // @17_4654b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_4654b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_4654b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4654b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840096), (u32)(0), (u32)(6840032), (u32)(278));  // @21_4654b0
  ecx = edx = 0;  // @22_4654b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 355), &v, sizeof v); }  // @23_4654b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_4654b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_4654b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4654b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840116), (u32)(0), (u32)(6840032), (u32)(279));  // @27_4654b0
  ecx = edx = 0;  // @28_4654b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 359), &v, sizeof v); }  // @29_4654b0
  eax = esi;  // @30_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 361), &v, sizeof v); }  // @31_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 327), &v, sizeof v); }  // @32_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 331), &v, sizeof v); }  // @33_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 335), &v, sizeof v); }  // @34_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 339), &v, sizeof v); }  // @35_4654b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 343), &v, sizeof v); }  // @36_4654b0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 324), &v, sizeof v); }  // @37_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 349), &v, sizeof v); }  // @38_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 315), &v, sizeof v); }  // @39_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 319), &v, sizeof v); }  // @40_4654b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 314), &v, sizeof v); }  // @41_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 450), &v, sizeof v); }  // @42_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 446), &v, sizeof v); }  // @43_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 442), &v, sizeof v); }  // @44_4654b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 454), &v, sizeof v); }  // @45_4654b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 326), &v, sizeof v); }  // @46_4654b0
  SEH_LEAVE();  // @47_4654b0
  return eax;  // @48_4654b0
}
PCREG(4654b0, lifted_4654b0);

extern "C" u32 THISCALL lifted_4c90a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_4c90a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4c90a0
  ecx = (u32)(EBP - 144);  // @2_4c90a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @4_4c90a0
  ecx = edx = 0;  // @5_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4c90a0
  reg.state = (s32)((u32)(0));  // @7_4c90a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @8_4c90a0
  if ((eax & 0xff) == (u32)(255)) goto L4c9131;  // @9_4c90a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @10_4c90a0
  if ((eax & 0xff) != (u32)(4)) goto L4c9131;  // @11_4c90a0
  ecx = esi;  // @12_4c90a0
  eax = ext_4e5ea0_thiscall1(ecx);  // @13_4c90a0
  ecx = edx = 0;  // @14_4c90a0
  ecx = (u32)(EBP - 272);  // @15_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(eax));  // @16_4c90a0
  ecx = edx = 0;  // @17_4c90a0
  eax = (u32)(EBP - 272);  // @18_4c90a0
  reg.state = (s32)((u32)(1));  // @19_4c90a0
  ecx = (u32)(EBP - 144);  // @20_4c90a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @21_4c90a0
  ecx = edx = 0;  // @22_4c90a0
  ecx = (u32)(EBP - 272);  // @23_4c90a0
  reg.state = (s32)((u32)(0));  // @24_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @25_4c90a0
  ecx = edx = 0;  // @26_4c90a0
  L4c9131:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @31_4c90a0
  ecx = edx = 0;  // @32_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4c90a0
  esi = eax;  // @34_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @35_4c90a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_4c90a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4c90a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }), (u32)(2));  // @38_4c90a0
  ecx = edx = 0;  // @39_4c90a0
  ecx = (u32)(EBP - 144);  // @40_4c90a0
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @41_4c90a0
  ecx = edx = 0;  // @42_4c90a0
  ecx = esi;  // @43_4c90a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(eax));  // @44_4c90a0
  ecx = edx = 0;  // @45_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @46_4c90a0
  ecx = ebx;  // @47_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @48_4c90a0
  ecx = edx = 0;  // @49_4c90a0
  ecx = (u32)(EBP - 144);  // @50_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @51_4c90a0
  ecx = edx = 0;  // @52_4c90a0
  SEH_LEAVE();  // @53_4c90a0
  ext_633654(G(u32, 0x6f5630));  // @54_4c90a0
  return eax;  // @55_4c90a0
}
PCREG(4c90a0, lifted_4c90a0);

extern "C" u32 THISCALL lifted_4d1390(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6692df);  // @h_4d1390
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_4d1390
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4d1390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4d1390
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @4_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @5_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @6_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @7_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @8_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @9_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @10_4d1390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @11_4d1390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @12_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @13_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @14_4d1390
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @15_4d1390
  if ((ecx & ecx) == 0) goto L4d1433;  // @16_4d1390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @17_4d1390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @18_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @19_4d1390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 40), sizeof v); (u32)v; });  // @20_4d1390
  if ((eax & eax) == 0) goto L4d142b;  // @21_4d1390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @22_4d1390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @23_4d1390
  goto L4d1441;  // @24_4d1390
  L4d142b:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 36), &v, sizeof v); }  // @26_4d1390
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @27_4d1390
  goto L4d1441;  // @28_4d1390
  L4d1433:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @30_4d1390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @31_4d1390
  L4d1441:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; });  // @33_4d1390
  if ((esi & esi) == 0) goto L4d1477;  // @34_4d1390
  L4d1448:;
  eax = ext_41e290_cdecl1((u32)(56));  // @36_4d1390
  ecx = edx = 0;  // @37_4d1390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @38_4d1390
  reg.state = (s32)((u32)(0));  // @39_4d1390
  if ((eax & eax) == 0) goto L4d1469;  // @40_4d1390
  ecx = eax;  // @41_4d1390
  eax = ext_4d1390_thiscall3(ecx, (u32)(esi), (u32)(edi));  // @42_4d1390
  ecx = edx = 0;  // @43_4d1390
  L4d1469:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @45_4d1390
  reg.state = (s32)((u32)(4294967295));  // @46_4d1390
  if ((esi & esi) != 0) goto L4d1448;  // @47_4d1390
  L4d1477:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_4d1390
  ecx = ebx;  // @50_4d1390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edi));  // @51_4d1390
  ecx = edx = 0;  // @52_4d1390
  eax = edi;  // @53_4d1390
  SEH_LEAVE();  // @54_4d1390
  return eax;  // @55_4d1390
}
PCREG(4d1390, lifted_4d1390);

extern "C" u32 THISCALL lifted_534be0(u32 ecx_in) {
  SEH_ENTER(0x6692b0);  // @h_534be0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_534be0
  { u32 v = (u32)((u32)(6953900)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_534be0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @2_534be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_534be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_534be0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20667), sizeof v); (u32)v; }));  // @5_534be0
  ecx = edx = 0;  // @6_534be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20667), sizeof v); (u32)v; });  // @7_534be0
  if ((ecx & ecx) == 0) goto L534c34;  // @8_534be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_534be0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @10_534be0
  ecx = edx = 0;  // @11_534be0
  L534c34:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_534be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_534be0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20671), sizeof v); (u32)v; }));  // @15_534be0
  ecx = edx = 0;  // @16_534be0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20671), sizeof v); (u32)v; });  // @17_534be0
  if ((ecx & ecx) == 0) goto L534c58;  // @18_534be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_534be0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @20_534be0
  ecx = edx = 0;  // @21_534be0
  L534c58:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @23_534be0
  if ((ecx & ecx) == 0) goto L534c68;  // @24_534be0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_534be0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @26_534be0
  ecx = edx = 0;  // @27_534be0
  L534c68:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21250), sizeof v); (u32)v; });  // @29_534be0
  if ((eax & eax) == 0) goto L534c7d;  // @30_534be0
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @31_534be0
  ecx = edx = 0;  // @32_534be0
  L534c7d:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21242), sizeof v); (u32)v; });  // @34_534be0
  if ((edi & edi) == 0) goto L534c99;  // @35_534be0
  ecx = edi;  // @36_534be0
  eax = ext_53a8f0_thiscall1(ecx);  // @37_534be0
  ecx = edx = 0;  // @38_534be0
  eax = ext_634273_cdecl2((u32)(edi), (u32)(26));  // @39_534be0
  ecx = edx = 0;  // @40_534be0
  L534c99:;
  ecx = (u32)(esi + 21426);  // @42_534be0
  eax = ext_4ccf60_thiscall1(ecx);  // @43_534be0
  ecx = edx = 0;  // @44_534be0
  ecx = (u32)(esi + 21254);  // @45_534be0
  eax = ext_4ccf60_thiscall1(ecx);  // @46_534be0
  ecx = edx = 0;  // @47_534be0
  ecx = (u32)(esi + 21062);  // @48_534be0
  eax = ext_4ccf60_thiscall1(ecx);  // @49_534be0
  ecx = edx = 0;  // @50_534be0
  ecx = (u32)(esi + 20921);  // @51_534be0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_534be0
  ecx = edx = 0;  // @53_534be0
  ecx = (u32)(esi + 139);  // @54_534be0
  eax = ext_533d60_thiscall1(ecx);  // @55_534be0
  ecx = edx = 0;  // @56_534be0
  ecx = esi;  // @57_534be0
  { u32 v = (u32)((u32)(6953568)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @58_534be0
  eax = ext_4e66a0_thiscall1(ecx);  // @59_534be0
  ecx = edx = 0;  // @60_534be0
  SEH_LEAVE();  // @61_534be0
  return eax;  // @62_534be0
}
PCREG(534be0, lifted_534be0);

extern "C" u32 THISCALL lifted_436f60(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_436f60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_436f60
  { u32 v = (u32)((u32)(6792928)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_436f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_436f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @3_436f60
  if ((ecx & ecx) == 0) goto L436fa5;  // @4_436f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_436f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(6793340));  // @6_436f60
  ecx = edx = 0;  // @7_436f60
  L436fa5:;
  ecx = edi;  // @9_436f60
  eax = ext_43aa30_thiscall1(ecx);  // @10_436f60
  ecx = edx = 0;  // @11_436f60
  ecx = edi;  // @12_436f60
  eax = ext_43a800_thiscall1(ecx);  // @13_436f60
  ecx = edx = 0;  // @14_436f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4628), sizeof v); (u32)v; });  // @15_436f60
  if ((ecx & ecx) == 0) goto L436fc3;  // @16_436f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_436f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_436f60
  ecx = edx = 0;  // @19_436f60
  L436fc3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4932), sizeof v); (u32)v; });  // @21_436f60
  if ((eax & eax) == 0) goto L436ffd;  // @22_436f60
  esi = (u32)(eax - 4);  // @23_436f60
  reg.state = (s32)((u32)(0));  // @24_436f60
  eax = ext_63418c_stdcall4((u32)(eax), (u32)(10), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 4), sizeof v); (u32)v; }), (u32)(4624560));  // @25_436f60
  ecx = edx = 0;  // @26_436f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_436f60
  eax = (u32)(eax + eax*4);  // @28_436f60
  eax = (u32)(eax*2 + 4);  // @29_436f60
  eax = ext_634273_cdecl2((u32)(esi), (u32)(eax));  // @30_436f60
  ecx = edx = 0;  // @31_436f60
  L436ffd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4892), sizeof v); (u32)v; });  // @33_436f60
  if ((eax & eax) == 0) goto L437012;  // @34_436f60
  eax = ext_634273_cdecl2((u32)(eax), (u32)(1));  // @35_436f60
  ecx = edx = 0;  // @36_436f60
  L437012:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4912), sizeof v); (u32)v; });  // @38_436f60
  if ((esi & esi) == 0) goto L43702e;  // @39_436f60
  ecx = esi;  // @40_436f60
  eax = ext_4d8d50_thiscall1(ecx);  // @41_436f60
  ecx = edx = 0;  // @42_436f60
  eax = ext_634273_cdecl2((u32)(esi), (u32)(6));  // @43_436f60
  ecx = edx = 0;  // @44_436f60
  L43702e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4924), sizeof v); (u32)v; });  // @46_436f60
  if ((ecx & ecx) == 0) goto L43703e;  // @47_436f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_436f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @49_436f60
  ecx = edx = 0;  // @50_436f60
  L43703e:;
  SEH_LEAVE();  // @52_436f60
  return eax;  // @53_436f60
}
PCREG(436f60, lifted_436f60);

extern "C" u32 THISCALL lifted_4957f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66809f);  // @h_4957f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4957f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @2_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_4957f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @6_4957f0
  if ((eax & eax) == 0) goto L4958c8;  // @7_4957f0
  eax = ext_41e290_cdecl1((u32)(eax));  // @8_4957f0
  ecx = edx = 0;  // @9_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @10_4957f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L4958a8;  // @11_4957f0
  eax = ext_41e290_cdecl1((u32)(16));  // @12_4957f0
  ecx = edx = 0;  // @13_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_4957f0
  reg.state = (s32)((u32)(0));  // @15_4957f0
  if ((eax & eax) == 0) goto L495890;  // @16_4957f0
  ecx = eax;  // @17_4957f0
  eax = ext_4ccdd0_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }), (u32)(1024));  // @18_4957f0
  ecx = edx = 0;  // @19_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @20_4957f0
  eax = esi;  // @21_4957f0
  SEH_LEAVE();  // @22_4957f0
  return eax;  // @23_4957f0
  L495890:;
  eax = 0;  // @25_4957f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_4957f0
  eax = esi;  // @27_4957f0
  SEH_LEAVE();  // @28_4957f0
  return eax;  // @29_4957f0
  L4958a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @31_4957f0
  if ((eax & eax) == 0) goto L4958c7;  // @32_4957f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @33_4957f0
  ecx = edx = 0;  // @34_4957f0
  eax = esi;  // @35_4957f0
  SEH_LEAVE();  // @36_4957f0
  return eax;  // @37_4957f0
  L4958c7:;
  __builtin_trap();  // @39_4957f0
  L4958c8:;
  eax = esi;  // @41_4957f0
  SEH_LEAVE();  // @42_4957f0
  return eax;  // @43_4957f0
}
PCREG(4957f0, lifted_4957f0);

