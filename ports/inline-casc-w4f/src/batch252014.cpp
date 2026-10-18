// batch252014.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_53c210_fastcall3(u32, u32, u32) __asm__("ext_53c210");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_53c280(u32 ecx_in) {
  SEH_ENTER(0x66aa76);  // @h_53c280
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  ebx = ecx;  // @0_53c280
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @1_53c280
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @2_53c280
  FL[2] = (esi & esi);  // @3_53c280
  if (FL[2] != 0) goto L53c2e2;  // @4_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_53c280
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6957956), (u32)(147));  // @7_53c280
  ecx = edx = 0;  // @8_53c280
  PV[0] = (u32)(eax);  // @9_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_53c280
  eax = ((u32(*)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6958008));  // @11_53c280
  ecx = edx = 0;  // @12_53c280
  goto L53c56c;  // @13_53c280
  L53c2e2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_53c280
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4585), &v, sizeof v); }  // @16_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @17_53c280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4593), &v, sizeof v); }  // @18_53c280
  eax = edx;  // @19_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @20_53c280
  edx = (u32)(164);  // @21_53c280
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 4589), &v, sizeof v); }  // @22_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @23_53c280
  esi = (esi + (u32)(16));  // @24_53c280
  FL[3] = esi;  // @25_53c280
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 4597), &v, sizeof v); }  // @26_53c280
  ecx = 0;  // @27_53c280
  FL[3] = ecx;  // @28_53c280
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @29_53c280
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @30_53c280
  FL[1] = ecx;  // @31_53c280
  ecx = (0u - ecx);  // @32_53c280
  ecx = (ecx | eax);  // @33_53c280
  FL[3] = ecx;  // @34_53c280
  PV[1] = (u32)(ecx);  // @35_53c280
  eax = ext_41e290_cdecl1(PV[1]);  // @36_53c280
  ecx = edx = 0;  // @37_53c280
  ecx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4585), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @38_53c280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4601), &v, sizeof v); }  // @39_53c280
  PV[2] = (u32)(ecx);  // @40_53c280
  PV[3] = (u32)(esi);  // @41_53c280
  PV[4] = (u32)(eax);  // @42_53c280
  eax = ext_634d22_cdecl3(PV[4], PV[3], PV[2]);  // @43_53c280
    // @44_53c280
  eax = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4585), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @45_53c280
  ecx = 0;  // @46_53c280
  FL[3] = ecx;  // @47_53c280
  edx = (u32)(12);  // @48_53c280
  esi = (esi + eax);  // @49_53c280
  FL[3] = esi;  // @50_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4593), sizeof v); (u32)v; });  // @51_53c280
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @52_53c280
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @53_53c280
  FL[1] = ecx;  // @54_53c280
  ecx = (0u - ecx);  // @55_53c280
  ecx = (ecx | eax);  // @56_53c280
  FL[3] = ecx;  // @57_53c280
  PV[5] = (u32)(ecx);  // @58_53c280
  eax = ext_41e290_cdecl1(PV[5]);  // @59_53c280
  ecx = edx = 0;  // @60_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4593), sizeof v); (u32)v; });  // @61_53c280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4605), &v, sizeof v); }  // @62_53c280
  ecx = (u32)(ecx + ecx*2);  // @63_53c280
  ecx = (ecx << (u32)(2));  // @64_53c280
  FL[3] = ecx;  // @65_53c280
  PV[6] = (u32)(ecx);  // @66_53c280
  PV[7] = (u32)(esi);  // @67_53c280
  PV[8] = (u32)(eax);  // @68_53c280
  eax = ext_634d22_cdecl3(PV[8], PV[7], PV[6]);  // @69_53c280
    // @70_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4593), sizeof v); (u32)v; });  // @71_53c280
  ecx = 0;  // @72_53c280
  FL[3] = ecx;  // @73_53c280
  edx = (u32)(8);  // @74_53c280
  eax = (u32)(eax + eax*2);  // @75_53c280
  esi = (u32)(esi + eax*4);  // @76_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4589), sizeof v); (u32)v; });  // @77_53c280
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @78_53c280
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @79_53c280
  FL[1] = ecx;  // @80_53c280
  ecx = (0u - ecx);  // @81_53c280
  ecx = (ecx | eax);  // @82_53c280
  FL[3] = ecx;  // @83_53c280
  PV[9] = (u32)(ecx);  // @84_53c280
  eax = ext_41e290_cdecl1(PV[9]);  // @85_53c280
  ecx = edx = 0;  // @86_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4589), sizeof v); (u32)v; });  // @87_53c280
  ecx = (ecx << (u32)(3));  // @88_53c280
  FL[3] = ecx;  // @89_53c280
  PV[10] = (u32)(ecx);  // @90_53c280
  PV[11] = (u32)(esi);  // @91_53c280
  PV[12] = (u32)(eax);  // @92_53c280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4609), &v, sizeof v); }  // @93_53c280
  eax = ext_634d22_cdecl3(PV[12], PV[11], PV[10]);  // @94_53c280
    // @95_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4589), sizeof v); (u32)v; });  // @96_53c280
  ecx = 0;  // @97_53c280
  FL[3] = ecx;  // @98_53c280
  edx = (u32)(4);  // @99_53c280
  esi = (u32)(esi + eax*8);  // @100_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4597), sizeof v); (u32)v; });  // @101_53c280
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @102_53c280
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @103_53c280
  FL[1] = ecx;  // @104_53c280
  ecx = (0u - ecx);  // @105_53c280
  ecx = (ecx | eax);  // @106_53c280
  FL[3] = ecx;  // @107_53c280
  PV[13] = (u32)(ecx);  // @108_53c280
  eax = ext_41e290_cdecl1(PV[13]);  // @109_53c280
  ecx = edx = 0;  // @110_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4597), sizeof v); (u32)v; });  // @111_53c280
  ecx = (ecx << (u32)(2));  // @112_53c280
  FL[3] = ecx;  // @113_53c280
  PV[14] = (u32)(ecx);  // @114_53c280
  PV[15] = (u32)(esi);  // @115_53c280
  PV[16] = (u32)(eax);  // @116_53c280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4613), &v, sizeof v); }  // @117_53c280
  eax = ext_634d22_cdecl3(PV[16], PV[15], PV[14]);  // @118_53c280
    // @119_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4597), sizeof v); (u32)v; });  // @120_53c280
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @121_53c280
  edi = (u32)(esi + eax*4);  // @122_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @123_53c280
  ebx = (ebx - edi);  // @124_53c280
  FL[3] = ebx;  // @125_53c280
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @126_53c280
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @127_53c280
  FL[3] = ebx;  // @128_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @129_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @130_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @132_53c280
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @133_53c280
  ecx = edx = 0;  // @134_53c280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @135_53c280
  if (FL[2] != 0) goto L53c555;  // @136_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @137_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @138_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @139_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @140_53c280
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @141_53c280
  FL[2] = (ecx & ecx);  // @142_53c280
  if (FL[2] == 0) goto L53c555;  // @143_53c280
  L53c451:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_53c280
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @146_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @147_53c280
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @148_53c280
  if (FL[0] == FL[1]) goto L53c52a;  // @149_53c280
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097173));  // @150_53c280
  ecx = 0;  // @151_53c280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @152_53c280
  if (FL[2] == 0) goto L53c4cf;  // @153_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @154_53c280
  ecx = (u32)(EBP - 144);  // @155_53c280
  PV[17] = (u32)(ecx);  // @156_53c280
  ecx = esi;  // @157_53c280
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[17], (u32)(0));  // @158_53c280
  ecx = edx = 0;  // @159_53c280
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_53c280
  ecx = (u32)(EBP - 144);  // @161_53c280
  PV[18] = (u32)(ebx);  // @162_53c280
  reg.state = (s32)((u32)(0));  // @163_53c280
  eax = ext_4cc1d0_thiscall1(ecx);  // @164_53c280
    // @165_53c280
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @166_53c280
  ecx = eax;  // @167_53c280
  eax = ext_53c210_fastcall3(ecx, edx, PV[18]);  // @168_53c280
  ecx = edx = 0;  // @169_53c280
  PV[19] = (u32)(eax);  // @170_53c280
  ecx = esi;  // @171_53c280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 584)))(ecx, PV[19]);  // @172_53c280
  ecx = edx = 0;  // @173_53c280
  ecx = (u32)(EBP - 144);  // @174_53c280
  reg.state = (s32)((u32)(4294967295));  // @175_53c280
  eax = ext_4cbec0_thiscall1(ecx);  // @176_53c280
  ecx = edx = 0;  // @177_53c280
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @178_53c280
  L53c4cf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @180_53c280
  eax = ext_4db9a0_thiscall2(ecx, (u32)(1048609));  // @181_53c280
  ecx = 0;  // @182_53c280
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @183_53c280
  if (FL[2] == 0) goto L53c52a;  // @184_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @185_53c280
  ecx = (u32)(EBP - 272);  // @186_53c280
  PV[20] = (u32)(ecx);  // @187_53c280
  ecx = esi;  // @188_53c280
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, PV[20], (u32)(0));  // @189_53c280
  ecx = edx = 0;  // @190_53c280
  PV[21] = (u32)(ebx);  // @191_53c280
  ecx = (u32)(EBP - 272);  // @192_53c280
  reg.state = (s32)((u32)(1));  // @193_53c280
  eax = ext_4cc1d0_thiscall1(ecx);  // @194_53c280
    // @195_53c280
  edx = edi;  // @196_53c280
  ecx = eax;  // @197_53c280
  eax = ext_53c210_fastcall3(ecx, edx, PV[21]);  // @198_53c280
  ecx = edx = 0;  // @199_53c280
  ecx = (u32)(EBP - 272);  // @200_53c280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @201_53c280
  reg.state = (s32)((u32)(4294967295));  // @202_53c280
  eax = ext_4cbec0_thiscall1(ecx);  // @203_53c280
  ecx = edx = 0;  // @204_53c280
  L53c52a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @206_53c280
  edx = (u32)(EBP - 276);  // @207_53c280
  PV[22] = (u32)(edx);  // @208_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @209_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @210_53c280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @211_53c280
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[22]);  // @212_53c280
  ecx = edx = 0;  // @213_53c280
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @214_53c280
  FL[2] = (ecx & ecx);  // @215_53c280
  if (FL[2] != 0) goto L53c451;  // @216_53c280
  L53c555:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @218_53c280
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @219_53c280
  eax = ext_634273_cdecl2(PV[23], (u32)(1));  // @220_53c280
  ecx = edx = 0;  // @221_53c280
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @222_53c280
  L53c56c:;
  SEH_LEAVE();  // @224_53c280
  ext_633654(G(u32, 0x6f5630));  // @225_53c280
  return eax;  // @226_53c280
}
PCREG(53c280, lifted_53c280);

