// batch230005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_457680_fastcall3(u32, u32, u32) __asm__("ext_457680");
extern "C" u32 FASTCALL ext_47ad60_fastcall4(u32, u32, u32, u32) __asm__("ext_47ad60");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 THISCALL ext_41e680_thiscall1(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_477740_thiscall3(u32, u32, u32) __asm__("ext_477740");
extern "C" u32 THISCALL ext_47aad0_thiscall3(u32, u32, u32) __asm__("ext_47aad0");
extern "C" u32 THISCALL ext_487440_thiscall2(u32, u32) __asm__("ext_487440");
extern "C" u32 THISCALL ext_487550_thiscall2(u32, u32) __asm__("ext_487550");
extern "C" u32 THISCALL ext_4d95f0_thiscall3(u32, u32, u32) __asm__("ext_4d95f0");
extern "C" u32 THISCALL ext_4dc1e0_thiscall2(u32, u32) __asm__("ext_4dc1e0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_585a10_thiscall1(u32) __asm__("ext_585a10");
extern "C" u32 THISCALL ext_5f48c0_thiscall4(u32, u32, u32, u32) __asm__("ext_5f48c0");
extern "C" u32 THISCALL ext_5f5620_thiscall2(u32, u32) __asm__("ext_5f5620");
extern "C" u32 THISCALL ext_5f9130_thiscall3(u32, u32, u32) __asm__("ext_5f9130");
extern "C" u32 THISCALL ext_5ff960_thiscall2(u32, u32) __asm__("ext_5ff960");
extern "C" u32 THISCALL ext_5ffa20_thiscall4(u32, u32, u32, u32) __asm__("ext_5ffa20");
extern "C" u32 THISCALL ext_600810_thiscall1(u32) __asm__("ext_600810");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5f4680(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5f4680
  edi = ecx;  // @1_5f4680
  ecx = (u32)(EBP - 8);  // @2_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_5f4680
  PV[0] = (u32)(ecx);  // @4_5f4680
  ecx = ebx;  // @5_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[0]);  // @6_5f4680
  ecx = edx = 0;  // @7_5f4680
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @8_5f4680
  X0[1] = 0;  // @9_5f4680
  X0[2] = 0;  // @10_5f4680
  X0[3] = 0;  // @11_5f4680
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @12_5f4680
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6959448) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @13_5f4680
  if (__builtin_parity(FL[2] & 0xff)) goto L5f46b9;  // @14_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_5f4680
  FL[2] = (eax & eax);  // @16_5f4680
  if (FL[2] == 0) goto L5f46b8;  // @17_5f4680
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_5f4680
  ecx = edx = 0;  // @19_5f4680
  goto L5f46b9;  // @20_5f4680
  L5f46b8:;
  __builtin_trap();  // @22_5f4680
  L5f46b9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @24_5f4680
  PV[1] = (u32)(ebx);  // @25_5f4680
  eax = ext_5ff960_thiscall2(ecx, PV[1]);  // @26_5f4680
  ecx = edx = 0;  // @27_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @28_5f4680
  ecx = (u32)(EBP - 12);  // @29_5f4680
  PV[2] = (u32)(ecx);  // @30_5f4680
  ecx = ebx;  // @31_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @32_5f4680
  ecx = edx = 0;  // @33_5f4680
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @34_5f4680
  ecx = edi;  // @35_5f4680
  eax = ext_5f9130_thiscall3(ecx, PV[3], (u32)(0));  // @36_5f4680
  ecx = edx = 0;  // @37_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_5f4680
  ecx = (u32)(EBP - 16);  // @39_5f4680
  PV[4] = (u32)(ecx);  // @40_5f4680
  ecx = ebx;  // @41_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @42_5f4680
  ecx = edx = 0;  // @43_5f4680
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @44_5f4680
  ecx = edi;  // @45_5f4680
  eax = ext_5f5620_thiscall2(ecx, PV[5]);  // @46_5f4680
  ecx = edx = 0;  // @47_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 166), &v, sizeof v); }  // @48_5f4680
  ecx = ebx;  // @49_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_5f4680
  eax = (u32)(edi + 170);  // @51_5f4680
  PV[6] = (u32)(eax);  // @52_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[6]);  // @53_5f4680
  ecx = edx = 0;  // @54_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_5f4680
  eax = (u32)(edi + 172);  // @56_5f4680
  PV[7] = (u32)(eax);  // @57_5f4680
  ecx = ebx;  // @58_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[7]);  // @59_5f4680
  ecx = edx = 0;  // @60_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @61_5f4680
  ecx = (u32)(EBP - 16);  // @62_5f4680
  PV[8] = (u32)(ecx);  // @63_5f4680
  ecx = ebx;  // @64_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @65_5f4680
  ecx = edx = 0;  // @66_5f4680
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @67_5f4680
  ecx = edi;  // @68_5f4680
  eax = ext_5f5620_thiscall2(ecx, PV[9]);  // @69_5f4680
  ecx = edx = 0;  // @70_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 174), &v, sizeof v); }  // @71_5f4680
  ecx = ebx;  // @72_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @73_5f4680
  eax = (u32)(edi + 178);  // @74_5f4680
  PV[10] = (u32)(eax);  // @75_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[10]);  // @76_5f4680
  ecx = edx = 0;  // @77_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @78_5f4680
  eax = (u32)(edi + 180);  // @79_5f4680
  PV[11] = (u32)(eax);  // @80_5f4680
  ecx = ebx;  // @81_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, PV[11]);  // @82_5f4680
  ecx = edx = 0;  // @83_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @84_5f4680
  eax = (u32)(edi + 8);  // @85_5f4680
  PV[12] = (u32)(eax);  // @86_5f4680
  ecx = ebx;  // @87_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[12]);  // @88_5f4680
  ecx = edx = 0;  // @89_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_5f4680
  eax = (u32)(edi + 10);  // @91_5f4680
  PV[13] = (u32)(eax);  // @92_5f4680
  ecx = ebx;  // @93_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 100)))(ecx, PV[13]);  // @94_5f4680
  ecx = edx = 0;  // @95_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_5f4680
  eax = (u32)(edi + 14);  // @97_5f4680
  PV[14] = (u32)(eax);  // @98_5f4680
  ecx = ebx;  // @99_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[14]);  // @100_5f4680
  ecx = edx = 0;  // @101_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_5f4680
  ecx = (u32)(EBP + 8);  // @103_5f4680
  PV[15] = (u32)(ecx);  // @104_5f4680
  ecx = ebx;  // @105_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[15]);  // @106_5f4680
  ecx = edx = 0;  // @107_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @108_5f4680
  FL[2] = (eax & eax);  // @109_5f4680
  if (FL[2] == 0) goto L5f478a;  // @110_5f4680
  PV[16] = (u32)(eax);  // @111_5f4680
  ecx = edi;  // @112_5f4680
  eax = ext_5f5620_thiscall2(ecx, PV[16]);  // @113_5f4680
  ecx = edx = 0;  // @114_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @115_5f4680
  goto L5f4791;  // @116_5f4680
  L5f478a:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 22), &v, sizeof v); }  // @118_5f4680
  L5f4791:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @120_5f4680
  eax = (u32)(edi + 36);  // @121_5f4680
  PV[17] = (u32)(eax);  // @122_5f4680
  ecx = ebx;  // @123_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 92)))(ecx, PV[17]);  // @124_5f4680
  ecx = edx = 0;  // @125_5f4680
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @126_5f4680
  eax = (u32)(edi + 40);  // @127_5f4680
  PV[18] = (u32)(eax);  // @128_5f4680
  PV[19] = (u32)(esi);  // @129_5f4680
  PV[20] = (u32)(ebx);  // @130_5f4680
  ecx = edi;  // @131_5f4680
  eax = ext_5f48c0_thiscall4(ecx, PV[20], PV[19], PV[18]);  // @132_5f4680
  ecx = edx = 0;  // @133_5f4680
  eax = (u32)(edi + 52);  // @134_5f4680
  ecx = edi;  // @135_5f4680
  PV[21] = (u32)(eax);  // @136_5f4680
  PV[22] = (u32)(esi);  // @137_5f4680
  PV[23] = (u32)(ebx);  // @138_5f4680
  eax = ext_5f48c0_thiscall4(ecx, PV[23], PV[22], PV[21]);  // @139_5f4680
  ecx = edx = 0;  // @140_5f4680
  eax = (u32)(edi + 64);  // @141_5f4680
  ecx = edi;  // @142_5f4680
  PV[24] = (u32)(eax);  // @143_5f4680
  PV[25] = (u32)(esi);  // @144_5f4680
  PV[26] = (u32)(ebx);  // @145_5f4680
  eax = ext_5f48c0_thiscall4(ecx, PV[26], PV[25], PV[24]);  // @146_5f4680
  ecx = edx = 0;  // @147_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @148_5f4680
  ecx = (u32)(EBP - 4);  // @149_5f4680
  PV[27] = (u32)(ecx);  // @150_5f4680
  ecx = ebx;  // @151_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[27]);  // @152_5f4680
  ecx = edx = 0;  // @153_5f4680
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @154_5f4680
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @155_5f4680
  if (FL[0] <= FL[1]) goto L5f485c;  // @156_5f4680
  L5f47e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @158_5f4680
  ecx = edi;  // @159_5f4680
  PV[28] = (u32)(esi);  // @160_5f4680
  PV[29] = (u32)(ebx);  // @161_5f4680
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[29], PV[28]);  // @162_5f4680
  ecx = edx = 0;  // @163_5f4680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @164_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @165_5f4680
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }); FL[1] = ecx;  // @166_5f4680
  if (FL[0] < FL[1]) goto L5f4841;  // @167_5f4680
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @168_5f4680
  eax = (u32)(ecx + ecx);  // @169_5f4680
  ecx = 0;  // @170_5f4680
  FL[3] = ecx;  // @171_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @172_5f4680
  edx = (u32)(4);  // @173_5f4680
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @174_5f4680
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @175_5f4680
  FL[1] = ecx;  // @176_5f4680
  ecx = (0u - ecx);  // @177_5f4680
  ecx = (ecx | eax);  // @178_5f4680
  FL[3] = ecx;  // @179_5f4680
  PV[30] = (u32)(ecx);  // @180_5f4680
  eax = ext_41e290_cdecl1(PV[30]);  // @181_5f4680
  ecx = edx = 0;  // @182_5f4680
  edx = 0;  // @183_5f4680
  FL[3] = edx;  // @184_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @185_5f4680
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; }); FL[1] = edx;  // @186_5f4680
  if (FL[0] <= FL[1]) goto L5f482f;  // @187_5f4680
  L5f4820:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @189_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4), sizeof v); (u32)v; });  // @190_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edx*4), &v, sizeof v); }  // @191_5f4680
  edx = (edx + 1);  // @192_5f4680
  FL[3] = edx;  // @193_5f4680
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @194_5f4680
  if (FL[0] < FL[1]) goto L5f4820;  // @195_5f4680
  L5f482f:;
  PV[31] = (u32)(esi);  // @197_5f4680
  eax = ext_41e2c0_cdecl1(PV[31]);  // @198_5f4680
  ecx = edx = 0;  // @199_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @200_5f4680
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @201_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @202_5f4680
  L5f4841:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @204_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @205_5f4680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @206_5f4680
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @207_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @208_5f4680
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @209_5f4680
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @210_5f4680
  eax = (eax + 1);  // @211_5f4680
  FL[3] = eax;  // @212_5f4680
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @213_5f4680
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @214_5f4680
  if (FL[0] < FL[1]) goto L5f47e0;  // @215_5f4680
  L5f485c:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @217_5f4680
  if (FL[0] != FL[1]) goto L5f48b4;  // @218_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @219_5f4680
  ecx = (u32)(EBP - 20);  // @220_5f4680
  PV[32] = (u32)(ecx);  // @221_5f4680
  ecx = ebx;  // @222_5f4680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[32]);  // @223_5f4680
  ecx = edx = 0;  // @224_5f4680
  ecx = (u32)(edi + 154);  // @225_5f4680
  eax = ext_600810_thiscall1(ecx);  // @226_5f4680
  ecx = edx = 0;  // @227_5f4680
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = eax;  // @228_5f4680
  if (FL[0] == FL[1]) goto L5f488b;  // @229_5f4680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @230_5f4680
  FL[2] = (eax & eax);  // @231_5f4680
  if (FL[2] == 0) goto L5f488a;  // @232_5f4680
  eax = ((u32(STDCALL *)(void))(eax))();  // @233_5f4680
  ecx = edx = 0;  // @234_5f4680
  goto L5f488b;  // @235_5f4680
  L5f488a:;
  __builtin_trap();  // @237_5f4680
  L5f488b:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @239_5f4680
  ecx = (u32)(edi + 154);  // @240_5f4680
  eax = ext_600810_thiscall1(ecx);  // @241_5f4680
  ecx = edx = 0;  // @242_5f4680
  PV[33] = (u32)(eax);  // @243_5f4680
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 158), sizeof v); (u32)v; });  // @244_5f4680
  ecx = ebx;  // @245_5f4680
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 112)))(ecx, PV[34], PV[33]);  // @246_5f4680
  ecx = edx = 0;  // @247_5f4680
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @248_5f4680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 150), sizeof v); (u32)v; });  // @249_5f4680
  PV[36] = (u32)(edi);  // @250_5f4680
  PV[37] = (u32)(ebx);  // @251_5f4680
  eax = ext_5ffa20_thiscall4(ecx, PV[37], PV[36], PV[35]);  // @252_5f4680
  ecx = edx = 0;  // @253_5f4680
  L5f48b4:;
  return eax;  // @255_5f4680
}
PCREG(5f4680, lifted_5f4680);

extern "C" u32 THISCALL lifted_4d9970(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4d9970
  esi = ecx;  // @1_4d9970
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @2_4d9970
  FL[0] = ebx; FL[1] = (u32)(6);  // @3_4d9970
  if (FL[0] <= FL[1]) goto L4d99a9;  // @4_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @5_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_4d9970
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909476), (u32)(2258));  // @7_4d9970
  ecx = edx = 0;  // @8_4d9970
  PV[0] = (u32)(eax);  // @9_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_4d9970
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6909760));  // @11_4d9970
  ecx = edx = 0;  // @12_4d9970
  L4d99a9:;
  edx = (u32)(3);  // @14_4d9970
  X2[0] = 0;  // @15_4d9970
  X2[1] = 0;  // @16_4d9970
  X2[2] = 0;  // @17_4d9970
  X2[3] = 0;  // @18_4d9970
  FL[0] = ebx; FL[1] = edx;  // @19_4d9970
  X1[0] = X2[0];  // @20_4d9970
  X1[1] = X2[1];  // @21_4d9970
  X1[2] = X2[2];  // @22_4d9970
  X1[3] = X2[3];  // @23_4d9970
  if (FL[0] <= FL[1]) edx = ebx;  // @24_4d9970
  ecx = 0;  // @25_4d9970
  FL[3] = ecx;  // @26_4d9970
  FL[2] = (edx & edx);  // @27_4d9970
  if (FL[2] == 0) goto L4d99d9;  // @28_4d9970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @29_4d9970
  L4d99c2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + ecx*4) + 0), 4); v; });  // @31_4d9970
  X0[1] = 0;  // @32_4d9970
  X0[2] = 0;  // @33_4d9970
  X0[3] = 0;  // @34_4d9970
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @35_4d9970
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @36_4d9970
  if (__builtin_parity(FL[2] & 0xff)) goto L4d99d9;  // @37_4d9970
  ecx = (ecx + 1);  // @38_4d9970
  FL[3] = ecx;  // @39_4d9970
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @40_4d9970
  FL[0] = ecx; FL[1] = edx;  // @41_4d9970
  if (FL[0] != FL[1]) goto L4d99c2;  // @42_4d9970
  L4d99d9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @44_4d9970
  X0[1] = 0;  // @45_4d9970
  X0[2] = 0;  // @46_4d9970
  X0[3] = 0;  // @47_4d9970
  ebx = 0;  // @48_4d9970
  FL[3] = ebx;  // @49_4d9970
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @50_4d9970
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ > b_) ? X0[0] : F2U(b_); }  // @51_4d9970
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @52_4d9970
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @53_4d9970
  if (FL[2] == 0) goto L4d9a18;  // @54_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4d9970
  PV[1] = (u32)(edx);  // @56_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @57_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @58_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4d9970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @60_4d9970
  ecx = edx = 0;  // @61_4d9970
  ecx = eax;  // @62_4d9970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @63_4d9970
  FL[2] = (ecx & ecx);  // @64_4d9970
  if (FL[2] == 0) goto L4d9a1d;  // @65_4d9970
  ebx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @66_4d9970
  goto L4d9a1d;  // @67_4d9970
  L4d9a18:;
  ecx = 0;  // @69_4d9970
  FL[3] = ecx;  // @70_4d9970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @71_4d9970
  L4d9a1d:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @73_4d9970
  esi = 0;  // @74_4d9970
  FL[3] = esi;  // @75_4d9970
  FL[2] = (ebx & ebx);  // @76_4d9970
  if (FL[2] == 0) goto L4d9a63;  // @77_4d9970
  L4d9a26:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @79_4d9970
  FL[0] = esi; FL[1] = eax;  // @80_4d9970
  if (FL[0] >= FL[1]) goto L4d9a33;  // @81_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + esi*4), sizeof v); (u32)v; });  // @82_4d9970
  goto L4d9a35;  // @83_4d9970
  L4d9a33:;
  ecx = 0;  // @85_4d9970
  FL[3] = ecx;  // @86_4d9970
  L4d9a35:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @88_4d9970
  eax = 0;  // @89_4d9970
  FL[3] = eax;  // @90_4d9970
  FL[2] = (edx & edx);  // @91_4d9970
  if (FL[2] == 0) goto L4d9a50;  // @92_4d9970
  L4d9a40:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; }); FL[1] = ecx;  // @94_4d9970
  if (FL[0] == FL[1]) goto L4d9a4c;  // @95_4d9970
  eax = (eax + 1);  // @96_4d9970
  FL[3] = eax;  // @97_4d9970
  FL[0] = eax; FL[1] = edx;  // @98_4d9970
  if (FL[0] != FL[1]) goto L4d9a40;  // @99_4d9970
  goto L4d9a50;  // @100_4d9970
  L4d9a4c:;
  FL[0] = eax; FL[1] = edx;  // @102_4d9970
  if (FL[0] != FL[1]) goto L4d9a5b;  // @103_4d9970
  L4d9a50:;
  PV[2] = (u32)(ecx);  // @105_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @106_4d9970
  eax = ext_4dc1e0_thiscall2(ecx, PV[2]);  // @107_4d9970
  ecx = edx = 0;  // @108_4d9970
  esi = (esi - 1);  // @109_4d9970
  FL[3] = esi;  // @110_4d9970
  ebx = (ebx - 1);  // @111_4d9970
  FL[3] = ebx;  // @112_4d9970
  L4d9a5b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @114_4d9970
  esi = (esi + 1);  // @115_4d9970
  FL[3] = esi;  // @116_4d9970
  FL[0] = esi; FL[1] = ebx;  // @117_4d9970
  if (FL[0] != FL[1]) goto L4d9a26;  // @118_4d9970
  L4d9a63:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @120_4d9970
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @121_4d9970
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @122_4d9970
  if (FL[2] == 0) goto L4d9ac0;  // @123_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_4d9970
  PV[3] = (u32)(edx);  // @125_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @126_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @127_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_4d9970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @129_4d9970
  ecx = edx = 0;  // @130_4d9970
  FL[2] = (eax & eax);  // @131_4d9970
  if (FL[2] == 0) goto L4d9ac0;  // @132_4d9970
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @133_4d9970
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @134_4d9970
  if (FL[2] == 0) goto L4d9ab1;  // @135_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_4d9970
  PV[4] = (u32)(edx);  // @137_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @138_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @139_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_4d9970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @141_4d9970
  ecx = edx = 0;  // @142_4d9970
  ecx = (u32)(6);  // @143_4d9970
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @144_4d9970
  ecx = (ecx - eax);  // @145_4d9970
  FL[3] = ecx;  // @146_4d9970
  goto L4d9ac5;  // @147_4d9970
  L4d9ab1:;
  eax = 0;  // @149_4d9970
  FL[3] = eax;  // @150_4d9970
  ecx = (u32)(6);  // @151_4d9970
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @152_4d9970
  ecx = (ecx - eax);  // @153_4d9970
  FL[3] = ecx;  // @154_4d9970
  goto L4d9ac5;  // @155_4d9970
  L4d9ac0:;
  ecx = (u32)(6);  // @157_4d9970
  L4d9ac5:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @159_4d9970
  eax = 0;  // @160_4d9970
  FL[3] = eax;  // @161_4d9970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @162_4d9970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @163_4d9970
  FL[2] = (esi & esi);  // @164_4d9970
  if (FL[2] == 0) goto L4d9b36;  // @165_4d9970
  L4d9ad4:;
  FL[2] = (ecx & ecx);  // @167_4d9970
  if (FL[2] == 0) goto L4d9b36;  // @168_4d9970
  eax = 0;  // @169_4d9970
  FL[3] = eax;  // @170_4d9970
  FL[2] = (ebx & ebx);  // @171_4d9970
  if (FL[2] == 0) goto L4d9b09;  // @172_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @173_4d9970
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @174_4d9970
  L4d9ae5:;
  FL[0] = eax; FL[1] = edx;  // @176_4d9970
  if (FL[0] >= FL[1]) goto L4d9aee;  // @177_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4), sizeof v); (u32)v; });  // @178_4d9970
  goto L4d9af0;  // @179_4d9970
  L4d9aee:;
  ecx = 0;  // @181_4d9970
  FL[3] = ecx;  // @182_4d9970
  L4d9af0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @184_4d9970
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4), sizeof v); (u32)v; });  // @185_4d9970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @186_4d9970
  if (FL[0] == FL[1]) goto L4d9b05;  // @187_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @188_4d9970
  eax = (eax + 1);  // @189_4d9970
  FL[3] = eax;  // @190_4d9970
  FL[0] = eax; FL[1] = ebx;  // @191_4d9970
  if (FL[0] != FL[1]) goto L4d9ae5;  // @192_4d9970
  goto L4d9b09;  // @193_4d9970
  L4d9b05:;
  FL[0] = eax; FL[1] = ebx;  // @195_4d9970
  if (FL[0] != FL[1]) goto L4d9b28;  // @196_4d9970
  L4d9b09:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @198_4d9970
  PV[5] = (u32)(ecx);  // @199_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @200_4d9970
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4), sizeof v); (u32)v; });  // @201_4d9970
  eax = ext_4d95f0_thiscall3(ecx, PV[6], (u32)(0));  // @202_4d9970
  ecx = edx = 0;  // @203_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @204_4d9970
  ecx = (ecx - 1);  // @205_4d9970
  FL[3] = ecx;  // @206_4d9970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @207_4d9970
  goto L4d9b2b;  // @208_4d9970
  L4d9b28:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @210_4d9970
  L4d9b2b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @212_4d9970
  eax = (eax + 1);  // @213_4d9970
  FL[3] = eax;  // @214_4d9970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @215_4d9970
  FL[0] = eax; FL[1] = esi;  // @216_4d9970
  if (FL[0] != FL[1]) goto L4d9ad4;  // @217_4d9970
  L4d9b36:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @219_4d9970
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @220_4d9970
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @221_4d9970
  if (FL[2] == 0) goto L4d9b62;  // @222_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @223_4d9970
  PV[7] = (u32)(edx);  // @224_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @225_4d9970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @226_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_4d9970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @228_4d9970
  ecx = edx = 0;  // @229_4d9970
  esi = eax;  // @230_4d9970
  FL[2] = (esi & esi);  // @231_4d9970
  if (FL[2] == 0) goto L4d9b64;  // @232_4d9970
  ebx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @233_4d9970
  goto L4d9b64;  // @234_4d9970
  L4d9b62:;
  esi = 0;  // @236_4d9970
  FL[3] = esi;  // @237_4d9970
  L4d9b64:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @239_4d9970
  FL[3] = (eax & 0xff);  // @240_4d9970
  ecx = 0;  // @241_4d9970
  FL[3] = ecx;  // @242_4d9970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 19), &v, sizeof v); }  // @243_4d9970
  FL[2] = (ebx & ebx);  // @244_4d9970
  if (FL[2] == 0) goto L4d9be0;  // @245_4d9970
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - edi)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @246_4d9970
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @247_4d9970
  edx = esi;  // @248_4d9970
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6910104) + 0), 4); v; });  // @249_4d9970
  X1[1] = 0;  // @250_4d9970
  X1[2] = 0;  // @251_4d9970
  X1[3] = 0;  // @252_4d9970
  edx = (edx - edi);  // @253_4d9970
  FL[3] = edx;  // @254_4d9970
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @255_4d9970
  X3[1] = 0;  // @256_4d9970
  X3[2] = 0;  // @257_4d9970
  X3[3] = 0;  // @258_4d9970
  X2[0] = 0;  // @259_4d9970
  X2[1] = 0;  // @260_4d9970
  X2[2] = 0;  // @261_4d9970
  X2[3] = 0;  // @262_4d9970
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @263_4d9970
  L4d9b90:;
  X0[0] = X2[0];  // @265_4d9970
  X0[1] = X2[1];  // @266_4d9970
  X0[2] = X2[2];  // @267_4d9970
  X0[3] = X2[3];  // @268_4d9970
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @269_4d9970
  if (FL[2] != 0) goto L4d9bb7;  // @270_4d9970
  FL[0] = ecx; FL[1] = (u32)(3);  // @271_4d9970
  if (FL[0] >= FL[1]) goto L4d9bb7;  // @272_4d9970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @273_4d9970
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi) + 0), 4); v; });  // @274_4d9970
  X0[1] = 0;  // @275_4d9970
  X0[2] = 0;  // @276_4d9970
  X0[3] = 0;  // @277_4d9970
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) << 8);  // @278_4d9970
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X2[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X2[0]) != U2F(X2[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))) ? 0x40 : 0)) & 68);  // @279_4d9970
  if (!__builtin_parity(FL[2] & 0xff)) goto L4d9bb3;  // @280_4d9970
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 19), &v, sizeof v); }  // @281_4d9970
  goto L4d9bb7;  // @282_4d9970
  L4d9bb3:;
  X0[0] = F2U(U2F(X0[0]) / U2F(X3[0]));  // @284_4d9970
  L4d9bb7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @286_4d9970
  FL[0] = ecx; FL[1] = (u32)(6);  // @287_4d9970
  if (FL[0] >= FL[1]) goto L4d9bd5;  // @288_4d9970
  FL[0] = ecx; FL[1] = (u32)(3);  // @289_4d9970
  if (FL[0] >= FL[1]) goto L4d9bcf;  // @290_4d9970
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @291_4d9970
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @292_4d9970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + ecx + 29), &v, sizeof v); }  // @293_4d9970
  L4d9bcf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @295_4d9970
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + edi), &v, sizeof v); }  // @296_4d9970
  L4d9bd5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 19), sizeof v); (u32)v; })) & 0xff);  // @298_4d9970
  ecx = (ecx + 1);  // @299_4d9970
  FL[3] = ecx;  // @300_4d9970
  edi = (edi + (u32)(4));  // @301_4d9970
  FL[3] = edi;  // @302_4d9970
  FL[0] = ecx; FL[1] = ebx;  // @303_4d9970
  if (FL[0] != FL[1]) goto L4d9b90;  // @304_4d9970
  L4d9be0:;
  return eax;  // @306_4d9970
}
PCREG(4d9970, lifted_4d9970);





