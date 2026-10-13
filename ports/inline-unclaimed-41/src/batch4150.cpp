// batch4150.cpp - unclaimed-41 batch 48 (residue 0 of the relevant list): 0x445e80 (thiscall, no arguments; returns al = this[0x170]).
#include "ff.h"

static u8 THISCALL fn445e80(u8 *self) {
  return self[0x170];
}
PCREG(445e80, fn445e80);
