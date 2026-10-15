// batch44000.cpp - cascade t5 (Sonnet): tier H float functions.
#include "ff.h"
#include <xmmintrin.h>

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" u32 THISCALL ext_4e4050(u8 *self, s32 l0, s32 l1, s32 l2, s32 h0, s32 h1, s32 h2, u32 a);  // thiscall ret 0x1c
extern "C" void ext_5002f0(void);
extern "C" void ext_500360(void);
extern "C" void ext_5003d0(void);

// 0x4e41e0, thiscall(pmin, pmax, a) ret 0xc: with s = float [this+0x1d], o = float [this+0x21..0x29] (unaligned), K = 32768.0f:
// lo[i] = (int)trunc((pmin[i]-o[i])*s + K); hi[i] = (int)trunc((pmax[i]-o[i])*s + K) + 1; return 0x4e4050(this, lo0, lo1, lo2, hi0, hi1, hi2, a).
static u32 THISCALL fn4e41e0(u8 *self, const float *pmin, const float *pmax, u32 a) {
  float s = rdf(self + 0x1d);
  float K = bitsf(0x47000000);
  s32 l0 = _mm_cvttss_si32(_mm_set_ss((pmin[0] - rdf(self + 0x21)) * s + K));
  s32 l1 = _mm_cvttss_si32(_mm_set_ss((pmin[1] - rdf(self + 0x25)) * s + K));
  s32 l2 = _mm_cvttss_si32(_mm_set_ss((pmin[2] - rdf(self + 0x29)) * s + K));
  s32 h0 = _mm_cvttss_si32(_mm_set_ss((pmax[0] - rdf(self + 0x21)) * s + K)) + 1;
  s32 h1 = _mm_cvttss_si32(_mm_set_ss((pmax[1] - rdf(self + 0x25)) * s + K)) + 1;
  s32 h2 = _mm_cvttss_si32(_mm_set_ss((pmax[2] - rdf(self + 0x29)) * s + K)) + 1;
  return ext_4e4050(self, l0, l1, l2, h0, h1, h2, a);
}
PCREG(4e41e0, fn4e41e0);

// 0x551830, stdcall(obj, key, v) ret 0xc: t = vslot 0x18 of obj(key); if null return 0; w = t.slot 0x4c();
// 0x5002f0(0x5003d0(w,0), v[0]); 0x5002f0(0x5003d0(w,1), v[1]); 0x500360(0x5003d0(w,2), v[2]) ... (2..4 float via 500360); return t.
asm(
    ".text\n"
    ".globl thunk551830\n"
    "thunk551830:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 8(%ebp), %ecx\n"
    "  pushl %ebx\n"
    "  pushl 0xc(%ebp)\n"
    "  movl (%ecx), %eax\n"
    "  call *0x18(%eax)\n"
    "  movl %eax, %ebx\n"
    "  testl %ebx, %ebx\n"
    "  je 1f\n"
    "  movl (%ebx), %edx\n"
    "  movl %ebx, %ecx\n"
    "  pushl %esi\n"
    "  pushl %edi\n"
    "  call *0x4c(%edx)\n"
    "  movl 0x10(%ebp), %esi\n"
    "  movl %eax, %edi\n"
    "  movl %edi, %ecx\n"
    "  pushl (%esi)\n"
    "  pushl $0\n"
    "  call ext_5003d0\n"
    "  movl %eax, %ecx\n"
    "  call ext_5002f0\n"
    "  pushl 4(%esi)\n"
    "  movl %edi, %ecx\n"
    "  pushl $1\n"
    "  call ext_5003d0\n"
    "  movl %eax, %ecx\n"
    "  call ext_5002f0\n"
    "  pushl 8(%esi)\n"
    "  movl %edi, %ecx\n"
    "  pushl $2\n"
    "  call ext_5003d0\n"
    "  movl %eax, %ecx\n"
    "  call ext_500360\n"
    "  pushl 0xc(%esi)\n"
    "  movl %edi, %ecx\n"
    "  pushl $3\n"
    "  call ext_5003d0\n"
    "  movl %eax, %ecx\n"
    "  call ext_500360\n"
    "  pushl 0x10(%esi)\n"
    "  movl %edi, %ecx\n"
    "  pushl $4\n"
    "  call ext_5003d0\n"
    "  movl %eax, %ecx\n"
    "  call ext_500360\n"
    "  popl %edi\n"
    "  movl %ebx, %eax\n"
    "  popl %esi\n"
    "1:\n"
    "  popl %ebx\n"
    "  popl %ebp\n"
    "  ret $0xc\n");
extern "C" u32 STDCALL thunk551830(void *, u32, const u32 *);
PCREG(551830, thunk551830);
