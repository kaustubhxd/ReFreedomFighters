// batch242026.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_403ab0_cdecl2(...) __asm__("ext_403ab0");
extern "C" u32 ext_403e50_cdecl2(...) __asm__("ext_403e50");
extern "C" u32 ext_403e80_cdecl1(...) __asm__("ext_403e80");
extern "C" u32 ext_403e80_cdecl2(...) __asm__("ext_403e80");
extern "C" u32 ext_403ea0_cdecl4(...) __asm__("ext_403ea0");
extern "C" u32 ext_405bb0_cdecl4(...) __asm__("ext_405bb0");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" u32 ext_634dfa_cdecl0(void) __asm__("ext_634dfa");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_40e8b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 80) + 88), sizeof v); (u32)v; });  // @0_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 80) + 92), sizeof v); (u32)v; });  // @1_40e8b0
  ecx = eax;  // @2_40e8b0
  ecx = (u32)((s32)ecx * (s32)edx);  // @3_40e8b0
  FL[3] = ecx;  // @4_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 88) + 108), sizeof v); (u32)v; });  // @5_40e8b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 112), sizeof v); (u32)v; });  // @6_40e8b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 96) + 48), &v, sizeof v); }  // @7_40e8b0
  FL[2] = (edx & edx);  // @8_40e8b0
  esi = (u32)(eax*4);  // @9_40e8b0
  ebx = (u32)(eax + eax);  // @10_40e8b0
  if ((s32)FL[2] <= 0) goto L40e9e1;  // @11_40e8b0
  esi = (esi << (u32)(2));  // @12_40e8b0
  FL[3] = esi;  // @13_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 88), &v, sizeof v); }  // @14_40e8b0
  esi = (u32)(ebq + ecx*4);  // @15_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 32), &v, sizeof v); }  // @16_40e8b0
  esi = (u32)(edi + ebx*4);  // @17_40e8b0
  ebx = (u32)(ebq + ecx*8);  // @18_40e8b0
  edx = (u32)(eax*4);  // @19_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 40), &v, sizeof v); }  // @20_40e8b0
  ebx = (u32)(ecx + ecx*2);  // @21_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 36), &v, sizeof v); }  // @22_40e8b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 96) + 28), &v, sizeof v); }  // @23_40e8b0
  ebx = (u32)(ebq + ebx*4);  // @24_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 44), &v, sizeof v); }  // @25_40e8b0
  ebx = (u32)(eax + eax);  // @26_40e8b0
  ebx = (u32)(edi + ebx*8 - 4);  // @27_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 24), &v, sizeof v); }  // @28_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 108), sizeof v); (u32)v; });  // @29_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 52), &v, sizeof v); }  // @30_40e8b0
  goto L40e92f;  // @31_40e8b0
  L40e92b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 84), sizeof v); (u32)v; });  // @33_40e8b0
  L40e92f:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @35_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @36_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @37_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; });  // @38_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @39_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 20)) :: "st");  // @40_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @41_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @42_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @43_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; });  // @44_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 16)) :: "st");  // @45_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @46_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @47_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebx)) : "st");  // @48_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 36), sizeof v); (u32)v; });  // @49_40e8b0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @50_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc2" ::: "st");  // @51_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @52_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @53_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 96) + 20)) : "st");  // @54_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 32), sizeof v); (u32)v; });  // @55_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @56_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 40), sizeof v); (u32)v; });  // @57_40e8b0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @58_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @59_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 44), sizeof v); (u32)v; });  // @60_40e8b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @61_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @62_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 96) + 20)) : "st");  // @63_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebx)) :: "st");  // @64_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 36), sizeof v); (u32)v; });  // @65_40e8b0
  ebx = (ebx + edx);  // @66_40e8b0
  FL[3] = ebx;  // @67_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 36), &v, sizeof v); }  // @68_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 32), sizeof v); (u32)v; });  // @69_40e8b0
  ebx = (ebx + edx);  // @70_40e8b0
  FL[3] = ebx;  // @71_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 32), &v, sizeof v); }  // @72_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 40), sizeof v); (u32)v; });  // @73_40e8b0
  ebx = (ebx + edx);  // @74_40e8b0
  FL[3] = ebx;  // @75_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 40), &v, sizeof v); }  // @76_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 44), sizeof v); (u32)v; });  // @77_40e8b0
  ebx = (ebx + edx);  // @78_40e8b0
  FL[3] = ebx;  // @79_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 44), &v, sizeof v); }  // @80_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 88), sizeof v); (u32)v; });  // @81_40e8b0
  esi = (esi + ebx);  // @82_40e8b0
  FL[3] = esi;  // @83_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 84), &v, sizeof v); }  // @84_40e8b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @85_40e8b0
  esi = (esi + ebx);  // @86_40e8b0
  FL[3] = esi;  // @87_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 24), &v, sizeof v); }  // @88_40e8b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; });  // @89_40e8b0
  esi = (esi + ebx);  // @90_40e8b0
  FL[3] = esi;  // @91_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 28), &v, sizeof v); }  // @92_40e8b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 52), sizeof v); (u32)v; });  // @93_40e8b0
  esi = (esi - 1);  // @94_40e8b0
  FL[3] = esi;  // @95_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 52), &v, sizeof v); }  // @96_40e8b0
  if (FL[3] != 0) goto L40e92b;  // @97_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 108), sizeof v); (u32)v; });  // @98_40e8b0
  L40e9e1:;
  FL[0] = eax; FL[1] = (u32)(2);  // @100_40e8b0
  if ((s32)FL[0] < (s32)FL[1]) goto L40ed8e;  // @101_40e8b0
  if (FL[0] == FL[1]) goto L40ecd0;  // @102_40e8b0
  esi = 0;  // @103_40e8b0
  FL[3] = esi;  // @104_40e8b0
  FL[0] = edx; FL[1] = esi;  // @105_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 24), &v, sizeof v); }  // @106_40e8b0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40ecb8;  // @107_40e8b0
  edx = (u32)(eax + eax*2);  // @108_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 36), &v, sizeof v); }  // @109_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 92), &v, sizeof v); }  // @110_40e8b0
  edx = (u32)(eax*4);  // @111_40e8b0
  edx = (edx - eax);  // @112_40e8b0
  FL[3] = edx;  // @113_40e8b0
  FL[1] = edx;  // @114_40e8b0
  edx = (0u - edx);  // @115_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 96), &v, sizeof v); }  // @116_40e8b0
  edx = (u32)(ecx + ecx*2);  // @117_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 52), &v, sizeof v); }  // @118_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 108), sizeof v); (u32)v; });  // @119_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 88), &v, sizeof v); }  // @120_40e8b0
  L40ea27:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @122_40e8b0
  FL[0] = eax; FL[1] = (u32)(2);  // @123_40e8b0
  ebx = (u32)(edx*4);  // @124_40e8b0
  edx = (u32)(ebx + eax*2);  // @125_40e8b0
  esi = (u32)(edx + eax*2);  // @126_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 84), &v, sizeof v); }  // @127_40e8b0
  if ((s32)FL[0] <= (s32)FL[1]) goto L40ec7f;  // @128_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 36), sizeof v); (u32)v; });  // @129_40e8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 84), sizeof v); (u32)v; });  // @130_40e8b0
  ecx = (u32)(edi + edx*4);  // @131_40e8b0
  edx = (u32)(edi + ebx*4);  // @132_40e8b0
  ebx = (ebx - ebq);  // @133_40e8b0
  FL[3] = ebx;  // @134_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @135_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 84), &v, sizeof v); }  // @136_40e8b0
  edi = (u32)(edi + eax*4);  // @137_40e8b0
  ebx = (u32)(ebq + ebx*4);  // @138_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 48), sizeof v); (u32)v; });  // @139_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 44), &v, sizeof v); }  // @140_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 84), sizeof v); (u32)v; });  // @141_40e8b0
  ebx = (ebx + ebq);  // @142_40e8b0
  FL[3] = ebx;  // @143_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @144_40e8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 128), sizeof v); (u32)v; });  // @145_40e8b0
  esi = ecx;  // @146_40e8b0
  ebx = (u32)(ebq + ebx*4);  // @147_40e8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 96) + 72), &v, sizeof v); }  // @148_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 40), &v, sizeof v); }  // @149_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 48), sizeof v); (u32)v; });  // @150_40e8b0
  ebx = (ebx + ebx);  // @151_40e8b0
  FL[3] = ebx;  // @152_40e8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 120), sizeof v); (u32)v; });  // @153_40e8b0
  ebq = ebx;  // @154_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 36), sizeof v); (u32)v; });  // @155_40e8b0
  ebq = (ebq - ebx);  // @156_40e8b0
  FL[3] = ebq;  // @157_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @158_40e8b0
  ebx = (ebx << (u32)(2));  // @159_40e8b0
  FL[3] = ebx;  // @160_40e8b0
  ebq = (ebq + ebx);  // @161_40e8b0
  FL[3] = ebq;  // @162_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @163_40e8b0
  eax = (eax + (u32)(4));  // @164_40e8b0
  FL[3] = eax;  // @165_40e8b0
  ebx = (u32)(ebx + ebq*4);  // @166_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 52), sizeof v); (u32)v; });  // @167_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 28), &v, sizeof v); }  // @168_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @169_40e8b0
  ebx = (ebx << (u32)(2));  // @170_40e8b0
  FL[3] = ebx;  // @171_40e8b0
  ebq = (ebq + ebx);  // @172_40e8b0
  FL[3] = ebq;  // @173_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @174_40e8b0
  ebx = (u32)(ebx + ebq*4);  // @175_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 120), sizeof v); (u32)v; });  // @176_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 32), &v, sizeof v); }  // @177_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 124), sizeof v); (u32)v; });  // @178_40e8b0
  ebx = (ebx - ebq);  // @179_40e8b0
  FL[3] = ebx;  // @180_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 76), &v, sizeof v); }  // @181_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 128), sizeof v); (u32)v; });  // @182_40e8b0
  ebx = (ebx - ebq);  // @183_40e8b0
  FL[3] = ebx;  // @184_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 128), sizeof v); (u32)v; });  // @185_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 80), &v, sizeof v); }  // @186_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 124), sizeof v); (u32)v; });  // @187_40e8b0
  ebx = (ebx - ebq);  // @188_40e8b0
  FL[3] = ebx;  // @189_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 68), &v, sizeof v); }  // @190_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 104), sizeof v); (u32)v; });  // @191_40e8b0
  ebx = (ebx - 1);  // @192_40e8b0
  FL[3] = ebx;  // @193_40e8b0
  ebx = (ebx >> (u32)(1));  // @194_40e8b0
  FL[3] = ebx;  // @195_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 84), &v, sizeof v); }  // @196_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 72), sizeof v); (u32)v; });  // @197_40e8b0
  L40eb07:;
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 44), sizeof v); (u32)v; });  // @199_40e8b0
  edx = (edx + (u32)(8));  // @200_40e8b0
  FL[3] = edx;  // @201_40e8b0
  ebq = (ebq + (u32)(8));  // @202_40e8b0
  FL[3] = ebq;  // @203_40e8b0
  ecx = (ecx + (u32)(8));  // @204_40e8b0
  FL[3] = ecx;  // @205_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 44), &v, sizeof v); }  // @206_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 40), sizeof v); (u32)v; });  // @207_40e8b0
  ebq = (ebq + (u32)(8));  // @208_40e8b0
  FL[3] = ebq;  // @209_40e8b0
  esi = (esi - (u32)(8));  // @210_40e8b0
  FL[3] = esi;  // @211_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 40), &v, sizeof v); }  // @212_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; });  // @213_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @214_40e8b0
  ebq = (ebq + (u32)(8));  // @215_40e8b0
  FL[3] = ebq;  // @216_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edi - 8)) : "st");  // @217_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 28), &v, sizeof v); }  // @218_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 32), sizeof v); (u32)v; });  // @219_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @220_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi - 8)) : "st");  // @221_40e8b0
  ebq = (ebq + (u32)(8));  // @222_40e8b0
  FL[3] = ebq;  // @223_40e8b0
  edi = (edi - (u32)(8));  // @224_40e8b0
  FL[3] = edi;  // @225_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @226_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @227_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @228_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @229_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 32), &v, sizeof v); }  // @230_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 44), sizeof v); (u32)v; });  // @231_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 20)) :: "st");  // @232_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx - 4)) : "st");  // @233_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edi - 4)) : "st");  // @234_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 16)) :: "st");  // @235_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx - 4)) : "st");  // @236_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edi - 4)) : "st");  // @237_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @238_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @239_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 56)) :: "st");  // @240_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx - 4)) : "st");  // @241_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @242_40e8b0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @243_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @244_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @245_40e8b0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @246_40e8b0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @247_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 72)) :: "st");  // @248_40e8b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @249_40e8b0
  __asm__ volatile(".byte 0xd9, 0xc0" ::: "st");  // @250_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc2" ::: "st");  // @251_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @252_40e8b0
  __asm__ volatile(".byte 0xd9, 0xc9" ::: "st");  // @253_40e8b0
  __asm__ volatile(".byte 0xd8, 0xe1" ::: "st");  // @254_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 40), sizeof v); (u32)v; });  // @255_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 64)) :: "st");  // @256_40e8b0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @257_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @258_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 96) + 20)) : "st");  // @259_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 60)) :: "st");  // @260_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @261_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 96) + 20)) : "st");  // @262_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 16)) :: "st");  // @263_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 56)) : "st");  // @264_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc1" ::: "st");  // @265_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 20)) :: "st");  // @266_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)((EBP - 96) + 56)) : "st");  // @267_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 60)) : "st");  // @268_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @269_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 20)) : "st");  // @270_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @271_40e8b0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @272_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @273_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 60)) : "st");  // @274_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax)) : "st");  // @275_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 20)) : "st");  // @276_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax - 4)) : "st");  // @277_40e8b0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @278_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @279_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 68), sizeof v); (u32)v; });  // @280_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 72)) : "st");  // @281_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + ebq)) : "st");  // @282_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 76), sizeof v); (u32)v; });  // @283_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 64)) : "st");  // @284_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + ebq)) : "st");  // @285_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; });  // @286_40e8b0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @287_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @288_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 68), sizeof v); (u32)v; });  // @289_40e8b0
  eax = (eax + (u32)(8));  // @290_40e8b0
  FL[3] = eax;  // @291_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 64)) : "st");  // @292_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx + ebq)) : "st");  // @293_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 76), sizeof v); (u32)v; });  // @294_40e8b0
  ebx = (ebx + (u32)(8));  // @295_40e8b0
  FL[3] = ebx;  // @296_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 72)) : "st");  // @297_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + ebq - 8)) : "st");  // @298_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 28), sizeof v); (u32)v; });  // @299_40e8b0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @300_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @301_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @302_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx - 8)) : "st");  // @303_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 80), sizeof v); (u32)v; });  // @304_40e8b0
  __asm__ volatile(".byte 0xd9, 0xc1" ::: "st");  // @305_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + ebq - 8)) : "st");  // @306_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 32), sizeof v); (u32)v; });  // @307_40e8b0
  __asm__ volatile(".byte 0xde, 0xe9" ::: "st");  // @308_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq - 4)) :: "st");  // @309_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 80), sizeof v); (u32)v; });  // @310_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebx - 8)) : "st");  // @311_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @312_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(eax + ebq - 8)) : "st");  // @313_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 32), sizeof v); (u32)v; });  // @314_40e8b0
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @315_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @316_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 84), sizeof v); (u32)v; });  // @317_40e8b0
  ebq = (ebq - 1);  // @318_40e8b0
  FL[3] = ebq;  // @319_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 84), &v, sizeof v); }  // @320_40e8b0
  if (FL[3] != 0) goto L40eb07;  // @321_40e8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 48), sizeof v); (u32)v; });  // @322_40e8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 104), sizeof v); (u32)v; });  // @323_40e8b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 112), sizeof v); (u32)v; });  // @324_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @325_40e8b0
  L40ec7f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 24), sizeof v); (u32)v; });  // @327_40e8b0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 36), sizeof v); (u32)v; });  // @328_40e8b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 52), sizeof v); (u32)v; });  // @329_40e8b0
  edx = (edx + eax);  // @330_40e8b0
  FL[3] = edx;  // @331_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 24), &v, sizeof v); }  // @332_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 92), sizeof v); (u32)v; });  // @333_40e8b0
  ebx = (ebx + edx);  // @334_40e8b0
  FL[3] = ebx;  // @335_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 96), sizeof v); (u32)v; });  // @336_40e8b0
  esi = (esi + edx);  // @337_40e8b0
  FL[3] = esi;  // @338_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 88), sizeof v); (u32)v; });  // @339_40e8b0
  edx = (edx - 1);  // @340_40e8b0
  FL[3] = edx;  // @341_40e8b0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 96) + 36), &v, sizeof v); }  // @342_40e8b0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 96) + 52), &v, sizeof v); }  // @343_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 88), &v, sizeof v); }  // @344_40e8b0
  if (FL[3] != 0) goto L40ea27;  // @345_40e8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 108), sizeof v); (u32)v; });  // @346_40e8b0
  L40ecb8:;
  esi = eax;  // @348_40e8b0
  esi = (esi & (u32)(2147483649));  // @349_40e8b0
  FL[3] = esi;  // @350_40e8b0
  if ((s32)FL[3] >= 0) goto L40ecc7;  // @351_40e8b0
  esi = (esi - 1);  // @352_40e8b0
  FL[3] = esi;  // @353_40e8b0
  esi = (esi | (u32)(4294967294));  // @354_40e8b0
  FL[3] = esi;  // @355_40e8b0
  esi = (esi + 1);  // @356_40e8b0
  FL[3] = esi;  // @357_40e8b0
  L40ecc7:;
  FL[0] = esi; FL[1] = (u32)(1);  // @359_40e8b0
  if (FL[0] == FL[1]) goto L40ed8e;  // @360_40e8b0
  L40ecd0:;
  FL[2] = (edx & edx);  // @362_40e8b0
  esi = (u32)(eax + eax*2);  // @363_40e8b0
  if ((s32)FL[2] <= 0) goto L40ed8e;  // @364_40e8b0
  edx = (u32)(eax*4);  // @365_40e8b0
  ebx = (u32)(eax*4);  // @366_40e8b0
  edx = (edx << (u32)(2));  // @367_40e8b0
  FL[3] = edx;  // @368_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 104), &v, sizeof v); }  // @369_40e8b0
  edx = (u32)(ebq + eax*4 - 4);  // @370_40e8b0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 96) + 128), &v, sizeof v); }  // @371_40e8b0
  edx = (u32)(ebx + edi);  // @372_40e8b0
  esi = (u32)(edi + esi*4);  // @373_40e8b0
  edi = (u32)(eax + ecx - 1);  // @374_40e8b0
  edi = (u32)(ebq + edi*4);  // @375_40e8b0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 96) + 116), &v, sizeof v); }  // @376_40e8b0
  edi = (u32)(eax + ecx*2 - 1);  // @377_40e8b0
  eax = (u32)(eax + ecx*2 - 1);  // @378_40e8b0
  ecx = (ecx + eax);  // @379_40e8b0
  FL[3] = ecx;  // @380_40e8b0
  edi = (u32)(ebq + edi*4);  // @381_40e8b0
  eax = (u32)(ebq + ecx*4);  // @382_40e8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 108), sizeof v); (u32)v; });  // @383_40e8b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 96) + 108), &v, sizeof v); }  // @384_40e8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 128), sizeof v); (u32)v; });  // @385_40e8b0
  L40ed2e:;
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @387_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @388_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi)) : "st");  // @389_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @390_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx - 4)) : "st");  // @391_40e8b0
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @392_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 116), sizeof v); (u32)v; });  // @393_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 96) + 16)) :: "st");  // @394_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(esi - 4)) : "st");  // @395_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(edx - 4)) : "st");  // @396_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @397_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @398_40e8b0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @399_40e8b0
  __asm__ volatile(".byte 0xd8, 0xe2" ::: "st");  // @400_40e8b0
  ecx = (ecx + ebx);  // @401_40e8b0
  FL[3] = ecx;  // @402_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283748)) : "st");  // @403_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebq)) :: "st");  // @404_40e8b0
  ebq = (ebq + ebx);  // @405_40e8b0
  FL[3] = ebq;  // @406_40e8b0
  __asm__ volatile(".byte 0xd8, 0xc0" ::: "st");  // @407_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 116), &v, sizeof v); }  // @408_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 104), sizeof v); (u32)v; });  // @409_40e8b0
  edx = (edx + ebq);  // @410_40e8b0
  FL[3] = edx;  // @411_40e8b0
  esi = (esi + ebq);  // @412_40e8b0
  FL[3] = esi;  // @413_40e8b0
  ebq = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 96) + 108), sizeof v); (u32)v; });  // @414_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi)) :: "st");  // @415_40e8b0
  edi = (edi + ebx);  // @416_40e8b0
  FL[3] = edi;  // @417_40e8b0
  __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)((EBP - 96) + 16)) : "st");  // @418_40e8b0
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(7283748)) : "st");  // @419_40e8b0
  __asm__ volatile("fchs" ::: "st");  // @420_40e8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(eax)) :: "st");  // @421_40e8b0
  eax = (eax + ebx);  // @422_40e8b0
  FL[3] = eax;  // @423_40e8b0
  ebq = (ebq - 1);  // @424_40e8b0
  FL[3] = ebq;  // @425_40e8b0
  { u32 v = (u32)(ebq); __builtin_memcpy((void *)(u32)((EBP - 96) + 108), &v, sizeof v); }  // @426_40e8b0
  if (FL[3] != 0) goto L40ed2e;  // @427_40e8b0
  L40ed8e:;
  return eax;  // @429_40e8b0
}
PCREG(40e8b0, lifted_40e8b0);



