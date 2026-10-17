// batch240002.cpp - Sonnet-w4a: CRT helpers (PE section lookup, startup info, security cookie check).
#include "ff.h"

extern "C" u32 ext_634d10(void *dst, u32 val, u32 n);   // memset (cdecl)
extern "C" void FASTCALL ext_633f4c(u32 cookie);           // __report_gsfailure-style fatal handler, ecx = value

// 0x633cbc: cdecl(base, rva): the PE section header of `base` containing rva, or 0
static u8 *fn_633cbc(u8 *base, u32 rva) {
  u8 *nt = base + *(u32 *)(base + 0x3c);
  u8 *sec = nt + 0x18 + *(u16 *)(nt + 0x14);
  u8 *end = sec + (u32)*(u16 *)(nt + 6) * 0x28;
  for (; sec != end; sec += 0x28) {
    u32 va = *(u32 *)(sec + 0xc);
    if (rva < va) continue;
    if (rva < *(u32 *)(sec + 8) + va) return sec;
  }
  return 0;
}
PCREG(633cbc, fn_633cbc);

// 0x634994: cdecl(): GetStartupInfo-style import [0x676050](buf) over a zeroed 0x44-byte block; returns wShowWindow when
// STARTF_USESHOWWINDOW (flags & 1), else 10
static u32 fn_634994() {
  u8 si[0x44];
  ext_634d10(si, 0, 0x44);
  (*(void(__stdcall **)(void *))0x676050)(si);
  if (*(u8 *)(si + 0x2c) & 1) return *(u16 *)(si + 0x30);
  return 10;
}
PCREG(634994, fn_634994);

// 0x633654: fastcall-ish (ecx = value): return when ecx == security cookie, else tail jump to the fatal handler 633f4c(ecx)
static void FASTCALL fn_633654(u32 v) {
  if (v == G(u32, 0x6f5630)) return;
  ext_633f4c(v);
}
PCREG(633654, fn_633654);
