// batch244028.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 FASTCALL ext_53c210_fastcall3(u32, u32, u32) __asm__("ext_53c210");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_5359f0_thiscall3(u32, u32, u32) __asm__("ext_5359f0");
extern "C" u32 THISCALL ext_6074f0_thiscall1(u32) __asm__("ext_6074f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" u32 ext_634da6_cdecl2(...) __asm__("ext_634da6");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_607640(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e00f);  // @h_607640
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_607640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_607640
  ecx = edi;  // @2_607640
  PV[0] = (u32)(esi);  // @3_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[0]);  // @5_607640
  ecx = edx = 0;  // @6_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_607640
  eax = (u32)(esi + 12);  // @8_607640
  PV[1] = (u32)(eax);  // @9_607640
  ecx = edi;  // @10_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[1]);  // @11_607640
  ecx = edx = 0;  // @12_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_607640
  eax = (u32)(esi + 24);  // @14_607640
  PV[2] = (u32)(eax);  // @15_607640
  ecx = edi;  // @16_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[2]);  // @17_607640
  ecx = edx = 0;  // @18_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_607640
  ecx = (u32)(EBP - 16);  // @20_607640
  PV[3] = (u32)(ecx);  // @21_607640
  ecx = edi;  // @22_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[3]);  // @23_607640
  ecx = edx = 0;  // @24_607640
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @25_607640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @26_607640
  if ((s32)FL[0] <= (s32)FL[1]) goto L6077fd;  // @27_607640
  L6076a7:;
  eax = ext_41e290_cdecl1((u32)(72));  // @29_607640
  ecx = edx = 0;  // @30_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @31_607640
  reg.state = (s32)((u32)(0));  // @32_607640
  FL[2] = (eax & eax);  // @33_607640
  if (FL[2] == 0) goto L6076ca;  // @34_607640
  ecx = eax;  // @35_607640
  eax = ext_6074f0_thiscall1(ecx);  // @36_607640
  ecx = edx = 0;  // @37_607640
  ebx = eax;  // @38_607640
  goto L6076cc;  // @39_607640
  L6076ca:;
  ebx = 0;  // @41_607640
  FL[3] = ebx;  // @42_607640
  L6076cc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_607640
  ecx = (u32)(EBP - 20);  // @45_607640
  PV[4] = (u32)(ecx);  // @46_607640
  ecx = edi;  // @47_607640
  reg.state = (s32)((u32)(4294967295));  // @48_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[4]);  // @49_607640
  ecx = edx = 0;  // @50_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @51_607640
  ecx = (u32)(EBP - 20);  // @52_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @53_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_607640
  PV[5] = (u32)(ecx);  // @55_607640
  ecx = edi;  // @56_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[5]);  // @57_607640
  ecx = edx = 0;  // @58_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @59_607640
  ecx = edi;  // @60_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @61_607640
  eax = (u32)(ebx + 8);  // @62_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @63_607640
  PV[6] = (u32)(eax);  // @64_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[6]);  // @65_607640
  ecx = edx = 0;  // @66_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_607640
  eax = (u32)(ebx + 20);  // @68_607640
  PV[7] = (u32)(eax);  // @69_607640
  ecx = edi;  // @70_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[7]);  // @71_607640
  ecx = edx = 0;  // @72_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @73_607640
  eax = (u32)(ebx + 32);  // @74_607640
  PV[8] = (u32)(eax);  // @75_607640
  ecx = edi;  // @76_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[8]);  // @77_607640
  ecx = edx = 0;  // @78_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @79_607640
  eax = (u32)(ebx + 44);  // @80_607640
  PV[9] = (u32)(eax);  // @81_607640
  ecx = edi;  // @82_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[9]);  // @83_607640
  ecx = edx = 0;  // @84_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_607640
  eax = (u32)(ebx + 56);  // @86_607640
  PV[10] = (u32)(eax);  // @87_607640
  ecx = edi;  // @88_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[10]);  // @89_607640
  ecx = edx = 0;  // @90_607640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @91_607640
  edi = (u32)(ebx + 12);  // @92_607640
  PV[11] = (u32)(edi);  // @93_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[11]);  // @95_607640
  ecx = edx = 0;  // @96_607640
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @97_607640
  if (FL[0] == FL[1]) goto L60778c;  // @98_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @99_607640
  eax = (eax + (u32)(-6));  // @100_607640
  FL[3] = eax;  // @101_607640
  FL[0] = eax; FL[1] = (u32)(15);  // @102_607640
  if (FL[0] > FL[1]) goto L60777e;  // @103_607640
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6322312), sizeof v); (u32)v; });  // @104_607640
  switch (eax) {  // @105_607640
  case 0: goto L607754;  // @106_607640
  case 1: goto L607762;  // @107_607640
  case 2: goto L607770;  // @108_607640
  case 3: goto L60778c;  // @109_607640
  case 4: goto L60777e;  // @110_607640
  default: __builtin_trap(); }  // @111_607640
  L607754:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @113_607640
  eax = (u32)(ebx + 16);  // @114_607640
  PV[12] = (u32)(eax);  // @115_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 96)))(ecx, PV[12]);  // @117_607640
  ecx = edx = 0;  // @118_607640
  goto L60778c;  // @119_607640
  L607762:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @121_607640
  eax = (u32)(ebx + 16);  // @122_607640
  PV[13] = (u32)(eax);  // @123_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 100)))(ecx, PV[13]);  // @125_607640
  ecx = edx = 0;  // @126_607640
  goto L60778c;  // @127_607640
  L607770:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @129_607640
  eax = (u32)(ebx + 16);  // @130_607640
  PV[14] = (u32)(eax);  // @131_607640
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[14]);  // @133_607640
  ecx = edx = 0;  // @134_607640
  goto L60778c;  // @135_607640
  L60777e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @137_607640
  FL[2] = (eax & eax);  // @138_607640
  if (FL[2] == 0) goto L60778b;  // @139_607640
  eax = ((u32(STDCALL *)(void))(eax))();  // @140_607640
  ecx = edx = 0;  // @141_607640
  goto L60778c;  // @142_607640
  L60778b:;
  __builtin_trap();  // @144_607640
  L60778c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @146_607640
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }); FL[1] = eax;  // @147_607640
  if (FL[0] < FL[1]) goto L6077de;  // @148_607640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @149_607640
  eax = (eax + eax);  // @150_607640
  FL[3] = eax;  // @151_607640
  ecx = 0;  // @152_607640
  FL[3] = ecx;  // @153_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @154_607640
  edx = (u32)(4);  // @155_607640
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @156_607640
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @157_607640
  FL[1] = ecx;  // @158_607640
  ecx = (0u - ecx);  // @159_607640
  ecx = (ecx | eax);  // @160_607640
  FL[3] = ecx;  // @161_607640
  PV[15] = (u32)(ecx);  // @162_607640
  eax = ext_41e290_cdecl1(PV[15]);  // @163_607640
  ecx = edx = 0;  // @164_607640
  edx = 0;  // @165_607640
  FL[3] = edx;  // @166_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @167_607640
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }); FL[1] = edx;  // @168_607640
  if (FL[0] <= FL[1]) goto L6077cf;  // @169_607640
  L6077c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @171_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + edx*4), sizeof v); (u32)v; });  // @172_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx*4), &v, sizeof v); }  // @173_607640
  edx = (edx + 1);  // @174_607640
  FL[3] = edx;  // @175_607640
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @176_607640
  if (FL[0] < FL[1]) goto L6077c0;  // @177_607640
  L6077cf:;
  PV[16] = (u32)(edi);  // @179_607640
  eax = ext_41e2c0_cdecl1(PV[16]);  // @180_607640
  ecx = edx = 0;  // @181_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @182_607640
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @183_607640
  L6077de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @185_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @186_607640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @187_607640
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @188_607640
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @189_607640
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @190_607640
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @191_607640
  ebx = (ebx + 1);  // @192_607640
  FL[3] = ebx;  // @193_607640
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @194_607640
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @195_607640
  if ((s32)FL[0] < (s32)FL[1]) goto L6076a7;  // @196_607640
  L6077fd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @198_607640
  ecx = (u32)(EBP - 16);  // @199_607640
  PV[17] = (u32)(ecx);  // @200_607640
  ecx = edi;  // @201_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[17]);  // @202_607640
  ecx = edx = 0;  // @203_607640
  eax = ext_41e290_cdecl1((u32)(21));  // @204_607640
  ecx = edx = 0;  // @205_607640
  ecx = eax;  // @206_607640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @207_607640
  FL[2] = (ecx & ecx);  // @208_607640
  if (FL[2] == 0) goto L60783c;  // @209_607640
  { u32 v = (u32)((u32)(7046408)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @210_607640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @211_607640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @212_607640
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @213_607640
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @214_607640
  goto L60783e;  // @215_607640
  L60783c:;
  ecx = 0;  // @217_607640
  FL[3] = ecx;  // @218_607640
  L60783e:;
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @220_607640
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @221_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[18]);  // @223_607640
  ecx = edx = 0;  // @224_607640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @225_607640
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @226_607640
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @227_607640
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @228_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 16)))(ecx, PV[19]);  // @229_607640
  ecx = edx = 0;  // @230_607640
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @231_607640
  PV[20] = (u32)(eax);  // @232_607640
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 112)))(ecx, PV[20]);  // @233_607640
  ecx = edx = 0;  // @234_607640
  SEH_LEAVE();  // @235_607640
  return eax;  // @236_607640
}
PCREG(607640, lifted_607640);

extern "C" u32 THISCALL lifted_536990(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  esi = ecx;  // @0_536990
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 56) + 12), &v, sizeof v); }  // @1_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_536990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @3_536990
  ecx = edx = 0;  // @4_536990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_536990
  ecx = esi;  // @6_536990
  PV[0] = (u32)(eax);  // @7_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 544)))(ecx, PV[0]);  // @8_536990
  ecx = edx = 0;  // @9_536990
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_536990
  edx = eax;  // @11_536990
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @12_536990
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 56) + 16), &v, sizeof v); }  // @13_536990
  FL[2] = (ebx & ebx);  // @14_536990
  if (FL[2] == 0) goto L536bbc;  // @15_536990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_536990
  eax = (u32)((EBP - 56) + 32);  // @17_536990
  PV[1] = (u32)(eax);  // @18_536990
  ecx = ebx;  // @19_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[1]);  // @20_536990
  ecx = edx = 0;  // @21_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @22_536990
  ecx = (u32)((EBP - 56) + 32);  // @23_536990
  PV[2] = (u32)(ecx);  // @24_536990
  ecx = ebx;  // @25_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @26_536990
  ecx = edx = 0;  // @27_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @28_536990
  ebx = eax;  // @29_536990
  if (FL[0] == FL[1]) goto L536bb8;  // @30_536990
  L5369f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_536990
  PV[3] = (u32)(ebx);  // @33_536990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[3]);  // @36_536990
  ecx = edx = 0;  // @37_536990
  esi = eax;  // @38_536990
  FL[2] = (esi & esi);  // @39_536990
  if (FL[2] == 0) goto L536b9a;  // @40_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(11);  // @41_536990
  if (FL[0] == FL[1]) goto L536b9a;  // @42_536990
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(16));  // @43_536990
  if (FL[2] == 0) goto L536a91;  // @44_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 12), sizeof v); (u32)v; });  // @45_536990
  edx = (u32)(esi + 212);  // @46_536990
  eax = (eax + (u32)(110));  // @47_536990
  FL[3] = eax;  // @48_536990
  ecx = (u32)((EBP - 56) + 20);  // @49_536990
  PV[4] = (u32)(eax);  // @50_536990
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @51_536990
  ecx = edx = 0;  // @52_536990
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 20) + 0), 4); v; });  // @53_536990
  X1[1] = 0;  // @54_536990
  X1[2] = 0;  // @55_536990
  X1[3] = 0;  // @56_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 24) + 0), 4); v; });  // @57_536990
  X0[1] = 0;  // @58_536990
  X0[2] = 0;  // @59_536990
  X0[3] = 0;  // @60_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @61_536990
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @62_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @63_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 28) + 0), 4); v; });  // @64_536990
  X0[1] = 0;  // @65_536990
  X0[2] = 0;  // @66_536990
  X0[3] = 0;  // @67_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @68_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @69_536990
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @70_536990
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @71_536990
  ecx = edx = 0;  // @72_536990
  X1[0] = 0;  // @73_536990
  X1[1] = 0;  // @74_536990
  X1[2] = 0;  // @75_536990
  X1[3] = 0;  // @76_536990
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(4294967279))); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @77_536990
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @78_536990
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @79_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; });  // @80_536990
  X0[1] = 0;  // @81_536990
  X0[2] = 0;  // @82_536990
  X0[3] = 0;  // @83_536990
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956272) + 0), 4); v; })));  // @84_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; })));  // @85_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @86_536990
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; })));  // @87_536990
  __builtin_memcpy((void *)((u32)(esi + 120) + 0), &X1[0], 4);  // @88_536990
  L536a91:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 120) + 0), 4); v; });  // @90_536990
  X0[1] = 0;  // @91_536990
  X0[2] = 0;  // @92_536990
  X0[3] = 0;  // @93_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @94_536990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @95_536990
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @96_536990
  ecx = (ecx - eax);  // @97_536990
  FL[3] = ecx;  // @98_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = ecx;  // @100_536990
  if ((s32)FL[0] >= (s32)FL[1]) goto L536abd;  // @101_536990
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @102_536990
  goto L536b9a;  // @103_536990
  L536abd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @105_536990
  FL[0] = eax; FL[1] = (u32)(2);  // @106_536990
  if (FL[0] == FL[1]) goto L536aca;  // @107_536990
  FL[0] = eax; FL[1] = (u32)(10);  // @108_536990
  if (FL[0] != FL[1]) goto L536ad1;  // @109_536990
  L536aca:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @111_536990
  L536ad1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @113_536990
  FL[0] = eax; FL[1] = (u32)(4);  // @114_536990
  if (FL[0] == FL[1]) goto L536b91;  // @115_536990
  FL[0] = eax; FL[1] = (u32)(5);  // @116_536990
  if (FL[0] == FL[1]) goto L536b91;  // @117_536990
  FL[0] = eax; FL[1] = (u32)(8);  // @118_536990
  if (FL[0] == FL[1]) goto L536b91;  // @119_536990
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 16), sizeof v); (u32)v; });  // @120_536990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 60) + 16), sizeof v); (u32)v; });  // @121_536990
  PV[6] = (u32)(esi);  // @122_536990
  eax = ext_5359f0_thiscall3(ecx, PV[6], PV[5]);  // @123_536990
  ecx = edx = 0;  // @124_536990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @125_536990
  if (FL[2] == 0) goto L536b85;  // @126_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @127_536990
  if (FL[0] == FL[1]) goto L536b14;  // @128_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @129_536990
  ecx = edi;  // @130_536990
  goto L536b96;  // @131_536990
  L536b14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 12), sizeof v); (u32)v; });  // @133_536990
  edx = (u32)(esi + 212);  // @134_536990
  eax = (eax + (u32)(110));  // @135_536990
  FL[3] = eax;  // @136_536990
  ecx = (u32)((EBP - 56) + 44);  // @137_536990
  PV[7] = (u32)(eax);  // @138_536990
  eax = ext_43e920_fastcall3(ecx, edx, PV[7]);  // @139_536990
  ecx = edx = 0;  // @140_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 48) + 0), 4); v; });  // @141_536990
  X0[1] = 0;  // @142_536990
  X0[2] = 0;  // @143_536990
  X0[3] = 0;  // @144_536990
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 44) + 0), 4); v; });  // @145_536990
  X1[1] = 0;  // @146_536990
  X1[2] = 0;  // @147_536990
  X1[3] = 0;  // @148_536990
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 92) + 0), 4); v; });  // @149_536990
  X2[1] = 0;  // @150_536990
  X2[2] = 0;  // @151_536990
  X2[3] = 0;  // @152_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @153_536990
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @154_536990
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @155_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @156_536990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 56) + 52) + 0), 4); v; });  // @157_536990
  X0[1] = 0;  // @158_536990
  X0[2] = 0;  // @159_536990
  X0[3] = 0;  // @160_536990
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @161_536990
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @162_536990
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L536b75;  // @163_536990
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(1));  // @164_536990
  PV[8] = (u32)(ebx);  // @165_536990
  if (FL[2] == 0) goto L536b6f;  // @166_536990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @167_536990
  ecx = esi;  // @168_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @169_536990
  goto L536b97;  // @170_536990
  L536b6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @172_536990
  ecx = edi;  // @173_536990
  goto L536b97;  // @174_536990
  L536b75:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @176_536990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @177_536990
  ecx = esi;  // @178_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_536990
  goto L536b96;  // @180_536990
  L536b85:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @182_536990
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @183_536990
  goto L536b94;  // @184_536990
  L536b91:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @186_536990
  L536b94:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @188_536990
  L536b96:;
  PV[9] = (u32)(ebx);  // @190_536990
  L536b97:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[9], PV[8]);  // @192_536990
  ecx = edx = 0;  // @193_536990
  L536b9a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @195_536990
  edx = (u32)((EBP - 56) + 32);  // @196_536990
  PV[10] = (u32)(edx);  // @197_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @198_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[10]);  // @199_536990
  ecx = edx = 0;  // @200_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @201_536990
  ebx = eax;  // @202_536990
  if (FL[0] != FL[1]) goto L5369f0;  // @203_536990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 12), sizeof v); (u32)v; });  // @204_536990
  L536bb8:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 16), sizeof v); (u32)v; });  // @206_536990
  L536bbc:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @208_536990
  FL[2] = (ecx & ecx);  // @209_536990
  if (FL[2] == 0) goto L536bd9;  // @210_536990
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @211_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @212_536990
  PV[12] = (u32)(edi);  // @213_536990
  PV[13] = (u32)(edx);  // @214_536990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[13], PV[12], PV[11]);  // @215_536990
  ecx = edx = 0;  // @216_536990
  return eax;  // @217_536990
  L536bd9:;
  FL[2] = (edi & edi);  // @219_536990
  if (FL[2] == 0) goto L536c2c;  // @220_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @221_536990
  ecx = (u32)((EBP - 56) + 20);  // @222_536990
  PV[14] = (u32)(ecx);  // @223_536990
  ecx = edi;  // @224_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @225_536990
  ecx = edx = 0;  // @226_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @227_536990
  ecx = (u32)((EBP - 56) + 20);  // @228_536990
  PV[15] = (u32)(ecx);  // @229_536990
  ecx = edi;  // @230_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @231_536990
  ecx = edx = 0;  // @232_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @233_536990
  ecx = eax;  // @234_536990
  if (FL[0] == FL[1]) goto L536c2c;  // @235_536990
  L536c00:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @237_536990
  PV[16] = (u32)(ecx);  // @238_536990
  ecx = eax;  // @239_536990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @240_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[16]);  // @241_536990
  ecx = edx = 0;  // @242_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @243_536990
  ecx = (u32)((EBP - 56) + 20);  // @244_536990
  PV[17] = (u32)(ecx);  // @245_536990
  ecx = edi;  // @246_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[17]);  // @247_536990
  ecx = edx = 0;  // @248_536990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @249_536990
  ecx = (u32)((EBP - 56) + 20);  // @250_536990
  PV[18] = (u32)(ecx);  // @251_536990
  ecx = edi;  // @252_536990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[18]);  // @253_536990
  ecx = edx = 0;  // @254_536990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 56) + 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @255_536990
  ecx = eax;  // @256_536990
  if (FL[0] != FL[1]) goto L536c00;  // @257_536990
  L536c2c:;
  return eax;  // @259_536990
}
PCREG(536990, lifted_536990);

extern "C" u32 THISCALL lifted_53c280(u32 ecx_in) {
  SEH_ENTER(0x66aa76);  // @h_53c280
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
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
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, PV[0], (u32)(6958008));  // @11_53c280
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

extern "C" u32 THISCALL lifted_650120(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_650120
  edx = (u32)(EBP - 4);  // @1_650120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_650120
  PV[0] = (u32)(edx);  // @3_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @5_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091404), PV[0]);  // @6_650120
  ecx = edx = 0;  // @7_650120
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775520), sizeof v); (u32)v; });  // @8_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @9_650120
  if (FL[2] == 0) goto L65016b;  // @10_650120
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @11_650120
  eax = ((u32( *)(u32))(edi))(PV[1]);  // @12_650120
  ecx = edx = 0;  // @13_650120
  ecx = (u32)(2);  // @14_650120
  FL[0] = eax; FL[1] = ecx;  // @15_650120
  if (FL[0] > FL[1]) eax = ecx;  // @16_650120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @17_650120
  FL[0] = eax; FL[1] = (u32)(1);  // @18_650120
  if (FL[0] != FL[1]) goto L65016b;  // @19_650120
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @20_650120
  L65016b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_650120
  edx = (u32)(EBP - 4);  // @23_650120
  PV[2] = (u32)(edx);  // @24_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @26_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6988588), PV[2]);  // @27_650120
  ecx = edx = 0;  // @28_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @29_650120
  if (FL[2] == 0) goto L650193;  // @30_650120
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @31_650120
  eax = ((u32( *)(u32))(edi))(PV[3]);  // @32_650120
  ecx = edx = 0;  // @33_650120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @34_650120
  L650193:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_650120
  edx = (u32)(EBP - 4);  // @37_650120
  PV[4] = (u32)(edx);  // @38_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @40_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091416), PV[4]);  // @41_650120
  ecx = edx = 0;  // @42_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @43_650120
  if (FL[2] == 0) goto L6501b1;  // @44_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 118), &v, sizeof v); }  // @45_650120
  L6501b1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @47_650120
  edx = (u32)(EBP - 4);  // @48_650120
  PV[5] = (u32)(edx);  // @49_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @51_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6988600), PV[5]);  // @52_650120
  ecx = edx = 0;  // @53_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @54_650120
  if (FL[2] == 0) goto L6501cf;  // @55_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @56_650120
  L6501cf:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_650120
  edx = (u32)(EBP - 4);  // @59_650120
  PV[6] = (u32)(edx);  // @60_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @62_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091428), PV[6]);  // @63_650120
  ecx = edx = 0;  // @64_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @65_650120
  if (FL[2] == 0) goto L650203;  // @66_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @67_650120
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @68_650120
  if (FL[0] != FL[1]) goto L6501f5;  // @69_650120
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_650120
  goto L650200;  // @71_650120
  L6501f5:;
  PV[7] = (u32)(eax);  // @73_650120
  eax = ((u32( *)(u32))(edi))(PV[7]);  // @74_650120
  ecx = edx = 0;  // @75_650120
  FL[2] = (eax & eax);  // @76_650120
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @77_650120
  L650200:;
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @79_650120
  L650203:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_650120
  edx = (u32)(EBP - 4);  // @82_650120
  PV[8] = (u32)(edx);  // @83_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @85_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091444), PV[8]);  // @86_650120
  ecx = edx = 0;  // @87_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @88_650120
  if (FL[2] == 0) goto L650221;  // @89_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @90_650120
  L650221:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_650120
  edx = (u32)(EBP - 4);  // @93_650120
  PV[9] = (u32)(edx);  // @94_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @96_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091464), PV[9]);  // @97_650120
  ecx = edx = 0;  // @98_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @99_650120
  if (FL[2] == 0) goto L65023f;  // @100_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @101_650120
  L65023f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @103_650120
  edx = (u32)(EBP - 4);  // @104_650120
  PV[10] = (u32)(edx);  // @105_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @107_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091480), PV[10]);  // @108_650120
  ecx = edx = 0;  // @109_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @110_650120
  if (FL[2] == 0) goto L65025d;  // @111_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @112_650120
  L65025d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_650120
  edx = (u32)(EBP - 4);  // @115_650120
  PV[11] = (u32)(edx);  // @116_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @118_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091492), PV[11]);  // @119_650120
  ecx = edx = 0;  // @120_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @121_650120
  if (FL[2] == 0) goto L65027b;  // @122_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 121), &v, sizeof v); }  // @123_650120
  L65027b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_650120
  edx = (u32)(EBP - 4);  // @126_650120
  PV[12] = (u32)(edx);  // @127_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @129_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091512), PV[12]);  // @130_650120
  ecx = edx = 0;  // @131_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @132_650120
  if (FL[2] == 0) goto L650299;  // @133_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @134_650120
  L650299:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_650120
  edx = (u32)(EBP - 4);  // @137_650120
  PV[13] = (u32)(edx);  // @138_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @140_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091528), PV[13]);  // @141_650120
  ecx = edx = 0;  // @142_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @143_650120
  if (FL[2] == 0) goto L6502b7;  // @144_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @145_650120
  L6502b7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @147_650120
  edx = (u32)(EBP - 4);  // @148_650120
  PV[14] = (u32)(edx);  // @149_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @151_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6988612), PV[14]);  // @152_650120
  ecx = edx = 0;  // @153_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @154_650120
  if (FL[2] == 0) goto L6502d5;  // @155_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @156_650120
  L6502d5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @158_650120
  edx = (u32)(EBP - 4);  // @159_650120
  PV[15] = (u32)(edx);  // @160_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @162_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091544), PV[15]);  // @163_650120
  ecx = edx = 0;  // @164_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @165_650120
  if (FL[2] == 0) goto L6502f3;  // @166_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 117), &v, sizeof v); }  // @167_650120
  L6502f3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_650120
  edx = (u32)(EBP - 4);  // @170_650120
  PV[16] = (u32)(edx);  // @171_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @172_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @173_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091568), PV[16]);  // @174_650120
  ecx = edx = 0;  // @175_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @176_650120
  if (FL[2] == 0) goto L65031f;  // @177_650120
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @178_650120
  eax = ((u32(*)(u32))(*(u32 *)0x6762d4))(PV[17]) /* atof is cdecl */;  // @179_650120
  ecx = edx = 0;  // @180_650120
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 145)) :: "st");  // @181_650120
  L65031f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_650120
  edx = (u32)(EBP - 4);  // @184_650120
  PV[18] = (u32)(edx);  // @185_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @187_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091580), PV[18]);  // @188_650120
  ecx = edx = 0;  // @189_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @190_650120
  if (FL[2] == 0) goto L65033d;  // @191_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 122), &v, sizeof v); }  // @192_650120
  L65033d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @194_650120
  edx = (u32)(EBP - 4);  // @195_650120
  PV[19] = (u32)(edx);  // @196_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @198_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7091596), PV[19]);  // @199_650120
  ecx = edx = 0;  // @200_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @201_650120
  if (FL[2] == 0) goto L65035b;  // @202_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @203_650120
  L65035b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @205_650120
  edx = (u32)(EBP - 4);  // @206_650120
  PV[20] = (u32)(edx);  // @207_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @208_650120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @209_650120
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6988504), PV[20]);  // @210_650120
  ecx = edx = 0;  // @211_650120
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @212_650120
  if (FL[2] == 0) goto L650379;  // @213_650120
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 114), &v, sizeof v); }  // @214_650120
  L650379:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @216_650120
  ecx = (u32)(ecx + 291);  // @217_650120
  eax = ext_4cc1d0_thiscall1(ecx);  // @218_650120
    // @219_650120
  edx = (u32)(7091608);  // @220_650120
  ecx = eax;  // @221_650120
  eax = ext_4cc850_fastcall2(ecx, edx);  // @222_650120
  ecx = edx = 0;  // @223_650120
  FL[2] = (eax & eax);  // @224_650120
  if (FL[2] != 0) goto L65039e;  // @225_650120
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @226_650120
  L65039e:;
  return eax;  // @228_650120
}
PCREG(650120, lifted_650120);

extern "C" u32 THISCALL lifted_535b70_dup28(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @1_535b70
  X0[1] = 0;  // @2_535b70
  X0[2] = 0;  // @3_535b70
  X0[3] = 0;  // @4_535b70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_535b70
  ebx = ecx;  // @6_535b70
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2503) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2503) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 2503) + 0), 4); v; }))))))) goto L535e80;  // @7_535b70
  FL[2] = (edi & edi);  // @8_535b70
  if (FL[2] == 0) goto L535e80;  // @9_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @10_535b70
  ecx = (u32)(EBP - 72);  // @11_535b70
  PV[0] = (u32)(ecx);  // @12_535b70
  ecx = edi;  // @13_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @14_535b70
  ecx = edx = 0;  // @15_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_535b70
  ecx = (u32)(EBP - 72);  // @17_535b70
  PV[1] = (u32)(ecx);  // @18_535b70
  ecx = edi;  // @19_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @20_535b70
  ecx = edx = 0;  // @21_535b70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_535b70
  edx = eax;  // @23_535b70
  if (FL[0] == FL[1]) goto L535e80;  // @24_535b70
  L535bd0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_535b70
  PV[2] = (u32)(edx);  // @27_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[2]);  // @30_535b70
  ecx = edx = 0;  // @31_535b70
  esi = eax;  // @32_535b70
  FL[2] = (esi & esi);  // @33_535b70
  if (FL[2] == 0) goto L535e68;  // @34_535b70
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(64));  // @35_535b70
  if (FL[2] != 0) goto L535e68;  // @36_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_535b70
  ecx = ebx;  // @38_535b70
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @39_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[3]);  // @40_535b70
  ecx = edx = 0;  // @41_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_535b70
  ecx = ebx;  // @43_535b70
  PV[4] = (u32)(eax);  // @44_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 476)))(ecx, PV[4]);  // @45_535b70
  ecx = edx = 0;  // @46_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 212) + 0), 4); v; });  // @47_535b70
  X0[1] = 0;  // @48_535b70
  X0[2] = 0;  // @49_535b70
  X0[3] = 0;  // @50_535b70
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @51_535b70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 216) + 0), 4); v; });  // @52_535b70
  X1[1] = 0;  // @53_535b70
  X1[2] = 0;  // @54_535b70
  X1[3] = 0;  // @55_535b70
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @56_535b70
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; })));  // @57_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 220) + 0), 4); v; });  // @58_535b70
  X0[1] = 0;  // @59_535b70
  X0[2] = 0;  // @60_535b70
  X0[3] = 0;  // @61_535b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @62_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_535b70
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @64_535b70
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @65_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @66_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(0));  // @68_535b70
  ecx = edx = 0;  // @69_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_535b70
  PV[5] = (u32)(eax);  // @71_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @72_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @73_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[5]);  // @74_535b70
  ecx = edx = 0;  // @75_535b70
  esi = eax;  // @76_535b70
  FL[2] = (esi & esi);  // @77_535b70
  if (FL[2] == 0) goto L535e7f;  // @78_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @79_535b70
  eax = (u32)(EBP - 16);  // @80_535b70
  PV[6] = (u32)(eax);  // @81_535b70
  ecx = esi;  // @82_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[6]);  // @83_535b70
  ecx = edx = 0;  // @84_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @85_535b70
  X0[1] = 0;  // @86_535b70
  X0[2] = 0;  // @87_535b70
  X0[3] = 0;  // @88_535b70
  X1[0] = 0;  // @89_535b70
  X1[1] = 0;  // @90_535b70
  X1[2] = 0;  // @91_535b70
  X1[3] = 0;  // @92_535b70
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L535e68;  // @93_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @94_535b70
  ecx = (u32)(EBP - 32);  // @95_535b70
  PV[7] = (u32)(ecx);  // @96_535b70
  ecx = esi;  // @97_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[7]);  // @98_535b70
  ecx = edx = 0;  // @99_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @100_535b70
  X0[1] = 0;  // @101_535b70
  X0[2] = 0;  // @102_535b70
  X0[3] = 0;  // @103_535b70
  ecx = esi;  // @104_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; })));  // @105_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_535b70
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @107_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 584), sizeof v); (u32)v; });  // @108_535b70
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @109_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @110_535b70
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @111_535b70
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @112_535b70
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @113_535b70
  ecx = edx = 0;  // @114_535b70
  __asm__ volatile("fdivrs %0" :: "m"(*(float *)(u32)(EBP - 20)) : "st");  // @115_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @117_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_535b70
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @119_535b70
  X2[1] = 0;  // @120_535b70
  X2[2] = 0;  // @121_535b70
  X2[3] = 0;  // @122_535b70
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 88) + 0), 4); v; })));  // @123_535b70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @124_535b70
  X1[1] = 0;  // @125_535b70
  X1[2] = 0;  // @126_535b70
  X1[3] = 0;  // @127_535b70
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; })));  // @128_535b70
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; })));  // @129_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @130_535b70
  X0[1] = 0;  // @131_535b70
  X0[2] = 0;  // @132_535b70
  X0[3] = 0;  // @133_535b70
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 64) + 0), 4); v; })));  // @134_535b70
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @135_535b70
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 36)) :: "st");  // @136_535b70
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @137_535b70
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @138_535b70
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @139_535b70
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X2[0], 4);  // @140_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @141_535b70
  ecx = edx = 0;  // @142_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @143_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @144_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @145_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @146_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @147_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @148_535b70
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @149_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @150_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 4), &X0[1], 4);  // @151_535b70
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 44)) : "st");  // @152_535b70
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[8] = (u32)v_; PV[9] = (u32)(v_ >> 32); }  // @153_535b70
  eax = ext_634da6_cdecl2(PV[8], PV[9]);  // @154_535b70
    // @155_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_535b70
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 60)) :: "st");  // @157_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @158_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 240)))(ecx);  // @160_535b70
  ecx = edx = 0;  // @161_535b70
  FL[1] = eax;  // @162_535b70
  eax = (0u - eax);  // @163_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @164_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @165_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @166_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @167_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @168_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @169_535b70
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @170_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @171_535b70
  __builtin_memcpy((void *)((u32)(EBP - 44) + 4), &X0[1], 4);  // @172_535b70
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 44)) : "st");  // @173_535b70
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[10] = (u32)v_; PV[11] = (u32)(v_ >> 32); }  // @174_535b70
  eax = ext_634da6_cdecl2(PV[10], PV[11]);  // @175_535b70
    // @176_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 48), sizeof v); (u32)v; });  // @177_535b70
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 56)) :: "st");  // @178_535b70
  FL[2] = (eax & eax);  // @179_535b70
  if (FL[2] == 0) goto L535e68;  // @180_535b70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @181_535b70
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @182_535b70
  FL[3] = esi;  // @183_535b70
  if (FL[3] == 0) goto L535e68;  // @184_535b70
  ecx = esi;  // @185_535b70
  edx = (u32)(ecx + 1);  // @186_535b70
  L535db0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @188_535b70
  ecx = (ecx + 1);  // @189_535b70
  FL[3] = ecx;  // @190_535b70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @191_535b70
  if (FL[2] != 0) goto L535db0;  // @192_535b70
  ecx = (ecx - edx);  // @193_535b70
  FL[3] = ecx;  // @194_535b70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @195_535b70
  X1[1] = 0;  // @196_535b70
  X1[2] = 0;  // @197_535b70
  X1[3] = 0;  // @198_535b70
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @199_535b70
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @200_535b70
  ecx = (ecx >> (u32)(31));  // @201_535b70
  FL[3] = ecx;  // @202_535b70
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 4), 4); v; })));  // @203_535b70
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @204_535b70
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @205_535b70
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @206_535b70
  X0[0] = 0;  // @207_535b70
  X0[1] = 0;  // @208_535b70
  X0[2] = 0;  // @209_535b70
  X0[3] = 0;  // @210_535b70
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X1[0], 4);  // @211_535b70
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L535e68;  // @212_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @213_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @214_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @215_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @216_535b70
  ecx = edx = 0;  // @217_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @218_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @219_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @220_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @221_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @222_535b70
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; }))))))) goto L535e68;  // @223_535b70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @224_535b70
  X0[1] = 0;  // @225_535b70
  X0[2] = 0;  // @226_535b70
  X0[3] = 0;  // @227_535b70
  X1[0] = 0;  // @228_535b70
  X1[1] = 0;  // @229_535b70
  X1[2] = 0;  // @230_535b70
  X1[3] = 0;  // @231_535b70
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L535e68;  // @232_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @234_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @235_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @236_535b70
  ecx = edx = 0;  // @237_535b70
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @238_535b70
  X0[0] = F2U((float)(s32)X0[0]);  // @239_535b70
  X0[1] = F2U((float)(s32)X0[1]);  // @240_535b70
  X0[2] = F2U((float)(s32)X0[2]);  // @241_535b70
  X0[3] = F2U((float)(s32)X0[3]);  // @242_535b70
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; }))))))) goto L535e68;  // @243_535b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @244_535b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @245_535b70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @246_535b70
  ecx = edx = 0;  // @247_535b70
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @248_535b70
  PV[12] = (u32)(esi);  // @249_535b70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @250_535b70
  PV[13] = (u32)(ecx);  // @251_535b70
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @252_535b70
  PV[14] = (u32)(ecx);  // @253_535b70
  PV[15] = (u32)(eax);  // @254_535b70
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[15], PV[14], PV[13], (u32)(6779752), PV[12]);  // @255_535b70
  ecx = edx = 0;  // @256_535b70
  L535e68:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @258_535b70
  ecx = (u32)(EBP - 72);  // @259_535b70
  PV[16] = (u32)(ecx);  // @260_535b70
  ecx = edi;  // @261_535b70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[16]);  // @262_535b70
  ecx = edx = 0;  // @263_535b70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @264_535b70
  edx = eax;  // @265_535b70
  if (FL[0] != FL[1]) goto L535bd0;  // @266_535b70
  L535e7f:;
  L535e80:;
  ext_633654(G(u32, 0x6f5630));  // @269_535b70
  return eax;  // @270_535b70
}
// (duplicate lift of 0x535b70, the registered port lives in batch244029.cpp)

