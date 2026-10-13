// batch1153.cpp - collision thread, batch 1153 (name GUESS): 0x4fc170 is a thunk (jmp 0x4fdd20, UpdateMainCamera, a thiscall
// with no arguments and plain ret). The target runs as exe code; this port forwards ECX.
#include "ff.h"

extern "C" void THISCALL ext_4fdd20(void *self);   // exe: camera update, thiscall, plain ret

static void THISCALL thunk4fc170(void *self) {
  ext_4fdd20(self);
}
PCREG(4fc170, thunk4fc170);
