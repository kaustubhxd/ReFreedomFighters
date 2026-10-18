// batch244017.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc4d0_fastcall2(u32, u32) __asm__("ext_4cc4d0");
extern "C" u32 FASTCALL ext_4cc6e0_fastcall2(u32, u32) __asm__("ext_4cc6e0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4ef660_thiscall2(u32, u32) __asm__("ext_4ef660");
extern "C" u32 THISCALL ext_63cc50_thiscall3(u32, u32, u32) __asm__("ext_63cc50");
extern "C" u32 THISCALL ext_63ead0_thiscall2(u32, u32) __asm__("ext_63ead0");
extern "C" u32 THISCALL ext_6500b0_thiscall1(u32) __asm__("ext_6500b0");
extern "C" u32 THISCALL ext_651180_thiscall1(u32) __asm__("ext_651180");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42abee_cdecl3(...) __asm__("ext_42abee");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_63b510(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ecx;  // @0_63b510
  ecx = 0;  // @1_63b510
  FL[3] = ecx;  // @2_63b510
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_63b510
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @4_63b510
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13320), sizeof v); (u32)v; }); FL[1] = ecx;  // @5_63b510
  if (FL[0] == FL[1]) goto L63b57b;  // @6_63b510
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_63b510
  edi = eax;  // @8_63b510
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @9_63b510
  L63b533:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_63b510
  FL[2] = (eax & eax);  // @12_63b510
  if (FL[2] == 0) goto L63b566;  // @13_63b510
  edx = edi;  // @14_63b510
  esi = 0;  // @15_63b510
  FL[3] = esi;  // @16_63b510
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @17_63b510
  L63b540:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = edi;  // @19_63b510
  if (FL[0] < FL[1]) goto L63b553;  // @20_63b510
  FL[2] = (esi & esi);  // @21_63b510
  if (FL[2] == 0) goto L63b54f;  // @22_63b510
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_63b510
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_63b510
  if (FL[0] <= FL[1]) goto L63b553;  // @25_63b510
  L63b54f:;
  ebx = edx;  // @27_63b510
  esi = eax;  // @28_63b510
  L63b553:;
  edx = (u32)(eax + 8);  // @30_63b510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @31_63b510
  FL[2] = (eax & eax);  // @32_63b510
  if (FL[2] != 0) goto L63b540;  // @33_63b510
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @34_63b510
  FL[2] = (esi & esi);  // @35_63b510
  if (FL[2] != 0) goto L63b587;  // @36_63b510
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @37_63b510
  L63b566:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_63b510
  ecx = (ecx + 1);  // @40_63b510
  FL[3] = ecx;  // @41_63b510
  edi = (edi + (u32)(4));  // @42_63b510
  FL[3] = edi;  // @43_63b510
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @44_63b510
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @45_63b510
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13320), sizeof v); (u32)v; });  // @46_63b510
  if (FL[0] != FL[1]) goto L63b533;  // @47_63b510
  L63b57b:;
  eax = (eax | (u32)(4294967295));  // @49_63b510
  FL[3] = eax;  // @50_63b510
  return eax;  // @51_63b510
  L63b587:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @53_63b510
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_63b510
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @55_63b510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @56_63b510
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) - eax)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @57_63b510
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @58_63b510
  if (FL[3] != 0) goto L63b5d9;  // @59_63b510
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @60_63b510
  eax = (u32)(65535);  // @61_63b510
  ecx = (ecx + (u32)(1024));  // @62_63b510
  FL[3] = ecx;  // @63_63b510
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12288), sizeof v); (u32)v; }) + (eax & 0xffff))); __builtin_memcpy((void *)(u32)(ecx + 12288), &v, sizeof v); }  // @64_63b510
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12288), sizeof v); (u32)v; });  // @65_63b510
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12290), sizeof v); (u32)v; })) & 0xffff);  // @66_63b510
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @67_63b510
  esi = (esi - ecx);  // @68_63b510
  FL[3] = esi;  // @69_63b510
  eax = (u32)(715827883);  // @70_63b510
  { long long p_ = (long long)(s32)eax * (long long)(s32)(esi); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @71_63b510
  edx = (u32)((s32)edx >> (u32)(1));  // @72_63b510
  FL[3] = edx;  // @73_63b510
  eax = edx;  // @74_63b510
  eax = (eax >> (u32)(31));  // @75_63b510
  FL[3] = eax;  // @76_63b510
  eax = (eax + edx);  // @77_63b510
  FL[3] = eax;  // @78_63b510
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 12290), &v, sizeof v); }  // @79_63b510
  eax = edi;  // @80_63b510
  return eax;  // @81_63b510
  L63b5d9:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @83_63b510
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_63b510
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @85_63b510
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_63b510
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13316), sizeof v); (u32)v; });  // @87_63b510
  edx = (edx >> (ecx & 0xff));  // @88_63b510
  FL[3] = edx;  // @89_63b510
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @90_63b510
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @91_63b510
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + edx*4), &v, sizeof v); }  // @92_63b510
  eax = edi;  // @93_63b510
  return eax;  // @94_63b510
}
PCREG(63b510, lifted_63b510);

extern "C" u32 lifted_4260a0(void) {
  SEH_ENTER(0x664592);  // @h_4260a0
  u8 F[0x1160] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x1060);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4260a0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4260a0
  if (FL[0] == FL[1]) goto L4261a3;  // @2_4260a0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_4260a0
  if (FL[0] != FL[1]) goto L426118;  // @4_4260a0
  eax = ext_41e290_cdecl1((u32)(28));  // @5_4260a0
  ecx = edx = 0;  // @6_4260a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4116), &v, sizeof v); }  // @7_4260a0
  reg.state = (s32)((u32)(0));  // @8_4260a0
  FL[2] = (eax & eax);  // @9_4260a0
  if (FL[2] == 0) goto L42610c;  // @10_4260a0
  ecx = eax;  // @11_4260a0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @12_4260a0
  ecx = edx = 0;  // @13_4260a0
  goto L42610e;  // @14_4260a0
  L42610c:;
  eax = 0;  // @16_4260a0
  FL[3] = eax;  // @17_4260a0
  L42610e:;
  reg.state = (s32)((u32)(4294967295));  // @19_4260a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @20_4260a0
  L426118:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @22_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_4260a0
  ecx = (u32)(EBP - 4112);  // @24_4260a0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @25_4260a0
  PV[2] = (u32)(ecx);  // @26_4260a0
  PV[3] = (u32)(edi);  // @27_4260a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, PV[3], PV[2], (u32)(6784796), PV[1], PV[0]);  // @28_4260a0
  ecx = edx = 0;  // @29_4260a0
  ecx = (u32)(EBP - 4112);  // @30_4260a0
  edx = (u32)(ecx + 1);  // @31_4260a0
  L426140:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @33_4260a0
  ecx = (ecx + 1);  // @34_4260a0
  FL[3] = ecx;  // @35_4260a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @36_4260a0
  if (FL[2] != 0) goto L426140;  // @37_4260a0
  eax = (u32)(EBP + 16);  // @38_4260a0
  ecx = (ecx - edx);  // @39_4260a0
  FL[3] = ecx;  // @40_4260a0
  PV[4] = (u32)(eax);  // @41_4260a0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @42_4260a0
  esi = (u32)(EBP - 4112);  // @43_4260a0
  esi = (esi + ecx);  // @44_4260a0
  FL[3] = esi;  // @45_4260a0
  PV[6] = (u32)(esi);  // @46_4260a0
  eax = ext_42abee_cdecl3(PV[6], PV[5], PV[4]);  // @47_4260a0
  ecx = edx = 0;  // @48_4260a0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(40);  // @49_4260a0
  if (FL[0] != FL[1]) goto L42617d;  // @50_4260a0
  ecx = (u32)(EBP - 4112);  // @51_4260a0
  ecx = (ecx - esi);  // @52_4260a0
  FL[3] = ecx;  // @53_4260a0
  L426170:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @55_4260a0
  esi = (u32)(esi + 1);  // @56_4260a0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + esi - 1), &v, sizeof v); }  // @57_4260a0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @58_4260a0
  if (FL[2] != 0) goto L426170;  // @59_4260a0
  L42617d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 40), sizeof v); (u32)v; });  // @61_4260a0
  edx = (u32)(EBP - 4112);  // @62_4260a0
  PV[7] = (u32)(edx);  // @63_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4260a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[7]);  // @65_4260a0
  ecx = edx = 0;  // @66_4260a0
  FL[2] = (eax & eax);  // @67_4260a0
  if (FL[2] == 0) goto L4261a3;  // @68_4260a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_4260a0
  ecx = (u32)(EBP - 4112);  // @70_4260a0
  PV[8] = (u32)(ecx);  // @71_4260a0
  PV[9] = (u32)(edi);  // @72_4260a0
  eax = ((u32( *)(u32, u32))(*(u32 *)(eax + 44)))(PV[9], PV[8]);  // @73_4260a0
  ecx = edx = 0;  // @74_4260a0
  L4261a3:;
  SEH_LEAVE();  // @76_4260a0
  ext_633654(G(u32, 0x6f5630));  // @77_4260a0
  return eax;  // @78_4260a0
}
PCREG(4260a0, lifted_4260a0);

extern "C" u32 THISCALL lifted_4f8e20(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 271), sizeof v); (u32)v; });  // @1_4f8e20
  ecx = (u32)(ebx + 271);  // @2_4f8e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @3_4f8e20
  ecx = edx = 0;  // @4_4f8e20
  FL[2] = (eax & eax);  // @5_4f8e20
  if (FL[2] != 0) goto L4f8e40;  // @6_4f8e20
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @7_4f8e20
  FL[3] = (eax & 0xff);  // @8_4f8e20
  return eax;  // @9_4f8e20
  L4f8e40:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_4f8e20
  eax = (u32)(ecx - 8);  // @12_4f8e20
  FL[0] = eax; FL[1] = (u32)(32);  // @13_4f8e20
  if (FL[0] > FL[1]) goto L4f8f20;  // @14_4f8e20
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5214036), sizeof v); (u32)v; });  // @15_4f8e20
  switch (eax) {  // @16_4f8e20
  case 0: goto L4f8e7d;  // @17_4f8e20
  case 1: goto L4f8f2b;  // @18_4f8e20
  case 2: goto L4f8e5e;  // @19_4f8e20
  case 3: goto L4f8ee4;  // @20_4f8e20
  case 4: goto L4f8f02;  // @21_4f8e20
  case 5: goto L4f8ef3;  // @22_4f8e20
  case 6: goto L4f8f11;  // @23_4f8e20
  case 7: goto L4f8f20;  // @24_4f8e20
  default: __builtin_trap(); }  // @25_4f8e20
  L4f8e5e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_4f8e20
  ecx = ebx;  // @28_4f8e20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @29_4f8e20
  ecx = edx = 0;  // @30_4f8e20
  PV[0] = (u32)(ebx);  // @31_4f8e20
  ecx = eax;  // @32_4f8e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @33_4f8e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 756)))(ecx, PV[0], (u32)(1));  // @34_4f8e20
  ecx = edx = 0;  // @35_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @36_4f8e20
  return eax;  // @37_4f8e20
  L4f8e7d:;
  ecx = (u32)(ebx + 143);  // @39_4f8e20
  eax = ext_4cc5f0_thiscall1(ecx);  // @40_4f8e20
  ecx = edx = 0;  // @41_4f8e20
  FL[2] = (eax & eax);  // @42_4f8e20
  if (FL[2] == 0) goto L4f8f2b;  // @43_4f8e20
  ecx = (u32)(ebx + 143);  // @44_4f8e20
  eax = ext_4cc1d0_thiscall1(ecx);  // @45_4f8e20
    // @46_4f8e20
  ecx = (u32)(ebx + 143);  // @47_4f8e20
  edi = (u32)(eax - 1);  // @48_4f8e20
  eax = ext_4cc5f0_thiscall1(ecx);  // @49_4f8e20
  ecx = edx = 0;  // @50_4f8e20
  ecx = (u32)(ebx + 143);  // @51_4f8e20
  edi = (edi + eax);  // @52_4f8e20
  FL[3] = edi;  // @53_4f8e20
  eax = ext_4cc1d0_thiscall1(ecx);  // @54_4f8e20
    // @55_4f8e20
  edx = edi;  // @56_4f8e20
  ecx = edi;  // @57_4f8e20
  edx = (edx - eax);  // @58_4f8e20
  FL[3] = edx;  // @59_4f8e20
  eax = ext_4cc4d0_fastcall2(ecx, edx);  // @60_4f8e20
  ecx = 0;  // @61_4f8e20
  ecx = (u32)(ebx + 143);  // @62_4f8e20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @63_4f8e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_4f8e20
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_4f8e20
    // @66_4f8e20
  PV[1] = (u32)(eax);  // @67_4f8e20
  ecx = ebx;  // @68_4f8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, PV[1]);  // @69_4f8e20
  ecx = edx = 0;  // @70_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @71_4f8e20
  return eax;  // @72_4f8e20
  L4f8ee4:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 475), &v, sizeof v); }  // @74_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @75_4f8e20
  return eax;  // @76_4f8e20
  L4f8ef3:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 476), &v, sizeof v); }  // @78_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @79_4f8e20
  return eax;  // @80_4f8e20
  L4f8f02:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 477), &v, sizeof v); }  // @82_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @83_4f8e20
  return eax;  // @84_4f8e20
  L4f8f11:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 478), &v, sizeof v); }  // @86_4f8e20
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @87_4f8e20
  return eax;  // @88_4f8e20
  L4f8f20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_4f8e20
  PV[2] = (u32)(ecx);  // @91_4f8e20
  ecx = ebx;  // @92_4f8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 856)))(ecx, PV[2]);  // @93_4f8e20
  ecx = edx = 0;  // @94_4f8e20
  L4f8f2b:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @96_4f8e20
  return eax;  // @97_4f8e20
}
PCREG(4f8e20, lifted_4f8e20);

extern "C" u32 THISCALL lifted_63d910(u32 ecx_in) {
  SEH_ENTER(0x66e878);  // @h_63d910
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @2_63d910
  eax = (eax - (u32)(8));  // @3_63d910
  FL[3] = eax;  // @4_63d910
  PV[0] = (u32)(eax);  // @5_63d910
  eax = ext_63cc50_thiscall3(ecx, (u32)(400000), PV[0]);  // @6_63d910
  ecx = edx = 0;  // @7_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @9_63d910
  eax = ext_651180_thiscall1(ecx);  // @10_63d910
  ecx = edx = 0;  // @11_63d910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @12_63d910
  if (FL[2] == 0) goto L63da34;  // @13_63d910
  esi = 0;  // @14_63d910
  FL[3] = esi;  // @15_63d910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }); FL[1] = esi;  // @16_63d910
  if (FL[0] == FL[1]) goto L63d993;  // @17_63d910
  edi = (u32)(ebx + 240);  // @18_63d910
  L63d980:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_63d910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @22_63d910
  ecx = edx = 0;  // @23_63d910
  esi = (esi + 1);  // @24_63d910
  FL[3] = esi;  // @25_63d910
  edi = (u32)(edi + 4);  // @26_63d910
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; });  // @27_63d910
  if (FL[0] != FL[1]) goto L63d980;  // @28_63d910
  L63d993:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @31_63d910
  eax = ext_6500b0_thiscall1(ecx);  // @32_63d910
  ecx = edx = 0;  // @33_63d910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @34_63d910
  if (FL[2] == 0) goto L63da34;  // @35_63d910
  ecx = (u32)(EBP - 52);  // @36_63d910
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(128), (u32)(1));  // @37_63d910
  ecx = edx = 0;  // @38_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @39_63d910
  eax = (u32)(EBP - 52);  // @40_63d910
  PV[1] = (u32)(eax);  // @41_63d910
  reg.state = (s32)((u32)(0));  // @42_63d910
  eax = ext_63ead0_thiscall2(ecx, PV[1]);  // @43_63d910
  ecx = edx = 0;  // @44_63d910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @45_63d910
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @46_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_63d910
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; });  // @48_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[3], PV[2], (u32)(12611839));  // @49_63d910
  ecx = edx = 0;  // @50_63d910
  eax = (u32)(EBP - 24);  // @51_63d910
  PV[4] = (u32)(eax);  // @52_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @53_63d910
  ecx = (u32)(EBP - 52);  // @54_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @55_63d910
  ecx = edx = 0;  // @56_63d910
  eax = (u32)(EBP - 24);  // @57_63d910
  PV[5] = (u32)(eax);  // @58_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @59_63d910
  ecx = (u32)(EBP - 52);  // @60_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @61_63d910
  ecx = edx = 0;  // @62_63d910
  FL[2] = (eax & eax);  // @63_63d910
  if (FL[2] == 0) goto L63da2c;  // @64_63d910
  L63da02:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @66_63d910
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @67_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @68_63d910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_63d910
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }));  // @70_63d910
  FL[3] = eax;  // @71_63d910
  PV[7] = (u32)(eax);  // @72_63d910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[7], PV[6], (u32)(8405232));  // @73_63d910
  ecx = edx = 0;  // @74_63d910
  eax = (u32)(EBP - 24);  // @75_63d910
  PV[8] = (u32)(eax);  // @76_63d910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @77_63d910
  ecx = (u32)(EBP - 52);  // @78_63d910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @79_63d910
  ecx = edx = 0;  // @80_63d910
  FL[2] = (eax & eax);  // @81_63d910
  if (FL[2] != 0) goto L63da02;  // @82_63d910
  L63da2c:;
  ecx = (u32)(EBP - 52);  // @84_63d910
  eax = ext_4ccfe0_thiscall1(ecx);  // @85_63d910
  ecx = edx = 0;  // @86_63d910
  L63da34:;
  SEH_LEAVE();  // @88_63d910
  return eax;  // @89_63d910
}
PCREG(63d910, lifted_63d910);

extern "C" u32 THISCALL lifted_4f5170(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66997b);  // @h_4f5170
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4f5170
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @1_4f5170
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4f5170
  PV[0] = (u32)(esi);  // @3_4f5170
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @4_4f5170
  eax = ext_4ef660_thiscall2(ecx, PV[0]);  // @5_4f5170
  ecx = edx = 0;  // @6_4f5170
  ecx = (u32)(EBP - 188);  // @7_4f5170
  eax = ext_4ccba0_thiscall1(ecx);  // @8_4f5170
    // @9_4f5170
  eax = (u32)(EBP - 188);  // @10_4f5170
  reg.state = (s32)((u32)(0));  // @11_4f5170
  PV[1] = (u32)(eax);  // @12_4f5170
  ecx = esi;  // @13_4f5170
  eax = ext_4e0fd0_thiscall2(ecx, PV[1]);  // @14_4f5170
  ecx = edx = 0;  // @15_4f5170
  eax = (u32)(EBP - 208);  // @16_4f5170
  ebx = 0;  // @17_4f5170
  FL[3] = ebx;  // @18_4f5170
  PV[2] = (u32)(eax);  // @19_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @20_4f5170
  ecx = (u32)(EBP - 188);  // @21_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @22_4f5170
  ecx = edx = 0;  // @23_4f5170
  eax = (u32)(EBP - 208);  // @24_4f5170
  PV[3] = (u32)(eax);  // @25_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @26_4f5170
  ecx = (u32)(EBP - 188);  // @27_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @28_4f5170
  ecx = edx = 0;  // @29_4f5170
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }); FL[1] = ebx;  // @30_4f5170
  if (FL[0] == FL[1]) goto L4f523b;  // @31_4f5170
  esi = (u32)(edi + 147);  // @32_4f5170
  L4f5211:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @34_4f5170
  ecx = (u32)(EBP - 188);  // @35_4f5170
  eax = (u32)(EBP - 208);  // @36_4f5170
  ebx = (ebx + 1);  // @37_4f5170
  FL[3] = ebx;  // @38_4f5170
  PV[4] = (u32)(eax);  // @39_4f5170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @40_4f5170
  esi = (u32)(esi + 4);  // @41_4f5170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @42_4f5170
  ecx = edx = 0;  // @43_4f5170
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @44_4f5170
  if (FL[0] != FL[1]) goto L4f5211;  // @45_4f5170
  FL[0] = ebx; FL[1] = (u32)(9);  // @46_4f5170
  if ((s32)FL[0] >= (s32)FL[1]) goto L4f5262;  // @47_4f5170
  L4f523b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @49_4f5170
  edi = (u32)(edi + ebx*4);  // @50_4f5170
  esi = (esi + (u32)(143));  // @51_4f5170
  FL[3] = esi;  // @52_4f5170
  edi = (edi + (u32)(147));  // @53_4f5170
  FL[3] = edi;  // @54_4f5170
  ecx = (u32)(9);  // @55_4f5170
  ecx = (ecx - ebx);  // @56_4f5170
  FL[3] = ecx;  // @57_4f5170
  esi = (u32)(esi + ebx*4);  // @58_4f5170
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @59_4f5170
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @60_4f5170
  L4f5262:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @62_4f5170
  ecx = ebx;  // @63_4f5170
  eax = ext_4e1600_thiscall1(ecx);  // @64_4f5170
    // @65_4f5170
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @66_4f5170
  if (FL[0] != FL[1]) goto L4f5295;  // @67_4f5170
  eax = (u32)(edi + 187);  // @68_4f5170
  ecx = ebx;  // @69_4f5170
  PV[5] = (u32)(eax);  // @70_4f5170
  eax = ext_4e11e0_thiscall3(ecx, PV[5], (u32)(1));  // @71_4f5170
  ecx = edx = 0;  // @72_4f5170
  eax = (u32)(edi + 191);  // @73_4f5170
  ecx = ebx;  // @74_4f5170
  PV[6] = (u32)(eax);  // @75_4f5170
  eax = ext_4e11e0_thiscall3(ecx, PV[6], (u32)(1));  // @76_4f5170
  ecx = edx = 0;  // @77_4f5170
  goto L4f52a9;  // @78_4f5170
  L4f5295:;
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(edi + 187), &v, sizeof v); }  // @80_4f5170
  { u32 v = (u32)((u32)(100)); __builtin_memcpy((void *)(u32)(edi + 191), &v, sizeof v); }  // @81_4f5170
  L4f52a9:;
  ecx = ebx;  // @83_4f5170
  eax = ext_4e1b30_thiscall1(ecx);  // @84_4f5170
  ecx = edx = 0;  // @85_4f5170
  ecx = (u32)(EBP - 188);  // @86_4f5170
  eax = ext_4ccf60_thiscall1(ecx);  // @87_4f5170
  ecx = edx = 0;  // @88_4f5170
  SEH_LEAVE();  // @89_4f5170
  ext_633654(G(u32, 0x6f5630));  // @90_4f5170
  return eax;  // @91_4f5170
}
PCREG(4f5170, lifted_4f5170);

extern "C" u32 THISCALL lifted_4f8720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669a96);  // @h_4f8720
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8720
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4f8720
  if (FL[0] == FL[1]) goto L4f887a;  // @2_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4f8720
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 224)))(ecx, PV[0]);  // @6_4f8720
  ecx = edx = 0;  // @7_4f8720
  esi = (eax & 0xffff);  // @8_4f8720
  FL[0] = esi; FL[1] = (u32)(32);  // @9_4f8720
  if (FL[0] < FL[1]) goto L4f887a;  // @10_4f8720
  FL[0] = esi; FL[1] = (u32)(42);  // @11_4f8720
  if (FL[0] == FL[1]) goto L4f887a;  // @12_4f8720
  FL[0] = esi; FL[1] = (u32)(60);  // @13_4f8720
  if (FL[0] == FL[1]) goto L4f887a;  // @14_4f8720
  FL[0] = esi; FL[1] = (u32)(62);  // @15_4f8720
  if (FL[0] == FL[1]) goto L4f887a;  // @16_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @17_4f8720
  edi = esi;  // @18_4f8720
  PV[1] = (u32)(edi);  // @19_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 648), sizeof v); (u32)v; });  // @21_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[1]);  // @22_4f8720
  ecx = edx = 0;  // @23_4f8720
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @24_4f8720
  if (FL[2] == 0) goto L4f887a;  // @25_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 451), sizeof v); (u32)v; });  // @26_4f8720
  PV[2] = (u32)(edi);  // @27_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, PV[2]);  // @29_4f8720
  ecx = edx = 0;  // @30_4f8720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 443), sizeof v); (u32)v; });  // @31_4f8720
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; });  // @32_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 656)))(ecx, PV[3]);  // @34_4f8720
  ecx = edx = 0;  // @35_4f8720
  FL[2] = (eax & eax);  // @36_4f8720
  if (FL[2] != 0) goto L4f87e0;  // @37_4f8720
  FL[0] = esi; FL[1] = (u32)(32);  // @38_4f8720
  if (FL[0] == FL[1]) goto L4f887a;  // @39_4f8720
  L4f87e0:;
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 471), sizeof v); (u32)v; });  // @41_4f8720
  if ((s32)FL[0] >= (s32)FL[1]) goto L4f887a;  // @42_4f8720
  edx = edi;  // @43_4f8720
  ecx = (u32)(EBP - 24);  // @44_4f8720
  eax = ext_4cc6e0_fastcall2(ecx, edx);  // @45_4f8720
  edx = 0;  // @46_4f8720
  eax = (u32)(EBP - 24);  // @47_4f8720
  PV[4] = (u32)(eax);  // @48_4f8720
  ecx = (u32)(EBP - 152);  // @49_4f8720
  eax = ext_4cbe80_thiscall2(ecx, PV[4]);  // @50_4f8720
  ecx = edx = 0;  // @51_4f8720
  eax = (u32)(EBP - 152);  // @52_4f8720
  reg.state = (s32)((u32)(0));  // @53_4f8720
  PV[5] = (u32)(eax);  // @54_4f8720
  eax = (u32)(EBP - 280);  // @55_4f8720
  PV[6] = (u32)(eax);  // @56_4f8720
  ecx = (u32)(ebx + 143);  // @57_4f8720
  eax = ext_4cc1e0_thiscall3(ecx, PV[6], PV[5]);  // @58_4f8720
  ecx = edx = 0;  // @59_4f8720
  PV[7] = (u32)(eax);  // @60_4f8720
  ecx = (u32)(ebx + 143);  // @61_4f8720
  reg.state = (s32)((u32)(1));  // @62_4f8720
  eax = ext_4cbee0_thiscall2(ecx, PV[7]);  // @63_4f8720
  ecx = edx = 0;  // @64_4f8720
  ecx = (u32)(EBP - 280);  // @65_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @66_4f8720
  ecx = edx = 0;  // @67_4f8720
  ecx = (u32)(EBP - 152);  // @68_4f8720
  reg.state = (s32)((u32)(4294967295));  // @69_4f8720
  eax = ext_4cbec0_thiscall1(ecx);  // @70_4f8720
  ecx = edx = 0;  // @71_4f8720
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @72_4f8720
  ecx = (u32)(ebx + 143);  // @73_4f8720
  eax = ext_4cc1d0_thiscall1(ecx);  // @74_4f8720
    // @75_4f8720
  PV[8] = (u32)(eax);  // @76_4f8720
  ecx = ebx;  // @77_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 864)))(ecx, PV[8]);  // @78_4f8720
  ecx = edx = 0;  // @79_4f8720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 467), sizeof v); (u32)v; });  // @80_4f8720
  ecx = ebx;  // @81_4f8720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @82_4f8720
  eax = (eax + 1);  // @83_4f8720
  FL[3] = eax;  // @84_4f8720
  PV[9] = (u32)(eax);  // @85_4f8720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 868)))(ecx, PV[9]);  // @86_4f8720
  ecx = edx = 0;  // @87_4f8720
  L4f887a:;
  SEH_LEAVE();  // @89_4f8720
  ext_633654(G(u32, 0x6f5630));  // @90_4f8720
  return eax;  // @91_4f8720
}
PCREG(4f8720, lifted_4f8720);

