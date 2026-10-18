// batch226029.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4388a0_thiscall1(u32) __asm__("ext_4388a0");
extern "C" u32 THISCALL ext_438910_thiscall1(u32) __asm__("ext_438910");
extern "C" u32 THISCALL ext_471f60_thiscall1(u32) __asm__("ext_471f60");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4d9230_thiscall2(u32, u32) __asm__("ext_4d9230");
extern "C" u32 THISCALL ext_4febf0_thiscall2(u32, u32) __asm__("ext_4febf0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_436ec0_cdecl1(...) __asm__("ext_436ec0");
extern "C" u32 ext_438a60_cdecl1(...) __asm__("ext_438a60");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl4(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4fe8a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b8b);  // @h_4fe8a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
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
PCREG(4fe8a0, lifted_4fe8a0);

extern "C" u32 THISCALL lifted_480ff0(u32 ecx_in) {
  SEH_ENTER(0x667420);  // @h_480ff0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
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
PCREG(480ff0, lifted_480ff0);

extern "C" u32 THISCALL lifted_492640(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x667ddb);  // @h_492640
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
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
PCREG(492640, lifted_492640);

extern "C" u32 STDCALL lifted_601b10(u32 a0, u32 a1) {
  SEH_ENTER(0x66976b);  // @h_601b10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
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
PCREG(601b10, lifted_601b10);

extern "C" u32 THISCALL lifted_43a900(u32 ecx_in) {
  SEH_ENTER(0x665cbc);  // @h_43a900
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  edi = ecx;  // @0_43a900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25), sizeof v); (u32)v; });  // @1_43a900
  if ((ecx & ecx) == 0) goto L43aa18;  // @2_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_43a900
  edx = (u32)(EBP - 24);  // @4_43a900
  PS[0] = edx;  // @5_43a900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @6_43a900
  ecx = edx = 0;  // @7_43a900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25), sizeof v); (u32)v; });  // @8_43a900
  edx = (u32)(EBP - 24);  // @9_43a900
  PS[0] = edx;  // @10_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_43a900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @12_43a900
  ecx = edx = 0;  // @13_43a900
  esi = eax;  // @14_43a900
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L43aa18;  // @15_43a900
  L43a960:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 17), sizeof v); (u32)v; });  // @17_43a900
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @18_43a900
  eax = ext_4d9230_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }));  // @19_43a900
  ecx = edx = 0;  // @20_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_43a900
  if ((eax & eax) != 0) goto L43a9b9;  // @22_43a900
  eax = (u32)(esi - 4);  // @23_43a900
  CF = (esi != 0); esi = (u32)(0 - esi);  // @24_43a900
  esi = (u32)(0 - CF);  // @25_43a900
  esi = (esi & eax);  // @26_43a900
  if (esi == 0) goto L43aa00;  // @27_43a900
  ecx = esi;  // @28_43a900
  reg.state = (s32)((u32)(0));  // @29_43a900
  { u32 v = (u32)((u32)(6793180)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @30_43a900
  eax = ext_4388a0_thiscall1(ecx);  // @31_43a900
  ecx = edx = 0;  // @32_43a900
  ecx = esi;  // @33_43a900
  eax = ext_438910_thiscall1(ecx);  // @34_43a900
  ecx = edx = 0;  // @35_43a900
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 50), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L43a9b5;  // @36_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @37_43a900
  if ((eax & eax) == 0) goto L43a9b5;  // @38_43a900
  PS[1] = eax;  // @39_43a900
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @40_43a900
  ecx = edx = 0;  // @41_43a900
  L43a9b5:;
  goto L43a9f0;  // @43_43a900
  L43a9b9:;
  if (eax != (u32)(1)) goto L43a9c9;  // @45_43a900
  ecx = esi;  // @46_43a900
  eax = ext_436ec0_cdecl1((u32)(74));  // @47_43a900
  ecx = edx = 0;  // @48_43a900
  goto L43a9f7;  // @49_43a900
  L43a9c9:;
  if (eax != (u32)(2)) goto L43aa00;  // @51_43a900
  ecx = esi;  // @52_43a900
  reg.state = (s32)((u32)(1));  // @53_43a900
  eax = ext_438a60_cdecl1((u32)(18));  // @54_43a900
  ecx = edx = 0;  // @55_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @56_43a900
  if ((eax & eax) == 0) goto L43a9ee;  // @57_43a900
  PS[1] = eax;  // @58_43a900
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @59_43a900
  ecx = edx = 0;  // @60_43a900
  L43a9ee:;
  L43a9f0:;
  reg.state = (s32)((u32)(4294967295));  // @63_43a900
  L43a9f7:;
  PS[1] = esi;  // @65_43a900
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(26));  // @66_43a900
  ecx = edx = 0;  // @67_43a900
  L43aa00:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 25), sizeof v); (u32)v; });  // @69_43a900
  edx = (u32)(EBP - 24);  // @70_43a900
  PS[0] = edx;  // @71_43a900
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_43a900
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @73_43a900
  ecx = edx = 0;  // @74_43a900
  esi = eax;  // @75_43a900
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L43a960;  // @76_43a900
  L43aa18:;
  SEH_LEAVE();  // @78_43a900
  return eax;  // @79_43a900
}
PCREG(43a900, lifted_43a900);

