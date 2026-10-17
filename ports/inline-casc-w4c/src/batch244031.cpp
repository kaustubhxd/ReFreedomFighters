// batch244031.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 ext_634dd6_cdecl0(void) __asm__("ext_634dd6");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

static inline u32 vcall_cc2(u32 fn, u32 ecx, u32 a, u32 b) {  // thiscall with caller-cleaned stack (variadic member): ecx = this, two pushed args
  u32 r; u32 c_ = ecx;
  __asm__ volatile("push %[b]\n\tpush %[a]\n\tcall *%[fn]\n\tadd $8, %%esp" : "=a"(r), "+c"(c_) : [fn] "r"(fn), [a] "r"(a), [b] "r"(b) : "edx", "memory", "cc");
  return r;
}
extern "C" u32 THISCALL lifted_535ea0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_535ea0
  ebx = ecx;  // @1_535ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @2_535ea0
  { u32 v = (u32)((u32)(6955488)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @3_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @4_535ea0
  { u32 v = (u32)((u32)(6955492)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @5_535ea0
  { u32 v = (u32)((u32)(6955504)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @6_535ea0
  { u32 v = (u32)((u32)(6955508)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @7_535ea0
  { u32 v = (u32)((u32)(6955516)); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @8_535ea0
  { u32 v = (u32)((u32)(6955524)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @9_535ea0
  { u32 v = (u32)((u32)(6955532)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @10_535ea0
  { u32 v = (u32)((u32)(6955540)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @11_535ea0
  { u32 v = (u32)((u32)(6955548)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @12_535ea0
  { u32 v = (u32)((u32)(6955560)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @13_535ea0
  { u32 v = (u32)((u32)(6955568)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @14_535ea0
  { u32 v = (u32)((u32)(6955576)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @15_535ea0
  { u32 v = (u32)((u32)(6955516)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @16_535ea0
  { u32 v = (u32)((u32)(6955580)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @17_535ea0
  { u32 v = (u32)((u32)(6955588)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @18_535ea0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @19_535ea0
  ecx = edx = 0;  // @20_535ea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @21_535ea0
  edi = eax;  // @22_535ea0
  PV[0] = (u32)(edi);  // @23_535ea0
  ecx = ebx;  // @24_535ea0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @25_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 544)))(ecx, PV[0]);  // @26_535ea0
  ecx = edx = 0;  // @27_535ea0
  esi = 0;  // @28_535ea0
  FL[3] = esi;  // @29_535ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @30_535ea0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20821), sizeof v); (u32)v; }); FL[1] = esi;  // @31_535ea0
  if ((s32)FL[0] <= (s32)FL[1]) goto L535f95;  // @32_535ea0
  edi = (u32)(ebx + 20825);  // @33_535ea0
  L535f52:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_535ea0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @37_535ea0
  ecx = edx = 0;  // @38_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @39_535ea0
  X0[1] = 0;  // @40_535ea0
  X0[2] = 0;  // @41_535ea0
  X0[3] = 0;  // @42_535ea0
  ecx = (u32)(esi + 3);  // @43_535ea0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @44_535ea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_535ea0
  PV[1] = X0[0]; PV[2] = X0[1];  // @46_535ea0
  PV[3] = (u32)(ecx);  // @47_535ea0
  PV[4] = (u32)(eax);  // @48_535ea0
  eax = ((u32(*)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[4], (u32)(0), PV[3], (u32)(6955596), PV[1], PV[2]);  // @49_535ea0
  ecx = edx = 0;  // @50_535ea0
  esi = (esi + 1);  // @51_535ea0
  FL[3] = esi;  // @52_535ea0
  edi = (u32)(edi + 9);  // @53_535ea0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20821), sizeof v); (u32)v; });  // @54_535ea0
  if ((s32)FL[0] < (s32)FL[1]) goto L535f52;  // @55_535ea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @56_535ea0
  L535f95:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @58_535ea0
  FL[2] = (edi & edi);  // @59_535ea0
  if (FL[2] == 0) goto L535fb0;  // @60_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @61_535ea0
  ecx = (u32)(6801640);  // @62_535ea0
  FL[2] = (eax & eax);  // @63_535ea0
  if (FL[2] != 0) ecx = eax;  // @64_535ea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @65_535ea0
  L535fb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_535ea0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @69_535ea0
  ecx = edx = 0;  // @70_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @71_535ea0
  edx = (u32)(6801640);  // @72_535ea0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @73_535ea0
  edi = eax;  // @74_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @75_535ea0
  FL[2] = (ecx & ecx);  // @76_535ea0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @77_535ea0
  if (FL[2] != 0) edx = ecx;  // @78_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @79_535ea0
  PV[6] = (u32)(edx);  // @80_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_535ea0
  eax = vcall_cc2(*(u32 *)(eax + 20), ecx, PV[6], PV[5]);  // @82_535ea0
  ecx = edx = 0;  // @83_535ea0
  PV[7] = (u32)(eax);  // @84_535ea0
  PV[8] = (u32)(edi);  // @85_535ea0
  eax = ((u32(*)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 388)))(PV[8], (u32)(0), (u32)(7), (u32)(6955604), PV[7]);  // @86_535ea0
  ecx = edx = 0;  // @87_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_535ea0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @90_535ea0
  ecx = edx = 0;  // @91_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @92_535ea0
  PV[9] = (u32)(eax);  // @93_535ea0
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[9], (u32)(0), (u32)(8), (u32)(6955656));  // @94_535ea0
  ecx = edx = 0;  // @95_535ea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @96_535ea0
  ecx = (u32)(EBP - 140);  // @97_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @98_535ea0
  PV[10] = (u32)(ecx);  // @99_535ea0
  ecx = edi;  // @100_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[10]);  // @101_535ea0
  ecx = edx = 0;  // @102_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @103_535ea0
  ecx = (u32)(EBP - 140);  // @104_535ea0
  PV[11] = (u32)(ecx);  // @105_535ea0
  ecx = edi;  // @106_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[11]);  // @107_535ea0
  ecx = edx = 0;  // @108_535ea0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @109_535ea0
  edx = eax;  // @110_535ea0
  if (FL[0] == FL[1]) goto L53624b;  // @111_535ea0
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @112_535ea0
  L536050:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_535ea0
  PV[12] = (u32)(edx);  // @115_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @116_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[12]);  // @118_535ea0
  ecx = edx = 0;  // @119_535ea0
  esi = eax;  // @120_535ea0
  FL[2] = (esi & esi);  // @121_535ea0
  if (FL[2] == 0) goto L53622e;  // @122_535ea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @123_535ea0
  ecx = ebx;  // @124_535ea0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 124), sizeof v); (u32)v; });  // @125_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[13]);  // @126_535ea0
  ecx = edx = 0;  // @127_535ea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @128_535ea0
  ecx = ebx;  // @129_535ea0
  PV[14] = (u32)(eax);  // @130_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 476)))(ecx, PV[14]);  // @131_535ea0
  ecx = edx = 0;  // @132_535ea0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; }) & (u32)(8));  // @133_535ea0
  edx = eax;  // @134_535ea0
  if (FL[2] == 0) goto L53609c;  // @135_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6955784), sizeof v); (u32)v; });  // @136_535ea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @137_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6955788), sizeof v); (u32)v; });  // @138_535ea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @139_535ea0
  goto L5360ac;  // @140_535ea0
  L53609c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6955792), sizeof v); (u32)v; });  // @142_535ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @143_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6955796), sizeof v); (u32)v; });  // @144_535ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @145_535ea0
  L5360ac:;
  FL[2] = (edx & edx);  // @147_535ea0
  if (FL[2] == 0) goto L53622e;  // @148_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21250), sizeof v); (u32)v; });  // @149_535ea0
  edi = (u32)(EBP - 16);  // @150_535ea0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }));  // @151_535ea0
  FL[3] = eax;  // @152_535ea0
  ecx = (u32)(6781786);  // @153_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6955800) + 0), 4); v; });  // @154_535ea0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6955800) + 4), 4); v; });  // @155_535ea0
  X0[2] = 0;  // @156_535ea0
  X0[3] = 0;  // @157_535ea0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @158_535ea0
  if (FL[3] != 0) ecx = eax;  // @159_535ea0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @160_535ea0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @161_535ea0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6955808), sizeof v); (u32)v; })) & 0xffff);  // @162_535ea0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @163_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @164_535ea0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @165_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @166_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @168_535ea0
  ecx = edx = 0;  // @169_535ea0
  FL[2] = (eax & eax);  // @170_535ea0
  if (FL[2] == 0) goto L53610e;  // @171_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @172_535ea0
  eax = ext_4db3b0_thiscall1(ecx);  // @173_535ea0
  ecx = edx = 0;  // @174_535ea0
  edi = (u32)(6801640);  // @175_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @176_535ea0
  FL[2] = (eax & eax);  // @177_535ea0
  if (FL[2] != 0) edi = eax;  // @178_535ea0
  L53610e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 136) + 0), 4); v; });  // @180_535ea0
  X0[1] = 0;  // @181_535ea0
  X0[2] = 0;  // @182_535ea0
  X0[3] = 0;  // @183_535ea0
  X1[0] = 0;  // @184_535ea0
  X1[1] = 0;  // @185_535ea0
  X1[2] = 0;  // @186_535ea0
  X1[3] = 0;  // @187_535ea0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 132) + 0), 4); v; })));  // @188_535ea0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @189_535ea0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @190_535ea0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @191_535ea0
  if (!__builtin_parity(FL[2] & 0xff)) goto L53613b;  // @192_535ea0
  { u32 v = (u32)((u32)(4294967196)); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @193_535ea0
  goto L536152;  // @194_535ea0
  L53613b:;
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @196_535ea0
  { double in_ = U2D(X0[0], X0[1]), out_; __asm__ volatile("movsd %1, %%xmm0\n\tcall *%2\n\tmovsd %%xmm0, %0" : "=m"(out_) : "m"(in_), "r"(0x634dd6u) : "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "eax", "ecx", "edx", "memory", "cc"); SD(&X0[0], out_); }  // @197_535ea0
    // @198_535ea0
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896976) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896976) + 4), 4); v; })));  // @199_535ea0
  { double f_ = U2D(X0[0], X0[1]); s32 r_; __asm__("cvttsd2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @200_535ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @201_535ea0
  L536152:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @203_535ea0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @204_535ea0
  if (FL[0] == FL[1]) goto L536165;  // @205_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; });  // @206_535ea0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @207_535ea0
  L536165:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 212) + 0), 4); v; });  // @209_535ea0
  X0[1] = 0;  // @210_535ea0
  X0[2] = 0;  // @211_535ea0
  X0[3] = 0;  // @212_535ea0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @213_535ea0
  __builtin_memcpy((void *)((u32)(EBP - 124) + 0), &X0[0], 4);  // @214_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 216) + 0), 4); v; });  // @215_535ea0
  X0[1] = 0;  // @216_535ea0
  X0[2] = 0;  // @217_535ea0
  X0[3] = 0;  // @218_535ea0
  __builtin_memcpy((void *)((u32)(EBP - 120) + 0), &X0[0], 4);  // @219_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @220_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 220) + 0), 4); v; });  // @221_535ea0
  X0[1] = 0;  // @222_535ea0
  X0[2] = 0;  // @223_535ea0
  X0[3] = 0;  // @224_535ea0
  __builtin_memcpy((void *)((u32)(EBP - 116) + 0), &X0[0], 4);  // @225_535ea0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @226_535ea0
  ecx = edx = 0;  // @227_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; });  // @228_535ea0
  X0[1] = 0;  // @229_535ea0
  X0[2] = 0;  // @230_535ea0
  X0[3] = 0;  // @231_535ea0
  ecx = eax;  // @232_535ea0
  PV[16] = (u32)(edi);  // @233_535ea0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @234_535ea0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @235_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @236_535ea0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @237_535ea0
  PV[18] = X0[0]; PV[19] = X0[1];  // @238_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; });  // @239_535ea0
  X0[1] = 0;  // @240_535ea0
  X0[2] = 0;  // @241_535ea0
  X0[3] = 0;  // @242_535ea0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @243_535ea0
  PV[20] = X0[0]; PV[21] = X0[1];  // @244_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @245_535ea0
  X0[1] = 0;  // @246_535ea0
  X0[2] = 0;  // @247_535ea0
  X0[3] = 0;  // @248_535ea0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @249_535ea0
  PV[22] = X0[0]; PV[23] = X0[1];  // @250_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 112) + 0), 4); v; });  // @251_535ea0
  X0[1] = 0;  // @252_535ea0
  X0[2] = 0;  // @253_535ea0
  X0[3] = 0;  // @254_535ea0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @255_535ea0
  PV[24] = X0[0]; PV[25] = X0[1];  // @256_535ea0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 84) + 0), 4); v; });  // @257_535ea0
  X0[1] = 0;  // @258_535ea0
  X0[2] = 0;  // @259_535ea0
  X0[3] = 0;  // @260_535ea0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @261_535ea0
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @262_535ea0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @263_535ea0
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; });  // @264_535ea0
  PV[28] = X0[0]; PV[29] = X0[1];  // @265_535ea0
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @266_535ea0
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax*4 - 52), sizeof v); (u32)v; });  // @267_535ea0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @268_535ea0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @269_535ea0
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + eax*4 - 100), sizeof v); (u32)v; });  // @270_535ea0
  eax = (u32)(EBP - 36);  // @271_535ea0
  PV[33] = (u32)(eax);  // @272_535ea0
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @273_535ea0
  PV[35] = (u32)(esi);  // @274_535ea0
  PV[36] = (u32)(ecx);  // @275_535ea0
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[36], (u32)(0), PV[35], (u32)(6955816), PV[34], PV[33], PV[32], PV[31], PV[30], PV[28], PV[29], PV[27], PV[26], PV[24], PV[25], PV[22], PV[23], PV[20], PV[21], PV[18], PV[19], PV[17], PV[16]);  // @276_535ea0
  ecx = edx = 0;  // @277_535ea0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @278_535ea0
  esi = (esi + 1);  // @279_535ea0
  FL[3] = esi;  // @280_535ea0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @281_535ea0
  L53622e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @283_535ea0
  ecx = (u32)(EBP - 140);  // @284_535ea0
  PV[37] = (u32)(ecx);  // @285_535ea0
  ecx = edi;  // @286_535ea0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[37]);  // @287_535ea0
  ecx = edx = 0;  // @288_535ea0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @289_535ea0
  edx = eax;  // @290_535ea0
  if (FL[0] != FL[1]) goto L536050;  // @291_535ea0
  L53624b:;
  ext_633654(G(u32, 0x6f5630));  // @293_535ea0
  return eax;  // @294_535ea0
}
PCREG(535ea0, lifted_535ea0);

