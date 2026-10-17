// batch230011.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_5af130_fastcall3(u32, u32, u32) __asm__("ext_5af130");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_568dc0_thiscall1(u32) __asm__("ext_568dc0");
extern "C" u32 THISCALL ext_5950c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5950c0");
extern "C" u32 THISCALL ext_5a8510_thiscall3(u32, u32, u32) __asm__("ext_5a8510");
extern "C" u32 THISCALL ext_5af0d0_thiscall2(u32, u32) __asm__("ext_5af0d0");
extern "C" u32 THISCALL ext_5af5b0_thiscall4(u32, u32, u32, u32) __asm__("ext_5af5b0");
extern "C" u32 THISCALL ext_5afbb0_thiscall3(u32, u32, u32) __asm__("ext_5afbb0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_567f70(u32 ecx_in) {
  u8 F[0x9c0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x8c0); __asm__ volatile("" : "+r"(EBP) :: "memory");   // w3e experiment: opaque frame pointer
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_567f70
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 656), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_567f70
  if (FL[0] == FL[1]) goto L568167;  // @2_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @4_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(6932112));  // @6_567f70
  ecx = edx = 0;  // @7_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 665), &v, sizeof v); }  // @8_567f70
  ecx = eax;  // @9_567f70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, (u32)(6974956));  // @11_567f70
  ecx = edx = 0;  // @12_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @13_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 669), &v, sizeof v); }  // @14_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2130), sizeof v); (u32)v; });  // @15_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 652), &v, sizeof v); }  // @16_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_567f70
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1124)))(ecx);  // @18_567f70
  ecx = edx = 0;  // @19_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 648), &v, sizeof v); }  // @20_567f70
  ecx = (u32)(ebx + 636);  // @21_567f70
  eax = (u32)(ebx + 384);  // @22_567f70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 656), &v, sizeof v); }  // @23_567f70
  PV[0] = (u32)(eax);  // @24_567f70
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @25_567f70
  eax = ext_5afbb0_thiscall3(ecx, PV[1], PV[0]);  // @26_567f70
  ecx = edx = 0;  // @27_567f70
  edi = (u32)(ebx + 552);  // @28_567f70
  ecx = edi;  // @29_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @30_567f70
    // @31_567f70
  FL[2] = (eax & eax);  // @32_567f70
  if (FL[2] == 0) goto L568167;  // @33_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @36_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(6976420));  // @38_567f70
  ecx = edx = 0;  // @39_567f70
  edx = (u32)((EBP - 2112) + 56);  // @40_567f70
  edx = (edx - eax);  // @41_567f70
  FL[3] = edx;  // @42_567f70
  L568042:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @44_567f70
  eax = (u32)(eax + 1);  // @45_567f70
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @46_567f70
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @47_567f70
  if (FL[2] != 0) goto L568042;  // @48_567f70
  ecx = (u32)((EBP - 2112) + 56);  // @49_567f70
  ecx = (ecx - 1);  // @50_567f70
  FL[3] = ecx;  // @51_567f70
  L568054:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @53_567f70
  ecx = (u32)(ecx + 1);  // @54_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @55_567f70
  if (FL[2] != 0) goto L568054;  // @56_567f70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6976432), sizeof v); (u32)v; })) & 0xffff);  // @57_567f70
  esi = 0;  // @58_567f70
  FL[3] = esi;  // @59_567f70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @60_567f70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6976434), sizeof v); (u32)v; })) & 0xff);  // @61_567f70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @62_567f70
  ecx = edi;  // @63_567f70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 2112) + 12), &v, sizeof v); }  // @64_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @65_567f70
    // @66_567f70
  FL[2] = (eax & eax);  // @67_567f70
  if ((s32)FL[2] <= 0) goto L56814f;  // @68_567f70
  L568084:;
  PV[2] = (u32)(esi);  // @70_567f70
  ecx = edi;  // @71_567f70
  eax = ext_5af0d0_thiscall2(ecx, PV[2]);  // @72_567f70
    // @73_567f70
  edx = (u32)(6801640);  // @74_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @76_567f70
  FL[2] = (eax & eax);  // @77_567f70
  if (FL[2] != 0) edx = eax;  // @78_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_567f70
  PV[3] = (u32)(edx);  // @80_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @81_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @82_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6850972), PV[3]);  // @84_567f70
  ecx = edx = 0;  // @85_567f70
  edx = eax;  // @86_567f70
  esi = eax;  // @87_567f70
  L5680c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @89_567f70
  edx = (edx + 1);  // @90_567f70
  FL[3] = edx;  // @91_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @92_567f70
  if (FL[2] != 0) goto L5680c0;  // @93_567f70
  edi = (u32)((EBP - 2112) + 56);  // @94_567f70
  edx = (edx - esi);  // @95_567f70
  FL[3] = edx;  // @96_567f70
  edi = (edi - 1);  // @97_567f70
  FL[3] = edi;  // @98_567f70
  L5680d0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @100_567f70
  edi = (edi + 1);  // @101_567f70
  FL[3] = edi;  // @102_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @103_567f70
  if (FL[2] != 0) goto L5680d0;  // @104_567f70
  ecx = edx;  // @105_567f70
  ecx = (ecx >> (u32)(2));  // @106_567f70
  FL[3] = ecx;  // @107_567f70
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @108_567f70
  ecx = edx;  // @109_567f70
  ecx = (ecx & (u32)(3));  // @110_567f70
  FL[3] = ecx;  // @111_567f70
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @112_567f70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2112) + 12), sizeof v); (u32)v; });  // @113_567f70
  edi = (u32)(ebx + 552);  // @114_567f70
  esi = (esi + 1);  // @115_567f70
  FL[3] = esi;  // @116_567f70
  ecx = edi;  // @117_567f70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 2112) + 12), &v, sizeof v); }  // @118_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @119_567f70
    // @120_567f70
  FL[0] = esi; FL[1] = eax;  // @121_567f70
  if ((s32)FL[0] >= (s32)FL[1]) goto L568140;  // @122_567f70
  ecx = (u32)((EBP - 2112) + 56);  // @123_567f70
  ecx = (ecx - 1);  // @124_567f70
  FL[3] = ecx;  // @125_567f70
  L568105:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @127_567f70
  ecx = (u32)(ecx + 1);  // @128_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @129_567f70
  if (FL[2] != 0) goto L568105;  // @130_567f70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6793336), sizeof v); (u32)v; })) & 0xffff);  // @131_567f70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @132_567f70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6793338), sizeof v); (u32)v; })) & 0xff);  // @133_567f70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @134_567f70
  ecx = (u32)((EBP - 2112) + 56);  // @135_567f70
  ecx = (ecx - 1);  // @136_567f70
  FL[3] = ecx;  // @137_567f70
  L568125:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @139_567f70
  ecx = (u32)(ecx + 1);  // @140_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @141_567f70
  if (FL[2] != 0) goto L568125;  // @142_567f70
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6976432), sizeof v); (u32)v; })) & 0xffff);  // @143_567f70
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @144_567f70
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6976434), sizeof v); (u32)v; })) & 0xff);  // @145_567f70
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 2), &v, sizeof v); }  // @146_567f70
  L568140:;
  ecx = edi;  // @148_567f70
  eax = ext_4cc1d0_thiscall1(ecx);  // @149_567f70
    // @150_567f70
  FL[0] = esi; FL[1] = eax;  // @151_567f70
  if ((s32)FL[0] < (s32)FL[1]) goto L568084;  // @152_567f70
  L56814f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 652), sizeof v); (u32)v; });  // @154_567f70
  eax = (u32)((EBP - 2112) + 56);  // @155_567f70
  PV[4] = (u32)(eax);  // @156_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 7439), sizeof v); (u32)v; });  // @157_567f70
  eax = ext_5a8510_thiscall3(ecx, PV[4], (u32)(1));  // @158_567f70
  ecx = edx = 0;  // @159_567f70
  L568167:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @161_567f70
  edx = (u32)((EBP - 2112) + 44);  // @162_567f70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; });  // @163_567f70
  X0[1] = 0;  // @164_567f70
  X0[2] = 0;  // @165_567f70
  X0[3] = 0;  // @166_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 657), &v, sizeof v); }  // @167_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2112) + 44), &v, sizeof v); }  // @168_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2112) + 48), &v, sizeof v); }  // @169_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2112) + 52), &v, sizeof v); }  // @170_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_567f70
  PV[5] = (u32)(edx);  // @172_567f70
  __builtin_memcpy((void *)((u32)((EBP - 2116) + 16) + 0), &X0[0], 4);  // @173_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[5]);  // @174_567f70
  ecx = edx = 0;  // @175_567f70
  esi = (u32)(ebx + 1006);  // @176_567f70
  edi = (u32)(8);  // @177_567f70
  L5681b5:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @179_567f70
  if (FL[0] == FL[1]) goto L568259;  // @180_567f70
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @181_567f70
  ecx = (u32)(ebx + 468);  // @182_567f70
  eax = ext_5af130_fastcall3(ecx, edx, PV[6]);  // @183_567f70
  edx = 0;  // @184_567f70
  FL[2] = (eax & eax);  // @185_567f70
  if (FL[2] == 0) goto L568259;  // @186_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @187_567f70
  edx = (u32)((EBP - 2112) + 32);  // @188_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2112) + 32), &v, sizeof v); }  // @189_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2112) + 36), &v, sizeof v); }  // @190_567f70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 2112) + 40), &v, sizeof v); }  // @191_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_567f70
  PV[7] = (u32)(edx);  // @193_567f70
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[7]);  // @194_567f70
  ecx = edx = 0;  // @195_567f70
  eax = (u32)((EBP - 2112) + 32);  // @196_567f70
  PV[8] = (u32)(eax);  // @197_567f70
  edx = (u32)((EBP - 2116) + 48);  // @198_567f70
  ecx = (u32)((EBP - 2116) + 24);  // @199_567f70
  eax = ext_43e920_fastcall3(ecx, edx, PV[8]);  // @200_567f70
  ecx = edx = 0;  // @201_567f70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2112) + 20) + 0), 4); v; });  // @202_567f70
  X1[1] = 0;  // @203_567f70
  X1[2] = 0;  // @204_567f70
  X1[3] = 0;  // @205_567f70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2112) + 24) + 0), 4); v; });  // @206_567f70
  X0[1] = 0;  // @207_567f70
  X0[2] = 0;  // @208_567f70
  X0[3] = 0;  // @209_567f70
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @210_567f70
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @211_567f70
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @212_567f70
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2112) + 28) + 0), 4); v; });  // @213_567f70
  X0[1] = 0;  // @214_567f70
  X0[2] = 0;  // @215_567f70
  X0[3] = 0;  // @216_567f70
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @217_567f70
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @218_567f70
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @219_567f70
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @220_567f70
  ecx = edx = 0;  // @221_567f70
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 2112) + 12) + 0), 4); v; });  // @222_567f70
  X1[1] = 0;  // @223_567f70
  X1[2] = 0;  // @224_567f70
  X1[3] = 0;  // @225_567f70
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @226_567f70
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L568259;  // @227_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @228_567f70
  __builtin_memcpy((void *)((u32)((EBP - 2112) + 12) + 0), &X0[0], 4);  // @229_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 657), &v, sizeof v); }  // @230_567f70
  L568259:;
  esi = (esi + (u32)(8));  // @232_567f70
  FL[3] = esi;  // @233_567f70
  edi = (edi - (u32)(1));  // @234_567f70
  FL[3] = edi;  // @235_567f70
  if (FL[3] != 0) goto L5681b5;  // @236_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @237_567f70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 2112) + 16), &v, sizeof v); }  // @238_567f70
  FL[2] = (eax & eax);  // @239_567f70
  if (FL[2] == 0) goto L5682f2;  // @240_567f70
  PV[9] = (u32)(eax);  // @241_567f70
  ecx = (u32)(ebx + 384);  // @242_567f70
  eax = ext_5af130_fastcall3(ecx, edx, PV[9]);  // @243_567f70
  edx = 0;  // @244_567f70
  ecx = (u32)(ebx + 636);  // @245_567f70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @246_567f70
  eax = (u32)((EBP - 2112) + 12);  // @247_567f70
  if (FL[0] != FL[1]) goto L568297;  // @248_567f70
  goto L568299;  // @249_567f70
  L568297:;
  L568299:;
  PV[10] = (u32)(eax);  // @252_567f70
  eax = (u32)((EBP - 2120) + 24);  // @253_567f70
  PV[11] = (u32)(eax);  // @254_567f70
  eax = ext_5af5b0_thiscall4(ecx, PV[11], PV[10], (u32)((FL[0] == FL[1]) ? 1 : 0));  // w3e: the lifter lost the push 1 / push 0 diamond  // @255_567f70
  ecx = edx = 0;  // @256_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2112) + 16), sizeof v); (u32)v; });  // @257_567f70
  FL[2] = (eax & eax);  // @258_567f70
  if (FL[2] != 0) goto L5682b5;  // @259_567f70
  ecx = ebx;  // @260_567f70
  eax = ext_568dc0_thiscall1(ecx);  // @261_567f70
  ecx = edx = 0;  // @262_567f70
  goto L5682f2;  // @263_567f70
  L5682b5:;
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @265_567f70
  if (FL[0] == FL[1]) goto L5682f2;  // @266_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @267_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @268_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @269_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @270_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6976444), (u32)(6976436));  // w3e: the extra `1` was the stray push of the push-1/push-0 diamond  // @271_567f70
  ecx = edx = 0;  // @272_567f70
  PV[12] = (u32)(eax);  // @273_567f70
  PV[13] = (u32)(ecx);  // @274_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @275_567f70
  eax = ext_5950c0_thiscall4(ecx, (u32)(17), (u32)(1133903872), PV[12]);  // @276_567f70
    // @277_567f70
  L5682f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @279_567f70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 661), &v, sizeof v); }  // @280_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_567f70
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 669), sizeof v); (u32)v; });  // @282_567f70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @283_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @284_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 44), sizeof v); (u32)v; });  // @285_567f70
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[14], (u32)(0));  // @286_567f70
  ecx = edx = 0;  // @287_567f70
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @288_567f70
  if (FL[2] == 0) goto L568333;  // @289_567f70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 657), sizeof v); (u32)v; });  // @290_567f70
  FL[2] = (eax & eax);  // @291_567f70
  if (FL[2] == 0) goto L568333;  // @292_567f70
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 2112) + 16), sizeof v); (u32)v; });  // @293_567f70
  if (FL[0] == FL[1]) goto L568333;  // @294_567f70
  ecx = ebx;  // @295_567f70
  eax = ext_568dc0_thiscall1(ecx);  // @296_567f70
  ecx = edx = 0;  // @297_567f70
  L568333:;
  ext_633654(G(u32, 0x6f5630));  // @299_567f70
  return eax;  // @300_567f70
}
PCREG(567f70, lifted_567f70);

