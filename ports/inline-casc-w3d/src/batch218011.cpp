// batch218011.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4637f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666a2d);  // @h_4637f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4637f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4637f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @3_4637f0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) != (u32)(0)) goto L463838;  // @4_4637f0
  eax = 0;  // @5_4637f0
  goto L46390f;  // @6_4637f0
  L463838:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4637f0
  esi = 0;  // @9_4637f0
  PV[0] = (u32)(edx);  // @10_4637f0
  edx = (u32)(EBP - 144);  // @11_4637f0
  PV[1] = (u32)(edx);  // @12_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, PV[1], PV[0]);  // @14_4637f0
  ecx = edx = 0;  // @15_4637f0
  ecx = eax;  // @16_4637f0
  reg.state = (s32)(esi);  // @17_4637f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @18_4637f0
  ecx = edx = 0;  // @19_4637f0
  ecx = (u32)(EBP - 144);  // @20_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @21_4637f0
  reg.state = (s32)((u32)(4294967295));  // @22_4637f0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_4637f0
  ecx = edx = 0;  // @24_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @26_4637f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) == esi) goto L46390d;  // @27_4637f0
  eax = ext_41e290_cdecl1((u32)(44));  // @28_4637f0
  ecx = edx = 0;  // @29_4637f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @30_4637f0
  reg.state = (s32)((u32)(1));  // @31_4637f0
  if ((eax & eax) == 0) goto L4638ac;  // @32_4637f0
  ecx = eax;  // @33_4637f0
  eax = ext_4e5000_thiscall1(ecx);  // @34_4637f0
  ecx = edx = 0;  // @35_4637f0
  esi = eax;  // @36_4637f0
  goto L4638ae;  // @37_4637f0
  L4638ac:;
  esi = 0;  // @39_4637f0
  L4638ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @41_4637f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @42_4637f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @43_4637f0
  reg.state = (s32)((u32)(4294967295));  // @44_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; });  // @45_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @47_4637f0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @48_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @49_4637f0
  PV[3] = (u32)(ecx);  // @50_4637f0
  PV[4] = (u32)(ebx);  // @51_4637f0
  PV[5] = (u32)(edi);  // @52_4637f0
  ecx = esi;  // @53_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, PV[5], PV[4], PV[3], PV[2]);  // @54_4637f0
  ecx = edx = 0;  // @55_4637f0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46390d;  // @56_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @57_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4637f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6838324), (u32)(453));  // @59_4637f0
  ecx = edx = 0;  // @60_4637f0
  PV[6] = (u32)(ebx);  // @61_4637f0
  PV[7] = (u32)(eax);  // @62_4637f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_4637f0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(6838400), PV[6]);  // @64_4637f0
  ecx = edx = 0;  // @65_4637f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_4637f0
  ecx = esi;  // @67_4637f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @68_4637f0
  ecx = edx = 0;  // @69_4637f0
  esi = 0;  // @70_4637f0
  L46390d:;
  eax = esi;  // @72_4637f0
  L46390f:;
  SEH_LEAVE();  // @74_4637f0
  ext_633654(G(u32, 0x6f5630));  // @75_4637f0
  return eax;  // @76_4637f0
}
PCREG(4637f0, lifted_4637f0);

