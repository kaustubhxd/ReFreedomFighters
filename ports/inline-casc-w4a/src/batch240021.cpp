// batch240021.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_42ab62_cdecl1(...) __asm__("ext_42ab62");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_425d30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {  // hand fix: cdecl(obj, fmt, varargs...): the lifter saw no stack arguments
  u8 F[0x2160] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x2060);
  __builtin_memcpy(F + 0x2060 + 8, &a0, 4); __builtin_memcpy(F + 0x2060 + 12, &a1, 4); __builtin_memcpy(F + 0x2060 + 16, &a2, 4); __builtin_memcpy(F + 0x2060 + 20, &a3, 4); __builtin_memcpy(F + 0x2060 + 24, &a4, 4); __builtin_memcpy(F + 0x2060 + 28, &a5, 4);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_425d30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_425d30
  if (FL[0] == FL[1]) goto L425f55;  // @2_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @3_425d30
  FL[2] = (eax & eax);  // @4_425d30
  if (FL[2] == 0) goto L425d90;  // @5_425d30
  eax = (eax - 1);  // @6_425d30
  FL[3] = eax;  // @7_425d30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @8_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @9_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_425d30
  FL[2] = (ecx & ecx);  // @11_425d30
  if (FL[2] == 0) goto L425d90;  // @12_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_425d30
  edx = (u32)(EBP - 8212);  // @14_425d30
  PV[0] = (u32)(edx);  // @15_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @16_425d30
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6784780), PV[0]);  // @17_425d30
  ecx = edx = 0;  // @18_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @19_425d30
  if (FL[2] == 0) goto L425d90;  // @20_425d30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @21_425d30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @22_425d30
  L425d90:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 18), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @24_425d30
  if (FL[0] != FL[1]) goto L425d90;  // @25_425d30
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @26_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_425d30
  ecx = (u32)(EBP - 8196);  // @28_425d30
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @29_425d30
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @30_425d30
  PV[3] = (u32)(ecx);  // @31_425d30
  PV[4] = (u32)(esi);  // @32_425d30
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 0)))(PV[4], PV[3], (u32)(6784796), PV[2], PV[1]);  // @33_425d30 (hand fix: cdecl, ecx is junk)
  ecx = edx = 0;  // @34_425d30
  ecx = (u32)(EBP - 8196);  // @35_425d30
  edx = (u32)(ecx + 1);  // @36_425d30
  L425dc0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @38_425d30
  ecx = (ecx + 1);  // @39_425d30
  FL[3] = ecx;  // @40_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @41_425d30
  if (FL[2] != 0) goto L425dc0;  // @42_425d30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @43_425d30
  ecx = (ecx - edx);  // @44_425d30
  FL[3] = ecx;  // @45_425d30
  edx = edi;  // @46_425d30
  ebx = (u32)(edx + 1);  // @47_425d30
  L425dd3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @49_425d30
  edx = (edx + 1);  // @50_425d30
  FL[3] = edx;  // @51_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @52_425d30
  if (FL[2] != 0) goto L425dd3;  // @53_425d30
  edx = (edx - ebx);  // @54_425d30
  FL[3] = edx;  // @55_425d30
  ebx = (u32)(EBP - 8196);  // @56_425d30
  ebx = (ebx + ecx);  // @57_425d30
  FL[3] = ebx;  // @58_425d30
  eax = (u32)(edx + ecx);  // @59_425d30
  FL[0] = eax; FL[1] = (u32)(8192);  // @60_425d30
  if (FL[0] >= FL[1]) goto L425dfd;  // @61_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_425d30
  ecx = (u32)(EBP + 16);  // @63_425d30
  PV[5] = (u32)(ecx);  // @64_425d30
  PV[6] = (u32)(edi);  // @65_425d30
  PV[7] = (u32)(ebx);  // @66_425d30
  ecx = esi;  // @67_425d30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[7], PV[6], PV[5]);  // @68_425d30
  ecx = edx = 0;  // @69_425d30
  goto L425e19;  // @70_425d30
  L425dfd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784804) + 0), 4); v; });  // @72_425d30
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784804) + 4), 4); v; });  // @73_425d30
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784804) + 8), 4); v; });  // @74_425d30
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784804) + 12), 4); v; });  // @75_425d30
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784820), sizeof v); (u32)v; })) & 0xffff);  // @76_425d30
  __builtin_memcpy((void *)((u32)(ebx) + 0), &X0[0], 4);  // @77_425d30
  __builtin_memcpy((void *)((u32)(ebx) + 4), &X0[1], 4);  // @78_425d30
  __builtin_memcpy((void *)((u32)(ebx) + 8), &X0[2], 4);  // @79_425d30
  __builtin_memcpy((void *)((u32)(ebx) + 12), &X0[3], 4);  // @80_425d30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @81_425d30
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6784822), sizeof v); (u32)v; })) & 0xff);  // @82_425d30
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 18), &v, sizeof v); }  // @83_425d30
  L425e19:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(40);  // @85_425d30
  if (FL[0] != FL[1]) goto L425e3d;  // @86_425d30
  edx = (u32)(EBP - 8196);  // @87_425d30
  ecx = ebx;  // @88_425d30
  edx = (edx - ebx);  // @89_425d30
  FL[3] = edx;  // @90_425d30
  L425e30:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @92_425d30
  ecx = (u32)(ecx + 1);  // @93_425d30
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @94_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @95_425d30
  if (FL[2] != 0) goto L425e30;  // @96_425d30
  L425e3d:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8196), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @98_425d30
  if (FL[0] != FL[1]) goto L425e5c;  // @99_425d30
  edi = (u32)(EBP - 8196);  // @100_425d30
  edi = (edi - 1);  // @101_425d30
  FL[3] = edi;  // @102_425d30
  L425e50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @104_425d30
  edi = (u32)(edi + 1);  // @105_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @106_425d30
  if (FL[2] != 0) goto L425e50;  // @107_425d30
  goto L425e8a;  // @108_425d30
  L425e5c:;
  ecx = (u32)(EBP - 8196);  // @110_425d30
  edx = (u32)(ecx + 1);  // @111_425d30
  L425e65:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @113_425d30
  ecx = (ecx + 1);  // @114_425d30
  FL[3] = ecx;  // @115_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @116_425d30
  if (FL[2] != 0) goto L425e65;  // @117_425d30
  ecx = (ecx - edx);  // @118_425d30
  FL[3] = ecx;  // @119_425d30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + ecx - 8197), sizeof v); (u32)v; }); FL[1] = (u32)(10);  // @120_425d30
  if (FL[0] == FL[1]) goto L425e93;  // @121_425d30
  edi = (u32)(EBP - 8196);  // @122_425d30
  edi = (edi - 1);  // @123_425d30
  FL[3] = edi;  // @124_425d30
  L425e80:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @126_425d30
  edi = (u32)(edi + 1);  // @127_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @128_425d30
  if (FL[2] != 0) goto L425e80;  // @129_425d30
  L425e8a:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6777860), sizeof v); (u32)v; })) & 0xffff);  // @131_425d30
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @132_425d30
  L425e93:;
  eax = (u32)(EBP - 8196);  // @134_425d30
  PV[8] = (u32)(eax);  // @135_425d30
  eax = ext_42ab62_cdecl1(PV[8]);  // @136_425d30
  ecx = edx = 0;  // @137_425d30
  eax = ((u32( *)(u32))(*(u32 *)0x6763c8))((u32)(1));  // @138_425d30
  ecx = edx = 0;  // @139_425d30
  PV[9] = (u32)(eax);  // @140_425d30
  eax = ((u32( *)(u32))(*(u32 *)0x6763c4))(PV[9]);  // @141_425d30
  ecx = edx = 0;  // @142_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @143_425d30
  FL[2] = (eax & eax);  // @144_425d30
  if (FL[2] == 0) goto L425ef4;  // @145_425d30
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 77), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @146_425d30
  if (FL[0] == FL[1]) goto L425ef4;  // @147_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @148_425d30
  FL[2] = (ecx & ecx);  // @149_425d30
  if (FL[2] == 0) goto L425ef4;  // @150_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @151_425d30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 432)))(ecx);  // @152_425d30
  ecx = edx = 0;  // @153_425d30
  FL[2] = (eax & eax);  // @154_425d30
  if (FL[2] == 0) goto L425ef4;  // @155_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_425d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @157_425d30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 432)))(ecx);  // @158_425d30
  ecx = edx = 0;  // @159_425d30
  edx = (u32)(EBP - 8196);  // @160_425d30
  PV[10] = (u32)(edx);  // @161_425d30
  PV[11] = (u32)(eax);  // @162_425d30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @163_425d30
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 4)))(PV[11], PV[10]);  // @164_425d30
  ecx = edx = 0;  // @165_425d30
  L425ef4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @167_425d30
  FL[2] = (edx & edx);  // @168_425d30
  if (FL[2] == 0) goto L425f42;  // @169_425d30
  ecx = (u32)(EBP - 8196);  // @170_425d30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8208), &v, sizeof v); }  // @171_425d30
  edi = (u32)(ecx + 1);  // @172_425d30
  L425f10:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @174_425d30
  ecx = (ecx + 1);  // @175_425d30
  FL[3] = ecx;  // @176_425d30
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @177_425d30
  if (FL[2] != 0) goto L425f10;  // @178_425d30
  ecx = (ecx - edi);  // @179_425d30
  FL[3] = ecx;  // @180_425d30
  eax = (u32)(ecx + 1);  // @181_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8204), &v, sizeof v); }  // @182_425d30
  eax = (u32)(EBP - 8196);  // @183_425d30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8200), &v, sizeof v); }  // @184_425d30
  eax = (u32)(EBP - 8208);  // @185_425d30
  PV[12] = (u32)(eax);  // @186_425d30
  PV[13] = (u32)(edx);  // @187_425d30
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x67621c))(PV[13], (u32)(74), (u32)(0), PV[12]);  // @188_425d30
  ecx = edx = 0;  // @189_425d30
  goto L425f4f;  // @190_425d30
  L425f42:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 19), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @192_425d30
  if (FL[0] == FL[1]) goto L425f4f;  // @193_425d30
  PV[14] = (u32)(ebx);  // @194_425d30
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676098))(PV[14]);  // @195_425d30
  ecx = edx = 0;  // @196_425d30
  L425f4f:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 18), &v, sizeof v); }  // @198_425d30
  L425f55:;
  ext_633654(G(u32, 0x6f5630));  // @200_425d30
  return eax;  // @201_425d30
}
PCREG(425d30, lifted_425d30);

