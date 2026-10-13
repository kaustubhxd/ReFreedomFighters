// batch1413.cpp - missions thread, batch 1413: ZFFCareTaker_C01A::FrameUpdate, the tutorial's per-frame checks.
//
// More C01A fields: +0x48 float debug "jump to act" request, +0x4c Bagzton, +0x50 Jones, +0x54 a third actor,
// +0x5c current act, +0x60/+0x61 "item lesson done" flags, +0x64/+0x65 one-shot requests, +0x76/+0x78 message ids,
// +0xbd hint 0x11 shown.
#include "missions.h"

extern "C" void THISCALL ext_5ba310(u8 *ct, s32 act);   // ZFFCareTaker_C01A::JumpToAct (batch 1412)
extern "C" u32 THISCALL ext_591b20(u8 *hero);           // ZFFHERO::GetFFItemType()
extern "C" void THISCALL ext_5af7c0(u8 *inv, u32 type, u32 n, u32 flag);   // ZFFInventoryBridge::GiveAmmo
extern "C" float FASTCALL ext_4e0870(float *a, float *b);                 // distance |a - b| (x87 return)
extern "C" void THISCALL ext_597fc0(u8 *osd, u32 hint, u32 flag);         // ZGameOSD::HintMessage
extern "C" void THISCALL ext_597fb0(u8 *osd);                             // ZGameOSD::HideHintMessage
#define CARETAKER_C01A_CPP 0x6b290cu

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline void send(u8 *ct, u32 target, u32 msg, u32 data) {
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x130, target, msg, data);
}
static float heroDistFromStart(u8 *ct) {   // hero position (slot 0x84) to the position saved at Init2 (+0xbe)
  float p[3] = {0.0f, 0.0f, 0.0f};
  vcall<void, float *>(*(u8 **)(ct + 0x58), 0x84, p);
  return ext_4e0870(p, (float *)(ct + 0xbe));
}

// 0x5b9f20 ZFFCareTaker_C01A::FrameUpdate().
//  - A pending debug act jump (+0x48 > 0) runs JumpToAct(round(+0x48)).
//  - +0x64: clears field +0xcd of Jones's slot-0x50c object. +0x65: a hero holding item type 4 gets 15 ammo of it.
//  - 8 s after Init2 (timer ticks are 1/1024 s): a hero still within 400 units of where it started sees hint 0x11
//    (+0xbd); the hint is hidden once the hero is more than 400 units away.
//  - Before the first act (+0x5c == 0) and after +0xb9: Jones and the +0x54 actor get message +0x78; the next
//    reminder is due 8 s later minus a random 0..2 s (sys slot 0x1c4 returns a random float).
//  - Act 9: holding item type 0xc (once, +0x60) sends message +0x76 to Bagzton. Act 5: holding type 0x10 (once,
//    +0x61) sends it to Jones. Act 10: hero slot 0x5d0 == 0x10 sends "OpeningSewer" to Bagzton.
static void THISCALL c01aFrameUpdate(u8 *ct) {
  float jump = *(float *)(ct + 0x48);
  if (comiss_gt(jump, 0.0f)) {
    ext_5ba310(ct, (s32)(jump - 0.5f));
    *(u32 *)(ct + 0x48) = 0;
  }
  if (ct[0x64] && vcall<u8 *>(*(u8 **)(ct + 0x50), 0x50c)) {
    *(u32 *)(vcall<u8 *>(*(u8 **)(ct + 0x50), 0x50c) + 0xcd) = 0;
    ct[0x64] = 0;
  }
  if (ct[0x65]) {
    u32 t = ext_591b20(*(u8 **)(ct + 0x58));
    if (t == 4) {
      ext_5af7c0(*(u8 **)(ct + 0x58) + 0x9c7, t, 0xf, 1);
      ct[0x65] = 0;
    }
  }
  if (!ct[0xb8]) {
    float secs = (float)(s32)(*(u32 *)(sysi() + 0x40) - *(u32 *)(ct + 0xb4)) * 0.0009765625f;
    if (comiss_gt(secs, 8.0f)) {
      float d = heroDistFromStart(ct);
      if (comiss_gt(400.0f, d)) {
        ext_597fc0(*(u8 **)(*(u8 **)(ct + 0x58) + 0x852), 0x11, 0);
        ct[0xbd] = 1;
      }
      ct[0xb8] = 1;
    }
  }
  if (ct[0xbd]) {
    float d = heroDistFromStart(ct);
    if (comiss_gt(d, 400.0f)) {
      ext_597fb0(*(u8 **)(*(u8 **)(ct + 0x58) + 0x852));
      ct[0xbd] = 0;
    }
  }
  if (*(u32 *)(ct + 0x5c) == 0 && *(s32 *)(sysi() + 0x40) > *(s32 *)(ct + 0xb9)) {
    send(ct, *(u32 *)(ct + 0x54), *(u16 *)(ct + 0x78), 0);
    send(ct, *(u32 *)(ct + 0x50), *(u16 *)(ct + 0x78), 0);
    u8 *s = sysi();
    s32 due = *(s32 *)(s + 0x40) + 0x2000;
    long double r = vcall<long double, const char *, u32>(s, 0x1c4, (const char *)CARETAKER_C01A_CPP, 0x9d);
    float v = (float)((r + r) * (long double)-1024.0f);
    *(s32 *)(ct + 0xb9) = due - (s32)v;
  }
  u32 act = *(u32 *)(ct + 0x5c);
  if (act == 9) {
    if (!ct[0x60] && ext_591b20(*(u8 **)(ct + 0x58)) == 0xc) {
      ct[0x60] = 1;
      send(ct, *(u32 *)(ct + 0x4c), *(u16 *)(ct + 0x76), 0);
    }
  } else if (act == 5) {
    if (!ct[0x61] && ext_591b20(*(u8 **)(ct + 0x58)) == 0x10) {
      ct[0x61] = 1;
      send(ct, *(u32 *)(ct + 0x50), *(u16 *)(ct + 0x76), 0);
    }
  } else if (act == 0xa) {
    if (vcall<u32>(*(u8 **)(ct + 0x58), 0x5d0) == 0x10) {
      u16 id = vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, (const char *)0x6a5660, 0,
                                                                (const char *)CARETAKER_C01A_CPP, 0xae);   // OpeningSewer
      send(ct, *(u32 *)(ct + 0x4c), id, 0);
    }
  }
}
PCREG(5b9f20, c01aFrameUpdate);
