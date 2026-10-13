// batch275.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch275"): the ZFFHERO
// constructor. Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_480a40(u8 *self, u32 info, u32 name, u32 parent);  // ZPlayer::ZPlayer (GUESS: hooked)
extern "C" u8 *THISCALL ext_4cbeb0(u8 *s);                                      // MYSTR::MYSTR (GUESS: hooked)
extern "C" u8 *THISCALL ext_5aede0(u8 *p);                                      // ZFFInventoryInfoList ctor (audit/inline-inventory)
extern "C" u8 *THISCALL ext_5afc10(u8 *p);                                      // ZFFInventoryController ctor (audit/inline-inventory)
extern "C" void THISCALL ext_475820(u8 *self, u32 bone, float mult);            // SetDamageMultForBone (inline-damage)
extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 size);                    // operator new (unclaimed-64)
extern "C" u8 *THISCALL ext_4d8330(u8 *p, u32 a, u32 b, u32 c);                 // debug variable ctor (GUESS: hooked)

typedef int(__attribute__((cdecl)) * atoi_t)(const char *);

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))
#define D32(o) (*(u32 *)(self + (o)))

// {message name, word field}; lines 0x60 + index in ffhero.cpp (0x6ac6d0).
static const u32 kHeroMsgs[31][2] = {
    {0x69c2d0u, 0x7b0}, {0x69c2e0u, 0x7b2}, {0x690c00u, 0x7b4}, {0x692ae4u, 0x7b6}, {0x69eaacu, 0x7b8},
    {0x6ac700u, 0x7ba}, {0x6ac70cu, 0x7bc}, {0x6ac71cu, 0x7be}, {0x6ac728u, 0x7c2}, {0x6ac740u, 0x7c0},
    {0x6ac758u, 0x7c4}, {0x6ac770u, 0x674}, {0x68f7e8u, 0x7c6}, {0x6ac784u, 0x7c8}, {0x6ac790u, 0x7ca},
    {0x6ac79cu, 0x7cc}, {0x68f84cu, 0x7ce}, {0x6ac7a8u, 0x7d0}, {0x688c28u, 0x7d2}, {0x6ac7bcu, 0x7d4},
    {0x6ac7d4u, 0x7d6}, {0x6ac7ecu, 0x7d8}, {0x6ac7f8u, 0x7da}, {0x6a55e0u, 0x7dc}, {0x6a5414u, 0x7de},
    {0x6a5428u, 0x7e0}, {0x6ac810u, 0x7e2}, {0x6ac824u, 0x7e4}, {0x6ac834u, 0x7e6}, {0x6a56a4u, 0x7e8},
    {0x6a56b4u, 0x7ea}};

// 0x58ab50 ZFFHERO::ZFFHERO(ZGEOMCLASSINFO *, const char *, ZBaseGeom *) ret 0xc, returns this. ZPlayer base ctor
// 0x480a40; vtable 0x6ac060; MYSTR at +0x698; inventory info list (+0x95b) and controller (+0x9af) ctors; 31 hero
// messages (lines 0x60..0x7e); hero defaults (+0x7f3 = 100, +0x7fb = +0x7ff = 300.0, +0x803 = 50.0, +0x807 = 20.0,
// +0x431 = -0.8, +0x829 = 0.1, +0x439 = +0x441 = 45.0, +0x43d = +0x451 = 90.0, +0x669 = 0x10000, +0x7f2 = 1, word
// +0x9f4 = 0x100); damage multiplier 1.0 for bones 1, 2, 3 (0x475820); a debug variable "Show_Follow" (new 0x108,
// 0x4d8330 over +0xee8) into +0xee4 and rm vt 0x1a4; config "blood" (rm vt 0x5c) sets +0x653 to value != "0" (1 when
// missing) and "followsneak" sets +0xee3 to atoi(value) != 0 (1 when missing); then about 40 more fields cleared.
u8 *THISCALL heroCtor_58ab50(u8 *self, u32 info, u32 name, u32 parent) {
  ext_480a40(self, info, name, parent);
  *(u32 *)self = 0x6ac060u;
  D32(0x690) = 0;
  D32(0x694) = 0;
  ext_4cbeb0(self + 0x698);
  D32(0x93a) = 0;
  D32(0x94f) = 0;
  ext_5aede0(self + 0x95b);
  ext_5afc10(self + 0x9af);
  D32(0xa16) = 0;
  D32(0xd4a) = 0;
  D32(0x80f) = 0;
  D32(0x42d) = 0;
  D32(0x431) = 0xbf4ccccdu;  // -0.8f
  D32(0x435) = 0;
  for (u32 i = 0; i < 31; i++)
    *(u16 *)(self + kHeroMsgs[i][1]) = (u16)vcall<u32>(DB, 0x114, kHeroMsgs[i][0], 0u, 0x6ac6d0u, 0x60u + i);
  *(u16 *)(self + 0x7f0) = 0;
  D32(0x694) = 0;
  D32(0x7ec) = 0;
  D32(0x669) = 0x10000;
  self[0x7f2] = 1;
  self[0x67f] = 0;
  D32(0x9f6) = 0;
  D32(0x83e) = 0;
  D32(0x7f3) = 100;
  D32(0x7f7) = 0;
  D32(0x7fb) = 0x43960000u;  // 300.0f
  D32(0x7ff) = 0x43960000u;
  D32(0x803) = 0x42480000u;  // 50.0f
  D32(0x807) = 0x41a00000u;  // 20.0f
  D32(0x817) = 0;
  D32(0x64b) = 0;
  self[0x67a] = 0;
  D32(0x846) = 0;
  D32(0x84e) = 0;
  D32(0x85e) = 0;
  D32(0x85a) = 0;
  D32(0xeee) = 0;
  D32(0x654) = 0;
  D32(0x658) = 0;
  ext_475820(self, 1, 1.0f);
  ext_475820(self, 2, 1.0f);
  ext_475820(self, 3, 1.0f);
  D32(0x439) = 0x42340000u;  // 45.0f
  D32(0x43d) = 0x42b40000u;  // 90.0f
  D32(0x441) = 0x42340000u;
  D32(0x451) = D32(0x43d);
  D32(0x842) = 0;
  D32(0x953) = 0;
  D32(0x957) = 0;
  D32(0x946) = 0;
  D32(0x94a) = 0;
  *(u16 *)(self + 0x66d) = 0;
  self[0x831] = 0;
  self[0x9e7] = 0;
  D32(0x9e8) = 0;
  D32(0x9ec) = 0;
  D32(0x9f0) = 0;
  D32(0x832) = 0;
  D32(0x836) = 0;
  D32(0x83a) = 0;
  self[0x827] = 0;
  *(u16 *)(self + 0x9f4) = 0x100;
  D32(0x829) = 0x3dcccccdu;  // 0.1f
  D32(0x9d7) = 0;
  D32(0x9df) = 0;
  D32(0x9e3) = 0;
  self[0x66f] = 0;
  D32(0x82d) = 0;
  self[0x94e] = 0;
  D32(0x94f) = 0;
  D32(0x823) = 0;
  D32(0xf5e) = 0;
  u8 *p = ext_41e290(0x108);
  u8 *v = p ? ext_4d8330(p, 0x6ac868u, 0x6ac844u, (u32)(self + 0xee8)) : 0;
  *(u8 **)(self + 0xee4) = v;
  vcall<void>(RM, 0x1a4, (u32)v);
  const char *val = (const char *)parent;
  if ((u8)vcall<u32>(RM, 0x5c, 0x6ac874u, (u32)&val)) {  // "blood"
    const u8 *a = (const u8 *)val, *b = (const u8 *)0x67a6d8u;  // "0"
    while (*a && *a == *b) a++, b++;
    self[0x653] = *a != *b;
  } else {
    self[0x653] = 1;
  }
  if ((u8)vcall<u32>(RM, 0x5c, 0x6ac87cu, (u32)&val)) {  // "followsneak"
    self[0xee3] = (*(atoi_t *)0x6762d8u)(val) != 0;
  } else {
    self[0xee3] = 1;
  }
  D32(0x942) = 0;
  D32(0x93a) = 0;
  D32(0x93e) = 0;
  for (u32 o = 0x8c2; o <= 0x936; o += 4) D32(o) = 0;
  return self;
}
PCREG(58ab50, heroCtor_58ab50);
#undef D32
#undef DB
#undef RM
