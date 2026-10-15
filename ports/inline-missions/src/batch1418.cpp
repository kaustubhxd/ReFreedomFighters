// batch1418.cpp - missions thread, batch 1418: ZFFCareTaker_C02A::FrameUpdate.
#include "missions.h"

extern "C" void THISCALL ext_5bb960(u8 *ct, s32 idx, s32 line);   // ZFFCareTaker_C02A::PlayVoiceOver (batch 1417; hooked in the spec)
extern "C" void THISCALL ext_597fc0(u8 *osd, u32 hint, u32 flag);   // ZGameOSD::HintMessage
extern "C" void THISCALL ext_597fb0(u8 *osd);                       // ZGameOSD::HideHintMessage
extern "C" u32 THISCALL ext_591e50(u8 *hero, u32 type);             // ZFFHERO::GetItem(EFFItemType)
#define CARETAKER_C02A_CPP 0x6b2ab4u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline s32 now() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }
static inline u8 *byHandle(u32 h) { return vcall<u8 *, u32>(mgr(), 0x58, h); }
#define U32(o) (*(u32 *)(ct + (o)))
static inline u8 *osd(u8 *ct) { return *(u8 **)(*(u8 **)(ct + 0x64) + 0x852); }
static inline void send(u8 *ct, u32 target, u32 msg, u32 data) {   // event sender +0x44, slot 0x12c
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, target, msg, data);
}

// 0x5bb160 ZFFCareTaker_C02A::FrameUpdate().
//  - +0x295 (C02B_Flag not set at Init2): every object of list +0x84 gets "ActivateSoldier" once.
//  - Once the hero's OSD counts 2 or more recruits (+0x1fae) and +0x294 is clear: objects +0x74 / +0x70 switched,
//    +0x80 moved back up 100, HeroHasRecruits to +0x1dc and +0x1e4, and the OSD learns the sender (+0x22df).
//  - Due hint (+0x2a2, time +0x29e) and due voice-over (+0x2a7, time +0x2a8, idx +0x2ac, line +0x2b0).
//  - +0x373: when every recruit in list +0x2c6 passes its slot 0x438 check, hint 0x1e in 0.5 s, +0x297.
//  - Voice 5 (line 24) once due at +0x376 unless the vantage lesson ran; voice 9 (line 39) at +0x37b while on the
//    vantage point.
//  - Two frames after Init (+0x29a counts down) a hero already carrying C4 sends HeroHasC4 to +0x1e0.
//  - Hint 0x1f (vantage point) is hidden 5 s after it was due if the hero left the vantage point.
static void THISCALL c02aFrameUpdate(u8 *ct) {
  if (ct[0x295]) {
    u8 *list = ct + 0x84;
    if (list) {
      u32 it;
      vcall<void, u32 *>(list, 0x4c, &it);
      u32 h = vcall<u32, u32 *>(list, 0x5c, &it);
      while (it) {
        u16 id = vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, (const char *)0x6a55d0, 0,
                                                                  (const char *)CARETAKER_C02A_CPP, 0x12d);   // ActivateSoldier
        send(ct, h, id, 0);
        h = vcall<u32, u32 *>(list, 0x5c, &it);
      }
    }
    ct[0x295] = 0;
  }
  if (!ct[0x294] && *(s32 *)(osd(ct) + 0x1fae) >= 2) {
    if (U32(0x70))
      vcall<void>(byHandle(U32(0x70)), 0x2c);
    if (U32(0x74))
      vcall<void>(byHandle(U32(0x74)), 0x28);
    if (U32(0x80)) {
      u8 *o = byHandle(U32(0x80));
      float mat[9], pos[3];
      vcall<void, float *, float *>(o, 0x80, mat, pos);
      pos[1] = pos[1] + 100.0f;
      vcall<void, float *, float *>(o, 0x7c, mat, pos);
    }
    ct[0x294] = 1;
    send(ct, U32(0x1dc), *(u16 *)(ct + 0x54), 0);   // HeroHasRecruits
    u8 *od = osd(ct);
    *(u32 *)(od + 0x22df) = vcall<u32, u32>(mgr(), 0x4c, U32(0x44));
    send(ct, U32(0x1e4), *(u16 *)(ct + 0x54), 0);
  }
  if (ct[0x2a2] && now() > *(s32 *)(ct + 0x29e)) {
    ext_597fc0(osd(ct), U32(0x2a3), 0);
    ct[0x2a2] = 0;
  }
  if (ct[0x2a7] && now() > *(s32 *)(ct + 0x2a8)) {
    ext_5bb960(ct, (s32)U32(0x2ac), (s32)U32(0x2b0));
    ct[0x2a7] = 0;
  }
  if (ct[0x373]) {
    u8 *list = ct + 0x2c6;
    bool all = true;
    if (list) {
      u32 it;
      vcall<void, u32 *>(list, 0x4c, &it);
      u32 h = vcall<u32, u32 *>(list, 0x5c, &it);
      while (it) {
        if (!vcall<u8>(byHandle(h), 0x438)) {
          all = false;
          break;
        }
        h = vcall<u32, u32 *>(list, 0x5c, &it);
      }
    }
    if (all) {
      ct[0x297] = 1;
      U32(0x29e) = now() + 0x200;
      ct[0x2a2] = 1;
      U32(0x2a3) = 0x1e;
      ct[0x373] = 0;
    }
  }
  if (!ct[0x374] && ct[0x375] && now() > *(s32 *)(ct + 0x376)) {
    ext_5bb960(ct, 5, 0x18);
    ct[0x375] = 0;
  }
  s32 cd = *(s32 *)(ct + 0x29a);
  if (cd >= 0) {
    if (cd == 0 && ext_591e50(*(u8 **)(ct + 0x64), 0xe))
      send(ct, U32(0x1e0), *(u16 *)(ct + 0x60), 0);   // HeroHasC4
    (*(s32 *)(ct + 0x29a))--;
  }
  if (ct[0x37f] && ct[0x37a] && now() > *(s32 *)(ct + 0x37b)) {
    ext_5bb960(ct, 9, 0x27);
    ct[0x37f] = 0;
  }
  if (U32(0x2a3) == 0x1f && !ct[0x37a]) {
    float secs = (float)(s32)((u32)now() - U32(0x29e)) * 0.0009765625f;
    if (comiss_gt(secs, 5.0f)) {
      ext_597fb0(osd(ct));
      ct[0x298] = 0;
    }
  }
}
PCREG(5bb160, c02aFrameUpdate);

extern "C" void THISCALL ext_4ccf60(u8 *tab);   // REFTAB32::~REFTAB32()

// 0x57fad0 ZFFCareTaker_C02A destructor body (no GameCube name): the four REFTAB32 lists, then the ZEventBase part
// (+0x44/+0x30 cleared, vtable 0x686874, manager slot 0x34 unregisters the event).
extern "C" void THISCALL m_57fad0(u8 *ct) {
  ext_4ccf60(ct + 0x2c6);
  ext_4ccf60(ct + 0x1e8);
  ext_4ccf60(ct + 0x130);
  ext_4ccf60(ct + 0x84);
  U32(0x44) = 0;
  U32(0x30) = 0;
  U32(0) = 0x686874;
  vcall<void, u8 *>(mgr(), 0x34, ct);
}
PCREG(57fad0, m_57fad0);

// 0x5babb0 ZFFCareTaker_C02A deleting destructor (object size 0x380).
static u8 *THISCALL c02aDtor(u8 *ct, u32 flags) {
  m_57fad0(ct);
  return deletingDtor(ct, flags, 0x380);
}
PCREG(5babb0, c02aDtor);
