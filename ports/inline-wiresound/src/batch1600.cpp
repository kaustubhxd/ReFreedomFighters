// batch1600.cpp - ZCharacterControl: the shout timers (soundtimers thread, 2026-10-11).
//
// ZCharacterControl is the scene's "Character_Controller" event object. It holds one timer pair per
// (shout enum, team): table at this+0x48, 98 enums x 3 teams, 8 bytes each:
//   rec(e, t) = this + 0x48 + 24*e + 8*t;  +0 = time of last play (seconds), +4 = minimum interval (seconds)
// this+0x978 = level start time (seconds) + 1, nobody speaks before it.
// this+0x97c/0x980/0x984/0x988 = one delayed on-screen shout (actor, enum, delay in ms, subtitle string).
// Engine time: ZSysInterface (*0x70039c) +0x40 is an int tick count, 1024 ticks per second; +0x48 is the frame
// time step in seconds (float).
// Confidence of names: GC names from decoders/gc_pc_namemap.tsv (high/medium, noted per function).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
// Re-read the tick counter every time the original does (the stores in between are floats into `this`).
static inline s32 ticks() { return *(volatile s32 *)(sys() + 0x40); }
static inline s32 cvtt(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

static const float kTickToSec = 0.0009765625f;  // 0x6785e4
static const float kSecToTick = 1024.0f;        // 0x678620

// 0x478a50 ZActor::GetActorSoundSet() [high]: the actor's voice sound set (SndRef), +0x5c2 on PC (GC +0x5d4).
static u32 THISCALL ZActor_GetActorSoundSet(void *self) { return AT(u32, self, 0x5c2); }
PCREG(478a50, ZActor_GetActorSoundSet);

// 0x478a70 ZActor::GetActorVoicePitch() [high]: +0x5c6 on PC (GC +0x5d8).
static u32 THISCALL ZActor_GetActorVoicePitch(void *self) { return AT(u32, self, 0x5c6); }
PCREG(478a70, ZActor_GetActorVoicePitch);

// 0x5dabe0 ZCharacterControl::Play_OnScreen_Delayed(ZFFActor*, uint enum, uint delay_ms, const char*) [low in the
// map; body agrees: stores exactly what FrameUpdate consumes]. Vtable +0x64 with 0x10 switches frame updates on
// (ZEventBase flag 0x10, inferred from FrameUpdate's +0x68(0x10, 0) when the delay runs out).
void THISCALL ZCharacterControl_Play_OnScreen_Delayed(void *self, void *actor, u32 e, u32 delay, const char *s) {
  AT(void *, self, 0x97c) = actor;
  AT(u32, self, 0x980) = e;
  AT(u32, self, 0x984) = delay;
  AT(const char *, self, 0x988) = s;
  vcall<void>(self, 0x64, (u32)0x10);
}
PCREG(5dabe0, ZCharacterControl_Play_OnScreen_Delayed);

// 0x5da950 ZCharacterControl::GetDefaultValues() [medium]: every interval 3 s and every timer "played 120 s ago",
// then the hard-coded exceptions. Offsets name (enum, team) by rec(e, t) above.
static void THISCALL ZCharacterControl_GetDefaultValues(void *self) {
  u8 *row = (u8 *)self + 0x48;
  for (int t = 0; t < 3; t++, row += 8) {
    u8 *p = row;
    for (int e = 0; e < 0x62; e++, p += 0x18) {
      AT(u32, p, 4) = 0x40400000;  // 3.0
      AT(float, p, 0) = (float)(s32)((u32)ticks() - 0x1e000u) * kTickToSec;
    }
  }
  AT(u32, self, 0x2ac) = 0x41ec0000;  // (25,1) interval 29.5, overwritten below
  AT(u32, self, 0x2d4) = 0x40000000;  // (27,0) Refuse 2
  AT(u32, self, 0x1cc) = 0x41400000;  // (16,0) Alarm 12
  AT(u32, self, 0x2bc) = 0x41880000;  // (26,0) Gun 17
  AT(u32, self, 0x27c) = 0x41f00000;  // (23,1) Generic 30
  float now0 = (float)ticks();
  AT(u32, self, 0x274) = 0x41f00000;  // (23,0) Generic 30
  AT(float, self, 0x278) = now0 * kTickToSec;  // (23,1) last = now
  float now1 = (float)ticks();
  AT(u32, self, 0x22c) = 0x41700000;  // (20,0) 15
  AT(u32, self, 0x234) = 0x41700000;  // (20,1) 15
  AT(u32, self, 0x2a4) = 0x41d80000;  // (25,0) Lostsight 27
  AT(u32, self, 0x2ac) = 0x41d80000;  // (25,1) Lostsight 27
  AT(u32, self, 0x134) = 0x40c00000;  // (9,2) Wounded 6
  AT(u32, self, 0x10c) = 0x3f000000;  // (8,0) Helped 0.5
  AT(u32, self, 0x11c) = 0x3f000000;  // (8,2) 0.5
  AT(u32, self, 0xac) = 0x3e99999a;   // (4,0) Inhale 0.3
  AT(float, self, 0x270) = now1 * kTickToSec;  // (23,0) last = now
  AT(u32, self, 0xbc) = 0x3e99999a;   // (4,2)
  AT(u32, self, 0xb4) = 0x3e99999a;   // (4,1)
  AT(u32, self, 0xc4) = 0x3e99999a;   // (5,0) Exhale 0.3
  AT(u32, self, 0xd4) = 0x3e99999a;   // (5,2)
  AT(u32, self, 0xcc) = 0x3e99999a;   // (5,1)
  AT(u32, self, 0x34c) = 0x3e99999a;  // (32,0) Accept 0.3
  s32 acc = ticks() + 0xc00;          // Accept last = now + 3 s
  AT(u32, self, 0x364) = 0x3e4ccccd;  // (33,0) Attack 0.2
  AT(u32, self, 0x37c) = 0x3e4ccccd;  // (34,0) Stay 0.2
  AT(u32, self, 0x3ac) = 0x3e4ccccd;  // (36,0) Follow 0.2
  AT(u32, self, 0x3c4) = 0x3e4ccccd;  // (37,0) Scout 0.2
  AT(u32, self, 0x35c) = 0x3f000000;  // (32,2) Accept 0.5
  AT(u32, self, 0x194) = 0x41600000;  // (13,2) Fence 14
  AT(u32, self, 0x1ac) = 0x41600000;  // (14,2) Near 14
  AT(u32, self, 0x1c4) = 0x41600000;  // (15,2) Sewer 14
  AT(u32, self, 0x2ec) = 0x41200000;  // (28,0) Obs 10
  AT(u32, self, 0x25c) = 0x42340000;  // (22,0) Helped 45
  AT(float, self, 0x348) = (float)acc * kTickToSec;
  float now2 = (float)ticks();
  AT(u32, self, 0x324) = 0x41d00000;  // (30,1) Order 26
  AT(u32, self, 0x334) = 0x41c00000;  // (31,0) Greeting 24
  AT(u32, self, 0x33c) = 0x41c00000;  // (31,1) Greeting 24
  AT(float, self, 0x258) = now2 * kTickToSec;            // (22,0) last = now
  AT(float, self, 0x330) = (float)ticks() * kTickToSec;  // (31,0) last = now
  AT(float, self, 0x338) = (float)ticks() * kTickToSec;  // (31,1) last = now
  s32 start = ticks() + 0x400;                           // level start + 1 s
  AT(u32, self, 0x97c) = 0;
  AT(u32, self, 0x980) = 0;
  AT(u32, self, 0x984) = 0;
  AT(u32, self, 0x988) = 0;
  AT(float, self, 0x978) = (float)start * kTickToSec;
}
PCREG(5da950, ZCharacterControl_GetDefaultValues);

// 0x5da750 ZCharacterControl::Load(ZLoadGame*) [medium]: clears event flag 0x40, resets the timers (nothing is
// read from the save), returns true.
static u8 THISCALL ZCharacterControl_Load(void *self, void *) {
  AT(u32, self, 4) &= 0xffffffbfu;
  ZCharacterControl_GetDefaultValues(self);
  return 1;
}
PCREG(5da750, ZCharacterControl_Load);

// 0x5da700 ZCharacterControl::Init() [medium]: registers itself under the name "Character_Controller"
// (sys+0x9b is the engine database object: +0x138 returns a name registry, +0x4c(ref, 0x10) resolves this object's
// reference, registry +0x60(name, ref) stores it; inferred from the string), then GetDefaultValues.
static void THISCALL ZCharacterControl_Init(void *self) {
  void *reg = vcall<void *>(AT(void *, sys(), 0x9b), 0x138);
  u32 ref = vcall<u32>(AT(void *, sys(), 0x9b), 0x4c, AT(u32, self, 0x44), (u32)0x10);
  vcall<void>(reg, 0x60, (const char *)0x6aecc8, ref);  // "Character_Controller"
  ZCharacterControl_GetDefaultValues(self);
}
PCREG(5da700, ZCharacterControl_Init);

// 0x5da860 ZCharacterControl::CanIPlay(uint enum, uchar team) [high]. All comparisons in ticks (seconds x 1024,
// truncated). Enum 35 (Cover) shares 34's (Stay) timer; a team above 2 counts as 1. A play restarts the (enum,
// team) timer and, unless the enum is 4 or 5 (Inhale, Exhale), that team's Generic (23) and Greeting (31) timers.
u8 THISCALL ZCharacterControl_CanIPlay(void *self, u32 e, u32 teamArg) {
  s32 now = ticks();
  if (now <= cvtt(AT(float, self, 0x978) * kSecToTick)) return 0;
  u32 ee = (e == 0x23) ? 0x22 : e;
  u8 tb = (u8)teamArg;
  u32 t = (tb <= 2) ? tb : 1;
  u32 idx = t + (ee + 3) * 3;  // rec(ee, t) is this + idx*8
  s32 since = now - cvtt(AT(float, self, idx * 8) * kSecToTick);
  if (since < cvtt(AT(float, self, (t + ee * 3) * 8 + 0x4c) * kSecToTick)) return 0;
  AT(float, self, idx * 8) = (float)now * kTickToSec;
  if (ee != 4 && ee != 5) {
    AT(float, self, t * 8 + 0x330) = (float)ticks() * kTickToSec;  // Greeting (31, t)
    AT(float, self, t * 8 + 0x270) = (float)ticks() * kTickToSec;  // Generic (23, t)
  }
  return 1;
}
PCREG(5da860, ZCharacterControl_CanIPlay);

// 0x5da760 ZCharacterControl::FrameUpdate() [high]: counts the delayed on-screen shout down (ms, frame step x
// 1000); when it reaches 0, frame updates are switched off (+0x68(0x10, 0)) and the actor gets
// PlaySound_Enum_On_Screen(enum, string, false) (ZFFActor vtable +0x6ec, slot 443).
static void THISCALL ZCharacterControl_FrameUpdate(void *self) {
  u32 left = AT(u32, self, 0x984);
  if (left) {
    float f = (float)(double)left - AT(float, sys(), 0x48) * 1000.0f;  // 1000.0 at 0x67d164
    AT(u32, self, 0x984) = crt_ftoll_lo(f);
    return;
  }
  vcall<void>(self, 0x68, (u32)0x10, (u32)0);
  void *actor = AT(void *, self, 0x97c);
  if (actor) vcall<void>(actor, 0x6ec, (u32)AT(u8, self, 0x980), AT(u32, self, 0x988), (u32)0);
}
PCREG(5da760, ZCharacterControl_FrameUpdate);
