// batch37108.cpp - cascade s6 batch 37108: 0x500020.
#include "ff.h"

extern "C" u32 FASTCALL ext_50b680(u32 a, u32 b);
extern "C" u32 FASTCALL ext_50d8e0(u32 a, u32 b);
extern "C" u32 FASTCALL ext_510f90(u32 a, u32 b);
extern "C" u32 FASTCALL ext_511830(u32 a, u32 b);
extern "C" u32 FASTCALL ext_504660(u32 a, u32 b);
extern "C" u32 FASTCALL ext_506160(u32 a, u32 b);
extern "C" u32 FASTCALL ext_5096c0(u32 a, u32 b);
extern "C" u32 FASTCALL ext_50a540(u32 a, u32 b);
typedef int (*stricmp_t)(const char *, const char *);
typedef u32 (*hook_t)();
#define imp_stricmp G(stricmp_t, 0x676414)

// 0x500020, stdcall(name, a, b) ret 0xc: dispatches on the case-insensitive name (eight strings in the exe image, tested in order through the _stricmp import) to the matching
// fastcall handler (ecx = a, edx = b) whose result is returned. An unknown name calls the assert hook at 0x7003b0 (int3 when it is null) and returns 0.
static u32 STDCALL fn500020(const char *name, u32 a, u32 b) {
  if (!imp_stricmp((const char *)0x69c770, name)) return ext_50b680(a, b);
  if (!imp_stricmp((const char *)0x69c77c, name)) return ext_50d8e0(a, b);
  if (!imp_stricmp((const char *)0x69c784, name)) return ext_510f90(a, b);
  if (!imp_stricmp((const char *)0x69c790, name)) return ext_511830(a, b);
  if (!imp_stricmp((const char *)0x685230, name)) return ext_504660(a, b);
  if (!imp_stricmp((const char *)0x69c754, name)) return ext_506160(a, b);
  if (!imp_stricmp((const char *)0x69c75c, name)) return ext_5096c0(a, b);
  if (!imp_stricmp((const char *)0x69c768, name)) return ext_50a540(a, b);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(500020, fn500020);
