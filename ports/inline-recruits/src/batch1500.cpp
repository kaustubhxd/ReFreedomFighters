// batch1500.cpp - recruits thread, batch 1500: charisma meter, recruit list, squad and follower leaves (bottom-up).
// Names are from the GameCube ELF via decoders/gc_pc_namemap.tsv (confidence in docs/20-recruits.md).
#include "ff.h"

// ---------------------------------------------------------------- ZOnScreenDisplay / CSprite3D (charisma meter)

// 0x5ec090 CSprite3D::Resize(int w, int h), thiscall, ret 8.
// If (w, h) differs from the stored size at +0x6e/+0x72, store it and walk the frame table [+0x62] (count +0x3e):
// every frame whose 16-bit size (+0x28, +0x2a) differs gets the new size and scale = size / base size (+4, +6),
// and the sprite's dirty byte +0xa6 is set.
static void THISCALL spriteResize(u8 *self, s32 w, s32 h) {
  if (*(s32 *)(self + 0x6e) == w && *(s32 *)(self + 0x72) == h)
    return;
  *(s32 *)(self + 0x6e) = w;
  *(s32 *)(self + 0x72) = h;
  for (u32 i = 0; i < *(u32 *)(self + 0x3e); ++i) {
    u8 *f = (*(u8 ***)(self + 0x62))[i];
    if ((s32) * (u16 *)(f + 0x28) == w && (s32) * (u16 *)(f + 0x2a) == h)
      continue;
    u16 bw = *(u16 *)(f + 4);
    *(u16 *)(f + 0x28) = (u16)w;
    *(u16 *)(f + 0x2a) = (u16)h;
    *(float *)(f + 8) = (float)w / (float)(s32)bw;
    u16 bh = *(u16 *)(f + 6);
    *(float *)(f + 0xc) = (float)h / (float)(s32)bh;
    self[0xa6] = 1;
  }
}
PCREG(5ec090, spriteResize);

extern "C" void THISCALL ext_5ec090(u8 *sprite, s32 w, s32 h);
extern "C" void THISCALL ext_5ebd80(u8 *sprite, s32 obj);  // CSprite3D::ChangeObj

// 0x5a5e90 ZOnScreenDisplay::CharismaSet(unsigned int), thiscall, ret 4.
// The meter value lives at +0x370. When all 12 charisma symbols are lit (+0x47c == 12) the value is forced to 100
// and +0x370 is cleared first, so the bar is always redrawn. On a change the bar sprite (+0x43c) is resized to
// (value / 100 * 120, 8): the value goes u32 -> double -> float, then float divide and multiply, truncated to int.
static void THISCALL osdCharismaSet(u8 *self, u32 v) {
  if (*(u32 *)(self + 0x47c) == 12) {
    v = 100;
    *(u32 *)(self + 0x370) = 0;
  }
  if (*(u32 *)(self + 0x370) == v)
    return;
  *(u32 *)(self + 0x370) = v;
  u8 *bar = *(u8 **)(self + 0x43c);
  if (!bar)
    return;
  float f = (float)(double)v;
  f = f / 100.0f;   // 0x67cd40
  f = f * 120.0f;   // 0x68c74c
  ext_5ec090(bar, _mm_cvttss_si32(_mm_set_ss(f)), 8);
}
PCREG(5a5e90, osdCharismaSet);

// 0x5a5f00 ZOnScreenDisplay::CharismaSymbolAdd(ECHARISMASYBMOLB kind), thiscall, ret 4.
// Lights the next of 12 symbol sprites (+0x440 table, count +0x47c): sets its visible byte +0x35 and changes its
// object to the one for `kind` (table of pointers at +0x4b8, first dword of each).
static void THISCALL osdCharismaSymbolAdd(u8 *self, u32 kind) {
  u32 n = *(u32 *)(self + 0x47c);
  if (n == 12)
    return;
  (*(u8 **)(self + 0x440 + 4 * n))[0x35] = 1;
  u8 *spr = *(u8 **)(self + 0x440 + 4 * n);
  s32 o = **(s32 **)(self + 0x4b8 + 4 * kind);
  ext_5ebd80(spr, o);
  ++*(u32 *)(self + 0x47c);
}
PCREG(5a5f00, osdCharismaSymbolAdd);

// 0x5a5f40 ZOnScreenDisplay::CharismaSymbolClear(), thiscall, plain ret: hides all 12 symbols, count = 0.
static void THISCALL osdCharismaSymbolClear(u8 *self) {
  for (u32 i = 0; i < 12; ++i)
    (*(u8 **)(self + 0x440 + 4 * i))[0x35] = 0;
  *(u32 *)(self + 0x47c) = 0;
}
PCREG(5a5f40, osdCharismaSymbolClear);

// ---------------------------------------------------------------- ZGameOSD charisma and recruit list
extern "C" void THISCALL ext_5a5e90(u8 *osd, u32 v);

// 0x596ce0 ZGameOSD::CharismaGetExperience(), thiscall: returns +0x1fb6.
static u32 THISCALL charismaGetExperience(u8 *self) { return *(u32 *)(self + 0x1fb6); }
PCREG(596ce0, charismaGetExperience);

// 0x596d00 ZGameOSD::CharismaSetExperience(int), thiscall, ret 4. Stores +0x1fb6 and, when the on-screen display
// (+0x1d0f) exists, tail-calls ZOnScreenDisplay::CharismaSet with the same value.
static void THISCALL charismaSetExperience(u8 *self, u32 v) {
  *(u32 *)(self + 0x1fb6) = v;
  u8 *osd = *(u8 **)(self + 0x1d0f);
  if (osd)
    ext_5a5e90(osd, v);
}
PCREG(596d00, charismaSetExperience);

// 0x596d30 ZGameOSD::CharismaSetRecruitable(int), thiscall, ret 4. The number of recruitable followers (+0x1fba)
// is capped (signed) at the maximum +0x1fbe; then the meter is refreshed with the experience value +0x1fb6.
static void THISCALL charismaSetRecruitable(u8 *self, s32 v) {
  s32 mx = *(s32 *)(self + 0x1fbe);
  if (v > mx)
    v = mx;
  u8 *osd = *(u8 **)(self + 0x1d0f);
  *(s32 *)(self + 0x1fba) = v;
  if (osd)
    ext_5a5e90(osd, *(u32 *)(self + 0x1fb6));
}
PCREG(596d30, charismaSetRecruitable);

// 0x596760 ZGameOSD::AddNonRecruitable(unsigned int id), thiscall, ret 4.
// Looks the id up through the engine's object table (system object 0x70039c, +0x9b, vtable slot 0x58) and, when the
// object exists and answers yes to slot 0x1e0 (IsKindOf) for class id 0x2007f9, appends the id to the
// non-recruitable list at +0x2ef (count +0x4ef; no capacity check).
static void THISCALL addNonRecruitable(u8 *self, u32 id) {
  void *tab = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  void *o = vcall<void *>(tab, 0x58, id);
  if (!o)
    return;
  if (!vcall<u8>(o, 0x1e0, 0x2007f9u))
    return;
  u32 n = *(u32 *)(self + 0x4ef);
  *(u32 *)(self + 0x2ef + 4 * n) = id;
  ++*(u32 *)(self + 0x4ef);
}
PCREG(596760, addNonRecruitable);

// 0x597e00 ZGameOSD::RemoveRecruit(unsigned int id), thiscall, ret 4.
// Recruit list: ids at +0x1dae, count +0x1fae, selected index +0x1fb2. The found entry is replaced by the last one,
// the old last slot is cleared, and the selection is pulled back when it pointed past the end (never below 0).
static void THISCALL removeRecruit(u8 *self, u32 id) {
  u32 n = *(u32 *)(self + 0x1fae);
  if (n == 0)
    return;
  u32 *ids = (u32 *)(self + 0x1dae);
  u32 i = 0;
  while (ids[i] != id) {
    ++i;
    if (i >= n)
      return;
  }
  u32 last = n - 1;
  *(u32 *)(self + 0x1fae) = last;
  ids[i] = ids[last];
  ids[*(u32 *)(self + 0x1fae)] = 0;
  u32 c = *(u32 *)(self + 0x1fae);
  if (*(u32 *)(self + 0x1fb2) == c)
    *(u32 *)(self + 0x1fb2) = c - 1;
  if (*(s32 *)(self + 0x1fb2) < 0)
    *(u32 *)(self + 0x1fb2) = 0;
}
PCREG(597e00, removeRecruit);

// ---------------------------------------------------------------- ZFFGameData squads

// 0x589c20 ZFFGameData::GetGameOSD(char player), thiscall, ret 4: the per-player ZGameOSD at +0x2c2d (signed index).
static u8 *THISCALL getGameOSD(u8 *self, s8 i) { return *(u8 **)(self + 0x2c2d + 4 * (s32)i); }
PCREG(589c20, getGameOSD);

// 0x589fd0 ZFFGameData::GetSquad(int), thiscall, ret 4: -1 gives null, else the 0xf4-byte squad record at +0xd91.
static u8 *THISCALL getSquadByIndex(u8 *self, s32 i) {
  if (i == -1)
    return 0;
  return self + (u32)(i * 0xf4 + 0xd91);
}
PCREG(589fd0, getSquadByIndex);

// 0x589f70 ZFFGameData::GetSquad(SSquad*), thiscall, ret 4: the index of the squad record, -1 for null or not found.
// The squad count is +0xd8d.
static s32 THISCALL getSquadIndex(u8 *self, u8 *sq) {
  u8 *p = self + 0xd91;
  if (!sq)
    return -1;
  u8 *end = self + (u32)(*(s32 *)(self + 0xd8d) * 0xf4 + 0xd91);
  if (p == end)
    return -1;
  s32 i = 0;
  while (p != sq) {
    p += 0xf4;
    ++i;
    if (p == end)
      return -1;
  }
  return i;
}
PCREG(589f70, getSquadIndex);

// 0x58a360 ZFFGameData::SSquad::RemoveMember(ZFFActor*), thiscall, ret 4, returns AL.
// Squad record: member count +0, members from +4. The found member is overwritten by the last one.
static u8 THISCALL squadRemoveMember(u32 *self, u32 actor) {
  u32 *last = self + self[0];
  u32 *end = last + 1;
  u32 *p = self + 1;
  if (p != end) {
    while (*p != actor) {
      ++p;
      if (p == end)
        break;
    }
  }
  if (p == end)
    return 0;
  *p = *last;
  --self[0];
  return 1;
}
PCREG(58a360, squadRemoveMember);

extern "C" u8 THISCALL ext_58a360(u8 *sq, u8 *actor);
extern "C" u8 THISCALL ext_5898c0(u8 *sq, u8 *actor);  // SSquad::AddMember (12 members max)

// 0x5a2860 ZFFActor::RemoveFromSquad(), thiscall, plain ret: leave the squad (+0x921), clear it and the index +0x925.
static void THISCALL actorRemoveFromSquad(u8 *self) {
  u8 *sq = *(u8 **)(self + 0x921);
  if (!sq)
    return;
  ext_58a360(sq, self);
  *(u32 *)(self + 0x921) = 0;
  *(u32 *)(self + 0x925) = 0xffffffffu;
}
PCREG(5a2860, actorRemoveFromSquad);

// 0x59dce0 ZFFActor::AddToSquad(SSquad*), thiscall, ret 4: remember the squad when AddMember accepts the actor.
static void THISCALL actorAddToSquad(u8 *self, u8 *sq) {
  if (ext_5898c0(sq, self))
    *(u8 **)(self + 0x921) = sq;
}
PCREG(59dce0, actorAddToSquad);

// ---------------------------------------------------------------- ZFFHERO followers

// 0x591d30 ZFFHERO::GetFollower(unsigned int), thiscall, ret 4: follower records of 0x30 bytes at +0xa1a, count
// +0xa16; the actor pointer is the record's first dword. Out of range gives null.
static u32 THISCALL heroGetFollower(u8 *self, u32 i) {
  if (i >= *(u32 *)(self + 0xa16))
    return 0;
  return *(u32 *)(self + 0xa1a + i * 0x30);
}
PCREG(591d30, heroGetFollower);
