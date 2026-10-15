// batch50015.cpp - cascade u3, tier H: 0x493820
#include "ff.h"

extern "C" void THISCALL ext_4e6870(u8 *self);
extern "C" u32 THISCALL ext_4e68e0(u8 *self, u32 val);
extern "C" u32 STDCALL ext_4e6900(u32 val);

typedef void (THISCALL *MakeKey)(u8 *, void *, u32 *, u32 *);
typedef bool (THISCALL *CompareKey)(u8 *, void *, void *);

static bool THISCALL fn493820(u8 *self, void *arg1, void *arg2, bool grow) {
  if (grow && *(u32 *)(self + 0x10) >= *(u32 *)(self + 8)) ext_4e6870(self);

  u32 key = 0, stepSeed = 0;
  u8 *vt = *(u8 **)self;
  (*(MakeKey *)(vt + 0x10))(self, arg1, &key, &stepSeed);
  u32 idx = ext_4e68e0(self, key);
  u32 step = ext_4e6900(stepSeed);
  u32 count = *(u32 *)(self + 8);
  u32 probes = 0;
  for (;;) {
    u32 wi = idx >> 5, bi = idx & 31, mask = 1u << bi;
    u32 *bits = *(u32 **)(self + 4);
    if ((bits[wi] & mask) && !(*(CompareKey *)(vt + 0x14))(self, (u8 *)*(u32 **)(self + 0x18) + idx * 8, arg1)) {
      ++probes;
      idx = (idx + step) & (count - 1);
      if (probes > count) {
        if (!grow) return false;
        ext_4e6870(self);
        return fn493820(self, arg1, arg2, true);
      }
      continue;
    }

    if (probes > *(u32 *)(self + 0x14)) *(u32 *)(self + 0x14) = probes;
    double d = (double)probes + (probes >> 31 ? 1.0 : 0.0);
    float f = (float)d;
    float sum = f * G(float, 0x67a284) + *(float *)(self + 0x1c) * G(float, 0x683768);
    *(float *)(self + 0x1c) = sum;
    u32 *data = *(u32 **)(self + 0x18);
    data[idx * 2] = *(u32 *)arg1;
    data[idx * 2 + 1] = (u32)arg2;
    if (!(bits[wi] & mask)) { bits[wi] |= mask; ++*(u32 *)(self + 0x10); }
    return true;
  }
}

PCREG(493820, fn493820);
