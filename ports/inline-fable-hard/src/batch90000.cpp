// batch90000.cpp - hard-function trial (fable), batch 90000: 0x578f30 ZControllerA::Init2() (401 insns, 73 calls).
#include "ff.h"

typedef u8 *(THISCALL *v0o_t)(void *);
typedef u32 (THISCALL *v0u_t)(void *);
typedef u32 (THISCALL *v1u_t)(void *, u32);
typedef void (THISCALL *v1_t)(void *, u32);
typedef void (THISCALL *v2_t)(void *, u32, u32);
typedef void (THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32 (*cdecl4_t)(void *, void *, u32, u32);

extern "C" void THISCALL ext_579a60(void *, u32);   // ret 4 (verified s5): bind "...afc" setting (bool)
extern "C" void THISCALL ext_579b20(void *, u32);   // ret 4 (verified s5): bind "...adc" setting (bool)
extern "C" void THISCALL ext_579bd0(void *, u32);   // ret 4 (verified s4): bind "...ac8" setting (bool)
extern "C" void THISCALL ext_579ca0(void *, u32);   // ret 4 (verified h1): bind "...af0" setting (bool)
extern "C" void THISCALL ext_563a50(void *);        // ret 0 (717 bytes, hooked)
extern "C" void FASTCALL ext_633654(u32 cookie);    // /GS check

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// [0x70039c]: engine object. slot 0xbc = input device object, slot 0x190 = string formatter; [eng+0x9b]->slot 0x134 = settings object.
static inline u8 *settings() {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  return (*(v0o_t **)tab)[0x134 / 4](tab);
}
static inline u8 *inputdev() {
  u8 *eng = G(u8 *, 0x70039c);
  return (*(v0o_t **)eng)[0xbc / 4](eng);
}
// y = eng->slot 0x190(); y->slot 0x198 is cdecl (y, buf, fmt, idx), caller pops 16.
static inline void fmt(char *buf, u32 f, u32 idx) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *y = (*(v0o_t **)eng)[0x190 / 4](eng);
  void *fn = *(void **)(*(u8 **)y + 0x198);
  ((cdecl4_t)fn)(y, buf, f, idx);
}
// settings->slot 0x90(buf, &out byte): read a bool setting named by buf. The out byte sits in a dword local whose
// other three bytes the exe never writes (they are pushed along with it; the callees read only the low byte).
static inline void readbool(char *buf, u32 *out) {
  u8 *z = settings();
  *(u8 *)out = 0;
  (*(v2_t **)z)[0x90 / 4](z, (u32)buf, (u32)out);
}
static inline void writeval(char *buf, u32 v) {   // settings->slot 0x68(buf, v, 0)
  u8 *z = settings();
  (*(v3_t **)z)[0x68 / 4](z, (u32)buf, v, 0);
}

// 0x578f30, thiscall(no args), this = E (ZControllerA). Reads the int setting 0x6a9b28 into v90 through settings->slot 0x88.
// v90 == 0 (first run): if E[0x94] && E[0x94][0x103c]: for i = E[0x194] := 0..3 { bd0(dev->slot 0xb8() byte); b20(dev->slot 0xc0() byte);
//   a60(1); fmt(b84, 0x6a9af0, i); settings->slot 0x68(b84, 1, 0) } then restore E[0x194]; else { bd0(dev->0xb8); b20(dev->0xc0); a60(1); ca0(1) };
//   then settings->slot 0x5c(0x6a9b28, 1, 2).
// Then if E[0x94] && E[0x94][0x103f]: for i = E[0x194] := 0..3 read bools 0x6a9ac8 -> bd0, 0x6a9adc -> b20, 0x6a9af0 -> v85, write 0x6a9af0 := v85 (slot 0x68),
//   0x6a9afc -> a60; then 0x563a50(E). Else the same once with E[0x194] as it is, then E->slot 0x64(8).
// Finally E[0x94][0x132af] = [eng+0x9b]->slot 0x4c(E[0x44]).
static void THISCALL fn578f30(u8 *E) {
  char b84[0x40];
  char b44[0x40];
  u32 v90 = 0;   // dword local: the int setting, later also the bool out byte (low byte)
  u32 v98;       // bool out byte in a dword local (upper bytes: whatever the stack held)
  u32 v94;       // copy of v85's byte in a dword local
  u32 v89;
  u32 v85;
  u8 *z = settings();
  (*(v2_t **)z)[0x88 / 4](z, 0x6a9b28u, (u32)&v90);
  if (v90 == 0) {
    u8 *p = *(u8 **)(E + 0x94);
    if (p && p[0x103c]) {
      u32 saved = rd(E + 0x194);
      wr(E + 0x194, 0);
      do {
        u8 *d = inputdev();
        u32 r1 = (*(v0u_t **)d)[0xb8 / 4](d) & 0xff;
        ext_579bd0(E, r1);
        d = inputdev();
        u32 r2 = (*(v0u_t **)d)[0xc0 / 4](d) & 0xff;
        ext_579b20(E, r2);
        ext_579a60(E, 1);
        fmt(b84, 0x6a9af0u, rd(E + 0x194));
        writeval(b84, 1);
        wr(E + 0x194, rd(E + 0x194) + 1);
      } while ((s32)rd(E + 0x194) < 4);
      wr(E + 0x194, saved);
    } else {
      u8 *d = inputdev();
      u32 r1 = (*(v0u_t **)d)[0xb8 / 4](d) & 0xff;
      ext_579bd0(E, r1);
      d = inputdev();
      u32 r2 = (*(v0u_t **)d)[0xc0 / 4](d) & 0xff;
      ext_579b20(E, r2);
      ext_579a60(E, 1);
      ext_579ca0(E, 1);
    }
    z = settings();
    (*(v3_t **)z)[0x5c / 4](z, 0x6a9b28u, 1, 2);
  }
  u8 *p = *(u8 **)(E + 0x94);
  if (p && p[0x103f]) {
    wr(E + 0x194, 0);
    do {
      fmt(b84, 0x6a9ac8u, rd(E + 0x194));
      readbool(b84, &v90);
      ext_579bd0(E, v90);
      fmt(b84, 0x6a9adcu, rd(E + 0x194));
      readbool(b84, &v98);
      ext_579b20(E, v98);
      fmt(b84, 0x6a9af0u, rd(E + 0x194));
      readbool(b84, &v85);
      *(u8 *)&v94 = *(u8 *)&v85;
      fmt(b44, 0x6a9af0u, rd(E + 0x194));
      writeval(b44, v94);
      fmt(b44, 0x6a9afcu, rd(E + 0x194));
      readbool(b44, &v89);
      ext_579a60(E, v89);
      wr(E + 0x194, rd(E + 0x194) + 1);
    } while ((s32)rd(E + 0x194) < 4);
    ext_563a50(E);
  } else {
    fmt(b44, 0x6a9ac8u, rd(E + 0x194));
    readbool(b44, &v89);
    ext_579bd0(E, v89);
    fmt(b44, 0x6a9adcu, rd(E + 0x194));
    readbool(b44, &v89);
    ext_579b20(E, v89);
    fmt(b44, 0x6a9af0u, rd(E + 0x194));
    readbool(b44, &v85);
    *(u8 *)&v94 = *(u8 *)&v85;
    fmt(b84, 0x6a9af0u, rd(E + 0x194));
    writeval(b84, v94);
    fmt(b44, 0x6a9afcu, rd(E + 0x194));
    readbool(b44, &v89);
    ext_579a60(E, v89);
    (*(v1_t **)E)[0x64 / 4](E, 8);
  }
  u8 *eng = G(u8 *, 0x70039c);
  u32 a44 = rd(E + 0x44);
  u8 *q = *(u8 **)(E + 0x94);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u32 res = (*(v1u_t **)tab)[0x4c / 4](tab, a44);
  wr(q + 0x132af, res);
  ext_633654(0);
}
PCREG(578f30, fn578f30);
