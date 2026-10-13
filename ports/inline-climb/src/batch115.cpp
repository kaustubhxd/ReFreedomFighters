// batch115.cpp - ZFFHERO::DisplayUseAction (climb thread, batch 115). Shows the help text for the hero's current use
// action. Names from the GC map (high): ZFFHERO::DisplayUseAction(); the action names are the strings the table uses.
#include "ff.h"

extern "C" void THISCALL ext_59a860(void *osd, const char *text, u32 changed);  // ZGameOSD::SetHelpMessage(text, bool)

static inline u8 *sys() { return G(u8 *, 0x70039c); }

// Action strings in table order (index 1..16). Index 17 reuses the stored text at +0x9df, index 0 returns at once,
// anything above 17 shows "Henning Fix This" (0x6ad0d8).
static const char *const kNames[17] = {
    (const char *)0x6a73b4,  // 1 PickUp
    (const char *)0x6ad018,  // 2 RaiseFlag
    (const char *)0x6ad024,  // 3 CancelRaiseFlag
    (const char *)0x6ad034,  // 4 UseMachineGun
    (const char *)0x6ad044,  // 5 LeaveMachineGun
    (const char *)0x6ad054,  // 6 Recruit
    (const char *)0x6ad05c,  // 7 Talk
    (const char *)0x6ad064,  // 8 OpenGate
    (const char *)0x6ad070,  // 9 CancelOpenGate
    (const char *)0x6ad080,  // 10 OpenSewer
    (const char *)0x6ad08c,  // 11 CancelOpenSewer
    (const char *)0x6ad09c,  // 12 AccessSewer
    (const char *)0x6ad0a8,  // 13 PlaceC4
    (const char *)0x6ad0b0,  // 14 CancelPlaceC4
    (const char *)0x6ad0c0,  // 15 GiveHealth
    (const char *)0x6ad0cc,  // 16 ClimbLadder
    (const char *)0,         // 17 (stored text)
};

static void THISCALL displayUseAction(u8 *self) {
  u32 cur = *(u32 *)(self + 0x9d7);
  u32 changed = cur != *(u32 *)(self + 0x9d3);
  *(u32 *)(self + 0x9d3) = cur;
  *(u32 *)(self + 0x9d7) = 0;
  *(u32 *)(self + 0x9db) = 0x7e967699u;   // GUESS: "no priority" marker (a large float), read by SetUseAction
  if (cur == 0)
    return;
  const char *text;
  if (cur > 0x11) {
    text = (const char *)0x6ad0d8;   // "Henning Fix This"
  } else if (cur == 0x11) {
    text = *(const char **)(self + 0x9df);
    if (!text)
      return;
  } else {
    u8 *eng = *(u8 **)(sys() + 0x9b);
    void *acts = *(void **)(eng + 0xae4);
    text = vcall<const char *>(acts, 0, (const char *)0x6a73bc /* "Menu/UseActions" */, kNames[cur - 1]);
    if (!text)
      return;
  }
  ext_59a860(*(void **)(self + 0x852), text, changed);
  *(u32 *)(self + 0x9df) = 0;
}
PCREG(591190, displayUseAction);
