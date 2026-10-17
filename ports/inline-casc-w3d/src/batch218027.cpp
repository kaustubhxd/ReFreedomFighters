// batch218027.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5fa5e0_thiscall1(u32) __asm__("ext_5fa5e0");
extern "C" u32 THISCALL ext_64a880_thiscall1(u32) __asm__("ext_64a880");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_602120_cdecl4(...) __asm__("ext_602120");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6159f0(u32 ecx_in) {
  SEH_ENTER(0x66e59e);  // @h_6159f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_6159f0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65621), sizeof v); (u32)v; })) & 0xff);  // @1_6159f0
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) + 1)) & 0xff);  // @2_6159f0
  FL[3] = (ebx & 0xff);  // @3_6159f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65885), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_6159f0
  if (FL[0] != FL[1]) goto L615a70;  // @5_6159f0
  eax = ext_41e290_cdecl1((u32)(20));  // @6_6159f0
  ecx = edx = 0;  // @7_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @8_6159f0
  FL[2] = (eax & eax);  // @9_6159f0
  if (FL[2] == 0) goto L615a61;  // @10_6159f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @11_6159f0
  ecx = (ecx + (u32)(568));  // @12_6159f0
  FL[3] = ecx;  // @13_6159f0
  { u32 v = (u32)((u32)(7068576)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @14_6159f0
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @15_6159f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @16_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @17_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @18_6159f0
  goto L615a63;  // @19_6159f0
  L615a61:;
  eax = 0;  // @21_6159f0
  FL[3] = eax;  // @22_6159f0
  L615a63:;
  reg.state = (s32)((u32)(4294967295));  // @24_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65885), &v, sizeof v); }  // @25_6159f0
  L615a70:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65873), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_6159f0
  if (FL[0] != FL[1]) goto L615ac1;  // @28_6159f0
  eax = ext_41e290_cdecl1((u32)(20));  // @29_6159f0
  ecx = edx = 0;  // @30_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @31_6159f0
  FL[2] = (eax & eax);  // @32_6159f0
  if (FL[2] == 0) goto L615ab2;  // @33_6159f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 65629), sizeof v); (u32)v; });  // @34_6159f0
  ecx = (ecx + (u32)(568));  // @35_6159f0
  FL[3] = ecx;  // @36_6159f0
  { u32 v = (u32)((u32)(7068636)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_6159f0
  { u8 v = (u8)((ebx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @38_6159f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @39_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @40_6159f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @41_6159f0
  goto L615ab4;  // @42_6159f0
  L615ab2:;
  eax = 0;  // @44_6159f0
  FL[3] = eax;  // @45_6159f0
  L615ab4:;
  reg.state = (s32)((u32)(4294967295));  // @47_6159f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 65873), &v, sizeof v); }  // @48_6159f0
  L615ac1:;
  ecx = esi;  // @50_6159f0
  eax = ext_64a880_thiscall1(ecx);  // @51_6159f0
  ecx = edx = 0;  // @52_6159f0
  SEH_LEAVE();  // @53_6159f0
  return eax;  // @54_6159f0
}
PCREG(6159f0, lifted_6159f0);

extern "C" u32 THISCALL lifted_601020(u32 ecx_in) {
  SEH_ENTER(0x66d896);  // @h_601020
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_601020
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 236), &v, sizeof v); }  // @1_601020
  ecx = (u32)(EBP - 228);  // @2_601020
  { u32 v = (u32)((u32)(7051004)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @3_601020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @4_601020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @5_601020
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 220), &v, sizeof v); }  // @6_601020
  eax = ext_6014a0_stdcall1((u32)(8));  // @7_601020
  ecx = edx = 0;  // @8_601020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @9_601020
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @10_601020
  ecx = (u32)(eax + 8);  // @11_601020
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 220), &v, sizeof v); }  // @12_601020
  FL[2] = (eax & eax);  // @13_601020
  if (FL[2] == 0) goto L6010a3;  // @14_601020
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @15_601020
  L6010a3:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_601020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @18_601020
  FL[2] = (eax & eax);  // @19_601020
  if (FL[2] == 0) goto L60127a;  // @20_601020
  L6010b1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @22_601020
  FL[2] = (ecx & ecx);  // @23_601020
  if (FL[2] == 0) goto L6010c4;  // @24_601020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @25_601020
  ecx = (ecx - 1);  // @26_601020
  FL[3] = ecx;  // @27_601020
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @28_601020
  eax = (u32)(eax + ecx*4);  // @29_601020
  goto L6010d8;  // @30_601020
  L6010c4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @32_601020
  FL[2] = (eax & eax);  // @33_601020
  if (FL[2] == 0) goto L6010d7;  // @34_601020
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @35_601020
  ecx = edx = 0;  // @36_601020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; });  // @37_601020
  goto L6010de;  // @38_601020
  L6010d7:;
  __builtin_trap();  // @40_601020
  L6010d8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @42_601020
  L6010de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @44_601020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; });  // @45_601020
  ecx = (ecx - edx);  // @46_601020
  FL[3] = ecx;  // @47_601020
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_601020
  FL[0] = ecx; FL[1] = (u32)(10);  // @49_601020
  if (FL[0] < FL[1]) goto L60113a;  // @50_601020
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7051284) + 0), 4); v; });  // @51_601020
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7051284) + 4), 4); v; });  // @52_601020
  X0[2] = 0;  // @53_601020
  X0[3] = 0;  // @54_601020
  __builtin_memcpy((void *)((u32)(edx) + 0), &X0[0], 4);  // @55_601020
  __builtin_memcpy((void *)((u32)(edx) + 4), &X0[1], 4);  // @56_601020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; });  // @57_601020
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7051292), sizeof v); (u32)v; })) & 0xffff);  // @58_601020
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @59_601020
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; });  // @60_601020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @61_601020
  esi = (esi + (u32)(10));  // @62_601020
  FL[3] = esi;  // @63_601020
  FL[0] = esi; FL[1] = ebx;  // @64_601020
  if (FL[0] == FL[1]) goto L60116b;  // @65_601020
  PV[0] = (u32)(ebx);  // @66_601020
  PV[1] = (u32)(esi);  // @67_601020
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x676278))(PV[1], PV[0], (u32)(1));  // @68_601020
  ecx = edx = 0;  // @69_601020
  esi = (esi - ebx);  // @70_601020
  FL[3] = esi;  // @71_601020
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @72_601020
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @73_601020
  goto L60116b;  // @74_601020
  L60113a:;
  PV[2] = (u32)(ecx);  // @76_601020
  PV[3] = (u32)(edx);  // @77_601020
  eax = ext_634d22_cdecl3(PV[3], (u32)(7051284), PV[2]);  // @78_601020
  ecx = edx = 0;  // @79_601020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @80_601020
  ecx = (u32)(EBP - 228);  // @81_601020
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; }));  // @82_601020
  FL[3] = eax;  // @83_601020
  eax = (eax + (u32)(7051284));  // @84_601020
  FL[3] = eax;  // @85_601020
  PV[4] = (u32)(eax);  // @86_601020
  eax = ext_5f2c60_thiscall3(ecx, PV[4], (u32)(7051294));  // @87_601020
  ecx = edx = 0;  // @88_601020
  L60116b:;
  ebx = (u32)(16);  // @90_601020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = ebx;  // @91_601020
  if ((s32)FL[0] < (s32)FL[1]) ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @92_601020
  esi = 0;  // @93_601020
  FL[3] = esi;  // @94_601020
  FL[2] = (ebx & ebx);  // @95_601020
  if ((s32)FL[2] <= 0) goto L6011d9;  // @96_601020
  L601180:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @98_601020
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }));  // @99_601020
  eax = (eax & 0xff);  // @100_601020
  PV[5] = (u32)(eax);  // @101_601020
  eax = (u32)(EBP - 216);  // @102_601020
  PV[6] = (u32)(eax);  // @103_601020
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 236), sizeof v); (u32)v; });  // @104_601020
  eax = ext_602120_cdecl4(PV[7], PV[6], (u32)(7051296), PV[5]);  // @105_601020
  ecx = edx = 0;  // @106_601020
  ecx = (u32)(EBP - 216);  // @107_601020
  edx = (u32)(ecx + 1);  // @108_601020
  L6011b0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @110_601020
  ecx = (ecx + 1);  // @111_601020
  FL[3] = ecx;  // @112_601020
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @113_601020
  if (FL[2] != 0) goto L6011b0;  // @114_601020
  ecx = (ecx - edx);  // @115_601020
  FL[3] = ecx;  // @116_601020
  eax = (u32)(EBP - 216);  // @117_601020
  eax = (eax + ecx);  // @118_601020
  FL[3] = eax;  // @119_601020
  ecx = (u32)(EBP - 228);  // @120_601020
  PV[8] = (u32)(eax);  // @121_601020
  eax = (u32)(EBP - 216);  // @122_601020
  PV[9] = (u32)(eax);  // @123_601020
  eax = ext_5f2c60_thiscall3(ecx, PV[9], PV[8]);  // @124_601020
  ecx = edx = 0;  // @125_601020
  esi = (esi + 1);  // @126_601020
  FL[3] = esi;  // @127_601020
  FL[0] = esi; FL[1] = ebx;  // @128_601020
  if ((s32)FL[0] < (s32)FL[1]) goto L601180;  // @129_601020
  L6011d9:;
  ecx = (u32)(EBP - 228);  // @131_601020
  eax = ext_5f2c60_thiscall3(ecx, (u32)(7051304), (u32)(7051307));  // @132_601020
  ecx = edx = 0;  // @133_601020
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 236), sizeof v); (u32)v; });  // @134_601020
  esi = 0;  // @135_601020
  FL[3] = esi;  // @136_601020
  L6011f6:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @138_601020
  if ((s32)FL[0] >= (s32)FL[1]) goto L601247;  // @139_601020
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @140_601020
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }));  // @141_601020
  PV[10] = (u32)(eax);  // @142_601020
  eax = (u32)(EBP - 216);  // @143_601020
  PV[11] = (u32)(eax);  // @144_601020
  PV[12] = (u32)(ebx);  // @145_601020
  eax = ext_602120_cdecl4(PV[12], PV[11], (u32)(7051308), PV[10]);  // @146_601020
  ecx = edx = 0;  // @147_601020
  eax = (u32)(EBP - 216);  // @148_601020
  edx = (u32)(eax + 1);  // @149_601020
  L601221:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @151_601020
  eax = (eax + 1);  // @152_601020
  FL[3] = eax;  // @153_601020
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @154_601020
  if (FL[2] != 0) goto L601221;  // @155_601020
  eax = (eax - edx);  // @156_601020
  FL[3] = eax;  // @157_601020
  ecx = (u32)(EBP - 216);  // @158_601020
  eax = (eax + ecx);  // @159_601020
  FL[3] = eax;  // @160_601020
  PV[13] = (u32)(eax);  // @161_601020
  eax = ecx;  // @162_601020
  ecx = (u32)(EBP - 228);  // @163_601020
  PV[14] = (u32)(eax);  // @164_601020
  eax = ext_5f2c60_thiscall3(ecx, PV[14], PV[13]);  // @165_601020
  ecx = edx = 0;  // @166_601020
  esi = (esi + 1);  // @167_601020
  FL[3] = esi;  // @168_601020
  FL[0] = esi; FL[1] = (u32)(16);  // @169_601020
  if ((s32)FL[0] < (s32)FL[1]) goto L6011f6;  // @170_601020
  L601247:;
  ecx = (u32)(EBP - 228);  // @172_601020
  eax = ext_5f2c60_thiscall3(ecx, (u32)(7051312), (u32)(7051313));  // @173_601020
  ecx = edx = 0;  // @174_601020
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @175_601020
  eax = ext_634273_cdecl2(PV[15], (u32)(1));  // @176_601020
  ecx = edx = 0;  // @177_601020
  PV[16] = (u32)(edi);  // @178_601020
  eax = ext_634273_cdecl2(PV[16], (u32)(12));  // @179_601020
  ecx = edx = 0;  // @180_601020
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @181_601020
  if (FL[0] != FL[1]) goto L6010b1;  // @182_601020
  L60127a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @184_601020
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; });  // @185_601020
  eax = (eax - edx);  // @186_601020
  FL[3] = eax;  // @187_601020
  reg.state = (s32)((u32)(0));  // @188_601020
  FL[2] = (edx & edx);  // @189_601020
  if (FL[2] == 0) goto L6012a4;  // @190_601020
  FL[2] = (eax & eax);  // @191_601020
  if (FL[2] == 0) goto L6012a4;  // @192_601020
  PV[17] = (u32)(eax);  // @193_601020
  PV[18] = (u32)(edx);  // @194_601020
  ecx = (u32)(EBP - 228);  // @195_601020
  eax = ext_54f870_stdcall2(PV[18], PV[17]);  // @196_601020
  ecx = edx = 0;  // @197_601020
  L6012a4:;
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @199_601020
  eax = ext_41e2c0_cdecl1(PV[19]);  // @200_601020
  ecx = edx = 0;  // @201_601020
  ecx = ebx;  // @202_601020
  eax = ext_5fa5e0_thiscall1(ecx);  // @203_601020
  ecx = edx = 0;  // @204_601020
  SEH_LEAVE();  // @205_601020
  ext_633654(G(u32, 0x6f5630));  // @206_601020
  return eax;  // @207_601020
}
PCREG(601020, lifted_601020);

