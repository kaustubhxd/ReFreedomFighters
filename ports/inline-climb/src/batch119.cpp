// batch119.cpp - ZOnScreenDisplay::HelpMessage and the CMessageBasics setters it uses (climb thread, batch 119).
// Names from the GC map where it has them (HelpMessage: GC high; SetAlpha, SetText: GC medium; the flag setter: guess).
#include "ff.h"

extern "C" void THISCALL ext_5abf00(void *msg, const char *text);   // CMessageBasics::ReformatText (not lifted)
extern "C" void THISCALL ext_5ac140(void *msg, const char *text);   // CMessageBasics::ReformatTextNoSymbols (not lifted)
extern "C" void THISCALL ext_5ac5b0(void *msg, float a);             // SetAlpha (batch 119)
extern "C" void THISCALL ext_5acac0(void *msg, u32 v);              // flag setter (batch 119)
extern "C" void THISCALL ext_5ac940(void *msg, const char *text);    // SetText (batch 119)

// 0x5ac5b0, CMessageBasics::SetAlpha(float) (GC map medium). thiscall, ret 4: +0x7a = the float.
static void THISCALL messageSetAlpha(u8 *self, float a) { *(float *)(self + 0x7a) = a; }
PCREG(5ac5b0, messageSetAlpha);

// 0x5acac0, a byte flag setter (GUESS: name unknown; +8 = the byte argument, as bool). thiscall, ret 4.
static void THISCALL messageSetFlag(u8 *self, u32 v) { self[8] = (u8)v; }
PCREG(5acac0, messageSetFlag);

// 0x5ac940, CMessageBasics::SetText(const char*) (GC map medium). thiscall, ret 4. Reformats the text with the symbols
// version when +0x6a is set, else with the no-symbols version (both are tail jumps; the callee pops the argument).
static void THISCALL messageSetText(u8 *self, const char *text) {
  if (*(u32 *)(self + 0x6a) == 0)   // a dword compare in the exe (cmp dword ptr [ecx+0x6a], 0)
    ext_5ac140(self, text);
  else
    ext_5abf00(self, text);
}
PCREG(5ac940, messageSetText);

// 0x5a84a0, ZOnScreenDisplay::HelpMessage(const char*) (GC map high). thiscall, ret 4. Shows the help text on the message
// object at +0x630 (SetAlpha 1.0, flag 1, SetText). Nothing when the text is null. When the text is the same pointer as the
// last one shown (+0x650), only the on-screen time (+0x374) is reset to 1.0.
static void THISCALL helpMessage(u8 *self, const char *text) {
  if (!text)
    return;
  if (*(const char **)(self + 0x650) != text) {
    u8 *msg = *(u8 **)(self + 0x630);
    ext_5ac5b0(msg, 1.0f);
    msg = *(u8 **)(self + 0x630);
    ext_5acac0(msg, 1u);
    msg = *(u8 **)(self + 0x630);
    ext_5ac940(msg, text);
    *(const char **)(self + 0x650) = text;
  }
  *(u32 *)(self + 0x374) = 0x3f800000u;
}
PCREG(5a84a0, helpMessage);
