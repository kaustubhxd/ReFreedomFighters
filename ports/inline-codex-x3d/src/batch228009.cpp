// batch228009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_603a50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dc9f);  // @h_603a50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_603a50
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @2_603a50
  eax = ext_41e290_cdecl1((u32)(24));  // @3_603a50
  ecx = edx = 0;  // @4_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_603a50
  reg.state = (s32)((u32)(0));  // @6_603a50
  if ((eax & eax) == 0) goto L603aa7;  // @7_603a50
  PV[0] = (u32)(esi);  // @8_603a50
  ecx = eax;  // @9_603a50
  eax = ext_603500_thiscall2(ecx, PV[0]);  // @10_603a50
  ecx = edx = 0;  // @11_603a50
  edi = eax;  // @12_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @13_603a50
  goto L603aac;  // @14_603a50
  L603aa7:;
  edi = 0;  // @16_603a50
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @17_603a50
  L603aac:;
  esi = 0;  // @19_603a50
  reg.state = (s32)((u32)(4294967295));  // @20_603a50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }) <= esi) goto L603b6f;  // @21_603a50
  L603ac0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @23_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @24_603a50
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L603af1;  // @25_603a50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @26_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_603a50
  ebx = (ebx + esi);  // @28_603a50
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L603aea;  // @29_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @30_603a50
  if ((eax & eax) == 0) goto L603ae9;  // @31_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_603a50
  ecx = edx = 0;  // @33_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_603a50
  ebx = (u32)(eax + ebx*8);  // @35_603a50
  goto L603b19;  // @36_603a50
  L603ae9:;
  __builtin_trap();  // @38_603a50
  L603aea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_603a50
  ebx = (u32)(eax + ebx*8);  // @41_603a50
  goto L603b19;  // @42_603a50
  L603af1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @44_603a50
  if ((eax & eax) == 0) goto L603afe;  // @45_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @46_603a50
  ecx = edx = 0;  // @47_603a50
  goto L603aff;  // @48_603a50
  L603afe:;
  __builtin_trap();  // @50_603a50
  L603aff:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_603a50
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L603b14;  // @53_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @54_603a50
  if ((eax & eax) == 0) goto L603b13;  // @55_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @56_603a50
  ecx = edx = 0;  // @57_603a50
  goto L603b14;  // @58_603a50
  L603b13:;
  __builtin_trap();  // @60_603a50
  L603b14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_603a50
  ebx = (u32)(eax + esi*8);  // @63_603a50
  L603b19:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @65_603a50
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; })) goto L603b2f;  // @66_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @67_603a50
  if ((eax & eax) == 0) goto L603b2e;  // @68_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @69_603a50
  ecx = edx = 0;  // @70_603a50
  goto L603b2f;  // @71_603a50
  L603b2e:;
  __builtin_trap();  // @73_603a50
  L603b2f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @75_603a50
  edi = (u32)(eax + esi*8);  // @76_603a50
  if (ebx == edi) goto L603b5f;  // @77_603a50
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) != (u32)(4)) goto L603b46;  // @78_603a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @81_603a50
  ecx = edx = 0;  // @82_603a50
  L603b46:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == (u32)(4)) goto L603b50;  // @84_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @85_603a50
  goto L603b57;  // @86_603a50
  L603b50:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @88_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @90_603a50
  ecx = edx = 0;  // @91_603a50
  L603b57:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @93_603a50
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @94_603a50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @95_603a50
  L603b5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @97_603a50
  esi = (esi + 1);  // @98_603a50
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; })) goto L603ac0;  // @99_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @100_603a50
  L603b6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @102_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @103_603a50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) <= (u32)(0)) goto L603b9f;  // @104_603a50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @105_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_603a50
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L603b98;  // @107_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @108_603a50
  if ((eax & eax) == 0) goto L603b97;  // @109_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @110_603a50
  ecx = edx = 0;  // @111_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_603a50
  esi = (u32)(eax + ebx*8);  // @113_603a50
  goto L603bc5;  // @114_603a50
  L603b97:;
  __builtin_trap();  // @116_603a50
  L603b98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @118_603a50
  esi = (u32)(eax + ebx*8);  // @119_603a50
  goto L603bc5;  // @120_603a50
  L603b9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @122_603a50
  if ((eax & eax) == 0) goto L603bac;  // @123_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @124_603a50
  ecx = edx = 0;  // @125_603a50
  goto L603bad;  // @126_603a50
  L603bac:;
  __builtin_trap();  // @128_603a50
  L603bad:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_603a50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) > (u32)(0)) goto L603bc3;  // @131_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @132_603a50
  if ((eax & eax) == 0) goto L603bc2;  // @133_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @134_603a50
  ecx = edx = 0;  // @135_603a50
  goto L603bc3;  // @136_603a50
  L603bc2:;
  __builtin_trap();  // @138_603a50
  L603bc3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_603a50
  L603bc5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @142_603a50
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L603bd7;  // @143_603a50
  if ((eax & 0xff) != (u32)(4)) goto L603be4;  // @144_603a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @147_603a50
  ecx = edx = 0;  // @148_603a50
  L603bd7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @150_603a50
  ecx = edi;  // @151_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @152_603a50
  ecx = edx = 0;  // @153_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @154_603a50
  { u8 v = (u8)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @155_603a50
  L603be4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @157_603a50
  ecx = edi;  // @158_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @159_603a50
  ecx = edx = 0;  // @160_603a50
  SEH_LEAVE();  // @161_603a50
  return eax;  // @162_603a50
}
PCREG(603a50, lifted_603a50);

extern "C" u32 THISCALL lifted_4ad770(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6688a1);  // @h_4ad770
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4ad770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ad770
  PV[0] = (u32)(edi);  // @3_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @4_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @6_4ad770
  ecx = edx = 0;  // @7_4ad770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @8_4ad770
  if ((eax & eax) != 0) goto L4ad816;  // @9_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @12_4ad770
  ecx = edx = 0;  // @13_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @14_4ad770
  edi = eax;  // @15_4ad770
  eax = (u32)(EBP - 144);  // @16_4ad770
  PV[1] = (u32)(eax);  // @17_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[1], (u32)(1));  // @19_4ad770
  ecx = edx = 0;  // @20_4ad770
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_4ad770
  ecx = eax;  // @22_4ad770
  reg.state = (s32)((u32)(0));  // @23_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @24_4ad770
  ecx = edx = 0;  // @25_4ad770
  PV[2] = (u32)(eax);  // @26_4ad770
  PV[3] = (u32)(edi);  // @27_4ad770
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[3], (u32)(6884388), PV[2]);  // @28_4ad770
  ecx = edx = 0;  // @29_4ad770
  ecx = (u32)(EBP - 144);  // @30_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @31_4ad770
  ecx = edx = 0;  // @32_4ad770
  goto L4ad97a;  // @33_4ad770
  L4ad816:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @35_4ad770
  ecx = (u32)(esi + 282);  // @36_4ad770
  PV[4] = (u32)(edi);  // @37_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, PV[4]);  // @38_4ad770
  ecx = edx = 0;  // @39_4ad770
  if ((eax & eax) != 0) goto L4ad8c3;  // @40_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @41_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @43_4ad770
  ecx = edx = 0;  // @44_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @45_4ad770
  edi = eax;  // @46_4ad770
  eax = (u32)(EBP - 400);  // @47_4ad770
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @48_4ad770
  PV[5] = (u32)(eax);  // @49_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[5], (u32)(1));  // @51_4ad770
  ecx = edx = 0;  // @52_4ad770
  ebx = eax;  // @53_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; });  // @54_4ad770
  eax = (u32)(EBP - 272);  // @55_4ad770
  PV[6] = (u32)(eax);  // @56_4ad770
  reg.state = (s32)((u32)(1));  // @57_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(1));  // @59_4ad770
  ecx = edx = 0;  // @60_4ad770
  esi = eax;  // @61_4ad770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @62_4ad770
  ecx = ebx;  // @63_4ad770
  reg.state = (s32)((u32)(2));  // @64_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_4ad770
  ecx = edx = 0;  // @66_4ad770
  PV[7] = (u32)(eax);  // @67_4ad770
  ecx = esi;  // @68_4ad770
  eax = ext_4cc1d0_cdecl1(PV[7]);  // @69_4ad770
  ecx = edx = 0;  // @70_4ad770
  PV[8] = (u32)(eax);  // @71_4ad770
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @72_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, PV[9], (u32)(6884448), PV[8]);  // @73_4ad770
  ecx = edx = 0;  // @74_4ad770
  ecx = (u32)(EBP - 272);  // @75_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @76_4ad770
  ecx = edx = 0;  // @77_4ad770
  ecx = (u32)(EBP - 400);  // @78_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @79_4ad770
  ecx = edx = 0;  // @80_4ad770
  goto L4ad97a;  // @81_4ad770
  L4ad8c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @83_4ad770
  ecx = (u32)(esi + 282);  // @84_4ad770
  PV[10] = (u32)(edi);  // @85_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[10]);  // @86_4ad770
  ecx = edx = 0;  // @87_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @88_4ad770
  if ((edx & edx) == 0) goto L4ad8fd;  // @89_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_4ad770
  PV[11] = (u32)(edx);  // @91_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @92_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @94_4ad770
  ecx = edx = 0;  // @95_4ad770
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @96_4ad770
  PV[12] = (u32)(edi);  // @97_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @98_4ad770
  PV[13] = (u32)(ecx);  // @99_4ad770
  ecx = eax;  // @100_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[13], PV[12], (u32)(0));  // @101_4ad770
  ecx = edx = 0;  // @102_4ad770
  L4ad8fd:;
  esi = (esi + (u32)(454));  // @104_4ad770
  if (esi == 0) goto L4ad97a;  // @105_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_4ad770
  ecx = (u32)(EBP - 412);  // @107_4ad770
  PV[14] = (u32)(ecx);  // @108_4ad770
  ecx = esi;  // @109_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @110_4ad770
  ecx = edx = 0;  // @111_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @112_4ad770
  ecx = (u32)(EBP - 412);  // @113_4ad770
  PV[15] = (u32)(ecx);  // @114_4ad770
  ecx = esi;  // @115_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @116_4ad770
  ecx = edx = 0;  // @117_4ad770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad97a;  // @118_4ad770
  L4ad930:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @120_4ad770
  PV[16] = (u32)(eax);  // @121_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[16]);  // @123_4ad770
  ecx = edx = 0;  // @124_4ad770
  ecx = eax;  // @125_4ad770
  if ((ecx & ecx) == 0) goto L4ad955;  // @126_4ad770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }) != edi) goto L4ad963;  // @127_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_4ad770
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @129_4ad770
  ecx = edx = 0;  // @130_4ad770
  L4ad955:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_4ad770
  ecx = (u32)(EBP - 412);  // @133_4ad770
  PV[17] = (u32)(ecx);  // @134_4ad770
  ecx = esi;  // @135_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[17]);  // @136_4ad770
  ecx = edx = 0;  // @137_4ad770
  L4ad963:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @139_4ad770
  ecx = (u32)(EBP - 412);  // @140_4ad770
  PV[18] = (u32)(ecx);  // @141_4ad770
  ecx = esi;  // @142_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[18]);  // @143_4ad770
  ecx = edx = 0;  // @144_4ad770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) != (u32)(0)) goto L4ad930;  // @145_4ad770
  L4ad97a:;
  SEH_LEAVE();  // @147_4ad770
  ext_633654(G(u32, 0x6f5630));  // @148_4ad770
  return eax;  // @149_4ad770
}
PCREG(4ad770, lifted_4ad770);

