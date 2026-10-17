// batch216032.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_43de70_thiscall1(u32) __asm__("ext_43de70");
extern "C" u32 THISCALL ext_43e0f0_thiscall1(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_49d6c0_thiscall1(u32) __asm__("ext_49d6c0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d1390_thiscall3(u32, u32, u32) __asm__("ext_4d1390");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_561020_thiscall1(u32) __asm__("ext_561020");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5ab970_thiscall1(u32) __asm__("ext_5ab970");
extern "C" u32 THISCALL ext_5aba60_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5aba60");
extern "C" u32 THISCALL ext_5ac5d0_thiscall2(u32, u32) __asm__("ext_5ac5d0");
extern "C" u32 THISCALL ext_5ac940_thiscall2(u32, u32) __asm__("ext_5ac940");
extern "C" u32 THISCALL ext_5f0630_thiscall1(u32) __asm__("ext_5f0630");
extern "C" u32 THISCALL ext_5f0700_thiscall2(u32, u32) __asm__("ext_5f0700");
extern "C" u32 THISCALL ext_5f0750_thiscall2(u32, u32) __asm__("ext_5f0750");
extern "C" u32 THISCALL ext_5f0880_thiscall3(u32, u32, u32) __asm__("ext_5f0880");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5d59a0(u32 ecx_in) {
  SEH_ENTER(0x66c8a2);  // @h_5d59a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_5d59a0
  eax = ext_43e0f0_thiscall1(ecx);  // @1_5d59a0
  ecx = edx = 0;  // @2_5d59a0
  eax = ext_41e290_cdecl1((u32)(144));  // @3_5d59a0
  ecx = edx = 0;  // @4_5d59a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_5d59a0
  reg.state = (s32)((u32)(0));  // @6_5d59a0
  if ((eax & eax) == 0) goto L5d59f1;  // @7_5d59a0
  ecx = eax;  // @8_5d59a0
  eax = ext_5f0630_thiscall1(ecx);  // @9_5d59a0
  ecx = edx = 0;  // @10_5d59a0
  goto L5d59f3;  // @11_5d59a0
  L5d59f1:;
  eax = 0;  // @13_5d59a0
  L5d59f3:;
  ecx = eax;  // @15_5d59a0
  reg.state = (s32)((u32)(4294967295));  // @16_5d59a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @17_5d59a0
  eax = ext_5f0880_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 29), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 33), sizeof v); (u32)v; }));  // @18_5d59a0
  ecx = edx = 0;  // @19_5d59a0
  edi = (u32)(32);  // @20_5d59a0
  L5d5a10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @22_5d59a0
  eax = ext_5f0700_thiscall2(ecx, (u32)(6781786));  // @23_5d59a0
  ecx = edx = 0;  // @24_5d59a0
  edi = (edi - (u32)(1));  // @25_5d59a0
  if (edi != 0) goto L5d5a10;  // @26_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @27_5d59a0
  PS[0] = edi;  // @28_5d59a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_5d59a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(7034916), (u32)(PS[0]));  // @30_5d59a0
  ecx = edx = 0;  // @31_5d59a0
  edi = eax;  // @32_5d59a0
  if ((s32)(edi & edi) <= 0) goto L5d5a6d;  // @33_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @34_5d59a0
  if ((ecx & ecx) == 0) goto L5d5a4b;  // @35_5d59a0
  PS[1] = ecx;  // @36_5d59a0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @37_5d59a0
  ecx = edx = 0;  // @38_5d59a0
  L5d5a4b:;
  PS[0] = edi;  // @40_5d59a0
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @41_5d59a0
  ecx = edx = 0;  // @42_5d59a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @43_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @44_5d59a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_5d59a0
  PS[2] = edi;  // @46_5d59a0
  PS[3] = eax;  // @47_5d59a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 96)))(ecx, (u32)(7034916), (u32)(PS[3]), (u32)(PS[2]), (u32)(0), (u32)(0));  // @48_5d59a0
  ecx = edx = 0;  // @49_5d59a0
  L5d5a6d:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @51_5d59a0
  edx = 0;  // @52_5d59a0
  ecx = (u32)(ebx + 1);  // @53_5d59a0
  L5d5a75:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) & 0xff);  // @55_5d59a0
  ebx = (ebx + 1);  // @56_5d59a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5d5a75;  // @57_5d59a0
  ebx = (ebx - ecx);  // @58_5d59a0
  edi = edx;  // @59_5d59a0
  if ((s32)ebx < 0) goto L5d5ab9;  // @60_5d59a0
  L5d5a82:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @62_5d59a0
  ecx = (u32)(eax + edi);  // @63_5d59a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @64_5d59a0
  if ((eax & 0xff) == (u32)(10)) goto L5d5a92;  // @65_5d59a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5d5ab4;  // @66_5d59a0
  L5d5a92:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @68_5d59a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 41), sizeof v); (u32)v; });  // @69_5d59a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @70_5d59a0
  eax = (eax + edx);  // @71_5d59a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(32)) goto L5d5aab;  // @72_5d59a0
  eax = (eax + 1);  // @73_5d59a0
  PS[0] = eax;  // @74_5d59a0
  eax = ext_5f0700_thiscall2(ecx, (u32)(PS[0]));  // @75_5d59a0
  ecx = edx = 0;  // @76_5d59a0
  goto L5d5ab1;  // @77_5d59a0
  L5d5aab:;
  PS[0] = eax;  // @79_5d59a0
  eax = ext_5f0750_thiscall2(ecx, (u32)(PS[0]));  // @80_5d59a0
  ecx = edx = 0;  // @81_5d59a0
  L5d5ab1:;
  edx = (u32)(edi + 1);  // @83_5d59a0
  L5d5ab4:;
  edi = (edi + 1);  // @85_5d59a0
  if ((s32)edi <= (s32)ebx) goto L5d5a82;  // @86_5d59a0
  L5d5ab9:;
  SEH_LEAVE();  // @88_5d59a0
  return eax;  // @89_5d59a0
}
PCREG(5d59a0, lifted_5d59a0);

extern "C" u32 THISCALL lifted_4b1930(u32 ecx_in) {
  SEH_ENTER(0x668b96);  // @h_4b1930
  u8 L90[0x80] __attribute__((aligned(16)));
  volatile u32 w94 = 0;
  u32 ebx = ecx_in;
  u32 eng = G(u32, 0x70039c);
  u32 tbl = *(u32 *)(eng + 155);
  u32 x = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)tbl + 88)))(tbl, *(u32 *)(ebx + 218));  // @h1_4b1930
  u32 eax;
  u32 tag = 0;
  if (x == 0) tag = 1;  // @h2_4b1930
  u32 y = 0;
  if (!tag) {
    y = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)x + 256)))(x, 6886756);  // @h3_4b1930
    if (y == 0) tag = 2;  // @h4_4b1930
  }
  if (tag) {
    u32 lg = G(u32, 0x700390);
    u32 line = tag == 1 ? 3865 : 3876;
    u32 edi = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(*(u32 *)lg + 32)))(lg, 6889180, line);  // @h5_4b1930
    u32 m = *(u32 *)(ebx + 68);
    u32 sv = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(*(u32 *)m + 472)))(m, (u32)(u8 *)L90, 1);  // @h6_4b1930
    reg.state = tag == 1 ? 0 : 1;  // @h7_4b1930
    u32 str = ext_4cc1d0_thiscall1(sv);
    ((u32(*)(u32, u32, u32))(*(u32 *)(*(u32 *)edi + 44)))(edi, tag == 1 ? 6891256 : 6891328, str);  // @h8_4b1930
    reg.state = -1;
    ext_4cbec0_thiscall1((u32)(u8 *)L90);
    eax = ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)ebx + 88)))(ebx);  // @h9_4b1930
  } else {
    if ((s32)*(u32 *)(ebx + 72) >= 0)  // @h10_4b1930
      ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)y + 132)))(y, ebx);  // @h11_4b1930
    u32 eng2 = G(u32, 0x70039c);
    u32 tbl2 = *(u32 *)(eng2 + 155);
    u32 e = ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)tbl2 + 312)))(tbl2);  // @h12_4b1930
    w94 = 0;
    ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(*(u32 *)e + 136)))(e, 6889580, (u32)(u32 *)&w94);  // @h13_4b1930
    u32 eng3 = G(u32, 0x70039c);
    u32 tbl3 = *(u32 *)(eng3 + 155);
    eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)tbl3 + 88)))(tbl3, w94);  // @h14_4b1930
    *(u32 *)(ebx + 76) = eax;  // @h15_4b1930
  }
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(4b1930, lifted_4b1930);

extern "C" u32 THISCALL lifted_578560(u32 ecx_in) {
  SEH_ENTER(0x66b15e);  // @h_578560
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_578560
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_578560
  eax = ext_561020_thiscall1(ecx);  // @2_578560
  ecx = edx = 0;  // @3_578560
  { u32 v = (u32)((u32)(6986028)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @6_578560
  reg.state = (s32)((u32)(0));  // @7_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_578560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6986320), (u32)(0), (u32)(6986276), (u32)(18));  // @9_578560
  ecx = edx = 0;  // @10_578560
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 408), &v, sizeof v); }  // @11_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_578560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6986340), (u32)(0), (u32)(6986276), (u32)(19));  // @15_578560
  ecx = edx = 0;  // @16_578560
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 410), &v, sizeof v); }  // @17_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @18_578560
  ecx = edx = 0;  // @19_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @20_578560
  reg.state = (s32)((u32)(1));  // @21_578560
  if ((eax & eax) == 0) goto L578621;  // @22_578560
  ecx = (u32)(esi + 424);  // @23_578560
  PS[0] = ecx;  // @24_578560
  ecx = eax;  // @25_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986364), (u32)(6975376), (u32)(PS[0]));  // @26_578560
  ecx = edx = 0;  // @27_578560
  edx = eax;  // @28_578560
  goto L578623;  // @29_578560
  L578621:;
  edx = 0;  // @31_578560
  L578623:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 412), &v, sizeof v); }  // @33_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_578560
  PS[0] = edx;  // @35_578560
  reg.state = (s32)((u32)(0));  // @36_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @38_578560
  ecx = edx = 0;  // @39_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @40_578560
  ecx = edx = 0;  // @41_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @42_578560
  reg.state = (s32)((u32)(2));  // @43_578560
  if ((eax & eax) == 0) goto L578670;  // @44_578560
  ecx = (u32)(esi + 428);  // @45_578560
  PS[0] = ecx;  // @46_578560
  ecx = eax;  // @47_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986372), (u32)(6975376), (u32)(PS[0]));  // @48_578560
  ecx = edx = 0;  // @49_578560
  edx = eax;  // @50_578560
  goto L578672;  // @51_578560
  L578670:;
  edx = 0;  // @53_578560
  L578672:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 416), &v, sizeof v); }  // @55_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_578560
  PS[0] = edx;  // @57_578560
  reg.state = (s32)((u32)(0));  // @58_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @60_578560
  ecx = edx = 0;  // @61_578560
  eax = ext_41e290_cdecl1((u32)(264));  // @62_578560
  ecx = edx = 0;  // @63_578560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @64_578560
  reg.state = (s32)((u32)(3));  // @65_578560
  if ((eax & eax) == 0) goto L5786bf;  // @66_578560
  ecx = (u32)(esi + 432);  // @67_578560
  PS[0] = ecx;  // @68_578560
  ecx = eax;  // @69_578560
  eax = ext_4d8330_thiscall4(ecx, (u32)(6986380), (u32)(6975376), (u32)(PS[0]));  // @70_578560
  ecx = edx = 0;  // @71_578560
  edx = eax;  // @72_578560
  goto L5786c1;  // @73_578560
  L5786bf:;
  edx = 0;  // @75_578560
  L5786c1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 420), &v, sizeof v); }  // @77_578560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_578560
  PS[0] = edx;  // @79_578560
  reg.state = (s32)((u32)(0));  // @80_578560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_578560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @82_578560
  ecx = edx = 0;  // @83_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 424), &v, sizeof v); }  // @84_578560
  eax = esi;  // @85_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 428), &v, sizeof v); }  // @86_578560
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 432), &v, sizeof v); }  // @87_578560
  SEH_LEAVE();  // @88_578560
  return eax;  // @89_578560
}
PCREG(578560, lifted_578560);

extern "C" u32 THISCALL lifted_435040(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_435040
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_435040
  ecx = (u32)(EBP - 144);  // @2_435040
  PS[0] = eax;  // @3_435040
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @4_435040
  ecx = edx = 0;  // @5_435040
  ecx = (u32)(EBP - 144);  // @6_435040
  reg.state = (s32)((u32)(0));  // @7_435040
  eax = ext_4cc5f0_thiscall1(ecx);  // @8_435040
  ecx = edx = 0;  // @9_435040
  ebx = eax;  // @10_435040
  esi = 0;  // @11_435040
  if ((ebx & ebx) == 0) goto L4350c5;  // @12_435040
  L4350a0:;
  ecx = (u32)(EBP - 144);  // @14_435040
  eax = ext_4cc1d0_thiscall1(ecx);  // @15_435040
  ecx = edx = 0;  // @16_435040
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(92)) goto L4350c0;  // @17_435040
  ecx = (u32)(EBP - 144);  // @18_435040
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_435040
  ecx = edx = 0;  // @20_435040
  { u8 v = (u8)((u32)(47)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @21_435040
  L4350c0:;
  esi = (esi + 1);  // @23_435040
  if (esi != ebx) goto L4350a0;  // @24_435040
  L4350c5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @26_435040
  if ((ecx & ecx) == 0) goto L435122;  // @27_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_435040
  edx = (u32)(EBP - 156);  // @29_435040
  PS[0] = edx;  // @30_435040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @31_435040
  ecx = edx = 0;  // @32_435040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @33_435040
  edx = (u32)(EBP - 156);  // @34_435040
  PS[0] = edx;  // @35_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_435040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @37_435040
  ecx = edx = 0;  // @38_435040
  esi = eax;  // @39_435040
  if ((esi & esi) == 0) goto L435122;  // @40_435040
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775828), sizeof v); (u32)v; });  // @41_435040
  L4350f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_435040
  PS[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 13), sizeof v); (u32)v; });
  ecx = (u32)(EBP - 144);  // @44_435040
  eax = ext_4cc1d0_thiscall1(ecx);  // @45_435040
  ecx = edx = 0;  // @46_435040
  PS[0] = eax;  // @47_435040
  eax = ((u32(*)(u32, u32))(ebx))((u32)(PS[0]), (u32)(PS[1]));  // @48_435040
  ecx = edx = 0;  // @49_435040
  if ((eax & eax) == 0) goto L43514f;  // @50_435040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @51_435040
  edx = (u32)(EBP - 156);  // @52_435040
  PS[0] = edx;  // @53_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_435040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @55_435040
  ecx = edx = 0;  // @56_435040
  esi = eax;  // @57_435040
  if ((esi & esi) != 0) goto L4350f3;  // @58_435040
  L435122:;
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @60_435040
  L435124:;
  ecx = (u32)(EBP - 144);  // @62_435040
  eax = ext_4cbec0_thiscall1(ecx);  // @63_435040
  ecx = edx = 0;  // @64_435040
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @65_435040
  SEH_LEAVE();  // @66_435040
  ext_633654(G(u32, 0x6f5630));  // @67_435040
  return eax;  // @68_435040
  L43514f:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_435040
  ecx = esi;  // @71_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @72_435040
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 56)))(ecx);  // @73_435040
  ecx = edx = 0;  // @74_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_435040
  ecx = esi;  // @76_435040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(1));  // @77_435040
  ecx = edx = 0;  // @78_435040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @79_435040
  edx = (u32)(EBP - 156);  // @80_435040
  PS[0] = edx;  // @81_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_435040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(PS[0]));  // @83_435040
  ecx = edx = 0;  // @84_435040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @85_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_435040
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @87_435040
  ecx = edx = 0;  // @88_435040
  if ((eax & eax) != 0) goto L435190;  // @89_435040
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @90_435040
  if ((ecx & ecx) == 0) goto L435189;  // @91_435040
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_435040
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @93_435040
  ecx = edx = 0;  // @94_435040
  L435189:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @96_435040
  L435190:;
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @98_435040
  goto L435124;  // @99_435040
}
PCREG(435040, lifted_435040);

#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 THISCALL lifted_5ee590(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  SEH_ENTER(0x66cbc4);  // @h_5ee590
  u32 edi = ecx_in, ebx = a3, eax;
  volatile u32 slot10 = a2;
  u32 m = *(u32 *)(edi + 0x15);
  ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))VSLOT(m, 0x14))(m, a2, 0, 0, 0, 0);  // @h1_5ee590
  if (ebx != 0) {  // @h2_5ee590
    do {
      u32 node = ext_41e290_cdecl1((u32)8);  // @h3_5ee590
      u32 obj = ext_41e290_cdecl1((u32)0xa8);  // @h4_5ee590
      slot10 = node;
      reg.state = 0;
      u32 o;
      if (obj) o = ext_5ab2e0_thiscall2(obj, *(u32 *)(edi + 0x80));  // @h5_5ee590
      else o = 0;
      reg.state = -1;
      *(u32 *)node = o;
      ext_5aba60_thiscall5(o, a0, a1, a4, 0);  // @h6_5ee590
      ext_5ac5d0_thiscall2(*(u32 *)node, (u32)-1);  // @h7_5ee590
      *(u32 *)(node + 4) = (u32)-1;
      u32 cur = *(u32 *)(edi + 9);
      if (cur == *(u32 *)(edi + 0xd)) {  // @h8_5ee590
        ext_5fe3b0_thiscall3(edi + 5, cur, (u32)(u32 *)&slot10);  // @h9_5ee590
      } else {
        if (cur) *(u32 *)cur = node;  // @h10_5ee590
        *(u32 *)(edi + 9) += 4;  // @h11_5ee590
      }
      ebx--;
    } while (ebx != 0);  // @h12_5ee590
  }
  u32 obj2 = ext_41e290_cdecl1((u32)0xa8);  // @h13_5ee590
  reg.state = 1;
  u32 esi;
  if (obj2) esi = ext_5ab2e0_thiscall2(obj2, 1);  // @h14_5ee590
  else esi = 0;
  reg.state = -1;
  ext_5aba60_thiscall5(esi, a0, a1, 0, 0);  // @h15_5ee590
  ext_5ac940_thiscall2(esi, 0x6b817c);  // @h16_5ee590
  eax = ext_5ab970_thiscall1(esi);  // @h17_5ee590
  *(u32 *)(edi + 0x6b) = eax;  // @h18_5ee590
  if (esi) eax = ((u32(THISCALL *)(u32, u32))VSLOT(esi, 0))(esi, 1);  // @h19_5ee590
  SEH_LEAVE();
  return eax;
}
PCREG(5ee590, lifted_5ee590);

extern "C" u32 THISCALL lifted_44a3d0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66612e);  // @h_44a3d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44a3d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44a3d0
  PS[0] = esi;  // @2_44a3d0
  eax = ext_45f3c0_thiscall2(ecx, (u32)(PS[0]));  // @3_44a3d0
  ecx = edx = 0;  // @4_44a3d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L44a419;  // @5_44a3d0
  SEH_LEAVE();  // @6_44a3d0
  return eax;  // @7_44a3d0
  L44a419:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @9_44a3d0
  if ((ecx & ecx) == 0) goto L44a42d;  // @10_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @12_44a3d0
  ecx = edx = 0;  // @13_44a3d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @14_44a3d0
  L44a42d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @16_44a3d0
  if ((ecx & ecx) == 0) goto L44a441;  // @17_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @19_44a3d0
  ecx = edx = 0;  // @20_44a3d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @21_44a3d0
  L44a441:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_44a3d0
  ecx = (u32)(EBP + 8);  // @24_44a3d0
  PS[0] = ecx;  // @25_44a3d0
  ecx = esi;  // @26_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(PS[0]));  // @27_44a3d0
  ecx = edx = 0;  // @28_44a3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L44a4ab;  // @29_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_44a3d0
  ecx = (u32)(EBP - 20);  // @31_44a3d0
  PS[1] = ecx;  // @32_44a3d0
  ecx = esi;  // @33_44a3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @34_44a3d0
  ecx = edx = 0;  // @35_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_44a3d0
  ecx = (u32)(EBP - 16);  // @37_44a3d0
  PS[1] = ecx;  // @38_44a3d0
  ecx = esi;  // @39_44a3d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(PS[1]), (u32)(4));  // @40_44a3d0
  ecx = edx = 0;  // @41_44a3d0
  eax = ext_41e290_cdecl1((u32)(28));  // @42_44a3d0
  ecx = edx = 0;  // @43_44a3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @44_44a3d0
  reg.state = (s32)((u32)(0));  // @45_44a3d0
  if ((eax & eax) == 0) goto L44a497;  // @46_44a3d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @47_44a3d0
  ecx = (ecx - 1);  // @48_44a3d0
  PS[0] = ecx;  // @49_44a3d0
  ecx = eax;  // @50_44a3d0
  eax = ext_4ccbe0_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }), (u32)(PS[0]));  // @51_44a3d0
  ecx = edx = 0;  // @52_44a3d0
  ecx = eax;  // @53_44a3d0
  goto L44a499;  // @54_44a3d0
  L44a497:;
  ecx = 0;  // @56_44a3d0
  L44a499:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @58_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_44a3d0
  PS[0] = ecx;  // @60_44a3d0
  ecx = esi;  // @61_44a3d0
  reg.state = (s32)((u32)(4294967295));  // @62_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(PS[0]));  // @63_44a3d0
  ecx = edx = 0;  // @64_44a3d0
  L44a4ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_44a3d0
  ecx = (u32)(EBP + 8);  // @67_44a3d0
  PS[0] = ecx;  // @68_44a3d0
  ecx = esi;  // @69_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(PS[0]));  // @70_44a3d0
  ecx = edx = 0;  // @71_44a3d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L44a4f7;  // @72_44a3d0
  eax = ext_41e290_cdecl1((u32)(28));  // @73_44a3d0
  ecx = edx = 0;  // @74_44a3d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @75_44a3d0
  reg.state = (s32)((u32)(1));  // @76_44a3d0
  if ((eax & eax) == 0) goto L44a4e3;  // @77_44a3d0
  ecx = eax;  // @78_44a3d0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(1));  // @79_44a3d0
  ecx = edx = 0;  // @80_44a3d0
  ecx = eax;  // @81_44a3d0
  goto L44a4e5;  // @82_44a3d0
  L44a4e3:;
  ecx = 0;  // @84_44a3d0
  L44a4e5:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @86_44a3d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @87_44a3d0
  PS[0] = ecx;  // @88_44a3d0
  ecx = esi;  // @89_44a3d0
  reg.state = (s32)((u32)(4294967295));  // @90_44a3d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(PS[0]));  // @91_44a3d0
  ecx = edx = 0;  // @92_44a3d0
  L44a4f7:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @94_44a3d0
  SEH_LEAVE();  // @95_44a3d0
  return eax;  // @96_44a3d0
}
PCREG(44a3d0, lifted_44a3d0);

#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 THISCALL lifted_49d2f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66583b);  // @h_49d2f0
  u8 loc[0x80] __attribute__((aligned(16)));
  u32 esi = ecx_in, ebx = a0;
  u32 cnt = *(u32 *)(esi + 0x14);
  u32 eax = cnt;
  bool skip_to_store = false;
  if (!(*(u32 *)(esi + 0x20) > cnt)) {  // @h1_49d2f0
    if (*(u8 *)(esi + 0x28) != 0) {  // @h2_49d2f0
      u32 i = 0;
      if (cnt != 0) {  // @h3_49d2f0
        do {
          u32 mgr = G(u32, 0x70038c);
          u32 obj = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 0xcc))(mgr, *(u32 *)(*(u32 *)(esi + 8) + i * 4));  // @h4_49d2f0
          u32 lg = G(u32, 0x700390);
          u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x68eea0, 0x5e);  // @h5_49d2f0
          u32 m30 = *(u32 *)(obj + 0x30);
          u32 sv = ((u32(THISCALL *)(u32, u32, u32))VSLOT(m30, 0x1d8))(m30, (u32)(u8 *)loc, 1);  // @h6_49d2f0
          reg.state = 0;
          u32 str = ext_4cc1d0_thiscall1(sv);
          u32 n = ((u32(THISCALL *)(u32))VSLOT(obj, 0x14))(obj);  // @h7_49d2f0
          ((u32(*)(u32, u32, u32, u32))VSLOT(L, 0x2c))(L, 0x68eecc, n, str);  // @h8_49d2f0
          reg.state = -1;
          eax = ext_4cbec0_thiscall1((u32)(u8 *)loc);
          i++;
        } while (i < *(u32 *)(esi + 0x14));  // @h9_49d2f0
      }
      if (*(u8 *)(esi + 0x28) != 0) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return eax; }  // @h10_49d2f0
    }
    eax = ext_49d6c0_thiscall1(esi);  // @h11_49d2f0
  }
  eax = *(u32 *)(esi + 0x14);
  if (eax >= *(u32 *)(esi + 0x20)) { SEH_LEAVE(); ext_633654(G(u32, 0x6f5630)); return eax; }  // @h12_49d2f0
  u32 edx;
  if (ebx == 0) edx = 0;  // @h13_49d2f0
  else {
    u32 mgr = G(u32, 0x70038c);
    u32 r = ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 0x20))(mgr, ebx);  // @h14_49d2f0
    if (r != 0) edx = 0;  // @h15_49d2f0
    else {
      mgr = G(u32, 0x70038c);
      u32 fn = *(u32 *)(mgr + 8);
      if (fn && !(*(u32 *)(mgr + 0xc) > ebx) && ebx < *(u32 *)(mgr + 0x10))  // @h16_49d2f0
        edx = ((u32(THISCALL *)(u32))fn)(ebx);  // @h17_49d2f0
      else {
        if (*(u32 *)(ebx - 4) == 0)  // @h18_49d2f0
          ((u32(THISCALL *)(u32, u32))VSLOT(mgr, 0xac))(mgr, ebx);  // @h19_49d2f0
        edx = *(u32 *)(ebx - 4);
      }
    }
  }
  u32 c2 = *(u32 *)(esi + 0x14);
  eax = *(u32 *)(esi + 8);
  *(u32 *)(eax + c2 * 4) = edx;  // @h20_49d2f0
  *(u32 *)(esi + 0x14) += 1;  // @h21_49d2f0
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(49d2f0, lifted_49d2f0);

#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 THISCALL ext_5fb980_m3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_602290_m5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_5f10c0_m2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fb110_m2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 STDCALL ext_54f870_m2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL lifted_602a60(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  SEH_ENTER(0x66dbac);  // @h_602a60
  volatile u32 A0 = a0;
  volatile u32 tmp10 = 0;
  u32 self = ecx_in, ebx = self + 1, eax;
  reg.state = 0;
  ext_5fb980_m3(ebx, (u32)(u32 *)&tmp10, (u32)(u32 *)&A0);  // @h1_602a60
  if (tmp10 == *(u32 *)ebx) {  // @h2_602a60
    u32 esi = a3, edi = 0;
    if (esi) {  // @h3_602a60
      u32 obj = ext_41e290_cdecl1((u32)0x30);  // @h4_602a60
      reg.state = 1;
      if (obj) edi = ext_602290_m5(obj, 0, esi, 0, 0);  // @h5_602a60
      else edi = 0;
      reg.state = 0;
    }
    u32 node = ext_41e290_cdecl1((u32)0x28);  // @h6_602a60
    reg.state = 2;
    if (node) {  // @h7_602a60
      *(u32 *)node = 0x6b98c4;
      ext_5f10c0_m2(node + 4, (u32)(u32 *)&A0);  // @h8_602a60
      *(u32 *)(node + 0x14) = a7;  // @h9_602a60
      *(u32 *)(node + 0x18) = a4;  // @h10_602a60
      *(u32 *)(node + 0x1c) = a6;  // @h11_602a60
      *(u32 *)(node + 0x10) = 5;
      *(u32 *)(node + 0x20) = a5;  // @h12_602a60
      *(u32 *)(node + 0x24) = edi;  // @h13_602a60
      esi = node;
    } else esi = 0;
    reg.state = 0;
    u32 pp = ext_5fb110_m2(ebx, (u32)(u32 *)&A0);  // @h14_602a60
    *(u32 *)pp = esi;  // @h15_602a60
    *(u8 *)self = 0;  // @h16_602a60
  } else {
    u32 lg = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x6b98c8, 0x4c);  // @h17_602a60
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x69c6b0, 0x6b9950);  // @h18_602a60
    u32 h = G(u32, 0x7003b0);
    if (h) ((u32(*)())h)(); else __builtin_trap();
  }
  u32 ecx = A0;
  eax = a2 - ecx;
  reg.state = 3;
  if (ecx && eax) eax = ext_54f870_m2(ecx, eax);  // @h19_602a60
  SEH_LEAVE();
  return eax;
}
PCREG(602a60, lifted_602a60);

extern "C" u32 THISCALL lifted_4d1830(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66934e);  // @h_4d1830
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4d1830
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4d1830
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4d1830
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; });  // @3_4d1830
  if ((ebx & ebx) == 0) goto L4d1966;  // @4_4d1830
  L4d1870:;
  eax = ext_41e290_cdecl1((u32)(56));  // @6_4d1830
  ecx = edx = 0;  // @7_4d1830
  edi = eax;  // @8_4d1830
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @9_4d1830
  reg.state = (s32)((u32)(0));  // @10_4d1830
  if ((edi & edi) == 0) goto L4d1954;  // @11_4d1830
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @12_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @13_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @14_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @15_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @16_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @17_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @18_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @19_4d1830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @20_4d1830
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @21_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @22_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @23_4d1830
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @24_4d1830
  if ((esi & esi) == 0) goto L4d1904;  // @25_4d1830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @26_4d1830
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @27_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @28_4d1830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @29_4d1830
  if ((eax & eax) == 0) goto L4d18fc;  // @30_4d1830
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax + 48), &v, sizeof v); }  // @31_4d1830
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @32_4d1830
  goto L4d1912;  // @33_4d1830
  L4d18fc:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @35_4d1830
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @36_4d1830
  goto L4d1912;  // @37_4d1830
  L4d1904:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @39_4d1830
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @40_4d1830
  L4d1912:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; });  // @42_4d1830
  if ((esi & esi) == 0) goto L4d1949;  // @43_4d1830
  L4d1920:;
  eax = ext_41e290_cdecl1((u32)(56));  // @45_4d1830
  ecx = edx = 0;  // @46_4d1830
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @47_4d1830
  reg.state = (s32)((u32)(1));  // @48_4d1830
  if ((eax & eax) == 0) goto L4d193e;  // @49_4d1830
  PS[0] = edi;  // @50_4d1830
  PS[1] = esi;  // @51_4d1830
  ecx = eax;  // @52_4d1830
  eax = ext_4d1390_thiscall3(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @53_4d1830
  ecx = edx = 0;  // @54_4d1830
  L4d193e:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @56_4d1830
  reg.state = (s32)((u32)(0));  // @57_4d1830
  if ((esi & esi) != 0) goto L4d1920;  // @58_4d1830
  L4d1949:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_4d1830
  ecx = ebx;  // @61_4d1830
  PS[0] = edi;  // @62_4d1830
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @63_4d1830
  ecx = edx = 0;  // @64_4d1830
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @65_4d1830
  L4d1954:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; });  // @67_4d1830
  reg.state = (s32)((u32)(4294967295));  // @68_4d1830
  if ((ebx & ebx) != 0) goto L4d1870;  // @69_4d1830
  L4d1966:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @71_4d1830
  ecx = ebx;  // @72_4d1830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @73_4d1830
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @74_4d1830
  ecx = edx = 0;  // @75_4d1830
  edi = 0;  // @76_4d1830
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @77_4d1830
  if ((eax & eax) == 0) goto L4d19a3;  // @78_4d1830
  L4d1980:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @80_4d1830
  ecx = ebx;  // @81_4d1830
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_4d1830
  PS[0] = edi;  // @83_4d1830
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @84_4d1830
  ecx = edx = 0;  // @85_4d1830
  PS[0] = eax;  // @86_4d1830
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_4d1830
  ecx = ebx;  // @88_4d1830
  PS[1] = edi;  // @89_4d1830
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @90_4d1830
  ecx = edx = 0;  // @91_4d1830
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @92_4d1830
  PS[0] = eax;  // @93_4d1830
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 28)))(ecx, (u32)(PS[0]));  // @94_4d1830
  ecx = edx = 0;  // @95_4d1830
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @96_4d1830
  edi = (edi + 1);  // @97_4d1830
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L4d1980;  // @98_4d1830
  L4d19a3:;
  SEH_LEAVE();  // @100_4d1830
  return eax;  // @101_4d1830
}
PCREG(4d1830, lifted_4d1830);

extern "C" u32 THISCALL lifted_4c6410(u32 ecx_in) {
  SEH_ENTER(0x668f90);  // @h_4c6410
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_4c6410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4c6410
  eax = ext_469870_thiscall1(ecx);  // @2_4c6410
  ecx = edx = 0;  // @3_4c6410
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4c6410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4c6410
  ebx = (u32)(esi + 88);  // @6_4c6410
  reg.state = (s32)((u32)(0));  // @7_4c6410
  edi = (u32)(esi + 93);  // @8_4c6410
  { u32 v = (u32)((u32)(6900120)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_4c6410
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @10_4c6410
  { u32 v = (u32)((u32)(1148846080)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @11_4c6410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @12_4c6410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @13_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @14_4c6410
  ecx = edx = 0;  // @15_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @16_4c6410
  reg.state = (s32)((u32)(1));  // @17_4c6410
  if ((eax & eax) == 0) goto L4c649f;  // @18_4c6410
  PS[0] = edi;  // @19_4c6410
  ecx = eax;  // @20_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900288), (u32)(6900252), (u32)(PS[0]));  // @21_4c6410
  ecx = edx = 0;  // @22_4c6410
  edx = eax;  // @23_4c6410
  goto L4c64a1;  // @24_4c6410
  L4c649f:;
  edx = 0;  // @26_4c6410
  L4c64a1:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @28_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4c6410
  PS[0] = edx;  // @30_4c6410
  reg.state = (s32)((u32)(0));  // @31_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @33_4c6410
  ecx = edx = 0;  // @34_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @35_4c6410
  ecx = edx = 0;  // @36_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @37_4c6410
  reg.state = (s32)((u32)(2));  // @38_4c6410
  if ((eax & eax) == 0) goto L4c64e5;  // @39_4c6410
  PS[0] = edi;  // @40_4c6410
  ecx = eax;  // @41_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900344), (u32)(6900312), (u32)(PS[0]));  // @42_4c6410
  ecx = edx = 0;  // @43_4c6410
  edx = eax;  // @44_4c6410
  goto L4c64e7;  // @45_4c6410
  L4c64e5:;
  edx = 0;  // @47_4c6410
  L4c64e7:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @49_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_4c6410
  PS[0] = edx;  // @51_4c6410
  reg.state = (s32)((u32)(0));  // @52_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @54_4c6410
  ecx = edx = 0;  // @55_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @56_4c6410
  ecx = edx = 0;  // @57_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @58_4c6410
  reg.state = (s32)((u32)(3));  // @59_4c6410
  if ((eax & eax) == 0) goto L4c652b;  // @60_4c6410
  PS[0] = ebx;  // @61_4c6410
  ecx = eax;  // @62_4c6410
  eax = ext_4d83b0_thiscall4(ecx, (u32)(6900392), (u32)(6900368), (u32)(PS[0]));  // @63_4c6410
  ecx = edx = 0;  // @64_4c6410
  edx = eax;  // @65_4c6410
  goto L4c652d;  // @66_4c6410
  L4c652b:;
  edx = 0;  // @68_4c6410
  L4c652d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @70_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_4c6410
  PS[0] = edx;  // @72_4c6410
  reg.state = (s32)((u32)(0));  // @73_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @75_4c6410
  ecx = edx = 0;  // @76_4c6410
  eax = ext_41e290_cdecl1((u32)(264));  // @77_4c6410
  ecx = edx = 0;  // @78_4c6410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @79_4c6410
  reg.state = (s32)((u32)(4));  // @80_4c6410
  if ((eax & eax) == 0) goto L4c6574;  // @81_4c6410
  ecx = (u32)(esi + 89);  // @82_4c6410
  PS[0] = ecx;  // @83_4c6410
  ecx = eax;  // @84_4c6410
  eax = ext_4d8330_thiscall4(ecx, (u32)(6900424), (u32)(6900408), (u32)(PS[0]));  // @85_4c6410
  ecx = edx = 0;  // @86_4c6410
  edx = eax;  // @87_4c6410
  goto L4c6576;  // @88_4c6410
  L4c6574:;
  edx = 0;  // @90_4c6410
  L4c6576:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @92_4c6410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_4c6410
  PS[0] = edx;  // @94_4c6410
  reg.state = (s32)((u32)(0));  // @95_4c6410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_4c6410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(PS[0]));  // @97_4c6410
  ecx = edx = 0;  // @98_4c6410
  eax = esi;  // @99_4c6410
  SEH_LEAVE();  // @100_4c6410
  return eax;  // @101_4c6410
}
PCREG(4c6410, lifted_4c6410);

extern "C" u32 THISCALL lifted_5a54b0(u32 ecx_in) {
  SEH_ENTER(0x66bfa2);  // @h_5a54b0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  edi = ecx;  // @0_5a54b0
  { u32 v = (u32)((u32)(7008876)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1_5a54b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5a54b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5a54b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1620), sizeof v); (u32)v; }));  // @4_5a54b0
  ecx = edx = 0;  // @5_5a54b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1620), sizeof v); (u32)v; });  // @6_5a54b0
  if ((ecx & ecx) == 0) goto L5a5501;  // @7_5a54b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5a54b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @9_5a54b0
  ecx = edx = 0;  // @10_5a54b0
  L5a5501:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1625), sizeof v); (u32)v; });  // @12_5a54b0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1629), sizeof v); (u32)v; })) goto L5a5527;  // @13_5a54b0
  L5a5510:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5a54b0
  if ((ecx & ecx) == 0) goto L5a551c;  // @16_5a54b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5a54b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @18_5a54b0
  ecx = edx = 0;  // @19_5a54b0
  L5a551c:;
  esi = (esi + (u32)(4));  // @21_5a54b0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1629), sizeof v); (u32)v; })) goto L5a5510;  // @22_5a54b0
  L5a5527:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1637), sizeof v); (u32)v; });  // @24_5a54b0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1641), sizeof v); (u32)v; })) goto L5a554c;  // @25_5a54b0
  L5a5535:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_5a54b0
  if ((ecx & ecx) == 0) goto L5a5541;  // @28_5a54b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_5a54b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @30_5a54b0
  ecx = edx = 0;  // @31_5a54b0
  L5a5541:;
  esi = (esi + (u32)(4));  // @33_5a54b0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1641), sizeof v); (u32)v; })) goto L5a5535;  // @34_5a54b0
  L5a554c:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1649), sizeof v); (u32)v; });  // @36_5a54b0
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1653), sizeof v); (u32)v; })) goto L5a5577;  // @37_5a54b0
  L5a5560:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_5a54b0
  if ((ecx & ecx) == 0) goto L5a556c;  // @40_5a54b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_5a54b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @42_5a54b0
  ecx = edx = 0;  // @43_5a54b0
  L5a556c:;
  esi = (esi + (u32)(4));  // @45_5a54b0
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1653), sizeof v); (u32)v; })) goto L5a5560;  // @46_5a54b0
  L5a5577:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1657), sizeof v); (u32)v; });  // @48_5a54b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1649), sizeof v); (u32)v; });  // @49_5a54b0
  eax = (eax - ecx);  // @50_5a54b0
  eax = (u32)((s32)eax >> (u32)(2));  // @51_5a54b0
  reg.state = (s32)((u32)(0));  // @52_5a54b0
  if ((eax & eax) == 0) goto L5a55a3;  // @53_5a54b0
  eax = (eax << (u32)(2));  // @54_5a54b0
  PS[0] = eax;  // @55_5a54b0
  PS[1] = ecx;  // @56_5a54b0
  ecx = (u32)(edi + 1649);  // @57_5a54b0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @58_5a54b0
  ecx = edx = 0;  // @59_5a54b0
  L5a55a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1645), sizeof v); (u32)v; });  // @61_5a54b0
  ecx = (u32)(edi + 1637);  // @62_5a54b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_5a54b0
  eax = (eax - edx);  // @64_5a54b0
  eax = (u32)((s32)eax >> (u32)(2));  // @65_5a54b0
  reg.state = (s32)((u32)(1));  // @66_5a54b0
  if ((eax & eax) == 0) goto L5a55cb;  // @67_5a54b0
  eax = (eax << (u32)(2));  // @68_5a54b0
  PS[0] = eax;  // @69_5a54b0
  PS[1] = edx;  // @70_5a54b0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @71_5a54b0
  ecx = edx = 0;  // @72_5a54b0
  L5a55cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1633), sizeof v); (u32)v; });  // @74_5a54b0
  ecx = (u32)(edi + 1625);  // @75_5a54b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_5a54b0
  eax = (eax - edx);  // @77_5a54b0
  eax = (u32)((s32)eax >> (u32)(2));  // @78_5a54b0
  reg.state = (s32)((u32)(2));  // @79_5a54b0
  if ((eax & eax) == 0) goto L5a55f3;  // @80_5a54b0
  eax = (eax << (u32)(2));  // @81_5a54b0
  PS[0] = eax;  // @82_5a54b0
  PS[1] = edx;  // @83_5a54b0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @84_5a54b0
  ecx = edx = 0;  // @85_5a54b0
  L5a55f3:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1358), sizeof v); (u32)v; }), (u32)(4));  // @87_5a54b0
  ecx = edx = 0;  // @88_5a54b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1362), sizeof v); (u32)v; }), (u32)(4));  // @89_5a54b0
  ecx = edx = 0;  // @90_5a54b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1344), sizeof v); (u32)v; }), (u32)(4));  // @91_5a54b0
  ecx = edx = 0;  // @92_5a54b0
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1348), sizeof v); (u32)v; }), (u32)(4));  // @93_5a54b0
  ecx = edx = 0;  // @94_5a54b0
  ecx = edi;  // @95_5a54b0
  eax = ext_43de70_thiscall1(ecx);  // @96_5a54b0
  ecx = edx = 0;  // @97_5a54b0
  SEH_LEAVE();  // @98_5a54b0
  return eax;  // @99_5a54b0
}
PCREG(5a54b0, lifted_5a54b0);

#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 STDCALL lifted_50e150(u32 a0) {
  SEH_ENTER(0x669ef7);  // @h_50e150
  u8 s90[0x80] __attribute__((aligned(16)));
  u8 s110[0x80] __attribute__((aligned(16)));
  u32 ebx = a0, eax;
  u32 ob = *(u32 *)(ebx + 0xc);
  u32 edi = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ob, 0))(ob, 0x67a14c, 0);  // @h1_50e150
  ext_4cbeb0_thiscall1((u32)(u8 *)s110);
  reg.state = 0;
  u32 p = ext_5003d0_thiscall2(*(u32 *)(ebx + 4), 0);  // @h2_50e150
  u32 tb = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 x = ((u32(THISCALL *)(u32, u32))VSLOT(tb, 0x58))(tb, *(u32 *)p);  // @h3_50e150
  if (x == 0) {  // @h4_50e150
    ext_4cbe80_thiscall2((u32)(u8 *)s90, 0x69dc24);
    reg.state = 1;
    ext_4cbee0_thiscall2((u32)(u8 *)s110, (u32)(u8 *)s90);
    reg.state = 0;
    ext_4cbec0_thiscall1((u32)(u8 *)s90);
    u32 p2 = ext_5003d0_thiscall2(*(u32 *)(ebx + 4), 0);  // @h5_50e150
    u32 cs = ext_4cc1d0_thiscall1((u32)(u8 *)s110);
    ext_4cbe80_thiscall2((u32)(u8 *)s90, cs + *(u32 *)p2);  // @h6_50e150
    reg.state = 2;
    ext_4cbee0_thiscall2((u32)(u8 *)s110, (u32)(u8 *)s90);
    reg.state = 0;
    ext_4cbec0_thiscall1((u32)(u8 *)s90);
    ext_4cbe80_thiscall2((u32)(u8 *)s90, 0x69dc30);  // @h7_50e150
    reg.state = 3;
    ext_4cc2c0_thiscall2((u32)(u8 *)s110, (u32)(u8 *)s90);
  } else {
    u32 sv = ((u32(THISCALL *)(u32, u32, u32))VSLOT(x, 0x1d8))(x, (u32)(u8 *)s90, 1);  // @h8_50e150
    reg.state = 4;
    ext_4cbee0_thiscall2((u32)(u8 *)s110, sv);
  }
  reg.state = 0;
  ext_4cbec0_thiscall1((u32)(u8 *)s90);
  u32 str = ext_4cc1d0_thiscall1((u32)(u8 *)s110);
  ((u32(THISCALL *)(u32, u32))VSLOT(edi, 0x30))(edi, str);  // @h9_50e150
  u32 p3 = ext_5003d0_thiscall2(*(u32 *)(ebx + 8), 0);  // @h10_50e150
  u32 al = *(u8 *)(p3 + 4);
  bool doinit = true;
  if (al != 0) {  // @h11_50e150
    if (al != 4) doinit = false;  // @h12_50e150
    else { u32 c = *(u32 *)p3; ((u32(THISCALL *)(u32))VSLOT(c, 0x28))(c); }  // @h13_50e150
  }
  if (doinit) {
    eax = ((u32(THISCALL *)(u32))VSLOT(edi, 0x24))(edi);  // @h14_50e150
    *(u32 *)p3 = eax;  // @h15_50e150
    *(u8 *)(p3 + 4) = 4;  // @h16_50e150
  }
  eax = ((u32(THISCALL *)(u32))VSLOT(edi, 0x28))(edi);  // @h17_50e150
  eax = ext_4cbec0_thiscall1((u32)(u8 *)s110);
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return eax;
}
PCREG(50e150, lifted_50e150);

#ifndef VSLOT
#define VSLOT(obj, off) (*(u32 *)(*(u32 *)(obj) + (off)))
#endif
extern "C" u32 THISCALL lifted_471020(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669acb);  // @h_471020
  u8 loc[0x80] __attribute__((aligned(16)));
  volatile u32 it = 0;
  u32 ebx = ecx_in, esi = a0;
  u32 edi = *(u32 *)(ebx + 0x60);
  u32 tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  if (esi) {  // @h1_471020
    u32 x = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, esi);  // @h2_471020
    bool keep = false;
    if (x) {  // @h3_471020
      u32 al = ((u32(THISCALL *)(u32, u32))VSLOT(x, 0x1e0))(x, 0x1007d3) & 0xff;  // @h4_471020
      if (al) keep = true;  // @h5_471020
    }
    if (!keep) esi = 0;
  }
  tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 y = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, esi);  // @h6_471020
  if (y == 0) {  // @h7_471020
    u32 lg = G(u32, 0x700390);
    u32 L = ((u32(THISCALL *)(u32, u32, u32))VSLOT(lg, 0x20))(lg, 0x6887c4, 0x4c7);  // @h8_471020
    u32 sv = ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x1d8))(ebx, (u32)(u8 *)loc, 1);  // @h9_471020
    reg.state = 0;
    u32 str = ext_4cc1d0_thiscall1(sv);
    ((u32(*)(u32, u32, u32))VSLOT(L, 0x2c))(L, 0x6889dc, str);  // @h10_471020
    reg.state = -1;
    ext_4cbec0_thiscall1((u32)(u8 *)loc);
  }
  u32 c = *(u32 *)(ebx + 0x6c);
  if (c) {  // @h11_471020
    ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x4c))(c, (u32)(u32 *)&it);  // @h12_471020
    c = *(u32 *)(ebx + 0x6c);
    u32 n = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x5c))(c, (u32)(u32 *)&it);  // @h13_471020
    if (it != 0) {  // @h14_471020
      do {
        tbl = *(u32 *)(G(u32, 0x70039c) + 0x9b);
        u32 x2 = ((u32(THISCALL *)(u32, u32))VSLOT(tbl, 0x58))(tbl, n);  // @h15_471020
        if (x2) ((u32(THISCALL *)(u32, u32))VSLOT(x2, 0x210))(x2, 1);  // @h16_471020
        c = *(u32 *)(ebx + 0x6c);
        n = ((u32(THISCALL *)(u32, u32))VSLOT(c, 0x5c))(c, (u32)(u32 *)&it);  // @h17_471020
      } while (it != 0);  // @h18_471020
    }
  }
  c = *(u32 *)(ebx + 0x6c);
  ((u32(THISCALL *)(u32))VSLOT(c, 0xc))(c);  // @h19_471020
  *(u32 *)(ebx + 0x60) = esi;  // @h20_471020
  ((u32(THISCALL *)(u32, u32, u32))VSLOT(ebx, 0x2d0))(ebx, 0, 0);  // @h21_471020
  SEH_LEAVE();
  ext_633654(G(u32, 0x6f5630));
  return edi;
}
PCREG(471020, lifted_471020);

extern "C" u32 THISCALL lifted_4b8bf0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66bdd6);  // @h_4b8bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4b8bf0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4b8bf0
  ecx = edi;  // @2_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @4_4b8bf0
  ecx = edx = 0;  // @5_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @6_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_4b8bf0
  PS[0] = eax;  // @8_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @9_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @11_4b8bf0
  ecx = edx = 0;  // @12_4b8bf0
  if ((eax & eax) != 0) goto L4b8c93;  // @13_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(20));  // @16_4b8bf0
  ecx = edx = 0;  // @17_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @18_4b8bf0
  edi = eax;  // @19_4b8bf0
  eax = (u32)(EBP - 144);  // @20_4b8bf0
  PS[1] = eax;  // @21_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @23_4b8bf0
  ecx = edx = 0;  // @24_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_4b8bf0
  ecx = eax;  // @26_4b8bf0
  reg.state = (s32)((u32)(0));  // @27_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @28_4b8bf0
  ecx = edx = 0;  // @29_4b8bf0
  PS[0] = eax;  // @30_4b8bf0
  PS[2] = edi;  // @31_4b8bf0
  eax = ((u32(*)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6891904), (u32)(PS[0]));  // @32_4b8bf0
  ecx = edx = 0;  // @33_4b8bf0
  ecx = (u32)(EBP - 144);  // @34_4b8bf0
  goto L4b8d68;  // @35_4b8bf0
  L4b8c93:;
  ecx = edi;  // @37_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @38_4b8bf0
  ecx = edx = 0;  // @39_4b8bf0
  ecx = edi;  // @40_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 80), &v, sizeof v); }  // @41_4b8bf0
  eax = ext_4e5e60_thiscall1(ecx);  // @42_4b8bf0
  ecx = edx = 0;  // @43_4b8bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @44_4b8bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 88), &v, sizeof v); }  // @45_4b8bf0
  if ((esi & esi) == 0) goto L4b8d7e;  // @46_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_4b8bf0
  ecx = esi;  // @48_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @49_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097158));  // @50_4b8bf0
  ecx = edx = 0;  // @51_4b8bf0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L4b8d20;  // @52_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @53_4b8bf0
  ecx = ebx;  // @54_4b8bf0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 89), &v, sizeof v); }  // @55_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(16));  // @56_4b8bf0
  ecx = edx = 0;  // @57_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @59_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892012), (u32)(0), (u32)(6891852), (u32)(36));  // @61_4b8bf0
  ecx = edx = 0;  // @62_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 72), &v, sizeof v); }  // @63_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @64_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @65_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892028), (u32)(0), (u32)(6891852), (u32)(37));  // @67_4b8bf0
  ecx = edx = 0;  // @68_4b8bf0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 74), &v, sizeof v); }  // @69_4b8bf0
  goto L4b8d7e;  // @70_4b8bf0
  L4b8d20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @72_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6891852), (u32)(32));  // @74_4b8bf0
  ecx = edx = 0;  // @75_4b8bf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @76_4b8bf0
  edi = eax;  // @77_4b8bf0
  eax = (u32)(EBP - 272);  // @78_4b8bf0
  PS[1] = eax;  // @79_4b8bf0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_4b8bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @81_4b8bf0
  ecx = edx = 0;  // @82_4b8bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @83_4b8bf0
  ecx = eax;  // @84_4b8bf0
  reg.state = (s32)((u32)(1));  // @85_4b8bf0
  eax = ext_4cc1d0_thiscall1(ecx);  // @86_4b8bf0
  ecx = edx = 0;  // @87_4b8bf0
  PS[0] = eax;  // @88_4b8bf0
  PS[2] = edi;  // @89_4b8bf0
  eax = ((u32(*)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6891960), (u32)(PS[0]));  // @90_4b8bf0
  ecx = edx = 0;  // @91_4b8bf0
  ecx = (u32)(EBP - 272);  // @92_4b8bf0
  L4b8d68:;
  reg.state = (s32)((u32)(4294967295));  // @94_4b8bf0
  eax = ext_4cbec0_thiscall1(ecx);  // @95_4b8bf0
  ecx = edx = 0;  // @96_4b8bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @97_4b8bf0
  ecx = ebx;  // @98_4b8bf0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @99_4b8bf0
  ecx = edx = 0;  // @100_4b8bf0
  L4b8d7e:;
  SEH_LEAVE();  // @102_4b8bf0
  ext_633654(G(u32, 0x6f5630));  // @103_4b8bf0
  return eax;  // @104_4b8bf0
}
PCREG(4b8bf0, lifted_4b8bf0);

