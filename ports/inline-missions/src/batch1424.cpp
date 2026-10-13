// batch1424.cpp - missions thread, batch 1424: ZFFCareTaker_C05A::FrameUpdate, the loudspeaker line.
#include "missions.h"

extern "C" u8 *THISCALL ext_49df60(u8 *rc, const char *name, u8 *res);   // ResourceCollection::GetResource: Resource* or 0
extern "C" const char *THISCALL ext_49e0d0(u8 *res);                     // Resource::GetText()
extern "C" void THISCALL ext_59a5b0(u8 *osd, const char *title, const char *text, float secs);   // ZGameOSD::MessageDialog
#define CARETAKER_C05A_CPP 0x6b31f0u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
#define U32(o) (*(u32 *)(ct + (o)))

// 0x5bce80 ZFFCareTaker_C05A::FrameUpdate(). When the loudspeaker is pending (+0x5e) and the engine clock (sys+0x40)
// has passed the timer (+0x5f):
//  - MSG_SOUNDSEGMENTSTART (line 0x5d) is sent to +0x6f (two arguments: the target and the id, no data word);
//  - the title "Names/Loudspeaker" and the text "C05A/LevelSpecific/C05A_01_Loudspeaker" are read from the resource
//    collection ([mgr+0xae4]; "N/A" when missing) and shown by MessageDialog on the hero ("HitmanGround") OSD for 25 s;
//  - the pending flag +0x5e is cleared.
static void THISCALL c05aFrameUpdate(u8 *ct) {
  if (!ct[0x5e])
    return;
  if (*(s32 *)(sysi() + 0x40) <= *(s32 *)(ct + 0x5f))
    return;
  // This call site pushes FIVE words (name, 0, file, line, 0): the register slot 0x114 is called with the extra
  // trailing zero here, unlike the four-word calls elsewhere. Mirrored as pushed.
  u16 id = vcall<u16, const char *, u32, const char *, u32, u32>(mgr(), 0x114, (const char *)0x692d94, 0,
                                                                 (const char *)CARETAKER_C05A_CPP, 0x5d, 0);   // MSG_SOUNDSEGMENTSTART
  vcall<void, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, U32(0x6f), (u32)id);
  u8 res[0x200];
  u8 *rc = *(u8 **)(mgr() + 0xae4);
  const char *title = (const char *)0x6852b8;   // "N/A"
  if (u8 *r = ext_49df60(rc, (const char *)0x6b324c, res))   // Names/Loudspeaker
    title = ext_49e0d0(r);
  const char *text = (const char *)0x6852b8;
  if (u8 *r = ext_49df60(rc, (const char *)0x6b3260, res))   // C05A/LevelSpecific/C05A_01_Loudspeaker
    text = ext_49e0d0(r);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x681320, &h);   // HitmanGround
  u8 *hero = vcall<u8 *, u32>(mgr(), 0x58, h);
  ext_59a5b0(*(u8 **)(hero + 0x852), title, text, 25.0f);
  ct[0x5e] = 0;
}
PCREG(5bce80, c05aFrameUpdate);
