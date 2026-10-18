// batch226033.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_500990_thiscall2(u32, u32) __asm__("ext_500990");
extern "C" u32 THISCALL ext_505d50_thiscall1(u32) __asm__("ext_505d50");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4d16e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66930f);  // @h_4d16e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4d16e0
  eax = ext_41e290_cdecl1((u32)(20));  // @1_4d16e0
  ecx = edx = 0;  // @2_4d16e0
  edi = eax;  // @3_4d16e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4d16e0
  reg.state = (s32)((u32)(0));  // @5_4d16e0
  if ((edi & edi) == 0) goto L4d176e;  // @6_4d16e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_4d16e0
  edx = (u32)(ecx + 1);  // @8_4d16e0
  L4d1728:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @10_4d16e0
  ecx = (ecx + 1);  // @11_4d16e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4d1728;  // @12_4d16e0
  ecx = (ecx - edx);  // @13_4d16e0
  esi = (u32)(ecx + 1);  // @14_4d16e0
  PS[0] = esi;  // @15_4d16e0
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @16_4d16e0
  ecx = edx = 0;  // @17_4d16e0
  PS[0] = esi;  // @18_4d16e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @19_4d16e0
  PS[2] = eax;  // @20_4d16e0
  eax = ext_634d22_cdecl3((u32)(PS[2]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(PS[0]));  // @21_4d16e0
  ecx = edx = 0;  // @22_4d16e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @23_4d16e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @24_4d16e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @25_4d16e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @26_4d16e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @27_4d16e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @28_4d16e0
  if ((eax & eax) == 0) goto L4d1768;  // @29_4d16e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @30_4d16e0
  goto L4d176b;  // @31_4d16e0
  L4d1768:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @33_4d16e0
  L4d176b:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @35_4d16e0
  L4d176e:;
  SEH_LEAVE();  // @37_4d16e0
  return eax;  // @38_4d16e0
}
PCREG(4d16e0, lifted_4d16e0);

extern "C" u32 THISCALL lifted_5047c0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669bf8);  // @h_5047c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5047c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5047c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5047c0
  PS[0] = esi;  // @3_5047c0
  eax = ext_500990_thiscall2(ecx, (u32)(PS[0]));  // @4_5047c0
  ecx = edx = 0;  // @5_5047c0
  reg.state = (s32)((u32)(0));  // @6_5047c0
  { u32 v = (u32)((u32)(6933640)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_5047c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @8_5047c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343996), sizeof v); (u32)v; }) != (u32)(0)) goto L504813;  // @9_5047c0
  ecx = edi;  // @10_5047c0
  eax = ext_505d50_thiscall1(ecx);  // @11_5047c0
  ecx = edx = 0;  // @12_5047c0
  L504813:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7245439), sizeof v); (u32)v; }) == (u32)(0)) goto L504854;  // @14_5047c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5047c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7245439), &v, sizeof v); }  // @16_5047c0
  if ((ecx & ecx) == 0) goto L504854;  // @17_5047c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_5047c0
  edx = (u32)(EBP + 8);  // @19_5047c0
  PS[0] = edx;  // @20_5047c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @21_5047c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6933760), (u32)(PS[0]));  // @22_5047c0
  ecx = edx = 0;  // @23_5047c0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7343992), sizeof v); (u32)v; });  // @24_5047c0
  edx = (u32)(1);  // @25_5047c0
  if (((eax & 0xff) & (eax & 0xff)) != 0) ecx = edx;  // @26_5047c0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(7343992), &v, sizeof v); }  // @27_5047c0
  L504854:;
  eax = edi;  // @29_5047c0
  SEH_LEAVE();  // @30_5047c0
  return eax;  // @31_5047c0
}
PCREG(5047c0, lifted_5047c0);

extern "C" u32 THISCALL lifted_435630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66697b);  // @h_435630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435630
  ecx = (u32)(EBP - 144);  // @2_435630
  PS[0] = eax;  // @3_435630
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @4_435630
  ecx = edx = 0;  // @5_435630
  eax = (u32)(EBP - 144);  // @6_435630
  reg.state = (s32)((u32)(0));  // @7_435630
  edi = (edi + (u32)(12));  // @8_435630
  PS[0] = eax;  // @9_435630
  ecx = edi;  // @10_435630
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @11_435630
  ecx = edx = 0;  // @12_435630
  ecx = (u32)(EBP - 144);  // @13_435630
  reg.state = (s32)((u32)(4294967295));  // @14_435630
  eax = ext_4cbec0_thiscall1(ecx);  // @15_435630
  ecx = edx = 0;  // @16_435630
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @17_435630
  ecx = edi;  // @18_435630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_435630
  eax = ext_4cc5f0_thiscall1(ecx);  // @20_435630
  ecx = edx = 0;  // @21_435630
  PS[0] = eax;  // @22_435630
  ecx = edi;  // @23_435630
  eax = ext_4cc1d0_cdecl1((u32)(PS[0]));  // @24_435630
  ecx = edx = 0;  // @25_435630
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @26_435630
  PS[0] = eax;  // @27_435630
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 20)))(ecx, (u32)(6792636), (u32)(8), (u32)(PS[0]));  // @28_435630
  ecx = edx = 0;  // @29_435630
  SEH_LEAVE();  // @30_435630
  ext_633654(G(u32, 0x6f5630));  // @31_435630
  return eax;  // @32_435630
}
PCREG(435630, lifted_435630);

