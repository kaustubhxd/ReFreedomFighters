// batch4152.cpp - unclaimed-41 batch 48 (residue 0 of the relevant list): 0x4e0980 (fastcall: ecx = this, edx = src; this.xyz *= src.xyz; plain ret).
#include "ff.h"

static void FASTCALL fn4e0980(float *self, float *src) {
  self[0] = self[0] * src[0];
  self[1] = self[1] * src[1];
  self[2] = self[2] * src[2];
}
PCREG(4e0980, fn4e0980);
