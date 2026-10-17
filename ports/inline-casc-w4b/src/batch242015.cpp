// batch242015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4e5e40_thiscall1(u32) __asm__("ext_4e5e40");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c1060(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c1060
  edi = ecx;  // @1_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_4c1060
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @3_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @4_4c1060
  if (FL[0] == FL[1]) goto L4c1098;  // @5_4c1060
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @6_4c1060
  FL[3] = (eax & 0xff);  // @7_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @8_4c1060
  if (FL[0] != FL[1]) goto L4c1098;  // @9_4c1060
  ecx = esi;  // @10_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @11_4c1060
  ecx = edx = 0;  // @12_4c1060
  FL[2] = (eax & eax);  // @13_4c1060
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @14_4c1060
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 81), &v, sizeof v); }  // @15_4c1060
  L4c1098:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_4c1060
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @18_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @19_4c1060
  if (FL[0] == FL[1]) goto L4c10b1;  // @20_4c1060
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @21_4c1060
  FL[3] = (eax & 0xff);  // @22_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @23_4c1060
  if (FL[0] != FL[1]) goto L4c10b1;  // @24_4c1060
  ecx = esi;  // @25_4c1060
  eax = ext_4e5e40_thiscall1(ecx);  // @26_4c1060
  ecx = edx = 0;  // @27_4c1060
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @28_4c1060
  L4c10b1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_4c1060
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @31_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @32_4c1060
  if (FL[0] == FL[1]) goto L4c10ca;  // @33_4c1060
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @34_4c1060
  FL[3] = (eax & 0xff);  // @35_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @36_4c1060
  if (FL[0] != FL[1]) goto L4c10ca;  // @37_4c1060
  ecx = esi;  // @38_4c1060
  eax = ext_4e5e40_thiscall1(ecx);  // @39_4c1060
  ecx = edx = 0;  // @40_4c1060
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi + 78), &v, sizeof v); }  // @41_4c1060
  L4c10ca:;
  ecx = esi;  // @43_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @44_4c1060
  ecx = edx = 0;  // @45_4c1060
  ecx = esi;  // @46_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @47_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @48_4c1060
  ecx = edx = 0;  // @49_4c1060
  ecx = esi;  // @50_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 268), &v, sizeof v); }  // @51_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @52_4c1060
  ecx = edx = 0;  // @53_4c1060
  ecx = esi;  // @54_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @55_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @56_4c1060
  ecx = edx = 0;  // @57_4c1060
  ecx = esi;  // @58_4c1060
  ebx = eax;  // @59_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @60_4c1060
  ecx = edx = 0;  // @61_4c1060
  ecx = esi;  // @62_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @63_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @64_4c1060
  ecx = edx = 0;  // @65_4c1060
  ecx = esi;  // @66_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @67_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @68_4c1060
  ecx = edx = 0;  // @69_4c1060
  ecx = esi;  // @70_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @71_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @72_4c1060
  ecx = edx = 0;  // @73_4c1060
  ecx = esi;  // @74_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @75_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @76_4c1060
  ecx = edx = 0;  // @77_4c1060
  ecx = esi;  // @78_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @79_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @80_4c1060
  ecx = edx = 0;  // @81_4c1060
  ecx = esi;  // @82_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @83_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @84_4c1060
  ecx = edx = 0;  // @85_4c1060
  ecx = esi;  // @86_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @87_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @88_4c1060
  ecx = edx = 0;  // @89_4c1060
  ecx = esi;  // @90_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @91_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @92_4c1060
  ecx = edx = 0;  // @93_4c1060
  ecx = esi;  // @94_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @95_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @96_4c1060
  ecx = edx = 0;  // @97_4c1060
  ecx = esi;  // @98_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 312), &v, sizeof v); }  // @99_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @100_4c1060
  ecx = edx = 0;  // @101_4c1060
  ecx = esi;  // @102_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @103_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @104_4c1060
  ecx = edx = 0;  // @105_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_4c1060
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @107_4c1060
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @108_4c1060
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @109_4c1060
  if (FL[0] == FL[1]) goto L4c11b1;  // @110_4c1060
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @111_4c1060
  FL[3] = (ecx & 0xff);  // @112_4c1060
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @113_4c1060
  if (FL[0] != FL[1]) goto L4c11b1;  // @114_4c1060
  ecx = esi;  // @115_4c1060
  eax = ext_4e5e80_thiscall1(ecx);  // @116_4c1060
  ecx = edx = 0;  // @117_4c1060
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + 109)) :: "st");  // @118_4c1060
  L4c11b1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_4c1060
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @121_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @122_4c1060
  if (FL[0] == FL[1]) goto L4c11ce;  // @123_4c1060
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @124_4c1060
  FL[3] = (eax & 0xff);  // @125_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @126_4c1060
  if (FL[0] != FL[1]) goto L4c11ce;  // @127_4c1060
  ecx = esi;  // @128_4c1060
  eax = ext_4e5e60_thiscall1(ecx);  // @129_4c1060
  ecx = edx = 0;  // @130_4c1060
  FL[2] = (eax & eax);  // @131_4c1060
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @132_4c1060
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 113), &v, sizeof v); }  // @133_4c1060
  L4c11ce:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @135_4c1060
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @136_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @137_4c1060
  if (FL[0] == FL[1]) goto L4c1200;  // @138_4c1060
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @139_4c1060
  FL[3] = (eax & 0xff);  // @140_4c1060
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @141_4c1060
  if (FL[0] != FL[1]) goto L4c1200;  // @142_4c1060
  ecx = esi;  // @143_4c1060
  eax = ext_4e5ea0_thiscall1(ecx);  // @144_4c1060
  ecx = edx = 0;  // @145_4c1060
  edx = edi;  // @146_4c1060
  edx = (edx - eax);  // @147_4c1060
  FL[3] = edx;  // @148_4c1060
  L4c11f0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @150_4c1060
  eax = (u32)(eax + 1);  // @151_4c1060
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax + 383), &v, sizeof v); }  // @152_4c1060
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @153_4c1060
  if (FL[2] != 0) goto L4c11f0;  // @154_4c1060
  L4c1200:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 113), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @156_4c1060
  if (FL[0] == FL[1]) goto L4c12dd;  // @157_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_4c1060
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @159_4c1060
  if (FL[0] == FL[1]) goto L4c12dd;  // @160_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @161_4c1060
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 115), &v, sizeof v); }  // @162_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @163_4c1060
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 124), sizeof v); (u32)v; });  // @164_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @165_4c1060
  PV[0] = (u32)(edx);  // @166_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @167_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @168_4c1060
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[0]);  // @169_4c1060
  ecx = edx = 0;  // @170_4c1060
  edx = eax;  // @171_4c1060
  FL[2] = (edx & edx);  // @172_4c1060
  if (FL[2] == 0) goto L4c12dd;  // @173_4c1060
  ecx = edx;  // @174_4c1060
  esi = (u32)(ecx + 1);  // @175_4c1060
  L4c1250:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @177_4c1060
  ecx = (ecx + 1);  // @178_4c1060
  FL[3] = ecx;  // @179_4c1060
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @180_4c1060
  if (FL[2] != 0) goto L4c1250;  // @181_4c1060
  eax = (u32)(0);  // @182_4c1060
  ecx = (ecx - esi);  // @183_4c1060
  FL[3] = ecx;  // @184_4c1060
  if (FL[3] == 0) goto L4c126b;  // @185_4c1060
  L4c1260:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @187_4c1060
  if (FL[0] == FL[1]) goto L4c126b;  // @188_4c1060
  eax = (eax + 1);  // @189_4c1060
  FL[3] = eax;  // @190_4c1060
  FL[0] = eax; FL[1] = ecx;  // @191_4c1060
  if (FL[0] < FL[1]) goto L4c1260;  // @192_4c1060
  L4c126b:;
  eax = (eax + 1);  // @194_4c1060
  FL[3] = eax;  // @195_4c1060
  FL[0] = eax; FL[1] = ecx;  // @196_4c1060
  if (FL[0] >= FL[1]) goto L4c127b;  // @197_4c1060
  L4c1270:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx), sizeof v); (u32)v; }); FL[1] = (u32)(47);  // @199_4c1060
  if (FL[0] == FL[1]) goto L4c127b;  // @200_4c1060
  eax = (eax + 1);  // @201_4c1060
  FL[3] = eax;  // @202_4c1060
  FL[0] = eax; FL[1] = ecx;  // @203_4c1060
  if (FL[0] < FL[1]) goto L4c1270;  // @204_4c1060
  L4c127b:;
  ecx = (u32)(eax + edx);  // @206_4c1060
  edx = (u32)(EBP - 260);  // @207_4c1060
  edx = (edx - ecx);  // @208_4c1060
  FL[3] = edx;  // @209_4c1060
  L4c1286:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @211_4c1060
  ecx = (u32)(ecx + 1);  // @212_4c1060
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @213_4c1060
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @214_4c1060
  if (FL[2] != 0) goto L4c1286;  // @215_4c1060
  ecx = (u32)(EBP - 260);  // @216_4c1060
  edx = (u32)(ecx + 1);  // @217_4c1060
  L4c12a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @219_4c1060
  ecx = (ecx + 1);  // @220_4c1060
  FL[3] = ecx;  // @221_4c1060
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @222_4c1060
  if (FL[2] != 0) goto L4c12a0;  // @223_4c1060
  ecx = (ecx - edx);  // @224_4c1060
  FL[3] = ecx;  // @225_4c1060
  ecx = (ecx + (u32)(-4));  // @226_4c1060
  FL[3] = ecx;  // @227_4c1060
  FL[0] = ecx; FL[1] = (u32)(256);  // @228_4c1060
  if (FL[0] >= FL[1]) goto L4c14a0;  // @229_4c1060
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + ecx - 260), &v, sizeof v); }  // @230_4c1060
  edx = edi;  // @231_4c1060
  ecx = (u32)(EBP - 260);  // @232_4c1060
  eax = ecx;  // @233_4c1060
  edx = (edx - eax);  // @234_4c1060
  FL[3] = edx;  // @235_4c1060
  L4c12d0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @237_4c1060
  ecx = (u32)(ecx + 1);  // @238_4c1060
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx + 127), &v, sizeof v); }  // @239_4c1060
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @240_4c1060
  if (FL[2] != 0) goto L4c12d0;  // @241_4c1060
  L4c12dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @243_4c1060
  eax = (eax << (u32)(4));  // @244_4c1060
  FL[3] = eax;  // @245_4c1060
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; }));  // @246_4c1060
  FL[3] = eax;  // @247_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @248_4c1060
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; });  // @249_4c1060
  X2[1] = 0;  // @250_4c1060
  X2[2] = 0;  // @251_4c1060
  X2[3] = 0;  // @252_4c1060
  ecx = (u32)(ecx + eax*4);  // @253_4c1060
  eax = ecx;  // @254_4c1060
  eax = (eax << (u32)(4));  // @255_4c1060
  FL[3] = eax;  // @256_4c1060
  eax = (eax - ecx);  // @257_4c1060
  FL[3] = eax;  // @258_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @259_4c1060
  eax = (u32)(ecx + eax*4);  // @260_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; });  // @261_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @262_4c1060
  eax = (eax >> (u32)(31));  // @263_4c1060
  FL[3] = eax;  // @264_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @265_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @266_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @267_4c1060
  eax = (eax << (u32)(4));  // @268_4c1060
  FL[3] = eax;  // @269_4c1060
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @270_4c1060
  FL[3] = eax;  // @271_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @272_4c1060
  ecx = (u32)(ecx + eax*4);  // @273_4c1060
  eax = ecx;  // @274_4c1060
  eax = (eax << (u32)(4));  // @275_4c1060
  FL[3] = eax;  // @276_4c1060
  eax = (eax - ecx);  // @277_4c1060
  FL[3] = eax;  // @278_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @279_4c1060
  X0[0] = ebx; X0[1] = X0[2] = X0[3] = 0;  // @280_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @281_4c1060
  ebx = (ebx >> (u32)(31));  // @282_4c1060
  FL[3] = ebx;  // @283_4c1060
  eax = (u32)(ecx + eax*4);  // @284_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; });  // @285_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 4), 4); v; })));  // @286_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @287_4c1060
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @288_4c1060
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @289_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @290_4c1060
  eax = (eax >> (u32)(31));  // @291_4c1060
  FL[3] = eax;  // @292_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @293_4c1060
  __builtin_memcpy((void *)((u32)(edi + 89) + 0), &X1[0], 4);  // @294_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @295_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @296_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @297_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @298_4c1060
  eax = (eax >> (u32)(31));  // @299_4c1060
  FL[3] = eax;  // @300_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @301_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @302_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; });  // @303_4c1060
  eax = (eax << (u32)(4));  // @304_4c1060
  FL[3] = eax;  // @305_4c1060
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }));  // @306_4c1060
  FL[3] = eax;  // @307_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @308_4c1060
  ecx = (u32)(ecx + eax*4);  // @309_4c1060
  eax = ecx;  // @310_4c1060
  eax = (eax << (u32)(4));  // @311_4c1060
  FL[3] = eax;  // @312_4c1060
  eax = (eax - ecx);  // @313_4c1060
  FL[3] = eax;  // @314_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; });  // @315_4c1060
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @316_4c1060
  eax = (u32)(ecx + eax*4);  // @317_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 312), sizeof v); (u32)v; });  // @318_4c1060
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @319_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @320_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @321_4c1060
  eax = (eax >> (u32)(31));  // @322_4c1060
  FL[3] = eax;  // @323_4c1060
  __builtin_memcpy((void *)((u32)(edi + 93) + 0), &X1[0], 4);  // @324_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @325_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; });  // @326_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @327_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @328_4c1060
  eax = (eax >> (u32)(31));  // @329_4c1060
  FL[3] = eax;  // @330_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @331_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @332_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 308), sizeof v); (u32)v; });  // @333_4c1060
  eax = (eax << (u32)(4));  // @334_4c1060
  FL[3] = eax;  // @335_4c1060
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 308), sizeof v); (u32)v; }));  // @336_4c1060
  FL[3] = eax;  // @337_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @338_4c1060
  ecx = (u32)(ecx + eax*4);  // @339_4c1060
  eax = ecx;  // @340_4c1060
  eax = (eax << (u32)(4));  // @341_4c1060
  FL[3] = eax;  // @342_4c1060
  eax = (eax - ecx);  // @343_4c1060
  FL[3] = eax;  // @344_4c1060
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 316), sizeof v); (u32)v; });  // @345_4c1060
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @346_4c1060
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @347_4c1060
  __builtin_memcpy((void *)((u32)(edi + 101) + 0), &X1[0], 4);  // @348_4c1060
  eax = (u32)(ecx + eax*4);  // @349_4c1060
  ext_633654(G(u32, 0x6f5630));  // @350_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @351_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @352_4c1060
  eax = (eax >> (u32)(31));  // @353_4c1060
  FL[3] = eax;  // @354_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @355_4c1060
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 320), sizeof v); (u32)v; });  // @356_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @357_4c1060
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @358_4c1060
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @359_4c1060
  eax = (eax >> (u32)(31));  // @360_4c1060
  FL[3] = eax;  // @361_4c1060
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @362_4c1060
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @363_4c1060
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @364_4c1060
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @365_4c1060
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @366_4c1060
  __builtin_memcpy((void *)((u32)(edi + 105) + 0), &X1[0], 4);  // @367_4c1060
  return eax;  // @368_4c1060
  L4c14a0:;
  eax = ext_634047_cdecl0();  // @370_4c1060
  ecx = edx = 0;  // @371_4c1060
}
PCREG(4c1060, lifted_4c1060);

