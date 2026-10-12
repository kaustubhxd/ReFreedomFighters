// batch272.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch272"): the ZActor constructor
// (every soldier, civilian and the hero). Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_471b50(u8 *self, u32 info, u32 name, u32 parent);  // ZLNKWHANDS ctor (audit/inline-ladder; hooked)
extern "C" u8 *THISCALL ext_4cbeb0(u8 *s);                                      // MYSTR::MYSTR (GUESS: hooked)
extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);                    // operator new (unclaimed-64)
extern "C" u8 *THISCALL ext_4ccbe0(u8 *p, u32 n, u32 grow);                     // table ctor (inline-batch45)
extern "C" u8 *THISCALL ext_4d8330(u8 *p, u32 a, u32 b, u32 c);                 // debug variable ctor (GUESS: hooked)
extern "C" void *__attribute__((cdecl)) ext_634d10(void *d, int v, u32 n);      // memset (CRT)

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))
#define D32(o) (*(u32 *)(self + (o)))

static u16 reg(u32 name, u32 line) { return (u16)vcall<u32>(DB, 0x114, name, 0u, 0x68a7c4u, line); }

// 0x476f50 ZActor::ZActor(ZGEOMCLASSINFO *, const char *, ZBaseGeom *) ret 0xc, returns this. ZLNKWHANDS base ctor
// 0x471b50; vtable 0x68a124; name string +0x412 (MYSTR); +0x5ce takes the global actor counter 0x6ffa4c (which wraps at
// 8); clears or sets about 70 fields (+0x624 = 30.0, +0x674 = 1.0, +0x678 = 100.0, +0x688 = 1.0, +0x75d = +0x765 = 10.0,
// +0x70e = -1.0); memset +0x4b2 (0x100 bytes); a (8, 0) table into +0x73e; ten actor messages into globals 0x6ffa20..
// 0x6ffa44 (actor.cpp 0x68a7c4 lines 0x138..0x141) and one into 0x6ffa40 (line 0x146); two debug variables (0x108 bytes,
// 0x4d8330) into +0x5ba and +0x5b6, each handed to rm vt 0x1a4; appended to the actor list [0x7003b8] (+4 count, +8
// entries); global 0x6ffa10 = 0.
u8 *THISCALL actorCtor_476f50(u8 *self, u32 info, u32 name, u32 parent) {
  ext_471b50(self, info, name, parent);
  *(u32 *)self = 0x68a124u;
  ext_4cbeb0(self + 0x412);
  u32 g = *(u32 *)0x6ffa4cu;
  D32(0x620) = 0;
  D32(0x5ce) = g;
  g++;
  self[0x5d2] = 0;
  D32(0x624) = 0x41f00000u;  // 30.0f
  if (g == 8) g = 0;
  D32(0x648) = 0;
  *(u32 *)0x6ffa4cu = g;
  D32(0x5be) = 0;
  D32(0x640) = 0;
  D32(0x644) = 0;
  D32(0x66c) = 0;
  D32(0x670) = 0;
  D32(0x674) = 0x3f800000u;
  D32(0x4ae) = 0;
  self[0x690] = 0;
  D32(0x691) = 0;
  D32(0x695) = 0;
  self[0x699] = 0;
  self[0x72f] = 0;
  self[0x726] = 0;
  D32(0x6b2) = 0;
  D32(0x6b6) = 0;
  D32(0x6ba) = 0;
  self[0x6be] = 0;
  D32(0x6bf) = 0;
  *(u16 *)(self + 0x6c3) = 0;
  self[0x6c5] = 0;
  D32(0x68c) = 0;
  D32(0x678) = 0x42c80000u;  // 100.0f
  D32(0x688) = 0x3f800000u;
  D32(0x49a) = 0;
  D32(0x49e) = 0;
  D32(0x4a2) = 0;
  D32(0x4a6) = 0;
  D32(0x4aa) = 0;
  ext_634d10(self + 0x4b2, 0, 0x100);
  self[0x6fe] = 1;
  D32(0x6ff) = 1;
  *(u16 *)(self + 0x704) = 0;
  self[0x754] = 0;
  D32(0x755) = 0;
  D32(0x759) = 0;
  D32(0x769) = 0;
  D32(0x75d) = 0x41200000u;  // 10.0f
  D32(0x765) = 0x41200000u;
  D32(0x76d) = 0;
  D32(0x64c) = 0;
  u8 *p = ext_41e290(0x1c);
  *(u8 **)(self + 0x73e) = p ? ext_4ccbe0(p, 8, 0) : 0;
  D32(0x658) = 0;
  D32(0x650) = 0;
  D32(0x70e) = 0xbf800000u;  // -1.0f
  D32(0x65c) = 1;
  D32(0x736) = 0;
  D32(0x5c2) = 0;
  D32(0x5c6) = 0;
  D32(0x77b) = 0;
  D32(0x5ca) = 0;
  static const u32 kMsgs[9][2] = {{0x68a87cu, 0x6ffa20u}, {0x68a88cu, 0x6ffa1cu}, {0x68a89cu, 0x6ffa24u},
                                  {0x68a8a8u, 0x6ffa28u}, {0x68a8b8u, 0x6ffa2cu}, {0x68a8c8u, 0x6ffa30u},
                                  {0x68a8e0u, 0x6ffa34u}, {0x68a8ecu, 0x6ffa38u}, {0x68a8fcu, 0x6ffa3cu}};
  for (u32 i = 0; i < 9; i++) *(u16 *)kMsgs[i][1] = reg(kMsgs[i][0], 0x138u + i);
  u16 w = reg(0x68a904u, 0x141u);
  p = ext_41e290(0x108);
  *(u16 *)0x6ffa44u = w;
  u8 *v = p ? ext_4d8330(p, 0x68a948u, 0x68a910u, 0x6ffa48u) : 0;
  *(u8 **)(self + 0x5ba) = v;
  vcall<void>(RM, 0x1a4, (u32)v);
  p = ext_41e290(0x108);
  v = p ? ext_4d8330(p, 0x68a984u, 0x68a958u, 0x6ffa18u) : 0;
  *(u8 **)(self + 0x5b6) = v;
  vcall<void>(RM, 0x1a4, (u32)v);
  *(u16 *)0x6ffa40u = reg(0x68a994u, 0x146u);
  D32(0x777) = 0;
  D32(0x772) = 0;
  D32(0x496) = 1;
  self[0x776] = 1;
  self[0x74e] = 0;
  self[0x771] = 0;
  D32(0x72b) = 0;
  u8 *lst = *(u8 **)0x7003b8u;
  *(u8 **)(lst + 8 + *(u32 *)(lst + 4) * 4) = self;
  *(u32 *)(lst + 4) += 1;
  D32(0x6ce) = 0;
  *(u32 *)0x6ffa10u = 0;
  return self;
}
PCREG(476f50, actorCtor_476f50);
#undef D32
#undef DB
#undef RM
