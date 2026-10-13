// batch717.cpp - soldier AI, batch 717 (2026-10-11): ZActor::OnSound, the actor-level version of hearing sound events.
// Same event list and block as ZFFActor::OnSound (batch 716), but: ten types (1 Shot, 2 Empty, 3 Pain, 4 FootStep,
// 5 Door, 6 Impact, 7 Die, 8 Strangulated, 9 SilentShot, 10 SilentShot-again), names built as MYSTR strings
// (exe string class: ctor 0x4cbe80, operator= 0x4cbee0, dtor 0x4cbec0, c_str 0x4cc1d0, default ctor 0x4cbeb0),
// a source equal to self is skipped (no assert), and the range tests are per type: distance <= 700 (or 1200 when the
// actor's flag at +0x145 is set) for FootStep; <= 1000 Door; <= 1500 Impact; <= 700 Strangulated and SilentShot.
// Type 10 warns and stops when the distance is <= 700; any other type warns and stops.
// FootStep: a source derived from class 0x80200014 with bit 0x100 at +0x417 silences it.
// Message id: RegisterZMsg(name, 0, file, 0xe77) (db slot 0x114); send: SendCommand(id, block, 0) on self (slot 0x128).
#include "ff.h"

extern "C" void THISCALL ext_4cbeb0(void *mystr);                  // MYSTR::MYSTR()
extern "C" void THISCALL ext_4cbe80(void *mystr, const char *s);   // MYSTR::MYSTR(const char*)
extern "C" void THISCALL ext_4cbee0(void *mystr, void *other);     // MYSTR::operator=(const MYSTR&)
extern "C" void THISCALL ext_4cbec0(void *mystr);                  // MYSTR::~MYSTR()
extern "C" const char *THISCALL ext_4cc1d0(void *mystr);           // MYSTR::c_str

struct MYSTR_buf { u8 b[0x80]; };   // inline storage: the original uses 0x80-byte slots (temp at -0xa8, name at -0x128)

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

static void actor_warn(u32 line) {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x68a7c4, line);
  typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
  (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68aec4);
}

// The name for one type: MYSTR tmp(lit); name = tmp; tmp.~MYSTR().
static void set_name(MYSTR_buf *name, const char *lit) {
  MYSTR_buf tmp;
  ext_4cbe80(&tmp, lit);
  ext_4cbee0(name, &tmp);
  ext_4cbec0(&tmp);
}

// Sends the block with the message named by `name`.
static void send_sound(u8 *self, u8 *ev, MYSTR_buf *name) {
  struct { float x, y, z, scale; u32 ref; u32 extra; } blk;
  blk.x = *(float *)(ev + 0);
  blk.y = *(float *)(ev + 4);
  blk.z = *(float *)(ev + 8);
  blk.scale = *(float *)(ev + 0x10) * 0.00999999978f;   // 0x67da00
  blk.ref = *(u32 *)(ev + 0x14);
  blk.extra = *(u32 *)(ev + 0x1c);
  const char *nm = ext_4cc1d0(name);
  u8 tmp16[0x10] = {0};
  u16 id = vcall<u16>(db(), 0x114, nm, 0u, (const char *)0x68a7c4, 0xe77u);   // zactor.cpp: four args
  vcall<void>(self, 0x128, (u32)id, tmp16, (void *)0);   // the leftover push goes to slot 0x128
}

// 0x47a620 ZActor::OnSound(REFTAB* events) [high].
static void THISCALL actor_OnSound(u8 *self, void *events) {
  if (!events)
    return;
  u32 it = 0;
  vcall<void>(events, 0x4c, &it);
  u8 *ev = vcall<u8 *>(events, 0x64, &it);
  while (ev) {
    MYSTR_buf name;
    ext_4cbeb0(&name);
    u8 *src = vcall<u8 *>(db(), 0x58, *(u32 *)(ev + 0x14));
    if (src == self) {
      ext_4cbec0(&name);
      ev = vcall<u8 *>(events, 0x64, &it);
      continue;
    }
    u32 idx = *(u32 *)(ev + 0xc) - 1;
    float dist = *(float *)(ev + 0x10);
    if (idx > 9) {
      actor_warn(0xe63);
      ext_4cbec0(&name);
      return;
    }
    bool send = false, warn = false;
    switch (idx) {
    case 0:   // Shot
      set_name(&name, (const char *)0x68ae1c);
      send = true;
      break;
    case 1:   // Empty
      set_name(&name, (const char *)0x68ae2c);
      send = true;
      break;
    case 2:   // Pain
      set_name(&name, (const char *)0x68ae4c);
      send = true;
      break;
    case 3: { // FootStep: within 700 (1200 with the flag at +0x145); silenced by bit 0x100 on a derived source
      set_name(&name, (const char *)0x68ae5c);
      bool inRange = (*(u8 *)(self + 0x145) != 0) ? !(dist > 1200.0f) : !(dist > 700.0f);
      if (inRange) {
        send = true;
        if (src && vcall<bool>(src, 0x1e0, 0x80200014) && (*(u32 *)(src + 0x417) & 0x100))
          send = false;
      }
      break;
    }
    case 4:   // Door: within 1000
      set_name(&name, (const char *)0x68ae70);
      send = !(dist > 1000.0f);
      break;
    case 5:   // Impact: within 1500
      set_name(&name, (const char *)0x68ae80);
      send = !(dist > 1500.0f);
      break;
    case 6:   // Die
      set_name(&name, (const char *)0x68ae3c);
      send = true;
      break;
    case 7:   // Strangulated: within 700
      set_name(&name, (const char *)0x68ae94);
      send = !(dist > 700.0f);
      break;
    case 8:   // SilentShot: within 700
      set_name(&name, (const char *)0x68aeac);
      send = !(dist > 700.0f);
      break;
    default:  // 9: type 10, SilentShot again: warns and stops when within 700, otherwise nothing
      set_name(&name, (const char *)0x68aeac);
      warn = !(dist > 700.0f);
      break;
    }
    if (warn) {
      actor_warn(0xe63);
      ext_4cbec0(&name);
      return;
    }
    if (send)
      send_sound(self, ev, &name);
    ext_4cbec0(&name);
    ev = vcall<u8 *>(events, 0x64, &it);
  }
}
PCREG(47a620, actor_OnSound);
