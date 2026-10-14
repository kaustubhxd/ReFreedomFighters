// batch935.cpp - 0x507c60 ZActorIf::ReplaceMove(OpaqueCallParameters_t&) [thiscall (ECX = this), one stack arg (a params reference p),
// ret 4, void]. Body read in full (2026-10-12).
// Three reads through the accessor 0x5003d0 (stood in) with indices 0, 1, 2 of p+4. Each read entry E has a type byte at E+4: 3 -> the dword at E;
// 4 -> the value of E's object slot +0x34; any other type -> the engine trace (logger 0x700390 slot +0x20 (0x69c8e0, 0x111) -> sink; sink
// slot +0x2c cdecl (sink, 0x69c6b0, 0x69c9b0)) and the hook 0x7003b0 (thiscall with ECX = the sink's vtable; a null hook is an int3 trap),
// giving 0. Then if the third entry's dword is <= 0: trace (0x69cff0, 0xe3) and sink slot +0x30 cdecl (sink, 0x69d020, esi, ebx); return.
// Else the name at esi is compared (case-insensitive, _stricmp at 0x676414, stood in) with "Walk", "Run", "User0", "User1" giving V = 1..4
// (V = 0 when none matches). R1 = X slot +0x598 (mgr+0x44 + count), R2 = X slot +0x5c4 (ebx), R3 = X slot +0x5c8 (R2), where X = this+0x18,
// then X slot +0x5b4 (V, R2, R1, R3).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);   // accessor (stood in)

typedef void (*printf3_t)(void *, const char *, const char *);       // cdecl sink slot +0x2c
typedef void (*trace4_t)(void *, const char *, u32, u32);            // cdecl sink slot +0x30
typedef s32 (*stricmp_t)(const char *, const char *);                // CRT import at 0x676414, cdecl
typedef void (*hook_t)(void);                                        // thiscall hook; ECX = the sink vtable (passed as the argument)

// Trace the unexpected type and call the hook; returns the sink so the caller can keep its ECX value (the sink's vtable).
static u8 *TraceUnexpected(void) {
  u8 *logger = G(u8 *, 0x700390);
  u8 *sink = (u8 *)vcall<void *>(logger, 0x20, (void *)0x69c8e0u, 0x111u);
  printf3_t pf = (printf3_t)FP(*(u8 **)sink, 0x2c);
  pf(sink, (const char *)0x69c6b0u, (const char *)0x69c9b0u);
  u32 hook = G(u32, 0x7003b0);
  if (!hook) asm volatile("int3");
  // the exe calls the hook with ECX = the sink's vtable and no arguments
  ((void(THISCALL *)(void *))hook)(*(void **)sink);
  return sink;
}

// 0x507c60 (name in the map: ZActorIf::ReplaceMove(OpaqueCallParameters_t&)).
static void THISCALL ReplaceMove507c60(u8 *self, u8 *p) {
  u32 esi = 0;
  u8 *P0 = (u8 *)ext_5003d0(FP(p, 4), 0);
  u8 sel = U8(P0, 4);
  if (sel == 3) {
    esi = U32(P0, 0);
  } else if (sel == 4) {
    esi = vcall<u32>(FP(P0, 0), 0x34);
  } else {
    TraceUnexpected();
    esi = 0;
  }
  u32 ebx = 0;
  u8 *P1 = (u8 *)ext_5003d0(FP(p, 4), 1);
  u8 sel1 = U8(P1, 4);
  if (sel1 == 3) {
    ebx = U32(P1, 0);
  } else if (sel1 == 4) {
    ebx = vcall<u32>(FP(P1, 0), 0x34);
  } else {
    TraceUnexpected();
    ebx = 0;
  }
  u8 *P2 = (u8 *)ext_5003d0(FP(p, 4), 2);
  u32 cnt = U32(P2, 0);
  if ((s32)cnt <= 0) {
    u8 *logger = G(u8 *, 0x700390);
    u8 *sink = (u8 *)vcall<void *>(logger, 0x20, (void *)0x69cff0u, 0xe3u);
    trace4_t t4 = (trace4_t)FP(*(u8 **)sink, 0x30);
    t4(sink, (const char *)0x69d020u, esi, ebx);
    return;
  }
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u32 idx = U32(mgr, 0x44) + cnt;
  stricmp_t ci = (stricmp_t)G(u32, 0x676414);
  u32 V;
  if (ci((const char *)esi, (const char *)0x68ac54u) == 0) V = 1;
  else if (ci((const char *)esi, (const char *)0x68ac5cu) == 0) V = 2;
  else if (ci((const char *)esi, (const char *)0x69d064u) == 0) V = 3;
  else V = (ci((const char *)esi, (const char *)0x69d06cu) == 0) ? 4 : 0;
  u8 *X = (u8 *)FP(self, 0x18);
  u32 R1 = vcall<u32>(X, 0x598, idx);
  u32 R2 = vcall<u32>(X, 0x5c4, ebx);
  u32 R3 = vcall<u32>(X, 0x5c8, R2);
  vcall<void>(X, 0x5b4, V, R2, R1, R3);
}
PCREG(507c60, ReplaceMove507c60);
