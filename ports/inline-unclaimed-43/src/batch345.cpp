// batch345.cpp - 0x41e170 (gap band). Forwarder: push ebp / mov ebp,esp / pop ebp / jmp [IAT 0x676254] (strchr from VCRUNTIME140).
// cdecl with (const char *s, int c); the stack arguments pass through unchanged, so the port calls strchr with the same two.
#include "ff.h"

static const char *cdeclForwardStrchr(const char *s, int c) {
  return ((const char *(*)(const char *, int))(unsigned long)(*(u32 *)0x676254u))(s, c);
}
PCREG(41e170, cdeclForwardStrchr);
