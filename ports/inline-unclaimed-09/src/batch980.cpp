// batch980.cpp - area 56 band, claim A46 (0x535990): stdcall, three floats, returns an int; no calls.
#include "ff.h"

// A46 0x535990: x = (a == 0) ? K2 : a; r = (x > b) ? x / b : 0; t = (K0 - c) * K3 - (r * r) * K4; return (int)t.
static s32 STDCALL f535990(float a, float b, float c) {
  float x = (a == 0.0f) ? G(float, 0x678858) : a;
  float r = 0.0f;
  if (x > b) r = x / b;
  float t = (G(float, 0x67cd40) - c) * G(float, 0x6a24f4);
  float u = (r * r) * G(float, 0x680a70);
  t = t - u;
  return (s32)t;
}
PCREG(535990, f535990);
