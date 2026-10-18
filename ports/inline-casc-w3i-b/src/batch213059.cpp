#include "ff.h"

typedef u32(THISCALL *S0)(void *);
typedef u32(THISCALL *S1)(void *, u32);
extern "C" u32 FASTCALL ext_4cc850(const char *s, const char *pat);

// 0x474070: thiscall(this, a, flag, obj) ret 0xc: picks a string constant (a table address of the exe) for the record byte a[0] (a[1] != 0 selects the first,
// a[1] == 0 the second constant of a pair; the flag byte, cleared when slot 0x1e0(0x80200014) has a nonzero low byte, selects the pair).
// obj type (slot 0x330, 0 for a null obj) 9 compares obj->[4] (or a default string) with a pattern through ext_4cc850; type 8 with the flag returns 0x689acc.
// The result of slot 0x21c(this, str) == 0 replaces the string with 0x689d04 (a[1] == 0) or 0x689cf4.
extern "C" u32 THISCALL fn_474070(u8 *self, u8 *a, u32 flagarg, u8 *obj) {
  u32 type = 0;
  if (obj) type = (*(S0 *)(*(u8 **)obj + 0x330))(obj);
  u32 flag = (u8)flagarg;
  u32 r = (*(S1 *)(*(u8 **)self + 0x1e0))(self, 0x80200014);
  if ((u8)r) flag = 0;
  if (type == 9) {
    const char *s = *(const char **)(obj + 4);
    if (!s) s = (const char *)0x67c8e8;
    return ext_4cc850(s, (const char *)0x689ab4) ? 0x689acc : 0x689ac0;
  }
  if (type == 8 && (u8)flag) return 0x689acc;
  u32 str = 0;
  u32 hi, lo;  // constants for a[1] != 0, a[1] == 0
  switch (a[0]) {
    case 0:
    case 4:
    case 5:
      if (flag) { hi = 0x689ad8; lo = 0x689af4; }
      else if (a[0] == 0) { hi = 0x689b0c; lo = 0x689b28; }
      else { hi = 0x689b44; lo = 0x689b5c; }
      str = a[1] == 0 ? lo : hi;
      break;
    case 7:
    case 8:
      if (flag) { hi = 0x689b74; lo = 0x689b90; } else { hi = 0x689bac; lo = 0x689bc4; }
      str = a[1] == 0 ? lo : hi;
      break;
    case 6:
      if (flag) { hi = 0x689bdc; lo = 0x689bf0; } else { hi = 0x689c04; lo = 0x689c1c; }
      str = a[1] == 0 ? lo : hi;
      break;
    case 9:
      if (flag) { hi = 0x689c34; lo = 0x689c4c; } else { hi = 0x689c60; lo = 0x689c78; }
      str = a[1] == 0 ? lo : hi;
      break;
    case 1:
      if (flag) { hi = 0x689c90; lo = 0x689ca4; } else { hi = 0x689cb8; lo = 0x689ccc; }
      str = a[1] == 0 ? lo : hi;
      break;
    case 2:
    case 3: str = 0x689ce0; break;
    default: break;
  }
  if (!(*(S1 *)(*(u8 **)self + 0x21c))(self, str)) str = a[1] == 0 ? 0x689d04 : 0x689cf4;
  return str;
}
PCREG(474070, fn_474070);
