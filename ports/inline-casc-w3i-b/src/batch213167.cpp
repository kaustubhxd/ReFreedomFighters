#include "ff.h"

extern "C" u32 ext_42ac56(char *buf, const char *fmt, u32 n);
extern "C" u32 THISCALL ext_589c20(void *g, u32 c);
extern "C" u32 THISCALL ext_59a5e0(void *self, u32 a);
extern "C" u32 THISCALL ext_5a4590(void *r, u32 i);
extern "C" u32 THISCALL ext_5a46f0(void *r, u32 i);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

#define EBP (fr + 0x698)
#define P(off) (EBP - (off))

// cdecl vcall with ecx = the vtable (as the original loads it) and 3 / 4 pushed arguments
static u32 cd3(void *o, u32 off, u32 a, u32 b) {
  u32 vtp = *(u32 *)o, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[b]\n\tpushl %[a]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $12, %%esp"
               : "+a"(ra), "+c"(rc)
               : [b] "r"(b), [a] "r"(a), [o] "r"(o)
               : "edx", "memory", "cc");
  return ra;
}
static u32 cd2(void *o, u32 off, u32 a) {
  u32 vtp = *(u32 *)o, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $8, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [o] "r"(o)
               : "edx", "memory", "cc");
  return ra;
}
static u32 cd4(void *o, u32 off, u32 buf, u32 b, u32 d) {
  // the formatter path leaves ecx = &buf (lea ecx, [ebp - 0x404]) instead of the vtable
  u32 vtp = *(u32 *)o, fn = *(u32 *)(vtp + off), rc = buf, ra = fn;
  asm volatile("pushl %[d]\n\tpushl %[b]\n\tpushl %[a]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $16, %%esp"
               : "+a"(ra), "+c"(rc)
               : [d] "r"(d), [b] "r"(b), [a] "r"(buf), [o] "r"(o)
               : "edx", "memory", "cc");
  return ra;
}

// 0x56e050: thiscall() plain ret, /GS, void. Multiplayer score board: reads MP_NumberOfPlayers / MP_KOTHGameType / GameController_Rout, collects the 4 player records of the
// route object into two teams (struct A "USA" = team 3, struct B "Soviet" = team 4, by MP_Player%iActive / %iTeam), orders the two team structs (KOTH: by the byte of the team-3
// record, else by its three signed dwords against team 4's), sends the winner's message to this[0x94][0x44] (slot 0x128) and then fills the 33 text widgets this[0x180 + i*4]
// (slot 0x284) with strings formatted through the engine formatter (engine slot 0x190 -> object slot 0x198) from team names / player names / numbers.
static void body_56e050(u8 *self) {
  u8 fr[0x6a0];
  { void *d = fr; u32 n = sizeof fr; asm volatile("rep stosb" : "+D"(d), "+c"(n) : "a"(0xcc) : "memory"); }
  u8 *eng = G(u8 *, 0x70039c);
  W32(P(0x648), (u32)self);
  u8 *T = (u8 *)R32(eng + 0x9b);
  u8 *X = vcall<u8 *>(T, 0x134);
  W32(P(0x640), 0);
  vcall<u32>(X, 0x88, 0x68fcecu, P(0x640));
  T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
  X = vcall<u8 *>(T, 0x134);
  W32(P(0x640), 0);
  vcall<u32>(X, 0x88, 0x6a80fcu, P(0x640));
  T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
  X = vcall<u8 *>(T, 0x138);
  W32(P(0x63c), 0);
  vcall<u32>(X, 0x88, 0x6a8324u, P(0x63c));
  u8 *Y = G(u8 *, 0x70038c);
  u8 *Rr = vcall<u8 *>(Y, 0xcc, R32(P(0x63c)));
  static const u32 pname[4] = {0x6a8338, 0x6a8340, 0x6a8348, 0x6a8350};
  W32(P(0x614), pname[0]);
  W32(P(0x644), (u32)Rr);
  W32(P(0x610), pname[1]);
  W32(P(0x60c), pname[2]);
  W32(P(0x608), pname[3]);
  for (u32 i = 1; i <= 4; i++) {
    u8 *ent = P(0x634) + 8 * (i - 1);
    W32(ent + 4, pname[i - 1]);
    W32(ent, ext_5a4590(Rr, i));
  }
  // team structs: A at -0x66c (kind 3, "USA"), B at -0x690 (kind 4, "Soviet"); fields +0 text, +4 team, +8 colour, +0xc team record, +0x10/+0x14/+0x18 player entries, +0x1c count, +0x20 music
  u8 *A = P(0x66c);
  u8 *B = P(0x690);
  u32 cntA = 0, cntB = 0;
  W32(A, 0x6a8368);
  W32(P(0x650), 0);
  W32(P(0x65c), 0);
  W32(P(0x658), 0);
  W32(P(0x654), 0);
  W32(P(0x674), 0);
  W32(P(0x680), 0);
  W32(P(0x67c), 0);
  W32(P(0x678), 0);
  W32(P(0x660), ext_5a46f0(Rr, 3));
  W32(P(0x668), 0x6a8358);
  W32(P(0x664), 0xf);
  W32(P(0x64c), 0x6a4fc4);
  W32(P(0x690), 0x6a838c);
  W32(P(0x684), ext_5a46f0(Rr, 4));
  W32(P(0x68c), 0x6a8378);
  W32(P(0x688), 0x10);
  W32(P(0x670), 0x6a4fdc);
  u8 *cur = P(0x634);
  W32(P(0x63c), (u32)cur);
  for (u32 b = 0; b < 4; b++) {
    char *buf = (char *)P(0x604);
    ext_42ac56(buf, (const char *)0x6a83a0, b);
    T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    X = vcall<u8 *>(T, 0x134);
    *P(0x635) = 0;
    vcall<u32>(X, 0x90, (u32)buf, P(0x635));
    if (*P(0x635) != 0) {
      ext_42ac56(buf, (const char *)0x6a83b4, b);
      T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
      X = vcall<u8 *>(T, 0x134);
      W32(P(0x644), 0);
      vcall<u32>(X, 0x88, (u32)buf, P(0x644));
      cur = (u8 *)R32(P(0x63c));
      if (R32(P(0x644)) == 3) {
        W32(P(0x65c) + 4 * cntA, (u32)cur);
        cntA = R32(P(0x650)) + 1;
        W32(P(0x650), cntA);
      } else {
        W32(P(0x680) + 4 * cntB, (u32)cur);
        cntB = R32(P(0x674)) + 1;
        W32(P(0x674), cntB);
      }
    } else {
      cur = (u8 *)R32(P(0x63c));
    }
    cur += 8;
    W32(P(0x63c), (u32)cur);
  }
  u8 *d1, *d2;   // d1 = edi, d2 = ebx
  u8 *p3 = (u8 *)R32(P(0x660));
  if (R32(P(0x640)) != 0) {
    if (*p3 != 0) {
      d1 = A;
      d2 = B;
    } else {
      d1 = B;
      d2 = A;
    }
  } else {
    u8 *p4 = (u8 *)R32(P(0x684));
    s32 a0 = (s32)R32(p3 + 2), b0 = (s32)R32(p4 + 2);
    bool less;
    if (a0 < b0) less = true;
    else if (a0 != b0) less = false;
    else {
      s32 a1 = (s32)R32(p3 + 6), b1 = (s32)R32(p4 + 6);
      if (a1 < b1) less = true;
      else if (a1 != b1) less = false;
      else less = (s32)R32(p3 + 0xa) < (s32)R32(p4 + 0xa);
    }
    if (less) {
      d1 = B;
      d2 = A;
    } else {
      d1 = A;
      d2 = B;
    }
  }
  {
    u8 *me = (u8 *)R32(P(0x648));
    u8 *o44 = (u8 *)R32((u8 *)R32(me + 0x94) + 0x44);
    T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    u32 w = (u16)vcall<u32>(T, 0x114);
    vcall<u32>(o44, 0x128, w, R32(d1 + 0x20), 0u, 0x6a82f4u, 0x12au, 0u, 0u);
  }
  char *buf = (char *)P(0x404);
  for (u32 i = 0; i < 0x21; i++) {
    W32(P(0x63c), i);
    u8 *Tm = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
    u8 *Z = (u8 *)R32(Tm + 0xae4);
    u8 *e = G(u8 *, 0x70039c);
    u8 *dd = i < 17 ? d1 : d2;
    u32 k = i < 17 ? i : i - 17 + 0;   // case within the edi / ebx family
    // case 0 is the only special one; 1..16 and 17..32 are the same sixteen bodies on edi / ebx
    auto Zs = [&](u32 s) { return vcall<u32>(Z, 0, 0x6a83c4u, s); };
    auto tail = [&](u32 val) {
      u8 *N = vcall<u8 *>(e, 0x190);
      cd3(N, 0x198, (u32)buf, val);
    };
    auto fmtd = [&](u32 val) {
      u8 *N = vcall<u8 *>(e, 0x190);
      (void)N;
    };
    (void)fmtd;
    auto fmtN = [&](u8 *N, u32 val) { cd4(N, 0x198, (u32)buf, 0x6784f4u, val); };
    auto cntOK = [&](u32 need) { return R32(dd + 0x1c) > need; };
    if (i == 0) {
      u8 *g = G(u8 *, 0x7003b8);
      u32 esi = ext_589c20(g, 0);
      Tm = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
      Z = (u8 *)R32(Tm + 0xae4);
      W32(P(0x640), vcall<u32>(Z, 0, 0x6a83c4u, R32(d1)));
      if (esi) ext_59a5e0((void *)esi, R32(d1 + 8));
      u8 *N = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
      cd3(N, 0x198, (u32)buf, R32(P(0x640)));
    } else {
      // dd family: i in 1..16 -> d1, 17..32 -> d2 ; k in 1..16
      u32 kk = i < 17 ? i : i - 16;
      dd = i < 17 ? d1 : d2;
      u8 *ent;
      switch (kk) {
        case 1:
          tail(Zs(R32(dd + 4)));
          break;
        case 2:
          ent = (u8 *)R32(dd + 0x10);
          tail(Zs(R32(ent + 4)));
          break;
        case 3:
          if (R32(dd + 0x1c) > 1) {
            ent = (u8 *)R32(dd + 0x14);
            tail(Zs(R32(ent + 4)));
          }
          break;
        case 4:
          if (R32(dd + 0x1c) > 2) {
            ent = (u8 *)R32(dd + 0x18);
            tail(Zs(R32(ent + 4)));
          }
          break;
        case 5: {
          u8 *N = vcall<u8 *>(e, 0x190);
          fmtN(N, R32((u8 *)R32(dd + 0xc) + 2));
          break;
        }
        case 6: {
          u8 *N = vcall<u8 *>(e, 0x190);
          fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x10)) ));
          break;
        }
        case 7:
          if (R32(dd + 0x1c) > 1) {
            u8 *N = vcall<u8 *>(e, 0x190);
            fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x14))));
          }
          break;
        case 8:
          if (R32(dd + 0x1c) > 2) {
            u8 *N = vcall<u8 *>(e, 0x190);
            fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x18))));
          }
          break;
        case 9: {
          u8 *N = vcall<u8 *>(e, 0x190);
          fmtN(N, R32((u8 *)R32(dd + 0xc) + 6));
          break;
        }
        case 10: {
          u8 *N = vcall<u8 *>(e, 0x190);
          fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x10)) + 8));
          break;
        }
        case 11:
          if (R32(dd + 0x1c) > 1) {
            u8 *N = vcall<u8 *>(e, 0x190);
            fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x14)) + 8));
          }
          break;
        case 12:
          if (R32(dd + 0x1c) > 2) {
            u8 *N = vcall<u8 *>(e, 0x190);
            fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x18)) + 8));
          }
          break;
        case 13: {
          u8 *N = vcall<u8 *>(e, 0x190);
          fmtN(N, R32((u8 *)R32(dd + 0xc) + 0xa));
          break;
        }
        case 14: {
          u8 *N = vcall<u8 *>(e, 0x190);
          fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x10)) + 4));
          break;
        }
        case 15:
          if (R32(dd + 0x1c) > 1) {
            u8 *N = vcall<u8 *>(e, 0x190);
            fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x14)) + 4));
          }
          break;
        case 16:
          if (R32(dd + 0x1c) > 2) {
            u8 *N = vcall<u8 *>(e, 0x190);
            fmtN(N, R32((u8 *)R32((u8 *)R32(dd + 0x18)) + 4));
          }
          break;
      }
      (void)cntOK;
      (void)k;
    }
    {
      u8 *L = G(u8 *, 0x700390);
      typedef u32(THISCALL * V2)(void *, u32, u32);
      u8 *M = (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, 0x6a82f4, 0x204);
      cd2(M, 0x2c, (u32)buf);
    }
    {
      u8 *w = (u8 *)R32(self + 0x180 + i * 4);
      vcall<u32>(w, 0x284, (u32)buf);
    }
    *P(0x404) = 0;
  }
}
extern "C" void THISCALL fn_56e050(u8 *self);
extern "C" void THISCALL fn_56e050(u8 *self) {
  body_56e050(self);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(56e050, fn_56e050);
