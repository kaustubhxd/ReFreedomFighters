// batch230007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_47ad60_fastcall4(u32, u32, u32, u32) __asm__("ext_47ad60");
extern "C" u32 THISCALL ext_41e680_thiscall1(u32) __asm__("ext_41e680");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_477740_thiscall3(u32, u32, u32) __asm__("ext_477740");
extern "C" u32 THISCALL ext_47aad0_thiscall3(u32, u32, u32) __asm__("ext_47aad0");
extern "C" u32 THISCALL ext_487440_thiscall2(u32, u32) __asm__("ext_487440");
extern "C" u32 THISCALL ext_487550_thiscall2(u32, u32) __asm__("ext_487550");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_585a10_thiscall1(u32) __asm__("ext_585a10");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_47c690(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_47c690
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1734), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_47c690
  if (FL[0] == FL[1]) goto L47c736;  // @2_47c690
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1738) + 0), 4); v; });  // @3_47c690
  X1[1] = 0;  // @4_47c690
  X1[2] = 0;  // @5_47c690
  X1[3] = 0;  // @6_47c690
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1826) + 0), 4); v; })));  // @7_47c690
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @8_47c690
  X0[1] = 0;  // @9_47c690
  X0[2] = 0;  // @10_47c690
  X0[3] = 0;  // @11_47c690
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47c736;  // @12_47c690
  PV[0] = (u32)(ebx);  // @13_47c690
  ecx = (u32)(EBP - 16);  // @14_47c690
  eax = ext_487440_thiscall2(ecx, PV[0]);  // @15_47c690
  ecx = edx = 0;  // @16_47c690
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1840), sizeof v); (u32)v; })) & 0xff);  // @17_47c690
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @18_47c690
  if (FL[2] == 0) goto L47c7c0;  // @19_47c690
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 6), &v, sizeof v); }  // @20_47c690
  L47c6de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1734), sizeof v); (u32)v; });  // @22_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_47c690
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @24_47c690
  ecx = edx = 0;  // @25_47c690
  FL[0] = eax; FL[1] = (u32)(1);  // @26_47c690
  if (FL[0] != FL[1]) goto L47c71d;  // @27_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1734), sizeof v); (u32)v; });  // @28_47c690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_47c690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @30_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_47c690
  PV[1] = (u32)(edx);  // @32_47c690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_47c690
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1], (u32)(0));  // @35_47c690
  ecx = edx = 0;  // @36_47c690
  PV[2] = (u32)(eax);  // @37_47c690
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338552), sizeof v); (u32)v; });  // @38_47c690
  ecx = ebx;  // @39_47c690
  PV[3] = (u32)(eax);  // @40_47c690
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 296)))(ecx, PV[3], PV[2]);  // @41_47c690
  ecx = edx = 0;  // @42_47c690
  L47c71d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1734), sizeof v); (u32)v; });  // @44_47c690
  edx = (u32)(EBP - 16);  // @45_47c690
  PV[4] = (u32)(edx);  // @46_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_47c690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[4]);  // @48_47c690
  ecx = edx = 0;  // @49_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_47c690
  ecx = ebx;  // @51_47c690
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1524)))(ecx);  // @52_47c690
  ecx = edx = 0;  // @53_47c690
  L47c736:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1746), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @55_47c690
  if (FL[0] == FL[1]) goto L47ca16;  // @56_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1612), sizeof v); (u32)v; });  // @57_47c690
  FL[0] = eax; FL[1] = (u32)(11);  // @58_47c690
  if (FL[0] == FL[1]) goto L47c774;  // @59_47c690
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1826) + 0), 4); v; });  // @60_47c690
  X0[1] = 0;  // @61_47c690
  X0[2] = 0;  // @62_47c690
  X0[3] = 0;  // @63_47c690
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @64_47c690
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1750) + 0), 4); v; });  // @65_47c690
  X1[1] = 0;  // @66_47c690
  X1[2] = 0;  // @67_47c690
  X1[3] = 0;  // @68_47c690
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @69_47c690
  X0[0] = 0;  // @70_47c690
  X0[1] = 0;  // @71_47c690
  X0[2] = 0;  // @72_47c690
  X0[3] = 0;  // @73_47c690
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47ca16;  // @74_47c690
  L47c774:;
  FL[0] = eax; FL[1] = (u32)(10);  // @76_47c690
  if (FL[0] == FL[1]) goto L47ca16;  // @77_47c690
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1685), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @78_47c690
  if (FL[0] == FL[1]) goto L47ca16;  // @79_47c690
  PV[5] = (u32)(ebx);  // @80_47c690
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1742), sizeof v); (u32)v; });  // @81_47c690
  ecx = (u32)(7338432);  // @82_47c690
  eax = ext_47ad60_fastcall4(ecx, edx, PV[6], PV[5]);  // @83_47c690
  ecx = edx = 0;  // @84_47c690
  ecx = ebx;  // @85_47c690
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @86_47c690
  if (FL[2] != 0) goto L47c850;  // @87_47c690
  eax = ext_477740_thiscall3(ecx, (u32)(1), (u32)(0));  // @88_47c690
  ecx = edx = 0;  // @89_47c690
  { u32 v = (u32)((u32)(11)); __builtin_memcpy((void *)(u32)(ebx + 1612), &v, sizeof v); }  // @90_47c690
  return eax;  // @91_47c690
  L47c7c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1841), sizeof v); (u32)v; })) & 0xff);  // @93_47c690
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @94_47c690
  if (FL[2] == 0) goto L47c7d2;  // @95_47c690
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 5), &v, sizeof v); }  // @96_47c690
  goto L47c6de;  // @97_47c690
  L47c7d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1734), sizeof v); (u32)v; });  // @99_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_47c690
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @101_47c690
  ecx = edx = 0;  // @102_47c690
  FL[0] = eax; FL[1] = (u32)(1);  // @103_47c690
  if (FL[0] != FL[1]) goto L47c6de;  // @104_47c690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1734), sizeof v); (u32)v; });  // @105_47c690
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @106_47c690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @107_47c690
  FL[2] = (ecx & ecx);  // @108_47c690
  if (FL[2] == 0) goto L47c81a;  // @109_47c690
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_47c690
  eax = (u32)(EBP - 4);  // @111_47c690
  PV[7] = (u32)(eax);  // @112_47c690
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7338556), sizeof v); (u32)v; });  // @113_47c690
  PV[8] = (u32)(eax);  // @114_47c690
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[8], PV[7], (u32)(0));  // @115_47c690
  ecx = edx = 0;  // @116_47c690
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @117_47c690
  if (FL[0] != FL[1]) goto L47c6de;  // @118_47c690
  L47c81a:;
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @120_47c690
  ecx = (u32)(EBP - 16);  // @121_47c690
  eax = ext_487550_thiscall2(ecx, PV[9]);  // @122_47c690
  ecx = edx = 0;  // @123_47c690
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @124_47c690
  if (FL[2] != 0) goto L47c6de;  // @125_47c690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @126_47c690
  eax = ext_41e680_thiscall1(ecx);  // @127_47c690
  ecx = edx = 0;  // @128_47c690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 1842), &v, sizeof v); }  // @129_47c690
  ecx = ebx;  // @130_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @131_47c690
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1576)))(ecx, (u32)(3), (u32)(0), (u32)(0));  // @132_47c690
  ecx = edx = 0;  // @133_47c690
  goto L47c736;  // @134_47c690
  L47c850:;
  edi = (u32)(ebx + 1754);  // @136_47c690
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @137_47c690
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @138_47c690
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @139_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @140_47c690
  PV[10] = (u32)(edi);  // @141_47c690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[10]);  // @142_47c690
  ecx = edx = 0;  // @143_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1685), sizeof v); (u32)v; });  // @144_47c690
  esi = (u32)(ebx + 1766);  // @145_47c690
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1746), sizeof v); (u32)v; });  // @146_47c690
  edx = (edx + edx);  // @147_47c690
  FL[3] = edx;  // @148_47c690
  PV[11] = (u32)(edi);  // @149_47c690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @150_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*8 + 20), sizeof v); (u32)v; });  // @151_47c690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @152_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*8 + 24), sizeof v); (u32)v; });  // @153_47c690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @154_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*8 + 28), sizeof v); (u32)v; });  // @155_47c690
  ecx = (u32)(ebx + 1778);  // @156_47c690
  edx = esi;  // @157_47c690
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @158_47c690
  eax = ext_43e920_fastcall3(ecx, edx, PV[11]);  // @159_47c690
  ecx = edx = 0;  // @160_47c690
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @161_47c690
  X0[1] = 0;  // @162_47c690
  X0[2] = 0;  // @163_47c690
  X0[3] = 0;  // @164_47c690
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @165_47c690
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @166_47c690
  if (__builtin_parity(FL[2] & 0xff)) goto L47c900;  // @167_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @168_47c690
  edx = (u32)(ebx + 1766);  // @169_47c690
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1854), sizeof v); (u32)v; });  // @170_47c690
  PV[12] = (u32)(edx);  // @171_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @172_47c690
  edx = (u32)(ebx + 1754);  // @173_47c690
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_47c690
  PV[13] = (u32)(edx);  // @175_47c690
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @176_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_47c690
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[13], PV[12], (u32)(-1));  // @178_47c690
  ecx = edx = 0;  // @179_47c690
  PV[14] = (u32)(eax);  // @180_47c690
  ecx = esi;  // @181_47c690
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 4)))(ecx, PV[14]);  // @182_47c690
  ecx = edx = 0;  // @183_47c690
  esi = (u32)(ebx + 1766);  // @184_47c690
  L47c900:;
  ecx = (u32)(ebx + 1778);  // @186_47c690
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1782), &v, sizeof v); }  // @187_47c690
  eax = ext_44c840_thiscall1(ecx);  // @188_47c690
  ecx = 0;  // @189_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @190_47c690
  ecx = ebx;  // @191_47c690
  PV[15] = (u32)(esi);  // @192_47c690
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @193_47c690
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1568)))(ecx, PV[15], (u32)(1), (u32)(0));  // @194_47c690
  ecx = edx = 0;  // @195_47c690
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1748), sizeof v); (u32)v; });  // @196_47c690
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1770) + 0), 4); v; });  // @197_47c690
  X1[1] = 0;  // @198_47c690
  X1[2] = 0;  // @199_47c690
  X1[3] = 0;  // @200_47c690
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1758) + 0), 4); v; })));  // @201_47c690
  FL[0] = eax; FL[1] = (u32)(3);  // @202_47c690
  if (FL[0] != FL[1]) goto L47c94a;  // @203_47c690
  eax = (u32)(26);  // @204_47c690
  goto L47c9ac;  // @205_47c690
  L47c94a:;
  FL[0] = eax; FL[1] = (u32)(4);  // @207_47c690
  if (FL[0] == FL[1]) goto L47ca05;  // @208_47c690
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))))) goto L47c981;  // @209_47c690
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; }))))))) goto L47c96c;  // @210_47c690
  eax = (u32)(24);  // @211_47c690
  goto L47c9ac;  // @212_47c690
  L47c96c:;
  eax = 0;  // @214_47c690
  FL[3] = eax;  // @215_47c690
  eax = (eax & 0xffffff00u) | (((((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860560) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860560) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860560) + 0), 4); v; }))))))) ? 1 : 0)) & 0xff);  // @216_47c690
  eax = (u32)(eax*2 + 20);  // @217_47c690
  goto L47c9ac;  // @218_47c690
  L47c981:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6855972) + 0), 4); v; });  // @220_47c690
  X0[1] = 0;  // @221_47c690
  X0[2] = 0;  // @222_47c690
  X0[3] = 0;  // @223_47c690
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47c995;  // @224_47c690
  eax = (u32)(25);  // @225_47c690
  goto L47c9ac;  // @226_47c690
  L47c995:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860596) + 0), 4); v; });  // @228_47c690
  X0[1] = 0;  // @229_47c690
  X0[2] = 0;  // @230_47c690
  X0[3] = 0;  // @231_47c690
  eax = 0;  // @232_47c690
  FL[3] = eax;  // @233_47c690
  eax = (eax & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @234_47c690
  eax = (u32)(eax*2 + 21);  // @235_47c690
  L47c9ac:;
  PV[16] = (u32)(eax);  // @237_47c690
  ecx = ebx;  // @238_47c690
  eax = ext_477740_thiscall3(ecx, PV[16], (u32)(0));  // @239_47c690
  ecx = edx = 0;  // @240_47c690
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @241_47c690
  if (FL[2] == 0) goto L47ca05;  // @242_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1685), sizeof v); (u32)v; });  // @243_47c690
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1746), sizeof v); (u32)v; });  // @244_47c690
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 1826) + 0), 4); v; });  // @245_47c690
  X0[1] = 0;  // @246_47c690
  X0[2] = 0;  // @247_47c690
  X0[3] = 0;  // @248_47c690
  ecx = (ecx + 1);  // @249_47c690
  FL[3] = ecx;  // @250_47c690
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(ebx + 1612), &v, sizeof v); }  // @251_47c690
  ecx = (ecx + ecx);  // @252_47c690
  FL[3] = ecx;  // @253_47c690
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @254_47c690
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx*8) + 0), 4); v; });  // @255_47c690
  X1[1] = 0;  // @256_47c690
  X1[2] = 0;  // @257_47c690
  X1[3] = 0;  // @258_47c690
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @259_47c690
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))))) goto L47ca16;  // @260_47c690
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @261_47c690
  __builtin_memcpy((void *)((u32)(ebx + 1826) + 0), &X0[0], 4);  // @262_47c690
  return eax;  // @263_47c690
  L47ca05:;
  PV[17] = (u32)(ebx);  // @265_47c690
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1742), sizeof v); (u32)v; });  // @266_47c690
  ecx = (u32)(7338432);  // @267_47c690
  eax = ext_47aad0_thiscall3(ecx, PV[18], PV[17]);  // @268_47c690
  ecx = edx = 0;  // @269_47c690
  L47ca16:;
  return eax;  // @271_47c690
}
PCREG(47c690, lifted_47c690);

extern "C" u32 STDCALL lifted_588180(u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7422608) + 0), 4); v; });  // @0_588180
  X1[1] = 0;  // @1_588180
  X1[2] = 0;  // @2_588180
  X1[3] = 0;  // @3_588180
  X0[0] = 0;  // @4_588180
  X0[1] = 0;  // @5_588180
  X0[2] = 0;  // @6_588180
  X0[3] = 0;  // @7_588180
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_588180
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))) ? 0x40 : 0)) << 8);  // @9_588180
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))) ? 0x40 : 0)) & 68);  // @10_588180
  if (!__builtin_parity(FL[2] & 0xff)) goto L588240;  // @11_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @12_588180
  FL[2] = (edx & edx);  // @13_588180
  if (FL[2] == 0) goto L5881db;  // @14_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_588180
  PV[0] = (u32)(edx);  // @16_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @17_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @18_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[0]);  // @20_588180
  ecx = edx = 0;  // @21_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @22_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @23_588180
  L5881db:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @25_588180
  FL[2] = (edx & edx);  // @26_588180
  if (FL[2] == 0) goto L588203;  // @27_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_588180
  PV[1] = (u32)(edx);  // @29_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @31_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[1]);  // @33_588180
  ecx = edx = 0;  // @34_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @35_588180
  L588203:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @37_588180
  FL[2] = (edx & edx);  // @38_588180
  if (FL[2] == 0) goto L58851f;  // @39_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_588180
  PV[2] = (u32)(edx);  // @41_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @43_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[2]);  // @45_588180
  ecx = edx = 0;  // @46_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @47_588180
  ext_633654(G(u32, 0x6f5630));  // @48_588180
  return eax;  // @49_588180
  L588240:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @51_588180
  eax = (u32)(16711680);  // @52_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @53_588180
  edi = (u32)(65280);  // @54_588180
  if (FL[0] != FL[1]) edi = eax;  // @55_588180
  FL[2] = (edx & edx);  // @56_588180
  if (FL[2] == 0) goto L58827f;  // @57_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_588180
  PV[3] = (u32)(edx);  // @59_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @62_588180
  ecx = edx = 0;  // @63_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @64_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @65_588180
  eax = (eax >> (u32)(10));  // @66_588180
  FL[3] = eax;  // @67_588180
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @68_588180
  FL[2] = ((eax & 0xff) & (u32)(1));  // @69_588180
  eax = (u32)(255);  // @70_588180
  if (FL[2] == 0) edi = eax;  // @71_588180
  L58827f:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @73_588180
  FL[2] = (edx & edx);  // @74_588180
  if (FL[2] == 0) goto L58839a;  // @75_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @77_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @78_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @79_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @80_588180
  PV[4] = (u32)(edx);  // @81_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @83_588180
  ecx = edx = 0;  // @84_588180
  FL[2] = (eax & eax);  // @85_588180
  if (FL[2] == 0) goto L5882d6;  // @86_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @87_588180
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @88_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @89_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @91_588180
  ecx = edx = 0;  // @92_588180
  ecx = (u32)(EBP - 16);  // @93_588180
  PV[6] = (u32)(ecx);  // @94_588180
  ecx = eax;  // @95_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @96_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[6]);  // @97_588180
  ecx = edx = 0;  // @98_588180
  L5882d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_588180
  ebx = (u32)(esi + 16);  // @101_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @102_588180
  FL[2] = (edx & edx);  // @103_588180
  edx = (u32)(EBP - 16);  // @104_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @105_588180
  PV[7] = (u32)(edx);  // @106_588180
  PV[8] = (u32)(ebx);  // @107_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @108_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_588180
  if (FL[2] != 0) goto L588308;  // @110_588180
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[8], PV[7], (u32)(16776960));  // @111_588180
  ecx = edx = 0;  // @112_588180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @113_588180
  goto L588312;  // @114_588180
  L588308:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @116_588180
  PV[9] = (u32)(edx);  // @117_588180
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[9], PV[8], PV[7], (u32)(16776960));  // w3e: the pushes before the branch are args of this call too  // @118_588180
  ecx = edx = 0;  // @119_588180
  L588312:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @121_588180
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @122_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @123_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @124_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @125_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @126_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @128_588180
  ecx = edx = 0;  // @129_588180
  FL[2] = (eax & eax);  // @130_588180
  if (FL[2] == 0) goto L58835f;  // @131_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_588180
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @133_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @134_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[11]);  // @136_588180
  ecx = edx = 0;  // @137_588180
  ecx = (u32)(EBP - 16);  // @138_588180
  PV[12] = (u32)(ecx);  // @139_588180
  ecx = eax;  // @140_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @141_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[12]);  // @142_588180
  ecx = edx = 0;  // @143_588180
  L58835f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @146_588180
  FL[2] = (edx & edx);  // @147_588180
  edx = (u32)(EBP - 16);  // @148_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @149_588180
  PV[13] = (u32)(edx);  // @150_588180
  PV[14] = (u32)(ebx);  // @151_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @152_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_588180
  if (FL[2] != 0) goto L58838e;  // @154_588180
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 536)))(ecx, PV[14], PV[13], (u32)(16711680));  // @155_588180
  ecx = edx = 0;  // @156_588180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @157_588180
  goto L5883ea;  // @158_588180
  L58838e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @160_588180
  PV[15] = (u32)(edx);  // @161_588180
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[15], PV[14], PV[13], (u32)(16711680));  // w3e: same  // @162_588180
  ecx = edx = 0;  // @163_588180
  goto L5883ea;  // @164_588180
  L58839a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @166_588180
  FL[2] = (edx & edx);  // @167_588180
  if (FL[2] == 0) goto L5883c2;  // @168_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @169_588180
  PV[16] = (u32)(edx);  // @170_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @171_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @172_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @173_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[16]);  // @174_588180
  ecx = edx = 0;  // @175_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @176_588180
  L5883c2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @178_588180
  FL[2] = (edx & edx);  // @179_588180
  if (FL[2] == 0) goto L5883ea;  // @180_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @181_588180
  PV[17] = (u32)(edx);  // @182_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @183_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @184_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @185_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, PV[17]);  // @186_588180
  ecx = edx = 0;  // @187_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @188_588180
  L5883ea:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; }); FL[1] = edi;  // @190_588180
  if (FL[0] == FL[1]) goto L58851e;  // @191_588180
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @192_588180
  FL[2] = (edx & edx);  // @193_588180
  if (FL[2] == 0) goto L58841c;  // @194_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @195_588180
  PV[18] = (u32)(edx);  // @196_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @197_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @198_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @199_588180
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[18]);  // @200_588180
  ecx = edx = 0;  // @201_588180
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @202_588180
  L58841c:;
  ecx = (u32)(EBP - 64);  // @204_588180
  eax = ext_4de7a0_thiscall1(ecx);  // @205_588180
    // @206_588180
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @207_588180
  X0[1] = 0;  // @208_588180
  X0[2] = 0;  // @209_588180
  X0[3] = 0;  // @210_588180
  ecx = esi;  // @211_588180
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @212_588180
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7422608) + 0), 4); v; });  // @213_588180
  X0[1] = 0;  // @214_588180
  X0[2] = 0;  // @215_588180
  X0[3] = 0;  // @216_588180
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @217_588180
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @218_588180
  if (!__builtin_parity(FL[2] & 0xff)) goto L58847a;  // @219_588180
  eax = ext_585a10_thiscall1(ecx);  // @220_588180
  ecx = edx = 0;  // @221_588180
  eax = (eax - (u32)(0));  // @222_588180
  FL[3] = eax;  // @223_588180
  if (FL[3] == 0) goto L588470;  // @224_588180
  eax = (eax - (u32)(1));  // @225_588180
  FL[3] = eax;  // @226_588180
  if (FL[3] == 0) goto L588466;  // @227_588180
  eax = (eax - (u32)(1));  // @228_588180
  FL[3] = eax;  // @229_588180
  if (FL[3] != 0) goto L5884af;  // @230_588180
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; });  // @231_588180
  X0[1] = 0;  // @232_588180
  X0[2] = 0;  // @233_588180
  X0[3] = 0;  // @234_588180
  goto L5884aa;  // @235_588180
  L588466:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818412) + 0), 4); v; });  // @237_588180
  X0[1] = 0;  // @238_588180
  X0[2] = 0;  // @239_588180
  X0[3] = 0;  // @240_588180
  goto L5884aa;  // @241_588180
  L588470:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @243_588180
  X0[1] = 0;  // @244_588180
  X0[2] = 0;  // @245_588180
  X0[3] = 0;  // @246_588180
  goto L5884aa;  // @247_588180
  L58847a:;
  eax = ext_585a10_thiscall1(ecx);  // @249_588180
  ecx = edx = 0;  // @250_588180
  eax = (eax - (u32)(0));  // @251_588180
  FL[3] = eax;  // @252_588180
  if (FL[3] == 0) goto L5884a2;  // @253_588180
  eax = (eax - (u32)(1));  // @254_588180
  FL[3] = eax;  // @255_588180
  if (FL[3] == 0) goto L588498;  // @256_588180
  eax = (eax - (u32)(1));  // @257_588180
  FL[3] = eax;  // @258_588180
  if (FL[3] != 0) goto L5884af;  // @259_588180
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6870108) + 0), 4); v; });  // @260_588180
  X0[1] = 0;  // @261_588180
  X0[2] = 0;  // @262_588180
  X0[3] = 0;  // @263_588180
  goto L5884aa;  // @264_588180
  L588498:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6941528) + 0), 4); v; });  // @266_588180
  X0[1] = 0;  // @267_588180
  X0[2] = 0;  // @268_588180
  X0[3] = 0;  // @269_588180
  goto L5884aa;  // @270_588180
  L5884a2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6971556) + 0), 4); v; });  // @272_588180
  X0[1] = 0;  // @273_588180
  X0[2] = 0;  // @274_588180
  X0[3] = 0;  // @275_588180
  L5884aa:;
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @277_588180
  L5884af:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @279_588180
  X0[1] = 0;  // @280_588180
  X0[2] = 0;  // @281_588180
  X0[3] = 0;  // @282_588180
  edx = (u32)(EBP - 16);  // @283_588180
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @284_588180
  X1[1] = 0;  // @285_588180
  X1[2] = 0;  // @286_588180
  X1[3] = 0;  // @287_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @288_588180
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @289_588180
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; });  // @290_588180
  X0[1] = 0;  // @291_588180
  X0[2] = 0;  // @292_588180
  X0[3] = 0;  // @293_588180
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @294_588180
  X0[0] = X1[0];  // @295_588180
  X0[1] = X1[1];  // @296_588180
  X0[2] = X1[2];  // @297_588180
  X0[3] = X1[3];  // @298_588180
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @299_588180
  { u32 v = (u32)((u32)(1090519040)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @300_588180
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X1[0], 4);  // @301_588180
  { u32 v = (u32)((u32)(1090519040)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @302_588180
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; })));  // @303_588180
  PV[19] = (u32)(edi);  // @304_588180
  PV[20] = (u32)(edx);  // @305_588180
  edx = (u32)(EBP - 28);  // @306_588180
  PV[21] = (u32)(edx);  // @307_588180
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @308_588180
  edx = (u32)(EBP - 64);  // @309_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @310_588180
  PV[22] = (u32)(edx);  // @311_588180
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @312_588180
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @313_588180
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 568)))(ecx, PV[22], PV[21], PV[20], PV[19], (u32)(1));  // @314_588180
  ecx = edx = 0;  // @315_588180
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @316_588180
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @317_588180
  L58851e:;
  L58851f:;
  ext_633654(G(u32, 0x6f5630));  // @320_588180
  return eax;  // @321_588180
}
PCREG(588180, lifted_588180);

extern "C" u32 THISCALL lifted_5b5d60(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @0_5b5d60
  X1[0] = 0;  // @1_5b5d60
  X1[1] = 0;  // @2_5b5d60
  X1[2] = 0;  // @3_5b5d60
  X1[3] = 0;  // @4_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5b5d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @6_5b5d60
  X0[1] = 0;  // @7_5b5d60
  X0[2] = 0;  // @8_5b5d60
  X0[3] = 0;  // @9_5b5d60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @10_5b5d60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @11_5b5d60
  if (__builtin_parity(FL[2] & 0xff)) goto L5b5dc6;  // @12_5b5d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @13_5b5d60
  X0[1] = 0;  // @14_5b5d60
  X0[2] = 0;  // @15_5b5d60
  X0[3] = 0;  // @16_5b5d60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @17_5b5d60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @18_5b5d60
  if (__builtin_parity(FL[2] & 0xff)) goto L5b5dc6;  // @19_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @21_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @22_5b5d60
  ecx = edx = 0;  // @23_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_5b5d60
  PV[0] = (u32)(edx);  // @25_5b5d60
  PV[1] = (u32)(eax);  // @26_5b5d60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(7021144));  // @28_5b5d60
  ecx = edx = 0;  // @29_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_5b5d60
  L5b5dc6:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @32_5b5d60
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @33_5b5d60
  FL[3] = (eax & 0xff);  // @34_5b5d60
  ebx = 0;  // @35_5b5d60
  FL[3] = ebx;  // @36_5b5d60
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @37_5b5d60
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @38_5b5d60
  { u32 v = (u32)((u32)(12)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @39_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @40_5b5d60
  FL[2] = (edx & edx);  // @41_5b5d60
  if (FL[2] == 0) goto L5b5f6c;  // @42_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @43_5b5d60
  ecx = (u32)(EBP - 24);  // @44_5b5d60
  PV[2] = (u32)(ecx);  // @45_5b5d60
  ecx = edx;  // @46_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @47_5b5d60
  ecx = edx = 0;  // @48_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @49_5b5d60
  edx = (u32)(EBP - 24);  // @50_5b5d60
  PV[3] = (u32)(edx);  // @51_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[3]);  // @53_5b5d60
  ecx = edx = 0;  // @54_5b5d60
  esi = eax;  // @55_5b5d60
  FL[2] = (esi & esi);  // @56_5b5d60
  if (FL[2] == 0) goto L5b5f66;  // @57_5b5d60
  L5b5e10:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_5b5d60
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @61_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[4]);  // @63_5b5d60
  ecx = edx = 0;  // @64_5b5d60
  ebx = eax;  // @65_5b5d60
  ecx = ebx;  // @66_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @67_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @68_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097268));  // @69_5b5d60
  ecx = edx = 0;  // @70_5b5d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @71_5b5d60
  if (FL[2] == 0) goto L5b5e94;  // @72_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @73_5b5d60
  ecx = ebx;  // @74_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @75_5b5d60
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @76_5b5d60
  ecx = edx = 0;  // @77_5b5d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_5b5d60
  if (FL[2] != 0) goto L5b5e79;  // @79_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @80_5b5d60
  ecx = ebx;  // @81_5b5d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @82_5b5d60
  ecx = edx = 0;  // @83_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @84_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @85_5b5d60
  eax = (eax >> (u32)(10));  // @86_5b5d60
  FL[3] = eax;  // @87_5b5d60
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @88_5b5d60
  FL[2] = ((eax & 0xff) & (u32)(1));  // @89_5b5d60
  if (FL[2] == 0) goto L5b5e79;  // @90_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @91_5b5d60
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @92_5b5d60
  if ((s32)FL[0] < (s32)FL[1]) goto L5b5e6f;  // @93_5b5d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @94_5b5d60
  FL[2] = (ebx & ebx);  // @95_5b5d60
  if (FL[2] != 0) goto L5b5e97;  // @96_5b5d60
  L5b5e6f:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_5b5d60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @99_5b5d60
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @100_5b5d60
  goto L5b5e97;  // @101_5b5d60
  L5b5e79:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @103_5b5d60
  edx = (u32)(EBP - 24);  // @104_5b5d60
  PV[5] = (u32)(edx);  // @105_5b5d60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + eax*4 + 12), &v, sizeof v); }  // @106_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @107_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[5]);  // @109_5b5d60
  ecx = edx = 0;  // @110_5b5d60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @111_5b5d60
  L5b5e94:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @113_5b5d60
  L5b5e97:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @115_5b5d60
  edx = (u32)(EBP - 24);  // @116_5b5d60
  PV[6] = (u32)(edx);  // @117_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[6]);  // @119_5b5d60
  ecx = edx = 0;  // @120_5b5d60
  esi = eax;  // @121_5b5d60
  FL[2] = (esi & esi);  // @122_5b5d60
  if (FL[2] != 0) goto L5b5e10;  // @123_5b5d60
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; })) & 0xff);  // @124_5b5d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @125_5b5d60
  if (FL[2] == 0) goto L5b5f66;  // @126_5b5d60
  eax = (u32)(edi + 12);  // @127_5b5d60
  esi = (esi | (u32)(4294967295));  // @128_5b5d60
  FL[3] = esi;  // @129_5b5d60
  PV[7] = (u32)(eax);  // @130_5b5d60
  eax = ext_634d10_cdecl3(PV[7], (u32)(0), (u32)(48));  // @131_5b5d60
    // @132_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @133_5b5d60
  FL[2] = (ecx & ecx);  // @134_5b5d60
  if (FL[2] == 0) goto L5b5f66;  // @135_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_5b5d60
  edx = (u32)(EBP - 36);  // @137_5b5d60
  PV[8] = (u32)(edx);  // @138_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @139_5b5d60
  ecx = edx = 0;  // @140_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @141_5b5d60
  edx = (u32)(EBP - 36);  // @142_5b5d60
  PV[9] = (u32)(edx);  // @143_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[9]);  // @145_5b5d60
  ecx = edx = 0;  // @146_5b5d60
  edx = eax;  // @147_5b5d60
  FL[2] = (edx & edx);  // @148_5b5d60
  if (FL[2] == 0) goto L5b5f66;  // @149_5b5d60
  L5b5ef1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @151_5b5d60
  FL[2] = (ecx & ecx);  // @152_5b5d60
  if ((s32)FL[2] >= 0) goto L5b5f14;  // @153_5b5d60
  eax = 0;  // @154_5b5d60
  FL[3] = eax;  // @155_5b5d60
  ecx = (u32)(edi + 12);  // @156_5b5d60
  L5b5f00:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @158_5b5d60
  if (FL[0] == FL[1]) goto L5b5f10;  // @159_5b5d60
  eax = (eax + 1);  // @160_5b5d60
  FL[3] = eax;  // @161_5b5d60
  ecx = (ecx + (u32)(4));  // @162_5b5d60
  FL[3] = ecx;  // @163_5b5d60
  FL[0] = eax; FL[1] = (u32)(12);  // @164_5b5d60
  if ((s32)FL[0] < (s32)FL[1]) goto L5b5f00;  // @165_5b5d60
  goto L5b5f1c;  // @166_5b5d60
  L5b5f10:;
  esi = eax;  // @168_5b5d60
  goto L5b5f1c;  // @169_5b5d60
  L5b5f14:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx*4 + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @171_5b5d60
  if (FL[0] == FL[1]) esi = ecx;  // @172_5b5d60
  L5b5f1c:;
  FL[0] = esi; FL[1] = (u32)(-1);  // @174_5b5d60
  if (FL[0] == FL[1]) goto L5b5f2e;  // @175_5b5d60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @176_5b5d60
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + esi*4 + 12), &v, sizeof v); }  // @177_5b5d60
  goto L5b5f51;  // @178_5b5d60
  L5b5f2e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @180_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @181_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7021036), (u32)(776));  // @182_5b5d60
  ecx = edx = 0;  // @183_5b5d60
  PV[10] = (u32)(eax);  // @184_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @185_5b5d60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 48)))(PV[10], (u32)(7021156));  // @186_5b5d60
  ecx = edx = 0;  // @187_5b5d60
  L5b5f51:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @189_5b5d60
  edx = (u32)(EBP - 36);  // @190_5b5d60
  PV[11] = (u32)(edx);  // @191_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[11]);  // @193_5b5d60
  ecx = edx = 0;  // @194_5b5d60
  edx = eax;  // @195_5b5d60
  FL[2] = (edx & edx);  // @196_5b5d60
  if (FL[2] != 0) goto L5b5ef1;  // @197_5b5d60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @198_5b5d60
  L5b5f66:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @200_5b5d60
  L5b5f6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @202_5b5d60
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @203_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @204_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[12]);  // @205_5b5d60
  ecx = edx = 0;  // @206_5b5d60
  esi = eax;  // @207_5b5d60
  ecx = esi;  // @208_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @209_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @210_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097268));  // @211_5b5d60
  ecx = edx = 0;  // @212_5b5d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @213_5b5d60
  if (FL[2] == 0) goto L5b60a5;  // @214_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @215_5b5d60
  ecx = esi;  // @216_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @217_5b5d60
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @218_5b5d60
  ecx = edx = 0;  // @219_5b5d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @220_5b5d60
  if (FL[2] != 0) goto L5b5fbe;  // @221_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @222_5b5d60
  ecx = esi;  // @223_5b5d60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @224_5b5d60
  ecx = edx = 0;  // @225_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @226_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @227_5b5d60
  eax = (eax >> (u32)(10));  // @228_5b5d60
  FL[3] = eax;  // @229_5b5d60
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @230_5b5d60
  FL[2] = ((eax & 0xff) & (u32)(1));  // @231_5b5d60
  if (FL[2] != 0) goto L5b60a5;  // @232_5b5d60
  L5b5fbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @234_5b5d60
  ecx = esi;  // @235_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @236_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2098152));  // @237_5b5d60
  ecx = edx = 0;  // @238_5b5d60
  ecx = 0;  // @239_5b5d60
  FL[3] = ecx;  // @240_5b5d60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @241_5b5d60
  if (FL[2] != 0) ebx = ecx;  // @242_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @243_5b5d60
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @244_5b5d60
  FL[2] = (ecx & ecx);  // @245_5b5d60
  if (FL[2] == 0) goto L5b6046;  // @246_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @247_5b5d60
  edx = (u32)(EBP - 36);  // @248_5b5d60
  PV[13] = (u32)(edx);  // @249_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[13]);  // @250_5b5d60
  ecx = edx = 0;  // @251_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @252_5b5d60
  edx = (u32)(EBP - 36);  // @253_5b5d60
  PV[14] = (u32)(edx);  // @254_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @255_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[14]);  // @256_5b5d60
  ecx = edx = 0;  // @257_5b5d60
  edx = eax;  // @258_5b5d60
  FL[2] = (edx & edx);  // @259_5b5d60
  if (FL[2] == 0) goto L5b6046;  // @260_5b5d60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @261_5b5d60
  L5b6000:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @263_5b5d60
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @264_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @265_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @266_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[15]);  // @267_5b5d60
  ecx = edx = 0;  // @268_5b5d60
  ecx = (u32)(EBP + 8);  // @269_5b5d60
  PV[16] = (u32)(ecx);  // @270_5b5d60
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 78), sizeof v); (u32)v; });  // @271_5b5d60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @272_5b5d60
  PV[17] = (u32)(ecx);  // @273_5b5d60
  ecx = eax;  // @274_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[17], PV[16], (u32)(0));  // @275_5b5d60
  ecx = edx = 0;  // @276_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @277_5b5d60
  edx = (u32)(EBP - 36);  // @278_5b5d60
  PV[18] = (u32)(edx);  // @279_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @280_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[18]);  // @281_5b5d60
  ecx = edx = 0;  // @282_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @283_5b5d60
  edx = (u32)(EBP - 36);  // @284_5b5d60
  PV[19] = (u32)(edx);  // @285_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @286_5b5d60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[19]);  // @287_5b5d60
  ecx = edx = 0;  // @288_5b5d60
  edx = eax;  // @289_5b5d60
  FL[2] = (edx & edx);  // @290_5b5d60
  if (FL[2] != 0) goto L5b6000;  // @291_5b5d60
  L5b6046:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @293_5b5d60
  X1[0] = 0;  // @294_5b5d60
  X1[1] = 0;  // @295_5b5d60
  X1[2] = 0;  // @296_5b5d60
  X1[3] = 0;  // @297_5b5d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @298_5b5d60
  X0[1] = 0;  // @299_5b5d60
  X0[2] = 0;  // @300_5b5d60
  X0[3] = 0;  // @301_5b5d60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @302_5b5d60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @303_5b5d60
  if (__builtin_parity(FL[2] & 0xff)) goto L5b609a;  // @304_5b5d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @305_5b5d60
  X0[1] = 0;  // @306_5b5d60
  X0[2] = 0;  // @307_5b5d60
  X0[3] = 0;  // @308_5b5d60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @309_5b5d60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @310_5b5d60
  if (__builtin_parity(FL[2] & 0xff)) goto L5b609a;  // @311_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @312_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @313_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @314_5b5d60
  ecx = edx = 0;  // @315_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @316_5b5d60
  PV[20] = (u32)(edx);  // @317_5b5d60
  PV[21] = (u32)(eax);  // @318_5b5d60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @319_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[21], PV[20], (u32)(7021144));  // @320_5b5d60
  ecx = edx = 0;  // @321_5b5d60
  L5b609a:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @323_5b5d60
  FL[3] = (eax & 0xff);  // @324_5b5d60
  return eax;  // @325_5b5d60
  L5b60a5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @327_5b5d60
  X1[0] = 0;  // @328_5b5d60
  X1[1] = 0;  // @329_5b5d60
  X1[2] = 0;  // @330_5b5d60
  X1[3] = 0;  // @331_5b5d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @332_5b5d60
  X0[1] = 0;  // @333_5b5d60
  X0[2] = 0;  // @334_5b5d60
  X0[3] = 0;  // @335_5b5d60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @336_5b5d60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @337_5b5d60
  if (__builtin_parity(FL[2] & 0xff)) goto L5b60f9;  // @338_5b5d60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @339_5b5d60
  X0[1] = 0;  // @340_5b5d60
  X0[2] = 0;  // @341_5b5d60
  X0[3] = 0;  // @342_5b5d60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @343_5b5d60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @344_5b5d60
  if (__builtin_parity(FL[2] & 0xff)) goto L5b60f9;  // @345_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @346_5b5d60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @347_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @348_5b5d60
  ecx = edx = 0;  // @349_5b5d60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @350_5b5d60
  PV[22] = (u32)(edx);  // @351_5b5d60
  PV[23] = (u32)(eax);  // @352_5b5d60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @353_5b5d60
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[23], PV[22], (u32)(7021144));  // @354_5b5d60
  ecx = edx = 0;  // @355_5b5d60
  L5b60f9:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @357_5b5d60
  return eax;  // @358_5b5d60
}
PCREG(5b5d60, lifted_5b5d60);

