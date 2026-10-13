// batch1430.cpp - missions thread, batch 1430: ZObjectives::SetupIconObj(icon, bool, name).
// Object table: [this+0x190 + 4*idx] for idx = [this+0x202] (the icon count [this+0x1fe] bounds it). The per-icon
// object's slots are unnamed (stubbed by number in the checker; GUESS names are not used in the code):
//   slot 0x2a0(int), slot 0x284(const char*), slot 0xbc(bool), slot 0x70(float*), slot 0x260(int); field +0x93 (dword)
//   is set to -6. ZBaseMap::SetupIcon (0x574af0) is other areas' code (real exe code; hooked in the checker).
#include "missions.h"

extern "C" void THISCALL ext_574af0(u8 *self, u32 icon, float *pos, u32 flag, u32 zero, u8 *charObj);   // ZBaseMap::SetupIcon

static inline void call1(u8 *o, u32 slot, u32 arg) { ((void(THISCALL *)(u8 *, u32))(*(void ***)o)[slot / 4])(o, arg); }
static inline void call1f(u8 *o, u32 slot, float *arg) { ((void(THISCALL *)(u8 *, float *))(*(void ***)o)[slot / 4])(o, arg); }
static inline void call1s(u8 *o, u32 slot, const char *arg) { ((void(THISCALL *)(u8 *, const char *))(*(void ***)o)[slot / 4])(o, arg); }

// 0x578430 ZObjectives::SetupIconObj(ESubZoneMapIcon icon, bool flag, const char *name). Returns nothing (ret 0xc).
static void THISCALL zobjSetupIconObj(u8 *self, u32 icon, u32 flag, const char *name) {
  if (*(u32 *)(self + 0x202) >= *(u32 *)(self + 0x1fe))
    return;
  float *p = (float *)(self + 0x210);
  ext_574af0(self, icon, p, flag, 0, 0);   // ZBaseMap::SetupIcon(icon, pos, flag, false, 0)
  float v[3];
  v[0] = p[0] + 30.0f;
  v[1] = *(float *)(self + 0x214);
  v[2] = 0.0f;
  u32 idx = *(u32 *)(self + 0x202);
  u8 *o = *(u8 **)(self + 0x190 + idx * 4);
  call1(o, 0x2a0, (u32)(s32)*(float *)(self + 0x21c));   // the trunc of the float at +0x21c
  idx = *(u32 *)(self + 0x202);
  u8 *o2 = *(u8 **)(self + 0x190 + idx * 4);
  *(u32 *)(o2 + 0x93) = 0xfffffffau;                       // -6
  idx = *(u32 *)(self + 0x202);
  u8 *o3 = *(u8 **)(self + 0x190 + idx * 4);
  call1s(o3, 0x284, name);
  idx = *(u32 *)(self + 0x202);
  u8 *o4 = *(u8 **)(self + 0x190 + idx * 4);
  call1(o4, 0xbc, 0);
  idx = *(u32 *)(self + 0x202);
  u8 *o5 = *(u8 **)(self + 0x190 + idx * 4);
  call1f(o5, 0x70, v);
  idx = *(u32 *)(self + 0x202);
  u8 *o6 = *(u8 **)(self + 0x190 + idx * 4);
  call1(o6, 0x260, 0x41);
  float t = (float)(s32)*(s32 *)(self + 0x220);
  (*(u32 *)(self + 0x202))++;
  *(float *)(self + 0x214) = t + *(float *)(self + 0x214);
}
PCREG(578430, zobjSetupIconObj);
