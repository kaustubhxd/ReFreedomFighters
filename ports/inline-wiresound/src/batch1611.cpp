// batch1611.cpp - ZGROUP::AddSound3d / AddSound2d, the engine side of every character sound (soundtimers thread).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *dll() { return AT(void *, sys(), 0x1a9f); }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }
typedef void(THISCALL *ProfFn)(const char *name);
extern "C" char ext_441730[], ext_440530[];  // profiler begin / end (batch 48: profBegin / profEnd); name in ECX

// 0x441890 (no map name; "set distances from the record", guessed name) thiscall on a ZSoundObject: with volume
// +0x88 == 0.0: min distance +0x54 = 1, max +0x5c = 2. Otherwise min = d x 100 and max = (volume / 0.78125) x min.
void THISCALL ZSoundObject_SetDistances(void *self, float d) {
  float vol = AT(float, self, 0x88);
  if (vol == 0.0f) {
    AT(u32, self, 0x54) = 0x3f800000;
    AT(u32, self, 0x5c) = 0x40000000;
    return;
  }
  float q = vol / 0.78125f;   // 0x67cd3c
  float mn = d * 100.0f;      // 0x67cd40
  AT(float, self, 0x54) = mn;
  AT(float, self, 0x5c) = q * mn;
}
PCREG(441890, ZSoundObject_SetDistances);

// 0x43eb80 ZGROUP::AddSound2d(int sound) [high]: DLL +0x120(sound, 4), 0 without a DLL.
u32 THISCALL ZGROUP_AddSound2d(void *self, u32 sound) {
  void *d = dll();
  if (!d) return 0;
  return vcall<u32>(d, 0x120, sound, (u32)4);
}
PCREG(43eb80, ZGROUP_AddSound2d);

// 0x43ec00 ZGROUP::AddSound3d(float* mat, float* pos, int sound, int kind, uint a5, uint a6) [high]. Without a DLL
// or with sound 0: 0. The DLL makes the sound (+0x11c(group, sound, mat, pos), between profiler marks
// "Addsound3d"); its min/max distances come from the sound's SND record (DLL +0x54(sound +0x7c), float at +0xc,
// scaled x100, see SetDistances). Then, unless kind is 0xc, or kind is 0 and the record is not type 2 or its byte
// +0x17 is 0 (that byte then becomes the kind), DLL +0xd8(group, group position (vtable +0x84), kind, sound, a5, a6)
// (meaning not traced; footsteps pass 4 or 0xc). Returns the handle.
u32 THISCALL ZGROUP_AddSound3d(void *self, float *mat, float *pos, u32 sound, s32 kind, u32 a5, u32 a6) {
  if (!dll()) return 0;
  if (!sound) return 0;
  ((ProfFn)(void *)ext_441730)((const char *)0x67cd30);  // "Addsound3d"
  u32 h = vcall<u32>(dll(), 0x11c, self, sound, mat, pos);
  ((ProfFn)(void *)ext_440530)((const char *)0x67cd30);
  if (!h) return 0;
  u8 *o = (u8 *)srefToPtr(h);
  if (!o) return 0;
  u8 *rec = vcall<u8 *>(dll(), 0x54, AT(u32, o, 0x7c));
  ZSoundObject_SetDistances(o, AT(float, rec, 0xc));
  if (kind == 0xc) return h;
  if (kind == 0) {
    if (AT(u32, rec, 0) != 2) return h;
    kind = AT(s8, rec, 0x17);
    if (!kind) return h;
  }
  float v[3] = {pos[0], pos[1], pos[2]};
  vcall<void>(self, 0x84, v);
  vcall<void>(dll(), 0xd8, self, v, kind, sound, a5, a6);
  return h;
}
PCREG(43ec00, ZGROUP_AddSound3d);
