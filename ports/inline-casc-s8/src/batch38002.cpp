// batch38002.cpp - cascade s8 batch 38002: 0x550db0.
#include "ff.h"

extern "C" u32 FASTCALL ext_55ed00(u32 a, u32 b);
extern "C" u32 FASTCALL ext_55fad0(u32 a, u32 b);
extern "C" u32 FASTCALL ext_560440(u32 a, u32 b);
extern "C" u32 FASTCALL ext_5579b0(u32 a, u32 b);
extern "C" u32 FASTCALL ext_51ae60(u32 a, u32 b);
extern "C" u32 FASTCALL ext_51b6d0(u32 a, u32 b);
extern "C" u32 FASTCALL ext_51f320(u32 a, u32 b);
extern "C" u32 FASTCALL ext_522dc0(u32 a, u32 b);
extern "C" u32 FASTCALL ext_520010(u32 a, u32 b);
extern "C" u32 FASTCALL ext_51a8a0(u32 a, u32 b);
typedef int (*stricmp_t)(const char *, const char *);
typedef u32 (*hook_t)();
#define imp_stricmp G(stricmp_t, 0x676414)

// 0x550db0, stdcall(name, a, b) ret 0xc: same dispatch as 0x550c50 but the handlers take (a, b) in ECX/EDX (fastcall) and their result is returned.
// The case-insensitive name is tested against 11 strings of the exe image in order (the last shares the handler of the third); an unknown name calls the
// assert hook at 0x7003b0 (int3 when null) and returns 0.
static u32 STDCALL fn550db0(const char *name, u32 a, u32 b) {
  if (!imp_stricmp((const char *)0x6a4b74, name)) return ext_55ed00(a, b);
  if (!imp_stricmp((const char *)0x6a4b80, name)) return ext_55fad0(a, b);
  if (!imp_stricmp((const char *)0x6a4b8c, name)) return ext_560440(a, b);
  if (!imp_stricmp((const char *)0x6a4b68, name)) return ext_5579b0(a, b);
  if (!imp_stricmp((const char *)0x69f3ac, name)) return ext_51ae60(a, b);
  if (!imp_stricmp((const char *)0x69f484, name)) return ext_51b6d0(a, b);
  if (!imp_stricmp((const char *)0x6a4bbc, name)) return ext_51f320(a, b);
  if (!imp_stricmp((const char *)0x6a4bc4, name)) return ext_522dc0(a, b);
  if (!imp_stricmp((const char *)0x6a4bcc, name)) return ext_520010(a, b);
  if (!imp_stricmp((const char *)0x69f26c, name)) return ext_51a8a0(a, b);
  if (!imp_stricmp((const char *)0x6a4bd4, name)) return ext_560440(a, b);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(550db0, fn550db0);
