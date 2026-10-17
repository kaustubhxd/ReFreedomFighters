// batch236000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4f21f0_thiscall2(u32, u32) __asm__("ext_4f21f0");
extern "C" u32 THISCALL ext_561f70_thiscall1(u32) __asm__("ext_561f70");
extern "C" u32 THISCALL ext_562390_thiscall1(u32) __asm__("ext_562390");
extern "C" u32 THISCALL ext_5a8350_thiscall1(u32) __asm__("ext_5a8350");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_563110(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @2_563110
  ecx = edx = 0;  // @3_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @4_563110
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4159), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5_563110
  if (FL[0] == FL[1]) goto L56313a;  // @6_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_563110
  ecx = edi;  // @8_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 244)))(ecx);  // @9_563110
  ecx = edx = 0;  // @10_563110
  L56313a:;
  ecx = edi;  // @12_563110
  eax = ext_562390_thiscall1(ecx);  // @13_563110
  ecx = edx = 0;  // @14_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_563110
  ecx = edi;  // @16_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @17_563110
  ecx = edx = 0;  // @18_563110
  ecx = eax;  // @19_563110
  eax = ext_4f21f0_thiscall2(ecx, (u32)(0));  // @20_563110
  ecx = edx = 0;  // @21_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @23_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 436)))(ecx, (u32)(1));  // @25_563110
  ecx = edx = 0;  // @26_563110
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @27_563110
  if (FL[0] == FL[1]) goto L563237;  // @28_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @29_563110
  ecx = edi;  // @30_563110
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 136), &v, sizeof v); }  // @31_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @32_563110
  ecx = edx = 0;  // @33_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 248), sizeof v); (u32)v; });  // @34_563110
  FL[2] = (ecx & ecx);  // @35_563110
  if (FL[2] == 0) goto L5631ac;  // @36_563110
  eax = ext_5a8350_thiscall1(ecx);  // @37_563110
    // @38_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 248), sizeof v); (u32)v; });  // @39_563110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 240), &v, sizeof v); }  // @40_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 532)))(ecx, (u32)(2048));  // @42_563110
  ecx = edx = 0;  // @43_563110
  L5631ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_563110
  ecx = edi;  // @46_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @47_563110
  ecx = edx = 0;  // @48_563110
  ecx = (u32)(eax + 203);  // @49_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @51_563110
  ecx = edx = 0;  // @52_563110
  FL[0] = eax; FL[1] = (u32)(1);  // @53_563110
  if (FL[0] != FL[1]) goto L563226;  // @54_563110
  ebx = 0;  // @55_563110
  FL[3] = ebx;  // @56_563110
  L5631d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @58_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + eax + 11325), sizeof v); (u32)v; });  // @59_563110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @60_563110
  FL[2] = (eax & eax);  // @61_563110
  if (FL[2] == 0) goto L56321e;  // @62_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @63_563110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @66_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_563110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6972944), (u32)(0), (u32)(6972596), (u32)(460), (u32)(0));  // @68_563110
  ecx = edx = 0;  // @69_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @70_563110
  eax = (eax & 0xffff);  // @71_563110
  PV[0] = (u32)(eax);  // @72_563110
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @73_563110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[1], PV[0]);  // @74_563110
  ecx = edx = 0;  // @75_563110
  L56321e:;
  ebx = (ebx + (u32)(4));  // @77_563110
  FL[3] = ebx;  // @78_563110
  FL[0] = ebx; FL[1] = (u32)(16);  // @79_563110
  if ((s32)FL[0] < (s32)FL[1]) goto L5631d0;  // @80_563110
  L563226:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_563110
  ecx = edi;  // @83_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 228)))(ecx);  // @84_563110
  ecx = edx = 0;  // @85_563110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @86_563110
  L563237:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @88_563110
  FL[2] = (esi & esi);  // @89_563110
  if (FL[2] == 0) goto L56325a;  // @90_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @91_563110
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @92_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @93_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @95_563110
  ecx = edx = 0;  // @96_563110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 78491), &v, sizeof v); }  // @97_563110
  L56325a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @99_563110
  FL[2] = (eax & eax);  // @100_563110
  if (FL[2] == 0) goto L56334f;  // @101_563110
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4161), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @102_563110
  if (FL[0] == FL[1]) goto L56334f;  // @103_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @104_563110
  ecx = edi;  // @105_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @106_563110
  ecx = edx = 0;  // @107_563110
  ecx = eax;  // @108_563110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @109_563110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 604)))(ecx, (u32)(6972968), (u32)(0));  // @110_563110
  ecx = edx = 0;  // @111_563110
  esi = eax;  // @112_563110
  FL[2] = (esi & esi);  // @113_563110
  if (FL[2] == 0) goto L563363;  // @114_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @115_563110
  edx = (u32)(6801640);  // @116_563110
  ebx = (u32)(6972988);  // @117_563110
  eax = (u32)(6972996);  // @118_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @119_563110
  FL[2] = (ecx & ecx);  // @120_563110
  if (FL[2] != 0) edx = ecx;  // @121_563110
  L5632b4:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @123_563110
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @124_563110
  if (FL[0] != FL[1]) goto L5632d4;  // @125_563110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @126_563110
  if (FL[2] == 0) goto L5632d0;  // @127_563110
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @128_563110
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @129_563110
  if (FL[0] != FL[1]) goto L5632d4;  // @130_563110
  edx = (edx + (u32)(2));  // @131_563110
  FL[3] = edx;  // @132_563110
  eax = (eax + (u32)(2));  // @133_563110
  FL[3] = eax;  // @134_563110
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @135_563110
  if (FL[2] != 0) goto L5632b4;  // @136_563110
  L5632d0:;
  eax = 0;  // @138_563110
  FL[3] = eax;  // @139_563110
  goto L5632d9;  // @140_563110
  L5632d4:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @142_563110
  eax = (eax | (u32)(1));  // @143_563110
  FL[3] = eax;  // @144_563110
  L5632d9:;
  FL[2] = (eax & eax);  // @146_563110
  ecx = (u32)(6973020);  // @147_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @148_563110
  if (FL[2] != 0) ecx = ebx;  // @149_563110
  PV[3] = (u32)(ecx);  // @150_563110
  ecx = esi;  // @151_563110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, PV[3], (u32)(0));  // @152_563110
  ecx = edx = 0;  // @153_563110
  ebx = eax;  // @154_563110
  FL[2] = (ebx & ebx);  // @155_563110
  if (FL[2] == 0) goto L563363;  // @156_563110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @157_563110
  ecx = ebx;  // @158_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 44)))(ecx);  // @159_563110
  ecx = edx = 0;  // @160_563110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @161_563110
  ecx = ebx;  // @162_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(0));  // @163_563110
  ecx = edx = 0;  // @164_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @165_563110
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @166_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; });  // @167_563110
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @168_563110
  eax = (eax - edx);  // @169_563110
  FL[3] = eax;  // @170_563110
  eax = (u32)((s32)eax >> (u32)(1));  // @171_563110
  FL[3] = eax;  // @172_563110
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @173_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; });  // @174_563110
  ecx = ebx;  // @175_563110
  X0[0] = F2U((float)(s32)X0[0]);  // @176_563110
  X0[1] = F2U((float)(s32)X0[1]);  // @177_563110
  X0[2] = F2U((float)(s32)X0[2]);  // @178_563110
  X0[3] = F2U((float)(s32)X0[3]);  // @179_563110
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @180_563110
  eax = (eax - edx);  // @181_563110
  FL[3] = eax;  // @182_563110
  eax = (u32)((s32)eax >> (u32)(1));  // @183_563110
  FL[3] = eax;  // @184_563110
  PV[4] = X0[0];  // @185_563110
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @186_563110
  X0[0] = F2U((float)(s32)X0[0]);  // @187_563110
  X0[1] = F2U((float)(s32)X0[1]);  // @188_563110
  X0[2] = F2U((float)(s32)X0[2]);  // @189_563110
  X0[3] = F2U((float)(s32)X0[3]);  // @190_563110
  PV[5] = X0[0];  // @191_563110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 620)))(ecx, PV[5], PV[4], (u32)(0));  // @192_563110
  ecx = edx = 0;  // @193_563110
  goto L563363;  // @194_563110
  L56334f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 252), sizeof v); (u32)v; });  // @196_563110
  FL[2] = (ecx & ecx);  // @197_563110
  if (FL[2] == 0) goto L563363;  // @198_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @200_563110
  ecx = edx = 0;  // @201_563110
  L563363:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @203_563110
  ecx = edi;  // @204_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(16));  // @205_563110
  ecx = edx = 0;  // @206_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @207_563110
  ecx = edi;  // @208_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @209_563110
  ecx = edx = 0;  // @210_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @211_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @212_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 592)))(ecx);  // @213_563110
  ecx = edx = 0;  // @214_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @215_563110
  ecx = edi;  // @216_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @217_563110
  ecx = edx = 0;  // @218_563110
  ecx = eax;  // @219_563110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @220_563110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 272)))(ecx, (u32)(272), (u32)(0));  // @221_563110
  ecx = edx = 0;  // @222_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @223_563110
  ecx = edi;  // @224_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @225_563110
  ecx = edx = 0;  // @226_563110
  ecx = eax;  // @227_563110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @228_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 780)))(ecx, (u32)(1));  // @229_563110
  ecx = edx = 0;  // @230_563110
  ecx = edi;  // @231_563110
  eax = ext_561f70_thiscall1(ecx);  // @232_563110
  ecx = edx = 0;  // @233_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @234_563110
  ecx = edi;  // @235_563110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @236_563110
  ecx = edx = 0;  // @237_563110
  ecx = eax;  // @238_563110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @239_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 780)))(ecx, (u32)(1));  // @240_563110
  ecx = edx = 0;  // @241_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @242_563110
  ecx = edi;  // @243_563110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 196)))(ecx, (u32)(1));  // @244_563110
  ecx = edx = 0;  // @245_563110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @246_563110
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @247_563110
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @248_563110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @249_563110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 728)))(ecx, PV[7], PV[6]);  // @250_563110
  ecx = edx = 0;  // @251_563110
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @252_563110
  FL[3] = (eax & 0xff);  // @253_563110
  return eax;  // @254_563110
}
PCREG(563110, lifted_563110);

