// batch0122.cpp - fresh-01 batch 22 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void ext_620cb0(u8 *parser, u8 *enc, u32 s, u32 e);      // expat reportDefault
extern "C" u32 ext_620180(u8 *pool, u8 *enc, u32 s, u32 e);          // expat poolAppend
extern "C" u32 ext_6206e0(u8 *pool);                                 // expat poolGrow
extern "C" void ext_6200d0(u8 *s);                                   // expat normalizeLines
extern "C" void ext_6204a0(u8 *pool);                                // expat poolClear
extern "C" void THISCALL ext_563d20(u8 *self, u32 a, u8 *v, u32 n);  // CBaseWindow value step (0x102)
extern "C" void THISCALL ext_563d40(u8 *self, u32 a, u8 *v, u32 n);  // CBaseWindow value step (0x103)
extern "C" void THISCALL ext_56d750(u8 *self);                       // CMultiplayerKOTH::UpdateAmountButton
extern "C" void THISCALL ext_56d840(u8 *self);                       // CMultiplayerKOTH::UpdateMapButton
extern "C" u32 THISCALL ext_562d90(u8 *self, u32 key);               // CBaseWindow::OnKeyPress
extern "C" u8 THISCALL ext_5b1000(u8 *save, const char *name);       // CSaveMissions::LevelCompleted
extern "C" void THISCALL ext_574af0(u8 *self, u32 icon, float *pos, u32 done, u32 b, u32 obj);  // ZBaseMap::SetupIcon
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie

typedef u32 (*encFn)(u8 *enc, u32 p);
typedef void (*piFn)(u32 arg, u32 target, u32 data);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x620d50, expat reportProcessingInstruction(parser, enc, start, end) (cdecl): no PI handler (+0x40): the default
// handler path (+0x50 -> reportDefault), 1. Else target = the name after "<?" (enc +0x44 minBytesPerChar, enc +0x20
// nameLength) and data = the rest after the blanks (enc +0x24 skipS) up to end - "?>", both stored in the temp pool
// at +0x22c (poolAppend, poolGrow when full, terminating 0, poolFinish between them); 0 when the pool fails; then
// normalizeLines(data), handler(+4 handlerArg, target, data), poolClear; 1.
static u32 reportProcessingInstruction(u8 *parser, u8 *enc, u32 start, u32 end) {
  if (*(u32 *)(parser + 0x40) == 0) {
    if (*(u32 *)(parser + 0x50)) ext_620cb0(parser, enc, start, end);
    return 1;
  }
  u32 s = start + *(u32 *)(enc + 0x44) * 2;
  u32 tem = (*(encFn *)(enc + 0x20))(enc, s) + s;
  u8 *pool = parser + 0x22c;
  if (!ext_620180(pool, enc, s, tem)) return 0;
  if (*(u32 *)(pool + 0xc) == *(u32 *)(pool + 8) && !ext_6206e0(pool)) return 0;
  **(u8 **)(pool + 0xc) = 0;
  (*(u32 *)(pool + 0xc))++;
  u32 target = *(u32 *)(pool + 0x10);
  if (!target) return 0;
  *(u32 *)(parser + 0x23c) = *(u32 *)(parser + 0x238);
  u32 dend = end - *(u32 *)(enc + 0x44) * 2;
  u32 ds = (*(encFn *)(enc + 0x24))(enc, tem);
  if (!ext_620180(pool, enc, ds, dend)) return 0;
  if (*(u32 *)(pool + 0xc) == *(u32 *)(pool + 8) && !ext_6206e0(pool)) return 0;
  **(u8 **)(pool + 0xc) = 0;
  (*(u32 *)(pool + 0xc))++;
  u8 *data = *(u8 **)(pool + 0x10);
  if (!data) return 0;
  ext_6200d0(data);
  (*(piFn *)(parser + 0x40))(*(u32 *)(parser + 4), target, (u32)data);
  ext_6204a0(pool);
  return 1;
}
PCREG(620d50, reportProcessingInstruction);

// 0x56cfd0, CMultiplayerKOTH::OnKeyPress(unsigned int): 0 when slot 0xd8 says so. On the amount button (+0x180):
// keys 0x102 / 0x103 step +0x1b6 (0x563d20 / 0x563d40 with (1, +0x1b6, 0xb)) when +0x1b5 is set, then
// UpdateAmountButton (also for other keys); on the map button (render slot 0x58(+0x184)): 0x103 / 0x102 step +0x1be
// ((0, +0x1be, 3)), then UpdateMapButton. A handled step returns 1; everything else goes to CBaseWindow::OnKeyPress.
static u32 THISCALL kothOnKeyPress(u8 *self, u32 key) {
  u8 r = vcall<u8>(self, 0xd8);
  if (r) return 0;
  u8 done = 0;
  u8 *a = vcall<u8 *>(self, 0x84);
  u8 *b = vcall<u8 *>(a, 0x2c4);
  u32 f = vcall<u32>(b, 0x2f0);
  if (f == *(u32 *)(self + 0x180)) {
    if (key == 0x102) {
      if (self[0x1b5]) {
        ext_563d20(self, 1, self + 0x1b6, 0xb);
        done = 1;
      }
    } else if (key == 0x103) {
      if (self[0x1b5]) {
        ext_563d40(self, 1, self + 0x1b6, 0xb);
        done = 1;
      }
    }
    ext_56d750(self);
  } else if (f == vcall<u32>(render(), 0x58, *(u32 *)(self + 0x184))) {
    if (key == 0x103) {
      ext_563d40(self, 0, self + 0x1be, 3);
      done = 1;
    } else if (key == 0x102) {
      ext_563d20(self, 0, self + 0x1be, 3);
      done = 1;
    }
    ext_56d840(self);
  } else {
    return ext_562d90(self, key);
  }
  if (done) return 1;
  return ext_562d90(self, key);
}
PCREG(56cfd0, kothOnKeyPress);

// 0x575bd0, ZZoneMap::SetupIcons(): for the 5 zone records at +0x240 (0x24 bytes: +0 zone, +4 marker object) with
// both set: pos = 0, marker slot 0x84(pos); done = LevelCompleted([+0x94]+0x50f, zone name +4 or ""); while fewer
// than +0x1fe label buttons were used, the next one (+0x190 array) gets the localised name (text(0x6a930c, name)),
// slot 0xbc(0), slot 0x260(0x14) and is passed on; SetupIcon(0, pos, done, 1, button or 0). /GS cookie.
static void THISCALL zoneMapSetupIcons(u8 *self) {
  u32 used = 0;
  u8 **btn = (u8 **)(self + 0x190);
  u8 *rec = self + 0x240;
  for (u32 k = 5; k != 0; k--, rec += 0x24) {
    if (*(u32 *)rec == 0) continue;
    u8 *mk = *(u8 **)(rec + 4);
    if (!mk) continue;
    float pos[3] = {0, 0, 0};
    vcall<void>(mk, 0x84, pos);
    const char *nm = *(const char **)(*(u8 **)rec + 4);
    if (!nm) nm = (const char *)0x67c8e8;
    u8 done = ext_5b1000(*(u8 **)(self + 0x94) + 0x50f, nm);
    u32 o = 0;
    if (used < *(u32 *)(self + 0x1fe)) {
      const char *nm2 = *(const char **)(*(u8 **)rec + 4);
      if (!nm2) nm2 = (const char *)0x67c8e8;
      u32 t = vcall<u32>(*(u8 **)(render() + 0xae4), 0, 0x6a930cu, (u32)nm2);
      vcall<void>(*btn, 0x284, t);
      vcall<void>(*btn, 0xbc, 0u);
      vcall<void>(*btn, 0x260, 0x14u);
      used++;
      o = (u32)*btn;
      btn++;
    }
    ext_574af0(self, 0, pos, done, 1, o);
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(575bd0, zoneMapSetupIcons);
