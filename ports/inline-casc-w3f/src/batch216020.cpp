// batch216020.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_492200_stdcall1(u32) __asm__("ext_492200");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_471f60_thiscall1(u32) __asm__("ext_471f60");
extern "C" u32 THISCALL ext_48cf50_thiscall1(u32) __asm__("ext_48cf50");
extern "C" u32 THISCALL ext_492880_thiscall2(u32, u32) __asm__("ext_492880");
extern "C" u32 THISCALL ext_493820_thiscall4(u32, u32, u32, u32) __asm__("ext_493820");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d5440_thiscall1(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e6780_thiscall2(u32, u32) __asm__("ext_4e6780");
extern "C" u32 THISCALL ext_4febf0_thiscall2(u32, u32) __asm__("ext_4febf0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl4(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_455200(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x6663ea);  // @h_455200
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_455200
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_455200
  eax = ext_43de40_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_455200
  ecx = edx = 0;  // @3_455200
  { u32 v = (u32)((u32)(6826716)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_455200
  edi = (u32)(esi + 28);  // @5_455200
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @6_455200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_455200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_455200
  reg.state = (s32)((u32)(0));  // @9_455200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_455200
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(6827288), (u32)(362));  // @11_455200
  ecx = edx = 0;  // @12_455200
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 2081), &v, sizeof v); }  // @13_455200
  eax = (u32)(esi + 29);  // @14_455200
  PS[2] = eax;  // @15_455200
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(2048));  // @16_455200
  ecx = edx = 0;  // @17_455200
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2083), &v, sizeof v); }  // @18_455200
  eax = ext_41e290_cdecl1((u32)(152580));  // @19_455200
  ecx = edx = 0;  // @20_455200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @21_455200
  if ((eax & eax) == 0) goto L4552c7;  // @22_455200
  ecx = 0;  // @23_455200
  edx = (u32)(eax + 152320);  // @24_455200
  L4552b0:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @26_455200
  edx = (u32)(edx + 4);  // @27_455200
  ecx = (ecx + 1);  // @28_455200
  if (ecx < (u32)(64)) goto L4552b0;  // @29_455200
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(eax + 152576), &v, sizeof v); }  // @30_455200
  goto L4552c9;  // @31_455200
  L4552c7:;
  eax = 0;  // @33_455200
  L4552c9:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2077), &v, sizeof v); }  // @35_455200
  eax = ext_41e290_cdecl1((u32)(264));  // @36_455200
  ecx = edx = 0;  // @37_455200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @38_455200
  reg.state = (s32)((u32)(1));  // @39_455200
  if ((eax & eax) == 0) goto L4552fd;  // @40_455200
  PS[0] = edi;  // @41_455200
  ecx = eax;  // @42_455200
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6827580), (u32)(6827556), (u32)(PS[0]));  // @43_455200
  ecx = edx = 0;  // @44_455200
  edx = eax;  // @45_455200
  goto L4552ff;  // @46_455200
  L4552fd:;
  edx = 0;  // @48_455200
  L4552ff:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @50_455200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_455200
  PS[0] = edx;  // @52_455200
  reg.state = (s32)((u32)(0));  // @53_455200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_455200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @55_455200
  ecx = edx = 0;  // @56_455200
  eax = esi;  // @57_455200
  SEH_LEAVE();  // @58_455200
  return eax;  // @59_455200
}
PCREG(455200, lifted_455200);

extern "C" u32 THISCALL lifted_434bf0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6657bf);  // @h_434bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_434bf0
  eax = ext_41e290_cdecl1((u32)(111));  // @1_434bf0
  ecx = edx = 0;  // @2_434bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_434bf0
  reg.state = (s32)((u32)(0));  // @4_434bf0
  if ((eax & eax) == 0) goto L434c3e;  // @5_434bf0
  ecx = eax;  // @6_434bf0
  eax = ext_4d5440_thiscall1(ecx);  // @7_434bf0
  ecx = edx = 0;  // @8_434bf0
  ebx = eax;  // @9_434bf0
  goto L434c40;  // @10_434bf0
  L434c3e:;
  ebx = 0;  // @12_434bf0
  L434c40:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_434bf0
  ecx = esi;  // @15_434bf0
  reg.state = (s32)((u32)(4294967295));  // @16_434bf0
  edx = (u32)(ecx + 1);  // @17_434bf0
  L434c50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @19_434bf0
  ecx = (ecx + 1);  // @20_434bf0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L434c50;  // @21_434bf0
  ecx = (ecx - edx);  // @22_434bf0
  eax = (u32)(ecx + 1);  // @23_434bf0
  PS[0] = eax;  // @24_434bf0
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @25_434bf0
  ecx = edx = 0;  // @26_434bf0
  edi = eax;  // @27_434bf0
  edx = esi;  // @28_434bf0
  esi = edi;  // @29_434bf0
  esi = (esi - edx);  // @30_434bf0
  L434c70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @32_434bf0
  edx = (u32)(edx + 1);  // @33_434bf0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + edx - 1), &v, sizeof v); }  // @34_434bf0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L434c70;  // @35_434bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @36_434bf0
  PS[1] = edi;  // @37_434bf0
  eax = ((u32( *)(u32, u32))(esi))((u32)(PS[1]), (u32)(92));  // @38_434bf0
  ecx = edx = 0;  // @39_434bf0
  if ((eax & eax) != 0) goto L434c9b;  // @40_434bf0
  PS[1] = edi;  // @41_434bf0
  eax = ((u32( *)(u32, u32))(esi))((u32)(PS[1]), (u32)(47));  // @42_434bf0
  ecx = edx = 0;  // @43_434bf0
  if ((eax & eax) == 0) goto L434ca7;  // @44_434bf0
  L434c9b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @46_434bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_434bf0
  PS[0] = edi;  // @48_434bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_434bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @50_434bf0
  ecx = edx = 0;  // @51_434bf0
  L434ca7:;
  PS[1] = edi;  // @53_434bf0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @54_434bf0
  ecx = edx = 0;  // @55_434bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_434bf0
  ecx = ebx;  // @57_434bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 52)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(1));  // @58_434bf0
  ecx = edx = 0;  // @59_434bf0
  eax = ebx;  // @60_434bf0
  SEH_LEAVE();  // @61_434bf0
  return eax;  // @62_434bf0
}

extern "C" u32 THISCALL lifted_4346e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_4346e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4346e0
  ecx = (u32)(EBP - 144);  // @2_4346e0
  PS[0] = eax;  // @3_4346e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @4_4346e0
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
  PS[0] = edx;  // @32_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @33_4346e0
  ecx = edx = 0;  // @34_4346e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @35_4346e0
  edx = (u32)(EBP - 156);  // @36_4346e0
  PS[0] = edx;  // @37_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @39_4346e0
  ecx = edx = 0;  // @40_4346e0
  if ((eax & eax) == 0) goto L4347cd;  // @41_4346e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @42_4346e0
  L4347a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @44_4346e0
  ecx = (u32)(EBP - 144);  // @45_4346e0
  PS[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13), sizeof v); (u32)v; });
  eax = ext_4cc1d0_thiscall1(ecx);  // @46_4346e0   (w3c: the pushed [eax+0xd] is a junk stack word popped by add esp,8)
  ecx = edx = 0;  // @47_4346e0
  PS[0] = eax;  // @48_4346e0
  eax = ((u32(*)(u32, u32))(esi))((u32)(PS[0]), (u32)(PS[1]));  // @49_4346e0
  ecx = edx = 0;  // @50_4346e0
  if ((eax & eax) == 0) goto L4347fa;  // @51_4346e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @52_4346e0
  edx = (u32)(EBP - 156);  // @53_4346e0
  PS[0] = edx;  // @54_4346e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4346e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @56_4346e0
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

extern "C" u32 THISCALL lifted_435800(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_435800
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435800
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L4358ff;  // @2_435800
  PS[0] = eax;  // @3_435800
  ecx = (u32)(EBP - 144);  // @4_435800
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @5_435800
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
  PS[0] = edx;  // @33_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @34_435800
  ecx = edx = 0;  // @35_435800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @36_435800
  edx = (u32)(EBP - 156);  // @37_435800
  PS[0] = edx;  // @38_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @40_435800
  ecx = edx = 0;  // @41_435800
  if ((eax & eax) == 0) goto L4358f4;  // @42_435800
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @43_435800
  L4358c0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_435800
  ecx = (u32)(EBP - 144);  // @46_435800
  eax = ext_4cc1d0_thiscall1(ecx);  // @47_435800
  ecx = edx = 0;  // @48_435800
  PS[0] = eax;  // @49_435800
  eax = ((u32( *)(u32, u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; }), (u32)(PS[0]));  // @50_435800
  ecx = edx = 0;  // @51_435800
  if ((eax & eax) != 0) goto L4358e1;  // @52_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @53_435800
  ecx = esi;  // @54_435800
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @55_435800
  ecx = edx = 0;  // @56_435800
  L4358e1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @58_435800
  edx = (u32)(EBP - 156);  // @59_435800
  PS[0] = edx;  // @60_435800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_435800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @62_435800
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

extern "C" u32 lifted_456bf0(void) {
  SEH_ENTER(0x6691af);  // @h_456bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_456bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @3_456bf0
  ecx = edx = 0;  // @4_456bf0
  ecx = (u32)(EBP - 16);  // @5_456bf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_456bf0
  PS[0] = ecx;  // @7_456bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_456bf0
  ecx = eax;  // @9_456bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6827256), (u32)(PS[0]));  // @10_456bf0
  ecx = edx = 0;  // @11_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @12_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_456bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @14_456bf0
  ecx = edx = 0;  // @15_456bf0
  if ((eax & eax) != 0) goto L456cfa;  // @16_456bf0
  eax = ext_41e290_cdecl1((u32)(28));  // @17_456bf0
  ecx = edx = 0;  // @18_456bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @19_456bf0
  reg.state = (s32)((u32)(0));  // @20_456bf0
  if ((eax & eax) == 0) goto L456c84;  // @21_456bf0
  ecx = eax;  // @22_456bf0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(0));  // @23_456bf0
  ecx = edx = 0;  // @24_456bf0
  esi = eax;  // @25_456bf0
  goto L456c86;  // @26_456bf0
  L456c84:;
  esi = 0;  // @28_456bf0
  L456c86:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_456bf0
  reg.state = (s32)((u32)(4294967295));  // @31_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @32_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_456bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @34_456bf0
  ecx = edx = 0;  // @35_456bf0
  edi = eax;  // @36_456bf0
  if ((esi & esi) != 0) goto L456caa;  // @37_456bf0
  L456ca6:;
  eax = 0;  // @39_456bf0
  goto L456ce9;  // @40_456bf0
  L456caa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @42_456bf0
  PS[0] = esi;  // @43_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_456bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(PS[0]));  // @45_456bf0
  ecx = edx = 0;  // @46_456bf0
  if ((eax & eax) != 0) goto L456ca6;  // @47_456bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @48_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @49_456bf0
  if ((eax & eax) == 0) goto L456cd7;  // @50_456bf0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L456cd7;  // @51_456bf0
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L456cd7;  // @52_456bf0
  ecx = esi;  // @53_456bf0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @54_456bf0
  ecx = edx = 0;  // @55_456bf0
  goto L456ce9;  // @56_456bf0
  L456cd7:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L456ce6;  // @58_456bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_456bf0
  PS[0] = esi;  // @60_456bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(PS[0]));  // @61_456bf0
  ecx = edx = 0;  // @62_456bf0
  L456ce6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @64_456bf0
  L456ce9:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_456bf0
  ecx = edi;  // @67_456bf0
  PS[1] = eax;  // @68_456bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(6827256), (u32)(PS[1]), (u32)(16));  // @69_456bf0
  ecx = edx = 0;  // @70_456bf0
  eax = esi;  // @71_456bf0
  L456cfa:;
  SEH_LEAVE();  // @73_456bf0
  return eax;  // @74_456bf0
}
PCREG(456bf0, lifted_456bf0);

extern "C" u32 THISCALL lifted_44a200(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6660dd);  // @h_44a200
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44a200
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44a200
  PS[0] = ebx;  // @2_44a200
  eax = ext_610100_stdcall1((u32)(PS[0]));  // @3_44a200
  ecx = edx = 0;  // @4_44a200
  ecx = (u32)(EBP - 188);  // @5_44a200
  eax = ext_4ccba0_thiscall1(ecx);  // @6_44a200
  ecx = edx = 0;  // @7_44a200
  eax = (u32)(EBP - 188);  // @8_44a200
  reg.state = (s32)((u32)(0));  // @9_44a200
  PS[0] = eax;  // @10_44a200
  ecx = ebx;  // @11_44a200
  eax = ext_4e0fd0_thiscall2(ecx, (u32)(PS[0]));  // @12_44a200
  ecx = edx = 0;  // @13_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L44a28d;  // @14_44a200
  eax = ext_41e290_cdecl1((u32)(28));  // @15_44a200
  ecx = edx = 0;  // @16_44a200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @17_44a200
  reg.state = (s32)((u32)(1));  // @18_44a200
  if ((eax & eax) == 0) goto L44a284;  // @19_44a200
  ecx = eax;  // @20_44a200
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @21_44a200
  ecx = edx = 0;  // @22_44a200
  goto L44a286;  // @23_44a200
  L44a284:;
  eax = 0;  // @25_44a200
  L44a286:;
  reg.state = (s32)((u32)(0));  // @27_44a200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @28_44a200
  L44a28d:;
  eax = (u32)(EBP - 200);  // @30_44a200
  PS[0] = eax;  // @31_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @32_44a200
  ecx = (u32)(EBP - 188);  // @33_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @34_44a200
  ecx = edx = 0;  // @35_44a200
  eax = (u32)(EBP - 200);  // @36_44a200
  PS[0] = eax;  // @37_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @38_44a200
  ecx = (u32)(EBP - 188);  // @39_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @40_44a200
  ecx = edx = 0;  // @41_44a200
  esi = eax;  // @42_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L44a310;  // @43_44a200
  L44a2d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_44a200
  PS[0] = esi;  // @46_44a200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @47_44a200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @49_44a200
  ecx = edx = 0;  // @50_44a200
  if ((eax & eax) == 0) goto L44a2ef;  // @51_44a200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @52_44a200
  PS[0] = esi;  // @53_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @55_44a200
  ecx = edx = 0;  // @56_44a200
  L44a2ef:;
  eax = (u32)(EBP - 200);  // @58_44a200
  PS[0] = eax;  // @59_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @60_44a200
  ecx = (u32)(EBP - 188);  // @61_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @62_44a200
  ecx = edx = 0;  // @63_44a200
  esi = eax;  // @64_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L44a2d0;  // @65_44a200
  L44a310:;
  ecx = ebx;  // @67_44a200
  eax = ext_4e1b30_thiscall1(ecx);  // @68_44a200
  ecx = edx = 0;  // @69_44a200
  ecx = (u32)(EBP - 188);  // @70_44a200
  eax = ext_4ccf60_thiscall1(ecx);  // @71_44a200
  ecx = edx = 0;  // @72_44a200
  SEH_LEAVE();  // @73_44a200
  ext_633654(G(u32, 0x6f5630));  // @74_44a200
  return eax;  // @75_44a200
}

extern "C" u32 THISCALL lifted_497750(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66818f);  // @h_497750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
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
  PS[1] = eax;  // @15_497750
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @16_497750
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
  PS[0] = ebx;  // @31_497750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @32_497750
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @33_497750
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
  PS[1] = eax;  // @55_497750
  PS[2] = edx;  // @56_497750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 216)))(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(4809904));  // @57_497750
  ecx = edx = 0;  // @58_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @59_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @61_497750
  ecx = edx = 0;  // @62_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @63_497750
  if ((ecx & ecx) == 0) goto L497866;  // @64_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_497750
  PS[0] = ebx;  // @66_497750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6874404), (u32)(PS[0]));  // @67_497750
  ecx = edx = 0;  // @68_497750
  L497866:;
  SEH_LEAVE();  // @70_497750
  return eax;  // @71_497750
}

extern "C" u32 THISCALL lifted_492250(u32 ecx_in) {
  SEH_ENTER(0x667d5b);  // @h_492250
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492250
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }) == (u32)(0)) goto L4923b9;  // @2_492250
  eax = (u32)(EBP - 30016);  // @3_492250
  PS[1] = eax;  // @4_492250
  ecx = (u32)(EBP - 30332);  // @5_492250
  eax = ext_499880_thiscall3(ecx, (u32)(PS[1]), (u32)(30000));  // @6_492250
  ecx = edx = 0;  // @7_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_492250
  ecx = (u32)(EBP - 30332);  // @9_492250
  reg.state = (s32)((u32)(0));  // @10_492250
  eax = ext_49a790_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }), (u32)(2));  // @11_492250
  ecx = edx = 0;  // @12_492250
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4922da;  // @13_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2994), &v, sizeof v); }  // @14_492250
  goto L4923ae;  // @15_492250
  L4922da:;
  ecx = (u32)(EBP - 30332);  // @17_492250
  eax = ext_49b340_thiscall3(ecx, (u32)(1), (u32)(4));  // @18_492250
  ecx = edx = 0;  // @19_492250
  ecx = (u32)(EBP - 30332);  // @20_492250
  eax = ext_49b2e0_thiscall2(ecx, (u32)(1));  // @21_492250
  ecx = edx = 0;  // @22_492250
  eax = (u32)(esi + 2992);  // @23_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3008), &v, sizeof v); }  // @24_492250
  PS[0] = eax;  // @25_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @26_492250
  ecx = (u32)(EBP - 30332);  // @27_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(PS[0]));  // @28_492250
  ecx = edx = 0;  // @29_492250
  eax = (u32)(esi + 2993);  // @30_492250
  PS[0] = eax;  // @31_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @32_492250
  ecx = (u32)(EBP - 30332);  // @33_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(PS[0]));  // @34_492250
  ecx = edx = 0;  // @35_492250
  eax = (u32)(esi + 2995);  // @36_492250
  PS[0] = eax;  // @37_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @38_492250
  ecx = (u32)(EBP - 30332);  // @39_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @40_492250
  ecx = edx = 0;  // @41_492250
  eax = (u32)(esi + 23873);  // @42_492250
  PS[0] = eax;  // @43_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @44_492250
  ecx = (u32)(EBP - 30332);  // @45_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @46_492250
  ecx = edx = 0;  // @47_492250
  eax = (u32)(esi + 2988);  // @48_492250
  PS[0] = eax;  // @49_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @50_492250
  ecx = (u32)(EBP - 30332);  // @51_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(PS[0]));  // @52_492250
  ecx = edx = 0;  // @53_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_492250
  edx = (u32)(EBP - 30332);  // @55_492250
  PS[0] = edx;  // @56_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @58_492250
  ecx = edx = 0;  // @59_492250
  eax = (u32)(EBP - 30332);  // @60_492250
  ecx = esi;  // @61_492250
  PS[0] = eax;  // @62_492250
  eax = ext_492200_stdcall1((u32)(PS[0]));  // @63_492250
  ecx = edx = 0;  // @64_492250
  eax = (u32)(EBP - 30332);  // @65_492250
  ecx = esi;  // @66_492250
  PS[0] = eax;  // @67_492250
  eax = ext_492880_thiscall2(ecx, (u32)(PS[0]));  // @68_492250
  ecx = edx = 0;  // @69_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @72_492250
  ecx = edx = 0;  // @73_492250
  ecx = eax;  // @74_492250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 112)))(ecx);  // @76_492250
  ecx = edx = 0;  // @77_492250
  L4923ae:;
  ecx = (u32)(EBP - 30332);  // @79_492250
  eax = ext_499970_thiscall1(ecx);  // @80_492250
  ecx = edx = 0;  // @81_492250
  L4923b9:;
  SEH_LEAVE();  // @83_492250
  ext_633654(G(u32, 0x6f5630));  // @84_492250
  return eax;  // @85_492250
}

extern "C" u32 THISCALL lifted_492880(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667e27);  // @h_492880
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_492880
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_492880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_492880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_492880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(4));  // @4_492880
  ecx = edx = 0;  // @5_492880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_492880
  ecx = ebx;  // @7_492880
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 404)))(ecx);  // @8_492880
  ecx = edx = 0;  // @9_492880
  eax = ext_41e290_cdecl1((u32)(32));  // @10_492880
  ecx = edx = 0;  // @11_492880
  esi = eax;  // @12_492880
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @13_492880
  reg.state = (s32)((u32)(0));  // @14_492880
  if ((esi & esi) == 0) goto L49290e;  // @15_492880
  ecx = esi;  // @16_492880
  eax = ext_4e6780_thiscall2(ecx, (u32)(1026));  // @17_492880
  ecx = edx = 0;  // @18_492880
  ecx = esi;  // @19_492880
  reg.state = (s32)((u32)(1));  // @20_492880
  { u32 v = (u32)((u32)(6871484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @21_492880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @22_492880
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @23_492880
  eax = ext_48cf50_thiscall1(ecx);  // @24_492880
  ecx = edx = 0;  // @25_492880
  { u32 v = (u32)((u32)(6871512)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @26_492880
  goto L492910;  // @27_492880
  L49290e:;
  esi = 0;  // @29_492880
  L492910:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 7253), &v, sizeof v); }  // @31_492880
  edi = 0;  // @32_492880
  reg.state = (s32)((u32)(4294967295));  // @33_492880
  ebx = (ebx + (u32)(3149));  // @34_492880
  L492925:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_492880
  edx = (u32)(EBP - 16);  // @37_492880
  PS[0] = edx;  // @38_492880
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_492880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(PS[0]));  // @40_492880
  ecx = edx = 0;  // @41_492880
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @42_492880
  if ((esi & esi) == 0) goto L492993;  // @43_492880
  ecx = (u32)(esi + 1);  // @44_492880
  L492940:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @46_492880
  esi = (esi + 1);  // @47_492880
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L492940;  // @48_492880
  esi = (esi - ecx);  // @49_492880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_492880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_492880
  eax = (u32)(esi + 1);  // @52_492880
  PS[0] = eax;  // @53_492880
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, (u32)(PS[0]));  // @54_492880
  ecx = edx = 0;  // @55_492880
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @56_492880
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @57_492880
  L492960:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @59_492880
  edx = (u32)(edx + 1);  // @60_492880
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @61_492880
  eax = (u32)(eax + 1);  // @62_492880
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L492960;  // @63_492880
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @64_492880
  PS[1] = edi;  // @65_492880
  PS[2] = ebx;  // @66_492880
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7253), sizeof v); (u32)v; });  // @67_492880
  eax = ext_493820_thiscall4(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(1));  // @68_492880
  ecx = edx = 0;  // @69_492880
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7257), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 7257), &v, sizeof v); }  // @70_492880
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(1));  // @71_492880
  ecx = edx = 0;  // @72_492880
  L492993:;
  edi = (edi + 1);  // @74_492880
  ebx = (ebx + (u32)(4));  // @75_492880
  if (edi < (u32)(1026)) goto L492925;  // @76_492880
  SEH_LEAVE();  // @77_492880
  return eax;  // @78_492880
}
PCREG(492880, lifted_492880);

extern "C" u32 STDCALL lifted_601b10(u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_601b10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_601b10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_601b10
  PS[0] = eax;  // @3_601b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_601b10
  eax = (u32)(EBP - 144);  // @5_601b10
  PS[1] = eax;  // @6_601b10
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @7_601b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 324)))(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @8_601b10
  ecx = edx = 0;  // @9_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @10_601b10
  ecx = (u32)(EBP - 144);  // @11_601b10
  reg.state = (s32)((u32)(0));  // @12_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @13_601b10
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @14_601b10
  ecx = edx = 0;  // @15_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @16_601b10
  PS[0] = eax;  // @17_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @18_601b10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(PS[0]));  // @19_601b10
  ecx = edx = 0;  // @20_601b10
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L601bf7;  // @21_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @22_601b10
  ecx = (u32)(EBP - 144);  // @23_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_601b10
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @25_601b10
  ecx = edx = 0;  // @26_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @27_601b10
  PS[0] = eax;  // @28_601b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(PS[0]));  // @29_601b10
  ecx = edx = 0;  // @30_601b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @31_601b10
  eax = (eax + 1);  // @32_601b10
  PS[0] = eax;  // @33_601b10
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @34_601b10
  ecx = edx = 0;  // @35_601b10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_601b10
  ecx = (u32)(EBP - 144);  // @37_601b10
  edi = eax;  // @38_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @39_601b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @40_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @41_601b10
  PS[3] = edi;  // @42_601b10
  eax = ext_4cc1d0_cdecl4((u32)(PS[3]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }), (u32)(0), (u32)(0));  // @43_601b10
  ecx = edx = 0;  // @44_601b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @45_601b10
  PS[0] = eax;  // @46_601b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 96)))(ecx, (u32)(PS[0]));  // @47_601b10
  ecx = edx = 0;  // @48_601b10
  if (eax == ebx) goto L601bf1;  // @49_601b10
  PS[0] = edi;  // @50_601b10
  eax = ext_41e2c0_cdecl1((u32)(PS[0]));  // @51_601b10
  ecx = edx = 0;  // @52_601b10
  goto L601c25;  // @53_601b10
  L601bf1:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + edi), &v, sizeof v); }  // @55_601b10
  goto L601c27;  // @56_601b10
  L601bf7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @58_601b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_601b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7051316), (u32)(121));  // @60_601b10
  ecx = edx = 0;  // @61_601b10
  esi = eax;  // @62_601b10
  ecx = (u32)(EBP - 144);  // @63_601b10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_601b10
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_601b10
  ecx = edx = 0;  // @66_601b10
  PS[0] = eax;  // @67_601b10
  PS[2] = esi;  // @68_601b10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(PS[2]), (u32)(7051372), (u32)(PS[0]));  // @69_601b10
  ecx = edx = 0;  // @70_601b10
  L601c25:;
  edi = 0;  // @72_601b10
  L601c27:;
  ecx = (u32)(EBP - 144);  // @74_601b10
  eax = ext_4cbec0_thiscall1(ecx);  // @75_601b10
  ecx = edx = 0;  // @76_601b10
  eax = edi;  // @77_601b10
  SEH_LEAVE();  // @78_601b10
  ext_633654(G(u32, 0x6f5630));  // @79_601b10
  return eax;  // @80_601b10
}

extern "C" u32 THISCALL lifted_45c730(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665aff);  // @h_45c730
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_45c730
  PS[1] = edi;  // @2_45c730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_45c730
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(PS[1]), (u32)(0));  // @5_45c730
  ecx = edx = 0;  // @6_45c730
  esi = eax;  // @7_45c730
  if ((esi & esi) != 0) goto L45c788;  // @8_45c730
  SEH_LEAVE();  // @9_45c730
  return eax;  // @10_45c730
  L45c788:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_45c730
  ecx = esi;  // @13_45c730
  PS[0] = edi;  // @14_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(PS[0]));  // @15_45c730
  ecx = edx = 0;  // @16_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_45c730
  ecx = edi;  // @18_45c730
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @19_45c730
  ecx = edx = 0;  // @20_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @21_45c730
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L45c7d6;  // @22_45c730
  eax = ext_41e290_cdecl1((u32)(28));  // @23_45c730
  ecx = edx = 0;  // @24_45c730
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @25_45c730
  reg.state = (s32)((u32)(0));  // @26_45c730
  if ((eax & eax) == 0) goto L45c7c7;  // @27_45c730
  ecx = eax;  // @28_45c730
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @29_45c730
  ecx = edx = 0;  // @30_45c730
  ecx = eax;  // @31_45c730
  goto L45c7c9;  // @32_45c730
  L45c7c7:;
  ecx = 0;  // @34_45c730
  L45c7c9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @36_45c730
  reg.state = (s32)((u32)(4294967295));  // @37_45c730
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @38_45c730
  L45c7d6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @40_45c730
  PS[0] = esi;  // @41_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(PS[0]));  // @43_45c730
  ecx = edx = 0;  // @44_45c730
  if ((eax & eax) == 0) goto L45c7ea;  // @45_45c730
  edx = 0;  // @46_45c730
  goto L45c81b;  // @47_45c730
  L45c7ea:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @49_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @50_45c730
  if ((eax & eax) == 0) goto L45c809;  // @51_45c730
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L45c809;  // @52_45c730
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L45c809;  // @53_45c730
  ecx = esi;  // @54_45c730
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @55_45c730
  ecx = edx = 0;  // @56_45c730
  edx = eax;  // @57_45c730
  goto L45c81b;  // @58_45c730
  L45c809:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L45c818;  // @60_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_45c730
  PS[0] = esi;  // @62_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(PS[0]));  // @63_45c730
  ecx = edx = 0;  // @64_45c730
  L45c818:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @66_45c730
  L45c81b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @68_45c730
  PS[0] = edx;  // @69_45c730
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @70_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_45c730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @72_45c730
  ecx = edx = 0;  // @73_45c730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_45c730
  ecx = edi;  // @75_45c730
  PS[1] = esi;  // @76_45c730
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(PS[1]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @77_45c730
  ecx = edx = 0;  // @78_45c730
  eax = esi;  // @79_45c730
  SEH_LEAVE();  // @80_45c730
  return eax;  // @81_45c730
}
PCREG(45c730, lifted_45c730);

extern "C" u32 THISCALL lifted_492640(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ddb);  // @h_492640
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @2_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_492640
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @4_492640
  ecx = edx = 0;  // @5_492640
  eax = (u32)(EBP - 30016);  // @6_492640
  PS[1] = eax;  // @7_492640
  ecx = (u32)(EBP - 30332);  // @8_492640
  eax = ext_499880_thiscall3(ecx, (u32)(PS[1]), (u32)(30000));  // @9_492640
  ecx = edx = 0;  // @10_492640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_492640
  ecx = (u32)(EBP - 30332);  // @12_492640
  PS[1] = edi;  // @13_492640
  reg.state = (s32)((u32)(0));  // @14_492640
  eax = ext_49a790_thiscall3(ecx, (u32)(PS[1]), (u32)(1));  // @15_492640
  ecx = edx = 0;  // @16_492640
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L492746;  // @17_492640
  ecx = (u32)(EBP - 30332);  // @18_492640
  eax = ext_49b340_thiscall3(ecx, (u32)(0), (u32)(0));  // @19_492640
  ecx = edx = 0;  // @20_492640
  ecx = (u32)(EBP - 30332);  // @21_492640
  eax = ext_49b2e0_thiscall2(ecx, (u32)(0));  // @22_492640
  ecx = edx = 0;  // @23_492640
  eax = (u32)(EBP - 30340);  // @24_492640
  PS[0] = eax;  // @25_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @26_492640
  ecx = (u32)(EBP - 30332);  // @27_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @28_492640
  ecx = edx = 0;  // @29_492640
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30340), sizeof v); (u32)v; }) == (u32)(64)) goto L49271d;  // @30_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @31_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_492640
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6870936), (u32)(757));  // @33_492640
  ecx = edx = 0;  // @34_492640
  PS[1] = eax;  // @35_492640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_492640
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(PS[1]), (u32)(6871012));  // @37_492640
  ecx = edx = 0;  // @38_492640
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @39_492640
  goto L49278d;  // @40_492640
  L49271d:;
  eax = (u32)(EBP - 30336);  // @42_492640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 30336), &v, sizeof v); }  // @43_492640
  PS[0] = eax;  // @44_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @45_492640
  ecx = (u32)(EBP - 30332);  // @46_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(PS[0]));  // @47_492640
  ecx = edx = 0;  // @48_492640
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }) != (u32)(0)) goto L492756;  // @49_492640
  L492746:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_492640
  ecx = esi;  // @52_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 392)))(ecx, (u32)(1));  // @53_492640
  ecx = edx = 0;  // @54_492640
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @55_492640
  goto L49278d;  // @56_492640
  L492756:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_492640
  ecx = esi;  // @59_492640
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @60_492640
  ecx = edx = 0;  // @61_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_492640
  ecx = esi;  // @63_492640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }));  // @64_492640
  ecx = edx = 0;  // @65_492640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_492640
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 6827), &v, sizeof v); }  // @67_492640
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30336), sizeof v); (u32)v; }), (u32)(1));  // @68_492640
  ecx = edx = 0;  // @69_492640
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_492640
  L49278d:;
  ecx = (u32)(EBP - 30332);  // @72_492640
  eax = ext_499970_thiscall1(ecx);  // @73_492640
  ecx = edx = 0;  // @74_492640
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @75_492640
  SEH_LEAVE();  // @76_492640
  ext_633654(G(u32, 0x6f5630));  // @77_492640
  return eax;  // @78_492640
}

extern "C" u32 THISCALL lifted_480ff0(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_480ff0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_480ff0
  { u32 v = (u32)((u32)(6862416)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_480ff0
  ebx = (u32)(esi + 1117);  // @2_480ff0
  edi = 0;  // @3_480ff0
  L481025:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_480ff0
  if ((ecx & ecx) == 0) goto L481032;  // @6_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(1));  // @8_480ff0
  ecx = edx = 0;  // @9_480ff0
  L481032:;
  edi = (edi + 1);  // @11_480ff0
  ebx = (ebx + (u32)(4));  // @12_480ff0
  if (edi <= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1113), sizeof v); (u32)v; })) goto L481025;  // @13_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1562), sizeof v); (u32)v; });  // @14_480ff0
  if ((ecx & ecx) == 0) goto L48104e;  // @15_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_480ff0
  ecx = edx = 0;  // @18_480ff0
  L48104e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1582), sizeof v); (u32)v; }));  // @22_480ff0
  ecx = edx = 0;  // @23_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1582), sizeof v); (u32)v; });  // @24_480ff0
  if ((ecx & ecx) == 0) goto L481072;  // @25_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @27_480ff0
  ecx = edx = 0;  // @28_480ff0
  L481072:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1586), sizeof v); (u32)v; }));  // @32_480ff0
  ecx = edx = 0;  // @33_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1586), sizeof v); (u32)v; });  // @34_480ff0
  if ((ecx & ecx) == 0) goto L481096;  // @35_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @37_480ff0
  ecx = edx = 0;  // @38_480ff0
  L481096:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1590), sizeof v); (u32)v; }));  // @42_480ff0
  ecx = edx = 0;  // @43_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1590), sizeof v); (u32)v; });  // @44_480ff0
  if ((ecx & ecx) == 0) goto L4810ba;  // @45_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @47_480ff0
  ecx = edx = 0;  // @48_480ff0
  L4810ba:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1594), sizeof v); (u32)v; }));  // @52_480ff0
  ecx = edx = 0;  // @53_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1594), sizeof v); (u32)v; });  // @54_480ff0
  if ((ecx & ecx) == 0) goto L4810de;  // @55_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @57_480ff0
  ecx = edx = 0;  // @58_480ff0
  L4810de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1578), sizeof v); (u32)v; }));  // @62_480ff0
  ecx = edx = 0;  // @63_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1578), sizeof v); (u32)v; });  // @64_480ff0
  if ((ecx & ecx) == 0) goto L481102;  // @65_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @67_480ff0
  ecx = edx = 0;  // @68_480ff0
  L481102:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1598), sizeof v); (u32)v; }));  // @72_480ff0
  ecx = edx = 0;  // @73_480ff0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1598), sizeof v); (u32)v; });  // @74_480ff0
  if ((ecx & ecx) == 0) goto L481126;  // @75_480ff0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_480ff0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @77_480ff0
  ecx = edx = 0;  // @78_480ff0
  L481126:;
  ecx = esi;  // @80_480ff0
  eax = ext_471f60_thiscall1(ecx);  // @81_480ff0
  ecx = edx = 0;  // @82_480ff0
  SEH_LEAVE();  // @83_480ff0
  return eax;  // @84_480ff0
}
// retired: PCREG(480ff0, lifted_480ff0); (hand port in batch216060)

extern "C" u32 THISCALL lifted_4fe8a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b8b);  // @h_4fe8a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4fe8a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4fe8a0
  eax = (u32)(edi + 72);  // @2_4fe8a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4fe8a0
  ecx = esi;  // @4_4fe8a0
  PS[1] = eax;  // @5_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(1));  // @7_4fe8a0
  ecx = edx = 0;  // @8_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4fe8a0
  eax = (u32)(edi + 95);  // @10_4fe8a0
  PS[1] = eax;  // @11_4fe8a0
  ecx = esi;  // @12_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @13_4fe8a0
  ecx = edx = 0;  // @14_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_4fe8a0
  eax = (u32)(edi + 99);  // @16_4fe8a0
  PS[1] = eax;  // @17_4fe8a0
  ecx = esi;  // @18_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @19_4fe8a0
  ecx = edx = 0;  // @20_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_4fe8a0
  eax = (u32)(edi + 103);  // @22_4fe8a0
  PS[1] = eax;  // @23_4fe8a0
  ecx = esi;  // @24_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(1));  // @25_4fe8a0
  ecx = edx = 0;  // @26_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4fe8a0
  eax = (u32)(edi + 104);  // @28_4fe8a0
  PS[1] = eax;  // @29_4fe8a0
  ecx = esi;  // @30_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @31_4fe8a0
  ecx = edx = 0;  // @32_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4fe8a0
  eax = (u32)(edi + 108);  // @34_4fe8a0
  PS[1] = eax;  // @35_4fe8a0
  ecx = esi;  // @36_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @37_4fe8a0
  ecx = edx = 0;  // @38_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_4fe8a0
  eax = (u32)(edi + 112);  // @40_4fe8a0
  PS[1] = eax;  // @41_4fe8a0
  ecx = esi;  // @42_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @43_4fe8a0
  ecx = edx = 0;  // @44_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @45_4fe8a0
  eax = (u32)(edi + 228);  // @46_4fe8a0
  PS[1] = eax;  // @47_4fe8a0
  ecx = esi;  // @48_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @49_4fe8a0
  ecx = edx = 0;  // @50_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_4fe8a0
  eax = (u32)(edi + 232);  // @52_4fe8a0
  PS[1] = eax;  // @53_4fe8a0
  ecx = esi;  // @54_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(PS[1]), (u32)(4));  // @55_4fe8a0
  ecx = edx = 0;  // @56_4fe8a0
  PS[0] = esi;  // @57_4fe8a0
  ecx = (u32)(EBP - 332);  // @58_4fe8a0
  eax = ext_4febf0_thiscall2(ecx, (u32)(PS[0]));  // @59_4fe8a0
  ecx = edx = 0;  // @60_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 73), sizeof v); (u32)v; });  // @61_4fe8a0
  ecx = (u32)(EBP - 332);  // @62_4fe8a0
  PS[0] = eax;  // @63_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @64_4fe8a0
  reg.state = (s32)((u32)(0));  // @65_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @66_4fe8a0
  ecx = edx = 0;  // @67_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 75), sizeof v); (u32)v; });  // @68_4fe8a0
  ecx = (u32)(EBP - 332);  // @69_4fe8a0
  PS[0] = eax;  // @70_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @71_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @72_4fe8a0
  ecx = edx = 0;  // @73_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 77), sizeof v); (u32)v; });  // @74_4fe8a0
  ecx = (u32)(EBP - 332);  // @75_4fe8a0
  PS[0] = eax;  // @76_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @77_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @78_4fe8a0
  ecx = edx = 0;  // @79_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 79), sizeof v); (u32)v; });  // @80_4fe8a0
  ecx = (u32)(EBP - 332);  // @81_4fe8a0
  PS[0] = eax;  // @82_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @83_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @84_4fe8a0
  ecx = edx = 0;  // @85_4fe8a0
  ecx = (u32)(EBP - 332);  // @86_4fe8a0
  eax = ext_499980_thiscall1(ecx);  // @87_4fe8a0
  ecx = edx = 0;  // @88_4fe8a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @89_4fe8a0
  SEH_LEAVE();  // @90_4fe8a0
  ext_633654(G(u32, 0x6f5630));  // @91_4fe8a0
  return eax;  // @92_4fe8a0
}

