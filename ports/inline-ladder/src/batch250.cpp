// batch250.cpp - ZFFHERO::CopyDataBlock(DBLK *blk) (inline-ladder thread, 2026-10-11). The DBLK accessors (Get, GetType,
// NextBlock) and GameEntity are other owners' verified functions and are called as the exe calls them.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_482800(void *self, void *blk);            // ZPlayer::CopyDataBlock (base)
extern "C" void THISCALL ext_4e12e0(void *blk, u32 *out, u32 flag);    // DBLK::Get(unsigned*, int)
extern "C" void THISCALL ext_4e11e0(void *blk, u32 *out, u32 flag);    // DBLK::Get(int*, int)
extern "C" u8 THISCALL ext_4e1600(void *blk);                          // DBLK::GetType
extern "C" void THISCALL ext_4e1b30(void *blk);                        // DBLK::NextBlock
extern "C" void *THISCALL ext_59d330(void *ent, void *owner, u32 zero);   // GameEntity::GameEntity (returns this)
extern "C" void THISCALL ext_59d430(void *ent, u32 team);              // GameEntity::SetEntityTeam
extern "C" void *ext_41e290(u32 size);                                  // operator new (cdecl)

static inline void *db250() { return (void *)U32(G(u32, 0x70039c), 0x9b); }

// 0x590620 ZFFHERO::CopyDataBlock(DBLK *blk), thiscall, ret 4.
// 1. base ZPlayer::CopyDataBlock(blk); 2. Get(tmp, 1). 3. type 3: Get(self+0x684, 1); a GameEntity (0x18 bytes) is made for
// self (+0x54) with its +8 = 4; when the database slot 0x134() manager's slot 0x90("Multiplayer", &flag) is set: the team from
// self+0x684: 2 -> "MP_Player1Team", 3 -> "MP_Player2Team", 4 -> "MP_Player3Team", otherwise "MP_Player0Team" (the last also
// sets self+0x684 = 1); team = slot 0x88(name, &out); SetEntityTeam(ent, team); ent+0x10 = 0x80 | (1 << team). If the flag is
// clear, self+0x684 = 1. 4. type 8: Get(self+0x846, 1) and then, if type 8 again, Get(tmp2, 1) and self+0x84e =
// db slot 0x58(tmp2). 5. NextBlock(blk).
static void THISCALL heroCopyDataBlock(u8 *self, u8 *blk) {
  ext_482800(self, blk);
  u32 tmp14 = 0;
  ext_4e12e0(blk, &tmp14, 1);
  if (ext_4e1600(blk) == 3) {
    u32 *flag684 = (u32 *)(self + 0x684);
    ext_4e11e0(blk, flag684, 1);
    u8 *ent = (u8 *)ext_41e290(0x18);
    if (ent)
      ent = (u8 *)ext_59d330(ent, self, 0);
    else
      ent = 0;
    U32(self, 0x54) = (u32)(unsigned long)ent;
    U32(ent, 8) = 4;
    u8 mpflag = 0;
    void *mgr = vcall<void *>(db250(), 0x134);
    vcall<void>(mgr, 0x90, (const char *)0x68a9d4, &mpflag);   // "Multiplayer"
    if (mpflag) {
      u32 v = *flag684;
      const char *name;
      if (v == 2)
        name = (const char *)0x6a7d6c;   // MP_Player1Team
      else if (v == 3)
        name = (const char *)0x6a7dc4;   // MP_Player2Team
      else if (v == 4)
        name = (const char *)0x6a7e1c;   // MP_Player3Team
      else
        name = (const char *)0x6a7d14;   // MP_Player0Team
      u32 team = 0;
      void *m2 = vcall<void *>(db250(), 0x134);
      if (name == (const char *)0x6a7d14) {
        // the MP_Player0Team branch: the manager call is made and the flag is set to 1 afterwards
        vcall<void>(m2, 0x88, name, &team);
        *flag684 = 1;
      } else {
        vcall<void>(m2, 0x88, name, &team);
      }
      ext_59d430(ent, team);
      U32(ent, 0x10) = 0x80u | (1u << (team & 31));
    } else {
      *flag684 = 1;
    }
  }
  if (ext_4e1600(blk) == 8) {
    ext_4e12e0(blk, (u32 *)(self + 0x846), 1);
  }
  if (ext_4e1600(blk) == 8) {
    u32 tmp10 = 0;
    ext_4e12e0(blk, &tmp10, 1);
    U32(self, 0x84e) = vcall<u32>(db250(), 0x58, tmp10);
  }
  ext_4e1b30(blk);
}
PCREG(590620, heroCopyDataBlock);
