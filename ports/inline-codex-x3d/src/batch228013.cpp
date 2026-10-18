// batch228013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_48cf50_thiscall1(u32) __asm__("ext_48cf50");
extern "C" u32 THISCALL ext_48f880_thiscall2(u32, u32) __asm__("ext_48f880");
extern "C" u32 THISCALL ext_493820_thiscall4(u32, u32, u32, u32) __asm__("ext_493820");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc690_thiscall1(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4ccb40_thiscall3(u32, u32, u32) __asm__("ext_4ccb40");
extern "C" u32 THISCALL ext_4ccef0_thiscall1(u32) __asm__("ext_4ccef0");
extern "C" u32 THISCALL ext_4cd6f0_thiscall3(u32, u32, u32) __asm__("ext_4cd6f0");
extern "C" u32 THISCALL ext_4cf690_thiscall1(u32) __asm__("ext_4cf690");
extern "C" u32 THISCALL ext_4da1d0_thiscall2(u32, u32) __asm__("ext_4da1d0");
extern "C" u32 THISCALL ext_4e6780_thiscall2(u32, u32) __asm__("ext_4e6780");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_493980(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x667ee8);  // @h_493980
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  edi = ecx;  // @0_493980
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_493980
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7253), sizeof v); (u32)v; }) != (u32)(0)) goto L493a67;  // @2_493980
  eax = ext_41e290_cdecl1((u32)(32));  // @3_493980
  ecx = edx = 0;  // @4_493980
  esi = eax;  // @5_493980
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @6_493980
  reg.state = (s32)((u32)(0));  // @7_493980
  if ((esi & esi) == 0) goto L493a10;  // @8_493980
  ecx = esi;  // @9_493980
  eax = ext_4e6780_thiscall2(ecx, (u32)(1026));  // @10_493980
  ecx = edx = 0;  // @11_493980
  ecx = esi;  // @12_493980
  reg.state = (s32)((u32)(1));  // @13_493980
  { u32 v = (u32)((u32)(6871484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_493980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @15_493980
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @16_493980
  eax = ext_48cf50_thiscall1(ecx);  // @17_493980
  ecx = edx = 0;  // @18_493980
  { u32 v = (u32)((u32)(6871512)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_493980
  goto L493a12;  // @20_493980
  L493a10:;
  esi = 0;  // @22_493980
  L493a12:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_493980
  ecx = edi;  // @25_493980
  reg.state = (s32)((u32)(4294967295));  // @26_493980
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 7253), &v, sizeof v); }  // @27_493980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6859156), (u32)(1025), (u32)(0), (u32)(0));  // @28_493980
  ecx = edx = 0;  // @29_493980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_493980
  ecx = edi;  // @31_493980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6871536), (u32)(1024), (u32)(0), (u32)(0));  // @32_493980
  ecx = edx = 0;  // @33_493980
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_493980
  ecx = edi;  // @35_493980
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6871536), (u32)(1024), (u32)(0), (u32)(0));  // @36_493980
  ecx = edx = 0;  // @37_493980
  L493a67:;
  PV[0] = (u32)(ebx);  // @39_493980
  ecx = (u32)(EBP - 144);  // @40_493980
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @41_493980
  ecx = edx = 0;  // @42_493980
  ecx = (u32)(EBP - 144);  // @43_493980
  reg.state = (s32)((u32)(2));  // @44_493980
  eax = ext_4cc690_thiscall1(ecx);  // @45_493980
  ecx = edx = 0;  // @46_493980
  ecx = (u32)(EBP - 144);  // @47_493980
  eax = ext_4cc1d0_thiscall1(ecx);  // @48_493980
  ecx = edx = 0;  // @49_493980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7253), sizeof v); (u32)v; });  // @50_493980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @51_493980
  eax = (u32)(EBP - 148);  // @52_493980
  PV[1] = (u32)(eax);  // @53_493980
  eax = ext_48f880_thiscall2(ecx, PV[1]);  // @54_493980
  ecx = edx = 0;  // @55_493980
  if ((eax & eax) == 0) goto L493ab6;  // @56_493980
  eax = (eax + (u32)(4));  // @57_493980
  if (eax == 0) goto L493ab6;  // @58_493980
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @59_493980
  goto L493b28;  // @60_493980
  L493ab6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @62_493980
  if ((esi & esi) != 0) goto L493ac9;  // @63_493980
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7257), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 7257), &v, sizeof v); }  // @64_493980
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7257), sizeof v); (u32)v; });  // @65_493980
  L493ac9:;
  ecx = (u32)(EBP - 144);  // @67_493980
  eax = ext_4cc1d0_thiscall1(ecx);  // @68_493980
  ecx = edx = 0;  // @69_493980
  edx = (u32)(eax + 1);  // @70_493980
  L493ad7:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @72_493980
  eax = (eax + 1);  // @73_493980
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L493ad7;  // @74_493980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @75_493980
  ebx = (u32)(edi + 3149);  // @76_493980
  eax = (eax - edx);  // @77_493980
  ebx = (u32)(ebx + esi*4);  // @78_493980
  eax = (eax + 1);  // @79_493980
  PV[2] = (u32)(eax);  // @80_493980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_493980
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, PV[2]);  // @82_493980
  ecx = edx = 0;  // @83_493980
  ecx = (u32)(EBP - 144);  // @84_493980
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @85_493980
  eax = ext_4cc1d0_thiscall1(ecx);  // @86_493980
  ecx = edx = 0;  // @87_493980
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @88_493980
  L493b08:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @90_493980
  eax = (u32)(eax + 1);  // @91_493980
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @92_493980
  edx = (u32)(edx + 1);  // @93_493980
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L493b08;  // @94_493980
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7253), sizeof v); (u32)v; });  // @95_493980
  PV[3] = (u32)(esi);  // @96_493980
  PV[4] = (u32)(ebx);  // @97_493980
  eax = ext_493820_thiscall4(ecx, PV[4], PV[3], (u32)(1));  // @98_493980
  ecx = edx = 0;  // @99_493980
  esi = (esi & 0xffff);  // @100_493980
  L493b28:;
  ecx = (u32)(EBP - 144);  // @102_493980
  eax = ext_4cbec0_thiscall1(ecx);  // @103_493980
  ecx = edx = 0;  // @104_493980
  eax = (eax & 0xffff0000u) | (((esi & 0xffff)) & 0xffff);  // @105_493980
  SEH_LEAVE();  // @106_493980
  ext_633654(G(u32, 0x6f5630));  // @107_493980
  return eax;  // @108_493980
}
PCREG(493980, lifted_493980);

extern "C" u32 STDCALL lifted_48c300(u32 a0) {
  SEH_ENTER(0x667a38);  // @h_48c300
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = (u32)(EBP - 60);  // @0_48c300
  eax = ext_4ccb40_thiscall3(ecx, (u32)(32), (u32)(0));  // @1_48c300
  ecx = edx = 0;  // @2_48c300
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_48c300
  reg.state = (s32)((u32)(0));  // @4_48c300
  if ((ebx & ebx) == 0) goto L48c408;  // @5_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @6_48c300
  ecx = (u32)(EBP - 24);  // @7_48c300
  PV[0] = (u32)(ecx);  // @8_48c300
  ecx = ebx;  // @9_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @10_48c300
  ecx = edx = 0;  // @11_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_48c300
  ecx = (u32)(EBP - 24);  // @13_48c300
  PV[1] = (u32)(ecx);  // @14_48c300
  ecx = ebx;  // @15_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @16_48c300
  ecx = edx = 0;  // @17_48c300
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L48c408;  // @18_48c300
  L48c370:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_48c300
  PV[2] = (u32)(eax);  // @21_48c300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @22_48c300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[2]);  // @24_48c300
  ecx = edx = 0;  // @25_48c300
  edi = eax;  // @26_48c300
  if ((edi & edi) == 0) goto L48c3f3;  // @27_48c300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @28_48c300
  if ((ecx & ecx) == 0) goto L48c397;  // @29_48c300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @30_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; });  // @31_48c300
  goto L48c39c;  // @32_48c300
  L48c397:;
  eax = (u32)(2097154);  // @34_48c300
  L48c39c:;
  if ((eax & (u32)(1048576)) != 0) goto L48c3af;  // @36_48c300
  ecx = edi;  // @37_48c300
  eax = ext_4da1d0_thiscall2(ecx, (u32)(0));  // @38_48c300
  ecx = edx = 0;  // @39_48c300
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @40_48c300
  L48c3af:;
  if ((edi & edi) == 0) goto L48c3f3;  // @42_48c300
  L48c3b3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @44_48c300
  ecx = esi;  // @45_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_48c300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 680)))(ecx);  // @47_48c300
  ecx = edx = 0;  // @48_48c300
  if ((eax & (u32)(16384)) != 0) goto L48c3f3;  // @49_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @50_48c300
  ecx = esi;  // @51_48c300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 676)))(ecx, (u32)(16384), (u32)(0));  // @52_48c300
  ecx = edx = 0;  // @53_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_48c300
  ecx = esi;  // @55_48c300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 608)))(ecx);  // @56_48c300
  ecx = edx = 0;  // @57_48c300
  PV[3] = (u32)(eax);  // @58_48c300
  PV[4] = (u32)(esi);  // @59_48c300
  ecx = (u32)(EBP - 60);  // @60_48c300
  eax = ext_4cd6f0_thiscall3(ecx, PV[4], PV[3]);  // @61_48c300
  ecx = edx = 0;  // @62_48c300
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @63_48c300
  if ((edi & edi) != 0) goto L48c3b3;  // @64_48c300
  L48c3f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @66_48c300
  ecx = (u32)(EBP - 24);  // @67_48c300
  PV[5] = (u32)(ecx);  // @68_48c300
  ecx = ebx;  // @69_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @70_48c300
  ecx = edx = 0;  // @71_48c300
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L48c370;  // @72_48c300
  L48c408:;
  ecx = (u32)(EBP - 60);  // @74_48c300
  eax = ext_4cf690_thiscall1(ecx);  // @75_48c300
  ecx = edx = 0;  // @76_48c300
  eax = (u32)(EBP - 24);  // @77_48c300
  PV[6] = (u32)(eax);  // @78_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @79_48c300
  ecx = (u32)(EBP - 60);  // @80_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[6]);  // @81_48c300
  ecx = edx = 0;  // @82_48c300
  eax = (u32)(EBP - 24);  // @83_48c300
  PV[7] = (u32)(eax);  // @84_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @85_48c300
  ecx = (u32)(EBP - 60);  // @86_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[7]);  // @87_48c300
  ecx = edx = 0;  // @88_48c300
  esi = eax;  // @89_48c300
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L48c45e;  // @90_48c300
  L48c432:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_48c300
  ecx = esi;  // @93_48c300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 0)))(ecx);  // @94_48c300
  ecx = edx = 0;  // @95_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @96_48c300
  ecx = esi;  // @97_48c300
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 676)))(ecx, (u32)(0), (u32)(16384));  // @98_48c300
  ecx = edx = 0;  // @99_48c300
  eax = (u32)(EBP - 24);  // @100_48c300
  PV[8] = (u32)(eax);  // @101_48c300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @102_48c300
  ecx = (u32)(EBP - 60);  // @103_48c300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[8]);  // @104_48c300
  ecx = edx = 0;  // @105_48c300
  esi = eax;  // @106_48c300
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L48c432;  // @107_48c300
  L48c45e:;
  ecx = (u32)(EBP - 60);  // @109_48c300
  eax = ext_4ccef0_thiscall1(ecx);  // @110_48c300
  ecx = edx = 0;  // @111_48c300
  SEH_LEAVE();  // @112_48c300
  return eax;  // @113_48c300
}
PCREG(48c300, lifted_48c300);

