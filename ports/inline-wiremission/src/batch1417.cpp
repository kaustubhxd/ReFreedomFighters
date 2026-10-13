// batch1417.cpp - missions thread, batch 1417: ZFFCareTaker_C02A PlayVoiceOver and Command (Isabella's radio
// lessons in C02A: attack, fall back, vantage point, map, recruits, C4).
//
// C02A fields used here: +0x130 voice-over sound list (REFTAB32, slot 0x30 = handle by index), +0x294 bool,
// +0x296..+0x299 lesson-state bytes, +0x29e time of the next hint, +0x2a2 hint pending, +0x2a3 hint id,
// +0x2a7 pending OSD message, +0x2a8 its time, +0x2ac/+0x2b0 its parameters, +0x2b4 current voice sound,
// +0x2bc voice-over "already played" flags, +0x372..+0x375 bytes, +0x376/+0x37b times, +0x37a/+0x37f bytes.
#include "missions.h"

extern "C" void THISCALL ext_44c370(u8 *snd);   // ZSNDOBJ::Stop()
extern "C" void THISCALL ext_44c2b0(u8 *snd);   // ZSNDOBJ::Start()
extern "C" u8 *THISCALL ext_49df60(u8 *rc, const char *name, u8 *res);   // ResourceCollection::GetResource
extern "C" const char *THISCALL ext_49e0d0(u8 *res);                     // Resource::GetText()
extern "C" int ext_42ac56(char *dst, const char *fmt, ...);              // sprintf (CRT, in the exe)
extern "C" void THISCALL ext_59a5b0(u8 *osd, const char *title, const char *text, float secs);   // ZGameOSD::MessageDialog
extern "C" s32 THISCALL ext_59b310(u8 *lc, const char *name);            // ZFFLevelController::GetLevelVar
extern "C" u32 THISCALL ext_591e50(u8 *hero, u32 type);                  // ZFFHERO::GetItem(EFFItemType)
extern "C" void THISCALL ext_597fc0(u8 *osd, u32 hint, u32 flag);        // ZGameOSD::HintMessage
extern "C" void THISCALL ext_597fb0(u8 *osd);                            // ZGameOSD::HideHintMessage
#define CARETAKER_C02A_CPP 0x6b2ab4u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u32 now() { return *(u32 *)(G(u8 *, 0x70039c) + 0x40); }
#define U32(o) (*(u32 *)(ct + (o)))

// 0x5bb960 ZFFCareTaker_C02A::PlayVoiceOver(int idx, int line): once per idx. Stops the previous voice sound,
// starts sound idx of the +0x130 list (with its "SoundExtend" part), and shows the OSD message dialog titled
// Names/Isabella with the text C02A/LevelSpecific/C02A_<line, %2i>_Isabella for the sound's length. A missing
// sound is logged ("m_pIsabellaVoice...") and nothing is marked.
extern "C" void THISCALL m_5bb960(u8 *ct, s32 idx, s32 line) {
  if (ct[0x2bc + idx])
    return;
  float secs = 0.0f;
  if (U32(0x2b4))
    ext_44c370(*(u8 **)(ct + 0x2b4));
  u8 *list = ct + 0x130;
  void **mvt = *(void ***)mgr();
  u32 h = vcall<u32, s32>(list, 0x30, idx);
  u8 *snd = ((u8 * (THISCALL *)(u8 *, u32)) mvt[0x58 / 4])(mgr(), h);
  *(u8 **)(ct + 0x2b4) = snd;
  if (!snd) {
    LOGF(CARETAKER_C02A_CPP, 0x100, (const char *)0x6b2ba0);
    return;
  }
  ext_44c2b0(snd);
  u8 *ext = vcall<u8 *, const char *>(*(u8 **)(ct + 0x2b4), 0x104, (const char *)0x68fcb0);   // SoundExtend
  if (ext)
    vcall<void>(ext, 0x84);
  u8 *data = *(u8 **)(*(u8 **)(ct + 0x2b4) + 0x18);
  if (data)
    secs = *(float *)(data + 0x70);
  u8 res[0x200];
  u8 *r = ext_49df60(*(u8 **)(mgr() + 0xae4), (const char *)0x6b2be8, res);   // Names/Isabella
  const char *title = r ? ext_49e0d0(r) : (const char *)0x6852b8;          // "N/A"
  char key[0x64];
  ext_42ac56(key, (const char *)0x6b2bf8, line);
  r = ext_49df60(*(u8 **)(mgr() + 0xae4), key, res);
  const char *text = (const char *)0x6852b8;
  if (r)
    text = ext_49e0d0(r);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 hh = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x681320, &hh);
  u8 *hero = vcall<u8 *, u32>(mgr(), 0x58, hh);
  ext_59a5b0(*(u8 **)(hero + 0x852), title, text, secs);
  ct[0x2bc + idx] = 1;
}
PCREG(5bb960, m_5bb960);

static inline u8 *osd(u8 *ct) { return *(u8 **)(*(u8 **)(ct + 0x64) + 0x852); }

// 0x5bacc0 ZFFCareTaker_C02A::Command(unsigned short msg, void*). Returns 0.
//  EnterFuelStation (once, before C02A_FuelDepot is done): hint 0x1c with C4 (item 0xe) in hand, else 0x1b.
//  VoiceOverAttack: with +0x294, voice 0 (line 19), hint 0x15 due in 5 s, +0x296 set.
//  VoiceOverFallBack: voice 2 (line 21).  VoiceOverVantagePoint: once, voice 4 (line 23), hint 0x1f in 7 s, +0x298;
//  always +0x37a.  LeftVantagePoint: clears +0x37a.  EnterBriefingRoom: object +0x7c slot 0x2c.
//  Friendly_Form with +0x297: OSD message (3, 0x16) in 1 s, hint hidden, +0x375, +0x376 = now + 8 s.
//  HideAllHints: hint hidden.  VoiceOverMap: once (voice 7 unplayed), voice 7 (line 27), hint 0x21 in 3 s, map
//  lesson armed (+0x299).  OpenedMap with +0x299: hint hidden, voice 8 (line 28).
//  Then: with +0x296, Friendly_Attack or Friendly_Check gives OSD message (1, 0x14) in 1 s and +0x373; otherwise,
//  with +0x298, Friendly_Check gives (6, 0x19) in 1 s and +0x37f with +0x37b = now + 10 s.
static u32 THISCALL c02aCommand(u8 *ct, u32 msg, void *data) {
  (void)data;
  u16 m = (u16)msg;
#define ID(o) (*(u16 *)(ct + (o)))
  if (m == ID(0x48) && !ct[0x372] &&
      ext_59b310(*(u8 **)(G(u8 *, 0x7003b8) + 0x2c15), (const char *)0x6b041c) == 0) {   // C02A_FuelDepot
    u32 item = ext_591e50(*(u8 **)(ct + 0x64), 0xe);
    ext_597fc0(osd(ct), item ? 0x1c : 0x1b, 1);
    ct[0x372] = 1;
  } else if (m == ID(0x4c)) {
    if (ct[0x294]) {
      m_5bb960(ct, 0, 0x13);
      ct[0x296] = 1;
      U32(0x29e) = now() + 0x1400;
      ct[0x2a2] = 1;
      U32(0x2a3) = 0x15;
    }
  } else if (m == ID(0x4e)) {
    m_5bb960(ct, 2, 0x15);
  } else if (m == ID(0x50)) {
    if (!ct[0x374]) {
      m_5bb960(ct, 4, 0x17);
      ct[0x298] = 1;
      U32(0x29e) = now() + 0x1c00;
      ct[0x2a2] = 1;
      U32(0x2a3) = 0x1f;
      ct[0x374] = 1;
    }
    ct[0x37a] = 1;
  } else if (m == ID(0x62)) {
    ct[0x37a] = 0;
  } else if (m == ID(0x4a)) {
    if (U32(0x7c))
      vcall<void>(vcall<u8 *, u32>(mgr(), 0x58, U32(0x7c)), 0x2c);
  } else if (m == ID(0x58)) {
    if (ct[0x297]) {
      ct[0x2a7] = 1;
      U32(0x2a8) = now() + 0x400;
      U32(0x2ac) = 3;
      U32(0x2b0) = 0x16;
      ct[0x297] = 0;
      ext_597fb0(osd(ct));
      ct[0x2a2] = 0;
      ct[0x375] = 1;
      U32(0x376) = now() + 0x2000;
    }
  } else if (m == ID(0x5c)) {
    ext_597fb0(osd(ct));
    ct[0x2a2] = 0;
  } else if (m == ID(0x52)) {
    if (!ct[0x2c3]) {
      m_5bb960(ct, 7, 0x1b);
      U32(0x29e) = now() + 0xc00;
      ct[0x2a2] = 1;
      U32(0x2a3) = 0x21;
      U32(0x296) = 0x1000000;
      ct[0x373] = 0;
      ct[0x375] = 0;
    }
  } else if (m == ID(0x5e)) {
    if (ct[0x299]) {
      ext_597fb0(osd(ct));
      ct[0x299] = 0;
      ct[0x2a2] = 0;
      m_5bb960(ct, 8, 0x1c);
    }
  }
  if (ct[0x296]) {
    if (m == ID(0x56) || m == ID(0x5a)) {
      ct[0x2a7] = 1;
      U32(0x2a8) = now() + 0x400;
      U32(0x2ac) = 1;
      U32(0x2b0) = 0x14;
      ct[0x296] = 0;
      ext_597fb0(osd(ct));
      ct[0x2a2] = 0;
      ct[0x373] = 1;
    }
    return 0;
  }
  if (ct[0x298] && m == ID(0x5a)) {
    ct[0x2a7] = 1;
    U32(0x2a8) = now() + 0x400;
    U32(0x2ac) = 6;
    U32(0x2b0) = 0x19;
    ct[0x298] = 0;
    ext_597fb0(osd(ct));
    ct[0x2a2] = 0;
    U32(0x37b) = now() + 0x2800;
    ct[0x37f] = 1;
  }
  return 0;
#undef ID
}
PCREG(5bacc0, c02aCommand);
