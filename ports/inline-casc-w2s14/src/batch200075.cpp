// batch200075.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_41cfd0_thiscall1(u32) __asm__("ext_41cfd0");
extern "C" u32 THISCALL ext_44b610_thiscall1(u32) __asm__("ext_44b610");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ff7b0_thiscall1(u32) __asm__("ext_4ff7b0");
extern "C" u32 THISCALL ext_5f12d0_thiscall1(u32) __asm__("ext_5f12d0");
extern "C" u32 THISCALL ext_63ed10_thiscall1(u32) __asm__("ext_63ed10");
extern "C" u32 THISCALL ext_6590a0_thiscall2(u32, u32) __asm__("ext_6590a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4ccef0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ccef0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1_4ccef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_4ccef0
  reg.state = (s32)((u32)(0));  // @3_4ccef0
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_4ccef0
  if ((edi & edi) == 0) goto L4ccf40;  // @5_4ccef0
  L4ccf31:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4ccef0
  ecx = esi;  // @8_4ccef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_4ccef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @10_4ccef0
  ecx = edx = 0;  // @11_4ccef0
  if ((edi & edi) != 0) goto L4ccf31;  // @12_4ccef0
  L4ccf40:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_4ccef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @15_4ccef0
  SEH_LEAVE();  // @16_4ccef0
  return eax;  // @17_4ccef0
}
PCREG(4ccef0, lifted_4ccef0);

extern "C" u32 THISCALL lifted_4cd050(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4cd050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_4cd050
  { u32 v = (u32)((u32)(6903876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4cd050
  if ((ecx & ecx) == 0) goto L4cd089;  // @3_4cd050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4cd050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_4cd050
  ecx = edx = 0;  // @6_4cd050
  L4cd089:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @8_4cd050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @9_4cd050
  reg.state = (s32)((u32)(0));  // @10_4cd050
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_4cd050
  if ((edi & edi) == 0) goto L4cd0b3;  // @12_4cd050
  L4cd0a4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_4cd050
  ecx = esi;  // @15_4cd050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @16_4cd050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(edi));  // @17_4cd050
  ecx = edx = 0;  // @18_4cd050
  if ((edi & edi) != 0) goto L4cd0a4;  // @19_4cd050
  L4cd0b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @21_4cd050
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @22_4cd050
  SEH_LEAVE();  // @23_4cd050
  return eax;  // @24_4cd050
}
PCREG(4cd050, lifted_4cd050);

extern "C" u32 THISCALL lifted_44c060(u32 ecx_in) {
  SEH_ENTER(0x665c56);  // @h_44c060
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = ecx;  // @0_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_44c060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }) == (u32)(0)) goto L44c0df;  // @2_44c060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @3_44c060
  if ((edx & edx) == 0) goto L44c0df;  // @4_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @5_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_44c060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(edx));  // @7_44c060
  ecx = edx = 0;  // @8_44c060
  esi = eax;  // @9_44c060
  if ((esi & esi) == 0) goto L44c0df;  // @10_44c060
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_44c060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L44c0df;  // @12_44c060
  ecx = esi;  // @13_44c060
  eax = ext_44b610_thiscall1(ecx);  // @14_44c060
  ecx = edx = 0;  // @15_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_44c060
  reg.state = (s32)((u32)(0));  // @17_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @18_44c060
  if ((ecx & ecx) == 0) goto L44c0df;  // @19_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_44c060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 280)))(ecx, (u32)(esi));  // @21_44c060
  ecx = edx = 0;  // @22_44c060
  L44c0df:;
  SEH_LEAVE();  // @24_44c060
  return eax;  // @25_44c060
}
PCREG(44c060, lifted_44c060);

extern "C" u32 THISCALL lifted_4b6d70(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668c0f);  // @h_4b6d70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4b6d70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4b6d70
  if ((esi & esi) != 0) goto L4b6ddf;  // @2_4b6d70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; }) == esi) goto L4b6db3;  // @3_4b6d70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @4_4b6d70
  if ((eax & eax) == 0) goto L4b6db2;  // @5_4b6d70
  eax = ((u32(STDCALL *)(void))(eax))();  // @6_4b6d70
  ecx = edx = 0;  // @7_4b6d70
  goto L4b6db3;  // @8_4b6d70
  L4b6db2:;
  __builtin_trap();  // @10_4b6d70
  L4b6db3:;
  eax = ext_41e290_cdecl1((u32)(40));  // @12_4b6d70
  ecx = edx = 0;  // @13_4b6d70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_4b6d70
  reg.state = (s32)((u32)(0));  // @15_4b6d70
  if ((eax & eax) == 0) goto L4b6dd8;  // @16_4b6d70
  ecx = eax;  // @17_4b6d70
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(2));  // @18_4b6d70
  ecx = edx = 0;  // @19_4b6d70
  goto L4b6dda;  // @20_4b6d70
  L4b6dd8:;
  eax = 0;  // @22_4b6d70
  L4b6dda:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340852), &v, sizeof v); }  // @24_4b6d70
  L4b6ddf:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @26_4b6d70
  SEH_LEAVE();  // @27_4b6d70
  return eax;  // @28_4b6d70
}
PCREG(4b6d70, lifted_4b6d70);

extern "C" u32 THISCALL lifted_614f10(u32 ecx_in) {
  SEH_ENTER(0x66e46d);  // @h_614f10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_614f10
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) != (u32)(0)) goto L614fe6;  // @1_614f10
  eax = ext_41e290_cdecl1((u32)(20));  // @2_614f10
  ecx = edx = 0;  // @3_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_614f10
  reg.state = (s32)((u32)(0));  // @5_614f10
  if ((eax & eax) == 0) goto L614f66;  // @6_614f10
  ecx = eax;  // @7_614f10
  eax = ext_6590a0_thiscall2(ecx, (u32)(131072));  // @8_614f10
  ecx = edx = 0;  // @9_614f10
  goto L614f68;  // @10_614f10
  L614f66:;
  eax = 0;  // @12_614f10
  L614f68:;
  reg.state = (s32)((u32)(4294967295));  // @14_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 47528), &v, sizeof v); }  // @15_614f10
  eax = ext_41e290_cdecl1((u32)(20));  // @16_614f10
  ecx = edx = 0;  // @17_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @18_614f10
  reg.state = (s32)((u32)(1));  // @19_614f10
  if ((eax & eax) == 0) goto L614f9b;  // @20_614f10
  ecx = eax;  // @21_614f10
  eax = ext_6590a0_thiscall2(ecx, (u32)(32768));  // @22_614f10
  ecx = edx = 0;  // @23_614f10
  goto L614f9d;  // @24_614f10
  L614f9b:;
  eax = 0;  // @26_614f10
  L614f9d:;
  reg.state = (s32)((u32)(4294967295));  // @28_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 47532), &v, sizeof v); }  // @29_614f10
  eax = ext_41e290_cdecl1((u32)(20));  // @30_614f10
  ecx = edx = 0;  // @31_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @32_614f10
  reg.state = (s32)((u32)(2));  // @33_614f10
  if ((eax & eax) == 0) goto L614fd0;  // @34_614f10
  ecx = eax;  // @35_614f10
  eax = ext_6590a0_thiscall2(ecx, (u32)(229376));  // @36_614f10
  ecx = edx = 0;  // @37_614f10
  goto L614fd2;  // @38_614f10
  L614fd0:;
  eax = 0;  // @40_614f10
  L614fd2:;
  ecx = esi;  // @42_614f10
  reg.state = (s32)((u32)(4294967295));  // @43_614f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 47536), &v, sizeof v); }  // @44_614f10
  eax = ext_63ed10_thiscall1(ecx);  // @45_614f10
  ecx = edx = 0;  // @46_614f10
  L614fe6:;
  SEH_LEAVE();  // @48_614f10
  return eax;  // @49_614f10
}
PCREG(614f10, lifted_614f10);

extern "C" u32 THISCALL lifted_45e710(u32 ecx_in) {
  SEH_ENTER(0x66d436);  // @h_45e710
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45e710
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L45e825;  // @1_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @3_45e710
  ecx = edx = 0;  // @4_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_45e710
  ecx = esi;  // @6_45e710
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 320)))(ecx);  // @7_45e710
  ecx = edx = 0;  // @8_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @9_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @10_45e710
  if ((edx & edx) == 0) goto L45e78c;  // @11_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7261), sizeof v); (u32)v; });  // @14_45e710
  if (edx < ecx) goto L45e781;  // @15_45e710
  if ((ecx & ecx) == 0) goto L45e781;  // @16_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @17_45e710
  eax = (eax & (u32)(536870911));  // @18_45e710
  eax = (eax + ecx);  // @19_45e710
  if (edx < eax) goto L45e78c;  // @20_45e710
  L45e781:;
  eax = ext_634273_cdecl2((u32)(edx), (u32)(24));  // @22_45e710
  ecx = edx = 0;  // @23_45e710
  L45e78c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @25_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @26_45e710
  if ((eax & eax) == 0) goto L45e7a1;  // @27_45e710
  eax = ext_634273_cdecl2((u32)(eax), (u32)(8));  // @28_45e710
  ecx = edx = 0;  // @29_45e710
  L45e7a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @31_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @32_45e710
  if ((eax & eax) == 0) goto L45e811;  // @33_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @34_45e710
  if ((eax & eax) == 0) goto L45e7c5;  // @35_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_45e710
  if ((edx & edx) == 0) goto L45e7c5;  // @37_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @38_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(edx));  // @40_45e710
  ecx = edx = 0;  // @41_45e710
  L45e7c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @43_45e710
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @44_45e710
  if ((edi & edi) == 0) goto L45e811;  // @45_45e710
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @46_45e710
  if ((ebx & ebx) == 0) goto L45e806;  // @47_45e710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @48_45e710
  reg.state = (s32)((u32)(0));  // @49_45e710
  if ((ecx & ecx) == 0) goto L45e7f4;  // @50_45e710
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @51_45e710
  if ((edx & edx) == 0) goto L45e7f4;  // @52_45e710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_45e710
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @54_45e710
  ecx = edx = 0;  // @55_45e710
  L45e7f4:;
  eax = ext_634273_cdecl2((u32)(ebx), (u32)(16));  // @57_45e710
  ecx = edx = 0;  // @58_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @59_45e710
  L45e806:;
  eax = ext_634273_cdecl2((u32)(edi), (u32)(8));  // @61_45e710
  ecx = edx = 0;  // @62_45e710
  L45e811:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }), (u32)(32));  // @64_45e710
  ecx = edx = 0;  // @65_45e710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @66_45e710
  L45e825:;
  SEH_LEAVE();  // @68_45e710
  return eax;  // @69_45e710
}
PCREG(45e710, lifted_45e710);

extern "C" u32 THISCALL lifted_59f1a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_59f1a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_59f1a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; }) != (u32)(0)) goto L59f2a0;  // @1_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1938), sizeof v); (u32)v; });  // @2_59f1a0
  if ((ecx & ecx) == 0) goto L59f2a0;  // @3_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @4_59f1a0
  ecx = ebx;  // @5_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1836)))(ecx, (u32)(ecx));  // @6_59f1a0
  ecx = edx = 0;  // @7_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_59f1a0
  esi = eax;  // @9_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @10_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(esi));  // @12_59f1a0
  ecx = edx = 0;  // @13_59f1a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1930), &v, sizeof v); }  // @14_59f1a0
  if ((esi & esi) == 0) goto L59f247;  // @15_59f1a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1946), sizeof v); (u32)v; }) == (u32)(0)) goto L59f237;  // @16_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @17_59f1a0
  ecx = ebx;  // @18_59f1a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1272)))(ecx);  // @19_59f1a0
  ecx = edx = 0;  // @20_59f1a0
  ecx = eax;  // @21_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @22_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1930), sizeof v); (u32)v; }));  // @23_59f1a0
  ecx = edx = 0;  // @24_59f1a0
  goto L59f2a0;  // @25_59f1a0
  L59f237:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_59f1a0
  ecx = esi;  // @28_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(1), (u32)(0));  // @29_59f1a0
  ecx = edx = 0;  // @30_59f1a0
  goto L59f2a0;  // @31_59f1a0
  L59f247:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @33_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(1388));  // @35_59f1a0
  ecx = edx = 0;  // @36_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_59f1a0
  edi = eax;  // @38_59f1a0
  eax = (u32)(EBP - 144);  // @39_59f1a0
  ecx = ebx;  // @40_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @41_59f1a0
  ecx = edx = 0;  // @42_59f1a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_59f1a0
  ecx = eax;  // @44_59f1a0
  reg.state = (s32)((u32)(0));  // @45_59f1a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_59f1a0
  ecx = edx = 0;  // @47_59f1a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(7006872), (u32)(eax));  // @48_59f1a0
  ecx = edx = 0;  // @49_59f1a0
  reg.state = (s32)((u32)(4294967295));  // @50_59f1a0
  ecx = (u32)(EBP - 144);  // @51_59f1a0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_59f1a0
  ecx = edx = 0;  // @53_59f1a0
  L59f2a0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; }) != (u32)(0)) goto L59f350;  // @55_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1942), sizeof v); (u32)v; });  // @56_59f1a0
  if ((ecx & ecx) == 0) goto L59f350;  // @57_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @58_59f1a0
  ecx = ebx;  // @59_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1836)))(ecx, (u32)(ecx));  // @60_59f1a0
  ecx = edx = 0;  // @61_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_59f1a0
  esi = eax;  // @63_59f1a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @64_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_59f1a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(esi));  // @66_59f1a0
  ecx = edx = 0;  // @67_59f1a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1934), &v, sizeof v); }  // @68_59f1a0
  if ((esi & esi) == 0) goto L59f2fe;  // @69_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @70_59f1a0
  ecx = ebx;  // @71_59f1a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1276)))(ecx);  // @72_59f1a0
  ecx = edx = 0;  // @73_59f1a0
  ecx = eax;  // @74_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 8)))(ecx, (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1934), sizeof v); (u32)v; }));  // @76_59f1a0
  ecx = edx = 0;  // @77_59f1a0
  goto L59f350;  // @78_59f1a0
  L59f2fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @80_59f1a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7005856), (u32)(1403));  // @82_59f1a0
  ecx = edx = 0;  // @83_59f1a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @84_59f1a0
  edi = eax;  // @85_59f1a0
  eax = (u32)(EBP - 272);  // @86_59f1a0
  ecx = ebx;  // @87_59f1a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @88_59f1a0
  ecx = edx = 0;  // @89_59f1a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @90_59f1a0
  ecx = eax;  // @91_59f1a0
  reg.state = (s32)((u32)(1));  // @92_59f1a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @93_59f1a0
  ecx = edx = 0;  // @94_59f1a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(7006920), (u32)(eax));  // @95_59f1a0
  ecx = edx = 0;  // @96_59f1a0
  ecx = (u32)(EBP - 272);  // @97_59f1a0
  eax = ext_4cbec0_thiscall1(ecx);  // @98_59f1a0
  ecx = edx = 0;  // @99_59f1a0
  L59f350:;
  SEH_LEAVE();  // @101_59f1a0
  ext_633654(G(u32, 0x6f5630));  // @102_59f1a0
  return eax;  // @103_59f1a0
}
PCREG(59f1a0, lifted_59f1a0);

extern "C" u32 THISCALL lifted_63cfe0(u32 ecx_in) {
  SEH_ENTER(0x66e848);  // @h_63cfe0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_63cfe0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 536), sizeof v); (u32)v; }) != (u32)(0)) goto L63d052;  // @1_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @2_63cfe0
  ecx = edx = 0;  // @3_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_63cfe0
  if ((eax & eax) == 0) goto L63d043;  // @5_63cfe0
  ecx = (u32)(esi + 568);  // @6_63cfe0
  { u32 v = (u32)((u32)(7087124)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @7_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @8_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @11_63cfe0
  goto L63d045;  // @12_63cfe0
  L63d043:;
  eax = 0;  // @14_63cfe0
  L63d045:;
  reg.state = (s32)((u32)(4294967295));  // @16_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 536), &v, sizeof v); }  // @17_63cfe0
  L63d052:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 540), sizeof v); (u32)v; }) != (u32)(0)) goto L63d09e;  // @19_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @20_63cfe0
  ecx = edx = 0;  // @21_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_63cfe0
  if ((eax & eax) == 0) goto L63d08f;  // @23_63cfe0
  ecx = (u32)(esi + 568);  // @24_63cfe0
  { u32 v = (u32)((u32)(7087184)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @26_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @27_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @28_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @29_63cfe0
  goto L63d091;  // @30_63cfe0
  L63d08f:;
  eax = 0;  // @32_63cfe0
  L63d091:;
  reg.state = (s32)((u32)(4294967295));  // @34_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 540), &v, sizeof v); }  // @35_63cfe0
  L63d09e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; }) != (u32)(0)) goto L63d0ea;  // @37_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @38_63cfe0
  ecx = edx = 0;  // @39_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_63cfe0
  if ((eax & eax) == 0) goto L63d0db;  // @41_63cfe0
  ecx = (u32)(esi + 568);  // @42_63cfe0
  { u32 v = (u32)((u32)(7087244)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @43_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @44_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @45_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @46_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @47_63cfe0
  goto L63d0dd;  // @48_63cfe0
  L63d0db:;
  eax = 0;  // @50_63cfe0
  L63d0dd:;
  reg.state = (s32)((u32)(4294967295));  // @52_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 544), &v, sizeof v); }  // @53_63cfe0
  L63d0ea:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 548), sizeof v); (u32)v; }) != (u32)(0)) goto L63d136;  // @55_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @56_63cfe0
  ecx = edx = 0;  // @57_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @58_63cfe0
  if ((eax & eax) == 0) goto L63d127;  // @59_63cfe0
  ecx = (u32)(esi + 568);  // @60_63cfe0
  { u32 v = (u32)((u32)(7087304)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @61_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @62_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @63_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @64_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @65_63cfe0
  goto L63d129;  // @66_63cfe0
  L63d127:;
  eax = 0;  // @68_63cfe0
  L63d129:;
  reg.state = (s32)((u32)(4294967295));  // @70_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 548), &v, sizeof v); }  // @71_63cfe0
  L63d136:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 552), sizeof v); (u32)v; }) != (u32)(0)) goto L63d182;  // @73_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @74_63cfe0
  ecx = edx = 0;  // @75_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @76_63cfe0
  if ((eax & eax) == 0) goto L63d173;  // @77_63cfe0
  ecx = (u32)(esi + 568);  // @78_63cfe0
  { u32 v = (u32)((u32)(7087364)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @79_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @80_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @81_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @82_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @83_63cfe0
  goto L63d175;  // @84_63cfe0
  L63d173:;
  eax = 0;  // @86_63cfe0
  L63d175:;
  reg.state = (s32)((u32)(4294967295));  // @88_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 552), &v, sizeof v); }  // @89_63cfe0
  L63d182:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 556), sizeof v); (u32)v; }) != (u32)(0)) goto L63d1ce;  // @91_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @92_63cfe0
  ecx = edx = 0;  // @93_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @94_63cfe0
  if ((eax & eax) == 0) goto L63d1bf;  // @95_63cfe0
  ecx = (u32)(esi + 568);  // @96_63cfe0
  { u32 v = (u32)((u32)(7087424)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @98_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @99_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @100_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @101_63cfe0
  goto L63d1c1;  // @102_63cfe0
  L63d1bf:;
  eax = 0;  // @104_63cfe0
  L63d1c1:;
  reg.state = (s32)((u32)(4294967295));  // @106_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 556), &v, sizeof v); }  // @107_63cfe0
  L63d1ce:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 560), sizeof v); (u32)v; }) != (u32)(0)) goto L63d21a;  // @109_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @110_63cfe0
  ecx = edx = 0;  // @111_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @112_63cfe0
  if ((eax & eax) == 0) goto L63d20b;  // @113_63cfe0
  ecx = (u32)(esi + 568);  // @114_63cfe0
  { u32 v = (u32)((u32)(7087484)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @115_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @116_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @117_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @118_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @119_63cfe0
  goto L63d20d;  // @120_63cfe0
  L63d20b:;
  eax = 0;  // @122_63cfe0
  L63d20d:;
  reg.state = (s32)((u32)(4294967295));  // @124_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 560), &v, sizeof v); }  // @125_63cfe0
  L63d21a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; }) != (u32)(0)) goto L63d25f;  // @127_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @128_63cfe0
  ecx = edx = 0;  // @129_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @130_63cfe0
  if ((eax & eax) == 0) goto L63d257;  // @131_63cfe0
  ecx = (u32)(esi + 568);  // @132_63cfe0
  { u32 v = (u32)((u32)(7087544)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @133_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @134_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @135_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @136_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @137_63cfe0
  goto L63d259;  // @138_63cfe0
  L63d257:;
  eax = 0;  // @140_63cfe0
  L63d259:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 564), &v, sizeof v); }  // @142_63cfe0
  L63d25f:;
  SEH_LEAVE();  // @144_63cfe0
  return eax;  // @145_63cfe0
}
PCREG(63cfe0, lifted_63cfe0);

extern "C" u32 lifted_4216f0(void) {
  SEH_ENTER(0x664311);  // @h_4216f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; }) != (u32)(0)) goto L4217ad;  // @0_4216f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340968), sizeof v); (u32)v; }) == (u32)(0)) goto L421737;  // @1_4216f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2_4216f0
  if ((eax & eax) == 0) goto L421736;  // @3_4216f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @4_4216f0
  ecx = edx = 0;  // @5_4216f0
  goto L421737;  // @6_4216f0
  L421736:;
  __builtin_trap();  // @8_4216f0
  L421737:;
  eax = ext_41e290_cdecl1((u32)(4116));  // @10_4216f0
  ecx = edx = 0;  // @11_4216f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_4216f0
  reg.state = (s32)((u32)(0));  // @13_4216f0
  if ((eax & eax) == 0) goto L42175d;  // @14_4216f0
  ecx = eax;  // @15_4216f0
  eax = ext_5f12d0_thiscall1(ecx);  // @16_4216f0
  ecx = edx = 0;  // @17_4216f0
  ecx = eax;  // @18_4216f0
  goto L42175f;  // @19_4216f0
  L42175d:;
  ecx = 0;  // @21_4216f0
  L42175f:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340964), &v, sizeof v); }  // @23_4216f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4216f0
  reg.state = (s32)((u32)(4294967295));  // @25_4216f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @26_4216f0
  ecx = edx = 0;  // @27_4216f0
  eax = ext_41e290_cdecl1((u32)(52));  // @28_4216f0
  ecx = edx = 0;  // @29_4216f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4216f0
  reg.state = (s32)((u32)(1));  // @31_4216f0
  if ((eax & eax) == 0) goto L421794;  // @32_4216f0
  ecx = eax;  // @33_4216f0
  eax = ext_4ff7b0_thiscall1(ecx);  // @34_4216f0
  ecx = edx = 0;  // @35_4216f0
  ecx = eax;  // @36_4216f0
  goto L421796;  // @37_4216f0
  L421794:;
  ecx = 0;  // @39_4216f0
  L421796:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340968), &v, sizeof v); }  // @41_4216f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4216f0
  reg.state = (s32)((u32)(4294967295));  // @43_4216f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @44_4216f0
  ecx = edx = 0;  // @45_4216f0
  eax = ext_41cfd0_thiscall1(ecx);  // @46_4216f0
  ecx = edx = 0;  // @47_4216f0
  L4217ad:;
  SEH_LEAVE();  // @49_4216f0
  return eax;  // @50_4216f0
}
PCREG(4216f0, lifted_4216f0);

