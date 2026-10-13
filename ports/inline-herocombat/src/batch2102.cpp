// batch2102.cpp - wire-hero-combat thread, batch 2102: ZProjectile::FrameUpdate 0x4b96c0 (the round's per-frame flight).
// Lifted 2026-10-13 from the exe (docs/20-unclaimed-73.md had it parked, not read).
#include "ff.h"

typedef void(THISCALL *vcall0)(void *self);
typedef void(THISCALL *vcallP)(void *self, const float *p);
typedef u8 *(THISCALL *vcallH)(void *self, u32 handle);

extern "C" void THISCALL ext_4b9940(u8 *self);                                         // FrameUpdateBallistic (batch 68)
extern "C" float THISCALL ext_4b9340(u8 *self, float dist);                            // CheckHit, result in ST0
extern "C" void THISCALL ext_4ba7f0(u8 *self, u8 *coli);                               // ShotImpact
extern "C" THISCALL void ext_4dc630(void *geom, u32 set, u32 clear);                   // ZBaseGeom::SetControl
extern "C" void FASTCALL ext_443ef0(float *dst, const float *a, const float *v, float s); // dst = a + v * s

static inline u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *rmLookup(u32 h) { u8 *rm = rmgr(); return ((vcallH)(*(void ***)rm)[0x58 / 4])(rm, h); }

// 0x4b96c0, thiscall, no args. Flags +0x89: bit 0x10 -> FrameUpdateBallistic and return; bit 8 -> the geom (+0x44) slot
// 0x28 (remove) and return. Otherwise: the time since the last update (+0x69, s; clock [[0x70039c]+0x40] in 1/1024 s
// ticks, the old time truncated to ticks) times the speed +0x51 * 100 is the distance to fly this frame; +0x69 = now.
// The owner (+0x5d, a render-manager handle) has its geom's control bits 6 cleared for the flight and restored after.
// While distance is left: h = CheckHit(distance). If h != distance (a hit, or NaN): look up the hit object (COLI
// [+0x8d] +0x44); the owner itself -> +0x65 = it (passes through); a known object -> unless (its geom bit 4 and flag
// bit 1: +0x65 = it, pass through) flag 8 and distance = h; then ShotImpact(COLI); h += 1. Every step moves the geom
// by h along minus its matrix row 2 (geom slot 0x70 with the new position), adds h to +0x55 (flown) and subtracts it
// from the distance. After the flight: flown > the range +0x59, or flag 8: remove now when the geom matrix's +0x40 is
// above the flown distance, else set flag 8. Name ZProjectile::FrameUpdate (name map high).
static void THISCALL projFrameUpdate(u8 *self) {
  u32 fl = *(u32 *)(self + 0x89);
  if (fl & 0x10) {
    ext_4b9940(self);
    return;
  }
  if (fl & 8) {
    u8 *g = *(u8 **)(self + 0x44);
    ((vcall0)(*(void ***)g)[0x28 / 4])(g);
    return;
  }
  u8 *sys = G(u8 *, 0x70039c);
  s32 last = (s32)(*(float *)(self + 0x69) * G(float, 0x678620));
  s32 now = *(s32 *)(sys + 0x40);
  u32 ownerH = *(u32 *)(self + 0x5d);
  *(float *)(self + 0x69) = (float)now * G(float, 0x6785e4);
  float secs = (float)(now - last) * G(float, 0x6785e4);
  float speed = *(float *)(self + 0x51) * G(float, 0x67cd40);
  float dist = secs * speed;
  u8 *owner = rmLookup(ownerH);
  u32 saved;
  if (owner) {
    void *og = *(void **)(owner + 8);
    saved = *(u32 *)((u8 *)og + 0x3c) & 6;
    ext_4dc630(og, 0, 6);
  } else {
    saved = 0;
  }
  if (dist > 0.0f) {
    do {
      float h = ext_4b9340(self, dist);
      if (h != dist) {
        u8 *coli = *(u8 **)(self + 0x8d);
        u8 *hit = rmLookup(*(u32 *)(coli + 0x44));
        u32 hitH = *(u32 *)(*(u8 **)(self + 0x8d) + 0x44);
        if (hitH == *(u32 *)(self + 0x5d)) {
          *(u32 *)(self + 0x65) = hitH;
        } else if (hit != 0) {
          u8 *obj = rmLookup(hitH);
          u8 *og = *(u8 **)(obj + 8);
          if ((og[0x3c] & 4) && (self[0x89] & 1)) {
            *(u32 *)(self + 0x65) = *(u32 *)(*(u8 **)(self + 0x8d) + 0x44);
          } else {
            *(u32 *)(self + 0x89) |= 8;
            dist = h;
          }
          ext_4ba7f0(self, *(u8 **)(self + 0x8d));
        }
        h = h + G(float, 0x678858);
      }
      u8 *m = *(u8 **)(*(u8 **)(self + 0x44) + 8);
      float p[3];
      ext_443ef0(p, (const float *)(m + 0x24), (const float *)(m + 0x18), -h);
      u8 *g = *(u8 **)(self + 0x44);
      ((vcallP)(*(void ***)g)[0x70 / 4])(g, p);
      *(float *)(self + 0x55) = *(float *)(self + 0x55) + h;
      dist = dist - h;
    } while (dist > 0.0f);
  }
  if (owner)
    ext_4dc630(*(void **)(owner + 8), saved, 0);
  float flown = *(float *)(self + 0x55);
  if (flown > *(float *)(self + 0x59) || (*(u32 *)(self + 0x89) & 8)) {
    u8 *g = *(u8 **)(self + 0x44);
    if (*(float *)(*(u8 **)(g + 8) + 0x40) > flown) {
      ((vcall0)(*(void ***)g)[0x28 / 4])(g);
      return;
    }
    *(u32 *)(self + 0x89) |= 8;
  }
}
PCREG(4b96c0, projFrameUpdate);
