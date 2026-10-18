// batch216009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_634123_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_634123");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_49f670_thiscall1(u32) __asm__("ext_49f670");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccee0_thiscall1(u32) __asm__("ext_4ccee0");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4d2030_thiscall2(u32, u32) __asm__("ext_4d2030");
extern "C" u32 THISCALL ext_4d8180_thiscall3(u32, u32, u32) __asm__("ext_4d8180");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_54f890_thiscall1(u32) __asm__("ext_54f890");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 ext_41c750_cdecl0(void) __asm__("ext_41c750");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_560580_cdecl0(void) __asm__("ext_560580");
extern "C" u32 ext_580000_cdecl0(void) __asm__("ext_580000");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4cb410(u32 ecx_in) {
  SEH_ENTER(0x6691af);  // @h_4cb410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4cb410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4cb410
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4cb410
  ecx = edx = 0;  // @5_4cb410
  ecx = (u32)(EBP - 16);  // @6_4cb410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_4cb410
  PS[0] = ecx;  // @8_4cb410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_4cb410
  ecx = eax;  // @10_4cb410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6903412), (u32)(PS[0]));  // @11_4cb410
  ecx = edx = 0;  // @12_4cb410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @13_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4cb410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @15_4cb410
  ecx = edx = 0;  // @16_4cb410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @17_4cb410
  edi = eax;  // @18_4cb410
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }) != (u32)(0)) goto L4cb4b3;  // @19_4cb410
  eax = ext_41e290_cdecl1((u32)(28));  // @20_4cb410
  ecx = edx = 0;  // @21_4cb410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @22_4cb410
  reg.state = (s32)((u32)(0));  // @23_4cb410
  if ((eax & eax) == 0) goto L4cb4a7;  // @24_4cb410
  ecx = eax;  // @25_4cb410
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(16), (u32)(0));  // @26_4cb410
  ecx = edx = 0;  // @27_4cb410
  goto L4cb4a9;  // @28_4cb410
  L4cb4a7:;
  eax = 0;  // @30_4cb410
  L4cb4a9:;
  reg.state = (s32)((u32)(4294967295));  // @32_4cb410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @33_4cb410
  L4cb4b3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @35_4cb410
  PS[0] = esi;  // @36_4cb410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4cb410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @38_4cb410
  ecx = edx = 0;  // @39_4cb410
  SEH_LEAVE();  // @40_4cb410
  return eax;  // @41_4cb410
}
PCREG(4cb410, lifted_4cb410);

extern "C" u32 lifted_41cfd0(void) {
  SEH_ENTER(0x663f7f);  // @h_41cfd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  eax = ext_41e290_cdecl1((u32)(13));  // @0_41cfd0
  ecx = edx = 0;  // @1_41cfd0
  edx = eax;  // @2_41cfd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_41cfd0
  if ((edx & edx) == 0) goto L41d019;  // @4_41cfd0
  { u32 v = (u32)((u32)(6777852)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @5_41cfd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @6_41cfd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @7_41cfd0
  goto L41d01b;  // @8_41cfd0
  L41d019:;
  edx = 0;  // @10_41cfd0
  L41d01b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @12_41cfd0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7327044), &v, sizeof v); }  // @13_41cfd0
  PS[0] = edx;  // @14_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_41cfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @16_41cfd0
  ecx = edx = 0;  // @17_41cfd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @18_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_41cfd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(9));  // @20_41cfd0
  ecx = edx = 0;  // @21_41cfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327048), sizeof v); (u32)v; }) != (u32)(0)) goto L41d07a;  // @22_41cfd0
  eax = ext_41e290_cdecl1((u32)(109));  // @23_41cfd0
  ecx = edx = 0;  // @24_41cfd0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @25_41cfd0
  reg.state = (s32)((u32)(0));  // @26_41cfd0
  if ((eax & eax) == 0) goto L41d066;  // @27_41cfd0
  ecx = eax;  // @28_41cfd0
  eax = ext_54f890_thiscall1(ecx);  // @29_41cfd0
  ecx = edx = 0;  // @30_41cfd0
  ecx = eax;  // @31_41cfd0
  goto L41d068;  // @32_41cfd0
  L41d066:;
  ecx = 0;  // @34_41cfd0
  L41d068:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7327048), &v, sizeof v); }  // @36_41cfd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_41cfd0
  reg.state = (s32)((u32)(4294967295));  // @38_41cfd0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @39_41cfd0
  ecx = edx = 0;  // @40_41cfd0
  L41d07a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @42_41cfd0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) == (u32)(0)) goto L41d096;  // @43_41cfd0
  eax = ext_580000_cdecl0();  // @44_41cfd0
  ecx = edx = 0;  // @45_41cfd0
  eax = ext_560580_cdecl0();  // @46_41cfd0
  ecx = edx = 0;  // @47_41cfd0
  eax = ext_41c750_cdecl0();  // @48_41cfd0
  ecx = edx = 0;  // @49_41cfd0
  L41d096:;
  SEH_LEAVE();  // @51_41cfd0
  return eax;  // @52_41cfd0
}
PCREG(41cfd0, lifted_41cfd0);

extern "C" u32 THISCALL lifted_45cb50(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666666);  // @h_45cb50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_45cb50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_45cb50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @3_45cb50
  if ((edx & edx) == 0) goto L45cbee;  // @4_45cb50
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L45cba8;  // @5_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_45cb50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @7_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 84), sizeof v); (u32)v; });  // @8_45cb50
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; })) goto L45cbee;  // @9_45cb50
  L45cba8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 84), sizeof v); (u32)v; });  // @11_45cb50
  PS[1] = edi;  // @12_45cb50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_45cb50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 468)))(ecx, (u32)(PS[1]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @14_45cb50
  ecx = edx = 0;  // @15_45cb50
  ecx = (u32)(EBP - 144);  // @16_45cb50
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @17_45cb50
  ecx = edx = 0;  // @18_45cb50
  eax = (u32)(EBP - 144);  // @19_45cb50
  reg.state = (s32)((u32)(0));  // @20_45cb50
  PS[0] = eax;  // @21_45cb50
  ecx = edi;  // @22_45cb50
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(PS[0]));  // @23_45cb50
  ecx = edx = 0;  // @24_45cb50
  ecx = (u32)(EBP - 144);  // @25_45cb50
  reg.state = (s32)((u32)(4294967295));  // @26_45cb50
  eax = ext_4cbec0_thiscall1(ecx);  // @27_45cb50
  ecx = edx = 0;  // @28_45cb50
  L45cbee:;
  ecx = (u32)(EBP - 272);  // @30_45cb50
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @31_45cb50
  ecx = edx = 0;  // @32_45cb50
  eax = (u32)(EBP - 272);  // @33_45cb50
  reg.state = (s32)((u32)(1));  // @34_45cb50
  PS[0] = eax;  // @35_45cb50
  ecx = edi;  // @36_45cb50
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(PS[0]));  // @37_45cb50
  ecx = edx = 0;  // @38_45cb50
  ecx = (u32)(EBP - 272);  // @39_45cb50
  eax = ext_4cbec0_thiscall1(ecx);  // @40_45cb50
  ecx = edx = 0;  // @41_45cb50
  SEH_LEAVE();  // @42_45cb50
  ext_633654(G(u32, 0x6f5630));  // @43_45cb50
  return eax;  // @44_45cb50
}
PCREG(45cb50, lifted_45cb50);

extern "C" u32 THISCALL lifted_430010(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66528c);  // @h_430010
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ecx;  // @0_430010
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_430010
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_430010
  if ((esi & esi) == 0) goto L4300ab;  // @3_430010
  L430042:;
  ecx = eax;  // @5_430010
  eax = ext_430010_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }));  // @6_430010
  ecx = edx = 0;  // @7_430010
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @8_430010
  ecx = (u32)(esi + 25);  // @9_430010
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @11_430010
  eax = (eax - edx);  // @12_430010
  reg.state = (s32)((u32)(0));  // @13_430010
  if ((edx & edx) == 0) goto L43006f;  // @14_430010
  if ((eax & eax) == 0) goto L43006f;  // @15_430010
  PS[0] = eax;  // @16_430010
  PS[1] = edx;  // @17_430010
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @18_430010
  ecx = edx = 0;  // @19_430010
  L43006f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; });  // @21_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @22_430010
  eax = (eax - edx);  // @23_430010
  reg.state = (s32)((u32)(1));  // @24_430010
  if ((edx & edx) == 0) goto L430090;  // @25_430010
  if ((eax & eax) == 0) goto L430090;  // @26_430010
  PS[0] = eax;  // @27_430010
  PS[1] = edx;  // @28_430010
  ecx = (u32)(esi + 13);  // @29_430010
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @30_430010
  ecx = edx = 0;  // @31_430010
  L430090:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @33_430010
  PS[1] = esi;  // @34_430010
  reg.state = (s32)((u32)(4294967295));  // @35_430010
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(37));  // @36_430010
  ecx = edx = 0;  // @37_430010
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @38_430010
  esi = ebx;  // @39_430010
  if ((ebx & ebx) != 0) goto L430042;  // @40_430010
  L4300ab:;
  SEH_LEAVE();  // @42_430010
  return eax;  // @43_430010
}
PCREG(430010, lifted_430010);

extern "C" u32 THISCALL lifted_447690(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447690
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447690
  { u32 v = (u32)((u32)(6811248)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447690
  if ((ecx & ecx) == 0) goto L447714;  // @3_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447690
  edx = (u32)(EBP - 24);  // @5_447690
  PS[0] = edx;  // @6_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @7_447690
  ecx = edx = 0;  // @8_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @9_447690
  edx = (u32)(EBP - 24);  // @10_447690
  PS[0] = edx;  // @11_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @13_447690
  ecx = edx = 0;  // @14_447690
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L447714;  // @15_447690
  L4476e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_447690
  PS[0] = eax;  // @18_447690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_447690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @21_447690
  ecx = edx = 0;  // @22_447690
  if ((eax & eax) == 0) goto L447702;  // @23_447690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_447690
  ecx = eax;  // @25_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_447690
  ecx = edx = 0;  // @27_447690
  L447702:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @29_447690
  edx = (u32)(EBP - 24);  // @30_447690
  PS[0] = edx;  // @31_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @33_447690
  ecx = edx = 0;  // @34_447690
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4476e0;  // @35_447690
  L447714:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @37_447690
  if ((ecx & ecx) == 0) goto L447721;  // @38_447690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_447690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @40_447690
  ecx = edx = 0;  // @41_447690
  L447721:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @43_447690
  reg.state = (s32)((u32)(0));  // @44_447690
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_447690
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @46_447690
  ecx = edx = 0;  // @47_447690
  ecx = esi;  // @48_447690
  eax = ext_45c3e0_thiscall1(ecx);  // @49_447690
  ecx = edx = 0;  // @50_447690
  SEH_LEAVE();  // @51_447690
  return eax;  // @52_447690
}
PCREG(447690, lifted_447690);

extern "C" u32 THISCALL lifted_447810(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_447810
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @1_447810
  { u32 v = (u32)((u32)(6812432)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_447810
  if ((ecx & ecx) == 0) goto L447894;  // @3_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_447810
  edx = (u32)(EBP - 24);  // @5_447810
  PS[0] = edx;  // @6_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @7_447810
  ecx = edx = 0;  // @8_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @9_447810
  edx = (u32)(EBP - 24);  // @10_447810
  PS[0] = edx;  // @11_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @13_447810
  ecx = edx = 0;  // @14_447810
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L447894;  // @15_447810
  L447860:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_447810
  PS[0] = eax;  // @18_447810
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_447810
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @21_447810
  ecx = edx = 0;  // @22_447810
  if ((eax & eax) == 0) goto L447882;  // @23_447810
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_447810
  ecx = eax;  // @25_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @26_447810
  ecx = edx = 0;  // @27_447810
  L447882:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @29_447810
  edx = (u32)(EBP - 24);  // @30_447810
  PS[0] = edx;  // @31_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @33_447810
  ecx = edx = 0;  // @34_447810
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L447860;  // @35_447810
  L447894:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @37_447810
  if ((ecx & ecx) == 0) goto L4478a1;  // @38_447810
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_447810
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @40_447810
  ecx = edx = 0;  // @41_447810
  L4478a1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @43_447810
  reg.state = (s32)((u32)(0));  // @44_447810
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @45_447810
  eax = ext_4dbb00_thiscall2(ecx, (u32)(0));  // @46_447810
  ecx = edx = 0;  // @47_447810
  ecx = esi;  // @48_447810
  eax = ext_45c3e0_thiscall1(ecx);  // @49_447810
  ecx = edx = 0;  // @50_447810
  SEH_LEAVE();  // @51_447810
  return eax;  // @52_447810
}
PCREG(447810, lifted_447810);

extern "C" u32 THISCALL lifted_57c6f0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x66b1bb);  // @h_57c6f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ecx;  // @0_57c6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_57c6f0
  ecx = (u32)(ebx + 44);  // @3_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @6_57c6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @7_57c6f0
  eax = ext_4cbeb0_thiscall1(ecx);  // @8_57c6f0
  ecx = edx = 0;  // @9_57c6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @10_57c6f0
  ecx = (u32)(EBP + 12);  // @11_57c6f0
  PS[0] = ecx;  // @12_57c6f0
  ecx = edi;  // @13_57c6f0
  reg.state = (s32)((u32)(0));  // @14_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @16_57c6f0
  ecx = edx = 0;  // @17_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @21_57c6f0
  ecx = edx = 0;  // @22_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @23_57c6f0
  esi = (u32)(ebx + 12);  // @24_57c6f0
  ebx = (u32)(8);  // @25_57c6f0
  L57c764:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_57c6f0
  ecx = (u32)(EBP + 12);  // @28_57c6f0
  PS[0] = ecx;  // @29_57c6f0
  ecx = edi;  // @30_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @31_57c6f0
  ecx = edx = 0;  // @32_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_57c6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @36_57c6f0
  ecx = edx = 0;  // @37_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @38_57c6f0
  esi = (u32)(esi + 4);  // @39_57c6f0
  ebx = (ebx - (u32)(1));  // @40_57c6f0
  if (ebx != 0) goto L57c764;  // @41_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_57c6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_57c6f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @44_57c6f0
  ecx = edx = 0;  // @45_57c6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @46_57c6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @47_57c6f0
  eax = ecx;  // @48_57c6f0
  SEH_LEAVE();  // @49_57c6f0
  return eax;  // @50_57c6f0
}
PCREG(57c6f0, lifted_57c6f0);

extern "C" u32 THISCALL lifted_602530(u32 ecx_in) {
  SEH_ENTER(0x66da28);  // @h_602530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_602530
  ecx = (u32)(esi + 36);  // @1_602530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @3_602530
  eax = (eax - edx);  // @4_602530
  reg.state = (s32)((u32)(0));  // @5_602530
  if ((edx & edx) == 0) goto L602575;  // @6_602530
  if ((eax & eax) == 0) goto L602575;  // @7_602530
  PS[0] = eax;  // @8_602530
  PS[1] = edx;  // @9_602530
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @10_602530
  ecx = edx = 0;  // @11_602530
  L602575:;
  ecx = (u32)(esi + 24);  // @13_602530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @15_602530
  eax = (eax - edx);  // @16_602530
  reg.state = (s32)((u32)(1));  // @17_602530
  if ((edx & edx) == 0) goto L602595;  // @18_602530
  if ((eax & eax) == 0) goto L602595;  // @19_602530
  PS[0] = eax;  // @20_602530
  PS[1] = edx;  // @21_602530
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @22_602530
  ecx = edx = 0;  // @23_602530
  L602595:;
  ecx = (u32)(esi + 12);  // @25_602530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @27_602530
  eax = (eax - edx);  // @28_602530
  reg.state = (s32)((u32)(2));  // @29_602530
  if ((edx & edx) == 0) goto L6025b5;  // @30_602530
  if ((eax & eax) == 0) goto L6025b5;  // @31_602530
  PS[0] = eax;  // @32_602530
  PS[1] = edx;  // @33_602530
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @34_602530
  ecx = edx = 0;  // @35_602530
  L6025b5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_602530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @38_602530
  eax = (eax - ecx);  // @39_602530
  reg.state = (s32)((u32)(3));  // @40_602530
  if ((ecx & ecx) == 0) goto L6025d4;  // @41_602530
  if ((eax & eax) == 0) goto L6025d4;  // @42_602530
  PS[0] = eax;  // @43_602530
  PS[1] = ecx;  // @44_602530
  ecx = esi;  // @45_602530
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @46_602530
  ecx = edx = 0;  // @47_602530
  L6025d4:;
  SEH_LEAVE();  // @49_602530
  return eax;  // @50_602530
}
PCREG(602530, lifted_602530);

extern "C" u32 THISCALL lifted_49f5a0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_49f5a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_49f5a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_49f5a0
  eax = ext_469870_thiscall1(ecx);  // @2_49f5a0
  ecx = edx = 0;  // @3_49f5a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_49f5a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_49f5a0
  ecx = (u32)(esi + 108);  // @6_49f5a0
  reg.state = (s32)((u32)(0));  // @7_49f5a0
  { u32 v = (u32)((u32)(6878560)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_49f5a0
  eax = ext_49f670_thiscall1(ecx);  // @9_49f5a0
  ecx = edx = 0;  // @10_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_49f5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_49f5a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @14_49f5a0
  ecx = edx = 0;  // @15_49f5a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @16_49f5a0
  edi = eax;  // @17_49f5a0
  PS[0] = esi;  // @18_49f5a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_49f5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(PS[0]));  // @20_49f5a0
  ecx = edx = 0;  // @21_49f5a0
  if ((eax & eax) == 0) goto L49f618;  // @22_49f5a0
  ecx = 0;  // @23_49f5a0
  goto L49f649;  // @24_49f5a0
  L49f618:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @26_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @27_49f5a0
  if ((eax & eax) == 0) goto L49f637;  // @28_49f5a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L49f637;  // @29_49f5a0
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L49f637;  // @30_49f5a0
  ecx = esi;  // @31_49f5a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @32_49f5a0
  ecx = edx = 0;  // @33_49f5a0
  ecx = eax;  // @34_49f5a0
  goto L49f649;  // @35_49f5a0
  L49f637:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L49f646;  // @37_49f5a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_49f5a0
  PS[0] = esi;  // @39_49f5a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(PS[0]));  // @40_49f5a0
  ecx = edx = 0;  // @41_49f5a0
  L49f646:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @43_49f5a0
  L49f649:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_49f5a0
  PS[1] = ecx;  // @46_49f5a0
  ecx = edi;  // @47_49f5a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6879012), (u32)(PS[1]), (u32)(4));  // @48_49f5a0
  ecx = edx = 0;  // @49_49f5a0
  eax = esi;  // @50_49f5a0
  SEH_LEAVE();  // @51_49f5a0
  return eax;  // @52_49f5a0
}
PCREG(49f5a0, lifted_49f5a0);

extern "C" u32 THISCALL lifted_461120(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66583b);  // @h_461120
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_461120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_461120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_461120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @3_461120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @4_461120
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_461120
  PS[0] = ecx;  // @6_461120
  ecx = ebx;  // @7_461120
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 540)))(ecx, (u32)(PS[0]));  // @8_461120
  ecx = edx = 0;  // @9_461120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @10_461120
  if ((eax & eax) != 0) goto L4611d6;  // @11_461120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @12_461120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_461120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6838324), (u32)(1440));  // @14_461120
  ecx = edx = 0;  // @15_461120
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_461120
  edi = eax;  // @17_461120
  eax = (u32)(EBP - 144);  // @18_461120
  ecx = ebx;  // @19_461120
  PS[1] = eax;  // @20_461120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @21_461120
  ecx = edx = 0;  // @22_461120
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_461120
  ecx = eax;  // @24_461120
  reg.state = (s32)((u32)(0));  // @25_461120
  eax = ext_4cc1d0_thiscall1(ecx);  // @26_461120
  ecx = edx = 0;  // @27_461120
  PS[0] = eax;  // @28_461120
  PS[3] = edi;  // @29_461120
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[3]), (u32)(6838660), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }), (u32)(PS[0]));  // @30_461120
  ecx = edx = 0;  // @31_461120
  reg.state = (s32)((u32)(4294967295));  // @32_461120
  ecx = (u32)(EBP - 144);  // @33_461120
  eax = ext_4cbec0_thiscall1(ecx);  // @34_461120
  ecx = edx = 0;  // @35_461120
  L4611d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_461120
  ecx = ebx;  // @38_461120
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 560)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }));  // @39_461120
  ecx = edx = 0;  // @40_461120
  SEH_LEAVE();  // @41_461120
  ext_633654(G(u32, 0x6f5630));  // @42_461120
  return eax;  // @43_461120
}
PCREG(461120, lifted_461120);

extern "C" u32 THISCALL lifted_4afc70(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4afc70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  ebx = ecx;  // @0_4afc70
  eax = (u32)(EBP - 148);  // @1_4afc70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @2_4afc70
  PS[0] = eax;  // @3_4afc70
  eax = ext_6352f0_thiscall2(ecx, (u32)(PS[0]));  // @4_4afc70
  ecx = edx = 0;  // @5_4afc70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_4afc70
  ecx = (u32)(EBP - 148);  // @7_4afc70
  PS[0] = ecx;  // @8_4afc70
  ecx = ebx;  // @9_4afc70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(PS[0]));  // @10_4afc70
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
  PS[1] = eax;  // @21_4afc70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4afc70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @23_4afc70
  ecx = edx = 0;  // @24_4afc70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4afc70
  ecx = eax;  // @26_4afc70
  reg.state = (s32)((u32)(0));  // @27_4afc70
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_4afc70
  ecx = edx = 0;  // @29_4afc70
  PS[0] = eax;  // @30_4afc70
  PS[2] = edi;  // @31_4afc70
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6890728), (u32)(PS[0]));  // @32_4afc70
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

extern "C" u32 THISCALL lifted_4d1530(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4d1530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @1_4d1530
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4d1530
  if ((eax & eax) == 0) goto L4d1574;  // @3_4d1530
  PS[1] = eax;  // @4_4d1530
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(4));  // @5_4d1530
  ecx = edx = 0;  // @6_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @7_4d1530
  L4d1574:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @9_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @10_4d1530
  if ((eax & eax) == 0) goto L4d158d;  // @11_4d1530
  PS[1] = eax;  // @12_4d1530
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(4));  // @13_4d1530
  ecx = edx = 0;  // @14_4d1530
  L4d158d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) == (u32)(0)) goto L4d15a7;  // @16_4d1530
  L4d1593:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @18_4d1530
  if ((ecx & ecx) == 0) goto L4d15a1;  // @19_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4d1530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @21_4d1530
  ecx = edx = 0;  // @22_4d1530
  L4d15a1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L4d1593;  // @24_4d1530
  L4d15a7:;
  ecx = esi;  // @26_4d1530
  eax = ext_4d2030_thiscall2(ecx, (u32)(-1));  // @27_4d1530
  ecx = edx = 0;  // @28_4d1530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @29_4d1530
  if ((ecx & ecx) == 0) goto L4d15ec;  // @30_4d1530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @31_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_4d1530
  if ((edx & edx) == 0) goto L4d15c6;  // @33_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 48), &v, sizeof v); }  // @34_4d1530
  goto L4d15c9;  // @35_4d1530
  L4d15c6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 36), &v, sizeof v); }  // @37_4d1530
  L4d15c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @39_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @40_4d1530
  if ((ecx & ecx) == 0) goto L4d15d8;  // @41_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @42_4d1530
  goto L4d15de;  // @43_4d1530
  L4d15d8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @45_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @46_4d1530
  L4d15de:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @48_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @49_4d1530
  L4d15ec:;
  SEH_LEAVE();  // @51_4d1530
  return eax;  // @52_4d1530
}
PCREG(4d1530, lifted_4d1530);

extern "C" u32 THISCALL lifted_4b2060(u32 ecx_in) {
  SEH_ENTER(0x665fd6);  // @h_4b2060
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_4b2060
  { u32 v = (u32)((u32)(6888700)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4b2060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; }) == (u32)(0)) goto L4b20dc;  // @2_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4b2060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4b2060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; }));  // @6_4b2060
  ecx = edx = 0;  // @7_4b2060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @8_4b2060
  PS[0] = eax;  // @9_4b2060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4b2060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @11_4b2060
  ecx = edx = 0;  // @12_4b2060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @13_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_4b2060
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @15_4b2060
  ecx = edx = 0;  // @16_4b2060
  if ((eax & eax) != 0) goto L4b20d2;  // @17_4b2060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340852), sizeof v); (u32)v; });  // @18_4b2060
  if ((ecx & ecx) == 0) goto L4b20d2;  // @19_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4b2060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @21_4b2060
  ecx = edx = 0;  // @22_4b2060
  L4b20d2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7340852), &v, sizeof v); }  // @24_4b2060
  L4b20dc:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 158), sizeof v); (u32)v; }) == (u32)(0)) goto L4b211a;  // @26_4b2060
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 152), sizeof v); (u32)v; }) == (u32)(0)) goto L4b211a;  // @27_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @29_4b2060
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) == (u32)(0)) goto L4b211a;  // @30_4b2060
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 253), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 253), &v, sizeof v); }  // @31_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @33_4b2060
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 257), &v, sizeof v); }  // @34_4b2060
  L4b211a:;
  ecx = (u32)(esi + 270);  // @36_4b2060
  eax = ext_4ccfe0_thiscall1(ecx);  // @37_4b2060
  ecx = edx = 0;  // @38_4b2060
  ecx = (u32)(esi + 242);  // @39_4b2060
  eax = ext_4ccfe0_thiscall1(ecx);  // @40_4b2060
  ecx = edx = 0;  // @41_4b2060
  ecx = (u32)(esi + 170);  // @42_4b2060
  eax = ext_4ccee0_thiscall1(ecx);  // @43_4b2060
  ecx = edx = 0;  // @44_4b2060
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @45_4b2060
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @46_4b2060
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @47_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_4b2060
  PS[0] = esi;  // @49_4b2060
  reg.state = (s32)((u32)(0));  // @50_4b2060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @51_4b2060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_4b2060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(PS[0]));  // @53_4b2060
  ecx = edx = 0;  // @54_4b2060
  SEH_LEAVE();  // @55_4b2060
  return eax;  // @56_4b2060
}
PCREG(4b2060, lifted_4b2060);

extern "C" u32 THISCALL lifted_5f2130(u32 ecx_in) {
  SEH_ENTER(0x66cf82);  // @h_5f2130
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  ebx = ecx;  // @0_5f2130
  eax = ext_41e290_cdecl1((u32)(264));  // @1_5f2130
  ecx = edx = 0;  // @2_5f2130
  edi = eax;  // @3_5f2130
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_5f2130
  reg.state = (s32)((u32)(0));  // @5_5f2130
  if ((edi & edi) == 0) goto L5f219a;  // @6_5f2130
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @7_5f2130
  ecx = edi;  // @8_5f2130
  esi = (esi + (u32)(20));  // @9_5f2130
  eax = ext_4d8180_thiscall3(ecx, (u32)(7046956), (u32)(7046848));  // @10_5f2130
  ecx = edx = 0;  // @11_5f2130
  { u32 v = (u32)((u32)(7046052)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @12_5f2130
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 260), &v, sizeof v); }  // @13_5f2130
  goto L5f219c;  // @14_5f2130
  L5f219a:;
  edi = 0;  // @16_5f2130
  L5f219c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @18_5f2130
  reg.state = (s32)((u32)(4294967295));  // @19_5f2130
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 148), &v, sizeof v); }  // @20_5f2130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_5f2130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @22_5f2130
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_5f2130
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 420)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 148), sizeof v); (u32)v; }));  // @24_5f2130
  ecx = edx = 0;  // @25_5f2130
  ecx = ebx;  // @26_5f2130
  eax = ext_4690b0_cdecl0();  // @27_5f2130
  ecx = edx = 0;  // @28_5f2130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5f2130
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_5f2130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_5f2130
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6900844), (u32)(0), (u32)(7046968), (u32)(223));  // @32_5f2130
  ecx = edx = 0;  // @33_5f2130
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422896), &v, sizeof v); }  // @34_5f2130
  ecx = ebx;  // @35_5f2130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_5f2130
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 120)))(ecx);  // @37_5f2130
  ecx = edx = 0;  // @38_5f2130
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_5f2130
  ecx = ebx;  // @40_5f2130
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_5f2130
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6971), sizeof v); (u32)v; });  // @42_5f2130
  PS[0] = eax;  // @43_5f2130
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(PS[0]));  // @44_5f2130
  ecx = edx = 0;  // @45_5f2130
  SEH_LEAVE();  // @46_5f2130
  return eax;  // @47_5f2130
}
PCREG(5f2130, lifted_5f2130);

extern "C" u32 THISCALL lifted_5249c0(u32 ecx_in) {
  SEH_ENTER(0x66a47c);  // @h_5249c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_5249c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5249c0
  eax = (u32)(esi + 189);  // @2_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @3_5249c0
  PS[4] = eax;  // @4_5249c0
  eax = ext_634123_stdcall5((u32)(PS[4]), (u32)(222), (u32)(4), (u32)(5332384), (u32)(5332736));  // @5_5249c0
  ecx = edx = 0;  // @6_5249c0
  eax = (u32)(esi + 1077);  // @7_5249c0
  reg.state = (s32)((u32)(0));  // @8_5249c0
  PS[4] = eax;  // @9_5249c0
  eax = ext_634123_stdcall5((u32)(PS[4]), (u32)(222), (u32)(4), (u32)(5332384), (u32)(5332736));  // @10_5249c0
  ecx = edx = 0;  // @11_5249c0
  eax = (u32)(esi + 1965);  // @12_5249c0
  reg.state = (s32)((u32)(1));  // @13_5249c0
  PS[4] = eax;  // @14_5249c0
  eax = ext_634123_stdcall5((u32)(PS[4]), (u32)(355), (u32)(4), (u32)(5412864), (u32)(5314864));  // @15_5249c0
  ecx = edx = 0;  // @16_5249c0
  eax = (u32)(esi + 3385);  // @17_5249c0
  reg.state = (s32)((u32)(2));  // @18_5249c0
  PS[4] = eax;  // @19_5249c0
  eax = ext_634123_stdcall5((u32)(PS[4]), (u32)(307), (u32)(4), (u32)(5413072), (u32)(5315248));  // @20_5249c0
  ecx = edx = 0;  // @21_5249c0
  eax = (u32)(esi + 4613);  // @22_5249c0
  reg.state = (s32)((u32)(3));  // @23_5249c0
  PS[4] = eax;  // @24_5249c0
  eax = ext_634123_stdcall5((u32)(PS[4]), (u32)(121), (u32)(2), (u32)(5334992), (u32)(4624560));  // @25_5249c0
  ecx = edx = 0;  // @26_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 140), &v, sizeof v); }  // @27_5249c0
  eax = esi;  // @28_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 144), &v, sizeof v); }  // @29_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4855), &v, sizeof v); }  // @30_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @31_5249c0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @32_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @33_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @34_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @35_5249c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 172), &v, sizeof v); }  // @36_5249c0
  SEH_LEAVE();  // @37_5249c0
  return eax;  // @38_5249c0
}
PCREG(5249c0, lifted_5249c0);

