// pf.h - helpers for the pathfinding tree (inline-pathfinding thread).
#pragma once
#include "ff.h"

// MSVC CRT pieces the pathfinder calls; kept as calls into the exe (platform layer), like crt:: in ff.h.
extern "C" double ext_634da6(double);   // ceil (cdecl, result in ST0)
extern "C" void ext_634670();           // _ftol2_sse: ST0 -> EAX (pops ST0); 32-bit cvttsd2si when SSE2 flag
                                        // [0x72580c] is set, else the x87 64-bit path
static inline int ftol2(double x) {
  int r;
  asm volatile("fldl %1\n\tcall ext_634670" : "=a"(r) : "m"(x) : "ecx", "edx", "memory", "st");
  return r;
}

// Debug report used by the pathfinder's asserts: g_pDebug (0x700390) vtable +0x20 (file, line) returns a reporter,
// whose vtable +0x2c is a cdecl printf-like (reporter, msg). Then the assert hook at 0x7003b0 runs, or int3 when unset.
static inline void pfReport(const char *file, int line, const char *msg) {
  void *r = vcall<void *>(G(void *, 0x700390), 0x20, file, line);
  typedef void (*fn)(void *, const char *);
  (*(fn *)(*(u8 **)r + 0x2c))(r, msg);
}
static inline void pfBreak() {
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h(); else __builtin_debugtrap();
}

// Engine callees outside this tree (bound to the exe by build.sh).
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);   // |a - b| (lifted in batch48, frameupdate)
extern "C" void *ext_41e290(u32 size);                                  // __builtin_new
extern "C" void ext_634273(void *p, u32 size);                          // __builtin_delete (sized)
