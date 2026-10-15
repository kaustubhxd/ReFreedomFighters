// batch716.cpp - soldier AI, batch 716 (2026-10-11): ZFFActor::OnSound, the soldier's hearing of sound events.
// wire-ai copy, run 11 (2026-10-13): the message's data is the sound block (was a zeroed buffer; the spec now compares the block).
// The list is a REFTAB (iterator: slot 0x4c begins, slot 0x64 gives the next event, null at the end). An event is
// {float x,y,z; ...; +0xc u32 type; +0x10 float distance; +0x14 u32 source ref; +0x1c u32 extra}. Type 1..7 selects
// the case through a jump table (type 2 and any other type: nothing; type 5 and types above 7: warning and stop).
// Sources must be ZLNKWHANDS-derived (class id 0x80200014); a soldier's own sounds assert and are skipped.
// Message names are exe strings "Msg_Sound_*"; the message id comes from RegisterZMsg (db slot 0x114) and the block
// {x, y, z, distance*0.01, source ref, extra} goes to self through SendCommand(id, data, sender = 0) (slot 0x128).
#include "ff.h"

struct SoundBlock {
  float x, y, z;
  float scale;
  u32 ref;
  u32 extra;
};

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

static void sound_warn(u32 line) {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ae6a0, line);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68aec4);   // "<debug message>"
}

// Team test used by Shot and FootStep: bit (source team index) must be set in the team mask of `team`.
static inline bool team_hears(u8 *team, u8 *source) {
  u32 bit = 1u << (*(u32 *)(*(u8 **)(source + 0x54) + 4) & 31);
  return (*(u32 *)(*(u8 **)(team + 0x54) + 0xc) & bit) != 0;
}

// 0x5a1830 ZFFActor::OnSound(REFTAB* events) [medium].
static void THISCALL zffactor_OnSound(u8 *self, void *events) {
  if (!events)
    return;
  u32 it = 0;
  vcall<void>(events, 0x4c, &it);
  u8 *ev = vcall<u8 *>(events, 0x64, &it);
  while (ev) {
    u8 *src = vcall<u8 *>(db(), 0x58, *(u32 *)(ev + 0x14));
    if (src && vcall<bool>(src, 0x1e0, 0x80200014)) {
      if (src == self) {
        void (*h)() = *(void (**)())0x7003b0;   // "tried to hear its own sound": assert, then skip
        if (h)
          h();
        else
          __builtin_debugtrap();
      } else {
        u32 t = *(u32 *)(ev + 0xc);
        u32 idx = t - 1;
        const char *name = 0;
        float dist = *(float *)(ev + 0x10);
        if (idx > 6 || idx == 4) {
          sound_warn(0x66e);
          return;
        }
        switch (idx) {
        case 0:   // Shot: within 1500 and heard by our team
          if (!(dist > 1500.0f) && team_hears(self, src))
            name = (const char *)0x68ae1c;
          break;
        case 2:   // Pain: no test
          name = (const char *)0x68ae4c;
          break;
        case 3:   // FootStep: within 1000, our team is team 1, and heard by it
          if (!(dist > 1000.0f) && *(u32 *)(*(u8 **)(self + 0x54) + 4) == 1 && team_hears(self, src))
            name = (const char *)0x68ae5c;
          break;
        case 5:   // Impact: within 1500
          if (!(dist > 1500.0f))
            name = (const char *)0x68ae80;
          break;
        case 6:   // Die: no test
          name = (const char *)0x68ae3c;
          break;
        default:  // type 2: nothing
          break;
        }
        if (name) {
          SoundBlock blk;
          blk.x = *(float *)(ev + 0);
          blk.y = *(float *)(ev + 4);
          blk.z = *(float *)(ev + 8);
          blk.scale = dist * 0.00999999978f;   // 0x67da00
          blk.ref = *(u32 *)(ev + 0x14);
          blk.extra = *(u32 *)(ev + 0x1c);
          u16 id = vcall<u16>(db(), 0x114, name, 0u, (const char *)0x6ae6a0, 0x683u);   // RegisterZMsg: four args
          // slot 0x128 SendCommand(id, &block, 0): the exe pushes 0 and &block before RegisterZMsg's four arguments, which that
          // callee pops, so they become 0x128's data and sender (wire-ai run 11 fix: the inline-ai lift passed a zeroed buffer)
          vcall<void>(self, 0x128, (u32)id, (void *)&blk, (void *)0);
        }
      }
    }
    ev = vcall<u8 *>(events, 0x64, &it);
  }
}
PCREG(5a1830, zffactor_OnSound);
