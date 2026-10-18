// batch218041.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42ae00_fastcall3(u32, u32, u32) __asm__("ext_42ae00");
extern "C" u32 FASTCALL ext_42aee0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42aee0");
extern "C" u32 FASTCALL ext_42b1e0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_42b1e0");
extern "C" u32 FASTCALL ext_4309b0_fastcall3(u32, u32, u32) __asm__("ext_4309b0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_4301c0_thiscall3(u32, u32, u32) __asm__("ext_4301c0");
extern "C" u32 THISCALL ext_4302d0_thiscall3(u32, u32, u32) __asm__("ext_4302d0");
extern "C" u32 THISCALL ext_430c70_thiscall3(u32, u32, u32) __asm__("ext_430c70");
extern "C" u32 THISCALL ext_430d10_thiscall4(u32, u32, u32, u32) __asm__("ext_430d10");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_42e6f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6650ba);  // @h_42e6f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7017), sizeof v); (u32)v; });  // @1_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @3_42e6f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_42e6f0
  if (FL[0] == FL[1]) goto L42e788;  // @5_42e6f0
  L42e730:;
  edx = esi;  // @7_42e6f0
  ecx = (u32)(EBP - 76);  // @8_42e6f0
  eax = ext_42ae00_fastcall3(ecx, edx, (u32)(6777860));  // @9_42e6f0
  ecx = edx = 0;  // @10_42e6f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @11_42e6f0
  ecx = ebx;  // @12_42e6f0
  reg.state = (s32)((u32)(0));  // @13_42e6f0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_42e6f0
  eax = ext_5f2c60_thiscall3(ecx, PV[1], PV[0]);  // @15_42e6f0
  ecx = edx = 0;  // @16_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @17_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @18_42e6f0
  eax = (eax - ecx);  // @19_42e6f0
  FL[3] = eax;  // @20_42e6f0
  reg.state = (s32)((u32)(1));  // @21_42e6f0
  FL[2] = (ecx & ecx);  // @22_42e6f0
  if (FL[2] == 0) goto L42e773;  // @23_42e6f0
  FL[2] = (eax & eax);  // @24_42e6f0
  if (FL[2] == 0) goto L42e773;  // @25_42e6f0
  PV[2] = (u32)(eax);  // @26_42e6f0
  PV[3] = (u32)(ecx);  // @27_42e6f0
  ecx = (u32)(EBP - 76);  // @28_42e6f0
  eax = ext_54f870_stdcall2(PV[3], PV[2]);  // @29_42e6f0
  ecx = edx = 0;  // @30_42e6f0
  L42e773:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7017), sizeof v); (u32)v; });  // @32_42e6f0
  esi = (esi + (u32)(12));  // @33_42e6f0
  FL[3] = esi;  // @34_42e6f0
  reg.state = (s32)((u32)(4294967295));  // @35_42e6f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @36_42e6f0
  if (FL[0] != FL[1]) goto L42e730;  // @37_42e6f0
  L42e788:;
  ecx = (u32)(EBP - 52);  // @39_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @40_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @41_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @42_42e6f0
  eax = ext_6014a0_stdcall1((u32)(8));  // @43_42e6f0
  ecx = edx = 0;  // @44_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @45_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @46_42e6f0
  ecx = (u32)(eax + 8);  // @47_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @48_42e6f0
  FL[2] = (eax & eax);  // @49_42e6f0
  if (FL[2] == 0) goto L42e7ba;  // @50_42e6f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @51_42e6f0
  L42e7ba:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @53_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @54_42e6f0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @55_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @56_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @57_42e6f0
  edx = ecx;  // @58_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @59_42e6f0
  PV[5] = (u32)(eax);  // @60_42e6f0
  reg.state = (s32)((u32)(2));  // @61_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @62_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @63_42e6f0
  eax = ext_42aee0_fastcall5(ecx, edx, PV[5], PV[4], (u32)(0));  // @64_42e6f0
  ecx = edx = 0;  // @65_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @66_42e6f0
  esi = eax;  // @67_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @68_42e6f0
  FL[0] = esi; FL[1] = eax;  // @69_42e6f0
  if (FL[0] == FL[1]) goto L42e820;  // @70_42e6f0
  ebx = eax;  // @71_42e6f0
  L42e7f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @73_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @74_42e6f0
  eax = (eax - ecx);  // @75_42e6f0
  FL[3] = eax;  // @76_42e6f0
  reg.state = (s32)((u32)(3));  // @77_42e6f0
  FL[2] = (ecx & ecx);  // @78_42e6f0
  if (FL[2] == 0) goto L42e80f;  // @79_42e6f0
  FL[2] = (eax & eax);  // @80_42e6f0
  if (FL[2] == 0) goto L42e80f;  // @81_42e6f0
  PV[6] = (u32)(eax);  // @82_42e6f0
  PV[7] = (u32)(ecx);  // @83_42e6f0
  ecx = esi;  // @84_42e6f0
  eax = ext_54f870_stdcall2(PV[7], PV[6]);  // @85_42e6f0
  ecx = edx = 0;  // @86_42e6f0
  L42e80f:;
  esi = (esi + (u32)(12));  // @88_42e6f0
  FL[3] = esi;  // @89_42e6f0
  reg.state = (s32)((u32)(2));  // @90_42e6f0
  FL[0] = esi; FL[1] = ebx;  // @91_42e6f0
  if (FL[0] != FL[1]) goto L42e7f3;  // @92_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @93_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @94_42e6f0
  L42e820:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @96_42e6f0
  eax = (u32)(3579139413);  // @97_42e6f0
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @98_42e6f0
  FL[3] = edx;  // @99_42e6f0
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @100_42e6f0
  edx = (u32)((s32)edx >> (u32)(1));  // @101_42e6f0
  FL[3] = edx;  // @102_42e6f0
  eax = edx;  // @103_42e6f0
  eax = (eax >> (u32)(31));  // @104_42e6f0
  FL[3] = eax;  // @105_42e6f0
  eax = (eax + edx);  // @106_42e6f0
  FL[3] = eax;  // @107_42e6f0
  eax = (u32)(eax + eax*2);  // @108_42e6f0
  eax = (eax << (u32)(2));  // @109_42e6f0
  FL[3] = eax;  // @110_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @111_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @112_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @113_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @114_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @115_42e6f0
  if (FL[0] == FL[1]) goto L42e9c0;  // @116_42e6f0
  L42e850:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @118_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @119_42e6f0
  ecx = (u32)(EBP - 20);  // @120_42e6f0
  PV[9] = (u32)(ecx);  // @121_42e6f0
  ecx = (u32)(EBP - 52);  // @122_42e6f0
  PV[10] = (u32)(ecx);  // @123_42e6f0
  ecx = edi;  // @124_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[10], PV[9], PV[8]);  // @125_42e6f0
  ecx = edx = 0;  // @126_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @127_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @128_42e6f0
  FL[0] = ecx; FL[1] = edx;  // @129_42e6f0
  if (FL[0] == FL[1]) goto L42e9b4;  // @130_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @131_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @133_42e6f0
  if (FL[0] == FL[1]) goto L42e8b0;  // @134_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @135_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 12), sizeof v); (u32)v; });  // @136_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 8), sizeof v); (u32)v; });  // @137_42e6f0
  eax = (eax - ebx);  // @138_42e6f0
  FL[3] = eax;  // @139_42e6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @140_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @141_42e6f0
  FL[0] = eax; FL[1] = (u32)(1);  // @142_42e6f0
  if (FL[0] != FL[1]) goto L42e8b0;  // @143_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @144_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @145_42e6f0
  if (FL[0] != FL[1]) goto L42e8b0;  // @146_42e6f0
  eax = edx;  // @147_42e6f0
  eax = (eax - ecx);  // @148_42e6f0
  FL[3] = eax;  // @149_42e6f0
  FL[0] = eax; FL[1] = (u32)(1);  // @150_42e6f0
  if (FL[0] != FL[1]) goto L42e8b0;  // @151_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @152_42e6f0
  if (FL[0] == FL[1]) goto L42e9b4;  // @153_42e6f0
  L42e8b0:;
  edx = (edx - ecx);  // @155_42e6f0
  FL[3] = edx;  // @156_42e6f0
  FL[0] = edx; FL[1] = (u32)(1);  // @157_42e6f0
  if (FL[0] != FL[1]) goto L42e908;  // @158_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(36);  // @159_42e6f0
  if (FL[0] != FL[1]) goto L42e908;  // @160_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @161_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @162_42e6f0
  if (FL[0] == FL[1]) goto L42e8e7;  // @163_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @164_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @165_42e6f0
  reg.state = (s32)((u32)(4));  // @166_42e6f0
  FL[2] = (eax & eax);  // @167_42e6f0
  if (FL[2] == 0) goto L42e8dd;  // @168_42e6f0
  ecx = (u32)(EBP - 52);  // @169_42e6f0
  PV[11] = (u32)(ecx);  // @170_42e6f0
  ecx = eax;  // @171_42e6f0
  eax = ext_5f10c0_thiscall2(ecx, PV[11]);  // @172_42e6f0
  ecx = edx = 0;  // @173_42e6f0
  L42e8dd:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @175_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @176_42e6f0
  reg.state = (s32)((u32)(2));  // @177_42e6f0
  goto L42e8f3;  // @178_42e6f0
  L42e8e7:;
  ecx = (u32)(EBP - 52);  // @180_42e6f0
  PV[12] = (u32)(ecx);  // @181_42e6f0
  PV[13] = (u32)(eax);  // @182_42e6f0
  ecx = esi;  // @183_42e6f0
  eax = ext_4302d0_thiscall3(ecx, PV[13], PV[12]);  // @184_42e6f0
  ecx = edx = 0;  // @185_42e6f0
  L42e8f3:;
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @187_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @188_42e6f0
  ecx = (u32)(EBP - 20);  // @189_42e6f0
  PV[15] = (u32)(ecx);  // @190_42e6f0
  ecx = (u32)(EBP - 52);  // @191_42e6f0
  PV[16] = (u32)(ecx);  // @192_42e6f0
  ecx = edi;  // @193_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[16], PV[15], PV[14]);  // @194_42e6f0
  ecx = edx = 0;  // @195_42e6f0
  L42e908:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @197_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @198_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @199_42e6f0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @200_42e6f0
  if (FL[0] == FL[1]) goto L42e9a5;  // @201_42e6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @202_42e6f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @203_42e6f0
  FL[2] = (ebx & ebx);  // @204_42e6f0
  if (FL[2] == 0) goto L42e99b;  // @205_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @206_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @207_42e6f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @208_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @209_42e6f0
  esi = edx;  // @210_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @211_42e6f0
  esi = (esi - ecx);  // @212_42e6f0
  FL[3] = esi;  // @213_42e6f0
  esi = (esi + 1);  // @214_42e6f0
  FL[3] = esi;  // @215_42e6f0
  reg.state = (s32)((u32)(6));  // @216_42e6f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @217_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @218_42e6f0
  FL[0] = esi; FL[1] = (u32)(-2);  // @219_42e6f0
  if (FL[0] > FL[1]) goto L42e975;  // @220_42e6f0
  FL[2] = (esi & esi);  // @221_42e6f0
  if (FL[2] != 0) goto L42e95d;  // @222_42e6f0
  eax = 0;  // @223_42e6f0
  FL[3] = eax;  // @224_42e6f0
  goto L42e96b;  // @225_42e6f0
  L42e95d:;
  PV[17] = (u32)(esi);  // @227_42e6f0
  ecx = ebx;  // @228_42e6f0
  eax = ext_6014a0_stdcall1(PV[17]);  // @229_42e6f0
  ecx = edx = 0;  // @230_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @231_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @232_42e6f0
  L42e96b:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @234_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @235_42e6f0
  eax = (eax + esi);  // @236_42e6f0
  FL[3] = eax;  // @237_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @238_42e6f0
  L42e975:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @240_42e6f0
  edx = (edx - ecx);  // @241_42e6f0
  FL[3] = edx;  // @242_42e6f0
  PV[18] = (u32)(edx);  // @243_42e6f0
  PV[19] = (u32)(ecx);  // @244_42e6f0
  PV[20] = (u32)(esi);  // @245_42e6f0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))(PV[20], PV[19], PV[18]);  // @246_42e6f0
  ecx = edx = 0;  // @247_42e6f0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @248_42e6f0
  FL[3] = esi;  // @249_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @250_42e6f0
  eax = (eax + esi);  // @251_42e6f0
  FL[3] = eax;  // @252_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @253_42e6f0
  if (FL[3] == 0) goto L42e995;  // @254_42e6f0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @255_42e6f0
  L42e995:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @257_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @258_42e6f0
  L42e99b:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @260_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @261_42e6f0
  reg.state = (s32)((u32)(2));  // @262_42e6f0
  goto L42e9b1;  // @263_42e6f0
  L42e9a5:;
  ecx = (u32)(EBP - 52);  // @265_42e6f0
  PV[21] = (u32)(ecx);  // @266_42e6f0
  PV[22] = (u32)(ebx);  // @267_42e6f0
  ecx = eax;  // @268_42e6f0
  eax = ext_4302d0_thiscall3(ecx, PV[22], PV[21]);  // @269_42e6f0
  ecx = edx = 0;  // @270_42e6f0
  L42e9b1:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @272_42e6f0
  L42e9b4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @274_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = eax;  // @275_42e6f0
  if (FL[0] != FL[1]) goto L42e850;  // @276_42e6f0
  L42e9c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7009), sizeof v); (u32)v; });  // @278_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @279_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @280_42e6f0
  edx = esi;  // @281_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @282_42e6f0
  edx = (edx - esi);  // @283_42e6f0
  FL[3] = edx;  // @284_42e6f0
  edx = (u32)((s32)edx >> (u32)(2));  // @285_42e6f0
  FL[3] = edx;  // @286_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @287_42e6f0
  FL[2] = (edx & edx);  // @288_42e6f0
  if ((s32)FL[2] <= 0) goto L42e9f4;  // @289_42e6f0
  ebx = esi;  // @290_42e6f0
  ebx = (ebx - ecx);  // @291_42e6f0
  FL[3] = ebx;  // @292_42e6f0
  L42e9e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx), sizeof v); (u32)v; });  // @294_42e6f0
  ecx = (u32)(ecx + 4);  // @295_42e6f0
  edx = (edx - 1);  // @296_42e6f0
  FL[3] = edx;  // @297_42e6f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @298_42e6f0
  FL[2] = (edx & edx);  // @299_42e6f0
  if ((s32)FL[2] > 0) goto L42e9e0;  // @300_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @301_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @302_42e6f0
  L42e9f4:;
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @304_42e6f0
  FL[3] = esi;  // @305_42e6f0
  esi = (u32)((s32)esi >> (u32)(2));  // @306_42e6f0
  FL[3] = esi;  // @307_42e6f0
  FL[1] = esi;  // @308_42e6f0
  esi = (0u - esi);  // @309_42e6f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @310_42e6f0
  esi = (esi << (u32)(2));  // @311_42e6f0
  FL[3] = esi;  // @312_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @313_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @314_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7009), sizeof v); (u32)v; });  // @315_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @316_42e6f0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @317_42e6f0
  if (FL[0] == FL[1]) goto L42ea27;  // @318_42e6f0
  FL[2] = (eax & eax);  // @319_42e6f0
  if (FL[2] == 0) goto L42ea21;  // @320_42e6f0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @321_42e6f0
  L42ea21:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @323_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @324_42e6f0
  goto L42ea31;  // @325_42e6f0
  L42ea27:;
  edx = (u32)(EBP - 36);  // @327_42e6f0
  PV[23] = (u32)(edx);  // @328_42e6f0
  PV[24] = (u32)(eax);  // @329_42e6f0
  eax = ext_4301c0_thiscall3(ecx, PV[24], PV[23]);  // @330_42e6f0
  ecx = edx = 0;  // @331_42e6f0
  L42ea31:;
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @333_42e6f0
  eax = ext_634d22_cdecl3(PV[25], (u32)(6781786), (u32)(0));  // @334_42e6f0
  ecx = edx = 0;  // @335_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @336_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @337_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @338_42e6f0
  FL[0] = ecx; FL[1] = esi;  // @339_42e6f0
  if (FL[0] == FL[1]) goto L42ea67;  // @340_42e6f0
  eax = esi;  // @341_42e6f0
  eax = (eax - esi);  // @342_42e6f0
  FL[3] = eax;  // @343_42e6f0
  eax = (eax + 1);  // @344_42e6f0
  FL[3] = eax;  // @345_42e6f0
  PV[26] = (u32)(eax);  // @346_42e6f0
  PV[27] = (u32)(esi);  // @347_42e6f0
  PV[28] = (u32)(ecx);  // @348_42e6f0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676278))(PV[28], PV[27], PV[26]);  // @349_42e6f0
  ecx = edx = 0;  // @350_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @351_42e6f0
  eax = (eax - esi);  // @352_42e6f0
  FL[3] = eax;  // @353_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @354_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @355_42e6f0
  L42ea67:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @357_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @358_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @359_42e6f0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @360_42e6f0
  if (FL[0] == FL[1]) goto L42ebe9;  // @361_42e6f0
  L42ea80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @363_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @364_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @365_42e6f0
  ebx = (ebx - esi);  // @366_42e6f0
  FL[3] = ebx;  // @367_42e6f0
  FL[0] = ebx; FL[1] = (u32)(6);  // @368_42e6f0
  if (FL[0] != FL[1]) goto L42eab2;  // @369_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1684433187);  // @370_42e6f0
  if (FL[0] != FL[1]) goto L42eab2;  // @371_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(26213);  // @372_42e6f0
  if (FL[0] != FL[1]) goto L42eab2;  // @373_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @374_42e6f0
  ecx = (u32)(EBP - 16);  // @375_42e6f0
  PV[29] = (u32)(ecx);  // @376_42e6f0
  ecx = edi;  // @377_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, PV[29]);  // @378_42e6f0
  ecx = edx = 0;  // @379_42e6f0
  goto L42ebd4;  // @380_42e6f0
  L42eab2:;
  FL[0] = ebx; FL[1] = (u32)(7);  // @382_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @383_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1852205347);  // @384_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @385_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(25956);  // @386_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @387_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; }); FL[1] = (u32)(102);  // @388_42e6f0
  if (FL[0] != FL[1]) goto L42eae0;  // @389_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @390_42e6f0
  ecx = (u32)(EBP - 16);  // @391_42e6f0
  PV[30] = (u32)(ecx);  // @392_42e6f0
  ecx = edi;  // @393_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 148)))(ecx, PV[30]);  // @394_42e6f0
  ecx = edx = 0;  // @395_42e6f0
  goto L42ebd4;  // @396_42e6f0
  L42eae0:;
  FL[0] = ebx; FL[1] = (u32)(5);  // @398_42e6f0
  if (FL[0] != FL[1]) goto L42eb06;  // @399_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1936483619);  // @400_42e6f0
  if (FL[0] != FL[1]) goto L42eb06;  // @401_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(101);  // @402_42e6f0
  if (FL[0] != FL[1]) goto L42eb06;  // @403_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @404_42e6f0
  ecx = (u32)(EBP - 16);  // @405_42e6f0
  PV[31] = (u32)(ecx);  // @406_42e6f0
  ecx = edi;  // @407_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[31]);  // @408_42e6f0
  ecx = edx = 0;  // @409_42e6f0
  goto L42ebd4;  // @410_42e6f0
  L42eb06:;
  FL[0] = ebx; FL[1] = (u32)(6);  // @412_42e6f0
  if (FL[0] != FL[1]) goto L42eb2e;  // @413_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1684956451);  // @414_42e6f0
  if (FL[0] != FL[1]) goto L42eb2e;  // @415_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(26217);  // @416_42e6f0
  if (FL[0] != FL[1]) goto L42eb2e;  // @417_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @418_42e6f0
  ecx = (u32)(EBP - 16);  // @419_42e6f0
  PV[32] = (u32)(ecx);  // @420_42e6f0
  ecx = edi;  // @421_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 156)))(ecx, PV[32]);  // @422_42e6f0
  ecx = edx = 0;  // @423_42e6f0
  goto L42ebd4;  // @424_42e6f0
  L42eb2e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7009), sizeof v); (u32)v; });  // @426_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @427_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @428_42e6f0
  if (FL[0] == FL[1]) goto L42ebd0;  // @429_42e6f0
  FL[0] = ebx; FL[1] = (u32)(7);  // @430_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @431_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(1717920803);  // @432_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @433_42e6f0
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(28265);  // @434_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @435_42e6f0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; }); FL[1] = (u32)(101);  // @436_42e6f0
  if (FL[0] != FL[1]) goto L42eb6c;  // @437_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @438_42e6f0
  ecx = (u32)(EBP - 16);  // @439_42e6f0
  PV[33] = (u32)(ecx);  // @440_42e6f0
  ecx = edi;  // @441_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, PV[33]);  // @442_42e6f0
  ecx = edx = 0;  // @443_42e6f0
  goto L42ebd4;  // @444_42e6f0
  L42eb6c:;
  FL[0] = ebx; FL[1] = (u32)(6);  // @446_42e6f0
  if (FL[0] != FL[1]) goto L42eb92;  // @447_42e6f0
  PV[34] = (u32)(ebx);  // @448_42e6f0
  edx = (u32)(6790772);  // @449_42e6f0
  ecx = esi;  // @450_42e6f0
  eax = ext_4309b0_fastcall3(ecx, edx, PV[34]);  // @451_42e6f0
  ecx = edx = 0;  // @452_42e6f0
  FL[2] = (eax & eax);  // @453_42e6f0
  if (FL[2] != 0) goto L42eb92;  // @454_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @455_42e6f0
  ecx = (u32)(EBP - 16);  // @456_42e6f0
  PV[35] = (u32)(ecx);  // @457_42e6f0
  ecx = edi;  // @458_42e6f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 164)))(ecx, PV[35]);  // @459_42e6f0
  ecx = edx = 0;  // @460_42e6f0
  goto L42ebd4;  // @461_42e6f0
  L42eb92:;
  FL[0] = ebx; FL[1] = (u32)(1);  // @463_42e6f0
  if (FL[0] != FL[1]) goto L42ebbc;  // @464_42e6f0
  PV[36] = (u32)(ebx);  // @465_42e6f0
  edx = (u32)(6790768);  // @466_42e6f0
  ecx = esi;  // @467_42e6f0
  eax = ext_4309b0_fastcall3(ecx, edx, PV[36]);  // @468_42e6f0
  ecx = edx = 0;  // @469_42e6f0
  FL[2] = (eax & eax);  // @470_42e6f0
  if (FL[2] != 0) goto L42ebbc;  // @471_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @472_42e6f0
  ecx = (u32)(EBP - 16);  // @473_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @474_42e6f0
  PV[37] = (u32)(ecx);  // @475_42e6f0
  PV[38] = (u32)(ebx);  // @476_42e6f0
  ecx = edi;  // @477_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 168)))(ecx, PV[38], PV[37]);  // @478_42e6f0
  ecx = edx = 0;  // @479_42e6f0
  goto L42ebd7;  // @480_42e6f0
  L42ebbc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @482_42e6f0
  ecx = (u32)(EBP - 16);  // @483_42e6f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @484_42e6f0
  PV[39] = (u32)(ecx);  // @485_42e6f0
  PV[40] = (u32)(ebx);  // @486_42e6f0
  ecx = edi;  // @487_42e6f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 172)))(ecx, PV[40], PV[39]);  // @488_42e6f0
  ecx = edx = 0;  // @489_42e6f0
  goto L42ebd7;  // @490_42e6f0
  L42ebd0:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }) + (u32)(12))); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @492_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @493_42e6f0
  L42ebd4:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @495_42e6f0
  L42ebd7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7021), sizeof v); (u32)v; });  // @497_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @498_42e6f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = eax;  // @499_42e6f0
  if (FL[0] != FL[1]) goto L42ea80;  // @500_42e6f0
  L42ebe9:;
  eax = (u32)(EBP + 11);  // @502_42e6f0
  PV[41] = (u32)(eax);  // @503_42e6f0
  ecx = (u32)(EBP - 64);  // @504_42e6f0
  eax = ext_42b390_thiscall3(ecx, (u32)(6781896), PV[41]);  // @505_42e6f0
  ecx = edx = 0;  // @506_42e6f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @507_42e6f0
  eax = edx;  // @508_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 60), sizeof v); (u32)v; });  // @509_42e6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @510_42e6f0
  ecx = (ecx - edi);  // @511_42e6f0
  FL[3] = ecx;  // @512_42e6f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @513_42e6f0
  eax = (eax - esi);  // @514_42e6f0
  FL[3] = eax;  // @515_42e6f0
  reg.state = (s32)((u32)(7));  // @516_42e6f0
  FL[0] = ecx; FL[1] = eax;  // @517_42e6f0
  if (FL[0] > FL[1]) goto L42ecda;  // @518_42e6f0
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @519_42e6f0
  eax = (u32)(ecx + edi);  // @520_42e6f0
  ecx = esi;  // @521_42e6f0
  PV[43] = (u32)(eax);  // @522_42e6f0
  PV[44] = (u32)(edi);  // @523_42e6f0
  eax = ext_42b1e0_fastcall5(ecx, edx, PV[44], PV[43], PV[42]);  // @524_42e6f0
  ecx = edx = 0;  // @525_42e6f0
  esi = eax;  // @526_42e6f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @527_42e6f0
  if (FL[0] == FL[1]) goto L42ec31;  // @528_42e6f0
  esi = (esi - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }));  // @529_42e6f0
  FL[3] = esi;  // @530_42e6f0
  goto L42ec34;  // @531_42e6f0
  L42ec31:;
  esi = (esi | (u32)(4294967295));  // @533_42e6f0
  FL[3] = esi;  // @534_42e6f0
  L42ec34:;
  FL[0] = esi; FL[1] = (u32)(-1);  // @536_42e6f0
  if (FL[0] == FL[1]) goto L42ecda;  // @537_42e6f0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @538_42e6f0
  L42ec44:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @540_42e6f0
  edi = (u32)(EBP - 36);  // @541_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @542_42e6f0
  eax = (u32)(EBP + 8);  // @543_42e6f0
  ecx = (ecx - edx);  // @544_42e6f0
  FL[3] = ecx;  // @545_42e6f0
  ecx = (ecx - esi);  // @546_42e6f0
  FL[3] = ecx;  // @547_42e6f0
  FL[0] = ecx; FL[1] = (u32)(2);  // @548_42e6f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @549_42e6f0
  ecx = (u32)(edx + esi);  // @550_42e6f0
  if (FL[0] >= FL[1]) eax = edi;  // @551_42e6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @552_42e6f0
  edi = (edi + edx);  // @553_42e6f0
  FL[3] = edi;  // @554_42e6f0
  edi = (edi + esi);  // @555_42e6f0
  FL[3] = edi;  // @556_42e6f0
  eax = edi;  // @557_42e6f0
  eax = (eax - ecx);  // @558_42e6f0
  FL[3] = eax;  // @559_42e6f0
  FL[0] = eax; FL[1] = (u32)(1);  // @560_42e6f0
  if ((s32)FL[0] < (s32)FL[1]) goto L42ec95;  // @561_42e6f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6777860), sizeof v); (u32)v; })) & 0xff);  // @562_42e6f0
  esi = (u32)(ecx + 1);  // @563_42e6f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @564_42e6f0
  FL[0] = esi; FL[1] = edi;  // @565_42e6f0
  if (FL[0] == FL[1]) goto L42ecbf;  // @566_42e6f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @567_42e6f0
  eax = (eax - edi);  // @568_42e6f0
  FL[3] = eax;  // @569_42e6f0
  eax = (eax + 1);  // @570_42e6f0
  FL[3] = eax;  // @571_42e6f0
  PV[45] = (u32)(eax);  // @572_42e6f0
  PV[46] = (u32)(edi);  // @573_42e6f0
  PV[47] = (u32)(esi);  // @574_42e6f0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x676278))(PV[47], PV[46], PV[45]);  // @575_42e6f0
  ecx = edx = 0;  // @576_42e6f0
  esi = (esi - edi);  // @577_42e6f0
  FL[3] = esi;  // @578_42e6f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @579_42e6f0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @580_42e6f0
  goto L42ecbf;  // @581_42e6f0
  L42ec95:;
  esi = (u32)(eax + 6777860);  // @583_42e6f0
  eax = esi;  // @584_42e6f0
  eax = (eax - (u32)(6777860));  // @585_42e6f0
  FL[3] = eax;  // @586_42e6f0
  PV[48] = (u32)(eax);  // @587_42e6f0
  PV[49] = (u32)(ecx);  // @588_42e6f0
  eax = ext_634d22_cdecl3(PV[49], (u32)(6777860), PV[48]);  // @589_42e6f0
  ecx = edx = 0;  // @590_42e6f0
  ecx = ebx;  // @591_42e6f0
  PV[50] = (u32)(esi);  // @592_42e6f0
  PV[51] = (u32)(edi);  // @593_42e6f0
  eax = ext_430d10_thiscall4(ecx, PV[51], PV[50], (u32)(6777861));  // @594_42e6f0
  ecx = edx = 0;  // @595_42e6f0
  L42ecbf:;
  eax = (u32)(EBP - 64);  // @597_42e6f0
  ecx = ebx;  // @598_42e6f0
  PV[52] = (u32)(eax);  // @599_42e6f0
  eax = ext_430c70_thiscall3(ecx, PV[52], (u32)(0));  // @600_42e6f0
  ecx = edx = 0;  // @601_42e6f0
  esi = eax;  // @602_42e6f0
  FL[0] = esi; FL[1] = (u32)(-1);  // @603_42e6f0
  if (FL[0] != FL[1]) goto L42ec44;  // @604_42e6f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @605_42e6f0
  L42ecda:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @607_42e6f0
  eax = (eax - edi);  // @608_42e6f0
  FL[3] = eax;  // @609_42e6f0
  reg.state = (s32)((u32)(8));  // @610_42e6f0
  FL[2] = (edi & edi);  // @611_42e6f0
  if (FL[2] == 0) goto L42ecf5;  // @612_42e6f0
  FL[2] = (eax & eax);  // @613_42e6f0
  if (FL[2] == 0) goto L42ecf5;  // @614_42e6f0
  PV[53] = (u32)(eax);  // @615_42e6f0
  PV[54] = (u32)(edi);  // @616_42e6f0
  ecx = (u32)(EBP - 64);  // @617_42e6f0
  eax = ext_54f870_stdcall2(PV[54], PV[53]);  // @618_42e6f0
  ecx = edx = 0;  // @619_42e6f0
  L42ecf5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @621_42e6f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @622_42e6f0
  eax = (eax - ecx);  // @623_42e6f0
  FL[3] = eax;  // @624_42e6f0
  reg.state = (s32)((u32)(9));  // @625_42e6f0
  FL[2] = (ecx & ecx);  // @626_42e6f0
  if (FL[2] == 0) goto L42ed16;  // @627_42e6f0
  FL[2] = (eax & eax);  // @628_42e6f0
  if (FL[2] == 0) goto L42ed16;  // @629_42e6f0
  PV[55] = (u32)(eax);  // @630_42e6f0
  PV[56] = (u32)(ecx);  // @631_42e6f0
  ecx = (u32)(EBP - 52);  // @632_42e6f0
  eax = ext_54f870_stdcall2(PV[56], PV[55]);  // @633_42e6f0
  ecx = edx = 0;  // @634_42e6f0
  L42ed16:;
  SEH_LEAVE();  // @636_42e6f0
  return eax;  // @637_42e6f0
}
PCREG(42e6f0, lifted_42e6f0);

