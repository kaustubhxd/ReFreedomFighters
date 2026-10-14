// batch1607.cpp - where a shout's subtitle and "talking" marker go: ZGameOSD forwarders and
// CActorActionMarker::Add (soundtimers thread, 2026-10-11).
#include "st.h"

typedef void(THISCALL *Fwd3)(void *self, u32 a, u32 b, float t);
extern "C" char ext_5aaa50[], ext_5eab20[], ext_5ef950[];

// 0x59a5b0 ZGameOSD::MessageDialog(name, text, seconds) [high]: forwards to its ZOnScreenDisplay (+0x1d0f) if any.
void THISCALL ZGameOSD_MessageDialog(void *self, u32 name, u32 text, float t) {
  void *osd = AT(void *, self, 0x1d0f);
  if (osd) ((Fwd3)(void *)ext_5aaa50)(osd, name, text, t);
}
PCREG(59a5b0, ZGameOSD_MessageDialog);

// 0x5aaa50 ZOnScreenDisplay::MessageDialog [medium]: forwards to the dialog box object at +0x64c (0x5ef950, the text
// layout; not ported here: it belongs to the HUD).
void THISCALL ZOnScreenDisplay_MessageDialog(void *self, u32 name, u32 text, float t) {
  ((Fwd3)(void *)ext_5ef950)(AT(void *, self, 0x64c), name, text, t);
}
PCREG(5aaa50, ZOnScreenDisplay_MessageDialog);

// 0x598e10 ZGameOSD::AddActorActionMarker(actor, kind, seconds) [high]: forwards to the marker list at +0x22d7
// (no null check).
void THISCALL ZGameOSD_AddActorActionMarker(void *self, u32 actor, u32 kind, float t) {
  ((Fwd3)(void *)ext_5eab20)(AT(void *, self, 0x22d7), actor, kind, t);
}
PCREG(598e10, ZGameOSD_AddActorActionMarker);

// 0x5eab20 CActorActionMarker::Add(actor, kind, seconds) [medium]: up to 16 markers (count +0x44, entry pointers at
// +4). Entry: +0 actor, +4 kind, +8 seconds, +0xc previous kind, +0x10 previous seconds, +0x14 u8 "positive".
// A negative time is stored negated with +0x14 = 0. An actor already in the list is updated in place: when the kind
// changes to 1 (the shouts use 1) the old kind and time are kept in +0xc/+0x10, any other change clears them.
// A full list ignores new actors.
void THISCALL CActorActionMarker_Add(void *self, void *actor, u32 kind, float t) {
  u32 n = AT(u32, self, 0x44);
  if (n == 0x10) return;
  u32 i = 0;
  bool found = false;
  if (n) {
    for (;;) {
      if (AT(void *, AT(u8 *, self, 4 + 4 * i), 0) == actor) {
        found = true;
        break;
      }
      i++;
      if (i >= AT(u32, self, 0x44)) break;
    }
  }
  u8 *e = AT(u8 *, self, 4 + 4 * i);
  if (0.0f > t) {
    t = __builtin_bit_cast(float, __builtin_bit_cast(u32, t) ^ 0x80000000u);  // xorps with 0x67af40
    AT(u8, e, 0x14) = 0;
  } else {
    AT(u8, e, 0x14) = 1;
  }
  if (found) {
    e = AT(u8 *, self, 4 + 4 * i);
    u32 old = AT(u32, e, 4);
    if (kind != old) {
      if (kind == 1) {
        AT(u32, e, 0xc) = old;
        u8 *e2 = AT(u8 *, self, 4 + 4 * i);
        AT(u32, e2, 0x10) = AT(u32, e2, 8);
      } else {
        AT(u32, e, 0xc) = 0;
        AT(u32, AT(u8 *, self, 4 + 4 * i), 0x10) = 0;
      }
      AT(u32, AT(u8 *, self, 4 + 4 * i), 4) = kind;
      e = AT(u8 *, self, 4 + 4 * i);
    }
    AT(float, e, 8) = t;
    return;
  }
  AT(void *, AT(u8 *, self, 4 + 4 * AT(u32, self, 0x44)), 0) = actor;
  AT(u32, AT(u8 *, self, 4 + 4 * AT(u32, self, 0x44)), 4) = kind;
  AT(float, AT(u8 *, self, 4 + 4 * AT(u32, self, 0x44)), 8) = t;
  AT(u32, AT(u8 *, self, 4 + 4 * AT(u32, self, 0x44)), 0xc) = 0;
  AT(u32, AT(u8 *, self, 4 + 4 * AT(u32, self, 0x44)), 0x10) = 0;
  AT(u32, self, 0x44) += 1;
}
PCREG(5eab20, CActorActionMarker_Add);
