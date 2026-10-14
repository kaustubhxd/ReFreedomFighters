// batch1505.cpp - recruits thread, batch 1505: ZGameOSD::CommandAllRecruits / CommandOneRecruit, the layer between
// the order handlers (batch 1501) and ZGameOSD::CommandRecruit (one actor).
#include "ff.h"

extern "C" void THISCALL ext_597050(u8 *osd, u32 cmd, u32 id, u32 all);   // ZGameOSD::CommandRecruit
extern "C" u8 THISCALL ext_597a70(u8 *osd, u32 id);                       // ZGameOSD::IsRecruited
extern "C" void THISCALL ext_597e00(u8 *osd, u32 id);                     // ZGameOSD::RemoveRecruit
extern "C" s32 THISCALL ext_597680(u8 *osd, s32 start, s32 step);         // ZGameOSD::FindCurrentRecruit
extern "C" s32 STDCALL ext_4df9d0(float x);                               // round(float)

typedef float(THISCALL *vcallRandF)(void *self, const char *file, u32 line);

#define IDS(self) ((u32 *)((self) + 0x1dae))
#define NREC(self) (*(s32 *)((self) + 0x1fae))
#define SEL(self) (*(s32 *)((self) + 0x1fb2))
// The "selected" list: ids at +0xe6, count +0x2e6 (+0x2ea is cleared with it). When it is not empty, orders go to
// the selected recruits only.
#define SELIDS(self) ((u32 *)((self) + 0xe6))
#define NSEL(self) (*(s32 *)((self) + 0x2e6))

// Order the selected recruits; with `dismiss` each one also leaves the recruit list (in multiplayer through
// IsRecruited, which checks every same-team player's list).
static void orderSelected(u8 *self, u32 cmd, u32 dismiss, u32 all) {
  for (s32 i = 0; i < NSEL(self); ++i) {
    u32 *pid = &SELIDS(self)[i];
    ext_597050(self, cmd, *pid, all);
    if (!(u8)dismiss)
      continue;
    u32 id = *pid;
    if (*(u32 *)(G(u8 *, 0x70039c) + 0x1b5d) == 1) {
      if (!ext_597a70(self, id))
        continue;
    } else {
      s32 n = NREC(self), k = 0;
      if (n <= 0)
        continue;
      while (IDS(self)[k] != id)
        if (++k >= n)
          break;
      if (k >= n)
        continue;
    }
    ext_597e00(self, *pid);
  }
}

// 0x596d70 ZGameOSD::CommandAllRecruits(RECRUIT_COMMAND cmd, bool dismiss), thiscall, ret 8.
// Selected recruits if any (then the selection is cleared when dismissing); otherwise every recruit, starting with
// a random one (index round(r * (count - 1)), r = engine random from ZGameOSD.cpp line 0x2b0), all with all = 1;
// dismissing then empties the recruit list.
static void THISCALL commandAllRecruits(u8 *self, u32 cmd, u32 dismiss) {
  if (NSEL(self) != 0) {
    if (NSEL(self) > 0)
      orderSelected(self, cmd, dismiss, 1);
    if ((u8)dismiss) {
      NSEL(self) = 0;
      *(u32 *)(self + 0x2ea) = 0;
    }
    return;
  }
  if (NREC(self) == 0)
    return;
  u8 *sys = G(u8 *, 0x70039c);
  float r = ((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6ad250, 0x2b0);
  float m = (float)(NREC(self) - 1);
  // x87 fmul then fstp to float, as the original: the x87 status flags it sets (inexact) are read later by the CRT
  // float-to-int helper inside round(), so the multiply must happen on the x87 unit.
  float x;
  asm("fmuls %2" : "=t"(x) : "0"(r), "m"(m));
  s32 first = ext_4df9d0(x);
  ext_597050(self, cmd, IDS(self)[first], 1);
  for (u32 i = 0; i < (u32)NREC(self); ++i)
    if ((u32)first != i)
      ext_597050(self, cmd, IDS(self)[i], 1);
  if ((u8)dismiss) {
    NREC(self) = 0;
    SEL(self) = 0;
  }
}
PCREG(596d70, commandAllRecruits);

// 0x596ef0 ZGameOSD::CommandOneRecruit(RECRUIT_COMMAND cmd, bool dismiss), thiscall, ret 8.
// Selected recruits if any (all = 0, the selection is kept). Otherwise the current recruit (FindCurrentRecruit from
// the selection index +0x1fb2, step 1) gets the order and becomes the selection; dismissing removes it from the list
// (last one moves into its place), else the selection moves on by one, wrapping to 0 at the end. For cmd 5 (form)
// the selection index only moves on.
static void THISCALL commandOneRecruit(u8 *self, u32 cmd, u32 dismiss) {
  if (NSEL(self) != 0) {
    if (NSEL(self) > 0)
      orderSelected(self, cmd, dismiss, 0);
    return;
  }
  if (NREC(self) == 0)
    return;
  s32 idx = ext_597680(self, SEL(self), 1);
  if (cmd == 5) {
    if (idx == -1)
      return;
    ext_597050(self, 5, IDS(self)[idx], 0);
    ++SEL(self);
  } else {
    if (idx != -1) {
      ext_597050(self, cmd, IDS(self)[idx], 0);
      SEL(self) = idx;
    }
    if ((u8)dismiss) {
      --NREC(self);
      IDS(self)[SEL(self)] = IDS(self)[NREC(self)];
      IDS(self)[NREC(self)] = 0;
    } else {
      ++SEL(self);
    }
  }
  if (SEL(self) == NREC(self))
    SEL(self) = 0;
}
PCREG(596ef0, commandOneRecruit);
