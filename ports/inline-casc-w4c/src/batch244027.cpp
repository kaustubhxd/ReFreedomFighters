// batch244027.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_52d250_fastcall4(u32, u32, u32, u32) __asm__("ext_52d250");
extern "C" u32 STDCALL ext_532730_stdcall1(u32) __asm__("ext_532730");
extern "C" u32 THISCALL ext_421680_thiscall1(u32) __asm__("ext_421680");
extern "C" u32 THISCALL ext_421940_thiscall1(u32) __asm__("ext_421940");
extern "C" u32 THISCALL ext_42a4a0_thiscall2(u32, u32) __asm__("ext_42a4a0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4f3ab0_thiscall1(u32) __asm__("ext_4f3ab0");
extern "C" u32 THISCALL ext_530a40_thiscall1(u32) __asm__("ext_530a40");
extern "C" u32 THISCALL ext_531740_thiscall3(u32, u32, u32) __asm__("ext_531740");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_420ea0_cdecl1(...) __asm__("ext_420ea0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_41fad0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6641b6);  // @h_41fad0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_41fad0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_41fad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_41fad0
  PV[0] = (u32)(eax);  // @3_41fad0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @4_41fad0
  eax = ext_42a4a0_thiscall2(ecx, PV[0]);  // @5_41fad0
  ecx = edx = 0;  // @6_41fad0
  ecx = (u32)(edi + 7825);  // @7_41fad0
  reg.state = (s32)((u32)(0));  // @8_41fad0
  { u32 v = (u32)((u32)(6780996)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @9_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @10_41fad0
    // @11_41fad0
  ecx = (u32)(edi + 7953);  // @12_41fad0
  reg.state = (s32)((u32)(1));  // @13_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @14_41fad0
    // @15_41fad0
  ecx = (u32)(edi + 8081);  // @16_41fad0
  reg.state = (s32)((u32)(2));  // @17_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @18_41fad0
    // @19_41fad0
  ecx = (u32)(edi + 8209);  // @20_41fad0
  reg.state = (s32)((u32)(3));  // @21_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @22_41fad0
    // @23_41fad0
  ecx = (u32)(edi + 8337);  // @24_41fad0
  reg.state = (s32)((u32)(4));  // @25_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @26_41fad0
    // @27_41fad0
  ecx = (u32)(edi + 8465);  // @28_41fad0
  reg.state = (s32)((u32)(5));  // @29_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @30_41fad0
    // @31_41fad0
  ecx = (u32)(edi + 8593);  // @32_41fad0
  reg.state = (s32)((u32)(6));  // @33_41fad0
  eax = ext_4ccba0_thiscall1(ecx);  // @34_41fad0
    // @35_41fad0
  ebx = (u32)(edi + 8770);  // @36_41fad0
  reg.state = (s32)((u32)(7));  // @37_41fad0
  ecx = ebx;  // @38_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @39_41fad0
    // @40_41fad0
  ecx = (u32)(edi + 8902);  // @41_41fad0
  reg.state = (s32)((u32)(8));  // @42_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @43_41fad0
    // @44_41fad0
  ecx = (u32)(edi + 9030);  // @45_41fad0
  reg.state = (s32)((u32)(9));  // @46_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @47_41fad0
    // @48_41fad0
  ecx = (u32)(edi + 9179);  // @49_41fad0
  reg.state = (s32)((u32)(10));  // @50_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @51_41fad0
    // @52_41fad0
  ecx = (u32)(edi + 9307);  // @53_41fad0
  reg.state = (s32)((u32)(11));  // @54_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @55_41fad0
    // @56_41fad0
  ecx = (u32)(edi + 9435);  // @57_41fad0
  reg.state = (s32)((u32)(12));  // @58_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @59_41fad0
    // @60_41fad0
  ecx = (u32)(edi + 9563);  // @61_41fad0
  reg.state = (s32)((u32)(13));  // @62_41fad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @63_41fad0
    // @64_41fad0
  eax = (u32)(edi + 9707);  // @65_41fad0
  reg.state = (s32)((u32)(14));  // @66_41fad0
  PV[1] = (u32)(eax);  // @67_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 7819), &v, sizeof v); }  // @68_41fad0
  eax = ext_634d10_cdecl3(PV[1], (u32)(0), (u32)(152));  // @69_41fad0
    // @70_41fad0
  eax = ext_41e290_cdecl1((u32)(260));  // @71_41fad0
  ecx = edx = 0;  // @72_41fad0
  esi = eax;  // @73_41fad0
  PV[2] = (u32)(esi);  // @74_41fad0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2511), sizeof v); (u32)v; });  // @75_41fad0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67607c))(PV[3], PV[2], (u32)(260));  // @76_41fad0
  ecx = edx = 0;  // @77_41fad0
  PV[4] = (u32)(esi);  // @78_41fad0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[4], (u32)(92));  // @79_41fad0
  ecx = edx = 0;  // @80_41fad0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_41fad0
  ecx = (u32)(EBP - 144);  // @82_41fad0
  PV[5] = (u32)(esi);  // @83_41fad0
  eax = ext_4cbe80_thiscall2(ecx, PV[5]);  // @84_41fad0
  ecx = edx = 0;  // @85_41fad0
  eax = (u32)(EBP - 144);  // @86_41fad0
  reg.state = (s32)((u32)(15));  // @87_41fad0
  PV[6] = (u32)(eax);  // @88_41fad0
  ecx = (u32)(edi + 163);  // @89_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[6]);  // @90_41fad0
  ecx = edx = 0;  // @91_41fad0
  ecx = (u32)(EBP - 144);  // @92_41fad0
  reg.state = (s32)((u32)(14));  // @93_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @94_41fad0
  ecx = edx = 0;  // @95_41fad0
  PV[7] = (u32)(esi);  // @96_41fad0
  eax = ext_634273_cdecl2(PV[7], (u32)(1));  // @97_41fad0
  ecx = edx = 0;  // @98_41fad0
  ecx = edi;  // @99_41fad0
  eax = ext_421680_thiscall1(ecx);  // @100_41fad0
  ecx = edx = 0;  // @101_41fad0
  ecx = edi;  // @102_41fad0
  eax = ext_421940_thiscall1(ecx);  // @103_41fad0
  ecx = edx = 0;  // @104_41fad0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @105_41fad0
  if (FL[2] == 0) goto L41fe52;  // @106_41fad0
  ecx = (u32)(EBP - 144);  // @107_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 6823), &v, sizeof v); }  // @108_41fad0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 7824), &v, sizeof v); }  // @109_41fad0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9704), &v, sizeof v); }  // @110_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8898), &v, sizeof v); }  // @111_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9158), &v, sizeof v); }  // @112_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9162), &v, sizeof v); }  // @113_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782784));  // @114_41fad0
  ecx = edx = 0;  // @115_41fad0
  eax = (u32)(EBP - 144);  // @116_41fad0
  reg.state = (s32)((u32)(16));  // @117_41fad0
  PV[8] = (u32)(eax);  // @118_41fad0
  ecx = (u32)(edi + 7953);  // @119_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[8]);  // @120_41fad0
  ecx = edx = 0;  // @121_41fad0
  ecx = (u32)(EBP - 144);  // @122_41fad0
  reg.state = (s32)((u32)(14));  // @123_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @124_41fad0
  ecx = edx = 0;  // @125_41fad0
  eax = (u32)(EBP - 144);  // @126_41fad0
  { u32 v = (u32)((u32)(4332832)); __builtin_memcpy((void *)(u32)(edi + 9174), &v, sizeof v); }  // @127_41fad0
  PV[9] = (u32)(eax);  // @128_41fad0
  { u32 v = (u32)((u32)(120)); __builtin_memcpy((void *)(u32)(edi + 2531), &v, sizeof v); }  // @129_41fad0
  eax = ext_420ea0_cdecl1(PV[9]);  // @130_41fad0
  ecx = edx = 0;  // @131_41fad0
  PV[10] = (u32)(eax);  // @132_41fad0
  ecx = ebx;  // @133_41fad0
  reg.state = (s32)((u32)(17));  // @134_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[10]);  // @135_41fad0
  ecx = edx = 0;  // @136_41fad0
  ecx = (u32)(EBP - 144);  // @137_41fad0
  reg.state = (s32)((u32)(14));  // @138_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @139_41fad0
  ecx = edx = 0;  // @140_41fad0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(7328832), &v, sizeof v); }  // @141_41fad0
  eax = ((u32( *)(u32))(*(u32 *)0x676270))((u32)(4344080));  // @142_41fad0
  ecx = edx = 0;  // @143_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 9692), &v, sizeof v); }  // @144_41fad0
  ecx = (u32)(EBP - 144);  // @145_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782788));  // @146_41fad0
  ecx = edx = 0;  // @147_41fad0
  eax = (u32)(EBP - 144);  // @148_41fad0
  reg.state = (s32)((u32)(18));  // @149_41fad0
  PV[11] = (u32)(eax);  // @150_41fad0
  ecx = (u32)(edi + 7825);  // @151_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[11]);  // @152_41fad0
  ecx = edx = 0;  // @153_41fad0
  ecx = (u32)(EBP - 144);  // @154_41fad0
  reg.state = (s32)((u32)(14));  // @155_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @156_41fad0
  ecx = edx = 0;  // @157_41fad0
  ecx = (u32)(EBP - 144);  // @158_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782804));  // @159_41fad0
  ecx = edx = 0;  // @160_41fad0
  eax = (u32)(EBP - 144);  // @161_41fad0
  reg.state = (s32)((u32)(19));  // @162_41fad0
  PV[12] = (u32)(eax);  // @163_41fad0
  ecx = (u32)(edi + 8081);  // @164_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[12]);  // @165_41fad0
  ecx = edx = 0;  // @166_41fad0
  ecx = (u32)(EBP - 144);  // @167_41fad0
  reg.state = (s32)((u32)(14));  // @168_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @169_41fad0
  ecx = edx = 0;  // @170_41fad0
  ecx = (u32)(EBP - 144);  // @171_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782820));  // @172_41fad0
  ecx = edx = 0;  // @173_41fad0
  eax = (u32)(EBP - 144);  // @174_41fad0
  reg.state = (s32)((u32)(20));  // @175_41fad0
  PV[13] = (u32)(eax);  // @176_41fad0
  ecx = (u32)(edi + 1059);  // @177_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[13]);  // @178_41fad0
  ecx = edx = 0;  // @179_41fad0
  ecx = (u32)(EBP - 144);  // @180_41fad0
  reg.state = (s32)((u32)(14));  // @181_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @182_41fad0
  ecx = edx = 0;  // @183_41fad0
  ecx = (u32)(EBP - 144);  // @184_41fad0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6782844));  // @185_41fad0
  ecx = edx = 0;  // @186_41fad0
  eax = (u32)(EBP - 144);  // @187_41fad0
  reg.state = (s32)((u32)(21));  // @188_41fad0
  PV[14] = (u32)(eax);  // @189_41fad0
  ecx = (u32)(edi + 8337);  // @190_41fad0
  eax = ext_4cbee0_thiscall2(ecx, PV[14]);  // @191_41fad0
  ecx = edx = 0;  // @192_41fad0
  ecx = (u32)(EBP - 144);  // @193_41fad0
  eax = ext_4cbec0_thiscall1(ecx);  // @194_41fad0
  ecx = edx = 0;  // @195_41fad0
  { u16 v = (u16)((u32)(257)); __builtin_memcpy((void *)(u32)(edi + 109), &v, sizeof v); }  // @196_41fad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 147), &v, sizeof v); }  // @197_41fad0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 151), &v, sizeof v); }  // @198_41fad0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 143), &v, sizeof v); }  // @199_41fad0
  L41fe52:;
  eax = edi;  // @201_41fad0
  SEH_LEAVE();  // @202_41fad0
  ext_633654(G(u32, 0x6f5630));  // @203_41fad0
  return eax;  // @204_41fad0
}
PCREG(41fad0, lifted_41fad0);

extern "C" u32 THISCALL lifted_4f1d60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @2_4f1d60
  ecx = edx = 0;  // @3_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_4f1d60
  ecx = edi;  // @5_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 728)))(ecx);  // @6_4f1d60
  ecx = edx = 0;  // @7_4f1d60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1530), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_4f1d60
  if (FL[0] == FL[1]) goto L4f1fe4;  // @9_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_4f1d60
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 419), sizeof v); (u32)v; });  // @11_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @14_4f1d60
  ecx = edx = 0;  // @15_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_4f1d60
  esi = eax;  // @17_4f1d60
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 415), sizeof v); (u32)v; });  // @18_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @19_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[1]);  // @21_4f1d60
  ecx = edx = 0;  // @22_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @23_4f1d60
  FL[2] = (esi & esi);  // @24_4f1d60
  if (FL[2] == 0) goto L4f1de5;  // @25_4f1d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 123) + 0), 4); v; });  // @26_4f1d60
  X0[1] = 0;  // @27_4f1d60
  X0[2] = 0;  // @28_4f1d60
  X0[3] = 0;  // @29_4f1d60
  PV[2] = (u32)(esi);  // @30_4f1d60
  PV[3] = (u32)(ecx);  // @31_4f1d60
  ecx = 0;  // @32_4f1d60
  PV[4] = (u32)(ecx);  // @33_4f1d60
  eax = 0;  // @34_4f1d60
  PV[5] = X0[0];  // @35_4f1d60
  ecx = edi;  // @36_4f1d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 119) + 0), 4); v; });  // @37_4f1d60
  X0[1] = 0;  // @38_4f1d60
  X0[2] = 0;  // @39_4f1d60
  X0[3] = 0;  // @40_4f1d60
  PV[6] = X0[0];  // @41_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_4f1d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 732)))(ecx, (u32)(2), PV[6], PV[5], PV[2]);  // @43_4f1d60
  ecx = edx = 0;  // @44_4f1d60
  L4f1de5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_4f1d60
  ecx = edi;  // @47_4f1d60
  ebx = 0;  // @48_4f1d60
  FL[3] = ebx;  // @49_4f1d60
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2576), sizeof v); (u32)v; })) & 0xff);  // @50_4f1d60
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @51_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 784)))(ecx);  // @53_4f1d60
  ecx = edx = 0;  // @54_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4f1d60
  PV[7] = (u32)(eax);  // @56_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @57_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @58_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[7]);  // @60_4f1d60
  ecx = edx = 0;  // @61_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @62_4f1d60
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 467), &v, sizeof v); }  // @63_4f1d60
  FL[2] = (eax & eax);  // @64_4f1d60
  if (FL[2] == 0) goto L4f1e58;  // @65_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @66_4f1d60
  ecx = eax;  // @67_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @68_4f1d60
  ecx = edx = 0;  // @69_4f1d60
  FL[2] = (eax & eax);  // @70_4f1d60
  if (FL[2] == 0) goto L4f1e58;  // @71_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @72_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @74_4f1d60
  ecx = edx = 0;  // @75_4f1d60
  ecx = eax;  // @76_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @77_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @78_4f1d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @79_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2148532274));  // @80_4f1d60
  ecx = edx = 0;  // @81_4f1d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @82_4f1d60
  if (FL[2] == 0) goto L4f1e58;  // @83_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @84_4f1d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @85_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 467), &v, sizeof v); }  // @86_4f1d60
  L4f1e58:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }); FL[1] = (u32)(128);  // @88_4f1d60
  if (FL[0] < FL[1]) goto L4f1ef5;  // @89_4f1d60
  FL[2] = (ebx & ebx);  // @90_4f1d60
  if (FL[2] == 0) goto L4f1ed1;  // @91_4f1d60
  FL[2] = (esi & esi);  // @92_4f1d60
  if (FL[2] != 0) goto L4f1ea2;  // @93_4f1d60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1527), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @94_4f1d60
  if (FL[0] != FL[1]) goto L4f1ea2;  // @95_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_4f1d60
  ecx = ebx;  // @97_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 768)))(ecx, (u32)(1));  // @98_4f1d60
  ecx = edx = 0;  // @99_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4f1d60
  PV[8] = (u32)(ebx);  // @101_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @104_4f1d60
  ecx = edx = 0;  // @105_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 419), &v, sizeof v); }  // @106_4f1d60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @107_4f1d60
  goto L4f1fe4;  // @108_4f1d60
  L4f1ea2:;
  FL[0] = esi; FL[1] = ebx;  // @110_4f1d60
  if (FL[0] != FL[1]) goto L4f1eb2;  // @111_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @112_4f1d60
  ecx = ebx;  // @113_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 768)))(ecx, (u32)(0));  // @114_4f1d60
  ecx = edx = 0;  // @115_4f1d60
  L4f1eb2:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); FL[1] = esi;  // @117_4f1d60
  if (FL[0] == FL[1]) goto L4f1ee9;  // @118_4f1d60
  FL[2] = (esi & esi);  // @119_4f1d60
  if (FL[2] == 0) goto L4f1ee9;  // @120_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_4f1d60
  ecx = esi;  // @122_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @123_4f1d60
  ecx = edx = 0;  // @124_4f1d60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @125_4f1d60
  goto L4f1fe4;  // @126_4f1d60
  L4f1ed1:;
  FL[2] = (esi & esi);  // @128_4f1d60
  if (FL[2] == 0) goto L4f1edf;  // @129_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_4f1d60
  ecx = esi;  // @131_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @132_4f1d60
  ecx = edx = 0;  // @133_4f1d60
  L4f1edf:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 415), &v, sizeof v); }  // @135_4f1d60
  L4f1ee9:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @137_4f1d60
  goto L4f1fe4;  // @138_4f1d60
  L4f1ef5:;
  FL[2] = (ebx & ebx);  // @140_4f1d60
  if (FL[2] == 0) goto L4f1fac;  // @141_4f1d60
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @142_4f1d60
  if (FL[0] == FL[1]) goto L4f1f1f;  // @143_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @144_4f1d60
  ecx = ebx;  // @145_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 764)))(ecx, (u32)(0));  // @146_4f1d60
  ecx = edx = 0;  // @147_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @148_4f1d60
  FL[2] = (ecx & ecx);  // @149_4f1d60
  if (FL[2] == 0) goto L4f1f8f;  // @150_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @152_4f1d60
  ecx = edx = 0;  // @153_4f1d60
  goto L4f1f8f;  // @154_4f1d60
  L4f1f1f:;
  FL[0] = ebx; FL[1] = esi;  // @156_4f1d60
  if (FL[0] != FL[1]) goto L4f1f8f;  // @157_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @158_4f1d60
  ecx = ebx;  // @159_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 772)))(ecx);  // @160_4f1d60
  ecx = edx = 0;  // @161_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @162_4f1d60
  ecx = ebx;  // @163_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 764)))(ecx, (u32)(1));  // @164_4f1d60
  ecx = edx = 0;  // @165_4f1d60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 419), &v, sizeof v); }  // @166_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @167_4f1d60
  PV[9] = (u32)(ebx);  // @168_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @169_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[9]);  // @171_4f1d60
  ecx = edx = 0;  // @172_4f1d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 123) + 0), 4); v; });  // @173_4f1d60
  X0[1] = 0;  // @174_4f1d60
  X0[2] = 0;  // @175_4f1d60
  X0[3] = 0;  // @176_4f1d60
  esi = eax;  // @177_4f1d60
  PV[10] = (u32)(ebx);  // @178_4f1d60
  PV[11] = (u32)(ecx);  // @179_4f1d60
  ecx = 0;  // @180_4f1d60
  PV[12] = (u32)(ecx);  // @181_4f1d60
  PV[13] = X0[0];  // @182_4f1d60
  ecx = 0;  // @183_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 119), sizeof v); (u32)v; });  // @184_4f1d60
  PV[14] = eax;  // @185_4f1d60
  ecx = edi;  // @186_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @187_4f1d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 732)))(ecx, (u32)(128), PV[14], PV[13], PV[10]);  // @188_4f1d60
  ecx = edx = 0;  // @189_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @190_4f1d60
  PV[15] = (u32)(esi);  // @191_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @192_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @193_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @194_4f1d60
  ecx = edx = 0;  // @195_4f1d60
  ebx = eax;  // @196_4f1d60
  esi = 0;  // @197_4f1d60
  FL[3] = esi;  // @198_4f1d60
  L4f1f8f:;
  FL[2] = (ebx & ebx);  // @200_4f1d60
  if (FL[2] == 0) goto L4f1fbb;  // @201_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @202_4f1d60
  PV[16] = (u32)(ebx);  // @203_4f1d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @204_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @205_4f1d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[16]);  // @206_4f1d60
  ecx = edx = 0;  // @207_4f1d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 415), &v, sizeof v); }  // @208_4f1d60
  goto L4f1fc5;  // @209_4f1d60
  L4f1fac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @211_4f1d60
  FL[2] = (ecx & ecx);  // @212_4f1d60
  if (FL[2] == 0) goto L4f1fc5;  // @213_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @214_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @215_4f1d60
  ecx = edx = 0;  // @216_4f1d60
  L4f1fbb:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 415), &v, sizeof v); }  // @218_4f1d60
  L4f1fc5:;
  FL[2] = (esi & esi);  // @220_4f1d60
  if (FL[2] == 0) goto L4f1fd3;  // @221_4f1d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @222_4f1d60
  ecx = esi;  // @223_4f1d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 760)))(ecx);  // @224_4f1d60
  ecx = edx = 0;  // @225_4f1d60
  L4f1fd3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 419), &v, sizeof v); }  // @227_4f1d60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1527), &v, sizeof v); }  // @228_4f1d60
  L4f1fe4:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @230_4f1d60
  if (FL[0] == FL[1]) goto L4f1ff1;  // @231_4f1d60
  ecx = edi;  // @232_4f1d60
  eax = ext_4f3ab0_thiscall1(ecx);  // @233_4f1d60
  ecx = edx = 0;  // @234_4f1d60
  L4f1ff1:;
  return eax;  // @236_4f1d60
}
PCREG(4f1d60, lifted_4f1d60);

extern "C" u32 STDCALL lifted_661f80(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661f80
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @2_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @3_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_661f80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[0]);  // @5_661f80
  ecx = edx = 0;  // @6_661f80
  edi = eax;  // @7_661f80
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @8_661f80
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @9_661f80
  if (FL[0] == FL[1]) goto L661fb2;  // @10_661f80
  eax = 0;  // @11_661f80
  FL[3] = eax;  // @12_661f80
  return eax;  // @13_661f80
  L661fb2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @15_661f80
  L661fc0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_661f80
  esi = 0;  // @18_661f80
  FL[3] = esi;  // @19_661f80
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @20_661f80
  ebx = 0;  // @21_661f80
  FL[3] = ebx;  // @22_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @23_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @24_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_661f80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[1]);  // @26_661f80
  ecx = edx = 0;  // @27_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_661f80
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @29_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @30_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @31_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @32_661f80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_661f80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, PV[2]);  // @34_661f80
  ecx = edx = 0;  // @35_661f80
  ecx = eax;  // @36_661f80
  edx = 0;  // @37_661f80
  FL[3] = edx;  // @38_661f80
  eax = 0;  // @39_661f80
  FL[3] = eax;  // @40_661f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @41_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @42_661f80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_661f80
  edi = (u32)(ecx + 2);  // @44_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @45_661f80
  ecx = edi;  // @46_661f80
  FL[0] = eax; FL[1] = (u32)(2);  // @47_661f80
  if (FL[0] < FL[1]) goto L662042;  // @48_661f80
  edx = (u32)(eax - 2);  // @49_661f80
  edx = (edx >> (u32)(1));  // @50_661f80
  FL[3] = edx;  // @51_661f80
  edx = (edx + 1);  // @52_661f80
  FL[3] = edx;  // @53_661f80
  eax = (u32)(edx + edx);  // @54_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @55_661f80
  L662020:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_661f80
  esi = (esi + eax);  // @58_661f80
  FL[3] = esi;  // @59_661f80
  ecx = (u32)(ecx + eax*2);  // @60_661f80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @61_661f80
  ecx = (u32)(ecx + 2);  // @62_661f80
  ebx = (ebx + eax);  // @63_661f80
  FL[3] = ebx;  // @64_661f80
  ecx = (u32)(ecx + eax*2);  // @65_661f80
  ecx = (ecx + (u32)(2));  // @66_661f80
  FL[3] = ecx;  // @67_661f80
  edx = (edx - (u32)(1));  // @68_661f80
  FL[3] = edx;  // @69_661f80
  if (FL[3] != 0) goto L662020;  // @70_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @71_661f80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @72_661f80
  L662042:;
  FL[0] = edx; FL[1] = eax;  // @74_661f80
  if (FL[0] >= FL[1]) goto L66204c;  // @75_661f80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @77_661f80
  L66204c:;
  eax = (u32)(esi + ebx);  // @79_661f80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @80_661f80
  esi = (esi + eax);  // @81_661f80
  FL[3] = esi;  // @82_661f80
  eax = ext_41e290_cdecl1((u32)(52));  // @83_661f80
  ecx = edx = 0;  // @84_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @85_661f80
  ebx = eax;  // @86_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @87_661f80
  edx = (u32)(4);  // @88_661f80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @89_661f80
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @90_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @91_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @92_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 44), sizeof v); (u32)v; });  // @93_661f80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @94_661f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 48), &v, sizeof v); }  // @95_661f80
  ecx = 0;  // @96_661f80
  FL[3] = ecx;  // @97_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @98_661f80
  eax = (u32)(esi + esi*2);  // @99_661f80
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @100_661f80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @101_661f80
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @102_661f80
  FL[1] = ecx;  // @103_661f80
  ecx = (0u - ecx);  // @104_661f80
  ecx = (ecx | eax);  // @105_661f80
  FL[3] = ecx;  // @106_661f80
  PV[3] = (u32)(ecx);  // @107_661f80
  eax = ext_41e290_cdecl1(PV[3]);  // @108_661f80
  ecx = edx = 0;  // @109_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @110_661f80
  ecx = 0;  // @111_661f80
  FL[3] = ecx;  // @112_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @113_661f80
  edx = (u32)(4);  // @114_661f80
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @115_661f80
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @116_661f80
  FL[1] = ecx;  // @117_661f80
  ecx = (0u - ecx);  // @118_661f80
  ecx = (ecx | eax);  // @119_661f80
  FL[3] = ecx;  // @120_661f80
  PV[4] = (u32)(ecx);  // @121_661f80
  eax = ext_41e290_cdecl1(PV[4]);  // @122_661f80
  ecx = edx = 0;  // @123_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @124_661f80
  ecx = 0;  // @125_661f80
  FL[3] = ecx;  // @126_661f80
  eax = esi;  // @127_661f80
  edx = (u32)(8);  // @128_661f80
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @129_661f80
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @130_661f80
  FL[1] = ecx;  // @131_661f80
  ecx = (0u - ecx);  // @132_661f80
  ecx = (ecx | eax);  // @133_661f80
  FL[3] = ecx;  // @134_661f80
  PV[5] = (u32)(ecx);  // @135_661f80
  eax = ext_41e290_cdecl1(PV[5]);  // @136_661f80
  ecx = edx = 0;  // @137_661f80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @138_661f80
  ecx = 0;  // @139_661f80
  FL[3] = ecx;  // @140_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 44), &v, sizeof v); }  // @141_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @142_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @143_661f80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @144_661f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @145_661f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @146_661f80
  FL[2] = (eax & eax);  // @147_661f80
  if (FL[2] == 0) goto L66218a;  // @148_661f80
  L6620f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @150_661f80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @151_661f80
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @152_661f80
  edi = (edi + (u32)(2));  // @153_661f80
  FL[3] = edi;  // @154_661f80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @155_661f80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ebx*4), &v, sizeof v); }  // @156_661f80
  ebx = 0;  // @157_661f80
  FL[3] = ebx;  // @158_661f80
  FL[2] = (edx & edx);  // @159_661f80
  if (FL[2] == 0) goto L662177;  // @160_661f80
  edx = edi;  // @161_661f80
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @162_661f80
  FL[3] = edx;  // @163_661f80
  edx = (edx << (u32)(15));  // @164_661f80
  FL[3] = edx;  // @165_661f80
  L662110:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @167_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @168_661f80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @169_661f80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + ecx*8 + 4), &v, sizeof v); }  // @170_661f80
  ecx = ebx;  // @171_661f80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @172_661f80
  ebx = (ebx + 1);  // @173_661f80
  FL[3] = ebx;  // @174_661f80
  ecx = (ecx << (u32)(31));  // @175_661f80
  FL[3] = ecx;  // @176_661f80
  ecx = (ecx | edx);  // @177_661f80
  FL[3] = ecx;  // @178_661f80
  edx = (edx + (u32)(65536));  // @179_661f80
  FL[3] = edx;  // @180_661f80
  ecx = (ecx & (u32)(4294901760));  // @181_661f80
  FL[3] = ecx;  // @182_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @183_661f80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @184_661f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + esi*8), &v, sizeof v); }  // @185_661f80
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @186_661f80
  edi = (edi + (u32)(2));  // @187_661f80
  FL[3] = edi;  // @188_661f80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @189_661f80
  ecx = (u32)(eax + eax*8);  // @190_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @191_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @192_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @193_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @194_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 4), sizeof v); (u32)v; });  // @195_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @196_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @197_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4 + 8), sizeof v); (u32)v; });  // @198_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @199_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @200_661f80
  ecx = (ecx + 1);  // @201_661f80
  FL[3] = ecx;  // @202_661f80
  esi = (esi + (u32)(12));  // @203_661f80
  FL[3] = esi;  // @204_661f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @205_661f80
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @206_661f80
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @207_661f80
  if (FL[0] < FL[1]) goto L662110;  // @208_661f80
  L662177:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @210_661f80
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @211_661f80
  eax = (eax + 1);  // @212_661f80
  FL[3] = eax;  // @213_661f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @214_661f80
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @215_661f80
  if (FL[0] < FL[1]) goto L6620f0;  // @216_661f80
  L66218a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @218_661f80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @219_661f80
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @220_661f80
  FL[2] = (edx & edx);  // @221_661f80
  if (FL[2] == 0) goto L6621b8;  // @222_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_661f80
  PV[6] = (u32)(edx);  // @224_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @225_661f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @226_661f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_661f80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[6]);  // @228_661f80
  ecx = edx = 0;  // @229_661f80
  edi = eax;  // @230_661f80
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @231_661f80
  FL[2] = (edi & edi);  // @232_661f80
  if (FL[2] != 0) goto L661fc0;  // @233_661f80
  L6621b8:;
  eax = ebx;  // @235_661f80
  return eax;  // @236_661f80
}
PCREG(661f80, lifted_661f80);

extern "C" u32 FASTCALL lifted_532420(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_532420
  eax = (eax & 0xffff);  // @1_532420
  eax = (u32)((s32)eax * (s32)(u32)(21));  // @2_532420
  edi = ecx;  // @3_532420
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; }));  // @4_532420
  FL[3] = eax;  // @5_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_532420
  ecx = (u32)(eax + eax*2);  // @8_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 90), sizeof v); (u32)v; });  // @9_532420
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @10_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 124), sizeof v); (u32)v; });  // @11_532420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 120), sizeof v); (u32)v; });  // @12_532420
  esi = (u32)(edx + edx*4);  // @13_532420
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax), sizeof v); (u32)v; })) & 0xff);  // @14_532420
  ebx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi*2 + 8), sizeof v); (u32)v; });  // @15_532420
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @16_532420
  if (FL[2] == 0) goto L53270e;  // @17_532420
  eax = (edx & 0xff);  // @18_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @19_532420
  eax = ebx;  // @20_532420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @21_532420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @22_532420
  ecx = (u32)(eax + eax*4);  // @23_532420
  ecx = (ecx + ecx);  // @24_532420
  FL[3] = ecx;  // @25_532420
  eax = 0;  // @26_532420
  FL[3] = eax;  // @27_532420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @28_532420
  L532480:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; });  // @30_532420
  ebx = (ebx + ecx);  // @31_532420
  FL[3] = ebx;  // @32_532420
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @33_532420
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @34_532420
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @35_532420
  if (FL[2] == 0) goto L5326f9;  // @36_532420
  edx = 0;  // @37_532420
  FL[3] = edx;  // @38_532420
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @39_532420
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_532420
  eax = ecx;  // @41_532420
  FL[2] = ((ecx & 0xffff) & (ecx & 0xffff));  // @42_532420
  if ((s32)FL[2] >= 0) goto L5324ba;  // @43_532420
  FL[1] = eax;  // @44_532420
  eax = (0u - eax);  // @45_532420
  edx = (u32)(1);  // @46_532420
  esi = 0;  // @47_532420
  FL[3] = esi;  // @48_532420
  eax = (eax & 0xffff);  // @49_532420
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @50_532420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @51_532420
  L5324ba:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @53_532420
  edx = (u32)(edx + edx*2);  // @54_532420
  eax = (eax & 0xffff);  // @55_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @56_532420
  ecx = (u32)(eax + eax*2);  // @57_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 136), sizeof v); (u32)v; });  // @58_532420
  ecx = (u32)(eax + ecx*4);  // @59_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xffff);  // @60_532420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @61_532420
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @62_532420
  if (FL[0] != FL[1]) goto L5326f3;  // @63_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; })) & 0xffff);  // @64_532420
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 2), sizeof v); (u32)v; });  // @65_532420
  if (FL[0] != FL[1]) goto L5326f3;  // @66_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) & 0xffff);  // @67_532420
  FL[0] = (eax & 0xffff); FL[1] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 4), sizeof v); (u32)v; });  // @68_532420
  if (FL[0] != FL[1]) goto L5326f3;  // @69_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @70_532420
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 56), sizeof v); (u32)v; });  // @71_532420
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @72_532420
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @73_532420
  edx = (u32)(eax + eax*2);  // @74_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @75_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @76_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 2), sizeof v); (u32)v; });  // @77_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 50), &v, sizeof v); }  // @78_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 4), sizeof v); (u32)v; });  // @79_532420
  ecx = (u32)(EBP - 100);  // @80_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @81_532420
  eax = (u32)(edi + 150);  // @82_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @83_532420
  eax = (u32)(EBP - 52);  // @84_532420
  PV[1] = (u32)(eax);  // @85_532420
  eax = ext_531740_thiscall3(ecx, PV[1], PV[0]);  // @86_532420
  ecx = edx = 0;  // @87_532420
  eax = (eax & 0xffff);  // @88_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @89_532420
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @90_532420
  if (FL[2] == 0) goto L5326f3;  // @91_532420
  ecx = (u32)(EBP - 100);  // @92_532420
  eax = ext_530a40_thiscall1(ecx);  // @93_532420
  ecx = edx = 0;  // @94_532420
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1), sizeof v); (u32)v; });  // @95_532420
  ecx = (ecx & 0xffff0000u) | ((((ecx & 0xffff) - 1)) & 0xffff);  // @96_532420
  FL[3] = (ecx & 0xffff);  // @97_532420
  eax = (eax & 0xffff0000u) | ((((eax & 0xffff) + (ecx & 0xffff))) & 0xffff);  // @98_532420
  FL[3] = (eax & 0xffff);  // @99_532420
  eax = (eax & 0xffff);  // @100_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @101_532420
  FL[2] = ((eax & 0xffff) & (eax & 0xffff));  // @102_532420
  if (FL[2] == 0) goto L53271c;  // @103_532420
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 10) + 0), 4); v; });  // @104_532420
  X2[1] = 0;  // @105_532420
  X2[2] = 0;  // @106_532420
  X2[3] = 0;  // @107_532420
  X0[0] = 0;  // @108_532420
  X0[1] = 0;  // @109_532420
  X0[2] = 0;  // @110_532420
  X0[3] = 0;  // @111_532420
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @112_532420
  eax = (eax & 0xffff);  // @113_532420
  ebx = (u32)((s32)eax * (s32)(u32)(21));  // @114_532420
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @115_532420
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; }));  // @116_532420
  FL[3] = ebx;  // @117_532420
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6866736) + 0), 4); v; })));  // @118_532420
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 10) + 0), 4); v; });  // @119_532420
  X0[1] = 0;  // @120_532420
  X0[2] = 0;  // @121_532420
  X0[3] = 0;  // @122_532420
  X1[0] = X2[0];  // @123_532420
  X1[1] = X2[1];  // @124_532420
  X1[2] = X2[2];  // @125_532420
  X1[3] = X2[3];  // @126_532420
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @127_532420
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5326f3;  // @128_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @129_532420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @130_532420
  __builtin_memcpy((void *)((u32)(ebx + 10) + 0), &X2[0], 4);  // @131_532420
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @132_532420
  esi = (esi << (u32)(5));  // @133_532420
  FL[3] = esi;  // @134_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + edi + 158), &v, sizeof v); }  // @135_532420
  eax = 0;  // @136_532420
  FL[3] = eax;  // @137_532420
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + edi + 186), &v, sizeof v); }  // @138_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + edi + 160), &v, sizeof v); }  // @139_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 170), &v, sizeof v); }  // @140_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 166), &v, sizeof v); }  // @141_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 162), &v, sizeof v); }  // @142_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 182), &v, sizeof v); }  // @143_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 178), &v, sizeof v); }  // @144_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 174), &v, sizeof v); }  // @145_532420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @146_532420
  if (FL[0] == FL[1]) goto L53269e;  // @147_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @148_532420
  ecx = (u32)(eax + edx*2);  // @149_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 140), sizeof v); (u32)v; });  // @150_532420
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*2), sizeof v); (u32)v; })) & 0xffff);  // @151_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + edi + 160), &v, sizeof v); }  // @152_532420
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 5), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @153_532420
  if (FL[0] == FL[1]) goto L53268a;  // @154_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 144), sizeof v); (u32)v; });  // @155_532420
  ecx = (u32)(edx + edx*2);  // @156_532420
  edx = (u32)(eax + ecx*8);  // @157_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @158_532420
  ecx = (u32)(eax + eax*2);  // @159_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @160_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 162), &v, sizeof v); }  // @161_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 4), sizeof v); (u32)v; });  // @162_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 166), &v, sizeof v); }  // @163_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 8), sizeof v); (u32)v; });  // @164_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 170), &v, sizeof v); }  // @165_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @166_532420
  ecx = (u32)(eax + eax*2);  // @167_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; });  // @168_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 174), &v, sizeof v); }  // @169_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 4), sizeof v); (u32)v; });  // @170_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 178), &v, sizeof v); }  // @171_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 8), sizeof v); (u32)v; });  // @172_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + edi + 182), &v, sizeof v); }  // @173_532420
  L53268a:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + edi + 160), sizeof v); (u32)v; });  // @175_532420
  ecx = edi;  // @176_532420
  PV[2] = (u32)(eax);  // @177_532420
  eax = ext_532730_stdcall1(PV[2]);  // @178_532420
  ecx = 0;  // @179_532420
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @180_532420
  if (FL[2] == 0) goto L5326f3;  // @181_532420
  L53269e:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @183_532420
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ebx + 20), &v, sizeof v); }  // @184_532420
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @185_532420
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @186_532420
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @187_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 14), &v, sizeof v); }  // @188_532420
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 156), &v, sizeof v); }  // @189_532420
  FL[3] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 156), sizeof v); (u32)v; });  // @190_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @191_532420
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @192_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @193_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @194_532420
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @195_532420
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 3), &v, sizeof v); }  // @196_532420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @197_532420
  edx = (u32)(eax + eax*2);  // @198_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2), sizeof v); (u32)v; });  // @199_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @200_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 2), sizeof v); (u32)v; });  // @201_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 6), &v, sizeof v); }  // @202_532420
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*2 + 4), sizeof v); (u32)v; });  // @203_532420
  ecx = edi;  // @204_532420
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @205_532420
  eax = ext_52d250_fastcall4(ecx, edx, PV[4], PV[3]);  // @206_532420
  ecx = edx = 0;  // @207_532420
  L5326f3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @209_532420
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @210_532420
  L5326f9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @212_532420
  eax = (eax + 1);  // @213_532420
  FL[3] = eax;  // @214_532420
  ecx = (ecx + (u32)(10));  // @215_532420
  FL[3] = ecx;  // @216_532420
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @217_532420
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @218_532420
  FL[0] = eax; FL[1] = edx;  // @219_532420
  if ((s32)FL[0] < (s32)FL[1]) goto L532480;  // @220_532420
  L53270e:;
  eax = (u32)(1);  // @222_532420
  return eax;  // @223_532420
  L53271c:;
  eax = (u32)(65535);  // @225_532420
  return eax;  // @226_532420
}
PCREG(532420, lifted_532420);

