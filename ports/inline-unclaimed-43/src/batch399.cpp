// batch399.cpp - 0x41e080 (gap band, parked row). cdecl, no arguments. Reads the file at global 0x6fd1a4 into a stack buffer:
// n = ftell(file), clamped to 0x3fff; rewind(file); fread(buf, 1, n, file); buf[0x3fff] = 0 (the exe's byte at ebp-9);
// 0x42ad40(0x676c08, 0, buf) (exe, stdcall with three arguments; hooked by address in the spec, GUESS: its body is not
// ported); fclose(file). The imports are called through their IAT slots (ftell 0x6763f4, rewind 0x6763f0, fread 0x6763f8,
// fclose 0x6763ac). The exe's stack cookie check is not reproduced.
#include "ff.h"

extern "C" void STDCALL ext_42ad40(u32 a, u32 b, void *buf);   // parser by address (hooked in the spec)

static void readFileIntoParser(void) {
  u8 buf[0x4000];
  u32 file = *(u32 *)0x6fd1a4u;
  s32 n = ((s32(*)(u32))(unsigned long)(*(u32 *)0x6763f4u))(file);
  if (n > 0x3fff)
    n = 0x3fff;
  ((void (*)(u32))(unsigned long)(*(u32 *)0x6763f0u))(file);
  ((u32(*)(void *, u32, u32, u32))(unsigned long)(*(u32 *)0x6763f8u))(buf, 1u, (u32)n, file);
  buf[0x3fff] = 0;
  ext_42ad40(0x676c08u, 0u, buf);
  ((u32(*)(u32))(unsigned long)(*(u32 *)0x6763acu))(file);
}
PCREG(41e080, readFileIntoParser);
