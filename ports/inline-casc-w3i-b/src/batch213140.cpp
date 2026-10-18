#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, u32, u32, u32);

extern "C" void THISCALL ext_462510(void *n, u32 one);
extern "C" void THISCALL ext_465330(void *n, u32 fbits);
extern "C" void THISCALL ext_463da0(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_4de7a0(void *m);

static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }
static inline float rdf(const u8 *p) { return *(const float *)p; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline double fmodx(double a, double b) {
  double r;
  __asm__ volatile("fldl %1\n\tfldl %2\n\tcall *0x676358\n\tfstpl %0" : "=m"(r) : "m"(a), "m"(b) : "eax", "ecx", "edx", "memory", "cc");
  return r;
}

// 0x4650c0: thiscall() -> bool in al. Per-frame update of an object's timed nodes (this[0x18] is an iterator object: slot 0x4c start, slot 0x64 next, slot 0x44 erase; node N = result + 4):
// a node with N[0x44] >= 0 advances its clock (N[4] = N[8] = ((engine time - N[0x1c]*1024) * (int)(count * N[0x28] * 1024) >> 10) / 1024, then 0x465330(N, N[4])), sets the
// 'finished' flag when N[4] >= N[0x18] and fires this slots 0x270 / 0x268 when floor(N[4] / N[0xc]) equals the running counter this[0x122]; N[0x44] == -1 means erase.
// Afterwards this slot 0x26c, then every record of the array this[0x1c] (count this[0x20], 0x18 bytes each) whose flags have bits 0/1 gets its clock folded with fmod, and the
// final orientation is set through 0x463da0 / 0x4de7a0 and the owner's slot 0x5c.
extern "C" u32 THISCALL fn_4650c0(u8 *self) {
  u32 it[6];
  u8 flag = 0;
  u8 *I = (u8 *)rd32(self + 0x18);
  if (I != 0) {
    (*(V1 *)(vt(I) + 0x4c))(I, (u32)it);
    I = (u8 *)rd32(self + 0x18);
    u8 *P = (u8 *)(*(V1 *)(vt(I) + 0x64))(I, (u32)it);
    if (P != 0) {
      float c = G(float, 0x678620);
      do {
        u8 *N = P + 4;
        int h = (int)rd32(N + 0x44);
        if (h >= 0) {
          *(u32 *)N = rd32(N + 8);
          u8 *V = (u8 *)rd32(N + 0x70);
          int engt = (int)rd32(G(u8 *, 0x70039c) + 0x40);
          float t0 = (float)(int)rd32(V + 0x6c);
          t0 = t0 * rdf(N + 0x28);
          t0 = t0 * c;
          int a = (int)t0;
          float t1 = rdf(N + 0x1c);
          t1 = t1 * c;
          int b = (int)t1;
          long long prod = (long long)(engt - b) * (long long)a;
          int sh = (int)(prod >> 10);
          float f = (float)sh * G(float, 0x6785e4);
          *(float *)(N + 4) = f;
          *(float *)(N + 8) = f;
          u32 fb;
          __builtin_memcpy(&fb, &f, 4);
          ext_465330(N, fb);
          float n4 = rdf(N + 4);
          if (n4 >= rdf(N + 0x18)) flag = 1;
          int den = (int)rd32(N + 0xc);
          if (den != 0) {
            int q = (int)n4 / den;
            int cnt = (int)rd32(self + 0x122);
            if (q == cnt) {
              *(u32 *)(self + 0x122) = (u32)(cnt + 1);
              u8 *edi = N + 0x4c;
              u8 *V2p = (u8 *)rd32(N + 0x70);
              (*(V2 *)(vt(self) + 0x270))(self, (u32)edi, rd32(V2p + 0x7c));
              if (flag == 0) {
                V2p = (u8 *)rd32(N + 0x70);
                (*(V2 *)(vt(self) + 0x268))(self, (u32)edi, rd32(V2p + 0x7c));
              }
            }
          }
        } else if (h == -1) {
          ext_462510(N, 1);
          I = (u8 *)rd32(self + 0x18);
          (*(V1 *)(vt(I) + 0x44))(I, (u32)it);
        }
        I = (u8 *)rd32(self + 0x18);
        P = (u8 *)(*(V1 *)(vt(I) + 0x64))(I, (u32)it);
        c = G(float, 0x678620);
      } while (P != 0);
    }
  }
  (*(V0 *)(vt(self) + 0x26c))(self);
  if (flag != 0) {
    u8 *A = (u8 *)rd32(self + 0x1c);
    if (rd32(self + 0x20) != 0) {
      u32 i = 0;
      do {
        if (A[4] & 3) {
          u8 *q = (u8 *)rd32(A + 0x14);
          float x1 = rdf(q + 0x18);
          float x0 = rdf(q + 4);
          if (!(x0 < x1)) {
            int ecx = (int)rd32(q + 0xc);
            if (x1 == (float)ecx) {
              *(float *)A = x1;
            } else {
              double r = fmodx((double)x1, (double)ecx);
              *(float *)A = (float)r;
            }
            (*(V2 *)(vt(self) + 0x340))(self, i, 1);
          }
        }
        i++;
        A += 0x18;
      } while (i != rd32(self + 0x20));
    }
  }
  u8 *edx = (u8 *)rd32(self + 0x1c);
  u8 *ecx = (u8 *)rd32(edx + 0x14);
  if (rd32(self + 0x18) != 0 && ecx != 0 && (edx[4] & 3) != 0 && (flag != 0 || (rd32(ecx + 0x14) & 0x200) == 0)) {
    ext_463da0(self, rd32(ecx), rd32(ecx + 8));
    u8 *o = (u8 *)rd32(self + 0x6c);
    (*(V3 *)(vt(o) + 0x5c))(o, (u32)self, (u32)(self + 0x24), (u32)(self + 0x48));
    return 1;
  }
  u8 *edi = self + 0x48;
  u8 *esi = self + 0x24;
  *(u32 *)edi = 0;
  *(u32 *)(edi + 4) = 0;
  *(u32 *)(edi + 8) = 0;
  ext_4de7a0(esi);
  u8 *o = (u8 *)rd32(self + 0x6c);
  return (*(V3 *)(vt(o) + 0x5c))(o, (u32)self, (u32)esi, (u32)edi);
}
PCREG(4650c0, fn_4650c0);
