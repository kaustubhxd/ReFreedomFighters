// batch218000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_44b610_thiscall1(u32) __asm__("ext_44b610");
extern "C" u32 THISCALL ext_5f4630_thiscall1(u32) __asm__("ext_5f4630");
extern "C" u32 THISCALL ext_600d70_thiscall3(u32, u32, u32) __asm__("ext_600d70");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_641bd0_thiscall1(u32) __asm__("ext_641bd0");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 THISCALL ext_661310_thiscall2(u32, u32) __asm__("ext_661310");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4ccef0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4ccef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
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
  PV[0] = (u32)(edi);  // @9_4ccef0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @10_4ccef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[0]);  // @11_4ccef0
  ecx = edx = 0;  // @12_4ccef0
  if ((edi & edi) != 0) goto L4ccf31;  // @13_4ccef0
  L4ccf40:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @15_4ccef0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @16_4ccef0
  SEH_LEAVE();  // @17_4ccef0
  return eax;  // @18_4ccef0
}
PCREG(4ccef0, lifted_4ccef0);

extern "C" u32 THISCALL lifted_654780(u32 ecx_in) {
  SEH_ENTER(0x66ed22);  // @h_654780
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_654780
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L6547e8;  // @1_654780
  eax = ext_41e290_cdecl1((u32)(8625));  // @2_654780
  ecx = edx = 0;  // @3_654780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_654780
  reg.state = (s32)((u32)(0));  // @5_654780
  if ((eax & eax) == 0) goto L6547e3;  // @6_654780
  ecx = eax;  // @7_654780
  eax = ext_661310_thiscall2(ecx, (u32)(0));  // @8_654780
  ecx = edx = 0;  // @9_654780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @10_654780
  SEH_LEAVE();  // @11_654780
  return eax;  // @12_654780
  L6547e3:;
  eax = 0;  // @14_654780
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @15_654780
  L6547e8:;
  SEH_LEAVE();  // @17_654780
  return eax;  // @18_654780
}
PCREG(654780, lifted_654780);

extern "C" u32 THISCALL lifted_42ba60(u32 ecx_in) {
  SEH_ENTER(0x66b0fc);  // @h_42ba60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_42ba60
  ecx = (u32)(esi + 12);  // @1_42ba60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_42ba60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @3_42ba60
  eax = (eax - edx);  // @4_42ba60
  reg.state = (s32)((u32)(0));  // @5_42ba60
  if ((edx & edx) == 0) goto L42baa5;  // @6_42ba60
  if ((eax & eax) == 0) goto L42baa5;  // @7_42ba60
  PV[0] = (u32)(eax);  // @8_42ba60
  PV[1] = (u32)(edx);  // @9_42ba60
  eax = ext_54f870_stdcall2(PV[1], PV[0]);  // @10_42ba60
  ecx = edx = 0;  // @11_42ba60
  L42baa5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @13_42ba60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @14_42ba60
  eax = (eax - ecx);  // @15_42ba60
  reg.state = (s32)((u32)(1));  // @16_42ba60
  if ((ecx & ecx) == 0) goto L42bac4;  // @17_42ba60
  if ((eax & eax) == 0) goto L42bac4;  // @18_42ba60
  PV[2] = (u32)(eax);  // @19_42ba60
  PV[3] = (u32)(ecx);  // @20_42ba60
  ecx = esi;  // @21_42ba60
  eax = ext_54f870_stdcall2(PV[3], PV[2]);  // @22_42ba60
  ecx = edx = 0;  // @23_42ba60
  L42bac4:;
  SEH_LEAVE();  // @25_42ba60
  return eax;  // @26_42ba60
}
PCREG(42ba60, lifted_42ba60);

extern "C" u32 THISCALL lifted_4cd240(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669286);  // @h_4cd240
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cd240
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1_4cd240
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_4cd240
  reg.state = (s32)((u32)(0));  // @3_4cd240
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_4cd240
  if ((edi & edi) == 0) goto L4cd290;  // @5_4cd240
  L4cd281:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4cd240
  ecx = esi;  // @8_4cd240
  PV[0] = (u32)(edi);  // @9_4cd240
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @10_4cd240
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[0]);  // @11_4cd240
  ecx = edx = 0;  // @12_4cd240
  if ((edi & edi) != 0) goto L4cd281;  // @13_4cd240
  L4cd290:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @15_4cd240
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @16_4cd240
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4cd2af;  // @17_4cd240
  PV[1] = (u32)(esi);  // @18_4cd240
  eax = ext_634273_cdecl2(PV[1], (u32)(36));  // @19_4cd240
  ecx = edx = 0;  // @20_4cd240
  L4cd2af:;
  eax = esi;  // @22_4cd240
  SEH_LEAVE();  // @23_4cd240
  return eax;  // @24_4cd240
}
PCREG(4cd240, lifted_4cd240);

extern "C" u32 THISCALL lifted_616620(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66e628);  // @h_616620
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edi = ecx;  // @0_616620
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_616620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_616620
  ecx = (u32)(edi + 8);  // @5_616620
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_616620
  { u32 v = (u32)((u32)(7068760)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_616620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_616620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @9_616620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @10_616620
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 47528), sizeof v); (u32)v; });  // @11_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @12_616620
  reg.state = (s32)((u32)(0));  // @13_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @14_616620
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @15_616620
  PV[1] = (u32)(eax);  // @16_616620
  eax = ext_659330_thiscall3(ecx, PV[1], PV[0]);  // @17_616620
  ecx = edx = 0;  // @18_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @19_616620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @20_616620
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) | (u32)(16777216))); __builtin_memcpy((void *)(u32)(eax + 60), &v, sizeof v); }  // @21_616620
  eax = edi;  // @22_616620
  { u32 v = (u32)((u32)(7068812)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @23_616620
  SEH_LEAVE();  // @24_616620
  return eax;  // @25_616620
}
PCREG(616620, lifted_616620);

extern "C" u32 THISCALL lifted_44c060(u32 ecx_in) {
  SEH_ENTER(0x665c56);  // @h_44c060
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = ecx;  // @0_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_44c060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }) == (u32)(0)) goto L44c0df;  // @2_44c060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 28), sizeof v); (u32)v; });  // @3_44c060
  if ((edx & edx) == 0) goto L44c0df;  // @4_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @5_44c060
  PV[0] = (u32)(edx);  // @6_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_44c060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[0]);  // @8_44c060
  ecx = edx = 0;  // @9_44c060
  esi = eax;  // @10_44c060
  if ((esi & esi) == 0) goto L44c0df;  // @11_44c060
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_44c060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L44c0df;  // @13_44c060
  ecx = esi;  // @14_44c060
  eax = ext_44b610_thiscall1(ecx);  // @15_44c060
  ecx = edx = 0;  // @16_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_44c060
  reg.state = (s32)((u32)(0));  // @18_44c060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @19_44c060
  if ((ecx & ecx) == 0) goto L44c0df;  // @20_44c060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_44c060
  PV[1] = (u32)(esi);  // @22_44c060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 280)))(ecx, PV[1]);  // @23_44c060
  ecx = edx = 0;  // @24_44c060
  L44c0df:;
  SEH_LEAVE();  // @26_44c060
  return eax;  // @27_44c060
}
PCREG(44c060, lifted_44c060);

extern "C" u32 THISCALL lifted_640ea0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_640ea0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_640ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 37), sizeof v); (u32)v; });  // @1_640ea0
  { u32 v = (u32)((u32)(7088144)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_640ea0
  if ((ecx & ecx) == 0) goto L640eec;  // @3_640ea0
  eax = (u32)(ecx - 4);  // @4_640ea0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 4), sizeof v); (u32)v; }) == (u32)(0)) goto L640ee3;  // @5_640ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_640ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(3));  // @7_640ea0
  ecx = edx = 0;  // @8_640ea0
  goto L640eec;  // @9_640ea0
  L640ee3:;
  PV[0] = (u32)(eax);  // @11_640ea0
  eax = ext_41e2c0_cdecl1(PV[0]);  // @12_640ea0
  ecx = edx = 0;  // @13_640ea0
  L640eec:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @15_640ea0
  if ((ecx & ecx) == 0) goto L640ef9;  // @16_640ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_640ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_640ea0
  ecx = edx = 0;  // @19_640ea0
  L640ef9:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @21_640ea0
  eax = ext_634273_cdecl2(PV[1], (u32)(4));  // @22_640ea0
  ecx = edx = 0;  // @23_640ea0
  ecx = esi;  // @24_640ea0
  eax = ext_641bd0_thiscall1(ecx);  // @25_640ea0
  ecx = edx = 0;  // @26_640ea0
  SEH_LEAVE();  // @27_640ea0
  return eax;  // @28_640ea0
}
PCREG(640ea0, lifted_640ea0);

extern "C" u32 THISCALL lifted_601f70(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66d93f);  // @h_601f70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_601f70
  eax = ext_41e290_cdecl1((u32)(4));  // @1_601f70
  ecx = edx = 0;  // @2_601f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601f70
  reg.state = (s32)((u32)(0));  // @4_601f70
  if ((eax & eax) == 0) goto L601fc0;  // @5_601f70
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @6_601f70
  ecx = eax;  // @7_601f70
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_601f70
  eax = ext_600d70_thiscall3(ecx, PV[1], PV[0]);  // @9_601f70
  ecx = edx = 0;  // @10_601f70
  edi = eax;  // @11_601f70
  goto L601fc2;  // @12_601f70
  L601fc0:;
  edi = 0;  // @14_601f70
  L601fc2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @16_601f70
  reg.state = (s32)((u32)(4294967295));  // @17_601f70
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L601fd9;  // @18_601f70
  ecx = (u32)(esi + 4);  // @19_601f70
  eax = ext_5f4630_thiscall1(ecx);  // @20_601f70
  ecx = edx = 0;  // @21_601f70
  L601fd9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @23_601f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @24_601f70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @25_601f70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @26_601f70
  SEH_LEAVE();  // @27_601f70
  return eax;  // @28_601f70
}
PCREG(601f70, lifted_601f70);

extern "C" u32 STDCALL lifted_601e20(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ext_41e290_cdecl1((u32)(42));  // @0_601e20
  ecx = edx = 0;  // @1_601e20
  esi = eax;  // @2_601e20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_601e20
  reg.state = (s32)((u32)(0));  // @4_601e20
  if ((esi & esi) == 0) goto L601e90;  // @5_601e20
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @6_601e20
  ecx = esi;  // @7_601e20
  eax = ext_603500_thiscall2(ecx, PV[0]);  // @8_601e20
  ecx = edx = 0;  // @9_601e20
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_601e20
  eax = (u32)(esi + 12);  // @11_601e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @12_601e20
  eax = 0;  // @13_601e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @14_601e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @15_601e20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @16_601e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_601e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @18_601e20
  goto L601e92;  // @19_601e20
  L601e90:;
  esi = 0;  // @21_601e20
  L601e92:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_601e20
  ecx = esi;  // @24_601e20
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @25_601e20
  reg.state = (s32)((u32)(4294967295));  // @26_601e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[1]);  // @27_601e20
  ecx = edx = 0;  // @28_601e20
  eax = esi;  // @29_601e20
  SEH_LEAVE();  // @30_601e20
  return eax;  // @31_601e20
}
PCREG(601e20, lifted_601e20);

