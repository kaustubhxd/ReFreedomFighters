// u69_66.cpp - area 69, group 66 (slice 8). A DBCS-style markup tokenizer, transcribed block by block from the original (labels are the original addresses).
// Jump tables are read from the exe image (0x629350, 0x629374, 0x629390, 0x6293a8, 0x6293c4, 0x6293d4, 0x6293fc, 0x629420, 0x629430, 0x629440, 0x629464).
// Helper 0x62c640 is a pure byte classifier (cdecl, two args, only the low bytes read, edx preserved), so the real code runs.
// Helper 0x62a690 is a GUESS stub in the spec (cdecl, four args; writes its out pointer; returns an int).
#include "ff.h"

extern "C" u32 ext_62c640(u32 a, u32 b);   // cdecl, two args; real code
extern "C" s32 ext_62a690(u8 *tab, u8 *start, u8 *end, u8 **out);   // cdecl, four args; other area (GUESS stub in the spec)

#define TB(a) (*(const u8 *)(u32)(a))
#define TD(a) (*(const u32 *)(u32)(a))

// 0x628fc0, cdecl (tab, start, end, out) -> int. Returns -1 at end of input, -2 for an incomplete token, 0 with *out = position, 1/3 with *out = position after a token.
static s32 scan628fc0(u8 *tab, u8 *start, u8 *endp, u8 **out) {
  u32 eax = 0, ebx = 0, ecx = 0, edx = 0, esi = 0, edi = 0, tgt = 0, flag = 0;
  u8 *B12 = start;   // the [ebp+0xc] slot: the position; the helper 0x62a690 writes it through &B12
  esi = (u32)endp;
  edi = (u32)start;
  flag = 0;
  if (edi == esi)
    goto L6292a9;
L628fe0:
  {
    u8 *p = (u8 *)edi;
    ebx = (ebx & ~0xffu) | p[1];
    ecx = (ecx & ~0xffu) | p[0];
  }
  if ((u8)ebx == 0)
    goto L628fe9;
  eax = ext_62c640(ebx, ecx);
  edx = (u32)tab;
  goto L629003;
L628fe9:
  edx = (u32)tab;
  eax = TB((u8)ecx + edx + 0x4c);
  goto L629003;
L629003:
  eax = eax - 5;
  if (eax > 0x18)
    goto L6290ca;
  tgt = TD(0x629350 + 4 * TB(0x629374 + eax));
  goto dispatch;
L62901d:
  eax = (u8)ebx;
  ecx = (u8)ecx;
  edx = TB(eax + 0x6bfd20);
  goto L62927f;
L62902f:
  if (flag != 0)
    goto L6290ca;
  edi += 2;
  flag = 1;
  if (edi == esi)
    goto L6292a9;
  {
    u8 *p = (u8 *)edi;
    ebx = (ebx & ~0xffu) | p[1];
    ecx = (ecx & ~0xffu) | p[0];
  }
  if ((u8)ebx == 0)
    goto L629054;
  eax = ext_62c640(ebx, ecx);
  goto L629068;
L629054:
  eax = TB((u8)ecx + edx + 0x4c);
  goto L629068;
L629068:
  eax = eax - 5;
  if (eax > 0x18)
    goto L6290ca;
  tgt = TD(0x629390 + 4 * TB(0x6293a8 + eax));
  goto dispatch;
L62907e:
  ecx = (u8)ecx;
  eax = (u8)ebx;
  goto L629278;
L629090:
  edi += 2;
  if (edi == esi)
    goto L6292a9;
  {
    u8 *p = (u8 *)edi;
    ecx = (ecx & ~0xffu) | p[1];
    eax = p[0];
  }
  if ((u8)ecx == 0) {
    eax = TB(eax + edx + 0x4c);
  } else {
    eax = ext_62c640(ecx, eax);
  }
  if (eax == 0xe)
    goto L6290d8;
  if ((s32)eax < 9)
    goto L6290ca;
  if ((s32)eax <= 0xa)
    goto L629090;
  if (eax == 0x15)
    goto L629090;
  goto L6290ca;
L6290ca:
  *out = (u8 *)edi;
  return 0;
L6290d8:
  flag = 0;
  goto L6290e0;
L6290e0:
  edi += 2;
  if (edi == esi)
    goto L6292a9;
  {
    u8 *p = (u8 *)edi;
    ecx = (ecx & ~0xffu) | p[1];
    eax = p[0];
  }
  if ((u8)ecx == 0) {
    ebx = TB(eax + edx + 0x4c);
  } else {
    ebx = ext_62c640(ecx, eax);
  }
  if (ebx == 0xc)
    goto L62912f;
  if (ebx == 0xd)
    goto L62912f;
  if ((s32)ebx < 9)
    goto L6290ca;
  if ((s32)ebx <= 0xa)
    goto L6290e0;
  if (ebx == 0x15)
    goto L6290e0;
  goto L6290ca;
L62912f:
  edi += 2;
  goto L629132;
L629132:
  B12 = (u8 *)edi;
  goto L629135;
L629135:
  if (edi == esi)
    goto L6292a9;
  {
    u8 *p = (u8 *)edi;
    eax = p[1];
  }
  if ((u8)eax != 0)
    goto L62914e;
  eax = TB(((u8 *)edi)[0] + edx + 0x4c);
  goto L629185;
L62914e:
  eax = (u8)eax;
  eax = eax - 0xd8;
  if (eax > 0x27)
    goto L629180;
  tgt = TD(0x6293c4 + 4 * TB(0x6293d4 + eax));
  goto dispatch;
L629169:
  eax = 7;
  goto L629185;
L629170:
  eax = 8;
  goto L629185;
L629177:
  if (((u8 *)edi)[0] < 0xfe)
    goto L629180;
  eax = 0;
  goto L629185;
L629180:
  eax = 0x1d;
  goto L629185;
L629185:
  if (eax == ebx)
    goto L6291f5;
  if (eax > 8)
    goto L62912f;
  tgt = TD(0x6293fc + 4 * eax);
  goto dispatch;
L629195:
  eax = esi - edi;
  if ((s32)eax < 2)
    goto L629313;
  goto L62912f;
L6291a4:
  eax = esi - edi;
  if ((s32)eax < 3)
    goto L629313;
  edi += 3;
  goto L629132;
L6291b9:
  eax = esi - edi;
  if ((s32)eax < 4)
    goto L629313;
  edi += 4;
  goto L629132;
L6291ce: {
    s32 r = ext_62a690(tab, (u8 *)(edi + 2), (u8 *)esi, &B12);
    edx = (u32)r;
    if ((s32)edx <= 0)
      goto L6292b3;
    edi = (u32)B12;
    edx = (u32)tab;
    goto L629135;
  }
L6292b3:
  if ((s32)edx != 0)
    goto L6292bd;
  *out = B12;
L6292bd:
  return (s32)edx;
L6291f5:
  edi += 2;
  if (edi == esi)
    goto L6292a9;
  {
    u8 *p = (u8 *)edi;
    ecx = (ecx & ~0xffu) | p[1];
    eax = p[0];
  }
  if ((u8)ecx == 0) {
    eax = TB(eax + edx + 0x4c);
  } else {
    eax = ext_62c640(ecx, eax);
  }
  goto L62921b;
L62921b:
  eax = eax - 9;
  if (eax > 0xc)
    goto L6290ca;
  tgt = TD(0x629420 + 4 * TB(0x629430 + eax));
  goto dispatch;
L629235:
  edi += 2;
  if (edi == esi)
    goto L6292a9;
  {
    u8 *p = (u8 *)edi;
    ecx = (ecx & ~0xffu) | p[1];
    eax = p[0];
  }
  if ((u8)ecx == 0) {
    eax = TB(eax + edx + 0x4c);
  } else {
    eax = ext_62c640(ecx, eax);
  }
  goto L629257;
L629257:
  eax = eax - 5;
  if (eax > 0x18)
    goto L6290ca;
  tgt = TD(0x629440 + 4 * TB(0x629464 + eax));
  goto dispatch;
L629271:
  ecx = ((u8 *)edi)[0];
  eax = ((u8 *)edi)[1];
  goto L629278;
L629278:
  edx = TB(eax + 0x6bfc20);
  goto L62927f;
L62927f:
  eax = ecx;
  ecx = ecx & 0x1f;
  eax = eax >> 5;
  edx = eax + edx * 8;
  eax = 1;
  eax = eax << (ecx & 31);
  if ((TD(0x6bf720 + 4 * edx) & eax) == 0)
    goto L6290ca;
  edi += 2;
  if (edi != esi)
    goto L628fe0;
  goto L6292a9;
L6292c6:
  edi += 2;
  if (edi == esi)
    goto L6292a9;
  if (((u8 *)edi)[1] != 0)
    goto L6290ca;
  if (((u8 *)edi)[0] != 0x3e)
    goto L6290ca;
  *out = (u8 *)(edi + 2);
  return 3;
L6292f4:
  *out = (u8 *)(edi + 2);
  return 1;
L629308:
  esi = esi - edi;
  if ((s32)esi >= 2)
    goto L6290ca;
  goto L629313;
L62931f:
  esi = esi - edi;
  if ((s32)esi >= 3)
    goto L6290ca;
  goto L62932a;
L629336:
  esi = esi - edi;
  if ((s32)esi >= 4)
    goto L6290ca;
  goto L629341;
L629313:
  return -2;
L62932a:
  return -2;
L629341:
  return -2;
L62929e:
  edi += 2;
  if (edi != esi)
    goto L628fe0;
  goto L6292a9;
L6292a9:
  return -1;
dispatch:
  switch (tgt) {
    case 0x629169: goto L629169;
    case 0x629170: goto L629170;
    case 0x629177: goto L629177;
    case 0x62901d: goto L62901d;
    case 0x62902f: goto L62902f;
    case 0x629090: goto L629090;
    case 0x6290ca: goto L6290ca;
    case 0x6290d8: goto L6290d8;
    case 0x62907e: goto L62907e;
    case 0x62912f: goto L62912f;
    case 0x629180: goto L629180;
    case 0x629195: goto L629195;
    case 0x6291a4: goto L6291a4;
    case 0x6291b9: goto L6291b9;
    case 0x6291ce: goto L6291ce;
    case 0x6291f5: goto L6291f5;
    case 0x629235: goto L629235;
    case 0x629271: goto L629271;
    case 0x6292c6: goto L6292c6;
    case 0x6292f4: goto L6292f4;
    case 0x629308: goto L629308;
    case 0x62931f: goto L62931f;
    case 0x629336: goto L629336;
    case 0x62929e: goto L62929e;
    default: __builtin_trap();
  }
}
PCREG(628fc0, scan628fc0);
