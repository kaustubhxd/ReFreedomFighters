// ff.h - shared declarations for the Freedom Fighters decompilation pilot.
//
// Target: Freedom.Exe.orig (2021 Steam build, MSVC 14.x, /GL LTCG, /arch:SSE2, /GS).
// Every function in src/ is written to do exactly what the machine code at its PC address does.
// The harness (harness/pilot.py) builds these files for i386 with clang and runs each function
// next to the original in Unicorn, so the calling convention of each function must match the
// original's: LTCG turned most internal functions into __fastcall (ECX, EDX, rest on the stack,
// callee pops). Member functions are __thiscall (this in ECX).
//
// Conventions used in this tree:
//   PCREG(addr, fn)   registers fn as the decompilation of the PC function at 0x<addr>.
//   ext_<hex>         a callee outside the decompiled set; build.sh binds it to that PC address,
//                     so the original code runs (in the final port it would be decompiled too).
//   G(T, addr)        a global variable of the exe, by absolute address.
#pragma once
#include <emmintrin.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned long long u64;

#define FASTCALL __attribute__((fastcall))
#define THISCALL __attribute__((thiscall))
#define STDCALL __attribute__((stdcall))
#define VECTORCALL __attribute__((vectorcall))

#define PCREG(addr, fn) extern "C" __attribute__((used)) const auto pc_##addr = fn
#define G(T, addr) (*(T *)(addr))

// ---------------------------------------------------------------- bit helpers
static inline u32 fbits(float f) { return __builtin_bit_cast(u32, f); }
static inline float bitsf(u32 u) { return __builtin_bit_cast(float, u); }

// ---------------------------------------------------------------- CRT (UCRT) math
// The exe calls _libm_sse2_*_precise through its IAT: argument and result in XMM0, which is
// what __vectorcall does for a single double. Calling through the IAT slot keeps the CRT a
// platform-layer dependency (in a WASM port these need bit-exact reimplementations).
namespace crt {
typedef double(VECTORCALL *libm1)(double);
static inline double sin(double x) { return (*(libm1 *)0x676338)(x); }
static inline double cos(double x) { return (*(libm1 *)0x676320)(x); }
static inline double tan(double x) { return (*(libm1 *)0x676348)(x); }
static inline double atan(double x) { return (*(libm1 *)0x676318)(x); }
static inline double asin(double x) { return (*(libm1 *)0x67631c)(x); }
static inline double acos(double x) { return (*(libm1 *)0x676354)(x); }
static inline double exp(double x) { return (*(libm1 *)0x676350)(x); }
static inline double log(double x) { return (*(libm1 *)0x676314)(x); }
// sqrt is correctly rounded in IEEE 754, so sqrtsd gives the same bits as the CRT call.
static inline double sqrt(double x) { return _mm_cvtsd_f64(_mm_sqrt_sd(_mm_set_sd(x), _mm_set_sd(x))); }
}  // namespace crt

// x87 square root on the FPU stack: the result is rounded to the precision the FPU control word selects
// (24, 53 or 64 bit mantissa). `long double` arithmetic compiles to x87 instructions for i386, so ports that use it
// follow the control word exactly like the original (see tools/fpu_kink.py for why that matters).
static inline long double fsqrt_x87(long double x) {
  asm("fsqrt" : "+t"(x));
  return x;
}

// ---------------------------------------------------------------- engine globals
// 0x70039c: ZSysInterface* (the engine object). Virtual calls go through its vtable.
struct ZSysInterface;
#define g_pSysInterface G(ZSysInterface *, 0x70039c)

// Call slot `off` (byte offset) of an object's vtable with the __thiscall convention.
template <class R, class... A>
static inline R vcall(void *obj, u32 off, A... a) {
  typedef R(THISCALL * fn)(void *, A...);
  return (*(fn *)(*(u8 **)obj + off))(obj, a...);
}

// ---------------------------------------------------------------- float constants of the exe
// Kept as literals; the address each one is read from is noted where it is used.

// ---------------------------------------------------------------- collision thread additions
static inline u64 f64bits(double d) { return __builtin_bit_cast(u64, d); }
static inline double bitsf64(u64 u) { return __builtin_bit_cast(double, u); }
