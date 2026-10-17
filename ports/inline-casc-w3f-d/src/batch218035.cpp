// batch218035.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4d3f10_thiscall3(u32, u32, u32) __asm__("ext_4d3f10");
extern "C" u32 THISCALL ext_4d4300_thiscall2(u32, u32) __asm__("ext_4d4300");
extern "C" u32 THISCALL ext_4d4540_thiscall1(u32) __asm__("ext_4d4540");
extern "C" u32 THISCALL ext_4d4960_thiscall1(u32) __asm__("ext_4d4960");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4d45f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66945f);  // @h_4d45f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4d45f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4d45f0
  FL[2] = (eax & eax);  // @2_4d45f0
  ecx = (u32)(eax + 1);  // @3_4d45f0
  if (FL[2] != 0) ecx = eax;  // @4_4d45f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_4d45f0
  FL[0] = eax; FL[1] = (u32)(9);  // @6_4d45f0
  if (FL[0] == FL[1]) goto L4d463a;  // @7_4d45f0
  FL[0] = eax; FL[1] = (u32)(16);  // @8_4d45f0
  if (FL[0] == FL[1]) goto L4d463a;  // @9_4d45f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4331), &v, sizeof v); }  // @10_4d45f0
  L4d463a:;
  eax = (eax + (u32)(-8));  // @12_4d45f0
  FL[3] = eax;  // @13_4d45f0
  FL[0] = eax; FL[1] = (u32)(38);  // @14_4d45f0
  if (FL[0] > FL[1]) goto L4d48dc;  // @15_4d45f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5064984), sizeof v); (u32)v; });  // @16_4d45f0
  switch (eax) {  // @17_4d45f0
  case 0: goto L4d466f;  // @18_4d45f0
  case 1: goto L4d477f;  // @19_4d45f0
  case 2: goto L4d4654;  // @20_4d45f0
  case 3: goto L4d46b3;  // @21_4d45f0
  case 4: goto L4d46cb;  // @22_4d45f0
  case 5: goto L4d4753;  // @23_4d45f0
  case 6: goto L4d472a;  // @24_4d45f0
  case 7: goto L4d46f0;  // @25_4d45f0
  case 8: goto L4d470d;  // @26_4d45f0
  case 9: goto L4d48dc;  // @27_4d45f0
  default: __builtin_trap(); }  // @28_4d45f0
  L4d4654:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_4d45f0
  ecx = esi;  // @31_4d45f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 28)))(ecx);  // @32_4d45f0
  ecx = edx = 0;  // @33_4d45f0
  SEH_LEAVE();  // @34_4d45f0
  return eax;  // @35_4d45f0
  L4d466f:;
  FL[2] = (ecx & ecx);  // @37_4d45f0
  if (FL[2] == 0) goto L4d48dc;  // @38_4d45f0
  L4d4680:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4303), sizeof v); (u32)v; });  // @40_4d45f0
  ecx = (ecx - 1);  // @41_4d45f0
  FL[3] = ecx;  // @42_4d45f0
  FL[0] = eax; FL[1] = (u32)(1);  // @43_4d45f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4d469b;  // @44_4d45f0
  eax = (eax - 1);  // @45_4d45f0
  FL[3] = eax;  // @46_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4303), &v, sizeof v); }  // @47_4d45f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + esi + 4103), &v, sizeof v); }  // @48_4d45f0
  L4d469b:;
  FL[2] = (ecx & ecx);  // @50_4d45f0
  if (FL[2] != 0) goto L4d4680;  // @51_4d45f0
  SEH_LEAVE();  // @52_4d45f0
  return eax;  // @53_4d45f0
  L4d46b3:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @55_4d45f0
  SEH_LEAVE();  // @56_4d45f0
  return eax;  // @57_4d45f0
  L4d46cb:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4303), &v, sizeof v); }  // @59_4d45f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4104), &v, sizeof v); }  // @60_4d45f0
  SEH_LEAVE();  // @61_4d45f0
  return eax;  // @62_4d45f0
  L4d46f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @64_4d45f0
  ecx = esi;  // @65_4d45f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @66_4d45f0
  ecx = edx = 0;  // @67_4d45f0
  SEH_LEAVE();  // @68_4d45f0
  return eax;  // @69_4d45f0
  L4d470d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @71_4d45f0
  ecx = esi;  // @72_4d45f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(1));  // @73_4d45f0
  ecx = edx = 0;  // @74_4d45f0
  SEH_LEAVE();  // @75_4d45f0
  return eax;  // @76_4d45f0
  L4d472a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4019), sizeof v); (u32)v; });  // @78_4d45f0
  FL[2] = (eax & eax);  // @79_4d45f0
  if (FL[2] == 0) goto L4d48dc;  // @80_4d45f0
  eax = (eax + 1);  // @81_4d45f0
  FL[3] = eax;  // @82_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4019), &v, sizeof v); }  // @83_4d45f0
  SEH_LEAVE();  // @84_4d45f0
  return eax;  // @85_4d45f0
  L4d4753:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4019), sizeof v); (u32)v; });  // @87_4d45f0
  FL[0] = eax; FL[1] = (u32)(4294966296);  // @88_4d45f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4d48dc;  // @89_4d45f0
  eax = (eax - 1);  // @90_4d45f0
  FL[3] = eax;  // @91_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4019), &v, sizeof v); }  // @92_4d45f0
  SEH_LEAVE();  // @93_4d45f0
  return eax;  // @94_4d45f0
  L4d477f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4331), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_4d45f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4336), sizeof v); (u32)v; });  // @97_4d45f0
  if (FL[0] != FL[1]) goto L4d4870;  // @98_4d45f0
  FL[2] = (ecx & ecx);  // @99_4d45f0
  if (FL[2] == 0) goto L4d479c;  // @100_4d45f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @101_4d45f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @102_4d45f0
  ecx = edx = 0;  // @103_4d45f0
  L4d479c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4315), sizeof v); (u32)v; });  // @105_4d45f0
  ecx = (u32)(esi + 4315);  // @106_4d45f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @107_4d45f0
  ecx = edx = 0;  // @108_4d45f0
  ecx = eax;  // @109_4d45f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_4d45f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @111_4d45f0
  ecx = edx = 0;  // @112_4d45f0
  ecx = 0;  // @113_4d45f0
  FL[3] = ecx;  // @114_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @115_4d45f0
  edx = (u32)(4);  // @116_4d45f0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @117_4d45f0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @118_4d45f0
  FL[1] = ecx;  // @119_4d45f0
  ecx = (0u - ecx);  // @120_4d45f0
  ecx = (ecx | eax);  // @121_4d45f0
  FL[3] = ecx;  // @122_4d45f0
  PV[0] = (u32)(ecx);  // @123_4d45f0
  eax = ext_41e290_cdecl1(PV[0]);  // @124_4d45f0
  ecx = edx = 0;  // @125_4d45f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4315), sizeof v); (u32)v; });  // @126_4d45f0
  ecx = (u32)(esi + 4315);  // @127_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @128_4d45f0
  ebx = eax;  // @129_4d45f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 16)))(ecx);  // @130_4d45f0
  ecx = edx = 0;  // @131_4d45f0
  edi = eax;  // @132_4d45f0
  FL[2] = (edi & edi);  // @133_4d45f0
  if (FL[2] == 0) goto L4d481a;  // @134_4d45f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @135_4d45f0
  eax = (u32)(EBP - 28);  // @136_4d45f0
  PV[1] = (u32)(eax);  // @137_4d45f0
  ecx = edi;  // @138_4d45f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[1]);  // @139_4d45f0
  ecx = edx = 0;  // @140_4d45f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @141_4d45f0
  ecx = (u32)(EBP - 28);  // @142_4d45f0
  PV[2] = (u32)(ecx);  // @143_4d45f0
  ecx = edi;  // @144_4d45f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @145_4d45f0
  ecx = edx = 0;  // @146_4d45f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @147_4d45f0
  if (FL[0] == FL[1]) goto L4d481a;  // @148_4d45f0
  L4d4804:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @150_4d45f0
  ecx = (u32)(EBP - 28);  // @151_4d45f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @152_4d45f0
  ebx = (u32)(ebx + 4);  // @153_4d45f0
  PV[3] = (u32)(ecx);  // @154_4d45f0
  ecx = edi;  // @155_4d45f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @156_4d45f0
  ecx = edx = 0;  // @157_4d45f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @158_4d45f0
  if (FL[0] != FL[1]) goto L4d4804;  // @159_4d45f0
  L4d481a:;
  eax = ext_41e290_cdecl1((u32)(20));  // @161_4d45f0
  ecx = edx = 0;  // @162_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @163_4d45f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @164_4d45f0
  reg.state = (s32)((u32)(0));  // @165_4d45f0
  FL[2] = (eax & eax);  // @166_4d45f0
  if (FL[2] == 0) goto L4d4842;  // @167_4d45f0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @168_4d45f0
  ecx = eax;  // @169_4d45f0
  PV[5] = (u32)(edi);  // @170_4d45f0
  eax = ext_4d3f10_thiscall3(ecx, PV[5], PV[4]);  // @171_4d45f0
  ecx = edx = 0;  // @172_4d45f0
  goto L4d4844;  // @173_4d45f0
  L4d4842:;
  eax = 0;  // @175_4d45f0
  FL[3] = eax;  // @176_4d45f0
  L4d4844:;
  PV[6] = (u32)(edi);  // @178_4d45f0
  reg.state = (s32)((u32)(4294967295));  // @179_4d45f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4336), &v, sizeof v); }  // @180_4d45f0
  eax = ext_634273_cdecl2(PV[6], (u32)(4));  // @181_4d45f0
  ecx = edx = 0;  // @182_4d45f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4336), sizeof v); (u32)v; });  // @183_4d45f0
  eax = (u32)(esi + 4104);  // @184_4d45f0
  PV[7] = (u32)(eax);  // @185_4d45f0
  eax = ext_4d4300_thiscall2(ecx, PV[7]);  // @186_4d45f0
  ecx = edx = 0;  // @187_4d45f0
  goto L4d4882;  // @188_4d45f0
  L4d4870:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @190_4d45f0
  if (FL[0] != FL[1]) goto L4d487d;  // @191_4d45f0
  eax = ext_4d4540_thiscall1(ecx);  // @192_4d45f0
  ecx = edx = 0;  // @193_4d45f0
  goto L4d4882;  // @194_4d45f0
  L4d487d:;
  eax = ext_4d4960_thiscall1(ecx);  // @196_4d45f0
  ecx = edx = 0;  // @197_4d45f0
  L4d4882:;
  ecx = eax;  // @199_4d45f0
  FL[2] = (ecx & ecx);  // @200_4d45f0
  if (FL[2] == 0) goto L4d48d5;  // @201_4d45f0
  edx = esi;  // @202_4d45f0
  edx = (edx - ecx);  // @203_4d45f0
  FL[3] = edx;  // @204_4d45f0
  L4d4890:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @206_4d45f0
  ecx = (u32)(ecx + 1);  // @207_4d45f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx + 4103), &v, sizeof v); }  // @208_4d45f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @209_4d45f0
  if (FL[2] != 0) goto L4d4890;  // @210_4d45f0
  ecx = (u32)(esi + 4103);  // @211_4d45f0
  edi = (u32)(ecx - 1);  // @212_4d45f0
  L4d48b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @214_4d45f0
  edi = (u32)(edi + 1);  // @215_4d45f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @216_4d45f0
  if (FL[2] != 0) goto L4d48b0;  // @217_4d45f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6790764), sizeof v); (u32)v; })) & 0xffff);  // @218_4d45f0
  edx = (u32)(ecx + 1);  // @219_4d45f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @220_4d45f0
  L4d48c6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @222_4d45f0
  ecx = (ecx + 1);  // @223_4d45f0
  FL[3] = ecx;  // @224_4d45f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @225_4d45f0
  if (FL[2] != 0) goto L4d48c6;  // @226_4d45f0
  ecx = (ecx - edx);  // @227_4d45f0
  FL[3] = ecx;  // @228_4d45f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 4303), &v, sizeof v); }  // @229_4d45f0
  L4d48d5:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4331), &v, sizeof v); }  // @231_4d45f0
  L4d48dc:;
  SEH_LEAVE();  // @233_4d45f0
  return eax;  // @234_4d45f0
}
PCREG(4d45f0, lifted_4d45f0);

