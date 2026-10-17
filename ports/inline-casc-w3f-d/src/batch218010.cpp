// batch218010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc780_fastcall2(u32, u32) __asm__("ext_4cc780");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_4c4f10_stdcall3(u32, u32, u32) __asm__("ext_4c4f10");
extern "C" u32 STDCALL ext_5c6370_stdcall2(u32, u32) __asm__("ext_5c6370");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_43de40_thiscall4(u32, u32, u32, u32) __asm__("ext_43de40");
extern "C" u32 THISCALL ext_442050_thiscall2(u32, u32) __asm__("ext_442050");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_49def0_thiscall1(u32) __asm__("ext_49def0");
extern "C" u32 THISCALL ext_49f2d0_thiscall1(u32) __asm__("ext_49f2d0");
extern "C" u32 THISCALL ext_4a3280_thiscall1(u32) __asm__("ext_4a3280");
extern "C" u32 THISCALL ext_4a3360_thiscall1(u32) __asm__("ext_4a3360");
extern "C" u32 THISCALL ext_4a3b40_thiscall1(u32) __asm__("ext_4a3b40");
extern "C" u32 THISCALL ext_4a4700_thiscall1(u32) __asm__("ext_4a4700");
extern "C" u32 THISCALL ext_4a4fb0_thiscall1(u32) __asm__("ext_4a4fb0");
extern "C" u32 THISCALL ext_4a6270_thiscall1(u32) __asm__("ext_4a6270");
extern "C" u32 THISCALL ext_4a7960_thiscall1(u32) __asm__("ext_4a7960");
extern "C" u32 THISCALL ext_4a80a0_thiscall1(u32) __asm__("ext_4a80a0");
extern "C" u32 THISCALL ext_4a86c0_thiscall1(u32) __asm__("ext_4a86c0");
extern "C" u32 THISCALL ext_4a9600_thiscall1(u32) __asm__("ext_4a9600");
extern "C" u32 THISCALL ext_4a9880_thiscall1(u32) __asm__("ext_4a9880");
extern "C" u32 THISCALL ext_4ae4f0_thiscall1(u32) __asm__("ext_4ae4f0");
extern "C" u32 THISCALL ext_4af440_thiscall1(u32) __asm__("ext_4af440");
extern "C" u32 THISCALL ext_4b1c70_thiscall1(u32) __asm__("ext_4b1c70");
extern "C" u32 THISCALL ext_4b8610_thiscall1(u32) __asm__("ext_4b8610");
extern "C" u32 THISCALL ext_4b86b0_thiscall1(u32) __asm__("ext_4b86b0");
extern "C" u32 THISCALL ext_4b8fd0_thiscall1(u32) __asm__("ext_4b8fd0");
extern "C" u32 THISCALL ext_4b9160_thiscall1(u32) __asm__("ext_4b9160");
extern "C" u32 THISCALL ext_4baeb0_thiscall1(u32) __asm__("ext_4baeb0");
extern "C" u32 THISCALL ext_4bb160_thiscall1(u32) __asm__("ext_4bb160");
extern "C" u32 THISCALL ext_4bb350_thiscall1(u32) __asm__("ext_4bb350");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0f60_thiscall2(u32, u32) __asm__("ext_4e0f60");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4e6ce0_thiscall1(u32) __asm__("ext_4e6ce0");
extern "C" u32 THISCALL ext_4e7160_thiscall1(u32) __asm__("ext_4e7160");
extern "C" u32 THISCALL ext_4f6b20_thiscall1(u32) __asm__("ext_4f6b20");
extern "C" u32 THISCALL ext_52cb60_thiscall3(u32, u32, u32) __asm__("ext_52cb60");
extern "C" u32 THISCALL ext_530fd0_thiscall2(u32, u32) __asm__("ext_530fd0");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5b6ab0_thiscall2(u32, u32) __asm__("ext_5b6ab0");
extern "C" u32 THISCALL ext_5b6d00_thiscall1(u32) __asm__("ext_5b6d00");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)











extern "C" u32 THISCALL lifted_48a470(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66772e);  // @h_48a470
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_48a470
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @1_48a470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_48a470
  ecx = (u32)(edi + 28);  // @3_48a470
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @4_48a470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @5_48a470
  { u32 v = (u32)((u32)(6870332)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @6_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @7_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @8_48a470
  eax = ext_4cca60_thiscall3(ecx, (u32)(8), (u32)(1111));  // @9_48a470
  ecx = edx = 0;  // @10_48a470
  reg.state = (s32)((u32)(0));  // @11_48a470
  ecx = (u32)(edi + 216);  // @12_48a470
  { u32 v = (u32)((u32)(6870316)); __builtin_memcpy((void *)(u32)(edi + 204), &v, sizeof v); }  // @13_48a470
  eax = (u32)(128);  // @14_48a470
  L48a4f4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @16_48a470
  ecx = (u32)(ecx + 20);  // @17_48a470
  eax = (eax - (u32)(1));  // @18_48a470
  if (eax != 0) goto L48a4f4;  // @19_48a470
  ecx = (u32)(edi + 2816);  // @20_48a470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2768), &v, sizeof v); }  // @21_48a470
  { u32 v = (u32)((u32)(128)); __builtin_memcpy((void *)(u32)(edi + 2772), &v, sizeof v); }  // @22_48a470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2776), &v, sizeof v); }  // @23_48a470
  eax = ext_4ccba0_thiscall1(ecx);  // @24_48a470
  ecx = edx = 0;  // @25_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2995), &v, sizeof v); }  // @26_48a470
  ecx = (u32)(edi + 3021);  // @27_48a470
  reg.state = (s32)((u32)(1));  // @28_48a470
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3012), &v, sizeof v); }  // @29_48a470
  eax = ext_4cbeb0_thiscall1(ecx);  // @30_48a470
  ecx = edx = 0;  // @31_48a470
  ecx = (u32)(edi + 7265);  // @32_48a470
  reg.state = (s32)((u32)(2));  // @33_48a470
  eax = ext_4d2280_thiscall1(ecx);  // @34_48a470
  ecx = edx = 0;  // @35_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23877), &v, sizeof v); }  // @36_48a470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @37_48a470
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_48a470
  reg.state = (s32)((u32)(3));  // @39_48a470
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 456), sizeof v); (u32)v; });  // @40_48a470
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, (u32)(6870936), (u32)(288), (u32)(6870936), (u32)(288));  // @41_48a470
  ecx = edx = 0;  // @42_48a470
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_48a470
  PV[0] = (u32)(eax);  // @44_48a470
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 440)))(ecx, PV[0]);  // @45_48a470
  ecx = edx = 0;  // @46_48a470
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @47_48a470
  ecx = (u32)(EBP - 144);  // @48_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23865), &v, sizeof v); }  // @49_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2999), &v, sizeof v); }  // @50_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3003), &v, sizeof v); }  // @51_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23861), &v, sizeof v); }  // @52_48a470
  { u32 v = (u32)((u32)(7233776)); __builtin_memcpy((void *)(u32)(edi + 23857), &v, sizeof v); }  // @53_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23849), &v, sizeof v); }  // @54_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23853), &v, sizeof v); }  // @55_48a470
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 23873), &v, sizeof v); }  // @56_48a470
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3010), &v, sizeof v); }  // @57_48a470
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3008), &v, sizeof v); }  // @58_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3017), &v, sizeof v); }  // @59_48a470
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @60_48a470
  ecx = edx = 0;  // @61_48a470
  eax = (u32)(EBP - 144);  // @62_48a470
  reg.state = (s32)((u32)(4));  // @63_48a470
  PV[2] = (u32)(eax);  // @64_48a470
  ecx = (u32)(edi + 3021);  // @65_48a470
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @66_48a470
  ecx = edx = 0;  // @67_48a470
  ecx = (u32)(EBP - 144);  // @68_48a470
  reg.state = (s32)((u32)(3));  // @69_48a470
  eax = ext_4cbec0_thiscall1(ecx);  // @70_48a470
  ecx = edx = 0;  // @71_48a470
  eax = (u32)(edi + 72);  // @72_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2990), &v, sizeof v); }  // @73_48a470
  PV[3] = (u32)(eax);  // @74_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @75_48a470
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2988), &v, sizeof v); }  // @76_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 68), &v, sizeof v); }  // @77_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 7261), &v, sizeof v); }  // @78_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2796), &v, sizeof v); }  // @79_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2792), &v, sizeof v); }  // @80_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2800), &v, sizeof v); }  // @81_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2804), &v, sizeof v); }  // @82_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2808), &v, sizeof v); }  // @83_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2812), &v, sizeof v); }  // @84_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2780), &v, sizeof v); }  // @85_48a470
  eax = ext_634d10_cdecl3(PV[3], (u32)(0), (u32)(128));  // @86_48a470
  ecx = edx = 0;  // @87_48a470
  eax = (u32)(edi + 3149);  // @88_48a470
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3007), &v, sizeof v); }  // @89_48a470
  PV[4] = (u32)(eax);  // @90_48a470
  eax = ext_634d10_cdecl3(PV[4], (u32)(0), (u32)(4104));  // @91_48a470
  ecx = edx = 0;  // @92_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 7257), &v, sizeof v); }  // @93_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 7253), &v, sizeof v); }  // @94_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23845), &v, sizeof v); }  // @95_48a470
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3009), &v, sizeof v); }  // @96_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @97_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @98_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 200), &v, sizeof v); }  // @99_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23881), &v, sizeof v); }  // @100_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23885), &v, sizeof v); }  // @101_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23889), &v, sizeof v); }  // @102_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23893), &v, sizeof v); }  // @103_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23897), &v, sizeof v); }  // @104_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23901), &v, sizeof v); }  // @105_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23905), &v, sizeof v); }  // @106_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23909), &v, sizeof v); }  // @107_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23913), &v, sizeof v); }  // @108_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23917), &v, sizeof v); }  // @109_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23921), &v, sizeof v); }  // @110_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23925), &v, sizeof v); }  // @111_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23929), &v, sizeof v); }  // @112_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23933), &v, sizeof v); }  // @113_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23937), &v, sizeof v); }  // @114_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23941), &v, sizeof v); }  // @115_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23945), &v, sizeof v); }  // @116_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23949), &v, sizeof v); }  // @117_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23953), &v, sizeof v); }  // @118_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23957), &v, sizeof v); }  // @119_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23961), &v, sizeof v); }  // @120_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 23965), &v, sizeof v); }  // @121_48a470
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 2784), &v, sizeof v); }  // @122_48a470
  eax = ext_41e290_cdecl1((u32)(8));  // @123_48a470
  ecx = edx = 0;  // @124_48a470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @125_48a470
  reg.state = (s32)((u32)(5));  // @126_48a470
  if ((eax & eax) == 0) goto L48a810;  // @127_48a470
  ecx = eax;  // @128_48a470
  eax = ext_49def0_thiscall1(ecx);  // @129_48a470
  ecx = edx = 0;  // @130_48a470
  goto L48a812;  // @131_48a470
  L48a810:;
  eax = 0;  // @133_48a470
  L48a812:;
  ecx = (u32)(edi + 3021);  // @135_48a470
  reg.state = (s32)((u32)(3));  // @136_48a470
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2788), &v, sizeof v); }  // @137_48a470
  eax = ext_4cc1d0_thiscall1(ecx);  // @138_48a470
  ecx = edx = 0;  // @139_48a470
  edx = (u32)(6870984);  // @140_48a470
  ecx = eax;  // @141_48a470
  eax = ext_4cc780_fastcall2(ecx, edx);  // @142_48a470
  ecx = edx = 0;  // @143_48a470
  if ((eax & eax) == 0) goto L48a852;  // @144_48a470
  ecx = (u32)(edi + 3021);  // @145_48a470
  eax = ext_4cc1d0_thiscall1(ecx);  // @146_48a470
  ecx = edx = 0;  // @147_48a470
  edx = (u32)(6870992);  // @148_48a470
  ecx = eax;  // @149_48a470
  eax = ext_4cc780_fastcall2(ecx, edx);  // @150_48a470
  ecx = edx = 0;  // @151_48a470
  if ((eax & eax) != 0) goto L48a859;  // @152_48a470
  L48a852:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 3009), &v, sizeof v); }  // @154_48a470
  L48a859:;
  eax = edi;  // @156_48a470
  SEH_LEAVE();  // @157_48a470
  ext_633654(G(u32, 0x6f5630));  // @158_48a470
  return eax;  // @159_48a470
}
PCREG(48a470, lifted_48a470);



extern "C" u32 THISCALL lifted_4b1ca0(u32 ecx_in) {
  SEH_ENTER(0x668968);  // @h_4b1ca0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4b1ca0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4b1ca0
  eax = ext_469870_thiscall1(ecx);  // @2_4b1ca0
  ecx = edx = 0;  // @3_4b1ca0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4b1ca0
  eax = (u32)(esi + 100);  // @6_4b1ca0
  { u32 v = (u32)((u32)(6889016)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_4b1ca0
  ecx = 0;  // @9_4b1ca0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @10_4b1ca0
  ecx = (u32)(EBP - 20);  // @11_4b1ca0
  reg.state = (s32)((u32)(0));  // @12_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @13_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @14_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @15_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @16_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @17_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @18_4b1ca0
  if (eax == ecx) goto L4b1d2e;  // @19_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @20_4b1ca0
  L4b1d2e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @22_4b1ca0
  { u32 v = (u32)((u32)(65792)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @23_4b1ca0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 388), &v, sizeof v); }  // @24_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @25_4b1ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @26_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6889180), (u32)(3378));  // @30_4b1ca0
  ecx = edx = 0;  // @31_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @32_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6889180), (u32)(3379));  // @36_4b1ca0
  ecx = edx = 0;  // @37_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @38_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @40_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6840116), (u32)(0), (u32)(6889180), (u32)(3380));  // @42_4b1ca0
  ecx = edx = 0;  // @43_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @44_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4b1ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @46_4b1ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4b1ca0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889320), (u32)(0), (u32)(6889180), (u32)(3381));  // @48_4b1ca0
  ecx = edx = 0;  // @49_4b1ca0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @50_4b1ca0
  eax = (u32)(esi + 128);  // @51_4b1ca0
  PV[0] = (u32)(eax);  // @52_4b1ca0
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(256));  // @53_4b1ca0
  ecx = edx = 0;  // @54_4b1ca0
  eax = esi;  // @55_4b1ca0
  SEH_LEAVE();  // @56_4b1ca0
  return eax;  // @57_4b1ca0
}
PCREG(4b1ca0, lifted_4b1ca0);

extern "C" u32 THISCALL lifted_5812c0(u32 ecx_in) {
  SEH_ENTER(0x66c588);  // @h_5812c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5812c0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5812c0
  eax = ext_469870_thiscall1(ecx);  // @2_5812c0
  ecx = edx = 0;  // @3_5812c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5812c0
  reg.state = (s32)((u32)(0));  // @6_5812c0
  edi = (u32)(esi + 157);  // @7_5812c0
  { u32 v = (u32)((u32)(6993488)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @8_5812c0
  ebx = (u32)(5);  // @9_5812c0
  L581313:;
  ecx = edi;  // @11_5812c0
  eax = ext_4e7160_thiscall1(ecx);  // @12_5812c0
  ecx = edx = 0;  // @13_5812c0
  edi = (edi + (u32)(44));  // @14_5812c0
  ebx = (ebx - (u32)(1));  // @15_5812c0
  if (ebx != 0) goto L581313;  // @16_5812c0
  eax = (u32)(esi + 522);  // @17_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 862), &v, sizeof v); }  // @18_5812c0
  PV[0] = (u32)(ebx);  // @19_5812c0
  PV[1] = (u32)(eax);  // @20_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 866), &v, sizeof v); }  // @21_5812c0
  { u32 v = (u32)((u32)(1012560910)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @22_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @23_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @24_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @25_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 878), &v, sizeof v); }  // @26_5812c0
  eax = ext_634d10_cdecl3(PV[1], PV[0], (u32)(340));  // @27_5812c0
  ecx = edx = 0;  // @28_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5812c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }) == ebx) goto L5813a2;  // @30_5812c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 878), &v, sizeof v); }  // @31_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_5812c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @33_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5812c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(6993720));  // @35_5812c0
  ecx = edx = 0;  // @36_5812c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 870), &v, sizeof v); }  // @37_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5812c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @39_5812c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5812c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(6993740));  // @41_5812c0
  ecx = edx = 0;  // @42_5812c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 874), &v, sizeof v); }  // @43_5812c0
  L5813a2:;
  ecx = 0;  // @45_5812c0
  edx = (u32)(esi + 377);  // @46_5812c0
  eax = (u32)(esi + 466);  // @47_5812c0
  L5813b0:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @49_5812c0
  edx = (u32)(edx + 4);  // @50_5812c0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + ecx + 457), &v, sizeof v); }  // @51_5812c0
  eax = (u32)(eax + 12);  // @52_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 8), &v, sizeof v); }  // @53_5812c0
  ecx = (ecx + 1);  // @54_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 12), &v, sizeof v); }  // @55_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 16), &v, sizeof v); }  // @56_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 73), &v, sizeof v); }  // @57_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 77), &v, sizeof v); }  // @58_5812c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 81), &v, sizeof v); }  // @59_5812c0
  if (ecx < (u32)(5)) goto L5813b0;  // @60_5812c0
  eax = esi;  // @61_5812c0
  SEH_LEAVE();  // @62_5812c0
  return eax;  // @63_5812c0
}
PCREG(5812c0, lifted_5812c0);

extern "C" u32 THISCALL lifted_4bdf20(u32 ecx_in) {
  SEH_ENTER(0x66c468);  // @h_4bdf20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4bdf20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4bdf20
  eax = ext_469870_thiscall1(ecx);  // @2_4bdf20
  ecx = edx = 0;  // @3_4bdf20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_4bdf20
  { u32 v = (u32)((u32)(6895992)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @7_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_4bdf20
  reg.state = (s32)((u32)(0));  // @10_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892948), (u32)(0), (u32)(6896704), (u32)(2657));  // @12_4bdf20
  ecx = edx = 0;  // @13_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @14_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892972), (u32)(0), (u32)(6896704), (u32)(2658));  // @18_4bdf20
  ecx = edx = 0;  // @19_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @20_4bdf20
  { u32 v = (u32)((u32)(257)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @21_4bdf20
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @22_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 85), &v, sizeof v); }  // @23_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @24_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @25_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @26_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 101), &v, sizeof v); }  // @27_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }  // @28_4bdf20
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @29_4bdf20
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @30_4bdf20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @31_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @32_4bdf20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 124), &v, sizeof v); }  // @33_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891112), (u32)(0), (u32)(6896704), (u32)(2676));  // @37_4bdf20
  ecx = edx = 0;  // @38_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @39_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4bdf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_4bdf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4bdf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6891132), (u32)(0), (u32)(6896704), (u32)(2677));  // @43_4bdf20
  ecx = edx = 0;  // @44_4bdf20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @45_4bdf20
  eax = (u32)(esi + 128);  // @46_4bdf20
  PV[0] = (u32)(eax);  // @47_4bdf20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 384), &v, sizeof v); }  // @48_4bdf20
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(256));  // @49_4bdf20
  ecx = edx = 0;  // @50_4bdf20
  eax = esi;  // @51_4bdf20
  SEH_LEAVE();  // @52_4bdf20
  return eax;  // @53_4bdf20
}
PCREG(4bdf20, lifted_4bdf20);

extern "C" u32 THISCALL lifted_442050(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665e4f);  // @h_442050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_442050
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; }) != (u32)(0)) goto L4420dd;  // @1_442050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338344), sizeof v); (u32)v; });  // @2_442050
  if ((ecx & ecx) != 0) goto L4420c0;  // @3_442050
  eax = ext_41e290_cdecl1((u32)(40));  // @4_442050
  ecx = edx = 0;  // @5_442050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_442050
  reg.state = (s32)((u32)(0));  // @7_442050
  if ((eax & eax) == 0) goto L4420b1;  // @8_442050
  ecx = eax;  // @9_442050
  eax = ext_4cca60_thiscall3(ecx, (u32)(1), (u32)(288));  // @10_442050
  ecx = edx = 0;  // @11_442050
  ecx = eax;  // @12_442050
  goto L4420b3;  // @13_442050
  L4420b1:;
  ecx = 0;  // @15_442050
  L4420b3:;
  reg.state = (s32)((u32)(4294967295));  // @17_442050
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7338344), &v, sizeof v); }  // @18_442050
  L4420c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_442050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @21_442050
  ecx = edx = 0;  // @22_442050
  eax = (eax + (u32)(-4));  // @23_442050
  PV[0] = (u32)(eax);  // @24_442050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @25_442050
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(1156));  // @26_442050
  ecx = edx = 0;  // @27_442050
  L4420dd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @29_442050
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_442050
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_442050
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 4), &v, sizeof v); }  // @32_442050
  ecx = esi;  // @33_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @34_442050
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @35_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 784), sizeof v); (u32)v; });  // @37_442050
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @38_442050
  ecx = edx = 0;  // @39_442050
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L442136;  // @40_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_442050
  ecx = esi;  // @42_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 776), sizeof v); (u32)v; });  // @43_442050
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @44_442050
  ecx = edx = 0;  // @45_442050
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L442136;  // @46_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_442050
  ecx = esi;  // @48_442050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @49_442050
  ecx = edx = 0;  // @50_442050
  if ((eax & eax) == 0) goto L442136;  // @51_442050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_442050
  ecx = esi;  // @53_442050
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @54_442050
  ecx = edx = 0;  // @55_442050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @56_442050
  eax = ext_4db7e0_thiscall1(ecx);  // @57_442050
  ecx = edx = 0;  // @58_442050
  if ((eax & eax) == 0) goto L442136;  // @59_442050
  PV[1] = (u32)(edi);  // @60_442050
  ecx = eax;  // @61_442050
  eax = ext_442050_thiscall2(ecx, PV[1]);  // @62_442050
  ecx = edx = 0;  // @63_442050
  L442136:;
  SEH_LEAVE();  // @65_442050
  return eax;  // @66_442050
}
PCREG(442050, lifted_442050);

extern "C" u32 THISCALL lifted_452ed0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666568);  // @h_452ed0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_452ed0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_452ed0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_452ed0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_452ed0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_452ed0
  eax = ext_43de40_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @5_452ed0
  ecx = edx = 0;  // @6_452ed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @7_452ed0
  eax = (u32)(65535);  // @8_452ed0
  reg.state = (s32)((u32)(0));  // @9_452ed0
  { u32 v = (u32)((u32)(6822692)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @10_452ed0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @11_452ed0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @12_452ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @13_452ed0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @14_452ed0
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @15_452ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @16_452ed0
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @17_452ed0
  eax = ext_4dc630_thiscall3(ecx, (u32)(4194304), (u32)(0));  // @18_452ed0
  ecx = edx = 0;  // @19_452ed0
  eax = (u32)(esi + 34);  // @20_452ed0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @21_452ed0
  PV[3] = (u32)(eax);  // @22_452ed0
  eax = ext_634d10_cdecl3(PV[3], (u32)(0), (u32)(48));  // @23_452ed0
  ecx = edx = 0;  // @24_452ed0
  eax = esi;  // @25_452ed0
  SEH_LEAVE();  // @26_452ed0
  return eax;  // @27_452ed0
}
PCREG(452ed0, lifted_452ed0);

