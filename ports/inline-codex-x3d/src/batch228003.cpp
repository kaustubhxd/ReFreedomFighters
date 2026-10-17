// batch228003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_45cd90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x666733);  // @h_45cd90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ecx;  // @0_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 448), &v, sizeof v); }  // @1_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_45cd90
  edi = 0;  // @3_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 480), &v, sizeof v); }  // @4_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @5_45cd90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @6_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @7_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 476), &v, sizeof v); }  // @8_45cd90
  eax = ext_4da3a0_thiscall1(ecx);  // @9_45cd90
  ecx = edx = 0;  // @10_45cd90
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45cdf4;  // @11_45cd90
  eax = (u32)(edi + 1);  // @12_45cd90
  goto L45d079;  // @13_45cd90
  L45cdf4:;
  ecx = (u32)(EBP - 444);  // @15_45cd90
  eax = ext_4ccba0_thiscall1(ecx);  // @16_45cd90
  ecx = edx = 0;  // @17_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @18_45cd90
  reg.state = (s32)((u32)(0));  // @19_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @20_45cd90
  if ((ecx & ecx) == 0) goto L45ce90;  // @21_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_45cd90
  edx = (u32)(EBP - 472);  // @23_45cd90
  PV[0] = (u32)(edx);  // @24_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @25_45cd90
  ecx = edx = 0;  // @26_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @27_45cd90
  edx = (u32)(EBP - 472);  // @28_45cd90
  PV[1] = (u32)(edx);  // @29_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @30_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @32_45cd90
  ecx = edx = 0;  // @33_45cd90
  esi = eax;  // @34_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) == (u32)(0)) goto L45ce90;  // @35_45cd90
  L45ce40:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @37_45cd90
  PV[2] = (u32)(esi);  // @38_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @40_45cd90
  ecx = edx = 0;  // @41_45cd90
  if ((eax & eax) != 0) goto L45ce67;  // @42_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @43_45cd90
  edx = (u32)(EBP - 472);  // @44_45cd90
  PV[3] = (u32)(edx);  // @45_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @46_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[3]);  // @48_45cd90
  ecx = edx = 0;  // @49_45cd90
  goto L45ce73;  // @50_45cd90
  L45ce67:;
  PV[4] = (u32)(esi);  // @52_45cd90
  ecx = (u32)(EBP - 444);  // @53_45cd90
  eax = ext_4cd540_thiscall2(ecx, PV[4]);  // @54_45cd90
  ecx = edx = 0;  // @55_45cd90
  L45ce73:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @57_45cd90
  edx = (u32)(EBP - 472);  // @58_45cd90
  PV[5] = (u32)(edx);  // @59_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @60_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @62_45cd90
  ecx = edx = 0;  // @63_45cd90
  esi = eax;  // @64_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) != (u32)(0)) goto L45ce40;  // @65_45cd90
  L45ce90:;
  eax = (u32)(EBP - 472);  // @67_45cd90
  PV[6] = (u32)(eax);  // @68_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @69_45cd90
  ecx = (u32)(EBP - 444);  // @70_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @71_45cd90
  ecx = edx = 0;  // @72_45cd90
  eax = (u32)(EBP - 472);  // @73_45cd90
  PV[7] = (u32)(eax);  // @74_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @75_45cd90
  ecx = (u32)(EBP - 444);  // @76_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @77_45cd90
  ecx = edx = 0;  // @78_45cd90
  edx = eax;  // @79_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) == (u32)(0)) goto L45d052;  // @80_45cd90
  L45ced0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @82_45cd90
  PV[8] = (u32)(edx);  // @83_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[8]);  // @85_45cd90
  ecx = edx = 0;  // @86_45cd90
  esi = eax;  // @87_45cd90
  if ((esi & esi) == 0) goto L45d02d;  // @88_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @89_45cd90
  eax = ebx;  // @90_45cd90
  eax = (eax & (u32)(1));  // @91_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @92_45cd90
  if (eax == 0) goto L45cf03;  // @93_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4)) != 0) goto L45d027;  // @94_45cd90
  L45cf03:;
  eax = ebx;  // @96_45cd90
  eax = (eax & (u32)(2));  // @97_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @98_45cd90
  if (eax == 0) goto L45cf1a;  // @99_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(8)) != 0) goto L45d027;  // @100_45cd90
  L45cf1a:;
  if (ebx != (u32)(4)) goto L45cf28;  // @102_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (ebx & 0xff)) == 0) goto L45d027;  // @103_45cd90
  L45cf28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @105_45cd90
  eax = (eax & (u32)(4));  // @106_45cd90
  if (eax != 0) goto L45d097;  // @107_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L45d097;  // @108_45cd90
  if (ebx == (u32)(1)) goto L45d097;  // @109_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 476), sizeof v); (u32)v; });  // @110_45cd90
  if ((ecx & ecx) == 0) goto L45cf7e;  // @111_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_45cd90
  edx = (u32)(EBP - 144);  // @113_45cd90
  PV[9] = (u32)(edx);  // @114_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[9], (u32)(1));  // @115_45cd90
  ecx = edx = 0;  // @116_45cd90
  edi = (edi | (u32)(1));  // @117_45cd90
  reg.state = (s32)((u32)(1));  // @118_45cd90
  ecx = eax;  // @119_45cd90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @120_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @121_45cd90
  ecx = edx = 0;  // @122_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @123_45cd90
  goto L45cf88;  // @124_45cd90
  L45cf7e:;
  { u32 v = (u32)((u32)(6836600)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @126_45cd90
  L45cf88:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @128_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1620));  // @130_45cd90
  ecx = edx = 0;  // @131_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @132_45cd90
  ebx = eax;  // @133_45cd90
  eax = (u32)(EBP - 272);  // @134_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @135_45cd90
  PV[10] = (u32)(eax);  // @136_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @137_45cd90
  ecx = edi;  // @138_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[10], (u32)(1));  // @139_45cd90
  ecx = edx = 0;  // @140_45cd90
  edi = eax;  // @141_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_45cd90
  ecx = esi;  // @143_45cd90
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; });  // @144_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @145_45cd90
  reg.state = (s32)((u32)(2));  // @146_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[11]);  // @147_45cd90
  ecx = edx = 0;  // @148_45cd90
  PV[12] = (u32)(eax);  // @149_45cd90
  ecx = edi;  // @150_45cd90
  // 0x4cc1d0 leaves its caller-pushed argument for the later add esp, 0x14,
  // but reads ECX (`mov eax,[ecx]; ret`).  Preserve that register across the
  // call rather than treating it as an ordinary cdecl argument.
  eax = ext_4cc1d0_thiscall1(ecx);  // @151_45cd90
  edx = 0;  // @152_45cd90
  PV[13] = (u32)(eax);  // @153_45cd90
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; });  // @154_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 44)))(ecx, PV[14], (u32)(6836608), PV[13]);  // @155_45cd90
  ecx = edx = 0;  // @156_45cd90
  ecx = (u32)(EBP - 272);  // @157_45cd90
  eax = ext_4cbec0_thiscall1(ecx);  // @158_45cd90
  ecx = edx = 0;  // @159_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @160_45cd90
  reg.state = (s32)((u32)(0));  // @161_45cd90
  if (((ebx & 0xff) & (u32)(1)) == 0) goto L45d021;  // @162_45cd90
  ebx = (ebx & (u32)(4294967294));  // @163_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @164_45cd90
  L45d016:;
  ecx = (u32)(EBP - 144);  // @166_45cd90
  eax = ext_4cbec0_thiscall1(ecx);  // @167_45cd90
  ecx = edx = 0;  // @168_45cd90
  L45d021:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @170_45cd90
  L45d027:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @172_45cd90
  L45d02d:;
  eax = (u32)(EBP - 472);  // @174_45cd90
  PV[15] = (u32)(eax);  // @175_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @176_45cd90
  ecx = (u32)(EBP - 444);  // @177_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @178_45cd90
  ecx = edx = 0;  // @179_45cd90
  edx = eax;  // @180_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) != (u32)(0)) goto L45ced0;  // @181_45cd90
  L45d052:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (u32)(1)) goto L45d067;  // @183_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @184_45cd90
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @185_45cd90
  ecx = edx = 0;  // @186_45cd90
  L45d067:;
  esi = (u32)(1);  // @188_45cd90
  L45d06c:;
  ecx = (u32)(EBP - 444);  // @190_45cd90
  eax = ext_4ccf60_thiscall1(ecx);  // @191_45cd90
  ecx = edx = 0;  // @192_45cd90
  eax = esi;  // @193_45cd90
  L45d079:;
  SEH_LEAVE();  // @195_45cd90
  ext_633654(G(u32, 0x6f5630));  // @196_45cd90
  return eax;  // @197_45cd90
  L45d097:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L45d027;  // @199_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @200_45cd90
  if ((ebx & ecx) != 0) goto L45d0b2;  // @201_45cd90
  if (ebx == (u32)(4)) goto L45d0b2;  // @202_45cd90
  if (ebx != (u32)(32)) goto L45d027;  // @203_45cd90
  L45d0b2:;
  if ((eax & eax) != 0) goto L45d11b;  // @205_45cd90
  if (((ecx & 0xff) & (u32)(1)) == 0) goto L45d11b;  // @206_45cd90
  if (ebx == (u32)(1)) goto L45d11b;  // @207_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @208_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1634));  // @210_45cd90
  ecx = edx = 0;  // @211_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @212_45cd90
  ebx = eax;  // @213_45cd90
  eax = (u32)(EBP - 144);  // @214_45cd90
  ecx = edi;  // @215_45cd90
  PV[16] = (u32)(eax);  // @216_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @217_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[16], (u32)(1));  // @218_45cd90
  ecx = edx = 0;  // @219_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @220_45cd90
  ecx = eax;  // @221_45cd90
  reg.state = (s32)((u32)(3));  // @222_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @223_45cd90
  ecx = edx = 0;  // @224_45cd90
  PV[17] = (u32)(eax);  // @225_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @226_45cd90
  ecx = esi;  // @227_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[17]);  // @228_45cd90
  ecx = edx = 0;  // @229_45cd90
  PV[18] = (u32)(eax);  // @230_45cd90
  PV[19] = (u32)(ebx);  // @231_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, PV[19], (u32)(6836680), PV[18]);  // @232_45cd90
  ecx = edx = 0;  // @233_45cd90
  reg.state = (s32)((u32)(0));  // @234_45cd90
  goto L45d016;  // @235_45cd90
  L45d11b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @237_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @238_45cd90
  PV[20] = (u32)(edi);  // @239_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @240_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @241_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[20]);  // @242_45cd90
  ecx = edx = 0;  // @243_45cd90
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 480), sizeof v); (u32)v; });  // @244_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @245_45cd90
  ecx = esi;  // @246_45cd90
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @247_45cd90
  edi = eax;  // @248_45cd90
  PV[23] = (u32)(ebx);  // @249_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[23], PV[22], PV[21]);  // @250_45cd90
  ecx = edx = 0;  // @251_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @252_45cd90
  PV[24] = (u32)(edi);  // @253_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @254_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @255_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[24]);  // @256_45cd90
  ecx = edx = 0;  // @257_45cd90
  if ((eax & eax) == 0) goto L45d194;  // @258_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; }) == (u32)(0)) goto L45d168;  // @259_45cd90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @260_45cd90
  L45d168:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; }) == (u32)(0)) goto L45d175;  // @262_45cd90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @263_45cd90
  L45d175:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @265_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L45d189;  // @266_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @267_45cd90
  ecx = esi;  // @268_45cd90
  PV[25] = (u32)(ebx);  // @269_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[25]);  // @270_45cd90
  ecx = edx = 0;  // @271_45cd90
  L45d189:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @273_45cd90
  goto L45d02d;  // @274_45cd90
  L45d194:;
  esi = 0;  // @276_45cd90
  goto L45d06c;  // @277_45cd90
}
PCREG(45cd90, lifted_45cd90);

