// batch200155.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_41f190_stdcall1(u32) __asm__("ext_41f190");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_56b460_stdcall1(u32) __asm__("ext_56b460");
extern "C" u32 STDCALL ext_661b40_stdcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_661b40");
extern "C" u32 THISCALL ext_438e30_thiscall1(u32) __asm__("ext_438e30");
extern "C" u32 THISCALL ext_439670_thiscall1(u32) __asm__("ext_439670");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_45fc70_thiscall2(u32, u32) __asm__("ext_45fc70");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4870b0_thiscall2(u32, u32) __asm__("ext_4870b0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4cce40_thiscall1(u32) __asm__("ext_4cce40");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cdcc0_thiscall1(u32) __asm__("ext_4cdcc0");
extern "C" u32 THISCALL ext_4d0f30_thiscall4(u32, u32, u32, u32) __asm__("ext_4d0f30");
extern "C" u32 THISCALL ext_4d4c90_thiscall3(u32, u32, u32) __asm__("ext_4d4c90");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_503770_thiscall2(u32, u32) __asm__("ext_503770");
extern "C" u32 THISCALL ext_505a00_thiscall2(u32, u32) __asm__("ext_505a00");
extern "C" u32 THISCALL ext_508680_thiscall2(u32, u32) __asm__("ext_508680");
extern "C" u32 THISCALL ext_512850_thiscall2(u32, u32) __asm__("ext_512850");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_561160_thiscall1(u32) __asm__("ext_561160");
extern "C" u32 THISCALL ext_562bc0_thiscall1(u32) __asm__("ext_562bc0");
extern "C" u32 THISCALL ext_563400_thiscall1(u32) __asm__("ext_563400");
extern "C" u32 THISCALL ext_563440_thiscall1(u32) __asm__("ext_563440");
extern "C" u32 THISCALL ext_564460_thiscall1(u32) __asm__("ext_564460");
extern "C" u32 THISCALL ext_564600_thiscall2(u32, u32) __asm__("ext_564600");
extern "C" u32 THISCALL ext_5646e0_thiscall2(u32, u32) __asm__("ext_5646e0");
extern "C" u32 THISCALL ext_565100_thiscall2(u32, u32) __asm__("ext_565100");
extern "C" u32 THISCALL ext_565840_thiscall1(u32) __asm__("ext_565840");
extern "C" u32 THISCALL ext_565870_thiscall1(u32) __asm__("ext_565870");
extern "C" u32 THISCALL ext_565b90_thiscall1(u32) __asm__("ext_565b90");
extern "C" u32 THISCALL ext_566bc0_thiscall1(u32) __asm__("ext_566bc0");
extern "C" u32 THISCALL ext_566c90_thiscall1(u32) __asm__("ext_566c90");
extern "C" u32 THISCALL ext_567720_thiscall1(u32) __asm__("ext_567720");
extern "C" u32 THISCALL ext_569380_thiscall1(u32) __asm__("ext_569380");
extern "C" u32 THISCALL ext_5696b0_thiscall1(u32) __asm__("ext_5696b0");
extern "C" u32 THISCALL ext_569730_thiscall1(u32) __asm__("ext_569730");
extern "C" u32 THISCALL ext_56ad80_thiscall1(u32) __asm__("ext_56ad80");
extern "C" u32 THISCALL ext_56b2d0_thiscall1(u32) __asm__("ext_56b2d0");
extern "C" u32 THISCALL ext_56c6a0_thiscall1(u32) __asm__("ext_56c6a0");
extern "C" u32 THISCALL ext_56c810_thiscall1(u32) __asm__("ext_56c810");
extern "C" u32 THISCALL ext_56db70_thiscall1(u32) __asm__("ext_56db70");
extern "C" u32 THISCALL ext_56e990_thiscall1(u32) __asm__("ext_56e990");
extern "C" u32 THISCALL ext_56fea0_thiscall1(u32) __asm__("ext_56fea0");
extern "C" u32 THISCALL ext_571960_thiscall1(u32) __asm__("ext_571960");
extern "C" u32 THISCALL ext_572360_thiscall1(u32) __asm__("ext_572360");
extern "C" u32 THISCALL ext_572e40_thiscall1(u32) __asm__("ext_572e40");
extern "C" u32 THISCALL ext_573590_thiscall1(u32) __asm__("ext_573590");
extern "C" u32 THISCALL ext_573650_thiscall4(u32, u32, u32, u32) __asm__("ext_573650");
extern "C" u32 THISCALL ext_574c60_thiscall1(u32) __asm__("ext_574c60");
extern "C" u32 THISCALL ext_575d50_thiscall1(u32) __asm__("ext_575d50");
extern "C" u32 THISCALL ext_5773f0_thiscall1(u32) __asm__("ext_5773f0");
extern "C" u32 THISCALL ext_577830_thiscall1(u32) __asm__("ext_577830");
extern "C" u32 THISCALL ext_578560_thiscall1(u32) __asm__("ext_578560");
extern "C" u32 THISCALL ext_578710_thiscall1(u32) __asm__("ext_578710");
extern "C" u32 THISCALL ext_57a100_thiscall1(u32) __asm__("ext_57a100");
extern "C" u32 THISCALL ext_57a3b0_thiscall1(u32) __asm__("ext_57a3b0");
extern "C" u32 THISCALL ext_57a440_thiscall1(u32) __asm__("ext_57a440");
extern "C" u32 THISCALL ext_57abc0_thiscall1(u32) __asm__("ext_57abc0");
extern "C" u32 THISCALL ext_57aea0_thiscall1(u32) __asm__("ext_57aea0");
extern "C" u32 THISCALL ext_57baa0_thiscall1(u32) __asm__("ext_57baa0");
extern "C" u32 THISCALL ext_57bd90_thiscall1(u32) __asm__("ext_57bd90");
extern "C" u32 THISCALL ext_57c100_thiscall1(u32) __asm__("ext_57c100");
extern "C" u32 THISCALL ext_57c460_thiscall1(u32) __asm__("ext_57c460");
extern "C" u32 THISCALL ext_57c7c0_thiscall1(u32) __asm__("ext_57c7c0");
extern "C" u32 THISCALL ext_57f1b0_thiscall1(u32) __asm__("ext_57f1b0");
extern "C" u32 THISCALL ext_5ae710_thiscall2(u32, u32) __asm__("ext_5ae710");
extern "C" u32 THISCALL ext_5aeff0_thiscall2(u32, u32) __asm__("ext_5aeff0");
extern "C" u32 THISCALL ext_5b6d00_thiscall1(u32) __asm__("ext_5b6d00");
extern "C" u32 THISCALL ext_5c5620_thiscall1(u32) __asm__("ext_5c5620");
extern "C" u32 THISCALL ext_5c5810_thiscall1(u32) __asm__("ext_5c5810");
extern "C" u32 THISCALL ext_5f9db0_thiscall2(u32, u32) __asm__("ext_5f9db0");
extern "C" u32 THISCALL ext_5fb210_thiscall3(u32, u32, u32) __asm__("ext_5fb210");
extern "C" u32 THISCALL ext_601380_thiscall1(u32) __asm__("ext_601380");
extern "C" u32 THISCALL ext_647f70_thiscall1(u32) __asm__("ext_647f70");
extern "C" u32 THISCALL ext_648dd0_thiscall1(u32) __asm__("ext_648dd0");
extern "C" u32 THISCALL ext_663610_thiscall2(u32, u32) __asm__("ext_663610");
extern "C" u32 THISCALL ext_663770_thiscall2(u32, u32) __asm__("ext_663770");
extern "C" u32 THISCALL ext_6638c0_thiscall2(u32, u32) __asm__("ext_6638c0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634aae_cdecl0(void) __asm__("ext_634aae");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" u32 ext_634e84_cdecl0(void) __asm__("ext_634e84");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_63b660(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_63b660
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_63b660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_63b660
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @3_63b660
  ecx = edx = 0;  // @4_63b660
  if ((eax & eax) != 0) goto L63b67a;  // @5_63b660
  return eax;  // @6_63b660
  L63b67a:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @8_63b660
  return eax;  // @9_63b660
}
PCREG(63b660, lifted_63b660);

extern "C" u32 STDCALL lifted_54f110(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_54f110
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_54f110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_54f110
  if (edx == esi) goto L54f147;  // @3_54f110
  if ((s32)edx <= (s32)esi) goto L54f133;  // @4_54f110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_54f110
  eax = edx;  // @6_54f110
  eax = (eax - esi);  // @7_54f110
  if ((s32)eax <= (s32)ecx) goto L54f147;  // @8_54f110
  eax = (u32)(esi + ecx);  // @9_54f110
  return eax;  // @10_54f110
  L54f133:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @12_54f110
  ecx = esi;  // @13_54f110
  ecx = (ecx - edx);  // @14_54f110
  if ((s32)ecx <= (s32)eax) goto L54f147;  // @15_54f110
  esi = (esi - eax);  // @16_54f110
  eax = esi;  // @17_54f110
  return eax;  // @18_54f110
  L54f147:;
  eax = edx;  // @20_54f110
  return eax;  // @21_54f110
}
PCREG(54f110, lifted_54f110);

extern "C" u32 THISCALL lifted_5dbe30(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) & 0xffff);  // @0_5dbe30
  if ((eax & 0xffff) != ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7422852), sizeof v); (u32)v; })) goto L5dbe45;  // @1_5dbe30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_5dbe30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @3_5dbe30
  L5dbe45:;
  eax = 0;  // @5_5dbe30
  return eax;  // @6_5dbe30
}
PCREG(5dbe30, lifted_5dbe30);

extern "C" u32 THISCALL lifted_45e420(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ecx;  // @0_45e420
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_45e420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @2_45e420
  if ((s32)(esi & esi) >= 0) goto L45e473;  // @3_45e420
  if ((esi & (u32)(1073741824)) == 0) goto L45e440;  // @4_45e420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @5_45e420
  ecx = (ecx + (u32)(5));  // @6_45e420
  ecx = (u32)(edx + ecx*4);  // @7_45e420
  goto L45e443;  // @8_45e420
  L45e440:;
  ecx = (u32)(edx + 16);  // @10_45e420
  L45e443:;
  if ((ecx & ecx) == 0) goto L45e473;  // @12_45e420
  if ((s32)(esi & esi) >= 0) goto L45e450;  // @13_45e420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @14_45e420
  goto L45e452;  // @15_45e420
  L45e450:;
  edx = 0;  // @17_45e420
  L45e452:;
  if ((s32)(edx & edx) <= 0) goto L45e473;  // @19_45e420
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_45e420
  L45e460:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) == esi) goto L45e47a;  // @22_45e420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @23_45e420
  edx = (edx - 1);  // @24_45e420
  eax = (eax & (u32)(1073741823));  // @25_45e420
  ecx = (ecx + eax);  // @26_45e420
  if ((s32)(edx & edx) > 0) goto L45e460;  // @27_45e420
  L45e473:;
  eax = 0;  // @29_45e420
  return eax;  // @30_45e420
  L45e47a:;
  eax = ecx;  // @32_45e420
  return eax;  // @33_45e420
}
PCREG(45e420, lifted_45e420);

extern "C" u32 THISCALL lifted_4cd540(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4cd540
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4cd557;  // @1_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @2_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @3_4cd540
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; })) goto L4cd597;  // @4_4cd540
  L4cd557:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4cd540
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 128)))(ecx);  // @7_4cd540
  ecx = edx = 0;  // @8_4cd540
  ecx = eax;  // @9_4cd540
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @10_4cd540
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L4cd57f;  // @11_4cd540
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @12_4cd540
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @13_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @14_4cd540
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_4cd540
  goto L4cd58d;  // @16_4cd540
  L4cd57f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @18_4cd540
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @19_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_4cd540
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @21_4cd540
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @22_4cd540
  L4cd58d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @24_4cd540
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @25_4cd540
  L4cd597:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @28_4cd540
  edx = (u32)(ecx + eax*4);  // @29_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_4cd540
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @31_4cd540
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_4cd540
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @33_4cd540
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @34_4cd540
  eax = (u32)(edx + 20);  // @35_4cd540
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @36_4cd540
  return eax;  // @37_4cd540
}
PCREG(4cd540, lifted_4cd540);

extern "C" u32 THISCALL lifted_41f400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_41f400
  ebx = ecx;  // @1_41f400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @2_41f400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @3_41f400
  eax = (u32)(edi + 32);  // @4_41f400
  p0_ = eax;  // @5_41f400
  eax = ext_41f190_stdcall1((u32)(p0_));  // @6_41f400
  ecx = edx = 0;  // @7_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == esi) goto L41f43e;  // @8_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @9_41f400
  ecx = ebx;  // @10_41f400
  p1_ = edi;  // @11_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780060), (u32)(p1_));  // @12_41f400
  ecx = edx = 0;  // @13_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @14_41f400
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @15_41f400
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @16_41f400
  if ((eax & eax) == 0) goto L41f478;  // @17_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_41f400
  ecx = edx = 0;  // @19_41f400
  L41f43e:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @21_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @22_41f400
  eax = (eax & (u32)(536870911));  // @23_41f400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 32), sizeof v); (u32)v; }) == (u32)(2271560481)) goto L41f487;  // @24_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_41f400
  ecx = ebx;  // @26_41f400
  p2_ = edi;  // @27_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780084), (u32)(p2_));  // @28_41f400
  ecx = edx = 0;  // @29_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_41f400
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @31_41f400
  if ((eax & eax) == 0) goto L41f47b;  // @32_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @33_41f400
  ecx = edx = 0;  // @34_41f400
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @35_41f400
  return eax;  // @36_41f400
  L41f478:;
  __builtin_trap();  // @38_41f400
  L41f47b:;
  __builtin_trap();  // @40_41f400
  L41f487:;
  eax = (eax & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @42_41f400
  return eax;  // @43_41f400
}
PCREG(41f400, lifted_41f400);

extern "C" u32 THISCALL lifted_51c210(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_51c210
  ebx = ecx;  // @1_51c210
  p0_ = edi;  // @2_51c210
  eax = ext_512850_thiscall2(ecx, (u32)(p0_));  // @3_51c210
  ecx = edx = 0;  // @4_51c210
  esi = (u32)(ebx + 1101);  // @5_51c210
  ecx = edi;  // @6_51c210
  p1_ = esi;  // @7_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p1_), (u32)(1));  // @8_51c210
  ecx = edx = 0;  // @9_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c267;  // @10_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @11_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(258));  // @13_51c210
  ecx = edx = 0;  // @14_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @15_51c210
  edx = (u32)(6801640);  // @16_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @17_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @18_51c210
  p2_ = edx;  // @19_51c210
  p3_ = eax;  // @20_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p3_), (u32)(6945012), (u32)(p2_));  // @21_51c210
  ecx = edx = 0;  // @22_51c210
  L51c267:;
  ecx = edi;  // @24_51c210
  eax = ext_4e1600_thiscall1(ecx);  // @25_51c210
  ecx = edx = 0;  // @26_51c210
  if ((eax & 0xff) != (u32)(8)) goto L51c2c6;  // @27_51c210
  esi = (u32)(ebx + 1105);  // @28_51c210
  ecx = edi;  // @29_51c210
  p4_ = esi;  // @30_51c210
  eax = ext_4e12e0_thiscall3(ecx, (u32)(p4_), (u32)(1));  // @31_51c210
  ecx = edx = 0;  // @32_51c210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) != (u32)(0)) goto L51c2d0;  // @33_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @34_51c210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_51c210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6944952), (u32)(261));  // @36_51c210
  ecx = edx = 0;  // @37_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @38_51c210
  edx = (u32)(6801640);  // @39_51c210
  if ((ecx & ecx) != 0) edx = ecx;  // @40_51c210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_51c210
  p5_ = edx;  // @42_51c210
  p6_ = eax;  // @43_51c210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(p6_), (u32)(6945036), (u32)(p5_));  // @44_51c210
  ecx = edx = 0;  // @45_51c210
  ecx = edi;  // @46_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @47_51c210
  ecx = edx = 0;  // @48_51c210
  return eax;  // @49_51c210
  L51c2c6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1105), &v, sizeof v); }  // @51_51c210
  L51c2d0:;
  ecx = edi;  // @53_51c210
  eax = ext_4e1b30_thiscall1(ecx);  // @54_51c210
  ecx = edx = 0;  // @55_51c210
  return eax;  // @56_51c210
}
PCREG(51c210, lifted_51c210);

extern "C" u32 THISCALL lifted_5dd1b0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5dd1b0
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_5dd1b0
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_5dd1b0
  esi = ecx;  // @3_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7040416), (u32)(0), (u32)(7040368), (u32)(56));  // @6_5dd1b0
  ecx = edx = 0;  // @7_5dd1b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_5dd1b0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L5dd239;  // @9_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; })) goto L5dd1ea;  // @10_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @11_5dd1b0
  L5dd1ea:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; })) goto L5dd1f3;  // @13_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @14_5dd1b0
  L5dd1f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; });  // @16_5dd1b0
  if (edi != eax) goto L5dd1fe;  // @17_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @18_5dd1b0
  L5dd1fe:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; });  // @20_5dd1b0
  if (edi != ecx) goto L5dd209;  // @21_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @22_5dd1b0
  L5dd209:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; })) goto L5dd212;  // @24_5dd1b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @25_5dd1b0
  L5dd212:;
  if (edi == eax) goto L5dd21a;  // @27_5dd1b0
  if (edi != ecx) goto L5dd239;  // @28_5dd1b0
  L5dd21a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 93), sizeof v); (u32)v; }));  // @33_5dd1b0
  ecx = edx = 0;  // @34_5dd1b0
  ecx = eax;  // @35_5dd1b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @37_5dd1b0
  ecx = edx = 0;  // @38_5dd1b0
  L5dd239:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_5dd1b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_5dd1b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5dd1b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7040428), (u32)(0), (u32)(7040368), (u32)(74));  // @43_5dd1b0
  ecx = edx = 0;  // @44_5dd1b0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L5dd295;  // @45_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73), sizeof v); (u32)v; })) goto L5dd269;  // @46_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @47_5dd1b0
  L5dd269:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 77), sizeof v); (u32)v; })) goto L5dd272;  // @49_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @50_5dd1b0
  L5dd272:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 81), sizeof v); (u32)v; })) goto L5dd27b;  // @52_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @53_5dd1b0
  L5dd27b:;
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 85), sizeof v); (u32)v; })) goto L5dd284;  // @55_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @56_5dd1b0
  L5dd284:;
  eax = 0;  // @58_5dd1b0
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 89), sizeof v); (u32)v; })) goto L5dd297;  // @59_5dd1b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @60_5dd1b0
  return eax;  // @61_5dd1b0
  L5dd295:;
  eax = 0;  // @63_5dd1b0
  L5dd297:;
  return eax;  // @65_5dd1b0
}
PCREG(5dd1b0, lifted_5dd1b0);

extern "C" u32 THISCALL lifted_4f1100(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f1100
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_4f1100
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_4f1100
  edi = ecx;  // @3_4f1100
  esi = (u32)(32);  // @4_4f1100
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @5_4f1100
  L4f1112:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @7_4f1100
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L4f1129;  // @8_4f1100
  edx = (edx + (u32)(4));  // @9_4f1100
  eax = (eax + (u32)(4));  // @10_4f1100
  esi = (esi - (u32)(4));  // @11_4f1100
  if (1 || esi) goto L4f1112;  // @12_4f1100
  return eax;  // @13_4f1100
  L4f1129:;
  ecx = edi;  // @15_4f1100
  eax = ext_45fc70_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @16_4f1100
  ecx = edx = 0;  // @17_4f1100
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 144), &v, sizeof v); }  // @18_4f1100
  return eax;  // @19_4f1100
}
PCREG(4f1100, lifted_4f1100);

extern "C" u32 THISCALL lifted_54f250(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @0_54f250
  if ((esi & esi) == 0) goto L54f2a0;  // @1_54f250
  eax = (u32)(ecx + 8);  // @2_54f250
  { u32 v = (u32)((u32)(7)); __builtin_memcpy((void *)(u32)(ecx + 76), &v, sizeof v); }  // @3_54f250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_54f250
  p0_ = eax;  // @5_54f250
  p1_ = esi;  // @6_54f250
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(p1_), (u32)(7069552), (u32)(2147483649), (u32)(0), (u32)(0), (u32)(p0_), (u32)(72));  // @7_54f250
  ecx = edx = 0;  // @8_54f250
  if ((s32)(eax & eax) >= 0) goto L54f2a0;  // @9_54f250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_54f250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_54f250
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6963560), (u32)(372));  // @12_54f250
  ecx = edx = 0;  // @13_54f250
  p2_ = eax;  // @14_54f250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_54f250
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p2_), (u32)(6963936));  // @16_54f250
  ecx = edx = 0;  // @17_54f250
  L54f2a0:;
  return eax;  // @19_54f250
}
PCREG(54f250, lifted_54f250);

extern "C" u32 THISCALL lifted_6385c0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_6385c0
  edx = (u32)(7493652);  // @1_6385c0
  if ((esi & esi) == 0) goto L6385fc;  // @2_6385c0
  L6385d0:;
  eax = esi;  // @4_6385c0
  eax = (u32)((s32)eax >> (u32)(24));  // @5_6385c0
  if ((s32)(eax & 0xff) < (s32)(u32)(97)) goto L6385dd;  // @6_6385c0
  if ((s32)(eax & 0xff) <= (s32)(u32)(122)) goto L6385ed;  // @7_6385c0
  L6385dd:;
  if ((s32)(eax & 0xff) < (s32)(u32)(65)) goto L6385e5;  // @9_6385c0
  if ((s32)(eax & 0xff) <= (s32)(u32)(90)) goto L6385ed;  // @10_6385c0
  L6385e5:;
  ecx = (u32)(eax - 48);  // @12_6385c0
  if ((ecx & 0xff) > (u32)(9)) goto L6385f1;  // @13_6385c0
  L6385ed:;
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @15_6385c0
  goto L6385f4;  // @16_6385c0
  L6385f1:;
  { u8 v = (u8)((u32)(46)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @18_6385c0
  L6385f4:;
  esi = (esi << (u32)(8));  // @20_6385c0
  edx = (edx + 1);  // @21_6385c0
  if ((esi & esi) != 0) goto L6385d0;  // @22_6385c0
  L6385fc:;
  eax = (u32)(7493652);  // @24_6385c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @25_6385c0
  return eax;  // @26_6385c0
}
PCREG(6385c0, lifted_6385c0);

extern "C" u32 THISCALL lifted_591b20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_591b20
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @1_591b20
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1047), sizeof v); (u32)v; }) & (u32)(33554432)) == 0) goto L591b3e;  // @2_591b20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @3_591b20
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @4_591b20
  L591b3e:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1628), sizeof v); (u32)v; })) & 0xff);  // @6_591b20
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 1628), &v, sizeof v); }  // @7_591b20
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L591ba2;  // @8_591b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_591b20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @10_591b20
  ecx = edx = 0;  // @11_591b20
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1624), sizeof v); (u32)v; })) goto L591b62;  // @12_591b20
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L591b88;  // @13_591b20
  L591b62:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1624), &v, sizeof v); }  // @15_591b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @16_591b20
  if ((eax & eax) == 0) goto L591b88;  // @17_591b20
  p0_ = eax;  // @18_591b20
  ecx = (u32)(esi + 2395);  // @19_591b20
  eax = ext_5aeff0_thiscall2(ecx, (u32)(p0_));  // @20_591b20
  ecx = edx = 0;  // @21_591b20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @22_591b20
  L591b88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_591b20
  ecx = esi;  // @25_591b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @26_591b20
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @27_591b20
  ecx = edx = 0;  // @28_591b20
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L591ba2;  // @29_591b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1620), &v, sizeof v); }  // @30_591b20
  L591ba2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1620), sizeof v); (u32)v; });  // @32_591b20
  return eax;  // @33_591b20
}
PCREG(591b20, lifted_591b20);

extern "C" u32 THISCALL lifted_648350(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_648350
  ebx = (u32)(65535);  // @1_648350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @2_648350
  if ((ecx & ecx) == 0) goto L648378;  // @3_648350
  L648361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_648350
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) != (ebx & 0xffff)) goto L648389;  // @6_648350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_648350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_648350
  if (ecx == eax) goto L648378;  // @9_648350
  if ((eax & eax) != 0) goto L648361;  // @10_648350
  L648378:;
  ecx = esi;  // @12_648350
  eax = ext_648dd0_thiscall1(ecx);  // @13_648350
  ecx = edx = 0;  // @14_648350
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L64839f;  // @15_648350
  eax = 0;  // @16_648350
  return eax;  // @17_648350
  L648389:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_648350
  edi = eax;  // @20_648350
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @21_648350
  if ((eax & 0xffff) != (ebx & 0xffff)) goto L6483b6;  // @22_648350
  esi = 0;  // @23_648350
  eax = esi;  // @24_648350
  return eax;  // @25_648350
  L64839f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @27_648350
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @28_648350
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; });  // @29_648350
  if ((eax & 0xffff) != (ebx & 0xffff)) goto L6483b6;  // @30_648350
  esi = 0;  // @31_648350
  eax = esi;  // @32_648350
  return eax;  // @33_648350
  L6483b6:;
  eax = (u32)(eax + eax*8);  // @35_648350
  eax = (u32)(eax + 4);  // @36_648350
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; })) & 0xffff);  // @37_648350
  esi = (u32)(edi + eax*4);  // @38_648350
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 2), &v, sizeof v); }  // @39_648350
  ecx = esi;  // @40_648350
  eax = ext_647f70_thiscall1(ecx);  // @41_648350
  ecx = edx = 0;  // @42_648350
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_648350
  eax = esi;  // @44_648350
  return eax;  // @45_648350
}
PCREG(648350, lifted_648350);

extern "C" u32 STDCALL lifted_663200(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_663200
  eax = (eax - (u32)(1));  // @1_663200
  if (eax == 0) goto L66323c;  // @2_663200
  eax = (eax - (u32)(4));  // @3_663200
  if (eax == 0) goto L663230;  // @4_663200
  eax = (eax - (u32)(3));  // @5_663200
  if (eax == 0) goto L663224;  // @6_663200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_663200
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_663200
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @9_663200
  return eax;  // @10_663200
  L663224:;
  eax = ext_663770_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @12_663200
  ecx = edx = 0;  // @13_663200
  return eax;  // @14_663200
  L663230:;
  eax = ext_6638c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @16_663200
  ecx = edx = 0;  // @17_663200
  return eax;  // @18_663200
  L66323c:;
  eax = ext_663610_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @20_663200
  ecx = edx = 0;  // @21_663200
  return eax;  // @22_663200
}
PCREG(663200, lifted_663200);

extern "C" u32 THISCALL lifted_662750(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 13), &v, sizeof v); }  // @0_662750
  edx = (u32)(ecx + 13);  // @1_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 17), &v, sizeof v); }  // @2_662750
  eax = (u32)(ecx + 17);  // @3_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @4_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @5_662750
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_ESI, 4);  // @6_662750
  esi = (u32)(EBP - 4);  // @7_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @8_662750
  if (edx == esi) goto L66278d;  // @9_662750
  { u32 v = (u32)((u32)(4294966272)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @10_662750
  L66278d:;
  edx = (u32)(EBP - 8);  // @12_662750
  if (eax == edx) goto L66279a;  // @13_662750
  { u32 v = (u32)((u32)(2048)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @14_662750
  L66279a:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ecx + 21), &v, sizeof v); }  // @16_662750
  eax = ecx;  // @17_662750
  { u32 v = (u32)((u32)(981668463)); __builtin_memcpy((void *)(u32)(ecx + 25), &v, sizeof v); }  // @18_662750
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @19_662750
  return eax;  // @20_662750
}
PCREG(662750, lifted_662750);

extern "C" u32 lifted_45c4b0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_45c4b0
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_45c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_45c4b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @3_45c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45c4b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 16)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(0));  // @5_45c4b0
  ecx = edx = 0;  // @6_45c4b0
  esi = eax;  // @7_45c4b0
  if ((esi & esi) != 0) goto L45c4e5;  // @8_45c4b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @9_45c4b0
  if ((eax & eax) == 0) goto L45c4e2;  // @10_45c4b0
  eax = ((u32(STDCALL *)(void))(eax))();  // @11_45c4b0
  ecx = edx = 0;  // @12_45c4b0
  eax = esi;  // @13_45c4b0
  return eax;  // @14_45c4b0
  L45c4e2:;
  __builtin_trap();  // @16_45c4b0
  L45c4e5:;
  return eax;  // @18_45c4b0
}
PCREG(45c4b0, lifted_45c4b0);

extern "C" u32 lifted_634a58(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = (u32)(7161140);  // @0_634a58
  ebx = (u32)(7161140);  // @1_634a58
  if (esi >= ebx) goto L634a80;  // @2_634a58
  L634a69:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_634a58
  if ((edi & edi) == 0) goto L634a78;  // @5_634a58
  ecx = edi;  // @6_634a58
  eax = ext_634aae_cdecl0();  // @7_634a58
  ecx = edx = 0;  // @8_634a58
  eax = ((u32(STDCALL *)(void))(edi))();  // @9_634a58
  ecx = edx = 0;  // @10_634a58
  L634a78:;
  esi = (esi + (u32)(4));  // @12_634a58
  if (esi < ebx) goto L634a69;  // @13_634a58
  L634a80:;
  return eax;  // @15_634a58
}
PCREG(634a58, lifted_634a58);

extern "C" u32 STDCALL lifted_634a17(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_634a17
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1_634a17
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(3765269347)) goto L634a4c;  // @2_634a17
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }) != (u32)(3)) goto L634a4c;  // @3_634a17
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @4_634a17
  if (eax == (u32)(429065504)) goto L634a52;  // @5_634a17
  if (eax == (u32)(429065505)) goto L634a52;  // @6_634a17
  if (eax == (u32)(429065506)) goto L634a52;  // @7_634a17
  if (eax == (u32)(26820608)) goto L634a52;  // @8_634a17
  L634a4c:;
  eax = 0;  // @10_634a17
  return eax;  // @11_634a17
  L634a52:;
  eax = ext_634e84_cdecl0();  // @13_634a17
  ecx = edx = 0;  // @14_634a17
}
PCREG(634a17, lifted_634a17);

extern "C" u32 lifted_6331d0(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6331d0
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_EBX, 4);  // @1_6331d0
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_ESI, 4);  // @2_6331d0
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EDI, 4);  // @3_6331d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @5_6331d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @6_6331d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @7_6331d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @8_6331d0
  if (esi <= ebx) goto L6331f2;  // @9_6331d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @10_6331d0
  L6331f2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @12_6331d0
  ebx = (ebx - esi);  // @13_6331d0
  if (ebx > ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; })) ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @14_6331d0
  if ((ebx & ebx) == 0) goto L633210;  // @15_6331d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @16_6331d0
  if (edx == (u32)(-5)) edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @17_6331d0
  L633210:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }) - ebx)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @19_6331d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; }) + ebx)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @20_6331d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 56), sizeof v); (u32)v; });  // @21_6331d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @22_6331d0
  if ((eax & eax) == 0) goto L633233;  // @23_6331d0
  p0_ = ebx;  // @24_6331d0
  p1_ = esi;  // @25_6331d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @26_6331d0
  ecx = edx = 0;  // @27_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @28_6331d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @29_6331d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 48), &v, sizeof v); }  // @30_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @31_6331d0
  L633233:;
  p2_ = ebx;  // @33_6331d0
  p3_ = esi;  // @34_6331d0
  p4_ = ecx;  // @35_6331d0
  eax = ext_634d22_cdecl3((u32)(p4_), (u32)(p3_), (u32)(p2_));  // @36_6331d0
  ecx = edx = 0;  // @37_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @38_6331d0
  esi = (esi + ebx);  // @39_6331d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @40_6331d0
  ecx = (ecx + ebx);  // @41_6331d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @42_6331d0
  if (esi != eax) goto L6332b9;  // @43_6331d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @44_6331d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; }) != eax) goto L63325a;  // @45_6331d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @46_6331d0
  L63325a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @48_6331d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @49_6331d0
  ebx = (ebx - esi);  // @50_6331d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @51_6331d0
  if (ebx > edx) ebx = edx;  // @52_6331d0
  if ((ebx & ebx) == 0) goto L633285;  // @53_6331d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @54_6331d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @55_6331d0
  if (edx == (u32)(-5)) edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @56_6331d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @57_6331d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @58_6331d0
  L633285:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; }) + ebx)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @60_6331d0
  edx = (edx - ebx);  // @61_6331d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @62_6331d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 56), sizeof v); (u32)v; });  // @63_6331d0
  if ((eax & eax) == 0) goto L6332a7;  // @64_6331d0
  p5_ = ebx;  // @65_6331d0
  p6_ = esi;  // @66_6331d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; }), (u32)(p6_), (u32)(p5_));  // @67_6331d0
  ecx = edx = 0;  // @68_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @69_6331d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 60), &v, sizeof v); }  // @70_6331d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 48), &v, sizeof v); }  // @71_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @72_6331d0
  L6332a7:;
  p7_ = ebx;  // @74_6331d0
  p8_ = esi;  // @75_6331d0
  p9_ = ecx;  // @76_6331d0
  eax = ext_634d22_cdecl3((u32)(p9_), (u32)(p8_), (u32)(p7_));  // @77_6331d0
  ecx = edx = 0;  // @78_6331d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @79_6331d0
  ecx = (ecx + ebx);  // @80_6331d0
  esi = (esi + ebx);  // @81_6331d0
  L6332b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @83_6331d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @84_6331d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @85_6331d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @86_6331d0
  return eax;  // @87_6331d0
}
PCREG(6331d0, lifted_6331d0);

extern "C" u32 lifted_66a2a8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a2a8
  ecx = (ecx + (u32)(1197));  // @1_66a2a8
  eax = ext_4690b0_cdecl0();  // @2_66a2a8
  ecx = edx = 0;  // @3_66a2a8
  return eax;  // @4_66a2a8
}
PCREG(66a2a8, lifted_66a2a8);

extern "C" u32 lifted_66a530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a530
  ecx = (ecx + (u32)(61));  // @1_66a530
  eax = ext_4690b0_cdecl0();  // @2_66a530
  ecx = edx = 0;  // @3_66a530
  return eax;  // @4_66a530
}
PCREG(66a530, lifted_66a530);

extern "C" u32 lifted_66a560(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @0_66a560
  ecx = (ecx + (u32)(61));  // @1_66a560
  eax = ext_4690b0_cdecl0();  // @2_66a560
  ecx = edx = 0;  // @3_66a560
  return eax;  // @4_66a560
}
PCREG(66a560, lifted_66a560);

extern "C" u32 lifted_663f1d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 928), sizeof v); (u32)v; });  // @0_663f1d
  p0_ = eax;  // @1_663f1d
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(4116));  // @2_663f1d
  ecx = edx = 0;  // @3_663f1d
  return eax;  // @4_663f1d
}
PCREG(663f1d, lifted_663f1d);

extern "C" u32 lifted_663f32(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 928), sizeof v); (u32)v; });  // @0_663f32
  p0_ = eax;  // @1_663f32
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(52));  // @2_663f32
  ecx = edx = 0;  // @3_663f32
  return eax;  // @4_663f32
}
PCREG(663f32, lifted_663f32);

extern "C" u32 lifted_66445b(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 660), sizeof v); (u32)v; });  // @0_66445b
  p0_ = eax;  // @1_66445b
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(21646));  // @2_66445b
  ecx = edx = 0;  // @3_66445b
  return eax;  // @4_66445b
}
PCREG(66445b, lifted_66445b);

extern "C" u32 lifted_664580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4116), sizeof v); (u32)v; });  // @0_664580
  p0_ = eax;  // @1_664580
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(28));  // @2_664580
  ecx = edx = 0;  // @3_664580
  return eax;  // @4_664580
}
PCREG(664580, lifted_664580);

extern "C" u32 lifted_6679e8(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8736), sizeof v); (u32)v; });  // @0_6679e8
  p0_ = eax;  // @1_6679e8
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(264));  // @2_6679e8
  ecx = edx = 0;  // @3_6679e8
  return eax;  // @4_6679e8
}
PCREG(6679e8, lifted_6679e8);

extern "C" u32 lifted_66adb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @0_66adb0
  p0_ = eax;  // @1_66adb0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(80));  // @2_66adb0
  ecx = edx = 0;  // @3_66adb0
  return eax;  // @4_66adb0
}
PCREG(66adb0, lifted_66adb0);

extern "C" u32 lifted_66e270(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1152), sizeof v); (u32)v; });  // @0_66e270
  p0_ = eax;  // @1_66e270
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(139628));  // @2_66e270
  ecx = edx = 0;  // @3_66e270
  return eax;  // @4_66e270
}
PCREG(66e270, lifted_66e270);

extern "C" u32 THISCALL lifted_4496d0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1_4496d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 568)))(ecx);  // @2_4496d0
  ecx = edx = 0;  // @3_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @5_4496d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @6_4496d0
  eax = (u32)(EBP - 56);  // @7_4496d0
  p0_ = eax;  // @8_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @9_4496d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4496d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 132)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }), (u32)(p0_));  // @11_4496d0
  ecx = edx = 0;  // @12_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @13_4496d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @14_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @16_4496d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @17_4496d0
  eax = (u32)(EBP - 56);  // @18_4496d0
  p1_ = eax;  // @19_4496d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_4496d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_4496d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 160)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }), (u32)(p1_));  // @22_4496d0
  ecx = edx = 0;  // @23_4496d0
  return eax;  // @24_4496d0
}
PCREG(4496d0, lifted_4496d0);

extern "C" u32 THISCALL lifted_534e00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_534e00
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_534e00
  esi = ecx;  // @2_534e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_534e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_534e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @5_534e00
  ecx = edx = 0;  // @6_534e00
  ecx = eax;  // @7_534e00
  if ((ecx & ecx) != 0) goto L534e49;  // @8_534e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_534e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_534e00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6954540), (u32)(1317));  // @11_534e00
  ecx = edx = 0;  // @12_534e00
  p0_ = eax;  // @13_534e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_534e00
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6955192));  // @15_534e00
  ecx = edx = 0;  // @16_534e00
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @17_534e00
  return eax;  // @18_534e00
  L534e49:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_534e00
  p1_ = ecx;  // @21_534e00
  ecx = esi;  // @22_534e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @23_534e00
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(p1_));  // @24_534e00
  ecx = edx = 0;  // @25_534e00
  return eax;  // @26_534e00
}
PCREG(534e00, lifted_534e00);

extern "C" u32 THISCALL lifted_4d5310(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edi = (u32)(ecx + 4);  // @0_4d5310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }) != edi) goto L4d534c;  // @1_4d5310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @2_4d5310
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @3_4d5310
  esi = (esi - edx);  // @4_4d5310
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) < esi) esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_4d5310
  if ((esi & esi) == 0) goto L4d5344;  // @6_4d5310
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_4d5310
  p0_ = esi;  // @8_4d5310
  ecx = (ecx + edx);  // @9_4d5310
  p1_ = ecx;  // @10_4d5310
  eax = ext_634d22_cdecl3(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(p1_), (u32)(p0_));  // @11_4d5310
  ecx = edx = 0;  // @12_4d5310
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @13_4d5310
  L4d5344:;
  eax = esi;  // @15_4d5310
  return eax;  // @16_4d5310
  L4d534c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_4d5310
  if ((eax & eax) == 0) goto L4d535c;  // @19_4d5310
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_4d5310
  ecx = edx = 0;  // @21_4d5310
  return eax;  // @22_4d5310
  L4d535c:;
  __builtin_trap();  // @24_4d5310
}
PCREG(4d5310, lifted_4d5310);

extern "C" u32 THISCALL lifted_4cd0e0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd0e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_ESI, 4);  // @0_4cd0e0
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EDI, 4);  // @1_4cd0e0
  esi = ecx;  // @2_4cd0e0
  { u32 v = (u32)((u32)(6904480)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @3_4cd0e0
  eax = ext_4cdcc0_thiscall1(ecx);  // @4_4cd0e0
  ecx = edx = 0;  // @5_4cd0e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @6_4cd0e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @7_4cd0e0
  reg.state = (s32)((u32)(0));  // @8_4cd0e0
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_4cd0e0
  if ((edi & edi) == 0) goto L4cd13f;  // @10_4cd0e0
  L4cd130:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_4cd0e0
  ecx = esi;  // @13_4cd0e0
  p0_ = edi;  // @14_4cd0e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @15_4cd0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(p0_));  // @16_4cd0e0
  ecx = edx = 0;  // @17_4cd0e0
  if ((edi & edi) != 0) goto L4cd130;  // @18_4cd0e0
  L4cd13f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @20_4cd0e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @21_4cd0e0
  SEH_LEAVE();  // @22_4cd0e0
  return eax;  // @23_4cd0e0
}
PCREG(4cd0e0, lifted_4cd0e0);

extern "C" u32 THISCALL lifted_6012e0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_6012e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EBX, 4);  // @0_6012e0
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @1_6012e0
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EDI, 4);  // @2_6012e0
  esi = ecx;  // @3_6012e0
  { u32 v = (u32)((u32)(7046360)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_6012e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L601358;  // @5_6012e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @6_6012e0
  L601317:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @8_6012e0
  if ((ecx & ecx) == 0) goto L60132a;  // @9_6012e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @10_6012e0
  ecx = (ecx - 1);  // @11_6012e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @12_6012e0
  ebx = (u32)(eax + ecx*4);  // @13_6012e0
  goto L60133a;  // @14_6012e0
  L60132a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @16_6012e0
  if ((eax & eax) == 0) goto L601337;  // @17_6012e0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @18_6012e0
  ecx = edx = 0;  // @19_6012e0
  goto L60133a;  // @20_6012e0
  L601337:;
  __builtin_trap();  // @22_6012e0
  L60133a:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_6012e0
  if ((edi & edi) == 0) goto L601352;  // @25_6012e0
  ecx = edi;  // @26_6012e0
  eax = ext_601380_thiscall1(ecx);  // @27_6012e0
  ecx = edx = 0;  // @28_6012e0
  p0_ = edi;  // @29_6012e0
  eax = ext_634273_cdecl2((u32)(p0_), (u32)(4));  // @30_6012e0
  ecx = edx = 0;  // @31_6012e0
  L601352:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L601317;  // @33_6012e0
  L601358:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @35_6012e0
  ecx = edx = 0;  // @36_6012e0
  { u32 v = (u32)((u32)(7046312)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @37_6012e0
  SEH_LEAVE();  // @38_6012e0
  return eax;  // @39_6012e0
}
PCREG(6012e0, lifted_6012e0);

extern "C" u32 THISCALL lifted_4ccc30(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x669258);  // @h_4ccc30
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_ESI, 4);  // @0_4ccc30
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_EDI, 4);  // @1_4ccc30
  esi = ecx;  // @2_4ccc30
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_4ccc30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_4ccc30
  edi = (u32)(1);  // @5_4ccc30
  edx = edi;  // @6_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @7_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @8_4ccc30
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) >= (s32)edx) edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_4ccc30
  ecx = (ecx + (u32)(2));  // @10_4ccc30
  eax = edx;  // @11_4ccc30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @12_4ccc30
  eax = (u32)((s32)eax * (s32)ecx);  // @13_4ccc30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @14_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @15_4ccc30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @16_4ccc30
  reg.state = (s32)((u32)(0));  // @17_4ccc30
  { u32 v = (u32)((u32)(6903876)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @18_4ccc30
  eax = ext_41e290_cdecl1((u32)(28));  // @19_4ccc30
  ecx = edx = 0;  // @20_4ccc30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @21_4ccc30
  if ((eax & eax) == 0) goto L4ccce6;  // @22_4ccc30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @23_4ccc30
  ecx = (ecx & (u32)(2147483647));  // @24_4ccc30
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 20), &v, sizeof v); }  // @26_4ccc30
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @27_4ccc30
  if (ecx < edi) ecx = edi;  // @28_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @29_4ccc30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @30_4ccc30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @31_4ccc30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @32_4ccc30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @33_4ccc30
  goto L4ccced;  // @34_4ccc30
  L4ccce6:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @36_4ccc30
  L4ccced:;
  eax = esi;  // @38_4ccc30
  SEH_LEAVE();  // @39_4ccc30
  return eax;  // @40_4ccc30
}
PCREG(4ccc30, lifted_4ccc30);

extern "C" u32 THISCALL lifted_5f97e0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_5f97e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EBX, 4);  // @0_5f97e0
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @1_5f97e0
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EDI, 4);  // @2_5f97e0
  edi = ecx;  // @3_5f97e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L5f9871;  // @4_5f97e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @5_5f97e0
  L5f9811:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @7_5f97e0
  if ((ecx & ecx) == 0) goto L5f9824;  // @8_5f97e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @9_5f97e0
  ecx = (ecx - 1);  // @10_5f97e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @11_5f97e0
  ebx = (u32)(eax + ecx*4);  // @12_5f97e0
  goto L5f9834;  // @13_5f97e0
  L5f9824:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_5f97e0
  if ((eax & eax) == 0) goto L5f9831;  // @16_5f97e0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @17_5f97e0
  ecx = edx = 0;  // @18_5f97e0
  goto L5f9834;  // @19_5f97e0
  L5f9831:;
  __builtin_trap();  // @21_5f97e0
  L5f9834:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @23_5f97e0
  if ((esi & esi) == 0) goto L5f986b;  // @24_5f97e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_5f97e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @26_5f97e0
  eax = (eax - ecx);  // @27_5f97e0
  reg.state = (s32)((u32)(0));  // @28_5f97e0
  if ((ecx & ecx) == 0) goto L5f9859;  // @29_5f97e0
  if ((eax & eax) == 0) goto L5f9859;  // @30_5f97e0
  p0_ = eax;  // @31_5f97e0
  p1_ = ecx;  // @32_5f97e0
  ecx = esi;  // @33_5f97e0
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @34_5f97e0
  ecx = edx = 0;  // @35_5f97e0
  L5f9859:;
  p2_ = esi;  // @37_5f97e0
  reg.state = (s32)((u32)(4294967295));  // @38_5f97e0
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(12));  // @39_5f97e0
  ecx = edx = 0;  // @40_5f97e0
  L5f986b:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; }) != (u32)(0)) goto L5f9811;  // @42_5f97e0
  L5f9871:;
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }));  // @44_5f97e0
  ecx = edx = 0;  // @45_5f97e0
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @46_5f97e0
  ecx = edx = 0;  // @47_5f97e0
  SEH_LEAVE();  // @48_5f97e0
  return eax;  // @49_5f97e0
}
PCREG(5f97e0, lifted_5f97e0);

extern "C" u32 THISCALL lifted_601380(u32 ecx_in) {
  SEH_ENTER(0x66d8d2);  // @h_601380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_ESI, 4);  // @0_601380
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EDI, 4);  // @1_601380
  edi = ecx;  // @2_601380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_601380
  eax = (eax - (u32)(2));  // @5_601380
  if (eax == 0) goto L6013c4;  // @6_601380
  eax = (eax - (u32)(1));  // @7_601380
  if (eax != 0) goto L6013fc;  // @8_601380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @9_601380
  if ((esi & esi) == 0) goto L6013fc;  // @10_601380
  reg.state = (s32)((u32)(1));  // @11_601380
  goto L6013d2;  // @12_601380
  L6013c4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @14_601380
  if ((esi & esi) == 0) goto L6013fc;  // @15_601380
  reg.state = (s32)((u32)(0));  // @16_601380
  L6013d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @19_601380
  eax = (eax - ecx);  // @20_601380
  if ((ecx & ecx) == 0) goto L6013ea;  // @21_601380
  if ((eax & eax) == 0) goto L6013ea;  // @22_601380
  p0_ = eax;  // @23_601380
  p1_ = ecx;  // @24_601380
  ecx = esi;  // @25_601380
  eax = ext_54f870_stdcall2((u32)(p1_), (u32)(p0_));  // @26_601380
  ecx = edx = 0;  // @27_601380
  L6013ea:;
  p2_ = esi;  // @29_601380
  reg.state = (s32)((u32)(4294967295));  // @30_601380
  eax = ext_634273_cdecl2((u32)(p2_), (u32)(12));  // @31_601380
  ecx = edx = 0;  // @32_601380
  L6013fc:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_601380
  if ((esi & esi) == 0) goto L60142d;  // @35_601380
  ecx = (u32)(esi + 12);  // @36_601380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_601380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @38_601380
  eax = (eax - edx);  // @39_601380
  reg.state = (s32)((u32)(2));  // @40_601380
  if ((edx & edx) == 0) goto L601422;  // @41_601380
  if ((eax & eax) == 0) goto L601422;  // @42_601380
  p3_ = eax;  // @43_601380
  p4_ = edx;  // @44_601380
  eax = ext_54f870_stdcall2((u32)(p4_), (u32)(p3_));  // @45_601380
  ecx = edx = 0;  // @46_601380
  L601422:;
  p5_ = esi;  // @48_601380
  eax = ext_634273_cdecl2((u32)(p5_), (u32)(24));  // @49_601380
  ecx = edx = 0;  // @50_601380
  L60142d:;
  SEH_LEAVE();  // @52_601380
  return eax;  // @53_601380
}
PCREG(601380, lifted_601380);

extern "C" u32 THISCALL lifted_4b1ca0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4b1ca0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @0_4b1ca0
  esi = ecx;  // @1_4b1ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_4b1ca0
  eax = ext_469870_thiscall1(ecx);  // @3_4b1ca0
  ecx = edx = 0;  // @4_4b1ca0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @5_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @6_4b1ca0
  eax = (u32)(esi + 100);  // @7_4b1ca0
  { u32 v = (u32)((u32)(6889016)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @9_4b1ca0
  ecx = 0;  // @10_4b1ca0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @11_4b1ca0
  ecx = (u32)(EBP - 20);  // @12_4b1ca0
  reg.state = (s32)((u32)(0));  // @13_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @14_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @15_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @16_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @17_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @18_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @19_4b1ca0
  if (eax == ecx) goto L4b1d2e;  // @20_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @21_4b1ca0
  L4b1d2e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @23_4b1ca0
  { u32 v = (u32)((u32)(65792)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @24_4b1ca0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 388), &v, sizeof v); }  // @25_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @26_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @27_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6889180), (u32)(3378));  // @31_4b1ca0
  ecx = edx = 0;  // @32_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @33_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6889180), (u32)(3379));  // @37_4b1ca0
  ecx = edx = 0;  // @38_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @39_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840116), (u32)(0), (u32)(6889180), (u32)(3380));  // @43_4b1ca0
  ecx = edx = 0;  // @44_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @45_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @47_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889320), (u32)(0), (u32)(6889180), (u32)(3381));  // @49_4b1ca0
  ecx = edx = 0;  // @50_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @51_4b1ca0
  eax = (u32)(esi + 128);  // @52_4b1ca0
  p0_ = eax;  // @53_4b1ca0
  eax = ext_634d10_cdecl3((u32)(p0_), (u32)(0), (u32)(256));  // @54_4b1ca0
  ecx = edx = 0;  // @55_4b1ca0
  eax = esi;  // @56_4b1ca0
  SEH_LEAVE();  // @57_4b1ca0
  return eax;  // @58_4b1ca0
}
PCREG(4b1ca0, lifted_4b1ca0);

extern "C" u32 THISCALL lifted_5b6e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c39e);  // @h_5b6e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy((void *)(u32)(EBP - 52), &SENT_EBX, 4);  // @0_5b6e20
  __builtin_memcpy((void *)(u32)(EBP - 56), &SENT_ESI, 4);  // @1_5b6e20
  __builtin_memcpy((void *)(u32)(EBP - 60), &SENT_EDI, 4);  // @2_5b6e20
  ebx = ecx;  // @3_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @4_5b6e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @5_5b6e20
  eax = ext_5b6d00_thiscall1(ecx);  // @6_5b6e20
  ecx = edx = 0;  // @7_5b6e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_5b6e20
  ecx = (u32)(EBP - 24);  // @9_5b6e20
  p0_ = ecx;  // @10_5b6e20
  ecx = esi;  // @11_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p0_), (u32)(4));  // @13_5b6e20
  ecx = edx = 0;  // @14_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @15_5b6e20
  if ((eax & eax) == 0) goto L5b7078;  // @16_5b6e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @17_5b6e20
  if ((s32)(eax & eax) <= 0) goto L5b7078;  // @18_5b6e20
  L5b6e80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_5b6e20
  ecx = (u32)(EBP - 28);  // @21_5b6e20
  p1_ = ecx;  // @22_5b6e20
  ecx = esi;  // @23_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p1_), (u32)(4));  // @24_5b6e20
  ecx = edx = 0;  // @25_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @26_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @28_5b6e20
  ecx = edx = 0;  // @29_5b6e20
  edi = eax;  // @30_5b6e20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @32_5b6e20
  ecx = edx = 0;  // @33_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @34_5b6e20
  reg.state = (s32)((u32)(0));  // @35_5b6e20
  if ((eax & eax) == 0) goto L5b6ec2;  // @36_5b6e20
  ecx = eax;  // @37_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(29));  // @38_5b6e20
  ecx = edx = 0;  // @39_5b6e20
  goto L5b6ec4;  // @40_5b6e20
  L5b6ec2:;
  eax = 0;  // @42_5b6e20
  L5b6ec4:;
  reg.state = (s32)((u32)(4294967295));  // @44_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @45_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @46_5b6e20
  ecx = edx = 0;  // @47_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @48_5b6e20
  reg.state = (s32)((u32)(1));  // @49_5b6e20
  if ((eax & eax) == 0) goto L5b6ef2;  // @50_5b6e20
  ecx = eax;  // @51_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(32));  // @52_5b6e20
  ecx = edx = 0;  // @53_5b6e20
  goto L5b6ef4;  // @54_5b6e20
  L5b6ef2:;
  eax = 0;  // @56_5b6e20
  L5b6ef4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @58_5b6e20
  ecx = esi;  // @59_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5b6e20
  eax = (u32)(edi + 56);  // @61_5b6e20
  p2_ = eax;  // @62_5b6e20
  reg.state = (s32)((u32)(4294967295));  // @63_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p2_), (u32)(4));  // @64_5b6e20
  ecx = edx = 0;  // @65_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_5b6e20
  eax = (u32)(edi + 96);  // @67_5b6e20
  p3_ = eax;  // @68_5b6e20
  ecx = esi;  // @69_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p3_), (u32)(36));  // @70_5b6e20
  ecx = edx = 0;  // @71_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_5b6e20
  eax = (u32)(edi + 72);  // @73_5b6e20
  p4_ = eax;  // @74_5b6e20
  ecx = esi;  // @75_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p4_), (u32)(12));  // @76_5b6e20
  ecx = edx = 0;  // @77_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_5b6e20
  eax = (u32)(edi + 84);  // @79_5b6e20
  p5_ = eax;  // @80_5b6e20
  ecx = esi;  // @81_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p5_), (u32)(12));  // @82_5b6e20
  ecx = edx = 0;  // @83_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_5b6e20
  eax = (u32)(edi + 60);  // @85_5b6e20
  p6_ = eax;  // @86_5b6e20
  ecx = esi;  // @87_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p6_), (u32)(12));  // @88_5b6e20
  ecx = edx = 0;  // @89_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_5b6e20
  eax = (u32)(edi + 8);  // @91_5b6e20
  p7_ = eax;  // @92_5b6e20
  ecx = esi;  // @93_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p7_), (u32)(48));  // @94_5b6e20
  ecx = edx = 0;  // @95_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_5b6e20
  eax = (u32)(edi + 132);  // @97_5b6e20
  p8_ = eax;  // @98_5b6e20
  ecx = esi;  // @99_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p8_), (u32)(4));  // @100_5b6e20
  ecx = edx = 0;  // @101_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @102_5b6e20
  eax = (u32)(edi + 136);  // @103_5b6e20
  p9_ = eax;  // @104_5b6e20
  ecx = esi;  // @105_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p9_), (u32)(4));  // @106_5b6e20
  ecx = edx = 0;  // @107_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5b6e20
  eax = (u32)(edi + 140);  // @109_5b6e20
  p10_ = eax;  // @110_5b6e20
  ecx = esi;  // @111_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p10_), (u32)(1));  // @112_5b6e20
  ecx = edx = 0;  // @113_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @114_5b6e20
  ecx = (u32)(EBP + 8);  // @115_5b6e20
  p11_ = ecx;  // @116_5b6e20
  ecx = esi;  // @117_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p11_), (u32)(4));  // @118_5b6e20
  ecx = edx = 0;  // @119_5b6e20
  ebx = 0;  // @120_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b6ffd;  // @121_5b6e20
  L5b6f90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @123_5b6e20
  ecx = (u32)(EBP - 32);  // @124_5b6e20
  p12_ = ecx;  // @125_5b6e20
  ecx = esi;  // @126_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p12_), (u32)(4));  // @127_5b6e20
  ecx = edx = 0;  // @128_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @129_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @131_5b6e20
  ecx = edx = 0;  // @132_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @133_5b6e20
  edi = eax;  // @134_5b6e20
  p13_ = edi;  // @135_5b6e20
  ecx = esi;  // @136_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p13_), (u32)(4));  // @137_5b6e20
  ecx = edx = 0;  // @138_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @139_5b6e20
  ecx = (u32)(edi + 4);  // @140_5b6e20
  p14_ = ecx;  // @141_5b6e20
  ecx = esi;  // @142_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p14_), (u32)(4));  // @143_5b6e20
  ecx = edx = 0;  // @144_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_5b6e20
  eax = (u32)(edi + 8);  // @146_5b6e20
  p15_ = eax;  // @147_5b6e20
  ecx = esi;  // @148_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p15_), (u32)(4));  // @149_5b6e20
  ecx = edx = 0;  // @150_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_5b6e20
  eax = (u32)(edi + 12);  // @152_5b6e20
  p16_ = eax;  // @153_5b6e20
  ecx = esi;  // @154_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p16_), (u32)(1));  // @155_5b6e20
  ecx = edx = 0;  // @156_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @157_5b6e20
  eax = (u32)(edi + 13);  // @158_5b6e20
  p17_ = eax;  // @159_5b6e20
  ecx = esi;  // @160_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p17_), (u32)(4));  // @161_5b6e20
  ecx = edx = 0;  // @162_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @163_5b6e20
  eax = (u32)(edi + 17);  // @164_5b6e20
  p18_ = eax;  // @165_5b6e20
  ecx = esi;  // @166_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p18_), (u32)(12));  // @167_5b6e20
  ecx = edx = 0;  // @168_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @169_5b6e20
  ebx = (ebx + 1);  // @170_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b6f90;  // @171_5b6e20
  L5b6ffd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_5b6e20
  ecx = (u32)(EBP + 8);  // @174_5b6e20
  p19_ = ecx;  // @175_5b6e20
  ecx = esi;  // @176_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p19_), (u32)(4));  // @177_5b6e20
  ecx = edx = 0;  // @178_5b6e20
  ebx = 0;  // @179_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b7065;  // @180_5b6e20
  L5b7011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @182_5b6e20
  ecx = (u32)(EBP - 36);  // @183_5b6e20
  p20_ = ecx;  // @184_5b6e20
  ecx = esi;  // @185_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(p20_), (u32)(4));  // @186_5b6e20
  ecx = edx = 0;  // @187_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @188_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @189_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @190_5b6e20
  ecx = edx = 0;  // @191_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @192_5b6e20
  edi = eax;  // @193_5b6e20
  p21_ = edi;  // @194_5b6e20
  ecx = esi;  // @195_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p21_), (u32)(12));  // @196_5b6e20
  ecx = edx = 0;  // @197_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @198_5b6e20
  ecx = (u32)(edi + 12);  // @199_5b6e20
  p22_ = ecx;  // @200_5b6e20
  ecx = esi;  // @201_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p22_), (u32)(12));  // @202_5b6e20
  ecx = edx = 0;  // @203_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @204_5b6e20
  eax = (u32)(edi + 28);  // @205_5b6e20
  p23_ = eax;  // @206_5b6e20
  ecx = esi;  // @207_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p23_), (u32)(4));  // @208_5b6e20
  ecx = edx = 0;  // @209_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @210_5b6e20
  eax = (u32)(edi + 24);  // @211_5b6e20
  p24_ = eax;  // @212_5b6e20
  ecx = esi;  // @213_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(p24_), (u32)(4));  // @214_5b6e20
  ecx = edx = 0;  // @215_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @216_5b6e20
  ebx = (ebx + 1);  // @217_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b7011;  // @218_5b6e20
  L5b7065:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @220_5b6e20
  ebx = (ebx + 1);  // @221_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @222_5b6e20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @223_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5b6e80;  // @224_5b6e20
  L5b7078:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @226_5b6e20
  SEH_LEAVE();  // @227_5b6e20
  return eax;  // @228_5b6e20
}
PCREG(5b6e20, lifted_5b6e20);

extern "C" u32 THISCALL lifted_519ea0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @0_519ea0
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_519ea0
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_519ea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_519ea0
  esi = ecx;  // @4_519ea0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @5_519ea0
  if (eax >= (u32)(50)) goto L519ed1;  // @6_519ea0
  { u32 v = (u32)((u32)(5348336)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @7_519ea0
  eax = (eax + 1);  // @8_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @9_519ea0
  goto L519eee;  // @10_519ea0
  L519ed1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @13_519ea0
  ecx = edx = 0;  // @14_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_519ea0
  if ((eax & eax) == 0) goto L519ee8;  // @16_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @17_519ea0
  ecx = edx = 0;  // @18_519ea0
  goto L519ee9;  // @19_519ea0
  L519ee8:;
  __builtin_trap();  // @21_519ea0
  L519ee9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @23_519ea0
  L519eee:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @25_519ea0
  if (eax >= (u32)(50)) goto L519f10;  // @26_519ea0
  { u32 v = (u32)((u32)(5347168)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @27_519ea0
  eax = (eax + 1);  // @28_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @29_519ea0
  goto L519f2f;  // @30_519ea0
  L519f10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_519ea0
  ecx = esi;  // @33_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @34_519ea0
  ecx = edx = 0;  // @35_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_519ea0
  if ((eax & eax) == 0) goto L519f29;  // @37_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_519ea0
  ecx = edx = 0;  // @39_519ea0
  goto L519f2a;  // @40_519ea0
  L519f29:;
  __builtin_trap();  // @42_519ea0
  L519f2a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @44_519ea0
  L519f2f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @46_519ea0
  if (eax >= (u32)(50)) goto L519f51;  // @47_519ea0
  { u32 v = (u32)((u32)(5346496)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @48_519ea0
  eax = (eax + 1);  // @49_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @50_519ea0
  goto L519f70;  // @51_519ea0
  L519f51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_519ea0
  ecx = esi;  // @54_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @55_519ea0
  ecx = edx = 0;  // @56_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_519ea0
  if ((eax & eax) == 0) goto L519f6a;  // @58_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_519ea0
  ecx = edx = 0;  // @60_519ea0
  goto L519f6b;  // @61_519ea0
  L519f6a:;
  __builtin_trap();  // @63_519ea0
  L519f6b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @65_519ea0
  L519f70:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @67_519ea0
  if (eax >= (u32)(50)) goto L519f92;  // @68_519ea0
  { u32 v = (u32)((u32)(5347296)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @69_519ea0
  eax = (eax + 1);  // @70_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @71_519ea0
  goto L519fb1;  // @72_519ea0
  L519f92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_519ea0
  ecx = esi;  // @75_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @76_519ea0
  ecx = edx = 0;  // @77_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @78_519ea0
  if ((eax & eax) == 0) goto L519fab;  // @79_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_519ea0
  ecx = edx = 0;  // @81_519ea0
  goto L519fac;  // @82_519ea0
  L519fab:;
  __builtin_trap();  // @84_519ea0
  L519fac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @86_519ea0
  L519fb1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @88_519ea0
  if (eax >= (u32)(50)) goto L519fd3;  // @89_519ea0
  { u32 v = (u32)((u32)(5346976)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @90_519ea0
  eax = (eax + 1);  // @91_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @92_519ea0
  goto L519ff2;  // @93_519ea0
  L519fd3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_519ea0
  ecx = esi;  // @96_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @97_519ea0
  ecx = edx = 0;  // @98_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @99_519ea0
  if ((eax & eax) == 0) goto L519fec;  // @100_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @101_519ea0
  ecx = edx = 0;  // @102_519ea0
  goto L519fed;  // @103_519ea0
  L519fec:;
  __builtin_trap();  // @105_519ea0
  L519fed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @107_519ea0
  L519ff2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @109_519ea0
  if (eax >= (u32)(50)) goto L51a014;  // @110_519ea0
  { u32 v = (u32)((u32)(5346928)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @111_519ea0
  eax = (eax + 1);  // @112_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @113_519ea0
  goto L51a033;  // @114_519ea0
  L51a014:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_519ea0
  ecx = esi;  // @117_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @118_519ea0
  ecx = edx = 0;  // @119_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @120_519ea0
  if ((eax & eax) == 0) goto L51a02d;  // @121_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @122_519ea0
  ecx = edx = 0;  // @123_519ea0
  goto L51a02e;  // @124_519ea0
  L51a02d:;
  __builtin_trap();  // @126_519ea0
  L51a02e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @128_519ea0
  L51a033:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @130_519ea0
  if (eax >= (u32)(50)) goto L51a055;  // @131_519ea0
  { u32 v = (u32)((u32)(5347504)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @132_519ea0
  eax = (eax + 1);  // @133_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @134_519ea0
  goto L51a074;  // @135_519ea0
  L51a055:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_519ea0
  ecx = esi;  // @138_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @139_519ea0
  ecx = edx = 0;  // @140_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @141_519ea0
  if ((eax & eax) == 0) goto L51a06e;  // @142_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @143_519ea0
  ecx = edx = 0;  // @144_519ea0
  goto L51a06f;  // @145_519ea0
  L51a06e:;
  __builtin_trap();  // @147_519ea0
  L51a06f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @149_519ea0
  L51a074:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @151_519ea0
  if (eax >= (u32)(50)) goto L51a096;  // @152_519ea0
  { u32 v = (u32)((u32)(5348864)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @153_519ea0
  eax = (eax + 1);  // @154_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @155_519ea0
  goto L51a0b5;  // @156_519ea0
  L51a096:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_519ea0
  ecx = esi;  // @159_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @160_519ea0
  ecx = edx = 0;  // @161_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @162_519ea0
  if ((eax & eax) == 0) goto L51a0af;  // @163_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @164_519ea0
  ecx = edx = 0;  // @165_519ea0
  goto L51a0b0;  // @166_519ea0
  L51a0af:;
  __builtin_trap();  // @168_519ea0
  L51a0b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @170_519ea0
  L51a0b5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @172_519ea0
  if (eax >= (u32)(50)) goto L51a0d7;  // @173_519ea0
  { u32 v = (u32)((u32)(5347424)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @174_519ea0
  eax = (eax + 1);  // @175_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @176_519ea0
  goto L51a0f6;  // @177_519ea0
  L51a0d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_519ea0
  ecx = esi;  // @180_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @181_519ea0
  ecx = edx = 0;  // @182_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @183_519ea0
  if ((eax & eax) == 0) goto L51a0f0;  // @184_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @185_519ea0
  ecx = edx = 0;  // @186_519ea0
  goto L51a0f1;  // @187_519ea0
  L51a0f0:;
  __builtin_trap();  // @189_519ea0
  L51a0f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @191_519ea0
  L51a0f6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @193_519ea0
  if (eax >= (u32)(50)) goto L51a118;  // @194_519ea0
  { u32 v = (u32)((u32)(5348592)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @195_519ea0
  eax = (eax + 1);  // @196_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @197_519ea0
  goto L51a137;  // @198_519ea0
  L51a118:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_519ea0
  ecx = esi;  // @201_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @202_519ea0
  ecx = edx = 0;  // @203_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_519ea0
  if ((eax & eax) == 0) goto L51a131;  // @205_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @206_519ea0
  ecx = edx = 0;  // @207_519ea0
  goto L51a132;  // @208_519ea0
  L51a131:;
  __builtin_trap();  // @210_519ea0
  L51a132:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @212_519ea0
  L51a137:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @214_519ea0
  if (eax >= (u32)(50)) goto L51a159;  // @215_519ea0
  { u32 v = (u32)((u32)(5348528)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @216_519ea0
  eax = (eax + 1);  // @217_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @218_519ea0
  goto L51a178;  // @219_519ea0
  L51a159:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_519ea0
  ecx = esi;  // @222_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @223_519ea0
  ecx = edx = 0;  // @224_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @225_519ea0
  if ((eax & eax) == 0) goto L51a172;  // @226_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @227_519ea0
  ecx = edx = 0;  // @228_519ea0
  goto L51a173;  // @229_519ea0
  L51a172:;
  __builtin_trap();  // @231_519ea0
  L51a173:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @233_519ea0
  L51a178:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @235_519ea0
  if (eax >= (u32)(50)) goto L51a19a;  // @236_519ea0
  { u32 v = (u32)((u32)(5347120)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @237_519ea0
  eax = (eax + 1);  // @238_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @239_519ea0
  goto L51a1b9;  // @240_519ea0
  L51a19a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_519ea0
  ecx = esi;  // @243_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @244_519ea0
  ecx = edx = 0;  // @245_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @246_519ea0
  if ((eax & eax) == 0) goto L51a1b3;  // @247_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @248_519ea0
  ecx = edx = 0;  // @249_519ea0
  goto L51a1b4;  // @250_519ea0
  L51a1b3:;
  __builtin_trap();  // @252_519ea0
  L51a1b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @254_519ea0
  L51a1b9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @256_519ea0
  if (eax >= (u32)(50)) goto L51a1db;  // @257_519ea0
  { u32 v = (u32)((u32)(5347664)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @258_519ea0
  eax = (eax + 1);  // @259_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @260_519ea0
  goto L51a1fa;  // @261_519ea0
  L51a1db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @263_519ea0
  ecx = esi;  // @264_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @265_519ea0
  ecx = edx = 0;  // @266_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @267_519ea0
  if ((eax & eax) == 0) goto L51a1f4;  // @268_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @269_519ea0
  ecx = edx = 0;  // @270_519ea0
  goto L51a1f5;  // @271_519ea0
  L51a1f4:;
  __builtin_trap();  // @273_519ea0
  L51a1f5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @275_519ea0
  L51a1fa:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @277_519ea0
  if (eax >= (u32)(50)) goto L51a21c;  // @278_519ea0
  { u32 v = (u32)((u32)(5346480)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @279_519ea0
  eax = (eax + 1);  // @280_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @281_519ea0
  goto L51a23b;  // @282_519ea0
  L51a21c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @284_519ea0
  ecx = esi;  // @285_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @286_519ea0
  ecx = edx = 0;  // @287_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @288_519ea0
  if ((eax & eax) == 0) goto L51a235;  // @289_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @290_519ea0
  ecx = edx = 0;  // @291_519ea0
  goto L51a236;  // @292_519ea0
  L51a235:;
  __builtin_trap();  // @294_519ea0
  L51a236:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @296_519ea0
  L51a23b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @298_519ea0
  if (eax >= (u32)(50)) goto L51a25d;  // @299_519ea0
  { u32 v = (u32)((u32)(5348160)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @300_519ea0
  eax = (eax + 1);  // @301_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @302_519ea0
  goto L51a27c;  // @303_519ea0
  L51a25d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @305_519ea0
  ecx = esi;  // @306_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @307_519ea0
  ecx = edx = 0;  // @308_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @309_519ea0
  if ((eax & eax) == 0) goto L51a276;  // @310_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @311_519ea0
  ecx = edx = 0;  // @312_519ea0
  goto L51a277;  // @313_519ea0
  L51a276:;
  __builtin_trap();  // @315_519ea0
  L51a277:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @317_519ea0
  L51a27c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @319_519ea0
  if (eax >= (u32)(50)) goto L51a29e;  // @320_519ea0
  { u32 v = (u32)((u32)(5346832)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @321_519ea0
  eax = (eax + 1);  // @322_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @323_519ea0
  goto L51a2bd;  // @324_519ea0
  L51a29e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_519ea0
  ecx = esi;  // @327_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @328_519ea0
  ecx = edx = 0;  // @329_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @330_519ea0
  if ((eax & eax) == 0) goto L51a2b7;  // @331_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @332_519ea0
  ecx = edx = 0;  // @333_519ea0
  goto L51a2b8;  // @334_519ea0
  L51a2b7:;
  __builtin_trap();  // @336_519ea0
  L51a2b8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @338_519ea0
  L51a2bd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @340_519ea0
  if (eax >= (u32)(50)) goto L51a2df;  // @341_519ea0
  { u32 v = (u32)((u32)(5346784)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @342_519ea0
  eax = (eax + 1);  // @343_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @344_519ea0
  goto L51a2fe;  // @345_519ea0
  L51a2df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @347_519ea0
  ecx = esi;  // @348_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @349_519ea0
  ecx = edx = 0;  // @350_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @351_519ea0
  if ((eax & eax) == 0) goto L51a2f8;  // @352_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @353_519ea0
  ecx = edx = 0;  // @354_519ea0
  goto L51a2f9;  // @355_519ea0
  L51a2f8:;
  __builtin_trap();  // @357_519ea0
  L51a2f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @359_519ea0
  L51a2fe:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @361_519ea0
  if (eax >= (u32)(50)) goto L51a320;  // @362_519ea0
  { u32 v = (u32)((u32)(5346736)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @363_519ea0
  eax = (eax + 1);  // @364_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @365_519ea0
  goto L51a33f;  // @366_519ea0
  L51a320:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @368_519ea0
  ecx = esi;  // @369_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @370_519ea0
  ecx = edx = 0;  // @371_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @372_519ea0
  if ((eax & eax) == 0) goto L51a339;  // @373_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @374_519ea0
  ecx = edx = 0;  // @375_519ea0
  goto L51a33a;  // @376_519ea0
  L51a339:;
  __builtin_trap();  // @378_519ea0
  L51a33a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @380_519ea0
  L51a33f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @382_519ea0
  if (eax >= (u32)(50)) goto L51a361;  // @383_519ea0
  { u32 v = (u32)((u32)(5348464)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @384_519ea0
  eax = (eax + 1);  // @385_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @386_519ea0
  goto L51a380;  // @387_519ea0
  L51a361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @389_519ea0
  ecx = esi;  // @390_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @391_519ea0
  ecx = edx = 0;  // @392_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @393_519ea0
  if ((eax & eax) == 0) goto L51a37a;  // @394_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @395_519ea0
  ecx = edx = 0;  // @396_519ea0
  goto L51a37b;  // @397_519ea0
  L51a37a:;
  __builtin_trap();  // @399_519ea0
  L51a37b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @401_519ea0
  L51a380:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @403_519ea0
  if (eax >= (u32)(50)) goto L51a3a2;  // @404_519ea0
  { u32 v = (u32)((u32)(5348656)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @405_519ea0
  eax = (eax + 1);  // @406_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @407_519ea0
  goto L51a3c1;  // @408_519ea0
  L51a3a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_519ea0
  ecx = esi;  // @411_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @412_519ea0
  ecx = edx = 0;  // @413_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @414_519ea0
  if ((eax & eax) == 0) goto L51a3bb;  // @415_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @416_519ea0
  ecx = edx = 0;  // @417_519ea0
  goto L51a3bc;  // @418_519ea0
  L51a3bb:;
  __builtin_trap();  // @420_519ea0
  L51a3bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @422_519ea0
  L51a3c1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @424_519ea0
  if (eax >= (u32)(50)) goto L51a3e3;  // @425_519ea0
  { u32 v = (u32)((u32)(5348768)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @426_519ea0
  eax = (eax + 1);  // @427_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @428_519ea0
  goto L51a402;  // @429_519ea0
  L51a3e3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_519ea0
  ecx = esi;  // @432_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @433_519ea0
  ecx = edx = 0;  // @434_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @435_519ea0
  if ((eax & eax) == 0) goto L51a3fc;  // @436_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @437_519ea0
  ecx = edx = 0;  // @438_519ea0
  goto L51a3fd;  // @439_519ea0
  L51a3fc:;
  __builtin_trap();  // @441_519ea0
  L51a3fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @443_519ea0
  L51a402:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @445_519ea0
  if (eax >= (u32)(50)) goto L51a424;  // @446_519ea0
  { u32 v = (u32)((u32)(5348816)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @447_519ea0
  eax = (eax + 1);  // @448_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @449_519ea0
  goto L51a443;  // @450_519ea0
  L51a424:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @452_519ea0
  ecx = esi;  // @453_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @454_519ea0
  ecx = edx = 0;  // @455_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @456_519ea0
  if ((eax & eax) == 0) goto L51a43d;  // @457_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @458_519ea0
  ecx = edx = 0;  // @459_519ea0
  goto L51a43e;  // @460_519ea0
  L51a43d:;
  __builtin_trap();  // @462_519ea0
  L51a43e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @464_519ea0
  L51a443:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @466_519ea0
  if (eax >= (u32)(50)) goto L51a465;  // @467_519ea0
  { u32 v = (u32)((u32)(5348976)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @468_519ea0
  eax = (eax + 1);  // @469_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @470_519ea0
  goto L51a484;  // @471_519ea0
  L51a465:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_519ea0
  ecx = esi;  // @474_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @475_519ea0
  ecx = edx = 0;  // @476_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @477_519ea0
  if ((eax & eax) == 0) goto L51a47e;  // @478_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @479_519ea0
  ecx = edx = 0;  // @480_519ea0
  goto L51a47f;  // @481_519ea0
  L51a47e:;
  __builtin_trap();  // @483_519ea0
  L51a47f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @485_519ea0
  L51a484:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @487_519ea0
  if (eax >= (u32)(50)) goto L51a4a6;  // @488_519ea0
  { u32 v = (u32)((u32)(5348992)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @489_519ea0
  eax = (eax + 1);  // @490_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @491_519ea0
  goto L51a4c5;  // @492_519ea0
  L51a4a6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @494_519ea0
  ecx = esi;  // @495_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @496_519ea0
  ecx = edx = 0;  // @497_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @498_519ea0
  if ((eax & eax) == 0) goto L51a4bf;  // @499_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @500_519ea0
  ecx = edx = 0;  // @501_519ea0
  goto L51a4c0;  // @502_519ea0
  L51a4bf:;
  __builtin_trap();  // @504_519ea0
  L51a4c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @506_519ea0
  L51a4c5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @508_519ea0
  if (eax >= (u32)(50)) goto L51a4e7;  // @509_519ea0
  { u32 v = (u32)((u32)(5347808)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @510_519ea0
  eax = (eax + 1);  // @511_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @512_519ea0
  goto L51a506;  // @513_519ea0
  L51a4e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_519ea0
  ecx = esi;  // @516_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @517_519ea0
  ecx = edx = 0;  // @518_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @519_519ea0
  if ((eax & eax) == 0) goto L51a500;  // @520_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @521_519ea0
  ecx = edx = 0;  // @522_519ea0
  goto L51a501;  // @523_519ea0
  L51a500:;
  __builtin_trap();  // @525_519ea0
  L51a501:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @527_519ea0
  L51a506:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @529_519ea0
  if (eax >= (u32)(50)) goto L51a528;  // @530_519ea0
  { u32 v = (u32)((u32)(5348016)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @531_519ea0
  eax = (eax + 1);  // @532_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @533_519ea0
  goto L51a547;  // @534_519ea0
  L51a528:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @536_519ea0
  ecx = esi;  // @537_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @538_519ea0
  ecx = edx = 0;  // @539_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @540_519ea0
  if ((eax & eax) == 0) goto L51a541;  // @541_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @542_519ea0
  ecx = edx = 0;  // @543_519ea0
  goto L51a542;  // @544_519ea0
  L51a541:;
  __builtin_trap();  // @546_519ea0
  L51a542:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @548_519ea0
  L51a547:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @550_519ea0
  if (eax >= (u32)(50)) goto L51a569;  // @551_519ea0
  { u32 v = (u32)((u32)(5348272)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @552_519ea0
  eax = (eax + 1);  // @553_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @554_519ea0
  goto L51a588;  // @555_519ea0
  L51a569:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_519ea0
  ecx = esi;  // @558_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @559_519ea0
  ecx = edx = 0;  // @560_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @561_519ea0
  if ((eax & eax) == 0) goto L51a582;  // @562_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @563_519ea0
  ecx = edx = 0;  // @564_519ea0
  goto L51a583;  // @565_519ea0
  L51a582:;
  __builtin_trap();  // @567_519ea0
  L51a583:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @569_519ea0
  L51a588:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @571_519ea0
  if (eax >= (u32)(50)) goto L51a5aa;  // @572_519ea0
  { u32 v = (u32)((u32)(5348208)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @573_519ea0
  eax = (eax + 1);  // @574_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @575_519ea0
  goto L51a5c9;  // @576_519ea0
  L51a5aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @578_519ea0
  ecx = esi;  // @579_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @580_519ea0
  ecx = edx = 0;  // @581_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @582_519ea0
  if ((eax & eax) == 0) goto L51a5c3;  // @583_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @584_519ea0
  ecx = edx = 0;  // @585_519ea0
  goto L51a5c4;  // @586_519ea0
  L51a5c3:;
  __builtin_trap();  // @588_519ea0
  L51a5c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @590_519ea0
  L51a5c9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @592_519ea0
  if (eax >= (u32)(50)) goto L51a5eb;  // @593_519ea0
  { u32 v = (u32)((u32)(5346880)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @594_519ea0
  eax = (eax + 1);  // @595_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @596_519ea0
  goto L51a60a;  // @597_519ea0
  L51a5eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @599_519ea0
  ecx = esi;  // @600_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @601_519ea0
  ecx = edx = 0;  // @602_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @603_519ea0
  if ((eax & eax) == 0) goto L51a604;  // @604_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @605_519ea0
  ecx = edx = 0;  // @606_519ea0
  goto L51a605;  // @607_519ea0
  L51a604:;
  __builtin_trap();  // @609_519ea0
  L51a605:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @611_519ea0
  L51a60a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @613_519ea0
  if (eax >= (u32)(50)) goto L51a62c;  // @614_519ea0
  { u32 v = (u32)((u32)(5346416)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @615_519ea0
  eax = (eax + 1);  // @616_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @617_519ea0
  goto L51a64b;  // @618_519ea0
  L51a62c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @620_519ea0
  ecx = esi;  // @621_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @622_519ea0
  ecx = edx = 0;  // @623_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @624_519ea0
  if ((eax & eax) == 0) goto L51a645;  // @625_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @626_519ea0
  ecx = edx = 0;  // @627_519ea0
  goto L51a646;  // @628_519ea0
  L51a645:;
  __builtin_trap();  // @630_519ea0
  L51a646:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @632_519ea0
  L51a64b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @634_519ea0
  if (eax >= (u32)(50)) goto L51a66d;  // @635_519ea0
  { u32 v = (u32)((u32)(5347216)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @636_519ea0
  eax = (eax + 1);  // @637_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @638_519ea0
  goto L51a68c;  // @639_519ea0
  L51a66d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @641_519ea0
  ecx = esi;  // @642_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @643_519ea0
  ecx = edx = 0;  // @644_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @645_519ea0
  if ((eax & eax) == 0) goto L51a686;  // @646_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @647_519ea0
  ecx = edx = 0;  // @648_519ea0
  goto L51a687;  // @649_519ea0
  L51a686:;
  __builtin_trap();  // @651_519ea0
  L51a687:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345760), sizeof v); (u32)v; });  // @653_519ea0
  L51a68c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L51a6e4;  // @655_519ea0
  if (eax >= (u32)(50)) goto L51a6ba;  // @656_519ea0
  { u32 v = (u32)((u32)(5348720)); __builtin_memcpy((void *)(u32)(eax*4 + 7345768), &v, sizeof v); }  // @657_519ea0
  ecx = esi;  // @658_519ea0
  eax = (eax + 1);  // @659_519ea0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @660_519ea0
  p0_ = edi;  // @661_519ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345760), &v, sizeof v); }  // @662_519ea0
  eax = ext_503770_thiscall2(ecx, (u32)(p0_));  // @663_519ea0
  ecx = edx = 0;  // @664_519ea0
  return eax;  // @665_519ea0
  L51a6ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @667_519ea0
  ecx = esi;  // @668_519ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6943356));  // @669_519ea0
  ecx = edx = 0;  // @670_519ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @671_519ea0
  if ((eax & eax) == 0) goto L51a6e3;  // @672_519ea0
  eax = ((u32(STDCALL *)(void))(eax))();  // @673_519ea0
  ecx = edx = 0;  // @674_519ea0
  p1_ = edi;  // @675_519ea0
  ecx = esi;  // @676_519ea0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @677_519ea0
  eax = ext_503770_thiscall2(ecx, (u32)(p1_));  // @678_519ea0
  ecx = edx = 0;  // @679_519ea0
  return eax;  // @680_519ea0
  L51a6e3:;
  __builtin_trap();  // @682_519ea0
  L51a6e4:;
  p2_ = edi;  // @684_519ea0
  ecx = esi;  // @685_519ea0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @686_519ea0
  eax = ext_503770_thiscall2(ecx, (u32)(p2_));  // @687_519ea0
  ecx = edx = 0;  // @688_519ea0
  return eax;  // @689_519ea0
}
PCREG(519ea0, lifted_519ea0);

extern "C" u32 THISCALL lifted_50ffe0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @0_50ffe0
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_50ffe0
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_50ffe0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_50ffe0
  esi = ecx;  // @4_50ffe0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @5_50ffe0
  if (eax >= (u32)(50)) goto L510011;  // @6_50ffe0
  { u32 v = (u32)((u32)(5298656)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @7_50ffe0
  eax = (eax + 1);  // @8_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @9_50ffe0
  goto L51002e;  // @10_50ffe0
  L510011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @13_50ffe0
  ecx = edx = 0;  // @14_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_50ffe0
  if ((eax & eax) == 0) goto L510028;  // @16_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @17_50ffe0
  ecx = edx = 0;  // @18_50ffe0
  goto L510029;  // @19_50ffe0
  L510028:;
  __builtin_trap();  // @21_50ffe0
  L510029:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @23_50ffe0
  L51002e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @25_50ffe0
  if (eax >= (u32)(50)) goto L510050;  // @26_50ffe0
  { u32 v = (u32)((u32)(5305312)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @27_50ffe0
  eax = (eax + 1);  // @28_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @29_50ffe0
  goto L51006f;  // @30_50ffe0
  L510050:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_50ffe0
  ecx = esi;  // @33_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @34_50ffe0
  ecx = edx = 0;  // @35_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_50ffe0
  if ((eax & eax) == 0) goto L510069;  // @37_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_50ffe0
  ecx = edx = 0;  // @39_50ffe0
  goto L51006a;  // @40_50ffe0
  L510069:;
  __builtin_trap();  // @42_50ffe0
  L51006a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @44_50ffe0
  L51006f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @46_50ffe0
  if (eax >= (u32)(50)) goto L510091;  // @47_50ffe0
  { u32 v = (u32)((u32)(5305312)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @48_50ffe0
  eax = (eax + 1);  // @49_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @50_50ffe0
  goto L5100b0;  // @51_50ffe0
  L510091:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_50ffe0
  ecx = esi;  // @54_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @55_50ffe0
  ecx = edx = 0;  // @56_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_50ffe0
  if ((eax & eax) == 0) goto L5100aa;  // @58_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_50ffe0
  ecx = edx = 0;  // @60_50ffe0
  goto L5100ab;  // @61_50ffe0
  L5100aa:;
  __builtin_trap();  // @63_50ffe0
  L5100ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @65_50ffe0
  L5100b0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @67_50ffe0
  if (eax >= (u32)(50)) goto L5100d2;  // @68_50ffe0
  { u32 v = (u32)((u32)(5305552)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @69_50ffe0
  eax = (eax + 1);  // @70_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @71_50ffe0
  goto L5100f1;  // @72_50ffe0
  L5100d2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_50ffe0
  ecx = esi;  // @75_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @76_50ffe0
  ecx = edx = 0;  // @77_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @78_50ffe0
  if ((eax & eax) == 0) goto L5100eb;  // @79_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_50ffe0
  ecx = edx = 0;  // @81_50ffe0
  goto L5100ec;  // @82_50ffe0
  L5100eb:;
  __builtin_trap();  // @84_50ffe0
  L5100ec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @86_50ffe0
  L5100f1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @88_50ffe0
  if (eax >= (u32)(50)) goto L510113;  // @89_50ffe0
  { u32 v = (u32)((u32)(5305056)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @90_50ffe0
  eax = (eax + 1);  // @91_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @92_50ffe0
  goto L510132;  // @93_50ffe0
  L510113:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_50ffe0
  ecx = esi;  // @96_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @97_50ffe0
  ecx = edx = 0;  // @98_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @99_50ffe0
  if ((eax & eax) == 0) goto L51012c;  // @100_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @101_50ffe0
  ecx = edx = 0;  // @102_50ffe0
  goto L51012d;  // @103_50ffe0
  L51012c:;
  __builtin_trap();  // @105_50ffe0
  L51012d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @107_50ffe0
  L510132:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @109_50ffe0
  if (eax >= (u32)(50)) goto L510154;  // @110_50ffe0
  { u32 v = (u32)((u32)(5304816)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @111_50ffe0
  eax = (eax + 1);  // @112_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @113_50ffe0
  goto L510173;  // @114_50ffe0
  L510154:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_50ffe0
  ecx = esi;  // @117_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @118_50ffe0
  ecx = edx = 0;  // @119_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @120_50ffe0
  if ((eax & eax) == 0) goto L51016d;  // @121_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @122_50ffe0
  ecx = edx = 0;  // @123_50ffe0
  goto L51016e;  // @124_50ffe0
  L51016d:;
  __builtin_trap();  // @126_50ffe0
  L51016e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @128_50ffe0
  L510173:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @130_50ffe0
  if (eax >= (u32)(50)) goto L510195;  // @131_50ffe0
  { u32 v = (u32)((u32)(5307424)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @132_50ffe0
  eax = (eax + 1);  // @133_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @134_50ffe0
  goto L5101b4;  // @135_50ffe0
  L510195:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_50ffe0
  ecx = esi;  // @138_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @139_50ffe0
  ecx = edx = 0;  // @140_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @141_50ffe0
  if ((eax & eax) == 0) goto L5101ae;  // @142_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @143_50ffe0
  ecx = edx = 0;  // @144_50ffe0
  goto L5101af;  // @145_50ffe0
  L5101ae:;
  __builtin_trap();  // @147_50ffe0
  L5101af:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @149_50ffe0
  L5101b4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @151_50ffe0
  if (eax >= (u32)(50)) goto L5101d6;  // @152_50ffe0
  { u32 v = (u32)((u32)(5307424)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @153_50ffe0
  eax = (eax + 1);  // @154_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @155_50ffe0
  goto L5101f5;  // @156_50ffe0
  L5101d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_50ffe0
  ecx = esi;  // @159_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @160_50ffe0
  ecx = edx = 0;  // @161_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @162_50ffe0
  if ((eax & eax) == 0) goto L5101ef;  // @163_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @164_50ffe0
  ecx = edx = 0;  // @165_50ffe0
  goto L5101f0;  // @166_50ffe0
  L5101ef:;
  __builtin_trap();  // @168_50ffe0
  L5101f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @170_50ffe0
  L5101f5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @172_50ffe0
  if (eax >= (u32)(50)) goto L510217;  // @173_50ffe0
  { u32 v = (u32)((u32)(5307648)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @174_50ffe0
  eax = (eax + 1);  // @175_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @176_50ffe0
  goto L510236;  // @177_50ffe0
  L510217:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_50ffe0
  ecx = esi;  // @180_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @181_50ffe0
  ecx = edx = 0;  // @182_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @183_50ffe0
  if ((eax & eax) == 0) goto L510230;  // @184_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @185_50ffe0
  ecx = edx = 0;  // @186_50ffe0
  goto L510231;  // @187_50ffe0
  L510230:;
  __builtin_trap();  // @189_50ffe0
  L510231:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @191_50ffe0
  L510236:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @193_50ffe0
  if (eax >= (u32)(50)) goto L510258;  // @194_50ffe0
  { u32 v = (u32)((u32)(5307248)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @195_50ffe0
  eax = (eax + 1);  // @196_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @197_50ffe0
  goto L510277;  // @198_50ffe0
  L510258:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_50ffe0
  ecx = esi;  // @201_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @202_50ffe0
  ecx = edx = 0;  // @203_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_50ffe0
  if ((eax & eax) == 0) goto L510271;  // @205_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @206_50ffe0
  ecx = edx = 0;  // @207_50ffe0
  goto L510272;  // @208_50ffe0
  L510271:;
  __builtin_trap();  // @210_50ffe0
  L510272:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @212_50ffe0
  L510277:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @214_50ffe0
  if (eax >= (u32)(50)) goto L510299;  // @215_50ffe0
  { u32 v = (u32)((u32)(5307024)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @216_50ffe0
  eax = (eax + 1);  // @217_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @218_50ffe0
  goto L5102b8;  // @219_50ffe0
  L510299:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_50ffe0
  ecx = esi;  // @222_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @223_50ffe0
  ecx = edx = 0;  // @224_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @225_50ffe0
  if ((eax & eax) == 0) goto L5102b2;  // @226_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @227_50ffe0
  ecx = edx = 0;  // @228_50ffe0
  goto L5102b3;  // @229_50ffe0
  L5102b2:;
  __builtin_trap();  // @231_50ffe0
  L5102b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @233_50ffe0
  L5102b8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @235_50ffe0
  if (eax >= (u32)(50)) goto L5102da;  // @236_50ffe0
  { u32 v = (u32)((u32)(5307952)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @237_50ffe0
  eax = (eax + 1);  // @238_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @239_50ffe0
  goto L5102f9;  // @240_50ffe0
  L5102da:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_50ffe0
  ecx = esi;  // @243_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @244_50ffe0
  ecx = edx = 0;  // @245_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @246_50ffe0
  if ((eax & eax) == 0) goto L5102f3;  // @247_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @248_50ffe0
  ecx = edx = 0;  // @249_50ffe0
  goto L5102f4;  // @250_50ffe0
  L5102f3:;
  __builtin_trap();  // @252_50ffe0
  L5102f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @254_50ffe0
  L5102f9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @256_50ffe0
  if (eax >= (u32)(50)) goto L51031b;  // @257_50ffe0
  { u32 v = (u32)((u32)(5306320)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @258_50ffe0
  eax = (eax + 1);  // @259_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @260_50ffe0
  goto L51033a;  // @261_50ffe0
  L51031b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @263_50ffe0
  ecx = esi;  // @264_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @265_50ffe0
  ecx = edx = 0;  // @266_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @267_50ffe0
  if ((eax & eax) == 0) goto L510334;  // @268_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @269_50ffe0
  ecx = edx = 0;  // @270_50ffe0
  goto L510335;  // @271_50ffe0
  L510334:;
  __builtin_trap();  // @273_50ffe0
  L510335:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @275_50ffe0
  L51033a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @277_50ffe0
  if (eax >= (u32)(50)) goto L51035c;  // @278_50ffe0
  { u32 v = (u32)((u32)(5306288)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @279_50ffe0
  eax = (eax + 1);  // @280_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @281_50ffe0
  goto L51037b;  // @282_50ffe0
  L51035c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @284_50ffe0
  ecx = esi;  // @285_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @286_50ffe0
  ecx = edx = 0;  // @287_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @288_50ffe0
  if ((eax & eax) == 0) goto L510375;  // @289_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @290_50ffe0
  ecx = edx = 0;  // @291_50ffe0
  goto L510376;  // @292_50ffe0
  L510375:;
  __builtin_trap();  // @294_50ffe0
  L510376:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @296_50ffe0
  L51037b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @298_50ffe0
  if (eax >= (u32)(50)) goto L51039d;  // @299_50ffe0
  { u32 v = (u32)((u32)(5300128)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @300_50ffe0
  eax = (eax + 1);  // @301_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @302_50ffe0
  goto L5103bc;  // @303_50ffe0
  L51039d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @305_50ffe0
  ecx = esi;  // @306_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @307_50ffe0
  ecx = edx = 0;  // @308_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @309_50ffe0
  if ((eax & eax) == 0) goto L5103b6;  // @310_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @311_50ffe0
  ecx = edx = 0;  // @312_50ffe0
  goto L5103b7;  // @313_50ffe0
  L5103b6:;
  __builtin_trap();  // @315_50ffe0
  L5103b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @317_50ffe0
  L5103bc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @319_50ffe0
  if (eax >= (u32)(50)) goto L5103de;  // @320_50ffe0
  { u32 v = (u32)((u32)(5304608)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @321_50ffe0
  eax = (eax + 1);  // @322_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @323_50ffe0
  goto L5103fd;  // @324_50ffe0
  L5103de:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_50ffe0
  ecx = esi;  // @327_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @328_50ffe0
  ecx = edx = 0;  // @329_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @330_50ffe0
  if ((eax & eax) == 0) goto L5103f7;  // @331_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @332_50ffe0
  ecx = edx = 0;  // @333_50ffe0
  goto L5103f8;  // @334_50ffe0
  L5103f7:;
  __builtin_trap();  // @336_50ffe0
  L5103f8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @338_50ffe0
  L5103fd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @340_50ffe0
  if (eax >= (u32)(50)) goto L51041f;  // @341_50ffe0
  { u32 v = (u32)((u32)(5304416)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @342_50ffe0
  eax = (eax + 1);  // @343_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @344_50ffe0
  goto L51043e;  // @345_50ffe0
  L51041f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @347_50ffe0
  ecx = esi;  // @348_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @349_50ffe0
  ecx = edx = 0;  // @350_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @351_50ffe0
  if ((eax & eax) == 0) goto L510438;  // @352_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @353_50ffe0
  ecx = edx = 0;  // @354_50ffe0
  goto L510439;  // @355_50ffe0
  L510438:;
  __builtin_trap();  // @357_50ffe0
  L510439:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @359_50ffe0
  L51043e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @361_50ffe0
  if (eax >= (u32)(50)) goto L510460;  // @362_50ffe0
  { u32 v = (u32)((u32)(5302112)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @363_50ffe0
  eax = (eax + 1);  // @364_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @365_50ffe0
  goto L51047f;  // @366_50ffe0
  L510460:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @368_50ffe0
  ecx = esi;  // @369_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @370_50ffe0
  ecx = edx = 0;  // @371_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @372_50ffe0
  if ((eax & eax) == 0) goto L510479;  // @373_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @374_50ffe0
  ecx = edx = 0;  // @375_50ffe0
  goto L51047a;  // @376_50ffe0
  L510479:;
  __builtin_trap();  // @378_50ffe0
  L51047a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @380_50ffe0
  L51047f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @382_50ffe0
  if (eax >= (u32)(50)) goto L5104a1;  // @383_50ffe0
  { u32 v = (u32)((u32)(5302256)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @384_50ffe0
  eax = (eax + 1);  // @385_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @386_50ffe0
  goto L5104c0;  // @387_50ffe0
  L5104a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @389_50ffe0
  ecx = esi;  // @390_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @391_50ffe0
  ecx = edx = 0;  // @392_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @393_50ffe0
  if ((eax & eax) == 0) goto L5104ba;  // @394_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @395_50ffe0
  ecx = edx = 0;  // @396_50ffe0
  goto L5104bb;  // @397_50ffe0
  L5104ba:;
  __builtin_trap();  // @399_50ffe0
  L5104bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @401_50ffe0
  L5104c0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @403_50ffe0
  if (eax >= (u32)(50)) goto L5104e2;  // @404_50ffe0
  { u32 v = (u32)((u32)(5300560)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @405_50ffe0
  eax = (eax + 1);  // @406_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @407_50ffe0
  goto L510501;  // @408_50ffe0
  L5104e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_50ffe0
  ecx = esi;  // @411_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @412_50ffe0
  ecx = edx = 0;  // @413_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @414_50ffe0
  if ((eax & eax) == 0) goto L5104fb;  // @415_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @416_50ffe0
  ecx = edx = 0;  // @417_50ffe0
  goto L5104fc;  // @418_50ffe0
  L5104fb:;
  __builtin_trap();  // @420_50ffe0
  L5104fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @422_50ffe0
  L510501:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @424_50ffe0
  if (eax >= (u32)(50)) goto L510523;  // @425_50ffe0
  { u32 v = (u32)((u32)(5299536)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @426_50ffe0
  eax = (eax + 1);  // @427_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @428_50ffe0
  goto L510542;  // @429_50ffe0
  L510523:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_50ffe0
  ecx = esi;  // @432_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @433_50ffe0
  ecx = edx = 0;  // @434_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @435_50ffe0
  if ((eax & eax) == 0) goto L51053c;  // @436_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @437_50ffe0
  ecx = edx = 0;  // @438_50ffe0
  goto L51053d;  // @439_50ffe0
  L51053c:;
  __builtin_trap();  // @441_50ffe0
  L51053d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @443_50ffe0
  L510542:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @445_50ffe0
  if (eax >= (u32)(50)) goto L510564;  // @446_50ffe0
  { u32 v = (u32)((u32)(5299792)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @447_50ffe0
  eax = (eax + 1);  // @448_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @449_50ffe0
  goto L510583;  // @450_50ffe0
  L510564:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @452_50ffe0
  ecx = esi;  // @453_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @454_50ffe0
  ecx = edx = 0;  // @455_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @456_50ffe0
  if ((eax & eax) == 0) goto L51057d;  // @457_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @458_50ffe0
  ecx = edx = 0;  // @459_50ffe0
  goto L51057e;  // @460_50ffe0
  L51057d:;
  __builtin_trap();  // @462_50ffe0
  L51057e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @464_50ffe0
  L510583:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @466_50ffe0
  if (eax >= (u32)(50)) goto L5105a5;  // @467_50ffe0
  { u32 v = (u32)((u32)(5311808)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @468_50ffe0
  eax = (eax + 1);  // @469_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @470_50ffe0
  goto L5105c4;  // @471_50ffe0
  L5105a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_50ffe0
  ecx = esi;  // @474_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @475_50ffe0
  ecx = edx = 0;  // @476_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @477_50ffe0
  if ((eax & eax) == 0) goto L5105be;  // @478_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @479_50ffe0
  ecx = edx = 0;  // @480_50ffe0
  goto L5105bf;  // @481_50ffe0
  L5105be:;
  __builtin_trap();  // @483_50ffe0
  L5105bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @485_50ffe0
  L5105c4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @487_50ffe0
  if (eax >= (u32)(50)) goto L5105e6;  // @488_50ffe0
  { u32 v = (u32)((u32)(5311472)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @489_50ffe0
  eax = (eax + 1);  // @490_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @491_50ffe0
  goto L510605;  // @492_50ffe0
  L5105e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @494_50ffe0
  ecx = esi;  // @495_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @496_50ffe0
  ecx = edx = 0;  // @497_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @498_50ffe0
  if ((eax & eax) == 0) goto L5105ff;  // @499_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @500_50ffe0
  ecx = edx = 0;  // @501_50ffe0
  goto L510600;  // @502_50ffe0
  L5105ff:;
  __builtin_trap();  // @504_50ffe0
  L510600:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @506_50ffe0
  L510605:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @508_50ffe0
  if (eax >= (u32)(50)) goto L510627;  // @509_50ffe0
  { u32 v = (u32)((u32)(5299296)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @510_50ffe0
  eax = (eax + 1);  // @511_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @512_50ffe0
  goto L510646;  // @513_50ffe0
  L510627:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_50ffe0
  ecx = esi;  // @516_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @517_50ffe0
  ecx = edx = 0;  // @518_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @519_50ffe0
  if ((eax & eax) == 0) goto L510640;  // @520_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @521_50ffe0
  ecx = edx = 0;  // @522_50ffe0
  goto L510641;  // @523_50ffe0
  L510640:;
  __builtin_trap();  // @525_50ffe0
  L510641:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @527_50ffe0
  L510646:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @529_50ffe0
  if (eax >= (u32)(50)) goto L510668;  // @530_50ffe0
  { u32 v = (u32)((u32)(5306448)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @531_50ffe0
  eax = (eax + 1);  // @532_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @533_50ffe0
  goto L510687;  // @534_50ffe0
  L510668:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @536_50ffe0
  ecx = esi;  // @537_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @538_50ffe0
  ecx = edx = 0;  // @539_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @540_50ffe0
  if ((eax & eax) == 0) goto L510681;  // @541_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @542_50ffe0
  ecx = edx = 0;  // @543_50ffe0
  goto L510682;  // @544_50ffe0
  L510681:;
  __builtin_trap();  // @546_50ffe0
  L510682:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @548_50ffe0
  L510687:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @550_50ffe0
  if (eax >= (u32)(50)) goto L5106a9;  // @551_50ffe0
  { u32 v = (u32)((u32)(5303072)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @552_50ffe0
  eax = (eax + 1);  // @553_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @554_50ffe0
  goto L5106c8;  // @555_50ffe0
  L5106a9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_50ffe0
  ecx = esi;  // @558_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @559_50ffe0
  ecx = edx = 0;  // @560_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @561_50ffe0
  if ((eax & eax) == 0) goto L5106c2;  // @562_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @563_50ffe0
  ecx = edx = 0;  // @564_50ffe0
  goto L5106c3;  // @565_50ffe0
  L5106c2:;
  __builtin_trap();  // @567_50ffe0
  L5106c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @569_50ffe0
  L5106c8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @571_50ffe0
  if (eax >= (u32)(50)) goto L5106ea;  // @572_50ffe0
  { u32 v = (u32)((u32)(5303552)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @573_50ffe0
  eax = (eax + 1);  // @574_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @575_50ffe0
  goto L510709;  // @576_50ffe0
  L5106ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @578_50ffe0
  ecx = esi;  // @579_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @580_50ffe0
  ecx = edx = 0;  // @581_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @582_50ffe0
  if ((eax & eax) == 0) goto L510703;  // @583_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @584_50ffe0
  ecx = edx = 0;  // @585_50ffe0
  goto L510704;  // @586_50ffe0
  L510703:;
  __builtin_trap();  // @588_50ffe0
  L510704:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @590_50ffe0
  L510709:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @592_50ffe0
  if (eax >= (u32)(50)) goto L51072b;  // @593_50ffe0
  { u32 v = (u32)((u32)(5301008)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @594_50ffe0
  eax = (eax + 1);  // @595_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @596_50ffe0
  goto L51074a;  // @597_50ffe0
  L51072b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @599_50ffe0
  ecx = esi;  // @600_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @601_50ffe0
  ecx = edx = 0;  // @602_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @603_50ffe0
  if ((eax & eax) == 0) goto L510744;  // @604_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @605_50ffe0
  ecx = edx = 0;  // @606_50ffe0
  goto L510745;  // @607_50ffe0
  L510744:;
  __builtin_trap();  // @609_50ffe0
  L510745:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @611_50ffe0
  L51074a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @613_50ffe0
  if (eax >= (u32)(50)) goto L51076c;  // @614_50ffe0
  { u32 v = (u32)((u32)(5302560)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @615_50ffe0
  eax = (eax + 1);  // @616_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @617_50ffe0
  goto L51078b;  // @618_50ffe0
  L51076c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @620_50ffe0
  ecx = esi;  // @621_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @622_50ffe0
  ecx = edx = 0;  // @623_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @624_50ffe0
  if ((eax & eax) == 0) goto L510785;  // @625_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @626_50ffe0
  ecx = edx = 0;  // @627_50ffe0
  goto L510786;  // @628_50ffe0
  L510785:;
  __builtin_trap();  // @630_50ffe0
  L510786:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @632_50ffe0
  L51078b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @634_50ffe0
  if (eax >= (u32)(50)) goto L5107ad;  // @635_50ffe0
  { u32 v = (u32)((u32)(5305776)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @636_50ffe0
  eax = (eax + 1);  // @637_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @638_50ffe0
  goto L5107cc;  // @639_50ffe0
  L5107ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @641_50ffe0
  ecx = esi;  // @642_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @643_50ffe0
  ecx = edx = 0;  // @644_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @645_50ffe0
  if ((eax & eax) == 0) goto L5107c6;  // @646_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @647_50ffe0
  ecx = edx = 0;  // @648_50ffe0
  goto L5107c7;  // @649_50ffe0
  L5107c6:;
  __builtin_trap();  // @651_50ffe0
  L5107c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @653_50ffe0
  L5107cc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @655_50ffe0
  if (eax >= (u32)(50)) goto L5107ee;  // @656_50ffe0
  { u32 v = (u32)((u32)(5305872)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @657_50ffe0
  eax = (eax + 1);  // @658_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @659_50ffe0
  goto L51080d;  // @660_50ffe0
  L5107ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @662_50ffe0
  ecx = esi;  // @663_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @664_50ffe0
  ecx = edx = 0;  // @665_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @666_50ffe0
  if ((eax & eax) == 0) goto L510807;  // @667_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @668_50ffe0
  ecx = edx = 0;  // @669_50ffe0
  goto L510808;  // @670_50ffe0
  L510807:;
  __builtin_trap();  // @672_50ffe0
  L510808:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @674_50ffe0
  L51080d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @676_50ffe0
  if (eax >= (u32)(50)) goto L51082f;  // @677_50ffe0
  { u32 v = (u32)((u32)(5308192)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @678_50ffe0
  eax = (eax + 1);  // @679_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @680_50ffe0
  goto L51084e;  // @681_50ffe0
  L51082f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @683_50ffe0
  ecx = esi;  // @684_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @685_50ffe0
  ecx = edx = 0;  // @686_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @687_50ffe0
  if ((eax & eax) == 0) goto L510848;  // @688_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @689_50ffe0
  ecx = edx = 0;  // @690_50ffe0
  goto L510849;  // @691_50ffe0
  L510848:;
  __builtin_trap();  // @693_50ffe0
  L510849:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @695_50ffe0
  L51084e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @697_50ffe0
  if (eax >= (u32)(50)) goto L510870;  // @698_50ffe0
  { u32 v = (u32)((u32)(5308288)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @699_50ffe0
  eax = (eax + 1);  // @700_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @701_50ffe0
  goto L51088f;  // @702_50ffe0
  L510870:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @704_50ffe0
  ecx = esi;  // @705_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @706_50ffe0
  ecx = edx = 0;  // @707_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @708_50ffe0
  if ((eax & eax) == 0) goto L510889;  // @709_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @710_50ffe0
  ecx = edx = 0;  // @711_50ffe0
  goto L51088a;  // @712_50ffe0
  L510889:;
  __builtin_trap();  // @714_50ffe0
  L51088a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @716_50ffe0
  L51088f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @718_50ffe0
  if (eax >= (u32)(50)) goto L5108b1;  // @719_50ffe0
  { u32 v = (u32)((u32)(5306032)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @720_50ffe0
  eax = (eax + 1);  // @721_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @722_50ffe0
  goto L5108d0;  // @723_50ffe0
  L5108b1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @725_50ffe0
  ecx = esi;  // @726_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @727_50ffe0
  ecx = edx = 0;  // @728_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @729_50ffe0
  if ((eax & eax) == 0) goto L5108ca;  // @730_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @731_50ffe0
  ecx = edx = 0;  // @732_50ffe0
  goto L5108cb;  // @733_50ffe0
  L5108ca:;
  __builtin_trap();  // @735_50ffe0
  L5108cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @737_50ffe0
  L5108d0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @739_50ffe0
  if (eax >= (u32)(50)) goto L5108f2;  // @740_50ffe0
  { u32 v = (u32)((u32)(5306128)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @741_50ffe0
  eax = (eax + 1);  // @742_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @743_50ffe0
  goto L510911;  // @744_50ffe0
  L5108f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @746_50ffe0
  ecx = esi;  // @747_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @748_50ffe0
  ecx = edx = 0;  // @749_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @750_50ffe0
  if ((eax & eax) == 0) goto L51090b;  // @751_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @752_50ffe0
  ecx = edx = 0;  // @753_50ffe0
  goto L51090c;  // @754_50ffe0
  L51090b:;
  __builtin_trap();  // @756_50ffe0
  L51090c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @758_50ffe0
  L510911:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @760_50ffe0
  if (eax >= (u32)(50)) goto L510933;  // @761_50ffe0
  { u32 v = (u32)((u32)(5302432)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @762_50ffe0
  eax = (eax + 1);  // @763_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @764_50ffe0
  goto L510952;  // @765_50ffe0
  L510933:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @767_50ffe0
  ecx = esi;  // @768_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @769_50ffe0
  ecx = edx = 0;  // @770_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @771_50ffe0
  if ((eax & eax) == 0) goto L51094c;  // @772_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @773_50ffe0
  ecx = edx = 0;  // @774_50ffe0
  goto L51094d;  // @775_50ffe0
  L51094c:;
  __builtin_trap();  // @777_50ffe0
  L51094d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @779_50ffe0
  L510952:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @781_50ffe0
  if (eax >= (u32)(50)) goto L510974;  // @782_50ffe0
  { u32 v = (u32)((u32)(5306864)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @783_50ffe0
  eax = (eax + 1);  // @784_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @785_50ffe0
  goto L510993;  // @786_50ffe0
  L510974:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @788_50ffe0
  ecx = esi;  // @789_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @790_50ffe0
  ecx = edx = 0;  // @791_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @792_50ffe0
  if ((eax & eax) == 0) goto L51098d;  // @793_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @794_50ffe0
  ecx = edx = 0;  // @795_50ffe0
  goto L51098e;  // @796_50ffe0
  L51098d:;
  __builtin_trap();  // @798_50ffe0
  L51098e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @800_50ffe0
  L510993:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @802_50ffe0
  if (eax >= (u32)(50)) goto L5109b5;  // @803_50ffe0
  { u32 v = (u32)((u32)(5299024)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @804_50ffe0
  eax = (eax + 1);  // @805_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @806_50ffe0
  goto L5109d4;  // @807_50ffe0
  L5109b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @809_50ffe0
  ecx = esi;  // @810_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @811_50ffe0
  ecx = edx = 0;  // @812_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @813_50ffe0
  if ((eax & eax) == 0) goto L5109ce;  // @814_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @815_50ffe0
  ecx = edx = 0;  // @816_50ffe0
  goto L5109cf;  // @817_50ffe0
  L5109ce:;
  __builtin_trap();  // @819_50ffe0
  L5109cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @821_50ffe0
  L5109d4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @823_50ffe0
  if (eax >= (u32)(50)) goto L5109f6;  // @824_50ffe0
  { u32 v = (u32)((u32)(5298896)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @825_50ffe0
  eax = (eax + 1);  // @826_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @827_50ffe0
  goto L510a15;  // @828_50ffe0
  L5109f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @830_50ffe0
  ecx = esi;  // @831_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @832_50ffe0
  ecx = edx = 0;  // @833_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @834_50ffe0
  if ((eax & eax) == 0) goto L510a0f;  // @835_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @836_50ffe0
  ecx = edx = 0;  // @837_50ffe0
  goto L510a10;  // @838_50ffe0
  L510a0f:;
  __builtin_trap();  // @840_50ffe0
  L510a10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @842_50ffe0
  L510a15:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @844_50ffe0
  if (eax >= (u32)(50)) goto L510a37;  // @845_50ffe0
  { u32 v = (u32)((u32)(5305968)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @846_50ffe0
  eax = (eax + 1);  // @847_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @848_50ffe0
  goto L510a56;  // @849_50ffe0
  L510a37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @851_50ffe0
  ecx = esi;  // @852_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @853_50ffe0
  ecx = edx = 0;  // @854_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @855_50ffe0
  if ((eax & eax) == 0) goto L510a50;  // @856_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @857_50ffe0
  ecx = edx = 0;  // @858_50ffe0
  goto L510a51;  // @859_50ffe0
  L510a50:;
  __builtin_trap();  // @861_50ffe0
  L510a51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @863_50ffe0
  L510a56:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @865_50ffe0
  if (eax >= (u32)(50)) goto L510a74;  // @866_50ffe0
  { u32 v = (u32)((u32)(5306224)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @867_50ffe0
  eax = (eax + 1);  // @868_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @869_50ffe0
  goto L510a93;  // @870_50ffe0
  L510a74:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @872_50ffe0
  ecx = esi;  // @873_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @874_50ffe0
  ecx = edx = 0;  // @875_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @876_50ffe0
  if ((eax & eax) == 0) goto L510a8d;  // @877_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @878_50ffe0
  ecx = edx = 0;  // @879_50ffe0
  goto L510a8e;  // @880_50ffe0
  L510a8d:;
  __builtin_trap();  // @882_50ffe0
  L510a8e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7345048), sizeof v); (u32)v; });  // @884_50ffe0
  L510a93:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L510ad3;  // @886_50ffe0
  if (eax >= (u32)(50)) goto L510ab5;  // @887_50ffe0
  { u32 v = (u32)((u32)(5289232)); __builtin_memcpy((void *)(u32)(eax*4 + 7345056), &v, sizeof v); }  // @888_50ffe0
  eax = (eax + 1);  // @889_50ffe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7345048), &v, sizeof v); }  // @890_50ffe0
  return eax;  // @891_50ffe0
  L510ab5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @893_50ffe0
  ecx = esi;  // @894_50ffe0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6937372));  // @895_50ffe0
  ecx = edx = 0;  // @896_50ffe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @897_50ffe0
  if ((eax & eax) == 0) goto L510ad2;  // @898_50ffe0
  eax = ((u32(STDCALL *)(void))(eax))();  // @899_50ffe0
  ecx = edx = 0;  // @900_50ffe0
  return eax;  // @901_50ffe0
  L510ad2:;
  __builtin_trap();  // @903_50ffe0
  L510ad3:;
  return eax;  // @905_50ffe0
}
PCREG(50ffe0, lifted_50ffe0);

extern "C" u32 THISCALL lifted_503770(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @0_503770
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_503770
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_503770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_503770
  esi = ecx;  // @4_503770
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @5_503770
  if (eax >= (u32)(60)) goto L5037a1;  // @6_503770
  { u32 v = (u32)((u32)(5256976)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @7_503770
  eax = (eax + 1);  // @8_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @9_503770
  goto L5037be;  // @10_503770
  L5037a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @13_503770
  ecx = edx = 0;  // @14_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_503770
  if ((eax & eax) == 0) goto L5037b8;  // @16_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @17_503770
  ecx = edx = 0;  // @18_503770
  goto L5037b9;  // @19_503770
  L5037b8:;
  __builtin_trap();  // @21_503770
  L5037b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @23_503770
  L5037be:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @25_503770
  if (eax >= (u32)(60)) goto L5037e0;  // @26_503770
  { u32 v = (u32)((u32)(5248336)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @27_503770
  eax = (eax + 1);  // @28_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @29_503770
  goto L5037ff;  // @30_503770
  L5037e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_503770
  ecx = esi;  // @33_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @34_503770
  ecx = edx = 0;  // @35_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_503770
  if ((eax & eax) == 0) goto L5037f9;  // @37_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_503770
  ecx = edx = 0;  // @39_503770
  goto L5037fa;  // @40_503770
  L5037f9:;
  __builtin_trap();  // @42_503770
  L5037fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @44_503770
  L5037ff:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @46_503770
  if (eax >= (u32)(60)) goto L503821;  // @47_503770
  { u32 v = (u32)((u32)(5249120)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @48_503770
  eax = (eax + 1);  // @49_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @50_503770
  goto L503840;  // @51_503770
  L503821:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_503770
  ecx = esi;  // @54_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @55_503770
  ecx = edx = 0;  // @56_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_503770
  if ((eax & eax) == 0) goto L50383a;  // @58_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_503770
  ecx = edx = 0;  // @60_503770
  goto L50383b;  // @61_503770
  L50383a:;
  __builtin_trap();  // @63_503770
  L50383b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @65_503770
  L503840:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @67_503770
  if (eax >= (u32)(60)) goto L503862;  // @68_503770
  { u32 v = (u32)((u32)(5256816)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @69_503770
  eax = (eax + 1);  // @70_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @71_503770
  goto L503881;  // @72_503770
  L503862:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_503770
  ecx = esi;  // @75_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @76_503770
  ecx = edx = 0;  // @77_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @78_503770
  if ((eax & eax) == 0) goto L50387b;  // @79_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_503770
  ecx = edx = 0;  // @81_503770
  goto L50387c;  // @82_503770
  L50387b:;
  __builtin_trap();  // @84_503770
  L50387c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @86_503770
  L503881:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @88_503770
  if (eax >= (u32)(60)) goto L5038a3;  // @89_503770
  { u32 v = (u32)((u32)(5256432)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @90_503770
  eax = (eax + 1);  // @91_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @92_503770
  goto L5038c2;  // @93_503770
  L5038a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_503770
  ecx = esi;  // @96_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @97_503770
  ecx = edx = 0;  // @98_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @99_503770
  if ((eax & eax) == 0) goto L5038bc;  // @100_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @101_503770
  ecx = edx = 0;  // @102_503770
  goto L5038bd;  // @103_503770
  L5038bc:;
  __builtin_trap();  // @105_503770
  L5038bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @107_503770
  L5038c2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @109_503770
  if (eax >= (u32)(60)) goto L5038e4;  // @110_503770
  { u32 v = (u32)((u32)(5256608)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @111_503770
  eax = (eax + 1);  // @112_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @113_503770
  goto L503903;  // @114_503770
  L5038e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_503770
  ecx = esi;  // @117_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @118_503770
  ecx = edx = 0;  // @119_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @120_503770
  if ((eax & eax) == 0) goto L5038fd;  // @121_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @122_503770
  ecx = edx = 0;  // @123_503770
  goto L5038fe;  // @124_503770
  L5038fd:;
  __builtin_trap();  // @126_503770
  L5038fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @128_503770
  L503903:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @130_503770
  if (eax >= (u32)(60)) goto L503925;  // @131_503770
  { u32 v = (u32)((u32)(5248800)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @132_503770
  eax = (eax + 1);  // @133_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @134_503770
  goto L503944;  // @135_503770
  L503925:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_503770
  ecx = esi;  // @138_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @139_503770
  ecx = edx = 0;  // @140_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @141_503770
  if ((eax & eax) == 0) goto L50393e;  // @142_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @143_503770
  ecx = edx = 0;  // @144_503770
  goto L50393f;  // @145_503770
  L50393e:;
  __builtin_trap();  // @147_503770
  L50393f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @149_503770
  L503944:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @151_503770
  if (eax >= (u32)(60)) goto L503966;  // @152_503770
  { u32 v = (u32)((u32)(5249504)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @153_503770
  eax = (eax + 1);  // @154_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @155_503770
  goto L503985;  // @156_503770
  L503966:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_503770
  ecx = esi;  // @159_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @160_503770
  ecx = edx = 0;  // @161_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @162_503770
  if ((eax & eax) == 0) goto L50397f;  // @163_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @164_503770
  ecx = edx = 0;  // @165_503770
  goto L503980;  // @166_503770
  L50397f:;
  __builtin_trap();  // @168_503770
  L503980:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @170_503770
  L503985:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @172_503770
  if (eax >= (u32)(60)) goto L5039a7;  // @173_503770
  { u32 v = (u32)((u32)(5246128)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @174_503770
  eax = (eax + 1);  // @175_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @176_503770
  goto L5039c6;  // @177_503770
  L5039a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_503770
  ecx = esi;  // @180_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @181_503770
  ecx = edx = 0;  // @182_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @183_503770
  if ((eax & eax) == 0) goto L5039c0;  // @184_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @185_503770
  ecx = edx = 0;  // @186_503770
  goto L5039c1;  // @187_503770
  L5039c0:;
  __builtin_trap();  // @189_503770
  L5039c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @191_503770
  L5039c6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @193_503770
  if (eax >= (u32)(60)) goto L5039e8;  // @194_503770
  { u32 v = (u32)((u32)(5245520)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @195_503770
  eax = (eax + 1);  // @196_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @197_503770
  goto L503a07;  // @198_503770
  L5039e8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_503770
  ecx = esi;  // @201_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @202_503770
  ecx = edx = 0;  // @203_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_503770
  if ((eax & eax) == 0) goto L503a01;  // @205_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @206_503770
  ecx = edx = 0;  // @207_503770
  goto L503a02;  // @208_503770
  L503a01:;
  __builtin_trap();  // @210_503770
  L503a02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @212_503770
  L503a07:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @214_503770
  if (eax >= (u32)(60)) goto L503a29;  // @215_503770
  { u32 v = (u32)((u32)(5247632)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @216_503770
  eax = (eax + 1);  // @217_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @218_503770
  goto L503a48;  // @219_503770
  L503a29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_503770
  ecx = esi;  // @222_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @223_503770
  ecx = edx = 0;  // @224_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @225_503770
  if ((eax & eax) == 0) goto L503a42;  // @226_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @227_503770
  ecx = edx = 0;  // @228_503770
  goto L503a43;  // @229_503770
  L503a42:;
  __builtin_trap();  // @231_503770
  L503a43:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @233_503770
  L503a48:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @235_503770
  if (eax >= (u32)(60)) goto L503a6a;  // @236_503770
  { u32 v = (u32)((u32)(5248048)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @237_503770
  eax = (eax + 1);  // @238_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @239_503770
  goto L503a89;  // @240_503770
  L503a6a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_503770
  ecx = esi;  // @243_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @244_503770
  ecx = edx = 0;  // @245_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @246_503770
  if ((eax & eax) == 0) goto L503a83;  // @247_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @248_503770
  ecx = edx = 0;  // @249_503770
  goto L503a84;  // @250_503770
  L503a83:;
  __builtin_trap();  // @252_503770
  L503a84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @254_503770
  L503a89:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @256_503770
  if (eax >= (u32)(60)) goto L503aab;  // @257_503770
  { u32 v = (u32)((u32)(5247056)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @258_503770
  eax = (eax + 1);  // @259_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @260_503770
  goto L503aca;  // @261_503770
  L503aab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @263_503770
  ecx = esi;  // @264_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @265_503770
  ecx = edx = 0;  // @266_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @267_503770
  if ((eax & eax) == 0) goto L503ac4;  // @268_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @269_503770
  ecx = edx = 0;  // @270_503770
  goto L503ac5;  // @271_503770
  L503ac4:;
  __builtin_trap();  // @273_503770
  L503ac5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @275_503770
  L503aca:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @277_503770
  if (eax >= (u32)(60)) goto L503aec;  // @278_503770
  { u32 v = (u32)((u32)(5247216)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @279_503770
  eax = (eax + 1);  // @280_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @281_503770
  goto L503b0b;  // @282_503770
  L503aec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @284_503770
  ecx = esi;  // @285_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @286_503770
  ecx = edx = 0;  // @287_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @288_503770
  if ((eax & eax) == 0) goto L503b05;  // @289_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @290_503770
  ecx = edx = 0;  // @291_503770
  goto L503b06;  // @292_503770
  L503b05:;
  __builtin_trap();  // @294_503770
  L503b06:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @296_503770
  L503b0b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @298_503770
  if (eax >= (u32)(60)) goto L503b2d;  // @299_503770
  { u32 v = (u32)((u32)(5250784)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @300_503770
  eax = (eax + 1);  // @301_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @302_503770
  goto L503b4c;  // @303_503770
  L503b2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @305_503770
  ecx = esi;  // @306_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @307_503770
  ecx = edx = 0;  // @308_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @309_503770
  if ((eax & eax) == 0) goto L503b46;  // @310_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @311_503770
  ecx = edx = 0;  // @312_503770
  goto L503b47;  // @313_503770
  L503b46:;
  __builtin_trap();  // @315_503770
  L503b47:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @317_503770
  L503b4c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @319_503770
  if (eax >= (u32)(60)) goto L503b6e;  // @320_503770
  { u32 v = (u32)((u32)(5250624)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @321_503770
  eax = (eax + 1);  // @322_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @323_503770
  goto L503b8d;  // @324_503770
  L503b6e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_503770
  ecx = esi;  // @327_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @328_503770
  ecx = edx = 0;  // @329_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @330_503770
  if ((eax & eax) == 0) goto L503b87;  // @331_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @332_503770
  ecx = edx = 0;  // @333_503770
  goto L503b88;  // @334_503770
  L503b87:;
  __builtin_trap();  // @336_503770
  L503b88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @338_503770
  L503b8d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @340_503770
  if (eax >= (u32)(60)) goto L503baf;  // @341_503770
  { u32 v = (u32)((u32)(5250464)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @342_503770
  eax = (eax + 1);  // @343_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @344_503770
  goto L503bce;  // @345_503770
  L503baf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @347_503770
  ecx = esi;  // @348_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @349_503770
  ecx = edx = 0;  // @350_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @351_503770
  if ((eax & eax) == 0) goto L503bc8;  // @352_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @353_503770
  ecx = edx = 0;  // @354_503770
  goto L503bc9;  // @355_503770
  L503bc8:;
  __builtin_trap();  // @357_503770
  L503bc9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @359_503770
  L503bce:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @361_503770
  if (eax >= (u32)(60)) goto L503bf0;  // @362_503770
  { u32 v = (u32)((u32)(5250256)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @363_503770
  eax = (eax + 1);  // @364_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @365_503770
  goto L503c0f;  // @366_503770
  L503bf0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @368_503770
  ecx = esi;  // @369_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @370_503770
  ecx = edx = 0;  // @371_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @372_503770
  if ((eax & eax) == 0) goto L503c09;  // @373_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @374_503770
  ecx = edx = 0;  // @375_503770
  goto L503c0a;  // @376_503770
  L503c09:;
  __builtin_trap();  // @378_503770
  L503c0a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @380_503770
  L503c0f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @382_503770
  if (eax >= (u32)(60)) goto L503c31;  // @383_503770
  { u32 v = (u32)((u32)(5249072)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @384_503770
  eax = (eax + 1);  // @385_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @386_503770
  goto L503c50;  // @387_503770
  L503c31:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @389_503770
  ecx = esi;  // @390_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @391_503770
  ecx = edx = 0;  // @392_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @393_503770
  if ((eax & eax) == 0) goto L503c4a;  // @394_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @395_503770
  ecx = edx = 0;  // @396_503770
  goto L503c4b;  // @397_503770
  L503c4a:;
  __builtin_trap();  // @399_503770
  L503c4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @401_503770
  L503c50:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @403_503770
  if (eax >= (u32)(60)) goto L503c72;  // @404_503770
  { u32 v = (u32)((u32)(5248784)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @405_503770
  eax = (eax + 1);  // @406_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @407_503770
  goto L503c91;  // @408_503770
  L503c72:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_503770
  ecx = esi;  // @411_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @412_503770
  ecx = edx = 0;  // @413_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @414_503770
  if ((eax & eax) == 0) goto L503c8b;  // @415_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @416_503770
  ecx = edx = 0;  // @417_503770
  goto L503c8c;  // @418_503770
  L503c8b:;
  __builtin_trap();  // @420_503770
  L503c8c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @422_503770
  L503c91:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @424_503770
  if (eax >= (u32)(60)) goto L503cb3;  // @425_503770
  { u32 v = (u32)((u32)(5248768)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @426_503770
  eax = (eax + 1);  // @427_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @428_503770
  goto L503cd2;  // @429_503770
  L503cb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_503770
  ecx = esi;  // @432_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @433_503770
  ecx = edx = 0;  // @434_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @435_503770
  if ((eax & eax) == 0) goto L503ccc;  // @436_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @437_503770
  ecx = edx = 0;  // @438_503770
  goto L503ccd;  // @439_503770
  L503ccc:;
  __builtin_trap();  // @441_503770
  L503ccd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @443_503770
  L503cd2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @445_503770
  if (eax >= (u32)(60)) goto L503cf4;  // @446_503770
  { u32 v = (u32)((u32)(5246656)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @447_503770
  eax = (eax + 1);  // @448_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @449_503770
  goto L503d13;  // @450_503770
  L503cf4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @452_503770
  ecx = esi;  // @453_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @454_503770
  ecx = edx = 0;  // @455_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @456_503770
  if ((eax & eax) == 0) goto L503d0d;  // @457_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @458_503770
  ecx = edx = 0;  // @459_503770
  goto L503d0e;  // @460_503770
  L503d0d:;
  __builtin_trap();  // @462_503770
  L503d0e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @464_503770
  L503d13:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @466_503770
  if (eax >= (u32)(60)) goto L503d35;  // @467_503770
  { u32 v = (u32)((u32)(5246640)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @468_503770
  eax = (eax + 1);  // @469_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @470_503770
  goto L503d54;  // @471_503770
  L503d35:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_503770
  ecx = esi;  // @474_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @475_503770
  ecx = edx = 0;  // @476_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @477_503770
  if ((eax & eax) == 0) goto L503d4e;  // @478_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @479_503770
  ecx = edx = 0;  // @480_503770
  goto L503d4f;  // @481_503770
  L503d4e:;
  __builtin_trap();  // @483_503770
  L503d4f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @485_503770
  L503d54:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @487_503770
  if (eax >= (u32)(60)) goto L503d76;  // @488_503770
  { u32 v = (u32)((u32)(5250944)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @489_503770
  eax = (eax + 1);  // @490_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @491_503770
  goto L503d95;  // @492_503770
  L503d76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @494_503770
  ecx = esi;  // @495_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @496_503770
  ecx = edx = 0;  // @497_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @498_503770
  if ((eax & eax) == 0) goto L503d8f;  // @499_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @500_503770
  ecx = edx = 0;  // @501_503770
  goto L503d90;  // @502_503770
  L503d8f:;
  __builtin_trap();  // @504_503770
  L503d90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @506_503770
  L503d95:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @508_503770
  if (eax >= (u32)(60)) goto L503db7;  // @509_503770
  { u32 v = (u32)((u32)(5251808)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @510_503770
  eax = (eax + 1);  // @511_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @512_503770
  goto L503dd6;  // @513_503770
  L503db7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_503770
  ecx = esi;  // @516_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @517_503770
  ecx = edx = 0;  // @518_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @519_503770
  if ((eax & eax) == 0) goto L503dd0;  // @520_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @521_503770
  ecx = edx = 0;  // @522_503770
  goto L503dd1;  // @523_503770
  L503dd0:;
  __builtin_trap();  // @525_503770
  L503dd1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @527_503770
  L503dd6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @529_503770
  if (eax >= (u32)(60)) goto L503df8;  // @530_503770
  { u32 v = (u32)((u32)(5251808)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @531_503770
  eax = (eax + 1);  // @532_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @533_503770
  goto L503e17;  // @534_503770
  L503df8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @536_503770
  ecx = esi;  // @537_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @538_503770
  ecx = edx = 0;  // @539_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @540_503770
  if ((eax & eax) == 0) goto L503e11;  // @541_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @542_503770
  ecx = edx = 0;  // @543_503770
  goto L503e12;  // @544_503770
  L503e11:;
  __builtin_trap();  // @546_503770
  L503e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @548_503770
  L503e17:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @550_503770
  if (eax >= (u32)(60)) goto L503e39;  // @551_503770
  { u32 v = (u32)((u32)(5252496)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @552_503770
  eax = (eax + 1);  // @553_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @554_503770
  goto L503e58;  // @555_503770
  L503e39:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_503770
  ecx = esi;  // @558_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @559_503770
  ecx = edx = 0;  // @560_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @561_503770
  if ((eax & eax) == 0) goto L503e52;  // @562_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @563_503770
  ecx = edx = 0;  // @564_503770
  goto L503e53;  // @565_503770
  L503e52:;
  __builtin_trap();  // @567_503770
  L503e53:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @569_503770
  L503e58:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @571_503770
  if (eax >= (u32)(60)) goto L503e7a;  // @572_503770
  { u32 v = (u32)((u32)(5252496)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @573_503770
  eax = (eax + 1);  // @574_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @575_503770
  goto L503e99;  // @576_503770
  L503e7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @578_503770
  ecx = esi;  // @579_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @580_503770
  ecx = edx = 0;  // @581_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @582_503770
  if ((eax & eax) == 0) goto L503e93;  // @583_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @584_503770
  ecx = edx = 0;  // @585_503770
  goto L503e94;  // @586_503770
  L503e93:;
  __builtin_trap();  // @588_503770
  L503e94:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @590_503770
  L503e99:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @592_503770
  if (eax >= (u32)(60)) goto L503ebb;  // @593_503770
  { u32 v = (u32)((u32)(5252496)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @594_503770
  eax = (eax + 1);  // @595_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @596_503770
  goto L503eda;  // @597_503770
  L503ebb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @599_503770
  ecx = esi;  // @600_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @601_503770
  ecx = edx = 0;  // @602_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @603_503770
  if ((eax & eax) == 0) goto L503ed4;  // @604_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @605_503770
  ecx = edx = 0;  // @606_503770
  goto L503ed5;  // @607_503770
  L503ed4:;
  __builtin_trap();  // @609_503770
  L503ed5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @611_503770
  L503eda:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @613_503770
  if (eax >= (u32)(60)) goto L503efc;  // @614_503770
  { u32 v = (u32)((u32)(5252016)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @615_503770
  eax = (eax + 1);  // @616_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @617_503770
  goto L503f1b;  // @618_503770
  L503efc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @620_503770
  ecx = esi;  // @621_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @622_503770
  ecx = edx = 0;  // @623_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @624_503770
  if ((eax & eax) == 0) goto L503f15;  // @625_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @626_503770
  ecx = edx = 0;  // @627_503770
  goto L503f16;  // @628_503770
  L503f15:;
  __builtin_trap();  // @630_503770
  L503f16:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @632_503770
  L503f1b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @634_503770
  if (eax >= (u32)(60)) goto L503f3d;  // @635_503770
  { u32 v = (u32)((u32)(5252240)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @636_503770
  eax = (eax + 1);  // @637_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @638_503770
  goto L503f5c;  // @639_503770
  L503f3d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @641_503770
  ecx = esi;  // @642_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @643_503770
  ecx = edx = 0;  // @644_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @645_503770
  if ((eax & eax) == 0) goto L503f56;  // @646_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @647_503770
  ecx = edx = 0;  // @648_503770
  goto L503f57;  // @649_503770
  L503f56:;
  __builtin_trap();  // @651_503770
  L503f57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @653_503770
  L503f5c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @655_503770
  if (eax >= (u32)(60)) goto L503f7e;  // @656_503770
  { u32 v = (u32)((u32)(5251328)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @657_503770
  eax = (eax + 1);  // @658_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @659_503770
  goto L503f9d;  // @660_503770
  L503f7e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @662_503770
  ecx = esi;  // @663_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @664_503770
  ecx = edx = 0;  // @665_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @666_503770
  if ((eax & eax) == 0) goto L503f97;  // @667_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @668_503770
  ecx = edx = 0;  // @669_503770
  goto L503f98;  // @670_503770
  L503f97:;
  __builtin_trap();  // @672_503770
  L503f98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @674_503770
  L503f9d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @676_503770
  if (eax >= (u32)(60)) goto L503fbf;  // @677_503770
  { u32 v = (u32)((u32)(5251536)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @678_503770
  eax = (eax + 1);  // @679_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @680_503770
  goto L503fde;  // @681_503770
  L503fbf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @683_503770
  ecx = esi;  // @684_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @685_503770
  ecx = edx = 0;  // @686_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @687_503770
  if ((eax & eax) == 0) goto L503fd8;  // @688_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @689_503770
  ecx = edx = 0;  // @690_503770
  goto L503fd9;  // @691_503770
  L503fd8:;
  __builtin_trap();  // @693_503770
  L503fd9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @695_503770
  L503fde:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @697_503770
  if (eax >= (u32)(60)) goto L504000;  // @698_503770
  { u32 v = (u32)((u32)(5253344)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @699_503770
  eax = (eax + 1);  // @700_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @701_503770
  goto L50401f;  // @702_503770
  L504000:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @704_503770
  ecx = esi;  // @705_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @706_503770
  ecx = edx = 0;  // @707_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @708_503770
  if ((eax & eax) == 0) goto L504019;  // @709_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @710_503770
  ecx = edx = 0;  // @711_503770
  goto L50401a;  // @712_503770
  L504019:;
  __builtin_trap();  // @714_503770
  L50401a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @716_503770
  L50401f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @718_503770
  if (eax >= (u32)(60)) goto L504041;  // @719_503770
  { u32 v = (u32)((u32)(5253040)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @720_503770
  eax = (eax + 1);  // @721_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @722_503770
  goto L504060;  // @723_503770
  L504041:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @725_503770
  ecx = esi;  // @726_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @727_503770
  ecx = edx = 0;  // @728_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @729_503770
  if ((eax & eax) == 0) goto L50405a;  // @730_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @731_503770
  ecx = edx = 0;  // @732_503770
  goto L50405b;  // @733_503770
  L50405a:;
  __builtin_trap();  // @735_503770
  L50405b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @737_503770
  L504060:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @739_503770
  if (eax >= (u32)(60)) goto L504082;  // @740_503770
  { u32 v = (u32)((u32)(5252720)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @741_503770
  eax = (eax + 1);  // @742_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @743_503770
  goto L5040a1;  // @744_503770
  L504082:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @746_503770
  ecx = esi;  // @747_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @748_503770
  ecx = edx = 0;  // @749_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @750_503770
  if ((eax & eax) == 0) goto L50409b;  // @751_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @752_503770
  ecx = edx = 0;  // @753_503770
  goto L50409c;  // @754_503770
  L50409b:;
  __builtin_trap();  // @756_503770
  L50409c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @758_503770
  L5040a1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @760_503770
  if (eax >= (u32)(60)) goto L5040c3;  // @761_503770
  { u32 v = (u32)((u32)(5251120)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @762_503770
  eax = (eax + 1);  // @763_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @764_503770
  goto L5040e2;  // @765_503770
  L5040c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @767_503770
  ecx = esi;  // @768_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @769_503770
  ecx = edx = 0;  // @770_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @771_503770
  if ((eax & eax) == 0) goto L5040dc;  // @772_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @773_503770
  ecx = edx = 0;  // @774_503770
  goto L5040dd;  // @775_503770
  L5040dc:;
  __builtin_trap();  // @777_503770
  L5040dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @779_503770
  L5040e2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @781_503770
  if (eax >= (u32)(60)) goto L504104;  // @782_503770
  { u32 v = (u32)((u32)(5253632)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @783_503770
  eax = (eax + 1);  // @784_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @785_503770
  goto L504123;  // @786_503770
  L504104:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @788_503770
  ecx = esi;  // @789_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @790_503770
  ecx = edx = 0;  // @791_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @792_503770
  if ((eax & eax) == 0) goto L50411d;  // @793_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @794_503770
  ecx = edx = 0;  // @795_503770
  goto L50411e;  // @796_503770
  L50411d:;
  __builtin_trap();  // @798_503770
  L50411e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @800_503770
  L504123:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @802_503770
  if (eax >= (u32)(60)) goto L504145;  // @803_503770
  { u32 v = (u32)((u32)(5254704)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @804_503770
  eax = (eax + 1);  // @805_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @806_503770
  goto L504164;  // @807_503770
  L504145:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @809_503770
  ecx = esi;  // @810_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @811_503770
  ecx = edx = 0;  // @812_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @813_503770
  if ((eax & eax) == 0) goto L50415e;  // @814_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @815_503770
  ecx = edx = 0;  // @816_503770
  goto L50415f;  // @817_503770
  L50415e:;
  __builtin_trap();  // @819_503770
  L50415f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @821_503770
  L504164:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @823_503770
  if (eax >= (u32)(60)) goto L504186;  // @824_503770
  { u32 v = (u32)((u32)(5254704)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @825_503770
  eax = (eax + 1);  // @826_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @827_503770
  goto L5041a5;  // @828_503770
  L504186:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @830_503770
  ecx = esi;  // @831_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @832_503770
  ecx = edx = 0;  // @833_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @834_503770
  if ((eax & eax) == 0) goto L50419f;  // @835_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @836_503770
  ecx = edx = 0;  // @837_503770
  goto L5041a0;  // @838_503770
  L50419f:;
  __builtin_trap();  // @840_503770
  L5041a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @842_503770
  L5041a5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @844_503770
  if (eax >= (u32)(60)) goto L5041c7;  // @845_503770
  { u32 v = (u32)((u32)(5256272)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @846_503770
  eax = (eax + 1);  // @847_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @848_503770
  goto L5041e6;  // @849_503770
  L5041c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @851_503770
  ecx = esi;  // @852_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @853_503770
  ecx = edx = 0;  // @854_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @855_503770
  if ((eax & eax) == 0) goto L5041e0;  // @856_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @857_503770
  ecx = edx = 0;  // @858_503770
  goto L5041e1;  // @859_503770
  L5041e0:;
  __builtin_trap();  // @861_503770
  L5041e1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @863_503770
  L5041e6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @865_503770
  if (eax >= (u32)(60)) goto L504208;  // @866_503770
  { u32 v = (u32)((u32)(5254912)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @867_503770
  eax = (eax + 1);  // @868_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @869_503770
  goto L504227;  // @870_503770
  L504208:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @872_503770
  ecx = esi;  // @873_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @874_503770
  ecx = edx = 0;  // @875_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @876_503770
  if ((eax & eax) == 0) goto L504221;  // @877_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @878_503770
  ecx = edx = 0;  // @879_503770
  goto L504222;  // @880_503770
  L504221:;
  __builtin_trap();  // @882_503770
  L504222:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @884_503770
  L504227:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @886_503770
  if (eax >= (u32)(60)) goto L504249;  // @887_503770
  { u32 v = (u32)((u32)(5254912)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @888_503770
  eax = (eax + 1);  // @889_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @890_503770
  goto L504268;  // @891_503770
  L504249:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @893_503770
  ecx = esi;  // @894_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @895_503770
  ecx = edx = 0;  // @896_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @897_503770
  if ((eax & eax) == 0) goto L504262;  // @898_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @899_503770
  ecx = edx = 0;  // @900_503770
  goto L504263;  // @901_503770
  L504262:;
  __builtin_trap();  // @903_503770
  L504263:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @905_503770
  L504268:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @907_503770
  if (eax >= (u32)(60)) goto L50428a;  // @908_503770
  { u32 v = (u32)((u32)(5254912)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @909_503770
  eax = (eax + 1);  // @910_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @911_503770
  goto L5042a9;  // @912_503770
  L50428a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @914_503770
  ecx = esi;  // @915_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @916_503770
  ecx = edx = 0;  // @917_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @918_503770
  if ((eax & eax) == 0) goto L5042a3;  // @919_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @920_503770
  ecx = edx = 0;  // @921_503770
  goto L5042a4;  // @922_503770
  L5042a3:;
  __builtin_trap();  // @924_503770
  L5042a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @926_503770
  L5042a9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @928_503770
  if (eax >= (u32)(60)) goto L5042cb;  // @929_503770
  { u32 v = (u32)((u32)(5255136)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @930_503770
  eax = (eax + 1);  // @931_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @932_503770
  goto L5042ea;  // @933_503770
  L5042cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @935_503770
  ecx = esi;  // @936_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @937_503770
  ecx = edx = 0;  // @938_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @939_503770
  if ((eax & eax) == 0) goto L5042e4;  // @940_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @941_503770
  ecx = edx = 0;  // @942_503770
  goto L5042e5;  // @943_503770
  L5042e4:;
  __builtin_trap();  // @945_503770
  L5042e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @947_503770
  L5042ea:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @949_503770
  if (eax >= (u32)(60)) goto L50430c;  // @950_503770
  { u32 v = (u32)((u32)(5255408)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @951_503770
  eax = (eax + 1);  // @952_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @953_503770
  goto L50432b;  // @954_503770
  L50430c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @956_503770
  ecx = esi;  // @957_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @958_503770
  ecx = edx = 0;  // @959_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @960_503770
  if ((eax & eax) == 0) goto L504325;  // @961_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @962_503770
  ecx = edx = 0;  // @963_503770
  goto L504326;  // @964_503770
  L504325:;
  __builtin_trap();  // @966_503770
  L504326:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @968_503770
  L50432b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @970_503770
  if (eax >= (u32)(60)) goto L50434d;  // @971_503770
  { u32 v = (u32)((u32)(5255680)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @972_503770
  eax = (eax + 1);  // @973_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @974_503770
  goto L50436c;  // @975_503770
  L50434d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @977_503770
  ecx = esi;  // @978_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @979_503770
  ecx = edx = 0;  // @980_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @981_503770
  if ((eax & eax) == 0) goto L504366;  // @982_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @983_503770
  ecx = edx = 0;  // @984_503770
  goto L504367;  // @985_503770
  L504366:;
  __builtin_trap();  // @987_503770
  L504367:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @989_503770
  L50436c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @991_503770
  if (eax >= (u32)(60)) goto L50438e;  // @992_503770
  { u32 v = (u32)((u32)(5255984)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @993_503770
  eax = (eax + 1);  // @994_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @995_503770
  goto L5043ad;  // @996_503770
  L50438e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @998_503770
  ecx = esi;  // @999_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1000_503770
  ecx = edx = 0;  // @1001_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1002_503770
  if ((eax & eax) == 0) goto L5043a7;  // @1003_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1004_503770
  ecx = edx = 0;  // @1005_503770
  goto L5043a8;  // @1006_503770
  L5043a7:;
  __builtin_trap();  // @1008_503770
  L5043a8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1010_503770
  L5043ad:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1012_503770
  if (eax >= (u32)(60)) goto L5043cf;  // @1013_503770
  { u32 v = (u32)((u32)(5254048)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1014_503770
  eax = (eax + 1);  // @1015_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1016_503770
  goto L5043ee;  // @1017_503770
  L5043cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1019_503770
  ecx = esi;  // @1020_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1021_503770
  ecx = edx = 0;  // @1022_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1023_503770
  if ((eax & eax) == 0) goto L5043e8;  // @1024_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1025_503770
  ecx = edx = 0;  // @1026_503770
  goto L5043e9;  // @1027_503770
  L5043e8:;
  __builtin_trap();  // @1029_503770
  L5043e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1031_503770
  L5043ee:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1033_503770
  if (eax >= (u32)(60)) goto L504410;  // @1034_503770
  { u32 v = (u32)((u32)(5254336)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1035_503770
  eax = (eax + 1);  // @1036_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1037_503770
  goto L50442f;  // @1038_503770
  L504410:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1040_503770
  ecx = esi;  // @1041_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1042_503770
  ecx = edx = 0;  // @1043_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1044_503770
  if ((eax & eax) == 0) goto L504429;  // @1045_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1046_503770
  ecx = edx = 0;  // @1047_503770
  goto L50442a;  // @1048_503770
  L504429:;
  __builtin_trap();  // @1050_503770
  L50442a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1052_503770
  L50442f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1054_503770
  if (eax >= (u32)(60)) goto L50444d;  // @1055_503770
  { u32 v = (u32)((u32)(5253840)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1056_503770
  eax = (eax + 1);  // @1057_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1058_503770
  goto L50446c;  // @1059_503770
  L50444d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1061_503770
  ecx = esi;  // @1062_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1063_503770
  ecx = edx = 0;  // @1064_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1065_503770
  if ((eax & eax) == 0) goto L504466;  // @1066_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1067_503770
  ecx = edx = 0;  // @1068_503770
  goto L504467;  // @1069_503770
  L504466:;
  __builtin_trap();  // @1071_503770
  L504467:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; });  // @1073_503770
  L50446c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L5044ac;  // @1075_503770
  if (eax >= (u32)(60)) goto L50448e;  // @1076_503770
  { u32 v = (u32)((u32)(5246688)); __builtin_memcpy((void *)(u32)(eax*4 + 7343736), &v, sizeof v); }  // @1077_503770
  eax = (eax + 1);  // @1078_503770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7343728), &v, sizeof v); }  // @1079_503770
  return eax;  // @1080_503770
  L50448e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1082_503770
  ecx = esi;  // @1083_503770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6933000));  // @1084_503770
  ecx = edx = 0;  // @1085_503770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1086_503770
  if ((eax & eax) == 0) goto L5044ab;  // @1087_503770
  eax = ((u32(STDCALL *)(void))(eax))();  // @1088_503770
  ecx = edx = 0;  // @1089_503770
  return eax;  // @1090_503770
  L5044ab:;
  __builtin_trap();  // @1092_503770
  L5044ac:;
  return eax;  // @1094_503770
}
PCREG(503770, lifted_503770);

extern "C" u32 THISCALL lifted_508680(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @0_508680
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_508680
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_508680
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_508680
  esi = ecx;  // @4_508680
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @5_508680
  if (eax >= (u32)(53)) goto L5086b1;  // @6_508680
  { u32 v = (u32)((u32)(5277248)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @7_508680
  eax = (eax + 1);  // @8_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @9_508680
  goto L5086ce;  // @10_508680
  L5086b1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @13_508680
  ecx = edx = 0;  // @14_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_508680
  if ((eax & eax) == 0) goto L5086c8;  // @16_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @17_508680
  ecx = edx = 0;  // @18_508680
  goto L5086c9;  // @19_508680
  L5086c8:;
  __builtin_trap();  // @21_508680
  L5086c9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @23_508680
  L5086ce:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @25_508680
  if (eax >= (u32)(53)) goto L5086f0;  // @26_508680
  { u32 v = (u32)((u32)(5276304)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @27_508680
  eax = (eax + 1);  // @28_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @29_508680
  goto L50870f;  // @30_508680
  L5086f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_508680
  ecx = esi;  // @33_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @34_508680
  ecx = edx = 0;  // @35_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_508680
  if ((eax & eax) == 0) goto L508709;  // @37_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_508680
  ecx = edx = 0;  // @39_508680
  goto L50870a;  // @40_508680
  L508709:;
  __builtin_trap();  // @42_508680
  L50870a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @44_508680
  L50870f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @46_508680
  if (eax >= (u32)(53)) goto L508731;  // @47_508680
  { u32 v = (u32)((u32)(5270144)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @48_508680
  eax = (eax + 1);  // @49_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @50_508680
  goto L508750;  // @51_508680
  L508731:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_508680
  ecx = esi;  // @54_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @55_508680
  ecx = edx = 0;  // @56_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_508680
  if ((eax & eax) == 0) goto L50874a;  // @58_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_508680
  ecx = edx = 0;  // @60_508680
  goto L50874b;  // @61_508680
  L50874a:;
  __builtin_trap();  // @63_508680
  L50874b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @65_508680
  L508750:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @67_508680
  if (eax >= (u32)(53)) goto L508772;  // @68_508680
  { u32 v = (u32)((u32)(5275200)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @69_508680
  eax = (eax + 1);  // @70_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @71_508680
  goto L508791;  // @72_508680
  L508772:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_508680
  ecx = esi;  // @75_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @76_508680
  ecx = edx = 0;  // @77_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @78_508680
  if ((eax & eax) == 0) goto L50878b;  // @79_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_508680
  ecx = edx = 0;  // @81_508680
  goto L50878c;  // @82_508680
  L50878b:;
  __builtin_trap();  // @84_508680
  L50878c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @86_508680
  L508791:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @88_508680
  if (eax >= (u32)(53)) goto L5087b3;  // @89_508680
  { u32 v = (u32)((u32)(6514864)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @90_508680
  eax = (eax + 1);  // @91_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @92_508680
  goto L5087d2;  // @93_508680
  L5087b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_508680
  ecx = esi;  // @96_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @97_508680
  ecx = edx = 0;  // @98_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @99_508680
  if ((eax & eax) == 0) goto L5087cc;  // @100_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @101_508680
  ecx = edx = 0;  // @102_508680
  goto L5087cd;  // @103_508680
  L5087cc:;
  __builtin_trap();  // @105_508680
  L5087cd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @107_508680
  L5087d2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @109_508680
  if (eax >= (u32)(53)) goto L5087f4;  // @110_508680
  { u32 v = (u32)((u32)(5274720)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @111_508680
  eax = (eax + 1);  // @112_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @113_508680
  goto L508813;  // @114_508680
  L5087f4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_508680
  ecx = esi;  // @117_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @118_508680
  ecx = edx = 0;  // @119_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @120_508680
  if ((eax & eax) == 0) goto L50880d;  // @121_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @122_508680
  ecx = edx = 0;  // @123_508680
  goto L50880e;  // @124_508680
  L50880d:;
  __builtin_trap();  // @126_508680
  L50880e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @128_508680
  L508813:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @130_508680
  if (eax >= (u32)(53)) goto L508835;  // @131_508680
  { u32 v = (u32)((u32)(5275904)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @132_508680
  eax = (eax + 1);  // @133_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @134_508680
  goto L508854;  // @135_508680
  L508835:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_508680
  ecx = esi;  // @138_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @139_508680
  ecx = edx = 0;  // @140_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @141_508680
  if ((eax & eax) == 0) goto L50884e;  // @142_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @143_508680
  ecx = edx = 0;  // @144_508680
  goto L50884f;  // @145_508680
  L50884e:;
  __builtin_trap();  // @147_508680
  L50884f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @149_508680
  L508854:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @151_508680
  if (eax >= (u32)(53)) goto L508876;  // @152_508680
  { u32 v = (u32)((u32)(5275216)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @153_508680
  eax = (eax + 1);  // @154_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @155_508680
  goto L508895;  // @156_508680
  L508876:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_508680
  ecx = esi;  // @159_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @160_508680
  ecx = edx = 0;  // @161_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @162_508680
  if ((eax & eax) == 0) goto L50888f;  // @163_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @164_508680
  ecx = edx = 0;  // @165_508680
  goto L508890;  // @166_508680
  L50888f:;
  __builtin_trap();  // @168_508680
  L508890:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @170_508680
  L508895:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @172_508680
  if (eax >= (u32)(53)) goto L5088b7;  // @173_508680
  { u32 v = (u32)((u32)(5272432)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @174_508680
  eax = (eax + 1);  // @175_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @176_508680
  goto L5088d6;  // @177_508680
  L5088b7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_508680
  ecx = esi;  // @180_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @181_508680
  ecx = edx = 0;  // @182_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @183_508680
  if ((eax & eax) == 0) goto L5088d0;  // @184_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @185_508680
  ecx = edx = 0;  // @186_508680
  goto L5088d1;  // @187_508680
  L5088d0:;
  __builtin_trap();  // @189_508680
  L5088d1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @191_508680
  L5088d6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @193_508680
  if (eax >= (u32)(53)) goto L5088f8;  // @194_508680
  { u32 v = (u32)((u32)(5272608)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @195_508680
  eax = (eax + 1);  // @196_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @197_508680
  goto L508917;  // @198_508680
  L5088f8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_508680
  ecx = esi;  // @201_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @202_508680
  ecx = edx = 0;  // @203_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_508680
  if ((eax & eax) == 0) goto L508911;  // @205_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @206_508680
  ecx = edx = 0;  // @207_508680
  goto L508912;  // @208_508680
  L508911:;
  __builtin_trap();  // @210_508680
  L508912:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @212_508680
  L508917:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @214_508680
  if (eax >= (u32)(53)) goto L508939;  // @215_508680
  { u32 v = (u32)((u32)(5273136)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @216_508680
  eax = (eax + 1);  // @217_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @218_508680
  goto L508958;  // @219_508680
  L508939:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_508680
  ecx = esi;  // @222_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @223_508680
  ecx = edx = 0;  // @224_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @225_508680
  if ((eax & eax) == 0) goto L508952;  // @226_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @227_508680
  ecx = edx = 0;  // @228_508680
  goto L508953;  // @229_508680
  L508952:;
  __builtin_trap();  // @231_508680
  L508953:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @233_508680
  L508958:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @235_508680
  if (eax >= (u32)(53)) goto L50897a;  // @236_508680
  { u32 v = (u32)((u32)(5272848)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @237_508680
  eax = (eax + 1);  // @238_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @239_508680
  goto L508999;  // @240_508680
  L50897a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_508680
  ecx = esi;  // @243_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @244_508680
  ecx = edx = 0;  // @245_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @246_508680
  if ((eax & eax) == 0) goto L508993;  // @247_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @248_508680
  ecx = edx = 0;  // @249_508680
  goto L508994;  // @250_508680
  L508993:;
  __builtin_trap();  // @252_508680
  L508994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @254_508680
  L508999:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @256_508680
  if (eax >= (u32)(53)) goto L5089bb;  // @257_508680
  { u32 v = (u32)((u32)(5273360)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @258_508680
  eax = (eax + 1);  // @259_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @260_508680
  goto L5089da;  // @261_508680
  L5089bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @263_508680
  ecx = esi;  // @264_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @265_508680
  ecx = edx = 0;  // @266_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @267_508680
  if ((eax & eax) == 0) goto L5089d4;  // @268_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @269_508680
  ecx = edx = 0;  // @270_508680
  goto L5089d5;  // @271_508680
  L5089d4:;
  __builtin_trap();  // @273_508680
  L5089d5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @275_508680
  L5089da:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @277_508680
  if (eax >= (u32)(53)) goto L5089fc;  // @278_508680
  { u32 v = (u32)((u32)(5273616)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @279_508680
  eax = (eax + 1);  // @280_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @281_508680
  goto L508a1b;  // @282_508680
  L5089fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @284_508680
  ecx = esi;  // @285_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @286_508680
  ecx = edx = 0;  // @287_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @288_508680
  if ((eax & eax) == 0) goto L508a15;  // @289_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @290_508680
  ecx = edx = 0;  // @291_508680
  goto L508a16;  // @292_508680
  L508a15:;
  __builtin_trap();  // @294_508680
  L508a16:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @296_508680
  L508a1b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @298_508680
  if (eax >= (u32)(53)) goto L508a3d;  // @299_508680
  { u32 v = (u32)((u32)(5269856)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @300_508680
  eax = (eax + 1);  // @301_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @302_508680
  goto L508a5c;  // @303_508680
  L508a3d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @305_508680
  ecx = esi;  // @306_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @307_508680
  ecx = edx = 0;  // @308_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @309_508680
  if ((eax & eax) == 0) goto L508a56;  // @310_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @311_508680
  ecx = edx = 0;  // @312_508680
  goto L508a57;  // @313_508680
  L508a56:;
  __builtin_trap();  // @315_508680
  L508a57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @317_508680
  L508a5c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @319_508680
  if (eax >= (u32)(53)) goto L508a7e;  // @320_508680
  { u32 v = (u32)((u32)(5268432)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @321_508680
  eax = (eax + 1);  // @322_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @323_508680
  goto L508a9d;  // @324_508680
  L508a7e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_508680
  ecx = esi;  // @327_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @328_508680
  ecx = edx = 0;  // @329_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @330_508680
  if ((eax & eax) == 0) goto L508a97;  // @331_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @332_508680
  ecx = edx = 0;  // @333_508680
  goto L508a98;  // @334_508680
  L508a97:;
  __builtin_trap();  // @336_508680
  L508a98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @338_508680
  L508a9d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @340_508680
  if (eax >= (u32)(53)) goto L508abf;  // @341_508680
  { u32 v = (u32)((u32)(5269216)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @342_508680
  eax = (eax + 1);  // @343_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @344_508680
  goto L508ade;  // @345_508680
  L508abf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @347_508680
  ecx = esi;  // @348_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @349_508680
  ecx = edx = 0;  // @350_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @351_508680
  if ((eax & eax) == 0) goto L508ad8;  // @352_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @353_508680
  ecx = edx = 0;  // @354_508680
  goto L508ad9;  // @355_508680
  L508ad8:;
  __builtin_trap();  // @357_508680
  L508ad9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @359_508680
  L508ade:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @361_508680
  if (eax >= (u32)(53)) goto L508b00;  // @362_508680
  { u32 v = (u32)((u32)(5276144)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @363_508680
  eax = (eax + 1);  // @364_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @365_508680
  goto L508b1f;  // @366_508680
  L508b00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @368_508680
  ecx = esi;  // @369_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @370_508680
  ecx = edx = 0;  // @371_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @372_508680
  if ((eax & eax) == 0) goto L508b19;  // @373_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @374_508680
  ecx = edx = 0;  // @375_508680
  goto L508b1a;  // @376_508680
  L508b19:;
  __builtin_trap();  // @378_508680
  L508b1a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @380_508680
  L508b1f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @382_508680
  if (eax >= (u32)(53)) goto L508b41;  // @383_508680
  { u32 v = (u32)((u32)(5276624)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @384_508680
  eax = (eax + 1);  // @385_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @386_508680
  goto L508b60;  // @387_508680
  L508b41:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @389_508680
  ecx = esi;  // @390_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @391_508680
  ecx = edx = 0;  // @392_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @393_508680
  if ((eax & eax) == 0) goto L508b5a;  // @394_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @395_508680
  ecx = edx = 0;  // @396_508680
  goto L508b5b;  // @397_508680
  L508b5a:;
  __builtin_trap();  // @399_508680
  L508b5b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @401_508680
  L508b60:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @403_508680
  if (eax >= (u32)(53)) goto L508b82;  // @404_508680
  { u32 v = (u32)((u32)(5276032)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @405_508680
  eax = (eax + 1);  // @406_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @407_508680
  goto L508ba1;  // @408_508680
  L508b82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_508680
  ecx = esi;  // @411_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @412_508680
  ecx = edx = 0;  // @413_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @414_508680
  if ((eax & eax) == 0) goto L508b9b;  // @415_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @416_508680
  ecx = edx = 0;  // @417_508680
  goto L508b9c;  // @418_508680
  L508b9b:;
  __builtin_trap();  // @420_508680
  L508b9c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @422_508680
  L508ba1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @424_508680
  if (eax >= (u32)(53)) goto L508bc3;  // @425_508680
  { u32 v = (u32)((u32)(5276192)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @426_508680
  eax = (eax + 1);  // @427_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @428_508680
  goto L508be2;  // @429_508680
  L508bc3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_508680
  ecx = esi;  // @432_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @433_508680
  ecx = edx = 0;  // @434_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @435_508680
  if ((eax & eax) == 0) goto L508bdc;  // @436_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @437_508680
  ecx = edx = 0;  // @438_508680
  goto L508bdd;  // @439_508680
  L508bdc:;
  __builtin_trap();  // @441_508680
  L508bdd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @443_508680
  L508be2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @445_508680
  if (eax >= (u32)(53)) goto L508c04;  // @446_508680
  { u32 v = (u32)((u32)(5276256)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @447_508680
  eax = (eax + 1);  // @448_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @449_508680
  goto L508c23;  // @450_508680
  L508c04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @452_508680
  ecx = esi;  // @453_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @454_508680
  ecx = edx = 0;  // @455_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @456_508680
  if ((eax & eax) == 0) goto L508c1d;  // @457_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @458_508680
  ecx = edx = 0;  // @459_508680
  goto L508c1e;  // @460_508680
  L508c1d:;
  __builtin_trap();  // @462_508680
  L508c1e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @464_508680
  L508c23:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @466_508680
  if (eax >= (u32)(53)) goto L508c45;  // @467_508680
  { u32 v = (u32)((u32)(5275760)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @468_508680
  eax = (eax + 1);  // @469_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @470_508680
  goto L508c64;  // @471_508680
  L508c45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_508680
  ecx = esi;  // @474_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @475_508680
  ecx = edx = 0;  // @476_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @477_508680
  if ((eax & eax) == 0) goto L508c5e;  // @478_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @479_508680
  ecx = edx = 0;  // @480_508680
  goto L508c5f;  // @481_508680
  L508c5e:;
  __builtin_trap();  // @483_508680
  L508c5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @485_508680
  L508c64:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @487_508680
  if (eax >= (u32)(53)) goto L508c86;  // @488_508680
  { u32 v = (u32)((u32)(5274032)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @489_508680
  eax = (eax + 1);  // @490_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @491_508680
  goto L508ca5;  // @492_508680
  L508c86:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @494_508680
  ecx = esi;  // @495_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @496_508680
  ecx = edx = 0;  // @497_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @498_508680
  if ((eax & eax) == 0) goto L508c9f;  // @499_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @500_508680
  ecx = edx = 0;  // @501_508680
  goto L508ca0;  // @502_508680
  L508c9f:;
  __builtin_trap();  // @504_508680
  L508ca0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @506_508680
  L508ca5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @508_508680
  if (eax >= (u32)(53)) goto L508cc7;  // @509_508680
  { u32 v = (u32)((u32)(5276576)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @510_508680
  eax = (eax + 1);  // @511_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @512_508680
  goto L508ce6;  // @513_508680
  L508cc7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_508680
  ecx = esi;  // @516_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @517_508680
  ecx = edx = 0;  // @518_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @519_508680
  if ((eax & eax) == 0) goto L508ce0;  // @520_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @521_508680
  ecx = edx = 0;  // @522_508680
  goto L508ce1;  // @523_508680
  L508ce0:;
  __builtin_trap();  // @525_508680
  L508ce1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @527_508680
  L508ce6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @529_508680
  if (eax >= (u32)(53)) goto L508d08;  // @530_508680
  { u32 v = (u32)((u32)(5277216)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @531_508680
  eax = (eax + 1);  // @532_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @533_508680
  goto L508d27;  // @534_508680
  L508d08:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @536_508680
  ecx = esi;  // @537_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @538_508680
  ecx = edx = 0;  // @539_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @540_508680
  if ((eax & eax) == 0) goto L508d21;  // @541_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @542_508680
  ecx = edx = 0;  // @543_508680
  goto L508d22;  // @544_508680
  L508d21:;
  __builtin_trap();  // @546_508680
  L508d22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @548_508680
  L508d27:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @550_508680
  if (eax >= (u32)(53)) goto L508d49;  // @551_508680
  { u32 v = (u32)((u32)(5277024)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @552_508680
  eax = (eax + 1);  // @553_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @554_508680
  goto L508d68;  // @555_508680
  L508d49:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_508680
  ecx = esi;  // @558_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @559_508680
  ecx = edx = 0;  // @560_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @561_508680
  if ((eax & eax) == 0) goto L508d62;  // @562_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @563_508680
  ecx = edx = 0;  // @564_508680
  goto L508d63;  // @565_508680
  L508d62:;
  __builtin_trap();  // @567_508680
  L508d63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @569_508680
  L508d68:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @571_508680
  if (eax >= (u32)(53)) goto L508d8a;  // @572_508680
  { u32 v = (u32)((u32)(5277152)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @573_508680
  eax = (eax + 1);  // @574_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @575_508680
  goto L508da9;  // @576_508680
  L508d8a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @578_508680
  ecx = esi;  // @579_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @580_508680
  ecx = edx = 0;  // @581_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @582_508680
  if ((eax & eax) == 0) goto L508da3;  // @583_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @584_508680
  ecx = edx = 0;  // @585_508680
  goto L508da4;  // @586_508680
  L508da3:;
  __builtin_trap();  // @588_508680
  L508da4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @590_508680
  L508da9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @592_508680
  if (eax >= (u32)(53)) goto L508dcb;  // @593_508680
  { u32 v = (u32)((u32)(5276976)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @594_508680
  eax = (eax + 1);  // @595_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @596_508680
  goto L508dea;  // @597_508680
  L508dcb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @599_508680
  ecx = esi;  // @600_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @601_508680
  ecx = edx = 0;  // @602_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @603_508680
  if ((eax & eax) == 0) goto L508de4;  // @604_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @605_508680
  ecx = edx = 0;  // @606_508680
  goto L508de5;  // @607_508680
  L508de4:;
  __builtin_trap();  // @609_508680
  L508de5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @611_508680
  L508dea:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @613_508680
  if (eax >= (u32)(53)) goto L508e0c;  // @614_508680
  { u32 v = (u32)((u32)(5271168)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @615_508680
  eax = (eax + 1);  // @616_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @617_508680
  goto L508e2b;  // @618_508680
  L508e0c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @620_508680
  ecx = esi;  // @621_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @622_508680
  ecx = edx = 0;  // @623_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @624_508680
  if ((eax & eax) == 0) goto L508e25;  // @625_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @626_508680
  ecx = edx = 0;  // @627_508680
  goto L508e26;  // @628_508680
  L508e25:;
  __builtin_trap();  // @630_508680
  L508e26:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @632_508680
  L508e2b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @634_508680
  if (eax >= (u32)(53)) goto L508e4d;  // @635_508680
  { u32 v = (u32)((u32)(5270496)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @636_508680
  eax = (eax + 1);  // @637_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @638_508680
  goto L508e6c;  // @639_508680
  L508e4d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @641_508680
  ecx = esi;  // @642_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @643_508680
  ecx = edx = 0;  // @644_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @645_508680
  if ((eax & eax) == 0) goto L508e66;  // @646_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @647_508680
  ecx = edx = 0;  // @648_508680
  goto L508e67;  // @649_508680
  L508e66:;
  __builtin_trap();  // @651_508680
  L508e67:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @653_508680
  L508e6c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @655_508680
  if (eax >= (u32)(53)) goto L508e8e;  // @656_508680
  { u32 v = (u32)((u32)(5276096)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @657_508680
  eax = (eax + 1);  // @658_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @659_508680
  goto L508ead;  // @660_508680
  L508e8e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @662_508680
  ecx = esi;  // @663_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @664_508680
  ecx = edx = 0;  // @665_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @666_508680
  if ((eax & eax) == 0) goto L508ea7;  // @667_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @668_508680
  ecx = edx = 0;  // @669_508680
  goto L508ea8;  // @670_508680
  L508ea7:;
  __builtin_trap();  // @672_508680
  L508ea8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @674_508680
  L508ead:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @676_508680
  if (eax >= (u32)(53)) goto L508ecf;  // @677_508680
  { u32 v = (u32)((u32)(5270384)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @678_508680
  eax = (eax + 1);  // @679_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @680_508680
  goto L508eee;  // @681_508680
  L508ecf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @683_508680
  ecx = esi;  // @684_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @685_508680
  ecx = edx = 0;  // @686_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @687_508680
  if ((eax & eax) == 0) goto L508ee8;  // @688_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @689_508680
  ecx = edx = 0;  // @690_508680
  goto L508ee9;  // @691_508680
  L508ee8:;
  __builtin_trap();  // @693_508680
  L508ee9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @695_508680
  L508eee:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @697_508680
  if (eax >= (u32)(53)) goto L508f10;  // @698_508680
  { u32 v = (u32)((u32)(5270368)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @699_508680
  eax = (eax + 1);  // @700_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @701_508680
  goto L508f2f;  // @702_508680
  L508f10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @704_508680
  ecx = esi;  // @705_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @706_508680
  ecx = edx = 0;  // @707_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @708_508680
  if ((eax & eax) == 0) goto L508f29;  // @709_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @710_508680
  ecx = edx = 0;  // @711_508680
  goto L508f2a;  // @712_508680
  L508f29:;
  __builtin_trap();  // @714_508680
  L508f2a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @716_508680
  L508f2f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @718_508680
  if (eax >= (u32)(53)) goto L508f51;  // @719_508680
  { u32 v = (u32)((u32)(5272256)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @720_508680
  eax = (eax + 1);  // @721_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @722_508680
  goto L508f70;  // @723_508680
  L508f51:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @725_508680
  ecx = esi;  // @726_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @727_508680
  ecx = edx = 0;  // @728_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @729_508680
  if ((eax & eax) == 0) goto L508f6a;  // @730_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @731_508680
  ecx = edx = 0;  // @732_508680
  goto L508f6b;  // @733_508680
  L508f6a:;
  __builtin_trap();  // @735_508680
  L508f6b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @737_508680
  L508f70:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @739_508680
  if (eax >= (u32)(53)) goto L508f92;  // @740_508680
  { u32 v = (u32)((u32)(5272304)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @741_508680
  eax = (eax + 1);  // @742_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @743_508680
  goto L508fb1;  // @744_508680
  L508f92:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @746_508680
  ecx = esi;  // @747_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @748_508680
  ecx = edx = 0;  // @749_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @750_508680
  if ((eax & eax) == 0) goto L508fab;  // @751_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @752_508680
  ecx = edx = 0;  // @753_508680
  goto L508fac;  // @754_508680
  L508fab:;
  __builtin_trap();  // @756_508680
  L508fac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @758_508680
  L508fb1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @760_508680
  if (eax >= (u32)(53)) goto L508fd3;  // @761_508680
  { u32 v = (u32)((u32)(5275408)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @762_508680
  eax = (eax + 1);  // @763_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @764_508680
  goto L508ff2;  // @765_508680
  L508fd3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @767_508680
  ecx = esi;  // @768_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @769_508680
  ecx = edx = 0;  // @770_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @771_508680
  if ((eax & eax) == 0) goto L508fec;  // @772_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @773_508680
  ecx = edx = 0;  // @774_508680
  goto L508fed;  // @775_508680
  L508fec:;
  __builtin_trap();  // @777_508680
  L508fed:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @779_508680
  L508ff2:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @781_508680
  if (eax >= (u32)(53)) goto L509014;  // @782_508680
  { u32 v = (u32)((u32)(5268736)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @783_508680
  eax = (eax + 1);  // @784_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @785_508680
  goto L509033;  // @786_508680
  L509014:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @788_508680
  ecx = esi;  // @789_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @790_508680
  ecx = edx = 0;  // @791_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @792_508680
  if ((eax & eax) == 0) goto L50902d;  // @793_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @794_508680
  ecx = edx = 0;  // @795_508680
  goto L50902e;  // @796_508680
  L50902d:;
  __builtin_trap();  // @798_508680
  L50902e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @800_508680
  L509033:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @802_508680
  if (eax >= (u32)(53)) goto L509055;  // @803_508680
  { u32 v = (u32)((u32)(5268640)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @804_508680
  eax = (eax + 1);  // @805_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @806_508680
  goto L509074;  // @807_508680
  L509055:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @809_508680
  ecx = esi;  // @810_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @811_508680
  ecx = edx = 0;  // @812_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @813_508680
  if ((eax & eax) == 0) goto L50906e;  // @814_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @815_508680
  ecx = edx = 0;  // @816_508680
  goto L50906f;  // @817_508680
  L50906e:;
  __builtin_trap();  // @819_508680
  L50906f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @821_508680
  L509074:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @823_508680
  if (eax >= (u32)(53)) goto L509096;  // @824_508680
  { u32 v = (u32)((u32)(5271264)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @825_508680
  eax = (eax + 1);  // @826_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @827_508680
  goto L5090b5;  // @828_508680
  L509096:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @830_508680
  ecx = esi;  // @831_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @832_508680
  ecx = edx = 0;  // @833_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @834_508680
  if ((eax & eax) == 0) goto L5090af;  // @835_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @836_508680
  ecx = edx = 0;  // @837_508680
  goto L5090b0;  // @838_508680
  L5090af:;
  __builtin_trap();  // @840_508680
  L5090b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @842_508680
  L5090b5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @844_508680
  if (eax >= (u32)(53)) goto L5090d7;  // @845_508680
  { u32 v = (u32)((u32)(5270400)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @846_508680
  eax = (eax + 1);  // @847_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @848_508680
  goto L5090f6;  // @849_508680
  L5090d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @851_508680
  ecx = esi;  // @852_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @853_508680
  ecx = edx = 0;  // @854_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @855_508680
  if ((eax & eax) == 0) goto L5090f0;  // @856_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @857_508680
  ecx = edx = 0;  // @858_508680
  goto L5090f1;  // @859_508680
  L5090f0:;
  __builtin_trap();  // @861_508680
  L5090f1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @863_508680
  L5090f6:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @865_508680
  if (eax >= (u32)(53)) goto L509118;  // @866_508680
  { u32 v = (u32)((u32)(5270448)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @867_508680
  eax = (eax + 1);  // @868_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @869_508680
  goto L509137;  // @870_508680
  L509118:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @872_508680
  ecx = esi;  // @873_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @874_508680
  ecx = edx = 0;  // @875_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @876_508680
  if ((eax & eax) == 0) goto L509131;  // @877_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @878_508680
  ecx = edx = 0;  // @879_508680
  goto L509132;  // @880_508680
  L509131:;
  __builtin_trap();  // @882_508680
  L509132:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @884_508680
  L509137:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @886_508680
  if (eax >= (u32)(53)) goto L509159;  // @887_508680
  { u32 v = (u32)((u32)(5268384)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @888_508680
  eax = (eax + 1);  // @889_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @890_508680
  goto L509178;  // @891_508680
  L509159:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @893_508680
  ecx = esi;  // @894_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @895_508680
  ecx = edx = 0;  // @896_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @897_508680
  if ((eax & eax) == 0) goto L509172;  // @898_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @899_508680
  ecx = edx = 0;  // @900_508680
  goto L509173;  // @901_508680
  L509172:;
  __builtin_trap();  // @903_508680
  L509173:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @905_508680
  L509178:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @907_508680
  if (eax >= (u32)(53)) goto L50919a;  // @908_508680
  { u32 v = (u32)((u32)(5276832)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @909_508680
  eax = (eax + 1);  // @910_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @911_508680
  goto L5091b9;  // @912_508680
  L50919a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @914_508680
  ecx = esi;  // @915_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @916_508680
  ecx = edx = 0;  // @917_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @918_508680
  if ((eax & eax) == 0) goto L5091b3;  // @919_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @920_508680
  ecx = edx = 0;  // @921_508680
  goto L5091b4;  // @922_508680
  L5091b3:;
  __builtin_trap();  // @924_508680
  L5091b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @926_508680
  L5091b9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @928_508680
  if (eax >= (u32)(53)) goto L5091db;  // @929_508680
  { u32 v = (u32)((u32)(5276688)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @930_508680
  eax = (eax + 1);  // @931_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @932_508680
  goto L5091fa;  // @933_508680
  L5091db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @935_508680
  ecx = esi;  // @936_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @937_508680
  ecx = edx = 0;  // @938_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @939_508680
  if ((eax & eax) == 0) goto L5091f4;  // @940_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @941_508680
  ecx = edx = 0;  // @942_508680
  goto L5091f5;  // @943_508680
  L5091f4:;
  __builtin_trap();  // @945_508680
  L5091f5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @947_508680
  L5091fa:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @949_508680
  if (eax >= (u32)(53)) goto L50921c;  // @950_508680
  { u32 v = (u32)((u32)(5275808)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @951_508680
  eax = (eax + 1);  // @952_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @953_508680
  goto L50923b;  // @954_508680
  L50921c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @956_508680
  ecx = esi;  // @957_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @958_508680
  ecx = edx = 0;  // @959_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @960_508680
  if ((eax & eax) == 0) goto L509235;  // @961_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @962_508680
  ecx = edx = 0;  // @963_508680
  goto L509236;  // @964_508680
  L509235:;
  __builtin_trap();  // @966_508680
  L509236:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @968_508680
  L50923b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @970_508680
  if (eax >= (u32)(53)) goto L50925d;  // @971_508680
  { u32 v = (u32)((u32)(5274048)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @972_508680
  eax = (eax + 1);  // @973_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @974_508680
  goto L50927c;  // @975_508680
  L50925d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @977_508680
  ecx = esi;  // @978_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @979_508680
  ecx = edx = 0;  // @980_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @981_508680
  if ((eax & eax) == 0) goto L509276;  // @982_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @983_508680
  ecx = edx = 0;  // @984_508680
  goto L509277;  // @985_508680
  L509276:;
  __builtin_trap();  // @987_508680
  L509277:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @989_508680
  L50927c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @991_508680
  if (eax >= (u32)(53)) goto L50929e;  // @992_508680
  { u32 v = (u32)((u32)(5274432)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @993_508680
  eax = (eax + 1);  // @994_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @995_508680
  goto L5092bd;  // @996_508680
  L50929e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @998_508680
  ecx = esi;  // @999_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @1000_508680
  ecx = edx = 0;  // @1001_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1002_508680
  if ((eax & eax) == 0) goto L5092b7;  // @1003_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @1004_508680
  ecx = edx = 0;  // @1005_508680
  goto L5092b8;  // @1006_508680
  L5092b7:;
  __builtin_trap();  // @1008_508680
  L5092b8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @1010_508680
  L5092bd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @1012_508680
  if (eax >= (u32)(53)) goto L5092df;  // @1013_508680
  { u32 v = (u32)((u32)(5272128)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @1014_508680
  eax = (eax + 1);  // @1015_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @1016_508680
  goto L5092fe;  // @1017_508680
  L5092df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1019_508680
  ecx = esi;  // @1020_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @1021_508680
  ecx = edx = 0;  // @1022_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1023_508680
  if ((eax & eax) == 0) goto L5092f8;  // @1024_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @1025_508680
  ecx = edx = 0;  // @1026_508680
  goto L5092f9;  // @1027_508680
  L5092f8:;
  __builtin_trap();  // @1029_508680
  L5092f9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @1031_508680
  L5092fe:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @1033_508680
  if (eax >= (u32)(53)) goto L509320;  // @1034_508680
  { u32 v = (u32)((u32)(5275856)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @1035_508680
  eax = (eax + 1);  // @1036_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @1037_508680
  goto L50933f;  // @1038_508680
  L509320:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1040_508680
  ecx = esi;  // @1041_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @1042_508680
  ecx = edx = 0;  // @1043_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1044_508680
  if ((eax & eax) == 0) goto L509339;  // @1045_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @1046_508680
  ecx = edx = 0;  // @1047_508680
  goto L50933a;  // @1048_508680
  L509339:;
  __builtin_trap();  // @1050_508680
  L50933a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @1052_508680
  L50933f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @1054_508680
  if (eax >= (u32)(53)) goto L509361;  // @1055_508680
  { u32 v = (u32)((u32)(5276352)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @1056_508680
  eax = (eax + 1);  // @1057_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @1058_508680
  goto L509380;  // @1059_508680
  L509361:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1061_508680
  ecx = esi;  // @1062_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @1063_508680
  ecx = edx = 0;  // @1064_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1065_508680
  if ((eax & eax) == 0) goto L50937a;  // @1066_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @1067_508680
  ecx = edx = 0;  // @1068_508680
  goto L50937b;  // @1069_508680
  L50937a:;
  __builtin_trap();  // @1071_508680
  L50937b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @1073_508680
  L509380:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @1075_508680
  if (eax >= (u32)(53)) goto L5093a2;  // @1076_508680
  { u32 v = (u32)((u32)(5275360)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @1077_508680
  eax = (eax + 1);  // @1078_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @1079_508680
  goto L5093c1;  // @1080_508680
  L5093a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1082_508680
  ecx = esi;  // @1083_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @1084_508680
  ecx = edx = 0;  // @1085_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1086_508680
  if ((eax & eax) == 0) goto L5093bb;  // @1087_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @1088_508680
  ecx = edx = 0;  // @1089_508680
  goto L5093bc;  // @1090_508680
  L5093bb:;
  __builtin_trap();  // @1092_508680
  L5093bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7344200), sizeof v); (u32)v; });  // @1094_508680
  L5093c1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L509419;  // @1096_508680
  if (eax >= (u32)(53)) goto L5093ef;  // @1097_508680
  { u32 v = (u32)((u32)(6357248)); __builtin_memcpy((void *)(u32)(eax*4 + 7344208), &v, sizeof v); }  // @1098_508680
  ecx = esi;  // @1099_508680
  eax = (eax + 1);  // @1100_508680
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @1101_508680
  p0_ = edi;  // @1102_508680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7344200), &v, sizeof v); }  // @1103_508680
  eax = ext_505a00_thiscall2(ecx, (u32)(p0_));  // @1104_508680
  ecx = edx = 0;  // @1105_508680
  return eax;  // @1106_508680
  L5093ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1108_508680
  ecx = esi;  // @1109_508680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6934500));  // @1110_508680
  ecx = edx = 0;  // @1111_508680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1112_508680
  if ((eax & eax) == 0) goto L509418;  // @1113_508680
  eax = ((u32(STDCALL *)(void))(eax))();  // @1114_508680
  ecx = edx = 0;  // @1115_508680
  p1_ = edi;  // @1116_508680
  ecx = esi;  // @1117_508680
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @1118_508680
  eax = ext_505a00_thiscall2(ecx, (u32)(p1_));  // @1119_508680
  ecx = edx = 0;  // @1120_508680
  return eax;  // @1121_508680
  L509418:;
  __builtin_trap();  // @1123_508680
  L509419:;
  p2_ = edi;  // @1125_508680
  ecx = esi;  // @1126_508680
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @1127_508680
  eax = ext_505a00_thiscall2(ecx, (u32)(p2_));  // @1128_508680
  ecx = edx = 0;  // @1129_508680
  return eax;  // @1130_508680
}
PCREG(508680, lifted_508680);

extern "C" u32 THISCALL lifted_55cfb0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @0_55cfb0
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_55cfb0
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @2_55cfb0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_55cfb0
  esi = ecx;  // @4_55cfb0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @5_55cfb0
  if (eax >= (u32)(105)) goto L55cfe1;  // @6_55cfb0
  { u32 v = (u32)((u32)(5605392)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @7_55cfb0
  eax = (eax + 1);  // @8_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @9_55cfb0
  goto L55cffe;  // @10_55cfb0
  L55cfe1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @13_55cfb0
  ecx = edx = 0;  // @14_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_55cfb0
  if ((eax & eax) == 0) goto L55cff8;  // @16_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @17_55cfb0
  ecx = edx = 0;  // @18_55cfb0
  goto L55cff9;  // @19_55cfb0
  L55cff8:;
  __builtin_trap();  // @21_55cfb0
  L55cff9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @23_55cfb0
  L55cffe:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @25_55cfb0
  if (eax >= (u32)(105)) goto L55d020;  // @26_55cfb0
  { u32 v = (u32)((u32)(5607152)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @27_55cfb0
  eax = (eax + 1);  // @28_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @29_55cfb0
  goto L55d03f;  // @30_55cfb0
  L55d020:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_55cfb0
  ecx = esi;  // @33_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @34_55cfb0
  ecx = edx = 0;  // @35_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @36_55cfb0
  if ((eax & eax) == 0) goto L55d039;  // @37_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_55cfb0
  ecx = edx = 0;  // @39_55cfb0
  goto L55d03a;  // @40_55cfb0
  L55d039:;
  __builtin_trap();  // @42_55cfb0
  L55d03a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @44_55cfb0
  L55d03f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @46_55cfb0
  if (eax >= (u32)(105)) goto L55d061;  // @47_55cfb0
  { u32 v = (u32)((u32)(5607392)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @48_55cfb0
  eax = (eax + 1);  // @49_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @50_55cfb0
  goto L55d080;  // @51_55cfb0
  L55d061:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_55cfb0
  ecx = esi;  // @54_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @55_55cfb0
  ecx = edx = 0;  // @56_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_55cfb0
  if ((eax & eax) == 0) goto L55d07a;  // @58_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_55cfb0
  ecx = edx = 0;  // @60_55cfb0
  goto L55d07b;  // @61_55cfb0
  L55d07a:;
  __builtin_trap();  // @63_55cfb0
  L55d07b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @65_55cfb0
  L55d080:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @67_55cfb0
  if (eax >= (u32)(105)) goto L55d0a2;  // @68_55cfb0
  { u32 v = (u32)((u32)(5622128)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @69_55cfb0
  eax = (eax + 1);  // @70_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @71_55cfb0
  goto L55d0c1;  // @72_55cfb0
  L55d0a2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_55cfb0
  ecx = esi;  // @75_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @76_55cfb0
  ecx = edx = 0;  // @77_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @78_55cfb0
  if ((eax & eax) == 0) goto L55d0bb;  // @79_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @80_55cfb0
  ecx = edx = 0;  // @81_55cfb0
  goto L55d0bc;  // @82_55cfb0
  L55d0bb:;
  __builtin_trap();  // @84_55cfb0
  L55d0bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @86_55cfb0
  L55d0c1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @88_55cfb0
  if (eax >= (u32)(105)) goto L55d0e3;  // @89_55cfb0
  { u32 v = (u32)((u32)(5619856)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @90_55cfb0
  eax = (eax + 1);  // @91_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @92_55cfb0
  goto L55d102;  // @93_55cfb0
  L55d0e3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_55cfb0
  ecx = esi;  // @96_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @97_55cfb0
  ecx = edx = 0;  // @98_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @99_55cfb0
  if ((eax & eax) == 0) goto L55d0fc;  // @100_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @101_55cfb0
  ecx = edx = 0;  // @102_55cfb0
  goto L55d0fd;  // @103_55cfb0
  L55d0fc:;
  __builtin_trap();  // @105_55cfb0
  L55d0fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @107_55cfb0
  L55d102:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @109_55cfb0
  if (eax >= (u32)(105)) goto L55d124;  // @110_55cfb0
  { u32 v = (u32)((u32)(5623664)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @111_55cfb0
  eax = (eax + 1);  // @112_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @113_55cfb0
  goto L55d143;  // @114_55cfb0
  L55d124:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @116_55cfb0
  ecx = esi;  // @117_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @118_55cfb0
  ecx = edx = 0;  // @119_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @120_55cfb0
  if ((eax & eax) == 0) goto L55d13d;  // @121_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @122_55cfb0
  ecx = edx = 0;  // @123_55cfb0
  goto L55d13e;  // @124_55cfb0
  L55d13d:;
  __builtin_trap();  // @126_55cfb0
  L55d13e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @128_55cfb0
  L55d143:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @130_55cfb0
  if (eax >= (u32)(105)) goto L55d165;  // @131_55cfb0
  { u32 v = (u32)((u32)(5616320)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @132_55cfb0
  eax = (eax + 1);  // @133_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @134_55cfb0
  goto L55d184;  // @135_55cfb0
  L55d165:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_55cfb0
  ecx = esi;  // @138_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @139_55cfb0
  ecx = edx = 0;  // @140_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @141_55cfb0
  if ((eax & eax) == 0) goto L55d17e;  // @142_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @143_55cfb0
  ecx = edx = 0;  // @144_55cfb0
  goto L55d17f;  // @145_55cfb0
  L55d17e:;
  __builtin_trap();  // @147_55cfb0
  L55d17f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @149_55cfb0
  L55d184:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @151_55cfb0
  if (eax >= (u32)(105)) goto L55d1a6;  // @152_55cfb0
  { u32 v = (u32)((u32)(5603232)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @153_55cfb0
  eax = (eax + 1);  // @154_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @155_55cfb0
  goto L55d1c5;  // @156_55cfb0
  L55d1a6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @158_55cfb0
  ecx = esi;  // @159_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @160_55cfb0
  ecx = edx = 0;  // @161_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @162_55cfb0
  if ((eax & eax) == 0) goto L55d1bf;  // @163_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @164_55cfb0
  ecx = edx = 0;  // @165_55cfb0
  goto L55d1c0;  // @166_55cfb0
  L55d1bf:;
  __builtin_trap();  // @168_55cfb0
  L55d1c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @170_55cfb0
  L55d1c5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @172_55cfb0
  if (eax >= (u32)(105)) goto L55d1e7;  // @173_55cfb0
  { u32 v = (u32)((u32)(5602672)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @174_55cfb0
  eax = (eax + 1);  // @175_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @176_55cfb0
  goto L55d206;  // @177_55cfb0
  L55d1e7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_55cfb0
  ecx = esi;  // @180_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @181_55cfb0
  ecx = edx = 0;  // @182_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @183_55cfb0
  if ((eax & eax) == 0) goto L55d200;  // @184_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @185_55cfb0
  ecx = edx = 0;  // @186_55cfb0
  goto L55d201;  // @187_55cfb0
  L55d200:;
  __builtin_trap();  // @189_55cfb0
  L55d201:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @191_55cfb0
  L55d206:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @193_55cfb0
  if (eax >= (u32)(105)) goto L55d228;  // @194_55cfb0
  { u32 v = (u32)((u32)(5606800)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @195_55cfb0
  eax = (eax + 1);  // @196_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @197_55cfb0
  goto L55d247;  // @198_55cfb0
  L55d228:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @200_55cfb0
  ecx = esi;  // @201_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @202_55cfb0
  ecx = edx = 0;  // @203_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_55cfb0
  if ((eax & eax) == 0) goto L55d241;  // @205_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @206_55cfb0
  ecx = edx = 0;  // @207_55cfb0
  goto L55d242;  // @208_55cfb0
  L55d241:;
  __builtin_trap();  // @210_55cfb0
  L55d242:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @212_55cfb0
  L55d247:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @214_55cfb0
  if (eax >= (u32)(105)) goto L55d269;  // @215_55cfb0
  { u32 v = (u32)((u32)(5606576)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @216_55cfb0
  eax = (eax + 1);  // @217_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @218_55cfb0
  goto L55d288;  // @219_55cfb0
  L55d269:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_55cfb0
  ecx = esi;  // @222_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @223_55cfb0
  ecx = edx = 0;  // @224_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @225_55cfb0
  if ((eax & eax) == 0) goto L55d282;  // @226_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @227_55cfb0
  ecx = edx = 0;  // @228_55cfb0
  goto L55d283;  // @229_55cfb0
  L55d282:;
  __builtin_trap();  // @231_55cfb0
  L55d283:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @233_55cfb0
  L55d288:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @235_55cfb0
  if (eax >= (u32)(105)) goto L55d2aa;  // @236_55cfb0
  { u32 v = (u32)((u32)(5606400)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @237_55cfb0
  eax = (eax + 1);  // @238_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @239_55cfb0
  goto L55d2c9;  // @240_55cfb0
  L55d2aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_55cfb0
  ecx = esi;  // @243_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @244_55cfb0
  ecx = edx = 0;  // @245_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @246_55cfb0
  if ((eax & eax) == 0) goto L55d2c3;  // @247_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @248_55cfb0
  ecx = edx = 0;  // @249_55cfb0
  goto L55d2c4;  // @250_55cfb0
  L55d2c3:;
  __builtin_trap();  // @252_55cfb0
  L55d2c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @254_55cfb0
  L55d2c9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @256_55cfb0
  if (eax >= (u32)(105)) goto L55d2eb;  // @257_55cfb0
  { u32 v = (u32)((u32)(5606224)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @258_55cfb0
  eax = (eax + 1);  // @259_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @260_55cfb0
  goto L55d30a;  // @261_55cfb0
  L55d2eb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @263_55cfb0
  ecx = esi;  // @264_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @265_55cfb0
  ecx = edx = 0;  // @266_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @267_55cfb0
  if ((eax & eax) == 0) goto L55d304;  // @268_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @269_55cfb0
  ecx = edx = 0;  // @270_55cfb0
  goto L55d305;  // @271_55cfb0
  L55d304:;
  __builtin_trap();  // @273_55cfb0
  L55d305:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @275_55cfb0
  L55d30a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @277_55cfb0
  if (eax >= (u32)(105)) goto L55d32c;  // @278_55cfb0
  { u32 v = (u32)((u32)(5615856)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @279_55cfb0
  eax = (eax + 1);  // @280_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @281_55cfb0
  goto L55d34b;  // @282_55cfb0
  L55d32c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @284_55cfb0
  ecx = esi;  // @285_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @286_55cfb0
  ecx = edx = 0;  // @287_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @288_55cfb0
  if ((eax & eax) == 0) goto L55d345;  // @289_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @290_55cfb0
  ecx = edx = 0;  // @291_55cfb0
  goto L55d346;  // @292_55cfb0
  L55d345:;
  __builtin_trap();  // @294_55cfb0
  L55d346:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @296_55cfb0
  L55d34b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @298_55cfb0
  if (eax >= (u32)(105)) goto L55d36d;  // @299_55cfb0
  { u32 v = (u32)((u32)(5622448)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @300_55cfb0
  eax = (eax + 1);  // @301_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @302_55cfb0
  goto L55d38c;  // @303_55cfb0
  L55d36d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @305_55cfb0
  ecx = esi;  // @306_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @307_55cfb0
  ecx = edx = 0;  // @308_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @309_55cfb0
  if ((eax & eax) == 0) goto L55d386;  // @310_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @311_55cfb0
  ecx = edx = 0;  // @312_55cfb0
  goto L55d387;  // @313_55cfb0
  L55d386:;
  __builtin_trap();  // @315_55cfb0
  L55d387:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @317_55cfb0
  L55d38c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @319_55cfb0
  if (eax >= (u32)(105)) goto L55d3ae;  // @320_55cfb0
  { u32 v = (u32)((u32)(5621712)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @321_55cfb0
  eax = (eax + 1);  // @322_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @323_55cfb0
  goto L55d3cd;  // @324_55cfb0
  L55d3ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @326_55cfb0
  ecx = esi;  // @327_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @328_55cfb0
  ecx = edx = 0;  // @329_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @330_55cfb0
  if ((eax & eax) == 0) goto L55d3c7;  // @331_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @332_55cfb0
  ecx = edx = 0;  // @333_55cfb0
  goto L55d3c8;  // @334_55cfb0
  L55d3c7:;
  __builtin_trap();  // @336_55cfb0
  L55d3c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @338_55cfb0
  L55d3cd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @340_55cfb0
  if (eax >= (u32)(105)) goto L55d3ef;  // @341_55cfb0
  { u32 v = (u32)((u32)(5607744)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @342_55cfb0
  eax = (eax + 1);  // @343_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @344_55cfb0
  goto L55d40e;  // @345_55cfb0
  L55d3ef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @347_55cfb0
  ecx = esi;  // @348_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @349_55cfb0
  ecx = edx = 0;  // @350_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @351_55cfb0
  if ((eax & eax) == 0) goto L55d408;  // @352_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @353_55cfb0
  ecx = edx = 0;  // @354_55cfb0
  goto L55d409;  // @355_55cfb0
  L55d408:;
  __builtin_trap();  // @357_55cfb0
  L55d409:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @359_55cfb0
  L55d40e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @361_55cfb0
  if (eax >= (u32)(105)) goto L55d430;  // @362_55cfb0
  { u32 v = (u32)((u32)(5607632)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @363_55cfb0
  eax = (eax + 1);  // @364_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @365_55cfb0
  goto L55d44f;  // @366_55cfb0
  L55d430:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @368_55cfb0
  ecx = esi;  // @369_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @370_55cfb0
  ecx = edx = 0;  // @371_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @372_55cfb0
  if ((eax & eax) == 0) goto L55d449;  // @373_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @374_55cfb0
  ecx = edx = 0;  // @375_55cfb0
  goto L55d44a;  // @376_55cfb0
  L55d449:;
  __builtin_trap();  // @378_55cfb0
  L55d44a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @380_55cfb0
  L55d44f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @382_55cfb0
  if (eax >= (u32)(105)) goto L55d471;  // @383_55cfb0
  { u32 v = (u32)((u32)(6357248)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @384_55cfb0
  eax = (eax + 1);  // @385_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @386_55cfb0
  goto L55d490;  // @387_55cfb0
  L55d471:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @389_55cfb0
  ecx = esi;  // @390_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @391_55cfb0
  ecx = edx = 0;  // @392_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @393_55cfb0
  if ((eax & eax) == 0) goto L55d48a;  // @394_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @395_55cfb0
  ecx = edx = 0;  // @396_55cfb0
  goto L55d48b;  // @397_55cfb0
  L55d48a:;
  __builtin_trap();  // @399_55cfb0
  L55d48b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @401_55cfb0
  L55d490:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @403_55cfb0
  if (eax >= (u32)(105)) goto L55d4b2;  // @404_55cfb0
  { u32 v = (u32)((u32)(5614768)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @405_55cfb0
  eax = (eax + 1);  // @406_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @407_55cfb0
  goto L55d4d1;  // @408_55cfb0
  L55d4b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @410_55cfb0
  ecx = esi;  // @411_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @412_55cfb0
  ecx = edx = 0;  // @413_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @414_55cfb0
  if ((eax & eax) == 0) goto L55d4cb;  // @415_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @416_55cfb0
  ecx = edx = 0;  // @417_55cfb0
  goto L55d4cc;  // @418_55cfb0
  L55d4cb:;
  __builtin_trap();  // @420_55cfb0
  L55d4cc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @422_55cfb0
  L55d4d1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @424_55cfb0
  if (eax >= (u32)(105)) goto L55d4f3;  // @425_55cfb0
  { u32 v = (u32)((u32)(5606208)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @426_55cfb0
  eax = (eax + 1);  // @427_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @428_55cfb0
  goto L55d512;  // @429_55cfb0
  L55d4f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @431_55cfb0
  ecx = esi;  // @432_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @433_55cfb0
  ecx = edx = 0;  // @434_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @435_55cfb0
  if ((eax & eax) == 0) goto L55d50c;  // @436_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @437_55cfb0
  ecx = edx = 0;  // @438_55cfb0
  goto L55d50d;  // @439_55cfb0
  L55d50c:;
  __builtin_trap();  // @441_55cfb0
  L55d50d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @443_55cfb0
  L55d512:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @445_55cfb0
  if (eax >= (u32)(105)) goto L55d534;  // @446_55cfb0
  { u32 v = (u32)((u32)(5622080)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @447_55cfb0
  eax = (eax + 1);  // @448_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @449_55cfb0
  goto L55d553;  // @450_55cfb0
  L55d534:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @452_55cfb0
  ecx = esi;  // @453_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @454_55cfb0
  ecx = edx = 0;  // @455_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @456_55cfb0
  if ((eax & eax) == 0) goto L55d54d;  // @457_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @458_55cfb0
  ecx = edx = 0;  // @459_55cfb0
  goto L55d54e;  // @460_55cfb0
  L55d54d:;
  __builtin_trap();  // @462_55cfb0
  L55d54e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @464_55cfb0
  L55d553:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @466_55cfb0
  if (eax >= (u32)(105)) goto L55d575;  // @467_55cfb0
  { u32 v = (u32)((u32)(5621936)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @468_55cfb0
  eax = (eax + 1);  // @469_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @470_55cfb0
  goto L55d594;  // @471_55cfb0
  L55d575:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @473_55cfb0
  ecx = esi;  // @474_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @475_55cfb0
  ecx = edx = 0;  // @476_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @477_55cfb0
  if ((eax & eax) == 0) goto L55d58e;  // @478_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @479_55cfb0
  ecx = edx = 0;  // @480_55cfb0
  goto L55d58f;  // @481_55cfb0
  L55d58e:;
  __builtin_trap();  // @483_55cfb0
  L55d58f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @485_55cfb0
  L55d594:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @487_55cfb0
  if (eax >= (u32)(105)) goto L55d5b6;  // @488_55cfb0
  { u32 v = (u32)((u32)(5611184)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @489_55cfb0
  eax = (eax + 1);  // @490_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @491_55cfb0
  goto L55d5d5;  // @492_55cfb0
  L55d5b6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @494_55cfb0
  ecx = esi;  // @495_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @496_55cfb0
  ecx = edx = 0;  // @497_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @498_55cfb0
  if ((eax & eax) == 0) goto L55d5cf;  // @499_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @500_55cfb0
  ecx = edx = 0;  // @501_55cfb0
  goto L55d5d0;  // @502_55cfb0
  L55d5cf:;
  __builtin_trap();  // @504_55cfb0
  L55d5d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @506_55cfb0
  L55d5d5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @508_55cfb0
  if (eax >= (u32)(105)) goto L55d5f7;  // @509_55cfb0
  { u32 v = (u32)((u32)(5610944)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @510_55cfb0
  eax = (eax + 1);  // @511_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @512_55cfb0
  goto L55d616;  // @513_55cfb0
  L55d5f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @515_55cfb0
  ecx = esi;  // @516_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @517_55cfb0
  ecx = edx = 0;  // @518_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @519_55cfb0
  if ((eax & eax) == 0) goto L55d610;  // @520_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @521_55cfb0
  ecx = edx = 0;  // @522_55cfb0
  goto L55d611;  // @523_55cfb0
  L55d610:;
  __builtin_trap();  // @525_55cfb0
  L55d611:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @527_55cfb0
  L55d616:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @529_55cfb0
  if (eax >= (u32)(105)) goto L55d638;  // @530_55cfb0
  { u32 v = (u32)((u32)(5621664)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @531_55cfb0
  eax = (eax + 1);  // @532_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @533_55cfb0
  goto L55d657;  // @534_55cfb0
  L55d638:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @536_55cfb0
  ecx = esi;  // @537_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @538_55cfb0
  ecx = edx = 0;  // @539_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @540_55cfb0
  if ((eax & eax) == 0) goto L55d651;  // @541_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @542_55cfb0
  ecx = edx = 0;  // @543_55cfb0
  goto L55d652;  // @544_55cfb0
  L55d651:;
  __builtin_trap();  // @546_55cfb0
  L55d652:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @548_55cfb0
  L55d657:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @550_55cfb0
  if (eax >= (u32)(105)) goto L55d679;  // @551_55cfb0
  { u32 v = (u32)((u32)(5608896)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @552_55cfb0
  eax = (eax + 1);  // @553_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @554_55cfb0
  goto L55d698;  // @555_55cfb0
  L55d679:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @557_55cfb0
  ecx = esi;  // @558_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @559_55cfb0
  ecx = edx = 0;  // @560_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @561_55cfb0
  if ((eax & eax) == 0) goto L55d692;  // @562_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @563_55cfb0
  ecx = edx = 0;  // @564_55cfb0
  goto L55d693;  // @565_55cfb0
  L55d692:;
  __builtin_trap();  // @567_55cfb0
  L55d693:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @569_55cfb0
  L55d698:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @571_55cfb0
  if (eax >= (u32)(105)) goto L55d6ba;  // @572_55cfb0
  { u32 v = (u32)((u32)(5616432)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @573_55cfb0
  eax = (eax + 1);  // @574_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @575_55cfb0
  goto L55d6d9;  // @576_55cfb0
  L55d6ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @578_55cfb0
  ecx = esi;  // @579_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @580_55cfb0
  ecx = edx = 0;  // @581_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @582_55cfb0
  if ((eax & eax) == 0) goto L55d6d3;  // @583_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @584_55cfb0
  ecx = edx = 0;  // @585_55cfb0
  goto L55d6d4;  // @586_55cfb0
  L55d6d3:;
  __builtin_trap();  // @588_55cfb0
  L55d6d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @590_55cfb0
  L55d6d9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @592_55cfb0
  if (eax >= (u32)(105)) goto L55d6fb;  // @593_55cfb0
  { u32 v = (u32)((u32)(5604112)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @594_55cfb0
  eax = (eax + 1);  // @595_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @596_55cfb0
  goto L55d71a;  // @597_55cfb0
  L55d6fb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @599_55cfb0
  ecx = esi;  // @600_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @601_55cfb0
  ecx = edx = 0;  // @602_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @603_55cfb0
  if ((eax & eax) == 0) goto L55d714;  // @604_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @605_55cfb0
  ecx = edx = 0;  // @606_55cfb0
  goto L55d715;  // @607_55cfb0
  L55d714:;
  __builtin_trap();  // @609_55cfb0
  L55d715:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @611_55cfb0
  L55d71a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @613_55cfb0
  if (eax >= (u32)(105)) goto L55d73c;  // @614_55cfb0
  { u32 v = (u32)((u32)(5622400)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @615_55cfb0
  eax = (eax + 1);  // @616_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @617_55cfb0
  goto L55d75b;  // @618_55cfb0
  L55d73c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @620_55cfb0
  ecx = esi;  // @621_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @622_55cfb0
  ecx = edx = 0;  // @623_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @624_55cfb0
  if ((eax & eax) == 0) goto L55d755;  // @625_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @626_55cfb0
  ecx = edx = 0;  // @627_55cfb0
  goto L55d756;  // @628_55cfb0
  L55d755:;
  __builtin_trap();  // @630_55cfb0
  L55d756:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @632_55cfb0
  L55d75b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @634_55cfb0
  if (eax >= (u32)(105)) goto L55d77d;  // @635_55cfb0
  { u32 v = (u32)((u32)(5610816)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @636_55cfb0
  eax = (eax + 1);  // @637_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @638_55cfb0
  goto L55d79c;  // @639_55cfb0
  L55d77d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @641_55cfb0
  ecx = esi;  // @642_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @643_55cfb0
  ecx = edx = 0;  // @644_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @645_55cfb0
  if ((eax & eax) == 0) goto L55d796;  // @646_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @647_55cfb0
  ecx = edx = 0;  // @648_55cfb0
  goto L55d797;  // @649_55cfb0
  L55d796:;
  __builtin_trap();  // @651_55cfb0
  L55d797:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @653_55cfb0
  L55d79c:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @655_55cfb0
  if (eax >= (u32)(105)) goto L55d7be;  // @656_55cfb0
  { u32 v = (u32)((u32)(5621168)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @657_55cfb0
  eax = (eax + 1);  // @658_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @659_55cfb0
  goto L55d7dd;  // @660_55cfb0
  L55d7be:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @662_55cfb0
  ecx = esi;  // @663_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @664_55cfb0
  ecx = edx = 0;  // @665_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @666_55cfb0
  if ((eax & eax) == 0) goto L55d7d7;  // @667_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @668_55cfb0
  ecx = edx = 0;  // @669_55cfb0
  goto L55d7d8;  // @670_55cfb0
  L55d7d7:;
  __builtin_trap();  // @672_55cfb0
  L55d7d8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @674_55cfb0
  L55d7dd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @676_55cfb0
  if (eax >= (u32)(105)) goto L55d7ff;  // @677_55cfb0
  { u32 v = (u32)((u32)(5621168)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @678_55cfb0
  eax = (eax + 1);  // @679_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @680_55cfb0
  goto L55d81e;  // @681_55cfb0
  L55d7ff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @683_55cfb0
  ecx = esi;  // @684_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @685_55cfb0
  ecx = edx = 0;  // @686_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @687_55cfb0
  if ((eax & eax) == 0) goto L55d818;  // @688_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @689_55cfb0
  ecx = edx = 0;  // @690_55cfb0
  goto L55d819;  // @691_55cfb0
  L55d818:;
  __builtin_trap();  // @693_55cfb0
  L55d819:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @695_55cfb0
  L55d81e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @697_55cfb0
  if (eax >= (u32)(105)) goto L55d840;  // @698_55cfb0
  { u32 v = (u32)((u32)(5620128)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @699_55cfb0
  eax = (eax + 1);  // @700_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @701_55cfb0
  goto L55d85f;  // @702_55cfb0
  L55d840:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @704_55cfb0
  ecx = esi;  // @705_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @706_55cfb0
  ecx = edx = 0;  // @707_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @708_55cfb0
  if ((eax & eax) == 0) goto L55d859;  // @709_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @710_55cfb0
  ecx = edx = 0;  // @711_55cfb0
  goto L55d85a;  // @712_55cfb0
  L55d859:;
  __builtin_trap();  // @714_55cfb0
  L55d85a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @716_55cfb0
  L55d85f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @718_55cfb0
  if (eax >= (u32)(105)) goto L55d881;  // @719_55cfb0
  { u32 v = (u32)((u32)(5620832)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @720_55cfb0
  eax = (eax + 1);  // @721_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @722_55cfb0
  goto L55d8a0;  // @723_55cfb0
  L55d881:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @725_55cfb0
  ecx = esi;  // @726_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @727_55cfb0
  ecx = edx = 0;  // @728_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @729_55cfb0
  if ((eax & eax) == 0) goto L55d89a;  // @730_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @731_55cfb0
  ecx = edx = 0;  // @732_55cfb0
  goto L55d89b;  // @733_55cfb0
  L55d89a:;
  __builtin_trap();  // @735_55cfb0
  L55d89b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @737_55cfb0
  L55d8a0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @739_55cfb0
  if (eax >= (u32)(105)) goto L55d8c2;  // @740_55cfb0
  { u32 v = (u32)((u32)(5608656)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @741_55cfb0
  eax = (eax + 1);  // @742_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @743_55cfb0
  goto L55d8e1;  // @744_55cfb0
  L55d8c2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @746_55cfb0
  ecx = esi;  // @747_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @748_55cfb0
  ecx = edx = 0;  // @749_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @750_55cfb0
  if ((eax & eax) == 0) goto L55d8db;  // @751_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @752_55cfb0
  ecx = edx = 0;  // @753_55cfb0
  goto L55d8dc;  // @754_55cfb0
  L55d8db:;
  __builtin_trap();  // @756_55cfb0
  L55d8dc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @758_55cfb0
  L55d8e1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @760_55cfb0
  if (eax >= (u32)(105)) goto L55d903;  // @761_55cfb0
  { u32 v = (u32)((u32)(5619872)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @762_55cfb0
  eax = (eax + 1);  // @763_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @764_55cfb0
  goto L55d922;  // @765_55cfb0
  L55d903:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @767_55cfb0
  ecx = esi;  // @768_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @769_55cfb0
  ecx = edx = 0;  // @770_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @771_55cfb0
  if ((eax & eax) == 0) goto L55d91c;  // @772_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @773_55cfb0
  ecx = edx = 0;  // @774_55cfb0
  goto L55d91d;  // @775_55cfb0
  L55d91c:;
  __builtin_trap();  // @777_55cfb0
  L55d91d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @779_55cfb0
  L55d922:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @781_55cfb0
  if (eax >= (u32)(105)) goto L55d944;  // @782_55cfb0
  { u32 v = (u32)((u32)(5623616)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @783_55cfb0
  eax = (eax + 1);  // @784_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @785_55cfb0
  goto L55d963;  // @786_55cfb0
  L55d944:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @788_55cfb0
  ecx = esi;  // @789_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @790_55cfb0
  ecx = edx = 0;  // @791_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @792_55cfb0
  if ((eax & eax) == 0) goto L55d95d;  // @793_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @794_55cfb0
  ecx = edx = 0;  // @795_55cfb0
  goto L55d95e;  // @796_55cfb0
  L55d95d:;
  __builtin_trap();  // @798_55cfb0
  L55d95e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @800_55cfb0
  L55d963:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @802_55cfb0
  if (eax >= (u32)(105)) goto L55d985;  // @803_55cfb0
  { u32 v = (u32)((u32)(5606112)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @804_55cfb0
  eax = (eax + 1);  // @805_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @806_55cfb0
  goto L55d9a4;  // @807_55cfb0
  L55d985:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @809_55cfb0
  ecx = esi;  // @810_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @811_55cfb0
  ecx = edx = 0;  // @812_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @813_55cfb0
  if ((eax & eax) == 0) goto L55d99e;  // @814_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @815_55cfb0
  ecx = edx = 0;  // @816_55cfb0
  goto L55d99f;  // @817_55cfb0
  L55d99e:;
  __builtin_trap();  // @819_55cfb0
  L55d99f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @821_55cfb0
  L55d9a4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @823_55cfb0
  if (eax >= (u32)(105)) goto L55d9c6;  // @824_55cfb0
  { u32 v = (u32)((u32)(5606160)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @825_55cfb0
  eax = (eax + 1);  // @826_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @827_55cfb0
  goto L55d9e5;  // @828_55cfb0
  L55d9c6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @830_55cfb0
  ecx = esi;  // @831_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @832_55cfb0
  ecx = edx = 0;  // @833_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @834_55cfb0
  if ((eax & eax) == 0) goto L55d9df;  // @835_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @836_55cfb0
  ecx = edx = 0;  // @837_55cfb0
  goto L55d9e0;  // @838_55cfb0
  L55d9df:;
  __builtin_trap();  // @840_55cfb0
  L55d9e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @842_55cfb0
  L55d9e5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @844_55cfb0
  if (eax >= (u32)(105)) goto L55da07;  // @845_55cfb0
  { u32 v = (u32)((u32)(5606032)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @846_55cfb0
  eax = (eax + 1);  // @847_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @848_55cfb0
  goto L55da26;  // @849_55cfb0
  L55da07:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @851_55cfb0
  ecx = esi;  // @852_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @853_55cfb0
  ecx = edx = 0;  // @854_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @855_55cfb0
  if ((eax & eax) == 0) goto L55da20;  // @856_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @857_55cfb0
  ecx = edx = 0;  // @858_55cfb0
  goto L55da21;  // @859_55cfb0
  L55da20:;
  __builtin_trap();  // @861_55cfb0
  L55da21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @863_55cfb0
  L55da26:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @865_55cfb0
  if (eax >= (u32)(105)) goto L55da48;  // @866_55cfb0
  { u32 v = (u32)((u32)(5602336)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @867_55cfb0
  eax = (eax + 1);  // @868_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @869_55cfb0
  goto L55da67;  // @870_55cfb0
  L55da48:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @872_55cfb0
  ecx = esi;  // @873_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @874_55cfb0
  ecx = edx = 0;  // @875_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @876_55cfb0
  if ((eax & eax) == 0) goto L55da61;  // @877_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @878_55cfb0
  ecx = edx = 0;  // @879_55cfb0
  goto L55da62;  // @880_55cfb0
  L55da61:;
  __builtin_trap();  // @882_55cfb0
  L55da62:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @884_55cfb0
  L55da67:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @886_55cfb0
  if (eax >= (u32)(105)) goto L55da89;  // @887_55cfb0
  { u32 v = (u32)((u32)(5602448)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @888_55cfb0
  eax = (eax + 1);  // @889_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @890_55cfb0
  goto L55daa8;  // @891_55cfb0
  L55da89:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @893_55cfb0
  ecx = esi;  // @894_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @895_55cfb0
  ecx = edx = 0;  // @896_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @897_55cfb0
  if ((eax & eax) == 0) goto L55daa2;  // @898_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @899_55cfb0
  ecx = edx = 0;  // @900_55cfb0
  goto L55daa3;  // @901_55cfb0
  L55daa2:;
  __builtin_trap();  // @903_55cfb0
  L55daa3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @905_55cfb0
  L55daa8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @907_55cfb0
  if (eax >= (u32)(105)) goto L55daca;  // @908_55cfb0
  { u32 v = (u32)((u32)(5602560)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @909_55cfb0
  eax = (eax + 1);  // @910_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @911_55cfb0
  goto L55dae9;  // @912_55cfb0
  L55daca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @914_55cfb0
  ecx = esi;  // @915_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @916_55cfb0
  ecx = edx = 0;  // @917_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @918_55cfb0
  if ((eax & eax) == 0) goto L55dae3;  // @919_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @920_55cfb0
  ecx = edx = 0;  // @921_55cfb0
  goto L55dae4;  // @922_55cfb0
  L55dae3:;
  __builtin_trap();  // @924_55cfb0
  L55dae4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @926_55cfb0
  L55dae9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @928_55cfb0
  if (eax >= (u32)(105)) goto L55db0b;  // @929_55cfb0
  { u32 v = (u32)((u32)(5616224)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @930_55cfb0
  eax = (eax + 1);  // @931_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @932_55cfb0
  goto L55db2a;  // @933_55cfb0
  L55db0b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @935_55cfb0
  ecx = esi;  // @936_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @937_55cfb0
  ecx = edx = 0;  // @938_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @939_55cfb0
  if ((eax & eax) == 0) goto L55db24;  // @940_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @941_55cfb0
  ecx = edx = 0;  // @942_55cfb0
  goto L55db25;  // @943_55cfb0
  L55db24:;
  __builtin_trap();  // @945_55cfb0
  L55db25:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @947_55cfb0
  L55db2a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @949_55cfb0
  if (eax >= (u32)(105)) goto L55db4c;  // @950_55cfb0
  { u32 v = (u32)((u32)(5616272)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @951_55cfb0
  eax = (eax + 1);  // @952_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @953_55cfb0
  goto L55db6b;  // @954_55cfb0
  L55db4c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @956_55cfb0
  ecx = esi;  // @957_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @958_55cfb0
  ecx = edx = 0;  // @959_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @960_55cfb0
  if ((eax & eax) == 0) goto L55db65;  // @961_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @962_55cfb0
  ecx = edx = 0;  // @963_55cfb0
  goto L55db66;  // @964_55cfb0
  L55db65:;
  __builtin_trap();  // @966_55cfb0
  L55db66:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @968_55cfb0
  L55db6b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @970_55cfb0
  if (eax >= (u32)(105)) goto L55db8d;  // @971_55cfb0
  { u32 v = (u32)((u32)(5605856)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @972_55cfb0
  eax = (eax + 1);  // @973_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @974_55cfb0
  goto L55dbac;  // @975_55cfb0
  L55db8d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @977_55cfb0
  ecx = esi;  // @978_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @979_55cfb0
  ecx = edx = 0;  // @980_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @981_55cfb0
  if ((eax & eax) == 0) goto L55dba6;  // @982_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @983_55cfb0
  ecx = edx = 0;  // @984_55cfb0
  goto L55dba7;  // @985_55cfb0
  L55dba6:;
  __builtin_trap();  // @987_55cfb0
  L55dba7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @989_55cfb0
  L55dbac:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @991_55cfb0
  if (eax >= (u32)(105)) goto L55dbce;  // @992_55cfb0
  { u32 v = (u32)((u32)(5605808)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @993_55cfb0
  eax = (eax + 1);  // @994_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @995_55cfb0
  goto L55dbed;  // @996_55cfb0
  L55dbce:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @998_55cfb0
  ecx = esi;  // @999_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1000_55cfb0
  ecx = edx = 0;  // @1001_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1002_55cfb0
  if ((eax & eax) == 0) goto L55dbe7;  // @1003_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1004_55cfb0
  ecx = edx = 0;  // @1005_55cfb0
  goto L55dbe8;  // @1006_55cfb0
  L55dbe7:;
  __builtin_trap();  // @1008_55cfb0
  L55dbe8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1010_55cfb0
  L55dbed:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1012_55cfb0
  if (eax >= (u32)(105)) goto L55dc0f;  // @1013_55cfb0
  { u32 v = (u32)((u32)(5605968)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1014_55cfb0
  eax = (eax + 1);  // @1015_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1016_55cfb0
  goto L55dc2e;  // @1017_55cfb0
  L55dc0f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1019_55cfb0
  ecx = esi;  // @1020_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1021_55cfb0
  ecx = edx = 0;  // @1022_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1023_55cfb0
  if ((eax & eax) == 0) goto L55dc28;  // @1024_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1025_55cfb0
  ecx = edx = 0;  // @1026_55cfb0
  goto L55dc29;  // @1027_55cfb0
  L55dc28:;
  __builtin_trap();  // @1029_55cfb0
  L55dc29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1031_55cfb0
  L55dc2e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1033_55cfb0
  if (eax >= (u32)(105)) goto L55dc50;  // @1034_55cfb0
  { u32 v = (u32)((u32)(5605904)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1035_55cfb0
  eax = (eax + 1);  // @1036_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1037_55cfb0
  goto L55dc6f;  // @1038_55cfb0
  L55dc50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1040_55cfb0
  ecx = esi;  // @1041_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1042_55cfb0
  ecx = edx = 0;  // @1043_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1044_55cfb0
  if ((eax & eax) == 0) goto L55dc69;  // @1045_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1046_55cfb0
  ecx = edx = 0;  // @1047_55cfb0
  goto L55dc6a;  // @1048_55cfb0
  L55dc69:;
  __builtin_trap();  // @1050_55cfb0
  L55dc6a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1052_55cfb0
  L55dc6f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1054_55cfb0
  if (eax >= (u32)(105)) goto L55dc91;  // @1055_55cfb0
  { u32 v = (u32)((u32)(5621760)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1056_55cfb0
  eax = (eax + 1);  // @1057_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1058_55cfb0
  goto L55dcb0;  // @1059_55cfb0
  L55dc91:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1061_55cfb0
  ecx = esi;  // @1062_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1063_55cfb0
  ecx = edx = 0;  // @1064_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1065_55cfb0
  if ((eax & eax) == 0) goto L55dcaa;  // @1066_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1067_55cfb0
  ecx = edx = 0;  // @1068_55cfb0
  goto L55dcab;  // @1069_55cfb0
  L55dcaa:;
  __builtin_trap();  // @1071_55cfb0
  L55dcab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1073_55cfb0
  L55dcb0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1075_55cfb0
  if (eax >= (u32)(105)) goto L55dcd2;  // @1076_55cfb0
  { u32 v = (u32)((u32)(5618320)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1077_55cfb0
  eax = (eax + 1);  // @1078_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1079_55cfb0
  goto L55dcf1;  // @1080_55cfb0
  L55dcd2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1082_55cfb0
  ecx = esi;  // @1083_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1084_55cfb0
  ecx = edx = 0;  // @1085_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1086_55cfb0
  if ((eax & eax) == 0) goto L55dceb;  // @1087_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1088_55cfb0
  ecx = edx = 0;  // @1089_55cfb0
  goto L55dcec;  // @1090_55cfb0
  L55dceb:;
  __builtin_trap();  // @1092_55cfb0
  L55dcec:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1094_55cfb0
  L55dcf1:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1096_55cfb0
  if (eax >= (u32)(105)) goto L55dd13;  // @1097_55cfb0
  { u32 v = (u32)((u32)(5622032)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1098_55cfb0
  eax = (eax + 1);  // @1099_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1100_55cfb0
  goto L55dd32;  // @1101_55cfb0
  L55dd13:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1103_55cfb0
  ecx = esi;  // @1104_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1105_55cfb0
  ecx = edx = 0;  // @1106_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1107_55cfb0
  if ((eax & eax) == 0) goto L55dd2c;  // @1108_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1109_55cfb0
  ecx = edx = 0;  // @1110_55cfb0
  goto L55dd2d;  // @1111_55cfb0
  L55dd2c:;
  __builtin_trap();  // @1113_55cfb0
  L55dd2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1115_55cfb0
  L55dd32:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1117_55cfb0
  if (eax >= (u32)(105)) goto L55dd54;  // @1118_55cfb0
  { u32 v = (u32)((u32)(5611312)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1119_55cfb0
  eax = (eax + 1);  // @1120_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1121_55cfb0
  goto L55dd73;  // @1122_55cfb0
  L55dd54:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1124_55cfb0
  ecx = esi;  // @1125_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1126_55cfb0
  ecx = edx = 0;  // @1127_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1128_55cfb0
  if ((eax & eax) == 0) goto L55dd6d;  // @1129_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1130_55cfb0
  ecx = edx = 0;  // @1131_55cfb0
  goto L55dd6e;  // @1132_55cfb0
  L55dd6d:;
  __builtin_trap();  // @1134_55cfb0
  L55dd6e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1136_55cfb0
  L55dd73:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1138_55cfb0
  if (eax >= (u32)(105)) goto L55dd95;  // @1139_55cfb0
  { u32 v = (u32)((u32)(5603664)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1140_55cfb0
  eax = (eax + 1);  // @1141_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1142_55cfb0
  goto L55ddb4;  // @1143_55cfb0
  L55dd95:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1145_55cfb0
  ecx = esi;  // @1146_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1147_55cfb0
  ecx = edx = 0;  // @1148_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1149_55cfb0
  if ((eax & eax) == 0) goto L55ddae;  // @1150_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1151_55cfb0
  ecx = edx = 0;  // @1152_55cfb0
  goto L55ddaf;  // @1153_55cfb0
  L55ddae:;
  __builtin_trap();  // @1155_55cfb0
  L55ddaf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1157_55cfb0
  L55ddb4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1159_55cfb0
  if (eax >= (u32)(105)) goto L55ddd6;  // @1160_55cfb0
  { u32 v = (u32)((u32)(5614864)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1161_55cfb0
  eax = (eax + 1);  // @1162_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1163_55cfb0
  goto L55ddf5;  // @1164_55cfb0
  L55ddd6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1166_55cfb0
  ecx = esi;  // @1167_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1168_55cfb0
  ecx = edx = 0;  // @1169_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1170_55cfb0
  if ((eax & eax) == 0) goto L55ddef;  // @1171_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1172_55cfb0
  ecx = edx = 0;  // @1173_55cfb0
  goto L55ddf0;  // @1174_55cfb0
  L55ddef:;
  __builtin_trap();  // @1176_55cfb0
  L55ddf0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1178_55cfb0
  L55ddf5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1180_55cfb0
  if (eax >= (u32)(105)) goto L55de17;  // @1181_55cfb0
  { u32 v = (u32)((u32)(5604176)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1182_55cfb0
  eax = (eax + 1);  // @1183_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1184_55cfb0
  goto L55de36;  // @1185_55cfb0
  L55de17:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1187_55cfb0
  ecx = esi;  // @1188_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1189_55cfb0
  ecx = edx = 0;  // @1190_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1191_55cfb0
  if ((eax & eax) == 0) goto L55de30;  // @1192_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1193_55cfb0
  ecx = edx = 0;  // @1194_55cfb0
  goto L55de31;  // @1195_55cfb0
  L55de30:;
  __builtin_trap();  // @1197_55cfb0
  L55de31:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1199_55cfb0
  L55de36:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1201_55cfb0
  if (eax >= (u32)(105)) goto L55de58;  // @1202_55cfb0
  { u32 v = (u32)((u32)(5604240)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1203_55cfb0
  eax = (eax + 1);  // @1204_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1205_55cfb0
  goto L55de77;  // @1206_55cfb0
  L55de58:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1208_55cfb0
  ecx = esi;  // @1209_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1210_55cfb0
  ecx = edx = 0;  // @1211_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1212_55cfb0
  if ((eax & eax) == 0) goto L55de71;  // @1213_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1214_55cfb0
  ecx = edx = 0;  // @1215_55cfb0
  goto L55de72;  // @1216_55cfb0
  L55de71:;
  __builtin_trap();  // @1218_55cfb0
  L55de72:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1220_55cfb0
  L55de77:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1222_55cfb0
  if (eax >= (u32)(105)) goto L55de99;  // @1223_55cfb0
  { u32 v = (u32)((u32)(5611360)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1224_55cfb0
  eax = (eax + 1);  // @1225_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1226_55cfb0
  goto L55deb8;  // @1227_55cfb0
  L55de99:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1229_55cfb0
  ecx = esi;  // @1230_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1231_55cfb0
  ecx = edx = 0;  // @1232_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1233_55cfb0
  if ((eax & eax) == 0) goto L55deb2;  // @1234_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1235_55cfb0
  ecx = edx = 0;  // @1236_55cfb0
  goto L55deb3;  // @1237_55cfb0
  L55deb2:;
  __builtin_trap();  // @1239_55cfb0
  L55deb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1241_55cfb0
  L55deb8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1243_55cfb0
  if (eax >= (u32)(105)) goto L55deda;  // @1244_55cfb0
  { u32 v = (u32)((u32)(5622496)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1245_55cfb0
  eax = (eax + 1);  // @1246_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1247_55cfb0
  goto L55def9;  // @1248_55cfb0
  L55deda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1250_55cfb0
  ecx = esi;  // @1251_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1252_55cfb0
  ecx = edx = 0;  // @1253_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1254_55cfb0
  if ((eax & eax) == 0) goto L55def3;  // @1255_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1256_55cfb0
  ecx = edx = 0;  // @1257_55cfb0
  goto L55def4;  // @1258_55cfb0
  L55def3:;
  __builtin_trap();  // @1260_55cfb0
  L55def4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1262_55cfb0
  L55def9:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1264_55cfb0
  if (eax >= (u32)(105)) goto L55df1b;  // @1265_55cfb0
  { u32 v = (u32)((u32)(5622784)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1266_55cfb0
  eax = (eax + 1);  // @1267_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1268_55cfb0
  goto L55df3a;  // @1269_55cfb0
  L55df1b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1271_55cfb0
  ecx = esi;  // @1272_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1273_55cfb0
  ecx = edx = 0;  // @1274_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1275_55cfb0
  if ((eax & eax) == 0) goto L55df34;  // @1276_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1277_55cfb0
  ecx = edx = 0;  // @1278_55cfb0
  goto L55df35;  // @1279_55cfb0
  L55df34:;
  __builtin_trap();  // @1281_55cfb0
  L55df35:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1283_55cfb0
  L55df3a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1285_55cfb0
  if (eax >= (u32)(105)) goto L55df5c;  // @1286_55cfb0
  { u32 v = (u32)((u32)(5622832)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1287_55cfb0
  eax = (eax + 1);  // @1288_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1289_55cfb0
  goto L55df7b;  // @1290_55cfb0
  L55df5c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1292_55cfb0
  ecx = esi;  // @1293_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1294_55cfb0
  ecx = edx = 0;  // @1295_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1296_55cfb0
  if ((eax & eax) == 0) goto L55df75;  // @1297_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1298_55cfb0
  ecx = edx = 0;  // @1299_55cfb0
  goto L55df76;  // @1300_55cfb0
  L55df75:;
  __builtin_trap();  // @1302_55cfb0
  L55df76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1304_55cfb0
  L55df7b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1306_55cfb0
  if (eax >= (u32)(105)) goto L55df9d;  // @1307_55cfb0
  { u32 v = (u32)((u32)(5605600)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1308_55cfb0
  eax = (eax + 1);  // @1309_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1310_55cfb0
  goto L55dfbc;  // @1311_55cfb0
  L55df9d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1313_55cfb0
  ecx = esi;  // @1314_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1315_55cfb0
  ecx = edx = 0;  // @1316_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1317_55cfb0
  if ((eax & eax) == 0) goto L55dfb6;  // @1318_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1319_55cfb0
  ecx = edx = 0;  // @1320_55cfb0
  goto L55dfb7;  // @1321_55cfb0
  L55dfb6:;
  __builtin_trap();  // @1323_55cfb0
  L55dfb7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1325_55cfb0
  L55dfbc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1327_55cfb0
  if (eax >= (u32)(105)) goto L55dfde;  // @1328_55cfb0
  { u32 v = (u32)((u32)(5622320)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1329_55cfb0
  eax = (eax + 1);  // @1330_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1331_55cfb0
  goto L55dffd;  // @1332_55cfb0
  L55dfde:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1334_55cfb0
  ecx = esi;  // @1335_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1336_55cfb0
  ecx = edx = 0;  // @1337_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1338_55cfb0
  if ((eax & eax) == 0) goto L55dff7;  // @1339_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1340_55cfb0
  ecx = edx = 0;  // @1341_55cfb0
  goto L55dff8;  // @1342_55cfb0
  L55dff7:;
  __builtin_trap();  // @1344_55cfb0
  L55dff8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1346_55cfb0
  L55dffd:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1348_55cfb0
  if (eax >= (u32)(105)) goto L55e01f;  // @1349_55cfb0
  { u32 v = (u32)((u32)(5614816)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1350_55cfb0
  eax = (eax + 1);  // @1351_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1352_55cfb0
  goto L55e03e;  // @1353_55cfb0
  L55e01f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1355_55cfb0
  ecx = esi;  // @1356_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1357_55cfb0
  ecx = edx = 0;  // @1358_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1359_55cfb0
  if ((eax & eax) == 0) goto L55e038;  // @1360_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1361_55cfb0
  ecx = edx = 0;  // @1362_55cfb0
  goto L55e039;  // @1363_55cfb0
  L55e038:;
  __builtin_trap();  // @1365_55cfb0
  L55e039:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1367_55cfb0
  L55e03e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1369_55cfb0
  if (eax >= (u32)(105)) goto L55e060;  // @1370_55cfb0
  { u32 v = (u32)((u32)(5612512)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1371_55cfb0
  eax = (eax + 1);  // @1372_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1373_55cfb0
  goto L55e07f;  // @1374_55cfb0
  L55e060:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1376_55cfb0
  ecx = esi;  // @1377_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1378_55cfb0
  ecx = edx = 0;  // @1379_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1380_55cfb0
  if ((eax & eax) == 0) goto L55e079;  // @1381_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1382_55cfb0
  ecx = edx = 0;  // @1383_55cfb0
  goto L55e07a;  // @1384_55cfb0
  L55e079:;
  __builtin_trap();  // @1386_55cfb0
  L55e07a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1388_55cfb0
  L55e07f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1390_55cfb0
  if (eax >= (u32)(105)) goto L55e0a1;  // @1391_55cfb0
  { u32 v = (u32)((u32)(5613136)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1392_55cfb0
  eax = (eax + 1);  // @1393_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1394_55cfb0
  goto L55e0c0;  // @1395_55cfb0
  L55e0a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1397_55cfb0
  ecx = esi;  // @1398_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1399_55cfb0
  ecx = edx = 0;  // @1400_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1401_55cfb0
  if ((eax & eax) == 0) goto L55e0ba;  // @1402_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1403_55cfb0
  ecx = edx = 0;  // @1404_55cfb0
  goto L55e0bb;  // @1405_55cfb0
  L55e0ba:;
  __builtin_trap();  // @1407_55cfb0
  L55e0bb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1409_55cfb0
  L55e0c0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1411_55cfb0
  if (eax >= (u32)(105)) goto L55e0e2;  // @1412_55cfb0
  { u32 v = (u32)((u32)(5611888)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1413_55cfb0
  eax = (eax + 1);  // @1414_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1415_55cfb0
  goto L55e101;  // @1416_55cfb0
  L55e0e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1418_55cfb0
  ecx = esi;  // @1419_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1420_55cfb0
  ecx = edx = 0;  // @1421_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1422_55cfb0
  if ((eax & eax) == 0) goto L55e0fb;  // @1423_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1424_55cfb0
  ecx = edx = 0;  // @1425_55cfb0
  goto L55e0fc;  // @1426_55cfb0
  L55e0fb:;
  __builtin_trap();  // @1428_55cfb0
  L55e0fc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1430_55cfb0
  L55e101:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1432_55cfb0
  if (eax >= (u32)(105)) goto L55e123;  // @1433_55cfb0
  { u32 v = (u32)((u32)(5616384)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1434_55cfb0
  eax = (eax + 1);  // @1435_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1436_55cfb0
  goto L55e142;  // @1437_55cfb0
  L55e123:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1439_55cfb0
  ecx = esi;  // @1440_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1441_55cfb0
  ecx = edx = 0;  // @1442_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1443_55cfb0
  if ((eax & eax) == 0) goto L55e13c;  // @1444_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1445_55cfb0
  ecx = edx = 0;  // @1446_55cfb0
  goto L55e13d;  // @1447_55cfb0
  L55e13c:;
  __builtin_trap();  // @1449_55cfb0
  L55e13d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1451_55cfb0
  L55e142:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1453_55cfb0
  if (eax >= (u32)(105)) goto L55e164;  // @1454_55cfb0
  { u32 v = (u32)((u32)(5620112)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1455_55cfb0
  eax = (eax + 1);  // @1456_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1457_55cfb0
  goto L55e183;  // @1458_55cfb0
  L55e164:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1460_55cfb0
  ecx = esi;  // @1461_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1462_55cfb0
  ecx = edx = 0;  // @1463_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1464_55cfb0
  if ((eax & eax) == 0) goto L55e17d;  // @1465_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1466_55cfb0
  ecx = edx = 0;  // @1467_55cfb0
  goto L55e17e;  // @1468_55cfb0
  L55e17d:;
  __builtin_trap();  // @1470_55cfb0
  L55e17e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1472_55cfb0
  L55e183:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1474_55cfb0
  if (eax >= (u32)(105)) goto L55e1a5;  // @1475_55cfb0
  { u32 v = (u32)((u32)(5622192)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1476_55cfb0
  eax = (eax + 1);  // @1477_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1478_55cfb0
  goto L55e1c4;  // @1479_55cfb0
  L55e1a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1481_55cfb0
  ecx = esi;  // @1482_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1483_55cfb0
  ecx = edx = 0;  // @1484_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1485_55cfb0
  if ((eax & eax) == 0) goto L55e1be;  // @1486_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1487_55cfb0
  ecx = edx = 0;  // @1488_55cfb0
  goto L55e1bf;  // @1489_55cfb0
  L55e1be:;
  __builtin_trap();  // @1491_55cfb0
  L55e1bf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1493_55cfb0
  L55e1c4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1495_55cfb0
  if (eax >= (u32)(105)) goto L55e1e6;  // @1496_55cfb0
  { u32 v = (u32)((u32)(5621568)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1497_55cfb0
  eax = (eax + 1);  // @1498_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1499_55cfb0
  goto L55e205;  // @1500_55cfb0
  L55e1e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1502_55cfb0
  ecx = esi;  // @1503_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1504_55cfb0
  ecx = edx = 0;  // @1505_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1506_55cfb0
  if ((eax & eax) == 0) goto L55e1ff;  // @1507_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1508_55cfb0
  ecx = edx = 0;  // @1509_55cfb0
  goto L55e200;  // @1510_55cfb0
  L55e1ff:;
  __builtin_trap();  // @1512_55cfb0
  L55e200:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1514_55cfb0
  L55e205:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1516_55cfb0
  if (eax >= (u32)(105)) goto L55e227;  // @1517_55cfb0
  { u32 v = (u32)((u32)(5618336)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1518_55cfb0
  eax = (eax + 1);  // @1519_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1520_55cfb0
  goto L55e246;  // @1521_55cfb0
  L55e227:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1523_55cfb0
  ecx = esi;  // @1524_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1525_55cfb0
  ecx = edx = 0;  // @1526_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1527_55cfb0
  if ((eax & eax) == 0) goto L55e240;  // @1528_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1529_55cfb0
  ecx = edx = 0;  // @1530_55cfb0
  goto L55e241;  // @1531_55cfb0
  L55e240:;
  __builtin_trap();  // @1533_55cfb0
  L55e241:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1535_55cfb0
  L55e246:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1537_55cfb0
  if (eax >= (u32)(105)) goto L55e268;  // @1538_55cfb0
  { u32 v = (u32)((u32)(5618576)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1539_55cfb0
  eax = (eax + 1);  // @1540_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1541_55cfb0
  goto L55e287;  // @1542_55cfb0
  L55e268:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1544_55cfb0
  ecx = esi;  // @1545_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1546_55cfb0
  ecx = edx = 0;  // @1547_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1548_55cfb0
  if ((eax & eax) == 0) goto L55e281;  // @1549_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1550_55cfb0
  ecx = edx = 0;  // @1551_55cfb0
  goto L55e282;  // @1552_55cfb0
  L55e281:;
  __builtin_trap();  // @1554_55cfb0
  L55e282:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1556_55cfb0
  L55e287:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1558_55cfb0
  if (eax >= (u32)(105)) goto L55e2a9;  // @1559_55cfb0
  { u32 v = (u32)((u32)(5618384)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1560_55cfb0
  eax = (eax + 1);  // @1561_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1562_55cfb0
  goto L55e2c8;  // @1563_55cfb0
  L55e2a9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1565_55cfb0
  ecx = esi;  // @1566_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1567_55cfb0
  ecx = edx = 0;  // @1568_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1569_55cfb0
  if ((eax & eax) == 0) goto L55e2c2;  // @1570_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1571_55cfb0
  ecx = edx = 0;  // @1572_55cfb0
  goto L55e2c3;  // @1573_55cfb0
  L55e2c2:;
  __builtin_trap();  // @1575_55cfb0
  L55e2c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1577_55cfb0
  L55e2c8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1579_55cfb0
  if (eax >= (u32)(105)) goto L55e2ea;  // @1580_55cfb0
  { u32 v = (u32)((u32)(5618624)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1581_55cfb0
  eax = (eax + 1);  // @1582_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1583_55cfb0
  goto L55e309;  // @1584_55cfb0
  L55e2ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1586_55cfb0
  ecx = esi;  // @1587_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1588_55cfb0
  ecx = edx = 0;  // @1589_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1590_55cfb0
  if ((eax & eax) == 0) goto L55e303;  // @1591_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1592_55cfb0
  ecx = edx = 0;  // @1593_55cfb0
  goto L55e304;  // @1594_55cfb0
  L55e303:;
  __builtin_trap();  // @1596_55cfb0
  L55e304:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1598_55cfb0
  L55e309:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1600_55cfb0
  if (eax >= (u32)(105)) goto L55e32b;  // @1601_55cfb0
  { u32 v = (u32)((u32)(5621616)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1602_55cfb0
  eax = (eax + 1);  // @1603_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1604_55cfb0
  goto L55e34a;  // @1605_55cfb0
  L55e32b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1607_55cfb0
  ecx = esi;  // @1608_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1609_55cfb0
  ecx = edx = 0;  // @1610_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1611_55cfb0
  if ((eax & eax) == 0) goto L55e344;  // @1612_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1613_55cfb0
  ecx = edx = 0;  // @1614_55cfb0
  goto L55e345;  // @1615_55cfb0
  L55e344:;
  __builtin_trap();  // @1617_55cfb0
  L55e345:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1619_55cfb0
  L55e34a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1621_55cfb0
  if (eax >= (u32)(105)) goto L55e36c;  // @1622_55cfb0
  { u32 v = (u32)((u32)(5604000)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1623_55cfb0
  eax = (eax + 1);  // @1624_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1625_55cfb0
  goto L55e38b;  // @1626_55cfb0
  L55e36c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1628_55cfb0
  ecx = esi;  // @1629_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1630_55cfb0
  ecx = edx = 0;  // @1631_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1632_55cfb0
  if ((eax & eax) == 0) goto L55e385;  // @1633_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1634_55cfb0
  ecx = edx = 0;  // @1635_55cfb0
  goto L55e386;  // @1636_55cfb0
  L55e385:;
  __builtin_trap();  // @1638_55cfb0
  L55e386:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1640_55cfb0
  L55e38b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1642_55cfb0
  if (eax >= (u32)(105)) goto L55e3ad;  // @1643_55cfb0
  { u32 v = (u32)((u32)(5604048)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1644_55cfb0
  eax = (eax + 1);  // @1645_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1646_55cfb0
  goto L55e3cc;  // @1647_55cfb0
  L55e3ad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1649_55cfb0
  ecx = esi;  // @1650_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1651_55cfb0
  ecx = edx = 0;  // @1652_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1653_55cfb0
  if ((eax & eax) == 0) goto L55e3c6;  // @1654_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1655_55cfb0
  ecx = edx = 0;  // @1656_55cfb0
  goto L55e3c7;  // @1657_55cfb0
  L55e3c6:;
  __builtin_trap();  // @1659_55cfb0
  L55e3c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1661_55cfb0
  L55e3cc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1663_55cfb0
  if (eax >= (u32)(105)) goto L55e3ee;  // @1664_55cfb0
  { u32 v = (u32)((u32)(5611232)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1665_55cfb0
  eax = (eax + 1);  // @1666_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1667_55cfb0
  goto L55e40d;  // @1668_55cfb0
  L55e3ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1670_55cfb0
  ecx = esi;  // @1671_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1672_55cfb0
  ecx = edx = 0;  // @1673_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1674_55cfb0
  if ((eax & eax) == 0) goto L55e407;  // @1675_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1676_55cfb0
  ecx = edx = 0;  // @1677_55cfb0
  goto L55e408;  // @1678_55cfb0
  L55e407:;
  __builtin_trap();  // @1680_55cfb0
  L55e408:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1682_55cfb0
  L55e40d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1684_55cfb0
  if (eax >= (u32)(105)) goto L55e42f;  // @1685_55cfb0
  { u32 v = (u32)((u32)(5602208)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1686_55cfb0
  eax = (eax + 1);  // @1687_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1688_55cfb0
  goto L55e44e;  // @1689_55cfb0
  L55e42f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1691_55cfb0
  ecx = esi;  // @1692_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1693_55cfb0
  ecx = edx = 0;  // @1694_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1695_55cfb0
  if ((eax & eax) == 0) goto L55e448;  // @1696_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1697_55cfb0
  ecx = edx = 0;  // @1698_55cfb0
  goto L55e449;  // @1699_55cfb0
  L55e448:;
  __builtin_trap();  // @1701_55cfb0
  L55e449:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1703_55cfb0
  L55e44e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1705_55cfb0
  if (eax >= (u32)(105)) goto L55e470;  // @1706_55cfb0
  { u32 v = (u32)((u32)(5616624)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1707_55cfb0
  eax = (eax + 1);  // @1708_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1709_55cfb0
  goto L55e48f;  // @1710_55cfb0
  L55e470:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1712_55cfb0
  ecx = esi;  // @1713_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1714_55cfb0
  ecx = edx = 0;  // @1715_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1716_55cfb0
  if ((eax & eax) == 0) goto L55e489;  // @1717_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1718_55cfb0
  ecx = edx = 0;  // @1719_55cfb0
  goto L55e48a;  // @1720_55cfb0
  L55e489:;
  __builtin_trap();  // @1722_55cfb0
  L55e48a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1724_55cfb0
  L55e48f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1726_55cfb0
  if (eax >= (u32)(105)) goto L55e4b1;  // @1727_55cfb0
  { u32 v = (u32)((u32)(5618928)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1728_55cfb0
  eax = (eax + 1);  // @1729_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1730_55cfb0
  goto L55e4d0;  // @1731_55cfb0
  L55e4b1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1733_55cfb0
  ecx = esi;  // @1734_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1735_55cfb0
  ecx = edx = 0;  // @1736_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1737_55cfb0
  if ((eax & eax) == 0) goto L55e4ca;  // @1738_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1739_55cfb0
  ecx = edx = 0;  // @1740_55cfb0
  goto L55e4cb;  // @1741_55cfb0
  L55e4ca:;
  __builtin_trap();  // @1743_55cfb0
  L55e4cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1745_55cfb0
  L55e4d0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1747_55cfb0
  if (eax >= (u32)(105)) goto L55e4f2;  // @1748_55cfb0
  { u32 v = (u32)((u32)(5608176)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1749_55cfb0
  eax = (eax + 1);  // @1750_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1751_55cfb0
  goto L55e511;  // @1752_55cfb0
  L55e4f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1754_55cfb0
  ecx = esi;  // @1755_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1756_55cfb0
  ecx = edx = 0;  // @1757_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1758_55cfb0
  if ((eax & eax) == 0) goto L55e50b;  // @1759_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1760_55cfb0
  ecx = edx = 0;  // @1761_55cfb0
  goto L55e50c;  // @1762_55cfb0
  L55e50b:;
  __builtin_trap();  // @1764_55cfb0
  L55e50c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1766_55cfb0
  L55e511:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1768_55cfb0
  if (eax >= (u32)(105)) goto L55e533;  // @1769_55cfb0
  { u32 v = (u32)((u32)(5619904)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1770_55cfb0
  eax = (eax + 1);  // @1771_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1772_55cfb0
  goto L55e552;  // @1773_55cfb0
  L55e533:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1775_55cfb0
  ecx = esi;  // @1776_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1777_55cfb0
  ecx = edx = 0;  // @1778_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1779_55cfb0
  if ((eax & eax) == 0) goto L55e54c;  // @1780_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1781_55cfb0
  ecx = edx = 0;  // @1782_55cfb0
  goto L55e54d;  // @1783_55cfb0
  L55e54c:;
  __builtin_trap();  // @1785_55cfb0
  L55e54d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1787_55cfb0
  L55e552:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1789_55cfb0
  if (eax >= (u32)(105)) goto L55e574;  // @1790_55cfb0
  { u32 v = (u32)((u32)(5623440)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1791_55cfb0
  eax = (eax + 1);  // @1792_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1793_55cfb0
  goto L55e593;  // @1794_55cfb0
  L55e574:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1796_55cfb0
  ecx = esi;  // @1797_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1798_55cfb0
  ecx = edx = 0;  // @1799_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1800_55cfb0
  if ((eax & eax) == 0) goto L55e58d;  // @1801_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1802_55cfb0
  ecx = edx = 0;  // @1803_55cfb0
  goto L55e58e;  // @1804_55cfb0
  L55e58d:;
  __builtin_trap();  // @1806_55cfb0
  L55e58e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1808_55cfb0
  L55e593:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1810_55cfb0
  if (eax >= (u32)(105)) goto L55e5b5;  // @1811_55cfb0
  { u32 v = (u32)((u32)(5611408)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1812_55cfb0
  eax = (eax + 1);  // @1813_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1814_55cfb0
  goto L55e5d4;  // @1815_55cfb0
  L55e5b5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1817_55cfb0
  ecx = esi;  // @1818_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1819_55cfb0
  ecx = edx = 0;  // @1820_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1821_55cfb0
  if ((eax & eax) == 0) goto L55e5ce;  // @1822_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1823_55cfb0
  ecx = edx = 0;  // @1824_55cfb0
  goto L55e5cf;  // @1825_55cfb0
  L55e5ce:;
  __builtin_trap();  // @1827_55cfb0
  L55e5cf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1829_55cfb0
  L55e5d4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1831_55cfb0
  if (eax >= (u32)(105)) goto L55e5f6;  // @1832_55cfb0
  { u32 v = (u32)((u32)(5619040)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1833_55cfb0
  eax = (eax + 1);  // @1834_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1835_55cfb0
  goto L55e615;  // @1836_55cfb0
  L55e5f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1838_55cfb0
  ecx = esi;  // @1839_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1840_55cfb0
  ecx = edx = 0;  // @1841_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1842_55cfb0
  if ((eax & eax) == 0) goto L55e60f;  // @1843_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1844_55cfb0
  ecx = edx = 0;  // @1845_55cfb0
  goto L55e610;  // @1846_55cfb0
  L55e60f:;
  __builtin_trap();  // @1848_55cfb0
  L55e610:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1850_55cfb0
  L55e615:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1852_55cfb0
  if (eax >= (u32)(105)) goto L55e637;  // @1853_55cfb0
  { u32 v = (u32)((u32)(5610000)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1854_55cfb0
  eax = (eax + 1);  // @1855_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1856_55cfb0
  goto L55e656;  // @1857_55cfb0
  L55e637:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1859_55cfb0
  ecx = esi;  // @1860_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1861_55cfb0
  ecx = edx = 0;  // @1862_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1863_55cfb0
  if ((eax & eax) == 0) goto L55e650;  // @1864_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1865_55cfb0
  ecx = edx = 0;  // @1866_55cfb0
  goto L55e651;  // @1867_55cfb0
  L55e650:;
  __builtin_trap();  // @1869_55cfb0
  L55e651:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1871_55cfb0
  L55e656:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1873_55cfb0
  if (eax >= (u32)(105)) goto L55e678;  // @1874_55cfb0
  { u32 v = (u32)((u32)(5621520)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1875_55cfb0
  eax = (eax + 1);  // @1876_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1877_55cfb0
  goto L55e697;  // @1878_55cfb0
  L55e678:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1880_55cfb0
  ecx = esi;  // @1881_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1882_55cfb0
  ecx = edx = 0;  // @1883_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1884_55cfb0
  if ((eax & eax) == 0) goto L55e691;  // @1885_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1886_55cfb0
  ecx = edx = 0;  // @1887_55cfb0
  goto L55e692;  // @1888_55cfb0
  L55e691:;
  __builtin_trap();  // @1890_55cfb0
  L55e692:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1892_55cfb0
  L55e697:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1894_55cfb0
  if (eax >= (u32)(105)) goto L55e6b9;  // @1895_55cfb0
  { u32 v = (u32)((u32)(5615584)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1896_55cfb0
  eax = (eax + 1);  // @1897_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1898_55cfb0
  goto L55e6d8;  // @1899_55cfb0
  L55e6b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1901_55cfb0
  ecx = esi;  // @1902_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1903_55cfb0
  ecx = edx = 0;  // @1904_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1905_55cfb0
  if ((eax & eax) == 0) goto L55e6d2;  // @1906_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1907_55cfb0
  ecx = edx = 0;  // @1908_55cfb0
  goto L55e6d3;  // @1909_55cfb0
  L55e6d2:;
  __builtin_trap();  // @1911_55cfb0
  L55e6d3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1913_55cfb0
  L55e6d8:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1915_55cfb0
  if (eax >= (u32)(105)) goto L55e6fa;  // @1916_55cfb0
  { u32 v = (u32)((u32)(5615296)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1917_55cfb0
  eax = (eax + 1);  // @1918_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1919_55cfb0
  goto L55e719;  // @1920_55cfb0
  L55e6fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1922_55cfb0
  ecx = esi;  // @1923_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1924_55cfb0
  ecx = edx = 0;  // @1925_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1926_55cfb0
  if ((eax & eax) == 0) goto L55e713;  // @1927_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1928_55cfb0
  ecx = edx = 0;  // @1929_55cfb0
  goto L55e714;  // @1930_55cfb0
  L55e713:;
  __builtin_trap();  // @1932_55cfb0
  L55e714:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1934_55cfb0
  L55e719:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1936_55cfb0
  if (eax >= (u32)(105)) goto L55e73b;  // @1937_55cfb0
  { u32 v = (u32)((u32)(5621984)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1938_55cfb0
  eax = (eax + 1);  // @1939_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1940_55cfb0
  goto L55e75a;  // @1941_55cfb0
  L55e73b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1943_55cfb0
  ecx = esi;  // @1944_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1945_55cfb0
  ecx = edx = 0;  // @1946_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1947_55cfb0
  if ((eax & eax) == 0) goto L55e754;  // @1948_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1949_55cfb0
  ecx = edx = 0;  // @1950_55cfb0
  goto L55e755;  // @1951_55cfb0
  L55e754:;
  __builtin_trap();  // @1953_55cfb0
  L55e755:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1955_55cfb0
  L55e75a:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1957_55cfb0
  if (eax >= (u32)(105)) goto L55e77c;  // @1958_55cfb0
  { u32 v = (u32)((u32)(5607088)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1959_55cfb0
  eax = (eax + 1);  // @1960_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1961_55cfb0
  goto L55e79b;  // @1962_55cfb0
  L55e77c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1964_55cfb0
  ecx = esi;  // @1965_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1966_55cfb0
  ecx = edx = 0;  // @1967_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1968_55cfb0
  if ((eax & eax) == 0) goto L55e795;  // @1969_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1970_55cfb0
  ecx = edx = 0;  // @1971_55cfb0
  goto L55e796;  // @1972_55cfb0
  L55e795:;
  __builtin_trap();  // @1974_55cfb0
  L55e796:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1976_55cfb0
  L55e79b:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1978_55cfb0
  if (eax >= (u32)(105)) goto L55e7bd;  // @1979_55cfb0
  { u32 v = (u32)((u32)(5615904)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @1980_55cfb0
  eax = (eax + 1);  // @1981_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @1982_55cfb0
  goto L55e7dc;  // @1983_55cfb0
  L55e7bd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1985_55cfb0
  ecx = esi;  // @1986_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @1987_55cfb0
  ecx = edx = 0;  // @1988_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @1989_55cfb0
  if ((eax & eax) == 0) goto L55e7d6;  // @1990_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @1991_55cfb0
  ecx = edx = 0;  // @1992_55cfb0
  goto L55e7d7;  // @1993_55cfb0
  L55e7d6:;
  __builtin_trap();  // @1995_55cfb0
  L55e7d7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @1997_55cfb0
  L55e7dc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @1999_55cfb0
  if (eax >= (u32)(105)) goto L55e7fe;  // @2000_55cfb0
  { u32 v = (u32)((u32)(5623488)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2001_55cfb0
  eax = (eax + 1);  // @2002_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2003_55cfb0
  goto L55e81d;  // @2004_55cfb0
  L55e7fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2006_55cfb0
  ecx = esi;  // @2007_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2008_55cfb0
  ecx = edx = 0;  // @2009_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2010_55cfb0
  if ((eax & eax) == 0) goto L55e817;  // @2011_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2012_55cfb0
  ecx = edx = 0;  // @2013_55cfb0
  goto L55e818;  // @2014_55cfb0
  L55e817:;
  __builtin_trap();  // @2016_55cfb0
  L55e818:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2018_55cfb0
  L55e81d:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2020_55cfb0
  if (eax >= (u32)(105)) goto L55e83f;  // @2021_55cfb0
  { u32 v = (u32)((u32)(5623648)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2022_55cfb0
  eax = (eax + 1);  // @2023_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2024_55cfb0
  goto L55e85e;  // @2025_55cfb0
  L55e83f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2027_55cfb0
  ecx = esi;  // @2028_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2029_55cfb0
  ecx = edx = 0;  // @2030_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2031_55cfb0
  if ((eax & eax) == 0) goto L55e858;  // @2032_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2033_55cfb0
  ecx = edx = 0;  // @2034_55cfb0
  goto L55e859;  // @2035_55cfb0
  L55e858:;
  __builtin_trap();  // @2037_55cfb0
  L55e859:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2039_55cfb0
  L55e85e:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2041_55cfb0
  if (eax >= (u32)(105)) goto L55e880;  // @2042_55cfb0
  { u32 v = (u32)((u32)(5607856)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2043_55cfb0
  eax = (eax + 1);  // @2044_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2045_55cfb0
  goto L55e89f;  // @2046_55cfb0
  L55e880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2048_55cfb0
  ecx = esi;  // @2049_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2050_55cfb0
  ecx = edx = 0;  // @2051_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2052_55cfb0
  if ((eax & eax) == 0) goto L55e899;  // @2053_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2054_55cfb0
  ecx = edx = 0;  // @2055_55cfb0
  goto L55e89a;  // @2056_55cfb0
  L55e899:;
  __builtin_trap();  // @2058_55cfb0
  L55e89a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2060_55cfb0
  L55e89f:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2062_55cfb0
  if (eax >= (u32)(105)) goto L55e8c1;  // @2063_55cfb0
  { u32 v = (u32)((u32)(5608944)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2064_55cfb0
  eax = (eax + 1);  // @2065_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2066_55cfb0
  goto L55e8e0;  // @2067_55cfb0
  L55e8c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2069_55cfb0
  ecx = esi;  // @2070_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2071_55cfb0
  ecx = edx = 0;  // @2072_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2073_55cfb0
  if ((eax & eax) == 0) goto L55e8da;  // @2074_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2075_55cfb0
  ecx = edx = 0;  // @2076_55cfb0
  goto L55e8db;  // @2077_55cfb0
  L55e8da:;
  __builtin_trap();  // @2079_55cfb0
  L55e8db:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2081_55cfb0
  L55e8e0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2083_55cfb0
  if (eax >= (u32)(105)) goto L55e902;  // @2084_55cfb0
  { u32 v = (u32)((u32)(5616960)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2085_55cfb0
  eax = (eax + 1);  // @2086_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2087_55cfb0
  goto L55e921;  // @2088_55cfb0
  L55e902:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2090_55cfb0
  ecx = esi;  // @2091_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2092_55cfb0
  ecx = edx = 0;  // @2093_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2094_55cfb0
  if ((eax & eax) == 0) goto L55e91b;  // @2095_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2096_55cfb0
  ecx = edx = 0;  // @2097_55cfb0
  goto L55e91c;  // @2098_55cfb0
  L55e91b:;
  __builtin_trap();  // @2100_55cfb0
  L55e91c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2102_55cfb0
  L55e921:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2104_55cfb0
  if (eax >= (u32)(105)) goto L55e943;  // @2105_55cfb0
  { u32 v = (u32)((u32)(6357248)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2106_55cfb0
  eax = (eax + 1);  // @2107_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2108_55cfb0
  goto L55e962;  // @2109_55cfb0
  L55e943:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2111_55cfb0
  ecx = esi;  // @2112_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2113_55cfb0
  ecx = edx = 0;  // @2114_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2115_55cfb0
  if ((eax & eax) == 0) goto L55e95c;  // @2116_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2117_55cfb0
  ecx = edx = 0;  // @2118_55cfb0
  goto L55e95d;  // @2119_55cfb0
  L55e95c:;
  __builtin_trap();  // @2121_55cfb0
  L55e95d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2123_55cfb0
  L55e962:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2125_55cfb0
  if (eax >= (u32)(105)) goto L55e984;  // @2126_55cfb0
  { u32 v = (u32)((u32)(5604064)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2127_55cfb0
  eax = (eax + 1);  // @2128_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2129_55cfb0
  goto L55e9a3;  // @2130_55cfb0
  L55e984:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2132_55cfb0
  ecx = esi;  // @2133_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2134_55cfb0
  ecx = edx = 0;  // @2135_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2136_55cfb0
  if ((eax & eax) == 0) goto L55e99d;  // @2137_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2138_55cfb0
  ecx = edx = 0;  // @2139_55cfb0
  goto L55e99e;  // @2140_55cfb0
  L55e99d:;
  __builtin_trap();  // @2142_55cfb0
  L55e99e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2144_55cfb0
  L55e9a3:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2146_55cfb0
  if (eax >= (u32)(105)) goto L55e9c5;  // @2147_55cfb0
  { u32 v = (u32)((u32)(5616336)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2148_55cfb0
  eax = (eax + 1);  // @2149_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2150_55cfb0
  goto L55e9e4;  // @2151_55cfb0
  L55e9c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2153_55cfb0
  ecx = esi;  // @2154_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2155_55cfb0
  ecx = edx = 0;  // @2156_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2157_55cfb0
  if ((eax & eax) == 0) goto L55e9de;  // @2158_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2159_55cfb0
  ecx = edx = 0;  // @2160_55cfb0
  goto L55e9df;  // @2161_55cfb0
  L55e9de:;
  __builtin_trap();  // @2163_55cfb0
  L55e9df:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7421712), sizeof v); (u32)v; });  // @2165_55cfb0
  L55e9e4:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L55ea3c;  // @2167_55cfb0
  if (eax >= (u32)(105)) goto L55ea12;  // @2168_55cfb0
  { u32 v = (u32)((u32)(5621824)); __builtin_memcpy((void *)(u32)(eax*4 + 7421720), &v, sizeof v); }  // @2169_55cfb0
  ecx = esi;  // @2170_55cfb0
  eax = (eax + 1);  // @2171_55cfb0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @2172_55cfb0
  p0_ = edi;  // @2173_55cfb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7421712), &v, sizeof v); }  // @2174_55cfb0
  eax = ext_508680_thiscall2(ecx, (u32)(p0_));  // @2175_55cfb0
  ecx = edx = 0;  // @2176_55cfb0
  return eax;  // @2177_55cfb0
  L55ea12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2179_55cfb0
  ecx = esi;  // @2180_55cfb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(6971044));  // @2181_55cfb0
  ecx = edx = 0;  // @2182_55cfb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @2183_55cfb0
  if ((eax & eax) == 0) goto L55ea3b;  // @2184_55cfb0
  eax = ((u32(STDCALL *)(void))(eax))();  // @2185_55cfb0
  ecx = edx = 0;  // @2186_55cfb0
  p1_ = edi;  // @2187_55cfb0
  ecx = esi;  // @2188_55cfb0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @2189_55cfb0
  eax = ext_508680_thiscall2(ecx, (u32)(p1_));  // @2190_55cfb0
  ecx = edx = 0;  // @2191_55cfb0
  return eax;  // @2192_55cfb0
  L55ea3b:;
  __builtin_trap();  // @2194_55cfb0
  L55ea3c:;
  p2_ = edi;  // @2196_55cfb0
  ecx = esi;  // @2197_55cfb0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @2198_55cfb0
  eax = ext_508680_thiscall2(ecx, (u32)(p2_));  // @2199_55cfb0
  ecx = edx = 0;  // @2200_55cfb0
  return eax;  // @2201_55cfb0
}
PCREG(55cfb0, lifted_55cfb0);

extern "C" u32 THISCALL lifted_661940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661940
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_EBX, 4);  // @1_661940
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_ESI, 4);  // @2_661940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @4_661940
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EDI, 4);  // @5_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @6_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_661940
  edi = edx;  // @8_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @9_661940
  eax = edx;  // @10_661940
  ebx = (edx & 0xffff);  // @11_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @12_661940
  eax = (eax >> (u32)(31));  // @13_661940
  edx = (edx + ecx);  // @14_661940
  edi = (edi >> (u32)(16));  // @15_661940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @16_661940
  edi = (edi & (u32)(32767));  // @17_661940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @18_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @19_661940
  ebx = (ebx + edi);  // @20_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @21_661940
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax) != 0) goto L661994;  // @22_661940
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @23_661940
  return eax;  // @24_661940
  L661994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @26_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @27_661940
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @28_661940
  eax = (u32)(eax + edi*2);  // @29_661940
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @30_661940
  p0_ = ebx;  // @31_661940
  p1_ = edi;  // @32_661940
  p2_ = eax;  // @33_661940
  p3_ = ecx;  // @34_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @35_661940
  eax = ext_661b40_stdcall8((u32)(p3_), (u32)(p2_), (u32)(p1_), (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @36_661940
  ecx = edx = 0;  // @37_661940
  return eax;  // @38_661940
}
PCREG(661940, lifted_661940);

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
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4fa390
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @1_4fa390
  eax = (eax + (u32)(4294967040));  // @2_4fa390
  esi = ecx;  // @3_4fa390
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_EDI, 4);  // @4_4fa390
  if (eax > (u32)(3)) goto L4fa3dc;  // @5_4fa390
  switch (eax) { case 0: goto L4fa3b7; case 1: goto L4fa3b3; case 2: goto L4fa3ab; case 3: goto L4fa3af; default: __builtin_trap(); }  // @6_4fa390
  L4fa3ab:;
  goto L4fa3b9;  // @8_4fa390
  L4fa3af:;
  goto L4fa3b9;  // @10_4fa390
  L4fa3b3:;
  goto L4fa3b9;  // @12_4fa390
  L4fa3b7:;
  L4fa3b9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_4fa390
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4), (u32)(3), (u32)(2), (u32)(1));  // @16_4fa390
  ecx = edx = 0;  // @17_4fa390
  edi = eax;  // @18_4fa390
  if ((edi & edi) == 0) goto L4fa3dc;  // @19_4fa390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_4fa390
  ecx = esi;  // @21_4fa390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @22_4fa390
  ecx = edx = 0;  // @23_4fa390
  p0_ = edi;  // @24_4fa390
  ecx = eax;  // @25_4fa390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_4fa390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, (u32)(p0_));  // @27_4fa390
  ecx = edx = 0;  // @28_4fa390
  L4fa3dc:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @30_4fa390
  return eax;  // @31_4fa390
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
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4fa720
  eax = (eax - 1);  // @1_4fa720
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @2_4fa720
  esi = ecx;  // @3_4fa720
  if (eax > (u32)(3)) goto L4fa7a3;  // @4_4fa720
  switch (eax) { case 0: goto L4fa736; case 1: goto L4fa751; case 2: goto L4fa76c; case 3: goto L4fa78a; default: __builtin_trap(); }  // @5_4fa720
  L4fa736:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @10_4fa720
  ecx = edx = 0;  // @11_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @12_4fa720
  return eax;  // @13_4fa720
  L4fa751:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @18_4fa720
  ecx = edx = 0;  // @19_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @20_4fa720
  return eax;  // @21_4fa720
  L4fa76c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @24_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @26_4fa720
  ecx = edx = 0;  // @27_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @28_4fa720
  return eax;  // @29_4fa720
  L4fa78a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_4fa720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_4fa720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4fa720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @34_4fa720
  ecx = edx = 0;  // @35_4fa720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @36_4fa720
  L4fa7a3:;
  return eax;  // @38_4fa720
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

extern "C" u32 THISCALL lifted_471ff0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_471ff0
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_EBX, 4);  // @1_471ff0
  __builtin_memcpy((void *)(u32)(EBP - 8), &SENT_ESI, 4);  // @2_471ff0
  esi = ecx;  // @3_471ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_471ff0
  __builtin_memcpy((void *)(u32)(EBP - 12), &SENT_EDI, 4);  // @5_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @7_471ff0
  ecx = edx = 0;  // @8_471ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @9_471ff0
  ebx = eax;  // @10_471ff0
  eax = (u32)(ecx - 1);  // @11_471ff0
  if (eax > (u32)(14)) goto L47208c;  // @12_471ff0
  switch (eax) { case 0: goto L472046; case 1: goto L472046; case 2: goto L472046; case 3: goto L472046; case 4: goto L47206d; case 5: goto L47206d; case 6: goto L47201f; case 7: goto L472046; case 8: goto L47206d; case 9: goto L47206d; case 10: goto L47206d; case 11: goto L47206d; case 12: goto L47206d; case 13: goto L47206d; case 14: goto L47206d; default: __builtin_trap(); }  // @13_471ff0
  L47201f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_471ff0
  p0_ = ecx;  // @16_471ff0
  ecx = esi;  // @17_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 1004)))(ecx, (u32)(p0_));  // @18_471ff0
  ecx = edx = 0;  // @19_471ff0
  edi = eax;  // @20_471ff0
  p1_ = ebx;  // @21_471ff0
  ecx = edi;  // @22_471ff0
  eax = ext_4870b0_thiscall2(ecx, (u32)(p1_));  // @23_471ff0
  ecx = edx = 0;  // @24_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_471ff0
  ecx = esi;  // @26_471ff0
  p2_ = edi;  // @27_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p2_));  // @28_471ff0
  ecx = edx = 0;  // @29_471ff0
  return eax;  // @30_471ff0
  L472046:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @32_471ff0
  p3_ = ecx;  // @33_471ff0
  ecx = esi;  // @34_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1004)))(ecx, (u32)(p3_));  // @35_471ff0
  ecx = edx = 0;  // @36_471ff0
  edi = eax;  // @37_471ff0
  p4_ = ebx;  // @38_471ff0
  ecx = edi;  // @39_471ff0
  eax = ext_4870b0_thiscall2(ecx, (u32)(p4_));  // @40_471ff0
  ecx = edx = 0;  // @41_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_471ff0
  ecx = esi;  // @43_471ff0
  p5_ = edi;  // @44_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p5_));  // @45_471ff0
  ecx = edx = 0;  // @46_471ff0
  return eax;  // @47_471ff0
  L47206d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @49_471ff0
  p6_ = ecx;  // @50_471ff0
  ecx = esi;  // @51_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1004)))(ecx, (u32)(p6_));  // @52_471ff0
  ecx = edx = 0;  // @53_471ff0
  edi = eax;  // @54_471ff0
  ecx = esi;  // @55_471ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_471ff0
  p7_ = edi;  // @57_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p7_));  // @58_471ff0
  ecx = edx = 0;  // @59_471ff0
  return eax;  // @60_471ff0
  L47208c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @62_471ff0
  if ((eax & eax) == 0) goto L472099;  // @63_471ff0
  eax = ((u32(STDCALL *)(void))(eax))();  // @64_471ff0
  ecx = edx = 0;  // @65_471ff0
  goto L47209a;  // @66_471ff0
  L472099:;
  __builtin_trap();  // @68_471ff0
  L47209a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_471ff0
  ecx = esi;  // @71_471ff0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @72_471ff0
  p8_ = edi;  // @73_471ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 984)))(ecx, (u32)(p8_));  // @74_471ff0
  ecx = edx = 0;  // @75_471ff0
  return eax;  // @76_471ff0
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

extern "C" u32 THISCALL lifted_4f9f50(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4f9f50
  edx = 0;  // @1_4f9f50
  __builtin_memcpy((void *)(u32)(EBP - 4), &SENT_ESI, 4);  // @2_4f9f50
  esi = ecx;  // @3_4f9f50
  if (eax > (u32)(4)) goto L4fa0af;  // @4_4f9f50
  switch (eax) { case 0: goto L4f9f6b; case 1: goto L4f9fbe; case 2: goto L4fa000; case 3: goto L4fa042; case 4: goto L4fa07b; default: __builtin_trap(); }  // @5_4f9f50
  L4f9f6b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4));  // @8_4f9f50
  ecx = edx = 0;  // @9_4f9f50
  edx = eax;  // @10_4f9f50
  if ((edx & edx) != 0) goto L4fa0af;  // @11_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_4f9f50
  ecx = esi;  // @13_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(2));  // @14_4f9f50
  ecx = edx = 0;  // @15_4f9f50
  edx = eax;  // @16_4f9f50
  if ((edx & edx) != 0) goto L4fa0af;  // @17_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_4f9f50
  ecx = esi;  // @19_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(3));  // @20_4f9f50
  ecx = edx = 0;  // @21_4f9f50
  edx = eax;  // @22_4f9f50
  if ((edx & edx) != 0) goto L4fa0af;  // @23_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_4f9f50
  ecx = esi;  // @25_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(1));  // @26_4f9f50
  ecx = edx = 0;  // @27_4f9f50
  edx = eax;  // @28_4f9f50
  return eax;  // @29_4f9f50
  L4f9fbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 120), sizeof v); (u32)v; }));  // @34_4f9f50
  ecx = edx = 0;  // @35_4f9f50
  edx = eax;  // @36_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @37_4f9f50
  if (edx == esi) goto L4fa0af;  // @38_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @39_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @40_4f9f50
  ecx = edx;  // @41_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(1));  // @42_4f9f50
  ecx = edx = 0;  // @43_4f9f50
  edx = eax;  // @44_4f9f50
  return eax;  // @45_4f9f50
  L4fa000:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @48_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; }));  // @50_4f9f50
  ecx = edx = 0;  // @51_4f9f50
  edx = eax;  // @52_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @53_4f9f50
  if (edx == esi) goto L4fa0af;  // @54_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @55_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @56_4f9f50
  ecx = edx;  // @57_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(2));  // @58_4f9f50
  ecx = edx = 0;  // @59_4f9f50
  edx = eax;  // @60_4f9f50
  return eax;  // @61_4f9f50
  L4fa042:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 128), sizeof v); (u32)v; }));  // @66_4f9f50
  ecx = edx = 0;  // @67_4f9f50
  edx = eax;  // @68_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @69_4f9f50
  if (edx == esi) goto L4fa0af;  // @70_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @71_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @72_4f9f50
  ecx = edx;  // @73_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(3));  // @74_4f9f50
  ecx = edx = 0;  // @75_4f9f50
  edx = eax;  // @76_4f9f50
  return eax;  // @77_4f9f50
  L4fa07b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_4f9f50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @80_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; }));  // @82_4f9f50
  ecx = edx = 0;  // @83_4f9f50
  edx = eax;  // @84_4f9f50
  if ((edx & edx) == 0) goto L4fa0af;  // @85_4f9f50
  if (edx == esi) goto L4fa0af;  // @86_4f9f50
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 108), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L4fa0af;  // @87_4f9f50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @88_4f9f50
  ecx = edx;  // @89_4f9f50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 792)))(ecx, (u32)(4));  // @90_4f9f50
  ecx = edx = 0;  // @91_4f9f50
  edx = eax;  // @92_4f9f50
  L4fa0af:;
  eax = edx;  // @94_4f9f50
  return eax;  // @95_4f9f50
}
PCREG(4f9f50, lifted_4f9f50);

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

extern "C" u32 lifted_427120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(EBP - 8);  // @0_427120
  p0_ = eax;  // @1_427120
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676124))((u32)(p0_));  // @2_427120
  ecx = edx = 0;  // @3_427120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @4_427120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @5_427120
  return eax;  // @6_427120
}
PCREG(427120, lifted_427120);

extern "C" u32 STDCALL lifted_427fd0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676130))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @0_427fd0
  ecx = edx = 0;  // @1_427fd0
  if ((eax & eax) != 0) goto L428006;  // @2_427fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @3_427fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_427fd0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6785452), (u32)(387));  // @5_427fd0
  ecx = edx = 0;  // @6_427fd0
  p0_ = eax;  // @7_427fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_427fd0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6786192));  // @9_427fd0
  ecx = edx = 0;  // @10_427fd0
  L428006:;
  return eax;  // @12_427fd0
}
PCREG(427fd0, lifted_427fd0);

extern "C" u32 THISCALL lifted_41f0d0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x664012);  // @h_41f0d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy((void *)(u32)(EBP - 16), &SENT_ESI, 4);  // @0_41f0d0
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_EDI, 4);  // @1_41f0d0
  esi = ecx;  // @2_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @3_41f0d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_41f0d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 61), &v, sizeof v); }  // @5_41f0d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @6_41f0d0
  if ((ecx & ecx) == 0) goto L41f116;  // @7_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_41f0d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(140));  // @9_41f0d0
  ecx = edx = 0;  // @10_41f0d0
  goto L41f11f;  // @11_41f0d0
  L41f116:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6762f0))();  // @13_41f0d0
  ecx = edx = 0;  // @14_41f0d0
  L41f11f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @16_41f0d0
  reg.state = (s32)((u32)(0));  // @17_41f0d0
  if ((eax & eax) == 0) goto L41f13f;  // @18_41f0d0
  ecx = eax;  // @19_41f0d0
  p0_ = edi;  // @20_41f0d0
  eax = ext_4d0f30_thiscall4(ecx, (u32)(p0_), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @21_41f0d0
  ecx = edx = 0;  // @22_41f0d0
  ecx = eax;  // @23_41f0d0
  goto L41f141;  // @24_41f0d0
  L41f13f:;
  ecx = 0;  // @26_41f0d0
  L41f141:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @28_41f0d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax*4 + 53), &v, sizeof v); }  // @29_41f0d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @30_41f0d0
  SEH_LEAVE();  // @31_41f0d0
  return eax;  // @32_41f0d0
}
PCREG(41f0d0, lifted_41f0d0);

extern "C" u32 THISCALL lifted_424fc0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x664512);  // @h_424fc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy((void *)(u32)(EBP - 280), &SENT_ESI, 4);  // @0_424fc0
  __builtin_memcpy((void *)(u32)(EBP - 284), &SENT_EDI, 4);  // @1_424fc0
  esi = ecx;  // @2_424fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_424fc0
  eax = ecx;  // @4_424fc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_424fc0
  eax = (eax >> (u32)(8));  // @6_424fc0
  if ((eax & eax) == 0) goto L425007;  // @7_424fc0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L425119;  // @8_424fc0
  L425007:;
  eax = (ecx & 0xff);  // @10_424fc0
  eax = (eax + (u32)(-2));  // @11_424fc0
  if (eax > (u32)(5)) goto L425119;  // @12_424fc0
  switch (eax) { case 0: goto L425067; case 1: goto L425079; case 2: goto L425099; case 3: goto L4250c3; case 4: goto L42501d; case 5: goto L4250a5; default: __builtin_trap(); }  // @13_424fc0
  L42501d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L42505e;  // @15_424fc0
  eax = ext_41e290_cdecl1((u32)(40));  // @16_424fc0
  ecx = edx = 0;  // @17_424fc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @18_424fc0
  reg.state = (s32)((u32)(0));  // @19_424fc0
  if ((eax & eax) == 0) goto L42504e;  // @20_424fc0
  ecx = eax;  // @21_424fc0
  eax = ext_4cca60_thiscall3(ecx, (u32)(128), (u32)(5));  // @22_424fc0
  ecx = edx = 0;  // @23_424fc0
  goto L425050;  // @24_424fc0
  L42504e:;
  eax = 0;  // @26_424fc0
  L425050:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @28_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_424fc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6980), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 6980), &v, sizeof v); }  // @30_424fc0
  L42505e:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @32_424fc0
  goto L425119;  // @33_424fc0
  L425067:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L425119;  // @35_424fc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @36_424fc0
  goto L425119;  // @37_424fc0
  L425079:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L425119;  // @39_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_424fc0
  ecx = esi;  // @41_424fc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @42_424fc0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(8), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }), (u32)(0));  // @43_424fc0
  ecx = edx = 0;  // @44_424fc0
  goto L425119;  // @45_424fc0
  L425099:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != edi) goto L4250a5;  // @47_424fc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @48_424fc0
  L4250a5:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L4250bd;  // @50_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_424fc0
  ecx = esi;  // @52_424fc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 72)))(ecx);  // @53_424fc0
  ecx = edx = 0;  // @54_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_424fc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6980), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 6980), &v, sizeof v); }  // @56_424fc0
  L4250bd:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @58_424fc0
  goto L425119;  // @59_424fc0
  L4250c3:;
  if ((edi & edi) == 0) goto L425106;  // @61_424fc0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L4250fd;  // @62_424fc0
  eax = (u32)(EBP - 272);  // @63_424fc0
  p0_ = eax;  // @64_424fc0
  p1_ = edi;  // @65_424fc0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6760f8))((u32)(p1_), (u32)(p0_), (u32)(255));  // @66_424fc0
  ecx = edx = 0;  // @67_424fc0
  p2_ = edi;  // @68_424fc0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760f0))((u32)(p2_));  // @69_424fc0
  ecx = edx = 0;  // @70_424fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_424fc0
  edx = (u32)(EBP - 272);  // @72_424fc0
  p3_ = edx;  // @73_424fc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_424fc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, (u32)(p3_), (u32)(0));  // @75_424fc0
  ecx = edx = 0;  // @76_424fc0
  goto L425119;  // @77_424fc0
  L4250fd:;
  p4_ = edi;  // @79_424fc0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760f0))((u32)(p4_));  // @80_424fc0
  ecx = edx = 0;  // @81_424fc0
  goto L425119;  // @82_424fc0
  L425106:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @84_424fc0
  p5_ = eax;  // @85_424fc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @86_424fc0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 52)))((u32)(p5_), (u32)(6784928));  // @87_424fc0
  ecx = edx = 0;  // @88_424fc0
  L425119:;
  eax = 0;  // @90_424fc0
  SEH_LEAVE();  // @91_424fc0
  ext_633654(G(u32, 0x6f5630));  // @92_424fc0
  return eax;  // @93_424fc0
}
PCREG(424fc0, lifted_424fc0);

extern "C" u32 lifted_6349c7(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676060))((u32)(0));  // @0_6349c7
  ecx = edx = 0;  // @1_6349c7
  ecx = eax;  // @2_6349c7
  if ((ecx & ecx) != 0) goto L6349d8;  // @3_6349c7
  L6349d5:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @5_6349c7
  return eax;  // @6_6349c7
  L6349d8:;
  eax = (u32)(23117);  // @8_6349c7
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) != (eax & 0xffff)) goto L6349d5;  // @9_6349c7
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @10_6349c7
  eax = (eax + ecx);  // @11_6349c7
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(17744)) goto L6349d5;  // @12_6349c7
  ecx = (u32)(267);  // @13_6349c7
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) != (ecx & 0xffff)) goto L6349d5;  // @14_6349c7
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 116), sizeof v); (u32)v; }) <= (u32)(14)) goto L6349d5;  // @15_6349c7
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 232), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @16_6349c7
  return eax;  // @17_6349c7
}
PCREG(6349c7, lifted_6349c7);

extern "C" u32 lifted_634771(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }) & (u32)(0))); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @0_634771
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }) & (u32)(0))); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1_634771
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @2_634771
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_ESI, 4);  // @3_634771
  __builtin_memcpy((void *)(u32)(EBP - 28), &SENT_EDI, 4);  // @4_634771
  edi = (u32)(3141592654);  // @5_634771
  esi = (u32)(4294901760);  // @6_634771
  if (eax == edi) goto L6347a1;  // @7_634771
  if ((esi & eax) == 0) goto L6347a1;  // @8_634771
  eax = (~eax);  // @9_634771
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7296556), &v, sizeof v); }  // @10_634771
  goto L634807;  // @11_634771
  L6347a1:;
  eax = (u32)(EBP - 12);  // @13_634771
  p0_ = eax;  // @14_634771
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676124))((u32)(p0_));  // @15_634771
  ecx = edx = 0;  // @16_634771
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @17_634771
  eax = (eax ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @18_634771
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @19_634771
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676058))();  // @20_634771
  ecx = edx = 0;  // @21_634771
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) ^ eax)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @22_634771
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x67605c))();  // @23_634771
  ecx = edx = 0;  // @24_634771
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }) ^ eax)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @25_634771
  eax = (u32)(EBP - 20);  // @26_634771
  p1_ = eax;  // @27_634771
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760e0))((u32)(p1_));  // @28_634771
  ecx = edx = 0;  // @29_634771
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @30_634771
  eax = (u32)(EBP - 4);  // @31_634771
  ecx = (ecx ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @32_634771
  ecx = (ecx ^ ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @33_634771
  ecx = (ecx ^ eax);  // @34_634771
  if (ecx != edi) goto L6347e9;  // @35_634771
  ecx = (u32)(3141592655);  // @36_634771
  goto L6347f9;  // @37_634771
  L6347e9:;
  if ((esi & ecx) != 0) goto L6347f9;  // @39_634771
  eax = ecx;  // @40_634771
  eax = (eax | (u32)(18193));  // @41_634771
  eax = (eax << (u32)(16));  // @42_634771
  ecx = (ecx | eax);  // @43_634771
  L6347f9:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7296560), &v, sizeof v); }  // @45_634771
  ecx = (~ecx);  // @46_634771
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7296556), &v, sizeof v); }  // @47_634771
  L634807:;
  return eax;  // @49_634771
}
PCREG(634771, lifted_634771);

extern "C" u32 THISCALL lifted_4352f0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4352f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 276), &SENT_ESI, 4);  // @0_4352f0
  esi = ecx;  // @1_4352f0
  eax = 0;  // @2_4352f0
  L435325:;
  if (eax >= (u32)(128)) goto L4353a0;  // @4_4352f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 144), &v, sizeof v); }  // @5_4352f0
  eax = (eax + 1);  // @6_4352f0
  if ((s32)eax < (s32)(u32)(128)) goto L435325;  // @7_4352f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @8_4352f0
  edx = (u32)(EBP - 144);  // @9_4352f0
  p0_ = edx;  // @10_4352f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4352f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p0_), (u32)(6792648), (u32)(8));  // @12_4352f0
  ecx = edx = 0;  // @13_4352f0
  eax = (u32)(EBP - 144);  // @14_4352f0
  p1_ = eax;  // @15_4352f0
  ecx = (u32)(EBP - 272);  // @16_4352f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @17_4352f0
  ecx = edx = 0;  // @18_4352f0
  eax = (u32)(EBP - 272);  // @19_4352f0
  reg.state = (s32)((u32)(0));  // @20_4352f0
  p2_ = eax;  // @21_4352f0
  ecx = (u32)(esi + 140);  // @22_4352f0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @23_4352f0
  ecx = edx = 0;  // @24_4352f0
  ecx = (u32)(EBP - 272);  // @25_4352f0
  eax = ext_4cbec0_thiscall1(ecx);  // @26_4352f0
  ecx = edx = 0;  // @27_4352f0
  SEH_LEAVE();  // @28_4352f0
  ext_633654(G(u32, 0x6f5630));  // @29_4352f0
  return eax;  // @30_4352f0
  L4353a0:;
  eax = ext_634047_cdecl0();  // @32_4352f0
  ecx = edx = 0;  // @33_4352f0
}
PCREG(4352f0, lifted_4352f0);

extern "C" u32 THISCALL lifted_4353b0(u32 ecx_in) {
  SEH_ENTER(0x6691db);  // @h_4353b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy((void *)(u32)(EBP - 276), &SENT_ESI, 4);  // @0_4353b0
  esi = ecx;  // @1_4353b0
  eax = 0;  // @2_4353b0
  L4353e5:;
  if (eax >= (u32)(128)) goto L43545d;  // @4_4353b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + eax - 144), &v, sizeof v); }  // @5_4353b0
  eax = (eax + 1);  // @6_4353b0
  if ((s32)eax < (s32)(u32)(128)) goto L4353e5;  // @7_4353b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340972), sizeof v); (u32)v; });  // @8_4353b0
  edx = (u32)(EBP - 144);  // @9_4353b0
  p0_ = edx;  // @10_4353b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4353b0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(p0_), (u32)(6792636), (u32)(8));  // @12_4353b0
  ecx = edx = 0;  // @13_4353b0
  eax = (u32)(EBP - 144);  // @14_4353b0
  p1_ = eax;  // @15_4353b0
  ecx = (u32)(EBP - 272);  // @16_4353b0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p1_));  // @17_4353b0
  ecx = edx = 0;  // @18_4353b0
  eax = (u32)(EBP - 272);  // @19_4353b0
  reg.state = (s32)((u32)(0));  // @20_4353b0
  p2_ = eax;  // @21_4353b0
  ecx = (u32)(esi + 12);  // @22_4353b0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p2_));  // @23_4353b0
  ecx = edx = 0;  // @24_4353b0
  ecx = (u32)(EBP - 272);  // @25_4353b0
  eax = ext_4cbec0_thiscall1(ecx);  // @26_4353b0
  ecx = edx = 0;  // @27_4353b0
  SEH_LEAVE();  // @28_4353b0
  ext_633654(G(u32, 0x6f5630));  // @29_4353b0
  return eax;  // @30_4353b0
  L43545d:;
  eax = ext_634047_cdecl0();  // @32_4353b0
  ecx = edx = 0;  // @33_4353b0
}
PCREG(4353b0, lifted_4353b0);

extern "C" u32 THISCALL lifted_435920(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66588e);  // @h_435920
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_ESI, 4);  // @0_435920
  esi = ecx;  // @1_435920
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) != (u32)(0)) goto L43597d;  // @2_435920
  eax = ext_41e290_cdecl1((u32)(40));  // @3_435920
  ecx = edx = 0;  // @4_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_435920
  reg.state = (s32)((u32)(0));  // @6_435920
  if ((eax & eax) == 0) goto L435971;  // @7_435920
  ecx = eax;  // @8_435920
  eax = ext_4cca60_thiscall3(ecx, (u32)(4), (u32)(1));  // @9_435920
  ecx = edx = 0;  // @10_435920
  goto L435973;  // @11_435920
  L435971:;
  eax = 0;  // @13_435920
  L435973:;
  reg.state = (s32)((u32)(4294967295));  // @15_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @16_435920
  L43597d:;
  eax = ext_41e290_cdecl1((u32)(21));  // @18_435920
  ecx = edx = 0;  // @19_435920
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @20_435920
  reg.state = (s32)((u32)(1));  // @21_435920
  if ((eax & eax) == 0) goto L4359a6;  // @22_435920
  ecx = eax;  // @23_435920
  eax = ext_4d4c90_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @24_435920
  ecx = edx = 0;  // @25_435920
  edx = eax;  // @26_435920
  goto L4359a8;  // @27_435920
  L4359a6:;
  edx = 0;  // @29_435920
  L4359a8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @31_435920
  p0_ = edx;  // @32_435920
  reg.state = (s32)((u32)(4294967295));  // @33_435920
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_435920
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(p0_));  // @35_435920
  ecx = edx = 0;  // @36_435920
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @37_435920
  SEH_LEAVE();  // @38_435920
  return eax;  // @39_435920
}
PCREG(435920, lifted_435920);

extern "C" u32 THISCALL lifted_444df0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66825f);  // @h_444df0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_ESI, 4);  // @0_444df0
  esi = ecx;  // @1_444df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @2_444df0
  if ((ecx & ecx) != 0) goto L444e63;  // @3_444df0
  eax = ext_41e290_cdecl1((u32)(28));  // @4_444df0
  ecx = edx = 0;  // @5_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_444df0
  reg.state = (s32)((u32)(0));  // @7_444df0
  if ((eax & eax) == 0) goto L444e52;  // @8_444df0
  ecx = eax;  // @9_444df0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @10_444df0
  ecx = edx = 0;  // @11_444df0
  reg.state = (s32)((u32)(4294967295));  // @12_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @13_444df0
  goto L444e6f;  // @14_444df0
  L444e52:;
  eax = 0;  // @16_444df0
  reg.state = (s32)((u32)(4294967295));  // @17_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @18_444df0
  goto L444e6f;  // @19_444df0
  L444e63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @22_444df0
  ecx = edx = 0;  // @23_444df0
  if ((eax & eax) != 0) goto L444e9c;  // @24_444df0
  L444e6f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @26_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @28_444df0
  ecx = edx = 0;  // @29_444df0
  L444e80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @31_444df0
  eax = ext_4dc630_thiscall3(ecx, (u32)(4194304), (u32)(0));  // @32_444df0
  ecx = edx = 0;  // @33_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_444df0
  ecx = esi;  // @35_444df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @36_444df0
  ecx = edx = 0;  // @37_444df0
  esi = eax;  // @38_444df0
  if ((esi & esi) != 0) goto L444e80;  // @39_444df0
  L444e9c:;
  SEH_LEAVE();  // @41_444df0
  return eax;  // @42_444df0
}
PCREG(444df0, lifted_444df0);

extern "C" u32 THISCALL lifted_441d90(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_441d90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  __builtin_memcpy((void *)(u32)(EBP - 20), &SENT_ESI, 4);  // @0_441d90
  __builtin_memcpy((void *)(u32)(EBP - 24), &SENT_EDI, 4);  // @1_441d90
  esi = ecx;  // @2_441d90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; }) != (u32)(0)) goto L441dee;  // @3_441d90
  eax = ext_41e290_cdecl1((u32)(28));  // @4_441d90
  ecx = edx = 0;  // @5_441d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_441d90
  reg.state = (s32)((u32)(0));  // @7_441d90
  if ((eax & eax) == 0) goto L441de2;  // @8_441d90
  ecx = eax;  // @9_441d90
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(4), (u32)(0));  // @10_441d90
  ecx = edx = 0;  // @11_441d90
  goto L441de4;  // @12_441d90
  L441de2:;
  eax = 0;  // @14_441d90
  L441de4:;
  reg.state = (s32)((u32)(4294967295));  // @16_441d90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @17_441d90
  L441dee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 119), sizeof v); (u32)v; });  // @19_441d90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @20_441d90
  p0_ = edi;  // @21_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_441d90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(p0_));  // @23_441d90
  ecx = edx = 0;  // @24_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_441d90
  ecx = edi;  // @26_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @27_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @28_441d90
  ecx = edx = 0;  // @29_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e12;  // @30_441d90
  p1_ = edi;  // @31_441d90
  ecx = esi;  // @32_441d90
  eax = ext_442050_thiscall2(ecx, (u32)(p1_));  // @33_441d90
  ecx = edx = 0;  // @34_441d90
  L441e12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_441d90
  ecx = edi;  // @37_441d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @38_441d90
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @39_441d90
  ecx = edx = 0;  // @40_441d90
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L441e2a;  // @41_441d90
  p2_ = edi;  // @42_441d90
  ecx = esi;  // @43_441d90
  eax = ext_441e40_thiscall2(ecx, (u32)(p2_));  // @44_441d90
  ecx = edx = 0;  // @45_441d90
  L441e2a:;
  SEH_LEAVE();  // @47_441d90
  return eax;  // @48_441d90
}
PCREG(441d90, lifted_441d90);

extern "C" u32 THISCALL lifted_431ce0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x6654b6);  // @h_431ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_;
  const u32 SENT_EBX = 0x0b0b0b0bu, SENT_ESI = 0x05151515u, SENT_EDI = 0x0d0d0d0du;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy((void *)(u32)(EBP - 336), &SENT_EBX, 4);  // @0_431ce0
  __builtin_memcpy((void *)(u32)(EBP - 340), &SENT_ESI, 4);  // @1_431ce0
  __builtin_memcpy((void *)(u32)(EBP - 344), &SENT_EDI, 4);  // @2_431ce0
  edi = ecx;  // @3_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @4_431ce0
  ecx = (u32)(EBP - 324);  // @5_431ce0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_431ce0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @7_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @8_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @9_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @10_431ce0
  eax = ext_4cbeb0_thiscall1(ecx);  // @11_431ce0
  ecx = edx = 0;  // @12_431ce0
  p0_ = esi;  // @13_431ce0
  ecx = (u32)(EBP - 144);  // @14_431ce0
  reg.state = (s32)((u32)(0));  // @15_431ce0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(p0_));  // @16_431ce0
  ecx = edx = 0;  // @17_431ce0
  eax = (u32)(EBP - 144);  // @18_431ce0
  reg.state = (s32)((u32)(1));  // @19_431ce0
  p1_ = eax;  // @20_431ce0
  ecx = (u32)(EBP - 324);  // @21_431ce0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(p1_));  // @22_431ce0
  ecx = edx = 0;  // @23_431ce0
  ecx = (u32)(EBP - 144);  // @24_431ce0
  reg.state = (s32)((u32)(0));  // @25_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @26_431ce0
  ecx = edx = 0;  // @27_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @28_431ce0
  if ((eax & eax) == 0) goto L431d81;  // @29_431ce0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @30_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @31_431ce0
  goto L431d92;  // @32_431ce0
  L431d81:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @34_431ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 163), &v, sizeof v); }  // @35_431ce0
  L431d92:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @37_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; });  // @38_431ce0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @39_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 149), &v, sizeof v); }  // @40_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @42_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @43_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @44_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @45_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @46_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @47_431ce0
  ecx = (u32)(EBP - 324);  // @48_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 184), &v, sizeof v); }  // @49_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @50_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 180), &v, sizeof v); }  // @51_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @52_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 176), &v, sizeof v); }  // @53_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @54_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @55_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @56_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @57_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @58_431ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @59_431ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @60_431ce0
  p2_ = ecx;  // @61_431ce0
  ecx = edi;  // @62_431ce0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 159), &v, sizeof v); }  // @63_431ce0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 157), &v, sizeof v); }  // @64_431ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p2_));  // @65_431ce0
  ecx = edx = 0;  // @66_431ce0
  ecx = (u32)(EBP - 324);  // @67_431ce0
  esi = eax;  // @68_431ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @69_431ce0
  ecx = edx = 0;  // @70_431ce0
  eax = esi;  // @71_431ce0
  SEH_LEAVE();  // @72_431ce0
  ext_633654(G(u32, 0x6f5630));  // @73_431ce0
  return eax;  // @74_431ce0
}
PCREG(431ce0, lifted_431ce0);

extern "C" u32 lifted_560580(void) {
  SEH_ENTER(0x66b0c0);  // @h_560580
  u8 F[0x11b0] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x10b0);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
  u32 p0_, p1_, p2_, p3_, p4_, p5_, p6_, p7_, p8_, p9_, p10_, p11_, p12_, p13_, p14_, p15_, p16_, p17_, p18_, p19_, p20_, p21_, p22_, p23_, p24_, p25_, p26_, p27_, p28_, p29_, p30_, p31_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = (u32)(EBP - 404);  // @0_560580
  eax = ext_561020_thiscall1(ecx);  // @1_560580
  ecx = edx = 0;  // @2_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @3_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @4_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_560580
  edx = (u32)(EBP - 404);  // @6_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @7_560580
  p0_ = edx;  // @8_560580
  reg.state = (s32)((u32)(0));  // @9_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p0_));  // @12_560580
  ecx = edx = 0;  // @13_560580
  ecx = (u32)(EBP - 3268);  // @14_560580
  reg.state = (s32)((u32)(4294967295));  // @15_560580
  eax = ext_565840_thiscall1(ecx);  // @16_560580
  ecx = edx = 0;  // @17_560580
  ecx = (u32)(EBP - 3268);  // @18_560580
  eax = ext_565870_thiscall1(ecx);  // @19_560580
  ecx = edx = 0;  // @20_560580
  ecx = (u32)(EBP - 2616);  // @21_560580
  eax = ext_565b90_thiscall1(ecx);  // @22_560580
  ecx = edx = 0;  // @23_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2548), &v, sizeof v); }  // @24_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2568), &v, sizeof v); }  // @25_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_560580
  edx = (u32)(EBP - 2616);  // @27_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 2616), &v, sizeof v); }  // @28_560580
  p1_ = edx;  // @29_560580
  reg.state = (s32)((u32)(1));  // @30_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p1_));  // @33_560580
  ecx = edx = 0;  // @34_560580
  ecx = (u32)(EBP - 436);  // @35_560580
  reg.state = (s32)((u32)(4294967295));  // @36_560580
  eax = ext_566bc0_thiscall1(ecx);  // @37_560580
  ecx = edx = 0;  // @38_560580
  ecx = (u32)(EBP - 436);  // @39_560580
  eax = ext_566c90_thiscall1(ecx);  // @40_560580
  ecx = edx = 0;  // @41_560580
  ecx = (u32)(EBP - 404);  // @42_560580
  eax = ext_561160_thiscall1(ecx);  // @43_560580
  ecx = edx = 0;  // @44_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @45_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @46_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_560580
  edx = (u32)(EBP - 404);  // @48_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @49_560580
  p2_ = edx;  // @50_560580
  reg.state = (s32)((u32)(2));  // @51_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p2_));  // @54_560580
  ecx = edx = 0;  // @55_560580
  ecx = (u32)(EBP - 3264);  // @56_560580
  reg.state = (s32)((u32)(4294967295));  // @57_560580
  eax = ext_564460_thiscall1(ecx);  // @58_560580
  ecx = edx = 0;  // @59_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3196), &v, sizeof v); }  // @60_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3216), &v, sizeof v); }  // @61_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @62_560580
  edx = (u32)(EBP - 3264);  // @63_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3264), &v, sizeof v); }  // @64_560580
  p3_ = edx;  // @65_560580
  reg.state = (s32)((u32)(3));  // @66_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p3_));  // @69_560580
  ecx = edx = 0;  // @70_560580
  ecx = (u32)(EBP - 1088);  // @71_560580
  reg.state = (s32)((u32)(4294967295));  // @72_560580
  eax = ext_567720_thiscall1(ecx);  // @73_560580
  ecx = edx = 0;  // @74_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1020), &v, sizeof v); }  // @75_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1040), &v, sizeof v); }  // @76_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_560580
  edx = (u32)(EBP - 1088);  // @78_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 1088), &v, sizeof v); }  // @79_560580
  p4_ = edx;  // @80_560580
  reg.state = (s32)((u32)(4));  // @81_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @82_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p4_));  // @84_560580
  ecx = edx = 0;  // @85_560580
  ecx = (u32)(EBP - 408);  // @86_560580
  reg.state = (s32)((u32)(4294967295));  // @87_560580
  eax = ext_569380_thiscall1(ecx);  // @88_560580
  ecx = edx = 0;  // @89_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @90_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @91_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_560580
  edx = (u32)(EBP - 408);  // @93_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @94_560580
  p5_ = edx;  // @95_560580
  reg.state = (s32)((u32)(5));  // @96_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @97_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p5_));  // @99_560580
  ecx = edx = 0;  // @100_560580
  ecx = (u32)(EBP - 480);  // @101_560580
  reg.state = (s32)((u32)(4294967295));  // @102_560580
  eax = ext_5696b0_thiscall1(ecx);  // @103_560580
  ecx = edx = 0;  // @104_560580
  ecx = (u32)(EBP - 480);  // @105_560580
  eax = ext_569730_thiscall1(ecx);  // @106_560580
  ecx = edx = 0;  // @107_560580
  ecx = (u32)(EBP - 3821);  // @108_560580
  eax = ext_56ad80_thiscall1(ecx);  // @109_560580
  ecx = edx = 0;  // @110_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3753), &v, sizeof v); }  // @111_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3773), &v, sizeof v); }  // @112_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_560580
  edx = (u32)(EBP - 3821);  // @114_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3821), &v, sizeof v); }  // @115_560580
  p6_ = edx;  // @116_560580
  reg.state = (s32)((u32)(6));  // @117_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p6_));  // @120_560580
  ecx = edx = 0;  // @121_560580
  ecx = (u32)(EBP - 3332);  // @122_560580
  reg.state = (s32)((u32)(4294967295));  // @123_560580
  eax = ext_56b2d0_thiscall1(ecx);  // @124_560580
  ecx = edx = 0;  // @125_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3264), &v, sizeof v); }  // @126_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3284), &v, sizeof v); }  // @127_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_560580
  edx = (u32)(EBP - 3332);  // @129_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3332), &v, sizeof v); }  // @130_560580
  p7_ = edx;  // @131_560580
  reg.state = (s32)((u32)(7));  // @132_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @133_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p7_));  // @135_560580
  ecx = edx = 0;  // @136_560580
  ecx = (u32)(EBP - 508);  // @137_560580
  reg.state = (s32)((u32)(4294967295));  // @138_560580
  eax = ext_56c810_thiscall1(ecx);  // @139_560580
  ecx = edx = 0;  // @140_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 440), &v, sizeof v); }  // @141_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @142_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @143_560580
  edx = (u32)(EBP - 508);  // @144_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @145_560580
  p8_ = edx;  // @146_560580
  reg.state = (s32)((u32)(8));  // @147_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @148_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p8_));  // @150_560580
  ecx = edx = 0;  // @151_560580
  ecx = (u32)(EBP - 548);  // @152_560580
  reg.state = (s32)((u32)(4294967295));  // @153_560580
  eax = ext_56db70_thiscall1(ecx);  // @154_560580
  ecx = edx = 0;  // @155_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 480), &v, sizeof v); }  // @156_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 500), &v, sizeof v); }  // @157_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_560580
  edx = (u32)(EBP - 548);  // @159_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @160_560580
  p9_ = edx;  // @161_560580
  reg.state = (s32)((u32)(9));  // @162_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @163_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p9_));  // @165_560580
  ecx = edx = 0;  // @166_560580
  ecx = (u32)(EBP - 1528);  // @167_560580
  reg.state = (s32)((u32)(4294967295));  // @168_560580
  eax = ext_56e990_thiscall1(ecx);  // @169_560580
  ecx = edx = 0;  // @170_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1460), &v, sizeof v); }  // @171_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1480), &v, sizeof v); }  // @172_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 1528), &v, sizeof v); }  // @174_560580
  reg.state = (s32)((u32)(10));  // @175_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @176_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_560580
  edx = (u32)(EBP - 1528);  // @178_560580
  p10_ = edx;  // @179_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p10_));  // @180_560580
  ecx = edx = 0;  // @181_560580
  ecx = (u32)(EBP - 588);  // @182_560580
  reg.state = (s32)((u32)(4294967295));  // @183_560580
  eax = ext_56fea0_thiscall1(ecx);  // @184_560580
  ecx = edx = 0;  // @185_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @186_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @187_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_560580
  edx = (u32)(EBP - 588);  // @189_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 588), &v, sizeof v); }  // @190_560580
  p11_ = edx;  // @191_560580
  reg.state = (s32)((u32)(11));  // @192_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @193_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @194_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p11_));  // @195_560580
  ecx = edx = 0;  // @196_560580
  ecx = (u32)(EBP - 428);  // @197_560580
  reg.state = (s32)((u32)(4294967295));  // @198_560580
  eax = ext_571960_thiscall1(ecx);  // @199_560580
  ecx = edx = 0;  // @200_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @201_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @202_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @203_560580
  edx = (u32)(EBP - 428);  // @204_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @205_560580
  p12_ = edx;  // @206_560580
  reg.state = (s32)((u32)(12));  // @207_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @208_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p12_));  // @210_560580
  ecx = edx = 0;  // @211_560580
  ecx = (u32)(EBP - 2196);  // @212_560580
  reg.state = (s32)((u32)(4294967295));  // @213_560580
  eax = ext_572360_thiscall1(ecx);  // @214_560580
  ecx = edx = 0;  // @215_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2128), &v, sizeof v); }  // @216_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 2148), &v, sizeof v); }  // @217_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @218_560580
  edx = (u32)(EBP - 2196);  // @219_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 2196), &v, sizeof v); }  // @220_560580
  p13_ = edx;  // @221_560580
  reg.state = (s32)((u32)(13));  // @222_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @223_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p13_));  // @225_560580
  ecx = edx = 0;  // @226_560580
  ecx = (u32)(EBP - 404);  // @227_560580
  reg.state = (s32)((u32)(4294967295));  // @228_560580
  eax = ext_572e40_thiscall1(ecx);  // @229_560580
  ecx = edx = 0;  // @230_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @231_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @232_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_560580
  edx = (u32)(EBP - 404);  // @234_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @235_560580
  p14_ = edx;  // @236_560580
  reg.state = (s32)((u32)(14));  // @237_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @238_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @239_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p14_));  // @240_560580
  ecx = edx = 0;  // @241_560580
  ecx = (u32)(EBP - 536);  // @242_560580
  reg.state = (s32)((u32)(4294967295));  // @243_560580
  eax = ext_573590_thiscall1(ecx);  // @244_560580
  ecx = edx = 0;  // @245_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 468), &v, sizeof v); }  // @246_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 488), &v, sizeof v); }  // @247_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @248_560580
  edx = (u32)(EBP - 536);  // @249_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @250_560580
  p15_ = edx;  // @251_560580
  reg.state = (s32)((u32)(15));  // @252_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @253_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @254_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p15_));  // @255_560580
  ecx = edx = 0;  // @256_560580
  ecx = (u32)(EBP - 752);  // @257_560580
  reg.state = (s32)((u32)(4294967295));  // @258_560580
  eax = ext_574c60_thiscall1(ecx);  // @259_560580
  ecx = edx = 0;  // @260_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 684), &v, sizeof v); }  // @261_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 704), &v, sizeof v); }  // @262_560580
  reg.state = (s32)((u32)(16));  // @263_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 752), &v, sizeof v); }  // @264_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @265_560580
  edx = (u32)(EBP - 752);  // @266_560580
  p16_ = edx;  // @267_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @268_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @269_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p16_));  // @270_560580
  ecx = edx = 0;  // @271_560580
  ecx = (u32)(EBP - 580);  // @272_560580
  reg.state = (s32)((u32)(4294967295));  // @273_560580
  eax = ext_575d50_thiscall1(ecx);  // @274_560580
  ecx = edx = 0;  // @275_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 512), &v, sizeof v); }  // @276_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @277_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @278_560580
  edx = (u32)(EBP - 580);  // @279_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 580), &v, sizeof v); }  // @280_560580
  p17_ = edx;  // @281_560580
  reg.state = (s32)((u32)(17));  // @282_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @283_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @284_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p17_));  // @285_560580
  ecx = edx = 0;  // @286_560580
  ecx = (u32)(EBP - 404);  // @287_560580
  reg.state = (s32)((u32)(4294967295));  // @288_560580
  eax = ext_5773f0_thiscall1(ecx);  // @289_560580
  ecx = edx = 0;  // @290_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @291_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @292_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @293_560580
  edx = (u32)(EBP - 404);  // @294_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @295_560580
  p18_ = edx;  // @296_560580
  reg.state = (s32)((u32)(18));  // @297_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @298_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @299_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p18_));  // @300_560580
  ecx = edx = 0;  // @301_560580
  ecx = (u32)(EBP - 568);  // @302_560580
  reg.state = (s32)((u32)(4294967295));  // @303_560580
  eax = ext_577830_thiscall1(ecx);  // @304_560580
  ecx = edx = 0;  // @305_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 500), &v, sizeof v); }  // @306_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @307_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @308_560580
  edx = (u32)(EBP - 568);  // @309_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 568), &v, sizeof v); }  // @310_560580
  p19_ = edx;  // @311_560580
  reg.state = (s32)((u32)(19));  // @312_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @313_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @314_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p19_));  // @315_560580
  ecx = edx = 0;  // @316_560580
  ecx = (u32)(EBP - 460);  // @317_560580
  reg.state = (s32)((u32)(4294967295));  // @318_560580
  eax = ext_578560_thiscall1(ecx);  // @319_560580
  ecx = edx = 0;  // @320_560580
  ecx = (u32)(EBP - 460);  // @321_560580
  eax = ext_578710_thiscall1(ecx);  // @322_560580
  ecx = edx = 0;  // @323_560580
  ecx = (u32)(EBP - 3820);  // @324_560580
  eax = ext_57a100_thiscall1(ecx);  // @325_560580
  ecx = edx = 0;  // @326_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3752), &v, sizeof v); }  // @327_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3772), &v, sizeof v); }  // @328_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @329_560580
  edx = (u32)(EBP - 3820);  // @330_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3820), &v, sizeof v); }  // @331_560580
  p20_ = edx;  // @332_560580
  reg.state = (s32)((u32)(20));  // @333_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @334_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @335_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p20_));  // @336_560580
  ecx = edx = 0;  // @337_560580
  ecx = (u32)(EBP - 404);  // @338_560580
  reg.state = (s32)((u32)(4294967295));  // @339_560580
  eax = ext_57a3b0_thiscall1(ecx);  // @340_560580
  ecx = edx = 0;  // @341_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @342_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @343_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @344_560580
  edx = (u32)(EBP - 404);  // @345_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @346_560580
  p21_ = edx;  // @347_560580
  reg.state = (s32)((u32)(21));  // @348_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @349_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @350_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p21_));  // @351_560580
  ecx = edx = 0;  // @352_560580
  reg.state = (s32)((u32)(4294967295));  // @353_560580
  ecx = (u32)(EBP - 428);  // @354_560580
  eax = ext_57a440_thiscall1(ecx);  // @355_560580
  ecx = edx = 0;  // @356_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @357_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 380), &v, sizeof v); }  // @358_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @359_560580
  edx = (u32)(EBP - 428);  // @360_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @361_560580
  p22_ = edx;  // @362_560580
  reg.state = (s32)((u32)(22));  // @363_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @364_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @365_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p22_));  // @366_560580
  ecx = edx = 0;  // @367_560580
  ecx = (u32)(EBP - 408);  // @368_560580
  reg.state = (s32)((u32)(4294967295));  // @369_560580
  eax = ext_57abc0_thiscall1(ecx);  // @370_560580
  ecx = edx = 0;  // @371_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @372_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @373_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @374_560580
  edx = (u32)(EBP - 408);  // @375_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @376_560580
  p23_ = edx;  // @377_560580
  reg.state = (s32)((u32)(23));  // @378_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @379_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @380_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p23_));  // @381_560580
  ecx = edx = 0;  // @382_560580
  ecx = (u32)(EBP - 3272);  // @383_560580
  reg.state = (s32)((u32)(4294967295));  // @384_560580
  eax = ext_57baa0_thiscall1(ecx);  // @385_560580
  ecx = edx = 0;  // @386_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3204), &v, sizeof v); }  // @387_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3224), &v, sizeof v); }  // @388_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @389_560580
  edx = (u32)(EBP - 3272);  // @390_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3272), &v, sizeof v); }  // @391_560580
  p24_ = edx;  // @392_560580
  reg.state = (s32)((u32)(24));  // @393_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @394_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @395_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p24_));  // @396_560580
  ecx = edx = 0;  // @397_560580
  ecx = (u32)(EBP - 3865);  // @398_560580
  reg.state = (s32)((u32)(4294967295));  // @399_560580
  eax = ext_573650_thiscall4(ecx, (u32)(0), (u32)(0), (u32)(0));  // @400_560580
  ecx = edx = 0;  // @401_560580
  ecx = (u32)(EBP - 3865);  // @402_560580
  eax = ext_43de70_thiscall1(ecx);  // @403_560580
  ecx = edx = 0;  // @404_560580
  ecx = (u32)(EBP - 404);  // @405_560580
  eax = ext_57bd90_thiscall1(ecx);  // @406_560580
  ecx = edx = 0;  // @407_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @408_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @409_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @410_560580
  edx = (u32)(EBP - 404);  // @411_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @412_560580
  p25_ = edx;  // @413_560580
  reg.state = (s32)((u32)(25));  // @414_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @415_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @416_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p25_));  // @417_560580
  ecx = edx = 0;  // @418_560580
  ecx = (u32)(EBP - 408);  // @419_560580
  reg.state = (s32)((u32)(4294967295));  // @420_560580
  eax = ext_57c100_thiscall1(ecx);  // @421_560580
  ecx = edx = 0;  // @422_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 340), &v, sizeof v); }  // @423_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 360), &v, sizeof v); }  // @424_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @425_560580
  edx = (u32)(EBP - 408);  // @426_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @427_560580
  p26_ = edx;  // @428_560580
  reg.state = (s32)((u32)(26));  // @429_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @430_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @431_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p26_));  // @432_560580
  ecx = edx = 0;  // @433_560580
  ecx = (u32)(EBP - 404);  // @434_560580
  reg.state = (s32)((u32)(4294967295));  // @435_560580
  eax = ext_57c460_thiscall1(ecx);  // @436_560580
  ecx = edx = 0;  // @437_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @438_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @439_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @440_560580
  edx = (u32)(EBP - 404);  // @441_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @442_560580
  p27_ = edx;  // @443_560580
  reg.state = (s32)((u32)(27));  // @444_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @445_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @446_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p27_));  // @447_560580
  ecx = edx = 0;  // @448_560580
  ecx = (u32)(EBP - 876);  // @449_560580
  reg.state = (s32)((u32)(4294967295));  // @450_560580
  eax = ext_57c7c0_thiscall1(ecx);  // @451_560580
  ecx = edx = 0;  // @452_560580
  ecx = (u32)(EBP - 264);  // @453_560580
  eax = ext_4ccf60_thiscall1(ecx);  // @454_560580
  ecx = edx = 0;  // @455_560580
  ecx = (u32)(EBP - 304);  // @456_560580
  eax = ext_4cce40_thiscall1(ecx);  // @457_560580
  ecx = edx = 0;  // @458_560580
  ecx = (u32)(EBP - 476);  // @459_560580
  eax = ext_4ccf60_thiscall1(ecx);  // @460_560580
  ecx = edx = 0;  // @461_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 808), &v, sizeof v); }  // @462_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 828), &v, sizeof v); }  // @463_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @464_560580
  edx = (u32)(EBP - 876);  // @465_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 876), &v, sizeof v); }  // @466_560580
  p28_ = edx;  // @467_560580
  reg.state = (s32)((u32)(28));  // @468_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @469_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @470_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p28_));  // @471_560580
  ecx = edx = 0;  // @472_560580
  ecx = (u32)(EBP - 416);  // @473_560580
  reg.state = (s32)((u32)(4294967295));  // @474_560580
  eax = ext_57f1b0_thiscall1(ecx);  // @475_560580
  ecx = edx = 0;  // @476_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @477_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 368), &v, sizeof v); }  // @478_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @479_560580
  edx = (u32)(EBP - 416);  // @480_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @481_560580
  p29_ = edx;  // @482_560580
  reg.state = (s32)((u32)(29));  // @483_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @484_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @485_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p29_));  // @486_560580
  ecx = edx = 0;  // @487_560580
  ecx = (u32)(EBP - 456);  // @488_560580
  reg.state = (s32)((u32)(4294967295));  // @489_560580
  eax = ext_57aea0_thiscall1(ecx);  // @490_560580
  ecx = edx = 0;  // @491_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 388), &v, sizeof v); }  // @492_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 408), &v, sizeof v); }  // @493_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @494_560580
  edx = (u32)(EBP - 456);  // @495_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @496_560580
  p30_ = edx;  // @497_560580
  reg.state = (s32)((u32)(30));  // @498_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @499_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @500_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p30_));  // @501_560580
  ecx = edx = 0;  // @502_560580
  ecx = (u32)(EBP - 3724);  // @503_560580
  reg.state = (s32)((u32)(4294967295));  // @504_560580
  eax = ext_57c100_thiscall1(ecx);  // @505_560580
  ecx = edx = 0;  // @506_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3656), &v, sizeof v); }  // @507_560580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 3676), &v, sizeof v); }  // @508_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @509_560580
  edx = (u32)(EBP - 3724);  // @510_560580
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(EBP - 3724), &v, sizeof v); }  // @511_560580
  p31_ = edx;  // @512_560580
  reg.state = (s32)((u32)(31));  // @513_560580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @514_560580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @515_560580
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(p31_));  // @516_560580
  ecx = edx = 0;  // @517_560580
  SEH_LEAVE();  // @518_560580
  ext_633654(G(u32, 0x6f5630));  // @519_560580
  return eax;  // @520_560580
}
PCREG(560580, lifted_560580);

extern "C" u32 THISCALL lifted_5fb770(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  struct Pg_ { ~Pg_() { *(volatile u32 *)0x8140f0 = 0; } } pg_; *(volatile u32 *)0x8140f0 = EBP;
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

extern "C" u32 STDCALL lifted_438d90(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 p0_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_438d90
  if ((esi & esi) != 0) goto L438dc5;  // @1_438d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_438d90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_438d90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2836));  // @4_438d90
  ecx = edx = 0;  // @5_438d90
  p0_ = eax;  // @6_438d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_438d90
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(p0_), (u32)(6793464));  // @8_438d90
  ecx = edx = 0;  // @9_438d90
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @10_438d90
  return eax;  // @11_438d90
  L438dc5:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) & 0xff);  // @13_438d90
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L438e04;  // @14_438d90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_438d90
  if (edi == (u32)(3)) goto L438ddf;  // @16_438d90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @17_438d90
  eax = ext_439670_thiscall1(ecx);  // @18_438d90
  ecx = edx = 0;  // @19_438d90
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (eax & 0xff))) & 0xff);  // @20_438d90
  L438ddf:;
  if (((ebx & 0xff) & (ebx & 0xff)) == 0) goto L438e04;  // @22_438d90
  if ((edi & edi) != 0) goto L438df1;  // @23_438d90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; })) & 0xff);  // @24_438d90
  return eax;  // @25_438d90
  L438df1:;
  if (edi != (u32)(1)) goto L438e04;  // @27_438d90
  ecx = esi;  // @28_438d90
  eax = ext_438e30_thiscall1(ecx);  // @29_438d90
  ecx = edx = 0;  // @30_438d90
  return eax;  // @31_438d90
  L438e04:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @33_438d90
  return eax;  // @34_438d90
}
PCREG(438d90, lifted_438d90);

