// batch216016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_616490(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66e5f8);  // @h_616490
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  edi = ecx;  // @0_616490
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_616490
  ecx = (u32)(edi + 8);  // @5_616490
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @6_616490
  { u32 v = (u32)((u32)(7068916)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @7_616490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_616490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @9_616490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @10_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @11_616490
  reg.state = (s32)((u32)(0));  // @12_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @13_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_616490
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @15_616490
  PS[1] = ebx;  // @16_616490
  eax = ext_659330_thiscall3(ecx, (u32)(PS[1]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47528), sizeof v); (u32)v; }));  // @17_616490
  ecx = edx = 0;  // @18_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 47524), sizeof v); (u32)v; });  // @19_616490
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5114), sizeof v); (u32)v; });  // @20_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @22_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @23_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @24_616490
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L616561;  // @25_616490
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L61653b;  // @26_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_616490
  ecx = esi;  // @28_616490
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @29_616490
  ecx = edx = 0;  // @30_616490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @31_616490
  L61653b:;
  eax = (u32)(ebx + ebx*8);  // @33_616490
  eax = (eax << (u32)(2));  // @34_616490
  PS[0] = eax;  // @35_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @37_616490
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @38_616490
  PS[1] = eax;  // @39_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @40_616490
  ecx = (u32)(eax + eax*8);  // @41_616490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @42_616490
  eax = (u32)(eax + ecx*4);  // @43_616490
  PS[2] = eax;  // @44_616490
  eax = ext_634d22_cdecl3((u32)(PS[2]), (u32)(PS[1]), (u32)(PS[0]));  // @45_616490
  ecx = edx = 0;  // @46_616490
  L616561:;
  eax = edi;  // @48_616490
  SEH_LEAVE();  // @49_616490
  return eax;  // @50_616490
}
PCREG(616490, lifted_616490);

extern "C" u32 THISCALL lifted_4b1f10(u32 ecx_in) {
  SEH_ENTER(0x6689e6);  // @h_4b1f10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_4b1f10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b1f10
  eax = ext_469870_thiscall1(ecx);  // @2_4b1f10
  ecx = edx = 0;  // @3_4b1f10
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b1f10
  { u32 v = (u32)((u32)(6888848)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4b1f10
  edi = (u32)(esi + 80);  // @7_4b1f10
  ecx = (u32)(esi + 149);  // @8_4b1f10
  reg.state = (s32)((u32)(0));  // @9_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_4b1f10
  eax = ext_4cbeb0_thiscall1(ecx);  // @11_4b1f10
  ecx = edx = 0;  // @12_4b1f10
  eax = (u32)(EBP - 20);  // @13_4b1f10
  reg.state = (s32)((u32)(1));  // @14_4b1f10
  if (edi == eax) goto L4b1f7e;  // @15_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @16_4b1f10
  L4b1f7e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @18_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @19_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @20_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @21_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @22_4b1f10
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @23_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 128), &v, sizeof v); }  // @24_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @25_4b1f10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 132), &v, sizeof v); }  // @26_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 283), &v, sizeof v); }  // @27_4b1f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 287), &v, sizeof v); }  // @28_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4b1f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4b1f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6889180), (u32)(2749));  // @32_4b1f10
  ecx = edx = 0;  // @33_4b1f10
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 279), &v, sizeof v); }  // @34_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4b1f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_4b1f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4b1f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6889180), (u32)(2750));  // @38_4b1f10
  ecx = edx = 0;  // @39_4b1f10
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 281), &v, sizeof v); }  // @40_4b1f10
  eax = (u32)(esi + 291);  // @41_4b1f10
  PS[2] = eax;  // @42_4b1f10
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(256));  // @43_4b1f10
  ecx = edx = 0;  // @44_4b1f10
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 547), &v, sizeof v); }  // @45_4b1f10
  eax = esi;  // @46_4b1f10
  SEH_LEAVE();  // @47_4b1f10
  return eax;  // @48_4b1f10
}
PCREG(4b1f10, lifted_4b1f10);

extern "C" u32 THISCALL lifted_441e40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665e4f);  // @h_441e40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_441e40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; }) != (u32)(0)) goto L441ecd;  // @1_441e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338344), sizeof v); (u32)v; });  // @2_441e40
  if ((ecx & ecx) != 0) goto L441eb0;  // @3_441e40
  eax = ext_41e290_cdecl1((u32)(40));  // @4_441e40
  ecx = edx = 0;  // @5_441e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_441e40
  reg.state = (s32)((u32)(0));  // @7_441e40
  if ((eax & eax) == 0) goto L441ea1;  // @8_441e40
  ecx = eax;  // @9_441e40
  eax = ext_4cca60_thiscall3(ecx, (u32)(1), (u32)(288));  // @10_441e40
  ecx = edx = 0;  // @11_441e40
  ecx = eax;  // @12_441e40
  goto L441ea3;  // @13_441e40
  L441ea1:;
  ecx = 0;  // @15_441e40
  L441ea3:;
  reg.state = (s32)((u32)(4294967295));  // @17_441e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7338344), &v, sizeof v); }  // @18_441e40
  L441eb0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_441e40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @21_441e40
  ecx = edx = 0;  // @22_441e40
  eax = (eax + (u32)(-4));  // @23_441e40
  PS[2] = eax;  // @24_441e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @25_441e40
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(1156));  // @26_441e40
  ecx = edx = 0;  // @27_441e40
  L441ecd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @29_441e40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_441e40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @31_441e40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 1028), &v, sizeof v); }  // @32_441e40
  ecx = esi;  // @33_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @34_441e40
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 2), &v, sizeof v); }  // @35_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 784), sizeof v); (u32)v; });  // @37_441e40
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @38_441e40
  ecx = edx = 0;  // @39_441e40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L441f2b;  // @40_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_441e40
  ecx = esi;  // @42_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @43_441e40
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @44_441e40
  ecx = edx = 0;  // @45_441e40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L441f2b;  // @46_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_441e40
  ecx = esi;  // @48_441e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @49_441e40
  ecx = edx = 0;  // @50_441e40
  if ((eax & eax) == 0) goto L441f2b;  // @51_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_441e40
  ecx = esi;  // @53_441e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @54_441e40
  ecx = edx = 0;  // @55_441e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @56_441e40
  eax = ext_4db7e0_thiscall1(ecx);  // @57_441e40
  ecx = edx = 0;  // @58_441e40
  if ((eax & eax) == 0) goto L441f2b;  // @59_441e40
  PS[0] = edi;  // @60_441e40
  ecx = eax;  // @61_441e40
  eax = ext_441e40_thiscall2(ecx, (u32)(PS[0]));  // @62_441e40
  ecx = edx = 0;  // @63_441e40
  L441f2b:;
  SEH_LEAVE();  // @65_441e40
  return eax;  // @66_441e40
}
PCREG(441e40, lifted_441e40);

