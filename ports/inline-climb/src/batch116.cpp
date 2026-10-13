// batch116.cpp - ZGameOSD::SetHelpMessage(text, flag) (climb thread, batch 116). Called by ZFFHERO::DisplayUseAction
// (batch 115). Names from the GC map (high): ZGameOSD::SetHelpMessage(const char*, bool).
#include "ff.h"

extern "C" void THISCALL ext_5a84a0(void *hudSub, const char *text);  // ZOnScreenDisplay::HelpMessage (one arg, ret 4)
extern "C" void THISCALL ext_59a5e0(void *osd, u32 sound);            // ZGameOSD::PlaySound (one arg, ret 4)

static inline s32 ticks() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }

// The help message goes to the on-screen display object (+0x1d0f, when present). When the flag byte is set, a sound plays
// at most once per 0x600 ticks (about 1.5 s; the last time is kept as a float in seconds at +0xe2, and 1024 ticks make a
// second, 0x678620 and 0x6785e4 read as 1024 and 1/1024).
static void THISCALL setHelpMessage(u8 *self, const char *text, u32 flag) {
  void *hud = *(void **)(self + 0x1d0f);
  if (!hud)
    return;
  ext_5a84a0(hud, text);
  if ((u8)flag == 0)
    return;
  float last = *(float *)(self + 0xe2) * 1024.0f;
  s32 lastTicks = (s32)last;
  s32 now = ticks();
  if (now - lastTicks <= 0x600)
    return;
  ext_59a5e0(self, 1);
  *(float *)(self + 0xe2) = (float)now * 0.0009765625f;
}
PCREG(59a860, setHelpMessage);
