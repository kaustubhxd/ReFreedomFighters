// batch230009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_574600_fastcall3(u32, u32, u32) __asm__("ext_574600");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_563610_thiscall2(u32, u32) __asm__("ext_563610");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_575230(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_575230
  eax = ext_563610_thiscall2(ecx, (u32)(6984272));  // @1_575230
    // @2_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @3_575230
  edx = (u32)(EBP - 12);  // @4_575230
  ecx = (ecx + (u32)(72));  // @5_575230
  FL[3] = ecx;  // @6_575230
  edx = (edx - ecx);  // @7_575230
  FL[3] = edx;  // @8_575230
  L575260:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @10_575230
  ecx = (u32)(ecx + 1);  // @11_575230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @12_575230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @13_575230
  if (FL[2] != 0) goto L575260;  // @14_575230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 9), &v, sizeof v); }  // @15_575230
  edx = (u32)(EBP - 12);  // @16_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_575230
  PV[0] = (u32)(edx);  // @18_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @20_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6978504), PV[0]);  // @22_575230
  ecx = edx = 0;  // @23_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 432), &v, sizeof v); }  // @24_575230
  edx = (u32)(EBP - 12);  // @25_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_575230
  PV[1] = (u32)(edx);  // @27_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @29_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6984284), PV[1]);  // @31_575230
  ecx = edx = 0;  // @32_575230
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 440), sizeof v); (u32)v; });  // @33_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 436), &v, sizeof v); }  // @34_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[2]);  // @38_575230
  ecx = edx = 0;  // @39_575230
  ecx = eax;  // @40_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_575230
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @42_575230
  ecx = edx = 0;  // @43_575230
  edi = eax;  // @44_575230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @45_575230
  L5752e0:;
  FL[2] = (esi & esi);  // @47_575230
  if (FL[2] == 0) goto L57530e;  // @48_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @49_575230
  FL[2] = (ecx & ecx);  // @50_575230
  if (FL[2] == 0) goto L5752f3;  // @51_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @52_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @53_575230
  goto L5752f8;  // @54_575230
  L5752f3:;
  eax = (u32)(2097154);  // @56_575230
  L5752f8:;
  FL[2] = (eax & (u32)(1048576));  // @58_575230
  if (FL[2] == 0) goto L57530e;  // @59_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(1));  // @61_575230
  ecx = edx = 0;  // @62_575230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 96), sizeof v); (u32)v; });  // @63_575230
  goto L5752e0;  // @64_575230
  L57530e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_575230
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 452), sizeof v); (u32)v; });  // @67_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @70_575230
  ecx = edx = 0;  // @71_575230
  ecx = eax;  // @72_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @73_575230
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @74_575230
  ecx = edx = 0;  // @75_575230
  ecx = eax;  // @76_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @77_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 604)))(ecx, (u32)(6983668), (u32)(0));  // @78_575230
  ecx = edx = 0;  // @79_575230
  ecx = eax;  // @80_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @81_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @82_575230
  ecx = edx = 0;  // @83_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @85_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_575230
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @87_575230
  ecx = edx = 0;  // @88_575230
  ecx = (u32)(EBP - 160);  // @89_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @90_575230
  PV[4] = (u32)(ecx);  // @91_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @92_575230
  ecx = eax;  // @93_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6983544), PV[4]);  // @94_575230
  ecx = edx = 0;  // @95_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_575230
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @97_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @98_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @100_575230
  ecx = edx = 0;  // @101_575230
  ecx = eax;  // @102_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @103_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @104_575230
  ecx = edx = 0;  // @105_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 548), &v, sizeof v); }  // @106_575230
  eax = (u32)(EBP - 12);  // @107_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 576), &v, sizeof v); }  // @108_575230
  ecx = (u32)(6984320);  // @109_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 584), &v, sizeof v); }  // @110_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 612), &v, sizeof v); }  // @111_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 620), &v, sizeof v); }  // @112_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 648), &v, sizeof v); }  // @113_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 656), &v, sizeof v); }  // @114_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 684), &v, sizeof v); }  // @115_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 692), &v, sizeof v); }  // @116_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 720), &v, sizeof v); }  // @117_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 526), &v, sizeof v); }  // @118_575230
  L575413:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @120_575230
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_575230
  if (FL[0] != FL[1]) goto L575433;  // @122_575230
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @123_575230
  if (FL[2] == 0) goto L57542f;  // @124_575230
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @125_575230
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @126_575230
  if (FL[0] != FL[1]) goto L575433;  // @127_575230
  eax = (eax + (u32)(2));  // @128_575230
  FL[3] = eax;  // @129_575230
  ecx = (ecx + (u32)(2));  // @130_575230
  FL[3] = ecx;  // @131_575230
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @132_575230
  if (FL[2] != 0) goto L575413;  // @133_575230
  L57542f:;
  eax = 0;  // @135_575230
  FL[3] = eax;  // @136_575230
  goto L575438;  // @137_575230
  L575433:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @139_575230
  eax = (eax | (u32)(1));  // @140_575230
  FL[3] = eax;  // @141_575230
  L575438:;
  FL[2] = (eax & eax);  // @143_575230
  if (FL[2] == 0) goto L5757e2;  // @144_575230
  ecx = (u32)(6984324);  // @145_575230
  eax = (u32)(EBP - 12);  // @146_575230
  L575448:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @148_575230
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_575230
  if (FL[0] != FL[1]) goto L575468;  // @150_575230
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @151_575230
  if (FL[2] == 0) goto L575464;  // @152_575230
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @153_575230
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @154_575230
  if (FL[0] != FL[1]) goto L575468;  // @155_575230
  eax = (eax + (u32)(2));  // @156_575230
  FL[3] = eax;  // @157_575230
  ecx = (ecx + (u32)(2));  // @158_575230
  FL[3] = ecx;  // @159_575230
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @160_575230
  if (FL[2] != 0) goto L575448;  // @161_575230
  L575464:;
  eax = 0;  // @163_575230
  FL[3] = eax;  // @164_575230
  goto L57546d;  // @165_575230
  L575468:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @167_575230
  eax = (eax | (u32)(1));  // @168_575230
  FL[3] = eax;  // @169_575230
  L57546d:;
  FL[2] = (eax & eax);  // @171_575230
  if (FL[2] == 0) goto L5757e2;  // @172_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @173_575230
  edx = (u32)(EBP - 12);  // @174_575230
  PV[6] = (u32)(edx);  // @175_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[6], (u32)(0));  // @177_575230
  ecx = edx = 0;  // @178_575230
  FL[2] = (eax & eax);  // @179_575230
  if (FL[2] == 0) goto L5754bc;  // @180_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @181_575230
  esi = (u32)(ebx + 548);  // @182_575230
  L575493:;
  FL[2] = (ecx & ecx);  // @184_575230
  if (FL[2] == 0) goto L5754bc;  // @185_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @186_575230
  FL[2] = (edx & edx);  // @187_575230
  if (FL[2] == 0) goto L5754a6;  // @188_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @189_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @190_575230
  goto L5754ab;  // @191_575230
  L5754a6:;
  eax = (u32)(2097154);  // @193_575230
  L5754ab:;
  FL[2] = (eax & (u32)(1048576));  // @195_575230
  if (FL[2] == 0) goto L5754bc;  // @196_575230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @197_575230
  esi = (esi + (u32)(36));  // @198_575230
  FL[3] = esi;  // @199_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 96), sizeof v); (u32)v; });  // @200_575230
  goto L575493;  // @201_575230
  L5754bc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @203_575230
  esi = (u32)(ebx + 548);  // @204_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @205_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @206_575230
  FL[2] = (edx & edx);  // @207_575230
  { u32 a_ = edx ? edx : ecx; eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 740)))(ecx, a_); }  // w3e: hand fix of the conditional push (edx or this), one argument
  ecx = edx = 0;  // @215_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @216_575230
  ecx = (u32)(EBP - 12);  // @217_575230
  PV[9] = (u32)(ecx);  // @218_575230
  ecx = edi;  // @219_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[9], (u32)(0));  // @220_575230
  ecx = edx = 0;  // @221_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 456), &v, sizeof v); }  // @222_575230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @223_575230
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @224_575230
  L575500:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @226_575230
  FL[2] = (eax & eax);  // @227_575230
  if (FL[2] == 0) goto L575669;  // @228_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @229_575230
  edx = (u32)(6801640);  // @230_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 456), sizeof v); (u32)v; });  // @231_575230
  FL[2] = (eax & eax);  // @232_575230
  if (FL[2] != 0) edx = eax;  // @233_575230
  PV[10] = (u32)(edx);  // @234_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[10], (u32)(0));  // @236_575230
  ecx = edx = 0;  // @237_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @238_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6984336), sizeof v); (u32)v; });  // @239_575230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6984328) + 0), 4); v; });  // @240_575230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6984328) + 4), 4); v; });  // @241_575230
  X0[2] = 0;  // @242_575230
  X0[3] = 0;  // @243_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 132), &v, sizeof v); }  // @244_575230
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6984340), sizeof v); (u32)v; })) & 0xffff);  // @245_575230
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @246_575230
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6984342), sizeof v); (u32)v; })) & 0xff);  // @247_575230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 126), &v, sizeof v); }  // @248_575230
  eax = (u32)(EBP - 125);  // @249_575230
  PV[11] = (u32)(eax);  // @250_575230
  __builtin_memcpy((void *)((u32)(EBP - 140) + 0), &X0[0], 4);  // @251_575230
  __builtin_memcpy((void *)((u32)(EBP - 140) + 4), &X0[1], 4);  // @252_575230
  eax = ext_634d10_cdecl3(PV[11], (u32)(0), (u32)(113));  // @253_575230
    // @254_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @255_575230
  edx = (u32)(6801640);  // @256_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @257_575230
  FL[2] = (eax & eax);  // @258_575230
  if (FL[2] != 0) edx = eax;  // @259_575230
  esi = edx;  // @260_575230
  L575580:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @262_575230
  edx = (edx + 1);  // @263_575230
  FL[3] = edx;  // @264_575230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @265_575230
  if (FL[2] != 0) goto L575580;  // @266_575230
  edi = (u32)(EBP - 140);  // @267_575230
  edx = (edx - esi);  // @268_575230
  FL[3] = edx;  // @269_575230
  edi = (edi - 1);  // @270_575230
  FL[3] = edi;  // @271_575230
  L575590:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @273_575230
  edi = (edi + 1);  // @274_575230
  FL[3] = edi;  // @275_575230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @276_575230
  if (FL[2] != 0) goto L575590;  // @277_575230
  ecx = edx;  // @278_575230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @279_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 456), sizeof v); (u32)v; });  // @280_575230
  ecx = (ecx >> (u32)(2));  // @281_575230
  FL[3] = ecx;  // @282_575230
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @283_575230
  ecx = edx;  // @284_575230
  ecx = (ecx & (u32)(3));  // @285_575230
  FL[3] = ecx;  // @286_575230
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @287_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @288_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @289_575230
  FL[2] = (eax & eax);  // @290_575230
  if (FL[2] == 0) goto L575639;  // @291_575230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @292_575230
  L5755c5:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @294_575230
  ecx = (u32)(6801640);  // @295_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @296_575230
  FL[2] = (eax & eax);  // @297_575230
  if (FL[2] != 0) ecx = eax;  // @298_575230
  eax = (u32)(EBP - 140);  // @299_575230
  L5755e0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @301_575230
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @302_575230
  if (FL[0] != FL[1]) goto L575600;  // @303_575230
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @304_575230
  if (FL[2] == 0) goto L5755fc;  // @305_575230
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @306_575230
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @307_575230
  if (FL[0] != FL[1]) goto L575600;  // @308_575230
  ecx = (ecx + (u32)(2));  // @309_575230
  FL[3] = ecx;  // @310_575230
  eax = (eax + (u32)(2));  // @311_575230
  FL[3] = eax;  // @312_575230
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @313_575230
  if (FL[2] != 0) goto L5755e0;  // @314_575230
  L5755fc:;
  eax = 0;  // @316_575230
  FL[3] = eax;  // @317_575230
  goto L575605;  // @318_575230
  L575600:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @320_575230
  eax = (eax | (u32)(1));  // @321_575230
  FL[3] = eax;  // @322_575230
  L575605:;
  FL[2] = (eax & eax);  // @324_575230
  if (FL[2] != 0) goto L575613;  // @325_575230
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 153), &v, sizeof v); }  // @326_575230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @327_575230
  L575613:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 456), sizeof v); (u32)v; });  // @329_575230
  edx = (u32)(EBP - 168);  // @330_575230
  PV[12] = (u32)(edx);  // @331_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @332_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[12]);  // @333_575230
  ecx = edx = 0;  // @334_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @335_575230
  FL[2] = (eax & eax);  // @336_575230
  if (FL[2] != 0) goto L5755c5;  // @337_575230
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 153), sizeof v); (u32)v; })) & 0xff);  // @338_575230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @339_575230
  if (FL[2] != 0) goto L575663;  // @340_575230
  L575639:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @342_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @343_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6984344), (u32)(238));  // @344_575230
  ecx = edx = 0;  // @345_575230
  edx = (u32)(EBP - 140);  // @346_575230
  PV[13] = (u32)(edx);  // @347_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @348_575230
  PV[14] = (u32)(eax);  // @349_575230
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[14], (u32)(6984384), PV[13]);  // @350_575230
  ecx = edx = 0;  // @351_575230
  L575663:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @353_575230
  L575669:;
  esi = (esi + (u32)(36));  // @355_575230
  FL[3] = esi;  // @356_575230
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @357_575230
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @358_575230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @359_575230
  if (FL[3] != 0) goto L575500;  // @360_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @361_575230
  edx = (u32)(EBP - 12);  // @362_575230
  PV[15] = (u32)(edx);  // @363_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[15], (u32)(0));  // @365_575230
  ecx = edx = 0;  // @366_575230
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 496), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @367_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 526), &v, sizeof v); }  // @368_575230
  if (FL[0] != FL[1]) goto L575754;  // @369_575230
  FL[2] = (eax & eax);  // @370_575230
  if (FL[2] == 0) goto L575754;  // @371_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @372_575230
  ecx = eax;  // @373_575230
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 44)))(ecx);  // @374_575230
  ecx = edx = 0;  // @375_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 526), sizeof v); (u32)v; });  // @376_575230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @377_575230
  L5756c0:;
  FL[2] = (edi & edi);  // @379_575230
  if (FL[2] == 0) goto L575754;  // @380_575230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @381_575230
  FL[2] = (esi & esi);  // @382_575230
  if (FL[2] == 0) goto L5756d7;  // @383_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @384_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @385_575230
  goto L5756dc;  // @386_575230
  L5756d7:;
  eax = (u32)(2097154);  // @388_575230
  L5756dc:;
  FL[2] = (eax & (u32)(1048576));  // @390_575230
  if (FL[2] == 0) goto L575754;  // @391_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @392_575230
  eax = (u32)(EBP - 152);  // @393_575230
  PV[16] = (u32)(eax);  // @394_575230
  eax = ext_4db500_thiscall2(ecx, PV[16]);  // @395_575230
  edx = 0;  // @396_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @397_575230
  ecx = (u32)(EBP - 152);  // @398_575230
  PV[17] = (u32)(ecx);  // @399_575230
  ecx = esi;  // @400_575230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 111), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @401_575230
  X0[0] = F2U((float)(s32)X0[0]);  // @402_575230
  X0[1] = F2U((float)(s32)X0[1]);  // @403_575230
  X0[2] = F2U((float)(s32)X0[2]);  // @404_575230
  X0[3] = F2U((float)(s32)X0[3]);  // @405_575230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 152) + 0), 4); v; })));  // @406_575230
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @407_575230
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @408_575230
  X0[0] = F2U((float)(s32)X0[0]);  // @409_575230
  X0[1] = F2U((float)(s32)X0[1]);  // @410_575230
  X0[2] = F2U((float)(s32)X0[2]);  // @411_575230
  X0[3] = F2U((float)(s32)X0[3]);  // @412_575230
  __builtin_memcpy((void *)((u32)(EBP - 152) + 0), &X0[0], 4);  // @413_575230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 115), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @414_575230
  X0[0] = F2U((float)(s32)X0[0]);  // @415_575230
  X0[1] = F2U((float)(s32)X0[1]);  // @416_575230
  X0[2] = F2U((float)(s32)X0[2]);  // @417_575230
  X0[3] = F2U((float)(s32)X0[3]);  // @418_575230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 148) + 0), 4); v; })));  // @419_575230
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @420_575230
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @421_575230
  X0[0] = F2U((float)(s32)X0[0]);  // @422_575230
  X0[1] = F2U((float)(s32)X0[1]);  // @423_575230
  X0[2] = F2U((float)(s32)X0[2]);  // @424_575230
  X0[3] = F2U((float)(s32)X0[3]);  // @425_575230
  __builtin_memcpy((void *)((u32)(EBP - 148) + 0), &X0[0], 4);  // @426_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @427_575230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[17]);  // @428_575230
  ecx = edx = 0;  // @429_575230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @430_575230
  goto L5756c0;  // @431_575230
  L575754:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @433_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @434_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @435_575230
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @436_575230
  ecx = edx = 0;  // @437_575230
  ecx = (u32)(EBP - 164);  // @438_575230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @439_575230
  PV[18] = (u32)(ecx);  // @440_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @441_575230
  ecx = eax;  // @442_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6977420), PV[18]);  // @443_575230
  ecx = edx = 0;  // @444_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @445_575230
  ecx = ebx;  // @446_575230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 530), &v, sizeof v); }  // @447_575230
  eax = ext_574600_fastcall3(ecx, edx, (u32)(2));  // @448_575230
  ecx = edx = 0;  // @449_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 476), sizeof v); (u32)v; });  // @450_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @451_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6984440), (u32)(0));  // @452_575230
  ecx = edx = 0;  // @453_575230
  ecx = eax;  // @454_575230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 92), &v, sizeof v); }  // @455_575230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 548), sizeof v); (u32)v; });  // @456_575230
  FL[2] = (edx & edx);  // @457_575230
  if (FL[2] == 0) goto L5757e2;  // @458_575230
  FL[2] = (ecx & ecx);  // @459_575230
  if (FL[2] == 0) goto L5757e2;  // @460_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @461_575230
  PV[19] = (u32)(edx);  // @462_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[19], (u32)(3));  // @463_575230
  ecx = edx = 0;  // @464_575230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 548), sizeof v); (u32)v; });  // @465_575230
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @466_575230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @467_575230
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[20], (u32)(4));  // @468_575230
  ecx = edx = 0;  // @469_575230
  L5757e2:;
  ext_633654(G(u32, 0x6f5630));  // @471_575230
  return eax;  // @472_575230
}
PCREG(575230, lifted_575230);

