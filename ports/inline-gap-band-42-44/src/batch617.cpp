// batch617.cpp - band 0x421000-0x441000, batch 617: 0x424d50, a debug-log forwarder (cdecl, one argument, no pops).
// The logger at [0x700390] gets slot 0x2c as a cdecl printf: (logger, fmt 0x677368, argument).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef int (*vPrintf)(void *stream, const char *fmt, u32 a);

static void logForwarder(u32 a) {
  u8 *lg = G(u8 *, 0x700390);
  ((vPrintf)VT(lg, 0x2c))(lg, (const char *)0x677368, a);
}
PCREG(424d50, logForwarder);
