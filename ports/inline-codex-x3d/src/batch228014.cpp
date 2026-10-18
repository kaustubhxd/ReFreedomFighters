// batch228014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_4d06a0_stdcall1(u32) __asm__("ext_4d06a0");
extern "C" u32 THISCALL ext_4367b0_thiscall3(u32, u32, u32) __asm__("ext_4367b0");
extern "C" u32 THISCALL ext_4369a0_thiscall3(u32, u32, u32) __asm__("ext_4369a0");
extern "C" u32 THISCALL ext_436b30_thiscall3(u32, u32, u32) __asm__("ext_436b30");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d9350_thiscall3(u32, u32, u32) __asm__("ext_4d9350");
extern "C" u32 THISCALL ext_57d500_thiscall3(u32, u32, u32) __asm__("ext_57d500");
extern "C" u32 THISCALL ext_639c50_thiscall2(u32, u32) __asm__("ext_639c50");
extern "C" u32 THISCALL ext_639df0_thiscall3(u32, u32, u32) __asm__("ext_639df0");
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_57cb40(u32 ecx_in) {
  SEH_ENTER(0x66b22b);  // @h_57cb40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_57cb40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }) != (u32)(0)) goto L57ccfa;  // @2_57cb40
  edi = (u32)(ebx + 572);  // @3_57cb40
  if ((edi & edi) == 0) goto L57ccd9;  // @4_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_57cb40
  ecx = (u32)(EBP - 208);  // @6_57cb40
  PV[0] = (u32)(ecx);  // @7_57cb40
  ecx = edi;  // @8_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @9_57cb40
  ecx = edx = 0;  // @10_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_57cb40
  ecx = (u32)(EBP - 208);  // @12_57cb40
  PV[1] = (u32)(ecx);  // @13_57cb40
  ecx = edi;  // @14_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @15_57cb40
  ecx = edx = 0;  // @16_57cb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }) == (u32)(0)) goto L57ccd9;  // @17_57cb40
  L57cbb6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @19_57cb40
  PV[2] = (u32)(eax);  // @20_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @22_57cb40
  ecx = edx = 0;  // @23_57cb40
  esi = eax;  // @24_57cb40
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 223), sizeof v); (u32)v; }) == (u32)(0)) goto L57ccbe;  // @25_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 188)))(ecx);  // @28_57cb40
  ecx = edx = 0;  // @29_57cb40
  ecx = (u32)(esi + 44);  // @30_57cb40
  PV[3] = (u32)(ecx);  // @31_57cb40
  ecx = eax;  // @32_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, PV[3]);  // @34_57cb40
  ecx = edx = 0;  // @35_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_57cb40
  ecx = (u32)(6990352);  // @37_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_57cb40
  L57cbf6:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @40_57cb40
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L57cc16;  // @41_57cb40
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L57cc12;  // @42_57cb40
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @43_57cb40
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L57cc16;  // @44_57cb40
  ecx = (ecx + (u32)(2));  // @45_57cb40
  eax = (eax + (u32)(2));  // @46_57cb40
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L57cbf6;  // @47_57cb40
  L57cc12:;
  eax = 0;  // @49_57cb40
  goto L57cc1b;  // @50_57cb40
  L57cc16:;
  eax = ((0) ? 0xffffffffu : 0u);  // @52_57cb40
  eax = (eax | (u32)(1));  // @53_57cb40
  L57cc1b:;
  if ((eax & eax) != 0) goto L57ccbe;  // @55_57cb40
  ecx = (u32)(EBP - 196);  // @56_57cb40
  eax = ext_4cbeb0_thiscall1(ecx);  // @57_57cb40
  ecx = edx = 0;  // @58_57cb40
  eax = (u32)(EBP - 196);  // @59_57cb40
  reg.state = (s32)((u32)(0));  // @60_57cb40
  PV[4] = (u32)(eax);  // @61_57cb40
  ecx = esi;  // @62_57cb40
  eax = ext_57d500_thiscall3(ecx, PV[4], (u32)(6991200));  // @63_57cb40
  ecx = edx = 0;  // @64_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 172), sizeof v); (u32)v; });  // @65_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @67_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 188), sizeof v); (u32)v; });  // @68_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @69_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 176), sizeof v); (u32)v; });  // @70_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @71_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 192), sizeof v); (u32)v; });  // @72_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @73_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 180), sizeof v); (u32)v; });  // @74_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @75_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 196), sizeof v); (u32)v; });  // @76_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @77_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 184), sizeof v); (u32)v; });  // @78_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @79_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; });  // @80_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @81_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @83_57cb40
  ecx = edx = 0;  // @84_57cb40
  ecx = (u32)(EBP - 196);  // @85_57cb40
  PV[5] = (u32)(ecx);  // @86_57cb40
  ecx = eax;  // @87_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, PV[5]);  // @89_57cb40
  ecx = edx = 0;  // @90_57cb40
  ecx = (u32)(EBP - 196);  // @91_57cb40
  reg.state = (s32)((u32)(4294967295));  // @92_57cb40
  eax = ext_4cbec0_thiscall1(ecx);  // @93_57cb40
  ecx = edx = 0;  // @94_57cb40
  L57ccbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @96_57cb40
  ecx = (u32)(EBP - 208);  // @97_57cb40
  PV[6] = (u32)(ecx);  // @98_57cb40
  ecx = edi;  // @99_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @100_57cb40
  ecx = edx = 0;  // @101_57cb40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }) != (u32)(0)) goto L57cbb6;  // @102_57cb40
  L57ccd9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @104_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 116)))(ecx);  // @106_57cb40
  ecx = edx = 0;  // @107_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @108_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 112)))(ecx);  // @110_57cb40
  ecx = edx = 0;  // @111_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @112_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @114_57cb40
  ecx = edx = 0;  // @115_57cb40
  L57ccfa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @117_57cb40
  ecx = ebx;  // @118_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(0));  // @119_57cb40
  ecx = edx = 0;  // @120_57cb40
  SEH_LEAVE();  // @121_57cb40
  ext_633654(G(u32, 0x6f5630));  // @122_57cb40
  return eax;  // @123_57cb40
}
PCREG(57cb40, lifted_57cb40);

extern "C" u32 THISCALL lifted_636020(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  SEH_ENTER(0x66e74b);  // @h_636020
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  edi = ecx;  // @0_636020
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @1_636020
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @2_636020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @4_636020
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @5_636020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @6_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @7_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }  // @8_636020
  { u32 v = (u32)((u32)(1380401729)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @9_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @10_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @11_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @12_636020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @13_636020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 41), &v, sizeof v); }  // @14_636020
  { u32 v = (u32)((u32)(7086356)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @15_636020
  reg.state = (s32)((u32)(0));  // @16_636020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @17_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @18_636020
  eax = ext_639c50_thiscall2(ecx, (u32)(1));  // @19_636020
  ecx = edx = 0;  // @20_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @21_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @22_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @24_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @25_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @26_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @27_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @28_636020
  eax = (u32)(EBP - 112);  // @29_636020
  PV[0] = (u32)(eax);  // @30_636020
  ecx = eax;  // @31_636020
  eax = ext_4d06a0_stdcall1(PV[0]);  // @32_636020
  ecx = edx = 0;  // @33_636020
  eax = (u32)(EBP - 64);  // @34_636020
  { u32 v = (u32)((u32)(255)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @35_636020
  PV[1] = (u32)(eax);  // @36_636020
  ecx = (u32)(EBP - 112);  // @37_636020
  { u32 v = (u32)((u32)(65280)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @38_636020
  { u32 v = (u32)((u32)(16711680)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @39_636020
  { u32 v = (u32)((u32)(4278190080)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @40_636020
  eax = ext_4d06a0_stdcall1(PV[1]);  // @41_636020
  ecx = edx = 0;  // @42_636020
  esi = ebx;  // @43_636020
  ecx = 0;  // @44_636020
  esi = (u32)((s32)esi * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; }));  // @45_636020
  edx = (u32)(4);  // @46_636020
  eax = esi;  // @47_636020
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @48_636020
  u64 mul_49 = (u64)eax * (u64)(edx);  // @49_636020
  eax = (u32)mul_49;  // @50_636020
  edx = (u32)(mul_49 >> 32);  // @51_636020
  ecx = (ecx & 0xffffff00u) | (((((mul_49 >> 32) != 0) ? 1 : 0)) & 0xff);  // @52_636020
  ecx = (0u - ecx);  // @53_636020
  ecx = (ecx | eax);  // @54_636020
  PV[2] = (u32)(ecx);  // @55_636020
  eax = ext_41e290_cdecl1(PV[2]);  // @56_636020
  ecx = edx = 0;  // @57_636020
  ebx = eax;  // @58_636020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 124), &v, sizeof v); }  // @59_636020
  if ((s32)(esi & esi) <= 0) goto L636153;  // @60_636020
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @61_636020
  esi = ebx;  // @62_636020
  edi = (edi - ebx);  // @63_636020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @64_636020
  L636132:;
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @66_636020
  ecx = (u32)(EBP - 112);  // @67_636020
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi), sizeof v); (u32)v; });  // @68_636020
  eax = ext_639df0_thiscall3(ecx, PV[4], PV[3]);  // @69_636020
  ecx = edx = 0;  // @70_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @71_636020
  esi = (u32)(esi + 4);  // @72_636020
  ebx = (ebx - (u32)(1));  // @73_636020
  if (ebx != 0) goto L636132;  // @74_636020
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @75_636020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 124), sizeof v); (u32)v; });  // @76_636020
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @77_636020
  L636153:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @79_636020
  esi = (esi << (u32)(2));  // @80_636020
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L636173;  // @81_636020
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @82_636020
  eax = ext_634273_cdecl2(PV[5], (u32)(1));  // @83_636020
  ecx = edx = 0;  // @84_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @85_636020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @86_636020
  L636173:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @88_636020
  PV[6] = (u32)(esi);  // @89_636020
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @90_636020
  eax = ext_41e290_cdecl1(PV[6]);  // @91_636020
  ecx = edx = 0;  // @92_636020
  ecx = eax;  // @93_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @94_636020
  PV[7] = (u32)(esi);  // @95_636020
  PV[8] = (u32)(ebx);  // @96_636020
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @97_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @98_636020
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @99_636020
  eax = ext_634d22_cdecl3(PV[9], PV[8], PV[7]);  // @100_636020
  ecx = edx = 0;  // @101_636020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @102_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 132), sizeof v); (u32)v; });  // @103_636020
  PV[10] = (u32)(ebx);  // @104_636020
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @105_636020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @106_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @107_636020
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @108_636020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @109_636020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @110_636020
  eax = ext_634273_cdecl2(PV[10], (u32)(4));  // @111_636020
  ecx = edx = 0;  // @112_636020
  eax = edi;  // @113_636020
  SEH_LEAVE();  // @114_636020
  ext_633654(G(u32, 0x6f5630));  // @115_636020
  return eax;  // @116_636020
}
PCREG(636020, lifted_636020);

extern "C" u32 THISCALL lifted_437210(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665a5d);  // @h_437210
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_437210
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_437210
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_437210
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[0]);  // @4_437210
  ecx = edx = 0;  // @5_437210
  if ((eax & eax) == 0) goto L4372a3;  // @6_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @7_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_437210
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2627));  // @9_437210
  ecx = edx = 0;  // @10_437210
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_437210
  PV[2] = (u32)(eax);  // @13_437210
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6794008), PV[1]);  // @14_437210
  ecx = edx = 0;  // @15_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @16_437210
  if ((eax & eax) == 0) goto L43728c;  // @17_437210
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_437210
  ecx = edx = 0;  // @19_437210
  eax = 0;  // @20_437210
  SEH_LEAVE();  // @21_437210
  return eax;  // @22_437210
  L43728c:;
  __builtin_trap();  // @24_437210
  L4372a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @26_437210
  if (((eax & 0xff) & (u32)(2)) == 0) goto L4372cf;  // @27_437210
  eax = ext_41e290_cdecl1((u32)(18));  // @28_437210
  ecx = edx = 0;  // @29_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @30_437210
  reg.state = (s32)((u32)(0));  // @31_437210
  if ((eax & eax) == 0) goto L4372f8;  // @32_437210
  PV[3] = (u32)(esi);  // @33_437210
  PV[4] = (u32)(ebx);  // @34_437210
  ecx = eax;  // @35_437210
  eax = ext_4369a0_thiscall3(ecx, PV[4], PV[3]);  // @36_437210
  ecx = edx = 0;  // @37_437210
  edi = eax;  // @38_437210
  goto L4372fa;  // @39_437210
  L4372cf:;
  if (((eax & 0xff) & (u32)(8)) == 0) goto L43731d;  // @41_437210
  eax = ext_41e290_cdecl1((u32)(26));  // @42_437210
  ecx = edx = 0;  // @43_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @44_437210
  reg.state = (s32)((u32)(1));  // @45_437210
  if ((eax & eax) == 0) goto L4372f8;  // @46_437210
  PV[5] = (u32)(esi);  // @47_437210
  PV[6] = (u32)(ebx);  // @48_437210
  ecx = eax;  // @49_437210
  eax = ext_436b30_thiscall3(ecx, PV[6], PV[5]);  // @50_437210
  ecx = edx = 0;  // @51_437210
  edi = eax;  // @52_437210
  goto L4372fa;  // @53_437210
  L4372f8:;
  edi = 0;  // @55_437210
  L4372fa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @57_437210
  PV[7] = (u32)(edi);  // @58_437210
  reg.state = (s32)((u32)(4294967295));  // @59_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_437210
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[7]);  // @61_437210
  ecx = edx = 0;  // @62_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @63_437210
  PV[8] = (u32)(edi);  // @64_437210
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @66_437210
  eax = ext_4d9350_thiscall3(ecx, PV[9], PV[8]);  // @67_437210
  ecx = edx = 0;  // @68_437210
  goto L437380;  // @69_437210
  L43731d:;
  eax = ext_41e290_cdecl1((u32)(74));  // @71_437210
  ecx = edx = 0;  // @72_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @73_437210
  reg.state = (s32)((u32)(2));  // @74_437210
  if ((eax & eax) == 0) goto L437343;  // @75_437210
  PV[10] = (u32)(esi);  // @76_437210
  ecx = (u32)(ebx + 4);  // @77_437210
  PV[11] = (u32)(ecx);  // @78_437210
  ecx = eax;  // @79_437210
  eax = ext_4367b0_thiscall3(ecx, PV[11], PV[10]);  // @80_437210
  ecx = edx = 0;  // @81_437210
  goto L437345;  // @82_437210
  L437343:;
  eax = 0;  // @84_437210
  L437345:;
  ecx = 0;  // @86_437210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @87_437210
  edi = (u32)(eax + 4);  // @88_437210
  reg.state = (s32)((u32)(4294967295));  // @89_437210
  esi = edi;  // @90_437210
  if ((eax & eax) == 0) esi = ecx;  // @91_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @92_437210
  PV[12] = (u32)(esi);  // @93_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_437210
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[12]);  // @95_437210
  ecx = edx = 0;  // @96_437210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @97_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @98_437210
  PV[13] = (u32)(esi);  // @99_437210
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @100_437210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4912), sizeof v); (u32)v; });  // @101_437210
  eax = ext_4d9350_thiscall3(ecx, PV[14], PV[13]);  // @102_437210
  ecx = edx = 0;  // @103_437210
  eax = 0;  // @104_437210
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) == eax) edi = eax;  // @105_437210
  L437380:;
  eax = edi;  // @107_437210
  SEH_LEAVE();  // @108_437210
  return eax;  // @109_437210
}
PCREG(437210, lifted_437210);

extern "C" u32 THISCALL lifted_45da60(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6667e6);  // @h_45da60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @1_45da60
  if ((eax & eax) == 0) goto L45dc03;  // @2_45da60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_45da60
  edi = (edi & (u32)(344));  // @4_45da60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L45db01;  // @5_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @6_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_45da60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1417));  // @8_45da60
  ecx = edx = 0;  // @9_45da60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_45da60
  edi = eax;  // @11_45da60
  eax = (u32)(EBP - 144);  // @12_45da60
  ecx = ebx;  // @13_45da60
  PV[0] = (u32)(eax);  // @14_45da60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[0], (u32)(1));  // @15_45da60
  ecx = edx = 0;  // @16_45da60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_45da60
  ecx = eax;  // @18_45da60
  reg.state = (s32)((u32)(0));  // @19_45da60
  eax = ext_4cc1d0_thiscall1(ecx);  // @20_45da60
  ecx = edx = 0;  // @21_45da60
  PV[1] = (u32)(eax);  // @22_45da60
  PV[2] = (u32)(edi);  // @23_45da60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[2], (u32)(6836440), PV[1]);  // @24_45da60
  ecx = edx = 0;  // @25_45da60
  ecx = (u32)(EBP - 144);  // @26_45da60
  eax = ext_4cbec0_thiscall1(ecx);  // @27_45da60
  ecx = edx = 0;  // @28_45da60
  goto L45dc03;  // @29_45da60
  L45db01:;
  ecx = (u32)(EBP - 316);  // @31_45da60
  eax = ext_4ccba0_thiscall1(ecx);  // @32_45da60
  ecx = edx = 0;  // @33_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @34_45da60
  reg.state = (s32)((u32)(1));  // @35_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @36_45da60
  if ((ecx & ecx) == 0) goto L45db6b;  // @37_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_45da60
  edx = (u32)(EBP - 328);  // @39_45da60
  PV[3] = (u32)(edx);  // @40_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @41_45da60
  ecx = edx = 0;  // @42_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @43_45da60
  edx = (u32)(EBP - 328);  // @44_45da60
  PV[4] = (u32)(edx);  // @45_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @46_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @48_45da60
  ecx = edx = 0;  // @49_45da60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }) == (u32)(0)) goto L45db6b;  // @50_45da60
  L45db44:;
  PV[5] = (u32)(eax);  // @52_45da60
  ecx = (u32)(EBP - 316);  // @53_45da60
  eax = ext_4cd540_thiscall2(ecx, PV[5]);  // @54_45da60
  ecx = edx = 0;  // @55_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @56_45da60
  edx = (u32)(EBP - 328);  // @57_45da60
  PV[6] = (u32)(edx);  // @58_45da60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @59_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @61_45da60
  ecx = edx = 0;  // @62_45da60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }) != (u32)(0)) goto L45db44;  // @63_45da60
  L45db6b:;
  eax = (u32)(EBP - 328);  // @65_45da60
  PV[7] = (u32)(eax);  // @66_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @67_45da60
  ecx = (u32)(EBP - 316);  // @68_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7]);  // @69_45da60
  ecx = edx = 0;  // @70_45da60
  eax = (u32)(EBP - 328);  // @71_45da60
  PV[8] = (u32)(eax);  // @72_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @73_45da60
  ecx = (u32)(EBP - 316);  // @74_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @75_45da60
  ecx = edx = 0;  // @76_45da60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }) == (u32)(0)) goto L45dbf8;  // @77_45da60
  L45dba0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @79_45da60
  PV[9] = (u32)(eax);  // @80_45da60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[9]);  // @82_45da60
  ecx = edx = 0;  // @83_45da60
  esi = eax;  // @84_45da60
  if ((esi & esi) == 0) goto L45dbd9;  // @85_45da60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45dbd9;  // @86_45da60
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & edi) == 0) goto L45dbd9;  // @87_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_45da60
  ecx = esi;  // @89_45da60
  PV[10] = (u32)(edi);  // @90_45da60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[10], (u32)(0));  // @91_45da60
  ecx = edx = 0;  // @92_45da60
  eax = edi;  // @93_45da60
  ecx = esi;  // @94_45da60
  eax = (~eax);  // @95_45da60
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & eax)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @96_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_45da60
  PV[11] = (u32)(ebx);  // @98_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[11]);  // @99_45da60
  ecx = edx = 0;  // @100_45da60
  L45dbd9:;
  eax = (u32)(EBP - 328);  // @102_45da60
  PV[12] = (u32)(eax);  // @103_45da60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @104_45da60
  ecx = (u32)(EBP - 316);  // @105_45da60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[12]);  // @106_45da60
  ecx = edx = 0;  // @107_45da60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 328), sizeof v); (u32)v; }) != (u32)(0)) goto L45dba0;  // @108_45da60
  L45dbf8:;
  ecx = (u32)(EBP - 316);  // @110_45da60
  eax = ext_4ccf60_thiscall1(ecx);  // @111_45da60
  ecx = edx = 0;  // @112_45da60
  L45dc03:;
  SEH_LEAVE();  // @114_45da60
  ext_633654(G(u32, 0x6f5630));  // @115_45da60
  return eax;  // @116_45da60
}
PCREG(45da60, lifted_45da60);

extern "C" u32 THISCALL lifted_53aae0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c60b);  // @h_53aae0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_53aae0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_53aae0
  ecx = (u32)(EBP - 188);  // @2_53aae0
  eax = ext_4ccba0_thiscall1(ecx);  // @3_53aae0
  ecx = edx = 0;  // @4_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_53aae0
  ecx = (u32)(EBP - 188);  // @6_53aae0
  PV[0] = (u32)(ecx);  // @7_53aae0
  ecx = esi;  // @8_53aae0
  reg.state = (s32)((u32)(0));  // @9_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[0]);  // @10_53aae0
  ecx = edx = 0;  // @11_53aae0
  eax = (u32)(EBP - 200);  // @12_53aae0
  PV[1] = (u32)(eax);  // @13_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @14_53aae0
  ecx = (u32)(EBP - 188);  // @15_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @16_53aae0
  ecx = edx = 0;  // @17_53aae0
  eax = (u32)(EBP - 200);  // @18_53aae0
  PV[2] = (u32)(eax);  // @19_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @20_53aae0
  ecx = (u32)(EBP - 188);  // @21_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @22_53aae0
  ecx = edx = 0;  // @23_53aae0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L53ac65;  // @24_53aae0
  L53ab70:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_53aae0
  PV[3] = (u32)(eax);  // @27_53aae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @28_53aae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[3]);  // @30_53aae0
  ecx = edx = 0;  // @31_53aae0
  ebx = eax;  // @32_53aae0
  if ((ebx & ebx) == 0) goto L53ac42;  // @33_53aae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @34_53aae0
  if ((ecx & ecx) == 0) goto L53abce;  // @35_53aae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_53aae0
  eax = (u32)(EBP - 212);  // @37_53aae0
  PV[4] = (u32)(eax);  // @38_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[4]);  // @39_53aae0
  ecx = edx = 0;  // @40_53aae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @41_53aae0
  edx = (u32)(EBP - 212);  // @42_53aae0
  PV[5] = (u32)(edx);  // @43_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @45_53aae0
  ecx = edx = 0;  // @46_53aae0
  if ((eax & eax) == 0) goto L53abce;  // @47_53aae0
  L53abb2:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) == ebx) goto L53ac42;  // @49_53aae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @50_53aae0
  edx = (u32)(EBP - 212);  // @51_53aae0
  PV[6] = (u32)(edx);  // @52_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[6]);  // @54_53aae0
  ecx = edx = 0;  // @55_53aae0
  if ((eax & eax) != 0) goto L53abb2;  // @56_53aae0
  L53abce:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @58_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @60_53aae0
  ecx = edx = 0;  // @61_53aae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_53aae0
  ecx = ebx;  // @63_53aae0
  esi = (u32)(eax - 4);  // @64_53aae0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @65_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2099152));  // @66_53aae0
  ecx = edx = 0;  // @67_53aae0
  ecx = (eax & 0xff);  // @68_53aae0
  ecx = (0u - ecx);  // @69_53aae0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @70_53aae0
  ecx = (((ecx != 0)) ? 0xffffffffu : 0u);  // @71_53aae0
  ecx = (ecx + (u32)(2));  // @72_53aae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @73_53aae0
  ecx = (u32)(esi + 8);  // @74_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_53aae0
  eax = (eax + (u32)(64));  // @76_53aae0
  if (ecx == eax) goto L53ac0e;  // @77_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @78_53aae0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @79_53aae0
  L53ac0e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @81_53aae0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @82_53aae0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 14), sizeof v); (u32)v; });  // @83_53aae0
  if ((ecx & ecx) != 0) goto L53ac28;  // @84_53aae0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 14), &v, sizeof v); }  // @85_53aae0
  goto L53ac42;  // @86_53aae0
  L53ac28:;
  eax = (u32)(ecx + 12);  // @88_53aae0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L53ac3c;  // @89_53aae0
  L53ac31:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_53aae0
  eax = (u32)(ecx + 12);  // @92_53aae0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L53ac31;  // @93_53aae0
  L53ac3c:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @95_53aae0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @96_53aae0
  L53ac42:;
  eax = (u32)(EBP - 200);  // @98_53aae0
  PV[7] = (u32)(eax);  // @99_53aae0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @100_53aae0
  ecx = (u32)(EBP - 188);  // @101_53aae0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @102_53aae0
  ecx = edx = 0;  // @103_53aae0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L53ab70;  // @104_53aae0
  L53ac65:;
  ecx = (u32)(EBP - 188);  // @106_53aae0
  eax = ext_4ccf60_thiscall1(ecx);  // @107_53aae0
  ecx = edx = 0;  // @108_53aae0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @109_53aae0
  SEH_LEAVE();  // @110_53aae0
  ext_633654(G(u32, 0x6f5630));  // @111_53aae0
  return eax;  // @112_53aae0
}
PCREG(53aae0, lifted_53aae0);

extern "C" u32 THISCALL lifted_6162f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e5c8);  // @h_6162f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_6162f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6162f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6162f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @3_6162f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @4_6162f0
  { u32 v = (u32)((u32)(7068968)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @5_6162f0
  eax = (u32)(ecx + 12);  // @6_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @7_6162f0
  edi = (u32)(ecx + 36);  // @8_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @9_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @11_6162f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @12_6162f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47536), sizeof v); (u32)v; });  // @13_6162f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47524), sizeof v); (u32)v; });  // @14_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @15_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_6162f0
  reg.state = (s32)((u32)(0));  // @17_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @18_6162f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @19_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @20_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @21_6162f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @22_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @23_6162f0
  eax = (eax + ecx);  // @24_6162f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @25_6162f0
  PV[1] = (u32)(eax);  // @26_6162f0
  eax = ext_659220_thiscall3(ecx, PV[1], PV[0]);  // @27_6162f0
  ecx = edx = 0;  // @28_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @29_6162f0
  ecx = edi;  // @30_6162f0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47532), sizeof v); (u32)v; });  // @31_6162f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 14), sizeof v); (u32)v; });  // @32_6162f0
  PV[3] = (u32)(eax);  // @33_6162f0
  eax = ext_659330_thiscall3(ecx, PV[3], PV[2]);  // @34_6162f0
  ecx = edx = 0;  // @35_6162f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5122), sizeof v); (u32)v; });  // @36_6162f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @37_6162f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @38_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) == (u32)(0)) goto L6163f0;  // @39_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L6163ce;  // @40_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @41_6162f0
  ecx = ebx;  // @42_6162f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @43_6162f0
  ecx = edx = 0;  // @44_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @45_6162f0
  L6163ce:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_6162f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @48_6162f0
  eax = (u32)((s32)eax * (s32)(u32)(52));  // @49_6162f0
  PV[4] = (u32)(eax);  // @50_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @51_6162f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @52_6162f0
  PV[5] = (u32)(eax);  // @53_6162f0
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) * (s32)(u32)(52));  // @54_6162f0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 48), sizeof v); (u32)v; }));  // @55_6162f0
  PV[6] = (u32)(eax);  // @56_6162f0
  eax = ext_634d22_cdecl3(PV[6], PV[5], PV[4]);  // @57_6162f0
  ecx = edx = 0;  // @58_6162f0
  L6163f0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L616472;  // @60_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L61640a;  // @61_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_6162f0
  ecx = edi;  // @63_6162f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @64_6162f0
  ecx = edx = 0;  // @65_6162f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @66_6162f0
  L61640a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @68_6162f0
  ebx = 0;  // @69_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @70_6162f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @71_6162f0
  edi = (edi + (u32)(2));  // @72_6162f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @73_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @74_6162f0
  edi = (edi + eax);  // @75_6162f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L616472;  // @76_6162f0
  L616425:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @78_6162f0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_6162f0
  edi = (edi + (u32)(2));  // @80_6162f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @81_6162f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*8 + 4), sizeof v); (u32)v; }) & (u32)(2147483647))); __builtin_memcpy((void *)(u32)(eax + ebx*8 + 4), &v, sizeof v); }  // @82_6162f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*8 + 4), sizeof v); (u32)v; });  // @83_6162f0
  eax = (u32)(edx + eax*2);  // @84_6162f0
  if ((ecx & ecx) == 0) goto L616469;  // @85_6162f0
  esi = edi;  // @86_6162f0
  edx = ecx;  // @87_6162f0
  esi = (esi - eax);  // @88_6162f0
  L616450:;
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; })) & 0xffff);  // @90_6162f0
  eax = (u32)(eax + 2);  // @91_6162f0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax - 2), &v, sizeof v); }  // @92_6162f0
  edx = (edx - (u32)(1));  // @93_6162f0
  if (edx != 0) goto L616450;  // @94_6162f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @95_6162f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @96_6162f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @97_6162f0
  L616469:;
  ebx = (ebx + 1);  // @99_6162f0
  edi = (u32)(edi + ecx*2);  // @100_6162f0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L616425;  // @101_6162f0
  L616472:;
  eax = esi;  // @103_6162f0
  SEH_LEAVE();  // @104_6162f0
  return eax;  // @105_6162f0
}
PCREG(6162f0, lifted_6162f0);

