#include "ff.h"
typedef unsigned short u16; typedef long long s64; typedef int v4si_t __attribute__((vector_size(16)));
typedef float v4sf_t __attribute__((vector_size(16)));
static inline u32 ld32(u32 a) { u32 v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline u32 ld16(u32 a) { u16 v; __builtin_memcpy(&v, (void *)a, 2); return v; }
static inline u32 ld8(u32 a) { return *(u8 *)a; }
static inline void st32(u32 a, u32 v) { __builtin_memcpy((void *)a, &v, 4); }
static inline void st16(u32 a, u32 v) { u16 x = (u16)v; __builtin_memcpy((void *)a, &x, 2); }
static inline void st8(u32 a, u32 v) { *(u8 *)a = (u8)v; }
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
#define PF_(r) (!(__builtin_popcount((r) & 0xff) & 1))
#define MSB(T) (sizeof(T) * 8 - 1)
template <class T> static inline T alu_add(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a + b; cf = r < a; of = ((a ^ r) & (b ^ r)) >> MSB(T) & 1; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_adc(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a + b + cf; cf = (u64)a + b + cf > (T)~(T)0; of = ((a ^ r) & (b ^ r)) >> MSB(T) & 1; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_sub(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a - b; cf = a < b; of = ((a ^ b) & (a ^ r)) >> MSB(T) & 1; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_sbb(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a - b - cf; cf = (u64)a < (u64)b + cf; of = ((a ^ b) & (a ^ r)) >> MSB(T) & 1; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_and(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a & b; cf = of = 0; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_or(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a | b; cf = of = 0; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_xor(T a, T b, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a ^ b; cf = of = 0; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_inc(T a, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a + 1; of = r == (T)((T)1 << MSB(T)); zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_dec(T a, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a - 1; of = a == (T)((T)1 << MSB(T)); zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_neg(T a, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = (T)0 - a; cf = a != 0; of = a == (T)((T)1 << MSB(T)); zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_shl(T a, int n, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a << n; cf = (a >> (MSB(T) + 1 - n)) & 1; of = 0; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_shr(T a, int n, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { T r = a >> n; cf = (a >> (n - 1)) & 1; of = 0; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
template <class T> static inline T alu_sar(T a, int n, u32 &cf, u32 &zf, u32 &sf, u32 &of, u32 &pf) { long long sa = (sizeof(T) == 4) ? (long long)(s32)a : (sizeof(T) == 2 ? (long long)(short)a : (long long)(signed char)a); T r = (T)(sa >> n); cf = (sa >> (n - 1)) & 1; of = 0; zf = r == 0; sf = r >> MSB(T) & 1; pf = PF_(r); return r; }
extern "C" unsigned long long ext_634670(void) __asm__("ext_634670");
extern "C" u32 STDCALL ext_5fa630_stdcall0(void) __asm__("ext_5fa630");
extern "C" u32 THISCALL ext_5002f0_thiscall2(u32, u32) __asm__("ext_5002f0");
extern "C" u32 THISCALL ext_500360_thiscall2(u32, u32) __asm__("ext_500360");
extern "C" u32 THISCALL ext_50d7b0_thiscall2(u32, u32) __asm__("ext_50d7b0");
extern "C" u32 THISCALL ext_5f3440_thiscall4(u32, u32, u32, u32) __asm__("ext_5f3440");
extern "C" u32 THISCALL ext_5f3bf0_thiscall2(u32, u32) __asm__("ext_5f3bf0");
extern "C" u32 THISCALL ext_5f3c40_thiscall1(u32) __asm__("ext_5f3c40");
extern "C" u32 THISCALL ext_5f3d40_thiscall2(u32, u32) __asm__("ext_5f3d40");
extern "C" u32 THISCALL ext_5f3db0_thiscall2(u32, u32) __asm__("ext_5f3db0");
extern "C" u32 THISCALL ext_5f3fc0_thiscall2(u32, u32) __asm__("ext_5f3fc0");
extern "C" u32 THISCALL ext_5f40b0_thiscall2(u32, u32) __asm__("ext_5f40b0");
extern "C" u32 THISCALL ext_5f4110_thiscall2(u32, u32) __asm__("ext_5f4110");
extern "C" u32 THISCALL ext_5f4390_thiscall1(u32) __asm__("ext_5f4390");
extern "C" u32 THISCALL ext_5f4a00_thiscall2(u32, u32) __asm__("ext_5f4a00");
extern "C" u32 THISCALL ext_5f4a80_thiscall2(u32, u32) __asm__("ext_5f4a80");
extern "C" u32 THISCALL ext_5f4ac0_thiscall1(u32) __asm__("ext_5f4ac0");
extern "C" u32 THISCALL ext_5f4d80_thiscall2(u32, u32) __asm__("ext_5f4d80");
extern "C" u32 THISCALL ext_5f4dc0_thiscall2(u32, u32) __asm__("ext_5f4dc0");
extern "C" u32 THISCALL ext_5f4e00_thiscall2(u32, u32) __asm__("ext_5f4e00");
extern "C" u32 THISCALL ext_5f4e60_thiscall2(u32, u32) __asm__("ext_5f4e60");
extern "C" u32 THISCALL ext_5f4ec0_thiscall2(u32, u32) __asm__("ext_5f4ec0");
extern "C" u32 THISCALL ext_5f4f00_thiscall2(u32, u32) __asm__("ext_5f4f00");
extern "C" u32 THISCALL ext_5f4f70_thiscall1(u32) __asm__("ext_5f4f70");
extern "C" u32 THISCALL ext_5f4fb0_thiscall2(u32, u32) __asm__("ext_5f4fb0");
extern "C" u32 THISCALL ext_5f4ff0_thiscall1(u32) __asm__("ext_5f4ff0");
extern "C" u32 THISCALL ext_5f5020_thiscall1(u32) __asm__("ext_5f5020");
extern "C" u32 THISCALL ext_5f51e0_thiscall2(u32, u32) __asm__("ext_5f51e0");
extern "C" u32 THISCALL ext_5f5250_thiscall2(u32, u32) __asm__("ext_5f5250");
extern "C" u32 THISCALL ext_5f52f0_thiscall2(u32, u32) __asm__("ext_5f52f0");
extern "C" u32 THISCALL ext_5f5390_thiscall2(u32, u32) __asm__("ext_5f5390");
extern "C" u32 THISCALL ext_5f53f0_thiscall2(u32, u32) __asm__("ext_5f53f0");
extern "C" u32 THISCALL ext_5f5490_thiscall3(u32, u32, u32) __asm__("ext_5f5490");
extern "C" u32 THISCALL ext_5f5520_thiscall3(u32, u32, u32) __asm__("ext_5f5520");
extern "C" u32 THISCALL ext_5f5620_thiscall2(u32, u32) __asm__("ext_5f5620");
extern "C" u32 THISCALL ext_5f5680_thiscall2(u32, u32) __asm__("ext_5f5680");
extern "C" u32 THISCALL ext_5f9010_thiscall1(u32) __asm__("ext_5f9010");
extern "C" u32 THISCALL ext_5f90a0_thiscall1(u32) __asm__("ext_5f90a0");
extern "C" u32 THISCALL ext_5f9130_thiscall3(u32, u32, u32) __asm__("ext_5f9130");
extern "C" u32 THISCALL ext_5f9260_thiscall1(u32) __asm__("ext_5f9260");
extern "C" u32 THISCALL ext_5fbb00_thiscall3(u32, u32, u32) __asm__("ext_5fbb00");
extern "C" u32 THISCALL ext_5ffb00_thiscall2(u32, u32) __asm__("ext_5ffb00");
extern "C" u32 THISCALL ext_600800_thiscall1(u32) __asm__("ext_600800");
extern "C" u32 THISCALL ext_602cd0_thiscall2(u32, u32) __asm__("ext_602cd0");
extern "C" u32 THISCALL ext_633654_thiscall1(u32) __asm__("ext_633654");
extern "C" u32 THISCALL lifted_5f56f0(u32 ecx_in) {
  u8 F[0x800] __attribute__((aligned(16)));
  for (int k = 0; k < 0x800; k++) F[k] = 0xa5;
  u32 esp = (u32)(F + 0x700), ebp = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 cf = 0, zf = 0, sf = 0, of = 0, pf = 0;
  u32 X[8][4] = {};
  /*5f56f0*/ { u32 v = ebp; esp -= 4; st32(esp, v); }
  /*5f56f1*/ { u32 v = esp; ebp = v; }
  /*5f56f3*/ { u32 a = (u32)esp; u32 b = (u32)(u32)284U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f56f9*/ { u32 v = (u32)ld32((u32)((u32)7296560)); eax = v; }
  /*5f56fe*/ { u32 a = (u32)eax; u32 b = (u32)ebp; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f5700*/ { u32 v = eax; st32((u32)(ebp + (u32)(-4)), v); }
  /*5f5703*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f5704*/ { u32 v = edi; esp -= 4; st32(esp, v); }
  /*5f5705*/ { u32 v = ecx; edi = v; }
  /*5f5707*/ { u32 v = (u32)34816U; eax = v; }
  /*5f570c*/ { u32 v = edi; st32((u32)(ebp + (u32)(-136)), v); }
  /*5f5712*/ { u32 v = (u32)65521U; esi = v; }
  /*5f5717*/ { u32 v = (u32)0U; st32((u32)(edi + (u32)14), v); }
  /*5f571e*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5725*/ if (!zf) goto L5f579a;
  /*5f5727*/ { u32 v = (u32)ld8((u32)(edi + (u32)172)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f572d*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffffff00u) | ((r) & 0xff); }
  /*5f572f*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)4U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5731*/ if (zf) goto L5f8be6;
  /*5f5737*/ { u32 v = (u32)ld32((u32)(edi + (u32)4)); eax = v; }
  /*5f573a*/ { X[0][0] = ld32((u32)(edi + (u32)10)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f573f*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f5744*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); ecx = v; }
  /*5f5747*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f5749*/ { u32 v = (u32)ld32((u32)(eax + (u32)4)); eax = v; }
  /*5f574c*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f574e*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5753*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-128))) :: "st", "memory");
  /*5f5756*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-128)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f575a*/ if (!cf && !zf) goto L5f8be6;
  /*5f5760*/ { u32 v = (u32)ld8((u32)(edi + (u32)172)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f5766*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffffff00u) | ((r) & 0xff); }
  /*5f5768*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)5U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f576a*/ if (!zf) goto L5f5781;
  /*5f576c*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f5773*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f5776*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)1U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f577a*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  L5f5781:;
  /*5f5781*/ { u32 ea = (u32)(edi + (u32)84); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5785*/ if (zf) goto L5f578e;
  /*5f5787*/ { u32 v = edi; ecx = v; }
  /*5f5789*/ eax = ext_5f4ac0_thiscall1(ecx);
  L5f578e:;
  /*5f578e*/ { u32 v = (u32)8192U; eax = v; }
  /*5f5793*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); st16(ea, r); }
  L5f579a:;
  /*5f579a*/ { u32 v = (u32)ld16((u32)(edi + (u32)8)); eax = v; }
  /*5f579e*/ { u32 a = (u32)edx; u32 b = (u32)edx; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); edx = r; }
  /*5f57a0*/ { u32 ea = (u32)(edi + (u32)172); u8 a = ld8(ea); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f57a7*/ { u32 v = edx; ecx = v; }
  /*5f57a9*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-124)), v); }
  /*5f57b0*/ if (!zf) { ecx = eax; }
  /*5f57b3*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-120)), v); }
  /*5f57b7*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-176)), v); }
  /*5f57c1*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-172)), v); }
  /*5f57c8*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-141)), v); }
  /*5f57cf*/ { u32 v = edx; st32((u32)(ebp + (u32)(-116)), v); }
  /*5f57d2*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f57d5*/ goto L5f57f3;
  L5f57d7:;
  /*5f57d7*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f57d8*/ ecx = (u32)(edi + (u32)52);
  /*5f57db*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f57db*/ esp += 4;
  L5f57e0:;
  /*5f57e0*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  L5f57e7:;
  /*5f57e7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  L5f57f0:;
  /*5f57f0*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  L5f57f3:;
  /*5f57f3*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = v; }
  /*5f57fa*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f57fc*/ if (zf) goto L5f5824;
  /*5f57fe*/ { u32 a = (u32)eax; u32 b = (u32)(u32)34816U; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5803*/ { eax = (eax & 0xffffff00u) | (((zf) ? 1 : 0) & 0xff); }
  /*5f5806*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(eax & 0xff); u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5808*/ if (zf) goto L5f5824;
  /*5f580a*/ { u32 a = (u32)ecx; u32 b = (u32)ecx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f580c*/ if (zf || sf != of) goto L5f5814;
  /*5f580e*/ { u32 a = (u32)ecx; u32 r = alu_dec<u32>(a, cf, zf, sf, of, pf); ecx = r; }
  /*5f580f*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f5812*/ goto L5f581c;
  L5f5814:;
  /*5f5814*/ { u32 a = (u32)edx; u32 b = (u32)edx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5816*/ if (zf || sf != of) goto L5f8bb6;
  L5f581c:;
  /*5f581c*/ { u32 a = (u32)edx; u32 b = (u32)edx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f581e*/ if (zf) goto L5f5824;
  /*5f5820*/ { u32 a = (u32)edx; u32 r = alu_dec<u32>(a, cf, zf, sf, of, pf); edx = r; }
  /*5f5821*/ { u32 v = edx; st32((u32)(ebp + (u32)(-116)), v); }
  L5f5824:;
  /*5f5824*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f5826*/ { u32 v = edi; ecx = v; }
  /*5f5828*/ { u32 ea = (u32)(edi + (u32)14); u32 a = ld32(ea); u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f582b*/ { u32 v = (u32)ld32((u32)(eax + (u32)40)); eax = v; }
  /*5f582e*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f5830*/ { u32 v = eax; st32((u32)(edi + (u32)2758), v); }
  /*5f5836*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f583c*/ { u32 v = (u32)ld8((u32)(eax)); edx = v; }
  /*5f583f*/ esi = (u32)(eax + (u32)1);
  /*5f5842*/ { u32 v = edx; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f5845*/ { u32 v = esi; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5848*/ { u32 v = esi; st32((u32)(edi + (u32)166), v); }
  /*5f584e*/ { u32 a = (u32)edx; u32 b = (u32)(u32)158U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5854*/ if (!cf && !zf) goto L5f8a77;
  /*5f585a*/ switch (edx) {
    case 0: goto L5f57e7;
    case 1: goto L5f5891;
    case 2: goto L5f58b2;
    case 3: goto L5f58e9;
    case 4: goto L5f595a;
    case 5: goto L5f5981;
    case 6: goto L5f59a7;
    case 7: goto L5f59e9;
    case 8: goto L5f5a2f;
    case 9: goto L5f5a48;
    case 10: goto L5f5a67;
    case 11: goto L5f5a86;
    case 12: goto L5f5a98;
    case 13: goto L5f5acb;
    case 14: goto L5f5b51;
    case 15: goto L5f5b82;
    case 16: goto L5f5ba1;
    case 17: goto L5f5bd2;
    case 18: goto L5f5bf1;
    case 19: goto L5f5c22;
    case 20: goto L5f5c42;
    case 21: goto L5f5c9a;
    case 22: goto L5f5ce7;
    case 23: goto L5f5ebc;
    case 24: goto L5f5ce7;
    case 25: goto L5f5ebc;
    case 26: goto L5f5ce7;
    case 27: goto L5f5ebc;
    case 28: goto L5f5ce7;
    case 29: goto L5f5ebc;
    case 30: goto L5f6056;
    case 31: goto L5f6214;
    case 32: goto L5f6056;
    case 33: goto L5f6214;
    case 34: goto L5f6056;
    case 35: goto L5f6214;
    case 36: goto L5f6056;
    case 37: goto L5f6214;
    case 38: goto L5f640d;
    case 39: goto L5f6456;
    case 40: goto L5f649f;
    case 41: goto L5f6519;
    case 42: goto L5f6592;
    case 43: goto L5f5861;
    case 44: goto L5f65b9;
    case 45: goto L5f65ff;
    case 46: goto L5f6645;
    case 47: goto L5f66be;
    case 48: goto L5f66fd;
    case 49: goto L5f673a;
    case 50: goto L5f677b;
    case 51: goto L5f67d6;
    case 52: goto L5f6808;
    case 53: goto L5f683a;
    case 54: goto L5f6897;
    case 55: goto L5f6903;
    case 56: goto L5f696c;
    case 57: goto L5f69db;
    case 58: goto L5f6a23;
    case 59: goto L5f6a8f;
    case 60: goto L5f6afc;
    case 61: goto L5f6b87;
    case 62: goto L5f6bf0;
    case 63: goto L5f6c5a;
    case 64: goto L5f6cc0;
    case 65: goto L5f6df0;
    case 66: goto L5f6cc0;
    case 67: goto L5f6df0;
    case 68: goto L5f6cc0;
    case 69: goto L5f6df0;
    case 70: goto L5f6cc0;
    case 71: goto L5f6df0;
    case 72: goto L5f6f3e;
    case 73: goto L5f6fbf;
    case 74: goto L5f7017;
    case 75: goto L5f587e;
    case 76: goto L5f7045;
    case 77: goto L5f7a5c;
    case 78: goto L5f7068;
    case 79: goto L5f70b7;
    case 80: goto L5f70d6;
    case 81: goto L5f70f8;
    case 82: goto L5f7127;
    case 83: goto L5f7136;
    case 84: goto L5f7173;
    case 85: goto L5f719c;
    case 86: goto L5f71c5;
    case 87: goto L5f71ee;
    case 88: goto L5f7217;
    case 89: goto L5f7240;
    case 90: goto L5f7269;
    case 91: goto L5f729b;
    case 92: goto L5f72cd;
    case 93: goto L5f72ff;
    case 94: goto L5f7331;
    case 95: goto L5f7367;
    case 96: goto L5f738c;
    case 97: goto L5f73f1;
    case 98: goto L5f7435;
    case 99: goto L5f7488;
    case 100: goto L5f74cb;
    case 101: goto L5f7522;
    case 102: goto L5f7559;
    case 103: goto L5f75d9;
    case 104: goto L5f760f;
    case 105: goto L5f7631;
    case 106: goto L5f7645;
    case 107: goto L5f76b3;
    case 108: goto L5f7739;
    case 109: goto L5f77b9;
    case 110: goto L5f7887;
    case 111: goto L5f7952;
    case 112: goto L5f7982;
    case 113: goto L5f79f7;
    case 114: goto L5f7a0b;
    case 115: goto L5f7a2e;
    case 116: goto L5f7a47;
    case 117: goto L5f7a63;
    case 118: goto L5f7a8c;
    case 119: goto L5f7a9d;
    case 120: goto L5f7b02;
    case 121: goto L5f7b36;
    case 122: goto L5f8b93;
    case 123: goto L5f8bb6;
    case 124: goto L5f7b80;
    case 125: goto L5f7b9d;
    case 126: goto L5f7c60;
    case 127: goto L5f804d;
    case 128: goto L5f80ed;
    case 129: goto L5f667b;
    case 130: goto L5f7f7b;
    case 131: goto L5f8a77;
    case 132: goto L5f8a77;
    case 133: goto L5f8191;
    case 134: goto L5f84fc;
    case 135: goto L5f66be;
    case 136: goto L5f8570;
    case 137: goto L5f8570;
    case 138: goto L5f8570;
    case 139: goto L5f8570;
    case 140: goto L5f86d9;
    case 141: goto L5f86d9;
    case 142: goto L5f86d9;
    case 143: goto L5f86d9;
    case 144: goto L5f889b;
    case 145: goto L5f892a;
    case 146: goto L5f893c;
    case 147: goto L5f8971;
    case 148: goto L5f5861;
    case 149: goto L5f7c6b;
    case 150: goto L5f7e2f;
    case 151: goto L5f801f;
    case 152: goto L5f8987;
    case 153: goto L5f89d2;
    case 154: goto L5f89e4;
    case 155: goto L5f89f6;
    case 156: goto L5f8a4e;
    case 157: goto L5f57e7;
    case 158: goto L5f8bb6;
    default: __builtin_trap(); }
  L5f5861:;
  /*5f5861*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f5863*/ ecx = (u32)(edi + (u32)52);
  /*5f5866*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5869*/ eax = (u32)(ebp + (u32)(-108));
  /*5f586c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f586d*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f586d*/ esp += 4;
  /*5f5872*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5879*/ goto L5f57e7;
  L5f587e:;
  /*5f587e*/ ecx = (u32)(edi + (u32)64);
  /*5f5881*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5886*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f588c*/ goto L5f57e7;
  L5f5891:;
  /*5f5891*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f5894*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5897*/ if (!sf) goto L5f58a2;
  /*5f5899*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f58a0*/ goto L5f58c1;
  L5f58a2:;
  /*5f58a2*/ { u32 v = eax; ecx = v; }
  /*5f58a4*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f58aa*/ { u32 ea = (u32)(eax + ecx); u32 a = ld32(ea); u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f58ad*/ goto L5f57e0;
  L5f58b2:;
  /*5f58b2*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f58b5*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f58b8*/ if (!sf) goto L5f58d9;
  /*5f58ba*/ { u32 v = (u32)4294967295U; st32((u32)(ebp + (u32)(-108)), v); }
  L5f58c1:;
  /*5f58c1*/ ecx = (u32)(ebp + (u32)(-108));
  /*5f58c4*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f58c5*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f58c6*/ { u32 v = edi; ecx = v; }
  /*5f58c8*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f58c8*/ esp += 4;
  /*5f58cd*/ { u32 v = eax; ecx = v; }
  /*5f58cf*/ eax = ext_5f3d40_thiscall2(ecx, ld32(esp + 0));
  /*5f58cf*/ esp += 4;
  /*5f58d4*/ goto L5f57e0;
  L5f58d9:;
  /*5f58d9*/ { u32 v = eax; ecx = v; }
  /*5f58db*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f58e1*/ { u32 ea = (u32)(eax + ecx); u32 a = ld32(ea); u32 r = alu_dec<u32>(a, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f58e4*/ goto L5f57e0;
  L5f58e9:;
  /*5f58e9*/ eax = (u32)(ebp + (u32)(-124));
  /*5f58ec*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f58ed*/ ecx = (u32)(edi + (u32)52);
  /*5f58f0*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f58f0*/ esp += 4;
  /*5f58f5*/ { u32 v = (u32)ld8((u32)(ebp + (u32)(-120))); eax = v; }
  /*5f58f9*/ { u32 a = (u32)eax; u32 b = (u32)(u32)1U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f58fc*/ if (zf) goto L5f594d;
  /*5f58fe*/ { u32 a = (u32)eax; u32 b = (u32)(u32)1U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f5901*/ if (zf) goto L5f5919;
  /*5f5903*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f5908*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f590a*/ if (zf) goto L5f5913;
  /*5f590c*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f590e*/ goto L5f57e7;
  L5f5913:;
  /*5f5913*/ __builtin_trap();
  L5f5919:;
  /*5f5919*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f591e*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5925*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f5926*/ { u32 a = (u32)edx; u32 b = (u32)edx; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); edx = r; }
  /*5f5928*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f592b*/ { u32 v = (u32)1U; eax = v; }
  /*5f5930*/ if (!pf) { edx = eax; }
  /*5f5933*/ { u32 v = edx; st32((u32)(ebp + (u32)(-108)), v); }
  L5f5936:;
  /*5f5936*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5939*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f593a*/ ecx = (u32)(edi + (u32)52);
  /*5f593d*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f593d*/ esp += 4;
  /*5f5942*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5945*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5948*/ goto L5f57f3;
  L5f594d:;
  /*5f594d*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f594f*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5952*/ { eax = (eax & 0xffffff00u) | (((zf) ? 1 : 0) & 0xff); }
  /*5f5955*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5958*/ goto L5f5936;
  L5f595a:;
  /*5f595a*/ eax = (u32)(ebp + (u32)(-124));
  /*5f595d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f595e*/ ecx = (u32)(edi + (u32)52);
  /*5f5961*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5961*/ esp += 4;
  /*5f5966*/ ecx = (u32)(edi + (u32)52);
  /*5f5969*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f596e*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5970*/ if (zf) goto L5f599e;
  /*5f5972*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5976*/ if (zf) goto L5f599e;
  L5f5978:;
  /*5f5978*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f597f*/ goto L5f5936;
  L5f5981:;
  /*5f5981*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5984*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5985*/ ecx = (u32)(edi + (u32)52);
  /*5f5988*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5988*/ esp += 4;
  /*5f598d*/ ecx = (u32)(edi + (u32)52);
  /*5f5990*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5995*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5997*/ if (!zf) goto L5f5978;
  /*5f5999*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f599c*/ if (!zf) goto L5f5978;
  L5f599e:;
  /*5f599e*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f59a5*/ goto L5f5936;
  L5f59a7:;
  /*5f59a7*/ eax = (u32)(ebp + (u32)(-124));
  /*5f59aa*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f59ab*/ ecx = (u32)(edi + (u32)52);
  /*5f59ae*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f59ae*/ esp += 4;
  /*5f59b3*/ ecx = (u32)(edi + (u32)52);
  /*5f59b6*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f59bb*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f59be*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f59c3*/ { for (int k = 0; k < 4; k++) X[1][k] ^= X[1][k]; }
  /*5f59c6*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f59c9*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f59ca*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f59cd*/ if (pf) goto L5f5978;
  /*5f59cf*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f59d4*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f59d7*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f59d8*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f59db*/ if (pf) goto L5f5978;
  /*5f59dd*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f59e4*/ goto L5f5936;
  L5f59e9:;
  /*5f59e9*/ eax = (u32)(ebp + (u32)(-124));
  /*5f59ec*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f59ed*/ ecx = (u32)(edi + (u32)52);
  /*5f59f0*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f59f0*/ esp += 4;
  /*5f59f5*/ ecx = (u32)(edi + (u32)52);
  /*5f59f8*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f59fd*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f5a00*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5a05*/ { for (int k = 0; k < 4; k++) X[1][k] ^= X[1][k]; }
  /*5f5a08*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5a0b*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f5a0c*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5a0f*/ if (!pf) goto L5f599e;
  /*5f5a11*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5a16*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  L5f5a19:;
  /*5f5a19*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f5a1a*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5a1d*/ if (!pf) goto L5f599e;
  /*5f5a23*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5a2a*/ goto L5f5936;
  L5f5a2f:;
  /*5f5a2f*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5a32*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5a33*/ ecx = (u32)(edi + (u32)52);
  /*5f5a36*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5a36*/ esp += 4;
  /*5f5a3b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); eax = v; }
  /*5f5a3e*/ { u32 r = (u32)~eax; eax = r; }
  /*5f5a40*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5a43*/ goto L5f5936;
  L5f5a48:;
  /*5f5a48*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5a4b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5a4c*/ ecx = (u32)(edi + (u32)52);
  /*5f5a4f*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5a4f*/ esp += 4;
  /*5f5a54*/ ecx = (u32)(edi + (u32)52);
  /*5f5a57*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5a5c*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f5a5f*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5a62*/ goto L5f5936;
  L5f5a67:;
  /*5f5a67*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5a6a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5a6b*/ ecx = (u32)(edi + (u32)52);
  /*5f5a6e*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5a6e*/ esp += 4;
  /*5f5a73*/ ecx = (u32)(edi + (u32)52);
  /*5f5a76*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5a7b*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_or<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f5a7e*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5a81*/ goto L5f5936;
  L5f5a86:;
  /*5f5a86*/ ecx = (u32)(edi + (u32)52);
  /*5f5a89*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5a8e*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f5a90*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5a93*/ goto L5f5936;
  L5f5a98:;
  /*5f5a98*/ ecx = (u32)(edi + (u32)52);
  /*5f5a9b*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f5aa0*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f5aa3*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5aa8*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5aab*/ { u32 ea = (u32)((u32)6795072); for (int k = 0; k < 4; k++) X[0][k] ^= ld32(ea + 4 * k); }
  /*5f5ab2*/ ecx = (u32)(edi + (u32)52);
  /*5f5ab5*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5ab6*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f5abb*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f5abb*/ esp += 4;
  /*5f5ac0*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5ac3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5ac6*/ goto L5f57f3;
  L5f5acb:;
  /*5f5acb*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5ace*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5acf*/ ecx = (u32)(edi + (u32)52);
  /*5f5ad2*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5ad2*/ esp += 4;
  /*5f5ad7*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f5adc*/ { float a = U2F(X[1][0]); float b = U2F(ld32((u32)((u32)6785112))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5ae3*/ if (cf || zf) goto L5f5afd;
  /*5f5ae5*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5ae8*/ { u32 v = (u32)1065353216U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5aef*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5af0*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f5af3*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f5af3*/ esp += 4;
  /*5f5af8*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  L5f5afd:;
  /*5f5afd*/ { for (int k = 0; k < 4; k++) X[0][k] ^= X[0][k]; }
  /*5f5b00*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5b03*/ if (cf || zf) goto L5f5b1d;
  /*5f5b05*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5b08*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5b0f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5b10*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f5b13*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f5b13*/ esp += 4;
  /*5f5b18*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  L5f5b1d:;
  /*5f5b1d*/ { X[0][0] = ld32((u32)((u32)6785112)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5b25*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5b28*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) - b); }
  /*5f5b2c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5b2d*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f5b30*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f5b35*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f5b35*/ esp += 4;
  /*5f5b3a*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5b3d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5b3e*/ ecx = (u32)(edi + (u32)52);
  /*5f5b41*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f5b41*/ esp += 4;
  /*5f5b46*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5b49*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5b4c*/ goto L5f57f3;
  L5f5b51:;
  /*5f5b51*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5b54*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5b55*/ ecx = (u32)(edi + (u32)52);
  /*5f5b58*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5b58*/ esp += 4;
  /*5f5b5d*/ ecx = (u32)(edi + (u32)52);
  /*5f5b60*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f5b65*/ __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebp + (u32)(-124))) : "st", "memory");
  /*5f5b68*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5b6b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5b6c*/ ecx = (u32)(edi + (u32)52);
  /*5f5b6f*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f5b72*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f5b72*/ esp += 4;
  /*5f5b77*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5b7a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5b7d*/ goto L5f57f3;
  L5f5b82:;
  /*5f5b82*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5b85*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5b86*/ ecx = (u32)(edi + (u32)52);
  /*5f5b89*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5b89*/ esp += 4;
  /*5f5b8e*/ ecx = (u32)(edi + (u32)52);
  /*5f5b91*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5b96*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f5b99*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5b9c*/ goto L5f5936;
  L5f5ba1:;
  /*5f5ba1*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5ba4*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5ba5*/ ecx = (u32)(edi + (u32)52);
  /*5f5ba8*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5ba8*/ esp += 4;
  /*5f5bad*/ ecx = (u32)(edi + (u32)52);
  /*5f5bb0*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f5bb5*/ __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(ebp + (u32)(-124))) : "st", "memory");
  /*5f5bb8*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5bbb*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5bbc*/ ecx = (u32)(edi + (u32)52);
  /*5f5bbf*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f5bc2*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f5bc2*/ esp += 4;
  /*5f5bc7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5bca*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5bcd*/ goto L5f57f3;
  L5f5bd2:;
  /*5f5bd2*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5bd5*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5bd6*/ ecx = (u32)(edi + (u32)52);
  /*5f5bd9*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5bd9*/ esp += 4;
  /*5f5bde*/ ecx = (u32)(edi + (u32)52);
  /*5f5be1*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5be6*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f5be9*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5bec*/ goto L5f5936;
  L5f5bf1:;
  /*5f5bf1*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5bf4*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5bf5*/ ecx = (u32)(edi + (u32)52);
  /*5f5bf8*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5bf8*/ esp += 4;
  /*5f5bfd*/ ecx = (u32)(edi + (u32)52);
  /*5f5c00*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f5c05*/ __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(ebp + (u32)(-124))) : "st", "memory");
  /*5f5c08*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5c0b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5c0c*/ ecx = (u32)(edi + (u32)52);
  /*5f5c0f*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f5c12*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f5c12*/ esp += 4;
  /*5f5c17*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5c1a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5c1d*/ goto L5f57f3;
  L5f5c22:;
  /*5f5c22*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5c25*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5c26*/ ecx = (u32)(edi + (u32)52);
  /*5f5c29*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5c29*/ esp += 4;
  /*5f5c2e*/ ecx = (u32)(edi + (u32)52);
  /*5f5c31*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5c36*/ { s32 a = (s32)eax, b = (s32)(u32)ld32((u32)(ebp + (u32)(-124))); s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f5c3a*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5c3d*/ goto L5f5936;
  L5f5c42:;
  /*5f5c42*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5c45*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5c46*/ ecx = (u32)(edi + (u32)52);
  /*5f5c49*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5c49*/ esp += 4;
  /*5f5c4e*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5c53*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5c5a*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f5c5b*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5c5e*/ if (pf) goto L5f5c75;
  /*5f5c60*/ { u32 v = edi; ecx = v; }
  /*5f5c62*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f5c67*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f5c6c*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5c6e*/ if (zf) goto L5f5c74;
  /*5f5c70*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f5c72*/ goto L5f5c75;
  L5f5c74:;
  /*5f5c74*/ __builtin_trap();
  L5f5c75:;
  /*5f5c75*/ ecx = (u32)(edi + (u32)52);
  /*5f5c78*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f5c7d*/ __asm__ volatile("fdivs %0" :: "m"(*(float *)(u32)(ebp + (u32)(-124))) : "st", "memory");
  /*5f5c80*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5c83*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5c84*/ ecx = (u32)(edi + (u32)52);
  /*5f5c87*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f5c8a*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f5c8a*/ esp += 4;
  /*5f5c8f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5c92*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5c95*/ goto L5f57f3;
  L5f5c9a:;
  /*5f5c9a*/ eax = (u32)(ebp + (u32)(-124));
  /*5f5c9d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5c9e*/ ecx = (u32)(edi + (u32)52);
  /*5f5ca1*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f5ca1*/ esp += 4;
  /*5f5ca6*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5caa*/ if (!zf) goto L5f5cd3;
  /*5f5cac*/ { u32 v = edi; ecx = v; }
  /*5f5cae*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f5cb3*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f5cb8*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5cba*/ if (zf) goto L5f5cd2;
  /*5f5cbc*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f5cbe*/ ecx = (u32)(edi + (u32)52);
  /*5f5cc1*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5cc6*/ edx = (u32)((s32)eax >> 31);
  /*5f5cc7*/ { u32 d = (u32)ld32((u32)(ebp + (u32)(-124))); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f5cca*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5ccd*/ goto L5f5936;
  L5f5cd2:;
  /*5f5cd2*/ __builtin_trap();
  L5f5cd3:;
  /*5f5cd3*/ ecx = (u32)(edi + (u32)52);
  /*5f5cd6*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f5cdb*/ edx = (u32)((s32)eax >> 31);
  /*5f5cdc*/ { u32 d = (u32)ld32((u32)(ebp + (u32)(-124))); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f5cdf*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5ce2*/ goto L5f5936;
  L5f5ce7:;
  /*5f5ce7*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f5cea*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967274U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); edx = r; }
  /*5f5ced*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f5cf0*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5cf3*/ if (!sf) goto L5f5dd4;
  /*5f5cf9*/ { u32 a = (u32)edx; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5cfc*/ if (!cf && !zf) goto L5f5eaa;
  /*5f5d02*/ switch (edx) {
    case 0: goto L5f5d09;
    case 1: goto L5f5eaa;
    case 2: goto L5f5d38;
    case 3: goto L5f5eaa;
    case 4: goto L5f5d46;
    case 5: goto L5f5eaa;
    case 6: goto L5f5d75;
    default: __builtin_trap(); }
  L5f5d09:;
  /*5f5d09*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  L5f5d0e:;
  /*5f5d0e*/ ecx = (u32)(ebp + (u32)(-108));
  /*5f5d11*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f5d16*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f5d17*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5d18*/ { u32 v = edi; ecx = v; }
  /*5f5d1a*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f5d1a*/ esp += 4;
  /*5f5d1f*/ { u32 v = eax; ecx = v; }
  /*5f5d21*/ eax = ext_5f3db0_thiscall2(ecx, ld32(esp + 0));
  /*5f5d21*/ esp += 4;
  /*5f5d26*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5d2d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5d30*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5d33*/ goto L5f57f3;
  L5f5d38:;
  /*5f5d38*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5d3d*/ { u32 ea = (u32)((u32)6795072); for (int k = 0; k < 4; k++) X[0][k] ^= ld32(ea + 4 * k); }
  /*5f5d44*/ goto L5f5d0e;
  L5f5d46:;
  /*5f5d46*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5d4b*/ ecx = (u32)(ebp + (u32)(-108));
  /*5f5d4e*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f5d4f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5d50*/ { u32 v = edi; ecx = v; }
  /*5f5d52*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f5d57*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f5d57*/ esp += 4;
  /*5f5d5c*/ { u32 v = eax; ecx = v; }
  /*5f5d5e*/ eax = ext_5f4e60_thiscall2(ecx, ld32(esp + 0));
  /*5f5d5e*/ esp += 4;
  /*5f5d63*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5d6a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5d6d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5d70*/ goto L5f57f3;
  L5f5d75:;
  /*5f5d75*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5d7a*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5d81*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f5d82*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5d85*/ if (pf) goto L5f5d9c;
  /*5f5d87*/ { u32 v = edi; ecx = v; }
  /*5f5d89*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f5d8e*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f5d93*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5d95*/ if (zf) goto L5f5d9b;
  /*5f5d97*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f5d99*/ goto L5f5d9c;
  L5f5d9b:;
  /*5f5d9b*/ __builtin_trap();
  L5f5d9c:;
  /*5f5d9c*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f5da2*/ { u32 v = edi; ecx = v; }
  /*5f5da4*/ { X[0][0] = ld32((u32)(eax + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5da9*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5dac*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5dad*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f5db0*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5db1*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f5db6*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f5db6*/ esp += 4;
  /*5f5dbb*/ { u32 v = eax; ecx = v; }
  /*5f5dbd*/ eax = ext_5f4110_thiscall2(ecx, ld32(esp + 0));
  /*5f5dbd*/ esp += 4;
  /*5f5dc2*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5dc9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5dcc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5dcf*/ goto L5f57f3;
  L5f5dd4:;
  /*5f5dd4*/ { u32 a = (u32)edx; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5dd7*/ if (!cf && !zf) goto L5f5eaa;
  /*5f5ddd*/ switch (edx) {
    case 0: goto L5f5de4;
    case 1: goto L5f5eaa;
    case 2: goto L5f5e0e;
    case 3: goto L5f5eaa;
    case 4: goto L5f5e38;
    case 5: goto L5f5eaa;
    case 6: goto L5f5e62;
    default: __builtin_trap(); }
  L5f5de4:;
  /*5f5de4*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5de9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5dec*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f5def*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f5df5*/ { float b = U2F(ld32((u32)(eax + ecx))); X[0][0] = F2U(U2F(X[0][0]) + b); }
  /*5f5dfa*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f5dff*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5e06*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5e09*/ goto L5f57f3;
  L5f5e0e:;
  /*5f5e0e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5e11*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f5e14*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f5e1a*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5e1f*/ { float b = U2F(ld32((u32)(esi + (u32)2))); X[0][0] = F2U(U2F(X[0][0]) - b); }
  /*5f5e24*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f5e29*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5e30*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5e33*/ goto L5f57f3;
  L5f5e38:;
  /*5f5e38*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5e3d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5e40*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f5e43*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f5e49*/ { float b = U2F(ld32((u32)(eax + ecx))); X[0][0] = F2U(U2F(X[0][0]) * b); }
  /*5f5e4e*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f5e53*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5e5a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5e5d*/ goto L5f57f3;
  L5f5e62:;
  /*5f5e62*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5e67*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f5e6e*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f5e6f*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5e72*/ if (pf) goto L5f5e89;
  /*5f5e74*/ { u32 v = edi; ecx = v; }
  /*5f5e76*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f5e7b*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f5e80*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5e82*/ if (zf) goto L5f5e88;
  /*5f5e84*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f5e86*/ goto L5f5e89;
  L5f5e88:;
  /*5f5e88*/ __builtin_trap();
  L5f5e89:;
  /*5f5e89*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f5e8c*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f5e92*/ { u32 v = (eax & 0xffff); edx = v; }
  /*5f5e95*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f5e9b*/ { X[0][0] = ld32((u32)(ecx + edx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f5ea0*/ { float b = U2F(ld32((u32)(eax + (u32)2))); X[0][0] = F2U(U2F(X[0][0]) / b); }
  /*5f5ea5*/ st32((u32)(ecx + edx), X[0][0]);
  L5f5eaa:;
  /*5f5eaa*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5eb1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5eb4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5eb7*/ goto L5f57f3;
  L5f5ebc:;
  /*5f5ebc*/ { u32 v = (u32)ld16((u32)(esi)); ecx = v; }
  /*5f5ebf*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967273U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); edx = r; }
  /*5f5ec2*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f5ec5*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5ec8*/ if (!sf) goto L5f5f8a;
  /*5f5ece*/ { u32 a = (u32)edx; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5ed1*/ if (!cf && !zf) goto L5f6044;
  /*5f5ed7*/ switch (edx) {
    case 0: goto L5f5ede;
    case 1: goto L5f6044;
    case 2: goto L5f5f09;
    case 3: goto L5f6044;
    case 4: goto L5f5f10;
    case 5: goto L5f6044;
    case 6: goto L5f5f3b;
    default: __builtin_trap(); }
  L5f5ede:;
  /*5f5ede*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  L5f5ee1:;
  /*5f5ee1*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5ee4*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5ee7*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5ee8*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f5ee9*/ { u32 v = edi; ecx = v; }
  /*5f5eeb*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f5eeb*/ esp += 4;
  /*5f5ef0*/ { u32 v = eax; ecx = v; }
  /*5f5ef2*/ eax = ext_5f3d40_thiscall2(ecx, ld32(esp + 0));
  /*5f5ef2*/ esp += 4;
  /*5f5ef7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5efe*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5f01*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5f04*/ goto L5f57f3;
  L5f5f09:;
  /*5f5f09*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f5f0c*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f5f0e*/ goto L5f5ee1;
  L5f5f10:;
  /*5f5f10*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f5f13*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5f16*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5f19*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5f1a*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f5f1b*/ { u32 v = edi; ecx = v; }
  /*5f5f1d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f5f1d*/ esp += 4;
  /*5f5f22*/ { u32 v = eax; ecx = v; }
  /*5f5f24*/ eax = ext_5f4e00_thiscall2(ecx, ld32(esp + 0));
  /*5f5f24*/ esp += 4;
  /*5f5f29*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5f30*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5f33*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5f36*/ goto L5f57f3;
  L5f5f3b:;
  /*5f5f3b*/ { u32 ea = (u32)(esi + (u32)2); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5f3f*/ if (!zf) goto L5f5f59;
  /*5f5f41*/ { u32 v = edi; ecx = v; }
  /*5f5f43*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f5f48*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f5f4d*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5f4f*/ if (zf) goto L5f5f55;
  /*5f5f51*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f5f53*/ goto L5f5f56;
  L5f5f55:;
  /*5f5f55*/ __builtin_trap();
  L5f5f56:;
  /*5f5f56*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  L5f5f59:;
  /*5f5f59*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f5f5f*/ { u32 v = (u32)ld32((u32)(eax + (u32)2)); eax = v; }
  /*5f5f62*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f5f65*/ eax = (u32)(ebp + (u32)(-108));
  /*5f5f68*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f5f69*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f5f6a*/ { u32 v = edi; ecx = v; }
  /*5f5f6c*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f5f6c*/ esp += 4;
  /*5f5f71*/ { u32 v = eax; ecx = v; }
  /*5f5f73*/ eax = ext_5f40b0_thiscall2(ecx, ld32(esp + 0));
  /*5f5f73*/ esp += 4;
  /*5f5f78*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5f7f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5f82*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5f85*/ goto L5f57f3;
  L5f5f8a:;
  /*5f5f8a*/ { u32 a = (u32)edx; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f5f8d*/ if (!cf && !zf) goto L5f6044;
  /*5f5f93*/ switch (edx) {
    case 0: goto L5f5f9a;
    case 1: goto L5f6044;
    case 2: goto L5f5fbb;
    case 3: goto L5f6044;
    case 4: goto L5f5fdc;
    case 5: goto L5f6044;
    case 6: goto L5f6001;
    default: __builtin_trap(); }
  L5f5f9a:;
  /*5f5f9a*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f5f9d*/ { u32 v = (ecx & 0xffff); edx = v; }
  /*5f5fa0*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f5fa6*/ { u32 ea = (u32)(ecx + edx); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5fa9*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5fb0*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5fb3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5fb6*/ goto L5f57f3;
  L5f5fbb:;
  /*5f5fbb*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f5fbe*/ { u32 v = (ecx & 0xffff); edx = v; }
  /*5f5fc1*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f5fc7*/ { u32 ea = (u32)(ecx + edx); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5fca*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5fd1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5fd4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5fd7*/ goto L5f57f3;
  L5f5fdc:;
  /*5f5fdc*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f5fdf*/ { u32 v = (ecx & 0xffff); edx = v; }
  /*5f5fe2*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f5fe8*/ { s32 a = (s32)eax, b = (s32)(u32)ld32((u32)(ecx + edx)); s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f5fec*/ { u32 v = eax; st32((u32)(ecx + edx), v); }
  /*5f5fef*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f5ff6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f5ff9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f5ffc*/ goto L5f57f3;
  L5f6001:;
  /*5f6001*/ { u32 ea = (u32)(esi + (u32)2); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6005*/ if (!zf) goto L5f601f;
  /*5f6007*/ { u32 v = edi; ecx = v; }
  /*5f6009*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f600e*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f6013*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6015*/ if (zf) goto L5f601b;
  /*5f6017*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f6019*/ goto L5f601c;
  L5f601b:;
  /*5f601b*/ __builtin_trap();
  L5f601c:;
  /*5f601c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  L5f601f:;
  /*5f601f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f6025*/ { u32 v = (ecx & 0xffff); edi = v; }
  /*5f6028*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f602e*/ { u32 v = (u32)ld32((u32)(eax + (u32)166)); ecx = v; }
  /*5f6034*/ { u32 v = (u32)ld32((u32)(esi + edi)); eax = v; }
  /*5f6037*/ edx = (u32)((s32)eax >> 31);
  /*5f6038*/ { u32 d = (u32)ld32((u32)(ecx + (u32)2)); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f603b*/ { u32 v = eax; st32((u32)(esi + edi), v); }
  /*5f603e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  L5f6044:;
  /*5f6044*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f604b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f604e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6051*/ goto L5f57f3;
  L5f6056:;
  /*5f6056*/ ecx = (u32)(edi + (u32)52);
  /*5f6059*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f605e*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f6061*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f6064*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4294967266U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f6067*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f606a*/ if (!sf) goto L5f613c;
  /*5f6070*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6073*/ if (!cf && !zf) goto L5f6202;
  /*5f6079*/ switch (eax) {
    case 0: goto L5f6080;
    case 1: goto L5f6202;
    case 2: goto L5f60b0;
    case 3: goto L5f6202;
    case 4: goto L5f60bc;
    case 5: goto L5f6202;
    case 6: goto L5f60ec;
    default: __builtin_trap(); }
  L5f6080:;
  /*5f6080*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6086*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  L5f6088:;
  /*5f6088*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f608b*/ eax = (u32)(ebp + (u32)(-108));
  /*5f608e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f608f*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  L5f6090:;
  /*5f6090*/ { u32 v = edi; ecx = v; }
  /*5f6092*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6092*/ esp += 4;
  /*5f6097*/ { u32 v = eax; ecx = v; }
  /*5f6099*/ eax = ext_5f3d40_thiscall2(ecx, ld32(esp + 0));
  /*5f6099*/ esp += 4;
  /*5f609e*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f60a5*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f60a8*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f60ab*/ goto L5f57f3;
  L5f60b0:;
  /*5f60b0*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f60b6*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f60b8*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f60ba*/ goto L5f6088;
  L5f60bc:;
  /*5f60bc*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f60c2*/ { u32 v = edi; ecx = v; }
  /*5f60c4*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f60c6*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f60c9*/ eax = (u32)(ebp + (u32)(-108));
  /*5f60cc*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f60cd*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f60ce*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f60ce*/ esp += 4;
  /*5f60d3*/ { u32 v = eax; ecx = v; }
  /*5f60d5*/ eax = ext_5f4e00_thiscall2(ecx, ld32(esp + 0));
  /*5f60d5*/ esp += 4;
  /*5f60da*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f60e1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f60e4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f60e7*/ goto L5f57f3;
  L5f60ec:;
  /*5f60ec*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f60f2*/ { u32 ea = (u32)(eax); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f60f5*/ if (!zf) goto L5f610c;
  /*5f60f7*/ { u32 v = edi; ecx = v; }
  /*5f60f9*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f60fe*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f6103*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6105*/ if (zf) goto L5f610b;
  /*5f6107*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f6109*/ goto L5f610c;
  L5f610b:;
  /*5f610b*/ __builtin_trap();
  L5f610c:;
  /*5f610c*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6112*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f6114*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f6117*/ eax = (u32)(ebp + (u32)(-108));
  L5f611a:;
  /*5f611a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f611b*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f611c*/ { u32 v = edi; ecx = v; }
  /*5f611e*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f611e*/ esp += 4;
  /*5f6123*/ { u32 v = eax; ecx = v; }
  /*5f6125*/ eax = ext_5f40b0_thiscall2(ecx, ld32(esp + 0));
  /*5f6125*/ esp += 4;
  /*5f612a*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6131*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6134*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6137*/ goto L5f57f3;
  L5f613c:;
  /*5f613c*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f613f*/ if (!cf && !zf) goto L5f6202;
  /*5f6145*/ switch (eax) {
    case 0: goto L5f614c;
    case 1: goto L5f6202;
    case 2: goto L5f6171;
    case 3: goto L5f6202;
    case 4: goto L5f6196;
    case 5: goto L5f6202;
    case 6: goto L5f61bf;
    default: __builtin_trap(); }
  L5f614c:;
  /*5f614c*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6152*/ { u32 v = esi; edx = v; }
  /*5f6154*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f615a*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f615c*/ { u32 ea = (u32)(ecx + edx); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f615f*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6166*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6169*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f616c*/ goto L5f57f3;
  L5f6171:;
  /*5f6171*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6177*/ { u32 v = esi; edx = v; }
  /*5f6179*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f617f*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f6181*/ { u32 ea = (u32)(ecx + edx); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6184*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f618b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f618e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6191*/ goto L5f57f3;
  L5f6196:;
  /*5f6196*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f619c*/ { u32 v = esi; edx = v; }
  /*5f619e*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f61a4*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f61a6*/ { s32 a = (s32)eax, b = (s32)(u32)ld32((u32)(ecx + edx)); s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f61aa*/ { u32 v = eax; st32((u32)(ecx + edx), v); }
  /*5f61ad*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f61b4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f61b7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f61ba*/ goto L5f57f3;
  L5f61bf:;
  /*5f61bf*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f61c5*/ { u32 ea = (u32)(eax); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f61c8*/ if (!zf) goto L5f61df;
  /*5f61ca*/ { u32 v = edi; ecx = v; }
  /*5f61cc*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f61d1*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f61d6*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f61d8*/ if (zf) goto L5f61de;
  /*5f61da*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f61dc*/ goto L5f61df;
  L5f61de:;
  /*5f61de*/ __builtin_trap();
  L5f61df:;
  /*5f61df*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f61e5*/ { u32 v = esi; edi = v; }
  /*5f61e7*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f61ed*/ { u32 v = (u32)ld32((u32)(eax + (u32)166)); ecx = v; }
  /*5f61f3*/ { u32 v = (u32)ld32((u32)(esi + edi)); eax = v; }
  /*5f61f6*/ edx = (u32)((s32)eax >> 31);
  /*5f61f7*/ { u32 d = (u32)ld32((u32)(ecx)); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f61f9*/ { u32 v = eax; st32((u32)(esi + edi), v); }
  /*5f61fc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  L5f6202:;
  /*5f6202*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6209*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f620c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f620f*/ goto L5f57f3;
  L5f6214:;
  /*5f6214*/ ecx = (u32)(edi + (u32)52);
  /*5f6217*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f621c*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f621f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f6222*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4294967265U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f6225*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6228*/ if (!sf) goto L5f6319;
  /*5f622e*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6231*/ if (!cf && !zf) goto L5f63fb;
  /*5f6237*/ switch (eax) {
    case 0: goto L5f623e;
    case 1: goto L5f63fb;
    case 2: goto L5f6272;
    case 3: goto L5f63fb;
    case 4: goto L5f6285;
    case 5: goto L5f63fb;
    case 6: goto L5f62b9;
    default: __builtin_trap(); }
  L5f623e:;
  /*5f623e*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6244*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  L5f6248:;
  /*5f6248*/ eax = (u32)(ebp + (u32)(-108));
  /*5f624b*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f6250*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6251*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6252*/ { u32 v = edi; ecx = v; }
  /*5f6254*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6254*/ esp += 4;
  /*5f6259*/ { u32 v = eax; ecx = v; }
  /*5f625b*/ eax = ext_5f3db0_thiscall2(ecx, ld32(esp + 0));
  /*5f625b*/ esp += 4;
  /*5f6260*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6267*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f626a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f626d*/ goto L5f57f3;
  L5f6272:;
  /*5f6272*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6278*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f627c*/ { u32 ea = (u32)((u32)6795072); for (int k = 0; k < 4; k++) X[0][k] ^= ld32(ea + 4 * k); }
  /*5f6283*/ goto L5f6248;
  L5f6285:;
  /*5f6285*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f628b*/ { u32 v = edi; ecx = v; }
  /*5f628d*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6291*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6294*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6295*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6296*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f629b*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f629b*/ esp += 4;
  /*5f62a0*/ { u32 v = eax; ecx = v; }
  /*5f62a2*/ eax = ext_5f4e60_thiscall2(ecx, ld32(esp + 0));
  /*5f62a2*/ esp += 4;
  /*5f62a7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f62ae*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f62b1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f62b4*/ goto L5f57f3;
  L5f62b9:;
  /*5f62b9*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f62bf*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f62c3*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f62ca*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f62cb*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f62ce*/ if (pf) goto L5f62e5;
  /*5f62d0*/ { u32 v = edi; ecx = v; }
  /*5f62d2*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f62d7*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f62dc*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f62de*/ if (zf) goto L5f62e4;
  /*5f62e0*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f62e2*/ goto L5f62e5;
  L5f62e4:;
  /*5f62e4*/ __builtin_trap();
  L5f62e5:;
  /*5f62e5*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f62eb*/ { u32 v = edi; ecx = v; }
  /*5f62ed*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f62f1*/ eax = (u32)(ebp + (u32)(-108));
  /*5f62f4*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f62f5*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f62f6*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f62fb*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f62fb*/ esp += 4;
  /*5f6300*/ { u32 v = eax; ecx = v; }
  /*5f6302*/ eax = ext_5f4110_thiscall2(ecx, ld32(esp + 0));
  /*5f6302*/ esp += 4;
  /*5f6307*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f630e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6311*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6314*/ goto L5f57f3;
  L5f6319:;
  /*5f6319*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f631c*/ if (!cf && !zf) goto L5f63fb;
  /*5f6322*/ switch (eax) {
    case 0: goto L5f6329;
    case 1: goto L5f63fb;
    case 2: goto L5f6357;
    case 3: goto L5f63fb;
    case 4: goto L5f6385;
    case 5: goto L5f63fb;
    case 6: goto L5f63b3;
    default: __builtin_trap(); }
  L5f6329:;
  /*5f6329*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f632f*/ { u32 v = esi; edx = v; }
  /*5f6331*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6337*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f633b*/ { float b = U2F(ld32((u32)(ecx + edx))); X[0][0] = F2U(U2F(X[0][0]) + b); }
  /*5f6340*/ st32((u32)(ecx + edx), X[0][0]);
  /*5f6345*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f634c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f634f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6352*/ goto L5f57f3;
  L5f6357:;
  /*5f6357*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f635d*/ { u32 v = esi; edx = v; }
  /*5f635f*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6365*/ { X[0][0] = ld32((u32)(ecx + edx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f636a*/ { float b = U2F(ld32((u32)(eax))); X[0][0] = F2U(U2F(X[0][0]) - b); }
  /*5f636e*/ st32((u32)(ecx + edx), X[0][0]);
  /*5f6373*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f637a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f637d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6380*/ goto L5f57f3;
  L5f6385:;
  /*5f6385*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f638b*/ { u32 v = esi; edx = v; }
  /*5f638d*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6393*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6397*/ { float b = U2F(ld32((u32)(ecx + edx))); X[0][0] = F2U(U2F(X[0][0]) * b); }
  /*5f639c*/ st32((u32)(ecx + edx), X[0][0]);
  /*5f63a1*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f63a8*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f63ab*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f63ae*/ goto L5f57f3;
  L5f63b3:;
  /*5f63b3*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f63b9*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f63bd*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f63c4*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f63c5*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f63c8*/ if (pf) goto L5f63df;
  /*5f63ca*/ { u32 v = edi; ecx = v; }
  /*5f63cc*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f63d1*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f63d6*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f63d8*/ if (zf) goto L5f63de;
  /*5f63da*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f63dc*/ goto L5f63df;
  L5f63de:;
  /*5f63de*/ __builtin_trap();
  L5f63df:;
  /*5f63df*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f63e5*/ { u32 v = esi; edx = v; }
  /*5f63e7*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f63ed*/ { X[0][0] = ld32((u32)(ecx + edx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f63f2*/ { float b = U2F(ld32((u32)(eax))); X[0][0] = F2U(U2F(X[0][0]) / b); }
  /*5f63f6*/ st32((u32)(ecx + edx), X[0][0]);
  L5f63fb:;
  /*5f63fb*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6402*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6405*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6408*/ goto L5f57f3;
  L5f640d:;
  /*5f640d*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6410*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6411*/ ecx = (u32)(edi + (u32)52);
  /*5f6414*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6414*/ esp += 4;
  /*5f6419*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f641b*/ ecx = (u32)(edi + (u32)52);
  /*5f641e*/ eax = ext_5f4ec0_thiscall2(ecx, ld32(esp + 0));
  /*5f641e*/ esp += 4;
  /*5f6423*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6428*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f642b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f642e*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6431*/ if (cf || zf) goto L5f57f3;
  /*5f6437*/ ecx = (u32)(edi + (u32)52);
  /*5f643a*/ eax = ext_5f4f70_thiscall1(ecx);
  /*5f643f*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6442*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6443*/ ecx = (u32)(edi + (u32)52);
  /*5f6446*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f6446*/ esp += 4;
  /*5f644b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f644e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6451*/ goto L5f57f3;
  L5f6456:;
  /*5f6456*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6459*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f645a*/ ecx = (u32)(edi + (u32)52);
  /*5f645d*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f645d*/ esp += 4;
  /*5f6462*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f6464*/ ecx = (u32)(edi + (u32)52);
  /*5f6467*/ eax = ext_5f4ec0_thiscall2(ecx, ld32(esp + 0));
  /*5f6467*/ esp += 4;
  /*5f646c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f646f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6472*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6476*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f647a*/ if (cf || zf) goto L5f57f3;
  /*5f6480*/ ecx = (u32)(edi + (u32)52);
  /*5f6483*/ eax = ext_5f4f70_thiscall1(ecx);
  /*5f6488*/ eax = (u32)(ebp + (u32)(-124));
  /*5f648b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f648c*/ ecx = (u32)(edi + (u32)52);
  /*5f648f*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f648f*/ esp += 4;
  /*5f6494*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6497*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f649a*/ goto L5f57f3;
  L5f649f:;
  /*5f649f*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f64a2*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f64a5*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f64a8*/ if (!sf) goto L5f64ee;
  /*5f64aa*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f64ab*/ { u32 v = edi; ecx = v; }
  /*5f64ad*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f64ad*/ esp += 4;
  /*5f64b2*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); ecx = v; }
  /*5f64b8*/ { X[0][0] = ld32((u32)(ecx + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f64bd*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f64c0*/ if (cf || zf) goto L5f6507;
  /*5f64c2*/ eax = (u32)(ebp + (u32)(-108));
  /*5f64c5*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f64ca*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f64cb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); esp -= 4; st32(esp, v); }
  /*5f64ce*/ { u32 v = edi; ecx = v; }
  /*5f64d0*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f64d0*/ esp += 4;
  /*5f64d5*/ { u32 v = eax; ecx = v; }
  /*5f64d7*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f64d7*/ esp += 4;
  /*5f64dc*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f64e3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f64e6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f64e9*/ goto L5f57f3;
  L5f64ee:;
  /*5f64ee*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f64f4*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f64f9*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f64fc*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ecx + eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6500*/ if (cf || zf) goto L5f6507;
  /*5f6502*/ st32((u32)(ecx + eax), X[0][0]);
  L5f6507:;
  /*5f6507*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f650e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6511*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6514*/ goto L5f57f3;
  L5f6519:;
  /*5f6519*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f651c*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f651f*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6522*/ if (!sf) goto L5f6563;
  /*5f6524*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6525*/ { u32 v = edi; ecx = v; }
  /*5f6527*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6527*/ esp += 4;
  /*5f652c*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); ecx = v; }
  /*5f6532*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6536*/ { X[1][0] = ld32((u32)(ecx + (u32)2)); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f653b*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f653e*/ if (cf || zf) goto L5f6580;
  /*5f6540*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); eax = v; }
  /*5f6543*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6546*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f6549*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f654f*/ st32((u32)(ecx + eax), X[1][0]);
  /*5f6554*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f655b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f655e*/ goto L5f57f3;
  L5f6563:;
  /*5f6563*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6569*/ { X[1][0] = ld32((u32)(esi + (u32)2)); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f656e*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f6571*/ { X[0][0] = ld32((u32)(ecx + eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6576*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6579*/ if (cf || zf) goto L5f6580;
  /*5f657b*/ st32((u32)(ecx + eax), X[1][0]);
  L5f6580:;
  /*5f6580*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6587*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f658a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f658d*/ goto L5f57f3;
  L5f6592:;
  /*5f6592*/ { X[0][0] = ld32((u32)(esi)); X[0][1] = X[0][2] = X[0][3] = 0; }
  L5f6596:;
  /*5f6596*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6599*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f659e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f659f*/ ecx = (u32)(edi + (u32)52);
  /*5f65a2*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f65a2*/ esp += 4;
  /*5f65a7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f65ae*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f65b1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f65b4*/ goto L5f57f3;
  L5f65b9:;
  /*5f65b9*/ ecx = (u32)(edi + (u32)52);
  /*5f65bc*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f65c1*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f65c4*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f65c7*/ if (!sf) goto L5f65e5;
  /*5f65c9*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f65ca*/ { u32 v = edi; ecx = v; }
  /*5f65cc*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f65cc*/ esp += 4;
  /*5f65d1*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f65d2*/ ecx = (u32)(edi + (u32)52);
  /*5f65d5*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f65d5*/ esp += 4;
  /*5f65da*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f65dd*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f65e0*/ goto L5f57f3;
  L5f65e5:;
  /*5f65e5*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f65eb*/ ecx = (u32)(edi + (u32)52);
  /*5f65ee*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f65ef*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f65ef*/ esp += 4;
  /*5f65f4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f65f7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f65fa*/ goto L5f57f3;
  L5f65ff:;
  /*5f65ff*/ ecx = (u32)(edi + (u32)52);
  /*5f6602*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6607*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f660a*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f660d*/ if (!sf) goto L5f662b;
  /*5f660f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6610*/ { u32 v = edi; ecx = v; }
  /*5f6612*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6612*/ esp += 4;
  /*5f6617*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6618*/ ecx = (u32)(edi + (u32)52);
  /*5f661b*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f661b*/ esp += 4;
  /*5f6620*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6623*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6626*/ goto L5f57f3;
  L5f662b:;
  /*5f662b*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f6631*/ ecx = (u32)(edi + (u32)52);
  /*5f6634*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6635*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f6635*/ esp += 4;
  /*5f663a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f663d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6640*/ goto L5f57f3;
  L5f6645:;
  /*5f6645*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f6648*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f664b*/ if (!sf) goto L5f665a;
  /*5f664d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f664e*/ { u32 v = edi; ecx = v; }
  /*5f6650*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6650*/ esp += 4;
  /*5f6655*/ goto L5f57d7;
  L5f665a:;
  /*5f665a*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  L5f6660:;
  /*5f6660*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6661*/ ecx = (u32)(edi + (u32)52);
  /*5f6664*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f6664*/ esp += 4;
  L5f6669:;
  /*5f6669*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6670*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6673*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6676*/ goto L5f57f3;
  L5f667b:;
  /*5f667b*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f667e*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6681*/ if (!sf) goto L5f6699;
  /*5f6683*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6684*/ { u32 v = edi; ecx = v; }
  /*5f6686*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6686*/ esp += 4;
  /*5f668b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f668c*/ ecx = (u32)(edi + (u32)52);
  /*5f668f*/ eax = ext_5f51e0_thiscall2(ecx, ld32(esp + 0));
  /*5f668f*/ esp += 4;
  /*5f6694*/ goto L5f57e0;
  L5f6699:;
  /*5f6699*/ { u32 v = eax; ecx = v; }
  /*5f669b*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f66a1*/ { u32 v = (u32)ld32((u32)(eax + ecx)); esp -= 4; st32(esp, v); }
  /*5f66a4*/ ecx = (u32)(edi + (u32)52);
  /*5f66a7*/ eax = ext_5f5390_thiscall2(ecx, ld32(esp + 0));
  /*5f66a7*/ esp += 4;
  /*5f66ac*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f66b3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f66b6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f66b9*/ goto L5f57f3;
  L5f66be:;
  /*5f66be*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f66c1*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f66c4*/ if (!sf) goto L5f66dc;
  /*5f66c6*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f66c7*/ { u32 v = edi; ecx = v; }
  /*5f66c9*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f66c9*/ esp += 4;
  /*5f66ce*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f66cf*/ ecx = (u32)(edi + (u32)52);
  /*5f66d2*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f66d2*/ esp += 4;
  /*5f66d7*/ goto L5f57e0;
  L5f66dc:;
  /*5f66dc*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  L5f66e2:;
  /*5f66e2*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f66e3*/ ecx = (u32)(edi + (u32)52);
  /*5f66e6*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f66e6*/ esp += 4;
  /*5f66eb*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f66f2*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f66f5*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f66f8*/ goto L5f57f3;
  L5f66fd:;
  /*5f66fd*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f6700*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6703*/ if (!sf) goto L5f6725;
  /*5f6705*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6706*/ { u32 v = edi; ecx = v; }
  /*5f6708*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6708*/ esp += 4;
  /*5f670d*/ ecx = (u32)(edi + (u32)52);
  /*5f6710*/ { v4sf_t v = {U2F(ld32((u32)(eax))), 0, 0, 0}; eax = (u32)__builtin_ia32_cvttss2si(v); }
  /*5f6714*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f6717*/ eax = (u32)(ebp + (u32)(-108));
  /*5f671a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f671b*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f671b*/ esp += 4;
  /*5f6720*/ goto L5f57e0;
  L5f6725:;
  /*5f6725*/ { u32 v = eax; ecx = v; }
  /*5f6727*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f672d*/ { v4sf_t v = {U2F(ld32((u32)(eax + ecx))), 0, 0, 0}; eax = (u32)__builtin_ia32_cvttss2si(v); }
  /*5f6732*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f6735*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6738*/ goto L5f66e2;
  L5f673a:;
  /*5f673a*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f673d*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6740*/ if (!sf) goto L5f675e;
  /*5f6742*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6743*/ { u32 v = edi; ecx = v; }
  /*5f6745*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6745*/ esp += 4;
  /*5f674a*/ { u32 v = (u32)ld32((u32)(eax)); X[0][0] = v; X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f674e*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6751*/ { for (int k = 0; k < 4; k++) X[0][k] = F2U((float)(s32)X[0][k]); }
  /*5f6754*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f6759*/ goto L5f57d7;
  L5f675e:;
  /*5f675e*/ { u32 v = eax; ecx = v; }
  /*5f6760*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f6766*/ { u32 v = (u32)ld32((u32)(eax + ecx)); X[0][0] = v; X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f676b*/ eax = (u32)(ebp + (u32)(-108));
  /*5f676e*/ { for (int k = 0; k < 4; k++) X[0][k] = F2U((float)(s32)X[0][k]); }
  /*5f6771*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f6776*/ goto L5f6660;
  L5f677b:;
  /*5f677b*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f677e*/ ecx = (u32)(edi + (u32)52);
  /*5f6781*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f6786*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6789*/ if (!sf) goto L5f67b9;
  /*5f678b*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-140))) :: "st", "memory");
  /*5f6791*/ eax = (u32)(ebp + (u32)(-140));
  L5f6797:;
  /*5f6797*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6798*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6799*/ { u32 v = edi; ecx = v; }
  /*5f679b*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f679b*/ esp += 4;
  /*5f67a0*/ { u32 v = eax; ecx = v; }
  /*5f67a2*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f67a2*/ esp += 4;
  /*5f67a7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f67ae*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f67b1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f67b4*/ goto L5f57f3;
  L5f67b9:;
  /*5f67b9*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f67bf*/ { u32 v = esi; ecx = v; }
  /*5f67c1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f67c4*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + eax)) :: "st", "memory");
  /*5f67c7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f67ce*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f67d1*/ goto L5f57f3;
  L5f67d6:;
  /*5f67d6*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f67d9*/ ecx = (u32)(edi + (u32)52);
  /*5f67dc*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f67e1*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f67e4*/ if (!sf) goto L5f681d;
  L5f67e6:;
  /*5f67e6*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f67e7*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f67e8*/ { u32 v = edi; ecx = v; }
  /*5f67ea*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f67ea*/ esp += 4;
  /*5f67ef*/ { u32 v = eax; ecx = v; }
  /*5f67f1*/ eax = ext_5002f0_thiscall2(ecx, ld32(esp + 0));
  /*5f67f1*/ esp += 4;
  /*5f67f6*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f67fd*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6800*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6803*/ goto L5f57f3;
  L5f6808:;
  /*5f6808*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f680b*/ ecx = (u32)(edi + (u32)52);
  /*5f680e*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f6813*/ { u64 r = ext_634670(); eax = (u32)r; edx = (u32)(r >> 32); }
  /*5f6818*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f681b*/ if (sf) goto L5f67e6;
  L5f681d:;
  /*5f681d*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6823*/ { u32 v = esi; edx = v; }
  /*5f6825*/ { u32 v = eax; st32((u32)(edx + ecx), v); }
  /*5f6828*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f682f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6832*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6835*/ goto L5f57f3;
  L5f683a:;
  /*5f683a*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f683d*/ ecx = (u32)(edi + (u32)52);
  /*5f6840*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6845*/ { u32 v = eax; X[0][0] = v; X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6849*/ { for (int k = 0; k < 4; k++) X[0][k] = F2U((float)(s32)X[0][k]); }
  /*5f684c*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f684f*/ if (!sf) goto L5f6878;
  /*5f6851*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6852*/ st32((u32)(esp), X[0][0]);
  /*5f6857*/ { u32 v = edi; ecx = v; }
  /*5f6859*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f685a*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f685a*/ esp += 4;
  /*5f685f*/ { u32 v = eax; ecx = v; }
  /*5f6861*/ eax = ext_500360_thiscall2(ecx, ld32(esp + 0));
  /*5f6861*/ esp += 4;
  /*5f6866*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f686d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6870*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6873*/ goto L5f57f3;
  L5f6878:;
  /*5f6878*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f687e*/ { u32 v = esi; ecx = v; }
  /*5f6880*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6883*/ st32((u32)(ecx + eax), X[0][0]);
  /*5f6888*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f688f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6892*/ goto L5f57f3;
  L5f6897:;
  /*5f6897*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f689a*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f689d*/ if (!sf) goto L5f68cf;
  /*5f689f*/ ecx = (u32)(edi + (u32)52);
  /*5f68a2*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f68a7*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  L5f68aa:;
  /*5f68aa*/ eax = (u32)(ebp + (u32)(-108));
  /*5f68ad*/ { u32 v = edi; ecx = v; }
  /*5f68af*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f68b0*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f68b1*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f68b1*/ esp += 4;
  /*5f68b6*/ { u32 v = eax; ecx = v; }
  /*5f68b8*/ eax = ext_5f3db0_thiscall2(ecx, ld32(esp + 0));
  /*5f68b8*/ esp += 4;
  /*5f68bd*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f68c4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f68c7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f68ca*/ goto L5f57f3;
  L5f68cf:;
  /*5f68cf*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f68d5*/ { u32 v = esi; edi = v; }
  /*5f68d7*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f68dd*/ ecx = (u32)(eax + (u32)52);
  /*5f68e0*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f68e5*/ __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(esi + edi)) : "st", "memory");
  /*5f68e8*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f68eb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f68ee*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + edi)) :: "st", "memory");
  /*5f68f1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f68f7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f68fe*/ goto L5f57f3;
  L5f6903:;
  /*5f6903*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f6906*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6909*/ if (!sf) goto L5f693b;
  /*5f690b*/ ecx = (u32)(edi + (u32)52);
  /*5f690e*/ eax = ext_5f4ff0_thiscall1(ecx);
  L5f6913:;
  /*5f6913*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f6916*/ { u32 v = edi; ecx = v; }
  /*5f6918*/ eax = (u32)(ebp + (u32)(-108));
  /*5f691b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f691c*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f691d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f691d*/ esp += 4;
  /*5f6922*/ { u32 v = eax; ecx = v; }
  /*5f6924*/ eax = ext_5f3d40_thiscall2(ecx, ld32(esp + 0));
  /*5f6924*/ esp += 4;
  /*5f6929*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6930*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6933*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6936*/ goto L5f57f3;
  L5f693b:;
  /*5f693b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f6941*/ { u32 v = esi; edi = v; }
  /*5f6943*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f6949*/ ecx = (u32)(eax + (u32)52);
  /*5f694c*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6951*/ { u32 ea = (u32)(esi + edi); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6954*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f695a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f695d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6960*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6967*/ goto L5f57f3;
  L5f696c:;
  /*5f696c*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f696f*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6972*/ if (!sf) goto L5f6995;
  /*5f6974*/ ecx = (u32)(edi + (u32)52);
  /*5f6977*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f697c*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f697f*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6984*/ { u32 ea = (u32)((u32)6795072); for (int k = 0; k < 4; k++) X[0][k] ^= ld32(ea + 4 * k); }
  /*5f698b*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f6990*/ goto L5f68aa;
  L5f6995:;
  /*5f6995*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f699b*/ { u32 v = esi; edi = v; }
  /*5f699d*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f69a3*/ ecx = (u32)(eax + (u32)52);
  /*5f69a6*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f69ab*/ __asm__ volatile("fsubrs %0" :: "m"(*(float *)(u32)(esi + edi)) : "st", "memory");
  /*5f69ae*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); ecx = v; }
  /*5f69b4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f69b7*/ { u32 v = (u32)ld32((u32)(ecx + (u32)158)); eax = v; }
  /*5f69bd*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f69c0*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f69c5*/ st32((u32)(edi + eax), X[0][0]);
  /*5f69ca*/ { u32 v = ecx; edi = v; }
  /*5f69cc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f69cf*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f69d6*/ goto L5f57f3;
  L5f69db:;
  /*5f69db*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f69de*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f69e1*/ if (!sf) goto L5f69f2;
  /*5f69e3*/ ecx = (u32)(edi + (u32)52);
  /*5f69e6*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f69eb*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f69ed*/ goto L5f6913;
  L5f69f2:;
  /*5f69f2*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f69f8*/ { u32 v = esi; edi = v; }
  /*5f69fa*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f6a00*/ ecx = (u32)(eax + (u32)52);
  /*5f6a03*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6a08*/ { u32 ea = (u32)(esi + edi); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6a0b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f6a11*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6a14*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6a17*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6a1e*/ goto L5f57f3;
  L5f6a23:;
  /*5f6a23*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f6a26*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6a29*/ if (!sf) goto L5f6a5b;
  /*5f6a2b*/ ecx = (u32)(edi + (u32)52);
  /*5f6a2e*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f6a33*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6a36*/ { u32 v = edi; ecx = v; }
  /*5f6a38*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6a39*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6a3a*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f6a3d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6a3d*/ esp += 4;
  /*5f6a42*/ { u32 v = eax; ecx = v; }
  /*5f6a44*/ eax = ext_5f4e60_thiscall2(ecx, ld32(esp + 0));
  /*5f6a44*/ esp += 4;
  /*5f6a49*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6a50*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6a53*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6a56*/ goto L5f57f3;
  L5f6a5b:;
  /*5f6a5b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f6a61*/ { u32 v = esi; edi = v; }
  /*5f6a63*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f6a69*/ ecx = (u32)(eax + (u32)52);
  /*5f6a6c*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f6a71*/ __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(esi + edi)) : "st", "memory");
  /*5f6a74*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6a77*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6a7a*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + edi)) :: "st", "memory");
  /*5f6a7d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f6a83*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6a8a*/ goto L5f57f3;
  L5f6a8f:;
  /*5f6a8f*/ { u32 v = (u32)ld16((u32)(esi)); esi = v; }
  /*5f6a92*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6a95*/ if (!sf) goto L5f6ac7;
  /*5f6a97*/ ecx = (u32)(edi + (u32)52);
  /*5f6a9a*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6a9f*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f6aa2*/ { u32 v = edi; ecx = v; }
  /*5f6aa4*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6aa7*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6aa8*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6aa9*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6aa9*/ esp += 4;
  /*5f6aae*/ { u32 v = eax; ecx = v; }
  /*5f6ab0*/ eax = ext_5f4e00_thiscall2(ecx, ld32(esp + 0));
  /*5f6ab0*/ esp += 4;
  /*5f6ab5*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6abc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6abf*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6ac2*/ goto L5f57f3;
  L5f6ac7:;
  /*5f6ac7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f6acd*/ { u32 v = esi; edi = v; }
  /*5f6acf*/ { u32 v = (u32)ld32((u32)(eax + (u32)158)); esi = v; }
  /*5f6ad5*/ ecx = (u32)(eax + (u32)52);
  /*5f6ad8*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6add*/ { s32 a = (s32)eax, b = (s32)(u32)ld32((u32)(esi + edi)); s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f6ae1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6ae4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6ae7*/ { u32 v = eax; st32((u32)(esi + edi), v); }
  /*5f6aea*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f6af0*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6af7*/ goto L5f57f3;
  L5f6afc:;
  /*5f6afc*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6aff*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6b00*/ ecx = (u32)(edi + (u32)52);
  /*5f6b03*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6b03*/ esp += 4;
  /*5f6b08*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f6b0d*/ { float a = U2F(X[1][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6b14*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f6b15*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6b18*/ if (!pf) goto L5f6b75;
  /*5f6b1a*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6b20*/ { u32 v = (u32)ld16((u32)(eax)); eax = v; }
  /*5f6b23*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6b26*/ if (!sf) goto L5f6b4d;
  /*5f6b28*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f6b2b*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6b2c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6b2d*/ { u32 v = edi; ecx = v; }
  /*5f6b2f*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6b2f*/ esp += 4;
  /*5f6b34*/ { u32 v = eax; ecx = v; }
  /*5f6b36*/ eax = ext_5f4110_thiscall2(ecx, ld32(esp + 0));
  /*5f6b36*/ esp += 4;
  /*5f6b3b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6b42*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6b45*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6b48*/ goto L5f57f3;
  L5f6b4d:;
  /*5f6b4d*/ { u32 v = eax; ecx = v; }
  /*5f6b4f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6b52*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f6b58*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6b5d*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) / b); }
  /*5f6b61*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f6b66*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6b6d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6b70*/ goto L5f57f3;
  L5f6b75:;
  /*5f6b75*/ { u32 v = edi; ecx = v; }
  /*5f6b77*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f6b7c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6b7f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6b82*/ goto L5f57f3;
  L5f6b87:;
  /*5f6b87*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6b8a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6b8b*/ ecx = (u32)(edi + (u32)52);
  /*5f6b8e*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6b8e*/ esp += 4;
  /*5f6b93*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6b97*/ if (zf) goto L5f6b75;
  /*5f6b99*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6b9f*/ { u32 v = (u32)ld16((u32)(eax)); eax = v; }
  /*5f6ba2*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6ba5*/ if (!sf) goto L5f6bcc;
  /*5f6ba7*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f6baa*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6bab*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6bac*/ { u32 v = edi; ecx = v; }
  /*5f6bae*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6bae*/ esp += 4;
  /*5f6bb3*/ { u32 v = eax; ecx = v; }
  /*5f6bb5*/ eax = ext_5f40b0_thiscall2(ecx, ld32(esp + 0));
  /*5f6bb5*/ esp += 4;
  /*5f6bba*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6bc1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6bc4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6bc7*/ goto L5f57f3;
  L5f6bcc:;
  /*5f6bcc*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6bd2*/ { u32 v = eax; esi = v; }
  /*5f6bd4*/ { u32 v = (u32)ld32((u32)(ecx + esi)); eax = v; }
  /*5f6bd7*/ edx = (u32)((s32)eax >> 31);
  /*5f6bd8*/ { u32 d = (u32)ld32((u32)(ebp + (u32)(-124))); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f6bdb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6bde*/ { u32 v = eax; st32((u32)(ecx + esi), v); }
  /*5f6be1*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6be8*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6beb*/ goto L5f57f3;
  L5f6bf0:;
  /*5f6bf0*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6bf3*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6bf4*/ ecx = (u32)(edi + (u32)52);
  /*5f6bf7*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6bf7*/ esp += 4;
  /*5f6bfc*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6c02*/ { u32 v = (u32)ld16((u32)(eax)); esi = v; }
  /*5f6c05*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6c08*/ if (!sf) goto L5f6c28;
  /*5f6c0a*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6c0b*/ { u32 v = edi; ecx = v; }
  /*5f6c0d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6c0d*/ esp += 4;
  /*5f6c12*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6c16*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6c1a*/ if (cf || zf) goto L5f6669;
  /*5f6c20*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6c23*/ goto L5f6797;
  L5f6c28:;
  /*5f6c28*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6c2e*/ { u32 v = esi; eax = v; }
  /*5f6c30*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f6c35*/ { X[0][0] = ld32((u32)(ecx + eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6c3a*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6c3d*/ if (cf || zf) goto L5f6669;
  /*5f6c43*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6c46*/ st32((u32)(ecx + eax), X[1][0]);
  /*5f6c4b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6c52*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6c55*/ goto L5f57f3;
  L5f6c5a:;
  /*5f6c5a*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6c5d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6c5e*/ ecx = (u32)(edi + (u32)52);
  /*5f6c61*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6c61*/ esp += 4;
  /*5f6c66*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f6c6c*/ { u32 v = (u32)ld16((u32)(eax)); esi = v; }
  /*5f6c6f*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6c72*/ if (!sf) goto L5f6c92;
  /*5f6c74*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6c75*/ { u32 v = edi; ecx = v; }
  /*5f6c77*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6c77*/ esp += 4;
  /*5f6c7c*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6c81*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6c84*/ if (cf || zf) goto L5f6669;
  /*5f6c8a*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6c8d*/ goto L5f6797;
  L5f6c92:;
  /*5f6c92*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6c98*/ { u32 v = esi; eax = v; }
  /*5f6c9a*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6c9f*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ecx + eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6ca3*/ if (cf || zf) goto L5f6669;
  /*5f6ca9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6cac*/ st32((u32)(ecx + eax), X[0][0]);
  /*5f6cb1*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6cb8*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6cbb*/ goto L5f57f3;
  L5f6cc0:;
  /*5f6cc0*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6cc3*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6cc4*/ ecx = (u32)(edi + (u32)52);
  /*5f6cc7*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6cc7*/ esp += 4;
  /*5f6ccc*/ ecx = (u32)(edi + (u32)52);
  /*5f6ccf*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6cd4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6cd7*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f6cda*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f6cdd*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4294967232U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f6ce0*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6ce3*/ if (!sf) goto L5f6d6a;
  /*5f6ce9*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6cec*/ if (!cf && !zf) goto L5f57f0;
  /*5f6cf2*/ switch (eax) {
    case 0: goto L5f6cf9;
    case 1: goto L5f57e7;
    case 2: goto L5f6d17;
    case 3: goto L5f57e7;
    case 4: goto L5f6d24;
    case 5: goto L5f57e7;
    case 6: goto L5f6d42;
    default: __builtin_trap(); }
  L5f6cf9:;
  /*5f6cf9*/ eax = (u32)(ebp + (u32)(-124));
  L5f6cfc:;
  /*5f6cfc*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6cfd*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6cfe*/ { u32 v = edi; ecx = v; }
  /*5f6d00*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6d00*/ esp += 4;
  /*5f6d05*/ { u32 v = eax; ecx = v; }
  /*5f6d07*/ eax = ext_5f3d40_thiscall2(ecx, ld32(esp + 0));
  /*5f6d07*/ esp += 4;
  /*5f6d0c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6d0f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6d12*/ goto L5f57f3;
  L5f6d17:;
  /*5f6d17*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); eax = v; }
  /*5f6d1a*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f6d1c*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f6d1f*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6d22*/ goto L5f6cfc;
  L5f6d24:;
  /*5f6d24*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6d27*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6d28*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6d29*/ { u32 v = edi; ecx = v; }
  /*5f6d2b*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6d2b*/ esp += 4;
  /*5f6d30*/ { u32 v = eax; ecx = v; }
  /*5f6d32*/ eax = ext_5f4e00_thiscall2(ecx, ld32(esp + 0));
  /*5f6d32*/ esp += 4;
  /*5f6d37*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6d3a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6d3d*/ goto L5f57f3;
  L5f6d42:;
  /*5f6d42*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6d46*/ if (zf) goto L5f6b75;
  /*5f6d4c*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6d4f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6d50*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6d51*/ { u32 v = edi; ecx = v; }
  /*5f6d53*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6d53*/ esp += 4;
  /*5f6d58*/ { u32 v = eax; ecx = v; }
  /*5f6d5a*/ eax = ext_5f40b0_thiscall2(ecx, ld32(esp + 0));
  /*5f6d5a*/ esp += 4;
  /*5f6d5f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6d62*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6d65*/ goto L5f57f3;
  L5f6d6a:;
  /*5f6d6a*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6d6d*/ if (!cf && !zf) goto L5f57f0;
  /*5f6d73*/ switch (eax) {
    case 0: goto L5f6d7a;
    case 1: goto L5f57e7;
    case 2: goto L5f6d93;
    case 3: goto L5f57e7;
    case 4: goto L5f6dac;
    case 5: goto L5f57e7;
    case 6: goto L5f6dc9;
    default: __builtin_trap(); }
  L5f6d7a:;
  /*5f6d7a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); eax = v; }
  /*5f6d7d*/ { u32 v = ecx; edx = v; }
  /*5f6d7f*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6d85*/ { u32 ea = (u32)(ecx + edx); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6d88*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6d8b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6d8e*/ goto L5f57f3;
  L5f6d93:;
  /*5f6d93*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); eax = v; }
  /*5f6d96*/ { u32 v = ecx; edx = v; }
  /*5f6d98*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6d9e*/ { u32 ea = (u32)(ecx + edx); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f6da1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6da4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6da7*/ goto L5f57f3;
  L5f6dac:;
  /*5f6dac*/ { u32 v = ecx; edx = v; }
  /*5f6dae*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6db4*/ { u32 v = (u32)ld32((u32)(ecx + edx)); eax = v; }
  /*5f6db7*/ { s32 a = (s32)eax, b = (s32)(u32)ld32((u32)(ebp + (u32)(-124))); s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f6dbb*/ { u32 v = eax; st32((u32)(ecx + edx), v); }
  /*5f6dbe*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6dc1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6dc4*/ goto L5f57f3;
  L5f6dc9:;
  /*5f6dc9*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6dcd*/ if (zf) goto L5f6b75;
  /*5f6dd3*/ { u32 v = ecx; esi = v; }
  /*5f6dd5*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6ddb*/ { u32 v = (u32)ld32((u32)(ecx + esi)); eax = v; }
  /*5f6dde*/ edx = (u32)((s32)eax >> 31);
  /*5f6ddf*/ { u32 d = (u32)ld32((u32)(ebp + (u32)(-124))); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f6de2*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6de5*/ { u32 v = eax; st32((u32)(ecx + esi), v); }
  /*5f6de8*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6deb*/ goto L5f57f3;
  L5f6df0:;
  /*5f6df0*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6df3*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6df4*/ ecx = (u32)(edi + (u32)52);
  /*5f6df7*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6df7*/ esp += 4;
  /*5f6dfc*/ ecx = (u32)(edi + (u32)52);
  /*5f6dff*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6e04*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6e07*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f6e0a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f6e0d*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4294967231U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f6e10*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6e13*/ if (!sf) goto L5f6e99;
  /*5f6e19*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6e1c*/ if (!cf && !zf) goto L5f57f0;
  /*5f6e22*/ switch (eax) {
    case 0: goto L5f6e29;
    case 1: goto L5f57e7;
    case 2: goto L5f6e47;
    case 3: goto L5f57e7;
    case 4: goto L5f6e5d;
    case 5: goto L5f57e7;
    case 6: goto L5f6e7b;
    default: __builtin_trap(); }
  L5f6e29:;
  /*5f6e29*/ eax = (u32)(ebp + (u32)(-124));
  L5f6e2c:;
  /*5f6e2c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6e2d*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6e2e*/ { u32 v = edi; ecx = v; }
  /*5f6e30*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6e30*/ esp += 4;
  /*5f6e35*/ { u32 v = eax; ecx = v; }
  /*5f6e37*/ eax = ext_5f3db0_thiscall2(ecx, ld32(esp + 0));
  /*5f6e37*/ esp += 4;
  /*5f6e3c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6e3f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6e42*/ goto L5f57f3;
  L5f6e47:;
  /*5f6e47*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6e4c*/ eax = (u32)(ebp + (u32)(-108));
  /*5f6e4f*/ { u32 ea = (u32)((u32)6795072); for (int k = 0; k < 4; k++) X[0][k] ^= ld32(ea + 4 * k); }
  /*5f6e56*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f6e5b*/ goto L5f6e2c;
  L5f6e5d:;
  /*5f6e5d*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6e60*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6e61*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6e62*/ { u32 v = edi; ecx = v; }
  /*5f6e64*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6e64*/ esp += 4;
  /*5f6e69*/ { u32 v = eax; ecx = v; }
  /*5f6e6b*/ eax = ext_5f4e60_thiscall2(ecx, ld32(esp + 0));
  /*5f6e6b*/ esp += 4;
  /*5f6e70*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6e73*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6e76*/ goto L5f57f3;
  L5f6e7b:;
  /*5f6e7b*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6e7e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6e7f*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f6e80*/ { u32 v = edi; ecx = v; }
  /*5f6e82*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6e82*/ esp += 4;
  /*5f6e87*/ { u32 v = eax; ecx = v; }
  /*5f6e89*/ eax = ext_5f4110_thiscall2(ecx, ld32(esp + 0));
  /*5f6e89*/ esp += 4;
  /*5f6e8e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6e91*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6e94*/ goto L5f57f3;
  L5f6e99:;
  /*5f6e99*/ { u32 a = (u32)eax; u32 b = (u32)(u32)6U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6e9c*/ if (!cf && !zf) goto L5f57f0;
  /*5f6ea2*/ switch (eax) {
    case 0: goto L5f6ea9;
    case 1: goto L5f57e7;
    case 2: goto L5f6ec9;
    case 3: goto L5f57e7;
    case 4: goto L5f6ee9;
    case 5: goto L5f57e7;
    case 6: goto L5f6f09;
    default: __builtin_trap(); }
  L5f6ea9:;
  /*5f6ea9*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f6eaf*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6eb4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6eb7*/ { float b = U2F(ld32((u32)(eax + ecx))); X[0][0] = F2U(U2F(X[0][0]) + b); }
  /*5f6ebc*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f6ec1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6ec4*/ goto L5f57f3;
  L5f6ec9:;
  /*5f6ec9*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f6ecf*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6ed2*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6ed7*/ { float b = U2F(ld32((u32)(ebp + (u32)(-124)))); X[0][0] = F2U(U2F(X[0][0]) - b); }
  /*5f6edc*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f6ee1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6ee4*/ goto L5f57f3;
  L5f6ee9:;
  /*5f6ee9*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f6eef*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6ef4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6ef7*/ { float b = U2F(ld32((u32)(eax + ecx))); X[0][0] = F2U(U2F(X[0][0]) * b); }
  /*5f6efc*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f6f01*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6f04*/ goto L5f57f3;
  L5f6f09:;
  /*5f6f09*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f6f0e*/ { float a = U2F(X[1][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6f15*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f6f16*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6f19*/ if (!pf) goto L5f6b75;
  /*5f6f1f*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f6f25*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6f28*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6f2d*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) / b); }
  /*5f6f31*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f6f36*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6f39*/ goto L5f57f3;
  L5f6f3e:;
  /*5f6f3e*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6f41*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6f42*/ ecx = (u32)(edi + (u32)52);
  /*5f6f45*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6f45*/ esp += 4;
  /*5f6f4a*/ ecx = (u32)(edi + (u32)52);
  /*5f6f4d*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6f52*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f6f55*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6f58*/ if (!sf) goto L5f6f94;
  /*5f6f5a*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6f5b*/ { u32 v = edi; ecx = v; }
  /*5f6f5d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6f5d*/ esp += 4;
  /*5f6f62*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6f66*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  L5f6f6a:;
  /*5f6f6a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6f6d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6f70*/ if (cf || zf) goto L5f57f3;
  /*5f6f76*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6f79*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6f7a*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  L5f6f7b:;
  /*5f6f7b*/ { u32 v = edi; ecx = v; }
  /*5f6f7d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6f7d*/ esp += 4;
  /*5f6f82*/ { u32 v = eax; ecx = v; }
  /*5f6f84*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f6f84*/ esp += 4;
  /*5f6f89*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6f8c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6f8f*/ goto L5f57f3;
  L5f6f94:;
  /*5f6f94*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6f9a*/ { u32 v = esi; eax = v; }
  /*5f6f9c*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f6fa1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f6fa4*/ { X[0][0] = ld32((u32)(ecx + eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6fa9*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6fac*/ if (cf || zf) goto L5f57f0;
  /*5f6fb2*/ st32((u32)(ecx + eax), X[1][0]);
  /*5f6fb7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f6fba*/ goto L5f57f3;
  L5f6fbf:;
  /*5f6fbf*/ eax = (u32)(ebp + (u32)(-124));
  /*5f6fc2*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f6fc3*/ ecx = (u32)(edi + (u32)52);
  /*5f6fc6*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f6fc6*/ esp += 4;
  /*5f6fcb*/ ecx = (u32)(edi + (u32)52);
  /*5f6fce*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f6fd3*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f6fd6*/ { u16 a = (u16)(esi & 0xffff); u16 b = (u16)(esi & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f6fd9*/ if (!sf) goto L5f6ff0;
  /*5f6fdb*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f6fdc*/ { u32 v = edi; ecx = v; }
  /*5f6fde*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f6fde*/ esp += 4;
  /*5f6fe3*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6fe8*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f6feb*/ goto L5f6f6a;
  L5f6ff0:;
  /*5f6ff0*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f6ff6*/ { u32 v = esi; eax = v; }
  /*5f6ff8*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f6ffd*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7000*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ecx + eax))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f7004*/ if (cf || zf) goto L5f57f0;
  /*5f700a*/ st32((u32)(ecx + eax), X[0][0]);
  /*5f700f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7012*/ goto L5f57f3;
  L5f7017:;
  /*5f7017*/ eax = (u32)(esi + (u32)2);
  /*5f701a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f701b*/ ecx = (u32)(edi + (u32)64);
  /*5f701e*/ eax = ext_5f53f0_thiscall2(ecx, ld32(esp + 0));
  /*5f701e*/ esp += 4;
  /*5f7023*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f7029*/ { u32 v = edi; ecx = v; }
  /*5f702b*/ { u32 v = (u32)ld16((u32)(eax)); eax = v; }
  /*5f702e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f702f*/ eax = ext_5f5680_thiscall2(ecx, ld32(esp + 0));
  /*5f702f*/ esp += 4;
  /*5f7034*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7037*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f703a*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f7040*/ goto L5f57f3;
  L5f7045:;
  /*5f7045*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f7047*/ ecx = (u32)(edi + (u32)52);
  /*5f704a*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f704d*/ eax = (u32)(ebp + (u32)(-108));
  /*5f7050*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7051*/ eax = ext_5f4fb0_thiscall2(ecx, ld32(esp + 0));
  /*5f7051*/ esp += 4;
  /*5f7056*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f705d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7060*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7063*/ goto L5f57f3;
  L5f7068:;
  /*5f7068*/ { u32 ea = (u32)(esi + (u32)4); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f706c*/ ecx = (u32)(edi + (u32)52);
  /*5f706f*/ if (zf) goto L5f7078;
  /*5f7071*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7076*/ goto L5f7081;
  L5f7078:;
  /*5f7078*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f707a*/ eax = ext_5f4ec0_thiscall2(ecx, ld32(esp + 0));
  /*5f707a*/ esp += 4;
  /*5f707f*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  L5f7081:;
  /*5f7081*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7083*/ if (zf) goto L5f70a5;
  L5f7085:;
  /*5f7085*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f708b*/ { u32 v = (u32)ld32((u32)(eax)); esp -= 4; st32(esp, v); }
  L5f708d:;
  /*5f708d*/ { u32 v = edi; ecx = v; }
  /*5f708f*/ eax = ext_5f5620_thiscall2(ecx, ld32(esp + 0));
  /*5f708f*/ esp += 4;
  /*5f7094*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7097*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f709a*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f70a0*/ goto L5f57f3;
  L5f70a5:;
  /*5f70a5*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f70ac*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f70af*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f70b2*/ goto L5f57f3;
  L5f70b7:;
  /*5f70b7*/ { u32 ea = (u32)(esi + (u32)4); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f70bb*/ ecx = (u32)(edi + (u32)52);
  /*5f70be*/ if (zf) goto L5f70c7;
  /*5f70c0*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f70c5*/ goto L5f70d0;
  L5f70c7:;
  /*5f70c7*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f70c9*/ eax = ext_5f4ec0_thiscall2(ecx, ld32(esp + 0));
  /*5f70c9*/ esp += 4;
  /*5f70ce*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  L5f70d0:;
  /*5f70d0*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f70d2*/ if (!zf) goto L5f70a5;
  /*5f70d4*/ goto L5f7085;
  L5f70d6:;
  /*5f70d6*/ ecx = (u32)(edi + (u32)52);
  /*5f70d9*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f70de*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f70e0*/ if (zf) goto L5f8acf;
  /*5f70e6*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f70ed*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f70f0*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f70f3*/ goto L5f57f3;
  L5f70f8:;
  /*5f70f8*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f70fa*/ { u32 v = (u32)ld32((u32)(esi)); esp -= 4; st32(esp, v); }
  L5f70fc:;
  /*5f70fc*/ { u32 v = edi; ecx = v; }
  /*5f70fe*/ eax = ext_5f9130_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f70fe*/ esp += 8;
  /*5f7103*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7106*/ { u32 v = (u32)34816U; eax = v; }
  /*5f710b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f710e*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7115*/ if (zf) goto L5f57f3;
  /*5f711b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7122*/ goto L5f57f3;
  L5f7127:;
  /*5f7127*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f712d*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f712f*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f7131*/ { u32 v = (u32)ld32((u32)(ecx + eax)); esp -= 4; st32(esp, v); }
  /*5f7134*/ goto L5f70fc;
  L5f7136:;
  /*5f7136*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f7139*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); ecx = v; }
  /*5f713f*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f7141*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7142*/ eax = ext_5f4a80_thiscall2(ecx, ld32(esp + 0));
  /*5f7142*/ esp += 4;
  /*5f7147*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7148*/ { u32 v = edi; ecx = v; }
  /*5f714a*/ eax = ext_5f9130_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f714a*/ esp += 8;
  /*5f714f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7152*/ { u32 v = (u32)34816U; eax = v; }
  /*5f7157*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f715a*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7161*/ if (zf) goto L5f57f3;
  /*5f7167*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f716e*/ goto L5f57f3;
  L5f7173:;
  /*5f7173*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7176*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7177*/ ecx = (u32)(edi + (u32)52);
  /*5f717a*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f717a*/ esp += 4;
  /*5f717f*/ ecx = (u32)(edi + (u32)52);
  /*5f7182*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7187*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f718a*/ if (sf == of) goto L5f599e;
  /*5f7190*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7197*/ goto L5f5936;
  L5f719c:;
  /*5f719c*/ eax = (u32)(ebp + (u32)(-124));
  /*5f719f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f71a0*/ ecx = (u32)(edi + (u32)52);
  /*5f71a3*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f71a3*/ esp += 4;
  /*5f71a8*/ ecx = (u32)(edi + (u32)52);
  /*5f71ab*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f71b0*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f71b3*/ if (zf || sf != of) goto L5f599e;
  /*5f71b9*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f71c0*/ goto L5f5936;
  L5f71c5:;
  /*5f71c5*/ eax = (u32)(ebp + (u32)(-124));
  /*5f71c8*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f71c9*/ ecx = (u32)(edi + (u32)52);
  /*5f71cc*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f71cc*/ esp += 4;
  /*5f71d1*/ ecx = (u32)(edi + (u32)52);
  /*5f71d4*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f71d9*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f71dc*/ if (!zf && sf == of) goto L5f599e;
  /*5f71e2*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f71e9*/ goto L5f5936;
  L5f71ee:;
  /*5f71ee*/ eax = (u32)(ebp + (u32)(-124));
  /*5f71f1*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f71f2*/ ecx = (u32)(edi + (u32)52);
  /*5f71f5*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f71f5*/ esp += 4;
  /*5f71fa*/ ecx = (u32)(edi + (u32)52);
  /*5f71fd*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7202*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7205*/ if (sf != of) goto L5f599e;
  /*5f720b*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7212*/ goto L5f5936;
  L5f7217:;
  /*5f7217*/ eax = (u32)(ebp + (u32)(-124));
  /*5f721a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f721b*/ ecx = (u32)(edi + (u32)52);
  /*5f721e*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f721e*/ esp += 4;
  /*5f7223*/ ecx = (u32)(edi + (u32)52);
  /*5f7226*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f722b*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f722e*/ if (!zf) goto L5f599e;
  /*5f7234*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f723b*/ goto L5f5936;
  L5f7240:;
  /*5f7240*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7243*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7244*/ ecx = (u32)(edi + (u32)52);
  /*5f7247*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f7247*/ esp += 4;
  /*5f724c*/ ecx = (u32)(edi + (u32)52);
  /*5f724f*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7254*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(ebp + (u32)(-124))); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7257*/ if (zf) goto L5f599e;
  /*5f725d*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7264*/ goto L5f5936;
  L5f7269:;
  /*5f7269*/ eax = (u32)(ebp + (u32)(-124));
  /*5f726c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f726d*/ ecx = (u32)(edi + (u32)52);
  /*5f7270*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f7270*/ esp += 4;
  /*5f7275*/ ecx = (u32)(edi + (u32)52);
  /*5f7278*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f727d*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f7282*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f7285*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-108)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f7289*/ if (cf || zf) goto L5f599e;
  /*5f728f*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7296*/ goto L5f5936;
  L5f729b:;
  /*5f729b*/ eax = (u32)(ebp + (u32)(-124));
  /*5f729e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f729f*/ ecx = (u32)(edi + (u32)52);
  /*5f72a2*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f72a2*/ esp += 4;
  /*5f72a7*/ ecx = (u32)(edi + (u32)52);
  /*5f72aa*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f72af*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f72b2*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f72b7*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f72bb*/ if (cf || zf) goto L5f599e;
  /*5f72c1*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f72c8*/ goto L5f5936;
  L5f72cd:;
  /*5f72cd*/ eax = (u32)(ebp + (u32)(-124));
  /*5f72d0*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f72d1*/ ecx = (u32)(edi + (u32)52);
  /*5f72d4*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f72d4*/ esp += 4;
  /*5f72d9*/ ecx = (u32)(edi + (u32)52);
  /*5f72dc*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f72e1*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f72e6*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f72e9*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-108)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f72ed*/ if (cf) goto L5f599e;
  /*5f72f3*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f72fa*/ goto L5f5936;
  L5f72ff:;
  /*5f72ff*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7302*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7303*/ ecx = (u32)(edi + (u32)52);
  /*5f7306*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f7306*/ esp += 4;
  /*5f730b*/ ecx = (u32)(edi + (u32)52);
  /*5f730e*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f7313*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f7316*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f731b*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f731f*/ if (cf) goto L5f599e;
  /*5f7325*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f732c*/ goto L5f5936;
  L5f7331:;
  /*5f7331*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7334*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7335*/ ecx = (u32)(edi + (u32)52);
  /*5f7338*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f7338*/ esp += 4;
  /*5f733d*/ ecx = (u32)(edi + (u32)52);
  /*5f7340*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f7345*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f7348*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f734d*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f7351*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f7352*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7355*/ if (pf) goto L5f599e;
  /*5f735b*/ { u32 v = (u32)1U; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7362*/ goto L5f5936;
  L5f7367:;
  /*5f7367*/ eax = (u32)(ebp + (u32)(-124));
  /*5f736a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f736b*/ ecx = (u32)(edi + (u32)52);
  /*5f736e*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f736e*/ esp += 4;
  /*5f7373*/ ecx = (u32)(edi + (u32)52);
  /*5f7376*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f737b*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f737e*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f7383*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)(ebp + (u32)(-124)))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f7387*/ goto L5f5a19;
  L5f738c:;
  /*5f738c*/ ecx = (u32)(edi + (u32)52);
  /*5f738f*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7394*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f7397*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f739a*/ if (!sf) goto L5f73cc;
  /*5f739c*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f73a2*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  L5f73a4:;
  /*5f73a4*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f73a7*/ eax = (u32)(ebp + (u32)(-108));
  L5f73aa:;
  /*5f73aa*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f73ab*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f73ac*/ { u32 v = edi; ecx = v; }
  /*5f73ae*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f73ae*/ esp += 4;
  /*5f73b3*/ { u32 v = eax; ecx = v; }
  /*5f73b5*/ eax = ext_50d7b0_thiscall2(ecx, ld32(esp + 0));
  /*5f73b5*/ esp += 4;
  /*5f73ba*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f73c1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f73c4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f73c7*/ goto L5f57f3;
  L5f73cc:;
  /*5f73cc*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f73d2*/ { u32 v = ecx; edx = v; }
  /*5f73d4*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f73da*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f73dc*/ { u32 v = eax; st32((u32)(edx + ecx), v); }
  /*5f73df*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f73e6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f73e9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f73ec*/ goto L5f57f3;
  L5f73f1:;
  /*5f73f1*/ ecx = (u32)(edi + (u32)52);
  /*5f73f4*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f73f9*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f73fc*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f73ff*/ if (!sf) goto L5f73cc;
  /*5f7401*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f7407*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f740b*/ eax = (u32)(ebp + (u32)(-108));
  /*5f740e*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  L5f7413:;
  /*5f7413*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7414*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7415*/ { u32 v = edi; ecx = v; }
  /*5f7417*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f7417*/ esp += 4;
  /*5f741c*/ { u32 v = eax; ecx = v; }
  /*5f741e*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f741e*/ esp += 4;
  /*5f7423*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f742a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f742d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7430*/ goto L5f57f3;
  L5f7435:;
  /*5f7435*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7438*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7439*/ ecx = (u32)(edi + (u32)52);
  /*5f743c*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f743c*/ esp += 4;
  /*5f7441*/ ecx = (u32)(edi + (u32)52);
  /*5f7444*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7449*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f744c*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f744f*/ if (!sf) goto L5f746f;
  /*5f7451*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f7454*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7455*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7456*/ { u32 v = edi; ecx = v; }
  /*5f7458*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f7458*/ esp += 4;
  /*5f745d*/ { u32 v = eax; ecx = v; }
  /*5f745f*/ eax = ext_50d7b0_thiscall2(ecx, ld32(esp + 0));
  /*5f745f*/ esp += 4;
  /*5f7464*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7467*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f746a*/ goto L5f57f3;
  L5f746f:;
  /*5f746f*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f7475*/ { u32 v = eax; edx = v; }
  /*5f7477*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); eax = v; }
  /*5f747a*/ { u32 v = eax; st32((u32)(edx + ecx), v); }
  /*5f747d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7480*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7483*/ goto L5f57f3;
  L5f7488:;
  /*5f7488*/ eax = (u32)(ebp + (u32)(-124));
  /*5f748b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f748c*/ ecx = (u32)(edi + (u32)52);
  /*5f748f*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f748f*/ esp += 4;
  /*5f7494*/ ecx = (u32)(edi + (u32)52);
  /*5f7497*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f749c*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f749f*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f74a2*/ if (!sf) goto L5f74ae;
  /*5f74a4*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f74a7*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f74a8*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f74a9*/ goto L5f6f7b;
  L5f74ae:;
  /*5f74ae*/ { X[0][0] = ld32((u32)(ebp + (u32)(-124))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f74b3*/ { u32 v = eax; ecx = v; }
  /*5f74b5*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f74bb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f74be*/ st32((u32)(ecx + eax), X[0][0]);
  /*5f74c3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f74c6*/ goto L5f57f3;
  L5f74cb:;
  /*5f74cb*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f74ce*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f74d1*/ if (!sf) goto L5f7502;
  /*5f74d3*/ { X[0][0] = ld32((u32)(esi + (u32)2)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f74d8*/ ecx = (u32)(ebp + (u32)(-108));
  /*5f74db*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f74dc*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f74dd*/ { u32 v = edi; ecx = v; }
  /*5f74df*/ st32((u32)(ebp + (u32)(-108)), X[0][0]);
  /*5f74e4*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f74e4*/ esp += 4;
  /*5f74e9*/ { u32 v = eax; ecx = v; }
  /*5f74eb*/ eax = ext_602cd0_thiscall2(ecx, ld32(esp + 0));
  /*5f74eb*/ esp += 4;
  /*5f74f0*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f74f7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f74fa*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f74fd*/ goto L5f57f3;
  L5f7502:;
  /*5f7502*/ { u32 v = eax; edx = v; }
  L5f7504:;
  /*5f7504*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f750a*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f750d*/ { u32 v = eax; st32((u32)(edx + ecx), v); }
  /*5f7510*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7517*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f751a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f751d*/ goto L5f57f3;
  L5f7522:;
  /*5f7522*/ { u32 v = (u32)ld16((u32)(esi)); ecx = v; }
  /*5f7525*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7528*/ if (!sf) goto L5f7555;
  /*5f752a*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); eax = v; }
  /*5f752d*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7530*/ eax = (u32)(ebp + (u32)(-108));
  /*5f7533*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7534*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7535*/ { u32 v = edi; ecx = v; }
  /*5f7537*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f7537*/ esp += 4;
  /*5f753c*/ { u32 v = eax; ecx = v; }
  /*5f753e*/ eax = ext_50d7b0_thiscall2(ecx, ld32(esp + 0));
  /*5f753e*/ esp += 4;
  /*5f7543*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)6U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f754a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f754d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7550*/ goto L5f57f3;
  L5f7555:;
  /*5f7555*/ { u32 v = ecx; edx = v; }
  /*5f7557*/ goto L5f7504;
  L5f7559:;
  /*5f7559*/ { u32 v = (u32)ld16((u32)(esi)); ecx = v; }
  /*5f755c*/ { u32 v = (u32)ld16((u32)(esi + (u32)2)); eax = v; }
  /*5f7560*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f7563*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7566*/ if (!sf) goto L5f7588;
  /*5f7568*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f756b*/ if (!sf) goto L5f757d;
  /*5f756d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f756e*/ { u32 v = edi; ecx = v; }
  /*5f7570*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f7570*/ esp += 4;
  /*5f7575*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f7578*/ goto L5f7413;
  L5f757d:;
  /*5f757d*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7583*/ goto L5f7413;
  L5f7588:;
  /*5f7588*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f758b*/ if (!sf) goto L5f75b8;
  /*5f758d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f758e*/ { u32 v = edi; ecx = v; }
  /*5f7590*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f7590*/ esp += 4;
  /*5f7595*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f7598*/ { u32 v = (ecx & 0xffff); edx = v; }
  /*5f759b*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f75a1*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f75a3*/ { u32 v = eax; st32((u32)(edx + ecx), v); }
  /*5f75a6*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f75ad*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f75b0*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f75b3*/ goto L5f57f3;
  L5f75b8:;
  /*5f75b8*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); edx = v; }
  /*5f75be*/ { u32 v = (ecx & 0xffff); ecx = v; }
  /*5f75c1*/ { u32 v = (u32)ld32((u32)(eax + edx)); eax = v; }
  /*5f75c4*/ { u32 v = eax; st32((u32)(ecx + edx), v); }
  /*5f75c7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f75ce*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f75d1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f75d4*/ goto L5f57f3;
  L5f75d9:;
  /*5f75d9*/ { u32 v = (u32)ld16((u32)(esi)); ecx = v; }
  /*5f75dc*/ { u32 v = (u32)ld16((u32)(esi + (u32)2)); eax = v; }
  /*5f75e0*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f75e3*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f75e6*/ if (!sf) goto L5f7588;
  /*5f75e8*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f75eb*/ if (!sf) goto L5f7604;
  /*5f75ed*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f75ee*/ { u32 v = edi; ecx = v; }
  /*5f75f0*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f75f0*/ esp += 4;
  /*5f75f5*/ { u32 v = eax; ecx = v; }
  /*5f75f7*/ eax = ext_5f3c40_thiscall1(ecx);
  /*5f75fc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f75ff*/ goto L5f73a4;
  L5f7604:;
  /*5f7604*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f760a*/ goto L5f73aa;
  L5f760f:;
  /*5f760f*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f7614*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7616*/ if (zf) goto L5f7625;
  /*5f7618*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f761a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f761d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7620*/ goto L5f57f3;
  L5f7625:;
  /*5f7625*/ __builtin_trap();
  L5f7631:;
  /*5f7631*/ ecx = (u32)(edi + (u32)52);
  /*5f7634*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f7639*/ { u32 v = eax; X[0][0] = v; X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f763d*/ { for (int k = 0; k < 4; k++) X[0][k] = F2U((float)(s32)X[0][k]); }
  /*5f7640*/ goto L5f6596;
  L5f7645:;
  /*5f7645*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7648*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7649*/ ecx = (u32)(edi + (u32)52);
  /*5f764c*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f764c*/ esp += 4;
  /*5f7651*/ eax = (u32)(ebp + (u32)(-176));
  /*5f7657*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7658*/ ecx = (u32)(edi + (u32)52);
  /*5f765b*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f765b*/ esp += 4;
  /*5f7660*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7663*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7664*/ ecx = (u32)(edi + (u32)52);
  /*5f7667*/ eax = ext_5f51e0_thiscall2(ecx, ld32(esp + 0));
  /*5f7667*/ esp += 4;
  /*5f766c*/ eax = (u32)(ebp + (u32)(-176));
  /*5f7672*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7673*/ ecx = (u32)(edi + (u32)52);
  /*5f7676*/ eax = ext_5f51e0_thiscall2(ecx, ld32(esp + 0));
  /*5f7676*/ esp += 4;
  /*5f767b*/ { u32 ea = (u32)(ebp + (u32)(-120)); u8 a = ld8(ea); u8 b = (u8)(u32)4U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f767f*/ if (!zf) goto L5f7689;
  /*5f7681*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); ecx = v; }
  /*5f7684*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f7686*/ { u32 fp = ld32((u32)(eax + (u32)40)); eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  L5f7689:;
  /*5f7689*/ { u32 ea = (u32)(ebp + (u32)(-172)); u8 a = ld8(ea); u8 b = (u8)(u32)4U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7690*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-120)), v); }
  /*5f7694*/ if (!zf) goto L5f76a1;
  /*5f7696*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-176))); ecx = v; }
  /*5f769c*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f769e*/ { u32 fp = ld32((u32)(eax + (u32)40)); eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  L5f76a1:;
  /*5f76a1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f76a4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f76a7*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-172)), v); }
  /*5f76ae*/ goto L5f57f3;
  L5f76b3:;
  /*5f76b3*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f76b5*/ ecx = (u32)(edi + (u32)52);
  /*5f76b8*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f76bb*/ { u32 v = (u32)ld32((u32)(esi + (u32)4)); eax = v; }
  /*5f76be*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f76c1*/ eax = (u32)(esi + (u32)8);
  /*5f76c4*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f76ca*/ eax = (u32)(ebp + (u32)(-124));
  /*5f76cd*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f76ce*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f76ce*/ esp += 4;
  /*5f76d3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f76d6*/ { u32 a = (u32)esi; u32 b = (u32)esi; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); esi = r; }
  /*5f76d8*/ { u32 a = (u32)ecx; u32 b = (u32)ecx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f76da*/ if (zf || sf != of) goto L5f7719;
  /*5f76dc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); edx = v; }
  L5f76e0:;
  /*5f76e0*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f76e6*/ { u32 a = (u32)edx; u32 b = (u32)(u32)ld32((u32)(eax)); u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f76e8*/ if (zf) goto L5f76fa;
  /*5f76ea*/ { u32 a = (u32)esi; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); esi = r; }
  /*5f76eb*/ { u32 a = (u32)eax; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f76ee*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f76f4*/ { u32 a = (u32)esi; u32 b = (u32)ecx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f76f6*/ if (sf != of) goto L5f76e0;
  /*5f76f8*/ goto L5f7719;
  L5f76fa:;
  /*5f76fa*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7701*/ { u32 v = edi; ecx = v; }
  /*5f7703*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f7709*/ { u32 v = (u32)ld32((u32)(eax)); esp -= 4; st32(esp, v); }
  /*5f770b*/ eax = ext_5f5620_thiscall2(ecx, ld32(esp + 0));
  /*5f770b*/ esp += 4;
  /*5f7710*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f7713*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  L5f7719:;
  /*5f7719*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); eax = v; }
  /*5f771c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f771f*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4294967295U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7722*/ if (zf) goto L5f57f0;
  /*5f7728*/ { u32 a = (u32)esi; u32 b = (u32)ecx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f772a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f772d*/ if (sf != of) goto L5f57f3;
  /*5f7733*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7734*/ goto L5f708d;
  L5f7739:;
  /*5f7739*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f773b*/ ecx = (u32)(edi + (u32)52);
  /*5f773e*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f7741*/ eax = (u32)(esi + (u32)8);
  /*5f7744*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f774a*/ eax = (u32)(ebp + (u32)(-124));
  /*5f774d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f774e*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f774e*/ esp += 4;
  /*5f7753*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f7756*/ { u32 a = (u32)esi; u32 b = (u32)esi; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); esi = r; }
  /*5f7758*/ { u32 a = (u32)ecx; u32 b = (u32)ecx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f775a*/ if (zf || sf != of) goto L5f779f;
  /*5f775c*/ { X[1][0] = ld32((u32)(ebp + (u32)(-124))); X[1][1] = X[1][2] = X[1][3] = 0; }
  L5f7761:;
  /*5f7761*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f7767*/ { X[0][0] = ld32((u32)(eax)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f776b*/ { float a = U2F(X[0][0]); float b = U2F(X[1][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f776e*/ if (!cf && !zf) goto L5f7780;
  /*5f7770*/ { u32 a = (u32)esi; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); esi = r; }
  /*5f7771*/ { u32 a = (u32)eax; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7774*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f777a*/ { u32 a = (u32)esi; u32 b = (u32)ecx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f777c*/ if (sf != of) goto L5f7761;
  /*5f777e*/ goto L5f779f;
  L5f7780:;
  /*5f7780*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7787*/ { u32 v = edi; ecx = v; }
  /*5f7789*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f778f*/ { u32 v = (u32)ld32((u32)(eax)); esp -= 4; st32(esp, v); }
  /*5f7791*/ eax = ext_5f5620_thiscall2(ecx, ld32(esp + 0));
  /*5f7791*/ esp += 4;
  /*5f7796*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); ecx = v; }
  /*5f7799*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  L5f779f:;
  /*5f779f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f77a2*/ { u32 a = (u32)esi; u32 b = (u32)ecx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f77a4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f77a7*/ if (!zf) goto L5f57f3;
  /*5f77ad*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4294967292U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f77b4*/ goto L5f7085;
  L5f77b9:;
  /*5f77b9*/ { u32 v = (u32)34816U; eax = v; }
  /*5f77be*/ ecx = (u32)(edi + (u32)52);
  /*5f77c1*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f77c8*/ if (!zf) goto L5f7825;
  /*5f77ca*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f77cf*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f77d1*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f77d8*/ if (zf) goto L5f77ef;
  /*5f77da*/ { u32 v = (u32)65522U; ecx = v; }
  /*5f77df*/ { u32 v = (u32)1U; st8((u32)(ebp + (u32)(-141)), v); }
  /*5f77e6*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f77e9*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)2U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f77ed*/ goto L5f77fb;
  L5f77ef:;
  /*5f77ef*/ { u32 v = (u32)65523U; ecx = v; }
  /*5f77f4*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f77f7*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)3U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  L5f77fb:;
  /*5f77fb*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f7802*/ { u32 v = (u32)ld32((u32)(edi + (u32)4)); eax = v; }
  /*5f7805*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); ecx = v; }
  /*5f7808*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f780a*/ { u32 v = (u32)ld32((u32)(eax + (u32)4)); eax = v; }
  /*5f780d*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f780f*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f7812*/ ecx = (u32)(edi + (u32)52);
  /*5f7815*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f781a*/ __asm__ volatile("fadds %0" :: "m"(*(float *)(u32)(ebp + (u32)(-108))) : "st", "memory");
  /*5f781d*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(edi + (u32)10)) :: "st", "memory");
  /*5f7820*/ goto L5f7af0;
  L5f7825:;
  /*5f7825*/ eax = ext_5f4f70_thiscall1(ecx);
  /*5f782a*/ ecx = (u32)(edi + (u32)52);
  /*5f782d*/ eax = ext_5f4f70_thiscall1(ecx);
  /*5f7832*/ eax = ext_5fa630_stdcall0();
  /*5f7837*/ { u32 v = eax; edi = v; }
  /*5f7839*/ { u32 v = edi; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f783c*/ eax = ext_5fa630_stdcall0();
  /*5f7841*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); ecx = v; }
  /*5f7847*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f7849*/ { u32 v = (u32)ld32((u32)(ecx + (u32)36)); esp -= 4; st32(esp, v); }
  /*5f784c*/ { u32 v = eax; ecx = v; }
  /*5f784e*/ { u32 v = (u32)ld32((u32)(edx + (u32)28)); edx = v; }
  /*5f7851*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f7851*/ esp += 4;
  /*5f7853*/ { u32 v = (u32)ld32((u32)(edi)); edi = v; }
  /*5f7855*/ { u32 v = eax; esi = v; }
  /*5f7857*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f785d*/ { u32 v = eax; ecx = v; }
  /*5f785f*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f7861*/ { u32 v = (u32)ld32((u32)(edx + (u32)40)); edx = v; }
  /*5f7864*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f7866*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7867*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7868*/ { u32 v = (u32)7048892U; esp -= 4; st32(esp, v); }
  /*5f786d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); esp -= 4; st32(esp, v); }
  /*5f7870*/ { u32 fp = ld32((u32)(edi + (u32)12)); eax = ((u32( *)(u32, u32, u32, u32))fp)(ld32(esp + 0), ld32(esp + 4), ld32(esp + 8), ld32(esp + 12)); }
  /*5f7873*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f7879*/ { u32 a = (u32)esp; u32 b = (u32)(u32)16U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f787c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f787f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7882*/ goto L5f57f3;
  L5f7887:;
  /*5f7887*/ { u32 v = (u32)34816U; eax = v; }
  /*5f788c*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7893*/ if (!zf) goto L5f78fd;
  /*5f7895*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); eax = v; }
  /*5f7898*/ { u32 v = (u32)ld32((u32)(esi)); esi = v; }
  /*5f789a*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f789d*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f78a3*/ { u32 v = (u32)ld32((u32)(edi + (u32)4)); eax = v; }
  /*5f78a6*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); ecx = v; }
  /*5f78a9*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f78ab*/ { u32 v = (u32)ld32((u32)(eax + (u32)4)); eax = v; }
  /*5f78ae*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f78b0*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f78b6*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-108))) :: "st", "memory");
  /*5f78b9*/ { X[0][0] = ld32((u32)(ebp + (u32)(-108))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f78be*/ { float b = U2F(ld32((u32)(eax))); X[0][0] = F2U(U2F(X[0][0]) + b); }
  /*5f78c2*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f78c5*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f78cb*/ st32((u32)(edi + (u32)10), X[0][0]);
  /*5f78d0*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f78d7*/ { u32 a = (u32)esi; u32 b = (u32)esi; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f78d9*/ if (!zf) goto L5f8ae9;
  /*5f78df*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f78e2*/ { u32 v = (u32)65523U; ecx = v; }
  /*5f78e7*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f78ea*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f78ed*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)3U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f78f1*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f78f8*/ goto L5f57f3;
  L5f78fd:;
  /*5f78fd*/ eax = ext_5fa630_stdcall0();
  /*5f7902*/ { u32 v = eax; edi = v; }
  /*5f7904*/ { u32 v = edi; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7907*/ eax = ext_5fa630_stdcall0();
  /*5f790c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); ecx = v; }
  /*5f7912*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f7914*/ { u32 v = (u32)ld32((u32)(ecx + (u32)36)); esp -= 4; st32(esp, v); }
  /*5f7917*/ { u32 v = eax; ecx = v; }
  /*5f7919*/ { u32 v = (u32)ld32((u32)(edx + (u32)28)); edx = v; }
  /*5f791c*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f791c*/ esp += 4;
  /*5f791e*/ { u32 v = (u32)ld32((u32)(edi)); edi = v; }
  /*5f7920*/ { u32 v = eax; esi = v; }
  /*5f7922*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f7928*/ { u32 v = eax; ecx = v; }
  /*5f792a*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f792c*/ { u32 v = (u32)ld32((u32)(edx + (u32)40)); edx = v; }
  /*5f792f*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f7931*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7932*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7933*/ { u32 v = (u32)7048892U; esp -= 4; st32(esp, v); }
  /*5f7938*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); esp -= 4; st32(esp, v); }
  /*5f793b*/ { u32 fp = ld32((u32)(edi + (u32)12)); eax = ((u32( *)(u32, u32, u32, u32))fp)(ld32(esp + 0), ld32(esp + 4), ld32(esp + 8), ld32(esp + 12)); }
  /*5f793e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f7944*/ { u32 a = (u32)esp; u32 b = (u32)(u32)16U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f7947*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f794a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f794d*/ goto L5f57f3;
  L5f7952:;
  /*5f7952*/ { u32 v = (u32)34816U; eax = v; }
  /*5f7957*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f795e*/ if (zf) goto L5f8b01;
  /*5f7964*/ eax = ext_5fa630_stdcall0();
  /*5f7969*/ { u32 v = (u32)7048952U; esp -= 4; st32(esp, v); }
  /*5f796e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f796f*/ { u32 v = (u32)ld32((u32)(eax)); ecx = v; }
  /*5f7971*/ { u32 fp = ld32((u32)(ecx + (u32)12)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f7974*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7977*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f797a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f797d*/ goto L5f57f3;
  L5f7982:;
  /*5f7982*/ { u32 v = esi; ecx = v; }
  /*5f7984*/ { u32 v = esi; st32((u32)(edi + (u32)22), v); }
  /*5f7987*/ { u32 v = (u32)34816U; eax = v; }
  /*5f798c*/ edx = (u32)(ecx + (u32)1);
  /*5f798f*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7996*/ if (!zf) goto L5f79c0;
  L5f7998:;
  /*5f7998*/ { u32 v = (u32)ld8((u32)(ecx)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f799a*/ { u32 a = (u32)ecx; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); ecx = r; }
  /*5f799b*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(eax & 0xff); u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f799d*/ if (!zf) goto L5f7998;
  /*5f799f*/ { u32 a = (u32)ecx; u32 b = (u32)edx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f79a1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f79a4*/ eax = (u32)(ecx + (u32)1);
  /*5f79a7*/ { u32 v = (u32)100000000U; ecx = v; }
  /*5f79ac*/ { u32 a = (u32)eax; u32 b = (u32)esi; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f79ae*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f79b1*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f79b7*/ goto L5f57f3;
  L5f79c0:;
  /*5f79c0*/ { u32 v = (u32)ld8((u32)(ecx)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f79c2*/ { u32 a = (u32)ecx; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); ecx = r; }
  /*5f79c3*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(eax & 0xff); u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f79c5*/ if (!zf) goto L5f79c0;
  /*5f79c7*/ { u32 a = (u32)ecx; u32 b = (u32)edx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f79c9*/ eax = (u32)(ecx + (u32)1);
  /*5f79cc*/ { u32 a = (u32)eax; u32 b = (u32)esi; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f79ce*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f79d4*/ eax = ext_5fa630_stdcall0();
  /*5f79d9*/ { u32 v = (u32)7049012U; esp -= 4; st32(esp, v); }
  /*5f79de*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f79df*/ { u32 v = (u32)ld32((u32)(eax)); ecx = v; }
  /*5f79e1*/ { u32 fp = ld32((u32)(ecx + (u32)12)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f79e4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f79e7*/ { u32 v = (u32)100000000U; ecx = v; }
  /*5f79ec*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f79ef*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f79f2*/ goto L5f57f3;
  L5f79f7:;
  /*5f79f7*/ { u32 v = (u32)ld32((u32)(esi)); edx = v; }
  /*5f79f9*/ eax = (u32)(esi + (u32)4);
  /*5f79fc*/ { u32 a = (u32)edx; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); edx = r; }
  /*5f79fd*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f7a03*/ { u32 v = edx; st32((u32)(ebp + (u32)(-116)), v); }
  /*5f7a06*/ goto L5f57f0;
  L5f7a0b:;
  /*5f7a0b*/ { u32 v = (u32)ld32((u32)(esi + (u32)4)); edx = v; }
  /*5f7a0e*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967295U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7a11*/ if (zf || sf != of) goto L5f7085;
  /*5f7a17*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); eax = v; }
  /*5f7a1d*/ { u32 v = (u32)ld32((u32)(eax + (u32)64)); ecx = v; }
  /*5f7a20*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f7a26*/ { u32 v = edx; st32((u32)(ecx + eax), v); }
  /*5f7a29*/ goto L5f7085;
  L5f7a2e:;
  /*5f7a2e*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f7a30*/ { u32 v = eax; st32((u32)(edi + (u32)18), v); }
  L5f7a33:;
  /*5f7a33*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7a36*/ eax = (u32)(esi + (u32)4);
  /*5f7a39*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7a3c*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f7a42*/ goto L5f57f3;
  L5f7a47:;
  /*5f7a47*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); eax = v; }
  /*5f7a4d*/ { u32 v = (u32)ld32((u32)(eax + (u32)64)); ecx = v; }
  /*5f7a50*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f7a56*/ { u32 ea = (u32)(ecx + eax); u32 a = ld32(ea); u32 b = (u32)(u32)1U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7a5a*/ if (!zf) goto L5f7a33;
  L5f7a5c:;
  /*5f7a5c*/ { u32 v = (u32)ld32((u32)(esi)); esp -= 4; st32(esp, v); }
  /*5f7a5e*/ goto L5f708d;
  L5f7a63:;
  /*5f7a63*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); eax = v; }
  /*5f7a69*/ { u32 v = (u32)ld32((u32)(eax + (u32)64)); ecx = v; }
  /*5f7a6c*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f7a72*/ { u32 ea = (u32)(ecx + eax); u32 a = ld32(ea); u32 b = (u32)(u32)1U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7a76*/ if (!zf) goto L5f7a5c;
  /*5f7a78*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7a7b*/ eax = (u32)(esi + (u32)4);
  /*5f7a7e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7a81*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f7a87*/ goto L5f57f3;
  L5f7a8c:;
  /*5f7a8c*/ eax = (u32)(esi + (u32)4);
  /*5f7a8f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7a90*/ ecx = (u32)(edi + (u32)64);
  /*5f7a93*/ eax = ext_5f53f0_thiscall2(ecx, ld32(esp + 0));
  /*5f7a93*/ esp += 4;
  /*5f7a98*/ goto L5f7085;
  L5f7a9d:;
  /*5f7a9d*/ { u32 ea = (u32)(edi + (u32)72); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7aa1*/ if (!zf) goto L5f587e;
  /*5f7aa7*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f7aae*/ { u32 v = (u32)65521U; ecx = v; }
  /*5f7ab3*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f7ab6*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)1U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f7aba*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f7ac1*/ { u32 ea = (u32)(edi + (u32)18); u32 a = ld32(ea); u32 b = (u32)(u32)4294967295U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7ac5*/ if (!zf) goto L5f7ada;
  /*5f7ac7*/ { u32 v = (u32)16384U; eax = v; }
  /*5f7acc*/ { u32 v = (u32)1U; st8((u32)(ebp + (u32)(-141)), v); }
  /*5f7ad3*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); st16(ea, r); }
  L5f7ada:;
  /*5f7ada*/ { u32 v = (u32)ld32((u32)(edi + (u32)18)); eax = v; }
  /*5f7add*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4294967295U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7ae0*/ if (zf) goto L5f8b41;
  /*5f7ae6*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f7ae8*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7ae9*/ { u32 v = edi; ecx = v; }
  /*5f7aeb*/ eax = ext_5f9130_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f7aeb*/ esp += 8;
  L5f7af0:;
  /*5f7af0*/ { u32 ea = (u32)(ebp + (u32)(-141)); u8 a = ld8(ea); u8 b = (u8)(u32)0U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7af7*/ if (!zf) goto L5f8bb6;
  /*5f7afd*/ goto L5f57e7;
  L5f7b02:;
  /*5f7b02*/ { u32 v = (u32)ld32((u32)(esi + (u32)4)); edx = v; }
  /*5f7b05*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967295U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7b08*/ if (zf || sf != of) goto L5f7b1c;
  /*5f7b0a*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); eax = v; }
  /*5f7b10*/ { u32 v = (u32)ld32((u32)(eax + (u32)64)); ecx = v; }
  /*5f7b13*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f7b19*/ { u32 v = edx; st32((u32)(ecx + eax), v); }
  L5f7b1c:;
  /*5f7b1c*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f7b22*/ { u32 v = edi; ecx = v; }
  /*5f7b24*/ { u32 v = (u32)ld32((u32)(eax)); esp -= 4; st32(esp, v); }
  /*5f7b26*/ eax = ext_5f4d80_thiscall2(ecx, ld32(esp + 0));
  /*5f7b26*/ esp += 4;
  /*5f7b2b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7b2e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7b31*/ goto L5f57f3;
  L5f7b36:;
  /*5f7b36*/ { u32 v = (u32)ld32((u32)(esi + (u32)2)); edx = v; }
  /*5f7b39*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967295U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7b3c*/ if (zf || sf != of) goto L5f7b50;
  /*5f7b3e*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); eax = v; }
  /*5f7b44*/ { u32 v = (u32)ld32((u32)(eax + (u32)64)); ecx = v; }
  /*5f7b47*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f7b4d*/ { u32 v = edx; st32((u32)(ecx + eax), v); }
  L5f7b50:;
  /*5f7b50*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f7b56*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); ecx = v; }
  /*5f7b5c*/ { u32 v = (u32)ld16((u32)(eax)); eax = v; }
  /*5f7b5f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7b60*/ eax = ext_5f4a80_thiscall2(ecx, ld32(esp + 0));
  /*5f7b60*/ esp += 4;
  /*5f7b65*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7b66*/ { u32 v = edi; ecx = v; }
  /*5f7b68*/ eax = ext_5f4dc0_thiscall2(ecx, ld32(esp + 0));
  /*5f7b68*/ esp += 4;
  /*5f7b6d*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(eax & 0xff); u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7b6f*/ if (zf) goto L5f8bb6;
  /*5f7b75*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7b78*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7b7b*/ goto L5f57f3;
  L5f7b80:;
  /*5f7b80*/ { u32 v = (u32)ld32((u32)(esi)); esp -= 4; st32(esp, v); }
  /*5f7b82*/ { u32 v = (u32)ld32((u32)(edi + (u32)4)); ecx = v; }
  /*5f7b85*/ { u32 v = edi; esp -= 4; st32(esp, v); }
  /*5f7b86*/ eax = ext_5fbb00_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f7b86*/ esp += 8;
  /*5f7b8b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7b92*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7b95*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7b98*/ goto L5f57f3;
  L5f7b9d:;
  /*5f7b9d*/ eax = (u32)(ebp + (u32)(-124));
  /*5f7ba0*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7ba1*/ ecx = (u32)(edi + (u32)52);
  /*5f7ba4*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f7ba4*/ esp += 4;
  /*5f7ba9*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); edx = v; }
  /*5f7baf*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f7bb5*/ { u32 v = (u32)ld32((u32)(edx + (u32)8)); ecx = v; }
  /*5f7bb8*/ { u32 v = (u32)ld32((u32)(ecx + eax)); eax = v; }
  /*5f7bbb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); ecx = v; }
  /*5f7bbe*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7bc1*/ { u32 a = (u32)ecx; u32 b = (u32)ecx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7bc3*/ if (sf) goto L5f7bf5;
  /*5f7bc5*/ { u32 a = (u32)ecx; u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7bc7*/ if (sf == of) goto L5f7bf5;
  /*5f7bc9*/ { u32 v = (u32)ld32((u32)(edx)); eax = v; }
  /*5f7bcb*/ { s32 a = (s32)eax, b = (s32)ecx; s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f7bce*/ ecx = (u32)(edi + (u32)52);
  /*5f7bd1*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edx + (u32)4)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7bd4*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edx + (u32)8)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7bd7*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7bda*/ eax = (u32)(ebp + (u32)(-108));
  /*5f7bdd*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7bde*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f7bde*/ esp += 4;
  /*5f7be3*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)12U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7bea*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7bed*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7bf0*/ goto L5f57f3;
  L5f7bf5:;
  /*5f7bf5*/ eax = ext_5fa630_stdcall0();
  /*5f7bfa*/ { u32 v = eax; esi = v; }
  /*5f7bfc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f7c02*/ { u32 v = eax; ecx = v; }
  /*5f7c04*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f7c06*/ { u32 v = (u32)ld32((u32)(esi)); edi = v; }
  /*5f7c08*/ { u32 v = (u32)ld32((u32)(edx + (u32)40)); edx = v; }
  /*5f7c0b*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f7c0d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7c0e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); esp -= 4; st32(esp, v); }
  /*5f7c11*/ eax = (u32)(ebp + (u32)(-104));
  /*5f7c14*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); esp -= 4; st32(esp, v); }
  /*5f7c17*/ { u32 v = (u32)7049192U; esp -= 4; st32(esp, v); }
  /*5f7c1c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7c1d*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7c1e*/ { u32 fp = ld32((u32)(edi + (u32)20)); eax = ((u32( *)(u32, u32, u32, u32, u32, u32))fp)(ld32(esp + 0), ld32(esp + 4), ld32(esp + 8), ld32(esp + 12), ld32(esp + 16), ld32(esp + 20)); }
  /*5f7c21*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f7c26*/ { u32 a = (u32)esp; u32 b = (u32)(u32)24U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f7c29*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7c2b*/ if (zf) goto L5f7c47;
  /*5f7c2d*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f7c2f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f7c35*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7c38*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7c3b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)12U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f7c42*/ goto L5f57f3;
  L5f7c47:;
  /*5f7c47*/ __builtin_trap();
  L5f7c60:;
  /*5f7c60*/ { u32 v = (u32)ld32((u32)(edi + (u32)100)); eax = v; }
  /*5f7c63*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7c66*/ goto L5f5936;
  L5f7c6b:;
  /*5f7c6b*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f7c6e*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); ecx = v; }
  /*5f7c74*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7c75*/ eax = ext_5ffb00_thiscall2(ecx, ld32(esp + 0));
  /*5f7c75*/ esp += 4;
  /*5f7c7a*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); ecx = v; }
  /*5f7c80*/ { u32 v = eax; esi = v; }
  /*5f7c82*/ { u32 v = (u32)ld16((u32)(ecx + (u32)2)); ecx = v; }
  /*5f7c86*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7c87*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); ecx = v; }
  /*5f7c8d*/ eax = ext_5ffb00_thiscall2(ecx, ld32(esp + 0));
  /*5f7c8d*/ esp += 4;
  /*5f7c92*/ { u32 v = (u32)7049272U; esp -= 4; st32(esp, v); }
  /*5f7c97*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7c98*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7c9b*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f7ca1*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); ecx = v; }
  /*5f7ca7*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f7caa*/ { u32 v = (u32)ld16((u32)(ecx + (u32)4)); eax = v; }
  /*5f7cae*/ { u32 v = eax; st32((u32)(ebp + (u32)(-148)), v); }
  /*5f7cb4*/ { u32 v = (u32)ld32((u32)(ecx + (u32)6)); eax = v; }
  /*5f7cb7*/ { u32 a = (u32)ecx; u32 b = (u32)(u32)10U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f7cba*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f7cbd*/ { u32 a = (u32)eax; u32 r = alu_sar<u32>(a, 16, cf, zf, sf, of, pf); eax = r; }
  /*5f7cc0*/ { u32 a = (u32)eax; u32 b = (u32)(u32)2U; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7cc3*/ { u32 v = ecx; st32((u32)(edi + (u32)166), v); }
  /*5f7cc9*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f7ccf*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f7cd1*/ if (zf) goto L5f7ce4;
  /*5f7cd3*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f7cd5*/ { u32 v = edi; ecx = v; }
  /*5f7cd7*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7cd8*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f7cda*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32, u32, u32))fp)(ecx, ld32(esp + 0), ld32(esp + 4)); }
  /*5f7cda*/ esp += 8;
  /*5f7cdc*/ { u32 v = eax; st32((u32)(ebp + (u32)(-140)), v); }
  /*5f7ce2*/ goto L5f7d03;
  L5f7ce4:;
  /*5f7ce4*/ ecx = (u32)(edi + (u32)52);
  /*5f7ce7*/ eax = ext_5f4ec0_thiscall2(ecx, ld32(esp + 0));
  /*5f7ce7*/ esp += 4;
  /*5f7cec*/ { u32 v = (u32)ld32((u32)(eax)); ecx = v; }
  /*5f7cee*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f7cf0*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); eax = v; }
  /*5f7cf3*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f7cf5*/ ecx = (u32)(edi + (u32)52);
  /*5f7cf8*/ { u32 v = eax; st32((u32)(ebp + (u32)(-140)), v); }
  /*5f7cfe*/ eax = ext_5f4f70_thiscall1(ecx);
  L5f7d03:;
  /*5f7d03*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f7d06*/ edx = (u32)(edi + (u32)52);
  /*5f7d09*/ { u32 v = (u32)ld32((u32)(edi + (u32)60)); ecx = v; }
  /*5f7d0c*/ { u32 a = (u32)eax; u32 r = alu_sar<u32>(a, 8, cf, zf, sf, of, pf); eax = r; }
  /*5f7d0f*/ { u32 v = (eax & 0xff); eax = v; }
  /*5f7d12*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7d13*/ { u32 a = (u32)ecx; u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f7d15*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7d16*/ { u32 v = edx; esp -= 4; st32(esp, v); }
  /*5f7d17*/ ecx = (u32)(ebp + (u32)(-212));
  /*5f7d1d*/ eax = ext_5f3440_thiscall4(ecx, ld32(esp + 0), ld32(esp + 4), ld32(esp + 8));
  /*5f7d1d*/ esp += 12;
  /*5f7d22*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); eax = v; }
  /*5f7d25*/ ecx = (u32)(edi + (u32)52);
  /*5f7d28*/ { u32 v = (eax & 0xff); esi = v; }
  /*5f7d2b*/ eax = (u32)(ebp + (u32)(-184));
  /*5f7d31*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7d32*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7d33*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-184)), v); }
  /*5f7d3d*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-180)), v); }
  /*5f7d44*/ eax = ext_5f5490_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f7d44*/ esp += 8;
  /*5f7d49*/ { u32 v = (u32)ld32((u32)(edi + (u32)60)); eax = v; }
  /*5f7d4c*/ ecx = (u32)(ebp + (u32)(-260));
  /*5f7d52*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7d53*/ { u32 a = (u32)eax; u32 b = (u32)esi; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7d55*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7d56*/ eax = (u32)(edi + (u32)52);
  /*5f7d59*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7d5a*/ eax = ext_5f3440_thiscall4(ecx, ld32(esp + 0), ld32(esp + 4), ld32(esp + 8));
  /*5f7d5a*/ esp += 12;
  /*5f7d5f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); eax = v; }
  /*5f7d62*/ ecx = (u32)(ebp + (u32)(-168));
  /*5f7d68*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-140))); esi = v; }
  /*5f7d6e*/ { u32 v = eax; st32((u32)(ebp + (u32)(-168)), v); }
  /*5f7d74*/ eax = (u32)(ebp + (u32)(-212));
  /*5f7d7a*/ { u32 v = eax; st32((u32)(ebp + (u32)(-164)), v); }
  /*5f7d80*/ eax = (u32)(ebp + (u32)(-260));
  /*5f7d86*/ { u32 v = eax; st32((u32)(ebp + (u32)(-160)), v); }
  /*5f7d8c*/ eax = (u32)(edi + (u32)2762);
  /*5f7d92*/ { u32 v = eax; st32((u32)(ebp + (u32)(-156)), v); }
  /*5f7d98*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-148))); eax = v; }
  /*5f7d9e*/ { u32 v = (eax & 0xffff); st16((u32)(ebp + (u32)(-152)), v); }
  /*5f7da5*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f7da7*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7da8*/ { u32 v = esi; ecx = v; }
  /*5f7daa*/ { u32 fp = ld32((u32)(eax + (u32)20)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f7daa*/ esp += 4;
  /*5f7dad*/ { u32 ea = (u32)(ebp + (u32)(-132)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7db4*/ if (zf) goto L5f7dc0;
  /*5f7db6*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f7db8*/ { u32 v = edi; ecx = v; }
  /*5f7dba*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7dbb*/ { u32 fp = ld32((u32)(eax + (u32)4)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f7dbb*/ esp += 4;
  /*5f7dbe*/ goto L5f7dc7;
  L5f7dc0:;
  /*5f7dc0*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f7dc2*/ { u32 v = esi; ecx = v; }
  /*5f7dc4*/ { u32 fp = ld32((u32)(eax + (u32)40)); eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  L5f7dc7:;
  /*5f7dc7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-204))); eax = v; }
  /*5f7dcd*/ ecx = (u32)(edi + (u32)52);
  /*5f7dd0*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f7dd6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-208))); eax = v; }
  /*5f7ddc*/ { u32 v = eax; st32((u32)(ebp + (u32)(-148)), v); }
  /*5f7de2*/ eax = (u32)(ebp + (u32)(-132));
  /*5f7de8*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7de9*/ eax = (u32)(ebp + (u32)(-148));
  /*5f7def*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7df0*/ eax = ext_5f5520_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f7df0*/ esp += 8;
  L5f7df5:;
  /*5f7df5*/ { u32 ea = (u32)(edi + (u32)172); u8 a = ld8(ea); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7dfc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7dff*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7e02*/ if (zf) goto L5f57f3;
  /*5f7e08*/ { u32 v = (u32)34816U; eax = v; }
  /*5f7e0d*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7e14*/ if (!zf) goto L5f57f3;
  L5f7e1a:;
  /*5f7e1a*/ { u32 ea = (u32)(edi + (u32)84); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7e1e*/ if (!zf) goto L5f8bb6;
  /*5f7e24*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f7e27*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f7e2a*/ goto L5f57f3;
  L5f7e2f:;
  /*5f7e2f*/ { u32 v = (u32)ld16((u32)(esi + (u32)2)); eax = v; }
  /*5f7e33*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); ecx = v; }
  /*5f7e39*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7e3a*/ eax = ext_5ffb00_thiscall2(ecx, ld32(esp + 0));
  /*5f7e3a*/ esp += 4;
  /*5f7e3f*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); ecx = v; }
  /*5f7e45*/ { u32 v = eax; st32((u32)(ebp + (u32)(-148)), v); }
  /*5f7e4b*/ { u32 v = (u32)ld16((u32)(ecx + (u32)4)); eax = v; }
  /*5f7e4f*/ { u32 v = (u32)ld16((u32)(ecx)); ecx = v; }
  /*5f7e52*/ { u32 v = eax; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f7e55*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7e58*/ if (!sf) goto L5f7e64;
  /*5f7e5a*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7e5b*/ { u32 v = edi; ecx = v; }
  /*5f7e5d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f7e5d*/ esp += 4;
  /*5f7e62*/ goto L5f7e6c;
  L5f7e64:;
  /*5f7e64*/ { u32 v = ecx; eax = v; }
  /*5f7e66*/ { u32 a = (u32)eax; u32 b = (u32)(u32)ld32((u32)(edi + (u32)158)); u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  L5f7e6c:;
  /*5f7e6c*/ { u32 v = (u32)ld32((u32)(eax)); edi = v; }
  /*5f7e6e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); esi = v; }
  /*5f7e74*/ { u32 v = (u32)ld32((u32)(esi + (u32)166)); eax = v; }
  /*5f7e7a*/ { u32 v = (u32)ld32((u32)(esi + (u32)60)); ecx = v; }
  /*5f7e7d*/ { u32 v = (u32)ld32((u32)(eax + (u32)6)); edx = v; }
  /*5f7e80*/ { u32 a = (u32)eax; u32 b = (u32)(u32)10U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7e83*/ { u32 v = eax; st32((u32)(esi + (u32)166), v); }
  /*5f7e89*/ { u32 v = edx; eax = v; }
  /*5f7e8b*/ { u32 a = (u32)eax; u32 r = alu_sar<u32>(a, 8, cf, zf, sf, of, pf); eax = r; }
  /*5f7e8e*/ { u32 v = (eax & 0xff); eax = v; }
  /*5f7e91*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7e92*/ { u32 a = (u32)ecx; u32 b = (u32)eax; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f7e94*/ { u32 v = edx; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f7e9a*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7e9b*/ edx = (u32)(esi + (u32)52);
  /*5f7e9e*/ { u32 v = edx; esp -= 4; st32(esp, v); }
  /*5f7e9f*/ ecx = (u32)(ebp + (u32)(-224));
  /*5f7ea5*/ eax = ext_5f3440_thiscall4(ecx, ld32(esp + 0), ld32(esp + 4), ld32(esp + 8));
  /*5f7ea5*/ esp += 12;
  /*5f7eaa*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-132))); eax = v; }
  /*5f7eb0*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); ecx = v; }
  /*5f7eb6*/ { u32 v = (eax & 0xff); esi = v; }
  /*5f7eb9*/ eax = (u32)(ebp + (u32)(-192));
  /*5f7ebf*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7ec0*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7ec1*/ ecx = (u32)(ecx + (u32)52);
  /*5f7ec4*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-192)), v); }
  /*5f7ece*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-188)), v); }
  /*5f7ed5*/ eax = ext_5f5490_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f7ed5*/ esp += 8;
  /*5f7eda*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); ecx = v; }
  /*5f7ee0*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7ee1*/ { u32 v = (u32)ld32((u32)(ecx + (u32)60)); eax = v; }
  /*5f7ee4*/ { u32 a = (u32)eax; u32 b = (u32)esi; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7ee6*/ esi = (u32)(ecx + (u32)52);
  /*5f7ee9*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7eea*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7eeb*/ ecx = (u32)(ebp + (u32)(-272));
  /*5f7ef1*/ eax = ext_5f3440_thiscall4(ecx, ld32(esp + 0), ld32(esp + 4), ld32(esp + 8));
  /*5f7ef1*/ esp += 12;
  /*5f7ef6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-148))); eax = v; }
  /*5f7efc*/ ecx = (u32)(ebp + (u32)(-168));
  /*5f7f02*/ { u32 v = eax; st32((u32)(ebp + (u32)(-168)), v); }
  /*5f7f08*/ eax = (u32)(ebp + (u32)(-224));
  /*5f7f0e*/ { u32 v = eax; st32((u32)(ebp + (u32)(-164)), v); }
  /*5f7f14*/ eax = (u32)(ebp + (u32)(-272));
  /*5f7f1a*/ { u32 v = eax; st32((u32)(ebp + (u32)(-160)), v); }
  /*5f7f20*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f7f26*/ { u32 a = (u32)eax; u32 b = (u32)(u32)2762U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f7f2b*/ { u32 v = eax; st32((u32)(ebp + (u32)(-156)), v); }
  /*5f7f31*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-108))); eax = v; }
  /*5f7f34*/ { u32 v = (eax & 0xffff); st16((u32)(ebp + (u32)(-152)), v); }
  /*5f7f3b*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f7f3d*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f7f3e*/ { u32 v = edi; ecx = v; }
  /*5f7f40*/ { u32 fp = ld32((u32)(eax + (u32)20)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f7f40*/ esp += 4;
  /*5f7f43*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-216))); eax = v; }
  /*5f7f49*/ { u32 v = esi; ecx = v; }
  /*5f7f4b*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f7f51*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-220))); eax = v; }
  /*5f7f57*/ { u32 v = eax; st32((u32)(ebp + (u32)(-148)), v); }
  /*5f7f5d*/ eax = (u32)(ebp + (u32)(-132));
  /*5f7f63*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7f64*/ eax = (u32)(ebp + (u32)(-148));
  /*5f7f6a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7f6b*/ eax = ext_5f5520_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f7f6b*/ esp += 8;
  /*5f7f70*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f7f76*/ goto L5f7df5;
  L5f7f7b:;
  /*5f7f7b*/ { u32 v = (u32)7047048U; esp -= 4; st32(esp, v); }
  /*5f7f80*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7f81*/ { u32 v = (u32)ld32((u32)((u32)6775828)); esi = v; }
  /*5f7f87*/ { u32 fp = esi; eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f7f89*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f7f8c*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7f8e*/ if (!zf) goto L5f7fa7;
  /*5f7f90*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f7f96*/ ecx = (u32)(edi + (u32)52);
  /*5f7f99*/ eax = (u32)(ebp + (u32)(-132));
  /*5f7f9f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7fa0*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f7fa0*/ esp += 4;
  /*5f7fa5*/ goto L5f7ff4;
  L5f7fa7:;
  /*5f7fa7*/ { u32 v = (u32)7049284U; esp -= 4; st32(esp, v); }
  /*5f7fac*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); esp -= 4; st32(esp, v); }
  /*5f7fb2*/ { u32 fp = esi; eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f7fb4*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f7fb7*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f7fb9*/ if (!zf) goto L5f7fd2;
  /*5f7fbb*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f7fc1*/ ecx = (u32)(edi + (u32)52);
  /*5f7fc4*/ eax = (u32)(ebp + (u32)(-132));
  /*5f7fca*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f7fcb*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f7fcb*/ esp += 4;
  /*5f7fd0*/ goto L5f7ff4;
  L5f7fd2:;
  /*5f7fd2*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f7fd4*/ { u32 v = edi; ecx = v; }
  /*5f7fd6*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f7fd8*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); esp -= 4; st32(esp, v); }
  /*5f7fde*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f7fe0*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32, u32, u32))fp)(ecx, ld32(esp + 0), ld32(esp + 4)); }
  /*5f7fe0*/ esp += 8;
  /*5f7fe2*/ { u32 v = eax; esi = v; }
  /*5f7fe4*/ ecx = (u32)(edi + (u32)52);
  /*5f7fe7*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f7fe8*/ eax = ext_5f5390_thiscall2(ecx, ld32(esp + 0));
  /*5f7fe8*/ esp += 4;
  /*5f7fed*/ { u32 v = (u32)ld32((u32)(esi)); edx = v; }
  /*5f7fef*/ { u32 v = esi; ecx = v; }
  /*5f7ff1*/ { u32 fp = ld32((u32)(edx + (u32)40)); eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  L5f7ff4:;
  /*5f7ff4*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); edx = v; }
  /*5f7ffa*/ { u32 v = edx; ecx = v; }
  /*5f7ffc*/ esi = (u32)(ecx + (u32)1);
  L5f8000:;
  /*5f8000*/ { u32 v = (u32)ld8((u32)(ecx)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f8002*/ { u32 a = (u32)ecx; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); ecx = r; }
  /*5f8003*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(eax & 0xff); u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8005*/ if (!zf) goto L5f8000;
  /*5f8007*/ { u32 a = (u32)ecx; u32 b = (u32)esi; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f8009*/ eax = (u32)(edx + (u32)1);
  /*5f800c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f800f*/ { u32 a = (u32)eax; u32 b = (u32)ecx; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f8011*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8014*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f801a*/ goto L5f57f3;
  L5f801f:;
  /*5f801f*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f8022*/ { u32 v = (u32)ld32((u32)(edi + (u32)150)); ecx = v; }
  /*5f8028*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8029*/ eax = ext_5ffb00_thiscall2(ecx, ld32(esp + 0));
  /*5f8029*/ esp += 4;
  /*5f802e*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f802f*/ ecx = (u32)(edi + (u32)52);
  /*5f8032*/ eax = ext_5f53f0_thiscall2(ecx, ld32(esp + 0));
  /*5f8032*/ esp += 4;
  /*5f8037*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f803a*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8041*/ { u32 a = (u32)ecx; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); ecx = r; }
  /*5f8042*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8045*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f8048*/ goto L5f57f3;
  L5f804d:;
  /*5f804d*/ eax = (u32)(ebp + (u32)(-124));
  /*5f8050*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8051*/ ecx = (u32)(edi + (u32)52);
  /*5f8054*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f8054*/ esp += 4;
  /*5f8059*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f805f*/ { u32 v = (u32)ld16((u32)(eax)); eax = v; }
  /*5f8062*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f8068*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f806b*/ if (!sf) goto L5f809b;
  /*5f806d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f806e*/ { u32 v = edi; ecx = v; }
  /*5f8070*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f8070*/ esp += 4;
  /*5f8075*/ { u32 v = (u32)ld32((u32)(eax)); ecx = v; }
  /*5f8077*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f8079*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); eax = v; }
  /*5f807c*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f807e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); esi = v; }
  /*5f8081*/ { u32 v = edi; ecx = v; }
  /*5f8083*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8084*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-132))); esp -= 4; st32(esp, v); }
  /*5f808a*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f808d*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f808d*/ esp += 4;
  /*5f8092*/ { u32 v = eax; ecx = v; }
  /*5f8094*/ eax = ext_5f3fc0_thiscall2(ecx, ld32(esp + 0));
  /*5f8094*/ esp += 4;
  /*5f8099*/ goto L5f80c0;
  L5f809b:;
  /*5f809b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); ecx = v; }
  /*5f809e*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f80a1*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f80a7*/ { u32 v = (u32)ld32((u32)(esi + eax)); eax = v; }
  /*5f80aa*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f80ad*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f80af*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); eax = v; }
  /*5f80b2*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f80b4*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f80ba*/ { u32 v = eax; st32((u32)(esi + ecx), v); }
  /*5f80bd*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); esi = v; }
  L5f80c0:;
  /*5f80c0*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f80c2*/ { u32 v = edi; ecx = v; }
  /*5f80c4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); esp -= 4; st32(esp, v); }
  /*5f80c7*/ { u32 fp = ld32((u32)(eax + (u32)4)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f80c7*/ esp += 4;
  /*5f80ca*/ { u32 ea = (u32)(ebp + (u32)(-120)); u8 a = ld8(ea); u8 b = (u8)(u32)4U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f80ce*/ if (!zf) goto L5f80d7;
  /*5f80d0*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f80d2*/ { u32 v = esi; ecx = v; }
  /*5f80d4*/ { u32 fp = ld32((u32)(eax + (u32)40)); eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  L5f80d7:;
  /*5f80d7*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)2U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f80de*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f80e1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f80e4*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-120)), v); }
  /*5f80e8*/ goto L5f57f3;
  L5f80ed:;
  /*5f80ed*/ eax = (u32)(ebp + (u32)(-124));
  /*5f80f0*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f80f1*/ ecx = (u32)(edi + (u32)52);
  /*5f80f4*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f80f4*/ esp += 4;
  /*5f80f9*/ ecx = (u32)(edi + (u32)52);
  /*5f80fc*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f8101*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f8104*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f810a*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f810d*/ if (!sf) goto L5f8146;
  /*5f810f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8110*/ { u32 v = edi; ecx = v; }
  /*5f8112*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f8112*/ esp += 4;
  /*5f8117*/ { u32 v = (u32)ld32((u32)(eax)); ecx = v; }
  /*5f8119*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f811b*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); eax = v; }
  /*5f811e*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f8120*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); esi = v; }
  /*5f8123*/ { u32 v = esi; ecx = v; }
  /*5f8125*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f8128*/ { u32 v = (u32)ld32((u32)(esi)); edx = v; }
  /*5f812a*/ { u32 v = (u32)ld32((u32)(edx + (u32)36)); edx = v; }
  /*5f812d*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f812f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8130*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-132))); esp -= 4; st32(esp, v); }
  /*5f8136*/ { u32 v = edi; ecx = v; }
  /*5f8138*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f8138*/ esp += 4;
  /*5f813d*/ { u32 v = eax; ecx = v; }
  /*5f813f*/ eax = ext_5f3fc0_thiscall2(ecx, ld32(esp + 0));
  /*5f813f*/ esp += 4;
  /*5f8144*/ goto L5f816b;
  L5f8146:;
  /*5f8146*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); ecx = v; }
  /*5f8149*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f814c*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8152*/ { u32 v = (u32)ld32((u32)(esi + eax)); eax = v; }
  /*5f8155*/ { u32 v = eax; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f8158*/ { u32 v = (u32)ld32((u32)(ecx)); eax = v; }
  /*5f815a*/ { u32 v = (u32)ld32((u32)(eax + (u32)36)); eax = v; }
  /*5f815d*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f815f*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f8165*/ { u32 v = eax; st32((u32)(esi + ecx), v); }
  /*5f8168*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); esi = v; }
  L5f816b:;
  /*5f816b*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f816d*/ { u32 v = edi; ecx = v; }
  /*5f816f*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); esp -= 4; st32(esp, v); }
  /*5f8172*/ { u32 fp = ld32((u32)(eax + (u32)4)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f8172*/ esp += 4;
  L5f8175:;
  /*5f8175*/ { u32 ea = (u32)(ebp + (u32)(-120)); u8 a = ld8(ea); u8 b = (u8)(u32)4U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8179*/ if (!zf) goto L5f8182;
  /*5f817b*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f817d*/ { u32 v = esi; ecx = v; }
  /*5f817f*/ { u32 fp = ld32((u32)(eax + (u32)40)); eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  L5f8182:;
  /*5f8182*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8185*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8188*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-120)), v); }
  /*5f818c*/ goto L5f57f3;
  L5f8191:;
  /*5f8191*/ ecx = (u32)(edi + (u32)52);
  /*5f8194*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f8196*/ eax = ext_5f4ec0_thiscall2(ecx, ld32(esp + 0));
  /*5f8196*/ esp += 4;
  /*5f819b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f819c*/ ecx = (u32)(ebp + (u32)(-124));
  /*5f819f*/ eax = ext_5f3bf0_thiscall2(ecx, ld32(esp + 0));
  /*5f819f*/ esp += 4;
  /*5f81a4*/ { u32 v = esi; ecx = v; }
  /*5f81a6*/ edx = (u32)(ecx + (u32)1);
  L5f81b0:;
  /*5f81b0*/ { u32 v = (u32)ld8((u32)(ecx)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f81b2*/ { u32 a = (u32)ecx; u32 r = alu_inc<u32>(a, cf, zf, sf, of, pf); ecx = r; }
  /*5f81b3*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(eax & 0xff); u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f81b5*/ if (!zf) goto L5f81b0;
  /*5f81b7*/ { u32 a = (u32)ecx; u32 b = (u32)edx; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f81b9*/ eax = (u32)(ecx + (u32)1);
  /*5f81bc*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)eax; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f81c2*/ { u32 v = (u32)ld8((u32)(ebp + (u32)(-120))); eax = v; }
  /*5f81c6*/ { u32 a = (u32)eax; u32 b = (u32)(u32)1U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f81c9*/ if (zf) goto L5f823d;
  /*5f81cb*/ { u32 a = (u32)eax; u32 b = (u32)(u32)1U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f81ce*/ if (zf) goto L5f8323;
  /*5f81d4*/ { u32 a = (u32)eax; u32 b = (u32)(u32)2U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f81d7*/ if (zf) goto L5f81fb;
  /*5f81d9*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f81de*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f81e0*/ if (zf) goto L5f81ef;
  /*5f81e2*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f81e4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f81e7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f81ea*/ goto L5f57f3;
  L5f81ef:;
  /*5f81ef*/ __builtin_trap();
  L5f81fb:;
  /*5f81fb*/ eax = (u32)(ebp + (u32)(-124));
  /*5f81fe*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f81ff*/ ecx = (u32)(edi + (u32)52);
  /*5f8202*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f8202*/ esp += 4;
  /*5f8207*/ eax = (u32)(edi + (u32)52);
  /*5f820a*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-228)), v); }
  /*5f8214*/ { u32 v = eax; st32((u32)(ebp + (u32)(-236)), v); }
  /*5f821a*/ ecx = (u32)(ebp + (u32)(-236));
  /*5f8220*/ { u32 v = (u32)ld32((u32)(eax + (u32)8)); eax = v; }
  /*5f8223*/ { u32 v = eax; st32((u32)(ebp + (u32)(-232)), v); }
  /*5f8229*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); eax = v; }
  /*5f822c*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f822d*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f822e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-124))); esi = v; }
  /*5f8231*/ { u32 v = esi; ecx = v; }
  /*5f8233*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f8235*/ { u32 fp = ld32((u32)(eax + (u32)24)); eax = ((u32(THISCALL *)(u32, u32, u32))fp)(ecx, ld32(esp + 0), ld32(esp + 4)); }
  /*5f8235*/ esp += 8;
  /*5f8238*/ goto L5f8175;
  L5f823d:;
  /*5f823d*/ { u32 v = (u32)7047060U; esp -= 4; st32(esp, v); }
  /*5f8242*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8243*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f8249*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f824c*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f824e*/ if (!zf) goto L5f8281;
  /*5f8250*/ ecx = (u32)(edi + (u32)52);
  /*5f8253*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f8258*/ { u32 v = (u32)1065353216U; st32((u32)(ebp + (u32)(-128)), v); }
  /*5f825f*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8261*/ if (!zf) goto L5f826a;
  /*5f8263*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-128)), v); }
  L5f826a:;
  /*5f826a*/ eax = (u32)(ebp + (u32)(-128));
  /*5f826d*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f826e*/ ecx = (u32)(edi + (u32)52);
  /*5f8271*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f8271*/ esp += 4;
  /*5f8276*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8279*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f827c*/ goto L5f57f3;
  L5f8281:;
  /*5f8281*/ { u32 v = (u32)7046812U; esp -= 4; st32(esp, v); }
  /*5f8286*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8287*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f828d*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8290*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8292*/ if (!zf) goto L5f82c5;
  /*5f8294*/ ecx = (u32)(edi + (u32)52);
  /*5f8297*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f829c*/ ecx = (u32)(edi + (u32)52);
  /*5f829f*/ { u32 v = eax; X[0][0] = v; X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f82a3*/ eax = (u32)(ebp + (u32)(-132));
  /*5f82a9*/ { for (int k = 0; k < 4; k++) X[0][k] = F2U((float)(s32)X[0][k]); }
  /*5f82ac*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f82ad*/ st32((u32)(ebp + (u32)(-132)), X[0][0]);
  /*5f82b5*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f82b5*/ esp += 4;
  /*5f82ba*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f82bd*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f82c0*/ goto L5f57f3;
  L5f82c5:;
  /*5f82c5*/ { u32 v = (u32)7047028U; esp -= 4; st32(esp, v); }
  /*5f82ca*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f82cb*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f82d1*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f82d4*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f82d6*/ if (!zf) goto L5f8306;
  /*5f82d8*/ ecx = (u32)(edi + (u32)52);
  /*5f82db*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f82e0*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f82e2*/ ecx = (u32)(edi + (u32)52);
  /*5f82e5*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_sbb<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f82e7*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f82e9*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f82ef*/ eax = (u32)(ebp + (u32)(-132));
  /*5f82f5*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f82f6*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f82f6*/ esp += 4;
  /*5f82fb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f82fe*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8301*/ goto L5f57f3;
  L5f8306:;
  /*5f8306*/ { u32 v = (u32)7049292U; esp -= 4; st32(esp, v); }
  /*5f830b*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f830c*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f8312*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8315*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8318*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f831b*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f831d*/ if (zf) goto L5f57f3;
  L5f8323:;
  /*5f8323*/ { u32 v = (u32)7046808U; esp -= 4; st32(esp, v); }
  /*5f8328*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8329*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f832f*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8332*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8334*/ if (zf) goto L5f84c6;
  /*5f833a*/ { u32 v = (u32)7047028U; esp -= 4; st32(esp, v); }
  /*5f833f*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8340*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f8346*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8349*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f834b*/ if (zf) goto L5f84c6;
  /*5f8351*/ { u32 v = (u32)7047060U; esp -= 4; st32(esp, v); }
  /*5f8356*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8357*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f835d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8360*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8363*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8366*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8368*/ if (zf) goto L5f57f3;
  /*5f836e*/ { u32 v = (u32)7047100U; esp -= 4; st32(esp, v); }
  /*5f8373*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8374*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f837a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f837d*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8380*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8383*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8385*/ if (zf) goto L5f57f3;
  /*5f838b*/ { u32 v = (u32)7047112U; esp -= 4; st32(esp, v); }
  /*5f8390*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8391*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f8397*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f839a*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f839d*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f83a0*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f83a2*/ if (zf) goto L5f57f3;
  /*5f83a8*/ { u32 v = (u32)7047132U; esp -= 4; st32(esp, v); }
  /*5f83ad*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f83ae*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f83b4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f83b7*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f83ba*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f83bd*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f83bf*/ if (zf) goto L5f57f3;
  /*5f83c5*/ { u32 v = (u32)7047156U; esp -= 4; st32(esp, v); }
  /*5f83ca*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f83cb*/ { u32 fp = ld32((u32)((u32)6775828)); eax = ((u32( *)(u32, u32))fp)(ld32(esp + 0), ld32(esp + 4)); }
  /*5f83d1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f83d4*/ { u32 a = (u32)esp; u32 b = (u32)(u32)8U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f83d7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f83da*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f83dc*/ if (zf) goto L5f57f3;
  /*5f83e2*/ { u32 v = (u32)ld32((u32)(edi + (u32)60)); eax = v; }
  /*5f83e5*/ ecx = (u32)(ebp + (u32)(-248));
  /*5f83eb*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f83ed*/ { u32 a = (u32)eax; u32 r = alu_dec<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f83ee*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f83ef*/ eax = (u32)(edi + (u32)52);
  /*5f83f2*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f83f3*/ eax = ext_5f3440_thiscall4(ecx, ld32(esp + 0), ld32(esp + 4), ld32(esp + 8));
  /*5f83f3*/ esp += 12;
  /*5f83f8*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f83fa*/ eax = (u32)(ebp + (u32)(-200));
  /*5f8400*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-200)), v); }
  /*5f840a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f840b*/ ecx = (u32)(edi + (u32)52);
  /*5f840e*/ { u32 v = (u32)0U; st8((u32)(ebp + (u32)(-196)), v); }
  /*5f8415*/ eax = ext_5f5490_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f8415*/ esp += 8;
  /*5f841a*/ { u32 v = (u32)ld32((u32)(edi + (u32)60)); eax = v; }
  /*5f841d*/ ecx = (u32)(ebp + (u32)(-284));
  /*5f8423*/ { u32 v = (u32)1U; esp -= 4; st32(esp, v); }
  /*5f8425*/ { u32 a = (u32)eax; u32 r = alu_dec<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f8426*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8427*/ eax = (u32)(edi + (u32)52);
  /*5f842a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f842b*/ eax = ext_5f3440_thiscall4(ecx, ld32(esp + 0), ld32(esp + 4), ld32(esp + 8));
  /*5f842b*/ esp += 12;
  /*5f8430*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f8432*/ { u32 v = edi; ecx = v; }
  /*5f8434*/ { u32 v = (u32)0U; esp -= 4; st32(esp, v); }
  /*5f8436*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8437*/ { u32 v = (u32)ld32((u32)(eax)); eax = v; }
  /*5f8439*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32, u32, u32))fp)(ecx, ld32(esp + 0), ld32(esp + 4)); }
  /*5f8439*/ esp += 8;
  /*5f843b*/ { u32 v = eax; esi = v; }
  /*5f843d*/ { u32 v = (u32)7049304U; st32((u32)(ebp + (u32)(-168)), v); }
  /*5f8447*/ eax = (u32)(ebp + (u32)(-248));
  /*5f844d*/ { u32 v = eax; st32((u32)(ebp + (u32)(-164)), v); }
  /*5f8453*/ ecx = (u32)(edi + (u32)2762);
  /*5f8459*/ eax = (u32)(ebp + (u32)(-284));
  /*5f845f*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-156)), v); }
  /*5f8465*/ { u32 v = eax; st32((u32)(ebp + (u32)(-160)), v); }
  /*5f846b*/ ecx = (u32)(ebp + (u32)(-168));
  /*5f8471*/ { u32 v = (u32)7U; eax = v; }
  /*5f8476*/ { u32 v = (eax & 0xffff); st16((u32)(ebp + (u32)(-152)), v); }
  /*5f847d*/ { u32 v = (u32)ld32((u32)(esi)); eax = v; }
  /*5f847f*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f8480*/ { u32 v = esi; ecx = v; }
  /*5f8482*/ { u32 fp = ld32((u32)(eax + (u32)20)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f8482*/ esp += 4;
  /*5f8485*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-240))); eax = v; }
  /*5f848b*/ ecx = (u32)(edi + (u32)52);
  /*5f848e*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f8494*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-244))); eax = v; }
  /*5f849a*/ { u32 v = eax; st32((u32)(ebp + (u32)(-148)), v); }
  /*5f84a0*/ eax = (u32)(ebp + (u32)(-132));
  /*5f84a6*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f84a7*/ eax = (u32)(ebp + (u32)(-148));
  /*5f84ad*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f84ae*/ eax = ext_5f5520_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f84ae*/ esp += 8;
  /*5f84b3*/ { u32 v = (u32)ld32((u32)(edi)); eax = v; }
  /*5f84b5*/ { u32 v = edi; ecx = v; }
  /*5f84b7*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f84b8*/ { u32 fp = ld32((u32)(eax + (u32)4)); eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f84b8*/ esp += 4;
  /*5f84bb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f84be*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f84c1*/ goto L5f57f3;
  L5f84c6:;
  /*5f84c6*/ ecx = (u32)(edi + (u32)52);
  /*5f84c9*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f84ce*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-132))) :: "st", "memory");
  /*5f84d4*/ { v4sf_t v = {U2F(ld32((u32)(ebp + (u32)(-132)))), 0, 0, 0}; eax = (u32)__builtin_ia32_cvttss2si(v); }
  /*5f84dc*/ ecx = (u32)(edi + (u32)52);
  /*5f84df*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f84e5*/ eax = (u32)(ebp + (u32)(-132));
  /*5f84eb*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f84ec*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f84ec*/ esp += 4;
  /*5f84f1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f84f4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f84f7*/ goto L5f57f3;
  L5f84fc:;
  /*5f84fc*/ ecx = (u32)(edi + (u32)52);
  /*5f84ff*/ eax = ext_5f5020_thiscall1(ecx);
  /*5f8504*/ { X[1][0] = ld32((u32)((u32)6785112)); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f850c*/ __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ebp + (u32)(-140))) :: "st", "memory");
  /*5f8512*/ { X[0][0] = ld32((u32)(ebp + (u32)(-140))); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f851a*/ { float a = U2F(X[1][0]); float b = U2F(X[0][0]); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f851d*/ if (cf || zf) goto L5f854c;
  /*5f851f*/ { float a = U2F(X[0][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f8526*/ if (!cf && !zf) goto L5f8556;
  /*5f8528*/ eax = (u32)(ebp + (u32)(-140));
  /*5f852e*/ { u32 v = (u32)0U; st32((u32)(ebp + (u32)(-140)), v); }
  /*5f8538*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8539*/ ecx = (u32)(edi + (u32)52);
  /*5f853c*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f853c*/ esp += 4;
  /*5f8541*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8544*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8547*/ goto L5f57f3;
  L5f854c:;
  /*5f854c*/ { u32 v = (u32)1065353216U; st32((u32)(ebp + (u32)(-140)), v); }
  L5f8556:;
  /*5f8556*/ eax = (u32)(ebp + (u32)(-140));
  /*5f855c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f855d*/ ecx = (u32)(edi + (u32)52);
  /*5f8560*/ eax = ext_5f52f0_thiscall2(ecx, ld32(esp + 0));
  /*5f8560*/ esp += 4;
  /*5f8565*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8568*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f856b*/ goto L5f57f3;
  L5f8570:;
  /*5f8570*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f8573*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f8579*/ { u32 v = (u32)ld16((u32)(esi + (u32)2)); eax = v; }
  /*5f857d*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8580*/ if (!sf) goto L5f8591;
  /*5f8582*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8583*/ { u32 v = edi; ecx = v; }
  /*5f8585*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f8585*/ esp += 4;
  /*5f858a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); edx = v; }
  /*5f858d*/ { u32 v = (u32)ld32((u32)(eax)); esi = v; }
  /*5f858f*/ goto L5f859c;
  L5f8591:;
  /*5f8591*/ { u32 v = eax; ecx = v; }
  /*5f8593*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8599*/ { u32 v = (u32)ld32((u32)(ecx + eax)); esi = v; }
  L5f859c:;
  /*5f859c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-132))); eax = v; }
  /*5f85a2*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967160U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); edx = r; }
  /*5f85a8*/ { u32 v = esi; st32((u32)(ebp + (u32)(-140)), v); }
  /*5f85ae*/ { u32 v = esi; st32((u32)(ebp + (u32)(-108)), v); }
  /*5f85b1*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f85b4*/ if (!sf) goto L5f863c;
  /*5f85ba*/ { u32 a = (u32)edx; u32 b = (u32)(u32)3U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f85bd*/ if (!cf && !zf) goto L5f6202;
  /*5f85c3*/ switch (edx) {
    case 0: goto L5f85ca;
    case 1: goto L5f85d7;
    case 2: goto L5f85ec;
    case 3: goto L5f8614;
    default: __builtin_trap(); }
  L5f85ca:;
  /*5f85ca*/ ecx = (u32)(ebp + (u32)(-140));
  /*5f85d0*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f85d1*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f85d2*/ goto L5f6090;
  L5f85d7:;
  /*5f85d7*/ ecx = (u32)(ebp + (u32)(-132));
  /*5f85dd*/ { u32 a = (u32)esi; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); esi = r; }
  /*5f85df*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f85e0*/ { u32 v = esi; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f85e6*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f85e7*/ goto L5f6090;
  L5f85ec:;
  /*5f85ec*/ ecx = (u32)(ebp + (u32)(-140));
  /*5f85f2*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f85f3*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f85f4*/ { u32 v = edi; ecx = v; }
  /*5f85f6*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f85f6*/ esp += 4;
  /*5f85fb*/ { u32 v = eax; ecx = v; }
  /*5f85fd*/ eax = ext_5f4e00_thiscall2(ecx, ld32(esp + 0));
  /*5f85fd*/ esp += 4;
  /*5f8602*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8609*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f860c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f860f*/ goto L5f57f3;
  L5f8614:;
  /*5f8614*/ { u32 a = (u32)esi; u32 b = (u32)esi; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8616*/ if (zf) goto L5f8623;
  /*5f8618*/ eax = (u32)(ebp + (u32)(-140));
  /*5f861e*/ goto L5f611a;
  L5f8623:;
  /*5f8623*/ { u32 v = edi; ecx = v; }
  /*5f8625*/ eax = ext_5f9260_thiscall1(ecx);
  /*5f862a*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8631*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8634*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8637*/ goto L5f57f3;
  L5f863c:;
  /*5f863c*/ { u32 a = (u32)edx; u32 b = (u32)(u32)3U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f863f*/ if (!cf && !zf) goto L5f6202;
  /*5f8645*/ switch (edx) {
    case 0: goto L5f864c;
    case 1: goto L5f866a;
    case 2: goto L5f8688;
    case 3: goto L5f86ac;
    default: __builtin_trap(); }
  L5f864c:;
  /*5f864c*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f864f*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f8652*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8658*/ { u32 ea = (u32)(eax + ecx); u32 a = ld32(ea); u32 b = (u32)esi; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f865b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8662*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8665*/ goto L5f57f3;
  L5f866a:;
  /*5f866a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f866d*/ { u32 v = (eax & 0xffff); ecx = v; }
  /*5f8670*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8676*/ { u32 ea = (u32)(eax + ecx); u32 a = ld32(ea); u32 b = (u32)esi; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8679*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8680*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8683*/ goto L5f57f3;
  L5f8688:;
  /*5f8688*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f868e*/ { u32 v = (eax & 0xffff); edx = v; }
  /*5f8691*/ { u32 v = (u32)ld32((u32)(ecx + edx)); eax = v; }
  /*5f8694*/ { s32 a = (s32)eax, b = (s32)esi; s64 p = (s64)a * b; u32 r = (u32)p; cf = of = (p != (s64)(s32)r); eax = r; }
  /*5f8697*/ { u32 v = eax; st32((u32)(ecx + edx), v); }
  /*5f869a*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f86a1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f86a4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f86a7*/ goto L5f57f3;
  L5f86ac:;
  /*5f86ac*/ { u32 a = (u32)esi; u32 b = (u32)esi; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f86ae*/ if (zf) goto L5f8623;
  /*5f86b4*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); ecx = v; }
  /*5f86ba*/ { u32 v = (eax & 0xffff); esi = v; }
  /*5f86bd*/ { u32 v = (u32)ld32((u32)(ecx + esi)); eax = v; }
  /*5f86c0*/ edx = (u32)((s32)eax >> 31);
  /*5f86c1*/ { u32 d = (u32)ld32((u32)(ebp + (u32)(-108))); __asm__ volatile("idivl %4" : "=a"(eax), "=d"(edx) : "0"(eax), "1"(edx), "r"(d) : "cc"); }
  /*5f86c4*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f86c7*/ { u32 v = eax; st32((u32)(ecx + esi), v); }
  /*5f86ca*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f86d1*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f86d4*/ goto L5f57f3;
  L5f86d9:;
  /*5f86d9*/ { u32 v = (u32)ld16((u32)(esi)); eax = v; }
  /*5f86dc*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f86e2*/ { u32 v = (u32)ld16((u32)(esi + (u32)2)); eax = v; }
  /*5f86e6*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f86e9*/ if (!sf) goto L5f86fc;
  /*5f86eb*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f86ec*/ { u32 v = edi; ecx = v; }
  /*5f86ee*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f86ee*/ esp += 4;
  /*5f86f3*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-128))); edx = v; }
  /*5f86f6*/ { X[1][0] = ld32((u32)(eax)); X[1][1] = X[1][2] = X[1][3] = 0; }
  /*5f86fa*/ goto L5f8709;
  L5f86fc:;
  /*5f86fc*/ { u32 v = eax; ecx = v; }
  /*5f86fe*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8704*/ { X[1][0] = ld32((u32)(ecx + eax)); X[1][1] = X[1][2] = X[1][3] = 0; }
  L5f8709:;
  /*5f8709*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-132))); ecx = v; }
  /*5f870f*/ { u32 a = (u32)edx; u32 b = (u32)(u32)4294967156U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); edx = r; }
  /*5f8715*/ st32((u32)(ebp + (u32)(-140)), X[1][0]);
  /*5f871d*/ { u16 a = (u16)(ecx & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8720*/ if (!sf) goto L5f87d6;
  /*5f8726*/ { u32 a = (u32)edx; u32 b = (u32)(u32)3U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8729*/ if (!cf && !zf) goto L5f6202;
  /*5f872f*/ switch (edx) {
    case 0: goto L5f8736;
    case 1: goto L5f875e;
    case 2: goto L5f8775;
    case 3: goto L5f879d;
    default: __builtin_trap(); }
  L5f8736:;
  /*5f8736*/ eax = (u32)(ebp + (u32)(-140));
  L5f873c:;
  /*5f873c*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f873d*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f873e*/ { u32 v = edi; ecx = v; }
  /*5f8740*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f8740*/ esp += 4;
  /*5f8745*/ { u32 v = eax; ecx = v; }
  /*5f8747*/ eax = ext_5f3db0_thiscall2(ecx, ld32(esp + 0));
  /*5f8747*/ esp += 4;
  /*5f874c*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8753*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8756*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8759*/ goto L5f57f3;
  L5f875e:;
  /*5f875e*/ { u32 ea = (u32)((u32)6795072); for (int k = 0; k < 4; k++) X[1][k] ^= ld32(ea + 4 * k); }
  /*5f8765*/ eax = (u32)(ebp + (u32)(-132));
  /*5f876b*/ st32((u32)(ebp + (u32)(-132)), X[1][0]);
  /*5f8773*/ goto L5f873c;
  L5f8775:;
  /*5f8775*/ eax = (u32)(ebp + (u32)(-140));
  /*5f877b*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f877c*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f877d*/ { u32 v = edi; ecx = v; }
  /*5f877f*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f877f*/ esp += 4;
  /*5f8784*/ { u32 v = eax; ecx = v; }
  /*5f8786*/ eax = ext_5f4e60_thiscall2(ecx, ld32(esp + 0));
  /*5f8786*/ esp += 4;
  /*5f878b*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8792*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8795*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8798*/ goto L5f57f3;
  L5f879d:;
  /*5f879d*/ { float a = U2F(X[1][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f87a4*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f87a5*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f87a8*/ if (!pf) goto L5f8623;
  /*5f87ae*/ eax = (u32)(ebp + (u32)(-140));
  /*5f87b4*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f87b5*/ { u32 v = ecx; esp -= 4; st32(esp, v); }
  /*5f87b6*/ { u32 v = edi; ecx = v; }
  /*5f87b8*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f87b8*/ esp += 4;
  /*5f87bd*/ { u32 v = eax; ecx = v; }
  /*5f87bf*/ eax = ext_5f4110_thiscall2(ecx, ld32(esp + 0));
  /*5f87bf*/ esp += 4;
  /*5f87c4*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f87cb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f87ce*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f87d1*/ goto L5f57f3;
  L5f87d6:;
  /*5f87d6*/ { u32 a = (u32)edx; u32 b = (u32)(u32)3U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f87d9*/ if (!cf && !zf) goto L5f6202;
  /*5f87df*/ switch (edx) {
    case 0: goto L5f87e6;
    case 1: goto L5f880f;
    case 2: goto L5f8838;
    case 3: goto L5f8861;
    default: __builtin_trap(); }
  L5f87e6:;
  /*5f87e6*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f87ec*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f87ef*/ { u32 v = (ecx & 0xffff); ecx = v; }
  /*5f87f2*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f87f7*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) + b); }
  /*5f87fb*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f8800*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8807*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f880a*/ goto L5f57f3;
  L5f880f:;
  /*5f880f*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8815*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8818*/ { u32 v = (ecx & 0xffff); ecx = v; }
  /*5f881b*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f8820*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) - b); }
  /*5f8824*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f8829*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8830*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8833*/ goto L5f57f3;
  L5f8838:;
  /*5f8838*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f883e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8841*/ { u32 v = (ecx & 0xffff); ecx = v; }
  /*5f8844*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f8849*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) * b); }
  /*5f884d*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f8852*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8859*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f885c*/ goto L5f57f3;
  L5f8861:;
  /*5f8861*/ { float a = U2F(X[1][0]); float b = U2F(ld32((u32)((u32)6784464))); of = sf = 0; if (a != a || b != b) { zf = pf = cf = 1; } else if (a > b) { zf = pf = cf = 0; } else if (a < b) { zf = pf = 0; cf = 1; } else { zf = 1; pf = cf = 0; } }
  /*5f8868*/ eax = (eax & 0xffff00ffu) | ((((sf << 7) | (zf << 6) | (pf << 2) | 2 | cf)) << 8);
  /*5f8869*/ { u8 a = (u8)((eax >> 8) & 0xff); u8 b = (u8)(u32)68U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f886c*/ if (!pf) goto L5f8623;
  /*5f8872*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f8878*/ { u32 v = (ecx & 0xffff); ecx = v; }
  /*5f887b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f887e*/ { X[0][0] = ld32((u32)(eax + ecx)); X[0][1] = X[0][2] = X[0][3] = 0; }
  /*5f8883*/ { float b = U2F(X[1][0]); X[0][0] = F2U(U2F(X[0][0]) / b); }
  /*5f8887*/ st32((u32)(eax + ecx), X[0][0]);
  /*5f888c*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8893*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8896*/ goto L5f57f3;
  L5f889b:;
  /*5f889b*/ { u32 v = (u32)ld32((u32)(esi)); ecx = v; }
  /*5f889d*/ { u32 a = (u32)ecx; u32 b = (u32)ecx; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f889f*/ if (!sf) goto L5f88f1;
  /*5f88a1*/ { u32 v = ecx; eax = v; }
  /*5f88a3*/ { u32 a = (u32)eax; u32 r = alu_neg<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f88a5*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f88ab*/ { u32 v = (u32)ld16((u32)(edi + (u32)170)); eax = v; }
  /*5f88b2*/ { u32 a = (u32)eax; u32 b = (u32)ecx; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f88b4*/ ecx = (u32)(edi + (u32)52);
  /*5f88b7*/ { u32 v = eax; st32((u32)(ebp + (u32)(-148)), v); }
  /*5f88bd*/ eax = (u32)(ebp + (u32)(-132));
  /*5f88c3*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f88c4*/ eax = (u32)(ebp + (u32)(-148));
  /*5f88ca*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f88cb*/ eax = ext_5f5520_thiscall3(ecx, ld32(esp + 0), ld32(esp + 4));
  /*5f88cb*/ esp += 8;
  /*5f88d0*/ ecx = (u32)(edi + (u32)64);
  /*5f88d3*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f88d8*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f88df*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f88e2*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f88e5*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)170), v); }
  /*5f88ec*/ goto L5f57f3;
  L5f88f1:;
  /*5f88f1*/ { u32 v = (u32)ld16((u32)(edi + (u32)170)); eax = v; }
  /*5f88f8*/ ecx = (u32)(edi + (u32)64);
  /*5f88fb*/ { u32 v = eax; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f8901*/ eax = (u32)(ebp + (u32)(-132));
  /*5f8907*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8908*/ eax = ext_5f5250_thiscall2(ecx, ld32(esp + 0));
  /*5f8908*/ esp += 4;
  /*5f890d*/ { u32 v = (u32)ld16((u32)(edi + (u32)60)); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f8911*/ { u32 ea = (u32)(edi + (u32)166); u32 a = ld32(ea); u32 b = (u32)(u32)4U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); st32(ea, r); }
  /*5f8918*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f891b*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f891e*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)170), v); }
  /*5f8925*/ goto L5f57f3;
  L5f892a:;
  /*5f892a*/ { u32 v = edi; ecx = v; }
  /*5f892c*/ eax = ext_5f4390_thiscall1(ecx);
  /*5f8931*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8934*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8937*/ goto L5f57f3;
  L5f893c:;
  /*5f893c*/ eax = (u32)(ebp + (u32)(-124));
  /*5f893f*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8940*/ ecx = (u32)(edi + (u32)52);
  /*5f8943*/ eax = ext_5f4f00_thiscall2(ecx, ld32(esp + 0));
  /*5f8943*/ esp += 4;
  /*5f8948*/ { u32 ea = (u32)(ebp + (u32)(-124)); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f894c*/ if (zf || sf != of) goto L5f8961;
  /*5f894e*/ { u32 v = (u32)ld16((u32)(ebp + (u32)(-124))); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f8952*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8955*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8958*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)8), v); }
  /*5f895c*/ goto L5f57f3;
  L5f8961:;
  /*5f8961*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8964*/ { u32 v = (u32)1000000U; ecx = v; }
  /*5f8969*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f896c*/ goto L5f57f3;
  L5f8971:;
  /*5f8971*/ { u32 v = (u32)ld32((u32)(esi)); ecx = v; }
  /*5f8973*/ eax = (u32)(esi + (u32)4);
  /*5f8976*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8979*/ { u32 v = ecx; st32((u32)(ebp + (u32)(-112)), v); }
  /*5f897c*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f8982*/ goto L5f57f3;
  L5f8987:;
  /*5f8987*/ ecx = (u32)(edi + (u32)52);
  /*5f898a*/ eax = ext_5f4ff0_thiscall1(ecx);
  /*5f898f*/ { u32 v = (eax & 0xffff); eax = v; }
  /*5f8992*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8995*/ if (!sf) goto L5f89b4;
  /*5f8997*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8998*/ { u32 v = edi; ecx = v; }
  /*5f899a*/ eax = ext_5f4a00_thiscall2(ecx, ld32(esp + 0));
  /*5f899a*/ esp += 4;
  /*5f899f*/ ecx = (u32)(edi + (u32)52);
  /*5f89a2*/ { u32 v = (u32)ld32((u32)(eax)); esp -= 4; st32(esp, v); }
  /*5f89a4*/ eax = ext_5f5390_thiscall2(ecx, ld32(esp + 0));
  /*5f89a4*/ esp += 4;
  /*5f89a9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f89ac*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f89af*/ goto L5f57f3;
  L5f89b4:;
  /*5f89b4*/ { u32 v = eax; ecx = v; }
  /*5f89b6*/ { u32 v = (u32)ld32((u32)(edi + (u32)158)); eax = v; }
  /*5f89bc*/ { u32 v = (u32)ld32((u32)(eax + ecx)); esp -= 4; st32(esp, v); }
  /*5f89bf*/ ecx = (u32)(edi + (u32)52);
  /*5f89c2*/ eax = ext_5f5390_thiscall2(ecx, ld32(esp + 0));
  /*5f89c2*/ esp += 4;
  /*5f89c7*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f89ca*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f89cd*/ goto L5f57f3;
  L5f89d2:;
  /*5f89d2*/ { u32 v = edi; ecx = v; }
  /*5f89d4*/ eax = ext_5f90a0_thiscall1(ecx);
  /*5f89d9*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f89dc*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f89df*/ goto L5f57f3;
  L5f89e4:;
  /*5f89e4*/ { u32 v = edi; ecx = v; }
  /*5f89e6*/ eax = ext_5f9010_thiscall1(ecx);
  /*5f89eb*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f89ee*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f89f1*/ goto L5f57f3;
  L5f89f6:;
  /*5f89f6*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = v; }
  /*5f89fd*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8a00*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8a03*/ { u32 a = (u32)eax; u32 b = (u32)(u32)34816U; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8a08*/ if (!zf) goto L5f57f3;
  /*5f8a0e*/ { u32 a = (u32)eax; u32 b = (u32)(u32)4096U; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8a13*/ if (zf) goto L5f8a37;
  /*5f8a15*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f8a1a*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8a1c*/ if (zf) goto L5f8a2b;
  /*5f8a1e*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f8a20*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8a23*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8a26*/ goto L5f57f3;
  L5f8a2b:;
  /*5f8a2b*/ __builtin_trap();
  L5f8a37:;
  /*5f8a37*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8a3a*/ { u32 v = (u32)36864U; eax = v; }
  /*5f8a3f*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); st16(ea, r); }
  /*5f8a46*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8a49*/ goto L5f57f3;
  L5f8a4e:;
  /*5f8a4e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8a51*/ { u32 v = (u32)4096U; eax = v; }
  /*5f8a56*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8a59*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8a60*/ if (zf) goto L5f57f3;
  /*5f8a66*/ { u32 v = (u32)28671U; eax = v; }
  /*5f8a6b*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); st16(ea, r); }
  /*5f8a72*/ goto L5f7e1a;
  L5f8a77:;
  /*5f8a77*/ eax = ext_5fa630_stdcall0();
  /*5f8a7c*/ { u32 v = eax; esi = v; }
  /*5f8a7e*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f8a84*/ { u32 v = eax; ecx = v; }
  /*5f8a86*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f8a88*/ { u32 v = (u32)ld32((u32)(esi)); edi = v; }
  /*5f8a8a*/ { u32 v = (u32)ld32((u32)(edx + (u32)40)); edx = v; }
  /*5f8a8d*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f8a8f*/ { u32 a = (u32)eax; u32 r = alu_dec<u32>(a, cf, zf, sf, of, pf); eax = r; }
  /*5f8a90*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8a91*/ { u32 v = (u32)7049312U; esp -= 4; st32(esp, v); }
  /*5f8a96*/ eax = (u32)(ebp + (u32)(-104));
  /*5f8a99*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8a9a*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8a9b*/ { u32 fp = ld32((u32)(edi + (u32)20)); eax = ((u32( *)(u32, u32, u32, u32))fp)(ld32(esp + 0), ld32(esp + 4), ld32(esp + 8), ld32(esp + 12)); }
  /*5f8a9e*/ { u32 v = (u32)ld32((u32)((u32)7340976)); eax = v; }
  /*5f8aa3*/ { u32 a = (u32)esp; u32 b = (u32)(u32)16U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  /*5f8aa6*/ { u32 a = (u32)eax; u32 b = (u32)eax; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8aa8*/ if (zf) goto L5f8abd;
  /*5f8aaa*/ { u32 fp = eax; eax = ((u32(THISCALL *)(u32))fp)(ecx); }
  /*5f8aac*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f8ab2*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-112))); ecx = v; }
  /*5f8ab5*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-116))); edx = v; }
  /*5f8ab8*/ goto L5f57f3;
  L5f8abd:;
  /*5f8abd*/ __builtin_trap();
  L5f8acf:;
  /*5f8acf*/ { u32 v = (u32)ld32((u32)(edi + (u32)166)); eax = v; }
  /*5f8ad5*/ { u32 v = edi; ecx = v; }
  /*5f8ad7*/ { u32 v = (u32)ld32((u32)(eax)); esp -= 4; st32(esp, v); }
  /*5f8ad9*/ eax = ext_5f5620_thiscall2(ecx, ld32(esp + 0));
  /*5f8ad9*/ esp += 4;
  /*5f8ade*/ { u32 v = eax; st32((u32)(edi + (u32)166), v); }
  /*5f8ae4*/ goto L5f8bb6;
  L5f8ae9:;
  /*5f8ae9*/ { u32 v = (u32)65522U; ecx = v; }
  /*5f8aee*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f8af1*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)2U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f8af5*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f8afc*/ goto L5f8bb6;
  L5f8b01:;
  /*5f8b01*/ { u32 v = (u32)ld8((u32)(edi + (u32)172)); eax = (eax & 0xffffff00u) | ((v) & 0xff); }
  /*5f8b07*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffffff00u) | ((r) & 0xff); }
  /*5f8b09*/ { u8 a = (u8)(eax & 0xff); u8 b = (u8)(u32)3U; u8 r = alu_sub<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8b0b*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = (eax & 0xffff0000u) | ((v) & 0xffff); }
  /*5f8b12*/ if (!zf) goto L5f8b2c;
  /*5f8b14*/ { u32 v = (u32)65525U; ecx = v; }
  /*5f8b19*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f8b1c*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)5U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f8b20*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f8b27*/ goto L5f8bb6;
  L5f8b2c:;
  /*5f8b2c*/ { u32 v = (u32)65524U; ecx = v; }
  /*5f8b31*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(ecx & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f8b34*/ { u16 a = (u16)(eax & 0xffff); u16 b = (u16)(u32)4U; u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); eax = (eax & 0xffff0000u) | ((r) & 0xffff); }
  /*5f8b38*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f8b3f*/ goto L5f8bb6;
  L5f8b41:;
  /*5f8b41*/ eax = ext_5fa630_stdcall0();
  /*5f8b46*/ { u32 v = eax; edi = v; }
  /*5f8b48*/ { u32 v = edi; st32((u32)(ebp + (u32)(-132)), v); }
  /*5f8b4e*/ eax = ext_5fa630_stdcall0();
  /*5f8b53*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); ecx = v; }
  /*5f8b59*/ { u32 v = (u32)ld32((u32)(eax)); edx = v; }
  /*5f8b5b*/ { u32 v = (u32)ld32((u32)(ecx + (u32)36)); esp -= 4; st32(esp, v); }
  /*5f8b5e*/ { u32 v = eax; ecx = v; }
  /*5f8b60*/ { u32 v = (u32)ld32((u32)(edx + (u32)28)); edx = v; }
  /*5f8b63*/ { u32 fp = edx; eax = ((u32(THISCALL *)(u32, u32))fp)(ecx, ld32(esp + 0)); }
  /*5f8b63*/ esp += 4;
  /*5f8b65*/ { u32 v = (u32)ld32((u32)(edi)); edi = v; }
  /*5f8b67*/ { u32 v = eax; esi = v; }
  /*5f8b69*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); eax = v; }
  /*5f8b6f*/ { u32 v = (u32)ld32((u32)(eax + (u32)150)); ecx = v; }
  /*5f8b75*/ eax = ext_600800_thiscall1(ecx);
  /*5f8b7a*/ { u32 v = eax; esp -= 4; st32(esp, v); }
  /*5f8b7b*/ { u32 v = esi; esp -= 4; st32(esp, v); }
  /*5f8b7c*/ { u32 v = (u32)7049080U; esp -= 4; st32(esp, v); }
  /*5f8b81*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-132))); esp -= 4; st32(esp, v); }
  /*5f8b87*/ { u32 fp = ld32((u32)(edi + (u32)12)); eax = ((u32( *)(u32, u32, u32, u32))fp)(ld32(esp + 0), ld32(esp + 4), ld32(esp + 8), ld32(esp + 12)); }
  /*5f8b8a*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-136))); edi = v; }
  /*5f8b90*/ { u32 a = (u32)esp; u32 b = (u32)(u32)16U; u32 r = alu_add<u32>(a, b, cf, zf, sf, of, pf); esp = r; }
  L5f8b93:;
  /*5f8b93*/ { u32 v = (u32)34816U; eax = v; }
  /*5f8b98*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_and<u16>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8b9f*/ { u32 v = (u32)16384U; eax = v; }
  /*5f8ba4*/ if (zf) goto L5f8baf;
  /*5f8ba6*/ { u32 ea = (u32)(edi + (u32)180); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); st16(ea, r); }
  /*5f8bad*/ goto L5f8bb6;
  L5f8baf:;
  /*5f8baf*/ { u32 ea = (u32)(edi + (u32)172); u16 a = ld16(ea); u16 b = (u16)(eax & 0xffff); u16 r = alu_or<u16>(a, b, cf, zf, sf, of, pf); st16(ea, r); }
  L5f8bb6:;
  /*5f8bb6*/ { u32 ea = (u32)(edi + (u32)172); u8 a = ld8(ea); u8 b = (u8)(u32)15U; u8 r = alu_and<u8>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8bbd*/ if (zf) goto L5f8be6;
  /*5f8bbf*/ { u32 v = (u32)ld16((u32)(edi + (u32)172)); eax = v; }
  /*5f8bc6*/ { u32 a = (u32)eax; u32 b = (u32)(u32)34816U; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8bcb*/ if (!zf) goto L5f8be6;
  /*5f8bcd*/ { u32 a = (u32)eax; u32 b = (u32)(u32)57343U; u32 r = alu_and<u32>(a, b, cf, zf, sf, of, pf); eax = r; }
  /*5f8bd2*/ { u32 ea = (u32)(edi + (u32)84); u32 a = ld32(ea); u32 b = (u32)(u32)0U; u32 r = alu_sub<u32>(a, b, cf, zf, sf, of, pf); (void)r; }
  /*5f8bd6*/ { u32 v = (eax & 0xffff); st16((u32)(edi + (u32)172), v); }
  /*5f8bdd*/ if (zf) goto L5f8be6;
  /*5f8bdf*/ { u32 v = edi; ecx = v; }
  /*5f8be1*/ eax = ext_5f4ac0_thiscall1(ecx);
  L5f8be6:;
  /*5f8be6*/ { u32 v = (u32)ld32((u32)(ebp + (u32)(-4))); ecx = v; }
  /*5f8be9*/ { u32 v = ld32(esp); esp += 4; edi = v; }
  /*5f8bea*/ { u32 a = (u32)ecx; u32 b = (u32)ebp; u32 r = alu_xor<u32>(a, b, cf, zf, sf, of, pf); ecx = r; }
  /*5f8bec*/ { u32 v = ld32(esp); esp += 4; esi = v; }
  /*5f8bed*/ eax = ext_633654_thiscall1(ecx);
  /*5f8bf2*/ { u32 v = ebp; esp = v; }
  /*5f8bf4*/ { u32 v = ld32(esp); esp += 4; ebp = v; }
  /*5f8bf5*/ return eax;
}
PCREG(5f56f0, lifted_5f56f0);

