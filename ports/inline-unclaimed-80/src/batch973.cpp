#include "ff.h"
// batch973.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md): ten 6-byte wrappers, each `call 0x634d1c; ret` (void, no arguments,
// cdecl). 0x634d1c is an IAT thunk claimed in docs/20-unclaimed-69.md, hooked by address in the spec (GUESS for its contract).
extern "C" void ext_634d1c(void);

static void zgw665076(void) { ext_634d1c(); }
PCREG(665076, zgw665076);
static void zgw66b0b4(void) { ext_634d1c(); }
PCREG(66b0b4, zgw66b0b4);
static void zgw66b0ba(void) { ext_634d1c(); }
PCREG(66b0ba, zgw66b0ba);
static void zgw66b47c(void) { ext_634d1c(); }
PCREG(66b47c, zgw66b47c);
static void zgw66d3b0(void) { ext_634d1c(); }
PCREG(66d3b0, zgw66d3b0);
static void zgw66d3b6(void) { ext_634d1c(); }
PCREG(66d3b6, zgw66d3b6);
static void zgw66d3bc(void) { ext_634d1c(); }
PCREG(66d3bc, zgw66d3bc);
static void zgw66def0(void) { ext_634d1c(); }
PCREG(66def0, zgw66def0);
static void zgw66def6(void) { ext_634d1c(); }
PCREG(66def6, zgw66def6);
static void zgw66defc(void) { ext_634d1c(); }
PCREG(66defc, zgw66defc);
