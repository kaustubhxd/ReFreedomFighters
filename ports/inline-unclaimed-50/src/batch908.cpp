// batch908.cpp - gap band slice: 0x41dd90 [no args, returns al (bool); frame 0x810; stack cookie check at the end (0x633654, not
// reproduced, tagged SEH/cookie). Imports (KERNEL32, through their IAT slots): LoadLibraryA 0x676164, GetProcAddress 0x6760b4 (called
// through the register it was loaded into), GetCurrentProcess 0x6760ac, GetModuleFileNameA 0x67607c, GetEnvironmentVariableA 0x676084,
// GetCurrentDirectoryA 0x676088, FreeLibrary 0x6760b0. Pointers obtained from GetProcAddress are called through the globals.
// Group 1 (load): module = LoadLibraryA("...") (0x676c1c); zero -> false. Eleven GetProcAddress results go to 0x6fcd50..0x6fcd74
//   (each zero -> FreeLibrary and false); a twelfth is only tested (0x676cd8).
// Group 2 (first call only, counter 0x6fcd7c zero): G80 = GetCurrentProcess(); r = [0x6fcd68](); [0x6fcd74](r | 0x80000016);
//   n = GetModuleFileNameA(0, buf, 0x800); if n: p = 0x41d500(buf) (last path separator); skip a ':' ; put ';' and NUL after it.
//   Then GetCurrentDirectoryA(remaining, p) -> d; if d: append the string at the terminator and advance.
//   Then three GetEnvironmentVariableA calls (names at 0x676cf0, 0x676d00, 0x676d1c) appending ';' separators.
// Group 3: [0x6fcd70](G80, buf, 1); global 0x6fcd78 = 0x41e020; the record at 0x6e4084 gets (size 0x18, flags 0x400), zeroed.
#include "ff.h"

extern "C" u8 *THISCALL ext_41d500(void *buf);     // path helper (real exe code, ECX = buffer, returns a pointer)

typedef u32(STDCALL *fn_lib)(u32);
typedef u32(STDCALL *fn_gpa)(u32, u32);
typedef u32(STDCALL *fn_0)(void);
typedef u32(STDCALL *fn_3)(u32, u32, u32);
typedef u32(STDCALL *fn_1)(u32);
typedef u32(STDCALL *fn_dir)(u32, u32);

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x41dd90 (name GUESS "Load41dd90"). Returns the al value.
bool Load41dd90(void) {
  u32 mod = ((fn_lib)G(u32, 0x676164))(0x676c1cu);
  if (mod == 0) return false;
  const u32 gpa = G(u32, 0x6760b4);
  const u32 names[11] = {0x676c28, 0x676c34, 0x676c40, 0x676c58, 0x676c6c, 0x676c80,
                         0x676c94, 0x676ca4, 0x676cb8, 0x676cc8, 0x676cd8};
  const u32 slots[11] = {0x6fcd50, 0x6fcd54, 0x6fcd58, 0x6fcd5c, 0x6fcd60, 0x6fcd64,
                         0x6fcd68, 0x6fcd6c, 0x6fcd70, 0x6fcd74, 0x0};
  for (int k = 0; k < 11; k++) {
    u32 v = ((fn_gpa)gpa)(mod, names[k]);
    if (v == 0) {
      ((fn_1)G(u32, 0x6760b0))(mod);
      return false;
    }
    if (slots[k]) G(u32, slots[k]) = v;
  }
  {
    u32 cnt = G(u32, 0x6fcd7c);
    G(u32, 0x6fcd7c) = cnt + 1;
    if (cnt == 0) {
      u32 g80 = ((fn_0)G(u32, 0x6760ac))();
      G(u32, 0x6fcd80) = g80;
      u32 r68 = ((fn_0)G(u32, 0x6fcd68))();
      ((fn_1)G(u32, 0x6fcd74))(r68 | 0x80000016u);
      char buf[0x804];
      u32 bufEnd = (u32)buf + 0x800;
      u32 esi = (u32)buf;
      u32 ebx = 0x800;
      u32 n = ((fn_3)G(u32, 0x67607c))(0u, (u32)buf, 0x800u);
      if (n != 0) {
        u8 *p = ext_41d500(buf);
        esi = (u32)p;
        if (*(u8 *)esi == 0x3a) esi += 2;
        *(u8 *)esi = 0x3b;
        ebx = bufEnd - (esi + 1);
        esi += 1;
        *(u8 *)esi = 0;
      }
      u32 d = ((fn_dir)G(u32, 0x676088))(ebx, esi);
      if (d != 0) {
        u32 ecx = 0xffffffffu - d;           // ~d
        u8 *edi = (u8 *)(esi - 1);
        do {
          edi++;
        } while (*(edi) != 0);
        // the scan above stops on the NUL at edi (it starts one before esi, as the exe does)
        ebx += ecx;
        *(u16 *)edi = G(u16, 0x676cec);
        esi = esi + 1 + d;
      }
      const u32 envs[3] = {0x676cf0, 0x676d00, 0x676d1c};
      for (int k = 0; k < 3; k++) {
        u32 r = ((fn_3)G(u32, 0x676084))(envs[k], esi, ebx);
        if (r != 0) {
          esi += r;
          u32 ecx2 = 0xffffffffu - r;
          *(u16 *)esi = 0x3b;
          esi += 2;
          ebx += ecx2;
        }
      }
      G(u32, 0x6fcd78) = 0x41e020u;
      ((fn_3)G(u32, 0x6fcd70))(g80, (u32)buf, 1u);
      u8 *rec = (u8 *)G(u32, 0x6e4084);
      for (int i = 0; i < 0x18; i++) rec[i] = 0;
      U32(rec, 0) = 0x18;
      U32(rec, 0x10) = 0x400;
    }
  }
  return true;
}
PCREG(41dd90, Load41dd90);
