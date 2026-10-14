// batch907.cpp - gap band slice: 0x41e120 [cdecl, varargs (format, ...), no result]. Formats the arguments with wvsprintfA
// (USER32 import at 0x6761e8, stdcall, three words: buffer, format, the argument pointer) into an 0x804-byte buffer, then calls
// 0x42ab49 (cdecl: the handle at 0x6fd1a4, the format 0x676c18, the buffer). The exe's stack cookie check (0x633654) is not
// reproduced, and neither is its stack frame. Stood in: 0x42ab49 (logger).
#include "ff.h"

extern "C" void ext_42ab49(void *handle, const char *fmt, char *buf);   // logger (stood in); cdecl

typedef int(STDCALL *wvsprintf_t)(char *, const char *, void *);

// 0x41e120 (name GUESS "Log41e120").
void Log41e120(const char *fmt, ...) {
  char buf[0x804];
  __builtin_va_list ap;
  __builtin_va_start(ap, fmt);
  ((wvsprintf_t)G(u32, 0x6761e8))(buf, fmt, (void *)ap);
  __builtin_va_end(ap);
  ext_42ab49((void *)G(u32, 0x6fd1a4), (const char *)0x676c18u, buf);
}
PCREG(41e120, Log41e120);
