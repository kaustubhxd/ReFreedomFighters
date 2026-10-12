// batch1001.cpp - unclaimed-07 batch 1 (docs/20-unclaimed-07.md): ZInputActions small functions.
// Names are from the GC name map (naming only, never committed; GUESS where the body disagrees with the name).
// Every function is thiscall. Pointers returned by vtable calls are carried as u32 (the PC code only tests and
// passes them on, it never reads through them except where the body says so).
#include "ff.h"

// 0x438780, ZInputActions::EnableActions() (medium): increments the dword at this+0x120c. No arguments.
static void THISCALL inputEnableActions(u8 *self) {
  *(u32 *)(self + 0x120c) += 1;
}
PCREG(438780, inputEnableActions);

// 0x438360, ZInputActions::DisableActions() (medium, GUESS): the body takes one argument. It calls vtable slot +0x58
// with that argument (returns a pointer); when the pointer is non-null, the byte at +0x0c of the result is cleared.
static void THISCALL inputDisableActions(u8 *self, u32 a1) {
  u8 *p = (u8 *)vcall<u32>(self, 0x58, a1);
  if (p)
    p[0x0c] = 0;
}
PCREG(438360, inputDisableActions);

// 0x43af70, ZInputActions::SetActionIgnoreLockOnSave(const char*) (high): vtable slot +0x58 on the name gives a pointer;
// when it is non-null and its first dword is 0, the byte at +0x30 of that object is set to 1 and the function returns.
// Otherwise vtable slot +0x60 on the name gives a pointer; when that is non-null its byte at +0x22 is set to 1.
// When that is null too, the function reports through the engine log (global 0x700390): slot +0x20 on the log object
// with file 0x67a850 (..\..\code\engine\system\actions.cpp) and line 0x782 gives a stream, and the stream's slot +0x2c
// is called with the stream and the message 0x67a928 ("Warning: Setting ignore locked node on save on a non-action
// reference"). That call is cdecl (the caller pops). PC also loads ECX with the stream's vtable before it; the port's
// cdecl call does not, which is a scratch register for a cdecl callee.
static void THISCALL inputSetActionIgnoreLockOnSave(u8 *self, u32 a1) {
  u8 *p = (u8 *)vcall<u32>(self, 0x58, a1);
  if (p && *(u32 *)p == 0) {
    p[0x30] = 1;
    return;
  }
  u8 *q = (u8 *)vcall<u32>(self, 0x60, a1);
  if (q) {
    q[0x22] = 1;
    return;
  }
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x67a850, 0x782);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x67a928);
}
PCREG(43af70, inputSetActionIgnoreLockOnSave);

// 0x43a7c0, ZInputActions::RemoveActionMap(ZActionMapDefinition*) (medium): vtable slot +0x5c on the argument gives a
// pointer; when it is non-null, vtable slot +0x10 is called on this with that pointer.
static void THISCALL inputRemoveActionMapDef(u8 *self, u32 a1) {
  u32 p = vcall<u32>(self, 0x5c, a1);
  if (p)
    vcall<void>(self, 0x10, p);
}
PCREG(43a7c0, inputRemoveActionMapDef);

// 0x43a7e0, ZInputActions::RemoveActionMap(const char*) (medium): as above, with vtable slot +0x60 for the lookup.
static void THISCALL inputRemoveActionMapName(u8 *self, u32 a1) {
  u32 p = vcall<u32>(self, 0x60, a1);
  if (p)
    vcall<void>(self, 0x10, p);
}
PCREG(43a7e0, inputRemoveActionMapName);

// 0x438f30, ZInputActions::GetActionValue(const char*) (high): returns vtable slot +0xa0 called on this with the
// pointer that vtable slot +0x58 returns for the name.
static u32 THISCALL inputGetActionValue(u8 *self, u32 a1) {
  u32 p = vcall<u32>(self, 0x58, a1);
  return vcall<u32>(self, 0xa0, p);
}
PCREG(438f30, inputGetActionValue);

// 0x438880, ZInputActions::ForceSetAction(const char*, bool) (medium): the pointer from vtable slot +0x58 on the name
// goes to vtable slot +0x4c together with the bool argument (pushed in that order: pointer is the first parameter).
static void THISCALL inputForceSetAction(u8 *self, u32 a1, u32 a2) {
  u32 p = vcall<u32>(self, 0x58, a1);
  vcall<void>(self, 0x4c, p, a2);
}
PCREG(438880, inputForceSetAction);
