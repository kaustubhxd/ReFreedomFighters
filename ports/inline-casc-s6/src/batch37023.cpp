// batch37023.cpp - cascade s6 batch 37023: 0x550c50.
#include "ff.h"

extern "C" u32 THISCALL ext_51a810(u8 *c);
extern "C" u32 THISCALL ext_51add0(u8 *c);
extern "C" u32 THISCALL ext_51b640(u8 *c);
extern "C" u32 THISCALL ext_51f290(u8 *c);
extern "C" u32 THISCALL ext_51ff80(u8 *c);
extern "C" u32 THISCALL ext_522d30(u8 *c);
extern "C" u32 THISCALL ext_557930(u8 *c);
extern "C" u32 THISCALL ext_55ec70(u8 *c);
extern "C" u32 THISCALL ext_55fa40(u8 *c);
extern "C" u32 THISCALL ext_5603e0(u8 *c);
typedef int(*stricmp_t)(const char *, const char *);
typedef u32(*hook_t)();
#define imp_stricmp G(stricmp_t, 0x676414)

// 0x550c50, stdcall(name, ctx) ret 8: dispatches on the case-insensitive name (11 strings in the exe image, tested in order through the _stricmp import) to the matching
// handler, which runs with ecx = ctx and whose result is returned (the last string shares the handler of the third). An unknown name calls the assert hook at
// 0x7003b0 (int3 when it is null) and returns 0.
static u32 STDCALL fn550c50(const char *name, u8 *ctx) {
  if (!imp_stricmp((const char *)0x6a4b74, name)) return ext_55ec70(ctx);
  if (!imp_stricmp((const char *)0x6a4b80, name)) return ext_55fa40(ctx);
  if (!imp_stricmp((const char *)0x6a4b8c, name)) return ext_5603e0(ctx);
  if (!imp_stricmp((const char *)0x6a4b68, name)) return ext_557930(ctx);
  if (!imp_stricmp((const char *)0x69f3ac, name)) return ext_51add0(ctx);
  if (!imp_stricmp((const char *)0x69f484, name)) return ext_51b640(ctx);
  if (!imp_stricmp((const char *)0x6a4bbc, name)) return ext_51f290(ctx);
  if (!imp_stricmp((const char *)0x6a4bc4, name)) return ext_522d30(ctx);
  if (!imp_stricmp((const char *)0x6a4bcc, name)) return ext_51ff80(ctx);
  if (!imp_stricmp((const char *)0x69f26c, name)) return ext_51a810(ctx);
  if (!imp_stricmp((const char *)0x6a4bd4, name)) return ext_5603e0(ctx);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(550c50, fn550c50);
