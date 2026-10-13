// batch1024.cpp - area 81, batch 1024: 0x462bf0, stdcall(path, name, obj) with ret 0xc. No SEH frame; the security cookie check is not reproduced.
// Copies the text after the last backslash of path into a 0x104-byte stack buffer, cuts its last four characters and writes "_" (the word at 0x685a38
// is "_" then NUL), appends name (with its NUL), and calls obj's vtable slot 0x25c with (buffer, 0). When obj is null the result is 0. The exe traps
// when the cut index is not in 0..0xff (it calls 0x634047); the port traps there too. The buffer's bytes past the first NUL are not compared.
#include "ff.h"

// 0x462bf0 (stdcall: path, name, obj).
static u32 __attribute__((stdcall)) pathWithNameCall(u8 *path, u8 *name, u8 *obj) {
  u32 len = 0;
  while (path[len])
    ++len;
  int k = (int)len;
  while (path[k] != 0x5c)
    --k;
  char L[0x104];
  u32 T = 0;
  while (path[k + 1 + T]) {
    L[T] = (char)path[k + 1 + T];
    ++T;
  }
  L[T] = 0;
  u32 idx = T - 4;
  if (idx >= 0x100u)
    __builtin_trap();
  L[idx] = 0x5f;   // the word at 0x685a38 is '_' followed by NUL
  L[idx + 1] = 0;
  u32 p = 0;
  while (L[p])
    ++p;
  u32 bl = 0;
  while (name[bl])
    ++bl;
  if (p + bl + 1 > 0x104u)
    __builtin_trap();
  for (u32 i = 0; i <= bl; ++i)
    L[p + i] = (char)name[i];
  if (!obj)
    return 0;
  return vcall<u32>(obj, 0x25c, (u32)L, 0u);
}
PCREG(462bf0, pathWithNameCall);
