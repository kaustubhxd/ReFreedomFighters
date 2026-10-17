// batch1913.cpp - fresh slice 19, batch 1913 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" u8 *ext_45c4f0(u32 n, u32 pool);                               // pool operator new (cdecl; hooked)
extern "C" u8 *ext_45c4b0(u32 n);                                         // operator new (cdecl; hooked)
extern "C" void THISCALL ext_4ee240(u8 *o, u32 c, u32 a, u32 b);          // base constructor ret 0xc (hooked)
extern "C" void ext_4690b0(void *p, u32 n);                               // empty function, here as sized delete (cdecl, hooked)
extern "C" void THISCALL ext_579bd0(u8 *self, u32 on);                    // ZControllerA::SetIV (hooked)
extern "C" void THISCALL ext_579b20(u8 *self, u32 on);                    // ZControllerA::SetIH (hooked)
extern "C" void THISCALL ext_579a60(u8 *self, u32 on);                    // ZControllerA::SetA (hooked)
extern "C" u8 *THISCALL ext_5003d0(u8 *arr, u32 i);                       // parameter array element (hooked)
extern "C" void THISCALL ext_5002f0(u8 *p, u32 v);                        // set int parameter (hooked)
extern "C" void THISCALL ext_4cbe80(u8 *s, const char *t);                // MYSTR::MYSTR(const char *) (hooked)
extern "C" void THISCALL ext_4cbee0(u8 *s, u8 *o);                        // MYSTR::operator= (hooked)
extern "C" void THISCALL ext_4cbec0(u8 *s);                               // MYSTR::~MYSTR (hooked)
extern "C" void THISCALL ext_435ae0(u8 *self);                            // base constructor (hooked)
extern "C" s32 STDCALL ext_61ba16(u32 inst, u32 ver, u32 riid, u8 **out, u32 outer);  // jmp [0x676018] (hooked)
extern "C" void THISCALL ext_428990(u8 *self);                            // (no GC name) (hooked)
extern "C" void THISCALL ext_4293e0(u8 *self);                            // ZSysInputGC::InitDevices (hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))
typedef void (*logf_t)(void *, ...);

static inline void assert_hook() {
  void (*hook)() = *(void (**)())0x7003b0u;
  if (hook) hook();
  else __builtin_debugtrap();   // the exe falls into an int3 when no hook is set
}

// 0x4f40b0 (no GC name) fastcall (a, b; c, pool) ret 8: 0x93 bytes from the pool (or plain new without one), built by
// 0x4ee240(c, a, b), vptr 0x6993dc; returns it or 0. (SEH frame not ported.)
static u8 *FASTCALL make_4f40b0(u32 a, u32 b, u32 c, u32 pool) {
  u8 *o = pool ? ext_45c4f0(0x93, pool) : ext_45c4b0(0x93);
  if (!o) return 0;
  ext_4ee240(o, c, a, b);
  *(u32 *)o = 0x6993dc;
  return o;
}
PCREG(4f40b0, make_4f40b0);

// 0x565df0 CBriefing scalar deleting destructor (flags) ret 4: +0x44 = +0x30 = 0, vptr 0x686874, db vt[0x34](this);
// flag 1 frees: flag 4 = 0x4690b0(this, 0xa23), else the assert hook [0x7003b0] (int3 without one). Returns this.
static u8 *THISCALL sdtor_565df0(u8 *self, u32 f) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(DB, 0x34, self);
  if (f & 1) {
    if (f & 4) ext_4690b0(self, 0xa23);
    else assert_hook();
  }
  return self;
}
PCREG(565df0, sdtor_565df0);

// 0x5ec670 CSprite3D::SetScale(float s, unsigned i) ret 8: i = -1 first sets every sprite 0..+0x3e-1, then (as the exe
// does) carries on with index -1. Item +0x62[i] gets s at +8/+0xc; vertex row i (0x28 bytes, table (+0x3a)->+4) gets
// (float)+0x52 * s at +0x1c and (float)+0x56 * s at +0x20 (unsigned to float via double); +0xa6 = 1.
static void THISCALL setScale_5ec670(u8 *self, float s, u32 i) {
  if (i == 0xffffffffu)
    for (u32 j = 0; j < *(u32 *)(self + 0x3e); j++) setScale_5ec670(self, s, j);
  u8 *it = *(u8 **)(*(u8 **)(self + 0x62) + i * 4);
  *(float *)(it + 8) = s;
  *(float *)(it + 0xc) = s;
  *(float *)(*(u8 **)(*(u8 **)(self + 0x3a) + 4) + i * 40 + 0x1c) = (float)(double)*(u32 *)(self + 0x52) * s;
  *(float *)(*(u8 **)(*(u8 **)(self + 0x3a) + 4) + i * 40 + 0x20) = (float)(double)*(u32 *)(self + 0x56) * s;
  self[0xa6] = 1;
}
PCREG(5ec670, setScale_5ec670);

// 0x428370 (GC map: ZSysFileGC::Exists, wrong for PC; this is ZSysFileWintel::WriteTo) stdcall (h, buf, n) ret 0xc: WriteFile
// in chunks of at most 0x3c00000 bytes (signed compare; at least one call, even for n = 0); on a failed write it logs
// "WriteTo failed : size(%d) %s" with the FormatMessageA text of GetLastError (called twice, first result unused), frees
// it and returns 0; else 1.
typedef s32(STDCALL *wf_t)(u32, u32, u32, u32 *, u32);
typedef u32(STDCALL *gle_t)();
typedef u32(STDCALL *fm_t)(u32, u32, u32, u32, char **, u32, u32);
typedef u32(STDCALL *lf_t)(void *);
static bool STDCALL write_428370(u32 h, u32 buf, u32 n) {
  u32 off = 0;
  do {
    u32 ch = n - off;
    if ((s32)ch > 0x3c00000) ch = 0x3c00000;
    u32 wr;
    if (!(*(wf_t *)0x676120u)(h, buf + off, ch, &wr, 0)) {
      gle_t gle = *(gle_t *)0x67609cu;
      gle();
      char *msg;
      (*(fm_t *)0x6760ecu)(0x1300, 0, gle(), 0x400, &msg, 0, 0);
      void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x6789acu, 0x113u);
      (*(logf_t *)(*(u8 **)log + 0x2c))(log, 0x678b88u, ch, msg);
      (*(lf_t *)0x676128u)(msg);
      return false;
    }
    off += ch;
  } while (n != off);
  return true;
}
PCREG(428370, write_428370);

// 0x578c70 ZControllerA::DiscardChanges(): SetIV(+0x1b4), SetIH(+0x1b5); engine vt[0x190]() -> o, o->vt[0x198] (cdecl
// sprintf shape) writes "Rumble%i" of +0x194 into a stack buffer; db vt[0x134]()->vt[0x68](buf, +0x1b6, 0); SetA(+0x1b7);
// vt[0xd0](0). The exe pushes the +0x1b6 byte as a dword whose upper bytes are stack leftovers. (Cookie not ported.)
typedef void (*spf_t)(u8 *, char *, u32, u32);
static void THISCALL discard_578c70(u8 *self) {
  ext_579bd0(self, self[0x1b4]);
  ext_579b20(self, self[0x1b5]);
  u8 b = self[0x1b6];
  u8 *o = vcall<u8 *>(*(u8 **)0x70039cu, 0x190);
  char buf[0x40];
  (*(spf_t *)(*(u8 **)o + 0x198))(o, buf, 0x6a9af0u, *(u32 *)(self + 0x194));
  vcall<void>(vcall<u8 *>(DB, 0x134), 0x68, buf, (u32)b, 0u);
  ext_579a60(self, self[0x1b7]);
  vcall<void>(self, 0xd0, 0u);
}
PCREG(578c70, discard_578c70);

// 0x62d2b0 element1 (expat xmlrole, cdecl (state, tok, ptr, end, enc)): PROLOG_S (0xf) -> 0; NAME (0x12) matching "EMPTY"
// / "ANY" (enc +0x1c nameMatchesAscii) -> handler 0x62cf90, 0x25 / 0x24; OPEN_PAREN (0x17) -> handler 0x62d360, level 1,
// 0x27; else PARAM_ENTITY_REF (0x1c) with no document entity (+0xc) -> 0x34; else handler 0x51f230 (error), -1.
typedef s32 (*nm_t)(u8 *, u32, u32, u32);
static s32 element1_62d2b0(u32 *st, u32 tok, u32 p, u32 end, u8 *enc) {
  if (tok == 0xf) return 0;
  if (tok == 0x12) {
    if ((*(nm_t *)(enc + 0x1c))(enc, p, end, 0x6c0174u)) { st[0] = 0x62cf90; return 0x25; }
    if ((*(nm_t *)(enc + 0x1c))(enc, p, end, 0x6c0150u)) { st[0] = 0x62cf90; return 0x24; }
  } else if (tok == 0x17) {
    st[0] = 0x62d360;
    st[1] = 1;
    return 0x27;
  }
  if (st[3] == 0 && tok == 0x1c) return 0x34;
  st[0] = 0x51f230;
  return -1;
}
PCREG(62d2b0, element1_62d2b0);

// 0x553830 (no GC name; script native, warning "Tried to use GetActorTeam() on null obj") (params) ret 4: g = db
// vt[0x58](*in param 0); out param 0 (array +8) = -1 for no object (and the warning), (g+0x54)->+4 when g->vt[0x1e0](0x200006) and +0x54,
// else 1 when g->vt[0x20]() is set and its vt[0x1e0](0x100bbd), else -1. The bool slots are tested on al only.
static void THISCALL team_553830(u8 *, u8 *pr) {
  u32 id = *(u32 *)ext_5003d0(*(u8 **)(pr + 4), 0);
  u8 *g = vcall<u8 *>(DB, 0x58, id);
  u32 v = 0xffffffffu;
  if (!g) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x6a57fcu, 0x315u);
    (*(logf_t *)(*(u8 **)log + 0x2c))(log, 0x6a5af4u);
  } else if ((u8)vcall<u32>(g, 0x1e0, 0x200006u) && *(u8 **)(g + 0x54)) {
    v = *(u32 *)(*(u8 **)(g + 0x54) + 4);
  } else if (vcall<u8 *>(g, 0x20) && (u8)vcall<u32>(vcall<u8 *>(g, 0x20), 0x1e0, 0x100bbdu)) {
    v = 1;
  }
  ext_5002f0(ext_5003d0(*(u8 **)(pr + 8), 0), v);
}
PCREG(553830, team_553830);

// 0x4352f0 (GC map: ZSysFile::SetSaveGameName(const char*); the PC build takes no argument): a zeroed 0x80-byte stack name
// filled by [0x7003ac]->vt[0x6c](name, "SaveName", 8), then +0x8c = MYSTR(name) via a temporary. (SEH, cookie not ported.)
static void THISCALL setSaveName_4352f0(u8 *self) {
  char name[0x80];
  for (u32 i = 0; i < 0x80; i++) name[i] = 0;
  vcall<void>(*(u8 **)0x7003acu, 0x6c, name, 0x67a5c8u, 8u);
  u8 tmp[0x80];
  ext_4cbe80(tmp, name);
  ext_4cbee0(self + 0x8c, tmp);
  ext_4cbec0(tmp);
}
PCREG(4352f0, setSaveName_4352f0);

// 0x4285f0 (no GC name; ZSysInputWintel constructor): base 0x435ae0, vptr 0x678d2c, global 0x7003a0 = this; +0x7c from
// 0x61ba16 (jmp [0x676018], DirectInput8Create shape: (engine +0x9cf, 0x800, 0x6be1c0, &+0x7c, 0)); a failed call releases
// any object (COM slot 8) and clears it; with an object: COM slot 0x10 (0, callback 0x428b60, this, 0) and 0x428990;
// then 0x4293e0 (InitDevices), +0x8e = 0. Returns this. (SEH frame not ported.)
typedef u32(STDCALL *rel_t)(u8 *);
typedef u32(STDCALL *enum_t)(u8 *, u32, u32, u8 *, u32);
static u8 *THISCALL ctor_4285f0(u8 *self) {
  ext_435ae0(self);
  *(u32 *)self = 0x678d2c;
  u8 **pp = (u8 **)(self + 0x7c);
  G(u8 *, 0x7003a0) = self;
  *pp = 0;
  if (ext_61ba16(*(u32 *)(*(u8 **)0x70039cu + 0x9cf), 0x800, 0x6be1c0, pp, 0) < 0 && *pp) {
    (*(rel_t *)(*(u8 **)*pp + 8))(*pp);
    *pp = 0;
  }
  if (*pp) {
    (*(enum_t *)(*(u8 **)*pp + 0x10))(*pp, 0, 0x428b60, self, 0);
    ext_428990(self);
  }
  ext_4293e0(self);
  self[0x8e] = 0;
  return self;
}
PCREG(4285f0, ctor_4285f0);
