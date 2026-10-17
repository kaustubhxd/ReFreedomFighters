// batch218040.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_4de4f0_fastcall2(u32, u32) __asm__("ext_4de4f0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e7880_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4e7880");
extern "C" u32 THISCALL ext_4e7930_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4e7930");
extern "C" u32 THISCALL ext_4e7c50_thiscall2(u32, u32) __asm__("ext_4e7c50");
extern "C" u32 THISCALL ext_4e7ce0_thiscall2(u32, u32) __asm__("ext_4e7ce0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5139e0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  SEH_ENTER(0x66a021);  // @h_5139e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  esi = ecx;  // @0_5139e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @1_5139e0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @2_5139e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5139e0
  PV[0] = (u32)(edx);  // @4_5139e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 397), &v, sizeof v); }  // @5_5139e0
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @6_5139e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 401), &v, sizeof v); }  // @7_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[0], (u32)(0));  // @9_5139e0
  ecx = edx = 0;  // @10_5139e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 345), &v, sizeof v); }  // @11_5139e0
  FL[2] = (eax & eax);  // @12_5139e0
  if (FL[2] != 0) goto L513ae4;  // @13_5139e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @14_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6939836), (u32)(806));  // @16_5139e0
  ecx = edx = 0;  // @17_5139e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_5139e0
  edi = eax;  // @19_5139e0
  eax = (u32)(EBP - 320);  // @20_5139e0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @21_5139e0
  PV[1] = (u32)(eax);  // @22_5139e0
  ecx = esi;  // @23_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[1], (u32)(1));  // @24_5139e0
  ecx = edx = 0;  // @25_5139e0
  ebx = eax;  // @26_5139e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 345), sizeof v); (u32)v; });  // @27_5139e0
  eax = (u32)(EBP - 192);  // @28_5139e0
  PV[2] = (u32)(eax);  // @29_5139e0
  reg.state = (s32)((u32)(0));  // @30_5139e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[2], (u32)(1));  // @32_5139e0
  ecx = edx = 0;  // @33_5139e0
  esi = eax;  // @34_5139e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_5139e0
  ecx = ebx;  // @36_5139e0
  reg.state = (s32)((u32)(1));  // @37_5139e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @38_5139e0
  ecx = edx = 0;  // @39_5139e0
  PV[3] = (u32)(eax);  // @40_5139e0
  ecx = esi;  // @41_5139e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @42_5139e0
  ecx = edx = 0;  // @43_5139e0
  PV[4] = (u32)(eax);  // @44_5139e0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; });  // @45_5139e0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[5], (u32)(6940164), PV[4], PV[3]);  // @46_5139e0
  ecx = edx = 0;  // @47_5139e0
  ecx = (u32)(EBP - 192);  // @48_5139e0
  eax = ext_4cbec0_thiscall1(ecx);  // @49_5139e0
  ecx = edx = 0;  // @50_5139e0
  ecx = (u32)(EBP - 320);  // @51_5139e0
  reg.state = (s32)((u32)(4294967295));  // @52_5139e0
  eax = ext_4cbec0_thiscall1(ecx);  // @53_5139e0
  ecx = edx = 0;  // @54_5139e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @55_5139e0
  L513ae4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 345), sizeof v); (u32)v; });  // @57_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_5139e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(1262836051));  // @59_5139e0
  ecx = edx = 0;  // @60_5139e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @61_5139e0
  FL[2] = (eax & eax);  // @62_5139e0
  if (FL[2] != 0) goto L513b59;  // @63_5139e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @64_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6939836), (u32)(812));  // @66_5139e0
  ecx = edx = 0;  // @67_5139e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 345), sizeof v); (u32)v; });  // @68_5139e0
  edi = eax;  // @69_5139e0
  eax = (u32)(EBP - 448);  // @70_5139e0
  PV[6] = (u32)(eax);  // @71_5139e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(1));  // @73_5139e0
  ecx = edx = 0;  // @74_5139e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_5139e0
  ecx = eax;  // @76_5139e0
  reg.state = (s32)((u32)(2));  // @77_5139e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @78_5139e0
  ecx = edx = 0;  // @79_5139e0
  PV[7] = (u32)(eax);  // @80_5139e0
  PV[8] = (u32)(edi);  // @81_5139e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[8], (u32)(6880964), PV[7]);  // @82_5139e0
  ecx = edx = 0;  // @83_5139e0
  ecx = (u32)(EBP - 448);  // @84_5139e0
  eax = ext_4cbec0_thiscall1(ecx);  // @85_5139e0
  ecx = edx = 0;  // @86_5139e0
  goto L513c58;  // @87_5139e0
  L513b59:;
  ebx = (u32)(esi + 349);  // @89_5139e0
  ecx = (u32)(esi + 413);  // @90_5139e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @91_5139e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @92_5139e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @93_5139e0
  eax = ext_4de7a0_thiscall1(ecx);  // @94_5139e0
  ecx = edx = 0;  // @95_5139e0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; });  // @96_5139e0
  X0[1] = 0;  // @97_5139e0
  X0[2] = 0;  // @98_5139e0
  X0[3] = 0;  // @99_5139e0
  edi = (u32)(esi + 324);  // @100_5139e0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836848) + 0), 4); v; })));  // @101_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_5139e0
  PV[9] = (u32)(ecx);  // @103_5139e0
  PV[10] = X0[0];  // @104_5139e0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @105_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @106_5139e0
  PV[12] = (u32)(ecx);  // @107_5139e0
  ecx = 0;  // @108_5139e0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; });  // @109_5139e0
  PV[14] = eax;  // @110_5139e0
  ecx = edi;  // @111_5139e0
  eax = ext_4e7880_thiscall5(ecx, PV[13], PV[14], PV[11], PV[10]);  // @112_5139e0
  ecx = edx = 0;  // @113_5139e0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 397), sizeof v); (u32)v; });  // @114_5139e0
  ecx = edi;  // @115_5139e0
  eax = ext_4e7ce0_thiscall2(ecx, PV[15]);  // @116_5139e0
  ecx = edx = 0;  // @117_5139e0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 401), sizeof v); (u32)v; });  // @118_5139e0
  ecx = edi;  // @119_5139e0
  eax = ext_4e7c50_thiscall2(ecx, PV[16]);  // @120_5139e0
  ecx = edx = 0;  // @121_5139e0
  esi = (esi + (u32)(361));  // @122_5139e0
  FL[3] = esi;  // @123_5139e0
  ecx = esi;  // @124_5139e0
  eax = ext_4de7a0_thiscall1(ecx);  // @125_5139e0
  ecx = edx = 0;  // @126_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @127_5139e0
  PV[17] = (u32)(ebx);  // @128_5139e0
  PV[18] = (u32)(esi);  // @129_5139e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 345), sizeof v); (u32)v; });  // @130_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[18], PV[17]);  // @132_5139e0
  ecx = edx = 0;  // @133_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @134_5139e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 345), sizeof v); (u32)v; });  // @135_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_5139e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @137_5139e0
  ecx = edx = 0;  // @138_5139e0
  PV[19] = (u32)(ebx);  // @139_5139e0
  PV[20] = (u32)(esi);  // @140_5139e0
  ecx = eax;  // @141_5139e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @142_5139e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 148)))(ecx, PV[20], PV[19]);  // @143_5139e0
  ecx = edx = 0;  // @144_5139e0
  PV[21] = (u32)(ecx);  // @145_5139e0
  eax = (u32)(EBP - 28);  // @146_5139e0
  PV[22] = (u32)(eax);  // @147_5139e0
  eax = (u32)(EBP - 64);  // @148_5139e0
  PV[23] = (u32)(eax);  // @149_5139e0
  PV[24] = (u32)(ecx);  // @150_5139e0
  eax = 0;  // @151_5139e0
  ecx = edi;  // @152_5139e0
  eax = ext_4e7930_thiscall5(ecx, (u32)(0), PV[23], PV[22], (u32)(3212836864));  // @153_5139e0
  ecx = edx = 0;  // @154_5139e0
  edx = (u32)(EBP - 28);  // @155_5139e0
  ecx = ebx;  // @156_5139e0
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @157_5139e0
  eax = ext_43e960_fastcall2(ecx, edx);  // @158_5139e0
  ecx = edx = 0;  // @159_5139e0
  edx = (u32)(EBP - 64);  // @160_5139e0
  ecx = esi;  // @161_5139e0
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @162_5139e0
  ecx = edx = 0;  // @163_5139e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @164_5139e0
  ecx = ebx;  // @165_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @166_5139e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @167_5139e0
  ecx = edx = 0;  // @168_5139e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @169_5139e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; }) | (u32)(2))); __builtin_memcpy((void *)(u32)(eax + 24), &v, sizeof v); }  // @170_5139e0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @171_5139e0
  L513c58:;
  SEH_LEAVE();  // @173_5139e0
  ext_633654(G(u32, 0x6f5630));  // @174_5139e0
  return eax;  // @175_5139e0
}
PCREG(5139e0, lifted_5139e0);

