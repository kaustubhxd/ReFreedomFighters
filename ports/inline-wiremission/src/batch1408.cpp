// batch1408.cpp - missions thread, batch 1408: ZFFLevelController::GetStartingSewerLid, where the hero comes up when
// a level starts (FF levels are entered through manholes).
#include "missions.h"

extern "C" s32 THISCALL m_59b350(u8 *lc, u8 *geom);   // ZFFLevelController::GetSewerId (batch 1401)
// ZSewerControl::GetSewerInfo(const char *level, int &lidId, float pos[3], float mat[9]) (profile +0xe84).
extern "C" void THISCALL ext_5b15d0(u8 *sc, const char *level, s32 *id, float *pos, float *mat);
extern "C" void THISCALL ext_4db2c0(u8 *geom, float *mat, float *pos);   // ZBaseGeom::GetMatPos(float*, float*) const
extern "C" void FASTCALL ext_43e960(float *v, const float *w);          // v -= w (3 floats, x87)
extern "C" void THISCALL ext_5c3a90(u8 *sewerCtrl, u8 *entry);          // open that lid (sends a command, marks +8)
typedef double(VECTORCALL *libm1)(double);

static inline u8 *mgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static u32 lookup(const char *name) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, name, &h);
  return h;
}

// 0x59b3c0 ZFFLevelController::GetStartingSewerLid(). Multiplayer (+0x103f): none. Cached at +0x1050.
// The profile's sewer control gives the lid id for this level (+0x1048) and a saved hero position/matrix.
// The game data at [0x7003b8] lists the level's lids (+0xc69 count, 9-byte entries from +0xc6d, handle at +4).
//  id -2 / -3: none.
//  id >= 0 (any other than -1): the hero geom (hero slot 0x20) is placed with slot 0x74(mat, pos); the lid whose
//    geom name ends in that number is opened through the "SewerController" object ([0x70038c] slot 0xcc).
//  id -1: the lid nearest to the hero's current position (ZBaseGeom::GetMatPos; distance through the CRT sqrt)
//    is opened.
// Returns +0x1050, which is left at the last lid looked at when nothing matched.
static u32 THISCALL getStartingSewerLid(u8 *lc) {
  if (lc[0x103f])
    return 0;
  if (*(u32 *)(lc + 0x1050))
    return *(u32 *)(lc + 0x1050);
  u8 *gd = G(u8 *, 0x7003b8);
  float pos[3], mat[9];
  s32 *id = (s32 *)(lc + 0x1048);
  ext_5b15d0(lc + 0xedb, (const char *)(lc + 0x48), id, pos, mat);
  u32 h1 = lookup((const char *)0x6adca0);   // SewerController
  u8 *sc = vcall<u8 *, u32>(G(u8 *, 0x70038c), 0xcc, h1);
  u32 h2 = lookup((const char *)0x681320);   // HitmanGround
  u8 *hero = vcall<u8 *, u32>(mgr(), 0x58, h2);
  if (*id == -2 || *id == -3)
    return *(u32 *)(lc + 0x1050);
  if (*id != -1) {
    u8 *g = vcall<u8 *>(hero, 0x20);
    vcall<void, float *, float *>(g, 0x74, mat, pos);
    for (u8 *e = gd + 0xc6d; e != gd + 0xc6d + *(u32 *)(gd + 0xc69) * 9; e += 9) {
      u8 *lid = vcall<u8 *, u32>(mgr(), 0x58, *(u32 *)(e + 4));
      *(u8 **)(lc + 0x1050) = lid;
      if (*id == m_59b350(lc, lid)) {
        ext_5c3a90(sc, e);
        break;
      }
    }
    return *(u32 *)(lc + 0x1050);
  }
  u8 first = 1;
  u8 *best = 0;
  float bestd = 0.0f;
  u8 *g = vcall<u8 *>(hero, 0x20);
  ext_4db2c0(*(u8 **)(g + 8), mat, pos);
  for (u8 *e = gd + 0xc6d; e != gd + 0xc6d + *(u32 *)(gd + 0xc69) * 9; e += 9) {
    float v[3] = {0.0f, 0.0f, 0.0f};
    u8 *lid = vcall<u8 *, u32>(mgr(), 0x58, *(u32 *)(e + 4));
    *(u8 **)(lc + 0x1050) = lid;
    vcall<void, float *>(lid, 0x84, v);
    ext_43e960(v, pos);
    float s = v[1] * v[1] + v[0] * v[0];
    s = s + v[2] * v[2];
    float d = (float)(*(libm1 *)0x676330)((double)s);
    if (first) {
      bestd = d;
      best = e;
      first = 0;
    } else if (bestd > d) {
      bestd = d;
      best = e;
    }
  }
  if (best) {
    ext_5c3a90(sc, best);
    *(u32 *)(lc + 0x1050) = vcall<u32, u32>(mgr(), 0x58, *(u32 *)(best + 4));
  }
  return *(u32 *)(lc + 0x1050);
}
PCREG(59b3c0, getStartingSewerLid);
