// batch226034.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f5490_thiscall3(u32, u32, u32) __asm__("ext_5f5490");
extern "C" u32 THISCALL ext_6033c0_thiscall2(u32, u32) __asm__("ext_6033c0");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_603850_thiscall1(u32) __asm__("ext_603850");
extern "C" u32 THISCALL ext_606ee0_thiscall4(u32, u32, u32, u32) __asm__("ext_606ee0");
extern "C" u32 THISCALL ext_6071c0_thiscall1(u32) __asm__("ext_6071c0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4352f0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4352f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_4352f0
  eax = 0;  // @1_4352f0
  L435325:;
  if (eax >= (u32)(128)) goto L4353a0;  // @3_4352f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 144), &v, sizeof v); }  // @4_4352f0
  eax = (eax + 1);  // @5_4352f0
  if ((s32)eax < (s32)(u32)(128)) goto L435325;  // @6_4352f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @7_4352f0
  edx = (u32)(EBP - 144);  // @8_4352f0
  PS[2] = edx;  // @9_4352f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4352f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(PS[2]), (u32)(6792648), (u32)(8));  // @11_4352f0
  ecx = edx = 0;  // @12_4352f0
  eax = (u32)(EBP - 144);  // @13_4352f0
  PS[0] = eax;  // @14_4352f0
  ecx = (u32)(EBP - 272);  // @15_4352f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @16_4352f0
  ecx = edx = 0;  // @17_4352f0
  eax = (u32)(EBP - 272);  // @18_4352f0
  reg.state = (s32)((u32)(0));  // @19_4352f0
  PS[0] = eax;  // @20_4352f0
  ecx = (u32)(esi + 140);  // @21_4352f0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @22_4352f0
  ecx = edx = 0;  // @23_4352f0
  ecx = (u32)(EBP - 272);  // @24_4352f0
  eax = ext_4cbec0_thiscall1(ecx);  // @25_4352f0
  ecx = edx = 0;  // @26_4352f0
  SEH_LEAVE();  // @27_4352f0
  ext_633654(G(u32, 0x6f5630));  // @28_4352f0
  return eax;  // @29_4352f0
  L4353a0:;
  eax = ext_634047_cdecl0();  // @31_4352f0
  ecx = edx = 0;  // @32_4352f0
}
PCREG(4352f0, lifted_4352f0);

extern "C" u32 THISCALL lifted_4e6ce0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_4e6ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = (u32)(ecx + 12);  // @0_4e6ce0
  { u32 v = (u32)((u32)(6877288)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1_4e6ce0
  if ((esi & esi) == 0) goto L4e6d4c;  // @2_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_4e6ce0
  ecx = (u32)(EBP - 24);  // @4_4e6ce0
  PS[0] = ecx;  // @5_4e6ce0
  ecx = esi;  // @6_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @7_4e6ce0
  ecx = edx = 0;  // @8_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4e6ce0
  ecx = (u32)(EBP - 24);  // @10_4e6ce0
  PS[0] = ecx;  // @11_4e6ce0
  ecx = esi;  // @12_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @13_4e6ce0
  ecx = edx = 0;  // @14_4e6ce0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4e6d4c;  // @15_4e6ce0
  L4e6d30:;
  PS[1] = eax;  // @17_4e6ce0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(24));  // @18_4e6ce0
  ecx = edx = 0;  // @19_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_4e6ce0
  ecx = (u32)(EBP - 24);  // @21_4e6ce0
  PS[0] = ecx;  // @22_4e6ce0
  ecx = esi;  // @23_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @24_4e6ce0
  ecx = edx = 0;  // @25_4e6ce0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4e6d30;  // @26_4e6ce0
  L4e6d4c:;
  ecx = esi;  // @28_4e6ce0
  eax = ext_4ccf60_thiscall1(ecx);  // @29_4e6ce0
  ecx = edx = 0;  // @30_4e6ce0
  SEH_LEAVE();  // @31_4e6ce0
  return eax;  // @32_4e6ce0
}
PCREG(4e6ce0, lifted_4e6ce0);

extern "C" u32 THISCALL lifted_474e00(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66705b);  // @h_474e00
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_474e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_474e00
  ecx = (u32)(EBP - 16596);  // @2_474e00
  eax = ext_4d2280_thiscall1(ecx);  // @3_474e00
  ecx = edx = 0;  // @4_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_474e00
  PS[0] = esi;  // @6_474e00
  reg.state = (s32)((u32)(0));  // @7_474e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_474e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_474e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @10_474e00
  ecx = edx = 0;  // @11_474e00
  PS[0] = eax;  // @12_474e00
  ecx = (u32)(EBP - 16596);  // @13_474e00
  eax = ext_4d3ab0_stdcall2((u32)(6851120), (u32)(PS[0]));  // @14_474e00
  ecx = edx = 0;  // @15_474e00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_474e00
  eax = (u32)(EBP - 16596);  // @17_474e00
  PS[0] = eax;  // @18_474e00
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338412), sizeof v); (u32)v; });  // @19_474e00
  ecx = edi;  // @20_474e00
  PS[1] = eax;  // @21_474e00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 360)))(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @22_474e00
  ecx = edx = 0;  // @23_474e00
  ecx = (u32)(EBP - 16596);  // @24_474e00
  eax = ext_4d2330_thiscall1(ecx);  // @25_474e00
  ecx = edx = 0;  // @26_474e00
  SEH_LEAVE();  // @27_474e00
  ext_633654(G(u32, 0x6f5630));  // @28_474e00
  return eax;  // @29_474e00
}
PCREG(474e00, lifted_474e00);

extern "C" u32 STDCALL lifted_601d80(u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66d907);  // @h_601d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
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

extern "C" u32 THISCALL lifted_606a70(u32 ecx_in) {
  SEH_ENTER(0x66df2b);  // @h_606a70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_606a70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_606a70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @2_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 3), &v, sizeof v); }  // @3_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 7), &v, sizeof v); }  // @4_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 11), &v, sizeof v); }  // @5_606a70
  ecx = (u32)(100);  // @6_606a70
  reg.state = (s32)((u32)(0));  // @7_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 15), &v, sizeof v); }  // @8_606a70
  eax = ext_6071c0_thiscall1(ecx);  // @9_606a70
  ecx = edx = 0;  // @10_606a70
  esi = eax;  // @11_606a70
  ecx = (u32)(ebx + 3);  // @12_606a70
  PS[0] = esi;  // @13_606a70
  eax = ext_59a9b0_thiscall2(ecx, (u32)(PS[0]));  // @14_606a70
  ecx = edx = 0;  // @15_606a70
  eax = (u32)(EBP - 16);  // @16_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @17_606a70
  PS[0] = eax;  // @18_606a70
  PS[1] = esi;  // @19_606a70
  ecx = (u32)(ebx + 3);  // @20_606a70
  eax = ext_606ee0_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 7), sizeof v); (u32)v; }), (u32)(PS[1]), (u32)(PS[0]));  // @21_606a70
  ecx = edx = 0;  // @22_606a70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 15), &v, sizeof v); }  // @23_606a70
  eax = ebx;  // @24_606a70
  SEH_LEAVE();  // @25_606a70
  return eax;  // @26_606a70
}
PCREG(606a70, lifted_606a70);

extern "C" u32 THISCALL lifted_5a3dc0(u32 ecx_in) {
  SEH_ENTER(0x66cb76);  // @h_5a3dc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_5a3dc0
  { u32 v = (u32)((u32)(7008280)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @1_5a3dc0
  esi = (u32)(ebx + 233);  // @2_5a3dc0
  edi = (u32)(4);  // @3_5a3dc0
  L5a3df8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_5a3dc0
  if ((ecx & ecx) == 0) goto L5a3e04;  // @6_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5a3dc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @8_5a3dc0
  ecx = edx = 0;  // @9_5a3dc0
  L5a3e04:;
  esi = (esi + (u32)(4));  // @11_5a3dc0
  edi = (edi - (u32)(1));  // @12_5a3dc0
  if (edi != 0) goto L5a3df8;  // @13_5a3dc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @14_5a3dc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @15_5a3dc0
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @16_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_5a3dc0
  PS[0] = ebx;  // @18_5a3dc0
  reg.state = (s32)(edi);  // @19_5a3dc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_5a3dc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_5a3dc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @22_5a3dc0
  ecx = edx = 0;  // @23_5a3dc0
  SEH_LEAVE();  // @24_5a3dc0
  return eax;  // @25_5a3dc0
}
PCREG(5a3dc0, lifted_5a3dc0);

extern "C" u32 THISCALL lifted_603500(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dc73);  // @h_603500
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_603500
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_603500
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @2_603500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @3_603500
  ecx = (u32)(ebx + 12);  // @4_603500
  reg.state = (s32)((u32)(0));  // @5_603500
  { u32 v = (u32)((u32)(7051812)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_603500
  eax = ext_6033c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @7_603500
  ecx = edx = 0;  // @8_603500
  eax = (u32)(EBP - 24);  // @9_603500
  reg.state = (s32)((u32)(1));  // @10_603500
  PS[1] = eax;  // @11_603500
  ecx = (u32)(ebx + 12);  // @12_603500
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @13_603500
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @14_603500
  eax = ext_5f5490_thiscall3(ecx, (u32)(PS[1]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @15_603500
  ecx = edx = 0;  // @16_603500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7489176), sizeof v); (u32)v; }) != (u32)(0)) goto L603580;  // @17_603500
  ecx = ebx;  // @18_603500
  eax = ext_603850_thiscall1(ecx);  // @19_603500
  ecx = edx = 0;  // @20_603500
  L603580:;
  eax = ebx;  // @22_603500
  SEH_LEAVE();  // @23_603500
  return eax;  // @24_603500
}
PCREG(603500, lifted_603500);

extern "C" u32 FASTCALL lifted_42b160(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x6649b1);  // @h_42b160
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = edx;  // @0_42b160
  esi = ecx;  // @1_42b160
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42b160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @3_42b160
  if (esi == ebx) goto L42b1be;  // @4_42b160
  L42b194:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_42b160
  reg.state = (s32)((u32)(0));  // @7_42b160
  if ((edi & edi) == 0) goto L42b1aa;  // @8_42b160
  PS[0] = esi;  // @9_42b160
  ecx = edi;  // @10_42b160
  eax = ext_5f10c0_thiscall2(ecx, (u32)(PS[0]));  // @11_42b160
  ecx = edx = 0;  // @12_42b160
  L42b1aa:;
  esi = (esi + (u32)(12));  // @14_42b160
  reg.state = (s32)((u32)(4294967295));  // @15_42b160
  edi = (edi + (u32)(12));  // @16_42b160
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @17_42b160
  if (esi != ebx) goto L42b194;  // @18_42b160
  L42b1be:;
  eax = edi;  // @20_42b160
  SEH_LEAVE();  // @21_42b160
  return eax;  // @22_42b160
}
PCREG(42b160, lifted_42b160);

