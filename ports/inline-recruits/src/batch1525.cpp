// batch1525.cpp - recruits thread, batch 1525: ZFFGameData::SSquad::AddMember(ZFFActor*) (0x5898c0), thiscall, ret 4,
// returns AL. A squad holds up to 12 members: the count is at +0, the members from +4. A member is appended and the
// count goes up (returns 1). A full squad logs the actor's name (MYSTR from the actor's slot 0x1d8; log object for file
// 0x6abf90 line 0x188; format 0x6ac018) and returns 0. The original's SEH frame and stack cookie are not ported.
#include "ff.h"

extern "C" void *THISCALL ext_4cc1d0(void *str);   // MYSTR -> const char* (batch 1513 refs)
extern "C" void THISCALL ext_4cbec0(void *str);    // MYSTR::~MYSTR

typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);

static u8 THISCALL squadAddMember(u32 *self, u8 *actor) {
  if (self[0] != 0xc) {
    self[1 + self[0]] = (u32)(u64)(u32)actor;
    ++self[0];
    return 1;
  }
  void *lo = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6abf90, 0x188u);
  u8 str[0x80];
  void *s = vcall<void *>(actor, 0x1d8, str, 1u);
  void *cs = ext_4cc1d0(s);
  ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x6ac018, cs);
  ext_4cbec0(str);
  return 0;
}
PCREG(5898c0, squadAddMember);
