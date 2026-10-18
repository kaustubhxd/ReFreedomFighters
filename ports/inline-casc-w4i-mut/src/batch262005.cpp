// batch262005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 STDCALL ext_4b48c0_stdcall1(u32) __asm__("ext_4b48c0");
extern "C" u32 THISCALL ext_4a5da0_thiscall2(u32, u32) __asm__("ext_4a5da0");
extern "C" u32 THISCALL ext_4b5500_thiscall2(u32, u32) __asm__("ext_4b5500");
extern "C" u32 THISCALL ext_4b7f90_thiscall3(u32, u32, u32) __asm__("ext_4b7f90");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4db860_thiscall2(u32, u32) __asm__("ext_4db860");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4dbb00_thiscall2(u32, u32) __asm__("ext_4dbb00");
extern "C" u32 THISCALL ext_4dbd10_thiscall1(u32) __asm__("ext_4dbd10");
extern "C" u32 THISCALL ext_4dbe30_thiscall2(u32, u32) __asm__("ext_4dbe30");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

extern "C" u32 THISCALL ext_4b48c0_thiscall2(u32, u32) __asm__("ext_4b48c0");
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4b4990(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x668b51);  // @h_4b4990
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[80], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_4b4990
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 500), &v, sizeof v); }  // @1_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4b4990
  ebx = (u32)(esi + 242);  // @3_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 516), &v, sizeof v); }  // @4_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @6_4b4990
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @7_4b4990
  FL[2] = (ebx & ebx);  // @8_4b4990
  if (FL[2] == 0) goto L4b4a57;  // @9_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_4b4990
  ecx = (u32)(EBP - 28);  // @11_4b4990
  PV[0] = (u32)(ecx);  // @12_4b4990
  ecx = ebx;  // @13_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @14_4b4990
  ecx = edx = 0;  // @15_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @16_4b4990
  ecx = (u32)(EBP - 28);  // @17_4b4990
  PV[1] = (u32)(ecx);  // @18_4b4990
  ecx = ebx;  // @19_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @20_4b4990
  ecx = edx = 0;  // @21_4b4990
  edi = eax;  // @22_4b4990
  FL[2] = (edi & edi);  // @23_4b4990
  if (FL[2] == 0) goto L4b4a57;  // @24_4b4990
  L4b4a10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_4b4990
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @28_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[2]);  // @30_4b4990
  ecx = edx = 0;  // @31_4b4990
  FL[2] = (eax & eax);  // @32_4b4990
  if (FL[2] == 0) goto L4b4a46;  // @33_4b4990
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @34_4b4990
  ecx = eax;  // @35_4b4990
  eax = ext_4dc110_thiscall1(ecx);  // @36_4b4990
  ecx = 0;  // @37_4b4990
  PV[4] = (u32)(eax);  // @38_4b4990
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[4], PV[3]);  // @39_4b4990
  ecx = edx = 0;  // @40_4b4990
  FL[2] = (eax & eax);  // @41_4b4990
  if (FL[2] == 0) goto L4b4dbc;  // @42_4b4990
  L4b4a46:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_4b4990
  ecx = (u32)(EBP - 28);  // @45_4b4990
  PV[5] = (u32)(ecx);  // @46_4b4990
  ecx = ebx;  // @47_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @48_4b4990
  ecx = edx = 0;  // @49_4b4990
  edi = eax;  // @50_4b4990
  FL[2] = (edi & edi);  // @51_4b4990
  if (FL[2] != 0) goto L4b4a10;  // @52_4b4990
  L4b4a57:;
  ebx = (u32)(esi + 270);  // @54_4b4990
  FL[2] = (ebx & ebx);  // @55_4b4990
  if (FL[2] == 0) goto L4b4ac7;  // @56_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_4b4990
  ecx = (u32)(EBP - 28);  // @58_4b4990
  PV[6] = (u32)(ecx);  // @59_4b4990
  ecx = ebx;  // @60_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @61_4b4990
  ecx = edx = 0;  // @62_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @63_4b4990
  ecx = (u32)(EBP - 28);  // @64_4b4990
  PV[7] = (u32)(ecx);  // @65_4b4990
  ecx = ebx;  // @66_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[7]);  // @67_4b4990
  ecx = edx = 0;  // @68_4b4990
  edi = eax;  // @69_4b4990
  FL[2] = (edi & edi);  // @70_4b4990
  if (FL[2] == 0) goto L4b4ac7;  // @71_4b4990
  L4b4a80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_4b4990
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @75_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[8]);  // @77_4b4990
  ecx = edx = 0;  // @78_4b4990
  FL[2] = (eax & eax);  // @79_4b4990
  if (FL[2] == 0) goto L4b4ab6;  // @80_4b4990
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @81_4b4990
  ecx = eax;  // @82_4b4990
  eax = ext_4dc110_thiscall1(ecx);  // @83_4b4990
  ecx = 0;  // @84_4b4990
  PV[10] = (u32)(eax);  // @85_4b4990
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[10], PV[9]);  // @86_4b4990
  ecx = edx = 0;  // @87_4b4990
  FL[2] = (eax & eax);  // @88_4b4990
  if (FL[2] == 0) goto L4b4dbc;  // @89_4b4990
  L4b4ab6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @91_4b4990
  ecx = (u32)(EBP - 28);  // @92_4b4990
  PV[11] = (u32)(ecx);  // @93_4b4990
  ecx = ebx;  // @94_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[11]);  // @95_4b4990
  ecx = edx = 0;  // @96_4b4990
  edi = eax;  // @97_4b4990
  FL[2] = (edi & edi);  // @98_4b4990
  if (FL[2] != 0) goto L4b4a80;  // @99_4b4990
  L4b4ac7:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @101_4b4990
  FL[2] = (ebx & ebx);  // @102_4b4990
  if (FL[2] == 0) goto L4b4eda;  // @103_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @104_4b4990
  ecx = (u32)(EBP - 544);  // @105_4b4990
  PV[12] = (u32)(ecx);  // @106_4b4990
  ecx = ebx;  // @107_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[12]);  // @108_4b4990
  ecx = edx = 0;  // @109_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @110_4b4990
  ecx = (u32)(EBP - 544);  // @111_4b4990
  PV[13] = (u32)(ecx);  // @112_4b4990
  ecx = ebx;  // @113_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[13]);  // @114_4b4990
  ecx = edx = 0;  // @115_4b4990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @116_4b4990
  edi = eax;  // @117_4b4990
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 512), &v, sizeof v); }  // @118_4b4990
  if (FL[0] == FL[1]) goto L4b4eda;  // @119_4b4990
  L4b4b10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_4b4990
  PV[14] = (u32)(edi);  // @122_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @123_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[14]);  // @125_4b4990
  ecx = edx = 0;  // @126_4b4990
  ebx = eax;  // @127_4b4990
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 496), &v, sizeof v); }  // @128_4b4990
  FL[2] = (ebx & ebx);  // @129_4b4990
  if (FL[2] == 0) goto L4b4eb3;  // @130_4b4990
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @131_4b4990
  ecx = ebx;  // @132_4b4990
  eax = ext_4dc110_thiscall1(ecx);  // @133_4b4990
  ecx = 0;  // @134_4b4990
  PV[16] = (u32)(eax);  // @135_4b4990
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[16], PV[15]);  // @136_4b4990
  ecx = edx = 0;  // @137_4b4990
  FL[2] = (eax & eax);  // @138_4b4990
  if (FL[2] != 0) goto L4b4eb3;  // @139_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @140_4b4990
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 104), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @141_4b4990
  if (FL[0] != FL[1]) goto L4b4b7a;  // @142_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @143_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6888208));  // @145_4b4990
  ecx = edx = 0;  // @146_4b4990
  FL[2] = (eax & eax);  // @147_4b4990
  if (FL[2] != 0) goto L4b4f33;  // @148_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_4b4990
  L4b4b7a:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @151_4b4990
  if (FL[0] != FL[1]) goto L4b53e5;  // @152_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; });  // @153_4b4990
  eax = (eax >> (u32)(10));  // @154_4b4990
  FL[3] = eax;  // @155_4b4990
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @156_4b4990
  FL[2] = ((eax & 0xff) & (u32)(1));  // @157_4b4990
  if (FL[2] != 0) goto L4b53e5;  // @158_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @159_4b4990
  ecx = esi;  // @160_4b4990
  PV[17] = (u32)(edi);  // @161_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @162_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 504), &v, sizeof v); }  // @163_4b4990
  eax = ext_4b5500_thiscall2(ecx, PV[17]);  // @164_4b4990
  ecx = edx = 0;  // @165_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @166_4b4990
  PV[18] = (u32)(eax);  // @167_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 492), &v, sizeof v); }  // @168_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @169_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[18]);  // @171_4b4990
  ecx = edx = 0;  // @172_4b4990
  edi = eax;  // @173_4b4990
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 528), &v, sizeof v); }  // @174_4b4990
  FL[2] = (edi & edi);  // @175_4b4990
  if (FL[2] == 0) goto L4b4c34;  // @176_4b4990
  ecx = edi;  // @177_4b4990
  eax = ext_4db9a0_thiscall2(ecx, (u32)(2097173));  // @178_4b4990
  ecx = 0;  // @179_4b4990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @180_4b4990
  if (FL[2] != 0) goto L4b52bb;  // @181_4b4990
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @182_4b4990
  ecx = esi;  // @183_4b4990
  eax = ext_4b48c0_thiscall2(esi, PV[19]);   // w4i: 0x4b48c0 is a thiscall (ecx = this), the lifter typed it stdcall  // @184_4b4990
  ecx = edx = 0;  // @185_4b4990
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @186_4b4990
  ecx = esi;  // @187_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 524), &v, sizeof v); }  // @188_4b4990
  eax = ext_4b48c0_thiscall2(esi, PV[20]);   // w4i: 0x4b48c0 is a thiscall (ecx = this), the lifter typed it stdcall  // @189_4b4990
  ecx = edx = 0;  // @190_4b4990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 524), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @191_4b4990
  edi = eax;  // @192_4b4990
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @193_4b4990
  if (FL[0] == FL[1]) goto L4b4c19;  // @194_4b4990
  FL[2] = (edi & edi);  // @195_4b4990
  if (FL[2] != 0) goto L4b4f53;  // @196_4b4990
  L4b4c19:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 528), sizeof v); (u32)v; });  // @198_4b4990
  ecx = edi;  // @199_4b4990
  eax = ext_4db860_thiscall2(ecx, (u32)(1));  // @200_4b4990
  ecx = edx = 0;  // @201_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @202_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @203_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 504), &v, sizeof v); }  // @204_4b4990
  L4b4c34:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 154), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @206_4b4990
  if (FL[0] == FL[1]) goto L4b4c7a;  // @207_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @208_4b4990
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 116), sizeof v); (u32)v; });  // @209_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @210_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @211_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[21]);  // @212_4b4990
  ecx = edx = 0;  // @213_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @214_4b4990
  esi = (u32)(EBP - 504);  // @215_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 504), &v, sizeof v); }  // @216_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @217_4b4990
  PV[22] = (u32)(esi);  // @218_4b4990
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @219_4b4990
  ecx = eax;  // @220_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 628)))(ecx, PV[23], PV[22], (u32)(1));  // @221_4b4990
  ecx = edx = 0;  // @222_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; });  // @223_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @224_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @225_4b4990
  ecx = edx = 0;  // @226_4b4990
  L4b4c7a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @228_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @229_4b4990
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 504), sizeof v); (u32)v; });  // @230_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 440)))(ecx, PV[24], (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @231_4b4990
  ecx = edx = 0;  // @232_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @233_4b4990
  ebx = eax;  // @234_4b4990
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 496), sizeof v); (u32)v; });  // @235_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @236_4b4990
  ecx = esi;  // @237_4b4990
  edi = esi;  // @238_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @239_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[25]);  // @240_4b4990
  ecx = edx = 0;  // @241_4b4990
  PV[26] = (u32)(eax);  // @242_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @243_4b4990
  ecx = edi;  // @244_4b4990
  PV[27] = (u32)(ebx);  // @245_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @246_4b4990
  ecx = edx = 0;  // @247_4b4990
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 500), sizeof v); (u32)v; });  // @248_4b4990
  ecx = edi;  // @249_4b4990
  PV[28] = (u32)(eax);  // @250_4b4990
  eax = ext_4b7f90_thiscall3(ecx, PV[28], PV[26]);  // @251_4b4990
  ecx = edx = 0;  // @252_4b4990
  FL[2] = (ebx & ebx);  // @253_4b4990
  if (FL[2] == 0) goto L4b539e;  // @254_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @255_4b4990
  ecx = ebx;  // @256_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6880744));  // @257_4b4990
  ecx = edx = 0;  // @258_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 496), sizeof v); (u32)v; });  // @259_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 492), &v, sizeof v); }  // @260_4b4990
  FL[2] = (eax & eax);  // @261_4b4990
  if (FL[2] == 0) goto L4b4d60;  // @262_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @263_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @264_4b4990
  FL[2] = (ecx & ecx);  // @265_4b4990
  if (FL[2] == 0) goto L4b4d60;  // @266_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @267_4b4990
  edx = (u32)(EBP - 28);  // @268_4b4990
  PV[29] = (u32)(edx);  // @269_4b4990
  edx = (u32)(EBP - 68);  // @270_4b4990
  PV[30] = (u32)(edx);  // @271_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[30], PV[29]);  // @272_4b4990
  ecx = edx = 0;  // @273_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 128), sizeof v); (u32)v; });  // @274_4b4990
  FL[2] = (edx & edx);  // @275_4b4990
  if (FL[2] == 0) goto L4b4d41;  // @276_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @277_4b4990
  PV[31] = (u32)(edx);  // @278_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @279_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @280_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[31]);  // @281_4b4990
  ecx = edx = 0;  // @282_4b4990
  FL[2] = (eax & eax);  // @283_4b4990
  if (FL[2] == 0) goto L4b4d41;  // @284_4b4990
  ecx = (u32)(EBP - 28);  // @285_4b4990
  PV[32] = (u32)(ecx);  // @286_4b4990
  ecx = (u32)(EBP - 104);  // @287_4b4990
  PV[33] = (u32)(ecx);  // @288_4b4990
  ecx = eax;  // @289_4b4990
  eax = ext_4db6c0_thiscall3(ecx, PV[33], PV[32]);  // @290_4b4990
  ecx = edx = 0;  // @291_4b4990
  edx = (u32)(EBP - 104);  // @292_4b4990
  ecx = (u32)(EBP - 68);  // @293_4b4990
  eax = ext_4de480_fastcall2(ecx, edx);  // @294_4b4990
  ecx = edx = 0;  // @295_4b4990
  L4b4d41:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @297_4b4990
  edx = (u32)(EBP - 68);  // @298_4b4990
  PV[34] = (u32)(edx);  // @299_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @300_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[34]);  // @301_4b4990
  ecx = edx = 0;  // @302_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @303_4b4990
  eax = ext_4a5da0_thiscall2(ecx, (u32)(1));  // @304_4b4990
  ecx = edx = 0;  // @305_4b4990
  L4b4d60:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @307_4b4990
  ecx = ebx;  // @308_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 456)))(ecx);  // @309_4b4990
  ecx = edx = 0;  // @310_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @311_4b4990
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }) & (u32)(1048576));  // @312_4b4990
  if (FL[2] == 0) goto L4b4e05;  // @313_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @314_4b4990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 496), &v, sizeof v); }  // @315_4b4990
  FL[2] = (ecx & ecx);  // @316_4b4990
  if (FL[2] == 0) goto L4b4e52;  // @317_4b4990
  L4b4d90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 80), sizeof v); (u32)v; });  // @319_4b4990
  FL[2] = (eax & eax);  // @320_4b4990
  if (FL[2] == 0) goto L4b4da0;  // @321_4b4990
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(1074003968));  // @322_4b4990
  if (FL[2] != 0) goto L4b4dad;  // @323_4b4990
  L4b4da0:;
  eax = ext_4dbe30_thiscall2(ecx, (u32)(1));  // @325_4b4990
  ecx = edx = 0;  // @326_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 496), sizeof v); (u32)v; });  // @327_4b4990
  L4b4dad:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @329_4b4990
  FL[2] = (eax & eax);  // @330_4b4990
  if (FL[2] == 0) goto L4b4dc6;  // @331_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @332_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; });  // @333_4b4990
  goto L4b4dcb;  // @334_4b4990
  L4b4dbc:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @336_4b4990
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @337_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @338_4b4990
  goto L4b4f35;  // @339_4b4990
  L4b4dc6:;
  eax = (u32)(2097154);  // @341_4b4990
  L4b4dcb:;
  FL[2] = (eax & (u32)(8388608));  // @343_4b4990
  if (FL[2] == 0) goto L4b4ddf;  // @344_4b4990
  eax = ext_4dbb00_thiscall2(ecx, (u32)(1));  // @345_4b4990
  ecx = edx = 0;  // @346_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 496), sizeof v); (u32)v; });  // @347_4b4990
  L4b4ddf:;
  eax = ext_4dc630_thiscall3(ecx, (u32)(33554432), (u32)(0));  // @349_4b4990
  ecx = edx = 0;  // @350_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @351_4b4990
  ecx = (u32)(EBP - 496);  // @352_4b4990
  PV[35] = (u32)(ecx);  // @353_4b4990
  ecx = ebx;  // @354_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[35]);  // @355_4b4990
  ecx = edx = 0;  // @356_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 496), sizeof v); (u32)v; });  // @357_4b4990
  FL[2] = (ecx & ecx);  // @358_4b4990
  if (FL[2] != 0) goto L4b4d90;  // @359_4b4990
  goto L4b4e52;  // @360_4b4990
  L4b4e05:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @362_4b4990
  ecx = ebx;  // @363_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @364_4b4990
  ecx = edx = 0;  // @365_4b4990
  FL[2] = (eax & eax);  // @366_4b4990
  if (FL[2] == 0) goto L4b4e23;  // @367_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @368_4b4990
  ecx = ebx;  // @369_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @370_4b4990
  ecx = edx = 0;  // @371_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @372_4b4990
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(1074003968));  // @373_4b4990
  if (FL[2] != 0) goto L4b4e2d;  // @374_4b4990
  L4b4e23:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @376_4b4990
  eax = ext_4dbe30_thiscall2(ecx, (u32)(1));  // @377_4b4990
  ecx = edx = 0;  // @378_4b4990
  L4b4e2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @380_4b4990
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }) & (u32)(8388608));  // @381_4b4990
  if (FL[2] == 0) goto L4b4e43;  // @382_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @383_4b4990
  eax = ext_4dbb00_thiscall2(ecx, (u32)(1));  // @384_4b4990
  ecx = edx = 0;  // @385_4b4990
  L4b4e43:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @387_4b4990
  eax = ext_4dc630_thiscall3(ecx, (u32)(33554432), (u32)(0));  // @388_4b4990
  ecx = edx = 0;  // @389_4b4990
  L4b4e52:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @391_4b4990
  PV[36] = (u32)(ebx);  // @392_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @393_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @394_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @395_4b4990
  ecx = edx = 0;  // @396_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 492), &v, sizeof v); }  // @397_4b4990
  ecx = ebx;  // @398_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @399_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @400_4b4990
  ecx = edx = 0;  // @401_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @402_4b4990
  PV[37] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @403_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @404_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @405_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[37]);  // @406_4b4990
  ecx = edx = 0;  // @407_4b4990
  FL[2] = (eax & eax);  // @408_4b4990
  if (FL[2] != 0) goto L4b5304;  // @409_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @410_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @411_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(937));  // @412_4b4990
  ecx = edx = 0;  // @413_4b4990
  PV[38] = (u32)(eax);  // @414_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @415_4b4990
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[38], (u32)(6890040));  // @416_4b4990
  ecx = edx = 0;  // @417_4b4990
  esi = edi;  // @418_4b4990
  L4b4eb3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @420_4b4990
  edx = (u32)(EBP - 544);  // @421_4b4990
  PV[39] = (u32)(edx);  // @422_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @423_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[39]);  // @424_4b4990
  ecx = edx = 0;  // @425_4b4990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @426_4b4990
  edi = eax;  // @427_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 512), &v, sizeof v); }  // @428_4b4990
  if (FL[0] != FL[1]) goto L4b4b10;  // @429_4b4990
  L4b4eda:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @431_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @432_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(1017));  // @433_4b4990
  ecx = edx = 0;  // @434_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @435_4b4990
  edi = eax;  // @436_4b4990
  eax = (u32)(EBP - 488);  // @437_4b4990
  PV[40] = (u32)(eax);  // @438_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @439_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[40], (u32)(1));  // @440_4b4990
  ecx = edx = 0;  // @441_4b4990
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @442_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @443_4b4990
  ecx = eax;  // @444_4b4990
  reg.state = (s32)((u32)(2));  // @445_4b4990
  eax = ext_4cc1d0_thiscall1(ecx);  // @446_4b4990
    // @447_4b4990
  PV[42] = (u32)(eax);  // @448_4b4990
  PV[43] = (u32)(edi);  // @449_4b4990
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[43], (u32)(6890120), PV[42], PV[41]);  // @450_4b4990
  ecx = edx = 0;  // @451_4b4990
  ecx = (u32)(EBP - 488);  // @452_4b4990
  eax = ext_4cbec0_thiscall1(ecx);  // @453_4b4990
  ecx = edx = 0;  // @454_4b4990
  L4b4f33:;
  eax = 0;  // @456_4b4990
  FL[3] = eax;  // @457_4b4990
  L4b4f35:;
  SEH_LEAVE();  // @459_4b4990
  ext_633654(G(u32, 0x6f5630));  // @460_4b4990
  return eax;  // @461_4b4990
  L4b4f53:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @463_4b4990
  FL[2] = (ebx & ebx);  // @464_4b4990
  if (FL[2] == 0) goto L4b4f9b;  // @465_4b4990
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 27), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @466_4b4990
  if (FL[0] == FL[1]) goto L4b4f9b;  // @467_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @468_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @469_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @470_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @471_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6889772), (u32)(0), (u32)(6889180), (u32)(789), (u32)(0));  // @472_4b4990
  ecx = edx = 0;  // @473_4b4990
  eax = (eax & 0xffff);  // @474_4b4990
  ecx = edi;  // @475_4b4990
  PV[44] = (u32)(eax);  // @476_4b4990
  PV[45] = (u32)(edi);  // @477_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[45], PV[44]);  // @478_4b4990
  ecx = edx = 0;  // @479_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 500), sizeof v); (u32)v; });  // @480_4b4990
  L4b4f9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @482_4b4990
  ecx = edi;  // @483_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 428)))(ecx);  // @484_4b4990
  ecx = edx = 0;  // @485_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @486_4b4990
  ecx = edi;  // @487_4b4990
  PV[46] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 524), sizeof v); (u32)v; });  // @488_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 740)))(ecx, PV[46]);  // @489_4b4990
  ecx = edx = 0;  // @490_4b4990
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 153), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @491_4b4990
  if (FL[0] != FL[1]) goto L4b4fc8;  // @492_4b4990
  FL[2] = (ebx & ebx);  // @493_4b4990
  if (FL[2] == 0) goto L4b4fee;  // @494_4b4990
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @495_4b4990
  if (FL[0] != FL[1]) goto L4b4fee;  // @496_4b4990
  L4b4fc8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @498_4b4990
  ecx = edi;  // @499_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @500_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2149580820));  // @501_4b4990
  ecx = edx = 0;  // @502_4b4990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @503_4b4990
  if (FL[2] == 0) goto L4b4fee;  // @504_4b4990
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 157), &v, sizeof v); }  // @505_4b4990
  ecx = edi;  // @506_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @507_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1412)))(ecx);  // @508_4b4990
  ecx = edx = 0;  // @509_4b4990
  L4b4fee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @511_4b4990
  ecx = edi;  // @512_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @513_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2149580820));  // @514_4b4990
  ecx = edx = 0;  // @515_4b4990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @516_4b4990
  if (FL[2] == 0) goto L4b504d;  // @517_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @518_4b4990
  ecx = edi;  // @519_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1232), sizeof v); (u32)v; });  // @520_4b4990
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @521_4b4990
  ecx = edx = 0;  // @522_4b4990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @523_4b4990
  if (FL[2] == 0) goto L4b504d;  // @524_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @525_4b4990
  eax = 0;  // @526_4b4990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @527_4b4990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @528_4b4990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @529_4b4990
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @530_4b4990
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @531_4b4990
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 4), 4); v; });  // @532_4b4990
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 8), 4); v; });  // @533_4b4990
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 12), 4); v; });  // @534_4b4990
  PV[47] = (u32)(ecx);  // @535_4b4990
  ecx = edi;  // @536_4b4990
  PV[48] = X0[0];  // @537_4b4990
  PV[49] = X0[1];  // @538_4b4990
  PV[50] = X0[2];  // @539_4b4990
  PV[51] = X0[3];  // @540_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 1204)))(ecx, (u32)(0), PV[48], PV[49], PV[50], PV[51]);  // @541_4b4990
  ecx = edx = 0;  // @542_4b4990
  L4b504d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @544_4b4990
  esi = (u32)(6801640);  // @545_4b4990
  ecx = esi;  // @546_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @547_4b4990
  FL[2] = (eax & eax);  // @548_4b4990
  if (FL[2] != 0) ecx = eax;  // @549_4b4990
  PV[52] = (u32)(ecx);  // @550_4b4990
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[52], (u32)(6889792));  // @551_4b4990
  ecx = edx = 0;  // @552_4b4990
  FL[2] = (eax & eax);  // @553_4b4990
  if (FL[2] == 0) goto L4b5129;  // @554_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 500), sizeof v); (u32)v; });  // @555_4b4990
  ecx = esi;  // @556_4b4990
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; });  // @557_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @558_4b4990
  FL[2] = (eax & eax);  // @559_4b4990
  if (FL[2] != 0) ecx = eax;  // @560_4b4990
  eax = (u32)(6889816);  // @561_4b4990
  L4b5090:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @563_4b4990
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @564_4b4990
  if (FL[0] != FL[1]) goto L4b50b0;  // @565_4b4990
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @566_4b4990
  if (FL[2] == 0) goto L4b50ac;  // @567_4b4990
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @568_4b4990
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @569_4b4990
  if (FL[0] != FL[1]) goto L4b50b0;  // @570_4b4990
  ecx = (ecx + (u32)(2));  // @571_4b4990
  FL[3] = ecx;  // @572_4b4990
  eax = (eax + (u32)(2));  // @573_4b4990
  FL[3] = eax;  // @574_4b4990
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @575_4b4990
  if (FL[2] != 0) goto L4b5090;  // @576_4b4990
  L4b50ac:;
  eax = 0;  // @578_4b4990
  FL[3] = eax;  // @579_4b4990
  goto L4b50b5;  // @580_4b4990
  L4b50b0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @582_4b4990
  eax = (eax | (u32)(1));  // @583_4b4990
  FL[3] = eax;  // @584_4b4990
  L4b50b5:;
  FL[2] = (eax & eax);  // @586_4b4990
  if (FL[2] == 0) goto L4b5129;  // @587_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @588_4b4990
  ecx = esi;  // @589_4b4990
  FL[2] = (eax & eax);  // @590_4b4990
  if (FL[2] != 0) ecx = eax;  // @591_4b4990
  eax = (u32)(6889848);  // @592_4b4990
  L4b50c8:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @594_4b4990
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @595_4b4990
  if (FL[0] != FL[1]) goto L4b50e8;  // @596_4b4990
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @597_4b4990
  if (FL[2] == 0) goto L4b50e4;  // @598_4b4990
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @599_4b4990
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @600_4b4990
  if (FL[0] != FL[1]) goto L4b50e8;  // @601_4b4990
  ecx = (ecx + (u32)(2));  // @602_4b4990
  FL[3] = ecx;  // @603_4b4990
  eax = (eax + (u32)(2));  // @604_4b4990
  FL[3] = eax;  // @605_4b4990
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @606_4b4990
  if (FL[2] != 0) goto L4b50c8;  // @607_4b4990
  L4b50e4:;
  eax = 0;  // @609_4b4990
  FL[3] = eax;  // @610_4b4990
  goto L4b50ed;  // @611_4b4990
  L4b50e8:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @613_4b4990
  eax = (eax | (u32)(1));  // @614_4b4990
  FL[3] = eax;  // @615_4b4990
  L4b50ed:;
  FL[2] = (eax & eax);  // @617_4b4990
  if (FL[2] == 0) goto L4b5129;  // @618_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @619_4b4990
  FL[2] = (eax & eax);  // @620_4b4990
  if (FL[2] != 0) esi = eax;  // @621_4b4990
  eax = (u32)(6889864);  // @622_4b4990
  L4b5100:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @624_4b4990
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @625_4b4990
  if (FL[0] != FL[1]) goto L4b5120;  // @626_4b4990
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @627_4b4990
  if (FL[2] == 0) goto L4b511c;  // @628_4b4990
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @629_4b4990
  FL[0] = (ecx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @630_4b4990
  if (FL[0] != FL[1]) goto L4b5120;  // @631_4b4990
  esi = (esi + (u32)(2));  // @632_4b4990
  FL[3] = esi;  // @633_4b4990
  eax = (eax + (u32)(2));  // @634_4b4990
  FL[3] = eax;  // @635_4b4990
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @636_4b4990
  if (FL[2] != 0) goto L4b5100;  // @637_4b4990
  L4b511c:;
  eax = 0;  // @639_4b4990
  FL[3] = eax;  // @640_4b4990
  goto L4b5125;  // @641_4b4990
  L4b5120:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @643_4b4990
  eax = (eax | (u32)(1));  // @644_4b4990
  FL[3] = eax;  // @645_4b4990
  L4b5125:;
  FL[2] = (eax & eax);  // @647_4b4990
  if (FL[2] != 0) goto L4b5142;  // @648_4b4990
  L4b5129:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 500), sizeof v); (u32)v; });  // @650_4b4990
  ecx = edi;  // @651_4b4990
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 157), &v, sizeof v); }  // @652_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @653_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1412)))(ecx);  // @654_4b4990
  ecx = edx = 0;  // @655_4b4990
  goto L4b5148;  // @656_4b4990
  L4b5142:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 500), sizeof v); (u32)v; });  // @658_4b4990
  L4b5148:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 270), sizeof v); (u32)v; });  // @660_4b4990
  ecx = (u32)(esi + 270);  // @661_4b4990
  PV[53] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @662_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[53]);  // @663_4b4990
  ecx = edx = 0;  // @664_4b4990
  ebx = eax;  // @665_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @666_4b4990
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @667_4b4990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @668_4b4990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @669_4b4990
  FL[2] = (eax & eax);  // @670_4b4990
  if (FL[2] == 0) goto L4b5293;  // @671_4b4990
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @672_4b4990
  if (FL[0] == FL[1]) goto L4b528a;  // @673_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @674_4b4990
  ecx = edi;  // @675_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @676_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097267));  // @677_4b4990
  ecx = edx = 0;  // @678_4b4990
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @679_4b4990
  if (FL[2] == 0) goto L4b51ed;  // @680_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @681_4b4990
  ecx = edi;  // @682_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @683_4b4990
  ecx = edx = 0;  // @684_4b4990
  FL[2] = (eax & eax);  // @685_4b4990
  if (FL[2] == 0) goto L4b51c0;  // @686_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @687_4b4990
  ecx = edi;  // @688_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1284)))(ecx);  // @689_4b4990
  ecx = edx = 0;  // @690_4b4990
  ecx = eax;  // @691_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @692_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @693_4b4990
  ecx = edx = 0;  // @694_4b4990
  L4b51c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @696_4b4990
  ecx = edi;  // @697_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1280)))(ecx);  // @698_4b4990
  ecx = edx = 0;  // @699_4b4990
  FL[2] = (eax & eax);  // @700_4b4990
  if (FL[2] == 0) goto L4b528a;  // @701_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @702_4b4990
  ecx = edi;  // @703_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1280)))(ecx);  // @704_4b4990
  ecx = edx = 0;  // @705_4b4990
  ecx = eax;  // @706_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @707_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @708_4b4990
  ecx = edx = 0;  // @709_4b4990
  goto L4b528a;  // @710_4b4990
  L4b51ed:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @712_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @713_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(831));  // @714_4b4990
  ecx = edx = 0;  // @715_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @716_4b4990
  edi = eax;  // @717_4b4990
  eax = (u32)(EBP - 360);  // @718_4b4990
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 524), &v, sizeof v); }  // @719_4b4990
  PV[54] = (u32)(eax);  // @720_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @721_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[54], (u32)(1));  // @722_4b4990
  ecx = edx = 0;  // @723_4b4990
  ebx = eax;  // @724_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @725_4b4990
  eax = (u32)(EBP - 232);  // @726_4b4990
  PV[55] = (u32)(eax);  // @727_4b4990
  reg.state = (s32)((u32)(0));  // @728_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @729_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[55], (u32)(1));  // @730_4b4990
  ecx = edx = 0;  // @731_4b4990
  esi = eax;  // @732_4b4990
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @733_4b4990
  ecx = ebx;  // @734_4b4990
  reg.state = (s32)((u32)(1));  // @735_4b4990
  eax = ext_4cc1d0_thiscall1(ecx);  // @736_4b4990
    // @737_4b4990
  PV[56] = (u32)(eax);  // @738_4b4990
  ecx = esi;  // @739_4b4990
  eax = ext_4cc1d0_thiscall1(ecx);  // @740_4b4990
    // @741_4b4990
  PV[57] = (u32)(eax);  // @742_4b4990
  PV[58] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 524), sizeof v); (u32)v; });  // @743_4b4990
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[58], (u32)(6889896), PV[57], PV[56]);  // @744_4b4990
  ecx = edx = 0;  // @745_4b4990
  ecx = (u32)(EBP - 232);  // @746_4b4990
  eax = ext_4cbec0_thiscall1(ecx);  // @747_4b4990
  ecx = edx = 0;  // @748_4b4990
  ecx = (u32)(EBP - 360);  // @749_4b4990
  reg.state = (s32)((u32)(4294967295));  // @750_4b4990
  eax = ext_4cbec0_thiscall1(ecx);  // @751_4b4990
  ecx = edx = 0;  // @752_4b4990
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @753_4b4990
  L4b528a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @755_4b4990
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @756_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @757_4b4990
  L4b5293:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 512), sizeof v); (u32)v; });  // @759_4b4990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @760_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 528), sizeof v); (u32)v; });  // @761_4b4990
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @762_4b4990
  eax = ext_4db860_thiscall2(ecx, (u32)(0));  // @763_4b4990
  ecx = edx = 0;  // @764_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @765_4b4990
  goto L4b4f35;  // @766_4b4990
  L4b52bb:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @768_4b4990
  ecx = esi;  // @769_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @770_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 564), sizeof v); (u32)v; });  // @771_4b4990
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @772_4b4990
  ecx = edx = 0;  // @773_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @774_4b4990
  ecx = esi;  // @775_4b4990
  ebx = (ebx & 0xffffff00u) | (((eax & 0xff)) & 0xff);  // @776_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 556)))(ecx);  // @777_4b4990
  ecx = edx = 0;  // @778_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; });  // @779_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @780_4b4990
  PV[59] = (u32)(esi);  // @781_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @782_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, PV[59]);  // @783_4b4990
  ecx = edx = 0;  // @784_4b4990
  ecx = (ebx & 0xff);  // @785_4b4990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @786_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 512), sizeof v); (u32)v; });  // @787_4b4990
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @788_4b4990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @789_4b4990
  eax = esi;  // @790_4b4990
  goto L4b4f35;  // @791_4b4990
  L4b5304:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 242), sizeof v); (u32)v; });  // @793_4b4990
  ecx = (u32)(edi + 242);  // @794_4b4990
  PV[60] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @795_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[60]);  // @796_4b4990
  ecx = edx = 0;  // @797_4b4990
  PV[61] = (u32)(esi);  // @798_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @799_4b4990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @800_4b4990
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @801_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @802_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @803_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @804_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[61]);  // @805_4b4990
  ecx = edx = 0;  // @806_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; });  // @807_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @808_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @809_4b4990
  FL[2] = (eax & eax);  // @810_4b4990
  if (FL[2] == 0) goto L4b536f;  // @811_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @812_4b4990
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(8388621);  // @813_4b4990
  if (FL[0] != FL[1]) goto L4b536f;  // @814_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @815_4b4990
  ecx = esi;  // @816_4b4990
  eax = (eax >> (u32)(10));  // @817_4b4990
  FL[3] = eax;  // @818_4b4990
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @819_4b4990
  eax = (eax & (u32)(1));  // @820_4b4990
  FL[3] = eax;  // @821_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @822_4b4990
  eax = ext_4dbd10_thiscall1(ecx);  // @823_4b4990
  ecx = edx = 0;  // @824_4b4990
  L4b536f:;
  PV[62] = (u32)(ebx);  // @826_4b4990
  ecx = edi;  // @827_4b4990
  eax = ext_4b48c0_thiscall2(edi, PV[62]);   // w4i: 0x4b48c0 is a thiscall (ecx = this), the lifter typed it stdcall  // @828_4b4990
  ecx = edx = 0;  // @829_4b4990
  FL[2] = (eax & eax);  // @830_4b4990
  if (FL[2] == 0) goto L4b5387;  // @831_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @832_4b4990
  ecx = eax;  // @833_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 760)))(ecx, (u32)(1));  // @834_4b4990
  ecx = edx = 0;  // @835_4b4990
  L4b5387:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @837_4b4990
  ecx = ebx;  // @838_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @839_4b4990
  ecx = edx = 0;  // @840_4b4990
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 492), sizeof v); (u32)v; });  // @841_4b4990
  goto L4b54a9;  // @842_4b4990
  L4b539e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @844_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @845_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(862));  // @846_4b4990
  ecx = edx = 0;  // @847_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @848_4b4990
  ebx = eax;  // @849_4b4990
  edi = (u32)(6801640);  // @850_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @851_4b4990
  FL[2] = (ecx & ecx);  // @852_4b4990
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @853_4b4990
  if (FL[2] != 0) edi = ecx;  // @854_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 496), sizeof v); (u32)v; });  // @855_4b4990
  eax = ext_4dc110_thiscall1(ecx);  // @856_4b4990
  ecx = 0;  // @857_4b4990
  PV[63] = (u32)(eax);  // @858_4b4990
  PV[64] = (u32)(edi);  // @859_4b4990
  PV[65] = (u32)(ebx);  // @860_4b4990
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[65], (u32)(6889988), PV[64], PV[63]);  // @861_4b4990
  ecx = edx = 0;  // @862_4b4990
  goto L4b4f33;  // @863_4b4990
  L4b53e5:;
  PV[66] = (u32)(edi);  // @865_4b4990
  ecx = esi;  // @866_4b4990
  eax = ext_4b5500_thiscall2(ecx, PV[66]);  // @867_4b4990
  ecx = edx = 0;  // @868_4b4990
  edi = eax;  // @869_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @870_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @871_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @872_4b4990
  FL[2] = (edi & edi);  // @873_4b4990
  if (FL[2] == 0) goto L4b5408;  // @874_4b4990
  PV[67] = (u32)(edi);  // @875_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[67]);  // @876_4b4990
  ecx = edx = 0;  // @877_4b4990
  ebx = eax;  // @878_4b4990
  goto L4b540e;  // @879_4b4990
  L4b5408:;
  PV[68] = (u32)(ebx);  // @881_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[68]);  // @882_4b4990
  ecx = edx = 0;  // @883_4b4990
  edi = eax;  // @884_4b4990
  L4b540e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 270), sizeof v); (u32)v; });  // @886_4b4990
  ecx = (u32)(esi + 270);  // @887_4b4990
  PV[69] = (u32)(edi);  // @888_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[69]);  // @889_4b4990
  ecx = edx = 0;  // @890_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 60), sizeof v); (u32)v; });  // @891_4b4990
  edx = eax;  // @892_4b4990
  ecx = (ecx >> (u32)(10));  // @893_4b4990
  FL[3] = ecx;  // @894_4b4990
  ecx = (ecx & 0xffffff00u) | (((~(ecx & 0xff))) & 0xff);  // @895_4b4990
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 508), &v, sizeof v); }  // @896_4b4990
  FL[2] = ((ecx & 0xff) & (u32)(1));  // @897_4b4990
  if (FL[2] != 0) goto L4b5458;  // @898_4b4990
  ecx = ebx;  // @899_4b4990
  eax = ext_4dbd10_thiscall1(ecx);  // @900_4b4990
  ecx = edx = 0;  // @901_4b4990
  ecx = ebx;  // @902_4b4990
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @903_4b4990
  ecx = 0;  // @904_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 508), sizeof v); (u32)v; });  // @905_4b4990
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @906_4b4990
  goto L4b545f;  // @907_4b4990
  L4b5458:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @909_4b4990
  L4b545f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @911_4b4990
  FL[2] = (eax & eax);  // @912_4b4990
  if (FL[2] == 0) goto L4b546e;  // @913_4b4990
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 25), sizeof v); (u32)v; });  // @914_4b4990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @915_4b4990
  goto L4b5474;  // @916_4b4990
  L4b546e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @918_4b4990
  L4b5474:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 512), sizeof v); (u32)v; });  // @920_4b4990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @921_4b4990
  ecx = esi;  // @922_4b4990
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @923_4b4990
  PV[70] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @924_4b4990
  eax = ext_4b48c0_thiscall2(esi, PV[70]);   // w4i: 0x4b48c0 is a thiscall (ecx = this), the lifter typed it stdcall  // @925_4b4990
  ecx = edx = 0;  // @926_4b4990
  FL[2] = (eax & eax);  // @927_4b4990
  if (FL[2] == 0) goto L4b549e;  // @928_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @929_4b4990
  ecx = eax;  // @930_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 428)))(ecx);  // @931_4b4990
  ecx = edx = 0;  // @932_4b4990
  goto L4b54a9;  // @933_4b4990
  L4b549e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @935_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @936_4b4990
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 428)))(ecx);  // @937_4b4990
  ecx = edx = 0;  // @938_4b4990
  L4b54a9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @940_4b4990
  PV[71] = (u32)(edi);  // @941_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @942_4b4990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @943_4b4990
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[71]);  // @944_4b4990
  ecx = edx = 0;  // @945_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @946_4b4990
  esi = eax;  // @947_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @948_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @949_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 276)))(ecx, (u32)(6881084), (u32)(0), (u32)(6889180), (u32)(1011));  // @950_4b4990
  ecx = edx = 0;  // @951_4b4990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @952_4b4990
  eax = (eax & 0xffff);  // @953_4b4990
  FL[2] = (ecx & ecx);  // @954_4b4990
  if (FL[2] == 0) goto L4b54f8;  // @955_4b4990
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @956_4b4990
  PV[72] = (u32)(eax);  // @957_4b4990
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 312)))(ecx, PV[72], (u32)(1), (u32)(0));  // @958_4b4990
  ecx = edx = 0;  // @959_4b4990
  L4b54f8:;
  eax = edi;  // @961_4b4990
  goto L4b4f35;  // @962_4b4990
}
PCREG(4b4990, lifted_4b4990);

