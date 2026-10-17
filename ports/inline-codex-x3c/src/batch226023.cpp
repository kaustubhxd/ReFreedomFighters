// batch226023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 THISCALL ext_440ce0_thiscall2(u32, u32) __asm__("ext_440ce0");
extern "C" u32 THISCALL ext_4444a0_thiscall1(u32) __asm__("ext_4444a0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da770_thiscall2(u32, u32) __asm__("ext_4da770");
extern "C" u32 THISCALL ext_4db860_thiscall2(u32, u32) __asm__("ext_4db860");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 ext_44a1f0_cdecl0(void) __asm__("ext_44a1f0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_444530(u32 ecx_in) {
  SEH_ENTER(0x665f5b);  // @h_444530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @1_444530
  eax = ext_4444a0_thiscall1(ecx);  // @2_444530
  ecx = edx = 0;  // @3_444530
  ecx = (u32)(EBP - 188);  // @4_444530
  eax = ext_4ccba0_thiscall1(ecx);  // @5_444530
  ecx = edx = 0;  // @6_444530
  ecx = (u32)(EBP - 220);  // @7_444530
  reg.state = (s32)((u32)(0));  // @8_444530
  eax = ext_440ce0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 184), sizeof v); (u32)v; }));  // @9_444530
  ecx = edx = 0;  // @10_444530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @11_444530
  if ((ebx & ebx) == 0) goto L444636;  // @12_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @13_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @14_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @15_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @16_444530
  L4445b4:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @18_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @19_444530
  edi = (edi & (u32)(4294967288));  // @20_444530
  eax = (eax & (u32)(4294967288));  // @21_444530
  ebx = (ebx + (u32)(8));  // @22_444530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @23_444530
  if (edi > eax) goto L4445ef;  // @24_444530
  esi = eax;  // @25_444530
  L4445d0:;
  PS[0] = edi;  // @27_444530
  ecx = (u32)(EBP - 188);  // @28_444530
  eax = ext_4cd540_thiscall2(ecx, (u32)(PS[0]));  // @29_444530
  ecx = edx = 0;  // @30_444530
  edi = (edi + (u32)(112));  // @31_444530
  if (edi <= esi) goto L4445d0;  // @32_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @33_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @34_444530
  L4445ef:;
  if (ebx != ecx) goto L44462c;  // @36_444530
  if ((esi & esi) == 0) goto L444630;  // @37_444530
  L4445f7:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L444630;  // @39_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @40_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @41_444530
  if ((esi & esi) == 0) goto L444630;  // @42_444530
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) < (u32)(2)) goto L4445f7;  // @43_444530
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xff);  // @44_444530
  ebx = (u32)(esi + 12);  // @45_444530
  if (((eax & 0xff) & (u32)(1)) == 0) goto L44461d;  // @46_444530
  ebx = (ebx + (u32)(4));  // @47_444530
  L44461d:;
  ecx = (eax & 0xff);  // @49_444530
  ecx = (ecx + (u32)(3));  // @50_444530
  ecx = (u32)(esi + ecx*4);  // @51_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @52_444530
  L44462c:;
  if ((ebx & ebx) != 0) goto L4445b4;  // @54_444530
  L444630:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @56_444530
  L444636:;
  ecx = (u32)(EBP - 220);  // @58_444530
  eax = ext_440ce0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 180), sizeof v); (u32)v; }));  // @59_444530
  ecx = edx = 0;  // @60_444530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @61_444530
  if ((ebx & ebx) == 0) goto L4446f6;  // @62_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @63_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @64_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @65_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @66_444530
  L444670:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @69_444530
  edi = (edi & (u32)(4294967288));  // @70_444530
  eax = (eax & (u32)(4294967288));  // @71_444530
  ebx = (ebx + (u32)(8));  // @72_444530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @73_444530
  if (edi > eax) goto L4446af;  // @74_444530
  esi = eax;  // @75_444530
  L444690:;
  PS[0] = edi;  // @77_444530
  ecx = (u32)(EBP - 188);  // @78_444530
  eax = ext_4cd540_thiscall2(ecx, (u32)(PS[0]));  // @79_444530
  ecx = edx = 0;  // @80_444530
  edi = (edi + (u32)(112));  // @81_444530
  if (edi <= esi) goto L444690;  // @82_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @83_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @84_444530
  L4446af:;
  if (ebx != ecx) goto L4446ec;  // @86_444530
  if ((esi & esi) == 0) goto L4446f0;  // @87_444530
  L4446b7:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4446f0;  // @89_444530
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @90_444530
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @91_444530
  if ((esi & esi) == 0) goto L4446f0;  // @92_444530
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) < (u32)(2)) goto L4446b7;  // @93_444530
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xff);  // @94_444530
  ebx = (u32)(esi + 12);  // @95_444530
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4446dd;  // @96_444530
  ebx = (ebx + (u32)(4));  // @97_444530
  L4446dd:;
  ecx = (eax & 0xff);  // @99_444530
  ecx = (ecx + (u32)(3));  // @100_444530
  ecx = (u32)(esi + ecx*4);  // @101_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @102_444530
  L4446ec:;
  if ((ebx & ebx) != 0) goto L444670;  // @104_444530
  L4446f0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @106_444530
  L4446f6:;
  ecx = (u32)(EBP - 220);  // @108_444530
  eax = ext_440ce0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 188), sizeof v); (u32)v; }));  // @109_444530
  ecx = edx = 0;  // @110_444530
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @111_444530
  if ((ebx & ebx) == 0) goto L4447b6;  // @112_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @113_444530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 220), sizeof v); (u32)v; });  // @114_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @115_444530
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @116_444530
  L444730:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @118_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @119_444530
  esi = (esi & (u32)(4294967288));  // @120_444530
  eax = (eax & (u32)(4294967288));  // @121_444530
  ebx = (ebx + (u32)(8));  // @122_444530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @123_444530
  if (esi > eax) goto L44476f;  // @124_444530
  edi = eax;  // @125_444530
  L444750:;
  PS[0] = esi;  // @127_444530
  ecx = (u32)(EBP - 188);  // @128_444530
  eax = ext_4cd540_thiscall2(ecx, (u32)(PS[0]));  // @129_444530
  ecx = edx = 0;  // @130_444530
  esi = (esi + (u32)(112));  // @131_444530
  if (esi <= edi) goto L444750;  // @132_444530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @133_444530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @134_444530
  L44476f:;
  if (ebx != ecx) goto L4447ac;  // @136_444530
  if ((edi & edi) == 0) goto L4447b0;  // @137_444530
  L444777:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4447b0;  // @139_444530
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @140_444530
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @141_444530
  if ((edi & edi) == 0) goto L4447b0;  // @142_444530
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) < (u32)(2)) goto L444777;  // @143_444530
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) & 0xff);  // @144_444530
  ebx = (u32)(edi + 12);  // @145_444530
  if (((eax & 0xff) & (u32)(1)) == 0) goto L44479d;  // @146_444530
  ebx = (ebx + (u32)(4));  // @147_444530
  L44479d:;
  ecx = (eax & 0xff);  // @149_444530
  ecx = (ecx + (u32)(3));  // @150_444530
  ecx = (u32)(edi + ecx*4);  // @151_444530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @152_444530
  L4447ac:;
  if ((ebx & ebx) != 0) goto L444730;  // @154_444530
  L4447b0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @156_444530
  L4447b6:;
  eax = (u32)(EBP - 232);  // @158_444530
  PS[0] = eax;  // @159_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @160_444530
  ecx = (u32)(EBP - 188);  // @161_444530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @162_444530
  ecx = edx = 0;  // @163_444530
  eax = (u32)(EBP - 232);  // @164_444530
  PS[0] = eax;  // @165_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @166_444530
  ecx = (u32)(EBP - 188);  // @167_444530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @168_444530
  ecx = edx = 0;  // @169_444530
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; }) == (u32)(0)) goto L444817;  // @170_444530
  L4447f0:;
  PS[0] = esi;  // @172_444530
  ecx = eax;  // @173_444530
  eax = ext_4da770_thiscall2(ecx, (u32)(PS[0]));  // @174_444530
  ecx = edx = 0;  // @175_444530
  eax = (u32)(EBP - 232);  // @176_444530
  PS[0] = eax;  // @177_444530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @178_444530
  ecx = (u32)(EBP - 188);  // @179_444530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @180_444530
  ecx = edx = 0;  // @181_444530
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; }) != (u32)(0)) goto L4447f0;  // @182_444530
  L444817:;
  ecx = (u32)(EBP - 188);  // @184_444530
  eax = ext_4ccf60_thiscall1(ecx);  // @185_444530
  ecx = edx = 0;  // @186_444530
  SEH_LEAVE();  // @187_444530
  ext_633654(G(u32, 0x6f5630));  // @188_444530
  return eax;  // @189_444530
}
PCREG(444530, lifted_444530);

extern "C" u32 THISCALL lifted_4ad9a0(u32 ecx_in) {
  SEH_ENTER(0x6688f1);  // @h_4ad9a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_4ad9a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @1_4ad9a0
  ebx = (u32)(esi + 282);  // @2_4ad9a0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @3_4ad9a0
  goto L4ad9ea;  // @4_4ad9a0
  L4ad9e4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @6_4ad9a0
  L4ad9ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_4ad9a0
  ecx = ebx;  // @9_4ad9a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @10_4ad9a0
  ecx = edx = 0;  // @11_4ad9a0
  if ((eax & eax) == 0) goto L4ada64;  // @12_4ad9a0
  if ((ebx & ebx) == 0) goto L4ad9ea;  // @13_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4ad9a0
  ecx = (u32)(EBP - 440);  // @15_4ad9a0
  PS[0] = ecx;  // @16_4ad9a0
  ecx = ebx;  // @17_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @18_4ad9a0
  ecx = edx = 0;  // @19_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_4ad9a0
  ecx = (u32)(EBP - 440);  // @21_4ad9a0
  PS[0] = ecx;  // @22_4ad9a0
  ecx = ebx;  // @23_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @24_4ad9a0
  ecx = edx = 0;  // @25_4ad9a0
  edi = eax;  // @26_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad9ea;  // @27_4ad9a0
  L4ada20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4ad9a0
  PS[0] = edi;  // @30_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @31_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @33_4ad9a0
  ecx = edx = 0;  // @34_4ad9a0
  ecx = eax;  // @35_4ad9a0
  if ((ecx & ecx) == 0) goto L4ada4b;  // @36_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @38_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050578));  // @39_4ad9a0
  ecx = edx = 0;  // @40_4ad9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4ada80;  // @41_4ad9a0
  L4ada4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @43_4ad9a0
  ecx = (u32)(EBP - 440);  // @44_4ad9a0
  PS[0] = ecx;  // @45_4ad9a0
  ecx = ebx;  // @46_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @47_4ad9a0
  ecx = edx = 0;  // @48_4ad9a0
  edi = eax;  // @49_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; }) != (u32)(0)) goto L4ada20;  // @50_4ad9a0
  L4ada64:;
  SEH_LEAVE();  // @52_4ad9a0
  ext_633654(G(u32, 0x6f5630));  // @53_4ad9a0
  return eax;  // @54_4ad9a0
  L4ada80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_4ad9a0
  PS[0] = edi;  // @57_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @58_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @60_4ad9a0
  ecx = edx = 0;  // @61_4ad9a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @62_4ad9a0
  if ((eax & eax) != 0) goto L4adafa;  // @63_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @64_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @66_4ad9a0
  ecx = edx = 0;  // @67_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @68_4ad9a0
  edi = eax;  // @69_4ad9a0
  eax = (u32)(EBP - 144);  // @70_4ad9a0
  PS[1] = eax;  // @71_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @73_4ad9a0
  ecx = edx = 0;  // @74_4ad9a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_4ad9a0
  ecx = eax;  // @76_4ad9a0
  reg.state = (s32)((u32)(0));  // @77_4ad9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @78_4ad9a0
  ecx = edx = 0;  // @79_4ad9a0
  PS[0] = eax;  // @80_4ad9a0
  PS[2] = edi;  // @81_4ad9a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6884388), (u32)(PS[0]));  // @82_4ad9a0
  ecx = edx = 0;  // @83_4ad9a0
  reg.state = (s32)((u32)(4294967295));  // @84_4ad9a0
  ecx = (u32)(EBP - 144);  // @85_4ad9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @86_4ad9a0
  ecx = edx = 0;  // @87_4ad9a0
  goto L4ad9e4;  // @88_4ad9a0
  L4adafa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_4ad9a0
  ecx = ebx;  // @91_4ad9a0
  PS[0] = edi;  // @92_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(PS[0]));  // @93_4ad9a0
  ecx = edx = 0;  // @94_4ad9a0
  if ((eax & eax) != 0) goto L4adbac;  // @95_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @96_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @98_4ad9a0
  ecx = edx = 0;  // @99_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @100_4ad9a0
  edi = eax;  // @101_4ad9a0
  eax = (u32)(EBP - 400);  // @102_4ad9a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @103_4ad9a0
  PS[1] = eax;  // @104_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @106_4ad9a0
  ecx = edx = 0;  // @107_4ad9a0
  ebx = eax;  // @108_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @109_4ad9a0
  eax = (u32)(EBP - 272);  // @110_4ad9a0
  PS[1] = eax;  // @111_4ad9a0
  reg.state = (s32)((u32)(1));  // @112_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @114_4ad9a0
  ecx = edx = 0;  // @115_4ad9a0
  esi = eax;  // @116_4ad9a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @117_4ad9a0
  ecx = ebx;  // @118_4ad9a0
  reg.state = (s32)((u32)(2));  // @119_4ad9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @120_4ad9a0
  ecx = edx = 0;  // @121_4ad9a0
  PS[0] = eax;  // @122_4ad9a0
  ecx = esi;  // @123_4ad9a0
  eax = ext_4cc1d0_cdecl1((u32)(PS[0]));  // @124_4ad9a0
  ecx = edx = 0;  // @125_4ad9a0
  PS[0] = eax;  // @126_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; }), (u32)(6884448), (u32)(PS[0]));  // @127_4ad9a0
  ecx = edx = 0;  // @128_4ad9a0
  ecx = (u32)(EBP - 272);  // @129_4ad9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @130_4ad9a0
  ecx = edx = 0;  // @131_4ad9a0
  ecx = (u32)(EBP - 400);  // @132_4ad9a0
  reg.state = (s32)((u32)(4294967295));  // @133_4ad9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @134_4ad9a0
  ecx = edx = 0;  // @135_4ad9a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @136_4ad9a0
  goto L4ad9e4;  // @137_4ad9a0
  L4adbac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @139_4ad9a0
  ecx = ebx;  // @140_4ad9a0
  PS[0] = edi;  // @141_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(PS[0]));  // @142_4ad9a0
  ecx = edx = 0;  // @143_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @144_4ad9a0
  if ((edx & edx) == 0) goto L4adbde;  // @145_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_4ad9a0
  PS[0] = edx;  // @147_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @148_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @150_4ad9a0
  ecx = edx = 0;  // @151_4ad9a0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @152_4ad9a0
  PS[1] = edi;  // @153_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @154_4ad9a0
  PS[2] = ecx;  // @155_4ad9a0
  ecx = eax;  // @156_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(0));  // @157_4ad9a0
  ecx = edx = 0;  // @158_4ad9a0
  L4adbde:;
  esi = (esi + (u32)(454));  // @160_4ad9a0
  if (esi == 0) goto L4ad9e4;  // @161_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @162_4ad9a0
  ecx = (u32)(EBP - 416);  // @163_4ad9a0
  PS[0] = ecx;  // @164_4ad9a0
  ecx = esi;  // @165_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @166_4ad9a0
  ecx = edx = 0;  // @167_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_4ad9a0
  ecx = (u32)(EBP - 416);  // @169_4ad9a0
  PS[0] = ecx;  // @170_4ad9a0
  ecx = esi;  // @171_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @172_4ad9a0
  ecx = edx = 0;  // @173_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad9e4;  // @174_4ad9a0
  L4adc13:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @176_4ad9a0
  PS[0] = eax;  // @177_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @178_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(PS[0]));  // @179_4ad9a0
  ecx = edx = 0;  // @180_4ad9a0
  ecx = eax;  // @181_4ad9a0
  if ((ecx & ecx) == 0) goto L4adc38;  // @182_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }) != edi) goto L4adc46;  // @183_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_4ad9a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @185_4ad9a0
  ecx = edx = 0;  // @186_4ad9a0
  L4adc38:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @188_4ad9a0
  ecx = (u32)(EBP - 416);  // @189_4ad9a0
  PS[0] = ecx;  // @190_4ad9a0
  ecx = esi;  // @191_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(PS[0]));  // @192_4ad9a0
  ecx = edx = 0;  // @193_4ad9a0
  L4adc46:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @195_4ad9a0
  ecx = (u32)(EBP - 416);  // @196_4ad9a0
  PS[0] = ecx;  // @197_4ad9a0
  ecx = esi;  // @198_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @199_4ad9a0
  ecx = edx = 0;  // @200_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; }) != (u32)(0)) goto L4adc13;  // @201_4ad9a0
  goto L4ad9e4;  // @202_4ad9a0
}
PCREG(4ad9a0, lifted_4ad9a0);

extern "C" u32 THISCALL lifted_512590(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_512590
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_512590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @2_512590
  ecx = edx = 0;  // @3_512590
  ecx = ebx;  // @4_512590
  eax = ext_44a1f0_cdecl0();  // @5_512590
  ecx = edx = 0;  // @6_512590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @7_512590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 291), &v, sizeof v); }  // @8_512590
  if ((edi & edi) == 0) goto L51274d;  // @9_512590
  L5125f0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L5126b6;  // @11_512590
  ecx = edi;  // @12_512590
  eax = ext_4dc110_thiscall1(ecx);  // @13_512590
  ecx = edx = 0;  // @14_512590
  edx = (u32)(6939940);  // @15_512590
  ecx = eax;  // @16_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @17_512590
  ecx = edx = 0;  // @18_512590
  if ((eax & eax) != 0) goto L51262a;  // @19_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @20_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @22_512590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @23_512590
  ecx = edx = 0;  // @24_512590
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L51269a;  // @25_512590
  L51262a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L5126b6;  // @27_512590
  ecx = edi;  // @28_512590
  eax = ext_4dc110_thiscall1(ecx);  // @29_512590
  ecx = edx = 0;  // @30_512590
  edx = (u32)(6939956);  // @31_512590
  ecx = eax;  // @32_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @33_512590
  ecx = edx = 0;  // @34_512590
  if ((eax & eax) != 0) goto L512664;  // @35_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @36_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @38_512590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @39_512590
  ecx = edx = 0;  // @40_512590
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L51269a;  // @41_512590
  L512664:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L5126b6;  // @43_512590
  ecx = edi;  // @44_512590
  eax = ext_4dc110_thiscall1(ecx);  // @45_512590
  ecx = edx = 0;  // @46_512590
  edx = (u32)(6939964);  // @47_512590
  ecx = eax;  // @48_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @49_512590
  ecx = edx = 0;  // @50_512590
  if ((eax & eax) != 0) goto L5126b6;  // @51_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @52_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @54_512590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @55_512590
  ecx = edx = 0;  // @56_512590
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5126b6;  // @57_512590
  L51269a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_512590
  PS[0] = edi;  // @60_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @63_512590
  ecx = edx = 0;  // @64_512590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 291), &v, sizeof v); }  // @65_512590
  goto L512742;  // @66_512590
  L5126b6:;
  ecx = edi;  // @68_512590
  eax = ext_4dc110_thiscall1(ecx);  // @69_512590
  ecx = edx = 0;  // @70_512590
  edx = (u32)(6939972);  // @71_512590
  ecx = eax;  // @72_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @73_512590
  ecx = edx = 0;  // @74_512590
  ecx = edi;  // @75_512590
  if ((eax & eax) != 0) goto L5126fb;  // @76_512590
  eax = ext_4db860_thiscall2(ecx, (u32)(1));  // @77_512590
  ecx = edx = 0;  // @78_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 295), sizeof v); (u32)v; });  // @79_512590
  PS[0] = edi;  // @80_512590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @81_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @83_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @85_512590
  ecx = edx = 0;  // @86_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 295), sizeof v); (u32)v; });  // @87_512590
  PS[0] = eax;  // @88_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, (u32)(PS[0]));  // @89_512590
  ecx = edx = 0;  // @90_512590
  goto L512742;  // @91_512590
  L5126fb:;
  eax = ext_4dc110_thiscall1(ecx);  // @93_512590
  ecx = edx = 0;  // @94_512590
  edx = (u32)(6939984);  // @95_512590
  ecx = eax;  // @96_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @97_512590
  ecx = edx = 0;  // @98_512590
  if ((eax & eax) != 0) goto L512742;  // @99_512590
  ecx = edi;  // @100_512590
  eax = ext_4db860_thiscall2(ecx, (u32)(1));  // @101_512590
  ecx = edx = 0;  // @102_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 299), sizeof v); (u32)v; });  // @103_512590
  PS[0] = edi;  // @104_512590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @105_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @107_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @109_512590
  ecx = edx = 0;  // @110_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 299), sizeof v); (u32)v; });  // @111_512590
  PS[0] = eax;  // @112_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, (u32)(PS[0]));  // @113_512590
  ecx = edx = 0;  // @114_512590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @115_512590
  L512742:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @117_512590
  if ((edi & edi) != 0) goto L5125f0;  // @118_512590
  L51274d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; });  // @120_512590
  if ((edx & edx) == 0) goto L5127b5;  // @121_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @122_512590
  PS[0] = edx;  // @123_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @124_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @125_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @126_512590
  ecx = edx = 0;  // @127_512590
  edi = eax;  // @128_512590
  ecx = edi;  // @129_512590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @130_512590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 268)))(ecx, (u32)(6878332), (u32)(-1));  // @131_512590
  ecx = edx = 0;  // @132_512590
  esi = eax;  // @133_512590
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) != 0) goto L512794;  // @134_512590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @135_512590
  ecx = esi;  // @136_512590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @137_512590
  ecx = edx = 0;  // @138_512590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @139_512590
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L5127ac;  // @140_512590
  L512794:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_512590
  ecx = esi;  // @143_512590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 76)))(ecx);  // @144_512590
  ecx = edx = 0;  // @145_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @146_512590
  ecx = esi;  // @147_512590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(256))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @148_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }));  // @149_512590
  ecx = edx = 0;  // @150_512590
  L5127ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @152_512590
  ecx = edi;  // @153_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(1));  // @154_512590
  ecx = edx = 0;  // @155_512590
  L5127b5:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L512825;  // @157_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @158_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_512590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6939836), (u32)(314));  // @160_512590
  ecx = edx = 0;  // @161_512590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @162_512590
  edi = eax;  // @163_512590
  eax = (u32)(EBP - 144);  // @164_512590
  ecx = ebx;  // @165_512590
  PS[1] = eax;  // @166_512590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @167_512590
  ecx = edx = 0;  // @168_512590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @169_512590
  ecx = eax;  // @170_512590
  reg.state = (s32)((u32)(0));  // @171_512590
  eax = ext_4cc1d0_thiscall1(ecx);  // @172_512590
  ecx = edx = 0;  // @173_512590
  PS[0] = eax;  // @174_512590
  PS[2] = edi;  // @175_512590
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6940000), (u32)(PS[0]));  // @176_512590
  ecx = edx = 0;  // @177_512590
  reg.state = (s32)((u32)(4294967295));  // @178_512590
  ecx = (u32)(EBP - 144);  // @179_512590
  eax = ext_4cbec0_thiscall1(ecx);  // @180_512590
  ecx = edx = 0;  // @181_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @182_512590
  if ((eax & eax) == 0) goto L512824;  // @183_512590
  eax = ((u32(STDCALL *)(void))(eax))();  // @184_512590
  ecx = edx = 0;  // @185_512590
  goto L512825;  // @186_512590
  L512824:;
  __builtin_trap();  // @188_512590
  L512825:;
  SEH_LEAVE();  // @190_512590
  ext_633654(G(u32, 0x6f5630));  // @191_512590
  return eax;  // @192_512590
}
PCREG(512590, lifted_512590);

extern "C" u32 THISCALL lifted_4ad4d0(u32 ecx_in) {
  SEH_ENTER(0x668851);  // @h_4ad4d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_4ad4d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @1_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @2_4ad4d0
  ebx = (u32)(esi + 282);  // @3_4ad4d0
  ecx = ebx;  // @4_4ad4d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @5_4ad4d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @6_4ad4d0
  ecx = edx = 0;  // @7_4ad4d0
  if ((eax & eax) == 0) goto L4ad74f;  // @8_4ad4d0
  L4ad525:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_4ad4d0
  ecx = ebx;  // @11_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @12_4ad4d0
  ecx = edx = 0;  // @13_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4ad4d0
  edi = eax;  // @15_4ad4d0
  PS[0] = edi;  // @16_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @17_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @19_4ad4d0
  ecx = edx = 0;  // @20_4ad4d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @21_4ad4d0
  if ((eax & eax) == 0) goto L4ad740;  // @22_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_4ad4d0
  PS[0] = edi;  // @24_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @25_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @27_4ad4d0
  ecx = edx = 0;  // @28_4ad4d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @29_4ad4d0
  if ((eax & eax) != 0) goto L4ad5cb;  // @30_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @31_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @33_4ad4d0
  ecx = edx = 0;  // @34_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @35_4ad4d0
  edi = eax;  // @36_4ad4d0
  eax = (u32)(EBP - 144);  // @37_4ad4d0
  PS[1] = eax;  // @38_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @40_4ad4d0
  ecx = edx = 0;  // @41_4ad4d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_4ad4d0
  ecx = eax;  // @43_4ad4d0
  reg.state = (s32)((u32)(0));  // @44_4ad4d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @45_4ad4d0
  ecx = edx = 0;  // @46_4ad4d0
  PS[0] = eax;  // @47_4ad4d0
  PS[2] = edi;  // @48_4ad4d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6884388), (u32)(PS[0]));  // @49_4ad4d0
  ecx = edx = 0;  // @50_4ad4d0
  reg.state = (s32)((u32)(4294967295));  // @51_4ad4d0
  ecx = (u32)(EBP - 144);  // @52_4ad4d0
  eax = ext_4cbec0_thiscall1(ecx);  // @53_4ad4d0
  ecx = edx = 0;  // @54_4ad4d0
  goto L4ad72a;  // @55_4ad4d0
  L4ad5cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_4ad4d0
  ecx = ebx;  // @58_4ad4d0
  PS[0] = edi;  // @59_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(PS[0]));  // @60_4ad4d0
  ecx = edx = 0;  // @61_4ad4d0
  if ((eax & eax) != 0) goto L4ad67d;  // @62_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @63_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @65_4ad4d0
  ecx = edx = 0;  // @66_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @67_4ad4d0
  edi = eax;  // @68_4ad4d0
  eax = (u32)(EBP - 400);  // @69_4ad4d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @70_4ad4d0
  PS[1] = eax;  // @71_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @73_4ad4d0
  ecx = edx = 0;  // @74_4ad4d0
  ebx = eax;  // @75_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; });  // @76_4ad4d0
  eax = (u32)(EBP - 272);  // @77_4ad4d0
  PS[1] = eax;  // @78_4ad4d0
  reg.state = (s32)((u32)(1));  // @79_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @81_4ad4d0
  ecx = edx = 0;  // @82_4ad4d0
  esi = eax;  // @83_4ad4d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_4ad4d0
  ecx = ebx;  // @85_4ad4d0
  reg.state = (s32)((u32)(2));  // @86_4ad4d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @87_4ad4d0
  ecx = edx = 0;  // @88_4ad4d0
  PS[0] = eax;  // @89_4ad4d0
  ecx = esi;  // @90_4ad4d0
  eax = ext_4cc1d0_cdecl1((u32)(PS[0]));  // @91_4ad4d0
  ecx = edx = 0;  // @92_4ad4d0
  PS[0] = eax;  // @93_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }), (u32)(6884448), (u32)(PS[0]));  // @94_4ad4d0
  ecx = edx = 0;  // @95_4ad4d0
  ecx = (u32)(EBP - 272);  // @96_4ad4d0
  eax = ext_4cbec0_thiscall1(ecx);  // @97_4ad4d0
  ecx = edx = 0;  // @98_4ad4d0
  ecx = (u32)(EBP - 400);  // @99_4ad4d0
  reg.state = (s32)((u32)(4294967295));  // @100_4ad4d0
  eax = ext_4cbec0_thiscall1(ecx);  // @101_4ad4d0
  ecx = edx = 0;  // @102_4ad4d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @103_4ad4d0
  goto L4ad72a;  // @104_4ad4d0
  L4ad67d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @106_4ad4d0
  ecx = ebx;  // @107_4ad4d0
  PS[0] = edi;  // @108_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(PS[0]));  // @109_4ad4d0
  ecx = edx = 0;  // @110_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @111_4ad4d0
  if ((edx & edx) == 0) goto L4ad6af;  // @112_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @113_4ad4d0
  PS[0] = edx;  // @114_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @115_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @117_4ad4d0
  ecx = edx = 0;  // @118_4ad4d0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @119_4ad4d0
  PS[1] = edi;  // @120_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @121_4ad4d0
  PS[2] = ecx;  // @122_4ad4d0
  ecx = eax;  // @123_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(0));  // @124_4ad4d0
  ecx = edx = 0;  // @125_4ad4d0
  L4ad6af:;
  esi = (esi + (u32)(454));  // @127_4ad4d0
  if (esi == 0) goto L4ad72a;  // @128_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_4ad4d0
  ecx = (u32)(EBP - 412);  // @130_4ad4d0
  PS[0] = ecx;  // @131_4ad4d0
  ecx = esi;  // @132_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @133_4ad4d0
  ecx = edx = 0;  // @134_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @135_4ad4d0
  ecx = (u32)(EBP - 412);  // @136_4ad4d0
  PS[0] = ecx;  // @137_4ad4d0
  ecx = esi;  // @138_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @139_4ad4d0
  ecx = edx = 0;  // @140_4ad4d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad72a;  // @141_4ad4d0
  L4ad6e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @143_4ad4d0
  PS[0] = eax;  // @144_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(PS[0]));  // @146_4ad4d0
  ecx = edx = 0;  // @147_4ad4d0
  ecx = eax;  // @148_4ad4d0
  if ((ecx & ecx) == 0) goto L4ad705;  // @149_4ad4d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }) != edi) goto L4ad713;  // @150_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_4ad4d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @152_4ad4d0
  ecx = edx = 0;  // @153_4ad4d0
  L4ad705:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_4ad4d0
  ecx = (u32)(EBP - 412);  // @156_4ad4d0
  PS[0] = ecx;  // @157_4ad4d0
  ecx = esi;  // @158_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(PS[0]));  // @159_4ad4d0
  ecx = edx = 0;  // @160_4ad4d0
  L4ad713:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @162_4ad4d0
  ecx = (u32)(EBP - 412);  // @163_4ad4d0
  PS[0] = ecx;  // @164_4ad4d0
  ecx = esi;  // @165_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @166_4ad4d0
  ecx = edx = 0;  // @167_4ad4d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) != (u32)(0)) goto L4ad6e0;  // @168_4ad4d0
  L4ad72a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @170_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @172_4ad4d0
  ecx = edx = 0;  // @173_4ad4d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @174_4ad4d0
  L4ad740:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_4ad4d0
  ecx = ebx;  // @177_4ad4d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @178_4ad4d0
  ecx = edx = 0;  // @179_4ad4d0
  if ((eax & eax) != 0) goto L4ad525;  // @180_4ad4d0
  L4ad74f:;
  SEH_LEAVE();  // @182_4ad4d0
  ext_633654(G(u32, 0x6f5630));  // @183_4ad4d0
  return eax;  // @184_4ad4d0
}
PCREG(4ad4d0, lifted_4ad4d0);

