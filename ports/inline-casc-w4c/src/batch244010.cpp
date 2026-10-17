// batch244010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_41f190_thiscall1(u32, u32) __asm__("ext_41f190");
extern "C" u32 THISCALL ext_661b40_thiscall8(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_661b40");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_661940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @2_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @3_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_661940
  edi = edx;  // @5_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @6_661940
  eax = edx;  // @7_661940
  ebx = (edx & 0xffff);  // @8_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @9_661940
  eax = (eax >> (u32)(31));  // @10_661940
  FL[3] = eax;  // @11_661940
  edx = (edx + ecx);  // @12_661940
  FL[3] = edx;  // @13_661940
  edi = (edi >> (u32)(16));  // @14_661940
  FL[3] = edi;  // @15_661940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @16_661940
  FL[3] = (eax & 0xff);  // @17_661940
  edi = (edi & (u32)(32767));  // @18_661940
  FL[3] = edi;  // @19_661940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @21_661940
  ebx = (ebx + edi);  // @22_661940
  FL[3] = ebx;  // @23_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @24_661940
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax);  // @25_661940
  if (FL[2] != 0) goto L661994;  // @26_661940
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @27_661940
  FL[3] = (eax & 0xff);  // @28_661940
  return eax;  // @29_661940
  L661994:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @31_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @32_661940
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @33_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @34_661940
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @35_661940
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @36_661940
  FL[3] = ecx;  // @37_661940
  eax = (u32)(eax + edi*2);  // @38_661940
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @39_661940
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @40_661940
  FL[3] = eax;  // @41_661940
  PV[4] = (u32)(ebx);  // @42_661940
  PV[5] = (u32)(edi);  // @43_661940
  PV[6] = (u32)(eax);  // @44_661940
  PV[7] = (u32)(ecx);  // @45_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @46_661940
  eax = ext_661b40_thiscall8(ecx_in, PV[7], PV[6], PV[5], PV[4], PV[3], PV[2], PV[1], PV[0]);  // @47_661940
  ecx = edx = 0;  // @48_661940
  return eax;  // @49_661940
}
PCREG(661940, lifted_661940);

extern "C" u32 THISCALL lifted_660f60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  X1[0] = 0;  // @0_660f60
  X1[1] = 0;  // @1_660f60
  X1[2] = 0;  // @2_660f60
  X1[3] = 0;  // @3_660f60
  ebx = ecx;  // @4_660f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_660f60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @6_660f60
  X0[1] = 0;  // @7_660f60
  X0[2] = 0;  // @8_660f60
  X0[3] = 0;  // @9_660f60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @10_660f60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @11_660f60
  if (__builtin_parity(FL[2] & 0xff)) goto L660fee;  // @12_660f60
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @13_660f60
  X0[1] = 0;  // @14_660f60
  X0[2] = 0;  // @15_660f60
  X0[3] = 0;  // @16_660f60
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @17_660f60
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @18_660f60
  if (__builtin_parity(FL[2] & 0xff)) goto L660fee;  // @19_660f60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_660f60
  if (FL[0] != FL[1]) goto L660fee;  // @21_660f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @22_660f60
  FL[2] = (ecx & ecx);  // @23_660f60
  if (FL[2] == 0) goto L660fee;  // @24_660f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_660f60
  edx = (u32)(EBP - 12);  // @26_660f60
  PV[0] = (u32)(edx);  // @27_660f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @28_660f60
  ecx = edx = 0;  // @29_660f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @30_660f60
  edx = (u32)(EBP - 12);  // @31_660f60
  PV[1] = (u32)(edx);  // @32_660f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_660f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @34_660f60
  ecx = edx = 0;  // @35_660f60
  FL[2] = (eax & eax);  // @36_660f60
  if (FL[2] == 0) goto L660fee;  // @37_660f60
  L660fc0:;
  edi = (u32)(eax + 48);  // @39_660f60
  ecx = (u32)(98);  // @40_660f60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @41_660f60
  edx = (u32)(EBP - 12);  // @42_660f60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @43_660f60
  esi = edi;  // @44_660f60
  edi = (edi + (u32)(8));  // @45_660f60
  FL[3] = edi;  // @46_660f60
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @47_660f60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @48_660f60
  PV[2] = (u32)(edx);  // @49_660f60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_660f60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[2]);  // @51_660f60
  ecx = edx = 0;  // @52_660f60
  FL[2] = (eax & eax);  // @53_660f60
  if (FL[2] != 0) goto L660fc0;  // @54_660f60
  L660fee:;
  return eax;  // @56_660f60
}
PCREG(660f60, lifted_660f60);

extern "C" u32 THISCALL lifted_41f400(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_41f400
  ebx = ecx;  // @1_41f400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @2_41f400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @3_41f400
  eax = (u32)(edi + 32);  // @4_41f400
  PV[0] = (u32)(eax);  // @5_41f400
  eax = ext_41f190_thiscall1(ecx, PV[0]);  // @6_41f400
  ecx = edx = 0;  // @7_41f400
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }); FL[1] = esi;  // @8_41f400
  if (FL[0] == FL[1]) goto L41f43e;  // @9_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_41f400
  ecx = ebx;  // @11_41f400
  PV[1] = (u32)(edi);  // @12_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780060), PV[1]);  // @13_41f400
  ecx = edx = 0;  // @14_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @15_41f400
  ecx = (ecx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @16_41f400
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @17_41f400
  FL[2] = (eax & eax);  // @18_41f400
  if (FL[2] == 0) goto L41f478;  // @19_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @20_41f400
  ecx = edx = 0;  // @21_41f400
  L41f43e:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; })) & 0xff);  // @23_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @24_41f400
  eax = (eax & (u32)(536870911));  // @25_41f400
  FL[3] = eax;  // @26_41f400
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 32), sizeof v); (u32)v; }); FL[1] = (u32)(2271560481);  // @27_41f400
  if (FL[0] == FL[1]) goto L41f487;  // @28_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_41f400
  ecx = ebx;  // @30_41f400
  PV[2] = (u32)(edi);  // @31_41f400
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, (u32)(6780084), PV[2]);  // @32_41f400
  ecx = edx = 0;  // @33_41f400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @34_41f400
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @35_41f400
  FL[2] = (eax & eax);  // @36_41f400
  if (FL[2] == 0) goto L41f47b;  // @37_41f400
  eax = ((u32(STDCALL *)(void))(eax))();  // @38_41f400
  ecx = edx = 0;  // @39_41f400
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @40_41f400
  return eax;  // @41_41f400
  L41f478:;
  __builtin_trap();  // @43_41f400
  L41f47b:;
  __builtin_trap();  // @45_41f400
  L41f487:;
  eax = (eax & 0xffffff00u) | (((ecx & 0xff)) & 0xff);  // @47_41f400
  return eax;  // @48_41f400
}
PCREG(41f400, lifted_41f400);


// ---- hand ports (lifter rejects these bodies). GUESS names.
extern "C" u32 THISCALL ext_63b240(u8 *self);
extern "C" u32 THISCALL ext_63f090(u8 *self, u8 *o);
extern "C" void THISCALL ext_45d3a0(u8 *self);
extern "C" u32 THISCALL ext_4db520(u8 *node);
extern "C" u32 THISCALL ext_4db9a0(u8 *node, u32 mask);
typedef u32(THISCALL *w4c_v0_t)(void *);
typedef u32(THISCALL *w4c_v1_t)(void *, u32);

// 0x63ace0: take a free entry (16 bytes) from the first block of the ring at [this+8] that has one (word +2 is the free-list head, 0xffff = none);
// refills with 0x63b240 when the ring is exhausted. Returns the cleared entry (dword +0 = 0, +4 = 0xffff1201, byte +8 = 0, +0xc = 0) or 0; counts attempts in [this+0xc].
static u8 *THISCALL fn63ace0(u8 *self) {
  u8 *first = *(u8 **)(self + 8);
  u8 *e;
  bool found = false;
  if (first) {
    for (;;) {
      e = *(u8 **)(self + 8);
      if (*(u16 *)(e + 2) != 0xffff) { found = true; break; }
      e = *(u8 **)(e + 8);
      *(u8 **)(self + 8) = e;
      if (first == e) break;
      if (!e) break;
    }
  }
  if (!found) {
    if (!(u8)ext_63b240(self)) return 0;
    e = *(u8 **)(self + 8);
  }
  (*(u32 *)(self + 0xc))++;
  u32 ax = *(u16 *)(e + 2);
  if (ax == 0xffff) return 0;
  u8 *ent = e + ((ax + 1) << 4);
  *(u16 *)(e + 2) = *(u16 *)ent;
  *(u32 *)ent = 0;
  *(u32 *)(ent + 4) = 0xffff1201;
  ent[8] = 0;
  *(u32 *)(ent + 0xc) = 0;
  (*e)++;
  return ent;
}
PCREG(63ace0, fn63ace0);

// 0x63f4e0: thiscall(out, rec, unused) ret 0xc; returns al. word [rec+6] != 0: out[0x10] = table[this+0x68][(word & 0xfff)]; else o = [this+0x228]->slot 8(); null returns 0;
// [o+8] = rec; this->slot 0x9c(o) false: this->slot 0x98(o), [this+0x228]->slot 0xc(o), return 0; true: word [rec+6] = 0x63f090(this, o), out[0x10] = o, return 1.
static u32 THISCALL fn63f4e0(u8 *self, u8 *out, u8 *rec, u32 unused) {
  u32 esi = *(u16 *)(rec + 6);
  if (esi == 0) {
    void *obj = *(void **)(self + 0x228);
    u8 *o = (u8 *)(*(w4c_v0_t **)obj)[8 / 4](obj);
    if (!o) return 0;
    *(u8 **)(o + 8) = rec;
    u32 r = (*(w4c_v1_t **)self)[0x9c / 4](self, (u32)o);
    if ((u8)r == 0) {
      (*(w4c_v1_t **)self)[0x98 / 4](self, (u32)o);
      void *ob2 = *(void **)(self + 0x228);
      (*(w4c_v1_t **)ob2)[0xc / 4](ob2, (u32)o);
      return 0;
    }
    u32 ax = ext_63f090(self, o);
    *(u16 *)(rec + 6) = (u16)ax;
    *(u8 **)(out + 0x10) = o;
    return 1;
  }
  u8 *tbl = *(u8 **)(self + 0x68);
  *(u32 *)(out + 0x10) = *(u32 *)(tbl + (esi & 0xfff) * 4);
  return 1;
}
PCREG(63f4e0, fn63f4e0);

// 0x4f9af0: walks the children list from [this+0x54] (next via 0x4db520), collecting flag bits; then reports through slots 0xbc, 0x2dc/0x2d8, 0x2ec.
static void THISCALL fn4f9af0(u8 *self) {
  ext_45d3a0(self);
  u8 *esi = *(u8 **)(self + 0x54);
  while (esi) {
    u8 *p = *(u8 **)(esi + 0x54);
    u32 flags = p ? *(u32 *)(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
    if (flags & 0x100000) break;
    if ((u8)ext_4db9a0(esi, 0x20002c)) *(u32 *)(self + 0x74) |= *(u8 *)(*(u8 **)(esi + 0x54) + 0x21);
    esi = (u8 *)ext_4db520(esi);
  }
  (*(w4c_v1_t **)self)[0xbc / 4](self, (self[0x6c] & 1) ? 0 : 1);
  if (self[0x6c] & 2) (*(w4c_v0_t **)self)[0x2dc / 4](self);
  else (*(w4c_v0_t **)self)[0x2d8 / 4](self);
  u32 v = *(u32 *)(self + 0x70);
  *(u32 *)(self + 0x70) = 0;
  (*(w4c_v1_t **)self)[0x2ec / 4](self, v);
}
PCREG(4f9af0, fn4f9af0);
