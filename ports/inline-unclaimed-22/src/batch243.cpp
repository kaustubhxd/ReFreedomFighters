// batch243.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch243"). Names from the GameCube
// name map (gc_pc_namemap.tsv, medium/high); behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_488bc0(u8 *self);            // original, thiscall, no stack args (ret)
extern "C" void THISCALL ext_5b37e0(u8 *self);            // original, ZActionControlMap helper (ret)
extern "C" void THISCALL ext_5b3540(u8 *self);            // original (ret)
extern "C" void THISCALL ext_5b3ba0(u8 *self);            // original (ret)
extern "C" void THISCALL ext_5b3ef0(u8 *self);            // original, tail-jumped to (ret)
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 index);  // original, script argument getter (ret 4)
extern "C" void THISCALL ext_5a2d20(u8 *self, float f);   // original, one float stack word (ret 4)

typedef int(__attribute__((cdecl)) * stricmp_t)(const char *, const char *);
typedef void(__attribute__((cdecl)) * logf1_t)(void *, const char *, u32);

// 0x47adc0 ZActor::Resurrect(): vt[0x584](1); vt[0x654](1).
static void THISCALL resurrect_47adc0(u8 *self) {
  vcall<void>(self, 0x584, 1u);
  vcall<void>(self, 0x654, 1u);
}
PCREG(47adc0, resurrect_47adc0);

// 0x489160 ZMovementGuide::GetAnims(): 0x488bc0(this); this+0x391 = vt[0x58]("..." at 0x68d410); vt[0x54](this + 0x391).
static void THISCALL getAnims_489160(u8 *self) {
  ext_488bc0(self);
  u32 *slot = (u32 *)(self + 0x391);
  *slot = vcall<u32>(self, 0x58, 0x68d410u);
  vcall<void>(self, 0x54, (u32)slot);
}
PCREG(489160, getAnims_489160);

// 0x5b3780 ZActionControlMap::GenerateGameActions(): when the engine flag [0x70039c]+0x6c is set, mode 3 (+0x4d) copies the
// bytes +0x176, +0x17b to +0x1a6, +0x1a7, other modes clear the word at +0x1a6; when it is clear, 0x5b37e0(this) runs
// instead. Then 0x5b3540, 0x5b3ba0 and (tail) 0x5b3ef0, all on this.
static void THISCALL generateGameActions_5b3780(u8 *self) {
  u8 *rm = *(u8 **)0x70039cu;
  if (rm[0x6c]) {
    if (*(u32 *)(self + 0x4d) == 3) {
      self[0x1a6] = self[0x176];
      self[0x1a7] = self[0x17b];
    } else {
      *(u16 *)(self + 0x1a6) = 0;
    }
  } else {
    ext_5b37e0(self);
  }
  ext_5b3540(self);
  ext_5b3ba0(self);
  ext_5b3ef0(self);
}
PCREG(5b3780, generateGameActions_5b3780);

// 0x514600 ZMoveOnSpline::TargetValid(id) ret 4: o = engine db->vt[0x58](id); null: false. If !o->vt[0x1e0](0x200074): true.
// If o->vt[0x438](): false. Else: bit 10 of o->[+8]->[+0x3c] clear.
static bool THISCALL targetValid_514600(u8 *self, u32 id) {
  (void)self;
  u8 *rm = *(u8 **)0x70039cu;
  u8 *o = (u8 *)vcall<u32>(*(u8 **)(rm + 0x9b), 0x58, id);
  if (!o) return false;
  if (!(u8)vcall<u32>(o, 0x1e0, 0x200074u)) return true;
  if ((u8)vcall<u32>(o, 0x438)) return false;
  u32 flags = *(u32 *)(*(u8 **)(o + 8) + 0x3c);
  return ((flags >> 10) & 1) == 0;
}
PCREG(514600, targetValid_514600);

// 0x478e20 ZActor::GetMoveTypeId(const char*) const, ret 4: looks the name up (case-insensitive, _stricmp through the IAT
// slot 0x676414) in the 18-entry {name, id} table at 0x68ac68 ("Stand" 1 ... "Turn180" 0x13); unknown names log
// "WARNING: MoveTypeId %s does not exist" (file 0x68a7c4, line 0xd81) and return 0.
static u32 THISCALL getMoveTypeId_478e20(u8 *self, const char *name) {
  (void)self;
  stricmp_t cmp = *(stricmp_t *)0x676414u;
  const u32 *tab = (const u32 *)0x68ac68u;
  for (u32 i = 0; i < 0x12; i++)
    if (cmp(name, (const char *)tab[2 * i]) == 0) return tab[2 * i + 1];
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x68a7c4u, 0xd81u);
  (*(logf1_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68add0u, (u32)name);
  return 0;
}
PCREG(478e20, getMoveTypeId_478e20);

// 0x55c840 ZFFActorIf::SetHPMultiplierForHeadShot(OpaqueCallParameters_t&) ret 4: p = element 0 of params->[+4]; a type
// byte (p+4) other than 0 or 2 logs "RAISE_EXCEPTION %s" / "NO! WRONG TYPE" (file 0x69c8e0, line 0x104) and calls the
// assert hook at 0x7003b0 (int3 when there is none); then 0x5a2d20(this->[+0x1c], float at p).
static void THISCALL setHPMulHeadShot_55c840(u8 *self, u8 *params) {
  u8 *p = ext_5003d0(*(u8 **)(params + 4), 0);
  u8 t = p[4];
  if (t != 0 && t != 2) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x69c8e0u, 0x104u);
    (*(logf1_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x69c6b0u, 0x69c938u);
    void (*hook)() = *(void (**)())0x7003b0u;
    if (hook) hook();
    else __builtin_debugtrap();
  }
  ext_5a2d20(*(u8 **)(self + 0x1c), *(float *)p);
}
PCREG(55c840, setHPMulHeadShot_55c840);
