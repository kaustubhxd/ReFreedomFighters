// u69_21.cpp - area 69, group 21 (slice 8). Address constants and global reads, no args, no callees.
#include "ff.h"

static u32 addrGetter5335c0() { return 0x711d28u; }
PCREG(5335c0, addrGetter5335c0);
static u32 addrGetter601b00() { return 0x694c6cu; }
PCREG(601b00, addrGetter601b00);
static u32 globalGetter490780() { return *(u32 *)0x7003ac; }
PCREG(490780, globalGetter490780);
static u32 globalGetter5b2500() { return *(u32 *)0x6ed350; }
PCREG(5b2500, globalGetter5b2500);
