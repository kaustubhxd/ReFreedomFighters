// batch4155.cpp - unclaimed-41 batch 49 (residue 0 of the relevant list): 0x5ebf00 (sets the byte at +0xa6); thiscall, no stack arguments.
#include "ff.h"

static void THISCALL fn5ebf00(u8 *self) {
  self[0xa6] = 1;
}
PCREG(5ebf00, fn5ebf00);
