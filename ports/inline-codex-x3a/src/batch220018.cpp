// batch220018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_632360_cdecl10(...) __asm__("ext_632360");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_632940(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  u8 F[0x400] __attribute__((aligned(16)));
  volatile u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[27];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  __builtin_memcpy(F + 0x300 + 40, &a8, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 40), sizeof v); (u32)v; });  // @0_632940
  STK[0] = (u32)(4);  // @1_632940
  STK[1] = (u32)(288);  // @2_632940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_632940
  STK[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @4_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @5_632940
  eax = ((u32( *)(u32, u32, u32))(eax))(STK[2], STK[1], STK[0]);  // @6_632940
  ecx = edx = 0;  // @7_632940
  ebx = eax;  // @8_632940
  if ((ebx & ebx) != 0) goto L632971;  // @9_632940
  eax = (u32)(ebx - 4);  // @10_632940
  return eax;  // @11_632940
  L632971:;
  STK[3] = ebx;  // @13_632940
  eax = (u32)(EBP - 4);  // @14_632940
  STK[4] = eax;  // @15_632940
  STK[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @16_632940
  STK[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @17_632940
  STK[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @18_632940
  STK[8] = (u32)(7082840);  // @19_632940
  STK[9] = (u32)(7082712);  // @20_632940
  STK[10] = (u32)(257);  // @21_632940
  STK[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_632940
  STK[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @23_632940
  eax = ext_632360_cdecl10(STK[12], STK[11], STK[10], STK[9], STK[8], STK[7], STK[6], STK[5], STK[4], STK[3]);  // @24_632940
  ecx = edx = 0;  // @25_632940
  edi = eax;  // @26_632940
  if ((edi & edi) != 0) goto L632a35;  // @27_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @28_632940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == edi) goto L632a48;  // @29_632940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @30_632940
  eax = (u32)(EBP - 4);  // @31_632940
  STK[13] = ebx;  // @32_632940
  STK[14] = eax;  // @33_632940
  STK[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @34_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @35_632940
  STK[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @36_632940
  STK[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @37_632940
  eax = (u32)(ecx + eax*4);  // @38_632940
  STK[18] = (u32)(7083088);  // @39_632940
  STK[19] = (u32)(7082968);  // @40_632940
  STK[20] = edi;  // @41_632940
  STK[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @42_632940
  STK[22] = eax;  // @43_632940
  eax = ext_632360_cdecl10(STK[22], STK[21], STK[20], STK[19], STK[18], STK[17], STK[16], STK[15], STK[14], STK[13]);  // @44_632940
  ecx = edx = 0;  // @45_632940
  edi = eax;  // @46_632940
  if ((edi & edi) != 0) goto L632a0b;  // @47_632940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @48_632940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != edi) goto L6329f6;  // @49_632940
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) > (u32)(257)) goto L632a2c;  // @50_632940
  L6329f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @52_632940
  STK[23] = ebx;  // @53_632940
  STK[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @54_632940
  eax = ((u32( *)(u32, u32))(eax))(STK[24], STK[23]);  // @55_632940
  ecx = edx = 0;  // @56_632940
  eax = 0;  // @57_632940
  return eax;  // @58_632940
  L632a0b:;
  if (edi != (u32)(-3)) goto L632a19;  // @60_632940
  { u32 v = (u32)((u32)(7083352)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @61_632940
  goto L632a54;  // @62_632940
  L632a19:;
  if (edi != (u32)(-5)) goto L632a27;  // @64_632940
  { u32 v = (u32)((u32)(7083384)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @65_632940
  goto L632a4f;  // @66_632940
  L632a27:;
  if (edi == (u32)(-4)) goto L632a54;  // @68_632940
  L632a2c:;
  { u32 v = (u32)((u32)(7083412)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @70_632940
  goto L632a4f;  // @71_632940
  L632a35:;
  if (edi != (u32)(-3)) goto L632a43;  // @73_632940
  { u32 v = (u32)((u32)(7083284)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @74_632940
  goto L632a54;  // @75_632940
  L632a43:;
  if (edi == (u32)(-4)) goto L632a54;  // @77_632940
  L632a48:;
  { u32 v = (u32)((u32)(7083320)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @79_632940
  L632a4f:;
  edi = (u32)(4294967293);  // @81_632940
  L632a54:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @83_632940
  STK[25] = ebx;  // @84_632940
  STK[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @85_632940
  eax = ((u32( *)(u32, u32))(eax))(STK[26], STK[25]);  // @86_632940
  ecx = edx = 0;  // @87_632940
  eax = edi;  // @88_632940
  return eax;  // @89_632940
}
PCREG(632940, lifted_632940);

