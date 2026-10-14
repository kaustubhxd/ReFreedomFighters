// batch1409.cpp - missions thread, batch 1409: ZFFLevelController::Command, the message interface scripts and other
// objects use to reach mission variables and the profile.
#include "missions.h"

extern "C" s32 THISCALL m_5adeb0(u8 *prof, const char *name);          // CPlayerProfile::GetLevelVar (batch 1401)
extern "C" void THISCALL m_5ae930(u8 *prof, const char *name, s32 v);   // CPlayerProfile::SetLevelVar (batch 1401)
extern "C" s32 THISCALL m_59b350(u8 *lc, u8 *geom);                     // ZFFLevelController::GetSewerId
extern "C" void THISCALL ext_4db2c0(u8 *geom, float *mat, float *pos);  // ZBaseGeom::GetMatPos
extern "C" void THISCALL ext_5b1760(u8 *sc, const char *level, s32 id, float *pos, float *mat);   // ZSewerControl::SetSewerInfo
extern "C" u32 THISCALL ext_48aad0(void *pair);   // {registry, name}: registry slot 0x88(name, &handle), returns handle

#define LEVELCONTROLLER_CPP 0x6adc28u
static inline u8 *mgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
// Manager slot 0x114: the id of a named message (registering it on first use; file/line are the caller's).
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)LEVELCONTROLLER_CPP, line);
}

// 0x59ae60 ZFFLevelController::Command(unsigned short msg, void *data). Returns 0. Messages, tested in this order:
//   Msg_GetPtrToPlayerProfile       *data = profile (this + 0x57)
//   GETMISSIONVAR                   data = {int result, const char *name}: result = GetLevelVar(name) when name is
//                                   set; a null block writes 0 to address 0 (a crash the scripts never trigger)
//   SETMISSIONVAR                   data = the variable name: set to 1
//   Msg_GetDifficultyLevel          *data = +0x411
//   Msg_GetPtrToWindowCoordinator   *data = this + 0x13298
//   Msg_SaveHeroPosMat              data = a lid handle: the hero's current matrix and position are stored in the
//                                   sewer control for this level under that lid's number (where to come up next time)
static u32 THISCALL lcCommand(u8 *lc, u32 msg, u32 *data) {
  u16 m = (u16)msg;
  if (m == msgId((const char *)0x6ad354, 0x26a)) {
    *data = (u32)(lc + 0x57);
    return 0;
  }
  if (m == msgId((const char *)0x6a5c68, 0x26f)) {
    if (!data) {
      u32 *z = data;
      asm("" : "+r"(z));   // keep the store: the original writes through the null pointer
      *(volatile u32 *)z = 0;
      return 0;
    }
    const char *name = (const char *)data[1];
    if (name)
      data[0] = (u32)m_5adeb0(lc + 0x57, name);
    return 0;
  }
  if (m == msgId((const char *)0x6a5c58, 0x280)) {
    if (data)
      m_5ae930(lc + 0x57, (const char *)data, 1);
    return 0;
  }
  if (m == msgId((const char *)0x6a5c78, 0x289)) {
    *data = *(u32 *)(lc + 0x411);
    return 0;
  }
  if (m == msgId((const char *)0x6add1c, 0x290)) {
    *data = (u32)(lc + 0x13298);
    return 0;
  }
  if (m == msgId((const char *)0x6add3c, 0x295)) {
    u8 *lid = vcall<u8 *, u32>(mgr(), 0x58, (u32)data);
    s32 sid = m_59b350(lc, lid);
    struct {
      u8 *reg;
      const char *name;
    } pr;
    pr.reg = vcall<u8 *>(mgr(), 0x138);
    pr.name = (const char *)0x681320;   // HitmanGround
    u32 h = ext_48aad0(&pr);
    u8 *hero = vcall<u8 *, u32>(mgr(), 0x58, h);
    if (hero) {
      u8 *g = vcall<u8 *>(hero, 0x20);
      float mat[9], pos[3];
      ext_4db2c0(*(u8 **)(g + 8), mat, pos);
      ext_5b1760(lc + 0xedb, (const char *)(lc + 0x48), sid, pos, mat);
    }
  }
  return 0;
}
PCREG(59ae60, lcCommand);
