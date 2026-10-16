// batch218008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_61bbd0_thiscall1(u32) __asm__("ext_61bbd0");
extern "C" u32 THISCALL ext_61bbe0_thiscall1(u32) __asm__("ext_61bbe0");
extern "C" u32 THISCALL ext_61bbf0_thiscall4(u32, u32, u32, u32) __asm__("ext_61bbf0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_43b9f0(u32 ecx_in) {
  SEH_ENTER(0x6685bb);  // @h_43b9f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_43b9f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 177), &v, sizeof v); }  // @1_43b9f0
  ecx = (u32)(EBP - 144);  // @2_43b9f0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 181), &v, sizeof v); }  // @3_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 144), &v, sizeof v); }  // @4_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @5_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 148), &v, sizeof v); }  // @6_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 164), &v, sizeof v); }  // @7_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @8_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 168), &v, sizeof v); }  // @9_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 156), &v, sizeof v); }  // @10_43b9f0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 172), &v, sizeof v); }  // @11_43b9f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 183), &v, sizeof v); }  // @12_43b9f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 187), &v, sizeof v); }  // @13_43b9f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 191), &v, sizeof v); }  // @14_43b9f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @15_43b9f0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @16_43b9f0
  ecx = edx = 0;  // @17_43b9f0
  eax = (u32)(EBP - 144);  // @18_43b9f0
  reg.state = (s32)((u32)(0));  // @19_43b9f0
  PV[0] = (u32)(eax);  // @20_43b9f0
  ecx = (u32)(ebx + 195);  // @21_43b9f0
  eax = ext_4cbee0_thiscall2(ecx, PV[0]);  // @22_43b9f0
  ecx = edx = 0;  // @23_43b9f0
  ecx = (u32)(EBP - 144);  // @24_43b9f0
  reg.state = (s32)((u32)(4294967295));  // @25_43b9f0
  eax = ext_4cbec0_thiscall1(ecx);  // @26_43b9f0
  ecx = edx = 0;  // @27_43b9f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @28_43b9f0
  ecx = (u32)(ebx + 323);  // @29_43b9f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_43b9f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @31_43b9f0
  ecx = edx = 0;  // @32_43b9f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @33_43b9f0
  PV[1] = (u32)(eax);  // @34_43b9f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 48)))(ecx, PV[1], (u32)(0));  // @35_43b9f0
  ecx = edx = 0;  // @36_43b9f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @37_43b9f0
  if ((s32)(eax & eax) > 0) goto L43bb12;  // @38_43b9f0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @39_43b9f0
  goto L43bbb5;  // @40_43b9f0
  L43bb12:;
  PV[2] = (u32)(eax);  // @42_43b9f0
  eax = ext_41e290_cdecl1(PV[2]);  // @43_43b9f0
  ecx = edx = 0;  // @44_43b9f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @45_43b9f0
  edi = eax;  // @46_43b9f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_43b9f0
  ecx = (u32)(ebx + 323);  // @48_43b9f0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @49_43b9f0
  PV[4] = (u32)(edi);  // @50_43b9f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @51_43b9f0
  ecx = edx = 0;  // @52_43b9f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @53_43b9f0
  PV[5] = (u32)(eax);  // @54_43b9f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, PV[5], PV[4], PV[3], (u32)(0), (u32)(0));  // @55_43b9f0
  ecx = edx = 0;  // @56_43b9f0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @57_43b9f0
  ecx = ebx;  // @58_43b9f0
  PV[7] = (u32)(edi);  // @59_43b9f0
  eax = ext_61bbf0_thiscall4(ecx, PV[7], PV[6], (u32)(1));  // @60_43b9f0
  ecx = edx = 0;  // @61_43b9f0
  PV[8] = (u32)(edi);  // @62_43b9f0
  { u8 v = (u8)((((eax & eax) != 0) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @63_43b9f0
  eax = ext_41e2c0_cdecl1(PV[8]);  // @64_43b9f0
  ecx = edx = 0;  // @65_43b9f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; })) & 0xff);  // @66_43b9f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L43bbb5;  // @67_43b9f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @68_43b9f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_43b9f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6798712), (u32)(70));  // @70_43b9f0
  ecx = edx = 0;  // @71_43b9f0
  esi = eax;  // @72_43b9f0
  ecx = ebx;  // @73_43b9f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_43b9f0
  eax = ext_61bbe0_thiscall1(ecx);  // @75_43b9f0
  ecx = edx = 0;  // @76_43b9f0
  PV[9] = (u32)(eax);  // @77_43b9f0
  ecx = ebx;  // @78_43b9f0
  eax = ext_61bbd0_thiscall1(ecx);  // @79_43b9f0
  ecx = edx = 0;  // @80_43b9f0
  PV[10] = (u32)(eax);  // @81_43b9f0
  ecx = (u32)(ebx + 323);  // @82_43b9f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @83_43b9f0
  ecx = edx = 0;  // @84_43b9f0
  PV[11] = (u32)(eax);  // @85_43b9f0
  PV[12] = (u32)(esi);  // @86_43b9f0
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[12], (u32)(6798756), PV[11], PV[10], PV[9]);  // @87_43b9f0
  ecx = edx = 0;  // @88_43b9f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; })) & 0xff);  // @89_43b9f0
  L43bbb5:;
  SEH_LEAVE();  // @91_43b9f0
  ext_633654(G(u32, 0x6f5630));  // @92_43b9f0
  return eax;  // @93_43b9f0
}
PCREG(43b9f0, lifted_43b9f0);

