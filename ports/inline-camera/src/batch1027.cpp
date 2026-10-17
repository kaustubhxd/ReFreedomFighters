// batch1027.cpp - ZFFCam::Save / ZFFCam::Load (camera state in save games). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL u32 ext_4fb2f0(void *self, void *sg);  // ZBaseCamera::Save (batch1026)
extern "C" THISCALL u32 ext_4fb360(void *self, void *lg);  // ZBaseCamera::Load (batch1026)

// ZSaveGame slots: 0x3c handle, 0x44 dword, 0x4c float, 0x60 byte, 0x68 vector*, 0x70 matrix*.
// ZLoadGame slots: 0x40 handle*, 0x48 dword*, 0x50 float*, 0x68 byte*, 0x6c vector*, 0x74 matrix*.
enum Kind : u8 { DW, FL, VEC, BY, MAT, HND };
struct Field {
  u16 off;
  Kind k;
};
// ZFFCam's saved fields in order (collision ray index, hit index, distances, flags, focal point, follow data,
// matrices and positions of camera, focus, player and follow frames).
static const Field kFields[] = {
    {0x64, DW},   {0x68, DW},   {0x2f6, FL},  {0x2fa, FL},  {0x2fe, VEC}, {0x30a, BY},  {0x30b, BY},
    {0x30c, VEC}, {0x318, VEC}, {0x324, VEC}, {0x330, FL},  {0x334, FL},  {0x338, FL},  {0x33c, FL},
    {0x340, FL},  {0x344, MAT}, {0x368, HND}, {0x36c, MAT}, {0x390, VEC}, {0x39c, VEC}, {0x3a8, VEC},
    {0x3b4, MAT}, {0x3d8, VEC}, {0x3e4, MAT}, {0x408, VEC}, {0x414, MAT}, {0x438, VEC}, {0x444, VEC},
    {0x450, BY},
};

// 0x5ca270 ZFFCam::Save(ZSaveGame*)
static THISCALL u32 ZFFCam_Save(u8 *self, void *sg) {
  u32 r = ext_4fb2f0(self, sg);
  if (!(u8)r) return r;
  for (const Field &f : kFields) {
    switch (f.k) {
      case DW: vcall<void>(sg, 0x44, at<u32>(self, f.off)); break;
      case FL: vcall<void>(sg, 0x4c, at<float>(self, f.off)); break;
      case VEC: vcall<void>(sg, 0x68, self + f.off); break;
      case BY: vcall<void>(sg, 0x60, (u32)at<u8>(self, f.off)); break;
      case MAT: vcall<void>(sg, 0x70, self + f.off); break;
      case HND: vcall<void>(sg, 0x3c, at<u32>(self, f.off)); break;
    }
  }
  return (r & ~0xffu) | 1;
}
PCREG(5ca270, ZFFCam_Save);

// 0x5c9f80 ZFFCam::Load(ZLoadGame*)
static THISCALL u32 ZFFCam_Load(u8 *self, void *lg) {
  u32 r = ext_4fb360(self, lg);
  if (!(u8)r) return r;
  for (const Field &f : kFields) {
    static const u16 slot[6] = {0x48, 0x50, 0x6c, 0x68, 0x74, 0x40};
    vcall<void>(lg, slot[f.k], self + f.off);
  }
  return (r & ~0xffu) | 1;
}
PCREG(5c9f80, ZFFCam_Load);

extern "C" THISCALL u32 ext_5ca270(void *self, void *sg);  // ZFFCam::Save (above)
extern "C" THISCALL u32 ext_5c9f80(void *self, void *lg);  // ZFFCam::Load (above)
extern "C" THISCALL void ext_662660(void *ease, void *sg);  // EaseInEaseOut save (inferred)
extern "C" THISCALL void ext_6625c0(void *ease, void *lg);  // EaseInEaseOut load (inferred)

// ZFFCamera1 adds: offsets, FOVs, distances, positions, shake, zoom state, three raw dwords (+0x4d8 .. +0x4e0,
// save slot 0x10 / load slot 0x18 with size 4), the four EaseInEaseOut, and the zoom-in/out flags.
// Extra kinds: TIM = TIMETYPE (save slot 0x54 by value, load slot 0x58), RAW = raw 4 bytes, EAS = ease object.
enum Kind1 : u8 { DW1, FL1, VEC1, BY1, MAT1, HND1, TIM, RAW, EAS };
static const struct { u16 off; Kind1 k; } kFields1[] = {
    {0x451, VEC1}, {0x45d, VEC1}, {0x469, FL1}, {0x46d, FL1}, {0x479, FL1}, {0x47d, FL1}, {0x481, FL1},
    {0x485, FL1},  {0x489, FL1},  {0x48d, VEC1}, {0x499, VEC1}, {0x4a5, FL1}, {0x4a9, BY1}, {0x4aa, FL1},
    {0x4ae, FL1},  {0x4b2, FL1},  {0x4b6, TIM}, {0x4ba, FL1}, {0x4be, FL1}, {0x4c2, FL1}, {0x4c6, FL1},
    {0x4ca, BY1},  {0x4cb, VEC1}, {0x4d8, RAW}, {0x4dc, RAW}, {0x4e0, RAW}, {0x4e4, EAS}, {0x511, EAS},
    {0x53e, EAS},  {0x56b, EAS},  {0x598, BY1}, {0x599, BY1},
};

// 0x5cc620 ZFFCamera1::Save(ZSaveGame*)
static THISCALL u32 ZFFCamera1_Save(u8 *self, void *sg) {
  u32 r = ext_5ca270(self, sg);
  if (!(u8)r) return r;
  for (auto &f : kFields1) {
    switch (f.k) {
      case FL1: vcall<void>(sg, 0x4c, at<float>(self, f.off)); break;
      case VEC1: vcall<void>(sg, 0x68, self + f.off); break;
      case BY1: vcall<void>(sg, 0x60, (u32)at<u8>(self, f.off)); break;
      case TIM: vcall<void>(sg, 0x54, at<u32>(self, f.off)); break;
      case RAW: vcall<void>(sg, 0x10, self + f.off, 4u); break;
      case EAS: ext_662660(self + f.off, sg); break;
      default: break;
    }
  }
  return (r & ~0xffu) | 1;
}
PCREG(5cc620, ZFFCamera1_Save);

// 0x5cc020 ZFFCamera1::Load(ZLoadGame*)
static THISCALL u32 ZFFCamera1_Load(u8 *self, void *lg) {
  u32 r = ext_5c9f80(self, lg);
  if (!(u8)r) return r;
  for (auto &f : kFields1) {
    switch (f.k) {
      case FL1: vcall<void>(lg, 0x50, self + f.off); break;
      case VEC1: vcall<void>(lg, 0x6c, self + f.off); break;
      case BY1: vcall<void>(lg, 0x68, self + f.off); break;
      case TIM: vcall<void>(lg, 0x58, self + f.off); break;
      case RAW: vcall<void>(lg, 0x18, self + f.off, 4u); break;
      case EAS: ext_6625c0(self + f.off, lg); break;
      default: break;
    }
  }
  return (r & ~0xffu) | 1;
}
PCREG(5cc020, ZFFCamera1_Load);
