// batch1604.cpp - ZFFActor::InitSounds: the shout table (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
extern "C" void *ext_41e290(u32 size);              // __builtin_new
extern "C" void *ext_634d10(void *d, int v, u32 n);  // memset

// FindInSoundSet(set, pattern) through the sound DLL, re-read from sys every time (as the original does).
static inline u32 find(u32 set, u32 str) {
  return vcall<u32>(AT(void *, sys(), 0x1a9f), 0x60, set, (const char *)str);
}
static inline void put(void *self, u32 idx, u32 v) { AT(u32 *, self, 0x936)[idx] = v; }

// 0x5a04f0 ZFFActor::InitSounds() [high]. Allocates the 38-entry shout table (+0x936, zeroed) and, when there is a
// sound DLL, registers the actor with it (DLL vtable +0x80(actor); meaning not traced) and, when the actor has a
// sound set, fills the table with FindInSoundSet(set, "*Name*") in this order (enum: name):
//   0 Nothing, 1 Pain, 2 Die, 3 Punch, 4 Inhale, 5 Exhale, 12 Panic, 8 Helped, 9 Wounded, (20 = 0), 6 Vehicle,
//   16 Alarm, 18 Combat, 26 Gun, 28 Obs, 21 Excl, 29 Obs, then 29 = Grenade if the set has one (looked up twice),
//   10 ComeWithMe, 11 SpecHints, 13 Fence, 14 Near, 15 Sewer, 17 Attack, 19 Control, 27 Refuse, 7 Relived,
//   25 Lostsight, 24 HeroDead, 22 Helped, 23 Generic, 30 Order, 31 Greeting, 32 Accept, 33 Attack, 34 Stay, 35 Cover,
//   36 Follow, 37 Scout.
// and sets the sound priority class +0x143 to 3 for team 0, else 2. Then finds the scene's Character_Controller:
// name registry (database +0x138) lookup "Character_Controller" (+0x88(name, &ref)); found -> database +0x58(ref)
// gives the geom, its +0x100("CharacterControl") the event object, stored at +0x93a; not found -> the warning
// "WARNING: No CharacterController" (ZFFActor.cpp line 0x9b0) and +0x93a is left as it was. Finally clears
// +0x93e (expanded) , sets +0x93f = 1 and clears +0x941 / +0x945.
static void THISCALL ZFFActor_InitSounds(void *self) {
  u32 set = vcall<u32>(self, 0x680);
  void *tab = ext_41e290(0x98);
  AT(void *, self, 0x936) = tab;
  ext_634d10(tab, 0, 0x98);
  void *dll = AT(void *, sys(), 0x1a9f);
  if (dll) {
    vcall<void>(dll, 0x80, self);
    if (set) {
      AT(u8, self, 0x143) = (u8)((AT(u32, AT(u8 *, self, 0x54), 4) == 0) + 2);
      put(self, 0, find(set, 0x6aeb5c));   // *Nothing*
      put(self, 1, find(set, 0x6aeb68));   // *Pain*
      put(self, 2, find(set, 0x6aeb70));   // *Die*
      put(self, 3, find(set, 0x6aeb78));   // *Punch*
      put(self, 4, find(set, 0x6aeb80));   // *Inhale*
      put(self, 5, find(set, 0x6aeb8c));   // *Exhale*
      put(self, 12, find(set, 0x6aeb98));  // *Panic*
      put(self, 8, find(set, 0x6aeba0));   // *Helped*
      put(self, 9, find(set, 0x6aebac));   // *Wounded*
      put(self, 20, 0);
      put(self, 6, find(set, 0x6aebb8));   // *Vehicle*
      put(self, 16, find(set, 0x6aebc4));  // *Alarm*
      put(self, 18, find(set, 0x6aebcc));  // *Combat*
      put(self, 26, find(set, 0x6aebd8));  // *Gun*
      put(self, 28, find(set, 0x6aebe0));  // *Obs*
      put(self, 21, find(set, 0x6aebe8));  // *Excl*
      put(self, 29, find(set, 0x6aebe0));  // *Obs*
      if (find(set, 0x6aebf0)) put(self, 29, find(set, 0x6aebf0));  // *Grenade*
      put(self, 10, find(set, 0x6aebfc));  // *ComeWithMe*
      put(self, 11, find(set, 0x6aec0c));  // *SpecHints*
      put(self, 13, find(set, 0x6aec18));  // *Fence*
      put(self, 14, find(set, 0x6aec20));  // *Near*
      put(self, 15, find(set, 0x6aec28));  // *Sewer*
      put(self, 17, find(set, 0x6aec30));  // *Attack*
      put(self, 19, find(set, 0x6aec3c));  // *Control*
      put(self, 27, find(set, 0x6aec48));  // *Refuse*
      put(self, 7, find(set, 0x6aec54));   // *Relived*
      put(self, 25, find(set, 0x6aec60));  // *Lostsight*
      put(self, 24, find(set, 0x6aec6c));  // *HeroDead*
      put(self, 22, find(set, 0x6aeba0));  // *Helped*
      put(self, 23, find(set, 0x6aec78));  // *Generic*
      put(self, 30, find(set, 0x6aec84));  // *Order*
      put(self, 31, find(set, 0x6aec8c));  // *Greeting*
      put(self, 32, find(set, 0x6aec98));  // *Accept*
      put(self, 33, find(set, 0x6aec30));  // *Attack*
      put(self, 34, find(set, 0x6aeca4));  // *Stay*
      put(self, 35, find(set, 0x6aecac));  // *Cover*
      put(self, 36, find(set, 0x6aecb4));  // *Follow*
      put(self, 37, find(set, 0x6aecc0));  // *Scout*
    }
  }
  void *reg = vcall<void *>(AT(void *, sys(), 0x9b), 0x138);
  u32 ref = 0;
  vcall<void>(reg, 0x88, (const char *)0x6aecc8, &ref);  // "Character_Controller"
  if (ref) {
    void *geom = vcall<void *>(AT(void *, sys(), 0x9b), 0x58, ref);
    AT(void *, self, 0x93a) = vcall<void *>(geom, 0x100, (const char *)0x6aece0);  // "CharacterControl"
  } else {
    void *log = G(void *, 0x700390);
    void *ch = vcall<void *>(log, 0x20, (const char *)0x6ae6a0, (u32)0x9b0);  // ZFFActor.cpp, line 0x9b0
    typedef void (*Print)(void *, const char *);
    (*(Print *)(*(u8 **)ch + 0x2c))(ch, (const char *)0x6aecf4);  // "WARNING: No CharacterController"
  }
  AT(u16, self, 0x93e) = 0x100;
  AT(u32, self, 0x945) = 0;
  AT(u32, self, 0x941) = 0;
}
PCREG(5a04f0, ZFFActor_InitSounds);
