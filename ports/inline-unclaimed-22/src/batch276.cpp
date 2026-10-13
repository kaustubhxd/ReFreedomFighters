// batch276.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch276"): the input action
// system (which controls are pressed this frame): ZInputActions::CheckAction, ZInputActionGroup::CheckGroup,
// ZInputActions::GetActiveActions and ZInputActions::Save. Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" u8 THISCALL ext_439670(u8 *a);           // ZInputActionBase::IsActive (GUESS: hooked)
extern "C" u8 *THISCALL ext_438c30(u8 *g);          // owning action set of a group (inline-unclaimed-76 batch280)
extern "C" u8 THISCALL ext_437d60(u8 *a);           // ZInputAction::CheckAction (GUESS: hooked)
extern "C" u8 THISCALL ext_438150(u8 *g);           // ZInputActionGroup::CheckGroup (this batch, original code)
extern "C" void *__attribute__((cdecl)) ext_634d10(void *d, int v, u32 n);  // memset (CRT)

typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);

// 0x437ed0 ZInputActions::CheckAction(ZInputActionBase *a, void *ctx) ret 8, returns bool (al). ctx 0 means the caller's
// return address. Kind 0 (single action, object at a - 4): not when flag 4 at +0x2e; needs its enabled byte (a+0xc) and,
// unless the parent kind is 3, the parent chain active (0x439670); then this->vt 0x34(action, ctx). Kind 1 (group):
// this->vt 0x30(a, ctx). Kind 2 (one-shot): returns and clears the byte at +0x15. Others: false.
u8 THISCALL checkAction_437ed0(u8 *self, u8 *a, u32 ctx) {
  if (!a) return 0;
  if (!ctx) ctx = (u32)__builtin_return_address(0);
  u32 t = *(u32 *)a;
  if (t == 0) {
    if (a[0x2e] & 4) return 0;
    u8 *s = a - 4;
    u8 b = s[0x10];
    if (!b) return 0;
    if (*(u32 *)(s + 4) != 3) b &= ext_439670(*(u8 **)(s + 0xc));
    if (!b) return 0;
    return (u8)vcall<u32>(self, 0x34, (u32)s, ctx);
  }
  if (t == 1) return (u8)vcall<u32>(self, 0x30, (u32)a, ctx);
  if (t == 2) {
    u8 r = a[0x15];
    a[0x15] = 0;
    return r;
  }
  return 0;
}
PCREG(437ed0, checkAction_437ed0);

// 0x438150 ZInputActionGroup::CheckGroup() (no args), returns bool (al): true when any member of the list +0xd is held.
// Each member id is looked up in the owning set's table (0x438c30, then [+0x11] vt 0x58); a single action (kind 0) is
// asked through the input manager (rm+0x1907 vt 0x34(action, 0)); anything else logs line 0xc02 (slot 0x2c).
u8 THISCALL checkGroup_438150(u8 *self) {
  u8 any = 0;
  u8 *lst = *(u8 **)(self + 0xd);
  if (!lst) return 0;
  u32 it[3];
  vcall<void>(lst, 0x4c, (u32)it);
  u32 x = vcall<u32>(*(u8 **)(self + 0xd), 0x5c, (u32)it);
  while (it[0]) {
    u8 *set = ext_438c30(self);
    u8 *e = (u8 *)vcall<u32>(*(u8 **)(set + 0x11), 0x58, x);
    if (*(u32 *)e == 0) {
      any |= (u8)vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x1907), 0x34, (u32)(e - 4), 0u);
    } else {
      void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x67a850u, 0xc02u);
      (*(log0_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x67abe0u);
    }
    x = vcall<u32>(*(u8 **)(self + 0xd), 0x5c, (u32)it);
  }
  return any;
}
PCREG(438150, checkGroup_438150);

// 0x438f50 ZInputActions::GetActiveActions(REFTAB *out) ret 4: for every group of the list +0x1214 and every action of
// the group's list +0x19, a held single action (kind 0, 0x437d60 on a - 4) or group (kind 1, 0x438150) is added to out
// (out->vt 4(a)).
void THISCALL getActiveActions_438f50(u8 *self, u8 *out) {
  u8 *lst = *(u8 **)(self + 0x1214);
  if (!lst) return;
  u32 it[3];
  vcall<void>(lst, 0x4c, (u32)it);
  u8 *g = (u8 *)vcall<u32>(*(u8 **)(self + 0x1214), 0x5c, (u32)it);
  while (it[0]) {
    u8 *inner = *(u8 **)(g + 0x19);
    if (inner) {
      u32 it2[3];
      vcall<void>(inner, 0x4c, (u32)it2);
      u8 *a = (u8 *)vcall<u32>(*(u8 **)(g + 0x19), 0x5c, (u32)it2);
      while (it2[0]) {
        u32 t = *(u32 *)a;
        u8 r = 0;
        if (t == 0) r = ext_437d60(a - 4);
        else if (t == 1) r = ext_438150(a);
        if ((t == 0 || t == 1) && r) vcall<void>(out, 4, (u32)a);
        a = (u8 *)vcall<u32>(*(u8 **)(g + 0x19), 0x5c, (u32)it2);
      }
    }
    g = (u8 *)vcall<u32>(*(u8 **)(self + 0x1214), 0x5c, (u32)it);
  }
}
PCREG(438f50, getActiveActions_438f50);

// 0x439690 ZInputActions::Save(ZSaveGame *s) ret 4, returns true. Reads 0x100-byte records (s->vt 0x18(buf, 0x100)) until
// one has kind 0: each names an action (this->vt 0x60(name at +4)); kind 2 resets it (vt 0x1c), kind 1 looks up the key
// at +0x80 (vt 0x10) and stores the word at +0xfc into that binding's +0x46.
u8 THISCALL inputSave_439690(u8 *self, u8 *s) {
  u8 buf[0x100];
  ext_634d10(buf, 0, 0x100);
  vcall<void>(s, 0x18, (u32)buf, 0x100u);
  while (*(u32 *)buf) {
    u8 *o = (u8 *)vcall<u32>(self, 0x60, (u32)(buf + 4));
    if (o) {
      u32 k = *(u32 *)buf;
      if (k == 2) {
        vcall<void>(o, 0x1c);
      } else if (k == 1) {
        u8 *r = (u8 *)vcall<u32>(o, 0x10, (u32)(buf + 0x80));
        u8 *p = r ? r - 4 : 0;
        *(u32 *)(p + 0x46) = *(u32 *)(buf + 0xfc);
      }
    }
    vcall<void>(s, 0x18, (u32)buf, 0x100u);
  }
  return 1;
}
PCREG(439690, inputSave_439690);
