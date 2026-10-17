// batch247.cpp - ZFFHERO::UpdateDefaultAction(CAction *a) (inline-ladder thread, 2026-10-11). NOT verified exact: the exe
// pushes five arguments for the two message sends (MSG_REMOVEACTION, MSG_ADDACTION) into RegisterZMsg-shaped slot 0x114,
// which pops four (ret 0x10): a 4-byte stack imbalance like batch 242. This port makes the intended four-argument calls.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16(p, off) (*(u16 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_4d2280(void *ccom);                          // CCom::CCom
extern "C" void THISCALL ext_4d2330(void *ccom);                          // CCom teardown
extern "C" void THISCALL ext_4d3a00(void *ccom, u32 name, u32 value, u32 type);   // CSharedCom::SetVal (ret 0xc)
extern "C" void THISCALL ext_4d39a0(void *ccom, u32 name, u32 value);     // CSharedCom::SetVal (ret 8)
extern "C" void THISCALL ext_4d3ad0(void *ccom, u32 name, u32 value, u32 type);   // CSharedCom::SetVal (ret 0xc)
extern "C" void THISCALL ext_4cbe80(void *mystr, u32 src);                // MYSTR ctor from a char*
extern "C" void THISCALL ext_4cbee0(void *mystr, void *other);            // MYSTR::operator=
extern "C" void THISCALL ext_4cbec0(void *mystr);                         // MYSTR dtor
extern "C" u32 THISCALL ext_4cc5f0(void *mystr);                          // MYSTR::Length
extern "C" void *THISCALL ext_4cc1d0(void *mystr);                        // MYSTR string pointer (3 bytes in the exe)
extern "C" void *THISCALL ext_41e680(void *p);                            // ConvPtr

static const char *const kFile = (const char *)0x6ac6d0;   // "..\..\freedomfighter\FFBackground\ZFFHero.cpp"

// 0x595570 ZFFHERO::UpdateDefaultAction(CAction *a) [GameCube reference-area, high], thiscall, ret 4.
// Nothing when a equals the current default action (+0x688) and the default name is empty (a == 0) or equal
// (case-insensitive, _stricmp) to a's name (+0x7a). Otherwise: CCom teardown/ctor with the "CUI" list (db slot 0x138, its
// slot 0x88); if the current name is non-empty, SetVal("strActionName", name, 0xc), REMOVEACTION message (db slot 0x114)
// and the hero's slot 0x12c(out, msg). If a != 0: SetVal("strActionName", a+0x7a), "rNotifyGeom" (db slot 0x4c(hero, 4)),
// "pData" (ConvPtr(a), 5), "msgMessage" (word +0x165, 0x12), "lPrio" (a+0x52, 2); the name is copied into the hero's
// MYSTR (+0x698); ADDACTION message and the hero's slot 0x12c. If a == 0 the MYSTR becomes "" (0x677b5a).
// Finally +0x688 = a.
static void THISCALL heroUpdateDefaultAction(u8 *self, u32 action) {
  u8 *eng = (u8 *)G(u32, 0x70039c);
  u8 *db = (u8 *)U32(eng, 0x9b);
  u8 *mystr = self + 0x698;
  if (action == U32(self, 0x688)) {
    if (action == 0) {
      if (ext_4cc5f0(mystr) == 0)
        return;
    } else {
      void *s = ext_4cc1d0(mystr);
      typedef int (*stricmpT)(const char *, const char *);
      if (((stricmpT)G(u32, 0x676414))((const char *)U32(action, 0x7a), (const char *)s) == 0)
        return;
    }
  }
  u8 ccom[0x4154];
  ext_4d2280(ccom);
  void *mgr = vcall<void *>(db, 0x138);
  u32 out = 0;
  vcall<void>(mgr, 0x88, (const char *)0x68be98, (u32)(unsigned long)&out);   // "CUI"
  void *s0 = ext_4cc1d0(mystr);
  if (s0 && *(u8 *)ext_4cc1d0(mystr) != 0) {
    ext_4d3a00(ccom, 0x6acb50u, (u32)(unsigned long)ext_4cc1d0(mystr), 0xcu);
    u32 msg = (u16)vcall<u32>(db, 0x114, (const char *)0x6acb60, 0u, kFile, 0x918u);   // MSG_REMOVEACTION
    vcall<void>(self, 0x12c, out, msg);
  }
  if (action) {
    ext_4d39a0(ccom, 0x6acb50u, U32(action, 0x7a));
    u32 g = vcall<u32>(db, 0x4c, (u32)(unsigned long)self, 4u);
    ext_4d3ad0(ccom, 0x6acb74u, g, 4u);
    u32 cp = (u32)(unsigned long)ext_41e680((void *)(unsigned long)action);
    ext_4d3a00(ccom, 0x6acb80u, cp, 5u);
    ext_4d3ad0(ccom, 0x6acb88u, (u32)U16(self, 0x165), 0x12u);
    ext_4d3ad0(ccom, 0x6acb94u, U32(action, 0x52), 2u);
    u8 tmp[16];
    ext_4cbe80(tmp, U32(action, 0x7a));
    ext_4cbee0(mystr, tmp);
    ext_4cbec0(tmp);
    u32 msg = (u16)vcall<u32>(db, 0x114, (const char *)0x6acb9c, 0u, kFile, 0x926u);   // MSG_ADDACTION
    vcall<void>(self, 0x12c, out, msg);
  } else {
    u8 tmp[16];
    ext_4cbe80(tmp, 0x677b5au);
    ext_4cbee0(mystr, tmp);
    ext_4cbec0(tmp);
  }
  U32(self, 0x688) = action;
  ext_4d2330(ccom);
}
PCREG(595570, heroUpdateDefaultAction);
