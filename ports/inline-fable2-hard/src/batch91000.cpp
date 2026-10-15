// batch91000.cpp - hard-function trial (fable 2), batch 91000: 0x5a3710 MP_GameController::MP_GameController() (455 insns, 70 calls).
// The function has an SEH/EH3 prologue (push -1; push 0x66bee7; fs:[0] frame; /GS cookie xor ebp) that is never used: no exception is
// thrown, the frame is only installed and removed. The port drops it (the fake TEB at 0 absorbs the fs:[0] writes on the exe side).
#include "ff.h"

typedef u8 *(THISCALL *v0o_t)(void *);
typedef u32 (THISCALL *v0u_t)(void *);
typedef u32 (THISCALL *v1u_t)(void *, u32);
typedef void (THISCALL *v1_t)(void *, u32);
typedef void (THISCALL *v2_t)(void *, u32, u32);
typedef void (THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32 (THISCALL *v4u_t)(void *, u32, u32, u32, u32);

extern "C" void THISCALL ext_469870(void *);             // ret 0: base ctor (ZGameController-ish, 257 bytes, hooked)
extern "C" void *ext_41e290(u32 size);                   // cdecl operator new through the memory manager at 0x70038c (verified unclaimed-64, hooked)
extern "C" u8 *THISCALL ext_4ccbe0(void *, u32, u32);    // ret 8: small list/array ctor (verified batch45, hooked)

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline void wr16(u8 *p, u16 v) { *(u16 *)p = v; }

// [0x70039c]: engine object; [eng+0x9b] = object table whose slot 0x134 returns the settings object, 0x114 registers a message
// (name, 0, file, line) -> id (word), 0x138 returns the routing object (slot 0x60(name, handle, 4)).
static inline u8 *table() {
  u8 *eng = G(u8 *, 0x70039c);
  return *(u8 **)(eng + 0x9b);
}
static inline u8 *settings() {
  u8 *tab = table();
  return (*(v0o_t **)tab)[0x134 / 4](tab);
}
static inline void set3(u32 slot, u32 name, u32 a, u32 b) {   // settings->slot(name, a, b)
  u8 *z = settings();
  (*(v3_t **)z)[slot / 4](z, name, a, b);
}
static inline u16 regmsg(u32 name, u32 line) {   // table->slot 0x114(name, 0, file, line), only ax is kept
  u8 *tab = table();
  return (u16)(*(v4u_t **)tab)[0x114 / 4](tab, name, 0, 0x6af0ccu, line);
}

// 0x5a3710, thiscall(no args), this = E. Constructor of the multiplayer game controller.
static u8 *THISCALL fn5a3710(u8 *E) {
  ext_469870(E);
  wr(E + 4, rd(E + 4) | 0x20);
  wr(E + 0x44, 0);
  wr(E, 0x6af018u);
  u8 *edi = E + 0xe9;
  wr(G(u8 *, 0x7003b8) + 0x2c21, (u32)E);
  wr(edi, 0);
  wr(E + 0xed, 0);
  wr(E + 0xf1, 0);
  wr(E + 0xf5, 0);
  u8 *z = settings();
  u8 mp = 0;
  (*(v2_t **)z)[0x90 / 4](z, 0x68a9d4u, (u32)&mp);   // "Multiplayer" -> bool
  u8 *eng = G(u8 *, 0x70039c);
  wr(eng + 0x1b5d, 1);
  if (mp == 0) {
    set3(0x68, 0x68a9d4u, 1, 0);     // Multiplayer := 1
    set3(0x5c, 0x68fcecu, 2, 2);     // MP_NumberOfPlayers
    set3(0x68, 0x6a7cf0u, 1, 0);     // MP_Player0Active
    set3(0x5c, 0x6a7d04u, 0, 2);     // MP_Player0Slot
    set3(0x5c, 0x6a7d14u, 3, 2);     // MP_Player0Team
    set3(0x40, 0x6a7d24u, 0x6a812cu, 0xc);   // MP_Player0Skin = "Hero1\Ground"
    set3(0x5c, 0x6a7d34u, 8, 2);     // MP_Player0Charisma
    set3(0x68, 0x6a7d48u, 1, 0);     // MP_Player1Active
    set3(0x5c, 0x6a7d5cu, 1, 2);     // MP_Player1Slot
    set3(0x5c, 0x6a7d6cu, 4, 2);     // MP_Player1Team
    set3(0x40, 0x6a7d7cu, 0x6af09cu, 0xc);   // MP_Player1Skin = "Hero4\Ground"
    set3(0x5c, 0x6a7d8cu, 4, 2);     // MP_Player1Charisma
    set3(0x68, 0x6a7da0u, 0, 0);     // MP_Player2Active
    set3(0x5c, 0x6a7db4u, 2, 2);     // MP_Player2Slot
    set3(0x5c, 0x6a7dc4u, 4, 2);     // MP_Player2Team
    set3(0x40, 0x6a7dd4u, 0x6af0acu, 0xc);   // MP_Player2Skin = "Hero5\Ground"
    set3(0x5c, 0x6a7de4u, 4, 2);     // MP_Player2Charisma
    set3(0x68, 0x6a7df8u, 0, 0);     // MP_Player3Active
    set3(0x5c, 0x6a7e0cu, 3, 2);     // MP_Player3Slot
    set3(0x5c, 0x6a7e1cu, 4, 2);     // MP_Player3Team
    set3(0x40, 0x6a7e2cu, 0x6af0bcu, 0xc);   // MP_Player3Skin = "Hero6\Ground"
    set3(0x5c, 0x6a7e3cu, 0, 2);     // MP_Player3Charisma
    set3(0x5c, 0x6a813cu, 0, 2);     // MP_Map
    set3(0x5c, 0x6a80fcu, 1, 2);     // MP_KOTHGameType
    set3(0x58, 0x6a810cu, 0x40400000u, 3);   // MP_KOTHLimit = 3.0f
  }
  z = settings();
  u32 koth = 0;
  (*(v2_t **)z)[0x88 / 4](z, 0x6a80fcu, (u32)&koth);   // MP_KOTHGameType -> int
  wr(E + 0x48, koth);
  wr16(E + 0xf9, regmsg(0x6af104u, 0x75));    // ReturnRefToCaller
  wr16(E + 0xfb, regmsg(0x6af118u, 0x77));    // MSG_MP_MAPCONTROL
  wr16(E + 0xfd, regmsg(0x6af12cu, 0x78));    // MSG_MP_TIMEREND
  wr16(E + 0xff, regmsg(0x6af13cu, 0x7a));    // MSG_MP_POINT
  wr16(E + 0x101, regmsg(0x6ace1cu, 0x7b));   // MSG_MP_KILL
  wr16(E + 0x103, regmsg(0x6af14cu, 0x7d));   // MSG_MP_BUNKERCONTROL
  wr16(E + 0x105, regmsg(0x6af164u, 0x7f));   // MSG_MP_SPAWN
  wr16(E + 0x107, regmsg(0x6af174u, 0x80));   // MSG_MP_REQUESTSPAWN
  u8 *tab = table();
  u8 *rout = (*(v0o_t **)tab)[0x138 / 4](tab);
  // inlined handle lookup through the memory manager at 0x70038c: slot 0x20(E) != 0 -> 0; else a direct resolver
  // M[8] for the address range [M[0xc], M[0x10]); else the word before the object, registered with slot 0xac if still 0.
  u8 *M = G(u8 *, 0x70038c);
  u32 handle;
  if ((*(v1u_t **)M)[0x20 / 4](M, (u32)E)) {
    handle = 0;
  } else {
    M = G(u8 *, 0x70038c);
    v0u_t res = *(v0u_t *)(M + 8);
    if (res && rd(M + 0xc) <= (u32)E && (u32)E < rd(M + 0x10)) {
      handle = res(E);
    } else {
      if (rd(E - 4) == 0)
        (*(v1_t **)M)[0xac / 4](M, (u32)E);
      handle = rd(E - 4);
    }
  }
  (*(v3_t **)rout)[0x60 / 4](rout, 0x6a8324u, handle, 4);   // "GameController_Rout"
  for (int i = 0; i < 4; i++) {
    u8 *p = (u8 *)ext_41e290(0x1c);
    wr(edi, p ? (u32)ext_4ccbe0(p, 4, 0) : 0);
    edi += 4;
  }
  wr(E + 0x10b, 0);
  wr(E + 0x10f, 0);
  wr(E + 0x11b, 0);
  wr(E + 0x123, 0);
  wr(E + 0x113, 0x41200000u);   // 10.0f
  wr(E + 0x127, 0);
  wr(E + 0x12b, 0);
  wr(E + 0x12f, 0);
  wr(E + 0x133, 0);
  return E;
}
PCREG(5a3710, fn5a3710);
